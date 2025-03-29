#ifndef _LVGL_CMD_H
#define _LVGL_CMD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "lvgl/lvgl.h"
#include "commu_thread.h"


typedef enum axis_type
{
    AXIS_X = 1,
    AXIS_Y,
    AXIS_Z,
    AXIS_E
}axis_type_t;

typedef enum Cmd_Get_Type
{
   CMD_GET_PRINT_FILE_INFO = 0x01,
   CMD_GET_Z_OFFSET = 0x02,
   CMD_GET_TEMPER = 0x03,
   CMD_GET_AXIS_POS = 0x04,
   CMD_GET_PREHEAT_PARAM = 0x05,
   CMD_GET_PARAM_STATUS = 0x06,
   CMD_GET_WIFI_INFO = 0x07,
   CMD_GET_LEVEL_DATA = 0x09,
   CMD_GET_MOVE_PARAM = 0x0A,
   CMD_GET_HOME_OFFSET = 0x0B,
   CMD_GET_AUTO_PID_PARAM = 0x0D,
   CMD_GET_PID_PARAM = 0x0E,
   CMD_GET_PRINT_STATUS = 0x0F,
   CMD_GET_PRINT_SPEED_PERCENT = 0x10,
   CMD_GET_CUR_LANGUAGE = 0x11,
   CMD_GET_BED_SIZE = 0x12,
   CMD_GET_REPRINT_TIMES = 0x13,
   CMD_GET_MACHINE_INFO = 0x14,
   CMD_GET_QRCODE = 0x15,
   CMD_GET_PRINT_FLOW = 0x16,
   CMD_GET_HOME_STATUS_INFO = 0x17,
   CMD_GET_PRINTING_ERROR_INFO = 0x18,
   CMD_GET_DEV_UPGRADE_INFO = 0x1A,
   CMD_GET_DEV_STATUS_PARAM = 0x1B,
   CMD_GET_LOGS = 0x1C,
   CMD_GET_CAMERA_STATUS = 0x1D,
   CMD_GET_POWERLOSS_OPT = 0x1E,
   CMD_GET_AI_OPT = 0x1F,
}Cmd_Get_Type_t;

typedef enum Cmd_Set_Type
{
   CMD_SET_START_PRINT = 0x01,
   CMD_SET_Z_OFFSET = 0x02,
   CMD_SET_TEMPER = 0x03,
   CMD_SET_AXIS_MOVE = 0x04,
   CMD_SET_PREHEAT_PARAM = 0x05,
   CMD_SET_PARAM_STATUS = 0x06,
   CMD_SET_WIFI_INFO = 0x07,
   CMD_SET_FILAMENT_OPT = 0x08,
   CMD_SET_LEVEL_OPT = 0x09,
   CMD_SET_MOVE_PARAM = 0x0A,
   CMD_SET_HOME_OFFSET = 0x0B,
   CMD_SET_PREHEAT_OPT = 0x0C,
   CMD_SET_AUTO_PID_PARAM = 0x0D,
   CMD_SET_PID_PARAM = 0x0E,
   CMD_SET_PRINT_OPT = 0x0F,
   CMD_SET_PRINT_SPEED_PERCENT = 0x10,
   CMD_SET_LANGUAGE = 0x11,
   CMD_SET_BED_SIZE = 0x12,
   CMD_SET_REPRINT_TIMES = 0x13,
   CMD_SET_PRINT_FLOW = 0x16,
   CMD_SET_RESTART_MACHINE = 0x19, 
   CMD_SET_START_DEV_UPGRADE = 0x1A,
   CMD_SET_DEV_STATUS_PARAM = 0x1B,
   CMD_SET_EXPORT_LOGS = 0x1C,
   CMD_SET_CAMERA_OPT = 0x1D,
   CMD_SET_POWERLOSS_OPT = 0x1E,
   CMD_SET_AI_OPT = 0x1F,
}Cmd_Set_Type_t;


