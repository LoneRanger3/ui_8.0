/**
 * @ Author: Rui Xiong
 * @ Create Time: 2022-11-11 15:42:32
 * @ Modified by: Rui Xiong
 * @ Modified time: 2022-11-16 10:50:52
 * @ Description:
 */

#ifndef __SERVER_MESSAGE_H__
#define __SERVER_MESSAGE_H__


#ifdef  __cplusplus  
extern "C" {  
#endif

int ExceptionHandleSemPost(void);
pthread_t *ServerMessageInit(void *arg);
int SendMsgBuff(MsgHeadBuf_t *data, size_t len);
int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif