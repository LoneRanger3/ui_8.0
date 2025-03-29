/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-09-02 13:46:05
 * @LastEditTime: 2023-03-21 15:28:40
 */

#ifndef __UPGRADE_MANAGER_H_H__
#define __UPGRADE_MANAGER_H_H__

#include <vector>
#include "CxyManager/CxyHttpServer.h"
// 枚举备注: 1: 盒子固件 2：打印机固件 3：迪文屏固件 4：IPC摄像头固件 5：树莓派固件 6：光固化软件（HALOT BOX） 7：FDM软件(Creality Print) 8：Creality Slicer 9：大型机切片软件 10：广告字切片软件 11：CR Studio 12：开源插件-Cura 13：开源插件-Octoprint 14：树莓派 BOX 15：树莓派 Octoprint 16：雕刻机固件

#define     LINUX_OTA           2
#define     MCU_OTA             2

typedef enum {
    UPGRADE_TARGET_LINUX,
    UPGRADE_TARGET_MCU1,
}UpgradeTarget_t;

typedef struct DevSysInfo {
    std::string  model;
    std::string  sysVersion;
    std::string  hwVersion;
    std::string  mcuSysVersion;
    std::string  mcuHwVersion;
    int          deploySetting;
    std::function<int(UpgradeState_t, int, UpgradeTarget_t)> updataInfoCb;
}DevSysInfo_t;

typedef struct NewImageInfo {
    bool isForce;
    std::string version;
    std::string name;
    uint32_t size;
    std::string manual;
    std::string url;
}NewImageInfo_t;

class UpgradeManager
{
    public:
        UpgradeManager(/* args */);
        ~UpgradeManager();

        void UpdataVerionOptions(DevSysInfo_t info);
        bool CheckForUpgrade(NewImageInfo_t *info, UpgradeTarget_t target);
        int UserStartUpgrade(NewImageInfo_t info, UpgradeTarget_t target);
        int UserCancelUpgrade(void);

    private:
        bool CompareVersionInfo(json_object* jsonObj, char *oldVersion, NewImageInfo_t *info);
        std::vector<std::string> splitString(std::string input, std::string split);
        int VersionStringToInt(std::string delectStr, int *buf);
        int CompareVersion(std::string curVersion, std::string newVersion);

        int FirmwareDownloadStateCb(int state, std::string fileName);
        int FirmwareDownloadProgressCb(int progress);

    private:
        CxyDownload             *m_firmwareDownload;
        UpgradeTarget_t         m_UpgradeTarget;
        DevSysInfo_t            m_deviceVersion;
        std::thread             m_upgradeThread;
        std::string             m_upgradeImagePath;
		CxyHttpServer           m_cxyHttpServer;
};

#endif