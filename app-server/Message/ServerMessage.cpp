/*
 * @Description : 通信管理
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:09
 * @LastEditTime: 2023-10-16 14:29:44
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
#include <fstream>
#include <curl/curl.h>

#include "Base/AppMsgBase.h"
#include "CxyManager/CxyManager.h"
#include "CxyManager/CxyHttpServer.h"
#include "Upgrade/UpgradeManager.hh"
#include "ServerMessage.h"

#define GET_SYS_VERSION_COUNT_MAX       10

static pthread_t messageHandle;
static int managerMsgId = -1;
static int serverMsgId = -1;
static SystemConfig_t systemComfig = {0}; // 系统配置文件
static PrintSavePara_t printSavePara; // 打印机保存参数
static PrintState_t printRunState = {0}; // 打印机运行状态
static CxyManager *CxyManagerClient;
static UpgradeManager startUpgradeClient; // 开始升级

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
    str.dialogue = (char*)"I am app server!";

    GET_MESSAGE_BUFF(buff);
    size_t len = server_test__pack(&str, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_TEST_ANS, buff, len);

    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerCheckUpgradeRes(MsgHeadBuf_t *head)
{
    UpgradeInfoList *infoList = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!infoList) {
        CrLogW("unpack failed\n");
        return;
    }

    // 获取设备系统信息
    DevSysInfo_t sysInfo;
    sysInfo.model = CxyManagerClient->GetAppPrintState()->model_str;
    sysInfo.sysVersion = CxyManagerClient->GetAppPrintState()->sys_version;
    sysInfo.hwVersion = CxyManagerClient->GetAppPrintState()->hw_version;
    sysInfo.mcuSysVersion = CxyManagerClient->GetAppPrintState()->fw_version;
    sysInfo.mcuHwVersion = CxyManagerClient->GetAppPrintState()->hw1_version;
    sysInfo.deploySetting = CxyManagerClient->GetAppPrintState()->deploy_setting;

    // 用户检查升级
    UpgradeManager UpgradeRequest;
    NewImageInfo_t info = {0};
    UpgradeInfo linuxVersion = UPGRADE_INFO__INIT;
    UpgradeInfo mcuVersion = UPGRADE_INFO__INIT;
    UpgradeInfoList getList = UPGRADE_INFO_LIST__INIT;
    UpgradeRequest.UpdataVerionOptions(sysInfo);
    
    // 检查Linux OTA镜像
    if (infoList->linuxota) {
        if (UpgradeRequest.CheckForUpgrade(&info, UPGRADE_TARGET_LINUX))
        {
            linuxVersion.has_version = 1;
            linuxVersion.version.data = (uint8_t*)info.version.c_str();
            linuxVersion.version.len = info.version.length();
            linuxVersion.has_name = 1;
            linuxVersion.name.data = (uint8_t*)info.name.c_str();
            linuxVersion.name.len = info.name.length();
            linuxVersion.has_size = 1;
            linuxVersion.size = info.size;
            linuxVersion.has_url = 1;
            linuxVersion.url.data = (uint8_t*)info.url.c_str();
            linuxVersion.url.len = info.url.length();
            linuxVersion.has_force = 1;
            linuxVersion.force = info.isForce;
            linuxVersion.has_manual = 1;
            linuxVersion.manual.data = (uint8_t*)info.manual.c_str();
            linuxVersion.manual.len = info.manual.length();
        }
        getList.linuxota = &linuxVersion;
    }
    // 检查mcu OTA镜像
    if (infoList->mcu1ota) {
        if (UpgradeRequest.CheckForUpgrade(&info, UPGRADE_TARGET_MCU1))
        {
            mcuVersion.has_version = 1;
            mcuVersion.version.data = (uint8_t*)info.version.c_str();
            mcuVersion.version.len = info.version.length();
            mcuVersion.has_name = 1;
            mcuVersion.name.data = (uint8_t*)info.name.c_str();
            mcuVersion.name.len = info.name.length();
            mcuVersion.has_size = 1;
            mcuVersion.size = info.size;
            mcuVersion.has_url = 1;
            mcuVersion.url.data = (uint8_t*)info.url.c_str();
            mcuVersion.url.len = info.url.length();
            mcuVersion.has_force = 1;
            mcuVersion.force = info.isForce;
            mcuVersion.has_manual = 1;
            mcuVersion.manual.data = (uint8_t*)info.manual.c_str();
            mcuVersion.manual.len = info.manual.length();
        }
        getList.mcu1ota = &mcuVersion;
    }

    GET_MESSAGE_BUFF(buf);
    size_t len = upgrade_info_list__pack(&getList, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CHECK_UPGRADE_ANS, buf, len);
    SendProcessMsgBuff(&send, size);

    upgrade_info_list__free_unpacked(infoList, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {UpgradeState_t} state
 * @param {int} progress
 */