int send_lvgl_cmd(uint8_t cmd_flag, char *cmd_content, int content_len,bool is_set_cmd);

/******************set 类型命令*************************/

void send_set_target_temper_cmd(uint16_t target, bool is_hotend);
void send_set_model_fan_opt_cmd(uint8_t duty_percent);
void send_set_chassis_fan_opt_cmd(uint8_t duty_percent);  //机箱风扇
void send_set_auxiliary_fan_opt_cmd(uint8_t duty_percent); //辅助风扇
void send_set_light_opt_cmd(bool open);
void send_set_axis_move_opt_cmd(axis_type_t axis, bool dir_positive, float dis, int feedrate);
void send_set_axis_home_cmd(bool home_x, bool home_y, bool home_z);
void send_set_print_start_cmd(uint16_t model_file_index, int is_print_record, bool IsPrintCalibration);
void send_set_pause_print_cmd(void);
void send_set_stop_print_cmd(void);
void send_set_resume_print_cmd(void);
int  send_set_z_offset_cmd(float z_offset);
void send_set_save_param(void);
void send_set_start_auto_level_cmd(void);

void send_set_print_speed_cmd(uint16_t speed_percent); //
void send_set_print_flow_cmd(uint16_t flow_percent);
void send_set_start_print_recovery_file(void);
void send_set_stop_print_recovery_file(void);
void send_set_buzzer_cmd(void);
void send_set_stop_fullscreen_cmd(void);

void send_set_camera_shoot_freq(uint8_t freq);
void send_set_camera_render_method_photoes(int photoes_count);
void send_set_camera_delayed_photography(bool open);
void send_set_camera_shoot_pos(uint8_t pos);

void send_set_language_cmd(uint8_t cur_language);
void send_set_disable_stepper_cmd(void);

void send_set_ai_detection_switch_cmd(bool opened);
void send_set_fault_action_cmd(bool is_detection_in_printing);
void send_set_first_layer_detection_cmd(bool opened);
void send_set_ai_flowcalibration_switch_cmd(bool opened);

/******************set 类型命令*************************/


/******************get 类型命令*************************/
void send_get_tempers_cmd(void);
void send_get_fans_status_cmd(void);
void send_get_light_status_cmd(void);
void send_get_wifi_status_cmd(void);
void send_get_power_loss_recovery_info_cmd(void);
void send_get_print_status(void);
void send_get_print_proccess(void);
void send_get_axis_home_status_cmd(void);
void send_get_cur_print_gcode_info_cmd(void);

void send_get_root_dir_file_count_cmd(bool is_local);  // local disk and udisk
void send_get_parent_dir_file_count_cmd(void);
void send_get_cur_dir_file_count_cmd(uint16_t dir_sort_index);
int  send_get_cur_dir_dirent_infos_cmd(uint16_t start_index, uint8_t count); // get sub dir and files
void send_get_print_record_count_cmd(void);
void send_get_records_cmd(uint16_t start_index, uint8_t count);
void send_get_filling_chart_info_cmd(uint16_t model_file_index);  //获取模型预览图信息

int  send_get_z_offset_cmd(void);
void send_get_print_speed_cmd(void); //
void send_get_print_flow_cmd(void);

void send_get_vedioes_count_cmd(void);
void send_get_vedio_infos_cmd(uint16_t start_index, uint8_t count);

void send_get_camera_shoot_freq(void);
void send_get_camera_render_method_photoes(void);
void send_get_camera_delayed_photography(void);
void send_get_camera_shoot_pos(void);

void send_get_cur_language_cmd(void);

void send_get_faq_qrcode_cmd(void);
void send_get_creality_cloud_qrcode_cmd(void);

void send_get_ai_detection_switch_cmd(void);
void send_get_fault_action_cmd(void);
void send_get_first_layer_detection_cmd(void);

/******************get 类型命令*************************/


#ifdef __cplusplus
}
#endif

#endif