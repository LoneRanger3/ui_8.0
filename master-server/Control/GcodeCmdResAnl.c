/*
 * @Description : gcode命令响应数据解析
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-17 13:51:38
 * @LastEditTime: 2023-11-02 21:14:11
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <regex.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <unistd.h>

#include "Base/MasterMsgBase.h"
#include "PrintControl.h"
#include "DefineGcode.h"
#include "GcodeCmdResAnl.h"
#include "SocketKlipper.h"

#include "Controller.h"
#include "AppPrint.h"
#include "AppModeAutoPrint.h"
#include "AppFuncModule.h"

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static bool autoResponseProcessed = false;
static ControlRange_t userGetGcodeImageFIleId;
static int userSetAutoPidTimes = 0; // 设置自动PID次数
static pidPara_t curAutoPidResult = {0};
static int curAutoLevelPointNum = 0; // 当前自动调平完成的点号
static bool syncKlipperConfigFile = true; // 应用同步klipper配置文件
static bool syncContinuePrint = true; // 应用同步klipper断连续打信息

/**
 * @description: 
 * @return {*}
 * @param {bool} flag
 */
void SetSyncKlipperConfigFile(bool flag) { syncKlipperConfigFile = flag; }

/**
 * @description: 
 * @return {*}
 */
bool GetSyncKlipperConfigFile(void) { return syncKlipperConfigFile; }

/**
 * @description: 
 * @return {*}
 * @param {bool} flag
 */
void SetSyncContinuePrint(bool flag) { syncContinuePrint = flag; }

/**
 * @description: 
 * @return {*}
 */
bool GetSyncContinuePrint(void) { return syncContinuePrint; }

/**
 * @description: 
 * @return {*}
 * @param {double} dutyCycle
 */
static int DutyCycleToPercentage(double dutyCycle) { return (dutyCycle * 255 + 0.5); }

/**
 * @description: 
 * @return {*}
 * @param {double} value
 * @param {MultiFan_t} num
 */
static int FloatToPercentage(double value, MultiFan_t num)
{
    int fanMin = 0;
    switch (num) {
        case MULTI_FAN_MODEL: fanMin = GetPrinter()->gcode_macro_Printer_Param.fan0_min; break;
        case MULTI_FAN_CASE: fanMin = GetPrinter()->gcode_macro_Printer_Param.fan1_min; break;
        case MULTI_FAN_AUXILIARY: fanMin = GetPrinter()->gcode_macro_Printer_Param.fan2_min; break;
        default: fanMin = 0; break;
    }

    double dutyCycle = value * 255;
    if (dutyCycle <= fanMin) return 0;
    if (dutyCycle >= 255) return 100;

    return ((dutyCycle - fanMin) / (255 - fanMin) * 100 + 0.5); 
}

/**
 * @description: 
 * @return {*}
 */
int ClearcurAutoLevelPointNum(void) { curAutoLevelPointNum = 0; return 0; }

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} times
 */
int setUserSetAutoPidTimes(int times) { userSetAutoPidTimes = times; return 0; }

/**
 * @description: 
 * @return {*}
 * @param {int} times
 */
static int ClearUserActivePause(void) { UpdataPrintPauseStatus(PAUSE_STATUS_IDLE); return 0; }

/**
 * @description: 
 * @return {*}
 */
static int ClearCurAutoPidResult(void) { memset(&curAutoPidResult, 0, sizeof(pidPara_t)); return 0; }

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {ControlRange_t} id
 */
