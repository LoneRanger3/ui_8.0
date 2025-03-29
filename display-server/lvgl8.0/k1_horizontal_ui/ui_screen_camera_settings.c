/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-08 11:17:29
 * @LastEditTime: 2023-02-02 14:13:48
 */
#include "ui_screen_camera_settings.h"
#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>
#include "ui_Screen_Settings.h"
#include "ui_custom_numbers_keys.h"
#include "ui_screen_HomeNormal.h"
#include "mult_language.h"

/*****************lvgl variable**************************/
lv_obj_t * ui_camerasetting;
static lv_obj_t * ui_NavigationBar;
static lv_obj_t * ui_Screen1_Image30;
static lv_obj_t * ui_Screen1_Image31;
static lv_obj_t * ui_Screen1_Image32;
static lv_obj_t * ui_Screen1_Image33;
static lv_obj_t * ui_Screen1_Image34;

static lv_obj_t * ui_bacground1;
static lv_obj_t * ui_bacground2;
static lv_obj_t * ui_title;
static lv_obj_t * ui_Screen2_Label4;
static lv_obj_t * ui_Button_Back_Setting_Screen;
static lv_obj_t * ui_Screen5_Label5;
static lv_obj_t * ui_label_delayed_photography;

static lv_obj_t * ui_switch_delayed_photography;
static lv_obj_t * ui_Screen2_Label6;
static lv_obj_t * ui_Screen2_Label7;
static lv_obj_t * ui_Screen2_Label8;
//static lv_obj_t * ui_Label_Shoot_Pos;
static lv_obj_t * ui_Dropdown_Shoot_Pos;
static lv_obj_t * ui_Label_Shoot_Freq;
static lv_obj_t * ui_Dropdown_Render_Method;


/*****************custom variable**************************/
#define MAX_RENDER_METHOD 2
static bool delayed_photography_opened = false;
static char *render_method_opt_name[MAX_RENDER_METHOD] = {"MP4-15", "MP4-25"};
static int16_t render_method_opt_value[MAX_RENDER_METHOD] = {15, 25};
static char *shoot_pos_opt_name[2] = {"每层起始位置", "喷头移开时"};
//static char *shoot_pos_opt_name[2] = {"move hotend", "not move hotend"};
static char  shoot_pos_opt_value[2] = {'0','1'};  //根据协议而来

/*****************lvgl funs**************************/
static void ui_event_Button_Back_Clicked(lv_event_t * e);
static void ui_event_Switch_Delayed_photography_Clicked(lv_event_t * e);
static void ui_event_label_shoot_freq_clicked(lv_event_t * e);
static void ui_event_dropdown_render_method_clicked(lv_event_t * e);
static void ui_event_dropdown_shoot_pos_changed(lv_event_t *e);

/*****************custom funs**************************/
static void confirm_btn_call_back(void * param);
static void delayed_photography(lv_event_t * e);
static void edit_shoot_freq(lv_event_t * e);


/******************************************************/

void ui_event_Button_Back_Clicked(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_Switch_Delayed_photography_Clicked(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        delayed_photography(e);
    }
}

void ui_event_label_shoot_freq_clicked(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        edit_shoot_freq(e);
    }
}

void ui_event_camerea_pageload(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load camerasetting page.");
        //暂时屏蔽延时摄影设置选项
        lv_obj_add_flag(ui_Screen2_Label6, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Dropdown_Shoot_Pos, LV_OBJ_FLAG_HIDDEN);
    }
}

void ui_event_camera_changepage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(target == ui_Screen1_Image30)
        {
            if ( home_printing_is_printing_finished() )
                LoadHomeNormalScreen();
            else
                LoadHomePrintingScreen();
        }
        if(target == ui_Screen1_Image31)LoadAxisMoveScreen();
        if(target == ui_Screen1_Image32)LoadFileManageScreen();
        if(target == ui_Screen1_Image33)LoadSettingsScreen();
        if(target == ui_Screen1_Image34)LoadCustomerServiceScreen();
    }
}
void ui_event_dropdown_render_method_clicked(lv_event_t * e)
{
        lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_READY) 
    {
        lv_obj_t *list_method = lv_dropdown_get_list(ui_Dropdown_Render_Method);
        if ( !list_method )
            return;
            
        lv_obj_set_style_text_color(list_method, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(list_method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(list_method, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(list_method, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(list_method, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(list_method, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(list_method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(list_method, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(list_method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(list_method, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        
        lv_obj_set_style_bg_color(list_method, lv_color_hex(0x42BDD8), LV_PART_SELECTED | LV_STATE_PRESSED);
        lv_obj_set_style_bg_opa(list_method, 255, LV_PART_SELECTED | LV_STATE_PRESSED);
    }
    else if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        // CrLogI("---------------------- call ui_event_dropdown_render_method_clicked");
        int index = lv_dropdown_get_selected(ui_Dropdown_Render_Method);
        if ( index >= 0 && index < MAX_RENDER_METHOD )
        {
            send_set_camera_render_method_photoes(render_method_opt_value[index]);
            send_get_camera_render_method_photoes();
        }
    }
}

void ui_event_dropdown_shoot_pos_changed(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_READY) 
    {
        lv_obj_t *list_shoot_pos = lv_dropdown_get_list(ui_Dropdown_Shoot_Pos);
        if ( !list_shoot_pos )
            return;

        lv_obj_set_style_text_color(list_shoot_pos, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(list_shoot_pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(list_shoot_pos, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(list_shoot_pos, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(list_shoot_pos, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(list_shoot_pos, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(list_shoot_pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(list_shoot_pos, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(list_shoot_pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(list_shoot_pos, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_set_style_bg_color(list_shoot_pos, lv_color_hex(0x42BDD8), LV_PART_SELECTED | LV_STATE_PRESSED);
        lv_obj_set_style_bg_opa(list_shoot_pos, 255, LV_PART_SELECTED | LV_STATE_PRESSED);
    }
    else if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int index = lv_dropdown_get_selected(ui_Dropdown_Shoot_Pos);
        //CrLogI("---------------------- ui_event_dropdown_shoot_pos_changed index %d", index);
        if ( index >= 0 && index < 2 )
        {
            send_set_camera_shoot_pos(shoot_pos_opt_value[index]);
            send_get_camera_shoot_pos();
        }
    }
    

  

}


///////////////////// SCREENS ////////////////////
void ui_camerasetting_screen_init(void)
{
    ui_camerasetting = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_camerasetting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    char buff[40] = {0};

    ui_NavigationBar = lv_obj_create(ui_camerasetting);
    lv_obj_set_width(ui_NavigationBar, 80);
    lv_obj_set_height(ui_NavigationBar, 480);
    lv_obj_clear_flag(ui_NavigationBar, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NavigationBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NavigationBar, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NavigationBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NavigationBar, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NavigationBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NavigationBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NavigationBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NavigationBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NavigationBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NavigationBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image30 = lv_img_create(ui_NavigationBar);
    lv_img_set_src(ui_Screen1_Image30, &ui_img_pagehome_png);
    lv_obj_set_width(ui_Screen1_Image30, 80);
    lv_obj_set_height(ui_Screen1_Image30, 96);
    lv_obj_add_flag(ui_Screen1_Image30, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image30, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Image30, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image31 = lv_img_create(ui_NavigationBar);
    lv_img_set_src(ui_Screen1_Image31, &ui_img_pagemove_png);
    lv_obj_set_width(ui_Screen1_Image31, 80);
    lv_obj_set_height(ui_Screen1_Image31, 96);
    lv_obj_set_x(ui_Screen1_Image31, 0);
    lv_obj_set_y(ui_Screen1_Image31, 96);
    lv_obj_add_flag(ui_Screen1_Image31, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image31, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Image31, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Image31, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image32 = lv_img_create(ui_NavigationBar);
    lv_img_set_src(ui_Screen1_Image32, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_Screen1_Image32, 80);
    lv_obj_set_height(ui_Screen1_Image32, 96);
    lv_obj_set_x(ui_Screen1_Image32, 0);
    lv_obj_set_y(ui_Screen1_Image32, 192);
    lv_obj_add_flag(ui_Screen1_Image32, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image32, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Image32, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Image32, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image33 = lv_img_create(ui_NavigationBar);
    lv_img_set_src(ui_Screen1_Image33, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_Screen1_Image33, 80);
    lv_obj_set_height(ui_Screen1_Image33, 96);
    lv_obj_set_x(ui_Screen1_Image33, 0);
    lv_obj_set_y(ui_Screen1_Image33, 288);
    lv_obj_add_flag(ui_Screen1_Image33, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image33, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Image33, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Image33, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image34 = lv_img_create(ui_NavigationBar);
    lv_img_set_src(ui_Screen1_Image34, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_Screen1_Image34, 80);
    lv_obj_set_height(ui_Screen1_Image34, 96);
    lv_obj_set_x(ui_Screen1_Image34, 0);
    lv_obj_set_y(ui_Screen1_Image34, 384);
    lv_obj_add_flag(ui_Screen1_Image34, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image34, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Image34, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Image34, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bacground1 = lv_obj_create(ui_camerasetting);
    lv_obj_set_width(ui_bacground1, 720);
    lv_obj_set_height(ui_bacground1, 480);
    lv_obj_set_x(ui_bacground1, 80);
    lv_obj_set_y(ui_bacground1, 0);
    lv_obj_clear_flag(ui_bacground1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bacground1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bacground1, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bacground1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_bacground1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_bacground1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bacground1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_bacground1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_bacground1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_bacground1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_bacground1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bacground2 = lv_obj_create(ui_bacground1);
    lv_obj_set_width(ui_bacground2, 696);
    lv_obj_set_height(ui_bacground2, 456);
    lv_obj_set_x(ui_bacground2, -1);
    lv_obj_set_y(ui_bacground2, 0);
    lv_obj_set_align(ui_bacground2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_bacground2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bacground2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bacground2, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bacground2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bacground2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_bacground2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_bacground2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_bacground2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_bacground2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_title = lv_obj_create(ui_bacground2);
    lv_obj_set_width(ui_title, 665);
    lv_obj_set_height(ui_title, 65);
    lv_obj_set_x(ui_title, 10);
    lv_obj_set_y(ui_title, 0);
    lv_obj_clear_flag(ui_title, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_title, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_title, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_title, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_title, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_title, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_title, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen2_Label4 = lv_label_create(ui_title);
    lv_obj_set_width(ui_Screen2_Label4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Screen2_Label4, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_Screen2_Label4, 15);
    lv_obj_set_y(ui_Screen2_Label4, 0);
    lv_obj_set_align(ui_Screen2_Label4, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Screen2_Label4, CameraSetting[language_index]);
    lv_obj_set_style_text_color(ui_Screen2_Label4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen2_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_Label4, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button_Back_Setting_Screen = lv_btn_create(ui_bacground2);
    lv_obj_set_width(ui_Button_Back_Setting_Screen, 116);
    lv_obj_set_height(ui_Button_Back_Setting_Screen, 60);
    lv_obj_set_x(ui_Button_Back_Setting_Screen, 560);
    lv_obj_set_y(ui_Button_Back_Setting_Screen, 381);
    lv_obj_add_flag(ui_Button_Back_Setting_Screen, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button_Back_Setting_Screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button_Back_Setting_Screen, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button_Back_Setting_Screen, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button_Back_Setting_Screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Button_Back_Setting_Screen, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Button_Back_Setting_Screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Button_Back_Setting_Screen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Button_Back_Setting_Screen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Button_Back_Setting_Screen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Button_Back_Setting_Screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Button_Back_Setting_Screen, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen5_Label5 = lv_label_create(ui_Button_Back_Setting_Screen);
    lv_obj_set_width(ui_Screen5_Label5, lv_pct(100));
    lv_obj_set_height(ui_Screen5_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Screen5_Label5, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_Screen5_Label5, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_Screen5_Label5, Back[language_index]);
    lv_obj_set_style_text_align(ui_Screen5_Label5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen5_Label5, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_label_delayed_photography = lv_label_create(ui_bacground2);
    lv_obj_set_width(ui_label_delayed_photography, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_label_delayed_photography, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_label_delayed_photography, 26);
    lv_obj_set_y(ui_label_delayed_photography, 90);
    lv_label_set_long_mode(ui_label_delayed_photography, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // memset(buff, 0, sizeof(buff));
    // sprintf(buff, "%s%s", EnableArray[language_index], DelayPhotograph[language_index]);
    lv_label_set_text(ui_label_delayed_photography, EnableArray[language_index]);
    lv_obj_set_style_text_color(ui_label_delayed_photography, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_label_delayed_photography, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_label_delayed_photography, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_switch_delayed_photography = lv_switch_create(ui_bacground2);
    lv_obj_set_width(ui_switch_delayed_photography, 74);
    lv_obj_set_height(ui_switch_delayed_photography, 36);
    lv_obj_set_x(ui_switch_delayed_photography, 586);
    lv_obj_set_y(ui_switch_delayed_photography, 90);
    lv_obj_set_style_radius(ui_switch_delayed_photography, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_switch_delayed_photography, lv_color_hex(0x43454A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_switch_delayed_photography, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_switch_delayed_photography, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_switch_delayed_photography, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(ui_switch_delayed_photography, 30, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_switch_delayed_photography, lv_color_hex(0x5F646C), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_switch_delayed_photography, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_switch_delayed_photography, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_switch_delayed_photography, 255, LV_PART_KNOB | LV_STATE_CHECKED);

    ui_Screen2_Label6 = lv_label_create(ui_bacground2);
    lv_obj_set_width(ui_Screen2_Label6, 300);
    lv_obj_set_height(ui_Screen2_Label6, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_Screen2_Label6, 26);
    lv_obj_set_y(ui_Screen2_Label6, 149);
    lv_label_set_long_mode(ui_Screen2_Label6, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_Screen2_Label6, ShootPosArray[language_index]);
    lv_obj_set_style_text_color(ui_Screen2_Label6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen2_Label6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_Label6, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen2_Label7 = lv_label_create(ui_bacground2);
    lv_obj_set_width(ui_Screen2_Label7, 300);
    lv_obj_set_height(ui_Screen2_Label7, 28);
    lv_obj_set_x(ui_Screen2_Label7, 26);
    lv_obj_set_y(ui_Screen2_Label7, 208);
    lv_label_set_long_mode(ui_Screen2_Label7, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_Screen2_Label7, ShootFreqArray[language_index]);
    lv_obj_set_style_text_color(ui_Screen2_Label7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen2_Label7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_Label7, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen2_Label8 = lv_label_create(ui_bacground2);
    lv_obj_set_width(ui_Screen2_Label8, 300);
    lv_obj_set_height(ui_Screen2_Label8, 28);
    lv_obj_set_x(ui_Screen2_Label8, 26);
    lv_obj_set_y(ui_Screen2_Label8, 268);
    lv_label_set_long_mode(ui_Screen2_Label8, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_Screen2_Label8, RenderArray[language_index]);
    lv_obj_set_style_text_color(ui_Screen2_Label8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen2_Label8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_Label8, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Shoot_Pos = lv_label_create(ui_bacground2);
    // lv_obj_set_width(ui_Label_Shoot_Pos, 300);
    // lv_obj_set_height(ui_Label_Shoot_Pos, 28);
    // lv_obj_set_x(ui_Label_Shoot_Pos, -44);
    // lv_obj_set_y(ui_Label_Shoot_Pos, 149);
    // lv_obj_set_align(ui_Label_Shoot_Pos, LV_ALIGN_TOP_RIGHT);
    // lv_label_set_long_mode(ui_Label_Shoot_Pos, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_Label_Shoot_Pos, "每层起始位置");
    // lv_obj_set_style_text_color(ui_Label_Shoot_Pos, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_Label_Shoot_Pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_Label_Shoot_Pos, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_Label_Shoot_Pos, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    shoot_pos_opt_name[0] = LayerStartPos[language_index];
    shoot_pos_opt_name[1] = HotendMoveAway[language_index];
    ui_Dropdown_Shoot_Pos = lv_dropdown_create(ui_bacground2);
    lv_dropdown_clear_options(ui_Dropdown_Shoot_Pos);
    for ( int j = 0; j < 2; j++ )
        lv_dropdown_add_option(ui_Dropdown_Shoot_Pos, shoot_pos_opt_name[j], j);

    lv_obj_set_width(ui_Dropdown_Shoot_Pos, 283);
    lv_obj_set_height(ui_Dropdown_Shoot_Pos, 40);
    lv_obj_set_x(ui_Dropdown_Shoot_Pos, 379);
    lv_obj_set_y(ui_Dropdown_Shoot_Pos, 149);
    lv_obj_add_flag(ui_Dropdown_Shoot_Pos, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_Dropdown_Shoot_Pos, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown_Shoot_Pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Dropdown_Shoot_Pos, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Dropdown_Shoot_Pos, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Dropdown_Shoot_Pos, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Dropdown_Shoot_Pos, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dropdown_Shoot_Pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Dropdown_Shoot_Pos, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Dropdown_Shoot_Pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dropdown_Shoot_Pos, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Dropdown_Shoot_Pos, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Dropdown_Shoot_Pos, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Dropdown_Shoot_Pos, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Dropdown_Shoot_Pos, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Dropdown_Shoot_Pos, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown_Shoot_Pos, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Dropdown_Shoot_Pos, LV_TEXT_ALIGN_LEFT, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Dropdown_Shoot_Pos, lv_font24.font, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_dropdown_set_symbol(ui_Dropdown_Shoot_Pos, &ui_img_expand_down_png);

    ui_Label_Shoot_Freq = lv_label_create(ui_bacground2);
    lv_obj_set_width(ui_Label_Shoot_Freq, 89);
    lv_obj_set_height(ui_Label_Shoot_Freq, 28);
    lv_obj_set_x(ui_Label_Shoot_Freq, -168);
    lv_obj_set_y(ui_Label_Shoot_Freq, 204);
    lv_obj_add_flag(ui_Label_Shoot_Freq, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_align(ui_Label_Shoot_Freq, LV_ALIGN_TOP_RIGHT);
    lv_label_set_long_mode(ui_Label_Shoot_Freq, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_Label_Shoot_Freq, "4");
    lv_obj_set_style_text_color(ui_Label_Shoot_Freq, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Shoot_Freq, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_Shoot_Freq, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Shoot_Freq, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Label_Shoot_Freq, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label_Shoot_Freq, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Dropdown_Render_Method = lv_dropdown_create(ui_bacground2);
    lv_dropdown_clear_options(ui_Dropdown_Render_Method);
    for ( int i = 0; i < MAX_RENDER_METHOD; i++ )
        lv_dropdown_add_option(ui_Dropdown_Render_Method, render_method_opt_name[i], i);

    lv_obj_set_width(ui_Dropdown_Render_Method, 283);
    lv_obj_set_height(ui_Dropdown_Render_Method, 40);
    lv_obj_set_x(ui_Dropdown_Render_Method, 379);
    lv_obj_set_y(ui_Dropdown_Render_Method, 268);
    lv_obj_add_flag(ui_Dropdown_Render_Method, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_Dropdown_Render_Method, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown_Render_Method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Dropdown_Render_Method, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Dropdown_Render_Method, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Dropdown_Render_Method, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Dropdown_Render_Method, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dropdown_Render_Method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Dropdown_Render_Method, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Dropdown_Render_Method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dropdown_Render_Method, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Dropdown_Render_Method, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Dropdown_Render_Method, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Dropdown_Render_Method, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Dropdown_Render_Method, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Dropdown_Render_Method, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown_Render_Method, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Dropdown_Render_Method, LV_TEXT_ALIGN_LEFT, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Dropdown_Render_Method, lv_font24.font, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_dropdown_set_symbol(ui_Dropdown_Render_Method, &ui_img_expand_down_png);


    lv_obj_add_event_cb(ui_Button_Back_Setting_Screen, ui_event_Button_Back_Clicked, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_switch_delayed_photography, ui_event_Switch_Delayed_photography_Clicked, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Label_Shoot_Freq, ui_event_label_shoot_freq_clicked, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Dropdown_Render_Method, ui_event_dropdown_render_method_clicked, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Dropdown_Shoot_Pos, ui_event_dropdown_shoot_pos_changed, LV_EVENT_ALL, NULL);

    lv_obj_add_flag(ui_Screen1_Image30, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_Screen1_Image31, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_Screen1_Image32, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_Screen1_Image33, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_Screen1_Image34, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    lv_obj_add_event_cb(ui_Screen1_Image30, ui_event_camera_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen1_Image31, ui_event_camera_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen1_Image32, ui_event_camera_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen1_Image33, ui_event_camera_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen1_Image34, ui_event_camera_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_camerasetting, ui_event_camerea_pageload, LV_EVENT_SCREEN_LOADED, NULL);
    /*****************隐藏用不到的控件************************/
    //拍照频率
    lv_obj_add_flag(ui_Screen2_Label7, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Label_Shoot_Freq, LV_OBJ_FLAG_HIDDEN);
    //渲染方式
    lv_obj_add_flag(ui_Screen2_Label8, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Dropdown_Render_Method, LV_OBJ_FLAG_HIDDEN);
    

}

void shoot_freq_confirm_btn_call_back(void * param)
{
    if ( !param )
        return;

    char *data = (char *)param;
    char *ch = strchr(data, '.');
    if ( ch )
        *ch = '\0';
        
    send_set_camera_shoot_freq(atoi(data));
    send_get_camera_shoot_freq();
}

void delayed_photography(lv_event_t * e)
{
    send_set_camera_delayed_photography(lv_obj_has_state(ui_switch_delayed_photography, LV_STATE_CHECKED));
    send_get_camera_delayed_photography();
}

void edit_shoot_freq(lv_event_t * e)
{
    char buff[40] = {0};
    sprintf(buff, "摄像频率可输入范围0-%d", MAX_SHOOT_FREQ);
    numberskeyboardinput(buff, MAX_SHOOT_FREQ, 0, &shoot_freq_confirm_btn_call_back, &key_reminder_callback, 80, 0);
}


void camera_settings_set_shoot_pos(uint8_t pos)
{
    for ( int i = 0; i < 2; i++ )
    {
        if ( pos == shoot_pos_opt_value[i]  )
        {
            if ( ui_Dropdown_Shoot_Pos )
            {
                lv_dropdown_set_selected(ui_Dropdown_Shoot_Pos, i);
                lv_dropdown_set_text(ui_Dropdown_Shoot_Pos, shoot_pos_opt_name[i]);
            }  
        }
    }
}

void camera_settings_set_shoot_freq(uint8_t freq)
{
    char buff[8] = {0};
    sprintf(buff, "%d", freq);
    if ( ui_Label_Shoot_Freq )
        lv_label_set_text(ui_Label_Shoot_Freq, buff);
}

void camera_settings_set_delayed_photography(bool opened)
{
    delayed_photography_opened = opened;
    if ( ui_switch_delayed_photography )
        delayed_photography_opened ? lv_obj_add_state(ui_switch_delayed_photography, LV_STATE_CHECKED) : \
        lv_obj_clear_state(ui_switch_delayed_photography, LV_STATE_CHECKED);
}

void camera_settings_set_rendering_method(uint8_t photoes)
{
    for ( int i = 0; i < MAX_RENDER_METHOD; i++ )
    {
        if ( photoes ==  render_method_opt_value[i] )
        {
            if ( ui_Dropdown_Render_Method )
            {
                lv_dropdown_set_selected(ui_Dropdown_Render_Method, i);
                lv_dropdown_set_text(ui_Dropdown_Render_Method, render_method_opt_name[i]);
            }  
        }  
    }
}

void camera_settigns_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    char buff[40] = {0};
    if ( ui_Screen2_Label4 )
    {
        lv_label_set_text(ui_Screen2_Label4, CameraSetting[language_index]);
    }

    if ( ui_Screen5_Label5 )
        lv_label_set_text(ui_Screen5_Label5, Back[language_index]);

    if ( ui_label_delayed_photography )
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", EnableArray[language_index], DelayPhotograph[language_index]);
        lv_label_set_text(ui_label_delayed_photography, EnableArray[language_index]);
    }

    if ( ui_Screen2_Label6 )
        lv_label_set_text(ui_Screen2_Label6, ShootPosArray[language_index]);

    if ( ui_Screen2_Label7 )
        // lv_label_set_text(ui_Screen2_Label7, ShootFreqArray[language_index]);

    if ( ui_Screen2_Label8 )
        // lv_label_set_text(ui_Screen2_Label8, RenderArray[language_index]);


    if ( ui_Dropdown_Shoot_Pos )
    {
        shoot_pos_opt_name[0] = LayerStartPos[language_index];
        shoot_pos_opt_name[1] = HotendMoveAway[language_index];
        uint8_t id = lv_dropdown_get_selected(ui_Dropdown_Shoot_Pos);
        lv_dropdown_clear_options(ui_Dropdown_Shoot_Pos);
        for ( int j = 0; j < 2; j++ )
            lv_dropdown_add_option(ui_Dropdown_Shoot_Pos, shoot_pos_opt_name[j], j);
        
        lv_dropdown_set_selected(ui_Dropdown_Shoot_Pos, id);
    }
    
}

