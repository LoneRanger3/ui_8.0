/*
 * @Description : 全局共享头文件
 * @Author      : Yufeng Zhang
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-04-28 15:53:58
 */
#ifndef __GLOBAL_MSG_H__
#define __GLOBAL_MSG_H__

#include <stdint.h>
#include <stddef.h>

#include "CrlogDef.h"
#include "json-c/json_object.h"
#include "json-c/json_tokener.h"
#include "json-c/json_util.h"
#include "json-c/linkhash.h"
#include "SysConfig.h"

#include "SystemProto/SystemServer.pb-c.h"
#include "Queue/qqueue.h"
#include "Base64/Base64.h"
#include "SystemCmd/SystemCmd.h"
#include "ConfigFile/FileManager.h"
#include "ConfigFile/CopyFile.h"
#include "ConfigFile/DiskInfo.h"

#ifdef  __cplusplus  
extern "C" {  
#endif

/**
 * @description: 位定义
 * @return {*}
 */
#define BIT0        (1 << 0)
#define BIT1        (1 << 1)
#define BIT2        (1 << 2)
#define BIT3        (1 << 3)
#define BIT4        (1 << 4)
#define BIT5        (1 << 5)
#define BIT6        (1 << 6)
#define BIT7        (1 << 7)

/**
 * @description: 消息数据源宏定义
 */
typedef enum {
    MSG_ORIGIN_WIFI_MANAGER         = 11,
    MSG_ORIGIN_AUDIO_MANAGER        = 12,
    MSG_ORIGIN_CAMERA_MANAGER       = 13,
    MSG_ORIGIN_BURN_MANAGER         = 14,
    MSG_ORIGIN_APP_MANAGER          = 15,
    MSG_ORIGIN_UPGRADE_MANAGER      = 16,
    MSG_ORIGIN_WEB_MANAGER          = 17,
    MSG_ORIGIN_DISPLAY_MANAGER      = 18,
    MSG_ORIGIN_APPOINTMENT          = 19,
    MSG_ORIGIN_CONTROLLER           = 20,
    MSG_ORIGIN_SYS_TRANSFER         = 21,
    MSG_ORIGIN_MASTER_BASE          = 22,

    MSG_ORIGIN_WIFI_SERVER          = 51,
    MSG_ORIGIN_AUDIO_SERVER         = 52,
    MSG_ORIGIN_CAMERA_SERVER        = 53,
    MSG_ORIGIN_BURN_SERVER          = 54,
    MSG_ORIGIN_UPGRADE_SERVER       = 55,
    MSG_ORIGIN_DISPLAY_SERVER       = 56,
    MSG_ORIGIN_APP_SERVER           = 57,
    MSG_ORIGIN_WEB_SERVER           = 58,
}MsgOrigin;

/**
 * @description: 信号量、共享内存键值定义
 */
#define PRINT_OBJECT_SHM_SIZE    (1024 * 1024)
#define PRINT_OBJECT_SEM_PATH    "/print_object_sem"
#define PRINT_OBJECT_SHM_FILE    "/print_object_shm"

/**
 * @description: 消息队列键值定义
 */
typedef enum {
    MSG_KEY_WIFI_MANAGER            = 17121511,
    MSG_KEY_AUDIO_MANAGER           = 17121512,
    MSG_KEY_CAMERA_MANAGER          = 17121513,
    MSG_KEY_BURN_MANAGER            = 17121514,
    MSG_KEY_APP_MANAGER             = 17121515,
    MSG_KEY_UPGRADE_MANAGER         = 17121516,
    MSG_KEY_WEB_MANAGER             = 17121517,
    MSG_KEY_DISPLAY_MANAGER         = 17121518,
    MSG_KEY_APPOINTMENT             = 17121519,
    MSG_KEY_CONTROLLER              = 17121520,
    MSG_KEY_SYS_TRANSFER            = 17121521,

    MSG_KEY_WIFI_SERVER             = 17121551,
    MSG_KEY_AUDIO_SERVER            = 17121552,
    MSG_KEY_CAMERA_SERVER           = 17121553,
    MSG_KEY_BURN_SERVER             = 17121554,
    MSG_KEY_UPGRADE_SERVER          = 17121555,
    MSG_KEY_DISPLAY_SERVER          = 17121556,
    MSG_KEY_APP_SERVER              = 17121557,
    MSG_KEY_WEB_SERVER              = 17121558,

    MSG_KEY_CMD_SYNC_RECV           = 18141290,
}MsgKey;

/**
 * @description: 消息命令字
 */
typedef enum {
    /**
     * @description: wifi服务指令
     * @param  {*}
     * @return {*}
     */    
    SERVER_CMD_WIFI_TEST_REQ = 100, // wifi服务进程通信测试请求
    SERVER_CMD_WIFI_TEST_ANS,       // wifi服务进程通信测试响应
    SERVER_CMD_WIFI_SCAN_NETWORK_LIST_REQ, // 获取热点列表请求
    SERVER_CMD_WIFI_SCAN_NETWORK_LIST_ANS, // 获取热点列表响应
    SERVER_CMD_WIFI_CONNECT_NETWORK_REQ, // 连接新热点请求
    SERVER_CMD_WIFI_CONNECT_NETWORK_ANS, // 连接新热点响应
    SERVER_CMD_WIFI_CONNECT_SAVE_NETWORK_REQ, // 连接已保存热点请求
    SERVER_CMD_WIFI_CONNECT_SAVE_NETWORK_ANS, // 连接已保存热点响应
    SERVER_CMD_WIFI_GET_DEVICE_WIFI_INFO_REQ, // 获取wifi状态信息请求
    SERVER_CMD_WIFI_GET_DEVICE_WIFI_INFO_ANS, // 获取wifi状态信息响应
    SERVER_CMD_WIFI_DISCONNECT_NETWORK_REQ, // 断开wifi请求
    SERVER_CMD_WIFI_DISCONNECT_NETWORK_ANS, // 断开wifi响应
    SERVER_CMD_WIFI_REMOVE_NETWORK_REQ, // 删除wifi请求
    SERVER_CMD_WIFI_REMOVE_NETWORK_ANS, // 删除wifi响应
    
    /**
     * @description: 显示服务指令
     * @param  {*}
     * @return {*}
     */    
    SERVER_CMD_DIS_BUTTON_SOUND = 200, // 显示按键提示音
    SERVER_CMD_DIS_SYNC_AUTO_LEVEL_RESULT, // 显示自动调平结果
    SERVER_CMD_DIS_SYNC_UPGRADE_STATE, // 显示同步升级状态

    SERVER_CMD_DIS_AUTO_PID_CONFIRM_REQ, // 自动PID结果确认请求
    SERVER_CMD_DIS_AUTO_PID_CONFIRM_ANS, // 自动PID结果确认应答

    SERVER_CMD_DIS_SYNC_FILE_COPY_PROGRESS, //显示同步文件拷贝进度
    SERVER_CMD_DIS_SYNC_EXPORT_LOG_STATE, //显示同步导出日志状态

    SERVER_CMD_DIS_TEST_REQ = 300, // 显示服务进程通信测试请求
    SERVER_CMD_DIS_TEST_ANS,       // 显示服务进程通信测试响应
    SERVER_CMD_DIS_GET_SYSTEM_CONFIG_REQ, // 显示获取系统配置请求
    SERVER_CMD_DIS_GET_SYSTEM_CONFIG_ANS, // 显示获取系统配置响应
    SERVER_CMD_DIS_GET_PRINT_SAVE_PARA_REQ, // 显示获取打印机保存参数请求
    SERVER_CMD_DIS_GET_PRINT_SAVE_PARA_ANS, // 显示获取打印机保存参数响应
    SERVER_CMD_DIS_GET_DEVICE_STATE_REQ, // 显示获取设备状态请求
    SERVER_CMD_DIS_GET_DEVICE_STATE_ANS, // 显示获取设备状态响应
    SERVER_CMD_DIS_GET_LOCAL_GCODE_REQ, // 显示获取本地gcode文件请求
    SERVER_CMD_DIS_GET_LOCAL_GCODE_ANS, // 显示获取本地gcode文件响应
    SERVER_CMD_DIS_GET_LOCAL_IMAGE_REQ, // 显示获取本地缩略图请求
    SERVER_CMD_DIS_GET_LOCAL_IMAGE_ANS, // 显示获取本地缩略图响应
    SERVER_CMD_DIS_GET_LOCAL_PHOTO_REQ, // 显示获取本地注水图请求
    SERVER_CMD_DIS_GET_LOCAL_PHOTO_ANS, // 显示获取本地注水图响应
    SERVER_CMD_DIS_GET_LOCALTION_REQ, // 显示获取位置请求
    SERVER_CMD_DIS_GET_LOCALTION_ANS, // 显示获取位置响应
    SERVER_CMD_DIS_GET_MATERIAL_PRE_REQ, // 显示获取材料偏好请求
    SERVER_CMD_DIS_GET_MATERIAL_PRE_ANS, // 显示获取材料偏好响应
    SERVER_CMD_DIS_GET_AUTO_PID_PRE_REQ, // 显示获取自动PID偏好请求
    SERVER_CMD_DIS_GET_AUTO_PID_PRE_ANS, // 显示获取自动PID偏好响应
    SERVER_CMD_DIS_GET_DELAY_IMAGE_PRE_REQ, // 显示获取延时摄影偏好请求
    SERVER_CMD_DIS_GET_DELAY_IMAGE_PRE_ANS, // 显示获取延时摄影偏好响应
    SERVER_CMD_DIS_GET_POWER_LOSS_PRE_REQ, // 显示获取断电续打偏好请求
    SERVER_CMD_DIS_GET_POWER_LOSS_PRE_ANS, // 显示获取断电续打偏好响应
    SERVER_CMD_DIS_GET_AI_CONTROL_PRE_REQ, // 显示获取AI偏好请求
    SERVER_CMD_DIS_GET_AI_CONTROL_PRE_ANS, // 显示获取AI偏好响应
    SERVER_CMD_DIS_GET_WIFI_INFO_REQ, // 显示获取wifi信息请求
    SERVER_CMD_DIS_GET_WIFI_INFO_ANS, // 显示获取wifi信息响应
    SERVER_CMD_DIS_GET_WIFI_SCAN_REQ, // 显示获取扫描wifi请求
    SERVER_CMD_DIS_GET_WIFI_SCAN_ANS, // 显示获取扫描wifi响应
    SERVER_CMD_DIS_GET_UPGRADE_INFO_REQ, // 显示升级信息请求
    SERVER_CMD_DIS_GET_UPGRADE_INFO_ANS, // 显示升级信息响应
    SERVER_CMD_DIS_GET_POWER_LOSS_RES, // 显示获取断电续打请求
    SERVER_CMD_DIS_GET_POWER_LOSS_ANS, // 显示获取断电续打响应
    SERVER_CMD_DIS_GET_PRINT_WORK_INFO_REQ, // 显示获取打印任务信息请求
    SERVER_CMD_DIS_GET_PRINT_WORK_INFO_ANS, // 显示获取打印任务信息响应
    SERVER_CMD_DIS_CONTROL_PRINT_REQ, // 显示控制打印机请求
    SERVER_CMD_DIS_CONTROL_PRINT_ANS, // 显示控制打印机响应
    SERVER_CMD_DIS_UPLOAD_LOCAL_LOG_REQ, // 显示上传本地日志请求
    SERVER_CMD_DIS_UPLOAD_LOCAL_LOG_ANS, // 显示上传本地日志响应
    SERVER_CMD_DIS_UPLOAD_LOCAL_VIDEO_REQ, // 显示上传本地视频请求
    SERVER_CMD_DIS_UPLOAD_LOCAL_VIDEO_ANS, // 显示上传本地视频响应
    SERVER_CMD_DIS_GET_USER_CXY_INFO_REQ, // 显示获取创想云信息请求
    SERVER_CMD_DIS_GET_USER_CXY_INFO_ANS, // 显示获取创想云信息响应
    SERVER_CMD_DIS_GET_GSENSOR_EXIST_RES, // 显示获取加速度传感器是否存在请求
    SERVER_CMD_DIS_GET_GSENSOR_EXIST_ANS, // 显示获取加速度传感器是否存在响应
    SERVER_CMD_DIS_GET_UPGRADE_REBOOT_RES, // 显示获取是否升级重启请求
    SERVER_CMD_DIS_GET_UPGRADE_REBOOT_ANS, // 显示获取是否升级重启响应
    SERVER_CMD_DIS_GET_PRINT_OBJECT_RES, // 显示获取打印对象请求
    SERVER_CMD_DIS_GET_PRINT_OBJECT_ANS, // 显示获取打印对象响应

    SERVER_CMD_DIS_SET_LASER_TEST_START_REQ, // 显示发送开始激光模组测试请求
    SERVER_CMD_DIS_SET_LASER_TEST_START_ANS, // 显示发送开始激光模组测试请求
    /**
     * @description: 打印服务指令
     * @param  {*}
     * @return {*}
     */    
    SERVER_CMD_PRINT_TEST_REQ = 500, // 打印服务进程通信测试请求
    SERVER_CMD_PRINT_TEST_ANS,       // 打印服务进程通信测试响应

    /**
     * @description: 音频服务指令
     * @param  {*}
     * @return {*}
     */    
    SERVER_CMD_AUDIO_TEST_REQ = 800, // 音频服务进程通信测试请求
    SERVER_CMD_AUDIO_TEST_ANS,       // 音频服务进程通信测试响应
    SERVER_CMD_AUDIO_FILE_PATH, // 发送音频播报文件路径

    /**
     * @description: 网络服务指令
     * @param  {*}
     * @return {*}
     */    
    SERVER_CMD_APP_SYNC_DEV_STATE = 1000,   // 网络同步打印机状态
    SERVER_CMD_APP_SYNC_UPGRADE_STATE,      // 网络同步升级状态
    SERVER_CMD_APP_UPLOAD_DELAY_IMAGE,      // 网络上传延时摄影视频
    SERVER_CMD_APP_SYNC_PRINT_WORK_INFO,    // 网络同步打印任务信息
    SERVER_CMD_APP_START_LOCAL_UPGRADE,     // 网络OTA下载完成，开始本地升级
    SERVER_CMD_APP_SYNC_MQTT_CONNECT,       // 网络同步MQTT连接状态
    SERVER_CMD_APP_SYNC_GCODE_DOWNLOAD,     // 网络同步gcode下载状态
    SERVER_CMD_APP_SYNC_EXPORT_LOG_STATE,   // 网络同步导出日志状态

    SERVER_CMD_APP_TEST_REQ = 1100,         // 网络服务进程通信测试请求
    SERVER_CMD_APP_TEST_ANS,                // 网络服务进程通信测试响应
    SERVER_CMD_APP_CONTROL_PRINT_REQ,       // 网络控制打印机请求
    SERVER_CMD_APP_CONTROL_PRINT_ANS,       // 网络控制打印机响应

    SERVER_CMD_APP_GET_SYSTEM_CONFIG_REQ, // 网络获取系统配置请求
    SERVER_CMD_APP_GET_SYSTEM_CONFIG_ANS, // 网络获取系统配置响应
    SERVER_CMD_APP_GET_PRINT_SAVE_PARA_REQ, // 网络获取打印机保存参数请求
    SERVER_CMD_APP_GET_PRINT_SAVE_PARA_ANS, // 网络获取打印机保存参数响应
    SERVER_CMD_APP_GET_DEVICE_STATE_REQ, // 网络获取设备状态请求
    SERVER_CMD_APP_GET_DEVICE_STATE_ANS, // 网络获取设备状态响应
    SERVER_CMD_APP_GET_GCODE_FILE_LIST_REQ, // 网络获取本地gcode文件请求
    SERVER_CMD_APP_GET_GCODE_FILE_LIST_ANS, // 网络获取本地gcode文件响应
    SERVER_CMD_APP_GET_CURRENT_LOCAL_REQ, // 网络获取当前位置请求
    SERVER_CMD_APP_GET_CURRENT_LOCAL_ANS, // 网络获取当前位置响应
    SERVER_CMD_APP_CHECK_UPGRADE_REQ, // 网络检查升级请求
    SERVER_CMD_APP_CHECK_UPGRADE_ANS, // 网络检查升级响应
    SERVER_CMD_APP_START_UPGRADE_REQ, // 网络开始升级请求
    SERVER_CMD_APP_START_UPGRADE_ANS, // 网络开始升级响应
    SERVER_CMD_APP_CANCEL_UPGRADE_REQ, // 网络取消升级请求
    SERVER_CMD_APP_CANCEL_UPGRADE_ANS, // 网络取消升级响应
    SERVER_CMD_APP_GET_DELAY_IMAGE_PRE_REQ, // 显示获取延时摄影偏好请求
    SERVER_CMD_APP_GET_DELAY_IMAGE_PRE_ANS, // 显示获取延时摄影偏好响应
    SERVER_CMD_APP_GET_POWER_LOSS_PRE_REQ, // 显示获取断电续打偏好请求
    SERVER_CMD_APP_GET_POWER_LOSS_PRE_ANS, // 显示获取断电续打偏好响应
    SERVER_CMD_APP_GET_AI_CONTROL_PRE_REQ, // 网络获取AI偏好请求
    SERVER_CMD_APP_GET_AI_CONTROL_PRE_ANS, // 网络获取AI偏好响应
    SERVER_CMD_APP_GET_UDISK_GCODE_FILE_LIST_REQ, // 网络获取U盘gcode文件请求
    SERVER_CMD_APP_GET_UDISK_GCODE_FILE_LIST_ANS, // 网络获取U盘gcode文件响应
    SERVER_CMD_APP_SYNC_AUTO_LEVEL_RESULT, // 显示自动调平结果
    SERVER_CMD_APP_SYNC_RESONANCE_RESULT, // 显示谐振补偿结果
    SERVER_CMD_APP_UPLOAD_LOCAL_LOG_REQ, // 本地上传日志请求
    SERVER_CMD_APP_UPLOAD_LOCAL_LOG_ANS, // 本地上传日志响应
    SERVER_CMD_APP_UPLOAD_LOCAL_VIDEO_REQ, //本地上传视频请求
    SERVER_CMD_APP_UPLOAD_LOCAL_VIDEO_ANS, //本地上传视频响应
    SERVER_CMD_APP_UPDATE_USER_INFO_REQ, //获取用户信息请求
    SERVER_CMD_APP_UPDATE_USER_INFO_ANS, //获取用户信息响应
    SERVER_CMD_APP_GET_WIFI_INFO_REQ, // 显示获取wifi信息请求
    SERVER_CMD_APP_GET_WIFI_INFO_ANS, // 显示获取wifi信息响应
    SERVER_CMD_APP_CONTROL_LOCAL_VIDEO, //本地视频修改
    SERVER_CMD_APP_CONTROL_LOCAL_VIDEO_RESULT, // 本地视频修改结果
    SERVER_CMD_APP_SYSTEM_RESET_REQ, // 网络恢复出厂设置请求
    SERVER_CMD_APP_SYSTEM_RESET_ANS, // 网络恢复出厂设置响应
    SERVER_CMD_APP_GET_PRINT_OBJECT_RES, // 网络获取打印对象请求
    SERVER_CMD_APP_GET_PRINT_OBJECT_ANS, // 网络获取打印对象响应

    /**
     * @description: 烧录服务指令
     * @param  {*}
     * @return {*}
     */    
    SERVER_CMD_BURN_TEST_REQ = 1500, // 烧录服务进程通信测试请求
    SERVER_CMD_BURN_TEST_ANS,        // 烧录服务进程通信测试响应

    /**
     * @description: 升级服务指令
     * @param  {*}
     * @return {*}
     */    
    SERVER_CMD_UPGRADE_TEST_REQ = 1600, // 升级服务进程通信测试请求
    SERVER_CMD_UPGRADE_TEST_ANS,        // 升级服务进程通信测试响应
    SERVER_CMD_START_UPGRADE_REQ,       // 开始升级请求
    SERVER_CMD_START_UPGRADE_ANS,       // 开始升级响应
    SERVER_CMD_UPGRADE_SYSTEM_CONFIG_REQ, // 升级获取系统配置请求
    SERVER_CMD_UPGRADE_SYSTEM_CONFIG_ANS, // 升级获取系统配置响应

    /**
     * @description: WEB服务指令
     * @param  {*}
     * @return {*}
     */    
    SERVER_CMD_WEB_SYNC_DEV_STATE = 1700,   // WEB同步打印机状态
    SERVER_CMD_WEB_SYNC_UPGRADE_STATE,      // WEB同步升级状态
    SERVER_CMD_WEB_UPLOAD_DELAY_IMAGE,      // WEB上传延时摄影视频
    SERVER_CMD_WEB_SYNC_PRINT_WORK_INFO,    // WEB同步打印任务信息
    SERVER_CMD_WEB_SYNC_EXPORT_LOG_STATE,   // WEB同步导出日志状态

    SERVER_CMD_WEB_TEST_REQ = 1800,         // WEB服务进程通信测试请求
    SERVER_CMD_WEB_TEST_ANS,                // WEB服务进程通信测试响应
    SERVER_CMD_WEB_CONTROL_PRINT_REQ,       // WEB控制打印机请求
    SERVER_CMD_WEB_CONTROL_PRINT_ANS,       // WEB控制打印机响应

    SERVER_CMD_WEB_GET_SYSTEM_CONFIG_REQ,   // WEB获取系统配置请求
    SERVER_CMD_WEB_GET_SYSTEM_CONFIG_ANS,   // WEB获取系统配置响应
    SERVER_CMD_WEB_GET_PRINT_SAVE_PARA_REQ, // WEB获取打印机保存参数请求
    SERVER_CMD_WEB_GET_PRINT_SAVE_PARA_ANS, // WEB获取打印机保存参数响应
    SERVER_CMD_WEB_GET_GCODE_FILE_LIST_REQ, // WEB获取本地gcode文件请求
    SERVER_CMD_WEB_GET_GCODE_FILE_LIST_ANS, // WEB获取本地gcode文件响应
    SERVER_CMD_WEB_GET_CURRENT_LOCAL_REQ,   // WEB获取当前位置请求
    SERVER_CMD_WEB_GET_CURRENT_LOCAL_ANS,   // WEB获取当前位置响应
    SERVER_CMD_WEB_CHECK_UPGRADE_REQ,       // WEB检查升级请求
    SERVER_CMD_WEB_CHECK_UPGRADE_ANS,       // WEB检查升级响应
    SERVER_CMD_WEB_START_UPGRADE_REQ,       // WEB开始升级请求
    SERVER_CMD_WEB_START_UPGRADE_ANS,       // WEB开始升级响应
    SERVER_CMD_WEB_SYSTEM_RESET_REQ,        // WEB恢复出厂设置请求
    SERVER_CMD_WEB_SYSTEM_RESET_ANS,        // WEB恢复出厂设置响应
    SERVER_CMD_WEB_GET_DEVICE_STATE_REQ,    // WEB获取设备状态请求
    SERVER_CMD_WEB_GET_DEVICE_STATE_ANS,    // WEB获取设备状态响应    
    SERVER_CMD_WEB_MULTIPLE_BEDTEMP_REQ,    // WEB热床控制请求
    //SERVER_CMD_WEB_MULTIPLE_BEDTEMP_ANS,    // WEB热床控制响应
    SERVER_CMD_WEB_GET_DELAY_IMAGE_PRE_REQ, // WEB获取延时摄影偏好请求
    SERVER_CMD_WEB_GET_DELAY_IMAGE_PRE_ANS, // WEB获取延时摄影偏好响应
    SERVER_CMD_WEB_GET_AUTO_PID_PRE_REQ, // WEB获取自动PID偏好请求
    SERVER_CMD_WEB_GET_AUTO_PID_PRE_ANS, // WEB获取自动PID偏好响应
    SERVER_CMD_WEB_SYNC_AUTO_LEVEL_RESULT, // 显示自动调平结果
    SERVER_CMD_WEB_GET_POWER_LOSS_PRE_REQ, // 显示获取断电续打偏好请求
    SERVER_CMD_WEB_GET_POWER_LOSS_PRE_ANS, // 显示获取断电续打偏好响应
    SERVER_CMD_WEB_GET_GCODE_FILE_IMAGE_REQ,
    SERVER_CMD_WEB_GET_GCODE_FILE_IMAGE_ANS,
    SERVER_CMD_WEB_GET_AI_CONTROL_PRE_REQ, // WEB获取AI偏好请求
    SERVER_CMD_WEB_GET_AI_CONTROL_PRE_ANS, // WEB获取AI偏好响应
    SERVER_CMD_WEB_GET_PRINT_OBJECT_RES, // WEB获取打印对象请求
    SERVER_CMD_WEB_GET_PRINT_OBJECT_ANS, // WEB获取打印对象响应
    SERVER_CMD_WEB_CONTROL_LOCAL_VIDEO, //本地视频修改
    SERVER_CMD_WEB_CONTROL_LOCAL_VIDEO_RESULT, // 本地视频修改结果

    /**
     * @description: 进程间通信命令最大值
     * @return {*}
     */    
    SYSTEM_SERVER_CMD_MAX = 4096 // 进程间通信命令最大值
}GlobalMsgCmd;

// 当前wifi网络状态
typedef enum{
    WIFI_STATE_CONNECTING, /* 网络正在连接 */
    WIFI_STATE_CONNECTED, /* 网络连接成功 */
    WIFI_STATE_DISCONNECTED, /* 网络断开连接 */
    WIFI_STATE_NETWORK, /* 连接互联网成功 */
}WifiNetworkState;

// 设备工作状态
typedef enum {
	DEVICE_STATE_IDLE = 0,              // 机器空闲
	DEVICE_STATE_PRINTTING,             // 打印中
	DEVICE_STATE_SELF_TEST,             // 开机自检中
    DEVICE_STATE_AUTO_LEVEL,            // 自动调平中
    DEVICE_STATE_RESONANCE_TEST,        // 振动补偿中
    DEVICE_STATE_UPGRADING,             // 升级中
    DEVICE_STATE_RESET,                 // 恢复出厂设置
    DEVICE_STATE_HOMING,                // 归零中
    DEVICE_STATE_EXPORT_LOG,            // 导出日志
    DEVICE_STATE_UPLOAD_LOG,            // 上传日志
    DEVICE_STATE_LOAD_MATERIAL,         // 进料中
    DEVICE_STATE_QUIT_MATERIAL,         // 退料中
    DEVICE_STATE_COMPRESSING_LOG,       // 压缩日志
} DEVICE_STATE_t; 

// 设备打印模式
typedef enum {
	APP_MODE_IDLE = 0,
	APP_MODE_SD_PRINT,
	APP_MODE_AUTO_PRINT,
    APP_MODE_MAX,
}FSM_MODE_t; 

// 设备打印状态
typedef enum {
    APP_PRINT_STATE_IDLE = 0,
    APP_PRINT_STATE_WORK = 1,
    APP_PRINT_STATE_PAUSE = 2,
    APP_PRINT_STATE_FINISH = 3,
    APP_PRINT_STATE_FAIL = 4,
    APP_PRINT_STATE_STOP = 5,
    APP_PRINT_STATE_DOWNLOAD = 6,
    // 状态切换中
    APP_PRINT_STATE_TO_WORK = 10,
    APP_PRINT_STATE_TO_PAUSE = 11,
    APP_PRINT_STATE_TO_RESUME = 12,
    APP_PRINT_STATE_TO_STOP = 13,
    // 特殊状态
    APP_PRINT_STATE_LAYER_PAUSE = 30,
}AppPrintState;

/**
 * @description: 消息处理相关宏调用
 */
#define MESSAGE_BUFF_MAX_LEN    8192 //消息体最大的数据长度
#define GET_MESSAGE_BUFF(a)     uint8_t a[MESSAGE_BUFF_MAX_LEN] = {0}

typedef struct {
    long mtype;         /* 消息类型，必须 > 0 */
    uint32_t origin;    /* 消息源 */
    uint32_t cmd;       /* 消息命令 */
    size_t bufLen;      /* 消息长度 */
    uint8_t buf[MESSAGE_BUFF_MAX_LEN];  /* 消息文本 */
}MsgHeadBuf_t;

#define CREATE_MESSAGE_PACKAGE(a, b, c, d, e, f)    \
    MsgHeadBuf_t a; \
    memset(&a, 0, sizeof(MsgHeadBuf_t));    \
    a.mtype = 1;    \
    a.origin = c;   \
    a.cmd = d;      \
    a.bufLen = f;   \
    memcpy(a.buf, e, f<MESSAGE_BUFF_MAX_LEN ? f : MESSAGE_BUFF_MAX_LEN);    \
    size_t b = sizeof(MsgHeadBuf_t) - sizeof(a.buf) + f;

#define CREATE_MESSAGE_QUEUE(a)    \
    msgget(a, IPC_CREAT|0666)

#define SEND_MESSAGE_PACKAGE(a, b, c)    \
    msgsnd(a, (const void *)b, c, IPC_NOWAIT)

#define RECV_MESSAGE_PACKAGE(a, b)    \
    msgrcv(a, (void *)b, sizeof(MsgHeadBuf_t), 0, 0)

#define RECV_MESSAGE_PACKAGE_NOWAIT(a, b)    \
    msgrcv(a, (void *)b, sizeof(MsgHeadBuf_t), 0, IPC_NOWAIT)


#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
