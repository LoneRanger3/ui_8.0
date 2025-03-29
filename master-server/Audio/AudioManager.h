/*
 * @Description : AudioManager.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:49
 * @LastEditTime: 2022-01-18 21:18:27
 */
#ifndef __AUDIO_MANAGER_H__
#define __AUDIO_MANAGER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

MsgHandle_t *AudioManagerInit(void *arg);
int AudioManagerExceptionHandleSemPost(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif