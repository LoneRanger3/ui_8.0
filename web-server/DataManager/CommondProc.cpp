/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-08-17 19:23:07
 * @LastEditTime: 2023-10-16 15:31:39
 */
#include "CommondProc.h"
#include "Message/ServerMessage.h"
#include "Base/JsonInter.h"
#include "DataManager/AttributeProc.h"
#include "Base/Ini.h"
#include <thread>

CommondProc* CommondProc::m_Instance=nullptr;
CommondProc::CommondProc()
{
    SetcmdList["fan"] = bind(&CommondProc::fanProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["fanCase"] = bind(&CommondProc::fanCaseProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["fanAuxiliary"] = bind(&CommondProc::fanAuxiliaryProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["nozzleTempControl"] = bind(&CommondProc::nozzleTempControlProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["bedTempControl"] = bind(&CommondProc::bedTempControlProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["stop"] = bind(&CommondProc::stopProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["pause"] = bind(&CommondProc::pauseProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["repoPlrStatus"] = bind(&CommondProc::repoPlrStatusProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["gcodeCmd"] = bind(&CommondProc::gcodeCmdProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["setFeedratePct"] = bind(&CommondProc::setFeedratePctProc,this,placeholders::_1,placeholders::_2);
    
    SetcmdList["setFlowratePct"] = bind(&CommondProc::setFlowratePctProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["setPosition"] = bind(&CommondProc::setPositionProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["autohome"] = bind(&CommondProc::autohomeProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["opGcodeFile"] = bind(&CommondProc::opGcodeFileProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["enableSelfTest"] = bind(&CommondProc::enableSelfTestProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["setZOffset"] = bind(&CommondProc::setZOffsetProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["motorLock"] = bind(&CommondProc::motorLockProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["heatersOff"] = bind(&CommondProc::heatersOffProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["velocityLimits"] = bind(&CommondProc::velocityLimitsProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["accelerationLimits"] = bind(&CommondProc::accelerationLimitsProc,this,placeholders::_1,placeholders::_2);
    
    SetcmdList["cornerVelocityLimits"] = bind(&CommondProc::cornerVelocityLimitsProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["accelToDecelLimits"] = bind(&CommondProc::accelToDecelLimitsProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["pressureAdvance"] = bind(&CommondProc::pressureAdvanceProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["smoothTime"] = bind(&CommondProc::smoothTimeProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["videoElapse"] = bind(&CommondProc::videoElapseProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["nozzleMoveSnapshot"] = bind(&CommondProc::nozzleMoveSnapshotProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["videoElapseFrame"] = bind(&CommondProc::videoElapseFrameProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["videoElapseInterval"] = bind(&CommondProc::videoElapseIntervalProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["bedTempAutoPid"] = bind(&CommondProc::bedTempAutoPidProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["nozzleTempAutoPid"] = bind(&CommondProc::nozzleTempAutoPidProc,this,placeholders::_1,placeholders::_2);
    
    SetcmdList["startAutoPid"] = bind(&CommondProc::startAutoPidProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["materialDetect"] = bind(&CommondProc::materialDetectProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["powerLossSw"] = bind(&CommondProc::powerLossSwProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["resonanceTest"] = bind(&CommondProc::resonanceTestProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["manualLevel"] = bind(&CommondProc::manualLevelProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["autoLevel"] = bind(&CommondProc::autoLevelProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["restartKlipper"] = bind(&CommondProc::restartKlipperProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["restartFirmware"] = bind(&CommondProc::restartFirmwareProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["resetSystem"] = bind(&CommondProc::resetSystemProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["exportLog"] = bind(&CommondProc::exportLogProc,this,placeholders::_1,placeholders::_2);

    SetcmdList["linuxUpgrade"] = bind(&CommondProc::linuxUpgradeProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["mcuUpgrade"] = bind(&CommondProc::mcuUpgradeProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["lightSw"] = bind(&CommondProc::lightSwProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["setPrinterCfg"] = bind(&CommondProc::setPrinterCfgProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["rmProbedMatrix"] = bind(&CommondProc::rmProbedMatrixProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["savePara"] = bind(&CommondProc::saveParaProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["aiSw"] = bind(&CommondProc::aiSwProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["aiDetection"] = bind(&CommondProc::aiDetectionProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["aiPausePrint"] = bind(&CommondProc::aiPausePrintProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["aiFirstFloor"] = bind(&CommondProc::aiFirstFloorProc,this,placeholders::_1,placeholders::_2);
  
    SetcmdList["deleteHistory"] = bind(&CommondProc::deleteHistoryProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["cleanErr"] = bind(&CommondProc::cleanErrProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["ctrlVideoFiles"] = bind(&CommondProc::ctrlVideoFilesProc,this,placeholders::_1,placeholders::_2);
    SetcmdList["excludeObjects"] = bind(&CommondProc::excludeObjectsProc,this,placeholders::_1,placeholders::_2);

    GetcmdList["ReqPrinterPara"] = bind(&CommondProc::ReqPrinterParaProc,this,placeholders::_1,placeholders::_2);
    GetcmdList["reqGcodeFile"] = bind(&CommondProc::reqGcodeFileProc,this,placeholders::_1,placeholders::_2);
    GetcmdList["reqHistory"] = bind(&CommondProc::reqHistoryProc,this,placeholders::_1,placeholders::_2);
    GetcmdList["reqElapseVideoList"] = bind(&CommondProc::reqElapseVideoListProc,this,placeholders::_1,placeholders::_2);
    GetcmdList["reqOtaInfo"] = bind(&CommondProc::reqOtaInfoProc,this,placeholders::_1,placeholders::_2);
    GetcmdList["reqPrinterCfg"] = bind(&CommondProc::reqPrinterCfgProc,this,placeholders::_1,placeholders::_2);
    GetcmdList["reqProbedMatrix"] = bind(&CommondProc::reqProbedMatrixProc,this,placeholders::_1,placeholders::_2);
    GetcmdList["reqPrintObjects"] = bind(&CommondProc::reqPrintObjectsProc,this,placeholders::_1,placeholders::_2); 
}

string CommondProc::GetCmdProc(int socketId,const string &key,json_object *val)
{
    string ret;
    CrLogI("GetCmdProc key: %s obj : %s", key.c_str(),json_object_to_json_string(val));

    auto cmd = GetcmdList.find(key);
    if(cmd != GetcmdList.end())
    {
        ret = cmd->second(val,socketId);
    }else
        CrLogW("GetCmdProc no support key: %s",key.c_str());
    return ret;
}

string CommondProc::SetCmdProc(int socketId,const string &key,json_object *val)
{
    string ret;
    CrLogI("SetCmdProc key: %s obj : %s", key.c_str(),json_object_to_json_string(val));
    auto cmd = SetcmdList.find(key);
    if(cmd != SetcmdList.end())
    {
        ret = cmd->second(val,socketId);
    }else
        CrLogW("SetCmdProc no support key: %s",key.c_str());
    return ret;
}

/**
 * @description: 
 * @return {*}
 * @param 
 */
void CommondProc::Remove7zPackges()
{
    char cmd[256]= {0};
    char* logPath = GetUserDataLogDirPtah();
    snprintf(cmd,sizeof(cmd),"rm -f %s*.7z && sync",logPath);
    CrLogI("cmd:[%s]\n",cmd);

    // 调用系统命令
    char sysRes[1024] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);
}

/**
 * @description: 
 * @return {*}
 */
char* CommondProc::UserExportLog()
{
    // 判断用户是否指定路径
    char *savePath = NULL;
    savePath = GetUserDataLogDirPtah();

    // 获取当前时间戳
    struct timeval startTime;
    gettimeofday(&startTime, NULL);
    struct tm *CurTime = localtime(&startTime.tv_sec);

    // 创建压缩包文件名称（包含绝对路径）
    char filePath[512] = {0};
    static char fileName[256] = {0};
    snprintf(fileName , sizeof(fileName) ,"%d-%02d-%02d_%02d-%02d-%02d_creality_log.7z",
        CurTime->tm_year + 1900, CurTime->tm_mon + 1,CurTime->tm_mday, 
        CurTime->tm_hour, CurTime->tm_min, CurTime->tm_sec);    
    CrLogI("fileName = %s", fileName);
    snprintf(filePath , sizeof(filePath) ,"%s/%s",savePath, fileName);
    CrLogI("7z savePath = %s", filePath);

    // 获取系统信息
    GetSaveSystemInfoToFile(GetTempSaveSystemInfoPath());
    
    // 构建压缩命令
    char exportLogCmd[512] = {0};
    snprintf(exportLogCmd, sizeof(exportLogCmd), GetDefaultLog7zCompressionScript(),
        LOG_DECOMPRESSION_PASSWORD, filePath, GetUserDataLogDirPtah(), GetUserDataKlipperLogDirPtah(),
        GetDefaultSystemKernelLogPtah(), GetUserDataConfigDirPtah(),GetTempSaveSystemInfoPath());
    CrLogI("export log cmd = %s\n", exportLogCmd);

    // 压缩日志
    // 调用系统命令
    char sysRes[1024] = {0};
    if (!PopenSystem(exportLogCmd, sysRes, sizeof(sysRes))){
        CrLogW("system fail! res = %s\n", sysRes);
        return NULL;
    }else{
        CrLogI("export log result = %s\n", sysRes);
        return fileName;
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char*} filename
 */
string CommondProc::ReportExportLogInfo(char* filename)
{
    json_object *exportLogInfo = json_object_new_object();
    if(filename){
        json_object_object_add(exportLogInfo, "exportLogInfo", json_object_new_string(filename));
    }else{
        json_object_object_add(exportLogInfo, "exportLogInfo", json_object_new_string(""));
        CrLogW("filename is NULL \n");
        json_object_put(exportLogInfo);
        return "";
    }
    std::string send = json_object_to_json_string(exportLogInfo);
    json_object_put(exportLogInfo);
    return send;
}

string CommondProc::ReportPrinterConfigInfo()
{
    CrLogI("get printer config from printer.cfg");
    if (access(GetUserPrinterConfigFilePath(), F_OK) == 0){
        std::string path = GetUserPrinterConfigFilePath();
        mINI::INIFile file(path);
        mINI::INIStructure cfg;
        bool readSuccess  = file.read(cfg);
        if(readSuccess){
            json_object *reportPrinterConfig = json_object_new_object();
            json_object *printerCfgInfo = json_object_new_object();
            if (cfg.has("stepper_x")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["stepper_x"];
                if (collection.has("homing_speed")){
                    auto& homing_speed = collection["homing_speed"];
                    json_object_object_add(obj, "homing_speed", json_object_new_string(homing_speed.c_str()));
                }
                if (collection.has("position_max")){
                    auto& position_max = collection["position_max"];
                    json_object_object_add(obj, "position_max", json_object_new_string(position_max.c_str()));
                }
                if (collection.has("position_min")){
                    auto& position_min = collection["position_min"];
                    json_object_object_add(obj, "position_min", json_object_new_string(position_min.c_str()));
                }
                if (collection.has("position_endstop")){
                    auto& position_endstop = collection["position_endstop"];
                    json_object_object_add(obj, "position_endstop", json_object_new_string(position_endstop.c_str()));
                }
                if (collection.has("microsteps")){
                    auto& microsteps = collection["microsteps"];
                    json_object_object_add(obj, "microsteps", json_object_new_string(microsteps.c_str()));
                }
                if (collection.has("rotation_distance")){
                    auto& rotation_distance = collection["rotation_distance"];
                    json_object_object_add(obj, "rotation_distance", json_object_new_string(rotation_distance.c_str()));
                }
                json_object_object_add(printerCfgInfo, "stepper_x", obj);
            }
            if (cfg.has("tmc2209 stepper_x")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["tmc2209 stepper_x"];
                if (collection.has("run_current")){
                    auto& run_current = collection["run_current"];
                    json_object_object_add(obj, "run_current", json_object_new_string(run_current.c_str()));
                }
                if (collection.has("hold_current")){
                    auto& hold_current = collection["hold_current"];
                    json_object_object_add(obj, "hold_current", json_object_new_string(hold_current.c_str()));
                }
                json_object_object_add(printerCfgInfo, "tmc2209_stepper_x", obj);
            }
            if (cfg.has("stepper_y")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["stepper_y"];
                if (collection.has("homing_speed")){
                    auto& homing_speed = collection["homing_speed"];
                    json_object_object_add(obj, "homing_speed", json_object_new_string(homing_speed.c_str()));
                }
                if (collection.has("position_max")){
                    auto& position_max = collection["position_max"];
                    json_object_object_add(obj, "position_max", json_object_new_string(position_max.c_str()));
                }
                if (collection.has("position_min")){
                    auto& position_min = collection["position_min"];
                    json_object_object_add(obj, "position_min", json_object_new_string(position_min.c_str()));
                }
                if (collection.has("position_endstop")){
                    auto& position_endstop = collection["position_endstop"];
                    json_object_object_add(obj, "position_endstop", json_object_new_string(position_endstop.c_str()));
                }
                if (collection.has("microsteps")){
                    auto& microsteps = collection["microsteps"];
                    json_object_object_add(obj, "microsteps", json_object_new_string(microsteps.c_str()));
                }
                if (collection.has("rotation_distance")){
                    auto& rotation_distance = collection["rotation_distance"];
                    json_object_object_add(obj, "rotation_distance", json_object_new_string(rotation_distance.c_str()));
                }
                json_object_object_add(printerCfgInfo, "stepper_y", obj);
            }
            if (cfg.has("tmc2209 stepper_y")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["tmc2209 stepper_y"];
                if (collection.has("run_current")){
                    auto& run_current = collection["run_current"];
                    json_object_object_add(obj, "run_current", json_object_new_string(run_current.c_str()));
                }
                if (collection.has("hold_current")){
                    auto& hold_current = collection["hold_current"];
                    json_object_object_add(obj, "hold_current", json_object_new_string(hold_current.c_str()));
                }
                json_object_object_add(printerCfgInfo, "tmc2209_stepper_y", obj);
            }
            if (cfg.has("stepper_z")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["stepper_z"];
                if (collection.has("homing_speed")){
                    auto& homing_speed = collection["homing_speed"];
                    json_object_object_add(obj, "homing_speed", json_object_new_string(homing_speed.c_str()));
                }
                if (collection.has("position_max")){
                    auto& position_max = collection["position_max"];
                    json_object_object_add(obj, "position_max", json_object_new_string(position_max.c_str()));
                }
                if (collection.has("position_min")){
                    auto& position_min = collection["position_min"];
                    json_object_object_add(obj, "position_min", json_object_new_string(position_min.c_str()));
                }
                if (collection.has("position_endstop")){
                    auto& position_endstop = collection["position_endstop"];
                    json_object_object_add(obj, "position_endstop", json_object_new_string(position_endstop.c_str()));
                }
                if (collection.has("microsteps")){
                    auto& microsteps = collection["microsteps"];
                    json_object_object_add(obj, "microsteps", json_object_new_string(microsteps.c_str()));
                }
                if (collection.has("rotation_distance")){
                    auto& rotation_distance = collection["rotation_distance"];
                    json_object_object_add(obj, "rotation_distance", json_object_new_string(rotation_distance.c_str()));
                }
                json_object_object_add(printerCfgInfo, "stepper_z", obj);
            }
            if (cfg.has("tmc2209 stepper_z")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["tmc2209 stepper_z"];
                if (collection.has("run_current")){
                    auto& run_current = collection["run_current"];
                    json_object_object_add(obj, "run_current", json_object_new_string(run_current.c_str()));
                }
                if (collection.has("hold_current")){
                    auto& hold_current = collection["hold_current"];
                    json_object_object_add(obj, "hold_current", json_object_new_string(hold_current.c_str()));
                }
                json_object_object_add(printerCfgInfo, "tmc2209_stepper_z", obj);
            }
            if (cfg.has("extruder")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["extruder"];
                if (collection.has("nozzle_diameter")){
                    auto& nozzle_diameter = collection["nozzle_diameter"];
                    json_object_object_add(obj, "nozzle_diameter", json_object_new_string(nozzle_diameter.c_str()));
                }
                if (collection.has("filament_diameter")){
                    auto& filament_diameter = collection["filament_diameter"];
                    json_object_object_add(obj, "filament_diameter", json_object_new_string(filament_diameter.c_str()));
                }
                if (collection.has("min_temp")){
                    auto& min_temp = collection["min_temp"];
                    json_object_object_add(obj, "min_temp", json_object_new_string(min_temp.c_str()));
                }
                if (collection.has("max_temp")){
                    auto& max_temp = collection["max_temp"];
                    json_object_object_add(obj, "max_temp", json_object_new_string(max_temp.c_str()));
                }
                if (collection.has("microsteps")){
                    auto& microsteps = collection["microsteps"];
                    json_object_object_add(obj, "microsteps", json_object_new_string(microsteps.c_str()));
                }
                if (collection.has("rotation_distance")){
                    auto& rotation_distance = collection["rotation_distance"];
                    json_object_object_add(obj, "rotation_distance", json_object_new_string(rotation_distance.c_str()));
                }
                if (collection.has("pressure_advance")){
                    auto& pressure_advance = collection["pressure_advance"];
                    json_object_object_add(obj, "pressure_advance", json_object_new_string(pressure_advance.c_str()));
                }
                if (collection.has("pressure_advance_smooth_time")){
                    auto& pressure_advance_smooth_time = collection["pressure_advance_smooth_time"];
                    json_object_object_add(obj, "pressure_advance_smooth_time", json_object_new_string(pressure_advance_smooth_time.c_str()));
                }
                if (collection.has("pid_Kp")){
                    auto& pid_Kp = collection["pid_Kp"];
                    json_object_object_add(obj, "pid_Kp", json_object_new_string(pid_Kp.c_str()));
                }
                if (collection.has("pid_Ki")){
                    auto& pid_Ki = collection["pid_Ki"];
                    json_object_object_add(obj, "pid_Ki", json_object_new_string(pid_Ki.c_str()));
                }
                if (collection.has("pid_Kd")){
                    auto& pid_Kd = collection["pid_Kd"];
                    json_object_object_add(obj, "pid_Kd", json_object_new_string(pid_Kd.c_str()));
                }
                if (collection.has("max_power")){
                    auto& max_power = collection["max_power"];
                    json_object_object_add(obj, "max_power", json_object_new_string(max_power.c_str()));
                }
                json_object_object_add(printerCfgInfo, "extruder", obj);
            }
            if (cfg.has("heater_fan hotend_fan")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["heater_fan hotend_fan"];
                if (collection.has("heater_temp")){
                    auto& heater_temp = collection["heater_temp"];
                    json_object_object_add(obj, "heater_temp", json_object_new_string(heater_temp.c_str()));
                }
                json_object_object_add(printerCfgInfo, "heater_fan_hotend_fan", obj);
            }
            if (cfg.has("tmc2209 extruder")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["tmc2209 extruder"];
                if (collection.has("run_current")){
                    auto& run_current = collection["run_current"];
                    json_object_object_add(obj, "run_current", json_object_new_string(run_current.c_str()));
                }
                if (collection.has("hold_current")){
                    auto& hold_current = collection["hold_current"];
                    json_object_object_add(obj, "hold_current", json_object_new_string(hold_current.c_str()));
                }
                json_object_object_add(printerCfgInfo, "tmc2209_extruder", obj);
            }
            if (cfg.has("heater_bed")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["heater_bed"];
                if (collection.has("pid_Kp")){
                    auto& pid_Kp = collection["pid_Kp"];
                    json_object_object_add(obj, "pid_Kp", json_object_new_string(pid_Kp.c_str()));
                }
                if (collection.has("pid_Ki")){
                    auto& pid_Ki = collection["pid_Ki"];
                    json_object_object_add(obj, "pid_Ki", json_object_new_string(pid_Ki.c_str()));
                }
                if (collection.has("pid_Kd")){
                    auto& pid_Kd = collection["pid_Kd"];
                    json_object_object_add(obj, "pid_Kd", json_object_new_string(pid_Kd.c_str()));
                }
                if (collection.has("min_temp")){
                    auto& min_temp = collection["min_temp"];
                    json_object_object_add(obj, "min_temp", json_object_new_string(min_temp.c_str()));
                }
                if (collection.has("max_temp")){
                    auto& max_temp = collection["max_temp"];
                    json_object_object_add(obj, "max_temp", json_object_new_string(max_temp.c_str()));
                }
                if (collection.has("max_power")){
                    auto& max_power = collection["max_power"];
                    json_object_object_add(obj, "max_power", json_object_new_string(max_power.c_str()));
                }
                json_object_object_add(printerCfgInfo, "heater_bed", obj);
            }
            if (cfg.has("bed_mesh")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["bed_mesh"];
                if (collection.has("speed")){
                    auto& speed = collection["speed"];
                    json_object_object_add(obj, "speed", json_object_new_string(speed.c_str()));
                }
                if (collection.has("mesh_min")){
                    auto& mesh_min = collection["mesh_min"];
                    json_object_object_add(obj, "mesh_min", json_object_new_string(mesh_min.c_str()));
                }
                if (collection.has("mesh_max")){
                    auto& mesh_max = collection["mesh_max"];
                    json_object_object_add(obj, "mesh_max", json_object_new_string(mesh_max.c_str()));
                }
                if (collection.has("probe_count")){
                    auto& probe_count = collection["probe_count"];
                    json_object_object_add(obj, "probe_count", json_object_new_string(probe_count.c_str()));
                }
                if (collection.has("horizontal_move_z")){
                    auto& horizontal_move_z = collection["horizontal_move_z"];
                    json_object_object_add(obj, "horizontal_move_z", json_object_new_string(horizontal_move_z.c_str()));
                }
                json_object_object_add(printerCfgInfo, "bed_mesh", obj);
            }
            if (cfg.has("printer")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["printer"];
                if (collection.has("max_velocity")){
                    auto& max_velocity = collection["max_velocity"];
                    json_object_object_add(obj, "max_velocity", json_object_new_string(max_velocity.c_str()));
                }
                if (collection.has("max_accel")){
                    auto& max_accel = collection["max_accel"];
                    json_object_object_add(obj, "max_accel", json_object_new_string(max_accel.c_str()));
                }
                if (collection.has("max_z_velocity")){
                    auto& max_z_velocity = collection["max_z_velocity"];
                    json_object_object_add(obj, "max_z_velocity", json_object_new_string(max_z_velocity.c_str()));
                }
                if (collection.has("max_z_accel")){
                    auto& max_z_accel = collection["max_z_accel"];
                    json_object_object_add(obj, "max_z_accel", json_object_new_string(max_z_accel.c_str()));
                }
                if (collection.has("max_accel_to_decel")){
                    auto& max_accel_to_decel = collection["max_accel_to_decel"];
                    json_object_object_add(obj, "max_accel_to_decel", json_object_new_string(max_accel_to_decel.c_str()));
                }
                if (collection.has("square_corner_velocity")){
                    auto& square_corner_velocity = collection["square_corner_velocity"];
                    json_object_object_add(obj, "square_corner_velocity", json_object_new_string(square_corner_velocity.c_str()));
                }
                json_object_object_add(printerCfgInfo, "printer", obj);
            }
            if (cfg.has("prtouch")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["prtouch"];
                if (collection.has("z_offset")){
                    auto& z_offset = collection["z_offset"];
                    json_object_object_add(obj, "z_offset", json_object_new_string(z_offset.c_str()));
                }
                if (collection.has("min_hold")){
                    auto& min_hold = collection["min_hold"];
                    json_object_object_add(obj, "min_hold", json_object_new_string(min_hold.c_str()));
                }
                if (collection.has("max_hold")){
                    auto& max_hold = collection["max_hold"];
                    json_object_object_add(obj, "max_hold", json_object_new_string(max_hold.c_str()));
                }
                json_object_object_add(printerCfgInfo, "prtouch", obj);
            }
            json_object_object_add(reportPrinterConfig, "printerCfgInfo", printerCfgInfo);
            std::string send = json_object_to_json_string(reportPrinterConfig);
            json_object_put(reportPrinterConfig);
            return send;
        }else {
            CrLogI("read printer.cfg failed\n");
        }
    }else {
        CrLogI("no printer.cfg \n");
    }
    return "";
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {json_object*} req
 */
string CommondProc::SetPrinterConfigInfo(json_object *req)
{
    CrLogI("set printer config to printer.cfg");
    if (access(GetUserPrinterConfigFilePath(), F_OK) == 0){
        std::string path = GetUserPrinterConfigFilePath();
        mINI::INIFile file(path);
        mINI::INIStructure cfg;
        bool readSuccess = file.read(cfg);
        if(readSuccess){
            json_object *stepper_x = json_object_object_get(req, "stepper_x");
            if (stepper_x != NULL && json_object_is_type(stepper_x, json_type_object) && cfg.has("stepper_x")){
                auto& collection = cfg["stepper_x"];
                json_object *homing_speed = json_object_object_get(stepper_x, "homing_speed");
                if (homing_speed != NULL && json_object_is_type(homing_speed, json_type_string) && collection.has("homing_speed")){          
                    std::string value = json_object_get_string(homing_speed);
                    if(value != ""){
                        cfg["stepper_x"]["homing_speed"] = value;
                    }
                }
                json_object *position_max = json_object_object_get(stepper_x, "position_max");
                if (position_max != NULL && json_object_is_type(position_max, json_type_string) && collection.has("position_max")){
                    std::string value = json_object_get_string(position_max);
                    if(value != ""){
                        cfg["stepper_x"]["position_max"] = value;
                    }
                }
                json_object *position_min = json_object_object_get(stepper_x, "position_min");
                if (position_min != NULL && json_object_is_type(position_min, json_type_string) && collection.has("position_min")){
                    std::string value = json_object_get_string(position_min);
                    if(value != ""){
                        cfg["stepper_x"]["position_min"] = value;
                    }
                }
                json_object *position_endstop = json_object_object_get(stepper_x, "position_endstop");
                if (position_endstop != NULL && json_object_is_type(position_endstop, json_type_string) && collection.has("position_endstop")){
                    std::string value = json_object_get_string(position_endstop);
                    if(value != ""){
                        cfg["stepper_x"]["position_endstop"] = value;
                    }
                }
                json_object *microsteps = json_object_object_get(stepper_x, "microsteps");
                if (microsteps != NULL && json_object_is_type(microsteps, json_type_string) && collection.has("microsteps")){
                    std::string value = json_object_get_string(microsteps);
                    if(value != ""){
                        cfg["stepper_x"]["microsteps"] = value;
                    }
                }
                json_object *rotation_distance = json_object_object_get(stepper_x, "rotation_distance");
                if (rotation_distance != NULL && json_object_is_type(rotation_distance, json_type_string) && collection.has("rotation_distance")){
                    std::string value = json_object_get_string(rotation_distance);
                    if(value != ""){
                        cfg["stepper_x"]["rotation_distance"] = value;
                    }
                }
            }
            
            json_object *tmc2209_stepper_x = json_object_object_get(req, "tmc2209_stepper_x");
            if (tmc2209_stepper_x != NULL && json_object_is_type(tmc2209_stepper_x, json_type_object) && cfg.has("tmc2209 stepper_x")){
                auto& collection = cfg["tmc2209 stepper_x"];
                json_object *run_current = json_object_object_get(tmc2209_stepper_x, "run_current");
                if (run_current != NULL && json_object_is_type(run_current, json_type_string) && collection.has("run_current")){
                    std::string value = json_object_get_string(run_current);
                    if(value != ""){
                        cfg["tmc2209 stepper_x"]["run_current"] = value;
                    }
                }
                json_object *hold_current = json_object_object_get(tmc2209_stepper_x, "hold_current");
                if (hold_current != NULL && json_object_is_type(hold_current, json_type_string) && collection.has("hold_current")){
                    std::string value = json_object_get_string(hold_current);
                    if(value != ""){
                        cfg["tmc2209 stepper_x"]["hold_current"] = value;
                    }
                }
            }

            json_object *stepper_y = json_object_object_get(req, "stepper_y");
            if (stepper_y != NULL && json_object_is_type(stepper_y, json_type_object) && cfg.has("stepper_y")){
                auto& collection = cfg["stepper_y"];
                json_object *homing_speed = json_object_object_get(stepper_y, "homing_speed");
                if (homing_speed != NULL && json_object_is_type(homing_speed, json_type_string) && collection.has("homing_speed")){
                    std::string value = json_object_get_string(homing_speed);
                    if(value != ""){
                        cfg["stepper_y"]["homing_speed"] = value;
                    }
                }
                json_object *position_max = json_object_object_get(stepper_y, "position_max");
                if (position_max != NULL && json_object_is_type(position_max, json_type_string) && collection.has("position_max")){
                    std::string value = json_object_get_string(position_max);
                    if(value != ""){
                        cfg["stepper_y"]["position_max"] = value;
                    }
                }
                json_object *position_min = json_object_object_get(stepper_y, "position_min");
                if (position_min != NULL && json_object_is_type(position_min, json_type_string) && collection.has("position_min")){
                    std::string value = json_object_get_string(position_min);
                    if(value != ""){
                        cfg["stepper_y"]["position_min"] = value;
                    }
                }
                json_object *position_endstop = json_object_object_get(stepper_y, "position_endstop");
                if (position_endstop != NULL && json_object_is_type(position_endstop, json_type_string) && collection.has("position_endstop")){
                    std::string value = json_object_get_string(position_endstop);
                    if(value != ""){
                        cfg["stepper_y"]["position_endstop"] = value;
                    }
                }
                json_object *microsteps = json_object_object_get(stepper_y, "microsteps");
                if (microsteps != NULL && json_object_is_type(microsteps, json_type_string) && collection.has("microsteps")){
                    std::string value = json_object_get_string(microsteps);
                    if(value != ""){
                        cfg["stepper_y"]["microsteps"] = value;
                    }
                }
                json_object *rotation_distance = json_object_object_get(stepper_y, "rotation_distance");
                if (rotation_distance != NULL && json_object_is_type(rotation_distance, json_type_string) && collection.has("rotation_distance")){
                    std::string value = json_object_get_string(rotation_distance);
                    if(value != ""){
                        cfg["stepper_y"]["rotation_distance"] = value;
                    }
                }
            }

            json_object *tmc2209_stepper_y = json_object_object_get(req, "tmc2209_stepper_y");
            if (tmc2209_stepper_y != NULL && json_object_is_type(tmc2209_stepper_y, json_type_object) && cfg.has("tmc2209 stepper_y")){
                auto& collection = cfg["tmc2209 stepper_y"];
                json_object *run_current = json_object_object_get(tmc2209_stepper_y, "run_current");
                if (run_current != NULL && json_object_is_type(run_current, json_type_string) && collection.has("run_current")){
                    std::string value = json_object_get_string(run_current);
                    if(value != ""){
                        cfg["tmc2209 stepper_y"]["run_current"] = value;
                    }
                }
                json_object *hold_current = json_object_object_get(tmc2209_stepper_y, "hold_current");
                if (hold_current != NULL && json_object_is_type(hold_current, json_type_string) && collection.has("hold_current")){
                    std::string value = json_object_get_string(hold_current);
                    if(value != ""){
                        cfg["tmc2209 stepper_y"]["hold_current"] = value;
                    }
                }
            }

            json_object *stepper_z = json_object_object_get(req, "stepper_z");
            if (stepper_z != NULL && json_object_is_type(stepper_z, json_type_object) && cfg.has("stepper_z")){
                auto& collection = cfg["stepper_z"];
                json_object *homing_speed = json_object_object_get(stepper_z, "homing_speed");
                if (homing_speed != NULL && json_object_is_type(homing_speed, json_type_string) && collection.has("homing_speed")){
                    std::string value = json_object_get_string(homing_speed);
                    if(value != ""){
                        cfg["stepper_z"]["homing_speed"] = value;
                    }
                }
                json_object *position_max = json_object_object_get(stepper_z, "position_max");
                if (position_max != NULL && json_object_is_type(position_max, json_type_string) && collection.has("position_max")){
                    std::string value = json_object_get_string(position_max);
                    if(value != ""){
                        cfg["stepper_z"]["position_max"] = value;
                    }
                }
                json_object *position_min = json_object_object_get(stepper_z, "position_min");
                if (position_min != NULL && json_object_is_type(position_min, json_type_string) && collection.has("position_min")){
                    std::string value = json_object_get_string(position_min);
                    if(value != ""){
                        cfg["stepper_z"]["position_min"] = value;
                    }
                }
                json_object *position_endstop = json_object_object_get(stepper_z, "position_endstop");
                if (position_endstop != NULL && json_object_is_type(position_endstop, json_type_string) && collection.has("position_endstop")){
                    std::string value = json_object_get_string(position_endstop);
                    if(value != ""){
                        cfg["stepper_z"]["position_endstop"] = value;
                    }
                }
                json_object *microsteps = json_object_object_get(stepper_z, "microsteps");
                if (microsteps != NULL && json_object_is_type(microsteps, json_type_string) && collection.has("microsteps")){
                    std::string value = json_object_get_string(microsteps);
                    if(value != ""){
                        cfg["stepper_z"]["microsteps"] = value;
                    }
                }
                json_object *rotation_distance = json_object_object_get(stepper_z, "rotation_distance");
                if (rotation_distance != NULL && json_object_is_type(rotation_distance, json_type_string) && collection.has("rotation_distance")){
                    std::string value = json_object_get_string(rotation_distance);
                    if(value != ""){
                        cfg["stepper_z"]["rotation_distance"] = value;
                    }
                }
            }

            json_object *tmc2209_stepper_z = json_object_object_get(req, "tmc2209_stepper_z");
            if (tmc2209_stepper_z != NULL && json_object_is_type(tmc2209_stepper_z, json_type_object) && cfg.has("tmc2209 stepper_z")){
                auto& collection = cfg["tmc2209 stepper_z"];
                json_object *run_current = json_object_object_get(tmc2209_stepper_z, "run_current");
                if (run_current != NULL && json_object_is_type(run_current, json_type_string) && collection.has("run_current")){
                    std::string value = json_object_get_string(run_current);
                    if(value != ""){
                        cfg["tmc2209 stepper_z"]["run_current"] = value;
                    }
                }
                json_object *hold_current = json_object_object_get(tmc2209_stepper_z, "hold_current");
                if (hold_current != NULL && json_object_is_type(hold_current, json_type_string) && collection.has("hold_current")){
                    std::string value = json_object_get_string(hold_current);
                    if(value != ""){
                        cfg["tmc2209 stepper_z"]["hold_current"] = value;
                    }
                }
            }

            json_object *extruder = json_object_object_get(req, "extruder");
            if (extruder != NULL && json_object_is_type(extruder, json_type_object) && cfg.has("extruder")){
                auto& collection = cfg["extruder"];
                json_object *rotation_distance = json_object_object_get(extruder, "rotation_distance");
                if (rotation_distance != NULL && json_object_is_type(rotation_distance, json_type_string) && collection.has("rotation_distance")){
                    std::string value = json_object_get_string(rotation_distance);
                    if(value != ""){
                        cfg["extruder"]["rotation_distance"] = value;
                    }
                }
                json_object *microsteps = json_object_object_get(extruder, "microsteps");
                if (microsteps != NULL && json_object_is_type(microsteps, json_type_string) && collection.has("microsteps")){
                    std::string value = json_object_get_string(microsteps);
                    if(value != ""){
                        cfg["extruder"]["microsteps"] = value;
                    }
                }
                json_object *nozzle_diameter = json_object_object_get(extruder, "nozzle_diameter");
                if (nozzle_diameter != NULL && json_object_is_type(nozzle_diameter, json_type_string) && collection.has("nozzle_diameter")){
                    std::string value = json_object_get_string(nozzle_diameter);
                    if(value != ""){
                        cfg["extruder"]["nozzle_diameter"] = value;
                    }
                }
                json_object *filament_diameter = json_object_object_get(extruder, "filament_diameter");
                if (filament_diameter != NULL && json_object_is_type(filament_diameter, json_type_string) && collection.has("filament_diameter")){
                    std::string value = json_object_get_string(filament_diameter);
                    if(value != ""){
                        cfg["extruder"]["filament_diameter"] = value;
                    }
                }
                json_object *min_temp = json_object_object_get(extruder, "min_temp");
                if (min_temp != NULL && json_object_is_type(min_temp, json_type_string) && collection.has("min_temp")){
                    std::string value = json_object_get_string(min_temp);
                    if(value != ""){
                        cfg["extruder"]["min_temp"] = value;
                    }
                }
                json_object *max_temp = json_object_object_get(extruder, "max_temp");
                if (max_temp != NULL && json_object_is_type(max_temp, json_type_string) && collection.has("max_temp")){
                    std::string value = json_object_get_string(max_temp);
                    if(value != ""){
                        cfg["extruder"]["max_temp"] = value;
                    }
                }
                json_object *pressure_advance = json_object_object_get(extruder, "pressure_advance");
                if (pressure_advance != NULL && json_object_is_type(pressure_advance, json_type_string) && collection.has("pressure_advance")){
                    std::string value = json_object_get_string(pressure_advance);
                    if(value != ""){
                        cfg["extruder"]["pressure_advance"] = value;
                    }
                }
                json_object *pressure_advance_smooth_time = json_object_object_get(extruder, "pressure_advance_smooth_time");
                if (pressure_advance_smooth_time != NULL && json_object_is_type(pressure_advance_smooth_time, json_type_string) && collection.has("pressure_advance_smooth_time")){
                    std::string value = json_object_get_string(pressure_advance_smooth_time);
                    if(value != ""){
                        cfg["extruder"]["pressure_advance_smooth_time"] = value;
                    }
                }
                json_object *pid_Kp = json_object_object_get(extruder, "pid_Kp");
                if (pid_Kp != NULL && json_object_is_type(pid_Kp, json_type_string) && collection.has("pid_Kp")){
                    std::string value = json_object_get_string(pid_Kp);
                    if(value != ""){
                        cfg["extruder"]["pid_Kp"] = value;
                    }
                }
                json_object *pid_Ki = json_object_object_get(extruder, "pid_Ki");
                if (pid_Ki != NULL && json_object_is_type(pid_Ki, json_type_string) && collection.has("pid_Ki")){
                    std::string value = json_object_get_string(pid_Ki);
                    if(value != ""){
                        cfg["extruder"]["pid_Ki"] = value;
                    }
                }
                json_object *pid_Kd = json_object_object_get(extruder, "pid_Kd");
                if (pid_Kd != NULL && json_object_is_type(pid_Kd, json_type_string) && collection.has("pid_Kd")){
                    std::string value = json_object_get_string(pid_Kd);
                    if(value != ""){
                        cfg["extruder"]["pid_Kd"] = value;
                    }
                }
                json_object *max_power = json_object_object_get(extruder, "max_power");
                if (max_power != NULL && json_object_is_type(max_power, json_type_string) && collection.has("max_power")){
                    std::string value = json_object_get_string(max_power);
                    if(value != ""){
                        cfg["extruder"]["max_power"] = value;
                    }
                }
            }

            json_object *tmc2209_extruder = json_object_object_get(req, "tmc2209_extruder");
            if (tmc2209_extruder != NULL && json_object_is_type(tmc2209_extruder, json_type_object) && cfg.has("tmc2209 extruder")){
                auto& collection = cfg["tmc2209 extruder"];
                json_object *run_current = json_object_object_get(tmc2209_extruder, "run_current");
                if (run_current != NULL && json_object_is_type(run_current, json_type_string) && collection.has("run_current")){
                    std::string value = json_object_get_string(run_current);
                    if(value != ""){
                        cfg["tmc2209 extruder"]["run_current"] = value;
                    }
                }
                json_object *hold_current = json_object_object_get(tmc2209_extruder, "hold_current");
                if (hold_current != NULL && json_object_is_type(hold_current, json_type_string) && collection.has("hold_current")){
                    std::string value = json_object_get_string(hold_current);
                    if(value != ""){
                        cfg["tmc2209 extruder"]["hold_current"] = value;
                    }
                }
            }

            json_object *heater_fan_hotend_fan = json_object_object_get(req, "heater_fan_hotend_fan");
            if (heater_fan_hotend_fan != NULL && json_object_is_type(heater_fan_hotend_fan, json_type_object) && cfg.has("heater_fan hotend_fan")){
                auto& collection = cfg["heater_fan hotend_fan"];
                json_object *heater_temp = json_object_object_get(heater_fan_hotend_fan, "heater_temp");
                if (heater_temp != NULL && json_object_is_type(heater_temp, json_type_string) && collection.has("heater_temp")){
                    std::string value = json_object_get_string(heater_temp);
                    if(value != ""){
                        cfg["heater_fan hotend_fan"]["heater_temp"] = value;
                    }
                }
            }

            json_object *heater_bed = json_object_object_get(req, "heater_bed");
            if (heater_bed != NULL && json_object_is_type(heater_bed, json_type_object) && cfg.has("heater_bed")){
                auto& collection = cfg["heater_bed"];
                json_object *pid_Kp = json_object_object_get(heater_bed, "pid_Kp");
                if (pid_Kp != NULL && json_object_is_type(pid_Kp, json_type_string) && collection.has("pid_Kp")){
                    std::string value = json_object_get_string(pid_Kp);
                    if(value != ""){
                        cfg["heater_bed"]["pid_Kp"] = value;
                    }
                }
                json_object *pid_Ki = json_object_object_get(heater_bed, "pid_Ki");
                if (pid_Ki != NULL && json_object_is_type(pid_Ki, json_type_string) && collection.has("pid_Ki")){
                    std::string value = json_object_get_string(pid_Ki);
                    if(value != ""){
                        cfg["heater_bed"]["pid_Ki"] = value;
                    }
                }
                json_object *pid_Kd = json_object_object_get(heater_bed, "pid_Kd");
                if (pid_Kd != NULL && json_object_is_type(pid_Kd, json_type_string) && collection.has("pid_Kd")){
                    std::string value = json_object_get_string(pid_Kd);
                    if(value != ""){
                        cfg["heater_bed"]["pid_Kd"] = value;
                    }
                }
                json_object *min_temp = json_object_object_get(heater_bed, "min_temp");
                if (min_temp != NULL && json_object_is_type(min_temp, json_type_string) && collection.has("min_temp")){
                    std::string value = json_object_get_string(min_temp);
                    if(value != ""){
                        cfg["heater_bed"]["min_temp"] = value;
                    }
                }
                json_object *max_temp = json_object_object_get(heater_bed, "max_temp");
                if (max_temp != NULL && json_object_is_type(max_temp, json_type_string) && collection.has("max_temp")){
                    std::string value = json_object_get_string(max_temp);
                    if(value != ""){
                        cfg["heater_bed"]["max_temp"] = value;
                    }
                }
                json_object *max_power = json_object_object_get(heater_bed, "max_power");
                if (max_power != NULL && json_object_is_type(max_power, json_type_string) && collection.has("max_power")){
                    std::string value = json_object_get_string(max_power);
                    if(value != ""){
                        cfg["heater_bed"]["max_power"] = value;
                    }
                }
            }

            json_object *bed_mesh = json_object_object_get(req, "bed_mesh");
            if (bed_mesh != NULL && json_object_is_type(bed_mesh, json_type_object) && cfg.has("bed_mesh")){
                auto& collection = cfg["bed_mesh"];
                json_object *speed = json_object_object_get(bed_mesh, "speed");
                if (speed != NULL && json_object_is_type(speed, json_type_string) && collection.has("speed")){
                    std::string value = json_object_get_string(speed);
                    if(value != ""){
                        cfg["bed_mesh"]["speed"] = value;
                    }
                }
                json_object *mesh_min = json_object_object_get(bed_mesh, "mesh_min");
                if (mesh_min != NULL && json_object_is_type(mesh_min, json_type_string) && collection.has("mesh_min")){
                    std::string value = json_object_get_string(mesh_min);
                    if(value != ""){
                        cfg["bed_mesh"]["mesh_min"] = value;
                    }
                }
                json_object *mesh_max = json_object_object_get(bed_mesh, "mesh_max");
                if (mesh_max != NULL && json_object_is_type(mesh_max, json_type_string) && collection.has("mesh_max")){
                    std::string value = json_object_get_string(mesh_max);
                    if(value != ""){
                        cfg["bed_mesh"]["mesh_max"] = value;
                    }
                }
                json_object *probe_count = json_object_object_get(bed_mesh, "probe_count");
                if (probe_count != NULL && json_object_is_type(probe_count, json_type_string) && collection.has("probe_count")){
                    std::string value = json_object_get_string(probe_count);
                    if(value != ""){
                        cfg["bed_mesh"]["probe_count"] = value;
                    }
                }
                json_object *horizontal_move_z = json_object_object_get(bed_mesh, "horizontal_move_z");
                if (horizontal_move_z != NULL && json_object_is_type(horizontal_move_z, json_type_string) && collection.has("horizontal_move_z")){
                    std::string value = json_object_get_string(horizontal_move_z);
                    if(value != ""){
                        cfg["bed_mesh"]["horizontal_move_z"] = value;
                    }
                }
            }

            json_object *printer = json_object_object_get(req, "printer");
            if (printer != NULL && json_object_is_type(printer, json_type_object) && cfg.has("printer")){
                auto& collection = cfg["printer"];
                json_object *max_velocity = json_object_object_get(printer, "max_velocity");
                if (max_velocity != NULL && json_object_is_type(max_velocity, json_type_string) && collection.has("max_velocity")){
                    std::string value = json_object_get_string(max_velocity);
                    if(value != ""){
                        cfg["printer"]["max_velocity"] = value;
                    }
                }
                json_object *max_accel = json_object_object_get(printer, "max_accel");
                if (max_accel != NULL && json_object_is_type(max_accel, json_type_string) && collection.has("max_accel")){
                    std::string value = json_object_get_string(max_accel);
                    if(value != ""){
                        cfg["printer"]["max_accel"] = value;
                    }
                }
                json_object *max_z_velocity = json_object_object_get(printer, "max_z_velocity");
                if (max_z_velocity != NULL && json_object_is_type(max_z_velocity, json_type_string) && collection.has("max_z_velocity")){
                    std::string value = json_object_get_string(max_z_velocity);
                    if(value != ""){
                        cfg["printer"]["max_z_velocity"] = value;
                    }
                }
                json_object *max_z_accel = json_object_object_get(printer, "max_z_accel");
                if (max_z_accel != NULL && json_object_is_type(max_z_accel, json_type_string) && collection.has("max_z_accel")){
                    std::string value = json_object_get_string(max_z_accel);
                    if(value != ""){
                        cfg["printer"]["max_z_accel"] = value;
                    }
                }
                json_object *max_accel_to_decel = json_object_object_get(printer, "max_accel_to_decel");
                if (max_accel_to_decel != NULL && json_object_is_type(max_accel_to_decel, json_type_string) && collection.has("max_accel_to_decel")){
                    std::string value = json_object_get_string(max_accel_to_decel);
                    if(value != ""){
                        cfg["printer"]["max_accel_to_decel"] = value;
                    }
                }
                json_object *square_corner_velocity = json_object_object_get(printer, "square_corner_velocity");
                if (square_corner_velocity != NULL && json_object_is_type(square_corner_velocity, json_type_string) && collection.has("square_corner_velocity")){
                    std::string value = json_object_get_string(square_corner_velocity);
                    if(value != ""){
                        cfg["printer"]["square_corner_velocity"] = value;
                    }
                }
            }

            json_object *prtouch = json_object_object_get(req, "prtouch");
            if (prtouch != NULL && json_object_is_type(prtouch, json_type_object) && cfg.has("prtouch")){
                auto& collection = cfg["prtouch"];
                json_object *z_offset = json_object_object_get(prtouch, "z_offset");
                if (z_offset != NULL && json_object_is_type(z_offset, json_type_string) && collection.has("z_offset")){
                    std::string value = json_object_get_string(z_offset);
                    if(value != ""){
                        cfg["prtouch"]["z_offset"] = value;
                    }
                }
                json_object *min_hold = json_object_object_get(prtouch, "min_hold");
                if (min_hold != NULL && json_object_is_type(min_hold, json_type_string) && collection.has("min_hold")){
                    std::string value = json_object_get_string(min_hold);
                    if(value != ""){
                        cfg["prtouch"]["min_hold"] = value;
                    }
                }
                json_object *max_hold = json_object_object_get(prtouch, "max_hold");
                if (max_hold != NULL && json_object_is_type(max_hold, json_type_string) && collection.has("max_hold")){
                    std::string value = json_object_get_string(max_hold);
                    if(value != ""){
                        cfg["prtouch"]["max_hold"] = value;
                    }
                }
            }

            bool writeSuccess = file.write(cfg, true);
            if(writeSuccess){
                return ReportPrinterConfigInfo();
            }else{
                CrLogI("write printer.cfg failed \n");
            }
        }
    }else{
        CrLogI("no printer.cfg \n");
    }
    return "";
}

string CommondProc::RemoveProbedMatrix()
{
    CrLogI("remove [bed_mesh default] from printer.cfg");
    if (access(GetUserPrinterConfigFilePath(), F_OK) == 0){
        std::string path = GetUserPrinterConfigFilePath();
        mINI::INIFile file(path);
        mINI::INIStructure cfg;
        bool readSuccess = file.read(cfg);
        if(readSuccess){
            if (cfg.has("bed_mesh default")){
                bool removeSuccess = cfg.remove("bed_mesh default");
                if(removeSuccess){
                    bool writeSuccess = file.write(cfg, true);
                    if(writeSuccess){
                        return ReportProbedMatrix();
                    }else{
                        CrLogI("write printer.cfg failed \n");
                    }
                }else{
                    CrLogI("remove [bed_mesh default] failed \n");
                }
            }
        }else{
            CrLogI("read printer.cfg failed\n");
        }
    }else{
        CrLogI("no printer.cfg \n");
    }
    return "";
}

string CommondProc::ReportProbedMatrix()
{
    CrLogI("get probed matrix from printer.cfg");

    if (access(GetUserPrinterConfigFilePath(), F_OK) == 0){
        std::string path = GetUserPrinterConfigFilePath();
        mINI::INIFile file(path);
        mINI::INIStructure cfg;
        bool readSuccess  = file.read(cfg);
        int pointsX = 0;
        int pointsY = 0;
        if(readSuccess){
            json_object *reportProbedMatrix = json_object_new_object();
            if (cfg.has("bed_mesh default")){
                json_object *obj = json_object_new_object();
                auto& collection = cfg["bed_mesh default"];
                if (collection.has("x_count") && collection.has("y_count")){
                    auto& x_count = collection["x_count"];
                    auto& y_count = collection["y_count"];
                    pointsX = atoi(x_count.c_str());
                    pointsY = atoi(y_count.c_str());
                    json_object_object_add(obj, "num", json_object_new_int(pointsX * pointsY));
                    if (collection.has("points") && collection.has("min_x") && collection.has("min_y") 
                        && collection.has("max_x") && collection.has("max_y")){
                        auto& points = collection["points"];
                        auto& min_x = collection["min_x"];
                        auto& min_y = collection["min_y"];
                        auto& max_x = collection["max_x"];
                        auto& max_y = collection["max_y"];
                        float x_step = (atof(max_x.c_str()) - atof(min_x.c_str())) / (atoi(x_count.c_str()) - 1);
                        float y_step = (atof(max_y.c_str()) - atof(min_y.c_str())) / (atoi(y_count.c_str()) - 1);
                        mINI::INIStringUtil::replace(points, "\n#*# \t  ", ", ");
                        points = points.substr(2);
                        json_object *arrayObj = json_object_new_array();
                        for(int i = 0; i < pointsY; i++){
                            auto yStr = std::to_string(atof(min_y.c_str()) + y_step * i);
                            for(int j = 0; j < pointsX; j++){
                                auto separateAt = points.find(", ");
                                auto zStr = points.substr(0, separateAt);
                                auto xStr = std::to_string(atof(min_x.c_str()) + x_step * j);
                                points = points.substr(separateAt + 2);
                                json_object *xyzPoints = json_object_new_object();
                                json_object_object_add(xyzPoints, "x", json_object_new_string(xStr.c_str()));
                                json_object_object_add(xyzPoints, "y", json_object_new_string(yStr.c_str()));
                                json_object_object_add(xyzPoints, "z", json_object_new_string(zStr.c_str()));
                                json_object_array_add(arrayObj, xyzPoints);
                                
                            }
                        }
                        json_object_object_add(obj, "val", arrayObj);
                    }  
                }       
                json_object_object_add(reportProbedMatrix, "probedMatrix", obj);
            }else{
                json_object_object_add(reportProbedMatrix, "probedMatrix", json_object_new_string(""));
            }
            std::string send = json_object_to_json_string(reportProbedMatrix);
            json_object_put(reportProbedMatrix);
            return send;           
        }
    }
    return "";
}

int CommondProc::ProcVideoRemove(std::string prindId,std::string file)
{
    CrLogI("ProcVideoRemove file = %s\n", file.c_str());
    FileControl fcon = FILE_CONTROL__INIT;
    fcon.has_cmd = 1;
    fcon.cmd = 3;
    fcon.has_printid = 1;
    fcon.printid.data = (uint8_t*)const_cast<char *>(prindId.c_str());
    fcon.printid.len = prindId.length();
    fcon.has_file = 1;
    fcon.file.data = (uint8_t*)const_cast<char*>(file.c_str());
    fcon.file.len = file.length();
    GET_MESSAGE_BUFF(buf);
    size_t len = file_control__pack(&fcon, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_LOCAL_VIDEO, buf, len);
    SendProcessMsgBuff(&send, size);
}

int CommondProc::ProcVideoRename(std::string prindId,std::string file,std::string targetname)
{
    CrLogI("ProcVideoRename file = %s to %s\n", file.c_str(), targetname.c_str());
    FileControl fcon = FILE_CONTROL__INIT;
    fcon.has_cmd = 1;
    fcon.cmd = 2;
    fcon.has_printid = 1;
    fcon.printid.data = (uint8_t*)const_cast<char*>(prindId.c_str());
    fcon.printid.len = prindId.length();
    fcon.has_file = 1;
    fcon.file.data = (uint8_t*)const_cast<char*>(file.c_str());
    fcon.file.len = file.length();
    fcon.has_param1 = 1;
    fcon.param1.data = (uint8_t*)const_cast<char*>(targetname.c_str());
    fcon.param1.len = targetname.length();
    GET_MESSAGE_BUFF(buf);
    size_t len = file_control__pack(&fcon, buf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_LOCAL_VIDEO, buf, len);
    SendProcessMsgBuff(&send, size);
}

string CommondProc::ReportGetRateLocal(std::string feed, std::string flow)
{
    json_object *localInfo = json_object_new_object();
    json_object_object_add(localInfo, "curFeedratePct", json_object_new_string(feed.c_str()));
    json_object_object_add(localInfo, "curFlowratePct", json_object_new_string(flow.c_str()));
    std::string send = json_object_to_json_string(localInfo);
    json_object_put(localInfo);
    
    return send;
}

string CommondProc::ReportGetCurrentLocal(std::string local)
{
    // 发布喷嘴当前位置信息到WEB
    json_object *localInfo = json_object_new_object();
    json_object_object_add(localInfo, "curPosition", json_object_new_string(local.c_str()));   
    char autoHome[16] = {0};
    GLOBAL_INFO * globalinfo = AttributeProc::getInstance()->getGlobalInfo();
    snprintf(autoHome, 100, "X:%d Y:%d Z:%d", globalinfo->homedAxes.x, globalinfo->homedAxes.y,globalinfo->homedAxes.z);
    json_object_object_add(localInfo, "autohome", json_object_new_string(autoHome));
    double temp = globalinfo->axisRecoup.z/1000.000;
    char axisRecoup[16] = {0};
    snprintf(axisRecoup, 16, "%.3f",temp);
    json_object_object_add(localInfo, "curZOffset", json_object_new_string(axisRecoup));   
    std::string send = json_object_to_json_string(localInfo);
    json_object_put(localInfo);

    return send;
}

string CommondProc::ReportGcodeFileInfo(std::string path)
{
    std::string fileInfoStr;
    json_object *localFileObj = json_object_from_file(path.c_str());
    if(localFileObj){
        int totalNum = json_object_array_length(localFileObj);
        int fileNum = 0;
        for (int i = 0; i < totalNum; i++) {
            json_object *elem = json_object_array_get_idx(localFileObj, i);
            int type = json_object_get_int(json_object_object_get(elem, "type"));
            if(type == 8 && json_object_object_get(elem, "name")
            &&json_object_object_get(elem, "path")
            &&json_object_object_get(elem, "file_size")
            &&json_object_object_get(elem, "floorHeight")
            &&json_object_object_get(elem, "create_time")
            &&json_object_object_get(elem, "consumables")
            &&json_object_object_get(elem, "thumbnail")){
                std::string name = json_object_get_string(json_object_object_get(elem, "name"));
                std::string path = json_object_get_string(json_object_object_get(elem, "path"));
                fileInfoStr = fileInfoStr + path.substr(0,path.find(name)-1) + ":";
                fileInfoStr = fileInfoStr + name + ":";
                int32_t size = json_object_get_int(json_object_object_get(elem, "file_size"));
                fileInfoStr = fileInfoStr + std::to_string(size) + ":";
                float height = json_object_get_double(json_object_object_get(elem, "floorHeight")) / 100;
                fileInfoStr = fileInfoStr + std::to_string(height) + ":";
                int32_t cTime = json_object_get_int(json_object_object_get(elem, "create_time"));
                fileInfoStr = fileInfoStr + std::to_string(cTime) + ":";
                int32_t consumables = json_object_get_int(json_object_object_get(elem, "consumables"));
                fileInfoStr = fileInfoStr + std::to_string(consumables) + ":";
                std::string thumbnail = json_object_get_string(json_object_object_get(elem, "thumbnail"));
                fileInfoStr = fileInfoStr + thumbnail + ";";
                fileNum ++;
                CrLogI("fileName = %s", path.c_str());
            }
        }
        // 发布文件列表信息到WEB
        json_object *fileList = json_object_new_object();
        json_object_object_add(fileList, "totalNum", json_object_new_int(fileNum));
        //json_object_object_add(fileList, "pageindex", json_object_new_int(index));
        json_object_object_add(fileList, "fileInfo", json_object_new_string(fileInfoStr.c_str()));
        json_object *repostGcodeList = json_object_new_object();
        json_object_object_add(repostGcodeList, "retGcodeFileInfo", fileList);
        std::string send = json_object_to_json_string(repostGcodeList);
        CrLogI("send gcodes = %s", send.c_str());
        json_object_put(repostGcodeList);
        json_object_put(localFileObj);
        return send;
    }
    return "";
}

string CommondProc::ReportHistoryInfo()
{
    CrLogI("get history record from file");
    // 判断历史记录是否存在，读取文件，获取json数据
    if (access(GetuserPrintHistoryRecordPtah(), F_OK) == 0){
        json_object *historyRecord = json_object_from_file(GetuserPrintHistoryRecordPtah());
        if (historyRecord) {
            // 提取历史记录列表
            json_object *listObj = json_object_object_get(historyRecord, "list");
            int recordSize = json_object_array_length(listObj);
            int totalUsageTime = 0;
            int totalUsageMaterial = 0;
            CrLogI("recordSize = %d", recordSize);
            for (int i = 0; i < recordSize; i++){
                json_object *record = json_object_array_get_idx(listObj, i);
                int usagetime = json_object_get_int(json_object_object_get(record, "usagetime"));
                totalUsageTime = totalUsageTime + usagetime;
                int usagematerial = json_object_get_int(json_object_object_get(record, "usagematerial"));
                totalUsageMaterial = totalUsageMaterial + usagematerial;
            }
            // 发布历史文件列表信息到WEB
            json_object *reportHistoryList = json_object_new_object();
            json_object_object_add(reportHistoryList, "totalJob", json_object_new_int(recordSize));
            json_object_object_add(reportHistoryList, "totalUsageTime", json_object_new_int(totalUsageTime));
            json_object_object_add(reportHistoryList, "totalUsageMaterial", json_object_new_int(totalUsageMaterial));
            json_object_object_add(reportHistoryList, "historyList", listObj);
            std::string send = json_object_to_json_string(reportHistoryList);
            json_object_put(reportHistoryList);
            return send;
        }else {
            CrLogW("read json object fail\n");
        }
    }else {
        CrLogI("no history record\n");
    }
    return "";
}

string CommondProc::ReportElapseVideoInfo()
{
    CrLogI("get elapse list from file");

    if (access(GetUserDelayImageInfoPtah(), F_OK) == 0){
        json_object *delayImage = json_object_from_file(GetUserDelayImageInfoPtah());
        if (delayImage) {
            json_object *listObj = json_object_object_get(delayImage, "list");
            int listSize = json_object_array_length(listObj);
            CrLogI("listSize = %d", listSize);
            json_object *reportElapseVideoList = json_object_new_object();
            json_object_object_add(reportElapseVideoList, "elapseVideoList", listObj);
            std::string send = json_object_to_json_string(reportElapseVideoList);
            json_object_put(reportElapseVideoList);
            return send;
        }
        else {
            CrLogW("read json object fail\n");
        }
    }
    else CrLogI("no history record\n");
    return "";
}

int CommondProc::SyncUploadLogState(int state, int progress)
{
    ExportLogState sync = EXPORT_LOG_STATE__INIT;
    sync.state = state;
    sync.progress = progress;

    GET_MESSAGE_BUFF(buff);
    size_t len = export_log_state__pack(&sync, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_SYNC_EXPORT_LOG_STATE, buff, len);
    SendProcessMsgBuff(&send, size);
}

string CommondProc::fanProc(json_object *val,int sockedId)
{
    int fan = JsonInter::getintdirect(val);
    CrLogI("property id: fan, value: %d", fan);
    MultiFan multiFan = MULTI_FAN__INIT;
    multiFan.has_multi_fan_model = 1;
    if (fan == 0) multiFan.multi_fan_model = 0;
    else multiFan.multi_fan_model = 100;
    
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.fan = &multiFan;

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::fanCaseProc(json_object *val,int sockedId)
{
    int fan = JsonInter::getintdirect(val);
    CrLogI("property id: fanCase, value: %d\n", fan);

    MultiFan multiFan = MULTI_FAN__INIT;
    multiFan.has_multi_fan_case = 1;
    if (fan == 0) multiFan.multi_fan_case = 0;
    else multiFan.multi_fan_case = 100;
    
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.fan = &multiFan;

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::fanAuxiliaryProc(json_object *val,int sockedId)
{
    int fan = JsonInter::getintdirect(val);
    CrLogI("property id: fanAuxiliary, value: %d\n", fan);

    MultiFan multiFan = MULTI_FAN__INIT;
    multiFan.has_multi_fan_auxiliary = 1;
    if (fan == 0) multiFan.multi_fan_auxiliary = 0;
    else multiFan.multi_fan_auxiliary = 100;
    
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.fan = &multiFan;

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::nozzleTempControlProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);

    CrLogI("property id: nozzleTempControl, value: %d\n", setval);
    Extruder extruder = EXTRUDER__INIT;
    extruder.has_extruder = 1;
    extruder.extruder = setval;

    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.nozzletemp = &extruder;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::bedTempControlProc(json_object *val,int sockedId)
{
    json_object *bedTempControl = val;
    if (bedTempControl != NULL && json_object_is_type(bedTempControl, json_type_object)){
        json_object *num = json_object_object_get(bedTempControl, "num");
        json_object *val = json_object_object_get(bedTempControl, "val");
        if (num != NULL && json_object_is_type(num, json_type_int) && val != NULL && json_object_is_type(val, json_type_int)){
            CrLogI("property id: bedTempControl, num: %d val: %d\n", json_object_get_int(num), json_object_get_int(val));
            HeaterBed heaterBed = HEATER_BED__INIT;
            switch (json_object_get_int(num)){
                case 0:
                    if (AttributeProc::getInstance()->getGlobalInfo()->sysmodel == CR_10_H1) {
                        heaterBed.has_heater_bed_0 = 1;
                        heaterBed.heater_bed_0 = json_object_get_int(val);
                    }
                    else {
                        heaterBed.has_heater_bed = 1;
                        heaterBed.heater_bed = json_object_get_int(val);
                    }
                    break;
                case 1:
                    heaterBed.has_heater_bed_1 = 1;
                    heaterBed.heater_bed_1 = json_object_get_int(val);
                    break;
                case 2:
                    heaterBed.has_heater_bed_2 = 1;
                    heaterBed.heater_bed_2 = json_object_get_int(val);
                    break;
                default:
                    break;                
            }
            WebControlPrint control = WEB_CONTROL_PRINT__INIT;
            control.bedtemp = &heaterBed;
            
            GET_MESSAGE_BUFF(buff);
            size_t len = web_control_print__pack(&control, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
            SendProcessMsgBuff(&send, size);
        }
    }
    return "";
}

string CommondProc::stopProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);

    CrLogI("property id: stop, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_stop = 1;
    control.stop = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::pauseProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: pause, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_pause = 1;
    control.pause = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::repoPlrStatusProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: repoPlrStatus, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_offcontinue = 1;
    control.offcontinue = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size); 
    return "";   
}

string CommondProc::gcodeCmdProc(json_object *val,int sockedId)
{
    string setval = JsonInter::getstringdirect(val);
    CrLogI("property id: gcodeCmd, value: %s\n", setval.c_str());
    
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_gcodecmd = 1;
    control.gcodecmd.data = (uint8_t*)const_cast<char*>(setval.c_str());
    control.gcodecmd.len = setval.size() + 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::setFeedratePctProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    char paraBuff[256] = {0};
    CrLogI("property id: setFeedratePct, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    snprintf(paraBuff, 256, "S%d", setval);
    CrLogI("property id: setFeedratePct, value: %s\n", paraBuff);
    control.has_setfeedratepct = 1;
    control.setfeedratepct.data = (uint8_t*)paraBuff;
    control.setfeedratepct.len = strlen(paraBuff) + 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::setFlowratePctProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    char paraBuff[256] = {0};
    CrLogI("property id: setFlowratePct, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    snprintf(paraBuff, 256, "S%d", setval);
    control.has_setflowratepct = 1;
    control.setflowratepct.data = (uint8_t*)paraBuff;
    control.setflowratepct.len = strlen(paraBuff) + 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::setPositionProc(json_object *val,int sockedId)
{
    string setval = JsonInter::getstringdirect(val);
    CrLogI("property id: setPosition, value: %s\n", setval.c_str());
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_setposition = 1;
    control.setposition.data = (uint8_t*)const_cast<char*>(setval.c_str());
    control.setposition.len = setval.size() + 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::autohomeProc(json_object *val,int sockedId)
{
    string setval = JsonInter::getstringdirect(val);

    CrLogI("property id: autohome, value: %s\n", setval.c_str());
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_autohome = 1;
    control.autohome.data = (uint8_t*)const_cast<char*>(setval.c_str());
    control.autohome.len = setval.size() + 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::enableSelfTestProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: enableSelfTest, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_enableselftest = 1;
    control.enableselftest = setval;

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::opGcodeFileProc(json_object *val,int sockedId)
{
    string setval = JsonInter::getstringdirect(val);
    CrLogI("property id: opGcodeFile, value: %s\n", setval.c_str());
    char * valuestring = const_cast<char*>(setval.c_str());
    GLOBAL_INFO * globalinfo = AttributeProc::getInstance()->getGlobalInfo();
    if(strstr(valuestring , "printprt:") != NULL){
        char * pTemp = strstr(valuestring, ":") + 1;
        CrLogI("property id: pTemp, value: %s\n", pTemp);
        WebControlPrint control = WEB_CONTROL_PRINT__INIT;
        control.has_print = 1;
        control.print.data = (uint8_t*)pTemp;
        control.print.len = strlen(pTemp) + 1;
        
        GET_MESSAGE_BUFF(buff);
        size_t len = web_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }else if(strstr(valuestring , "renameprt:") != NULL){
        std::string pTemp = strstr(valuestring, ":") + 1;
        CrLogI("property id: pTemp, value: %s\n", pTemp.c_str());

        int pos= pTemp.find(":");
        std::string target = pTemp.substr(pos+1, pTemp.length()); 
        std::string source = pTemp.substr(0, pos);
        CrLogI("source = %s", source.c_str());
        CrLogI("target = %s\n", target.c_str());

        // 判断文件路径是否合法
        if(source.find(globalinfo->sdPath) == 0 && target.find(globalinfo->sdPath) == 0)
        {
            rename(source.c_str(), target.c_str());
            system("sync");
        }
        else CrLogW("illegal file name\n");
    }else if(strstr(valuestring , "deleteprt:") != NULL){
        string pTemp = string(strstr(valuestring, ":") + 1);
        CrLogI("property id: pTemp, value: %s\n", pTemp.c_str());
        // 判断文件路径是否合法
        if(pTemp.find(globalinfo->sdPath) == 0 || pTemp.find(globalinfo->uDiskPath) == 0)
        {
            remove(pTemp.c_str());
            system("sync");
        }
        else CrLogW("illegal file name\n");
    }
    return "";
}

string CommondProc::setZOffsetProc(json_object *val,int sockedId)
{
    string setval = JsonInter::getstringdirect(val);

    CrLogI("property id: zOffset, value: %s\n", setval.c_str());
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_axisrecoup = 1;
    control.axisrecoup.data = (uint8_t*)const_cast<char*>(setval.c_str());
    control.axisrecoup.len = setval.size() + 1;   

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::motorLockProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: motorLock, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_motorlock = 1;
    control.motorlock = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::heatersOffProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: heatersOff, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_heatersoff = 1;
    control.heatersoff = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::velocityLimitsProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: velocityLimits, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    char * pTemp =  (char *)std::to_string(setval).c_str();
    control.has_velocitylimits = 1;
    control.velocitylimits.data = (uint8_t*)pTemp;
    control.velocitylimits.len = strlen(pTemp) + 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::accelerationLimitsProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);

    CrLogI("property id: accelerationLimits, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    char * pTemp =  (char *)std::to_string(setval).c_str();
    control.has_accelerationlimits = 1;
    control.accelerationlimits.data = (uint8_t*)pTemp;
    control.accelerationlimits.len = strlen(pTemp) + 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::cornerVelocityLimitsProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: cornerVelocityLimits, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    char * pTemp =  (char *)std::to_string(setval).c_str();
    control.has_cornervelocitylimits = 1;
    control.cornervelocitylimits.data = (uint8_t*)pTemp;
    control.cornervelocitylimits.len = strlen(pTemp) + 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::accelToDecelLimitsProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: accelToDecelLimits, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    char * pTemp =  (char *)std::to_string(setval).c_str();
    control.has_acceltodecellimits = 1;
    control.acceltodecellimits.data = (uint8_t*)pTemp;
    control.acceltodecellimits.len = strlen(pTemp) + 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::pressureAdvanceProc(json_object *val,int sockedId)
{
    string setval = JsonInter::getstringdirect(val);
    CrLogI("property id: pressureAdvance, value: %s\n", setval.c_str());
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_pressureadvance = 1;
    control.pressureadvance.data = (uint8_t*)const_cast<char*>(setval.c_str());
    control.pressureadvance.len = setval.size() + 1;  

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::smoothTimeProc(json_object *val,int sockedId)
{
    string setval = JsonInter::getstringdirect(val);
    CrLogI("property id: smoothTime, value: %s\n", setval.c_str());
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_smoothtime = 1;
    control.smoothtime.data = (uint8_t*)const_cast<char*>(setval.c_str());
    control.smoothtime.len = setval.size() + 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::videoElapseProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: videoElapse, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_videoelapse = 1;
    control.videoelapse = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::nozzleMoveSnapshotProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);

    CrLogI("property id: nozzleMoveSnapshot, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_nozzlemovesnapshot = 1;
    control.nozzlemovesnapshot = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::videoElapseFrameProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: videoElapseFrame, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_videoelapseframe = 1;
    control.videoelapseframe = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::videoElapseIntervalProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: videoElapseInterval, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_videoelapseinterval = 1;
    control.videoelapseinterval = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::bedTempAutoPidProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: bedTempAutoPid, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_bedtempautopid = 1;
    control.bedtempautopid = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::nozzleTempAutoPidProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: nozzleTempAutoPid, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_nozzletempautopid = 1;
    control.nozzletempautopid = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::startAutoPidProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: startAutoPid, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_startautopid = 1;
    control.startautopid = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::materialDetectProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: materialDetect, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    char * pTemp =  (char *)std::to_string(setval).c_str();
    control.has_materialdetect = 1;
    control.materialdetect.data = (uint8_t*)pTemp;
    control.materialdetect.len = strlen(pTemp) + 1;

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::powerLossSwProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);

    CrLogI("property id: powerLossSw, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_powerlosssw = 1;
    control.powerlosssw = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
}

string CommondProc::resonanceTestProc(json_object *val,int sockedId)
{
    string setval = JsonInter::getstringdirect(val);
    
    CrLogI("property id: resonanceTest, value: %s\n", setval.c_str());
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_resonancetest = 1;
    control.resonancetest.data = (uint8_t*)const_cast<char*>(setval.c_str());
    control.resonancetest.len = setval.size() + 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::manualLevelProc(json_object *val,int sockedId)
{
    string setval = JsonInter::getstringdirect(val);

    CrLogI("property id: manualLevel, value: %s\n", setval.c_str());
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_manuallevel = 1;
    control.manuallevel.data = (uint8_t*)const_cast<char*>(setval.c_str());
    control.manuallevel.len = setval.size() + 1;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::autoLevelProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: autoLevel, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_autolevel = 1;
    control.autolevel = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::restartKlipperProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: restartKlipper, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_restartklipper = 1;
    control.restartklipper = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::restartFirmwareProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: restartFirmware, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_restartfirmware = 1;
    control.restartfirmware = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::resetSystemProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: resetSystem, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_resetsystem = 1;
    control.resetsystem = setval;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::exportLogProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    int ctl = setval;
    CrLogI("property id: exportLog, value: %d\n", ctl);
    if(ctl == 1){
        char *savePath = NULL;
        Remove7zPackges();
        SyncUploadLogState(COMPRESSING_LOG, 0);
        savePath = UserExportLog();
        if(savePath) SyncUploadLogState(EXPORT_LOG_SUCCESS, 0);
        else SyncUploadLogState(EXPORT_LOG_FAIL, 0);
        return ReportExportLogInfo(savePath);
    }
    return "";
}

string CommondProc::linuxUpgradeProc(json_object *val,int sockedId)
{
    string value = JsonInter::getstringdirect(val);
    CrLogI("property id: linuxUpgrade, value: %s\n", value.c_str());
    if(value != ""){
        WebControlPrint control = WEB_CONTROL_PRINT__INIT;      
        UpgradeInfo otaInfo = UPGRADE_INFO__INIT;
        otaInfo.has_url = 1;
        otaInfo.url.data = (uint8_t*)const_cast<char*>(value.c_str());
        otaInfo.url.len = value.size() + 1;
        control.upgrade->linuxota = &otaInfo;        
        
        GET_MESSAGE_BUFF(buff);
        size_t len = web_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    } 
    return "";
}

string CommondProc::mcuUpgradeProc(json_object *val,int sockedId)
{
    string setval = JsonInter::getstringdirect(val);
    CrLogI("property id: mcuUpgrade, value: %s\n", setval.c_str());
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;      
    UpgradeInfo otaInfo = UPGRADE_INFO__INIT;
    otaInfo.has_url = 1;
    otaInfo.url.data = (uint8_t*)const_cast<char*>(setval.c_str());
    otaInfo.url.len = setval.size() + 1;
    control.upgrade->mcu1ota = &otaInfo;        
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::lightSwProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: lightSw, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_lightsw = 1;
    control.lightsw = setval;

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);

    return "";
}

string CommondProc::setPrinterCfgProc(json_object *val,int sockedId)
{
    json_object *setPrinterCfg = val;
    if (setPrinterCfg != NULL && json_object_is_type(setPrinterCfg, json_type_object)){
        return SetPrinterConfigInfo(setPrinterCfg);
    } 
    return "";
}

string CommondProc::rmProbedMatrixProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    if(setval)
        return RemoveProbedMatrix();
    return "";
}

string CommondProc::saveParaProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: savePara, value: %d\n", setval);
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    control.has_savepara = 1;
    control.savepara = setval;

    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::aiSwProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: aiSw, value: %d\n", setval);
    AiControlPrefer aiPrefer = AI_CONTROL_PREFER__INIT;
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    aiPrefer.has_sw = 1;
    aiPrefer.sw = setval;
    control.aipre= &aiPrefer;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::aiDetectionProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: aiDetection, value: %d\n", setval);
    AiControlPrefer aiPrefer = AI_CONTROL_PREFER__INIT;
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    aiPrefer.has_detection = 1;
    aiPrefer.detection = setval;
    control.aipre= &aiPrefer;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::aiPausePrintProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);

    CrLogI("property id: aiPausePrint, value: %d\n", setval);
    AiControlPrefer aiPrefer = AI_CONTROL_PREFER__INIT;
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    aiPrefer.has_pauseprint = 1;
    aiPrefer.pauseprint = setval;
    control.aipre= &aiPrefer;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::aiFirstFloorProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: aiFirstFloor, value: %d\n", setval);
    AiControlPrefer aiPrefer = AI_CONTROL_PREFER__INIT;
    WebControlPrint control = WEB_CONTROL_PRINT__INIT;
    aiPrefer.has_firstfloor = 1;
    aiPrefer.firstfloor = setval;
    control.aipre= &aiPrefer;
    
    GET_MESSAGE_BUFF(buff);
    size_t len = web_control_print__pack(&control, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
    return "";
}

string CommondProc::deleteHistoryProc(json_object *val,int sockedId)
{
    json_object *deleteHistory = val;
    if (deleteHistory != NULL && json_object_is_type(deleteHistory, json_type_array))
    {
        json_object *resObj = json_object_new_object();
        json_object *historyRecord = json_object_from_file(GetuserPrintHistoryRecordPtah());
        if(historyRecord){
            json_object *listObj = json_object_object_get(historyRecord, "list");

            for(int i = 0; i < (int)json_object_array_length(deleteHistory); i++){
                json_object * child_obj = json_object_array_get_idx(deleteHistory, i);
                if(json_object_is_type(child_obj, json_type_int)){
                    int removeId = json_object_get_int(child_obj);
                    CrLogI("remove histroy id = %d", removeId);
                    for(int j = 0; j < (int)json_object_array_length(listObj); j++){
                        json_object *record = json_object_array_get_idx(listObj, j);
                        int id = json_object_get_int(json_object_object_get(record, "id"));
                        if(id == removeId){
                            json_object_array_del_idx(listObj, j, 1);
                        }
                    }
                }
            }
            json_object_to_file_ext(GetuserPrintHistoryRecordPtah(), historyRecord, JSON_C_TO_STRING_PRETTY|JSON_C_TO_STRING_NOSLASHESCAPE);
        }
        json_object_put(historyRecord);
        json_object_put(resObj);
    }
    return "";
}

string CommondProc::cleanErrProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: cleanErr, value: %d\n", setval);
    if(setval){
        WebControlPrint control = WEB_CONTROL_PRINT__INIT;
        control.has_clearfaultcode = 1;
        
        GET_MESSAGE_BUFF(buff);
        size_t len = web_control_print__pack(&control, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }
    return "";
}

string CommondProc::ctrlVideoFilesProc(json_object *val,int sockedId)
{
    json_object *ctrlVideoFiles = val;
    if (ctrlVideoFiles != NULL && json_object_is_type(ctrlVideoFiles, json_type_object))
    {
        int ret = -1;
        json_object *cmd = json_object_object_get(ctrlVideoFiles, "cmd");
        json_object *printId = json_object_object_get(ctrlVideoFiles, "printId");
        json_object *file = json_object_object_get(ctrlVideoFiles, "file");
        if(cmd&& json_object_is_type(cmd, json_type_string)
        &&printId&& json_object_is_type(printId, json_type_string)
        &&file&& json_object_is_type(file, json_type_string))
        {
            const char* cmdstr = json_object_get_string(cmd);
            const char* printidstr = json_object_get_string(printId);
            const char* filestr = json_object_get_string(file); 
            CrLogI("iot ctrlVideoFiles cmd = %s\n", cmdstr);
            CrLogI("iot ctrlVideoFiles printId = %s\n", printidstr);
            CrLogI("iot ctrlVideoFiles filestr = %s\n", filestr);
            if(!strcmp(cmdstr,"remove"))
            {
                ret = ProcVideoRemove(printidstr,filestr);
            }else if(!strcmp(cmdstr,"rename"))
            {
                json_object *targetname = json_object_object_get(ctrlVideoFiles, "targetname");
                std::string targetnamestr = "";
                if(targetname&& json_object_is_type(targetname, json_type_string))
                {
	 	            targetnamestr = json_object_get_string(targetname);
                    ret = ProcVideoRename(printidstr,filestr,targetnamestr);
		        }
            }
        }
    }    
    return "";
}

string CommondProc::excludeObjectsProc(json_object *val,int sockedId)
{
    json_object *exobj = val;
    CrLogI("property id: excludeObjectsProc\n");

    if (exobj != NULL && json_object_is_type(exobj, json_type_array))
    {
        for(int i = 0; i < (int)json_object_array_length(exobj); i++){
             json_object * child_obj = json_object_array_get_idx(exobj, i);
             if(json_object_is_type(child_obj, json_type_string))
             {
                WebControlPrint control = WEB_CONTROL_PRINT__INIT;
                MutableTypeData res = MUTABLE_TYPE_DATA__INIT;
                const char *objret = json_object_to_json_string(child_obj);
                CrLogI("property id: excludeObjectsProc, value: %s\n", objret);

                res.has_bytes_v = 1;
                res.bytes_v.data = (uint8_t	*)objret;
                res.bytes_v.len = strlen(objret);
                control.excludeobject = &res;
                GET_MESSAGE_BUFF(buff);
                size_t len = web_control_print__pack(&control, buff);
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CONTROL_PRINT_REQ, buff, len);
                SendProcessMsgBuff(&send, size);
             }
        }
    }
    return "";
}

string CommondProc::ReqPrinterParaProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: ReqPrinterPara, value: %d\n", setval);
    GLOBAL_INFO * globalinfo = AttributeProc::getInstance()->getGlobalInfo();
    switch (setval){
        // 获取打印倍速
        case 0: {
            char speedBuff[100] = {0};
            snprintf(speedBuff, 100, "%d", globalinfo->printSpeed);
            std::string speedInfo = std::string(speedBuff);
            CrLogI("cur speed = %s", speedInfo.c_str());

            char flowBuff[100] = {0};
            snprintf(flowBuff, 100, "%d", globalinfo->printFlow);
            std::string flowInfo = std::string(flowBuff);
            CrLogI("cur flow = %s", flowInfo.c_str());
            return ReportGetRateLocal(speedInfo, flowInfo);
            break;
        }
        // 获取喷头当前位置
        case 1: {
            char infoBuff[100] = {0};
            snprintf(infoBuff, 100, "X:%.2f Y:%.2f Z:%.2f", 
                globalinfo->livePosition.x/1000.00,
                globalinfo->livePosition.y/1000.00,
                globalinfo->livePosition.z/1000.00);
            
            std::string localInfo = std::string(infoBuff);
            CrLogI("cur local = %s", localInfo.c_str());
            return ReportGetCurrentLocal(localInfo);
            break;
        }
    }
    return "";
}

string CommondProc::reqGcodeFileProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: reqGcodeFile, value: %d\n", setval);
    if(setval == 1){
        return ReportGcodeFileInfo(GetUserLocalGcodeFileInfoPtah());
    }
    return "";
}

string CommondProc::reqHistoryProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: reqHistory, value: %d\n", setval);
    if(setval == 1){
        return ReportHistoryInfo();
    }
    return "";
}

string CommondProc::reqElapseVideoListProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: reqElapseVideoList, value: %d\n", setval);
    if(setval == 1){
        return ReportElapseVideoInfo();
    }
    return "";
}

string CommondProc::reqOtaInfoProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);

    CrLogI("property id: reqOtaInfo, value: %d\n", setval);
    if(setval == 1){

        UpgradeInfo otaInfo = UPGRADE_INFO__INIT;
        UpgradeInfoList infoList = UPGRADE_INFO_LIST__INIT;
        infoList.linuxota = &otaInfo;     
        GET_MESSAGE_BUFF(buff);
        size_t len = upgrade_info_list__pack(&infoList, buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_CHECK_UPGRADE_REQ, buff, len);
        SendProcessMsgBuff(&send, size);
    }
    return "";
}

string CommondProc::reqPrinterCfgProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);

    CrLogI("property id: reqPrinterCfg, value: %d\n", setval);
    if(setval == 1){
        return ReportPrinterConfigInfo();
    }
    return "";
}

string CommondProc::reqProbedMatrixProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: reqProbedMatrix, value: %d\n", setval);
    if(setval == 1){
        return ReportProbedMatrix();
    }
    return "";
}

string CommondProc::reqPrintObjectsProc(json_object *val,int sockedId)
{
    int setval = JsonInter::getintdirect(val);
    CrLogI("property id: reqPrintObjectsProc, value: %d\n", setval);
    if(setval == 1){
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_WEB_SERVER, SERVER_CMD_WEB_GET_PRINT_OBJECT_RES, "", 0);
        SendProcessMsgBuff(&send, size);
    }
    return "";
}

#if 0
void CommondProc::test()
{
    thread *test = new thread([this](){
        while(1){
            reqPrintObjectsProc(json_object_new_int(1),0);
            sleep(5);

            json_object *val = json_object_new_array();
            json_object_array_add(val,json_object_new_string("0_0"));
            json_object_array_add(val,json_object_new_string("0_1"));
            
            excludeObjectsProc(val,0);
            json_object_put(val);
        }
    });  
    test->detach(); 
}
#endif
