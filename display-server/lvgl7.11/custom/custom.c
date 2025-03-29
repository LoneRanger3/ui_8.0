// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lvgl/lvgl.h"
#include "custom.h"
#include "clanguage.h"

#include "commu_thread.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */
#define LV_DEMO_PRINTER_WHITE           lv_color_hex(0xffffff)
#define LV_DEMO_PRINTER_LIGHT_GRAY      lv_color_hex(0xc4c4c4)

#define CLICK_DIFF 600    //单位毫秒
//#define FRINT_FILE_DELAY 1500   //单位毫秒

int cur_scr;
int pre_scr;
//char *file_names = NULL;            //存储SD卡获取的文件名称
//char *printing_file_name = NULL;    //存储选中的准备打印的文件全路径名称
//unsigned char file_name_num;
char printing_file_name[FILE_SIZE+1];

unsigned int tick_start;
unsigned int print_file_pages;
unsigned int print_total_files;

char input_str[INPUT_WINDOW_LEN+1];
unsigned char shield_input_bit;
unsigned char input_number_bit;

char *cur_data;
char edit_temp[EDIT_TEMP_LEN];
char edit_pid_temp[PID_LEN];
char edit_motion[MOTION_TEMP_LEN];
char hotend_max_temp[HOTEND_TEMP_LEN+1];
char hotend_cur_temp[HOTEND_TEMP_LEN+1];
char bed_max_temp[BED_TEMP_LEN+1];
char bed_cur_temp[BED_TEMP_LEN+1];
char zoffset_value[ZOFFSET_LEN+1] = {'\0'};
char cur_speed[CUR_SPEED_LEN+2];
char cur_xposition[CUR_POSITION+1];
char cur_yposition[CUR_POSITION+1];
char cur_zposition[CUR_POSITION+1];
bool fan_state;
bool light_state;
unsigned char cur_language;
char wifi_state;
char xRTO[RTO_LEN+1];
char yRTO[RTO_LEN+1];
char zRTO[RTO_LEN+1];
char eRTO[RTO_LEN+1];
char xmacc[MACC_LEN+1];
char ymacc[MACC_LEN+1];
char zmacc[MACC_LEN+1];
char emacc[MACC_LEN+1];
char xmconcor[MCONCOR_LEN+1];
char ymconcor[MCONCOR_LEN+1];
char zmconcor[MCONCOR_LEN+1];
char emconcor[MCONCOR_LEN+1];
char xmspeed[MSPEED_LEN+1];
char ymspeed[MSPEED_LEN+1];
char zmspeed[MSPEED_LEN+1];
char emspeed[MSPEED_LEN+1];
char hotend_pid_p[(PID_LEN+1)];
char hotend_pid_i[(PID_LEN+1)];
char hotend_pid_d[(PID_LEN+1)];
char bed_pid_p[(PID_LEN+1)];
char bed_pid_i[(PID_LEN+1)];
char bed_pid_d[(PID_LEN+1)];
char PLA_preheat_hotend[HOTEND_TEMP_LEN+1];
char PLA_preheat_bed[BED_TEMP_LEN+1];
char ABS_preheat_hotend[HOTEND_TEMP_LEN+1];
char ABS_preheat_bed[BED_TEMP_LEN+1];
char auto_poweroff[AUTO_POWEROFF_LEN+1];
char machine_type_value[ABOUT_INFO_LEN+1];
char fireware_ver_value[ABOUT_INFO_LEN+1];
char screen_ver_value[ABOUT_INFO_LEN+1];
char hardware_ver_value[ABOUT_INFO_LEN+1];
char print_size_value[ABOUT_INFO_LEN+1];
char official_web_value[ABOUT_INFO_LEN+1];

unsigned char preheating_flag;
unsigned int current_page;
char axis_move_uint;
char zoffset_move_uint;
bool motor_loss_state;
char material_length[MATERIAL_LEN+1];
bool input_win_flag;

//char printing_file_name[FILE_NAME_LEN+1];
char print_percent[PERCENT_LEN+2];
char print_remain_time[PRINT_TIME_LEN+1];

int model_start_pix;
int model_end_pix;
char big_photo_name[FILE_PHOTO_SIZE+1];

bool refresh_hotend_temp;
bool refresh_bed_temp;
bool refresh_zoffset;
bool refresh_preheat_hotend;
bool refresh_preheat_bed;
bool refresh_pid_hotend_p;
bool refresh_pid_hotend_i;
bool refresh_pid_hotend_d;
bool refresh_pid_bed_p;
bool refresh_pid_bed_i;
bool refresh_pid_bed_d;
bool refresh_rto_x;
bool refresh_rto_y;
bool refresh_rto_z;
bool refresh_rto_e;
bool refresh_macc_x;
bool refresh_macc_y;
bool refresh_macc_z;
bool refresh_macc_e;
bool refresh_mcon_x;
bool refresh_mcon_y;
bool refresh_mcon_z;
bool refresh_mcon_e;
bool refresh_mspeed_x;
bool refresh_mspeed_y;
bool refresh_mspeed_z;
bool refresh_mspeed_e;
bool refresh_print_speed;
bool print_file_ok;

int msg_id;
unsigned char print_state;  //0:未打印或打印停止，1：正在打印，2：暂停打印，3：打印完成
static lv_task_t * my_task;

//void memory_print(void)
//{
//    char myper[6];
//    lv_mem_monitor_t mon;
//    lv_mem_monitor(&mon);
////    printf("used: %6d , biggest free: %6d\n", (int)mon.total_size - mon.free_size,(int)mon.free_biggest_size);
//    int total = mon.total_size;
//    int free_cn = mon.free_cnt;
//    int used_cn = mon.used_cnt;
//    int free_s = mon.free_size;
//    snprintf(myper, 6, "%5d", free_s);
//    msgbox(myper);
////    max_used = 0;
//}


void lv_demo_printer_anim_in_all(lv_obj_t * obj, uint32_t delay)
{
//    return;
    if(delay == 0)
        return;
    lv_coord_t y;
    lv_obj_t * child = lv_obj_get_child_back(obj, NULL);
    while(child) {
        y = lv_obj_get_y(child);
        if (child != lv_scr_act()) {
            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);
            lv_anim_set_var(&a, child);
            lv_anim_set_time(&a, LV_DEMO_PRINTER_ANIM_TIME);

            if(y > 400)
                lv_anim_set_values(&a, 799, y);
            else
                lv_anim_set_values(&a, 0, y);
            lv_anim_set_delay(&a, delay);

            lv_anim_start(&a);

//            lv_obj_fade_in(child, LV_DEMO_PRINTER_ANIM_TIME - 20, delay);
        }
        child = lv_obj_get_child_back(obj, child);
    }
}

lv_obj_t **get_scr_by_id(int scr_id)
{
    if(scr_id == SCR_HOME_PAGE)
        return &guider_ui.home_cont_home;
    else if(scr_id == SCR_PRINT_PAGE)
        return &guider_ui.print_cont_print;
    else if(scr_id == SCR_PREPARE_MOVE_AXIS_PAGE)
        return &guider_ui.prepare_move_axis_cont_prepare_move_axis;
    else if(scr_id == SCR_PREPARE_MATERIAL_PAGE)
        return &guider_ui.prepare_material_cont_prepare_material;
    else if(scr_id == SCR_PREPARE_MANUAL_TEMP_PAGE)
        return &guider_ui.prepare_manual_temp_cont_prepare_manual_temp;
    else if(scr_id == SCR_SETTING_DEVICE_PAGE)
        return &guider_ui.setting_device_cont_seting_device;
    else if(scr_id == SCR_SETTING_AD_SETTING_PAGE)
        return &guider_ui.setting_ad_setting_cont_setting_ad_setting;
    else if(scr_id == SCR_SETTING_ABOUT_PAGE)
        return &guider_ui.setting_about_cont_setting_about;
    else if(scr_id == SCR_LANGUAGE_PAGE)
        return &guider_ui.Language_cont_language;
    else if(scr_id == SCR_LEVEL_AUTO_PAGE)
        return &guider_ui.Level_auto_cont_level_auto;
    else if(scr_id == SCR_LEVEL_MANUAL_PAGE)
        return &guider_ui.Level_manual_cont_level_manual;
    else if(scr_id == SCR_MOTIONSET_PAGE)
        return &guider_ui.MotionSet_cont_motion_set;
    else if(scr_id == SCR_RTOSET_PAGE)
        return &guider_ui.RTOSet_cont_rto_set;
    else if(scr_id == SCR_MAXACCSET_PAGE)
        return &guider_ui.MaxAccSet_cont_max_acc_set;
    else if(scr_id == SCR_MAXCONCORSET_PAGE)
        return &guider_ui.MaxConcorSet_cont_max_concor_set;
    else if(scr_id == SCR_MAXSPEEDSET_PAGE)
        return &guider_ui.MaxSpeedSet_cont_max_speed_set;
    else if(scr_id == SCR_TEMPPIDSET_PAGE)
        return &guider_ui.TempPIDSet_cont_temppid_set;
    else if(scr_id == SCR_PRINTINGSET_PAGE)
        return &guider_ui.PrintingSet_cont_printing_set;
    else if(scr_id == SCR_ZOFFSETSET_PAGE)
        return &guider_ui.ZoffsetSet_cont_zoffset_set;
    else if(scr_id == SCR_PREHEATING_PAGE)
        return &guider_ui.Preheating_cont_preheating;
    else if(scr_id == SCR_MSGBOX_PAGE)
        return &guider_ui.Msgboxs_cont_msgboxs;
    else if(scr_id == SCR_INPUTBOXS_PAGE)
        return &guider_ui.Inputboxs_cont_inputboxs;

    return NULL;
}

void guider_load_screen(int scr_id)
{
    lv_obj_t **old_scr = NULL;

    if(my_task != NULL)
    {
        lv_task_del(my_task);
        my_task = NULL;
    }

//    if(check_time())
//    {
//        return;
//    }
	tick_start = lv_tick_get();

//    lv_scr_load(guider_ui.home);
//    old_scr = get_scr_by_id(cur_scr);
//    lv_obj_clean(*old_scr);
//    lv_obj_del(*old_scr);
//
//    *old_scr = NULL;
//    cur_scr = scr_id;

    switch(scr_id)
    {
        case SCR_HOME_PAGE:
            setup_scr_menu(&guider_ui);
            setup_scr_home(&guider_ui);
            home_event_init();
            if(guider_ui.prepare_menu_cont_prepare_menu != NULL)
            {
                lv_obj_clean(guider_ui.prepare_menu_cont_prepare_menu);
                lv_obj_del(guider_ui.prepare_menu_cont_prepare_menu);
                guider_ui.prepare_menu_cont_prepare_menu = NULL;
            }
            if(guider_ui.setting_menu_cont_seting_menu != NULL)
            {
                lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                guider_ui.setting_menu_cont_seting_menu = NULL;
            }
            printf("load home page\n");
            break;
        case SCR_PRINT_PAGE:
            setup_scr_menu(&guider_ui);
            setup_scr_print(&guider_ui);
            print_event_init();
            if(guider_ui.prepare_menu_cont_prepare_menu != NULL)
            {
                lv_obj_clean(guider_ui.prepare_menu_cont_prepare_menu);
                lv_obj_del(guider_ui.prepare_menu_cont_prepare_menu);
                guider_ui.prepare_menu_cont_prepare_menu = NULL;
            }
            if(guider_ui.setting_menu_cont_seting_menu != NULL)
            {
                lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                guider_ui.setting_menu_cont_seting_menu = NULL;
            }
            printf("load print page\n");
            break;
        case SCR_PREPARE_MOVE_AXIS_PAGE:
            setup_scr_menu(&guider_ui);
            setup_scr_prepare_move_axis(&guider_ui);
            setup_scr_prepare_menu(&guider_ui);
            prepare_move_axis_event_init();
            if(guider_ui.setting_menu_cont_seting_menu != NULL)
            {
                lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                guider_ui.setting_menu_cont_seting_menu = NULL;
            }
            printf("load prepare move axis page\n");
            break;
        case SCR_PREPARE_MATERIAL_PAGE:
            setup_scr_menu(&guider_ui);
            setup_scr_prepare_material(&guider_ui);
            setup_scr_prepare_menu(&guider_ui);
            prepare_material_event_init();
            if(guider_ui.setting_menu_cont_seting_menu != NULL)
            {
                lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                guider_ui.setting_menu_cont_seting_menu = NULL;
            }
            printf("load prepare material page\n");
            break;
        case SCR_PREPARE_MANUAL_TEMP_PAGE:
            setup_scr_menu(&guider_ui);
            setup_scr_prepare_manual_temp(&guider_ui);
            setup_scr_prepare_menu(&guider_ui);
            prepare_manual_temp_event_init();
            if(guider_ui.setting_menu_cont_seting_menu != NULL)
            {
                lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                guider_ui.setting_menu_cont_seting_menu = NULL;
            }
            printf("load prepare manual temp page\n");
            break;
        case SCR_SETTING_DEVICE_PAGE:
                setup_scr_menu(&guider_ui);
                setup_scr_setting_device(&guider_ui);
                setup_scr_setting_menu(&guider_ui);
                setting_device_event_init();
                if(guider_ui.prepare_menu_cont_prepare_menu != NULL)
                {
                    lv_obj_clean(guider_ui.prepare_menu_cont_prepare_menu);
                    lv_obj_del(guider_ui.prepare_menu_cont_prepare_menu);
                    guider_ui.prepare_menu_cont_prepare_menu = NULL;
                }
                printf("load setting device page\n");
            break;
        case SCR_SETTING_AD_SETTING_PAGE:
                setup_scr_menu(&guider_ui);
                setup_scr_setting_ad_setting(&guider_ui);
                setup_scr_setting_menu(&guider_ui);
                setting_ad_setting_event_init();
                if(guider_ui.prepare_menu_cont_prepare_menu != NULL)
                {
                    lv_obj_clean(guider_ui.prepare_menu_cont_prepare_menu);
                    lv_obj_del(guider_ui.prepare_menu_cont_prepare_menu);
                    guider_ui.prepare_menu_cont_prepare_menu = NULL;
                }
                printf("load setting ad_setting page\n");
            break;
        case SCR_SETTING_ABOUT_PAGE:
                setup_scr_menu(&guider_ui);
                setup_scr_setting_about(&guider_ui);
                setup_scr_setting_menu(&guider_ui);
                setting_about_event_init();
                if(guider_ui.prepare_menu_cont_prepare_menu != NULL)
                {
                    lv_obj_clean(guider_ui.prepare_menu_cont_prepare_menu);
                    lv_obj_del(guider_ui.prepare_menu_cont_prepare_menu);
                    guider_ui.prepare_menu_cont_prepare_menu = NULL;
                }
                printf("load setting about page\n");
            break;
        case SCR_LANGUAGE_PAGE:
                setup_scr_Language(&guider_ui);
                language_event_init();
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_obj_clean(guider_ui.menu_cont_menu);
                    lv_obj_del(guider_ui.menu_cont_menu);
                    guider_ui.menu_cont_menu = NULL;
                }
                if(guider_ui.setting_menu_cont_seting_menu != NULL)
                {
                    lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                    lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                    guider_ui.setting_menu_cont_seting_menu = NULL;
                }
                printf("load language page\n");
            break;
        case SCR_LEVEL_AUTO_PAGE:
                setup_scr_Level_menu(&guider_ui);
                setup_scr_Level_auto(&guider_ui);
                setup_scr_Level_title(&guider_ui);
                levle_auto_event_init();
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_obj_clean(guider_ui.menu_cont_menu);
                    lv_obj_del(guider_ui.menu_cont_menu);
                    guider_ui.menu_cont_menu = NULL;
                }
                if(guider_ui.setting_menu_cont_seting_menu != NULL)
                {
                    lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                    lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                    guider_ui.setting_menu_cont_seting_menu = NULL;
                }
                printf("load level auto page\n");

            break;
        case SCR_LEVEL_MANUAL_PAGE:
                setup_scr_Level_menu(&guider_ui);
                setup_scr_Level_manual(&guider_ui);
                setup_scr_Level_title(&guider_ui);
                levle_manual_event_init();
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_obj_clean(guider_ui.menu_cont_menu);
                    lv_obj_del(guider_ui.menu_cont_menu);
                    guider_ui.menu_cont_menu = NULL;
                }
                if(guider_ui.setting_menu_cont_seting_menu != NULL)
                {
                    lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                    lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                    guider_ui.setting_menu_cont_seting_menu = NULL;
                }
                printf("load level manual page\n");
            break;
        case SCR_MOTIONSET_PAGE:
                setup_scr_MotionSet(&guider_ui);
                motionset_event_init();
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_obj_clean(guider_ui.menu_cont_menu);
                    lv_obj_del(guider_ui.menu_cont_menu);
                    guider_ui.menu_cont_menu = NULL;
                }
                if(guider_ui.setting_menu_cont_seting_menu != NULL)
                {
                    lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                    lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                    guider_ui.setting_menu_cont_seting_menu = NULL;
                }
                printf("load motion set page\n");
            break;
        case SCR_RTOSET_PAGE:
                setup_scr_RTOSet(&guider_ui);
                rtoset_event_init();
                printf("load RTO set page\n");
            break;
        case SCR_MAXACCSET_PAGE:
                setup_scr_MaxAccSet(&guider_ui);
                maxaccset_event_init();
                printf("load max acc set page\n");
            break;
        case SCR_MAXCONCORSET_PAGE:
                setup_scr_MaxConcorSet(&guider_ui);
                maxconcorset_event_init();
            break;
        case SCR_MAXSPEEDSET_PAGE:
                setup_scr_MaxSpeedSet(&guider_ui);
                maxspeedset_event_init();
                printf("load max speed set page\n");
            break;
        case SCR_TEMPPIDSET_PAGE:
                setup_scr_TempPIDSet(&guider_ui);
                tempPIDset_event_init();
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_obj_clean(guider_ui.menu_cont_menu);
                    lv_obj_del(guider_ui.menu_cont_menu);
                    guider_ui.menu_cont_menu = NULL;
                }
                if(guider_ui.setting_menu_cont_seting_menu != NULL)
                {
                    lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                    lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                    guider_ui.setting_menu_cont_seting_menu = NULL;
                }
                printf("load TempPIDSet page\n");
            break;
         case SCR_PRINTINGSET_PAGE:
                setup_scr_PrintingSet(&guider_ui);
                printingset_event_init();
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_obj_clean(guider_ui.menu_cont_menu);
                    lv_obj_del(guider_ui.menu_cont_menu);
                    guider_ui.menu_cont_menu = NULL;
                }
                printf("load printing set page\n");
            break;
         case SCR_ZOFFSETSET_PAGE:
                setup_scr_ZoffsetSet(&guider_ui);
                zoffset_event_init();
                printf("load zoffset set page\n");
            break;
        case SCR_PREHEATING_PAGE:
                setup_scr_Preheating(&guider_ui);
                preheating_event_init();
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_obj_clean(guider_ui.menu_cont_menu);
                    lv_obj_del(guider_ui.menu_cont_menu);
                    guider_ui.menu_cont_menu = NULL;
                }
                if(guider_ui.setting_menu_cont_seting_menu != NULL)
                {
                    lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                    lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                    guider_ui.setting_menu_cont_seting_menu = NULL;
                }
                printf("load preheating page\n");
            break;
        case SCR_MSGBOX_PAGE:
                setup_scr_Msgboxs(&guider_ui);
                msgboxs_event_init();
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_obj_clean(guider_ui.menu_cont_menu);
                    lv_obj_del(guider_ui.menu_cont_menu);
                    guider_ui.menu_cont_menu = NULL;
                }
                if(guider_ui.prepare_menu_cont_prepare_menu != NULL)
                {
                    lv_obj_clean(guider_ui.prepare_menu_cont_prepare_menu);
                    lv_obj_del(guider_ui.prepare_menu_cont_prepare_menu);
                    guider_ui.prepare_menu_cont_prepare_menu = NULL;
                }
                if(guider_ui.setting_menu_cont_seting_menu != NULL)
                {
                    lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                    lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                    guider_ui.setting_menu_cont_seting_menu = NULL;
                }
                printf("load msgbox page\n");
            break;
        case SCR_INPUTBOXS_PAGE:
                setup_scr_Inputboxs(&guider_ui);
                inputboxs_event_init();
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_obj_clean(guider_ui.menu_cont_menu);
                    lv_obj_del(guider_ui.menu_cont_menu);
                    guider_ui.menu_cont_menu = NULL;
                }
                if(guider_ui.setting_menu_cont_seting_menu != NULL)
                {
                    lv_obj_clean(guider_ui.setting_menu_cont_seting_menu);
                    lv_obj_del(guider_ui.setting_menu_cont_seting_menu);
                    guider_ui.setting_menu_cont_seting_menu = NULL;
                }
                if(guider_ui.prepare_menu_cont_prepare_menu != NULL)
                {
                    lv_obj_clean(guider_ui.prepare_menu_cont_prepare_menu);
                    lv_obj_del(guider_ui.prepare_menu_cont_prepare_menu);
                    guider_ui.prepare_menu_cont_prepare_menu = NULL;
                }
                printf("load inputboxs page\n");
            break;
    }
//    lv_scr_load(guider_ui.home);
    old_scr = get_scr_by_id(cur_scr);
    lv_obj_clean(*old_scr);
    lv_obj_del(*old_scr);

    *old_scr = NULL;
    cur_scr = scr_id;
//    memory_print();

}

unsigned int file_click_num;
void load_print_confirm_cb(struct _lv_obj_t * obj, lv_event_t event){
 char myper[4];
 if (event == LV_EVENT_CLICKED) {
        switch(msg_id){
            case PRINT_FILE:
                big_photo_name[0] = '\0';
                snprintf(myper, FILE_NUM_SIZE+1, "%03d", file_click_num);
                set_printer_data(0x05,strlen(myper),myper);
                printf("myper = %s\n", myper);
//                char data[] = "23\t258\t987\t0.18\tlv_lib_png/modeltest.png\n";
//                get_response_printer_data(0x01, strlen(data) , data);
//                char data1[] = "09:12\t100\0";
//                get_response_printer_data(0x0d,strlen(data1) , data1);
                break;
            case PRINTING_RESUME:
                set_printer_data(0x06,1,"3");
                printf("resume print\n");
                break;
            case PRINTING_STOP:
                set_printer_data(0x06,1,"1");
                printf("stop print\n");
                break;
            case PRINTING_PAUSE:
                set_printer_data(0x06,1,"2");
                printf("pause print\n");
                break;
            default:
                break;
        }
    }
}

void load_print_cancel_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_CLICKED) {
        switch(msg_id){
            case PRINT_FILE:
                guider_load_screen(SCR_PRINT_PAGE);
//                lv_list_clean(guider_ui.print_list_1);
                lv_btn_set_state(guider_ui.menu_btn_print,LV_BTN_STATE_PRESSED);
                lv_obj_set_click(guider_ui.menu_btn_print, false);
                lv_obj_set_click(guider_ui.menu_img_print, false);
                lv_demo_printer_anim_in_all(guider_ui.print_cont_print, LV_DEMO_PRINTER_ANIM_DELAY);
//                handle_file(current_page);
                printf("cancel print file\n");
                break;
            case PRINTING_PAUSE:
                print_state = 1;
                guider_load_screen(SCR_HOME_PAGE);
                lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
                lv_obj_set_click(guider_ui.menu_btn_home, false);
                lv_obj_set_click(guider_ui.menu_img_home, false);
                lv_obj_set_click(guider_ui.menu_btn_print, false);
                lv_obj_set_click(guider_ui.menu_img_print, false);
                lv_obj_set_click(guider_ui.menu_btn_prepare, false);
                lv_obj_set_click(guider_ui.menu_img_prepare, false);
                lv_obj_set_click(guider_ui.menu_btn_setting, false);
                lv_obj_set_click(guider_ui.menu_img_setting, false);
                lv_demo_printer_anim_in_all(guider_ui.home_cont_home, LV_DEMO_PRINTER_ANIM_DELAY);
                printf("pause print file\n");
                break;
            case PRINTING_STOP:
                print_state = 1;
                guider_load_screen(SCR_HOME_PAGE);
                lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
                lv_obj_set_click(guider_ui.menu_btn_home, false);
                lv_obj_set_click(guider_ui.menu_img_home, false);
                lv_obj_set_click(guider_ui.menu_btn_print, false);
                lv_obj_set_click(guider_ui.menu_img_print, false);
                lv_obj_set_click(guider_ui.menu_btn_prepare, false);
                lv_obj_set_click(guider_ui.menu_img_prepare, false);
                lv_obj_set_click(guider_ui.menu_btn_setting, false);
                lv_obj_set_click(guider_ui.menu_img_setting, false);
                lv_demo_printer_anim_in_all(guider_ui.home_cont_home, LV_DEMO_PRINTER_ANIM_DELAY);
                printf("stop print file\n");
                break;
            case PRINTING_RESUME:
                print_state = 2;
                guider_load_screen(SCR_HOME_PAGE);
                lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
                lv_obj_set_click(guider_ui.menu_btn_home, false);
                lv_obj_set_click(guider_ui.menu_img_home, false);
                lv_obj_set_click(guider_ui.menu_btn_print, false);
                lv_obj_set_click(guider_ui.menu_img_print, false);
                lv_obj_set_click(guider_ui.menu_btn_prepare, false);
                lv_obj_set_click(guider_ui.menu_img_prepare, false);
                lv_obj_set_click(guider_ui.menu_btn_setting, false);
                lv_obj_set_click(guider_ui.menu_img_setting, false);
                lv_demo_printer_anim_in_all(guider_ui.home_cont_home, LV_DEMO_PRINTER_ANIM_DELAY);
                printf("resume print file\n");
                break;
            default:
                break;
        }
    }
}

void print_stop_event_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        guider_load_screen(SCR_MSGBOX_PAGE);
        lv_label_set_text(guider_ui.Msgboxs_label_title,tips[cur_language]);
        lv_label_set_text(guider_ui.Msgboxs_label_msgbox_secondline,stop_print[cur_language]);
        lv_demo_printer_anim_in_all(guider_ui.Msgboxs_cont_msgboxs, LV_DEMO_PRINTER_ANIM_DELAY);
        msg_id = PRINTING_STOP;
        lv_obj_set_event_cb(guider_ui.Msgboxs_btn_confirm, load_print_confirm_cb);
        lv_obj_set_event_cb(guider_ui.Msgboxs_btn_cancel, load_print_cancel_cb);
        printf("stop print file\n");
    }
}

void print_pause_event_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        guider_load_screen(SCR_MSGBOX_PAGE);
        lv_label_set_text(guider_ui.Msgboxs_label_title,tips[cur_language]);
        lv_label_set_text(guider_ui.Msgboxs_label_msgbox_secondline,pause_print[cur_language]);
        lv_demo_printer_anim_in_all(guider_ui.Msgboxs_cont_msgboxs, LV_DEMO_PRINTER_ANIM_DELAY);
        msg_id = PRINTING_PAUSE;
        lv_obj_set_event_cb(guider_ui.Msgboxs_btn_confirm, load_print_confirm_cb);
        lv_obj_set_event_cb(guider_ui.Msgboxs_btn_cancel, load_print_cancel_cb);
        printf("pause print file\n");
    }
}

void print_resume_event_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        guider_load_screen(SCR_MSGBOX_PAGE);
        lv_label_set_text(guider_ui.Msgboxs_label_title,tips[cur_language]);
        lv_label_set_text(guider_ui.Msgboxs_label_msgbox_secondline,resume_print[cur_language]);
        lv_demo_printer_anim_in_all(guider_ui.Msgboxs_cont_msgboxs, LV_DEMO_PRINTER_ANIM_DELAY);
        msg_id = PRINTING_RESUME;
        lv_obj_set_event_cb(guider_ui.Msgboxs_btn_confirm, load_print_confirm_cb);
        lv_obj_set_event_cb(guider_ui.Msgboxs_btn_cancel, load_print_cancel_cb);
        printf("resume print file\n");
    }
}

void print_finsh_event_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        print_state = 0;
        lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
        lv_obj_set_click(guider_ui.menu_btn_home, false);
        lv_obj_set_click(guider_ui.menu_img_home, false);
        lv_obj_set_click(guider_ui.menu_btn_print, true);
        lv_obj_set_click(guider_ui.menu_img_print, true);
        lv_obj_set_click(guider_ui.menu_btn_prepare, true);
        lv_obj_set_click(guider_ui.menu_img_prepare, true);
        lv_obj_set_click(guider_ui.menu_btn_setting, true);
        lv_obj_set_click(guider_ui.menu_img_setting, true);
        lv_obj_set_hidden(guider_ui.home_btn_background,true);
        lv_obj_set_hidden(guider_ui.home_img_finish,true);
        lv_obj_set_hidden(guider_ui.home_img_start,true);
        lv_obj_set_hidden(guider_ui.home_img_pause,true);
        lv_obj_set_hidden(guider_ui.home_btn_stop,true);
        lv_obj_set_hidden(guider_ui.home_line_fenge,true);
        lv_obj_set_hidden(guider_ui.home_label_file_name,true);
        lv_obj_set_hidden(guider_ui.home_label_remain_time,true);
        lv_obj_set_hidden(guider_ui.home_label_fin_percent,true);
        if(big_photo_name[0] == '\0')
        {
            lv_obj_set_hidden(guider_ui.home_arc_progress,true);
        }
        else
        {
            lv_obj_set_hidden(guider_ui.home_img_model,true);
            lv_obj_set_hidden(guider_ui.home_btn_mask,true);
            big_photo_name[0] = '\0';
        }
        lv_obj_set_hidden(guider_ui.home_img_logo,false);
        lv_obj_set_hidden(guider_ui.home_img_12,false);
        printf("finish print\n");
    }
}

// img对象设置png图片自适应显示
static void lv_obj_img_png_set_zoom(lv_obj_t * obj_img, const char *src, uint32_t obj_width, uint32_t obj_height)
{
    if (obj_img == NULL || src == NULL || src[0] == '\0')
    {
        printf("[%s:%d] param errror\n", __FUNCTION__, __LINE__);
        return;
    }

    if (obj_width == 0 || obj_height == 0)
    {
        printf("[%s:%d] param errror\n", __FUNCTION__, __LINE__);
        return;
    }

    uint32_t img_width = 0, img_height = 0, zoom_factor = 0;
    // 获取img对象的信息
    lv_img_header_t header;
    if (lv_img_decoder_get_info(src, &header) != LV_RES_OK)
    {
        printf("[%s:%d] lv_img_decoder_get_info errror\n", __FUNCTION__, __LINE__);
        return;
    }

    img_width = header.w;
    img_height = header.h;

//    printf("[%s:%d] img_width:%u, img_height:%u, obj_width:%u, obj_height:%u\n", __FUNCTION__, __LINE__, img_width, img_height, obj_width, obj_height);
    if (img_width != 0 && img_height != 0)
    {
        uint32_t y_a= obj_height * img_width;
        uint32_t x_b= obj_width * img_height;

        if (x_b >= y_a)
        {
            if (img_height >= obj_height)
            {
                uint32_t x = obj_height * 256;
                zoom_factor = x / img_height;
                lv_img_set_zoom(obj_img, zoom_factor);
            }
        }
        else
        {
            if (img_width > obj_width)
            {
                uint32_t x = obj_width * 256;
                zoom_factor = x / img_width;
                lv_img_set_zoom(obj_img, zoom_factor);
            }
        }
    }
}

void show_model_image(char *data)
{
    lv_obj_set_hidden(guider_ui.home_arc_progress,true);
    lv_img_set_src(guider_ui.home_img_model, data); // 设置图片
    lv_obj_img_png_set_zoom(guider_ui.home_img_model, data, 300, 300);
//    lv_obj_set_pos(guider_ui.home_img_model, -60, 108);     //缩放后需要重新定位位置，原有的位置减去，缩放差值的一半
}

void home_event_init(void)
{
    int num;
//    show_model_image("lv_lib_png/modeltest.png");
    get_printer_data(0x02, 1, "0");
    get_printer_data(0x03, 1, "0");
	if(hotend_max_temp[0] != '\0')
	{
		lv_label_set_text(guider_ui.home_label_max_ht_temp, &hotend_max_temp[0]);
	}
	if(hotend_cur_temp[0] != '\0')
	{
		lv_label_set_text(guider_ui.home_label_cur_ht_temp, &hotend_cur_temp[0]);
	}
	if(bed_max_temp[0] != '\0')
	{
		lv_label_set_text(guider_ui.home_label_max_bed_temp, &bed_max_temp[0]);
	}
	if(bed_cur_temp[0] != '\0')
	{
		lv_label_set_text(guider_ui.home_label_cur_bed_temp, &bed_cur_temp[0]);
	}
	if(cur_speed[0] != '\0')
	{
        char temp[CUR_SPEED_LEN+2];
        unsigned char i;
	    for(i=0;i<CUR_SPEED_LEN;i++)
        {
            if(cur_speed[i] == '\0')
            {
                break;
            }
            temp[i] = cur_speed[i];
        }
        temp[i] = '%';
        temp[i+1] = '\0';
		lv_label_set_text(guider_ui.home_label_cur_speed, &temp[0]);
	}
	if(zoffset_value[0] != '\0')
	{
		lv_label_set_text(guider_ui.home_label_cur_zoffset, &zoffset_value[0]);
	}
	printf("print_state = %d\n",print_state);

    char temp[PERCENT_LEN+2] = {'\0'};
    unsigned char i;
    num = 0;
    if(print_percent[0] != '\0')
    {
        for(i=0;i<PERCENT_LEN;i++)
        {
            if(print_percent[i] == '\0')
            {
                break;
            }
            temp[i] = print_percent[i];
        }
        temp[i] = '%';
        temp[i+1] = '\0';
        num = atoi(print_percent);
    }

	switch(print_state){
        case 0:
            set_refresh_data(0x01);
            lv_obj_set_hidden(guider_ui.home_btn_background,true);
            lv_obj_set_hidden(guider_ui.home_img_finish,true);
            lv_obj_set_hidden(guider_ui.home_img_start,true);
            lv_obj_set_hidden(guider_ui.home_img_pause,true);
            lv_obj_set_hidden(guider_ui.home_btn_stop,true);
            lv_obj_set_hidden(guider_ui.home_line_fenge,true);
            lv_obj_set_hidden(guider_ui.home_label_file_name,true);
            lv_obj_set_hidden(guider_ui.home_label_remain_time,true);
            lv_obj_set_hidden(guider_ui.home_label_fin_percent,true);
            lv_obj_set_hidden(guider_ui.home_arc_progress,true);
            lv_obj_set_hidden(guider_ui.home_img_model,true);
            lv_obj_set_hidden(guider_ui.home_btn_mask,true);
            lv_obj_set_click(guider_ui.home_btn_printing, false);
            break;
        case 1:
            get_printer_data(0x0d, 1, "0");
            set_refresh_data(0x05);
            lv_obj_set_hidden(guider_ui.home_img_logo,true);
            lv_obj_set_hidden(guider_ui.home_img_12,true);
            lv_obj_set_click(guider_ui.home_btn_background, false);
            lv_obj_set_click(guider_ui.home_img_finish, false);
            lv_obj_set_click(guider_ui.home_img_start, false);
            lv_obj_set_click(guider_ui.home_btn_printing, true);
            lv_obj_set_hidden(guider_ui.home_btn_background,false);
            lv_obj_set_hidden(guider_ui.home_img_finish,true);
            lv_obj_set_hidden(guider_ui.home_img_start,true);
            lv_obj_set_hidden(guider_ui.home_img_pause,false);
            lv_obj_set_hidden(guider_ui.home_btn_stop,false);
            lv_obj_set_hidden(guider_ui.home_line_fenge,false);
            lv_obj_set_hidden(guider_ui.home_label_file_name,false);
            lv_obj_set_hidden(guider_ui.home_label_remain_time,false);
            lv_obj_set_hidden(guider_ui.home_label_fin_percent,false);
            if(printing_file_name[0] != '\0')
            {
                lv_label_set_text(guider_ui.home_label_file_name, printing_file_name);
            }

            if(big_photo_name[0] == '\0')
            {
                lv_obj_set_hidden(guider_ui.home_img_model,true);
                lv_obj_set_hidden(guider_ui.home_btn_mask,true);
                lv_obj_set_hidden(guider_ui.home_arc_progress,false);
                // if(i>3) i=3;
                // temp[i] = '%';
                // temp[i+1] = '\0';
                lv_label_set_text(guider_ui.home_label_fin_percent, &temp[0]);
                lv_arc_set_value(guider_ui.home_arc_progress,num);
            }
            else
            {
                lv_obj_set_hidden(guider_ui.home_img_model,false);
                lv_obj_set_hidden(guider_ui.home_btn_mask,false);
                lv_obj_set_hidden(guider_ui.home_arc_progress,true);
                lv_img_set_src(guider_ui.home_img_model,big_photo_name);
                unsigned int hg = num * (model_end_pix - model_start_pix) / 100 + model_start_pix;
                lv_obj_set_pos(guider_ui.home_btn_mask, 90, 558 - hg);
                lv_obj_set_size(guider_ui.home_btn_mask, 300, hg);
                //设置灌水效果
            }
            if(print_remain_time[0] != '\0')
            {
                lv_label_set_text(guider_ui.home_label_remain_time, &print_remain_time[0]);
            }
            lv_obj_set_event_cb(guider_ui.home_btn_stop, print_stop_event_cb);
            lv_obj_set_event_cb(guider_ui.home_img_pause, print_pause_event_cb);
            break;
        case 2:
            get_printer_data(0x0d, 1, "0");
            set_refresh_data(0x05);
            lv_obj_set_hidden(guider_ui.home_img_logo,true);
            lv_obj_set_hidden(guider_ui.home_img_12,true);
            lv_obj_set_click(guider_ui.home_btn_background, false);
            lv_obj_set_click(guider_ui.home_img_finish, false);
            lv_obj_set_click(guider_ui.home_img_pause, false);
            lv_obj_set_click(guider_ui.home_btn_printing, true);
            lv_obj_set_hidden(guider_ui.home_btn_background,false);
            lv_obj_set_hidden(guider_ui.home_img_finish,true);
            lv_obj_set_hidden(guider_ui.home_img_start,false);
            lv_obj_set_hidden(guider_ui.home_img_pause,true);
            lv_obj_set_hidden(guider_ui.home_btn_stop,false);
            lv_obj_set_hidden(guider_ui.home_line_fenge,false);
            lv_obj_set_hidden(guider_ui.home_label_file_name,false);
            lv_obj_set_hidden(guider_ui.home_label_remain_time,false);
            lv_obj_set_hidden(guider_ui.home_label_fin_percent,false);
            if(printing_file_name[0] != '\0')
            {
                lv_label_set_text(guider_ui.home_label_file_name, printing_file_name);
            }

            if(big_photo_name[0] == '\0')
            {
                lv_obj_set_hidden(guider_ui.home_img_model,true);
                lv_obj_set_hidden(guider_ui.home_btn_mask,true);
                lv_obj_set_hidden(guider_ui.home_arc_progress,false);
                // if(i>3) i=3;
                // temp[i] = '%';
                // temp[i+1] = '\0';
                lv_label_set_text(guider_ui.home_label_fin_percent, &temp[0]);
                lv_arc_set_value(guider_ui.home_arc_progress,num);
            }
            else
            {
                lv_obj_set_hidden(guider_ui.home_img_model,false);
                lv_obj_set_hidden(guider_ui.home_btn_mask,false);
                lv_obj_set_hidden(guider_ui.home_arc_progress,true);
                lv_img_set_src(guider_ui.home_img_model,big_photo_name);
                unsigned int hg = num * (model_end_pix - model_start_pix) / 100 + model_start_pix;
                lv_obj_set_pos(guider_ui.home_btn_mask, 90, 558 - hg);
                lv_obj_set_size(guider_ui.home_btn_mask, 300, hg);
                //设置灌水效果
            }

            if(print_remain_time[0] != '\0')
            {
                lv_label_set_text(guider_ui.home_label_remain_time, &print_remain_time[0]);
            }
            lv_obj_set_event_cb(guider_ui.home_btn_stop, print_stop_event_cb);
            lv_obj_set_event_cb(guider_ui.home_img_start, print_resume_event_cb);
            break;
        case 3:
//            get_printer_data(0x0d, 1, "0");
            set_refresh_data(0x01);
            lv_obj_set_hidden(guider_ui.home_img_logo,true);
            lv_obj_set_hidden(guider_ui.home_img_12,true);
            lv_obj_set_click(guider_ui.home_img_finish, true);
            lv_obj_set_click(guider_ui.home_btn_background, true);
            lv_obj_set_click(guider_ui.home_img_start, false);
            lv_obj_set_click(guider_ui.home_img_pause, false);
            lv_obj_set_click(guider_ui.home_btn_stop, false);
            lv_obj_set_click(guider_ui.home_btn_printing, false);
            lv_obj_set_hidden(guider_ui.home_btn_background,false);
            lv_obj_set_hidden(guider_ui.home_img_finish,false);
            lv_obj_set_hidden(guider_ui.home_img_start,true);
            lv_obj_set_hidden(guider_ui.home_img_pause,true);
            lv_obj_set_hidden(guider_ui.home_btn_stop,true);
            lv_obj_set_hidden(guider_ui.home_line_fenge,true);
            lv_obj_set_hidden(guider_ui.home_label_file_name,false);
            lv_obj_set_hidden(guider_ui.home_label_remain_time,false);
            lv_obj_set_hidden(guider_ui.home_label_fin_percent,false);
            if(printing_file_name[0] != '\0')
            {
                lv_label_set_text(guider_ui.home_label_file_name, printing_file_name);
            }

            if(big_photo_name[0] == '\0')
            {
                lv_obj_set_hidden(guider_ui.home_img_model,true);
                lv_obj_set_hidden(guider_ui.home_btn_mask,true);
                lv_obj_set_hidden(guider_ui.home_arc_progress,false);
                // if(i>3) i=3;
                // temp[i] = '%';
                // temp[i+1] = '\0';
                lv_label_set_text(guider_ui.home_label_fin_percent, &temp[0]);
                lv_arc_set_value(guider_ui.home_arc_progress,num);
            }
            else
            {
                lv_obj_set_hidden(guider_ui.home_img_model,false);
                lv_obj_set_hidden(guider_ui.home_btn_mask,false);
                lv_obj_set_hidden(guider_ui.home_arc_progress,true);
                lv_img_set_src(guider_ui.home_img_model,big_photo_name);
                unsigned int hg = num * (model_end_pix - model_start_pix) / 100 + model_start_pix;
                lv_obj_set_pos(guider_ui.home_btn_mask, 90, 558 - hg);
                lv_obj_set_size(guider_ui.home_btn_mask, 300, hg);
                //设置灌水效果
            }

            if(print_remain_time[0] != '\0')
            {
                lv_label_set_text(guider_ui.home_label_remain_time, &print_remain_time[0]);
            }
            lv_obj_set_event_cb(guider_ui.home_img_finish, print_finsh_event_cb);
            lv_obj_set_event_cb(guider_ui.home_btn_background, print_finsh_event_cb);
            break;
	}
//	show_model_image("lv_lib_png/modeltest.png");
}

