/*
 * @Description : SysConfig.h
 * @Author      : Yufeng Zhang
 * @Date: 2022-01-06 11:23:40
 * @LastEditTime: 2023-11-02 21:13:56
 */
#ifndef __SYS_CONFIG_H__
#define __SYS_CONFIG_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

/**
 * @description: 定义不同机型，当前版本可降版本的最低限制
 * @param  {*}
 * @return {*}
 */
#define FALLBACK_MIN_VERSION_K1             "1.3.1.19"
#define FALLBACK_MIN_VERSION_K1_MAX         "1.3.1.19"
#define FALLBACK_MIN_VERSION_PF_05          "1.0.0.1"

/**
 * @description: 导出日志解压密码
 * @return {*}
 */
#define LOG_DECOMPRESSION_PASSWORD      "q!ew5rN7@U2s7;L"

/**
 * @description: AES128加密密码
 * @return {*}
 */
#define AES128_PASSWORD     "hEPPNBcEBm5Crc4Vgjm5AGn5g8mWkWjDvX38RMyZ7wbCxu3XuyT5kDMa72v5BBFRa"
#define AES128_IV           "rk7tbGWMEkxyz6GmV9y4qG3FjEt6CxChz"

/**
 * @description: 应用程序版本定义
 * @param  {*}
 * @return {*}
 */
#define INTERNAL_DEVELOP_VERSION        01   // 内部开发版本

/**
 * @description: 定义错误码
 * @return {*}
 */
typedef enum{
    FAULT_CODE_IDLE,
    // 100~499：上位机系统错误码，影响打印
    FAULT_COPY_GCODE_FILE_FROM_UDISK = 100,
    FAULT_AI_DETECT_PASTA_PRINT_PAUSE = 101,
    FAULT_GCODE_FILE_NAME_TO_LONG = 102,
    FAULT_FIRST_LAYER_EXCEPTION_PAUSE = 103,
    FAULT_AI_DETECT_FOREIGN_BODY_PAUSE = 104,
    FAULT_AI_LASER_NO_EXISTS_PAUSE = 105,
    FAULT_AI_LASER_CALIBRATION_PAUSE = 106,
    FAULT_AI_FLOW_EXCEPTION_PAUSE = 107,
    FAULT_AI_LASER_OFFSET_CORRECT_PAUSE = 108,
    FAULT_THROAT_FAN_ABNORMAL_PAUSE = 109,
    FAULT_MCU0_HARDWARE_EXCEPTION = 110,
    FAULT_NOZ0_HARDWARE_EXCEPTION = 111,
    FAULT_BED0_HARDWARE_EXCEPTION = 112,
    FAULT_NOT_ENOUGH_STORAGE_ERROR = 113,
    
    // 500~999：上位机系统错误码，仅提示
    FAULT_AI_DETECT_DISCOVER_PASTA = 500,
    FAULT_THROAT_FAN_RUNING_ABNORMAL = 501,
    FAULT_MOTHERBOARD_FAN_RUNING_ABNORMAL = 502,
    FAULT_FIRST_LAYER_EXCEPTION = 503,
    FAULT_AI_FLOW_EXCEPTION_FAIL = 504,
    FAULT_AI_LASER_NO_EXISTS = 505,
    FAULT_AI_LASER_CALIBRATION_FILA = 506,
    FAULT_AI_LASER_OFFSET_CORRECT_FAIL = 507,
    FAULT_NOT_ENOUGH_STORAGE_REMIND = 508,

    // 1000~1999：marlin错误码
    
    // 2000~2999：klipper主动上报错误码
    FAULT_KLIPPER_CODE_CONVERT = 2000,
    FAULT_KLIPPER_START_UP_STATE = 2003,
    FAULT_KLIPPER_RESCHEDULED_TIMER_IN_THE_PAST = 2093,
    FAULT_KLIPPER_OPEN_FILE_FAIL = 2121,
    FAULT_KLIPPER_UNABLE_UPGRADE_MCU_CONFIG = 2298,
    FAULT_KLIPPER_MCU0_CONNECT_TIMEOUT = 2343,
    FAULT_KLIPPER_NOZ0_CONNECT_TIMEOUT = 2344,
    FAULT_KLIPPER_BED0_CONNECT_TIMEOUT = 2345,

    // 3000~3999：应用检测klipper错误码
    FAULT_DETECT_KLIPPER_DISCONNECT = 3000,
    FAULT_DETECT_KLIPPER_WEB_HOOKS_SHUTDOWN = 3001,
    FAULT_DETECT_KLIPPER_WEB_HOOKS_ERROR = 3002,
    FAULT_DETECT_KLIPPER_CODE_SIZE,
}FaultCodeDef;

