/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-01-12 15:10:05
 * @LastEditTime: 2023-09-21 16:10:58
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <pthread.h>

#include "global/Global.h"
#include "monitor.h"

/**
 * @description: 
 * @return {*}
 */
static pthread_t monitor_t;
static char processName[][64] = {
    MASTER_SERVER,
    WIFI_SERVER,
    AUDIO_SERVER,
    APP_SERVER,
    DISPLAY_SERVER,
    UPGRADE_SERVER,
    WEB_SERVER,
    WEBRTC,
    LOG_MAIN
};

/**
 * @description: 
 * @return {*}
 */
static SystemConfig_t GetSystemConfig(void)
{
    SystemConfig_t systemComfig = {0};
    json_object *tempObj = NULL;

    // 从文件读取json数据
    json_object *config = json_object_from_file(GetUserSystemConfigFilePath());
    if (config)
    {
        // 获取 user_info 的json
        json_object *userInfoObj = json_object_object_get(config, "user_info");
        if (userInfoObj)
        {
            // 获取是否同意隐私协议
            tempObj = json_object_object_get(userInfoObj, "agree_privacy");
            if (tempObj) systemComfig.agree_privacy = json_object_get_int(tempObj);
        }
    }

    if (config) json_object_put(config);
    return systemComfig;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *MonitorProcess(void *arg)
{
    CrLogI("Monitor Process statr");
    int delayCount = 0;

    // 启动循环检测
    do {
        // 判断是否存在触发守护进程立即启动状态
        if (access(GetUserMonitorExecuteRunPtah(), F_OK) != 0 && ++delayCount <= 10) {
            sleep(1);
            continue;
        }
        else {
            delayCount = 0;
            if (access(GetUserMonitorExecuteRunPtah(), F_OK) == 0) remove(GetUserMonitorExecuteRunPtah());
        }

        // 检查是否有进程退出，重新拉起
        for (int i = 0; i < sizeof(processName)/sizeof(processName[0]); i++)
        {
            char psCmd[256] = {0};
            snprintf(psCmd, 256, "ps -ef | grep %s | grep -v grep | wc -l", processName[i]);

            // 查询应用是否存在
            char sysRes[1024] = {0};
            if (PopenSystem(psCmd, sysRes, sizeof(sysRes)))
            {
                if (atoi(sysRes) <= 0) {
                    // 判断是否拉起应用
                    char startCmd[256] = {0};
                    if (!strcmp(processName[i], WEBRTC))
                        snprintf(startCmd, 256, WEBRTC_RESTART);
                    else if (!strcmp(processName[i], LOG_MAIN)) {
                        if (GetSystemConfig().agree_privacy) snprintf(startCmd, 256, LOG_MAIN_RESTART);
                    }
                    else
                        snprintf(startCmd, 256, "%s &", processName[i]);

                    // 重新拉起应用
                    if (strlen(startCmd) > 0) CrLogW("<%s> process restart !!!\n", startCmd);
                    system(startCmd);
                }
            }
        }
    } while(1);

    return NULL;
}

/**
 * @description: 
 * @return {*}
 */
static void RunMonitorProcess(void)
{
    pthread_create(&monitor_t, NULL, MonitorProcess, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {int} argc
 * @param {char} *argv
 */
int main(int argc, char *argv[])
{
    FileManagerInit();
    CrLogOpen(GetUserDataLogDirPtah(), (char *)"Monitor");

    RunMonitorProcess();
    pthread_join(monitor_t, NULL);

    return 0;
}
