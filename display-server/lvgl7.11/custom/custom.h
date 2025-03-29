// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/*
 * custom.h
 *
 *  Created on: July 29, 2020
 *      Author: nxf53801
 */

#ifndef __CUSTOM_H_
#define __CUSTOM_H_

#include "gui_guider.h"

enum SCR_ID {
	SCR_HOME_PAGE = 0,
	SCR_PRINT_PAGE = 1,
	SCR_PREPARE_MOVE_AXIS_PAGE = 2,
	SCR_PREPARE_MATERIAL_PAGE = 3,
	SCR_PREPARE_MANUAL_TEMP_PAGE = 4,
	SCR_SETTING_DEVICE_PAGE = 5,
	SCR_SETTING_AD_SETTING_PAGE = 6,
	SCR_SETTING_ABOUT_PAGE = 7,
	SCR_LANGUAGE_PAGE = 8,
	SCR_LEVEL_AUTO_PAGE = 9,
	SCR_LEVEL_MANUAL_PAGE = 10,
	SCR_MOTIONSET_PAGE = 11,
	SCR_RTOSET_PAGE = 12,
	SCR_MAXACCSET_PAGE = 13,
	SCR_MAXCONCORSET_PAGE = 14,
	SCR_MAXSPEEDSET_PAGE = 15,
	SCR_TEMPPIDSET_PAGE = 16,
	SCR_PRINTINGSET_PAGE = 17,
	SCR_ZOFFSETSET_PAGE = 18,
	SCR_PREHEATING_PAGE = 19,
	SCR_MSGBOX_PAGE = 20,
	SCR_INPUTBOXS_PAGE = 21
};

enum MSG_ID {
	PRINT_FILE = 0,
	PRINTING_PAUSE = 1,
	PRINTING_STOP = 2,
	PRINTING_RESUME = 3,
	PRINT_FINISHED = 4,
	PRINT_NORMAL = 5
};

#define LV_DEMO_PRINTER_ANIM_TIME  (30)
#define LV_DEMO_PRINTER_ANIM_DELAY  (10)

#define PID_LEN 8

#define MOTION_TEMP_LEN 6   //这个数值必须不小于下面的四个数值
#define RTO_LEN 6
#define MACC_LEN 4
#define MCONCOR_LEN 5
#define MSPEED_LEN 4

#define EDIT_TEMP_LEN 4     //这个数值必须不小于下面的三个数值
#define HOTEND_TEMP_LEN 3
#define BED_TEMP_LEN 2
#define CUR_SPEED_LEN 3

#define ZOFFSET_LEN 5
#define CUR_POSITION 6
#define MATERIAL_LEN 3
#define PERCENT_LEN 3
#define PRINT_TIME_LEN 6
#define AUTO_POWEROFF_LEN 3
#define ABOUT_INFO_LEN 20
//#define FILE_NAME_LEN 50
#define INPUT_WINDOW_LEN 20

#define FILE_NUM_PRE_PAGE 6
#define FILE_NUM_SIZE 3

#define FILE_PHOTO_SIZE 50
#define FILE_SIZE 13

extern int cur_scr;
extern int pre_scr;
//extern char *file_names;
extern lv_anim_t ani_en_btn_click;
extern unsigned int tick_start;
extern unsigned int print_file_pages;
extern unsigned int print_total_files;

