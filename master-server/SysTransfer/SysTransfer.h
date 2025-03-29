/*
 * @Description : SysTransfer.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:15
 * @LastEditTime: 2023-01-29 17:21:29
 */
#ifndef __SYS_UBOX_H__
#define __SYS_UBOX_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

MsgHandle_t *SysTransferInit(void *arg);
int SysTransferExceptionHandleSemPost(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
