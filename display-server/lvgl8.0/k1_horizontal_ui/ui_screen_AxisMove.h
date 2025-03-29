/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-02 17:27:51
 * @LastEditTime: 2023-01-10 14:38:22
 */
#ifndef _UI_SCREEN_AXISMOVE_H
#define _UI_SCREEN_AXISMOVE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
#include "ui_helpers.h"

#define COLD_EXTRUSION_TEMPER 180

extern int16_t axis_move_feedrate_xy;
extern int16_t axis_move_feedrate_z;    
extern int16_t axis_move_feedrate_e;

void ui_ScreenAxisMovePage_screen_init(void);
void LoadAxisMoveScreen(void);
void axis_move_set_hotend_temper(int16_t curTemper, int16_t targetTemper);
void axis_move_set_bed_temper(int16_t curTemper, int16_t targetTemper);
void axis_move_set_chassis_temper(int16_t Temper);
void axis_move_set_fan_status(bool opened);
void axis_move_set_home_status(bool x_home_flag, bool y_home_flag, bool z_home_flag);
void axis_move_set_homing_status(uint8_t homing_status);  // 0:失败，1：成功，2：正在进行归零中 (根据协议而来)
void axis_move_set_print_status(int8_t print_status);  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议

void axis_move_set_z_move_forward_dir(uint8_t dir);   //0:正向，1：反向. 
void axis_move_change_language_text(void);

//冷却子页面
void cool_set_model_fan_duty_percent(uint8_t percent);
void cool_set_cool_fan_duty_percent(uint8_t percent);
void cool_set_Chassis_fan_duty_percent(uint8_t percent);
void cool_change_language_text();

//进退料页面
enum SHOW_TEMPER_PANEL{
    SHOW_TEMPER_EDIT_PANEL,
    SHOW_HEATING_PANEL,
    SHOW_NORMAL_PANEL,
};

enum STEP_DIR_STATE{
    STEP_NOT_START,
    STEP_PROCCESSING,
    STEP_FINISHED,
};

enum IN_FILA_PROCCESS{
    IN_FILAMENT_FIRST_STEP,
    IN_FILAMENT_SECOND_STEP,
    IN_FILAMENT_THIRD_STEP,
};

enum OUT_FILA_PROCCESS{
    OUT_FILAMENT_FIRST_STEP,
    OUT_FILAMENT_SECOND_STEP,
    OUT_FILAMENT_THIRD_STEP,
    OUT_FILAMENT_FOURTH_STEP,
};

/*****挤出料的过程，不包含加热温度*******/
enum IN_FILAMENT_STATE
{
    IN_FILAMENT_NONE,
    IN_FILAMENT_IN,
    IN_FILAMENT_FINISHED,
};

/*****退出料的过程，不包含加热温度*******/
enum OUT_FILAMENT_STATE
{
    OUT_FILAMENT_NONE,
    OUT_FILAMENT_READY,
    OUT_FILAMENT_OUT,
    OUT_FILAMENT_FINISHED,
};

/***********料操作动作状态******************/
enum FILAMENT_ACTION_STATE
{
    FILAMENT_ACTION_PROCCESSING,
    FILAMENT_ACTION_FAILED,
    FILAMENT_ACTION_SUCCESS,
};

enum FILA_ACTION_TYPE{
    FILA_ACTION_NONE,
    FILA_ACTION_IN,
    FILA_ACTION_OUT,
};

#define FILAMENT_ACTION_INCREASE_TEMPER 10
#define FILAMENT_COOL_EXTRUDE_TEMPER 180

void filament_set_filament_action_state(enum FILAMENT_ACTION_STATE state);  //进退料的动作过程，只有开始和结束，不包含加热温度
void filament_set_print_status(int8_t print_status);  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
void refresh_filament_process(int flag, int process);
void set_hotend_temper_filament(char * curtemp, char * tartemp);
void filament_infor_change_language_text();
void filament_actions_status(bool disable);
int get_fila_action_type(void);
void set_current_subpage(int pagenumber);
#ifdef __cplusplus
}
#endif

#endif