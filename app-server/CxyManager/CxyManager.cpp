/*
 * @Description : 创想云管理
 * @Author      : Yufeng Zhang
 * @Date: 2022-05-06 22:16:45
 * @LastEditTime: 2023-10-16 16:35:55
 */
#include <iostream>
#include <thread>
#include <algorithm>
#include <sys/time.h>
#include <chrono>
#include "Base/AppMsgBase.h"
#include "Message/ServerMessage.h"
#include "CxyManager.h"
#include "CxyQrCode.h"
#include "CxyHttpServer.h"
#include "global/Global.h"
#include "Base/Jwt/jwt-cpp/jwt.h"
#include "Base/Jwt/jwt-cpp/base.h"
#include "Base/Jwt/picojson/picojson.h"
#include <curl/curl.h>
#include <fstream>
using namespace std;
/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {* args} *
 */
CxyManager::CxyManager()
{
    m_downloadGcodeClient = NULL;
    m_heartBeatCount = 0;
    m_mqttConState = MQTT_THRUN_NUM;
    memset(&m_appPrintState, 0, sizeof(AppPrintState_t));
    memset(&m_lastPrintState, 0, sizeof(AppPrintState_t));
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
CxyManager::~CxyManager()
{
    m_mqttServerClient.Stop();
    m_mqttServerClient.RegisterRecvJsonCb(nullptr);
    m_mqttServerClient.RegisterConStateCb(nullptr);
}

/**
 * @description: 
 * @return {*}
 */
int CxyManager::GetMqttConState(void) { return m_mqttConState; }

/**
 * @description: 
 * @return {*}
 */
AppPrintState_t *CxyManager::GetAppPrintState(void) { return &m_appPrintState; }

/**
 * @description: 上报遥测数据
 * @param  {*}
 * @return {*}
 * @param {string} &result
 */
int CxyManager::DelectPrintTelemetryState(std::string &result, bool flag)
{
    bool change = false;
    json_object *resObj = json_object_new_object();

    BUILD_JS_ITEM(CMP_INT, curHotendTemp, resObj, nozzleTemp, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, curBedTemp, resObj, bedTemp, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, curBoxTemp, resObj, boxTemp, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, printProgress, resObj, printProgress, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, printUsageTime, resObj, printJobTime, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, printRemainTime, resObj, printLeftTime, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, downloadProgress, resObj, dProgress, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, printSpeed, resObj, curFeedratePct, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, printFlow, resObj, curFlowratePct, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, filamentUsed, resObj, ConsumablesLen, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_STR, curPosition, resObj, curPosition, json_object_new_string, CPY_STR, change, flag);
    BUILD_JS_ITEM(CMP_STR, autohome, resObj, curHome, json_object_new_string, CPY_STR, change, flag);
    BUILD_JS_ITEM(CMP_INT, printLayer, resObj, layer, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, consumables, resObj, FilamentLen, json_object_new_int, CPY_INT, change, flag);
    if (change) result = json_object_to_json_string(resObj);
    json_object_put(resObj);

    return result.length();
}

/**
 * @description: 上报属性数据
 * @param  {*}
 * @return {*}
 * @param {string} &result
 */
int CxyManager::DelectPrintAttributesState(std::string &result, bool flag)
{
    bool change = false;
    json_object *resObj = json_object_new_object();
    BUILD_JS_ITEM(CMP_INT, serialPort, resObj, connect, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, sdCardExists, resObj, tfCard, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_STR, modelVersion, resObj, modelVersion, json_object_new_string, CPY_STR, change, flag);
    BUILD_JS_ITEM(CMP_STR, model_str, resObj, model, json_object_new_string, CPY_STR, change, flag);
    //BUILD_JS_ITEM(CMP_INT, workState, resObj, state, json_object_new_int, CPY_INT, change, flag);
    //BUILD_JS_ITEM(CMP_STR, printId, resObj, printId, json_object_new_string, CPY_STR, change, flag);
    BUILD_JS_COMBIN_ITEM(CMP_INT, workState, resObj, state, json_object_new_int, CPY_INT, change, flag, printId, printId, json_object_new_string);
    BUILD_JS_ITEM(CMP_INT, deviceState, resObj, machineStatus, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, modelFan, resObj, modelFan, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, caseFan, resObj, caseFan, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, auxiliaryFan, resObj, auxiliaryFan, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, modelFanPct, resObj, modelFanPct, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, caseFanPct, resObj, caseFanPct, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, auxiliaryFanPct, resObj, auxiliaryFanPct, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, targetHotendTemp, resObj, nozzleTemp2, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, targetBedTemp, resObj, bedTemp2, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, printLayers, resObj, TotalLayer, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, startPrintTime, resObj, printStartTime, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, existOffContinue, resObj, repoPlrStatus, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, upgradeState, resObj, upgradeStatus, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, videoElapseState, resObj, videoElapse, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, nozzleMoveSnapshotState, resObj, nozzleMoveSnapshot, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, lightState, resObj, led_state, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, modleCamera, resObj, video, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, nozzleCamera, resObj, video1, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, aiSw, resObj, enableAITest, json_object_new_int, CPY_INT, change, flag);
    //BUILD_JS_ITEM(CMP_INT, aiDetection, resObj, faultReminder, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, aiPausePrint, resObj, enableFaultStop, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, aiFirstFloor, resObj, firstFaultReminder, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_STR, zOffset, resObj, zOffset, json_object_new_string, CPY_STR, change, flag);
    BUILD_JS_ITEM(CMP_INT, autoLevelProgress, resObj, autoLeveling, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, chatteringOpt, resObj, chatteringOpt, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, enableSelfTest, resObj, enableSelfTest, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, withSelfTest, resObj, withSelfTest, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, selfTestStep, resObj, selfTestStep, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, feedState, resObj, feedState, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, feedStateTemp2, resObj, feedStateTemp2, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_INT, speedMode, resObj, speedMode, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_STR, sys_version, resObj, printerVersion, json_object_new_string, CPY_STR, change, flag);
    BUILD_JS_ITEM(CMP_STR, wifi_ip, resObj, netIP, json_object_new_string, CPY_STR, change, flag);
    BUILD_JS_ITEM(CMP_STR, lan_ip, resObj, lanIP, json_object_new_string, CPY_STR, change, flag);
    BUILD_JS_ITEM(CMP_INT, faultCode.code, resObj, err, json_object_new_int, CPY_INT, change, flag);
    BUILD_JS_ITEM(CMP_STR, printFileName, resObj, print, json_object_new_string, CPY_STR, change, flag);
    BUILD_JS_ITEM(CMP_INT, materialStatus, resObj, report_consumables, json_object_new_int, CPY_INT, change, flag);
    if (change) result = json_object_to_json_string(resObj);
    json_object_put(resObj);

    return result.length();
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int CxyManager::DelectAppPrintState(bool flag)
{
    static auto lastCallTime = std::chrono::steady_clock::now();
    auto currentTime = std::chrono::steady_clock::now();
    std::string telemetryState;
    std::string attributesState;
    if (std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastCallTime).count() >= 3  || flag) {
        // 上报遥测
        if (DelectPrintTelemetryState(telemetryState, flag))
        {
            m_mqttServerClient.SendTelemetry(telemetryState);
        }
        // 上报属性
        if (DelectPrintAttributesState(attributesState, flag))
        {
            m_mqttServerClient.SendAttributes(attributesState);
        }
        lastCallTime = currentTime;
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
int CxyManager::AttributesTelemetryStateInit(void)
{
    DelectAppPrintState(true);
    return 0;
}


/**
 * @description: 
 * @return {*}
 * @param {UpgradeState_t} state
 * @param {int} progress
 */
int CxyManager::AppSyncUpgradeState(UpgradeState_t state, int progress, UpgradeTarget_t target)
{
    if (state == UPGRADE_DOWNLOAD_ING ||
        state == UPGRADE_DOWNLOAD_OK ||
        state == UPGRADE_DOWNLOAD_FAIL)
    {
        DownloadProgressCallback(progress);
    }

    int iotUgState;
    switch (state)
    {
        case UPGRADE_DOWNLOAD_ING: iotUgState = APP_UPGRADE_DOWNLOAD_ING; break;
        case UPGRADE_INSTALL_ING: iotUgState = APP_UPGRADE_INSTALL_ING; break;
        case UPGRADE_INSTALL_FAIL: iotUgState = APP_UPGRADE_INSTALL_FAIL; break;
        case UPGRADE_INSTALL_OK: iotUgState = APP_UPGRADE_INSTALL_OK; break;
        default: iotUgState = APP_UPGRADE_STATE_IDLE; break;
    }
    // 更新状态
    m_appPrintState.upgradeState = iotUgState;
    if (m_lastPrintState.upgradeState != m_appPrintState.upgradeState) DelectAppPrintState(true);
    else DelectAppPrintState(false);
	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {UpgradeState_t} state
 * @param {int} progress
 */
int CxyManager::UpgradeStateResponse(UpgradeState_t state, int progress, UpgradeTarget_t target)
{
    // 更新升级状态到IOT
    AppSyncUpgradeState(state, progress, target);

    // 同步升级状态
    UpgradeInfo info = UPGRADE_INFO__INIT;
    info.has_state = 1;
    info.state = state;
    info.has_progress = 1;
    info.progress = progress;

    UpgradeInfoList list = UPGRADE_INFO_LIST__INIT;
    if (target == UPGRADE_TARGET_LINUX)
        list.linuxota = &info;
    else list.mcu1ota = &info;

    GET_MESSAGE_BUFF(buff);
    size_t len = upgrade_info_list__pack(&list, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_SYNC_UPGRADE_STATE, buff, len);
    SendProcessMsgBuff(&send, size);
	return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} progress
 */
int CxyManager::DownloadProgressCallback(int progress)
{
    CrLogI("Download Progress = %d", progress);
    m_appPrintState.downloadProgress = progress;
    DelectAppPrintState(false);
	return 0;
}

/**
 * @description: 
 * @return {*}
 */
bool CxyManager::EndsWith(std::string &str, std::string const &suffix)
{
    if (str.length() < suffix.length()) {
        return false;
    }
    return std::equal(suffix.rbegin(), suffix.rend(), str.rbegin());
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} state
 */
int CxyManager::DownloadStateCallback(int state, std::string fileName)
{
    CrLogI("Download state = %d", state);
    if (state == FILE_DOWNLOAD_OK)
    {
        DownloadProgressCallback(100);

        // 获取文件名
        std::string newGcodeName = fileName;
        // 判断文件格式
        if (EndsWith(newGcodeName, ".gz")) {
            // 提取文件名解压文件
            newGcodeName.erase(newGcodeName.end() - strlen(".gz"), newGcodeName.end());

            std::string systemCmd = "gzip -df '" + fileName + "' > '" + newGcodeName + "'";
            CrLogD("systemCmd = %s\n", systemCmd.c_str());

            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem((char*)systemCmd.c_str(), sysRes, sizeof(sysRes)))
                CrLogW("system fail! res = %s\n", sysRes);
        }
        CrLogI("newGcodeName = %s", newGcodeName.c_str());

        // 开始打印云切片3D模型文件
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_print = 1;
        control.print.data = (uint8_t*)newGcodeName.c_str();
        control.print.len = newGcodeName.length();
      
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    // 同步gcode下载状态
    DownloadGcode downloadState = DOWNLOAD_GCODE__INIT;
    downloadState.has_state = 1;
    downloadState.state = state;
        
    GET_MESSAGE_BUFF(buff);
    size_t len = download_gcode__pack(&downloadState, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_SYNC_GCODE_DOWNLOAD, buff, len);
    SendProcessMsgBuff(&send, size);
    
    // 释放类
    if (state == FILE_DOWNLOAD_OK || 
        state == FILE_DOWNLOAD_FAIL ||
        state == FILE_DOWNLOAD_CANCEL)
    {
        delete m_downloadGcodeClient;
        m_downloadGcodeClient = NULL;
    }

	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {*}
 */
static size_t WriteData(void *ptr, size_t size, size_t nmemb, void *stream) 
{
    std::ofstream *file = static_cast<std::ofstream *>(stream);
    file->write(static_cast<char *>(ptr), size * nmemb);
    return size * nmemb;
}

/**
 * @description: 
 * @return {*}
 * @param {*}
 */
static int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow,
                      curl_off_t ultotal, curl_off_t ulnow) 
{
    CrLogI("Download progress: %ld / %ld", dlnow,dltotal);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {string} url
 * @param {string} path
 */
int CxyManager::DownloadUserAvatar(std::string url, std::string path)
{
    CURL *curl = curl_easy_init();
    if (curl) {
        // std::string path = path;
        std::ofstream file(path);
        if (!file.is_open()) {
            CrLogW("Failed to open file: %s", path.c_str());
            curl_easy_cleanup(curl);
            return -1;
        }
        curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, ProgressCallback);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION , WriteData);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA , &file);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            CrLogW("curl_easy_perform() failed: %s", curl_easy_strerror(res));          
            file.close();
            curl_easy_cleanup(curl);
            return -1;
        }
        file.close();
        curl_easy_cleanup(curl);
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
void CxyManager::UserUpdateUserInfo(void)
{
    // 判断JWT token是否有效
    int response = RequestOwnerInfo(m_appPrintState.appJwtToken);

    json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
    if(iotConfig){
        json_object * otherInfoObj = json_object_object_get(iotConfig, "cxy_other_info");
        if(otherInfoObj){
            json_object *jwtObj = json_object_object_get(otherInfoObj, "jwt_token");
            if(jwtObj){
                bzero(m_appPrintState.appJwtToken, sizeof(m_appPrintState.appJwtToken));
                memcpy(m_appPrintState.appJwtToken, json_object_get_string(jwtObj), strlen(json_object_get_string(jwtObj)));    
            }
        }
        json_object * userInfoObj = json_object_object_get(iotConfig, "cxy_user_info");
        if(userInfoObj){
            json_object *avatarObj = json_object_object_get(userInfoObj, "avatar");
            std::string url = json_object_get_string(avatarObj);

            // 生成用户图片路径
            char userAvatarPngPath[256] = {0};
            strcat(userAvatarPngPath, GetUserDataConfigDirPtah());
            strcat(userAvatarPngPath, "/user_avatar");
            if (strrchr(url.c_str(), '.')) strcat(userAvatarPngPath, strrchr(url.c_str(), '.'));
            else strcat(userAvatarPngPath, url.c_str());
            CrLogI("userAvatarPngPath = %s", userAvatarPngPath);

            // 下载用户图片
            if(response) {
                // 限制下载用户头像图片大小
                url = url + "?x-oss-process=image/resize,m_fill,h_76,w_76";
                CrLogI("download avatar url = %s", url.c_str());

                int downloadResult = DownloadUserAvatar(url , userAvatarPngPath);
                CrLogI("downloadResult = %d", downloadResult);
                if (downloadResult != 0) bzero(userAvatarPngPath, sizeof(userAvatarPngPath));
            }
            json_object_object_add(userInfoObj, "avatar_png", json_object_new_string(userAvatarPngPath));
            AppAesEncryptToFile(GetUserIotTbInfoFilePtah(), json_object_to_json_string(iotConfig));
        }
        json_object_put(iotConfig);
    }
    
    // 响应
    GeneralRes res = GENERAL_RES__INIT;
    if (response){
        res.result = 1;
        CrLogI("Get user info success!");
    } 
    else {
        res.result = 0;
    } 

    GET_MESSAGE_BUFF(buf);
    size_t len = general_res__pack(&res, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_UPDATE_USER_INFO_ANS, buf, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
int32_t CxyManager::AppParseSetProperty(json_object *req)
{
    char paraBuff[256] = {0};
    int ifresult = 1;
    json_object *modelFanPct = json_object_object_get(req, "modelFanPct");
    if (modelFanPct != NULL && json_object_is_type(modelFanPct, json_type_int)){
        CrLogD("property id: modelFanPct, value: %d\n", json_object_get_int(modelFanPct));

        MultiFan multiFan = MULTI_FAN__INIT;
        multiFan.has_multi_fan_model = 1;
        multiFan.multi_fan_model = json_object_get_int(modelFanPct);
        
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.fan = &multiFan;

		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *caseFanPct = json_object_object_get(req, "caseFanPct");
    if (caseFanPct != NULL && json_object_is_type(caseFanPct, json_type_int)){
        CrLogD("property id: caseFanPct, value: %d\n", json_object_get_int(caseFanPct));

        MultiFan multiFan = MULTI_FAN__INIT;
        multiFan.has_multi_fan_case = 1;
        multiFan.multi_fan_case = json_object_get_int(caseFanPct);
        
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.fan = &multiFan;

		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *auxiliaryFanPct = json_object_object_get(req, "auxiliaryFanPct");
    if (auxiliaryFanPct != NULL && json_object_is_type(auxiliaryFanPct, json_type_int)){
        CrLogD("property id: auxiliaryFanPct, value: %d\n", json_object_get_int(auxiliaryFanPct));

        MultiFan multiFan = MULTI_FAN__INIT;
        multiFan.has_multi_fan_auxiliary = 1;
        multiFan.multi_fan_auxiliary = json_object_get_int(auxiliaryFanPct);
        
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.fan = &multiFan;

		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *nozzleTemp2 = json_object_object_get(req, "nozzleTemp2");
    if (nozzleTemp2 != NULL && json_object_is_type(nozzleTemp2, json_type_int))
    {
        CrLogD("property id: nozzleTemp2, value: %d\n", json_object_get_int(nozzleTemp2));

        Extruder extruder = EXTRUDER__INIT;
        extruder.has_extruder = 1;
        extruder.extruder = json_object_get_int(nozzleTemp2);

        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.nozzletemp = &extruder;
        
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *bedTemp2 = json_object_object_get(req, "bedTemp2");
    if (bedTemp2 != NULL && json_object_is_type(bedTemp2, json_type_int))
    {
        CrLogD("property id: bedTemp2, value: %d\n", json_object_get_int(bedTemp2));

        HeaterBed heaterBed = HEATER_BED__INIT;
        if (GetAppPrintState()->model == CR_10_H1) {
            heaterBed.has_heater_bed_0 = 1;
            heaterBed.heater_bed_0 = json_object_get_int(bedTemp2);
        }
        else {
            heaterBed.has_heater_bed = 1;
            heaterBed.heater_bed = json_object_get_int(bedTemp2);
        }

        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.bedtemp = &heaterBed;
        
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *print = json_object_object_get(req, "print");
    if (print != NULL && json_object_is_type(print, json_type_string))
    {
        // 获取下载路径
        std::string downloadPath = "";
        // if (access(m_appPrintState.uDiskPath, F_OK) == 0)
        //     downloadPath = std::string(m_appPrintState.uDiskPath);
        // else if (access(m_appPrintState.sdPath, F_OK) == 0)
            downloadPath = std::string(m_appPrintState.sdPath);

        // 存在外部储存，开始下载文件
        if (m_downloadGcodeClient == NULL && downloadPath.length() > 2) {
            // 判断是否实时设置打印前校准
            json_object *enableSelfTest = json_object_object_get(req, "enableSelfTest");
            if (enableSelfTest != NULL && json_object_is_type(enableSelfTest, json_type_int)){
                CrLogD("property id: enableSelfTest, value: %d\n", json_object_get_int(enableSelfTest));
                
                AppControlPrint control = APP_CONTROL_PRINT__INIT;
                control.has_enableselftest = 1;
                control.enableselftest = json_object_get_int(enableSelfTest);

                GET_MESSAGE_BUFF(buff);
                size_t len = app_control_print__pack(&control, buff);
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
                SendProcessMsgBuff(&send, size);
            }

            CrLogD("property id: print, value: %s", json_object_get_string(print));
            CrLogD("property id: download path: %s\n", downloadPath.c_str());
            // 下载gcode压缩文件
            m_downloadGcodeClient = new CxyDownload();
            CxyDownloadOptions_t options;
            options.url = std::string(json_object_get_string(print));
            options.filePath = std::string(downloadPath.c_str());
            options.conStateCb = [this](int state, std::string res) {return DownloadStateCallback(state, res);};
            options.progressCb = [this](int res) {return DownloadProgressCallback(res);};
            m_downloadGcodeClient->Init(options);
            m_downloadGcodeClient->Start();
        }
        else {
            if (m_downloadGcodeClient != NULL) CrLogW("downloading gcode file\n");
            ReportAppControlPrint(0);
        }
	}

    json_object *printId = json_object_object_get(req, "printId");
    if (printId != NULL && json_object_is_type(printId, json_type_string))
    {
        CrLogD("property id: printId, value: %s\n", json_object_get_string(printId));
        memset(m_appPrintState.printId, 0, sizeof(m_appPrintState.printId));
        memcpy(m_appPrintState.printId, json_object_get_string(printId), json_object_get_string_len(printId));
        DelectAppPrintState(false);
        
        json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
        if (!iotConfig) {
            CrLogW("no tb info file\n");
            iotConfig = json_object_new_object();
        }

        json_object *otherInfoObj = json_object_object_get(iotConfig, "cxy_other_info");
        if (!otherInfoObj){
            otherInfoObj = json_object_new_object();
            json_object_object_add(otherInfoObj, "printid", json_object_new_string(m_appPrintState.printId));
            json_object_object_add(iotConfig, "cxy_other_info", otherInfoObj);
        }else{
            json_object *printidObj = json_object_object_get(otherInfoObj, "printid");
            if(printidObj){
                if(strcmp(json_object_get_string(printidObj),m_appPrintState.printId) != 0){
                    json_object_object_del(otherInfoObj, "printid");
                    json_object_object_add(otherInfoObj, "printid", json_object_new_string(m_appPrintState.printId));
                }                  
            }else{
                json_object_object_add(otherInfoObj, "printid", json_object_new_string(m_appPrintState.printId));
            }    
        }  
        AppAesEncryptToFile(GetUserIotTbInfoFilePtah(), json_object_to_json_string(iotConfig));
        json_object_put(iotConfig); 
	}

    json_object *token = json_object_object_get(req, "token");
    if (token != NULL && json_object_is_type(token, json_type_string))
    {
        CrLogD("property id: token, value: %s\n", json_object_get_string(token));
        memset(m_appPrintState.appToken, 0, sizeof(m_appPrintState.appToken));
        memcpy(m_appPrintState.appToken, json_object_get_string(token), json_object_get_string_len(token));
	}

    json_object *jwtToken = json_object_object_get(req, "jwtToken");
    if (jwtToken != NULL && json_object_is_type(jwtToken, json_type_string))
    {
        CrLogD("property id: jwtToken, value: %s\n", json_object_get_string(jwtToken));
        
        memset(m_appPrintState.appJwtToken, 0, sizeof(m_appPrintState.appJwtToken));
        memcpy(m_appPrintState.appJwtToken, json_object_get_string(jwtToken), json_object_get_string_len(jwtToken));
        
        json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
        if (!iotConfig) {
            CrLogW("no tb info file\n");
            iotConfig = json_object_new_object();
        }

        json_object *otherInfoObj = json_object_object_get(iotConfig, "cxy_other_info");
        if (!otherInfoObj){
            otherInfoObj = json_object_new_object();
            json_object_object_add(otherInfoObj, "jwt_token", json_object_new_string(m_appPrintState.appJwtToken));
            json_object_object_add(iotConfig, "cxy_other_info", otherInfoObj);
        }else{
            json_object *jwt_token = json_object_object_get(otherInfoObj, "jwt_token");
            if(jwt_token){
                 json_object_object_del(otherInfoObj, "jwt_token");
            }
            json_object_object_add(otherInfoObj, "jwt_token", json_object_new_string(m_appPrintState.appJwtToken));
        }
        
        AppAesEncryptToFile(GetUserIotTbInfoFilePtah(), json_object_to_json_string(iotConfig));
        json_object_put(iotConfig);

        // 获取信息
        if (m_downloadGcodeClient == NULL) UserUpdateUserInfo();
	}

    json_object *stop = json_object_object_get(req, "stop");
    if (stop != NULL && json_object_is_type(stop, json_type_int))
    {
        CrLogD("property id: stop, value: %d\n", json_object_get_int(stop));
        
		AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_stop = 1;
        control.stop = json_object_get_int(stop);
        
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
	}

    json_object *pause = json_object_object_get(req, "pause");
    if (pause != NULL && json_object_is_type(pause, json_type_int))
    {
        CrLogD("property id: pause, value: %d\n", json_object_get_int(pause));

		AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_pause = 1;
        control.pause = json_object_get_int(pause);
        
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
	}

    json_object *repoPlrStatus = json_object_object_get(req, "repoPlrStatus");
    if (repoPlrStatus != NULL && json_object_is_type(repoPlrStatus, json_type_int))
    {
        CrLogD("property id: repoPlrStatus, value: %d\n", json_object_get_int(repoPlrStatus));

		AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_powerloss = 1;
        switch (json_object_get_int(repoPlrStatus))
        {
            case 5: control.powerloss = 1; break;
            case 6: control.powerloss = 0; break;
        }
        
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
	}

    json_object *gcodeCmd = json_object_object_get(req, "gcodeCmd");
    if (gcodeCmd != NULL && json_object_is_type(gcodeCmd, json_type_string))
    {
        CrLogD("property id: gcodeCmd, value: %s\n", json_object_get_string(gcodeCmd));

        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_gcodecmd = 1;
        control.gcodecmd.data = (uint8_t*)json_object_get_string(gcodeCmd);
        control.gcodecmd.len = json_object_get_string_len(gcodeCmd) + 1;

		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *setPrinterPowerOff = json_object_object_get(req, "setPrinterPowerOff");
    if (setPrinterPowerOff != NULL && json_object_is_type(setPrinterPowerOff, json_type_int))
    {
        CrLogD("property id: setPrinterPowerOff, value: %d\n", json_object_get_int(setPrinterPowerOff));
    }

    json_object *times_left_toprint = json_object_object_get(req, "times_left_toprint");
    if (times_left_toprint != NULL && json_object_is_type(times_left_toprint, json_type_int))
    {
        CrLogD("property id: times_left_toprint, value: %d\n", json_object_get_int(times_left_toprint));
    }

    json_object *ReqPrinterPara = json_object_object_get(req, "ReqPrinterPara");
    if (ReqPrinterPara != NULL && json_object_is_type(ReqPrinterPara, json_type_int))
    {
        CrLogD("property id: ReqPrinterPara, value: %d\n", json_object_get_int(ReqPrinterPara));
    }

    json_object *setFeedratePct = json_object_object_get(req, "setFeedratePct");
    if (setFeedratePct != NULL && json_object_is_type(setFeedratePct, json_type_int))
    {
        CrLogD("property id: setFeedratePct, value: %d\n", json_object_get_int(setFeedratePct));
        
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        snprintf(paraBuff, 256, "S%d", json_object_get_int(setFeedratePct));
        CrLogD("property id: setFeedratePct, value: %s\n", paraBuff);
        control.has_setfeedratepct = 1;
        control.setfeedratepct.data = (uint8_t*)paraBuff;
        control.setfeedratepct.len = strlen(paraBuff) + 1;
        
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *setFlowratePct = json_object_object_get(req, "setFlowratePct");
    if (setFlowratePct != NULL && json_object_is_type(setFlowratePct, json_type_int))
    {
        CrLogD("property id: setFlowratePct, value: %d\n", json_object_get_int(setFlowratePct));

        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        snprintf(paraBuff, 256, "S%d", json_object_get_int(setFlowratePct));
        control.has_setflowratepct = 1;
        control.setflowratepct.data = (uint8_t*)paraBuff;
        control.setflowratepct.len = strlen(paraBuff) + 1;

		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *setPosition = json_object_object_get(req, "setPosition");
    if (setPosition != NULL && json_object_is_type(setPosition, json_type_string))
    {
        CrLogD("property id: setPosition, value: %s\n", json_object_get_string(setPosition));

        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_setposition = 1;
        control.setposition.data = (uint8_t*)json_object_get_string(setPosition);
        control.setposition.len = json_object_get_string_len(setPosition) + 1;

		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *autohome = json_object_object_get(req, "autohome");
    if (autohome != NULL && json_object_is_type(autohome, json_type_int))
    {
        CrLogD("property id: autohome, value: %d\n", json_object_get_int(autohome));
        
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_autohome = 1;
        control.autohome = json_object_get_int(autohome);

		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *opGcodeFile = json_object_object_get(req, "opGcodeFile");
    if (opGcodeFile != NULL && json_object_is_type(opGcodeFile, json_type_string))
    {
        CrLogD("property id: opGcodeFile, value: %s\n", json_object_get_string(opGcodeFile));

        char * valuestring = (char *)json_object_get_string(opGcodeFile);
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_print = 1;
        control.print.data = (uint8_t*)valuestring;
        control.print.len = strlen(valuestring) + 1;

        GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *exportLog = json_object_object_get(req, "exportLog");
    if (exportLog != NULL && json_object_is_type(exportLog, json_type_int))
    {
        int ctl = json_object_get_int(exportLog);
        CrLogD("property id: exportLog, value: %d\n", ctl);
        
        if(ctl == 1){
            int ret = AppUploadLog();
            json_object *resObj = json_object_new_object();
            if(ret == 0){
                json_object_object_add(resObj, "code", json_object_new_int(0));
                json_object_object_add(resObj, "msg", json_object_new_string("success"));  
            }else if(ret == -1){
                json_object_object_add(resObj, "code", json_object_new_int(-1));
                json_object_object_add(resObj, "msg", json_object_new_string("fail"));                 
            }
            std::string response = json_object_to_json_string(resObj);
            m_mqttServerClient.ResponseRpc(response);
            json_object_put(resObj);
        }
    }

    json_object *formatTf = json_object_object_get(req, "formatTf");
    if (formatTf != NULL && json_object_is_type(formatTf, json_type_int))
    {
        CrLogD("property id: formatTf, value: %d\n", json_object_get_int(formatTf));
    }

    json_object *upgrade = json_object_object_get(req, "upgrade");
    if (upgrade != NULL && json_object_is_type(upgrade, json_type_string))
    {
		CrLogD("property id: upgrade, value: %s\n", json_object_get_string(upgrade));

        int urlLen = json_object_get_string_len(upgrade);
        if (urlLen > 0)
        {
            char downlodeUrl[urlLen + 1];
            memset(downlodeUrl, 0, urlLen + 1);
            memcpy(downlodeUrl, json_object_get_string(upgrade), urlLen);
    
            // 判断是上位机升级，还是下位机升级
            UpgradeTarget_t upgradeType;
            if (strstr(downlodeUrl, "img")) upgradeType = UPGRADE_TARGET_LINUX;
            else upgradeType = UPGRADE_TARGET_MCU1;
            
            NewImageInfo_t info;
            info.url = downlodeUrl;

            // 更新设备系统版本信息
            DevSysInfo_t sysInfo;
            sysInfo.model = GetAppPrintState()->model_str;
            sysInfo.sysVersion = GetAppPrintState()->sys_version;
            sysInfo.hwVersion = GetAppPrintState()->hw_version;
            sysInfo.mcuSysVersion = GetAppPrintState()->fw_version;
            sysInfo.mcuHwVersion = GetAppPrintState()->hw1_version;
            sysInfo.updataInfoCb = [this](UpgradeState_t state, int res, UpgradeTarget_t target) {return UpgradeStateResponse(state, res, target);};
            m_startOtaUpgrade.UpdataVerionOptions(sysInfo);
            // 开始升级
            m_startOtaUpgrade.UserStartUpgrade(info, upgradeType);
        }
        else {
            // 取消下载
            m_startOtaUpgrade.UserCancelUpgrade();
        }
    }

    json_object *livestream = json_object_object_get(req, "livestream");
    if (livestream != NULL && json_object_is_type(livestream, json_type_int))
    {
        CrLogD("property id: livestream, value: %d\n", json_object_get_int(livestream));
        
        json_object *webrtc = json_object_new_object();
        json_object_object_add(webrtc, "method", json_object_new_string("set"));
        std::string params = json_object_to_json_string(req); 
        json_object_object_add(webrtc, "params", json_tokener_parse(params.c_str()));
        std::string send = json_object_to_json_string(webrtc); 
        json_object_put(webrtc);
        if (access(GetDefaultWebrtcPipePath(), F_OK) != 0){
            int ret;
	        ret = mkfifo(GetDefaultWebrtcPipePath(), 0775);			
	        if(ret < 0){
                CrLogE("Create /tmp/uvc_fifo failed!\n");
                return -1;
	        }
        }
        char cmd[512] = {0};
        snprintf(cmd,sizeof(cmd),"echo \'webRtc=%s\' > %s &",send.c_str(),GetDefaultWebrtcPipePath()) ;
        system(cmd);
    }

    json_object *videoElapse = json_object_object_get(req, "videoElapse");
    if (videoElapse != NULL && json_object_is_type(videoElapse, json_type_int))
    {
        CrLogD("property id: videoElapse, value: %d\n", json_object_get_int(videoElapse));

        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_videoelapse = 1;
        control.videoelapse = json_object_get_int(videoElapse);
        
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *nozzleMoveSnapshot = json_object_object_get(req, "nozzleMoveSnapshot");
    if (nozzleMoveSnapshot != NULL && json_object_is_type(nozzleMoveSnapshot, json_type_int))
    {
        CrLogD("property id: nozzleMoveSnapshot, value: %d\n", json_object_get_int(nozzleMoveSnapshot));

        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_nozzlemovesnapshot = 1;
        control.nozzlemovesnapshot = json_object_get_int(nozzleMoveSnapshot);
        
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *enableAITest = json_object_object_get(req, "enableAITest");
    if (enableAITest != NULL && json_object_is_type(enableAITest, json_type_int)){
        CrLogD("property id: enableAITest, value: %d\n", json_object_get_int(enableAITest));

        AiControlPrefer aiPrefer = AI_CONTROL_PREFER__INIT;
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        aiPrefer.has_sw = 1;
        aiPrefer.sw = json_object_get_int(enableAITest);
        control.aipre= &aiPrefer;
        
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    // json_object *faultReminder = json_object_object_get(req, "faultReminder");
    // if (faultReminder != NULL && json_object_is_type(faultReminder, json_type_int)){
    //     CrLogD("property id: faultReminder, value: %d\n", json_object_get_int(faultReminder));
    //     AiControlPrefer aiPrefer = AI_CONTROL_PREFER__INIT;
    //     AppControlPrint control = APP_CONTROL_PRINT__INIT;
    //     aiPrefer.has_detection = 1;
    //     aiPrefer.detection = json_object_get_int(faultReminder);
    //     control.aipre= &aiPrefer;
        
	// 	GET_MESSAGE_BUFF(buff);
    //     size_t len = app_control_print__pack(&control, buff);
    //     CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
    //     SendProcessMsgBuff(&send, size);
    // }

    json_object *enableFaultStop = json_object_object_get(req, "enableFaultStop");
    if (enableFaultStop != NULL && json_object_is_type(enableFaultStop, json_type_int)){
        CrLogD("property id: enableFaultStop, value: %d\n", json_object_get_int(enableFaultStop));

        AiControlPrefer aiPrefer = AI_CONTROL_PREFER__INIT;
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        aiPrefer.has_pauseprint = 1;
        aiPrefer.pauseprint = json_object_get_int(enableFaultStop);
        control.aipre= &aiPrefer;
        
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *firstFaultReminder = json_object_object_get(req, "firstFaultReminder");
    if (firstFaultReminder != NULL && json_object_is_type(firstFaultReminder, json_type_int)){
        CrLogD("property id: firstFaultReminder, value: %d\n", json_object_get_int(firstFaultReminder));

        AiControlPrefer aiPrefer = AI_CONTROL_PREFER__INIT;
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        aiPrefer.has_firstfloor = 1;
        aiPrefer.firstfloor = json_object_get_int(firstFaultReminder);
        control.aipre= &aiPrefer;
        
		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *led = json_object_object_get(req, "led");
    if (led != NULL && json_object_is_type(led, json_type_int)){
        CrLogD("property id: led, value: %d\n", json_object_get_int(led));

        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_lightsw = 1;
        control.lightsw = json_object_get_int(led);

		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *enableSelfTest = json_object_object_get(req, "enableSelfTest");
    if (enableSelfTest != NULL && json_object_is_type(enableSelfTest, json_type_int)){
        CrLogD("property id: enableSelfTest, value: %d\n", json_object_get_int(enableSelfTest));
        
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_enableselftest = 1;
        control.enableselftest = json_object_get_int(enableSelfTest);

		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *autoLeveling = json_object_object_get(req, "autoLeveling");
    json_object *chatteringOpt = json_object_object_get(req, "chatteringOpt");
    if (autoLeveling != NULL && json_object_is_type(autoLeveling, json_type_int) &&
        chatteringOpt != NULL && json_object_is_type(chatteringOpt, json_type_int))
    {
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        if(json_object_get_int(autoLeveling) && json_object_get_int(chatteringOpt) == 1){
            control.has_autoleveling = 1;
            control.autoleveling = json_object_get_int(autoLeveling);
            control.has_chatteringopt = 1;
            control.chatteringopt = json_object_get_int(chatteringOpt);
            m_appPrintState.autoLevelProgress = 1;
            DelectAppPrintState(false);

        }else if(json_object_get_int(autoLeveling) && json_object_get_int(chatteringOpt) == 0){
            control.has_autoleveling = 1;
            control.autoleveling = json_object_get_int(autoLeveling);
            m_appPrintState.autoLevelProgress = 1;
            m_appPrintState.chatteringOpt = 0;
            DelectAppPrintState(false);
        }else if(!json_object_get_int(autoLeveling) && json_object_get_int(chatteringOpt) == 1){
            control.has_chatteringopt = 1;
            control.chatteringopt = json_object_get_int(chatteringOpt);
            m_appPrintState.chatteringOpt = 1;
            m_appPrintState.autoLevelProgress = 0;
            DelectAppPrintState(false);
        }
        GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);  
    }

    json_object *reNameGcode = json_object_object_get(req, "reNameGcode");
    if (reNameGcode != NULL && json_object_is_type(reNameGcode, json_type_object))
    {
        json_object *filePath = json_object_object_get(reNameGcode, "filePath");
        json_object *type = json_object_object_get(reNameGcode, "type");
        json_object *reName = json_object_object_get(reNameGcode, "reName");
        if (filePath != NULL && json_object_is_type(filePath, json_type_string) && 
            type != NULL && json_object_is_type(type, json_type_int) &&
            reName != NULL && json_object_is_type(reName, json_type_string))
        {
            json_object *resObj = json_object_new_object();
            const char *sourceFilePath = json_object_get_string(filePath);
            const char *newFileName = json_object_get_string(reName);
            int32_t pathType = json_object_get_int(type);
            CrLogI("sourceFilePath = %s", sourceFilePath);
            CrLogI("newFileName = %s", newFileName);
            CrLogI("pathType = %d", pathType);

            // 判断文件路径是否合法
            if ((pathType == 1 && strncmp(sourceFilePath, m_appPrintState.sdPath, strlen(m_appPrintState.sdPath)) != 0) ||
                (pathType == 2 && strncmp(sourceFilePath, m_appPrintState.uDiskPath, strlen(m_appPrintState.uDiskPath)) != 0) ||
                strchr(newFileName, '/'))
            {
                CrLogW("reNameGcode fail\n");
                json_object_object_add(resObj, "code", json_object_new_int(-1));
                json_object_object_add(resObj, "msg", json_object_new_string("fail"));
            }
            else
            {
                char tagetPath[512] = {0};
                if (json_object_get_int(type) == 1){
                    snprintf(tagetPath, sizeof(tagetPath), "%s/%s", m_appPrintState.sdPath, newFileName);
                }else if (json_object_get_int(type) == 2){
                    snprintf(tagetPath, sizeof(tagetPath), "%s/%s", m_appPrintState.uDiskPath, newFileName);
                }
                CrLogI("taget path = %s\n", tagetPath);

                rename(sourceFilePath, tagetPath);
                system("sync");
                
                json_object_object_add(resObj, "code", json_object_new_int(0));
                json_object_object_add(resObj, "msg", json_object_new_string("success"));    
            }

            std::string response = json_object_to_json_string(resObj);
            m_mqttServerClient.ResponseRpc(response);
            json_object_put(resObj);
        }
    }

    json_object *ctrlVideoFiles = json_object_object_get(req, "ctrlVideoFiles");
    if (ctrlVideoFiles != NULL && json_object_is_type(ctrlVideoFiles, json_type_object))
    {
        int ret = -1;
        json_object *cmd = json_object_object_get(ctrlVideoFiles, "cmd");
        json_object *printId = json_object_object_get(ctrlVideoFiles, "printId");
        json_object *file = json_object_object_get(ctrlVideoFiles, "file");
        if(cmd&& json_object_is_type(cmd, json_type_string)
        &&printId&& json_object_is_type(printId, json_type_string)
        &&file&& json_object_is_type(file, json_type_string))
        {
            const char* cmdstr = json_object_get_string(cmd);
            const char* printidstr = json_object_get_string(printId);
            const char* filestr = json_object_get_string(file); 
            CrLogI("iot ctrlVideoFiles cmd = %s\n", cmdstr);
            CrLogI("iot ctrlVideoFiles printId = %s\n", printidstr);
            CrLogI("iot ctrlVideoFiles filestr = %s\n", filestr);
            if(!strcmp(cmdstr,"remove"))
            {
                ret = ProcVideoRemove(printidstr,filestr);
            }else if(!strcmp(cmdstr,"rename"))
            {
                json_object *targetname = json_object_object_get(ctrlVideoFiles, "targetname");
                string targetnamestr = "";
                if(targetname&& json_object_is_type(targetname, json_type_string))
                {
	 	            targetnamestr = json_object_get_string(targetname);
                    ret = ProcVideoRename(printidstr,filestr,targetnamestr);
		        }
            }else if(!strcmp(cmdstr,"upload"))
            {
		        json_object *token = json_object_object_get(ctrlVideoFiles, "token");
                string tokenstr = "";
                if(token&& json_object_is_type(token, json_type_string))
                    tokenstr = json_object_get_string(token);
                ret = ProcVideoUpload(printidstr,filestr,tokenstr);
                ifresult = 0;
                if(ret != 0)
                    ControlVideoFilesResult(ret);
            }
            else{
                ControlVideoFilesResult(-1);
            }
        }
    }    

    json_object *deleteLocalFiles = json_object_object_get(req, "deleteLocalFiles");
    if (deleteLocalFiles != NULL && json_object_is_type(deleteLocalFiles, json_type_array))
    {
        json_object *resObj = json_object_new_object();
        int flag = 0;
        for(int i = 0; i < (int)json_object_array_length(deleteLocalFiles); i++){
             json_object * child_obj = json_object_array_get_idx(deleteLocalFiles, i);
             if(json_object_is_type(child_obj, json_type_string))
             {
                const char *fileName = json_object_get_string(child_obj);
                CrLogI("iot remove %s", fileName);

                // 判断文件路径是否合法
                if ((strncmp(fileName, m_appPrintState.sdPath, strlen(m_appPrintState.sdPath)) == 0) ||
                    (strncmp(fileName, m_appPrintState.uDiskPath, strlen(m_appPrintState.uDiskPath)) == 0))
                {
                    remove(fileName);
                    system("sync");
                }
                else CrLogW("illegal file name\n");
            }
            if(flag == 0){
                json_object_object_add(resObj, "code", json_object_new_int(0));
                json_object_object_add(resObj, "msg", json_object_new_string("success"));    
            }
        }
        std::string response = json_object_to_json_string(resObj);
        m_mqttServerClient.ResponseRpc(response);
        json_object_put(resObj);
    }

    json_object *cleanSpace = json_object_object_get(req, "cleanSpace");
    if (cleanSpace != NULL && json_object_is_type(cleanSpace, json_type_int))
    {
        CrLogD("property id: cleanSpace, value: %d\n", json_object_get_int(cleanSpace));
        
        //send spaceInfo back
        if(json_object_get_int(cleanSpace) == 1){
            CrLogI("iot clean log ....");
            char cmd[256] = {0};
            char tmp[128] = {0};
            snprintf(cmd, sizeof(cmd), "rm -rf %s/* && sync", GetUserDataLogDirPtah());

            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) {
                CrLogW("system fail! res = %s\n", sysRes);
                CrLogW("clean space fail\n");
                json_object *resObj = json_object_new_object();
                json_object_object_add(resObj, "code", json_object_new_int(-1));
                json_object_object_add(resObj, "msg", json_object_new_string("fail"));
                std::string response = json_object_to_json_string(resObj);
                m_mqttServerClient.ResponseRpc(response);
                json_object_put(resObj);                
            }else{
                double userLogSize = (double)GetDirectorySize(GetUserDataLogDirPtah()) / (1024 * 1024);
                json_object *resObj = json_object_new_object();
                snprintf(tmp, 128, "%0.2f", userLogSize);
                json_object_object_add(resObj, "log", json_object_new_double_s(userLogSize, tmp));
                json_object_object_add(resObj, "code", json_object_new_int(0));
                json_object_object_add(resObj, "msg", json_object_new_string("success"));
                std::string response = json_object_to_json_string(resObj);
                m_mqttServerClient.ResponseRpc(response);
                json_object_put(resObj);
            }
        }else if(json_object_get_int(cleanSpace) == 2){
            CrLogI("iot clean other ....");
            char cmd[256] = {0};
            char tmp[128] = {0};
            snprintf(cmd, sizeof(cmd), "rm -rf %s/* && sync",GetuserPrintHistoryPtah());

            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) {
                CrLogW("system fail! res = %s\n", sysRes);
                CrLogW("clean space fail\n");
                json_object *resObj = json_object_new_object();
                json_object_object_add(resObj, "code", json_object_new_int(-1));
                json_object_object_add(resObj, "msg", json_object_new_string("fail"));
                std::string response = json_object_to_json_string(resObj);
                m_mqttServerClient.ResponseRpc(response);
                json_object_put(resObj);                
            }else{
                double userHistorySize = (double)GetDirectorySize(GetuserPrintHistoryPtah()) / (1024 * 1024);
                json_object *resObj = json_object_new_object();
                snprintf(tmp, 128, "%0.2f", userHistorySize);
                json_object_object_add(resObj, "other", json_object_new_double_s(userHistorySize, tmp));
                json_object_object_add(resObj, "code", json_object_new_int(0));
                json_object_object_add(resObj, "msg", json_object_new_string("success"));
                std::string response = json_object_to_json_string(resObj);
                m_mqttServerClient.ResponseRpc(response);
                json_object_put(resObj);
            }
        }
    }

    json_object *feed = json_object_object_get(req, "feed");
    json_object *feedStateTemp2 = json_object_object_get(req, "feedStateTemp2");
    if (feed != NULL && json_object_is_type(feed, json_type_int) && 
        feedStateTemp2 != NULL && json_object_is_type(feedStateTemp2, json_type_int))
    {
        CrLogD("property id: feed, value: %d\n", json_object_get_int(feed));
        CrLogD("property id: feedStateTemp2, value: %d\n", json_object_get_int(feedStateTemp2));

        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        LoadQuitMaterial cmd = LOAD_QUIT_MATERIAL__INIT;
        cmd.has_targettemp = 1;
        cmd.targettemp = json_object_get_int(feedStateTemp2);
        m_appPrintState.feedStateTemp2 = json_object_get_int(feedStateTemp2);
        DelectAppPrintState(false);
        if(json_object_get_int(feed) == 1){
            control.loadmaterial = &cmd;
        }else if(json_object_get_int(feed) == 0){
            control.quitmaterial = &cmd;
        }

		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    json_object *speedMode = json_object_object_get(req, "speedMode");
    if (speedMode != NULL && json_object_is_type(speedMode, json_type_int)){
        CrLogD("property id: speedMode, value: %d\n", json_object_get_int(speedMode));
        
        AppControlPrint control = APP_CONTROL_PRINT__INIT;
        control.has_speedmode = 1;
        control.speedmode = json_object_get_int(speedMode);

		GET_MESSAGE_BUFF(buff);
        size_t len = app_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }

	return ifresult;
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
int32_t CxyManager::AppParseGetProperty(json_object *req)
{
    int32_t iRet = 0;
    json_object *allPrintTime = json_object_object_get(req, "allPrintTime");
    if (allPrintTime != NULL && json_object_is_type(allPrintTime, json_type_int)){
        CrLogI("property id: allPrintTime, value: %d\n", json_object_get_int(allPrintTime));
		if(json_object_get_int(allPrintTime) == 1){
            //ReportAllPrintTime();
            ReportTotalTime();
		}
    }

    json_object *pFileList = json_object_object_get(req, "pFileList");
    if (pFileList != NULL && json_object_is_type(pFileList, json_type_int))
    {
        CrLogD("property id: pFileList, value: %d\n", json_object_get_int(pFileList));
        int index = json_object_get_int(pFileList) - 1;
        ReportGcodeFileInfo(index, 0);
    }

    json_object *uFileList = json_object_object_get(req, "uFileList");
    if (uFileList != NULL && json_object_is_type(uFileList, json_type_int))
    {
        CrLogD("property id: uFileList, value: %d\n", json_object_get_int(uFileList));
        int index = json_object_get_int(uFileList) - 1;
        ReportGcodeFileInfo(index, 1);
    }

    json_object *getVideoFiles = json_object_object_get(req, "getVideoFiles");
    if (getVideoFiles != NULL && json_object_is_type(getVideoFiles, json_type_int))
    {
        CrLogD("property id: getVideoFiles, value: %d\n", json_object_get_int(getVideoFiles));
        ReportVideoFilesInfo();
    } 

    json_object *getElapseInfor = json_object_object_get(req, "getElapseInfor");
    if (getElapseInfor != NULL)
    {
        json_object *pageNo = json_object_object_get(req, "pageNo");
        if (pageNo != NULL && json_object_is_type(pageNo, json_type_int))
        {
            CrLogD("property id: getElapseInfor, pageid: %d\n", json_object_get_int(pageNo));
            ReportVideoFilesInfo(json_object_get_int(pageNo));
        } 
    }

    json_object *getRecDetail = json_object_object_get(req, "getRecDetail");
    if (getRecDetail != NULL)
    {
        json_object *pageNo = json_object_object_get(req, "pageNo");
        json_object *printId = json_object_object_get(req, "printId");
        if (pageNo != NULL && json_object_is_type(pageNo, json_type_int)
        &&printId != NULL && json_object_is_type(printId, json_type_string))
        {
            CrLogD("property id: getRecDetail, pageid: %d\n", json_object_get_int(pageNo));
            ReportRecDetail(json_object_get_string(printId),json_object_get_int(pageNo));
        } 
    }
    
    json_object *getRecOutline = json_object_object_get(req, "getRecOutline");
    if (getRecOutline != NULL)
    {
        json_object *pageNo = json_object_object_get(req, "pageNo");
        if (pageNo != NULL && json_object_is_type(pageNo, json_type_int))
        {
            CrLogD("property id: getRecOutline, pageid: %d\n", json_object_get_int(pageNo));
            ReportRecFilesInfo(json_object_get_int(pageNo));
        } 
    }   

    json_object *spaceInfo = json_object_object_get(req, "spaceInfo");
    if (spaceInfo != NULL && json_object_is_type(spaceInfo, json_type_int))
    {
        char tmp[128];
        char diskName[]="/usr/data";
        CrLogD("property id: spaceInfo, value: %d\n", json_object_get_int(spaceInfo));
        int cmd = json_object_get_int(spaceInfo) ;
        if(cmd == 1){
            double diskTotalSize = GetSystemMemorySize(m_appPrintState.model).total_size;
            //double diskUsedSize = (double)GetDiskUsedSize(diskName)/ (1024 * 1024);
            double diskAvailableSize = (double)GetDiskAvailableSize(diskName) / (1024 * 1024);
            double diskUsedSize = diskTotalSize - diskAvailableSize;
            double userLogSize = (double)GetDirectorySize(GetUserDataLogDirPtah()) / (1024 * 1024);
            double userVideoSize = (double)GetDirectorySize(GetUserDelayImageDirPtah()) / (1024 * 1024);
            double userHistorySize = (double)GetDirectorySize(GetuserPrintHistoryPtah()) / (1024 * 1024);
            double userGcodeSize = (double)GetDirectorySize(m_appPrintState.sdPath) / (1024 * 1024);
            double userOtherSize = diskUsedSize - userGcodeSize - userVideoSize - userLogSize;
            json_object *resObj = json_object_new_object();
            
            snprintf(tmp, 128, "%0.2f", diskTotalSize);
            json_object_object_add(resObj, "totalSize", json_object_new_double_s(diskTotalSize, tmp));
            memset(tmp, 0, 128);
            snprintf(tmp, 128, "%0.2f", userGcodeSize);
            json_object_object_add(resObj, "gcode", json_object_new_double_s(userGcodeSize, tmp));
            memset(tmp, 0, 128);
            snprintf(tmp, 128, "%0.2f", userVideoSize);
            json_object_object_add(resObj, "video", json_object_new_double_s(userVideoSize, tmp));
            memset(tmp, 0, 128);
            snprintf(tmp, 128, "%0.2f", userLogSize);
            json_object_object_add(resObj, "log", json_object_new_double_s(userLogSize, tmp));
            memset(tmp, 0, 128);
            snprintf(tmp, 128, "%0.2f", userOtherSize);
            json_object_object_add(resObj, "other", json_object_new_double_s(userOtherSize, tmp));
            memset(tmp, 0, 128);
            snprintf(tmp, 128, "%0.2f", diskUsedSize);
            json_object_object_add(resObj, "usedSize", json_object_new_double_s(diskUsedSize, tmp));
            memset(tmp, 0, 128);
            snprintf(tmp, 128, "%0.2f", diskAvailableSize);
            json_object_object_add(resObj, "canUseSize", json_object_new_double_s(diskAvailableSize, tmp));
            json_object_object_add(resObj, "code", json_object_new_int(0));
            json_object_object_add(resObj, "msg", json_object_new_string("success"));
            std::string response = json_object_to_json_string(resObj);
            m_mqttServerClient.ResponseRpc(response);
            json_object_put(resObj);
        }
    }

    return iRet ;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char} *request
 */
int CxyManager::AppParseMethod(std::string request)
{
    json_object *req = json_tokener_parse(request.c_str());
    if (req == NULL || !json_object_is_type(req, json_type_object))
    {
        CrLogE("get json object fail, str = %s\n", request.c_str());
        if (req) json_object_put(req);
        return -1;
    }
    CrLogI("AppParseMethod: %s", request.c_str());
    json_object *method = json_object_object_get(req, "method");
    json_object *params = json_object_object_get(req, "params");

    if (method != NULL && json_object_is_type(method, json_type_string) && json_object_get_string(method) &&
        params != NULL && json_object_is_type(params, json_type_object))
    {
        CrLogD("method: %s", json_object_get_string(method));
        if(!strcmp(json_object_get_string(method), "set")){
            if(AppParseSetProperty(params))
                ReportAppControlPrint(1);
		}
		else if(!strcmp(json_object_get_string(method), "get")){
			AppParseGetProperty(params);
		}
    }
	else{
		CrLogE("ignore:%s \n",request);
	}
    json_object_put(req);

	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {int} state
 */
int CxyManager::CreateDeviceBindingQrcode(void)
{
    // 获取生成二维码信息
    RegisterInfo_t devInfo;
    CxyHttpServer getInfoClient;
    if (getInfoClient.GetRegisterInfoFromFile(&devInfo) != 0) {
        CrLogE("get device sn or mac fail\n\n\n");
        return -1;
    }

    // 生成二维码信息
    std::string devBindQrcodeInfo = devInfo.sn + " " + devInfo.mac;
    CrLogD("qrcode Info = %s", devBindQrcodeInfo.c_str());

    // 判断储存路径是否存在
    if (access(GetUserTempDirPtah(), F_OK) != 0) {
        char cmd[254] = {0};
        snprintf(cmd, 254, "mkdir -p %s", GetUserTempDirPtah());

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }
    
    //生成二维码
    CxyQrCode m_userQrCode;
    int res = m_userQrCode.GenerateQrCode(GetCxyDeviceBindingQrCodePtah(), (char*)devBindQrcodeInfo.c_str(), devBindQrcodeInfo.length());
    if (res != 0) CrLogW("Failed to create QR code\n");

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
int CxyManager::CreateUserServiceQrcode(void)
{
    // 获取生成二维码信息
    std::string qrcodeInfo;
    CxyHttpServer getInfoClient;
    if (getInfoClient.GetUserServiceInfoFromFile(&qrcodeInfo) != 0) {
        CrLogE("get user service fail\n\n\n");
        return -1;
    }
    CrLogD("qrcode Info = %s", qrcodeInfo.c_str());

    // 判断储存路径是否存在
    if (access(GetUserTempDirPtah(), F_OK) != 0) {
        char cmd[254] = {0};
        snprintf(cmd, 254, "mkdir -p %s", GetUserTempDirPtah());

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }
    
    //生成二维码
    CxyQrCode m_userQrCode;
    int res = m_userQrCode.GenerateQrCode(GetCxyUserServiceQrCodePtah(), (char*)qrcodeInfo.c_str(), qrcodeInfo.length());
    if (res != 0) CrLogW("Failed to create QR code\n");

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {int} state
 */
int CxyManager::SyncMqttConnectState(int state)
{
    CrLogI("mqtt connect state = %d", state);
    MutableTypeData res = MUTABLE_TYPE_DATA__INIT;
    res.has_int_v = 1;
    res.int_v = state;

    GET_MESSAGE_BUFF(buff);
    size_t len = mutable_type_data__pack(&res, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, SERVER_CMD_APP_SYNC_MQTT_CONNECT, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} *state
 */
int CxyManager::ConStateCallback(int state)
{
    if (m_mqttConState != state)
    {
        CrLogI("mqtt connect status = %d\n", state);
        if (state == MQTT_THRUN_OK)
        {
            AttributesTelemetryStateInit();
            CreateDeviceBindingQrcode();
        }
        SyncMqttConnectState(state);
    }

    m_mqttConState = state;
	return 0;
}

/**
 * @description: 
 * @return {*}
 */
void CxyManager::GetPrintIdFromFile(void)
{
    // 打印状态空闲，不获取printid
    if (m_appPrintState.workState == 0) {
        CrLogI("Idle state does not get print id\n");
        return;
    }

    // 获取当前时间戳
    struct timeval startTime;
    gettimeofday(&startTime, NULL);
    // 生成本地打印id，如果有保存前一次printId，就用前一次的
    char localId[32] = {0};
    snprintf(localId, 32, "local_%ld", startTime.tv_sec);
    bzero(m_appPrintState.printId, sizeof(m_appPrintState.printId));
    strcat(m_appPrintState.printId, localId);
                
    // 判断文件是否存在
    if (access(GetUserIotTbInfoFilePtah(), F_OK) != 0) return;

    // 提取文件信息
    json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
    if (!iotConfig) {
        CrLogW("no tb info file\n");
        return;
    }

    // 获取创想云信息
    json_object *otherInfoObj = json_object_object_get(iotConfig, "cxy_other_info");
    if (otherInfoObj) {
        json_object *printidObj = json_object_object_get(otherInfoObj, "printid");
        if(printidObj) {
            bzero(m_appPrintState.printId, sizeof(m_appPrintState.printId));
            strcat(m_appPrintState.printId, json_object_get_string(printidObj));
        }
    }
    CrLogI("get print id = %s", m_appPrintState.printId);

    json_object_put(iotConfig);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
void CxyManager::Start(void)
{
    // 判断用户是否同意隐私协议
    while (1) {
        if (GetAppPrintState()->agreePrivacy > 0) break;
        sleep(1);
    }
    CrLogI("User agrees to privacy agreement\n");
    
    // 判断设备是否连接wifi
    #ifdef CROSS_COMPILE
    do {
        if (GetAppPrintState()->wifiState == WIFI_STATE_CONNECTED ||
            GetAppPrintState()->wifiState == WIFI_STATE_NETWORK ||
            (GetAppPrintState()->ethernetExists && strlen(GetAppPrintState()->lan_ip) > 6)) {
            break;
        }

        CrLogW("device no connect wifi, try again after 1 seconds\n");
        sleep(1);
    } while(1);
    #endif

    // 获取设备在服务器部署环境
    do {
        if (GetAppPrintState()->deploy_setting > 0) break;
        CrLogW("no get server deploy setting, try again after 1 seconds\n");
        sleep(1);
    } while(1);

    // 读取保存的printId
    GetPrintIdFromFile();
    CxyUpload::getInstance();
    // 启动服务器连接
    m_mqttServerClient.RegisterRecvJsonCb([this](std::string res) {return AppParseMethod(res);});
    m_mqttServerClient.RegisterConStateCb([this](int res) {return ConStateCallback(res);});
    //m_mqttServerClient.Start();
    m_mqttServerClient.Start(GetAppPrintState()->deploy_setting);
    // 创建客服二维码
    CreateUserServiceQrcode();
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {string} path
 */
int CxyManager::ReportGcodeFileInfo(int index, int type)
{
    int count = 0;
    int totalPage = 0;
    int totalPageRem = 0;

    // 发布文件列表信息到APP
    json_object *fileList = json_object_new_object();
    json_object *fileArray = json_object_new_array();
    json_object *tempArray = json_object_new_array();
    json_object *child_obj = json_object_new_object();
    if(type){
        fileArray = GetDirectoryInfo(m_appPrintState.uDiskPath, fileArray);
    }else{
        fileArray = GetDirectoryInfo(m_appPrintState.sdPath, fileArray);
    }
    
    if (json_type_array == json_object_get_type(fileArray)){
        int i = 0;
        for(i = 0; i < (int)json_object_array_length(fileArray); i++){
            if(i >= index * 5 + 5 || i < index * 5){
                continue;
            }else{
                child_obj = json_object_array_get_idx(fileArray, i);
                json_object_array_add(tempArray, child_obj);
                count++; 
            }
        }
        totalPage = i / 5;
        totalPageRem = i % 5;
        if(totalPageRem){
            totalPage = totalPage + 1;
        }
    }

    if(type){
        json_object_object_add(fileList, "uFileList", tempArray);
    }else{
        json_object_object_add(fileList, "pFileList", tempArray);
    }
    json_object_object_add(fileList, "total_page", json_object_new_int(totalPage));
    json_object_object_add(fileList, "page_size", json_object_new_int(count));
    std::string send = json_object_to_json_string(fileList);
    m_mqttServerClient.SendAttributes(send);

    json_object_object_add(fileList, "code", json_object_new_int(0));
    json_object_object_add(fileList, "msg", json_object_new_string("success"));
    std::string response = json_object_to_json_string(fileList);
    m_mqttServerClient.ResponseRpc(response);
    json_object_put(fileList);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {string} path
 */
int CxyManager::ReportVideoFilesInfo(int pageid)
{
    json_object *fileList = json_object_new_object();
    json_object *fileArray = json_object_new_array();
    if(pageid ==0)
    {
        json_object_object_add(fileList, "cmd", json_object_new_string("getVideoFiles"));
        json_object_object_add(fileList, "sn", json_object_new_string("1"));        
    }
    else{
        json_object_object_add(fileList, "cmd", json_object_new_string("getElapseInfor"));
        json_object_object_add(fileList, "sn", json_object_new_string("0")); 
        json_object_object_add(fileList, "pageNo", json_object_new_int(pageid));   
    }

    json_object_object_add(fileList, "content", fileArray);
    if (access(GetUserDelayImageInfoPtah(), F_OK) == 0)
    {
        json_object *delayImage = json_object_from_file(GetUserDelayImageInfoPtah());
        if (delayImage) {
            json_object *listObj = json_object_object_get(delayImage, "list");
            if(listObj)
            {
                int imageSize = json_object_array_length(listObj);
                CrLogI("imageSize = %d", imageSize);
                int starti = 0;
                int endi = imageSize;
                if(pageid !=0)
                {
                    int pagenum = (imageSize%countperpage==0)? imageSize/countperpage:(imageSize/countperpage+1);
                    json_object_object_add(fileList, "total_pages", json_object_new_int(pagenum));
                    json_object_object_add(fileList, "totalPrint", json_object_new_int(imageSize));
                    if(pageid <= pagenum)
                    {
                        starti = (pageid-1)*countperpage;
                        endi = (pageid*countperpage > imageSize)? imageSize:pageid*countperpage;
                    }else
                    starti = endi;
                }

                for (int i = starti; i < endi; i++)
                {
                    json_object *onecon = json_object_new_object();
                    json_object_array_add(fileArray,onecon);  

                    json_object *image = json_object_array_get_idx(listObj, i);

                    json_object *obj = json_object_object_get(image, "printId");
                    if(obj&&json_object_is_type(obj, json_type_string))
                    {
                        json_object_object_add(onecon, "printId", json_object_new_string(json_object_get_string(obj)));
                    }

                    obj = json_object_object_get(image, "name");
                    if(obj&&json_object_is_type(obj, json_type_string))
                    {
                        json_object_object_add(onecon, "gcodeFile", json_object_new_string(getnameformpath(json_object_get_string(obj))));
                    }

                    obj = json_object_object_get(image, "gcodename");
                    if(obj&&json_object_is_type(obj, json_type_string))
                    {
                        json_object_object_add(onecon, "gcodeName", json_object_new_string(json_object_get_string(obj)));
                    }

                    time_t t = 0;
                    obj = json_object_object_get(image, "starttime");
                    if(obj&&json_object_is_type(obj, json_type_int))
                    {
                        t = json_object_get_int64(obj);
                        struct tm* timeinfo = localtime(&t);
                        char buffer[80]={0};
                        strftime(buffer, 80, "%Y-%m-%d_%H-%M-%S", timeinfo);      
                        json_object_object_add(onecon, "start", json_object_new_string(buffer));
                    }

                    obj = json_object_object_get(image, "printtime");
                    if(obj&&json_object_is_type(obj, json_type_int))
                    {
                        t += json_object_get_int64(obj);
                        struct tm* timeinfo = localtime(&t);
                        char buffer[80]={0};
                        strftime(buffer, 80, "%Y-%m-%d_%H-%M-%S", timeinfo);      
                        json_object_object_add(onecon, "end", json_object_new_string(buffer));
                    }

                    json_object *elapsefiles = json_object_new_array();
                    json_object_object_add(onecon, "elapsefiles", elapsefiles);
                    json_object *oneelapse = json_object_new_object();
                    json_object_array_add(elapsefiles,oneelapse);

                    obj = json_object_object_get(image, "video");
                    if(obj&&json_object_is_type(obj, json_type_string))
                    {
                        json_object_object_add(oneelapse, "file", json_object_new_string(json_object_get_string(obj)));
                    }

                    obj = json_object_object_get(image, "videoname");
                    if(obj&&json_object_is_type(obj, json_type_string))
                    {
                        json_object_object_add(oneelapse, "name", json_object_new_string(json_object_get_string(obj)));
                    }

                    obj = json_object_object_get(image, "duration");
                    if(obj&&json_object_is_type(obj, json_type_int))
                    {
                        json_object_object_add(oneelapse, "duration", json_object_new_int(json_object_get_int(obj)));
                    }

                    obj = json_object_object_get(image, "size");
                    if(obj&&json_object_is_type(obj, json_type_int))
                    {
                        json_object_object_add(oneelapse, "size", json_object_new_int(json_object_get_int(obj)));
                    }

                    obj = json_object_object_get(image, "upload");
                    if(obj&&json_object_is_type(obj, json_type_int))
                    {
                        json_object_object_add(oneelapse, "upload", json_object_new_int(json_object_get_int(obj)));
                    }
                }
            }
            json_object_put(delayImage);
        }
        else CrLogW("read json object fail\n");
    }else CrLogW("no file\n");
    
    std::string response = json_object_to_json_string(fileList);
    CrLogI("ReportVideoFilesInfo response = %s", response.c_str());
    m_mqttServerClient.ResponseRpc(response);
    json_object_put(fileList);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {string} path
 */
int CxyManager::ReportRecFilesInfo(int pageid)
{
    json_object *fileList = json_object_new_object();
    json_object *fileArray = json_object_new_array();
    json_object_object_add(fileList, "cmd", json_object_new_string("getRecOutline"));
    json_object_object_add(fileList, "sn", json_object_new_string("0")); 
    json_object_object_add(fileList, "pageNo", json_object_new_int(pageid));   
    json_object_object_add(fileList, "total_pages", json_object_new_int(0));
    json_object_object_add(fileList, "totalPrint", json_object_new_int(0));
    json_object_object_add(fileList, "content", fileArray);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {string} path
 */
int CxyManager::ReportRecDetail(std::string prindId,int pageid)
{
    json_object *fileList = json_object_new_object();
    json_object *fileArray = json_object_new_array();
    json_object_object_add(fileList, "cmd", json_object_new_string("getRecDetail"));
    json_object_object_add(fileList, "sn", json_object_new_string("0")); 
    json_object_object_add(fileList, "printId", json_object_new_string(prindId.c_str())); 
    json_object_object_add(fileList, "pageNo", json_object_new_int(pageid));   
    json_object_object_add(fileList, "total_pages", json_object_new_int(0));
    json_object_object_add(fileList, "content", fileArray);
}

std::string CxyManager::GetPrintidByFilePath(std::string file)
{
    string ret = m_appPrintState.printId;
    if (access(GetUserDelayImageInfoPtah(), F_OK) != 0)
        return ret;

    json_object *delayImage = json_object_from_file(GetUserDelayImageInfoPtah());
    if (!delayImage) 
        return ret;

    json_object *listObj = json_object_object_get(delayImage, "list");
    if(!listObj)
    {
        json_object_put(delayImage);
        return ret;
    }

    int imageSize = json_object_array_length(listObj);
    CrLogI("imageSize = %d", imageSize);
    for (int i = 0; i < imageSize; i++)
    {
        json_object *image = json_object_array_get_idx(listObj, i);
        json_object *pathobj = json_object_object_get(image, "video");
        if(pathobj&&json_object_is_type(pathobj, json_type_string))
        {
            string vp = json_object_get_string(pathobj);
            if(vp == file)
            {
                CrLogI("GetPrintidByFilePath findfileinfo = %s", vp.c_str());
                json_object *obj = json_object_object_get(image, "printId");
                if(obj&&json_object_is_type(obj, json_type_string))
                {
                    ret = json_object_get_string(obj);
                }               
                break;
            }
        }
    }

    json_object_put(delayImage);
    CrLogI("GetPrintidByFilePath printid = %s", ret.c_str());
    return ret;
}

int CxyManager::ProcVideoUpload(std::string prindId,std::string file,std::string token)
{
    CrLogI("ProcVideoUpload file = %s\n", file.c_str());
    if(token.size()>0)
    {
        memset(m_appPrintState.appJwtToken, 0, sizeof(m_appPrintState.appJwtToken));
        memcpy(m_appPrintState.appJwtToken, token.c_str(), token.size());
    }

    if (access(GetUserDelayImageInfoPtah(), F_OK) != 0)
        return -1;

    json_object *delayImage = json_object_from_file(GetUserDelayImageInfoPtah());
    if (!delayImage) 
        return -2;

    json_object *listObj = json_object_object_get(delayImage, "list");
    if(!listObj)
    {
        json_object_put(delayImage);
        return -3;
    }

    int imageSize = json_object_array_length(listObj);
    CrLogI("imageSize = %d", imageSize);
    for (int i = 0; i < imageSize; i++)
    {
        json_object *image = json_object_array_get_idx(listObj, i);
        json_object *obj = json_object_object_get(image, "printId");
        if(obj&&json_object_is_type(obj, json_type_string))
        {
            string pid = json_object_get_string(obj);
            if(pid != prindId)
                continue;
        }else continue;
        obj = json_object_object_get(image, "videoname");
        json_object *pathobj = json_object_object_get(image, "video");
        if(obj&&json_object_is_type(obj, json_type_string)
        &&pathobj&&json_object_is_type(pathobj, json_type_string))
        {
            string vp = json_object_get_string(pathobj);
            if(vp == file)
            {
                CrLogI("ProcVideoUpload findfileinfo = %s", vp.c_str());
                int ret = AppUploadDelayImage(json_object_get_string(pathobj),prindId);
                json_object_put(delayImage);
                return ret;
            }
        }else continue;
    }
    json_object_put(delayImage);
    return -4;
}

int CxyManager::ProcVideoRemove(std::string prindId,std::string file)
{
    CrLogI("ProcVideoRemove file = %s\n", file.c_str());
    FileControl fcon = FILE_CONTROL__INIT;
    fcon.has_cmd = 1;
    fcon.cmd = 3;
    fcon.has_printid = 1;
    fcon.printid.data = (uint8_t*)const_cast<char *>(prindId.c_str());
    fcon.printid.len = prindId.length();
    fcon.has_file = 1;
    fcon.file.data = (uint8_t*)const_cast<char*>(file.c_str());
    fcon.file.len = file.length();
    GET_MESSAGE_BUFF(buf);
    size_t len = file_control__pack(&fcon, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_LOCAL_VIDEO, buf, len);
    SendProcessMsgBuff(&send, size);
}

int CxyManager::ProcVideoRename(std::string prindId,std::string file,std::string targetname)
{
    CrLogI("ProcVideoRename file = %s to %s\n", file.c_str(), targetname.c_str());
    FileControl fcon = FILE_CONTROL__INIT;
    fcon.has_cmd = 1;
    fcon.cmd = 2;
    fcon.has_printid = 1;
    fcon.printid.data = (uint8_t*)const_cast<char*>(prindId.c_str());
    fcon.printid.len = prindId.length();
    fcon.has_file = 1;
    fcon.file.data = (uint8_t*)const_cast<char*>(file.c_str());
    fcon.file.len = file.length();
    fcon.has_param1 = 1;
    fcon.param1.data = (uint8_t*)const_cast<char*>(targetname.c_str());
    fcon.param1.len = targetname.length();
    GET_MESSAGE_BUFF(buf);
    size_t len = file_control__pack(&fcon, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_LOCAL_VIDEO, buf, len);
    SendProcessMsgBuff(&send, size);
}

int CxyManager::ProcVideoAddPrintid(std::string file)
{
    CrLogI("ProcVideoAddPrintid file = %s printId = %s\n", file.c_str(), m_appPrintState.printId);

    FileControl fcon = FILE_CONTROL__INIT;
    fcon.has_cmd = 1;
    fcon.cmd = 1;
    fcon.has_printid = 1;
    fcon.printid.data = (uint8_t*)m_appPrintState.printId;
    fcon.printid.len = strlen(m_appPrintState.printId);
    fcon.has_file = 1;
    fcon.file.data = (uint8_t*)const_cast<char*>(file.c_str());
    fcon.file.len = file.length();
    GET_MESSAGE_BUFF(buf);
    size_t len = file_control__pack(&fcon, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_LOCAL_VIDEO, buf, len);
    SendProcessMsgBuff(&send, size);
}

int CxyManager::ProcVideoUploadState(std::string file,std::string videoid)
{
    CrLogI("ProcVideoUploadState file = %s videoid = %s\n", file.c_str(), videoid.c_str());

    FileControl fcon = FILE_CONTROL__INIT;
    fcon.has_cmd = 1;
    fcon.cmd = 4;
    fcon.has_file = 1;
    fcon.file.data = (uint8_t*)const_cast<char*>(file.c_str());
    fcon.file.len = file.length();
    fcon.has_param1 = 1;
    fcon.param1.data = (uint8_t*)const_cast<char*>(videoid.c_str());
    fcon.param1.len = videoid.length();
    GET_MESSAGE_BUFF(buf);
    size_t len = file_control__pack(&fcon, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_CONTROL_LOCAL_VIDEO, buf, len);
    SendProcessMsgBuff(&send, size);
}

int CxyManager::ControlVideoFilesResult(int ret)
{
    json_object *result = json_object_new_object();
    json_object_object_add(result, "code", json_object_new_int(ret));
    //json_object_object_add(result, "msg", json_object_new_string("fail"));
    std::string response = json_object_to_json_string(result);
    m_mqttServerClient.ResponseRpc(response);
    json_object_put(result);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} result
 */
int CxyManager::ReportAppControlPrint(int result)
{
    // 发布RPC设置结果到APP
    json_object *rpcReport = json_object_new_object();
    if (result) {
        json_object_object_add(rpcReport, "code", json_object_new_int(0));
        json_object_object_add(rpcReport, "msg", json_object_new_string("success"));
    }
    else json_object_object_add(rpcReport, "code", json_object_new_int(-1));

    std::string response = json_object_to_json_string(rpcReport);
    m_mqttServerClient.ResponseRpc(response);
    json_object_put(rpcReport);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {*}
 */
int CxyManager::ReportTotalTime()
{
    json_object *reportAllPrintTime = json_object_new_object();
    std::string allPrintTime = std::to_string(m_appPrintState.allPrintTime);
    json_object_object_add(reportAllPrintTime, "allPrintTime", json_object_new_string(allPrintTime.c_str()));
    std::string send = json_object_to_json_string(reportAllPrintTime);
    m_mqttServerClient.SendAttributes(send);
    json_object_object_add(reportAllPrintTime, "code", json_object_new_int(0));
    json_object_object_add(reportAllPrintTime, "msg", json_object_new_string("success"));
    std::string response = json_object_to_json_string(reportAllPrintTime);
    m_mqttServerClient.ResponseRpc(response);
    json_object_put(reportAllPrintTime);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {*}
 */
int CxyManager::ReportAllPrintTime()
{
    CrLogI("get history record from file");
    // 判断历史记录是否存在，读取文件，获取json数据
    if (access(GetuserPrintHistoryRecordPtah(), F_OK) == 0){
        json_object *historyRecord = json_object_from_file(GetuserPrintHistoryRecordPtah());
        if (historyRecord) {
            // 提取历史记录列表
            json_object *listObj = json_object_object_get(historyRecord, "list");
            int recordSize = json_object_array_length(listObj);
            int totalUsageTime = 0;
            int totalUsageMaterial = 0;
            CrLogI("recordSize = %d", recordSize);
            for (int i = 0; i < recordSize; i++){
                json_object *record = json_object_array_get_idx(listObj, i);
                int usagetime = json_object_get_int(json_object_object_get(record, "usagetime"));
                totalUsageTime = totalUsageTime + usagetime;
                int usagematerial = json_object_get_int(json_object_object_get(record, "usagematerial"));
                totalUsageMaterial = totalUsageMaterial + usagematerial;
            }
            // 发布历史文件列表信息到app
            json_object *reportAllPrintTime = json_object_new_object();
            std::string allPrintTime = std::to_string(totalUsageTime);
            json_object_object_add(reportAllPrintTime, "allPrintTime", json_object_new_string(allPrintTime.c_str()));
            std::string send = json_object_to_json_string(reportAllPrintTime);
            m_mqttServerClient.SendAttributes(send);
            json_object_object_add(reportAllPrintTime, "code", json_object_new_int(0));
            json_object_object_add(reportAllPrintTime, "msg", json_object_new_string("success"));
            std::string response = json_object_to_json_string(reportAllPrintTime);
            m_mqttServerClient.ResponseRpc(response);
            json_object_put(listObj);
            json_object_put(reportAllPrintTime);
        }else {
            CrLogW("read json object fail\n");
            json_object *reportAllPrintTime = json_object_new_object();
            json_object_object_add(reportAllPrintTime, "code", json_object_new_int(-1));
            json_object_object_add(reportAllPrintTime, "msg", json_object_new_string("fail"));
            std::string response = json_object_to_json_string(reportAllPrintTime);
            m_mqttServerClient.ResponseRpc(response);
            json_object_put(reportAllPrintTime);
            json_object_put(historyRecord);
        }
    }else {
        CrLogI("no history record\n");
        json_object *reportAllPrintTime = json_object_new_object();
        json_object_object_add(reportAllPrintTime, "code", json_object_new_int(-1));
        json_object_object_add(reportAllPrintTime, "msg", json_object_new_string("fail"));
        std::string response = json_object_to_json_string(reportAllPrintTime);
        m_mqttServerClient.ResponseRpc(response);
        json_object_put(reportAllPrintTime);
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {int} state
 */
int CxyManager::UploadStateCallback(int state,CxyUpload *upload,int progress)
{
    CrLogI("upload delay image state = %d", state);
    if(upload == NULL)
        return -1;
    if (state == FILE_UPLOAD_OK)
    {
        std::string pathfile;
        if(upload->getOpetions())
            pathfile = upload->getOpetions()->filePath;
        /*
        std::string pid = GetPrintidByFilePath(pathfile);
        if (upload->AssociateUploadVideoToPrintJob(const_cast<char*>(pid.c_str())))
        {
            ProcVideoUploadState(pathfile,upload->getvideoid());
            ControlVideoFilesResult(0);
            CrLogI("video association successfully");
        }
        else CrLogW("video association failed\n");*/
        ProcVideoUploadState(pathfile,upload->getvideoid());
        ControlVideoFilesResult(0);
    }
    
    // 释放类
    if (state == FILE_UPLOAD_OK || state == FILE_UPLOAD_FAIL) {
        //delete upload;
    }

	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {int} state
 */
int CxyManager::UploadLocalStateCallback(int state,CxyUpload *upload,int progress)
{
    CrLogI("upload delay image state = %d", state);
    if(upload == NULL)
    {
        GeneralRes res = GENERAL_RES__INIT;
        res.result = 0;
        GET_MESSAGE_BUFF(buf);
        size_t len = general_res__pack(&res, buf);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_UPLOAD_LOCAL_VIDEO_ANS, buf, len);
        SendProcessMsgBuff(&send, size);
        return -1;
    }

    if (state == FILE_UPLOAD_OK)
    {
        // 响应
        GeneralRes res = GENERAL_RES__INIT;
        res.result = 1;
        std::string pathfile;
        if(upload->getOpetions())
            pathfile = upload->getOpetions()->filePath;

        /*std::string pid = GetPrintidByFilePath(pathfile);
        if (upload->AssociateUploadVideoToPrintJob(const_cast<char*>(pid.c_str())))
        {
            CrLogI("video association successfully");
            res.result = 1;
        }
        else {
            CrLogW("video association failed\n");
            res.result = 0;
        }*/
        ProcVideoUploadState(pathfile,upload->getvideoid());
        GET_MESSAGE_BUFF(buf);
        size_t len = general_res__pack(&res, buf);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_UPLOAD_LOCAL_VIDEO_ANS, buf, len);
        SendProcessMsgBuff(&send, size);
    }
    if (state == FILE_UPLOAD_FAIL)
    {
        GeneralRes res = GENERAL_RES__INIT;
        res.result = 0;
        GET_MESSAGE_BUFF(buf);
        size_t len = general_res__pack(&res, buf);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_UPLOAD_LOCAL_VIDEO_ANS, buf, len);
        SendProcessMsgBuff(&send, size);
    }
    
    // 释放类
    if (state == FILE_UPLOAD_OK || state == FILE_UPLOAD_FAIL) {
        //if(upload){delete upload;}
    }

	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {string} path
 */
int CxyManager::AppUploadDelayImage(std::string path,std::string printid)
{
    CxyUpload *m_delayImageUpload = CxyUpload::getInstance();
    CxyUploadOptions_t options;
    if(printid.size() == 0)
        options.printId = m_appPrintState.printId;
    else 
        options.printId = printid;
    options.appToken = m_appPrintState.appJwtToken;
    options.filePath = path;
    options.deploy_setting = GetAppPrintState()->deploy_setting;
    options.fileTitle = "440x-upload-delay-image.mp4";
    options.upload = m_delayImageUpload;
    options.conStateCb = [this](int res,CxyUpload *upload,int progress) {return UploadStateCallback(res,upload,progress);};
    m_delayImageUpload->StartUploadVideo(options);
    
	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {int} state
 */
int CxyManager::SyncUploadLogState(int state, int progress)
{
    ExportLogState sync = EXPORT_LOG_STATE__INIT;
    switch (state) {
        case FILE_UPLOAD_COMPRESS: sync.state = COMPRESSING_LOG; break;
        case FILE_UPLOAD_ING: sync.state = EXPORTING_LOGS; break;
        case FILE_UPLOAD_OK: sync.state = EXPORT_LOG_SUCCESS; break;
        case FILE_UPLOAD_FAIL: sync.state = EXPORT_LOG_FAIL; break;
        case FILE_UPLOAD_STOPOK: sync.state = EXPORT_STOPLOG_SUCCESS; break;
        default: sync.state = EXPORT_LOG_FAIL; break;
    }
    sync.progress = progress;

    GET_MESSAGE_BUFF(buff);
    size_t len = export_log_state__pack(&sync, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_SYNC_EXPORT_LOG_STATE, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {int} state
 */
int CxyManager::UploadLogStateCallback(int state,CxyUpload *upload,int progress)
{
    CrLogI("upload log state = %d", state);
    if(upload == NULL)
        return -1;
    if (state == FILE_UPLOAD_OK){
        if(upload->RequestRecordUploadLog()){
            CrLogI("submit log successfully\n");
        }else{
            CrLogW("submit log failed\n");
        }
    }
    
    // 同步上传日志状态
    SyncUploadLogState(state, progress);
    
    // 释放类
    if (state == FILE_UPLOAD_OK || state == FILE_UPLOAD_FAIL || state == FILE_UPLOAD_STOPOK) {
        upload->RemoveLogPackges();
        //if(upload) delete upload;
    }

	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {int} state
 */
int CxyManager::UploadLocalLogStateCallback(int state,CxyUpload *upload,int progress)
{
    CrLogI("upload log state = %d", state);
    if(upload == NULL)
    {
        MutableTypeData res = MUTABLE_TYPE_DATA__INIT;
        res.has_int_v = 1;
        res.int_v = 0;

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&res, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_UPLOAD_LOCAL_LOG_ANS, buff, len);
        SendProcessMsgBuff(&send, size);
        return -1;
    }
        
    if (state == FILE_UPLOAD_OK){
        std::string uploadLogId = upload->getUploadLogId();
        CrLogI("uploadLogId = %s", uploadLogId.c_str());

        // 响应
        MutableTypeData res = MUTABLE_TYPE_DATA__INIT;
        res.has_int_v = 1;
        res.int_v = 1;
        res.has_bytes_v = 1;
        res.bytes_v.data = (u_int8_t*)uploadLogId.c_str();
        res.bytes_v.len = uploadLogId.length();

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&res, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_UPLOAD_LOCAL_LOG_ANS, buff, len);
        SendProcessMsgBuff(&send, size);
    }
    else if (state == FILE_UPLOAD_FAIL)
    {
        MutableTypeData res = MUTABLE_TYPE_DATA__INIT;
        res.has_int_v = 1;
        res.int_v = 0;

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&res, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_UPLOAD_LOCAL_LOG_ANS, buff, len);
        SendProcessMsgBuff(&send, size);
    }
    else if(state == FILE_UPLOAD_STOPOK)
    {
        MutableTypeData res = MUTABLE_TYPE_DATA__INIT;
        res.has_int_v = 1;
        res.int_v = 2;

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&res, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_SERVER, SERVER_CMD_APP_UPLOAD_LOCAL_LOG_ANS, buff, len);
        SendProcessMsgBuff(&send, size);
    }

    // 同步上传日志状态
    SyncUploadLogState(state, progress);
    
    // 释放类
    if (state == FILE_UPLOAD_OK || state == FILE_UPLOAD_FAIL || state == FILE_UPLOAD_STOPOK) {
        upload->RemoveLogPackges();
        //if(upload) delete upload;
    }

	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {string} path
 */
int CxyManager::AppUploadLog()
{
    CxyUpload * m_logUpload = CxyUpload::getInstance();
    CxyUploadOptions_t options;
    options.appToken = m_appPrintState.appToken;
    options.upload = m_logUpload;
    options.deploy_setting = GetAppPrintState()->deploy_setting;
    options.conStateCb = [this](int res,CxyUpload *upload,int progress) {return UploadLogStateCallback(res,upload,progress);};
    m_logUpload->StartUploadLog(options);

	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {*}
 */
int CxyManager::AppUploadLocalLog()
{
    std::string token = m_appPrintState.appJwtToken;
    auto decoded = jwt::decode(token);
    struct timeval tv;
    gettimeofday(&tv, NULL);
    for(auto& e : decoded.get_payload_json()){
        if(e.first == "exp"){
            std::string tmp = e.second.to_str();
            if(atoi(tmp.c_str()) < tv.tv_sec){
                UploadLocalLogStateCallback(FILE_UPLOAD_FAIL,nullptr,0);
                return 0;
            }
        }
    }

    CxyUpload *m_logUpload = CxyUpload::getInstance();
    CxyUploadOptions_t options;
    options.appToken = m_appPrintState.appJwtToken;
    options.upload = m_logUpload;
    options.deploy_setting = GetAppPrintState()->deploy_setting;
    options.conStateCb = [this](int res,CxyUpload *upload,int progress) {return UploadLocalLogStateCallback(res,upload,progress);};
    m_logUpload->StartUploadLog(options);

	return 1;
}

int CxyManager::AppStopUploadLog()
{
    CxyUpload::getInstance()->StopUploadLog();
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {*}

std::string CxyManager::GetUploadLogId()
{
    return m_logUpload->getUploadLogId();
} */

/**
 * @description: 
 * @return {*}
 * @param {*}
 */
int CxyManager::AppUploadLocalDelayImage(std::string path)
{
    std::string token = m_appPrintState.appJwtToken;
    auto decoded = jwt::decode(token);
    struct timeval tv;
    gettimeofday(&tv, NULL);
    for(auto& e : decoded.get_payload_json()){
        if(e.first == "exp"){
            std::string tmp = e.second.to_str();
            if(atoi(tmp.c_str()) < tv.tv_sec){
                UploadLocalStateCallback(FILE_UPLOAD_FAIL,nullptr,0);
                return 0;
            }
        }
    }

    CxyUpload *m_delayImageUpload = CxyUpload::getInstance();
    CxyUploadOptions_t options;
    options.printId = GetPrintidByFilePath(path);
    options.appToken = m_appPrintState.appJwtToken;
    options.filePath = path;
    options.deploy_setting = GetAppPrintState()->deploy_setting;
    options.upload = m_delayImageUpload;
    options.fileTitle = "440x-upload-delay-image.mp4";
    options.conStateCb = [this](int res,CxyUpload *upload,int progress) {return UploadLocalStateCallback(res,upload,progress);};
    m_delayImageUpload->StartUploadVideo(options);

	return 1;
}

/**
 * @description: 
 * @return {*}
 */
bool CxyManager::RequestOwnerInfo(char *token)
{
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(GetAppPrintState()->deploy_setting);
    std::string url = server.url;
    m_cxyHttpServer.CxyHttpApiInit(url, "onwer_info");
    std::string tmplyAuthorityInfo;
    m_cxyHttpServer.HttpGetOwnerInfo(token, &tmplyAuthorityInfo);

    if (!OwnerInfoInfoAnl(tmplyAuthorityInfo)) {
        CrLogW("OwnerInfoInfoAnl fail\n");
        return false;
    }

    json_object *iotConfig = json_tokener_parse(AppAesDecryptFromFile(GetUserIotTbInfoFilePtah()).c_str());
    if(iotConfig){
        json_object *userUpdateInfoObj = json_tokener_parse(tmplyAuthorityInfo.c_str());
        if(userUpdateInfoObj){
            json_object *resultObj = json_object_object_get(userUpdateInfoObj, "result");
            json_object *userInfoObj = json_object_object_get(iotConfig, "cxy_user_info");
            if(userInfoObj){
                json_object_object_del(userInfoObj, "cxy_user_info");
            }
            json_object_object_add(iotConfig, "cxy_user_info", resultObj);
            AppAesEncryptToFile(GetUserIotTbInfoFilePtah(), json_object_to_json_string(iotConfig));
        }else{
            json_object_put(iotConfig);
            return false;
        }
        json_object_put(iotConfig);
    }else{
        return false;
    }
    
    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {string} info
 */
bool CxyManager::OwnerInfoInfoAnl(std::string info)
{
    CrLogI("tmply authority info anl");
    // 解析获取的授权信息
    json_object *infoObj = json_tokener_parse(info.c_str());
    if (infoObj == NULL || !json_object_is_type(infoObj, json_type_object))
    {
        CrLogW("return information parsing error\n");
        if (infoObj != NULL) json_object_put(infoObj);
        return false;
    }

    // 判断code值
    json_object *codeObj = json_object_object_get(infoObj, "code");
    json_object *msgObj = json_object_object_get(infoObj, "msg");
    if (codeObj == NULL || !json_object_is_type(codeObj, json_type_int) ||
        msgObj == NULL || !json_object_is_type(msgObj, json_type_string))
    {
        CrLogW("no code or msg\n");
        json_object_put(infoObj);
        return false;
    }

    // 判断请求信息是否成功
    CrLogI("code = %d; msg = %s", json_object_get_int(codeObj), json_object_get_string(msgObj));
    if (json_object_get_int(codeObj) != 0 || strcmp(json_object_get_string(msgObj), "ok") != 0)
    {
        CrLogW("code or msg fail\n");
        json_object_put(infoObj);
        return false;
    }

    // 判断是否有返回结果
    json_object *resultObj = json_object_object_get(infoObj, "result");
    if (resultObj == NULL || !json_object_is_type(resultObj, json_type_object))
    {
        CrLogW("no return result\n");
        json_object_put(infoObj);
        return false;
    }

    // 获取授权信息
    json_object *nickName = json_object_object_get(resultObj, "nickName");
    if (nickName != NULL && json_object_is_type(nickName, json_type_string))
    {
        std::string nickNameStr = json_object_get_string(nickName);
        CrLogI("nickName = %s",nickNameStr.c_str());
    }
    json_object *avatar = json_object_object_get(resultObj, "avatar");
    if (avatar != NULL && json_object_is_type(avatar, json_type_string))
    {
        std::string avatarStr = json_object_get_string(avatar);
        CrLogI("avatar = %s", avatarStr.c_str());
    }
    json_object *userId = json_object_object_get(resultObj, "userId");
    if (userId != NULL && json_object_is_type(userId, json_type_int))
    {
        uint userIdNum = json_object_get_int(userId);
        CrLogI("userId = %u", userIdNum);
    }
    json_object *introduction = json_object_object_get(resultObj, "introduction");
    if (introduction != NULL && json_object_is_type(introduction, json_type_string))
    {
        std::string introductionStr = json_object_get_string(introduction);
        CrLogI("introduction = %s\n", introductionStr.c_str());
    }
    json_object *level = json_object_object_get(resultObj, "level");
    if (level != NULL && json_object_is_type(level, json_type_int))
    {
        uint levelNum = json_object_get_int(level);
        CrLogI("level = %u", levelNum);
    }
    // 释放资源
    json_object_put(infoObj);
    return true;
}

/**
 * @description: 
 * @return {*}
 */
bool CxyManager::RequestReportAiNotice(char *token, char *printId)
{
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(GetAppPrintState()->deploy_setting);
    std::string url = server.url;
    m_cxyHttpServer.CxyHttpApiInit(url, "report_ai_notice");
    std::string tmplyAuthorityInfo;
    m_cxyHttpServer.HttpReportAiNotice(token, &tmplyAuthorityInfo, printId);

    if (!ReportAiNoticeAnl(tmplyAuthorityInfo)) {
        CrLogW("ReportAiNoticeAnl fail\n");
        return false;
    }

    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {string} info
 */
bool CxyManager::ReportAiNoticeAnl(std::string info)
{
    CrLogI("tmply authority info anl");
    // 解析获取的授权信息
    json_object *infoObj = json_tokener_parse(info.c_str());
    if (infoObj == NULL || !json_object_is_type(infoObj, json_type_object))
    {
        CrLogW("return information parsing error\n");
        if (infoObj != NULL) json_object_put(infoObj);
        return false;
    }

    // 判断code值
    json_object *codeObj = json_object_object_get(infoObj, "code");
    json_object *msgObj = json_object_object_get(infoObj, "msg");
    if (codeObj == NULL || !json_object_is_type(codeObj, json_type_int) ||
        msgObj == NULL || !json_object_is_type(msgObj, json_type_string))
    {
        CrLogW("no code or msg\n");
        json_object_put(infoObj);
        return false;
    }

    // 判断请求信息是否成功
    CrLogI("code = %d; msg = %s", json_object_get_int(codeObj), json_object_get_string(msgObj));
    if (json_object_get_int(codeObj) != 0 || strcmp(json_object_get_string(msgObj), "ok") != 0)
    {
        CrLogW("code or msg fail\n");
        json_object_put(infoObj);
        return false;
    }

    // 释放资源
    json_object_put(infoObj);
    return true;
}

/**
 * @description: 
 * @return {*}
 */
bool CxyManager::RequestLocalPrint(char *token, char *workId, char *fileName, char *model, std::string *info)
{
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(GetAppPrintState()->deploy_setting);
    std::string url = server.url;
    m_cxyHttpServer.CxyHttpApiInit(url, "localPrint");

    m_cxyHttpServer.HttpLocalPrint(token, info, workId, fileName, model);

    if (!LocalPrintAnl(*info)) {
        CrLogW("LocalPrintAnl fail\n");
        return false;
    }

    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {string} info
 */
bool CxyManager::LocalPrintAnl(std::string info)
{
    CrLogI("tmply authority info anl");
    // 解析获取的授权信息
    json_object *infoObj = json_tokener_parse(info.c_str());
    if (infoObj == NULL || !json_object_is_type(infoObj, json_type_object))
    {
        CrLogW("return information parsing error\n");
        if (infoObj != NULL) json_object_put(infoObj);
        return false;
    }

    // 判断code值
    json_object *codeObj = json_object_object_get(infoObj, "code");
    json_object *msgObj = json_object_object_get(infoObj, "msg");
    json_object *resObj = json_object_object_get(infoObj, "result");
    if (codeObj == NULL || !json_object_is_type(codeObj, json_type_int) ||
        msgObj == NULL || !json_object_is_type(msgObj, json_type_string) ||
        resObj == NULL || !json_object_is_type(resObj, json_type_object))
    {
        CrLogW("no code or msg\n");
        json_object_put(infoObj);
        return false;
    }

    // 判断请求信息是否成功
    CrLogI("code = %d; msg = %s", json_object_get_int(codeObj), json_object_get_string(msgObj));
    if (json_object_get_int(codeObj) != 0 || strcmp(json_object_get_string(msgObj), "ok") != 0)
    {
        CrLogW("code or msg fail\n");
        json_object_put(infoObj);
        return false;
    }

    // 释放资源
    json_object_put(infoObj);
    return true;
}

/**
 * @description: 
 * @return {*}
 */
int CxyManager::CxyInit(void)
{
    // 获取IOT配置
    CrLogW("CxyInit\n");
    json_object *config = json_tokener_parse(AppAesDecryptFromFile(GetUserIotConfigPath()).c_str());
    CrLogW("create iot config file %x\n",config);
    if (!config) {
        CrLogW("create iot config file\n");
        // 创建创想云远端URL
        json_object *cnObj = json_object_new_object();
        json_object_object_add(cnObj, "url", json_object_new_string("https://api.crealitycloud.cn"));
        json_object_object_add(cnObj, "vod", json_object_new_string("cn-shanghai"));
        json_object_object_add(cnObj, "endpoint", json_object_new_string("http://oss-cn-hangzhou.aliyuncs.com"));
        json_object_object_add(cnObj, "bucket", json_object_new_string("file-creality"));
        json_object_object_add(cnObj, "iot", json_object_new_string("mqtt.crealitycloud.cn"));

        json_object *comObj = json_object_new_object();
        json_object_object_add(comObj, "url", json_object_new_string("https://api.crealitycloud.com"));
        json_object_object_add(comObj, "vod", json_object_new_string("ap-southeast-1"));
        json_object_object_add(comObj, "endpoint", json_object_new_string("http://oss-us-east-1.aliyuncs.com"));
        json_object_object_add(comObj, "bucket", json_object_new_string("file2-creality"));
        json_object_object_add(comObj, "iot", json_object_new_string("mqtt.crealitycloud.com"));

        json_object *cnPreObj = json_object_new_object();
        json_object_object_add(cnPreObj, "url", json_object_new_string("https://admin-pre.crealitycloud.cn"));
        json_object_object_add(cnPreObj, "vod", json_object_new_string("cn-shanghai"));
        json_object_object_add(cnPreObj, "endpoint", json_object_new_string("http://oss-cn-hangzhou.aliyuncs.com"));
        json_object_object_add(cnPreObj, "bucket", json_object_new_string("file-creality"));
        json_object_object_add(cnPreObj, "iot", json_object_new_string("120.55.101.240:1883"));

        json_object *comPreObj = json_object_new_object();
        json_object_object_add(comPreObj, "url", json_object_new_string("https://admin-pre.crealitycloud.com"));
        json_object_object_add(comPreObj, "vod", json_object_new_string("ap-southeast-1"));
        json_object_object_add(comPreObj, "endpoint", json_object_new_string("http://oss-us-east-1.aliyuncs.com"));
        json_object_object_add(comPreObj, "bucket", json_object_new_string("file2-creality"));
        json_object_object_add(comPreObj, "iot", json_object_new_string("pre-tb-iot.crealitycloud.com:1883"));

        json_object *testObj = json_object_new_object();
        json_object_object_add(testObj, "url", json_object_new_string("http://api-dev.crealitycloud.cn"));
        json_object_object_add(testObj, "vod", json_object_new_string("cn-shanghai"));
        json_object_object_add(testObj, "endpoint", json_object_new_string("http://oss-cn-hangzhou.aliyuncs.com"));
        json_object_object_add(testObj, "bucket", json_object_new_string("file-creality-dev"));
        json_object_object_add(testObj, "iot", json_object_new_string("47.114.48.45:1883"));

        json_object *debugObj = json_object_new_object();
        json_object_object_add(debugObj, "url", json_object_new_string("http://172.29.99.188:4020"));
        json_object_object_add(debugObj, "vod", json_object_new_string("cn-shanghai"));
        json_object_object_add(debugObj, "endpoint", json_object_new_string("http://oss-cn-hangzhou.aliyuncs.com"));
        json_object_object_add(debugObj, "bucket", json_object_new_string("file-creality-dev"));
        json_object_object_add(debugObj, "iot", json_object_new_string("172.29.99.188:1883"));

        json_object *remoteObj = json_object_new_object();
        json_object_object_add(remoteObj, "cxy_cn_server", cnObj);
        json_object_object_add(remoteObj, "cxy_com_server", comObj);
        json_object_object_add(remoteObj, "cxy_cn_pre_server", cnPreObj);
        json_object_object_add(remoteObj, "cxy_com_pre_server", comPreObj);
        json_object_object_add(remoteObj, "cxy_test_server", testObj);
        json_object_object_add(remoteObj, "cxy_debug_server", debugObj);

        // 创建创想云API
        json_object *apiObj = json_object_new_object();
        json_object_object_add(apiObj, "register_dev", json_object_new_string("/api/cxy/v2/device/registerDevice"));
        json_object_object_add(apiObj, "upgrade_info", json_object_new_string("/api/cxy/v2/firmware/list"));
        json_object_object_add(apiObj, "aliyun_authority", json_object_new_string("/api/cxy/v2/device/user/getAliyunSts"));
        json_object_object_add(apiObj, "video_associate", json_object_new_string("/api/cxy/v2/device/submitVideoJwt"));
        json_object_object_add(apiObj, "submit_log_file", json_object_new_string("/api/cxy/v2/device/user/submitLogFile"));
        json_object_object_add(apiObj, "onwer_info", json_object_new_string("/api/cxy/v2/device/user/onwerInfo"));
        json_object_object_add(apiObj, "report_ai_notice", json_object_new_string("/api/cxy/v2/device/user/reportAiNotice"));
        json_object_object_add(apiObj, "localPrint", json_object_new_string("/api/cxy/v2/device/user/localPrint"));
        json_object_object_add(apiObj, "presubmit_timelapse", json_object_new_string("/api/cxy/v2/device/preSubmitTimelapse"));

        // 用户服务
        json_object *userServiceObj = json_object_new_string("https://www.crealitycloud.cn/product");

        // 创建创想云配置文件
        config = json_object_new_object();
        json_object_object_add(config, "cxy_remote", remoteObj);
        json_object_object_add(config, "cxy_http_api", apiObj);
        json_object_object_add(config, "user_service", userServiceObj);

        // 保存配置文件
        AppAesEncryptToFile(GetUserIotConfigPath(), json_object_to_json_string(config));
    }

    // 释放内存
    json_object_put(config);
	return 0;
}
