/*
 * @Description : AppPrint.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-13 14:10:30
 * @LastEditTime: 2023-09-20 09:55:47
 */
#ifndef __APP_PRINT_H__
#define __APP_PRINT_H__

#include "Base/MasterMsgBase.h"
#include "ControllerFsm.h"

#ifdef  __cplusplus  
extern "C" {  
#endif

typedef enum {
    APP_SWAP_WAY_ACTIVELY_SEND = 0,
    APP_SWAP_WAY_PASSIVE_SEND,
}AppSwapWay;

typedef enum _ai_mode {
    ai_fault_mode = 0,
    ai_foreign_objects_mode = 1,
}AiDetectMode_t;

typedef enum {
    AI_DETECT_TYPE_FOREIGN_BODY = 0,
    AI_DETECT_TYPE_PASTA = 1,
}AiDetectType_t;

typedef enum {
    FORCED_UPGRADE_MCU0 = 1,
    FORCED_UPGRADE_NOZ0 = 2,
    FORCED_UPGRADE_BED0 = 3,
}ForcedUpgradeMcu_t;

typedef struct SingleTaskFailure {
    int throatFanDetect;
} SingleTaskFailure_t;

typedef struct SingleBootFailure {
} SingleBootFailure_t;

typedef struct FunctionFailure {
    FaultCode_t lastFaultCode;
    SingleTaskFailure_t singleTask;
    SingleBootFailure_t singleBoot;
} FunctionFailure_t;

/**
 * @description: AI识别结果
 * @return {*}
 */
typedef struct AiResults {
    int re_label;
    float re_prob;
    float re_obj_rect_x;
    float re_obj_rect_y;
    float re_obj_rect_width;
    float re_obj_rect_height;
} AiResults_t;

typedef struct VideoInfo {
    char fileName[256];
    int duration;
    int bitrate;
} VideoInfo_t;

void SetAppModeChange(FSM_MODE_t mode);
FSM_MODE_t GetCurrentAppMode(void);
void SetAppStateChange(AppPrintState state);
AppPrintState GetCurrentAppstate(void);

void AppSendPrintState();
void AutoGetGetPrinterStatus(void);
void GetDeviceSavePowerLossInfo(void);
void MsaterShareStateInit(void);
void MsaterCreateNewLogFile();
void UpdataErrorStateToManager(int code, char *message, char *value);
int KlipperInitGetObjectsConfig(void);

int enablePauseAutoGetHotendBedTemp(void);
int setEnableGetKlipperState(bool state);

void DeleteOldDelayImageH264File(void);
void DeleteOldAiImageFile(void);
void CumulativePrintingTime(void);
int UploadDelayImage(void);
int UploadPrintHistoryRecord(bool isUpdata);
int AiDetectForeignBody(Camera_t camNum);

void SetSyncKlipperConfigFile(bool flag);
bool GetSyncKlipperConfigFile(void);

void SetSyncContinuePrint(bool flag);
bool GetSyncContinuePrint(void);

void SetFunctionFailure(FunctionFailure_t data);
FunctionFailure_t GetFunctionFailure(void);
void SetFunctionFailureFaultCode(FaultCode_t code);
void ClearSingleTaskFunctionFailure(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
