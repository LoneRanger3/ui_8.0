/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-10-31 11:47:04
 * @LastEditTime: 2023-10-30 11:01:51
 */
#ifndef __SYSTEM_CMD_H__
#define __SYSTEM_CMD_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#include <stdbool.h>
#include <regex.h>
#include <semaphore.h>
#include "../Global.h"

typedef struct {
    char ip[64];
    char gateway[64];
    char subnetMask[64];
    char dnsServer[64];
} EthernetInfo_t;

typedef enum get_shm_result{
    GET_SHM_IDLE = 0,
    GET_SHM_OK,
    GET_SHM_OPEN_SEM_FAIL,
    GET_SHM_OPEN_SHM_FAIL,
    GET_SHM_FTRUNCATE_SHM_FAIL,
    GET_SHM_MMAP_SHM_FAIL,
} get_shm_result;

typedef struct {
    int result;
    sem_t *mutex;
    bool isLock;
    int fd;
    void *ptr;
    int ptrSize;
} sem_shm_t;

typedef struct {
    int width, height;
    int bit_depth;
    int quality;
    int flag;
    int col_type;
    unsigned char *rgba;
} img_pic_data;

char *AesEncryptToBase64(char *str, int len);
char *AesDecryptFromBase64(char *str, int len);
int AesEncryptToFile(char *path, char *str, int len);
char *AesDecryptFromFile(char *path);

bool PopenSystem(char *cmd, char *resStr, int resLen);
bool getFileMD5(char *filePath, char *md5);
bool GetEthernetInfo(EthernetInfo_t *info);
json_object *GetJsonObject(json_object *source, char *key, json_type type);
void ReverseString(char* str);

sem_shm_t CreateSemShm(const char *semPath, const char *shmFile, int size, bool isCreate);
int CloseSemShm(sem_shm_t *shmInfo);
int WriteDataToShm(sem_shm_t *shmInfo, void *data, int len);
int ReadDataFromShm(sem_shm_t *shmInfo, void *data, int len);
int ShmExceptionHandleSemPost(sem_shm_t *shmInfo);
int GetSaveSystemInfoToFile(char *path);

/**
 * @param {int} zoom 是缩小系数（1，2，4，8）
 */
int JpegToPng(char *jpegName, char *pngName, int zoom);

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {const char *} __String：待匹配字符串
 * @param {const char *} __pattern：正则表达式
 * @param {regmatch_t} __pmatch：匹配成功返回数组
 * @param {size_t} __nmatch：允许返回的最大数组个数
 */
int UserGetRegexStr(const char *__restrict __String,
                    const char *__restrict __pattern,
                    regmatch_t __pmatch[__restrict_arr],
                    size_t __nmatch);

void RestartNowAppServer(void);
void RestartNowDisplayServer(void);
void RestartNowMasterServer(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
