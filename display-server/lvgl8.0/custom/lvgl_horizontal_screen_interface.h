/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-02 17:27:51
 * @LastEditTime: 2023-03-15 11:01:25
 */
#ifndef _LVGL_HORIZONTAL_SCREEN_INTERFACE_H
#define _LVGL_HORIZONTAL_SCREEN_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "k1_horizontal_ui/ui_screen_FileManage.h"
#include "k1_horizontal_ui/ui_screen_CameraList.h"
#include "k1_horizontal_ui/ui_screen_filament_Infor.h"

void analyze_files_info_respone(char *data, uint16_t data_len);
void analyze_print_records_info_respone(char *data, uint16_t data_len);
void analyze_filling_chart_info_respone(char *data, uint16_t data_len);
void analyze_vedioes_info_respone(char *data, uint16_t data_len);

/*********************home page******************/
void set_hotend_temper(int16_t curTemper, int16_t targetTemper);
void set_bed_temper(int16_t curTemper, int16_t targetTemper);
void set_chassis_temper(int16_t curTemper);
void set_fans_status(uint8_t model_fan_duty_percent, 
        uint8_t auxiliary_fan_duty_percent,uint8_t chassis_fan_duty_percent);
void set_light_status(bool open);
void set_wifi_status(int intensity);
void set_print_proccess_info(int32_t used_time, int32_t left_time, int8_t proccess); //time unit is minter
void set_print_proccess_layers_info(uint32_t layer_count, uint32_t cur_layer_index);
void set_print_file_name(char *file_name);  //???
void set_filling_chart_info(char *chart_name, uint16_t pixel_start, 
                                          uint16_t pixel_end, float model_height,float model_layer_height);  
void set_printing_status(int status);  // 0: finished, 1:stoped, 2:paused, 3: printing.  依赖于协议
void set_powerloss_recovery_info(int state);
void set_filament_runout(bool filamen_runout); // ???
void set_home_status(bool x_home_flag, bool y_home_flag, bool z_home_flag);  // ???
void set_homing_status(uint8_t homing_status);

/*****************move and adjust**********************/
void set_offset_z(float offset_z);
void set_speed_percent(int percent);
void set_flow_percent(int percent);

/********************cool and filament******************************/
void set_in_or_out_filamnet_state(enum FILAMENT_ACTION_STATE state);  //进退料的进料、退料准备和退料的操作的状态，不包含加热过程


/*****************file manage , sub dir , preview and history**************************************/
void set_files_count(int count);  
void set_file_infos(Dirent_Info_t dirent_array[8], int real_count);  // 因为没有传文件索引，所以需要根据页面上的开始编号来获取文件索引
void set_print_record_info(print_record_info_t record_arry[3], int real_record_count); // row_no is 0 to 2 
void set_print_record_count(int count);
void set_u_disk_status(bool inserted); //???


/************************full screen*****************************/
void set_full_screen_display_status(bool open_full_screen);


/***********************************************/
void set_screen_off_status(bool screen_off);

/******************settings screen*******************************/
void set_vedioes_count(int count);
void set_vedioes_info(print_vedio_info_t info_array[3], int real_count);

void set_camera_shoot_pos(uint8_t pos);
void set_camera_shoot_freq(uint8_t freq);
void set_camera_delayed_photography(bool opened);
void set_camera_rendering_method(uint8_t photoes);  //渲染帧数

void set_cur_language(uint8_t language);

void set_faq_qrcode(char * qrcode_name);

void set_ai_detection_state(AIConfigState_t aistate);
void set_fault_action(bool is_detection_in_printing);
void set_first_layer_detection_state(bool opened);

#ifdef __cplusplus
}
#endif

#endif
