/*
 * @Description : BurnManager.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:15
 * @LastEditTime: 2022-03-03 17:23:38
 */
#ifndef __BURN_MANAGER_H__
#define __BURN_MANAGER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

MsgHandle_t *BurnManagerInit(void *arg);
int BurnManagerExceptionHandleSemPost(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif