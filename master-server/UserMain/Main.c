/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:20:06
 * @LastEditTime: 2023-07-28 09:12:47
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#include "Base/MasterMsgBase.h"
#include "Wifi/WifiManager.h"
#include "Display/DisplayManager.h"
#include "Control/PrintfManager.h"
#include "Audio/AudioManager.h"
#include "App/AppManager.h"
#include "Web/WebManager.h"
#include "Upgrade/UpgradeManager.h"
#include "Burn/BurnManager.h"
#include "Control/Controller.h"
#include "Appointment/Appointment.h"
#include "SysTransfer/SysTransfer.h"

/**
 * @description: 全局变量定义
 * @return {*}
 */
MsgHandle_t *wifiManager;
MsgHandle_t *displayManager;
MsgHandle_t *audioManager;
MsgHandle_t *appManager;
MsgHandle_t *webManager;
MsgHandle_t *upgradeManager;
MsgHandle_t *burnManager;
MsgHandle_t *controller;
MsgHandle_t *appointment;
MsgHandle_t *sysTransfer;

/**
 * @description: 静态函数声明
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
    AppointmentExceptionHandleSemPost();
    SysTransferExceptionHandleSemPost();
    AudioManagerExceptionHandleSemPost();
    AppManagerExceptionHandleSemPost();
    WebManagerExceptionHandleSemPost();
    UpgradeManagerExceptionHandleSemPost();
    BurnManagerExceptionHandleSemPost();
    ControllerExceptionHandleSemPost();
    DisplayManagerExceptionHandleSemPost();
    PrintfManagerExceptionHandleSemPost();
    WifiManagerExceptionHandleSemPost();

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
    CrLogOpen(GetUserDataLogDirPtah(), (char *)"master-server");
    SetLogFileNum(20);
    ShareStateInit();

    wifiManager = WifiManagerInit(NULL);
    displayManager = DisplayManagerInit(NULL);
    audioManager = AudioManagerInit(NULL);
    appManager = AppManagerInit(NULL);
    webManager = WebManagerInit(NULL);
    upgradeManager = UpgradeManagerInit(NULL);
    burnManager = BurnManagerInit(NULL);
    controller = ControllerInit(NULL);
    appointment = AppointmentInit(NULL);
    sysTransfer= SysTransferInit(NULL);
    
    pthread_join(wifiManager->handle, NULL);
    CrLogI("Release wifiManager thread resources!");

    pthread_join(displayManager->handle, NULL);
    CrLogI("Release displayManager thread resources!");

    pthread_join(audioManager->handle, NULL);
    CrLogI("Release audioManager thread resources!");

    pthread_join(appManager->handle, NULL);
    CrLogI("Release appManager thread resources!");

    pthread_join(webManager->handle, NULL);
    CrLogI("Release webManager thread resources!");

    pthread_join(upgradeManager->handle, NULL);
    CrLogI("Release upgradeManager thread resources!");

    pthread_join(burnManager->handle, NULL);
    CrLogI("Release burnManager thread resources!");

    pthread_join(controller->handle, NULL);
    CrLogI("Release controller thread resources!");

    pthread_join(appointment->handle, NULL);
    CrLogI("Release appointment thread resources!");

    pthread_join(sysTransfer->handle, NULL);
    CrLogI("Release sysTransfer thread resources!");

    return 0;
}
