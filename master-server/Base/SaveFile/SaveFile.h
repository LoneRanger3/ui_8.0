/*
 * @Description : SaveFile.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-29 14:23:52
 * @LastEditTime: 2023-09-20 09:56:34
 */
#ifndef __SAVE_FILE_H__
#define __SAVE_FILE_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

typedef enum {
    WEBRTC_TEST_SERVER,        // 测试服务器
    WEBRTC_CN_SERVER,          // 国内正式服务器
    WEBRTC_COM_SERVER,         // 海外正式服务器
    WEBRTC_CN_PRE_SERVER,      // 国内预发布服务器
    WEBRTC_COM_PRE_SERVER,     // 海外预发布服务器
    WEBRTC_DEBUG_SERVER,       // 联调服务器
} WebrtcDeploySetting_t;

#define SAVE_HISTORY_RECORD_SIZE    50
#define SAVE_DELAY_IMAGE_INFO_SIZE  50
#define SAVE_FAULT_CODE_INFO_SIZE   500
#define COMPANY_OFFICIAL_WEBSITE    "www.creality.com"

int ConfigFileInit(void);
int ConfigFileReset(void);
SystemConfig_t GetSystemConfig(void);
int UpdataSystemConfig(SystemConfigProto *config);

int SetMaterialPrefer(MaterialPrefer *material);
int GetMaterialPrefer(MaterialPreferList *list, MaterialPreferList *getList);
int GetMaterialPreferFree(MaterialPreferList *getList);

int SetTempAutoPidPrefer(TempAutoPidPrefer *pidRefer);
int GetTempAutoPidPrefer(TempAutoPidPreferList *list, TempAutoPidPreferList *getList);
int GetTempAutoPidPreferFree(TempAutoPidPreferList *getList);

int SetDelayImagePrefer(DelayImagePrefer *imageRefer);
int GetDelayImagePrefer(DelayImagePrefer *imageRefer);
int SetHistoryRecord(HistoryRecord history, bool isUpdata);
int GetHistoryRecord(HistoryRecordList *recordList);
int GetHistoryRecordFree(HistoryRecordList *recordList);
int SetDelayImageInfo(DelayImageInfo setInfo);
int GetDelayImageInfo(DelayImageInfoList *infoList);
int ModifyDelayImageInfo(int cmd,char* file,char*printid,char* param);
int SetFaultCodeRecord(FaultCode_t faultCode);

int SetPowerLossPrefer(PowerLossPrefer *lossRefer);
int GetPowerLossPrefer(PowerLossPrefer *lossRefer);
int SetAiControlPrefer(AiControlPrefer *lossRefer);
int GetAiControlPrefer(AiControlPrefer *lossRefer);

double GetSaveFileZaxesHight(void);
int SetSaveFileZaxesHight(double hight);

int PlaMaterialPreferExceptionHandleMallocPost(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif