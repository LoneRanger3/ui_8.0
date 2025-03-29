/*
 * @Description : AppModeAutoPrint.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-08 18:53:47
 * @LastEditTime: 2022-11-29 10:30:31
 */

#ifndef __APP_MODE_AUTO_PRINT_H__
#define __APP_MODE_AUTO_PRINT_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#include "Controller.h"

#define GCODE_RING_BUFF_IDLE_SIZE       5
#define GCODE_RING_BUFF_USABLE_SIZE     4
#define GCODE_RING_BUFF_DEF_SIZE        (GCODE_RING_BUFF_IDLE_SIZE + GCODE_RING_BUFF_USABLE_SIZE)

void EnterAppAutoPrint(void);
void ExecuteAppAutoPrint(void);
void ExitAppAutoPrint(void);

void SetAutoPrintInfo(PrintFileInfo_t info);
int EnableAutoGetGcodeCmd(void);
int EnableRequestSendGcodeCmd(void);
int EnableRequestGetGcodeCmd(uint32_t line);
int AppModeAutoPrintInit(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif