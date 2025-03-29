/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:20:06
 * @LastEditTime: 2022-09-30 16:35:01
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#include "Base/UpgradeMsgBase.h"
#include "Message/ServerMessage.h"

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */

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
    CrLogOpen(GetUserDataLogDirPtah(), (char *)"upgrade-server");
    pthread_t*serverMessagehandle = ServerMessageInit(NULL);

    pthread_join(*serverMessagehandle, NULL);
    CrLogI("Release serverMessagehandle thread resources!");

    return 0;
}
