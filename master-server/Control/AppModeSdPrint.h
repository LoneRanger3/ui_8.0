/*
 * @Description : AppModeSdPrint.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-08 18:53:47
 * @LastEditTime: 2022-11-29 10:30:24
 */

#ifndef __APP_MODE_SD_PRINT_H__
#define __APP_MODE_SD_PRINT_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#include "Controller.h"

void EnterAppSdPrint(void);
void ExecuteAppSdPrint(void);
void ExitAppSdPrint(void);

void SetSdPrintInfo(PrintFileInfo_t info);
void UserControlStopReady(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif