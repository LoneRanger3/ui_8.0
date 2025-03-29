/*
 * @Description : 间接打印模式
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-08 18:53:35
 * @LastEditTime: 2023-10-30 22:15:07
 */
#include <sys/msg.h>

#include "Base/MasterMsgBase.h"
#include "AppPrint.h"
#include "Controller.h"
#include "DefineGcode.h"
#include "PrintControl.h"
#include "AppModeSdPrint.h"
#include "AppFuncModule.h"


#define FIRST_FLOOR_DETECT_TEMP     140

/**
 * @description: 定义静态变量
 * @return {*}
 */
static PrintFileInfo_t printInfo;
static pthread_t printReadyHandle = 0;
static bool printReadyCancel = false;

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *name
 * @param {int} len
 */
void SetSdPrintInfo(PrintFileInfo_t info) { printInfo = info; }

/**
 * @description: 
 * @return {*}
 */
static CmdSyncRecv_t GetSelfCalibrationRecv(void)
{
    CmdSyncRecv_t data = {0};
    if (GetKlipperCmdSyncRecvData(&data, KLIPPER_SELF_CALIBRATION_NUM, IPC_NOWAIT) <= 0) {
        bzero(&data, sizeof(data));
    }
    return data;
}

/**
 * @description: 
 * @return {*}
 */
static int DelaySelfCalibrationGenericReply(void)
{
    while (1) {
        CmdSyncRecv_t recv = GetSelfCalibrationRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static void ClearSelfCalibrationRecvList(void)
{
    CmdSyncRecv_t data = {0};
    while (1) {
        if (GetKlipperCmdSyncRecvData(&data, KLIPPER_SELF_CALIBRATION_NUM, IPC_NOWAIT) <= 0) break;
        bzero(&data, sizeof(data));
    }
}

/**
 * @description: 
 * @return {*}
 * @param {char} *data
 */
static void SendSelfCalibrationCmd(char *data)
{
    json_object *params = json_object_new_object();
    json_object_object_add(params, "script", json_object_new_string(data));
    AddKlipperCmd("gcode/script", params, KLIPPER_SELF_CALIBRATION_NUM, MSG_ORIGIN_CONTROLLER);
}

/**
 * @description: 
 * @return {*}
 * @param {char} *data
 */
static void SendSelfCalibrationApi(char *api)
{
    json_object *params = json_object_new_object();
    AddKlipperCmd(api, params, KLIPPER_SELF_CALIBRATION_NUM, MSG_ORIGIN_CONTROLLER);
}

/**
 * @description: 
 * @return {*}
 * @param {double} detectValue
 */
static double GetFlowDetectEffectiveValue(double detectValue)
{
    double result = 0.044;
    // 获取配置
    json_object *config = json_object_from_file(GetDevicePrintParaConfig());
    if (config == NULL || !json_object_is_type(config, json_type_object)) {
        CrLogW("get flow detect effective value\n");
        if (config) json_object_put(config);
        return result;
    }

    // 获取对比配置
    json_object *flowDetectObj = json_object_object_get(config, "flow_detect");
    if (flowDetectObj != NULL || json_object_is_type(flowDetectObj, json_type_object))
    {
        // 获取当前打印材料
        char *material = GetPrinter()->current_file.material;
        CrLogI("current pritn material = %s", material);
        // 获取范围值
        json_object *materialObj = json_object_object_get(flowDetectObj, material);
        json_object *otherObj = json_object_object_get(flowDetectObj, "other");
        // 读取范围值
        if (materialObj != NULL || json_object_is_type(materialObj, json_type_object))
        {
            json_object *minObj = json_object_object_get(materialObj, "min");
            json_object *maxObj = json_object_object_get(materialObj, "max");
            json_object *optimalObj = json_object_object_get(materialObj, "optimal");

            if (minObj != NULL && json_object_is_type(minObj, json_type_double) &&
                maxObj != NULL && json_object_is_type(maxObj, json_type_double) &&
                optimalObj != NULL && json_object_is_type(optimalObj, json_type_double))
            {
                double min = json_object_get_double(minObj);
                double max = json_object_get_double(maxObj);
                double optimal = json_object_get_double(optimalObj);
                CrLogI("flow reference; min = %f, max = %f, optimal = %f", min, max, optimal);

                if (detectValue >= min && detectValue <= max) result = detectValue;
                else result = optimal;
            }
        }
        else if (otherObj != NULL || json_object_is_type(otherObj, json_type_object))
        {
            json_object *minObj = json_object_object_get(otherObj, "min");
            json_object *maxObj = json_object_object_get(otherObj, "max");
            json_object *optimalObj = json_object_object_get(otherObj, "optimal");

            if (minObj != NULL && json_object_is_type(minObj, json_type_double) &&
                maxObj != NULL && json_object_is_type(maxObj, json_type_double) &&
                optimalObj != NULL && json_object_is_type(optimalObj, json_type_double))
            {
                double min = json_object_get_double(minObj);
                double max = json_object_get_double(maxObj);
                double optimal = json_object_get_double(optimalObj);
                CrLogI("other flow reference; min = %f, max = %f, optimal = %f", min, max, optimal);

                if (detectValue >= min && detectValue <= max) result = detectValue;
                else result = optimal;
            }
        }
        else CrLogW("get material detect obj fail\n");
    }
    else CrLogW("get flow detect obj fail\n");

    // 释放内存
    json_object_put(config);
    return result;
}

/**
 * @description: 
 * @return {*}
 * @param {double} dis
 */
static int SendSafeMoveZaxes(double dis)
{
    // 发送Z轴安全移动指令
    char buf[128] = {0};
    if (dis > -0.000001 && dis < 0.000001) snprintf(buf, sizeof(buf), "SAFE_MOVE_Z STA=0");
    else snprintf(buf, sizeof(buf), "SAFE_MOVE_Z STA=1 DIS=%f SPD=3 RDO=2", dis);

    SendSelfCalibrationCmd(buf);
    do {
        CmdSyncRecv_t recv = GetSelfCalibrationRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);
    return 0;
} 

/**
 * @description: 
 * @return {*}
 * @param {double} dis
 */
static int UpdataZaxesCoordinate(double coordinate)
{
    char buf[128] = {0};
    snprintf(buf, sizeof(buf), "SET_POSITION Z=%f", coordinate);

    SendSelfCalibrationCmd(buf);
    do {
        CmdSyncRecv_t recv = GetSelfCalibrationRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {Camera_t} camNum
 */
static int AiDetectForeignBodyRun(Camera_t camNum)
{
    // 检测异物
    int detectResult = AiDetectForeignBody(camNum);
    if (detectResult != 0) return detectResult;
        
    // 获取当前Z轴高度
    double currentZaxesHight = 0;
    if (GetPrintState().homedAxes.z) currentZaxesHight = GetPrintState().gcodePosition.z / 1000.00;
    else currentZaxesHight = GetSaveFileZaxesHight();
    CrLogI("current zaxes hight = %f", currentZaxesHight);

    // 判断是否需要移动检测异物
    AiControlPrefer pre = AI_CONTROL_PREFER__INIT;
    GetAiControlPrefer(&pre);
    double moveDis = currentZaxesHight - pre.optimalheight;
    CrLogI("moveDis = %f", moveDis);

    if (currentZaxesHight > pre.optimalheight && moveDis > 1)
    {
        CrLogI("foreign object detection, camera blind spot\n");
        SendSafeMoveZaxes(0 - currentZaxesHight + pre.optimalheight);
        GetPrinter()->virtual_sdcard.run_dis = 0;
        
        // 循环检测异物
        while (1)
        {
            detectResult = AiDetectForeignBody(camNum);
            if (detectResult != 0) {
                SendSafeMoveZaxes(0);
                // 等待更新Z轴移动距离
                while (GetPrinter()->virtual_sdcard.run_dis == 0) usleep(10 * 1000);
                break;
            }
            if (GetPrinter()->virtual_sdcard.run_dis != 0) break;
        }
        
        // 更新文件保存的Z轴值
        double newZaxesHight = currentZaxesHight - GetPrinter()->virtual_sdcard.run_dis;
        SetSaveFileZaxesHight(newZaxesHight);
        // 更新Z轴坐标
        if (GetPrintState().homedAxes.x && GetPrintState().homedAxes.y && GetPrintState().homedAxes.z) {
            CrLogI("reset axis coordinates; z = %f", newZaxesHight);
            UpdataZaxesCoordinate(newZaxesHight);
        }
    }

    return detectResult;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *res
 */
static bool IsGcodeCmdExecuteFail(char *res)
{
    bool isFail = false;
    json_object *resObj = json_tokener_parse(res);
    if (resObj == NULL) {
        CrLogW("gcode cmd execute result to json fail\n");
        goto END;
    }

    json_object *errorObj = GetJsonObject(resObj, "error", json_type_object);
    if (errorObj) isFail = true;

END:
    if (resObj) json_object_put(resObj);
    return isFail;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *PrintReadyThread(void *arg)
{
    // 判断是否是fluidd启动打印
    if (printInfo.fluiddStart) {
        CrLogI("fluidd start print file = %s", printInfo.fileName);
        SetPrintPrepareState(PRINT_PREPARE_SUCCESS);
        goto END_PRINT_PREPARE;
    }

    // 切换工作状态
    SetAppStateChange(APP_PRINT_STATE_WORK);
    // 重置打印机状态，启动打印
    SendSelfCalibrationCmd("WAIT_TEMP_END");
    do {
        CmdSyncRecv_t recv = GetSelfCalibrationRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);

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
            // 通过打印材料，判断是否开启机箱风扇
            bool openCaseFan = true;
            char *material = GetPrinter()->current_file.material;
            if (strlen(material) > 0 && strcmp(material, "PLA") != 0 && strcmp(material, "TPU") != 0) openCaseFan = false;
            CrLogI("material = %s, open case fan flag = %d", material, openCaseFan);

            MultiFan multiFan = MULTI_FAN__INIT;
            multiFan.has_multi_fan_case = 1;
            // if (openCaseFan) multiFan.multi_fan_case = 100;
            // else multiFan.multi_fan_case = 0;
            // 默认打开机箱风扇
            multiFan.multi_fan_case = 100;

            GET_MESSAGE_BUFF(buff);
            size_t len = multi_fan__pack(&multiFan, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_OPEN_FAN_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
        break;
    default:
        {
            break;
        }
    }


    // 判断是否断电续打
    if (printInfo.powerLossStart) {
        CrLogI("start power loss file = %s", printInfo.fileName);
        // 构建打印指令参数, 启动打印
        char scriptBuff[512] = {0};
        snprintf(scriptBuff, 512, "SDCARD_PRINT_FILE FILENAME=\"%s\" ISCONTINUEPRINT=True", printInfo.fileName);

        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string(scriptBuff));
        AddKlipperCmd("gcode/script", params, SET_START_PRINT_FILE_NUM, MSG_ORIGIN_CONTROLLER);

        SetPrintPrepareState(PRINT_PREPARE_SUCCESS);
        goto END_PRINT_PREPARE;
    }
    else CrLogI("no power loss\n");

    // 启动打印前准备工作
    bool laserCalibrationRes = false;
    AiControlPrefer aiConfig = AI_CONTROL_PREFER__INIT;
    GetAiControlPrefer(&aiConfig);
    SetPrintPrepareState(PRINT_PREPARE_RUNING);

    // 判断是否存在摄像头
    if (GetPrintState().cameraOnline[CAMERA_MODEL] && aiConfig.sw) {
        CrLogI("start sundries detect");
        UpdataWithSelfTest(PREPARE_STEP_FOREIGN_BODY);

        // 判断是否存在异物
        if (AiDetectForeignBodyRun(CAMERA_MODEL) != 0)
        {
            CrLogW("ai detect discover foreign objects\n");
            SetPrintPrepareState(PRINT_PREPARE_FAIL);
            SetAppStateChange(APP_PRINT_STATE_PAUSE);
            UpdataErrorStateToManager(FAULT_AI_DETECT_FOREIGN_BODY_PAUSE, "ai detect discover foreign objects", NULL);

            // 打印暂停，等待用户处理
            while (1) {
                if (printReadyCancel) {
                    CrLogW("sundries detect abnormal, cancel print");
                    goto END_PRINT_PREPARE;
                }
                if (GetPrintPrepareState() == PRINT_PREPARE_RESUME_PRINT) {
                    CrLogW("sundries detect abnormal, resume print");
                    SetAppStateChange(APP_PRINT_STATE_WORK);
                    SetPrintPrepareState(PRINT_PREPARE_RUNING);
                    break;
                }
                usleep(10 * 1000);
            }
        }
    }
    else CrLogW("start sundries detect fail, cameraOnline = %d", GetPrintState().cameraOnline[CAMERA_MODEL]);

// 开始应力片校准
START_STRESS_CALIBRATION:
    // 判断是否取消打印
    if (printReadyCancel) goto END_PRINT_PREPARE;
    // 粗归零
    UpdataWithSelfTest(PREPARE_STEP_ROUGH_G28);
    CrLogI("CX_ROUGH_G28");
    char cxRoughG28Cmd[256] = {0};
    strcat(cxRoughG28Cmd, "CX_ROUGH_G28 ");
    // 修改归零温度
    if (GetPrinter()->current_file.nozzle_target_temp > 0) {
        sprintf(&cxRoughG28Cmd[strlen(cxRoughG28Cmd)], "EXTRUDER_TEMP=%f ", GetPrinter()->current_file.nozzle_target_temp);
    } 
    if (GetPrinter()->current_file.bed_target_temp > 0) {
        sprintf(&cxRoughG28Cmd[strlen(cxRoughG28Cmd)], "BED_TEMP=%f ", GetPrinter()->current_file.bed_target_temp);
    }
    CrLogI("cxRoughG28Cmd = %s", cxRoughG28Cmd);

    SendSelfCalibrationCmd(cxRoughG28Cmd);
    do {
        CmdSyncRecv_t recv = GetSelfCalibrationRecv();
        if (recv.mtype != 0)
        {
            if (IsGcodeCmdExecuteFail(recv.buf))
            {
                CrLogW("CX_ROUGH_G28 fail\n");
                SetPrintPrepareState(PRINT_PREPARE_FAIL);
                SetAppStateChange(APP_PRINT_STATE_PAUSE);
                // 打印暂停，等待用户处理
                while (1) {
                    if (printReadyCancel) {
                        CrLogW("CX_ROUGH_G28 abnormal, cancel print");
                        goto END_PRINT_PREPARE;
                    }
                    if (GetPrintPrepareState() == PRINT_PREPARE_RESUME_PRINT) {
                        CrLogW("CX_ROUGH_G28 abnormal, resume print");
                        SetAppStateChange(APP_PRINT_STATE_WORK);
                        SetPrintPrepareState(PRINT_PREPARE_RUNING);
                        goto START_STRESS_CALIBRATION;
                    }
                    usleep(10 * 1000);
                }
            }
            break;
        }
        usleep(10 * 1000);
    } while (1);

    // 判断是否取消打印
    if (printReadyCancel) goto END_PRINT_PREPARE;
    // 检测喉管风扇是否异常
    CrLogI("throat fan runing detect");
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
            if (GetFanFeedback()->exist && !GetFunctionFailure().singleTask.throatFanDetect &&
                    (GetPrintState().nozzleCurTemp[NOZZLE_TEMP] / 100) > GetheaterFanHotendFan()->heater_temp)
            {
                if (GetPrintState().fanSpeed[MULTI_FAN_THROAT] <= 0)
                {
                    CrLogW("throat fan runing abnormal\n");
                    SetPrintPrepareState(PRINT_PREPARE_FAIL);
                    SetAppStateChange(APP_PRINT_STATE_PAUSE);
                    UpdataErrorStateToManager(FAULT_THROAT_FAN_ABNORMAL_PAUSE, "throat fan runing abnormal", NULL);

                    // 打印暂停，等待用户处理
                    while (1) {
                        if (printReadyCancel) {
                            CrLogW("throat fan abnormal, cancel print");
                            goto END_PRINT_PREPARE;
                        }
                        if (GetPrintPrepareState() == PRINT_PREPARE_RESUME_PRINT) {
                            CrLogW("throat fan abnormal, resume print");
                            SetAppStateChange(APP_PRINT_STATE_WORK);
                            SetPrintPrepareState(PRINT_PREPARE_RUNING);
                            break;
                        }
                        usleep(10 * 1000);
                    }
                }
            }
        }
        break;
    default:
        {
            break;
        }
    }

    // 判断是否取消打印
    if (printReadyCancel) goto END_PRINT_PREPARE;
    // 擦嘴
    UpdataWithSelfTest(PREPARE_STEP_NOZZLE_CLEAR);
    CrLogI("CX_NOZZLE_CLEAR");
    SendSelfCalibrationCmd("CX_NOZZLE_CLEAR");
    do {
        CmdSyncRecv_t recv = GetSelfCalibrationRecv();
        if (recv.mtype != 0)
        {
            if (IsGcodeCmdExecuteFail(recv.buf))
            {
                CrLogW("CX_NOZZLE_CLEAR fail\n");
                SetPrintPrepareState(PRINT_PREPARE_FAIL);
                SetAppStateChange(APP_PRINT_STATE_PAUSE);
                // 打印暂停，等待用户处理
                while (1) {
                    if (printReadyCancel) {
                        CrLogW("CX_NOZZLE_CLEAR abnormal, cancel print");
                        goto END_PRINT_PREPARE;
                    }
                    if (GetPrintPrepareState() == PRINT_PREPARE_RESUME_PRINT) {
                        CrLogW("CX_NOZZLE_CLEAR abnormal, resume print");
                        SetAppStateChange(APP_PRINT_STATE_WORK);
                        SetPrintPrepareState(PRINT_PREPARE_RUNING);
                        goto START_STRESS_CALIBRATION;
                    }
                    usleep(10 * 1000);
                }
            }
            break;
        }
        usleep(10 * 1000);
    } while (1);

    // 判断是否取消打印
    if (printReadyCancel) goto END_PRINT_PREPARE;
    // 细归零
    CrLogI("ACCURATE_G28");
    UpdataWithSelfTest(PREPARE_STEP_ACCURATE_G28);
    SendSelfCalibrationCmd("ACCURATE_G28");
    do {
        CmdSyncRecv_t recv = GetSelfCalibrationRecv();
        if (recv.mtype != 0)
        {
            if (IsGcodeCmdExecuteFail(recv.buf))
            {
                CrLogW("ACCURATE_G28 fail\n");
                SetPrintPrepareState(PRINT_PREPARE_FAIL);
                SetAppStateChange(APP_PRINT_STATE_PAUSE);
                // 打印暂停，等待用户处理
                while (1) {
                    if (printReadyCancel) {
                        CrLogW("ACCURATE_G28 abnormal, cancel print");
                        goto END_PRINT_PREPARE;
                    }
                    if (GetPrintPrepareState() == PRINT_PREPARE_RESUME_PRINT) {
                        CrLogW("ACCURATE_G28 abnormal, resume print");
                        SetAppStateChange(APP_PRINT_STATE_WORK);
                        SetPrintPrepareState(PRINT_PREPARE_RUNING);
                        goto START_STRESS_CALIBRATION;
                    }
                    usleep(10 * 1000);
                }
            }
            break;
        }
        usleep(10 * 1000);
    } while (1);

    // 判断是否取消打印
    if (printReadyCancel) goto END_PRINT_PREPARE;
    // 判断是否启动打印前校准
    if(printInfo.withSelfTest) {
        CrLogI("start with self test");
        UpdataWithSelfTest(PREPARE_STEP_LEVEL_DELECT);
        // 调平校准
        SendSelfCalibrationCmd("CX_PRINT_LEVELING_CALIBRATION");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0)
            {
                if (IsGcodeCmdExecuteFail(recv.buf))
                {
                    CrLogW("CX_PRINT_LEVELING_CALIBRATION fail\n");
                    SetPrintPrepareState(PRINT_PREPARE_FAIL);
                    SetAppStateChange(APP_PRINT_STATE_PAUSE);
                    // 打印暂停，等待用户处理
                    while (1) {
                        if (printReadyCancel) {
                            CrLogW("CX_PRINT_LEVELING_CALIBRATION abnormal, cancel print");
                            goto END_PRINT_PREPARE;
                        }
                        if (GetPrintPrepareState() == PRINT_PREPARE_RESUME_PRINT) {
                            CrLogW("CX_PRINT_LEVELING_CALIBRATION abnormal, resume print");
                            SetAppStateChange(APP_PRINT_STATE_WORK);
                            SetPrintPrepareState(PRINT_PREPARE_RUNING);
                            goto START_STRESS_CALIBRATION;
                        }
                        usleep(10 * 1000);
                    }
                }
                break;
            }
            usleep(10 * 1000);
        } while (1);
    }
    else CrLogI("start with self test fail, switch = %d", printInfo.withSelfTest);

    // 判断是否取消打印
    if (printReadyCancel) goto END_PRINT_PREPARE;
    // 判断激光雷达是否存在
    GetAiControlPrefer(&aiConfig);
#ifdef CROSS_COMPILE
    if (printInfo.withSelfTest && (aiConfig.flowdetect || aiConfig.firstfloor))
    {
        if (!GetPrintState().laserExists) {
            CrLogW("laser no exists\n");
            UpdataErrorStateToManager(FAULT_AI_LASER_NO_EXISTS, "laser no exists", NULL);
        }
        else CrLogI("laser exists, state = %d", GetPrintState().laserExists);
    }
#endif

    // 判断是否取消打印
    if (printReadyCancel) goto END_PRINT_PREPARE;
    // 判断是否存在激光雷达，并开启流量检测或首层检测，进行激光校准
    GetAiControlPrefer(&aiConfig);
#ifdef CROSS_COMPILE
    if (printInfo.withSelfTest && GetPrintState().laserExists && (aiConfig.flowdetect || aiConfig.firstfloor))
#else
    if (printInfo.withSelfTest && (aiConfig.flowdetect || aiConfig.firstfloor))
#endif
    {
        CrLogI("start laser calibration");
        UpdataWithSelfTest(PREPARE_STEP_LASER_CALIBRATION);
        // 开启激光标定
        if (StartLaserCalibration() != 0) {
            CrLogW("laser calibration fail\n");
            UpdataErrorStateToManager(FAULT_AI_LASER_CALIBRATION_FILA, "laser calibration fail", NULL);
        }
        else laserCalibrationRes = true;
    }
    else CrLogI("start laser calibration, laserExists = %d, flowdetect = %d, firstfloor = %d",
                GetPrintState().laserExists, aiConfig.flowdetect, aiConfig.firstfloor);

    // 判断是否取消打印
    if (printReadyCancel) goto END_PRINT_PREPARE;
    // 判断是否存在激光雷达，并开启流量检测
    GetAiControlPrefer(&aiConfig);
    char best_line[64]={0};
#ifdef CROSS_COMPILE
    if (GetPrintState().laserExists && laserCalibrationRes && aiConfig.flowdetect)
#else
    if (laserCalibrationRes && aiConfig.flowdetect)
#endif
    {
        CrLogI("start flow detect");
        // 开启流量检测
        if (StartAiFlowDetect(true, best_line) != 0) {
            CrLogW("ai flow detect fail\n");
            UpdataErrorStateToManager(FAULT_AI_FLOW_EXCEPTION_FAIL, "ai flow detect fail", NULL);
        }
    }
    else CrLogI("start flow detect fail, laserExists = %d, flowdetect = %d", GetPrintState().laserExists, aiConfig.flowdetect);

    // AI检测结果
    CrLogI("best_line = %s\n", best_line);
    double flowValue = atof(best_line);

    // 判断识别结果是否有效
    flowValue = GetFlowDetectEffectiveValue(flowValue);
    char resuleStr[10] = {0};
    snprintf(resuleStr, sizeof(resuleStr), "%0.3f", flowValue);
    CrLogI("flow detect effective value = %s", resuleStr);

    // 设置AI检测最优压力补偿值
    GcodeCmd max = GCODE_CMD__INIT;
    max.has_cmdstr = 1;
    max.cmdstr.data = (uint8_t*)resuleStr;
    max.cmdstr.len = strlen(resuleStr);

    GET_MESSAGE_BUFF(buff1);
    size_t len1 = gcode_cmd__pack(&max, buff1);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_PRESSURE_ADVANCE_REQ, buff1, len1);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send1, size1);

    // 设置平滑时间
    GcodeCmd time = GCODE_CMD__INIT;
    time.has_cmdstr = 1;
    time.cmdstr.data = (uint8_t*)"0.04";
    time.cmdstr.len = strlen((char*)time.cmdstr.data);

    GET_MESSAGE_BUFF(buff2);
    size_t len2 = gcode_cmd__pack(&time, buff2);
    CREATE_MESSAGE_PACKAGE(send2, size2, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_SMOOTH_TIME_REQ, buff2, len2);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send2, size2);

    // 判断是否取消打印
    if (printReadyCancel) goto END_PRINT_PREPARE;
    // 构建打印指令参数
    char scriptBuff[300] = {0};
    snprintf(scriptBuff, 300, "SDCARD_PRINT_FILE FILENAME=\"%s\"", printInfo.fileName);

    // 判断是否开启首层检测，扫描床板
    GetAiControlPrefer(&aiConfig);
#ifdef CROSS_COMPILE
    if (GetPrintState().laserExists && laserCalibrationRes && aiConfig.firstfloor)
#else
    if (laserCalibrationRes && aiConfig.firstfloor)
#endif
    {
        // 获取gcode还原点云数据
        CrLogI("first floor detect, scan table");
        UpdataWithSelfTest(PREPARE_STEP_FLOOR_SCAN_TABLE);
        
        // 计算点云还原间隔
        float segmentLen = 5.0;
        double area = GetPrinter()->current_file.object_light * GetPrinter()->current_file.object_weight;
        if (area > (200 * 200)) segmentLen = 5.0;
        else if (area > (150 * 150)) segmentLen = 2.0;
        else if (area > (100 * 100)) segmentLen = 2.0;
        else if (area > (1 * 1)) segmentLen = 1.0;
        // float segmentLen = 1.0;

        // 还原点云
        GetGcodePointCloudFromFile(GetPrinter()->current_file.fileName, segmentLen);
        // 判断点云是否还原成功
        if (IsPointCloudRestored()) {
            CrLogI("gcode restored point cloud finish\n");
            StartLaserScanningTable();
            strcat(scriptBuff, " FIRST_FLOOR_PRINT=True");
            UpdataWithSelfTest(PREPARE_STEP_FLOOR_PRINT_LINE);
        }
        else CrLogW("gcode restored point cloud fail\n");
    }

    // 判断是否取消打印
    if (printReadyCancel) goto END_PRINT_PREPARE;
    // 设置非moonraker
    CrLogI("PRINT_PREPARED");
    SendSelfCalibrationCmd("PRINT_PREPARED");
    do {
        CmdSyncRecv_t recv = GetSelfCalibrationRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);
    // 启动打印
    json_object *params = json_object_new_object();
    json_object_object_add(params, "script", json_object_new_string(scriptBuff));
    AddKlipperCmd("gcode/script", params, SET_START_PRINT_FILE_NUM, MSG_ORIGIN_CONTROLLER);

    // 判断是否开启首层检测，等待首层打印完成
    GetAiControlPrefer(&aiConfig);
#ifdef CROSS_COMPILE
    if (GetPrintState().laserExists && laserCalibrationRes && aiConfig.firstfloor && IsPointCloudRestored())
#else
    if (laserCalibrationRes && aiConfig.firstfloor && IsPointCloudRestored())
#endif
    {
        CrLogI("wait first floor print finish\n");
        do {
            // 判断是否打印完首层
            if (GetCurrentAppstate() == APP_PRINT_STATE_PAUSE &&
                GetPrinter()->virtual_sdcard.first_layer_stop) break;
            // 打印任务中断，结束打印准备线程
            if (GetCurrentAppstate() == APP_PRINT_STATE_IDLE || GetCurrentAppstate() == APP_PRINT_STATE_FINISH ||
                GetCurrentAppstate() == APP_PRINT_STATE_FAIL || GetCurrentAppstate() == APP_PRINT_STATE_STOP)
            {
                goto END_PRINT_PREPARE;
            }
            // 判断是否取消打印
            if (printReadyCancel) goto END_PRINT_PREPARE;
            usleep(1000 * 10);
        } while (1);
        SetAppStateChange(APP_PRINT_STATE_LAYER_PAUSE);

        // 保存当前打印状态
        int nozzleTargetTemp[NOZZLE_TEMP_SIZE] = {0}; // 喷嘴目标温度
        int fanState[MULTI_FAN_SIZE] = {0}; // 风扇状态
        
        for (int i = 0; i < NOZZLE_TEMP_SIZE; i++) {
            nozzleTargetTemp[i] = GetPrintState().nozzleMaxTemp[i];
            CrLogI("nozzleTargetTemp[%d] = %d", i, nozzleTargetTemp[i]);
        }
        for (int i = 0; i <= MULTI_FAN_AUXILIARY; i++) {
            fanState[i] = GetPrintState().fanState[i];
            CrLogI("fanState[%d] = %d", i, fanState[i]);
        }
        CrLogI("Save parameters complete\n");
        
        // 打开风扇快速降温
        UpdataWithSelfTest(PREPARE_STEP_FLOOR_COOL_DOWN);
        SendSelfCalibrationCmd("M106 P0 S255");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);

        SendSelfCalibrationCmd("M106 P2 S255");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);

        // 喷嘴移动到暂停位置，降温
        SendSelfCalibrationCmd("FIRST_FLOOR_PAUSE_POSITION");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);

        // 等待温度
        sleep(1);
        while (1) {
            if (GetPrintState().nozzleCurTemp[NOZZLE_TEMP]/100 > (GetPrintState().nozzleMaxTemp[NOZZLE_TEMP]/100 - 5) &&
                GetPrintState().nozzleCurTemp[NOZZLE_TEMP]/100 < (GetPrintState().nozzleMaxTemp[NOZZLE_TEMP]/100 + 5)
            ) break;
            usleep(10 * 1000);
        }

        // 关闭风扇
        SendSelfCalibrationCmd("M106 P0 S0");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);

        SendSelfCalibrationCmd("M106 P2 S0");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);

        // 开始首层检测
        CrLogI("first floor detect, scan first floor");
        int res = StartFirstLayerDetect(true);
        char *msg = "first layer print exception";

        // 喷嘴移动到暂停位置
        SendSelfCalibrationCmd("FIRST_FLOOR_PAUSE_POSITION");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);

        // 处理结果
        GetAiControlPrefer(&aiConfig);
        if (res != 0 && aiConfig.pauseprint) {
            CrLogI("first layer detect fail\n");
            SetPrintPrepareState(PRINT_PREPARE_FAIL);
            UpdataErrorStateToManager(FAULT_FIRST_LAYER_EXCEPTION_PAUSE, msg, NULL);
            SetAppStateChange(APP_PRINT_STATE_PAUSE);

            // 打印暂停，等待用户处理
            while (1) {
                if (printReadyCancel) {
                    CrLogW("first layer detect abnormal, cancel print");
                    goto END_PRINT_PREPARE;
                }
                if (GetPrintPrepareState() == PRINT_PREPARE_RESUME_PRINT) {
                    CrLogW("first layer detect abnormal, resume print");
                    SetPrintPrepareState(PRINT_PREPARE_RUNING);
                    SetAppStateChange(APP_PRINT_STATE_LAYER_PAUSE);
                    break;
                }
                usleep(10 * 1000);
            }
        }
        else {
            if (res != 0) {
                CrLogI("first layer detect fail\n");
                UpdataErrorStateToManager(FAULT_FIRST_LAYER_EXCEPTION, msg, NULL);
            }
            else CrLogI("first layer detect success\n");
        }

        UpdataWithSelfTest(PREPARE_STEP_FLOOR_HEAT_UP);
        // 恢复风扇转速
        char gcode[256] = {0};
        for (int i = 0; i <= MULTI_FAN_AUXILIARY; i++) {
            bzero(gcode, sizeof(gcode));
            snprintf(gcode, sizeof(gcode), "%s P%d S%d", SET_CONTROL_OPEN_FAN, i, fanState[i]);
            SendSelfCalibrationCmd(gcode);
            do {
                CmdSyncRecv_t recv = GetSelfCalibrationRecv();
                if (recv.mtype != 0) break;
                usleep(10 * 1000);
            } while (1);
        }

        // 喷嘴温度恢复
        bzero(gcode, sizeof(gcode));
        snprintf(gcode, sizeof(gcode), "%s S%d", SET_NOZZLE_TARGET_TEMP, (int)(nozzleTargetTemp[NOZZLE_TEMP]/100.0 + 0.5));
        SendSelfCalibrationCmd(gcode);
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
        // 等待温度
        while (1) {
            if (GetPrintState().nozzleCurTemp[NOZZLE_TEMP]/100 > (nozzleTargetTemp[NOZZLE_TEMP]/100 - 5) &&
                GetPrintState().nozzleCurTemp[NOZZLE_TEMP]/100 < (nozzleTargetTemp[NOZZLE_TEMP]/100 + 5)
            ) break;
            usleep(10 * 1000);
        }
        SendSelfCalibrationCmd("G1 Z2.0 F600\nM400");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
        SendSelfCalibrationCmd("G1 Z.2 F600\nM400");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
        SendSelfCalibrationCmd("G91");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);

        SendSelfCalibrationCmd("G1 E-.56 F2400");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
      
        SendSelfCalibrationCmd("G1 F4000");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
        SendSelfCalibrationCmd("G1 E-.06416 \n \
                                G1 E-.05233\n \
                                G1 E-.03433\n \
                                G1 E-.037\n \
                                G1 E-.04019\n \
                                G1 E-.012 F2400");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
       
        SendSelfCalibrationCmd("G90");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
        SendSelfCalibrationCmd("G1 Z2.0 F600\nM400");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
    
        // 首层检测继续，清除检测状态
        if (GetPrinter()->virtual_sdcard.first_layer_stop) {
            json_object *params1 = json_object_new_object();
            AddKlipperCmd("pause_resume/set_print_first_layer", params1, SET_PRINT_FIRST_LAYER_NUM, MSG_ORIGIN_CONTROLLER);
        }
        // 继续打印
        SendSelfCalibrationCmd("FIRST_FLOOR_RESUME");
        do {
            CmdSyncRecv_t recv = GetSelfCalibrationRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
    }
    CrLogI("Prepare before finishing printing\n");
    SetPrintPrepareState(PRINT_PREPARE_SUCCESS);

END_PRINT_PREPARE:
    // 打印前校准完成
    UpdataWithSelfTest(PREPARE_STEP_FINISH);
    CrLogI("print ready end\n");
    return NULL;
}

/**
 * @description: 进入
 * @param  {*}
 * @return {*}
 */
void EnterAppSdPrint(void)
{
    CrLogI("enter app mode sd print");
    CrLogI("prin file name = %s", printInfo.fileName);
    CrLogI("with self test = %d\n", printInfo.withSelfTest);
    CrLogI("power loss start = %d\n", printInfo.powerLossStart);
    CrLogI("fluidd start = %d\n", printInfo.fluiddStart);

    // 重置打印准备状态
    ClearSelfCalibrationRecvList();
    SetPrintPrepareState(PRINT_PREPARE_NULL);
    UpdataWithSelfTest(PREPARE_STEP_NULL);

    // 创建打印准备线程
    printReadyCancel = false;
    if (pthread_create(&printReadyHandle, NULL, (void*)PrintReadyThread, NULL)) {
        CrLogE("create pthread error!\n");
    }
}

/**
 * @description: 运行
 * @param  {*}
 * @return {*}
 */
void ExecuteAppSdPrint(void)
{
    AppSendPrintState();
    AutoGetGetPrinterStatus();
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *StopReadyThread(void *arg)
{
    CrLogI("stop ready start");
    // 停止独立模块
    // CancelFuncModule();
    
    // 取消打印校准
    printReadyCancel = true;
    do {
        if (GetPrintState().withSelfTest == PREPARE_STEP_FINISH) break;
        usleep(10 * 1000);
    } while (1);
    CrLogI("stop ready end");

    // 清空发送，防止gcode无回复，通信卡住无法停止
    CleanCurrentSendCmd();
    // ClearSendGcodeList();
    ClearKlipperSendGcodeList();

    // 判断klipper是否启动
    CrLogI("klipper print = %d", GetPrintState().klipperPrint);
    if (GetPrintState().klipperPrint == KLIPPER_PRINT_PAUSED ||
        GetPrintState().klipperPrint == KLIPPER_PRINT_PRINTING)
    {
        // 取消打印
        SendSelfCalibrationApi("pause_resume/cancel");
        DelaySelfCalibrationGenericReply();
        // 中断加热
        SendSelfCalibrationApi("breakheater");
        DelaySelfCalibrationGenericReply();
    }
    else {
        // 停止加热
        SendSelfCalibrationCmd("TURN_OFF_HEATERS");
        DelaySelfCalibrationGenericReply();
        // 喷嘴归位
        SendSelfCalibrationCmd("END_PRINT\nM400");
        DelaySelfCalibrationGenericReply();
        // 停止操作; 切换状态机
        SetAppStateChange(APP_PRINT_STATE_STOP);
        SetAppModeChange(APP_MODE_IDLE);
    }

    CrLogI("user stop print finish\n");
    return NULL;
}

/**
 * @description: 
 * @return {*}
 */
void UserControlStopReady(void)
{
    // 创建打印结束线程
    pthread_t stopHandle = 0;
    if (pthread_create(&stopHandle, NULL, (void*)StopReadyThread, NULL)) {
        CrLogE("create pthread error!\n");
    }
    pthread_detach(stopHandle);
}

/**
 * @description: 退出
 * @param  {*}
 * @return {*}
 */
void ExitAppSdPrint(void)
{
    CrLogI("exit app mode sd print\n");

    // 等待打印准备线程结束
    usleep(10 * 1000);
    // 结束打印准备线程
    pthread_cancel(printReadyHandle);
    pthread_join(printReadyHandle, NULL);

    // 判断是否打印前校准异常，取消打印，不保存任务记录
    if (GetPrintPrepareState() != PRINT_PREPARE_SUCCESS) {
        SetPrintPrepareState(PRINT_PREPARE_NULL);
        return;
    }
    // 保存打印时间到配置文件
    CumulativePrintingTime();
    // 上传流逝影像
    UploadDelayImage();
    //上报打印记录
    UploadPrintHistoryRecord(true);
}