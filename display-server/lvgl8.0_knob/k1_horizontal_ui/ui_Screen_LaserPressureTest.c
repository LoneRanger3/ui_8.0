/*
 * @Author: Fang JinLun 
 * @Date: 2023-06-01 20:00:14 
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-06-08 15:03:30
 */

#include "ui_Screen_LaserPressureTest.h"
#include "mult_language.h"
#include "src/core/lv_obj_pos.h"

static char* startText="开始";
static char* returnText="返回";
static char* passText="成功次数：";
static char* failText="失败次数：";

static lv_obj_t *pressure_test_obj;
static lv_obj_t *start_btn;
static lv_obj_t *start_label;
static lv_obj_t *return_btn;
static lv_obj_t *return_label; 
static lv_obj_t *pass_label; 
static lv_obj_t *fail_label; 
static lv_obj_t *pass_num_label; 
static lv_obj_t *fail_num_label; 

static lv_timer_t* pressure_timer;
static int cali_pass_num=0;
static int cali_fail_num=0;

static bool test_end_flag=true;

static void set_pressure_test_end_flag(bool flag)
{
    test_end_flag=flag;
}

static void start_laser_test_cmd(int step)
{   
    DisStartLaserTest(step);
}

void set_laser_pressure_status(char* status)
{   
    if(!status)
        return;
    if(0==strncmp(status,"OK",2)){
        cali_pass_num++;
        lv_label_set_text_fmt(pass_num_label,"%d",cali_pass_num);
    }
    else if(0==strncmp(status,"NG",2)){
        cali_fail_num++;
        lv_label_set_text_fmt(fail_num_label,"%d",cali_fail_num);
        
    }else if(0==strncmp(status,"END",3)){
        set_pressure_test_end_flag(true);
    }
}


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

static void close_messagebox()
{
    selftest_messagebox_close();
}


static void pressure_timer_cb(lv_timer_t *timer)
{
    if(test_end_flag){
        start_laser_test_cmd(7);
        test_end_flag=false;
    }
    if(system_state.Laser_state == 0 || system_state.Camera_model_state == 0)
    {
        uint8_t language_index = get_cur_language_index();
        void (*btns_callback[2])(void) = {&close_messagebox};
        if(system_state.Camera_model_state == 0){
            create_selftest_messagebox(KindTips[language_index], "检测到摄像头断开", Confirm[language_index], NULL,btns_callback);
        }else {
            create_selftest_messagebox(KindTips[language_index], "检测到激光雷达断开", Confirm[language_index], NULL,btns_callback);
        }
        start_laser_test_cmd(6);
        lv_timer_pause(timer);
        lv_timer_del(timer);
        test_end_flag=true;
        pressure_timer=NULL;
    }

}

static void laser_pressure_test_start_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        if(system_state.Laser_state == 0)
        {
            create_msgbox(NoLaser[get_cur_language_index()], NULL, 1000 * 1, lv_scr_act());
            return;
        }
        if(!pressure_timer)
            pressure_timer = lv_timer_create(pressure_timer_cb, 500, NULL);
    }
}


static void return_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        CrLogI("return\n");
        start_laser_test_cmd(6);
        if(pressure_test_obj){
            if(pressure_timer){
                lv_timer_pause(pressure_timer);
                lv_timer_del(pressure_timer);
                pressure_timer=NULL;
            }
            lv_obj_del_async(pressure_test_obj);
            pressure_test_obj=NULL;
            test_end_flag=true;
            LoadMachinetestScreen();
        }    
    }
}



void ui_laser_pressure_test_init(lv_obj_t* parents) 
{
    CrLogI("ui_laser_flow_test_init\n");

    get_printer_data(CONTROL_MACHINE_STATE, 2, "a");    //获取轮廓仪状态

    pressure_test_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(pressure_test_obj, 640, 360);
    lv_obj_set_pos(pressure_test_obj, 0, 60);
    lv_obj_clear_flag(pressure_test_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(pressure_test_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(pressure_test_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(pressure_test_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(pressure_test_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(pressure_test_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  
    
    //开始按钮
    start_btn = lv_btn_create(pressure_test_obj);
    lv_obj_set_size(start_btn, 130, 50);
    lv_obj_align_to(start_btn, pressure_test_obj, LV_ALIGN_BOTTOM_LEFT, 20, -20);
    lv_obj_add_flag(start_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_set_style_radius(start_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(start_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(start_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(start_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(start_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(start_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(start_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(start_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(start_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(start_btn, lv_color_hex(0xB0F1FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_opa(start_btn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(start_btn, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_spread(start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(start_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(start_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    
    start_label = add_label(start_btn, startText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, start_btn, 0, 0);

    //返回按钮
    return_btn = lv_btn_create(pressure_test_obj);
    lv_obj_set_size(return_btn, 130, 50);
    lv_obj_align_to(return_btn, pressure_test_obj, LV_ALIGN_TOP_LEFT, 20, 20);
    lv_obj_add_flag(return_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_set_style_radius(return_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(return_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(return_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(return_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(return_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(return_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(return_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(return_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(return_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(return_btn, lv_color_hex(0xB0F1FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_opa(return_btn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(return_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(return_btn, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_spread(return_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(return_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(return_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(return_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    return_label = add_label(return_btn, returnText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, return_btn, 0, 0);

    pass_label = add_label(pressure_test_obj, passText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, pressure_test_obj, -50, -40);
    pass_num_label = add_label(pressure_test_obj, "0", lv_font25.font, lv_color_white(),
                                        LV_ALIGN_OUT_RIGHT_MID, pass_label, 20, 0);

    fail_label = add_label(pressure_test_obj, failText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_OUT_BOTTOM_MID, pass_label, 0, 40);
    fail_num_label = add_label(pressure_test_obj, "0", lv_font25.font, lv_color_white(),
                                        LV_ALIGN_OUT_RIGHT_MID, fail_label, 20, 0);

    lv_obj_add_event_cb(start_btn, laser_pressure_test_start_btn_event_cb, LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(return_btn, return_btn_event_cb, LV_EVENT_CLICKED,NULL);

}

void LaserPressureTestAddObjToGroup(void)
{
    lv_group_add_obj(encoder_group, return_btn);
    lv_group_add_obj(encoder_group, start_btn);
}