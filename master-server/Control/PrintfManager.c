/*
 * @Description : 打印指令管理器
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-02 14:09:36
 * @LastEditTime: 2023-11-02 16:23:08
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
#include <math.h>

#include "Base/MasterMsgBase.h"
#include "AppPrint.h"
#include "AppFuncModule.h"
#include "PrintfManager.h"
#include "PrintControl.h"
#include "DefineGcode.h"
#include "GcodeCmdResAnl.h"
#include "GcodEmetadata.h"


/**
 * @description: 静态变量声明
 * @param  {*}
 * @return {*}
 */
static int startLaserCalibrationOrigin = 0;
static int devStateBeforeInAndOutMaterial = DEVICE_STATE_IDLE;

/**
 * @description: 静态函数声明
 */


/**
 * @description: 
 * @return {*}
 * @param {MultiFan_t} fan
 * @param {int} percentage
 */
static int PercentageToDutyCycle(MultiFan_t fanType, int percentage)
{
    if (percentage == 0) return 0;
    if (percentage == 100) return 255;

    // int fanMin = 0;
    // switch (fanType) {
    //     case MULTI_FAN_MODEL: fanMin = GetPrinter()->gcode_macro_Printer_Param.fan0_min; break;
    //     case MULTI_FAN_CASE: fanMin = GetPrinter()->gcode_macro_Printer_Param.fan1_min; break;
    //     case MULTI_FAN_AUXILIARY: fanMin = GetPrinter()->gcode_macro_Printer_Param.fan2_min; break;
    //     default: fanMin = 0; break;
    // }

    // return ((percentage / 100.00) * (255 - fanMin) + fanMin +0.5); 
    
    return ((percentage / 100.00) * 255);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserStopHeatingReq(MsgHeadBuf_t *head)
{
    GcodeCmd *stop = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!stop) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("stop temp heating");
    String_t tCmd = {0};

    tCmd.data = SET_BREAK_AND_CONTINUE;
    tCmd.len = strlen(SET_BREAK_AND_CONTINUE);
    AddGcodeListCmd(SET_STOP_TEMP_HEATING_NUM, 0, &tCmd, head->origin);
    gcode_cmd__free_unpacked(stop, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserReturnHomeReq(MsgHeadBuf_t *head)
{
    GcodeCmd *returnHome = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!returnHome) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("return hone");
    if (returnHome->has_cmdstr)
    {
        UpdataDeviceState(DEVICE_STATE_HOMING);
        char tempPara[200] = {0};
        memcpy(tempPara, returnHome->cmdstr.data, returnHome->cmdstr.len);
        char moveCmd[256] = {0};
        snprintf(moveCmd, 256, "%s %s", SET_DEVICE_RETURN_HOME, tempPara);
        
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(moveCmd));
        AddKlipperCmd("gcode/script", params, SET_DEVICE_RETURN_HOME_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(returnHome, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserHotendXyzMoveReq(MsgHeadBuf_t *head)
{
    GcodeCmd *move = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!move) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("control xyz move");
    if (move->has_cmdstr)
    {
        char tempPara[256] = {0};
        memcpy(tempPara, move->cmdstr.data, move->cmdstr.len);
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(tempPara));
        AddKlipperCmd("gcode/script", params, SET_CONTROL_DEV_MOVE_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(move, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetAxisRecoupReq(MsgHeadBuf_t *head)
{
    GcodeCmd *offset = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!offset) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("set Axis Recoup");
    if (offset->has_cmdstr)
    {
        char tempPara[200] = {0};
        memcpy(tempPara, offset->cmdstr.data, offset->cmdstr.len);

        int moveFlag = GetPrintState().homedAxes.z;
        char tempCmd[512] = {0};
        // 判断是否移动到零点
        if (moveFlag && GetCurrentAppMode() == APP_MODE_IDLE) {
            snprintf(tempCmd, 512, "G0 Z0\n SET_GCODE_OFFSET Z_ADJUST=%s MOVE=%d\n Z_OFFSET_APPLY_PROBE", tempPara, moveFlag);
        }
        else {
            snprintf(tempCmd, 512, "SET_GCODE_OFFSET Z_ADJUST=%s MOVE=%d\n Z_OFFSET_APPLY_PROBE", tempPara, moveFlag);
        }

        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(tempCmd));
        AddKlipperCmd("gcode/script", params, SET_Z_AXIS_OFFSET_PARA_NUM, head->origin);
    }

    gcode_cmd__free_unpacked(offset, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetHomeOffsetReq(MsgHeadBuf_t *head)
{
    GcodeCmd *offset = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!offset) {
        CrLogW("unpack failed\n");
        return;
    }
    
    char sendBuff[100] = {0};
    CrLogI("set home offset");
    String_t tCmd = {0};

    if (offset->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, offset->cmdstr.data, offset->cmdstr.len);
        snprintf(sendBuff, 100, "%s %s", SET_HOME_OFFSET_PARA, tempPara);
        tCmd.data = sendBuff;
        tCmd.len = strlen(sendBuff);
    }
    else
    {
        tCmd.data = SET_HOME_OFFSET_PARA;
        tCmd.len = strlen(SET_HOME_OFFSET_PARA);
    }
    AddGcodeListCmd(SET_HOME_OFFSET_PARA_NUM, 0, &tCmd, head->origin);

    gcode_cmd__free_unpacked(offset, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetSaveConfigReq(MsgHeadBuf_t *head)
{
    CrLogI("Set Save config");

    char *scriptBuff = "CXSAVE_CONFIG";
    json_object *params = json_object_new_object();
    json_object_object_add(params, "script", json_object_new_string(scriptBuff));
    AddKlipperCmd("gcode/script", params, SET_PARA_SAVE_CONFIG_NUM, head->origin);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetMotorLockReq(MsgHeadBuf_t *head)
{
    GcodeCmd *lock = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!lock) {
        CrLogW("unpack failed\n");
        return;
    }
    
    char sendBuff[100] = {0};
    CrLogI("Set Motor Lock");
    String_t tCmd = {0};

    if (lock->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, lock->cmdstr.data, lock->cmdstr.len);
        snprintf(sendBuff, 100, "%s %s", SET_DEVICE_MOTOR_LOCK, tempPara);
        tCmd.data = sendBuff;
        tCmd.len = strlen(sendBuff);
    }
    else
    {
        tCmd.data = SET_DEVICE_MOTOR_LOCK;
        tCmd.len = strlen(SET_DEVICE_MOTOR_LOCK);
    }
    AddGcodeListCmd(SET_DEVICE_MOTOR_LOCK_NUM, 0, &tCmd, head->origin);

    gcode_cmd__free_unpacked(lock, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetMotorUnlockReq(MsgHeadBuf_t *head)
{
    MutableTypeData *unlock = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!unlock) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set Motor Unlock");
    char tempPara[256] = {0};
    strcat(tempPara, "M84");

    json_object *params = json_object_new_object();
    json_object_object_add(params, "script", json_object_new_string(tempPara));
    AddKlipperCmd("gcode/script", params, SET_DEVICE_MOTOR_UNLOCK_NUM, head->origin);

    mutable_type_data__free_unpacked(unlock, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetNozzleTempReq(MsgHeadBuf_t *head)
{
    Extruder *temp = extruder__unpack(NULL, head->bufLen, head->buf);
    if (!temp) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set Nozzle Temp");
    bool change = false;
    char tempPara[256] = {0};
    
    if (temp->has_extruder) {
        // snprintf(tempPara, 256, "SET_HEATER_TEMPERATURE HEATER=extruder TARGET=%d", temp->extruder);
        snprintf(tempPara, 256, "%s S%d", SET_NOZZLE_TARGET_TEMP, temp->extruder);
        change = true;
    }
    else CrLogW("Error control instruction\n");

    if (change) {
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(tempPara));
        AddKlipperCmd("gcode/script", params, SET_NOZZLE_TARGET_TEMP_NUM, head->origin);
    }

    extruder__free_unpacked(temp, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetBedTempReq(MsgHeadBuf_t *head)
{
    HeaterBed *temp = heater_bed__unpack(NULL, head->bufLen, head->buf);
    if (!temp) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set bed Temp");
    bool change = false;
    char tempPara[256] = {0};

    // 发送指令
    if (temp->has_heater_bed) {
        // snprintf(tempPara, 256, "SET_HEATER_TEMPERATURE HEATER=heater_bed TARGET=%d", temp->heater_bed);
        snprintf(tempPara, 256, "%s S%d", SET_BED_TARGET_TEMP, temp->heater_bed);
        change = true;
    }
    else if (temp->has_heater_bed_0) {
        snprintf(tempPara, 256, "SET_HEATER_TEMPERATURE HEATER=heater_bed_0 TARGET=%d", temp->heater_bed_0);
        change = true;
    }
    else if (temp->has_heater_bed_1) {
        snprintf(tempPara, 256, "SET_HEATER_TEMPERATURE HEATER=heater_bed_1 TARGET=%d", temp->heater_bed_1);
        change = true;
    }
    else if (temp->has_heater_bed_2) {
        snprintf(tempPara, 256, "SET_HEATER_TEMPERATURE HEATER=heater_bed_2 TARGET=%d", temp->heater_bed_2);
        change = true;
    }
    else CrLogW("Error control instruction\n");

    if (change) {
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(tempPara));
        AddKlipperCmd("gcode/script", params, SET_BED_TARGET_TEMP_NUM, head->origin);
    }

    heater_bed__free_unpacked(temp, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetOpenFanReq(MsgHeadBuf_t *head)
{
    MultiFan *multiFan = multi_fan__unpack(NULL, head->bufLen, head->buf);
    if (!multiFan) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set open fan");
    char fanCmd[256] = {0};
    if (multiFan->has_multi_fan_model)
        snprintf(fanCmd, 256, "%s P0 S%d", SET_CONTROL_OPEN_FAN, PercentageToDutyCycle(MULTI_FAN_MODEL, multiFan->multi_fan_model));
    else if (multiFan->has_multi_fan_case)
        snprintf(fanCmd, 256, "%s P1 S%d", SET_CONTROL_OPEN_FAN, PercentageToDutyCycle(MULTI_FAN_CASE, multiFan->multi_fan_case));
    else if (multiFan->has_multi_fan_auxiliary)
        snprintf(fanCmd, 256, "%s P2 S%d", SET_CONTROL_OPEN_FAN, PercentageToDutyCycle(MULTI_FAN_AUXILIARY, multiFan->multi_fan_auxiliary));
    else CrLogW("Error control instruction\n");

    json_object *params = json_object_new_object();
    json_object_object_add(params, "script", json_object_new_string(fanCmd));
    AddKlipperCmd("gcode/script", params, SET_CONTROL_OPEN_FAN_NUM, head->origin);

    multi_fan__free_unpacked(multiFan, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetStopFanReq(MsgHeadBuf_t *head)
{
    GcodeCmd *fan = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!fan) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Set stop fan");
    String_t tCmd = {0};
    tCmd.data = SET_CONTROL_STOP_FAN;
    tCmd.len = strlen(SET_CONTROL_STOP_FAN);
    AddGcodeListCmd(SET_CONTROL_STOP_FAN_NUM, 0, &tCmd, head->origin);

    gcode_cmd__free_unpacked(fan, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetLightValueReq(MsgHeadBuf_t *head)
{
    MutableTypeData *value = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!value) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set light value");
    if (value->has_int_v) {
        char tempPara[256] = {0};
        snprintf(tempPara, 256, "SET_PIN PIN=LED VALUE=%.2f", value->int_v / 100.00);

        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(tempPara));
        AddKlipperCmd("gcode/script", params, SET_CONTROL_LIGHT_VALUE_NUM, head->origin);
    }

    mutable_type_data__free_unpacked(value, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetStopAllHeatReq(MsgHeadBuf_t *head)
{
    json_object *params = json_object_new_object();
    json_object_object_add(params, "script", json_object_new_string("TURN_OFF_HEATERS"));
    AddKlipperCmd("gcode/script", params, SET_STOP_ALL_HEATING_NUM, head->origin);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserAbsolutePositioningReq(MsgHeadBuf_t *head)
{
    GcodeCmd *position = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!position) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Absolute Positioning");
    String_t tCmd = {0};
    tCmd.data = SET_ABSOLUTE_POSITIONING;
    tCmd.len = strlen(SET_ABSOLUTE_POSITIONING);
    AddGcodeListCmd(SET_ABSOLUTE_POSITIONING_NUM, 0, &tCmd, head->origin);

    gcode_cmd__free_unpacked(position, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserRelativePositioningReq(MsgHeadBuf_t *head)
{
    GcodeCmd *position = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!position) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Relative Positioning");
    String_t tCmd = {0};
    tCmd.data = SET_RELATIVE_POSITIONING;
    tCmd.len = strlen(SET_RELATIVE_POSITIONING);
    AddGcodeListCmd(SET_RELATIVE_POSITIONING_NUM, 0, &tCmd, head->origin);

    gcode_cmd__free_unpacked(position, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserDeviceAutoLevelReq(MsgHeadBuf_t *head)
{
    MutableTypeData *level = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!level) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Device Auto Level");
    UpdataAutoLevelProgress(0);
    ClearcurAutoLevelPointNum();

    // 设置自动调平
    if (level->has_int_v)
    {
        // 更新设备状态
        UpdataDeviceState(DEVICE_STATE_AUTO_LEVEL);

        // 启动调平
        char moveCmd[256] = {0};
        switch (GetPrintSavePara().levelPoints.x) {
            case 3: snprintf(moveCmd, 256, "G29 PROBE_COUNT=3,3"); break;
            case 4: snprintf(moveCmd, 256, "G29 PROBE_COUNT=4,4"); break;
            case 5: snprintf(moveCmd, 256, "G29 PROBE_COUNT=5,5"); break;
            default: snprintf(moveCmd, 256, "G29"); break;
        }

        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(moveCmd));
        AddKlipperCmd("gcode/script", params, SET_DEVICE_AUTO_LEVEL_NUM, head->origin);

        // 自动调平状态应答
        AutoLevelResultResponse(AUTO_LEVELING);
    }

    mutable_type_data__free_unpacked(level, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetAutoLevelPonitsReq(MsgHeadBuf_t *head)
{
    GcodeCmd *points = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!points) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Set Auto Level Ponits");
    if (points->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, points->cmdstr.data, points->cmdstr.len);

        // 更新打印机保存数据
        PrintSavePara_t updataPara = GetPrintSavePara();
        switch (tempPara[0])
        {
            case '3': {
                updataPara.levelPoints.x = 3;
                updataPara.levelPoints.y = 3;
                break;
            }
            case '4': {
                updataPara.levelPoints.x = 4;
                updataPara.levelPoints.y = 4;
                break;
            }
            case '5': {
                updataPara.levelPoints.x = 5;
                updataPara.levelPoints.y = 5;
                break;
            }
        }
        CrLogI("auto level ponits; x = %d, y = %d", updataPara.levelPoints.x, updataPara.levelPoints.y);
        UpdataPrintSavePara(updataPara);

        // char sendBuff[100] = {0};
        // snprintf(sendBuff, 100, "%s %s", CXSW_SET_LEVEL_POINTS, tempPara);

        // String_t tCmd = {0};
        // tCmd.data = sendBuff;
        // tCmd.len = strlen(sendBuff);
        // AddGcodeListCmd(CXSW_SET_LEVEL_POINTS_NUM, 0, &tCmd, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(points, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetHotendPidReq(MsgHeadBuf_t *head)
{
    GcodeCmd *pid = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!pid) {
        CrLogW("unpack failed\n");
        return;
    }
    
    char sendBuff[100] = {0};
    CrLogI("Set Hotend Pid");
    String_t tCmd = {0};

    if (pid->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, pid->cmdstr.data, pid->cmdstr.len);
        snprintf(sendBuff, 100, "%s %s", SET_HOTEND_TEMP_PID, tempPara);
        tCmd.data = sendBuff;
        tCmd.len = strlen(sendBuff);
    }
    else
    {
        tCmd.data = SET_HOTEND_TEMP_PID;
        tCmd.len = strlen(SET_HOTEND_TEMP_PID);
    }
    AddGcodeListCmd(SET_HOTEND_TEMP_PID_NUM, 0, &tCmd, head->origin);

    gcode_cmd__free_unpacked(pid, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetBedPidReq(MsgHeadBuf_t *head)
{
    GcodeCmd *pid = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!pid) {
        CrLogW("unpack failed\n");
        return;
    }
    
    char sendBuff[100] = {0};
    CrLogI("Set Bed Pid");
    String_t tCmd = {0};

    if (pid->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, pid->cmdstr.data, pid->cmdstr.len);
        snprintf(sendBuff, 100, "%s %s", SET_BED_TEMP_PID, tempPara);
        tCmd.data = sendBuff;
        tCmd.len = strlen(sendBuff);
    }
    else
    {
        tCmd.data = SET_BED_TEMP_PID;
        tCmd.len = strlen(SET_BED_TEMP_PID);
    }
    AddGcodeListCmd(SET_BED_TEMP_PID_NUM, 0, &tCmd, head->origin);

    gcode_cmd__free_unpacked(pid, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlDeviceResetReq(MsgHeadBuf_t *head)
{
    GcodeCmd *reset = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!reset) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Control Device Reset");
    String_t tCmd = {0};
    tCmd.data = CONTROL_DEVICE_RESET;
    tCmd.len = strlen(CONTROL_DEVICE_RESET);
    AddGcodeListCmd(SET_DEVICE_RESET_NUM, 0, &tCmd, head->origin);

    gcode_cmd__free_unpacked(reset, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetStepValueReq(MsgHeadBuf_t *head)
{
    GcodeCmd *max = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!max) {
        CrLogW("unpack failed\n");
        return;
    }
    
    char sendBuff[100] = {0};
    CrLogI("Set step value");
    String_t tCmd = {0};

    if (max->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, max->cmdstr.data, max->cmdstr.len);
        snprintf(sendBuff, 100, "%s %s", SET_STEP_VALUE, tempPara);
        tCmd.data = sendBuff;
        tCmd.len = strlen(sendBuff);
        AddGcodeListCmd(SET_STEP_VALUE_NUM, 0, &tCmd, head->origin);
    }
    else
    {
        CrLogW("Error control instruction\n");
    }

    gcode_cmd__free_unpacked(max, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetMaxAccelerationReq(MsgHeadBuf_t *head)
{
    GcodeCmd *max = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!max) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set Max Acceleration");
    if (max->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, max->cmdstr.data, max->cmdstr.len);
        char maxCmd[256] = {0};
        snprintf(maxCmd, 256, "SET_VELOCITY_LIMIT ACCEL=%s", tempPara);

        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(maxCmd));
        AddKlipperCmd("gcode/script", params, SET_MAX_ACCELERATION_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(max, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetMaxSpeedReq(MsgHeadBuf_t *head)
{
    GcodeCmd *max = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!max) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set Max Speed");
    if (max->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, max->cmdstr.data, max->cmdstr.len);
        char maxCmd[256] = {0};
        snprintf(maxCmd, 256, "SET_VELOCITY_LIMIT VELOCITY=%s", tempPara);
        
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(maxCmd));
        AddKlipperCmd("gcode/script", params, SET_MAX_SPEED_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(max, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetMaxJerkReq(MsgHeadBuf_t *head)
{
    GcodeCmd *max = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!max) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set Max Jerk");
    if (max->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, max->cmdstr.data, max->cmdstr.len);
        char maxCmd[256] = {0};
        snprintf(maxCmd, 256, "SET_VELOCITY_LIMIT ACCEL_TO_DECEL=%s", tempPara);
        
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(maxCmd));
        AddKlipperCmd("gcode/script", params, SET_MAX_JERK_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(max, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetMaxCornerReq(MsgHeadBuf_t *head)
{
    GcodeCmd *max = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!max) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set Max Corner");
    if (max->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, max->cmdstr.data, max->cmdstr.len);
        char maxCmd[256] = {0};
        snprintf(maxCmd, 256, "SET_VELOCITY_LIMIT SQUARE_CORNER_VELOCITY=%s", tempPara);
        
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(maxCmd));
        AddKlipperCmd("gcode/script", params, SET_MAX_CORNER_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(max, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetPressureAdvanceReq(MsgHeadBuf_t *head)
{
    GcodeCmd *max = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!max) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set Pressure Advance");
    if (max->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, max->cmdstr.data, max->cmdstr.len);
        char maxCmd[256] = {0};
        snprintf(maxCmd, 256, "SET_PRESSURE_ADVANCE ADVANCE=%s", tempPara);

        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(maxCmd));
        AddKlipperCmd("gcode/script", params, SET_PRESSURE_ADVANCE_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(max, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetSmoothTimeReq(MsgHeadBuf_t *head)
{
    GcodeCmd *max = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!max) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set Smooth Time");
    if (max->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, max->cmdstr.data, max->cmdstr.len);
        char maxCmd[256] = {0};
        snprintf(maxCmd, 256, "SET_PRESSURE_ADVANCE SMOOTH_TIME=%s", tempPara);

        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(maxCmd));
        AddKlipperCmd("gcode/script", params, SET_SMOOTH_TIME_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(max, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetPrintSpeedReq(MsgHeadBuf_t *head)
{
    GcodeCmd *speed = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!speed) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set Print Speed");
    if (speed->has_cmdstr)
    {
        char tempPara[200] = {0};
        memcpy(tempPara, speed->cmdstr.data, speed->cmdstr.len);
        char speedCmd[256] = {0};
        snprintf(speedCmd, 256, "%s %s", SET_DEVICE_PRINT_SPEED, tempPara);
        
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(speedCmd));
        AddKlipperCmd("gcode/script", params, SET_DEVICE_PRINT_SPEED_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(speed, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetPrintFlowReq(MsgHeadBuf_t *head)
{
    GcodeCmd *flow = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!flow) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("Set Print flow");
    if (flow->has_cmdstr)
    {
        char tempPara[200] = {0};
        memcpy(tempPara, flow->cmdstr.data, flow->cmdstr.len);
        char flowCmd[256] = {0};
        snprintf(flowCmd, 256, "%s %s", SET_DEVICE_PRINT_FLOW, tempPara);
        
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(flowCmd));
        AddKlipperCmd("gcode/script", params, SET_DEVICE_PRINT_FLOW_NUM, head->origin);
    }
    else {
        CrLogW("Error control instruction\n");
    }

    gcode_cmd__free_unpacked(flow, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetMaterialDelectReq(MsgHeadBuf_t *head)
{
    GcodeCmd *sw = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!sw) {
        CrLogW("unpack failed\n");
        return;
    }
    
    char sendBuff[100] = {0};
    CrLogI("Set Material Delect");
    String_t tCmd = {0};
    if (sw->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, sw->cmdstr.data, sw->cmdstr.len);
        snprintf(sendBuff, 100, "%s %s", SET_MATERIAL_DELECT, tempPara);
        tCmd.data = sendBuff;
        tCmd.len = strlen(sendBuff);
        AddGcodeListCmd(SET_MATERIAL_DELECT_NUM, 0, &tCmd, head->origin);
    }
    else
    {
        CrLogW("Error control instruction\n");
    }

    gcode_cmd__free_unpacked(sw, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetPowerLossSwReq(MsgHeadBuf_t *head)
{
    GcodeCmd *sw = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!sw) {
        CrLogW("unpack failed\n");
        return;
    }
    
    char sendBuff[100] = {0};
    CrLogI("Set Power Loss Sw");
    String_t tCmd = {0};
    if (sw->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, sw->cmdstr.data, sw->cmdstr.len);
        snprintf(sendBuff, 100, "%s %s", SET_POWER_OFF_CONTINUE, tempPara);
        tCmd.data = sendBuff;
        tCmd.len = strlen(sendBuff);
        AddGcodeListCmd(SET_POWER_LOSS_SW_NUM, 0, &tCmd, head->origin);
    }
    else
    {
        CrLogW("Error control instruction\n");
    }

    gcode_cmd__free_unpacked(sw, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetCrTouchReq(MsgHeadBuf_t *head)
{
    GcodeCmd *touch = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!touch) {
        CrLogW("unpack failed\n");
        return;
    }
    
    char sendBuff[100] = {0};
    CrLogI("Set Cr Touch control");
    String_t tCmd = {0};
    if (touch->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, touch->cmdstr.data, touch->cmdstr.len);
        snprintf(sendBuff, 100, "%s %s", SET_CR_TOUCH_CONTROL, tempPara);
        tCmd.data = sendBuff;
        tCmd.len = strlen(sendBuff);
        AddGcodeListCmd(SET_CR_TOUCH_CONTROL_NUM, 0, &tCmd, head->origin);
    }
    else
    {
        CrLogW("Error control instruction\n");
    }

    gcode_cmd__free_unpacked(touch, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetInsertFilamentReq(MsgHeadBuf_t *head)
{
    CrLogI("Set Insert Filament");
    // 清空当前发送指令
    CleanCurrentSendCmd();
    // 中断当前忙状态
    String_t tCmd = {0};
    tCmd.data = SET_BREAK_AND_CONTINUE;
    tCmd.len = strlen(SET_BREAK_AND_CONTINUE);
    AddGcodeListHeadCmd(SET_INSERT_FILAMENT_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    // 设置成功应答
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = 1;
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_INSERT_FILAMENT_ANS, buff, len);
    MANAGER_MSG_SEND(head->origin, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetGcodeMacroReq(MsgHeadBuf_t *head)
{
    GcodeCmd *macro = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!macro) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("set print gcode macro");
    if (macro->has_cmdstr)
    {
        char tempPara[256] = {0};
        memcpy(tempPara, macro->cmdstr.data, macro->cmdstr.len);
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(tempPara));
        AddKlipperCmd("gcode/script", params, SET_RUN_GCODE_MACRO_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(macro, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetConsoleCtlReq(MsgHeadBuf_t *head)
{
    GcodeCmd *console = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!console) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("set print console control");
    if (console->has_cmdstr)
    {
        char tempPara[256] = {0};
        memcpy(tempPara, console->cmdstr.data, console->cmdstr.len);
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(tempPara));
        AddKlipperCmd("gcode/script", params, SET_CONSOLE_CONTRIL_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(console, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetRestartKlipperReq(MsgHeadBuf_t *head)
{
    CrLogI("set print restart klipper");
    json_object *params = json_object_new_object();
    AddKlipperCmd("gcode/restart", params, KLIPPER_RESTART_KLIPPER_NUM, head->origin);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetFirmwareRestartReq(MsgHeadBuf_t *head)
{
    CrLogI("set print firmware restart");
    json_object *params = json_object_new_object();
    AddKlipperCmd("gcode/firmware_restart", params, KLIPPER_FIRMWARE_RESTART_NUM, head->origin);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetResonanceTestReq(MsgHeadBuf_t *head)
{
    GcodeCmd *resonance = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!resonance) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("set resonance test");
    if (resonance->has_cmdstr)
    {
        // 更新设备状态
        UpdataDeviceState(DEVICE_STATE_RESONANCE_TEST);

        // 启动测试
        char tempPara[200] = {0};
        memcpy(tempPara, resonance->cmdstr.data, resonance->cmdstr.len);
        char testCmd[256] = {0};
        snprintf(testCmd, 256, "INPUTSHAPER %s", tempPara);
        
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(testCmd));
        AddKlipperCmd("gcode/script", params, KLIPPER_RESONANCE_TEST_NUM, head->origin);

        // 振动补偿状态应答
        ResonanceTestResultResponse(RESONANCE_TESTING);
    }
    else CrLogW("Error control instruction\n");

    gcode_cmd__free_unpacked(resonance, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetQuietModeReq(MsgHeadBuf_t *head)
{
    MutableTypeData *quietmode = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!quietmode) {
        CrLogW("quietmode failed\n");
        return;
    }

    CrLogI("set quietmode");
    if (quietmode->has_int_v){
        char cmd[16] = {0};
        if(quietmode->int_v == 0){
            snprintf(cmd, 16, "Qmode_exit");
        }else if(quietmode->int_v == 1){
            snprintf(cmd, 16, "Qmode");
        }
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(cmd));
        AddKlipperCmd("gcode/script", params, KLIPPER_SET_QUIET_MODE, head->origin);
    }
    else CrLogW("Error control instruction\n");

    mutable_type_data__free_unpacked(quietmode, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {int} res
 */
static void UserSetLoadMaterialResult(int res)
{
    CrLogI("user set load material result = %d", res);
    UpdataLoadMaterial(res);
    // 进料结束
    if (res == 100) UpdataDeviceState(devStateBeforeInAndOutMaterial);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetLoadMaterialReq(MsgHeadBuf_t *head)
{
    LoadQuitMaterial *material = load_quit_material__unpack(NULL, head->bufLen, head->buf);
    if (!material) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("set load material");
    json_object *loadMaterial = GetLoadMaterial()->macro;
    if (!loadMaterial) {
        CrLogW("load material macro fail\n");
        GcodeCmdRes res = GCODE_CMD_RES__INIT;
        res.result = 0;
        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd_res__pack(&res, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_LOAD_MATERIAL_ANS, buff, len);
        MANAGER_MSG_SEND(head->origin, &send, size);
        
        UserSetLoadMaterialResult(100);
        load_quit_material__free_unpacked(material, NULL);
        return;
    }
    
    // 修改目标温度
    if (material->has_targettemp) {
        for (int i = 0; i < json_object_array_length(loadMaterial); i++)
        {
            json_object *gcodeObj = json_object_array_get_idx(loadMaterial, i);
            if (strstr(json_object_get_string(gcodeObj), "M109"))
            {
                char temp[256] = {0};
                snprintf(temp, sizeof(temp), "M109 S%d", material->targettemp);
                json_object_set_string(gcodeObj, temp);
                break;
            }
        }
    }

    // 重置进退料状态
    UpdataLoadMaterial(0);
    UpdataQuitMaterial(0);

    // 更新设备状态
    devStateBeforeInAndOutMaterial = GetPrintState().deviceState;
    UpdataDeviceState(DEVICE_STATE_LOAD_MATERIAL);

    // 启动进料
    CrLogI("load material = %s", json_object_to_json_string(loadMaterial));
    AppGcodeMacroRecv(GetLoadMaterial()->macro, UserSetLoadMaterialResult);

    // 应答
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = 1;
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_LOAD_MATERIAL_ANS, buff, len);
    MANAGER_MSG_SEND(head->origin, &send, size);
    
    load_quit_material__free_unpacked(material, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {int} res
 */
static void UserSetQuitMaterialResult(int res)
{
    CrLogI("user set quit material result = %d", res);
    UpdataQuitMaterial(res);
    // 退料结束
    if (res == 100) UpdataDeviceState(devStateBeforeInAndOutMaterial);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetQuitMaterialReq(MsgHeadBuf_t *head)
{
    LoadQuitMaterial *material = load_quit_material__unpack(NULL, head->bufLen, head->buf);
    if (!material) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("set quit material");
    json_object *quitMaterial = GetQuitMaterial()->macro;
    if (!quitMaterial) {
        CrLogW("quit material macro fail\n");
        GcodeCmdRes res = GCODE_CMD_RES__INIT;
        res.result = 0;
        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_cmd_res__pack(&res, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_QUIT_MATERIAL_ANS, buff, len);
        MANAGER_MSG_SEND(head->origin, &send, size);

        UserSetQuitMaterialResult(100);
        load_quit_material__free_unpacked(material, NULL);
        return;
    }
    
    // 修改目标温度
    if (material->has_targettemp) {
        for (int i = 0; i < json_object_array_length(quitMaterial); i++)
        {
            json_object *gcodeObj = json_object_array_get_idx(quitMaterial, i);
            if (strstr(json_object_get_string(gcodeObj), "M109"))
            {
                char temp[256] = {0};
                snprintf(temp, sizeof(temp), "M109 S%d", material->targettemp);
                json_object_set_string(gcodeObj, temp);
                break;
            }
        }
    }

    // 重置进退料状态
    UpdataLoadMaterial(0);
    UpdataQuitMaterial(0);

    // 更新设备状态
    devStateBeforeInAndOutMaterial = GetPrintState().deviceState;
    UpdataDeviceState(DEVICE_STATE_QUIT_MATERIAL);

    // 启动退料
    CrLogI("quit material = %s", json_object_to_json_string(quitMaterial));
    AppGcodeMacroRecv(GetQuitMaterial()->macro, UserSetQuitMaterialResult);

    // 应答
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = 1;
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_QUIT_MATERIAL_ANS, buff, len);
    MANAGER_MSG_SEND(head->origin, &send, size);

    load_quit_material__free_unpacked(material, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *LaserCalibrationThread(void *arg)
{
    // 启动校准
    int calibrationResult = StartLaserCalibration();
    CrLogI("laser calibration result = %d\n", calibrationResult);

    // 应答
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    if (calibrationResult == 0) res.result = 1;
    else res.result = 0;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_LASER_CALIBRATION_ANS, buff, len);
    MANAGER_MSG_SEND(startLaserCalibrationOrigin, &send, size);

    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetLaserCalibrationReq(MsgHeadBuf_t *head)
{
    CrLogI("set laser calibration\n");
    startLaserCalibrationOrigin = head->origin;

    // 新开线程执行激光校准
    pthread_t calibration;
    if (pthread_create(&calibration, NULL, &LaserCalibrationThread, NULL)) {
        CrLogE("create pthread error!\n");
        return;
    }
    pthread_detach(calibration);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetEndPrintPointReq(MsgHeadBuf_t *head)
{
    CrLogI("set end print point");
    json_object *params = json_object_new_object();
    json_object_object_add(params, "script", json_object_new_string("END_PRINT"));
    AddKlipperCmd("gcode/script", params, KLIPPER_END_PRINT_POINT_NUM, head->origin);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetExcludeObjectReq(MsgHeadBuf_t *head)
{
    MutableTypeData *excludeObject = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!excludeObject) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("set exclude object");
    if (excludeObject->has_bytes_v)
    {
        char tempPara[200] = {0};
        memcpy(tempPara, excludeObject->bytes_v.data, excludeObject->bytes_v.len);
        char setCmd[256] = {0};
        snprintf(setCmd, sizeof(setCmd), "EXCLUDE_OBJECT NAME=%s", tempPara);

        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(setCmd));
        AddKlipperCmd("gcode/script", params, KLIPPER_SET_EXCLUDE_OBJECT_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    mutable_type_data__free_unpacked(excludeObject, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetMeshInfoReq(MsgHeadBuf_t *head)
{
    MutableTypeData *meshInfo = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!meshInfo) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("set mesh info");
    if (meshInfo->has_bytes_v)
    {
        char setCmd[meshInfo->bytes_v.len + 1];
        bzero(setCmd, sizeof(setCmd));
        memcpy(setCmd, meshInfo->bytes_v.data, meshInfo->bytes_v.len);

        json_object *params = json_tokener_parse(setCmd);
        AddKlipperCmd("update_mesh", params, KLIPPER_SET_MESH_INFO_NUM, head->origin);
    }
    else CrLogW("Error control instruction\n");

    mutable_type_data__free_unpacked(meshInfo, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetSdCardFileReq(MsgHeadBuf_t *head)
{
    GetGcodeFIleList *cmd = get_gcode_file_list__unpack(NULL, head->bufLen, head->buf);
    if (!cmd) {
        CrLogW("unpack failed\n");
        return;
    }

    // 缓存本地gcode文件
    CrLogI("traverse sort = %d, path = %s", cmd->sort, cmd->path.data);
    int fileSum = GetLocalGcodeFileInfo((char*)cmd->path.data, cmd->sort, GetUserGcodeFileInfoFilePath());

    // 应答文件总数
    GcodeCmdRes sdFileSum = GCODE_CMD_RES__INIT;
    sdFileSum.result = fileSum >= 0 ? 1 : 0;;
    sdFileSum.has_resstr = 1;
    sdFileSum.resstr.data = (uint8_t *)&fileSum;
    sdFileSum.resstr.len = sizeof(int);
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&sdFileSum, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_GET_SD_FILE_ANS, buff, len);
    MANAGER_MSG_SEND(head->origin, &send, size);

    GET_MESSAGE_BUFF(buff1);
    size_t len1 = get_gcode_file_list__pack(cmd, buff1);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_GET_SD_FILE_LIST_ANS, buff1, len1);
    MANAGER_MSG_SEND(head->origin, &send1, size1);

    get_gcode_file_list__free_unpacked(cmd, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetHotendXyzLocalReq(MsgHeadBuf_t *head)
{
    GcodeCmd *local = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!local) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("get dev cur xyz local");
    char sendBuff[100] = {0};
    String_t tCmd = {0};

    if (local->has_cmdstr)
    {
        char tempPara[50] = {0};
        memcpy(tempPara, local->cmdstr.data, local->cmdstr.len);
        snprintf(sendBuff, 100, "%s %s", GET_DEV_CUR_XYZ_LOCAL, tempPara);
        tCmd.data = sendBuff;
        tCmd.len = strlen(sendBuff);  
    }
    else
    {
        tCmd.data = GET_DEV_CUR_XYZ_LOCAL;
        tCmd.len = strlen(GET_DEV_CUR_XYZ_LOCAL);
    }
    AddGcodeListCmd(GET_DEV_CUR_XYZ_LOCAL_NUM, 0, &tCmd, head->origin);
    gcode_cmd__free_unpacked(local, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetSdGcodeImageReq(MsgHeadBuf_t *head)
{
    ControlRange *getImage = control_range__unpack(NULL, head->bufLen, head->buf);
    if (!getImage) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Get Sd Gcode Image");
    // 删除原来的图像文件
    if (access(GetUserTempThumbnailDirPtah(), F_OK) == 0)
    {
        char cmdStr[100] = {0};
        snprintf(cmdStr, 100, "rm %s/* && sync", GetUserTempThumbnailDirPtah());
        CrLogI("system cmd str = %s", cmdStr);

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmdStr, sysRes, sizeof(sysRes))) {
            CrLogW("system fail! res = %s\n", sysRes);
            CrLogE("delete sd old gcode image error\n");
        }
    }

    // 记录范围
    ControlRange_t getId;
    getId.start = getImage->start;
    getId.current = getImage->start;
    getId.end = getImage->end;
    SetUserGetGcodeImageEndFileId(getId);

    // 获取缩略图
    SaveLocalGcodeImageToFile(GetUserGcodeFileInfoFilePath(), head->origin, 1);
    control_range__free_unpacked(getImage, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetSdGcodePhotoReq(MsgHeadBuf_t *head)
{
    GcodeCmd *photo = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!photo) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("get sd gcode photo");
    if (photo->has_cmdstr)
    {
        // 获取注水图
        CurrentFile_t current_file = {0};
        strcat(current_file.preview, GetUserTempOriginalPtah());
        int result = GetLocalGcodePhotoToFile((char*)photo->cmdstr.data, &current_file, GCODE_PHOTO_TYPE_PREVIEW);
        CrLogI("updata Get Sd Gcode Photo Result = %d", result);
    
        // 响应
        GcodePhotoInfoRes res = GCODE_PHOTO_INFO_RES__INIT;
        res.result = result;
        res.start_pixel = current_file.startPixel;
        res.end_pixel = current_file.endPixel;
        res.model_height = current_file.modelHeight;
        res.layer_height = current_file.layerHeight;
        res.path.data = (uint8_t*)current_file.preview;
        res.path.len = strlen(current_file.preview) + 1;

        GET_MESSAGE_BUFF(buff);
        size_t len = gcode_photo_info_res__pack(&res, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_GET_SD_GCODE_PHOTO_ANS, buff, len);
        MANAGER_MSG_SEND(head->origin, &send, size);
    }
    else
    {
        CrLogW("No file id specified to get normal image\n");
    }
    
    gcode_cmd__free_unpacked(photo, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void systemGetMcuVersionReq(MsgHeadBuf_t *head)
{
    CrLogI("system get mcu version");
    json_object *params = json_object_new_object();
    AddKlipperCmd("getBootLoaderVersion", params, KLIPPER_GET_MCU_VERSION_NUM, head->origin);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetGsensorExistReq(MsgHeadBuf_t *head)
{
    MultiGsensor *gsensor = multi_gsensor__unpack(NULL, head->bufLen, head->buf);
    if (!gsensor) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("get gsensor exist");
    char klipperApi[1024] = {0};
    strcat(klipperApi, "getAdxl345Status");

    if (gsensor->has_multi_gsensor_x) strcat(klipperApi, "_x");
    else if (gsensor->has_multi_gsensor_y) strcat(klipperApi, "_y");
    else if (gsensor->has_multi_gsensor_all) strcat(klipperApi, "");
    else CrLogW("Error control instruction\n");

    json_object *params = json_object_new_object();
    AddKlipperCmd(klipperApi, params, KLIPPER_GET_GSENSOR_EXIST_NUM, head->origin);

    multi_gsensor__free_unpacked(gsensor, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void startLaserTest(MsgHeadBuf_t *head)
{
    if( !head || !head->buf){
        return;
    }

    int step = atoi((char*)head->buf);
    CrLogI("startLaserTest step =%d \n",step);
    if(step==9){
        getLaserVersion();
    }else{
        StartLaserTest(step);
    }
    
    
}
/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} head
 */
int PrintfManagerMsgUpdata(MsgHeadBuf_t head)
{
    switch (head.cmd)
    {
        case MANAGER_CMD_GCODE_SET_STOP_HEATING_REQ: UserStopHeatingReq(&head); break;
        case MANAGER_CMD_GCODE_RETURN_HOME_REQ: UserReturnHomeReq(&head); break;
        case MANAGER_CMD_GCODE_HOTEND_XYZ_MOVE_REQ: UserHotendXyzMoveReq(&head); break;
        case MANAGER_CMD_GCODE_SET_AXIS_RECOUP_REQ: UserSetAxisRecoupReq(&head); break;
        case MANAGER_CMD_GCODE_SET_MOTOR_LOCK_REQ: UserSetMotorLockReq(&head); break;
        case MANAGER_CMD_GCODE_SET_MOTOR_UNLOCK_REQ: UserSetMotorUnlockReq(&head); break;
        case MANAGER_CMD_GCODE_SET_NOZZLE_TEMP_REQ: UserSetNozzleTempReq(&head); break;
        case MANAGER_CMD_GCODE_SET_BED_TEMP_REQ: UserSetBedTempReq(&head); break;
        case MANAGER_CMD_GCODE_OPEN_FAN_REQ: UserSetOpenFanReq(&head); break;
        case MANAGER_CMD_GCODE_STOP_FAN_REQ: UserSetStopFanReq(&head); break;
        case MANAGER_CMD_GCODE_LIGHT_VALUE_REQ: UserSetLightValueReq(&head); break;
        case MANAGER_CMD_GCODE_STOP_ALL_HEAT_REQ: UserSetStopAllHeatReq(&head); break;
        case MANAGER_CMD_GCODE_SET_ABSOLUTE_REQ: UserAbsolutePositioningReq(&head); break;
        case MANAGER_CMD_GCODE_SET_RELATIVE_REQ: UserRelativePositioningReq(&head); break;
        case MANAGER_CMD_GCODE_DEVICE_AUTO_LEVEL_REQ: UserDeviceAutoLevelReq(&head); break;
        case MANAGER_CMD_GCODE_SET_AUTO_LEVEL_POINTS_REQ: UserSetAutoLevelPonitsReq(&head); break;
        case MANAGER_CMD_GCODE_SET_HOTEND_PID_REQ: UserSetHotendPidReq(&head); break;
        case MANAGER_CMD_GCODE_SET_BED_PID_REQ: UserSetBedPidReq(&head); break;
        case MANAGER_CMD_GCODE_SET_DEVICE_RESET_REQ: UserControlDeviceResetReq(&head); break;
        case MANAGER_CMD_GCODE_SET_STEP_VALUE_REQ: UserSetStepValueReq(&head); break;
        case MANAGER_CMD_GCODE_SET_MAX_ACCELERATION_REQ: UserSetMaxAccelerationReq(&head); break;
        case MANAGER_CMD_GCODE_SET_MAX_SPEED_REQ: UserSetMaxSpeedReq(&head); break;
        case MANAGER_CMD_GCODE_SET_MAX_JERK_REQ: UserSetMaxJerkReq(&head); break;
        case MANAGER_CMD_GCODE_SET_MAX_CORNER_REQ: UserSetMaxCornerReq(&head); break;
        case MANAGER_CMD_GCODE_SET_PRESSURE_ADVANCE_REQ: UserSetPressureAdvanceReq(&head); break;
        case MANAGER_CMD_GCODE_SET_SMOOTH_TIME_REQ: UserSetSmoothTimeReq(&head); break;
        case MANAGER_CMD_GCODE_SET_PRINT_SPEED_REQ: UserSetPrintSpeedReq(&head); break;
        case MANAGER_CMD_GCODE_SET_PRINT_FLOW_REQ: UserSetPrintFlowReq(&head); break;
        case MANAGER_CMD_GCODE_SET_MATERIAL_DELECT_REQ: UserSetMaterialDelectReq(&head); break;
        case MANAGER_CMD_GCODE_SET_POWER_LOSS_SW_REQ: UserSetPowerLossSwReq(&head); break;
        case MANAGER_CMD_GCODE_SET_CR_TOUCH_REQ: UserSetCrTouchReq(&head); break;
        case MANAGER_CMD_GCODE_SET_HOME_OFFSET_REQ: UserSetHomeOffsetReq(&head); break;
        case MANAGER_CMD_GCODE_SET_SAVE_CONFIG_REQ: UserSetSaveConfigReq(&head); break;
        case MANAGER_CMD_GCODE_SET_INSERT_FILAMENT_REQ: UserSetInsertFilamentReq(&head); break;
        case MANAGER_CMD_GCODE_SET_GCODE_MACRO_REQ: UserSetGcodeMacroReq(&head); break;
        case MANAGER_CMD_GCODE_SET_CONSOLE_CTL_REQ: UserSetConsoleCtlReq(&head); break;
        case MANAGER_CMD_GCODE_SET_RESTART_KLIPPER_REQ: UserSetRestartKlipperReq(&head); break;
        case MANAGER_CMD_GCODE_SET_FIRMWARE_RESTART_REQ: UserSetFirmwareRestartReq(&head); break;
        case MANAGER_CMD_GCODE_SET_RESONANCE_TEST_REQ: UserSetResonanceTestReq(&head); break;
        case MANAGER_CMD_GCODE_SET_QUIET_MODE_REQ: UserSetQuietModeReq(&head); break;
        case MANAGER_CMD_GCODE_SET_LOAD_MATERIAL_REQ: UserSetLoadMaterialReq(&head); break;
        case MANAGER_CMD_GCODE_SET_QUIT_MATERIAL_REQ: UserSetQuitMaterialReq(&head); break;
        case MANAGER_CMD_GCODE_SET_LASER_CALIBRATION_REQ: UserSetLaserCalibrationReq(&head); break;
        case MANAGER_CMD_GCODE_SET_END_PRINT_POINT_REQ: UserSetEndPrintPointReq(&head); break;
        case MANAGER_CMD_GCODE_SET_EXCLUDE_OBJECT_REQ: UserSetExcludeObjectReq(&head); break;
        case MANAGER_CMD_GCODE_SET_MESH_INFO_REQ: UserSetMeshInfoReq(&head); break;

        case MANAGER_CMD_GCODE_GET_SD_FILE_REQ: UserGetSdCardFileReq(&head); break;
        case MANAGER_CMD_GCODE_GET_HOTEND_XYZ_LOCAL_REQ: UserGetHotendXyzLocalReq(&head); break;
        case MANAGER_CMD_GCODE_GET_SD_MODEL_IMAGE_REQ: UserGetSdGcodeImageReq(&head); break;
        case MANAGER_CMD_GCODE_GET_SD_GCODE_PHOTO_REQ: UserGetSdGcodePhotoReq(&head); break;

        case MANAGER_CMD_GET_CUR_MCU_VERSION_REQ: systemGetMcuVersionReq(&head); break;
        case MANAGER_CMD_GET_GSENSOR_EXIST_REQ: UserGetGsensorExistReq(&head); break;

        case MANAGER_CMD_START_LASER_TEST_REQ: startLaserTest(&head); break;
        default:
        {
            CrLogW("msg cmd file !!! origin %d, cmd %d\n", head.origin, head.cmd);
            break;
        }
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int PrintfManagerInit(void)
{
    CrLogI("print manager init");
    // PrintControlInit();
    PrintKlipperInit();

    return 0;  
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int PrintfManagerExceptionHandleSemPost(void)
{
    sdGcodeFileInfoExceptionHandleSemPost();
    return 0;
}