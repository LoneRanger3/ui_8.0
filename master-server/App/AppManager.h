/*
 * @Description : AppManager.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:15
 * @LastEditTime: 2022-03-03 16:23:16
 */
#ifndef __APP_MANAGER_H__
#define __APP_MANAGER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

MsgHandle_t *AppManagerInit(void *arg);
int AppManagerExceptionHandleSemPost(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif