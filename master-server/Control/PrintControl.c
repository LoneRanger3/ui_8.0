/*
 * @Description : 打印控制
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-14 18:22:07
 * @LastEditTime: 2023-07-18 14:06:45
 */
#include <sys/time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>

#include "Base/MasterMsgBase.h"
#include "PrintControl.h"
#include "SerialPort.h"
#include "SocketKlipper.h"
#include "DefineGcode.h"
#include "GcodeCmdResAnl.h"
#include "AppPrint.h"
#include "AppFuncModule.h"
#include "GcodEmetadata.h"
#include "Controller.h"

#define SOCKET_COMMUNICATION_OUT_TIME   100 // 超时时间10s，100ms周期
#define DEFAULT_SENDING_TIMEOUT         100 // 默认重发时间10s，100ms周期
#define DEFAULT_RETRANSMISSION_TIMES    0 // 默认重发次数
#define SEND_GCODE_LIST_MAX_SIZE        50 // gcode发送缓存链表最大值
#define SEND_GCODE_LIST_ENABLE_SIZE     (SEND_GCODE_LIST_MAX_SIZE - 20) // gcode发送缓存链表动态可用大小
#define SERIAL_PORT_MAX_DATA_FRAME_LEN  2048 // 处理最大窗口数据帧长度

#define KLIPPER_RECV_MAX_LEN            (1024 * 2) // 默认接收最大长度

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static pthread_mutex_t sendGcodeCondLock;
static pthread_cond_t sendGcodeCond;
static struct list_head gcodeSendList; // 定义gcode发送链表
static pthread_rwlock_t sendRwLock; // 声明读写锁
static GcodeSend_t currentSendCmd = {0}; // 当前发送指令
static int lastSerialPortFd = -1; // 前一次句柄状态
static int socketOutTimeCount = 0; // socket通信超时计数

/**
 * @description: 静态函数声明
 * @param  {*}
 * @return {*}
 */
static void *SerialPortRecvThread(void);
static void *SerialPortSendThread(void);
static void *CUSBListenerThread(void);
static void *SerialPortTimeOutResendThread(void);
static int SerialPortRecvResponse(char *buf, int len);
static int ResetSendTimeOutCount(void);


/**
 * @description: 
 * @return {*}
 */
static void SocketOutTimeCountClear(void) { socketOutTimeCount = 0; }


/**
 * @description: 
 * @return {*}
 */
static bool IsSocketOutTime(void)
{
    if (socketOutTimeCount >= SOCKET_COMMUNICATION_OUT_TIME) {
        SocketOutTimeCountClear();
        return true;
    }

    socketOutTimeCount++;
    return false;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {uint32_t} cmd
 */
static uint32_t GetSendResend(uint32_t cmd)
{
    switch (cmd)
    {
        case AUTO_PRINT_SEND_GCODE_NUM: return 3;
        case SERIAL_PORT_HANDSHAKE_NUM: return 1;
        default: return DEFAULT_RETRANSMISSION_TIMES;
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {uint32_t} cmd
 */
static uint32_t GetSendOutTime(uint32_t cmd)
{
    switch (cmd)
    {
        case AUTO_PRINT_SEND_GCODE_NUM: return 30;
        case SERIAL_PORT_HANDSHAKE_NUM: return 20;
        default: return DEFAULT_SENDING_TIMEOUT;
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {  } memset
 */
void CleanCurrentSendCmd(void) { memset(&currentSendCmd, 0, sizeof(GcodeSend_t)); }

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *send_buf
 * @param {int} data_len
 */
int AppEnforceUartSend(char *send_buf, int data_len)
{
    CrLogI("send gcode; len = %d, cmd = %s", data_len, send_buf);
    UART_Send(send_buf, data_len);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int EnableSendGcodeCmd(void)
{
    pthread_mutex_lock(&sendGcodeCondLock);
    pthread_cond_signal(&sendGcodeCond);
    pthread_mutex_unlock(&sendGcodeCondLock);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int GetGcodeListSize()
{
    int size = 0;
    struct list_head *ltemp = NULL;
    list_for_each(ltemp, &gcodeSendList){
        size++;
    }
    return size;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int GetGcodeListSizeLock()
{
    int size = 0;
    struct list_head *ltemp = NULL;

    pthread_rwlock_rdlock(&sendRwLock);
    list_for_each(ltemp, &gcodeSendList){
        size++;
    }
    pthread_rwlock_unlock(&sendRwLock);

    return size;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {uint32_t} cmd
 * @param {uint32_t} num
 * @param {int8_t} *data
 * @param {uint32_t} len
 * @param {uint32_t} origin
 */
int AddGcodeListCmd(uint32_t cmd, uint32_t num, String_t *cmdStr, uint32_t origin)
{
    if (GetGcodeListSizeLock() >= SEND_GCODE_LIST_ENABLE_SIZE)
    {
        CrLogW("send gcode list full space!\n");
        return -1;
    }
    
    GcodeSend_t *send = (GcodeSend_t *)malloc(sizeof(GcodeSend_t));
    if (send == NULL) 
    {
        CrLogW("Unable to allocate memory\n");
        return -1;
    }

    memset(send, 0, sizeof(GcodeSend_t));
    send->sendFlag = true;
    send->resend = GetSendResend(cmd);
    send->outTime = GetSendOutTime(cmd);
    send->timeCount = send->outTime;

    send->origin = origin;
    send->cmd = cmd;
    send->lineNum = num;

    memset(send->cmdStr, 0, sizeof(send->cmdStr)/sizeof(send->cmdStr[0]));
    memcpy(send->cmdStr, cmdStr->data, cmdStr->len);
    send->cmdStr[cmdStr->len] = '\n';

    pthread_rwlock_wrlock(&sendRwLock);
    list_add_tail(&send->node, &gcodeSendList);
    EnableSendGcodeCmd();
    pthread_rwlock_unlock(&sendRwLock);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {uint32_t} cmd
 * @param {uint32_t} num
 * @param {String_t} *cmdStr
 * @param {uint32_t} origin
 */
int AddGcodeListHeadCmd(uint32_t cmd, uint32_t num, String_t *cmdStr, uint32_t origin)
{
    if (GetGcodeListSizeLock() >= SEND_GCODE_LIST_MAX_SIZE)
    {
        CrLogW("send gcode list full space!\n");
        return -1;
    }
    
    GcodeSend_t *send = (GcodeSend_t *)malloc(sizeof(GcodeSend_t));
    if (send == NULL) 
    {
        CrLogW("Unable to allocate memory\n");
        return -1;
    }

    memset(send, 0, sizeof(GcodeSend_t));
    send->sendFlag = true;
    send->resend = GetSendResend(cmd);
    send->outTime = GetSendOutTime(cmd);
    send->timeCount = send->outTime;

    send->origin = origin;
    send->cmd = cmd;
    send->lineNum = num;

    memset(send->cmdStr, 0, sizeof(send->cmdStr)/sizeof(send->cmdStr[0]));
    memcpy(send->cmdStr, cmdStr->data, cmdStr->len);
    send->cmdStr[cmdStr->len] = '\n';

    pthread_rwlock_wrlock(&sendRwLock);
    list_add(&send->node, &gcodeSendList);
    EnableSendGcodeCmd();
    pthread_rwlock_unlock(&sendRwLock);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {uint32_t} cmd
 * @param {uint32_t} num
 * @param {String_t} *cmdStr
 * @param {uint32_t} origin
 */
int AddGcodeListHeadSecondCmd(uint32_t cmd, uint32_t num, String_t *cmdStr, uint32_t origin)
{
    if (GetGcodeListSizeLock() >= SEND_GCODE_LIST_MAX_SIZE)
    {
        CrLogW("send gcode list full space!\n");
        return -1;
    }
    
    GcodeSend_t *send = (GcodeSend_t *)malloc(sizeof(GcodeSend_t));
    if (send == NULL) 
    {
        CrLogW("Unable to allocate memory\n");
        return -1;
    }

    memset(send, 0, sizeof(GcodeSend_t));
    send->sendFlag = true;
    send->resend = GetSendResend(cmd);
    send->outTime = GetSendOutTime(cmd);
    send->timeCount = send->outTime;

    send->origin = origin;
    send->cmd = cmd;
    send->lineNum = num;

    memset(send->cmdStr, 0, sizeof(send->cmdStr)/sizeof(send->cmdStr[0]));
    memcpy(send->cmdStr, cmdStr->data, cmdStr->len);
    send->cmdStr[cmdStr->len] = '\n';

    pthread_rwlock_wrlock(&sendRwLock);
    __list_add(&send->node, (&gcodeSendList)->next, (&gcodeSendList)->next->next);
    EnableSendGcodeCmd();
    pthread_rwlock_unlock(&sendRwLock);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *data
 */
static int GetFirstGcodeListCmd(GcodeSend_t *data)
{
    pthread_rwlock_rdlock(&sendRwLock);
    if (!list_empty(&gcodeSendList))
    {
        memcpy(data, list_entry(gcodeSendList.next, GcodeSend_t, node), sizeof(GcodeSend_t));
        pthread_rwlock_unlock(&sendRwLock);
        return 0;
    }
    else
    {
        pthread_rwlock_unlock(&sendRwLock);
        return -1;
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {GcodeSend_t} *del
 */
static int DelFirstGcodeListCmd(void)
{
    // 缓存即将删除的指令号
    uint32_t tempCmd = currentSendCmd.cmd;

    pthread_rwlock_wrlock(&sendRwLock);
    if (!list_empty(&gcodeSendList))
    {
        GcodeSend_t *del = list_entry(gcodeSendList.next, GcodeSend_t, node);
        if (del != NULL)
        {
            CrLogI("delete gcode cmd = %s", del->cmdStr);
            list_del_init(&del->node);
            free(del);
            del = NULL;
        }
    }

    CleanCurrentSendCmd();
    if (GetGcodeListSize() > 0) EnableSendGcodeCmd();
    pthread_rwlock_unlock(&sendRwLock);

    // 挂起线程，释放CPU，发送线程先执行
    if (tempCmd == SET_PARK_HEAD_PRINT_NUM ||
        tempCmd == SET_BREAK_CONTINUE_PEINR_NUM)
        usleep(10 * 1000);
    else usleep(10);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int ClearSendGcodeListNoPrintCmd(void)
{
    // 链表为空
    if (list_empty(&gcodeSendList)) {
        CrLogW("linked list is empty\n");
        return 0;
    }

    pthread_rwlock_wrlock(&sendRwLock);
    GcodeSend_t *temp = NULL, *snext = NULL;
    list_for_each_entry_safe(temp, snext, &gcodeSendList, node){
        // 删除周期性查询指令
        if (temp->cmd == GET_CUR_HOTEND_BED_TEMP_NUM ||
            temp->cmd == CXSW_GET_PRINT_STATUS_NUM ||
            temp->cmd == GET_DEVICE_PRINT_PROGRESS_NUM)
        {
            list_del_init(&temp->node);
            if (temp != NULL)
            {
                free(temp);
                temp = NULL;
            }
        }
	}
    pthread_rwlock_unlock(&sendRwLock);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int ClearSendGcodeList(void)
{
    // 链表为空
    if (list_empty(&gcodeSendList)) {
        CrLogW("linked list is empty\n");
        return 0;
    }

    pthread_rwlock_wrlock(&sendRwLock);
    GcodeSend_t *del = NULL, *snext = NULL;
    list_for_each_entry_safe(del, snext, &gcodeSendList, node){
        list_del_init(&del->node);
        if (del != NULL)
        {
            free(del);
            del = NULL;
        }   
	}
    pthread_rwlock_unlock(&sendRwLock);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int StartSerialPortHandshake(void)
{
    // 串口未连接
    UpdataSerialPort(0);
    UpdataSdCardExists(0);
    // 清空当前发送指令
    CleanCurrentSendCmd();
    // 发送与打印机握手信号（查询温度）
    String_t tCmd = {0};
    tCmd.data = GET_CUR_HOTEND_BED_TEMP;
    tCmd.len = strlen(GET_CUR_HOTEND_BED_TEMP);
    AddGcodeListHeadCmd(SERIAL_PORT_HANDSHAKE_NUM, 0, &tCmd, MSG_ORIGIN_CONTROLLER);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int ResetSendTimeOutAndPuaseGetTemp(void)
{
    ResetSendTimeOutCount();
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_PUASE_GET_HOTEND_BED_TEMP, "", 0);
    MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int DevicePrintWorkBusy(char *buf, int bufLen)
{
    if (strstr(buf, PTINT_WORK_BUSY))
    {
        ResetSendTimeOutAndPuaseGetTemp();
        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int UpdataGcodeSend()
{
    pthread_mutex_lock(&sendGcodeCondLock);
    pthread_cond_wait(&sendGcodeCond, &sendGcodeCondLock);
    pthread_mutex_unlock(&sendGcodeCondLock);
        
    if (!currentSendCmd.sendFlag)
    {
        GcodeSend_t cmdData;
        memset(&cmdData, 0, sizeof(GcodeSend_t));
        if (GetFirstGcodeListCmd(&cmdData) == -1) return -1;

        // 排除已发送指令，不重复发送
        if (cmdData.cmd != SET_BREAK_CONTINUE_PEINR_NUM)
        {
            CrLogI("send gcode; cmd = %d, len = %d", cmdData.cmd, strlen((char*)cmdData.cmdStr));
            CrLogD("send data = %s", cmdData.cmdStr);
            UART_Send((char*)cmdData.cmdStr, strlen((char*)cmdData.cmdStr));
        }
        else CrLogW("The command has been sent, not repeated\n");

        // 排除没有应答指令，发送后立刻删除
        if (cmdData.cmd == AUTO_PRINT_REQUEST_GCODE_NUM) DelFirstGcodeListCmd();
        else memcpy(&currentSendCmd, &cmdData, sizeof(GcodeSend_t));
    }
    
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int PrintControlInit()
{
    SerialPortInit();
    pthread_mutex_init(&sendGcodeCondLock, NULL);
    pthread_cond_init(&sendGcodeCond, NULL);
    pthread_rwlock_init(&sendRwLock, NULL);
    INIT_LIST_HEAD(&gcodeSendList);
    CleanCurrentSendCmd();

    // 设置实时线程优先级
    struct sched_param recvParam;
    recvParam.sched_priority = SERIAL_PORT_RECV_THREAD_PRIORITY;
    pthread_attr_t recvAttr;
    pthread_attr_init(&recvAttr);
    pthread_attr_setinheritsched(&recvAttr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&recvAttr, SCHED_RR);
    if(pthread_attr_setschedparam(&recvAttr, &recvParam) != 0)
    {
        CrLogW("setschedpolicy recvAttr NG! \n");
    }
    // 实时线程
    pthread_t recvHandle;
    int res = pthread_create(&recvHandle, &recvAttr, (void*)SerialPortRecvThread, NULL);
    if (res) {
        // 返回值为1，是没有权限来设置调度策略及参数定义。修改调度策略，需要在ROOT权限下来执行
        CrLogE("create Serial Port Recv pthread error! res = %d, %s\n", res, strerror(errno));
        return -1;
    }

    // 设置实时线程优先级
    struct sched_param sendParam;
    sendParam.sched_priority = SERIAL_PORT_SEND_THREAD_PRIORITY;
    pthread_attr_t sendAttr;
    pthread_attr_init(&sendAttr);
    pthread_attr_setinheritsched(&sendAttr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&sendAttr, SCHED_FIFO);
    if(pthread_attr_setschedparam(&sendAttr, &sendParam) != 0)
    {
        CrLogW("setschedpolicy sendAttr NG! \n");
    }
    // 实时线程
    pthread_t sendHandle;
    res = pthread_create(&sendHandle, &sendAttr, (void*)SerialPortSendThread, NULL);
    if (res) {
        // 返回值为1，是没有权限来设置调度策略及参数定义。修改调度策略，需要在ROOT权限下来执行
        CrLogE("create Serial Port Send pthread error! res = %d, %s\n", res, strerror(errno));
        return -1;
    }

    // USB热拔插检测
    pthread_t listenerHandle;
    res = pthread_create(&listenerHandle, NULL, (void*)CUSBListenerThread, NULL);
    if (res)
    {
        CrLogE("create CUSB Listener pthread error!");
    }

    // 串口超时重发检测
    pthread_t TimeOutResendHandle;
    res = pthread_create(&TimeOutResendHandle, NULL, (void*)SerialPortTimeOutResendThread, NULL);
    if (res)
    {
        CrLogE("create Serial Port TimeOut Resend pthread error!");
    }

    return 0;
}

/**
 * @description: 串口数据发送
 * @param  {*}
 * @return {*}
 */
static void *SerialPortSendThread(void)
{
    while (1)
    {
        UpdataGcodeSend();
        // usleep(1000 * 10);
    }

    return NULL;
}

/**
 * @description: 串口接收数据线程
 * @param  {*}
 * @return {*}
 */
static void *SerialPortRecvThread(void)
{
    while (1)
    {
        char rcv_buf[SERIAL_PORT_RECV_MAX_LEN];
        int len = 0;
        UART_Recv(rcv_buf, &len);   // 内部有系统状态监听，10s超时
        if(len > 0)
        {
            rcv_buf[len] = '\0';
            SerialPortRecvResponse(rcv_buf, len);
        }
        // usleep(1000 * 10);
    }

    return NULL;
}

/**
 * @description: 监听串口拔插状态
 * @param  {*}
 * @return {*}
 */
static void *CUSBListenerThread(void)
{
    CUSBListenerRun();
    return NULL;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int ResetSendTimeOutCount(void) { currentSendCmd.timeCount = currentSendCmd.outTime; return 0; }

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static void *SerialPortTimeOutResendThread(void)
{
    // 启动串口握手
    StartSerialPortHandshake();
    while (1)
    {
        usleep(100 * 1000);
        // 判断串口句柄是否存在
        if (GetSerialPortFd() == -1)
        {
            if (GetSerialPortFd() != lastSerialPortFd)
            {
                lastSerialPortFd = GetSerialPortFd();
                StartSerialPortHandshake();
            }
            continue;
        }
        lastSerialPortFd = GetSerialPortFd();
        // 判断是否有数据正在发送
        if (!currentSendCmd.sendFlag) continue;
        // 判断超时时间是否到0
        if (currentSendCmd.timeCount != 0)
        {
            currentSendCmd.timeCount--;
            continue;
        }
        // 判断重发次数是否到0
        if (currentSendCmd.resend != 0)
        {
            CrLogW("Send timeout, resend command; cmd = %d", currentSendCmd.cmd);
            // 重新发送
            UART_Send((char*)currentSendCmd.cmdStr, strlen((char*)currentSendCmd.cmdStr));
            // 通信异常，暂停一次上位机自动获取打印状态
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_PUASE_GET_HOTEND_BED_TEMP, "", 0);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
            // 重新计算超时
            currentSendCmd.timeCount = currentSendCmd.outTime;
            // 串口握手指令会无限重发，直到发送成功，不计算重发次数
            if (currentSendCmd.cmd != SERIAL_PORT_HANDSHAKE_NUM)
                currentSendCmd.resend--;
            continue;
        }
        
        // 串口通信出现异常, 尝试重新连接串口
        CrLogE("Send timeout, resend fail; cmd = [%d]\n\n", currentSendCmd.cmd);
        // 重新启动串口握手
        StartSerialPortHandshake();
    }
    
    return 0;
}

/**
 * @description: 通过文件id，从gcode缓存文件读出指定文件id的文件信息
 * @return {*}
 * @param {char} *path
 * @param {int} id
 * @param {char} *info
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
 * @description: 通过文件名称，从gcode缓存文件读出指定文件id的文件信息
 * @return {*}
 * @param {char} *path
 * @param {char} *name
 * @param {int} *line
 */
json_object *GetFileInfoToNameFromCache(char *path, char *name, int *line)
{
    CrLogI("get file info; cache path = %s, name = %s\n", path, name);
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
        // 获取文件名称
        json_object *nameObj = json_object_object_get(infoObj, "fileName");
        if (nameObj == NULL || !json_object_is_type(nameObj, json_type_string))
        {
            json_object_put(infoObj);
            memset(readBuff, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            continue;
        }
        // 获取指定文件名称的信息
        if (strcmp(json_object_get_string(nameObj), name) == 0)
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
 * @description: 修改gcode缓存文件，指定行数的文件信息
 * @return {*}
 * @param {char} *cachePath
 * @param {int} line
 * @param {json_object} *info
 */
int ReviseFileInfoToCache(char *path, int line, json_object *info)
{
    FILE *cacheFd = fopen(path, "r");
    if (cacheFd == NULL) {
        CrLogE("open %s error", path);
        return -1;
    }
    // 创建临时文件
    char *tempSavePath = "/tmp/gcode_file_info.temp";
    FILE *saveFd = fopen(tempSavePath, "w");
    if (saveFd == NULL) {
        CrLogE("open %s error", tempSavePath);
        return -1;
    }
    // 获取指定文件信息
    int lineCount = 0;
    char readBuff[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};

    // 遍历文件信息缓存
    while (1)
    {
        // 读取准备下一行
        lineCount++;
        bzero(readBuff, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        
        if (!fgets(readBuff, SERIAL_PORT_MAX_DATA_FRAME_LEN, cacheFd) && !feof(cacheFd)) continue;
        if (feof(cacheFd)) break;

        // 判断当前行内容是否需要修改
        if (lineCount == line) {
            fputs(json_object_to_json_string_ext(info, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE), saveFd);
            fputs("\n", saveFd);
        }
        else fputs(readBuff, saveFd);
    }

    // 关闭文件
    fclose(cacheFd);
    fclose(saveFd);

    // 移动文件
    char cmdStr[1024] = {0};
    snprintf(cmdStr, sizeof(cmdStr), "mv %s %s", tempSavePath, path);

    // 调用系统命令
    char sysRes[1024] = {0};
    if (!PopenSystem(cmdStr, sysRes, sizeof(sysRes))) {
        CrLogW("system fail! res = %s\n", sysRes);
        CrLogE("revise file info to cache fail, line = %d", line);
    }

    return 0;
}

/**
 * @description: 文件列表获取gcode文件中模型信息
 * @param  {*}
 * @return {*}
 * @param {uint32_t} origin
 * @param {int} result
 */
int SaveLocalGcodeImageToFile(char *cachePath, uint32_t origin, int result)
{
    // 下位机开始发送SD卡gcode文件缩略图
    CrLogI("start get gcode thumbnail");
    if (access(GetUserTempThumbnailDirPtah(), F_OK) != 0)
    {
        char cmd[254] = {0};
        snprintf(cmd, 254, "mkdir -p %s", GetUserTempThumbnailDirPtah());

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    while(1)
    {
        ControlRange_t fileId = GetUserGetGcodeImageEndFileId();
        if (fileId.current > fileId.end)
        {
            // 发送更新缩略图的文件ID
            ControlRange image = CONTROL_RANGE__INIT;
            image.has_result = 1;
            image.result = result;
            image.has_start = 1;
            image.start = GetUserGetGcodeImageEndFileId().start;
            image.has_end = 1;
            image.end = GetUserGetGcodeImageEndFileId().end;

            GET_MESSAGE_BUFF(buff);
            size_t len = control_range__pack(&image, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_GET_SD_MODEL_IMAGE_ANS, buff, len);
            MANAGER_MSG_SEND(origin, &send, size);
            CrLogI("get user select gcode image finish\n");
            break;
        }

        // 获取当前文件ID的缩略图
        int lineCount = 0;
        json_object *fileInfo = GetFileInfoToIdFromCache(cachePath, fileId.current, &lineCount);
        if (fileInfo)
        {
            // 获取文件信息
            json_object *nameObj = json_object_object_get(fileInfo, "fileName");
            json_object *typeObj = json_object_object_get(fileInfo, "type");
            // 判断是否正确
            if (nameObj == NULL || !json_object_is_type(nameObj, json_type_string) ||
                typeObj == NULL || !json_object_is_type(typeObj, json_type_int) ||
                json_object_get_int(typeObj) == CACHE_PATH_TYPE_DIR)
            {
                CrLogW("failed to get thumbnail\n");
                if (json_object_get_int(typeObj) == CACHE_PATH_TYPE_DIR)
                {
                    CrLogW("this is a folder");
                    json_object *thumbnailObj = json_object_object_get(fileInfo, "thumbnail");
                    json_object_set_string(thumbnailObj, GetDefaultFolderIconPtah());
                    ReviseFileInfoToCache(cachePath, lineCount, fileInfo);
                }

                json_object_put(fileInfo);
                // 更新当前获取缩略图的文件ID
                fileId.current += 1;
                SetUserGetGcodeImageEndFileId(fileId);
                continue;
            }
            // 获取文件名称
            char curName[256] = {0};
            strcat(curName, json_object_get_string(nameObj));

            // 在临时目录创建保存缩略图文件
            CrLogI("current gcode file = %s", curName);
            CurrentFile_t current_file = {0};
            snprintf(current_file.thumbnails, sizeof(current_file.thumbnails), 
                    "%s/image_file_%d.png", GetUserTempThumbnailDirPtah(), fileId.current);
            CrLogI("save file id = %d, thumbnail path = %s", fileId.current, current_file.thumbnails);

            // 从gcode文件获取参数
            GetPrintParaFromGcodeFile(curName, &current_file);
            json_object *thumbnailObj = json_object_object_get(fileInfo, "thumbnail");
            json_object_set_string(thumbnailObj, current_file.thumbnails);
            json_object *timeCostObj = json_object_object_get(fileInfo, "timeCost");
            json_object_set_int(timeCostObj, current_file.estimated_time);
            json_object *consumablesObj = json_object_object_get(fileInfo, "consumables");
            json_object_set_int(consumablesObj, current_file.filament_total);
            json_object *floorHeightObj = json_object_object_get(fileInfo, "floorHeight");
            json_object_set_int(floorHeightObj, current_file.layer_height * 100 + 0.5);
            json_object *modelXObj = json_object_object_get(fileInfo, "modelX");
            json_object_set_int(modelXObj, current_file.object_light * 100 + 0.5);
            json_object *modelYObj = json_object_object_get(fileInfo, "modelY");
            json_object_set_int(modelYObj, current_file.object_weight * 100 + 0.5);
            json_object *modelZObj = json_object_object_get(fileInfo, "modelZ");
            json_object_set_int(modelZObj, current_file.object_height * 100 + 0.5);
            json_object *materialZObj = json_object_object_get(fileInfo, "material");
            json_object_set_string(materialZObj, current_file.material);
            json_object *nozzleTempObj = json_object_object_get(fileInfo, "nozzleTemp");
            json_object_set_int(nozzleTempObj, current_file.nozzle_target_temp * 100 + 0.5);
            json_object *bedTempObj = json_object_object_get(fileInfo, "bedTemp");
            json_object_set_int(bedTempObj, current_file.bed_target_temp * 100 + 0.5);
            json_object *softwareObj = json_object_object_get(fileInfo, "software");
            json_object_set_string(softwareObj, current_file.software);
            ReviseFileInfoToCache(cachePath, lineCount, fileInfo);

            // 更新当前获取缩略图的文件ID
            fileId.current += 1;
            SetUserGetGcodeImageEndFileId(fileId);
            json_object_put(fileInfo);
        }
        else
        {
            CrLogI("get gcode file image advance end");
            // 发送更新缩略图的文件ID
            ControlRange image = CONTROL_RANGE__INIT;
            image.has_result = 1;
            image.result = result;
            image.has_start = 1;
            image.start = GetUserGetGcodeImageEndFileId().start;
            image.has_end = 1;
            image.end = GetUserGetGcodeImageEndFileId().current - 1;

            GET_MESSAGE_BUFF(buff);
            size_t len = control_range__pack(&image, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_GET_SD_MODEL_IMAGE_ANS, buff, len);
            MANAGER_MSG_SEND(origin, &send, size);
            break;
        }
    }
    return 0;
}

/**
 * @description: 响应交互端请求注水图
 * @param  {*}
 * @return {*}
 * @param {int} result
 * @param {uint32_t} *buf
 */
void UpdataGetSdGcodePhotoResult(int result, uint32_t *buf, uint32_t origin)
{
    CrLogI("updata Get Sd Gcode Photo Result = %d", result);
    // 响应
    GcodePhotoInfoRes res = GCODE_PHOTO_INFO_RES__INIT;
    res.result = result;
    if (result)
    {
        res.start_pixel = buf[0];
        res.end_pixel = buf[1];
        res.model_height = buf[2];
        res.layer_height = buf[3];
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = gcode_photo_info_res__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_CONTROLLER, MANAGER_CMD_GCODE_GET_SD_GCODE_PHOTO_ANS, buff, len);
    MANAGER_MSG_SEND(origin, &send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int photoParaCount = 0;
static uint32_t photoParaBuf[BIG_IMAGE_PARA_SIZE] = {0};
static int saveNormalImageFd = -1;
static bool startRecvNormalImageFlag = false;
static int remainingNormalImageBufferLen = 0;
static char remainingNormalImageBuffer[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};

static int remainingNormalImageStartBufLen = 0;
static char remainingNormalImageStartBuf[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
/**
 * @description: 保存从串口获取gcode文件注水图
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} len
 */
static int saveSdGcodeNormalToFile(char *buf, int *len, uint32_t cmdNum, uint32_t origin)
{
    if (cmdNum != GET_DEV_GCODE_FILE_PHOTO_NUM) return 0;
    if (strstr(buf, UNDEFINED_COMMAND)) return 0;

    CrLogI("recv len = %d", *len);
    if (!startRecvNormalImageFlag)
    {
        memcpy(&remainingNormalImageStartBuf[remainingNormalImageStartBufLen], buf, *len);
        remainingNormalImageStartBufLen += *len;
    }
    else if (startRecvNormalImageFlag)
    {
        memset(remainingNormalImageStartBuf, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        remainingNormalImageStartBufLen = 0;
    }

    // 判断文件开始
    char *pImage = strstr(remainingNormalImageStartBuf, BEGIN_BIG_IMAGE);
    if (pImage) 
    {
        // 下位机开始发送SD卡gcode文件注水图
        CrLogI("start get sd gcode normal image");
        if (access(GetUserTempOriginalDirPtah(), F_OK) != 0)
        {
            char cmd[254] = {0};
            snprintf(cmd, 254, "mkdir -p %s", GetUserTempOriginalDirPtah());

            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
                CrLogW("system fail! res = %s\n", sysRes);
        }

        // 在临时目录创建保存注水图文件
        saveNormalImageFd = open(GetUserTempOriginalPtah(), O_RDWR | O_CREAT | O_TRUNC , S_IRWXG | S_IRWXO | S_IRWXU);
        if(saveNormalImageFd < 0)
        {
            CrLogE("open %s failed.Fd = %d.", GetUserTempOriginalPtah(), saveNormalImageFd);
        }
        photoParaCount = 0;
        memset(photoParaBuf, 0, sizeof(photoParaBuf));

        // 检索数据
        pImage = pImage + strlen(BEGIN_BIG_IMAGE);
        char *qImage = strstr(pImage, END_BIG_IMAGE);
        if (qImage)
        {
            int imageLen = qImage - pImage;
            memset(remainingNormalImageBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            remainingNormalImageBufferLen = imageLen;
            memcpy(remainingNormalImageBuffer, pImage, remainingNormalImageBufferLen);
            CrLogI("save image len = %d", remainingNormalImageBufferLen);

            if (strstr(remainingNormalImageBuffer, NO_SMALL_IMAGE) ||
                !strstr(remainingNormalImageBuffer, "PNG"))
            {
                CrLogW("There is no normal image for this gcode file\n");
                UpdataGetSdGcodePhotoResult(0, NULL, origin);
            }
            else if (strstr(remainingNormalImageBuffer, GCODE_FILE_OPEN_FAIL))
            {
                CrLogW("gcode file open failed = %s\n", GetUserTempOriginalPtah());
                UpdataGetSdGcodePhotoResult(0, NULL, origin);
            }
            else
            {
                char *temp = remainingNormalImageBuffer;
                while(1)
                {
                    char *para = strchr(temp, '\t');
                    if (!para) break;

                    int strLen = para - temp;
                    char str[strLen + 1];
                    memset(str, 0, strLen + 1);
                    memcpy(str, temp, strLen);
                    photoParaBuf[photoParaCount] = atof(str) * 100 + 0.5;
                    temp = para + 1;

                    if(++photoParaCount >= BIG_IMAGE_PARA_SIZE)
                    {
                        CrLogI("get user select gcode file photo");
                        for (int i = 0; i < BIG_IMAGE_PARA_SIZE; i++)
                            CrLogI("photoParaBuf[%d] = %d", i, photoParaBuf[i]);
                        
                        // 写入image文件
                        int lenTemp = write(saveNormalImageFd, temp, remainingNormalImageBufferLen - (temp - remainingNormalImageBuffer));
                        CrLogI("write image file len = %d", lenTemp);
                        if(lenTemp < 0)
                        {
                            CrLogE("write %s send msg fail, %s\n", GetUserTempOriginalPtah(), strerror(errno));
                        }
                        UpdataGetSdGcodePhotoResult(1, photoParaBuf, origin);
                        break;
                    }
                }
                CrLogI("save sd gcode normal image finish\n");
            }

            // 关闭image文件
            close(saveNormalImageFd);
            saveNormalImageFd = -1;
            memset(remainingNormalImageStartBuf, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            remainingNormalImageStartBufLen = 0;
            return 0;
        }

        // 保存未处理数据
        memset(remainingNormalImageBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        remainingNormalImageBufferLen = remainingNormalImageStartBufLen - (pImage - remainingNormalImageStartBuf);
        memcpy(remainingNormalImageBuffer, pImage, remainingNormalImageBufferLen);

        startRecvNormalImageFlag = true;
        return -1;
    }
    else if (startRecvNormalImageFlag)
    {
        // 持续接受处理SD卡gcode文件缩略图
        char selectStr[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
        memcpy(selectStr, remainingNormalImageBuffer, remainingNormalImageBufferLen);
        memcpy(&selectStr[remainingNormalImageBufferLen], buf, *len);

        int selectStrLen = remainingNormalImageBufferLen + *len;
        if (photoParaCount < BIG_IMAGE_PARA_SIZE)
        {
            char *temp = selectStr;
            while(1)
            {
                char *para = strchr(temp, '\t');
                if (!para) break;

                int strLen = para - temp;
                char str[strLen + 1];
                memset(str, 0, strLen + 1);
                memcpy(str, temp, strLen);
                photoParaBuf[photoParaCount] = atof(str) * 100 + 0.5;
                temp = para + 1;

                if(++photoParaCount >= BIG_IMAGE_PARA_SIZE)
                {
                    CrLogI("get user select gcode file photo");
                    for (int i = 0; i < BIG_IMAGE_PARA_SIZE; i++)
                        CrLogI("photoParaBuf[%d] = %d", i, photoParaBuf[i]);
                    break;
                }
            }
            memset(remainingNormalImageBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            remainingNormalImageBufferLen = selectStrLen - (temp - selectStr);
            memcpy(remainingNormalImageBuffer, temp, remainingNormalImageBufferLen);
        }
        else if (selectStrLen <= strlen(END_BIG_IMAGE))
        {
            memset(remainingNormalImageBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            remainingNormalImageBufferLen = selectStrLen;
            memcpy(remainingNormalImageBuffer, selectStr, remainingNormalImageBufferLen);
        }
        else
        {
            int writeLen = selectStrLen - strlen(END_BIG_IMAGE);
            int lenTemp = write(saveNormalImageFd, selectStr, writeLen);
            CrLogI("write image file len = %d", lenTemp);
            if(lenTemp < 0)
            {
                CrLogE("write %s send msg fail, %s\n", GetUserTempOriginalPtah(), strerror(errno));
            }
            memset(remainingNormalImageBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            remainingNormalImageBufferLen = strlen(END_BIG_IMAGE);
            memcpy(remainingNormalImageBuffer, &selectStr[writeLen], remainingNormalImageBufferLen);
        }

        if (strstr(remainingNormalImageBuffer, END_BIG_IMAGE)) 
        {
            // 读取N个字节判断
            char readBuf[100] = {0};
            lseek(saveNormalImageFd, 0L, SEEK_SET);
            int lenTemp = read(saveNormalImageFd, readBuf, 100);
            if(lenTemp < 0)
            {
                CrLogE("write %s send msg fail, %s\n", GetUserTempOriginalPtah(), strerror(errno));
            }

            char seleceBuf[lenTemp + 1];
            memset(seleceBuf, 0, lenTemp + 1);
            memcpy(seleceBuf, readBuf, lenTemp);
            // 判断此文件是否有注水图
            if (strstr(seleceBuf, NO_SMALL_IMAGE) || strstr(remainingNormalImageBuffer, NO_SMALL_IMAGE) ||
                (!strstr(seleceBuf, "PNG") && !strstr(remainingNormalImageBuffer, "PNG")))
            {
                CrLogW("There is no normal image for this gcode file\n");
                UpdataGetSdGcodePhotoResult(0, NULL, origin);
            }
            else if (strstr(seleceBuf, GCODE_FILE_OPEN_FAIL) || strstr(remainingNormalImageBuffer, GCODE_FILE_OPEN_FAIL))
            {
                CrLogW("gcode file open failed = %s\n", GetUserTempOriginalPtah());
                UpdataGetSdGcodePhotoResult(0, NULL, origin);
            }
            else
            {
                UpdataGetSdGcodePhotoResult(1, photoParaBuf, origin);
            }

            // 关闭image文件
            close(saveNormalImageFd);
            saveNormalImageFd = -1;
            // 获取SD卡文件缩略图退出
            startRecvNormalImageFlag = false;
            // 
            memset(buf, 0, SERIAL_PORT_RECV_MAX_LEN);
            memcpy(buf, remainingNormalImageBuffer, remainingNormalImageBufferLen);
            *len = remainingNormalImageBufferLen;
            CrLogI("save sd gcode normal image finish\n");
            return 0;
        }
        else return -1;
    }
    else return 0;
}

static int thumbnailLineCount = 0;
static json_object *thumbnailFileInfo = NULL;
static json_object *saveThumbnailObj = NULL;
static int saveThumbnailFd = -1;
static bool startRecvThumbnailFlag = false;
static int saveThumbnailGcodeFileId = 0;
static char saveThumbnailGcodeFileName[100] = {0};
static char saveThumbnailPath[512] = {0};
static int remainingThumbnailBufferLen = 0;
static char remainingThumbnailBuffer[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};

static int remainingThumbnailStartBufLen = 0;
static char remainingThumbnailStartBuf[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
/**
 * @description: 保存从串口获取gcode文件缩略图
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} len
 */
static int saveSdGcodeThumbnailToFile(char *cachePath, char *buf, int *len, uint32_t cmdNum, char *cmdStr)
{
    if (cmdNum != GET_DEV_GCODE_FILE_IMAGE_NUM) return 0;
    if (strstr(buf, UNDEFINED_COMMAND)) return 0;

    CrLogI("recv len = %d", *len);
    if (!startRecvThumbnailFlag)
    {
        memcpy(&remainingThumbnailStartBuf[remainingThumbnailStartBufLen], buf, *len);
        remainingThumbnailStartBufLen += *len;
    }
    else if (startRecvThumbnailFlag)
    {
        memset(remainingThumbnailStartBuf, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        remainingThumbnailStartBufLen = 0;
    }

    // 判断文件开始
    char *pImage = strstr(remainingThumbnailStartBuf, BEGIN_SMALL_IMAGE);
    if (pImage) 
    {
        // 下位机开始发送SD卡gcode文件缩略图
        CrLogI("start get sd gcode thumbnail");
        if (access(GetUserTempThumbnailDirPtah(), F_OK) != 0)
        {
            char cmd[254] = {0};
            snprintf(cmd, 254, "mkdir -p %s", GetUserTempThumbnailDirPtah());
            
            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
                CrLogW("system fail! res = %s\n", sysRes);
        }

        // 获取缩略图的文件ID和文件名
        char *name = strstr(cmdStr, " ") + 1;
        char *nameEnd = strstr(name, "\n");
        memset(saveThumbnailGcodeFileName, 0, sizeof(saveThumbnailGcodeFileName)/sizeof(saveThumbnailGcodeFileName[0]));
        memcpy(saveThumbnailGcodeFileName, name, nameEnd - name);
        CrLogI("saveThumbnailGcodeFileName = %s", saveThumbnailGcodeFileName);

        thumbnailFileInfo = GetFileInfoToNameFromCache(GetUserGcodeFileInfoFilePath(), saveThumbnailGcodeFileName, &thumbnailLineCount);
        if (thumbnailFileInfo) {
            // 获取文件ID
            json_object *idObj = json_object_object_get(thumbnailFileInfo, "fileId");
            if (idObj || json_object_is_type(idObj, json_type_int))
                saveThumbnailGcodeFileId = json_object_get_int(idObj);
            else CrLogW("get file id error\n");

            // 获取缓存缩略图路径
            saveThumbnailObj = json_object_object_get(thumbnailFileInfo, "thumbnail");
        }
        else CrLogW("find file fail to name = %s\n", saveThumbnailGcodeFileName);
        CrLogI("saveThumbnailGcodeFileId = %d", saveThumbnailGcodeFileId);

        // 在临时目录创建保存缩略图文件
        memset(saveThumbnailPath, 0, 512);
        snprintf(saveThumbnailPath, 512, "%s/image_file_%d.png", GetUserTempThumbnailDirPtah(), saveThumbnailGcodeFileId);
        CrLogI("save file id = %d, thumbnail path = %s", saveThumbnailGcodeFileId, saveThumbnailPath);
        // 打开image文件
        saveThumbnailFd = open(saveThumbnailPath, O_RDWR | O_CREAT | O_TRUNC , S_IRWXG | S_IRWXO | S_IRWXU);
        if(saveThumbnailFd < 0)
        {
            CrLogE("open %s failed.Fd = %d.", saveThumbnailPath, saveThumbnailFd);
        }

        // 检索数据
        pImage = pImage + strlen(BEGIN_SMALL_IMAGE);
        char *qImage = strstr(pImage, END_SMALL_IMAGE);
        if (qImage)
        {
            int imageLen = qImage - pImage;
            memset(remainingThumbnailBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            remainingThumbnailBufferLen = imageLen;
            memcpy(remainingThumbnailBuffer, pImage, remainingThumbnailBufferLen);
            CrLogI("save image len = %d", remainingThumbnailBufferLen);

            if (strstr(remainingThumbnailBuffer, NO_SMALL_IMAGE) ||
                !strstr(remainingNormalImageBuffer, "PNG"))
            {
                CrLogW("There is no thumbnail for this gcode file\n");
                json_object_set_string(saveThumbnailObj, GetDefaultFileIconPtah());
                ReviseFileInfoToCache(cachePath, thumbnailLineCount, thumbnailFileInfo);
            }
            else if (strstr(remainingThumbnailBuffer, GCODE_FILE_OPEN_FAIL))
            {
                CrLogW("gcode file open failed = %s\n", saveThumbnailGcodeFileName);
                json_object_set_string(saveThumbnailObj, GetDefaultFileIconPtah());
                ReviseFileInfoToCache(cachePath, thumbnailLineCount, thumbnailFileInfo);
            }
            else
            {
                // 写入image文件
                int lenTemp = write(saveThumbnailFd, remainingThumbnailBuffer, remainingThumbnailBufferLen);
                CrLogI("write image file len = %d", lenTemp);
                if(lenTemp < 0)
                {
                    CrLogE("write %s send msg fail, %s\n", saveThumbnailPath, strerror(errno));
                }
                // 更新缓存文件
                json_object_set_string(saveThumbnailObj, saveThumbnailPath);
                ReviseFileInfoToCache(cachePath, thumbnailLineCount, thumbnailFileInfo);
                CrLogI("save sd gcode thumbnail finish\n");
            }

            // 关闭image文件
            close(saveThumbnailFd);
            saveThumbnailFd = -1;
            memset(remainingThumbnailStartBuf, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            remainingThumbnailStartBufLen = 0;
            thumbnailLineCount = 0;
            json_object_put(thumbnailFileInfo);
            return 0;
        }

        // 保存未处理数据
        memset(remainingThumbnailBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        remainingThumbnailBufferLen = remainingThumbnailStartBufLen - (pImage - remainingThumbnailStartBuf);
        memcpy(remainingThumbnailBuffer, pImage, remainingThumbnailBufferLen);

        startRecvThumbnailFlag = true;
        return -1;
    }
    else if (startRecvThumbnailFlag)
    {
        // 持续接受处理SD卡gcode文件缩略图
        char selectStr[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
        memcpy(selectStr, remainingThumbnailBuffer, remainingThumbnailBufferLen);
        memcpy(&selectStr[remainingThumbnailBufferLen], buf, *len);

        int selectStrLen = remainingThumbnailBufferLen + *len;
        if (selectStrLen <= strlen(END_SMALL_IMAGE))
        {
            memset(remainingThumbnailBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            remainingThumbnailBufferLen = selectStrLen;
            memcpy(remainingThumbnailBuffer, selectStr, remainingThumbnailBufferLen);
        }
        else
        {
            int writeLen = selectStrLen - strlen(END_SMALL_IMAGE);
            int lenTemp = write(saveThumbnailFd, selectStr, writeLen);
            CrLogI("write image file len = %d", lenTemp);
            if(lenTemp < 0)
            {
                CrLogE("write %s send msg fail, %s\n", saveThumbnailPath, strerror(errno));
            }
            memset(remainingThumbnailBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            remainingThumbnailBufferLen = strlen(END_SMALL_IMAGE);
            memcpy(remainingThumbnailBuffer, &selectStr[writeLen], remainingThumbnailBufferLen);
        }

        if (strstr(remainingThumbnailBuffer, END_SMALL_IMAGE)) 
        {
            // 读取N个字节判断
            char readBuf[100] = {0};
            lseek(saveThumbnailFd, 0L, SEEK_SET);
            int lenTemp = read(saveThumbnailFd, readBuf, 100);
            if(lenTemp < 0)
            {
                CrLogE("write %s send msg fail, %s\n", saveThumbnailPath, strerror(errno));
            }

            char seleceBuf[lenTemp + 1];
            memset(seleceBuf, 0, lenTemp + 1);
            memcpy(seleceBuf, readBuf, lenTemp);
            // 判断此文件是否有缩略图
            if (strstr(seleceBuf, NO_SMALL_IMAGE) || strstr(remainingThumbnailBuffer, NO_SMALL_IMAGE) ||
                (!strstr(seleceBuf, "PNG") && !strstr(remainingThumbnailBuffer, "PNG")))
            {
                CrLogW("There is no thumbnail for this gcode file\n");
                json_object_set_string(saveThumbnailObj, GetDefaultFileIconPtah());
                ReviseFileInfoToCache(cachePath, thumbnailLineCount, thumbnailFileInfo);
            }
            else if (strstr(seleceBuf, GCODE_FILE_OPEN_FAIL))
            {
                CrLogW("gcode file open failed = %s\n", saveThumbnailGcodeFileName);
                json_object_set_string(saveThumbnailObj, GetDefaultFileIconPtah());
                ReviseFileInfoToCache(cachePath, thumbnailLineCount, thumbnailFileInfo);
            }
            else
            {
                // 更新缓存文件
                json_object_set_string(saveThumbnailObj, saveThumbnailPath);
                ReviseFileInfoToCache(cachePath, thumbnailLineCount, thumbnailFileInfo);
            }

            // gcode文件缩略图接收完成，关闭文件
            close(saveThumbnailFd);
            saveThumbnailFd = -1;
            // 获取SD卡文件缩略图退出
            startRecvThumbnailFlag = false;
            thumbnailLineCount = 0;
            json_object_put(thumbnailFileInfo);
            // 
            memset(buf, 0, SERIAL_PORT_RECV_MAX_LEN);
            memcpy(buf, remainingThumbnailBuffer, remainingThumbnailBufferLen);
            *len = remainingThumbnailBufferLen;
            CrLogI("save sd gcode Thumbnail finish\n");
            return 0;
        }
        else return -1;
    }
    else return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} fd
 * @param {json_object} *object
 */
void JsonWriteToFile(int fd, struct json_object *object)
{
    const char* jsonStr = json_object_to_json_string_ext(object, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE);
    if(write(fd, jsonStr, strlen(jsonStr)) < 0)
    {
        CrLogE("write send msg fail, %s\n", strerror(errno));
    }
    if(write(fd, "\r\n", strlen("\r\n")) < 0)
    {
        CrLogE("write send msg fail, %s\n", strerror(errno));
    }
}

/**
 * @description: 保存gcode文件信息到缓存文件
 * @param  {*}
 * @return {*}
 * @param {int} fd
 * @param {int} *id
 * @param {char} *
 */
static int SdFileInfoToJsonAndWriteFile(int fd, uint32_t *id, char **info)
{
    char *pa = strchr(*info, ' ');
    char *pb = strstr(*info, "\r\n");
    if (pa && pb)
    {
        struct json_object *fileInfo = json_object_new_object();
        *id = *id + 1;
        json_object_object_add(fileInfo, "fileId", json_object_new_int(*id));

        int strLen = pa - *info;
        char fileName[strLen + 2];
        memset(fileName, 0, strLen + 2);
        if (*info[0] == '/') memcpy(fileName, *info, strLen);
        else
        {
            fileName[0] = '/';
            memcpy(&fileName[1], *info, strLen);
        }
        json_object_object_add(fileInfo, "fileName", json_object_new_string_len(fileName, strlen(fileName)));

        pa += 1;
        strLen = pb - pa;
        char sizeStr[strLen + 1];
        memcpy(sizeStr, pa, strLen);
        sizeStr[strLen] = '\0';
        int fileSize = atoi(sizeStr);
        json_object_object_add(fileInfo, "fileSize", json_object_new_int(fileSize));

        json_object_object_add(fileInfo, "cTime", json_object_new_int(0));
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

        CrLogI("fileId = %d, name = %s, fileSize = %d", *id, fileName, fileSize);
        JsonWriteToFile(fd, fileInfo);
        json_object_put(fileInfo);
        *info = pb + strlen("\r\n");

        return 0;
    }
    else return -1;
}

/**
 * @description: 保存gcode文件总数到gcode缓存文件
 * @param  {*}
 * @return {*}
 * @param {int} fd
 * @param {int} *num
 */
int SaveSdFileTotalNumber(char *cachePath, int sum)
{
    CrLogI("Total number of files saved = %d", sum);
    FILE *fileInfoFd = fopen(cachePath, "r");
    if (fileInfoFd == NULL)
    {
        CrLogE("open %s error", cachePath);
        return -1;
    }

    char *fileSum = "fileSum";
    char readBuff[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
    char cmdStr[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};

    if (fgets(readBuff, SERIAL_PORT_MAX_DATA_FRAME_LEN, fileInfoFd) != NULL)
    {
        struct json_object* fileInfo = json_tokener_parse(readBuff);
        if(fileInfo != NULL)
        {
            struct json_object *tempObj;
            json_object_object_get_ex(fileInfo, fileSum, &tempObj);
            json_object_set_int(tempObj, sum);

            snprintf(cmdStr, SERIAL_PORT_MAX_DATA_FRAME_LEN, "sed -i -e '%dc %s' %s", 1,
                    json_object_to_json_string_ext(fileInfo, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE),
                    cachePath);
            CrLogI("system cmd str = %s", cmdStr);
            
            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem(cmdStr, sysRes, sizeof(sysRes))) {
                CrLogW("system fail! res = %s\n", sysRes);
                CrLogE("Modify Sd Gcode File Info %s path error", fileSum);
            }
            json_object_put(fileInfo);
        }
        else CrLogI("data conversion json error\n");
    }
    else CrLogI("file not read\n");

    fclose(fileInfoFd);
    return 0;
}

/**
 * @description: 从gcode缓存文件获取gcode文件总数
 * @param  {*}
 * @return {*}
 */
int GetSaveSdFileTotalNumber(char *cachePath)
{
    FILE *fileInfoFd = fopen(cachePath, "r");
    if (fileInfoFd == NULL)
    {
        CrLogE("open %s error", cachePath);
        return -1;
    }

    int fileSum = 0;
    char readBuff[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
    if (fgets(readBuff, SERIAL_PORT_MAX_DATA_FRAME_LEN, fileInfoFd) != NULL)
    {
        struct json_object* fileInfo = json_tokener_parse(readBuff);
        if(fileInfo != NULL)
        {
            struct json_object *tempObj;
            json_object_object_get_ex(fileInfo, "fileSum", &tempObj);
            fileSum = json_object_get_int(tempObj);
            json_object_put(fileInfo);
            CrLogI("current save file total = %d", fileSum);
        }
        else CrLogI("data conversion json error\n");
    }
    else CrLogI("file not read\n");

    fclose(fileInfoFd);
    return fileSum;
}

static int saveSdFileInfoFd = -1;
static uint32_t fileId = 0;
static bool startRecvSdFileFlag = false;
static char remainingAcceptBuffer[SERIAL_PORT_MAX_DATA_FRAME_LEN];

static int remainingAcceptStartBufLen = 0;
static char remainingAcceptStartBuf[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
/**
 * @description: 保存从串口获取gcode文件列表
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} len
 */
static int saveSdGcodeFileInfoToFile(char *cachePath, char *buf, int *len, uint32_t cmdNum)
{
    if (cmdNum != GET_DEV_GCODE_FILE_PATH_NUM) return 0;
    if (strstr(buf, UNDEFINED_COMMAND)) return 0;
    
    CrLogI("recv buf = \n%s", buf);
    if (!startRecvSdFileFlag)
    {
        memcpy(&remainingAcceptStartBuf[remainingAcceptStartBufLen], buf, *len);
        remainingAcceptStartBufLen += *len;
    }
    else if (startRecvSdFileFlag)
    {
        memset(remainingAcceptStartBuf, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        remainingAcceptStartBufLen = 0;
    }
    
    // 判断文件开始
    char *pFile = strstr(remainingAcceptStartBuf, BEGIN_FILE_LIST);
    if (pFile) 
    {
        // 下位机开始发送SD卡gcode文件信息
        CrLogI("start get sd gcode file info");

        // 在临时目录创建保存信息文件
        saveSdFileInfoFd = open(cachePath, O_RDWR | O_CREAT, S_IRWXG | S_IRWXO | S_IRWXU);
        if(saveSdFileInfoFd < 0)
        {
            CrLogE("open %s failed.Fd = %d.", cachePath, saveSdFileInfoFd);
        }
        lseek(saveSdFileInfoFd, 0L, SEEK_END);
        fileId = GetSaveSdFileTotalNumber(cachePath);

        // 检索数据
        pFile = pFile + strlen(BEGIN_FILE_LIST);
        char *qFile = strstr(pFile, END_FILE_LIST);
        if (qFile)
        {
            int fileLen = qFile - pFile;
            memset(remainingAcceptBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            memcpy(remainingAcceptBuffer, pFile, fileLen);
            CrLogI("save image len = %d", fileLen);

            char *selectStr = remainingAcceptBuffer;
            while (1)
            {
                if (SdFileInfoToJsonAndWriteFile(saveSdFileInfoFd, &fileId, &selectStr) == -1)
                {
                    CrLogI("save sd gcode file info finish\n");
                    break;
                }
            }

            // 关闭SD卡信息文件
            close(saveSdFileInfoFd);
            saveSdFileInfoFd = -1;
            memset(remainingAcceptStartBuf, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            remainingAcceptStartBufLen = 0;

            // 保存SD卡gcode文件总数
            SaveSdFileTotalNumber(cachePath, fileId);
            return 0;
        }

        // 保存未处理数据
        memset(remainingAcceptBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        int remainingAcceptBufferLen = remainingAcceptStartBufLen - (pFile - remainingAcceptStartBuf);
        memcpy(remainingAcceptBuffer, pFile, remainingAcceptBufferLen);

        startRecvSdFileFlag = true;
        return -1;
    }
    else if (startRecvSdFileFlag)
    {
        // 持续接受处理SD卡gcode文件信息
        char temp[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
        memcpy(temp, remainingAcceptBuffer, strlen(remainingAcceptBuffer));
        memcpy(&temp[strlen(remainingAcceptBuffer)], buf, *len);

        char *selectStr = temp;
        while (1)
        {
            if (SdFileInfoToJsonAndWriteFile(saveSdFileInfoFd, &fileId, &selectStr) == -1)
            {
                memset(remainingAcceptBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
                memcpy(remainingAcceptBuffer, selectStr, strlen(selectStr));
                break;
            }
        }

        if (strstr(remainingAcceptBuffer, END_FILE_LIST)) 
        {
            // gcode文件信息接收完成，关闭文件
            close(saveSdFileInfoFd);
            saveSdFileInfoFd = -1;

            CrLogI("save sd gcode file info finish\n");
            // 保存SD卡gcode文件总数
            SaveSdFileTotalNumber(cachePath, fileId);
        }

        if (strstr(remainingAcceptBuffer, "ok")) 
        {
            // 获取SD卡文件信息退出
            startRecvSdFileFlag = false;
            // 
            *len = strlen(remainingAcceptBuffer);
            memset(buf, 0, SERIAL_PORT_RECV_MAX_LEN);
            memcpy(buf, remainingAcceptBuffer, *len);
            return 0;
        }
        else return -1;
    }
    else return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int sdGcodeFileInfoExceptionHandleSemPost(void)
{
    // 清空链表，释放资源
    // ClearSendGcodeList();
    ClearKlipperSendGcodeList();
    return 0;
}

static uint32_t serialPortAcceptBufferLen = 0;
static char serialPortAcceptBuffer[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
static char responseFrameBuffer[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *buf
 * @param {int} len
 */
static int SerialPortRecvResponse(char *buf, int len)
{
    // 判断自动请求gcode
    int autoRequestProcessed = 0;
    AutoPrintRequest(buf, len, &autoRequestProcessed);
    // 判断自动发送gcode响应
    AutoPrintResponse(currentSendCmd.cmd, buf, len);
    // SD卡文件信息存文件
    if (saveSdGcodeFileInfoToFile(GetUserGcodeFileInfoFilePath(), buf, &len, currentSendCmd.cmd) == -1)
    {
        memset(serialPortAcceptBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        serialPortAcceptBufferLen = 0;
        return -1;
    }
    // 缓存Gcode文件缩略图
    if (saveSdGcodeThumbnailToFile(GetUserGcodeFileInfoFilePath(), buf, &len, currentSendCmd.cmd, (char*)currentSendCmd.cmdStr) == -1)
    {
        memset(serialPortAcceptBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        serialPortAcceptBufferLen = 0;
        return -1;
    }
    // 缓存Gcode文件注水图
    if (saveSdGcodeNormalToFile(buf, &len, currentSendCmd.cmd, currentSendCmd.origin) == -1)
    {
        memset(serialPortAcceptBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        serialPortAcceptBufferLen = 0;
        return -1;
    }

    // 获取允许缓存数据长度
    uint32_t remainingLen = SERIAL_PORT_MAX_DATA_FRAME_LEN - serialPortAcceptBufferLen;
    uint32_t allowCopyLen = len < remainingLen ? len : remainingLen;

    // 缓存数据
    memcpy(&serialPortAcceptBuffer[serialPortAcceptBufferLen], buf, allowCopyLen);
    serialPortAcceptBufferLen += allowCopyLen;

    if (allowCopyLen == remainingLen)
    {
        // 缓存空间满，结束接收，开始解析
        CrLogW("Serial single frame data is too long");
        goto CACHE_FULL_PARSE_RESULTS;
    }
    
    // 等待接收以‘\n’结尾的一帧完整数据
    if (serialPortAcceptBuffer[serialPortAcceptBufferLen - 1] != '\n')
        return -1;

CACHE_FULL_PARSE_RESULTS:
    CrLogI("receive len = %d", serialPortAcceptBufferLen);
    CrLogD("receive data = \n%s", serialPortAcceptBuffer);

    char *strtokContext = NULL;
    char *answer = strtok_r(serialPortAcceptBuffer, "\n", &strtokContext);
    while (answer)
    {
        // 响应自动打印请求检测
        if (AutoPrintRequestAnl(answer, strlen(answer), autoRequestProcessed) == 0)
        {
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 打印完成检测
        if (DevicePrintFinish(answer, strlen(answer)) == 0)
        {
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 下位机忙检测
        if (DevicePrintWorkBusy(answer, strlen(answer)) == 0)
        {
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 检测自动报告设备状态
        if (DetectAutoReportStatus(answer, strlen(answer)) == 0)
        {
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 获取自动调平进度
        if (DeviceAutoLevelProgress(currentSendCmd.cmd, answer, strlen(answer)) == 0)
        {
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 获取自动PID进度
        if (DeviceAutoPidProgress(currentSendCmd.cmd, answer, strlen(answer)) == 0)
        {
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 用户设置M125
        if (DetectUserSetParkHead(answer, strlen(answer)) == 0)
        {
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 检测设备是否断料
        if (DetectMaterialStatus(answer, strlen(answer)) == 0)
        {
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 设备主动停止喷嘴加热
        if (DetectActiveCooling(answer, strlen(answer)) == 0)
        {
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 下位机重启
        if (DetectLowerComputerStarts(answer, strlen(answer)) == 0)
        {
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 下位机挂机
        if (DetectLowerComputerPrinterHalted(answer, strlen(answer)) == 0)
        {
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 自动上报温度
        char *regex = "[BT]:[-|+]?[0-9]{1,3}.[0-9]{1,2} /[0-9]{1,2}.[0-9]{1,2}";
        regmatch_t regmatch[5];
        if (UserGetRegexStr(answer, regex, regmatch, sizeof(regmatch)/sizeof(regmatch[0])) && !strstr(answer, "ok"))
        {
            getTempFromResponseData(answer, strlen(answer), 1);
            ResetSendTimeOutAndPuaseGetTemp();
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
            answer = strtok_r(NULL, "\n", &strtokContext);
            continue;
        }
        // 指令应答
        strcat(responseFrameBuffer, answer);
        strcat(responseFrameBuffer, "\n");
        if (strstr(responseFrameBuffer, "ok"))
        {
            if (currentSendCmd.sendFlag)
            {
                SerialPortRecvGcodeAnl(currentSendCmd, responseFrameBuffer, strlen(responseFrameBuffer), 1);
                DelFirstGcodeListCmd();
            }
            else
            {
                // 提示程序未处理的返回结果
                if (!strstr(buf, PTINT_WORK_BUSY))
                    CrLogW("Unprocessed return result !!! = %s", buf);
            }
            memset(responseFrameBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        }
        // 获取下一条指令
        answer = strtok_r(NULL, "\n", &strtokContext);
    }

    memset(serialPortAcceptBuffer, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
    serialPortAcceptBufferLen = 0;
    return 0;
}


/**
 * @description: 
 * @return {*}
 * @param {char} *method
 * @param {json_object} *params
 * @param {uint32_t} origin
 */
int AddKlipperCmd(char *method, json_object *params, uint32_t Num, uint32_t origin)
{
    if (GetGcodeListSizeLock() >= SEND_GCODE_LIST_MAX_SIZE)
    {
        CrLogW("send gcode list full space!\n");
        return -1;
    }
    
    // 申请指令内存空间
    KlipperSend_t *send = (KlipperSend_t *)malloc(sizeof(KlipperSend_t));
    if (send == NULL) 
    {
        CrLogW("Unable to allocate memory\n");
        return -1;
    }

    memset(send, 0, sizeof(KlipperSend_t));
    send->sendFlag = true;
    send->resend = DEFAULT_RETRANSMISSION_TIMES;
    send->outTime = DEFAULT_SENDING_TIMEOUT;
    send->timeCount = send->outTime;
    send->origin = origin;
    send->cmdNum = Num;

    // 使用时间戳生成命令ID
    struct timeval newTime;
    gettimeofday(&newTime, NULL);
    uint32_t createCmdId = newTime.tv_sec % 1000 * 1000000 + newTime.tv_usec;
    send->cmdId = createCmdId;

    // 生成发送指令
    json_object *sendCmd = json_object_new_object();
    json_object_object_add(sendCmd, "id", json_object_new_int(send->cmdId));
    json_object_object_add(sendCmd, "method", json_object_new_string(method));
    json_object_object_add(sendCmd, "params", params);
    const char* cmdJsonStr = json_object_to_json_string_ext(sendCmd, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE);
    uint32_t cmdJsonStrLen = strlen(cmdJsonStr);

    // 缓存至链表
    send->cmdStr = (char*)malloc(cmdJsonStrLen + 5);
    if (send->cmdStr)
    {
        memset(send->cmdStr, 0, (cmdJsonStrLen + 5));
        memcpy(send->cmdStr, cmdJsonStr, cmdJsonStrLen);
        send->cmdStr[cmdJsonStrLen] = 0x03;
        send->cmdLen = cmdJsonStrLen + 1;

        pthread_rwlock_wrlock(&sendRwLock);
        list_add_tail(&send->node, &gcodeSendList);
        pthread_rwlock_unlock(&sendRwLock);
    }
    else
    {
        CrLogW("Unable to allocate memory\n");
        free(send);
        send = NULL;
    }

    json_object_put(sendCmd);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {KlipperSend_t} *del
 */
static int DeleteSendGcode(KlipperSend_t del)
{
    CrLogI("delete gcode cmd = %d\n", del.cmdId);
    // 链表为空
    if (list_empty(&gcodeSendList)) {
        CrLogW("linked list is empty\n");
        return 0;
    }

    pthread_rwlock_wrlock(&sendRwLock);
    KlipperSend_t *temp = NULL, *snext = NULL;
    list_for_each_entry_safe(temp, snext, &gcodeSendList, node) {
        if (temp->cmdId == del.cmdId)
        {
            list_del_init(&temp->node);
            if (temp->cmdStr != NULL)
            {
                free(temp->cmdStr);
                temp->cmdStr = NULL;
            }
            free(temp);
            temp = NULL;
            break;
        }
    }
    pthread_rwlock_unlock(&sendRwLock);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
int ClearKlipperSendGcodeList(void)
{
    // 链表为空
    if (list_empty(&gcodeSendList)) {
        CrLogW("linked list is empty\n");
        return 0;
    }

    pthread_rwlock_wrlock(&sendRwLock);
    KlipperSend_t *temp = NULL, *snext = NULL;
    list_for_each_entry_safe(temp, snext, &gcodeSendList, node) {
        list_del_init(&temp->node);
        if (temp->cmdStr != NULL)
        {
            free(temp->cmdStr);
            temp->cmdStr = NULL;
        }
        free(temp);
        temp = NULL;
    }
    pthread_rwlock_unlock(&sendRwLock);
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static void *KlipperCmdDetectThread(void)
{
    while (1) {
        usleep(100 * 1000);
        // 通信超时检测
        if (GetKlipperSocketFlag() && IsSocketOutTime()) {
            KlipperSocketDeinit();
        }

        // 判断socket是否连接成功
        if (!GetKlipperSocketFlag())
        {
            SocketOutTimeCountClear();
            UpdataSerialPort(0);
            UpdataSdCardExists(0);
            CrLogE("The socket connection is disconnected, try again after 1 seconds");
            sleep(1);
            CrLogE("reconnecting...\n");
            if (KlipperSocketInit() == 0) {
                CrLogI("socket connection successful");
                // 清空发送链表
                ClearKlipperSendGcodeList();
                // 启动与 klipper 握手
                setEnableGetKlipperState(true);
                // 重新获取klipper配置文件
                SetSyncKlipperConfigFile(true);
            }
            else
            {
                CrLogE("socket connection failed\n");
                // socket断连时不发送握手请求
                setEnableGetKlipperState(false);
                continue;
            }
        }
        
        // 遍历发送链表
        pthread_rwlock_wrlock(&sendRwLock);
        bool singleSend = true;
        KlipperSend_t *temp = NULL, *snext = NULL;

        list_for_each_entry_safe(temp, snext, &gcodeSendList, node){
            if (temp->sendFlag && singleSend)
            {
                singleSend = false;
                temp->sendFlag = false;
                CrLogD("send klipper cmd = %s\n", temp->cmdStr);
                KlipperSocketWrite(temp->cmdStr, temp->cmdLen);
            }
            else {
                // 超时处理
            }
        }
        pthread_rwlock_unlock(&sendRwLock);
    }

    return NULL;
}

static uint32_t klipperAcceptBufferLen = 0;
static char klipperAcceptBuffer[KLIPPER_RECV_MAX_LEN * 100] = {0};
/**
 * @description: 
 * @return {*}
 * @param {char} *buff
 * @param {int} len
 */
static int KlipperRecvResponse(char *buff, int len)
{
    // 缓存数据；等待接收以‘0x03’结尾的一帧完整数据
    memcpy(&klipperAcceptBuffer[klipperAcceptBufferLen], buff, len);
    klipperAcceptBufferLen += len;
    if (klipperAcceptBuffer[klipperAcceptBufferLen - 1] != 0x03)
        return -1;
    
    // 开始解析klipper应答json数据
    char *answer = klipperAcceptBuffer;
    while (answer)
    {
        char *answerEnd = strchr(answer, 0x03);
        if (!answerEnd) break;
        answerEnd[0] = '\0';

        CrLogD("klipper recv = %s\n", answer);
        json_object *klipperRecv = json_tokener_parse(answer);
        if (klipperRecv == NULL)
        {
            CrLogW("klipper recv data to json fail\n");
            answer = answerEnd + 1;
            continue;
        }
        
        // 解析
        json_object *idObj = json_object_object_get(klipperRecv, "id");
        if (idObj != NULL && json_object_is_type(idObj, json_type_int))
        {
            // 获取应答命令id
            int32_t recvCmdId = json_object_get_int(idObj);
            //
            KlipperSend_t *temp = NULL, *snext = NULL;
            KlipperSend_t curResCmd = {0};
            // 遍历发送链表
            pthread_rwlock_wrlock(&sendRwLock);
            list_for_each_entry_safe(temp, snext, &gcodeSendList, node) {
                if (temp->cmdId == recvCmdId) {
                    memcpy(&curResCmd, temp, sizeof(KlipperSend_t));
                    break;
                }
            }
            pthread_rwlock_unlock(&sendRwLock);

            // 解析应答
            if (curResCmd.cmdId == recvCmdId)
            {
                // 指令执行错误
                json_object *errorObj = json_object_object_get(klipperRecv, "error");
                if (errorObj != NULL && json_object_is_type(errorObj, json_type_object))
                {
                    json_object *errObj = json_object_object_get(errorObj, "error");
                    if (errObj != NULL && json_object_is_type(errObj, json_type_string))
                    {
                        const char *errorStr = json_object_get_string(errObj);
                        CrLogW("error = %s", errorStr);
                    }
                    json_object *messageObj = json_object_object_get(errorObj, "message");
                    if (messageObj != NULL && json_object_is_type(messageObj, json_type_string))
                    {
                        const char *messageStr = json_object_get_string(messageObj);
                        CrLogW("message = %s", messageStr);
                        GetKlipperErrorKeyValue(messageStr);
                    }
                }

                // 判断是否是收发异步指令，同步指令在指令发送位置处理
                if (curResCmd.cmdNum > KLIPPER_CMD_SYNC_RECV_START_NUM &&
                    curResCmd.cmdNum < KLIPPER_CMD_SYNC_RECV_END_NUM)
                {
                    const char *resultStr = json_object_to_json_string(klipperRecv);
                    SaveKlipperCmdSyncRecvData((char*)resultStr, curResCmd.cmdNum);
                }
                else KlipperRecvGcodeAnl(&curResCmd, klipperRecv); // 指令执行结果

                // 删除已应答指令
                DeleteSendGcode(curResCmd);
            }
            else CrLogW("The command ID for the reply was not found in the send list\n");
        }
        else {
            KlipperRecvSubscribeAnl(klipperRecv);
        }

        json_object_put(klipperRecv);
        answer = answerEnd + 1;
    }

    memset(klipperAcceptBuffer, 0, (KLIPPER_RECV_MAX_LEN * 100));
    klipperAcceptBufferLen = 0;
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static void *KlipperRecvThread(void)
{
    while (1) {
        char rcv_buf[KLIPPER_RECV_MAX_LEN] = {0};
        int len = KlipperSocketRead(rcv_buf, KLIPPER_RECV_MAX_LEN); // 内部有系统状态监听，10s超时
        if(len > 0)
        {
            rcv_buf[len] = '\0';
            KlipperRecvResponse(rcv_buf, len);
            SocketOutTimeCountClear();
        }
        // usleep(1000 * 10);
    }

    return NULL;
}

/**
 * @description: 
 * @return {*}
 */
int PrintKlipperInit(void)
{
    CrLogI("Print Klipper Init");
    KlipperSocketInit();
    // 开发远程调试服务
    CreateKlipperRemoteDebug();
    // 初始化发送链表
    pthread_rwlock_init(&sendRwLock, NULL);
    INIT_LIST_HEAD(&gcodeSendList);

    // 创建socket接收线程
    pthread_t socketRecvHandle;
    int res = pthread_create(&socketRecvHandle, NULL, (void*)KlipperRecvThread, NULL);
    if (res) {
        CrLogE("create socket recv pthread error!");
    }

    // 命令超时重发检测
    pthread_t timeOutResendHandle;
    res = pthread_create(&timeOutResendHandle, NULL, (void*)KlipperCmdDetectThread, NULL);
    if (res) {
        CrLogE("create timeout resend pthread error!");
    }

    // 启动与 klipper 握手
    CrLogI("print klipper ready handshake\n");
    setEnableGetKlipperState(true);
    // 获取klipper配置文件
    SetSyncKlipperConfigFile(true);
    // 获取继续打印信息
    SetSyncContinuePrint(true);
    return 0;
}
