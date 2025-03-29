/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-05-06 22:16:45
 * @LastEditTime: 2023-10-16 12:01:19
 */

#ifndef __CXY_HTTP_SERVER_H__
#define __CXY_HTTP_SERVER_H__

#include <iostream>
#include <curl/curl.h>

#define		__CXY_BRAND_			"creality" // 一般是creality
#define		__CXY_PLATFORM_			"10" // 平台类型；0-IOS 1-安卓 2-PC_WEB 3-PC_ADMIN 4-WAP 5-打印机 6-切片软件 7-扫描仪 10-FDM一体机（新版）
#define		__CXY_APP_CH_           "creality" // 一般是creality，除非客户定制机
#define		__CXY_APP_ID_			"creality_model" // 创想云	creality_model

#define		DEVICE_TYPE				9 // 1-wifi盒子 2-蓝牙盒子 3-FDM打印机 4-光固化打印机 5-树莓派 6-激光雕刻机 7-智慧屏 8-音速屏幕 9-FDM快速打印机
#define     IOT_TYPE                2 // 1-aliyun  2-tb
#define     POST_SECRET             "Os5juJJERoUosWpbd2Q4QmkpNRNr"

// HTTP请求头语言
typedef enum {
    OS_LANG_EN,     // 英文	0
    OS_LANG_ZH,     // 简体中文	1
    OS_LANG_ZH_TW,  // 台湾繁体	2
    OS_LANG_ZH_HK,  // 香港繁体	3
    OS_LANG_RU,     // 俄罗斯语	4
    OS_LANG_KR,     // 韩语	5
    OS_LANG_XA,     // 阿拉伯语言	6
    OS_LANG_ES,     // 西班牙语	7
    OS_LANG_DE,     // 德语	8
    OS_LANG_FR,     // 法语	9
    OS_LANG_JP,     // 日语	10
    OS_LANG_PT,     // 葡萄牙语言	11
    OS_LANG_TH,     // 泰语	12
    OS_LANG_NL,     // 荷兰语	13
    OS_LANG_IT,     // 意大利语	14
    OS_LANG_PT_BR,  // 葡萄牙语-巴西	15
    OS_LANG_TR,     // 土耳其语	16
    OS_LANG_RO,     // 罗马尼亚语	17
    OS_LANG_HE,     // 希伯来语	18
// 波兰语	19	
// 印度尼西亚	20	
// 匈牙利	21	
} CxyHttpLang_t;

typedef struct {
    std::string sn;
    std::string mac;
    std::string model;
}RegisterInfo_t;

typedef struct {
    std::string sysVersion;
    std::string hwVersion;
}DeviceVersionInfo_t;

typedef struct {
    std::string token;
    std::string devName;
    std::string devId;
    std::string httpRes;
}DeviceTbInfo_t;

typedef struct {
    std::string mac;
    std::string videoId;
    std::string printId;
    std::string deviceName;
    std::string md5;
    bool manually;
    std::string name;
    uint64_t size;
}VideoAssociate_t;

typedef struct{
    std::string url;
    std::string vod;
    std::string endpoint;
    std::string bucket;
    std::string iot;
}CxyServer_t;

class CxyHttpServer
{
    public:
        CxyHttpServer();
        ~CxyHttpServer();
        int GetRegisterInfoFromFile(RegisterInfo_t *devInfo);
        int GetVersionInfoFromFile(DeviceVersionInfo_t *versionInfo);
        int GetTbInfoFromFile(DeviceTbInfo_t *tbInfo);
        int GetUserServiceInfoFromFile(std::string *userService);
        CxyServer_t GetCxyServer(int setting);
        int CxyHttpApiInit(std::string remoteUrl, std::string apiName);

        int GetConnectTbInfo(RegisterInfo_t devInfo, DeviceTbInfo_t *tbInfo);
        CURLcode HttpGetUpgradeInfo(char *subType, char *fwVersion, char *hwVersion, std::string *info, int otaType);
        CURLcode HttpGetTmplyAuthorityInfo(std::string token, std::string *info);
        CURLcode HttpGetPreSubmitTimelapse(std::string token,VideoAssociate_t para, std::string *info);
        CURLcode HttpAssociateVideoToPrintJob(std::string token, VideoAssociate_t para, std::string *info);
        CURLcode HttpCallRecordUploadLog2server(std::string token, std::string deviceName, char *logFileKey, std::string *info);
        CURLcode HttpGetOwnerInfo(char *token, std::string *info);
        CURLcode HttpReportAiNotice(char *token, std::string *info, char *printId);
        CURLcode HttpLocalPrint(char *token, std::string *info, char *workId, char *fileName, char *model);

    private:
        int HttpRegisterDevice(RegisterInfo_t devInfo, DeviceTbInfo_t *tbInfo);
        inline int ParseTbInfo(const char *contex, DeviceTbInfo_t *tbInfo);
        inline std::string GetRandString(void);
        inline std::string GetTbSignString(std::string macAddr, std::string requestId);
        inline std::string GetProductionSnString(void);
        static inline size_t StoreData(void *ptr, size_t size, size_t nmemb, void *data);
        CxyHttpLang_t NetworkLanguageConversion(LanguageType language);
        std::string GetHttpRequestHeadLanguage(void);
        struct curl_slist *CommonHttpHeaderFields(struct curl_slist *header, std::string randStr);

    private:
        std::string         m_httpRequestApi;
};

#endif