void SetUserGetGcodeImageEndFileId(ControlRange_t id)
{
    userGetGcodeImageFIleId = id;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
ControlRange_t GetUserGetGcodeImageEndFileId(void)
{
    return userGetGcodeImageFIleId;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSerialPortHandshakeResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Serial Port Handshake result = %d", result);
    if (result)
    {
        // 清空链表中非打印指令和握手指令
        ClearSendGcodeListNoPrintCmd();
        // 获取打印机保存参数
        MsaterShareStateInit();
        // 串口已连接
        UpdataSerialPort(1);
        UpdataSdCardExists(1);
    }
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSelectSdFileResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("select print file result = %d", result);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseStartPrintFileResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("start print file result = %d", result);
    GcodeCmdRes start = GCODE_CMD_RES__INIT;
    start.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&start, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_START_PRINT_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponsePausePrintFileResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("pause print file result = %d", result);
    GcodeCmdRes pause = GCODE_CMD_RES__INIT;
    pause.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&pause, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_PAUSE_PRINT_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseResumePrintFileResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("resume print file result = %d", result);
    GcodeCmdRes resume = GCODE_CMD_RES__INIT;
    resume.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&resume, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_RESUME_PRINT_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseStopPrintFileResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("stop print file result = %d", result);
    GcodeCmdRes stop = GCODE_CMD_RES__INIT;
    stop.result = result;
    if (result)
    {
        SetAppModeChange(APP_MODE_IDLE);
    }
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&stop, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_STOP_PRINT_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 * @param undefined
 * @param undefined
 * @param undefined
 */
static int ResponseParkHeadPrintResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Park Head Print result = %d", result);
    ClearUserActivePause();
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 * @param undefined
 * @param undefined
 * @param undefined
 */
static int ResponseBreakContinueResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Break Continue result = %d", result);
    ClearUserActivePause();
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseStopHeatingResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("stop temp heating result = %d", result);
    GcodeCmdRes stop = GCODE_CMD_RES__INIT;
    stop.result = result;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&stop, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_STOP_HEATING_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseDevReturnHomeResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("device return home result = %d", result);
    GcodeCmdRes home = GCODE_CMD_RES__INIT;
    home.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&home, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_RETURN_HOME_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseControlMoveResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("control xyz move result = %d", result);
    GcodeCmdRes move = GCODE_CMD_RES__INIT;
    move.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&move, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_HOTEND_XYZ_MOVE_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseAxisRecoupResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("set Axis Recoup result = %d", result);
    GcodeCmdRes offset = GCODE_CMD_RES__INIT;
    offset.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_DEVICE_ADVANCE_SET;
    tCmd.len = strlen(GET_DEVICE_ADVANCE_SET);
    AddGcodeListCmd(GET_DEVICE_ADVANCE_SET_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&offset, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_AXIS_RECOUP_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseHomeOffsetParaResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("set Home Offset result = %d", result);
    GcodeCmdRes offset = GCODE_CMD_RES__INIT;
    offset.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_DEVICE_ADVANCE_SET;
    tCmd.len = strlen(GET_DEVICE_ADVANCE_SET);
    AddGcodeListCmd(GET_DEVICE_ADVANCE_SET_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&offset, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_HOME_OFFSET_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseMotorLockResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("motor lock result = %d", result);
    GcodeCmdRes lock = GCODE_CMD_RES__INIT;
    lock.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&lock, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MOTOR_LOCK_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseMotorUnlockResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("motor unlock result = %d", result);
    GcodeCmdRes unlock = GCODE_CMD_RES__INIT;
    unlock.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&unlock, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MOTOR_UNLOCK_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetNozzleTempResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Nozzle Temp result = %d", result);
    GcodeCmdRes temp = GCODE_CMD_RES__INIT;
    temp.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_CUR_HOTEND_BED_TEMP;
    tCmd.len = strlen(GET_CUR_HOTEND_BED_TEMP);
    AddGcodeListCmd(GET_CUR_HOTEND_BED_TEMP_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&temp, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_NOZZLE_TEMP_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetBedTempResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Bed Temp result = %d", result);
    GcodeCmdRes temp = GCODE_CMD_RES__INIT;
    temp.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_CUR_HOTEND_BED_TEMP;
    tCmd.len = strlen(GET_CUR_HOTEND_BED_TEMP);
    AddGcodeListCmd(GET_CUR_HOTEND_BED_TEMP_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&temp, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_BED_TEMP_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseContolOpenFanResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Contol Open Fan result = %d", result);
    GcodeCmdRes fan = GCODE_CMD_RES__INIT;
    fan.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&fan, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_OPEN_FAN_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseContolStopFanResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Contol Stop Fan result = %d", result);
    GcodeCmdRes fan = GCODE_CMD_RES__INIT;
    fan.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&fan, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_STOP_FAN_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseAbsolutePositioningResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Absolute Positioning result = %d", result);
    GcodeCmdRes positioning = GCODE_CMD_RES__INIT;
    positioning.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&positioning, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_ABSOLUTE_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseRelativePositioningResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Relative Positioning result = %d", result);
    GcodeCmdRes positioning = GCODE_CMD_RES__INIT;
    positioning.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&positioning, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_RELATIVE_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseDeviceAutoLevelResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Device Auto Level result = %d", result);
    GcodeCmdRes level = GCODE_CMD_RES__INIT;
    level.result = result;
    UpdataAutoLevelProgress(100);
    CrLogI("auto level current progress = %d%%", GetPrintState().autoLevelProgress);

    String_t tCmd = {0};
    // 获取调平点数
    tCmd.data = CXSW_SET_LEVEL_POINTS;
    tCmd.len = strlen(CXSW_SET_LEVEL_POINTS);
    AddGcodeListCmd(CXSW_GET_LEVEL_POINTS_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    // 获取调平值
    tCmd.data = GET_DEVICE_ADVANCE_SET;
    tCmd.len = strlen(GET_DEVICE_ADVANCE_SET);
    AddGcodeListCmd(GET_DEVICE_ADVANCE_SET_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&level, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_DEVICE_AUTO_LEVEL_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetHotendTempPidResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Hotend Temp Pid result = %d", result);
    GcodeCmdRes pid = GCODE_CMD_RES__INIT;
    pid.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_DEVICE_ADVANCE_SET;
    tCmd.len = strlen(GET_DEVICE_ADVANCE_SET);
    AddGcodeListCmd(GET_DEVICE_ADVANCE_SET_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&pid, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_HOTEND_PID_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetBedTempPidResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Bed Temp Pid result = %d", result);
    GcodeCmdRes pid = GCODE_CMD_RES__INIT;
    pid.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_DEVICE_ADVANCE_SET;
    tCmd.len = strlen(GET_DEVICE_ADVANCE_SET);
    AddGcodeListCmd(GET_DEVICE_ADVANCE_SET_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&pid, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_BED_PID_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseControlDeviceResetResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Control Device Reset result = %d", result);
    GcodeCmdRes reset = GCODE_CMD_RES__INIT;
    reset.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&reset, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_DEVICE_RESET_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetDevResetSaveResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Dev Reset Save result = %d", result);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CONTROL_SYSTEM_REBOOT, "", 0);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetStepValueResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Step Value result = %d", result);
    GcodeCmdRes max = GCODE_CMD_RES__INIT;
    max.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_DEVICE_ADVANCE_SET;
    tCmd.len = strlen(GET_DEVICE_ADVANCE_SET);
    AddGcodeListCmd(GET_DEVICE_ADVANCE_SET_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&max, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_STEP_VALUE_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetMaxAccelerationResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Max Acceleration result = %d", result);
    GcodeCmdRes max = GCODE_CMD_RES__INIT;
    max.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_DEVICE_ADVANCE_SET;
    tCmd.len = strlen(GET_DEVICE_ADVANCE_SET);
    AddGcodeListCmd(GET_DEVICE_ADVANCE_SET_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&max, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MAX_ACCELERATION_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetMaxSpeedResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Max Speed result = %d", result);
    GcodeCmdRes max = GCODE_CMD_RES__INIT;
    max.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_DEVICE_ADVANCE_SET;
    tCmd.len = strlen(GET_DEVICE_ADVANCE_SET);
    AddGcodeListCmd(GET_DEVICE_ADVANCE_SET_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&max, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MAX_SPEED_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetMaxJerkResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Max Jerk result = %d", result);
    GcodeCmdRes max = GCODE_CMD_RES__INIT;
    max.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_DEVICE_ADVANCE_SET;
    tCmd.len = strlen(GET_DEVICE_ADVANCE_SET);
    AddGcodeListCmd(GET_DEVICE_ADVANCE_SET_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&max, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MAX_JERK_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetMaterialDelectResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Material Delect result = %d", result);
    GcodeCmdRes sw = GCODE_CMD_RES__INIT;
    sw.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_DEVICE_ADVANCE_SET;
    tCmd.len = strlen(GET_DEVICE_ADVANCE_SET);
    AddGcodeListCmd(GET_DEVICE_ADVANCE_SET_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&sw, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MATERIAL_DELECT_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetPowerLossSwResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Power loss sw result = %d", result);
    GcodeCmdRes sw = GCODE_CMD_RES__INIT;
    sw.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_DEVICE_ADVANCE_SET;
    tCmd.len = strlen(GET_DEVICE_ADVANCE_SET);
    AddGcodeListCmd(GET_DEVICE_ADVANCE_SET_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&sw, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_POWER_LOSS_SW_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetPrintSpeedResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Print Speed result = %d", result);
    GcodeCmdRes speed = GCODE_CMD_RES__INIT;
    speed.result = result;

    String_t tCmd = {0};
    tCmd.data = GET_DEVICE_PRINT_SPEED;
    tCmd.len = strlen(GET_DEVICE_PRINT_SPEED);
    AddGcodeListCmd(GET_DEVICE_PRINT_SPEED_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&speed, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_PRINT_SPEED_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetCrTouchResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Cr Touch result = %d", result);
    GcodeCmdRes touch = GCODE_CMD_RES__INIT;
    touch.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&touch, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_CR_TOUCH_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetStartHotendAutoPidResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Start Hotend Auto Pid result = %d", result);
    
    if (result) {
        // 发送交互确认，是否保存
        PidInfo pidRes = PID_INFO__INIT;
        pidRes.p = curAutoPidResult.p;
        pidRes.i = curAutoPidResult.i;
        pidRes.d = curAutoPidResult.d;

        AutoPidResult sendPid = AUTO_PID_RESULT__INIT;
        sendPid.hotend = &pidRes;

        GET_MESSAGE_BUFF(buff);
        size_t len = auto_pid_result__pack(&sendPid, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_AUTO_PID_RESULT_CONFIRM_REMIND, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
        ClearCurAutoPidResult();
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetStartHotbedAutoPidResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Start Hotbed Auto Pid result = %d", result);

    if (result) {
        // 发送交互确认，是否保存
        PidInfo pidRes = PID_INFO__INIT;
        pidRes.p = curAutoPidResult.p;
        pidRes.i = curAutoPidResult.i;
        pidRes.d = curAutoPidResult.d;

        AutoPidResult sendPid = AUTO_PID_RESULT__INIT;
        sendPid.hotbed = &pidRes;

        GET_MESSAGE_BUFF(buff);
        size_t len = auto_pid_result__pack(&sendPid, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_AUTO_PID_RESULT_CONFIRM_REMIND, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
        ClearCurAutoPidResult();
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetParaSaveConfigResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Print save config result = %d", result);
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = result;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_SAVE_CONFIG_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseSetInsertFilamentResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Set Insert Filament result = %d", result);
    if (result)
    {
        if (GetPrintState().materialStatus[MATERIAL_DETECTOR_1] == MATERIAL_STATUS_COOLING)
            UpdataPrintMaterialStatus(MATERIAL_STATUS_HEATING, MATERIAL_DETECTOR_1);
        else
            UpdataPrintMaterialStatus(MATERIAL_STATUS_IDLE, MATERIAL_DETECTOR_1);
    }
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseCxswGetPrintStatusResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Cxsw Get Print Status result = %d", result);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseCxswGetPrintDevInfoResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Cxsw Get Print Dev Info result = %d", result);
    CrLogD("Print Dev Info = %s", buf);
    
    if (result && !strstr(buf, UNDEFINED_COMMAND))
    {
        // 命令原型：M8004
        // 功能：查询固件的版本号和机器型号
        // 参数：无
        // 方向：应用软件发送给嵌入式软件。
        // 回复：Model:Ender3 Pro;Version:1.0.2;Size:Lengthx width xheight;
        // OK
        // 例如：Model:Ender-3 V2;Version:1.0;Size:220x220x250
        // 注意：size是打印机工作空间的大小，分别是X轴宽度，Y轴宽度和Z轴高度。
        char *Model = NULL, *Version = NULL, *length = NULL, *width = NULL, *height = NULL;
        int tempCount = 0;
        char *strtokContext1 = NULL;
        char *info = strtok_r(buf, ";", &strtokContext1);
        while (info)
        {
            tempCount++;
            switch (tempCount)
            {
                case 1: Model = strstr(info, "Model:") + strlen("Model:"); break;
                case 2: Version = strstr(info, "Version:") + strlen("Version:"); break;
                case 3:
                {
                    char *Size = strstr(info, "Size:") + strlen("Size:");
                    int count = 0;
                    char *strtokContext2 = NULL;
                    char *num = strtok_r(Size, "x", &strtokContext2);
                    while (num)
                    {
                        count++;
                        switch (count)
                        {
                            case 1: length = num; break;
                            case 2: width = num; break;
                            case 3: height = num; break;
                        }
                        num = strtok_r(NULL, "x", &strtokContext2);
                    }
                }break;
            }
            info = strtok_r(NULL, ";", &strtokContext1);
        }
        
        int devLength = 0, devWidth = 0, devHeight = 0;
        if (length) devLength = atoi(length);
        if (width) devWidth = atoi(width);
        if (height) devHeight = atoi(height);
        CrLogI("==============================");
        if (Model) CrLogI("Model = %s", Model);
        if (Version) CrLogI("Version = %s", Version);
        CrLogI("length = %d", devLength);
        CrLogI("width = %d", devWidth);
        CrLogI("height = %d", devHeight);
        CrLogI("==============================\n");

        // 保存到配置文件
        SystemConfigProto config = SYSTEM_CONFIG_PROTO__INIT;
        config.has_model_str = 1;
        config.model_str.data = (uint8_t*)Model;
        config.model_str.len = strlen(Model);
        config.has_fw_version = 1;
        config.fw_version.data = (uint8_t*)Version;
        config.fw_version.len = strlen(Version);
        config.has_bed_length = 1;
        config.bed_length = devLength;
        config.has_bed_width = 1;
        config.bed_width = devWidth;
        config.has_bed_hight = 1;
        config.bed_hight = devHeight;
        UpdataSystemConfig(&config);
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseCxswSetOffsetAndTimeResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Cxsw Set Offset And Time result = %d", result);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseCxswSetPrintFileInfoResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Cxsw Cxsw Set Print File Info result = %d", result);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseCxswGetPowerLossResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Cxsw Get Power loss result = %d", result);
    CrLogD("Power loss info = %s", buf);

    if (result && !strstr(buf, UNDEFINED_COMMAND))
    {
        char *filename = NULL, *offset = NULL, *elapsedtime = NULL, *count = NULL;
        int tempCount = 0;
        char *strtokContext = NULL;
        char *info = strtok_r(buf, ";", &strtokContext);
        while (info)
        {
            tempCount++;
            switch (tempCount)
            {
                case 1: filename = strstr(info, "filename:") + strlen("filename:"); break;
                case 2: offset = strstr(info, "offset:") + strlen("offset:"); break;
                case 3: elapsedtime = strstr(info, "elapsedtime:") + strlen("elapsedtime:"); break;
                case 4: count = strstr(info, "count:") + strlen("count:"); break;
            }
            info = strtok_r(NULL, ";", &strtokContext);
        }
        // 获取断电续打文件名, 如果文件名为空，则没有断电续打任务
        if (filename && strlen(filename) > 0)
        {
            PowerLossInfo_t fileInfo;
            memset(&fileInfo, 0, sizeof(PowerLossInfo_t));
            memcpy(fileInfo.fileName, filename, strlen(filename));
            fileInfo.fileOffset = atoi(offset);
            fileInfo.usedTime = atoi(elapsedtime);
            fileInfo.cmdCount = atoi(count);

            CrLogI("==============================");
            CrLogI("power loss info");
            CrLogI("filename = %s", fileInfo.fileName);
            CrLogI("offset = %d", fileInfo.fileOffset);
            CrLogI("elapsedtime = %d", fileInfo.usedTime);
            CrLogI("count = %d", fileInfo.cmdCount);
            CrLogI("==============================\n");
            SavePowerLossPrintInfo(fileInfo);
        }
        else CrLogI("No power outage to resume the task\n");
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseCxswSetStopPirintResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Cxsw Set Stop Pirint result = %d", result);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseCxswSetPaueResumeResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Cxsw Set Paue Resume result = %d", result);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseCxswStartAutoRecoupResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Cxsw Start Auto Recoup result = %d", result);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseCxswGetLevelPointsResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Cxsw Get Level Points result = %d", result);
    CrLogD("Level Points = %s", buf);

    if (result && !strstr(buf, UNDEFINED_COMMAND))
    {
        char *resData = strstr(buf, "ok ");
        if (!resData) return -1;

        resData = resData + strlen("ok ");
        // 解析数据
        char *S = NULL, *X = NULL, *Y = NULL;
        char *strtokContext = NULL;
        char *dataAnl = strtok_r(resData, " ", &strtokContext);
        while (dataAnl)
        {
            if (strstr(dataAnl, "S")) S = strstr(dataAnl, "S") + strlen("S");
            if (strstr(dataAnl, "X")) X = strstr(dataAnl, "X") + strlen("X");
            if (strstr(dataAnl, "Y")) Y = strstr(dataAnl, "Y") + strlen("Y");
            dataAnl = strtok_r(NULL, " ", &strtokContext);
        }

        int s_int = 0, x_int = 0, y_int = 0;
        if (S) s_int = atoi(S);
        if (X) x_int = atoi(X);
        if (Y) y_int = atoi(Y);
        CrLogI("==============================");
        CrLogI("S  = %d", s_int);
        CrLogI("X  = %d", x_int);
        CrLogI("Y  = %d", y_int);
        CrLogI("==============================");

        // 更新打印机保存数据
        PrintSavePara_t updataPara = GetPrintSavePara();
        updataPara.levelPoints.x = x_int;
        updataPara.levelPoints.y = y_int;
        UpdataPrintSavePara(updataPara);
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseCxswSetLevelPointsResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Cxsw Set Level Points result = %d", result);
    CrLogD("Level Points = %s", buf);

    if (result && !strstr(buf, UNDEFINED_COMMAND))
    {
        // 获取调平点数
        String_t tCmd = {0};
        tCmd.data = CXSW_SET_LEVEL_POINTS;
        tCmd.len = strlen(CXSW_SET_LEVEL_POINTS);
        AddGcodeListCmd(CXSW_GET_LEVEL_POINTS_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);
    }

    // 应答
    GcodeCmdRes points = GCODE_CMD_RES__INIT;
    points.result = result;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&points, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_AUTO_LEVEL_POINTS_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
} 

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseCxswSetActivelyAcquireResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Cxsw Set Actively Acquire result = %d", result);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} len
 * @param {int} result
 */
int getTempFromResponseData(char *buf, int bufLen, int result)
{
    if (!result)
    {
        CrLogW("The serial port connection is abnormal!\n");
        return -1;
    }
    if (strstr(buf, UNDEFINED_COMMAND)) return -1;

    char *regex = "[-|+]?[0-9]{1,3}.[0-9]{2}";
    regmatch_t regmatch[5];
    int regexSize = UserGetRegexStr(buf, regex, regmatch, 5);

    int temp[5] = {0};
    for(int i = 0; i< regexSize; i++)
    {
        int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &buf[regmatch[i].rm_so], cnt);
        str[cnt] = '\0';
        float temp_f = atof(str) * 100 + 0.5;
        temp[i] = temp_f;
    }

    CrLogI("T0 = %d, T1 = %d, B0 = %d, B1 = %d", temp[0], temp[1], temp[2], temp[3]);
    UpdataNozzleCurTemp(temp[0], NOZZLE_TEMP);
    UpdataNozzleMaxTemp(temp[1], NOZZLE_TEMP);
    UpdataBedCurTemp(temp[2], HOTBED_TEMP);
    UpdataBedMaxTemp(temp[3], HOTBED_TEMP);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {dirent} *entry
 */
static int FindDirAndGcode(const struct dirent *entry)
{
    if ((entry->d_type != 4 && entry->d_type != 8) ||
        strcmp(".", entry->d_name) == 0 ||
        strcmp("..", entry->d_name) == 0 ||
        entry->d_name[0] == '.' ||
        (entry->d_type == 4 && strstr(entry->d_name, "System Volume Information")) ||
        (entry->d_type == 8 && strlen(entry->d_name) < strlen(".gcode")) || 
        (entry->d_type == 8 && strcmp(entry->d_name + (strlen(entry->d_name) - strlen(".gcode")), ".gcode")))
    {
        return 0;
    }
    return 1;
}

static const char *TempSortPath = NULL;
/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {dirent} *
 * @param {dirent} *
 */
static inline int SortByTime(const struct dirent **a, const struct dirent **b)
{
    struct stat sbuf1, sbuf2;
    char path1[PATH_MAX], path2[PATH_MAX];

    snprintf(path1, PATH_MAX, "%s/%s", TempSortPath, (*a)->d_name);
    snprintf(path2, PATH_MAX, "%s/%s", TempSortPath, (*b)->d_name);

    if (lstat(path1, &sbuf1)) return 0;
    if (lstat(path2, &sbuf2)) return 0;

    return sbuf1.st_mtim.tv_sec - sbuf2.st_mtim.tv_sec;
}

/**
 * @description: 
 * @return {*}
 * @param {dirent} *
 * @param {dirent} *
 */
static inline int SortBySize(const struct dirent **a, const struct dirent **b)
{
    struct stat sbuf1, sbuf2;
    char path1[PATH_MAX], path2[PATH_MAX];

    snprintf(path1, PATH_MAX, "%s/%s", TempSortPath, (*a)->d_name);
    snprintf(path2, PATH_MAX, "%s/%s", TempSortPath, (*b)->d_name);

    if (lstat(path1, &sbuf1)) return 0;
    if (lstat(path2, &sbuf2)) return 0;

    return sbuf1.st_size - sbuf2.st_size;
}

/**
 * @description: 
 * @return {*}
 * @param {dirent} *
 * @param {dirent} *
 */
static inline int SortByMode(const struct dirent **a, const struct dirent **b)
{
    struct stat sbuf1, sbuf2;
    char path1[PATH_MAX], path2[PATH_MAX];

    snprintf(path1, PATH_MAX, "%s/%s", TempSortPath, (*a)->d_name);
    snprintf(path2, PATH_MAX, "%s/%s", TempSortPath, (*b)->d_name);

    if (lstat(path1, &sbuf1)) return 0;
    if (lstat(path2, &sbuf2)) return 0;

    return sbuf1.st_mode - sbuf2.st_mode;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} fd
 * @param {char} *path
 * @param {int} curSum
 */
static int readLocalGcodeFileList(int fd, char *path, int sort, int curSum)
{
    TempSortPath = path;
    CrLogI("gcode file path = %s", TempSortPath);
    // 按照制定的规则顺序，获取文件个数和文件名称
    struct dirent **entry_list = NULL;
    int count = 0;
    switch (sort) {
        case FILE_NAME_POSITIVE_SORT:
        case FILE_NAME_REVERSE_SORT: count = scandir(path, &entry_list, FindDirAndGcode, alphasort); break;
        case FILE_TIME_POSITIVE_SORT:
        case FILE_TIME_REVERSE_SORT: count = scandir(path, &entry_list, FindDirAndGcode, SortByTime); break;
        case FILE_MODE_POSITIVE_SORT:
        case FILE_MODE_REVERSE_SORT: count = scandir(path, &entry_list, FindDirAndGcode, SortByMode); break;
        case FILE_SIZE_POSITIVE_SORT:
        case FILE_SIZE_REVERSE_SORT: count = scandir(path, &entry_list, FindDirAndGcode, SortBySize); break;

        default: count = scandir(path, &entry_list, FindDirAndGcode, alphasort); break;
    }
    if (count < 0) {
        CrLogW("Wrong path “%s”, error = %s\n", path, strerror(errno));
        return -1;
    }

    // 获取文件信息
    for (int i = 0; i < count; i++)
    {
        // 判断是否是倒序
        int sort_selec = i;
        if (sort == FILE_NAME_REVERSE_SORT || sort == FILE_TIME_REVERSE_SORT ||
            sort == FILE_MODE_REVERSE_SORT || sort == FILE_SIZE_REVERSE_SORT)
            sort_selec = count - 1 - i;

        // 提取文件信息
        struct dirent *entry = entry_list[sort_selec];
        struct json_object *fileInfo = json_object_new_object();
        json_object_object_add(fileInfo, "fileId", json_object_new_int(++curSum));
        if (entry->d_type == 4) json_object_object_add(fileInfo, "type", json_object_new_int(CACHE_PATH_TYPE_DIR));
        else json_object_object_add(fileInfo, "type", json_object_new_int(CACHE_PATH_TYPE_FILE));

        int dir_path_len = strlen(path) + entry->d_reclen + 10;
        char dir_path[dir_path_len];
        memset(dir_path, 0, dir_path_len);
        sprintf(dir_path, "%s/%s", path, entry->d_name);
        json_object_object_add(fileInfo, "fileName", json_object_new_string_len(dir_path, strlen(dir_path)));

        struct stat stat_info;
        int ret = lstat(dir_path, &stat_info);
        if (ret == -1)
        {
            CrLogW("%s get info error !", dir_path);
            JsonWriteToFile(fd, fileInfo);
            json_object_put(fileInfo);
            free(entry);
            continue;
        }
        json_object_object_add(fileInfo, "fileSize", json_object_new_int(stat_info.st_size));
        json_object_object_add(fileInfo, "cTime", json_object_new_int(stat_info.st_ctim.tv_sec));
        json_object_object_add(fileInfo, "thumbnail", json_object_new_string_len("", 0));
        json_object_object_add(fileInfo, "timeCost", json_object_new_int(0));
        json_object_object_add(fileInfo, "consumables", json_object_new_int(0));
        json_object_object_add(fileInfo, "floorHeight", json_object_new_int(0));
        json_object_object_add(fileInfo, "modelX", json_object_new_int(0));
        json_object_object_add(fileInfo, "modelY", json_object_new_int(0));
        json_object_object_add(fileInfo, "modelZ", json_object_new_int(0));
        json_object_object_add(fileInfo, "material", json_object_new_string_len("", 0));
        json_object_object_add(fileInfo, "nozzleTemp", json_object_new_int(0));
        json_object_object_add(fileInfo, "bedTemp", json_object_new_int(0));
        json_object_object_add(fileInfo, "software", json_object_new_string_len("", 0));

        CrLogI("fileId = %d, name = %s, fileSize = %d", curSum, dir_path, stat_info.st_size);
        JsonWriteToFile(fd, fileInfo);
        json_object_put(fileInfo);
        free(entry);
    }
    free(entry_list);

    return curSum;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int GetLocalGcodeFileInfo(char *traversePath, int sort, char *cachePath)
{
    CrLogI("start get local gcode file info");
    if (access(GetUserTempDirPtah(), F_OK) != 0)
    {
        char cmd[254] = {0};
        snprintf(cmd, 254, "mkdir -p %s", GetUserTempDirPtah());
        
        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    // 在临时目录创建保存信息文件
    int saveSdFileInfoFd = open(cachePath, O_RDWR | O_CREAT | O_TRUNC , S_IRWXG | S_IRWXO | S_IRWXU);
    if(saveSdFileInfoFd < 0)
    {
        CrLogE("open %s failed.Fd = %d.", cachePath, saveSdFileInfoFd);
    }

    // 设置文件总数json对象
    struct json_object *fileSum = json_object_new_object();
    json_object_object_add(fileSum, "fileSum", json_object_new_int(0));
    JsonWriteToFile(saveSdFileInfoFd, fileSum);
    json_object_put(fileSum);

    // 读取文件
    int curSum = readLocalGcodeFileList(saveSdFileInfoFd, traversePath, sort, 0);
    if (curSum == 0)
    {
        CrLogW("current local no gcode file\n");
    }
    
    // gcode文件信息接收完成，关闭文件
    close(saveSdFileInfoFd);
    saveSdFileInfoFd = -1;
    SaveSdFileTotalNumber(cachePath, curSum);

    CrLogI("save local gcode file info finish\n");
    return curSum;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseGetGcodeFileResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Get Gcode File result = %d", result);
    if (result)
    {
        if (strstr(buf, SD_CARD_NO_MEDIA))
        {
            CrLogI("The printer does not have an SD card\n");
        }

        // 应答文件总数
        int fileSum = GetSaveSdFileTotalNumber(GetUserGcodeFileInfoFilePath());
        GcodeCmdRes sdFileSum = GCODE_CMD_RES__INIT;
        sdFileSum.result = fileSum >= 0 ? 1 : 0;
        sdFileSum.has_resstr = 1;
        sdFileSum.resstr.data = (uint8_t *)&fileSum;
        sdFileSum.resstr.len = sizeof(int);
        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd_res__pack(&sdFileSum, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_GET_SD_FILE_ANS, buff, len);
        MANAGER_MSG_SEND(cmd.origin, &send, size);
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseGetGcodeFileImageResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Get Gcode File Image result = %d", result);
    if (result) SaveLocalGcodeImageToFile(GetUserGcodeFileInfoFilePath(), cmd.origin, result);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseGetGcodeFilePhotoResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Get Gcode File photo result = %d", result);
    
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseGetXyzLocalResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    GET_MESSAGE_BUFF(localBuff);
    size_t localLen = 0;
        
    GcodeCmdRes hotendLocal = GCODE_CMD_RES__INIT;
    hotendLocal.result = result;
    if (result && !strstr(buf, UNDEFINED_COMMAND))
    {
        char *regex = "[-|+]?[0-9]{1,3}.[0-9]{2}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(buf, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &buf[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            float temp_f = atof(str) * 100 + 0.5;
            temp[i] = temp_f;
        }

        CrLogI("X = %d, Y = %d, Z = %d, E = %d", temp[0], temp[1], temp[2], temp[3]);
        
        AxisPara local = AXIS_PARA__INIT;
        local.has_x = 1;
        local.x = temp[0];
        local.has_y = 1;
        local.y = temp[1];
        local.has_z = 1;
        local.z = temp[2];
        local.has_e = 1;
        local.e = temp[3];
        localLen = axis_para__pack(&local, localBuff);

        hotendLocal.has_resstr = 1;
        hotendLocal.resstr.data = localBuff;
        hotendLocal.resstr.len = localLen;
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&hotendLocal, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_GET_HOTEND_XYZ_LOCAL_ANS, buff, len);
    MANAGER_MSG_SEND(cmd.origin, &send, size);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
static int GetHotendTempPid(char *buf, int bufLen, PrintSavePara_t *para)
{
    char tempPid[100] = {0};
    char *M301 = strstr(buf, "M301");
    if (M301)
    {
        char *M301End = strchr(M301, '\n');
        memcpy(tempPid, M301, M301End - M301);
        CrLogI("temp Pid = %s", tempPid);

        char *regex = "[-|+]?[0-9]{1,4}.[0-9]{2}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(tempPid, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &tempPid[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            float temp_f = atof(str) * 100 + 0.5;
            temp[i] = temp_f;
        }
        CrLogI("P = %d, I = %d, D = %d", temp[0], temp[1], temp[2]);

        pidPara_t pid;
        pid.p = temp[0];
        pid.i = temp[1];
        pid.d = temp[2];
        para->hotendPid = pid;
    }
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
static int GetBedTempPid(char *buf, int bufLen, PrintSavePara_t *para)
{
    char tempPid[100] = {0};
    char *M304 = strstr(buf, "M304");
    if (M304)
    {
        char *M304End = strchr(M304, '\n');
        memcpy(tempPid, M304, M304End - M304);
        CrLogI("temp Pid = %s", tempPid);

        char *regex = "[-|+]?[0-9]{1,4}.[0-9]{2}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(tempPid, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &tempPid[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            float temp_f = atof(str) * 100 + 0.5;
            temp[i] = temp_f;
        }
        CrLogI("P = %d, I = %d, D = %d", temp[0], temp[1], temp[2]);

        pidPara_t pid;
        pid.p = temp[0];
        pid.i = temp[1];
        pid.d = temp[2];
        para->bedPid = pid;
    }
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
static int GetAxisRecoup(char *buf, int bufLen, PrintSavePara_t *para)
{
    char axisRecoup[100] = {0};
    char *M851 = strstr(buf, "M851");
    if (M851)
    {
        char *M851End = strchr(M851, '\n');
        memcpy(axisRecoup, M851, M851End - M851);
        CrLogI("axis Recoup = %s", axisRecoup);

        char *regex = "[-|+]?[0-9]{1,3}.[0-9]{2}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(axisRecoup, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &axisRecoup[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            float temp_f = atof(str) * 100 + 0.5;
            temp[i] = temp_f;
        }

        CrLogI("X = %d, Y = %d, Z = %d, E = %d", temp[0], temp[1], temp[2], temp[3]);
        Coordinate_t data;
        data.x = temp[0];
        data.y = temp[1];
        data.z = temp[2];
        data.e = temp[3];
        para->axisRecoup = data; 
    }
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
static int GetHomeOffset(char *buf, int bufLen, PrintSavePara_t *para)
{
    char homeOffset[100] = {0};
    char *M206 = strstr(buf, "M206");
    if (M206)
    {
        char *M206End = strchr(M206, '\n');
        memcpy(homeOffset, M206, M206End - M206);
        CrLogI("home Offset = %s", homeOffset);

        char *regex = "[-|+]?[0-9]{1,3}.[0-9]{2}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(homeOffset, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &homeOffset[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            float temp_f = atof(str) * 100 + 0.5;
            temp[i] = temp_f;
        }

        CrLogI("X = %d, Y = %d, Z = %d, E = %d", temp[0], temp[1], temp[2], temp[3]);
        Coordinate_t data;
        data.x = temp[0];
        data.y = temp[1];
        data.z = temp[2];
        data.e = temp[3];
        para->homeOffset = data;
    }
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
static int GetStepValue(char *buf, int bufLen, PrintSavePara_t *para)
{
    char StepValue[100] = {0};
    char *M92 = strstr(buf, "M92");
    if (M92)
    {
        char *M92End = strchr(M92, '\n');
        memcpy(StepValue, M92, M92End - M92);
        CrLogI("Step Value = %s", StepValue);

        char *regex = "[0-9]{1,4}.[0-9]{2}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(StepValue, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &StepValue[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            float temp_f = atof(str) * 100 + 0.5;
            temp[i] = temp_f;
        }
        CrLogI("X = %d, Y = %d, Z = %d, E = %d", temp[0], temp[1], temp[2], temp[3]);

        Coordinate_t data;
        data.x = temp[0];
        data.y = temp[1];
        data.z = temp[2];
        data.e = temp[3];
        para->stepValue = data;
    }
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
static int GetMaximumAcceleration(char *buf, int bufLen, PrintSavePara_t *para)
{
    char Acceleration[100] = {0};
    char *M201 = strstr(buf, "M201");
    if (M201)
    {
        char *M201End = strchr(M201, '\n');
        memcpy(Acceleration, M201, M201End - M201);
        CrLogI("Maximum Acceleration = %s", Acceleration);

        char *regex = "[0-9]{1,4}.[0-9]{2}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(Acceleration, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &Acceleration[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            float temp_f = atof(str);
            temp[i] = temp_f;
        }
        CrLogI("X = %d, Y = %d, Z = %d, E = %d", temp[0], temp[1], temp[2], temp[3]);

        Coordinate_t data;
        data.x = temp[0];
        data.y = temp[1];
        data.z = temp[2];
        data.e = temp[3];
        para->Acceleration = data;
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
static int GetMaximumSpeed(char *buf, int bufLen, PrintSavePara_t *para)
{
    char Speed[100] = {0};
    char *M203 = strstr(buf, "M203");
    if (M203)
    {
        char *M203End = strchr(M203, '\n');
        memcpy(Speed, M203, M203End - M203);
        CrLogI("Maximum Speed = %s", Speed);

        char *regex = "[0-9]{1,4}.[0-9]{2}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(Speed, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &Speed[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            float temp_f = atof(str);
            temp[i] = temp_f;
        }
        CrLogI("X = %d, Y = %d, Z = %d, E = %d", temp[0], temp[1], temp[2], temp[3]);

        Coordinate_t data;
        data.x = temp[0];
        data.y = temp[1];
        data.z = temp[2];
        data.e = temp[3];
        para->Speed = data;
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
static int GetMaximumJerk(char *buf, int bufLen, PrintSavePara_t *para)
{
    char jerk[100] = {0};
    char *M205 = strstr(buf, "M205");
    if (M205)
    {
        char *M205End = strchr(M205, '\n');
        memcpy(jerk, M205, M205End - M205);
        CrLogI("Maximum jerk = %s", jerk);

        char *regex = "[0-9]{1,3}.[0-9]{2}";
        regmatch_t regmatch[10];
        int regexSize = UserGetRegexStr(jerk, regex, regmatch, sizeof(regmatch)/sizeof(regmatch[0]));

        int temp[10] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &jerk[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            float temp_f = atof(str) * 100 + 0.5;
            temp[i] = temp_f;
        }
        CrLogI("X = %d, Y = %d, Z = %d, E = %d", temp[3], temp[4], temp[5], temp[6]);

        Coordinate_t data;
        data.x = temp[3];
        data.y = temp[4];
        data.z = temp[5];
        data.e = temp[6];
        para->Jerk = data;
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
static int GetPowerLossState(char *buf, int bufLen, PrintSavePara_t *para)
{
    char stateStr[10] = {0};
    char *M413 = strstr(buf, "M413 S");
    if (M413)
    {
        M413 += strlen("M413 S");
        char *M413End = strchr(M413, '\n');
        memcpy(stateStr, M413, M413End - M413);
        int state = atoi(stateStr);
        CrLogI("GetPowerLossState = %d", state);
        para->powerLoss = state;
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
static int GetMaterialDetectState(char *buf, int bufLen, PrintSavePara_t *para)
{
    char stateStr[10] = {0};
    char *M412 = strstr(buf, "M412 S");
    if (M412)
    {
        M412 += strlen("M412 S");
        char *M412End = strchr(M412, ';');
        if (!M412End) M412End = strchr(M412, '\n');
        memcpy(stateStr, M412, M412End - M412);
        int state = atoi(stateStr);
        CrLogI("GetMaterialDetectState = %d", state);
        para->materialDetect = state;
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
static int GetAutoLevelingValue(char *buf, int bufLen, PrintSavePara_t *para)
{
    char delectStr[2048] = {0};
    char *G29 = strstr(buf, "G29");
    while (G29)
    {
        char *G29End = strchr(G29, '\n') + 1;
        memcpy(&delectStr[strlen(delectStr)], G29, G29End - G29);
        G29 = strstr(G29End, "G29");
    }
    CrLogI("auto leveling value str = \n%s", delectStr);

    // 获取调平点数
    PrintSavePara_t savePara = GetPrintSavePara();
    int levelPoints = savePara.levelPoints.x * savePara.levelPoints.y;

    // 获取调平值
    LevelValue_t updataValue = {0};
    char *strtokContext = NULL;
    char *temp = strtok_r(delectStr, "\n", &strtokContext);
    while (temp)
    {
        char *valueStr = strchr(temp, 'Z') + 1;
        int tempValue = atof(valueStr) * 10000 + 0.5;
        updataValue.value[updataValue.size] = tempValue;
        updataValue.size++;
        if (updataValue.size >= levelPoints) break;
        temp = strtok_r(NULL, "\n", &strtokContext);
    }

    CrLogI("auto level point size = %d", updataValue.size);
    para->levelValue = updataValue;

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseAdvanceSetResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("Advance Set result = %d", result);
    if (result && !strstr(buf, UNDEFINED_COMMAND))
    {
        PrintSavePara_t updataPara = GetPrintSavePara();
        GetHotendTempPid(buf, bufLen, &updataPara);
        GetBedTempPid(buf, bufLen, &updataPara);
        GetAxisRecoup(buf, bufLen, &updataPara);
        GetHomeOffset(buf, bufLen, &updataPara);
        GetStepValue(buf, bufLen, &updataPara);
        GetMaximumAcceleration(buf, bufLen, &updataPara);
        GetMaximumSpeed(buf, bufLen, &updataPara);
        GetMaximumJerk(buf, bufLen, &updataPara);
        GetPowerLossState(buf, bufLen, &updataPara);
        GetMaterialDetectState(buf, bufLen, &updataPara);
        GetAutoLevelingValue(buf, bufLen, &updataPara);
        UpdataPrintSavePara(updataPara);
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponsePrintSpeedResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    CrLogI("get Print Speed result = %d", result);
    if (result && !strstr(buf, UNDEFINED_COMMAND))
    {
        char *temp = strstr(buf, "FR:");
        if (temp)
        {
            temp += strlen("FR:");
            char *end = strchr(temp, '%');
            char speedStr[10] = {0};
            memcpy(speedStr, temp, end - temp);
            int speedInt = atoi(speedStr);

            CrLogI("current print speed = %d%%", speedInt);
            UpdataPrintSpeed(speedInt);
        }
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int GerPrintProgressFromResponseData(char *buf, int bufLen, int result)
{
    if (!result)
    {
        CrLogW("The serial port connection is abnormal!\n");
        return -1;
    }
    if (strstr(buf, UNDEFINED_COMMAND)) return -1;

    char progressBuf[100] = {0};
    char *pa, *pb;
    pa = strstr(buf, UPDATA_PRINT_TIME);
    if (pa)
    {
        // 获取打印时间
        pb = strstr(pa, "\n");
        memcpy(progressBuf, pa, pb - pa);
        CrLogI("Response Print Progress = %s", progressBuf);

        char *regex = "[0-9]{1,2}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(progressBuf, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &progressBuf[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            float temp_f = atof(str);
            temp[i] = temp_f;
        }

        int time = 0;
        switch (regexSize)
        {
            case 1: time = temp[0]; break;
            case 2: time = (temp[0] * 60) + temp[1]; break;
            case 3: time = (temp[0] * 60 * 60) + (temp[1] * 60) + temp[2]; break;
        }
        CrLogI("Print Progress; time = %d", time);

        // 获取打印进度百分比
        pa = strstr(pb, UPDATA_PRINT_PROGRESS);
        if (pa)
        {
            pa = pa + strlen(UPDATA_PRINT_PROGRESS);
            pb = strstr(pa, "\n");
            memset(progressBuf, 0, 100);
            memcpy(progressBuf, pa, pb - pa);
            CrLogI("Response Print percentDone = %s", progressBuf);
            
            int percentDone = atoi(progressBuf);
            if (percentDone >= 100) percentDone = 100;
            CrLogI("Print percentDone = %d%%", percentDone);
            UpdataPrintProgress(percentDone * 100 + 0.5);
        }
        UpdataPrintUsageTime(time);
    }
    else
    {
        CrLogW("Response not (Print time:)");
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} cmd
 * @param {char} *buf
 * @param {int} bufLen
 * @param {int} result
 */
static int ResponseAutoPrintSendGcodeResult(GcodeSend_t cmd, char *buf, int bufLen, int result)
{
    // 判断当前响应是否已处理
    if (autoResponseProcessed) {
        autoResponseProcessed = false;
        CrLogI("The current response has been processed");
        return 0;
    }

    if (result) EnableRequestSendGcodeCmd();
    else CrLogW("Auto Print Send Gcode fail !!!\n\n\n");

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *send
 * @param {char} *buf
 * @param {int} len
 * @param {int} result
 */
int SerialPortRecvGcodeAnl(GcodeSend_t send, char *buf, int bufLen, int result)
{
    switch (send.cmd)
    {
        case SERIAL_PORT_HANDSHAKE_NUM: ResponseSerialPortHandshakeResult(send, buf, bufLen, result); break;

        case GET_CUR_HOTEND_BED_TEMP_NUM: getTempFromResponseData(buf, bufLen, result); break;
        case GET_DEV_GCODE_FILE_PATH_NUM: ResponseGetGcodeFileResult(send, buf, bufLen, result); break;
        case GET_DEV_GCODE_FILE_IMAGE_NUM: ResponseGetGcodeFileImageResult(send, buf, bufLen, result); break;
        case GET_DEV_GCODE_FILE_PHOTO_NUM: ResponseGetGcodeFilePhotoResult(send, buf, bufLen, result); break;
        case GET_DEV_CUR_XYZ_LOCAL_NUM: ResponseGetXyzLocalResult(send, buf, bufLen, result); break;
        case GET_DEVICE_ADVANCE_SET_NUM: ResponseAdvanceSetResult(send, buf, bufLen, result); break;
        case GET_DEVICE_PRINT_SPEED_NUM: ResponsePrintSpeedResult(send, buf, bufLen, result); break;
        case GET_DEVICE_PRINT_PROGRESS_NUM: GerPrintProgressFromResponseData(buf, bufLen, result); break;

        case SET_SELECT_PRINT_FILE_NUM: ResponseSelectSdFileResult(send, buf, bufLen, result); break;
        case SET_START_PRINT_FILE_NUM: ResponseStartPrintFileResult(send, buf, bufLen, result); break;
        case SET_PAUSE_PRINT_FILE_NUM: ResponsePausePrintFileResult(send, buf, bufLen, result); break;
        case SET_RESUME_PRINT_FILE_NUM: ResponseResumePrintFileResult(send, buf, bufLen, result); break;
        case SET_STOP_PRINT_FILE_NUM: ResponseStopPrintFileResult(send, buf, bufLen, result); break;
        case SET_PARK_HEAD_PRINT_NUM: ResponseParkHeadPrintResult(send, buf, bufLen, result); break;
        case SET_BREAK_CONTINUE_PEINR_NUM: ResponseBreakContinueResult(send, buf, bufLen, result); break;
        case SET_STOP_TEMP_HEATING_NUM: ResponseStopHeatingResult(send, buf, bufLen, result); break;
        case SET_DEVICE_RETURN_HOME_NUM: ResponseDevReturnHomeResult(send, buf, bufLen, result); break;
        case SET_CONTROL_DEV_MOVE_NUM: ResponseControlMoveResult(send, buf, bufLen, result); break;
        case SET_Z_AXIS_OFFSET_PARA_NUM: ResponseAxisRecoupResult(send, buf, bufLen, result); break;
        case SET_HOME_OFFSET_PARA_NUM: ResponseHomeOffsetParaResult(send, buf, bufLen, result); break;
        case SET_DEVICE_MOTOR_LOCK_NUM: ResponseMotorLockResult(send, buf, bufLen, result); break;
        case SET_DEVICE_MOTOR_UNLOCK_NUM: ResponseMotorUnlockResult(send, buf, bufLen, result); break;
        case SET_NOZZLE_TARGET_TEMP_NUM: ResponseSetNozzleTempResult(send, buf, bufLen, result); break;
        case SET_BED_TARGET_TEMP_NUM: ResponseSetBedTempResult(send, buf, bufLen, result); break;
        case SET_CONTROL_OPEN_FAN_NUM: ResponseContolOpenFanResult(send, buf, bufLen, result); break;
        case SET_CONTROL_STOP_FAN_NUM: ResponseContolStopFanResult(send, buf, bufLen, result); break;
        case SET_ABSOLUTE_POSITIONING_NUM: ResponseAbsolutePositioningResult(send, buf, bufLen, result); break;
        case SET_RELATIVE_POSITIONING_NUM: ResponseRelativePositioningResult(send, buf, bufLen, result); break;
        case SET_DEVICE_AUTO_LEVEL_NUM: ResponseDeviceAutoLevelResult(send, buf, bufLen, result); break;
        case SET_HOTEND_TEMP_PID_NUM: ResponseSetHotendTempPidResult(send, buf, bufLen, result); break;
        case SET_BED_TEMP_PID_NUM: ResponseSetBedTempPidResult(send, buf, bufLen, result); break;
        case SET_DEVICE_RESET_NUM: ResponseControlDeviceResetResult(send, buf, bufLen, result); break;
        case SET_DEV_RESET_AFTER_SAVE_NUM: ResponseSetDevResetSaveResult(send, buf, bufLen, result); break;
        case SET_STEP_VALUE_NUM: ResponseSetStepValueResult(send, buf, bufLen, result); break;
        case SET_MAX_ACCELERATION_NUM: ResponseSetMaxAccelerationResult(send, buf, bufLen, result); break;
        case SET_MAX_SPEED_NUM: ResponseSetMaxSpeedResult(send, buf, bufLen, result); break;
        case SET_MAX_JERK_NUM: ResponseSetMaxJerkResult(send, buf, bufLen, result); break;
        case SET_MATERIAL_DELECT_NUM: ResponseSetMaterialDelectResult(send, buf, bufLen, result); break;
        case SET_POWER_LOSS_SW_NUM: ResponseSetPowerLossSwResult(send, buf, bufLen, result); break;
        case SET_DEVICE_PRINT_SPEED_NUM: ResponseSetPrintSpeedResult(send, buf, bufLen, result); break;
        case SET_CR_TOUCH_CONTROL_NUM: ResponseSetCrTouchResult(send, buf, bufLen, result); break;
        case SET_START_HOT_END_TEMP_AUTO_PID_NUM: ResponseSetStartHotendAutoPidResult(send, buf, bufLen, result); break;
        case SET_START_HOT_BED_TEMP_AUTO_PID_NUM: ResponseSetStartHotbedAutoPidResult(send, buf, bufLen, result); break;
        case SET_PARA_SAVE_CONFIG_NUM: ResponseSetParaSaveConfigResult(send, buf, bufLen, result); break;
        case SET_INSERT_FILAMENT_NUM: ResponseSetInsertFilamentResult(send, buf, bufLen, result); break;
            
        // 公司自定义指令
        case CXSW_GET_PRINT_STATUS_NUM: ResponseCxswGetPrintStatusResult(send, buf, bufLen, result); break;
        case CXSW_GET_PRINT_DEV_INFO_NUM: ResponseCxswGetPrintDevInfoResult(send, buf, bufLen, result); break;
        case CXSW_SET_OFFSET_AND_TIME_NUM: ResponseCxswSetOffsetAndTimeResult(send, buf, bufLen, result); break;
        case CXSW_SET_PRINT_FILE_INFO_NUM: ResponseCxswSetPrintFileInfoResult(send, buf, bufLen, result); break;
        case CXSW_GET_POWER_LOSS_INFO_NUM: ResponseCxswGetPowerLossResult(send, buf, bufLen, result); break;
        case CXSW_SET_STOP_PRINTING_NUM: ResponseCxswSetStopPirintResult(send, buf, bufLen, result); break;
        case CXSW_SET_PAUE_RESUME_NUM: ResponseCxswSetPaueResumeResult(send, buf, bufLen, result); break;
        case CXSW_START_AUTO_RECOUP_NUM: ResponseCxswStartAutoRecoupResult(send, buf, bufLen, result); break;
        case CXSW_GET_LEVEL_POINTS_NUM: ResponseCxswGetLevelPointsResult(send, buf, bufLen, result); break;
        case CXSW_SET_LEVEL_POINTS_NUM: ResponseCxswSetLevelPointsResult(send, buf, bufLen, result); break;
        case CXSW_SET_ACTIVELY_ACQUIRE_NUM: ResponseCxswSetActivelyAcquireResult(send, buf, bufLen, result); break;
        
        // 自动打印
        case AUTO_PRINT_SEND_GCODE_NUM: ResponseAutoPrintSendGcodeResult(send, buf, bufLen, result); break;
        default:
            CrLogW("Command is not defined; cmd = [%d]!\n", send.cmd);
            break;
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
int AutoPrintResponse(uint32_t cmdNum, char *buf, int bufLen)
{
    // 不是自动发送gcode指令应答，不发送下一条指令
    if (cmdNum != AUTO_PRINT_SEND_GCODE_NUM) return 0;
    if (strstr(buf, "ok"))
    {
        EnableRequestSendGcodeCmd();
        autoResponseProcessed = true;
        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
int AutoPrintRequest(char *buf, int bufLen, int *line)
{
    char *requestCmd = strstr(buf, ACTIVELY_HEADER);
    if (requestCmd)
    {
        requestCmd += strlen(ACTIVELY_HEADER);
        char *lineEnd = strchr(requestCmd, '\n');
        if (lineEnd)
        {
            int lineLen = lineEnd - requestCmd;
            char lineBuff[10] = {0};
            memcpy(lineBuff, requestCmd, lineLen);
            
            uint32_t requestLine = atoi(lineBuff);
            EnableRequestGetGcodeCmd( requestLine );
            *line = requestLine;
            return 0;
        }
    }
    return -1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
int AutoPrintRequestAnl(char *buf, int bufLen, uint32_t line)
{
    char *requestCmd = strstr(buf, ACTIVELY_HEADER);
    if (requestCmd)
    {
        requestCmd += strlen(ACTIVELY_HEADER);
        
        int requestLine = atoi(requestCmd);
        if (requestLine > line || (requestLine != line && requestLine == 1))
            EnableRequestGetGcodeCmd( requestLine );
        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int DevicePrintFinish(char *buf, int bufLen)
{
    if (strstr(buf, DONE_PRINTING_FILE))
    {
        GcodeCmdRes finish = GCODE_CMD_RES__INIT;
        finish.result = 1;
        GerPrintProgressFromResponseData(buf, bufLen, 1);
        UpdataPrintProgress(100 * 100);

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd_res__pack(&finish, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_DEVICE_PRINT_FINISH, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
int DetectAutoReportStatus(char *buf, int bufLen)
{
    char *value = strstr(buf, UPDATA_PRINT_STATUS);
    if (value)
    {
        CrLogI("Detect Auto Report Status = %s", value);
        value = value + strlen(UPDATA_PRINT_STATUS);

        // 解析数据
        char *F = NULL, *T = NULL, *C = NULL;
        char *FR = NULL, *TR = NULL, *CR = NULL;
        char *W = NULL, *FAN0 = NULL, *MOTOR = NULL;

        char *strtokContext = NULL;
        char *dataAnl = strtok_r(value, ";", &strtokContext);
        while (dataAnl)
        {
            if (strstr(dataAnl, "F:")) F = strstr(dataAnl, "F:") + strlen("F:");
            if (strstr(dataAnl, "T:")) T = strstr(dataAnl, "T:") + strlen("T:");
            if (strstr(dataAnl, "C:")) C = strstr(dataAnl, "C:") + strlen("C:");
            if (strstr(dataAnl, "FR:")) FR = strstr(dataAnl, "FR:") + strlen("FR:");
            if (strstr(dataAnl, "TR:")) TR = strstr(dataAnl, "TR:") + strlen("TR:");
            if (strstr(dataAnl, "CR:")) CR = strstr(dataAnl, "CR:") + strlen("CR:");
            if (strstr(dataAnl, "W:")) W = strstr(dataAnl, "W:") + strlen("W:");
            if (strstr(dataAnl, "FAN0:")) FAN0 = strstr(dataAnl, "FAN0:") + strlen("FAN0:");
            if (strstr(dataAnl, "MOTOR:")) MOTOR = strstr(dataAnl, "MOTOR:") + strlen("MOTOR:");
            dataAnl = strtok_r(NULL, ";", &strtokContext);
        }

        // 将字符串转换成整型
        int F_int = 0, T_int = 0, C_int = 0;
        int FR_int = 0, TR_int = 0, CR_int = 0;
        int W_int = 0, FAN0_int = 0, MOTOR_int = 0;

        if (F)  F_int = atoi(F);
        if (T)  T_int = atoi(T);
        if (C)  C_int = atoi(C);
        if (FR) FR_int = atoi(FR);
        if (TR) TR_int = atoi(TR);
        if (CR) CR_int = atoi(CR);
        if (W)  W_int = atoi(W);
        if (FAN0)  FAN0_int = atoi(FAN0);
        if (MOTOR)  MOTOR_int = atoi(MOTOR);
        CrLogI("==============================");
        CrLogI("F  = %d", F_int);
        CrLogI("T  = %d", T_int);
        CrLogI("C  = %d", C_int);
        CrLogI("FR = %d", FR_int);
        CrLogI("TR = %d", TR_int);
        CrLogI("CR = %d", CR_int);
        CrLogI("W  = %d", W_int);
        CrLogI("FAN0  = %d", FAN0_int);
        CrLogI("MOTOR  = %d", MOTOR_int);
        CrLogI("==============================");

        UpdataErrorStateToManager(W_int, "", NULL);
        UpdataPrintFanState(FAN0_int, MULTI_FAN_MODEL); // 更新风扇状态
        UpdataPrintMotorState(MOTOR_int); // 更新电机锁定状态
        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
int DeviceAutoLevelProgress(uint32_t cmdNum, char *buf, int bufLen)
{
    if (cmdNum != SET_DEVICE_AUTO_LEVEL_NUM) return -1;

    CrLogI("Device Auto Level Progress");
    char *value = strstr(buf, AUTO_LEVEL_PROGRESS);
    if (value)
    {
        value += strlen(AUTO_LEVEL_PROGRESS);
        char *temp = strchr(value, '/');
        char str1[10] = {0};
        memcpy(str1, value, temp - value);

        value = temp + 1;
        temp = strchr(value, '.');
        char str2[10] = {0};
        memcpy(str2, value, temp - value);

        int progress = (atof(str1) - 1)/atoi(str2) * 100 + 0.5;
        UpdataAutoLevelProgress(progress);
        CrLogI("auto level current progress = %d%%", GetPrintState().autoLevelProgress);
        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {uint32_t} cmdNum
 * @param {char} *buf
 * @param {int} bufLen
 */
int DeviceAutoPidProgress(uint32_t cmdNum, char *buf, int bufLen)
{
    if (cmdNum != SET_START_HOT_END_TEMP_AUTO_PID_NUM &&
        cmdNum != SET_START_HOT_BED_TEMP_AUTO_PID_NUM) return -1;

    CrLogI("Device Auto Pid Progress");
    bool change = false;
    static int autoPidProgressCount = 0;

    if (strstr(buf, TEMP_AUTO_PID_START))
    {
        autoPidProgressCount = 0;
        change = true;
    }
    else if (strstr(buf, TEMP_AUTO_PID_FLAG))
    {
        autoPidProgressCount++;
        change = true;
    }  
    else if (strstr(buf, TEMP_AUTO_PID_END))
    {
        autoPidProgressCount = userSetAutoPidTimes;
        ClearCurAutoPidResult();
        change = true;
    }
    else if (strstr(buf, TEMP_AUTO_PID_KP))
    {
        char *kp = strstr(buf, TEMP_AUTO_PID_KP) + strlen(TEMP_AUTO_PID_KP);
        curAutoPidResult.p = atof(kp) * 100 + 0.5;
        CrLogI("curAutoPidResult.p = %d", curAutoPidResult.p);
    }
    else if (strstr(buf, TEMP_AUTO_PID_KI))
    {
        char *ki = strstr(buf, TEMP_AUTO_PID_KI) + strlen(TEMP_AUTO_PID_KI);
        curAutoPidResult.i = atof(ki) * 100 + 0.5;
        CrLogI("curAutoPidResult.i = %d", curAutoPidResult.i);
    }
    else if (strstr(buf, TEMP_AUTO_PID_KD))
    {
        char *kd = strstr(buf, TEMP_AUTO_PID_KD) + strlen(TEMP_AUTO_PID_KD);
        curAutoPidResult.d = atof(kd) * 100 + 0.5;
        CrLogI("curAutoPidResult.d = %d", curAutoPidResult.d);
    }
    else if (strstr(buf, TEMP_AUTO_PID_BED_KP))
    {
        char *kp = strstr(buf, TEMP_AUTO_PID_BED_KP) + strlen(TEMP_AUTO_PID_BED_KP);
        curAutoPidResult.p = atof(kp) * 100 + 0.5;
        CrLogI("curAutoPidResult.p = %d", curAutoPidResult.p);
    }
    else if (strstr(buf, TEMP_AUTO_PID_BED_KI))
    {
        char *ki = strstr(buf, TEMP_AUTO_PID_BED_KI) + strlen(TEMP_AUTO_PID_BED_KI);
        curAutoPidResult.i = atof(ki) * 100 + 0.5;
        CrLogI("curAutoPidResult.i = %d", curAutoPidResult.i);
    }
    else if (strstr(buf, TEMP_AUTO_PID_BED_KD))
    {
        char *kd = strstr(buf, TEMP_AUTO_PID_BED_KD) + strlen(TEMP_AUTO_PID_BED_KD);
        curAutoPidResult.d = atof(kd) * 100 + 0.5;
        CrLogI("curAutoPidResult.d = %d", curAutoPidResult.d);
    }

    // 判断是否更新进度
    if (change)
    {
        int progress = (double)autoPidProgressCount/userSetAutoPidTimes * 100 + 0.5;
        UpdataAutoPidProgress(progress);
        CrLogI("auto pid current progress = %d%%", GetPrintState().autoPidProgress);
        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
int DetectUserSetParkHead(char *buf, int bufLen)
{
    if (strstr(buf, USER_SET_PARK_HEAD))
    {
        CrLogW("Send M108 to resume\n\n");
        if (GetPrintState().pauseStatus == PAUSE_STATUS_HEATING)
        {
            UpdataPrintPauseStatus(PAUSE_STATUS_FINISH);
            char M108Buff[10] = {0};
            snprintf(M108Buff, 10, "%s\n", SET_BREAK_AND_CONTINUE);
            AppEnforceUartSend(M108Buff, strlen(M108Buff));
            String_t tCmd = {0};
            tCmd.data = SET_BREAK_AND_CONTINUE;
            tCmd.len = strlen(SET_BREAK_AND_CONTINUE);
            AddGcodeListHeadSecondCmd(SET_BREAK_CONTINUE_PEINR_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);
        }
        else UpdataPrintPauseStatus(PAUSE_STATUS_PAUSEING);

        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
int DetectMaterialStatus(char *buf, int bufLen)
{
    if (strstr(buf, DETECT_MATARIAL_BREAK))
    {
        CrLogW("Insert filament and send M108\n\n");
        UpdataPrintMaterialStatus(MATERIAL_STATUS_BLANKING, MATERIAL_DETECTOR_1);
        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
int DetectActiveCooling(char *buf, int bufLen)
{
    if (strstr(buf, DEV_ACTIVE_COOLING))
    {
        CrLogW("Send M108 to heat nozzle\n\n");
        if (GetPrintState().pauseStatus == PAUSE_STATUS_PAUSEING)
            UpdataPrintPauseStatus(PAUSE_STATUS_COOLING);
        if (GetPrintState().materialStatus[MATERIAL_DETECTOR_1] == MATERIAL_STATUS_BLANKING)
            UpdataPrintMaterialStatus(MATERIAL_STATUS_COOLING, MATERIAL_DETECTOR_1);
        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
int DetectLowerComputerStarts(char *buf, int bufLen)
{
    if (strstr(buf, LOWER_COMPUTER_STARTS))
    {
        CrLogE("Lower computer starts\n\n");
        CleanCurrentSendCmd();
        ClearSendGcodeList();
        ClearUserActivePause();
        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *buf
 * @param {int} bufLen
 */
int DetectLowerComputerPrinterHalted(char *buf, int bufLen)
{
    if (strstr(buf, PRINTER_HALTED))
    {
        CrLogE("Lower computer Printer halted\n\n");
        CleanCurrentSendCmd();
        ClearSendGcodeList();
        ClearUserActivePause();
        return 0;
    }
    return -1;
}



/**
 * @description: 
 * @return {*}
 * @param {char} *str
 */
int GetKlipperErrorKeyValue(const char *str)
{
    json_object *responseStrObj = json_tokener_parse(str);
    if (responseStrObj != NULL && json_object_is_type(responseStrObj, json_type_object))
    {
        FaultCode_t info = {0};
        info.code = FAULT_CODE_IDLE;
        
        // 解析 klipper 错误key值
        json_object *codeObj = json_object_object_get(responseStrObj, "code");
        if (codeObj != NULL && json_object_is_type(codeObj, json_type_string))
        {
            const char *codeStr = json_object_get_string(codeObj);
            // 正则匹配
            char *regex = "[0-9]{1,4}";
            regmatch_t regmatch[5];
            int regexSize = UserGetRegexStr(codeStr, regex, regmatch, 5);

            int temp[5] = {0};
            for(int i = 0; i< regexSize; i++)
            {
                int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
                char str[cnt + 1];
                bzero(str, sizeof(str));
                memcpy(str, &codeStr[regmatch[i].rm_so], cnt);
                temp[i] = atoi(str);
            }
            // 转换错误码
            info.code = temp[0] + FAULT_KLIPPER_CODE_CONVERT;
            CrLogI("klipper fault code = %s, key = %d", codeStr, info.code);
        }
        json_object *msgObj = json_object_object_get(responseStrObj, "msg");
        if (msgObj != NULL && json_object_is_type(msgObj, json_type_string))
        {
            strcat(info.msg, json_object_get_string(msgObj));
            CrLogI("klipper fault code msg = %s", info.msg);
        }
        json_object *valuesObj = json_object_object_get(responseStrObj, "values");
        if (valuesObj != NULL && json_object_is_type(valuesObj, json_type_array))
        {
            strcat(info.value, json_object_to_json_string(msgObj));
            CrLogI("klipper fault code value = %s", info.value);
        }

        // 更新错误码
        UpdataErrorStateToManager(info.code, info.msg, info.value);
        json_object_put(responseStrObj);
        return 0;
    }
    else {
        if (responseStrObj != NULL) json_object_put(responseStrObj);
        return -1;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {ResonanceTest_t} res
 */
int ResonanceTestResultResponse(ResonanceTest_t testRes)
{
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = testRes;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_RESONANCE_TEST_ANS, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {AutoLeveling_t} levelRes
 */
int AutoLevelResultResponse(AutoLeveling_t levelRes)
{
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = levelRes;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_DEVICE_AUTO_LEVEL_ANS, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param 
 */
static int SetQuietModeResultResponse()
{
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_QUIET_MODE_ANS, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *obj
 */
static int KlipperGcodeOutputResultAnl(json_object *obj)
{
    json_object *responseObj = json_object_object_get(obj, "response");
    if (responseObj != NULL && json_object_is_type(responseObj, json_type_string))
    {
        // 获取gcode输出结果
        const char *responseStr = json_object_get_string(responseObj);
        CrLogI("response = %s", responseStr);

        // 发送gcode工作日志到交互端
        {
            GcodeCmdRes response = GCODE_CMD_RES__INIT;
            response.result = 1;
            response.has_resstr = 1;
            response.resstr.data = (uint8_t*)responseStr;
            response.resstr.len = strlen(responseStr);
            GET_MESSAGE_BUFF(buff);
            size_t len = gcode_cmd_res__pack(&response, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_CONSOLE_CTL_ANS, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
        }

        // 解析 gcode 应答 klipper 状态
        if (strstr(responseStr, GCODE_RES_KLIPPER_STATE))
        {
            if (strstr(responseStr, "Klipper state: Disconnect")) {
                UpdataKlipperState(KLIPPER_STATE_SHUTDOWN);
                UpdataErrorStateToManager(FAULT_DETECT_KLIPPER_DISCONNECT, (char*)responseStr, NULL);
                // klipper 重启，返回首页
                SetAppStateChange(APP_PRINT_STATE_STOP);
                SetAppModeChange(APP_MODE_IDLE);
                UpdataDeviceState(DEVICE_STATE_IDLE);
                // 断开klipper连接
                KlipperSocketDeinit();
                // 获取继续打印信息
                SetSyncContinuePrint(true);
            }
            else if (strstr(responseStr, "Klipper state: Shutdown")) {
                // 获取继续打印信息
                SetSyncContinuePrint(true);
            }
        }

        // 解析json数据结构结果，获取自定义报错信息
        if (GetKlipperErrorKeyValue(responseStr + 3) == 0) {
            return 0;
        }

        // 解析温度自动PID结果
        if (strstr(responseStr, TEMP_AUTO_PID_RESULT))
        {
            char *regex = "[-|+]?[0-9]{1,4}.[0-9]{3}";
            regmatch_t regmatch[5];
            int regexSize = UserGetRegexStr(responseStr, regex, regmatch, 5);

            int32_t temp[5] = {0};
            for(int i = 0; i< regexSize; i++)
            {
                int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
                char str[cnt + 1];
                memset(str, 0, cnt + 1);
                memcpy(str, &responseStr[regmatch[i].rm_so], cnt);
                str[cnt] = '\0';
                temp[i] = atof(str) * 1000 + 0.5;
            }

            CrLogI("temp auto pid; p = %d, i = %d, d = %d", temp[0], temp[1], temp[2]);
            curAutoPidResult.p = temp[0];
            curAutoPidResult.i = temp[1];
            curAutoPidResult.d = temp[2];

            return 0;
        }

        // 获取自动调平结果
        if (strstr(responseStr, AUTO_LEVEL_RESULT))
        {
            char *regex = "[-|+]?[0-9]{1,3}.[0-9]{1,6}";
            regmatch_t regmatch[5];
            int regexSize = UserGetRegexStr(responseStr, regex, regmatch, 5);

            int32_t temp[5] = {0};
            for(int i = 0; i< regexSize; i++)
            {
                int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
                char str[cnt + 1];
                memset(str, 0, cnt + 1);
                memcpy(str, &responseStr[regmatch[i].rm_so], cnt);
                str[cnt] = '\0';
                temp[i] = atof(str) * 10000 + 0.5;
            }

            curAutoLevelPointNum++;
            CrLogI("auto level; num = %d; x = %d, y = %d, z = %d", curAutoLevelPointNum, temp[0], temp[1], temp[2]);
            // 同步调平结果
            ReportAutoLevelRes res = REPORT_AUTO_LEVEL_RES__INIT;
            res.has_num = 1;
            res.num = curAutoLevelPointNum;
            res.has_pointx = 1;
            res.pointx = temp[0];
            res.has_pointy = 1;
            res.pointy = temp[1];
            res.has_value = 1;
            res.value = temp[2];

            GET_MESSAGE_BUFF(buff);
            size_t len = report_auto_level_res__pack(&res, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_REPORT_AUTO_LEVEL_RESULT, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
            MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
            MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
            
            return 0;
        }
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} *state
 */
static void SyncFluiddStartPrintState(KlipperPrint_t *state)
{
    char filePath[256] = {0};
    snprintf(filePath, sizeof(filePath), "%s/%s", GetUserLocalSdCardPtah(), state->print_stats.filename.data);
    CrLogI("filePath = %s", filePath);

    // 启动同步
    MutableTypeData start = MUTABLE_TYPE_DATA__INIT;
    start.has_bytes_v = 1;
    start.bytes_v.data = (uint8_t*)filePath;
    start.bytes_v.len = strlen(filePath);

    GET_MESSAGE_BUFF(buff);
    size_t len = mutable_type_data__pack(&start, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_FLUIDD_START_PRINT_REQ, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} *state
 * @param {json_object} *Obj
 */
static int SyncKlipperPrintState(KlipperPrint_t *state, json_object *Obj)
{
    const char *printState = state->print_stats.state.data;
    CrLogI("print state = %s", printState);

    // 获取状态消息
    json_object *messageObj = json_object_object_get(Obj, "message");
    if (messageObj != NULL && json_object_is_type(messageObj, json_type_string))
    {
        String_t *stateTemp = &(state->print_stats.message);
        stateTemp->len = json_object_get_string_len(messageObj);
        stateTemp->data = (char*)realloc(stateTemp->data, stateTemp->len + 1);
        memset(stateTemp->data, 0, stateTemp->len + 1);
        memcpy(stateTemp->data, json_object_get_string(messageObj), stateTemp->len);
        CrLogI("print state_message = %s", stateTemp->data);
    }
    
    // 处理状态
    if (strcmp(printState, "complete") == 0)
    {
        CrLogI("Print Finish\n");
        UpdataKlipperPrint(KLIPPER_PRINT_COMPLETE);
        SetAppModeChange(APP_MODE_IDLE);
        SetAppStateChange(APP_PRINT_STATE_FINISH);
        UpdataPrintProgress(100 * 100);
        UpdataPrintRemainTime(0);
        UpdataPrintLayer(GetPrintState().printLayers);

        // 打印完成
        GcodeCmdRes finish = GCODE_CMD_RES__INIT;
        finish.result = 1;
        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd_res__pack(&finish, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_DEVICE_PRINT_FINISH, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    }
    else if (strcmp(printState, "printing") == 0)
    {
        CrLogI("Print printing\n");
        UpdataKlipperPrint(KLIPPER_PRINT_PRINTING);
        if (GetCurrentAppstate() != APP_PRINT_STATE_WORK) SetAppStateChange(APP_PRINT_STATE_WORK);
        if (GetCurrentAppMode() == APP_MODE_IDLE) SyncFluiddStartPrintState(state);
    }
    else if (strcmp(printState, "paused") == 0)
    {
        CrLogI("Print paused\n");
        UpdataKlipperPrint(KLIPPER_PRINT_PAUSED);
        if (GetCurrentAppstate() != APP_PRINT_STATE_PAUSE) SetAppStateChange(APP_PRINT_STATE_PAUSE);
        if (GetCurrentAppMode() == APP_MODE_IDLE) SyncFluiddStartPrintState(state);
    }
    else if (strcmp(printState, "error") == 0)
    {
        CrLogI("Print error\n");
        UpdataKlipperPrint(KLIPPER_PRINT_ERROR);
        SetAppStateChange(APP_PRINT_STATE_FAIL);
        SetAppModeChange(APP_MODE_IDLE);
        // 降温
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_STOP_ALL_HEAT_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    else if (strcmp(printState, "cancelled") == 0)
    {
        CrLogI("Print cancelled\n");
        UpdataKlipperPrint(KLIPPER_PRINT_CANCELLED);
        SetAppStateChange(APP_PRINT_STATE_STOP);
        SetAppModeChange(APP_MODE_IDLE);
    }
    else if (strcmp(printState, "standby") == 0)
    {
        CrLogI("Print standby\n");
        UpdataKlipperPrint(KLIPPER_PRINT_STANDBY);
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} *state
 * @param {json_object} *Obj
 */
static int SyncKlipperPrepareState(KlipperPrint_t *state, json_object *Obj)
{
    const char *readyState = state->webhooks.state.data;
    CrLogI("klipper state = %s", readyState);

    // 获取状态消息
    json_object *stateMessageObj = json_object_object_get(Obj, "state_message");
    if (stateMessageObj != NULL && json_object_is_type(stateMessageObj, json_type_string))
    {
        String_t *stateMessageTemp = &(state->webhooks.state_message);
        stateMessageTemp->len = json_object_get_string_len(stateMessageObj);
        stateMessageTemp->data = (char*)realloc(stateMessageTemp->data, stateMessageTemp->len + 1);
        memset(stateMessageTemp->data, 0, stateMessageTemp->len + 1);
        memcpy(stateMessageTemp->data, json_object_get_string(stateMessageObj), stateMessageTemp->len);
        CrLogI("klipper state_message = %s", stateMessageTemp->data);
    }

    // 处理状态
    if (strcmp(readyState, "shutdown") == 0)
    {
        CrLogI("klipper shutdown\n");
        setEnableGetKlipperState(true);
        UpdataKlipperState(KLIPPER_STATE_SHUTDOWN);
        // klipper 重启，返回首页
        SetAppStateChange(APP_PRINT_STATE_STOP);
        SetAppModeChange(APP_MODE_IDLE);
        UpdataDeviceState(DEVICE_STATE_IDLE);
        if (GetKlipperErrorKeyValue(state->webhooks.state_message.data) != 0) {
            UpdataErrorStateToManager(FAULT_DETECT_KLIPPER_WEB_HOOKS_SHUTDOWN, state->webhooks.state_message.data, NULL);
        }
    }
    else if (strcmp(readyState, "startup") == 0)
    {
        CrLogI("klipper startup\n");
        setEnableGetKlipperState(true);
        UpdataKlipperState(KLIPPER_STATE_STARTUP);
        // klipper 重启，返回首页
        SetAppStateChange(APP_PRINT_STATE_STOP);
        SetAppModeChange(APP_MODE_IDLE);
        UpdataDeviceState(DEVICE_STATE_IDLE);
        GetKlipperErrorKeyValue(state->webhooks.state_message.data);
    }
    else if (strcmp(readyState, "error") == 0)
    {
        CrLogI("klipper error\n");
        setEnableGetKlipperState(true);
        UpdataKlipperState(KLIPPER_STATE_ERROR);
        // klipper 重启，返回首页
        SetAppStateChange(APP_PRINT_STATE_STOP);
        SetAppModeChange(APP_MODE_IDLE);
        UpdataDeviceState(DEVICE_STATE_IDLE);
        if (GetKlipperErrorKeyValue(state->webhooks.state_message.data) != 0) {
            UpdataErrorStateToManager(FAULT_DETECT_KLIPPER_WEB_HOOKS_ERROR, state->webhooks.state_message.data, NULL);
        }
    }
    else if (strcmp(readyState, "ready") == 0)
    {
        CrLogI("klipper ready\n");
        setEnableGetKlipperState(false);
        UpdataKlipperState(KLIPPER_STATE_READY);

        // 判断是否清除klipper错误码
        int code = GetPrintState().faultCode.code;
        if (code >= FAULT_KLIPPER_CODE_CONVERT && code < FAULT_DETECT_KLIPPER_CODE_SIZE) {
            UpdataErrorStateToManager(FAULT_CODE_IDLE, "", NULL);
        }
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} state
 */
static int CustomCalculationKlipperState(KlipperPrint_t state)
{
    if (GetCurrentAppstate() == APP_PRINT_STATE_WORK &&
        GetPrintState().klipperPrint == KLIPPER_PRINT_PRINTING)
    {
        // // 获取当前层数
        // uint32_t layer = GetPrintCurLayer(state);
        // UpdataPrintLayer(layer);
        // 获取进度
        int progress = GetPrintProgress(state) * 100 * 100 + 0.5;
        UpdataPrintProgress(progress);
        // 获取剩余时间
        int remainTime = GetPrintTimeEstimates(state);
        UpdataPrintRemainTime(remainTime);
        // 获取实时速度
        int speed = GetRealTimeSpeed(state) * 100 + 0.5;
        UpdataRealTimeSpeed(speed);
        // 获取实时流量
        int flow = GetRealTimeFlow(state) * 100 + 0.5;
        UpdataRealTimeFlow(flow);
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *obj
 */
static int KlipperObjectsResultAnl(json_object *obj)
{
    KlipperPrint_t *printer = GetPrinter();
    // 解析状态信息
    json_object *statusObj = json_object_object_get(obj, "status");
    if (statusObj != NULL && json_object_is_type(statusObj, json_type_object))
    {
        // 获取暂停状态信息
        json_object *pauseResumeObj = json_object_object_get(statusObj, "pause_resume");
        if (pauseResumeObj != NULL && json_object_is_type(pauseResumeObj, json_type_object))
        {
            json_object *isPausedObj = json_object_object_get(pauseResumeObj, "is_paused");
            if (isPausedObj != NULL && json_object_is_type(isPausedObj, json_type_boolean))
            {
                printer->pause_resume.is_paused = json_object_get_boolean(isPausedObj);
            }
        }
        // 获取热床状态信息
        json_object *heaterBedObj = json_object_object_get(statusObj, "heater_bed");
        if (heaterBedObj != NULL && json_object_is_type(heaterBedObj, json_type_object))
        {
            json_object *temperatureObj = json_object_object_get(heaterBedObj, "temperature");
            if (temperatureObj != NULL && json_object_is_type(temperatureObj, json_type_double))
            {
                printer->heater_bed.temperature = json_object_get_double(temperatureObj);
                int curTemp = printer->heater_bed.temperature * 100 + 0.5;
                UpdataBedCurTemp(curTemp, HOTBED_TEMP);
            }
            json_object *targetObj = json_object_object_get(heaterBedObj, "target");
            if (targetObj != NULL && json_object_is_type(targetObj, json_type_double))
            {
                printer->heater_bed.target = json_object_get_double(targetObj);
                int targetTemp = printer->heater_bed.target * 100 + 0.5;
                UpdataBedMaxTemp(targetTemp, HOTBED_TEMP);
            }
            else if (targetObj != NULL && json_object_is_type(targetObj, json_type_int))
            {
                printer->heater_bed.target = json_object_get_int(targetObj);
                int targetTemp = printer->heater_bed.target * 100 + 0.5;
                UpdataBedMaxTemp(targetTemp, HOTBED_TEMP);
            }
            json_object *powerObj = json_object_object_get(heaterBedObj, "power");
            if (powerObj != NULL && json_object_is_type(powerObj, json_type_double))
            {
                printer->heater_bed.power = json_object_get_double(powerObj);
                int power = printer->heater_bed.power * 100 + 0.5;
                UpdataBedPower(power, HOTBED_TEMP);
            }
        }
        // 获取热床状态信息
        json_object *heaterBed0Obj = json_object_object_get(statusObj, "heater_bed_0");
        if (heaterBed0Obj != NULL && json_object_is_type(heaterBed0Obj, json_type_object))
        {
            json_object *temperatureObj = json_object_object_get(heaterBed0Obj, "temperature");
            if (temperatureObj != NULL && json_object_is_type(temperatureObj, json_type_double))
            {
                printer->heater_bed_0.temperature = json_object_get_double(temperatureObj);
                int curTemp = printer->heater_bed_0.temperature * 100 + 0.5;
                UpdataBedCurTemp(curTemp, HOTBED_0_TEMP);
            }
            json_object *targetObj = json_object_object_get(heaterBed0Obj, "target");
            if (targetObj != NULL && json_object_is_type(targetObj, json_type_double))
            {
                printer->heater_bed_0.target = json_object_get_double(targetObj);
                int targetTemp = printer->heater_bed_0.target * 100 + 0.5;
                UpdataBedMaxTemp(targetTemp, HOTBED_0_TEMP);
            }
            else if (targetObj != NULL && json_object_is_type(targetObj, json_type_int))
            {
                printer->heater_bed_0.target = json_object_get_int(targetObj);
                int targetTemp = printer->heater_bed_0.target * 100 + 0.5;
                UpdataBedMaxTemp(targetTemp, HOTBED_0_TEMP);
            }
            json_object *powerObj = json_object_object_get(heaterBed0Obj, "power");
            if (powerObj != NULL && json_object_is_type(powerObj, json_type_double))
            {
                printer->heater_bed_0.power = json_object_get_double(powerObj);
                int power = printer->heater_bed_0.power * 100 + 0.5;
                UpdataBedPower(power, HOTBED_0_TEMP);
            }
        }
        // 获取热床状态信息
        json_object *heaterBed1Obj = json_object_object_get(statusObj, "heater_bed_1");
        if (heaterBed1Obj != NULL && json_object_is_type(heaterBed1Obj, json_type_object))
        {
            json_object *temperatureObj = json_object_object_get(heaterBed1Obj, "temperature");
            if (temperatureObj != NULL && json_object_is_type(temperatureObj, json_type_double))
            {
                printer->heater_bed_1.temperature = json_object_get_double(temperatureObj);
                int curTemp = printer->heater_bed_1.temperature * 100 + 0.5;
                UpdataBedCurTemp(curTemp, HOTBED_1_TEMP);
            }
            json_object *targetObj = json_object_object_get(heaterBed1Obj, "target");
            if (targetObj != NULL && json_object_is_type(targetObj, json_type_double))
            {
                printer->heater_bed_1.target = json_object_get_double(targetObj);
                int targetTemp = printer->heater_bed_1.target * 100 + 0.5;
                UpdataBedMaxTemp(targetTemp, HOTBED_1_TEMP);
            }
            else if (targetObj != NULL && json_object_is_type(targetObj, json_type_int))
            {
                printer->heater_bed_1.target = json_object_get_int(targetObj);
                int targetTemp = printer->heater_bed_1.target * 100 + 0.5;
                UpdataBedMaxTemp(targetTemp, HOTBED_1_TEMP);
            }
            json_object *powerObj = json_object_object_get(heaterBed1Obj, "power");
            if (powerObj != NULL && json_object_is_type(powerObj, json_type_double))
            {
                printer->heater_bed_1.power = json_object_get_double(powerObj);
                int power = printer->heater_bed_1.power * 100 + 0.5;
                UpdataBedPower(power, HOTBED_1_TEMP);
            }
        }
        // 获取热床状态信息
        json_object *heaterBed2Obj = json_object_object_get(statusObj, "heater_bed_2");
        if (heaterBed2Obj != NULL && json_object_is_type(heaterBed2Obj, json_type_object))
        {
            json_object *temperatureObj = json_object_object_get(heaterBed2Obj, "temperature");
            if (temperatureObj != NULL && json_object_is_type(temperatureObj, json_type_double))
            {
                printer->heater_bed_2.temperature = json_object_get_double(temperatureObj);
                int curTemp = printer->heater_bed_2.temperature * 100 + 0.5;
                UpdataBedCurTemp(curTemp, HOTBED_2_TEMP);
            }
            json_object *targetObj = json_object_object_get(heaterBed2Obj, "target");
            if (targetObj != NULL && json_object_is_type(targetObj, json_type_double))
            {
                printer->heater_bed_2.target = json_object_get_double(targetObj);
                int targetTemp = printer->heater_bed_2.target * 100 + 0.5;
                UpdataBedMaxTemp(targetTemp, HOTBED_2_TEMP);
            }
            else if (targetObj != NULL && json_object_is_type(targetObj, json_type_int))
            {
                printer->heater_bed_2.target = json_object_get_int(targetObj);
                int targetTemp = printer->heater_bed_2.target * 100 + 0.5;
                UpdataBedMaxTemp(targetTemp, HOTBED_2_TEMP);
            }
            json_object *powerObj = json_object_object_get(heaterBed2Obj, "power");
            if (powerObj != NULL && json_object_is_type(powerObj, json_type_double))
            {
                printer->heater_bed_2.power = json_object_get_double(powerObj);
                int power = printer->heater_bed_2.power * 100 + 0.5;
                UpdataBedPower(power, HOTBED_2_TEMP);
            }
        }
        // 获取喷嘴状态信息
        json_object *extruderObj = json_object_object_get(statusObj, "extruder");
        if (extruderObj != NULL && json_object_is_type(extruderObj, json_type_object))
        {
            json_object *temperatureObj = json_object_object_get(extruderObj, "temperature");
            if (temperatureObj != NULL && json_object_is_type(temperatureObj, json_type_double))
            {
                printer->extruder.temperature = json_object_get_double(temperatureObj);
                int curTemp = printer->extruder.temperature * 100 + 0.5;
                UpdataNozzleCurTemp(curTemp, NOZZLE_TEMP);
            }
            json_object *targetObj = json_object_object_get(extruderObj, "target");
            if (targetObj != NULL && json_object_is_type(targetObj, json_type_double))
            {
                printer->extruder.target = json_object_get_double(targetObj);
                int targetTemp = printer->extruder.target * 100 + 0.5;
                UpdataNozzleMaxTemp(targetTemp, NOZZLE_TEMP);
            }
            else if (targetObj != NULL && json_object_is_type(targetObj, json_type_int))
            {
                printer->extruder.target = json_object_get_int(targetObj);
                int targetTemp = printer->extruder.target * 100 + 0.5;
                UpdataNozzleMaxTemp(targetTemp, NOZZLE_TEMP);
            }
            json_object *powerObj = json_object_object_get(extruderObj, "power");
            if (powerObj != NULL && json_object_is_type(powerObj, json_type_double))
            {
                printer->extruder.power = json_object_get_double(powerObj);
                int power = printer->extruder.power * 100 + 0.5;
                UpdataNozzlePower(power, NOZZLE_TEMP);
            }
            json_object *pressureAdvanceObj = json_object_object_get(extruderObj, "pressure_advance");
            if (pressureAdvanceObj != NULL && json_object_is_type(pressureAdvanceObj, json_type_double))
            {
                printer->extruder.pressure_advance = json_object_get_double(pressureAdvanceObj);
                PrintSavePara_t updataPara = GetPrintSavePara();
                updataPara.pressureAdvance = printer->extruder.pressure_advance * 1000 + 0.5;
                UpdataPrintSavePara(updataPara);
                CrLogI("pressure advance = %f", printer->extruder.pressure_advance);
            }
            json_object *smoothTimeObj = json_object_object_get(extruderObj, "smooth_time");
            if (smoothTimeObj != NULL && json_object_is_type(smoothTimeObj, json_type_double))
            {
                printer->extruder.smooth_time = json_object_get_double(smoothTimeObj);
                PrintSavePara_t updataPara = GetPrintSavePara();
                updataPara.SmoothTime = printer->extruder.smooth_time * 1000 + 0.5;
                UpdataPrintSavePara(updataPara);
                CrLogI("smooth time = %f", printer->extruder.smooth_time);
            }
        }
        // 获取腔体状态信息
        json_object *chamberTempObj = json_object_object_get(statusObj, "temperature_sensor chamber_temp");
        if (chamberTempObj != NULL && json_object_is_type(chamberTempObj, json_type_object))
        {
            json_object *temperatureObj = json_object_object_get(chamberTempObj, "temperature");
            if (temperatureObj != NULL && json_object_is_type(temperatureObj, json_type_double))
            {
                printer->chamber_temp.temperature = json_object_get_double(temperatureObj);
                int curTemp = printer->chamber_temp.temperature * 100 + 0.5;
                UpdataOtherCurTemp(curTemp, OTHER_TEMP_CAVITY);
            }
        }
        // 获取运动报告
        json_object *motionReportObj = json_object_object_get(statusObj, "motion_report");
        if (motionReportObj != NULL && json_object_is_type(motionReportObj, json_type_object))
        {
            // 现场位置
            json_object *livePositionObj = json_object_object_get(motionReportObj, "live_position");
            if (livePositionObj != NULL && json_object_is_type(livePositionObj, json_type_array))
            {
                double positionData[10] = {0};
                for(int i = 0; i < json_object_array_length(livePositionObj); i++) {
                    json_object *dataObj = json_object_array_get_idx(livePositionObj, i);
                    positionData[i] = json_object_get_double(dataObj);
                    printer->motion_report.live_position[i] = positionData[i];
                }
                // 更新位置数据
                Coordinate_t updataPosition = {0};
                updataPosition.x = positionData[0] * 1000 + 0.5;
                updataPosition.y = positionData[1] * 1000 + 0.5;
                updataPosition.z = positionData[2] * 1000 + 0.5;
                updataPosition.e = positionData[3] * 1000 + 0.5;
                UpdataLivePosition(updataPosition);
                CrLogI("live position; x = %d, y = %d, z = %d, e = %d",
                    updataPosition.x, updataPosition.y, updataPosition.z, updataPosition.e);
            }
        }
        // 获取打印状态信息
        json_object *printStatsObj = json_object_object_get(statusObj, "print_stats");
        if (printStatsObj != NULL && json_object_is_type(printStatsObj, json_type_object))
        {
            // 打印文件名称
            json_object *filenameObj = json_object_object_get(printStatsObj, "filename");
            if (filenameObj != NULL && json_object_is_type(filenameObj, json_type_string))
            {
                String_t *filenameTemp = &(printer->print_stats.filename);
                filenameTemp->len = json_object_get_string_len(filenameObj);
                filenameTemp->data = (char*)realloc(filenameTemp->data, filenameTemp->len + 1);
                memset(filenameTemp->data, 0, filenameTemp->len + 1);
                memcpy(filenameTemp->data, json_object_get_string(filenameObj), filenameTemp->len);
            }
            // 打印时间
            json_object *printDurationObj = json_object_object_get(printStatsObj, "print_duration");
            if (printDurationObj != NULL && json_object_is_type(printDurationObj, json_type_double))
            {
                printer->print_stats.print_duration = json_object_get_double(printDurationObj);
                uint32_t printTime = json_object_get_double(printDurationObj);
                UpdataPrintUsageTime(printTime);
            }
            // 打印总时间
            json_object *totalDurationObj = json_object_object_get(printStatsObj, "total_duration");
            if (totalDurationObj != NULL && json_object_is_type(totalDurationObj, json_type_double))
            {
                printer->print_stats.total_duration = json_object_get_double(totalDurationObj);
            }
            // 耗材使用长度
            json_object *filamentUsedObj = json_object_object_get(printStatsObj, "filament_used");
            if (filamentUsedObj != NULL && json_object_is_type(filamentUsedObj, json_type_double))
            {
                printer->print_stats.filament_used = json_object_get_double(filamentUsedObj);
                // klipper返回的材料使用量，实际是E轴坐标；需要避免回抽对材料使用量计算的影响
                if (printer->print_stats.filament_used == 0 || 
                    printer->print_stats.filament_used > printer->print_stats.filament_used_real)
                {
                    printer->print_stats.filament_used_real = printer->print_stats.filament_used;
                    UpdataFilamentUsed(printer->print_stats.filament_used_real * 100 + 0.5);
                }
            }
            // 工作状态
            json_object *stateObj = json_object_object_get(printStatsObj, "state");
            if (stateObj != NULL && json_object_is_type(stateObj, json_type_string))
            {
                String_t *stateTemp = &(printer->print_stats.state);
                stateTemp->len = json_object_get_string_len(stateObj);
                stateTemp->data = (char*)realloc(stateTemp->data, stateTemp->len + 1);
                memset(stateTemp->data, 0, stateTemp->len + 1);
                memcpy(stateTemp->data, json_object_get_string(stateObj), stateTemp->len);

                SyncKlipperPrintState(printer, printStatsObj);
            }
        }
        // 获取运动报告
        json_object *gcodeMoveObj = json_object_object_get(statusObj, "gcode_move");
        if (gcodeMoveObj != NULL && json_object_is_type(gcodeMoveObj, json_type_object))
        {
            json_object *gcodePositionObj = json_object_object_get(gcodeMoveObj, "gcode_position");
            if (gcodePositionObj != NULL && json_object_is_type(gcodePositionObj, json_type_array))
            {
                // 获取位置信息
                double positionData[10] = {0};
                for(int i = 0; i < json_object_array_length(gcodePositionObj); i++) {
                    json_object *dataObj = json_object_array_get_idx(gcodePositionObj, i);
                    positionData[i] = json_object_get_double(dataObj);
                    printer->gcode_move.gcode_position[i] = positionData[i];
                }
                // 更新位置数据
                Coordinate_t updataPosition = {0};
                updataPosition.x = positionData[0] * 1000 + 0.5;
                updataPosition.y = positionData[1] * 1000 + 0.5;
                updataPosition.z = positionData[2] * 1000 + 0.5;
                updataPosition.e = positionData[3] * 1000 + 0.5;
                UpdataGcodePosition(updataPosition);
                CrLogI("gcode position; x = %d, y = %d, z = %d, e = %d",
                    updataPosition.x, updataPosition.y, updataPosition.z, updataPosition.e);
            }
            json_object *homingOriginObj = json_object_object_get(gcodeMoveObj, "homing_origin");
            if (homingOriginObj != NULL && json_object_is_type(homingOriginObj, json_type_array))
            {
                // 获取原点偏移
                double homeOffset[10] = {0};
                for(int i = 0; i < json_object_array_length(homingOriginObj); i++) {
                    json_object *dataObj = json_object_array_get_idx(homingOriginObj, i);
                    homeOffset[i] = json_object_get_double(dataObj);
                    printer->gcode_move.homing_origin[i] = homeOffset[i];
                }
                CrLogI("homing origin; x = %f, y = %f, z = %f, e = %f",
                    homeOffset[0], homeOffset[1], homeOffset[2], homeOffset[3]);

                // 更新位置数据
                PrintSavePara_t updataPara = GetPrintSavePara();
                updataPara.homeOffset.x = homeOffset[0] * 1000 + 0.5;
                updataPara.homeOffset.y = homeOffset[1] * 1000 + 0.5;
                updataPara.homeOffset.z = homeOffset[2] * 1000 + 0.5;
                updataPara.homeOffset.e = homeOffset[3] * 1000 + 0.5;
                UpdataPrintSavePara(updataPara);
            }
            json_object *speedObj = json_object_object_get(gcodeMoveObj, "speed");
            if (speedObj != NULL && json_object_is_type(speedObj, json_type_double))
            {
                printer->gcode_move.speed = json_object_get_double(speedObj);
            }
            json_object *absoluteCoordinatesObj = json_object_object_get(gcodeMoveObj, "absolute_coordinates");
            if (absoluteCoordinatesObj != NULL && json_object_is_type(absoluteCoordinatesObj, json_type_boolean))
            {
                printer->gcode_move.absolute_coordinates = json_object_get_boolean(absoluteCoordinatesObj);
            }
            json_object *speedFactorObj = json_object_object_get(gcodeMoveObj, "speed_factor");
            if (speedFactorObj != NULL && json_object_is_type(speedFactorObj, json_type_double))
            {
                // 获取打印倍速
                printer->gcode_move.speed_factor = json_object_get_double(speedFactorObj);
                uint32_t speedFactor = json_object_get_double(speedFactorObj) * 100 + 0.5;
                UpdataPrintSpeed(speedFactor);
                CrLogI("speed factor = %d", speedFactor);
            }
            json_object *extrudeFactorObj = json_object_object_get(gcodeMoveObj, "extrude_factor");
            if (extrudeFactorObj != NULL && json_object_is_type(extrudeFactorObj, json_type_double))
            {
                // 获取打印流量
                printer->gcode_move.extrude_factor = json_object_get_double(extrudeFactorObj);
                uint32_t extrudeFactor = json_object_get_double(extrudeFactorObj) * 100 + 0.5;
                UpdataPrintFlow(extrudeFactor);
                CrLogI("extrude factor = %d", extrudeFactor);
            }
        }
        // 获取模型风扇状态
        json_object *modelFanObj = json_object_object_get(statusObj, "output_pin fan0");
        if (modelFanObj != NULL && json_object_is_type(modelFanObj, json_type_object))
        {
            json_object *speedObj = json_object_object_get(modelFanObj, "value");
            if (speedObj != NULL && json_object_is_type(speedObj, json_type_double))
            {
                printer->modelFan.speed = json_object_get_double(speedObj);
                UpdataPrintFanState(DutyCycleToPercentage(printer->modelFan.speed), MULTI_FAN_MODEL);
                UpdataPrintFanPercentage(FloatToPercentage(printer->modelFan.speed, MULTI_FAN_MODEL), MULTI_FAN_MODEL);
            }
        }
        // 获取机箱风扇状态
        json_object *caseFanObj = json_object_object_get(statusObj, "output_pin fan1");
        if (caseFanObj != NULL && json_object_is_type(caseFanObj, json_type_object))
        {
            json_object *speedObj = json_object_object_get(caseFanObj, "value");
            if (speedObj != NULL && json_object_is_type(speedObj, json_type_double))
            {
                printer->caseFan.speed = json_object_get_double(speedObj);
                UpdataPrintFanState(DutyCycleToPercentage(printer->caseFan.speed), MULTI_FAN_CASE);
                UpdataPrintFanPercentage(FloatToPercentage(printer->caseFan.speed, MULTI_FAN_CASE), MULTI_FAN_CASE);
            }
        }
        // 获取辅助风扇状态
        json_object *auxiliaryFanObj = json_object_object_get(statusObj, "output_pin fan2");
        if (auxiliaryFanObj != NULL && json_object_is_type(auxiliaryFanObj, json_type_object))
        {
            json_object *speedObj = json_object_object_get(auxiliaryFanObj, "value");
            if (speedObj != NULL && json_object_is_type(speedObj, json_type_double))
            {
                printer->auxiliaryFan.speed = json_object_get_double(speedObj);
                UpdataPrintFanState(DutyCycleToPercentage(printer->auxiliaryFan.speed), MULTI_FAN_AUXILIARY);
                UpdataPrintFanPercentage(FloatToPercentage(printer->auxiliaryFan.speed, MULTI_FAN_AUXILIARY), MULTI_FAN_AUXILIARY);
            }
        }
        // 获取风扇状态反馈
        json_object *fanFeedbackObj = json_object_object_get(statusObj, "fan_feedback");
        if (fanFeedbackObj != NULL && json_object_is_type(fanFeedbackObj, json_type_object))
        {
            CrLogI("fan_feedback = %s", json_object_to_json_string(fanFeedbackObj));
            json_object *fan0SpeedObj = json_object_object_get(fanFeedbackObj, "fan0_speed");
            // 区分不同机型硬件情况不同
            switch (GetSystemConfig().model)
            {
            case PF_05:
                if (fan0SpeedObj != NULL && json_object_is_type(fan0SpeedObj, json_type_int))
                {
                    printer->fan_feedback.fan1_speed = json_object_get_int(fan0SpeedObj);
                    UpdataPrintFanSpeed(printer->fan_feedback.fan1_speed, MULTI_FAN_MOTHERBOARD);
                }
                break;
            case CR_K1:
            case CR_K1_Max:
                {
                    if (fan0SpeedObj != NULL && json_object_is_type(fan0SpeedObj, json_type_int))
                    {
                        printer->fan_feedback.fan0_speed = json_object_get_int(fan0SpeedObj);
                        UpdataPrintFanSpeed(printer->fan_feedback.fan0_speed, MULTI_FAN_THROAT);
                    }
                    json_object *fan1SpeedObj = json_object_object_get(fanFeedbackObj, "fan1_speed");
                    if (fan1SpeedObj != NULL && json_object_is_type(fan1SpeedObj, json_type_int))
                    {
                        printer->fan_feedback.fan1_speed = json_object_get_int(fan1SpeedObj);
                        UpdataPrintFanSpeed(printer->fan_feedback.fan1_speed, MULTI_FAN_MOTHERBOARD);
                    }
                }
                break;
            default:
                {
                    break;
                }
            }
        }
        // 获取显示信息
        json_object *displayStatusObj = json_object_object_get(statusObj, "display_status");
        if (displayStatusObj != NULL && json_object_is_type(displayStatusObj, json_type_object))
        {
            json_object *progressObj = json_object_object_get(displayStatusObj, "progress");
            if (progressObj != NULL && json_object_is_type(progressObj, json_type_double))
            {
                printer->display_status.progress = json_object_get_double(progressObj);
            }
        }
        // 获取模拟SD卡信息
        json_object *virtualSdcardObj = json_object_object_get(statusObj, "virtual_sdcard");
        if (virtualSdcardObj != NULL && json_object_is_type(virtualSdcardObj, json_type_object))
        {
            json_object *progressObj = json_object_object_get(virtualSdcardObj, "progress");
            if (progressObj != NULL && json_object_is_type(progressObj, json_type_double))
            {
                printer->virtual_sdcard.progress = json_object_get_double(progressObj);
            }
            json_object *filePositionObj = json_object_object_get(virtualSdcardObj, "file_position");
            if (filePositionObj != NULL && json_object_is_type(filePositionObj, json_type_int))
            {
                printer->virtual_sdcard.file_position = json_object_get_int(filePositionObj);
            }
            json_object *isActiveObj = json_object_object_get(virtualSdcardObj, "is_active");
            if (isActiveObj != NULL && json_object_is_type(isActiveObj, json_type_boolean))
            {
                printer->virtual_sdcard.is_active = json_object_get_boolean(isActiveObj);
            }
            json_object *filePathObj = json_object_object_get(virtualSdcardObj, "file_path");
            if (filePathObj != NULL && json_object_is_type(filePathObj, json_type_string))
            {
                String_t *filePathTemp = &(printer->virtual_sdcard.file_path);
                filePathTemp->len = json_object_get_string_len(filePathObj);
                filePathTemp->data = (char*)realloc(filePathTemp->data, filePathTemp->len + 1);
                memset(filePathTemp->data, 0, filePathTemp->len + 1);
                memcpy(filePathTemp->data, json_object_get_string(filePathObj), filePathTemp->len);
            }
            json_object *fileSizeObj = json_object_object_get(virtualSdcardObj, "file_size");
            if (fileSizeObj != NULL && json_object_is_type(fileSizeObj, json_type_int))
            {
                printer->virtual_sdcard.file_size = json_object_get_int(fileSizeObj);
            }
            json_object *firstLayerStopObj = json_object_object_get(virtualSdcardObj, "first_layer_stop");
            if (firstLayerStopObj != NULL && json_object_is_type(firstLayerStopObj, json_type_boolean))
            {
                printer->virtual_sdcard.first_layer_stop = json_object_get_boolean(firstLayerStopObj);
                CrLogI("first_layer_stop = %d", printer->virtual_sdcard.first_layer_stop);
            }
            json_object *layerObj = json_object_object_get(virtualSdcardObj, "layer");
            if (layerObj != NULL && json_object_is_type(layerObj, json_type_int))
            {
                printer->virtual_sdcard.last_layer = printer->virtual_sdcard.layer;
                printer->virtual_sdcard.layer = json_object_get_int(layerObj);
                CrLogI("layer = %d", printer->virtual_sdcard.layer);
                UpdataPrintLayer(printer->virtual_sdcard.layer);
            }
            json_object *layerCountObj = json_object_object_get(virtualSdcardObj, "layer_count");
            if (layerCountObj != NULL && json_object_is_type(layerCountObj, json_type_int))
            {
                printer->virtual_sdcard.last_layer_count = printer->virtual_sdcard.layer_count;
                printer->virtual_sdcard.layer_count = json_object_get_int(layerCountObj);
                CrLogI("layer_count = %d", printer->virtual_sdcard.layer_count);
                UpdataPrintLayers(printer->virtual_sdcard.layer_count);
            }
            json_object *runDisObj = json_object_object_get(virtualSdcardObj, "run_dis");
            if (runDisObj != NULL && json_object_is_type(runDisObj, json_type_double))
            {
                printer->virtual_sdcard.run_dis = json_object_get_double(runDisObj);
                CrLogI("run_dis = %f", printer->virtual_sdcard.run_dis);
            }
        }
        // 获取断料检测信息
        json_object *filamentSensorObj = json_object_object_get(statusObj, "filament_switch_sensor filament_sensor");
        if (filamentSensorObj != NULL && json_object_is_type(filamentSensorObj, json_type_object))
        {
            json_object *filamentDetectedObj = json_object_object_get(filamentSensorObj, "filament_detected");
            if (filamentDetectedObj != NULL && json_object_is_type(filamentDetectedObj, json_type_boolean))
            {
                printer->filament_sensor.filament_detected = json_object_get_boolean(filamentDetectedObj);
                CrLogI("filament_sensor filament_detected = %d", printer->filament_sensor.filament_detected);
                if (printer->filament_sensor.filament_detected)
                    UpdataPrintMaterialStatus(MATERIAL_STATUS_IDLE, MATERIAL_DETECTOR_1);
                else UpdataPrintMaterialStatus(MATERIAL_STATUS_BLANKING, MATERIAL_DETECTOR_1);
            }
            json_object *enabledObj = json_object_object_get(filamentSensorObj, "enabled");
            if (enabledObj != NULL && json_object_is_type(enabledObj, json_type_boolean))
            {
                printer->filament_sensor.enabled = json_object_get_boolean(enabledObj);
                CrLogI("filament_sensor enabled = %d", printer->filament_sensor.enabled);
                PrintSavePara_t updataPara = GetPrintSavePara();
                updataPara.materialDetect = printer->filament_sensor.enabled;
                UpdataPrintSavePara(updataPara);
            }
        }
        // 获取断料检测2信息
        json_object *filamentSensor2Obj = json_object_object_get(statusObj, "filament_switch_sensor filament_sensor_2");
        if (filamentSensor2Obj != NULL && json_object_is_type(filamentSensor2Obj, json_type_object))
        {
            json_object *filamentDetectedObj = json_object_object_get(filamentSensor2Obj, "filament_detected");
            if (filamentDetectedObj != NULL && json_object_is_type(filamentDetectedObj, json_type_boolean))
            {
                printer->filament_sensor_2.filament_detected = json_object_get_boolean(filamentDetectedObj);
                CrLogI("filament_sensor_2 filament_detected = %d", printer->filament_sensor_2.filament_detected);
                if (printer->filament_sensor_2.filament_detected)
                    UpdataPrintMaterialStatus(MATERIAL_STATUS_IDLE, MATERIAL_DETECTOR_2);
                else UpdataPrintMaterialStatus(MATERIAL_STATUS_BLANKING, MATERIAL_DETECTOR_2);
            }
            json_object *enabledObj = json_object_object_get(filamentSensor2Obj, "enabled");
            if (enabledObj != NULL && json_object_is_type(enabledObj, json_type_boolean))
            {
                printer->filament_sensor_2.enabled = json_object_get_boolean(enabledObj);
                CrLogI("filament_sensor_2 enabled = %d", printer->filament_sensor_2.enabled);
            }
        }
        // 获取工具头信息
        json_object *toolheadObj = json_object_object_get(statusObj, "toolhead");
        if (toolheadObj != NULL && json_object_is_type(toolheadObj, json_type_object))
        {
            json_object *printTimeObj = json_object_object_get(toolheadObj, "print_time");
            if (printTimeObj != NULL && json_object_is_type(printTimeObj, json_type_double))
            {
                printer->toolhead.print_time = json_object_get_double(printTimeObj);
            }
            json_object *estimatedPrintTimeObj = json_object_object_get(toolheadObj, "estimated_print_time");
            if (estimatedPrintTimeObj != NULL && json_object_is_type(estimatedPrintTimeObj, json_type_double))
            {
                printer->toolhead.estimated_print_time = json_object_get_double(estimatedPrintTimeObj);
            }
            json_object *homedAxesObj = json_object_object_get(toolheadObj, "homed_axes");
            if (homedAxesObj != NULL && json_object_is_type(homedAxesObj, json_type_string))
            {
                String_t *homedAxesTemp = &(printer->toolhead.homed_axes);
                homedAxesTemp->len = json_object_get_string_len(homedAxesObj);
                homedAxesTemp->data = (char*)realloc(homedAxesTemp->data, homedAxesTemp->len + 1);
                memset(homedAxesTemp->data, 0, homedAxesTemp->len + 1);
                memcpy(homedAxesTemp->data, json_object_get_string(homedAxesObj), homedAxesTemp->len);

                // 更新轴归位信息
                Coordinate_t homedAxes = {0};
                if (strstr(homedAxesTemp->data, "x")) homedAxes.x = 1;
                else homedAxes.x = 0;
                if (strstr(homedAxesTemp->data, "y")) homedAxes.y = 1;
                else homedAxes.y = 0;
                if (strstr(homedAxesTemp->data, "z")) homedAxes.z = 1;
                else homedAxes.z = 0;
                UpdataHomedAxes(homedAxes);
                CrLogI("homed axes; x = %d, y = %d, z = %d", homedAxes.x, homedAxes.y, homedAxes.z);
            }
            json_object *maxVelocityObj = json_object_object_get(toolheadObj, "max_velocity");
            if (maxVelocityObj != NULL && json_object_is_type(maxVelocityObj, json_type_double))
            {
                printer->toolhead.max_velocity = json_object_get_double(maxVelocityObj);
                PrintSavePara_t updataPara = GetPrintSavePara();
                updataPara.k_Speed = printer->toolhead.max_velocity * 1000 + 0.5;
                UpdataPrintSavePara(updataPara);
                CrLogI("max velocity = %f", printer->toolhead.max_velocity);
            }
            json_object *maxAccelObj = json_object_object_get(toolheadObj, "max_accel");
            if (maxAccelObj != NULL && json_object_is_type(maxAccelObj, json_type_double))
            {
                printer->toolhead.max_accel = json_object_get_double(maxAccelObj);
                PrintSavePara_t updataPara = GetPrintSavePara();
                updataPara.k_Acceleration = printer->toolhead.max_accel * 1000 + 0.5;
                UpdataPrintSavePara(updataPara);
                CrLogI("max accel = %f", printer->toolhead.max_accel);
            }
            json_object *squareCornerVelocitylObj = json_object_object_get(toolheadObj, "square_corner_velocity");
            if (squareCornerVelocitylObj != NULL && json_object_is_type(squareCornerVelocitylObj, json_type_double))
            {
                printer->toolhead.square_corner_velocity = json_object_get_double(squareCornerVelocitylObj);
                PrintSavePara_t updataPara = GetPrintSavePara();
                updataPara.k_Corner = printer->toolhead.square_corner_velocity * 1000 + 0.5;
                UpdataPrintSavePara(updataPara);
                CrLogI("square corner velocity = %f", printer->toolhead.square_corner_velocity);
            }
            json_object *maxAccelToDecelObj = json_object_object_get(toolheadObj, "max_accel_to_decel");
            if (maxAccelToDecelObj != NULL && json_object_is_type(maxAccelToDecelObj, json_type_double))
            {
                printer->toolhead.max_accel_to_decel = json_object_get_double(maxAccelToDecelObj);
                PrintSavePara_t updataPara = GetPrintSavePara();
                updataPara.k_Jerk = printer->toolhead.max_accel_to_decel * 1000 + 0.5;
                UpdataPrintSavePara(updataPara);
                CrLogI("max accel to decel = %f", printer->toolhead.max_accel_to_decel);
            }
        }
        // 获取网络挂钩信息
        json_object *webhooksObj = json_object_object_get(statusObj, "webhooks");
        if (webhooksObj != NULL && json_object_is_type(webhooksObj, json_type_object))
        {
            json_object *stateObj = json_object_object_get(webhooksObj, "state");
            if (stateObj != NULL && json_object_is_type(stateObj, json_type_string))
            {
                String_t *stateTemp = &(printer->webhooks.state);
                stateTemp->len = json_object_get_string_len(stateObj);
                stateTemp->data = (char*)realloc(stateTemp->data, stateTemp->len + 1);
                memset(stateTemp->data, 0, stateTemp->len + 1);
                memcpy(stateTemp->data, json_object_get_string(stateObj), stateTemp->len);

                SyncKlipperPrepareState(printer, webhooksObj);
            }
        }
        // 获取加热器状态
        json_object *heatersObj = json_object_object_get(statusObj, "heaters");
        if (heatersObj != NULL && json_object_is_type(heatersObj, json_type_object))
        {
            CrLogI("heaters = %s", json_object_to_json_string(heatersObj));
            json_object *bedtTempWaitObj = json_object_object_get(heatersObj, "bed_temperature_wait");
            if (bedtTempWaitObj != NULL && json_object_is_type(bedtTempWaitObj, json_type_boolean))
            {
                printer->heaters.bed_temperature_wait = json_object_get_boolean(bedtTempWaitObj);
                UpdataBedTempWait(printer->heaters.bed_temperature_wait);
                CrLogI("bed_temperature_wait = %d", printer->heaters.bed_temperature_wait);
            }
            json_object *extruderTempWaitObj = json_object_object_get(heatersObj, "extruder_temperature_wait");
            if (extruderTempWaitObj != NULL && json_object_is_type(extruderTempWaitObj, json_type_boolean))
            {
                printer->heaters.extruder_temperature_wait = json_object_get_boolean(extruderTempWaitObj);
                UpdataNozzleTempWait(printer->heaters.extruder_temperature_wait);
                CrLogI("extruder_temperature_wait = %d", printer->heaters.extruder_temperature_wait);
            }
        }
        // 获取探测器状态
        json_object *probeObj = json_object_object_get(statusObj, "probe");
        if (probeObj != NULL && json_object_is_type(probeObj, json_type_object))
        {
            CrLogI("probe = %s", json_object_to_json_string(probeObj));
            json_object *zOffsetObj = json_object_object_get(probeObj, "z_offset");
            if (zOffsetObj != NULL && json_object_is_type(zOffsetObj, json_type_double))
            {
                // 获取轴补偿
                printer->probe.z_offset = json_object_get_double(zOffsetObj);
                CrLogI("z_offset = %f", printer->probe.z_offset);
                // 更新偏移数据
                PrintSavePara_t updataPara = GetPrintSavePara();
                updataPara.axisRecoup.z = printer->probe.z_offset * 1000 + 0.5;
                UpdataPrintSavePara(updataPara);
            }
        }
        // 获取打印对象
        json_object *excludeObjectObj = json_object_object_get(statusObj, "exclude_object");
        if (excludeObjectObj != NULL && json_object_is_type(excludeObjectObj, json_type_object))
        {
            // 解析json数据
            json_object_object_foreach(excludeObjectObj, key, val)
            {
                CrLogI("exclude_object; key = %s", key);
                if (strcmp(key, "objects") == 0)
                {
                    if (val != NULL && json_object_is_type(val, json_type_array))
                    {
                        const char *str = json_object_to_json_string(val);
                        String_t *object = &(printer->exclude_object.objects);
                        object->len = strlen(str);
                        object->data = (char*)realloc(object->data, object->len + 1);
                        bzero(object->data, object->len + 1);
                        memcpy(object->data, str, object->len);
                        CrLogI("exclude_object; objects = %s\n", object->data);
                    }
                }
                else if (strcmp(key, "excluded_objects") == 0)
                {
                    if (val != NULL && json_object_is_type(val, json_type_array))
                    {
                        const char *str = json_object_to_json_string(val);
                        String_t *object = &(printer->exclude_object.excluded_objects);
                        object->len = strlen(str);
                        object->data = (char*)realloc(object->data, object->len + 1);
                        bzero(object->data, object->len + 1);
                        memcpy(object->data, str, object->len);
                        CrLogI("exclude_object; excluded_objects = %s\n", object->data);
                    }
                }
                else if (strcmp(key, "current_object") == 0)
                {
                    if (val != NULL && json_object_is_type(val, json_type_string))
                    {
                        const char *str = json_object_get_string(val);
                        String_t *object = &(printer->exclude_object.current_object);
                        object->len = strlen(str);
                        object->data = (char*)realloc(object->data, object->len + 1);
                        bzero(object->data, object->len + 1);
                        memcpy(object->data, str, object->len);
                        CrLogI("exclude_object; current_object = %s\n", object->data);
                    }
                }
            }
            
            // 更新对象排除信息到共享内存
            exclude_object_t object = GetPrinter()->exclude_object;
            json_object *result = json_object_new_object();

            if (object.objects.data) json_object_object_add(result, "objects", json_tokener_parse(object.objects.data));
            else json_object_object_add(result, "objects", json_tokener_parse("[]"));
            if (object.excluded_objects.data) json_object_object_add(result, "excluded_objects", json_tokener_parse(object.excluded_objects.data));
            else json_object_object_add(result, "excluded_objects", json_tokener_parse("[]"));
            if (object.current_object.data) json_object_object_add(result, "current_object", json_object_new_string_len(object.current_object.data, object.current_object.len));
            else json_object_object_add(result, "current_object", json_object_new_string_len("", 0));

            char *resultStr = (char*)json_object_to_json_string(result);
            UpdataPrintObjectInfo(resultStr, strlen(resultStr));
            json_object_put(result);
            
            // 同步状态打印对象
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_SYNC_PRINT_OBJECT_INFO, "", 0);
            MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
            MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
            MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
        }


        // 静音模式宏指令
        json_object *qmodeObj = json_object_object_get(statusObj, "gcode_macro Qmode");
        if (qmodeObj != NULL && json_object_is_type(qmodeObj, json_type_object))
        {
            json_object *flagObj = json_object_object_get(qmodeObj, "flag");
            if (flagObj != NULL && json_object_is_type(flagObj, json_type_int))
            {
                printer->gcode_macro_Qmode.flag = json_object_get_int(flagObj);
                CrLogI("gcode_macro Qmode flag = %d", printer->gcode_macro_Qmode.flag);
                UpdataQmodeFlag(printer->gcode_macro_Qmode.flag);
            }
        }
        // 打印机参数宏指令
        json_object *printerParamObj = json_object_object_get(statusObj, "gcode_macro PRINTER_PARAM");
        if (printerParamObj != NULL && json_object_is_type(printerParamObj, json_type_object))
        {
            json_object *fan0MinObj = json_object_object_get(printerParamObj, "fan0_min");
            if (fan0MinObj != NULL && json_object_is_type(fan0MinObj, json_type_int))
            {
                printer->gcode_macro_Printer_Param.fan0_min = json_object_get_int(fan0MinObj);
                CrLogI("gcode macro printer param fan0 min = %d", printer->gcode_macro_Printer_Param.fan0_min);
            }
            json_object *fan1MinObj = json_object_object_get(printerParamObj, "fan1_min");
            if (fan1MinObj != NULL && json_object_is_type(fan1MinObj, json_type_int))
            {
                printer->gcode_macro_Printer_Param.fan1_min = json_object_get_int(fan1MinObj);
                CrLogI("gcode macro printer param fan1 min = %d", printer->gcode_macro_Printer_Param.fan1_min);
            }
            json_object *fan2MinObj = json_object_object_get(printerParamObj, "fan2_min");
            if (fan2MinObj != NULL && json_object_is_type(fan2MinObj, json_type_int))
            {
                printer->gcode_macro_Printer_Param.fan2_min = json_object_get_int(fan2MinObj);
                CrLogI("gcode macro printer param fan2 min = %d", printer->gcode_macro_Printer_Param.fan2_min);
            }
        }

        // 通过klipper消息，计算期望数据
        CustomCalculationKlipperState(*printer);
    }

    // 获取当前时间戳
    json_object *eventtimeObj = json_object_object_get(obj, "eventtime");
    if (eventtimeObj != NULL && json_object_is_type(eventtimeObj, json_type_double))
    {
        printer->eventtime = json_object_get_double(eventtimeObj);
        CrLogD("eventtime = %lf", printer->eventtime);
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperGetDeviceInfoResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;
    
    // 解析 "info" 接口返回结果
    json_object *klipperPathObj = json_object_object_get(resObj, "klipper_path");
    if (klipperPathObj != NULL && json_object_is_type(klipperPathObj, json_type_string))
    {
        CrLogI("klipper_path = %s", json_object_to_json_string_ext(klipperPathObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    }

    json_object *configFileObj = json_object_object_get(resObj, "config_file");
    if (configFileObj != NULL && json_object_is_type(configFileObj, json_type_string))
    {
        CrLogI("config_file = %s", json_object_to_json_string_ext(configFileObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    }

    json_object *softwareVersionObj = json_object_object_get(resObj, "software_version");
    if (softwareVersionObj != NULL && json_object_is_type(softwareVersionObj, json_type_string))
    {
        CrLogI("software_version = %s", json_object_to_json_string_ext(softwareVersionObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    }

    json_object *hostnameObj = json_object_object_get(resObj, "hostname");
    if (hostnameObj != NULL && json_object_is_type(hostnameObj, json_type_string))
    {
        CrLogI("hostname = %s", json_object_to_json_string_ext(hostnameObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    }

    json_object *cpuInfoObj = json_object_object_get(resObj, "cpu_info");
    if (cpuInfoObj != NULL && json_object_is_type(cpuInfoObj, json_type_string))
    {
        CrLogI("cpu_info = %s", json_object_to_json_string_ext(cpuInfoObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    }

    json_object *pythonPathObj = json_object_object_get(resObj, "python_path");
    if (pythonPathObj != NULL && json_object_is_type(pythonPathObj, json_type_string))
    {
        CrLogI("python_path = %s", json_object_to_json_string_ext(pythonPathObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    }

    json_object *logFileObj = json_object_object_get(resObj, "log_file");
    if (logFileObj != NULL && json_object_is_type(logFileObj, json_type_string))
    {
        CrLogI("log_file = %s", json_object_to_json_string_ext(logFileObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    }

    json_object *stateObj = json_object_object_get(resObj, "state");
    if (stateObj != NULL && json_object_is_type(stateObj, json_type_string))
    {
        const char *stateStr = json_object_get_string(stateObj);
        CrLogI("state = %s", stateStr);

        KlipperPrint_t *printer = GetPrinter();
        String_t *stateTemp = &(printer->webhooks.state);
        stateTemp->len = json_object_get_string_len(stateObj);
        stateTemp->data = (char*)realloc(stateTemp->data, stateTemp->len + 1);
        memset(stateTemp->data, 0, stateTemp->len + 1);
        memcpy(stateTemp->data, stateStr, stateTemp->len);

        SyncKlipperPrepareState(printer, resObj);
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperReadyHandshakeResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    // 清空发送链表
    ClearKlipperSendGcodeList();
    // 停止独立模块
    CancelFuncModule();
    // 解析info
    KlipperGetDeviceInfoResult(send, resultObj);

    // 是否需要重新获取配置文件
    if (GetSyncKlipperConfigFile()) {
        CrLogI("klipper ready handshake success\n");
        KlipperInitGetObjectsConfig();
    }

    // 处理状态
    if (strcmp(GetPrinter()->webhooks.state.data, "ready") == 0) {
        // 重新初始化 klipper
        MsaterShareStateInit();
        // 置位连接标志
        UpdataSerialPort(1);
        UpdataSdCardExists(1);
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperGetObjectListResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    json_object *objectListObj = json_object_object_get(resObj, "objects");
    if (objectListObj != NULL && json_object_is_type(objectListObj, json_type_array))
    {
        // 获取gcode宏定义
        GcodeMacro_t updataMacro = {0};
        json_object *subscribeObjs = json_object_new_object();

        // 解析list
        for (int i = 0; i < json_object_array_length(objectListObj); i++)
        {
            json_object *objectName = json_object_array_get_idx(objectListObj, i);
            if (objectName != NULL && json_object_is_type(objectName, json_type_string))
            {
                const char *objectNameStr = json_object_get_string(objectName);
                CrLogI("objectName = %s", objectNameStr);

                // 获取 gcode宏定义
                if (strstr(objectNameStr, GCODE_MACRO_GET)) {
                    // 判断宏定义个数是否超过上限
                    if (updataMacro.size >= (sizeof(updataMacro.value)/sizeof(updataMacro.value[0]))) {
                        CrLogW("The number of gcode macro definitions exceeds the upper limit\n");
                    }
                    else {
                        const char *saveMacro = objectNameStr + strlen(GCODE_MACRO_GET);
                        memcpy(updataMacro.value[updataMacro.size++], saveMacro, strlen(saveMacro));
                    }
                }
                // 订阅消息
                if (!strstr(objectNameStr, GCODE_MENU)) {
                    json_object_object_add(subscribeObjs, objectNameStr, NULL);
                }
            }
        }
        CrLogI("gcode macro size = %d", updataMacro.size);

        // 订阅klipper消息
        json_object *responseObj = json_object_new_object();
        json_object_object_add(responseObj, "method", json_object_new_string("process_status_update"));

        json_object *params = json_object_new_object();
        json_object_object_add(params, "objects", subscribeObjs);
        json_object_object_add(params, "response_template", responseObj);
        AddKlipperCmd("objects/subscribe", params, KLIPPER_SUBSCRIBE_OBJECTS, 0);

        // 更新宏定义列表
        PrintSavePara_t updataPara = GetPrintSavePara();
        updataPara.gcodeMacro = updataMacro;
        UpdataPrintSavePara(updataPara);
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperGetObjectConfigResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    // 解析klipper配置文件
    KlipperConfigAnl(resObj);
    // 获取klipper配置文件成功
    SetSyncKlipperConfigFile(false);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperStartPrintFileResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("start print file result");
    GcodeCmdRes start = GCODE_CMD_RES__INIT;
    start.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&start, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_START_PRINT_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperPausePrintFileResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;
    
    CrLogI("pause print file result");
    GcodeCmdRes pause = GCODE_CMD_RES__INIT;
    pause.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&pause, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_PAUSE_PRINT_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperResumePrintFileResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("resume print file result");
    GcodeCmdRes resume = GCODE_CMD_RES__INIT;
    resume.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&resume, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_RESUME_PRINT_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperStopPrintFileResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("stop print file result");
    GcodeCmdRes stop = GCODE_CMD_RES__INIT;
    stop.result = 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&stop, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_STOP_PRINT_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperEndPrintPointResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("end print point result");
    GcodeCmdRes point = GCODE_CMD_RES__INIT;
    point.result = 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&point, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_END_PRINT_POINT_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperGetGsensorExistResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;
    
    CrLogI("get gsensor exist result = %s", json_object_to_json_string(resObj));

    MultiGsensor gsensorRes = MULTI_GSENSOR__INIT;
    json_object *adxl345ExistObj = GetJsonObject(resObj, "adxl345_is_exist", json_type_boolean);
    json_object *adxl345NameObj = GetJsonObject(resObj, "name", json_type_string);

    // 提取结果
    if (adxl345ExistObj && adxl345NameObj) {
        const char *nameStr = json_object_get_string(adxl345NameObj);
        if (strcmp(nameStr, "x") == 0) {
            gsensorRes.has_multi_gsensor_x = 1;
            gsensorRes.multi_gsensor_x = json_object_get_boolean(adxl345ExistObj);
        }
        else if (strcmp(nameStr, "y") == 0) {
            gsensorRes.has_multi_gsensor_y = 1;
            gsensorRes.multi_gsensor_y = json_object_get_boolean(adxl345ExistObj);
        }
        else {
            gsensorRes.has_multi_gsensor_all = 1;
            gsensorRes.multi_gsensor_all = json_object_get_boolean(adxl345ExistObj);
        }
    }
    else if (adxl345ExistObj) {
        gsensorRes.has_multi_gsensor_all = 1;
        gsensorRes.multi_gsensor_all = json_object_get_boolean(adxl345ExistObj);
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = multi_gsensor__pack(&gsensorRes, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GET_GSENSOR_EXIST_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetExclideObjectResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("set exclide object result");
    GcodeCmdRes exclide = GCODE_CMD_RES__INIT;
    exclide.result = 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&exclide, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_EXCLUDE_OBJECT_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resultObj
 */
static int KlipperGetMeshInfoResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功    
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    const char *meshInfoStr = json_object_to_json_string_ext(resObj, JSON_C_TO_STRING_PLAIN);
    CrLogI("meshInfoStr = %s", meshInfoStr);
    
    // 更新klipper保存参数
    PrintSavePara_t updataPara = GetPrintSavePara();
    bzero(updataPara.bedMeshInfo, sizeof(updataPara.bedMeshInfo));
    strcat(updataPara.bedMeshInfo, meshInfoStr);
    UpdataPrintSavePara(updataPara);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resultObj
 */
static int KlipperSetMeshInfoResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功    
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("set exclide object result");
    GcodeCmdRes bedMesh = GCODE_CMD_RES__INIT;
    bedMesh.result = 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&bedMesh, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MESH_INFO_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    // 更新klipper保存参数
    const char *meshInfoStr = json_object_to_json_string_ext(resObj, JSON_C_TO_STRING_PLAIN);
    CrLogI("meshInfoStr = %s", meshInfoStr);

    PrintSavePara_t updataPara = GetPrintSavePara();
    bzero(updataPara.bedMeshInfo, sizeof(updataPara.bedMeshInfo));
    strcat(updataPara.bedMeshInfo, meshInfoStr);
    UpdataPrintSavePara(updataPara);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperPrintFirstLayerResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("print first layer result");
    CrLogI("resObj = %s", json_object_to_json_string_ext(resObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperCheckContinuePrintResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;
    
    CrLogI("check Continue Print result");
    CrLogI("resObj = %s", json_object_to_json_string_ext(resObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    
    // 检查状态
    json_object *fileStateObj = json_object_object_get(resObj, "file_state");
    json_object *eepromStateObj = json_object_object_get(resObj, "eeprom_state");
    if (fileStateObj && json_object_is_type(fileStateObj, json_type_boolean) &&
        eepromStateObj && json_object_is_type(eepromStateObj, json_type_boolean))
    {
        if (json_object_get_boolean(fileStateObj) && json_object_get_boolean(eepromStateObj)) {
            // 提取并同步继续打印信息
            GetDeviceSavePowerLossInfo();
        }
    }
    SetSyncContinuePrint(false);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperCancelContinuePrintResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Cancel Continue Print result");
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperStopHeatingResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("stop temp heating result");
    GcodeCmdRes stop = GCODE_CMD_RES__INIT;
    stop.result = 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&stop, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_STOP_HEATING_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperDevReturnHomeResult(KlipperSend_t *send, json_object *resultObj)
{
    CrLogI("device return home result");
    GcodeCmdRes home = GCODE_CMD_RES__INIT;

    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) home.result = 0;
    else home.result = 1;
    // 更新设备状态
    UpdataDeviceState(DEVICE_STATE_IDLE);

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&home, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_RETURN_HOME_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperControlMoveResult(KlipperSend_t *send, json_object *resultObj)
{
    CrLogI("control xyz move result");
    GcodeCmdRes move = GCODE_CMD_RES__INIT;

    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) move.result = 0;
    else move.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&move, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_HOTEND_XYZ_MOVE_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperAxisRecoupResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("set Axis Recoup result");
    GcodeCmdRes offset = GCODE_CMD_RES__INIT;
    offset.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&offset, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_AXIS_RECOUP_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperHomeOffsetParaResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("set Home Offset result");
    GcodeCmdRes offset = GCODE_CMD_RES__INIT;
    offset.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&offset, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_HOME_OFFSET_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperMotorLockResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("motor lock result");
    GcodeCmdRes lock = GCODE_CMD_RES__INIT;
    lock.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&lock, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MOTOR_LOCK_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperMotorUnlockResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("motor unlock result");
    GcodeCmdRes unlock = GCODE_CMD_RES__INIT;
    unlock.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&unlock, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MOTOR_UNLOCK_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetNozzleTempResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Nozzle Temp result");
    GcodeCmdRes temp = GCODE_CMD_RES__INIT;
    temp.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&temp, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_NOZZLE_TEMP_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetBedTempResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;
    
    CrLogI("Set Bed Temp result");
    GcodeCmdRes temp = GCODE_CMD_RES__INIT;
    temp.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&temp, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_BED_TEMP_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperContolOpenFanResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Contol Open Fan result");
    GcodeCmdRes fan = GCODE_CMD_RES__INIT;
    fan.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&fan, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_OPEN_FAN_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperContolStopFanResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Contol Stop Fan result");
    GcodeCmdRes fan = GCODE_CMD_RES__INIT;
    fan.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&fan, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_STOP_FAN_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperContolLightValueResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Contol light value result");
    GcodeCmdRes value = GCODE_CMD_RES__INIT;
    value.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&value, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_LIGHT_VALUE_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperContolStopAllHeatingResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Contol Stop All Heating result");
    GcodeCmdRes stopHeat = GCODE_CMD_RES__INIT;
    stopHeat.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&stopHeat, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_STOP_ALL_HEAT_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperAbsolutePositioningResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Absolute Positioning result");
    GcodeCmdRes positioning = GCODE_CMD_RES__INIT;
    positioning.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&positioning, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_ABSOLUTE_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperRelativePositioningResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Relative Positioning result");
    GcodeCmdRes positioning = GCODE_CMD_RES__INIT;
    positioning.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&positioning, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_RELATIVE_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperDeviceAutoLevelResult(KlipperSend_t *send, json_object *resultObj)
{
    CrLogI("device auto level end");

    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) {
        UpdataAutoLevelProgress(-1);
        AutoLevelResultResponse(AUTO_LEVELING_FAIL);
    }
    else {
        UpdataAutoLevelProgress(100);
        AutoLevelResultResponse(AUTO_LEVELING_SUCCESS);
    }
    // 更新设备状态
    UpdataDeviceState(DEVICE_STATE_IDLE);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetHotendTempPidResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Hotend Temp Pid result");
    GcodeCmdRes pid = GCODE_CMD_RES__INIT;
    pid.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&pid, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_HOTEND_PID_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetBedTempPidResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Bed Temp Pid result");
    GcodeCmdRes pid = GCODE_CMD_RES__INIT;
    pid.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&pid, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_BED_PID_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperControlDeviceResetResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Control Device Reset result");
    GcodeCmdRes reset = GCODE_CMD_RES__INIT;
    reset.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&reset, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_DEVICE_RESET_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetMaxAccelerationResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Max Acceleration result");
    GcodeCmdRes max = GCODE_CMD_RES__INIT;
    max.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&max, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MAX_ACCELERATION_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetMaxSpeedResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Max Speed result");
    GcodeCmdRes max = GCODE_CMD_RES__INIT;
    max.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&max, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MAX_SPEED_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetMaxJerkResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Max Jerk result");
    GcodeCmdRes max = GCODE_CMD_RES__INIT;
    max.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&max, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MAX_JERK_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetMaxCornerResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;
    
    CrLogI("Set Max Corner result");
    GcodeCmdRes max = GCODE_CMD_RES__INIT;
    max.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&max, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MAX_CORNER_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetPressureAdvanceResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Pressure Advance result");
    GcodeCmdRes max = GCODE_CMD_RES__INIT;
    max.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&max, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_PRESSURE_ADVANCE_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetSmoothTimeResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Smooth Time result");
    GcodeCmdRes max = GCODE_CMD_RES__INIT;
    max.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&max, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_SMOOTH_TIME_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetDevResetSaveResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CONTROL_SYSTEM_REBOOT, "", 0);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send1, size1);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetMaterialDelectResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Material Delect result");
    GcodeCmdRes sw = GCODE_CMD_RES__INIT;
    sw.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&sw, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_MATERIAL_DELECT_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetPowerLossSwResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Power loss sw result");
    GcodeCmdRes sw = GCODE_CMD_RES__INIT;
    sw.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&sw, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_POWER_LOSS_SW_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetPrintSpeedResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;
    
    CrLogI("Set Print Speed result");
    GcodeCmdRes speed = GCODE_CMD_RES__INIT;
    speed.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&speed, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_PRINT_SPEED_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetPrintFlowResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Print flow result");
    GcodeCmdRes flow = GCODE_CMD_RES__INIT;
    flow.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&flow, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_PRINT_FLOW_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetCrTouchResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Cr Touch result");
    GcodeCmdRes touch = GCODE_CMD_RES__INIT;
    touch.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&touch, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_CR_TOUCH_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperRunGcodeMacroResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("run gcode macro result");
    GcodeCmdRes touch = GCODE_CMD_RES__INIT;
    touch.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&touch, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_GCODE_MACRO_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetConsoleControlResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("set console control result");
    CrLogI("resObj = %s", json_object_to_json_string_ext(resObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperStartHotendAutoPidResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("hotend auto pid end, p = %d, i = %d, d = %d\n", curAutoPidResult.p, curAutoPidResult.i, curAutoPidResult.d);
    UpdataAutoPidProgress(100);
    // 发送交互确认，是否保存
    PidInfo pidRes = PID_INFO__INIT;
    pidRes.p = curAutoPidResult.p;
    pidRes.i = curAutoPidResult.i;
    pidRes.d = curAutoPidResult.d;

    AutoPidResult sendPid = AUTO_PID_RESULT__INIT;
    sendPid.hotend = &pidRes;

    GET_MESSAGE_BUFF(buff);
    size_t len = auto_pid_result__pack(&sendPid, buff);
    CREATE_MESSAGE_PACKAGE(send1, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_AUTO_PID_RESULT_CONFIRM_REMIND, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send1, size);
    ClearCurAutoPidResult();

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperStartHotbedAutoPidResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("hotbed auto pid end, p = %d, i = %d, d = %d\n", curAutoPidResult.p, curAutoPidResult.i, curAutoPidResult.d);
    UpdataAutoPidProgress(100);
    // 发送交互确认，是否保存
    PidInfo pidRes = PID_INFO__INIT;
    pidRes.p = curAutoPidResult.p;
    pidRes.i = curAutoPidResult.i;
    pidRes.d = curAutoPidResult.d;

    AutoPidResult sendPid = AUTO_PID_RESULT__INIT;
    sendPid.hotbed = &pidRes;

    GET_MESSAGE_BUFF(buff);
    size_t len = auto_pid_result__pack(&sendPid, buff);
    CREATE_MESSAGE_PACKAGE(send1, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_AUTO_PID_RESULT_CONFIRM_REMIND, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send1, size);
    ClearCurAutoPidResult();

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetParaSaveConfigResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("Set Print save config result");
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_SAVE_CONFIG_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSetDeviceInfoResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("resObj = %s", json_object_to_json_string_ext(resObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperSubscribeObjectsResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;
    
    KlipperObjectsResultAnl(resObj);

    // 是否需要重新获取继续打印信息
    if (GetSyncContinuePrint())
    {
        CrLogI("get power loss info");
        PowerLossPrefer powerLoss = POWER_LOSS_PREFER__INIT;
        GetPowerLossPrefer(&powerLoss);

        // 查询断电续打打印
        if (powerLoss.sw && GetPrintState().klipperPrint == KLIPPER_PRINT_STANDBY) {
            json_object *params = json_object_new_object();
            AddKlipperCmd("pause_resume/check_continue_print_state", params, SET_CHECK_CONTINUE_PRINT_NUM, MSG_ORIGIN_CONTROLLER);
        }
        else {
            CrLogW("powerLoss.sw = %d, klipperPrint = %d", powerLoss.sw, GetPrintState().klipperPrint);
            SetSyncContinuePrint(false);
        }
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperRegisterRemoteMethodResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("resObj = %s", json_object_to_json_string_ext(resObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperRestartKlipperResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("restart klipper result");
    CrLogI("resObj = %s", json_object_to_json_string_ext(resObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_RESTART_KLIPPER_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperFirmwareRestartResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("firmware restart result");
    CrLogI("resObj = %s", json_object_to_json_string_ext(resObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_FIRMWARE_RESTART_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    // 重启klipper服务
    #ifdef CROSS_COMPILE
    usleep(500 * 1000);
    char sysRes[1024] = {0};
    if (!PopenSystem(GetDefaultRestartKlipperServer(), sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);
    #endif
    // 结束任务
    SetAppStateChange(APP_PRINT_STATE_STOP);
    SetAppModeChange(APP_MODE_IDLE);
    UpdataDeviceState(DEVICE_STATE_IDLE);
    // 断开klipper连接
    KlipperSocketDeinit();
    
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperResonanceTestResult(KlipperSend_t *send, json_object *resultObj)
{
    CrLogI("resonance test result");
    CrLogI("resObj = %s", json_object_to_json_string_ext(resultObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));

    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) {
        ResonanceTestResultResponse(RESONANCE_TEST_FAIL);
    }
    else {
        ResonanceTestResultResponse(RESONANCE_TEST_SUCCESS);
    }
    // 更新设备状态
    UpdataDeviceState(DEVICE_STATE_IDLE);

    return 0;
}

static int KlipperSetQuietModeResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("set quiet mode result");
    CrLogI("resObj = %s", json_object_to_json_string_ext(resObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    SetQuietModeResultResponse();
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *resObj
 */
static int KlipperGetMcuVersionResult(KlipperSend_t *send, json_object *resultObj)
{
    // 判断指令是否成功
    json_object *resObj = json_object_object_get(resultObj, "result");
    if (resObj == NULL || !json_object_is_type(resObj, json_type_object)) return -1;

    CrLogI("get mcu version result");
    CrLogI("resObj = %s", json_object_to_json_string_ext(resObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
    
    // mcu版本
    CurMcuVersion hostMcu = CUR_MCU_VERSION__INIT;
    CurMcuVersionList list = CUR_MCU_VERSION_LIST__INIT;

    // 获取下位机软硬件版本
    json_object *versionObj = json_object_object_get(resObj, "software_version");
    if (versionObj && json_object_is_type(versionObj, json_type_string))
    {
        hostMcu.has_software = 1;
        hostMcu.software.data = (uint8_t*)json_object_get_string(versionObj);
        hostMcu.software.len = json_object_get_string_len(versionObj);
        list.hostmcu = &hostMcu;
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = cur_mcu_version_list__pack(&list, buff);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GET_CUR_MCU_VERSION_ANS, buff, len);
    MANAGER_MSG_SEND(send->origin, &send1, size1);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *send
 * @param {json_object} *result
 */
int KlipperRecvGcodeAnl(KlipperSend_t *send, json_object *resObj)
{
    switch (send->cmdNum)
    {
        case KLIPPER_READY_HANDSHAKE_NUM: KlipperReadyHandshakeResult(send, resObj); break;
        case KLIPPER_GET_DEVICR_INFO: KlipperGetDeviceInfoResult(send, resObj); break;
        case KLIPPER_GET_OBJECT_LIST: KlipperGetObjectListResult(send, resObj); break;
        case KLIPPER_GET_OBJECT_CONFIG: KlipperGetObjectConfigResult(send, resObj); break;

        case SET_START_PRINT_FILE_NUM: KlipperStartPrintFileResult(send, resObj); break;
        case SET_PAUSE_PRINT_FILE_NUM: KlipperPausePrintFileResult(send, resObj); break;
        case SET_RESUME_PRINT_FILE_NUM: KlipperResumePrintFileResult(send, resObj); break;
        case SET_STOP_PRINT_FILE_NUM: KlipperStopPrintFileResult(send, resObj); break;
        case SET_PRINT_FIRST_LAYER_NUM: KlipperPrintFirstLayerResult(send, resObj); break;
        case SET_CHECK_CONTINUE_PRINT_NUM: KlipperCheckContinuePrintResult(send, resObj); break;
        case SET_CANCEL_CONTINUE_PRINT_NUM: KlipperCancelContinuePrintResult(send, resObj); break;
        case SET_STOP_TEMP_HEATING_NUM: KlipperStopHeatingResult(send, resObj); break;
        case SET_DEVICE_RETURN_HOME_NUM: KlipperDevReturnHomeResult(send, resObj); break;
        case SET_CONTROL_DEV_MOVE_NUM: KlipperControlMoveResult(send, resObj); break;
        case SET_Z_AXIS_OFFSET_PARA_NUM: KlipperAxisRecoupResult(send, resObj); break;
        case SET_HOME_OFFSET_PARA_NUM: KlipperHomeOffsetParaResult(send, resObj); break;
        case SET_DEVICE_MOTOR_LOCK_NUM: KlipperMotorLockResult(send, resObj); break;
        case SET_DEVICE_MOTOR_UNLOCK_NUM: KlipperMotorUnlockResult(send, resObj); break;
        case SET_NOZZLE_TARGET_TEMP_NUM: KlipperSetNozzleTempResult(send, resObj); break;
        case SET_BED_TARGET_TEMP_NUM: KlipperSetBedTempResult(send, resObj); break;
        case SET_CONTROL_OPEN_FAN_NUM: KlipperContolOpenFanResult(send, resObj); break;
        case SET_CONTROL_STOP_FAN_NUM: KlipperContolStopFanResult(send, resObj); break;
        case SET_CONTROL_LIGHT_VALUE_NUM: KlipperContolLightValueResult(send, resObj); break;
        case SET_STOP_ALL_HEATING_NUM: KlipperContolStopAllHeatingResult(send, resObj); break;
        case SET_ABSOLUTE_POSITIONING_NUM: KlipperAbsolutePositioningResult(send, resObj); break;
        case SET_RELATIVE_POSITIONING_NUM: KlipperRelativePositioningResult(send, resObj); break;
        case SET_DEVICE_AUTO_LEVEL_NUM: KlipperDeviceAutoLevelResult(send, resObj); break;
        case SET_HOTEND_TEMP_PID_NUM: KlipperSetHotendTempPidResult(send, resObj); break;
        case SET_BED_TEMP_PID_NUM: KlipperSetBedTempPidResult(send, resObj); break;
        case SET_DEVICE_RESET_NUM: KlipperControlDeviceResetResult(send, resObj); break;
        case SET_MAX_ACCELERATION_NUM: KlipperSetMaxAccelerationResult(send, resObj); break;
        case SET_MAX_SPEED_NUM: KlipperSetMaxSpeedResult(send, resObj); break;
        case SET_MAX_JERK_NUM: KlipperSetMaxJerkResult(send, resObj); break;
        case SET_MAX_CORNER_NUM: KlipperSetMaxCornerResult(send, resObj); break;
        case SET_PRESSURE_ADVANCE_NUM: KlipperSetPressureAdvanceResult(send, resObj); break;
        case SET_SMOOTH_TIME_NUM: KlipperSetSmoothTimeResult(send, resObj); break;
        case SET_DEV_RESET_AFTER_SAVE_NUM: KlipperSetDevResetSaveResult(send, resObj); break;
        case SET_MATERIAL_DELECT_NUM: KlipperSetMaterialDelectResult(send, resObj); break;
        case SET_POWER_LOSS_SW_NUM: KlipperSetPowerLossSwResult(send, resObj); break;
        case SET_DEVICE_PRINT_SPEED_NUM: KlipperSetPrintSpeedResult(send, resObj); break;
        case SET_DEVICE_PRINT_FLOW_NUM: KlipperSetPrintFlowResult(send, resObj); break;
        case SET_CR_TOUCH_CONTROL_NUM: KlipperSetCrTouchResult(send, resObj); break;
        case SET_RUN_GCODE_MACRO_NUM: KlipperRunGcodeMacroResult(send, resObj); break;
        case SET_CONSOLE_CONTRIL_NUM: KlipperSetConsoleControlResult(send, resObj); break;
        case SET_START_HOT_END_TEMP_AUTO_PID_NUM: KlipperStartHotendAutoPidResult(send, resObj); break;
        case SET_START_HOT_BED_TEMP_AUTO_PID_NUM: KlipperStartHotbedAutoPidResult(send, resObj); break;
        case SET_PARA_SAVE_CONFIG_NUM: KlipperSetParaSaveConfigResult(send, resObj); break;

        case KLIPPER_SET_DEVICR_INFO: KlipperSetDeviceInfoResult(send, resObj); break;
        case KLIPPER_SUBSCRIBE_OBJECTS: KlipperSubscribeObjectsResult(send, resObj); break;
        case KLIPPER_REGISTER_REMOTE_METHOD: KlipperRegisterRemoteMethodResult(send, resObj); break;
        case KLIPPER_RESTART_KLIPPER_NUM: KlipperRestartKlipperResult(send, resObj); break;
        case KLIPPER_FIRMWARE_RESTART_NUM: KlipperFirmwareRestartResult(send, resObj); break;
        case KLIPPER_RESONANCE_TEST_NUM: KlipperResonanceTestResult(send, resObj); break;
        case KLIPPER_GET_MCU_VERSION_NUM: KlipperGetMcuVersionResult(send, resObj); break;
        case KLIPPER_SET_QUIET_MODE: KlipperSetQuietModeResult(send, resObj); break;
        case KLIPPER_SDCARD_RESET_FILE_NUM: KlipperStopPrintFileResult(send, resObj); break;
        case KLIPPER_END_PRINT_POINT_NUM: KlipperEndPrintPointResult(send, resObj); break;
        case KLIPPER_GET_GSENSOR_EXIST_NUM: KlipperGetGsensorExistResult(send, resObj); break;
        case KLIPPER_SET_EXCLUDE_OBJECT_NUM: KlipperSetExclideObjectResult(send, resObj); break;
        case KLIPPER_GET_MESH_INFO_NUM: KlipperGetMeshInfoResult(send, resObj); break;
        case KLIPPER_SET_MESH_INFO_NUM: KlipperSetMeshInfoResult(send, resObj); break;
        
        default: CrLogW("Command is not defined; cmd = [%d]!\n", send->cmdNum); break;
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *resObj
 */
int KlipperRecvSubscribeAnl(json_object *resObj)
{
    json_object *methodObj = json_object_object_get(resObj, "method");
    if (methodObj != NULL && json_object_is_type(methodObj, json_type_string))
    {
        // 按照不同的“method”解析通知
        if (strstr(json_object_get_string(methodObj), "process_gcode_response"))
        {
            json_object *paramsObj = json_object_object_get(resObj, "params");
            if (paramsObj != NULL && json_object_is_type(paramsObj, json_type_object))
            {
                KlipperGcodeOutputResultAnl(paramsObj);
            }
        }
        else if (strstr(json_object_get_string(methodObj), "process_status_update"))
        {
            json_object *paramsObj = json_object_object_get(resObj, "params");
            if (paramsObj != NULL && json_object_is_type(paramsObj, json_type_object))
            {
                KlipperObjectsResultAnl(paramsObj);
            }
        }
    }

    return 0;
}


/*********************************************************
 *********************************************************
 ******************** 获取打印模型参数 **********************
 *********************************************************
 *********************************************************/
/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} printer
 */
uint32_t GetPrintLayers(KlipperPrint_t printer)
{
    CurrentFile_t current_file = printer.current_file;

    if (current_file.layer_height > 0 &&
        current_file.object_height > current_file.first_layer_height)
    {
        uint32_t layers = (current_file.object_height - current_file.first_layer_height) / current_file.layer_height + 0.5 + 1;
        CrLogI("get print layers = %d", layers);
        if (layers > 0) return layers;
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} printer
 */
uint32_t GetPrintCurLayer(KlipperPrint_t printer)
{
    CurrentFile_t current_file = printer.current_file;
    double z = printer.gcode_move.gcode_position[2];

    if (current_file.layer_height > 0 &&
        z > current_file.first_layer_height)
    {
        uint32_t layer = (z - current_file.first_layer_height) / current_file.layer_height + 0.5 + 1;
        uint32_t curLayer = GetPrintState().printLayer;

        if (layer == 1) return layer;
        if (layer > 1 && layer > curLayer && layer < (curLayer + 3)) {
            return (layer <= GetPrintState().printLayers ? layer : GetPrintState().printLayers);
        }
        return curLayer;
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} printer
 */
double GetPrintProgress(KlipperPrint_t printer)
{
#if 0
    double filament_total = printer.current_file.filament_total;
    double filament_used_real = printer.print_stats.filament_used_real;

    // 有打印完成记录，使用记录中消耗长度
    if (printer.current_file.history.status) {
        filament_total = printer.current_file.history.filament_used_real;
    }

    // 有耗材长度时通过耗材长度计算进度(打印100%时停止更新)
    if (filament_total) {
        if (!filament_used_real) {
            return 0;
        }
        else {
            double progress = filament_used_real / filament_total;
            if(progress >= 1) {
                return 0.9999;
            } else {
                return progress;
            }
        }
    }
#endif

    long gcode_start_byte = printer.current_file.gcode_start_byte;
    long gcode_end_byte = printer.current_file.gcode_end_byte;
    long file_position = printer.virtual_sdcard.file_position;

    // 使用文件偏移值计算进度
    if (gcode_start_byte > 0 && gcode_end_byte > 0 && file_position > 0)
    {
        if (file_position <= gcode_start_byte) return 0;
        if (file_position >= gcode_end_byte) return 0.9999;

        long currentPosition = file_position - gcode_start_byte;
        long endPosition = gcode_end_byte - gcode_start_byte;

        return (currentPosition * 1.0000 / endPosition);
    }
    
    return printer.display_status.progress;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} printer
 */
uint32_t GetPrintTimeEstimates(KlipperPrint_t printer)
{
    double progress = GetPrintProgress(printer);
    double duration = printer.print_stats.print_duration;
    double multiplier = printer.gcode_move.speed_factor || 1;
    int32_t estimatedTime = printer.current_file.estimated_time;

    double file = 0;
    uint32_t fileEndTime = 0;
    if (progress > 0 && duration > 0) {
        file = duration / progress;
        fileEndTime = (file - duration) / multiplier + 0.5;
    }

    double actualTotal = 0;
    uint32_t actualEndTime = 0;
    if (printer.current_file.history.status)
    {
        actualTotal = printer.current_file.history.print_duration;
        if (actualTotal >= duration) {
            actualEndTime = actualTotal - duration;
        }
    }

    uint32_t slicerEndTime = 0;
    if (estimatedTime > 0) {
        if (estimatedTime >= duration) {
            slicerEndTime = (estimatedTime - duration) / multiplier + 0.5;
        }
    }

    uint32_t eta = fileEndTime;
    if (slicerEndTime > 0) eta = slicerEndTime;
    if (actualEndTime > 0) eta = actualEndTime;

    return eta;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} printer
 */
double GetRealTimeSpeed(KlipperPrint_t printer)
{
    double multiplier = printer.gcode_move.speed_factor || 1;
    double speed = printer.gcode_move.speed;
    return (speed * multiplier) / 60;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} printer
 */
double GetRealTimeFlow(KlipperPrint_t printer)
{
    static struct timeval timestamp;
    static double lastExtruderPosition = 0;
    static double value = 0;
    static double max = 0;
    static bool getFlowInit = false;
    struct timeval startTime;

    // 初始化时间变量
    if (!getFlowInit) {
        getFlowInit = true;
        gettimeofday(&startTime, NULL);
        timestamp.tv_sec = startTime.tv_sec;
    }

    // 获取计算状态值
    double extruderPosition = printer.print_stats.filament_used;
    double filament_diameter = GetExtruder()->filamentDiameter;
    gettimeofday(&startTime, NULL);
    double timeDelta = startTime.tv_sec - timestamp.tv_sec;

    if (timeDelta >= 2) {
        if (lastExtruderPosition < extruderPosition) {
            double filamentDiff = extruderPosition - lastExtruderPosition;
            double filamentCrossSection = pow(filament_diameter / 2, 2) * 3.141592653589793;

            value = filamentCrossSection * filamentDiff / timeDelta;
            if (max < value) max = value;
        }

        lastExtruderPosition = extruderPosition;
        gettimeofday(&startTime, NULL);
        timestamp.tv_sec = startTime.tv_sec;
    }

    return value;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} *printer
 */
int GetHistoryRecordFromFileName(KlipperPrint_t *printer)
{
    // 打印文件MD5码
    char fileMd5[256] = {0};
    getFileMD5(printer->current_file.fileName, fileMd5);
    CrLogI("get history record; file name = %s", printer->current_file.fileName);
    CrLogI("get history record; file md5 = %s", fileMd5);

    HistoryRecordList list = HISTORY_RECORD_LIST__INIT;
    GetHistoryRecord(&list);
    
    // 对比文件名称
    for (int i = 0; i < list.n_list; i++)
    {
        char historyFileMd5[256] = {0};
        memcpy(historyFileMd5, list.list[i]->filemd5.data, list.list[i]->filemd5.len);
        if (strcmp(historyFileMd5, fileMd5) == 0 && list.list[i]->printfinish)
        {
            printer->current_file.history.status = list.list[i]->printfinish;
            printer->current_file.history.print_duration = list.list[i]->usagetime;
            printer->current_file.history.filament_used_real = list.list[i]->usagematerial;
            
            CrLogI("status = %d, print_duration = %d, filament_used_real = %f\n",
                    printer->current_file.history.status,
                    printer->current_file.history.print_duration,
                    printer->current_file.history.filament_used_real);
            break;
        }
    }
    GetHistoryRecordFree(&list);

    return 0;
}
