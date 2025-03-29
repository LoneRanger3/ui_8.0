/**
 * @ Author: Rui Xiong
 * @ Create Time: 2023-02-21 11:24:16
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-02-21 19:26:16
 * @ Description:
 */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "CopyFile.h"
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../SystemCmd/SystemCmd.h"

/** 全局回调函数 */
static bool cancelCopyFlag = false;
static progress_callback g_cb;
static void *g_userPtr;
void *get_frate_fmc(void *args);   

typedef struct {
    char file_name[256];
    char dir_name[256];
    progress_callback cb;
    void *userPtr;
	int run_flag;
}ST_GET_RATE;

/** 设置回调函数 */
int file_setCallback(progress_callback cb, void *userPtr)
{
    g_cb = cb;
    g_userPtr = userPtr;
    return 0;
}

/** 获取速率线程状态 */
void *get_frate_fmc(void *args)
{
    ST_GET_RATE *pstGetRate = (ST_GET_RATE*)args;

    int nSrcFileSize = 0;
    int nDestFileSize = 0, nDestTempSize = 0; 
    int fRate = 0;

    /** 获得原文件的大小 */
    nSrcFileSize = getFileSize(pstGetRate->file_name);
        
    while(1){
		sleep(1);
		
		/** 如果run_flag为0，退出线程 */ 
		if(pstGetRate->run_flag == 0) break;

		// 如果dir_name为0，采用定时发送进度信息
		if(strlen(pstGetRate->dir_name) == 0){
			fRate++;
			if(pstGetRate->cb) pstGetRate->cb(fRate, pstGetRate->userPtr); //进度通过回调发送出去
			continue;
		}

        /** 获得目的文件的大小 */
        nDestTempSize = getFileSize(pstGetRate->dir_name);
		if(nDestTempSize == 0)
			nDestFileSize += 6000;
		else 
			nDestFileSize = nDestTempSize;

        /*** 计算复制的进度 */
        if(nSrcFileSize) {
            fRate = nDestFileSize * 100 / nSrcFileSize;
            if(pstGetRate->cb) pstGetRate->cb(fRate, pstGetRate->userPtr); //进度通过回调发送出去
        }
            
        /** 复制完成之后，退出循环 */
        if (nSrcFileSize == nDestFileSize)
        {
            if(pstGetRate->cb) pstGetRate->cb(100, pstGetRate->userPtr);
            break;
        } 
    }
    return NULL;
}

/** 拷贝一个文件到一个目录 */
int file_copyFileToDir(char *file_name,char *dir_name)
{  
    // 判断文件路径是否有效
    if (!file_name || !dir_name) {
        CrLogW("invalid file path\n");
        return -1;
    }

    int ret;
    pthread_t pth;

    bool copyFinish = false;
    char readBuff[4096] = {0};
    ST_GET_RATE stGetRate;

    strcpy(stGetRate.file_name, file_name);
    strcpy(stGetRate.dir_name, dir_name);
    stGetRate.cb = g_cb;
    stGetRate.userPtr = g_userPtr;
	stGetRate.run_flag = 1;
    cancelCopyFlag = false;

    // 创建线程
    if(stGetRate.cb) stGetRate.cb(0, stGetRate.userPtr);
    ret = pthread_create(&pth, NULL, get_frate_fmc, (void*)&stGetRate);
    if(ret < 0){
        CrLogW("Create pthread for \'\' is Failed - %d!\n", ret);
        return -1;
    }

    // 打开文件
    FILE *fpSrc = fopen(file_name, "r");
    FILE *fpDes = fopen(dir_name, "w+");
    if (!fpSrc || !fpDes) {
        CrLogW("open file fail!\n");
        goto COPY_END;
    }

    // 复制文件
    while(!feof(fpSrc))
    {
        bzero(readBuff, sizeof(readBuff));
        if (cancelCopyFlag) break;
        
        // 读取
        size_t count = fread(readBuff, sizeof(char), sizeof(readBuff) - 1, fpSrc);
        if (count == 0) {
            CrLogW("read file fail, %s\n", strerror(errno));
            break;
        }
        // 写入
        count = fwrite(readBuff, sizeof(char), count, fpDes);
        if (count == 0) {
            CrLogW("read file fail, %s\n", strerror(errno));
            break;
        }
        // 判断文件是否有效
        if ((access(file_name, F_OK) != 0) || (access(dir_name, F_OK) != 0)) break;
    }
    // 判断是否正常读取结束
    if (feof(fpSrc)) {
        sync();
        copyFinish = true;
        if(stGetRate.cb) stGetRate.cb(100, stGetRate.userPtr);
    }
    

COPY_END:
    // 关闭文件
    if (fpSrc) fclose(fpSrc);
    if (fpDes) fclose(fpDes);

    // 关闭线程，等待线程结束
    stGetRate.run_flag = 0;
    pthread_join(pth, 0);

    // 返回结果
    if (copyFinish) return 0;
    else return -1;
}

/**
 * @description: 停止把文件拷贝到目录 
 * @param {*}
 * @return {*}
 */

int stop_copyFileToDir(void) { cancelCopyFlag = true; return 0; }

/**
 * @description: 获取文件大小
 * @param {*}
 * @return {*}
 */

int getFileSize(char *file_name)
{
    struct stat buf = {0};

	stat(file_name, &buf);

    return buf.st_size / 1024;
}