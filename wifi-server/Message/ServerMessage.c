/*
 * @Description : 通信管理
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:09
 * @LastEditTime: 2023-09-07 14:19:13
 */

#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

#include "Base/WifiMsgBase.h"
#include "ServerMessage.h"
#include "wifiServerWpa.h"

/*********************
 *      DEFINES
 *********************/
#define STD_OUT                 1

/**
 * @description: 静态变量声明
 * @param  {*}
 * @return {*}
 */
static pthread_t messageHandle;
static int managerMsgId = -1;
static int serverMsgId = -1;

/**
 * @description: 静态函数声明
 */

/**
 * @description: 
 * @return {*}
 */
static SystemConfig_t GetSystemConfig(void)
{
    SystemConfig_t systemComfig = {0};
    json_object *tempObj = NULL;

    // 从文件读取json数据
    json_object *config = json_object_from_file(GetUserSystemConfigFilePath());
    if (config)
    {
        // 获取 user_info 的json
        json_object *userInfoObj = json_object_object_get(config, "user_info");
        if (userInfoObj)
        {
            // 获取设备部署环境
            tempObj = json_object_object_get(userInfoObj, "deploy_setting");
            if (tempObj) systemComfig.deploy_setting = json_object_get_int(tempObj);

            // 获取是否同意隐私协议
            tempObj = json_object_object_get(userInfoObj, "agree_privacy");
            if (tempObj) systemComfig.agree_privacy = json_object_get_int(tempObj);
        }
    }

    if (config) json_object_put(config);
    return systemComfig;
}

/**
 * @description: 
 * @return {*}
 */
static int GetPingNetworkAddr(char *pingAddr, int deploy_setting)
{
    // 从文件读取数据
    char *getStr = AesDecryptFromFile(GetUserIotConfigPath());
    json_object *config = NULL;
    if (getStr && (config = json_tokener_parse(getStr)))
    {
        // 选择不同服务器地址
        json_object *remoteObj = json_object_object_get(config, "cxy_remote");
        json_object *serverObj = NULL;
        
        switch (deploy_setting) {
            case CXY_CN_SERVER: serverObj = json_object_object_get(remoteObj, "cxy_cn_server"); break;
            case CXY_COM_SERVER: serverObj = json_object_object_get(remoteObj, "cxy_com_server"); break;
            case CXY_CN_PRE_SERVER: serverObj = json_object_object_get(remoteObj, "cxy_cn_pre_server"); break;
            case CXY_COM_PRE_SERVER: serverObj = json_object_object_get(remoteObj, "cxy_com_pre_server"); break;
            case CXY_TEST_SERVER: serverObj = json_object_object_get(remoteObj, "cxy_test_server"); break;
            case CXY_DEBUG_SERVER: serverObj = json_object_object_get(remoteObj, "cxy_debug_server"); break;
            default: serverObj = json_object_object_get(remoteObj, "cxy_com_server"); break;
        }

        // 获取 url
        json_object *tmpObj = json_object_object_get(serverObj, "url");
        const char *cxy_url = json_object_get_string(tmpObj);
        
        // 获取ping网络地址
        bzero(pingAddr, strlen(pingAddr));
        char *addr = strstr(cxy_url, "//");
        if (addr) strcat(pingAddr, (addr + strlen("//")));
        else strcat(pingAddr, cxy_url);
    }
    
    if (config) json_object_put(config);
    if (getStr) free(getStr);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*} 0：网络正常
 *            -1：网络异常
 *            -2：测试函数执行错误
 */
int NetworkIsOk(void)
{
    // 获取系统配置
    SystemConfig_t config = GetSystemConfig();
    if (config.agree_privacy == 0) return -1;

    // 新建一个进程来执行ping命令
    pid_t pid;
    if ((pid = vfork()) < 0)
    {
        CrLogE("vfork error");
        return -2;
    }
 
    // ping www.baidu.com
    if (pid == 0)
    {
        // 重定向输出
        int outfd = open("/dev/null", O_CREAT|O_WRONLY|O_TRUNC, 0644);
        if (!outfd) {
            CrLogE("open /dev/null fail\n");
            return -2;
        }
        dup2(outfd, STD_OUT);
        close(outfd);

        // 获取拼网络地址
        char pingAddr[256] = "8.8.8.8";
        GetPingNetworkAddr(pingAddr, config.deploy_setting);

        // ping 网络
        if (execlp("ping", "ping", "-c", "1", pingAddr, (char*)0) < 0)
        {
            CrLogE("execlp error\n");
            dup2(STD_OUT, STD_OUT);
            return -2;
        }
        dup2(STD_OUT, STD_OUT);
    }

    int status;
    waitpid(pid, &status, 0);
    // 相等说明正常
    if (status == 0)
        return 0;

    return -1;
}

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
    str.dialogue = "I am wifi server!";

    GET_MESSAGE_BUFF(buff);
    size_t len = server_test__pack(&str, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_SERVER, SERVER_CMD_WIFI_TEST_ANS, buff, len);

    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WifiScanNetworkListReq(MsgHeadBuf_t *head)
{
    CrLogI("Wifi Scan Network List Req");
    UserScanWifiList();
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WifiConnectNetworkReq(MsgHeadBuf_t *head)
{
    NetworksInfo *info = networks_info__unpack(NULL, head->bufLen, head->buf);
    if (!info) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Wifi Connect Network ssid = %s, pass = %s", info->ssid.data, info->pass.data);
    UserConnectNetworks((char*)info->ssid.data, (char*)info->pass.data);

    networks_info__free_unpacked(info, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WifiConnectSaveNetworkReq(MsgHeadBuf_t *head)
{
    NetworksInfo *info = networks_info__unpack(NULL, head->bufLen, head->buf);
    if (!info) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Wifi Connect Save Network ssid = %s", info->ssid.data);
    UserConnectSavedNetworks((char*)info->ssid.data);
    
    networks_info__free_unpacked(info, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WifiGetDeviceWifiInfoReq(MsgHeadBuf_t *head)
{
    CrLogI("Wifi Get Device Wifi Info Req");
    UserGetDeviceWifiInfo();
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WifiDisconnectNetworkReq(MsgHeadBuf_t *head)
{
    CrLogI("Wifi Disconnect Network Req");
    UserDisconnectNetworks();
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WifiRemoveNetworkReq(MsgHeadBuf_t *head)
{
    NetworksInfo *info = networks_info__unpack(NULL, head->bufLen, head->buf);
    if (!info) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Wifi Remove Network ssid = %s", info->ssid.data);
    UserRemoveNetworks((char*)info->ssid.data, info->ssid.len);
    
    networks_info__free_unpacked(info, NULL);
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
            case SERVER_CMD_WIFI_TEST_REQ: ServerMessageTestReq(&head); break;
            case SERVER_CMD_WIFI_SCAN_NETWORK_LIST_REQ: WifiScanNetworkListReq(&head); break;
            case SERVER_CMD_WIFI_CONNECT_NETWORK_REQ: WifiConnectNetworkReq(&head); break;
            case SERVER_CMD_WIFI_CONNECT_SAVE_NETWORK_REQ: WifiConnectSaveNetworkReq(&head); break;
            case SERVER_CMD_WIFI_GET_DEVICE_WIFI_INFO_REQ: WifiGetDeviceWifiInfoReq(&head); break;
            case SERVER_CMD_WIFI_DISCONNECT_NETWORK_REQ: WifiDisconnectNetworkReq(&head); break;
            case SERVER_CMD_WIFI_REMOVE_NETWORK_REQ: WifiRemoveNetworkReq(&head); break;

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
pthread_t *ServerMessageInit(void *arg)
{
    CrLogI("wifi server init");
    // 新开线程接收数据
    int res = pthread_create(&messageHandle, NULL, (void*)MessageThread, arg);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return NULL;
    }

    // WiFi状态检测
    pthread_t checkWifiStateHandle;
    res = pthread_create(&checkWifiStateHandle, NULL, (void*)CheckWifiStateThread, arg);
    if (res)
    {
        CrLogE("create pthread error!\n");
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
    ExceptionHandleFreeScanNetworksInfo();
    return 0;
}