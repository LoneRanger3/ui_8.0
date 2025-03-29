/*
 * @Description : 通信管理
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:09
 * @LastEditTime: 2023-11-02 16:39:10
 */

#include <sys/msg.h>
#include <sys/types.h>
#include <sys/time.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <regex.h>
#include <time.h>
#include <inotifytools/inotifytools.h>
#include <inotifytools/inotify.h>

#include "Base/DisplayMsgBase.h"
#include "custom/commu_thread.h"
#include "ServerMessage.h"
#include "k1_horizontal_ui/ui_Screen_Widgets.h"

#define SERIAL_PORT_MAX_DATA_FRAME_LEN      2048 // 从缓存文件一次读取的最大长度
#define WAIT_SYSTEM_CONFIG_TIME             500 // 10ms周期，最长等待时间是5秒
#define STARTUP_FULL_SCREEN_TIME            (30 * 100) // 10ms周期，30秒后开启全屏
#define ONE_MINUTE_COUNT_TIME               (60 * 100) // 10ms周期，一分钟时长

/**
 * @description: 静态变量声明
 * @param  {*}
 * @return {*}
 */
static bool UiInitFinishFlag = false; // UI未初始化完成，向UI推送数据可能会使界面死机
static int managerMsgId = -1;
static int serverMsgId = -1;
static sem_shm_t printObjectShm = {0};
static SystemConfig_t systemComfig = {0}; // 系统配置文件
static SystemConfig_t lastSystemComfig = {0}; // 系统前一次配置文件
static PrintSavePara_t printSavePara = {0}; // 打印机保存参数
static PrintSavePara_t lastPrintSavePara = {0}; // 打印机前一次保存参数
static PrintState_t printRunState = {0}; // 打印机运行状态
static PrintState_t lastPrintRunState = {0}; // 打印机前一次运行状态
static char currentTraversePath[300] = {0}; // 记录当前请求目录路径
static FirmwareInfo_t linuxOTA = {0}; // linux OTA升级
static FirmwareInfo_t linuxLocal = {0}; // linux 本地升级
static FirmwareInfo_t mcuOTA = {0}; // mcu OTA升级
static FirmwareInfo_t mcuLocal = {0}; // mcu 本地升级
static PrintWorkInfo_t currentWorkInfo = {0}; // 同步当前打印任务信息
static int startupFullScreenCount = 0; // 启动全屏计数
static int startupScreenSaverCount = 0; // 启动息屏计数
static pthread_mutex_t uiThreadLock; // UI多线程锁，防止更新控件数据与UI刷新页面同时进行
static char logOutputPath[256] = {0}; // 日志导出路径
static bool logOutputRuning = false; // 日志导出中
static bool udisFileInfoMonitor = false; // U盘文件信息监听
static bool firstBootConnectKlipper = true; // 首次开机连接klipper标志
static bool uiStartUploadLog = false; // UI启动上传日志

static int curSelectFileCount = 0; // UI选中文件个数
static int selectFileCollectionNum = 0; // UI选中文件个数
static char selectFileCollection[100][256] = {0}; // UI选中文件集合
static char *copyFileTargetPath = NULL; // UI选中文件个数

// 暂存LVGL设置指令，设置操作成功之后，将指令再回传给LVGL
static int saveDisSetFlag = 0;
static int saveDisSetDataLen = 0;
static char saveDisSetData[200] = {0};

/**
 * @description: 声明静态函数
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurWorkStateToDis(MsgHeadBuf_t *head);
static void DevSendCurFaultCodeToDis(MsgHeadBuf_t *head);
static void DevSendCurSerialPortStateToDis(MsgHeadBuf_t *head);
static void DevSendCurMqttConnectStateToDis(MsgHeadBuf_t *head);
static void SetUdisFileInfokMonitor(void);

/**
 * @description: 
 * @return {*}
 */
void ui_pthread_mutex_lock(void) { pthread_mutex_lock(&uiThreadLock); }

/**
 * @description: 
 * @return {*}
 */
void ui_pthread_mutex_unlock(void) { pthread_mutex_unlock(&uiThreadLock); }

/**
 * @description: 
 * @return {*}
 */
void TurnOffBootAnimation(void)
{
    if (access("/tmp/load_done", F_OK) != 0) {
        CrLogI("turn off boot animation\n");
        system("touch /tmp/load_done");
    }
}

/**
 * @description: 
 * @return {*}
 */
SystemConfig_t GetSystemComfig(void) { return systemComfig; }
PrintSavePara_t GetPrintSavePara(void) { return printSavePara; }
PrintState_t GetPrintRunState(void) { return printRunState; }

/**
 * @description: 
 * @return {*}
 */
static int GetNnknownError(void)
{
    int error = -1;

    // 获取错误码配置文件
    json_object *configObj = json_object_from_file(GetDefaultErrorCodeMapPtah());
    if (!configObj || !json_object_is_type(configObj, json_type_object)) {
        CrLogW("get config obj fail\n");
        goto ERROR_END;
    }

    // 获取未知错误码error
    json_object *unknownObj = json_object_object_get(configObj, "unknown_error");
    if (!unknownObj || !json_object_is_type(unknownObj, json_type_int)) {
        CrLogW("get unknown error obj fail\n");
        goto ERROR_END;
    }
    error = json_object_get_int(unknownObj);

ERROR_END:
    json_object_put(configObj);
    return error;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *key
 * @param {char} *result
 */
static int GetKlipperConfigFileInfo(char *key, char *result)
{
    int res = -1;
    const char *configPath = GetUserPrinterConfigFilePath();

    // 判断文件是否存在
    if (access(configPath, F_OK) == 0)
    {
        // 打开文件
        FILE *fd = fopen(configPath, "r");
        if (fd == NULL) {
            CrLogE("open %s error", configPath);
            return res;
        }
        
        // 读取配置文件
        bool startRead = false;
        char readBuff[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
        while (fgets(readBuff, SERIAL_PORT_MAX_DATA_FRAME_LEN, fd) != NULL)
        {
            // 获取key值，开始读取
            if (!startRead && strstr(readBuff, key)) {
                startRead = true;
                strcat(result, readBuff);
                bzero(readBuff, SERIAL_PORT_MAX_DATA_FRAME_LEN);
                continue;
            }
            // 判断是否读取结束
            if (startRead && strstr(readBuff, "[")) break;
            // 持续读取文件
            if (startRead) strcat(result, readBuff);
            
            bzero(readBuff, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        }

        // 关闭文件
        if (startRead) res = 0;
        fclose(fd);
    }
    
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *path
 * @param {int} id
 * @param {int} *line
 */
static json_object *GetFileInfoToIdFromCache(char *path, int id, int *line)
{
    CrLogI("get file info; cache path = %s, id = %d\n", path, id);
    FILE *cacheFd = fopen(path, "r");
    if (cacheFd == NULL)
    {
        CrLogE("open %s error", path);
        return NULL;
    }
    
    // 获取指定文件信息
    json_object *getInfo = NULL;
    int lineCount = 0;
    char readBuff[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
    // 遍历文件信息缓存
    while (fgets(readBuff, SERIAL_PORT_MAX_DATA_FRAME_LEN, cacheFd) != NULL)
    {
        lineCount++;
        // 转换成json格式
        json_object* infoObj = json_tokener_parse(readBuff);
        if (infoObj == NULL || !json_object_is_type(infoObj, json_type_object))
        {
            if (infoObj) json_object_put(infoObj);
            memset(readBuff, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            continue;
        }
        // 获取文件ID
        json_object *idObj = json_object_object_get(infoObj, "fileId");
        if (idObj == NULL || !json_object_is_type(idObj, json_type_int))
        {
            json_object_put(infoObj);
            memset(readBuff, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            continue;
        }
        // 获取指定文件ID的信息
        if (json_object_get_int(idObj) == id)
        {
            getInfo = infoObj;
            memset(readBuff, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            break;
        }

        json_object_put(infoObj);
        memset(readBuff, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
    }

    fclose(cacheFd);
    *line = lineCount;
    return getInfo;
}

/**
 * @description: 
 * @return {*}
 */
static void DisInitiativeGetPowerLossInfo(void)
{
    // 同步打印机保存参数
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_POWER_LOSS_RES, "", 0);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 */
static void DisInitiativeGetUpgradeInfo(void)
{
    // 开机检测升级信息，判断是否升级重启
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_UPGRADE_REBOOT_RES, "", 0);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: UI初始化完成
 * @return {*}
 */
void SyncUiInitFinish(void)
{
    UiInitFinishFlag = true;
    DisInitiativeGetPowerLossInfo();
    DevSendCurWorkStateToDis(NULL);
    DevSendCurFaultCodeToDis(NULL);
    DevSendCurSerialPortStateToDis(NULL);
    DevSendCurMqttConnectStateToDis(NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHead} *head
 */
static void UserSetCmdResponse(unsigned char flag, unsigned int len, char *data)
{
    CrLogI("SetPrinter response flag = %d, len = %d", flag, len);
    CrLogI("SetPrinter response data = %s\n", data);
    set_response_printer_data(flag, len, data);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetCmdResponse(unsigned char flag, unsigned int len, char *data)
{
    CrLogI("GetPrinter response flag = %d, len = %d", flag, len);
    CrLogI("GetPrinter response data = %s\n", data);
    get_response_printer_data(flag, len, data);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurAutoPowerOffSwToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "4%d", systemComfig.auto_power_off);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurScreenBrightnessToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "e%d", systemComfig.screen_value);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurFullScreenToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "j%d", systemComfig.full_screen);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurScreensacerSwToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "b%d", systemComfig.screensaver);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurSoundSizeToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "h%d", systemComfig.sound_size);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurSoundSwToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "a%d", systemComfig.sound_sw);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurSoundFfectToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "i%d", systemComfig.sounde_ffect);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurSelfTestSwToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "9%d", systemComfig.self_test_sw);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurDisplayThemeToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "c%d", systemComfig.theme_mode);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurWifiStateToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "2%d", systemComfig.wifi_sw);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurLightStateToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "1%d", systemComfig.light_sw);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurLightValueToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "k%d", systemComfig.light_value);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurLanguageToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%d", systemComfig.language);
    UserGetCmdResponse(UI_GET_CURRENT_LANGUAGE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurHotBedSizeToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%d\t%d\t%d", systemComfig.bed_length, systemComfig.bed_width, systemComfig.bed_hight);
    UserGetCmdResponse(UI_GET_HOT_BED_SIZE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendDeviceAllInfoToDis(MsgHeadBuf_t *head)
{
    char devMacStr[32] = {0};
    snprintf(devMacStr, 32, "%c%c:%c%c:%c%c:%c%c:%c%c:%c%c",
            systemComfig.device_mac[0], systemComfig.device_mac[1],
            systemComfig.device_mac[2], systemComfig.device_mac[3],
            systemComfig.device_mac[4], systemComfig.device_mac[5],
            systemComfig.device_mac[6], systemComfig.device_mac[7],
            systemComfig.device_mac[8], systemComfig.device_mac[9],
            systemComfig.device_mac[10], systemComfig.device_mac[11]);

    // 因产品变更，导致既定机型不可直接显示，做强制装换
    char tempModelStr[256] = {0};
    if (strcmp(systemComfig.model_str, "CR-K1") == 0) strcat(tempModelStr, "K1");
    else if (strcmp(systemComfig.model_str, "CR-K1 Max") == 0) strcat(tempModelStr, "K1 Max");
    else strcat(tempModelStr, systemComfig.model_str);

    // 计算磁盘空间
    double sysTotalSize = GetSystemMemorySize(systemComfig.model).total_size;
    double userAvailableSize = GetDiskAvailableSize(GetUserDataPath()) / (1024 * 1024);
    double userUsedSize = sysTotalSize - userAvailableSize;

    char paraBuff[1000] = {0};
    snprintf(paraBuff, 1000, "%s\t%s\t%s\t%s\t%d\t%s\t%s\t%f\t%f\t%s",
    tempModelStr,
    systemComfig.hw_version,
    systemComfig.fw_version,
    systemComfig.sys_version,
    systemComfig.total_time,
    devMacStr,
    systemComfig.website,
    sysTotalSize,
    userUsedSize,
    systemComfig.host_name);
    UserGetCmdResponse(UI_GET_DEVICE_ALL_INFO, strlen(paraBuff) + 1, paraBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendDeviceTimezoneToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "m%s", systemComfig.time_zone);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendServerConfigToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "n%d", systemComfig.server_config);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendUpgradeRemindToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "o%d", systemComfig.upgrade_remind);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendServerLocalToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "p%d", systemComfig.server_local);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendAgreePrivacyToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "q%d", systemComfig.agree_privacy);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendDataCollectToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "s%d", systemComfig.data_collect);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendBindingQrcodeToDis(MsgHeadBuf_t *head)
{
    char sendBuff[300] = {0};
    // 判断二维码是否存在
    if (access(GetCxyDeviceBindingQrCodePtah(), F_OK) == 0) {
        CrLogI("device binding qrcode exist");
        snprintf(sendBuff, 300, "1%s", GetCxyDeviceBindingQrCodePtah());
    }
    else {
        snprintf(sendBuff, 300, "1");
    }

    CrLogI("binding qrcode path = %s", sendBuff);
    UserGetCmdResponse(UI_GET_CXY_BINDING_QRCODE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendUserServiceQrcodeToDis(MsgHeadBuf_t *head)
{
    char sendBuff[300] = {0};
    // 判断二维码是否存在
    if (access(GetCxyUserServiceQrCodePtah(), F_OK) == 0) {
        CrLogI("user service qrcode exist");
        snprintf(sendBuff, 300, "2%s", GetCxyUserServiceQrCodePtah());
    }
    else {
        snprintf(sendBuff, 300, "2");
    }

    CrLogI("User Service qrcode path = %s", sendBuff);
    UserGetCmdResponse(UI_GET_CXY_BINDING_QRCODE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 */
SystemConfig_t GetSystemConfig(void) { return systemComfig; }

/**
 * @description: 
 * @return {*}
 */
int DelayGetSystemConfig(void)
{
    int delayCount = 0;
    while ((systemComfig.model == 0) && (++delayCount <= WAIT_SYSTEM_CONFIG_TIME)) {
        usleep(1000 * 10);
    }
    
    if (delayCount > WAIT_SYSTEM_CONFIG_TIME) {
        // 无法从系统获取机器型号，主动退出，结束进程
        CrLogE("get device model fail !!\n");
        CrLogE("EXIT:!!!\n\n");
        exit(1);
    } 
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurPowerLossSwToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "8%d", printSavePara.powerLoss);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurAxisOffsetToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%.2f\t%.2f\t%.2f",
        printSavePara.homeOffset.x/100.00, printSavePara.homeOffset.y/100.00, printSavePara.homeOffset.z/100.00);
    UserGetCmdResponse(UI_GET_ORGIN_OFFSET_DATA, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurAutoLevelValueToDis(MsgHeadBuf_t *head)
{
    // char sendBuff[1024] = {0};
    // strcat(sendBuff, "7");
    // for (int i = 0; i < printSavePara.levelValue.size; i++)
    // {
    //     char temp[10] = {0};
    //     snprintf(temp, 10, "%.2f\t", printSavePara.levelValue.value[i]/10000.00);
    //     strcat(sendBuff, temp);
    // }

    char sendBuff[1024] = {0};
    strcat(sendBuff, "7");

    // 获取调平值
    char result[2048] = {0};
    GetKlipperConfigFileInfo("[bed_mesh default]", result);
    CrLogI("result = \n%s", result);

    char *regex = "[-|+]?[0-9]{1,2}.[0-9]{4,6}";
    regmatch_t regmatch[50];
    int regexSize = UserGetRegexStr(result, regex, regmatch, sizeof(regmatch)/sizeof(regmatch_t));

    double temp[regexSize];
    bzero(temp, sizeof(temp));
    for(int i = 0; i< regexSize; i++)
    {
        int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
        char str[cnt + 1];
        bzero(str, sizeof(str));
        memcpy(str, &result[regmatch[i].rm_so], cnt);
        temp[i] = atof(str);
        snprintf(&sendBuff[strlen(sendBuff)], 10, "%.2f\t", temp[i]);
    }
    sendBuff[strlen(sendBuff) - 1] = '\0';
    UserGetCmdResponse(UI_GET_AUTO_LEVELING_DATA, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurAxisRecoupToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%.2f", printSavePara.axisRecoup.z/1000.000);
    UserGetCmdResponse(UI_GET_DEV_AXIS_RECOUP_DATA, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} num
 */
static void DevSendCurSportsParaToDis(int num)
{
    char sendBuff[100] = {0};
    switch(num) {
        case 1: snprintf(sendBuff, 100, "1%.2f\t%.2f\t%.2f\t%.2f", printSavePara.stepValue.x/100.00, printSavePara.stepValue.y/100.00, printSavePara.stepValue.z/100.00, printSavePara.stepValue.e/100.00); break;
        case 2: snprintf(sendBuff, 100, "2%d\t%d\t%d\t%d", printSavePara.Acceleration.x, printSavePara.Acceleration.y, printSavePara.Acceleration.z, printSavePara.Acceleration.e); break;
        case 3: snprintf(sendBuff, 100, "3%.2f\t%.2f\t%.2f\t%.2f", printSavePara.Jerk.x/100.00, printSavePara.Jerk.y/100.00, printSavePara.Jerk.z/100.00, printSavePara.Jerk.e/100.00); break;
        case 4: snprintf(sendBuff, 100, "4%d\t%d\t%d\t%d", printSavePara.Speed.x, printSavePara.Speed.y, printSavePara.Speed.z, printSavePara.Speed.e); break;
    }
    UserGetCmdResponse(UI_GET_DEV_SPORTS_PARAMETER, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} num
 */
static void DevSendCurTempPidToDis(MsgHeadBuf_t *head)
{
    char sendBuff[256] = {0};
    snprintf(sendBuff, 256, "%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f",
        printSavePara.hotendPid.p/100.00, printSavePara.hotendPid.i/100.00, printSavePara.hotendPid.d/100.00,
        printSavePara.bedPid.p/100.00, printSavePara.bedPid.i/100.00, printSavePara.bedPid.d/100.00);
    UserGetCmdResponse(UI_GET_TEMP_PID_PARA, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurAutoLevelPointsToDis(MsgHeadBuf_t *head)
{
    switch (printSavePara.levelPoints.x)
    {
        case 3: UserGetCmdResponse(UI_GET_AUTO_LEVELING_DATA, 3, "40"); break;
        case 4: UserGetCmdResponse(UI_GET_AUTO_LEVELING_DATA, 3, "41"); break;
        case 5: UserGetCmdResponse(UI_GET_AUTO_LEVELING_DATA, 3, "42"); break;
        default: UserGetCmdResponse(UI_GET_AUTO_LEVELING_DATA, 3, "40"); break;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurExistFanFeedbackToDis(MsgHeadBuf_t *head)
{
    char sendBuff[256] = {0};
    snprintf(sendBuff, 256, "9%d", printSavePara.fanFeedback);
    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurWorkStateToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    switch (printRunState.workState)
    {
        case APP_PRINT_STATE_TO_WORK: snprintf(sendBuff, 100, "010");break;
        case APP_PRINT_STATE_WORK: snprintf(sendBuff, 100, "03"); break;
        case APP_PRINT_STATE_TO_PAUSE: snprintf(sendBuff, 100, "011");break;
        case APP_PRINT_STATE_PAUSE: snprintf(sendBuff, 100, "02"); break;
        case APP_PRINT_STATE_TO_RESUME: snprintf(sendBuff, 100, "012");break;
        case APP_PRINT_STATE_LAYER_PAUSE: snprintf(sendBuff, 100, "03");break;
        case APP_PRINT_STATE_FINISH: snprintf(sendBuff, 100, "00"); break;
        case APP_PRINT_STATE_TO_STOP: snprintf(sendBuff, 100, "013");break;
        case APP_PRINT_STATE_DOWNLOAD: break;
        default: snprintf(sendBuff, 100, "01"); break;
    }
    UserGetCmdResponse(UI_GET_CURRENT_PRINT_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHead} *head
 */
static void DevSendCurTempToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    if (systemComfig.model == CR_10_H1){
        snprintf(sendBuff, 100, "%d\t%d\t%d\t%d\t%d",
            (int)(printRunState.nozzleCurTemp[NOZZLE_TEMP]/100.0 + 0.5), (int)(printRunState.bedCurTemp[HOTBED_0_TEMP]/100.0 + 0.5),
            (int)(printRunState.nozzleMaxTemp[NOZZLE_TEMP]/100.0 + 0.5), (int)(printRunState.bedMaxTemp[HOTBED_0_TEMP]/100.0 + 0.5),
            (int)(printRunState.otherCurTemp[OTHER_TEMP_CAVITY]/100.0 + 0.5));
    }
    else {
        snprintf(sendBuff, 100, "%d\t%d\t%d\t%d\t%d",
            (int)(printRunState.nozzleCurTemp[NOZZLE_TEMP]/100.0 + 0.5), (int)(printRunState.bedCurTemp[HOTBED_TEMP]/100.0 + 0.5),
            (int)(printRunState.nozzleMaxTemp[NOZZLE_TEMP]/100.0 + 0.5), (int)(printRunState.bedMaxTemp[HOTBED_TEMP]/100.0 + 0.5),
            (int)(printRunState.otherCurTemp[OTHER_TEMP_CAVITY]/100.0 + 0.5));
    }
    
    UserGetCmdResponse(UI_GET_CUR_HOTEND_BED_TEMP, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurProgressToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "1%d\t%d\t%d\t%d\t%d",
        printRunState.printUsageTime, printRunState.printRemainTime, printRunState.printProgress/100,
        printRunState.printLayers, printRunState.printLayer);
    UserGetCmdResponse(UI_GET_CURRENT_PRINT_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurFanToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "0%d\t%d\t%d", 
        printRunState.fanPercentage[MULTI_FAN_MODEL], printRunState.fanPercentage[MULTI_FAN_CASE], printRunState.fanPercentage[MULTI_FAN_AUXILIARY]);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurUDiskToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "4%d", printRunState.udiskMount[0]);
    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurFanStateToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "8%d\t%d", printRunState.fanSpeed[MULTI_FAN_THROAT], printRunState.fanSpeed[MULTI_FAN_MOTHERBOARD]);
    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurCameraToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "5%d\t%d", printRunState.cameraOnline[0], printRunState.cameraOnline[1]);
    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurQmodeStatusToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "l%d", printRunState.qmodeFlag);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurSelftestToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "16\t%d", printRunState.withSelfTest);
    UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurloadMaterialToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "1%d", printRunState.loadMaterial);
    UserGetCmdResponse(UI_GET_CURRENT_FILAMENT, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurquitMaterialToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "2%d", printRunState.quitMaterial);
    UserGetCmdResponse(UI_GET_CURRENT_FILAMENT, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurPowerlossStateToDis(MsgHeadBuf_t *head)
{
    // 判断是否在开机自检
    if (systemComfig.self_test_sw) return;

    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "13\t%d\t%s", printRunState.existOffContinue, "");
    UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurSerialPortStateToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "7%d", printRunState.serialPort);
    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurlaserExistsToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "a%d", printRunState.laserExists);
    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurMqttConnectStateToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    switch (printRunState.cxyMqttState) {
        case MQTT_THRUN_OK: snprintf(sendBuff, 100, "b1"); break;
        default: snprintf(sendBuff, 100, "b0"); break;
    }
    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurScanFileProgressToDis(MsgHeadBuf_t *head)
{
    CrLogI("scanFileProgress = %d", printRunState.scanFileProgress);
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "d%d", printRunState.scanFileProgress);
    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendXYZAxisRangeToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "1%d\t%d\t%d\t%d\t%d\t%d", printSavePara.devMinSize.x, printSavePara.devMaxSize.x, printSavePara.devMinSize.y, printSavePara.devMaxSize.y, printSavePara.devMinSize.z, printSavePara.devMaxSize.z);
    UserGetCmdResponse(UI_GET_XYZ_AXIS_RANGE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendBedMeshInfoToDis(MsgHeadBuf_t *head)
{
    char sendBuff[1024] = {0};
    strcat(sendBuff, "9");
    strcat(sendBuff, printSavePara.bedMeshInfo);
    UserGetCmdResponse(UI_GET_AUTO_LEVELING_DATA, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurMotorStateToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "d%d", printRunState.motorState);
    UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurAutoLevelProgressToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "3%d", printRunState.autoLevelProgress);
    UserSetCmdResponse(UI_SET_LEVELING_CONTROL, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurAutoPidProgressToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "6%d", printRunState.autoPidProgress);
    UserSetCmdResponse(UI_SET_AUTO_PID_PARA, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurPuaseStatusToDis(MsgHeadBuf_t *head)
{
    CrLogI("Cur Puase Status = %d", printRunState.pauseStatus);
    char sendBuff[100] = {0};
    switch (printRunState.pauseStatus)
    {
        case PAUSE_STATUS_HEATING:
            strcat(sendBuff, "06");
            UserGetCmdResponse(UI_GET_CURRENT_PRINT_STATE, strlen(sendBuff) + 1, sendBuff);
            break;
        case PAUSE_STATUS_FINISH:
            strcat(sendBuff, "03");
            UserGetCmdResponse(UI_GET_CURRENT_PRINT_STATE, strlen(sendBuff) + 1, sendBuff);
            break;
    } 
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurMaterialStatusToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    if(!printSavePara.materialDetect)//断料检测器关闭状态
    {
        strcat(sendBuff, "70");
        UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
        return;
    }

    CrLogI("materialStatus_1 = %d, materialStatus_2 = %d",
        printRunState.materialStatus[MATERIAL_DETECTOR_1], printRunState.materialStatus[MATERIAL_DETECTOR_2]);
    // 断料状态，K1、K1 Max会存在两种结构，配置两个断料检测器，实际只是用一个
    if (printRunState.materialStatus[MATERIAL_DETECTOR_1] == MATERIAL_STATUS_IDLE &&
        printRunState.materialStatus[MATERIAL_DETECTOR_2] == MATERIAL_STATUS_IDLE)
    {
        strcat(sendBuff, "71");
        UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
    }
    else {
        strcat(sendBuff, "74");
        UserGetCmdResponse(UI_GET_DEVICE_CONFIG_STATE, strlen(sendBuff) + 1, sendBuff);
    } 
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurCrTouchStateToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "5%d", printRunState.crTouchState);
    UserGetCmdResponse(UI_GET_AUTO_LEVELING_DATA, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurLocationToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%.3f\t%.3f\t%.3f",
        printRunState.livePosition.x/1000.00, printRunState.livePosition.y/1000.00, printRunState.livePosition.z/1000.00);
    UserGetCmdResponse(UI_GET_CUR_NOZZLE_XYZ_LOCAL, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendGcodeLocationToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%.2f\t%.2f\t%.2f",
        printRunState.gcodePosition.x/1000.00, printRunState.gcodePosition.y/1000.00, printRunState.gcodePosition.z/1000.00);
    // UserGetCmdResponse(UI_GET_CUR_NOZZLE_XYZ_LOCAL, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurHomedAxesToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%d%d%d",
        printRunState.homedAxes.x, printRunState.homedAxes.y, printRunState.homedAxes.z);
    UserGetCmdResponse(UI_GET_HOME_AXES_STATE, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurPrintSpeedToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%d", printRunState.printSpeed);
    UserGetCmdResponse(UI_GET_PRINT_DOUBLE_SPEED, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurPrintFlowToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%d", printRunState.printFlow);
    UserGetCmdResponse(UI_GET_PRINT_FLOW_PARA, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurKlipperStateToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%d", printRunState.klipperStata);
    // UserGetCmdResponse(UI_GET_PRINT_FLOW_PARA, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurKlipperPrintStateToDis(MsgHeadBuf_t *head)
{
    CrLogI("klipper print state = %d", printRunState.klipperPrint);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurFaultCodeToDis(MsgHeadBuf_t *head)
{
    // 关闭屏幕错误弹窗
    if (access(GetDevelopStopErrorPtah(), F_OK) == 0) {
        CrLogW("Stop pushing popups to the screen\n");
        return;
    }

    // 处理特殊错误
    if (printRunState.faultCode.code == FAULT_NOT_ENOUGH_STORAGE_ERROR ||
        printRunState.faultCode.code == FAULT_NOT_ENOUGH_STORAGE_REMIND)
    {
        SystemMemory getInfo = {0};
        json_object *errorValueObj = json_tokener_parse(printRunState.faultCode.value);
        if (errorValueObj)
        {
            json_object *usedSizeObj = json_object_array_get_idx(errorValueObj, 0);
            getInfo.used_size = json_object_get_int64(usedSizeObj);
            json_object *totalSizeObj = json_object_array_get_idx(errorValueObj, 1);
            getInfo.total_size = json_object_get_int64(totalSizeObj);
            json_object *usedPctObj = json_object_array_get_idx(errorValueObj, 2);
            getInfo.used_pct = json_object_get_double(usedPctObj);
        }
        json_object_put(errorValueObj);
        CrLogI("used_size = %d, total_size = %d, used_pct = %f",
                getInfo.used_size, getInfo.total_size, getInfo.used_pct);

        char sendBuff[2048] = {0};
        snprintf(sendBuff, 2048, "%d\t%d\t%.1fG/%.1fG(%d%%)", 
            printRunState.faultCode.code, printRunState.faultCode.error,
            getInfo.used_size/1024.0, getInfo.total_size/1024.0, (int)(getInfo.used_pct*100));
        UserGetCmdResponse(UI_GET_DEVICE_ERROR_INFO, strlen(sendBuff) + 1, sendBuff);
        return;
    }

    char sendBuff[2048] = {0};
    snprintf(sendBuff, 2048, "%d\t%d\t%s", printRunState.faultCode.code, printRunState.faultCode.error, printRunState.faultCode.msg);
    UserGetCmdResponse(UI_GET_DEVICE_ERROR_INFO, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendStartupFullScreenToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%d", 1);
    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendStartupScreenSaverToDis(MsgHeadBuf_t *head)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%d", 2);
    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurrentPrintWorkInfoToDis(MsgHeadBuf_t *head)
{
    char *fileName = strrchr(currentWorkInfo.fileName, '/');
    if (fileName) fileName += 1;

    // 组装应答数据
    char sendBuff[1024] = {0};
    snprintf(sendBuff, 1024, "15\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\t%s",
                fileName,
                currentWorkInfo.startPixel/100.00,
                currentWorkInfo.endPixel/100.00,
                currentWorkInfo.modelHeight/100.00,
                currentWorkInfo.layerHeight/100.00,
                currentWorkInfo.photo,
                currentWorkInfo.software);
    UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerSyncPowerLossInfo(MsgHeadBuf_t *head)
{
    SendString *name = send_string__unpack(NULL, head->bufLen, head->buf);
    if (!name) {
        CrLogW("unpack failed\n");
        return;
    }

    char tempBuff[256] = {0};
    memcpy(tempBuff, name->str.data, name->str.len);
    CrLogI("Power loss file name = %s\n", tempBuff);

    if (name->str.len > 5 && UiInitFinishFlag && !systemComfig.self_test_sw) {
        char *shortName = strrchr((const char*)tempBuff, '/');
        if (shortName)
        {
            shortName += 1;
            char sendBuff[100] = {0};
            snprintf(sendBuff, 100, "13\t%d\t%s", 1, shortName);
            UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendBuff) + 1, sendBuff);
        }
        else CrLogW("Power Off Continue file name fail\n");
    }
    else if (!systemComfig.self_test_sw) {
        char sendBuff[100] = {0};
        snprintf(sendBuff, 100, "13\t%d\t%s", 0, "");
        UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendBuff) + 1, sendBuff);
    }
    else CrLogW("self_test_sw = %d\n", systemComfig.self_test_sw);

    send_string__free_unpacked(name, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {char} *delectStr
 * @param {int} *buf
 */
static int VersionStringToInt(char *delectStr, int *buf)
{
    char *regex = "[0-9]{1,3}";
    regmatch_t regmatch[10];
    int regexSize = UserGetRegexStr(delectStr, regex, regmatch, 10);

    for(int i = 0; i< regexSize; i++)
    {
        int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &delectStr[regmatch[i].rm_so], cnt);
        buf[i] = atoi(str);
    }

    return regexSize;
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

    // 获取重启信息
    char oldVersion[32] = {0};
    memcpy(oldVersion, info->oldversion.data, info->oldversion.len);
    CrLogI("state = %d, oldVer = %s\n", info->state, oldVersion);

    // 判断是否升级重启
    if (info->state)
    {
        CrLogI("This is a system upgrade restart");
        // // 将字符串版本号转换成int数组
        // int oldVer[5] = {0};
        // int curVer[5] = {0};
        // int lodSize = VersionStringToInt(oldVersion, oldVer);
        // int curSize = VersionStringToInt(systemComfig.sys_version, curVer);
        // CrLogI("old version = %d-%d-%d-%d", oldVer[0], oldVer[1], oldVer[2], oldVer[3]);
        // CrLogI("cur version = %d-%d-%d-%d", curVer[0], curVer[1], curVer[2], curVer[3]);

        // // 区分不同版本升级后操作
        // if (systemComfig.model == CR_K1 &&
        //     oldVer[0] == 1 && oldVer[1] == 2 &&
        //     (curVer[0] > 1 || (curVer[0] == 1 && curVer[1] > 2)))
        // {
        //     CrLogI("prompt user auto leveling\n"); 
        // }
        RemindUserToAgreePrivacyPolicy();
        RemindUserToAutolevel();
    }

    upgrade_reboot_sync__free_unpacked(info, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerSyncPrintObjectInfo(MsgHeadBuf_t *head)
{
    // 创建对象排除信息共享内存
    if (printObjectShm.result != GET_SHM_OK) {
        printObjectShm = CreateSemShm(PRINT_OBJECT_SEM_PATH, PRINT_OBJECT_SHM_FILE, 0, false);
    }

    char objectInfo[PRINT_OBJECT_SHM_SIZE] = {0};
    ReadDataFromShm(&printObjectShm, objectInfo, sizeof(objectInfo));
    CrLogI("objectInfo = %s", objectInfo);

    // 更新状态
    char sendBuff[PRINT_OBJECT_SHM_SIZE + 5] = {0};
    strcat(sendBuff, "c");
    strcat(sendBuff, objectInfo);
    
    if (UiInitFinishFlag)
        UserGetCmdResponse(UI_SET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurCompressLogStateToDis(int progress)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "4%d", progress);
    UserSetCmdResponse(UI_SET_USER_EXPORT_LOG, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurExportLogStateToDis(int res, int progress)
{
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "1%d\t%d", res, progress);
    UserSetCmdResponse(UI_SET_USER_EXPORT_LOG, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void DevSendCurUploadLogStateToDis(int res, int progress, char *buff)
{
    char sendBuff[2048] = {0};
    snprintf(sendBuff, 2048, "2%d\t%d\t%s", res, progress, buff);
    UserSetCmdResponse(UI_SET_USER_EXPORT_LOG, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ServerSendAutoPidConfirmToDis(MsgHeadBuf_t *head)
{
    AutoPidResult *pidResult = auto_pid_result__unpack(NULL, head->bufLen, head->buf);
    if (!pidResult) {
        CrLogW("unpack failed\n");
        return;
    }

    if (pidResult->hotend)
    {
        CrLogI("hotend auto pid result; p = %f, i = %f, d = %f",
            pidResult->hotend->p/100.00, pidResult->hotend->i/100.00, pidResult->hotend->d/100.00);
    }  
    if (pidResult->hotbed)
    {
        CrLogI("hotbed auto pid result; p = %f, i = %f, d = %f",
            pidResult->hotbed->p/100.00, pidResult->hotbed->i/100.00, pidResult->hotbed->d/100.00);
    }  
    auto_pid_result__free_unpacked(pidResult, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ServerSyncAutoLevelResultToDis(MsgHeadBuf_t *head)
{
    ReportAutoLevelRes *levelResult = report_auto_level_res__unpack(NULL, head->bufLen, head->buf);
    if (!levelResult) {
        CrLogW("unpack failed\n");
        return;
    }

    // 推送结果到显示
    if (levelResult->has_num && levelResult->has_value)
    {
        CrLogI("auto level num = %d, value = %d", levelResult->num, levelResult->value);
        char sendBuff[100] = {0};
        snprintf(sendBuff, 100, "8%d\t%.2f", levelResult->num, levelResult->value/10000.00);
        UserGetCmdResponse(UI_GET_AUTO_LEVELING_DATA, strlen(sendBuff) + 1, sendBuff);
    }

    report_auto_level_res__free_unpacked(levelResult, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ServerSyncUpgradeStateToDis(MsgHeadBuf_t *head)
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
        int upgradeState = info->state - 1;

        char sendBuff[100] = {0};
        if (info->progress > 0) {
            snprintf(sendBuff, 100, "0%d\t%d", upgradeState, info->progress);
        }
        else snprintf(sendBuff, 100, "0%d\t", upgradeState);
        UserGetCmdResponse(UI_GET_DEVICE_UPGRADE_INFO, strlen(sendBuff) + 1, sendBuff);
    }

    upgrade_info_list__free_unpacked(list, NULL);
}

/**
 * @description: 
 * @return {*}
 */
static void UpdataLogExportStatus(MsgHeadBuf_t *head)
{
    CrLogI("lastPrintRunState, deviceState = %d, logProgress = %d",
        lastPrintRunState.deviceState, lastPrintRunState.logProgress);
    CrLogI("printRunState, deviceState = %d, logProgress = %d\n",
        printRunState.deviceState, printRunState.logProgress);
    
    // 更新状态
    if (printRunState.deviceState == DEVICE_STATE_COMPRESSING_LOG) {
        DevSendCurCompressLogStateToDis(0);
    }
    else if (printRunState.deviceState == DEVICE_STATE_EXPORT_LOG) {
        DevSendCurExportLogStateToDis(EXPORTING_LOGS, printRunState.logProgress);
    }
    else if (printRunState.deviceState == DEVICE_STATE_UPLOAD_LOG) {
        DevSendCurUploadLogStateToDis(EXPORTING_LOGS, printRunState.logProgress, "");
    }
    else if (printRunState.deviceState == DEVICE_STATE_IDLE)
    {
        if (lastPrintRunState.deviceState == DEVICE_STATE_COMPRESSING_LOG ||
            lastPrintRunState.deviceState == DEVICE_STATE_EXPORT_LOG)
        {
            if (printRunState.logProgress == -1) {
                DevSendCurExportLogStateToDis(EXPORT_LOG_FAIL, -1);
            }
            else if (printRunState.logProgress == -2) {
                DevSendCurExportLogStateToDis(EXPORT_STOPLOG_SUCCESS, -1);
            }             
            else DevSendCurExportLogStateToDis(EXPORT_LOG_SUCCESS, 0);
        }
        else if (lastPrintRunState.deviceState == DEVICE_STATE_UPLOAD_LOG && uiStartUploadLog == false)
        {
            if (printRunState.logProgress == -1) {
                DevSendCurUploadLogStateToDis(EXPORT_LOG_FAIL, -1, "");
            }
            else if (printRunState.logProgress == -2) {
                DevSendCurExportLogStateToDis(EXPORT_STOPLOG_SUCCESS, -1);
            }              
            else DevSendCurUploadLogStateToDis(EXPORT_LOG_SUCCESS, 0, "");
        }
    }
}

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
    str.dialogue = "I am display server!";

    GET_MESSAGE_BUFF(buff);
    size_t len = server_test__pack(&str, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_TEST_ANS, buff, len);

    SendProcessMsgBuff(&send, size);
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
    memcpy(systemComfig.time_zone, config->time_zone.data, config->time_zone.len);
    systemComfig.server_config = config->server_config;
    systemComfig.upgrade_remind = config->upgrade_remind;
    systemComfig.server_local = config->server_local;
    systemComfig.agree_privacy = config->agree_privacy;
    systemComfig.creality_num = config->creality_num;
    memcpy(systemComfig.host_name, config->host_name.data, config->host_name.len);
    systemComfig.data_collect = config->data_collect;
    system_config_proto__free_unpacked(config, NULL);
    
    CrLogI("version; sys = %s, hw = %s, model = %d, str = %s, hw1 = %s, deploy = %d",
            systemComfig.sys_version, systemComfig.hw_version, systemComfig.model,
            systemComfig.model_str, systemComfig.hw1_version, systemComfig.deploy_setting);

    // 按进程实际需求处理数据
    // UI未初始化完成，向UI推送数据可能会使界面死机
    if (UiInitFinishFlag)
    {
        // 同步变化状态到UI页面
        if (systemComfig.language != lastSystemComfig.language)
            DevSendCurLanguageToDis(NULL);
        if (systemComfig.sound_size != lastSystemComfig.sound_size)
            DevSendCurSoundSizeToDis(NULL);
        if (systemComfig.sound_sw != lastSystemComfig.sound_sw)
            DevSendCurSoundSwToDis(NULL);
        if (systemComfig.sounde_ffect != lastSystemComfig.sounde_ffect)
            DevSendCurSoundFfectToDis(NULL);  
        if (systemComfig.light_sw != lastSystemComfig.light_sw)
            DevSendCurLightStateToDis(NULL);
        if (systemComfig.light_value != lastSystemComfig.light_value)
            DevSendCurLightValueToDis(NULL);
        if (systemComfig.wifi_sw != lastSystemComfig.wifi_sw)
            DevSendCurWifiStateToDis(NULL);
        if (systemComfig.theme_mode != lastSystemComfig.theme_mode)
            DevSendCurDisplayThemeToDis(NULL);
        if (systemComfig.self_test_sw != lastSystemComfig.self_test_sw)
            DevSendCurSelfTestSwToDis(NULL);
        if (systemComfig.screensaver != lastSystemComfig.screensaver)
            DevSendCurScreensacerSwToDis(NULL);
        if (systemComfig.screen_value != lastSystemComfig.screen_value)
            DevSendCurScreenBrightnessToDis(NULL);
        if (systemComfig.full_screen != lastSystemComfig.full_screen)
            DevSendCurFullScreenToDis(NULL);
        if (systemComfig.auto_power_off != lastSystemComfig.auto_power_off)
            DevSendCurAutoPowerOffSwToDis(NULL);
        if (systemComfig.total_time != lastSystemComfig.total_time)
            DevSendDeviceAllInfoToDis(NULL);
        if (strcmp(systemComfig.time_zone, lastSystemComfig.time_zone) != 0)
            DevSendDeviceTimezoneToDis(NULL);
        if (systemComfig.server_config != lastSystemComfig.server_config)
            DevSendServerConfigToDis(NULL);
        if (systemComfig.upgrade_remind != lastSystemComfig.upgrade_remind)
            DevSendUpgradeRemindToDis(NULL);
        if (systemComfig.server_local != lastSystemComfig.server_local)
            DevSendServerLocalToDis(NULL);
        if (systemComfig.agree_privacy != lastSystemComfig.agree_privacy)
            DevSendAgreePrivacyToDis(NULL);
        if (strcmp(systemComfig.host_name, lastSystemComfig.host_name) != 0)
            DevSendDeviceAllInfoToDis(NULL);
        if (systemComfig.data_collect != lastSystemComfig.data_collect)
            DevSendDataCollectToDis(NULL);
    }

    lastSystemComfig = systemComfig;
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
    for (int i = 0; i < savePara->n_levelvalue; i++)
        printSavePara.levelValue.value[i] = savePara->levelvalue[i];

    printSavePara.gcodeMacro.size = savePara->n_gcodemacro;
    for (int i = 0; i < savePara->n_gcodemacro; i++)
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

    memcpy(printSavePara.bedMeshInfo, savePara->bedmeshinfo.data, savePara->bedmeshinfo.len);
    print_save_para__free_unpacked(savePara, NULL);

    CrLogI("k_Speed = %d, k_Acceleration = %d, k_Corner = %d, k_Jerk = %d, pressureAdvance = %d, SmoothTime = %d",
        printSavePara.k_Speed, printSavePara.k_Acceleration, printSavePara.k_Corner,
        printSavePara.k_Jerk, printSavePara.pressureAdvance, printSavePara.SmoothTime);
    CrLogI("levelPoints; x = %d, y = %d", printSavePara.levelPoints.x, printSavePara.levelPoints.y);

    // 按进程实际需求处理数据
    // UI未初始化完成，向UI推送数据可能会使界面死机
    if (UiInitFinishFlag)
    {
        // 同步变化状态到UI页面
        if (printSavePara.powerLoss != lastPrintSavePara.powerLoss)
            DevSendCurPowerLossSwToDis(NULL);
        if (printSavePara.materialDetect != lastPrintSavePara.materialDetect)
            DevSendCurMaterialStatusToDis(NULL);
        if (printSavePara.hotendPid.p != lastPrintSavePara.hotendPid.p ||
            printSavePara.hotendPid.i != lastPrintSavePara.hotendPid.i ||
            printSavePara.hotendPid.d != lastPrintSavePara.hotendPid.d ||
            printSavePara.bedPid.p != lastPrintSavePara.bedPid.p ||
            printSavePara.bedPid.i != lastPrintSavePara.bedPid.i ||
            printSavePara.bedPid.d != lastPrintSavePara.bedPid.d)
            DevSendCurTempPidToDis(NULL);
        if (printSavePara.homeOffset.x != lastPrintSavePara.homeOffset.x ||
            printSavePara.homeOffset.y != lastPrintSavePara.homeOffset.y ||
            printSavePara.homeOffset.z != lastPrintSavePara.homeOffset.z ||
            printSavePara.homeOffset.e != lastPrintSavePara.homeOffset.e)
            DevSendCurAxisOffsetToDis(NULL);
        if (printSavePara.axisRecoup.x != lastPrintSavePara.axisRecoup.x ||
            printSavePara.axisRecoup.y != lastPrintSavePara.axisRecoup.y ||
            printSavePara.axisRecoup.z != lastPrintSavePara.axisRecoup.z ||
            printSavePara.axisRecoup.e != lastPrintSavePara.axisRecoup.e)
            DevSendCurAxisRecoupToDis(NULL);
        if (printSavePara.stepValue.x != lastPrintSavePara.stepValue.x ||
            printSavePara.stepValue.y != lastPrintSavePara.stepValue.y ||
            printSavePara.stepValue.z != lastPrintSavePara.stepValue.z ||
            printSavePara.stepValue.e != lastPrintSavePara.stepValue.e)
            DevSendCurSportsParaToDis(1);
        if (printSavePara.Acceleration.x != lastPrintSavePara.Acceleration.x ||
            printSavePara.Acceleration.y != lastPrintSavePara.Acceleration.y ||
            printSavePara.Acceleration.z != lastPrintSavePara.Acceleration.z ||
            printSavePara.Acceleration.e != lastPrintSavePara.Acceleration.e)
            DevSendCurSportsParaToDis(2);
        if (printSavePara.Speed.x != lastPrintSavePara.Speed.x ||
            printSavePara.Speed.y != lastPrintSavePara.Speed.y ||
            printSavePara.Speed.z != lastPrintSavePara.Speed.z ||
            printSavePara.Speed.e != lastPrintSavePara.Speed.e)
            DevSendCurSportsParaToDis(4);
        if (printSavePara.Jerk.x != lastPrintSavePara.Jerk.x ||
            printSavePara.Jerk.y != lastPrintSavePara.Jerk.y ||
            printSavePara.Jerk.z != lastPrintSavePara.Jerk.z ||
            printSavePara.Jerk.e != lastPrintSavePara.Jerk.e)
            DevSendCurSportsParaToDis(3);
        if (printSavePara.levelPoints.x != lastPrintSavePara.levelPoints.x ||
            printSavePara.levelPoints.y != lastPrintSavePara.levelPoints.y)
            DevSendCurAutoLevelPointsToDis(NULL);
        if (printSavePara.fanFeedback != lastPrintSavePara.fanFeedback)
            DevSendCurExistFanFeedbackToDis(NULL);
        if (printSavePara.devMinSize.x != lastPrintSavePara.devMinSize.x ||
            printSavePara.devMinSize.y != lastPrintSavePara.devMinSize.y ||
            printSavePara.devMinSize.z != lastPrintSavePara.devMinSize.z ||
            printSavePara.devMaxSize.x != lastPrintSavePara.devMaxSize.x ||
            printSavePara.devMaxSize.y != lastPrintSavePara.devMaxSize.y ||
            printSavePara.devMaxSize.z != lastPrintSavePara.devMaxSize.z )
            DevSendXYZAxisRangeToDis(NULL);
        if (strcmp(printSavePara.bedMeshInfo, lastPrintSavePara.bedMeshInfo) != 0)
            DevSendBedMeshInfoToDis(NULL);
    }

    lastPrintSavePara = printSavePara;
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
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeMultiFanChange(PrintState_t last, PrintState_t cur)
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
static bool JudgeMultiUDISKChange(PrintState_t last, PrintState_t cur)
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
static bool JudgeMultiFanStateChange(PrintState_t last, PrintState_t cur)
{
    if(last.fanSpeed[MULTI_FAN_THROAT] != cur.fanSpeed[MULTI_FAN_THROAT])
        return true;
    else if(last.fanSpeed[MULTI_FAN_MOTHERBOARD] != cur.fanSpeed[MULTI_FAN_MOTHERBOARD])
        return true;
    else
        return false;
}

/**
 * @description: 
 * @return {*}
 * @param {PrintState_t} last
 * @param {PrintState_t} cur
 */
static bool JudgeMultiCameraChange(PrintState_t last, PrintState_t cur)
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
 * @param undefined
 */
static void SyncDeviceStateToDis(MsgHeadBuf_t *head)
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
    printRunState.scannerExists = state->scannerexists;
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
    printRunState.scanFileProgress = state->scanfileprogress;
    sync_print_state__free_unpacked(state, NULL);
    
    CrLogI("[Heartbeat] port = %d, state = %d, progress = %d, layer = %d, layers = %d",
            printRunState.serialPort, printRunState.workState, printRunState.printProgress, printRunState.printLayer, printRunState.printLayers);
    CrLogI("[Heartbeat] code = %d, usage = %d, remain = %d, used = %d",
            printRunState.faultCode.code, printRunState.printUsageTime, printRunState.printRemainTime, printRunState.filamentUsed);
    CrLogI("[Heartbeat] udisk0 = %d, ethernet = %d, camera0 = %d",
            printRunState.udiskMount[UDISK_0], printRunState.ethernetExists, printRunState.cameraOnline[CAMERA_MODEL]);
    CrLogI("[Heartbeat] modelFan = %d, caseFan = %d, auxiliaryFan = %d",
            printRunState.fanState[MULTI_FAN_MODEL], printRunState.fanState[MULTI_FAN_CASE], printRunState.fanState[MULTI_FAN_AUXILIARY]);
    CrLogI("[Heartbeat] real time; speed = %d, flow = %d",
            printRunState.realTimeSpeed, printRunState.realTimeFlow);
    CrLogI("[Heartbeat] chamber = %d, deviceState = %d, withSelfTest = %d, cxyMqttState = %d",
            printRunState.otherCurTemp[OTHER_TEMP_CAVITY], printRunState.deviceState, printRunState.withSelfTest, printRunState.cxyMqttState);
    DisplayCurrentPower(printRunState);
    DisplayCurrentTemp(printRunState);

    // 按进程实际需求处理数据
    // UI未初始化完成，向UI推送数据可能会使界面死机
    if (UiInitFinishFlag)
    {
        // 同步周期状态到UI页面
        DevSendCurTempToDis(NULL);
        // 同步变化状态到UI页面
        if (printRunState.workState != lastPrintRunState.workState)
            DevSendCurWorkStateToDis(NULL);
        if (JudgeMultiFanChange(lastPrintRunState, printRunState))
            DevSendCurFanToDis(NULL);
        if (printRunState.motorState != lastPrintRunState.motorState)
            DevSendCurMotorStateToDis(NULL);
        if (printRunState.printProgress/100 != lastPrintRunState.printProgress/100 ||
            printRunState.printLayer != lastPrintRunState.printLayer ||
            printRunState.printLayers != lastPrintRunState.printLayers ||
            printRunState.printUsageTime/60 != lastPrintRunState.printUsageTime/60 ||
            printRunState.printRemainTime/60 != lastPrintRunState.printRemainTime/60)
            DevSendCurProgressToDis(NULL);
        if (printRunState.autoLevelProgress != lastPrintRunState.autoLevelProgress)
            DevSendCurAutoLevelProgressToDis(NULL);
        if (printRunState.autoPidProgress != lastPrintRunState.autoPidProgress)
            DevSendCurAutoPidProgressToDis(NULL);
        if (printRunState.crTouchState != lastPrintRunState.crTouchState)
            DevSendCurCrTouchStateToDis(NULL);
        if (JudgeFaultCodeChange(lastPrintRunState, printRunState)) {
            DevSendCurFaultCodeToDis(NULL);
            if (printRunState.faultCode.error > 0 && printRunState.faultCode.error <= GetNnknownError()) TurnOffBootAnimation();
        }
        if (printRunState.pauseStatus != lastPrintRunState.pauseStatus)
            DevSendCurPuaseStatusToDis(NULL);
        if (JudgeMaterialDetectorChange(lastPrintRunState, printRunState))
            DevSendCurMaterialStatusToDis(NULL);
        if (printRunState.livePosition.x != lastPrintRunState.livePosition.x ||
            printRunState.livePosition.y != lastPrintRunState.livePosition.y ||
            printRunState.livePosition.z != lastPrintRunState.livePosition.z ||
            printRunState.livePosition.e != lastPrintRunState.livePosition.e)
            DevSendCurLocationToDis(NULL);
        if (printRunState.gcodePosition.x != lastPrintRunState.gcodePosition.x ||
            printRunState.gcodePosition.y != lastPrintRunState.gcodePosition.y ||
            printRunState.gcodePosition.z != lastPrintRunState.gcodePosition.z ||
            printRunState.gcodePosition.e != lastPrintRunState.gcodePosition.e)
            DevSendGcodeLocationToDis(NULL);
        if (printRunState.homedAxes.x != lastPrintRunState.homedAxes.x ||
            printRunState.homedAxes.y != lastPrintRunState.homedAxes.y ||
            printRunState.homedAxes.z != lastPrintRunState.homedAxes.z ||
            printRunState.homedAxes.e != lastPrintRunState.homedAxes.e)
            DevSendCurHomedAxesToDis(NULL);
        if (printRunState.printSpeed != lastPrintRunState.printSpeed)
            DevSendCurPrintSpeedToDis(NULL);
        if (printRunState.printFlow != lastPrintRunState.printFlow)
            DevSendCurPrintFlowToDis(NULL);
        if (printRunState.klipperStata != lastPrintRunState.klipperStata)
            DevSendCurKlipperStateToDis(NULL);
        if (printRunState.klipperPrint != lastPrintRunState.klipperPrint)
            DevSendCurKlipperPrintStateToDis(NULL);
        if (JudgeMultiUDISKChange(lastPrintRunState, printRunState)) {
            DevSendCurUDiskToDis(NULL);
            SetUdisFileInfokMonitor();
        }
        if(JudgeMultiFanStateChange(lastPrintRunState, printRunState))
        {
            DevSendCurFanStateToDis(NULL);
        }
        if (JudgeMultiCameraChange(lastPrintRunState, printRunState)) {
            DevSendCurCameraToDis(NULL);
        }
        if (printRunState.qmodeFlag != lastPrintRunState.qmodeFlag)
            DevSendCurQmodeStatusToDis(NULL);
        if (printRunState.withSelfTest != lastPrintRunState.withSelfTest)
            DevSendCurSelftestToDis(NULL);
        if (printRunState.loadMaterial != lastPrintRunState.loadMaterial)
            DevSendCurloadMaterialToDis(NULL);
        if (printRunState.quitMaterial != lastPrintRunState.quitMaterial)
            DevSendCurquitMaterialToDis(NULL);
        if (printRunState.existOffContinue != lastPrintRunState.existOffContinue)
            DevSendCurPowerlossStateToDis(NULL);
        if (printRunState.serialPort != lastPrintRunState.serialPort) {
            DevSendCurSerialPortStateToDis(NULL);
            // klipper连接成功
            if (printRunState.serialPort && firstBootConnectKlipper) {
                firstBootConnectKlipper = false;
                TurnOffBootAnimation(); // 关闭开机动画
                DisInitiativeGetUpgradeInfo(); // 查询是否是升级重启
            }
        }
        if (printRunState.laserExists != lastPrintRunState.laserExists)
            DevSendCurlaserExistsToDis(NULL);
        if (printRunState.cxyMqttState != lastPrintRunState.cxyMqttState)
            DevSendCurMqttConnectStateToDis(NULL);
        if (printRunState.logProgress != lastPrintRunState.logProgress ||
            printRunState.deviceState != lastPrintRunState.deviceState)
            UpdataLogExportStatus(NULL);
        if (printRunState.scanFileProgress != lastPrintRunState.scanFileProgress)
            DevSendCurScanFileProgressToDis(NULL);
    }

    lastPrintRunState = printRunState;
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ServerSyncPrintWorkInfoToDis(MsgHeadBuf_t *head)
{
    PrintWorkInfo *workInfo = print_work_info__unpack(NULL, head->bufLen, head->buf);
    if (!workInfo) {
        CrLogW("unpack failed\n");
        return;
    }

    // 打印任务ID
    CrLogI("print work start id = %d", workInfo->id);
    currentWorkInfo.id = workInfo->id;

    // 打印文件名
    bzero(currentWorkInfo.fileName, sizeof(currentWorkInfo.fileName));
    memcpy(currentWorkInfo.fileName, workInfo->filename.data, workInfo->filename.len);
    CrLogI("print work file name = %s", currentWorkInfo.fileName);

    // 打印文件大小
    CrLogI("print work file size = %d", workInfo->size);
    currentWorkInfo.size = workInfo->size;

    // 打印文件创建时间
    CrLogI("print work create time = %d", workInfo->ctime);
    currentWorkInfo.cTime = workInfo->ctime;

    // 打印开始时间
    CrLogI("print work start time = %d", workInfo->starttime);
    currentWorkInfo.startTime = workInfo->starttime;

    // 预计打印时间
    CrLogI("print work total time = %d", workInfo->totaltime);
    currentWorkInfo.totalTime = workInfo->totaltime;

    // 预计打印耗材
    CrLogI("print work consumables = %d", workInfo->consumables);
    currentWorkInfo.consumables = workInfo->consumables;

    // 判断启动打印的交互方式
    CrLogI("print work start way = %d", workInfo->startway);
    currentWorkInfo.startWay = workInfo->startway;

    // 文件缩略图
    bzero(currentWorkInfo.thumbnail, sizeof(currentWorkInfo.thumbnail));
    memcpy(currentWorkInfo.thumbnail, workInfo->thumbnail.data, workInfo->thumbnail.len);
    CrLogI("print work file thumbnail = %s", currentWorkInfo.thumbnail);

    // 文件注水图
    bzero(currentWorkInfo.photo, sizeof(currentWorkInfo.photo));
    memcpy(currentWorkInfo.photo, workInfo->photo.data, workInfo->photo.len);
    CrLogI("print work file photo = %s", currentWorkInfo.photo);

    // 注水图起始像素点
    CrLogI("print work file photo start pixel = %d", workInfo->startpixel);
    currentWorkInfo.startPixel = workInfo->startpixel;

    // 注水图结束像素点
    CrLogI("print work file photo end pixel = %d", workInfo->endpixel);
    currentWorkInfo.endPixel = workInfo->endpixel;

    // 注水图模型高度
    CrLogI("print work file photo model height = %d", workInfo->modelheight);
    currentWorkInfo.modelHeight = workInfo->modelheight;

    // 注水图模型层高
    CrLogI("print work file photo layer height = %d", workInfo->layerheight);
    currentWorkInfo.layerHeight = workInfo->layerheight;

    // 切片软件名称
    bzero(currentWorkInfo.software, sizeof(currentWorkInfo.software));
    memcpy(currentWorkInfo.software, workInfo->software.data, workInfo->software.len);
    CrLogI("print work file software = %s", currentWorkInfo.software);

    print_work_info__free_unpacked(workInfo, NULL);

    // 更新状态
    if (UiInitFinishFlag) {
        DevSendCurrentPrintWorkInfoToDis(NULL);
    }
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ServerSyncFileCopyProgressToDis(MsgHeadBuf_t *head)
{
    SendString *name = send_string__unpack(NULL, head->bufLen, head->buf);
    if (!name) {
        CrLogW("unpack failed\n");
        return;
    }
    char tempBuff[16] = {0};
    memcpy(tempBuff, name->str.data, name->str.len);
    CrLogI("File copy progress = %s\n", tempBuff);

    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "22\t%s", tempBuff);
    UserSetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetLocalGcodeAns(MsgHeadBuf_t *head)
{
    LocalGcodeInfo *fileSum = local_gcode_info__unpack(NULL, head->bufLen, head->buf);
    if (!fileSum) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("get gcode file result = %d", fileSum->result);
    char sendBuff[100] = {0};
    if (fileSum->result) snprintf(sendBuff, 100, "10\t%d", fileSum->sum);
    else snprintf(sendBuff, 100, "10\t%d", 0);
    UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendBuff) + 1, sendBuff);

    local_gcode_info__free_unpacked(fileSum, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetLocalImageAns(MsgHeadBuf_t *head)
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
    local_gcode_info__free_unpacked(image, NULL);

    // 打包返回结果
    CrLogI("get gcode image result = %d", getGcodeInfoResult);
    if (getGcodeInfoResult)
    {
        CrLogI("file id range start = %d, end = %d", fileStart, fileEnd);
        int imageSize = (fileEnd - fileStart + 1) * 500;
        char sendImageBuf[imageSize];
        memset(sendImageBuf, 0, imageSize);
        strcat(sendImageBuf, "11\t"); // 第一个字节是1，表示发送目录名称和图片

        // 判断文件是否有效
        CrLogI("filePath = %s", filePath);
        if (access(filePath, F_OK) != 0) {
            CrLogW("gcode info file does not exist\n");
            return;
        }

        // 打开文件
        FILE *fileInfoFd = fopen(filePath, "r");
        if (fileInfoFd == NULL) {
            CrLogE("open %s error", filePath);
            return;
        }

        // 读取文件
        int readSizeMax = 1024;
        char readBuff[readSizeMax];
        memset(readBuff, 0, readSizeMax);
        while (fgets(readBuff, readSizeMax, fileInfoFd) != NULL)
        {
            CrLogI("json info = %s", readBuff);
            json_object* fileInfo = json_tokener_parse(readBuff);
            memset(readBuff, 0, readSizeMax);

            // 判断数据是否有效
            if (fileInfo == NULL || !json_object_is_type(fileInfo, json_type_object)) {
                CrLogW("get file info obj fail\n");
                if (fileInfo) json_object_put(fileInfo);
                continue;
            }
            
            // 获取文件id
            json_object *tempObj = json_object_object_get(fileInfo, "fileId");
            if (tempObj == NULL || !json_object_is_type(tempObj, json_type_int)) {
                CrLogW("get file id obj fail\n");
                json_object_put(fileInfo);
                continue;
            }
            
            // 获取文件名称和图片
            int fileId = json_object_get_int(tempObj);
            if (fileId >= fileStart)
            {
                // 文件名
                tempObj = json_object_object_get(fileInfo, "fileName");
                if (tempObj && json_object_is_type(tempObj, json_type_string))
                {
                    const char *name = json_object_get_string(tempObj);
                    if (name) {
                        if (strrchr(name, '/')) name = strrchr(name, '/') + 1;
                        strcat(sendImageBuf, name);
                    }
                    else CrLogW("get file name string fail\n");
                }
                else CrLogW("get file name obj fail\n");
                strcat(sendImageBuf, ":");

                // 缩略图地址
                tempObj = json_object_object_get(fileInfo, "thumbnail");
                if (tempObj && json_object_is_type(tempObj, json_type_string))
                {
                    const char *thumbnail = json_object_get_string(tempObj);
                    if (thumbnail) strcat(sendImageBuf, thumbnail);
                    else CrLogW("get thumbnail string fail\n");
                }
                else CrLogW("get thumbnail obj fail\n");
                strcat(sendImageBuf, ":");

                // 预计时间
                tempObj = json_object_object_get(fileInfo, "timeCost");
                if (tempObj && json_object_is_type(tempObj, json_type_int))
                {
                    sprintf(&sendImageBuf[strlen(sendImageBuf)], "%d", json_object_get_int(tempObj));
                }
                else CrLogW("get timeCost obj fail\n");
                strcat(sendImageBuf, ":");

                // 所需耗材
                tempObj = json_object_object_get(fileInfo, "consumables");
                if (tempObj && json_object_is_type(tempObj, json_type_int))
                {
                    sprintf(&sendImageBuf[strlen(sendImageBuf)], "%d", json_object_get_int(tempObj));
                }
                else CrLogW("get consumables obj fail\n");
                strcat(sendImageBuf, ":");

                // 层高
                tempObj = json_object_object_get(fileInfo, "floorHeight");
                if (tempObj && json_object_is_type(tempObj, json_type_int))
                {
                    sprintf(&sendImageBuf[strlen(sendImageBuf)], "%.2f", json_object_get_int(tempObj) / 100.00);
                }
                else CrLogW("get floorHeight obj fail\n");
                strcat(sendImageBuf, ":");

                // 模型尺寸
                tempObj = json_object_object_get(fileInfo, "modelX");
                if (tempObj && json_object_is_type(tempObj, json_type_int))
                {
                    sprintf(&sendImageBuf[strlen(sendImageBuf)], "%.2f", json_object_get_int(tempObj) / 100.00);
                }
                else CrLogW("get modelX obj fail\n");
                strcat(sendImageBuf, "x");

                tempObj = json_object_object_get(fileInfo, "modelY");
                if (tempObj && json_object_is_type(tempObj, json_type_int))
                {
                    sprintf(&sendImageBuf[strlen(sendImageBuf)], "%.2f", json_object_get_int(tempObj) / 100.00);
                }
                else CrLogW("get modelY obj fail\n");
                strcat(sendImageBuf, "x");

                tempObj = json_object_object_get(fileInfo, "modelZ");
                if (tempObj && json_object_is_type(tempObj, json_type_int))
                {
                    sprintf(&sendImageBuf[strlen(sendImageBuf)], "%.2f", json_object_get_int(tempObj) / 100.00);
                }
                else CrLogW("get modelZ obj fail\n");
                strcat(sendImageBuf, ":");

                // 文件夹/文件
                tempObj = json_object_object_get(fileInfo, "type");
                if (tempObj && json_object_is_type(tempObj, json_type_int))
                {
                    if (json_object_get_int(tempObj) == CACHE_PATH_TYPE_DIR) strcat(sendImageBuf, "0");
                    else strcat(sendImageBuf, "1");
                }
                else CrLogW("get type obj fail\n");
                strcat(sendImageBuf, ":");

                // 文件大小
                tempObj = json_object_object_get(fileInfo, "fileSize");
                if (tempObj && json_object_is_type(tempObj, json_type_int))
                {
                    sprintf(&sendImageBuf[strlen(sendImageBuf)], "%d", json_object_get_int(tempObj));
                }
                else CrLogW("get fileSize obj fail\n");
                strcat(sendImageBuf, ":");

                // 文件时间
                tempObj = json_object_object_get(fileInfo, "cTime");
                if (tempObj && json_object_is_type(tempObj, json_type_int))
                {
                    sprintf(&sendImageBuf[strlen(sendImageBuf)], "%d", json_object_get_int(tempObj));
                }
                else CrLogW("get cTime obj fail\n");
                strcat(sendImageBuf, ":");

                // 耗材类型
                tempObj = json_object_object_get(fileInfo, "material");
                if (tempObj && json_object_is_type(tempObj, json_type_string))
                {
                    const char *material = json_object_get_string(tempObj);
                    if (material) strcat(sendImageBuf, material);
                    else CrLogW("get material string fail\n");
                }
                else CrLogW("get material obj fail\n");
                strcat(sendImageBuf, ":");

                // 喷头目标温度
                tempObj = json_object_object_get(fileInfo, "nozzleTemp");
                if (tempObj && json_object_is_type(tempObj, json_type_int))
                {
                    sprintf(&sendImageBuf[strlen(sendImageBuf)], "%d", json_object_get_int(tempObj) / 100);
                }
                else CrLogW("get nozzleTemp obj fail\n");
                strcat(sendImageBuf, ":");

                // 热床目标温度
                tempObj = json_object_object_get(fileInfo, "bedTemp");
                if (tempObj && json_object_is_type(tempObj, json_type_int))
                {
                    sprintf(&sendImageBuf[strlen(sendImageBuf)], "%d", json_object_get_int(tempObj) / 100);
                }
                else CrLogW("get bedTemp obj fail\n");
                strcat(sendImageBuf, ":");
                strcat(sendImageBuf, "\t");
            }
            json_object_put(fileInfo);

            // 完成退出
            if (fileId == fileEnd)
            {
                sendImageBuf[strlen(sendImageBuf) - 1] = '\0';
                CrLogI("sendImageBuf = \n%s", sendImageBuf);
                break;
            }
        }
        fclose(fileInfoFd);
        
        UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendImageBuf) + 1, sendImageBuf);
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetLocalPhotoAns(MsgHeadBuf_t *head)
{
    LocalGcodeInfo *photo = local_gcode_info__unpack(NULL, head->bufLen, head->buf);
    if (!photo) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("get gcode photo result = %d", photo->result);
    char photoPath[256] = {0};
    if (photo->result)
    {
        snprintf(photoPath, 256, "12\t%.2f\t%.2f\t%.2f\t%.2f\t%s",
                photo->startpixel/100.00, photo->endpixel/100.00,
                photo->modelheight/100.00, photo->layerheight/100.00,
                photo->photopath.data);
        UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(photoPath) + 1, photoPath);
    }
    else
    {
        snprintf(photoPath, 256, "12");
        UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(photoPath) + 1, photoPath);
    }

    local_gcode_info__free_unpacked(photo, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetLocaltionAns(MsgHeadBuf_t *head)
{
    AxisPositionInfo *location = axis_position_info__unpack(NULL, head->bufLen, head->buf);
    if (!location) {
        CrLogW("unpack failed\n");
        return;
    }

    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "%.2f\t%.2f\t%.2f", location->x/100.00, location->y/100.00, location->z/100.00);
    UserGetCmdResponse(UI_GET_CUR_NOZZLE_XYZ_LOCAL, strlen(sendBuff) + 1, sendBuff);

    axis_position_info__free_unpacked(location, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetMaterialPreferAns(MsgHeadBuf_t *head)
{
    MaterialPreferList *list = material_prefer_list__unpack(NULL, head->bufLen, head->buf);
    if (!list) {
        CrLogW("unpack failed\n");
        return;
    }

    // 循环提取
    for (int i = 0; i < list->n_list; i++)
    {
        char sendBuff[100] = {0};
        snprintf(sendBuff, 100, "%d%d\t%d", (list->list[i]->id - 1), list->list[i]->hotendtemp, list->list[i]->bedtemp);
        UserGetCmdResponse(UI_GET_PLA_ABS_WARM_UP_TEMP, strlen(sendBuff) + 1, sendBuff);
    }
    
    material_prefer_list__free_unpacked(list, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetAutoPidPreferAns(MsgHeadBuf_t *head)
{
    TempAutoPidPreferList *list = temp_auto_pid_prefer_list__unpack(NULL, head->bufLen, head->buf);
    if (!list) {
        CrLogW("unpack failed\n");
        return;
    }

    // 循环提取
    for (int i = 0; i < list->n_list; i++)
    {
        char sendBuff[100] = {0};
        snprintf(sendBuff, 100, "%d%d\t%d", (list->list[i]->id - 1), list->list[i]->temp, list->list[i]->time);
        UserGetCmdResponse(UI_GET_AUTO_PID_PARA, strlen(sendBuff) + 1, sendBuff);
    }

    temp_auto_pid_prefer_list__free_unpacked(list, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetHistoryRecordSumAns(MsgHeadBuf_t *head)
{
    int sun = 0;
    if (access(GetuserPrintHistoryRecordPtah(), F_OK) == 0) {
        // 读取文件，获取json数据
        json_object *historyRecord = json_object_from_file(GetuserPrintHistoryRecordPtah());
        if (historyRecord) {
            json_object *listObj = json_object_object_get(historyRecord, "list");
            sun = json_object_array_length(listObj);
            json_object_put(historyRecord);
        }
        else CrLogW("read json object fail\n");
    }
    else CrLogI("no history record\n");

    CrLogI("history record sum = %d", sun);
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "20\t%d", sun);
    UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetHistoryRecordAns(uint32_t startId, uint32_t endId)
{
    CrLogI("get history record from file");
    int bufLen = (endId - startId + 1) * 1024;
    char sendBuff[bufLen];
    bzero(sendBuff, sizeof(sendBuff));
    strcat(sendBuff, "21\t");

    // 判断历史记录是否存在，读取文件，获取json数据
    if (access(GetuserPrintHistoryRecordPtah(), F_OK) == 0)
    {
        json_object *historyRecord = json_object_from_file(GetuserPrintHistoryRecordPtah());
        if (historyRecord) {
            // 提取历史记录列表
            json_object *listObj = json_object_object_get(historyRecord, "list");
            int recordSize = json_object_array_length(listObj);
            CrLogI("recordSize = %d", recordSize);
            // 循环提取记录
            int getSize = endId < recordSize ? endId : recordSize;
            for (int i = (startId-1); i < getSize; i++)
            {
                json_object *record = json_object_array_get_idx(listObj, i);
                // 文件名
                const char *filePath = json_object_get_string(json_object_object_get(record, "filename"));
                char *filename = strrchr(filePath, '/');
                if (filename) strcat(sendBuff, filename + 1);
                else strcat(sendBuff, filePath);
                strcat(sendBuff, ":");
                // 图片地址
                const char *thumbnail = json_object_get_string(json_object_object_get(record, "thumbnail"));
                strcat(sendBuff, thumbnail);
                strcat(sendBuff, ":");
                // 开始打印时间
                int starttime = json_object_get_int(json_object_object_get(record, "starttime"));
                char startTimeStr[32] = {0};
                snprintf(startTimeStr, sizeof(startTimeStr), "%d", starttime);
                strcat(sendBuff, startTimeStr);
                strcat(sendBuff, ":");
                // 打印使用时间
                int usagetime = json_object_get_int(json_object_object_get(record, "usagetime"));
                char usageTimeStr[32] = {0};
                snprintf(usageTimeStr, sizeof(usageTimeStr), "%d", usagetime);
                strcat(sendBuff, usageTimeStr);
                strcat(sendBuff, ":");
                // 打印结果
                int printfinish = json_object_get_int(json_object_object_get(record, "printfinish"));
                if (printfinish) strcat(sendBuff, "1");
                else strcat(sendBuff, "0");
                strcat(sendBuff, ":");
                // 文件是否存在
                if (access(filePath, F_OK) == 0) strcat(sendBuff, "1");
                else strcat(sendBuff, "0");
                strcat(sendBuff, "\t");
            }
            json_object_put(historyRecord);

            // 去除最后一个\t
            sendBuff[strlen(sendBuff) - 1] = 0;
            CrLogI("sendBuff = \n%s\n", sendBuff);
        }
        else CrLogW("read json object fail\n");
    }
    else CrLogI("no history record\n");

    UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetDelayImageSumAns(MsgHeadBuf_t *head)
{
    int sun = 0;
    if (access(GetUserDelayImageInfoPtah(), F_OK) == 0) {
        // 读取文件，获取json数据
        json_object *delayImage = json_object_from_file(GetUserDelayImageInfoPtah());
        if (delayImage) {
            json_object *listObj = json_object_object_get(delayImage, "list");
            sun = json_object_array_length(listObj);
            json_object_put(delayImage);
        }
        else CrLogW("read json object fail\n");
    }
    else CrLogI("no delay image\n");

    CrLogI("delay image sum = %d", sun);
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "30\t%d", sun);
    UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendBuff) + 1, sendBuff);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetDelayImageAns(uint32_t startId, uint32_t endId)
{
    CrLogI("get delay image from file");
    int bufLen = (endId - startId + 1) * 1024;
    char sendBuff[bufLen];
    bzero(sendBuff, sizeof(sendBuff));
    strcat(sendBuff, "31\t");

    // 判断延时摄影是否存在，读取文件，获取json数据
    if (access(GetUserDelayImageInfoPtah(), F_OK) == 0)
    {
        json_object *delayImage = json_object_from_file(GetUserDelayImageInfoPtah());
        if (delayImage) {
            // 提取延时摄影列表
            json_object *listObj = json_object_object_get(delayImage, "list");
            int imageSize = json_object_array_length(listObj);
            CrLogI("imageSize = %d", imageSize);
            // 循环提取记录
            int getSize = endId < imageSize ? endId : imageSize;
            for (int i = (startId-1); i < getSize; i++)
            {
                json_object *image = json_object_array_get_idx(listObj, i);
                // 文件名
                const char *fileName = json_object_get_string(json_object_object_get(image, "videoname"));
                /*char *video = strrchr(filePath, '/');
                if (video) strcat(sendBuff, video + 1);
                else strcat(sendBuff, filePath);*/
                strcat(sendBuff, fileName);
                strcat(sendBuff, ":");
                // 开始打印时间
                int starttime = json_object_get_int(json_object_object_get(image, "starttime"));
                char startTimeStr[32] = {0};
                snprintf(startTimeStr, sizeof(startTimeStr), "%d", starttime);
                strcat(sendBuff, startTimeStr);
                strcat(sendBuff, ":");
                // 打印使用时间
                int printtime = json_object_get_int(json_object_object_get(image, "printtime"));
                char printTimeStr[32] = {0};
                snprintf(printTimeStr, sizeof(printTimeStr), "%d", printtime);
                strcat(sendBuff, printTimeStr);
                strcat(sendBuff, ":");
                // 视频时长
                int duration = json_object_get_int(json_object_object_get(image, "duration"));
                char durationStr[32] = {0};
                snprintf(durationStr, sizeof(durationStr), "%d", duration);
                strcat(sendBuff, durationStr);
                strcat(sendBuff, ":");
                // 喷嘴位置
                int location = json_object_get_int(json_object_object_get(image, "location"));
                char locationStr[32] = {0};
                snprintf(locationStr, sizeof(locationStr), "%d", location);
                strcat(sendBuff, locationStr);
                strcat(sendBuff, ":");
                // 拍摄间隔
                int interval = json_object_get_int(json_object_object_get(image, "interval"));
                char intervalStr[32] = {0};
                snprintf(intervalStr, sizeof(intervalStr), "%d", interval);
                strcat(sendBuff, intervalStr);
                strcat(sendBuff, ":");
                // 渲染帧数
                int render = json_object_get_int(json_object_object_get(image, "render"));
                char renderStr[32] = {0};
                snprintf(renderStr, sizeof(renderStr), "%d", render);
                strcat(sendBuff, renderStr);
                strcat(sendBuff, ":");
                // 图片地址
                const char *cover = json_object_get_string(json_object_object_get(image, "cover"));
                strcat(sendBuff, cover);
                strcat(sendBuff, ":");
                strcat(sendBuff, "\t");
            }
            json_object_put(delayImage);

            // 去除最后一个\t
            sendBuff[strlen(sendBuff) - 1] = 0;
            CrLogI("sendBuff = \n%s\n", sendBuff);
        }
        else CrLogW("read json object fail\n");
    }
    else CrLogI("no delay image\n");

    UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendBuff) + 1, sendBuff);
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

    char sendBuff[512] = {0};
    CrLogI("wifi state, state: %d", info->status);
    if ((info->status == WIFI_STATE_NETWORK || info->status == WIFI_STATE_CONNECTED) && 
        info->has_ssid && info->has_ip)
    {
        CrLogI("wifi change, ssid = [%s], ip = %s, signal = %d\n", info->ssid.data, info->ip.data, info->signal);
        snprintf(sendBuff, 512, "1%d\t%s\t%s\t%d\t", 1, info->ssid.data, info->ip.data, info->signal);
    }
    else snprintf(sendBuff, 512, "1%d\t%s\t%s\t%d\t", 2, "", "", 0);
    
    // 获取有线网络信息
    EthernetInfo_t ethernetInfo = {0};
    if (GetEthernetInfo(&ethernetInfo))
    {
        CrLogI("get ethernet local ip = %s", ethernetInfo.ip);
        CrLogI("get ethernet local gateway = %s", ethernetInfo.gateway);
        CrLogI("get ethernet local subnetMask = %s", ethernetInfo.subnetMask);
        CrLogI("get ethernet local dnsServer = %s", ethernetInfo.dnsServer);

        // 保留一个DNS服务器地址
        char *end = strchr(ethernetInfo.dnsServer, '\n');
        if (end) end[0] = '\0';
        snprintf(&sendBuff[strlen(sendBuff)], 512, "%d\t%s\t%s\t%s\t%s", 1,
            ethernetInfo.ip, ethernetInfo.gateway, ethernetInfo.subnetMask, ethernetInfo.dnsServer);
    }
    else {
        CrLogI("get ethernet info fail\n");
        snprintf(&sendBuff[strlen(sendBuff)], 512, "%d\t%s", 2, "");
    }
    
    if (UiInitFinishFlag)
        UserGetCmdResponse(UI_GET_CURRENT_WIFI_INFO, strlen(sendBuff) + 1, sendBuff);
    networks_info__free_unpacked(info, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetWifiScanListAns(MsgHeadBuf_t *head)
{
    CrLogI("User Control Scan Wifi Ans");
    NetworksInfo *info = networks_info__unpack(NULL, head->bufLen, head->buf);
    if (!info) {
        CrLogW("unpack failed\n");
        return;
    }

    if (info->n_list == 0) CrLogW("Hotspot not scanned\n");
    else
    {
        /* WIFI 加密模式 (WPA2-PSK 、WPA2-PSK、 WPA2、WPA、不加密) */
        // info->list[i]->flags.data

        CrLogI("user scan wifi list size = %d", info->n_list);
        CrLogI("num / usage / frequency / signal / bssid / encrypt / ssid / flags");
        for (int i = 0; i < info->n_list; i++)
        {
            CrLogI("[%2d]\t%d\t%s\t%s\t%s\t%d\t%s\t%s", i+1,
                info->list[i]->wifiusage,
                info->list[i]->frequer.data,
                info->list[i]->signal.data,
                info->list[i]->bssid.data,
                info->list[i]->encrypt,
                info->list[i]->ssid.data,
                info->list[i]->flags.data);
        }
        CrLogI("=====================================================\n");    

        int strLen = 0;
        char sendBuff[2048] = {0};
        sendBuff[strLen++] = '2';
        
        for (int i = 0; i < info->n_list; i++)
        {
            strLen += snprintf(&sendBuff[strLen], 2048, "%s:%d:%s:%s:%d\t",
                info->list[i]->ssid.data, info->list[i]->wifiusage, info->list[i]->signal.data,
                info->list[i]->flags.data, info->list[i]->encrypt);
        }
        sendBuff[strLen - 1] = '\0';

        if (UiInitFinishFlag)
            UserGetCmdResponse(UI_GET_CURRENT_WIFI_INFO, strlen(sendBuff) + 1, sendBuff);
    }

    networks_info__free_unpacked(info, NULL);
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

    // 判断是否有linux OTA新版本
    if (infoList->linuxota)
    {
        CrLogI("get linux ota upgrade info");
        memset(&linuxOTA, 0, sizeof(FirmwareInfo_t));

        char sendBuff[2048] = {0};
        UpgradeInfo *info = infoList->linuxota;
        if (info->has_version) {
            memcpy(linuxOTA.version, info->version.data, info->version.len);
            CrLogI("version = %s", linuxOTA.version);
            memcpy(linuxOTA.url, info->url.data, info->url.len);
            CrLogI("url = %s", linuxOTA.url);
            memcpy(linuxOTA.name, info->name.data, info->name.len);
            CrLogI("name = %s", linuxOTA.name);
            linuxOTA.size = info->size;
            CrLogI("size = %d", linuxOTA.size);
            linuxOTA.isForce = info->force;
            CrLogI("force = %d", linuxOTA.isForce);
            
            char manual[info->manual.len + 10];
            bzero(manual, sizeof(manual));
            memcpy(manual, info->manual.data, info->manual.len);
            CrLogI("upgrade info = %s\n", manual);
            snprintf(sendBuff, 2048, "1%s\t%s\t%d\t%s", systemComfig.sys_version, linuxOTA.version, linuxOTA.size, manual);
        }
        else {
            snprintf(sendBuff, 2048, "1");
        }
        UserGetCmdResponse(UI_GET_DEVICE_UPGRADE_INFO, strlen(sendBuff) + 1, sendBuff);
    }
    // 判断是否有linux 本地新版本
    if (infoList->linuxlocal)
    {
        CrLogI("get linux local upgrade info");
        memset(&linuxLocal, 0, sizeof(FirmwareInfo_t));

        char sendBuff[2048] = {0};
        UpgradeInfo *info = infoList->linuxlocal;
        if (info->has_version) {
            memcpy(linuxLocal.version, info->version.data, info->version.len);
            CrLogI("version = %s", linuxLocal.version);
            memcpy(linuxLocal.name, info->name.data, info->name.len);
            CrLogI("name = %s", linuxLocal.name);
            linuxLocal.size = info->size;
            CrLogI("size = %d", linuxLocal.size);
            memcpy(linuxLocal.path, info->imagepath.data, info->imagepath.len);
            CrLogI("path = %s\n", linuxLocal.path);
            snprintf(sendBuff, 2048, "2%s\t%s\t%d\t", systemComfig.sys_version, linuxLocal.version, linuxLocal.size);
        }
        else {
            snprintf(sendBuff, 2048, "2");
        }
        UserGetCmdResponse(UI_GET_DEVICE_UPGRADE_INFO, strlen(sendBuff) + 1, sendBuff);
    }
    // 判断是否有mcu OTA新版本
    if (infoList->mcu1ota)
    {
        CrLogI("get mcu ota upgrade info");
        memset(&mcuOTA, 0, sizeof(FirmwareInfo_t));

        char sendBuff[2048] = {0};
        UpgradeInfo *info = infoList->mcu1ota;
        if (info->has_version) {
            memcpy(mcuOTA.version, info->version.data, info->version.len);
            CrLogI("version = %s", mcuOTA.version);
            memcpy(mcuOTA.url, info->url.data, info->url.len);
            CrLogI("url = %s", mcuOTA.url);
            memcpy(mcuOTA.name, info->name.data, info->name.len);
            CrLogI("name = %s", mcuOTA.name);
            mcuOTA.size = info->size;
            CrLogI("size = %d", mcuOTA.size);
            mcuOTA.isForce = info->force;
            CrLogI("force = %d", mcuOTA.isForce);
            
            char manual[info->manual.len + 10];
            bzero(manual, sizeof(manual));
            memcpy(manual, info->manual.data, info->manual.len);
            CrLogI("upgrade info = %s\n", manual);
            snprintf(sendBuff, 2048, "3%s\t%s\t%d\t%s", systemComfig.fw_version, mcuOTA.version, mcuOTA.size, manual);
        }
        else {
            snprintf(sendBuff, 2048, "3");
        }
        UserGetCmdResponse(UI_GET_DEVICE_UPGRADE_INFO, strlen(sendBuff) + 1, sendBuff);
    }
    // 判断是否有mcu 本地新版本
    if (infoList->mcu1local)
    {
        CrLogI("get mcu local upgrade info");
        memset(&mcuLocal, 0, sizeof(FirmwareInfo_t));

        char sendBuff[2048] = {0};
        UpgradeInfo *info = infoList->mcu1local;
        if (info->has_version) {
            memcpy(mcuLocal.version, info->version.data, info->version.len);
            CrLogI("version = %s", mcuLocal.version);
            memcpy(mcuLocal.name, info->name.data, info->name.len);
            CrLogI("name = %s", mcuLocal.name);
            mcuLocal.size = info->size;
            CrLogI("size = %d", mcuLocal.size);
            memcpy(mcuLocal.path, info->imagepath.data, info->imagepath.len);
            CrLogI("name = %s\n", mcuLocal.path);
            snprintf(sendBuff, 2048, "4%s\t%s\t%d\t", systemComfig.fw_version, mcuLocal.version, mcuLocal.size);
        }
        else {
            snprintf(sendBuff, 2048, "4");
        }
        UserGetCmdResponse(UI_GET_DEVICE_UPGRADE_INFO, strlen(sendBuff) + 1, sendBuff);
    }

    upgrade_info_list__free_unpacked(infoList, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetUserCxyInfoAns(MsgHeadBuf_t *head)
{
    CrLogI("User Get User Cxy Info Ans");
    GeneralRes *res = general_res__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }

    // 提取信息
    char sendBuff[2048] = {0};
    strcat(sendBuff, "6");
    CrLogI("get userinfo result = %d", res->result);

    if (res->result)
    {
        CrLogI("get userinfo from file");
        // 判断用户信息是否存在，读取文件，获取json数据
        if (access(GetUserIotTbInfoFilePtah(), F_OK) == 0)
        {
            // 从文件读取数据
            char *getStr = AesDecryptFromFile(GetUserIotTbInfoFilePtah());
            json_object *tbInfo = NULL;
            if (getStr && (tbInfo = json_tokener_parse(getStr)))
            {
                json_object *userinfo = json_object_object_get(tbInfo, "cxy_user_info");
                if (userinfo)
                {
                    // 提取用户名
                    json_object *singleobj = json_object_object_get(userinfo, "nickName");
                    const char *nickName = json_object_get_string(singleobj);
                    strcat(sendBuff, nickName);
                    strcat(sendBuff, "\t");

                    //用户ID
                    singleobj = json_object_object_get(userinfo, "userId");
                    const char *userId = json_object_get_string(singleobj);
                    strcat(sendBuff, userId);
                    strcat(sendBuff, "\t");

                    // 用户缩略图
                    singleobj = json_object_object_get(userinfo, "avatar_png");
                    const char *avatarPng = json_object_get_string(singleobj);
                    CrLogI("avatar path = %s", avatarPng);
                    // 将jpeg格式图片转换成png格式
                    char outPath[256] = {0};
                    strcat(outPath, avatarPng);
                    char *endStr = strstr(outPath, ".jpg");
                    if (endStr) {
                        memcpy(endStr, ".png\0", strlen(".png") + 1);
                        JpegToPng(avatarPng, outPath, 1); // 将jpeg格式图片转换成png格式
                    }

                    strcat(sendBuff, outPath);
                    CrLogI("sendBuff = \n%s\n", sendBuff);
                }
                else CrLogW("no userinfo object\n");
                json_object_put(tbInfo);
            }
            else CrLogW("read json object fail\n");

            // 释放资源
            if (getStr) free(getStr);
        }
        else CrLogW("cxy user info no exist\n");
    }

    // 返回结果
    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
    general_res__free_unpacked(res, NULL);
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
        char sendBuff[32] = {0};
        snprintf(sendBuff, sizeof(sendBuff), "1%d", pre->sw);
        UserGetCmdResponse(UI_GET_CAMERA_PARAMETERS, strlen(sendBuff) + 1, sendBuff);
    }
    if (pre->has_location) {
        CrLogI("delay image prefer location = %d", pre->location);
        char sendBuff[32] = {0};
        snprintf(sendBuff, sizeof(sendBuff), "2%d", pre->location);
        UserGetCmdResponse(UI_GET_CAMERA_PARAMETERS, strlen(sendBuff) + 1, sendBuff);
    }
    if (pre->has_interval) {
        CrLogI("delay image prefer interval = %d", pre->interval);
        char sendBuff[32] = {0};
        snprintf(sendBuff, sizeof(sendBuff), "3%d", pre->interval);
        UserGetCmdResponse(UI_GET_CAMERA_PARAMETERS, strlen(sendBuff) + 1, sendBuff);
    }
    if (pre->has_frame) {
        CrLogI("delay image prefer frame = %d", pre->frame);
        char sendBuff[32] = {0};
        snprintf(sendBuff, sizeof(sendBuff), "4%d", pre->frame);
        UserGetCmdResponse(UI_GET_CAMERA_PARAMETERS, strlen(sendBuff) + 1, sendBuff);
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
    CrLogI("power loss prefer; sw = %d", pre->sw);
    char sendBuff[32] = {0};
    snprintf(sendBuff, sizeof(sendBuff), "1%d", pre->sw);
    UserGetCmdResponse(UI_GET_POWER_LOSS_PARA, strlen(sendBuff) + 1, sendBuff);

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
    CrLogI("ai control prefer; sw = %d, detection = %d, pauseprint = %d, firstfloor = %d, flowdetect = %d, aimode = %d, pastatime = %d",
        pre->sw, pre->detection, pre->pauseprint, pre->firstfloor, pre->flowdetect, pre->aimode, pre->pastatime);
    char sendBuff[64] = {0};
    snprintf(sendBuff, sizeof(sendBuff), "1%d\t%d\t%d\t%d\t%d\t%d\t%d",
        pre->sw, pre->detection, pre->pauseprint, pre->firstfloor, pre->flowdetect, pre->aimode, pre->pastatime);
    UserGetCmdResponse(UI_GET_AI_CONTROL_PARA, strlen(sendBuff) + 1, sendBuff);

    ai_control_prefer__free_unpacked(pre, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlPrintAns(MsgHeadBuf_t *head)
{
    DisControlPrint *res = dis_control_print__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }

    // 不同指令响应区分处理
    if (res->connectwifi || res->connectsavewifi)
    {
        char sendBuff[2048] = {0};
        switch (res->result) {
            case WIFI_CONNECT_FAIL: strcat(sendBuff, "0"); break;
            case WIFI_CONNECT_SUCCESS: strcat(sendBuff, "1"); break;
            case WIFI_CONNECT_ING: strcat(sendBuff, "2"); break;
            case WIFI_CONNECT_WRONG_PASSWORD: strcat(sendBuff, "3"); break;
            case WIFI_CONNECT_TIME_OUT: strcat(sendBuff, "4"); break;
            case WIFI_CONNECT_NO_SSID: strcat(sendBuff, "5"); break;
        }
        UserSetCmdResponse(UI_SET_WIFI_OPERATE, strlen(sendBuff) + 1, sendBuff);
    }
    else if (res->has_resonancetest)
    {
        char sendBuff[2048] = {0};
        snprintf(sendBuff, 2048, "3%d", res->result);
        UserSetCmdResponse(UI_SET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
    }
    else if (res->has_autolevel)
    {
        char sendBuff[2048] = {0};
        snprintf(sendBuff, 2048, "2%d", res->result);
        UserSetCmdResponse(UI_SET_LEVELING_CONTROL, strlen(sendBuff) + 1, sendBuff);
    }
    else if (res->has_returnhome)
    {
        // 判断保存指令，是否是轴归位指令
        char resStr = 0;
        if (saveDisSetData[0] >= 'A' && saveDisSetData[0] <= 'E') resStr = saveDisSetData[0];
        else resStr = 'E';

        char sendBuff[2048] = {0};
        snprintf(sendBuff, 2048, "%c%d", resStr, res->result);
        UserSetCmdResponse(UI_SET_CONTROL_AXIS_MOVE, strlen(sendBuff) + 1, sendBuff);
    }
    else if (res->has_axismove)
    {
        char sendBuff[2048] = {0};
        if (saveDisSetFlag == UI_SET_IN_AND_OUT_MATERIAL) {
            snprintf(sendBuff, 2048, "%d", res->result);
            UserSetCmdResponse(UI_SET_IN_AND_OUT_MATERIAL, strlen(sendBuff) + 1, sendBuff);
        }
        else {
            // 判断保存指令，是否是轴移动指令
            char resStr = 0;
            if (saveDisSetData[0] >= 'X' && saveDisSetData[0] <= 'Z') resStr = saveDisSetData[0];
            else resStr = 'Z';

            snprintf(sendBuff, 2048, "%c%d", resStr, res->result);
            UserSetCmdResponse(UI_SET_CONTROL_AXIS_MOVE, strlen(sendBuff) + 1, sendBuff); 
        }
    }
    else if (res->has_consolectl)
    {
        char sendBuff[res->consolectl.len + 10];
        bzero(sendBuff, sizeof(sendBuff));
        memcpy(sendBuff, res->consolectl.data, res->consolectl.len);
        CrLogI("consolectl result = %s", sendBuff);
        UserSetCmdResponse(UI_SET_KLIPPER_CONSOLE_CMD, strlen(sendBuff) + 1, sendBuff);
    }
    else if (res->has_uploadlocalvideo)
    {
        CrLogI("upload local video result = %d", res->result);
        char sendBuff[2048] = {0};
        if (res->has_result && res->result) snprintf(sendBuff, 2048, "31");
        else snprintf(sendBuff, 2048, "32");
        UserSetCmdResponse(UI_SET_USER_EXPORT_LOG, strlen(sendBuff) + 1, sendBuff);
    }
    else if (res->has_lasercalibration)
    {
        CrLogI("laser calibration result = %d\n", res->result);
        char sendBuff[2048] = {0};
        if (res->has_result && res->result) snprintf(sendBuff, 2048, "a1");
        else snprintf(sendBuff, 2048, "a2");
        UserSetCmdResponse(UI_SET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
    }
    else if(res->has_result && res->result)
    {
        UserSetCmdResponse(saveDisSetFlag, saveDisSetDataLen, saveDisSetData);
    }
    dis_control_print__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserUploadLocalLogAns(MsgHeadBuf_t *head)
{
    MutableTypeData *res = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!res) {
        CrLogW("unpack failed\n");
        return;
    }

    // 解析上传结果
    char idBuff[100] = {0};
    int uiResult = EXPORT_LOG_FAIL;
    if(res->has_int_v){
        int result = res->int_v;
        CrLogI("upload local log result = %d", result);
        if (result == 1) uiResult = EXPORT_LOG_SUCCESS;
        else if(result == 2) uiResult = EXPORT_STOPLOG_SUCCESS;
    }
    if(res->has_bytes_v){
        memcpy(idBuff, res->bytes_v.data, res->bytes_v.len);
    }

    DevSendCurUploadLogStateToDis(uiResult, 0, idBuff);
    uiStartUploadLog = false;
    mutable_type_data__free_unpacked(res, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserGetGsensorExistAns(MsgHeadBuf_t *head)
{
    MultiGsensor *gsensorRes = multi_gsensor__unpack(NULL, head->bufLen, head->buf);
    if (!gsensorRes) {
        CrLogW("unpack failed\n");
        return;
    }

    // 解析获取结果
    char sendBuff[100] = {0};
    if (gsensorRes->has_multi_gsensor_all) {
        snprintf(sendBuff, 100, "31\t%d", gsensorRes->multi_gsensor_all);
    }
    else if (gsensorRes->has_multi_gsensor_x) {
        snprintf(sendBuff, 100, "32\t%d", gsensorRes->multi_gsensor_x);
    }
    if (gsensorRes->has_multi_gsensor_y) {
        snprintf(sendBuff, 100, "33\t%d", gsensorRes->multi_gsensor_y);
    }

    UserGetCmdResponse(UI_GET_DEVICE_STATE_PUSH, strlen(sendBuff) + 1, sendBuff);
    multi_gsensor__free_unpacked(gsensorRes, NULL);
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


static void UploadLaserTestImagePath(MsgHeadBuf_t *head)
{
    char img_path[128]={0};
    char version[128]={0};
    CrLogI("UploadLaserTestImagePath = %s\n", head->buf);
    if('1'==head->buf[0]){
        snprintf(img_path,sizeof(img_path),"%s",head->buf+2);
        set_step1_image(img_path);
    }else if('2'==head->buf[0]){
        snprintf(img_path,sizeof(img_path),"%s",head->buf+2);
        set_step2_image(img_path);
    }else if('3'==head->buf[0]){
        snprintf(img_path,sizeof(img_path),"%s",head->buf+2);
        set_step1_laser_cali_status(img_path);
    }else if('5'==head->buf[0]){
        snprintf(img_path,sizeof(img_path),"%s",head->buf+4);
        int num = atoi(head->buf+2);
        flow_test_show_result(num, img_path);
    }else if('7'==head->buf[0]){
        char status[128]={0};
        snprintf(status,sizeof(status),"%s",head->buf+2);
        CrLogI("laser pressure test status = %s \n",status);
        set_laser_pressure_status(status);
    }else if('8'==head->buf[0]){
        snprintf(img_path,sizeof(img_path),"%s",head->buf+2);
        set_step2_laser_cali_status(img_path);
    }
    else if('9'==head->buf[0]){
        snprintf(version,sizeof(version),"%s",head->buf+2);
        set_laser_version_label(version);
    }
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
        CrLogI("package len = %ld, origin %d, cmd %d, message len %ld", headSize, head.origin, head.cmd, head.bufLen);

        ui_pthread_mutex_lock();
        switch (head.cmd)
        {
            case SERVER_CMD_DIS_AUTO_PID_CONFIRM_REQ: ServerSendAutoPidConfirmToDis(&head); break;
            case SERVER_CMD_DIS_SYNC_AUTO_LEVEL_RESULT: ServerSyncAutoLevelResultToDis(&head); break;
            case SERVER_CMD_DIS_SYNC_UPGRADE_STATE: ServerSyncUpgradeStateToDis(&head); break;
            case SERVER_CMD_DIS_SYNC_FILE_COPY_PROGRESS: ServerSyncFileCopyProgressToDis(&head); break;
            
            case SERVER_CMD_DIS_TEST_REQ: ServerMessageTestReq(&head); break;

            case SERVER_CMD_DIS_GET_SYSTEM_CONFIG_ANS: ManagerSyncSystemConfig(&head); break;
            case SERVER_CMD_DIS_GET_PRINT_SAVE_PARA_ANS: ManagerSyncPrintSavePara(&head); break;
            case SERVER_CMD_DIS_GET_DEVICE_STATE_ANS: SyncDeviceStateToDis(&head); break;
            case SERVER_CMD_DIS_GET_POWER_LOSS_ANS: ManagerSyncPowerLossInfo(&head); break;
            case SERVER_CMD_DIS_GET_UPGRADE_REBOOT_ANS: ManagerSyncUpgradeRebootInfo(&head); break;
            case SERVER_CMD_DIS_GET_PRINT_OBJECT_ANS: ManagerSyncPrintObjectInfo(&head); break;

            case SERVER_CMD_DIS_GET_LOCAL_GCODE_ANS: UserGetLocalGcodeAns(&head); break;
            case SERVER_CMD_DIS_GET_LOCAL_IMAGE_ANS: UserGetLocalImageAns(&head); break;
            case SERVER_CMD_DIS_GET_LOCAL_PHOTO_ANS: UserGetLocalPhotoAns(&head); break;
            case SERVER_CMD_DIS_GET_LOCALTION_ANS: UserGetLocaltionAns(&head); break;
            case SERVER_CMD_DIS_GET_MATERIAL_PRE_ANS: UserGetMaterialPreferAns(&head); break;
            case SERVER_CMD_DIS_GET_AUTO_PID_PRE_ANS: UserGetAutoPidPreferAns(&head); break;
            case SERVER_CMD_DIS_GET_WIFI_INFO_ANS: UserGetWifiInfoAns(&head); break;
            case SERVER_CMD_DIS_GET_WIFI_SCAN_ANS: UserGetWifiScanListAns(&head); break;
            case SERVER_CMD_DIS_GET_UPGRADE_INFO_ANS: UserGetUpgradeInfoAns(&head); break;
            case SERVER_CMD_DIS_GET_USER_CXY_INFO_ANS: UserGetUserCxyInfoAns(&head); break;
            case SERVER_CMD_DIS_GET_DELAY_IMAGE_PRE_ANS: UserGetDelayImagePreAns(&head); break;
            case SERVER_CMD_DIS_GET_POWER_LOSS_PRE_ANS: UserGetPowerLossPreAns(&head); break;
            case SERVER_CMD_DIS_GET_AI_CONTROL_PRE_ANS: UserGetAiControlPreAns(&head); break;
            case SERVER_CMD_DIS_GET_PRINT_WORK_INFO_ANS: ServerSyncPrintWorkInfoToDis(&head); break;
            case SERVER_CMD_DIS_UPLOAD_LOCAL_LOG_ANS: UserUploadLocalLogAns(&head); break;
            case SERVER_CMD_DIS_GET_GSENSOR_EXIST_ANS: UserGetGsensorExistAns(&head); break;

            case SERVER_CMD_DIS_CONTROL_PRINT_ANS: UserControlPrintAns(&head); break;

            case MANAGER_CMD_MESSAGE_TEST: ManagerMessageTest(&head); break;
            case SERVER_CMD_DIS_SET_LASER_TEST_START_ANS: UploadLaserTestImagePath(&head); break;
            default:
            {
                CrLogW("msg cmd file !!! origin %d, cmd %d\n", head.origin, head.cmd);
                break;
            }
        }
        ui_pthread_mutex_unlock();
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
static void DisInitiativeSyncManagerData(void)
{
    // 同步Linux系统配置
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_SYSTEM_CONFIG_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 */
static void DisInitiativeSyncPrintSavePara(void)
{
    // 同步打印机保存参数
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_PRINT_SAVE_PARA_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 */
static void DisInitiativeSyncDeviceState(void)
{
    // 同步打印机保存参数
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_DEVICE_STATE_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 */
static void DisInitiativeSyncWorkInfo(void)
{
    // 同步打印机打印任务信息
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_PRINT_WORK_INFO_REQ, "", 0);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 */
static void DisInitiativeSyncPrintObject(void)
{
    // 同步打印对象信息
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_PRINT_OBJECT_RES, "", 0);
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
    managerMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_DISPLAY_MANAGER);
    if (managerMsgId == -1)
    {
        CrLogE("create manager msg queue fail\n");
    }
    serverMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_DISPLAY_SERVER);
    if (serverMsgId == -1)
    {
        CrLogE("create manager msg queue fail\n");
    }
    // 清空消息队列
    CleanMessageQueue();
    // 同步manager数据
    DisInitiativeSyncManagerData();
    DisInitiativeSyncPrintSavePara();
    DisInitiativeSyncDeviceState();
    DisInitiativeSyncWorkInfo();
    DisInitiativeSyncPrintObject();

    while (1)
    {
        MsgUpdata();
        usleep(1000 * 10);
    }

    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {int} sw
 */
static void ScreenDisplayControl(int sw)
{
#ifdef CROSS_COMPILE
    char *setCmd = NULL;
    if (sw) setCmd = GetDefaultScreenDisplayOn();
    else setCmd = GetDefaultScreenDisplayOff();

    char resBuf[32] = {0};
    CrLogI("screen display control = %s", setCmd);
    // 设置
    if (!PopenSystem(setCmd, resBuf, sizeof(resBuf)))
        CrLogW("set screen value fail !!\n");
#endif
}

/**
 * @description: 
 * @return {*}
 */
static void DetectStartupFullScreen(void)
{
    // 判断是否开启全屏, 非工作状态不启动
    if (!systemComfig.full_screen || printRunState.workState != APP_PRINT_STATE_WORK) {
        startupFullScreenCount = 0;
        return;
    }

    // 延时启动全屏
    if (startupFullScreenCount < STARTUP_FULL_SCREEN_TIME + 10) {
        if (++startupFullScreenCount == STARTUP_FULL_SCREEN_TIME)
        {
            CrLogI("startup full screen ...!");
            DevSendStartupFullScreenToDis(NULL);
        }
    }
}

/**
 * @description: 
 * @return {*}
 */
static void DetectStartupScreenSaver(void)
{
    // 判断是否开启屏保
    if (!systemComfig.screensaver || systemComfig.self_test_sw) {
        startupScreenSaverCount = 0;
        return;
    }

    // 延时启动屏保
    int startupTime = ONE_MINUTE_COUNT_TIME * systemComfig.screensaver;
    if (startupScreenSaverCount < startupTime + 10) {
        if (++startupScreenSaverCount == startupTime)
        {
            CrLogI("startup screen saver ...!");
            DevSendStartupScreenSaverToDis(NULL);
            ScreenDisplayControl(0);
        }
    }
}

/**
 * @description: 运行线程
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
static void *RunThread(void *arg)
{
    while (1)
    {
        DetectStartupFullScreen();
        DetectStartupScreenSaver();
        usleep(1000 * 10);
    }

    return NULL;
}

/**
 * @description: 
 * @return {*}
 */
static void SetUdisFileInfokMonitor(void)
{
    // 添加U盘文件信息监听
    if (!udisFileInfoMonitor && access(GetUserUdiskGcodeFileInfoPtah(), F_OK) == 0)
    {
        CrLogI("add U disk file info monitor");
        if (!inotifytools_watch_recursively(GetUserUdiskGcodeFileInfoPtah(), IN_MODIFY)) {
            CrLogW("inotifytools_watch_recursively failed\n");
        }
        udisFileInfoMonitor = true;

        // 添加将文件信息自动同步到交互端
        CrLogI("test sync udisk file info");
    }
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

    // 添加将文件信息自动同步到交互端
    CrLogI("test sync local file info");

    // 添加U盘文件信息监听
    if (access(GetUserUdiskGcodeFileInfoPtah(), F_OK) == 0) {
        if (!inotifytools_watch_recursively(GetUserUdiskGcodeFileInfoPtah(), IN_MODIFY)) {
            CrLogW("inotifytools_watch_recursively failed\n");
        }
        udisFileInfoMonitor = true;

        // 添加将文件信息自动同步到交互端
        CrLogI("test sync udisk file info");
    }

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

        // 解析监听事件
        switch (event->mask)
        {
            // 文件变化，同步到交互端
            case IN_MODIFY:
            {
                if (strstr(changePath, GetUserLocalGcodeInfoDirPtah())) {
                    // 同步本地文件
                    CrLogI("test sync local file info");
                }
                else if (strstr(changePath, GetUserUdiskGcodeInfoDirPtah())) {
                    // 同步U盘文件
                    CrLogI("test sync udisk file info");
                }
                break;
            }
            default: CrLogI("event->mask = %d\n", event->mask); break;
        }
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
int *ServerMessageInit(void *arg)
{
    CrLogI("display server init");
    pthread_mutex_init(&uiThreadLock, NULL);

    // 新开线程接收数据
    pthread_t handle;
    int res = pthread_create(&handle, NULL, (void*)MessageThread, arg);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return NULL;
    }

    // 创建任务运行线程
    pthread_t RunHandle;
    res = pthread_create(&RunHandle, NULL, (void*)RunThread, arg);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return NULL;
    }

    // 创建获取gcode线程
    pthread_t gcodeHandle;
    res = pthread_create(&gcodeHandle, NULL, (void*)GetGcodeThread, arg);
    if (res) {
        CrLogE("create pthread error!\n");
    }

    return 0;  
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

/**
 * @description: 
 * @return {*}
 * @param {char} *recv
 */
static int GetGcodeFileOperations(char *recv)
{
    // 分解参数
    char *operate = strtok(recv, "\t");
    if (!operate) {
        CrLogW("no find operate cmd\n");
        return -1;
    }

    // 区分不同操作处理
    switch (operate[0]) {
        case '0':
        {
            // 分解参数
            char *ansPath = strtok(NULL, "\t");
            if (!ansPath) {
                CrLogW("no find traverse path\n");
                break;
            }
            char *ansSort = strtok(NULL, "\t");
            if (!ansSort) {
                CrLogW("no find sort by\n");
                break;
            }
                    
            // 获取扫描路径
            if (ansPath[0] == 'C') {
                // 返回上一级目录
                if (strlen(currentTraversePath) <= 0) {
                    CrLogW("First get the root directory file once\n");
                    break;
                }
                char *end = strrchr(currentTraversePath, '/');
                if (end) memset(end, 0, strlen(end));
            }
            else if (ansPath[0] != 'D')
            {
                memset(currentTraversePath, 0, sizeof(currentTraversePath)/sizeof(currentTraversePath[0]));
                // 获取本机目录
                if (ansPath[0] == 'A')
                    strcat(currentTraversePath, printRunState.sdPath);
                // 获取U盘目录
                else if (ansPath[0] == 'B')
                    strcat(currentTraversePath, printRunState.uDiskPath);
                // 获取子目录
                else if (isdigit(ansPath[0]))
                {
                    int lineCount = 0;
                    json_object *fileInfo = GetFileInfoToIdFromCache(GetUserGcodeFileInfoFilePath(), atoi(ansPath), &lineCount);
                    if (fileInfo)
                    {
                        // 判断选中ID是否是文件夹
                        json_object *typeObj = json_object_object_get(fileInfo, "type");
                        if (typeObj || json_object_is_type(typeObj, json_type_int)) {
                            if (json_object_get_int(typeObj) != CACHE_PATH_TYPE_DIR) {
                                CrLogW("The current ID points to not a folder\n");
                                break;
                            }
                        }
                        // 获取子目录名称
                        json_object *nameObj = json_object_object_get(fileInfo, "fileName");
                        if (nameObj || json_object_is_type(nameObj, json_type_string))
                            strcat(currentTraversePath, json_object_get_string(nameObj));
                        else CrLogW("get file name fail\n");
                        json_object_put(fileInfo);
                    }
                    else CrLogW("No subdirectory with this id exists\n");
                }
                // 均不存在，默认获取本机目录
                else strcat(currentTraversePath, printRunState.sdPath);
            }

             // 获取排序方式
            int sortBy = FILE_NAME_POSITIVE_SORT;
            switch (ansSort[0]) {
                case '0': sortBy = FILE_NAME_POSITIVE_SORT; break;
                case '1': sortBy = FILE_SIZE_POSITIVE_SORT; break;
                case '2': sortBy = FILE_TIME_REVERSE_SORT; break;
                case '3': sortBy = FILE_NAME_REVERSE_SORT; break;
                case '4': sortBy = FILE_SIZE_REVERSE_SORT; break;
                case '5': sortBy = FILE_TIME_POSITIVE_SORT; break;
            }

            CrLogI("traverse sort = %d, path = %s", sortBy, currentTraversePath);
            // 开始获取
            GetGcodeFIleList getList = GET_GCODE_FILE_LIST__INIT;
            getList.has_path = 1;
            getList.path.data = (uint8_t*)currentTraversePath;
            getList.path.len = strlen(currentTraversePath) + 1;
            getList.has_sort = 1;
            getList.sort = sortBy;

            GET_MESSAGE_BUFF(buff);
            size_t len = get_gcode_file_list__pack(&getList, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_LOCAL_GCODE_REQ, buff, len);
            SendProcessMsgBuff(&send, size);
            break;
        }
        case '1':
        {
            // 分解参数
            char *startIdStr = strtok(NULL, "\t");
            if (!startIdStr) {
                CrLogW("no find start id\n");
                break;
            }
            char *endIdStr = strtok(NULL, "\t");
            if (!endIdStr) {
                CrLogW("no find end id\n");
                break;
            }

            // 获取ID范围
            uint32_t fileListStartId = atoi(startIdStr);
            uint32_t fileListEndId = atoi(endIdStr);
            CrLogI("fileListStartId = %d, fileListEndId = %d", fileListStartId, fileListEndId);

            // 校验参数
            if (fileListStartId > fileListEndId)
            {
                CrLogI("select id Scope error; start = %d, end = %d\n", fileListStartId, fileListEndId);
                break;
            }

            LocalGcodeInfo image = LOCAL_GCODE_INFO__INIT;
            image.has_optstart = 1;
            image.optstart = fileListStartId;
            image.has_optend = 1;
            image.optend = fileListEndId;

            GET_MESSAGE_BUFF(buff);
            size_t len = local_gcode_info__pack(&image, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_LOCAL_IMAGE_REQ, buff, len);
            SendProcessMsgBuff(&send, size);
            break;
        }
        case '2':
        {
            // 分解参数
            char *getPara = strtok(NULL, "\t");
            if (!getPara) {
                CrLogW("no find get para\n");
                break;
            }

            // 获取ID
            uint32_t selectFileId = atoi(getPara);
            CrLogI("user select gcode file id = %d", selectFileId);

            // 根据文件ID获取文件名
            int lineCount = 0;
            char fileName[256] = {0};
            json_object *fileInfo = GetFileInfoToIdFromCache(GetUserGcodeFileInfoFilePath(), selectFileId, &lineCount);
            if (fileInfo) {
                json_object *nameObj = json_object_object_get(fileInfo, "fileName");
                if (nameObj || json_object_is_type(nameObj, json_type_string))
                    strcat(fileName, json_object_get_string(nameObj));
                json_object_put(fileInfo);
            }
            CrLogI("choose print file = %s", fileName);

            // 发送命令
            SendString getPhoto = SEND_STRING__INIT;
            getPhoto.str.data = (uint8_t*)fileName;
            getPhoto.str.len = strlen(fileName) + 1;

            GET_MESSAGE_BUFF(buff);
            size_t len = send_string__pack(&getPhoto, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_LOCAL_PHOTO_REQ, buff, len);
            SendProcessMsgBuff(&send, size);
            break;
        }
        case '5':
        {
            DevSendCurrentPrintWorkInfoToDis(NULL);
            break;
        }
        case '6':
        {
            DevSendCurSelftestToDis(NULL);
            break;
        }
        default: CrLogW("Error control instruction\n"); break;
    }

    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *recv
 */
static int GetHistoryRecordOperations(char *recv)
{
    // 分解参数
    char *operate = strtok(recv, "\t");
    if (!operate) {
        CrLogW("no find operate cmd\n");
        return -1;
    }
    
    // 区分不同操作处理
    switch (operate[0]) {
        case '0':
        {
            UserGetHistoryRecordSumAns(NULL);
            break;
        }
        case '1':
        {
            // 分解参数
            char *startIdStr = strtok(NULL, "\t");
            if (!startIdStr) {
                CrLogW("no find start id\n");
                break;
            }
            char *endIdStr = strtok(NULL, "\t");
            if (!endIdStr) {
                CrLogW("no find end id\n");
                break;
            }

            // 获取ID范围
            uint32_t historyStartId = atoi(startIdStr);
            uint32_t historyEndId = atoi(endIdStr);
            CrLogI("historyStartId = %d, historyEndId = %d", historyStartId, historyEndId);

            // 校验参数
            if (historyStartId > historyEndId)
            {
                CrLogI("select id Scope error; start = %d, end = %d\n", historyStartId, historyEndId);
                break;
            }
            UserGetHistoryRecordAns(historyStartId, historyEndId);
            break;
        }
        case '2':
        {
            // 获取设置参数
            char *setPara = strtok(NULL, "\t");
            if (!setPara) {
                CrLogW("no find set para\n");
                break;
            }
            // 根据文件ID获取文件名
            uint32_t fileId = atoi(setPara);
            CrLogI("dis set start print, file id = %d", fileId);

            CrLogI("get history record from file");
            // 判断历史记录是否存在，读取文件，获取json数据
            if (access(GetuserPrintHistoryRecordPtah(), F_OK) != 0) {
                CrLogW("no history record\n");
                break;
            }
            // 提取历史记录
            json_object *historyRecord = json_object_from_file(GetuserPrintHistoryRecordPtah());
            if (!historyRecord) {
                CrLogW("read json object fail\n");
                break;
            }
            // 提取历史记录列表
            json_object *listObj = json_object_object_get(historyRecord, "list");
            if (!listObj) {
                CrLogW("read list object fail\n");
                json_object_put(historyRecord);
                break;
            }
            // 获取指定历史记录
            json_object *record = json_object_array_get_idx(listObj, fileId - 1);
            if (!record) {
                CrLogW("read history object fail\n");
                json_object_put(historyRecord);
                break;
            }

            // 提取文件名
            json_object *fileName = json_object_object_get(record, "filename");
            if (!fileName) {
                CrLogW("read name object fail\n");
                json_object_put(historyRecord);
                break;
            }

            // 获取文件名
            char result[256] = {0};
            strcat(result, json_object_get_string(fileName));
            json_object_put(historyRecord);
            
            //从本地文件列表查询文件信息
            CrLogI("get historyfile from local file,%s",result);
            if (access(result, F_OK) != 0) {
                CrLogW("gcode file no exist\n");
                break;
            }

            // 判断本地是否存在，读取文件，获取json数据
            if (access(GetUserLocalGcodeFileInfoPtah(), F_OK) != 0) {
                CrLogW("no local record\n");
                break;
            }
            // 提取本地文件信息
            json_object *localfile = json_object_from_file(GetUserLocalGcodeFileInfoPtah());
            if (!localfile) {
                CrLogW("read json object fail\n");
                break;
            }

            char sendbuff[1024] = {0};
            strcat(sendbuff, "22\t");
            for (int i = 0; i < json_object_array_length(localfile); i++)
            {
                json_object *singlefile = json_object_array_get_idx(localfile, i);
                json_object *name = json_object_object_get(singlefile, "path");
                if(strcmp(json_object_get_string(name), result) == 0)   //找到目标json
                {
                    name = json_object_object_get(singlefile, "name");
                    const char *filename = json_object_get_string(name);
                    strcat(sendbuff,filename);
                    strcat(sendbuff, "\t");

                    name = json_object_object_get(singlefile, "bedTemp");
                    const char *bedTemp = json_object_get_string(name);
                    strcat(sendbuff, bedTemp);
                    strcat(sendbuff, "\t");

                    name = json_object_object_get(singlefile, "nozzleTemp");
                    const char *nozzleTemp = json_object_get_string(name);
                    strcat(sendbuff, nozzleTemp);
                    strcat(sendbuff, "\t");

                    name = json_object_object_get(singlefile, "timeCost");
                    const char *timeCost = json_object_get_string(name);
                    strcat(sendbuff, timeCost);
                    strcat(sendbuff, "\t");

                    name = json_object_object_get(singlefile, "consumables");
                    const char *consumables = json_object_get_string(name);
                    strcat(sendbuff, consumables);
                    strcat(sendbuff, "\t");

                    name = json_object_object_get(singlefile, "preview");
                    const char *preview = json_object_get_string(name);
                    strcat(sendbuff, preview);
                    strcat(sendbuff, "\t");

                    strcat(sendbuff, setPara);//打印历史记录索引
                    strcat(sendbuff, "\t");

                    name = json_object_object_get(singlefile, "material");
                    const char *material1 = json_object_get_string(name);
                    strcat(sendbuff, material1);
                    break;
                }
            }

            json_object_put(localfile);
            UserGetCmdResponse(UI_GET_DEV_GCODE_FILE_PATH, strlen(sendbuff) + 1, sendbuff);
            break;
        }   
        default: CrLogW("Error control instruction\n"); break;
    }

    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *recv
 */
static int GetDelayImageOperations(char *recv)
{
    // 分解参数
    char *operate = strtok(recv, "\t");
    if (!operate) {
        CrLogW("no find operate cmd\n");
        return -1;
    }
    
    // 区分不同操作处理
    switch (operate[0]) {
        case '0':
        {
            UserGetDelayImageSumAns(NULL);
            break;
        }
        case '1':
        {
            // 分解参数
            char *startIdStr = strtok(NULL, "\t");
            if (!startIdStr) {
                CrLogW("no find start id\n");
                break;
            }
            char *endIdStr = strtok(NULL, "\t");
            if (!endIdStr) {
                CrLogW("no find end id\n");
                break;
            }

            // 获取ID范围
            uint32_t imageStartId = atoi(startIdStr);
            uint32_t imageEndId = atoi(endIdStr);
            CrLogI("imageStartId = %d, imageEndId = %d", imageStartId, imageEndId);

            // 校验参数
            if (imageStartId > imageEndId)
            {
                CrLogI("select id Scope error; start = %d, end = %d\n", imageStartId, imageEndId);
                break;
            }
            UserGetDelayImageAns(imageStartId, imageEndId);
            break;
        }
        default: CrLogW("Error control instruction\n"); break;
    }

    return -1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {unsigned char} flag
 * @param {unsigned char} len
 * @param {char} *data
 */
int GetPrinterDataFromManager(unsigned char flag, unsigned char dataLen, char *data)
{
    char tempBuff[1024] = {0};
    CrLogI("GetPrinter flag = %d, len = %d", flag, dataLen);
    if (data) {
        memcpy(tempBuff, data, dataLen);
        CrLogI("display get cmd data = %s", tempBuff);
    }

    switch (flag)
    {
        case UI_GET_DEV_GCODE_FILE_PATH:
        {
            CrLogI("UI_GET_DEV_GCODE_FILE_PATH");
            switch (tempBuff[0])
            {
                case '1': GetGcodeFileOperations(&tempBuff[1]); break;
                case '2': GetHistoryRecordOperations(&tempBuff[1]); break;
                case '3': GetDelayImageOperations(&tempBuff[1]); break;
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_GET_DEV_AXIS_RECOUP_DATA:
        {
            CrLogI("UI_GET_DEV_AXIS_RECOUP_DATA");
            DevSendCurAxisRecoupToDis(NULL);
            break;
        }
        case UI_GET_CUR_HOTEND_BED_TEMP:
        {
            CrLogI("UI_GET_CUR_HOTEND_BED_TEMP");
            DevSendCurTempToDis(NULL);
            break;
        }
        case UI_GET_CUR_NOZZLE_XYZ_LOCAL:
        {
            CrLogI("UI_GET_CUR_NOZZLE_XYZ_LOCAL");
            DevSendCurLocationToDis(NULL);
            // CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_LOCALTION_REQ, "", 0);
            // SendProcessMsgBuff(&send, size);
            break;
        }
        case UI_GET_PLA_ABS_WARM_UP_TEMP:
        {
            CrLogI("UI_GET_PLA_ABS_WARM_UP_TEMP");
            MaterialPrefer *temp[1];
            temp[0] = malloc(sizeof(MaterialPrefer));
            material_prefer__init(temp[0]);

            switch (tempBuff[0]) {
                case '0': temp[0]->id = 1; break;
                case '1': temp[0]->id = 2; break;
                case '2': temp[0]->id = 3; break;
                default: CrLogW("Error control instruction\n"); break;
            }

            MaterialPreferList list = MATERIAL_PREFER_LIST__INIT;
            list.n_list = 1;
            list.list = temp;

            GET_MESSAGE_BUFF(buff);
            size_t len = material_prefer_list__pack(&list, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_MATERIAL_PRE_REQ, buff, len);
            SendProcessMsgBuff(&send, size);
            free (temp[0]);
            break;
        }
        case UI_GET_DEVICE_CONFIG_STATE:
        {
            CrLogI("UI_GET_DEVICE_CONFIG_STATE");
            switch (tempBuff[0])
            {
                case '0': DevSendCurFanToDis(NULL); break;
                case '1': DevSendCurLightStateToDis(NULL); break;
                case '2': DevSendCurWifiStateToDis(NULL); break;
                case '4': DevSendCurAutoPowerOffSwToDis(NULL); break;
                case '7': DevSendCurMaterialStatusToDis(NULL); break;
                case '8': DevSendCurPowerLossSwToDis(NULL); break;
                case '9': DevSendCurSelfTestSwToDis(NULL); break;
                case 'a': DevSendCurSoundSwToDis(NULL); break;
                case 'b': DevSendCurScreensacerSwToDis(NULL);break;
                case 'c': DevSendCurDisplayThemeToDis(NULL); break;
                case 'd': DevSendCurMotorStateToDis(NULL); break;
                case 'e': DevSendCurScreenBrightnessToDis(NULL); break;
                case 'h': DevSendCurSoundSizeToDis(NULL); break;
                case 'i': DevSendCurSoundFfectToDis(NULL); break;
                case 'j': DevSendCurFullScreenToDis(NULL); break;
                case 'l': DevSendCurQmodeStatusToDis(NULL); break;
                case 'm': DevSendDeviceTimezoneToDis(NULL); break;
                case 'n': DevSendServerConfigToDis(NULL); break;
                case 'o': DevSendUpgradeRemindToDis(NULL); break;
                case 'p': DevSendServerLocalToDis(NULL); break;
                case 'q': DevSendAgreePrivacyToDis(NULL); break;
                case 's': DevSendDataCollectToDis(NULL); break;
            }
            break;
        }
        case UI_GET_CURRENT_WIFI_INFO:
        {
            CrLogI("UI_GET_CURRENT_WIFI_INFO");
            switch (tempBuff[0])
            {
                case '1': {
                    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_WIFI_INFO_REQ, "", 0);
                    SendProcessMsgBuff(&send, size);
                    break;
                }
                case '2': {
                    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_WIFI_SCAN_REQ, "", 0);
                    SendProcessMsgBuff(&send, size);
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_GET_AUTO_LEVELING_DATA:
        {
            CrLogI("UI_GET_AUTO_LEVELING_DATA");
            switch (tempBuff[0])
            {
                case '4': DevSendCurAutoLevelPointsToDis(NULL); break;
                case '5': DevSendCurCrTouchStateToDis(NULL); break;
                case '6': break;
                case '7': DevSendCurAutoLevelValueToDis(NULL); break;
                case '9': DevSendBedMeshInfoToDis(NULL); break;
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_GET_DEV_SPORTS_PARAMETER:
        {
            CrLogI("UI_GET_DEV_SPORTS_PARAMETER");
            switch (tempBuff[0])
            {
                case '1': DevSendCurSportsParaToDis(1); break;
                case '2': DevSendCurSportsParaToDis(2); break;
                case '3': DevSendCurSportsParaToDis(3); break;
                case '4': DevSendCurSportsParaToDis(4); break;
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_GET_ORGIN_OFFSET_DATA:
        {
            CrLogI("UI_GET_ORGIN_OFFSET_DATA");
            DevSendCurAxisOffsetToDis(NULL);
            break;
        }
        case UI_GET_AUTO_PID_PARA:
        {
            CrLogI("UI_GET_AUTO_PID_PARA");
            TempAutoPidPrefer *temp[1];
            temp[0] = malloc(sizeof(TempAutoPidPrefer));
            temp_auto_pid_prefer__init(temp[0]);

            switch (tempBuff[0]) {
                case '0': temp[0]->id = 1; break;
                case '1': temp[0]->id = 2; break;
                default: CrLogW("Error control instruction\n"); break;
            }

            TempAutoPidPreferList list = TEMP_AUTO_PID_PREFER_LIST__INIT;
            list.n_list = 1;
            list.list = temp;

            GET_MESSAGE_BUFF(buff);
            size_t len = temp_auto_pid_prefer_list__pack(&list, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_AUTO_PID_PRE_REQ, buff, len);
            SendProcessMsgBuff(&send, size);
            free (temp[0]);
            break;
        }
        case UI_GET_TEMP_PID_PARA:
        {
            CrLogI("UI_GET_TEMP_PID_PARA");
            DevSendCurTempPidToDis(NULL);
            break;
        }
        case UI_GET_CURRENT_PRINT_STATE:
        {
            CrLogI("UI_GET_CURRENT_PRINT_STATE");
            switch (tempBuff[0])
            {
                case '0': DevSendCurWorkStateToDis(NULL); break;
                case '1': DevSendCurProgressToDis(NULL); break;
            }
            break;
        }
        case UI_GET_PRINT_DOUBLE_SPEED:
        {
            CrLogI("UI_GET_PRINT_DOUBLE_SPEED");
            DevSendCurPrintSpeedToDis(NULL);
            break;
        }
        case UI_GET_CURRENT_LANGUAGE:
        {
            CrLogI("UI_GET_CURRENT_LANGUAGE");
            DevSendCurLanguageToDis(NULL);
            break;
        }
        case UI_GET_HOT_BED_SIZE:
        {
            CrLogI("UI_GET_HOT_BED_SIZE");
            DevSendCurHotBedSizeToDis(NULL);
            break;
        }
        case UI_GET_REPEAT_PRINT_TIMES:
        {
            CrLogI("UI_GET_REPEAT_PRINT_TIMES");
            break;
        }
        case UI_GET_DEVICE_ALL_INFO:
        {
            CrLogI("UI_GET_DEVICE_ALL_INFO");
            DevSendDeviceAllInfoToDis(NULL);
            break;
        }
        case UI_GET_CXY_BINDING_QRCODE:
        {
            CrLogI("UI_GET_CXY_BINDING_QRCODE");
            switch (tempBuff[0])
            {
                case '1': DevSendBindingQrcodeToDis(NULL); break;
                case '2': DevSendUserServiceQrcodeToDis(NULL); break;
            }
            break;
        }
        case UI_GET_PRINT_FLOW_PARA:
        {
            CrLogI("UI_GET_PRINT_FLOW_PARA");
            DevSendCurPrintFlowToDis(NULL);
            break;
        }
        case UI_GET_HOME_AXES_STATE:
        {
            CrLogI("UI_GET_HOME_AXES_STATE");
            DevSendCurHomedAxesToDis(NULL);
            break;
        }
        case UI_GET_DEVICE_UPGRADE_INFO:
        {
            CrLogI("UI_GET_DEVICE_UPGRADE_INFO");
            UpgradeInfo otaInfo = UPGRADE_INFO__INIT;
            UpgradeInfoList infoList = UPGRADE_INFO_LIST__INIT;

            switch (tempBuff[0])
            {
                case '1': infoList.linuxota = &otaInfo;     break;
                case '2': infoList.linuxlocal = &otaInfo;   break;
                case '3': infoList.mcu1ota = &otaInfo;      break;
                case '4': infoList.mcu1local = &otaInfo;    break;
                default: CrLogW("Error control instruction\n"); break;
            }

            GET_MESSAGE_BUFF(buff);
            size_t len = upgrade_info_list__pack(&infoList, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_UPGRADE_INFO_REQ, buff, len);
            SendProcessMsgBuff(&send, size);
            break;
        }
        case UI_GET_DEVICE_STATE_PUSH:
        {
            CrLogI("UI_GET_DEVICE_STATE_PUSH");
            switch (tempBuff[0])
            {
                case '3': {
                    MultiGsensor gsensor = MULTI_GSENSOR__INIT;
                    switch (tempBuff[1])
                    {
                        case '1': gsensor.has_multi_gsensor_all = 1;  break;
                        case '2': gsensor.has_multi_gsensor_x = 1;  break;
                        case '3': gsensor.has_multi_gsensor_y = 1;  break;
                        default: gsensor.has_multi_gsensor_all = 1;  break;
                    }

                    GET_MESSAGE_BUFF(buff);
                    size_t len = multi_gsensor__pack(&gsensor, buff);
                    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_GSENSOR_EXIST_RES, buff, len);
                    SendProcessMsgBuff(&send, size);
                    break;
                }
                case '4': DevSendCurUDiskToDis(NULL); break;
                case '5': DevSendCurCameraToDis(NULL); break;
                case '6':
                {
                    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_USER_CXY_INFO_REQ, "", 0);
                    SendProcessMsgBuff(&send, size);
                    break;
                }
                case '7': DevSendCurSerialPortStateToDis(NULL);break;
                case '8': DevSendCurFanStateToDis(NULL);break;
                case '9': DevSendCurExistFanFeedbackToDis(NULL); break;
                case 'a': DevSendCurlaserExistsToDis(NULL); break;
                case 'b': DevSendCurMqttConnectStateToDis(NULL); break;
                case 'c': ManagerSyncPrintObjectInfo(NULL); break;
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_GET_CAMERA_PARAMETERS:
        {
            CrLogI("UI_GET_CAMERA_PARAMETERS");
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_DELAY_IMAGE_PRE_REQ, "", 0);
            SendProcessMsgBuff(&send, size);
            break;
        }
        case UI_GET_POWER_LOSS_PARA:
        {
            CrLogI("UI_GET_POWER_LOSS_PARA");
            switch (tempBuff[0])
            {
                case '1':
                {
                    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_POWER_LOSS_PRE_REQ, "", 0);
                    SendProcessMsgBuff(&send, size);
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_GET_AI_CONTROL_PARA:
        {
            CrLogI("UI_GET_AI_CONTROL_PARA");
            switch (tempBuff[0])
            {
                case '1':
                {
                    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_GET_AI_CONTROL_PRE_REQ, "", 0);
                    SendProcessMsgBuff(&send, size);
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_GET_XYZ_AXIS_RANGE:
        {
            CrLogI("UI_GET_XYZ_AXIS_RANGE");
            switch (tempBuff[0])
            {
                case '1': DevSendXYZAxisRangeToDis(NULL); break;
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }

        default: CrLogW("ui get data cmd fail!; cmd = [%d]\n", flag); break;
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {MaterialPrefer} *temp
 * @param {char} *buff
 */
static int CreateSetMaterialPrefer(int id, MaterialPrefer *temp, char *buff)
{
    temp->id = id;
    switch (buff[0])
    {
        case '1': {
            temp->has_hotendtemp = 1;
            temp->hotendtemp = atof(&buff[1]);
            break;
        }
        case '2': {
            temp->has_bedtemp = 1;
            temp->bedtemp = atof(&buff[1]);
            break;
        }
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {int} state
 * @param {int} progress
 */
static void SyncExportLogState(int state, int progress)
{
    ExportLogState sync = EXPORT_LOG_STATE__INIT;
    sync.state = state;
    sync.progress = progress;

    GET_MESSAGE_BUFF(buff);
    size_t len = export_log_state__pack(&sync, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_SYNC_EXPORT_LOG_STATE, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {int} progress
 * @param {void} *userPtr
 */
static void ExportLogProgress(int progress, void *userPtr)
{
    CrLogI("export log progress = %d", progress);
    SyncExportLogState(EXPORTING_LOGS, progress);
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *LogCompressionThread(void *arg)
{
    SyncExportLogState(COMPRESSING_LOG, 0);
    
    // 判断用户是否指定路径
    char *savePath = NULL;
    if (strlen(logOutputPath) > 0) savePath = logOutputPath;
    else savePath = printRunState.uDiskPath;

    // 获取当前时间戳
    struct timeval startTime;
    gettimeofday(&startTime, NULL);
    struct tm *CurTime = localtime(&startTime.tv_sec);

    // 创建压缩包文件名称（包含绝对路径）
    char filePath[256] = {0};
    snprintf(filePath , sizeof(filePath) ,"%s/%d-%02d-%02d_%02d-%02d-%02d_creality_log.7z",
        savePath, CurTime->tm_year + 1900, CurTime->tm_mon + 1,
        CurTime->tm_mday, CurTime->tm_hour, CurTime->tm_min, CurTime->tm_sec);
    CrLogI("7z savePath = %s", filePath);
    
    // 获取系统信息
    GetSaveSystemInfoToFile(GetTempSaveSystemInfoPath());
    
    // 构建压缩命令
    char exportLogCmd[512] = {0};
    snprintf(exportLogCmd, sizeof(exportLogCmd), GetDefaultLog7zCompressionScript(),
        LOG_DECOMPRESSION_PASSWORD, GetTempExportLog7z(), GetUserDataLogDirPtah(), GetUserDataKlipperLogDirPtah(),
        GetDefaultSystemKernelLogPtah(), GetUserDataConfigDirPtah(), GetTempSaveSystemInfoPath());
    CrLogI("export log cmd = %s\n", exportLogCmd);

    // 压缩日志
    char sysRes[1024] = {0};
    if (!PopenSystem(exportLogCmd, sysRes, sizeof(sysRes))){
        CrLogW("system fail! res = %s\n", sysRes);
        SyncExportLogState(EXPORT_LOG_FAIL, 0);
    }
    else {
        CrLogI("export log result = %s\n", sysRes);
        // 判断U盘是否存在
        if (access(printRunState.uDiskPath, F_OK) != 0) {
            CrLogW("U disk no exist \n");
            DevSendCurExportLogStateToDis(EXPORT_LOG_UDISK_NO_EXIT, 0);
            SyncExportLogState(EXPORT_LOG_FAIL, 0);
        }
        else {
            // 导出到U盘
            SyncExportLogState(EXPORTING_LOGS, 0);
            file_setCallback(ExportLogProgress, NULL);
            if (file_copyFileToDir(GetTempExportLog7z(), filePath) == 0) {
                SyncExportLogState(EXPORT_LOG_SUCCESS, 0);
            }
            else {
                SyncExportLogState(EXPORT_LOG_FAIL, 0);
            }
        }

        // 清除临时文件
        if (access(GetTempExportLog7z(), F_OK) == 0) remove(GetTempExportLog7z());
    }
    system("sync");

    // 结束线程，释放资源
    logOutputRuning = false;
    pthread_detach(pthread_self());
    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *path
 */
static void UserExportLogToUdisk(char *path)
{
    // 判断U盘是否存在
    if (access(printRunState.uDiskPath, F_OK) != 0) {
        CrLogW("U disk no exist \n");
        DevSendCurExportLogStateToDis(EXPORT_LOG_UDISK_NO_EXIT, 0);
        return;
    }

    // 判断是否正在导出日志
    if (logOutputRuning) {
        CrLogW("log output runing!!\n");
        return;
    }
    logOutputRuning = true;

    // 保存日志输出路径
    bzero(logOutputPath, sizeof(logOutputPath));
    strcat(logOutputPath, path);

    // 创建日志压缩线程
    pthread_t logHandle;
    if (pthread_create(&logHandle, NULL, (void*)LogCompressionThread, NULL)) {
        CrLogE("create pthread error!\n");
        DevSendCurExportLogStateToDis(EXPORT_LOG_FAIL, 0);
        return;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {char} *fileName
 * @param {int} fileId
 */
static int GetFileNameByFileId(char *fileName, int fileId)
{
    // 提取文件
    int lineCount = 0;
    json_object *fileInfo = GetFileInfoToIdFromCache(GetUserGcodeFileInfoFilePath(), fileId, &lineCount);
    if (!fileInfo) {
        CrLogW("get json object fail\n");
        return -1;
    }

    // 提取文件名
    json_object *name = json_object_object_get(fileInfo, "fileName");
    if (!name) {
        CrLogW("read name object fail\n");
        json_object_put(fileInfo);
        return -1;
    }

    // 获取文件名
    strcat(fileName, json_object_get_string(name));
    json_object_put(fileInfo);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {int} progress
 * @param {void} *userPtr
 */
static void copyProgress(int progress, void *userPtr)
{
    int pro = (100 / selectFileCollectionNum * curSelectFileCount) + (progress * 1.00 / selectFileCollectionNum);
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "12\t%d", pro);
    ui_pthread_mutex_lock();
    UserSetCmdResponse(UI_SET_START_PRINT_FILE, strlen(sendBuff) + 1, sendBuff);
    ui_pthread_mutex_unlock();
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *UserCopyGcodeThread(void *arg)
{
    // 判断是否存在复制文件目标路径
    if (copyFileTargetPath == NULL) {
        CrLogW("gcode copy target path fail\n");
        return NULL;
    }

    // 复制文件
    bool copyFileSuccess = true;
    file_setCallback(copyProgress, NULL);
    for (int i = 0; i < selectFileCollectionNum; i++) {
        curSelectFileCount = i;
        // 获取临时文件路径
        char tempPath[256] = {0};
        strcat(tempPath, copyFileTargetPath);
        strcat(tempPath, strrchr(selectFileCollection[i], '/'));
        strcat(tempPath, ".temp");
        CrLogI("tempPath = %s", tempPath);
        file_copyFileToDir(selectFileCollection[i], tempPath);

        // 获取源文件MD5
        char sourceFileMd5[256] = {0};
        getFileMD5(selectFileCollection[i], sourceFileMd5);
        // 获取新文件MD5
        char targetFileMd5[256] = {0};
        getFileMD5(tempPath, targetFileMd5);
        CrLogI("sourceFileMd5 = %s", sourceFileMd5);
        CrLogI("targetFileMd5 = %s\n", targetFileMd5);

        // 判断复制文件完整新
        if (strcmp(sourceFileMd5, targetFileMd5) != 0) {
            CrLogW("copy file fail!\n");
            if (remove(tempPath) != 0) CrLogW("remove gcode fail\n");
            copyFileSuccess = false;
            break;
        }

        // 重命名文件
        char newFilePath[256] = {0};
        strcat(newFilePath, copyFileTargetPath);
        strcat(newFilePath, strrchr(selectFileCollection[i], '/'));
        if (rename(tempPath, newFilePath) != 0) CrLogW("rename gcode fail\n");
    }
    system("sync");

    curSelectFileCount = 0;
    selectFileCollectionNum = 0;
    bzero(selectFileCollection, sizeof(selectFileCollection));

    // 判断结果
    int result = -1;
    if (copyFileSuccess) result = 101;
    // 应答
    char sendBuff[100] = {0};
    snprintf(sendBuff, sizeof(sendBuff), "12\t%d", result);
    ui_pthread_mutex_lock();
    UserSetCmdResponse(UI_SET_START_PRINT_FILE, strlen(sendBuff) + 1, sendBuff);
    ui_pthread_mutex_unlock();

    copyFileTargetPath = NULL;
    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *UserDeleteGcodeThread(void *arg)
{
    // 删除文件
    for (int i = 0; i < selectFileCollectionNum; i++) {
        remove(selectFileCollection[i]);
        curSelectFileCount++;

        char sendBuff[100] = {0};
        snprintf(sendBuff, 100, "13\t%d", (int)(curSelectFileCount * 1.00 / selectFileCollectionNum));
        ui_pthread_mutex_lock();
        UserSetCmdResponse(UI_SET_START_PRINT_FILE, strlen(sendBuff) + 1, sendBuff);
        ui_pthread_mutex_unlock();  
    }

    curSelectFileCount = 0;
    selectFileCollectionNum = 0;
    bzero(selectFileCollection, sizeof(selectFileCollection));

    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "13\t%d", 100);
    ui_pthread_mutex_lock();
    UserSetCmdResponse(UI_SET_START_PRINT_FILE, strlen(sendBuff) + 1, sendBuff);
    ui_pthread_mutex_unlock();

    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *recv
 * @param {char} *result
 */
static int SetGcodeFileOperations(char *recv, char *result, int *calibration)
{
    // 分解参数
    char *operate = strtok(recv, "\t");
    if (!operate) {
        CrLogW("no find operate cmd\n");
        return -1;
    }

    // 区分不同操作处理
    switch (operate[0]) {
        case '1':
        {
            // 获取设置参数
            char *setPara = strtok(NULL, "\t");
            if (!setPara) {
                CrLogW("no find set para\n");
                break;
            }
            char *calibrationPara = strtok(NULL, "\t");
            if (!calibrationPara) {
                CrLogW("no find set para\n");
                break;
            }
            *calibration = atoi(calibrationPara);

            // 根据文件ID获取文件名
            uint32_t fileId = atoi(setPara);
            CrLogI("dis set start print, file id = %d", fileId);
            GetFileNameByFileId(result, fileId);
            CrLogI("choose print file = %s", result);
            return 0;
        }
        case '2':
        {
            curSelectFileCount = 0;
            selectFileCollectionNum = 0;
            bzero(selectFileCollection, sizeof(selectFileCollection));

            // 判断U盘是否存在
            if (access(printRunState.uDiskPath, F_OK) != 0) {
                CrLogW("U disk no exist \n");

                char sendBuff[100] = {0};
                snprintf(sendBuff, sizeof(sendBuff), "12\t%d", -1);
                UserSetCmdResponse(UI_SET_START_PRINT_FILE, strlen(sendBuff) + 1, sendBuff);
                break;
            }

            // 获取复制文件目标路径
            char *setPara = strtok(NULL, "\t");
            if (setPara) {
                if (atoi(setPara) == 1) copyFileTargetPath = printRunState.uDiskPath;
                else if (atoi(setPara) == 2) copyFileTargetPath = printRunState.sdPath;
                else CrLogW("Error control instruction\n");
            }

            // 获取文件名称
            setPara = strtok(NULL, "\t");
            while (setPara)
            {
                // 根据文件ID获取文件名
                uint32_t fileId = atoi(setPara);
                CrLogI("detect file id = %d", fileId);
                GetFileNameByFileId(selectFileCollection[selectFileCollectionNum++], fileId);
                setPara = strtok(NULL, "\t");
            }

            // 创建操作线程
            pthread_t handle;
            if (pthread_create(&handle, NULL, (void*)UserCopyGcodeThread, NULL)) {
                CrLogE("create pthread error!\n");
                break;
            }
            pthread_detach(handle);
            break;
        }
        case '3':
        {
            curSelectFileCount = 0;
            selectFileCollectionNum = 0;
            bzero(selectFileCollection, sizeof(selectFileCollection));

            // 获取文件名称
            char *setPara = strtok(NULL, "\t");
            while (setPara)
            {
                // 根据文件ID获取文件名
                uint32_t fileId = atoi(setPara);
                CrLogI("detect file id = %d", fileId);
                GetFileNameByFileId(selectFileCollection[selectFileCollectionNum++], fileId);
                setPara = strtok(NULL, "\t");
            }

            // 创建操作线程
            pthread_t handle;
            if (pthread_create(&handle, NULL, (void*)UserDeleteGcodeThread, NULL)) {
                CrLogE("create pthread error!\n");
                break;
            }
            pthread_detach(handle);
            break;
        }
        
        default: CrLogW("Error control instruction\n"); break;
    }

    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *recv
 * @param {char} *result
 * @param {int} *calibration
 */
static int SetHistoryRecordOperations(char *recv, char *result, int *calibration)
{
    // 分解参数
    char *operate = strtok(recv, "\t");
    if (!operate) {
        CrLogW("no find operate cmd\n");
        return -1;
    }

    // 区分不同操作处理
    switch (operate[0]) {
        case '1':
        {
            // 获取设置参数
            char *setPara = strtok(NULL, "\t");
            if (!setPara) {
                CrLogW("no find set para\n");
                break;
            }
            char *calibrationPara = strtok(NULL, "\t");
            if (!calibrationPara) {
                CrLogW("no find set para\n");
                break;
            }
            *calibration = atoi(calibrationPara);

            // 根据文件ID获取文件名
            uint32_t fileId = atoi(setPara);
            CrLogI("dis set start print, file id = %d", fileId);

            CrLogI("get history record from file");
            // 判断历史记录是否存在，读取文件，获取json数据
            if (access(GetuserPrintHistoryRecordPtah(), F_OK) != 0) {
                CrLogW("no history record\n");
                break;
            }
            // 提取历史记录
            json_object *historyRecord = json_object_from_file(GetuserPrintHistoryRecordPtah());
            if (!historyRecord) {
                CrLogW("read json object fail\n");
                break;
            }
            // 提取历史记录列表
            json_object *listObj = json_object_object_get(historyRecord, "list");
            if (!listObj) {
                CrLogW("read list object fail\n");
                json_object_put(historyRecord);
                break;
            }
            // 获取指定历史记录
            json_object *record = json_object_array_get_idx(listObj, fileId - 1);
            if (!record) {
                CrLogW("read history object fail\n");
                json_object_put(historyRecord);
                break;
            }
            // 提取文件名
            json_object *name = json_object_object_get(record, "filename");
            if (!name) {
                CrLogW("read name object fail\n");
                json_object_put(historyRecord);
                break;
            }
            // 获取文件名
            strcat(result, json_object_get_string(name));
            json_object_put(historyRecord);
            CrLogI("choose print file = %s", result);
            return 0;
        }
        default: CrLogW("Error control instruction\n"); break;
    }

    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *videoName
 * @param {int} videoId
 */
static int GetVideoNameByVideoId(char *videoName, int videoId)
{
    json_object *delayImage = json_object_from_file(GetUserDelayImageInfoPtah());
    if (delayImage) {
        // 提取延时摄影列表
        json_object *listObj = json_object_object_get(delayImage, "list");
        // 获取文件名
        json_object *image = json_object_array_get_idx(listObj, (videoId - 1));
        const char *filePath = json_object_get_string(json_object_object_get(image, "video"));
            
        strcat(videoName, filePath);
        json_object_put(delayImage);
    }
    else CrLogW("read json object fail\n");

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {int} progress
 * @param {void} *userPtr
 */
static void copyVideoProgress(int progress, void *userPtr)
{
    int pro = (100 / selectFileCollectionNum * curSelectFileCount) + (progress * 1.00 / selectFileCollectionNum);
    char sendBuff[100] = {0};
    snprintf(sendBuff, 100, "32\t%d", pro);
    ui_pthread_mutex_lock();
    UserSetCmdResponse(UI_SET_START_PRINT_FILE, strlen(sendBuff) + 1, sendBuff);
    ui_pthread_mutex_unlock();
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *UserCopyVideoThread(void *arg)
{
    // 判断是否存在复制文件目标路径
    if (copyFileTargetPath == NULL) {
        CrLogW("gcode copy target path fail\n");
        return NULL;
    }

    // 复制文件
    bool copyFileSuccess = true;
    file_setCallback(copyVideoProgress, NULL);
    for (int i = 0; i < selectFileCollectionNum; i++) {
        curSelectFileCount = i;
        // 获取临时文件路径
        char tempPath[256] = {0};
        strcat(tempPath, copyFileTargetPath);
        strcat(tempPath, strrchr(selectFileCollection[i], '/'));
        strcat(tempPath, ".temp");
        CrLogI("tempPath = %s", tempPath);
        file_copyFileToDir(selectFileCollection[i], tempPath);

        // 获取源文件MD5
        char sourceFileMd5[256] = {0};
        getFileMD5(selectFileCollection[i], sourceFileMd5);
        // 获取新文件MD5
        char targetFileMd5[256] = {0};
        getFileMD5(tempPath, targetFileMd5);
        CrLogI("sourceFileMd5 = %s", sourceFileMd5);
        CrLogI("targetFileMd5 = %s\n", targetFileMd5);

        // 判断复制文件完整新
        if (strcmp(sourceFileMd5, targetFileMd5) != 0) {
            CrLogW("copy file fail!\n");
            if (remove(tempPath) != 0) CrLogW("remove gcode fail\n");
            copyFileSuccess = false;
            break;
        }

        // 重命名文件
        char newFilePath[256] = {0};
        strcat(newFilePath, copyFileTargetPath);
        strcat(newFilePath, strrchr(selectFileCollection[i], '/'));
        if (rename(tempPath, newFilePath) != 0) CrLogW("rename gcode fail\n");
    }
    system("sync");

    curSelectFileCount = 0;
    selectFileCollectionNum = 0;
    bzero(selectFileCollection, sizeof(selectFileCollection));

    // 判断结果
    int result = -1;
    if (copyFileSuccess) result = 101;
    // 应答
    char sendBuff[100] = {0};
    snprintf(sendBuff, sizeof(sendBuff), "32\t%d", result);
    ui_pthread_mutex_lock();
    UserSetCmdResponse(UI_SET_START_PRINT_FILE, strlen(sendBuff) + 1, sendBuff);
    ui_pthread_mutex_unlock();

    copyFileTargetPath = NULL;
    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *recv
 */
static int SetDelayImageOperations(char *recv)
{
    // 分解参数
    char *operate = strtok(recv, "\t");
    if (!operate) {
        CrLogW("no find operate cmd\n");
        return -1;
    }

    // 区分不同操作处理
    switch (operate[0]) {
        case '2':
        {
            curSelectFileCount = 0;
            selectFileCollectionNum = 0;
            bzero(selectFileCollection, sizeof(selectFileCollection));

            // 判断U盘是否存在
            if (access(printRunState.uDiskPath, F_OK) != 0) {
                CrLogW("U disk no exist \n");
                
                char sendBuff[100] = {0};
                snprintf(sendBuff, sizeof(sendBuff), "32\t%d", -1);
                UserSetCmdResponse(UI_SET_START_PRINT_FILE, strlen(sendBuff) + 1, sendBuff);
                break;
            }

            // 获取复制文件目标路径
            char *setPara = strtok(NULL, "\t");
            if (setPara) {
                if (atoi(setPara) == 1) copyFileTargetPath = printRunState.uDiskPath;
                else if (atoi(setPara) == 2) copyFileTargetPath = printRunState.sdPath;
                else CrLogW("Error control instruction\n");
            }

            // 获取文件名称
            setPara = strtok(NULL, "\t");
            while (setPara)
            {
                // 根据文件ID获取文件名
                uint32_t fileId = atoi(setPara);
                CrLogI("detect file id = %d", fileId);
                GetVideoNameByVideoId(selectFileCollection[selectFileCollectionNum++], fileId);
                setPara = strtok(NULL, "\t");
            }

            // 创建操作线程
            pthread_t handle;
            if (pthread_create(&handle, NULL, (void*)UserCopyVideoThread, NULL)) {
                CrLogE("create pthread error!\n");
                break;
            }
            pthread_detach(handle);
            break;
        }

        default: CrLogW("Error control instruction\n"); break;
    }

    return -1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {unsigned char} flag
 * @param {unsigned char} len
 * @param {char} *data
 */
int SetPrinterDataToManager(unsigned char flag, unsigned char dataLen, char *data)
{
    // 缓存LVGL指令
    saveDisSetFlag = flag;
    saveDisSetDataLen = dataLen;
    memset(saveDisSetData, 0, sizeof(saveDisSetData)/sizeof(saveDisSetData[0]));
    memcpy(saveDisSetData, data, (dataLen<sizeof(saveDisSetData))? dataLen:(sizeof(saveDisSetData)-1));

    // 处理指令
    CrLogI("SetPrinter flag = %d, len = %d", flag, dataLen);
    char tempBuff[100] = {0};
    if (data) {
        memcpy(tempBuff, data, dataLen);
        CrLogI("display set cmd data = %s\n", tempBuff);
    }
    
    char paraBuff[256] = {0};
    DisControlPrint disControl = DIS_CONTROL_PRINT__INIT;
    MutableTypeData startPrint = MUTABLE_TYPE_DATA__INIT;
    Extruder extruder = EXTRUDER__INIT;
    HeaterBed heaterBed = HEATER_BED__INIT;
    MultiFan multiFan = MULTI_FAN__INIT;
    MaterialPrefer warmUpTemp = MATERIAL_PREFER__INIT;
    TempAutoPidPrefer tempAutoPid = TEMP_AUTO_PID_PREFER__INIT;
    NetworksInfo wifiControl = NETWORKS_INFO__INIT;
    LoadQuitMaterial material = LOAD_QUIT_MATERIAL__INIT;
    UpgradeInfo otaInfo = UPGRADE_INFO__INIT;
    UpgradeInfoList list = UPGRADE_INFO_LIST__INIT;
    SystemSetting setting = SYSTEM_SETTING__INIT;
    DelayImagePrefer imagePrefer = DELAY_IMAGE_PREFER__INIT;
    PowerLossPrefer lossPrefer = POWER_LOSS_PREFER__INIT;
    AiControlPrefer aiPrefer = AI_CONTROL_PREFER__INIT;
    MutableTypeData object = MUTABLE_TYPE_DATA__INIT;
    MutableTypeData bedMesh = MUTABLE_TYPE_DATA__INIT;

    switch (flag)
    {
        case UI_SET_START_PRINT_FILE:
        {
            CrLogI("UI_SET_START_PRINT_FILE");
            switch (tempBuff[0])
            {
                case '1':
                {
                    int calibration = 0;
                    if (SetGcodeFileOperations(&tempBuff[1], paraBuff, &calibration) == 0) {
                        CrLogI("calibration = %d, path = %s", calibration, paraBuff);
                        startPrint.has_bytes_v = 1;
                        startPrint.bytes_v.data = (uint8_t*)paraBuff;
                        startPrint.bytes_v.len = strlen(paraBuff) + 1;
                        startPrint.has_int_v = 1;
                        startPrint.int_v = calibration;
                        disControl.print = &startPrint;
                    }
                    break;
                }
                case '2':
                {
                    int calibration = 0;
                    if (SetHistoryRecordOperations(&tempBuff[1], paraBuff, &calibration) == 0) {
                        CrLogI("calibration = %d, path = %s", calibration, paraBuff);
                        startPrint.has_bytes_v = 1;
                        startPrint.bytes_v.data = (uint8_t*)paraBuff;
                        startPrint.bytes_v.len = strlen(paraBuff) + 1;
                        startPrint.has_int_v = 1;
                        startPrint.int_v = calibration;
                        disControl.print = &startPrint;
                    }
                    break;
                }
                case '3':
                {
                    if (SetDelayImageOperations(&tempBuff[1]) == 0) {
                    }
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_DEV_AXIS_RECOUP_DATA:
        {
            CrLogI("UI_SET_DEV_AXIS_RECOUP_DATA");
            snprintf(paraBuff, 256, "%s", tempBuff);
            disControl.has_axisrecoup = 1;
            disControl.axisrecoup.data = (uint8_t*)paraBuff;
            disControl.axisrecoup.len = strlen(paraBuff) + 1;
            break;
        }
        case UI_SET_HEATING_TARGET_TEMP:
        {
            CrLogI("UI_SET_HEATING_TARGET_TEMP");
            switch (tempBuff[0])
            {
                case '1':
                {
                    if (systemComfig.model == CR_10_H1) {
                        heaterBed.has_heater_bed_0 = 1;
                        heaterBed.heater_bed_0 = atoi(&tempBuff[1]);
                    }
                    else {
                        heaterBed.has_heater_bed = 1;
                        heaterBed.heater_bed = atoi(&tempBuff[1]);
                    }
                    disControl.bedtemp = &heaterBed;
                    break;
                }
                case '2':
                {
                    extruder.has_extruder = 1;
                    extruder.extruder = atoi(&tempBuff[1]);
                    disControl.nozzletemp = &extruder;
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_CONTROL_AXIS_MOVE:
        {
            CrLogI("UI_SET_CONTROL_AXIS_MOVE");
            switch (tempBuff[0])
            {
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                {
                    switch (tempBuff[0])
                    {
                        case 'A': snprintf(paraBuff, 256, "X Y"); break;
                        case 'B': snprintf(paraBuff, 256, "Z"); break;
                        case 'C': snprintf(paraBuff, 256, "X"); break;
                        case 'D': snprintf(paraBuff, 256, "Y"); break;
                        case 'E': break;
                    }
                    disControl.has_returnhome = 1;
                    disControl.returnhome.data = (uint8_t*)paraBuff;
                    disControl.returnhome.len = strlen(paraBuff) + 1;
                    break;
                }
                case 'X':
                case 'Y':
                case 'Z':
                {
                    snprintf(paraBuff, 256, "%s", tempBuff);
                    disControl.has_axismove = 1;
                    disControl.axismove.data = (uint8_t*)paraBuff;
                    disControl.axismove.len = strlen(paraBuff) + 1;
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }

            // 执行中
            char sendBuff[2048] = {0};
            snprintf(sendBuff, 2048, "%c%d", tempBuff[0], 2);
            UserSetCmdResponse(flag, strlen(sendBuff) + 1, sendBuff);
            break;
        }
        case UI_SET_WARM_UP_TEMP_PARA:
        {
            CrLogI("UI_SET_WARM_UP_TEMP_PARA");
            switch (tempBuff[0])
            {
                case '1': CreateSetMaterialPrefer(1, &warmUpTemp, &tempBuff[1]); break;
                case '2': CreateSetMaterialPrefer(2, &warmUpTemp, &tempBuff[1]); break;
                case '3': CreateSetMaterialPrefer(3, &warmUpTemp, &tempBuff[1]); break;
                default: CrLogW("Error control instruction\n"); break;
            }
            disControl.materialpre = &warmUpTemp;
            break;
        }
        case UI_SET_DEVICE_CONFIG_STATE:
        {
            CrLogI("UI_SET_DEVICE_CONFIG_STATE");
            switch (tempBuff[0])
            {
                case '0':
                {
                    // 分解参数
                    char *operate = strtok(&tempBuff[1], "\t");
                    if (!operate) {
                        CrLogW("no find operate cmd\n");
                        break;
                    }
                    char *percentage = strtok(NULL, "\t");
                    if (!percentage) {
                        CrLogW("no find traverse path\n");
                        break;
                    }

                    // 区分不同操作处理
                    switch (operate[0]) {
                        case '0': {
                            multiFan.has_multi_fan_model = 1;
                            multiFan.multi_fan_model = atoi(percentage);
                            break;
                        }
                        case '1': {
                            multiFan.has_multi_fan_case = 1;
                            multiFan.multi_fan_case = atoi(percentage);
                            break;
                        }
                        case '2': {
                            multiFan.has_multi_fan_auxiliary = 1;
                            multiFan.multi_fan_auxiliary = atoi(percentage);
                            break;
                        }
                        default: CrLogW("Error control instruction\n"); break;
                    }
                    disControl.fancontrol = &multiFan;
                    break;
                }
                case '1':
                {
                    setting.has_lightsw = 1;
                    setting.lightsw = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case '3':
                {
                    disControl.has_stopallheating = 1;
                    break;
                }
                case '4':
                {
                    setting.has_autooff = 1;
                    setting.autooff = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case '6':
                {
                    disControl.has_systemreset = 1;
                    disControl.systemreset = 0;
                    if (tempBuff[1] == '1') disControl.systemreset |= BIT0;
                    if (tempBuff[2] == '1') disControl.systemreset |= BIT1;
                    if (tempBuff[3] == '1') disControl.systemreset |= BIT2;
                    if (tempBuff[4] == '1') disControl.systemreset |= BIT3;
                    break;
                }
                case '7':
                {
                    switch (tempBuff[1])
                    {
                        case '0':
                        case '1':
                        {
                            snprintf(paraBuff, 256, "S%s", &tempBuff[1]);
                            disControl.has_materialdelect = 1;
                            disControl.materialdelect.data = (uint8_t*)paraBuff;
                            disControl.materialdelect.len = strlen(paraBuff);
                            break;
                        }

                        case '3':
                        case '4': 
                        {
                            disControl.has_insertfilament = 1;
                            break;
                        }
                    }
                    break;
                }
                case '8':
                {
                    snprintf(paraBuff, 256, "S%s", &tempBuff[1]);
                    disControl.has_powerlosssw = 1;
                    disControl.powerlosssw.data = (uint8_t*)paraBuff;
                    disControl.powerlosssw.len = strlen(paraBuff);
                    break;
                }
                case '9':
                {
                    setting.has_selftest = 1;
                    setting.selftest = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'a':
                {
                    setting.has_soundsw = 1;
                    setting.soundsw = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'b':
                {
                    setting.has_screensaver = 1;
                    setting.screensaver = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'c':
                {
                    setting.has_thememode = 1;
                    setting.thememode = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'd':
                {
                    disControl.has_motorlock = 1;
                    disControl.motorlock = atoi(&tempBuff[1]);
                    break;
                }
                case 'e':
                {
                    setting.has_screenvalue = 1;
                    setting.screenvalue = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'f':
                {
                    disControl.has_savepara = 1;
                    disControl.savepara = 1;
                    break;
                }
                case 'g':
                {
                    setting.has_uidirection = 1;
                    setting.uidirection = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'h':
                {
                    setting.has_soundsize = 1;
                    setting.soundsize = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'i':
                {
                    setting.has_soundeffect = 1;
                    setting.soundeffect = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'j':
                {
                    setting.has_fullscreen = 1;
                    setting.fullscreen = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'k':
                {
                    setting.has_lightvalue = 1;
                    setting.lightvalue = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'l':
                {
                    disControl.has_quietmode = 1;
                    disControl.quietmode = atoi(&tempBuff[1]);
                    break;
                }
                case 'm':
                {
                    setting.has_timezone = 1;
                    snprintf(paraBuff, 256, "%s", &tempBuff[1]);
                    setting.timezone.data = (uint8_t*)paraBuff;
                    setting.timezone.len = strlen(paraBuff) + 1;
                    disControl.syssetting = &setting;
                    break;
                }
                case 'n':
                {
                    setting.has_serverconfig = 1;
                    setting.serverconfig = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'o':
                {
                    setting.has_upgraderemind = 1;
                    setting.upgraderemind = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'p':
                {
                    setting.has_serverlocal = 1;
                    setting.serverlocal = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'q':
                {
                    setting.has_agreeprivacy = 1;
                    setting.agreeprivacy = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                case 'r':
                {
                    snprintf(paraBuff, 256, "%s", &tempBuff[1]);
                    setting.has_hostname = 1;
                    setting.hostname.data = (uint8_t*)paraBuff;
                    setting.hostname.len = strlen(paraBuff) + 1;
                    disControl.syssetting = &setting;
                    break;
                }
                case 's':
                {
                    setting.has_datacollect = 1;
                    setting.datacollect = atoi(&tempBuff[1]);
                    disControl.syssetting = &setting;
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_WIFI_OPERATE:
        {
            CrLogI("UI_SET_WIFI_OPERATE");
            char *tempStr = strtok(tempBuff, "\t");
            switch (tempStr[0])
            {
                case '0':
                {
                    tempStr = strtok(NULL, "\t");
                    if (tempStr)
                    {
                        CrLogI("ssid = %s", tempStr);
                        wifiControl.has_ssid = 1;
                        wifiControl.ssid.data = (uint8_t*)tempStr;
                        wifiControl.ssid.len = strlen(tempStr) + 1;
                    }
                    else CrLogW("no find wifi ssid\n");

                    tempStr = strtok(NULL, "\t");
                    if (tempStr) {
                        CrLogI("pass = %s", tempStr);
                        wifiControl.has_pass = 1;
                        wifiControl.pass.data = (uint8_t*)tempStr;
                        wifiControl.pass.len = strlen(tempStr) + 1;
                    }
                    else {
                        CrLogW("no find wifi pass\n");
                        wifiControl.has_pass = 1;
                        wifiControl.pass.data = (uint8_t*)"";
                        wifiControl.pass.len = 0;
                    }

                    disControl.connectwifi = &wifiControl;
                    break;
                }
                case '1':
                {
                    tempStr = strtok(NULL, "\t");
                    if (tempStr)
                    {
                        CrLogI("ssid = %s", tempStr);
                        wifiControl.has_ssid = 1;
                        wifiControl.ssid.data = (uint8_t*)tempStr;
                        wifiControl.ssid.len = strlen(tempStr) + 1;
                    }
                    else CrLogW("no find wifi ssid\n");
                    disControl.connectsavewifi = &wifiControl;
                    break;
                }
                case '2':
                {
                    disControl.disconnectwifi = &wifiControl;
                    break;
                }
                case '3':
                {
                    tempStr = strtok(NULL, "\t");
                    if (tempStr)
                    {
                        CrLogI("ssid = %s", tempStr);
                        wifiControl.has_ssid = 1;
                        wifiControl.ssid.data = (uint8_t*)tempStr;
                        wifiControl.ssid.len = strlen(tempStr) + 1;
                    }
                    else CrLogW("no find wifi ssid\n");
                    disControl.removewifi = &wifiControl;
                    break;
                }

                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_IN_AND_OUT_MATERIAL:
        {
            CrLogI("UI_SET_IN_AND_OUT_MATERIAL");
            switch (tempBuff[0])
            {
                case '1':
                {
                    material.has_targettemp = 1;
                    material.targettemp = atoi(&tempBuff[1]);
                    disControl.loadmaterial = &material;
                    break;
                }
                case '2':
                {
                    material.has_targettemp = 1;
                    material.targettemp = atoi(&tempBuff[1]);
                    disControl.quitmaterial = &material;
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_LEVELING_CONTROL: 
        {
            CrLogI("UI_SET_LEVELING_CONTROL");
            switch (tempBuff[0])
            {
                case '1':
                {
                    switch (tempBuff[1]) {
                        case '5': snprintf(paraBuff, 256, "X%d Y%d", systemComfig.bed_length/2, systemComfig.bed_width/2); break;
                        case '1': snprintf(paraBuff, 256, "X%d Y%d", 20, 20); break;
                        case '2': snprintf(paraBuff, 256, "X%d Y%d", systemComfig.bed_length - 20, 20); break;
                        case '3': snprintf(paraBuff, 256, "X%d Y%d", systemComfig.bed_length - 20, systemComfig.bed_width - 20); break;
                        case '4': snprintf(paraBuff, 256, "X%d Y%d", 20, systemComfig.bed_width - 20); break;
                    }
                    disControl.has_manuallevel = 1;
                    disControl.manuallevel.data = (uint8_t*)paraBuff;
                    disControl.manuallevel.len = strlen(paraBuff) + 1;
                    break;
                }
                case '2':
                {
                    disControl.has_autolevel = 1;
                    disControl.autolevel = printSavePara.levelPoints.x;
                    break;
                }
                case '4':
                {
                    switch (tempBuff[1]) {
                        case '0': snprintf(paraBuff, 256, "3"); break;
                        case '1': snprintf(paraBuff, 256, "4"); break;
                        case '2': snprintf(paraBuff, 256, "5"); break;
                        default: snprintf(paraBuff, 256, "3"); break;
                    }
                    disControl.has_autolevelpoints = 1;
                    disControl.autolevelpoints.data = (uint8_t*)paraBuff;
                    disControl.autolevelpoints.len = strlen(paraBuff);
                    break;
                }
                case '5':
                {
                    switch (tempBuff[1]) {
                        case '0': snprintf(paraBuff, 256, "P%d S10", 0); break;
                        case '1': snprintf(paraBuff, 256, "P%d S90", 0); break;
                        case '2': snprintf(paraBuff, 256, "P%d S120", 0); break;
                        case '3': snprintf(paraBuff, 256, "P%d S160", 0); break;
                    }
                    disControl.has_setcrtouch = 1;
                    disControl.setcrtouch.data = (uint8_t*)paraBuff;
                    disControl.setcrtouch.len = strlen(paraBuff);
                    break;
                }
                case '9':
                {
                    bedMesh.has_bytes_v = 1;
                    bedMesh.bytes_v.data = (uint8_t*)&tempBuff[1];
                    bedMesh.bytes_v.len = strlen(&tempBuff[1]);
                    disControl.bedmeshinfo = &bedMesh;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_DEV_SPORTS_PARAMETER:
        {
            CrLogI("UI_SET_DEV_SPORTS_PARAMETER");
            switch (tempBuff[0])
            {
                case '1':
                {
                    switch (tempBuff[1]) {
                        case '1': snprintf(paraBuff, 256, "X%s", &tempBuff[2]); break;
                        case '2': snprintf(paraBuff, 256, "Y%s", &tempBuff[2]); break;
                        case '3': snprintf(paraBuff, 256, "Z%s", &tempBuff[2]); break;
                        case '4': snprintf(paraBuff, 256, "E%s", &tempBuff[2]); break;
                    }
                    disControl.has_stepvalue = 1;
                    disControl.stepvalue.data = (uint8_t*)paraBuff;
                    disControl.stepvalue.len = strlen(paraBuff);
                    break;
                }
                case '2':
                {
                    switch (tempBuff[1]) {
                        case '1': snprintf(paraBuff, 256, "X%s", &tempBuff[2]); break;
                        case '2': snprintf(paraBuff, 256, "Y%s", &tempBuff[2]); break;
                        case '3': snprintf(paraBuff, 256, "Z%s", &tempBuff[2]); break;
                        case '4': snprintf(paraBuff, 256, "E%s", &tempBuff[2]); break;
                    }
                    disControl.has_acceleration = 1;
                    disControl.acceleration.data = (uint8_t*)paraBuff;
                    disControl.acceleration.len = strlen(paraBuff);
                    break;
                }
                case '3':
                {
                    switch (tempBuff[1]) {
                        case '1': snprintf(paraBuff, 256, "X%s", &tempBuff[2]); break;
                        case '2': snprintf(paraBuff, 256, "Y%s", &tempBuff[2]); break;
                        case '3': snprintf(paraBuff, 256, "Z%s", &tempBuff[2]); break;
                        case '4': snprintf(paraBuff, 256, "E%s", &tempBuff[2]); break;
                    }
                    disControl.has_maxjerk = 1;
                    disControl.maxjerk.data = (uint8_t*)paraBuff;
                    disControl.maxjerk.len = strlen(paraBuff);
                    break;
                }
                case '4':
                {
                    switch (tempBuff[1]) {
                        case '1': snprintf(paraBuff, 256, "X%s", &tempBuff[2]); break;
                        case '2': snprintf(paraBuff, 256, "Y%s", &tempBuff[2]); break;
                        case '3': snprintf(paraBuff, 256, "Z%s", &tempBuff[2]); break;
                        case '4': snprintf(paraBuff, 256, "E%s", &tempBuff[2]); break;
                    }
                    disControl.has_maxspeed = 1;
                    disControl.maxspeed.data = (uint8_t*)paraBuff;
                    disControl.maxspeed.len = strlen(paraBuff);
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_ORGIN_OFFSET_DATA:
        {
            CrLogI("UI_SET_ORGIN_OFFSET_DATA");
            switch (tempBuff[0]) {
                case '1': snprintf(paraBuff, 256, "X%s", &tempBuff[1]); break;
                case '2': snprintf(paraBuff, 256, "Y%s", &tempBuff[1]); break;
                case '3': snprintf(paraBuff, 256, "Z%s", &tempBuff[1]); break;
            }
            disControl.has_axisoffset = 1;
            disControl.axisoffset.data = (uint8_t*)paraBuff;
            disControl.axisoffset.len = strlen(paraBuff);
            break;
        }
        case UI_SET_START_WARM_UP_TEMP:
        {
            CrLogI("UI_SET_START_WARM_UP_TEMP");
            disControl.has_startwarmup = 1;
            switch (tempBuff[0])
            {
                case '1': disControl.startwarmup = 1; break;
                case '2': disControl.startwarmup = 2; break;
                case '3': disControl.startwarmup = 3; break;
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_AUTO_PID_PARA:
        {
            CrLogI("UI_SET_AUTO_PID_PARA");
            switch (tempBuff[0])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                {
                    switch (tempBuff[0])
                    {
                        case '1': {
                            tempAutoPid.id = 1;
                            tempAutoPid.has_temp = 1;
                            tempAutoPid.temp = atof(&tempBuff[1]);
                            break;
                        }
                        case '2': {
                            tempAutoPid.id = 1;
                            tempAutoPid.has_time = 1;
                            tempAutoPid.time = atof(&tempBuff[1]);
                            break;
                        }
                        case '3': {
                            tempAutoPid.id = 2;
                            tempAutoPid.has_temp = 1;
                            tempAutoPid.temp = atof(&tempBuff[1]);
                            break;
                        }
                        case '4': {
                            tempAutoPid.id = 2;
                            tempAutoPid.has_time = 1;
                            tempAutoPid.time = atof(&tempBuff[1]);
                            break;
                        }
                    }
                    disControl.temppidpre = &tempAutoPid;
                    break;
                }
                case '5':
                case '7':
                {
                    disControl.has_startautopid = 1;
                    switch (tempBuff[0]) {
                        case '5': disControl.startautopid = 1; break;
                        case '7': disControl.startautopid = 2; break;
                    }
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_TEMP_PID_PARA:
        {
            CrLogI("UI_SET_TEMP_PID_PARA");
            switch (tempBuff[0])
            {
                case '1':
                case '2':
                case '3':
                {
                    switch (tempBuff[0]) {
                        case '1': snprintf(paraBuff, 256, "P%s", &tempBuff[1]); break;
                        case '2': snprintf(paraBuff, 256, "I%s", &tempBuff[1]); break;
                        case '3': snprintf(paraBuff, 256, "D%s", &tempBuff[1]); break;
                    }
                    disControl.has_hotendpid = 1;
                    disControl.hotendpid.data = (uint8_t*)paraBuff;
                    disControl.hotendpid.len = strlen(paraBuff);
                    break;
                }
                case '4':
                case '5':
                case '6':
                {
                    switch (tempBuff[0]) {
                        case '4': snprintf(paraBuff, 256, "P%s", &tempBuff[1]); break;
                        case '5': snprintf(paraBuff, 256, "I%s", &tempBuff[1]); break;
                        case '6': snprintf(paraBuff, 256, "D%s", &tempBuff[1]); break;
                    }
                    disControl.has_bedpid = 1;
                    disControl.bedpid.data = (uint8_t*)paraBuff;
                    disControl.bedpid.len = strlen(paraBuff);
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_PRINT_CONTROL:
        {
            CrLogI("UI_SET_PRINT_CONTROL");
            disControl.has_printctr = 1;
            switch (tempBuff[0])
            {
                case '1': disControl.printctr = 1; break;
                case '2': disControl.printctr = 2; break;
                case '3': disControl.printctr = 3; break;
                case '4': disControl.printctr = 4; break;
                case '5': disControl.printctr = 5; break;
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_PRINT_DOUBLE_SPEED:
        {
            CrLogI("UI_SET_PRINT_DOUBLE_SPEED");
            snprintf(paraBuff, 256, "S%s", tempBuff);
            disControl.has_speedmultiple = 1;
            disControl.speedmultiple.data = (uint8_t*)paraBuff;
            disControl.speedmultiple.len = strlen(paraBuff) + 1;
            break;
        }
        case UI_SET_SYSTEM_LANGUAGE:
        {
            CrLogI("UI_SET_SYSTEM_LANGUAGE");
            setting.has_language = 1;
            setting.language = atoi(tempBuff);
            disControl.syssetting = &setting;
            break;
        }
        case UI_SET_PRINT_FLOW_PARA:
        {
            CrLogI("UI_SET_PRINT_FLOW_PARA");
            snprintf(paraBuff, 256, "S%s", tempBuff);
            disControl.has_flowmultiple = 1;
            disControl.flowmultiple.data = (uint8_t*)paraBuff;
            disControl.flowmultiple.len = strlen(paraBuff) + 1;
            break;
        }
        case UI_SET_RESTART_ERRORCODE:
        {
            CrLogI("UI_SET_RESTART_ERRORCODE");
            disControl.has_clearfaultcode = 1;
            break;
        }
        case UI_SET_RESTART_KLIPPER:
        {
            CrLogI("UI_SET_RESTART_KLIPPER");
            switch (tempBuff[0])
            {
                case '1': disControl.has_restartklipper = 1; break;
                case '2': disControl.has_firmwarerestart = 1; break;
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_START_DEVICE_UPGRADE:
        {
            CrLogI("UI_SET_START_DEVICE_UPGRADE");
            switch (tempBuff[0])
            {
                case '1':
                {
                    otaInfo.has_url = 1;
                    otaInfo.url.data = (uint8_t*)linuxOTA.url;
                    otaInfo.url.len = strlen(linuxOTA.url);
                    list.linuxota = &otaInfo;
                    break;
                }
                case '2':
                {
                    otaInfo.has_imagepath = 1;
                    otaInfo.imagepath.data = (uint8_t*)linuxLocal.path;
                    otaInfo.imagepath.len = strlen(linuxLocal.path);
                    list.linuxlocal = &otaInfo;
                    break;
                }
                case '3':
                {
                    otaInfo.has_url = 1;
                    otaInfo.url.data = (uint8_t*)mcuOTA.url;
                    otaInfo.url.len = strlen(mcuOTA.url);
                    list.mcu1ota = &otaInfo;
                    break;
                }
                case '4':
                {
                    otaInfo.has_imagepath = 1;
                    otaInfo.imagepath.data = (uint8_t*)mcuLocal.path;
                    otaInfo.imagepath.len = strlen(mcuLocal.path);
                    list.mcu1local = &otaInfo;
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            disControl.startupgrade = &list;
            break;
        }
        case UI_SET_DEVICE_STATE_PUSH:
        {
            CrLogI("UI_SET_DEVICE_STATE_PUSH");
            switch (tempBuff[0])
            {
                case '1':
                {
                    CrLogI("exit screen saver ...!");
                    startupFullScreenCount = 0; // 启动全屏计数清零
                    break;
                }
                case '2':
                {
                    CrLogI("exit screen saver ...!");
                    startupScreenSaverCount = 0; // 启动息屏计数清零
                    ScreenDisplayControl(1);
                    break;
                }
                case '3':
                {
                    CrLogI("start resonance testing");
                    disControl.has_resonancetest = 1;
                    disControl.resonancetest.data = (uint8_t*)&tempBuff[1];
                    disControl.resonancetest.len = strlen((char*)disControl.resonancetest.data) + 1;
                    break;
                }
                case '6':
                {
                    CrLogI("update user cxy info");
                    disControl.has_updateusercxyinfo = 1;
                    break;
                }
                case 'a':
                {
                    CrLogI("set laser calibration");
                    disControl.has_lasercalibration = 1;
                    // 执行中
                    char sendBuff[2048] = {0};
                    snprintf(sendBuff, 2048, "%c%d", tempBuff[0], 0);
                    UserSetCmdResponse(flag, strlen(sendBuff) + 1, sendBuff);
                    break;
                }
                case 'c':
                {
                    snprintf(paraBuff, 256, "%s", &tempBuff[1]);
                    object.has_bytes_v = 1;
                    object.bytes_v.data = (uint8_t*)paraBuff;
                    object.bytes_v.len = strlen(paraBuff);
                    disControl.excludeobject = &object;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_USER_EXPORT_LOG:
        {
            CrLogI("UI_SET_USER_EXPORT_LOG");
            switch (tempBuff[0])
            {
                case '1':
                {
                    UserExportLogToUdisk(&tempBuff[1]);
                    break;
                }
                case '2':
                {
                    CrLogI("upload local log");
                    disControl.has_uploadlocallog = 1;
                    disControl.uploadlocallog.data = (uint8_t*)"";
                    disControl.uploadlocallog.len = 0;
                    uiStartUploadLog = true;
                    break;
                }
                case '3':
                {
                    CrLogI("upload local video = %s", &tempBuff[1]);
                    int videoId = atoi(&tempBuff[1]);

                    // 获取视频地址
                    bool getFlag = false;
                    if (access(GetUserDelayImageInfoPtah(), F_OK) == 0)
                    {
                        json_object *delayImage = json_object_from_file(GetUserDelayImageInfoPtah());
                        if (delayImage)
                        {
                            // 提取延时摄影列表
                            json_object *listObj = json_object_object_get(delayImage, "list");
                            int imageSize = json_object_array_length(listObj);
                            CrLogI("imageSize = %d", imageSize);

                            // 判断索引是否有效
                            if (videoId <= imageSize) {
                                json_object *image = json_object_array_get_idx(listObj, (videoId - 1));
                                const char *filePath = json_object_get_string(json_object_object_get(image, "video"));
                                snprintf(paraBuff, 256, "%s", filePath);
                                getFlag = true;
                            }
                            json_object_put(delayImage);
                        }
                        else CrLogW("read json object fail\n");
                    }
                    else CrLogI("no delay image\n");

                    // 响应UI
                    char sendBuff[2048] = {0};
                    if (getFlag) snprintf(sendBuff, 2048, "30");
                    else snprintf(sendBuff, 2048, "32");
                    UserSetCmdResponse(UI_SET_USER_EXPORT_LOG, strlen(sendBuff) + 1, sendBuff);

                    // 启动上传
                    if (getFlag) {
                        disControl.has_uploadlocalvideo = 1;
                        disControl.uploadlocalvideo.data = (uint8_t*)paraBuff;
                        disControl.uploadlocalvideo.len = strlen(paraBuff) + 1;
                    }
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            break;
        }
        case UI_SET_CAMERA_PARAMETERS:
        {
            CrLogI("UI_SET_CAMERA_PARAMETERS");
            switch (tempBuff[0])
            {
                case '1':
                {
                    imagePrefer.has_sw = 1;
                    imagePrefer.sw = atoi(&tempBuff[1]);
                    break;
                }
                case '2':
                {
                    imagePrefer.has_location = 1;
                    imagePrefer.location = atoi(&tempBuff[1]);
                    break;
                }
                case '3':
                {
                    imagePrefer.has_interval = 1;
                    imagePrefer.interval = atoi(&tempBuff[1]);
                    break;
                }
                case '4':
                {
                    imagePrefer.has_frame = 1;
                    imagePrefer.frame = atoi(&tempBuff[1]);
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            disControl.delayimagepre = &imagePrefer;
            break;
        }
        case UI_SET_POWER_LOSS_PARA:
        {
            CrLogI("UI_SET_POWER_LOSS_PARA");
            switch (tempBuff[0])
            {
                case '1':
                {
                    lossPrefer.has_sw = 1;
                    lossPrefer.sw = atoi(&tempBuff[1]);
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            disControl.powerlosspre = &lossPrefer;
            break;
        }
        case UI_SET_AI_CONTROL_PARA:
        {
            CrLogI("UI_SET_AI_CONTROL_PARA");
            switch (tempBuff[0])
            {
                case '1':
                {
                    aiPrefer.has_sw = 1;
                    aiPrefer.sw = atoi(&tempBuff[1]);
                    break;
                }
                case '2':
                {
                    aiPrefer.has_detection = 1;
                    aiPrefer.detection = atoi(&tempBuff[1]);
                    break;
                }
                case '3':
                {
                    aiPrefer.has_pauseprint = 1;
                    aiPrefer.pauseprint = atoi(&tempBuff[1]);
                    break;
                }
                case '4':
                {
                    aiPrefer.has_firstfloor = 1;
                    aiPrefer.firstfloor = atoi(&tempBuff[1]);
                    break;
                }
                case '5':
                {
                    aiPrefer.has_flowdetect = 1;
                    aiPrefer.flowdetect = atoi(&tempBuff[1]);
                    break;
                }
                case '6':
                {
                    aiPrefer.has_aimode = 1;
                    aiPrefer.aimode = atoi(&tempBuff[1]);
                    break;
                }
                default: CrLogW("Error control instruction\n"); break;
            }
            disControl.aipre= &aiPrefer;
            break;
        }
        case UI_SET_KLIPPER_CONSOLE_CMD:
        {
            CrLogI("UI_SET_KLIPPER_CONSOLE_CMD");
            snprintf(paraBuff,256,"%s",tempBuff);
            disControl.has_consolectl = 1;
            disControl.consolectl.data = (uint8_t*)paraBuff;
            disControl.consolectl.len = strlen(paraBuff)+1;

            break;
        }

        default: CrLogW("ui set state cmd fail!; cmd = [%d]\n", flag); break;
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = dis_control_print__pack(&disControl, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {unsigned char} flag
 */
int SetPrinterRefreshToManager(unsigned char flag)
{
    CrLogI("SetPrinter Refresh flag = %d", flag);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {unsigned char} flag
 */
int SetPrinterBuzzerToManager(unsigned char flag)
{
    CrLogI("SetPrinter buzzer flag = %d", flag);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_BUTTON_SOUND, "", 0);
    SendProcessMsgBuff(&send, size);
    
    startupFullScreenCount = 0; // 启动全屏计数清零
    startupScreenSaverCount = 0; // 启动息屏计数清零
    return 0;
}


/**
 * @description: 
 * @return {*}
 */
void DisStartLaserTest(int step)
{
    CrLogI("DisStartLaserTest =%d\n",step);
    char buf[64]={0};
    snprintf(buf,sizeof(buf),"%d",step);
    // 同步打印机打印任务信息
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_SET_LASER_TEST_START_REQ, buf, sizeof(buf));
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {FactoryTest_t} control
 */
void DisFactoryTestControl(FactoryTest_t control)
{
    CrLogI("factory test control = %d", control);
    switch (control)
    {
        // 进入裸板测试
        case FACTORY_TEST_START: {
            // 修改配置文件
            remove(GetUserPrinterConfigFilePath());
            char copyCmd[1024] = {0};
            snprintf(copyCmd, sizeof(copyCmd), "cp %s %s", GetUserFactoryConfigFilePath(), GetUserPrinterConfigFilePath());
            system(copyCmd);

            // 重启klipper
            DisControlPrint disControl = DIS_CONTROL_PRINT__INIT;
            disControl.has_restartklipper = 1;
            GET_MESSAGE_BUFF(buff);
            size_t len = dis_control_print__pack(&disControl, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_CONTROL_PRINT_REQ, buff, len);
            SendProcessMsgBuff(&send, size);

            // 重启显示，进入裸板产测
            char touchCmd[256] = {0};
            snprintf(touchCmd, sizeof(touchCmd), "touch %s && sync", GetDevelopFactoryTestPtah());
            system(touchCmd);
            RestartNowDisplayServer();
            break;
        }

        // 退出裸板测试
        case FACTORY_TEST_STOP: {
            remove(GetUserPrinterConfigFilePath());
            remove(GetDevelopFactoryTestPtah());
            system("clear_sn_mac.sh pcba_test");
            system("/usr/bin/mcu_reset.sh");
            system("sync && reboot -f");
            break;
        }

        // 进入整机测试
        case MACHINE_TEST_START: {
            char touchCmd[256] = {0};
            snprintf(touchCmd, sizeof(touchCmd), "touch %s && sync", GetDevelopMachineTestPtah());
            system(touchCmd);
            RestartNowDisplayServer();
            break;
        }

        // 退出整机测试
        case MACHINE_TEST_STOP: {
            remove(GetDevelopMachineTestPtah());
            system("sync");
            RestartNowMasterServer();
            RestartNowDisplayServer();
            break;
        }
    }
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
 */
static int SaveLaserAiPointCloud(void)
{
    // 创建新路径
    struct timeval nowTime;
    gettimeofday(&nowTime, NULL);
    struct tm *CurTime = localtime(&nowTime.tv_sec);

    char savePointCloud[256] = {0};
    snprintf(savePointCloud, DEF_PATH_LEN, "%s%04d-%02d-%02d_%02d-%02d-%02d", GetTempUserPointCloudDir(),
        CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday, CurTime->tm_hour , CurTime->tm_min , CurTime->tm_sec);

    // 创建路径
    if (access(savePointCloud, F_OK) != 0) {
        char cmd[300] = {0};
        snprintf(cmd, 300, "mkdir -p %s", savePointCloud);

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    // 保存文件原始图片
    char cmd[1024] = {0};
    snprintf(cmd, sizeof(cmd), "cp %s*.temp %s && sync", GetTempUserPointCloudDir(), savePointCloud);
    CrLogI("save ai image = %s\n", cmd);
    char sysRes[1024] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {DataCollectionType_t} type
 */
void DisSaveDataCollection(DataCollectionType_t type)
{
    CrLogI("save data collection = %d", type);
#ifdef CROSS_COMPILE
    switch (type) {
        case COLLECTION_AI_CAMERA_IMAGE: SaveCameraAiDetectImage(); break;
        case COLLECTION_AI_POINT_CLOUD: SaveLaserAiPointCloud(); break;
    }
#endif
}
