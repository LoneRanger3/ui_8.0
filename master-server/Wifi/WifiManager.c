/*
 * @Description : wifi设备管理器
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:09
 * @LastEditTime: 2023-09-07 14:35:50
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
#include "WifiManager.h"

#define DETECT_WIFI_INFO_TIME       (30 * 100) // 10ms周期，30秒查询一次wifi信息

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
static void UserControlScanWifiAns(MsgHeadBuf_t *head)
{
    CrLogI("User Control Scan Wifi Ans");
    NetworksInfo *info = networks_info__unpack(NULL, head->bufLen, head->buf);
    if (!info) {
        CrLogW("unpack failed\n");
        return;
    }

    if (info->n_list == 0) CrLogW("Hotspot not scanned\n");
    else
    {
        CrLogI("user scan wifi list size = %d", info->n_list);
        CrLogI("num / usage / frequency / signal / ssid / bssid");
        for (int i = 0; i < info->n_list; i++)
        {
            CrLogI("[%d]\t%d\t%s\t%s\t%s\t%s", i+1,
                info->list[i]->wifiusage,
                info->list[i]->frequer.data,
                info->list[i]->signal.data,
                info->list[i]->ssid.data,
                info->list[i]->bssid.data);
        }
        CrLogI("=====================================================\n");    
    }

    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, MANAGER_CMD_WIFI_USER_SCAN_WIFI_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    networks_info__free_unpacked(info, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlConnectNetworkAns(MsgHeadBuf_t *head)
{
    CrLogI("User Control Connect Network Ans");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, MANAGER_CMD_WIFI_USER_CONNECT_NETWORK_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlConnectSaveNetworkAns(MsgHeadBuf_t *head)
{
    CrLogI("User Control Connect Save Network Ans");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, MANAGER_CMD_WIFI_USER_CONNECT_SAVE_NETWORK_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlGetWifiInfoAns(MsgHeadBuf_t *head)
{
    CrLogI("User Control Get Wifi Info Ans");
    NetworksInfo *info = networks_info__unpack(NULL, head->bufLen, head->buf);
    if (!info) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("wifi state, state: %d", info->status);
    UpdataPrintWifiState(info->status);
    if (info->has_ssid && info->has_ip)
        CrLogI("wifi change, ssid = [%s], get connect ip = %s\n", info->ssid.data, info->ip.data);

    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, MANAGER_CMD_WIFI_USER_GET_WIFI_INFO_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    networks_info__free_unpacked(info, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlDisconnectNetworkAns(MsgHeadBuf_t *head)
{
    CrLogI("User Control Disconnect Networ kAns");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, MANAGER_CMD_WIFI_USER_DISCONNECT_NETWORK_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlRemoveNetworkAns(MsgHeadBuf_t *head)
{
    CrLogI("User Control Remove Network Ans");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, MANAGER_CMD_WIFI_USER_REMOVE_NETWORK_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlScanwifiRes(MsgHeadBuf_t *head)
{
    CrLogI("User Control Scan wifi Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, SERVER_CMD_WIFI_SCAN_NETWORK_LIST_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlConnectNetworkRes(MsgHeadBuf_t *head)
{
    CrLogI("User Control Connect Network Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, SERVER_CMD_WIFI_CONNECT_NETWORK_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlConnectSaveNetworkRes(MsgHeadBuf_t *head)
{
    CrLogI("User Control Connect Save Network Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, SERVER_CMD_WIFI_CONNECT_SAVE_NETWORK_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlGetWifiInfoRes(MsgHeadBuf_t *head)
{
    CrLogI("User Control Get Wifi Info Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, SERVER_CMD_WIFI_GET_DEVICE_WIFI_INFO_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlDisconnectNetworkRes(MsgHeadBuf_t *head)
{
    CrLogI("User Control Disconnect Network Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, SERVER_CMD_WIFI_DISCONNECT_NETWORK_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlRemoveNetworkRes(MsgHeadBuf_t *head)
{
    CrLogI("User Control Remove Network Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, SERVER_CMD_WIFI_REMOVE_NETWORK_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
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
            case SERVER_CMD_WIFI_TEST_ANS: ServerMessageTestAns(&head); break;
            case SERVER_CMD_WIFI_SCAN_NETWORK_LIST_ANS: UserControlScanWifiAns(&head); break;
            case SERVER_CMD_WIFI_CONNECT_NETWORK_ANS: UserControlConnectNetworkAns(&head); break;
            case SERVER_CMD_WIFI_CONNECT_SAVE_NETWORK_ANS: UserControlConnectSaveNetworkAns(&head); break;
            case SERVER_CMD_WIFI_GET_DEVICE_WIFI_INFO_ANS: UserControlGetWifiInfoAns(&head); break;
            case SERVER_CMD_WIFI_DISCONNECT_NETWORK_ANS: UserControlDisconnectNetworkAns(&head); break;
            case SERVER_CMD_WIFI_REMOVE_NETWORK_ANS: UserControlRemoveNetworkAns(&head); break;

            case MANAGER_CMD_WIFI_USER_SCAN_WIFI_REQ: UserControlScanwifiRes(&head); break;
            case MANAGER_CMD_WIFI_USER_CONNECT_NETWORK_REQ: UserControlConnectNetworkRes(&head); break;
            case MANAGER_CMD_WIFI_USER_CONNECT_SAVE_NETWORK_REQ: UserControlConnectSaveNetworkRes(&head); break;
            case MANAGER_CMD_WIFI_USER_GET_WIFI_INFO_REQ: UserControlGetWifiInfoRes(&head); break;
            case MANAGER_CMD_WIFI_USER_DISCONNECT_NETWORK_REQ: UserControlDisconnectNetworkRes(&head); break;
            case MANAGER_CMD_WIFI_USER_REMOVE_NETWORK_REQ: UserControlRemoveNetworkRes(&head); break;

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
    managerMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_WIFI_MANAGER);
    if (managerMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    serverMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_WIFI_SERVER);
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
 * @description: 
 * @return {*}
 */
static int CycleDetectWifiInfo(void)
{
    static int detectCount = 0;
    if (++detectCount >= DETECT_WIFI_INFO_TIME)
    {
        detectCount = 0;
        if (GetPrintState().wifiState == WIFI_STATE_CONNECTED ||
            GetPrintState().wifiState == WIFI_STATE_NETWORK)
        {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_MANAGER, SERVER_CMD_WIFI_GET_DEVICE_WIFI_INFO_REQ, "", 0);
            SendProcessMsgBuff(&send, size);
        }
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *RunThread(void *arg)
{
    while (1)
    {
        CycleDetectWifiInfo();
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
MsgHandle_t *WifiManagerInit(void *arg)
{
    CrLogI("wifi manager init");
    int res = pthread_create(&msgHandle.handle, NULL, (void*)ManagerThread, arg);
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
int WifiManagerExceptionHandleSemPost(void)
{
    return 0;
}