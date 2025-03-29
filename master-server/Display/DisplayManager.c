/*
 * @Description : 显示设备管理器
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-01 17:42:14
 * @LastEditTime: 2023-11-01 14:59:38
 */

#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

#include "Base/MasterMsgBase.h"
#include "DisplayManager.h"

/**
 * @description: 静态变量声明
 * @param  {*}
 * @return {*}
 */
static MsgHandle_t msgHandle;
static int managerMsgId = -1;
static int serverMsgId = -1;
static UpgradeRebootInfo_t upgradeInfo = {0};

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
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DisSyncExportLogState(MsgHeadBuf_t *head)
{
    ExportLogState *sync = export_log_state__unpack(NULL, head->bufLen, head->buf);
    if (!sync) {
        CrLogW("unpack failed\n");
        return;
    }

    int deviceState = GetPrintState().deviceState;
    CrLogI("export log, state = %d, progress = %d, deviceState = %d\n", sync->state, sync->progress, deviceState);

    if (sync->state == COMPRESSING_LOG)
        UpdataDeviceState(DEVICE_STATE_COMPRESSING_LOG);
    else if (sync->state == EXPORTING_LOGS)
        UpdataDeviceState(DEVICE_STATE_EXPORT_LOG);
    else if (deviceState == DEVICE_STATE_COMPRESSING_LOG || deviceState == DEVICE_STATE_EXPORT_LOG)
        UpdataDeviceState(DEVICE_STATE_IDLE);
    
    // 失败进度置-1
    if (sync->state == EXPORT_LOG_FAIL) UpdataLogProgress(-1);
    else UpdataLogProgress(sync->progress);

    export_log_state__free_unpacked(sync, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void DisGetSystemConfigRes(MsgHeadBuf_t *head)
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
    sendConfig.has_time_zone = 1;
    sendConfig.time_zone.data = (uint8_t*)config.time_zone;
    sendConfig.time_zone.len = strlen(config.time_zone);
    sendConfig.has_server_config = 1;
    sendConfig.server_config = config.server_config;
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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_SYSTEM_CONFIG_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void DisGetPrintSaveParaRes(MsgHeadBuf_t *head)
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

    sendPara.n_levelvalue = printSavePara.levelValue.size;
    sendPara.levelvalue = printSavePara.levelValue.value;

    sendPara.n_gcodemacro = printSavePara.gcodeMacro.size;
    ProtobufCBinaryData gcodeMacroBuf[sendPara.n_gcodemacro];
    memset(gcodeMacroBuf, 0, sizeof(ProtobufCBinaryData) * sendPara.n_gcodemacro);
    for (int i = 0; i < sendPara.n_gcodemacro; i++) {
        gcodeMacroBuf[i].data = (uint8_t*)printSavePara.gcodeMacro.value[i];
        gcodeMacroBuf[i].len = strlen(printSavePara.gcodeMacro.value[i]);
    }
    sendPara.gcodemacro = gcodeMacroBuf;

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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_PRINT_SAVE_PARA_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void DisGetDeviceStateRes(MsgHeadBuf_t *head)
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
    syncState.pausestatus = curState.pauseStatus;
    syncState.n_materialstatus = MATERIAL_DETECTOR_SIZE;
    syncState.materialstatus = curState.materialStatus;
    syncState.printspeed = curState.printSpeed;
    syncState.printflow = curState.printFlow;
    syncState.realtimespeed = curState.realTimeSpeed;
    syncState.realtimeflow = curState.realTimeFlow;
    syncState.curprintlayer = curState.printLayer;
    syncState.printtotallayer = curState.printLayers;
    syncState.printprogress = curState.printProgress;
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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_DEVICE_STATE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DisGetPowerLossInfoRes(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GET_POWER_LOSS_INFO_REQ, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DisGetUpgradeRebootInfoRes(MsgHeadBuf_t *head)
{
    UpgradeRebootSync info = UPGRADE_REBOOT_SYNC__INIT;
    info.state = upgradeInfo.state;
    info.oldversion.data = (uint8_t*)upgradeInfo.oldVer;
    info.oldversion.len = strlen(upgradeInfo.oldVer);
    
    GET_MESSAGE_BUFF(buff);
    size_t len = upgrade_reboot_sync__pack(&info, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_UPGRADE_REBOOT_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    // 清空记录信息
    bzero(&upgradeInfo, sizeof(UpgradeRebootInfo_t));
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserPrintFinishAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *finish = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!finish) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Print Finish result = %d", finish->result);

    gcode_cmd_res__free_unpacked(finish, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerSyncUpgradeState(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_SYNC_UPGRADE_STATE, head->buf, head->bufLen);
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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_PRINT_WORK_INFO_ANS, buf, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerSyncFileCopyProgress(MsgHeadBuf_t *head)
{
    GcodeCmdRes *progress = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!progress) {
        CrLogW("unpack failed\n");
        return;
    }
    SendString progressString = SEND_STRING__INIT;
    progressString.str.data = progress->resstr.data;
    progressString.str.len = progress->resstr.len;

    GET_MESSAGE_BUFF(buff);
    size_t len = send_string__pack(&progressString, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_SYNC_FILE_COPY_PROGRESS, buff, len);
    SendProcessMsgBuff(&send, size);

    gcode_cmd_res__free_unpacked(progress, NULL);
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
    CrLogI("state = %d, oldVer = %s\n", upgradeInfo.state, upgradeInfo.oldVer);

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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_PRINT_OBJECT_ANS, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserAbsolutePositioningAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *positioning = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!positioning) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("set Absolute Positioning result = %d", positioning->result);

    gcode_cmd_res__free_unpacked(positioning, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserRelativePositioningAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *positioning = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!positioning) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("set Relative Positioning result = %d", positioning->result);

    gcode_cmd_res__free_unpacked(positioning, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetSdCardFileAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *file = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!file) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("get gcode file result = %d", file->result);
    LocalGcodeInfo fileSum = LOCAL_GCODE_INFO__INIT;

    fileSum.has_result = 1;
    fileSum.result = file->result;
    if (file->result)
    {
        CrLogD("get sd gcode file num = %d", *file->resstr.data);
        fileSum.has_sum = 1;
        fileSum.sum = *file->resstr.data;
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = local_gcode_info__pack(&fileSum, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_LOCAL_GCODE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    gcode_cmd_res__free_unpacked(file, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetSdGcodeImageAns(MsgHeadBuf_t *head)
{
    ControlRange *image = control_range__unpack(NULL, head->bufLen, head->buf);
    if (!image) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Get SdGcode Image result = %d", image->result);
    LocalGcodeInfo fileImage = LOCAL_GCODE_INFO__INIT;

    fileImage.has_result = 1;
    fileImage.result = image->result;
    if (image->result)
    {
        CrLogI("file id range start = %d, end = %d", image->start, image->end);
        fileImage.has_optstart = 1;
        fileImage.optstart = image->start;
        fileImage.has_optend = 1;
        fileImage.optend = image->end;
        fileImage.has_cachepath = 1;

        char *cachePath = GetUserGcodeFileInfoFilePath();
        fileImage.cachepath.data = (uint8_t*)cachePath;
        fileImage.cachepath.len = strlen(cachePath);
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = local_gcode_info__pack(&fileImage, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_LOCAL_IMAGE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    control_range__free_unpacked(image, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetSdGcodePhotoAns(MsgHeadBuf_t *head)
{
    GcodePhotoInfoRes *res = gcode_photo_info_res__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Get SdGcode Photo result = %d", res->result);
    LocalGcodeInfo photo = LOCAL_GCODE_INFO__INIT;

    photo.has_result = 1;
    photo.result = res->result;
    if (res->result)
    {
        photo.has_startpixel = 1;
        photo.startpixel = res->start_pixel;
        photo.has_endpixel = 1;
        photo.endpixel = res->end_pixel;
        photo.has_modelheight = 1;
        photo.modelheight = res->model_height;
        photo.has_layerheight = 1;
        photo.layerheight = res->layer_height;
        photo.has_photopath = 1;
        photo.photopath.data = res->path.data;
        photo.photopath.len = res->path.len;
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = local_gcode_info__pack(&photo, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_LOCAL_PHOTO_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    gcode_photo_info_res__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
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

        AxisPositionInfo location = AXIS_POSITION_INFO__INIT;
        location.x = local->x;
        location.y = local->y;
        location.z = local->z;
        location.e = local->e;

        GET_MESSAGE_BUFF(buff);
        size_t len = axis_position_info__pack(&location, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_LOCALTION_ANS, buff, len);
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
static void UserGetWifiInfoAns(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_WIFI_INFO_ANS, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetWifiScanListAns(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_WIFI_SCAN_ANS, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetUpgradeInfoAns(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_UPGRADE_INFO_ANS, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetUserCxyInfoAns(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_USER_CXY_INFO_ANS, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetSystemResetAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *res = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Set System Reset result = %d", res->result);
    DisControlPrint result = DIS_CONTROL_PRINT__INIT;
    result.has_result = 1;
    result.result = res->result;
    result.has_systemreset = 1;

    GET_MESSAGE_BUFF(buff);
    size_t resLen = dis_control_print__pack(&result, buff);
    CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_CONTROL_PRINT_ANS, buff, resLen);
    SendProcessMsgBuff(&resSend, resSize);

    gcode_cmd_res__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisControlPrintAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *res = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Control Print result = %d", res->result);
    DisControlPrint result = DIS_CONTROL_PRINT__INIT;
    result.has_result = 1;
    result.result = res->result;

    // 解析显示控制指令应答
    MutableTypeData startPrint = MUTABLE_TYPE_DATA__INIT;
    Extruder extruder = EXTRUDER__INIT;
    HeaterBed heaterBed = HEATER_BED__INIT;
    MultiFan multiFan = MULTI_FAN__INIT;
    LoadQuitMaterial loadMaterial = LOAD_QUIT_MATERIAL__INIT;
    LoadQuitMaterial quitMaterial = LOAD_QUIT_MATERIAL__INIT;
    NetworksInfo wifiInfo = NETWORKS_INFO__INIT;
    UpgradeInfoList upgrade = UPGRADE_INFO_LIST__INIT;
    MutableTypeData excludeobject = MUTABLE_TYPE_DATA__INIT;
    MutableTypeData bedMeshInfo = MUTABLE_TYPE_DATA__INIT;

    switch (head->cmd)
    {
        case MANAGER_CMD_GCODE_START_PRINT_ANS: result.print = &startPrint; break;
        case MANAGER_CMD_GCODE_PAUSE_PRINT_ANS: result.has_printctr = 1; break;
        case MANAGER_CMD_GCODE_RESUME_PRINT_ANS: result.has_printctr = 1; break;
        case MANAGER_CMD_GCODE_STOP_PRINT_ANS: result.has_printctr = 1; break;
        case MANAGER_CMD_START_POWER_LOSS_ANS: result.has_printctr = 1; break;
        case MANAGER_CMD_CANCEL_POWER_LOSS_ANS: result.has_printctr = 1; break;
        case MANAGER_CMD_GCODE_SET_MATERIAL_DELECT_ANS: result.has_materialdelect = 1; break;
        case MANAGER_CMD_GCODE_SET_POWER_LOSS_SW_ANS: result.has_powerlosssw = 1; break;

        case MANAGER_CMD_GCODE_RETURN_HOME_ANS: result.has_returnhome = 1; break;
        case MANAGER_CMD_GCODE_HOTEND_XYZ_MOVE_ANS:result.has_axismove = 1; break;
        case MANAGER_CMD_GCODE_SET_AXIS_RECOUP_ANS: result.has_axisrecoup = 1; break;
        case MANAGER_CMD_GCODE_SET_HOME_OFFSET_ANS: result.has_axisoffset = 1; break;
        case MANAGER_CMD_GCODE_SET_MOTOR_LOCK_ANS: result.has_motorlock = 1; break;
        case MANAGER_CMD_GCODE_SET_MOTOR_UNLOCK_ANS: result.has_motorlock = 1; break;
        case MANAGER_CMD_GCODE_SET_NOZZLE_TEMP_ANS: result.nozzletemp = &extruder; break;
        case MANAGER_CMD_GCODE_SET_BED_TEMP_ANS: result.bedtemp = &heaterBed; break;
        case MANAGER_CMD_GCODE_OPEN_FAN_ANS: result.fancontrol = &multiFan; break;
        case MANAGER_CMD_GCODE_STOP_FAN_ANS: result.fancontrol = &multiFan; break;
        case MANAGER_CMD_GCODE_STOP_ALL_HEAT_ANS: result.has_stopallheating = 1; break;
        case MANAGER_CMD_GCODE_DEVICE_AUTO_LEVEL_ANS: result.has_autolevel = 1; break;
        case MANAGER_CMD_GCODE_SET_AUTO_LEVEL_POINTS_ANS: result.has_autolevelpoints = 1; break;
        case MANAGER_CMD_GCODE_SET_HOTEND_PID_ANS: result.has_hotendpid = 1; break;
        case MANAGER_CMD_GCODE_SET_BED_PID_ANS: result.has_bedpid = 1; break;

        case MANAGER_CMD_GCODE_SET_STEP_VALUE_ANS: result.has_stepvalue = 1; break;
        case MANAGER_CMD_GCODE_SET_MAX_ACCELERATION_ANS: result.has_acceleration = 1; break;
        case MANAGER_CMD_GCODE_SET_MAX_SPEED_ANS: result.has_maxspeed = 1; break;
        case MANAGER_CMD_GCODE_SET_MAX_JERK_ANS: result.has_maxjerk = 1; break;
        case MANAGER_CMD_GCODE_SET_MAX_CORNER_ANS: result.has_maxcorner = 1; break;
        case MANAGER_CMD_GCODE_SET_PRESSURE_ADVANCE_ANS: result.has_pressureadvance = 1; break;
        case MANAGER_CMD_GCODE_SET_SMOOTH_TIME_ANS: result.has_smoothtime = 1; break;
        case MANAGER_CMD_GCODE_SET_SAVE_CONFIG_ANS: result.has_savepara = 1; break;
        
        case MANAGER_CMD_GCODE_SET_INSERT_FILAMENT_ANS: result.has_insertfilament = 1; break;
        case MANAGER_CMD_GCODE_SET_GCODE_MACRO_ANS: result.has_gcodemacro = 1; break;
        case MANAGER_CMD_GCODE_SET_CONSOLE_CTL_ANS: {
            result.has_consolectl = 1;
            result.consolectl.data = res->resstr.data;
            result.consolectl.len = res->resstr.len;
            break;
        }
        case MANAGER_CMD_GCODE_SET_RESTART_KLIPPER_ANS: result.has_restartklipper = 1; break;
        case MANAGER_CMD_GCODE_SET_FIRMWARE_RESTART_ANS: result.has_firmwarerestart = 1; break;
        case MANAGER_CMD_GCODE_SET_PRINT_SPEED_ANS: result.has_speedmultiple = 1; break;
        case MANAGER_CMD_GCODE_SET_PRINT_FLOW_ANS: result.has_flowmultiple = 1; break;
        case MANAGER_CMD_GCODE_SET_CR_TOUCH_ANS: result.has_setcrtouch = 1; break;
        case MANAGER_CMD_GCODE_SET_RESONANCE_TEST_ANS: result.has_resonancetest = 1; break;
        case MANAGER_CMD_GCODE_SET_QUIET_MODE_ANS: result.has_quietmode = 1; break;
        case MANAGER_CMD_GCODE_SET_LOAD_MATERIAL_ANS: result.loadmaterial = &loadMaterial; break;
        case MANAGER_CMD_GCODE_SET_QUIT_MATERIAL_ANS: result.quitmaterial = &quitMaterial; break;
        case MANAGER_CMD_GCODE_SET_LASER_CALIBRATION_ANS: result.has_lasercalibration = 1; break;
        case MANAGER_CMD_GCODE_SET_EXCLUDE_OBJECT_ANS: result.excludeobject = &excludeobject; break;
        case MANAGER_CMD_GCODE_SET_MESH_INFO_ANS: result.bedmeshinfo = &bedMeshInfo; break;

        case MANAGER_CMD_START_MATERIAL_WARM_UP_ANS: result.has_startwarmup = 1; break;
        case MANAGER_CMD_START_TEMP_AUTO_PID_ANS: result.has_startautopid = 1; break;
        case MANAGER_CMD_START_UPGRADE_ANS: result.startupgrade = &upgrade; break;
        case MANAGER_CMD_CANCEL_UPGRADE_ANS: result.cancelupgrade = &upgrade; break;
        case MANAGER_CMD_UPLOAD_LOCAL_VIDEO_ANS: result.has_uploadlocalvideo = 1; break;

        case MANAGER_CMD_WIFI_USER_CONNECT_NETWORK_ANS: result.connectwifi = &wifiInfo; break;
        case MANAGER_CMD_WIFI_USER_CONNECT_SAVE_NETWORK_ANS: result.connectsavewifi = &wifiInfo; break;
        case MANAGER_CMD_WIFI_USER_DISCONNECT_NETWORK_ANS: result.disconnectwifi = &wifiInfo; break;
        case MANAGER_CMD_WIFI_USER_REMOVE_NETWORK_ANS: result.removewifi = &wifiInfo; break;

        default: {
            CrLogW("msg cmd file !!! origin %d, cmd %d\n", head->origin, head->cmd);
            break;
        }
    }

    GET_MESSAGE_BUFF(buff);
    size_t resLen = dis_control_print__pack(&result, buff);
    CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_CONTROL_PRINT_ANS, buff, resLen);
    SendProcessMsgBuff(&resSend, resSize);

    gcode_cmd_res__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetLocalGcodeReq(MsgHeadBuf_t *head)
{
    GetGcodeFIleList *cmd = get_gcode_file_list__unpack(NULL, head->bufLen, head->buf);
    if (!cmd) {
        CrLogW("unpack failed\n");
        return;
    }

    // 判断文件路径是否存在
    CrLogI("traverse sort = %d, path = %s", cmd->sort, cmd->path.data);
    if (cmd->path.len <= 3) {
        CrLogW("traverse path fail\n");
        LocalGcodeInfo fileSum = LOCAL_GCODE_INFO__INIT;
        fileSum.has_result = 1;
        fileSum.result = 0;

        GET_MESSAGE_BUFF(buff);
        size_t len = local_gcode_info__pack(&fileSum, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_LOCAL_GCODE_ANS, buff, len);
        SendProcessMsgBuff(&send, size);
    }
    else {
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_GET_SD_FILE_REQ, head->buf, head->bufLen);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

    get_gcode_file_list__free_unpacked(cmd, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetLocalImageReq(MsgHeadBuf_t *head)
{
    LocalGcodeInfo *info = local_gcode_info__unpack(NULL, head->bufLen, head->buf);
    if (!info) {
        CrLogW("unpack failed\n");
        return;
    }

    ControlRange image = CONTROL_RANGE__INIT;
    image.has_start = 1;
    image.start = info->optstart;
    image.has_end = 1;
    image.end = info->optend;

    GET_MESSAGE_BUFF(buff);
    size_t len = control_range__pack(&image, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_GET_SD_MODEL_IMAGE_REQ, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);

    local_gcode_info__free_unpacked(info, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetLocalPhotoReq(MsgHeadBuf_t *head)
{
    SendString *info = send_string__unpack(NULL, head->bufLen, head->buf);
    if (!info) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("choose print file = %s", info->str.data);
    // 发送命令
    GcodeCmd photo = GCODE_CMD__INIT;
    photo.has_cmdstr = 1;
    photo.cmdstr.data = info->str.data;
    photo.cmdstr.len = info->str.len;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd__pack(&photo, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_GET_SD_GCODE_PHOTO_REQ, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);

    send_string__free_unpacked(info, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetLocaltionReq(MsgHeadBuf_t *head)
{
    GcodeCmd local = GCODE_CMD__INIT;
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd__pack(&local, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_GET_HOTEND_XYZ_LOCAL_REQ, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetMaterialPreferReq(MsgHeadBuf_t *head)
{
    MaterialPreferList *list = material_prefer_list__unpack(NULL, head->bufLen, head->buf);
    if (!list) {
        CrLogW("unpack failed\n");
        return;
    }

    // 获取保存值
    MaterialPreferList getList = MATERIAL_PREFER_LIST__INIT;
    GetMaterialPrefer(list, &getList);

    GET_MESSAGE_BUFF(buff);
    size_t len = material_prefer_list__pack(&getList, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_MATERIAL_PRE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    // 释放资源
    GetMaterialPreferFree(&getList);
    material_prefer_list__free_unpacked(list, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetAutoPidPreferReq(MsgHeadBuf_t *head)
{
    TempAutoPidPreferList *list = temp_auto_pid_prefer_list__unpack(NULL, head->bufLen, head->buf);
    if (!list) {
        CrLogW("unpack failed\n");
        return;
    }

    // 获取保存值
    TempAutoPidPreferList getList = TEMP_AUTO_PID_PREFER_LIST__INIT;
    GetTempAutoPidPrefer(list, &getList);

    GET_MESSAGE_BUFF(buff);
    size_t len = temp_auto_pid_prefer_list__pack(&getList, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_AUTO_PID_PRE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    // 释放资源
    GetTempAutoPidPreferFree(&getList);
    temp_auto_pid_prefer_list__free_unpacked(list, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetDelayImagePreferReq(MsgHeadBuf_t *head)
{
    // 获取摄像头设置
    DelayImagePrefer pre = DELAY_IMAGE_PREFER__INIT;
    GetDelayImagePrefer(&pre);

    GET_MESSAGE_BUFF(buff);
    size_t len = delay_image_prefer__pack(&pre, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_DELAY_IMAGE_PRE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetPowerLossPreferReq(MsgHeadBuf_t *head)
{
    // 获取摄像头设置
    PowerLossPrefer pre = POWER_LOSS_PREFER__INIT;
    GetPowerLossPrefer(&pre);

    GET_MESSAGE_BUFF(buff);
    size_t len = power_loss_prefer__pack(&pre, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_POWER_LOSS_PRE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetAiControlPreferReq(MsgHeadBuf_t *head)
{
    // 获取AI控制设置
    AiControlPrefer pre = AI_CONTROL_PREFER__INIT;
    GetAiControlPrefer(&pre);

    GET_MESSAGE_BUFF(buff);
    size_t len = ai_control_prefer__pack(&pre, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_AI_CONTROL_PRE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetWifiInfoReq(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_WIFI_USER_GET_WIFI_INFO_REQ, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_WIFI_MANAGER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetWifiScanListReq(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_WIFI_USER_SCAN_WIFI_REQ, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_WIFI_MANAGER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetUpgradeInfoReq(MsgHeadBuf_t *head)
{
    CrLogI("App Get Device upgrade Info Res");
    UpgradeInfoList *infoList = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!infoList) {
        CrLogW("unpack failed\n");
        return;
    }
    
    // 从云端查询Linux、mcu升级固件
    if (infoList->linuxota || infoList->mcu1ota) {
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GET_UPGRADE_INFO_REQ, head->buf, head->bufLen);
        MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    }
    // 从本地查询Linux、mcu升级固件
    if (infoList->linuxlocal || infoList->mcu1local) {
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GET_UPGRADE_INFO_REQ, head->buf, head->bufLen);
        MANAGER_MSG_SEND(MSG_ORIGIN_UPGRADE_MANAGER, &send, size);
    }

    upgrade_info_list__free_unpacked(infoList, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetUserCxyInfoReq(MsgHeadBuf_t *head)
{
    CrLogI("User Dis Get User Cxy Info Req");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_UPDATE_USER_CXY_INFO_REQ, "", 0);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisGetGsensorExistReq(MsgHeadBuf_t *head)
{
    CrLogI("User Dis Get Gsensor Exist Req");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GET_GSENSOR_EXIST_REQ, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisControlPrintReq(MsgHeadBuf_t *head)
{
    DisControlPrint *disControl = dis_control_print__unpack(NULL, head->bufLen, head->buf);
    if (!disControl) {
        CrLogW("unpack failed\n");
        return;
    }
    // 设置喷嘴目标温度
    if (disControl->nozzletemp)
    {
        CrLogI("dis set nozzle temp");
        GET_MESSAGE_BUFF(buff);
        size_t len = extruder__pack(disControl->nozzletemp, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_NOZZLE_TEMP_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置热床目标温度
    if (disControl->bedtemp)
    {
        CrLogI("dis set bed temp");
        GET_MESSAGE_BUFF(buff);
        size_t len = heater_bed__pack(disControl->bedtemp, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_BED_TEMP_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置打印倍速
    if (disControl->has_speedmultiple)
    {
        CrLogI("dis set speed multiple = %s", disControl->speedmultiple.data);
        GcodeCmd speed = GCODE_CMD__INIT;
        speed.has_cmdstr = 1;
        speed.cmdstr.data = disControl->speedmultiple.data;
        speed.cmdstr.len = disControl->speedmultiple.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&speed, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_PRINT_SPEED_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置打印流量
    if (disControl->has_flowmultiple)
    {
        CrLogI("dis set flow multiple = %s", disControl->flowmultiple.data);
        GcodeCmd flow = GCODE_CMD__INIT;
        flow.has_cmdstr = 1;
        flow.cmdstr.data = disControl->flowmultiple.data;
        flow.cmdstr.len = disControl->flowmultiple.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&flow, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_PRINT_FLOW_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置轴补偿值（X\Y\Z）
    if (disControl->has_axisrecoup)
    {
        CrLogI("dis set axis recoup = %s", disControl->axisrecoup.data);
        GcodeCmd offset = GCODE_CMD__INIT;
        offset.has_cmdstr = 1;
        offset.cmdstr.data = disControl->axisrecoup.data;
        offset.cmdstr.len = disControl->axisrecoup.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&offset, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_AXIS_RECOUP_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置文件id，开始打印
    if (disControl->print)
    {
        CrLogI("dis set start print");
        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(disControl->print, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_START_PRINT_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 打印控制（暂停、恢复、停止）
    if (disControl->has_printctr)
    {
        CrLogI("dis set print control = %d", disControl->printctr);
        GcodeCmd control = GCODE_CMD__INIT;
        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&control, buff);

        switch (disControl->printctr)
        {
            case 1: {
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_STOP_PRINT_REQ, buff, len);
                MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
                break;
            }
            case 2: {
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_PAUSE_PRINT_REQ, buff, len);
                MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
                break;
            }
            case 3: {
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_RESUME_PRINT_REQ, buff, len);
                MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
                break;
            }
            case 4: {
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_POWER_LOSS_REQ, buff, len);
                MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
                break;
            }
            case 5: {
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_CANCEL_POWER_LOSS_REQ, buff, len);
                MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
                break;
            }
        }
    } 
    // 回原点
    if (disControl->has_returnhome)
    {
        CrLogI("dis set return home = %s", disControl->returnhome.data);
        GcodeCmd move = GCODE_CMD__INIT;
        move.has_cmdstr = 1;
        move.cmdstr.data = disControl->returnhome.data;
        move.cmdstr.len = disControl->returnhome.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&move, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_RETURN_HOME_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 轴移动
    if (disControl->has_axismove)
    {
        CrLogI("dis set axis move = %s", disControl->axismove.data);
        char moveCmd[256] = {0};
        snprintf(moveCmd, 256, "SAVE_GCODE_STATE NAME=myMoveState\n G91\n G0 %s\n M400\n RESTORE_GCODE_STATE NAME=myMoveState", disControl->axismove.data);
        GcodeCmd move = GCODE_CMD__INIT;
        move.has_cmdstr = 1;
        move.cmdstr.data = (uint8_t*)moveCmd;
        move.cmdstr.len = strlen(moveCmd);

        GET_MESSAGE_BUFF(buff1);
        size_t len1 = gcode_cmd__pack(&move, buff1);
        CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_HOTEND_XYZ_MOVE_REQ, buff1, len1);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send1, size1);
    }
    // 电机锁定、解锁
    if (disControl->has_motorlock)
    {
        CrLogI("dis set motor lock = %d", disControl->motorlock);
        MutableTypeData lock = MUTABLE_TYPE_DATA__INIT;
        lock.has_int_v = 1;
        lock.int_v = disControl->motorlock;

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&lock, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_MOTOR_UNLOCK_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 风扇控制
    if (disControl->fancontrol)
    {
        CrLogI("dis set fan control");
        GET_MESSAGE_BUFF(buff);
        size_t len = multi_fan__pack(disControl->fancontrol, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_OPEN_FAN_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 停止所有加热
    if (disControl->has_stopallheating)
    {
        CrLogI("dis set stop all heating");
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_STOP_ALL_HEAT_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置断料检测
    if (disControl->has_materialdelect)
    {
        CrLogI("dis set material delect = %s", disControl->materialdelect.data);
        GcodeCmd delect = GCODE_CMD__INIT;
        delect.has_cmdstr = 1;
        delect.cmdstr.data = disControl->materialdelect.data;
        delect.cmdstr.len = disControl->materialdelect.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&delect, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_MATERIAL_DELECT_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置断电续打
    if (disControl->has_powerlosssw)
    {
        CrLogI("dis set power loss = %s", disControl->powerlosssw.data);
        GcodeCmd sw = GCODE_CMD__INIT;
        sw.has_cmdstr = 1;
        sw.cmdstr.data = disControl->powerlosssw.data;
        sw.cmdstr.len = disControl->powerlosssw.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&sw, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_POWER_LOSS_SW_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置传动比
    if (disControl->has_stepvalue)
    {
        CrLogI("dis set step value = %s", disControl->stepvalue.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = disControl->stepvalue.data;
        max.cmdstr.len = disControl->stepvalue.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_STEP_VALUE_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置最大加速度
    if (disControl->has_acceleration)
    {
        CrLogI("dis set max acceleration = %s", disControl->acceleration.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = disControl->acceleration.data;
        max.cmdstr.len = disControl->acceleration.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_MAX_ACCELERATION_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置最大加速到减速的加速度限制
    if (disControl->has_maxjerk)
    {
        CrLogI("dis set max jerk = %s", disControl->maxjerk.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = disControl->maxjerk.data;
        max.cmdstr.len = disControl->maxjerk.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_MAX_JERK_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置最大速度
    if (disControl->has_maxspeed)
    {
        CrLogI("dis set max speed = %s", disControl->maxspeed.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = disControl->maxspeed.data;
        max.cmdstr.len = disControl->maxspeed.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_MAX_SPEED_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置最大拐角速度
    if (disControl->has_maxcorner)
    {
        CrLogI("dis set max corner = %s", disControl->maxcorner.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = disControl->maxcorner.data;
        max.cmdstr.len = disControl->maxcorner.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_MAX_CORNER_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置压力推进
    if (disControl->has_pressureadvance)
    {
        CrLogI("dis set pressure advance = %s", disControl->pressureadvance.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = disControl->pressureadvance.data;
        max.cmdstr.len = disControl->pressureadvance.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_PRESSURE_ADVANCE_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置平滑时间
    if (disControl->has_smoothtime)
    {
        CrLogI("dis set smooth time = %s", disControl->smoothtime.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = disControl->smoothtime.data;
        max.cmdstr.len = disControl->smoothtime.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_SMOOTH_TIME_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    
    // 设置喷嘴温度PID
    if (disControl->has_hotendpid)
    {
        CrLogI("dis set hotend pid = %s", disControl->hotendpid.data);
        GcodeCmd pid = GCODE_CMD__INIT;
        pid.has_cmdstr = 1;
        pid.cmdstr.data = disControl->hotendpid.data;
        pid.cmdstr.len = disControl->hotendpid.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&pid, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_HOTEND_PID_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置热床温度PID
    if (disControl->has_bedpid)
    {
        CrLogI("dis set bed pid = %s", disControl->bedpid.data);
        GcodeCmd pid = GCODE_CMD__INIT;
        pid.has_cmdstr = 1;
        pid.cmdstr.data = disControl->bedpid.data;
        pid.cmdstr.len = disControl->bedpid.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&pid, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_BED_PID_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置轴偏移
    if (disControl->has_axisoffset)
    {
        CrLogI("dis set axis offset = %s", disControl->axisoffset.data);
        GcodeCmd offset = GCODE_CMD__INIT;
        offset.has_cmdstr = 1;
        offset.cmdstr.data = disControl->axisoffset.data;
        offset.cmdstr.len = disControl->axisoffset.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&offset, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_HOME_OFFSET_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 辅助调平
    if (disControl->has_manuallevel)
    {
        CrLogI("dis set manual level = %s", disControl->manuallevel.data);
        GcodeCmd move = GCODE_CMD__INIT;
        
        // 检测轴没有归位，需要先归零
        PrintState_t curState = GetPrintState();
        if (!curState.homedAxes.x || !curState.homedAxes.y || !curState.homedAxes.z)
        {
            CrLogI("Leveling for the first time after power-on, first return to zero");
            move.has_cmdstr = 1;
            move.cmdstr.data = (uint8_t*)"";
            move.cmdstr.len = 0;
            GET_MESSAGE_BUFF(buff);
            size_t len = gcode_cmd__pack(&move, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_RETURN_HOME_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
        // 点移动
        char moveCmd[256] = {0};
        snprintf(moveCmd, 256, "G0 Z10 F7800\n G0 %s F7800\n G0 Z0 F7800", disControl->manuallevel.data);
        GcodeCmd level = GCODE_CMD__INIT;
        level.has_cmdstr = 1;
        level.cmdstr.data = (uint8_t*)moveCmd;
        level.cmdstr.len = strlen(moveCmd);

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&level, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_HOTEND_XYZ_MOVE_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置自动调平
    if (disControl->has_autolevel)
    {
        CrLogI("dis set auto level, ponits = %d", disControl->autolevel);
        MutableTypeData move = MUTABLE_TYPE_DATA__INIT;
        move.has_int_v = 1;
        move.int_v = disControl->autolevel;

        GET_MESSAGE_BUFF(buff1);
        size_t len1 = mutable_type_data__pack(&move, buff1);
        CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_DEVICE_AUTO_LEVEL_REQ, buff1, len1);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send1, size1);
    }
    // 自动调平点数设置
    if (disControl->has_autolevelpoints)
    {
        CrLogI("dis set auto level points = %s", disControl->autolevelpoints.data);
        GcodeCmd points = GCODE_CMD__INIT;
        points.has_cmdstr = 1;
        points.cmdstr.data = disControl->autolevelpoints.data;
        points.cmdstr.len = disControl->autolevelpoints.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&points, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_AUTO_LEVEL_POINTS_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置CR touch
    if (disControl->has_setcrtouch)
    {
        CrLogI("dis set CR touch = %s", disControl->setcrtouch.data);
        GcodeCmd level = GCODE_CMD__INIT;
        level.has_cmdstr = 1;
        level.cmdstr.data = disControl->setcrtouch.data;
        level.cmdstr.len = disControl->setcrtouch.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&level, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_CR_TOUCH_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 保存参数到（EEPROM）
    if (disControl->has_savepara)
    {
        CrLogI("dis set save para");
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_SAVE_CONFIG_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 更换耗材
    if (disControl->has_insertfilament)
    {
        CrLogI("dis set recover temp");
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_INSERT_FILAMENT_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 执行宏定义
    if (disControl->has_gcodemacro)
    {
        CrLogI("dis run gcode macro = %s", disControl->gcodemacro.data);
        GcodeCmd macro = GCODE_CMD__INIT;
        macro.has_cmdstr = 1;
        macro.cmdstr.data = disControl->gcodemacro.data;
        macro.cmdstr.len = disControl->gcodemacro.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&macro, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_GCODE_MACRO_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 终端控制
    if (disControl->has_consolectl)
    {
        CrLogI("dis console control = %s", disControl->consolectl.data);
        GcodeCmd console = GCODE_CMD__INIT;
        console.has_cmdstr = 1;
        console.cmdstr.data = disControl->consolectl.data;
        console.cmdstr.len = disControl->consolectl.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&console, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_CONSOLE_CTL_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 重启klipper
    if (disControl->has_restartklipper)
    {
        CrLogI("dis set restart klipper");
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_RESTART_KLIPPER_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 重启klipper下位机
    if (disControl->has_firmwarerestart)
    {
        CrLogI("dis set firmware restart");
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_FIRMWARE_RESTART_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 共振补偿测试
    if (disControl->has_resonancetest)
    {
        CrLogI("dis set resonance test = %s", disControl->resonancetest.data);
        GcodeCmd resonance = GCODE_CMD__INIT;
        resonance.has_cmdstr = 1;
        resonance.cmdstr.data = disControl->resonancetest.data;
        resonance.cmdstr.len = disControl->resonancetest.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&resonance, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_RESONANCE_TEST_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置对象排除
    if (disControl->excludeobject)
    {
        CrLogI("dis set exclude object");
        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(disControl->excludeobject, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_EXCLUDE_OBJECT_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置热床调平数据
    if (disControl->bedmeshinfo)
    {
        CrLogI("dis set bed mesh info");
        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(disControl->bedmeshinfo, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_MESH_INFO_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

    // 设置恢复出厂设置
    if (disControl->has_systemreset)
    {
        CrLogI("dis set system reset = %d", disControl->systemreset);
        MutableTypeData reset = MUTABLE_TYPE_DATA__INIT;
        reset.has_int_v = 1;
        reset.int_v = disControl->systemreset;

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&reset, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_SYSTEM_RESET_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置系统设置
    if (disControl->syssetting)
    {
        SystemSetting *setting = disControl->syssetting;
        SystemConfigProto config = SYSTEM_CONFIG_PROTO__INIT;

        if (setting->has_autooff) {
            CrLogI("dis set auto power off = %d", setting->autooff);
            config.has_auto_power_off = 1;
            config.auto_power_off = setting->autooff;
        }
        if (setting->has_selftest) {
            CrLogI("dis set self test = %d", setting->selftest);
            config.has_self_test_sw = 1;
            config.self_test_sw = setting->selftest;

            // 自检完成，喷头移动到指定位置
            if (!setting->selftest) {
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_END_PRINT_POINT_REQ, "", 0);
                MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
            }
        }
        if (setting->has_soundsw) {
            CrLogI("dis set sound sw = %d", setting->soundsw);
            config.has_sound_sw = 1;
            config.sound_sw = setting->soundsw;
        }
        if (setting->has_lightsw) {
            CrLogI("dis set light sw = %d", setting->lightsw);
            config.has_light_sw= 1;
            config.light_sw = setting->lightsw;
        }
        if (setting->has_lightvalue) {
            CrLogI("dis set light value = %d", setting->lightvalue);
            config.has_light_value= 1;
            config.light_value = setting->lightvalue;
        }
        if (setting->has_screensaver) {
            CrLogI("dis set screensaver = %d", setting->screensaver);
            config.has_screensaver = 1;
            config.screensaver = setting->screensaver;
        }
        if (setting->has_thememode) {
            CrLogI("dis set theme mode = %d", setting->thememode);
            config.has_theme_mode = 1;
            config.theme_mode = setting->thememode;
        }
        if (setting->has_language) {
            CrLogI("dis set language = %d", setting->language);
            config.has_language = 1;
            config.language = setting->language;
        }
        if (setting->has_screenvalue) {
            CrLogI("dis set screen value = %d", setting->screenvalue);
            config.has_screen_value = 1;
            config.screen_value = setting->screenvalue;
        }
        if (setting->has_uidirection) {
            CrLogI("dis set ui direction = %d", setting->uidirection);
            config.has_ui_direction= 1;
            config.ui_direction = setting->uidirection;
        }
        if (setting->has_soundsize) {
            CrLogI("dis set sound size = %d", setting->soundsize);
            config.has_sound_size= 1;
            config.sound_size = setting->soundsize;
        }
        if (setting->has_soundeffect) {
            CrLogI("dis set sounde ffect = %d", setting->soundeffect);
            config.has_sounde_ffect= 1;
            config.sounde_ffect = setting->soundeffect;
        }
        if (setting->has_fullscreen) {
            CrLogI("dis set full screen = %d", setting->fullscreen);
            config.has_full_screen= 1;
            config.full_screen = setting->fullscreen;
        }
        if (setting->has_timezone) {
            CrLogI("dis set time zone = %s", setting->timezone.data);
            config.has_time_zone= 1;
            config.time_zone.data = setting->timezone.data;
            config.time_zone.len = setting->timezone.len;
        }
        if (setting->has_serverconfig) {
            CrLogI("dis set server config = %d", setting->serverconfig);
            config.has_server_config = 1;
            config.server_config = setting->serverconfig;
        }
        if (setting->has_upgraderemind) {
            CrLogI("dis set upgrade remind = %d", setting->upgraderemind);
            config.has_upgrade_remind = 1;
            config.upgrade_remind = setting->upgraderemind;
        }
        if (setting->has_serverlocal) {
            CrLogI("dis set server local = %d", setting->serverlocal);
            config.has_server_local = 1;
            config.server_local = setting->serverlocal;
        }
        if (setting->has_agreeprivacy) {
            CrLogI("dis set agree privacy = %d", setting->agreeprivacy);
            config.has_agree_privacy = 1;
            config.agree_privacy = setting->agreeprivacy;
        }
        if (setting->has_hostname) {
            CrLogI("dis set host name = %s", setting->hostname.data);
            config.has_host_name = 1;
            config.host_name.data = setting->hostname.data;
            config.host_name.len = setting->hostname.len;
        }
        if (setting->has_datacollect) {
            CrLogI("dis set data collect = %d", setting->datacollect);
            config.has_data_collect = 1;
            config.data_collect = setting->datacollect;
        }
        int res = UpdataSystemConfig(&config);

        // 应答
        SystemSetting systemSetting = SYSTEM_SETTING__INIT;
        DisControlPrint result = DIS_CONTROL_PRINT__INIT;
        result.has_result = 1;
        result.result = res;
        result.syssetting = &systemSetting;
        
        GET_MESSAGE_BUFF(buff);
        size_t resLen = dis_control_print__pack(&result, buff);
        CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_CONTROL_PRINT_ANS, buff, resLen);
        SendProcessMsgBuff(&resSend, resSize);
    }
    // 开始升级
    if (disControl->startupgrade)
    {
        CrLogI("App Start Device upgrade Res");
        GET_MESSAGE_BUFF(buff);
        size_t len = upgrade_info_list__pack(disControl->startupgrade, buff);

        // 从云端升级Linux、mcu固件
        if (disControl->startupgrade->linuxota || disControl->startupgrade->mcu1ota) {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_UPGRADE_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
        }
        // 从本地升级Linux、mcu固件
        if (disControl->startupgrade->linuxlocal || disControl->startupgrade->mcu1local) {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_UPGRADE_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_UPGRADE_MANAGER, &send, size);
        }
    }
    // 取消升级
    if (disControl->cancelupgrade)
    {
        CrLogI("App cancel Device upgrade Res");
        GET_MESSAGE_BUFF(buff);
        size_t len = upgrade_info_list__pack(disControl->cancelupgrade, buff);

        // 取消从云端升级Linux、mcu固件
        if (disControl->cancelupgrade->linuxota || disControl->cancelupgrade->mcu1ota) {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_CANCEL_UPGRADE_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
        }
    }
    // 清除错误码
    if (disControl->has_clearfaultcode)
    {
        CrLogI("dis clear fault code = %d", disControl->clearfaultcode);
        FaultCode_t info = {0}; 
        UpdataFaultCode(info);

        // 应答
        DisControlPrint result = DIS_CONTROL_PRINT__INIT;
        result.has_clearfaultcode = 1;
        GET_MESSAGE_BUFF(buff);
        size_t resLen = dis_control_print__pack(&result, buff);
        CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_CONTROL_PRINT_ANS, buff, resLen);
        SendProcessMsgBuff(&resSend, resSize);
    }

    // 设置材料预热
    if (disControl->materialpre)
    {
        CrLogI("dis set material prefer");
        int res = SetMaterialPrefer(disControl->materialpre);

        // 应答
        MaterialPrefer pre = MATERIAL_PREFER__INIT;
        DisControlPrint result = DIS_CONTROL_PRINT__INIT;
        result.has_result = 1;
        result.result = res;
        result.materialpre = &pre;
        
        GET_MESSAGE_BUFF(buff);
        size_t resLen = dis_control_print__pack(&result, buff);
        CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_CONTROL_PRINT_ANS, buff, resLen);
        SendProcessMsgBuff(&resSend, resSize);
    }
    // 开始选中材料预热
    if (disControl->has_startwarmup)
    {
        CrLogI("dis set start warm up = %d", disControl->startwarmup);
        MaterialPrefer warmUp = MATERIAL_PREFER__INIT;
        warmUp.id = disControl->startwarmup;

        GET_MESSAGE_BUFF(buff);
        size_t len = material_prefer__pack(&warmUp, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_MATERIAL_WARM_UP_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置自动温度PID
    if (disControl->temppidpre)
    {
        CrLogI("dis set temp pid prefer");
        int res = SetTempAutoPidPrefer(disControl->temppidpre);
        
        // 应答
        TempAutoPidPrefer pid = TEMP_AUTO_PID_PREFER__INIT;
        DisControlPrint result = DIS_CONTROL_PRINT__INIT;
        result.has_result = 1;
        result.result = res;
        result.temppidpre = &pid;
        
        GET_MESSAGE_BUFF(buff);
        size_t resLen = dis_control_print__pack(&result, buff);
        CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_CONTROL_PRINT_ANS, buff, resLen);
        SendProcessMsgBuff(&resSend, resSize);
    }
    // 开始自动PID
    if (disControl->has_startautopid)
    {
        CrLogI("dis set start auto pid = %d", disControl->startautopid);
        TempAutoPidPrefer pid = TEMP_AUTO_PID_PREFER__INIT;
        pid.id = disControl->startautopid;

        GET_MESSAGE_BUFF(buff);
        size_t len = temp_auto_pid_prefer__pack(&pid, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_TEMP_AUTO_PID_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置延时摄影偏好
    if (disControl->delayimagepre)
    {
        CrLogI("dis set delay image prefer");
        int res = SetDelayImagePrefer(disControl->delayimagepre);

        // 应答
        DelayImagePrefer delayimagepre = DELAY_IMAGE_PREFER__INIT;
        DisControlPrint result = DIS_CONTROL_PRINT__INIT;
        result.has_result = 1;
        result.result = res;
        result.delayimagepre = &delayimagepre;
        
        GET_MESSAGE_BUFF(buff);
        size_t resLen = dis_control_print__pack(&result, buff);
        CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_CONTROL_PRINT_ANS, buff, resLen);
        SendProcessMsgBuff(&resSend, resSize);
    }
    // 设置断电续打偏好
    if (disControl->powerlosspre)
    {
        CrLogI("dis set power loss prefer");
        int res = SetPowerLossPrefer(disControl->powerlosspre);

        // 应答
        PowerLossPrefer powerlosspre = POWER_LOSS_PREFER__INIT;
        DisControlPrint result = DIS_CONTROL_PRINT__INIT;
        result.has_result = 1;
        result.result = res;
        result.powerlosspre = &powerlosspre;
        
        GET_MESSAGE_BUFF(buff);
        size_t resLen = dis_control_print__pack(&result, buff);
        CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_CONTROL_PRINT_ANS, buff, resLen);
        SendProcessMsgBuff(&resSend, resSize);
    }
    // 设置AI控制偏好
    if (disControl->aipre)
    {
        CrLogI("dis set ai control prefer");
        int res = SetAiControlPrefer(disControl->aipre);

        // 应答
        AiControlPrefer aicontrolpre = AI_CONTROL_PREFER__INIT;
        DisControlPrint result = DIS_CONTROL_PRINT__INIT;
        result.has_result = 1;
        result.result = res;
        result.aipre = &aicontrolpre;
        
        GET_MESSAGE_BUFF(buff);
        size_t resLen = dis_control_print__pack(&result, buff);
        CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_CONTROL_PRINT_ANS, buff, resLen);
        SendProcessMsgBuff(&resSend, resSize);
    }
    
    // 连接wifi
    if (disControl->connectwifi)
    {
        CrLogI("dis set connect wifi ssid = %s, pass = %s",
                disControl->connectwifi->ssid.data, disControl->connectwifi->pass.data);
        NetworksInfo info = NETWORKS_INFO__INIT;
        info.has_ssid = 1;
        info.ssid.data = disControl->connectwifi->ssid.data;
        info.ssid.len = disControl->connectwifi->ssid.len;
        info.has_pass = 1;
        info.pass.data = disControl->connectwifi->pass.data;
        info.pass.len = disControl->connectwifi->pass.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = networks_info__pack(&info, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_WIFI_USER_CONNECT_NETWORK_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_WIFI_MANAGER, &send, size);
    }
    // 连接已保存wifi
    if (disControl->connectsavewifi)
    {
        CrLogI("dis set connect save wifi ssid = %s", disControl->connectsavewifi->ssid.data);
        NetworksInfo info = NETWORKS_INFO__INIT;
        info.has_ssid = 1;
        info.ssid.data = disControl->connectsavewifi->ssid.data;
        info.ssid.len = disControl->connectsavewifi->ssid.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = networks_info__pack(&info, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_WIFI_USER_CONNECT_SAVE_NETWORK_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_WIFI_MANAGER, &send, size);
    }
    // 断开连接
    if (disControl->disconnectwifi)
    {
        CrLogI("dis set disconnect wifi");
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_WIFI_USER_DISCONNECT_NETWORK_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_WIFI_MANAGER, &send, size);
    }
    // 忽略保存wifi
    if (disControl->removewifi)
    {
        CrLogI("dis set remove save wifi ssid = %s", disControl->removewifi->ssid.data);
        NetworksInfo info = NETWORKS_INFO__INIT;
        info.has_ssid = 1;
        info.ssid.data = disControl->removewifi->ssid.data;
        info.ssid.len = disControl->removewifi->ssid.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = networks_info__pack(&info, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_WIFI_USER_REMOVE_NETWORK_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_WIFI_MANAGER, &send, size);
    }
    // 共振补偿测试
    if (disControl->has_quietmode)
    {
        CrLogI("dis set quietmode test = %d", disControl->quietmode);
        MutableTypeData quietmode = MUTABLE_TYPE_DATA__INIT;
        quietmode.has_int_v = 1;
        quietmode.int_v = disControl->quietmode;

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&quietmode, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_QUIET_MODE_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置进料
    if (disControl->loadmaterial)
    {
        CrLogI("dis set load material");
        GET_MESSAGE_BUFF(buff);
        size_t len = load_quit_material__pack(disControl->loadmaterial, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_LOAD_MATERIAL_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置退料
    if (disControl->quitmaterial)
    {
        CrLogI("dis set quit material");
        GET_MESSAGE_BUFF(buff);
        size_t len = load_quit_material__pack(disControl->quitmaterial, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_QUIT_MATERIAL_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 上传本地日志
    if (disControl->has_uploadlocallog)
    {
        CrLogI("dis upload local log");
        SendString path = SEND_STRING__INIT;
        path.str.data = disControl->uploadlocallog.data;
        path.str.len = disControl->uploadlocallog.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = send_string__pack(&path, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_UPLOAD_LOCAL_LOG_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    }
    // 上传本地视频
    if (disControl->has_uploadlocalvideo)
    {
        CrLogI("dis upload local video");
        SendString path = SEND_STRING__INIT;
        path.str.data = disControl->uploadlocalvideo.data;
        path.str.len = disControl->uploadlocalvideo.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = send_string__pack(&path, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_UPLOAD_LOCAL_VIDEO_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    }
    // 删除创想云用户信息，解除用户绑定
    if (disControl->has_updateusercxyinfo)
    {
        // 删除信息，重启app-server
        RestartNowAppServer();

        // 应答
        DisControlPrint result = DIS_CONTROL_PRINT__INIT;
        result.has_result = 1;
        result.result = 1;

        GET_MESSAGE_BUFF(buff);
        size_t resLen = dis_control_print__pack(&result, buff);
        CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_CONTROL_PRINT_ANS, buff, resLen);
        SendProcessMsgBuff(&resSend, resSize);
    }
    // 激光标定
    if (disControl->has_lasercalibration)
    {
        CrLogI("dis set laser calibration");
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_GCODE_SET_LASER_CALIBRATION_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

    dis_control_print__free_unpacked(disControl, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisplayButtonSound(MsgHeadBuf_t *head)
{
    AudioNum sound = AUDIO_NUM__INIT;
    sound.data = AUDIO_BUTTON_BEEP;

    GET_MESSAGE_BUFF(buff);
    size_t len = audio_num__pack(&sound, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_SEND_AUDIO_MESSAGE, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_AUDIO_MANAGER, &send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetPowerLossInfoAns(MsgHeadBuf_t *head)
{
    GcodeCmd *fileName = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!fileName) {
        CrLogW("unpack failed\n");
        return;
    }

    if (fileName->has_cmdstr)
    {
        CrLogI("Power loss file name = %s", fileName->cmdstr.data);
        // 发送到UI，提示用户执行是否断电续打
        SendString name = SEND_STRING__INIT;
        name.str.data = fileName->cmdstr.data;
        name.str.len = fileName->cmdstr.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = send_string__pack(&name, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_POWER_LOSS_ANS, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    gcode_cmd__free_unpacked(fileName, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserAutoPidResultConfirmRemind(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_AUTO_PID_CONFIRM_REQ, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserReportAutoLevelResult(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_SYNC_AUTO_LEVEL_RESULT, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

static void UserGetUploadLocalLogAns(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_UPLOAD_LOCAL_LOG_ANS, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetGsensorExistAns(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_GET_GSENSOR_EXIST_ANS, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDisplayStartLaserTest(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_REQ, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

static void UserDisplayStartLaserAns(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_SET_LASER_TEST_START_ANS, head->buf, head->bufLen);
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
            case MANAGER_CMD_MESSAGE_TEST: ManagerMessageTest(&head); break;
            case SERVER_CMD_DIS_TEST_ANS: ServerMessageTestAns(&head); break;

            case SERVER_CMD_DIS_SYNC_EXPORT_LOG_STATE: DisSyncExportLogState(&head); break;

            case SERVER_CMD_DIS_GET_SYSTEM_CONFIG_REQ: DisGetSystemConfigRes(&head); break;
            case SERVER_CMD_DIS_GET_PRINT_SAVE_PARA_REQ: DisGetPrintSaveParaRes(&head); break;
            case SERVER_CMD_DIS_GET_DEVICE_STATE_REQ: DisGetDeviceStateRes(&head); break;
            case SERVER_CMD_DIS_GET_POWER_LOSS_RES: DisGetPowerLossInfoRes(&head); break;
            case SERVER_CMD_DIS_GET_UPGRADE_REBOOT_RES: DisGetUpgradeRebootInfoRes(&head); break;
            case SERVER_CMD_DIS_GET_PRINT_WORK_INFO_REQ: ManagerSyncPrintWorkInfo(&head); break;
            case SERVER_CMD_DIS_GET_PRINT_OBJECT_RES: ManagerSyncPrintObjectInfo(&head); break;
            
            case SERVER_CMD_DIS_GET_LOCAL_GCODE_REQ: UserDisGetLocalGcodeReq(&head); break;
            case SERVER_CMD_DIS_GET_LOCAL_IMAGE_REQ: UserDisGetLocalImageReq(&head); break;
            case SERVER_CMD_DIS_GET_LOCAL_PHOTO_REQ: UserDisGetLocalPhotoReq(&head); break;
            case SERVER_CMD_DIS_GET_LOCALTION_REQ: UserDisGetLocaltionReq(&head); break;
            case SERVER_CMD_DIS_GET_MATERIAL_PRE_REQ: UserDisGetMaterialPreferReq(&head); break;
            case SERVER_CMD_DIS_GET_AUTO_PID_PRE_REQ: UserDisGetAutoPidPreferReq(&head); break;
            case SERVER_CMD_DIS_GET_DELAY_IMAGE_PRE_REQ: UserDisGetDelayImagePreferReq(&head); break;
            case SERVER_CMD_DIS_GET_POWER_LOSS_PRE_REQ: UserDisGetPowerLossPreferReq(&head); break;
            case SERVER_CMD_DIS_GET_AI_CONTROL_PRE_REQ: UserDisGetAiControlPreferReq(&head); break;
            case SERVER_CMD_DIS_GET_WIFI_INFO_REQ: UserDisGetWifiInfoReq(&head); break;
            case SERVER_CMD_DIS_GET_WIFI_SCAN_REQ: UserDisGetWifiScanListReq(&head); break;
            case SERVER_CMD_DIS_GET_UPGRADE_INFO_REQ: UserDisGetUpgradeInfoReq(&head); break;
            case SERVER_CMD_DIS_GET_USER_CXY_INFO_REQ: UserDisGetUserCxyInfoReq(&head); break;
            case SERVER_CMD_DIS_GET_GSENSOR_EXIST_RES: UserDisGetGsensorExistReq(&head); break;
            case SERVER_CMD_DIS_CONTROL_PRINT_REQ: UserDisControlPrintReq(&head); break;
            case SERVER_CMD_DIS_BUTTON_SOUND: UserDisplayButtonSound(&head); break;

            case MANAGER_SYNC_SYSTEM_CONFIG: DisGetSystemConfigRes(&head); break;
            case MANAGER_SYNC_PRINT_SAVE_PARA: DisGetPrintSaveParaRes(&head); break;
            case MANAGER_CMD_SYNC_DELAY_IMAGE_CONFIG: UserDisGetDelayImagePreferReq(&head); break;
            case MANAGER_CMD_SYNC_TEMP_AUTO_CONFIG: UserDisGetAutoPidPreferReq(&head); break;
            case MANAGER_CMD_SYNC_MATERIAL_WARMUP_CONFIG: UserDisGetMaterialPreferReq(&head); break;
            case MANAGER_CMD_SYNC_POWER_LOSS_CONFIG: UserDisGetPowerLossPreferReq(&head); break;
            case MANAGER_CMD_SYNC_AI_CONTROL_CONFIG: UserDisGetAiControlPreferReq(&head); break;
            case MANAGER_DEVICE_STATE_CHANGE: DisGetDeviceStateRes(&head); break;
            case MANAGER_DEVICE_PRINT_FINISH: UserPrintFinishAns(&head); break;
            case MANAGER_SYNC_DEV_UPGRADE_STATE: ManagerSyncUpgradeState(&head); break;
            case MANAGER_SYNC_PRINT_WORK_INFO: ManagerSyncPrintWorkInfo(&head); break;
            case MANAGER_CMD_SYNC_FILE_COPY_PROGRESS: ManagerSyncFileCopyProgress(&head); break;
            case MANAGER_CMD_SYNC_UPGRADE_REBOOT_INFO: ManagerSyncUpgradeRebootInfo(&head); break;
            case MANAGER_CMD_SYNC_PRINT_OBJECT_INFO: ManagerSyncPrintObjectInfo(&head); break;

            case MANAGER_CMD_GCODE_SET_ABSOLUTE_ANS: UserAbsolutePositioningAns(&head); break;
            case MANAGER_CMD_GCODE_SET_RELATIVE_ANS: UserRelativePositioningAns(&head); break;
            case MANAGER_CMD_GCODE_GET_SD_FILE_ANS: UserGetSdCardFileAns(&head); break;
            case MANAGER_CMD_GCODE_GET_SD_MODEL_IMAGE_ANS: UserGetSdGcodeImageAns(&head); break;
            case MANAGER_CMD_GCODE_GET_SD_GCODE_PHOTO_ANS: UserGetSdGcodePhotoAns(&head); break;
            case MANAGER_CMD_GCODE_GET_HOTEND_XYZ_LOCAL_ANS: UserGetHotendXyzLocalAns(&head); break;
            case MANAGER_CMD_WIFI_USER_GET_WIFI_INFO_ANS: UserGetWifiInfoAns(&head); break;
            case MANAGER_CMD_WIFI_USER_SCAN_WIFI_ANS: UserGetWifiScanListAns(&head); break;
            case MANAGER_CMD_GET_POWER_LOSS_INFO_ANS: UserGetPowerLossInfoAns(&head); break;
            case MANAGER_CMD_UPLOAD_LOCAL_LOG_ANS: UserGetUploadLocalLogAns(&head); break;
            case MANAGER_CMD_GET_GSENSOR_EXIST_ANS: UserGetGsensorExistAns(&head); break;

            case MANAGER_CMD_GET_UPGRADE_INFO_ANS: UserGetUpgradeInfoAns(&head); break;
            case MANAGER_CMD_UPDATE_USER_CXY_INFO_ANS: UserGetUserCxyInfoAns(&head); break;
            case MANAGER_CMD_SYSTEM_RESET_ANS: UserSetSystemResetAns(&head); break;

            case MANAGER_CMD_AUTO_PID_RESULT_CONFIRM_REMIND: UserAutoPidResultConfirmRemind(&head); break;
            case MANAGER_CMD_REPORT_AUTO_LEVEL_RESULT: UserReportAutoLevelResult(&head); break;

            case SERVER_CMD_DIS_SET_LASER_TEST_START_REQ: UserDisplayStartLaserTest(&head); break;
            case MANAGER_CMD_START_LASER_TEST_ANS: UserDisplayStartLaserAns(&head); break;
            default: UserDisControlPrintAns(&head); break; 
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
    managerMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_DISPLAY_MANAGER);
    if (managerMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    serverMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_DISPLAY_SERVER);
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
MsgHandle_t *DisplayManagerInit(void *arg)
{
    CrLogI("display manager init");
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
int DisplayManagerExceptionHandleSemPost(void)
{
    return 0;
}