/**
 * @description: 系统指定网络环境部署
 * @return {*}
 */
typedef enum {
    SYS_OFFICIAL_SERVER = 1,    // 正式服务器
    SYS_PRE_RELEASE_SERVER,     // 预发布服务器
    SYS_TEST_SERVER,            // 测试服务器
    SYS_DEBUG_SERVER,           // 联调服务器
}SysServerAddr_t;

typedef enum {
    SYS_CN_SERVER = 1,      // 国内服务器
    SYS_COM_SERVER,         // 海外服务器
}SysServerLocal_t;

/**
 * @description: 网络环境部署
 * @return {*}
 */
typedef enum {
    CXY_SERVER_NULL,        // 无服务器
    CXY_CN_SERVER,          // 国内正式服务器
    CXY_COM_SERVER,         // 海外正式服务器
    CXY_CN_PRE_SERVER,      // 国内预发布服务器
    CXY_COM_PRE_SERVER,     // 海外预发布服务器
    CXY_TEST_SERVER,        // 测试服务器
    CXY_DEBUG_SERVER,       // 联调服务器
}CxyServerAddr_t;

/**
 * @description: linux系统配置
 * @return {*}
 */
typedef enum{
    CREALITY = 1001,
    CR_10_H1 = 1002,
    CR_K1 = 1003,
    CR_K1_Max = 1004,
    Nebula_Pad = 1005,
    CR_10_SE = 1006,
    K1C = 1007,
    K1_Max_SE = 1008,
    PF_05 = 2001,
}DeviceModel;

typedef enum{
    Customer_Creality,
}CustomerId;

typedef enum{
    Language_Chinese,
    Language_English,
    Language_German,
    Language_Spanish,
    Language_French,
    Language_Italian,
    Language_Portuguese,
    Language_Russian,
    Language_Turkish,
    Language_Japan,
}LanguageType;

typedef enum{
    UI_DIRECTION_NONE,
    UI_DIRECTION_90,
    UI_DIRECTION_180,
    UI_DIRECTION_270,
}UiDirection;

typedef enum{
    Z_DIRECTION_FORWARD,
    Z_DIRECTION_REVERSE,
}ZDirection;

typedef enum{
    AI_MODE_TYPE_ROUTINE = 1,
    AI_MODE_TYPE_MAJOR,
} AiModeType;

typedef enum {
    UPGRADE_PROCESS_IDLE,
    UPGRADE_DOWNLOAD_OK,
    UPGRADE_DOWNLOAD_ING,
    UPGRADE_DOWNLOAD_FAIL,
    UPGRADE_UNZIP_OK,
    UPGRADE_UNZIP_ING,
    UPGRADE_UNZIP_FAIL,
    UPGRADE_INSTALL_OK,
    UPGRADE_INSTALL_ING,
    UPGRADE_INSTALL_FAIL,
    UPGRADE_DOWNLOAD_CANCEL,
}UpgradeState_t;

typedef struct SystemConfig {
    char sys_version[32];   // 软件包版本
    int app_version;        // 应用版本
    char fw_version[32];    // 固件版本
    char hw_version[32];    // 硬件版本
    char hw1_version[32];   // 下位机硬件版本
    char website[256];      // 官方网址
    int model;              // 设备型号
    char model_str[32];     // 设备型号字符串
    int bed_length;         // 热床长度
    int bed_width;          // 热床宽度
    int bed_hight;          // 热床高度
    char device_sn[32];     // 设备SN
    char device_mac[32];    // 设备MAC
    int swap_way;           // 通信数据交换方式
    int32_t deploy_setting; // 部署设置
    int customer;           // 客户ID
    int language;           // 语言类型
    int sound_size;         // 音量大小
    int sound_sw;           // 音频开关
    int sounde_ffect;       // 音效设置
    int light_sw;           // 灯光开关
    int light_value;        // 灯光亮度
    int wifi_sw;            // wifi开关
    int theme_mode;         // 主题模式
    int self_test_sw;       // 开机自检开关
    int screensaver;        // 屏保开启时间
    int screen_value;       // 屏幕亮度值
    int ui_direction;       // 横竖屏方向
    int full_screen;        // 全屏模式
    int auto_power_off;     // 自动关机开关
    int z_direction;        // Z轴方向
    uint32_t total_time;    // 累计使用总时间
    int enableselftest;     // 打印前检测开关
    char time_zone[32];     // 时区设置
    int server_config;      // 服务器配置 {1：正式，2：预发布，3：测试，4：联调}
    int upgrade_remind;     // 升级提醒
    int server_local;       // 服务器位置 {1：国内，2：海外}
    int agree_privacy;      // 同意隐私协议
    int creality_num;       // 权限标志
    char host_name[64];     // 主机名称
    int data_collect;       // 用户数据采集
} SystemConfig_t;

