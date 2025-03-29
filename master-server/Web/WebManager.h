/**
 * @ Author: Rui Xiong
 * @ Create Time: 2022-11-14 18:02:19
 * @ Modified by: Rui Xiong
 * @ Modified time: 2022-11-15 14:06:19
 * @ Description:
 */
#ifndef __WEB_MANAGER_H__
#define __WEB_MANAGER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

MsgHandle_t *WebManagerInit(void *arg);
int WebManagerExceptionHandleSemPost(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif