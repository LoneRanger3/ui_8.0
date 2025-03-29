/**
 * @ Author: Rui Xiong
 * @ Create Time: 2023-02-24 14:07:24
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-02-28 18:57:05
 * @ Description:
 */

#include "CrLog.h"

#ifndef __DISK_INFO_H__
#define __DISK_INFO_H__
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t total_size;    /**< Total heap size */
    uint32_t free_size;     /**< Size of available memory */
    uint32_t used_size;     /**< Size of Heap memory used */
    double used_pct;        /**< Percentage used */
} SystemMemory;

/**
 * @description: 获取磁盘空间MB
 * @param {*}
 * @return {*}
 */

unsigned long long GetDiskTotalSize(char *disk_name);

/**
 * @description: 获取磁盘已用空间MB
 * @param {*}
 * @return {*}
 */

unsigned long long GetDiskUsedSize(char *disk_name);

/**
 * @description: 获取磁盘可用空间MB
 * @param {*}
 * @return {*}
 */

unsigned long long GetDiskAvailableSize(char *disk_name);

/**
 * @description: 获取目录所占空间大小
 * @param {*}
 * @return {*}
 */

unsigned long long GetDirectorySize(char *dir_name);

/**
 * @description: 获取磁盘使用情况
 * @param {*}
 * @return {*}
 */

SystemMemory GetSystemMemorySize(int model);

/**
 * @description: 遍历文件夹内信息
 * @param {char *} dir_name
 * @return {json_object *}
 */

json_object * GetDirectoryInfo(char *dir_name, json_object * infoObj);

/**
 * @description: 遍历文件夹内信息，包含子文件夹
 * @return {*}
 * @param {char} *dir_name
 * @param {int} sort
 */
json_object * GetDirectoryInfoSubFile(char *dir_name, int sort, int *size);

#ifdef __cplusplus
}
#endif

#endif