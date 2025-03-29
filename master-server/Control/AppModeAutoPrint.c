/*
 * @Description : 直接打印模式
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-08 18:53:35
 * @LastEditTime: 2023-09-20 09:55:59
 */
#include <errno.h>

#include "Base/MasterMsgBase.h"
#include "AppPrint.h"
#include "AppModeAutoPrint.h"
#include "DefineGcode.h"
#include "PrintControl.h"
#include "Controller.h"
#include "GcodEmetadata.h"


/**
 * @description: 静态变量声明
 * @param  {*}
 * @return {*}
 */
static uint32_t printingTimeCount = 0;
static PrintFileInfo_t printInfo;
static FILE *gcodeFileFd = NULL;
static uint32_t fileLineNum = 0;
static pthread_mutex_t getGcodeCondLock;
static pthread_cond_t getGcodeCond;
static long int recordGcodeStartFileOffset = 0;
static long int recordGcodeRealTotal = 0;
static int deviceRequestCmdNumber = 0;
static char deviceRequestCmd[256] = {0};

static Ring_t ringArray[GCODE_RING_BUFF_DEF_SIZE] = {0};
static RingBuff_t requestGcode, *p_requestGcode;

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *name
 * @param {int} len
 */
void SetAutoPrintInfo(PrintFileInfo_t info) { printInfo = info; }

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {FILE} *fd
 */
static int AutoUpdataPrintProgress(FILE *fd)
{
    // 获取打印进度
    long int currentOffset = ftell(fd);
    if (currentOffset > recordGcodeStartFileOffset)
    {
        int curPrintProgress = (double)(currentOffset - recordGcodeStartFileOffset) / recordGcodeRealTotal * 10000 + 0.5;
        if (curPrintProgress > GetPrintState().printProgress)
        {
            CrLogI("current Print Progress = %d", curPrintProgress);
            UpdataPrintProgress(curPrintProgress);
        }
        // 获取预计剩余时间
        int remainTime = 0;
        PrintState_t curState = GetPrintState();
        uint32_t totalTime = GetPrinter()->current_file.estimated_time;
        if (totalTime)
        {
            if ((curState.printUsageTime / 60 < 20) && (curState.printProgress / 100 < 3)) {
                remainTime = totalTime * 1 - curState.printUsageTime;
            }
            else {
                remainTime = totalTime * 1 * (1 - (double)curState.printProgress/10000);
            }
        }
        UpdataPrintRemainTime(remainTime);
        CrLogI("remainTime = %d", remainTime);
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {FILE} *fd
 * @param {long} *start
 * @param {long} *total
 */
static int GetGcodeFileOffset(FILE *fd, long int *start, long int *total)
{
    int readLen = 1024;
    char readBuff[readLen];
    memset(readBuff, 0, readLen);

    // 获取gcode开始位置
    fseek(fd, 0, SEEK_SET);
    while (fgets(readBuff, readLen, fd) != NULL)
    {
        if ((readBuff[0] == 'G') || (readBuff[0] == 'M') || (readBuff[0] == 'T')) 
        {
            *start = ftell(fd);
            break;
        }
        memset(readBuff, 0, readLen);
    }

    // 获取gcode结束位置
    fseek(fd, 0, SEEK_END);
    *total = ftell(fd) - *start;

    // 复位文件指针
    fseek(fd, 0, SEEK_SET);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {FILE} *fd
 * @param {PrintFileInfo_t} info
 */
static int SetAutoPrintFileOffset(FILE *fd, PrintFileInfo_t info)
{
    // 修改文件偏移到指定层
    fseek(fd, info.fileOffset, SEEK_SET);

    // 去除已使用的gcode命令
    uint32_t count = 0;
    char readBuff[1024];
    while (1)
    {
        if (count >= info.cmdCount) break;
        //
        char *getGcode = fgets(readBuff, 1024, fd);
        if (getGcode == NULL)
        {
            CrLogE("Modify file offset error\n");
            break;
        }

        if ((readBuff[0] != 'G') && (readBuff[0] != 'M') && (readBuff[0] != 'T')) 
            continue;
        else count++;
    }
    
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int ClearRequestRingBuff(void)
{
    Ring_t ringBuff = {0};
    while (!RingBuffEmpty(p_requestGcode))
        RingBuffPoll(p_requestGcode, &ringBuff);

    return 0;
}

/**
 * @description: 进入
 * @param  {*}
 * @return {*}
 */
void EnterAppAutoPrint(void)
{
    CrLogI("enter app mode auto print");
    CrLogI("prin file name = %s\n", printInfo.fileName);
    SetAppStateChange(APP_PRINT_STATE_WORK);

    fileLineNum = 0;
    gcodeFileFd = fopen(printInfo.fileName, "r");
    if (gcodeFileFd == NULL)
    {
        CrLogW("gcode file open failed = %s\n", printInfo.fileName);
    }
    recordGcodeStartFileOffset = 0;
    recordGcodeRealTotal = 0;
    GetGcodeFileOffset(gcodeFileFd, &recordGcodeStartFileOffset, &recordGcodeRealTotal);
    CrLogI("recordGcodeStartFileOffset = %d, recordGcodeRealTotal = %d", recordGcodeStartFileOffset, recordGcodeRealTotal);

    // 断电续打时，修正文件偏移、打印时间、打印进度
    SetAutoPrintFileOffset(gcodeFileFd, printInfo);
    UpdataPrintUsageTime(printInfo.usedTime);
    AutoUpdataPrintProgress(gcodeFileFd);

    ClearRequestRingBuff();
    printingTimeCount = 0;
    deviceRequestCmdNumber = 0;
    // 如果是主动下发命令，则使能发送
    if (GetSystemConfig().swap_way == APP_SWAP_WAY_ACTIVELY_SEND) EnableRequestSendGcodeCmd();
    else {
        // 开始下位机主动获取 gcode 指令
        EnableAutoGetGcodeCmd();
        CrLogI("Set the lower computer to actively acquire");
        String_t tCmd = {0};
        char sendBuff[300] = {0};
        snprintf(sendBuff, 300, "%s %s", CXSW_SET_PRINT_FILE_INFO, printInfo.fileName);
        tCmd.data = sendBuff;
        tCmd.len = strlen(sendBuff);
        AddGcodeListCmd(CXSW_SET_PRINT_FILE_INFO_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);
            
        memset(sendBuff, 0, 300);
        snprintf(sendBuff, 300, "%s S1", CXSW_SET_ACTIVELY_ACQUIRE);
        tCmd.data = sendBuff;
        tCmd.len = strlen(sendBuff);
        AddGcodeListCmd(CXSW_SET_ACTIVELY_ACQUIRE_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
void CalculatePrintingTime(void)
{
    if (GetCurrentAppstate() == APP_PRINT_STATE_WORK)
    {
        if (++printingTimeCount > 100)
        {
            printingTimeCount = 0;
            UpdataPrintUsageTime(GetPrintState().printUsageTime + 1);
        }
    }
}

/**
 * @description: 运行
 * @param  {*}
 * @return {*}
 */
void ExecuteAppAutoPrint(void)
{
    AppSendPrintState();
    AutoGetGetPrinterStatus();
    CalculatePrintingTime();
}

/**
 * @description: 退出
 * @param  {*}
 * @return {*}
 */
void ExitAppAutoPrint(void)
{
    CrLogI("exit app mode auto print\n");
    fileLineNum = 0;
    fclose(gcodeFileFd);
    gcodeFileFd = NULL;
    printingTimeCount = 0;

    // 保存打印时间到配置文件
    CumulativePrintingTime();
    // 上传流逝影像
    UploadDelayImage();
    //上报打印记录
    UploadPrintHistoryRecord(true);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int EnableAutoGetGcodeCmd(void)
{
    pthread_mutex_lock(&getGcodeCondLock);
    pthread_cond_signal(&getGcodeCond);
    pthread_mutex_unlock(&getGcodeCondLock);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int EnableRequestSendGcodeCmd(void)
{
    // 从环形缓冲区提取指令
    if (!RingBuffEmpty(p_requestGcode)) {
        Ring_t ringBuff = {0};
        RingBuffPoll(p_requestGcode, &ringBuff);
        // 发送指令
        String_t tCmd = {0};
        tCmd.data = ringBuff.cmd;
        tCmd.len = strlen(ringBuff.cmd);
        AddGcodeListCmd(AUTO_PRINT_SEND_GCODE_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);
    }
    else if (GetCurrentAppstate() == APP_PRINT_STATE_WORK) 
    {
        CrLogW("device next request cmd no refresh\n");
        String_t tCmd = {0};
        tCmd.data = GET_CUR_HOTEND_BED_TEMP;
        tCmd.len = strlen(GET_CUR_HOTEND_BED_TEMP);
        AddGcodeListCmd(AUTO_PRINT_SEND_GCODE_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);
    }

    usleep(1); // 释放线程，让串口发送先执行
    // 获取下一条指令
    EnableAutoGetGcodeCmd();

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {uint32_t} line
 */
int EnableRequestGetGcodeCmd(uint32_t line)
{
    // 停止状态下不回复gcode请求
    if (GetCurrentAppstate() == APP_PRINT_STATE_STOP)
    {
        CrLogW("stop state, not reply gcode requests\n");
        return 0;
    }

    CrLogI("line = %d, last = %d", line, deviceRequestCmdNumber);
    if (deviceRequestCmdNumber != line)
    {
        deviceRequestCmdNumber = line;
        // 从环形缓冲区提取指令
        if (!RingBuffEmpty(p_requestGcode)) {
            Ring_t ringBuff = {0};
            RingBuffPoll(p_requestGcode, &ringBuff);
            // 合成指令并发送
            memset(deviceRequestCmd, 0, 256);
            snprintf(deviceRequestCmd, 256, "$%d%s\n", line, ringBuff.cmd);
            AppEnforceUartSend(deviceRequestCmd, strlen(deviceRequestCmd));
        }
        else if (GetCurrentAppstate() == APP_PRINT_STATE_FINISH)
        {
            // 停止下位机主动获取 gcode 指令
            CrLogI("print finish, stop answer gcode request!!!\n");
            String_t tCmd = {0};
            char sendBuff[100] = {0};
            snprintf(sendBuff, 100, "%s S0", CXSW_SET_ACTIVELY_ACQUIRE);
            tCmd.data = sendBuff;
            tCmd.len = strlen(sendBuff);
            AddGcodeListCmd(CXSW_SET_ACTIVELY_ACQUIRE_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);
        }
        else 
        {
            CrLogW("device next request cmd no refresh\n");
            AppEnforceUartSend(deviceRequestCmd, strlen(deviceRequestCmd));
        }

        usleep(1); // 释放线程，让串口发送先执行
        // 获取下一条指令
        EnableAutoGetGcodeCmd();
    }
    else
    {
        AppEnforceUartSend(deviceRequestCmd, strlen(deviceRequestCmd));
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *buf
 * @param {uint32_t} *layerNum
 */
static bool GetPrintLayerNumFromGcodeFile(char *buf, uint32_t *layerNum)
{
    if (strstr(buf, GET_LAYER_CHANGES) ||
        strstr(buf, GET_LAYER_CHANGES_1) ||
        strstr(buf, GET_LAYER_CHANGES_2) ||
        strstr(buf, GET_LAYER_CHANGES_3) ||
        strstr(buf, GET_LAYER_CHANGES_4))
    {
        char *regex = "[-|+]?[0-9]{1,10}";
        regmatch_t regmatch[5];
        UserGetRegexStr(buf, regex, regmatch, 5);

        int cnt = regmatch[0].rm_eo - regmatch[0].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &buf[regmatch[0].rm_so], cnt);
        str[cnt] = '\0';
        *layerNum = atoll(str);

        return true;
    }

    return false;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {FILE} *fd
 * @param {char} *cmd
 */
static int ReadGcodeCmdFormLocalFile(FILE *fd, char *cmd)
{
    int readLen = 1024;
    char readBuff[readLen];
    memset(readBuff, 0, readLen);

    while (1)
    {
        char *getGcode = fgets(readBuff, readLen, fd);
        if (getGcode == NULL)
        {
            CrLogI("Print Finish\n");
            memset(readBuff, 0, readLen);
            SetAppModeChange(APP_MODE_IDLE);
            UpdataPrintProgress(100 * 100);
            UpdataPrintRemainTime(0);
            SetAppStateChange(APP_PRINT_STATE_FINISH);

            // 解锁电机
            Ring_t motor = {0};
            memcpy(motor.cmd, SET_DEVICE_MOTOR_UNLOCK, strlen(SET_DEVICE_MOTOR_UNLOCK));
            RingBuffPush(p_requestGcode, motor);

            // 停止自动打印
            if (GetSystemConfig().swap_way == APP_SWAP_WAY_PASSIVE_SEND)
            {
                CrLogI("Stop actively acquiring the lower computer");
                // 停止打印
                Ring_t stopPrint = {0};
                memcpy(stopPrint.cmd, CXSW_SET_STOP_PRINTING, strlen(CXSW_SET_STOP_PRINTING));
                RingBuffPush(p_requestGcode, stopPrint);
            }
            
            // 打印完成
            GcodeCmdRes finish = GCODE_CMD_RES__INIT;
            finish.result = 1;
            GET_MESSAGE_BUFF(buff);
            size_t len = gcode_cmd_res__pack(&finish, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_DEVICE_PRINT_FINISH, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
            break;
        }
        // 计算文件行号
        fileLineNum++;

        // 获取文件层数文件偏移，设置给下位机，用作断电续打
        uint32_t layerNum = 0;
        if (GetPrintLayerNumFromGcodeFile(readBuff, &layerNum))
        {
            // 组装文件偏移设置命令
            char offsetStr[20] = {0};
            sprintf(offsetStr, "%ld", ftell(fd));
            CrLogI("offsetStr = %s", offsetStr);
            char timeStr[20] = {0};
            sprintf(timeStr, "%d", GetPrintState().printUsageTime);
            CrLogI("timeStr = %s", timeStr);

            Ring_t ringBuff = {0};
            snprintf(ringBuff.cmd, (sizeof(ringBuff.cmd)/sizeof(ringBuff.cmd[0])),
                        "%s O%s T%s", CXSW_SET_OFFSET_AND_TIME, offsetStr, timeStr);
            CrLogI("layer change = %s", ringBuff.cmd);
            RingBuffPush(p_requestGcode, ringBuff);

            // 更新层数
            UpdataPrintLayer(layerNum);
            CrLogI("layer num = %d\n", GetPrintState().printLayer);

            // 更新打印进度
            AutoUpdataPrintProgress(fd);

            // 缓冲区满，退出读取
            if (GetRingBuffSize(p_requestGcode) <= GCODE_RING_BUFF_IDLE_SIZE) break;
            else {
                memset(readBuff, 0, readLen);
                continue;
            }
        }

        // 解析Gcode
        if ((readBuff[0] != 'G') && (readBuff[0] != 'M') && (readBuff[0] != 'T')) 
        {
            memset(readBuff, 0, readLen);
            continue;
        }
        else
        {
            char *notes = strstr(readBuff, " ;");
            if (notes) notes[0] = '\0';
            else
            {
                char *line1 = strstr(readBuff, "\r\n");
                char *line2 = strstr(readBuff, "\n");
                char *line3 = strstr(readBuff, "\r");
                if (line1) line1[0] = '\0';
                else if (line2) line2[0] = '\0';
                else if (line3) line3[0] = '\0';
            }
            CrLogD("[line = %d]", fileLineNum);

            // 判断设置风扇状态
            char *fanOpen = strstr(readBuff, "M106 S");
            if (fanOpen)
            {
                double speed = atof(fanOpen + strlen("M106 S"));
                if (speed > 0) UpdataPrintFanState(1, MULTI_FAN_MODEL);
                else UpdataPrintFanState(0, MULTI_FAN_MODEL);
                CrLogI("current fan state = %d, speed = %f", GetPrintState().fanState[MULTI_FAN_MODEL], speed);
            }
            if (strstr(readBuff, "M107"))
            {
                UpdataPrintFanState(0, MULTI_FAN_MODEL);
                CrLogI("current fan state = %d", GetPrintState().fanState[MULTI_FAN_MODEL]);
            }

            // 判断设置打印倍速
            char *doubleSpeed = strstr(readBuff, "M220 S");
            if (doubleSpeed)
            {
                int speed = atoi(doubleSpeed + strlen("M220 S"));
                UpdataPrintSpeed(speed);
                CrLogI("current print double speed = %d, speed = %d", GetPrintState().printSpeed, speed);
            }

            // 更新下一条发送指令
            CrLogI("nextCmd = %s\n", readBuff);
            Ring_t ringBuff = {0};
            memcpy(ringBuff.cmd, readBuff, strlen(readBuff));
            RingBuffPush(p_requestGcode, ringBuff);

            // 更新打印进度
            AutoUpdataPrintProgress(fd);

            // 缓冲区满，退出读取
            if (GetRingBuffSize(p_requestGcode) <= GCODE_RING_BUFF_IDLE_SIZE) break;
        }
        memset(readBuff, 0, readLen);
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
static void *AutoGetGcodeCmdThread(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&getGcodeCondLock);
        pthread_cond_wait(&getGcodeCond, &getGcodeCondLock);
        pthread_mutex_unlock(&getGcodeCondLock);

        if (GetCurrentAppstate() == APP_PRINT_STATE_WORK)
        {
            ReadGcodeCmdFormLocalFile(gcodeFileFd, NULL);
        }
    }

    return NULL;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int AppModeAutoPrintInit(void)
{
    pthread_mutex_init(&getGcodeCondLock, NULL);
    pthread_cond_init(&getGcodeCond, NULL);
    // 初始化读取gcode指令环形缓冲区
    p_requestGcode = &requestGcode;
    RingBuffInit(p_requestGcode, ringArray, GCODE_RING_BUFF_DEF_SIZE);

    // 设置实时线程优先级
    struct sched_param getCmdParam;
    getCmdParam.sched_priority = GET_GCODE_CMD_THREAD_PRIORITY;
    pthread_attr_t getCmdAttr;
    pthread_attr_init(&getCmdAttr);
    pthread_attr_setinheritsched(&getCmdAttr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&getCmdAttr, SCHED_RR);
    if(pthread_attr_setschedparam(&getCmdAttr, &getCmdParam) != 0)
    {
        CrLogW("setschedpolicy getCmdAttr NG! \n");
    }
    // 实时线程
    pthread_t getGcodehandle;
    int res = pthread_create(&getGcodehandle, &getCmdAttr, (void*)AutoGetGcodeCmdThread, NULL);
    if (res) {
        // 返回值为1，是没有权限来设置调度策略及参数定义。修改调度策略，需要在ROOT权限下来执行
        CrLogE("create pthread error! res = %d, %s\n", res, strerror(errno));
        return -1;
    }

    return 0;
}
