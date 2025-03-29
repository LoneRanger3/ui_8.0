/*
 * @Author: Fang JinLun 
 * @Date: 2023-06-01 20:00:14 
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-06-09 16:01:01
 */

#include "ui_Screen_LaserFlowDetectTest.h"
#include "src/core/lv_obj_pos.h"

static char* startText="开始";
static char* flowResultText="检测结果";
static char* flowResult1Text="1: ";
static char* flowResult2Text="2: ";
static char* flowResult3Text="3: ";
static char* flowResult4Text="4: ";
static char* flowResult5Text="5: ";
static char* returnText="返回";

static lv_obj_t *flow_test_obj;
static lv_obj_t *laser_flow_start_btn;
static lv_obj_t *laser_flow_start_label;
static lv_obj_t *return_btn;
static lv_obj_t *return_label; 
static lv_obj_t *result_label; 
static lv_obj_t *result1_label;
static lv_obj_t *result2_label;
static lv_obj_t *result3_label;
static lv_obj_t *result4_label;
static lv_obj_t *result5_label;

#define MAX_TEST_COUNT 5

void flow_test_show_result(int num,char *result)
{
    if(!flow_test_obj || num > MAX_TEST_COUNT || num < 0){
        return;
    }

    switch(num)
    {
    case 0:
        lv_label_set_text_fmt(result1_label,"1: %s",result);
        break;
    case 1:
        lv_label_set_text_fmt(result2_label,"2: %s",result);
        break;
    case 2:
        lv_label_set_text_fmt(result3_label,"3: %s",result);
        break;
    case 3:
        lv_label_set_text_fmt(result4_label,"4: %s",result);
        break;
    case 4:
        lv_label_set_text_fmt(result5_label,"5: %s",result);
        break;
    }
}


static void start_laser_test_cmd(int step)
{   
    DisStartLaserTest(step);
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

static void laser_cali_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        set_printer_data(0x1b, 1, "a");
    }
}


static void laser_flow_test_start_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
#ifdef CROSS_COMPILE
        if(system_state.Laser_state == 0)
        {
            create_msgbox(NoLaser[get_cur_language_index()], NULL, 1000 * 1, lv_scr_act());
            return;
        }
#endif
        if(flow_test_obj){
            lv_label_set_text(result1_label,"1: ");
            lv_label_set_text(result2_label,"2: ");
            lv_label_set_text(result3_label,"3: ");
            lv_label_set_text(result4_label,"4: ");
            lv_label_set_text(result5_label,"5: ");
        }
        CrLogI("laser flow test start\n");
        start_laser_test_cmd(5);
    }
}


static void return_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        CrLogI("return\n");
        if(flow_test_obj){
            CrLogI("laser test close laser\n");
            start_laser_test_cmd(4);
            lv_obj_del_async(flow_test_obj);
            flow_test_obj=NULL;
            LoadMachinetestScreen();
        }    
    }
}



void ui_laser_flow_test_init(lv_obj_t* parents) 
{
    CrLogI("ui_laser_flow_test_init\n");

    get_printer_data(CONTROL_MACHINE_STATE, 2, "a");    //获取轮廓仪状态

    flow_test_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(flow_test_obj, 640, 360);
    lv_obj_set_pos(flow_test_obj, 0, 60);
    lv_obj_clear_flag(flow_test_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(flow_test_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(flow_test_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(flow_test_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(flow_test_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(flow_test_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  
    
    //第一步开始按钮
    laser_flow_start_btn = lv_btn_create(flow_test_obj);
    lv_obj_set_size(laser_flow_start_btn, 130, 50);
    lv_obj_align_to(laser_flow_start_btn, flow_test_obj, LV_ALIGN_TOP_LEFT, 20, 225);
    lv_obj_add_flag(laser_flow_start_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_set_style_radius(laser_flow_start_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(laser_flow_start_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_flow_start_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(laser_flow_start_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(laser_flow_start_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(laser_flow_start_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_flow_start_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(laser_flow_start_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(laser_flow_start_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_flow_start_btn, lv_color_hex(0xB0F1FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_opa(laser_flow_start_btn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(laser_flow_start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(laser_flow_start_btn, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_spread(laser_flow_start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(laser_flow_start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(laser_flow_start_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(laser_flow_start_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    laser_flow_start_label = add_label(laser_flow_start_btn, startText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, laser_flow_start_btn, 0, 0);

    //返回按钮
    return_btn = lv_btn_create(flow_test_obj);
    lv_obj_set_size(return_btn, 130, 50);
    lv_obj_align_to(return_btn, flow_test_obj, LV_ALIGN_TOP_LEFT, 20, 100);
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

    result_label = add_label(flow_test_obj, flowResultText, lv_font28.font, lv_color_white(),
                                        LV_ALIGN_TOP_RIGHT, flow_test_obj, -230, 50);
    lv_obj_set_size(result_label,200,80);     

    result1_label = add_label(flow_test_obj, flowResult1Text, lv_font28.font, lv_color_white(),
                                        LV_ALIGN_TOP_RIGHT, flow_test_obj, -400, 100);
    lv_obj_set_size(result_label,200,80);
    lv_obj_set_style_text_align(result1_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

         
    result2_label = add_label(flow_test_obj, flowResult2Text, lv_font28.font, lv_color_white(),
                                        LV_ALIGN_OUT_BOTTOM_MID, result1_label, 0, 30);
    lv_obj_set_size(result_label,200,80);     
    lv_obj_set_style_text_align(result2_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    result3_label = add_label(flow_test_obj, flowResult3Text, lv_font28.font, lv_color_white(),
                                        LV_ALIGN_OUT_BOTTOM_MID, result2_label, 0, 30);
    lv_obj_set_size(result_label,200,80);     
    lv_obj_set_style_text_align(result3_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    result4_label = add_label(flow_test_obj, flowResult4Text, lv_font28.font, lv_color_white(),
                                        LV_ALIGN_OUT_BOTTOM_MID, result3_label, 0, 30);
    lv_obj_set_size(result_label,200,80);   
    lv_obj_set_style_text_align(result4_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    result5_label = add_label(flow_test_obj, flowResult5Text, lv_font28.font, lv_color_white(),
                                        LV_ALIGN_OUT_BOTTOM_MID, result4_label, 0,30);
    lv_obj_set_size(result_label,200,80);                             
    lv_obj_set_style_text_align(result5_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(laser_flow_start_btn,laser_flow_test_start_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(return_btn,return_btn_event_cb,LV_EVENT_CLICKED,NULL);
}

void LaserFloeDetectTestAddObjToGroup(void)
{
    lv_group_add_obj(encoder_group, return_btn);
    lv_group_add_obj(encoder_group, laser_flow_start_btn);
}

