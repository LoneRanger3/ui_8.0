/*
 * @Description : ServerMessage.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:15
 * @LastEditTime: 2023-07-27 20:38:15
 */
#ifndef __SERVER_MESSAGE_H__
#define __SERVER_MESSAGE_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#include "Base/DisplayMsgBase.h"

/*
flag是一个十六进制数，最多可以表示256个类型，对于目前来说足够
0x01：获取打印机的Gcode文件名称和目录，需要带参数
0x02：获取打印机的Z轴偏移数据
0x03：获取当前喷嘴和热床温度
0x04：获取当前XYZ位置
0x05：获取PLA、ABS预热的温度参数
0x06：获取参数类状态
0x07：获取当前WIFI及网络状态
0x08：
0x09：获取自动调平数据
0x0a：获取运动参数，包括：传动比参数、最大加速度参数、最大拐角参数、最大速度参数
0x0b：获取打印机的XYZ轴原点偏移数据
0x0c：
0x0d：获取喷头和热床自动PID参数
0x0e：获取温度PID参数，包括喷嘴和热床的PID参数
0x0f：获取打印状态
0x10：
0x11：获取当前语言
0x12：获取热床大小参数
0x13：获取重复打印次数
0x14：获取关于本机页面的所有参数
0x15：获取创想云绑定的二维码
*/
typedef enum {
    UI_GET_DEV_GCODE_FILE_PATH = 0x01,
    UI_GET_DEV_AXIS_RECOUP_DATA = 0x02,
    UI_GET_CUR_HOTEND_BED_TEMP = 0x03,
    UI_GET_CUR_NOZZLE_XYZ_LOCAL = 0x04,
    UI_GET_PLA_ABS_WARM_UP_TEMP = 0x05,
    UI_GET_DEVICE_CONFIG_STATE = 0x06,
    UI_GET_CURRENT_WIFI_INFO = 0x07,
    UI_GET_CURRENT_FILAMENT = 0x08,
    UI_GET_AUTO_LEVELING_DATA = 0x09,
    UI_GET_DEV_SPORTS_PARAMETER = 0x0a,
    UI_GET_ORGIN_OFFSET_DATA = 0x0b,

    UI_GET_AUTO_PID_PARA = 0x0d,
    UI_GET_TEMP_PID_PARA = 0x0e,
    UI_GET_CURRENT_PRINT_STATE = 0x0f,
    UI_GET_PRINT_DOUBLE_SPEED = 0x10,
    UI_GET_CURRENT_LANGUAGE = 0x11,
    UI_GET_HOT_BED_SIZE = 0x12,
    UI_GET_REPEAT_PRINT_TIMES = 0x13,
    UI_GET_DEVICE_ALL_INFO = 0x14,
    UI_GET_CXY_BINDING_QRCODE = 0x15,
    UI_GET_PRINT_FLOW_PARA = 0x16,
    UI_GET_HOME_AXES_STATE = 0x17,
    UI_GET_DEVICE_ERROR_INFO = 0x18,
    UI_GET_DEVICE_UPGRADE_INFO = 0x1a,
    UI_GET_DEVICE_STATE_PUSH = 0x1b,

    UI_GET_CAMERA_PARAMETERS = 0x1d,
    UI_GET_POWER_LOSS_PARA = 0x1e,
    UI_GET_AI_CONTROL_PARA = 0x1f,
    UI_GET_XYZ_AXIS_RANGE = 0x21,
    UI_GET_CMD_MAX,
}UiGetCmd_t;

/*
flag是一个十六进制数，最多可以表示256个类型，对于目前来说足够
0x01：开始打印指定的文件
0x02：设置Z轴偏移数据
0x03：设置喷嘴和热床最高温度
0x04：移动XYZ轴，包括移动方向和距离
0x05：设置预热参数，包括PLA、ABS的喷嘴和热床参数
0x06：设置参数类状态
0x07：wifi操作
0x08：进料和退料操作
0x09：设置调平操作参数
0x0a：设置运动参数
0x0b：设置XYZ轴原点偏移数据
0x0c：开始预热：包括PLA预热和ABS预热
0x0d：设置喷头和热床自动PID参数
0x0e：设置温度PID参数
0x0f：打印控制，包括：停止打印，暂停打印，继续打印
0x10：设置打印速度倍数
0x11：设置当前语言
0x12：设置热床大小数据
0x13：设置重复打印的次数
*/
typedef enum {
    UI_SET_START_PRINT_FILE = 0x01,
    UI_SET_DEV_AXIS_RECOUP_DATA = 0x02,
    UI_SET_HEATING_TARGET_TEMP = 0x03,
    UI_SET_CONTROL_AXIS_MOVE = 0x04,
    UI_SET_WARM_UP_TEMP_PARA = 0x05,
    UI_SET_DEVICE_CONFIG_STATE = 0x06,
    UI_SET_WIFI_OPERATE = 0x07,
    UI_SET_IN_AND_OUT_MATERIAL = 0x08,
    UI_SET_LEVELING_CONTROL = 0x09,
    UI_SET_DEV_SPORTS_PARAMETER = 0x0a,
    UI_SET_ORGIN_OFFSET_DATA = 0x0b,
    UI_SET_START_WARM_UP_TEMP = 0x0c,
    UI_SET_AUTO_PID_PARA = 0x0d,
    UI_SET_TEMP_PID_PARA = 0x0e,
    UI_SET_PRINT_CONTROL = 0x0f,
    UI_SET_PRINT_DOUBLE_SPEED = 0x10,
    UI_SET_SYSTEM_LANGUAGE = 0x11,
    UI_SET_HOT_BED_SIZE = 0x12,
    UI_SET_REPEAT_PRINT_TIMES = 0x13,

    UI_SET_PRINT_FLOW_PARA = 0x16,
    UI_SET_RESTART_ERRORCODE = 0x18,
    UI_SET_RESTART_KLIPPER = 0x19,
    UI_SET_START_DEVICE_UPGRADE = 0x1a,
    UI_SET_DEVICE_STATE_PUSH = 0x1b,
    UI_SET_USER_EXPORT_LOG = 0x1c,
    UI_SET_CAMERA_PARAMETERS = 0x1d,
    UI_SET_POWER_LOSS_PARA = 0x1e,
    UI_SET_AI_CONTROL_PARA = 0x1f,
    UI_SET_KLIPPER_CONSOLE_CMD = 0x20,
    UI_SET_CMD_MAX,
}UiSetCmd_t;

typedef enum {
    FACTORY_TEST_START,
    FACTORY_TEST_STOP,
    MACHINE_TEST_START,
    MACHINE_TEST_STOP,
}FactoryTest_t;

typedef enum {
    COLLECTION_AI_CAMERA_IMAGE,
    COLLECTION_AI_POINT_CLOUD,
} DataCollectionType_t;

typedef struct {
    uint32_t id;            // 打印任务ID
    char fileName[256];     // 打印文件名称
    int32_t size;           // 文件大小
    int32_t cTime;          // 创建时间
    uint32_t startTime;     // 打印开始时间
    uint32_t totalTime;     // 预计使用时间
    uint32_t consumables;   // 预计耗材
    int startWay;           // 启动打印方式（UI、APP、...）
    char thumbnail[256];    // 缩略图路径
    char photo[256];        // 注水图路径
    uint32_t startPixel;    // 注水图起始像素点
    uint32_t endPixel;      // 注水图结束像素点
    uint32_t modelHeight;   // 注水图模型高度
    uint32_t layerHeight;   // 注水图模型层高
    char software[256];     // 切片软件名称
}PrintWorkInfo_t;

typedef struct FirmwareInfo {
    bool isForce;
    char version[32];
    char name[256];
    uint32_t size;
    char url[2048];
    char path[256];
}FirmwareInfo_t;

typedef struct ActionGcodeFile
{
    char filePath[256]; //文件拷贝、删除时存储起目录
    bool isUdiskFile;
    uint16_t gcodeIndex;
}ActionGcodeFile_t;
ActionGcodeFile_t ActionGcodes; 

void ui_pthread_mutex_lock(void);
void ui_pthread_mutex_unlock(void);
PrintState_t GetPrintRunState(void);

int *ServerMessageInit(void *arg);
void SyncUiInitFinish(void);
int ExceptionHandleSemPost(void);
int SendMsgBuff(MsgHeadBuf_t *data, size_t len);
int SendProcessMsgBuff(MsgHeadBuf_t *data, size_t len);

int GetPrinterDataFromManager(unsigned char flag, unsigned char dataLen, char *data);
int SetPrinterDataToManager(unsigned char flag, unsigned char dataLen, char *data);

int SetPrinterRefreshToManager(unsigned char flag);
int SetPrinterBuzzerToManager(unsigned char flag);

void DisStartLaserTest(int step);
void DisFactoryTestControl(FactoryTest_t control);
void DisSaveDataCollection(DataCollectionType_t type);
// 获取配置
SystemConfig_t GetSystemConfig(void);
int DelayGetSystemConfig(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif