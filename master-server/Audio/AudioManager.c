/*
 * @Description : 声音设备管理器
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:44
 * @LastEditTime: 2022-12-05 17:14:33
 */

#include <sys/msg.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

#include "Base/MasterMsgBase.h"
#include "AudioManager.h"

/**
 * @description: 静态变量声明
 * @param  {*}
 * @return {*}
 */
static MsgHandle_t msgHandle;
static int managerMsgId = -1;
static int serverMsgId = -1;

/**
 * @description: 静态函数声明
 */
static int SendMsgBuff(MsgHeadBuf_t *data, size_t len);
static int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len);

/**
 * @description: 
 * @return {*}
 * @param {LanguageType} language
 */
static char *GetlanguagePath(LanguageType language)
{
    switch (language)
    {
        case Language_Chinese: return "chinese"; break;
        case Language_English: return "english"; break;
        case Language_German: return "german"; break;
        case Language_Spanish: return "spanish"; break;
        case Language_French: return "french"; break;
        case Language_Italian: return "italian"; break;
        case Language_Portuguese: return "portuguese"; break;
        case Language_Russian: return "russian"; break;
        case Language_Turkish: return "turkish"; break;
        default: return "chinese"; break;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {AudioPlayNum} num
 */
static char *GetAudioFileName(AudioPlayNum_t num)
{
    switch (num)
    {
        case AUDIO_BUTTON_BEEP:
        {
            // 按键音有不同音效
            switch (GetSystemConfig().sounde_ffect) {
                case BUTTON_SOUND_TECHNOLOGY:   return "1.sound_button_technology.wav"; break;
                case BUTTON_SOUND_SMART:        return "1.sound_button_smart.wav"; break;
                case BUTTON_SOUND_SHORT:        return "1.sound_button_short.wav"; break;
                case BUTTON_SOUND_CRISP:        return "1.sound_button_crisp.wav"; break;
            }break;
        }
        case AUDIO_START_PRINT: return "1.button_beep.wav"; break;
        
        default: CrLogW("no such audio file path!\n\n"); break;
    }

    return NULL;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHead} *head
 */
static void ServerMessageTestAns(MsgHeadBuf_t *head)
{
    ServerTest *recv = server_test__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("dialogue = %s\n", recv->dialogue);
    server_test__free_unpacked(recv, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHead} *head
 */
static void ManagerMessageTest(MsgHeadBuf_t *head)
{
    ManagerTest *recv = manager_test__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("dialogue = %s\n", recv->dialogue);
    manager_test__free_unpacked(recv, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UpdataAudioNum(MsgHeadBuf_t *head)
{
    AudioNum *recv = audio_num__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }

    SystemConfig_t config = GetSystemConfig();
    CrLogI("sound_sw = %d", config.sound_sw);
    if (config.sound_sw)
    {
        CrLogI("sound num = %d", recv->data);
        char audioPath[256] = {0};
        snprintf(audioPath, 256, "%s/%s/%s",
            GetDefaultLanguagePtah(), GetlanguagePath(config.language), GetAudioFileName(recv->data));
        CrLogI("sound file path data = %s", audioPath);

        SendString sound = SEND_STRING__INIT;
        sound.str.data = (uint8_t*)audioPath;
        sound.str.len = strlen(audioPath) + 1;

        GET_MESSAGE_BUFF(buff);
        size_t len = send_string__pack(&sound, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_AUDIO_MANAGER, SERVER_CMD_AUDIO_FILE_PATH, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    audio_num__free_unpacked(recv, NULL);
}

/**
 * @description: 消息更新
 * @param  {*}
 * @return {*}
 */
static void msgUpdata(void)
{
    MsgHeadBuf_t head;
    ssize_t headSize = RECV_MESSAGE_PACKAGE(managerMsgId, &head);
    
    if (headSize > 0)
    {
        CrLogI("package len = %ld, origin %d, cmd %d, message len %ld", headSize, head.origin, head.cmd, head.bufLen);

        switch (head.cmd)
        {
            case SERVER_CMD_AUDIO_TEST_ANS: ServerMessageTestAns(&head); break;

            case MANAGER_CMD_MESSAGE_TEST: ManagerMessageTest(&head); break;
            case MANAGER_SEND_AUDIO_MESSAGE: UpdataAudioNum(&head); break;

            default:
            {
                CrLogW("msg cmd file !!! origin %d, cmd %d\n", head.origin, head.cmd);
                break;
            }
        }
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static void CleanMessageQueue(void)
{
    MsgHeadBuf_t head;
    while (1)
    {
        ssize_t headSize = RECV_MESSAGE_PACKAGE_NOWAIT(managerMsgId, &head);
        if (headSize == -1)
        {
            CrLogI("The message queue has been emptied");
            break;
        }
    }
}

/**
 * @description: 管理器主线程
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
static void *ManagerThread(void *arg)
{
    // 创建消息队列
    managerMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_AUDIO_MANAGER);
    if (managerMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    serverMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_AUDIO_SERVER);
    if (serverMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    // 清空消息队列
    CleanMessageQueue();

    while (1)
    {
        msgUpdata();
        usleep(1000 * 10);
    }

    return NULL;
}

/**
 * @description: 管理器初始化
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
MsgHandle_t *AudioManagerInit(void *arg)
{
    CrLogI("audio manager init");
    int res = pthread_create(&msgHandle.handle, NULL, (void*)ManagerThread, arg);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return NULL;
    }
    msgHandle.sendMsgBuff = &SendMsgBuff;
    
    return &msgHandle;  
}

/**
 * @description: 发送消息到消息队列
 * @param  {*}
 * @return {*}
 * @param {uint8_t} *data
 */
static int SendMsgBuff(MsgHeadBuf_t *data, size_t len)
{
    if (managerMsgId == -1)
    {
        CrLogW("message queue or semaphore not created\n");
        return -1;
    }
    
    int res = SEND_MESSAGE_PACKAGE(managerMsgId, data, len);
    if (res == -1)
    {
        CrLogW("send msg fail, %s\n", strerror(errno));
    }

    return res;
}

/**
 * @description: 发送消息到进程消息队列
 * @param  {*}
 * @return {*}
 * @param {uint8_t} *data
 */
static int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len)
{
    if (serverMsgId == -1)
    {
        CrLogW("message queue or semaphore not created\n");
        return -1;
    }
    
    int res = SEND_MESSAGE_PACKAGE(serverMsgId, data, len);
    if (res == -1)
    {
        CrLogW("send msg fail, %s\n", strerror(errno));
    }

    return res;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int AudioManagerExceptionHandleSemPost(void)
{
    return 0;
}