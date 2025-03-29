/*
 * @Description : 通信管理
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:09
 * @LastEditTime: 2022-12-29 11:03:54
 */

#include <sys/msg.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

#include "Base/DisplayMsgBase.h"
#include "custom/commu_thread.h"
#include "ServerMessage.h"

/**
 * @description: 静态变量声明
 * @param  {*}
 * @return {*}
 */
static int managerMsgId = -1;
static int serverMsgId = -1;

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
    str.dialogue = "I am display server!";

    GET_MESSAGE_BUFF(buff);
    size_t len = server_test__pack(&str, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_TEST_ANS, buff, len);

    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHead} *head
 */
static void UserGcodeCmdSetAns(MsgHeadBuf_t *head)
{
    DisplayCmd *setCmd = display_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!setCmd) {
        CrLogW("unpack failed\n");
        return;
    }

    if(setCmd->has_para)
    {
        char sendBuff[setCmd->para.len + 10];
        memset(sendBuff, 0, sizeof(sendBuff)/sizeof(sendBuff[0]));
        memcpy(sendBuff, setCmd->para.data, setCmd->para.len);
        CrLogI("SetPrinter response flag = %d, len = %d", setCmd->flag, setCmd->para.len);
        CrLogI("SetPrinter response data = %s\n", sendBuff);
        set_response_printer_data(setCmd->flag, setCmd->para.len, sendBuff);
    }
    else
    {
        CrLogI("SetPrinter response fail\n");
        set_response_printer_data(setCmd->flag, 0, "");
    }

    display_cmd__free_unpacked(setCmd, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGcodeCmdGetAns(MsgHeadBuf_t *head)
{
    DisplayCmd *getCmd = display_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!getCmd) {
        CrLogW("unpack failed\n");
        return;
    }

    if(getCmd->has_para)
    {
        CrLogI("GetPrinter response flag = %d, len = %d", getCmd->flag, getCmd->para.len);
        CrLogI("GetPrinter response data = %s\n", getCmd->para.data);
        get_response_printer_data(getCmd->flag, getCmd->para.len, (char *)getCmd->para.data);
    }
    else
    {
        CrLogI("GetPrinter response fail\n");
        get_response_printer_data(getCmd->flag, 0, "");
    }

    display_cmd__free_unpacked(getCmd, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisplayControlAns(MsgHeadBuf_t *head)
{
    DisplayCmd *control = display_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!control) {
        CrLogW("unpack failed\n");
        return;
    }

    if (control->has_refresh)
    {
        CrLogI("display Refresh flag = [%d] success", control->refresh);
    }
    
    if (control->has_sound)
    {
        CrLogI("display buzzer flag = [%d] success", control->sound);
    }

    display_cmd__free_unpacked(control, NULL);
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
            case SERVER_CMD_DIS_TEST_REQ: ServerMessageTestReq(&head); break;

            case SERVER_CMD_DIS_GCODE_SET_CMD_ANS: UserGcodeCmdSetAns(&head); break;
            case SERVER_CMD_DIS_GCODE_GET_CMD_ANS: UserGcodeCmdGetAns(&head); break;
            case SERVER_CMD_DIS_INTERACT_CONTROL_ANS: UserDisplayControlAns(&head); break;

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
    managerMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_DISPLAY_MANAGER);
    if (managerMsgId == -1)
    {
        CrLogE("create manager msg queue fail\n");
    }
    serverMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_DISPLAY_SERVER);
    if (serverMsgId == -1)
    {
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
 * @description: 通信初始化
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
int *ServerMessageInit(void *arg)
{
    CrLogI("display server init");
    // 新开线程接收数据
    pthread_t handle;
    int res = pthread_create(&handle, NULL, (void*)MessageThread, arg);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return NULL;
    }

    return 0;  
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

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {unsigned char} flag
 * @param {unsigned char} len
 * @param {char} *data
 */
int GetPrinterDataFromManager(unsigned char flag, unsigned char dataLen, char *data)
{
    CrLogI("GetPrinter flag = %d, len = %d", flag, dataLen);
    if (data) CrLogI("GetPrinter data = %s\n", data);

    DisplayCmd getCmd = DISPLAY_CMD__INIT;
    getCmd.flag = flag;
    if (dataLen != 0)
    {
        getCmd.has_para = 1;
        getCmd.para.data = (uint8_t *)data;
        getCmd.para.len = dataLen;
    }
    else
    {
        getCmd.has_para = 0;
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = display_cmd__pack(&getCmd, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GCODE_GET_CMD_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {unsigned char} flag
 * @param {unsigned char} len
 * @param {char} *data
 */
int SetPrinterDataToManager(unsigned char flag, unsigned char dataLen, char *data)
{
    CrLogI("SetPrinter flag = %d, len = %d", flag, dataLen);
    if (data) CrLogI("SetPrinter data = %s\n", data);

    DisplayCmd setCmd = DISPLAY_CMD__INIT;
    setCmd.flag = flag;
    if (dataLen != 0)
    {
        setCmd.has_para = 1;
        setCmd.para.data = (uint8_t *)data;
        setCmd.para.len = dataLen;
    }
    else
    {
        setCmd.has_para = 0;
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = display_cmd__pack(&setCmd, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GCODE_SET_CMD_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {unsigned char} flag
 */
int SetPrinterRefreshToManager(unsigned char flag)
{
    CrLogI("SetPrinter Refresh flag = %d", flag);

    DisplayCmd control = DISPLAY_CMD__INIT;
    control.has_refresh = 1;
    control.refresh = flag;

    GET_MESSAGE_BUFF(buff);
    size_t len = display_cmd__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_INTERACT_CONTROL_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {unsigned char} flag
 */
int SetPrinterBuzzerToManager(unsigned char flag)
{
    CrLogI("SetPrinter buzzer flag = %d", flag);

    DisplayCmd control = DISPLAY_CMD__INIT;
    control.has_sound = 1;
    control.sound = flag;

    GET_MESSAGE_BUFF(buff);
    size_t len = display_cmd__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_INTERACT_CONTROL_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    
    return 0;
}
