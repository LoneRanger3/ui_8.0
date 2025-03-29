/*
 * @Description : ServerMessage.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:15
 * @LastEditTime: 2022-01-19 17:34:17
 */
#ifndef __SERVER_MESSAGE_H__
#define __SERVER_MESSAGE_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

pthread_t *ServerMessageInit(void *arg);
int ExceptionHandleSemPost(void);
int SendMsgBuff(MsgHeadBuf_t *data, size_t len);
int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif