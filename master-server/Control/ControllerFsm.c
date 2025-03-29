/*
 * @Description : Controller状态机
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-08 18:17:29
 * @LastEditTime: 2022-04-11 14:57:46
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "Base/MasterMsgBase.h"
#include "ControllerFsm.h"
#include "AppPrint.h"
#include "AppModeIdle.h"
#include "AppModeSdPrint.h"
#include "AppModeAutoPrint.h"

typedef void (*MODE_ACTION)(void);	

typedef struct FSM_ACTION {
	FSM_MODE_t 		modeID;
	MODE_ACTION 	enterApp;	
	MODE_ACTION 	executeApp;	
	MODE_ACTION 	exitApp;
}FSM_ACTION_t;

typedef struct FSM{
	FSM_MODE_t curMode;
	FSM_MODE_t nextMode;
	FSM_ACTION_t *action;
}FSM_t;


static FSM_t modeFsm; // 定义状态机
/**
 * @description: 状态机初始化
 * @param  {*}
 * @return {*}
 * @param {FSM_ACTION_t} *action
 */
static void AppFsmImit(FSM_ACTION_t *action)
{
	modeFsm.curMode = APP_MODE_IDLE;
	modeFsm.nextMode = APP_MODE_IDLE;
	modeFsm.action = action;
}

/**
 * @description: 监控状态机模式切换
 * @param  {*}
 * @return {*}
 */
static void AppModeMonitor(void)
{
    if(modeFsm.curMode != modeFsm.nextMode)
	{
		modeFsm.action[modeFsm.curMode].exitApp();
		modeFsm.action[modeFsm.nextMode].enterApp();
		modeFsm.curMode = modeFsm.nextMode;
	}
    modeFsm.action[modeFsm.curMode].executeApp();
}

/**
 * @description: 状态机模式切换表；
 *               增加模式：
 *                  1、定义模式枚举
 *                  2、定义模式的“enterApp”、“executeApp”、“exitApp”函数，添加到表格
 * @param  {*}
 * @return {*}
 */
static FSM_ACTION_t actionDeclare[] = {
    {APP_MODE_IDLE,             EnterAppIdle,       ExecuteAppIdle,         ExitAppIdle},
	{APP_MODE_SD_PRINT,         EnterAppSdPrint,	ExecuteAppSdPrint,      ExitAppSdPrint},
	{APP_MODE_AUTO_PRINT,       EnterAppAutoPrint,	ExecuteAppAutoPrint,    ExitAppAutoPrint},
};

/**
 * @description: 设备工作运行的基准线程，确定运行时间周期
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
static void *FsmThread(void *arg)
{
	while(1)
	{
		AppModeMonitor();
        usleep(1000 * 10);
	}
	
	return 0;
}

/**
 * @description: 初始化controller状态机
 * @param  {*}
 * @return {*}
 */
int ControllerFsmInit(void)
{
    AppFsmImit(actionDeclare);
    pthread_t fsmHandle;
    int res = pthread_create(&fsmHandle, NULL, (void*)FsmThread, NULL);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return -1;
    }

    return 0;  
}

/**
 * @description: 状态机切换控制
 * @param  {*}
 * @return {*}
 * @param {FSM_MODE_t} stModeID
 */
void AppModeChange(FSM_MODE_t stModeID)
{
	uint8_t i = 0;
    for(i=0; modeFsm.action[i].modeID < APP_MODE_MAX; i++)
	{
		if(stModeID == modeFsm.action[i].modeID)
		{
			modeFsm.nextMode = modeFsm.action[i].modeID;
			return;
		}
	}	
}

