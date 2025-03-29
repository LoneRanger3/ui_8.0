/*
 * @Description : app设备管理器
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:09
 * @LastEditTime: 2023-10-26 14:58:13
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
#include "UdpTestServer.h"
#include "AppManager.h"

static MsgHandle_t msgHandle;
static int managerMsgId = -1;
static int serverMsgId = -1;
static UpgradeRebootInfo_t upgradeInfo = {0};

/**
 * @description: 静态函数声明
 */
static int SendMsgBuff(MsgHeadBuf_t *data, size_t len);
static int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len);
static void UserAppGetDelayImagePreferReq(MsgHeadBuf_t *head);


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
static void ManagerDeviceStateChange(MsgHeadBuf_t *head)
{
    PrintState_t curState = GetPrintState();
    SyncPrintState syncState = SYNC_PRINT_STATE__INIT;

    syncState.serialport = curState.serialPort;
    syncState.sdcardexists = curState.sdCardExists;
    syncState.n_udiskmount = UDISK_SIZE;
    syncState.udiskmount = curState.udiskMount;
    syncState.ethernetexists = curState.ethernetExists;
    syncState.n_cameraonline = CAMERA_SIZE;
    syncState.cameraonline = curState.cameraOnline;
    syncState.laserexists = curState.laserExists;
    syncState.scannerexists = curState.scannerExists;
    syncState.devicestate = curState.deviceState;
    syncState.workmode = curState.workMode;
    syncState.workstate = curState.workState;
    syncState.n_fanstate = MULTI_FAN_SIZE;
    syncState.fanstate = curState.fanState;
    syncState.n_fanspeed = MULTI_FAN_SIZE;
    syncState.fanspeed = curState.fanSpeed;
    syncState.n_fanpercentage = MULTI_FAN_SIZE;
    syncState.fanpercentage = curState.fanPercentage;
    syncState.motorstate = curState.motorState;
    syncState.lightstate = curState.lightState;
    syncState.wifistate = curState.wifiState;
    syncState.n_materialstatus = MATERIAL_DETECTOR_SIZE;
    syncState.materialstatus = curState.materialStatus;
    syncState.printspeed = curState.printSpeed;
    syncState.printflow = curState.printFlow;
    syncState.realtimespeed = curState.realTimeSpeed;
    syncState.realtimeflow = curState.realTimeFlow;
    syncState.curprintlayer = curState.printLayer;
    syncState.printtotallayer = curState.printLayers;
    syncState.printprogress = curState.printProgress/100;
    syncState.n_curhotendtemp = NOZZLE_TEMP_SIZE;
    syncState.curhotendtemp = curState.nozzleCurTemp;
    syncState.n_curbedtemp = HOTBED_TEMP_SIZE;
    syncState.curbedtemp = curState.bedCurTemp;
    syncState.n_targethotendtemp = NOZZLE_TEMP_SIZE;
    syncState.targethotendtemp = curState.nozzleMaxTemp;
    syncState.n_targetbedtemp = HOTBED_TEMP_SIZE;
    syncState.targetbedtemp = curState.bedMaxTemp;
    syncState.n_curhotendpower = NOZZLE_TEMP_SIZE;
    syncState.curhotendpower = curState.nozzlePower;
    syncState.n_curbedpower = HOTBED_TEMP_SIZE;
    syncState.curbedpower = curState.bedPower;
    syncState.n_othercurtemp = OTHER_TEMP_SIZE;
    syncState.othercurtemp = curState.otherCurTemp;
    syncState.nozzletempwait = curState.nozzleTempWait;
    syncState.bedtempwait = curState.bedTempWait;
    
    syncState.printusagetime = curState.printUsageTime;
    syncState.printremaintime = curState.printRemainTime;
    syncState.filamentused = curState.filamentUsed;
    syncState.autolevelprogress = curState.autoLevelProgress;
    syncState.autopidprogress = curState.autoPidProgress;
    syncState.crtouchstate = curState.crTouchState;
    syncState.existoffcontinue = curState.existOffContinue;

    UpdataErrorInfo info = UPDATA_ERROR_INFO__INIT;
    info.code = curState.faultCode.code;
    info.error = curState.faultCode.error;
    info.msg.data = (uint8_t*)curState.faultCode.msg;
    info.msg.len = strlen(curState.faultCode.msg);
    info.values.data = (uint8_t*)curState.faultCode.value;
    info.values.len = strlen(curState.faultCode.value);
    syncState.faultcode = &info;

    AxisPositionInfo position = AXIS_POSITION_INFO__INIT;
    position.x = curState.livePosition.x;
    position.y = curState.livePosition.y;
    position.z = curState.livePosition.z;
    position.e = curState.livePosition.e;
    syncState.liveposition = &position;

    AxisPositionInfo gcodePosition = AXIS_POSITION_INFO__INIT;
    gcodePosition.x = curState.gcodePosition.x;
    gcodePosition.y = curState.gcodePosition.y;
    gcodePosition.z = curState.gcodePosition.z;
    gcodePosition.e = curState.gcodePosition.e;
    syncState.gcodeposition = &gcodePosition;

    AxisPositionInfo homedAxes = AXIS_POSITION_INFO__INIT;
    homedAxes.x = curState.homedAxes.x;
    homedAxes.y = curState.homedAxes.y;
    homedAxes.z = curState.homedAxes.z;
    homedAxes.e = curState.homedAxes.e;
    syncState.homedaxes = &homedAxes;

    syncState.klipperstata = curState.klipperStata;
    syncState.klipperprint = curState.klipperPrint;

    syncState.sdpath.data = (uint8_t*)curState.sdPath;
    syncState.sdpath.len = strlen(curState.sdPath);
    syncState.udiskpath.data = (uint8_t*)curState.uDiskPath;
    syncState.udiskpath.len = strlen(curState.uDiskPath);

    syncState.qmodeflag = curState.qmodeFlag;
    syncState.withselftest = curState.withSelfTest;
    syncState.loadmaterial = curState.loadMaterial;
    syncState.quitmaterial = curState.quitMaterial;
    syncState.cxymqttstate = curState.cxyMqttState;
    syncState.logprogress = curState.logProgress;
    syncState.scanfileprogress = curState.scanFileProgress;

    GET_MESSAGE_BUFF(buff);
    size_t len = sync_print_state__pack(&syncState, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_GET_DEVICE_STATE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerUploadDelayImage(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_UPLOAD_DELAY_IMAGE, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerSyncUpgradeState(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_SYNC_UPGRADE_STATE, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerSyncPrintWorkInfo(MsgHeadBuf_t *head)
{
    CurrentFile_t workInfo = GetPrinter()->current_file;
    PrintWorkInfo sendWorkInfo = PRINT_WORK_INFO__INIT;

    sendWorkInfo.id = workInfo.id;
    sendWorkInfo.filename.data = (uint8_t*)workInfo.fileName;
    sendWorkInfo.filename.len = strlen(workInfo.fileName) + 1;
    sendWorkInfo.size = workInfo.size;
    sendWorkInfo.ctime = workInfo.cTime;
    sendWorkInfo.starttime = workInfo.startTime;
    sendWorkInfo.totaltime = workInfo.estimated_time;
    sendWorkInfo.consumables = workInfo.filament_total;
    sendWorkInfo.startway = workInfo.startWay;
    sendWorkInfo.thumbnail.data = (uint8_t*)workInfo.thumbnails;
    sendWorkInfo.thumbnail.len = strlen(workInfo.thumbnails);
    sendWorkInfo.photo.data = (uint8_t*)workInfo.preview;
    sendWorkInfo.photo.len = strlen(workInfo.preview);
    sendWorkInfo.startpixel = workInfo.startPixel;
    sendWorkInfo.endpixel = workInfo.endPixel;
    sendWorkInfo.modelheight = workInfo.modelHeight;
    sendWorkInfo.layerheight = workInfo.layerHeight;
    sendWorkInfo.software.data = (uint8_t*)workInfo.software;
    sendWorkInfo.software.len = strlen(workInfo.software);

    GET_MESSAGE_BUFF(buf);
    size_t len = print_work_info__pack(&sendWorkInfo, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_SYNC_PRINT_WORK_INFO, buf, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetGcodeFileListAns(MsgHeadBuf_t *head)
{
    GetGcodeFIleList *getList = get_gcode_file_list__unpack(NULL, head->bufLen, head->buf);
    if (!getList) {
        CrLogW("unpack failed\n");
        return;
    }
    char *cachePath = GetUserGcodeFileInfoFilePath();
    GetGcodeFIleList getListToSend = GET_GCODE_FILE_LIST__INIT;
    getListToSend.has_path = 1;
    getListToSend.path.data = (uint8_t*)cachePath;
    getListToSend.path.len = strlen(cachePath) + 1;
    getListToSend.has_type = getList->has_type;
    getListToSend.type = getList->type;

    GET_MESSAGE_BUFF(buff);
    size_t len = get_gcode_file_list__pack(&getListToSend, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_GET_GCODE_FILE_LIST_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    get_gcode_file_list__free_unpacked(getList, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserAppControlPrintAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *result = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!result) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("print control file result = %d", result->result);
    AppControlPrint control = APP_CONTROL_PRINT__INIT;
    if (result->result)
    {
        control.has_result = 1;
        control.result = result->result;
    }
    gcode_cmd_res__free_unpacked(result, NULL);

    GET_MESSAGE_BUFF(res);
    size_t resLen = app_control_print__pack(&control, res);
    CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_CONTROL_PRINT_ANS, res, resLen);
    SendProcessMsgBuff(&resSend, resSize);
}

/**
 * @description: 
 * @return {*}
 * @param {int} result
 */
static void UserAppControlPrintDirectAns(int result)
{
    CrLogI("print control file result = %d", result);
    AppControlPrint control = APP_CONTROL_PRINT__INIT;
    control.has_result = 1;
    control.result = result;

    GET_MESSAGE_BUFF(res);
    size_t resLen = app_control_print__pack(&control, res);
    CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_CONTROL_PRINT_ANS, res, resLen);
    SendProcessMsgBuff(&resSend, resSize);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void UserGetHotendXyzLocalAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *hotendLocal = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!hotendLocal) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("get nozzle xyz local result = %d", hotendLocal->result);
    if (hotendLocal->result && hotendLocal->has_resstr)
    {
        AxisPara *local = axis_para__unpack(NULL, hotendLocal->resstr.len, hotendLocal->resstr.data);
        if (!local) {
            CrLogW("unpack failed\n");
        }

        AxisPositionInfo axisInfo = AXIS_POSITION_INFO__INIT;
        axisInfo.x = local->x;
        axisInfo.y = local->y;
        axisInfo.z = local->z;
        axisInfo.e = local->e;

        GET_MESSAGE_BUFF(buff);
        size_t len = axis_position_info__pack(&axisInfo, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_GET_CURRENT_LOCAL_ANS, buff, len);
        SendProcessMsgBuff(&send, size);

        axis_para__free_unpacked(local, NULL);
    }
    gcode_cmd_res__free_unpacked(hotendLocal, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppGetDeviceUpgradeInfoRes(MsgHeadBuf_t *head)
{
    CrLogI("App Get Device upgrade Info Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_CHECK_UPGRADE_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppStartDeviceUpgradeRes(MsgHeadBuf_t *head)
{
    CrLogI("App Start Device upgrade Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_START_UPGRADE_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppCancelDeviceUpgradeRes(MsgHeadBuf_t *head)
{
    CrLogI("App Start Device upgrade Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_CANCEL_UPGRADE_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppUploadLocalVideoRes(MsgHeadBuf_t *head)
{
    CrLogI("App upload local video Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_UPLOAD_LOCAL_VIDEO_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppUpdateUserCxyInfoRes(MsgHeadBuf_t *head)
{
    CrLogI("App update user cxy info Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_UPDATE_USER_INFO_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppSystemResetToIotRes(MsgHeadBuf_t *head)
{
    CrLogI("App System Reset To Iot Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_SYSTEM_RESET_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppUploadLocalLogRes(MsgHeadBuf_t *head)
{
    CrLogI("App upload local log Res");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_UPLOAD_LOCAL_LOG_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void AppGetSystemConfigRes(MsgHeadBuf_t *head)
{
    SystemConfig_t config = GetSystemConfig();
    SystemConfigProto sendConfig = SYSTEM_CONFIG_PROTO__INIT;

    sendConfig.has_sys_version = 1;
    sendConfig.sys_version.data = (uint8_t*)config.sys_version;
    sendConfig.sys_version.len = strlen(config.sys_version);
    sendConfig.has_fw_version = 1;
    sendConfig.fw_version.data = (uint8_t*)config.fw_version;
    sendConfig.fw_version.len = strlen(config.fw_version);
    sendConfig.has_hw_version = 1;
    sendConfig.hw_version.data = (uint8_t*)config.hw_version;
    sendConfig.hw_version.len = strlen(config.hw_version);
    sendConfig.has_hw1_version = 1;
    sendConfig.hw1_version.data = (uint8_t*)config.hw1_version;
    sendConfig.hw1_version.len = strlen(config.hw1_version);
    sendConfig.has_website = 1;
    sendConfig.website.data = (uint8_t*)config.website;
    sendConfig.website.len = strlen(config.website);
    sendConfig.has_model = 1;
    sendConfig.model = config.model;
    sendConfig.has_model_str = 1;
    sendConfig.model_str.data = (uint8_t*)config.model_str;
    sendConfig.model_str.len = strlen(config.model_str);
    sendConfig.has_bed_length = 1;
    sendConfig.bed_length = config.bed_length;
    sendConfig.has_bed_width = 1;
    sendConfig.bed_width = config.bed_width;
    sendConfig.has_bed_hight = 1;
    sendConfig.bed_hight = config.bed_hight;
    sendConfig.has_device_sn = 1;
    sendConfig.device_sn.data = (uint8_t*)config.device_sn;
    sendConfig.device_sn.len = strlen(config.device_sn);
    sendConfig.has_device_mac = 1;
    sendConfig.device_mac.data = (uint8_t*)config.device_mac;
    sendConfig.device_mac.len = strlen(config.device_mac);
    sendConfig.has_swap_way = 1;
    sendConfig.swap_way = config.swap_way;
    sendConfig.has_deploy_setting = 1;
    sendConfig.deploy_setting = config.deploy_setting;
    sendConfig.has_customer = 1;
    sendConfig.customer = config.customer;
    sendConfig.has_language = 1;
    sendConfig.language = config.language;
    sendConfig.has_sound_size = 1;
    sendConfig.sound_size = config.sound_size;
    sendConfig.has_sound_sw = 1;
    sendConfig.sound_sw = config.sound_sw;
    sendConfig.has_sounde_ffect = 1;
    sendConfig.sounde_ffect = config.sounde_ffect;
    sendConfig.has_light_sw = 1;
    sendConfig.light_sw = config.light_sw;
    sendConfig.has_light_value = 1;
    sendConfig.light_value = config.light_value;
    sendConfig.has_wifi_sw = 1;
    sendConfig.wifi_sw = config.wifi_sw;
    sendConfig.has_theme_mode = 1;
    sendConfig.theme_mode = config.theme_mode;
    sendConfig.has_self_test_sw = 1;
    sendConfig.self_test_sw = config.self_test_sw;
    sendConfig.has_screensaver = 1;
    sendConfig.screensaver = config.screensaver;
    sendConfig.has_screen_value = 1;
    sendConfig.screen_value = config.screen_value;
    sendConfig.has_auto_power_off = 1;
    sendConfig.auto_power_off = config.auto_power_off;
    sendConfig.has_ui_direction = 1;
    sendConfig.ui_direction = config.ui_direction;
    sendConfig.has_full_screen = 1;
    sendConfig.full_screen = config.full_screen;
    sendConfig.has_z_direction = 1;
    sendConfig.z_direction = config.z_direction;
    sendConfig.has_total_time = 1;
    sendConfig.total_time = config.total_time;
    sendConfig.has_enableselftest = 1;
    sendConfig.enableselftest = config.enableselftest;
    sendConfig.has_time_zone = 1;
    sendConfig.time_zone.data = (uint8_t*)config.time_zone;
    sendConfig.time_zone.len = strlen(config.time_zone);
    sendConfig.has_upgrade_remind = 1;
    sendConfig.upgrade_remind = config.upgrade_remind;
    sendConfig.has_server_local = 1;
    sendConfig.server_local = config.server_local;
    sendConfig.has_agree_privacy = 1;
    sendConfig.agree_privacy = config.agree_privacy;
    sendConfig.has_creality_num = 1;
    sendConfig.creality_num = config.creality_num;
    sendConfig.has_host_name = 1;
    sendConfig.host_name.data = (uint8_t*)config.host_name;
    sendConfig.host_name.len = strlen(config.host_name);
    sendConfig.has_data_collect = 1;
    sendConfig.data_collect = config.data_collect;
    CrLogI("version; sys = %s, hw = %s, model = %s",
            config.sys_version, config.hw_version, config.model_str);

    GET_MESSAGE_BUFF(buff);
    size_t len = system_config_proto__pack(&sendConfig, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_GET_SYSTEM_CONFIG_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void AppGetPrintSaveParaRes(MsgHeadBuf_t *head)
{
    PrintSavePara_t printSavePara = GetPrintSavePara();
    PrintSavePara sendPara = PRINT_SAVE_PARA__INIT;

    sendPara.powerloss = printSavePara.powerLoss;
    sendPara.materialdetect = printSavePara.materialDetect;

    PidInfo hotendPid = PID_INFO__INIT;
    hotendPid.p = printSavePara.hotendPid.p;
    hotendPid.i = printSavePara.hotendPid.i;
    hotendPid.d = printSavePara.hotendPid.d;
    sendPara.hotendpid = &hotendPid;

    PidInfo bedPid = PID_INFO__INIT;
    bedPid.p = printSavePara.bedPid.p;
    bedPid.i = printSavePara.bedPid.i;
    bedPid.d = printSavePara.bedPid.d;
    sendPara.bedpid = &bedPid;

    sendPara.nozzlehwmaxtemp = printSavePara.nozzleHwMaxTemp;
    sendPara.bedhwmaxtemp = printSavePara.bedHwMaxTemp;

    AxisPositionInfo offset = AXIS_POSITION_INFO__INIT;
    offset.x = printSavePara.homeOffset.x;
    offset.y = printSavePara.homeOffset.y;
    offset.z = printSavePara.homeOffset.z;
    offset.e = printSavePara.homeOffset.e;
    sendPara.homeoffset = &offset;

    AxisPositionInfo recoup = AXIS_POSITION_INFO__INIT;
    recoup.x = printSavePara.axisRecoup.x;
    recoup.y = printSavePara.axisRecoup.y;
    recoup.z = printSavePara.axisRecoup.z;
    recoup.e = printSavePara.axisRecoup.e;
    sendPara.axisrecoup = &recoup;

    AxisPositionInfo step = AXIS_POSITION_INFO__INIT;
    step.x = printSavePara.stepValue.x;
    step.y = printSavePara.stepValue.y;
    step.z = printSavePara.stepValue.z;
    step.e = printSavePara.stepValue.e;
    sendPara.stepvalue = &step;

    AxisPositionInfo acceleration = AXIS_POSITION_INFO__INIT;
    acceleration.x = printSavePara.Acceleration.x;
    acceleration.y = printSavePara.Acceleration.y;
    acceleration.z = printSavePara.Acceleration.z;
    acceleration.e = printSavePara.Acceleration.e;
    sendPara.acceleration = &acceleration;

    AxisPositionInfo speed = AXIS_POSITION_INFO__INIT;
    speed.x = printSavePara.Speed.x;
    speed.y = printSavePara.Speed.y;
    speed.z = printSavePara.Speed.z;
    speed.e = printSavePara.Speed.e;
    sendPara.speed = &speed;

    AxisPositionInfo jerk = AXIS_POSITION_INFO__INIT;
    jerk.x = printSavePara.Jerk.x;
    jerk.y = printSavePara.Jerk.y;
    jerk.z = printSavePara.Jerk.z;
    jerk.e = printSavePara.Jerk.e;
    sendPara.jerk = &jerk;

    sendPara.k_speed = printSavePara.k_Speed;
    sendPara.k_acceleration = printSavePara.k_Acceleration;
    sendPara.k_corner = printSavePara.k_Corner;
    sendPara.k_jerk = printSavePara.k_Jerk;
    sendPara.pressureadvance = printSavePara.pressureAdvance;
    sendPara.smoothtime = printSavePara.SmoothTime;
    sendPara.fanfeedback = printSavePara.fanFeedback;

    AxisPositionInfo points = AXIS_POSITION_INFO__INIT;
    points.x = printSavePara.levelPoints.x;
    points.y = printSavePara.levelPoints.y;
    sendPara.levelpoint = &points;

    AxisPositionInfo devMaxSize = AXIS_POSITION_INFO__INIT;
    devMaxSize.x = printSavePara.devMaxSize.x;
    devMaxSize.y = printSavePara.devMaxSize.y;
    devMaxSize.z = printSavePara.devMaxSize.z;
    sendPara.devmaxsize = &devMaxSize;

    AxisPositionInfo devMinSize = AXIS_POSITION_INFO__INIT;
    devMinSize.x = printSavePara.devMinSize.x;
    devMinSize.y = printSavePara.devMinSize.y;
    devMinSize.z = printSavePara.devMinSize.z;
    sendPara.devminsize = &devMinSize;

    sendPara.bedmeshinfo.data = printSavePara.bedMeshInfo;
    sendPara.bedmeshinfo.len = strlen(printSavePara.bedMeshInfo);

    GET_MESSAGE_BUFF(buff);
    size_t len = print_save_para__pack(&sendPara, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_GET_PRINT_SAVE_PARA_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppGetGcodeFileListRes(MsgHeadBuf_t *head)
{
    // 获取扫描路径
    char *traversePath = GetUserLocalSdCardPtah();

    // 发送指令
    GetGcodeFIleList getList = GET_GCODE_FILE_LIST__INIT;
    getList.has_path = 1;
    getList.path.data = (uint8_t*)traversePath;
    getList.path.len = strlen(traversePath) + 1;
    getList.has_type = 1;
    getList.type = 0;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = get_gcode_file_list__pack(&getList, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_GET_SD_FILE_REQ, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppGetUDiskGcodeFileListRes(MsgHeadBuf_t *head)
{
    // 获取扫描路径
    char *traversePath = GetUserLocalUdiskPtah();

    // 发送指令
    GetGcodeFIleList getList = GET_GCODE_FILE_LIST__INIT;
    getList.has_path = 1;
    getList.path.data = (uint8_t*)traversePath;
    getList.path.len = strlen(traversePath) + 1;
    getList.has_type = 1;
    getList.type = 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = get_gcode_file_list__pack(&getList, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_GET_SD_FILE_REQ, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void AppGetCurrentLocalRes(MsgHeadBuf_t *head)
{
    GcodeCmd local = GCODE_CMD__INIT;
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd__pack(&local, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_GET_HOTEND_XYZ_LOCAL_REQ, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppGetDeviceUpgradeInfoAns(MsgHeadBuf_t *head)
{
    UpgradeInfoList *infoList = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!infoList) {
        CrLogW("unpack failed\n");
        return;
    }

    // 打印版本信息
    if (infoList->linuxota) {
        CrLogI("get linux upgrade info");
        UpgradeInfo *info = infoList->linuxota;
        if (info->has_version) CrLogI("get upgrade version = %s", info->version.data);
        if (info->has_url) CrLogI("get upgrade download url = %s", info->url.data);
    }
    if (infoList->mcu1ota) {
        CrLogI("get mcu1 upgrade info");
        UpgradeInfo *info = infoList->mcu1ota;
        if (info->has_version) CrLogI("get upgrade version = %s", info->version.data);
        if (info->has_url) CrLogI("get upgrade download url = %s", info->url.data);
    }

    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GET_UPGRADE_INFO_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);

    upgrade_info_list__free_unpacked(infoList, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppStartDeviceUpgradeAns(MsgHeadBuf_t *head)
{
    GeneralRes *res = general_res__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("start device upgrade result = %d", res->result);

    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_START_UPGRADE_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);

    general_res__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppCancelDeviceUpgradeAns(MsgHeadBuf_t *head)
{
    GeneralRes *res = general_res__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("cancel device upgrade result = %d", res->result);

    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_CANCEL_UPGRADE_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);

    general_res__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppUploadLocalLogAns(MsgHeadBuf_t *head)
{
    MutableTypeData *res = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }

    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_UPLOAD_LOCAL_LOG_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);

    mutable_type_data__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppUploadLocalVideoAns(MsgHeadBuf_t *head)
{
    GeneralRes *res = general_res__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("app upload local video result = %d", res->result);
    GcodeCmdRes result = GCODE_CMD_RES__INIT;
    result.result = res->result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&result, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_UPLOAD_LOCAL_VIDEO_ANS, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);

    general_res__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppUpdateUserInfoAns(MsgHeadBuf_t *head)
{
    GeneralRes *res = general_res__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("app get user info result = %d", res->result);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_UPDATE_USER_CXY_INFO_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);

    general_res__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppSystemResetToIotAns(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_SYSTEM_RESET_TO_APP_ANS, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppSyncUpgradeState(MsgHeadBuf_t *head)
{
    UpgradeInfoList *list = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!list) {
        CrLogW("unpack failed\n");
        return;
    }

    if (list->linuxota) {
        if (list->linuxota->has_progress) CrLogI("get linux upgrade download progress = %d", list->linuxota->progress);
    }
    if (list->mcu1ota) {
        if (list->mcu1ota->has_progress) CrLogI("get mcu upgrade download progress = %d", list->mcu1ota->progress);
    }

    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_SYNC_DEV_UPGRADE_STATE, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);

    upgrade_info_list__free_unpacked(list, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppStartLocalUpgrade(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_START_UPGRADE_REQ, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_UPGRADE_MANAGER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppSyncMqttConnectState(MsgHeadBuf_t *head)
{
    MutableTypeData *state = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!state) {
        CrLogW("unpack failed\n");
        return;
    }

    // 更新状态
    if(state->has_int_v) {
        CrLogI("sync mqtt connect state = %d", state->int_v);
        UpdataCxyMqttState(state->int_v);
    }
    mutable_type_data__free_unpacked(state, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppSyncGcodeDownloadState(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_SYNC_GCODE_DOWNLOAD, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppSyncExportLogState(MsgHeadBuf_t *head)
{
    ExportLogState *sync = export_log_state__unpack(NULL, head->bufLen, head->buf);
    if (!sync) {
        CrLogW("unpack failed\n");
        return;
    }

    int deviceState = GetPrintState().deviceState;
    CrLogI("upload log, state = %d, progress = %d, deviceState = %d\n", sync->state, sync->progress, deviceState);

    if (sync->state == COMPRESSING_LOG)
        UpdataDeviceState(DEVICE_STATE_COMPRESSING_LOG);
    else if (sync->state == EXPORTING_LOGS)
        UpdataDeviceState(DEVICE_STATE_UPLOAD_LOG);
    else if (deviceState == DEVICE_STATE_COMPRESSING_LOG || deviceState == DEVICE_STATE_UPLOAD_LOG)
        UpdataDeviceState(DEVICE_STATE_IDLE);
    
    // 失败进度置-1
    if (sync->state == EXPORT_LOG_FAIL) UpdataLogProgress(-1);
    if (sync->state == EXPORT_STOPLOG_SUCCESS) UpdataLogProgress(-2);
    else UpdataLogProgress(sync->progress);

    export_log_state__free_unpacked(sync, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void AppControlPrintRes(MsgHeadBuf_t *head)
{
    AppControlPrint *control = app_control_print__unpack(NULL, head->bufLen, head->buf);
    if (!control) {
        CrLogW("unpack failed\n");
        return;
    }
    // 开始打印文件
    if (control->has_print) {
        CrLogI("app control start print local gcode");
        CrLogI("file name = %s\n", control->print.data);
        MutableTypeData start = MUTABLE_TYPE_DATA__INIT;
        start.has_bytes_v = 1;
        start.bytes_v.data = control->print.data;
        start.bytes_v.len = control->print.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&start, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_START_CLOUD_PRINT_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 暂停
    if (control->has_pause)
    {
        CrLogI("app control paue/resume print local gcode, paue/resume = %d\n", control->pause);
        GcodeCmd printControl = GCODE_CMD__INIT;
        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&printControl, buff);

        if (control->pause) {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_PAUSE_PRINT_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
        else {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_RESUME_PRINT_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
    }
    // 停止
    if (control->has_stop)
    {
        CrLogI("app control stop print local gcode, stop = %d\n", control->stop);
        if (control->stop) {
            GcodeCmd printControl = GCODE_CMD__INIT;
            GET_MESSAGE_BUFF(buff);
            size_t len = gcode_cmd__pack(&printControl, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_STOP_PRINT_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
    }
    // 风扇控制
    if (control->fan)
    {
        CrLogI("app control fan\n");
        GET_MESSAGE_BUFF(buff);
        size_t len = multi_fan__pack(control->fan, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_OPEN_FAN_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置喷嘴温度
    if (control->nozzletemp)
    {
        CrLogI("app control nozzle temp\n");
        GET_MESSAGE_BUFF(buff);
        size_t len = extruder__pack(control->nozzletemp, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_SET_NOZZLE_TEMP_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置热床温度
    if (control->bedtemp)
    {
        CrLogI("app control bed temp\n");
        GET_MESSAGE_BUFF(buff);
        size_t len = heater_bed__pack(control->bedtemp, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_SET_BED_TEMP_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 控制断电续打
    if (control->has_powerloss)
    {
        CrLogI("app control power loss, value = %d\n", control->powerloss);

        GcodeCmd print = GCODE_CMD__INIT;
        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&print, buff);

        if (control->powerloss) {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_START_POWER_LOSS_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
        else {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_CANCEL_POWER_LOSS_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
    }

    // 控制回原点
    if (control->has_autohome)
    {
        CrLogI("app control autohome, value = %d\n", control->autohome);
        if(control->autohome == 0){
            GcodeCmd move = GCODE_CMD__INIT;
            move.has_cmdstr = 1;
            move.cmdstr.data = (uint8_t*)"";
            move.cmdstr.len = 0;

            GET_MESSAGE_BUFF(buff);
            size_t len = gcode_cmd__pack(&move, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_RETURN_HOME_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }

    }
    // 轴移动（X\Y\Z\E）
    if (control->has_setposition)
    {
        CrLogI("app control setPosition, value = %s\n", control->setposition.data);
        char moveCmd[256] = {0};
        snprintf(moveCmd, 256, "SAVE_GCODE_STATE NAME=myMoveState\n G91\n G0 %s\n M400\n RESTORE_GCODE_STATE NAME=myMoveState", control->setposition.data);
        GcodeCmd move = GCODE_CMD__INIT;
        move.has_cmdstr = 1;
        move.cmdstr.data = (uint8_t*)moveCmd;
        move.cmdstr.len = strlen(moveCmd);

        GET_MESSAGE_BUFF(buff1);
        size_t len1 = gcode_cmd__pack(&move, buff1);
        CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_HOTEND_XYZ_MOVE_REQ, buff1, len1);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send1, size1);
    }
    // 设置打印倍速
    if (control->has_setfeedratepct)
    {
        CrLogI("app control setFeedratePct, value = %d\n", control->setfeedratepct.data);
        GcodeCmd speed = GCODE_CMD__INIT;
        speed.has_cmdstr = 1;
        speed.cmdstr.data = control->setfeedratepct.data;
        speed.cmdstr.len = control->setfeedratepct.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&speed, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_SET_PRINT_SPEED_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置流量倍速
    if (control->has_setflowratepct)
    {
        CrLogI("app control setFlowratePct, value = %d\n", control->setflowratepct.data);
        GcodeCmd flow = GCODE_CMD__INIT;
        flow.has_cmdstr = 1;
        flow.cmdstr.data = control->setflowratepct.data;
        flow.cmdstr.len = control->setflowratepct.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&flow, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_SET_PRINT_FLOW_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 执行gcode宏定义
    if (control->has_gcodecmd)
    {
        CrLogI("app control gcodeCmd, value = %d\n", control->gcodecmd.data);
        GcodeCmd macro = GCODE_CMD__INIT;
        macro.has_cmdstr = 1;
        macro.cmdstr.data = control->gcodecmd.data;
        macro.cmdstr.len = control->gcodecmd.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&macro, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_SET_GCODE_MACRO_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    
    if (control->has_videoelapse)
    {
        CrLogI("app control videoElapse, value = %d\n", control->videoelapse);
        DelayImagePrefer prefer = DELAY_IMAGE_PREFER__INIT;
        prefer.has_sw = 1;
        prefer.sw = control->videoelapse;

        // 设置摄像头设置
        int result = SetDelayImagePrefer(&prefer);
        UserAppControlPrintDirectAns(result);
    }

    if (control->has_nozzlemovesnapshot)
    {
        CrLogI("app control has_nozzleMoveSnapshot, value = %d\n", control->nozzlemovesnapshot);
        DelayImagePrefer prefer = DELAY_IMAGE_PREFER__INIT;
        prefer.has_location = 1;
        prefer.location = control->nozzlemovesnapshot;

        // 设置摄像头设置
        int result = SetDelayImagePrefer(&prefer);
        UserAppControlPrintDirectAns(result);
    }
    // 设置断电续打参数
    if (control->has_powerlossswitch)
    {
        CrLogI("app control power loss, value = %d\n", control->powerlossswitch);
        PowerLossPrefer prefer = POWER_LOSS_PREFER__INIT;
        prefer.has_sw = 1;
        prefer.sw = control->powerlossswitch;

        // 设置断电续打设置
        int result = SetPowerLossPrefer(&prefer);
        UserAppControlPrintDirectAns(result);
    }
    // 设置AI控制偏好
    if (control->aipre)
    {
        CrLogI("app control ai control\n");
        // 设置AI控制设置
        int result = SetAiControlPrefer(control->aipre);
        UserAppControlPrintDirectAns(result);
    }
    // 灯光开关
    if (control->has_lightsw)
    {
        CrLogI("app control led, value = %d\n", control->lightsw);
        SystemConfigProto config = SYSTEM_CONFIG_PROTO__INIT;
        config.has_light_sw= 1;
        config.light_sw = control->lightsw;
        int result = UpdataSystemConfig(&config);
        UserAppControlPrintDirectAns(result);
    }
    // 打印前检测开关
    if (control->has_enableselftest)
    {
        CrLogI("app control enableSelfTest, value = %d\n", control->enableselftest);
        SystemConfigProto config = SYSTEM_CONFIG_PROTO__INIT;
        config.has_enableselftest= 1;
        config.enableselftest = control->enableselftest;
        int result = UpdataSystemConfig(&config);
        UserAppControlPrintDirectAns(result);
    }
    // 设置自动调平
    if (control->has_autoleveling)
    {
        CrLogI("app set auto level");
        // 设置自动调平
        MutableTypeData move = MUTABLE_TYPE_DATA__INIT;
        move.has_int_v = 1;
        move.int_v = control->autoleveling;

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&move, buff);
        CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_DEVICE_AUTO_LEVEL_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send1, size1);
    }
    // 谐振补偿测试
    if (control->has_chatteringopt)
    {
        CrLogI("app set resonance test = %d", control->chatteringopt);
        char cmd[16] = {0};
        if(control->chatteringopt == 1){
            memcpy(cmd, "", strlen(""));
            GcodeCmd resonance = GCODE_CMD__INIT;
            resonance.has_cmdstr = 1;
            resonance.cmdstr.data = (uint8_t*)cmd;
            resonance.cmdstr.len = strlen(cmd);
            GET_MESSAGE_BUFF(buff);
            size_t len = gcode_cmd__pack(&resonance, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_SET_RESONANCE_TEST_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
    }
    // 设置进料
    if (control->loadmaterial)
    {
        CrLogI("app set load material");
        GET_MESSAGE_BUFF(buff);
        size_t len = load_quit_material__pack(control->loadmaterial, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_SET_LOAD_MATERIAL_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置退料
    if (control->quitmaterial)
    {
        CrLogI("app set quit material");
        GET_MESSAGE_BUFF(buff);
        size_t len = load_quit_material__pack(control->quitmaterial, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_SET_QUIT_MATERIAL_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    //  打印速度模式
    if (control->has_speedmode)
    {
        CrLogI("app set speedmode test = %d", control->speedmode);
        
        char cmd[16] = {0};
        if(control->speedmode == 0){
            snprintf(cmd, 16, "Qmode_exit");
        }else if(control->speedmode == 1){
            snprintf(cmd, 16, "Qmode");
        }
        GcodeCmd quietmode = GCODE_CMD__INIT;
        quietmode.has_cmdstr = 1;
        quietmode.cmdstr.data = (uint8_t*)cmd;
        quietmode.cmdstr.len = strlen(cmd);

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&quietmode, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_SET_QUIET_MODE_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 清除错误码
    if (control->has_clearfaultcode)
    {
        CrLogI("app clear fault code = %d", control->clearfaultcode);
        FaultCode_t info = {0}; 
        UpdataFaultCode(info);

        // 应答
        AppControlPrint result = APP_CONTROL_PRINT__INIT;
        result.has_clearfaultcode = 1;
        GET_MESSAGE_BUFF(buff);
        size_t resLen = app_control_print__pack(&result, buff);
        CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_CONTROL_PRINT_ANS, buff, resLen);
        SendProcessMsgBuff(&resSend, resSize);
    }

    app_control_print__free_unpacked(control, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserAppGetDelayImagePreferReq(MsgHeadBuf_t *head)
{
    // 获取摄像头设置
    DelayImagePrefer pre = DELAY_IMAGE_PREFER__INIT;
    GetDelayImagePrefer(&pre);

    GET_MESSAGE_BUFF(buff);
    size_t len = delay_image_prefer__pack(&pre, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_GET_DELAY_IMAGE_PRE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserAppGetPowerLossPreferReq(MsgHeadBuf_t *head)
{
    // 获取断电续打设置
    PowerLossPrefer pre = POWER_LOSS_PREFER__INIT;
    GetPowerLossPrefer(&pre);

    GET_MESSAGE_BUFF(buff);
    size_t len = power_loss_prefer__pack(&pre, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_GET_POWER_LOSS_PRE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserAppGetAiControlPreferReq(MsgHeadBuf_t *head)
{
    // 获取AI控制设置
    AiControlPrefer pre = AI_CONTROL_PREFER__INIT;
    GetAiControlPrefer(&pre);

    GET_MESSAGE_BUFF(buff);
    size_t len = ai_control_prefer__pack(&pre, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_GET_AI_CONTROL_PRE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerSyncUpgradeRebootInfo(MsgHeadBuf_t *head)
{
    UpgradeRebootSync *info = upgrade_reboot_sync__unpack(NULL, head->bufLen, head->buf);
    if (!info) {
        CrLogW("unpack failed\n");
        return;
    }

    // 记录信息
    upgradeInfo.state = info->state;
    memcpy(upgradeInfo.oldVer, info->oldversion.data, info->oldversion.len);

    upgrade_reboot_sync__free_unpacked(info, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerSyncPrintObjectInfo(MsgHeadBuf_t *head)
{
    CrLogI("sync print object info");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_GET_PRINT_OBJECT_ANS, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserAppGetWifiInfoReq(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_WIFI_USER_GET_WIFI_INFO_REQ, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_WIFI_MANAGER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserAppFileControlReq(MsgHeadBuf_t *head)
{
    FileControl *control = file_control__unpack(NULL, head->bufLen, head->buf);
    if (!control) {
        CrLogW("unpack failed\n");
        return;
    }
    int cmd = 0;
    char file[DEF_PATH_LEN] = {0};
    char printid[DEF_PATH_LEN] = {0};
    char param1[DEF_PATH_LEN] = {0};
    if(control->has_cmd)
        cmd=control->cmd;
    if(control->has_file)
        strncpy(file,control->file.data,(control->file.len<DEF_PATH_LEN)? control->file.len:(DEF_PATH_LEN-1));
    if(control->has_printid)
        strncpy(printid,control->printid.data,(control->printid.len<DEF_PATH_LEN)? control->printid.len:(DEF_PATH_LEN-1));
    if(control->has_param1)
        strncpy(param1,control->param1.data,(control->param1.len<DEF_PATH_LEN)? control->param1.len:(DEF_PATH_LEN-1));
    int ret = ModifyDelayImageInfo(cmd,file,printid,param1);

    GeneralRes res = GENERAL_RES__INIT;
    res.result = ret;
    GET_MESSAGE_BUFF(buf);
    size_t len = general_res__pack(&res, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_LOCAL_VIDEO_RESULT, buf, len);
    SendProcessMsgBuff(&send, size);

    file_control__free_unpacked(control, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserReportAutoLevelResult(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_SYNC_AUTO_LEVEL_RESULT, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserReportResonanceResult(MsgHeadBuf_t *head)
{
    GcodeCmdRes *resonanceResult = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!resonanceResult) {
        CrLogW("unpack failed\n");
        return;
    }
    CrLogI("Print  result = %d", resonanceResult->result);
    // 响应
    GeneralRes res = GENERAL_RES__INIT;
    res.result = resonanceResult->result;
    GET_MESSAGE_BUFF(buf);
    size_t len = general_res__pack(&res, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_SYNC_RESONANCE_RESULT, buf, len);
    SendProcessMsgBuff(&send, size);

    gcode_cmd_res__free_unpacked(resonanceResult, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetWifiInfoAns(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_GET_WIFI_INFO_ANS, head->buf, head->bufLen);
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
            case SERVER_CMD_APP_SYNC_UPGRADE_STATE: AppSyncUpgradeState(&head); break;
            case SERVER_CMD_APP_START_LOCAL_UPGRADE: AppStartLocalUpgrade(&head); break;
            case SERVER_CMD_APP_SYNC_MQTT_CONNECT: AppSyncMqttConnectState(&head); break;
            case SERVER_CMD_APP_SYNC_GCODE_DOWNLOAD: AppSyncGcodeDownloadState(&head); break;
            case SERVER_CMD_APP_SYNC_EXPORT_LOG_STATE: AppSyncExportLogState(&head); break;

            case SERVER_CMD_APP_CONTROL_PRINT_REQ: AppControlPrintRes(&head); break;
            case SERVER_CMD_APP_GET_SYSTEM_CONFIG_REQ: AppGetSystemConfigRes(&head); break;
            case SERVER_CMD_APP_GET_PRINT_SAVE_PARA_REQ: AppGetPrintSaveParaRes(&head); break;
            case SERVER_CMD_APP_GET_UDISK_GCODE_FILE_LIST_REQ: AppGetUDiskGcodeFileListRes(&head); break;
            case SERVER_CMD_APP_GET_GCODE_FILE_LIST_REQ: AppGetGcodeFileListRes(&head); break;
            case SERVER_CMD_APP_GET_CURRENT_LOCAL_REQ: AppGetCurrentLocalRes(&head); break;
            case SERVER_CMD_APP_GET_PRINT_OBJECT_RES: ManagerSyncPrintObjectInfo(&head); break;

            case SERVER_CMD_APP_CHECK_UPGRADE_ANS: AppGetDeviceUpgradeInfoAns(&head); break;
            case SERVER_CMD_APP_START_UPGRADE_ANS: AppStartDeviceUpgradeAns(&head); break;
            case SERVER_CMD_APP_CANCEL_UPGRADE_ANS: AppCancelDeviceUpgradeAns(&head); break;
            case SERVER_CMD_APP_UPLOAD_LOCAL_LOG_ANS: AppUploadLocalLogAns (&head); break;
            case SERVER_CMD_APP_UPLOAD_LOCAL_VIDEO_ANS: AppUploadLocalVideoAns (&head); break;
            case SERVER_CMD_APP_UPDATE_USER_INFO_ANS: AppUpdateUserInfoAns(&head); break;
            case SERVER_CMD_APP_SYSTEM_RESET_ANS: AppSystemResetToIotAns(&head); break;

            case MANAGER_SYNC_SYSTEM_CONFIG: AppGetSystemConfigRes(&head); break;
            case MANAGER_SYNC_PRINT_SAVE_PARA: AppGetPrintSaveParaRes(&head); break;
            case MANAGER_CMD_SYNC_DELAY_IMAGE_CONFIG: UserAppGetDelayImagePreferReq(&head); break;
            case MANAGER_CMD_SYNC_POWER_LOSS_CONFIG: UserAppGetPowerLossPreferReq(&head); break;
            case MANAGER_CMD_SYNC_AI_CONTROL_CONFIG: UserAppGetAiControlPreferReq(&head); break;
            case MANAGER_CMD_SYNC_UPGRADE_REBOOT_INFO: ManagerSyncUpgradeRebootInfo(&head); break;
            case MANAGER_CMD_SYNC_PRINT_OBJECT_INFO: ManagerSyncPrintObjectInfo(&head); break;
            
            case MANAGER_CMD_GCODE_GET_SD_FILE_LIST_ANS: UserGetGcodeFileListAns(&head); break;
            case MANAGER_CMD_GCODE_START_PRINT_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_START_CLOUD_PRINT_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_PAUSE_PRINT_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_RESUME_PRINT_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_STOP_PRINT_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_START_POWER_LOSS_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_CANCEL_POWER_LOSS_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_OPEN_FAN_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_STOP_FAN_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_NOZZLE_TEMP_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_BED_TEMP_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_GET_HOTEND_XYZ_LOCAL_ANS: UserGetHotendXyzLocalAns(&head); break;
            case MANAGER_CMD_GCODE_RETURN_HOME_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_HOTEND_XYZ_MOVE_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_PRINT_SPEED_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_PRINT_FLOW_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_GCODE_MACRO_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_LOAD_MATERIAL_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_QUIT_MATERIAL_ANS: UserAppControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_QUIET_MODE_ANS:UserAppControlPrintAns(&head); break;
            
            case MANAGER_CMD_GET_UPGRADE_INFO_REQ: AppGetDeviceUpgradeInfoRes(&head); break;
            case MANAGER_CMD_START_UPGRADE_REQ: AppStartDeviceUpgradeRes(&head); break;
            case MANAGER_CMD_CANCEL_UPGRADE_REQ: AppCancelDeviceUpgradeRes(&head); break;
            case MANAGER_CMD_UPLOAD_LOCAL_VIDEO_REQ: AppUploadLocalVideoRes(&head); break;
            case MANAGER_CMD_UPLOAD_LOCAL_LOG_REQ: AppUploadLocalLogRes(&head); break;
            case MANAGER_CMD_UPDATE_USER_CXY_INFO_REQ: AppUpdateUserCxyInfoRes(&head); break;
            case MANAGER_CMD_SYSTEM_RESET_TO_APP_REQ: AppSystemResetToIotRes(&head); break;

            case SERVER_CMD_APP_TEST_ANS: ServerMessageTestAns(&head); break;
            case MANAGER_CMD_MESSAGE_TEST: ManagerMessageTest(&head); break;
            case MANAGER_DEVICE_STATE_CHANGE: ManagerDeviceStateChange(&head); break;
            case MANAGER_CMD_UPLOAD_DELAY_IMAGE: ManagerUploadDelayImage(&head); break;
            case MANAGER_SYNC_DEV_UPGRADE_STATE: ManagerSyncUpgradeState(&head); break;
            case MANAGER_SYNC_PRINT_WORK_INFO: ManagerSyncPrintWorkInfo(&head); break;
            case MANAGER_CMD_REPORT_AUTO_LEVEL_RESULT: UserReportAutoLevelResult(&head); break;
            case MANAGER_CMD_GCODE_SET_RESONANCE_TEST_ANS:UserReportResonanceResult(&head); break;
            case MANAGER_CMD_WIFI_USER_GET_WIFI_INFO_ANS: UserGetWifiInfoAns(&head); break;

            case SERVER_CMD_APP_GET_DEVICE_STATE_REQ: ManagerDeviceStateChange(&head); break;

            case SERVER_CMD_APP_GET_DELAY_IMAGE_PRE_REQ: UserAppGetDelayImagePreferReq(&head); break;
            case SERVER_CMD_APP_GET_POWER_LOSS_PRE_REQ: UserAppGetPowerLossPreferReq(&head); break;
            case SERVER_CMD_APP_GET_AI_CONTROL_PRE_REQ: UserAppGetAiControlPreferReq(&head); break;
            case SERVER_CMD_APP_GET_WIFI_INFO_REQ: UserAppGetWifiInfoReq(&head); break;
            case SERVER_CMD_APP_CONTROL_LOCAL_VIDEO:UserAppFileControlReq(&head); break;
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
MsgHandle_t *AppManagerInit(void *arg)
{
    CrLogI("app manager init");
    
    // 创建DUP调试线程
    CreateUdpTestServerThread();

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
int AppManagerExceptionHandleSemPost(void)
{
    return 0;
}
