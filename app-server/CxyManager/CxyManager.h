/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-05-06 22:16:45
 * @LastEditTime: 2023-10-16 11:33:22
 */

#ifndef __CXY_MANAGER_H__
#define __CXY_MANAGER_H__

#include "CxyMqttServer.h"
#include "CxyDownload.h"
#include "CxyUpload.hh"
#include "Upgrade/UpgradeManager.hh"


#define CMP_INT(a, b)       (a != b)
#define CMP_STR(a, b)       (strcmp(a, b))

#define CPY_INT(a, b)       a = b
#define CPY_STR(a, b)       strcpy(a, b)

#define BUILD_JS_ITEM(cmp, _x_, json, jsoname, add, cpy, change, forcibly)          \
    do{                                                                             \
        if (forcibly || cmp(m_lastPrintState._x_, m_appPrintState._x_)) {           \
            json_object_object_add(json, #jsoname, add(m_appPrintState._x_));       \
            cpy(m_lastPrintState._x_, m_appPrintState._x_);                         \
            change = true;                                             \
        }                                                                           \
    }while(0)

#define BUILD_JS_COMBIN_ITEM(cmp, _x_, json, jsoname, add, cpy, change, forcibly, _y_, jsonname, type)          \
    do{                                                                             \
        if (forcibly || cmp(m_lastPrintState._x_, m_appPrintState._x_)) {           \
            json_object_object_add(json, #jsoname, add(m_appPrintState._x_));       \
            json_object_object_add(json, #jsonname, type(m_appPrintState._y_));       \
            cpy(m_lastPrintState._x_, m_appPrintState._x_);                         \
            change = true;                                             \
        }                                                                           \
    }while(0)

typedef struct {
    int serialPort; // 串口连接成功标志
    int sdCardExists; // SD卡连接标志
    int udiskMount; // U盘挂载状态
    int ethernetExists; // 以太网状态
    int cameraOnline; // 摄像头状态
    int laserExists; // 激光模组状态
    char sys_version[32]; // 软件包版本
    char fw_version[32]; // 固件版本
    char hw_version[32]; // 硬件版本
    char hw1_version[32]; // 下位机硬件版本
    char modelVersion[256]; // 组件版本
    int model; // 机器型号
    char model_str[33]; // 机器型号
    int deviceState; // 设备状态
    int workMode; // 工作模式
    int workState; // 工作状态
    int modelFan; // 模型风扇
    int caseFan; // 机箱风扇
    int auxiliaryFan; // 辅助风扇
    int motorState; // 电机状态
    int lightState; // 灯光状态
    int wifiState; // wifi状态
    int materialStatus; // 断料状态
    int printSpeed; // 打印速度
    int printFlow; // 打印流量
    int printProgress; // 打印进度
    uint32_t printLayer; // 打印层数
    uint32_t printLayers; // 打印总层数
    uint32_t startPrintTime; // 开始打印时间
    int curHotendTemp; // 当前喷嘴温度
    int curBedTemp; // 当前热床温度
    int curBoxTemp; // 当前腔体温度
    int targetHotendTemp; // 喷嘴目标温度
    int targetBedTemp; // 热床目标温度
    uint8_t powerLoss; // 断电续打开关
    uint8_t materialDetect; // 断料检测
    uint32_t printTotalTime; // 打印使用时间
    uint32_t printUsageTime; // 打印使用时间
    uint32_t printRemainTime; // 打印剩余时间
    uint32_t filamentUsed; // 打印使用耗材
    int crTouchState; // 调平模块状态 
    FaultCode_t faultCode; // 错误码 
    int existOffContinue; // 是否存在断电续打 
    int autoLevelProgress; // 自动调平进度
    int autoPidProgress; // 自动PID进度
    int downloadProgress; // 文件下载进度
    int upgradeState; // 升级状态
    char printId[256]; // 打印任务id
    char appToken[256]; // app token
    char appJwtToken[256]; // app jwtToken
    int printSource; // 启动打印的交互方式（UI、APP、...）
    Coordinate_t livePosition; // 喷嘴当前位置
    Coordinate_t gcodePosition; // 喷嘴目标位置
    Coordinate_t homedAxes; // 轴归位状态
    char sdPath[256]; // 虚拟SD卡路径
    char uDiskPath[256]; // U盘路径
    int klipperStata; // klipper状态
    int deploy_setting;//部署设置
    int videoElapseState; // 延时摄影状态
    int nozzleMoveSnapshotState; //延时摄影移开喷嘴设置状态
    Coordinate_t axisRecoup; //轴补偿值
    int modleCamera; //模型摄像头
    int nozzleCamera; //喷嘴摄像头
    int aiSw; //ai检测开关
    int aiDetection; //ai故障检测
    int aiPausePrint; //ai故障暂停打印
    int aiFirstFloor; //ai首层检测
    char curPosition[32];
    char autohome[16];
    char zOffset[16];
    int chatteringOpt; //谐振补偿
    int withSelfTest; //打印前自检步骤
    int selfTestStep; //打印前自检步骤（详细步骤）
    int enableSelfTest; //打印前自检开关
    int feedState; //进退料状态
    int feedStateTemp2; //进退料温度
    int speedMode; // 打印速度模式
    uint32_t consumables; // 预计打印使用耗材
    int aiNoticeFlag;
    char printFileName[256]; //打印文件名称
    int modelFanPct; // 模型风扇百分比
    int caseFanPct; // 机箱风扇百分比
    int auxiliaryFanPct; // 辅助风扇百分比
    char wifi_ip[32]; // 无线ip
    char lan_ip[32]; // 有线ip
    int agreePrivacy; // 同意隐私协议
    int allPrintTime; //累计打印时间
}AppPrintState_t;

typedef enum {
    APP_UPGRADE_STATE_IDLE = 0,
    APP_UPGRADE_DOWNLOAD_ING = 1,
    APP_UPGRADE_INSTALL_ING = 2,
    APP_UPGRADE_INSTALL_FAIL = 3,
    APP_UPGRADE_INSTALL_OK = 4,
}AppUpgradeState_t;

class CxyManager
{
    public:
        CxyManager();
        ~CxyManager();

        int CxyInit(void);
        void Start(void);
        int GetMqttConState(void);
        int ReportGcodeFileInfo(int index, int type);
        int ReportVideoFilesInfo(int pageid=0);
        int ReportRecFilesInfo(int pageid=0);
        int ReportRecDetail(std::string prindId,int pageid);
        int ReportAppControlPrint(int result);
        AppPrintState_t *GetAppPrintState(void);
        int DelectAppPrintState(bool flag);
        int AppUploadDelayImage(std::string path,std::string printid);
        int AppUploadLocalDelayImage(std::string path);
        int AppUploadLog();
        int AppUploadLocalLog();
        int AppStopUploadLog();
        int AppSyncUpgradeState(UpgradeState_t state, int progress, UpgradeTarget_t target);
        int UpgradeStateResponse(UpgradeState_t state, int progress, UpgradeTarget_t target);
        int ReportTotalTime();
        int ReportAllPrintTime();
        //std::string GetUploadLogId();
        bool RequestOwnerInfo(char *token);
        bool RequestReportAiNotice(char *token, char *printId);
        bool RequestLocalPrint(char *token, char *workId, char *fileName, char *model , std::string *info);
        void UserUpdateUserInfo(void);
        int ProcVideoAddPrintid(std::string file);
        int ControlVideoFilesResult(int ret);
        int SyncMqttConnectState(int state);
        
    private:
        int DelectPrintTelemetryState(std::string &result, bool flag);
        int DelectPrintAttributesState(std::string &result, bool flag);
        int AttributesTelemetryStateInit(void);

        int32_t AppParseSetProperty(json_object *req);
        int32_t AppParseGetProperty(json_object *req);

        int DownloadProgressCallback(int progress);
        bool EndsWith(std::string &str, std::string const &suffix);
        int DownloadStateCallback(int state, std::string fileName);
        int UploadStateCallback(int state,CxyUpload *upload,int progress);
        int UploadLocalStateCallback(int state,CxyUpload *upload,int progress);
        int UploadLogStateCallback(int state,CxyUpload *upload,int progress);
        int UploadLocalLogStateCallback(int state,CxyUpload *upload,int progress);
        int AppParseMethod(std::string request);
        int ConStateCallback(int state);

        int CreateDeviceBindingQrcode(void);
        int CreateUserServiceQrcode(void);
        void GetPrintIdFromFile(void);

        bool OwnerInfoInfoAnl(std::string info);
        bool ReportAiNoticeAnl(std::string info);
        bool LocalPrintAnl(std::string info);
        int DownloadUserAvatar(std::string url, std::string path);

        int ProcVideoUpload(std::string prindId,std::string file,std::string token);
        int ProcVideoRemove(std::string prindId,std::string file);
        int ProcVideoRename(std::string prindId,std::string file,std::string targetname);
        int ProcVideoUploadState(std::string file,std::string videoid);
        std::string GetPrintidByFilePath(std::string file);
        char *getnameformpath(const char *path){
            if(path == nullptr)
                return "";
            char *video = strrchr(const_cast<char*>(path), '/');
            if (video) 
                return video + 1;
            else
                return "";
        }
        int SyncUploadLogState(int state, int progress);
        
    private:
        CxyMqttServer       m_mqttServerClient;
        CxyDownload         *m_downloadGcodeClient;
        //CxyUpload           *m_delayImageUpload;
        //CxyUpload           *m_logUpload;
        UpgradeManager      m_startOtaUpgrade;
        AppPrintState_t     m_appPrintState;
        AppPrintState_t     m_lastPrintState;
        int                 m_heartBeatCount;
        int                 m_mqttConState;
        std::string         m_fileInfoPath;
        CxyHttpServer       m_cxyHttpServer;
        static const int countperpage = 10; 
};

#endif
