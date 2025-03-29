/*
 * @Description : 通信管理
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:09
 * @LastEditTime: 2023-08-23 15:20:40
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

#include "Base/UpgradeMsgBase.h"
#include "ServerMessage.h"

static pthread_t messageHandle;
static int managerMsgId = -1;
static int serverMsgId = -1;
static SystemConfig_t systemComfig = {0}; // 系统配置文件
static SystemConfig_t lastSystemComfig = {0}; // 系统前一次配置文件
static UpgradeFilePath_t upgradeFilePath = {0};

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
    str.dialogue = "I am upgrade server!";

    GET_MESSAGE_BUFF(buff);
    size_t len = server_test__pack(&str, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_UPGRADE_SERVER, SERVER_CMD_UPGRADE_TEST_ANS, buff, len);

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
 * @return {*}
 * @param {void} *arg
 */
static void *LinuxUpgradeThread(void *arg)
{
    CrLogI("start system upgrade ...");
    // 固件路径
    char *upgradePath = (char*) arg;
    CrLogI("upgrade image path = %s\n", upgradePath);

    // 调用系统命令
    char sysRes[1024] = {0};
    if (!PopenSystem((char*)"sync", sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);

    // 启动命令
    char upgradeCmd[512] = {0};
    snprintf(upgradeCmd, 512, "%s '%s'", GetDefaultStartUpgradeScript(), upgradePath);
    CrLogI("upgradeCmd = %s\n", upgradeCmd);
    
    // 调用系统命令
    char upgradeRes[1024 * 1024] = {0};
    #ifdef CROSS_COMPILE
    PopenSystem(upgradeCmd, upgradeRes, sizeof(upgradeRes));
    #endif

    // 输出升级脚本日志
    CrLogI("upgrade result len = %d", strlen(upgradeRes));
    char *answer = strtok(upgradeRes, "\n");
    while (answer)
    {
        CrLogI("%s", answer);
        // 判断升级是否成功
        if (strstr(answer, "ota update ok")) {
            CrLogI("system upgrade success\n\n");
            pthread_exit("true");
        }
        answer = strtok(NULL, "\n");
    }

    CrLogE("system upgrade fail\n\n");
    pthread_exit("false");
    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *HostMcuUpgradeThread(void *arg)
{
    #define OUT_TIME_COUNT_TIMERS       10
    #define RETRY_COUNT_TIMERS          1
    #define MCU_RESET_COUNT_TIMERS      1

    // 固件路径
    char *upgradePath = (char*) arg;
    CrLogI("upgrade bin path = %s\n", upgradePath);

    // 复制bin文件到指定升级目录
    char cpCmd[512] = {0};
    snprintf(cpCmd, sizeof(cpCmd), "cp '%s' '%s' && sync", upgradePath, GetMcuSwdUpgradeFilePath());
    // 调用系统命令
    char sysRes[1024] = {0};
    if (!PopenSystem(cpCmd, sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);

    // 启动 mcu1 SWD升级
    CrLogI("mcu1 SWD upgrade ...");
    bzero(sysRes, sizeof(sysRes));
    #ifdef CROSS_COMPILE
    if (!PopenSystem(GetDefaultMcuSwdUpgradeCmd(), sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);
    #endif
    CrLogI("swd cmd = %s", GetDefaultMcuSwdUpgradeCmd());

    // 延时等待升级启动，再查询升级进度及结果
    sleep(3);
    int outTimeCount = 0; // 升级失败，超时计数
    int retryCount = 0; // 升级失败，重试次数
    int mcuResetCount = 0; // 升级失败，MCU复位次数

    while (1)
    {
        if (++outTimeCount >= OUT_TIME_COUNT_TIMERS) // 升级超时等待计数
        {
            outTimeCount = 0;
            if (++retryCount > RETRY_COUNT_TIMERS)
            {
                retryCount = 0;
                if (++mcuResetCount > MCU_RESET_COUNT_TIMERS) {
                    CrLogI("mcu upgrade fail!!\n");
                    break;
                }
                // 重启下位机
                CrLogW("reset host mcu\n");

                // 等待下位机启动
                usleep(500 * 1000);
            }

            // 重新发送升级指令
            bzero(sysRes, sizeof(sysRes));
            #ifdef CROSS_COMPILE
            if (!PopenSystem(GetDefaultMcuSwdUpgradeCmd(), sysRes, sizeof(sysRes)))
                CrLogW("system fail! res = %s\n", sysRes);
            #endif
            CrLogI("swd cmd = %s", GetDefaultMcuSwdUpgradeCmd());

            // 延时等待升级启动，再查询升级进度及结果
            sleep(3);
        }

        // 查询升级进度
        char progress[10] = {0};
        #ifdef CROSS_COMPILE
        if (!PopenSystem(GetDefaultMcuSwdUpgradeProgress(), progress, sizeof(progress)))
            CrLogW("system fail! res = %s\n", progress);
        #endif
        CrLogI("swd progress = %s", progress);

        // 判断是否升级成功
        if (strstr(progress, "100")) {
            CrLogI("mcu upgrade success!!\n");
            pthread_exit("true");
            break;
        }

        sleep(1);
    }

    pthread_exit("false");
    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *NozzleMcuUpgradeThread(void *arg)
{
    pthread_exit("false");
    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *BedMcuUpgradeThread(void *arg)
{
    pthread_exit("false");
    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *UpgradeThread(void *arg)
{
    // 获取升级固件路径
    UpgradeFilePath_t *path = (UpgradeFilePath_t*) arg;
    CrLogI("upgrade file path:");
    CrLogI("linux = %s", path->linux1);
    CrLogI("host = %s", path->hostMcu);
    CrLogI("nozzle = %s", path->nozzleMcu);
    CrLogI("bed = %s\n", path->bedMcu);

    // 定义升级结果消息体
    UpgradeInfo linux1 = UPGRADE_INFO__INIT;
    UpgradeInfo hostMcu = UPGRADE_INFO__INIT;
    UpgradeInfo nozzleMcu = UPGRADE_INFO__INIT;
    UpgradeInfo bedMcu = UPGRADE_INFO__INIT;
    UpgradeInfoList list = UPGRADE_INFO_LIST__INIT;

    // 多线程升级句柄
    pthread_t linuxUpgradeHandle;
    pthread_t hostMcuUpgradeHandle;
    pthread_t nozzleMcuUpgradeHandle;
    pthread_t bedMcuUpgradeHandle;

    // 通过判断是否有固件路径，启动升级
    if (strlen(path->linux1) > 0) {
        CrLogI("start linux upgrade");
        linux1.has_state = 1;
        linux1.state = UPGRADE_INSTALL_ING;
        linux1.has_progress = 1;
        linux1.progress = 0;
        list.linuxlocal = &linux1;
        
        if (pthread_create(&linuxUpgradeHandle, NULL, (void*)LinuxUpgradeThread, (void*)path->linux1)) {
            CrLogE("create pthread error!\n");
        }
    }
    if (strlen(path->hostMcu) > 0) {
        CrLogI("start host mcu upgrade");
        hostMcu.has_state = 1;
        hostMcu.state = UPGRADE_INSTALL_ING;
        hostMcu.has_progress = 1;
        hostMcu.progress = 0;
        list.mcu1local = &hostMcu;

        if (pthread_create(&hostMcuUpgradeHandle, NULL, (void*)HostMcuUpgradeThread, (void*)path->hostMcu)) {
            CrLogE("create pthread error!\n");
        }
    }
    if (strlen(path->nozzleMcu) > 0) {
        CrLogI("start nozzle mcu upgrade");
        nozzleMcu.has_state = 1;
        nozzleMcu.state = UPGRADE_INSTALL_ING;
        nozzleMcu.has_progress = 1;
        nozzleMcu.progress = 0;
        list.mcu2local = &nozzleMcu;

        if (pthread_create(&nozzleMcuUpgradeHandle, NULL, (void*)NozzleMcuUpgradeThread, (void*)path->nozzleMcu)) {
            CrLogE("create pthread error!\n");
        }
    }
    if (strlen(path->bedMcu) > 0) {
        CrLogI("start bed mcu upgrade");
        bedMcu.has_state = 1;
        bedMcu.state = UPGRADE_INSTALL_ING;
        bedMcu.has_progress = 1;
        bedMcu.progress = 0;
        list.mcu3local = &bedMcu;
        
        if (pthread_create(&bedMcuUpgradeHandle, NULL, (void*)BedMcuUpgradeThread, (void*)path->bedMcu)) {
            CrLogE("create pthread error!\n");
        }
    }

    // 报告升级状态
    GET_MESSAGE_BUFF(buff);
    size_t len = upgrade_info_list__pack(&list, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_UPGRADE_SERVER, SERVER_CMD_START_UPGRADE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    // 判断各个线程是否升级完成
    void *pthreadResult = NULL;
    if (strlen(path->linux1) > 0) {
        pthread_join(linuxUpgradeHandle, &pthreadResult);
        CrLogI("upgrade linux result = %s", (char*)pthreadResult);
        
        if (strstr(pthreadResult, "true")) linux1.state = UPGRADE_INSTALL_OK;
        else linux1.state = UPGRADE_INSTALL_FAIL;
    }
    if (strlen(path->hostMcu) > 0) {
        pthread_join(hostMcuUpgradeHandle, &pthreadResult);
        CrLogI("upgrade host mcu = %s", (char*)pthreadResult);

        if (strstr(pthreadResult, "true")) hostMcu.state = UPGRADE_INSTALL_OK;
        else hostMcu.state = UPGRADE_INSTALL_FAIL;
    }
    if (strlen(path->nozzleMcu) > 0) {
        pthread_join(nozzleMcuUpgradeHandle, &pthreadResult);
        CrLogI("upgrade nozzle mcu = %s", (char*)pthreadResult);

        if (strstr(pthreadResult, "true")) nozzleMcu.state = UPGRADE_INSTALL_OK;
        else nozzleMcu.state = UPGRADE_INSTALL_FAIL;
    }
    if (strlen(path->bedMcu) > 0) {
        pthread_join(bedMcuUpgradeHandle, &pthreadResult);
        CrLogI("upgrade bed mcu result = %s", (char*)pthreadResult);

        if (strstr(pthreadResult, "true")) bedMcu.state = UPGRADE_INSTALL_OK;
        else bedMcu.state = UPGRADE_INSTALL_FAIL;
    }

    // 报告升级状态
    GET_MESSAGE_BUFF(buff1);
    size_t len1 = upgrade_info_list__pack(&list, buff1);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_UPGRADE_SERVER, SERVER_CMD_START_UPGRADE_ANS, buff1, len1);
    SendProcessMsgBuff(&send1, size1);

    // 结束线程，释放资源
    pthread_detach(pthread_self());
    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserStartUpgradeReq(MsgHeadBuf_t *head)
{
    UpgradeInfoList *list = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!list) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Receive an upgrade request, check if an upgrade is required");
    bzero(&upgradeFilePath, sizeof(UpgradeFilePath_t));

    // 判断是否存在升级请求，记录升级文件路径
    if (list->linuxlocal && list->linuxlocal->has_imagepath) {
        CrLogI("upgrade linux");
        memcpy(upgradeFilePath.linux1, list->linuxlocal->imagepath.data, list->linuxlocal->imagepath.len);
    }
    if (list->mcu1local && list->mcu1local->has_imagepath) {
        CrLogI("upgrade mcu1");
        memcpy(upgradeFilePath.hostMcu, list->mcu1local->imagepath.data, list->mcu1local->imagepath.len);
    }
    if (list->mcu2local && list->mcu2local->has_imagepath) {
        CrLogI("upgrade mcu2");
        memcpy(upgradeFilePath.nozzleMcu, list->mcu2local->imagepath.data, list->mcu2local->imagepath.len);
    }
    if (list->mcu3local && list->mcu3local->has_imagepath) {
        CrLogI("upgrade mcu3");
        memcpy(upgradeFilePath.bedMcu, list->mcu3local->imagepath.data, list->mcu3local->imagepath.len);
    }

    // 创建新线程，启动后台升级
    pthread_t upgradeHandle;
    if (pthread_create(&upgradeHandle, NULL, (void*)UpgradeThread, (void*)&upgradeFilePath)) {
        CrLogE("create pthread error!\n");
    }

    upgrade_info_list__free_unpacked(list, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerSyncSystemConfig(MsgHeadBuf_t *head)
{
    SystemConfigProto *config = system_config_proto__unpack(NULL, head->bufLen, head->buf);
    if (!config) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Manager Sync System Config");
    memset(&systemComfig, 0, sizeof(SystemConfig_t));
    memcpy(systemComfig.sys_version, config->sys_version.data, config->sys_version.len);
    memcpy(systemComfig.hw_version, config->hw_version.data, config->hw_version.len);
    systemComfig.model = config->model;
    memcpy(systemComfig.model_str, config->model_str.data, config->model_str.len);
    systemComfig.creality_num = config->creality_num;
    system_config_proto__free_unpacked(config, NULL);
    
    CrLogI("version; sys = %s, hw = %s, model = %d, str = %s, creality_num = %d",
            systemComfig.sys_version, systemComfig.hw_version, systemComfig.model,
            systemComfig.model_str, systemComfig.creality_num);

    // 按进程实际需求处理数据

    lastSystemComfig = systemComfig; 
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
            case SERVER_CMD_UPGRADE_TEST_REQ: ServerMessageTestReq(&head); break;
            case MANAGER_CMD_MESSAGE_TEST: ManagerMessageTest(&head); break;

            case SERVER_CMD_START_UPGRADE_REQ: UserStartUpgradeReq(&head); break;
            case SERVER_CMD_UPGRADE_SYSTEM_CONFIG_ANS: ManagerSyncSystemConfig(&head); break;

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
 * @description: 
 * @return {*}
 */
static void UpgradeInitiativeSyncManagerData(void)
{
    // 同步Linux系统配置
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_UPGRADE_SERVER, SERVER_CMD_UPGRADE_SYSTEM_CONFIG_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
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
    managerMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_UPGRADE_MANAGER);
    if (managerMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    serverMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_UPGRADE_SERVER);
    if (serverMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    // 清空消息队列
    CleanMessageQueue();
    // 同步manager数据
    UpgradeInitiativeSyncManagerData();

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
    CrLogI("upgrade server init");
    // 新开线程接收数据
    int res = pthread_create(&messageHandle, NULL, (void*)MessageThread, arg);
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
