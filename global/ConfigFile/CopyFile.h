/**
 * @ Author: Rui Xiong
 * @ Create Time: 2023-02-21 11:24:06
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-02-24 16:03:04
 * @ Description:
 */
#include "CrLog.h"

#ifndef __COPY_FILE_H__
#define __COPY_FILE_H__
#ifdef __cplusplus
extern "C" {
#endif
/** 定义回调函数 */
typedef void (*progress_callback)(int progress, void *userPtr);

/**
 * @description: 设置回调函数
 * @param {*} cb 回调函数指针
 * @return {*}
 */
int file_setCallback(progress_callback cb, void *userPtr);

/**
 * @description:把文件拷贝到目录 
 * @param {char} *file_name 源文件名
 * @param {char} *dir_name  目的文件目录
 * @return {*}
 */
int file_copyFileToDir(char *file_name, char *dir_name);

/**
 * @description: 获取文件大小KB
 * @param {*}
 * @return {*}
 */

int getFileSize(char *file_name);

/**
 * @description: 停止把文件拷贝到目录 
 * @param {*}
 * @return {*}
 */

int stop_copyFileToDir(void);


#ifdef __cplusplus
}
#endif

#endif