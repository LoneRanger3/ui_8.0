/*
 * @Description : ServerMessage.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:15
 * @LastEditTime: 2022-01-18 19:41:19
 */
#ifndef __SERVER_MESSAGE_H__
#define __SERVER_MESSAGE_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#include "Base/DisplayMsgBase.h"

int *ServerMessageInit(void *arg);
int ExceptionHandleSemPost(void);
int SendMsgBuff(MsgHeadBuf_t *data, size_t len);
int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len);

int GetPrinterDataFromManager(unsigned char flag, unsigned char dataLen, char *data);
int SetPrinterDataToManager(unsigned char flag, unsigned char dataLen, char *data);

int SetPrinterRefreshToManager(unsigned char flag);
int SetPrinterBuzzerToManager(unsigned char flag);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif