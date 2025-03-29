/*
 * @Author: Fang JinLun 
 * @Date: 2023-04-23 11:49:55 
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-06-09 11:25:43
 */

#include "ui_Screen_MachineTest.h"
#include "ui_Screen_LaserTest.h"
#include "ui_Screen_LaserFlowDetectTest.h"
#include "ui_Screen_MachineMcuVersion.h"
#include "ui_Screen_LaserPressureTest.h"
#include "ui_Screen_MachineScanGunSnNum.h"


#define DELETE_FILE_CMD     "rm"

static char* laser_test_text = "激光雷达测试";
static char* laser_flow_test_text = "流量检测测试";
static char* laser_pressure_test_text = "激光压力测试";
static char* mcu_version_text = "MCU版本";
static char* reset_text = "退出整机测试";
static char* delete_user_data_text = "删除使用记录";
static char* scan_sn_text = "SN号录入";
static char* delete_success_text = "删除成功";
static char* delete_fail_text = "删除失败";

static lv_obj_t* mt_obj;
static lv_obj_t* scroll_obj;
static lv_obj_t* laser_test_btn;
static lv_obj_t* laser_test_label;
static lv_obj_t* laser_flow_test_btn;
static lv_obj_t* laser_flow_test_label;
static lv_obj_t* reset_btn;
static lv_obj_t* reset_label;
static lv_obj_t* laser_pressure_test_btn;
static lv_obj_t* laser_pressure_test_label;
static lv_obj_t* mcu_version_btn;
static lv_obj_t* mcu_version_label;
static lv_obj_t* delete_user_data_btn;
static lv_obj_t* delete_user_data_label;
static lv_obj_t* scan_sn_num_btn;
static lv_obj_t* scan_sn_num_label;

static lv_obj_t *add_label(lv_obj_t *parents, char *text, lv_font_t *font, lv_color_t color, lv_align_t align,
                                      lv_obj_t *align_to_obj, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
    lv_obj_t *label = lv_label_create(parents);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(label, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align_to(label, align_to_obj, align, x_ofs, y_ofs);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    return label;
}

static void laser_test_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        ui_laser_test_init(mt_obj);
    }
}

static void laser_flow_test_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        ui_laser_flow_test_init(mt_obj);
    }
}

static void laser_pressure_test_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        ui_laser_pressure_test_init(mt_obj);
    }
}

static void mcu_version_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        ui_machine_mcu_version_init(mt_obj);
    }
}

static void delete_user_data_file_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        char cmd[256]={0};
        char resBuf[256]={0};
        snprintf(cmd,sizeof(cmd),"%s %s",DELETE_FILE_CMD,GetUserDataNotDeleteFilePtah());
        if (!PopenSystem(cmd, resBuf, sizeof(resBuf))){
            CrLogW("delete user data file fail !!\n");
            create_msgbox(delete_fail_text, NULL, 1000 * 1, lv_scr_act());
        }else{
            CrLogI("delete user data file success !!\n");
            create_msgbox(delete_success_text, NULL, 1000 * 1, lv_scr_act());
        }
    }
}
static void scan_sn_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        ui_machine_scan_gun_sn_screen_init(mt_obj);
    }
}
void ui_load_machinetestScreen(void)
{
    if (mt_obj)
        lv_disp_load_scr(mt_obj);
}

static void reset_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        //发送指令给master终止正在执行的线程
        char buf[64]={0};
        snprintf(buf,sizeof(buf),"%d",6);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_SET_LASER_TEST_START_REQ, buf, sizeof(buf));
        SendProcessMsgBuff(&send, size);
        DisFactoryTestControl(MACHINE_TEST_STOP);
    }
}
 

void ui_machine_test_init(void)
{
    CrLogI("ui_machine_test_init");
    int i = 0;
    mt_obj = lv_obj_create(NULL);
    lv_obj_set_size(mt_obj,800,480);
    lv_obj_clear_flag(mt_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(mt_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(mt_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(mt_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(mt_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(mt_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_flex_flow(mt_obj, LV_FLEX_FLOW_ROW_WRAP);
    // lv_obj_set_style_flex_main_place(mt_obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_row(mt_obj, 40, 0);
    // lv_obj_set_style_pad_column(mt_obj, 15, 0);
    // lv_obj_set_style_layout(mt_obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(mt_obj, LV_ALIGN_CENTER, 0, 0);

    scroll_obj = lv_obj_create(mt_obj);
    lv_obj_set_size(scroll_obj,800,420);
    lv_obj_set_style_bg_color(scroll_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(scroll_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(scroll_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(scroll_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(scroll_obj,60,LV_PART_MAIN);
    lv_obj_set_style_pad_left(scroll_obj,38,LV_PART_MAIN);
    lv_obj_set_style_border_width(scroll_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(scroll_obj, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_style_flex_main_place(scroll_obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(scroll_obj, 40, 0);
    lv_obj_set_style_pad_column(scroll_obj, 30, 0);
    lv_obj_set_style_layout(scroll_obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(scroll_obj, LV_ALIGN_TOP_MID, 0, 0);

    laser_test_btn = lv_btn_create(scroll_obj);
    lv_obj_set_size(laser_test_btn, 160, 60);
    lv_obj_align_to(laser_test_btn, scroll_obj, LV_ALIGN_CENTER, 0,0);
    lv_obj_add_flag(laser_test_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(laser_test_btn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(laser_test_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(laser_test_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_test_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(laser_test_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(laser_test_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(laser_test_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_test_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(laser_test_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(laser_test_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    laser_test_label = add_label(laser_test_btn, laser_test_text, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, laser_test_btn, 0, 0);
    laser_flow_test_btn = lv_btn_create(scroll_obj);
    lv_obj_set_size(laser_flow_test_btn, 160, 60);
    lv_obj_align_to(laser_flow_test_btn, scroll_obj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(laser_flow_test_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(laser_flow_test_btn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(laser_flow_test_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(laser_flow_test_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_flow_test_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(laser_flow_test_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(laser_flow_test_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(laser_flow_test_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_flow_test_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(laser_flow_test_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(laser_flow_test_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_align_to(laser_flow_test_btn,laser_test_btn,LV_ALIGN_OUT_TOP_MID,0,-60);
    laser_flow_test_label = add_label(laser_flow_test_btn, laser_flow_test_text, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, laser_flow_test_btn, 0, 0);

    mcu_version_btn = lv_btn_create(scroll_obj);
    lv_obj_set_size(mcu_version_btn, 160, 60);
    lv_obj_align_to(mcu_version_btn, scroll_obj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(mcu_version_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(mcu_version_btn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(mcu_version_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(mcu_version_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(mcu_version_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(mcu_version_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(mcu_version_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(mcu_version_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(mcu_version_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(mcu_version_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(mcu_version_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_align_to(mcu_version_btn,laser_test_btn,LV_ALIGN_OUT_RIGHT_MID,80,0);
    mcu_version_label = add_label(mcu_version_btn, mcu_version_text, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, mcu_version_btn, 0, 0);

    laser_pressure_test_btn = lv_btn_create(scroll_obj);
    lv_obj_set_size(laser_pressure_test_btn, 160, 60);
    lv_obj_align_to(laser_pressure_test_btn, scroll_obj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(laser_pressure_test_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(laser_pressure_test_btn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(laser_pressure_test_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(laser_pressure_test_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_pressure_test_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(laser_pressure_test_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(laser_pressure_test_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(laser_pressure_test_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_pressure_test_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(laser_pressure_test_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(laser_pressure_test_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_align_to(laser_pressure_test_btn,laser_test_btn,LV_ALIGN_OUT_LEFT_MID,-80,0);
    laser_pressure_test_label = add_label(laser_pressure_test_btn, laser_pressure_test_text, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, laser_pressure_test_btn, 0, 0);

    delete_user_data_btn = lv_btn_create(scroll_obj);
    lv_obj_set_size(delete_user_data_btn, 160, 60);
    lv_obj_align_to(delete_user_data_btn, scroll_obj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(delete_user_data_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(delete_user_data_btn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(delete_user_data_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(delete_user_data_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(delete_user_data_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(delete_user_data_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(delete_user_data_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(delete_user_data_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(delete_user_data_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(delete_user_data_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(delete_user_data_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_align_to(delete_user_data_btn,laser_test_btn,LV_ALIGN_OUT_LEFT_MID,-80,-60);
    delete_user_data_label = add_label(delete_user_data_btn, delete_user_data_text, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, delete_user_data_btn, 0, 0);

    scan_sn_num_btn = lv_btn_create(scroll_obj);
    lv_obj_set_size(scan_sn_num_btn, 160, 60);
    lv_obj_align_to(scan_sn_num_btn, scroll_obj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(scan_sn_num_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(scan_sn_num_btn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(scan_sn_num_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(scan_sn_num_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(scan_sn_num_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(scan_sn_num_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(scan_sn_num_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(scan_sn_num_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(scan_sn_num_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(scan_sn_num_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(scan_sn_num_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_align_to(scan_sn_num_btn,laser_test_btn,LV_ALIGN_OUT_LEFT_MID,-80,-60);
    scan_sn_num_label = add_label(scan_sn_num_btn, scan_sn_text, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, scan_sn_num_btn, 0, 0);

    reset_btn = lv_btn_create(mt_obj);
    lv_obj_set_size(reset_btn, 160, 60);
    lv_obj_align_to(reset_btn, mt_obj, LV_ALIGN_BOTTOM_MID, 0, -10);
    lv_obj_add_flag(reset_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(reset_btn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(reset_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(reset_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(reset_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(reset_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(reset_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(reset_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(reset_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(reset_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(reset_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    reset_label = add_label(reset_btn, reset_text, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, reset_btn, 0, 0);

    lv_obj_add_event_cb(laser_test_btn,laser_test_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(laser_flow_test_btn,laser_flow_test_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(mcu_version_btn,mcu_version_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(laser_pressure_test_btn,laser_pressure_test_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(delete_user_data_btn,delete_user_data_file_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(scan_sn_num_btn,scan_sn_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(reset_btn,reset_btn_event_cb,LV_EVENT_CLICKED,NULL);
    
    
}