/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:20:06
 * @LastEditTime: 2023-07-28 09:12:31
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#include "Base/AppMsgBase.h"
#include "Message/ServerMessage.h"
#include "CxyManager/CxyManager.h"

/**
 * @description: 静态变量
 * @param  {*}
 * @return {*}
 */
static CxyManager CxyManagerClient;

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int AppConfigFileInit(CxyManager *client);

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} sig_no
 */
static void Terminate(int sig_no)
{
    CrLogI("Enter blackbox_handler: ");
    CrLogI("Got signal name %s, num %d; exiting ...", strsignal(sig_no), sig_no);

    if (SIGHUP == sig_no || SIGPIPE == sig_no || SIGUSR2 == sig_no || SIGUSR1 == sig_no)
    {
        CrLogD("ignore signal :%d\r\n", sig_no);
        return;
    }
    ExceptionHandleSemPost();

    CrLogE("EXIT:!!!\n\n");
    exit(1);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static void InstallSignalHandler(void)
{
    signal(SIGBUS, Terminate);
    signal(SIGFPE, Terminate);
    signal(SIGHUP, Terminate);
    signal(SIGILL, Terminate);
    signal(SIGINT, Terminate);
    signal(SIGIOT, Terminate);
    signal(SIGPIPE, Terminate);
    signal(SIGQUIT, Terminate);
    signal(SIGSEGV, Terminate);
    signal(SIGSYS, Terminate);
    signal(SIGTERM, Terminate);
    signal(SIGTRAP, Terminate);
    signal(SIGUSR1, Terminate);
    signal(SIGUSR2, Terminate);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} argv
 * @param {char} *
 */
int main(int argv, char **argc)
{
    InstallSignalHandler();
    FileManagerInit();
    CrLogOpen(GetUserDataLogDirPtah(), (char *)"app-server");
    SetLogFileNum(10);
    // 初始化配置文件
    AppConfigFileInit(&CxyManagerClient);
    pthread_t *serverMessagehandle = ServerMessageInit(&CxyManagerClient);
    CxyManagerClient.Start();

    pthread_join(*serverMessagehandle, NULL);
    CrLogI("Release serverMessagehandle thread resources!");

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int AppConfigFileInit(CxyManager *client)
{
    // 判断路径是否存在
    if (access(GetUserDataConfigDirPtah(), F_OK) != 0) {
        char cmd[300] = {0};
        snprintf(cmd, 300, "mkdir -p %s", GetUserDataConfigDirPtah());

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    // 初始化创想云
    client->CxyInit();
    return 0;
}

