/*
 * @Description : SysTransfer管理器
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:09
 * @LastEditTime: 2023-08-23 14:31:17
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
#include <arpa/inet.h>
#include <sys/un.h>
#include <sys/select.h>

#include "Base/MasterMsgBase.h"
#include "SysTransfer.h"

#ifdef CROSS_COMPILE
#include <unistd.h>
#include <libubox/blobmsg_json.h>
#include "libubus.h"
#endif

#define SYS_SOCKET_PATH         "/tmp/sys_sock"

/**
 * @description: 静态变量声明
 * @param  {*}
 * @return {*}
 */
static MsgHandle_t msgHandle;
static int managerMsgId = -1;
#ifdef CROSS_COMPILE
static struct ubus_context *ctx;
#endif

/**
 * @description: 静态函数声明
 */
static int SendMsgBuff(MsgHeadBuf_t *data, size_t len);



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
static void msgUpdata(void)
{
    MsgHeadBuf_t head;
    ssize_t headSize = RECV_MESSAGE_PACKAGE(managerMsgId, &head);
    
    if (headSize > 0)
    {
        CrLogI("package len = %ld, origin %d, cmd %d, message len %ld", headSize, head.origin, head.cmd, head.bufLen);

        switch (head.cmd)
        {
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
 * @description: 管理器主线程
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
static void *ManagerThread(void *arg)
{
    // 创建消息队列
    managerMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_SYS_TRANSFER);
    if (managerMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }

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
 * @param {char} *res
 */
static void UpdataScannerClientState(char *res)
{
    json_object *stateObj = json_tokener_parse(res);
    if (stateObj == NULL) return;

    CrLogI("get scanner connect state\n");
    if (json_object_is_type(stateObj, json_type_object))
    {
        // 获取扫码枪连接状态
        json_object *scannerPluggedObj = json_object_object_get(stateObj, "usb_keyboard_plugged");
        if (scannerPluggedObj != NULL && json_object_is_type(scannerPluggedObj, json_type_int)) {
            int scanner_plugged = json_object_get_int(scannerPluggedObj);
            CrLogI("scanner plugged = %d\n", scanner_plugged);
            UpdataScannerOnline(scanner_plugged);
        }
        else CrLogW("plugged Obj fail\n");
    }

    json_object_put(stateObj);
}

/**
 * @description: 
 * @return {*}
 * @param {char} *res
 */
static void UpdataLaserClientState(char *res)
{
    json_object *stateObj = json_tokener_parse(res);
    if (stateObj == NULL) return;

    CrLogI("get laser connect state\n");
    if (json_object_is_type(stateObj, json_type_object))
    {
        // 获取激光连接状态
        json_object *laserPluggedObj = json_object_object_get(stateObj, "laser_plugged");
        if (laserPluggedObj != NULL && json_object_is_type(laserPluggedObj, json_type_int)) {
            int laser_plugged = json_object_get_int(laserPluggedObj);
            CrLogI("laser plugged = %d\n", laser_plugged);
            UpdataLaserOnline(laser_plugged);
        }
        else CrLogW("plugged Obj fail\n");
    }

    json_object_put(stateObj);
}

/**
 * @description: 
 * @return {*}
 * @param {char} *res
 */
static void UpdataUdiskClientState(char *res)
{
    json_object *stateObj = json_tokener_parse(res);
    if (stateObj == NULL) return;

    CrLogI("get udisk mount state");
    if (json_object_is_type(stateObj, json_type_object))
    {
        // 解析U盘状态
        json_object *udisksObj = json_object_object_get(stateObj, "udisks");
        if (udisksObj != NULL && json_object_is_type(udisksObj, json_type_object))
        {
            json_object *udisk_0Obj = json_object_object_get(udisksObj, "udisk_0");
            if (udisk_0Obj != NULL && json_object_is_type(udisk_0Obj, json_type_object))
            {
                // 更新U盘路径
                char *fileInfoPath = GetUserLocalUdiskPtah();
                memset(fileInfoPath, 0, strlen(fileInfoPath));

                // 获取U盘挂载状态
                json_object *mountObj = json_object_object_get(udisk_0Obj, "mount");
                if (mountObj != NULL && json_object_is_type(mountObj, json_type_int)) {
                    int udiskMount = json_object_get_int(mountObj);
                    CrLogI("udisk mount = %d", udiskMount);
                    UpdataUdiskMount(udiskMount, UDISK_0);
                }
                else CrLogW("mount Obj fail\n");

                // 获取U盘文件路径
                json_object *pathObj = json_object_object_get(udisk_0Obj, "path");
                if (pathObj != NULL && json_object_is_type(pathObj, json_type_string))
                {
                    memcpy(fileInfoPath, (char*)json_object_get_string(pathObj), json_object_get_string_len(pathObj));
                    CrLogI("updata udisk path = %s", fileInfoPath);
                }
                else CrLogW("path Obj fail\n");

                // 同步到其他服务进程
                UpdataUDiskPath(fileInfoPath);
                // 同步到其他服务进程
                SendString path = SEND_STRING__INIT;
                path.str.data = (uint8_t*)fileInfoPath;
                path.str.len = strlen(fileInfoPath);

                GET_MESSAGE_BUFF(buff);
                size_t len = send_string__pack(&path, buff);
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_SYS_TRANSFER, MANAGER_SYNC_UDISK_STATE, buff, len);
                MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
            }
            else CrLogW("udisk_0 Obj fail\n");
        }
        else CrLogW("udisks Obj fail\n");
    }

    json_object_put(stateObj);
}

/**
 * @description: 
 * @return {*}
 * @param {char} *res
 */
static void UpdataEthernetClientState(char *res)
{
    json_object *stateObj = json_tokener_parse(res);
    if (stateObj == NULL) return;

    CrLogI("get ethernet connect state");
    if (json_object_is_type(stateObj, json_type_object))
    {
        // 获取以太网连接状态
        json_object *pluggedObj = json_object_object_get(stateObj, "plugged");
        if (pluggedObj != NULL && json_object_is_type(pluggedObj, json_type_int)) {
            int plugged = json_object_get_int(pluggedObj);
            CrLogI("ethernet plugged = %d", plugged);
            UpdataEthernetExists(plugged);

            // 重新获取IP地址
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_SYS_TRANSFER, MANAGER_CMD_WIFI_USER_GET_WIFI_INFO_REQ, "", 0);
            MANAGER_MSG_SEND(MSG_ORIGIN_WIFI_MANAGER, &send, size);
        }
        else CrLogW("plugged Obj fail\n");
    }

    json_object_put(stateObj);
}

/**
 * @description: 
 * @return {*}
 * @param {char} *res
 */
static void UpdataCameraClientState(char *res)
{
    json_object *stateObj = json_tokener_parse(res);
    if (stateObj == NULL) return;

    CrLogI("get camera connect state");
    if (json_object_is_type(stateObj, json_type_object))
    {
        // 解析摄像头状态
        json_object *camerasObj = json_object_object_get(stateObj, "cameras");
        if (camerasObj != NULL && json_object_is_type(camerasObj, json_type_object))
        {
            // 主摄像头
            json_object *camera_mainObj = json_object_object_get(camerasObj, "camera_main");
            if (camera_mainObj != NULL && json_object_is_type(camera_mainObj, json_type_object))
            {
                // 获取摄像头连接状态
                json_object *onlineObj = json_object_object_get(camera_mainObj, "online");
                if (onlineObj != NULL && json_object_is_type(onlineObj, json_type_int)) {
                    int online = json_object_get_int(onlineObj);
                    CrLogI("camera_main online = %d", online);
                    UpdataCameraOnline(online, CAMERA_MODEL);

                    // 根据摄像头状态，创建临时文件，给klipper判断摄像头状态
                    char *cameraTemp = "/tmp/camera_main";
                    if (online == 1) {
                        if (access(cameraTemp, F_OK) != 0) system("touch /tmp/camera_main");
                    }
                    else {
                        if (access(cameraTemp, F_OK) == 0) remove(cameraTemp);
                    }
                }
                else CrLogW("online Obj fail\n");
            }
            else CrLogW("camera_main Obj fail\n");

            // 从摄像头
            json_object *camera_subObj = json_object_object_get(camerasObj, "camera_sub");
            if (camera_subObj != NULL && json_object_is_type(camera_subObj, json_type_object))
            {
                // 获取摄像头连接状态
                json_object *onlineObj = json_object_object_get(camera_subObj, "online");
                if (onlineObj != NULL && json_object_is_type(onlineObj, json_type_int)) {
                    int online = json_object_get_int(onlineObj);
                    CrLogI("camera_sub online = %d", online);
                    UpdataCameraOnline(online, CAMERA_NOZZLE);
                }
                else CrLogW("online Obj fail\n");
            }
            else CrLogW("camera_sub Obj fail\n");
        }
        else CrLogW("cameras Obj fail\n");
    }

    json_object_put(stateObj);
}

#ifdef CROSS_COMPILE
/**
 * @description: 
 * @return {*}
 */
static int recv_scanner_status_cb(struct ubus_context *ctx, struct ubus_object *obj,
                struct ubus_request_data *req,
                const char *method, struct blob_attr *msg)
{
    if (!msg) return -1;

    char *str = blobmsg_format_json_indent(msg, true, 0);
    CrLogI("\n%s\n", str);
    UpdataScannerClientState(str);
    free(str);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static void proc_scanner_status_cb(struct ubus_request *req,
                    int type, struct blob_attr *msg)
{
    if (!msg) return;

    char *str = blobmsg_format_json_indent(msg, true, 0);
    CrLogI("\n%s\n", str);
    UpdataScannerClientState(str);
    free(str);
}

/**
 * @description: 
 * @return {*}
 */
static struct ubus_subscriber scanner_sub = {
    .cb = recv_scanner_status_cb,
};

/**
 * @description: 
 * @return {*}
 */
static void scanner_client_main(void)
{
    uint32_t id;
    int ret;

    if (ubus_lookup_id(ctx, "usb_keyboard", &id)) {
        CrLogW("Failed to look up usb_keyboard object\n");
        return;
    }

    ubus_invoke(ctx, id, "status", NULL, proc_scanner_status_cb, NULL, 1000);

    ret = ubus_register_subscriber(ctx, &scanner_sub);
    if (ret)
        CrLogW("Failed to add ubus_register_subscriber: %s\n", ubus_strerror(ret));

    ret = ubus_subscribe(ctx, &scanner_sub, id);
    if (ret)
        CrLogW("Failed to ubus_subscribe: %s\n", ubus_strerror(ret));
}

/**
 * @description: 
 * @return {*}
 */
static int recv_laser_status_cb(struct ubus_context *ctx, struct ubus_object *obj,
                struct ubus_request_data *req,
                const char *method, struct blob_attr *msg)
{
    if (!msg) return -1;

    char *str = blobmsg_format_json_indent(msg, true, 0);
    CrLogI("\n%s\n", str);
    UpdataLaserClientState(str);
    free(str);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static void proc_laser_status_cb(struct ubus_request *req,
                    int type, struct blob_attr *msg)
{
    if (!msg) return;

    char *str = blobmsg_format_json_indent(msg, true, 0);
    CrLogI("\n%s\n", str);
    UpdataLaserClientState(str);
    free(str);
}

/**
 * @description: 
 * @return {*}
 */
static struct ubus_subscriber laser_sub = {
    .cb = recv_laser_status_cb,
};

/**
 * @description: 
 * @return {*}
 */
static void laser_client_main(void)
{
    uint32_t id;
    int ret;

    if (ubus_lookup_id(ctx, "laser", &id)) {
        CrLogW("Failed to look up laser object\n");
        return;
    }

    ubus_invoke(ctx, id, "status", NULL, proc_laser_status_cb, NULL, 1000);

    ret = ubus_register_subscriber(ctx, &laser_sub);
    if (ret)
        CrLogW("Failed to add ubus_register_subscriber: %s\n", ubus_strerror(ret));

    ret = ubus_subscribe(ctx, &laser_sub, id);
    if (ret)
        CrLogW("Failed to ubus_subscribe: %s\n", ubus_strerror(ret));
}

/**
 * @description: 
 * @return {*}
 */
static int recv_udisk_status_cb(struct ubus_context *ctx, struct ubus_object *obj,
                struct ubus_request_data *req,
                const char *method, struct blob_attr *msg)
{
    if (!msg) return -1;

    char *str = blobmsg_format_json_indent(msg, true, 0);
    CrLogI("\n%s", str);
    UpdataUdiskClientState(str);
    free(str);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static void proc_udisk_status_cb(struct ubus_request *req,
                    int type, struct blob_attr *msg)
{
    if (!msg) return;

    char *str = blobmsg_format_json_indent(msg, true, 0);
    CrLogI("\n%s", str);
    UpdataUdiskClientState(str);
    free(str);
}

/**
 * @description: 
 * @return {*}
 */
static struct ubus_subscriber udisk_sub = {
    .cb = recv_udisk_status_cb,
};

/**
 * @description: 
 * @return {*}
 */
static void udisk_client_main(void)
{
    uint32_t id;
    int ret;

    if (ubus_lookup_id(ctx, "udisk", &id)) {
        CrLogE("Failed to look up udisk object\n");
        return;
    }

    ubus_invoke(ctx, id, "status", NULL, proc_udisk_status_cb, NULL, 1000);

    ret = ubus_register_subscriber(ctx, &udisk_sub);
    if (ret)
        CrLogE("Failed to add ubus_register_subscriber: %s\n", ubus_strerror(ret));

    ret = ubus_subscribe(ctx, &udisk_sub, id);
    if (ret)
        CrLogE("Failed to ubus_subscribe: %s\n", ubus_strerror(ret));

}

/**
 * @description: 
 * @return {*}
 */
static int recv_ethernet_status_cb(struct ubus_context *ctx, struct ubus_object *obj,
                struct ubus_request_data *req,
                const char *method, struct blob_attr *msg)
{
    if (!msg) return -1;

    char *str = blobmsg_format_json_indent(msg, true, 0);
    CrLogI("\n%s", str);
    UpdataEthernetClientState(str);
    free(str);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static void proc_ethernet_status_cb(struct ubus_request *req,
                    int type, struct blob_attr *msg)
{
    if (!msg) return;

    char *str = blobmsg_format_json_indent(msg, true, 0);
    CrLogI("\n%s", str);
    UpdataEthernetClientState(str);
    free(str);
}

/**
 * @description: 
 * @return {*}
 */
static struct ubus_subscriber ethernet_sub = {
    .cb = recv_ethernet_status_cb,
};

/**
 * @description: 
 * @return {*}
 */
static void ethernet_client_main(void)
{
    uint32_t id;
    int ret;

    if (ubus_lookup_id(ctx, "ethernet", &id)) {
        CrLogE("Failed to look up ethernet object\n");
        return;
    }

    ubus_invoke(ctx, id, "status", NULL, proc_ethernet_status_cb, NULL, 1000);

    ret = ubus_register_subscriber(ctx, &ethernet_sub);
    if (ret)
        CrLogE("Failed to add ubus_register_subscriber: %s\n", ubus_strerror(ret));

    ret = ubus_subscribe(ctx, &ethernet_sub, id);
    if (ret)
        CrLogE("Failed to ubus_subscribe: %s\n", ubus_strerror(ret));

}

/**
 * @description: 
 * @return {*}
 */
static int recv_camera_status_cb(struct ubus_context *ctx, struct ubus_object *obj,
                struct ubus_request_data *req,
                const char *method, struct blob_attr *msg)
{
    if (!msg) return -1;

    char *str = blobmsg_format_json_indent(msg, true, 0);
    CrLogI("\n%s", str);
    UpdataCameraClientState(str);
    free(str);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static void proc_camera_status_cb(struct ubus_request *req,
                    int type, struct blob_attr *msg)
{
    if (!msg) return;

    char *str = blobmsg_format_json_indent(msg, true, 0);
    CrLogI("\n%s", str);
    UpdataCameraClientState(str);
    free(str);
}

/**
 * @description: 
 * @return {*}
 */
static struct ubus_subscriber camera_sub = {
    .cb = recv_camera_status_cb,
};

/**
 * @description: 
 * @return {*}
 */
static void camera_client_main(void)
{
    uint32_t id;
    int ret;

    if (ubus_lookup_id(ctx, "camera", &id)) {
        CrLogE("Failed to look up camera object\n");
        return;
    }

    ubus_invoke(ctx, id, "status", NULL, proc_camera_status_cb, NULL, 1000);

    ret = ubus_register_subscriber(ctx, &camera_sub);
    if (ret)
        CrLogE("Failed to add ubus_register_subscriber: %s\n", ubus_strerror(ret));

    ret = ubus_subscribe(ctx, &camera_sub, id);
    if (ret)
        CrLogE("Failed to ubus_subscribe: %s\n", ubus_strerror(ret));
}
#endif

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *PeripheralMonitorThread(void *arg)
{
    // 应用启动正常后，延时再开始检测外设器件
    sleep(2);

    #ifdef CROSS_COMPILE
    const char *ubus_socket = NULL;
    uloop_init();

    ctx = ubus_connect(ubus_socket);
    if (!ctx) {
        CrLogE("Failed to connect to ubus\n");
        return NULL;
    }

    ubus_add_uloop(ctx);

    udisk_client_main();
    ethernet_client_main();
    camera_client_main();
    laser_client_main();
    scanner_client_main();

    uloop_run();

    ubus_free(ctx);
    uloop_done();
    #endif

    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *ListenSystemNotifyThread(void *arg)
{
    // 避免因文件已存在导致的bind()失败
    unlink(SYS_SOCKET_PATH);

    // 绑定本地套接字文件
    struct sockaddr_un serverAddr;
    serverAddr.sun_family = AF_LOCAL;
    strcpy(serverAddr.sun_path, SYS_SOCKET_PATH);

    // 创建socket
    int serverSockFd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (serverSockFd == -1) {
		CrLogW("create socket error %s",strerror(errno));
		goto THREAD_END;
	}

    // 绑定socket
    int bindResult = bind(serverSockFd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (bindResult == -1) {
        CrLogW("remote debug bind error %s",strerror(errno));
        goto THREAD_END;
    }

    // 监听
    int listenResult = listen(serverSockFd, 5);
    if (listenResult == -1) {
        CrLogW("remote debug listen error %s",strerror(errno));
        goto THREAD_END;
    }

    // 等待客户端连接
    while(1) {
        struct sockaddr_un clientAddress;
        socklen_t addressLen = sizeof(clientAddress);
        int clientSockFd = accept(serverSockFd, (struct sockaddr *)&clientAddress, &addressLen);
        CrLogI("new connection clientSockFd = %d\n", clientSockFd);

        if (clientSockFd > 0) {
            // 设置系统状态监听
            fd_set fs_read;
            FD_ZERO(&fs_read); //每次循环都要清空集合，否则不能检测描述符变化
            FD_SET(clientSockFd, &fs_read); //添加描述符

            struct timeval time;
            time.tv_sec = 0; //set the rcv wait time
            time.tv_usec = 10 * 1000; //100000us = 0.1s

            // 超时等待读变化，>0：就绪描述字的正数目， -1：出错， 0 ：超时
            if (select(clientSockFd + 1, &fs_read, NULL, NULL, &time))
            {
                char recvMsg[4096] = {0};
                long byteNum = recv(clientSockFd, recvMsg, 4096, 0);

                if (byteNum > 0) {
                    CrLogI("recvMsg = %s\n", recvMsg);
                    if ((strncmp(recvMsg, "console", strlen("console")) || strncmp(recvMsg, "ssh", strlen("ssh"))) &&
                        GetSystemConfig().creality_num != 1)
                    {
                        SystemConfigProto config = SYSTEM_CONFIG_PROTO__INIT;
                        config.has_creality_num = 1;
                        config.creality_num = 1;
                        UpdataSystemConfig(&config);
                    }
                }
                else CrLogW("client recv fail\n");
            }
            else CrLogW("recv time out\n\n");

            close(clientSockFd);
        }
    }

    close(serverSockFd);
    return 0;

THREAD_END:
    if (serverSockFd > 0) close(serverSockFd);
    return -1;
}

/**
 * @description: 管理器初始化
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
MsgHandle_t *SysTransferInit(void *arg)
{
    CrLogI("SysTransfer init");
    int res = pthread_create(&msgHandle.handle, NULL, (void*)ManagerThread, arg);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return NULL;
    }
    msgHandle.sendMsgBuff = &SendMsgBuff;

    // 创建监听外设器件状态
    pthread_t peripheralMonitorHandle;
    res = pthread_create(&peripheralMonitorHandle, NULL, (void*)PeripheralMonitorThread, arg);
    if (res) {
        CrLogE("create pthread error!\n");
        return NULL;
    }

    // 创建监听系统通知状态
    pthread_t listenSystemNotifyHandle;
    res = pthread_create(&listenSystemNotifyHandle, NULL, (void*)ListenSystemNotifyThread, arg);
    if (res) {
        CrLogE("create pthread error!\n");
        return NULL;
    }
    pthread_detach(listenSystemNotifyHandle);
    
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
 * @description: 
 * @param  {*}
 * @return {*}
 */
int SysTransferExceptionHandleSemPost(void)
{
    return 0;
}
