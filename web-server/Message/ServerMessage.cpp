/**
 * @ Author: Rui Xiong
 * @ Create Time: 2022-11-11 15:42:32
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-04-20 14:36:12
 * @ Description:
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
#include <iostream>
#include "Base/WebMsgBase.h"
#include "DataManager/DataManager.h"
#include "ServerMessage.h"
#include "Server/Httpd.h"
#include <inotifytools/inotifytools.h>
#include <inotifytools/inotify.h>
#include "DataManager/CommondProc.h"
#include "DataManager/AttributeProc.h"

#define GET_SYS_VERSION_COUNT_MAX       10

static pthread_t messageHandle;
static int managerMsgId = -1;
static int serverMsgId = -1;
static sem_shm_t printObjectShm = {0};

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
    str.dialogue = (char*)"I am web server!";

    GET_MESSAGE_BUFF(buff);
    size_t len = server_test__pack(&str, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_TEST_ANS, buff, len);

    SendProcessMsgBuff(&send, size);
}

// /**
//  * @description: 
//  * @return {*}
//  * @param {MsgHeadBuf_t} *head
//  */
// static void ManagerSystemResetRes(MsgHeadBuf_t *head)
// {
//     if (remove(GetUserIotConfigPath()) != 0)
//         CrLogW("remove iot config fail\n");
    
//     GeneralRes res = GENERAL_RES__INIT;
//     res.result = 1;

