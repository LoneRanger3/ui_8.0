/*
 * @Description : 升级设备管理器
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:09
 * @LastEditTime: 2023-11-02 21:14:19
 */

#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

#include "Base/MasterMsgBase.h"
#include "UpgradeManager.h"

static MsgHandle_t msgHandle;
static int managerMsgId = -1;
static int serverMsgId = -1;
static bool getMcuVersion = true;
static bool duringUpgradeFlag = false;

/**
 * @description: 静态函数声明
 */
static int SendMsgBuff(MsgHeadBuf_t *data, size_t len);
static int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len);


/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHead} *head
 */
static void ServerMessageTestAns(MsgHeadBuf_t *head)
{
    ServerTest *recv = server_test__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("dialogue = %s\n", recv->dialogue);
    server_test__free_unpacked(recv, NULL);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {MsgHead} *head
 */
static void ManagerMessageTest(MsgHeadBuf_t *head)
{
    ManagerTest *recv = manager_test__unpack(NULL, head->bufLen, head->buf);
    if (!recv) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("dialogue = %s\n", recv->dialogue);
    manager_test__free_unpacked(recv, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void DisGetSystemConfigRes(MsgHeadBuf_t *head)
{
    SystemConfig_t config = GetSystemConfig();
    SystemConfigProto sendConfig = SYSTEM_CONFIG_PROTO__INIT;

    sendConfig.has_sys_version = 1;
    sendConfig.sys_version.data = (uint8_t*)config.sys_version;
    sendConfig.sys_version.len = strlen(config.sys_version);
    sendConfig.has_hw_version = 1;
    sendConfig.hw_version.data = (uint8_t*)config.hw_version;
    sendConfig.hw_version.len = strlen(config.hw_version);
    sendConfig.has_model = 1;
    sendConfig.model = config.model;
    sendConfig.has_model_str = 1;
    sendConfig.model_str.data = (uint8_t*)config.model_str;
    sendConfig.model_str.len = strlen(config.model_str);
    sendConfig.has_creality_num = 1;
    sendConfig.creality_num = config.creality_num;
    CrLogI("version; sys = %s, hw = %s, model = %s",
            config.sys_version, config.hw_version, config.model_str);

    GET_MESSAGE_BUFF(buff);
    size_t len = system_config_proto__pack(&sendConfig, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_UPGRADE_MANAGER, SERVER_CMD_UPGRADE_SYSTEM_CONFIG_ANS, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
static void DisGetDeviceStateRes(MsgHeadBuf_t *head)
{
    PrintState_t curState = GetPrintState();

    // 获取下位机版本
    if (curState.serialPort && getMcuVersion) {
        CrLogI("get current mcu version");
        getMcuVersion = false;
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_UPGRADE_MANAGER, MANAGER_CMD_GET_CUR_MCU_VERSION_REQ, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }
}

/**
 * @description: 
 * @return {*}
 * @param {dirent} *entry
 */
static int FindImageFilter(const struct dirent *entry)
{
    if (strstr(entry->d_name, ".img") && entry->d_name[0] != '.')
        return 1;
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {dirent} *entry
 */
static int FindFirmwareFilter(const struct dirent *entry)
{
    if (strstr(entry->d_name, ".bin") && entry->d_name[0] != '.')
        return 1;
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *delectStr
 * @param {int} *buf111
 */
static int VersionStringToInt(char *delectStr, int *buf)
{
    char *regex = "[0-9]{1,3}";
    regmatch_t regmatch[10];
    int regexSize = UserGetRegexStr(delectStr, regex, regmatch, 10);

    for(int i = 0; i< regexSize; i++)
    {
        int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &delectStr[regmatch[i].rm_so], cnt);
        buf[i] = atoi(str);
    }

    return regexSize;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *cur
 * @param {char} *next
 */
static int CompareVersion(char *cur, char *next)
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
 * @param {char} *cur
 * @param {char} *next
 */
static int IsUpgradeSystemImage(char *cur, char *next)
{
    // 获取符合当前版本可降版本的最低限制
    char *baseVersionStr = cur;
    switch (GetSystemConfig().model) {
        case CR_K1: baseVersionStr = FALLBACK_MIN_VERSION_K1; break;
        case CR_K1_Max: baseVersionStr = FALLBACK_MIN_VERSION_K1_MAX; break;
        case PF_05: baseVersionStr = FALLBACK_MIN_VERSION_PF_05; break;
    }

    // 将字符串版本号转换成int数组
    int curVersion[5] = {0};
    int newVersion[5] = {0};
    int baseVersion[5] = {0};
    VersionStringToInt(cur, curVersion);
    VersionStringToInt(next, newVersion);
    VersionStringToInt(baseVersionStr, baseVersion);
    CrLogI("baseVersionStr = %s", baseVersionStr);

    int curVersionInt = (curVersion[0] << 24) + (curVersion[1] << 16) + (curVersion[2] << 8) + curVersion[3];
    int newVersionInt = (newVersion[0] << 24) + (newVersion[1] << 16) + (newVersion[2] << 8) + newVersion[3];
    int baseVersionInt = (baseVersion[0] << 24) + (baseVersion[1] << 16) + (baseVersion[2] << 8) + baseVersion[3];
    CrLogI("curVersionInt = %d, newVersionInt = %d, baseVersionInt = %d",
            curVersionInt, newVersionInt, baseVersionInt);

    // 比较版本号，判断版本号是否相同，是否符合当前版本可降版本的最低限制
    if (curVersionInt < newVersionInt) return 1;
    if ((curVersionInt > newVersionInt) && (newVersionInt >= baseVersionInt)) return 1;
    else return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {UpgradeLocalFindOptions_t} options
 * @param {FirmwareInfo_t} *firmwareInfo
 */
static bool GetLocalNewVersionInfo(UpgradeLocalFindOptions_t options, FirmwareInfo_t *firmwareInfo)
{
    CrLogI("U disk path = %s, upgrade target = %d", options.findPath, options.type);
    CrLogI("upgrade: software = %s, hardware = %s", options.software, options.hardware);

    // 判断是否存在硬件版本
    if (!options.software || strlen(options.software) < 2 ||
        !options.hardware || strlen(options.hardware) < 2)
    {
        CrLogW("No find device version\n");
        return false;
    }
    
    // 按照指定规则遍历文件
    int count = 0;
    struct dirent **entryList = NULL;
    switch (options.type) {
        case UPGRADE_TARGET_LINUX: count = scandir(options.findPath, &entryList, FindImageFilter, alphasort); break;
        case UPGRADE_TARGET_MCU1: count = scandir(options.findPath, &entryList, FindFirmwareFilter, alphasort); break;
        default: count = scandir(options.findPath, &entryList, FindImageFilter, alphasort); break;
    }

    // 最大版本号镜像文件名称
    char maxVersionName[256] = {0};
    char maxVersionNum[32] = {0};
    for (int i = 0; i < count; i++)
    {
        // 获取文件名称，过滤硬件版本
        struct dirent *entry = entryList[i];
        char *nextFile = strstr(entry->d_name, options.hardware);
        if (nextFile)
        {
            // 获取比较前后，固件软件版本信息
            char nextVersion[256] = {0};
            strcat(nextVersion, (strstr(nextFile, "ota_img_V") + strlen("ota_img_V")));
            char *suffix = strrchr(nextVersion, '.');
            if (suffix) suffix[0] = '\0';

            char curVersion[256] = {0};
            char *curFile = strstr(maxVersionName, options.hardware);
            if (curFile) {
                strcat(curVersion, (strstr(curFile, "ota_img_V") + strlen("ota_img_V")));
                char *suffix = strrchr(curVersion, '.');
                if (suffix) suffix[0] = '\0';
            }
            CrLogI("curVersion = %s, nextVersion = %s", curVersion, nextVersion);

            // 对比软件版本
            if (CompareVersion(curVersion, nextVersion) == 1) {
                bzero(maxVersionName, sizeof(maxVersionName));
                strcat(maxVersionName, entry->d_name);
                bzero(maxVersionNum, sizeof(maxVersionNum));
                strcat(maxVersionNum, nextVersion);
            }
        }
        free(entry);
    }
    free(entryList);

    // 判断U盘中是否有符合条件镜像文件
    if (strlen(maxVersionName)) {
        CrLogI("find the upgrade file with the largest version number");
        CrLogI("version = %s, file name = %s", maxVersionNum, maxVersionName);

        // 对比软件版本
        if (IsUpgradeSystemImage(options.software, maxVersionNum) == 1) {
            // 拼接文件绝对路径
            char filePath[512] = {0};
            sprintf(filePath, "%s/%s", options.findPath, maxVersionName);
            // 获取文件信息
            struct stat stat_info;
            int ret = lstat(filePath, &stat_info);
            if (ret == -1) {
                CrLogW("%s get info error !", filePath);
            }
            CrLogI("name = %s, fileSize = %d\n", filePath, stat_info.st_size);

            memcpy(firmwareInfo->version, maxVersionNum, strlen(maxVersionNum));
            memcpy(firmwareInfo->name, maxVersionName, strlen(maxVersionName));
            memcpy(firmwareInfo->path, filePath, strlen(filePath));
            firmwareInfo->size = stat_info.st_size;
            return true;
        }
        else {
            CrLogW("less than the current version\n");
            return false;
        }
    }
    else {
        CrLogW("No find image file from u disk\n");
        return false;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void ManagerCheckUpgradeRes(MsgHeadBuf_t *head)
{
    UpgradeInfoList *infoList = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!infoList) {
        CrLogW("unpack failed\n");
        return;
    }

    // 用户检查升级
    CrLogI("get local upgrade info\n");
    FirmwareInfo_t linuxFirmware = {0};
    FirmwareInfo_t mcuFirmware = {0};
    UpgradeInfo linuxInfo = UPGRADE_INFO__INIT;
    UpgradeInfo mcu1Info = UPGRADE_INFO__INIT;
    UpgradeInfoList list = UPGRADE_INFO_LIST__INIT;
    
    UpgradeLocalFindOptions_t options = {0};
    options.findPath = GetUserLocalUdiskPtah();
    // 升级
    if (infoList->linuxlocal) {
        CrLogI("start get linux local image");
        if (access(GetUserLocalUdiskPtah(), F_OK) == 0)
        {
            options.software = GetSystemConfig().sys_version;
            options.hardware = GetSystemConfig().hw_version;
            options.type = UPGRADE_TARGET_LINUX;
            if (GetLocalNewVersionInfo(options, &linuxFirmware))
            {
                linuxInfo.has_version = 1;
                linuxInfo.version.data = (uint8_t*)linuxFirmware.version;
                linuxInfo.version.len = strlen(linuxFirmware.version);
                linuxInfo.has_name = 1;
                linuxInfo.name.data = (uint8_t*)linuxFirmware.name;
                linuxInfo.name.len = strlen(linuxFirmware.name);
                linuxInfo.has_size = 1;
                linuxInfo.size = linuxFirmware.size;
                linuxInfo.has_imagepath = 1;
                linuxInfo.imagepath.data = (uint8_t*)linuxFirmware.path;
                linuxInfo.imagepath.len = strlen(linuxFirmware.path);
            }
            else CrLogW("no get linux local image\n");
        }
        else CrLogW("U disk not detected\n");
        list.linuxlocal = &linuxInfo;
    }
    if (infoList->mcu1local) {
        CrLogI("start get mcu local firmware");
        if (access(GetUserLocalUdiskPtah(), F_OK) == 0)
        {
            options.software = GetSystemConfig().fw_version;
            options.hardware = GetSystemConfig().hw1_version;
            options.type = UPGRADE_TARGET_MCU1;
            if (GetLocalNewVersionInfo(options, &mcuFirmware))
            {
                mcu1Info.has_version = 1;
                mcu1Info.version.data = (uint8_t*)mcuFirmware.version;
                mcu1Info.version.len = strlen(mcuFirmware.version);
                mcu1Info.has_name = 1;
                mcu1Info.name.data = (uint8_t*)mcuFirmware.name;
                mcu1Info.name.len = strlen(mcuFirmware.name);
                mcu1Info.has_size = 1;
                mcu1Info.size = mcuFirmware.size;
                mcu1Info.has_imagepath = 1;
                mcu1Info.imagepath.data = (uint8_t*)mcuFirmware.path;
                mcu1Info.imagepath.len = strlen(mcuFirmware.path);
            }
            else CrLogW("no get mcu local firmware\n");
        }
        else CrLogW("U disk not detected\n");
        list.mcu1local = &mcu1Info;
    }

    GET_MESSAGE_BUFF(buff);
    size_t len = upgrade_info_list__pack(&list, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_UPGRADE_MANAGER, MANAGER_CMD_GET_UPGRADE_INFO_ANS, buff, len);
    MANAGER_MSG_SEND(head->origin, &send, size);
    upgrade_info_list__free_unpacked(infoList, NULL);
}

/**
 * @description: 
 * @return {*}
 */
static bool IsPossibleUpgrade(void)
{
    if (duringUpgradeFlag) {
        CrLogW("device during upgrade\n");
        return false;
    }
    else if (GetPrintState().workMode != APP_MODE_IDLE) {
        CrLogW("device printing\n");
        return false;
    }
    else {
        return true;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void SendStartUpgradeToServer(uint8_t *buff, size_t len)
{
    if (!IsPossibleUpgrade()) {
        CrLogW("The device does not meet the upgrade requirements\n");
        return;
    }
    
    duringUpgradeFlag = true;
    UpdataDeviceState(DEVICE_STATE_UPGRADING);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_UPGRADE_MANAGER, SERVER_CMD_START_UPGRADE_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void systemGetMcuVersionAns(MsgHeadBuf_t *head)
{
    CurMcuVersionList *list = cur_mcu_version_list__unpack(NULL, head->bufLen, head->buf);
    if (!list) {
        CrLogW("unpack failed\n");
        return;
    }

    // 获取版本信息
    FirmwareInfo_t hostMcuFirmwareInfo = {0};
    FirmwareInfo_t nozzleMcuFirmwareInfo = {0};
    FirmwareInfo_t bedMcuFirmwareInfo = {0};

    UpgradeInfo hostMcu = UPGRADE_INFO__INIT;
    UpgradeInfo nozzleMcu = UPGRADE_INFO__INIT;
    UpgradeInfo bedMcu = UPGRADE_INFO__INIT;
    UpgradeInfoList startList = UPGRADE_INFO_LIST__INIT;

    // 解析下位机版本，判断是否启动升级
    UpgradeLocalFindOptions_t options = {0};
    options.findPath = GetUserLocalUdiskPtah();
    options.type = UPGRADE_TARGET_MCU1;
    // 运动下位机
    if (list->hostmcu)
    {
        if (list->hostmcu->has_software)
            CrLogI("host mcu software version = %s", list->hostmcu->software.data);
        if (list->hostmcu->has_hardware)
            CrLogI("host mcu hardware version = %s", list->hostmcu->hardware.data);

        options.software = (char*)list->hostmcu->software.data;
        options.hardware = GetSystemConfig().hw_version;
        if (GetLocalNewVersionInfo(options, &hostMcuFirmwareInfo)){
            hostMcu.has_imagepath = 1;
            hostMcu.imagepath.data = (uint8_t*)hostMcuFirmwareInfo.path;
            hostMcu.imagepath.len = strlen(hostMcuFirmwareInfo.path);
            startList.mcu1local = &hostMcu;
        }
        else CrLogW("no get new version bin\n");
    }
    // 喷嘴下位机
    if (list->nozzlemcu)
    {
        if (list->nozzlemcu->has_software)
            CrLogI("nozzle mcu software version = %s", list->nozzlemcu->software.data);
        if (list->nozzlemcu->has_hardware)
            CrLogI("nozzle mcu hardware version = %s", list->nozzlemcu->hardware.data);

        options.software = (char*)list->nozzlemcu->software.data;
        options.hardware = (char*)list->nozzlemcu->hardware.data;
        if (GetLocalNewVersionInfo(options, &nozzleMcuFirmwareInfo)) {
            nozzleMcu.has_imagepath = 1;
            nozzleMcu.imagepath.data = (uint8_t*)nozzleMcuFirmwareInfo.path;
            nozzleMcu.imagepath.len = strlen(nozzleMcuFirmwareInfo.path);
            startList.mcu2local = &nozzleMcu;
        }
        else CrLogW("no get new version bin\n");
    }
    // 热床下位机
    if (list->bedmcu)
    {
        if (list->bedmcu->has_software)
            CrLogI("bed mcu software version = %s", list->bedmcu->software.data);
        if (list->bedmcu->has_hardware)
            CrLogI("bed mcu hardware version = %s", list->bedmcu->hardware.data);

        options.software = (char*)list->bedmcu->software.data;
        options.hardware = (char*)list->bedmcu->hardware.data;
        if (GetLocalNewVersionInfo(options, &bedMcuFirmwareInfo)) {
            bedMcu.has_imagepath = 1;
            bedMcu.imagepath.data = (uint8_t*)bedMcuFirmwareInfo.path;
            bedMcu.imagepath.len = strlen(bedMcuFirmwareInfo.path);
            startList.mcu3local = &bedMcu;
        }
        else CrLogW("no get new version bin\n");
    }

    // 判断是否有下位机需要启动升级
    if (startList.mcu1local || startList.mcu2local || startList.mcu3local) {
        GET_MESSAGE_BUFF(buff);
        size_t len = upgrade_info_list__pack(&startList, buff);
        SendStartUpgradeToServer(buff, len);
    }
    else CrLogI("No lower computer needs to be upgraded");
    
    cur_mcu_version_list__free_unpacked(list, NULL);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserStartDeviceUpgradeRes(MsgHeadBuf_t *head)
{
    CrLogI("Start Device upgrade Res");
    SendStartUpgradeToServer(head->buf, head->bufLen);
}

/**
 * @description: 
 * @return {*}
 * @param {MsgHeadBuf_t} *head
 */
static void UserStartUpgradeAns(MsgHeadBuf_t *head)
{
    UpgradeInfoList *list = upgrade_info_list__unpack(NULL, head->bufLen, head->buf);
    if (!list) {
        CrLogW("unpack failed\n");
        return;
    }

    CrLogI("user start upgrade ans");
    bool restartKlipperFilg = false;
    bool restartSystemFilg = false;

    // 判断升级结果
    if (list->linuxlocal && list->linuxlocal->has_state) {
        CrLogI("upgrade linux result = %d", list->linuxlocal->state);
        if (list->linuxlocal->state == UPGRADE_INSTALL_OK)
        {
            // 创建升级文件夹
            if (access(GetUserUpgradeDirPtah(), F_OK) != 0) {
                char cmd[254] = {0};
                snprintf(cmd, 254, "mkdir -p %s", GetUserUpgradeDirPtah());

                // 调用系统命令
                char sysRes[1024] = {0};
                if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
                    CrLogW("system fail! res = %s\n", sysRes);
            }
            
            // 创建升级信息文件，重启时使用
            json_object *infoObj = json_object_new_object();
            json_object_object_add(infoObj, "upgrade", json_object_new_int(1));
            json_object_object_add(infoObj, "sysVersion", json_object_new_string(GetSystemConfig().sys_version));
            if (json_object_to_file_ext(GetUserUpgradeInfoPtah(), infoObj, JSON_C_TO_STRING_PRETTY) == -1) {
                CrLogW("save upgrade info file fail !!\n");
            }
            json_object_put(infoObj);

            // 删除相关配置文件
            if (remove(GetUserSystemVersionFilePath()) != 0)
                CrLogW("remove faile = %s, file = %s\n", strerror(errno), GetUserSystemVersionFilePath());
            if (remove(GetUserIotConfigPath()) != 0)
                CrLogW("remove faile = %s, file = %s\n", strerror(errno), GetUserIotConfigPath());
            if (remove(GetUserDataLogConfigPtah()) != 0)
                CrLogW("remove faile = %s, file = %s\n", strerror(errno), GetUserDataLogConfigPtah());
            if (remove(GetDeviceStructureConfig()) != 0)
                CrLogW("remove faile = %s, file = %s\n", strerror(errno), GetDeviceStructureConfig());
            if (remove(GetDevicePrintParaConfig()) != 0)
                CrLogW("remove faile = %s, file = %s\n", strerror(errno), GetDevicePrintParaConfig());

            // 删除除“printer.cfg”外所有的klipper配置文件
            char cmd[512] = {0};
            snprintf(cmd, sizeof(cmd), "/usr/bin/find '%s' -path '%s/%s' -prune -o -path '%s' -o -print -exec rm -rf {} \\;",
                GetUserPrinterConfigPath(), GetUserPrinterConfigPath(), PRINTER_CONFIG_FILE, GetUserPrinterConfigPath());
            CrLogI("cmd = %s", cmd);
            
            char sysRes[1024] = {0};
            PopenSystem(cmd, sysRes, sizeof(sysRes));
            CrLogI("delete klipper config file; res = %s\n", sysRes);

            // // 删除 /overlay/upper/
            // {
            //     CrLogI("remove /overlay/upper/ ....");
            //     char cmd[256] = {0};
            //     snprintf(cmd, sizeof(cmd), "rm -rf %s/* && sync", GetDefaultOverlayUpperPtah());

            //     // 调用系统命令
            //     char sysRes[1024] = {0};
            //     if (!PopenSystem(cmd, sysRes, sizeof(sysRes))) {
            //         CrLogW("system fail! res = %s\n", sysRes);
            //         CrLogW("remove /overlay/upper/ fail\n");
            //     }
            // }
            
            // 设置系统重启标志
            restartSystemFilg = true;
        }
        else if (list->linuxlocal->state == UPGRADE_INSTALL_FAIL) {
            CrLogW("linux upgrade fail\n\n");
        }

        // 退出升级状态
        if (list->linuxlocal->state == UPGRADE_INSTALL_OK ||
            list->linuxlocal->state == UPGRADE_INSTALL_FAIL) {
            duringUpgradeFlag = false;
            UpdataDeviceState(DEVICE_STATE_IDLE);
        }
    }
    if (list->mcu1local && list->mcu1local->has_state) {
        CrLogI("upgrade mcu1 result = %d", list->mcu1local->state);
        if (list->mcu1local->state == UPGRADE_INSTALL_OK) {
            // 设置klipper重启标志
            restartKlipperFilg = true;
        }
        else if (list->mcu1local->state == UPGRADE_INSTALL_FAIL)
            CrLogW("host mcu upgrade fail\n\n");
        
        // 退出升级状态
        if (list->mcu1local->state == UPGRADE_INSTALL_OK ||
            list->mcu1local->state == UPGRADE_INSTALL_FAIL) {
            duringUpgradeFlag = false;
            UpdataDeviceState(DEVICE_STATE_IDLE);
        }
    }
    if (list->mcu2local && list->mcu2local->has_state) {
        CrLogI("upgrade mcu2 result = %d", list->mcu2local->state);
        if (list->mcu2local->state == UPGRADE_INSTALL_OK) {
            // 设置klipper重启标志
            restartKlipperFilg = true;
        }
        else if (list->mcu2local->state == UPGRADE_INSTALL_FAIL)
            CrLogW("nozzle mcu upgrade fail\n\n");

        // 退出升级状态
        if (list->mcu2local->state == UPGRADE_INSTALL_OK ||
            list->mcu2local->state == UPGRADE_INSTALL_FAIL) {
            duringUpgradeFlag = false;
            UpdataDeviceState(DEVICE_STATE_IDLE);
        }
    }
    if (list->mcu3local && list->mcu3local->has_state) {
        CrLogI("upgrade mcu3 result = %d", list->mcu3local->state);
        if (list->mcu3local->state == UPGRADE_INSTALL_OK) {
            // 设置klipper重启标志
            restartKlipperFilg = true;
        }
        else if (list->mcu3local->state == UPGRADE_INSTALL_FAIL)
            CrLogW("bed mcu upgrade fail\n\n");
        
        // 退出升级状态
        if (list->mcu3local->state == UPGRADE_INSTALL_OK ||
            list->mcu3local->state == UPGRADE_INSTALL_FAIL) {
            duringUpgradeFlag = false;
            UpdataDeviceState(DEVICE_STATE_IDLE);
        }
    }

    // 同步升级状态到各个交互端
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_UPGRADE_MANAGER, MANAGER_SYNC_DEV_UPGRADE_STATE, head->buf, head->bufLen);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
    MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);

    // 判断是否重启klipper
    if (restartKlipperFilg) {
        CrLogI("restart klipper\n\n");
    }

    // 判断是否重启系统
    if (restartSystemFilg) {
        CrLogI("upgrade system\n\n");
        // 重启系统
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_UPGRADE_MANAGER, MANAGER_CONTROL_SYSTEM_REBOOT, "", 0);
        MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
    }

    upgrade_info_list__free_unpacked(list, NULL);
}

/**
 * @description: 消息更新
 * @param  {*}
 * @return {*}
 */
static void msgUpdata(void)
{
    MsgHeadBuf_t head;
    ssize_t headSize = RECV_MESSAGE_PACKAGE(managerMsgId, &head);
    
    if (headSize > 0)
    {
        CrLogI("package len = %ld, origin %d, cmd %d, message len %ld", headSize, head.origin, head.cmd, head.bufLen);

        switch (head.cmd)
        {
            case SERVER_CMD_UPGRADE_TEST_ANS: ServerMessageTestAns(&head); break;
            case MANAGER_CMD_MESSAGE_TEST: ManagerMessageTest(&head); break;
            case SERVER_CMD_UPGRADE_SYSTEM_CONFIG_REQ: DisGetSystemConfigRes(&head); break;

            case MANAGER_SYNC_SYSTEM_CONFIG: DisGetSystemConfigRes(&head); break;
            case MANAGER_DEVICE_STATE_CHANGE: DisGetDeviceStateRes(&head); break;

            case MANAGER_CMD_GET_UPGRADE_INFO_REQ: ManagerCheckUpgradeRes(&head); break;
            case MANAGER_CMD_GET_CUR_MCU_VERSION_ANS: systemGetMcuVersionAns(&head); break;
            case MANAGER_CMD_START_UPGRADE_REQ: UserStartDeviceUpgradeRes(&head); break;

            case SERVER_CMD_START_UPGRADE_ANS: UserStartUpgradeAns(&head); break;

            default:
            {
                CrLogW("msg cmd file !!! origin %d, cmd %d\n", head.origin, head.cmd);
                break;
            }
        }
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static void CleanMessageQueue(void)
{
    MsgHeadBuf_t head;
    while (1)
    {
        ssize_t headSize = RECV_MESSAGE_PACKAGE_NOWAIT(managerMsgId, &head);
        if (headSize == -1)
        {
            CrLogI("The message queue has been emptied");
            break;
        }
    }
}

/**
 * @description: 
 * @return {*}
 */
static void DelectUpgradeRestart(void)
{
    if (access(GetUserUpgradeInfoPtah(), F_OK) == 0) {
        // 读取文件，获取json数据
        json_object *infoObj = json_object_from_file(GetUserUpgradeInfoPtah());
        if (infoObj && json_object_is_type(infoObj, json_type_object))
        {
            UpgradeRebootSync upgradeInfo = UPGRADE_REBOOT_SYNC__INIT;
            // 获取升级前保存信息
            json_object *upgradeObj = json_object_object_get(infoObj, "upgrade");
            if (upgradeObj && json_object_is_type(upgradeObj, json_type_int))
            {
                CrLogI("upgrade restart = %d", json_object_get_int(upgradeObj));
                upgradeInfo.state = json_object_get_int(upgradeObj);
            }
            else CrLogI("no upgrade restart\n");

            json_object *versionObj = json_object_object_get(infoObj, "sysVersion");
            if (versionObj && json_object_is_type(versionObj, json_type_string))
            {
                CrLogI("upgrade version = %s\n\n", json_object_get_string(versionObj));
                upgradeInfo.oldversion.data = (uint8_t*)json_object_get_string(versionObj);
                upgradeInfo.oldversion.len = json_object_get_string_len(versionObj);
            }
            else CrLogI("no upgrade restart\n");
            json_object_put(infoObj);

            // 延时通知交互管理线程升级状态
            usleep(1000 * 100);
            GET_MESSAGE_BUFF(buff);
            size_t len = upgrade_reboot_sync__pack(&upgradeInfo, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_UPGRADE_MANAGER, MANAGER_CMD_SYNC_UPGRADE_REBOOT_INFO, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_APP_MANAGER, &send, size);
            MANAGER_MSG_SEND(MSG_ORIGIN_WEB_MANAGER, &send, size);
            MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
        }
        else {
            CrLogI("no upgrade restart\n");
            if (infoObj) json_object_put(infoObj);
        }

        // 删除升级信息文件
        if (remove(GetUserUpgradeInfoPtah()) != 0)
            CrLogW("remove faile = %s, file = %s\n", strerror(errno), GetUserUpgradeInfoPtah());
    }
    else CrLogI("no upgrade restart\n");
}

/**
 * @description: 管理器主线程
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
static void *ManagerThread(void *arg)
{
    // 创建消息队列
    managerMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_UPGRADE_MANAGER);
    if (managerMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    serverMsgId = CREATE_MESSAGE_QUEUE(MSG_KEY_UPGRADE_SERVER);
    if (serverMsgId == -1)
    {
        CrLogE("errno = %s\n", strerror(errno));
        CrLogE("create manager msg queue fail\n");
    }
    // 清空消息队列
    CleanMessageQueue();
    DelectUpgradeRestart();

    while (1)
    {
        msgUpdata();
        usleep(1000 * 10);
    }

    return NULL;
}

/**
 * @description: 管理器初始化
 * @param  {*}
 * @return {*}
 * @param {void} *arg
 */
MsgHandle_t *UpgradeManagerInit(void *arg)
{
    CrLogI("upgrade manager init");
    int res = pthread_create(&msgHandle.handle, NULL, (void*)ManagerThread, arg);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return NULL;
    }
    msgHandle.sendMsgBuff = &SendMsgBuff;
    
    return &msgHandle;  
}

/**
 * @description: 发送消息到消息队列
 * @param  {*}
 * @return {*}
 * @param {uint8_t} *data
 */
static int SendMsgBuff(MsgHeadBuf_t *data, size_t len)
{
    if (managerMsgId == -1)
    {
        CrLogW("message queue or semaphore not created\n");
        return -1;
    }
    
    int res = SEND_MESSAGE_PACKAGE(managerMsgId, data, len);
    if (res == -1)
    {
        CrLogW("send msg fail, %s\n", strerror(errno));
    }

    return res;
}

/**
 * @description: 发送消息到进程消息队列
 * @param  {*}
 * @return {*}
 * @param {uint8_t} *data
 */
static int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len)
{
    if (serverMsgId == -1)
    {
        CrLogW("message queue or semaphore not created\n");
        return -1;
    }
    
    int res = SEND_MESSAGE_PACKAGE(serverMsgId, data, len);
    if (res == -1)
    {
        CrLogW("send msg fail, %s\n", strerror(errno));
    }

    return res;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int UpgradeManagerExceptionHandleSemPost(void)
{
    return 0;
}
