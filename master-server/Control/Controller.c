/*
 * @Description : Controller管理器
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:09
 * @LastEditTime: 2023-11-02 19:52:31
 */

#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <dirent.h>
#include <linux/limits.h>
#include <sys/time.h>
#include <string.h>
#include <inotifytools/inotifytools.h>
#include <inotifytools/inotify.h>

#include "Base/MasterMsgBase.h"
#include "Controller.h"
#include "ControllerFsm.h"
#include "AppPrint.h"
#include "AppFuncModule.h"
#include "AppModeAutoPrint.h"
#include "AppModeSdPrint.h"

#include "DefineGcode.h"
#include "PrintControl.h"
#include "GcodeCmdResAnl.h"
#include "PrintfManager.h"
#include "GcodEmetadata.h"

// 监听文件变化
#define IN_USER_EVENTS	(IN_CREATE | IN_DELETE | IN_MODIFY | IN_MOVE)

/**
 * @description: 静态变量声明
 * @param  {*}
 * @return {*}
 */
static MsgHandle_t msgHandle;
static int managerMsgId = -1;
static PowerLossInfo_t savePowerLossInfo;
static char userLastUdiskPath[256] = {0};
static pthread_mutex_t getGcodeInfoLock;
static int klipperCmdSyncRecvId = -1;
static PrintPrepareState_t printPrepare = PRINT_PREPARE_NULL;
static int userControlSystemResetBit = 0;
static bool userControlSystemResetApp = false;
static sem_shm_t printObjectShm = {0};

/**
 * @description: 静态函数声明
 */
static int SendMsgBuff(MsgHeadBuf_t *data, size_t len);
static void SystemSyncUdiskState(MsgHeadBuf_t *head);



/**
 * @description: 
 * @return {*}
 * @param {PrintPrepareState_t} state
 */
void SetPrintPrepareState(PrintPrepareState_t state) { printPrepare = state; }

/**
 * @description: 
 * @return {*}
 */
PrintPrepareState_t GetPrintPrepareState(void) { return printPrepare; }

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
static void PauseGetHotendBedTemp(MsgHeadBuf_t *head)
{
    enablePauseAutoGetHotendBedTemp();
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void MsaterControlReboot(MsgHeadBuf_t *head)
{
    CrLogI("reboot system after 1 second !!!\n\n");
    #ifdef CROSS_COMPILE
    sleep(1);
    // 调用系统命令
    // 重启下位机
    char sysRes[1024] = {0};
    if (!PopenSystem((char*)"/usr/bin/mcu_reset.sh", sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);
    // 重启系统
    bzero(sysRes, sizeof(sysRes));
    if (!PopenSystem((char*)"sync && reboot -f", sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);
    #endif
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void userControlSystemReset(MsgHeadBuf_t *head)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_DEVICE_RESET_REQ, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
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

    CrLogI("Print Finish result = %d\n", finish->result);
    if (finish->result)
    {
        AppSendPrintState();
        SetAppModeChange(APP_MODE_IDLE);
    }

    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_DEVICE_PRINT_FINISH, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);

    gcode_cmd_res__free_unpacked(finish, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSyncDownloadGcodeState(MsgHeadBuf_t *head)
{
    DownloadGcode *state = download_gcode__unpack(NULL, head->bufLen, head->buf);
    if (!state) {
        CrLogW("unpack failed\n");
        return;
    }

    // 更新下载状态
    if (state->has_state)
    {
        CrLogI("sync download gcode state = %d", state->state);
        switch (state->state) {
            case FILE_DOWNLOAD_ING: SetAppStateChange(APP_PRINT_STATE_DOWNLOAD); break;
            case FILE_DOWNLOAD_FAIL:
            case FILE_DOWNLOAD_CANCEL: {
                if (GetCurrentAppstate() == APP_PRINT_STATE_DOWNLOAD) SetAppStateChange(APP_PRINT_STATE_STOP);
                break;
            }
        }
    }

    download_gcode__free_unpacked(state, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserStartTempAutoPidReq(MsgHeadBuf_t *head)
{
    TempAutoPidPrefer *temp = temp_auto_pid_prefer__unpack(NULL, head->bufLen, head->buf);
    if (!temp) {
        CrLogW("unpack failed\n");
        return;
    }

    // 获取保存值
    TempAutoPidPreferList list = TEMP_AUTO_PID_PREFER_LIST__INIT;
    TempAutoPidPreferList getList = TEMP_AUTO_PID_PREFER_LIST__INIT;
    int result = GetTempAutoPidPrefer(&list, &getList);
    
    // 提取选中的ID
    for (int i = 0; i < getList.n_list; i++)
    {
        if (getList.list[i]->id == temp->id)
        {
            UpdataAutoPidProgress(0);
            setUserSetAutoPidTimes(getList.list[i]->time);

            // 开启温度自动PID
            char sendBuff[100] = {0};
            if (getList.list[i]->id == 1) {
                snprintf(sendBuff, 100, "PID_CALIBRATE HEATER=extruder TARGET=%d", getList.list[i]->temp);
                json_object *params = json_object_new_object();
                json_object_object_add(params, "script", json_object_new_string(sendBuff));
                AddKlipperCmd("gcode/script", params, SET_START_HOT_END_TEMP_AUTO_PID_NUM, head->origin);
            }
            else {
                if (GetSystemConfig().model == CR_10_H1)
                    snprintf(sendBuff, 100, "PID_CALIBRATE HEATER=heater_bed_0 TARGET=%d", getList.list[i]->temp);
                else
                    snprintf(sendBuff, 100, "PID_CALIBRATE HEATER=heater_bed TARGET=%d", getList.list[i]->temp);
                
                json_object *params = json_object_new_object();
                json_object_object_add(params, "script", json_object_new_string(sendBuff));
                AddKlipperCmd("gcode/script", params, SET_START_HOT_BED_TEMP_AUTO_PID_NUM, head->origin);
            }
            CrLogI("hotend temp auto pid = %s", sendBuff);
        }
    }
    // 释放资源
    GetTempAutoPidPreferFree(&getList);
    
    // 应答
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = result;
    GET_MESSAGE_BUFF(resBuff);
    size_t resLen = gcode_cmd_res__pack(&res, resBuff);
    CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_START_TEMP_AUTO_PID_ANS, resBuff, resLen);
    MANAGER_MSG_SEND(head->origin, &resSend, resSize);

    temp_auto_pid_prefer__free_unpacked(temp, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserStartPlaWarmUpReq(MsgHeadBuf_t *head)
{
    MaterialPrefer *warmUp = material_prefer__unpack(NULL, head->bufLen, head->buf);
    if (!warmUp) {
        CrLogW("unpack failed\n");
        return;
    }

    // 获取保存值
    MaterialPreferList list = MATERIAL_PREFER_LIST__INIT;
    MaterialPreferList getList = MATERIAL_PREFER_LIST__INIT;
    int result = GetMaterialPrefer(&list, &getList);

    // 提取选中的ID
    for (int i = 0; i < getList.n_list; i++)
    {
        if (getList.list[i]->id == warmUp->id)
        {
            // 发送喷嘴温度
            Extruder extruder = EXTRUDER__INIT;
            extruder.has_extruder = 1;
            extruder.extruder = getList.list[i]->hotendtemp;

            GET_MESSAGE_BUFF(buff);
            size_t len = extruder__pack(&extruder, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_NOZZLE_TEMP_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);

            // 发送热床温度
            HeaterBed heaterBed = HEATER_BED__INIT;
            if (GetSystemConfig().model == CR_10_H1) {
                heaterBed.has_heater_bed_0 = 1;
                heaterBed.heater_bed_0 = getList.list[i]->bedtemp;
            }
            else {
                heaterBed.has_heater_bed = 1;
                heaterBed.heater_bed = getList.list[i]->bedtemp;
            }

            GET_MESSAGE_BUFF(buff1);
            size_t len1 = heater_bed__pack(&heaterBed, buff1);
            CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_SET_BED_TEMP_REQ, buff1, len1);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send1, size1);
        }
    }
    // 释放资源
    GetMaterialPreferFree(&getList);

    // 应答
    GcodeCmdRes res = GCODE_CMD_RES__INIT;
    res.result = result;
    GET_MESSAGE_BUFF(resBuff);
    size_t resLen = gcode_cmd_res__pack(&res, resBuff);
    CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_START_MATERIAL_WARM_UP_ANS, resBuff, resLen);
    MANAGER_MSG_SEND(head->origin, &resSend, resSize);

    material_prefer__free_unpacked(warmUp, NULL);
}

/**
 * @description: 
 * @return {*}
 */
static int UserGetPowerLossInfoReq(MsgHeadBuf_t *head)
{
    GcodeCmd fileName = GCODE_CMD__INIT;
    fileName.has_cmdstr = 1;
    fileName.cmdstr.data = (uint8_t*)savePowerLossInfo.fileName;
    fileName.cmdstr.len = strlen(savePowerLossInfo.fileName) + 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd__pack(&fileName, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GET_POWER_LOSS_INFO_ANS, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} *info
 */
static void SaveCurrentWorkInfoToFile(KlipperPrint_t *info)
{
    json_object *curInfo = json_object_new_object();
    json_object_object_add(curInfo, "work_id", json_object_new_int(info->current_file.id));
    json_object_object_add(curInfo, "start_time", json_object_new_int(info->current_file.startTime));
    json_object_object_add(curInfo, "work_file", json_object_new_string(info->current_file.fileName));

    json_object_to_file_ext(GetCurrentWorkInfo(), curInfo, JSON_C_TO_STRING_PRETTY | JSON_C_TO_STRING_NOSLASHESCAPE | JSON_C_TO_STRING_NOZERO);
    json_object_put(curInfo);
}

/**
 * @description: 
 * @return {*}
 * @param {uint32_t} layers
 */
static void SetDelayImageIntervalByLayers(uint32_t layers)
{
    // 通过总层数确定延时摄影拍摄间隔
    DelayImagePrefer getPrefer = DELAY_IMAGE_PREFER__INIT;
    GetDelayImagePrefer(&getPrefer);

    // 计算间隔层数
    int interval = 0;
    if (layers <= 150) interval = layers / (getPrefer.frame * (getPrefer.mintime * 2 + 1)) + 1;
    else if (layers <= 900) interval = layers / (getPrefer.frame * (getPrefer.mintime * 4 + 1)) + 1;
    else interval = layers / (getPrefer.frame * (getPrefer.mintime * 12 + 1)) + 1;
    CrLogI("current delay image interval = %d\n", interval);

    // 设置延时摄影间隔
    DelayImagePrefer prefer = DELAY_IMAGE_PREFER__INIT;
    prefer.has_interval = 1;
    prefer.interval = interval;
    SetDelayImagePrefer(&prefer);
    CrLogI("delay image interval = %d\n", interval);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} progress, {void *}userPtr
 */
static void copyProgress(int progress, void *userPtr)
{
    char progress_str[16] = {0};
    snprintf(progress_str, 16, "%d", progress);
    GcodeCmdRes *res = userPtr;
    res->result = 1;
    res->has_resstr = 1;
    res->resstr.len = strlen(progress_str);
    res->resstr.data = (uint8_t*)progress_str;
    GET_MESSAGE_BUFF(resBuff);
    size_t resLen = gcode_cmd_res__pack(res, resBuff);
    CREATE_MESSAGE_PACKAGE(resSend, resSize, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_SYNC_FILE_COPY_PROGRESS, resBuff, resLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &resSend, resSize);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &resSend, resSize);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &resSend, resSize);
    usleep(100);
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} *printer
 */
static void ResetKlipperPrintData(KlipperPrint_t *printer, PrintFileInfo_t printInfo)
{
    printer->print_stats.print_duration = 0;
    printer->print_stats.total_duration = 0;
    printer->print_stats.filament_used = 0;
    printer->print_stats.filament_used_real = 0;
    
    // 判断是否是fluidd启动的打印
    if (printInfo.fluiddStart == 0) {
        // 重置对象排除信息
        json_object *result = json_object_new_object();
        json_object_object_add(result, "current_object", json_object_new_string_len("", 0));
        json_object_object_add(result, "excluded_objects", json_object_new_string_len("", 0));
        json_object_object_add(result, "objects", json_object_new_string_len("", 0));

        char *resultStr = (char*)json_object_to_json_string(result);
        UpdataPrintObjectInfo(resultStr, strlen(resultStr));
        json_object_put(result);

        // 同步状态打印对象
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_SYNC_PRINT_OBJECT_INFO, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
        MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
        MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
    }
}

/**
 * @description: 
 * @return {*}
 * @param {char} *file
 * @param {KlipperPrint_t} *printer
 * @param {PrintFileInfo_t} printInfo
 */
static bool ControlStartPrint(char *file, KlipperPrint_t *printer, PrintFileInfo_t printInfo)
{
    char printFile[256] = {0};
    memcpy(printFile, file, strlen(file));

    // 判断文件名是否过长
    if (strlen(printFile) >= NAME_MAX - 50) {
        CrLogW("gcode file name too long\n");
        UpdataErrorStateToManager(FAULT_GCODE_FILE_NAME_TO_LONG, "gcode file name too long", NULL);
        return false;
    }

    // 判断文件是否有效
    if (access(printFile, F_OK) != 0) {
        CrLogW("gcode file does not exist\n");
        return false;
    }

    // 判断设备是否是空闲
    if (GetPrintState().deviceState != DEVICE_STATE_IDLE) {
        CrLogW("printer busy, operation not allowed\n");
        return false;
    }

    // 判断是否在空闲模式
    if (GetCurrentAppMode() != APP_MODE_IDLE) {
        CrLogW("during printing, the operation cannot be repeated\n");
        return false;
    }

    // 判断选中的是否为U盘文件，如果在U盘，先移动到SD中，再打印
    if (access(GetUserLocalUdiskPtah(), F_OK) == 0 &&
        strstr(printFile, GetUserLocalUdiskPtah())) {
        CrLogI("the file is in the U disk and moved to the SD card");

        // 提取文件名
        char *fileName = strrchr(printFile, '/');
        char tempPath[256] = {0};
        strcat(tempPath, GetUserLocalSdCardPtah());
        strcat(tempPath, fileName);
        strcat(tempPath, ".temp");

        GcodeCmdRes res = GCODE_CMD_RES__INIT;
        file_setCallback(copyProgress,&res);
        file_copyFileToDir(printFile,tempPath);

        // 获取源文件MD5
        char sourceFileMd5[256] = {0};
        getFileMD5(printFile, sourceFileMd5);
        // 获取新文件MD5
        char targetFileMd5[256] = {0};
        getFileMD5(tempPath, targetFileMd5);
        CrLogI("sourceFileMd5 = %s", sourceFileMd5);
        CrLogI("targetFileMd5 = %s", targetFileMd5);

        // 判断复制文件完整新
        if (strcmp(sourceFileMd5, targetFileMd5) != 0) {
            CrLogW("copy file fail!\n");
            UpdataErrorStateToManager(FAULT_COPY_GCODE_FILE_FROM_UDISK, "copy gcode fail from udisk", NULL);
            // 删除校验错误文件
            if (remove(tempPath) != 0) CrLogW("remove gcode fail\n");
            // 同步复制状态
            copyProgress(-1, &res);
            return false;
        }

        bzero(printFile, sizeof(printFile));
        strcat(printFile, tempPath);

        // 重命名
        char *end = printFile + strlen(printFile) - strlen(".temp");
        if (end) end[0] = '\0';
        if (rename(tempPath, printFile) != 0) CrLogW("rename gcode fail\n");
    }
    system("sync");

    // 判断是否清除图像文件
    if (printInfo.powerLossStart == 0) {
        DeleteOldDelayImageH264File(); // 清除延时摄影文件
        DeleteOldAiImageFile(); // 清除AI识别图片
    }
    // 判断是否是fluidd启动的打印
    if (printInfo.fluiddStart == 0) {
        UpdataPrintLayer(0);
        UpdataPrintLayers(0);
        SetAppStateChange(APP_PRINT_STATE_TO_WORK);
    }
    
    // 清空共享状态
    UpdataPrintUsageTime(0);
    UpdataPrintRemainTime(0);
    UpdataFilamentUsed(0);
    UpdataPrintProgress(0);
    UpdataExistOffContinue(0);
    // 重置klipper的同步状态
    ResetKlipperPrintData(printer, printInfo);

    // 记录当前打印文件名称
    memcpy(printer->current_file.fileName, printFile, strlen(printFile));
    CrLogI("get print sd file path = %s", printFile);

    // 从gcode文件获取元数据，保存缩略图到历史记录
    snprintf(printer->current_file.thumbnails, sizeof(printer->current_file.thumbnails),
            "%s/%d.png", GetuserPrintHistoryImagePtah(), printer->current_file.id);
    GetPrintParaFromGcodeFile(printFile, &printer->current_file);

    // 获取注水图
    strcat(printer->current_file.preview, GetUserCurrentPrintImagePath());
    GetLocalGcodePhotoToFile(printFile, &printer->current_file, GCODE_PHOTO_TYPE_PRINT);

    // 获取同名历史记录信息
    GetHistoryRecordFromFileName(printer);

    // 动态设置延时摄影拍摄层数
    uint32_t layers = GetPrintLayers(*printer);
    SetDelayImageIntervalByLayers(layers);

    // 除去SD卡路径
    char *sdFileName = strstr(printFile, GetUserLocalSdCardPtah());
    if (sdFileName) sdFileName = sdFileName + strlen(GetUserLocalSdCardPtah()) + 1;
    CrLogI("get print file name = %s", sdFileName);

    // 设置打印文件名称
    memcpy(printInfo.fileName, sdFileName, strlen(sdFileName));
    SetSdPrintInfo(printInfo);

    // 清除断电续打信息
    memset(&savePowerLossInfo, 0, sizeof(PowerLossInfo_t));

    // 同步当前打印任务信息
    SyncPrintingWorkInfo();

    // 保存当前打印任务信息
    SaveCurrentWorkInfoToFile(printer);

    // 新建打印记录
    UploadPrintHistoryRecord(false);

    // 切换状态机
    SetAppModeChange(APP_MODE_SD_PRINT);
    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperPrint_t} *info
 */
static void GetWorkInfoFromFile(KlipperPrint_t *info)
{
    if (access(GetCurrentWorkInfo(), F_OK) == 0) {
        json_object *workInfo = json_object_from_file(GetCurrentWorkInfo());
        if (workInfo)
        {
            json_object *workIdObj = json_object_object_get(workInfo, "work_id");
            if (workIdObj) info->current_file.id = json_object_get_int(workIdObj);
            CrLogI("work info id = %d", info->current_file.id);

            json_object *startTimeObj = json_object_object_get(workInfo, "start_time");
            if (startTimeObj) info->current_file.startTime = json_object_get_int(startTimeObj);
            CrLogI("work info start time = %d", info->current_file.startTime);

            json_object_put(workInfo);
            return;
        }
    }

    // 没有获取到保存信息，使用当前时间
    struct timeval startTime;
    gettimeofday(&startTime, NULL);
    CrLogI("start Print Time = %d", startTime.tv_sec);
    info->current_file.id = startTime.tv_sec;
    info->current_file.startTime = startTime.tv_sec;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserStartPowerLossReq(MsgHeadBuf_t *head)
{
    // 获取打印文件
    CrLogI("control start power loss");
    char printFile[256] = {0};
    memcpy(printFile, savePowerLossInfo.fileName, strlen(savePowerLossInfo.fileName));
    CrLogI("checked print file name = %s", printFile);

    // 记录当前打印任务信息
    KlipperPrint_t *printer = GetPrinter();
    CleanPrinterCurrentFile();
    // 开始打印时间
    GetWorkInfoFromFile(printer);

    // 打印任务启动方式
    CrLogI("start print cmd origin = %d\n", head->origin);
    if (head->origin == MSG_ORIGIN_APP_MANAGER)
        printer->current_file.startWay = PRINT_SOURCE_APP_CLOUD_OFF_CONTINUE;
    else if (head->origin == MSG_ORIGIN_DISPLAY_MANAGER)
        printer->current_file.startWay = PRINT_SOURCE_DIS_MARLIN_OFF_CONTINUE;
    else if (head->origin == MSG_ORIGIN_WEB_MANAGER)
        printer->current_file.startWay = PRINT_SOURCE_WEB_LINUX_OFF_CONTINUE;

    // 设置打印参数选项
    PrintFileInfo_t printInfo = {0};
    printInfo.powerLossStart = 1;

    // 启动打印任务
    if (ControlStartPrint(printFile, printer, printInfo) == false) return;

    // 应答
    GcodeCmdRes start = GCODE_CMD_RES__INIT;
    start.result = 1;
    GET_MESSAGE_BUFF(buff2);
    size_t len2 = gcode_cmd_res__pack(&start, buff2);
    CREATE_MESSAGE_PACKAGE(send2, size2, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_START_POWER_LOSS_ANS, buff2, len2);
    MANAGER_MSG_SEND(head->origin, &send2, size2);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserCancelPowerLossReq(MsgHeadBuf_t *head)
{
    CrLogI("control Cancel Power loss");
    UpdataExistOffContinue(0);
    memset(&savePowerLossInfo, 0, sizeof(PowerLossInfo_t));

    // 取消断电续打打印
    json_object *params = json_object_new_object();
    AddKlipperCmd("pause_resume/cancel_continue_print", params, SET_CANCEL_CONTINUE_PRINT_NUM, MSG_ORIGIN_CONTROLLER);

    // 应答
    GcodeCmdRes stop = GCODE_CMD_RES__INIT;
    stop.result = 1;

    GET_MESSAGE_BUFF(buff1);
    size_t len1 = gcode_cmd_res__pack(&stop, buff1);
    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_CANCEL_POWER_LOSS_ANS, buff1, len1);
    MANAGER_MSG_SEND(head->origin, &send1, size1);
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *SystemResetThread(void *arg)
{
    // 恢复IOT配置
    CrLogI("system reset to app server");
    int timeoutCount = 0;
    userControlSystemResetApp = false;

    CREATE_MESSAGE_PACKAGE(send1, size1, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_SYSTEM_RESET_TO_APP_REQ, "", 0);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send1, size1);
    // 等待IOT恢复完成，或者3秒超时
    while (!userControlSystemResetApp && timeoutCount < 300) {
        usleep(1000 * 10);
        timeoutCount++;
    }

    CrLogI("delete config file");
    // 全部数据清除标志
    int allClearSign = (BIT0 | BIT1 | BIT2 | BIT3);
    // 遍历恢复出厂设置选项
    if (userControlSystemResetBit != 0)
    {
        if (userControlSystemResetBit & BIT0)
        {
            allClearSign &= ~BIT0;
            CrLogI("system reset remove log ....");
            char cmd[256] = {0};
            snprintf(cmd, sizeof(cmd), "rm -rf %s/* && sync", GetUserDataLogDirPtah());

            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) {
                CrLogW("system fail! res = %s\n", sysRes);
                CrLogW("remove log fail\n");
            }
        }
        if (userControlSystemResetBit & BIT1)
        {
            allClearSign &= ~BIT1;
            CrLogI("system reset remove delay image ....");
            char cmd[256] = {0};
            snprintf(cmd, sizeof(cmd), "rm -rf %s/* && sync", GetUserDelayImageDirPtah());

            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) {
                CrLogW("system fail! res = %s\n", sysRes);
                CrLogW("remove delay image fail\n");
            }
        }
        if (userControlSystemResetBit & BIT2)
        {
            allClearSign &= ~BIT2;
            CrLogI("system reset remove gcode file ....");
            char cmd[256] = {0};
            snprintf(cmd, sizeof(cmd), "rm -rf %s/* && sync", GetUserLocalSdCardPtah());

            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) {
                CrLogW("system fail! res = %s\n", sysRes);
                CrLogW("remove gcode file fail\n");
            }
        }
        if (userControlSystemResetBit & BIT3)
        {
            allClearSign &= ~BIT3;
            CrLogI("system reset remove print history ....");
            char cmd[256] = {0};
            snprintf(cmd, sizeof(cmd), "rm -rf %s/* && sync", GetuserPrintHistoryPtah());

            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) {
                CrLogW("system fail! res = %s\n", sysRes);
                CrLogW("remove print history fail\n");
            }
        }
    }

    // 删除系统配置文件
    {
        CrLogI("system reset remove system config file ....");
        // ‘creality’文件夹内，只保存‘userdata’文件夹，删除其他文件
        char cmd[4096] = {0};
        snprintf(cmd, sizeof(cmd), "/usr/bin/find '%s' -path '%suserdata' -prune -o -path '%s' -o -print -exec rm -rf {} \\;",
                GetDeviceCrealityDirPtah(), GetDeviceCrealityDirPtah(), GetDeviceCrealityDirPtah());
        CrLogI("cmd = %s", cmd);
        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) {
            CrLogW("system fail! res = %s\n", sysRes);
            CrLogW("remove system config file fail\n");
        }

        // ‘userdata’文件夹内，只保存‘config’、‘log’、‘histor’、‘delay_image’文件夹，删除其他文件
        bzero(cmd, sizeof(cmd));
        snprintf(cmd, sizeof(cmd), "/usr/bin/find '%s' -path '%sconfig' -prune -o -path '%slog' -prune -o -path '%shistory' -prune -o -path '%sdelay_image' -prune -o -path '%s' -o -print -exec rm -rf {} \\;",
                GetDeviceUserdataDirPtah(), GetDeviceUserdataDirPtah(), GetDeviceUserdataDirPtah(),
                GetDeviceUserdataDirPtah(), GetDeviceUserdataDirPtah(), GetDeviceUserdataDirPtah());
        CrLogI("cmd = %s", cmd);
        // 调用系统命令
        bzero(sysRes, sizeof(sysRes));
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) {
            CrLogW("system fail! res = %s\n", sysRes);
            CrLogW("remove system config file fail\n");
        }

        // 保留‘config’部分配置
        char moveCmd[1024] = {0};
        snprintf(moveCmd, sizeof(moveCmd), "mv %s /tmp/user_data_not_deleted.temp", GetUserDataNotDeleteFilePtah());
        CrLogI("moveCmd = %s", moveCmd);
        system(moveCmd);

        bzero(moveCmd, sizeof(moveCmd));
        snprintf(moveCmd, sizeof(moveCmd), "mv %s /tmp/laser_offset_info.temp", GetLaserOffsetInfo());
        CrLogI("moveCmd = %s", moveCmd);
        system(moveCmd);

        bzero(moveCmd, sizeof(moveCmd));
        snprintf(moveCmd, sizeof(moveCmd), "mv %s /tmp/save_z_pos.temp", GetSaveZaxisHeight());
        CrLogI("moveCmd = %s", moveCmd);
        system(moveCmd);

        // 清除全部文件
        bzero(cmd, sizeof(cmd));
        snprintf(cmd, sizeof(cmd), "rm -rf %s/*", GetUserDataConfigDirPtah());

        // 调用系统命令
        bzero(sysRes, sizeof(sysRes));
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) {
            CrLogW("system fail! res = %s\n", sysRes);
            CrLogW("remove system config file fail\n");
        }

        // 恢复保留配置
        bzero(moveCmd, sizeof(moveCmd));
        snprintf(moveCmd, sizeof(moveCmd), "mv /tmp/user_data_not_deleted.temp %s", GetUserDataNotDeleteFilePtah());
        CrLogI("moveCmd = %s", moveCmd);
        system(moveCmd);

        bzero(moveCmd, sizeof(moveCmd));
        snprintf(moveCmd, sizeof(moveCmd), "mv /tmp/laser_offset_info.temp %s", GetLaserOffsetInfo());
        CrLogI("moveCmd = %s", moveCmd);
        system(moveCmd);

        bzero(moveCmd, sizeof(moveCmd));
        snprintf(moveCmd, sizeof(moveCmd), "mv /tmp/save_z_pos.temp %s", GetSaveZaxisHeight());
        CrLogI("moveCmd = %s", moveCmd);
        system(moveCmd);
    }

    // 删除klipper配置文件
    {
        CrLogI("system reset remove klipper config file ....");
        char cmd[256] = {0};
        snprintf(cmd, sizeof(cmd), "rm -rf %s/* && sync", GetUserPrinterConfigPath());

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) {
            CrLogW("system fail! res = %s\n", sysRes);
            CrLogW("remove klipper print config file fail\n");
        }
    }

    // 同步到交互端，应用恢复出厂设置完成
    CrLogI("System Reset finish\n\n");
    GcodeCmdRes result = GCODE_CMD_RES__INIT;
    result.result = 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&result, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_SYSTEM_RESET_ANS, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);

    // 等待系统恢复重启
    #ifdef CROSS_COMPILE
    char *script = NULL;
    if (allClearSign == 0) script = GetDefaultSystemRestartAll();
    else script = GetDefaultSystemRestartPart();
    
    // 调用系统命令
    char sysRes[1024] = {0};
    bzero(sysRes, sizeof(sysRes));
    if (!PopenSystem(script, sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);
    #endif

    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlSystemResetReq(MsgHeadBuf_t *head)
{
    CrLogI("Control System Reset\n");
    MutableTypeData *systemreset = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!systemreset) {
        CrLogW("unpack failed\n");
        return;
    }

    userControlSystemResetBit = 0;
    if (systemreset->has_int_v) userControlSystemResetBit = systemreset->int_v;
    mutable_type_data__free_unpacked(systemreset, NULL);
    CrLogI("userControlSystemResetBit = %d", userControlSystemResetBit);

    // 置位恢复出厂设置状态
    UpdataDeviceState(DEVICE_STATE_RESET);
    // 创建恢复出厂设置线程
    pthread_t resetHandle;
    if (pthread_create(&resetHandle, NULL, (void*)SystemResetThread, NULL)) {
        CrLogE("create pthread error!\n");
    }
    pthread_detach(resetHandle);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlStartPrintReq(MsgHeadBuf_t *head)
{
    MutableTypeData *recv = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }
    
    // 获取打印文件
    CrLogI("control start print file");
    char printFile[256] = {0};
    if (recv->has_bytes_v) memcpy(printFile, recv->bytes_v.data, recv->bytes_v.len);
    CrLogI("checked print file name = %s", printFile);
    
    int withSelfTest = 0;
    if (recv->has_int_v) withSelfTest = recv->int_v;
    mutable_type_data__free_unpacked(recv, NULL);

    // 记录当前打印任务信息
    KlipperPrint_t *printer = GetPrinter();
    CleanPrinterCurrentFile();
    // 开始打印时间
    struct timeval startTime;
    gettimeofday(&startTime, NULL);
    CrLogI("start Print Time = %d", startTime.tv_sec);
    printer->current_file.id = startTime.tv_sec;
    printer->current_file.startTime = startTime.tv_sec;

    // 打印任务启动方式
    CrLogI("start print cmd origin = %d\n", head->origin);
    if (head->origin == MSG_ORIGIN_APP_MANAGER)
        printer->current_file.startWay = PRINT_SOURCE_APP_MARLIN;
    else if (head->origin == MSG_ORIGIN_DISPLAY_MANAGER)
        printer->current_file.startWay = PRINT_SOURCE_DIS_MARLIN;
    else if (head->origin == MSG_ORIGIN_WEB_MANAGER)
        printer->current_file.startWay = PRINT_SOURCE_WEB_LINUX;

    // 设置打印参数选项
    PrintFileInfo_t printInfo = {0};
    printInfo.withSelfTest = withSelfTest;

    // 启动打印任务
    ControlStartPrint(printFile, printer, printInfo);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlStartCloudPrintReq(MsgHeadBuf_t *head)
{
    MutableTypeData *recv = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }
    
    // 获取打印文件
    CrLogI("control start print file");
    char printFile[256] = {0};
    if (recv->has_bytes_v) memcpy(printFile, recv->bytes_v.data, recv->bytes_v.len);
    CrLogI("checked print file name = %s", printFile);

    int withSelfTest = GetSystemConfig().enableselftest;
    mutable_type_data__free_unpacked(recv, NULL);

    // 记录当前打印任务信息
    KlipperPrint_t *printer = GetPrinter();
    CleanPrinterCurrentFile();
    // 开始打印时间
    struct timeval startTime;
    gettimeofday(&startTime, NULL);
    CrLogI("start Print Time = %d", startTime.tv_sec);
    printer->current_file.id = startTime.tv_sec;
    printer->current_file.startTime = startTime.tv_sec;

    // 打印任务启动方式
    CrLogI("start print cmd origin = %d\n", head->origin);
    if (head->origin == MSG_ORIGIN_APP_MANAGER)
        printer->current_file.startWay = PRINT_SOURCE_APP_CLOUD;
    else if (head->origin == MSG_ORIGIN_WEB_MANAGER)
        printer->current_file.startWay = PRINT_SOURCE_WEB_LINUX;

    // 设置打印参数选项
    PrintFileInfo_t printInfo = {0};
    printInfo.withSelfTest = withSelfTest;

    // 启动打印任务
    if (ControlStartPrint(printFile, printer, printInfo) == false) return;

    // 应答
    GcodeCmdRes start = GCODE_CMD_RES__INIT;
    start.result = 1;
    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_cmd_res__pack(&start, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_START_CLOUD_PRINT_ANS, buff, len);
    MANAGER_MSG_SEND(head->origin, &send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlFluiddStartPrintReq(MsgHeadBuf_t *head)
{
    MutableTypeData *recv = mutable_type_data__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }
    
    // 获取打印文件
    CrLogI("fluidd start print file");
    char printFile[256] = {0};
    if (recv->has_bytes_v) memcpy(printFile, recv->bytes_v.data, recv->bytes_v.len);
    CrLogI("checked print file name = %s", printFile);
    mutable_type_data__free_unpacked(recv, NULL);

    // 记录当前打印任务信息
    KlipperPrint_t *printer = GetPrinter();
    CleanPrinterCurrentFile();
    // 开始打印时间
    if (printer->print_stats.total_duration < 10) {
        struct timeval startTime;
        gettimeofday(&startTime, NULL);
        CrLogI("start Print Time = %d", startTime.tv_sec);
        printer->current_file.id = startTime.tv_sec;
        printer->current_file.startTime = startTime.tv_sec;
    }
    else GetWorkInfoFromFile(printer);
    
    // 打印任务启动方式
    printer->current_file.startWay = PRINT_SOURCE_FLUIDD_LINUX;

    // 设置打印参数选项
    PrintFileInfo_t printInfo = {0};
    printInfo.fluiddStart = 1;

    // 启动打印任务
    ControlStartPrint(printFile, printer, printInfo);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlPausePrintReq(MsgHeadBuf_t *head)
{
    GcodeCmd *recv = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("control pause print file");
    // 机器在工作状态，打印准备工作结束
    if (GetCurrentAppstate() == APP_PRINT_STATE_WORK &&
        GetPrintState().deviceState == DEVICE_STATE_PRINTTING &&
        GetPrintState().withSelfTest == PREPARE_STEP_FINISH)
    {
        SetAppStateChange(APP_PRINT_STATE_TO_PAUSE);
        json_object *params = json_object_new_object();
        AddKlipperCmd("pause_resume/pause", params, SET_PAUSE_PRINT_FILE_NUM, MSG_ORIGIN_CONTROLLER);
    }
    else CrLogW("not currently working, state = %d, withSelfTest = %d", GetCurrentAppstate(), GetPrintState().withSelfTest);

    gcode_cmd__free_unpacked(recv, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlResumePrintReq(MsgHeadBuf_t *head)
{
    GcodeCmd *recv = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("control resume print file");
    // 失能部分功能
    FunctionFailure_t functionFailure = GetFunctionFailure();
    switch (functionFailure.lastFaultCode.code) {
        case FAULT_THROAT_FAN_ABNORMAL_PAUSE: functionFailure.singleTask.throatFanDetect = 1; break;
    }
    SetFunctionFailure(functionFailure);

    // 打印准备过程检测到异常，继续打印
    if (GetPrintState().withSelfTest != PREPARE_STEP_FINISH &&
        GetPrintState().deviceState == DEVICE_STATE_PRINTTING &&
        GetPrintPrepareState() == PRINT_PREPARE_FAIL)
    {
        SetPrintPrepareState(PRINT_PREPARE_RESUME_PRINT);
    }
    // 机器在暂停状态，打印准备工作结束
    else if (GetPrintState().deviceState == DEVICE_STATE_PRINTTING &&
        GetCurrentAppstate() == APP_PRINT_STATE_PAUSE)
    {
        SetAppStateChange(APP_PRINT_STATE_TO_RESUME);
        json_object *params = json_object_new_object();
        AddKlipperCmd("pause_resume/resume", params, SET_RESUME_PRINT_FILE_NUM, MSG_ORIGIN_CONTROLLER);
    }
    else CrLogW("not currently suspended, state = %d, withSelfTest = %d", GetCurrentAppstate(), GetPrintState().withSelfTest);

    gcode_cmd__free_unpacked(recv, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlStopPrintReq(MsgHeadBuf_t *head)
{
    // 如果当前在空闲模式，重置打印文件
    if (GetCurrentAppMode() == APP_MODE_IDLE) {
        json_object *params = json_object_new_object();
        json_object_object_add(params, "script", json_object_new_string("SDCARD_RESET_FILE"));
        AddKlipperCmd("gcode/script", params, KLIPPER_SDCARD_RESET_FILE_NUM, 0);
        // 停止操作; 切换状态机
        SetAppStateChange(APP_PRINT_STATE_STOP);
        SetAppModeChange(APP_MODE_IDLE);
        return;
    }

    // 解析指令
    GcodeCmd *recv = gcode_cmd__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }
    
    CrLogI("control stop print file");
    // 切换模式，退出打印
    if (GetCurrentAppstate() != APP_PRINT_STATE_TO_STOP) {
        SetAppStateChange(APP_PRINT_STATE_TO_STOP);
        UserControlStopReady();
    }
    else CrLogW("device stopping printing\n");

    gcode_cmd__free_unpacked(recv, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetNozzleTempAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *temp = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!temp) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("set nozzle temp result = %d", temp->result);

    gcode_cmd_res__free_unpacked(temp, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetBedTempAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *temp = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!temp) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("set bed temp result = %d", temp->result);

    gcode_cmd_res__free_unpacked(temp, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserSetOpenFanAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *fan = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!fan) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Set Open Fan result = %d", fan->result);

    gcode_cmd_res__free_unpacked(fan, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserControlDeviceResetAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *reset = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!reset) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Control Device Reset result = %d", reset->result);
    if (reset->result)
    {
        // 打印机保存配置
        String_t tCmd = {0};
        tCmd.data = SET_PARA_SAVE_EEPROM;
        tCmd.len = strlen(SET_PARA_SAVE_EEPROM);
        AddGcodeListCmd(SET_DEV_RESET_AFTER_SAVE_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);
        // 复位配置文件
        ConfigFileReset();
    }

    gcode_cmd_res__free_unpacked(reset, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserAppSystemResetAns(MsgHeadBuf_t *head)
{
    GcodeCmdRes *reset = gcode_cmd_res__unpack(NULL, head->bufLen, head->buf);
    if (!reset) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("Control app system reset result = %d", reset->result);
    userControlSystemResetApp = true;

    gcode_cmd_res__free_unpacked(reset, NULL);
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
            case MANAGER_PUASE_GET_HOTEND_BED_TEMP: PauseGetHotendBedTemp(&head); break;
            case MANAGER_CONTROL_SYSTEM_REBOOT: MsaterControlReboot(&head); break;
            case MANAGER_CONTROL_SYSTEM_RESET: userControlSystemReset(&head); break;
            case MANAGER_SYNC_UDISK_STATE: SystemSyncUdiskState(&head); break;
            case MANAGER_DEVICE_PRINT_FINISH: UserPrintFinishAns(&head); break;
            case MANAGER_CMD_SYNC_GCODE_DOWNLOAD: UserSyncDownloadGcodeState(&head); break;

            case MANAGER_CMD_START_MATERIAL_WARM_UP_REQ: UserStartPlaWarmUpReq(&head); break;
            case MANAGER_CMD_START_TEMP_AUTO_PID_REQ: UserStartTempAutoPidReq(&head); break;
            case MANAGER_CMD_GET_POWER_LOSS_INFO_REQ: UserGetPowerLossInfoReq(&head); break;

            case MANAGER_CMD_GCODE_START_PRINT_REQ: UserControlStartPrintReq(&head); break;
            case MANAGER_CMD_GCODE_START_CLOUD_PRINT_REQ: UserControlStartCloudPrintReq(&head); break;
            case MANAGER_CMD_GCODE_FLUIDD_START_PRINT_REQ: UserControlFluiddStartPrintReq(&head); break;
            case MANAGER_CMD_GCODE_PAUSE_PRINT_REQ: UserControlPausePrintReq(&head); break;
            case MANAGER_CMD_GCODE_RESUME_PRINT_REQ: UserControlResumePrintReq(&head); break;
            case MANAGER_CMD_GCODE_STOP_PRINT_REQ: UserControlStopPrintReq(&head); break;
            case MANAGER_CMD_START_POWER_LOSS_REQ: UserStartPowerLossReq(&head); break;
            case MANAGER_CMD_CANCEL_POWER_LOSS_REQ: UserCancelPowerLossReq(&head); break;
            case MANAGER_CMD_SYSTEM_RESET_REQ: UserControlSystemResetReq(&head); break;

            case MANAGER_CMD_GCODE_SET_NOZZLE_TEMP_ANS: UserSetNozzleTempAns(&head); break;
            case MANAGER_CMD_GCODE_SET_BED_TEMP_ANS: UserSetBedTempAns(&head); break;
            case MANAGER_CMD_GCODE_OPEN_FAN_ANS: UserSetOpenFanAns(&head); break;
            case MANAGER_CMD_GCODE_SET_DEVICE_RESET_ANS: UserControlDeviceResetAns(&head); break;
            case MANAGER_CMD_SYSTEM_RESET_TO_APP_ANS: UserAppSystemResetAns(&head); break;
            default: PrintfManagerMsgUpdata(head); break;
        }
    }
}

/**
 * @description: 
 * @return {*}
 */
static bool CheckShadowStatus(void)
{
    char path[32] = {0};
    path[0] = '/';
    path[1] = 'o';
    path[2] = 'v';
    path[3] = 'e';
    path[4] = 'r';
    path[5] = 'l';
    path[6] = 'a';
    path[7] = 'y';
    path[8] = '/';
    path[9] = 'u';
    path[10] = 'p';
    path[11] = 'p';
    path[12] = 'e';
    path[13] = 'r';
    path[14] = '/';
    path[15] = 'e';
    path[16] = 't';
    path[17] = 'c';
    path[18] = '/';
    path[19] = 's';
    path[20] = 'h';
    path[21] = 'a';
    path[22] = 'd';
    path[23] = 'o';
    path[24] = 'w';

    if (access(path, F_OK) == 0)
        return true;
    else
        return false;
}

/**
 * @description: 检查机器系统是否异常，是否被用户修改
 * @return {*}
 */
void CheckMachineSystemAbnormal(void)
{
    if (CheckShadowStatus())
    {
        // 删除相关数据
        remove(GetDefaultOverlayUpperPtah());

        // 重启系统
        system("sync");
        MsaterControlReboot(NULL);
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
    managerMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_CONTROLLER);
    if (managerMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    // 创建缓存收发同步的klipper指令应答
    klipperCmdSyncRecvId = msgget(MSG_KEY_CMD_SYNC_RECV, IPC_CREAT | 0666);
    if (klipperCmdSyncRecvId == -1) {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    // 创建对象排除信息共享内存
    printObjectShm = CreateSemShm(PRINT_OBJECT_SEM_PATH, PRINT_OBJECT_SHM_FILE, PRINT_OBJECT_SHM_SIZE, true);
    if (printObjectShm.result != GET_SHM_OK) {
        CrLogE("create print object shm fail\n");
    }

    // 设置设备初始状态
    UpdataDeviceState(DEVICE_STATE_IDLE);
    // 获取系统配置
    ConfigFileInit();
    // 更新SD卡路径
    UpdataSdPath(GetUserLocalSdCardPtah());
    // 更新U盘路径
    UpdataUDiskPath(GetUserLocalUdiskPtah());
    // 初始化串口通信
    PrintfManagerInit();
    // 初始化状态机
    ControllerFsmInit();
    // 初始化自动打印
    AppModeAutoPrintInit();
    // 初始化独立任务模块
    AppFuncModuleInit();
    // 设置打印机模式，状态
    SetAppModeChange(APP_MODE_IDLE);
    SetAppStateChange(APP_PRINT_STATE_IDLE);
    // // 检查机器系统是否异常
    // CheckMachineSystemAbnormal();

    while (1)
    {
        msgUpdata();
        usleep(1000 * 10);
    }

    return NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *fileObj
 */
static void GetSingleGcodeDetails(json_object *fileObj)
{
    // 获取文件路径
    json_object *pathObj = json_object_object_get(fileObj, "path");
    char *pathStr = (char*)json_object_get_string(pathObj);
    CrLogI("gcode file path = %s", pathStr);

    // 获取保存路径
    char *source = NULL, *thumbnails = NULL, *preview = NULL;
    if (strstr(pathStr, GetUserLocalSdCardPtah())) {
        source = GetUserLocalSdCardPtah();
        thumbnails = GetUserLocalThumbnailDirPtah();            
        preview = GetUserLocalOriginalDirPtah();
    }
    else {
        source = GetUserLocalUdiskPtah();
        thumbnails = GetUserUdiskThumbnailDirPtah();                 
        preview = GetUserUdiskOriginalDirPtah();
    }
    char *folder = pathStr + strlen(source);   

    // 提取gcode文件信息
    CurrentFile_t current_file = {0};
    snprintf(current_file.thumbnails, sizeof(current_file.thumbnails), "%s%s.png", thumbnails, folder);
    snprintf(current_file.preview, sizeof(current_file.preview), "%s%s.png", preview, folder);

    // 从gcode文件获取参数
    GetPrintParaFromGcodeFile((char*)pathStr, &current_file);
    GetLocalGcodePhotoToFile(pathStr, &current_file, GCODE_PHOTO_TYPE_PREVIEW);
    json_object_object_add(fileObj, "timeCost", json_object_new_int(current_file.estimated_time));
    json_object_object_add(fileObj, "consumables", json_object_new_int(current_file.filament_total));
    json_object_object_add(fileObj, "floorHeight", json_object_new_int(current_file.layer_height * 100 + 0.5));
    json_object_object_add(fileObj, "modelX", json_object_new_int(current_file.object_light * 100 + 0.5));
    json_object_object_add(fileObj, "modelY", json_object_new_int(current_file.object_weight * 100 + 0.5));
    json_object_object_add(fileObj, "modelZ", json_object_new_int(current_file.object_height * 100 + 0.5));
    json_object_object_add(fileObj, "material", json_object_new_string(current_file.material));
    json_object_object_add(fileObj, "nozzleTemp", json_object_new_int(current_file.nozzle_target_temp * 100 + 0.5));
    json_object_object_add(fileObj, "bedTemp", json_object_new_int(current_file.bed_target_temp * 100 + 0.5));
    json_object_object_add(fileObj, "software", json_object_new_string(current_file.software));
    json_object_object_add(fileObj, "thumbnail", json_object_new_string(current_file.thumbnails));
    json_object_object_add(fileObj, "startPixel", json_object_new_int(current_file.startPixel));
    json_object_object_add(fileObj, "endPixel", json_object_new_int(current_file.endPixel));
    json_object_object_add(fileObj, "modelHeight", json_object_new_int(current_file.modelHeight));
    json_object_object_add(fileObj, "layerHeight", json_object_new_int(current_file.layer_height));
    json_object_object_add(fileObj, "preview", json_object_new_string(current_file.preview));
}

/**
 * @description: 
 * @return {*}
 * @param {char} *list
 * @param {json_object} *gcodeFile
 */
static void GetGcodeDetails(char *list, json_object *gcodeFile, int total, int *current)
{
    int fileSize = json_object_array_length(gcodeFile);
    CrLogI("gcode file size = %d", fileSize);

    for (int i = 0; i < fileSize; i++)
    {
        json_object *fileObj = json_object_array_get_idx(gcodeFile, i);
        json_object *typeObj = json_object_object_get(fileObj, "type");
        if (json_object_get_int(typeObj) == DT_DIR) {
            json_object *subfolderObj = json_object_object_get(fileObj, "file");
            GetGcodeDetails(list, subfolderObj, total, current);
            continue;
        }

        // 判断获取U盘文件信息，U盘是否中途拔出
        json_object *pathObj = json_object_object_get(fileObj, "path");
        if (!strstr(json_object_get_string(pathObj), GetUserLocalSdCardPtah()) && 
            !GetPrintState().udiskMount[UDISK_0])
        {
            CrLogW("U disk connection interrupted\n");
            UpdataScanFileProgress(-1);
            break;
        }

        // 提取信息
        CrLogI("get details gcode path = %s", json_object_get_string(pathObj));
        GetSingleGcodeDetails(fileObj);
        *current += 1;
        // 每解析10个文件保存一次缓存，线程强制休眠；提高交互端获取速度
        if ((i % 10) == 0) {
            json_object_to_file_ext(list, gcodeFile, JSON_C_TO_STRING_PRETTY | JSON_C_TO_STRING_NOSLASHESCAPE | JSON_C_TO_STRING_NOZERO);
            usleep(10 * 1000);
        }

        // 扫描文件进度
        int progress = (double)*current / total * 100;
        if (progress < 1) progress = 1;
        else if (progress >= 100) progress = 100;
        CrLogI("scan gcode file progress = %d", progress);
        UpdataScanFileProgress(progress);
    }

    // 保存文件
    json_object_to_file_ext(list, gcodeFile, JSON_C_TO_STRING_PRETTY | JSON_C_TO_STRING_NOSLASHESCAPE | JSON_C_TO_STRING_NOZERO);
}

/**
 * @description: 
 * @return {*}
 * @param {char} *path
 */
static void GetGcodeInformationList(char *path)
{
    // 获取保存路径
    char *source = NULL, *list = NULL;
    if (strstr(path, GetUserLocalSdCardPtah())) {
        source = GetUserLocalGcodeInfoDirPtah();
        list = GetUserLocalGcodeFileInfoPtah();            
    }
    else {
        source = GetUserUdiskGcodeInfoDirPtah();
        list = GetUserUdiskGcodeFileInfoPtah();                 
    }
    CrLogI("path = %s", path);
    CrLogI("source = %s", source);
    CrLogI("list = %s", list);
    
    // 创建文件路径
    if (access(source, F_OK) != 0) {
        char cmd[254] = {0};
        snprintf(cmd, 254, "mkdir -p %s", source);
        
        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    // 获取文件列表
    int gcodeSize = 0;
    json_object *gcodeFile = GetDirectoryInfoSubFile(path, FILE_TIME_REVERSE_SORT, &gcodeSize);
    CrLogI("get gcode size = %d", gcodeSize);
    if (gcodeFile) {
        json_object_to_file_ext(list, gcodeFile, JSON_C_TO_STRING_PRETTY | JSON_C_TO_STRING_NOSLASHESCAPE | JSON_C_TO_STRING_NOZERO);
        // 提取详情信息
        UpdataScanFileProgress(0);
        int count = 0;
        GetGcodeDetails(list, gcodeFile, gcodeSize, &count);
        json_object_put(gcodeFile);
    }
    else CrLogW("get gcode file list fail\n");
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void SystemSyncUdiskState(MsgHeadBuf_t *head)
{
    SendString *path = send_string__unpack(NULL, head->bufLen, head->buf);
    if (!path) {
        CrLogW("unpack failed\n");
        return;
    }

    // 判断是否监听U盘
    if (path->str.len > 0)
    {
        // 提取SD卡gcode文件列表
        pthread_mutex_lock(&getGcodeInfoLock);
        GetGcodeInformationList(GetUserLocalUdiskPtah());
        pthread_mutex_unlock(&getGcodeInfoLock);

        // 监听U盘
        if (!inotifytools_watch_recursively(GetUserLocalUdiskPtah(), IN_USER_EVENTS)) {
            CrLogW("inotifytools_watch_recursively failed\n");
        }

        bzero(userLastUdiskPath, sizeof(userLastUdiskPath));
        strcat(userLastUdiskPath, GetUserLocalUdiskPtah());
    }
    else {
        // 解除监听
        if (!inotifytools_remove_watch_by_filename(userLastUdiskPath)) {
            CrLogW("inotifytools_remove_watch_by_filename failed\n");
        }

        CrLogI("clear the U disk gcode cache info\n");
        // 清空获取信息
        json_object *gcodeFile = json_object_new_array();
        json_object_to_file_ext(GetUserUdiskGcodeFileInfoPtah(), gcodeFile, JSON_C_TO_STRING_PRETTY | JSON_C_TO_STRING_NOSLASHESCAPE | JSON_C_TO_STRING_NOZERO);
        json_object_put(gcodeFile);

        // 清空图片
        char cmd[256] = {0};
        char sysRes[1024] = {0};
        snprintf(cmd, sizeof(cmd), "rm -rf %s/* && sync", GetUserUdiskThumbnailDirPtah());
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) CrLogW("system fail! res = %s\n", sysRes);

        bzero(cmd, sizeof(cmd));
        bzero(sysRes, sizeof(sysRes));
        snprintf(cmd, sizeof(cmd), "rm -rf %s/* && sync", GetUserUdiskOriginalDirPtah());
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) CrLogW("system fail! res = %s\n", sysRes);
    }

    send_string__free_unpacked(path, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *obj
 * @param {char} *fileName
 */
static void AddInfo(json_object *obj, char *fileName)
{
    struct stat statbuf;
    lstat(fileName, &statbuf);

    // 获取文件信息
    json_object *newFile = json_object_new_object();
    json_object_object_add(newFile, "type", json_object_new_int(DT_REG));
    json_object_object_add(newFile, "name", json_object_new_string(strrchr(fileName, '/') + 1));
    json_object_object_add(newFile, "path", json_object_new_string(fileName));
    json_object_object_add(newFile, "file_size", json_object_new_int(statbuf.st_size));
    json_object_object_add(newFile, "create_time", json_object_new_int(statbuf.st_ctime));
    GetSingleGcodeDetails(newFile);

    // 备份原有文件信息
    json_object *oldFileObj = json_tokener_parse(json_object_to_json_string(obj));
    // 删除原有文件信息
    json_object_array_del_idx(obj, 0, json_object_array_length(obj));
    // 插入新文件信息
    json_object_array_add(obj, newFile);

    // 还原原有文件信息
    int arrayLength = json_object_array_length(oldFileObj);
    for (int i = 0; i < arrayLength; i++) {
        json_object* element = json_object_array_get_idx(oldFileObj, i);
        json_object_array_add(obj, element);
        json_object_get(element);
    }

    // 释放资源
    json_object_put(oldFileObj);
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *obj
 * @param {int} num
 */
static void DeleteInfo(json_object *obj, int num)
{
    json_object *fileObj = json_object_array_get_idx(obj, num);
    // 删除缩略图
    json_object *thumbnailObj = json_object_object_get(fileObj, "thumbnail");
    if (thumbnailObj && json_object_is_type(thumbnailObj, json_type_string)) {
        remove(json_object_get_string(thumbnailObj));
    }
    // 删除注水图
    json_object *previewObj = json_object_object_get(fileObj, "preview");
    if (previewObj && json_object_is_type(thumbnailObj, json_type_string)) {
        remove(json_object_get_string(previewObj));
    }
    // 删除当前json对象
    json_object_array_del_idx(obj, num, 1); 
}

/**
 * @description: 
 * @return {*}
 * @param {char} *fileName
 * @param {json_object} *obj
 */
static int AddGcodeInfo(char *fileName, json_object *obj)
{
    for (int i = 0; i < json_object_array_length(obj); i++)
    {
        json_object *fileObj = json_object_array_get_idx(obj, i);

        // 判断类型
        json_object *typeObj = json_object_object_get(fileObj, "type");
        if (json_object_get_int(typeObj) == DT_DIR)
        {
            json_object *subfolderObj = json_object_object_get(fileObj, "file");

            // 提取信息
            json_object *pathObj = json_object_object_get(fileObj, "path");
            const char *getPath = json_object_get_string(pathObj);

            char fileDir[256] = {0};
            strcat(fileDir, fileName);
            strrchr(fileDir, '/')[0] = '\0';

            // 判断是否在同一个文件夹
            if (strcmp(getPath, fileDir) == 0) {
                AddInfo(subfolderObj, fileName);
                return 1;
            }

            if (AddGcodeInfo(fileName, subfolderObj)) return 1;
            else continue;
        }
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *path
 */
static void AddGcodeInformationList(char *path)
{
    // 获取gcode信息缓存文件
    char *source = NULL, *filePath = NULL;
    if (strstr(path, GetUserLocalSdCardPtah())) {
        source = GetUserLocalSdCardPtah();
        filePath = GetUserLocalGcodeFileInfoPtah();
    }
    else {
        source = GetUserLocalUdiskPtah();
        filePath = GetUserUdiskGcodeFileInfoPtah();
    }

    // 获取缓存信息
    json_object *infoObj = json_object_from_file(filePath);
    if (!strchr((path + strlen(source) + 1), '/')) {
        AddInfo(infoObj, path);
    }
    else {
        AddGcodeInfo(path, infoObj);
    }

    json_object_to_file_ext(filePath, infoObj, JSON_C_TO_STRING_PRETTY | JSON_C_TO_STRING_NOSLASHESCAPE | JSON_C_TO_STRING_NOZERO);
    json_object_put(infoObj);
}

/**
 * @description: 
 * @return {*}
 * @param {char} *fileName
 * @param {json_object} *obj
 */
static int DeleteGcodeInfo(char *fileName, json_object *obj)
{
    for (int i = 0; i < json_object_array_length(obj); i++)
    {
        json_object *fileObj = json_object_array_get_idx(obj, i);

        // 判断类型
        json_object *typeObj = json_object_object_get(fileObj, "type");
        if (json_object_get_int(typeObj) == DT_DIR) {
            json_object *subfolderObj = json_object_object_get(fileObj, "file");
            if (DeleteGcodeInfo(fileName, subfolderObj)) return 1;
            else continue;
        }

        // 提取信息
        json_object *pathObj = json_object_object_get(fileObj, "path");
        const char *getPath = json_object_get_string(pathObj);
        if (strcmp(getPath, fileName) == 0)
        {
            DeleteInfo(obj, i);
            return 1;
        }
    }
    return 0;
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

    // 等待获取SD卡路径
    do {
        if (GetPrintState().sdCardExists && access(GetUserLocalSdCardPtah(), F_OK) == 0) break;
        usleep(10 * 1000);
    } while (1);

    // 提取SD卡gcode文件列表
    pthread_mutex_lock(&getGcodeInfoLock);
    CrLogI("get local gcode file info");
    GetGcodeInformationList(GetUserLocalSdCardPtah());
    pthread_mutex_unlock(&getGcodeInfoLock);

    // 提取U盘gcode文件列表
    #ifndef CROSS_COMPILE
    pthread_mutex_lock(&getGcodeInfoLock);
    CrLogI("get udisk gcode file info");
    GetGcodeInformationList(GetUserLocalUdiskPtah());
    pthread_mutex_unlock(&getGcodeInfoLock);
    #endif

    // 监听SD卡路径
    if (!inotifytools_watch_recursively(GetUserLocalSdCardPtah(), IN_USER_EVENTS)) {
        CrLogW("inotifytools_watch_recursively failed\n");
    }

    // 监听U盘路径
    #ifndef CROSS_COMPILE
    if (!inotifytools_watch_recursively(GetUserLocalUdiskPtah(), IN_USER_EVENTS)) {
        CrLogW("inotifytools_watch_recursively failed\n");
    }
    #endif
    
    // 获取监听事件
	while (1)
    {
        struct inotify_event *event = inotifytools_next_event(-1);
        if (!event) {
            sleep(2);
            CrLogE("File monitoring fails\n");
            continue;
        }

        // 获取变化文件路径
        char changePath[256] = {0};
        snprintf(changePath, sizeof(changePath), "%s%s", inotifytools_filename_from_wd(event->wd), event->name);

        // 不响应特殊文件
        if (changePath[0] == '.') continue;
        if (strlen(changePath) > strlen(".gcode") && 
            strcmp(changePath + strlen(changePath) - strlen(".gcode"), ".gcode")) {
            continue;
        }

        // 输出监听事件
        switch (event->mask) {
            case IN_CREATE: CrLogI("Create path = %s", changePath); break;
            case IN_DELETE: CrLogI("Delete path = %s", changePath); break;
            case IN_MOVED_TO: CrLogI("Move to path = %s", changePath); break;
            case IN_MOVED_FROM: CrLogI("Move from path = %s", changePath); break;
            case IN_MODIFY: CrLogI("Modify path = %s", changePath); break;
        }

        // 解析监听事件
        switch (event->mask)
        {
            case IN_DELETE:
            case IN_MOVED_FROM:
            {
                char *filePath = NULL;
                if (strstr(changePath, GetUserLocalSdCardPtah())) filePath = GetUserLocalGcodeFileInfoPtah();  
                else filePath = GetUserUdiskGcodeFileInfoPtah();

                // 删除缓存信息
                json_object *infoObj = json_object_from_file(filePath);
                DeleteGcodeInfo(changePath, infoObj);
                json_object_to_file_ext(filePath, infoObj, JSON_C_TO_STRING_PRETTY | JSON_C_TO_STRING_NOSLASHESCAPE | JSON_C_TO_STRING_NOZERO);
                json_object_put(infoObj);
                break;
            }
            case IN_CREATE:
            case IN_MOVED_TO:
            case IN_MODIFY:
            {
                char *filePath = NULL;
                if (strstr(changePath, GetUserLocalSdCardPtah())) filePath = GetUserLocalGcodeFileInfoPtah();  
                else filePath = GetUserUdiskGcodeFileInfoPtah();

                // 修改缓存信息
                json_object *infoObj = json_object_from_file(filePath);
                DeleteGcodeInfo(changePath, infoObj);
                json_object_to_file_ext(filePath, infoObj, JSON_C_TO_STRING_PRETTY | JSON_C_TO_STRING_NOSLASHESCAPE | JSON_C_TO_STRING_NOZERO);
                json_object_put(infoObj);

                // 增加新文件信息
                AddGcodeInformationList(changePath);
                break;
            }
            default: CrLogI("event->mask = %d\n", event->mask); break;
        }
	}

    inotifytools_cleanup();
    return NULL;
}

/**
 * @description: 管理器初始化
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
MsgHandle_t *ControllerInit(void *arg)
{
    CrLogI("controller init");
    pthread_mutex_init(&getGcodeInfoLock, NULL);

    // 创建消息接收线程
    int res = pthread_create(&msgHandle.handle, NULL, (void*)ManagerThread, arg);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return NULL;
    }
    msgHandle.sendMsgBuff = &SendMsgBuff;

    // 创建获取gcode线程
    pthread_t gcodeHandle;
    res = pthread_create(&gcodeHandle, NULL, (void*)GetGcodeThread, arg);
    if (res) {
        CrLogE("create pthread error!\n");
    }

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
 * @description: 
 * @param  {*}
 * @return {*}
 */
int ControllerExceptionHandleSemPost(void)
{
    inotifytools_cleanup();
    ShmExceptionHandleSemPost(&printObjectShm);
    PlaMaterialPreferExceptionHandleMallocPost();
    KlipperPrintAbnormalExitProcessing();
    KlipperConfigAnlAbnormalExitProcessing();
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *info
 * @param {int} len
 */
int UpdataPrintObjectInfo(char *info, int len)
{
    CrLogI("updata print object info; data len = %d\n", len);
    return WriteDataToShm(&printObjectShm, info, strlen(info));
}

/**
 * @description: 
 * @return {*}
 * @param {PowerLossInfo_t} info
 */
int SavePowerLossPrintInfo(PowerLossInfo_t info)
{
    savePowerLossInfo = info;
    UpdataExistOffContinue(1);
    UserGetPowerLossInfoReq(NULL);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *data
 * @param {long} type
 */
int SaveKlipperCmdSyncRecvData(char *data, long type)
{
    CmdSyncRecv_t send = {0};
    send.mtype = type;
    strcat(send.buf, data);
    size_t len = sizeof(CmdSyncRecv_t) - sizeof(send.buf) + strlen(data) + 1;
    return msgsnd(klipperCmdSyncRecvId, (const void *)&send, len, IPC_NOWAIT);
}

/**
 * @description: 
 * @return {*}
 * @param {CmdSyncRecv_t} *data
 * @param {long} type
 * @param {int} flag 0：阻塞，IPC_NOWAIT：非阻塞
 */
int GetKlipperCmdSyncRecvData(CmdSyncRecv_t *data, long type, int flag)
{
    return msgrcv(klipperCmdSyncRecvId, (void *)data, sizeof(MsgHeadBuf_t), type, flag);
}
