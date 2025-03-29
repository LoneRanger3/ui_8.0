/*
 * @Description : ControllerFsm.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-08 18:18:00
 * @LastEditTime: 2022-01-17 16:54:44
 */
#ifndef __CONTROLLER_FSM_H__
#define __CONTROLLER_FSM_H__

#ifdef  __cplusplus  
extern "C" {  
#endif


/**
 * @description: 状态机切换控制，设置“FSM_MODE_t”枚举值切换状态
 */
void AppModeChange(FSM_MODE_t stModeID);
int ControllerFsmInit(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
