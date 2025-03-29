/**
 * @ Author: Rui Xiong
 * @ Create Time: 2022-11-14 18:02:19
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-04-24 11:17:07
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

#include "Base/MasterMsgBase.h"
#include "WebManager.h"

static MsgHandle_t msgHandle;
static int managerMsgId = -1;
static int serverMsgId = -1;
static UpgradeRebootInfo_t upgradeInfo = {0};

/**
 * @description: 静态函数声明
 */
static int SendMsgBuff(MsgHeadBuf_t *data, size_t len);
static int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len);
static void UserWebGetDelayImagePreferReq(MsgHeadBuf_t *head);

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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_GET_DEVICE_STATE_ANS, buff, len);
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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_SYNC_PRINT_WORK_INFO, buf, len);
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
    GcodeCmdRes *file = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!file) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("get gcode file result = %d", file->result);
    SendString path = SEND_STRING__INIT;
    if (file->result)
    {
        char *cachePath = GetUserGcodeFileInfoFilePath();
        path.str.data = (uint8_t*)cachePath;
        path.str.len = strlen(cachePath) + 1;
        CrLogD("get sd gcode file num = %d, path = %s\n", *file->resstr.data, path.str.data);
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = send_string__pack(&path, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_GET_GCODE_FILE_LIST_ANS, buff, len);
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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_GET_GCODE_FILE_IMAGE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    control_range__free_unpacked(image, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserWebControlPrintAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *result = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!result) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("print control file result = %d", result->result);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    if (result->result)
    {
        control.has_result = 1;
        control.result = result->result;
    }
    gcode_cmd_res__free_unpacked(result, NULL);

    GET_MESSAGE_BUFF(res);
    size_t resLen = web_control_print__pack(&control, res);
    CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_CONTROL_PRINT_ANS, res, resLen);
    SendProcessMsgBuff(&resSend, resSize);
}

/**
 * @description: 
 * @return {*}
 * @param {int} result
 */
static void UserWebControlPrintDirectAns(int result)
{
    CrLogI("print control file result = %d", result);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_result = 1;
    control.result = result;

    GET_MESSAGE_BUFF(res);
    size_t resLen = web_control_print__pack(&control, res);
    CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_CONTROL_PRINT_ANS, res, resLen);
    SendProcessMsgBuff(&resSend, resSize);
}

/**
 * @description: 
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

        AxisPositionInfo axisInfo = AXIS_POSITION_INFO__INIT;
        axisInfo.x = local->x;
        axisInfo.y = local->y;
        axisInfo.z = local->z;
        axisInfo.e = local->e;

        GET_MESSAGE_BUFF(buff);
        size_t len = axis_position_info__pack(&axisInfo, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_GET_CURRENT_LOCAL_ANS, buff, len);
        SendProcessMsgBuff(&send, size);

        axis_para__free_unpacked(local, NULL);
    }
    gcode_cmd_res__free_unpacked(hotendLocal, NULL);
}

// /**
//  * @description: 
//  * @return {*}
//  * @param {MsgHeadBuf_t} *head
//  */
// static void WebSetSystemResetRes(MsgHeadBuf_t *head)
// {
//     CrLogI("Web Set System Reset Res");
//     CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_SYSTEM_RESET_REQ, head->buf, head->bufLen);
//     SendProcessMsgBuff(&send, size);
// }

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WebGetSystemConfigRes(MsgHeadBuf_t *head)
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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_GET_SYSTEM_CONFIG_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WebGetPrintSaveParaRes(MsgHeadBuf_t *head)
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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_GET_PRINT_SAVE_PARA_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WebGetGcodeFileListRes(MsgHeadBuf_t *head)
{
    // 获取扫描路径
    char *traversePath = GetUserLocalSdCardPtah();

    // 发送指令
    GcodeCmd file = GCODE_CMD__INIT;
    file.has_cmdstr = 1;
    file.cmdstr.data = (uint8_t*)traversePath;
    file.cmdstr.len = strlen(traversePath) + 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd__pack(&file, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_GET_SD_FILE_REQ, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WebGetCurrentLocalRes(MsgHeadBuf_t *head)
{
    GcodeCmd local = GCODE_CMD__INIT;
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd__pack(&local, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_GET_HOTEND_XYZ_LOCAL_REQ, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

// /**
//  * @description: 
//  * @return {*}
//  * @param {MsgHeadBuf_t} *head
//  */
// static void WebStartSystemResetAns(MsgHeadBuf_t *head)
// {
//     CrLogI("Web Set System Reset Ans");
//     CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_SYSTEM_RESET_ANS, head->buf, head->bufLen);
//     MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
// }

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WebControlPrintRes(MsgHeadBuf_t *head)
{
    WebControlPrint *control = web_control_print__unpack(NULL, head->bufLen, head->buf);
    if (!control) {
        CrLogW("unpack failed\n");
        return;
    }
    // 开始打印文件
    if (control->has_print) {
        CrLogI("web control start print local gcode");
        CrLogI("file name = %s\n", control->print.data);

        MutableTypeData start = MUTABLE_TYPE_DATA__INIT;
        start.has_bytes_v = 1;
        start.bytes_v.data = control->print.data;
        start.bytes_v.len = control->print.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&start, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_START_CLOUD_PRINT_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 开始删除文件
    if (control->has_delete_) {
        CrLogI("web control start delete local gcode");
        CrLogI("file name = %s\n", control->delete_.data);

        GcodeCmd start = GCODE_CMD__INIT;
        start.has_cmdstr = 1;
        start.cmdstr.data = control->delete_.data;
        start.cmdstr.len = control->delete_.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&start, buff);
        // CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_START_CLOUD_PRINT_REQ, buff, len);
        // MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 开始重命名文件
    if (control->has_rename) {
        CrLogI("web control start rename local gcode");
        CrLogI("cmd = %s\n", control->rename.data);

        GcodeCmd start = GCODE_CMD__INIT;
        start.has_cmdstr = 1;
        start.cmdstr.data = control->rename.data;
        start.cmdstr.len = control->rename.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&start, buff);
        // CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_START_CLOUD_PRINT_REQ, buff, len);
        // MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 暂停
    if (control->has_pause)
    {
        CrLogI("web control paue/resume print local gcode, paue/resume = %d\n", control->pause);
        GcodeCmd printControl = GCODE_CMD__INIT;
        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&printControl, buff);

        if (control->pause) {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_PAUSE_PRINT_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
        else {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_RESUME_PRINT_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
    }
    // 停止
    if (control->has_stop)
    {
        CrLogI("web control stop print local gcode, stop = %d\n", control->stop);
        if (control->stop) {
            GcodeCmd printControl = GCODE_CMD__INIT;
            GET_MESSAGE_BUFF(buff);
            size_t len = gcode_cmd__pack(&printControl, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_STOP_PRINT_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
    }
    // 风扇控制
    if (control->fan)
    {
        CrLogI("web control fan\n");
        GET_MESSAGE_BUFF(buff);
        size_t len = multi_fan__pack(control->fan, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_OPEN_FAN_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置喷嘴温度
    if (control->nozzletemp)
    {
        CrLogI("web control nozzle temp\n");
        GET_MESSAGE_BUFF(buff);
        size_t len = extruder__pack(control->nozzletemp, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_NOZZLE_TEMP_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置热床温度
    if (control->bedtemp)
    {
        CrLogI("web control bed temp\n");
        GET_MESSAGE_BUFF(buff);
        size_t len = heater_bed__pack(control->bedtemp, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_BED_TEMP_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 控制断电续打
    if (control->has_offcontinue)
    {
        CrLogI("web control off continue, value = %d\n", control->offcontinue);

        GcodeCmd offcontinue = GCODE_CMD__INIT;
        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&offcontinue, buff);

        if (control->offcontinue) {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_START_POWER_LOSS_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
        else {
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_CANCEL_POWER_LOSS_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
    }

    // 控制回原点
    if (control->has_autohome)
    {
        CrLogI("web control autohome, value = %s\n", control->autohome.data);
        GcodeCmd move = GCODE_CMD__INIT;
        move.has_cmdstr = 1;
        move.cmdstr.data = control->autohome.data;
        move.cmdstr.len = control->autohome.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&move, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_RETURN_HOME_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 轴移动（X\Y\Z\E）
    if (control->has_setposition)
    {
        CrLogI("web control setPosition, value = %s\n", control->setposition.data);
        char moveCmd[256] = {0};
        snprintf(moveCmd, 256, "SAVE_GCODE_STATE NAME=myMoveState\n G91\n G0 %s\n M400\n RESTORE_GCODE_STATE NAME=myMoveState", control->setposition.data);
        GcodeCmd move = GCODE_CMD__INIT;
        move.has_cmdstr = 1;
        move.cmdstr.data = (uint8_t*)moveCmd;
        move.cmdstr.len = strlen(moveCmd);

        GET_MESSAGE_BUFF(buff1);
        size_t len1 = gcode_cmd__pack(&move, buff1);
        CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_HOTEND_XYZ_MOVE_REQ, buff1, len1);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send1, size1);
    }
    // 设置打印倍速
    if (control->has_setfeedratepct)
    {
        CrLogI("web control setFeedratePct, value = %s\n", control->setfeedratepct.data);
        GcodeCmd speed = GCODE_CMD__INIT;
        speed.has_cmdstr = 1;
        speed.cmdstr.data = control->setfeedratepct.data;
        speed.cmdstr.len = control->setfeedratepct.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&speed, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_PRINT_SPEED_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置流量倍速
    if (control->has_setflowratepct)
    {
        CrLogI("web control setFlowratePct, value = %s\n", control->setflowratepct.data);
        GcodeCmd flow = GCODE_CMD__INIT;
        flow.has_cmdstr = 1;
        flow.cmdstr.data = control->setflowratepct.data;
        flow.cmdstr.len = control->setflowratepct.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&flow, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_PRINT_FLOW_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 执行gcode宏定义
    if (control->has_gcodecmd)
    {
        CrLogI("web control gcodeCmd, value = %d\n", control->gcodecmd.data);
        GcodeCmd macro = GCODE_CMD__INIT;
        macro.has_cmdstr = 1;
        macro.cmdstr.data = control->gcodecmd.data;
        macro.cmdstr.len = control->gcodecmd.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&macro, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_GCODE_MACRO_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

    // 设置轴补偿值（Z）
    if (control->has_axisrecoup){
        CrLogI("set axis recoup = %s", control->axisrecoup.data);
        GcodeCmd offset = GCODE_CMD__INIT;
        offset.has_cmdstr = 1;
        offset.cmdstr.data = control->axisrecoup.data;
        offset.cmdstr.len = control->axisrecoup.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&offset, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_AXIS_RECOUP_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

    // 电机锁定、解锁
    if (control->has_motorlock){
        CrLogI("web set motor lock = %d", control->motorlock);
        MutableTypeData lock = MUTABLE_TYPE_DATA__INIT;
        lock.has_int_v = 1;
        lock.int_v = control->motorlock;
        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&lock, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_MOTOR_UNLOCK_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);

    }

        // 一键冷却
    if (control->has_heatersoff){
        CrLogI("web control heatersoff, value = %d\n", control->heatersoff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_STOP_ALL_HEAT_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

        // 速度限制
    if (control->has_velocitylimits){
        CrLogI("web control velocitylimits, value = %s\n", control->velocitylimits.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = control->velocitylimits.data;
        max.cmdstr.len = control->velocitylimits.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_MAX_SPEED_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

        // 加速度限制
    if (control->has_accelerationlimits){
        CrLogI("web control accelerationLimits, value = %s\n", control->accelerationlimits.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = control->accelerationlimits.data;
        max.cmdstr.len = control->accelerationlimits.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_MAX_ACCELERATION_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

        // 拐角速度限制
    if (control->has_cornervelocitylimits){
        CrLogI("web control cornerVelocityLimits, value = %s\n", control->cornervelocitylimits.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = control->cornervelocitylimits.data;
        max.cmdstr.len = control->cornervelocitylimits.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_MAX_CORNER_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

        // 加速到减速的加速度限制
    if (control->has_acceltodecellimits){
        CrLogI("web control accelToDecelLimits, value = %s\n", control->acceltodecellimits.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = control->acceltodecellimits.data;
        max.cmdstr.len = control->acceltodecellimits.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_MAX_JERK_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

        // 压力推进设置
    if (control->has_pressureadvance){
        CrLogI("web control pressureAdvance, value = %s\n", control->pressureadvance.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = control->pressureadvance.data;
        max.cmdstr.len = control->pressureadvance.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_PRESSURE_ADVANCE_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

        // 平滑时间设置
    if (control->has_smoothtime){
        CrLogI("web control smoothTime, value = %s\n", control->smoothtime.data);
        GcodeCmd max = GCODE_CMD__INIT;
        max.has_cmdstr = 1;
        max.cmdstr.data = control->smoothtime.data;
        max.cmdstr.len = control->smoothtime.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&max, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_SMOOTH_TIME_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

    if (control->has_videoelapse)
    {
        CrLogI("web control videoElapse, value = %d\n", control->videoelapse);
        DelayImagePrefer prefer = DELAY_IMAGE_PREFER__INIT;
        prefer.has_sw = 1;
        prefer.sw = control->videoelapse;

        // 设置摄像头设置
        int result = SetDelayImagePrefer(&prefer);
        UserWebControlPrintDirectAns(result);
    }

    if (control->has_nozzlemovesnapshot)
    {
        CrLogI("web control has_nozzleMoveSnapshot, value = %d\n", control->nozzlemovesnapshot);
        DelayImagePrefer prefer = DELAY_IMAGE_PREFER__INIT;
        prefer.has_location = 1;
        prefer.location = control->nozzlemovesnapshot;

        // 设置摄像头设置
        int result = SetDelayImagePrefer(&prefer);
        UserWebControlPrintDirectAns(result);
    }

    if (control->has_videoelapseframe)
    {
        CrLogI("web control videoElapseFrame, value = %d\n", control->videoelapseframe);
        DelayImagePrefer prefer = DELAY_IMAGE_PREFER__INIT;
        prefer.has_frame = 1;
        prefer.frame = control->videoelapseframe;

        // 设置摄像头设置
        int result = SetDelayImagePrefer(&prefer);
        UserWebControlPrintDirectAns(result);
    }

    if (control->has_videoelapseinterval)
    {
        CrLogI("web control has_videoElapseInterval, value = %d\n", control->videoelapseinterval);
        DelayImagePrefer prefer = DELAY_IMAGE_PREFER__INIT;
        prefer.has_interval = 1;
        prefer.interval = control->videoelapseinterval;

        // 设置摄像头设置
        int result = SetDelayImagePrefer(&prefer);
        UserWebControlPrintDirectAns(result);
    }
    // 设置自动温度PID
    if (control->has_bedtempautopid)
    {
        CrLogI("web set has_bedtempautopid, value = %d\n", control->bedtempautopid);
        TempAutoPidPrefer prefer = TEMP_AUTO_PID_PREFER__INIT;
        prefer.id = 2;
        prefer.has_temp = 1;
        prefer.temp = control->bedtempautopid;

        int result = SetTempAutoPidPrefer(&prefer);
        UserWebControlPrintDirectAns(result);
    }
    // 设置自动温度PID
    if (control->has_nozzletempautopid)
    {
        CrLogI("web set has_nozzletempautopid, value = %d\n", control->nozzletempautopid);
        TempAutoPidPrefer prefer = TEMP_AUTO_PID_PREFER__INIT;
        prefer.id = 1;
        prefer.has_temp = 1;
        prefer.temp = control->nozzletempautopid;

        int result = SetTempAutoPidPrefer(&prefer);
        UserWebControlPrintDirectAns(result);
    }
    // 开始自动PID
    if (control->has_startautopid)
    {
        CrLogI("web control as_startautopid, value = %d", control->startautopid);
        TempAutoPidPrefer pid = TEMP_AUTO_PID_PREFER__INIT;
        pid.id = control->startautopid;

        GET_MESSAGE_BUFF(buff);
        size_t len = temp_auto_pid_prefer__pack(&pid, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_START_TEMP_AUTO_PID_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置断料检测
    if (control->has_materialdetect)
    {
        CrLogI("web set material detect = %s", control->materialdetect.data);
        GcodeCmd detect = GCODE_CMD__INIT;
        detect.has_cmdstr = 1;
        detect.cmdstr.data = control->materialdetect.data;
        detect.cmdstr.len = control->materialdetect.len;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&detect, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_MATERIAL_DELECT_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置断电续打
    if (control->has_powerlosssw)
    {
        CrLogI("web set power loss = %d", control->powerlosssw);
        PowerLossPrefer prefer = POWER_LOSS_PREFER__INIT;
        prefer.has_sw = 1;
        prefer.sw = control->powerlosssw;

        // 设置断电续打设置
        int result = SetPowerLossPrefer(&prefer);
        UserWebControlPrintDirectAns(result);
    }
    // 谐振补偿测试
    if (control->has_resonancetest)
    {
        CrLogI("dis set resonance test = %s", control->resonancetest.data);
        GcodeCmd resonance = GCODE_CMD__INIT;
        resonance.has_cmdstr = 1;
        resonance.cmdstr.data = control->resonancetest.data;
        resonance.cmdstr.len = control->resonancetest.len;
        
        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&resonance, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_RESONANCE_TEST_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 手动调平
    if (control->has_manuallevel)
    {
        CrLogI("web set manual level = %s", control->manuallevel.data);
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
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_RETURN_HOME_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
        // 点移动
        char moveCmd[256] = {0};
        snprintf(moveCmd, 256, "G0 Z10 F7800\n G0 %s F7800\n G0 Z0 F7800", control->manuallevel.data);
        GcodeCmd level = GCODE_CMD__INIT;
        level.has_cmdstr = 1;
        level.cmdstr.data = (uint8_t*)moveCmd;
        level.cmdstr.len = strlen(moveCmd);

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd__pack(&level, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_HOTEND_XYZ_MOVE_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置自动调平
    if (control->has_autolevel)
    {
        CrLogI("web set auto level");
        // 设置自动调平
        MutableTypeData move = MUTABLE_TYPE_DATA__INIT;
        move.has_int_v = 1;
        move.int_v = control->autolevel;

        GET_MESSAGE_BUFF(buff1);
        size_t len1 = mutable_type_data__pack(&move, buff1);
        CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_DEVICE_AUTO_LEVEL_REQ, buff1, len1);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send1, size1);
    }
    // 重启klipper
    if (control->has_restartklipper)
    {
        CrLogI("web set restart klipper");
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_RESTART_KLIPPER_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 重启klipper下位机
    if (control->has_restartfirmware)
    {
        CrLogI("web set restart firmware");
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_FIRMWARE_RESTART_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
     // 设置恢复出厂设置
    if (control->has_resetsystem)
    {
        CrLogI("web set system reset = %d", control->resetsystem);
        MutableTypeData reset = MUTABLE_TYPE_DATA__INIT;
        reset.has_int_v = 1;
        reset.int_v = control->resetsystem;

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&reset, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_SYSTEM_RESET_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }   
    // 开始升级
    if (control->upgrade)
    {
        CrLogI("web Start Device upgrade Res");
        GET_MESSAGE_BUFF(buff);
        size_t len = upgrade_info_list__pack(control->upgrade, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_START_UPGRADE_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    }
    // 灯光开关
    if (control->has_lightsw)
    {
        CrLogI("web control led, value = %d\n", control->lightsw);
        SystemConfigProto config = SYSTEM_CONFIG_PROTO__INIT;
        config.has_light_sw= 1;
        config.light_sw = control->lightsw;
        int result = UpdataSystemConfig(&config);
        UserWebControlPrintDirectAns(result);
    }
    // 保存参数到（EEPROM）
    if (control->has_savepara)
    {
        CrLogI("web set save para");
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_SAVE_CONFIG_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 设置AI控制偏好
    if (control->aipre)
    {
        CrLogI("web control ai control\n");
        // 设置AI控制设置
        int result = SetAiControlPrefer(control->aipre);
        UserWebControlPrintDirectAns(result);
    }
    // 清除错误码
    if (control->has_clearfaultcode)
    {
        CrLogI("web clear fault code = %d", control->clearfaultcode);
        FaultCode_t info = {0}; 
        UpdataFaultCode(info);
    }
    // 打印前检测开关
    if (control->has_enableselftest)
    {
        CrLogI("web control enableSelfTest, value = %d\n", control->enableselftest);
        SystemConfigProto config = SYSTEM_CONFIG_PROTO__INIT;
        config.has_enableselftest= 1;
        config.enableselftest = control->enableselftest;
        int result = UpdataSystemConfig(&config);
        UserWebControlPrintDirectAns(result);
    }
        // 设置对象排除
    if (control->excludeobject)
    {
        CrLogI("dis set exclude object");
        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(control->excludeobject, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_SET_EXCLUDE_OBJECT_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    web_control_print__free_unpacked(control, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WebMultipleBedTempRes(MsgHeadBuf_t *head)
{
    MultipleBedTemp *bedTemp = multiple_bed_temp__unpack(NULL, head->bufLen, head->buf);
    if (!bedTemp) {
        CrLogW("unpack failed\n");
        return;
    }
    char paraBuff[100] = {0};
    if (bedTemp->has_bedtemp0) {
        
        CrLogI("web control bed temp, num = 0 val = %d\n", bedTemp->bedtemp0);
        if (GetSystemConfig().model == CR_10_H1) {
            snprintf(paraBuff, 100, "SET_HEATER_TEMPERATURE HEATER=heater_bed_0 TARGET=%d", bedTemp->bedtemp0);
        }  
        else {
            snprintf(paraBuff, 100, "SET_HEATER_TEMPERATURE HEATER=heater_bed TARGET=%d", bedTemp->bedtemp0);
        }

    }else if (bedTemp->has_bedtemp1){

        CrLogI("web control bed temp, num = 1 val = %d\n", bedTemp->bedtemp1);
        snprintf(paraBuff, 100, "SET_HEATER_TEMPERATURE HEATER=heater_bed_1 TARGET=%d", bedTemp->bedtemp1);

    }else if (bedTemp->has_bedtemp2){
        
        CrLogI("web control bed temp, num = 2 val = %d\n", bedTemp->bedtemp2);
        snprintf(paraBuff, 100, "SET_HEATER_TEMPERATURE HEATER=heater_bed_2 TARGET=%d", bedTemp->bedtemp2);

    }
    multiple_bed_temp__free_unpacked(bedTemp, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserWebGetDelayImagePreferReq(MsgHeadBuf_t *head)
{
    // 获取摄像头设置
    DelayImagePrefer pre = DELAY_IMAGE_PREFER__INIT;
    GetDelayImagePrefer(&pre);
    GET_MESSAGE_BUFF(buff);
    size_t len = delay_image_prefer__pack(&pre, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_GET_DELAY_IMAGE_PRE_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserWebGetAutoPidPreferReq(MsgHeadBuf_t *head)
{
    TempAutoPidPreferList *list = temp_auto_pid_prefer_list__unpack(NULL, head->bufLen, head->buf);
    if (!list) {
        CrLogW("unpack failed\n");
        return;
    }
    TempAutoPidPreferList getList = TEMP_AUTO_PID_PREFER_LIST__INIT;
    GetTempAutoPidPrefer(list, &getList);

    GET_MESSAGE_BUFF(buff);
    size_t len = temp_auto_pid_prefer_list__pack(&getList, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_GET_AUTO_PID_PRE_ANS, buff, len);
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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_GET_PRINT_OBJECT_ANS, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserReportAutoLevelResult(MsgHeadBuf_t *head)
{
    CrLogI("web set save para");
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_SYNC_AUTO_LEVEL_RESULT, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserWebGetUpgradeInfoReq(MsgHeadBuf_t *head)
{
    CrLogI("Web Get Device upgrade Info Res");
    UpgradeInfoList *infoList = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!infoList) {
        CrLogW("unpack failed\n");
        return;
    }
    
    // 从云端查询Linux、mcu升级固件
    if (infoList->linuxota || infoList->mcu1ota) {
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GET_UPGRADE_INFO_REQ, head->buf, head->bufLen);
        MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    }

    upgrade_info_list__free_unpacked(infoList, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetUpgradeInfoAns(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_CHECK_UPGRADE_ANS, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerSyncUpgradeState(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_SYNC_UPGRADE_STATE, head->buf, head->bufLen);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserWebGetPowerLossPreferReq(MsgHeadBuf_t *head)
{
    // 获取断电续打设置
    PowerLossPrefer pre = POWER_LOSS_PREFER__INIT;
    GetPowerLossPrefer(&pre);

    GET_MESSAGE_BUFF(buff);
    size_t len = power_loss_prefer__pack(&pre, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_GET_POWER_LOSS_PRE_ANS, buff, len);
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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, SERVER_CMD_WEB_GET_AI_CONTROL_PRE_ANS, buff, len);
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
    // DisControlPrint result = DIS_CONTROL_PRINT__INIT;
    // result.has_result = 1;
    // result.result = res->result;
    // result.has_systemreset = 1;

    // GET_MESSAGE_BUFF(buff);
    // size_t resLen = dis_control_print__pack(&result, buff);
    // CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_DISPLAY_MANAGER, SERVER_CMD_DIS_CONTROL_PRINT_ANS, buff, resLen);
    // SendProcessMsgBuff(&resSend, resSize);

    gcode_cmd_res__free_unpacked(res, NULL);
}

static void WebGetGcodeFileImageRes(MsgHeadBuf_t *head)
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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_MANAGER, MANAGER_CMD_GCODE_GET_SD_MODEL_IMAGE_REQ, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);

    local_gcode_info__free_unpacked(info, NULL);
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
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_LOCAL_VIDEO_RESULT, buf, len);
    SendProcessMsgBuff(&send, size);

    file_control__free_unpacked(control, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void WebSyncExportLogState(MsgHeadBuf_t *head)
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
    else UpdataLogProgress(sync->progress);

    export_log_state__free_unpacked(sync, NULL);
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
            case SERVER_CMD_WEB_CONTROL_PRINT_REQ: WebControlPrintRes(&head); break;
            case SERVER_CMD_WEB_GET_SYSTEM_CONFIG_REQ: WebGetSystemConfigRes(&head); break;
            case SERVER_CMD_WEB_GET_PRINT_SAVE_PARA_REQ: WebGetPrintSaveParaRes(&head); break;
            case SERVER_CMD_WEB_GET_GCODE_FILE_LIST_REQ: WebGetGcodeFileListRes(&head); break;
            case SERVER_CMD_WEB_GET_GCODE_FILE_IMAGE_REQ: WebGetGcodeFileImageRes(&head); break;
            case SERVER_CMD_WEB_GET_CURRENT_LOCAL_REQ: WebGetCurrentLocalRes(&head); break;
            case SERVER_CMD_WEB_MULTIPLE_BEDTEMP_REQ: WebMultipleBedTempRes(&head); break;
            //case SERVER_CMD_WEB_SYSTEM_RESET_ANS: WebStartSystemResetAns(&head); break;
            case SERVER_CMD_WEB_GET_DEVICE_STATE_REQ: ManagerDeviceStateChange(&head); break;
            case SERVER_CMD_WEB_GET_DELAY_IMAGE_PRE_REQ: UserWebGetDelayImagePreferReq(&head); break;
            case SERVER_CMD_WEB_GET_POWER_LOSS_PRE_REQ: UserWebGetPowerLossPreferReq(&head); break;
            case SERVER_CMD_WEB_GET_AI_CONTROL_PRE_REQ: UserAppGetAiControlPreferReq(&head); break;
            case SERVER_CMD_WEB_GET_AUTO_PID_PRE_REQ:UserWebGetAutoPidPreferReq(&head); break;
            case SERVER_CMD_WEB_CHECK_UPGRADE_REQ:UserWebGetUpgradeInfoReq(&head); break;
            case SERVER_CMD_WEB_CONTROL_LOCAL_VIDEO:UserAppFileControlReq(&head); break;
            case SERVER_CMD_WEB_SYNC_EXPORT_LOG_STATE:WebSyncExportLogState(&head); break;
            case SERVER_CMD_WEB_GET_PRINT_OBJECT_RES: ManagerSyncPrintObjectInfo(&head); break;

            case MANAGER_SYNC_SYSTEM_CONFIG: WebGetSystemConfigRes(&head); break;
            case MANAGER_SYNC_PRINT_SAVE_PARA: WebGetPrintSaveParaRes(&head); break;
            case MANAGER_SYNC_PRINT_WORK_INFO: ManagerSyncPrintWorkInfo(&head); break;
            case MANAGER_SYNC_DEV_UPGRADE_STATE: ManagerSyncUpgradeState(&head); break;
            case MANAGER_CMD_SYNC_DELAY_IMAGE_CONFIG: UserWebGetDelayImagePreferReq(&head); break;
            case MANAGER_CMD_SYNC_POWER_LOSS_CONFIG: UserWebGetPowerLossPreferReq(&head); break;
            case MANAGER_CMD_SYNC_AI_CONTROL_CONFIG: UserAppGetAiControlPreferReq(&head); break;
            case MANAGER_CMD_SYNC_TEMP_AUTO_CONFIG: UserWebGetAutoPidPreferReq(&head); break;
            case MANAGER_CMD_SYNC_UPGRADE_REBOOT_INFO: ManagerSyncUpgradeRebootInfo(&head); break;
            case MANAGER_CMD_SYNC_PRINT_OBJECT_INFO: ManagerSyncPrintObjectInfo(&head); break;
            
            case MANAGER_CMD_GCODE_GET_SD_FILE_ANS: UserGetGcodeFileListAns(&head); break;
            case MANAGER_CMD_GCODE_GET_SD_MODEL_IMAGE_ANS: UserGetSdGcodeImageAns(&head); break;
            case MANAGER_CMD_GCODE_START_PRINT_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_START_CLOUD_PRINT_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_PAUSE_PRINT_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_RESUME_PRINT_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_STOP_PRINT_ANS: UserWebControlPrintAns(&head); break;
            // case MANAGER_CMD_POWER_OFF_CONTINUE_ANS: UserWebControlPrintAns(&head); break;
            // case MANAGER_CMD_CANCEL_POWER_OFF_CONTINUE_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_OPEN_FAN_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_STOP_FAN_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_NOZZLE_TEMP_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_BED_TEMP_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_GET_HOTEND_XYZ_LOCAL_ANS: UserGetHotendXyzLocalAns(&head); break;
            case MANAGER_CMD_GCODE_RETURN_HOME_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_HOTEND_XYZ_MOVE_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_PRINT_SPEED_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_PRINT_FLOW_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_GCODE_MACRO_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_MOTOR_LOCK_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_MOTOR_UNLOCK_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_STOP_ALL_HEAT_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_MATERIAL_DELECT_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_POWER_LOSS_SW_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_MAX_SPEED_REQ: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_MAX_ACCELERATION_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_MAX_CORNER_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_MAX_JERK_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_PRESSURE_ADVANCE_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_SMOOTH_TIME_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_START_TEMP_AUTO_PID_ANS:UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_RESONANCE_TEST_ANS:UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_DEVICE_AUTO_LEVEL_ANS:UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_RESTART_KLIPPER_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_GCODE_SET_FIRMWARE_RESTART_ANS: UserWebControlPrintAns(&head); break;
            case MANAGER_CMD_SYSTEM_RESET_ANS: UserSetSystemResetAns(&head); break;
            case MANAGER_CMD_REPORT_AUTO_LEVEL_RESULT: UserReportAutoLevelResult(&head); break;
            case MANAGER_CMD_GET_UPGRADE_INFO_ANS: UserGetUpgradeInfoAns(&head); break;
            case MANAGER_DEVICE_STATE_CHANGE: ManagerDeviceStateChange(&head); break;
            case MANAGER_CMD_GCODE_SET_EXCLUDE_OBJECT_ANS: UserWebControlPrintAns(&head); break;

            case SERVER_CMD_WEB_TEST_ANS: ServerMessageTestAns(&head); break;
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
MsgHandle_t *WebManagerInit(void *arg)
{
    CrLogI("web manager init");
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
int WebManagerExceptionHandleSemPost(void)
{
    return 0;
}
