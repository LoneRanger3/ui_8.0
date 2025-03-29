/*
 * @Description : 保存master配置文件
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-29 14:23:17
 * @LastEditTime: 2023-10-31 08:19:37
 */
#include <sys/time.h>
#include "Base/MasterMsgBase.h"
#include "global/SysConfig.h"

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static SystemConfig_t systemComfig = {0}; // 系统配置文件
static pthread_rwlock_t rwLock; // 声明读写锁
static pthread_rwlock_t delayVideoLock; // 声明读写锁
static json_object *saveUserRrefer = NULL; // 保存用户偏好

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */

/*********************************************************
 *********************************************************
 ******************** 系统默认配置 *************************
 *********************************************************
 *********************************************************/
/**
 * @description: 
 * @return {*}
 * @param {char} *type
 */
static int GetDeviceIdByDeviceType(char *type)
{
    if (strcmp(type, "CREALITY") == 0) return CREALITY;
    else if (strcmp(type, "CR-10 H1") == 0) return CR_10_H1;
    else if (strcmp(type, "CR-K1") == 0) return CR_K1;
    else if (strcmp(type, "CR-K1 Max") == 0) return CR_K1_Max;
    else if (strcmp(type, "Nebula Pad") == 0) return Nebula_Pad;
    else if (strcmp(type, "CR-10 SE") == 0) return CR_10_SE;
    else if (strcmp(type, "PF-05") == 0) return PF_05;
    else if (strcmp(type, "K1C") == 0) return K1C;
    else if (strcmp(type, "K1 Max SE") == 0) return K1_Max_SE;
    else {
        // 无法从系统获取机器型号，主动退出，结束进程；防止生成未知机型配置文件
        CrLogE("get device model fail !!\n");
        CrLogE("EXIT:!!!\n\n");
        exit(1);
    }
}

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetBedLengthById(DeviceModel id) { return 220; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetBedWidthById(DeviceModel id) { return 220; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetBedHightById(DeviceModel id) { return 270; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetUiDirectionById(DeviceModel id)
{
    switch (id) {
        case CR_K1: return UI_DIRECTION_270;
        case CR_K1_Max: return UI_DIRECTION_270;
        case K1C: return UI_DIRECTION_270;
        case K1_Max_SE: return UI_DIRECTION_270;
        case Nebula_Pad: return UI_DIRECTION_90;
        case CR_10_SE: return UI_DIRECTION_90;
        case PF_05: return UI_DIRECTION_270;
        default: return UI_DIRECTION_NONE;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetZDirectionById(DeviceModel id)
{
    switch (id) {
        case CR_K1: return Z_DIRECTION_REVERSE;
        case CR_K1_Max: return Z_DIRECTION_REVERSE;
        case PF_05: return Z_DIRECTION_REVERSE;
        case K1C: return Z_DIRECTION_REVERSE;
        case K1_Max_SE: return Z_DIRECTION_REVERSE;
        default: return Z_DIRECTION_FORWARD;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetSwapWayById(DeviceModel id) { return 1; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetDeploySettingById(DeviceModel id) { return CXY_SERVER_NULL; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetCustomerById(DeviceModel id) { return Customer_Creality; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetLanguageById(DeviceModel id)
{
    switch (id) {
        case CR_K1: return Language_English;
        case CR_K1_Max: return Language_English;
        case PF_05: return Language_English;
        case K1C: return Language_English;
        case K1_Max_SE: return Language_English;
        default: return Language_Chinese;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetSoundSizeById(DeviceModel id) { return 10; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetSoundSwitchById(DeviceModel id) { return 1; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetSoundeFfectById(DeviceModel id) { return 1; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetLightSwitchById(DeviceModel id) { return 1; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetLightValueById(DeviceModel id) { return 100; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetWifiSwitchById(DeviceModel id) { return 1; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetThemeModeById(DeviceModel id) { return 1; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetSelfTestSwitchById(DeviceModel id) { return 1; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetScreensaverById(DeviceModel id) { return 3; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetScreenValueById(DeviceModel id) { return 60; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetFullScreenById(DeviceModel id) { return 0; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetAutoPowerOffById(DeviceModel id) { return 0; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetUpgradeRemindById(DeviceModel id) { return 1; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetServerLocalById(SystemConfig_t config)
{
    if (config.deploy_setting == CXY_CN_SERVER ||
        config.deploy_setting == CXY_CN_PRE_SERVER)
    {
        return SYS_CN_SERVER;
    }
    else return SYS_COM_SERVER;
}

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetAgreePrivacyById(DeviceModel id) { return 0; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetDataCollectById(DeviceModel id) { return 0; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetdelayImageSwitchById(DeviceModel id) { return 1; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetdelayImageLocationById(DeviceModel id) { return 0; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetdelayImageFrameById(DeviceModel id) { return 15; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetdelayImageIntervalById(DeviceModel id) { return 5; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetdelayImageMinTimeById(DeviceModel id) { return 3; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static bool GetPowerLossSwitchById(DeviceModel id) { return true; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetAiControlSwitchById(DeviceModel id)
{
    switch (id) {
        case CR_K1: return 0;
        case Nebula_Pad: return 0;
        case CR_10_SE: return 0;
        case PF_05: return 0;
        case K1C: return 1;
        default: return 1;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetAiControlDetectionById(DeviceModel id) { return 1; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetAiControlPausePrintById(DeviceModel id) { return 0; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetAiControlFirstFloorById(DeviceModel id) { return 0; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetAiControlPastaTimeById(DeviceModel id, AiModeType mode)
{
    switch (mode) {
        case AI_MODE_TYPE_ROUTINE: return 30;
        case AI_MODE_TYPE_MAJOR: return 30;
        default: return 30;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static double GetAiControlPastaTruthById(DeviceModel id, AiModeType mode)
{
    switch (mode) {
        case AI_MODE_TYPE_ROUTINE: return 62.5;
        case AI_MODE_TYPE_MAJOR: return 57.5;
        default: return 62.5;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetAiControlDataCollectById(DeviceModel id) { return 0; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static double GetAiControlSundriesTruthById(DeviceModel id) { return 62.5; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetAiControlFlowDetectById(DeviceModel id) { return 0; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetAiControlOptimalHeightById(DeviceModel id) { return 50; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetAiControlAiModeById(DeviceModel id) { return AI_MODE_TYPE_ROUTINE; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetEnableSelfTestById(DeviceModel id) { return 0; }

/**
 * @description: 
 * @return {*}
 * @param {DeviceModel} id
 */
static int GetServerConfigById(DeviceModel id) { return SYS_OFFICIAL_SERVER; }

/*********************************************************
 *********************************************************
 ******************** 保存系统配置 *************************
 *********************************************************
 *********************************************************/
/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int SaveUserDataNotDelete(void)
{
    pthread_rwlock_rdlock(&rwLock);

    // 生成json数据
    json_object *userData = json_object_new_object();
    json_object_object_add(userData, "total_time", json_object_new_int(systemComfig.total_time));
    json_object_object_add(userData, "creality_num", json_object_new_int(systemComfig.creality_num));

    pthread_rwlock_unlock(&rwLock);
    CrLogI("total_time = %d\n", systemComfig.total_time);

    // 保存配置文件
    char *saveData = json_object_to_json_string(userData);
    int res = AesEncryptToFile(GetUserDataNotDeleteFilePtah(), saveData, strlen(saveData));
    json_object_put(userData);

    if (res != -1) return 1;
    else return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int ReadUserDataNotDelete(void)
{
    pthread_rwlock_wrlock(&rwLock);
    json_object *tempObj = NULL;

    // 从文件读取json数据
    json_object *userData = NULL;
    char *readData = AesDecryptFromFile(GetUserDataNotDeleteFilePtah());
    if (readData) {
        userData = json_tokener_parse(readData);
        free(readData);
    }

    // 判断是否获取配置
    if (!userData) userData = json_object_from_file(GetUserDataNotDeleteFilePtah());
    if (!userData) userData = json_object_new_object();

    // 获取累计使用时间
    tempObj = json_object_object_get(userData, "total_time");
    if (!tempObj) systemComfig.total_time = 0;
    else systemComfig.total_time = json_object_get_int(tempObj);

    // 获取权限标志
    tempObj = json_object_object_get(userData, "creality_num");
    if (!tempObj) systemComfig.creality_num = 0;
    else systemComfig.creality_num  = json_object_get_int(tempObj);

    pthread_rwlock_unlock(&rwLock);
    json_object_put(userData);

    // 保存配置文件
    SaveUserDataNotDelete();
    return 1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int SaveSystemVersion(void)
{
    pthread_rwlock_rdlock(&rwLock);
    json_object *version = json_object_new_object();
    json_object_object_add(version, "sys_version", json_object_new_string(systemComfig.sys_version));
    json_object_object_add(version, "fw_version", json_object_new_string(systemComfig.fw_version));
    json_object_object_add(version, "app_version", json_object_new_int(systemComfig.app_version));
    json_object_object_add(version, "hw_version", json_object_new_string(systemComfig.hw_version));
    json_object_object_add(version, "hw1_version", json_object_new_string(systemComfig.hw1_version));
    json_object_object_add(version, "website", json_object_new_string(systemComfig.website));
    CrLogI("sys_version = %s, fw_version = %s, app_version = %d, hw_version = %s, hw1_version = %s, website = %s",
            systemComfig.sys_version, systemComfig.fw_version, systemComfig.app_version,
            systemComfig.hw_version, systemComfig.hw1_version, systemComfig.website);

    pthread_rwlock_unlock(&rwLock);
    // 保存配置文件
    int res = json_object_to_file_ext(GetUserSystemVersionFilePath(), version, JSON_C_TO_STRING_PRETTY);
    json_object_put(version);

    if (res != -1) return 1;
    else return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int ReadSystemVersion(void)
{
    json_object *config = json_object_from_file(GetUserSystemVersionFilePath());
    if (!config) config = json_object_new_object();

    // 从配置文件获取系统版本参数
    pthread_rwlock_wrlock(&rwLock);

    // 获取系统版本
    json_object *tempObj = json_object_object_get(config, "sys_version");
    if (!tempObj) {    
        char buff[32] = {0};
        if (PopenSystem(GetDefaultGetSystemVersionPath(), buff, sizeof(buff))) {
            CrLogI("get system version = %s", buff);
            memcpy(systemComfig.sys_version, buff, strlen(buff));
        }
        else CrLogW("get system version fail !!\n");
    }
    else memcpy(systemComfig.sys_version, json_object_get_string(tempObj), json_object_get_string_len(tempObj));

    // 获取下位机版本
    tempObj = json_object_object_get(config, "fw_version");
    if (!tempObj) CrLogW("get fw version fail !!\n");
    else memcpy(systemComfig.fw_version, json_object_get_string(tempObj), json_object_get_string_len(tempObj));
    
    // 生成应用版本
    tempObj = json_object_object_get(config, "app_version");
    if (!tempObj) systemComfig.app_version = INTERNAL_DEVELOP_VERSION;
    else systemComfig.app_version = json_object_get_int(tempObj);

    // 获取系统硬件版本
    tempObj = json_object_object_get(config, "hw_version");
    if (!tempObj) {    
        char buff[32] = {0};
        if (PopenSystem(GetDefaultOtaBoardNameScript(), buff, sizeof(buff))) {
            CrLogI("get hw version = %s", buff);
            memcpy(systemComfig.hw_version, buff, strlen(buff));
        }
        else CrLogW("get hw version fail !!\n");
    }
    else memcpy(systemComfig.hw_version, json_object_get_string(tempObj), json_object_get_string_len(tempObj));

    // 获取下位机硬件版本
    tempObj = json_object_object_get(config, "hw1_version");
    if (!tempObj) CrLogW("get hw1 version fail !!\n");
    else memcpy(systemComfig.hw1_version, json_object_get_string(tempObj), json_object_get_string_len(tempObj));

    // 获取官网地址
    tempObj = json_object_object_get(config, "website");
    if (!tempObj) memcpy(systemComfig.website, COMPANY_OFFICIAL_WEBSITE, strlen(COMPANY_OFFICIAL_WEBSITE));
    else memcpy(systemComfig.website, json_object_get_string(tempObj), json_object_get_string_len(tempObj));

    // 释放资源，保存数据
    pthread_rwlock_unlock(&rwLock);
    json_object_put(config);
    SaveSystemVersion();
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int SaveSystemConfig(void)
{
    pthread_rwlock_rdlock(&rwLock);
    json_object *device_info = json_object_new_object();
    json_object_object_add(device_info, "device_sn", json_object_new_string(systemComfig.device_sn));
    json_object_object_add(device_info, "device_mac", json_object_new_string(systemComfig.device_mac));
    json_object_object_add(device_info, "model", json_object_new_int(systemComfig.model));
    json_object_object_add(device_info, "model_str", json_object_new_string(systemComfig.model_str));
    json_object_object_add(device_info, "bed_length", json_object_new_int(systemComfig.bed_length));
    json_object_object_add(device_info, "bed_width", json_object_new_int(systemComfig.bed_width));
    json_object_object_add(device_info, "bed_hight", json_object_new_int(systemComfig.bed_hight));
    json_object_object_add(device_info, "ui_direction", json_object_new_int(systemComfig.ui_direction));
    json_object_object_add(device_info, "z_direction", json_object_new_int(systemComfig.z_direction));
    CrLogI("device_sn = %s, device_mac = %s, model = %d, model_str = %s, bed_length = %d, bed_width = %d, bed_hight = %d",
        systemComfig.device_sn, systemComfig.device_mac, systemComfig.model,
        systemComfig.model_str, systemComfig.bed_length, systemComfig.bed_width,
        systemComfig.bed_hight);
    CrLogI("ui_direction = %d, z_direction = %d",
        systemComfig.ui_direction, systemComfig.z_direction);
    
    json_object *user_info = json_object_new_object();
    json_object_object_add(user_info, "swap_way", json_object_new_int(systemComfig.swap_way));
    json_object_object_add(user_info, "deploy_setting", json_object_new_int(systemComfig.deploy_setting));
    json_object_object_add(user_info, "customer", json_object_new_int(systemComfig.customer));
    json_object_object_add(user_info, "language", json_object_new_int(systemComfig.language));
    json_object_object_add(user_info, "sound_size", json_object_new_int(systemComfig.sound_size));
    json_object_object_add(user_info, "sound_sw", json_object_new_int(systemComfig.sound_sw));
    json_object_object_add(user_info, "sounde_ffect", json_object_new_int(systemComfig.sounde_ffect));
    json_object_object_add(user_info, "light_sw", json_object_new_int(systemComfig.light_sw));
    json_object_object_add(user_info, "light_value", json_object_new_int(systemComfig.light_value));
    json_object_object_add(user_info, "wifi_sw", json_object_new_int(systemComfig.wifi_sw));
    json_object_object_add(user_info, "theme_mode", json_object_new_int(systemComfig.theme_mode));
    json_object_object_add(user_info, "self_test_sw", json_object_new_int(systemComfig.self_test_sw));
    json_object_object_add(user_info, "screensaver", json_object_new_int(systemComfig.screensaver));
    json_object_object_add(user_info, "screen_value", json_object_new_int(systemComfig.screen_value));
    json_object_object_add(user_info, "full_screen", json_object_new_int(systemComfig.full_screen));
    json_object_object_add(user_info, "auto_power_off", json_object_new_int(systemComfig.auto_power_off));
    json_object_object_add(user_info, "enableselftest", json_object_new_int(systemComfig.enableselftest));
    json_object_object_add(user_info, "time_zone", json_object_new_string(systemComfig.time_zone));
    json_object_object_add(user_info, "server_config", json_object_new_int(systemComfig.server_config));
    json_object_object_add(user_info, "upgrade_remind", json_object_new_int(systemComfig.upgrade_remind));
    json_object_object_add(user_info, "server_local", json_object_new_int(systemComfig.server_local));
    json_object_object_add(user_info, "agree_privacy", json_object_new_int(systemComfig.agree_privacy));
    json_object_object_add(user_info, "host_name", json_object_new_string(systemComfig.host_name));
    json_object_object_add(user_info, "data_collect", json_object_new_int(systemComfig.data_collect));
    
    CrLogI("swap_way = %d, deploy_setting = %d, customer = %d, language = %d, sound_size = %d, sound_sw = %d, sounde_ffect = %d",
        systemComfig.swap_way, systemComfig.deploy_setting, systemComfig.customer,
        systemComfig.language, systemComfig.sound_size, systemComfig.sound_sw, systemComfig.sounde_ffect);
    CrLogI("light_sw = %d, light_value = %d, wifi_sw = %d, theme_mode = %d, self_test_sw = %d, screensaver = %d",
        systemComfig.light_sw, systemComfig.light_value, systemComfig.wifi_sw,
        systemComfig.theme_mode, systemComfig.self_test_sw, systemComfig.screensaver);
    CrLogI("screen_value = %d, full_screen = %d, auto_power_off = %d, time_zone = %s, server_config = %d, upgrade_remind = %d",
        systemComfig.screen_value, systemComfig.full_screen, systemComfig.auto_power_off,
        systemComfig.time_zone, systemComfig.server_config, systemComfig.upgrade_remind);
    CrLogI("server_local = %d, agree_privacy = %d\n",
        systemComfig.server_local, systemComfig.agree_privacy);
    
    json_object *comfig = json_object_new_object();
    json_object_object_add(comfig, "device_info", device_info);
    json_object_object_add(comfig, "user_info", user_info);
    pthread_rwlock_unlock(&rwLock);
    // 保存配置文件
    int res = json_object_to_file_ext(GetUserSystemConfigFilePath(), comfig, JSON_C_TO_STRING_PRETTY);
    json_object_put(comfig);

    if (res != -1) return 1;
    else return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {SystemConfig_t} *systemComfig
 */
static void GenerateDeploySetting(SystemConfig_t *config)
{
    // 根据用户设置，生成服务器部署环境
    if (config->server_config == SYS_OFFICIAL_SERVER)
    {
        if (config->server_local == SYS_CN_SERVER)
            config->deploy_setting = CXY_CN_SERVER;
        else config->deploy_setting = CXY_COM_SERVER;
    }
    else if (config->server_config == SYS_PRE_RELEASE_SERVER)
    {
        if (config->server_local == SYS_CN_SERVER)
            config->deploy_setting = CXY_CN_PRE_SERVER;
        else config->deploy_setting = CXY_COM_PRE_SERVER;
    }
    else if (config->server_config == SYS_DEBUG_SERVER)
    {
        config->deploy_setting = CXY_DEBUG_SERVER;
    }
    else config->deploy_setting = CXY_TEST_SERVER;
    
    CrLogI("generates deploy setting = %d\n", config->deploy_setting);
}

/**
 * @description: 
 * @return {*}
 * @param {SystemConfig_t} config
 */
static void RestartWebrtcFromDeploySetting(SystemConfig_t config)
{
    // 获取 webrtc 部署环境
    int webrtcDeploy = WEBRTC_TEST_SERVER;
    switch (config.deploy_setting)
    {
        case CXY_TEST_SERVER: webrtcDeploy = WEBRTC_TEST_SERVER; break;
        case CXY_CN_SERVER: webrtcDeploy = WEBRTC_CN_SERVER; break;
        case CXY_COM_SERVER: webrtcDeploy = WEBRTC_COM_SERVER; break;
        case CXY_CN_PRE_SERVER: webrtcDeploy = WEBRTC_CN_PRE_SERVER; break;
        case CXY_COM_PRE_SERVER: webrtcDeploy = WEBRTC_COM_PRE_SERVER; break;
        case CXY_DEBUG_SERVER: webrtcDeploy = WEBRTC_DEBUG_SERVER; break;
    }
    CrLogI("webrtc deploy = %d", webrtcDeploy);

    // 重启 webrtc
    char cmd[254] = {0};
    snprintf(cmd, 254, GetDefaultRestartWebrtcScript(), webrtcDeploy);
    CrLogI("restart cmd = %s\n", cmd);

    #ifdef CROSS_COMPILE
    char sysRes[1024] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);
     #endif
}

/**
 * @description: 
 * @return {*}
 * @param {SystemConfig_t} config
 */
static void CollectDataControl(SystemConfig_t config)
{
    // 判断是否同意隐私协议
    char control[10] = {0};
    if (config.agree_privacy) strcat(control, "start");
    else strcat(control, "stop");

    // 数据收集控制脚本
    char cmd[254] = {0};
    snprintf(cmd, 254, GetDefaultRestartReportScript(), control);

    #ifdef CROSS_COMPILE
    char sysRes[1024] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);
     #endif
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int ReadSystemConfig(void)
{
    pthread_rwlock_wrlock(&rwLock);

    // 从文件读取json数据
    json_object *config = json_object_from_file(GetUserSystemConfigFilePath());
    if (!config) config = json_object_new_object();

    // 获取 device_info 的json
    json_object *deviceInfoObj = json_object_object_get(config, "device_info");
    if (!deviceInfoObj) deviceInfoObj = json_object_new_object();
    json_object *tempObj = NULL;

    // 获取SN
    #ifdef CROSS_COMPILE
    char buff[64] = {0};
    bzero(buff, sizeof(buff));
    if (PopenSystem(GetDefaultCertifiedSnScript(), buff, sizeof(buff))) {
        CrLogI("get certified sn = %s", buff);
        memcpy(systemComfig.device_sn, buff, strlen(buff));
    }
    else CrLogW("get certified sn fail !!\n");
    #else
    tempObj = json_object_object_get(deviceInfoObj, "device_sn");
    if (tempObj) memcpy(systemComfig.device_sn, json_object_get_string(tempObj), json_object_get_string_len(tempObj));
    #endif

    // 获取MAC
    #ifdef CROSS_COMPILE
    bzero(buff, sizeof(buff));
    if (PopenSystem(GetDefaultCertifiedMacScript(), buff, sizeof(buff))) {
        CrLogI("get certified mac = %s", buff);
        memcpy(systemComfig.device_mac, buff, strlen(buff));
    }
    else CrLogW("get certified mac fail !!\n");
    #else
    tempObj = json_object_object_get(deviceInfoObj, "device_mac");
    if (tempObj) memcpy(systemComfig.device_mac, json_object_get_string(tempObj), json_object_get_string_len(tempObj));
    #endif

    // 获取机器型号字符
    tempObj = json_object_object_get(deviceInfoObj, "model_str");
    if (!tempObj) {
        #ifdef CROSS_COMPILE
        bzero(buff, sizeof(buff));
        if (PopenSystem(GetDefaultDeviceModelScript(), buff, sizeof(buff))) {
            CrLogI("get device model str = %s", buff);
            memcpy(systemComfig.model_str, buff, strlen(buff));
        }
        else CrLogE("get device model fail !!\n");
        #else
        memcpy(systemComfig.model_str, "CR-10 H1", strlen("CR-10 H1"));
        #endif
    }
    else memcpy(systemComfig.model_str, json_object_get_string(tempObj), json_object_get_string_len(tempObj));

    // 获取机器型号
    tempObj = json_object_object_get(deviceInfoObj, "model");
    if (!tempObj) systemComfig.model = GetDeviceIdByDeviceType(systemComfig.model_str);
    else systemComfig.model = json_object_get_int(tempObj);

    // 获取热床大小
    tempObj = json_object_object_get(deviceInfoObj, "bed_length");
    if (!tempObj) systemComfig.bed_length = GetBedLengthById(systemComfig.model);
    else systemComfig.bed_length = json_object_get_int(tempObj);

    tempObj = json_object_object_get(deviceInfoObj, "bed_width");
    if (!tempObj) systemComfig.bed_width = GetBedWidthById(systemComfig.model);
    else systemComfig.bed_width = json_object_get_int(tempObj);

    tempObj = json_object_object_get(deviceInfoObj, "bed_hight");
    if (!tempObj) systemComfig.bed_hight = GetBedHightById(systemComfig.model);
    else systemComfig.bed_hight = json_object_get_int(tempObj);

    // 获取UI方向
    tempObj = json_object_object_get(deviceInfoObj, "ui_direction");
    if (!tempObj) systemComfig.ui_direction = GetUiDirectionById(systemComfig.model);
    else systemComfig.ui_direction = json_object_get_int(tempObj);

    // 获取Z轴方向
    tempObj = json_object_object_get(deviceInfoObj, "z_direction");
    if (!tempObj) systemComfig.z_direction = GetZDirectionById(systemComfig.model);
    else systemComfig.z_direction = json_object_get_int(tempObj);

    // 获取 user_info 的json
    json_object *userInfoObj = json_object_object_get(config, "user_info");
    if (!userInfoObj) userInfoObj = json_object_new_object();

    // 获取交互方式
    tempObj = json_object_object_get(userInfoObj, "swap_way");
    if (!tempObj) systemComfig.swap_way = GetSwapWayById(systemComfig.model);
    else systemComfig.swap_way = json_object_get_int(tempObj);

    // 获取设备部署环境
    tempObj = json_object_object_get(userInfoObj, "deploy_setting");
    if (!tempObj) systemComfig.deploy_setting = GetDeploySettingById(systemComfig.model);
    else systemComfig.deploy_setting = json_object_get_int(tempObj);

    // 获取客户ID
    tempObj = json_object_object_get(userInfoObj, "customer");
    if (!tempObj) systemComfig.customer = GetCustomerById(systemComfig.model);
    else systemComfig.customer = json_object_get_int(tempObj);

    // 获取语言类型
    tempObj = json_object_object_get(userInfoObj, "language");
    if (!tempObj) systemComfig.language = GetLanguageById(systemComfig.model);
    else systemComfig.language = json_object_get_int(tempObj);

    // 获取音量大小
    tempObj = json_object_object_get(userInfoObj, "sound_size");
    if (!tempObj) systemComfig.sound_size = GetSoundSizeById(systemComfig.model);
    else systemComfig.sound_size = json_object_get_int(tempObj);
    // 设置音量大小
    #ifdef CROSS_COMPILE
    char setCmd[256] = {0};
    snprintf(setCmd, sizeof(setCmd), "%s %d", GetDefaultGetSoundSizeScript(), systemComfig.sound_size);
    // 设置
    bzero(buff, sizeof(buff));
    if (!PopenSystem(setCmd, buff, sizeof(buff)))
        CrLogW("set sound size fail !!\n");
    #endif

    // 获取声音开关
    tempObj = json_object_object_get(userInfoObj, "sound_sw");
    if (!tempObj) systemComfig.sound_sw = GetSoundSwitchById(systemComfig.model);
    else systemComfig.sound_sw = json_object_get_int(tempObj);

    // 获取音效设置
    tempObj = json_object_object_get(userInfoObj, "sounde_ffect");
    if (!tempObj) systemComfig.sounde_ffect = GetSoundeFfectById(systemComfig.model);
    else systemComfig.sounde_ffect = json_object_get_int(tempObj);

    // 获取灯光开关
    tempObj = json_object_object_get(userInfoObj, "light_sw");
    if (!tempObj) systemComfig.light_sw = GetLightSwitchById(systemComfig.model);
    else systemComfig.light_sw = json_object_get_int(tempObj);

    // 获取灯光亮度
    tempObj = json_object_object_get(userInfoObj, "light_value");
    if (!tempObj) systemComfig.light_value = GetLightValueById(systemComfig.model);
    else systemComfig.light_value = json_object_get_int(tempObj);

    // 获取wifi开关
    tempObj = json_object_object_get(userInfoObj, "wifi_sw");
    if (!tempObj) systemComfig.wifi_sw = GetWifiSwitchById(systemComfig.model);
    else systemComfig.wifi_sw = json_object_get_int(tempObj);

    // 获取主题
    tempObj = json_object_object_get(userInfoObj, "theme_mode");
    if (!tempObj) systemComfig.theme_mode = GetThemeModeById(systemComfig.model);
    else systemComfig.theme_mode = json_object_get_int(tempObj);

    // 获取开机自检
    tempObj = json_object_object_get(userInfoObj, "self_test_sw");
    if (!tempObj) systemComfig.self_test_sw = GetSelfTestSwitchById(systemComfig.model);
    else systemComfig.self_test_sw = json_object_get_int(tempObj);
    // 是否需要开机自检
    if (systemComfig.self_test_sw) UpdataDeviceStateSelfTest(DEVICE_STATE_SELF_TEST);

    // 获取屏保时间
    tempObj = json_object_object_get(userInfoObj, "screensaver");
    if (!tempObj) systemComfig.screensaver = GetScreensaverById(systemComfig.model);
    else systemComfig.screensaver = json_object_get_int(tempObj);

    // 获取屏幕亮度
    tempObj = json_object_object_get(userInfoObj, "screen_value");
    if (!tempObj) systemComfig.screen_value = GetScreenValueById(systemComfig.model);
    else systemComfig.screen_value = json_object_get_int(tempObj);
    // 设置屏幕亮度
    #ifdef CROSS_COMPILE
    bzero(setCmd, sizeof(setCmd));
    snprintf(setCmd, sizeof(setCmd), "%s %d", GetDefaultGetScreenValueScript(), systemComfig.screen_value);
    // 设置
    bzero(buff, sizeof(buff));
    if (!PopenSystem(setCmd, buff, sizeof(buff)))
        CrLogW("set screen value fail !!\n");
    #endif

    // 获取打印全屏时间
    tempObj = json_object_object_get(userInfoObj, "full_screen");
    if (!tempObj) systemComfig.full_screen = GetFullScreenById(systemComfig.model);
    else systemComfig.full_screen = json_object_get_int(tempObj);

    // 获取自动关机
    tempObj = json_object_object_get(userInfoObj, "auto_power_off");
    if (!tempObj) systemComfig.auto_power_off = GetAutoPowerOffById(systemComfig.model);
    else systemComfig.auto_power_off = json_object_get_int(tempObj);

    // 获取累计使用时间
    tempObj = json_object_object_get(userInfoObj, "total_time");
    if (tempObj) systemComfig.total_time = json_object_get_int(tempObj);

    // 获取打印校准
    tempObj = json_object_object_get(userInfoObj, "enableselftest");
    if (!tempObj) systemComfig.enableselftest = GetEnableSelfTestById(systemComfig.model);
    else systemComfig.enableselftest = json_object_get_int(tempObj);

    // 获取时区
    #ifdef CROSS_COMPILE
    bzero(buff, sizeof(buff));
    if (PopenSystem(GetDefaultSystemTimeZoneScript(), buff, sizeof(buff))) {
        CrLogI("get time zone str = %s", buff);
        memcpy(systemComfig.time_zone, buff, strlen(buff));
    }
    else CrLogE("get time zone fail !!\n");
    #else
    tempObj = json_object_object_get(userInfoObj, "time_zone");
    if (tempObj) memcpy(systemComfig.time_zone, json_object_get_string(tempObj), json_object_get_string_len(tempObj));
    #endif

    // 获取服务器配置
    tempObj = json_object_object_get(userInfoObj, "server_config");
    if (!tempObj) systemComfig.server_config = GetServerConfigById(systemComfig.model);
    else systemComfig.server_config = json_object_get_int(tempObj);

    // 获取升级提醒
    tempObj = json_object_object_get(userInfoObj, "upgrade_remind");
    if (!tempObj) systemComfig.upgrade_remind = GetUpgradeRemindById(systemComfig.model);
    else systemComfig.upgrade_remind = json_object_get_int(tempObj);

    // 获取服务器位置
    tempObj = json_object_object_get(userInfoObj, "server_local");
    if (!tempObj) systemComfig.server_local = GetServerLocalById(systemComfig);
    else systemComfig.server_local = json_object_get_int(tempObj);

    // 获取是否同意隐私协议
    tempObj = json_object_object_get(userInfoObj, "agree_privacy");
    if (!tempObj) systemComfig.agree_privacy = GetAgreePrivacyById(systemComfig.model);
    else systemComfig.agree_privacy = json_object_get_int(tempObj);

    // 获取主机名称
    char host_name[64] = {0};
    GetConfigFromFile(SYSTEM_HOSTNAME_DIR, host_name, sizeof(host_name));
    char *end = strstr(host_name, "\n");
    if (end) end[0] = '\0';
    CrLogI("get host name str = %s", host_name);
    memcpy(systemComfig.host_name, host_name, strlen(host_name));

    // 获取是否同意收集数据
    tempObj = json_object_object_get(userInfoObj, "data_collect");
    if (!tempObj) systemComfig.data_collect = GetDataCollectById(systemComfig.model);
    else systemComfig.data_collect = json_object_get_int(tempObj);
   
    // 最后检测生成服务器部署环境
    GenerateDeploySetting(&systemComfig);
    RestartWebrtcFromDeploySetting(systemComfig);
    // 判断是否启动数据收集
    CollectDataControl(systemComfig);

    pthread_rwlock_unlock(&rwLock);
    json_object_put(config);
    SaveSystemConfig();

    return 1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static void MsaterSyncSystemConfig(void)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_SYNC_SYSTEM_CONFIG, "", 0);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_AUDIO_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_UPGRADE_MANAGER, &send, size);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
SystemConfig_t GetSystemConfig(void)
{
    pthread_rwlock_rdlock(&rwLock);
    SystemConfig_t config = systemComfig;
    pthread_rwlock_unlock(&rwLock);
    return config;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *dns
 */
static bool CheckDnsLegal(char *dns)
{
    char *regex = "^(([a-zA-Z0-9]|[a-zA-Z0-9][a-zA-Z0-9\\-]*[a-zA-Z0-9])\\.)*([A-Za-z0-9]|[A-Za-z0-9][A-Za-z0-9\\-]*[A-Za-z0-9])$";
    regmatch_t regmatch[5];
    int regexSize = UserGetRegexStr(dns, regex, regmatch, 5);

    if(regexSize != 1) return false;
    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {SystemConfigProto} *config
 */
int UpdataSystemConfig(SystemConfigProto *config)
{
    // 记录前一次状态
    SystemConfig_t lastSystemComfig = systemComfig;

    // 修改配置
    pthread_rwlock_wrlock(&rwLock);
    // 机器型号字符
    if (config->has_model_str) {
        bzero(systemComfig.model_str, sizeof(systemComfig.model_str));
        memcpy(systemComfig.model_str, config->model_str.data, config->model_str.len);
        CrLogI("updata device model = %s", systemComfig.model_str);
        // 根据设备类型字符串，获取设备类型ID
        systemComfig.model = GetDeviceIdByDeviceType(systemComfig.model_str);
    }
    // 热床大小
    if (config->has_bed_length) {
        systemComfig.bed_length = config->bed_length;
        CrLogI("updata bed length = %d", systemComfig.bed_length);
    }
    if (config->has_bed_width) {
        systemComfig.bed_width = config->bed_width;
        CrLogI("updata bed width = %d", systemComfig.bed_width);
    }
    if (config->has_bed_hight) {
        systemComfig.bed_hight = config->bed_hight;
        CrLogI("updata bed hight = %d", systemComfig.bed_hight);
    }
    // 设备部署环境
    if (config->has_deploy_setting) {
        systemComfig.deploy_setting = config->deploy_setting;
        CrLogI("updata deploy setting = %d", systemComfig.deploy_setting);
    }
    // 语言类型
    if (config->has_language) {
        systemComfig.language = config->language;
        CrLogI("display set language type = %d", systemComfig.language);
    }
    // 音量大小
    if (config->has_sound_size) {
        #ifdef CROSS_COMPILE
        char resBuf[32] = {0};
        char setCmd[256] = {0};
        snprintf(setCmd, sizeof(setCmd), "%s %d", GetDefaultGetSoundSizeScript(), config->sound_size);
        // 设置
        if (!PopenSystem(setCmd, resBuf, sizeof(resBuf)))
            CrLogW("set sound size fail !!\n");
        // 获取
        bzero(resBuf, sizeof(resBuf));
        if (!PopenSystem(GetDefaultGetSoundSizeScript(), resBuf, sizeof(resBuf)))
            CrLogW("get sound size fail !!\n");

        CrLogI("get sound size = %s", resBuf);
        systemComfig.sound_size = atoi(resBuf);
        #else
        systemComfig.sound_size = config->sound_size;
        #endif
        CrLogI("display set sound size = %d", systemComfig.sound_size);
    }
    // 声音开关
    if (config->has_sound_sw) {
        systemComfig.sound_sw = config->sound_sw;
        CrLogI("display set sound sw = %d", systemComfig.sound_sw);
    }
    // 音效设置
    if (config->has_sounde_ffect) {
        systemComfig.sounde_ffect = config->sounde_ffect;
        CrLogI("display set sounde ffect = %d", systemComfig.sounde_ffect);
    }
    // 灯光开关
    if (config->has_light_sw) {
        systemComfig.light_sw = config->light_sw;
        CrLogI("display set light sw = %d", systemComfig.light_sw);

        // 修改灯光亮度
        MutableTypeData value = MUTABLE_TYPE_DATA__INIT;
        value.has_int_v = 1;
        if (!systemComfig.light_sw) value.int_v = 0;
        else value.int_v = systemComfig.light_value;

        GET_MESSAGE_BUFF(buff);
        size_t len = mutable_type_data__pack(&value, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_CMD_GCODE_LIGHT_VALUE_REQ, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 灯光亮度
    if (config->has_light_value) {
        systemComfig.light_value = config->light_value;
        CrLogI("display set light value = %d", systemComfig.light_value);

        // 修改灯光亮度
        if (systemComfig.light_sw) {
            MutableTypeData value = MUTABLE_TYPE_DATA__INIT;
            value.has_int_v = 1;
            value.int_v = systemComfig.light_value;

            GET_MESSAGE_BUFF(buff);
            size_t len = mutable_type_data__pack(&value, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_CMD_GCODE_LIGHT_VALUE_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
    }
    // 主题
    if (config->has_theme_mode) {
        systemComfig.theme_mode = config->theme_mode;
        CrLogI("display set theme mode = %d", systemComfig.theme_mode);
    }
    // 开机自检
    if (config->has_self_test_sw) {
        systemComfig.self_test_sw = config->self_test_sw;
        CrLogI("display set self test = %d", systemComfig.self_test_sw);
        // 开机自检完成
        if (!systemComfig.self_test_sw) UpdataDeviceStateSelfTest(DEVICE_STATE_IDLE);
    }
    // 屏保时间
    if (config->has_screensaver) {
        systemComfig.screensaver = config->screensaver;
        CrLogI("display set screensaver = %d", systemComfig.screensaver);
    }
    // 屏幕亮度
    if (config->has_screen_value) {
        #ifdef CROSS_COMPILE
        char resBuf[32] = {0};
        char setCmd[256] = {0};
        snprintf(setCmd, sizeof(setCmd), "%s %d", GetDefaultGetScreenValueScript(), config->screen_value);
        // 设置
        if (!PopenSystem(setCmd, resBuf, sizeof(resBuf)))
            CrLogW("set screen value fail !!\n");
        // 获取
        bzero(resBuf, sizeof(resBuf));
        if (!PopenSystem(GetDefaultGetScreenValueScript(), resBuf, sizeof(resBuf)))
            CrLogW("get screen value fail !!\n");

        CrLogI("get screen value = %s", resBuf);
        systemComfig.screen_value = atoi(resBuf);
        #else
        systemComfig.screen_value = config->screen_value;
        #endif
        CrLogI("display set screen value = %d", systemComfig.screen_value);
    }
    // UI方向
    if (config->has_ui_direction) {
        systemComfig.ui_direction = config->ui_direction;
        CrLogI("display set ui direction = %d", systemComfig.ui_direction);
        // 重启系统
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_CONTROL_SYSTEM_REBOOT, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
    // 打印全屏时间
    if (config->has_full_screen) {
        systemComfig.full_screen = config->full_screen;
        CrLogI("display set full screen = %d", systemComfig.full_screen);
    }
    // 自动关机
    if (config->has_auto_power_off) {
        systemComfig.auto_power_off = config->auto_power_off;
        CrLogI("display set auto power off = %d", systemComfig.auto_power_off);
    }
    // 累计使用时间
    if (config->has_total_time) {
        systemComfig.total_time += config->total_time;
        CrLogI("updata print total = %d", systemComfig.total_time);
    }
    // 打印前检测开关
    if (config->has_enableselftest) {
        systemComfig.enableselftest = config->enableselftest;
        CrLogI("set enableselftest = %d", systemComfig.enableselftest);
    }
    // 设置时区
    if (config->has_time_zone) {
        #ifdef CROSS_COMPILE
        char time_zone_str[32] = {0};
        memcpy(time_zone_str, config->time_zone.data, config->time_zone.len);

        char resBuf[32] = {0};
        char setCmd[256] = {0};
        snprintf(setCmd, sizeof(setCmd), "%s %s", GetDefaultSystemTimeZoneScript(), time_zone_str);
        // 设置
        if (!PopenSystem(setCmd, resBuf, sizeof(resBuf)))
            CrLogW("set time zone fail !!\n");
        // 获取
        bzero(resBuf, sizeof(resBuf));
        if (!PopenSystem(GetDefaultSystemTimeZoneScript(), resBuf, sizeof(resBuf)))
            CrLogW("get time zone fail !!\n");

        CrLogI("get screen value = %s", resBuf);
        bzero(systemComfig.time_zone, sizeof(systemComfig.time_zone));
        strcat(systemComfig.time_zone, resBuf);
        #else
        bzero(systemComfig.time_zone, sizeof(systemComfig.time_zone));
        memcpy(systemComfig.time_zone, config->time_zone.data, config->time_zone.len);
        #endif
        CrLogI("set time zone = %s", systemComfig.time_zone);
    }
    // 设置服务器配置
    if (config->has_server_config) {
        systemComfig.server_config = config->server_config;
        CrLogI("updata server config = %d\n", systemComfig.server_config);
    }
    // 设置升级提醒
    if (config->has_upgrade_remind) {
        systemComfig.upgrade_remind = config->upgrade_remind;
        CrLogI("set upgrade remind = %d", systemComfig.upgrade_remind);
    }
    // 设置服务器位置
    if (config->has_server_local) {
        systemComfig.server_local = config->server_local;
        CrLogI("set server local = %d", systemComfig.server_local);
    }
    // 设置是否同意隐私协议
    if (config->has_agree_privacy) {
        systemComfig.agree_privacy = config->agree_privacy;
        CrLogI("set agree privacy = %d", systemComfig.agree_privacy);
    }
    // 设置权限标志
    if (config->has_creality_num) {
        systemComfig.creality_num = config->creality_num;
    }
    // 设置主机名称
    if (config->has_host_name) {
        // 判断名称是否符合规则
        char host_name[64] = {0};
        memcpy(host_name, config->host_name.data, config->host_name.len);
        CrLogI("set host name = %s", host_name);

        if (CheckDnsLegal(host_name)) {
            #ifdef CROSS_COMPILE
            // 修改主机名
            strcat(host_name, "\n");
            SaveConfigToFile(SYSTEM_HOSTNAME_DIR, host_name, strlen(host_name));
            // 重新获取主机名
            bzero(host_name, sizeof(host_name));
            GetConfigFromFile(SYSTEM_HOSTNAME_DIR, host_name, sizeof(host_name));
            char *end = strstr(host_name, "\n");
            if (end) end[0] = '\0';
            // 重启部分服务
            system(RESTART_HOSTNAME);
            system(RESTART_MDNS);
            #endif
            bzero(systemComfig.host_name, sizeof(systemComfig.host_name));
            memcpy(systemComfig.host_name, host_name, strlen(host_name));
        }
        else CrLogW("The hostname does not comply with the rules\n");
    }
    // 设置是否同意收集数据
    if (config->has_data_collect) {
        systemComfig.data_collect = config->data_collect;
        CrLogI("set data collect = %d", systemComfig.data_collect);
    }

    // 判断服务器连接是否修改，是否需要删除IOT信息
    if (systemComfig.server_config != lastSystemComfig.server_config ||
        systemComfig.server_local != lastSystemComfig.server_local)
    {
        CrLogI("Modify the device deployment environment\n");
        // 生成服务器部署环境
        GenerateDeploySetting(&systemComfig);
        RestartWebrtcFromDeploySetting(systemComfig);

        // 重启app-server服务
        RestartNowAppServer();
    }
    else if (systemComfig.agree_privacy != lastSystemComfig.agree_privacy) {
        // 判断是否启动数据收集
        CollectDataControl(systemComfig);
        // 重新获取IP地址
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_CMD_WIFI_USER_GET_WIFI_INFO_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_WIFI_MANAGER, &send, size);
        // 重启app-server服务
        RestartNowAppServer();
    }
    
    pthread_rwlock_unlock(&rwLock);
    MsaterSyncSystemConfig();
    return (SaveSystemConfig() && SaveSystemVersion() && SaveUserDataNotDelete());
}

/*********************************************************
 *********************************************************
 ******************** 保存打印偏好 **********************
 *********************************************************
 *********************************************************/
/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int SavePrintRrefer(void)
{
    // 打印偏好信息
    json_object *Material = json_object_object_get(saveUserRrefer, "material");
    if (Material) {
        for (int i = 0; i < json_object_array_length(Material); i++)
        {
            json_object *printMaterial = json_object_array_get_idx(Material, i);
            json_object *tempObj;
            json_object_object_get_ex(printMaterial, "id", &tempObj);
            int id = json_object_get_int(tempObj);
            json_object_object_get_ex(printMaterial, "name", &tempObj);
            const char *name = json_object_get_string(tempObj);
            json_object_object_get_ex(printMaterial, "hotend", &tempObj);
            int hotendTemp = json_object_get_int(tempObj);
            json_object_object_get_ex(printMaterial, "bed", &tempObj);
            int bedTemp = json_object_get_int(tempObj);
            CrLogI("Print Materials; id = %d, name = %s, hotend = %d, bed = %d",
                    id, name, hotendTemp, bedTemp);
        }
    }
    // 自动PID信息
    json_object *autoPid = json_object_object_get(saveUserRrefer, "auto_pid");
    if (autoPid) {
        for (int i = 0; i < json_object_array_length(autoPid); i++)
        {
            json_object *pid = json_object_array_get_idx(autoPid, i);
            json_object *tempObj;
            json_object_object_get_ex(pid, "id", &tempObj);
            int id = json_object_get_int(tempObj);
            json_object_object_get_ex(pid, "name", &tempObj);
            const char *name = json_object_get_string(tempObj);
            json_object_object_get_ex(pid, "temp", &tempObj);
            int temp = json_object_get_int(tempObj);
            json_object_object_get_ex(pid, "time", &tempObj);
            int time = json_object_get_int(tempObj);
            CrLogI("auto pid; id = %d, name = %s, temp = %d, time = %d",
                    id, name, temp, time);
        }
    }
    // 延时摄影信息
    json_object *delayImageObj = json_object_object_get(saveUserRrefer, "delay_image");
    if (delayImageObj) {
        int sw = 0, location = 0, frame = 0, interval = 0, minTime = 0;
        // 开关
        json_object *switchObj = json_object_object_get(delayImageObj, "switch");
        if (switchObj != NULL && json_object_is_type(switchObj, json_type_int))
            sw = json_object_get_int(switchObj);
        // 位置
        json_object *locationObj = json_object_object_get(delayImageObj, "location");
        if (locationObj != NULL && json_object_is_type(locationObj, json_type_int))
            location = json_object_get_int(locationObj);
        // 帧数
        json_object *frameObj = json_object_object_get(delayImageObj, "frame");
        if (frameObj != NULL && json_object_is_type(frameObj, json_type_int))
            frame = json_object_get_int(frameObj);
        // 间隔层数
        json_object *intervalObj = json_object_object_get(delayImageObj, "interval");
        if (intervalObj != NULL && json_object_is_type(intervalObj, json_type_int))
            interval = json_object_get_int(intervalObj);
        // 最短时长
        json_object *minTimeObj = json_object_object_get(delayImageObj, "minTime");
        if (minTimeObj != NULL && json_object_is_type(minTimeObj, json_type_int))
            minTime = json_object_get_int(minTimeObj);

        CrLogI("delay image; sw = %d, location = %d, frame = %d, interval = %d, minTime = %d",
                sw, location, frame, interval, minTime);
    }
    // 断电续打信息
    json_object *powerLossObj = json_object_object_get(saveUserRrefer, "power_loss");
    if (powerLossObj) {
        bool sw = 0;
        // 开关
        json_object *switchObj = json_object_object_get(powerLossObj, "switch");
        if (switchObj != NULL && json_object_is_type(switchObj, json_type_boolean))
            sw = json_object_get_boolean(switchObj);

        CrLogI("power loss; sw = %d", sw);
    }
    // AI控制信息
    json_object *aiControlObj = json_object_object_get(saveUserRrefer, "ai_control");
    if (aiControlObj) {
        int sw = 0, detection = 0, pausePrint = 0, firstFloor = 0, pastaTime = 0, dataCollect = 0, flowDetect = 0;
        int optimalHeight = 0, aiMode = 0;
        double pastaTruth = 0, sundriesTruth = 0;
        // 开关
        json_object *switchObj = json_object_object_get(aiControlObj, "switch");
        if (switchObj != NULL && json_object_is_type(switchObj, json_type_int))
            sw = json_object_get_int(switchObj);
        // 故障检测
        json_object *detectionObj = json_object_object_get(aiControlObj, "detection");
        if (detectionObj != NULL && json_object_is_type(detectionObj, json_type_int))
            detection = json_object_get_int(detectionObj);
        // 故障暂停打印
        json_object *pausePrintObj = json_object_object_get(aiControlObj, "pausePrint");
        if (pausePrintObj != NULL && json_object_is_type(pausePrintObj, json_type_int))
            pausePrint = json_object_get_int(pausePrintObj);
        // 首层检测
        json_object *firstFloorObj = json_object_object_get(aiControlObj, "firstFloor");
        if (firstFloorObj != NULL && json_object_is_type(firstFloorObj, json_type_int))
            firstFloor = json_object_get_int(firstFloorObj);
        // 意面检测时间
        json_object *pastaTimeObj = json_object_object_get(aiControlObj, "pastaTime");
        if (pastaTimeObj != NULL && json_object_is_type(pastaTimeObj, json_type_int))
            pastaTime = json_object_get_int(pastaTimeObj);
        // 意面可信度
        json_object *pastaTruthObj = json_object_object_get(aiControlObj, "pastaTruth");
        if (pastaTruthObj != NULL && json_object_is_type(pastaTruthObj, json_type_double))
            pastaTruth = json_object_get_double(pastaTruthObj);
        // AI数据采集开关
        json_object *dataCollectObj = json_object_object_get(aiControlObj, "dataCollect");
        if (dataCollectObj != NULL && json_object_is_type(dataCollectObj, json_type_int))
            dataCollect = json_object_get_int(dataCollectObj);
        // 异物可信度
        json_object *sundriesTruthObj = json_object_object_get(aiControlObj, "sundriesTruth");
        if (sundriesTruthObj != NULL && json_object_is_type(sundriesTruthObj, json_type_double))
            sundriesTruth = json_object_get_double(sundriesTruthObj);
        // 流量检测
        json_object *flowDetectObj = json_object_object_get(aiControlObj, "flowDetect");
        if (flowDetectObj != NULL && json_object_is_type(flowDetectObj, json_type_int))
            flowDetect = json_object_get_int(flowDetectObj);
        // 摄像头最佳高度
        json_object *optimalHeightObj = json_object_object_get(aiControlObj, "optimalHeight");
        if (optimalHeightObj != NULL && json_object_is_type(optimalHeightObj, json_type_int))
            optimalHeight = json_object_get_int(optimalHeightObj);
        // AI模式
        json_object *aiModeObj = json_object_object_get(aiControlObj, "aiMode");
        if (aiModeObj != NULL && json_object_is_type(aiModeObj, json_type_int))
            aiMode = json_object_get_int(aiModeObj);

        CrLogI("ai control; sw = %d, detection = %d, pausePrint = %d, firstFloor = %d, pastaTime = %d, pastaTruth = %f, dataCollect = %d, sundriesTruth = %f, flowDetect = %d",
                sw, detection, pausePrint, firstFloor, pastaTime, pastaTruth, dataCollect, sundriesTruth, flowDetect);
        CrLogI("ai control; optimalHeight = %d, aiMode = %d",
                optimalHeight, aiMode);
    }

    int res = json_object_to_file_ext(GetUserPrintReferFilePath(), saveUserRrefer, JSON_C_TO_STRING_PRETTY);
    //成功返回1，失败返回0
    return res + 1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int ReadPrintRrefer(void)
{
    // 读取文件，获取json数据
    saveUserRrefer = json_object_from_file(GetUserPrintReferFilePath());
    if (!saveUserRrefer) saveUserRrefer = json_object_new_object();

    // 打印材料偏好信息
    json_object *Material = json_object_object_get(saveUserRrefer, "material");
    if (!Material) {
        json_object *plaPre = json_object_new_object();
        json_object_object_add(plaPre, "id", json_object_new_int(1));
        json_object_object_add(plaPre, "name", json_object_new_string("PLA"));
        json_object_object_add(plaPre, "hotend", json_object_new_int(200));
        json_object_object_add(plaPre, "bed", json_object_new_int(60));

        json_object *absPre = json_object_new_object();
        json_object_object_add(absPre, "id", json_object_new_int(2));
        json_object_object_add(absPre, "name", json_object_new_string("ABS"));
        json_object_object_add(absPre, "hotend", json_object_new_int(180));
        json_object_object_add(absPre, "bed", json_object_new_int(50));

        Material = json_object_new_array();
        json_object_array_add(Material, plaPre);
        json_object_array_add(Material, absPre);
        json_object_object_add(saveUserRrefer, "material", Material);
    }

    // 自动PID信息
    json_object *autoPid = json_object_object_get(saveUserRrefer, "auto_pid");
    if (!autoPid) {
        json_object *endPid = json_object_new_object();
        json_object_object_add(endPid, "id", json_object_new_int(1));
        json_object_object_add(endPid, "name", json_object_new_string("hotend"));
        json_object_object_add(endPid, "temp", json_object_new_int(200));
        json_object_object_add(endPid, "time", json_object_new_int(4));

        json_object *bedPid = json_object_new_object();
        json_object_object_add(bedPid, "id", json_object_new_int(2));
        json_object_object_add(bedPid, "name", json_object_new_string("bed"));
        json_object_object_add(bedPid, "temp", json_object_new_int(60));
        json_object_object_add(bedPid, "time", json_object_new_int(5));

        autoPid = json_object_new_array();
        json_object_array_add(autoPid, endPid);
        json_object_array_add(autoPid, bedPid);
        json_object_object_add(saveUserRrefer, "auto_pid", autoPid);
    }

    // 延时摄影信息
    json_object *delayImageObj = json_object_object_get(saveUserRrefer, "delay_image");
    if (!delayImageObj) {
        delayImageObj = json_object_new_object();
        json_object_object_add(saveUserRrefer, "delay_image", delayImageObj);
    }
    // 获取延时摄影开关
    json_object *tempObj = json_object_object_get(delayImageObj, "switch");
    if (!tempObj) {
        int sw = GetdelayImageSwitchById(systemComfig.model);
        json_object_object_add(delayImageObj, "switch", json_object_new_int(sw));
    }
    // 获取延时摄影拍摄位置
    tempObj = json_object_object_get(delayImageObj, "location");
    if (!tempObj) {
        int location = GetdelayImageLocationById(systemComfig.model);
        json_object_object_add(delayImageObj, "location", json_object_new_int(location));
    }
    // 获取延时摄影渲染帧数
    tempObj = json_object_object_get(delayImageObj, "frame");
    if (!tempObj) {
        int frame = GetdelayImageFrameById(systemComfig.model);
        json_object_object_add(delayImageObj, "frame", json_object_new_int(frame));
    }
    // 获取延时摄影拍摄间隔
    tempObj = json_object_object_get(delayImageObj, "interval");
    if (!tempObj) {
        int interval = GetdelayImageIntervalById(systemComfig.model);
        json_object_object_add(delayImageObj, "interval", json_object_new_int(interval));
    }
    // 获取延时摄影最短时长
    tempObj = json_object_object_get(delayImageObj, "minTime");
    if (!tempObj) {
        int minTime = GetdelayImageMinTimeById(systemComfig.model);
        json_object_object_add(delayImageObj, "minTime", json_object_new_int(minTime));
    }

    // 断电续打信息
    json_object *powerLossObj = json_object_object_get(saveUserRrefer, "power_loss");
    if (!powerLossObj) {
        powerLossObj = json_object_new_object();
        json_object_object_add(saveUserRrefer, "power_loss", powerLossObj);
    }
    // 获取延时摄影开关
    tempObj = json_object_object_get(powerLossObj, "switch");
    if (!tempObj) {
        bool sw = GetPowerLossSwitchById(systemComfig.model);
        json_object_object_add(powerLossObj, "switch", json_object_new_boolean(sw));
    }

    // AI控制信息
    json_object *aiControlObj = json_object_object_get(saveUserRrefer, "ai_control");
    if (!aiControlObj) {
        aiControlObj = json_object_new_object();
        json_object_object_add(saveUserRrefer, "ai_control", aiControlObj);
    }
    // AI模式
    int aiMode = AI_MODE_TYPE_ROUTINE;
    tempObj = json_object_object_get(aiControlObj, "aiMode");
    if (!tempObj) {
        aiMode = GetAiControlAiModeById(systemComfig.model);
        json_object_object_add(aiControlObj, "aiMode", json_object_new_int(aiMode));
    }
    // 开关
    tempObj = json_object_object_get(aiControlObj, "switch");
    if (!tempObj) {
        int sw = GetAiControlSwitchById(systemComfig.model);
        json_object_object_add(aiControlObj, "switch", json_object_new_int(sw));
    }
    // 故障检测
    tempObj = json_object_object_get(aiControlObj, "detection");
    if (!tempObj) {
        int detection = GetAiControlDetectionById(systemComfig.model);
        json_object_object_add(aiControlObj, "detection", json_object_new_int(detection));
    }
    // 故障暂停打印
    tempObj = json_object_object_get(aiControlObj, "pausePrint");
    if (!tempObj) {
        int pausePrint = GetAiControlPausePrintById(systemComfig.model);
        json_object_object_add(aiControlObj, "pausePrint", json_object_new_int(pausePrint));
    }
    // 首层检测
    tempObj = json_object_object_get(aiControlObj, "firstFloor");
    if (!tempObj) {
        int firstFloor = GetAiControlFirstFloorById(systemComfig.model);
        json_object_object_add(aiControlObj, "firstFloor", json_object_new_int(firstFloor));
    }
    // 意面检测时间
    tempObj = json_object_object_get(aiControlObj, "pastaTime");
    if (!tempObj) {
        int pastaTime = GetAiControlPastaTimeById(systemComfig.model, aiMode);
        json_object_object_add(aiControlObj, "pastaTime", json_object_new_int(pastaTime));
    }
    // 意面可信度
    tempObj = json_object_object_get(aiControlObj, "pastaTruth");
    if (!tempObj) {
        double pastaTruth = GetAiControlPastaTruthById(systemComfig.model, aiMode);
        json_object_object_add(aiControlObj, "pastaTruth", json_object_new_double(pastaTruth));
    }
    // AI数据采集开关
    tempObj = json_object_object_get(aiControlObj, "dataCollect");
    if (!tempObj) {
        int dataCollect = GetAiControlDataCollectById(systemComfig.model);
        json_object_object_add(aiControlObj, "dataCollect", json_object_new_int(dataCollect));
    }
    // 异物可信度
    tempObj = json_object_object_get(aiControlObj, "sundriesTruth");
    if (!tempObj) {
        double sundriesTruth = GetAiControlSundriesTruthById(systemComfig.model);
        json_object_object_add(aiControlObj, "sundriesTruth", json_object_new_double(sundriesTruth));
    }
    // 流量检测
    tempObj = json_object_object_get(aiControlObj, "flowDetect");
    if (!tempObj) {
        int flowDetect = GetAiControlFlowDetectById(systemComfig.model);
        json_object_object_add(aiControlObj, "flowDetect", json_object_new_int(flowDetect));
    }
    // 摄像头最佳高度
    tempObj = json_object_object_get(aiControlObj, "optimalHeight");
    if (!tempObj) {
        int optimalHeight = GetAiControlOptimalHeightById(systemComfig.model);
        json_object_object_add(aiControlObj, "optimalHeight", json_object_new_int(optimalHeight));
    }

    SavePrintRrefer();
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int UpdataMaterialPrefer(void)
{
    MaterialPreferList list = MATERIAL_PREFER_LIST__INIT;
    GET_MESSAGE_BUFF(buff);
    size_t len = material_prefer_list__pack(&list, buff);
    
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_CMD_SYNC_MATERIAL_WARMUP_CONFIG, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int SetMaterialPrefer(MaterialPrefer *material)
{
    bool change = false;
    json_object *Material = json_object_object_get(saveUserRrefer, "material");
    if (Material) {
        CrLogI("set material prefer, material id = %d\n", material->id);
        for (int i = 0; i < json_object_array_length(Material); i++)
        {
            json_object *tempObj = NULL;
            json_object *arrayObj = json_object_array_get_idx(Material, i);

            json_object_object_get_ex(arrayObj, "id", &tempObj);
            if (json_object_get_int(tempObj) == material->id)
            {
                if (material->has_hotendtemp) {
                    json_object_object_get_ex(arrayObj, "hotend", &tempObj);
                    json_object_set_int(tempObj, material->hotendtemp);
                }
                if (material->has_bedtemp) {
                    json_object_object_get_ex(arrayObj, "bed", &tempObj);
                    json_object_set_int(tempObj, material->bedtemp);
                }
                change = true;
                break;
            }
        }

        // 新增加材料偏好
        if (!change) {
            json_object *newArray = json_object_new_object();
            json_object_object_add(newArray, "id", json_object_new_int(material->id));
            json_object_object_add(newArray, "name", json_object_new_string_len("other", strlen("other")));
            // 喷嘴温度
            if (material->has_hotendtemp)
                json_object_object_add(newArray, "hotend", json_object_new_int(material->hotendtemp));
            else json_object_object_add(newArray, "hotend", json_object_new_int(0));
            // 热床温度
            if (material->has_bedtemp)
                json_object_object_add(newArray, "bed", json_object_new_int(material->bedtemp));
            else json_object_object_add(newArray, "bed", json_object_new_int(0));

            json_object_array_add(Material, newArray);
        }
        UpdataMaterialPrefer();
    }

    return SavePrintRrefer();
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *arrayObj
 * @param {MaterialPrefer} *info
 */
int GetMaterialPreferFromJson(json_object *arrayObj, MaterialPrefer *info)
{
    // 获取ID
    json_object *tempObj = json_object_object_get(arrayObj, "id");
    info->id = json_object_get_int(tempObj);
    // 获取名称
    tempObj = json_object_object_get(arrayObj, "name");
    info->has_name = 1;
    info->name.data = (uint8_t*)json_object_get_string(tempObj);
    info->name.len = json_object_get_string_len(tempObj);
    // 获取喷嘴温度
    tempObj = json_object_object_get(arrayObj, "hotend");
    info->has_hotendtemp = 1;
    info->hotendtemp = json_object_get_int(tempObj);
    // 获取热床温度
    tempObj = json_object_object_get(arrayObj, "bed");
    info->has_bedtemp = 1;
    info->bedtemp = json_object_get_int(tempObj);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int GetMaterialPrefer(MaterialPreferList *list, MaterialPreferList *getList)
{
    json_object *Material = json_object_object_get(saveUserRrefer, "material");
    if (Material) {
        int jsonArraySize = json_object_array_length(Material);
        // 没有指定获取哪一个，获取全部
        if (list->n_list == 0)
        {
            getList->n_list = jsonArraySize;
            getList->list = (MaterialPrefer **)malloc(sizeof(MaterialPrefer *) * jsonArraySize);
            CrLogI("Material size = %d", jsonArraySize);
            
            // 循环获取
            for (int i = 0; i < jsonArraySize; i++)
            {
                getList->list[i] = (MaterialPrefer*)malloc(sizeof(MaterialPrefer));
                if (getList->list[i] == NULL) {
                    CrLogE("no memory to allocate\n");
                    return -1;
                }
                material_prefer__init(getList->list[i]);

                // 提取数据
                json_object *arrayObj = json_object_array_get_idx(Material, i);
                GetMaterialPreferFromJson(arrayObj, getList->list[i]);
            }
        }
        else
        {
            CrLogI("get material size = %d", list->n_list);
            getList->n_list = list->n_list;
            getList->list = (MaterialPrefer **)malloc(sizeof(MaterialPrefer *) * list->n_list);

            // 循环获取
            for (int i = 0; i < list->n_list; i++)
            {
                // 循环比较
                CrLogI("get material prefer, material id = %d\n", list->list[i]->id);
                for (int j = 0; j < jsonArraySize; j++)
                {
                    getList->list[i] = (MaterialPrefer*)malloc(sizeof(MaterialPrefer));
                    if (getList->list[i] == NULL) {
                        CrLogE("no memory to allocate\n");
                        return -1;
                    }
                    material_prefer__init(getList->list[i]);

                    // 提取数据
                    json_object *arrayObj = json_object_array_get_idx(Material, j);
                    json_object *tempObj = json_object_object_get(arrayObj, "id");
                    // 比较ID
                    if (json_object_get_int(tempObj) == list->list[i]->id) {
                        // 提取数据
                        GetMaterialPreferFromJson(arrayObj, getList->list[i]);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {MaterialPreferList} *getList
 */
int GetMaterialPreferFree(MaterialPreferList *getList)
{
    if (getList->list)
    {
        for (int i = 0; i < getList->n_list; i++)
        {
            if (getList->list[i])
            {
                free(getList->list[i]);
                getList->list[i] = NULL;
            }
        }
        free(getList->list);
        getList->list = NULL;
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int UpdataTempAutoPidPrefer(void)
{
    TempAutoPidPreferList list = TEMP_AUTO_PID_PREFER_LIST__INIT;
    GET_MESSAGE_BUFF(buff);
    size_t len = temp_auto_pid_prefer_list__pack(&list, buff);
    
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_CMD_SYNC_TEMP_AUTO_CONFIG, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int SetTempAutoPidPrefer(TempAutoPidPrefer *pidRefer)
{
    json_object *autoPid = json_object_object_get(saveUserRrefer, "auto_pid");
    if (autoPid) {
        for (int i = 0; i < json_object_array_length(autoPid); i++)
        {
            json_object *tempObj = NULL;
            json_object *arrayObj = json_object_array_get_idx(autoPid, i);

            json_object_object_get_ex(arrayObj, "id", &tempObj);
            if (json_object_get_int(tempObj) == pidRefer->id)
            {
                if (pidRefer->has_temp) {
                    json_object_object_get_ex(arrayObj, "temp", &tempObj);
                    json_object_set_int(tempObj, pidRefer->temp);
                }
                if (pidRefer->has_time) {
                    json_object_object_get_ex(arrayObj, "time", &tempObj);
                    json_object_set_int(tempObj, pidRefer->time);
                }
                break;
            }
        }
        UpdataTempAutoPidPrefer();
    }

    return SavePrintRrefer();
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *arrayObj
 * @param {TempAutoPidPrefer} *info
 */
int GetAutoPidPreferFromJson(json_object *arrayObj, TempAutoPidPrefer *info)
{
    // 获取ID
    json_object *tempObj = json_object_object_get(arrayObj, "id");
    info->id = json_object_get_int(tempObj);
    // 获取名称
    tempObj = json_object_object_get(arrayObj, "name");
    info->has_name = 1;
    info->name.data = (uint8_t*)json_object_get_string(tempObj);
    info->name.len = json_object_get_string_len(tempObj);
    // 获取目标温度
    tempObj = json_object_object_get(arrayObj, "temp");
    info->has_temp = 1;
    info->temp = json_object_get_int(tempObj);
    // 获取调整次数
    tempObj = json_object_object_get(arrayObj, "time");
    info->has_time = 1;
    info->time = json_object_get_int(tempObj);

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int GetTempAutoPidPrefer(TempAutoPidPreferList *list, TempAutoPidPreferList *getList)
{
    json_object *autoPid = json_object_object_get(saveUserRrefer, "auto_pid");
    if (autoPid) {
        int jsonArraySize = json_object_array_length(autoPid);
        // 没有指定获取哪一个，获取全部
        if (list->n_list == 0)
        {
            getList->n_list = jsonArraySize;
            getList->list = (TempAutoPidPrefer **)malloc(sizeof(TempAutoPidPrefer *) * jsonArraySize);
            CrLogI("Auto Pid size = %d", jsonArraySize);

            // 循环获取
            for (int i = 0; i < jsonArraySize; i++)
            {
                getList->list[i] = (TempAutoPidPrefer*)malloc(sizeof(TempAutoPidPrefer));
                if (getList->list[i] == NULL) {
                    CrLogE("no memory to allocate\n");
                    return -1;
                }
                temp_auto_pid_prefer__init(getList->list[i]);

                // 提取数据
                json_object *arrayObj = json_object_array_get_idx(autoPid, i);
                GetAutoPidPreferFromJson(arrayObj, getList->list[i]);
            }
        }
        else
        {
            CrLogI("get auto pid size = %d", list->n_list);
            getList->n_list = list->n_list;
            getList->list = (TempAutoPidPrefer **)malloc(sizeof(TempAutoPidPrefer *) * list->n_list);

            // 循环获取
            for (int i = 0; i < list->n_list; i++)
            {
                // 循环比较
                CrLogI("get auto pid prefer, pid id = %d\n", list->list[i]->id);
                for (int j = 0; j < jsonArraySize; j++)
                {
                    getList->list[i] = (TempAutoPidPrefer*)malloc(sizeof(TempAutoPidPrefer));
                    if (getList->list[i] == NULL) {
                        CrLogE("no memory to allocate\n");
                        return -1;
                    }
                    temp_auto_pid_prefer__init(getList->list[i]);

                    // 提取数据
                    json_object *arrayObj = json_object_array_get_idx(autoPid, j);
                    json_object *tempObj = json_object_object_get(arrayObj, "id");
                    // 比较ID
                    if (json_object_get_int(tempObj) == list->list[i]->id) {
                        // 提取数据
                        GetAutoPidPreferFromJson(arrayObj, getList->list[i]);
                        break;
                    }
                }
            }
        }
    }

    return 1;
}

/**
 * @description: 
 * @return {*}
 * @param {TempAutoPidPreferList} *getList
 */
int GetTempAutoPidPreferFree(TempAutoPidPreferList *getList)
{
    if (getList->list)
    {
        for (int i = 0; i < getList->n_list; i++)
        {
            if (getList->list[i])
            {
                free(getList->list[i]);
                getList->list[i] = NULL;
            }
        }
        free(getList->list);
        getList->list = NULL;
    }

    return 1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int UpdataDelayImagePrefer(void)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_CMD_SYNC_DELAY_IMAGE_CONFIG, "", 0);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {DelayImagePrefer} *imageRefer
 */
int SetDelayImagePrefer(DelayImagePrefer *imageRefer)
{
    json_object *delayImageObj = json_object_object_get(saveUserRrefer, "delay_image");
    if (delayImageObj) {
        // 开关
        if (imageRefer->has_sw) {
            json_object *switchObj = json_object_object_get(delayImageObj, "switch");
            if (switchObj != NULL && json_object_is_type(switchObj, json_type_int))
                json_object_set_int(switchObj, imageRefer->sw);
        }
        // 位置
        if (imageRefer->has_location) {
            json_object *locationObj = json_object_object_get(delayImageObj, "location");
            if (locationObj != NULL && json_object_is_type(locationObj, json_type_int))
                json_object_set_int(locationObj, imageRefer->location);
        }
        // 帧数
        if (imageRefer->has_frame) {
            json_object *frameObj = json_object_object_get(delayImageObj, "frame");
            if (frameObj != NULL && json_object_is_type(frameObj, json_type_int))
                json_object_set_int(frameObj, imageRefer->frame);
        }
        // 间隔层数
        if (imageRefer->has_interval) {
            json_object *intervalObj = json_object_object_get(delayImageObj, "interval");
            if (intervalObj != NULL && json_object_is_type(intervalObj, json_type_int))
                json_object_set_int(intervalObj, imageRefer->interval);
        }
        // 时长
        if (imageRefer->has_mintime) {
            json_object *minTimeObj = json_object_object_get(delayImageObj, "minTime");
            if (minTimeObj != NULL && json_object_is_type(minTimeObj, json_type_int))
                json_object_set_int(minTimeObj, imageRefer->mintime);
        }
        UpdataDelayImagePrefer();
    }

    return SavePrintRrefer();
}

/**
 * @description: 
 * @return {*}
 * @param {DelayImagePrefer} *imageRefer
 */
int GetDelayImagePrefer(DelayImagePrefer *imageRefer)
{
    json_object *delayImageObj = json_object_object_get(saveUserRrefer, "delay_image");
    if (delayImageObj) {
        // 开关
        json_object *switchObj = json_object_object_get(delayImageObj, "switch");
        if (switchObj != NULL && json_object_is_type(switchObj, json_type_int))
        {
            imageRefer->has_sw = 1;
            imageRefer->sw = json_object_get_int(switchObj);
        }
        // 位置
        json_object *locationObj = json_object_object_get(delayImageObj, "location");
        if (locationObj != NULL && json_object_is_type(locationObj, json_type_int))
        {
            imageRefer->has_location = 1;
            imageRefer->location = json_object_get_int(locationObj);
        }
        // 帧数
        json_object *frameObj = json_object_object_get(delayImageObj, "frame");
        if (frameObj != NULL && json_object_is_type(frameObj, json_type_int))
        {
            imageRefer->has_frame = 1;
            imageRefer->frame = json_object_get_int(frameObj);
        }
        // 间隔层数
        json_object *intervalObj = json_object_object_get(delayImageObj, "interval");
        if (intervalObj != NULL && json_object_is_type(intervalObj, json_type_int))
        {
            imageRefer->has_interval = 1;
            imageRefer->interval = json_object_get_int(intervalObj);
        }
        // 时长
        json_object *minTimeObj = json_object_object_get(delayImageObj, "minTime");
        if (minTimeObj != NULL && json_object_is_type(minTimeObj, json_type_int))
        {
            imageRefer->has_mintime = 1;
            imageRefer->mintime = json_object_get_int(minTimeObj);
        }
    }

    return 1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int UpdataPowerLossPrefer(void)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_CMD_SYNC_POWER_LOSS_CONFIG, "", 0);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {PowerLossPrefer} *lossRefer
 */
int SetPowerLossPrefer(PowerLossPrefer *lossRefer)
{
    json_object *powerLossObj = json_object_object_get(saveUserRrefer, "power_loss");
    if (powerLossObj) {
        // 开关
        if (lossRefer->has_sw) {
            json_object *switchObj = json_object_object_get(powerLossObj, "switch");
            if (switchObj != NULL && json_object_is_type(switchObj, json_type_boolean))
                json_object_set_boolean(switchObj, lossRefer->sw);
        }
        UpdataPowerLossPrefer();
    }

    return SavePrintRrefer();
}

/**
 * @description: 
 * @return {*}
 * @param {PowerLossPrefer} *lossRefer
 */
int GetPowerLossPrefer(PowerLossPrefer *lossRefer)
{
    json_object *powerLossObj = json_object_object_get(saveUserRrefer, "power_loss");
    if (powerLossObj) {
        // 开关
        json_object *switchObj = json_object_object_get(powerLossObj, "switch");
        if (switchObj != NULL && json_object_is_type(switchObj, json_type_boolean))
        {
            lossRefer->has_sw = 1;
            lossRefer->sw = json_object_get_boolean(switchObj);
        }
    }

    return 1;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int UpdataAIControlPrefer(void)
{
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_MASTER_BASE, MANAGER_CMD_SYNC_AI_CONTROL_CONFIG, "", 0);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {AiControlPrefer} *aiRefer
 */
int SetAiControlPrefer(AiControlPrefer *aiRefer)
{
    json_object *aiControlObj = json_object_object_get(saveUserRrefer, "ai_control");
    if (aiControlObj) {
        // 开关
        if (aiRefer->has_sw) {
            json_object *switchObj = json_object_object_get(aiControlObj, "switch");
            if (switchObj != NULL && json_object_is_type(switchObj, json_type_int))
                json_object_set_int(switchObj, aiRefer->sw);
        }
        // 故障检测
        if (aiRefer->has_detection) {
            json_object *detectionObj = json_object_object_get(aiControlObj, "detection");
            if (detectionObj != NULL && json_object_is_type(detectionObj, json_type_int))
                json_object_set_int(detectionObj, aiRefer->detection);
        }
        // 故障暂停打印
        if (aiRefer->has_pauseprint) {
            json_object *pausePrintObj = json_object_object_get(aiControlObj, "pausePrint");
            if (pausePrintObj != NULL && json_object_is_type(pausePrintObj, json_type_int))
                json_object_set_int(pausePrintObj, aiRefer->pauseprint);
        }
        // 首层检测
        if (aiRefer->has_firstfloor) {
            json_object *firstFloorObj = json_object_object_get(aiControlObj, "firstFloor");
            if (firstFloorObj != NULL && json_object_is_type(firstFloorObj, json_type_int))
                json_object_set_int(firstFloorObj, aiRefer->firstfloor);
        }
        // 意面检测时间
        if (aiRefer->has_pastatime) {
            json_object *pastaTimeObj = json_object_object_get(aiControlObj, "pastaTime");
            if (pastaTimeObj != NULL && json_object_is_type(pastaTimeObj, json_type_int))
                json_object_set_int(pastaTimeObj, aiRefer->pastatime);
        }
        // 意面可信度
        if (aiRefer->has_pastatruth) {
            json_object *pastaTruthObj = json_object_object_get(aiControlObj, "pastaTruth");
            if (pastaTruthObj != NULL && json_object_is_type(pastaTruthObj, json_type_double))
                json_object_set_double(pastaTruthObj, aiRefer->pastatruth);
        }
        // AI数据采集开关
        if (aiRefer->has_datacollect) {
            json_object *dataCollectObj = json_object_object_get(aiControlObj, "dataCollect");
            if (dataCollectObj != NULL && json_object_is_type(dataCollectObj, json_type_int))
                json_object_set_int(dataCollectObj, aiRefer->datacollect);
        }
        // 异物可信度
        if (aiRefer->has_sundriestruth) {
            json_object *sundriesTruthObj = json_object_object_get(aiControlObj, "sundriesTruth");
            if (sundriesTruthObj != NULL && json_object_is_type(sundriesTruthObj, json_type_double))
                json_object_set_double(sundriesTruthObj, aiRefer->sundriestruth);
        }
        // 流量检测
        if (aiRefer->has_flowdetect) {
            json_object *flowDetectObj = json_object_object_get(aiControlObj, "flowDetect");
            if (flowDetectObj != NULL && json_object_is_type(flowDetectObj, json_type_int))
                json_object_set_int(flowDetectObj, aiRefer->flowdetect);
        }
        // 摄像头最佳高度
        if (aiRefer->has_optimalheight) {
            json_object *optimalHeightObj = json_object_object_get(aiControlObj, "optimalHeight");
            if (optimalHeightObj != NULL && json_object_is_type(optimalHeightObj, json_type_int))
                json_object_set_int(optimalHeightObj, aiRefer->optimalheight);
        }
        // AI模式
        if (aiRefer->has_aimode) {
            json_object *aiModeObj = json_object_object_get(aiControlObj, "aiMode");
            if (aiModeObj != NULL && json_object_is_type(aiModeObj, json_type_int))
            {
                json_object_set_int(aiModeObj, aiRefer->aimode);

                // 切换AI模式，修改检测时间、检测置信度
                json_object *pastaTimeObj = json_object_object_get(aiControlObj, "pastaTime");
                if (pastaTimeObj != NULL && json_object_is_type(pastaTimeObj, json_type_int)) {
                    json_object_set_int(pastaTimeObj, GetAiControlPastaTimeById(systemComfig.model, aiRefer->aimode));
                }
                json_object *pastaTruthObj = json_object_object_get(aiControlObj, "pastaTruth");
                if (pastaTruthObj != NULL && json_object_is_type(pastaTruthObj, json_type_double)) {
                    json_object_set_double(pastaTruthObj, GetAiControlPastaTruthById(systemComfig.model, aiRefer->aimode));
                }
            }  
        }
        UpdataAIControlPrefer();
    }

    return SavePrintRrefer();
}

/**
 * @description: 
 * @return {*}
 * @param {AiControlPrefer} *aiRefer
 */
int GetAiControlPrefer(AiControlPrefer *aiRefer)
{
    json_object *aiControlObj = json_object_object_get(saveUserRrefer, "ai_control");
    if (aiControlObj) {
        // 开关
        json_object *switchObj = json_object_object_get(aiControlObj, "switch");
        if (switchObj != NULL && json_object_is_type(switchObj, json_type_int))
        {
            aiRefer->has_sw = 1;
            aiRefer->sw = json_object_get_int(switchObj);
        }
        // 故障检测
        json_object *detectionObj = json_object_object_get(aiControlObj, "detection");
        if (detectionObj != NULL && json_object_is_type(detectionObj, json_type_int))
        {
            aiRefer->has_detection = 1;
            aiRefer->detection = json_object_get_int(detectionObj);
        }
        // 故障暂停打印
        json_object *pausePrintObj = json_object_object_get(aiControlObj, "pausePrint");
        if (pausePrintObj != NULL && json_object_is_type(pausePrintObj, json_type_int))
        {
            aiRefer->has_pauseprint = 1;
            aiRefer->pauseprint = json_object_get_int(pausePrintObj);
        }
        // 首层检测
        json_object *firstFloorObj = json_object_object_get(aiControlObj, "firstFloor");
        if (firstFloorObj != NULL && json_object_is_type(firstFloorObj, json_type_int))
        {
            aiRefer->has_firstfloor = 1;
            aiRefer->firstfloor = json_object_get_int(firstFloorObj);
        }
        // 意面检测时间
        json_object *pastaTimeObj = json_object_object_get(aiControlObj, "pastaTime");
        if (pastaTimeObj != NULL && json_object_is_type(pastaTimeObj, json_type_int))
        {
            aiRefer->has_pastatime = 1;
            aiRefer->pastatime = json_object_get_int(pastaTimeObj);
        }
        // 意面可信度
        json_object *pastaTruthObj = json_object_object_get(aiControlObj, "pastaTruth");
        if (pastaTruthObj != NULL && json_object_is_type(pastaTruthObj, json_type_double))
        {
            aiRefer->has_pastatruth = 1;
            aiRefer->pastatruth = json_object_get_double(pastaTruthObj);
        }
        // AI数据采集开关
        json_object *dataCollectObj = json_object_object_get(aiControlObj, "dataCollect");
        if (dataCollectObj != NULL && json_object_is_type(dataCollectObj, json_type_int))
        {
            aiRefer->has_datacollect = 1;
            aiRefer->datacollect = json_object_get_int(dataCollectObj);
        }
        // 异物可信度
        json_object *sundriesTruthObj = json_object_object_get(aiControlObj, "sundriesTruth");
        if (sundriesTruthObj != NULL && json_object_is_type(sundriesTruthObj, json_type_double))
        {
            aiRefer->has_sundriestruth = 1;
            aiRefer->sundriestruth = json_object_get_double(sundriesTruthObj);
        }
        // 流量检测
        json_object *flowDetectObj = json_object_object_get(aiControlObj, "flowDetect");
        if (flowDetectObj != NULL && json_object_is_type(flowDetectObj, json_type_int))
        {
            aiRefer->has_flowdetect = 1;
            aiRefer->flowdetect = json_object_get_int(flowDetectObj);
        }
        // 摄像头最佳高度
        json_object *optimalHeightObj = json_object_object_get(aiControlObj, "optimalHeight");
        if (optimalHeightObj != NULL && json_object_is_type(optimalHeightObj, json_type_int))
        {
            aiRefer->has_optimalheight = 1;
            aiRefer->optimalheight = json_object_get_int(optimalHeightObj);
        }
        // AI模式
        json_object *aiModeObj = json_object_object_get(aiControlObj, "aiMode");
        if (aiModeObj != NULL && json_object_is_type(aiModeObj, json_type_int))
        {
            aiRefer->has_aimode = 1;
            aiRefer->aimode = json_object_get_int(aiModeObj);
        }
    }

    return 1;
}

/*********************************************************
 *********************************************************
 ******************** 保存历史记录 **********************
 *********************************************************
 *********************************************************/
/**
 * @description: 
 * @return {*}
 * @param {json_object} *Obj
 */
static int GetHistoryRecordOriginalData(json_object *Obj)
{
    json_object *lastRecordObj = json_object_from_file(GetuserPrintHistoryRecordPtah());
    if (lastRecordObj) {
        // 获取文件已保存历史记录列表
        json_object *lastListObj = json_object_object_get(lastRecordObj, "list");
        if (lastListObj)
        {
            // 判断历史数量
            size_t recordSize = json_object_array_length(lastListObj);
            CrLogI("last history records number = %d\n", recordSize);

            // 转移原有记录，删除超出限制的历史
            for (int i = 0; i < recordSize; i++)
            {
                json_object *historyObj = json_object_array_get_idx(lastListObj, i);
                if (i < (SAVE_HISTORY_RECORD_SIZE - 1))
                {
                    json_object_array_add(Obj, historyObj);
                    json_object_get(historyObj);
                }
                else
                {
                    CrLogI("History exceeded maximum");
                    // 删除缩略图
                    json_object *thumbnailObj = json_object_object_get(historyObj, "thumbnail");
                    if (thumbnailObj && json_object_is_type(thumbnailObj, json_type_string)) {
                        if (json_object_get_string_len(thumbnailObj) > 0)
                        {
                            if (remove(json_object_get_string(thumbnailObj)) != 0)
                                CrLogW("remove thumbnail fail\n");
                        }
                    }
                }
            }
        }
        else CrLogW("no find list obj\n");
        json_object_put(lastRecordObj);
    }
    else CrLogW("no get history record original data\n");

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {HistoryRecord} history
 */
static int UpdataHistoryRecord(HistoryRecord history)
{
    int res = -1;
    CrLogI("updata history record :");
    // 从文件获取json数据
    json_object *recordObj = json_object_from_file(GetuserPrintHistoryRecordPtah());
    if (!recordObj) goto ERROR;

    // 获取list列表
    json_object *listObj = GetJsonObject(recordObj, "list", json_type_array);
    if (!listObj) goto SET_END;

    // 获取第一个历史记录
    json_object *historyObj = json_object_array_get_idx(listObj, 0);
    if (!historyObj) goto SET_END;

    // 获取第一个历史记录id
    json_object *idObj = GetJsonObject(historyObj, "id", json_type_int);
    if (!idObj) goto SET_END;

    // 判断id是否相同
    CrLogI("id = %d, updata id = %d", history.id, json_object_get_int(idObj));
    if (history.id != json_object_get_int(idObj)) goto SET_END;

    // 实际时间
    CrLogI("usagetime = %d", history.usagetime);
    json_object *usagetimeObj = GetJsonObject(historyObj, "usagetime", json_type_int);
    if (usagetimeObj) json_object_set_int(usagetimeObj, history.usagetime);
    // 实际耗材
    CrLogI("usagematerial = %d", history.usagematerial);
    json_object *usagematerialObj = GetJsonObject(historyObj, "usagematerial", json_type_double);
    if (usagematerialObj) json_object_set_double(usagematerialObj, history.usagematerial);
    // 是否打印完成
    CrLogI("printfinish = %d", history.printfinish);
    json_object *printfinishObj = GetJsonObject(historyObj, "printfinish", json_type_int);
    if (printfinishObj) json_object_set_int(printfinishObj, history.printfinish);

SET_END:
    // 保存到文件
    CrLogI("updata print history to file");
    res = json_object_to_file_ext(GetuserPrintHistoryRecordPtah(), recordObj, JSON_C_TO_STRING_PRETTY|JSON_C_TO_STRING_NOSLASHESCAPE);
    json_object_put(recordObj);
    return res;

ERROR:
    CrLogW("get json fail from file\n");
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {int} id
 */
static bool IsHistoryRecordExists(int id)
{
    bool isExists = false;
    // 从文件获取json数据
    json_object *recordObj = json_object_from_file(GetuserPrintHistoryRecordPtah());
    if (!recordObj) goto SET_END;

    // 获取list列表
    json_object *listObj = GetJsonObject(recordObj, "list", json_type_array);
    if (!listObj) goto SET_END;

    // 获取第一个历史记录
    json_object *historyObj = json_object_array_get_idx(listObj, 0);
    if (!historyObj) goto SET_END;

    // 获取第一个历史记录id
    json_object *idObj = GetJsonObject(historyObj, "id", json_type_int);
    if (!idObj) goto SET_END;

    // 判断id是否存在
    CrLogI("old id = %d, new id = %d", json_object_get_int(idObj), id);
    if (json_object_get_int(idObj) == id) isExists = true;

SET_END:
    if(recordObj) json_object_put(recordObj);
    return isExists;
}

/**
 * @description: 
 * @return {*}
 * @param {HistoryRecord} history
 * @param {bool} isUpdata
 */
int SetHistoryRecord(HistoryRecord history, bool isUpdata)
{
    // 判断是否更新记录
    if (isUpdata) {
        return UpdataHistoryRecord(history);
    }

    // 判断记录是否存在，存在则不再新增记录
    if (IsHistoryRecordExists(history.id)) {
        CrLogW("history record exists\n");
        return 0;
    }

    CrLogI("save history record :");
    json_object *record = json_object_new_object();

    // id
    CrLogI("id = %d", history.id);
    json_object_object_add(record, "id", json_object_new_int(history.id));
    // 名称
    CrLogI("filename = %s", history.filename.data);
    json_object_object_add(record, "filename", json_object_new_string_len((char*)history.filename.data, history.filename.len));
    // 文件大小
    CrLogI("size = %d", history.size);
    json_object_object_add(record, "size", json_object_new_int(history.size));
    // 文件创建时间
    CrLogI("ctime = %d", history.ctime);
    json_object_object_add(record, "ctime", json_object_new_int(history.ctime));
    // 开始时间
    CrLogI("starttime = %d", history.starttime);
    json_object_object_add(record, "starttime", json_object_new_int(history.starttime));
    // 启动方式
    CrLogI("startway = %d", history.startway);
    json_object_object_add(record, "startway", json_object_new_int(history.startway));
    // 实际时间
    CrLogI("usagetime = %d", history.usagetime);
    json_object_object_add(record, "usagetime", json_object_new_int(history.usagetime));
    // 实际耗材
    CrLogI("usagematerial = %f", history.usagematerial);
    json_object_object_add(record, "usagematerial", json_object_new_double(history.usagematerial));
    // 是否打印完成
    CrLogI("printfinish = %d", history.printfinish);
    json_object_object_add(record, "printfinish", json_object_new_int(history.printfinish));
    // 缩略图路径
    CrLogI("thumbnail = %s", history.thumbnail.data);
    json_object_object_add(record, "thumbnail", json_object_new_string_len((char*)history.thumbnail.data, history.thumbnail.len));
    // 打印文件MD5码
    CrLogI("filemd5 = %s", history.filemd5.data);
    json_object_object_add(record, "filemd5", json_object_new_string_len((char*)history.filemd5.data, history.filemd5.len));

    // 创建保存历史记录列表json数组
    json_object *listObj = json_object_new_array();
    // 添加历史记录到历史列表
    json_object_array_add(listObj, record);

    // 读取历史记录文件，获取文件已保存json数据，转移到新的记录json中
    GetHistoryRecordOriginalData(listObj);

    // 判断历史数量
    CrLogI("history records number = %d\n", json_object_array_length(listObj));

    // 创建保存历史记录json
    json_object *recordObj = json_object_new_object();
    json_object_object_add(recordObj, "list", listObj);

    // 保存到文件
    CrLogI("save print history to file");
    int res = json_object_to_file_ext(GetuserPrintHistoryRecordPtah(), recordObj, JSON_C_TO_STRING_PRETTY|JSON_C_TO_STRING_NOSLASHESCAPE);
    json_object_put(recordObj);
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {HistoryRecordList} *recordList
 */
int GetHistoryRecord(HistoryRecordList *recordList)
{
    // 读取文件，获取json数据
    json_object *saveHistoryRecord = json_object_from_file(GetuserPrintHistoryRecordPtah());
    if (!saveHistoryRecord) {
        CrLogW("read json object fail, no history record\n");
        recordList->n_list = 0;
        return -1;
    }
    
    // 提取打印历史记录列表
    json_object *listObj = json_object_object_get(saveHistoryRecord, "list");
    int recordSize = json_object_array_length(listObj);

    recordList->list = (HistoryRecord**) malloc(sizeof(HistoryRecord*) * recordSize);
    if (recordList->list == NULL) {
        CrLogE("no memory to allocate\n");
        recordList->n_list = 0;
        return -1;
    }

    // 提取历史记录
    int i = 0;
    for (i = 0; i < recordSize; i++)
    {
        recordList->list[i] = (HistoryRecord*) malloc( sizeof(HistoryRecord) );
        if (recordList->list[i] == NULL) {
            CrLogE("no memory to allocate\n");
            recordList->n_list = i;
            return -1;
        }
        // 初始化历史记录
        history_record__init(recordList->list[i]);

        json_object *record = json_object_array_get_idx(listObj, i);
        recordList->list[i]->id = json_object_get_int(json_object_object_get(record, "id"));
        recordList->list[i]->filename.len = json_object_get_string_len(json_object_object_get(record, "filename"));
        recordList->list[i]->filename.data = (uint8_t*)malloc(recordList->list[i]->filename.len);
        memcpy(recordList->list[i]->filename.data, json_object_get_string(json_object_object_get(record, "filename")), recordList->list[i]->filename.len);
        recordList->list[i]->size = json_object_get_int(json_object_object_get(record, "size"));
        recordList->list[i]->ctime = json_object_get_int(json_object_object_get(record, "ctime"));
        recordList->list[i]->starttime = json_object_get_int(json_object_object_get(record, "starttime"));
        recordList->list[i]->startway = json_object_get_int(json_object_object_get(record, "startway"));
        recordList->list[i]->usagetime = json_object_get_int(json_object_object_get(record, "usagetime"));
        recordList->list[i]->usagematerial = json_object_get_double(json_object_object_get(record, "usagematerial"));
        recordList->list[i]->printfinish = json_object_get_int(json_object_object_get(record, "printfinish"));
        recordList->list[i]->thumbnail.len = json_object_get_string_len(json_object_object_get(record, "thumbnail"));
        recordList->list[i]->thumbnail.data = (uint8_t*)malloc(recordList->list[i]->thumbnail.len);
        memcpy(recordList->list[i]->thumbnail.data, json_object_get_string(json_object_object_get(record, "thumbnail")), recordList->list[i]->thumbnail.len);
        recordList->list[i]->filemd5.len = json_object_get_string_len(json_object_object_get(record, "filemd5"));
        recordList->list[i]->filemd5.data = (uint8_t*)malloc(recordList->list[i]->filemd5.len);
        memcpy(recordList->list[i]->filemd5.data, json_object_get_string(json_object_object_get(record, "filemd5")), recordList->list[i]->filemd5.len);
    }

    recordList->n_list = i;
    json_object_put(saveHistoryRecord);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {HistoryRecordList} *recordList
 */
int GetHistoryRecordFree(HistoryRecordList *recordList)
{
    if (recordList->list)
    {
        for (int i = 0; i < recordList->n_list; i++)
        {
            if (recordList->list[i])
            {
                if (recordList->list[i]->filename.data)
                {
                    free(recordList->list[i]->filename.data);
                    recordList->list[i]->filename.data = NULL;
                }
                if (recordList->list[i]->thumbnail.data)
                {
                    free(recordList->list[i]->thumbnail.data);
                    recordList->list[i]->thumbnail.data = NULL;
                }
                if (recordList->list[i]->filemd5.data)
                {
                    free(recordList->list[i]->filemd5.data);
                    recordList->list[i]->filemd5.data = NULL;
                }
                free(recordList->list[i]);
                recordList->list[i] = NULL;
            }
        }
        free(recordList->list);
        recordList->list = NULL;
    }
    return 0;
}

/*********************************************************
 *********************************************************
 ****************** 保存延时摄影视频信息 ********************
 *********************************************************
 *********************************************************/
/**
 * @description: 
 * @return {*}
 * @param {json_object} *Obj
 */
static int GetDelayImageOriginalData(json_object *Obj)
{
    json_object *lastImageObj = json_object_from_file(GetUserDelayImageInfoPtah());
    if (lastImageObj) {
        // 获取文件已保存视频记录列表
        json_object *lastListObj = json_object_object_get(lastImageObj, "list");
        if (lastListObj)
        {
            // 判断视频数量
            size_t imageSize = json_object_array_length(lastListObj);
            CrLogI("last delay image number = %d\n", imageSize);

            // 转移原有记录，删除超出限制的视频
            for (int i = 0; i < imageSize; i++)
            {
                json_object *imageObj = json_object_array_get_idx(lastListObj, i);
                if (i < (SAVE_DELAY_IMAGE_INFO_SIZE - 1))
                {
                    json_object_array_add(Obj, imageObj);
                    json_object_get(imageObj);
                }
                else
                {
                    CrLogI("Image exceeded maximum");
                    // 删除视频
                    json_object *pathObj = json_object_object_get(imageObj, "video");
                    if (pathObj && json_object_is_type(pathObj, json_type_string)) {
                        if (json_object_get_string_len(pathObj) > 0)
                        {
                            if (remove(json_object_get_string(pathObj)) != 0)
                                CrLogW("remove delay image fail\n");
                        }
                    }
                    // 删除封面
                    json_object *coverObj = json_object_object_get(imageObj, "cover");
                    if (coverObj && json_object_is_type(coverObj, json_type_string)) {
                        if (json_object_get_string_len(coverObj) > 0)
                        {
                            if (remove(json_object_get_string(coverObj)) != 0)
                                CrLogW("remove delay image cover fail\n");
                        }
                    }
                }
            }
        }
        else CrLogW("no find list obj\n");
        json_object_put(lastImageObj);
    }
    else CrLogW("no get delay image original data\n");

    return 0;
}

static char *getnameformpath(char *path){
    if(path != NULL)
    {
        char *name = strrchr(path, '/');
        if (name) 
            return name + 1;
    }
    return "";
}
/**
 * @description: 
 * @return {*}
 * @param {DelayImageInfo} setInfo
 */
int SetDelayImageInfo(DelayImageInfo setInfo)
{
    CrLogI("save delay image info :");
    pthread_rwlock_wrlock(&delayVideoLock);
    json_object *info = json_object_new_object();

    // gcode名称
    CrLogI("name = %s", setInfo.name.data);
    json_object_object_add(info, "name", json_object_new_string_len((char*)setInfo.name.data, setInfo.name.len));
    // id
    CrLogI("id = %d", setInfo.id);
    json_object_object_add(info, "id", json_object_new_int(setInfo.id));
    // 名称
    CrLogI("video = %s", setInfo.video.data);
    json_object_object_add(info, "video", json_object_new_string_len((char*)setInfo.video.data, setInfo.video.len));
    // 大小
    CrLogI("size = %d", setInfo.size);
    json_object_object_add(info, "size", json_object_new_int(setInfo.size));
    // 时长
    CrLogI("duration = %d", setInfo.duration);
    json_object_object_add(info, "duration", json_object_new_int(setInfo.duration));
    // 封面
    CrLogI("cover = %s", setInfo.cover.data);
    json_object_object_add(info, "cover", json_object_new_string_len((char*)setInfo.cover.data, setInfo.cover.len));
    // 开始时间
    CrLogI("starttime = %d", setInfo.starttime);
    json_object_object_add(info, "starttime", json_object_new_int(setInfo.starttime));
    // 打印时间
    CrLogI("printtime = %d", setInfo.printtime);
    json_object_object_add(info, "printtime", json_object_new_int(setInfo.printtime));
    // 喷嘴位置
    CrLogI("location = %d", setInfo.location);
    json_object_object_add(info, "location", json_object_new_int(setInfo.location));
    // 间隔层数
    CrLogI("interval = %d", setInfo.interval);
    json_object_object_add(info, "interval", json_object_new_int(setInfo.interval));
    // 渲染帧数
    CrLogI("render = %d", setInfo.render);
    json_object_object_add(info, "render", json_object_new_int(setInfo.render));

    char pid[32] = {0};
    sprintf(pid,"%d",setInfo.id);
    json_object_object_add(info, "printId", json_object_new_string(pid));
    json_object_object_add(info, "videoid", json_object_new_string(pid));
    json_object_object_add(info, "upload", json_object_new_int(0));
    char *gcodepath = json_object_get_string(json_object_object_get(info, "name"));
    json_object_object_add(info, "gcodename", json_object_new_string(getnameformpath(gcodepath)));
    char *videopath = json_object_get_string(json_object_object_get(info, "video"));
    json_object_object_add(info, "videoname", json_object_new_string(getnameformpath(videopath)));
    // 创建保存视频记录列表json数组
    json_object *listObj = json_object_new_array();
    // 添加视频信息到信息列表
    json_object_array_add(listObj, info);

    // 读取视频记录文件，获取文件已保存json数据，转移到新的记录json中
    GetDelayImageOriginalData(listObj);

    // 判断视频数量
    CrLogI("delay image number = %d\n", json_object_array_length(listObj));

    // 创建保存视频记录json
    json_object *imageObj = json_object_new_object();
    json_object_object_add(imageObj, "list", listObj);

    // 保存到文件
    int res = json_object_to_file_ext(GetUserDelayImageInfoPtah(), imageObj, JSON_C_TO_STRING_PRETTY|JSON_C_TO_STRING_NOSLASHESCAPE);
    json_object_put(imageObj);
    pthread_rwlock_unlock(&delayVideoLock);
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {DelayImageInfoList} *infoList
 */
int GetDelayImageInfo(DelayImageInfoList *infoList)
{
    // 读取文件，获取json数据
    json_object *saveDelayImageInfo = json_object_from_file(GetUserDelayImageInfoPtah());
    if (!saveDelayImageInfo) {
        CrLogW("read json object fail, no delay image\n");
        infoList->n_list = 0;
        return -1;
    }

    // 提取延时摄影信息列表
    json_object *listObj = json_object_object_get(saveDelayImageInfo, "list");
    int infoSize = json_object_array_length(listObj);

    infoList->list = (DelayImageInfo**) malloc(sizeof(DelayImageInfo*) * infoSize);
    if (infoList->list == NULL) {
        CrLogE("no memory to allocate\n");
        infoList->n_list = 0;
        return -1;
    }

    // 提取延时摄影信息
    int i = 0;
    for (i = 0; i < infoSize; i++)
    {
        infoList->list[i] = (DelayImageInfo*) malloc( sizeof(DelayImageInfo) );
        if (infoList->list[i] == NULL) {
            CrLogE("no memory to allocate\n");
            infoList->n_list = i;
            return -1;
        }
        // 初始化延时摄影信息
        delay_image_info__init(infoList->list[i]);

        json_object *info = json_object_array_get_idx(listObj, i);
        infoList->list[i]->name.len = json_object_get_string_len(json_object_object_get(info, "name"));
        infoList->list[i]->name.data = (uint8_t*)malloc(infoList->list[i]->name.len);
        memcpy(infoList->list[i]->name.data, json_object_get_string(json_object_object_get(info, "name")), infoList->list[i]->name.len);
        infoList->list[i]->id = json_object_get_int(json_object_object_get(info, "id"));
        infoList->list[i]->video.len = json_object_get_string_len(json_object_object_get(info, "video"));
        infoList->list[i]->video.data = (uint8_t*)malloc(infoList->list[i]->video.len);
        memcpy(infoList->list[i]->video.data, json_object_get_string(json_object_object_get(info, "video")), infoList->list[i]->video.len);
        infoList->list[i]->size = json_object_get_int(json_object_object_get(info, "size"));
        infoList->list[i]->duration = json_object_get_int(json_object_object_get(info, "duration"));
        infoList->list[i]->cover.len = json_object_get_string_len(json_object_object_get(info, "cover"));
        infoList->list[i]->cover.data = (uint8_t*)malloc(infoList->list[i]->cover.len);
        memcpy(infoList->list[i]->cover.data, json_object_get_string(json_object_object_get(info, "cover")), infoList->list[i]->cover.len);
        infoList->list[i]->starttime = json_object_get_int(json_object_object_get(info, "starttime"));
        infoList->list[i]->printtime = json_object_get_int(json_object_object_get(info, "printtime"));
        infoList->list[i]->location = json_object_get_int(json_object_object_get(info, "location"));
        infoList->list[i]->interval = json_object_get_int(json_object_object_get(info, "interval"));
        infoList->list[i]->render = json_object_get_int(json_object_object_get(info, "render"));
    }

    infoList->n_list = i;
    json_object_put(saveDelayImageInfo);
    return 0;
}

static int addprintid(json_object *image,char* file,char*printid)
{
    json_object *pathobj = json_object_object_get(image, "video");
    if(pathobj&&json_object_is_type(pathobj, json_type_string))
    {
        char* vpath = json_object_get_string(pathobj);
        if(!strcmp(file,vpath))
        {
            CrLogI("addprintid filename = %s", vpath);
            //json_object *printid = json_object_object_get(image, "printId");
            //if(printid)
            {
                json_object_object_del(image, "printId");
                json_object_object_add(image, "printId", json_object_new_string(printid));
                return 0;
            }
        }
    }
    return -1;
}

static int changename(json_object *image,char* file,char*printid,char* param)
{
    json_object * obj = json_object_object_get(image, "videoname");
    json_object *pathobj = json_object_object_get(image, "video");
    if(obj&&json_object_is_type(obj, json_type_string)
    &&pathobj&&json_object_is_type(pathobj, json_type_string))
    {
        char *vp = json_object_get_string(pathobj);
        CrLogI("changename vp = %s", vp);
        if(!strcmp(file,vp))
        {
            CrLogI("changename findfileinfo = %s", file);
            json_object_object_del(image, "videoname");
            json_object_object_add(image, "videoname", json_object_new_string(param));
            return 0;
        }
    }
    return -1;
}

static int uploadstatus(json_object *image,char* file,char*videoid)
{
    json_object * obj = json_object_object_get(image, "videoname");
    json_object *pathobj = json_object_object_get(image, "video");
    if(obj&&json_object_is_type(obj, json_type_string)
    &&pathobj&&json_object_is_type(pathobj, json_type_string))
    {
        char *vp = json_object_get_string(pathobj);
        if(!strcmp(file,vp))
        {
            CrLogI("uploadstatus findfileinfo = %s", file);
            json_object_object_del(image, "upload");
            json_object_object_add(image, "upload", json_object_new_int(1));
            if(json_object_object_get(image, "videoid"))
            {
                json_object_object_del(image, "videoid");
            }
            json_object_object_add(image, "videoid", json_object_new_string(videoid));
            return 0;
        }
    }
    return -1;
}

static int removefile(json_object *image,char* file,char*printid)
{
    json_object * obj = json_object_object_get(image, "videoname");
    json_object *pathobj = json_object_object_get(image, "video");
    if(obj&&json_object_is_type(obj, json_type_string)
    &&pathobj&&json_object_is_type(pathobj, json_type_string))
    {
        char *vp = json_object_get_string(pathobj);
        if(!strcmp(file,vp))
        {
            CrLogI("removefile findfileinfo = %s", file);
            remove(vp);
            obj = json_object_object_get(image, "cover");
            if(obj&&json_object_is_type(obj, json_type_string))
                remove(json_object_get_string(obj));
            return 0;
        }
    }
    return -1;
}

int ModifyDelayImageInfo(int cmd,char* file,char*printid,char* param)
{
    CrLogI("ModifyDelayImageInfo cmd = %d", cmd);
    if (access(GetUserDelayImageInfoPtah(), F_OK) != 0)
        return -1;
    pthread_rwlock_wrlock(&delayVideoLock);
    json_object *delayImage = json_object_from_file(GetUserDelayImageInfoPtah());
    if (!delayImage) 
    {
        pthread_rwlock_unlock(&delayVideoLock);
        return -2;
    }
        
    json_object *listObj = json_object_object_get(delayImage, "list");
    if(!listObj)
    {
        json_object_put(delayImage);
        pthread_rwlock_unlock(&delayVideoLock);
        return -3;
    }

    int imageSize = json_object_array_length(listObj);
    CrLogI("imageSize = %d", imageSize);
    CrLogI("file = %s", file);
    CrLogI("printid = %s", printid);
    CrLogI("param = %s", param);
    for (int i = 0; i < imageSize; i++)
    {
        json_object *image = json_object_array_get_idx(listObj, i);
        int ret = -1;
        switch(cmd)
        {
            case 1:
                ret = addprintid(image,file,printid);
            break;
            case 2:
                ret = changename(image,file,printid,param);
            break;
            case 3:
                ret = removefile(image,file,printid);
                if(ret == 0)
                {
                    json_object_array_del_idx(listObj,i,1);
                }
            break;
            case 4:
                ret = uploadstatus(image,file,param);
            break;
            default:
            break;                                    
        }

        if(ret == 0){
            int res = json_object_to_file_ext(GetUserDelayImageInfoPtah(), delayImage, JSON_C_TO_STRING_PRETTY|JSON_C_TO_STRING_NOSLASHESCAPE);
            json_object_put(delayImage);
            pthread_rwlock_unlock(&delayVideoLock);
            return 0;
        }
    }
    json_object_put(delayImage);
    pthread_rwlock_unlock(&delayVideoLock);
    return -4;
}

/*********************************************************
 *********************************************************
 ******************** 保存报错历史信息 **********************
 *********************************************************
 *********************************************************/
/**
 * @description: 
 * @return {*}
 * @param {json_object} *Obj
 */
static int GetFaultCodeOriginalData(json_object *Obj)
{
    json_object *lastCodeObj = json_object_from_file(GetUserFaultCodeInfoPtah());
    if (lastCodeObj) {
        // 获取文件已保存错误记录列表
        json_object *lastListObj = json_object_object_get(lastCodeObj, "list");
        if (lastListObj)
        {
            // 判断错误记录数量
            size_t codeSize = json_object_array_length(lastListObj);
            CrLogI("last fault code number = %d\n", codeSize);

            // 转移原有记录，删除超出限制的记录
            int num = codeSize <= (SAVE_FAULT_CODE_INFO_SIZE - 1) ? codeSize : (SAVE_FAULT_CODE_INFO_SIZE - 1);
            for (int i = 0; i < num; i++) {
                json_object *codeObj = json_object_array_get_idx(lastListObj, i);
                json_object_array_add(Obj, codeObj);
                json_object_get(codeObj);
            }
        }
        else CrLogW("no find list obj\n");
        json_object_put(lastCodeObj);
    }
    else CrLogW("no get fault code original data\n");

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {FaultCode_t} faultCode
 */
int SetFaultCodeRecord(FaultCode_t faultCode)
{
    // 判断是否有错误码
    if (faultCode.code == FAULT_CODE_IDLE) return 0;

    // 判断文件夹是否存在
    if (access(GetUserFaultCodeDirPtah(), F_OK) != 0) {
        char cmd[300] = {0};
        snprintf(cmd, 300, "mkdir -p %s", GetUserFaultCodeDirPtah());
        
        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    // 保存错误
    CrLogI("save fault code record");
    struct timeval newTime;
    gettimeofday(&newTime, NULL);
    
    json_object *info = json_object_new_object();
    json_object_object_add(info, "time", json_object_new_int(newTime.tv_sec));
    json_object_object_add(info, "code", json_object_new_int(faultCode.code));
    json_object_object_add(info, "error", json_object_new_int(faultCode.error));
    json_object_object_add(info, "msg", json_object_new_string(faultCode.msg));
    json_object_object_add(info, "value", json_object_new_string(faultCode.value));

    // 创建保存错误记录列表json数组
    json_object *listObj = json_object_new_array();
    // 添加错误记录到信息列表
    json_object_array_add(listObj, info);

    // 读取错误记录文件，获取文件已保存json数据，转移到新的记录json中
    GetFaultCodeOriginalData(listObj);

    // 判断错误记录数量
    CrLogI("fault code record = %d\n", json_object_array_length(listObj));

    // 创建保存错误记录json
    json_object *codeObj = json_object_new_object();
    json_object_object_add(codeObj, "list", listObj);

    // 保存到文件
    int res = json_object_to_file_ext(GetUserFaultCodeInfoPtah(), codeObj, JSON_C_TO_STRING_PRETTY|JSON_C_TO_STRING_NOSLASHESCAPE);
    json_object_put(codeObj);
    return res;
}

/*********************************************************
 *********************************************************
 ********************* 创建结构配置文件 *********************
 *********************************************************
 *********************************************************/
/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int CreateStructureConfigFile(void)
{
    json_object *config = json_object_from_file(GetDeviceStructureConfig());
    if (!config)
    {
        // 生成结构配置文件
        CrLogI("Create Structure Config File");
        CrLogI("model = %d\n", systemComfig.model);
        config = json_object_new_object();

        // 根据机型创建雷达结构偏移
        switch (systemComfig.model)
        {
            case CR_K1_Max:
            case K1_Max_SE:
            {
                json_object *laserObj = json_object_new_object();
                json_object_object_add(laserObj, "laser_x_offset", json_object_new_double(-36));
                json_object_object_add(laserObj, "laser_y_offset", json_object_new_double(-23.2));
                json_object_object_add(laserObj, "laser_z_offset", json_object_new_double(3));
                json_object_object_add(laserObj, "cali_x_offset", json_object_new_double(7));
                json_object_object_add(laserObj, "cali_y_offset", json_object_new_double(168));
                json_object_object_add(laserObj, "cali_z_offset", json_object_new_double(1));
                json_object_object_add(config, "laser_offset", laserObj);
                break;
            }
            case CR_K1:
            case K1C:
            {
                json_object *laserObj = json_object_new_object();
                json_object_object_add(laserObj, "laser_x_offset", json_object_new_double(-36));
                json_object_object_add(laserObj, "laser_y_offset", json_object_new_double(-23.2));
                json_object_object_add(laserObj, "laser_z_offset", json_object_new_double(3));
                json_object_object_add(laserObj, "cali_x_offset", json_object_new_double(7));
                json_object_object_add(laserObj, "cali_y_offset", json_object_new_double(140));
                json_object_object_add(laserObj, "cali_z_offset", json_object_new_double(1));
                json_object_object_add(config, "laser_offset", laserObj);
                break;
            }
            case PF_05: {
                json_object *laserObj = json_object_new_object();
                json_object_object_add(laserObj, "laser_x_offset", json_object_new_double(-36));
                json_object_object_add(laserObj, "laser_y_offset", json_object_new_double(-23.2));
                json_object_object_add(laserObj, "laser_z_offset", json_object_new_double(3));
                json_object_object_add(laserObj, "cali_x_offset", json_object_new_double(7));
                json_object_object_add(laserObj, "cali_y_offset", json_object_new_double(140));
                json_object_object_add(laserObj, "cali_z_offset", json_object_new_double(1));
                json_object_object_add(config, "laser_offset", laserObj);
                break;
            }
        }

        // 保存配置文件
        json_object_to_file_ext(GetDeviceStructureConfig(), config, JSON_C_TO_STRING_PRETTY|JSON_C_TO_STRING_NOSLASHESCAPE);
    }

    // 释放内存
    json_object_put(config);
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int CreatePrintParaConfigFile(void)
{
    json_object *config = json_object_from_file(GetDevicePrintParaConfig());
    if (!config)
    {
        // 生成打印参数配置文件
        CrLogI("Create Print Para Config File");
        config = json_object_new_object();

        // 创建流量检测对比参数
        {
            json_object *plaObj = json_object_new_object();
            json_object_object_add(plaObj, "min",       json_object_new_double(0.036));
            json_object_object_add(plaObj, "max",       json_object_new_double(0.05));
            json_object_object_add(plaObj, "optimal",   json_object_new_double(0.044));

            json_object *absObj = json_object_new_object();
            json_object_object_add(absObj, "min",       json_object_new_double(0.04));
            json_object_object_add(absObj, "max",       json_object_new_double(0.06));
            json_object_object_add(absObj, "optimal",   json_object_new_double(0.05));

            json_object *petgObj = json_object_new_object();
            json_object_object_add(petgObj, "min",       json_object_new_double(0.066));
            json_object_object_add(petgObj, "max",       json_object_new_double(0.076));
            json_object_object_add(petgObj, "optimal",   json_object_new_double(0.07));

            json_object *tpuObj = json_object_new_object();
            json_object_object_add(tpuObj, "min",       json_object_new_double(0.08));
            json_object_object_add(tpuObj, "max",       json_object_new_double(0.1));
            json_object_object_add(tpuObj, "optimal",   json_object_new_double(0.09));

            json_object *silkPlaObj = json_object_new_object();
            json_object_object_add(silkPlaObj, "min",       json_object_new_double(0.05));
            json_object_object_add(silkPlaObj, "max",       json_object_new_double(0.06));
            json_object_object_add(silkPlaObj, "optimal",   json_object_new_double(0.054));

            json_object *otherObj = json_object_new_object();
            json_object_object_add(otherObj, "min",       json_object_new_double(0.03));
            json_object_object_add(otherObj, "max",       json_object_new_double(0.06));
            json_object_object_add(otherObj, "optimal",   json_object_new_double(0.044));

            json_object *flowObj = json_object_new_object();
            json_object_object_add(flowObj, "PLA", plaObj);
            json_object_object_add(flowObj, "ABS", absObj);
            json_object_object_add(flowObj, "PETG", petgObj);
            json_object_object_add(flowObj, "TPU", tpuObj);
            json_object_object_add(flowObj, "Silk-PLA", silkPlaObj);
            json_object_object_add(flowObj, "other", otherObj);

            json_object_object_add(config, "flow_detect", flowObj);
        }

        // 保存配置文件
        json_object_to_file_ext(GetDevicePrintParaConfig(), config, JSON_C_TO_STRING_PRETTY|JSON_C_TO_STRING_NOSLASHESCAPE);
    }

    // 释放内存
    json_object_put(config);
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int GetMachineSnToFile(void)
{
    // 获取产线SN号
    #ifdef CROSS_COMPILE
    char resBuf[64] = {0};
    if (!PopenSystem(GetDefaultGetMachineSnScript(), resBuf, sizeof(resBuf)))
        CrLogW("set screen value fail !!\n");
    CrLogI("production sn = %s\n", resBuf);

    // SN是否有效
    if (strlen(resBuf) > 5) {
        json_object *machineInfoObj = json_object_new_object();
        json_object_object_add(machineInfoObj, "productionSn", json_object_new_string(resBuf));
        json_object_to_file_ext(GetMachineProductionInfo(), machineInfoObj, JSON_C_TO_STRING_PLAIN);
        json_object_put(machineInfoObj);
    }
    else {
        // 从文件获取生产信息
        json_object *productionInfoObj = json_object_from_file(GetMachineProductionInfo());
        if (productionInfoObj) {
            json_object *productionSnObj = GetJsonObject(productionInfoObj, "productionSn", json_type_string);
            if (productionSnObj) {
                const char *productionSn = json_object_get_string(productionSnObj);
                CrLogI("production sn = %s\n", productionSn);

                // 更新SN到写号分区
                char setCmd[256] = {0};
                snprintf(setCmd, sizeof(setCmd), GetDefaultSetMachineSnScript(), productionSn);
                // 设置
                bzero(resBuf, sizeof(resBuf));
                if (!PopenSystem(setCmd, resBuf, sizeof(resBuf)))
                    CrLogW("set screen value fail !!\n");
            }
            json_object_put(productionInfoObj);
        } 
    }
    #endif
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
double GetSaveFileZaxesHight(void)
{
    double zHight = 0;
    json_object *configObj = json_object_from_file(GetSaveZaxisHeight());
    if (configObj)
    {
        json_object *z_posObj = json_object_object_get(configObj, "z_pos");
        if (z_posObj) zHight = json_object_get_double(z_posObj);
        json_object_put(configObj);
    }
    return zHight;
}

/**
 * @description: 
 * @return {*}
 * @param {double} hight
 */
int SetSaveFileZaxesHight(double hight)
{
    json_object *configObj = json_object_from_file(GetSaveZaxisHeight());
    if (configObj)
    {
        CrLogI("set z axes height to file, height = %f", hight);
        json_object *z_posObj = json_object_object_get(configObj, "z_pos");
        if (z_posObj) json_object_set_double(z_posObj, hight);
        json_object_to_file(GetSaveZaxisHeight(), configObj);
        json_object_put(configObj);
    }
    return 0;
}

/*********************************************************
 *********************************************************
 ********************* 配置文件初始化 **********************
 *********************************************************
 *********************************************************/
/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int ConfigFileInit(void)
{
    CrLogI("Control Config File Init");
    pthread_rwlock_init(&rwLock, NULL);
    pthread_rwlock_init(&delayVideoLock, NULL);
    
    // 判断路径是否存在
    if (access(GetUserDataConfigDirPtah(), F_OK) != 0) {
        char cmd[300] = {0};
        snprintf(cmd, 300, "mkdir -p %s", GetUserDataConfigDirPtah());
        
        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }
    memset(&systemComfig, 0, sizeof(SystemConfig_t));

    // 不可删除的用户数据
    ReadUserDataNotDelete();
    // 系统版本
    ReadSystemVersion();
    // 系统配置
    ReadSystemConfig();
    // 用户偏好
    ReadPrintRrefer();
    // 发送系统配置
    MsaterSyncSystemConfig();
    // 创建结构配置文件
    CreateStructureConfigFile();
    // 创建打印参数配置文件
    CreatePrintParaConfigFile();
    // 读取产线SN号
    GetMachineSnToFile();
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int ConfigFileReset(void)
{
    CrLogI("Control Config File Reset");
    if (access(GetUserSystemConfigFilePath(), F_OK) == 0)
    {
        char cmd[254] = {0};
        snprintf(cmd, 254, "rm %s && sync", GetUserSystemConfigFilePath());
        CrLogI("%s", cmd);
        
        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }
    if (access(GetUserSystemVersionFilePath(), F_OK) == 0)
    {
        char cmd[254] = {0};
        snprintf(cmd, 254, "rm %s && sync", GetUserSystemVersionFilePath());
        CrLogI("%s", cmd);
        
        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }
    if (access(GetUserPrintReferFilePath(), F_OK) == 0)
    {
        char cmd[254] = {0};
        snprintf(cmd, 254, "rm %s && sync", GetUserPrintReferFilePath());
        CrLogI("%s", cmd);

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int PlaMaterialPreferExceptionHandleMallocPost(void)
{
    // 释放json资源
    if (saveUserRrefer) {
        json_object_put(saveUserRrefer);
        saveUserRrefer = NULL;
    }
    return 0;
}
