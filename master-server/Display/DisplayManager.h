/*
 * @Description : DisplayManager.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-01 17:42:21
 * @LastEditTime: 2023-01-09 18:16:04
 */
#ifndef __DISPLAY_MANAGER_H__
#define __DISPLAY_MANAGER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

MsgHandle_t *DisplayManagerInit(void *arg);
int DisplayManagerExceptionHandleSemPost(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
