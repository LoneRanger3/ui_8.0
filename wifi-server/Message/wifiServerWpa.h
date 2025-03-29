/*
 * @Description : ServerMessage.h
 * @Author      : Yufeng Zhang
 * @Date: 2022-03-14 17:21:15
 * @LastEditTime: 2023-06-09 17:51:24
 */
#ifndef __WIFI_SERVER_WAP_H__
#define __WIFI_SERVER_WAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>

/*********************
 *      DEFINES
 *********************/
#define WIFI_CONNECT_INFO_PATH      "/etc/wifi/wpa_supplicant.conf"
#define WIFI_INFO_PATH_INGENIC      "/usr/data/wpa_supplicant.conf"
#define NETWORK_STATE_CHECK_TIME    20 // 网络连接检测周期

/**********************
 *      TYPEDEFS
 **********************/
enum Wifi_Info_Type{
    WIFI_INFO_TYPE_BSSID,
    WIFI_INFO_TYPE_FREQUER,
    WIFI_INFO_TYPE_SIGNAL,
    WIFI_INFO_TYPE_FLAGS,
    WIFI_INFO_TYPE_SSID,
    WIFI_INFO_TYPE_SIZE,
};

enum Wifi_Info_Use{
    WIFI_INFO_USE_NET_ID,
    WIFI_INFO_USE_SSID,
    WIFI_INFO_USE_BSSID,
    WIFI_INFO_USE_FLAGS,
    WIFI_INFO_USE_SIZE,
};

enum Wifi_Use_State{
    WIFI_USE_STATE_UNUSED,
    WIFI_USE_STATE_USED,
    WIFI_USE_STATE_IS_USING,
    WIFI_USE_STATE_SIZE,
};

struct Wifi_Str_t{
    char *str;
    unsigned char strLen;
};

struct Wifi_Info_t{
    int infoSize;
    struct Wifi_Str_t single[WIFI_INFO_TYPE_SIZE];
    enum Wifi_Use_State wifiUsage;
};

struct Wifi_Manager_t{
    unsigned long wifiNum;
    struct Wifi_Info_t **info;
};

/**********************
 * GLOBAL PROTOTYPES
 **********************/
int UserScanWifiList(void);
int UserConnectNetworks(const char *name_str, const char *pass_str);
int UserConnectSavedNetworks(char *name);
int UserGetDeviceWifiInfo(void);
int UserDisconnectNetworks(void);
int UserRemoveNetworks(char *name, int nameLen);

void *CheckWifiStateThread(void *arg);
int UserSetOpenWifiDaemon(void);
int UserSetCloseWifiDeamon(void);
int UserGetSaveNetworksList(char *result, int len);

int ExceptionHandleFreeScanNetworksInfo(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*__WIFI_SERVER_WAP_H__*/
