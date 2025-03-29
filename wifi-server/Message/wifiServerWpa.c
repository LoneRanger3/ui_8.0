/**
 * @file wifiServerWpa.c
 * @author Feng
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "Base/WifiMsgBase.h"
#include "ServerMessage.h"
#include "wifiServerWpa.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
/**
 * @description: 连接网络热点
 * @param  {*}
 * @return {*}
 * @param {char} *name_str
 * @param {char} *pass_str
 */
int UserConnectNetworks(const char *name_str, const char *pass_str)
{
    CrLogW("No hardware driver service\n");
    return 0;
}

/**
 * @description: 断开连接
 * @param  {*}
 * @return {*}
 */
int UserDisconnectNetworks(void)
{
    CrLogW("No hardware driver service\n");
    return 0;
}

/**
 * @description: 删除已保存热点
 * @param  {*}
 * @return {*}
 * @param {char} *name
 * @param {int} nameLen
 */
int UserRemoveNetworks(char *name, int nameLen)
{
    CrLogW("No hardware driver service\n");
    return 0;
}

/**
 * @description: 用户获取设备WiFi信息
 * @param  {*}
 * @return {*}
 */
int UserGetDeviceWifiInfo(void)
{
    CrLogW("No hardware driver service\n");
    return 0;
}

/**
 * @description: 获取已保存热点信息
 * @param  {*}
 * @return {*}
 * @param {char} *result
 * @param {int} len
 */
int UserGetSaveNetworksList(char *result, int len)
{
    CrLogW("No hardware driver service\n");
    return 0;
}

/**
 * @description: 启动wifi守护进程，打开WiFi
 * @param  {*}
 * @return {*}
 */
int UserSetOpenWifiDaemon(void)
{
    CrLogW("No hardware driver service\n");
    return 0;
}

/**
 * @description: 关闭wifi守护进程，关闭wifi
 * @param  {*}
 * @return {*}
 */
int UserSetCloseWifiDeamon(void)
{
    CrLogW("No hardware driver service\n");
    return 0;
}


/**
 * @description: 连接已保存wifi热点
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
int UserConnectSavedNetworks(char *name)
{
    CrLogW("No hardware driver service\n");
    return 0;
}

/**
 * @description: 扫描热点
 * @param  {*}
 * @return {*}
 */
int UserScanWifiList(void)
{
    CrLogW("No hardware driver service\n");
    return 0;
}

/**
 * @description: 检查WiFi状态线程
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
void *CheckWifiStateThread(void *arg)
{
    CrLogW("No hardware driver service\n");
    pthread_exit(0);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int ExceptionHandleFreeScanNetworksInfo(void)
{
    CrLogW("No hardware driver service\n");
    return 0;
}
