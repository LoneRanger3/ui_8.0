/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-02-22 20:24:06
 * @LastEditTime: 2023-06-17 12:01:02
 */
#include "Base/MasterMsgBase.h"
#include "ConfigAnl.h"

/**
 * @description: 
 * @return {*}
 */
static Mcu_NozzleMcu_t nozzleMcu = {0};
static Mcu_LevelingMcu_t levelingMcu = {0};
static ExtruderConfig_t extruder = {0};
static HeaterBedConfig_t heaterBed = {0};
static LoadMaterial_t loadMaterial = {0};
static QuitMaterial_t quitMaterial = {0};
static PrintCalibration_t printCalibration = {0};
static LaserConfig_t laserConfig = {0};
static HeaterFanHotendFan_t heaterFanHotendFan = {0};
static FanFeedback_t fanFeedback = {0};
static Stepper_t stepperX = {0};
static Stepper_t stepperY = {0};
static Stepper_t stepperZ = {0};
static StructurePara_t structurePara = {0};

/**
 * @description: 
 * @return {*}
 */
Mcu_NozzleMcu_t *GetNozzleMcu(void) { return &nozzleMcu; }
Mcu_LevelingMcu_t *GetLevelingMcu(void) { return &levelingMcu; }
ExtruderConfig_t *GetExtruder(void) { return &extruder; }
HeaterBedConfig_t *GetHeaterBed(void) { return &heaterBed; }
LoadMaterial_t *GetLoadMaterial(void) { return &loadMaterial; }
QuitMaterial_t *GetQuitMaterial(void) { return &quitMaterial; }
PrintCalibration_t *GetPrintCalibration(void) { return &printCalibration; }
LaserConfig_t *GetLaserOffset(void) { return &laserConfig; }
HeaterFanHotendFan_t *GetheaterFanHotendFan(void) { return &heaterFanHotendFan; }
FanFeedback_t *GetFanFeedback(void) { return &fanFeedback; }
Stepper_t *GetStepperX(void) { return &stepperX; }
Stepper_t *GetStepperY(void) { return &stepperY; }
Stepper_t *GetStepperZ(void) { return &stepperZ; }
StructurePara_t *GetStructurePara(void) { return &structurePara; }

/**
 * @description: 
 * @return {*}
 * @param {json_object} *sourceObj
 * @param {json_object} *targetObj
 */
static void ExtractGcodeMacro(json_object *sourceObj, json_object *targetObj)
{
    // 提取字符串
    char gcodeStr[json_object_get_string_len(sourceObj) + 1];
    bzero(gcodeStr, sizeof(gcodeStr));
    strcat(gcodeStr, json_object_get_string(sourceObj));
    CrLogI("gcode macro = %s", gcodeStr);

    // 提取gcode指令
    char *answer = strtok(gcodeStr, "\n");
    while (answer)
    {
        char stitching[256] = {0};
        if (strstr(answer, "G0 ") || strstr(answer, "G1 ")) {
            snprintf(stitching, sizeof(stitching), "%s\nM400", answer);
        }
        else strcat(stitching, answer);

        json_object_array_add(targetObj, json_object_new_string(stitching));
        answer = strtok(NULL, "\n");
    }
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *configObj
 */
static int KlipperDedaultConfigAnl(json_object *configObj)
{
    // 获取已更新klipper保存参数
    PrintSavePara_t updataPara = GetPrintSavePara();
    SystemConfigProto config = SYSTEM_CONFIG_PROTO__INIT;

    // 虚拟SD卡
    json_object *sdcardObj = json_object_object_get(configObj, "virtual_sdcard");
    if (sdcardObj != NULL && json_object_is_type(sdcardObj, json_type_object))
    {
        CrLogI("sdcardObj = %s", json_object_to_json_string_ext(sdcardObj, JSON_C_TO_STRING_PLAIN|JSON_C_TO_STRING_NOSLASHESCAPE));
        json_object *pathObj = json_object_object_get(sdcardObj, "path");
        if (pathObj != NULL && json_object_is_type(pathObj, json_type_string))
        {
            const char *getPath = json_object_get_string(pathObj);
            char updataPath[256] = {0};

            if (getPath[0] == '~') {
                char *getHome = getenv("HOME");
                CrLogI("'HOME' pwd = %s", getHome);
                strcat(updataPath, getHome);
                strcat(updataPath, &getPath[1]);
            }
            else strcat(updataPath, getPath);
            CrLogI("updata sdcard path = %s", updataPath);

            #ifdef CROSS_COMPILE
            // 更新SD卡路径
            char *fileInfoPath = GetUserLocalSdCardPtah();
            memset(fileInfoPath, 0, strlen(fileInfoPath));
            memcpy(fileInfoPath, updataPath, strlen(updataPath));

            // 同步到其他服务进程
            UpdataSdPath(updataPath);
            #endif
        }
    }
    // 喷嘴MCU
    json_object *nozzleMcuObj = json_object_object_get(configObj, "mcu nozzle_mcu");
    if (nozzleMcuObj != NULL && json_object_is_type(nozzleMcuObj, json_type_object))
    {
        json_object *serialObj = json_object_object_get(nozzleMcuObj, "serial");
        if (serialObj != NULL && json_object_is_type(serialObj, json_type_string))
        {
            nozzleMcu.serial = (char*)realloc(nozzleMcu.serial, json_object_get_string_len(serialObj) + 1);
            memset(nozzleMcu.serial, 0, json_object_get_string_len(serialObj) + 1);
            strcat(nozzleMcu.serial, json_object_get_string(serialObj));
            CrLogI("nozzle mcu serial = %s", nozzleMcu.serial);
        }
    }
    // 热床MCU
    json_object *levelingMcuObj = json_object_object_get(configObj, "mcu leveling_mcu");
    if (levelingMcuObj != NULL && json_object_is_type(levelingMcuObj, json_type_object))
    {
        json_object *serialObj = json_object_object_get(levelingMcuObj, "serial");
        if (serialObj != NULL && json_object_is_type(serialObj, json_type_string))
        {
            levelingMcu.serial = (char*)realloc(levelingMcu.serial, json_object_get_string_len(serialObj) + 1);
            memset(levelingMcu.serial, 0, json_object_get_string_len(serialObj) + 1);
            strcat(levelingMcu.serial, json_object_get_string(serialObj));
            CrLogI("leveling mcu serial = %s", levelingMcu.serial);
        }
    }
    // 进料宏指令
    json_object *loadMaterialObj = json_object_object_get(configObj, "gcode_macro LOAD_MATERIAL");
    if (loadMaterialObj != NULL && json_object_is_type(loadMaterialObj, json_type_object))
    {
        json_object *gcodeObj = json_object_object_get(loadMaterialObj, "gcode");
        if (gcodeObj != NULL && json_object_is_type(gcodeObj, json_type_string))
        {
            if (loadMaterial.macro) json_object_put(loadMaterial.macro);
            loadMaterial.macro = json_object_new_array();
            ExtractGcodeMacro(gcodeObj, loadMaterial.macro);
            CrLogI("gcode macro = %s\n", json_object_to_json_string(loadMaterial.macro));
        }
    }
    // 进料宏指令
    json_object *quitMaterialObj = json_object_object_get(configObj, "gcode_macro QUIT_MATERIAL");
    if (quitMaterialObj != NULL && json_object_is_type(quitMaterialObj, json_type_object))
    {
        json_object *gcodeObj = json_object_object_get(quitMaterialObj, "gcode");
        if (gcodeObj != NULL && json_object_is_type(gcodeObj, json_type_string))
        {
            if (quitMaterial.macro) json_object_put(quitMaterial.macro);
            quitMaterial.macro = json_object_new_array();
            ExtractGcodeMacro(gcodeObj, quitMaterial.macro);
            CrLogI("gcode macro = %s\n", json_object_to_json_string(quitMaterial.macro));
        }
    }
    // 打印前校准宏指令
    json_object *printCalibrationObj = json_object_object_get(configObj, "gcode_macro PRINT_CALIBRATION");
    if (printCalibrationObj != NULL && json_object_is_type(printCalibrationObj, json_type_object))
    {
        json_object *gcodeObj = json_object_object_get(printCalibrationObj, "gcode");
        if (gcodeObj != NULL && json_object_is_type(gcodeObj, json_type_string))
        {
            if (printCalibration.macro) json_object_put(printCalibration.macro);
            printCalibration.macro = json_object_new_array();
            ExtractGcodeMacro(gcodeObj, printCalibration.macro);
            CrLogI("gcode macro = %s\n", json_object_to_json_string(printCalibration.macro));
        }
    }
    // 喷嘴
    json_object *extruderObj = json_object_object_get(configObj, "extruder");
    if (extruderObj != NULL && json_object_is_type(extruderObj, json_type_object))
    {
        json_object *filamentDiameterObj = json_object_object_get(extruderObj, "filament_diameter");
        if (filamentDiameterObj != NULL && json_object_is_type(filamentDiameterObj, json_type_string))
        {
            const char *diameterStr = json_object_get_string(filamentDiameterObj);
            extruder.filamentDiameter = atof(diameterStr);
            CrLogI("filament_diameter = %f", extruder.filamentDiameter);
        }
        json_object *maxTempObj = json_object_object_get(extruderObj, "max_temp");
        if (maxTempObj != NULL && json_object_is_type(maxTempObj, json_type_string))
        {
            const char *temp = json_object_get_string(maxTempObj);
            extruder.max_temp = atof(temp);
            CrLogI("max_temp = %f", extruder.max_temp);
            updataPara.nozzleHwMaxTemp = extruder.max_temp;
        }
    }
    // 热床
    json_object *heaterBedObj = json_object_object_get(configObj, "heater_bed");
    if (heaterBedObj != NULL && json_object_is_type(heaterBedObj, json_type_object))
    {
        json_object *maxTempObj = json_object_object_get(heaterBedObj, "max_temp");
        if (maxTempObj != NULL && json_object_is_type(maxTempObj, json_type_string))
        {
            const char *temp = json_object_get_string(maxTempObj);
            heaterBed.max_temp = atof(temp);
            CrLogI("max_temp = %f", heaterBed.max_temp);
            updataPara.bedHwMaxTemp = heaterBed.max_temp;
        }
    }
    // 流量检测激光XYZ偏移值
    json_object *laserObj = json_object_object_get(configObj, "laser");
    if (laserObj != NULL && json_object_is_type(laserObj, json_type_object))
    {
        json_object *x_offsetObj = json_object_object_get(laserObj, "x_offset");
        if (x_offsetObj != NULL && json_object_is_type(x_offsetObj, json_type_string))
        {
            const char *x_offsetStr = json_object_get_string(x_offsetObj);
            laserConfig.x_offset = atof(x_offsetStr);
            CrLogI("laser x_offset = %f", laserConfig.x_offset);
        }
        json_object *y_offsetObj = json_object_object_get(laserObj, "y_offset");
        if (y_offsetObj != NULL && json_object_is_type(y_offsetObj, json_type_string))
        {
            const char *y_offsetStr = json_object_get_string(y_offsetObj);
            laserConfig.y_offset = atof(y_offsetStr);
            CrLogI("laser y_offset = %f", laserConfig.y_offset);
        }
        json_object *z_offsetObj = json_object_object_get(laserObj, "z_offset");
        if (z_offsetObj != NULL && json_object_is_type(z_offsetObj, json_type_string))
        {
            const char *z_offsetStr = json_object_get_string(z_offsetObj);
            laserConfig.z_offset = atof(z_offsetStr);
            CrLogI("laser z_offset = %f", laserConfig.z_offset);
        }
    }
    // 获取喷嘴风扇状态
    json_object *hotendFanObj = json_object_object_get(configObj, "heater_fan hotend_fan");
    if (hotendFanObj != NULL && json_object_is_type(hotendFanObj, json_type_object))
    {
        json_object *heaterTempObj = json_object_object_get(hotendFanObj, "heater_temp");
        if (heaterTempObj != NULL && json_object_is_type(heaterTempObj, json_type_string))
        {
            const char *heaterTempStr = json_object_get_string(heaterTempObj);
            heaterFanHotendFan.heater_temp = atoi(heaterTempStr);
            CrLogI("heater_temp = %d", heaterFanHotendFan.heater_temp);
        }
    }
    // 获取风扇反馈配置
    json_object *fanFeedbackObj = json_object_object_get(configObj, "fan_feedback");
    if (fanFeedbackObj != NULL && json_object_is_type(fanFeedbackObj, json_type_object))
    {
        fanFeedback.exist = true;
        updataPara.fanFeedback = 1;
        CrLogI("exist fan_feedback");
    }
    else updataPara.fanFeedback = 0;

    // 获取设备尺寸大小
    json_object *stepper_xObj = json_object_object_get(configObj, "stepper_x");
    if (stepper_xObj != NULL && json_object_is_type(stepper_xObj, json_type_object))
    {
        json_object *positionMinObj = json_object_object_get(stepper_xObj, "position_min");
        if (positionMinObj != NULL && json_object_is_type(positionMinObj, json_type_string))
        {
            const char *position_min = json_object_get_string(positionMinObj);
            stepperX.position_min = atof(position_min);
            CrLogI("position_min = %f", stepperX.position_min);
            if (stepperX.position_min > 0) updataPara.devMinSize.x = stepperX.position_min * 100 + 0.5;
            else updataPara.devMinSize.x = stepperX.position_min * 100 - 0.5;
        }
        json_object *positionMaxObj = json_object_object_get(stepper_xObj, "position_max");
        if (positionMaxObj != NULL && json_object_is_type(positionMaxObj, json_type_string))
        {
            const char *position_max = json_object_get_string(positionMaxObj);
            stepperX.position_max = atof(position_max);
            CrLogI("position_max = %f", stepperX.position_max);
            updataPara.devMaxSize.x = stepperX.position_max * 100 + 0.5;
        }
    }
    json_object *stepper_yObj = json_object_object_get(configObj, "stepper_y");
    if (stepper_yObj != NULL && json_object_is_type(stepper_yObj, json_type_object))
    {
        json_object *positionMinObj = json_object_object_get(stepper_yObj, "position_min");
        if (positionMinObj != NULL && json_object_is_type(positionMinObj, json_type_string))
        {
            const char *position_min = json_object_get_string(positionMinObj);
            stepperY.position_min = atof(position_min);
            CrLogI("position_min = %f", stepperY.position_min);
            if (stepperY.position_min > 0) updataPara.devMinSize.y = stepperY.position_min * 100 + 0.5;
            else updataPara.devMinSize.y = stepperY.position_min * 100 - 0.5;
        }
        json_object *positionMaxObj = json_object_object_get(stepper_yObj, "position_max");
        if (positionMaxObj != NULL && json_object_is_type(positionMaxObj, json_type_string))
        {
            const char *position_max = json_object_get_string(positionMaxObj);
            stepperY.position_max = atof(position_max);
            CrLogI("position_max = %f", stepperY.position_max);
            updataPara.devMaxSize.y = stepperY.position_max * 100 + 0.5;
        }
    }
    json_object *stepper_zObj = json_object_object_get(configObj, "stepper_z");
    if (stepper_zObj != NULL && json_object_is_type(stepper_zObj, json_type_object))
    {
        json_object *positionMinObj = json_object_object_get(stepper_zObj, "position_min");
        if (positionMinObj != NULL && json_object_is_type(positionMinObj, json_type_string))
        {
            const char *position_min = json_object_get_string(positionMinObj);
            stepperZ.position_min = atof(position_min);
            CrLogI("position_min = %f", stepperZ.position_min);
            if (stepperZ.position_min > 0) updataPara.devMinSize.z = stepperZ.position_min * 100 + 0.5;
            else updataPara.devMinSize.z = stepperZ.position_min * 100 - 0.5;
        }
        json_object *positionMaxObj = json_object_object_get(stepper_zObj, "position_max");
        if (positionMaxObj != NULL && json_object_is_type(positionMaxObj, json_type_string))
        {
            const char *position_max = json_object_get_string(positionMaxObj);
            stepperZ.position_max = atof(position_max);
            CrLogI("position_max = %f", stepperZ.position_max);
            updataPara.devMaxSize.z = stepperZ.position_max * 100 + 0.5;
        }
    }

    // 获取结构偏移尺寸
    json_object *structureParaObj = json_object_object_get(configObj, "gcode_macro STRUCTURE_PARAM");
    if (structureParaObj != NULL && json_object_is_type(structureParaObj, json_type_object))
    {
        // 获取热床尺寸
        json_object *bedLengthObj = json_object_object_get(structureParaObj, "variable_bed_length");
        if (bedLengthObj != NULL && json_object_is_type(bedLengthObj, json_type_string))
        {
            structurePara.bed_length = atoi(json_object_get_string(bedLengthObj));
            CrLogI("bed_length = %d", structurePara.bed_length);
            config.has_bed_length = 1;
            config.bed_length = structurePara.bed_length;
        }
        json_object *bedWidthObj = json_object_object_get(structureParaObj, "variable_bed_width");
        if (bedWidthObj != NULL && json_object_is_type(bedWidthObj, json_type_string))
        {
            structurePara.bed_width = atoi(json_object_get_string(bedWidthObj));
            CrLogI("bed_width = %d", structurePara.bed_width);
            config.has_bed_width = 1;
            config.bed_width = structurePara.bed_width;
        }
        json_object *bedHightObj = json_object_object_get(structureParaObj, "variable_bed_hight");
        if (bedHightObj != NULL && json_object_is_type(bedHightObj, json_type_string))
        {
            structurePara.bed_hight = atoi(json_object_get_string(bedHightObj));
            CrLogI("bed_hight = %d", structurePara.bed_hight);
            config.has_bed_hight = 1;
            config.bed_hight = structurePara.bed_hight;
        }

        // 获取激光雷达偏移位置、标定位置
        json_object *configObj = json_object_from_file(GetDeviceStructureConfig());
        if (!configObj) configObj = json_object_new_object();
        json_object *laserObj= json_object_object_get(configObj, "laser_offset");
        if (!laserObj) laserObj = json_object_new_object();
        // X偏移
        json_object *laser_x_offsetObj = json_object_object_get(structureParaObj, "variable_laser_x_offset");
        if (laser_x_offsetObj != NULL && json_object_is_type(laser_x_offsetObj, json_type_string))
        {
            structurePara.laser_x_offset = atof(json_object_get_string(laser_x_offsetObj));
            CrLogI("laser_x_offset = %f", structurePara.laser_x_offset);
            json_object *value = json_object_object_get(laserObj, "laser_x_offset");
            if (value) json_object_set_double(value, structurePara.laser_x_offset);
            else json_object_object_add(laserObj, "laser_x_offset", json_object_new_double(structurePara.laser_x_offset));
        }
        // Y偏移
        json_object *laser_y_offsetObj = json_object_object_get(structureParaObj, "variable_laser_y_offset");
        if (laser_y_offsetObj != NULL && json_object_is_type(laser_y_offsetObj, json_type_string))
        {
            structurePara.laser_y_offset = atof(json_object_get_string(laser_y_offsetObj));
            CrLogI("laser_y_offset = %f", structurePara.laser_y_offset);
            json_object *value = json_object_object_get(laserObj, "laser_y_offset");
            if (value) json_object_set_double(value, structurePara.laser_y_offset);
            else json_object_object_add(laserObj, "laser_y_offset", json_object_new_double(structurePara.laser_y_offset));
        }
        // Z偏移
        json_object *laser_z_offsetObj = json_object_object_get(structureParaObj, "variable_laser_z_offset");
        if (laser_z_offsetObj != NULL && json_object_is_type(laser_z_offsetObj, json_type_string))
        {
            structurePara.laser_z_offset = atof(json_object_get_string(laser_z_offsetObj));
            CrLogI("laser_z_offset = %f", structurePara.laser_z_offset);
            json_object *value = json_object_object_get(laserObj, "laser_z_offset");
            if (value) json_object_set_double(value, structurePara.laser_z_offset);
            else json_object_object_add(laserObj, "laser_z_offset", json_object_new_double(structurePara.laser_z_offset));
        }
        // X标定
        json_object *cali_x_offsetObj = json_object_object_get(structureParaObj, "variable_cali_x_offset");
        if (cali_x_offsetObj != NULL && json_object_is_type(cali_x_offsetObj, json_type_string))
        {
            structurePara.cali_x_offset = atof(json_object_get_string(cali_x_offsetObj));
            CrLogI("cali_x_offset = %f", structurePara.cali_x_offset);
            json_object *value = json_object_object_get(laserObj, "cali_x_offset");
            if (value) json_object_set_double(value, structurePara.cali_x_offset);
            else json_object_object_add(laserObj, "cali_x_offset", json_object_new_double(structurePara.cali_x_offset));
        }
        // Y标定
        json_object *cali_y_offsetObj = json_object_object_get(structureParaObj, "variable_cali_y_offset");
        if (cali_y_offsetObj != NULL && json_object_is_type(cali_y_offsetObj, json_type_string))
        {
            structurePara.cali_y_offset = atof(json_object_get_string(cali_y_offsetObj));
            CrLogI("cali_y_offset = %f", structurePara.cali_y_offset);
            json_object *value = json_object_object_get(laserObj, "cali_y_offset");
            if (value) json_object_set_double(value, structurePara.cali_y_offset);
            else json_object_object_add(laserObj, "cali_y_offset", json_object_new_double(structurePara.cali_y_offset));
        }
        // Z标定
        json_object *cali_z_offsetObj = json_object_object_get(structureParaObj, "variable_cali_z_offset");
        if (cali_z_offsetObj != NULL && json_object_is_type(cali_z_offsetObj, json_type_string))
        {
            structurePara.cali_z_offset = atof(json_object_get_string(cali_z_offsetObj));
            CrLogI("cali_z_offset = %f", structurePara.cali_z_offset);
            json_object *value = json_object_object_get(laserObj, "cali_z_offset");
            if (value) json_object_set_double(value, structurePara.cali_z_offset);
            else json_object_object_add(laserObj, "cali_z_offset", json_object_new_double(structurePara.cali_z_offset));
        }
        // 保存配置文件, 释放内存
        json_object_to_file_ext(GetDeviceStructureConfig(), configObj, JSON_C_TO_STRING_PRETTY|JSON_C_TO_STRING_NOSLASHESCAPE);
        json_object_put(configObj);
    }

    // 更新klipper保存参数
    UpdataPrintSavePara(updataPara);
    UpdataSystemConfig(&config);
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *configObj
 */
static int KlipperSettingsConfigAnl(json_object *settingsObj)
{
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *resObj
 */
int KlipperConfigAnl(json_object *resObj)
{
    json_object *statusObj = json_object_object_get(resObj, "status");
    if (statusObj != NULL && json_object_is_type(statusObj, json_type_object))
    {
        json_object *configfileObj = json_object_object_get(statusObj, "configfile");
        if (configfileObj != NULL && json_object_is_type(configfileObj, json_type_object))
        {
            // 默认配置参数
            json_object *configObj = json_object_object_get(configfileObj, "config");
            if (configObj != NULL && json_object_is_type(configObj, json_type_object)) {
                KlipperDedaultConfigAnl(configObj);
            }
            
            // 动态运行参数
            json_object *settingsObj = json_object_object_get(configfileObj, "settings");
            if (settingsObj != NULL && json_object_is_type(settingsObj, json_type_object)) {
                KlipperSettingsConfigAnl(settingsObj);
            }
        }
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
int KlipperConfigAnlAbnormalExitProcessing(void)
{
    // 释放资源
    if (nozzleMcu.serial) free(nozzleMcu.serial);
    if (levelingMcu.serial) free(levelingMcu.serial);
    if (loadMaterial.macro) json_object_put(loadMaterial.macro);
    if (quitMaterial.macro) json_object_put(quitMaterial.macro);
    if (printCalibration.macro) json_object_put(printCalibration.macro);

    return 0;
}
