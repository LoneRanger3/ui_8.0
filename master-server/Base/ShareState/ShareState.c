/*
 * @Description : 共享打印机状态
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-28 12:00:56
 * @LastEditTime: 2023-10-11 17:53:06
 */
#include <string.h>
#include <pthread.h>

#include "ShareState.h"

static PrintSavePara_t printSavePara; // 打印机保存参数，多线程共享
static pthread_rwlock_t rwSaveLock; // 声明读写锁
static PrintState_t printState; // 打印机状态，多线程共享
static pthread_rwlock_t rwLock; // 声明读写锁

/**
 * @description: 初始化打印机状态
 * @param  {*}
 * @return {*}
 */
void ShareStateInit(void)
{
    memset(&printSavePara, 0, sizeof(PrintSavePara_t));
    pthread_rwlock_init(&rwSaveLock, NULL);
    memset(&printState, 0, sizeof(PrintState_t));
    pthread_rwlock_init(&rwLock, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static void MsaterSyncPrintSavePara(void)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_SYNC_PRINT_SAVE_PARA, "", 0);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_AUDIO_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
void UpdataPrintSavePara(PrintSavePara_t data)
{
    pthread_rwlock_wrlock(&rwSaveLock);
    printSavePara = data;
    pthread_rwlock_unlock(&rwSaveLock);
    MsaterSyncPrintSavePara();
}

/**
 * @description: 
 * @return {*}
 */
PrintSavePara_t GetPrintSavePara(void)
{
    pthread_rwlock_rdlock(&rwSaveLock);
    PrintSavePara_t data = printSavePara;
    pthread_rwlock_unlock(&rwSaveLock);
    return data;
}

/**
 * @description: 获取打印机状态
 * @param  {*}
 * @return {*}
 */
PrintState_t GetPrintState(void)
{
    pthread_rwlock_rdlock(&rwLock);
    PrintState_t data;
    data = printState;
    pthread_rwlock_unlock(&rwLock);
    return data;
}

/**
 * @description: 更新串口连接状态
 * @param  {*}
 * @return {*}
 * @param {int} data
 */
void UpdataSerialPort(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.serialPort = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新SD卡是否存在
 * @return {*}
 * @param undefined
 */
void UpdataSdCardExists(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.sdCardExists = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新U盘挂载状态
 * @return {*}
 * @param {int} data
 * @param {Udisk_t} num
 */
void UpdataUdiskMount(int data, Udisk_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.udiskMount[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新以太网是否连接
 * @return {*}
 * @param {int} data
 */
void UpdataEthernetExists(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.ethernetExists = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新摄像头是否连接
 * @return {*}
 * @param {int} data
 * @param {Camera_t} num
 */
void UpdataCameraOnline(int data, Camera_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.cameraOnline[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataLaserOnline(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.laserExists = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataScannerOnline(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.scannerExists = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataDeviceState(int data)
{
    // 自检状态下，不可随意修改设备状态，保证自检处于最高优先级
    if (printState.deviceState == DEVICE_STATE_SELF_TEST) {
        CrLogW("Self-testing cannot modify the device status");
        return;
    }
    pthread_rwlock_wrlock(&rwLock);
    printState.deviceState = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataDeviceStateSelfTest(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.deviceState = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新工作模式
 * @param  {*}
 * @return {*}
 * @param {int} data
 */
void UpdataPrintWorkMode(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.workMode = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新工作状态
 * @param  {*}
 * @return {*}
 * @param {int} data
 */
void UpdataPrintWorkState(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.workState = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新喷嘴当前温度
 * @return {*}
 * @param {int} data
 * @param {NozzleTemp_t} num
 */
void UpdataNozzleCurTemp(int data, NozzleTemp_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.nozzleCurTemp[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新喷嘴目标温度
 * @return {*}
 * @param {int} data
 * @param {NozzleTemp_t} num
 */
void UpdataNozzleMaxTemp(int data, NozzleTemp_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.nozzleMaxTemp[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新喷嘴加热功率
 * @return {*}
 * @param {int} data
 * @param {NozzleTemp_t} num
 */
void UpdataNozzlePower(int data, NozzleTemp_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.nozzlePower[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新喷嘴加热等待状态
 * @return {*}
 * @param {int} data
 */
void UpdataNozzleTempWait(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.nozzleTempWait = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新热床当前温度
 * @return {*}
 * @param {int} data
 * @param {HotbedTemp_t} num
 */
void UpdataBedCurTemp(int data, HotbedTemp_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.bedCurTemp[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新热床目标温度
 * @return {*}
 * @param {int} data
 * @param {HotbedTemp_t} num
 */
void UpdataBedMaxTemp(int data, HotbedTemp_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.bedMaxTemp[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新热床加热功率
 * @return {*}
 * @param {int} data
 * @param {HotbedTemp_t} num
 */
void UpdataBedPower(int data, HotbedTemp_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.bedPower[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新热床加热等待状态
 * @return {*}
 * @param {int} data
 */
void UpdataBedTempWait(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.bedTempWait = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新其他当前温度
 * @return {*}
 * @param {int} data
 * @param {OtherTemp_t} num
 */
void UpdataOtherCurTemp(int data, OtherTemp_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.otherCurTemp[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新风扇状态
 * @return {*}
 * @param {int} data
 * @param {MultiFan_t} num
 */
void UpdataPrintFanState(int data, MultiFan_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.fanState[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新风扇速度
 * @return {*}
 * @param {int} data
 * @param {MultiFan_t} num
 */
void UpdataPrintFanSpeed(int data, MultiFan_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.fanSpeed[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 * @param {MultiFan_t} num
 */
void UpdataPrintFanPercentage(int data, MultiFan_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.fanPercentage[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新电机状态
 * @param  {*}
 * @return {*}
 * @param {int} data
 */
void UpdataPrintMotorState(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.motorState = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新灯光状态
 * @param  {*}
 * @return {*}
 * @param {int} data
 */
void UpdataPrintLightState(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.lightState = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新wifi状态
 * @param  {*}
 * @return {*}
 * @param {int} data
 */
void UpdataPrintWifiState(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.wifiState = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataPrintPauseStatus(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.pauseStatus = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 * @param {MaterialDetector_t} num
 */
void UpdataPrintMaterialStatus(int data, MaterialDetector_t num)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.materialStatus[num] = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新打印倍数
 * @param  {*}
 * @return {*}
 * @param {int} data
 */
void UpdataPrintSpeed(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.printSpeed = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新打印流量
 * @return {*}
 * @param {int} data
 */
void UpdataPrintFlow(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.printFlow = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新打印实时速度
 * @return {*}
 * @param {int} data
 */
void UpdataRealTimeSpeed(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.realTimeSpeed = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新打印实时流量
 * @return {*}
 * @param {int} data
 */
void UpdataRealTimeFlow(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.realTimeFlow = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 打印使用时间
 * @return {*}
 * @param {uint32_t} data
 */
void UpdataPrintUsageTime(uint32_t data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.printUsageTime = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 打印剩余时间
 * @return {*}
 * @param {uint32_t} data
 */
void UpdataPrintRemainTime(uint32_t data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.printRemainTime = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 打印使用耗材
 * @return {*}
 * @param {uint32_t} data
 */
void UpdataFilamentUsed(uint32_t data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.filamentUsed = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 打印进度
 * @param  {*}
 * @return {*}
 * @param {int} data
 */
void UpdataPrintProgress(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.printProgress = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新打印层数
 * @return {*}
 * @param {uint32_t} data
 */
void UpdataPrintLayer(uint32_t data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.printLayer = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新打印总层数
 * @return {*}
 * @param {uint32_t} data
 */
void UpdataPrintLayers(uint32_t data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.printLayers = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: CR Touch状态
 * @param  {*}
 * @return {*}
 * @param {int} data
 */
void UpdataCrTouchState(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.crTouchState = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {FaultCode_t} data
 */
void UpdataFaultCode(FaultCode_t data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.faultCode = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataExistOffContinue(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.existOffContinue = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataLivePosition(Coordinate_t data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.livePosition = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {Coordinate_t} data
 */
void UpdataGcodePosition(Coordinate_t data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.gcodePosition = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新轴归位状态
 * @return {*}
 * @param {Coordinate_t} data
 */
void UpdataHomedAxes(Coordinate_t data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.homedAxes = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 自动调平进度
 * @param  {*}
 * @return {*}
 * @param {int} data
 */
void UpdataAutoLevelProgress(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.autoLevelProgress = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新自动PID进度
 * @param  {*}
 * @return {*}
 * @param {int} data
 */
void UpdataAutoPidProgress(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.autoPidProgress = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新klipper状态
 * @return {*}
 * @param {int} data
 */
void UpdataKlipperState(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.klipperStata = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新klipper打印状态
 * @return {*}
 * @param {int} data
 */
void UpdataKlipperPrint(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.klipperPrint = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新SD卡路径
 * @return {*}
 * @param {char} *data
 */
void UpdataSdPath(char *data)
{
    pthread_rwlock_wrlock(&rwLock);
    bzero(printState.sdPath, sizeof(printState.sdPath));
    strcat(printState.sdPath, data);
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {char} *data
 */
void UpdataUDiskPath(char *data)
{
    pthread_rwlock_wrlock(&rwLock);
    bzero(printState.uDiskPath, sizeof(printState.uDiskPath));
    strcat(printState.uDiskPath, data);
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新静音模式状态
 * @return {*}
 * @param {int} data
 */
void UpdataQmodeFlag(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.qmodeFlag = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataWithSelfTest(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.withSelfTest = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataLoadMaterial(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.loadMaterial = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataQuitMaterial(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.quitMaterial = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 更新mqtt连接状态
 * @return {*}
 * @param {int} data
 */
void UpdataCxyMqttState(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.cxyMqttState = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataLogProgress(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.logProgress = data;
    pthread_rwlock_unlock(&rwLock);
}

/**
 * @description: 
 * @return {*}
 * @param {int} data
 */
void UpdataScanFileProgress(int data)
{
    pthread_rwlock_wrlock(&rwLock);
    printState.scanFileProgress = data;
    pthread_rwlock_unlock(&rwLock);
}

/*********************************************************
 *********************************************************
 ******************** 当前打印任务信息 **********************
 *********************************************************
 *********************************************************/
static KlipperPrint_t printer = {0};

/**
 * @description: 
 * @return {*}
 */
KlipperPrint_t *GetPrinter(void) { return &printer; }

/**
 * @description: 
 * @return {*}
 */
void CleanPrinterCurrentFile(void) { bzero(&printer.current_file, sizeof(printer.current_file)); }

/**
 * @description: 
 * @return {*}
 */
int KlipperPrintAbnormalExitProcessing(void)
{
    // 释放资源
    if (printer.print_stats.state.data) free(printer.print_stats.state.data);
    if (printer.print_stats.message.data) free(printer.print_stats.message.data);
    if (printer.print_stats.filename.data) free(printer.print_stats.filename.data);
    if (printer.virtual_sdcard.file_path.data) free(printer.virtual_sdcard.file_path.data);
    if (printer.toolhead.homed_axes.data) free(printer.toolhead.homed_axes.data);
    if (printer.webhooks.state.data) free(printer.webhooks.state.data);
    if (printer.webhooks.state_message.data) free(printer.webhooks.state_message.data);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
int SyncPrintingWorkInfo(void)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_SYNC_PRINT_WORK_INFO, "", 0);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
    return 0;
}