static int UpgradeStateCallback(UpgradeState_t state, int progress, UpgradeTarget_t target)
{
    CxyManagerClient->UpgradeStateResponse(state, progress, target);
	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerStartUpgradeRes(MsgHeadBuf_t *head)
{
    // 准备升级
    UpgradeInfoList *infoList = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!infoList) {
        CrLogW("unpack failed\n");
        return;
    }

    // 更新设备系统版本信息
    DevSysInfo_t sysInfo;
    sysInfo.model = CxyManagerClient->GetAppPrintState()->model_str;
    sysInfo.sysVersion = CxyManagerClient->GetAppPrintState()->sys_version;
    sysInfo.hwVersion = CxyManagerClient->GetAppPrintState()->hw_version;
    sysInfo.mcuSysVersion = CxyManagerClient->GetAppPrintState()->fw_version;
    sysInfo.mcuHwVersion = CxyManagerClient->GetAppPrintState()->hw1_version;
    sysInfo.updataInfoCb = UpgradeStateCallback;
    startUpgradeClient.UpdataVerionOptions(sysInfo);

    // 开始linux OTA升级
    if (infoList->linuxota)
    {
        CrLogI("start dowmload linux firmware\n");
        UpgradeInfo *info = infoList->linuxota;
        if (info->has_url) {
            char downlodeUrl[info->url.len + 1];
            memset(downlodeUrl, 0, info->url.len + 1);
            memcpy(downlodeUrl, info->url.data, info->url.len);

            NewImageInfo_t info;
            info.url = downlodeUrl;
            startUpgradeClient.UserStartUpgrade(info, UPGRADE_TARGET_LINUX);
        }
        else CrLogW("no dowmload firmware url\n");
    }
    // 开始mcu1 OTA升级
    if (infoList->mcu1ota)
    {
        CrLogI("start dowmload mcu firmware\n");
        UpgradeInfo *info = infoList->mcu1ota;
        if (info->has_url) {
            char downlodeUrl[info->url.len + 1];
            memset(downlodeUrl, 0, info->url.len + 1);
            memcpy(downlodeUrl, info->url.data, info->url.len);

            NewImageInfo_t info;
            info.url = downlodeUrl;
            startUpgradeClient.UserStartUpgrade(info, UPGRADE_TARGET_MCU1);
        }
        else CrLogW("no dowmload firmware url\n");
    }

    // 响应
    GeneralRes res = GENERAL_RES__INIT;
    res.result = 1;
    GET_MESSAGE_BUFF(buf);
    size_t len = general_res__pack(&res, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_START_UPGRADE_ANS, buf, len);
    SendProcessMsgBuff(&send, size);

    upgrade_info_list__free_unpacked(infoList, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerCancelUpgradeRes(MsgHeadBuf_t *head)
{
    startUpgradeClient.UserCancelUpgrade();

    // 响应
    GeneralRes res = GENERAL_RES__INIT;
    res.result = 1;
    GET_MESSAGE_BUFF(buf);
    size_t len = general_res__pack(&res, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CANCEL_UPGRADE_ANS, buf, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerUploadLoaclLog(MsgHeadBuf_t *head)
{
    SendString *resStr = send_string__unpack(NULL, head->bufLen, head->buf);
    if (!resStr) {
        CrLogW("unpack failed\n");
        return;
    }

    json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
    if(iotConfig){
         json_object * otherInfoObj = json_object_object_get(iotConfig, "cxy_other_info");
         if(otherInfoObj){
            json_object *jwtObj = json_object_object_get(otherInfoObj, "jwt_token");
            if(jwtObj){
                bzero(CxyManagerClient->GetAppPrintState()->appJwtToken, sizeof(CxyManagerClient->GetAppPrintState()->appJwtToken));
                memcpy(CxyManagerClient->GetAppPrintState()->appJwtToken, json_object_get_string(jwtObj), strlen(json_object_get_string(jwtObj)));    
            }
         }
        json_object_put(iotConfig);
    }

    if(resStr->str.len&&!strcmp((char*)resStr->str.data,"stop"))
        CxyManagerClient->AppStopUploadLog();
    else{
        int response = CxyManagerClient->AppUploadLocalLog();
        CrLogI("response = %d", response);        
    }

    send_string__free_unpacked(resStr, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerUploadLoaclVideo(MsgHeadBuf_t *head)
{
    SendString *resStr = send_string__unpack(NULL, head->bufLen, head->buf);
    if (!resStr) {
        CrLogW("unpack failed\n");
        return;
    }

    json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
    if(iotConfig){
         json_object * otherInfoObj = json_object_object_get(iotConfig, "cxy_other_info");
         if(otherInfoObj){
            json_object *jwtObj = json_object_object_get(otherInfoObj, "jwt_token");
            if(jwtObj){
                bzero(CxyManagerClient->GetAppPrintState()->appJwtToken, sizeof(CxyManagerClient->GetAppPrintState()->appJwtToken));
                memcpy(CxyManagerClient->GetAppPrintState()->appJwtToken, json_object_get_string(jwtObj), strlen(json_object_get_string(jwtObj)));    
            }
         }
    }
    json_object_put(iotConfig);

    char filePath[256] = {0};
    memcpy(filePath, resStr->str.data, resStr->str.len);
    CrLogI("voide file path = %s", filePath);
    int response = CxyManagerClient->AppUploadLocalDelayImage(filePath);
    CrLogI("response = %d", response);

    send_string__free_unpacked(resStr, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerUpdateUserInfo(MsgHeadBuf_t *head)
{
    CxyManagerClient->UserUpdateUserInfo();
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerSystemResetRes(MsgHeadBuf_t *head)
{
    CrLogI("ManagerSystemResetRes");
    int rc = 0;
    DeviceTbInfo_t tbInfo;
    CxyHttpServer m_cxyHttpServer;

    // 删除设备保存tb信息
    if (remove(GetUserIotTbInfoFilePtah()) != 0)
        CrLogW("remove iot tb info fail\n,");
    system("sync");
    
    // 获取创想云服务器配置
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(systemComfig.deploy_setting);
    // 获取创想云服务器地址
    std::string remoteUrl = server.url;
    // 获取SN、MAC地址
    RegisterInfo_t devInfo;
    if (m_cxyHttpServer.GetRegisterInfoFromFile(&devInfo) != 0) {
        CrLogE("get device sn or mac fail\n\n\n");
        goto SYSTEM_RESET_END;
    }

    CrLogD("url = %s", remoteUrl.c_str());
    if (remoteUrl.length() < 2) {
        CrLogE("get cxy remote url fail\n\n\n");
        goto SYSTEM_RESET_END;
    }
    
    // 初始化 HTTP pai接口
    if (m_cxyHttpServer.CxyHttpApiInit(remoteUrl, "register_dev") != 0) {
        CrLogE("cxy http api init fail\n\n\n");
        goto SYSTEM_RESET_END;
    }

    // 调用设备注册接口，解绑设备
    if (m_cxyHttpServer.GetConnectTbInfo(devInfo, &tbInfo) == -1) {
        CrLogW("No TB information is obtained\n");
        goto SYSTEM_RESET_END;
    }

    // http请求成功，判断是否获取tb信息
    if (tbInfo.token.length() < 2 || tbInfo.devName.length() < 2) {
        CrLogE("%s\n", tbInfo.httpRes.c_str());
        goto SYSTEM_RESET_END;
    }
    rc = 1;

SYSTEM_RESET_END:
    // 响应
    GeneralRes res = GENERAL_RES__INIT;
    res.result = rc;
    GET_MESSAGE_BUFF(buf);
    size_t len = general_res__pack(&res, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_SYSTEM_RESET_ANS, buf, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppGetGcodeFileListAns(MsgHeadBuf_t *head)
{
    GetGcodeFIleList *getList = get_gcode_file_list__unpack(NULL, head->bufLen, head->buf);
    if (!getList) {
        CrLogW("unpack failed\n");
        return;
    }
    std::string fileListPath = (char*)getList->path.data;
    uint type = 0;
    if(getList->has_type){
        type = getList->type;
    }
    CrLogI("file path = %s", fileListPath.c_str());
    int index = 0;
    
    get_gcode_file_list__free_unpacked(getList, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void AppGetCurrentLocalAns(MsgHeadBuf_t *head)
{
    AxisPositionInfo *local = axis_position_info__unpack(NULL, head->bufLen, head->buf);
    if (!local) {
        CrLogW("unpack failed\n");
        return;
    }
    
    char infoBuff[100] = {0};
    snprintf(infoBuff, 100, "X%.2f Y%.2f Z%.2f", local->x/100.00, local->y/100.00, local->z/100.00);
    bzero(CxyManagerClient->GetAppPrintState()->curPosition, sizeof(CxyManagerClient->GetAppPrintState()->curPosition));
    memcpy(CxyManagerClient->GetAppPrintState()->curPosition, infoBuff, strlen(infoBuff));    
    std::string localInfo = std::string(infoBuff);
    CrLogI("cur local = %s", localInfo.c_str());
    axis_position_info__free_unpacked(local, NULL);
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
    memset(&systemComfig, 0, sizeof(SystemConfig_t));
    memcpy(systemComfig.sys_version, config->sys_version.data, config->sys_version.len);
    memcpy(systemComfig.fw_version, config->fw_version.data, config->fw_version.len);
    memcpy(systemComfig.hw_version, config->hw_version.data, config->hw_version.len);
    memcpy(systemComfig.hw1_version, config->hw1_version.data, config->hw1_version.len);
    memcpy(systemComfig.website, config->website.data, config->website.len);
    systemComfig.model = config->model;
    memcpy(systemComfig.model_str, config->model_str.data, config->model_str.len);
    systemComfig.bed_length = config->bed_length;
    systemComfig.bed_width = config->bed_width;
    systemComfig.bed_hight = config->bed_hight;
    memcpy(systemComfig.device_sn, config->device_sn.data, config->device_sn.len);
    memcpy(systemComfig.device_mac, config->device_mac.data, config->device_mac.len);
    systemComfig.swap_way = config->swap_way;
    systemComfig.deploy_setting = config->deploy_setting;
    systemComfig.customer = config->customer;
    systemComfig.language = config->language;
    systemComfig.sound_size = config->sound_size;
    systemComfig.sound_sw = config->sound_sw;
    systemComfig.sounde_ffect = config->sounde_ffect;
    systemComfig.light_sw = config->light_sw;
    systemComfig.light_value = config->light_value;
    systemComfig.wifi_sw = config->wifi_sw;
    systemComfig.theme_mode = config->theme_mode;
    systemComfig.self_test_sw = config->self_test_sw;
    systemComfig.screensaver = config->screensaver;
    systemComfig.screen_value = config->screen_value;
    systemComfig.auto_power_off = config->auto_power_off;
    systemComfig.ui_direction = config->ui_direction;
    systemComfig.full_screen = config->full_screen;
    systemComfig.z_direction = config->z_direction;
    systemComfig.total_time = config->total_time;
    systemComfig.enableselftest = config->enableselftest;
    memcpy(systemComfig.time_zone, config->time_zone.data, config->time_zone.len);
    systemComfig.upgrade_remind = config->upgrade_remind;
    systemComfig.server_local = config->server_local;
    systemComfig.agree_privacy = config->agree_privacy;
    systemComfig.creality_num = config->creality_num;
    memcpy(systemComfig.host_name, config->host_name.data, config->host_name.len);
    system_config_proto__free_unpacked(config, NULL);
    
    CrLogI("version; sys = %s, hw = %s, model = %d, str = %s, hw1 = %s, deploy = %d",
            systemComfig.sys_version, systemComfig.hw_version, systemComfig.model,
            systemComfig.model_str, systemComfig.hw1_version, systemComfig.deploy_setting);

    // 按进程实际需求处理数据
    memset(CxyManagerClient->GetAppPrintState()->sys_version, 0, sizeof(CxyManagerClient->GetAppPrintState()->sys_version));
    memcpy(CxyManagerClient->GetAppPrintState()->sys_version, systemComfig.sys_version, strlen(systemComfig.sys_version));
    memset(CxyManagerClient->GetAppPrintState()->fw_version, 0, sizeof(CxyManagerClient->GetAppPrintState()->fw_version));
    memcpy(CxyManagerClient->GetAppPrintState()->fw_version, systemComfig.fw_version, strlen(systemComfig.fw_version));
    memset(CxyManagerClient->GetAppPrintState()->hw_version, 0, sizeof(CxyManagerClient->GetAppPrintState()->hw_version));
    memcpy(CxyManagerClient->GetAppPrintState()->hw_version, systemComfig.hw_version, strlen(systemComfig.hw_version));
    memset(CxyManagerClient->GetAppPrintState()->hw1_version, 0, sizeof(CxyManagerClient->GetAppPrintState()->hw1_version));
    memcpy(CxyManagerClient->GetAppPrintState()->hw1_version, systemComfig.hw1_version, strlen(systemComfig.hw1_version));
    memset(CxyManagerClient->GetAppPrintState()->model_str, 0, sizeof(CxyManagerClient->GetAppPrintState()->model_str));
    memcpy(CxyManagerClient->GetAppPrintState()->model_str, systemComfig.model_str, strlen(systemComfig.model_str));

    CxyManagerClient->GetAppPrintState()->model = systemComfig.model;
    CxyManagerClient->GetAppPrintState()->deploy_setting = systemComfig.deploy_setting;
    CxyManagerClient->GetAppPrintState()->lightState = systemComfig.light_sw;
    CxyManagerClient->GetAppPrintState()->enableSelfTest = systemComfig.enableselftest;
    CxyManagerClient->GetAppPrintState()->agreePrivacy = systemComfig.agree_privacy;
    CxyManagerClient->GetAppPrintState()->allPrintTime = systemComfig.total_time;
    // 拼接组件版本
    char *modelVersion = CxyManagerClient->GetAppPrintState()->modelVersion;
    memset(modelVersion, 0, sizeof(CxyManagerClient->GetAppPrintState()->modelVersion));
    snprintf(modelVersion, sizeof(CxyManagerClient->GetAppPrintState()->modelVersion)/sizeof(CxyManagerClient->GetAppPrintState()->modelVersion[0]),
            "printer hw ver:%s;printer sw ver:%s;DWIN hw ver:%s;DWIN sw ver:%s;",
            systemComfig.hw_version, systemComfig.sys_version, systemComfig.hw1_version, systemComfig.fw_version);
    // 更新遥测、属性
    CxyManagerClient->DelectAppPrintState(false);
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
    memset(&printSavePara, 0, sizeof(PrintSavePara_t));
    printSavePara.powerLoss = savePara->powerloss;
    printSavePara.materialDetect = savePara->materialdetect;

    printSavePara.hotendPid.p = savePara->hotendpid->p;
    printSavePara.hotendPid.i = savePara->hotendpid->i;
    printSavePara.hotendPid.d = savePara->hotendpid->d;

    printSavePara.bedPid.p = savePara->bedpid->p;
    printSavePara.bedPid.i = savePara->bedpid->i;
    printSavePara.bedPid.d = savePara->bedpid->d;

    printSavePara.nozzleHwMaxTemp = savePara->nozzlehwmaxtemp;
    printSavePara.bedHwMaxTemp = savePara->bedhwmaxtemp;

    printSavePara.levelValue.size = savePara->n_levelvalue;
    for (int i = 0; i < printSavePara.levelValue.size; i++)
        printSavePara.levelValue.value[i] = savePara->levelvalue[i];

    printSavePara.gcodeMacro.size = savePara->n_gcodemacro;
    for (int i = 0; i < printSavePara.gcodeMacro.size; i++)
        memcpy(printSavePara.gcodeMacro.value[i], savePara->gcodemacro[i].data, savePara->gcodemacro[i].len);

    printSavePara.homeOffset.x = savePara->homeoffset->x;
    printSavePara.homeOffset.y = savePara->homeoffset->y;
    printSavePara.homeOffset.z = savePara->homeoffset->z;
    printSavePara.homeOffset.e = savePara->homeoffset->e;

    printSavePara.axisRecoup.x = savePara->axisrecoup->x;
    printSavePara.axisRecoup.y = savePara->axisrecoup->y;
    printSavePara.axisRecoup.z = savePara->axisrecoup->z;
    printSavePara.axisRecoup.e = savePara->axisrecoup->e;

    printSavePara.stepValue.x = savePara->stepvalue->x;
    printSavePara.stepValue.y = savePara->stepvalue->y;
    printSavePara.stepValue.z = savePara->stepvalue->z;
    printSavePara.stepValue.e = savePara->stepvalue->e;

    printSavePara.Acceleration.x = savePara->acceleration->x;
    printSavePara.Acceleration.y = savePara->acceleration->y;
    printSavePara.Acceleration.z = savePara->acceleration->z;
    printSavePara.Acceleration.e = savePara->acceleration->e;

    printSavePara.Speed.x = savePara->speed->x;
    printSavePara.Speed.y = savePara->speed->y;
    printSavePara.Speed.z = savePara->speed->z;
    printSavePara.Speed.e = savePara->speed->e;

    printSavePara.Jerk.x = savePara->jerk->x;
    printSavePara.Jerk.y = savePara->jerk->y;
    printSavePara.Jerk.z = savePara->jerk->z;
    printSavePara.Jerk.e = savePara->jerk->e;

    printSavePara.k_Speed = savePara->k_speed;
    printSavePara.k_Acceleration = savePara->k_acceleration;
    printSavePara.k_Corner = savePara->k_corner;
    printSavePara.k_Jerk = savePara->k_jerk;
    printSavePara.pressureAdvance = savePara->pressureadvance;
    printSavePara.SmoothTime = savePara->smoothtime;
    printSavePara.fanFeedback = savePara->fanfeedback;
    
    printSavePara.levelPoints.x = savePara->levelpoint->x;
    printSavePara.levelPoints.y = savePara->levelpoint->y;

    printSavePara.devMaxSize.x = savePara->devmaxsize->x;
    printSavePara.devMaxSize.y = savePara->devmaxsize->y;
    printSavePara.devMaxSize.z = savePara->devmaxsize->z;

    printSavePara.devMinSize.x = savePara->devminsize->x;
    printSavePara.devMinSize.y = savePara->devminsize->y;
    printSavePara.devMinSize.z = savePara->devminsize->z;
    print_save_para__free_unpacked(savePara, NULL);

    CrLogI("k_Speed = %d, k_Acceleration = %d, k_Corner = %d, k_Jerk = %d, pressureAdvance = %d, SmoothTime = %d",
        printSavePara.k_Speed, printSavePara.k_Acceleration, printSavePara.k_Corner,
        printSavePara.k_Jerk, printSavePara.pressureAdvance, printSavePara.SmoothTime);
    CrLogI("levelPoints; x = %d, y = %d", printSavePara.levelPoints.x, printSavePara.levelPoints.y);

    // 按进程实际需求处理数据
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppControlPrintAns(MsgHeadBuf_t *head)
{
    AppControlPrint *control = app_control_print__unpack(NULL, head->bufLen, head->buf);
    if (!control) {
        CrLogW("unpack failed\n");
        return;
    }

    // 响应请求打印本地文件
    if (control->has_result)
    {
        CrLogI("report app control print result = %d", control->result);
    }
    app_control_print__free_unpacked(control, NULL);
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
    CrLogI("[Heartbeat] nuzzle: %s", nozzleStr);

    char hotbedStr[512] = {0};
    for (int i = 0; i < HOTBED_TEMP_SIZE; i++)
        snprintf(&hotbedStr[strlen(hotbedStr)], 256, "%d=%d, ", i, cur.bedCurTemp[i]);
    CrLogI("[Heartbeat] hotbed: %s\n", hotbedStr);

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
    CrLogI("[Heartbeat] nuzzle power: %s", nozzleStr);

    char hotbedStr[512] = {0};
    for (int i = 0; i < HOTBED_TEMP_SIZE; i++)
        snprintf(&hotbedStr[strlen(hotbedStr)], 256, "%d=%d, ", i, cur.bedPower[i]);
    CrLogI("[Heartbeat] hotbed power: %s", hotbedStr);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} state
 */
static void GetErrInfo(PrintState_t state)
{
    if((state.faultCode.error == 8 || state.faultCode.error == 206) && CxyManagerClient->GetAppPrintState()->aiNoticeFlag == 0){
        json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
        if(iotConfig){
            json_object * otherInfoObj = json_object_object_get(iotConfig, "cxy_other_info");
            if(otherInfoObj){
                json_object *jwtObj = json_object_object_get(otherInfoObj, "jwt_token");
                if(jwtObj){
                    bzero(CxyManagerClient->GetAppPrintState()->appJwtToken, sizeof(CxyManagerClient->GetAppPrintState()->appJwtToken));
                    memcpy(CxyManagerClient->GetAppPrintState()->appJwtToken, json_object_get_string(jwtObj), strlen(json_object_get_string(jwtObj)));    
                }
            }
            json_object_put(iotConfig);
        }
        if(CxyManagerClient->GetAppPrintState()->appJwtToken && CxyManagerClient->GetAppPrintState()->printId){
            int response = CxyManagerClient->RequestReportAiNotice(CxyManagerClient->GetAppPrintState()->appJwtToken, 
            CxyManagerClient->GetAppPrintState()->printId);
        }
        CxyManagerClient->GetAppPrintState()->aiNoticeFlag = 1;
        
    }else if(state.faultCode.error == 0){
        CxyManagerClient->GetAppPrintState()->aiNoticeFlag = 0;
    }
}

/**
 * @description: 
 * @return {*}
 */
static void UpgradeMqttStateByNetwork(void)
{
    static int lastWifiState = WIFI_STATE_DISCONNECTED;
    static int lastEthernetExists = 0;

    // wifi状态、有线网状态改变
    if (printRunState.wifiState != lastWifiState || printRunState.ethernetExists != lastEthernetExists)
    {
        if (printRunState.wifiState != WIFI_STATE_NETWORK &&
            printRunState.ethernetExists != 1 &&
            CxyManagerClient->GetMqttConState() == MQTT_THRUN_OK)
        {
            CxyManagerClient->SyncMqttConnectState(MQTT_THRUN_EXIT);
        }
        else if ((printRunState.wifiState == WIFI_STATE_NETWORK ||
            printRunState.ethernetExists == 1) &&
            CxyManagerClient->GetMqttConState() == MQTT_THRUN_OK)
        {
            CxyManagerClient->SyncMqttConnectState(MQTT_THRUN_OK);
        }
    }

    // 记录前一次状态
    lastWifiState = printRunState.wifiState;
    lastEthernetExists = printRunState.ethernetExists;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void SyncDeviceStateToApp(MsgHeadBuf_t *head)
{
    SyncPrintState *state = sync_print_state__unpack(NULL, head->bufLen, head->buf);
    if (!state) {
        CrLogW("unpack failed\n");
        return;
    }

    memset(&printRunState, 0, sizeof(PrintState_t));
    printRunState.serialPort = state->serialport;
    printRunState.sdCardExists = state->sdcardexists;
    for (int i = 0; i < UDISK_SIZE; i++)
        printRunState.udiskMount[i] = state->udiskmount[i];
    printRunState.ethernetExists = state->ethernetexists;
    for (int i = 0; i < CAMERA_SIZE; i++)
        printRunState.cameraOnline[i] = state->cameraonline[i];
    printRunState.laserExists = state->laserexists;
    printRunState.deviceState = state->devicestate;
    printRunState.workMode = state->workmode;
    printRunState.workState = state->workstate;
    for (int i = 0; i < MULTI_FAN_SIZE; i++)
        printRunState.fanState[i] = state->fanstate[i];
    for (int i = 0; i < MULTI_FAN_SIZE; i++)
        printRunState.fanSpeed[i] = state->fanspeed[i];
    for (int i = 0; i < MULTI_FAN_SIZE; i++)
        printRunState.fanPercentage[i] = state->fanpercentage[i];
    printRunState.motorState = state->motorstate;
    printRunState.lightState = state->lightstate;
    printRunState.wifiState = state->wifistate;
    printRunState.pauseStatus = state->pausestatus;
    for (int i = 0; i < MATERIAL_DETECTOR_SIZE; i++)
        printRunState.materialStatus[i] = state->materialstatus[i];
    printRunState.printSpeed = state->printspeed;
    printRunState.printFlow = state->printflow;
    printRunState.realTimeSpeed = state->realtimespeed;
    printRunState.realTimeFlow = state->realtimeflow;
    printRunState.printLayer = state->curprintlayer;
    printRunState.printLayers = state->printtotallayer;
    printRunState.printProgress = state->printprogress;
    for (int i = 0; i < NOZZLE_TEMP_SIZE; i++)
        printRunState.nozzleCurTemp[i] = state->curhotendtemp[i];
    for (int i = 0; i < HOTBED_TEMP_SIZE; i++)
        printRunState.bedCurTemp[i] = state->curbedtemp[i];
    for (int i = 0; i < NOZZLE_TEMP_SIZE; i++)
        printRunState.nozzleMaxTemp[i] = state->targethotendtemp[i];
    for (int i = 0; i < HOTBED_TEMP_SIZE; i++)
        printRunState.bedMaxTemp[i] = state->targetbedtemp[i];
    for (int i = 0; i < NOZZLE_TEMP_SIZE; i++)
        printRunState.nozzlePower[i] = state->curhotendpower[i];
    for (int i = 0; i < HOTBED_TEMP_SIZE; i++)
        printRunState.bedPower[i] = state->curbedpower[i];
    for (int i = 0; i < OTHER_TEMP_SIZE; i++)
        printRunState.otherCurTemp[i] = state->othercurtemp[i];
    printRunState.nozzleTempWait = state->nozzletempwait;
    printRunState.bedTempWait = state->bedtempwait;
    
    printRunState.printUsageTime = state->printusagetime;
    printRunState.printRemainTime = state->printremaintime;
    printRunState.filamentUsed = state->filamentused;
    printRunState.autoLevelProgress = state->autolevelprogress;
    printRunState.autoPidProgress = state->autopidprogress;
    printRunState.crTouchState = state->crtouchstate;
    printRunState.faultCode.code = state->faultcode->code;
    printRunState.faultCode.error = state->faultcode->error;
    memcpy(printRunState.faultCode.msg, state->faultcode->msg.data, state->faultcode->msg.len);
    memcpy(printRunState.faultCode.value, state->faultcode->values.data, state->faultcode->values.len);
    printRunState.existOffContinue = state->existoffcontinue; 
    printRunState.livePosition.x = state->liveposition->x;
    printRunState.livePosition.y = state->liveposition->y;
    printRunState.livePosition.z = state->liveposition->z;
    printRunState.livePosition.e = state->liveposition->e;
    printRunState.gcodePosition.x = state->gcodeposition->x;
    printRunState.gcodePosition.y = state->gcodeposition->y;
    printRunState.gcodePosition.z = state->gcodeposition->z;
    printRunState.gcodePosition.e = state->gcodeposition->e;
    printRunState.homedAxes.x = state->homedaxes->x;
    printRunState.homedAxes.y = state->homedaxes->y;
    printRunState.homedAxes.z = state->homedaxes->z;
    printRunState.homedAxes.e = state->homedaxes->e;
    printRunState.klipperStata = state->klipperstata;
    printRunState.klipperPrint = state->klipperprint;
    memcpy(printRunState.sdPath, state->sdpath.data, state->sdpath.len);
    memcpy(printRunState.uDiskPath, state->udiskpath.data, state->udiskpath.len);
    printRunState.qmodeFlag = state->qmodeflag;
    printRunState.withSelfTest = state->withselftest;
    printRunState.loadMaterial = state->loadmaterial;
    printRunState.quitMaterial = state->quitmaterial;
    printRunState.cxyMqttState = state->cxymqttstate;
    printRunState.logProgress = state->logprogress;
    sync_print_state__free_unpacked(state, NULL);
    
    CrLogI("[Heartbeat] port = %d, state = %d, progress = %d, layer = %d, code = %d, usage = %d, remain = %d, used = %d",
            printRunState.serialPort, printRunState.workState, printRunState.printProgress, printRunState.printLayer,
            printRunState.faultCode.code, printRunState.printUsageTime, printRunState.printRemainTime, printRunState.filamentUsed);
    CrLogI("[Heartbeat] udisk0 = %d, ethernet = %d, camera0 = %d",
            printRunState.udiskMount[UDISK_0], printRunState.ethernetExists, printRunState.cameraOnline[CAMERA_MODEL]);
    CrLogI("[Heartbeat] modelFan = %d, caseFan = %d, auxiliaryFan = %d",
            printRunState.fanState[MULTI_FAN_MODEL], printRunState.fanState[MULTI_FAN_CASE], printRunState.fanState[MULTI_FAN_AUXILIARY]);
    CrLogI("[Heartbeat] modelFanPct = %d, caseFanPct = %d, auxiliaryFanPct = %d",
            printRunState.fanPercentage[MULTI_FAN_MODEL], printRunState.fanPercentage[MULTI_FAN_CASE], printRunState.fanPercentage[MULTI_FAN_AUXILIARY]);
    CrLogI("[Heartbeat] real time; speed = %d, flow = %d",
            printRunState.realTimeSpeed, printRunState.realTimeFlow);
    CrLogI("[Heartbeat] chamber = %d",
            printRunState.otherCurTemp[OTHER_TEMP_CAVITY]);
    DisplayCurrentPower(printRunState);
    DisplayCurrentTemp(printRunState);

    // 按进程实际需求处理数据
    UpgradeMqttStateByNetwork();
    CxyManagerClient->GetAppPrintState()->serialPort = printRunState.serialPort;
    CxyManagerClient->GetAppPrintState()->sdCardExists = printRunState.sdCardExists;
    CxyManagerClient->GetAppPrintState()->udiskMount = printRunState.udiskMount[UDISK_0];
    CxyManagerClient->GetAppPrintState()->ethernetExists = printRunState.ethernetExists;
    CxyManagerClient->GetAppPrintState()->modleCamera = printRunState.cameraOnline[CAMERA_MODEL];
    CxyManagerClient->GetAppPrintState()->nozzleCamera = printRunState.cameraOnline[CAMERA_NOZZLE];
    CxyManagerClient->GetAppPrintState()->workMode = printRunState.workMode;
    CxyManagerClient->GetAppPrintState()->axisRecoup.x = printSavePara.axisRecoup.x;
    CxyManagerClient->GetAppPrintState()->axisRecoup.y = printSavePara.axisRecoup.y;
    CxyManagerClient->GetAppPrintState()->axisRecoup.z = printSavePara.axisRecoup.z;
    CxyManagerClient->GetAppPrintState()->axisRecoup.e = printSavePara.axisRecoup.e;
    CxyManagerClient->GetAppPrintState()->deviceState = printRunState.deviceState;
    switch (printRunState.workState)
    {
        case APP_PRINT_STATE_IDLE: CxyManagerClient->GetAppPrintState()->workState = 0; break;
        case APP_PRINT_STATE_TO_WORK: break;
        case APP_PRINT_STATE_WORK: CxyManagerClient->GetAppPrintState()->workState = 1; break;
        case APP_PRINT_STATE_TO_PAUSE: CxyManagerClient->GetAppPrintState()->workState = 6; break;
        case APP_PRINT_STATE_PAUSE: CxyManagerClient->GetAppPrintState()->workState = 5; break;
        case APP_PRINT_STATE_TO_RESUME: CxyManagerClient->GetAppPrintState()->workState = 8; break;
        case APP_PRINT_STATE_LAYER_PAUSE: CxyManagerClient->GetAppPrintState()->workState = 1; break;
        case APP_PRINT_STATE_FINISH: CxyManagerClient->GetAppPrintState()->workState = 2; break;
        case APP_PRINT_STATE_FAIL: CxyManagerClient->GetAppPrintState()->workState = 3; break;
        case APP_PRINT_STATE_TO_STOP: CxyManagerClient->GetAppPrintState()->workState = 7; break;
        case APP_PRINT_STATE_STOP: CxyManagerClient->GetAppPrintState()->workState = 4; break;
        case APP_PRINT_STATE_DOWNLOAD: {
            CxyManagerClient->GetAppPrintState()->workState = 0;
            CxyManagerClient->DelectAppPrintState(true);
            break;
        }
    }
    CxyManagerClient->GetAppPrintState()->modelFan = printRunState.fanState[MULTI_FAN_MODEL];
    CxyManagerClient->GetAppPrintState()->caseFan = printRunState.fanState[MULTI_FAN_CASE];
    CxyManagerClient->GetAppPrintState()->auxiliaryFan = printRunState.fanState[MULTI_FAN_AUXILIARY];
    CxyManagerClient->GetAppPrintState()->modelFanPct = printRunState.fanPercentage[MULTI_FAN_MODEL];
    CxyManagerClient->GetAppPrintState()->caseFanPct = printRunState.fanPercentage[MULTI_FAN_CASE];
    CxyManagerClient->GetAppPrintState()->auxiliaryFanPct = printRunState.fanPercentage[MULTI_FAN_AUXILIARY];
    CxyManagerClient->GetAppPrintState()->motorState = printRunState.motorState;
    //CxyManagerClient->GetAppPrintState()->lightState = printRunState.lightState;
    CxyManagerClient->GetAppPrintState()->wifiState = printRunState.wifiState;
    
    // 断料状态，K1、K1 Max会存在两种结构，配置两个断料检测器，实际只是用一个
    if (printRunState.materialStatus[MATERIAL_DETECTOR_1] == MATERIAL_STATUS_IDLE &&
        printRunState.materialStatus[MATERIAL_DETECTOR_2] == MATERIAL_STATUS_IDLE)
    {
        CxyManagerClient->GetAppPrintState()->materialStatus = MATERIAL_STATUS_IDLE;
    }
    else CxyManagerClient->GetAppPrintState()->materialStatus = MATERIAL_STATUS_BLANKING;

    CxyManagerClient->GetAppPrintState()->printSpeed = printRunState.printSpeed;
    CxyManagerClient->GetAppPrintState()->printFlow = printRunState.printFlow;
    CxyManagerClient->GetAppPrintState()->printProgress = printRunState.printProgress;
    CxyManagerClient->GetAppPrintState()->curHotendTemp = printRunState.nozzleCurTemp[NOZZLE_TEMP]/100;
    CxyManagerClient->GetAppPrintState()->targetHotendTemp = printRunState.nozzleMaxTemp[NOZZLE_TEMP]/100;
    if (systemComfig.model == CR_10_H1){
        CxyManagerClient->GetAppPrintState()->curBedTemp = printRunState.bedCurTemp[HOTBED_0_TEMP]/100;
        CxyManagerClient->GetAppPrintState()->targetBedTemp = printRunState.bedMaxTemp[HOTBED_0_TEMP]/100;
    }
    else {
        CxyManagerClient->GetAppPrintState()->curBedTemp = printRunState.bedCurTemp[HOTBED_TEMP]/100;
        CxyManagerClient->GetAppPrintState()->targetBedTemp = printRunState.bedMaxTemp[HOTBED_TEMP]/100;
    }
    CxyManagerClient->GetAppPrintState()->curBoxTemp = printRunState.otherCurTemp[OTHER_TEMP_CAVITY]/100;
    CxyManagerClient->GetAppPrintState()->printUsageTime = printRunState.printUsageTime;
    CxyManagerClient->GetAppPrintState()->printRemainTime = printRunState.printRemainTime;
    CxyManagerClient->GetAppPrintState()->filamentUsed = printRunState.filamentUsed/100;
    CxyManagerClient->GetAppPrintState()->printLayer = printRunState.printLayer;
    CxyManagerClient->GetAppPrintState()->printLayers = printRunState.printLayers;
    CxyManagerClient->GetAppPrintState()->faultCode.code = printRunState.faultCode.code;
    bzero(CxyManagerClient->GetAppPrintState()->faultCode.msg, sizeof(CxyManagerClient->GetAppPrintState()->faultCode.msg));
    memcpy(CxyManagerClient->GetAppPrintState()->faultCode.msg, printRunState.faultCode.msg, strlen(printRunState.faultCode.msg));
    bzero(CxyManagerClient->GetAppPrintState()->faultCode.value, sizeof(CxyManagerClient->GetAppPrintState()->faultCode.value));
    memcpy(CxyManagerClient->GetAppPrintState()->faultCode.value, printRunState.faultCode.value, strlen(printRunState.faultCode.value));
    CxyManagerClient->GetAppPrintState()->existOffContinue = printRunState.existOffContinue;
    CxyManagerClient->GetAppPrintState()->livePosition.x = printRunState.livePosition.x;
    CxyManagerClient->GetAppPrintState()->livePosition.y = printRunState.livePosition.y;
    CxyManagerClient->GetAppPrintState()->livePosition.z = printRunState.livePosition.z;
    CxyManagerClient->GetAppPrintState()->livePosition.e = printRunState.livePosition.e;
    CxyManagerClient->GetAppPrintState()->gcodePosition.x = printRunState.gcodePosition.x;
    CxyManagerClient->GetAppPrintState()->gcodePosition.y = printRunState.gcodePosition.y;
    CxyManagerClient->GetAppPrintState()->gcodePosition.z = printRunState.gcodePosition.z;
    CxyManagerClient->GetAppPrintState()->gcodePosition.e = printRunState.gcodePosition.e;
    CxyManagerClient->GetAppPrintState()->homedAxes.x = printRunState.homedAxes.x;
    CxyManagerClient->GetAppPrintState()->homedAxes.y = printRunState.homedAxes.y;
    CxyManagerClient->GetAppPrintState()->homedAxes.z = printRunState.homedAxes.z;
    CxyManagerClient->GetAppPrintState()->klipperStata = printRunState.klipperStata;
    if(printRunState.autoLevelProgress == 100){
        CxyManagerClient->GetAppPrintState()->autoLevelProgress = 2;
    }else if(printRunState.autoLevelProgress == 0)
    {
        if(printRunState.deviceState == 3)
            CxyManagerClient->GetAppPrintState()->autoLevelProgress = 1;
    }
    char curPosition[32] = {0};
    snprintf(curPosition, 32, "X:%.2f Y:%.2f Z:%.2f", 
        CxyManagerClient->GetAppPrintState()->livePosition.x/1000.00,
        CxyManagerClient->GetAppPrintState()->livePosition.y/1000.00,
        CxyManagerClient->GetAppPrintState()->livePosition.z/1000.00);
    bzero(CxyManagerClient->GetAppPrintState()->curPosition, sizeof(CxyManagerClient->GetAppPrintState()->curPosition));
    memcpy(CxyManagerClient->GetAppPrintState()->curPosition, curPosition, strlen(curPosition));
    
    char autohome[16] = {0};
    snprintf(autohome, 16, "X:%d Y:%d Z:%d", 
        CxyManagerClient->GetAppPrintState()->homedAxes.x, 
        CxyManagerClient->GetAppPrintState()->homedAxes.y, 
        CxyManagerClient->GetAppPrintState()->homedAxes.z);
    bzero(CxyManagerClient->GetAppPrintState()->autohome, sizeof(CxyManagerClient->GetAppPrintState()->autohome));
    memcpy(CxyManagerClient->GetAppPrintState()->autohome, autohome, strlen(autohome));
    
    double temp = CxyManagerClient->GetAppPrintState()->axisRecoup.z/1000.000;
    char zOffset[16] = {0};
    snprintf(zOffset, 16, "%.3f",temp);
    bzero(CxyManagerClient->GetAppPrintState()->zOffset, sizeof(CxyManagerClient->GetAppPrintState()->zOffset));
    memcpy(CxyManagerClient->GetAppPrintState()->zOffset, zOffset, strlen(zOffset));   
    
    bzero(CxyManagerClient->GetAppPrintState()->sdPath, sizeof(CxyManagerClient->GetAppPrintState()->sdPath));
    memcpy(CxyManagerClient->GetAppPrintState()->sdPath, printRunState.sdPath, strlen(printRunState.sdPath));
    bzero(CxyManagerClient->GetAppPrintState()->uDiskPath, sizeof(CxyManagerClient->GetAppPrintState()->uDiskPath));
    memcpy(CxyManagerClient->GetAppPrintState()->uDiskPath, printRunState.uDiskPath, strlen(printRunState.uDiskPath));

    if(CxyManagerClient->GetAppPrintState()->enableSelfTest == 1){
        if(printRunState.withSelfTest >= 1&&printRunState.withSelfTest<100){
            CxyManagerClient->GetAppPrintState()->withSelfTest = 2;
        }else if(printRunState.withSelfTest == 100){
            CxyManagerClient->GetAppPrintState()->withSelfTest = 3;
        }else if(printRunState.withSelfTest == 0 ){
            CxyManagerClient->GetAppPrintState()->withSelfTest = 0;
        }
    }else{
        CxyManagerClient->GetAppPrintState()->withSelfTest = 0;
    }


    if(printRunState.loadMaterial == 1){
        CxyManagerClient->GetAppPrintState()->feedState = 1;
    }else if(printRunState.loadMaterial == 4){
        CxyManagerClient->GetAppPrintState()->feedState = 2;
    }else if(printRunState.loadMaterial == 100){
        CxyManagerClient->GetAppPrintState()->feedState = 3;
    }

    if(printRunState.quitMaterial == 1){
        CxyManagerClient->GetAppPrintState()->feedState = 11;
    }else if(printRunState.quitMaterial == 4){
        CxyManagerClient->GetAppPrintState()->feedState = 12;
    }else if(printRunState.quitMaterial == 5){
        CxyManagerClient->GetAppPrintState()->feedState = 13;
    }else if(printRunState.quitMaterial == 100){
        CxyManagerClient->GetAppPrintState()->feedState = 14;
    }

    CxyManagerClient->GetAppPrintState()->speedMode = printRunState.qmodeFlag;
    CxyManagerClient->GetAppPrintState()->selfTestStep = printRunState.withSelfTest;
    
    GetErrInfo(printRunState);
    
    CxyManagerClient->DelectAppPrintState(false);
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

    // 打印文件名
    char curFileName[256] = {0};
    memcpy(curFileName, workInfo->filename.data, workInfo->filename.len);
    CrLogI("print work file name = %s", curFileName);
    // 过滤绝对路径
    std::string fileName  = curFileName;
    fileName = fileName.substr(fileName.rfind("/") + 1);
    bzero(CxyManagerClient->GetAppPrintState()->printFileName, sizeof(CxyManagerClient->GetAppPrintState()->printFileName));
    strcat(CxyManagerClient->GetAppPrintState()->printFileName, fileName.c_str());

    // 打印开始时间
    CrLogI("print work start time = %d", workInfo->starttime);
    CxyManagerClient->GetAppPrintState()->startPrintTime = workInfo->starttime;

    // 预计打印时间
    CrLogI("print work total time = %d", workInfo->totaltime);
    CxyManagerClient->GetAppPrintState()->printTotalTime = workInfo->totaltime;

    CxyManagerClient->GetAppPrintState()->consumables = workInfo->consumables;

    // 判断启动打印的交互方式
    CrLogI("print work start way = %d", workInfo->startway);
    if (workInfo->startway != PRINT_SOURCE_APP_CLOUD){  
        json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
        if(iotConfig){
            json_object * otherInfoObj = json_object_object_get(iotConfig, "cxy_other_info");
            if(otherInfoObj){
                json_object *jwtObj = json_object_object_get(otherInfoObj, "jwt_token");
                if(jwtObj){
                    bzero(CxyManagerClient->GetAppPrintState()->appJwtToken, sizeof(CxyManagerClient->GetAppPrintState()->appJwtToken));
                    memcpy(CxyManagerClient->GetAppPrintState()->appJwtToken, json_object_get_string(jwtObj), strlen(json_object_get_string(jwtObj)));    
                }
            }
            json_object_put(iotConfig);
        } 
        
        if(workInfo->startway == PRINT_SOURCE_APP_CLOUD_OFF_CONTINUE || workInfo->startway == PRINT_SOURCE_DIS_MARLIN_OFF_CONTINUE ||
            workInfo->startway == PRINT_SOURCE_WEB_LINUX_OFF_CONTINUE){
            
            json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
            if(iotConfig){
                json_object * otherInfoObj = json_object_object_get(iotConfig, "cxy_other_info");
                if(otherInfoObj){
                    json_object *printidObj = json_object_object_get(otherInfoObj, "printid");
                    if(printidObj){
                        bzero(CxyManagerClient->GetAppPrintState()->printId, sizeof(CxyManagerClient->GetAppPrintState()->printId));
                        memcpy(CxyManagerClient->GetAppPrintState()->printId, json_object_get_string(printidObj), strlen(json_object_get_string(printidObj)));    
                    }
                }
                json_object_put(iotConfig);
            }

        }else {
            bzero(CxyManagerClient->GetAppPrintState()->printId, sizeof(CxyManagerClient->GetAppPrintState()->printId));
            char infoBuff[32] = {0};
            snprintf(infoBuff, 32, "%d", workInfo->id);
            std::string ansInfo;
            bool ret = CxyManagerClient->RequestLocalPrint(CxyManagerClient->GetAppPrintState()->appJwtToken, infoBuff,
                (char *)fileName.c_str(), CxyManagerClient->GetAppPrintState()->model_str, &ansInfo);
            if(ret){
                json_object *infoObj = json_tokener_parse(ansInfo.c_str());
                if (infoObj != NULL && json_object_is_type(infoObj, json_type_object)){
                    json_object *resObj = json_object_object_get(infoObj, "result");
                    if(resObj != NULL && json_object_is_type(resObj, json_type_object)){
                        json_object *idObj = json_object_object_get(resObj, "id");
                        if(idObj != NULL && json_object_is_type(idObj, json_type_string)){
                            std::string id = json_object_get_string(idObj);
                            memcpy(CxyManagerClient->GetAppPrintState()->printId, id.c_str(), id.length());
                        }
                    }
                }
                if(infoObj)json_object_put(infoObj);
            }else{
                char localId[32] = {0};
                snprintf(localId, 32, "local_%d", workInfo->id);
                memcpy(CxyManagerClient->GetAppPrintState()->printId, localId, strlen(localId)); 
            }

            json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
            if (!iotConfig) {
                CrLogW("no tb info file\n");
                iotConfig = json_object_new_object();
            }

            json_object *otherInfoObj = json_object_object_get(iotConfig, "cxy_other_info");
            if (!otherInfoObj){
                otherInfoObj = json_object_new_object();
                json_object_object_add(otherInfoObj, "printid", json_object_new_string(CxyManagerClient->GetAppPrintState()->printId));
                json_object_object_add(iotConfig, "cxy_other_info", otherInfoObj);
            }else{
                json_object *printidObj = json_object_object_get(otherInfoObj, "printid");
                if(printidObj){
                    if(strcmp(json_object_get_string(printidObj),CxyManagerClient->GetAppPrintState()->printId) != 0){
                        json_object_object_del(otherInfoObj, "printid");
                        json_object_object_add(otherInfoObj, "printid", json_object_new_string(CxyManagerClient->GetAppPrintState()->printId));
                    }                  
                }else{
                    json_object_object_add(otherInfoObj, "printid", json_object_new_string(CxyManagerClient->GetAppPrintState()->printId));
                }    
            }  
            AppAesEncryptToFile(GetUserIotTbInfoFilePtah(), json_object_to_json_string(iotConfig));
            json_object_put(iotConfig);   

        } 
    }
    CxyManagerClient->GetAppPrintState()->printSource = workInfo->startway;

    // 更新属性
    CxyManagerClient->DelectAppPrintState(false);

    print_work_info__free_unpacked(workInfo, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UploadDelayImageToServer(MsgHeadBuf_t *head)
{
    SendString *resStr = send_string__unpack(NULL, head->bufLen, head->buf);
    if (!resStr) {
        CrLogW("unpack failed\n");
        return;
    }

    char filePath[256] = {0};
    memcpy(filePath, resStr->str.data, resStr->str.len);
    CrLogI("voide file path = %s", filePath);
    CxyManagerClient->AppUploadDelayImage(filePath,"");
    CxyManagerClient->ProcVideoAddPrintid(filePath);
    send_string__free_unpacked(resStr, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void SyncUpgradeStateToServer(MsgHeadBuf_t *head)
{
    UpgradeInfoList *list = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!list) {
        CrLogW("unpack failed\n");
        return;
    }

    // 升级状态
    if (list->linuxota || list->linuxlocal) {
        UpgradeInfo *info = NULL;
        if (list->linuxota) info = list->linuxota;
        if (list->linuxlocal) info = list->linuxlocal;

        CrLogI("get upgrade state %d, progress = %d", info->state, info->progress);
        CxyManagerClient->AppSyncUpgradeState((UpgradeState_t)info->state, info->progress, UPGRADE_TARGET_LINUX);
    }

    upgrade_info_list__free_unpacked(list, NULL);
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

    // 同步获取状态
    if (pre->has_sw) {
        CrLogI("delay image prefer sw = %d", pre->sw);
        CxyManagerClient->GetAppPrintState()->videoElapseState = pre->sw;
        CxyManagerClient->DelectAppPrintState(false);
    }

    if (pre->has_location){
        CrLogI("delay image prefer location = %d", pre->location);
        CxyManagerClient->GetAppPrintState()->nozzleMoveSnapshotState = pre->location;
        CxyManagerClient->DelectAppPrintState(false);        
    }
    
    delay_image_prefer__free_unpacked(pre, NULL);
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

    // 同步获取状态
    if (pre->has_sw) {
        CrLogI("power loss prefer sw = %d", pre->sw);
    }

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

    // 同步获取状态
    if (pre->has_sw) {
        CrLogI("ai control prefer sw = %d", pre->sw);
        CxyManagerClient->GetAppPrintState()->aiSw = pre->sw;
    }
    if (pre->has_detection) {
        CrLogI("ai control prefer detection = %d", pre->detection);
        CxyManagerClient->GetAppPrintState()->aiDetection = pre->detection;
    }
    if (pre->has_pauseprint) {
        CrLogI("ai control prefer pause print = %d", pre->pauseprint);
        CxyManagerClient->GetAppPrintState()->aiPausePrint = pre->pauseprint;
    }
    if (pre->has_firstfloor) {
        CrLogI("ai control prefer first floor = %d", pre->firstfloor);
        CxyManagerClient->GetAppPrintState()->aiFirstFloor = pre->firstfloor;
    }
    if (pre->has_flowdetect) {
        CrLogI("ai control prefer flow detection = %d", pre->flowdetect);
    }

    ai_control_prefer__free_unpacked(pre, NULL);
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
    report_auto_level_res__free_unpacked(levelResult, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ServerSyncResonanceResult(MsgHeadBuf_t *head)
{
    GeneralRes *res = general_res__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }
    CrLogI("resonance result = %d", res->result);
    if(res->result == 1){
        CxyManagerClient->GetAppPrintState()->chatteringOpt = 2;
    }else if(res->result == 2){
        CxyManagerClient->GetAppPrintState()->chatteringOpt = 1;
    }

    general_res__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ControlLocalVideoResult(MsgHeadBuf_t *head)
{
    GeneralRes *res = general_res__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }
    CrLogI("resonance result = %d", res->result);
    //CxyManagerClient->ControlVideoFilesResult(res->result);
    general_res__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetWifiInfoAns(MsgHeadBuf_t *head)
{
    CrLogI("User Control Get Wifi Info Ans");
    NetworksInfo *info = networks_info__unpack(NULL, head->bufLen, head->buf);
    if (!info) {
        CrLogW("unpack failed\n");
        return;
    }

    char sendBuff[256] = {0};
    CrLogI("wifi state, state: %d", info->status);
    if ((info->status == WIFI_STATE_NETWORK || info->status == WIFI_STATE_CONNECTED) && 
        info->has_ssid && info->has_ip)
    {
        CrLogI("wifi change, ssid = [%s], ip = %s, signal = %d\n", info->ssid.data, info->ip.data, info->signal);
        snprintf(sendBuff, 256, "1%d\t%s\t%s\t%d\t", 1, info->ssid.data, info->ip.data, info->signal);

        memset(CxyManagerClient->GetAppPrintState()->wifi_ip, 0, sizeof(CxyManagerClient->GetAppPrintState()->wifi_ip));
        memcpy(CxyManagerClient->GetAppPrintState()->wifi_ip, info->ip.data, strlen((const char *)info->ip.data));
    }
    else snprintf(sendBuff, 256, "1%d\t%s\t%s\t%d\t", 2, "", "", 0);
    
    // 获取有线网络信息
    EthernetInfo_t ethernetInfo = {0};
    if (GetEthernetInfo(&ethernetInfo))
    {
        CrLogI("get ethernet local ip = %s", ethernetInfo.ip);
        CrLogI("get ethernet local gateway = %s", ethernetInfo.gateway);
        CrLogI("get ethernet local subnetMask = %s", ethernetInfo.subnetMask);
        CrLogI("get ethernet local dnsServer = %s", ethernetInfo.dnsServer);
        memset(CxyManagerClient->GetAppPrintState()->lan_ip, 0, sizeof(CxyManagerClient->GetAppPrintState()->lan_ip));
        memcpy(CxyManagerClient->GetAppPrintState()->lan_ip, ethernetInfo.ip, strlen(ethernetInfo.ip));
    }
    
    networks_info__free_unpacked(info, NULL);
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
    
    // 判断用户是否同意隐私协议，不同意不执行以下指令
    if (CxyManagerClient->GetAppPrintState()->agreePrivacy == 0 &&
        head.cmd != SERVER_CMD_APP_GET_SYSTEM_CONFIG_ANS)
    {
        CrLogW("The user has not agreed to the privacy agreement, command not executed; cmd = %d\n", head.cmd);
        return;
    }
    
    // 指令处理
    if (headSize > 0)
    {
        CrLogI("package len = %ld, origin %d, cmd %d, message len %ld", headSize, head.origin, head.cmd, head.bufLen);

        switch (head.cmd)
        {
            case SERVER_CMD_APP_TEST_REQ: ServerMessageTestReq(&head); break;
            case SERVER_CMD_APP_CHECK_UPGRADE_REQ: ManagerCheckUpgradeRes(&head); break;
            case SERVER_CMD_APP_START_UPGRADE_REQ: ManagerStartUpgradeRes(&head); break;
            case SERVER_CMD_APP_CANCEL_UPGRADE_REQ: ManagerCancelUpgradeRes(&head); break;
            case SERVER_CMD_APP_UPLOAD_LOCAL_LOG_REQ: ManagerUploadLoaclLog(&head);break;
            case SERVER_CMD_APP_UPLOAD_LOCAL_VIDEO_REQ: ManagerUploadLoaclVideo(&head);break;
            case SERVER_CMD_APP_UPDATE_USER_INFO_REQ: ManagerUpdateUserInfo(&head);break;
            case SERVER_CMD_APP_SYSTEM_RESET_REQ: ManagerSystemResetRes(&head);break;

            case SERVER_CMD_APP_GET_SYSTEM_CONFIG_ANS: ManagerSyncSystemConfig(&head); break;
            case SERVER_CMD_APP_GET_PRINT_SAVE_PARA_ANS: ManagerSyncPrintSavePara(&head); break;
            case SERVER_CMD_APP_CONTROL_PRINT_ANS: AppControlPrintAns(&head); break;
            case SERVER_CMD_APP_GET_GCODE_FILE_LIST_ANS: AppGetGcodeFileListAns(&head); break;
            case SERVER_CMD_APP_GET_CURRENT_LOCAL_ANS: AppGetCurrentLocalAns(&head); break;

            case SERVER_CMD_APP_GET_DEVICE_STATE_ANS: SyncDeviceStateToApp(&head); break;
            case SERVER_CMD_APP_SYNC_PRINT_WORK_INFO: SyncPrintWorkInfo(&head); break;
            case SERVER_CMD_APP_UPLOAD_DELAY_IMAGE: UploadDelayImageToServer(&head); break;
            case SERVER_CMD_APP_SYNC_UPGRADE_STATE: SyncUpgradeStateToServer(&head); break;
            case MANAGER_CMD_MESSAGE_TEST: ManagerMessageTest(&head); break;

            case SERVER_CMD_APP_GET_DELAY_IMAGE_PRE_ANS: UserGetDelayImagePreAns(&head); break;
            case SERVER_CMD_APP_GET_POWER_LOSS_PRE_ANS: UserGetPowerLossPreAns(&head); break;
            case SERVER_CMD_APP_GET_AI_CONTROL_PRE_ANS: UserGetAiControlPreAns(&head); break;
            case SERVER_CMD_APP_SYNC_AUTO_LEVEL_RESULT: ServerSyncAutoLevelResult(&head); break;
            case SERVER_CMD_APP_SYNC_RESONANCE_RESULT: ServerSyncResonanceResult(&head); break;
            case SERVER_CMD_APP_GET_WIFI_INFO_ANS: UserGetWifiInfoAns(&head); break;
            case SERVER_CMD_APP_CONTROL_LOCAL_VIDEO_RESULT:ControlLocalVideoResult(&head); break;
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
static void AppInitiativeSyncManagerData(void)
{
    // 同步Linux系统配置
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_GET_SYSTEM_CONFIG_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 */
static void AppInitiativeSyncPrintSavePara(void)
{
    // 同步打印机保存参数
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_GET_PRINT_SAVE_PARA_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 */
static void AppInitiativeSyncDeviceState(void)
{
    // 同步打印机保存参数
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_GET_DEVICE_STATE_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}

 */
static void AppInitiativeSyncUserPrefer(void)
{
    // 获取延时摄影偏好
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_GET_DELAY_IMAGE_PRE_REQ, "", 0);
    SendProcessMsgBuff(&send, size);

    // 获取断电续打偏好
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_GET_POWER_LOSS_PRE_REQ, "", 0);
    SendProcessMsgBuff(&send1, size1);

    // 获取AI控制偏好
    CREATE_MESSAGE_PACKAGE(send2, size2, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_GET_AI_CONTROL_PRE_REQ, "", 0);
    SendProcessMsgBuff(&send2, size2);
}

/**
 * @description: 
 * @return {*}
 */
static void AppInitiativeSyncWifiInfo(void)
{
    // 获取wifi信息
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_GET_WIFI_INFO_REQ, "", 0);
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
    managerMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_APP_MANAGER);
    if (managerMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    serverMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_APP_SERVER);
    if (serverMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    // 清空消息队列
    CleanMessageQueue();
    // 初始化MQTT连接状态
    CxyManagerClient = (CxyManager*)arg;
    CxyManagerClient->SyncMqttConnectState(MQTT_THRUN_NUM);
    // 同步manager数据
    AppInitiativeSyncManagerData();
    AppInitiativeSyncPrintSavePara();
    AppInitiativeSyncDeviceState();
    AppInitiativeSyncUserPrefer();
    AppInitiativeSyncWifiInfo();

    while (1)
    {
        MsgUpdata();
        usleep(1000 * 10);
    }
}

/**
 * @description: 通信初始化
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
pthread_t *ServerMessageInit(void *arg)
{
    CrLogI("app server init");
    // 新开线程接收数据
    int res = pthread_create(&messageHandle, NULL, &MessageThread, arg);
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
