/*
 * @Description : 通信管理
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:09
 * @LastEditTime: 2023-03-23 12:11:40
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

#include "Base/AudioMsgBase.h"
#include "ServerMessage.h"

#define AUDIO_QUEUE_MAX_SIZE    20
typedef struct {
    char *path;
}SoundQueue_t;

/**
 * @description: 静态变量声明
 * @param  {*}
 * @return {*}
 */
static pthread_t messageHandle;
static int managerMsgId = -1;
static int serverMsgId = -1;
static qqueue_t *audioQueue = NULL;


/**
 * @description: 静态函数声明
 */

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHead} *head
 */
static void ServerMessageTestReq(MsgHeadBuf_t *head)
{
    ServerTest *recv = server_test__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("dialogue = %s\n", recv->dialogue);
    server_test__free_unpacked(recv, NULL);


    ServerTest str = SERVER_TEST__INIT;
    str.dialogue = "I am audio server!";

    GET_MESSAGE_BUFF(buff);
    size_t len = server_test__pack(&str, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_AUDIO_SERVER, SERVER_CMD_AUDIO_TEST_ANS, buff, len);

    SendProcessMsgBuff(&send, size);
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
static void SaveAudioFilePath(MsgHeadBuf_t *head)
{
    SendString *recv = send_string__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("audio file name len = %d, path = %s\n", recv->str.len, recv->str.data);
    if(audioQueue->num != audioQueue->max)
    {
        SoundQueue_t sound;
        sound.path = (char *)malloc(recv->str.len + 1);
        if (sound.path)
        {
            memset(sound.path, 0, (recv->str.len + 1));
            memcpy(sound.path, recv->str.data, recv->str.len);

            Q_MUTEX_ENTER(audioQueue->qmutex);
            if(qqueue_addlast(audioQueue, (void *)&sound, sizeof(SoundQueue_t)) == false)
            {
                free_s(sound.path);
            }
            Q_MUTEX_LEAVE(audioQueue->qmutex);
        }
        else CrLogW("Unable to allocate memory\n");
    }
    else
    {
        CrLogW("voice buffer queue is full, voice is discarded\n");
    }
    send_string__free_unpacked(recv, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static void AudioQueueUpdata(void)
{
    uint32_t img_size = 0;
    SoundQueue_t *recvSound = (SoundQueue_t*)qqueue_popfirst(audioQueue, &img_size);
    if (recvSound)
    {
        // 播放音频
        char audioPlayCmd[320];
        snprintf(audioPlayCmd, 320, "%s %s", GetDefaultplaySoundScript(), recvSound->path);
        // 调用系统命令
        // char sysRes[1024] = {0};
        // if (!PopenSystem(audioPlayCmd, sysRes, sizeof(sysRes)))
        //     CrLogW("system fail! res = %s\n", sysRes);
        // 释放内存
        free_s(recvSound->path);
        free_s(recvSound);
    }
}

/**
 * @description: 消息更新
 * @param  {*}
 * @return {*}
 */
static void MsgUpdata(void)
{
    MsgHeadBuf_t head;
    ssize_t headSize = RECV_MESSAGE_PACKAGE(serverMsgId, &head);
    
    if (headSize > 0)
    {
        CrLogI("package len = %ld, origin %d, cmd %d, message len %ld", headSize, head.origin, head.cmd, head.bufLen);

        switch (head.cmd)
        {
            case SERVER_CMD_AUDIO_TEST_REQ: ServerMessageTestReq(&head); break;
            
            case SERVER_CMD_AUDIO_FILE_PATH: SaveAudioFilePath(&head); break;

            case MANAGER_CMD_MESSAGE_TEST: ManagerMessageTest(&head); break;

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
        ssize_t headSize = RECV_MESSAGE_PACKAGE_NOWAIT(serverMsgId, &head);
        if (headSize == -1)
        {
            CrLogI("The message queue has been emptied");
            break;
        }
    }
}

/**
 * @description: 通信线程
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
static void *MessageThread(void *arg)
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
        MsgUpdata();
        usleep(1000 * 10);
    }

    return NULL;
}

/**
 * @description: 运行线程
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
static void *RunThread(void *arg)
{
    // 初始化音频播报队列
    audioQueue = qqueue(QUEUE_THREADSAFE);
    qqueue_setsize(audioQueue, AUDIO_QUEUE_MAX_SIZE);

    while (1)
    {
        AudioQueueUpdata();
        usleep(1000 * 10);
    }

    return NULL;
}

/**
 * @description: 通信初始化
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
pthread_t *ServerMessageInit(void *arg)
{
    CrLogI("audio server init");
    // 新开线程接收数据
    int res = pthread_create(&messageHandle, NULL, (void*)MessageThread, arg);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return NULL;
    }

    // 创建任务运行线程
    pthread_t RunHandle;
    res = pthread_create(&RunHandle, NULL, (void*)RunThread, arg);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return NULL;
    }

    return &messageHandle;  
}

/**
 * @description: 发送消息到消息队列
 * @param  {*}
 * @return {*}
 * @param {uint8_t} *data
 */
int SendMsgBuff(MsgHeadBuf_t *data, size_t len)
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
 * @description: 发送消息到进程消息队列
 * @param  {*}
 * @return {*}
 * @param {uint8_t} *data
 */
int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len)
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
 * @description: 
 * @param  {*}
 * @return {*}
 */
int ExceptionHandleSemPost(void)
{
    return 0;
}