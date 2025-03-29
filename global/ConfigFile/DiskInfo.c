/**
 * @ Author: Rui Xiong
 * @ Create Time: 2023-02-24 14:07:38
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-02-28 18:57:28
 * @ Description:
 */

#include "../Global.h"
#include <sys/statfs.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/**
 * @description: 静态变量
 * @return {*}
 */
static const char *scanPath = NULL;

/**
 * @description: 获取磁盘空间
 * @param {char *} disk_name
 * @return {unsigned long long}
 */

unsigned long long GetDiskTotalSize(char *disk_name)
{
    struct statfs diskInfo;
    int lSts = 0;
    memset(&diskInfo, 0, sizeof(struct statfs));
    lSts = statfs(disk_name, &diskInfo);
    if(lSts != 0){
        return 0;
    }
    unsigned long long blocksize = diskInfo.f_bsize;    //每个block里包含的字节数
    unsigned long long totalsize = blocksize * diskInfo.f_blocks;
    return totalsize;
}

/**
 * @description: 获取磁盘已用空间
 * @param {char *} disk_name
 * @return {unsigned long long}
 */

unsigned long long GetDiskUsedSize(char *disk_name)
{
    struct statfs diskInfo;
    int lSts = 0;
    memset(&diskInfo, 0, sizeof(struct statfs));
    lSts = statfs(disk_name, &diskInfo);
    if(lSts != 0){
        return 0;
    }
    unsigned long long blocksize = diskInfo.f_bsize;    //每个block里包含的字节数
    unsigned long long usedsize = (diskInfo.f_blocks - diskInfo.f_bfree)  * blocksize;     //已用空间大小
    return usedsize;
}

/**
 * @description: 获取磁盘可用空间
 * @param {char *} disk_name
 * @return {unsigned long long}
 */

unsigned long long GetDiskAvailableSize(char *disk_name)
{
    struct statfs diskInfo;
    int lSts = 0;
    memset(&diskInfo, 0, sizeof(struct statfs));
    lSts = statfs(disk_name, &diskInfo);
    if(lSts != 0){
        return 0;
    }
    unsigned long long blocksize = diskInfo.f_bsize;    //每个block里包含的字节数
    unsigned long long availablesize = diskInfo.f_bavail * blocksize;     //可用空间大小
    return availablesize;
}

/**
 * @description: 获取目录所占空间大小
 * @param {char *} dir_name
 * @return {unsigned long long}
 */

unsigned long long GetDirectorySize(char *dir_name)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    unsigned long long totalSize=0;

    if ((dp = opendir(dir_name)) == NULL)
    {
        CrLogI("Cannot open dir: %s\n", dir_name);
        return 0; //可能是个文件，或者目录不存在
    }

    //先加上自身目录的大小
    lstat(dir_name, &statbuf);
    totalSize+=statbuf.st_size;

    while ((entry = readdir(dp)) != NULL)
    {
        char subdir[1024];
        sprintf(subdir, "%s/%s", dir_name, entry->d_name);
        lstat(subdir, &statbuf);

        if (S_ISDIR(statbuf.st_mode))
        {
            if (strcmp(".", entry->d_name) == 0 ||
                strcmp("..", entry->d_name) == 0)
            {
                continue;
            }

            unsigned long long subDirSize = GetDirectorySize(subdir);
            totalSize+=subDirSize;
        }
        else
        {
            totalSize+=statbuf.st_size;
        }
    }

    closedir(dp);
    return totalSize;
}

/**
 * @description: 获取磁盘使用情况
 * @return {*}
 * @param {int} model
 */
SystemMemory GetSystemMemorySize(int model)
{
    SystemMemory menInfo;
#ifdef CROSS_COMPILE
    switch (model) {
        case CR_K1:
        case CR_K1_Max:
        case K1_Max_SE:
        case PF_05:
        {
            menInfo.total_size = 8 * 1024;
            break;
        }

        default: menInfo.total_size = GetDiskTotalSize(GetUserDataPath()) / (1024 * 1024); break;
    }
#else
    menInfo.total_size = GetDiskTotalSize(GetUserDataPath()) / (1024 * 1024);
#endif

    menInfo.free_size = GetDiskAvailableSize(GetUserDataPath()) / (1024 * 1024);
    menInfo.used_size = menInfo.total_size - menInfo.free_size;
    menInfo.used_pct = (double)menInfo.used_size / menInfo.total_size;

    return menInfo;
}

/**
 * @description: 遍历文件夹内信息
 * @param {char *} dir_name
 * @return {*}
 */
json_object * GetDirectoryInfo(char *dir_name, json_object * infoObj)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	dp = opendir(dir_name);
	if (NULL == dp)
	{
		CrLogI("Cannot open dir: %s\n", dir_name);
		return infoObj;
	}
	while((entry = readdir(dp)) != NULL)
	{
        char subdir[1024];
        sprintf(subdir, "%s/%s", dir_name, entry->d_name);
        lstat(subdir, &statbuf);

		if(S_ISDIR(statbuf.st_mode))
		{
            if (strcmp(".", entry->d_name) == 0 ||
                strcmp("..", entry->d_name) == 0)
            {
                continue;
            }
            GetDirectoryInfo(subdir, infoObj);
		}
		else
		{
            if(strlen(entry->d_name)>6 && !strcmp(".gcode",entry->d_name+(strlen(entry->d_name)-6)))
            {
                CrLogI("name:%s path:%s size:%ld time:%ld", entry->d_name, subdir, statbuf.st_size, statbuf.st_ctime);
                json_object *arrayObj = json_object_new_object();
                json_object_object_add(arrayObj, "name", json_object_new_string(entry->d_name));
                json_object_object_add(arrayObj, "path", json_object_new_string(subdir));
                json_object_object_add(arrayObj, "file_size", json_object_new_int(statbuf.st_size));
                json_object_object_add(arrayObj, "file_create_time", json_object_new_int(statbuf.st_ctime));
                json_object_array_add(infoObj, arrayObj);
            }
		}
	}
	closedir(dp);
    return infoObj;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {dirent} *entry
 */
static int FindDirAndGcode(const struct dirent *entry)
{
    if ((entry->d_type != 4 && entry->d_type != 8) ||
        strcmp(".", entry->d_name) == 0 ||
        strcmp("..", entry->d_name) == 0 ||
        entry->d_name[0] == '.' ||
        (entry->d_type == 4 && strstr(entry->d_name, "System Volume Information")) ||
        (entry->d_type == 8 && strlen(entry->d_name) < strlen(".gcode")) || 
        (entry->d_type == 8 && strcmp(entry->d_name + (strlen(entry->d_name) - strlen(".gcode")), ".gcode")))
    {
        return 0;
    }
    return 1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {dirent} *
 * @param {dirent} *
 */
static inline int SortByTime(const struct dirent **a, const struct dirent **b)
{
    struct stat sbuf1, sbuf2;
    char path1[PATH_MAX], path2[PATH_MAX];

    snprintf(path1, PATH_MAX, "%s/%s", scanPath, (*a)->d_name);
    snprintf(path2, PATH_MAX, "%s/%s", scanPath, (*b)->d_name);

    if (lstat(path1, &sbuf1)) return 0;
    if (lstat(path2, &sbuf2)) return 0;

    return sbuf1.st_mtim.tv_sec - sbuf2.st_mtim.tv_sec;
}

/**
 * @description: 
 * @return {*}
 * @param {dirent} *
 * @param {dirent} *
 */
static inline int SortBySize(const struct dirent **a, const struct dirent **b)
{
    struct stat sbuf1, sbuf2;
    char path1[PATH_MAX], path2[PATH_MAX];

    snprintf(path1, PATH_MAX, "%s/%s", scanPath, (*a)->d_name);
    snprintf(path2, PATH_MAX, "%s/%s", scanPath, (*b)->d_name);

    if (lstat(path1, &sbuf1)) return 0;
    if (lstat(path2, &sbuf2)) return 0;

    return sbuf1.st_size - sbuf2.st_size;
}

/**
 * @description: 
 * @return {*}
 * @param {dirent} *
 * @param {dirent} *
 */
static inline int SortByMode(const struct dirent **a, const struct dirent **b)
{
    struct stat sbuf1, sbuf2;
    char path1[PATH_MAX], path2[PATH_MAX];

    snprintf(path1, PATH_MAX, "%s/%s", scanPath, (*a)->d_name);
    snprintf(path2, PATH_MAX, "%s/%s", scanPath, (*b)->d_name);

    if (lstat(path1, &sbuf1)) return 0;
    if (lstat(path2, &sbuf2)) return 0;

    return sbuf1.st_mode - sbuf2.st_mode;
}

/**
 * @description: 遍历文件夹内信息，包含子文件夹
 * @return {*}
 * @param {char} *dir_name
 * @param {int} sort
 */
json_object * GetDirectoryInfoSubFile(char *dir_name, int sort, int *size)
{
    int count = 0;
    scanPath = dir_name;
    struct dirent **entry_list = NULL;

    // 按照制定的规则顺序，获取文件个数和文件名称
    switch (sort) {
        case FILE_NAME_POSITIVE_SORT:
        case FILE_NAME_REVERSE_SORT: count = scandir(scanPath, &entry_list, FindDirAndGcode, alphasort); break;
        case FILE_TIME_POSITIVE_SORT:
        case FILE_TIME_REVERSE_SORT: count = scandir(scanPath, &entry_list, FindDirAndGcode, SortByTime); break;
        case FILE_MODE_POSITIVE_SORT:
        case FILE_MODE_REVERSE_SORT: count = scandir(scanPath, &entry_list, FindDirAndGcode, SortByMode); break;
        case FILE_SIZE_POSITIVE_SORT:
        case FILE_SIZE_REVERSE_SORT: count = scandir(scanPath, &entry_list, FindDirAndGcode, SortBySize); break;

        default: count = scandir(scanPath, &entry_list, FindDirAndGcode, alphasort); break;
    }

    // 获取文件信息
    json_object *infoObj = json_object_new_array();
    for (int i = 0; i < count; i++)
    {
        // 判断是否是倒序
        int sort_selec = i;
        if (sort == FILE_NAME_REVERSE_SORT || sort == FILE_TIME_REVERSE_SORT ||
            sort == FILE_MODE_REVERSE_SORT || sort == FILE_SIZE_REVERSE_SORT)
            sort_selec = count - 1 - i;

        char subdir[1024] = {0};
        struct stat statbuf;
        struct dirent *entry = entry_list[sort_selec];

        sprintf(subdir, "%s/%s", scanPath, entry->d_name);
        lstat(subdir, &statbuf);

        if(S_ISDIR(statbuf.st_mode)) {
            json_object *dirObj = GetDirectoryInfoSubFile(subdir, sort, size);
            json_object *arrayObj = json_object_new_object();
            json_object_object_add(arrayObj, "type", json_object_new_int(entry->d_type));
            json_object_object_add(arrayObj, "name", json_object_new_string(entry->d_name));
            json_object_object_add(arrayObj, "path", json_object_new_string(subdir));
            json_object_object_add(arrayObj, "file", dirObj);
            json_object_array_add(infoObj, arrayObj);
            scanPath = dir_name;
		}
		else {
            json_object *arrayObj = json_object_new_object();
            json_object_object_add(arrayObj, "type", json_object_new_int(entry->d_type));
            json_object_object_add(arrayObj, "name", json_object_new_string(entry->d_name));
            json_object_object_add(arrayObj, "path", json_object_new_string(subdir));
            json_object_object_add(arrayObj, "file_size", json_object_new_int(statbuf.st_size));
            json_object_object_add(arrayObj, "create_time", json_object_new_int(statbuf.st_ctime));
            json_object_array_add(infoObj, arrayObj);
            *size += 1;
		}
        free(entry);
    }

    free(entry_list);
    return infoObj;
}