void file_list_btn_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        const char *title = lv_list_get_btn_text(obj);
        file_click_num = lv_list_get_btn_index(NULL,obj) + current_page * FILE_NUM_PRE_PAGE + 1;
        for(unsigned char i=0;i<FILE_SIZE;i++)
        {
            printing_file_name[i] = *title++;
            if(*title == '\0')
            {
                printing_file_name[i+1] = '\0';
                break;
            }
        }
//        int32_t index = lv_list_get_btn_index(NULL,obj) + current_page * FILE_NUM_PRE_PAGE;
//        char *file_copy = malloc(strlen(file_names));
//        memcpy(file_copy,file_names,strlen(file_names));
//        char *temp = strtok(file_copy,"\n");
//        unsigned char i = 0;
//        file_name_num = 0;
//        while(temp)
//        {
//            if(i == index)
//            {
//                free((void *)printing_file_name);
//                printing_file_name = malloc(strlen(temp));
//
//                for(unsigned char i=0;i<strlen(temp);i++)
//                {
//                    printing_file_name[i] = temp[i];
//                    if(temp[i] == '/')
//                    {
//                        file_name_num = i+1;
//                    }
//                    if(temp[i] == 0x20)
//                    {
//                        printing_file_name[i+1] = '\0';
//                        break;
//                    }
//                }
//                break;
//            }
//            temp = strtok(NULL,"\n");
//            i++;
//        }
//        free((void *)file_copy);

        guider_load_screen(SCR_MSGBOX_PAGE);
        lv_label_set_text(guider_ui.Msgboxs_label_title,print_file[cur_language]);
        if(printing_file_name[0] != '\0')
        {
            lv_label_set_text(guider_ui.Msgboxs_label_msgbox_secondline,printing_file_name);
        }
        lv_demo_printer_anim_in_all(guider_ui.Msgboxs_cont_msgboxs, LV_DEMO_PRINTER_ANIM_DELAY);
        msg_id = PRINT_FILE;
        lv_obj_set_event_cb(guider_ui.Msgboxs_btn_confirm, load_print_confirm_cb);
        lv_obj_set_event_cb(guider_ui.Msgboxs_btn_cancel, load_print_cancel_cb);
    }
}

void set_print_file_nums(void)
{
   char myper[6];
    snprintf(myper, 3, "%d", (current_page + 1));
    if((current_page + 1) < 10)
    {
        myper[1] = '/';
        snprintf(&myper[2], 3, "%d", print_file_pages);
    }
    else
    {
        myper[2] = '/';
        snprintf(&myper[3], 3, "%d",print_file_pages);
    }
    lv_label_set_text(guider_ui.print_btn_page_num_label, myper);
}

uint8_t test_data = 0;
static void task_cb(lv_task_t* task)
{
	uint8_t *dat = (uint8_t*)task->user_data;
	(*dat)++;
	lv_arc_set_value(guider_ui.print_arc_s,(*dat));
	if(*dat == 100)
    {
		lv_task_del(task);
		my_task = NULL;
		if(guider_ui.menu_cont_menu != NULL)
        {
            lv_obj_set_click(guider_ui.menu_btn_home, true);
            lv_obj_set_click(guider_ui.menu_btn_prepare, true);
            lv_obj_set_click(guider_ui.menu_btn_setting, true);
            lv_obj_set_click(guider_ui.menu_img_home, true);
            lv_obj_set_click(guider_ui.menu_img_prepare, true);
            lv_obj_set_click(guider_ui.menu_img_setting, true);
        }

		if(guider_ui.print_cont_print != NULL)
        {
            lv_obj_set_hidden(guider_ui.print_arc_s,true);
            lv_obj_set_hidden(guider_ui.print_label_2,true);
            lv_obj_set_click(guider_ui.print_btn_page_end, true);
            lv_obj_set_click(guider_ui.print_btn_page_next, true);
            lv_obj_set_click(guider_ui.print_btn_page_pre, true);
            lv_obj_set_click(guider_ui.print_btn_page_home, true);
            lv_obj_set_click(guider_ui.print_img_page_end, true);
            lv_obj_set_click(guider_ui.print_img_page_next, true);
            lv_obj_set_click(guider_ui.print_img_page_pre, true);
            lv_obj_set_click(guider_ui.print_img_page_home, true);
            lv_label_set_text(guider_ui.print_btn_page_num_label, "0/0");
        }
    }
	if(print_file_ok)
    {
		lv_task_del(task);
		my_task = NULL;
		if(guider_ui.menu_cont_menu != NULL)
        {
            lv_obj_set_click(guider_ui.menu_btn_home, true);
            lv_obj_set_click(guider_ui.menu_btn_prepare, true);
            lv_obj_set_click(guider_ui.menu_btn_setting, true);
            lv_obj_set_click(guider_ui.menu_img_home, true);
            lv_obj_set_click(guider_ui.menu_img_prepare, true);
            lv_obj_set_click(guider_ui.menu_img_setting, true);
        }

		if(guider_ui.print_cont_print != NULL)
        {
            lv_obj_set_hidden(guider_ui.print_arc_s,true);
            lv_obj_set_hidden(guider_ui.print_label_2,true);
            lv_obj_set_click(guider_ui.print_btn_page_end, true);
            lv_obj_set_click(guider_ui.print_btn_page_next, true);
            lv_obj_set_click(guider_ui.print_btn_page_pre, true);
            lv_obj_set_click(guider_ui.print_btn_page_home, true);
            lv_obj_set_click(guider_ui.print_img_page_end, true);
            lv_obj_set_click(guider_ui.print_img_page_next, true);
            lv_obj_set_click(guider_ui.print_img_page_pre, true);
            lv_obj_set_click(guider_ui.print_img_page_home, true);
            set_print_file_nums();
        }
    }
}

void handle_file()
{
    print_file_ok = false;
//    current_page = cpage;
    unsigned int itemp;
    char myper[FILE_NUM_SIZE + FILE_NUM_SIZE + 1 + 1 + 1] = "1001 000";

    snprintf(&myper[1], FILE_NUM_SIZE+1, "%03d", (current_page * FILE_NUM_PRE_PAGE) + 1);
    if(((current_page + 1) * FILE_NUM_PRE_PAGE) > print_total_files)
    {
        itemp = print_total_files;
    }
    else
    {
        itemp =  (current_page + 1) * FILE_NUM_PRE_PAGE;
    }
    snprintf(&myper[FILE_NUM_SIZE + 1 + 1], FILE_NUM_SIZE+1, "%03d", itemp);
    myper[4] = '\t';
    get_printer_data(0x01, FILE_NUM_SIZE+FILE_NUM_SIZE+1+1, myper);

    lv_obj_set_hidden(guider_ui.print_arc_s,false);
    lv_obj_set_hidden(guider_ui.print_label_2,false);

    test_data = 0;
    lv_obj_set_click(guider_ui.menu_btn_home, false);
    lv_obj_set_click(guider_ui.menu_btn_prepare, false);
    lv_obj_set_click(guider_ui.menu_btn_setting, false);
    lv_obj_set_click(guider_ui.menu_img_home, false);
    lv_obj_set_click(guider_ui.menu_img_prepare, false);
    lv_obj_set_click(guider_ui.menu_img_setting, false);

    lv_obj_set_click(guider_ui.print_btn_page_end, false);
    lv_obj_set_click(guider_ui.print_btn_page_next, false);
    lv_obj_set_click(guider_ui.print_btn_page_pre, false);
    lv_obj_set_click(guider_ui.print_btn_page_home, false);
    lv_obj_set_click(guider_ui.print_img_page_end, false);
    lv_obj_set_click(guider_ui.print_img_page_next, false);
    lv_obj_set_click(guider_ui.print_img_page_pre, false);
    lv_obj_set_click(guider_ui.print_img_page_home, false);

    my_task = lv_task_create(task_cb,15,LV_TASK_PRIO_MID, &test_data);
}

void print_event_init(void)
{
    set_refresh_data(0x00);
    get_printer_data(0x01, 1, "0");
//    get_response_printer_data(0x01, 4 , "0012");
//    char data[] = "1FLOWER~1.GCO:\tFLOWER~2.GCO:lv_lib_png/modeltess.png\tTURTLE~1.GCO:lv_lib_png/image_file_6.png\tDRAGON~1.GCO:\tENDER3~1.GCO:\n";
//    get_response_printer_data(0x01, strlen(data) , data);
}

void prepare_move_axis_event_init()
{
    get_printer_data(0x04, 1, "0");
    set_refresh_data(0x02);
    lv_btn_set_state(guider_ui.prepare_menu_btn_move_axis,LV_BTN_STATE_PRESSED);
    lv_obj_set_click(guider_ui.prepare_menu_btn_move_axis, false);

    lv_obj_set_click(guider_ui.prepare_move_axis_btn_cur_xposition, false);
    lv_obj_set_click(guider_ui.prepare_move_axis_btn_cur_yposition, false);
    lv_obj_set_click(guider_ui.prepare_move_axis_btn_cur_zposition, false);
    lv_obj_set_click(guider_ui.prepare_move_axis_btn_5, false);

    if(motor_loss_state)
    {
        lv_btn_set_state(guider_ui.prepare_move_axis_imgbtn_motor_loss,LV_BTN_STATE_CHECKED_PRESSED);
    }
    else
    {
        lv_btn_set_state(guider_ui.prepare_move_axis_imgbtn_motor_loss,LV_BTN_STATE_PRESSED);
    }
    lv_btn_set_state(guider_ui.prepare_move_axis_btn_move_uintb,LV_BTN_STATE_PRESSED);
    axis_move_uint = '1';
    if(cur_xposition[0] != '\0')
    {
        lv_label_set_text(guider_ui.prepare_move_axis_btn_cur_xposition_label, &cur_xposition[0]);
    }
    if(cur_yposition[0] != '\0')
    {
        lv_label_set_text(guider_ui.prepare_move_axis_btn_cur_xposition_label, &cur_yposition[0]);
    }
    if(cur_zposition[0] != '\0')
    {
        lv_label_set_text(guider_ui.prepare_move_axis_btn_cur_xposition_label, &cur_zposition[0]);
    }
}

