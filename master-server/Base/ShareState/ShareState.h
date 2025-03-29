/*
 * @Description : ShareState.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-28 12:01:27
 * @LastEditTime: 2023-10-11 17:53:43
 */

#ifndef __SHARE_STATE_H__
#define __SHARE_STATE_H__

#include "Base/MasterMsgBase.h"

#ifdef  __cplusplus  
extern "C" {  
#endif

typedef struct String {
    uint32_t len;
    char *data;
}String_t;

void ShareStateInit(void);
PrintSavePara_t GetPrintSavePara(void);
void UpdataPrintSavePara(PrintSavePara_t data);
PrintState_t GetPrintState(void);

void UpdataSerialPort(int data);
void UpdataSdCardExists(int data);
void UpdataUdiskMount(int data, Udisk_t num);
void UpdataEthernetExists(int data);
void UpdataCameraOnline(int data, Camera_t num);
void UpdataLaserOnline(int data);
void UpdataScannerOnline(int data);
void UpdataDeviceState(int data);
void UpdataDeviceStateSelfTest(int data);
void UpdataPrintWorkMode(int data);
void UpdataPrintWorkState(int data);
void UpdataNozzleCurTemp(int data, NozzleTemp_t num);
void UpdataNozzleMaxTemp(int data, NozzleTemp_t num);
void UpdataNozzlePower(int data, NozzleTemp_t num);
void UpdataNozzleTempWait(int data);
void UpdataBedCurTemp(int data, HotbedTemp_t num);
void UpdataBedMaxTemp(int data, HotbedTemp_t num);
void UpdataBedPower(int data, HotbedTemp_t num);
void UpdataBedTempWait(int data);
void UpdataOtherCurTemp(int data, OtherTemp_t num);
void UpdataPrintFanState(int data, MultiFan_t num);
void UpdataPrintFanSpeed(int data, MultiFan_t num);
void UpdataPrintFanPercentage(int data, MultiFan_t num);
void UpdataPrintMotorState(int data);
void UpdataPrintLightState(int data);
void UpdataPrintWifiState(int data);
void UpdataPrintPauseStatus(int data);
void UpdataPrintMaterialStatus(int data, MaterialDetector_t num);
void UpdataPrintSpeed(int data);
void UpdataPrintFlow(int data);
void UpdataRealTimeSpeed(int data);
void UpdataRealTimeFlow(int data);
void UpdataPrintUsageTime(uint32_t data);
void UpdataPrintRemainTime(uint32_t data);
void UpdataFilamentUsed(uint32_t data);
void UpdataPrintProgress(int data);
void UpdataPrintLayer(uint32_t data);
void UpdataPrintLayers(uint32_t data);
void UpdataCrTouchState(int data);
void UpdataFaultCode(FaultCode_t data);
void UpdataExistOffContinue(int data);
void UpdataLivePosition(Coordinate_t data);
void UpdataGcodePosition(Coordinate_t data);
void UpdataHomedAxes(Coordinate_t data);
void UpdataAutoLevelProgress(int data);
void UpdataAutoPidProgress(int data);
void UpdataKlipperState(int data);
void UpdataKlipperPrint(int data);
void UpdataSdPath(char *data);
void UpdataUDiskPath(char *data);
void UpdataQmodeFlag(int data);
void UpdataWithSelfTest(int data);
void UpdataLoadMaterial(int data);
void UpdataQuitMaterial(int data);
void UpdataCxyMqttState(int data);
void UpdataLogProgress(int data);
void UpdataScanFileProgress(int data);


/*********************************************************
 *********************************************************
 ******************** 当前打印任务信息 **********************
 *********************************************************
 *********************************************************/
/**
 * @description: 提取前一次打印文件历史记录
 * @return {*}
 */
typedef struct PrintHistory {
    uint32_t status;
    uint32_t print_duration;
    double filament_used_real;
} PrintHistory_t;

/**
 * @description: gcode文件提取元数据信息
 * @return {*}
 */
typedef struct CurrentFile {
    // 任务信息
    uint32_t id;                    // 打印任务ID
    uint32_t startTime;             // 打印开始时间
    int startWay;                   // 启动打印方式（UI、APP、...）

    // 文件信息
    char fileName[256];             // 打印文件名称
    int32_t size;                   // 文件大小
    int32_t cTime;                  // 创建时间

    // 模型信息
    double nozzle_target_temp;      // 喷嘴目标温度
    double bed_target_temp;         // 热床目标温度
    double layer_height;            // 模型层高
    double first_layer_height;      // 首层高度
    double object_light;            // 模型长
    double object_weight;           // 模型宽
    double object_height;           // 模型高度
    double filament_total;          // 预计使用耗材长度
    double filament_weight_total;   // 预计使用耗材重量
    int32_t estimated_time;         // 预计打印时间
    int32_t first_layer_bed_temp;   // 首层热床温度
    int32_t first_layer_extr_temp;  // 首层喷嘴温度
    long gcode_start_byte;          // 开始gcode指令文件偏移
    long gcode_end_byte;            // 结束gcode指令文件偏移
    char material[32];              // 耗材名称
    char software[32];              // 切片软件

    // 图片信息
    char thumbnails[256];           // 缩略图路径
    uint32_t startPixel;            // 预览图起始像素点
    uint32_t endPixel;              // 预览图结束像素点
    uint32_t modelHeight;           // 预览图模型高度
    uint32_t layerHeight;           // 预览图模型层高
    char preview[256];              // 预览图路径

    // 同名文件，前一次打印信息
    PrintHistory_t history;         // 前一次打印记录
} CurrentFile_t;

/**
 * @description: klipper动态状态
 * @return {*}
 */
typedef struct {
    bool is_paused;
}pause_resume_t;

typedef struct {
    double temperature;
    double target;
    double power;
}heater_bed_t;

typedef struct {
    double temperature;
    double target;
    double power;
    double pressure_advance;
    double smooth_time;
}extruder_t;

typedef struct {
    double live_position[4];
}motion_report_t;

typedef struct {
    String_t state;
    String_t message;
    String_t filename;
    double total_duration;
    double print_duration;
    double filament_used;
    double filament_used_real;
}print_stats_t;

typedef struct {
    double gcode_position[4];
    double homing_origin[4];
    double speed;
    bool absolute_coordinates;
    double speed_factor;
    double extrude_factor;
}gcode_move_t;

typedef struct {
    double speed;
}fan_t;

typedef struct {
    int32_t fan0_speed;
    int32_t fan1_speed;
    int32_t fan2_speed;
    int32_t fan3_speed;
    int32_t fan4_speed;
}fan_feedback_t;

typedef struct {
    double progress;
    int file_position;
    bool is_active;
    String_t file_path;
    int file_size;
    bool first_layer_stop;
    int layer;
    int last_layer;
    int layer_count;
    int last_layer_count;
    double run_dis;
}virtual_sdcard_t;

typedef struct {
    double progress;
}display_status_t;

typedef struct {
    bool filament_detected;
    bool enabled;
}filament_sensor_t;

typedef struct {
    double print_time;
    double estimated_print_time;
    String_t homed_axes;
    double max_velocity;
    double max_accel;
    double square_corner_velocity;
    double max_accel_to_decel;
}toolhead_t;

typedef struct {
    String_t state;
    String_t state_message;
}webhooks_t;

typedef struct {
    bool bed_temperature_wait;
    bool extruder_temperature_wait;
}heaters_t;

typedef struct {
    double z_offset;
}probe_t;

typedef struct {
    String_t objects;
    String_t excluded_objects;
    String_t current_object;
}exclude_object_t;

typedef struct {
    int flag;
}gcode_macro_Qmode_t;

typedef struct {
    int fan0_min;
    int fan1_min;
    int fan2_min;
}gcode_macro_Printer_Param_t;

/**
 * @description: klipper整体状态
 * @return {*}
 */
typedef struct {
    double eventtime;
    pause_resume_t pause_resume;
    heater_bed_t heater_bed;
    heater_bed_t heater_bed_0;
    heater_bed_t heater_bed_1;
    heater_bed_t heater_bed_2;
    heater_bed_t chamber_temp;
    extruder_t extruder;
    motion_report_t motion_report;
    print_stats_t print_stats;
    gcode_move_t gcode_move;
    fan_t modelFan;
    fan_t caseFan;
    fan_t auxiliaryFan;
    fan_feedback_t fan_feedback;
    virtual_sdcard_t virtual_sdcard;
    display_status_t display_status;
    filament_sensor_t filament_sensor;
    filament_sensor_t filament_sensor_2;
    toolhead_t toolhead;
    webhooks_t webhooks;
    heaters_t heaters;
    probe_t probe;
    exclude_object_t exclude_object;
    CurrentFile_t current_file;

    gcode_macro_Qmode_t gcode_macro_Qmode;
    gcode_macro_Printer_Param_t gcode_macro_Printer_Param;
}KlipperPrint_t;

KlipperPrint_t *GetPrinter(void);
void CleanPrinterCurrentFile(void);
int KlipperPrintAbnormalExitProcessing(void);
int SyncPrintingWorkInfo(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
