/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-02 17:27:51
 * @LastEditTime: 2023-10-24 20:48:19
 */
#ifndef _UI_SCREEN_AXISMOVE_H
#define _UI_SCREEN_AXISMOVE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
#include "ui_helpers.h"

#define COLD_EXTRUSION_TEMPER 180

extern lv_obj_t * ui_PanelExtrudeRetract;
extern enum FILA_ACTION_TYPE filament_action;

extern int16_t axis_move_feedrate_xy;
extern int16_t axis_move_feedrate_z;    
extern int16_t axis_move_feedrate_e;
// extern bool RefreshModelFanFlag;

// #define FAN_CONTROL_A
//const double FanMinDutyValue;

typedef struct ctrl_list
{
    lv_obj_t *parent;
    lv_obj_t *part_panel;
    lv_obj_t *image_item;
    lv_obj_t *label_item_name; //设置列表项名
    lv_obj_t *label_content_name; //设置列表项名
    lv_obj_t *img_arrow_png;
    uint8_t index;
}ctrl_list_t;

typedef enum {
    HOTEND_STATE_INIT = 0,
    HOTEND_STATE_NORMAL,
    HOTEND_STATE_HEATING,
}HotendState_t;

typedef enum {
    PROMPT_STATE_TIP = 0,   //提示状态
    PROMPT_STATE_EXTRUDE_POCCESS,
    PROMPT_STATE_RETRACT_POCCESS,
}PromptState_t;

enum FILA_ACTION_TYPE{
    FILA_ACTION_NONE = 0,
    FILA_ACTION_IN,
    FILA_ACTION_OUT,
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

enum STEP_DIR_STATE{
    STEP_NOT_START,
    STEP_PROCCESSING,
    STEP_FINISHED,
};

enum SHOW_TEMPER_PANEL{
    SHOW_TEMPER_EDIT_PANEL,
    SHOW_HEATING_PANEL,
    SHOW_NORMAL_PANEL,
};

enum FILAMENT_ACTION_STATE
{
    FILAMENT_ACTION_PROCCESSING,
    FILAMENT_ACTION_FAILED,
    FILAMENT_ACTION_SUCCESS,
};


void LoadAxixMoveScreenAndObjs(bool IsEntered);
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
void axis_move_change_white_style();
void ui_event_changelabel(lv_event_t * e);
void refresh_fan_value(int fanvalue);
void axis_move_set_model_fan_duty_percent(uint8_t percent);
void axismove_page_refresh_laserstate(int laser_state);
void axismove_page_refresh_camerastate(int camera_state);
void axismove_page_set_wifi_status(int intensity);
void axis_move_filament_set_hotend_temper(uint16_t cur_temper, uint16_t target_temper);
void axis_move_filament_set_filament_action_state(enum FILAMENT_ACTION_STATE state);
void axis_move_filament_set_print_status(int8_t print_status);
void axis_move_refresh_filament_process(int flag, int process);
void axis_move_set_hotend_temper_filament(char * curtemp, char * tartemp);
void axis_move_filament_infor_change_language_text(void);

//进退料有关的接口
void AddExtrudeRetractNavObjs(void);
void show_proccess_panel(PromptState_t show_proccess);
void show_temper_panel(enum SHOW_TEMPER_PANEL panel);
void filament_actions_status(bool disable);

//风扇冷却页有关
void AddCoolSubPageNavObjs(void);
void AddFanCtrlNavObjs(void);
void ShowCoolSubPage(lv_obj_t *parent);
void HideCoolSubPage(void);

void refresh_xyz_value(int x_value, int y_value, int z_value);
void AxisMovePageCloseSubPage(void);

#ifdef __cplusplus
}
#endif

#endif