extern char edit_temp[EDIT_TEMP_LEN];
extern char edit_pid_temp[PID_LEN];
extern char edit_motion[MOTION_TEMP_LEN];
extern char hotend_max_temp[HOTEND_TEMP_LEN+1];
extern char hotend_cur_temp[HOTEND_TEMP_LEN+1];
extern char bed_max_temp[BED_TEMP_LEN+1];
extern char bed_cur_temp[BED_TEMP_LEN+1];
extern char zoffset_value[ZOFFSET_LEN+1];
extern char cur_speed[CUR_SPEED_LEN+2];
extern char cur_xposition[CUR_POSITION+1];
extern char cur_yposition[CUR_POSITION+1];
extern char cur_zposition[CUR_POSITION+1];
extern bool fan_state;
extern bool light_state;
extern unsigned char cur_language;
extern char wifi_state;
extern char xRTO[RTO_LEN+1];
extern char yRTO[RTO_LEN+1];
extern char zRTO[RTO_LEN+1];
extern char eRTO[RTO_LEN+1];
extern char xmacc[MACC_LEN+1];
extern char ymacc[MACC_LEN+1];
extern char zmacc[MACC_LEN+1];
extern char emacc[MACC_LEN+1];
extern char xmconcor[MCONCOR_LEN+1];
extern char ymconcor[MCONCOR_LEN+1];
extern char zmconcor[MCONCOR_LEN+1];
extern char emconcor[MCONCOR_LEN+1];
extern char xmspeed[MSPEED_LEN+1];
extern char ymspeed[MSPEED_LEN+1];
extern char zmspeed[MSPEED_LEN+1];
extern char emspeed[MSPEED_LEN+1];
extern char hotend_pid_p[PID_LEN+1];
extern char hotend_pid_i[PID_LEN+1];
extern char hotend_pid_d[PID_LEN+1];
extern char bed_pid_p[PID_LEN+1];
extern char bed_pid_i[PID_LEN+1];
extern char bed_pid_d[PID_LEN+1];
extern char PLA_preheat_hotend[HOTEND_TEMP_LEN+1];
extern char PLA_preheat_bed[BED_TEMP_LEN+1];
extern char ABS_preheat_hotend[HOTEND_TEMP_LEN+1];
extern char ABS_preheat_bed[BED_TEMP_LEN+1];
extern char auto_poweroff[AUTO_POWEROFF_LEN+1];
extern char machine_type_value[ABOUT_INFO_LEN+1];
extern char fireware_ver_value[ABOUT_INFO_LEN+1];
extern char screen_ver_value[ABOUT_INFO_LEN+1];
extern char hardware_ver_value[ABOUT_INFO_LEN+1];
extern char print_size_value[ABOUT_INFO_LEN+1];
extern char official_web_value[ABOUT_INFO_LEN+1];

extern unsigned char preheating_flag;
extern unsigned int current_page;
extern char axis_move_uint;
extern char zoffset_move_uint;
extern bool motor_loss_state;
extern char material_length[MATERIAL_LEN+1];

//extern char printing_file_name[FILE_NAME_LEN+1];
extern char print_percent[PERCENT_LEN+2];
extern char print_remain_time[PRINT_TIME_LEN+1];

extern int model_start_pix;
extern int model_end_pix;
extern char big_photo_name[FILE_PHOTO_SIZE+1];

extern bool refresh_hotend_temp;
extern bool refresh_bed_temp;
extern bool refresh_zoffset;
extern bool refresh_preheat_hotend;
extern bool refresh_preheat_bed;
extern bool refresh_pid_hotend_p;
extern bool refresh_pid_hotend_i;
extern bool refresh_pid_hotend_d;
extern bool refresh_pid_bed_p;
extern bool refresh_pid_bed_i;
extern bool refresh_pid_bed_d;
extern bool refresh_rto_x;
extern bool refresh_rto_y;
extern bool refresh_rto_z;
extern bool refresh_rto_e;
extern bool refresh_macc_x;
extern bool refresh_macc_y;
extern bool refresh_macc_z;
extern bool refresh_macc_e;
extern bool refresh_mcon_x;
extern bool refresh_mcon_y;
extern bool refresh_mcon_z;
extern bool refresh_mcon_e;
extern bool refresh_mspeed_x;
extern bool refresh_mspeed_y;
extern bool refresh_mspeed_z;
extern bool refresh_mspeed_e;
extern bool refresh_print_speed;
extern bool print_file_ok;

extern int msg_id;
extern unsigned char print_state;

void home_event_init(void);
void print_event_init(void);
void print_finsh_event_cb(struct _lv_obj_t * obj, lv_event_t event);
void prepare_move_axis_event_init();
void prepare_material_event_init();
void prepare_manual_temp_event_init();
void language_event_init(void);
void motionset_event_init(void);
void tempPIDset_event_init(void);
void rtoset_event_init(void);
void maxaccset_event_init(void);
void maxconcorset_event_init(void);
void maxspeedset_event_init(void);
void printingset_event_init(void);
void zoffset_event_init(void);
void preheating_event_init(void);
void inputboxs_event_init(void);
void setting_device_event_init();
void setting_ad_setting_event_init();
void setting_about_event_init();
void levle_auto_event_init(void);
void levle_manual_event_init(void);
void language_event_init(void);
void msgboxs_event_init(void);
void event_cb(void);

void custom_init(lv_ui *ui);
void guider_load_screen(int scr_id);
void lv_demo_printer_anim_in_all(lv_obj_t * obj, uint32_t delay);
void file_list_btn_event_handler(lv_obj_t * obj, lv_event_t event);
void set_print_file_nums(void);
void handle_file();

bool check_time(void);
void msgbox(char *msg);
void stack_preheating(unsigned char preheating);
void stack_input(int scr_id,unsigned char shield,unsigned char nums,char *cur_dt);
void handle_input(char chr);
void show_model_image(char *data);

#endif /* EVENT_CB_H_ */
