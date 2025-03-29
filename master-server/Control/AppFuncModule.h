/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-02-23 12:00:09
 * @LastEditTime: 2023-06-13 11:40:59
 */

#ifndef __APP_FUNTION_MODULE_H__
#define __APP_FUNTION_MODULE_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

typedef void (*MACRO_RES)(int res);

void AppFuncModuleInit(void);
void CancelFuncModule(void);

/**
 * @description: 独立功能模块
 * @return {*}
 */
// 流量检测是阻塞接口
int StartAiFlowDetect(bool syncState, char *result);
// 激光标定接口
int StartLaserCalibration(void);
// 激光扫描床面
int StartLaserScanningTable(void);
// 激光首层检测
int StartFirstLayerDetect(bool syncState);
// 激光偏移矫正
int StartLaserOffsetCorrection(void);

// 添加宏指令到等待队列，顺序执行
int AppGcodeMacroRecv(json_object *gcode, MACRO_RES resCb);

//激光模组厂测,热床跟激光模组相对位置矫正
int StartLaserTest(int step);

//获取激光模组版本
void getLaserVersion(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
