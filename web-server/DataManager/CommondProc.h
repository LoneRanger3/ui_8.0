/*
 * @Description : 

 * @Author      : Yufeng Zhang
 * @Date: 2023-08-17 19:22:37
 * @LastEditTime: 2023-09-04 14:42:43
 */
#pragma once

#include <string>
#include <ctime>
#include <atomic>
#include <memory>
#include "global/Global.h"
#include <functional>
#include <map>
using namespace std;
class CommondProc
{
public:
    static CommondProc* getInstance(){
        if(m_Instance == nullptr) m_Instance = new CommondProc();
        return m_Instance;
    }
    CommondProc();
    ~CommondProc(){}
    string GetCmdProc(int socketId,const string &key,json_object *val);
    string SetCmdProc(int socketId,const string &key,json_object *val);
    string ReportGcodeFileInfo(std::string path);
    string ReportGetCurrentLocal(std::string local);
    string ReportProbedMatrix();
    string ReportHistoryInfo();
    string ReportElapseVideoInfo();
private:
    void Remove7zPackges();
    string ReportExportLogInfo(char* filename);
    int SyncUploadLogState(int state, int progress);
    char* UserExportLog();
    string SetPrinterConfigInfo(json_object *req);
    string ReportPrinterConfigInfo();
    string RemoveProbedMatrix();
    int ProcVideoRemove(std::string prindId,std::string file);
    int ProcVideoRename(std::string prindId,std::string file,std::string targetname);
    string ReportGetRateLocal(std::string feed, std::string flow);


    string fanProc(json_object *val,int sockedId);
    string fanCaseProc(json_object *val,int sockedId);
    string fanAuxiliaryProc(json_object *val,int sockedId);
    string nozzleTempControlProc(json_object *val,int sockedId);
    string bedTempControlProc(json_object *val,int sockedId);
    string stopProc(json_object *val,int sockedId);
    string pauseProc(json_object *val,int sockedId);
    string repoPlrStatusProc(json_object *val,int sockedId);
    string gcodeCmdProc(json_object *val,int sockedId);
    string setFeedratePctProc(json_object *val,int sockedId);
    
    string setFlowratePctProc(json_object *val,int sockedId);
    string setPositionProc(json_object *val,int sockedId);
    string autohomeProc(json_object *val,int sockedId);
    string opGcodeFileProc(json_object *val,int sockedId);
    string enableSelfTestProc(json_object *val,int sockedId);
    string setZOffsetProc(json_object *val,int sockedId);
    string motorLockProc(json_object *val,int sockedId);
    string heatersOffProc(json_object *val,int sockedId);
    string velocityLimitsProc(json_object *val,int sockedId);
    string accelerationLimitsProc(json_object *val,int sockedId);

    string cornerVelocityLimitsProc(json_object *val,int sockedId);
    string accelToDecelLimitsProc(json_object *val,int sockedId);
    string pressureAdvanceProc(json_object *val,int sockedId);
    string smoothTimeProc(json_object *val,int sockedId);
    string videoElapseProc(json_object *val,int sockedId);
    string nozzleMoveSnapshotProc(json_object *val,int sockedId);
    string videoElapseFrameProc(json_object *val,int sockedId);
    string videoElapseIntervalProc(json_object *val,int sockedId);
    string bedTempAutoPidProc(json_object *val,int sockedId);
    string nozzleTempAutoPidProc(json_object *val,int sockedId);

    string startAutoPidProc(json_object *val,int sockedId);
    string materialDetectProc(json_object *val,int sockedId);
    string powerLossSwProc(json_object *val,int sockedId);
    string resonanceTestProc(json_object *val,int sockedId);
    string manualLevelProc(json_object *val,int sockedId);
    string autoLevelProc(json_object *val,int sockedId);
    string restartKlipperProc(json_object *val,int sockedId);
    string restartFirmwareProc(json_object *val,int sockedId);
    string resetSystemProc(json_object *val,int sockedId);
    string exportLogProc(json_object *val,int sockedId);

    string linuxUpgradeProc(json_object *val,int sockedId);
    string mcuUpgradeProc(json_object *val,int sockedId);
    string lightSwProc(json_object *val,int sockedId);
    string setPrinterCfgProc(json_object *val,int sockedId);
    string rmProbedMatrixProc(json_object *val,int sockedId);
    string saveParaProc(json_object *val,int sockedId);
    string aiSwProc(json_object *val,int sockedId);
    string aiDetectionProc(json_object *val,int sockedId);
    string aiPausePrintProc(json_object *val,int sockedId);
    string aiFirstFloorProc(json_object *val,int sockedId);

    string deleteHistoryProc(json_object *val,int sockedId);
    string cleanErrProc(json_object *val,int sockedId);
    string ctrlVideoFilesProc(json_object *val,int sockedId);
    string excludeObjectsProc(json_object *val,int sockedId);

    string ReqPrinterParaProc(json_object *val,int sockedId);
    string reqGcodeFileProc(json_object *val,int sockedId);
    string reqHistoryProc(json_object *val,int sockedId);
    string reqElapseVideoListProc(json_object *val,int sockedId);
    string reqOtaInfoProc(json_object *val,int sockedId);
    string reqPrinterCfgProc(json_object *val,int sockedId);
    string reqProbedMatrixProc(json_object *val,int sockedId);
    string reqPrintObjectsProc(json_object *val,int sockedId);

private:
    map<string,function<string(json_object *,int)>> GetcmdList;
    map<string,function<string(json_object *,int)>> SetcmdList;
    static CommondProc* m_Instance;
};