void prepare_material_event_init()
{
    get_printer_data(0x03, 1, "0");
    set_refresh_data(0x01);
    lv_btn_set_state(guider_ui.prepare_menu_btn_move_e,LV_BTN_STATE_PRESSED);
    lv_obj_set_click(guider_ui.prepare_menu_btn_move_e, false);

    lv_btn_set_state(guider_ui.menu_btn_prepare,LV_BTN_STATE_PRESSED);
    lv_obj_set_click(guider_ui.menu_btn_prepare, false);
    lv_obj_set_click(guider_ui.menu_img_prepare, false);

    if(refresh_hotend_temp)
    {
        if(input_win_flag)
        {
            set_printer_data(0x01,strlen(edit_temp) ,edit_temp);
            input_win_flag = false;
        }
        refresh_hotend_temp = false;
    }

    int len = atoi(material_length);
    lv_slider_set_value(guider_ui.prepare_material_slider_1,len,LV_ANIM_OFF);
    if(material_length[0] != '\0')
    {
        lv_label_set_text(guider_ui.prepare_material_label_material_length, &material_length[0]);
    }
    if(hotend_cur_temp[0] != '\0')
    {
        lv_label_set_text(guider_ui.prepare_material_label_hotend_cur_temp, &hotend_cur_temp[0]);
    }
}

void prepare_manual_temp_event_init()
{
    get_printer_data(0x06, 1, "0");
    get_printer_data(0x03, 1, "0");
    set_refresh_data(0x00);
    lv_btn_set_state(guider_ui.prepare_menu_btn_manual_temp,LV_BTN_STATE_PRESSED);
    lv_obj_set_click(guider_ui.prepare_menu_btn_manual_temp, false);

    lv_btn_set_state(guider_ui.menu_btn_prepare,LV_BTN_STATE_PRESSED);
    lv_obj_set_click(guider_ui.menu_btn_prepare, false);
    lv_obj_set_click(guider_ui.menu_img_prepare, false);

    if(refresh_hotend_temp)
    {
        if(input_win_flag)
        {
            set_printer_data(0x01,strlen(edit_temp) ,edit_temp);
            input_win_flag = false;
        }
        refresh_hotend_temp = false;
    }
    if(refresh_bed_temp)
    {
        if(input_win_flag)
        {
            set_printer_data(0x02,strlen(edit_temp) ,edit_temp);
            input_win_flag = false;
        }
        refresh_bed_temp = false;
    }

    if(hotend_max_temp[0] != '\0')
    {
        lv_label_set_text(guider_ui.prepare_manual_temp_label_hot_mtemp, &hotend_max_temp[0]);
    }
    if(bed_max_temp[0] != '\0')
    {
        lv_label_set_text(guider_ui.prepare_manual_temp_label_bed_mtemp, &bed_max_temp[0]);
    }
    if(fan_state)
    {
        lv_label_set_text(guider_ui.prepare_manual_temp_label_fan_state, "ON");
    }
    else
    {
        lv_label_set_text(guider_ui.prepare_manual_temp_label_fan_state, "OFF");
    }
}

void setting_device_event_init()
{
    get_printer_data(0x07, 1, "0");
    set_refresh_data(0x00);
    lv_btn_set_state(guider_ui.setting_menu_btn_about,LV_BTN_STATE_RELEASED);
    lv_btn_set_state(guider_ui.setting_menu_btn_ad_setting,LV_BTN_STATE_RELEASED);
    lv_btn_set_state(guider_ui.setting_menu_btn_device,LV_BTN_STATE_PRESSED);
    lv_obj_set_click(guider_ui.setting_menu_btn_about, true);
    lv_obj_set_click(guider_ui.setting_menu_btn_ad_setting, true);
    lv_obj_set_click(guider_ui.setting_menu_btn_device, false);
    if(light_state)
    {
        lv_label_set_text(guider_ui.setting_device_label_light_state, "ON");
    }
    else
    {
        lv_label_set_text(guider_ui.setting_device_label_light_state, "OFF");
    }
}
void setting_ad_setting_event_init()
{
    get_printer_data(0x08, 1, "0");
    set_refresh_data(0x00);
    if(wifi_state == 0)
    {
        lv_label_set_text(guider_ui.setting_ad_setting_label_wifi_state, "OFF");
    }
    else
    {
        lv_label_set_text(guider_ui.setting_ad_setting_label_wifi_state, "ON");
    }
}
void setting_about_event_init()
{
    get_printer_data(0x0c, 1, "0");
    set_refresh_data(0x00);
}

void load_setting_device_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_CLICKED) {
        guider_load_screen(SCR_SETTING_DEVICE_PAGE);
        lv_btn_set_state(guider_ui.menu_btn_setting,LV_BTN_STATE_PRESSED);
        lv_obj_set_click(guider_ui.menu_btn_setting, false);
        lv_obj_set_click(guider_ui.menu_img_setting, false);
        lv_demo_printer_anim_in_all(guider_ui.setting_device_cont_seting_device, LV_DEMO_PRINTER_ANIM_DELAY);
        if(guider_ui.Level_menu_cont_level_menu != NULL)
        {
            lv_obj_clean(guider_ui.Level_menu_cont_level_menu);
            lv_obj_del(guider_ui.Level_menu_cont_level_menu);
            guider_ui.Level_menu_cont_level_menu = NULL;
        }
        if(guider_ui.Level_title_cont_level_title != NULL)
        {
            lv_obj_clean(guider_ui.Level_title_cont_level_title);
            lv_obj_del(guider_ui.Level_title_cont_level_title);
            guider_ui.Level_title_cont_level_title = NULL;
        }
        printf("back setting device page\n");
    }
}

void language_event_init(void)
{
    lv_obj_set_event_cb(guider_ui.Language_img_back, load_setting_device_cb);
    switch(cur_language)
    {
        case 0:
            lv_btn_set_state(guider_ui.Language_btn_china,LV_BTN_STATE_PRESSED);
            lv_obj_set_click(guider_ui.Language_btn_china, false);
            break;
        case 1:
            lv_btn_set_state(guider_ui.Language_btn_english,LV_BTN_STATE_PRESSED);
            lv_obj_set_click(guider_ui.Language_btn_english, false);
            break;
        case 2:
            lv_btn_set_state(guider_ui.Language_btn_deutsch,LV_BTN_STATE_PRESSED);
            lv_obj_set_click(guider_ui.Language_btn_deutsch, false);
            break;
        case 3:
            lv_btn_set_state(guider_ui.Language_btn_espanol,LV_BTN_STATE_PRESSED);
            lv_obj_set_click(guider_ui.Language_btn_espanol, false);
            break;
        case 4:
            lv_btn_set_state(guider_ui.Language_btn_france,LV_BTN_STATE_PRESSED);
            lv_obj_set_click(guider_ui.Language_btn_france, false);
            break;
        case 5:
            lv_btn_set_state(guider_ui.Language_btn_italy,LV_BTN_STATE_PRESSED);
            lv_obj_set_click(guider_ui.Language_btn_italy, false);
            break;
        case 6:
            lv_btn_set_state(guider_ui.Language_btn_portugues,LV_BTN_STATE_PRESSED);
            lv_obj_set_click(guider_ui.Language_btn_portugues, false);
            break;
        case 7:
            lv_btn_set_state(guider_ui.Language_btn_russian,LV_BTN_STATE_PRESSED);
            lv_obj_set_click(guider_ui.Language_btn_russian, false);
           break;
        case 8:
            lv_btn_set_state(guider_ui.Language_btn_turkish,LV_BTN_STATE_PRESSED);
            lv_obj_set_click(guider_ui.Language_btn_turkish, false);
            break;
        default:
            break;
    }
}

void levle_auto_event_init(void)
{
    lv_obj_set_click(guider_ui.Level_auto_btn_16, false);
    lv_obj_set_size(guider_ui.Level_auto_btn_mask, 300, 90);
    lv_label_set_text(guider_ui.Level_auto_label_zauto_progress, "0%");
    lv_label_set_text(guider_ui.Level_auto_label_13, "");
    lv_label_set_text(guider_ui.Level_auto_label_14, "");
    lv_obj_set_event_cb(guider_ui.Level_title_img_back, load_setting_device_cb);
}

void levle_manual_event_init(void)
{
    get_printer_data(0x02, 1, "0");
    if(zoffset_value[0] != '\0')
    {
        lv_label_set_text(guider_ui.Level_manual_btn_zoffset_value_label, &zoffset_value[0]);
    }
    lv_btn_set_state(guider_ui.Level_manual_btn_zoffset_unita,LV_BTN_STATE_PRESSED);
    zoffset_move_uint = '0';
    lv_obj_set_click(guider_ui.Level_manual_btn_11, false);
    lv_obj_set_click(guider_ui.Level_manual_btn_5, false);
    lv_obj_set_event_cb(guider_ui.Level_title_img_back, load_setting_device_cb);
	lv_obj_set_click(guider_ui.Level_manual_btn_zoffset_value, false);
}

void load_setting_ad_setting_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_CLICKED) {
		if(check_time())
			return;
        guider_load_screen(SCR_SETTING_AD_SETTING_PAGE);
        lv_btn_set_state(guider_ui.menu_btn_setting,LV_BTN_STATE_PRESSED);
        lv_obj_set_click(guider_ui.menu_btn_setting, false);
        lv_obj_set_click(guider_ui.menu_img_setting, false);
        lv_btn_set_state(guider_ui.setting_menu_btn_ad_setting,LV_BTN_STATE_PRESSED);
        lv_obj_set_click(guider_ui.setting_menu_btn_ad_setting, false);
        lv_demo_printer_anim_in_all(guider_ui.setting_ad_setting_cont_setting_ad_setting, LV_DEMO_PRINTER_ANIM_DELAY);
        printf("back ad setting page\n");
    }
}

void motionset_event_init(void)
{
    lv_obj_set_event_cb(guider_ui.MotionSet_img_back, load_setting_ad_setting_cb);
}

void tempPIDset_event_init(void)
{
    get_printer_data(0x0b, 1, "0");
    lv_obj_set_event_cb(guider_ui.TempPIDSet_img_back, load_setting_ad_setting_cb);

    if(refresh_pid_hotend_p)
    {
        if(input_win_flag)
        {
            char buf[(PID_LEN+1)] = "1";
            for(unsigned char i=0;i<PID_LEN;i++)
            {
                if(edit_pid_temp[i] == '\0')
                {
                    break;
                }
                buf[i+1] = edit_pid_temp[i];
            }
            set_printer_data(0x10,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_pid_hotend_p = false;
    }
    if(refresh_pid_hotend_i)
    {
        if(input_win_flag)
        {
            char buf[(PID_LEN+1)] = "2";
            for(unsigned char i=0;i<PID_LEN;i++)
            {
                if(edit_pid_temp[i] == '\0')
                {
                    break;
                }
                buf[i+1] = edit_pid_temp[i];
            }
            set_printer_data(0x10,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_pid_hotend_i = false;
    }
    if(refresh_pid_hotend_d)
    {
        if(input_win_flag)
        {
            char buf[(PID_LEN+1)] = "3";
            for(unsigned char i=0;i<PID_LEN;i++)
            {
                if(edit_pid_temp[i] == '\0')
                {
                    break;
                }
                buf[i+1] = edit_pid_temp[i];
            }
            set_printer_data(0x10,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_pid_hotend_d = false;
    }
    if(refresh_pid_bed_p)
    {
        if(input_win_flag)
        {
            char buf[(PID_LEN+1)] = "4";
            for(unsigned char i=0;i<PID_LEN;i++)
            {
                if(edit_pid_temp[i] == '\0')
                {
                    break;
                }
                buf[i+1] = edit_pid_temp[i];
            }
            set_printer_data(0x10,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_pid_bed_p = false;
    }
    if(refresh_pid_bed_i)
    {
        if(input_win_flag)
        {
            char buf[(PID_LEN+1)] = "5";
            for(unsigned char i=0;i<PID_LEN;i++)
            {
                if(edit_pid_temp[i] == '\0')
                {
                    break;
                }
                buf[i+1] = edit_pid_temp[i];
            }
            set_printer_data(0x10,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_pid_bed_i = false;
    }
    if(refresh_pid_bed_d)
    {
        if(input_win_flag)
        {
            char buf[(PID_LEN+1)] = "6";
            for(unsigned char i=0;i<PID_LEN;i++)
            {
                if(edit_pid_temp[i] == '\0')
                {
                    break;
                }
                buf[i+1] = edit_pid_temp[i];
            }
            set_printer_data(0x10,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_pid_bed_d = false;
    }

	if(hotend_pid_p[0] != '\0')
	{
		lv_label_set_text(guider_ui.TempPIDSet_label_hotend_pid_p, &hotend_pid_p[0]);
	}
	if(hotend_pid_i[0] != '\0')
	{
		lv_label_set_text(guider_ui.TempPIDSet_label_hotend_pid_i, &hotend_pid_i[0]);
	}
	if(hotend_pid_d[0] != '\0')
	{
		lv_label_set_text(guider_ui.TempPIDSet_label_hotend_pid_d, &hotend_pid_d[0]);
	}
	if(bed_pid_p[0] != '\0')
	{
		lv_label_set_text(guider_ui.TempPIDSet_label_bed_pid_p, &bed_pid_p[0]);
	}
	if(bed_pid_i[0] != '\0')
	{
		lv_label_set_text(guider_ui.TempPIDSet_label_bed_pid_i, &bed_pid_i[0]);
	}
	if(bed_pid_d[0] != '\0')
	{
		lv_label_set_text(guider_ui.TempPIDSet_label_bed_pid_d, &bed_pid_d[0]);
	}
}

void load_home_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_CLICKED) {
        guider_load_screen(SCR_HOME_PAGE);
        lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
        lv_obj_set_click(guider_ui.menu_btn_home, false);
        lv_obj_set_click(guider_ui.menu_img_home, false);
        lv_obj_set_click(guider_ui.menu_btn_print, false);
        lv_obj_set_click(guider_ui.menu_img_print, false);
        lv_obj_set_click(guider_ui.menu_btn_prepare, false);
        lv_obj_set_click(guider_ui.menu_img_prepare, false);
        lv_obj_set_click(guider_ui.menu_btn_setting, false);
        lv_obj_set_click(guider_ui.menu_img_setting, false);
        lv_demo_printer_anim_in_all(guider_ui.home_cont_home, LV_DEMO_PRINTER_ANIM_DELAY);
        printf("back home page\n");
    }
}

void printingset_event_init(void)
{
    get_printer_data(0x02, 1, "0");
    get_printer_data(0x06, 1, "0");
    get_printer_data(0x07, 1, "0");

    if(refresh_hotend_temp)
    {
        if(input_win_flag)
        {
            set_printer_data(0x01,strlen(edit_temp) ,edit_temp);
            input_win_flag = false;
        }
        refresh_hotend_temp = false;
    }
    if(refresh_bed_temp)
    {
        if(input_win_flag)
        {
            set_printer_data(0x02,strlen(edit_temp) ,edit_temp);
            input_win_flag = false;
        }
        refresh_bed_temp = false;
    }
    if(refresh_print_speed)
    {
        if(input_win_flag)
        {
            set_printer_data(0x03,strlen(edit_temp) ,edit_temp);
            input_win_flag = false;
        }
        refresh_print_speed = false;
    }

	if(hotend_max_temp[0] != '\0')
	{
		lv_label_set_text(guider_ui.PrintingSet_label_hotend_mtemp_value, &hotend_max_temp[0]);
	}
	if(bed_max_temp[0] != '\0')
	{
		lv_label_set_text(guider_ui.PrintingSet_label_bed_mtemp_value, &bed_max_temp[0]);
	}
	if(cur_speed[0] != '\0')
	{
	    char temp[CUR_SPEED_LEN+2];
	    unsigned char i;
	    for(i=0;i<CUR_SPEED_LEN;i++)
        {
            if(cur_speed[i] == '\0')
            {
                break;
            }
            temp[i] = cur_speed[i];
        }
        temp[i] = '%';
        temp[i+1] = '\0';
		lv_label_set_text(guider_ui.PrintingSet_label_cur_speed_value, &temp[0]);
	}
	if(zoffset_value[0] != '\0')
	{
		lv_label_set_text(guider_ui.PrintingSet_label_zoffset_value, &zoffset_value[0]);
	}
    if(fan_state)
    {
        lv_label_set_text(guider_ui.PrintingSet_label_fan_state_value, "ON");
    }
    else
    {
        lv_label_set_text(guider_ui.PrintingSet_label_fan_state_value, "OFF");
    }
    if(light_state)
    {
        lv_label_set_text(guider_ui.PrintingSet_label_light_state_value, "ON");
    }
    else
    {
        lv_label_set_text(guider_ui.PrintingSet_label_light_state_value, "OFF");
    }
    lv_obj_set_event_cb(guider_ui.PrintingSet_img_back, load_home_cb);
}

void load_printing_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_CLICKED) {
        guider_load_screen(SCR_PRINTINGSET_PAGE);
        lv_demo_printer_anim_in_all(guider_ui.PrintingSet_cont_printing_set, LV_DEMO_PRINTER_ANIM_DELAY);
        printf("back printing set page\n");
    }
}

void zoffset_event_init(void)
{
    get_printer_data(0x02, 1, "0");
    lv_obj_set_event_cb(guider_ui.ZoffsetSet_img_back, load_printing_cb);
    if(zoffset_value[0] != '\0')
	{
		lv_label_set_text(guider_ui.ZoffsetSet_label_zoffset_value, &zoffset_value[0]);
	}
    lv_obj_set_click(guider_ui.ZoffsetSet_btn_zoffset_value, false);
}

void preheating_event_init(void)
{
    lv_obj_set_event_cb(guider_ui.Preheating_img_back, load_setting_device_cb);
    if(refresh_preheat_hotend)
    {
        if(input_win_flag)
        {
            char temp[HOTEND_TEMP_LEN+2];
            if(preheating_flag == 0)
            {
                temp[0] = '1';
            }
            else
            {
                temp[0] = '2';
            }
            temp[1] = '1';
            for(unsigned char i=0;i<HOTEND_TEMP_LEN;i++)
            {
                if(edit_temp[i] == '\0')
                {
                    break;
                }
                temp[i+2] = edit_temp[i];
            }
            set_printer_data(0x0c, strlen(temp), temp);
            input_win_flag = false;
        }
        refresh_preheat_hotend = false;
    }
    if(refresh_preheat_bed)
    {
        if(input_win_flag)
        {
            char temp[BED_TEMP_LEN+2];
            if(preheating_flag == 0)
            {
                temp[0] = '1';
            }
            else
            {
                temp[0] = '2';
            }
            temp[1] = '2';
            for(unsigned char i=0;i<BED_TEMP_LEN;i++)
            {
                if(edit_temp[i] == '\0')
                {
                    break;
                }
                temp[i+2] = edit_temp[i];
            }
            set_printer_data(0x0c, strlen(temp), temp);
            input_win_flag = false;
        }
        refresh_preheat_bed = false;
    }
	if(preheating_flag == 0)
	{
	    get_printer_data(0x05, 1, "0");
		if(PLA_preheat_hotend[0] != '\0')
		{
			lv_label_set_text(guider_ui.Preheating_label_preheat_hotend, &PLA_preheat_hotend[0]);
		}
		if(PLA_preheat_bed[0] != '\0')
		{
			lv_label_set_text(guider_ui.Preheating_label_preheat_bed, &PLA_preheat_bed[0]);
		}
	}
	else if(preheating_flag == 1)
	{
	    get_printer_data(0x05, 1, "1");
		if(ABS_preheat_hotend[0] != '\0')
		{
			lv_label_set_text(guider_ui.Preheating_label_preheat_hotend, &ABS_preheat_hotend[0]);
		}
		if(ABS_preheat_bed[0] != '\0')
		{
			lv_label_set_text(guider_ui.Preheating_label_preheat_bed, &ABS_preheat_bed[0]);
		}
	}
}

void msgboxs_event_init(void)
{

}

void inputboxs_event_init(void)
{
	for(unsigned char i=0;i<(INPUT_WINDOW_LEN+1);i++)
	{
		input_str[i] = '\0';
	}
	lv_label_set_text(guider_ui.Inputboxs_btn_input_label, "");
	lv_obj_set_click(guider_ui.Inputboxs_btn_input, false);
	lv_obj_set_click(guider_ui.Inputboxs_btn_1, false);
	if(shield_input_bit & 0x1)
	{
		lv_obj_set_click(guider_ui.Inputboxs_btn_neg, false);
	}
	if(shield_input_bit & 0x2)
	{
		lv_obj_set_click(guider_ui.Inputboxs_btn_dot, false);
	}
}

void load_motionset_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_CLICKED) {
		if(check_time())
			return;
        guider_load_screen(SCR_MOTIONSET_PAGE);
        lv_demo_printer_anim_in_all(guider_ui.MotionSet_cont_motion_set, LV_DEMO_PRINTER_ANIM_DELAY);
        printf("back motion set page\n");
    }
}

void rtoset_event_init(void)
{
    get_printer_data(0x0a, 1, "1");
    lv_obj_set_event_cb(guider_ui.RTOSet_img_back, load_motionset_cb);

    if(refresh_rto_x)
    {
        if(input_win_flag)
        {
            char buf[RTO_LEN+2] = "11";
            for(unsigned char i=0;i<RTO_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_rto_x = false;
    }
    if(refresh_rto_y)
    {
        if(input_win_flag)
        {
            char buf[RTO_LEN+2] = "12";
            for(unsigned char i=0;i<RTO_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_rto_y = false;
    }
    if(refresh_rto_z)
    {
        if(input_win_flag)
        {
            char buf[RTO_LEN+2] = "13";
            for(unsigned char i=0;i<RTO_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_rto_z = false;
    }
    if(refresh_rto_e)
    {
        if(input_win_flag)
        {
            char buf[RTO_LEN+2] = "14";
            for(unsigned char i=0;i<RTO_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_rto_e = false;
    }

	if(xRTO[0] != '\0')
	{
		lv_label_set_text(guider_ui.RTOSet_label_xRTO, &xRTO[0]);
	}
	if(yRTO[0] != '\0')
	{
		lv_label_set_text(guider_ui.RTOSet_label_yRTO, &yRTO[0]);
	}
	if(zRTO[0] != '\0')
	{
		lv_label_set_text(guider_ui.RTOSet_label_zRTO, &zRTO[0]);
	}
	if(eRTO[0] != '\0')
	{
		lv_label_set_text(guider_ui.RTOSet_label_eRTO, &eRTO[0]);
	}
}

void maxaccset_event_init(void)
{
    get_printer_data(0x0a, 1, "2");
    lv_obj_set_event_cb(guider_ui.MaxAccSet_img_back, load_motionset_cb);

    if(refresh_macc_x)
    {
        if(input_win_flag)
        {
            char buf[MACC_LEN+2] = "21";
            for(unsigned char i=0;i<MACC_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_macc_x = false;
    }
    if(refresh_macc_y)
    {
        if(input_win_flag)
        {
            char buf[MACC_LEN+2] = "22";
            for(unsigned char i=0;i<MACC_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_macc_y = false;
    }
    if(refresh_macc_z)
    {
        if(input_win_flag)
        {
            char buf[MACC_LEN+2] = "23";
            for(unsigned char i=0;i<MACC_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_macc_z= false;
    }
    if(refresh_macc_e)
    {
        if(input_win_flag)
        {
            char buf[MACC_LEN+2] = "24";
            for(unsigned char i=0;i<MACC_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_macc_e = false;
    }

	if(xmacc[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxAccSet_label_xmacc, &xmacc[0]);
	}
	if(ymacc[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxAccSet_label_ymacc, &ymacc[0]);
	}
	if(zmacc[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxAccSet_label_zmacc, &zmacc[0]);
	}
	if(emacc[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxAccSet_label_emacc, &emacc[0]);
	}
}

void maxconcorset_event_init(void)
{
    get_printer_data(0x0a, 1, "3");
    lv_obj_set_event_cb(guider_ui.MaxConcorSet_img_back, load_motionset_cb);

    if(refresh_mcon_x)
    {
        if(input_win_flag)
        {
            char buf[MCONCOR_LEN+2] = "31";
            for(unsigned char i=0;i<MCONCOR_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_mcon_x = false;
    }
    if(refresh_mcon_y)
    {
        if(input_win_flag)
        {
            char buf[MCONCOR_LEN+2] = "32";
            for(unsigned char i=0;i<MCONCOR_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_mcon_y = false;
    }
    if(refresh_mcon_z)
    {
        if(input_win_flag)
        {
            char buf[MCONCOR_LEN+2] = "33";
            for(unsigned char i=0;i<MCONCOR_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_mcon_z= false;
    }
    if(refresh_mcon_e)
    {
        if(input_win_flag)
        {
            char buf[MCONCOR_LEN+2] = "34";
            for(unsigned char i=0;i<MCONCOR_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_mcon_e = false;
    }

	if(xmconcor[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxConcorSet_label_xmconcor, &xmconcor[0]);
	}
	if(ymconcor[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxConcorSet_label_ymconcor, &ymconcor[0]);
	}
	if(zmconcor[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxConcorSet_label_zmconcor, &zmconcor[0]);
	}
	if(emconcor[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxConcorSet_label_emconcor, &emconcor[0]);
	}
}

void maxspeedset_event_init(void)
{
    get_printer_data(0x0a, 1, "4");
    lv_obj_set_event_cb(guider_ui.MaxSpeedSet_img_back, load_motionset_cb);

    if(refresh_mspeed_x)
    {
        if(input_win_flag)
        {
            char buf[MSPEED_LEN+2] = "41";
            for(unsigned char i=0;i<MSPEED_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_mspeed_x = false;
    }
    if(refresh_mspeed_y)
    {
        if(input_win_flag)
        {
            char buf[MSPEED_LEN+2] = "42";
            for(unsigned char i=0;i<MSPEED_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_mspeed_y = false;
    }
    if(refresh_mspeed_z)
    {
        if(input_win_flag)
        {
            char buf[MSPEED_LEN+2] = "43";
            for(unsigned char i=0;i<MSPEED_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_mspeed_z= false;
    }
    if(refresh_mspeed_e)
    {
        if(input_win_flag)
        {
            char buf[MSPEED_LEN+2] = "44";
            for(unsigned char i=0;i<MSPEED_LEN;i++)
            {
                if(edit_motion[i] == '\0')
                {
                    break;
                }
                buf[i+2] = edit_motion[i];
            }
            set_printer_data(0x0f,strlen(buf) ,buf);
            input_win_flag = false;
        }
        refresh_mspeed_e = false;
    }

	if(xmspeed[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxSpeedSet_label_xmspeed, &xmspeed[0]);
	}
	if(ymspeed[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxSpeedSet_label_ymspeed, &ymspeed[0]);
	}
	if(zmspeed[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxSpeedSet_label_zmspeed, &zmspeed[0]);
	}
	if(emspeed[0] != '\0')
	{
		lv_label_set_text(guider_ui.MaxSpeedSet_label_emspeed, &emspeed[0]);
	}
}

bool check_time(void)
{
	if((lv_tick_get() - tick_start) < CLICK_DIFF)
		return true;
	else
		return false;
}

void msgbox(char *msg)
{
    lv_obj_t* mbox = lv_msgbox_create(lv_scr_act(), NULL);

	static lv_style_t style_msg;
	lv_style_reset(&style_msg);
	lv_style_set_radius(&style_msg, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_msg, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_bg_grad_color(&style_msg, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_bg_grad_dir(&style_msg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_msg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_msg, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_msg, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_msg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_msg, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_msg, LV_STATE_DEFAULT, 0);
	lv_style_set_text_line_space(&style_msg, LV_STATE_DEFAULT, 10);
	lv_obj_add_style(mbox, LV_MSGBOX_PART_BG, &style_msg);

    lv_msgbox_set_text(mbox, msg);
    lv_msgbox_start_auto_close(mbox, 1000);
	lv_obj_align(mbox, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_click(mbox, false);
}

void stack_preheating(unsigned char preheating)
{
	preheating_flag = preheating;
}

void stack_input(int scr_id,unsigned char shield,unsigned char nums,char *cur_dt)
{
	pre_scr = scr_id;
	shield_input_bit = shield;
	input_number_bit = nums;
	cur_data = cur_dt;
}

void handle_input(char chr)
{
	if(check_time())
        return;
	char *src = lv_label_get_text(guider_ui.Inputboxs_btn_input_label);
	unsigned char len = 0;
	bool dot_flag = false;
	while(*src != '\0')
	{
		if(*src == '.')
		{
			dot_flag = true;
		}
		input_str[len++] = *src++;
	}
	switch(chr)
	{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if(len < input_number_bit)
			{
				input_str[len] = chr;
			}
			break;
		case '0':
			if((len != 0) && (len < input_number_bit))
			{
				input_str[len] = chr;
			}
			break;
		case '-':
			if(len == 0)
			{
				input_str[len] = chr;
			}
			break;
		case '.':
			if(!dot_flag)
			{
				if(len == 0)
				{
					input_str[len++] = '0';
				}
				input_str[len] = chr;
				dot_flag = true;
			}
			break;
		case 'b':
			if(len > 0)
			{
				input_str[--len] = '\0';
			}
			break;
		case 'c':
			guider_load_screen(pre_scr);
			break;
		case 's':
		    if(input_str[0] != '\0')
            {
                for(unsigned char i=0; i<input_number_bit; i++)
                {
                    cur_data[i] = input_str[i];
                }
            }
			input_win_flag = true;
			guider_load_screen(pre_scr);
			break;
		default:
			break;
	}
    if((chr != 'c') && (chr != 's'))
    {
        lv_label_set_text(guider_ui.Inputboxs_btn_input_label, &input_str[0]);
    }
}

void data_init(void)
{
	material_length[0] = '1';
	print_state = 0;
	motor_loss_state = false;
	refresh_hotend_temp = false;
    refresh_bed_temp = false;
    refresh_zoffset = false;
    refresh_preheat_hotend = false;
    refresh_preheat_bed = false;
    refresh_pid_hotend_p = false;
    refresh_pid_hotend_i = false;
    refresh_pid_hotend_d = false;
    refresh_pid_bed_p = false;
    refresh_pid_bed_i = false;
    refresh_pid_bed_d = false;
    refresh_rto_x = false;
    refresh_rto_y = false;
    refresh_rto_z = false;
    refresh_rto_e = false;
    refresh_macc_x = false;
    refresh_macc_y = false;
    refresh_macc_z = false;
    refresh_macc_e = false;
    refresh_mcon_x = false;
    refresh_mcon_y = false;
    refresh_mcon_z = false;
    refresh_mcon_e = false;
    refresh_mspeed_x = false;
    refresh_mspeed_y = false;
    refresh_mspeed_z = false;
    refresh_mspeed_e = false;
    refresh_print_speed = false;
//    file_names = malloc(13);
    big_photo_name[0] = '\0';
//    printing_file_name = malloc(13);
}

void UI_init(void)
{
    lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
    lv_btn_set_state(guider_ui.menu_btn_print,LV_BTN_STATE_RELEASED);
    lv_btn_set_state(guider_ui.menu_btn_prepare,LV_BTN_STATE_RELEASED);
    lv_btn_set_state(guider_ui.menu_btn_setting,LV_BTN_STATE_RELEASED);
    lv_obj_set_click(guider_ui.menu_btn_home, false);
    lv_obj_set_click(guider_ui.menu_btn_print, true);
    lv_obj_set_click(guider_ui.menu_btn_prepare, true);
    lv_obj_set_click(guider_ui.menu_btn_setting, true);
    lv_obj_set_click(guider_ui.menu_img_home, false);
    lv_obj_set_click(guider_ui.menu_img_print, true);
    lv_obj_set_click(guider_ui.menu_img_prepare, true);
    lv_obj_set_click(guider_ui.menu_img_setting, true);
}

void custom_init(lv_ui *ui)
{
	data_init();
	cur_scr = 0xff;
    get_printer_data(0x02, 1, "0");
    get_printer_data(0x03, 1, "0");
	setup_scr_menu(ui);
    setup_scr_home(ui);
	cur_scr = SCR_HOME_PAGE;
	home_event_init();
	UI_init();

	lv_scr_load(ui->home);
}