/**
 * @description: 打印机保存参数
 * @return {*}
 */
typedef struct{
    int32_t p;
    int32_t i;
    int32_t d;
}pidPara_t;

typedef struct{
    int x;
    int y;
    int z;
    int e;
}Coordinate_t;

typedef struct{
    int size;
    int value[100];
}LevelValue_t;

typedef struct{
    int size;
    char value[200][64];
}GcodeMacro_t;

typedef struct{
    uint8_t powerLoss; // 断电续打开关
    uint8_t materialDetect; // 断料检测
    pidPara_t hotendPid; // 喷嘴温度PID
    pidPara_t bedPid; // 热床温度PID
    uint32_t nozzleHwMaxTemp; // 喷嘴硬件最大温度
    uint32_t bedHwMaxTemp; // 热床硬件最大温度
    LevelValue_t levelValue; // 自动调平值
    GcodeMacro_t gcodeMacro; // Gcode宏定义
    Coordinate_t homeOffset; // 原点偏移
    Coordinate_t axisRecoup; // 轴补偿值
    Coordinate_t stepValue; // 步进值
    Coordinate_t Acceleration; // 最大加速度
    Coordinate_t Speed; // 最大速度
    Coordinate_t Jerk; // 最大抖动速度
    Coordinate_t levelPoints; // 自动调平点数
    uint32_t k_Speed; // 高速最大速度
    uint32_t k_Acceleration; // 高速最大加速度
    uint32_t k_Corner; // 高速最大拐角速度
    uint32_t k_Jerk; // 高速最大加速到减速的加速度限制
    uint32_t pressureAdvance; // 高速压力推进
    uint32_t SmoothTime; // 高速平滑时间
    uint32_t fanFeedback; // 风扇反馈
    Coordinate_t devMaxSize; // 设备最大尺寸
    Coordinate_t devMinSize; // 设备最小尺寸
    char bedMeshInfo[1024]; // 热床调平信息
}PrintSavePara_t;

typedef enum {
	PAUSE_STATUS_IDLE = 0,
	PAUSE_STATUS_PAUSEING,
    PAUSE_STATUS_COOLING,
    PAUSE_STATUS_HEATING,
    PAUSE_STATUS_FINISH,
}PauseStatus_t; 

typedef enum {
	MATERIAL_STATUS_IDLE = 0,
	MATERIAL_STATUS_BLANKING,
    MATERIAL_STATUS_COOLING,
    MATERIAL_STATUS_HEATING,
}MaterialStatus_t; 

typedef enum {
	PRINT_SOURCE_NULL = 0,
	PRINT_SOURCE_DIS_MARLIN,
    PRINT_SOURCE_DIS_LINUX,
    PRINT_SOURCE_DIS_MARLIN_OFF_CONTINUE,
    PRINT_SOURCE_DIS_LINUX_OFF_CONTINUE,
    PRINT_SOURCE_APP_MARLIN,
    PRINT_SOURCE_APP_LINUX,
    PRINT_SOURCE_APP_MARLIN_OFF_CONTINUE,
    PRINT_SOURCE_APP_LINUX_OFF_CONTINUE,
    PRINT_SOURCE_APP_CLOUD,
    PRINT_SOURCE_APP_CLOUD_OFF_CONTINUE,
    PRINT_SOURCE_WEB_LINUX,
    PRINT_SOURCE_WEB_LINUX_OFF_CONTINUE,
    PRINT_SOURCE_FLUIDD_LINUX,
}PrintSource_t; 

typedef enum {
	KLIPPER_STATE_SHUTDOWN = 0,
	KLIPPER_STATE_STARTUP,
    KLIPPER_STATE_ERROR,
    KLIPPER_STATE_READY,
}KlipperState_t;

typedef enum {
	KLIPPER_PRINT_COMPLETE = 0,
	KLIPPER_PRINT_PRINTING,
    KLIPPER_PRINT_PAUSED,
    KLIPPER_PRINT_ERROR,
    KLIPPER_PRINT_CANCELLED,
    KLIPPER_PRINT_STANDBY,
}KlipperPrintState_t;

typedef enum {
    NOZZLE_TEMP,
	NOZZLE_0_TEMP,
	NOZZLE_1_TEMP,
    NOZZLE_TEMP_SIZE,
}NozzleTemp_t;

typedef enum {
    HOTBED_TEMP,
	HOTBED_0_TEMP,
	HOTBED_1_TEMP,
    HOTBED_2_TEMP,
    HOTBED_3_TEMP,
    HOTBED_TEMP_SIZE,
}HotbedTemp_t;

typedef enum {
    OTHER_TEMP_CAVITY,
    OTHER_TEMP_SIZE,
}OtherTemp_t;

typedef enum {
	MULTI_FAN_MODEL,
	MULTI_FAN_CASE,
    MULTI_FAN_AUXILIARY,
    MULTI_FAN_THROAT,
    MULTI_FAN_MOTHERBOARD,
    MULTI_FAN_SIZE,
}MultiFan_t;

typedef enum {
	UDISK_0,
	UDISK_1,
    UDISK_SIZE,
}Udisk_t;

typedef enum {
	CAMERA_MODEL,
	CAMERA_NOZZLE,
    CAMERA_SIZE,
}Camera_t;

typedef enum {
	MATERIAL_DETECTOR_1,
	MATERIAL_DETECTOR_2,
    MATERIAL_DETECTOR_SIZE,
}MaterialDetector_t;

typedef struct {         
    int code;           // 错误码
    int error;          // 交互提示 
    char msg[1024];     // 错误消息
    char value[1024];   // 错误参数
}FaultCode_t;

typedef struct {         
    int state;          // 升级成功 
    char oldVer[32];    // 旧版本号
} UpgradeRebootInfo_t;

typedef struct{
    int serialPort; // 串口连接成功标志
    int sdCardExists; // SD卡连接标志
    int udiskMount[UDISK_SIZE]; // U盘挂载状态
    int ethernetExists; // 以太网状态
    int cameraOnline[CAMERA_SIZE]; // 摄像头状态
    int laserExists; // 激光模组状态
    int scannerExists; // 扫码枪状态
    int deviceState; // 设备状态
    int workMode; // 工作模式
    int workState; // 工作状态
    int fanState[MULTI_FAN_SIZE]; // 风扇状态
    int fanSpeed[MULTI_FAN_SIZE]; // 风扇速度
    int fanPercentage[MULTI_FAN_SIZE]; // 风扇百分比
    int motorState; // 电机状态
    int lightState; // 灯光状态
    int wifiState; // wifi状态
    int pauseStatus; // 暂停状态
    int materialStatus[MATERIAL_DETECTOR_SIZE]; // 断料状态
    int printSpeed; // 打印速度
    int printFlow; // 打印流量
    int realTimeSpeed; // 打印实时速度
    int realTimeFlow; // 打印实时流量
    int printProgress; // 打印进度
    uint32_t printLayer; // 打印层数
    uint32_t printLayers; // 打印总层数
    int nozzleCurTemp[NOZZLE_TEMP_SIZE]; // 喷嘴当前温度
    int nozzleMaxTemp[NOZZLE_TEMP_SIZE]; // 喷嘴目标温度
    int nozzlePower[NOZZLE_TEMP_SIZE]; // 喷嘴加热功率
    int nozzleTempWait; // 喷嘴加热等待
    int bedCurTemp[HOTBED_TEMP_SIZE]; // 热床当前温度
    int bedMaxTemp[HOTBED_TEMP_SIZE]; // 热床目标温度
    int bedPower[HOTBED_TEMP_SIZE]; // 热床加热功率
    int bedTempWait; // 热床加热等待
    int otherCurTemp[OTHER_TEMP_SIZE]; // 其他当前温度
    uint32_t printUsageTime; // 打印使用时间
    uint32_t printRemainTime; // 打印剩余时间
    uint32_t filamentUsed; // 打印使用耗材
    int autoLevelProgress; // 自动调平进度
    int autoPidProgress; // 自动PID进度
    int crTouchState; // 调平模块状态
    FaultCode_t faultCode; // 错误码
    int existOffContinue; // 是否存在断电续打
    Coordinate_t livePosition; // 喷嘴当前位置
    Coordinate_t gcodePosition; // 喷嘴目标位置
    Coordinate_t homedAxes; // 轴归位状态
    int klipperStata; // klipper状态
    int klipperPrint; // klipper打印状态
    char sdPath[256]; // 虚拟SD卡路径
    char uDiskPath[256]; // U盘路径
    int qmodeFlag; // 静音模式
    int withSelfTest; // 打印前校准步骤
    int loadMaterial; // 进料状态
    int quitMaterial; // 退料状态
    int cxyMqttState; // 创想云MQTT状态
    int logProgress; // 日志导出、上传进度
    int scanFileProgress; // 扫描文件进度
}PrintState_t;

typedef enum {
    WIFI_CONNECT_FAIL,
    WIFI_CONNECT_SUCCESS,
    WIFI_CONNECT_ING,
	WIFI_CONNECT_WRONG_PASSWORD,
	WIFI_CONNECT_TIME_OUT,
    WIFI_CONNECT_NO_SSID,
}WifiConnectRes_t;

typedef enum{
    MQTT_THRUN_REGISTOR,
    MQTT_THRUN_GETTBINFO,
    MQTT_THRUN_CONNECT,
    MQTT_THRUN_SUB,
    MQTT_THRUN_OK,
    MQTT_THRUN_EXIT,
    MQTT_THRUN_NUM,
}MQTT_THRUN_STATE;

typedef enum {
    FILE_NAME_POSITIVE_SORT = 1,
    FILE_NAME_REVERSE_SORT,
    FILE_TIME_POSITIVE_SORT,
    FILE_TIME_REVERSE_SORT,
    FILE_MODE_POSITIVE_SORT,
    FILE_MODE_REVERSE_SORT,
    FILE_SIZE_POSITIVE_SORT,
    FILE_SIZE_REVERSE_SORT,
}GcodeFIleSort_t;

typedef enum {
    RESONANCE_TEST_FAIL,
    RESONANCE_TEST_SUCCESS,
    RESONANCE_TESTING,
}ResonanceTest_t;

typedef enum {
    AUTO_LEVELING_FAIL,
    AUTO_LEVELING_SUCCESS,
    AUTO_LEVELING,
} AutoLeveling_t;

typedef enum {
    CACHE_PATH_TYPE_FILE = 1,
    CACHE_PATH_TYPE_DIR,
} CacheFIleType_t;

typedef enum {
    PREPARE_STEP_NULL = 0,
    PREPARE_STEP_FOREIGN_BODY = 1,
    PREPARE_STEP_ROUGH_G28 = 2,
    PREPARE_STEP_NOZZLE_CLEAR = 3,
    PREPARE_STEP_ACCURATE_G28 = 4,
    PREPARE_STEP_LEVEL_DELECT = 5,
    PREPARE_STEP_LASER_CALIBRATION = 6,
    // 流量检测
    PREPARE_STEP_FLOW_SCAN_TABLE = 20,
    PREPARE_STEP_FLOW_PRINT_LINE = 21,
    PREPARE_STEP_FLOW_COOL_DOWN = 22,
    PREPARE_STEP_FLOW_SCAN_MODEL = 23,
    PREPARE_STEP_FLOW_AI_CALCULATE = 24,
    // 首层检测
    PREPARE_STEP_FLOOR_SCAN_TABLE = 30,
    PREPARE_STEP_FLOOR_PRINT_LINE = 31,
    PREPARE_STEP_FLOOR_COOL_DOWN = 32,
    PREPARE_STEP_FLOOR_SCAN_MODEL = 33,
    PREPARE_STEP_FLOOR_AI_CALCULATE = 34,
    PREPARE_STEP_FLOOR_HEAT_UP = 35,
    // 完成
    PREPARE_STEP_FINISH = 100,
} PrintPrepareStep_t;

typedef enum {
    FILE_DOWNLOAD_OK,
    FILE_DOWNLOAD_ING,
    FILE_DOWNLOAD_FAIL,
    FILE_DOWNLOAD_CANCEL,
}FileDownloadState_t;

typedef enum {
    EXPORTING_LOGS,
    EXPORT_LOG_SUCCESS,
    EXPORT_LOG_FAIL,
    EXPORT_LOG_UDISK_NO_EXIT,
    COMPRESSING_LOG,
    EXPORT_STOPLOG_SUCCESS,
}ExportLog_t;

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
