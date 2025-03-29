/*
 * @Description : Controller.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:15
 * @LastEditTime: 2023-08-08 17:15:19
 */
#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

typedef enum {
    PRINT_PREPARE_NULL = 0,
    PRINT_PREPARE_RUNING = 1,
    PRINT_PREPARE_SUCCESS = 2,
    PRINT_PREPARE_FAIL = 3,
    PRINT_PREPARE_RESUME_PRINT = 4,
} PrintPrepareState_t;

typedef struct {
    char fileName[256];
    uint32_t usedTime;
    uint32_t cmdCount;
    long int fileOffset;
    int withSelfTest;
    int powerLossStart;
    int fluiddStart;
}PowerLossInfo_t, PrintFileInfo_t;

typedef struct {
    long mtype;     /* 消息类型，必须 > 0 */
    char buf[4096]; /* 消息文本 */
} CmdSyncRecv_t;

MsgHandle_t *ControllerInit(void *arg);
int ControllerExceptionHandleSemPost(void);

int SaveKlipperCmdSyncRecvData(char *data, long type);
int GetKlipperCmdSyncRecvData(CmdSyncRecv_t *data, long type, int flag);

void SetPrintPrepareState(PrintPrepareState_t state);
PrintPrepareState_t GetPrintPrepareState(void);

int SavePowerLossPrintInfo(PowerLossInfo_t info);
int UpdataPrintObjectInfo(char *info, int len);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif