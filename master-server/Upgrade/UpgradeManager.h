/*
 * @Description : UpgradeManager.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:15
 * @LastEditTime: 2023-01-11 09:43:48
 */
#ifndef __UOGRADE_MANAGER_H__
#define __UPGRADE_MANAGER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

typedef enum {
    UPGRADE_TARGET_LINUX,
    UPGRADE_TARGET_MCU1,
}UpgradeTarget_t;

typedef struct FirmwareInfo {
    char version[64];
    char name[256];
    uint32_t size;
    char path[256];
}FirmwareInfo_t;

typedef struct UpgradeLocalFindOptions {
    char *findPath;
    char *software;
    char *hardware;
    UpgradeTarget_t type;
}UpgradeLocalFindOptions_t;

MsgHandle_t *UpgradeManagerInit(void *arg);
int UpgradeManagerExceptionHandleSemPost(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif