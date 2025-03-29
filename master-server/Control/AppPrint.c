/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-13 14:10:11
 * @LastEditTime: 2023-10-31 08:19:52
 */
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <libavformat/avformat.h>

#include "Base/MasterMsgBase.h"
#include "Controller.h"
#include "ControllerFsm.h"
#include "AppPrint.h"
#include "SocketKlipper.h"

#include "DefineGcode.h"
#include "PrintControl.h"
#include "global/SysConfig.h"

#define HEARTBEAT_COUNT_PERIOD                  500 // 10ms周期，5秒发送一次心跳给服务进程
#define AUTO_GET_TEMP_TIME                      600 // 10ms周期，6秒获取一次温度
#define AUTO_GET_TEMP_TIME_NO_WORK              100 // 10ms周期，非打印状态，1秒获取一次温度
#define AUTO_GET_PRINT_STATE                    1000 // 10ms周期，10秒获取一次打印机状态
#define AUTO_GET_PRINT_PROGRESS                 1000 // 10ms周期，10秒获取一次打印进度
#define PUASE_AUTO_GET_PARA_TIME                500 // 10ms周期，暂停自动获取参数一次，时间5秒

#define AUTO_GET_KLIPPER_STATE                  100 // 10ms周期，1秒获取一次klipper状态
#define AUTO_DETECT_FAN_STATE                   500 // 10ms周期，5秒检测风扇状态
#define AUTO_MEMORY_MONITOR_TIME                (5 * 60 * 100) // 10ms周期，5分钟检测一次是否查询内存状态

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int heartbeatCount = 0;
static PrintState_t lastPrintState = {0};
static int pauseAutoGetTempTime = 0;
static bool enableGetKlipperState = false;
static bool firstInitKlipper = true;
static Camera_t aiCamera = CAMERA_MODEL;
static AiControlPrefer aiConfig = AI_CONTROL_PREFER__INIT;
static bool AiDetectPastaRun = false;
static int AiDetectPastaNum = 0;
static FunctionFailure_t functionFailure = {0};
static ForcedUpgradeMcu_t forcedUpgradeMcu = 0;

/**
 * @description: 静态函数声明
 * @return {*}
 */
static int KlipperGetKlipperInfo(void);
static void AiDetectPasta(Camera_t cam);

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
void SetAppModeChange(FSM_MODE_t mode)
{
    CrLogI("user change dev mode = %d", mode);
    AppModeChange(mode);
    UpdataPrintWorkMode(mode);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
FSM_MODE_t GetCurrentAppMode(void)
{
    PrintState_t get = GetPrintState();
    return get.workMode;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {AppPrintState} state
 */
void SetAppStateChange(AppPrintState state)
{
    CrLogI("user change dev state = %d", state);
    UpdataPrintWorkState(state);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {AppPrintState} state
 */
AppPrintState GetCurrentAppstate(void)
{
    PrintState_t get = GetPrintState();
    return get.workState;
}

/**
 * @description: 
 * @return {*}
 * @param {FunctionFailure_t} data
 */
void SetFunctionFailure(FunctionFailure_t data) { functionFailure = data; }

/**
 * @description: 
 * @return {*}
 */
FunctionFailure_t GetFunctionFailure(void) { return functionFailure; }

/**
 * @description: 
 * @return {*}
 * @param {FaultCode_t} code
 */
void SetFunctionFailureFaultCode(FaultCode_t code) { functionFailure.lastFaultCode = code; }

/**
 * @description: 
 * @return {*}
 */
void ClearSingleTaskFunctionFailure(void) { bzero(&functionFailure.singleTask, sizeof(functionFailure.singleTask)); }

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int enablePauseAutoGetHotendBedTemp(void)
{
    pauseAutoGetTempTime = PUASE_AUTO_GET_PARA_TIME;
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {bool} state
 */
int setEnableGetKlipperState(bool state)
{
    enableGetKlipperState = state;
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
void AutoGetGetPrinterStatus(void)
{
    // static int tempCount = 0;
    // static int stateCount = 0;
    // static int progressCount = 0;

    // // 暂停获取状态
    // if (pauseAutoGetTempTime)
    // {
    //     pauseAutoGetTempTime--;
    //     tempCount = 0;
    //     stateCount = 0;
    //     progressCount = 0;
    //     return;
    // }

    // // 周期性获取温度，
    // tempCount++;
    // if ((GetCurrentAppstate() != APP_PRINT_STATE_WORK && tempCount >= AUTO_GET_TEMP_TIME_NO_WORK) ||
    //     tempCount >= AUTO_GET_TEMP_TIME)
    // {
    //     CrLogI("Actively get the current temperature\n");
    //     tempCount = 0;
    //     String_t tCmd = {0};
    //     tCmd.data = GET_CUR_HOTEND_BED_TEMP;
    //     tCmd.len = strlen(GET_CUR_HOTEND_BED_TEMP);
    //     AddGcodeListCmd(GET_CUR_HOTEND_BED_TEMP_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);
    // }
    // // 周期性获取打印机状态
    // if (++stateCount >= AUTO_GET_PRINT_STATE)
    // {
    //     CrLogI("Actively obtain print status\n");
    //     stateCount = 0;
    //     String_t tCmd = {0};
    //     tCmd.data = CXSW_GET_PRINT_STATUS;
    //     tCmd.len = strlen(CXSW_GET_PRINT_STATUS);
    //     AddGcodeListCmd(CXSW_GET_PRINT_STATUS_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);
    // }
    // // 周期性获取进度
    // if (GetCurrentAppMode() == APP_MODE_SD_PRINT &&
    //     GetCurrentAppstate() == APP_PRINT_STATE_WORK &&
    //     ++progressCount >= AUTO_GET_PRINT_PROGRESS)
    // {
    //     CrLogI("Actively obtain printing progress\n");
    //     progressCount = 0;
    //     String_t tCmd = {0};
    //     tCmd.data = GET_DEVICE_PRINT_PROGRESS;
    //     tCmd.len = strlen(GET_DEVICE_PRINT_PROGRESS);
    //     AddGcodeListCmd(GET_DEVICE_PRINT_PROGRESS_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);
    // }

    // 周期性获取klipper状态
    static int klipperStateCount = 0;
    if (enableGetKlipperState) {
        if (++klipperStateCount >= AUTO_GET_KLIPPER_STATE) {
            klipperStateCount = 0;
            KlipperGetKlipperInfo();
        }
    }
    else klipperStateCount = 0;

    // 周期性检测是否存在打印意面
    static int AiDetectPastaCount = 0;
    if (GetCurrentAppMode() != APP_MODE_IDLE &&
        GetCurrentAppstate() == APP_PRINT_STATE_WORK &&
        GetPrintState().cameraOnline[CAMERA_MODEL] &&
        GetPrintState().printProgress > 0 &&
        GetPrintState().withSelfTest >= 100 &&
        !AiDetectPastaRun)
    {
        if (++AiDetectPastaCount >= (aiConfig.pastatime * 100)) {
            AiDetectPastaCount = 0;
            GetAiControlPrefer(&aiConfig);
            if (aiConfig.sw) AiDetectPasta(CAMERA_MODEL);
        }
    }
    else {
        AiDetectPastaCount = 0;
        if (GetCurrentAppMode() == APP_MODE_IDLE) AiDetectPastaNum = 0;
    }

    // 周期性检测风扇是否异常
    static int fanDetectCount = 0;
    static bool lastFanRun = false;
    if (GetCurrentAppstate() == APP_PRINT_STATE_WORK &&
        GetPrintState().klipperPrint == KLIPPER_PRINT_PRINTING &&
        GetFanFeedback()->exist && ++fanDetectCount >= AUTO_DETECT_FAN_STATE)
    {
        fanDetectCount = 0;
        bool fanRun = (GetPrintState().nozzleCurTemp[NOZZLE_TEMP] / 100) > GetheaterFanHotendFan()->heater_temp;
        // 确认风扇已启动
        if (fanRun && lastFanRun)
        {
            // 判断喉管风扇是否正常转动
            // 区分不同机型硬件情况不同
            switch (GetSystemConfig().model)
            {
            case PF_05:
            {
                break;
            }
            case CR_K1:
            case CR_K1_Max:
                {
                    if (!GetFunctionFailure().singleTask.throatFanDetect &&
                        GetPrintState().fanSpeed[MULTI_FAN_THROAT] <= 0)
                    {
                        UpdataErrorStateToManager(FAULT_THROAT_FAN_ABNORMAL_PAUSE, "throat fan runing abnormal", NULL);
                        GcodeCmd control = GCODE_CMD__INIT;
                        GET_MESSAGE_BUFF(buff);
                        size_t len = gcode_cmd__pack(&control, buff);
                        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_PAUSE_PRINT_REQ, buff, len);
                        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
                    }
                }
                break;
            default:
                {
                    break;
                }
            }

            // 判断主板风扇是否正常转动
            if (GetPrintState().fanSpeed[MULTI_FAN_MOTHERBOARD] <= 0)
                UpdataErrorStateToManager(FAULT_MOTHERBOARD_FAN_RUNING_ABNORMAL, "motherboard fan runing abnormal", NULL);
            else if (GetPrintState().faultCode.code == FAULT_MOTHERBOARD_FAN_RUNING_ABNORMAL)
                UpdataErrorStateToManager(FAULT_CODE_IDLE, NULL, NULL);
        }
        // 记录前一次运行状态
        lastFanRun = fanRun;
    }

    // 周期性检测内存是否异常
    static int memoryMonitorCount = 0;
    static struct tm lastTime = {0};
    if (++memoryMonitorCount >= AUTO_MEMORY_MONITOR_TIME)
    {
        memoryMonitorCount = 0;
        int faultCode = GetPrintState().faultCode.code;

        // 获取时间
        time_t now = time(NULL);
        struct tm *CurTime = localtime(&now);

        // 获取内存资源
        SystemMemory memoryInfo = GetSystemMemorySize(GetSystemConfig().model);
        CrLogI("memory monitor; used_size = %d, free_size = %d, total_size = %d, used_pct = %.2f",
                memoryInfo.used_size, memoryInfo.free_size, memoryInfo.total_size, memoryInfo.used_pct);

        // 提示信息
        char *errorMsg = "The current memory space occupied has reached %d/%d (%.f%%)";
        json_object *errorValueObj = json_object_new_array();
        json_object_array_add(errorValueObj, json_object_new_int64(memoryInfo.used_size));
        json_object_array_add(errorValueObj, json_object_new_int64(memoryInfo.total_size));
        json_object_array_add(errorValueObj, json_object_new_double(memoryInfo.used_pct));
        const char *errorValueStr = json_object_to_json_string(errorValueObj);
        CrLogI("memory monitor; errorValueStr = %s\n", errorValueStr);

        // 检查内存使用情况
        if (memoryInfo.free_size < 500) {
            if (CurTime->tm_hour != lastTime.tm_hour)
            {
                UpdataErrorStateToManager(FAULT_NOT_ENOUGH_STORAGE_REMIND, errorMsg, (char*)errorValueStr);
                lastTime = *CurTime;
            }
        }
        else if (memoryInfo.free_size < 1024) {
            if (CurTime->tm_mday != lastTime.tm_mday)
            {
                UpdataErrorStateToManager(FAULT_NOT_ENOUGH_STORAGE_REMIND, errorMsg, (char*)errorValueStr);
                lastTime = *CurTime;
            }
        }
        else if (faultCode == FAULT_NOT_ENOUGH_STORAGE_ERROR || faultCode == FAULT_NOT_ENOUGH_STORAGE_REMIND) {
            UpdataErrorStateToManager(FAULT_CODE_IDLE, "", NULL);
        }

        json_object_put(errorValueObj);
    }
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeUdiskMountChange(PrintState_t last, PrintState_t cur)
{
    for (int i = 0; i < UDISK_SIZE; i++) {
        if (last.udiskMount[i] != cur.udiskMount[i]) return true;
    }
    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeCameraOnlineChange(PrintState_t last, PrintState_t cur)
{
    for (int i = 0; i < CAMERA_SIZE; i++) {
        if (last.cameraOnline[i] != cur.cameraOnline[i]) return true;
    }
    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeMultiFanChange(PrintState_t last, PrintState_t cur)
{
    for (int i = 0; i < MULTI_FAN_SIZE; i++) {
        if (last.fanState[i] != cur.fanState[i]) return true;
    }
    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeMultiFanSpeedChange(PrintState_t last, PrintState_t cur)
{
    for (int i = 0; i < MULTI_FAN_SIZE; i++) {
        if (last.fanSpeed[i] != cur.fanSpeed[i]) return true;
    }
    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeMultiFanPercentageChange(PrintState_t last, PrintState_t cur)
{
    for (int i = 0; i < MULTI_FAN_SIZE; i++) {
        if (last.fanPercentage[i] != cur.fanPercentage[i]) return true;
    }
    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeNozzleTempChange(PrintState_t last, PrintState_t cur)
{
    // 当前温度
    for (int i = 0; i < NOZZLE_TEMP_SIZE; i++) {
        if (last.nozzleCurTemp[i]/100 != cur.nozzleCurTemp[i]/100) return true;
    }
    // 目标温度
    for (int i = 0; i < NOZZLE_TEMP_SIZE; i++) {
        if (last.nozzleMaxTemp[i]/100 != cur.nozzleMaxTemp[i]/100) return true;
    }

    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeHotbedTempChange(PrintState_t last, PrintState_t cur)
{
    // 当前温度
    for (int i = 0; i < HOTBED_TEMP_SIZE; i++) {
        if (last.bedCurTemp[i]/100 != cur.bedCurTemp[i]/100) return true;
    }
    // 目标温度
    for (int i = 0; i < HOTBED_TEMP_SIZE; i++) {
        if (last.bedMaxTemp[i]/100 != cur.bedMaxTemp[i]/100) return true;
    }

    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeNozzlePowerChange(PrintState_t last, PrintState_t cur)
{
    for (int i = 0; i < NOZZLE_TEMP_SIZE; i++) {
        if (last.nozzlePower[i]/100 != cur.nozzlePower[i]/100) return true;
    }
    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeHotbedPowerChange(PrintState_t last, PrintState_t cur)
{
    for (int i = 0; i < HOTBED_TEMP_SIZE; i++) {
        if (last.bedPower[i]/100 != cur.bedPower[i]/100) return true;
    }
    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeOtherTempChange(PrintState_t last, PrintState_t cur)
{
    // 当前温度
    for (int i = 0; i < OTHER_TEMP_SIZE; i++) {
        if (last.otherCurTemp[i]/100 != cur.otherCurTemp[i]/100) return true;
    }

    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeFaultCodeChange(PrintState_t last, PrintState_t cur)
{
    if (last.faultCode.code != cur.faultCode.code) return true;
    if (last.faultCode.error != cur.faultCode.error) return true;
    if (strcmp(last.faultCode.msg, cur.faultCode.msg) != 0) return true;
    if (strcmp(last.faultCode.value, cur.faultCode.value) != 0) return true;
    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeMaterialDetectorChange(PrintState_t last, PrintState_t cur)
{
    for (int i = 0; i < MATERIAL_DETECTOR_SIZE; i++) {
        if (last.materialStatus[i] != cur.materialStatus[i]) return true;
    }
    return false;
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
 * @param  {*}
 * @return {*}
 */
void AppSendPrintState()
{
    bool stateChange = false;
    PrintState_t curDevState = GetPrintState();

    // 判断是否保存报错
    if (JudgeFaultCodeChange(lastPrintState, curDevState))
        SetFaultCodeRecord(curDevState.faultCode);

    // 判断共享状态变化
    if (lastPrintState.serialPort != curDevState.serialPort ||
        lastPrintState.sdCardExists != curDevState.sdCardExists ||
        JudgeUdiskMountChange(lastPrintState, curDevState) ||
        lastPrintState.ethernetExists != curDevState.ethernetExists ||
        JudgeCameraOnlineChange(lastPrintState, curDevState) ||
        lastPrintState.laserExists != curDevState.laserExists ||
        lastPrintState.scannerExists != curDevState.scannerExists ||
        lastPrintState.deviceState != curDevState.deviceState ||
        lastPrintState.workMode != curDevState.workMode ||
        lastPrintState.workState != curDevState.workState ||
        JudgeMultiFanChange(lastPrintState, curDevState) ||
        JudgeMultiFanSpeedChange(lastPrintState, curDevState) ||
        JudgeMultiFanPercentageChange(lastPrintState, curDevState) ||
        lastPrintState.motorState != curDevState.motorState ||
        lastPrintState.lightState != curDevState.lightState ||
        lastPrintState.wifiState != curDevState.wifiState ||
        lastPrintState.printSpeed != curDevState.printSpeed ||
        lastPrintState.printFlow != curDevState.printFlow ||
        lastPrintState.realTimeSpeed != curDevState.realTimeSpeed ||
        lastPrintState.realTimeFlow != curDevState.realTimeFlow ||
        lastPrintState.printProgress/100 != curDevState.printProgress/100 ||
        lastPrintState.printLayer != curDevState.printLayer ||
        lastPrintState.printLayers != curDevState.printLayers ||
        JudgeNozzleTempChange(lastPrintState, curDevState) ||
        JudgeHotbedTempChange(lastPrintState, curDevState) ||
        JudgeNozzlePowerChange(lastPrintState, curDevState) ||
        JudgeHotbedPowerChange(lastPrintState, curDevState) ||
        JudgeOtherTempChange(lastPrintState, curDevState) ||
        lastPrintState.nozzleTempWait != curDevState.nozzleTempWait ||
        lastPrintState.bedTempWait != curDevState.bedTempWait ||

        lastPrintState.printUsageTime/60 != curDevState.printUsageTime/60 ||
        lastPrintState.printRemainTime/60 != curDevState.printRemainTime/60 ||
        lastPrintState.filamentUsed != curDevState.filamentUsed ||
        lastPrintState.autoLevelProgress != curDevState.autoLevelProgress ||
        lastPrintState.autoPidProgress != curDevState.autoPidProgress ||
        lastPrintState.crTouchState != curDevState.crTouchState ||
        JudgeFaultCodeChange(lastPrintState, curDevState) ||
        lastPrintState.existOffContinue != curDevState.existOffContinue ||
        lastPrintState.livePosition.x != curDevState.livePosition.x ||
        lastPrintState.livePosition.y != curDevState.livePosition.y ||
        lastPrintState.livePosition.z != curDevState.livePosition.z ||
        lastPrintState.livePosition.e != curDevState.livePosition.e ||
        lastPrintState.gcodePosition.x != curDevState.gcodePosition.x ||
        lastPrintState.gcodePosition.y != curDevState.gcodePosition.y ||
        lastPrintState.gcodePosition.z != curDevState.gcodePosition.z ||
        lastPrintState.gcodePosition.e != curDevState.gcodePosition.e ||
        lastPrintState.homedAxes.x != curDevState.homedAxes.x ||
        lastPrintState.homedAxes.y != curDevState.homedAxes.y ||
        lastPrintState.homedAxes.z != curDevState.homedAxes.z ||
        lastPrintState.homedAxes.e != curDevState.homedAxes.e ||
        lastPrintState.pauseStatus != curDevState.pauseStatus ||
        lastPrintState.klipperStata != curDevState.klipperStata ||
        lastPrintState.klipperPrint != curDevState.klipperPrint ||
        (strcmp(lastPrintState.sdPath, lastPrintState.sdPath) != 0) ||
        (strcmp(lastPrintState.uDiskPath, lastPrintState.uDiskPath) != 0) ||
        lastPrintState.qmodeFlag != curDevState.qmodeFlag ||
        lastPrintState.withSelfTest != curDevState.withSelfTest ||
        lastPrintState.loadMaterial != curDevState.loadMaterial ||
        lastPrintState.quitMaterial != curDevState.quitMaterial ||
        lastPrintState.cxyMqttState != curDevState.cxyMqttState ||
        lastPrintState.logProgress != curDevState.logProgress ||
        lastPrintState.scanFileProgress != curDevState.scanFileProgress ||
        JudgeMaterialDetectorChange(lastPrintState, curDevState))
    {
        stateChange = true;
    }

    // 打印机状态发生变化
    if (stateChange || (++heartbeatCount >= HEARTBEAT_COUNT_PERIOD))
    {
        heartbeatCount = 0;
        lastPrintState = curDevState;

        CrLogI("[Heartbeat] port = %d, state = %d, progress = %d, layer = %d, usage = %d, remain = %d, used = %d",
            curDevState.serialPort, curDevState.workState, curDevState.printProgress, curDevState.printLayer,
            curDevState.printUsageTime, curDevState.printRemainTime, curDevState.filamentUsed);
        CrLogI("[Heartbeat] udisk0 = %d, ethernet = %d, camera0 = %d",
            curDevState.udiskMount[UDISK_0], curDevState.ethernetExists, curDevState.cameraOnline[CAMERA_MODEL]);
        CrLogI("[Heartbeat] modelFan = %d, caseFan = %d, auxiliaryFan = %d",
            curDevState.fanState[MULTI_FAN_MODEL], curDevState.fanState[MULTI_FAN_CASE], curDevState.fanState[MULTI_FAN_AUXILIARY]);
        CrLogI("[Heartbeat] real time; speed = %d, flow = %d",
            curDevState.realTimeSpeed, curDevState.realTimeFlow);
        CrLogI("[Heartbeat] chamber = %d",
            curDevState.otherCurTemp[OTHER_TEMP_CAVITY]);
        // 打印温度
        DisplayCurrentPower(curDevState);
        DisplayCurrentTemp(curDevState);

        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_DEVICE_STATE_CHANGE, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
        MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
        MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
        MANAGER_MSG_SEND(MSG_ORIGIN_UPGRADE_MANAGER, &send, size);
    }
}

/**
 * @description: 
 * @return {*}
 */
int KlipperInitGetObjectsConfig(void)
{
    json_object *objs = json_object_new_object();
    json_object_object_add(objs, "configfile", NULL);
    json_object *params = json_object_new_object();
    json_object_object_add(params, "objects", objs);
    AddKlipperCmd("objects/query", params, KLIPPER_GET_OBJECT_CONFIG, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperGetKlipperInfo(void)
{
    json_object *params = json_object_new_object();
    AddKlipperCmd("info", params, KLIPPER_READY_HANDSHAKE_NUM, 0);
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitGetListEndpoints(void)
{
    json_object *params = json_object_new_object();
    AddKlipperCmd("list_endpoints", params, KLIPPER_SET_DEVICR_INFO, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitGetDeviceInfo(void)
{
    json_object *clientInfoObj = json_object_new_object();
    json_object_object_add(clientInfoObj, "program", json_object_new_string("c440x"));
    json_object_object_add(clientInfoObj, "version", json_object_new_string(GetSystemConfig().sys_version));
    json_object *params = json_object_new_object();
    json_object_object_add(params, "client_info", clientInfoObj);
    AddKlipperCmd("info", params, KLIPPER_GET_DEVICR_INFO, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitGetObjectsList(void)
{
    json_object *params = json_object_new_object();
    AddKlipperCmd("objects/list", params, KLIPPER_GET_OBJECT_LIST, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitRegShutdown(void)
{
    json_object *responseObj = json_object_new_object();
    json_object_object_add(responseObj, "method", json_object_new_string("shutdown_machine"));
    json_object *params = json_object_new_object();
    json_object_object_add(params, "response_template", responseObj);
    json_object_object_add(params, "remote_method", json_object_new_string("shutdown_machine"));
    AddKlipperCmd("register_remote_method", params, KLIPPER_REGISTER_REMOTE_METHOD, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitRegReboot(void)
{
    json_object *responseObj = json_object_new_object();
    json_object_object_add(responseObj, "method", json_object_new_string("reboot_machine"));
    json_object *params = json_object_new_object();
    json_object_object_add(params, "response_template", responseObj);
    json_object_object_add(params, "remote_method", json_object_new_string("reboot_machine"));
    AddKlipperCmd("register_remote_method", params, KLIPPER_REGISTER_REMOTE_METHOD, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitRegPauseJobQueue(void)
{
    json_object *responseObj = json_object_new_object();
    json_object_object_add(responseObj, "method", json_object_new_string("pause_job_queue"));
    json_object *params = json_object_new_object();
    json_object_object_add(params, "response_template", responseObj);
    json_object_object_add(params, "remote_method", json_object_new_string("pause_job_queue"));
    AddKlipperCmd("register_remote_method", params, KLIPPER_REGISTER_REMOTE_METHOD, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitRegStartJobQueue(void)
{
    json_object *responseObj = json_object_new_object();
    json_object_object_add(responseObj, "method", json_object_new_string("start_job_queue"));
    json_object *params = json_object_new_object();
    json_object_object_add(params, "response_template", responseObj);
    json_object_object_add(params, "remote_method", json_object_new_string("start_job_queue"));
    AddKlipperCmd("register_remote_method", params, KLIPPER_REGISTER_REMOTE_METHOD, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitRegTimelapseNewframe(void)
{
    json_object *responseObj = json_object_new_object();
    json_object_object_add(responseObj, "method", json_object_new_string("timelapse_newframe"));
    json_object *params = json_object_new_object();
    json_object_object_add(params, "response_template", responseObj);
    json_object_object_add(params, "remote_method", json_object_new_string("timelapse_newframe"));
    AddKlipperCmd("register_remote_method", params, KLIPPER_REGISTER_REMOTE_METHOD, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitRegTimelapseSaveFrames(void)
{
    json_object *responseObj = json_object_new_object();
    json_object_object_add(responseObj, "method", json_object_new_string("timelapse_saveFrames"));
    json_object *params = json_object_new_object();
    json_object_object_add(params, "response_template", responseObj);
    json_object_object_add(params, "remote_method", json_object_new_string("timelapse_saveFrames"));
    AddKlipperCmd("register_remote_method", params, KLIPPER_REGISTER_REMOTE_METHOD, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitRegTimelapseRender(void)
{
    json_object *responseObj = json_object_new_object();
    json_object_object_add(responseObj, "method", json_object_new_string("timelapse_render"));
    json_object *params = json_object_new_object();
    json_object_object_add(params, "response_template", responseObj);
    json_object_object_add(params, "remote_method", json_object_new_string("timelapse_render"));
    AddKlipperCmd("register_remote_method", params, KLIPPER_REGISTER_REMOTE_METHOD, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitGcodeScriptInit(void)
{
    char *scriptBuff = "ENABLE=True VERBOSE=False PARK_ENABLE=False PARK_POS=back_left CUSTOM_POS_X=10.0 CUSTOM_POS_Y=10.0 CUSTOM_POS_DZ=0.0 TRAVEL_SPEED=100 RETRACT_SPEED=15 EXTRUDE_SPEED=15 RETRACT_DISTANCE=1.0 EXTRUDE_DISTANCE=1.0 PARK_TIME=0.1 FW_RETRACT=False";
    json_object *params = json_object_new_object();
    json_object_object_add(params, "script", json_object_new_string(scriptBuff));
    AddKlipperCmd("gcode/script", params, KLIPPER_SET_DEVICR_INFO, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitSubscribeOutput(void)
{
    json_object *responseObj = json_object_new_object();
    json_object_object_add(responseObj, "method", json_object_new_string("process_gcode_response"));

    json_object *params = json_object_new_object();
    json_object_object_add(params, "response_template", responseObj);
    AddKlipperCmd("gcode/subscribe_output", params, KLIPPER_SET_DEVICR_INFO, 0);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperInitGetMeshInfo(void)
{
    json_object *params = json_object_new_object();
    AddKlipperCmd("get_mesh", params, KLIPPER_GET_MESH_INFO_NUM, 0);

    return 0;
}

/**
 * @description: 向打印机查询参数
 * @param  {*}
 * @return {*}
 */
static void GetDeviceSavePrintPara(void)
{
    // 初始化klipper
    KlipperInitGetListEndpoints();
    KlipperInitGetDeviceInfo();
    KlipperInitGetObjectsList();
    KlipperInitRegShutdown();
    KlipperInitRegReboot();
    KlipperInitRegPauseJobQueue();
    KlipperInitRegStartJobQueue();
    KlipperInitRegTimelapseNewframe();
    KlipperInitRegTimelapseSaveFrames();
    KlipperInitRegTimelapseRender();
    // KlipperInitGcodeScriptInit();
    KlipperInitSubscribeOutput();
    KlipperInitGetMeshInfo();
}

/**
 * @description: 
 * @return {*}
 */
void GetDeviceSavePowerLossInfo(void)
{
    // 判断断电续打打印文件名称文件，是否存在
    if (access(GetSavePrintFileNamePtah(), F_OK) == 0)
    {
        // 读取文件，获取json数据
        json_object *info = json_object_from_file(GetSavePrintFileNamePtah());
        if (!info) {
            CrLogW("json failed\n");
            return;
        }

        // 获取打印文件名
        json_object *filePathObj = json_object_object_get(info, "file_path");
        if (filePathObj && json_object_is_type(filePathObj, json_type_string))
        {
            const char *filePath = json_object_get_string(filePathObj);
            CrLogI("power loss filePath = %s", filePath);

            PowerLossInfo_t fileInfo = {0};
            memcpy(fileInfo.fileName, filePath, strlen(filePath));

            CrLogI("==============================");
            CrLogI("power loss info");
            CrLogI("filename = %s", fileInfo.fileName);
            CrLogI("==============================\n");
            SavePowerLossPrintInfo(fileInfo);
        }

        // 释放资源
        json_object_put(info);
    }
    else CrLogI("no power loss info \n");
}

/**
 * @description: 初始化灯光状态
 * @return {*}
 */
static void LightValueStateInit(void)
{
    // 根据机型初始化不同的灯光状态
    switch (GetSystemConfig().model)
    {
        case PF_05:
        {
            break;
        }
        case CR_K1:
        case CR_K1_Max:
        case K1_Max_SE:
        {
            // 设置系统状态
            SystemConfigProto config = SYSTEM_CONFIG_PROTO__INIT;
            config.has_light_sw = 1;
            config.light_sw = 1;
            config.has_light_value = 1;
            config.light_value = 100;
            UpdataSystemConfig(&config);

            // 打开灯光
            MutableTypeData value = MUTABLE_TYPE_DATA__INIT;
            value.has_int_v = 1;
            value.int_v = GetSystemConfig().light_value;
                
            GET_MESSAGE_BUFF(buff);
            size_t len = mutable_type_data__pack(&value, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_LIGHT_VALUE_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
            break;
        }
        default: {
            if (GetSystemConfig().light_sw) {
                MutableTypeData value = MUTABLE_TYPE_DATA__INIT;
                value.has_int_v = 1;
                value.int_v = GetSystemConfig().light_value;
                
                GET_MESSAGE_BUFF(buff);
                size_t len = mutable_type_data__pack(&value, buff);
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_LIGHT_VALUE_REQ, buff, len);
                MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
            }
            break;
        }
    }
}

/**
 * @description: 初始化共享状态
 * @param  {*}
 * @return {*}
 */
void MsaterShareStateInit(void)
{
    // 串口握手成功，获取打印机保存参数
    GetDeviceSavePrintPara();

    // 判断是否首次初始化 klipper
    if (!firstInitKlipper) return;
    firstInitKlipper = false;

    // 初始化灯光状态
    LightValueStateInit();
    // 获取AI参数
    GetAiControlPrefer(&aiConfig);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
void MsaterCreateNewLogFile()
{
    CrLogI("create new log file\n\n");
    CrLogRecreate();
}

/**
 * @description: 
 * @return {*}
 * @param {FaultCode_t} info
 */
static int FaultCodeToError(FaultCode_t info)
{
    int error = -1;

    // 获取错误码配置文件
    json_object *configObj = json_object_from_file(GetDefaultErrorCodeMapPtah());
    if (!configObj || !json_object_is_type(configObj, json_type_object)) {
        CrLogW("get config obj fail\n");
        goto ERROR_END;
    }

    // 获取错误码对照映射表
    json_object *mapObj = json_object_object_get(configObj, "code_to_error");
    if (!mapObj || !json_object_is_type(mapObj, json_type_array)) {
        CrLogW("get fault code obj fail\n");
        goto ERROR_END;
    }

    // 对比错误码
    bool getSuccessFlag = false;
    for (int i = 0; i < json_object_array_length(mapObj); i++)
    {
        // 获取对比数据
        json_object *arrayObj = json_object_array_get_idx(mapObj, i);
        if (!arrayObj || !json_object_is_type(arrayObj, json_type_object)) continue;

        // 获取 fault_code 对象
        json_object *faultCodeObj = json_object_object_get(arrayObj, "fault_code");
        if (!faultCodeObj || !json_object_is_type(faultCodeObj, json_type_int)) continue;

        // 对比
        if (info.code != json_object_get_int(faultCodeObj)) continue;

        // 获取 error 对象
        json_object *errorObj = json_object_object_get(arrayObj, "error");
        if (!errorObj || !json_object_is_type(errorObj, json_type_int)) continue;

        // 获取 error 值
        error = json_object_get_int(errorObj);
        getSuccessFlag = true;
        break;
    }

    // 未知错误
    if (!getSuccessFlag) {
        // 获取未知错误码error
        json_object *unknownObj = json_object_object_get(configObj, "unknown_error");
        if (!unknownObj || !json_object_is_type(unknownObj, json_type_int)) {
            CrLogW("get unknown error obj fail\n");
            goto ERROR_END;
        }
        error = json_object_get_int(unknownObj);
    }

ERROR_END:
    json_object_put(configObj);
    return error;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *ForcedUpgradeMcuThread(void *arg)
{
    #ifdef CROSS_COMPILE
    bool hardwareException = false;
    
    // 获取下位机版本
    json_object *versionObj = json_object_from_file("/tmp/.mcu_version");
    if(versionObj)
    {
        switch (forcedUpgradeMcu)
        {
            case FORCED_UPGRADE_MCU0:
            {
                json_object* mcuObj = json_object_object_get(versionObj, "mcu0");
                if(mcuObj) {
                    json_object* mcuVerObj= json_object_object_get(mcuObj, "version");
                    if (mcuVerObj && json_object_get_string_len(mcuVerObj) > 0) break;
                }
                
                CrLogW("no get mcu0 version info\n");
                UpdataErrorStateToManager(FAULT_MCU0_HARDWARE_EXCEPTION, "no get mcu0 version info", NULL);
                hardwareException = true;
                break;
            }
            case FORCED_UPGRADE_NOZ0:
            {
                json_object* nozObj= json_object_object_get(versionObj,"noz0");
                if(nozObj) {
                    json_object* nozVerObj= json_object_object_get(nozObj,"version");
                    if (nozVerObj && json_object_get_string_len(nozVerObj) > 0) break;
                }

                CrLogW("no get noz0 version info\n");
                UpdataErrorStateToManager(FAULT_NOZ0_HARDWARE_EXCEPTION, "no get noz0 version info", NULL);
                hardwareException = true;
                break;
            }
            case FORCED_UPGRADE_BED0:
            {
                json_object* bedObj= json_object_object_get(versionObj,"bed0");
                if(bedObj) {
                    json_object* bedVerObj= json_object_object_get(bedObj,"version");
                    if (bedVerObj && json_object_get_string_len(bedVerObj) > 0) break;
                }

                CrLogW("no get bed0 version info\n");
                UpdataErrorStateToManager(FAULT_BED0_HARDWARE_EXCEPTION, "no get bed0 version info", NULL);
                hardwareException = true;
                break;
            }
        }
    }
    json_object_put(versionObj);
    CrLogI("query MCU version end\n");

    // 硬件异常，退出升级
    if (hardwareException) {
        CrLogW("hardware exception, exit upgrade\n");
        return NULL;
    }

    // 停止与klipper握手
    setEnableGetKlipperState(false);
    // 停止获取klipper配置文件
    SetSyncKlipperConfigFile(false);
    // 停止获取继续打印信息
    SetSyncContinuePrint(false);
    // 清空发送
    CleanCurrentSendCmd();
    ClearKlipperSendGcodeList();

    // 停掉klipper服务
    CrLogI("stop klipper");
    system("/etc/init.d/S55klipper_service stop");

    // 复位下位机
    CrLogI("reset mcu");
    system("mcu_reset.sh");

    // 延时保证下位机复位生效
    sleep(1);

    // 强制更新MCU固件
    char upgradeMcu[256] = {0};
    switch (forcedUpgradeMcu)
    {
        case FORCED_UPGRADE_MCU0: strcat(upgradeMcu, "FORCE=mcu0 /etc/init.d/S13mcu_update start"); break;
        case FORCED_UPGRADE_NOZ0: strcat(upgradeMcu, "FORCE=noz0 /etc/init.d/S13mcu_update start"); break;
        case FORCED_UPGRADE_BED0: strcat(upgradeMcu, "FORCE=bed0 /etc/init.d/S13mcu_update start"); break;
    }
    CrLogI("upgrade mcu = %s", upgradeMcu);
    system(upgradeMcu);

    // 启动klipper服务
    CrLogI("start klipper\n");
    system("/etc/init.d/S55klipper_service start");

    // 启动与 klipper 握手
    setEnableGetKlipperState(true);
    // 获取klipper配置文件
    SetSyncKlipperConfigFile(true);
    // 获取继续打印信息
    SetSyncContinuePrint(true);
    // 断开klipper连接
    KlipperSocketDeinit();
    #endif
    
    return NULL;
}

/**
 * @description: 
 * @return {*}
 */
static int AutoHandleErrorException(int code, char *message)
{
    // 应用自动处理部分报错，保证用户使用流畅
    switch (code)
    {
        // 无法更新下位机配置，主动重启下位机
        case FAULT_KLIPPER_UNABLE_UPGRADE_MCU_CONFIG: {
            CrLogW("auto firmware restart\n");
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_FIRMWARE_RESTART_REQ, "", 0);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
            return 0;
        }
        
        // 开机klipper与下位机连接超时
        case FAULT_KLIPPER_MCU0_CONNECT_TIMEOUT:
        case FAULT_KLIPPER_NOZ0_CONNECT_TIMEOUT:
        case FAULT_KLIPPER_BED0_CONNECT_TIMEOUT:
        {
            CrLogW("mcu connection timeout\n");
            // 选择需要升级的MCU
            switch (code) {
                case FAULT_KLIPPER_MCU0_CONNECT_TIMEOUT: forcedUpgradeMcu = FORCED_UPGRADE_MCU0; break;
                case FAULT_KLIPPER_NOZ0_CONNECT_TIMEOUT: forcedUpgradeMcu = FORCED_UPGRADE_NOZ0; break;
                case FAULT_KLIPPER_BED0_CONNECT_TIMEOUT: forcedUpgradeMcu = FORCED_UPGRADE_BED0; break;
            }

            pthread_t handle;
            if (pthread_create(&handle, NULL, (void*)ForcedUpgradeMcuThread, NULL)) {
                CrLogE("create pthread error!\n");
                break;
            }
            pthread_detach(handle);
            return 0;
        }

        // 开机klipper计数器与下位机不同步
        case FAULT_KLIPPER_RESCHEDULED_TIMER_IN_THE_PAST:
        {
            // 判断开机时间，大于1分钟不再自动修复这个错误
            struct timespec startTime;
            clock_gettime(CLOCK_MONOTONIC_RAW, &startTime);
            if (startTime.tv_sec >= 60) {
                CrLogW("Long boot time does not automatically repair errors\n");
                break;
            }
            
            CrLogW("Rescheduled timer in the past\n");
            // 选择需要升级的MCU
            if (strstr(message, "'mcu'")) forcedUpgradeMcu = FORCED_UPGRADE_MCU0;
            if (strstr(message, "'mcu nozzle_mcu'")) forcedUpgradeMcu = FORCED_UPGRADE_NOZ0;
            if (strstr(message, "'mcu leveling_mcu'")) forcedUpgradeMcu = FORCED_UPGRADE_BED0;

            pthread_t handle;
            if (pthread_create(&handle, NULL, (void*)ForcedUpgradeMcuThread, NULL)) {
                CrLogE("create pthread error!\n");
                break;
            }
            pthread_detach(handle);
            return 0;
        }

        // 最后是直接忽略的错误码
        case FAULT_KLIPPER_START_UP_STATE:
        {
            CrLogW("ignore error code; code = %d", code);
            return 0;
        }
        default: break;
    }
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {int} code
 */
static void HandleSpecifiedErrorException(int code)
{
    switch (code)
    {
        // 打开文件错误，打印失败
        case FAULT_KLIPPER_OPEN_FILE_FAIL: {
            if (GetCurrentAppMode() != APP_MODE_IDLE)
            {
                SetAppStateChange(APP_PRINT_STATE_FAIL);
                SetAppModeChange(APP_MODE_IDLE);
            }
            break;
        }
    }
}

/**
 * @description: 
 * @return {*}
 * @param {int} code
 * @param {char} *message
 * @param {char} *value
 */
void UpdataErrorStateToManager(int code, char *message, char *value)
{
    // 针对特定错误码，做主动操作，不同步错误
    if (AutoHandleErrorException(code, message) == 0) return;
    // 指定错误码需要特殊操作，不消除错误码
    HandleSpecifiedErrorException(code);

    // 同步错误码
    FaultCode_t info = {0};
    info.code = code;
    if (message) strcat(info.msg, message);
    if (value) strcat(info.value, value);
    // 将错误码“code”归类成交互使用的“error”
    if (code != 0) info.error = FaultCodeToError(info);

    // 更新错误码
    CrLogE("updata fault code:");
    CrLogE("error = %d, code = %d", info.error, info.code);
    CrLogE("msg = %s", info.msg);
    CrLogE("value = %s\n", info.value);  
    UpdataFaultCode(info);
    SetFunctionFailureFaultCode(info);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
void DeleteOldDelayImageH264File(void)
{
    if (access(GetUserDelayImageH264Ptah(), F_OK) == 0)
    {
        CrLogI("delete old delay image h264 file");
        if (remove(GetUserDelayImageH264Ptah()) != 0)
            CrLogW("remove delay image h264 fail\n");
    }
}

/**
 * @description: 
 * @return {*}
 */
void DeleteOldAiImageFile(void)
{
    if (access(GetUserAiImageDirPtah(), F_OK) == 0)
    {
        CrLogI("delete old ai image file");
        char cmd[256] = {0};
        snprintf(cmd, sizeof(cmd), "rm -rf %s/* && sync", GetUserAiImageDirPtah());
        CrLogI("cmd = %s", cmd);

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("remove ai image fail\n");
    }
}

/**
 * @description: 
 * @return {*}
 */
void CumulativePrintingTime(void)
{
    uint32_t tempTotal = GetPrintState().printUsageTime;
    CrLogI("updata print total time = %d", tempTotal);
    SystemConfigProto config = SYSTEM_CONFIG_PROTO__INIT;
    config.has_total_time = 1;
    config.total_time = tempTotal;
    UpdataSystemConfig(&config);
}

/**
 * @description: 
 * @return {*}
 */
static char *GetSaveDelayImageCover(void)
{
    CrLogI("get save delay image cover");
    if (access(GetUserAiImageCapturePtah(), F_OK) != 0)
    {
        // 生成图片
        CrLogI("create delay image cover");
        char cmd[256] = {0}, sysRes[1024] = {0};
        snprintf(cmd, sizeof(cmd), "ai_engine %d %d", CAMERA_MODEL, ai_fault_mode);
        PopenSystem(cmd, sysRes, sizeof(sysRes));
    }
    
    // 获取图片
    if (access(GetUserAiImageCapturePtah(), F_OK) == 0) {
        return GetUserAiImageCapturePtah();
    }
    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *fileName
 * @param {VideoInfo_t} *info
 */
static bool GetVideoInfo(char *fileName, VideoInfo_t *info)
{
    //注册复用器，编码器等
    av_register_all();

    // 打开视频文件
    AVFormatContext *formatContext = NULL;
    if (avformat_open_input(&formatContext, fileName, NULL, NULL) != 0) {
        CrLogW("open video file fail\n");
        goto GET_INFO_END;
    }
 
    // 查找视频文件中的流信息
    if (avformat_find_stream_info(formatContext, NULL) < 0) {
        printf("find video file info fail\n");
        goto GET_INFO_END;
	}

    // 获取视频信息
    bzero(info->fileName, sizeof(info->fileName));
    strcat(info->fileName, fileName);
    info->duration = (double)formatContext->duration / AV_TIME_BASE;
 
	// 关闭视频文件
	avformat_close_input(&formatContext);
	return true;

GET_INFO_END:
    avformat_close_input(&formatContext);
    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *path
 */
static int SaveDelayImageInfoToFile(char *path, char *cover)
{
    CrLogI("save delay image info\n");
    PrintState_t state = GetPrintState();
    CurrentFile_t workInfo = GetPrinter()->current_file;

    DelayImagePrefer imageRefer = DELAY_IMAGE_PREFER__INIT;
    GetDelayImagePrefer(&imageRefer);

    // 获取视频封面
    char coverPath[256] = {0};
    snprintf(coverPath, sizeof(coverPath), "%s/%d.png", GetUserDelayImageCoverPtah(), workInfo.id);
    CrLogI("coverPath = %s", coverPath);

    // 复制封面，判断图片是否是jpg格式
    if (cover != NULL && strstr(cover, ".jpg")) {
        JpegToPng(cover, coverPath, 4); // 将jpeg格式图片转换成png格式
    }
    else
    {
        char cpCmd[600] = {0};
        if (cover != NULL) snprintf(cpCmd, sizeof(cpCmd), "cp '%s' '%s' && sync", cover, coverPath);
        else snprintf(cpCmd, sizeof(cpCmd), "cp '%s' '%s' && sync", workInfo.thumbnails, coverPath);
        CrLogI("cpCmd = %s", cpCmd);

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cpCmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    // 获取文件大小
    struct stat stat_info;
    int ret = lstat(path, &stat_info);
    if (ret != 0) CrLogW("%s get info error !", path);

    // 获取视频文件信息
    VideoInfo_t videoInfo = {0};
    GetVideoInfo(path, &videoInfo);
    CrLogI("video info; duration = %d\n", videoInfo.duration);

    // 打包视频文件信息
    DelayImageInfo info = DELAY_IMAGE_INFO__INIT;
    info.name.data = (uint8_t*)workInfo.fileName;
    info.name.len = strlen(workInfo.fileName);
    info.id = workInfo.id;
    info.video.data = (uint8_t*)path;
    info.video.len = strlen(path);
    info.size = stat_info.st_size;
    info.duration = videoInfo.duration;
    info.cover.data = (uint8_t*)coverPath;
    info.cover.len = strlen(coverPath);
    info.starttime = workInfo.startTime;
    info.printtime = state.printUsageTime;
    info.location = imageRefer.location;
    info.interval = imageRefer.interval;
    info.render = imageRefer.frame;

    SetDelayImageInfo(info);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *H264ToMp4ConvertThread(void *arg)
{
    // 判断封面文件夹是否存在
    if (access(GetUserDelayImageCoverPtah(), F_OK) != 0) {
        CrLogI("create delay image cover ptah");
        char cmd[300] = {0};
        snprintf(cmd, 300, "mkdir -p %s", GetUserDelayImageCoverPtah());

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    // 判断视频文件夹是否存在
    if (access(GetUserDelayImageVideoPtah(), F_OK) != 0) {
        CrLogI("create delay image video ptah");
        char cmd[300] = {0};
        snprintf(cmd, 300, "mkdir -p %s", GetUserDelayImageVideoPtah());
            
        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);
    }

    // 创建mp4文件名称（包含绝对路径）
    char filePath[512] = {0};
    snprintf(filePath , sizeof(filePath) ,"%s/%d.mp4", GetUserDelayImageVideoPtah(), GetPrinter()->current_file.id);
    CrLogI("image path = %s", filePath);
        
    // 获取延时摄影帧数
    DelayImagePrefer pre = DELAY_IMAGE_PREFER__INIT;
    GetDelayImagePrefer(&pre);
    int imageFrame = 15;
    if (pre.has_frame) imageFrame = pre.frame;
    CrLogI("image frame = %d", imageFrame);

    // 生成mp4文件
    char convertCmd[1024] = {0};
    snprintf(convertCmd, 1024, GetDefaultH264ConvertMp4Script(), imageFrame, GetUserDelayImageH264Ptah(), filePath);
    CrLogD("mp4 convert cmd = %s", convertCmd);
    CrLogI("start convert h264 to mp4 ...\n");

    // 开始转换
    #ifdef CROSS_COMPILE
    // 调用系统命令
    char sysRes[1024] = {0};
    if (PopenSystem(convertCmd, sysRes, sizeof(sysRes)))
    {
        CrLogI("create delay image finish\n");
        // 保存视频相关信息
        // SaveDelayImageInfoToFile(filePath, GetSaveDelayImageCover());
        SaveDelayImageInfoToFile(filePath, NULL);
        SendString uploadVideo = SEND_STRING__INIT;
        uploadVideo.str.data = (uint8_t*)filePath;
        uploadVideo.str.len = strlen(filePath) + 1;
            
        GET_MESSAGE_BUFF(buff);
        size_t len = send_string__pack(&uploadVideo, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_UPLOAD_DELAY_IMAGE, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    }
    else {
        CrLogW("system fail! res = %s\n", sysRes);
        CrLogE("H264 conversion to mp4 failed\n");
    }
    #endif

    // 结束线程，释放资源
    pthread_detach(pthread_self());
    return NULL;
}

/**
 * @description: 
 * @return {*}
 */
int UploadDelayImage(void)
{
    // 获取配置参数
    DelayImagePrefer pre = DELAY_IMAGE_PREFER__INIT;
    GetDelayImagePrefer(&pre);
    CrLogI("create delay image; sw = %d, frame = %d, interval = %d", pre.sw, pre.frame, pre.interval);

    // 判断延时摄影开关
    if (!pre.has_sw || !pre.sw) return -1;
    // 判断是否有H264文件
    if (access(GetUserDelayImageH264Ptah(), F_OK) != 0) {
        CrLogW("no find h264 file\n");
        return -1;
    }

    // 判断打印层数，是否需要生成延时摄影视频
    int needMinLayer = pre.mintime * pre.frame * pre.interval;
    CrLogI("last layer = %d, need min layer = %d", GetPrinter()->virtual_sdcard.last_layer, needMinLayer);
    if (GetPrinter()->virtual_sdcard.last_layer < needMinLayer) {
        CrLogW("printing layers is small, no video is generated");
        return -1;
    }
    
    // H264转MP4视频
    CrLogI("Upload Delay Image\n");
    pthread_t handle;
    int res = pthread_create(&handle, NULL, (void*)H264ToMp4ConvertThread, NULL);
    if (res) {
        CrLogE("create pthread error!\n");
        return -1;
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {bool} isUpdata
 */
int UploadPrintHistoryRecord(bool isUpdata)
{
    CrLogI("Upload Print History Record\n");
    KlipperPrint_t *printer = GetPrinter();
    HistoryRecord history = HISTORY_RECORD__INIT;

    history.id = printer->current_file.id;
    history.filename.data = (uint8_t*)printer->current_file.fileName;
    history.filename.len = strlen(printer->current_file.fileName);
    history.size = printer->current_file.size;
    history.ctime = printer->current_file.cTime;
    history.starttime = printer->current_file.startTime;
    history.startway = printer->current_file.startWay;
    history.usagetime = printer->print_stats.print_duration;
    history.usagematerial = printer->print_stats.filament_used_real;
    if (GetPrintState().printProgress == 100 * 100) history.printfinish = 1;
    else history.printfinish = 0;
    history.thumbnail.data = (uint8_t*)printer->current_file.thumbnails;
    history.thumbnail.len = strlen(printer->current_file.thumbnails);
    // 打印文件MD5码
    char fileMd5[256] = {0};
    getFileMD5(printer->current_file.fileName, fileMd5);
    history.filemd5.data = (uint8_t*)fileMd5;
    history.filemd5.len = strlen(fileMd5);
    SetHistoryRecord(history, isUpdata);
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int SaveCameraAiDetectImage(void)
{
    // 创建新路径
    struct timeval nowTime;
    gettimeofday(&nowTime, NULL);
    struct tm *CurTime = localtime(&nowTime.tv_sec);

    char saveJpg[256] = {0};
    snprintf(saveJpg, DEF_PATH_LEN, "%s/%04d-%02d-%02d_%02d-%02d-%02d", GetUserAiImageDirPtah(),
        CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday, CurTime->tm_hour , CurTime->tm_min , CurTime->tm_sec);

    // 创建路径
    if (access(saveJpg, F_OK) != 0) {
        char cmd[300] = {0};
        snprintf(cmd, 300, "mkdir -p %s", saveJpg);

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    // 保存文件原始图片
    char cmd[1024] = {0};
    snprintf(cmd, sizeof(cmd), "cp %s/*.jpg %s && sync", GetUserAiImageDirPtah(), saveJpg);
    CrLogI("save ai image = %s\n", cmd);
    char sysRes[1024] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {Camera_t} *camNum
 * @param {AiDetectMode_t} mode
 * @param {AiResults_t} *aiResult
 * @param {int} aiMaxNum
 */
static int CameraAiDetect(Camera_t *camNum, AiDetectMode_t mode, AiResults_t *aiResult, int aiMaxNum)
{
    // 拼接AI指令
    char aiEngineCmd[100] = {0};
    snprintf(aiEngineCmd, sizeof(aiEngineCmd), "ai_engine %d %d", *camNum, mode);
    CrLogI("ai engine cmd = %s\n", aiEngineCmd);

    // 调用AI接口
    char buff[2048] = {0};
    #ifdef CROSS_COMPILE
    if (!PopenSystem(aiEngineCmd, buff, sizeof(buff))) {
        CrLogW("ai engine cmd fail !!\n");
        return -1;
    }
    #endif

    // 判断AI是否执行完成
    CrLogI("ai engine res = \n%s\n", buff);
    char *aiCompleted = strstr(buff, "ai detection completed");
    if (!aiCompleted) {
        CrLogW("ai detection fail\n");
        return -1;
    }

    // 获取AI识别个数
    char *aiSizeStr = strtok(aiCompleted + strlen("ai detection completed, cnt = "), "\n");
    int aiSizeInt = atoi(aiSizeStr);

    // AI个数不小于0，AI识别有效
    if (aiSizeInt < 0) {
        CrLogW("ai detection no valid value\n");
        return -1;
    }

    // 暂存AI识别结果
    char valueStr[aiSizeInt][512];
    bzero(valueStr, sizeof(valueStr));
    
    // 去除无效字符
    char *aiResultStr = strtok(NULL, "\n");
    // 开始提取结果字符串
    for (int temp = 0; temp < aiSizeInt; temp++)
    {
        // 切割AI结果
        aiResultStr = strtok(NULL, "\n");
        if (!aiResultStr) continue;
        strcat(valueStr[temp], aiResultStr);
    }

    // 计算实际返回个数
    int returnSize = aiSizeInt < aiMaxNum ? aiSizeInt : aiMaxNum;
    for (int temp = 0; temp < returnSize; temp++)
    {
        int valueCount = 0;
        char value[10][64] = {0};

        // 获取AI结果参数
        char *resultStr = strtok(valueStr[temp], "\t");
        while (resultStr) {
            strcat(value[valueCount++], resultStr);
            resultStr = strtok(NULL, "\t");
        }
        
        // 提取数值
        aiResult[temp].re_label = atoi(value[1]);
        aiResult[temp].re_prob = atof(value[2]);
        aiResult[temp].re_obj_rect_x = atof(value[3]);
        aiResult[temp].re_obj_rect_y = atof(value[4]);
        aiResult[temp].re_obj_rect_width = atof(value[5]);
        aiResult[temp].re_obj_rect_height = atof(value[6]);
    }

    return returnSize;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *AiDetectThread(void *arg)
{
    Camera_t *camNum = (Camera_t*)arg;

    // 记录AI结果
    AiResults_t aiResult[20];
    bzero(aiResult, sizeof(aiResult));

    // 获取AI识别结果
    int aiResultSize = CameraAiDetect(camNum, ai_fault_mode, aiResult, sizeof(aiResult)/sizeof(aiResult[0]));
    if (aiResultSize < 0) {
        CrLogW("camera ai detect fail\n");
        // 结束线程，释放资源
        AiDetectPastaRun = false;
        pthread_detach(pthread_self());
        return NULL;
    }

    // 显示结果
    for (int temp = 0; temp < aiResultSize; temp++) {
        CrLogI("ai result; label = %d, prob = %f, obj_rect_x = %f, obj_rect_y = %f, obj_rect_w = %f, obj_rect_h = %f",
            aiResult[temp].re_label, aiResult[temp].re_prob, aiResult[temp].re_obj_rect_x,
            aiResult[temp].re_obj_rect_y, aiResult[temp].re_obj_rect_width, aiResult[temp].re_obj_rect_height);
    }

    // 分析意面结果
    GetAiControlPrefer(&aiConfig);
    int pastaSize = 0;
    for (int i = 0; i < aiResultSize; i++)
    {
        if (aiResult[i].re_label == AI_DETECT_TYPE_PASTA && aiResult[i].re_prob * 100 >= aiConfig.pastatruth)
            pastaSize++;
    }
    CrLogI("ai detect pasta size = %d\n", pastaSize);

    // 保存意面结果图片
    if (aiConfig.datacollect && pastaSize > 0) SaveCameraAiDetectImage();

    // 是否上报AI结果
    if (AiDetectPastaNum != pastaSize && pastaSize > 0) {
        // 发送AI结果
        char msg[256] = {0};
        snprintf(msg, sizeof(msg), "ai detect pasta; num [%d]", pastaSize);

        // 判断是否暂停打印
        if (aiConfig.pauseprint)
        {
            UpdataErrorStateToManager(FAULT_AI_DETECT_PASTA_PRINT_PAUSE, msg, NULL);
            // 如果在工作状态，暂停打印
            if (GetCurrentAppstate() == APP_PRINT_STATE_WORK) {
                GcodeCmd control = GCODE_CMD__INIT;
                GET_MESSAGE_BUFF(buff);
                size_t len = gcode_cmd__pack(&control, buff);
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_PAUSE_PRINT_REQ, buff, len);
                MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
            }
        }
        else UpdataErrorStateToManager(FAULT_AI_DETECT_DISCOVER_PASTA, msg, NULL);
    }
    // AI意面消失，消除错误码
    int curFaultCode = GetPrintState().faultCode.code;
    if (curFaultCode == FAULT_AI_DETECT_DISCOVER_PASTA && pastaSize == 0)
    {
        UpdataErrorStateToManager(FAULT_CODE_IDLE, "", NULL);
    }
    AiDetectPastaNum = pastaSize;

    // 结束线程，释放资源
    AiDetectPastaRun = false;
    pthread_detach(pthread_self());
    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {Camera_t} cam
 */
static void AiDetectPasta(Camera_t camera)
{
    CrLogI("start ai pasta detect");
    aiCamera = camera;
    pthread_t aiDetectHandle;
    if (pthread_create(&aiDetectHandle, NULL, (void*)AiDetectThread, (void*)&aiCamera)) {
        CrLogE("create pthread error!\n");
        return;
    }
    AiDetectPastaRun = true;
}

/**
 * @description: 
 * @return {*}
 * @param {Camera_t} camNum
 */
int AiDetectForeignBody(Camera_t camNum)
{
    // 记录AI结果
    int res = 0;
    AiResults_t aiResult[20];
    bzero(aiResult, sizeof(aiResult));

    // 获取AI识别结果
    int aiResultSize = CameraAiDetect(&camNum, ai_foreign_objects_mode, aiResult, sizeof(aiResult)/sizeof(aiResult[0]));
    if (aiResultSize < 0) {
        CrLogW("camera ai detect fail\n");
        return res;
    }

    // 显示结果
    for (int temp = 0; temp < aiResultSize; temp++) {
        CrLogI("ai result; label = %d, prob = %f, obj_rect_x = %f, obj_rect_y = %f, obj_rect_w = %f, obj_rect_h = %f",
            aiResult[temp].re_label, aiResult[temp].re_prob, aiResult[temp].re_obj_rect_x,
            aiResult[temp].re_obj_rect_y, aiResult[temp].re_obj_rect_width, aiResult[temp].re_obj_rect_height);
    }

    // 分析异物结果
    GetAiControlPrefer(&aiConfig);
    int foreignBodySize = 0;
    for (int i = 0; i < aiResultSize; i++)
    {
        if (aiResult[i].re_label == AI_DETECT_TYPE_FOREIGN_BODY && aiResult[i].re_prob * 100 >= aiConfig.sundriestruth)
            foreignBodySize++;
    }
    CrLogI("ai detect foreign body size = %d\n", foreignBodySize);

    // 判断异物检测结果
    if (foreignBodySize > 0) {
        // 保存异物结果图片
        if (aiConfig.datacollect) SaveCameraAiDetectImage();
        res = -1;
    }
    
    return res;
}
