/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-08-25 16:33:08
 * @LastEditTime: 2023-08-29 15:08:14
 */
#pragma once
#include "Attribute.h"
#include <map>
using namespace std;

typedef struct
{
    int sysmodel;
    string sdPath; // 虚拟SD卡路径
    string uDiskPath; // U盘路径
    int printSpeed; // 打印速度
    int printFlow; // 打印流量
    Coordinate_t livePosition; // 喷嘴当前位置    
    Coordinate_t homedAxes; // 轴归位状态
    Coordinate_t axisRecoup; //轴补偿值
}GLOBAL_INFO;

class AttributeProc
{
private:
    map<string,AttributePtr> attrMap;
    GLOBAL_INFO globalInfo;
    static shared_ptr<AttributeProc> m_Instance;
    void initGlobalInfo();
    void addone(const string &key,int val,int type);
    void addone(const string &key,string val,int type);
    void addone(const string &key,JsonObject &val,int type);
    AttributePtr findAttr(const string &key);
    json_object * newObject();
    AttributeProc();
public:
    static shared_ptr<AttributeProc> getInstance(){
        return m_Instance;
    }
    ~AttributeProc(){}
    GLOBAL_INFO* getGlobalInfo(){return &globalInfo;}
    string detectTimeoutAttr();
    string detectAllAttr();
    void sendObj(json_object *Obj);
    void setSystemConfig(SystemConfigProto *config);
    void setPrintSavePara(PrintSavePara *config);
    void setDeviceState(SyncPrintState *config);
    void setPrintWorkInfo(PrintWorkInfo *config);
    void setDelayImage(DelayImagePrefer *config);
    void setUpgradeStateToWeb(UpgradeInfoList *config);
    void setPowerLoss(PowerLossPrefer *config);
    void setAutoPid(TempAutoPidPreferList *config);
    void setAutoLevel(ReportAutoLevelRes *config);
    void setAiControl(AiControlPrefer *config);
    void setCurrentLocal(AxisPositionInfo *config);
};

