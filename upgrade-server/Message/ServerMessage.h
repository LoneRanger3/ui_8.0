/*
 * @Description : ServerMessage.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:15
 * @LastEditTime: 2023-01-11 14:08:12
 */
#ifndef __SERVER_MESSAGE_H__
#define __SERVER_MESSAGE_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

typedef struct UpgradeFilePath {
    char linux1[256];
    char hostMcu[256];
    char nozzleMcu[256];
    char bedMcu[256];
}UpgradeFilePath_t;

pthread_t *ServerMessageInit(void *arg);
int ExceptionHandleSemPost(void);
int SendMsgBuff(MsgHeadBuf_t *data, size_t len);
int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif