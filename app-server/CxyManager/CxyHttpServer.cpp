/*
 * @Description : 创想云 HTTP 服务
 * @Author      : Yufeng Zhang
 * @Date: 2022-05-06 22:16:45
 * @LastEditTime: 2023-10-17 11:50:34
 */
#include <iostream>
#include <string>
#include <ctime>
#include <curl/curl.h>
#include <openssl/sha.h>

#include "Base/AppMsgBase.h"
#include "CxyHttpServer.h"

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
CxyHttpServer::CxyHttpServer()
{
    m_httpRequestApi = "";
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
CxyHttpServer::~CxyHttpServer() {}

/**
 * @description: 
 * @return {*}
 * @param {RegisterInfo_t} *devInfo
 */
int CxyHttpServer::GetRegisterInfoFromFile(RegisterInfo_t *devInfo)
{
    CrLogI("Get Register Info From File");
    #ifdef CROSS_COMPILE
    char buff[64] = {0};
    bzero(buff, sizeof(buff));
    if (PopenSystem(GetDefaultCertifiedSnScript(), buff, sizeof(buff))) {
        devInfo->sn = buff;
    }
    else CrLogW("get certified sn fail !!\n");

    bzero(buff, sizeof(buff));
    if (PopenSystem(GetDefaultCertifiedMacScript(), buff, sizeof(buff))) {
        devInfo->mac = buff;
    }
    else CrLogW("get certified mac fail !!\n");

    bzero(buff, sizeof(buff));
    if (PopenSystem(GetDefaultDeviceModelScript(), buff, sizeof(buff))) {
        devInfo->model = buff;
    }
    else CrLogW("get certified model fail !!\n");

    CrLogI("device sn = %s", devInfo->sn.c_str());
    CrLogI("device mac = %s", devInfo->mac.c_str());
    CrLogI("device model = %s", devInfo->model.c_str());
    return 0;
    
    #else
    json_object *iotConfig = json_object_from_file(GetUserSystemConfigFilePath());
    if (iotConfig)
    {
        const char *snStr = NULL, *macStr = NULL, *modelStr = NULL;
        json_object *devInfoObj = NULL, *snObj = NULL, *macObj = NULL, *modelObj = NULL;
        // 获取设备信息对象
        devInfoObj = json_object_object_get(iotConfig, "device_info");
        if (!devInfoObj)
        {
            goto GET_DEV_INFO_ERR;
        }
        // 获取device_sn、device_mac、model_str对象
        snObj = json_object_object_get(devInfoObj, "device_sn");
        macObj = json_object_object_get(devInfoObj, "device_mac");
        modelObj = json_object_object_get(devInfoObj, "model_str");
        if (!snObj || !macObj || !modelObj)
        {
            goto GET_DEV_INFO_ERR;
        }
        // 获取device_sn、device_mac、model_str值
        snStr = json_object_get_string(snObj);
        macStr = json_object_get_string(macObj);
        modelStr = json_object_get_string(modelObj);
        if (!snStr || !macStr || !modelStr || strlen(snStr) < 2 || strlen(macStr) < 2 || strlen(modelStr) < 2)
            goto GET_DEV_INFO_ERR;

        // 提取参数
        devInfo->sn = snStr;
        devInfo->mac = macStr;
        devInfo->model = modelStr;
        json_object_put(iotConfig);
        
        CrLogI("device sn = %s", devInfo->sn.c_str());
        CrLogI("device mac = %s", devInfo->mac.c_str());
        CrLogI("device model = %s\n", devInfo->model.c_str());
        return 0;
        
GET_DEV_INFO_ERR:
        json_object_put(iotConfig);
        devInfo->sn.clear();
        devInfo->mac.clear();
        devInfo->model.clear();
        CrLogW("get device register info fail !!\n");
        return -1;
    }
    else
    {
        CrLogE("User Iot Config file fail!\n");
        return -1;
    }
    #endif
}

/**
 * @description: 
 * @return {*}
 * @param {DeviceVersionInfo_t} *versionInfo
 */
int CxyHttpServer::GetVersionInfoFromFile(DeviceVersionInfo_t *versionInfo)
{
    CrLogI("Get Version Info From File");
    #ifdef CROSS_COMPILE
    char buff[64] = {0};
    bzero(buff, sizeof(buff));
    if (PopenSystem(GetDefaultGetSystemVersionPath(), buff, sizeof(buff))) {
        versionInfo->sysVersion = buff;
    }
    else CrLogW("get system version fail !!\n");

    bzero(buff, sizeof(buff));
    if (PopenSystem(GetDefaultOtaBoardNameScript(), buff, sizeof(buff))) {
        versionInfo->hwVersion = buff;
    }
    else CrLogW("get hardware version fail !!\n");

    CrLogI("system version = %s", versionInfo->sysVersion.c_str());
    CrLogI("hardware version = %s", versionInfo->hwVersion.c_str());
    return 0;
    
    #else
    json_object *versionConfig = json_object_from_file(GetUserSystemVersionFilePath());
    if (versionConfig)
    {
        const char *sysVersionStr = NULL, *hwVersionStr = NULL;
        json_object *sysVersionObj = NULL, *hwVersionObj = NULL;

        // 获取sys_version、hw_version对象
        sysVersionObj = json_object_object_get(versionConfig, "sys_version");
        hwVersionObj = json_object_object_get(versionConfig, "hw_version");
        if (!sysVersionObj || !hwVersionObj)
            goto GET_DEV_INFO_ERR;

        // 获取sys_version、hw_version值
        sysVersionStr = json_object_get_string(sysVersionObj);
        hwVersionStr = json_object_get_string(hwVersionObj);
        if (!sysVersionStr || !hwVersionStr || strlen(sysVersionStr) < 2 || strlen(hwVersionStr) < 2)
            goto GET_DEV_INFO_ERR;

        // 提取参数
        versionInfo->sysVersion = sysVersionStr;
        versionInfo->hwVersion = hwVersionStr;
        json_object_put(versionConfig);
        
        CrLogI("system version = %s", versionInfo->sysVersion.c_str());
        CrLogI("hardware version = %s\n", versionInfo->hwVersion.c_str());
        return 0;
        
GET_DEV_INFO_ERR:
        json_object_put(versionConfig);
        versionInfo->sysVersion.clear();
        versionInfo->hwVersion.clear();
        CrLogW("get device version info fail !!\n");
        return -1;
    }
    else {
        CrLogE("User version Config file fail!\n");
        return -1;
    }
    #endif
}

/**
 * @description: 
 * @return {*}
 * @param {DeviceTbInfo_t} *tbInfo
 */
int CxyHttpServer::GetTbInfoFromFile(DeviceTbInfo_t *tbInfo)
{
    CrLogI("Get tb Info From File");
    json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
    if (iotConfig)
    {
        const char *tokenStr = NULL, *nameStr = NULL, *idStr = NULL;
        json_object *tbInfoObj = NULL, *tokenObj = NULL, *nameObj = NULL, *idObj = NULL;

        // 获取tb信息对象
        tbInfoObj = json_object_object_get(iotConfig, "cxy_tb_info");
        if (!tbInfoObj)
        {
            goto GET_DEV_INFO_ERR;
        }
        // 获取tb_token、dev_name、dev_id对象
        tokenObj = json_object_object_get(tbInfoObj, "tb_token");
        nameObj = json_object_object_get(tbInfoObj, "dev_name");
        idObj = json_object_object_get(tbInfoObj, "dev_id");
        if (!tokenObj || !nameObj || !idObj)
        {
            goto GET_DEV_INFO_ERR;
        }
        // 获取tb_token、dev_name、dev_id值
        tokenStr = json_object_get_string(tokenObj);
        nameStr = json_object_get_string(nameObj);
        idStr = json_object_get_string(idObj);
        if (!tokenStr || !nameStr || !idStr || 
            strlen(tokenStr) < 2 || strlen(nameStr) < 2 || strlen(idStr) < 2)
            goto GET_DEV_INFO_ERR;

        // 提取参数
        tbInfo->token = tokenStr;
        tbInfo->devName = nameStr;
        tbInfo->devId = idStr;
        json_object_put(iotConfig);
        
        CrLogI("device token = %s", AppAesEncryptToBase64(tbInfo->token).c_str());
        CrLogI("device name = %s", tbInfo->devName.c_str());
        CrLogI("device id = %s", tbInfo->devId.c_str());
        return 0;
        
GET_DEV_INFO_ERR:
        json_object_put(iotConfig);
        tbInfo->token.clear();
        tbInfo->devName.clear();
        tbInfo->devId.clear();
        CrLogW("get device register info fail !!\n");
        return -1;
    }
    else
    {
        CrLogE("User Iot Config file fail!\n");
        return -1;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {string} userService
 */
int CxyHttpServer::GetUserServiceInfoFromFile(std::string *userService)
{
    CrLogI("Get User Service Info");
    json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotConfigPath()).c_str());
    if (iotConfig)
    {
        // 获取用户服务
        json_object *userServiceObj = json_object_object_get(iotConfig, "user_service");
        if (!userServiceObj || !json_object_is_type(userServiceObj, json_type_string))
            goto GET_USER_SERVICE_ERR;

        // 获取用户服务信息
        *userService = json_object_get_string(userServiceObj);
        CrLogD("user service info = %s", userService->c_str());
        json_object_put(iotConfig);
        return 0;
        
GET_USER_SERVICE_ERR:
        CrLogE("get http api error\n");
        json_object_put(iotConfig);
        return -1;
    }
    else {
        CrLogE("User Iot Config file fail!\n");
        return -1;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {int} setting
 */
CxyServer_t CxyHttpServer::GetCxyServer(int setting)
{
    CxyServer_t cxyServer = {(char*)"",(char*)"",(char*)"",(char*)"",(char*)""};
    struct json_object *config = json_tokener_parse(AppAesDecryptFromFile(GetUserIotConfigPath()).c_str());
    struct json_object *remoteObj;
    struct json_object *serverObj;
    struct json_object *tmpObj;
    json_object_object_get_ex(config, "cxy_remote", &remoteObj);
    // 选择不同服务器地址
    switch (setting) {
        case CXY_CN_SERVER:
            json_object_object_get_ex(remoteObj, "cxy_cn_server", &serverObj); 
            break;
        case CXY_COM_SERVER: 
            json_object_object_get_ex(remoteObj, "cxy_com_server", &serverObj); 
            break;
        case CXY_CN_PRE_SERVER: 
            json_object_object_get_ex(remoteObj, "cxy_cn_pre_server", &serverObj); 
            break;
        case CXY_COM_PRE_SERVER: 
            json_object_object_get_ex(remoteObj, "cxy_com_pre_server", &serverObj); 
            break;
        case CXY_TEST_SERVER: 
            json_object_object_get_ex(remoteObj, "cxy_test_server", &serverObj);
            break;
        case CXY_DEBUG_SERVER: 
            json_object_object_get_ex(remoteObj, "cxy_debug_server", &serverObj);
            break;
        default: 
            json_object_object_get_ex(remoteObj, "cxy_test_server", &serverObj);
            break;
    }

    json_object_object_get_ex(serverObj, "url", &tmpObj);
    const char *cxy_url = json_object_get_string(tmpObj);
    json_object_object_get_ex(serverObj, "vod", &tmpObj);
    const char *cxy_vod = json_object_get_string(tmpObj);
    json_object_object_get_ex(serverObj, "endpoint", &tmpObj);
    const char *cxy_endpoint = json_object_get_string(tmpObj);    
    json_object_object_get_ex(serverObj, "bucket", &tmpObj);
    const char *cxy_bucket = json_object_get_string(tmpObj);
    json_object_object_get_ex(serverObj, "iot", &tmpObj);
    const char *cxy_iot = json_object_get_string(tmpObj);

    if (cxy_url != NULL) {
        cxyServer.url = (char *)cxy_url;
    }
    if (cxy_vod != NULL) {
        cxyServer.vod = (char *)cxy_vod;
    }
    if (cxy_endpoint != NULL){
        cxyServer.endpoint = (char *)cxy_endpoint;
    }
    if (cxy_bucket != NULL){
        cxyServer.bucket = (char *)cxy_bucket;
    }
    if (cxy_iot != NULL){
        cxyServer.iot = (char *)cxy_iot;
    }
    CrLogD("url = %s,vod = %s, endpoint = %s, bucket = %s, iot = %s",
        cxyServer.url.c_str(), cxyServer.vod.c_str(), cxyServer.endpoint.c_str(),
        cxyServer.bucket.c_str(), cxyServer.iot.c_str());
    json_object_put(config);
    return cxyServer;
}


/**
 * @description: 
 * @return {*}
 * @param {string} remoteUrl
 * @param {string} apiName
 */
int CxyHttpServer::CxyHttpApiInit(std::string remoteUrl, std::string apiName)
{
    CrLogI("Cxy Http Api Init");
    // 从配置文件获取 HTTP 接口
    json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotConfigPath()).c_str());
    if (iotConfig)
    {
        const char *apiStr = NULL;
        json_object *httpApiObj = NULL, *apiObj = NULL;
        // 获取http api信息
        httpApiObj = json_object_object_get(iotConfig, "cxy_http_api");
        if (!httpApiObj) goto GET_HTTP_API_ERR;

        // 获取指定http api
        apiObj = json_object_object_get(httpApiObj, apiName.c_str());
        if (!apiObj) goto GET_HTTP_API_ERR;

        // 获取API接口值
        apiStr = json_object_get_string(apiObj);
        if (!apiStr || strlen(apiStr) < 2)
            goto GET_HTTP_API_ERR;

        // 组装完整API接口
        m_httpRequestApi = remoteUrl + apiStr;
        json_object_put(iotConfig);

        CrLogD("Http Api Init = %s", AppAesEncryptToBase64(m_httpRequestApi).c_str());
        return 0;
        
GET_HTTP_API_ERR:
        CrLogE("get http api error\n");
        json_object_put(iotConfig);
        return -1;
    }
    else
    {
        CrLogE("User Iot Config file fail!\n");
        return -1;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {LanguageType} language
 */
CxyHttpLang_t CxyHttpServer::NetworkLanguageConversion(LanguageType language)
{
    switch (language) {
        case Language_Chinese:  return OS_LANG_ZH;
        case Language_English:  return OS_LANG_EN;
        case Language_German:   return OS_LANG_DE;
        case Language_Spanish:  return OS_LANG_ES;
        case Language_French:   return OS_LANG_FR;
        case Language_Italian:  return OS_LANG_IT;
        case Language_Portuguese: return OS_LANG_PT;
        case Language_Russian:  return OS_LANG_RU;
        case Language_Turkish:  return OS_LANG_TR;
        case Language_Japan:    return OS_LANG_JP;
        default: return OS_LANG_EN;
    }
}

/**
 * @description: 
 * @return {*}
 */
std::string CxyHttpServer::GetHttpRequestHeadLanguage(void)
{
    json_object *config = NULL;
    json_object *userInfoObj = NULL;
    json_object *languageObj = NULL;
    LanguageType language = Language_English;

    // 从文件读取json数据
    config = json_object_from_file(GetUserSystemConfigFilePath());
    if (!config) goto GET_END;

    // 获取 user_info 的json
    userInfoObj = json_object_object_get(config, "user_info");
    if (!userInfoObj) goto GET_END;

    // 获取语言类型
    languageObj = json_object_object_get(userInfoObj, "language");
    if (!languageObj) goto GET_END;

    language = (LanguageType)json_object_get_int(languageObj);

GET_END:
    if (config) json_object_put(config);
    return std::to_string(NetworkLanguageConversion(language));
}

/**
 * @description: 
 * @return {*}
 * @param {curl_slist} *header
 * @param {string} randStr
 */
struct curl_slist *CxyHttpServer::CommonHttpHeaderFields(struct curl_slist *header, std::string randStr)
{
    // 获取设备信息
    RegisterInfo_t devInfo;
    GetRegisterInfoFromFile(&devInfo);
    DeviceVersionInfo_t versionInfo;
    GetVersionInfoFromFile(&versionInfo);

    // 获取系统版本
    char osVersion[100] = {0};
    char buff[64] = {0};
    PopenSystem((char*)"uname -a", buff, sizeof(buff));
    
    regmatch_t regmatch[5];
    int regexSize = UserGetRegexStr(buff, "[^ ]+", regmatch, sizeof(regmatch)/sizeof(regmatch_t));
    if (regexSize >= 3) memcpy(osVersion, &buff[regmatch[2].rm_so], (regmatch[2].rm_eo - regmatch[2].rm_so));
    CrLogI("get os version = %s", osVersion);

    // 获取时区偏移值
    time_t _rt = time(NULL); // 获取系统时间
    tm _gtm = *gmtime(&_rt); // 系统时间转换为GMT时间
    tm _ltm = *localtime(&_rt); // 系统时间转换为本地时间

    // 再将GMT时间重新转换为系统时间
    time_t _gt = mktime(&_gtm);
    tm _gtm2 = *localtime(&_gt);

    // 这时的_gt已经与实际的系统时间_rt有时区偏移了,计算两个值的之差就是时区偏的秒数
    int timeZoneOffset = (_rt - _gt ) + (_gtm2.tm_isdst ? 3600 : 0);
    CrLogI("timeZoneOffset (s) = %d\n", timeZoneOffset);

    // 创建HTTP公共请求头
    header = curl_slist_append(header, "Content-Type: application/json; charset=UTF-8"); // 通信协议
    header = curl_slist_append(header, ("__CXY_BRAND_: " + std::string(__CXY_BRAND_)).c_str()); // 设备品牌
    header = curl_slist_append(header, ("__CXY_OS_VER_: " + std::string(osVersion)).c_str()); // 系统版本
    header = curl_slist_append(header, ("__CXY_OS_LANG_: " + GetHttpRequestHeadLanguage()).c_str()); // 语言
    header = curl_slist_append(header, ("__CXY_PLATFORM_: " + std::string(__CXY_PLATFORM_)).c_str()); // 平台类型
    header = curl_slist_append(header, ("__CXY_DUID_: " + devInfo.sn).c_str()); // 设备ID
    header = curl_slist_append(header, ("__CXY_APP_VER_: " + versionInfo.sysVersion).c_str()); // 固件版本
    header = curl_slist_append(header, ("__CXY_APP_CH_: " + std::string(__CXY_APP_CH_)).c_str()); // 渠道
    header = curl_slist_append(header, ("__CXY_APP_ID_: " + std::string(__CXY_APP_ID_)).c_str()); // APP_ID
	header = curl_slist_append(header, ("__CXY_REQUESTID_: " + randStr).c_str()); // 请求ID，随机字符串
    header = curl_slist_append(header, ("__CXY_TIMEZONE_: " + std::to_string(timeZoneOffset)).c_str()); // 时区
    return header;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *ptr
 * @param {size_t} size
 * @param {size_t} nmemb
 * @param {void} *data
 */
inline size_t CxyHttpServer::StoreData(void *ptr, size_t size, size_t nmemb, void *data)
{
    size_t real_size = size * nmemb;
    std::string &mem_ptr = *((std::string *)data);
    mem_ptr += (char *)ptr;
    return real_size;
}

/**
 * @description: 获取随机数
 * @param  {*}
 * @return {*}
 */
inline std::string CxyHttpServer::GetRandString(void)
{
    struct timeval now;
    gettimeofday(&now, NULL);
    struct tm *curTime = localtime(&now.tv_sec);

    char curTimeStr[25] = {0};
    sprintf(curTimeStr, "%d%02d%02d%02d%02d%02d%ld",
            curTime->tm_year + 1900, curTime->tm_mon + 1, curTime->tm_mday ,
            curTime->tm_hour, curTime->tm_min, curTime->tm_sec, now.tv_usec/1000);

    std::string randStr = "cl60" + std::string(curTimeStr) + std::to_string(rand() % (99999 - 10000) + 10000);
    return randStr;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {string} macAddr
 * @param {string} requestId
 */
inline std::string CxyHttpServer::GetTbSignString(std::string macAddr, std::string requestId)
{
    unsigned char hashStr[33] = {0};
	std::string sha256Source = macAddr + requestId + std::string(POST_SECRET);

    // 哈希后的十六进制串 32字节  
	SHA256((const unsigned char *)sha256Source.c_str(), sha256Source.length(), hashStr);
	char hashHex[65] = {0};
	for (int i = 0; i < 32; i++)
	{
        char temp[3] = {0};
		sprintf(temp, "%02x", hashStr[i]);
		strcat(hashHex, temp);
	}

    return std::string(hashHex);
}

/**
 * @description: 
 * @return {*}
 */
inline std::string CxyHttpServer::GetProductionSnString(void)
{
    CrLogI("get production info");
    std::string productionSn = "";

    // 从文件获取生产信息
    json_object *productionInfoObj = json_object_from_file(GetMachineProductionInfo());
    if (!productionInfoObj) {
        CrLogW("no production info\n");
        return productionSn;
    }

    // 获取生产SN号
    json_object *productionSnObj = json_object_object_get(productionInfoObj, "productionSn");
    if (productionSnObj && json_object_is_type(productionSnObj, json_type_string)) {
        productionSn = json_object_get_string(productionSnObj);
    }

    json_object_put(productionInfoObj);
    CrLogI("production sn = %s\n", productionSn.c_str());
    return productionSn;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *contex
 * @param {string} &token
 * @param {string} &devName
 */
inline int CxyHttpServer::ParseTbInfo(const char *contex, DeviceTbInfo_t *tbInfo)
{
    struct json_object *root = NULL;
    struct json_object *item = NULL;
    struct json_object *result = NULL;
    int code = -1;

    if ((contex == NULL) || (root = json_tokener_parse(contex)) == NULL) {
        CrLogE("contex NULL or json parse error!\n");
        goto PARSE_END;
    }

    if ((item = json_object_object_get(root, "code")) == NULL || (json_object_get_type(item) != json_type_int)) {
        CrLogE("no code fileds or type error!\n");
        goto PARSE_END;
    }

    code = json_object_get_int(item);
    if (code != 0) {
        CrLogE("result error!: %d\n", code);
        goto PARSE_END;
    }

    if ((result = json_object_object_get(root, "result")) == NULL) {
    	CrLogE("result error!\n");
    	goto PARSE_END;
    }

    if ((item = json_object_object_get(result, "tbToken")) == NULL || (json_object_get_type(item) != json_type_string)) {
    	CrLogE("%s key not find or item type error!\n", "tbToken");
    	goto PARSE_END;
    }
    tbInfo->token = json_object_get_string(item);

    if ((item = json_object_object_get(result, "deviceName")) == NULL || (json_object_get_type(item) != json_type_string)) {
    	CrLogE("%s key not find or item type error!\n", "deviceName");
    	goto PARSE_END;
    }
    tbInfo->devName = json_object_get_string(item);

    if ((item = json_object_object_get(result, "tbId")) == NULL || (json_object_get_type(item) != json_type_string)) {
    	CrLogE("%s key not find or item type error!\n", "tbId");
    	goto PARSE_END;
    }
    tbInfo->devId = json_object_get_string(item);

    json_object_put(root);
    return 0;

PARSE_END:
    if (root) json_object_put(root);
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {RegisterInfo_t} devInfo
 * @param {DeviceTbInfo_t} *tbInfo
 */
int CxyHttpServer::HttpRegisterDevice(RegisterInfo_t devInfo, DeviceTbInfo_t *tbInfo)
{
    int ret = -1;
    std::string randStr = GetRandString();
    std::string sigStr = GetTbSignString(devInfo.mac, randStr);
    std::string productionSn = GetProductionSnString();

    struct curl_slist *header = NULL;
    header = CommonHttpHeaderFields(header, randStr);

    json_object *bodyObj = json_object_new_object();
    json_object_object_add(bodyObj, "iotType", json_object_new_int(IOT_TYPE));
    json_object_object_add(bodyObj, "mac", json_object_new_string(devInfo.mac.c_str()));
    json_object_object_add(bodyObj, "sign", json_object_new_string(sigStr.c_str()));
    json_object_object_add(bodyObj, "type", json_object_new_int(DEVICE_TYPE));
    json_object_object_add(bodyObj, "printerName", json_object_new_string(devInfo.model.c_str()));
    json_object_object_add(bodyObj, "factorySN", json_object_new_string(productionSn.c_str()));

    std::string body = json_object_to_json_string_ext(bodyObj, JSON_C_TO_STRING_PLAIN);
    CrLogD("body = %s\n", AppAesEncryptToBase64(body).c_str());
    json_object_put(bodyObj);

    std::string response = "";
    CURL *curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        if(strstr(m_httpRequestApi.c_str(),  "https:")  != NULL)
        {
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        }
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, m_httpRequestApi.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());

        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1l);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, StoreData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)(&response));

        long httpCode = 0;
        CURLcode res = curl_easy_perform(curl);
        CURLcode getCodeRes = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE , &httpCode);
        CrLogI("res = %d, getCodeRes = %d, httpCode = %d", res, getCodeRes, httpCode);

        // 判断http请求结果
        if (res != CURLE_OK || getCodeRes != CURLE_OK || httpCode != 200) {
            CrLogE("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else {
            CrLogD("response = %s\n", AppAesEncryptToBase64(response).c_str());
            tbInfo->httpRes = response;
            if (ParseTbInfo(response.c_str(), tbInfo) == 0) {
                CrLogI("tbToken = %s", AppAesEncryptToBase64(tbInfo->token).c_str());
                CrLogI("deviceName = %s", tbInfo->devName.c_str());
                CrLogI("deviceId = %s", tbInfo->devId.c_str());
            }
            ret = 0;
        }
        curl_easy_cleanup(curl);
    }
    curl_slist_free_all(header);
    return ret;
}

/**
 * @description: 
 * @return {*}
 * @param {RegisterInfo_t} devInfo
 * @param {DeviceTbInfo_t} *tbInfo
 */
int CxyHttpServer::GetConnectTbInfo(RegisterInfo_t devInfo, DeviceTbInfo_t *tbInfo)
{
    CrLogI("Get Connect Tb Info");
    json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
    if (!iotConfig) {
        iotConfig = json_object_from_file(GetUserIotTbInfoFilePtah());
        if (!iotConfig) {
            CrLogW("no tb info file\n");
            iotConfig = json_object_new_object();
        }
        else AppAesEncryptToFile(GetUserIotTbInfoFilePtah(), json_object_to_json_string(iotConfig));
    }

    const char *tbTokenStr = NULL, *devNameStr = NULL, *devIdStr = NULL;
    json_object *tbInfoObj = NULL, *tbTokenObj = NULL, *devNameObj = NULL, *devIdObj = NULL;
    // 获取tb信息对象
    tbInfoObj = json_object_object_get(iotConfig, "cxy_tb_info");
    if (!tbInfoObj)
    {
        tbInfoObj = json_object_new_object();
        tbTokenObj = json_object_new_string_len("", 0);
        devNameObj = json_object_new_string_len("", 0);
        devIdObj = json_object_new_string_len("", 0);
        json_object_object_add(tbInfoObj, "tb_token", tbTokenObj);
        json_object_object_add(tbInfoObj, "dev_name", devNameObj);
        json_object_object_add(tbInfoObj, "dev_id", devIdObj);
        json_object_object_add(iotConfig, "cxy_tb_info", tbInfoObj);
        goto GET_TB_INFO;
    }
    // 获取tb_token、dev_name对象
    tbTokenObj = json_object_object_get(tbInfoObj, "tb_token");
    devNameObj = json_object_object_get(tbInfoObj, "dev_name");
    devIdObj = json_object_object_get(tbInfoObj, "dev_id");
    if (!tbTokenObj || !devNameObj || !devIdObj)
    {
        if (!tbTokenObj) 
        {
            tbTokenObj = json_object_new_string_len("", 0);
            json_object_object_add(tbInfoObj, "tb_token", tbTokenObj);
        }
        if (!devNameObj)
        {
            devNameObj = json_object_new_string_len("", 0);
            json_object_object_add(tbInfoObj, "dev_name", devNameObj);
        }
        if (!devIdObj)
        {
            devIdObj = json_object_new_string_len("", 0);
            json_object_object_add(tbInfoObj, "dev_id", devIdObj);
        }
        goto GET_TB_INFO;
    }
    // 获取tb_token、dev_name值
    tbTokenStr = json_object_get_string(tbTokenObj);
    devNameStr = json_object_get_string(devNameObj);
    devIdStr = json_object_get_string(devIdObj);
    if (!tbTokenStr || !devNameStr || !devIdStr || 
        strlen(tbTokenStr) < 2 || strlen(devNameStr) < 2 || strlen(devIdStr) < 2)
        goto GET_TB_INFO;

    // 判断是否手动修改设备信息
    if (devInfo.sn != std::string(devNameStr)) {
        CrLogW("the device name are different from the regist info\n");
        if (remove(GetCxyDeviceBindingQrCodePtah()) != 0)
            CrLogW("remove binding qrcode fail\n");
        goto GET_TB_INFO;
    }

    tbInfo->token = tbTokenStr;
    tbInfo->devName = devNameStr;
    tbInfo->devId = devIdStr;
    json_object_put(iotConfig);

    CrLogI("get tb connect info from local file");
    CrLogI("tbToken = %s", AppAesEncryptToBase64(tbInfo->token).c_str());
    CrLogI("deviceName = %s", tbInfo->devName.c_str());
    CrLogI("deviceId = %s", tbInfo->devId.c_str());
    return 0;

GET_TB_INFO:
    CrLogI("Http Register Device start\n");
    if(HttpRegisterDevice(devInfo, tbInfo) == -1) {
        json_object_put(iotConfig);
        return -1;
    }
    json_object_set_string_len(tbTokenObj, tbInfo->token.c_str(), tbInfo->token.length());
    json_object_set_string_len(devNameObj, tbInfo->devName.c_str(), tbInfo->devName.length());
    json_object_set_string_len(devIdObj, tbInfo->devId.c_str(), tbInfo->devId.length());

    int res = AppAesEncryptToFile(GetUserIotTbInfoFilePtah(), json_object_to_json_string(iotConfig));
    json_object_put(iotConfig);
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *subType
 * @param {char} *hwVersion
 * @param {string} *info
 * @param {int} otaType
 */
CURLcode CxyHttpServer::HttpGetUpgradeInfo(char *subType, char *fwVersion, char *hwVersion, std::string *info, int otaType)
{
    CURLcode res = CURLE_FAILED_INIT;
    struct curl_slist *header = NULL;
    header = CommonHttpHeaderFields(header, GetRandString());

    // 创建body数据
    CrLogI("subType = %s, hwVersion = %s", subType, hwVersion);
    json_object *infoObj = json_object_new_object();
    json_object_object_add(infoObj, "type", json_object_new_int(otaType));
    json_object_object_add(infoObj, "subType", json_object_new_string(subType));
    json_object_object_add(infoObj, "firmwareVersion", json_object_new_string(fwVersion));
    json_object_object_add(infoObj, "hardwareVersionNumber", json_object_new_string(hwVersion));

    json_object *arrayObj = json_object_new_array();
    json_object_array_add(arrayObj, infoObj);
    json_object *bodyObj = json_object_new_object();
    json_object_object_add(bodyObj, "items", arrayObj);

    std::string body = json_object_to_json_string_ext(bodyObj, JSON_C_TO_STRING_PLAIN);
    CrLogD("body = %s", AppAesEncryptToBase64(body).c_str());
    json_object_put(bodyObj);

    // 开始http请求
    CURL *curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        if(strstr(m_httpRequestApi.c_str(),  "https:")  != NULL)
        {
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        }
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, m_httpRequestApi.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());

        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1l);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, StoreData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)(info));

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            CrLogE("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else CrLogD("request info = %s\n", info->c_str());
        curl_easy_cleanup(curl);
    }
    
    curl_slist_free_all(header);
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *mac
 * @param {string} *info
 */
CURLcode CxyHttpServer::HttpGetTmplyAuthorityInfo(std::string token, std::string *info)
{
    CURLcode res = CURLE_FAILED_INIT;
    struct curl_slist *header = NULL;
    header = CommonHttpHeaderFields(header, GetRandString());
    header = curl_slist_append(header, ("__CXY_JWTOKEN_: " + token).c_str());

    // 创建body数据
    json_object *bodyObj = json_object_new_object();
    std::string body = json_object_to_json_string_ext(bodyObj, JSON_C_TO_STRING_PLAIN);
    CrLogD("body = %s", AppAesEncryptToBase64(body).c_str());
    json_object_put(bodyObj);

    // 开始http请求
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        if(strstr(m_httpRequestApi.c_str(),  "https:")  != NULL)
        {
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        }
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, m_httpRequestApi.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());

        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1l);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, StoreData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)(info));

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            CrLogE("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else CrLogD("request info = %s\n", AppAesEncryptToBase64(*info).c_str());
        curl_easy_cleanup(curl);
    }
    
    curl_slist_free_all(header);
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *mac
 * @param {string} *info
 */
CURLcode CxyHttpServer::HttpGetPreSubmitTimelapse(std::string token,VideoAssociate_t para, std::string *info)
{
    CURLcode res = CURLE_FAILED_INIT;
    struct curl_slist *header = NULL;
    header = CommonHttpHeaderFields(header, GetRandString());
    header = curl_slist_append(header, ("__CXY_JWTOKEN_: " + token).c_str());

    // 创建body数据
    json_object *bodyObj = json_object_new_object();

    json_object_object_add(bodyObj, "mac", json_object_new_string(para.mac.c_str()));
    json_object_object_add(bodyObj, "printId", json_object_new_string(para.printId.c_str()));
    json_object_object_add(bodyObj, "deviceName", json_object_new_string(para.deviceName.c_str()));
    json_object_object_add(bodyObj, "md5", json_object_new_string(para.md5.c_str()));
    json_object_object_add(bodyObj, "manually", json_object_new_boolean(para.manually));
    json_object_object_add(bodyObj, "name", json_object_new_string(para.name.c_str()));
    json_object_object_add(bodyObj, "size", json_object_new_uint64(para.size));

    std::string body = json_object_to_json_string_ext(bodyObj, JSON_C_TO_STRING_PLAIN);
    CrLogD("body = %s", AppAesEncryptToBase64(body).c_str());
    json_object_put(bodyObj);

    // 开始http请求
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        if(strstr(m_httpRequestApi.c_str(),  "https:")  != NULL)
        {
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        }
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, m_httpRequestApi.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());

        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1l);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, StoreData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)(info));

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            CrLogE("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else CrLogD("request info = %s\n", AppAesEncryptToBase64(*info).c_str());
        curl_easy_cleanup(curl);
    }
    
    curl_slist_free_all(header);
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *token
 * @param {VideoAssociate_t} para
 * @param {string} *info
 */
CURLcode CxyHttpServer::HttpAssociateVideoToPrintJob(std::string token, VideoAssociate_t para, std::string *info)
{
    CURLcode res = CURLE_FAILED_INIT;
    struct curl_slist *header = NULL;
    header = CommonHttpHeaderFields(header, GetRandString());
    header = curl_slist_append(header, ("__CXY_JWTOKEN_: " + token).c_str());

    // 创建body数据
    json_object *bodyObj = json_object_new_object();
    json_object_object_add(bodyObj, "mac", json_object_new_string(para.mac.c_str()));
    json_object_object_add(bodyObj, "videoId", json_object_new_string(para.videoId.c_str()));
    json_object_object_add(bodyObj, "printId", json_object_new_string(para.printId.c_str()));
    json_object_object_add(bodyObj, "deviceName", json_object_new_string(para.deviceName.c_str()));
    json_object_object_add(bodyObj, "md5", json_object_new_string(para.md5.c_str()));
    json_object_object_add(bodyObj, "manually", json_object_new_boolean(para.manually));
    json_object_object_add(bodyObj, "name", json_object_new_string(para.name.c_str()));

    std::string body = json_object_to_json_string_ext(bodyObj, JSON_C_TO_STRING_PLAIN);
    CrLogD("body = %s", AppAesEncryptToBase64(body).c_str());
    json_object_put(bodyObj);

    // 开始http请求
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        if(strstr(m_httpRequestApi.c_str(),  "https:")  != NULL)
        {
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        }
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, m_httpRequestApi.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());

        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1l);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, StoreData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)(info));

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            CrLogE("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else CrLogD("request info = %s\n", info->c_str());
        curl_easy_cleanup(curl);
    }
    
    curl_slist_free_all(header);
    return res;
}

/**
 * @description: 
 * @return {CURLcode}
 * @param {char *} token
 * @param {char *} deviceName
 * @param {char *} logFileKey
 */
CURLcode CxyHttpServer::HttpCallRecordUploadLog2server(std::string token, std::string deviceName, char *logFileKey, std::string *info)
{
	CURL *curl = NULL;
	CURLcode res;
	struct curl_slist *header = NULL;
	char body[1024] = {0};

    snprintf(body, sizeof(body), "{\"deviceName\":\"%s\", \"logFileKey\":\"%s\"}", deviceName.c_str(), logFileKey);
    CrLogD("body:%s\n", AppAesEncryptToBase64(body).c_str());

    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, m_httpRequestApi.c_str());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST"); // post
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        if(strstr(m_httpRequestApi.c_str(),  "https:")  != NULL)
        {
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        }
        header = CommonHttpHeaderFields(header, GetRandString());
        header = curl_slist_append(header, ("__CXY_JWTOKEN_: " + token).c_str());

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body); // POST
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, StoreData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)(info));
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            CrLogE("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else CrLogD("request info = %s\n", info->c_str());
        curl_easy_cleanup(curl);
    }
    curl_slist_free_all(header);
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *token
 * @param {string} *info
 */
CURLcode CxyHttpServer::HttpGetOwnerInfo(char *token, std::string *info)
{
    CURLcode res = CURLE_FAILED_INIT;
    struct curl_slist *header = NULL;
    header = CommonHttpHeaderFields(header, GetRandString());
    header = curl_slist_append(header, ("__CXY_JWTOKEN_: " + std::string(token)).c_str());

    // 创建body数据
    json_object *bodyObj = json_object_new_object();
    std::string body = json_object_to_json_string_ext(bodyObj, JSON_C_TO_STRING_PLAIN);
    CrLogD("body = %s", AppAesEncryptToBase64(body).c_str());
    json_object_put(bodyObj);

    // 开始http请求
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        if(strstr(m_httpRequestApi.c_str(),  "https:")  != NULL)
        {
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        }
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, m_httpRequestApi.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());

        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1l);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, StoreData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)(info));

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            CrLogE("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else CrLogD("request info = %s\n", info->c_str());
        curl_easy_cleanup(curl);
    }
    
    curl_slist_free_all(header);
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *token
 * @param {string} *info
 */
CURLcode CxyHttpServer::HttpReportAiNotice(char *token, std::string *info, char * printId)
{
    CURLcode res = CURLE_FAILED_INIT;
    struct curl_slist *header = NULL;
    header = CommonHttpHeaderFields(header, GetRandString());
    header = curl_slist_append(header, ("__CXY_JWTOKEN_: " + std::string(token)).c_str());

    // 创建body数据
    json_object *bodyObj = json_object_new_object();
    json_object *arrayObj = json_object_new_array();
    json_object_array_add(arrayObj, json_object_new_int(1));
    json_object_object_add(bodyObj, "printId", json_object_new_string(printId));
    json_object_object_add(bodyObj, "notifyMethods", arrayObj);
    std::string body = json_object_to_json_string_ext(bodyObj, JSON_C_TO_STRING_PLAIN);
    CrLogD("body = %s", AppAesEncryptToBase64(body).c_str());
    json_object_put(bodyObj);

    // 开始http请求
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        if(strstr(m_httpRequestApi.c_str(),  "https:")  != NULL)
        {
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        }
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, m_httpRequestApi.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());

        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1l);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, StoreData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)(info));

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            CrLogE("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else CrLogD("request info = %s\n", info->c_str());
        curl_easy_cleanup(curl);
    }
    
    curl_slist_free_all(header);
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *token
 * @param {string} *info
 */
CURLcode CxyHttpServer::HttpLocalPrint(char *token, std::string *info, char * workId, char *fileName, char *model)
{
    CURLcode res = CURLE_FAILED_INIT;
    struct curl_slist *header = NULL;
    header = CommonHttpHeaderFields(header, GetRandString());
    header = curl_slist_append(header, ("__CXY_JWTOKEN_: " + std::string(token)).c_str());

    // 创建body数据
    json_object *bodyObj = json_object_new_object();
    json_object *printerObj = json_object_new_object();
    json_object_object_add(printerObj, "internalName", json_object_new_string(model));
    
    std::string modelStr = "";
    modelStr = model;
    modelStr = modelStr.substr(modelStr.find('-') + 1);

    json_object_object_add(printerObj, "name", json_object_new_string(modelStr.c_str()));
    json_object_object_add(printerObj, "type", json_object_new_int(1));
    json_object_object_add(bodyObj, "printer", printerObj);
    json_object_object_add(bodyObj, "localPrintId", json_object_new_string(workId));
    json_object_object_add(bodyObj, "fileName", json_object_new_string(fileName));
    json_object_object_add(bodyObj, "type", json_object_new_int(1));

    std::string body = json_object_to_json_string_ext(bodyObj, JSON_C_TO_STRING_PLAIN);
    CrLogD("body = %s", AppAesEncryptToBase64(body).c_str());
    json_object_put(bodyObj);

    // 开始http请求
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        if(strstr(m_httpRequestApi.c_str(),  "https:")  != NULL)
        {
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        }
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, m_httpRequestApi.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());

        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, StoreData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)(info));

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            CrLogE("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else CrLogD("request info = %s\n", info->c_str());
        curl_easy_cleanup(curl);
    }
    
    curl_slist_free_all(header);
    return res;
}