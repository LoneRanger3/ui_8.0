/*
 * @Description : WifiManager.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:15
 * @LastEditTime: 2022-01-18 21:17:05
 */
#ifndef __WIFI_MANAGER_H__
#define __WIFI_MANAGER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

MsgHandle_t *WifiManagerInit(void *arg);
int WifiManagerExceptionHandleSemPost(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif