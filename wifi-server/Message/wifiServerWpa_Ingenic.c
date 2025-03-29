/**
 * @file wifiServerWpa_Tina.c
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
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "Base/WifiMsgBase.h"
#include "ServerMessage.h"
#include "wifiServerWpa.h"
#include "libhardware2/wifi.h"

/*********************
 *      DEFINES
 *********************/
#define MAX_SCAN_COUNT          50

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static enum wifi_server_state wifiServerState = SERVER_DISCONNECT;
static enum wifi_connect_state wifiConnectState = WIFI_DISCONNECTED;
static int networkConnectState = -1;
static WifiConnectRes_t lastConnectRes = WIFI_CONNECT_FAIL;

static struct Wifi_Manager_t getWifiManagerInfo = {
    .info = NULL,
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
/**
 * @description: 更新设备WiFi信息
 * @param  {*}
 * @return {*}
 * @param {struct wifi_status} *getStatus
 * @param {struct connection_status} *info
 */
static void UpdataDeviceWifiInfo(void)
{
    // 获取wifi信息
    struct wifi_network_status_info info;
    memset(&info, 0, sizeof(struct wifi_network_status_info));
    wifi_get_status_info(&info);

    // 获取wifi状态
    CrLogI("get wifi connect status = %s", info.status);
    if (strstr(info.status, "ASSOCIATED") || strstr(info.status, "COMPLETED"))
        wifiConnectState = WIFI_CONNECTED;
    else if (strstr(info.status, "ASSOCIATING"))
        wifiConnectState = WIFI_CONNECTING;
    else
        wifiConnectState = WIFI_DISCONNECTED;

    // 转换wifi状态
    int networkState = WIFI_STATE_DISCONNECTED;
    switch (wifiConnectState)
    {
        case WIFI_CONNECTING: networkState = WIFI_STATE_CONNECTING; break;
        case WIFI_CONNECTED: networkState = WIFI_STATE_CONNECTED; break;
        case WIFI_DISCONNECTED: networkState = WIFI_STATE_DISCONNECTED; break;
        default: networkState = WIFI_STATE_DISCONNECTED; break;
    }

    // 整合wifi和网络状态
    if (wifiServerState == SERVER_CONNECT && networkState == WIFI_STATE_CONNECTED && networkConnectState == 0)
        networkState = WIFI_STATE_NETWORK;

    CrLogI("wifi state, network: %d, ssid = [%s]", networkState, info.ssid);
    CrLogI("wifi change, get connect ip = %s", info.ip_addr);
    CrLogI("get signal strength = %d\n", info.signal_strength);

    // 同步网络信息
    NetworksInfo updata = NETWORKS_INFO__INIT;
    updata.has_status = 1;
    updata.status = networkState;
    if (wifiServerState == SERVER_CONNECT && 
       (networkState == WIFI_STATE_NETWORK || networkState == WIFI_STATE_CONNECTED))
    {
        updata.has_ip = 1;
        updata.ip.data = info.ip_addr;
        updata.ip.len = sizeof(info.ip_addr) + 1;
        updata.has_ssid = 1;
        updata.ssid.data = info.ssid;
        updata.ssid.len = sizeof(info.ssid) + 1;
        updata.has_signal = 1;
        updata.signal = info.signal_strength;
    }

    // 应答
    GET_MESSAGE_BUFF(buff);
    size_t len = networks_info__pack(&updata, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_SERVER, SERVER_CMD_WIFI_GET_DEVICE_WIFI_INFO_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 释放扫描热点获取的缓存信息
 * @param  {*}
 * @return {*}
 * @param {Wifi_Manager_t} *wifiInfo
 */
static int FreeScanNetworksInfo(struct Wifi_Manager_t *wifiInfo)
{
    CrLogI("Free Scan Networks Info\n");
    if (wifiInfo->info != NULL)
    {
        for (int i = 0; i < wifiInfo->wifiNum; i++)
        {
            for (int j = 0; j < wifiInfo->info[i]->infoSize; j++)
            {
                free(wifiInfo->info[i]->single[j].str);
                wifiInfo->info[i]->single[j].str = NULL;
            }
            free(wifiInfo->info[i]);
            wifiInfo->info[i] = NULL;
        }
        free(wifiInfo->info);
        wifiInfo->info = NULL;
        wifiInfo->wifiNum = 0;
    }

    return 0;
}

/**
 * @description: 筛选SSID是否相同或者为空
 * @param  {*}
 * @return {*}
 * @param {Wifi_Manager_t} *list
 */
static int FilterSSIDSameOrEmpty(struct Wifi_Manager_t *list)
{
    int filteSize = 0;
    // 申请空间储存wifi信息
    struct Wifi_Info_t **filterList = (struct Wifi_Info_t **)malloc(sizeof(struct Wifi_Info_t *) * list->wifiNum);
    if (filterList == NULL)
    {
        CrLogE("no memory to allocate\n");
        FreeScanNetworksInfo(list);
        // 保存筛选后的数据
        list->wifiNum = 0;
        list->info = NULL;
        return -1;
    }

    for (int i = 0; i < list->wifiNum; i++)
    {
        if (list->info[i]->single[WIFI_INFO_TYPE_SSID].strLen == 1) continue; // 长度最少一个字符‘\0’
        bool ssidSameFlag = false;
        for (int j = 0; j < filteSize; j++)
        {
            if (strcmp(filterList[j]->single[WIFI_INFO_TYPE_SSID].str, list->info[i]->single[WIFI_INFO_TYPE_SSID].str) == 0)
            {
                int signal1 = atoi(filterList[j]->single[WIFI_INFO_TYPE_SIGNAL].str);
                int signal2 = atoi(list->info[i]->single[WIFI_INFO_TYPE_SIGNAL].str);
                if (signal1 < signal2)
                {
                    filterList[j]->infoSize = list->info[i]->infoSize;
                    for (int k = 0; k < list->info[i]->infoSize; k++)
                    {
                        filterList[j]->single[k].strLen = list->info[i]->single[k].strLen;
                        free(filterList[j]->single[k].str);
                        filterList[j]->single[k].str = (char *)malloc(list->info[i]->single[k].strLen + 1);
                        if (filterList[j]->single[k].str == NULL)
                        {
                            CrLogE("no memory to allocate\n");
                            continue;
                        }
                        memset(filterList[j]->single[k].str, 0, list->info[i]->single[k].strLen + 1);
                        memcpy(filterList[j]->single[k].str, list->info[i]->single[k].str, list->info[i]->single[k].strLen);
                    }
                }
                ssidSameFlag = true;
                break;
            }
        }
        if (ssidSameFlag == false)
        {
            filterList[filteSize] = (struct Wifi_Info_t *)malloc(sizeof(struct Wifi_Info_t));
            if (filterList[filteSize] == NULL)
            {
                CrLogE("no memory to allocate\n");
                continue;
            }
            memset(filterList[filteSize], 0, sizeof(struct Wifi_Info_t));

            filterList[filteSize]->infoSize = list->info[i]->infoSize;
            for(int j = 0; j < list->info[i]->infoSize; j++)
            {
                filterList[filteSize]->single[j].strLen = list->info[i]->single[j].strLen;
                filterList[filteSize]->single[j].str = (char *)malloc(list->info[i]->single[j].strLen);
                if (filterList[filteSize]->single[j].str == NULL)
                {
                    CrLogE("no memory to allocate\n");
                    continue;
                }
                memset(filterList[filteSize]->single[j].str, 0, list->info[i]->single[j].strLen);
                memcpy(filterList[filteSize]->single[j].str, list->info[i]->single[j].str, list->info[i]->single[j].strLen);
            }
            filteSize++;
        }
    }
    FreeScanNetworksInfo(list);
    CrLogI("Filter the remaining number after the SSID is empty %d", filteSize);
    
    // 申请空间储存wifi信息
    struct Wifi_Info_t **confirmList = (struct Wifi_Info_t **)malloc(sizeof(struct Wifi_Info_t *) * filteSize);
    if (confirmList == NULL)
    {
        CrLogE("no memory to allocate\n");
        free(filterList);
        // 保存筛选后的数据
        list->wifiNum = 0;
        list->info = NULL;
        return -1;
    }
    for (int i = 0; i < filteSize; i++)
    {
        confirmList[i] = filterList[i];
    }
    free(filterList);

    // 保存筛选后的数据
    list->wifiNum = filteSize;
    list->info = confirmList;
    CrLogI("Filter SSID is empty or the same name is completed");

    return 0;
}

/**
 * @description: 按照wifi信号强度排序
 * @param  {*}
 * @return {*}
 * @param {Wifi_Manager_t} *wifiInfo
 */
static int WifiSignalStrengthSorting(struct Wifi_Manager_t *wifiInfo)
{
    struct Wifi_Info_t *temp;
    for (int i = 0; i < (wifiInfo->wifiNum - 1); i++)
    {
        for (int j = 0; j < (wifiInfo->wifiNum - i - 1); j++)
        {
            int signal1 = atoi(wifiInfo->info[j]->single[WIFI_INFO_TYPE_SIGNAL].str);
            int signal2 = atoi(wifiInfo->info[j+1]->single[WIFI_INFO_TYPE_SIGNAL].str);
            if (signal1 < signal2)
            {
                temp = wifiInfo->info[j];
                wifiInfo->info[j] = wifiInfo->info[j+1];
                wifiInfo->info[j+1] = temp;
            }
        }
    }
    CrLogI("Sort by signal strength\n");

    return 0;
}

/**
 * @description: 从字符串获取WiFi信息
 * @param  {*}
 * @return {*}
 * @param {char} *buff
 * @param {Wifi_Info_t} *
 * @param {int} infoSize
 */
static int GetWifiInfoFromStr(struct wifi_network_scan_info *scan_info, int wifiSize, struct Wifi_Info_t ***wifiInfo, int infoSize)
{
    CrLogI("get scan wifi num = %d", wifiSize);
    if (wifiSize <= 0) return -1;

    // 申请空间储存wifi信息
    struct Wifi_Info_t **filterList = (struct Wifi_Info_t **)malloc(sizeof(struct Wifi_Info_t *) * wifiSize);
    if (filterList == NULL)
    {
        CrLogE("no memory to allocate\n");
        *wifiInfo = NULL;
        return 0;
    }

    for(int i = 0; i < wifiSize; i++)
    {
        filterList[i] = (struct Wifi_Info_t *)malloc(sizeof(struct Wifi_Info_t));
        if (filterList[i] == NULL)
        {
            CrLogE("no memory to allocate\n");
            continue;
        }
        memset(filterList[i], 0, sizeof(struct Wifi_Info_t));
        filterList[i]->infoSize = infoSize;

        filterList[i]->single[WIFI_INFO_TYPE_BSSID].strLen = strlen(scan_info[i].bssid) + 1;
        filterList[i]->single[WIFI_INFO_TYPE_BSSID].str = (char *)malloc(filterList[i]->single[WIFI_INFO_TYPE_BSSID].strLen);
        memset(filterList[i]->single[WIFI_INFO_TYPE_BSSID].str, 0, filterList[i]->single[WIFI_INFO_TYPE_BSSID].strLen);
        memcpy(filterList[i]->single[WIFI_INFO_TYPE_BSSID].str, scan_info[i].bssid, strlen(scan_info[i].bssid));

        filterList[i]->single[WIFI_INFO_TYPE_FREQUER].strLen = 10;
        filterList[i]->single[WIFI_INFO_TYPE_FREQUER].str = (char *)malloc(filterList[i]->single[WIFI_INFO_TYPE_FREQUER].strLen + 1);
        memset(filterList[i]->single[WIFI_INFO_TYPE_FREQUER].str, 0, filterList[i]->single[WIFI_INFO_TYPE_FREQUER].strLen + 1);
        snprintf(filterList[i]->single[WIFI_INFO_TYPE_FREQUER].str, filterList[i]->single[WIFI_INFO_TYPE_FREQUER].strLen, "%d", scan_info[i].freq);

        filterList[i]->single[WIFI_INFO_TYPE_SIGNAL].strLen = 10;
        filterList[i]->single[WIFI_INFO_TYPE_SIGNAL].str = (char *)malloc(filterList[i]->single[WIFI_INFO_TYPE_SIGNAL].strLen + 1);
        memset(filterList[i]->single[WIFI_INFO_TYPE_SIGNAL].str, 0, filterList[i]->single[WIFI_INFO_TYPE_SIGNAL].strLen + 1);
        snprintf(filterList[i]->single[WIFI_INFO_TYPE_SIGNAL].str, filterList[i]->single[WIFI_INFO_TYPE_SIGNAL].strLen, "-%d", scan_info[i].signal_strength);

        filterList[i]->single[WIFI_INFO_TYPE_FLAGS].strLen = strlen(scan_info[i].cipher_mode) + 1;
        filterList[i]->single[WIFI_INFO_TYPE_FLAGS].str = (char *)malloc(filterList[i]->single[WIFI_INFO_TYPE_FLAGS].strLen);
        memset(filterList[i]->single[WIFI_INFO_TYPE_FLAGS].str, 0, filterList[i]->single[WIFI_INFO_TYPE_FLAGS].strLen);
        memcpy(filterList[i]->single[WIFI_INFO_TYPE_FLAGS].str, scan_info[i].cipher_mode, strlen(scan_info[i].cipher_mode));

        filterList[i]->single[WIFI_INFO_TYPE_SSID].strLen = strlen(scan_info[i].ssid) + 1;
        filterList[i]->single[WIFI_INFO_TYPE_SSID].str = (char *)malloc(filterList[i]->single[WIFI_INFO_TYPE_SSID].strLen);
        memset(filterList[i]->single[WIFI_INFO_TYPE_SSID].str, 0, filterList[i]->single[WIFI_INFO_TYPE_SSID].strLen);
        memcpy(filterList[i]->single[WIFI_INFO_TYPE_SSID].str, scan_info[i].ssid, strlen(scan_info[i].ssid));
    }

    *wifiInfo = filterList;
    return wifiSize;
}

/**
 * @description: 标记保存密码的热点
 * @param  {*}
 * @return {*}
 * @param {Wifi_Manager_t} *wifiInfo
 */
static int MarkHotspotsSavingPasswords(struct Wifi_Manager_t *wifiInfo)
{
    CrLogI("Mark hotspots for saving passwords");

    // 查询保存密码的热点
    struct wifi_network_list_info network_info[MAX_SCAN_COUNT];
    memset(network_info, 0, sizeof(network_info));
    int ret = wifi_list_network(network_info, MAX_SCAN_COUNT);
    if (ret < 0) {
        CrLogW("wifi_shell: get wifi list network fail\n");
    }

    // 标记热点是否保存密码
    for (int i = 0; i < wifiInfo->wifiNum; i++)
    {
        bool savePassFlag = false;
        for (int j = 0; j < ret; j++)
        {
            if (strcmp(wifiInfo->info[i]->single[WIFI_INFO_TYPE_SSID].str, network_info[j].ssid) == 0)
            {
                if (strstr(network_info[j].flags, "CURRENT"))
                    wifiInfo->info[i]->wifiUsage = WIFI_USE_STATE_IS_USING;
                else
                    wifiInfo->info[i]->wifiUsage = WIFI_USE_STATE_USED;

                savePassFlag = true;
                break;
            }
        }
        if (savePassFlag == false) wifiInfo->info[i]->wifiUsage = WIFI_USE_STATE_UNUSED;
    }

    // 申请空间储存wifi信息
    int count = 0;
    struct Wifi_Info_t **confirmList = (struct Wifi_Info_t **)malloc(sizeof(struct Wifi_Info_t *) * wifiInfo->wifiNum);
    if (confirmList == NULL)
    {
        CrLogE("no memory to allocate\n");
        free(wifiInfo->info);
        wifiInfo->info = NULL;
        wifiInfo->wifiNum = 0;
        return 0;
    }

    // 重新排序
    for (int i = 0; i < wifiInfo->wifiNum; i++)
    {
        if (wifiInfo->info[i]->wifiUsage == WIFI_USE_STATE_IS_USING) {
            confirmList[count++] = wifiInfo->info[i];
            break;
        }
    }
    for (int i = 0; i < wifiInfo->wifiNum; i++)
    {
        if (wifiInfo->info[i]->wifiUsage == WIFI_USE_STATE_USED)
            confirmList[count++] = wifiInfo->info[i];
    }
    for (int i = 0; i < wifiInfo->wifiNum; i++)
    {
        if ((wifiInfo->info[i]->wifiUsage != WIFI_USE_STATE_IS_USING) && (wifiInfo->info[i]->wifiUsage != WIFI_USE_STATE_USED))
            confirmList[count++] = wifiInfo->info[i];
    }
    free(wifiInfo->info);
    CrLogI("Done using status flag");

    // 保存筛选后的数据
    wifiInfo->info = confirmList;
    wifiInfo->wifiNum = count;
    return count;
}

/**
 * @description: 从扫描热点返回结果中，整理获取热点信息
 * @param  {*}
 * @return {*}
 * @param {char} *buff
 * @param {Wifi_Manager_t} *wifiInfo
 */
static int GetWifiInfoFromScanResult(struct wifi_network_scan_info *scan_info, int wifisize, struct Wifi_Manager_t *wifiInfo)
{
    // 获取WiFi信息
    struct Wifi_Info_t **info = NULL;
    int wifi_size = GetWifiInfoFromStr(scan_info, wifisize, &info, WIFI_INFO_TYPE_SIZE);
    if (wifi_size > 0)
    {
        wifiInfo->wifiNum = wifi_size;
        wifiInfo->info = info;
        // 筛选SSID是否相同或者为空
        FilterSSIDSameOrEmpty(wifiInfo);
        // 按照信号强度排序
        WifiSignalStrengthSorting(wifiInfo);
        // 判断热点是否有保存密码或正在连接
        MarkHotspotsSavingPasswords(wifiInfo);
        return wifiInfo->wifiNum;
    }
    else
    {
        CrLogW("There are no hotspots scanned in the current environment");
        wifiInfo->wifiNum = 0;
        wifiInfo->info = NULL;
        return wifiInfo->wifiNum;
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {WifiConnectRes_t} res
 */
static void WifiConnectResponse(WifiConnectRes_t res)
{
    // 判断当前是否手动连接wifi
    if (res == WIFI_CONNECT_ING || lastConnectRes == WIFI_CONNECT_ING)
    {
        CrLogI("wifi connect response; last = %d, cur = %d", lastConnectRes, res);
        GeneralRes ret = GENERAL_RES__INIT;
        ret.result = res;

        GET_MESSAGE_BUFF(buff);
        size_t len = general_res__pack(&ret, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_SERVER, SERVER_CMD_WIFI_CONNECT_NETWORK_ANS, buff, len);
        SendProcessMsgBuff(&send, size);
    }
    lastConnectRes = res;
}

/**
 * @description: 
 * @return {*}
 */
static void networkNotFoundCb(void)
{
    CrLogW("not found network\n");
    WifiConnectResponse(WIFI_CONNECT_NO_SSID);
}

/**
 * @description: 
 * @return {*}
 */
static void networkWrongKeyCb(void)
{
    CrLogW("network key wrong\n");
    WifiConnectResponse(WIFI_CONNECT_WRONG_PASSWORD);
}

/**
 * @description: 
 * @return {*}
 */
static void networkTimeoutCb(void)
{
    CrLogW("network timeout\n");
    WifiConnectResponse(WIFI_CONNECT_TIME_OUT);
}

/**
 * @description: 
 * @return {*}
 * @param {enum wifi_server_state} state
 */
static void networkServerChangedCb(enum wifi_server_state state)
{
    CrLogI("wifi server state = %d", state);
    if (state == SERVER_CONNECT)
    {
        CrLogI("network server open\n");
        networkConnectState = NetworkIsOk();
    }
    else if (state == SERVER_DISCONNECT)
    {
        CrLogW("network server close\n");
        wifiConnectState = WIFI_DISCONNECTED;
        networkConnectState = -1;
    }

    wifiServerState = state;
    UpdataDeviceWifiInfo();
}

/**
 * @description: 
 * @return {*}
 * @param {enum wifi_connect_state} state
 */
static void networkStateChangedCb(enum wifi_connect_state state)
{
    CrLogI("wifi connect state = %d", state);
    if (state == WIFI_CONNECTED)
    {
        CrLogI("connect success!\n");
        networkConnectState = NetworkIsOk();
        WifiConnectResponse(WIFI_CONNECT_SUCCESS);
    }
    else if (state == WIFI_DISCONNECTED)
    {
        CrLogW("connect fail\n");
        networkConnectState = -1;
    }
    else if (state == WIFI_CONNECTING)
    {
        CrLogW("connecting\n");
        networkConnectState = -1;
    }

    wifiConnectState = state;
    UpdataDeviceWifiInfo();
}

/**
 * @description: 
 * @return {*}
 */
static wifi_event_callback networkCallback = {
    networkNotFoundCb,
    networkWrongKeyCb,
    networkTimeoutCb,
    networkServerChangedCb,
    networkStateChangedCb,
};

/**
 * @description: 周期性查询wifi状态
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
static int CycleCheckWifiState(void)
{
    // 是否连接互联网
    if (wifiServerState == SERVER_CONNECT && wifiConnectState == WIFI_CONNECTED) 
    {
        int networkState = NetworkIsOk();
        if (networkState != networkConnectState)
            UpdataDeviceWifiInfo(); // 更新设备WiFi信息
        networkConnectState = networkState;
    }

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
    CrLogI("Check Wifi State Thread init");
    wifi_register_event_callback(&networkCallback);
    wifiServerState = wifi_check_network_server_state();
    if (wifiServerState == SERVER_DISCONNECT) UserSetOpenWifiDaemon();

    while (1)
    {
        CycleCheckWifiState();
        sleep(NETWORK_STATE_CHECK_TIME);
    }

    return NULL;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int ExceptionHandleFreeScanNetworksInfo(void)
{
    FreeScanNetworksInfo(&getWifiManagerInfo);
    return 0;
}



/**
 * @description: 扫描热点
 * @param  {*}
 * @return {*}
 */
int UserScanWifiList(void)
{
    struct wifi_network_scan_info scan_info[MAX_SCAN_COUNT];
    memset(scan_info, 0, sizeof(scan_info));
    int ret = wifi_get_scan_info(scan_info, MAX_SCAN_COUNT);
    if (ret < 0) {
        CrLogW("wifi_shell: scan wifi fail\n");
        return ret;
    }
    CrLogI("wifi_get_scan_info = %d", ret);

    // 整理扫描结果
    FreeScanNetworksInfo(&getWifiManagerInfo);
    GetWifiInfoFromScanResult(scan_info, ret, &getWifiManagerInfo);
    CrLogI("Generate a list of hotspots that can be used, network size = %d", getWifiManagerInfo.wifiNum);

    // 扫描结果
    WifiInfo *infoList[getWifiManagerInfo.wifiNum];
    CrLogI("num / usage / frequency / signal / ssid / bssid");
    for (int i = 0; i < getWifiManagerInfo.wifiNum; i++)
    {
        CrLogI("[%d]\t%d\t%s\t%s\t%s\t%s", i+1, getWifiManagerInfo.info[i]->wifiUsage,
            getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_FREQUER].str,
            getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_SIGNAL].str,
            getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_SSID].str,
            getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_BSSID].str);

        infoList[i] = malloc(sizeof(WifiInfo));
        if (infoList[i] == NULL)
        {
            CrLogE("no memory to allocate\n");
            continue;
        }
        wifi_info__init(infoList[i]);

        infoList[i]->has_bssid = 1;
        infoList[i]->bssid.data = getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_BSSID].str;
        infoList[i]->bssid.len = getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_BSSID].strLen;
        infoList[i]->has_frequer = 1;
        infoList[i]->frequer.data = getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_FREQUER].str;
        infoList[i]->frequer.len = getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_FREQUER].strLen;
        infoList[i]->has_signal = 1;
        infoList[i]->signal.data = getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_SIGNAL].str;
        infoList[i]->signal.len = getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_SIGNAL].strLen;
        infoList[i]->has_flags = 1;
        infoList[i]->flags.data = getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_FLAGS].str;
        infoList[i]->flags.len = getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_FLAGS].strLen;
        infoList[i]->has_ssid = 1;
        infoList[i]->ssid.data = getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_SSID].str;
        infoList[i]->ssid.len = getWifiManagerInfo.info[i]->single[WIFI_INFO_TYPE_SSID].strLen;
        infoList[i]->has_wifiusage = 1;
        infoList[i]->wifiusage = getWifiManagerInfo.info[i]->wifiUsage;
        // 创建wifi加密标志
        infoList[i]->has_encrypt = 1;
        if (memcmp(infoList[i]->flags.data, "[ESS]", strlen("[ESS]")) == 0)infoList[i]->encrypt = 0;
        else infoList[i]->encrypt = 1;
    }
    CrLogI("=====================================================\n");

    // 发送
    NetworksInfo info = NETWORKS_INFO__INIT;
    info.n_list = getWifiManagerInfo.wifiNum;
    info.list = infoList;

    GET_MESSAGE_BUFF(buff);
    size_t len = networks_info__pack(&info, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_SERVER, SERVER_CMD_WIFI_SCAN_NETWORK_LIST_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    // 释放内存资源
    for (int i = 0; i < getWifiManagerInfo.wifiNum; i++) {
        if (infoList[i]) free (infoList[i]);
    }
    return 0;
}

/**
 * @description: 连接网络热点
 * @param  {*}
 * @return {*}
 * @param {char} *name_str
 * @param {char} *pass_str
 */
int UserConnectNetworks(const char *name_str, const char *pass_str)
{
    CrLogI("==============================================");
    CrLogI("connecting ssid:%s passward:%s", name_str, pass_str);

    WifiConnectResponse(WIFI_CONNECT_ING);
    int res = wifi_connect_network(name_str, pass_str, NULL);
    if(res < 0) {
        CrLogW("connected ap failed; res = %d\n", res);
        WifiConnectResponse(WIFI_CONNECT_FAIL);
    }
    CrLogI("==============================================\n");

    return res;
}

/**
 * @description: 连接已保存wifi热点
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
int UserConnectSavedNetworks(char *name)
{
    CrLogI("Reconnect to new hotspot ssid--%s", name);

    struct wifi_network_list_info network_info[MAX_SCAN_COUNT];
    memset(network_info, 0, sizeof(network_info));
    int res = wifi_list_network(network_info, MAX_SCAN_COUNT);
    if (res < 0) {
        CrLogW("wifi_shell: get wifi list network fail\n");
    }

    // 查找wifi ssid对应的network_id
    int i = 0;
    for (i = 0; i < res; i++) {
        if (!strcmp(name, network_info[i].ssid))
            break;
    }

    // 重连
    WifiConnectResponse(WIFI_CONNECT_ING);
    char getNetworkId[10] = {0};
    snprintf(getNetworkId, 10, "%d", network_info[i].network_id);
    res = wifi_reconnect(getNetworkId);
    if (res < 0) {
        CrLogW("wifi_shell: reconnect wifi fail\n");
        WifiConnectResponse(WIFI_CONNECT_FAIL);
    }

    return 0;
}

/**
 * @description: 用户获取设备WiFi信息
 * @param  {*}
 * @return {*}
 */
int UserGetDeviceWifiInfo(void)
{
    CrLogI("User Get Device Wifi Info");
    UpdataDeviceWifiInfo();
    return 0;
}

/**
 * @description: 断开连接
 * @param  {*}
 * @return {*}
 */
int UserDisconnectNetworks(void)
{
    CrLogI("User actively disconnected");
    GeneralRes ret = GENERAL_RES__INIT;

    int res = wifi_disconnect_current_network();
    if (res < 0)
    {
        CrLogW("removeing wifi fail\n");
        ret.result = 0;
    }
    else ret.result = 1;

    // 应答
    GET_MESSAGE_BUFF(buff);
    size_t len = general_res__pack(&ret, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_SERVER, SERVER_CMD_WIFI_DISCONNECT_NETWORK_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    return res;
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
    CrLogI("removing wifi ssid: %s", name);
    GeneralRes ret = GENERAL_RES__INIT;

    struct wifi_network_list_info network_info[MAX_SCAN_COUNT];
    memset(network_info, 0, sizeof(network_info));
    int res = wifi_remove_net(network_info, MAX_SCAN_COUNT, name);
    if (res < 0)
    {
        CrLogW("removeing wifi fail\n");
        ret.result = 0;
    }
    else ret.result = 1;

    // 应答
    GET_MESSAGE_BUFF(buff);
    size_t len = general_res__pack(&ret, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_SERVER, SERVER_CMD_WIFI_REMOVE_NETWORK_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    return res;
}

/**
 * @description: 启动wifi守护进程，打开WiFi
 * @param  {*}
 * @return {*}
 */
int UserSetOpenWifiDaemon(void)
{
    CrLogI("start network server......");
    wifi_start_network_server(WIFI_INFO_PATH_INGENIC);
    return 0;
}

/**
 * @description: 关闭wifi守护进程，关闭wifi
 * @param  {*}
 * @return {*}
 */
int UserSetCloseWifiDeamon(void)
{
    CrLogI("stop network server......");
    wifi_stop_network_server();
    return 0;
}
