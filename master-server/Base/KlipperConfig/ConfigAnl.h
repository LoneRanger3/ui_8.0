/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-02-22 20:24:14
 * @LastEditTime: 2023-06-17 11:40:15
 */
#ifndef __KLIPPER_CONFIG_ANL_H__
#define __KLIPPER_CONFIG_ANL_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#include "Base/MasterMsgBase.h"

int KlipperConfigAnl(json_object *resObj);

/**
 * @description: 接收 klipper 配置文件信息
 * @return {*}
 */
typedef struct {
    char *serial;
}Mcu_NozzleMcu_t;

typedef struct {
    char *serial;
}Mcu_LevelingMcu_t;

typedef struct {
    double filamentDiameter;
    double max_temp;
}ExtruderConfig_t;

typedef struct {
    double max_temp;
}HeaterBedConfig_t;

typedef struct {
    json_object *macro;
}LoadMaterial_t;

typedef struct {
    json_object *macro;
}QuitMaterial_t;

typedef struct {
    json_object *macro;
}PrintCalibration_t;

typedef struct {
    float x_offset;
    float y_offset;
    float z_offset;
}LaserConfig_t;

typedef struct {
    int heater_temp;
}HeaterFanHotendFan_t;

typedef struct {
    bool exist;
}FanFeedback_t;

typedef struct {
    double position_min;
    double position_max;
}Stepper_t;

typedef struct {
    int bed_length;
    int bed_width;
    int bed_hight;
    double laser_x_offset;
    double laser_y_offset;
    double laser_z_offset;
    double cali_x_offset;
    double cali_y_offset;
    double cali_z_offset;
}StructurePara_t;

// 获取数据接口
Mcu_NozzleMcu_t *GetNozzleMcu(void);
Mcu_LevelingMcu_t *GetLevelingMcu(void);
ExtruderConfig_t *GetExtruder(void);
HeaterBedConfig_t *GetHeaterBed(void);
LoadMaterial_t *GetLoadMaterial(void);
QuitMaterial_t *GetQuitMaterial(void);
PrintCalibration_t *GetPrintCalibration(void);
LaserConfig_t *GetLaserOffset(void);
HeaterFanHotendFan_t *GetheaterFanHotendFan(void);
FanFeedback_t *GetFanFeedback(void);
Stepper_t *GetStepperX(void);
Stepper_t *GetStepperY(void);
Stepper_t *GetStepperZ(void);
StructurePara_t *GetStructurePara(void);

int KlipperConfigAnlAbnormalExitProcessing(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif