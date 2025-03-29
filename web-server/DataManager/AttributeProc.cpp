#include "AttributeProc.h"
#include "CommondProc.h"
#include "Server/WebSocket.h"
shared_ptr<AttributeProc> AttributeProc::m_Instance(new AttributeProc());

void AttributeProc::initGlobalInfo()
{
    globalInfo.sysmodel = 0;
    globalInfo.printSpeed = 0;
    globalInfo.printFlow = 0;
    memset(&globalInfo.livePosition,0,sizeof(Coordinate_t));
    memset(&globalInfo.homedAxes,0,sizeof(Coordinate_t));
    memset(&globalInfo.axisRecoup,0,sizeof(Coordinate_t));
}

AttributeProc::AttributeProc()
{
    addone("connect",0,0);
    addone("tfCard",0,0);
    addone("modelVersion","",0);
    addone("model","",0);
    addone("deviceState",0,0);
    addone("state",0,0);
    addone("printId","",0);
    addone("fan",0,0);
    addone("fanCase",0,0);
    addone("fanAuxiliary",0,0);

    addone("targetNozzleTemp",0,0);
    addone("targetBedTemp0",0,0);
    addone("targetBedTemp1",0,0);
    addone("targetBedTemp2",0,0);
    addone("boxTemp",0,0);
    addone("maxNozzleTemp",0,0);
    addone("maxBedTemp",0,0);
    addone("layer",0,0);
    addone("TotalLayer",0,0);
    addone("printStartTime",0,0);
    addone("repoPlrStatus",0,0);
    addone("upgradeStatus",0,0);

    addone("videoElapse",0,0);
    addone("nozzleMoveSnapshot",0,0);
    addone("videoElapseFrame",0,0);
    addone("videoElapseInterval",0,0);
    addone("powerLoss",0,0);
    addone("materialDetect",0,0);
    addone("velocityLimits",0,0);
    addone("accelerationLimits",0,0);
    addone("cornerVelocityLimits",0,0);
    addone("accelToDecelLimits",0,0);

    addone("pressureAdvance","",0);
    addone("smoothTime","",0);
    addone("bedTempAutoPid",0,0);
    addone("nozzleTempAutoPid",0,0);
    addone("autoLevelResult","",0);
    addone("printFileName","",0);
    addone("lightSw",0,0);
    addone("withSelfTest",0,0);
    JsonObject jobj(json_object_new_object());
    addone("err",jobj,0);
    addone("aiSw",0,0);

    addone("aiDetection",0,0);
    addone("aiPausePrint",0,0);
    addone("aiFirstFloor",0,0);
    addone("video",0,0);
    addone("video1",0,0);
    addone("materialStatus",0,0);
    addone("enableSelfTest",0,0);
    addone("modelFanPct",0,0);
    addone("caseFanPct",0,0);
    addone("auxiliaryFanPct",0,0);

    addone("nozzleTemp","",0);
    addone("bedTemp0","",0);
    addone("bedTemp1","",0);
    addone("bedTemp2","",0);
    addone("printProgress",0,0);
    addone("printJobTime",0,0);
    addone("printLeftTime",0,0);
    addone("dProgress",0,0);
    addone("curFeedratePct",0,0);
    addone("curFlowratePct",0,0);
    addone("usedMaterialLength",0,0);
    addone("realTimeSpeed","",0);
    addone("realTimeFlow","",0);
    addone("curPosition","",0);
    addone("autohome","",0);
    initGlobalInfo();
}

void AttributeProc::addone(const string &key,int val,int type)
{
    attrMap[key] = AttributePtr(new AttrAll<int>(key,val,type));
}

void AttributeProc::addone(const string &key,string val,int type)
{
    attrMap[key] = AttributePtr(new AttrAll<string>(key,val,type));
}

void AttributeProc::addone(const string &key,JsonObject &val,int type)
{
    attrMap[key] = AttributePtr(new AttrAll<JsonObject>(key,val,type));
}

AttributePtr AttributeProc::findAttr(const string &key)
{
    auto attr = attrMap.find(key);
    if(attr!=attrMap.end())
        return attr->second;
    return nullptr;
}

json_object * AttributeProc::newObject()
{
    if(WebSocket::getInstance()->getSocketCount()>0)
        return json_object_new_object();
    return nullptr;
}

string AttributeProc::detectTimeoutAttr()
{
    string result;
    json_object *resObj = json_object_new_object();

    for(auto it=attrMap.begin();it!=attrMap.end();++it){
        it->second->getTimeoutObj(resObj);
    } 

    if (json_object_object_length(resObj)) result = json_object_to_json_string(resObj);
    json_object_put(resObj);
    return result;
}

string AttributeProc::detectAllAttr()
{
    string result;
    json_object *resObj = json_object_new_object();

    for(auto it=attrMap.begin();it!=attrMap.end();++it){
        it->second->getObj(resObj);
    } 

    if (json_object_object_length(resObj)) result = json_object_to_json_string(resObj);
    json_object_put(resObj);
    return result; 
}

void AttributeProc::setSystemConfig(SystemConfigProto *config)
{
    globalInfo.sysmodel = config->model;
    json_object *resObj = newObject();
    string hw1_version = string((char *)config->hw1_version.data, config->hw1_version.len);
    string hw_version = string((char *)config->hw_version.data, config->hw_version.len);
    string fw_version = string((char *)config->fw_version.data, config->fw_version.len);
    string sys_version = string((char *)config->sys_version.data, config->sys_version.len);
    string modelversion = "printer hw ver:" + hw1_version
                            +";printer sw ver:" + fw_version
                            +";DWIN hw ver:" + hw_version
                            +";DWIN sw ver:" + sys_version
                            +";";
    string modelStr = string((char*)config->model_str.data, config->model_str.len);
    if(modelStr.find('-') != string::npos)
        modelStr = modelStr.substr(modelStr.find('-') + 1);    
    
    CrLogI("version; modelversion = %s, model = %s",modelversion.c_str(),modelStr.c_str());

    attrMap["modelVersion"]->setToObj(resObj,&modelversion);    
    attrMap["model"]->setToObj(resObj,&modelStr);    
    attrMap["lightSw"]->setToObj(resObj,&config->light_sw); 
    attrMap["enableSelfTest"]->setToObj(resObj,&config->enableselftest);                
    sendObj(resObj);
}

void AttributeProc::setPrintSavePara(PrintSavePara *config)
{
    globalInfo.axisRecoup.x = config->axisrecoup->x;
    globalInfo.axisRecoup.y = config->axisrecoup->y;
    globalInfo.axisRecoup.z = config->axisrecoup->z;
    globalInfo.axisRecoup.e = config->axisrecoup->e;
    int materialDetectState = atoi((const char*)&config->materialdetect);
    int velocityLimitsState = config->k_speed/1000;
    int accelerationLimitsState = config->k_acceleration/1000;
    int cornerVelocityLimitsState = config->k_corner/1000;
    int accelToDecelLimitsState = config->k_jerk/1000;
    double pTemp = config->pressureadvance/1000.000;
    string pressureAdvanceVal = to_string(pTemp);
    double sTemp = config->smoothtime/1000.000;
    string smoothTimeVal = to_string(sTemp);
    CrLogI("k_Speed = %d, k_Acceleration = %d, k_Corner = %d, k_Jerk = %d, pressureAdvance = %d, SmoothTime = %d, nozzlehwmaxtemp = %d, bedhwmaxtemp = %d",
        velocityLimitsState, accelerationLimitsState, cornerVelocityLimitsState,
        accelToDecelLimitsState, config->pressureadvance, config->smoothtime,
        config->nozzlehwmaxtemp,config->bedhwmaxtemp);

    json_object *resObj = newObject();
    attrMap["materialDetect"]->setToObj(resObj,&materialDetectState);
    attrMap["velocityLimits"]->setToObj(resObj,&velocityLimitsState);
    attrMap["accelerationLimits"]->setToObj(resObj,&accelerationLimitsState);
    attrMap["cornerVelocityLimits"]->setToObj(resObj,&cornerVelocityLimitsState);
    attrMap["accelToDecelLimits"]->setToObj(resObj,&accelToDecelLimitsState);
    attrMap["pressureAdvance"]->setToObj(resObj,&pressureAdvanceVal);
    attrMap["smoothTime"]->setToObj(resObj,&smoothTimeVal);
    attrMap["maxNozzleTemp"]->setToObj(resObj,&config->nozzlehwmaxtemp);
    attrMap["maxBedTemp"]->setToObj(resObj,&config->bedhwmaxtemp);

    sendObj(resObj);
}

void AttributeProc::setDeviceState(SyncPrintState *config)
{
    int workstate = 0;
    globalInfo.sdPath = string((char*)config->sdpath.data, config->sdpath.len);
    globalInfo.uDiskPath = string((char*)config->udiskpath.data, config->udiskpath.len);
    globalInfo.printSpeed = config->printspeed;
    globalInfo.printFlow = config->printflow;
    globalInfo.livePosition.x = config->liveposition->x;
    globalInfo.livePosition.y = config->liveposition->y;
    globalInfo.livePosition.z = config->liveposition->z;
    globalInfo.livePosition.e = config->liveposition->e;
    globalInfo.homedAxes.x = config->homedaxes->x;
    globalInfo.homedAxes.y = config->homedaxes->y;
    globalInfo.homedAxes.z = config->homedaxes->z;
    globalInfo.homedAxes.e = config->homedaxes->e;
    
    switch(config->workstate)
    {
        case APP_PRINT_STATE_IDLE: workstate = 0; break;
        case APP_PRINT_STATE_TO_WORK: break;
        case APP_PRINT_STATE_WORK: workstate = 1; break;
        case APP_PRINT_STATE_TO_PAUSE: break;
        case APP_PRINT_STATE_PAUSE: workstate = 5; break;
        case APP_PRINT_STATE_TO_RESUME: break;
        case APP_PRINT_STATE_LAYER_PAUSE: workstate = 1; break;
        case APP_PRINT_STATE_FINISH: workstate = 2; break;
        case APP_PRINT_STATE_FAIL: workstate = 3; break;
        case APP_PRINT_STATE_TO_STOP: break;
        case APP_PRINT_STATE_STOP: workstate = 4; break;
        case APP_PRINT_STATE_DOWNLOAD: break;
    }
    int fanState = config->fanstate[MULTI_FAN_MODEL]? 1:0;
    int fanCaseState = config->fanstate[MULTI_FAN_CASE]? 1:0;
    int fanAuxiliaryState = config->fanstate[MULTI_FAN_AUXILIARY]? 1:0;
    string curHotendTemp = to_string(config->curhotendtemp[NOZZLE_TEMP]/100.00);
    int targetHotendTemp = config->targethotendtemp[NOZZLE_TEMP]/100;
    string curBedTemp0;
    int targetBedTemp0;
    if (globalInfo.sysmodel == CR_10_H1){
        curBedTemp0 = to_string(config->curbedtemp[HOTBED_0_TEMP]/100.00);
        targetBedTemp0 = config->targetbedtemp[HOTBED_0_TEMP]/100;
    }else{
        curBedTemp0 = to_string(config->curbedtemp[HOTBED_TEMP]/100.00);
        targetBedTemp0 = config->targetbedtemp[HOTBED_TEMP]/100;
    }
    int targetBedTemp1 = config->targetbedtemp[HOTBED_1_TEMP]/100;
    int targetBedTemp2 = config->targetbedtemp[HOTBED_2_TEMP]/100;
    int curBoxTemp = config->othercurtemp[OTHER_TEMP_CAVITY]/100;
    string curBedTemp1 = to_string(config->curbedtemp[HOTBED_1_TEMP]/100.00);
    string curBedTemp2 = to_string(config->curbedtemp[HOTBED_2_TEMP]/100.00);
    int filaused = config->filamentused/100;
    string rtspeed = to_string(config->realtimespeed/100.00);
    string rtflow = to_string(config->realtimeflow/100.00);
    char curPosition[32] = {0};
    snprintf(curPosition, 32, "X:%.2f Y:%.2f Z:%.2f", 
        config->liveposition->x/1000.00,
        config->liveposition->y/1000.00,
        config->liveposition->z/1000.00);
    string cpos = curPosition;
    char autohome[16] = {0};
    snprintf(autohome, 16, "X:%d Y:%d Z:%d", 
        config->homedaxes->x, 
        config->homedaxes->y, 
        config->homedaxes->z);
    string ahome = autohome;  

    //CrLogI("devicestate = %d,workstate = %d,existoffcontinue=%d",config->devicestate,workstate,config->existoffcontinue);
    json_object *resObj = newObject();
    attrMap["nozzleTemp"]->setToObj(resObj,&curHotendTemp);
    attrMap["bedTemp0"]->setToObj(resObj,&curBedTemp0);
    attrMap["bedTemp1"]->setToObj(resObj,&curBedTemp1);
    attrMap["bedTemp2"]->setToObj(resObj,&curBedTemp2);
    attrMap["printProgress"]->setToObj(resObj,&config->printprogress);
    attrMap["printJobTime"]->setToObj(resObj,&config->printusagetime);
    attrMap["printLeftTime"]->setToObj(resObj,&config->printremaintime);
    attrMap["curFeedratePct"]->setToObj(resObj,&config->printspeed);
    attrMap["curFlowratePct"]->setToObj(resObj,&config->printflow);
    attrMap["usedMaterialLength"]->setToObj(resObj,&filaused);
    attrMap["realTimeSpeed"]->setToObj(resObj,&rtspeed);
    attrMap["realTimeFlow"]->setToObj(resObj,&rtflow);
    attrMap["curPosition"]->setToObj(resObj,&cpos);
    attrMap["autohome"]->setToObj(resObj,&ahome);
    attrMap["connect"]->setToObj(resObj,&config->serialport);
    attrMap["tfCard"]->setToObj(resObj,&config->sdcardexists);
    attrMap["deviceState"]->setToObj(resObj,&config->devicestate);
    attrMap["state"]->setToObj(resObj,&workstate);
    attrMap["fan"]->setToObj(resObj,&fanState);
    attrMap["fanCase"]->setToObj(resObj,&fanCaseState);
    attrMap["fanAuxiliary"]->setToObj(resObj,&fanAuxiliaryState);
    attrMap["targetNozzleTemp"]->setToObj(resObj,&targetHotendTemp);
    attrMap["targetBedTemp0"]->setToObj(resObj,&targetBedTemp0);
    attrMap["targetBedTemp1"]->setToObj(resObj,&targetBedTemp1);    
    attrMap["targetBedTemp2"]->setToObj(resObj,&targetBedTemp2);
    attrMap["boxTemp"]->setToObj(resObj,&curBoxTemp);  
    attrMap["layer"]->setToObj(resObj,&config->curprintlayer);  
    attrMap["TotalLayer"]->setToObj(resObj,&config->printtotallayer); 
    attrMap["repoPlrStatus"]->setToObj(resObj,&config->existoffcontinue); 
    attrMap["withSelfTest"]->setToObj(resObj,&config->withselftest); 

    json_object *errInfo = json_object_new_object();
    json_object_object_add(errInfo, "errcode", json_object_new_int(config->faultcode->error));
    json_object_object_add(errInfo, "key", json_object_new_int(config->faultcode->code));
    JsonObject jobj(errInfo);
    attrMap["err"]->setToObj(resObj,&jobj);
    json_object_put(errInfo);
    
    attrMap["video"]->setToObj(resObj,&config->cameraonline[CAMERA_MODEL]);
    attrMap["video1"]->setToObj(resObj,&config->cameraonline[CAMERA_NOZZLE]);

    int materialStatus = MATERIAL_STATUS_BLANKING; 
    if (config->materialstatus[MATERIAL_DETECTOR_1] == MATERIAL_STATUS_IDLE &&
        config->materialstatus[MATERIAL_DETECTOR_2] == MATERIAL_STATUS_IDLE)
    {
        materialStatus = MATERIAL_STATUS_IDLE;
    }
    attrMap["materialStatus"]->setToObj(resObj,&materialStatus);

    attrMap["modelFanPct"]->setToObj(resObj,&config->fanpercentage[MULTI_FAN_MODEL]);
    attrMap["caseFanPct"]->setToObj(resObj,&config->fanpercentage[MULTI_FAN_CASE]);
    attrMap["auxiliaryFanPct"]->setToObj(resObj,&config->fanpercentage[MULTI_FAN_AUXILIARY]);
    sendObj(resObj);
}

void AttributeProc::setPrintWorkInfo(PrintWorkInfo *config)
{
    json_object *resObj = newObject();
    string printFileName = string((const char*)config->filename.data, config->filename.len);

    if (config->startway != PRINT_SOURCE_APP_CLOUD)
    {
        string printId = "";
        string appToken = "";
        attrMap["printId"]->setToObj(resObj,&printId);
    }
    CrLogI("printStartTime = %d,printFileName=%s", config->starttime,printFileName.c_str());
    attrMap["printStartTime"]->setToObj(resObj,&config->starttime);
    attrMap["printFileName"]->setToObj(resObj,&printFileName);
    sendObj(resObj);
}

void AttributeProc::setDelayImage(DelayImagePrefer *config)
{
    json_object *resObj = newObject();

    if (config->has_sw) {
        CrLogI("delay image prefer sw = %d", config->sw);
        attrMap["videoElapse"]->setToObj(resObj,&config->sw);
    }

    if (config->has_location){
        CrLogI("delay image prefer location = %d", config->location);
        attrMap["nozzleMoveSnapshot"]->setToObj(resObj,&config->location);
    }

    if (config->has_frame){
        CrLogI("delay image prefer frame = %d", config->frame);
        attrMap["videoElapseFrame"]->setToObj(resObj,&config->frame);
    }

    if (config->has_interval){
        CrLogI("delay image prefer interval = %d", config->interval);
        attrMap["videoElapseInterval"]->setToObj(resObj,&config->interval);
    }
    sendObj(resObj);
}

void AttributeProc::setUpgradeStateToWeb(UpgradeInfoList *config)
{
    // 升级状态
    if (config->linuxota || config->linuxlocal) {
        UpgradeInfo *info = NULL;
        if (config->linuxota) info = config->linuxota;
        if (config->linuxlocal) info = config->linuxlocal;
        json_object *resObj = newObject();
        attrMap["upgradeStatus"]->setToObj(resObj,&info->state);
        attrMap["dProgress"]->setToObj(resObj,&info->progress);
        CrLogI("get upgrade state %d, progress = %d", info->state, info->progress);
        sendObj(resObj);
    }    
}

void AttributeProc::setPowerLoss(PowerLossPrefer *config)
{
    if (config->has_sw) {
        CrLogI("power loss prefer sw = %d", config->sw);
        json_object *resObj = newObject();
        attrMap["powerLoss"]->setToObj(resObj,&config->sw);
        sendObj(resObj);
    }
}

void AttributeProc::setAutoPid(TempAutoPidPreferList *config)
{
    json_object *resObj = newObject();
    for (uint i = 0; i < config->n_list; i++)
    {
        if(config->list[i]->id == 1){
            attrMap["nozzleTempAutoPid"]->setToObj(resObj,&config->list[0]->temp);
        }else if(config->list[i]->id == 2){
            attrMap["bedTempAutoPid"]->setToObj(resObj,&config->list[1]->temp);
        }
    }
    sendObj(resObj);
}

void AttributeProc::setAutoLevel(ReportAutoLevelRes *config)
{
    if (config->has_num && config->has_value)
    {
        json_object *resObj = newObject();
        CrLogI("auto level num = %d, value = %d", config->num, config->value);
        char sendBuff[100] = {0};
        snprintf(sendBuff, 100, "%d:%.2f", config->num, config->value/10000.00);
        string autoLevelResult = sendBuff;
        attrMap["autoLevelResult"]->setToObj(resObj,&autoLevelResult);
        sendObj(resObj);
        string ret = CommondProc::getInstance()->ReportProbedMatrix();
        if(ret.size()>0)
            WebSocket::getInstance()->sendToAllSocket(ret);
    }
}
   
void AttributeProc::setAiControl(AiControlPrefer *config)
{
    json_object *resObj = newObject();
    if (config->has_sw) {
        CrLogI("ai control prefer sw = %d", config->sw);
        attrMap["aiSw"]->setToObj(resObj,&config->sw);
    }
    if (config->has_detection) {
        CrLogI("ai control prefer detection = %d", config->detection);
        attrMap["aiDetection"]->setToObj(resObj,&config->detection);
    }
    if (config->has_pauseprint) {
        CrLogI("ai control prefer pause print = %d", config->pauseprint);
        attrMap["aiPausePrint"]->setToObj(resObj,&config->pauseprint);
    }
    if (config->has_firstfloor) {
        CrLogI("ai control prefer first floor = %d", config->firstfloor);
        attrMap["aiFirstFloor"]->setToObj(resObj,&config->firstfloor);
    }
    if (config->has_flowdetect) {
        CrLogI("ai control prefer flow detection = %d", config->flowdetect);
    }

    sendObj(resObj);
}

void AttributeProc::setCurrentLocal(AxisPositionInfo *config)
{
    char infoBuff[100] = {0};
    snprintf(infoBuff, 100, "X%.2f Y%.2f Z%.2f", config->x/100.00, config->y/100.00, config->z/100.00);
    std::string localInfo = std::string(infoBuff);
    attrMap["curPosition"]->setToObj(nullptr,&infoBuff);
    CrLogI("cur local = %s", localInfo.c_str());
    string ret = CommondProc::getInstance()->ReportGetCurrentLocal(localInfo);
    if(ret.size()>0)
        WebSocket::getInstance()->sendToAllSocket(ret);
}

void AttributeProc::sendObj(json_object *Obj)
{
    if(Obj == nullptr) return;
    if(json_object_array_length(Obj)>0)
    {
        string send = json_object_to_json_string(Obj);
        WebSocket::getInstance()->sendToAllSocket(send);
        //CrLogI("send attr :%s",send.c_str());                
    }
    json_object_put(Obj);
}
