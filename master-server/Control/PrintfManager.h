/*
 * @Description : PrintfManager.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-02 14:10:06
 * @LastEditTime: 2022-04-07 14:18:06
 */
#ifndef __PRINTF_MANAGER_H__
#define __PRINTF_MANAGER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

int PrintfManagerInit(void);
int PrintfManagerMsgUpdata(MsgHeadBuf_t head);
int PrintfManagerExceptionHandleSemPost(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif