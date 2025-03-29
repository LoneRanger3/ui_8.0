/*
 * @Description : 空闲模式
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-08 18:53:35
 * @LastEditTime: 2023-05-27 11:56:35
 */
#include "Base/MasterMsgBase.h"
#include "AppPrint.h"
#include "AppModeIdle.h"


/**
 * @description: 进入
 * @param  {*}
 * @return {*}
 */
void EnterAppIdle(void)
{
    CrLogI("enter app mode idle");
    // MsaterCreateNewLogFile();
    ClearSingleTaskFunctionFailure();
    UpdataDeviceState(DEVICE_STATE_IDLE);
}

/**
 * @description: 运行
 * @param  {*}
 * @return {*}
 */
void ExecuteAppIdle(void)
{
    AppSendPrintState();
    AutoGetGetPrinterStatus();
}

/**
 * @description: 退出
 * @param  {*}
 * @return {*}
 */
void ExitAppIdle(void)
{
    CrLogI("exit app mode idle\n");
    UpdataDeviceState(DEVICE_STATE_PRINTTING);
}