/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-09-02 13:45:54
 * @LastEditTime: 2023-06-01 17:04:08
 */

#include <string>
#include <algorithm>
#include <regex>

#include "Base/AppMsgBase.h"
#include "Message/ServerMessage.h"
#include "CxyManager/CxyHttpServer.h"
#include "CxyManager/CxyDownload.h"
#include "UpgradeManager.hh"

/**
 * @description: 
 * @return {*}
 */
UpgradeManager::UpgradeManager() {}

/**
 * @description: 
 * @return {*}
 */
UpgradeManager::~UpgradeManager()
{
    // 析构时保证子线程join进来
    if (m_upgradeThread.joinable()) {
        m_upgradeThread.join();
    }
}

/**
 * @description: 
 * @return {*}
 * @param {DevSysInfo_t} info
 */
void UpgradeManager::UpdataVerionOptions(DevSysInfo_t info) { m_deviceVersion = info; }

/**
 * @description: 
 * @return {*}
 * @param {string} input
 * @param {string} split
 */
std::vector<std::string> UpgradeManager::splitString(std::string input, std::string split)
{
    int begin = 0;
	std::vector<std::string> result;
	
	while (1) {
		size_t pos = input.find(split, begin);
		if (pos == std::string::npos)
		{
			result.push_back(input.substr(begin));
			break;
		}
		result.push_back(input.substr(begin, pos - begin));
		begin = pos + split.size();
	}

	return result;
}

/**
 * @description: 
 * @return {*}
 * @param {string} delectStr
 * @param {int} *buf
 */
int UpgradeManager::VersionStringToInt(std::string delectStr, int *buf)
{
    std::regex regmatch("\\d{1,3}");
    //迭代器声明
    std::string::const_iterator iterStart = delectStr.begin();
    std::string::const_iterator iterEnd = delectStr.end();

    // 获取版本
    int versionSize = 0;
    std::smatch result;
    while (regex_search(iterStart, iterEnd, result, regmatch)) {
        std::string temp = result[0];
        buf[versionSize++] = atoi(temp.c_str());
        iterStart = result[0].second;
    }

    return versionSize;
}

/**
 * @description: 
 * @return {*}
 * @param {string} curVersion
 * @param {string} newVersion
 */
int UpgradeManager::CompareVersion(std::string cur, std::string next)
{
    // 将字符串版本号转换成int数组
    int curVersion[5] = {0};
    int newVersion[5] = {0};
    int curSize = VersionStringToInt(cur, curVersion);
    int newSize = VersionStringToInt(next, newVersion);

    // 比较版本号
    int retval = 0;
    for(int i = 0; i < curSize; i++)
    {
        // 循环次数大于新版本的字符组数，且在此之前未比较出版本大小，则没有可升级版本
        if (i >= newSize) {
            retval = -1;
            break;
        }
        // 比较版本大小
        if( newVersion[i] > curVersion[i]) {
            retval = 1;
            break;
        }
        else if (newVersion[i] < curVersion[i]) {
            retval = -1;
            break;
        }
    }

    // 未比较出大小，且新版本字符长度长，则有可升级版本
    if (retval == 0 && newSize > curSize) retval = 1;

	return retval;
}

/**
 * @description: 
 * @return {*}
 * @param {json_object*} jsonObj
 * @param {char} *oldVersion
 * @param {NewImageInfo_t} *info
 */
bool UpgradeManager::CompareVersionInfo(json_object* jsonObj, char *oldVersion, NewImageInfo_t *info)
{
    bool flag = false; // 是否需要升级

    json_object *resultObj = json_object_object_get(jsonObj, "result");
    if (resultObj == NULL || !json_object_is_type(resultObj, json_type_object)) {
        CrLogW("no result\n");
        return flag;
    }

    json_object *countObj = json_object_object_get(resultObj, "count");
    if (countObj == NULL || !json_object_is_type(countObj, json_type_int)) {
        CrLogW("no count\n");
        return flag;
    }

    json_object *listObj = json_object_object_get(resultObj, "list");
    if (listObj == NULL || !json_object_is_type(listObj, json_type_array)) {
        CrLogW("no list\n");
        return flag;
    }

    // 获取信息列表总数
    int count = json_object_get_int(countObj);
    CrLogI("upgrade info count = %d", count);
    if (count <= 0) {
        CrLogI("No upgradeable version found\n");
        return flag;
    }

    // 遍历信息列表
    for (size_t i = 0; i < json_object_array_length(listObj); i++)
    {
        json_object *versionInfo = json_object_array_get_idx(listObj, i);
        // 获取版本号
        json_object *versionNumberObj = json_object_object_get(versionInfo, "versionNumber");
        if (versionNumberObj == NULL || !json_object_is_type(versionNumberObj, json_type_string)) {
            CrLogW("no get version nunber\n");
            continue;
        }

        // 获取版本号
        std::string curVersion = oldVersion;
        std::string newVersion = json_object_get_string(versionNumberObj);
        CrLogI("cur version = %s", curVersion.c_str());
        CrLogI("new version = %s", newVersion.c_str());

        // 比较版本
        if (CompareVersion(curVersion, newVersion) == 1) {
            CrLogI("find upgradeable version\n");
            flag = true;
        }
        else {
            CrLogI("No upgradeable version found\n");
            continue;
        }
        info->version = newVersion;

        // 获取升级文件名称
        json_object *nameObj = json_object_object_get(versionInfo, "name");
        if (nameObj != NULL && json_object_is_type(nameObj, json_type_string)) {
            info->name = json_object_get_string(nameObj);
            CrLogI("update file name = %s", info->name.c_str());
        }
        // 获取升级文件大小
        json_object *firmwareSizeObj = json_object_object_get(versionInfo, "firmwareSize");
        if (firmwareSizeObj != NULL && json_object_is_type(firmwareSizeObj, json_type_int)) {
            info->size = json_object_get_int(firmwareSizeObj);
            CrLogI("update file size = %d", info->size);
        }
        // 获取升级文件下载地址
        json_object *downloadUrlObj = json_object_object_get(versionInfo, "downloadUrl");
        if (downloadUrlObj != NULL && json_object_is_type(downloadUrlObj, json_type_string)) {
            info->url = json_object_get_string(downloadUrlObj);
            CrLogI("update download url = %s", info->url.c_str());
        }
        // 获取是否强制升级
        json_object *isForceObj = json_object_object_get(versionInfo, "isForce");
        if (isForceObj != NULL && json_object_is_type(isForceObj, json_type_boolean)) {
            info->isForce = json_object_get_boolean(isForceObj);
            CrLogI("update is force = %d", info->isForce);
        }
        // 获取更新说明
        json_object *updateDescriptionObj = json_object_object_get(versionInfo, "updateDescription");
        if (updateDescriptionObj != NULL && json_object_is_type(updateDescriptionObj, json_type_array)) {
            for(size_t i = 0; i < json_object_array_length(updateDescriptionObj); i++) {
                json_object *dataObj = json_object_array_get_idx(updateDescriptionObj, i);
                info->manual += json_object_get_string(dataObj);
            }
            CrLogI("update description = %s\n\n", info->manual.c_str());
        }
    }

    return flag;
}

/**
 * @description: 
 * @return {*}
 * @param {NewImageInfo_t} *info
 * @param {UpgradeTarget_t} target
 */
bool UpgradeManager::CheckForUpgrade(NewImageInfo_t *info, UpgradeTarget_t target)
{
    bool upgradeFlag = false; // 是否需要升级
    std::string upgradeInfo;
    char *model = (char*)m_deviceVersion.model.c_str();
    char *sysVersion = (char*)m_deviceVersion.sysVersion.c_str();
    char *hwVersion = (char*)m_deviceVersion.hwVersion.c_str();
    char *mcuSysVersion = (char*)m_deviceVersion.mcuSysVersion.c_str();
    char *mcuHwVersion = (char*)m_deviceVersion.mcuHwVersion.c_str();
    int setting = m_deviceVersion.deploySetting;
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(setting);
    // 初始化 http 请求 api
    std::string url = server.url;
    int rc = m_cxyHttpServer.CxyHttpApiInit(url, "upgrade_info");
    if (rc != 0) {
        CrLogE("cxy http api init fail\n\n\n");
        return upgradeFlag;
    }

    // 发出请求
    CURLcode res = CURL_LAST;
    switch (target) {
        case UPGRADE_TARGET_LINUX: res = m_cxyHttpServer.HttpGetUpgradeInfo(model, sysVersion, hwVersion, &upgradeInfo, LINUX_OTA); break;
        case UPGRADE_TARGET_MCU1: res = m_cxyHttpServer.HttpGetUpgradeInfo(model, sysVersion, mcuHwVersion, &upgradeInfo, MCU_OTA); break;
        default: res = m_cxyHttpServer.HttpGetUpgradeInfo(model, sysVersion, hwVersion, &upgradeInfo, LINUX_OTA); break;
    }
    if (res != CURLE_OK) {
        CrLogW("http request upgrade info fail\n");
        return upgradeFlag;
    }

    // 解析获取的升级固件信息
    json_object* infoObj = json_tokener_parse(upgradeInfo.c_str());
    if (infoObj == NULL || !json_object_is_type(infoObj, json_type_object))
    {
        CrLogW("return information parsing error\n");
        if (infoObj != NULL) json_object_put(infoObj);
        return upgradeFlag;
    }

    // 判断code值
    json_object *codeObj = json_object_object_get(infoObj, "code");
    json_object *msgObj = json_object_object_get(infoObj, "msg");
    if (codeObj == NULL || !json_object_is_type(codeObj, json_type_int) ||
        msgObj == NULL || !json_object_is_type(msgObj, json_type_string))
    {
        CrLogW("no code or msg\n");
        json_object_put(infoObj);
        return upgradeFlag;
    }

    // 判断请求信息是否成功
    CrLogI("code = %d; msg = %s", json_object_get_int(codeObj), json_object_get_string(msgObj));
    if (json_object_get_int(codeObj) == 0 && strcmp(json_object_get_string(msgObj), "ok") == 0)
    {
        switch (target) {
            case UPGRADE_TARGET_LINUX: upgradeFlag = CompareVersionInfo(infoObj, sysVersion, info); break;
            case UPGRADE_TARGET_MCU1: upgradeFlag = CompareVersionInfo(infoObj, mcuSysVersion, info); break;
            default: upgradeFlag = CompareVersionInfo(infoObj, sysVersion, info); break;
        }
    }

    // 释放json
    json_object_put(infoObj);
    return upgradeFlag;
}

/**
 * @description: 
 * @return {*}
 * @param {int} state
 * @param {string} fileName
 */
int UpgradeManager::FirmwareDownloadStateCb(int state, std::string fileName)
{
    CrLogI("firmware Download state = %d", state);
    if (state == FILE_DOWNLOAD_OK)
    {
        CrLogI("new Firmware download finish\n");
        m_deviceVersion.updataInfoCb(UPGRADE_DOWNLOAD_OK, 100, m_UpgradeTarget);

        // OTA下载完成，开始本地升级
        UpgradeInfo otaInfo = UPGRADE_INFO__INIT;
        otaInfo.has_imagepath = 1;
        otaInfo.imagepath.data = (uint8_t*)fileName.c_str();
        otaInfo.imagepath.len = fileName.length();

        UpgradeInfoList list = UPGRADE_INFO_LIST__INIT;
        if (m_UpgradeTarget == UPGRADE_TARGET_LINUX)
            list.linuxlocal = &otaInfo;
        else list.mcu1local = &otaInfo;

        GET_MESSAGE_BUFF(buff);
        size_t len = upgrade_info_list__pack(&list, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_UPGRADE_MANAGER, SERVER_CMD_APP_START_LOCAL_UPGRADE, buff, len);
        SendProcessMsgBuff(&send, size);
    }
    else if (state == FILE_DOWNLOAD_FAIL)
    {
        CrLogI("new Firmware download fail\n");
        m_deviceVersion.updataInfoCb(UPGRADE_DOWNLOAD_FAIL, 0, m_UpgradeTarget);
    }
    else if (state == FILE_DOWNLOAD_CANCEL)
    {
        CrLogI("new Firmware download cancel\n");
        m_deviceVersion.updataInfoCb(UPGRADE_DOWNLOAD_CANCEL, 0, m_UpgradeTarget);
    }

    // 释放类
    if (state == FILE_DOWNLOAD_OK || 
        state == FILE_DOWNLOAD_FAIL ||
        state == FILE_DOWNLOAD_CANCEL)
    {
        delete m_firmwareDownload;
        m_firmwareDownload = NULL;
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {int} progress
 */
int UpgradeManager::FirmwareDownloadProgressCb(int progress)
{
    CrLogI("firmware Download Progress = %d", progress);
    m_deviceVersion.updataInfoCb(UPGRADE_DOWNLOAD_ING, progress, m_UpgradeTarget);
	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {NewImageInfo_t} info
 */
int UpgradeManager::UserStartUpgrade(NewImageInfo_t info, UpgradeTarget_t target)
{
    if (access(GetUserUpgradeDirPtah(), F_OK) != 0) {
        char cmd[254] = {0};
        snprintf(cmd, 254, "mkdir -p %s", GetUserUpgradeDirPtah());

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    // 下载更新镜像
    m_firmwareDownload = new CxyDownload();
    m_deviceVersion.updataInfoCb(UPGRADE_DOWNLOAD_ING, 0, m_UpgradeTarget);

    CxyDownloadOptions_t options;
    options.url = info.url;
    options.filePath = GetUserUpgradeDirPtah();
    options.conStateCb = [this](int state, std::string res) {return FirmwareDownloadStateCb(state, res);};
    options.progressCb = [this](int res) {return FirmwareDownloadProgressCb(res);};
    m_firmwareDownload->Init(options);
    m_firmwareDownload->Start();
    m_UpgradeTarget = target;

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
int UpgradeManager::UserCancelUpgrade(void)
{
    // 取消更新下载
    if (m_firmwareDownload) {
        m_firmwareDownload->Stop();
        return 0;
    }
    return -1;
}