//     GET_MESSAGE_BUFF(buff);
//     size_t len = general_res__pack(&res, buff);
//     CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_SYSTEM_RESET_ANS, buff, len);
//     SendProcessMsgBuff(&send, size);
// }

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WebGetGcodeFileListAns(MsgHeadBuf_t *head)
{
    SendString *path = send_string__unpack(NULL, head->bufLen, head->buf);
    if (!path) {
        CrLogW("unpack failed\n");
        return;
    }

    std::string fileListPath = (char*)path->str.data;
    CrLogI("file path = %s", fileListPath.c_str());
    int num = DataManager::getInstance()->ReportGcodeFileNum(fileListPath);
    
    LocalGcodeInfo image = LOCAL_GCODE_INFO__INIT;
    image.has_optstart = 1;
    image.optstart = 1;
    image.has_optend = 1;
    image.optend = num;

    GET_MESSAGE_BUFF(buff);
    size_t len = local_gcode_info__pack(&image, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_GET_GCODE_FILE_IMAGE_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    
    send_string__free_unpacked(path, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WebGetGcodeFileImageAns(MsgHeadBuf_t *head)
{
    LocalGcodeInfo *image = local_gcode_info__unpack(NULL, head->bufLen, head->buf);
    if (!image) {
        CrLogW("unpack failed\n");
        return;
    }

    // 提取参数
    int getGcodeInfoResult = image->result;
    char filePath[256] = {0};
    memcpy(filePath, image->cachepath.data, image->cachepath.len);
    int fileStart = image->optstart;
    int fileEnd = image->optend;
    string ret = CommondProc::getInstance()->ReportGcodeFileInfo(filePath);
    if(ret.size()>0)
        WebSocket::getInstance()->sendToAllSocket(ret);
    local_gcode_info__free_unpacked(image, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void WebGetCurrentLocalAns(MsgHeadBuf_t *head)
{
    AxisPositionInfo *local = axis_position_info__unpack(NULL, head->bufLen, head->buf);
    if (!local) {
        CrLogW("unpack failed\n");
        return;
    }
    AttributeProc::getInstance()->setCurrentLocal(local);
    axis_position_info__free_unpacked(local, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetUpgradeInfoAns(MsgHeadBuf_t *head)
{
    CrLogI("User Get Upgrade Info Ans");
    UpgradeInfoList *infoList = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!infoList) {
        CrLogW("unpack failed\n");
        return;
    }
    DataManager::getInstance()->ReportOtaInfo(infoList);

    upgrade_info_list__free_unpacked(infoList, NULL);
}


/**
 * @description: 
 * @param  {*}
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
    AttributeProc::getInstance()->setSystemConfig(config);
    system_config_proto__free_unpacked(config, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void ManagerSyncPrintSavePara(MsgHeadBuf_t *head)
{
    PrintSavePara *savePara = print_save_para__unpack(NULL, head->bufLen, head->buf);
    if (!savePara) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Manager Sync Print Save Para");
    AttributeProc::getInstance()->setPrintSavePara(savePara);
    print_save_para__free_unpacked(savePara, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WebControlPrintAns(MsgHeadBuf_t *head)
{
    WebControlPrint *control = web_control_print__unpack(NULL, head->bufLen, head->buf);
    if (!control) {
        CrLogW("unpack failed\n");
        return;
    }

    // 响应请求打印本地文件
    if (control->has_result)
    {
        DataManager::getInstance()->ReportWebControlPrint(control->result);
    }
    web_control_print__free_unpacked(control, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} cur
 */
static int DisplayCurrentTemp(PrintState_t cur)
{
    char nozzleStr[256] = {0};
    for (int i = 0; i < NOZZLE_TEMP_SIZE; i++)
        snprintf(&nozzleStr[strlen(nozzleStr)], 256, "%d=%d, ", i, cur.nozzleCurTemp[i]);
    CrLogD("[Heartbeat] nuzzle: %s", nozzleStr);

    char hotbedStr[512] = {0};
    for (int i = 0; i < HOTBED_TEMP_SIZE; i++)
        snprintf(&hotbedStr[strlen(hotbedStr)], 256, "%d=%d, ", i, cur.bedCurTemp[i]);
    CrLogD("[Heartbeat] hotbed: %s\n", hotbedStr);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} cur
 */
static int DisplayCurrentPower(PrintState_t cur)
{
    char nozzleStr[256] = {0};
    for (int i = 0; i < NOZZLE_TEMP_SIZE; i++)
        snprintf(&nozzleStr[strlen(nozzleStr)], 256, "%d=%d, ", i, cur.nozzlePower[i]);
    CrLogD("[Heartbeat] nuzzle power: %s", nozzleStr);

    char hotbedStr[512] = {0};
    for (int i = 0; i < HOTBED_TEMP_SIZE; i++)
        snprintf(&hotbedStr[strlen(hotbedStr)], 256, "%d=%d, ", i, cur.bedPower[i]);
    CrLogD("[Heartbeat] hotbed power: %s", hotbedStr);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} state
 */
static std::string GetErrInfo(PrintState_t state)
{
    json_object *errInfo = json_object_new_object();
    json_object_object_add(errInfo, "errcode", json_object_new_int(state.faultCode.error));
    json_object_object_add(errInfo, "key", json_object_new_int(state.faultCode.code));
    std::string send = json_object_to_json_string(errInfo);
    json_object_put(errInfo);

    return send;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void SyncDeviceStateToWeb(MsgHeadBuf_t *head)
{
    SyncPrintState *state = sync_print_state__unpack(NULL, head->bufLen, head->buf);
    if (!state) {
        CrLogW("unpack failed\n");
        return;
    }
    AttributeProc::getInstance()->setDeviceState(state);
    sync_print_state__free_unpacked(state, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void SyncPrintWorkInfo(MsgHeadBuf_t *head)
{
    PrintWorkInfo *workInfo = print_work_info__unpack(NULL, head->bufLen, head->buf);
    if (!workInfo) {
        CrLogW("unpack failed\n");
        return;
    }
    // 打印任务ID
    CrLogI("print work start id = %d", workInfo->id);

    AttributeProc::getInstance()->setPrintWorkInfo(workInfo);
    print_work_info__free_unpacked(workInfo, NULL);
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
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetDelayImagePreAns(MsgHeadBuf_t *head)
{
    DelayImagePrefer *pre = delay_image_prefer__unpack(NULL, head->bufLen, head->buf);
    if (!pre) {
        CrLogW("unpack failed\n");
        return;
    }
    AttributeProc::getInstance()->setDelayImage(pre);
    delay_image_prefer__free_unpacked(pre, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetAutoPidPreAns(MsgHeadBuf_t *head)
{
    TempAutoPidPreferList *pid = temp_auto_pid_prefer_list__unpack(NULL, head->bufLen, head->buf);
    if (!pid) {
        CrLogW("unpack failed\n");
        return;
    }
    AttributeProc::getInstance()->setAutoPid(pid);
    temp_auto_pid_prefer_list__free_unpacked(pid, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ServerSyncAutoLevelResult(MsgHeadBuf_t *head)
{
    ReportAutoLevelRes *levelResult = report_auto_level_res__unpack(NULL, head->bufLen, head->buf);
    if (!levelResult) {
        CrLogW("unpack failed\n");
        return;
    }
    AttributeProc::getInstance()->setAutoLevel(levelResult);
    report_auto_level_res__free_unpacked(levelResult, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ServerSyncUpgradeStateToWeb(MsgHeadBuf_t *head)
{
    UpgradeInfoList *list = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!list) {
        CrLogW("unpack failed\n");
        return;
    }
    AttributeProc::getInstance()->setUpgradeStateToWeb(list);
    upgrade_info_list__free_unpacked(list, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetPowerLossPreAns(MsgHeadBuf_t *head)
{
    PowerLossPrefer *pre = power_loss_prefer__unpack(NULL, head->bufLen, head->buf);
    if (!pre) {
        CrLogW("unpack failed\n");
        return;
    }
    AttributeProc::getInstance()->setPowerLoss(pre);
    power_loss_prefer__free_unpacked(pre, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetAiControlPreAns(MsgHeadBuf_t *head)
{
    AiControlPrefer *pre = ai_control_prefer__unpack(NULL, head->bufLen, head->buf);
    if (!pre) {
        CrLogW("unpack failed\n");
        return;
    }
    AttributeProc::getInstance()->setAiControl(pre);
    ai_control_prefer__free_unpacked(pre, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ControlLocalVedioResult(MsgHeadBuf_t *head)
{
    GeneralRes *res = general_res__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }
    CrLogI("resonance result = %d", res->result);
    DataManager::getInstance()->ControlVideoFilesResult(res->result);
    general_res__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetPrintObjectResult(MsgHeadBuf_t *head)
{
    // 创建对象排除信息共享内存
    if (printObjectShm.result != GET_SHM_OK) {
        printObjectShm = CreateSemShm(PRINT_OBJECT_SEM_PATH, PRINT_OBJECT_SHM_FILE, 0, false);
    }

    char objectInfo[PRINT_OBJECT_SHM_SIZE] = {0};
    ReadDataFromShm(&printObjectShm, objectInfo, sizeof(objectInfo));
    DataManager::getInstance()->PrintObjectResult(objectInfo);
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
        CrLogD("package len = %ld, origin %d, cmd %d, message len %ld", headSize, head.origin, head.cmd, head.bufLen);

        switch (head.cmd)
        {
            case SERVER_CMD_WEB_TEST_REQ: ServerMessageTestReq(&head); break;
            //case SERVER_CMD_WEB_SYSTEM_RESET_REQ: ManagerSystemResetRes(&head); break;
            case SERVER_CMD_WEB_SYNC_UPGRADE_STATE: ServerSyncUpgradeStateToWeb(&head); break;
            case SERVER_CMD_WEB_SYNC_AUTO_LEVEL_RESULT: ServerSyncAutoLevelResult(&head); break;

            case SERVER_CMD_WEB_GET_SYSTEM_CONFIG_ANS: ManagerSyncSystemConfig(&head); break;
            case SERVER_CMD_WEB_GET_PRINT_SAVE_PARA_ANS: ManagerSyncPrintSavePara(&head); break;
            case SERVER_CMD_WEB_CONTROL_PRINT_ANS: WebControlPrintAns(&head); break;
            case SERVER_CMD_WEB_GET_GCODE_FILE_LIST_ANS: WebGetGcodeFileListAns(&head); break;
            case SERVER_CMD_WEB_GET_GCODE_FILE_IMAGE_ANS: WebGetGcodeFileImageAns(&head); break;
            case SERVER_CMD_WEB_GET_CURRENT_LOCAL_ANS: WebGetCurrentLocalAns(&head); break;

            case SERVER_CMD_WEB_GET_DEVICE_STATE_ANS: SyncDeviceStateToWeb(&head); break;
            case SERVER_CMD_WEB_SYNC_PRINT_WORK_INFO: SyncPrintWorkInfo(&head); break;
            case MANAGER_CMD_MESSAGE_TEST: ManagerMessageTest(&head); break;

            case SERVER_CMD_WEB_GET_DELAY_IMAGE_PRE_ANS: UserGetDelayImagePreAns(&head); break;
            case SERVER_CMD_WEB_GET_AUTO_PID_PRE_ANS: UserGetAutoPidPreAns(&head); break;
            case SERVER_CMD_WEB_CHECK_UPGRADE_ANS: UserGetUpgradeInfoAns(&head); break;
            case SERVER_CMD_WEB_GET_POWER_LOSS_PRE_ANS: UserGetPowerLossPreAns(&head); break;
            case SERVER_CMD_WEB_GET_AI_CONTROL_PRE_ANS: UserGetAiControlPreAns(&head); break;
            case SERVER_CMD_WEB_CONTROL_LOCAL_VIDEO_RESULT:ControlLocalVedioResult(&head); break;
            case SERVER_CMD_WEB_GET_PRINT_OBJECT_ANS:UserGetPrintObjectResult(&head); break;
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
static void WebInitiativeSyncManagerData(void)
{
    // 同步Linux系统配置
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_GET_SYSTEM_CONFIG_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 */
static void WebInitiativeSyncPrintSavePara(void)
{
    // 同步打印机保存参数
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_GET_PRINT_SAVE_PARA_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 */
static void WebInitiativeSyncDeviceState(void)
{
    // 同步打印机保存参数
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_GET_DEVICE_STATE_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
}
/**
 * @description: 
 * @return {*}

 */
static void WebInitiativeSyncUserPrefer(void)
{
    // 获取延时摄影偏好
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_GET_DELAY_IMAGE_PRE_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
    // 获取断电续打偏好
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_GET_POWER_LOSS_PRE_REQ, "", 0);
    SendProcessMsgBuff(&send1, size1);
    // 获取AI控制偏好
    CREATE_MESSAGE_PACKAGE(send2, size2, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_GET_AI_CONTROL_PRE_REQ, "", 0);
    SendProcessMsgBuff(&send2, size2);
}
/**
 * @description: 
 * @return {*}

 */
static void WebInitiativeSyncAutoPidPrefer(int id)
{
    // 同步打印机保存参数
    TempAutoPidPrefer *temp[1];
    temp[0] = (TempAutoPidPrefer *)malloc(sizeof(TempAutoPidPrefer));
    temp[1] = (TempAutoPidPrefer *)malloc(sizeof(TempAutoPidPrefer));
    temp_auto_pid_prefer__init(temp[0]);
    temp_auto_pid_prefer__init(temp[1]);
    temp[0]->id = 1;
    temp[0]->id = 2;
    TempAutoPidPreferList list = TEMP_AUTO_PID_PREFER_LIST__INIT;
    list.n_list = 0;
    list.list = temp;

    GET_MESSAGE_BUFF(buff);
    size_t len = temp_auto_pid_prefer_list__pack(&list, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_GET_AUTO_PID_PRE_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    free (temp[0]);
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
    managerMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_WEB_MANAGER);
    if (managerMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    serverMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_WEB_SERVER);
    if (serverMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    // 清空消息队列
    CleanMessageQueue();
    // 同步manager数据
    WebInitiativeSyncManagerData();
    WebInitiativeSyncPrintSavePara();
    WebInitiativeSyncDeviceState();
    WebInitiativeSyncUserPrefer();
    WebInitiativeSyncAutoPidPrefer(1);
    WebInitiativeSyncAutoPidPrefer(2);
    while (1)
    {
        MsgUpdata();
        usleep(1000 * 10);
    }
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *HttpdServerThread(void *arg)
{
    Httpd httpd;
    //httpd.SetConfile();
    httpd.Start();
    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *GetGcodeThread(void *arg)
{
    CrLogI("start get gcode file info");
    // 初始化 inotifytools
  if (!inotifytools_initialize()) {
        CrLogW("%s\n", strerror(inotifytools_error()));
  }

    // 等待获取SD卡信息路径
    do {
        if (access(GetUserLocalGcodeFileInfoPtah(), F_OK) == 0) break;
        usleep(10 * 1000);
    } while (1);

    // 监听SD卡信息
    if (!inotifytools_watch_recursively(GetUserLocalGcodeFileInfoPtah(), IN_MODIFY)) {
        CrLogW("inotifytools_watch_recursively failed\n");
    }

    // 监听历史记录信息
    if (!inotifytools_watch_recursively(GetuserPrintHistoryRecordPtah(), IN_MODIFY)) {
        CrLogW("inotifytools_watch_recursively failed\n");
    }

    // 监听延时视频信息
    if (!inotifytools_watch_file(GetUserDelayImageInfoPtah(), IN_MODIFY)) {
        CrLogW("inotifytools_watch_file failed\n");
    }
    // 添加将文件信息自动同步到交互端
    CrLogI("test sync local file info");

    CrLogI("start listening path");
    while (1)
    {
        // 获取监听事件
        struct inotify_event *event = inotifytools_next_event(-1);
        if (!event) {
            sleep(2);
            CrLogE("File monitoring fails\n");
            continue;
        }

        // 获取变化文件路径
        char changePath[256] = {0};
        snprintf(changePath, sizeof(changePath), "%s%s", inotifytools_filename_from_wd(event->wd), event->name);
        CrLogI("change path = %s", changePath);
        string ret = "";
        // 解析监听事件
        switch (event->mask)
        {
            // 文件变化，同步到交互端
            case IN_MODIFY:
            {
                if (strstr(changePath, GetUserLocalGcodeInfoDirPtah())) {
                    // 同步本地文件
                    CrLogI("test sync local file info");
                    ret = CommondProc::getInstance()->ReportGcodeFileInfo(GetUserLocalGcodeFileInfoPtah());
                }else if(strstr(changePath, GetuserPrintHistoryRecordPtah())){
                    ret = CommondProc::getInstance()->ReportHistoryInfo();
                }else if(strstr(changePath, GetUserDelayImageInfoPtah())){
                    ret = CommondProc::getInstance()->ReportElapseVideoInfo();
                }
                break;
            }
            default: CrLogI("event->mask = %d\n", event->mask); break;
        }
        if(ret.size()>0)
            WebSocket::getInstance()->sendToAllSocket(ret);
    }

    inotifytools_cleanup();
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
    CrLogI("Web server init");
    // 新开线程接收数据
    int res = pthread_create(&messageHandle, NULL, &MessageThread, NULL);
    if (res){
        CrLogE("create pthread error!\n");
        return NULL;
    }

    pthread_t httpHandle;
    res = pthread_create(&httpHandle, NULL, &HttpdServerThread, arg);
    if (res){
        CrLogE("create pthread error!\n");
        return NULL;
    }

    // 创建获取gcode线程
    pthread_t gcodeHandle;
    res = pthread_create(&gcodeHandle, NULL, &GetGcodeThread, arg);
    if (res) {
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
    ShmExceptionHandleSemPost(&printObjectShm);
    return 0;
}
