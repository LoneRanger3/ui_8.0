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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "Base/WifiMsgBase.h"
#include "ServerMessage.h"
#include "wifiServerWpa.h"
#define __WMG_DEBUG_H
#include "wifid_cmd.h"

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
static struct wifi_status lastWifiStatus = {
    .state = STATE_UNKNOWN,
    .ssid = {'\0'},
};
static struct Wifi_Manager_t getWifiManagerInfo = {
    .info = NULL,
};
static int lastNetworkState = -1;
static int NetworkDetectCount = 0;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
/**
 * @description: 获取当前wifi连接状态
 * @param  {*}
 * @return {*}
 * @param {wifi_status} *getStatus
 */
static int UserGetCurrentWifiConnectStatus(struct wifi_status *getStatus)
{
    int ret = aw_wifid_get_status(getStatus);
    if (ret < 0)
    {
        CrLogW("Get Current Wifi Connect Status fail\n");
    }
    return ret;
}

/**
 * @description: 获取网络热点连接信息
 * @param  {*}
 * @return {*}
 * @param {struct connection_status} *info
 */
static int UserGetCurrentConnectInfo(struct connection_status *info)
{
    CrLogI("User Get Current Connect Info");
    int res = aw_wifid_get_connect_info(info);
    if (res < 0)
    {
        CrLogW("Get Current Connect Info fail\n");
    }
    return res;
}

/**
 * @description: 更新设备WiFi信息
 * @param  {*}
 * @return {*}
 * @param {struct wifi_status} *getStatus
 * @param {struct connection_status} *info
 */
static void UpdataDeviceWifiInfo(struct wifi_status getStatus, struct connection_status info, int Network)
{
    CrLogI("wifi state, state: %d, ssid = [%s], network: %d", getStatus.state, getStatus.ssid, Network);
    CrLogI("wifi change, get connect ip = %s", info.ip_address);

    uint8_t networkState = getStatus.state;
    if (networkState == NETWORK_CONNECTED && Network == 0)
        networkState = 10;
    CrLogI("Merged status of wifi and network: %d\n", networkState);

    NetworksInfo updata = NETWORKS_INFO__INIT;
    updata.has_status = 1;
    updata.status = networkState;
    updata.has_ip = 1;
    updata.ip.data = info.ip_address;
    updata.ip.len = sizeof(info.ip_address);
    updata.has_ssid = 1;
    updata.ssid.data = getStatus.ssid;
    updata.ssid.len = sizeof(getStatus.ssid);

    // 应答
    GET_MESSAGE_BUFF(buff);
    size_t len = networks_info__pack(&updata, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_SERVER, SERVER_CMD_WIFI_GET_DEVICE_WIFI_INFO_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
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
    enum cn_event event = DA_UNKNOWN;
    CrLogI("==============================================");
    CrLogI("connecting ssid:%s passward:%s", name_str, pass_str);

    GeneralRes ret = GENERAL_RES__INIT;
    int res = aw_wifid_connect_ap(name_str, pass_str, &event);
    if((event == DA_CONNECTED) && (res >= 0))
    {
        CrLogI("connected ap successful");
        ret.result = 1;
    }else
    {
        CrLogW("connected ap failed: %s; res = %d\n", connect_event_txt(event), res);
        ret.result = 0;
    }
    CrLogI("==============================================");

    // 应答
    GET_MESSAGE_BUFF(buff);
    size_t len = general_res__pack(&ret, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WIFI_SERVER, SERVER_CMD_WIFI_CONNECT_NETWORK_ANS, buff, len);
    SendProcessMsgBuff(&send, size);

    return res;
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

    int res = aw_wifid_disconnect_ap();
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

    int res = aw_wifid_remove_networks(name, nameLen);
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
 * @description: 用户获取设备WiFi信息
 * @param  {*}
 * @return {*}
 */
int UserGetDeviceWifiInfo(void)
{
    CrLogI("User Get Device Wifi Info");
    int NetworkState = -1;
    struct wifi_status getStatus;
    struct connection_status info;
    memset(&getStatus, 0, sizeof(struct wifi_status));
    memset(&info, 0, sizeof(struct connection_status));

    int ret = UserGetCurrentWifiConnectStatus(&getStatus);
    if ((ret >= 0) && (getStatus.state == NETWORK_CONNECTED))
    {
        UserGetCurrentConnectInfo(&info);
        NetworkState = NetworkIsOk();
    }
    UpdataDeviceWifiInfo(getStatus, info, NetworkState);
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
    CrLogI("User Get Save Networks List");
    int ret = aw_wifid_list_networks(result, len);
    if(ret < 0)
    {
        CrLogW("Get Save Networks List faile! list networks results:\n%s\n", result);
    }
}

/**
 * @description: 启动wifi守护进程，打开WiFi
 * @param  {*}
 * @return {*}
 */
int UserSetOpenWifiDaemon(void)
{
    CrLogI("opening wifi daemon......");
    aw_wifid_open();
}

/**
 * @description: 关闭wifi守护进程，关闭wifi
 * @param  {*}
 * @return {*}
 */
int UserSetCloseWifiDeamon(void)
{
    CrLogI("closing wifi daemon......");
    aw_wifid_close();
}

/**
 * @description: 获取已保存WiFi密码
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
static void GetWiFiPassConnected(char **pass, char *name, char *save)
{
    char *source = save;
    char *find = NULL;
    while (1)
    {
        source = strstr(source, "network");
        if(source != NULL)
        {
            source = strstr(source, "ssid=\"");
            source = source + strlen("ssid=\"");
            find = strstr(source, "\"");

            int ssid_len = find - source;
            char wifi_ssid[ssid_len + 1];
            memcpy(wifi_ssid, source, ssid_len);
            wifi_ssid[ssid_len] = '\0';

            if (strcmp(name, wifi_ssid) == 0)
            {
                CrLogI("Get the password of %s", wifi_ssid);

                source = strstr(source, "psk=\"");
                source = source + strlen("psk=\"");
                find = strstr(source, "\"");

                int pass_len = find - source;
                char pass_ssid[pass_len + 1];
                memcpy(pass_ssid, source, pass_len);
                pass_ssid[pass_len] = '\0';
                CrLogI("The password obtained is = %s", pass_ssid);

                memcpy(pass, pass_ssid, pass_len);
                break;
            }
        }
        else break;
    }
}

/**
 * @description: 连接已保存wifi热点
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
int UserConnectSavedNetworks(char *name)
{
    // 获取设备保存的WiFi信息
    char saveResults[4*1024] = {0,};
    GetConfigFromFile(WIFI_CONNECT_INFO_PATH, saveResults, sizeof(saveResults));
    char password[100] = {0,};
    GetWiFiPassConnected((char **)&password, name, saveResults);

    CrLogI("Reconnect to new hotspot ssid--%s, pass--%s", name, password);
    UserConnectNetworks(name, password);
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
}

/**
 * @description: 从字符串获取WiFi信息
 * @param  {*}
 * @return {*}
 * @param {char} *buff
 * @param {Wifi_Info_t} *
 * @param {int} infoSize
 */
static int GetWifiInfoFromStr(char *buff, struct Wifi_Info_t ***wifiInfo, int infoSize)
{
    int wifiSize = 0;
    char *pRecv = NULL;
    char *pSource = NULL;

    // 去除信息头部字符串
    if (buff == NULL || strlen(buff) == 0) return -1;
    pRecv = strchr(buff, '\n') + 1;
    CrLogI("get scan wifi info str valid len %d", strlen(pRecv));

    // 计算热点数量
    pSource = pRecv;
    char logStr[256] = {0};
    char *tar = NULL;
    while (1)
    {
        tar = strchr(pSource, '\n');
        if (tar == NULL)
        {
            CrLogD("%s\n", pSource);
            wifiSize++;
            break;
        }
        memset(logStr, 0, 256);
        memcpy(logStr, pSource, tar-pSource);
        CrLogD("%s", logStr);
        pSource = tar + 1;
        wifiSize++;
    }
    CrLogI("get scan wifi num = %d", wifiSize);
    if (wifiSize <= 0) return -1;

    // 定义空间,提取热点信息
    struct Wifi_Info_t list[wifiSize];
    char *p_t = NULL, *p_n = NULL;
    pSource = pRecv;
    for (int i = 0; i < wifiSize; i++)
    {
        p_n = strchr(pSource, '\n');
        for (int j = 0; j < infoSize; j++)
        {
            p_t = strchr(pSource, '\t');
            if (p_n == NULL)
            {
                if (p_t == NULL)
                {
                    list[i].single[j].str = pSource;
                    list[i].single[j].strLen = strlen(pSource);
                    break;
                }
                else
                {
                    list[i].single[j].str = pSource;
                    list[i].single[j].strLen = p_t - pSource;
                    pSource = p_t + 1;
                }
            }
            else
            {
                if (p_t < p_n)
                {
                    list[i].single[j].str = pSource;
                    list[i].single[j].strLen = p_t - pSource;
                    pSource = p_t + 1; 
                }
                else 
                {
                    list[i].single[j].str = pSource;
                    list[i].single[j].strLen = p_n - pSource;
                    break;
                }
            }
        }
        pSource = p_n + 1;
    }
    CrLogI("Extract hotspot information to an array");

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
        for(int j = 0; j < infoSize; j++)
        {
            filterList[i]->single[j].strLen = list[i].single[j].strLen + 1;
            filterList[i]->single[j].str = (char *)malloc(filterList[i]->single[j].strLen);
            if (filterList[i]->single[j].str == NULL)
            {
                CrLogE("no memory to allocate\n");
                continue;
            }
            memset(filterList[i]->single[j].str, 0, filterList[i]->single[j].strLen);
            memcpy(filterList[i]->single[j].str, list[i].single[j].str, list[i].single[j].strLen);
        }
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
    char listNetResults[LIST_NETWORK_MAX];
    int ret = UserGetSaveNetworksList(listNetResults, LIST_NETWORK_MAX);
    if(ret == -1)
    {
        CrLogW("list networks results:\n%s", listNetResults);
    }

    // 将字符串转换成结构数据
    struct Wifi_Info_t **info = NULL;
    int wifiSize = GetWifiInfoFromStr(listNetResults, &info, WIFI_INFO_USE_SIZE);
    if (wifiSize == -1)
    {
        CrLogW("list networks results fail");
        return -1;
    }

    // 标记热点是否保存密码
    for (int i = 0; i < wifiInfo->wifiNum; i++)
    {
        bool savePassFlag = false;
        for (int j = 0; j < wifiSize; j++)
        {
            if (strcmp(wifiInfo->info[i]->single[WIFI_INFO_TYPE_SSID].str, info[j]->single[WIFI_INFO_USE_SSID].str) == 0)
            {
                if (info[j]->single[WIFI_INFO_USE_FLAGS].strLen == 0)
                {
                    wifiInfo->info[i]->wifiUsage = WIFI_USE_STATE_USED;
                }
                else
                {
                    wifiInfo->info[i]->wifiUsage = WIFI_USE_STATE_IS_USING;
                }
                savePassFlag = true;
                break;
            }
        }
        if (savePassFlag == false)
        {
            wifiInfo->info[i]->wifiUsage = WIFI_USE_STATE_UNUSED;
        }
    }
    struct Wifi_Manager_t temp;
    temp.wifiNum = wifiSize;
    temp.info = info;
    FreeScanNetworksInfo(&temp);

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

    for (int i = 0; i < wifiInfo->wifiNum; i++)
    {
        if (wifiInfo->info[i]->wifiUsage == WIFI_USE_STATE_IS_USING)
        {
            confirmList[count++] = wifiInfo->info[i];
            break;
        }
    }
    for (int i = 0; i < wifiInfo->wifiNum; i++)
    {
        if (wifiInfo->info[i]->wifiUsage == WIFI_USE_STATE_USED)
        {
            confirmList[count++] = wifiInfo->info[i];
        }
    }
    for (int i = 0; i < wifiInfo->wifiNum; i++)
    {
        if ((wifiInfo->info[i]->wifiUsage != WIFI_USE_STATE_IS_USING) && (wifiInfo->info[i]->wifiUsage != WIFI_USE_STATE_USED))
        {
            confirmList[count++] = wifiInfo->info[i];
        }
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
static int GetWifiInfoFromScanResult(char *buff, struct Wifi_Manager_t *wifiInfo)
{
    // 获取WiFi信息
    struct Wifi_Info_t **info = NULL;
    int wifi_size = GetWifiInfoFromStr(buff, &info, WIFI_INFO_TYPE_SIZE);
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
}

/**
 * @description: 扫描热点
 * @param  {*}
 * @return {*}
 */
int UserScanWifiList(void)
{
    char scanResults[SCAN_MAX] = {0};
    int ret = aw_wifid_get_scan_results(scanResults, SCAN_MAX);
    if(ret == -1)
    {
        CrLogW("scan wifi error!");
        return -1;
    }
    FreeScanNetworksInfo(&getWifiManagerInfo);
    GetWifiInfoFromScanResult(scanResults, &getWifiManagerInfo);
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
    for (int i = 0; i < getWifiManagerInfo.wifiNum; i++)
        free (infoList[i]);
    return 0;
}

/**
 * @description: 周期性查询wifi状态
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
static int CycleCheckWifiState(void)
{
    int NetworkState = lastNetworkState;
    struct wifi_status getStatus;
    struct connection_status info;
    memset(&getStatus, 0, sizeof(struct wifi_status));
    memset(&info, 0, sizeof(struct connection_status));

    // 获取WiFi连接状态
    int ret = UserGetCurrentWifiConnectStatus(&getStatus);
    if (ret >= 0)
    {
        // 获取网络连通状态，是否也连接互联网
        if (lastWifiStatus.state == NETWORK_CONNECTED)
        {
            NetworkDetectCount++;
            if (lastNetworkState != 0 || NetworkDetectCount > NETWORK_STATE_CHECK_TIME)
            {
                NetworkDetectCount = 0;
                NetworkState = NetworkIsOk();
            }
        }
        else NetworkDetectCount = 0;

        // 判断wifi状态、网络状态是否发生改变
        if ((getStatus.state != lastWifiStatus.state) || 
            (strcmp(lastWifiStatus.ssid, getStatus.ssid) != 0) ||
            (NetworkState != lastNetworkState))
        {
            // NETWORK_CONNECTED = 0x01,
            // CONNECTING,
            // OBTAINING_IP,
            // DISCONNECTED,
            // CONNECTED,
            // STATE_UNKNOWN,
            if (getStatus.state == NETWORK_CONNECTED)
            {
                UserGetCurrentConnectInfo(&info);
                NetworkState = NetworkIsOk();
                CrLogI("wifi status change !!!\n");
            }
            else  CrLogI("WiFi not connected, status = %d", getStatus.state);
            
            // 更新设备WiFi信息
            UpdataDeviceWifiInfo(getStatus, info, NetworkState);
            memcpy(&lastWifiStatus, &getStatus, sizeof(struct wifi_status));
            lastNetworkState = NetworkState;
        }  
    }
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
    while (1)
    {
        CycleCheckWifiState();
        sleep(WIFI_STATE_CHECK_TIME);
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int ExceptionHandleFreeScanNetworksInfo(void)
{
    FreeScanNetworksInfo(&getWifiManagerInfo);
}
