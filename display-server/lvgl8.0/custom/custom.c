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
#include <time.h>
#include "lvgl/lvgl.h"
#include "custom.h"
#include "clanguage.h"
#include "commu_thread.h"
#include "CrlogDef.h"
#include "mystyle.h"

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
//#define LV_DEMO_PRINTER_WHITE           lv_color_hex(0xffffff)
//#define LV_DEMO_PRINTER_LIGHT_GRAY      lv_color_hex(0xc4c4c4)
//
#define CLICK_DIFF 600    //单位毫秒
//#define FRINT_FILE_DELAY 1500   //单位毫秒
//
int cur_scr;
int pre_scr;
lv_ui guider_ui;
bool motor_loss_state;          //当前电机状态
char offset_move_uint;
bool refreshflag_settingpage = false;

////char *file_names = NULL;            //存储SD卡获取的文件名称
////char *printing_file_name = NULL;    //存储选中的准备打印的文件全路径名称
////unsigned char file_name_num;
char printing_file_name[FILE_SIZE+1];
char manuallevel_count = 0;

unsigned int tick_start;
unsigned int print_file_pages;
unsigned int current_page;
unsigned int print_total_files;
          int clicked_file_num;
unsigned int historyfile_pages;
unsigned int history_total_files;
unsigned int history_current_page;
          int history_clientnum;
unsigned int videolist_pages;
unsigned int videolist_total_files;
unsigned int videolist_current_page;
          int videolist_clientnum;

char input_str[INPUT_WINDOW_LEN+1];
unsigned char shield_input_bit;     //按位数禁止输入，0x01禁止输入负号，0x02禁止输入小数点
unsigned char input_number_bit;
int input_min;
int input_max;
lv_obj_t *input_label;
int input_type;

char *cur_data;
//char edit_temp[EDIT_TEMP_LEN];
//char edit_pid_temp[PID_LEN];
//char edit_motion[MOTION_TEMP_LEN];
char hotend_max_temp[HOTEND_TEMP_LEN+1];
char hotend_cur_temp[HOTEND_TEMP_LEN+1];
char bed_max_temp[BED_TEMP_LEN+1];
char bed_cur_temp[BED_TEMP_LEN+1];
char chassis_temp[BED_TEMP_LEN+1];
char origin_xoffset_value[OFFSET_LEN+1] = {'\0'};
char origin_yoffset_value[OFFSET_LEN+1] = {'\0'};
char origin_zoffset_value[OFFSET_LEN+1] = {'\0'};
char zoffset_value[OFFSET_LEN+1] = {'\0'};
char cur_speed[CUR_SPEED_LEN+1] = "100";
char speedchangetype = '0';
char speedflowchangetype = '0';
char cur_printflow[CUR_SPEED_LEN+1] = "100";
char cur_xposition[CUR_POSITION+1];
char cur_yposition[CUR_POSITION+1];
char cur_zposition[CUR_POSITION+1];
bool fan_state;
bool light_state;
bool shake_sensor_state = true;
char filesort_type = '0';
unsigned int cur_language;
char wifi_state;
char xSTEPS[STEPS_LEN+1];
char ySTEPS[STEPS_LEN+1];
char zSTEPS[STEPS_LEN+1];
char eSTEPS[STEPS_LEN+1];
char xmacc[MACC_LEN+1];
char ymacc[MACC_LEN+1];
char zmacc[MACC_LEN+1];
char emacc[MACC_LEN+1];
char xjerk[MJERK_LEN+1];
char yjerk[MJERK_LEN+1];
char zjerk[MJERK_LEN+1];
char ejerk[MJERK_LEN+1];
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
char self_preheat_hotend[HOTEND_TEMP_LEN+1];
char self_preheat_bed[BED_TEMP_LEN+1];
//char auto_poweroff[AUTO_POWEROFF_LEN+1];
char machine_type_value[ABOUT_INFO_LEN+1];
char hardware_ver_value[ABOUT_INFO_LEN+1];
char fireware_ver_value[ABOUT_INFO_LEN+1];
char screen_ver_value[ABOUT_INFO_LEN+1];
char total_time_value[ABOUT_INFO_LEN+1];
char mac_value[ABOUT_INFO_LEN+1];
char official_web_value[ABOUT_INFO_LEN+1];
char bed_size_x[BED_SIZE_LEN+1];
char bed_size_y[BED_SIZE_LEN+1];
char pid_hotend_tar[HOTEND_TEMP_LEN+1];
char pid_hotend_times[REPEAT_TIMES_LEN+1];
char pid_bed_tar[BED_TEMP_LEN+1];
char pid_bed_times[REPEAT_TIMES_LEN+1];
bool post_state;
bool powerloss_state;
//unsigned char repeat_print_times;
char repeat_times[REPEAT_TIMES_LEN+1];
bool sound_state;
char sound_value[3] = {0};
char sound_type = 0;
bool fullscreen_mode_state = false;
char screen_save_value[3] = {0};
char bright_value[3] = {0};
//bool level_high_speed_level;
char level_point_value;
char level_point_value_flag;
//char point_num;
//char level_auto_model_value;
bool auto_poweroff;
char material_seneor;
unsigned char theme_model_id;
//
//char axis_move_uint;
//char offset_move_uint;
char material_in_length[MATERIAL_LEN+1];
char material_out_length[MATERIAL_LEN+1];
char extruderspeed = '0';
char movelenthtype = '0';
char zoffsetmovelen = '0';
char material_temp[MATERIAL_LEN+1];
bool input_win_flag;

bool input_hotendtemp_flag;
bool input_bedtemp_flag;
char input_pidseting[6];
char input_piddate[6];
bool input_pidhot_p_flag;
bool input_pidhot_i_flag;
bool input_pidhot_d_flag;
bool input_pidbed_p_flag;
bool input_pidbed_i_flag;
bool input_pidbed_d_flag;
bool autopidtype_flag;
bool input_printhottemp_flag = false;
bool input_printbedtemp_flag = false;
bool input_printfeed_flag = false;
bool input_printzoffset_flag = false;
bool input_printflow_flag = false;
int input_autopidhottemp_flag = 0;
int input_autopidhotcount_flag= 0;
int input_autopidbedtemp_flag = 0;
int input_autopidbedcount_flag= 0;
bool printpage_pause_flag;

char input_hotend_temp[MATERIAL_LEN+1];
char input_bed_temp[MATERIAL_LEN+1];
char input_feed_temp[MATERIAL_LEN+1];
char input_flow_temp[MATERIAL_LEN+1];
char input_pretemphot_temp[MATERIAL_LEN+1];
bool input_pretemphot_flag;

char changeflag_probetest;
char autolevelingflag = 0;
char probe_offsetlenth = '0';


char print_percent[PERCENT_LEN+2];
char print_remain_time[PRINT_TIME_LEN+1];
char print_printed_time[PRINT_TIME_LEN+1];
char errorcode[10];
char k1_errorcode[10];
bool current_error = false;
bool current_tips = false;
char current_version[VERSION_LEN+1];
char version_flag = '\0';
char upgrade_progress[MATERIAL_LEN];
char new_version[VERSION_LEN+1];
char version_size[VERSION_LEN+1];
char selftest_result[SLEFTEST_COUNT] = {0};
bool selftest_flag = false;
lv_timer_t * mytimer;
lv_timer_t * mytimer_1;
lv_timer_t * mytimer_2;
lv_timer_t * mytimer_3;
lv_timer_t * wait_timer;
bool connectwifi_state = false;
uint32_t timer_user_data = 0;

//unsigned char led_on_r_color = 66;
//unsigned char led_on_g_color = 189;
//unsigned char led_on_b_color = 216;
//unsigned char led_off_r_color = 121;
//unsigned char led_off_g_color = 121;
//unsigned char led_off_b_color = 121;
//
int model_start_pix;
int model_end_pix;
char big_photo_name[FILE_PHOTO_SIZE+1];
struct display_file_info dis_file_info[FILE_NUM_PRE_PAGE];
struct history_file_info history_file_list[HISTORY_NUM_PRE_PAGE];
struct video_info video_file_list[VIDEO_NUM_PRE_PAGE];
char qrcode_name[FILE_PHOTO_SIZE+1];

//bool refresh_hotend_temp;
//bool refresh_bed_temp;
//bool refresh_pla_hotend_temp;
//bool refresh_pla_bed_temp;
//bool refresh_petg_hotend_temp;
//bool refresh_petg_bed_temp;
//bool refresh_self_hotend_temp;
//bool refresh_self_bed_temp;
//bool refresh_zoffset;
//bool refresh_preheat_hotend;
//bool refresh_preheat_bed;
//bool refresh_pid_hotend_p;
//bool refresh_pid_hotend_i;
//bool refresh_pid_hotend_d;
//bool refresh_pid_bed_p;
//bool refresh_pid_bed_i;
//bool refresh_pid_bed_d;
//bool refresh_steps_x;
//bool refresh_steps_y;
//bool refresh_steps_z;
//bool refresh_steps_e;
//bool refresh_macc_x;
//bool refresh_macc_y;
//bool refresh_macc_z;
//bool refresh_macc_e;
//bool refresh_jerk_x;
//bool refresh_jerk_y;
//bool refresh_jerk_z;
//bool refresh_jerk_e;
//bool refresh_mspeed_x;
//bool refresh_mspeed_y;
//bool refresh_mspeed_z;
//bool refresh_mspeed_e;
//bool refresh_print_speed;
bool print_file_ok;
//bool refresh_repeat_times;
//bool refresh_bed_size_x;
//bool refresh_bed_size_y;
//bool refresh_pid_hotend_tar;
//bool refresh_pid_hotend_times;
//bool refresh_pid_bed_tar;
//bool refresh_pid_bed_times;
bool refresh_material_in;
bool refresh_material_out;
bool rebootflag = false;
//
//int msg_id;
int print_state = 1;  //0:未打印或打印停止，1：正在打印，2：暂停打印，3：打印完成，6：温度升温中
int auto_pid_progress;
int auto_level_progress;

lv_chart_series_t * pid_temp;

char wifi_state;
char wifi_name[WIFI_NAME_LEN+1];
char wifi_ip[16];
char wifi_signal_level[16];
char wire_net_state;
char wire_net_ip[16];
char wire_gateway[20];
char wire_subnet_mask[20];
char wire_dns[20];
char exchange_wifi_name[WIFI_NAME_LEN+1];       //用于弹出窗口做数据交换和判断的数据
unsigned char exchange_wifi_state;             //用于弹出窗口做数据交换和判断的数据

bool screen_rotate;
bool selftestflag = false;
int manualtestcount = 0;
int UIType = CR_K1;
bool IsK1MaxSe = false; //(暂时使用flag标识IsK1MaxSe版本，后续UI型号部分代码更新后去掉)
bool IsK1C = false; //(暂时使用flag标识K1C版本，后续UI型号部分代码更新后去掉)
int CheckUpdataFlag = 0;
lv_obj_t *list_btn;

char manualtest[11] = {0};
char manualtestlength;
char manualtest_curpage;

/******延时摄影参数设置*********/
bool isopencamera;
bool cameraposition;
char picturelayers[CAMERA_SIZE_LEN+1];
char Render_mode[CAMERA_SIZE_LEN+1];
/******延时摄影参数设置*********/

/*****运动轴状态*********/
bool x_state = false;
bool y_state = false;
bool z_state = false;
/******运动轴状态*********/

/*****系统状态信息*********/
SysConInfo_t system_state = {0};
AIConfigState_t ai_state = {0};
MachineInfo_t machineinfo = {0};
CloudUserInfo_t cxyUserinfo = {0};
UIInit_t init_uiconfiginfo = {0};
/******系统状态信息*********/
static void ReportMESQrcodeExitEventHandler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *reportCont = lv_event_get_user_data(e);
	switch (code) {
        case LV_EVENT_CLICKED: lv_obj_del(reportCont); break;
        default: break;
	}
}

void ReportMESQrcode(int id, json_object *result, char *describe)
{
    char productionSn[100] = {0};
    if (!result) result = json_object_new_object();
    if (!describe) describe = "";

    // 从文件获取生产信息
    json_object *productionInfoObj = json_object_from_file(GetMachineProductionInfo());
    if (productionInfoObj) {
        json_object *snObj = GetJsonObject(productionInfoObj, "productionSn", json_type_string);
        if (snObj) strcat(productionSn, json_object_get_string(snObj));
        json_object_put(productionInfoObj);
    }
    else CrLogW("no production info\n");

    // 生成二维码信息
    json_object *report = json_object_new_object();
    json_object_object_add(report, "sn", json_object_new_string(productionSn));
    json_object_object_add(report, "dn", json_object_new_string(GetSystemConfig().device_sn));
    json_object_object_add(report, "id", json_object_new_int(id));
    json_object_object_add(report, "result", result);

    int jsonFlag = JSON_C_TO_STRING_PLAIN | JSON_C_TO_STRING_PRETTY_TAB | JSON_C_TO_STRING_NOZERO | JSON_C_TO_STRING_NOSLASHESCAPE;
    char *reportStr = json_object_to_json_string_ext(report, jsonFlag);
    CrLogI("reportStr; len = %d, str = %s", strlen(reportStr), reportStr);

    // 创建容器
	lv_obj_t *reportCont = lv_obj_create(lv_layer_top());
    lv_obj_set_align(reportCont, LV_ALIGN_LEFT_MID);
    lv_obj_set_style_pad_all(reportCont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(reportCont, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(reportCont, lv_obj_get_width(lv_layer_top()), lv_obj_get_height(lv_layer_top()));
    // 创建二维码
    lv_obj_t *reportQrcode = lv_qrcode_create(reportCont, lv_obj_get_height(lv_layer_top()), lv_color_hex(0xFFFFFF), lv_color_hex(0x000000));
    // 返回按键
	lv_obj_t *returnBtn = lv_btn_create(reportCont);
    lv_obj_align(returnBtn, LV_ALIGN_BOTTOM_RIGHT, -30, -30);
    lv_obj_add_event_cb(returnBtn, ReportMESQrcodeExitEventHandler, LV_EVENT_ALL, reportCont);
    lv_obj_t *returnBtnName = lv_label_create(returnBtn);
    lv_label_set_text(returnBtnName, "返回");
    lv_obj_set_style_text_font(returnBtnName, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // 二维码描述
    lv_obj_t *describeTotal = lv_label_create(reportCont);
    lv_obj_align_to(describeTotal, reportQrcode, LV_ALIGN_OUT_RIGHT_TOP, 30, 50);
    lv_label_set_text(describeTotal, "检测项目：");
    lv_obj_set_style_text_font(describeTotal, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(describeTotal, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t *describeLabel = lv_label_create(reportCont);
    lv_obj_align_to(describeLabel, describeTotal, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
    lv_obj_set_size(describeLabel, 250, 200);
    lv_label_set_text(describeLabel, describe);
    lv_obj_set_style_text_font(describeLabel, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(describeLabel, lv_color_hex(0xFFFFFF), 0);

    // 显示二维码
    lv_qrcode_update(reportQrcode, reportStr, strlen(reportStr));
    json_object_put(report);
}

void btn_alern_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
//            lv_obj_clean(guider_ui.my_msgbox_cont_1);
//            lv_obj_del(guider_ui.my_msgbox_cont_1);
            lv_obj_add_flag(guider_ui.my_msgbox_cont_1, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
            if(rebootflag)
            {
                set_printer_data(0x19,1,"2");
                rebootflag = false;
            }
        }
		break;
        default:
		break;
	}
}

void mymsgbox(char *msg)
{
    if (!lv_obj_is_valid(guider_ui.my_msgbox_cont_1))
    {
        guider_ui.my_msgbox_cont_1 = lv_obj_create(lv_layer_top());
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_size(guider_ui.my_msgbox_cont_1, 400, 200);
        lv_obj_align(guider_ui.my_msgbox_cont_1,LV_ALIGN_CENTER,0,0);
        lv_obj_add_style(guider_ui.my_msgbox_cont_1, &style_cont_default, LV_PART_MAIN|LV_STATE_DEFAULT);

        lv_obj_t *btn_1 = lv_btn_create(guider_ui.my_msgbox_cont_1);
        lv_obj_set_size(btn_1, 146, 60);
        lv_obj_align(btn_1,LV_ALIGN_BOTTOM_MID,0,-10);
        lv_obj_add_style(btn_1, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(btn_1, 0, LV_STATE_DEFAULT);
        lv_obj_clear_flag(btn_1, LV_OBJ_FLAG_CLICKABLE);

        //Write codes label_title
        lv_obj_t * label_title = lv_label_create(guider_ui.my_msgbox_cont_1);
        lv_obj_set_size(label_title, 98, 32);
        lv_obj_align(label_title,LV_ALIGN_TOP_MID,0,10);
        lv_label_set_text(label_title, "TIPS");
        lv_label_set_long_mode(label_title, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_align(label_title, LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_add_style(label_title, &style_white32_text_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(label_title, &lv_font_simsun_28, LV_STATE_DEFAULT);

        //Write codes label_msg
        lv_obj_t * label_msg = lv_label_create(guider_ui.my_msgbox_cont_1);
        lv_obj_set_size(label_msg, 300, 35);
        lv_obj_align(label_msg,LV_ALIGN_CENTER,0,0);
        lv_label_set_text(label_msg, msg);
        lv_label_set_long_mode(label_msg, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_align(label_msg, LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_add_style(label_msg, &style_white28_text_default, LV_PART_MAIN|LV_STATE_DEFAULT);

        //Write codes btn_alern
        lv_obj_t * btn_alern = lv_btn_create(guider_ui.my_msgbox_cont_1);
        lv_obj_set_size(btn_alern, 146, 60);
        lv_obj_align(btn_alern,LV_ALIGN_BOTTOM_MID,0,-10);
        lv_obj_add_style(btn_alern, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);

        lv_obj_t * btn_alern_label = lv_label_create(btn_alern);
        if(rebootflag)
            lv_label_set_text(btn_alern_label, "Reset");
        else
            lv_label_set_text(btn_alern_label, "OK");
        lv_obj_set_style_text_color(btn_alern_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn_alern_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(btn_alern, 0, LV_STATE_DEFAULT);
        lv_obj_align(btn_alern_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn_alern, btn_alern_event_handler, LV_EVENT_ALL, NULL);
    }
    if (lv_obj_has_flag(guider_ui.my_msgbox_cont_1,LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(guider_ui.my_msgbox_cont_1, LV_OBJ_FLAG_HIDDEN);
    }
}
void mymsgbox_two(char *msg)
{
//    if (!lv_obj_is_valid(guider_ui.my_msgbox_two_cont_1))
//    {
//        guider_ui.my_msgbox_two_cont_1 = lv_obj_create(lv_layer_top());
//        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//
//            lv_obj_set_pos(guider_ui.my_msgbox_two_cont_1, 35, 180);
//            lv_obj_set_size(guider_ui.my_msgbox_two_cont_1, 411, 500);
//
//
//        lv_obj_add_style(guider_ui.my_msgbox_two_cont_1, &style_cont_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//        lv_obj_t * btn_1 = lv_btn_create(guider_ui.my_msgbox_two_cont_1);
//
//            lv_obj_set_pos(btn_1, 0, 0);
//            lv_obj_set_size(btn_1, 460, 320);
//
//
//        lv_obj_add_style(btn_1, &style_background_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//        lv_obj_set_style_pad_all(btn_1, 0, LV_STATE_DEFAULT);
//        lv_obj_clear_flag(btn_1, LV_OBJ_FLAG_CLICKABLE);
//
//
//        //Write codes label_title
//        lv_obj_t * label_title = lv_label_create(guider_ui.my_msgbox_two_cont_1);
//
//            lv_obj_set_pos(label_title, 10, 30);
//            lv_obj_set_size(label_title, 440, 36);
//
//
//        lv_label_set_text(label_title, "温馨提示");
//        lv_label_set_long_mode(label_title, LV_LABEL_LONG_SCROLL_CIRCULAR);
//        lv_obj_set_style_text_align(label_title, LV_TEXT_ALIGN_CENTER, 0);
//        lv_obj_add_style(label_title, &style_white32_text_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//        //Write codes label_msg
//        lv_obj_t * label_msg = lv_label_create(guider_ui.my_msgbox_two_cont_1);
//
//            lv_obj_set_pos(label_msg, 10, 110);
//            lv_obj_set_size(label_msg, 440, 32);
//
//
//        lv_label_set_text(label_msg, msg);
//        lv_label_set_long_mode(label_msg, LV_LABEL_LONG_SCROLL_CIRCULAR);
//        lv_obj_set_style_text_align(label_msg, LV_TEXT_ALIGN_CENTER, 0);
//        lv_obj_add_style(label_msg, &style_white28_text_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//        //Write codes my_msgbox_ok
//        guider_ui.my_msgbox_ok = lv_btn_create(guider_ui.my_msgbox_two_cont_1);
//
//            lv_obj_set_pos(guider_ui.my_msgbox_ok, 30, 220);
//            lv_obj_set_size(guider_ui.my_msgbox_ok, 200, 80);
//
//        lv_obj_add_style(guider_ui.my_msgbox_ok, &style_fillet_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//        lv_obj_t * btn_ok_label = lv_label_create(guider_ui.my_msgbox_ok);
//        lv_label_set_text(btn_ok_label, "确认");
//        lv_obj_set_style_text_color(btn_ok_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
//        lv_obj_set_style_text_font(btn_ok_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
//        lv_obj_set_style_pad_all(guider_ui.my_msgbox_ok, 0, LV_STATE_DEFAULT);
//        lv_obj_align(btn_ok_label, LV_ALIGN_CENTER, 0, 0);
//
//        //Write codes my_msgbox_cancel
//        guider_ui.my_msgbox_cancel = lv_btn_create(guider_ui.my_msgbox_two_cont_1);
//
//            lv_obj_set_pos(guider_ui.my_msgbox_cancel, 250, 220);
//            lv_obj_set_size(guider_ui.my_msgbox_cancel, 200, 80);
//
//
//        lv_obj_add_style(guider_ui.my_msgbox_cancel, &style_fillet_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//        lv_obj_t * btn_cancel_label = lv_label_create(guider_ui.my_msgbox_cancel);
//        lv_label_set_text(btn_cancel_label, "取消");
//        lv_obj_set_style_text_color(btn_cancel_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
//        lv_obj_set_style_text_font(btn_cancel_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
//        lv_obj_set_style_pad_all(guider_ui.my_msgbox_cancel, 0, LV_STATE_DEFAULT);
//        lv_obj_align(btn_cancel_label, LV_ALIGN_CENTER, 0, 0);
//    }
//    if (lv_obj_has_flag(guider_ui.my_msgbox_two_cont_1,LV_OBJ_FLAG_HIDDEN))
//    {
//        lv_obj_clear_flag(guider_ui.my_msgbox_two_cont_1, LV_OBJ_FLAG_HIDDEN);
//    }
////	lv_obj_add_event_cb(guider_ui.my_msgbox_ok, btn_alern_event_handler, LV_EVENT_ALL, NULL);
}

void inputboard_event_handler(lv_event_t * e)
{
    static char input_str[10] = {'\0'};
    static int len = 0;
    int tint = 0;
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            uint16_t input_char = lv_event_get_user_data(e);
            CrLogI("%c",input_char);
            switch(input_char)
            {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                {
                    if(len < 10)
                    {
                        input_str[len++] = input_char;
                        lv_label_set_text(guider_ui.keyboardinput_label_title,input_str);
                    }
                    break;
                }
                case 'B':
                {
                    if(len > 0)
                    {
                        input_str[--len] = '\0';
                        lv_label_set_text(guider_ui.keyboardinput_label_title,input_str);
                    }
                    break;
                }
                case 'E':
                {
                    send_buzzer(0x01);
                    memset(input_str,0,sizeof(input_str));
                    len = 0;
                    lv_obj_add_flag(guider_ui.keyboardinput_cont_1, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
                    break;
                }
                case 'O':
                {
                    tint = atoi(input_str);
                    if((tint > input_max) || (tint < input_min))
                    {
                        mymsgbox("输入的数据超出范围,请重新输入");
                        memset(input_str,0,sizeof(input_str));
                        lv_label_set_text(guider_ui.keyboardinput_label_title,"0");
                        len = 0;
                        break;
                    }
                    else if(input_str[0] != '\0' && input_label != NULL)
                    {
                        lv_label_set_text(input_label,input_str);
                        if(input_type == 0)     //更改喷头温度
                        {
                            char temp[HOTEND_TEMP_LEN+1+1] = {'\0'};
                            temp[0] = '2';
                            strcat(temp,input_str);
                            set_printer_data(0x03,strlen(temp),temp);
                        }
                        if(input_type == 1)     //更改热床温度
                        {
                            char temp[BED_TEMP_LEN+1+1] = {'\0'};
                            temp[0] = '1';
                            strcat(temp,input_str);
                            set_printer_data(0x03,strlen(temp),temp);
                        }
                        if(input_type == 2)     //更改打印速率
                        {
                            set_printer_data(0x10,strlen(input_str),input_str);
                        }
                        if(input_type == 3)     //喷头PID校准
                        {
                            char temp[HOTEND_TEMP_LEN+1+1+1] = {'\0'};
                            temp[0] = '1';
                            strcat(temp,input_str);
                            set_printer_data(0x0d,strlen(temp),temp);
                            memset(temp,0,HOTEND_TEMP_LEN+1+1+1);
                            snprintf(temp,HOTEND_TEMP_LEN+1+1+1,"%s℃",input_str);
                            lv_label_set_text(input_label,temp);
                        }
                        if(input_type == 4)     //热床PID校准
                        {
                            char temp[BED_TEMP_LEN+1+1+1] = {'\0'};
                            temp[0] = '3';
                            strcat(temp,input_str);
                            set_printer_data(0x0d,strlen(temp),temp);
                            memset(temp,0,HOTEND_TEMP_LEN+1+1+1);
                            snprintf(temp,BED_TEMP_LEN+1+1+1,"%s℃",input_str);
                            lv_label_set_text(input_label,temp);
                        }
                    }
                    memset(input_str,0,sizeof(input_str));
                    len = 0;
                    lv_obj_add_flag(guider_ui.keyboardinput_cont_1, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
                    break;
                  }
                default:
                    break;
            }
        }
        break;
        default:
		break;
	}
}

void keyboardinput(char *msg,lv_obj_t *label_text,int *inputmax,int *inputmin,int type)
{
    if( guider_ui.keyboardinput_cont_1 == NULL )
    {
        guider_ui.keyboardinput_cont_1 = lv_obj_create(lv_layer_top());
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_size(guider_ui.keyboardinput_cont_1, 480, 522);
        lv_obj_align(guider_ui.keyboardinput_cont_1,LV_ALIGN_CENTER,0,0);
        lv_obj_add_style(guider_ui.keyboardinput_cont_1, &style_cont_msgbox, LV_PART_MAIN|LV_STATE_DEFAULT);

        lv_obj_t *img_1 = lv_img_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(img_1, 23, 23);
        lv_obj_align(img_1,LV_ALIGN_TOP_LEFT,50,50);
        lv_obj_add_style(img_1, &style_img_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_add_flag(img_1, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_event_cb(img_1, inputboard_event_handler, LV_EVENT_ALL, 'E');
        lv_img_set_src(img_1,&_group_1453_23x23);

        guider_ui.keyboardinput_label_title = lv_label_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(guider_ui.keyboardinput_label_title, 300, 28);
        lv_obj_align_to(guider_ui.keyboardinput_label_title,img_1,LV_ALIGN_OUT_RIGHT_TOP,0,0);
        lv_label_set_text(guider_ui.keyboardinput_label_title, msg);
        lv_obj_set_style_text_font(guider_ui.keyboardinput_label_title, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(guider_ui.keyboardinput_label_title, LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_add_style(guider_ui.keyboardinput_label_title, &style_white24_text_creality, LV_PART_MAIN|LV_STATE_DEFAULT);

        //btn0
        lv_obj_t * btn0 = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn0, 120, 80);
        lv_obj_align(btn0,LV_ALIGN_BOTTOM_LEFT,49,-68);
        lv_obj_add_style(btn0, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_t * btn0_label = lv_label_create(btn0);
        lv_label_set_text(btn0_label, "0");
        lv_obj_set_style_text_color(btn0_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn0_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_align(btn0_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn0, inputboard_event_handler, LV_EVENT_ALL, '0');

        //btn1
        lv_obj_t * btn1 = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn1, 120, 80);
        lv_obj_align_to(btn1,btn0,LV_ALIGN_OUT_TOP_MID,0,-15);
        lv_obj_add_style(btn1, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_t * btn1_label = lv_label_create(btn1);
        lv_label_set_text(btn1_label, "1");
        lv_obj_set_style_text_color(btn1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn1_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_align(btn1_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn1, inputboard_event_handler, LV_EVENT_ALL, '1');

        //btn2
        lv_obj_t * btn2 = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn2, 120, 80);
        lv_obj_align_to(btn2,btn1,LV_ALIGN_OUT_RIGHT_TOP,15,0);
        lv_obj_add_style(btn2, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_t * btn2_label = lv_label_create(btn2);
        lv_label_set_text(btn2_label, "2");
        lv_obj_set_style_text_color(btn2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn2_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_align(btn2_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn2, inputboard_event_handler, LV_EVENT_ALL, '2');

        //btn3
        lv_obj_t * btn3 = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn3, 120, 80);
        lv_obj_align_to(btn3,btn2,LV_ALIGN_OUT_RIGHT_TOP,15,0);
        lv_obj_add_style(btn3, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_t * btn3_label = lv_label_create(btn3);
        lv_label_set_text(btn3_label, "3");
        lv_obj_set_style_text_color(btn3_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn3_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_align(btn3_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn3, inputboard_event_handler, LV_EVENT_ALL, '3');

        //btn4
        lv_obj_t * btn4 = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn4, 120, 80);
        lv_obj_align_to(btn4,btn1,LV_ALIGN_OUT_TOP_MID,0,-15);
        lv_obj_add_style(btn4, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_t * btn4_label = lv_label_create(btn4);
        lv_label_set_text(btn4_label, "4");
        lv_obj_set_style_text_color(btn4_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn4_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_align(btn4_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn4, inputboard_event_handler, LV_EVENT_ALL, '4');

        //btn5
        lv_obj_t * btn5 = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn5, 120, 80);
        lv_obj_align_to(btn5,btn4,LV_ALIGN_OUT_RIGHT_TOP,15,0);
        lv_obj_add_style(btn5, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_t * btn5_label = lv_label_create(btn5);
        lv_label_set_text(btn5_label, "5");
        lv_obj_set_style_text_color(btn5_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn5_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_align(btn5_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn5, inputboard_event_handler, LV_EVENT_ALL, '5');

        //btn6
        lv_obj_t * btn6 = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn6, 120, 80);
        lv_obj_align_to(btn6,btn5,LV_ALIGN_OUT_RIGHT_TOP,15,0);
        lv_obj_add_style(btn6, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_t * btn6_label = lv_label_create(btn6);
        lv_label_set_text(btn6_label, "6");
        lv_obj_set_style_text_color(btn6_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn6_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_align(btn6_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn6, inputboard_event_handler, LV_EVENT_ALL, '6');

        //btn7
        lv_obj_t * btn7 = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn7, 120, 80);
        lv_obj_align_to(btn7,btn4,LV_ALIGN_OUT_TOP_MID,0,-15);
        lv_obj_add_style(btn7, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_t * btn7_label = lv_label_create(btn7);
        lv_label_set_text(btn7_label, "7");
        lv_obj_set_style_text_color(btn7_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn7_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_align(btn7_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn7, inputboard_event_handler, LV_EVENT_ALL, '7');

        //btn8
        lv_obj_t * btn8 = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn8, 120, 80);
        lv_obj_align_to(btn8,btn7,LV_ALIGN_OUT_RIGHT_TOP,15,0);
        lv_obj_add_style(btn8, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_t * btn8_label = lv_label_create(btn8);
        lv_label_set_text(btn8_label, "8");
        lv_obj_set_style_text_color(btn8_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn8_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_align(btn8_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn8, inputboard_event_handler, LV_EVENT_ALL, '8');

        //btn9
        lv_obj_t * btn9 = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn9, 120, 80);
        lv_obj_align_to(btn9,btn8,LV_ALIGN_OUT_RIGHT_TOP,15,0);
        lv_obj_add_style(btn9, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_t * btn9_label = lv_label_create(btn9);
        lv_label_set_text(btn9_label, "9");
        lv_obj_set_style_text_color(btn9_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn9_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_align(btn9_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn9, inputboard_event_handler, LV_EVENT_ALL, '9');

        //btnback
        lv_obj_t * btn_back = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn_back, 120, 80);
        lv_obj_align_to(btn_back,btn0,LV_ALIGN_OUT_RIGHT_TOP,15,0);
        lv_obj_add_style(btn_back, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_add_event_cb(btn_back, inputboard_event_handler, LV_EVENT_ALL, 'B');
        lv_obj_t *img_back = lv_img_create(btn_back);
        lv_obj_set_size(img_back, 36, 24);
        lv_obj_align(img_back,LV_ALIGN_CENTER,0,0);
        lv_obj_add_style(img_back, &style_img_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_add_event_cb(img_back, inputboard_event_handler, LV_EVENT_ALL, 'B');
        lv_obj_add_flag(img_back, LV_OBJ_FLAG_CLICKABLE);
        lv_img_set_src(img_back,&_back_36x24);

        //btnok
        lv_obj_t * btn_ok = lv_btn_create(guider_ui.keyboardinput_cont_1);
        lv_obj_set_size(btn_ok, 120, 80);
        lv_obj_align_to(btn_ok,btn_back,LV_ALIGN_OUT_RIGHT_TOP,15,0);
        lv_obj_add_style(btn_ok, &style_normal_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_t * btn_ok_label = lv_label_create(btn_ok);
        lv_label_set_text(btn_ok_label, "ok");
        lv_obj_set_style_text_color(btn_ok_label, lv_color_make(0x42, 0xbd, 0xd8), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(btn_ok_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
        lv_obj_align(btn_ok_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_event_cb(btn_ok, inputboard_event_handler, LV_EVENT_ALL, 'O');
        CrLogI("create the keyboard hidden.");
    }
    if (lv_obj_has_flag(guider_ui.keyboardinput_cont_1,LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(guider_ui.keyboardinput_cont_1,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_label_set_text(guider_ui.keyboardinput_label_title, msg);
        CrLogI("clear the keyboard hidden.");
    }
    input_max = inputmax;
    input_min = inputmin;
    input_label = label_text;
    input_type = type;
}

void lv_demo_printer_anim_in_all(lv_obj_t * obj, uint32_t delay)
{
    return;
    if(delay == 0)
        return;
    lv_coord_t y;
    lv_obj_t * child;
    for(int i = 0; i < lv_obj_get_child_cnt(obj); i++)
	{
        child = lv_obj_get_child(obj, i);
        lv_obj_update_layout(child);
        y = lv_obj_get_y(child);
        if (child != lv_scr_act())
		{
            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, child);
            lv_anim_set_time(&a, LV_DEMO_PRINTER_ANIM_TIME);
            lv_anim_set_delay(&a, delay);
            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);

//            if(y > 240)
//                lv_anim_set_values(&a, 479, y);
//            else
                lv_anim_set_values(&a, 0, y);

            lv_anim_start(&a);

            lv_obj_fade_in(child, LV_DEMO_PRINTER_ANIM_TIME - 50, delay);
        }
    }
}

lv_obj_t **get_scr_by_id(int scr_id)
{
    if(scr_id == SCR_HOME_PAGE)
        return &guider_ui.homepage_cont_1;
    else if(scr_id == SCR_MOVE_PAGE)
        return &guider_ui.axismove_cont_1;
    else if(scr_id == SCR_FILES_PAGE)
        return &guider_ui.file_management_cont_1;
    else if(scr_id == SCR_SETINGS_PAGE)
        return &guider_ui.settings_cont_1;
    else if(scr_id == SCR_FAQ_PAGE)
        return &guider_ui.FAQ_cont_1;
    else if(scr_id == SCR_KEYTONE_PAGE)
        return &guider_ui.keytone_setting_cont_1;
    else if(scr_id == SCR_DEVICE_PAGE)
        return &guider_ui.device_binding_cont_1;
    else if(scr_id == SCR_EXPORTLOG_PAGE)
        return &guider_ui.export_log_cont_1;
    else if(scr_id == SCR_ABOUTDEVICE_PAGE)
        return &guider_ui.about_device_cont_1;
    else if(scr_id == SCR_RESET_PAGE)
        return &guider_ui.resetdevide_cont_1;
    else if(scr_id == SCR_FILEINFOMATION_PAGE)
        return &guider_ui.file_information_cont_1;
    else if(scr_id == SCR_CHANGEPRINTSTATE_PAGE)
        return &guider_ui.change_printstate_cont_1;
    else if(scr_id == SCR_NETINFOMATION_PAGE)
        return &guider_ui.netwowork_information_cont_1;
    else if(scr_id == SCR_PRINTADJUST_PAGE)
        return &guider_ui.printing_adjust_cont_1;
    else if(scr_id == SCR_SELFTEST_PAGE)
        return &guider_ui.selftest_cont_1;
    else if(scr_id == SCR_VIDEOLIST_PAGE)
        return &guider_ui.video_list_cont_1;
    else if(scr_id == SCR_VIDEOINFO_PAGE)
        return &guider_ui.video_information_cont_1;
    else if(scr_id == SCR_CAMERASETING_PAGE)
        return &guider_ui.camera_seting_cont_1;
    return NULL;
}

void guider_load_screen(int scr_id)
{
    lv_obj_t **old_scr = NULL;

    //1、清除新页面的隐藏标志
    switch(scr_id)
    {
        case SCR_HOME_PAGE:           //主页面
            lv_obj_clear_flag(guider_ui.homepage_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load print main");
            break;
        case SCR_MOVE_PAGE:                 //移动页面
            lv_obj_clear_flag(guider_ui.axismove_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load move");
            break;
        case SCR_FILES_PAGE:              //准备打印页面
            lv_obj_clear_flag(guider_ui.file_management_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load file");
            break;
        case SCR_SETINGS_PAGE:                 //移动页面
            lv_obj_clear_flag(guider_ui.settings_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load settings");
            break;
        case SCR_FAQ_PAGE:              //准备打印页面
            lv_obj_clear_flag(guider_ui.FAQ_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load FAQ");
            break;
        case SCR_FILEINFOMATION_PAGE:
            lv_obj_clear_flag(guider_ui.file_information_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load keytone");
            break;
        case SCR_KEYTONE_PAGE:          //按键音页面
            lv_obj_clear_flag(guider_ui.keytone_setting_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load keytone");
            break;
        case SCR_DEVICE_PAGE:
            lv_obj_clear_flag(guider_ui.device_binding_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load device");
            break;
        case SCR_EXPORTLOG_PAGE:
            lv_obj_clear_flag(guider_ui.export_log_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load export");
            break;
        case SCR_ABOUTDEVICE_PAGE:
            lv_obj_clear_flag(guider_ui.about_device_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load about_device");
            break;
        case SCR_RESET_PAGE:
            lv_obj_clear_flag(guider_ui.resetdevide_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load reset");
            break;
        case SCR_CHANGEPRINTSTATE_PAGE:
            lv_obj_clear_flag(guider_ui.change_printstate_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load change_printstate");
            break;
        case SCR_NETINFOMATION_PAGE:
            lv_obj_clear_flag(guider_ui.netwowork_information_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load netwowork_information");
            break;
        case SCR_PRINTADJUST_PAGE:
            lv_obj_clear_flag(guider_ui.printing_adjust_cont_1, LV_OBJ_FLAG_HIDDEN);
            CrLogI("load printing_adjust");
            break;
        case SCR_SELFTEST_PAGE:
            lv_obj_clear_flag(guider_ui.selftest_cont_1,LV_OBJ_FLAG_HIDDEN);
            CrLogI("load printing_adjust");
            break;
        case SCR_VIDEOLIST_PAGE:
            lv_obj_clear_flag(guider_ui.video_list_cont_1,LV_OBJ_FLAG_HIDDEN);
            CrLogI("load video_list");
            break;
        case SCR_VIDEOINFO_PAGE:
            lv_obj_clear_flag(guider_ui.video_information_cont_1,LV_OBJ_FLAG_HIDDEN);
            CrLogI("load video_infomation");
            break;
        case SCR_CAMERASETING_PAGE:
            lv_obj_clear_flag(guider_ui.camera_seting_cont_1,LV_OBJ_FLAG_HIDDEN);
            CrLogI("load camera_seting");
            break;
        default:
            break;
    }

    //2、旧页面隐藏
    old_scr = get_scr_by_id(cur_scr);
    CrLogI("hidden the old page.");
    if(old_scr != NULL && old_scr != get_scr_by_id(scr_id))
    {
        lv_obj_add_flag(*old_scr, LV_OBJ_FLAG_HIDDEN);
    }

    //3、新页面组件内容初始化
    CrLogI("load the new page.");
    load_screen_init(scr_id);

    //4、标志量更新
    cur_scr = scr_id;
//    memory_print();
}

void load_screen_init(int scr_id)
{
    switch(scr_id)
    {
        case SCR_HOME_PAGE:           //主页面
        {
            CrLogI("refresh homepage data.");
            //1、获取需要刷新的数据
            get_printer_data(0x03, 1, "\0");    //温度更新
            get_printer_data(0x10, 1, "\0");    //打印速率更新
            get_printer_data(0x06, 2, "0");    //风扇状态更新

            //2、根据打印状态隐藏部分的控件
            if(print_state == 0 || print_state == 1)    //空闲或已完成
            {
                lv_obj_add_flag(guider_ui.homepage_img_17,LV_OBJ_FLAG_HIDDEN);  //隐藏打印的暂停/停止按钮
                lv_obj_add_flag(guider_ui.homepage_img_16,LV_OBJ_FLAG_HIDDEN);  //隐藏打印的显示图片

                lv_obj_add_flag(guider_ui.homepage_bar_1,LV_OBJ_FLAG_HIDDEN);   //隐藏打印的进度条

                lv_obj_add_flag(guider_ui.homepage_label_6,LV_OBJ_FLAG_HIDDEN); //隐藏打印的进度文字
                lv_obj_add_flag(guider_ui.homepage_label_7,LV_OBJ_FLAG_HIDDEN); //隐藏打印的进度文字
                lv_obj_add_flag(guider_ui.homepage_label_8,LV_OBJ_FLAG_HIDDEN); //隐藏打印的进度文字
                lv_obj_add_flag(guider_ui.homepage_label_9,LV_OBJ_FLAG_HIDDEN); //隐藏打印的进度文字
                lv_obj_add_flag(guider_ui.homepage_label_10,LV_OBJ_FLAG_HIDDEN);//隐藏打印的进度文字
                lv_obj_add_flag(guider_ui.homepage_label_11,LV_OBJ_FLAG_HIDDEN);//隐藏打印的进度文字

                lv_obj_clear_flag(guider_ui.stacked_area_chart.obj,LV_OBJ_FLAG_HIDDEN);//显示温度曲线图
                lv_obj_clear_flag(guider_ui.homepage_img_10,LV_OBJ_FLAG_HIDDEN); //显示添加打印任务的图片
            }
            else if(print_state == 2)                  //暂停打印
            {
                CrLogI("Pause Print.");
                lv_obj_clear_flag(guider_ui.homepage_img_17,LV_OBJ_FLAG_HIDDEN);  //显示打印的开始/停止按钮
                lv_img_set_src(guider_ui.homepage_img_17,&_start_102x53);
                lv_obj_clear_flag(guider_ui.homepage_img_16,LV_OBJ_FLAG_HIDDEN);  //显示打印的显示图片

                lv_obj_clear_flag(guider_ui.homepage_bar_1,LV_OBJ_FLAG_HIDDEN);   //显示打印的进度条

                lv_obj_clear_flag(guider_ui.homepage_label_6,LV_OBJ_FLAG_HIDDEN); //显示打印的进度文字
                lv_obj_clear_flag(guider_ui.homepage_label_7,LV_OBJ_FLAG_HIDDEN); //显示打印的进度文字
                lv_obj_clear_flag(guider_ui.homepage_label_8,LV_OBJ_FLAG_HIDDEN); //显示打印的进度文字
                lv_obj_clear_flag(guider_ui.homepage_label_9,LV_OBJ_FLAG_HIDDEN); //显示打印的进度文字
                lv_obj_clear_flag(guider_ui.homepage_label_10,LV_OBJ_FLAG_HIDDEN);//显示打印的进度文字
                lv_obj_clear_flag(guider_ui.homepage_label_11,LV_OBJ_FLAG_HIDDEN);//显示打印的进度文字

                lv_obj_add_flag(guider_ui.stacked_area_chart.obj,LV_OBJ_FLAG_HIDDEN);//隐藏温度曲线图
                lv_obj_add_flag(guider_ui.homepage_img_10,LV_OBJ_FLAG_HIDDEN); //隐藏添加打印任务的图片
            }
            else if(print_state == 3)                  //继续打印
            {
                CrLogI("Printing");
                lv_obj_clear_flag(guider_ui.homepage_img_17,LV_OBJ_FLAG_HIDDEN);  //显示打印的暂停/停止按钮
                lv_img_set_src(guider_ui.homepage_img_17,&_pause_102x53);

                lv_obj_clear_flag(guider_ui.homepage_img_16,LV_OBJ_FLAG_HIDDEN);  //显示打印的显示图片

                lv_obj_clear_flag(guider_ui.homepage_bar_1,LV_OBJ_FLAG_HIDDEN);   //显示打印的进度条

                lv_obj_clear_flag(guider_ui.homepage_label_6,LV_OBJ_FLAG_HIDDEN); //显示打印的进度文字
                lv_obj_clear_flag(guider_ui.homepage_label_7,LV_OBJ_FLAG_HIDDEN); //显示打印的进度文字
                lv_obj_clear_flag(guider_ui.homepage_label_8,LV_OBJ_FLAG_HIDDEN); //显示打印的进度文字
                lv_obj_clear_flag(guider_ui.homepage_label_9,LV_OBJ_FLAG_HIDDEN); //显示打印的进度文字
                lv_obj_clear_flag(guider_ui.homepage_label_10,LV_OBJ_FLAG_HIDDEN);//显示打印的进度文字
                lv_obj_clear_flag(guider_ui.homepage_label_11,LV_OBJ_FLAG_HIDDEN);//显示打印的进度文字

                lv_obj_add_flag(guider_ui.stacked_area_chart.obj,LV_OBJ_FLAG_HIDDEN);//隐藏温度曲线图
                lv_obj_add_flag(guider_ui.homepage_img_10,LV_OBJ_FLAG_HIDDEN); //隐藏添加打印任务的图片
            }
            break;
        }
        case SCR_MOVE_PAGE:                 //移动页面
        {
            lv_obj_clear_flag(guider_ui.axismove_btn_1,LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(guider_ui.axismove_btn_2,LV_OBJ_FLAG_CLICKABLE);
            lv_obj_add_style(guider_ui.axismove_btn_3,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.axismove_btn_4,&btnstyle_check_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.axismove_btn_5,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            material_in_length[0] = '1';
            material_in_length[1] = '\t';
            material_out_length[0] = '1';
            material_out_length[1] = '\t';

            //获取温度和打印速度
            get_printer_data(0x03, 1, "\0");    //温度更新
            get_printer_data(0x10, 1, "\0");    //打印速率更新
            get_printer_data(0x06, 2, "0");    //风扇状态更新
            break;
        }
        case SCR_FILES_PAGE:                //文件管理页面
        {
            // 1、停止数据刷新
            set_refresh_data(0x00);
            // 2、隐藏部分控件
            //tab1
            lv_obj_add_flag(guider_ui.file_management_label_2,LV_OBJ_FLAG_HIDDEN);  //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_label_6,LV_OBJ_FLAG_HIDDEN);  //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_label_10,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_label_11,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_label_12,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_label_13,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_label_29,LV_OBJ_FLAG_HIDDEN); //隐藏暂无内容提示栏提示栏

            //tab2
            lv_obj_add_flag(guider_ui.file_management_sd_label_2,LV_OBJ_FLAG_HIDDEN);  //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_sd_label_6,LV_OBJ_FLAG_HIDDEN);  //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_sd_label_10,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_sd_label_11,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_sd_label_12,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_sd_label_13,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
            lv_obj_add_flag(guider_ui.file_management_label_28,LV_OBJ_FLAG_HIDDEN); //隐藏暂无内容提示栏提示栏

            //tab3
            lv_obj_add_flag(guider_ui.file_management_history_label_3, LV_OBJ_FLAG_HIDDEN);      //文件1
            lv_obj_add_flag(guider_ui.file_management_history_label_4, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.file_management_history_label_5, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.file_management_history_btn_3, LV_OBJ_FLAG_HIDDEN);       //
            lv_obj_add_flag(guider_ui.file_management_history_img_8, LV_OBJ_FLAG_HIDDEN);       //

            lv_obj_add_flag(guider_ui.file_management_history_label_11, LV_OBJ_FLAG_HIDDEN);      //文件2
            lv_obj_add_flag(guider_ui.file_management_history_label_15, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.file_management_history_label_19, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.file_management_history_btn_4, LV_OBJ_FLAG_HIDDEN);        //
            lv_obj_add_flag(guider_ui.file_management_history_img_9, LV_OBJ_FLAG_HIDDEN);       //

            lv_obj_add_flag(guider_ui.file_management_history_label_12,LV_OBJ_FLAG_HIDDEN);      //文件3
            lv_obj_add_flag(guider_ui.file_management_history_label_16, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.file_management_history_label_20, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.file_management_history_btn_5, LV_OBJ_FLAG_HIDDEN);        //
            lv_obj_add_flag(guider_ui.file_management_history_img_10, LV_OBJ_FLAG_HIDDEN);       //

            lv_obj_add_flag(guider_ui.file_management_history_label_13, LV_OBJ_FLAG_HIDDEN);      //文件4
            lv_obj_add_flag(guider_ui.file_management_history_label_17, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.file_management_history_label_21, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.file_management_history_btn_6, LV_OBJ_FLAG_HIDDEN);        //
            lv_obj_add_flag(guider_ui.file_management_history_img_11, LV_OBJ_FLAG_HIDDEN);       //

            lv_obj_add_flag(guider_ui.file_management_history_label_14, LV_OBJ_FLAG_HIDDEN);      //文件5
            lv_obj_add_flag(guider_ui.file_management_history_label_18, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.file_management_history_label_22, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.file_management_history_btn_7, LV_OBJ_FLAG_HIDDEN);        //
            lv_obj_add_flag(guider_ui.file_management_history_img_12, LV_OBJ_FLAG_HIDDEN);       //

            //3、从后台获取相应数据
            lv_event_send(guider_ui.file_management_tabview_1,LV_EVENT_CLICKED,NULL);            //进入页面通知当前tab刷新数据
//            get_response_printer_data(0x01,100,"1Ender-3 S1_tst.gcode:/tmp/creality/humbnail/image_file_1.png:6h43m:21.20m:0.2mm:57.2x57.2x99.8mm:1    ");
            break;
        }
        case SCR_SETINGS_PAGE:              //设置页面
        {
            if(refreshflag_settingpage)
                refresh_page_language();
            lv_event_send(guider_ui.settings_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);    //发送事件通知页面刷新
            break;
        }
        case SCR_FAQ_PAGE:                  //机器人页面
        {
            break;
        }
        case SCR_KEYTONE_PAGE:              //按键音页面
        {
            get_printer_data(0x06,1,"h");   //获取音量大小
            get_printer_data(0x06,1,"i");   //获取音效设置
            get_printer_data(0x06,1,"a");   //获取声音状态
            break;
        }
        case SCR_FILEINFOMATION_PAGE:
        {
            //1、关闭数据发送
            set_refresh_data(0x00);

            //2、对各label和image赋值
            char ctemp[20] = {0};
            snprintf(ctemp, sizeof(ctemp), "12\t%03d", (current_page * FILE_NUM_PRE_PAGE + clicked_file_num + 1));
            get_printer_data(0x01, strlen(ctemp),ctemp);

            strcpy(ctemp,"");
            strcat(ctemp,dis_file_info[clicked_file_num].name);
            lv_label_set_text(guider_ui.file_information_label_5,ctemp);

            strcpy(ctemp,"");
            strcat(ctemp,dis_file_info[clicked_file_num].estime);
            lv_label_set_text(guider_ui.file_information_label_7, ctemp);

            strcpy(ctemp,"");
            strcat(ctemp,dis_file_info[clicked_file_num].filament);
            lv_label_set_text(guider_ui.file_information_label_8, ctemp);
            break;
        }
        case SCR_NETINFOMATION_PAGE:
        {
            get_printer_data(0x07,2,"1");
            break;
        }
        case SCR_ABOUTDEVICE_PAGE:
        {
            get_printer_data(0x14,1,"\0");
            break;
        }
        case SCR_PRINTADJUST_PAGE:
        {
            get_printer_data(0x02,1,"\0");  //获取Z轴补偿
            get_printer_data(0x10,1,"\0");  //获取打印速度
            get_printer_data(0x16,1,"\0");  //获取打印流量比
            break;
        }
        case SCR_DEVICE_PAGE:
        {
            get_printer_data(0x15,1,"\0");  //获取创想云二维码图片
            break;
        }
        case SCR_SELFTEST_PAGE:
        {
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        case SCR_CAMERASETING_PAGE:
        {
            CrLogI("get the camerasetting.");
            get_printer_data(0x1d,1,"1");
            get_printer_data(0x1d,1,"3");
            get_printer_data(0x1d,1,"4");
            break;
        }
        case SCR_VIDEOLIST_PAGE:
        {
            CrLogI("load the videolist page.");
            get_printer_data(0x01,2,"30");
//            char temp[500] = {0};
//            snprintf(temp,500,"31\t%s\t%s","x3.gcode_2022-11-14_video.mp4:1668431840:530:1230:0:5:15:/usr/data//creality/userdata/delay_image/cover/1668431840.png","1668432810.mp4:1668432810:217:0:0:5:15:/usr/data//creality/userdata/delay_image/cover/1668432810.png");
//            get_response_printer_data(0x01,500,temp);

            //每次展示前都将文件控件隐藏
            lv_obj_add_flag(guider_ui.video_list_img_2, LV_OBJ_FLAG_HIDDEN);        //文件1
            lv_obj_add_flag(guider_ui.video_list_label_4, LV_OBJ_FLAG_HIDDEN);      //
            lv_obj_add_flag(guider_ui.video_list_label_5, LV_OBJ_FLAG_HIDDEN);      //
            lv_obj_add_flag(guider_ui.video_list_label_6, LV_OBJ_FLAG_HIDDEN);      //
            lv_obj_add_flag(guider_ui.video_list_img_9, LV_OBJ_FLAG_HIDDEN);        //

            lv_obj_add_flag(guider_ui.video_list_img_3, LV_OBJ_FLAG_HIDDEN);        //文件2
            lv_obj_add_flag(guider_ui.video_list_label_7, LV_OBJ_FLAG_HIDDEN);      //
            lv_obj_add_flag(guider_ui.video_list_label_8, LV_OBJ_FLAG_HIDDEN);      //
            lv_obj_add_flag(guider_ui.video_list_label_9, LV_OBJ_FLAG_HIDDEN);      //
            lv_obj_add_flag(guider_ui.video_list_img_10, LV_OBJ_FLAG_HIDDEN);       //

            lv_obj_add_flag(guider_ui.video_list_img_4, LV_OBJ_FLAG_HIDDEN);        //文件3
            lv_obj_add_flag(guider_ui.video_list_label_10, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.video_list_label_11, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.video_list_label_12, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.video_list_img_11, LV_OBJ_FLAG_HIDDEN);       //

            lv_obj_add_flag(guider_ui.video_list_img_5, LV_OBJ_FLAG_HIDDEN);        //文件4
            lv_obj_add_flag(guider_ui.video_list_label_13, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.video_list_label_14, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.video_list_label_15, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.video_list_img_12, LV_OBJ_FLAG_HIDDEN);       //

            lv_obj_add_flag(guider_ui.video_list_img_6, LV_OBJ_FLAG_HIDDEN);        //文件5
            lv_obj_add_flag(guider_ui.video_list_label_16, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.video_list_label_17, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.video_list_label_18, LV_OBJ_FLAG_HIDDEN);     //
            lv_obj_add_flag(guider_ui.video_list_img_13, LV_OBJ_FLAG_HIDDEN);       //
            break;
        }
        case SCR_VIDEOINFO_PAGE:
        {
            CrLogI("load the videoinfo page.");
            lv_label_set_text(guider_ui.video_information_label_10,video_file_list[videolist_clientnum].name);

            //时间
            time_t timesteamp = atol(video_file_list[videolist_clientnum].print_time);
            struct tm *CurTime = localtime(&timesteamp);
            char timepath[512] = {0};
            snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d_%02d:%02d",
                        CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
                        CurTime->tm_hour, CurTime->tm_min);
            lv_label_set_text(guider_ui.video_information_label_11, timepath);

            char temp[30] = {0};
            snprintf(temp,30,"%.1fh",atoi(video_file_list[videolist_clientnum].length_of_time)/3600.0);
            lv_label_set_text(guider_ui.video_information_label_12, temp);

            if(video_file_list[videolist_clientnum].photo_position[0] == '1')
                lv_label_set_text(guider_ui.video_information_label_13, "移开喷头");
            else
                lv_label_set_text(guider_ui.video_information_label_13, "打印机起始点");

            char temp2[30] = {0};
            snprintf(temp2,30,"每%s层拍摄一次",video_file_list[videolist_clientnum].photo_freq);
            lv_label_set_text(guider_ui.video_information_label_14, temp2);

            char temp3[30] = {0};
            snprintf(temp3,30,"%s帧",video_file_list[videolist_clientnum].render_mode);
            lv_label_set_text(guider_ui.video_information_label_15, temp3);

            lv_img_set_src(guider_ui.video_information_img_2,video_file_list[videolist_clientnum].photo);
            break;
        }
        default:
            break;
    }
}

void handle_file()
{
    print_file_ok = false;
    unsigned int itemp;
    char myper[FILE_NUM_SIZE + FILE_NUM_SIZE + 10] = "11\t001000";

    snprintf(&myper[3], FILE_NUM_SIZE+1, "%03d", (current_page * FILE_NUM_PRE_PAGE) + 1);
    if(((current_page + 1) * FILE_NUM_PRE_PAGE) > print_total_files)
    {
        itemp = print_total_files;
    }
    else
    {
        itemp =  (current_page + 1) * FILE_NUM_PRE_PAGE;
    }

    if(print_total_files)
    {
        snprintf(&myper[FILE_NUM_SIZE + 4], FILE_NUM_SIZE+1, "%03d", itemp);
        myper[6] = '\t';
        get_printer_data(0x01, FILE_NUM_SIZE+FILE_NUM_SIZE+10, myper);
    }
    else
    {
        print_file_ok = true;
    }
}

void handle_history_file()
{
    unsigned int itemp;
    char myper[FILE_NUM_SIZE + FILE_NUM_SIZE + 10] = "21\t001000";

    snprintf(&myper[3], FILE_NUM_SIZE+1, "%03d", (history_current_page * HISTORY_NUM_PRE_PAGE) + 1);
    if(((history_current_page + 1) * HISTORY_NUM_PRE_PAGE) > history_total_files)
    {
        itemp = history_total_files;
    }
    else
    {
        itemp =  (history_current_page + 1) * HISTORY_NUM_PRE_PAGE;
    }
    if(history_total_files)
    {
        snprintf(&myper[FILE_NUM_SIZE + 4], FILE_NUM_SIZE+1, "%03d", itemp);
        myper[6] = '\t';
        get_printer_data(0x01, FILE_NUM_SIZE+FILE_NUM_SIZE+10, myper);
    }
}

void handle_video_file()
{
    unsigned int itemp;
    char myper[FILE_NUM_SIZE + FILE_NUM_SIZE + 10] = {0};

    if(((videolist_current_page + 1) * VIDEO_NUM_PRE_PAGE) > videolist_total_files)
    {
        itemp = videolist_total_files;
    }
    else
    {
        itemp =  (videolist_current_page + 1) * VIDEO_NUM_PRE_PAGE;
    }
    snprintf(myper, FILE_NUM_SIZE + FILE_NUM_SIZE + 10, "31\t%03d\t%03d", (videolist_current_page * VIDEO_NUM_PRE_PAGE) + 1,itemp);
    CrLogI("get the videolist:%s",myper);
    get_printer_data(0x01, FILE_NUM_SIZE+FILE_NUM_SIZE+4, myper);
}

lv_timer_t * plugin_material_task;
bool check_time(void)
{
	if((lv_tick_get() - tick_start) < CLICK_DIFF)
		return true;
	else
		return false;
}

void stack_input(int scr_id,unsigned char shield,unsigned char nums,char *cur_dt,int nmin,int nmax)
{
	pre_scr = scr_id;
	shield_input_bit = shield;
	input_number_bit = nums;
	cur_data = cur_dt;
	input_min = nmin;
	input_max = nmax;
}

void handle_input(char chr)
{
//	if(check_time())
//        return;
//    int tint;
//	char *src = lv_label_get_text(guider_ui.inputboard_label_2);
//	unsigned char len = 0;
//	bool dot_flag = false;
//	while(*src != '\0')
//	{
//		if(*src == '.')
//		{
//			dot_flag = true;
//		}
//		input_str[len++] = *src++;
//	}
//	switch(chr)
//	{
//		case '1':
//		case '2':
//		case '3':
//		case '4':
//		case '5':
//		case '6':
//		case '7':
//		case '8':
//		case '9':
//			if(len < input_number_bit)
//			{
//			    if((input_str[0] == '0') && (len == 1))
//                {
//                    input_str[0] = chr;
//			    }
//			    else
//                {
//                    input_str[len] = chr;
//                }
//			}
//			break;
//		case '0':
////			if((len != 0) && (len < input_number_bit))
//			if(len < input_number_bit)
//			{
//				input_str[len] = chr;
//			}
//			break;
//		case '-':
//			if(len == 0)
//			{
//				input_str[len] = chr;
//			}
//			break;
//		case '.':
//			if(!dot_flag)
//			{
//				if(len == 0)
//				{
//					input_str[len++] = '0';
//				}
//				input_str[len] = chr;
//				dot_flag = true;
//			}
//			break;
//		case 'b':
//			if(len > 0)
//			{
//				input_str[--len] = '\0';
//			}
//			break;
//		case 'c':
//			guider_load_screen(pre_scr);
//			break;
//		case 's':
//		    tint = atoi(input_str);
//            if((tint > input_max) || (tint < input_min))
//            {
//                mymsgbox("输入的数据超出范围,请重新输入");
//            }
//		    else if(input_str[0] != '\0')
//            {
//                for(unsigned char i=0; i<input_number_bit; i++)
//                {
//                    cur_data[i] = input_str[i];
//                }
//                input_win_flag = true;
//                guider_load_screen(pre_scr);
//            }
//			break;
//		default:
//			break;
//	}
//    if((chr != 'c') && (chr != 's'))
//    {
//        lv_label_set_text(guider_ui.inputboard_label_2, &input_str[0]);
//    }
}

void data_init(void)
{

}

void custom_init(lv_ui *ui)
{
	data_init();
	mystyle_init();

//1、将当前的屏幕标志量设为默认
	cur_scr = 0xff;

//2、生成所有的界面ui，并设为隐藏
    setup_scr_homepage(ui);
    setup_scr_axismove(ui);
    setup_scr_file_management(ui);
    setup_scr_FAQ(ui);
    setup_scr_settings(ui);
    setup_scr_selftest(ui);
    setup_scr_keytone_setting(ui);
    setup_scr_device_binding(ui);
    setup_scr_export_log(ui);
    setup_scr_about_device(ui);
    setup_scr_resetdevide(ui);
    setup_scr_inputboard_wifi(ui);
    setup_scr_select_language(ui);
    setup_scr_file_information(ui);
    setup_scr_change_printstate(ui);
    setup_scr_netwowork_information(ui);
    setup_scr_update_version(ui);
    setup_scr_printing_adjust(ui);
    setup_scr_video_list(ui);
    setup_scr_video_information(ui);
    setup_scr_camera_seting(ui);
    setup_scr_fullscreen_mode(ui);
    setup_scr_messagebox(ui);
    setup_scr_sleep_mode(ui);
    setup_scr_printmessage(ui);
    setup_scr_wait(ui);

    lv_obj_add_flag(guider_ui.homepage_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.axismove_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.file_management_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.FAQ_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.settings_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.selftest_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.keytone_setting_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.device_binding_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.export_log_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.about_device_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.resetdevide_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.select_language_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.inputboard_wifi_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.file_information_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.change_printstate_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.netwowork_information_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.update_version_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.printing_adjust_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.video_list_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.video_information_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.camera_seting_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.fullscreen_mode_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.messagebox_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.sleep_mode_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.printmessage_cont_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.wait_cont_1, LV_OBJ_FLAG_HIDDEN);

//3、进行主界面数据初始化
    get_printer_data(0x03, 1, "\0");    //温度更新
    get_printer_data(0x10, 1, "\0");    //打印速率更新
    if(selftestflag)
        guider_load_screen(SCR_SELFTEST_PAGE);
    else
        guider_load_screen(SCR_HOME_PAGE);
}

void set_screen_vertical(bool flag)
{
    screen_rotate = flag;
}
void UI_Init(UIInit_t init_ui)
{
    selftestflag = init_ui.SelftestFlag;
    screen_rotate = init_ui.direction;
    UIType = init_ui.MachineType;
    if(UIType == K1_Max_SE)
    {
        UIType = CR_K1_Max;
        IsK1MaxSe = true;
    }
    else if(UIType == K1C)//K1C的UI与K1保持一致
    {
        UIType = CR_K1;
        IsK1C = true;
    }
    CheckUpdataFlag = init_ui.CheckUpdateFlag;

    init_uiconfiginfo.SelftestFlag        = init_ui.SelftestFlag;
    init_uiconfiginfo.AgreePrivacyPolicy  = init_ui.AgreePrivacyPolicy;
    init_uiconfiginfo.CheckUpdateFlag     = init_ui.CheckUpdateFlag;
    init_uiconfiginfo.direction           = init_ui.direction;
    init_uiconfiginfo.MachineType         = init_ui.MachineType;
    init_uiconfiginfo.ServerOption        = init_ui.ServerOption;
    init_uiconfiginfo.ZAxisForwardMoveDir = init_ui.ZAxisForwardMoveDir;

    switch (UIType)
    {
    case CR_10_H1:{
        setup_ui(&guider_ui);
        events_init(&guider_ui);
        custom_init(&guider_ui);
        break;
    }
    case CR_K1:{
	    mystyle_init();
        ui_init(init_ui);
        break;
    }
    case CR_K1_Max:{
	    mystyle_init();
        ui_init(init_ui);
        break;
    }
    default://默认启动横屏UI
	    mystyle_init();
        ui_init(init_ui);
        break;
    }
    //打开屏幕背光，防止出现息屏情况下显示进程重启的情况，背光无法打开
    CrLogI("UI init open the screen light");
    set_printer_data(CONTROL_MACHINE_STATE,1,"2");
}

/**
 * @description: 判断是否在产测模式
 * @return {*}
 */
bool isFactoryTest(void)
{
    if (access(GetDevelopFactoryTestPtah(), F_OK) == 0) return true;
    else return false;
}
/**
 * @description: 判断是否在产测模式
 * @return {*}
 */
bool isMachineTest(void)
{
    if (access(GetDevelopMachineTestPtah(), F_OK) == 0) return true;
    else return false;
}
