/*
 * @Description : GcodeCmdResAnl.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-17 13:52:24
 * @LastEditTime: 2023-02-07 16:56:15
 */
#ifndef __GCODE_CMD_RES_ANL_H__
#define __GCODE_CMD_RES_ANL_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#include "AppPrint.h"

typedef struct {
    uint32_t start;
    uint32_t current;
    uint32_t end;
}ControlRange_t;

int SerialPortRecvGcodeAnl(GcodeSend_t send, char *buf, int bufLen, int result);
int getTempFromResponseData(char *buf, int bufLen, int result);
int AutoPrintResponse(uint32_t cmdNum, char *buf, int bufLen);
int AutoPrintRequest(char *buf, int bufLen, int *line);
int AutoPrintRequestAnl(char *buf, int bufLen, uint32_t line);
int DevicePrintFinish(char *buf, int bufLen);
int DetectAutoReportStatus(char *buf, int bufLen);
int DeviceAutoLevelProgress(uint32_t cmdNum, char *buf, int bufLen);
int DeviceAutoPidProgress(uint32_t cmdNum, char *buf, int bufLen);
int DetectUserSetParkHead(char *buf, int bufLen);
int DetectMaterialStatus(char *buf, int bufLen);
int DetectActiveCooling(char *buf, int bufLen);
int DetectLowerComputerStarts(char *buf, int bufLen);
int DetectLowerComputerPrinterHalted(char *buf, int bufLen);

int setUserSetAutoPidTimes(int times);
void SetUserGetGcodeImageEndFileId(ControlRange_t id);
ControlRange_t GetUserGetGcodeImageEndFileId(void);
int GetLocalGcodeFileInfo(char *traversePath, int sort, char *cachePath);

int GetKlipperErrorKeyValue(const char *str);
int KlipperRecvGcodeAnl(KlipperSend_t *send, json_object *resObj);
int KlipperRecvSubscribeAnl(json_object *resObj);
int ClearcurAutoLevelPointNum(void);

int ResonanceTestResultResponse(ResonanceTest_t testRes);
int AutoLevelResultResponse(AutoLeveling_t levelRes);

/*********************************************************
 *********************************************************
 ******************** 获取打印模型参数 **********************
 *********************************************************
 *********************************************************/
uint32_t GetPrintLayers(KlipperPrint_t printer);
uint32_t GetPrintCurLayer(KlipperPrint_t printer);
double GetPrintProgress(KlipperPrint_t printer);
uint32_t GetPrintTimeEstimates(KlipperPrint_t printer);
double GetRealTimeSpeed(KlipperPrint_t printer);
double GetRealTimeFlow(KlipperPrint_t printer);
int GetHistoryRecordFromFileName(KlipperPrint_t *printer);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
