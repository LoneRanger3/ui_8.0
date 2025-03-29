/*
 * @Description : PrintControl.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-14 18:23:03
 * @LastEditTime: 2023-01-29 17:48:24
 */
#ifndef __PRINTF_CONTROL_H__
#define __PRINTF_CONTROL_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#include "global/list/list.h"

typedef struct GcodeSend {
    bool sendFlag;      // 是否未发送
    uint8_t resend;     // 重发次数
    uint32_t outTime;   // 超时时间，10ms时间周期
    uint32_t timeCount; // 计算时间，10ms时间周期
    uint32_t origin;    // 发送来源
    uint32_t cmd;       // 发送命令
    uint32_t lineNum;   // gcode行号
    uint8_t cmdStr[100];// 发送命令
    struct list_head node;
} GcodeSend_t;

typedef struct KlipperSend {
    bool sendFlag;      // 是否未发送
    uint8_t resend;     // 重发次数
    uint32_t outTime;   // 超时时间，10ms时间周期
    uint32_t timeCount; // 计算时间，10ms时间周期
    uint32_t origin;    // 发送来源
    uint32_t cmdNum;    // 命令编号
    uint32_t cmdId;     // 命令id
    char *cmdStr;       // 发送命令
    uint32_t cmdLen;    // 命令长度
    struct list_head node;
} KlipperSend_t;

int PrintControlInit();
void CleanCurrentSendCmd(void);
int ClearSendGcodeListNoPrintCmd(void);
int ClearSendGcodeList(void);
int ClearKlipperSendGcodeList(void);
int AppEnforceUartSend(char *send_buf, int data_len);
int AddGcodeListCmd(uint32_t cmd, uint32_t num, String_t *cmdStr, uint32_t origin);
int AddGcodeListHeadCmd(uint32_t cmd, uint32_t num, String_t *cmdStr, uint32_t origin);
int AddGcodeListHeadSecondCmd(uint32_t cmd, uint32_t num, String_t *cmdStr, uint32_t origin);
int sdGcodeFileInfoExceptionHandleSemPost(void);
json_object *GetFileInfoToNameFromCache(char *path, char *name, int *line);
int ReviseFileInfoToCache(char *path, int line, json_object *info);
void JsonWriteToFile(int fd, struct json_object *object);
int SaveSdFileTotalNumber(char *cachePath, int sum);
int GetSaveSdFileTotalNumber(char *cachePath);
int SaveLocalGcodeImageToFile(char *cachePath, uint32_t origin, int result);

int PrintKlipperInit(void);
int AddKlipperCmd(char *method, json_object *params, uint32_t Num, uint32_t origin);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif