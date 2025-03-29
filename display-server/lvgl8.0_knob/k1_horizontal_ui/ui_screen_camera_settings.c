/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-08 11:17:29
 * @LastEditTime: 2023-10-23 03:27:51
 */
#include "ui_screen_camera_settings.h"
#include "src/core/lv_obj_pos.h"
#include "src/misc/lv_area.h"
#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>
#include "ui_Screen_Settings.h"
#include "ui_custom_numbers_keys.h"
#include "ui_screen_HomeNormal.h"
#include "mult_language.h"
#include "ui_custom_messagebox.h"

/*****************lvgl variable**************************/
lv_obj_t * ui_camerasetting;
static lv_obj_t * ui_NavigationBar;
static lv_obj_t * ui_Screen1_Image30;
static lv_obj_t * ui_Screen1_Image31;
static lv_obj_t * ui_Screen1_Image32;
static lv_obj_t * ui_Screen1_Image33;
static lv_obj_t * ui_Screen1_Image34;

static lv_obj_t * ui_PanelCameraSettings;
static lv_obj_t * ui_LabelTitleScreenCamera;
static lv_obj_t * ui_PanelLineScreenCamera;
static lv_obj_t * ui_ButtonBackScreenCamera;
static lv_obj_t * ui_PanelDelayedPhotography;
static lv_obj_t * ui_LabelDelayedPhotography;
static lv_obj_t * ui_SwitchDelayedPhotography;
static lv_obj_t * ui_PanelShootPos;
static lv_obj_t * ui_LabelShootPos;
static lv_obj_t * ui_ArrowImageShootPos;
static lv_obj_t * ui_LabelSelectShootPos;
static lv_obj_t * ui_Screen2_Label7;
static lv_obj_t * ui_Screen2_Label8;
//static lv_obj_t * ui_Label_Shoot_Pos;
//static lv_obj_t * ui_Dropdown_Shoot_Pos;
static lv_obj_t * ui_Screen2_Label10;
static lv_obj_t * ui_Label_Shoot_Freq;
static lv_obj_t * ui_Screen2_Label12;
static lv_obj_t * ui_Dropdown_Render_Method;


/*****************custom variable**************************/
#define MAX_RENDER_METHOD 2
static bool delayed_photography_opened = false;
static char *render_method_opt_name[MAX_RENDER_METHOD] = {"MP4-15", "MP4-25"};
static int16_t render_method_opt_value[MAX_RENDER_METHOD] = {15, 25};
static char *shoot_pos_opt_name[2] = {"每层起始位置", "喷头移开时"};
//static char *shoot_pos_opt_name[2] = {"move hotend", "not move hotend"};
static char  shoot_pos_opt_value[2] = {'0','1'};  //根据协议而来
static DialogMsgbox_t ShootPosMessage;  //拍摄位置选择对话框

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
static void ShootPosMessageAddFocusObjs(void);
static void LoadCameraSettingsScreen(void);
static void CameraSettingsPageAddFocusObjs(void);

/******************************************************/

void ui_event_Button_Back_Clicked(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
       // _ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        BackPrepage(false);
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
        //lv_obj_add_flag(ui_PanelShootPos, LV_OBJ_FLAG_HIDDEN);
       
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

#if 0
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
#endif
void ui_event_PanelShootPos(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        CrLogI("ShootPos Panel Settings.");
        ShowDialogMessagebox(&ShootPosMessage, ShootPosMessageAddFocusObjs);
    }
}

/***********************************拍照位置对话框回调处理*****************************************/
void ShootPosSettingCb(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int dat = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_set_camera_shoot_pos(shoot_pos_opt_value[dat]);
        send_get_camera_shoot_pos();
        
        HiddenDialogMessagebox(&ShootPosMessage);
        // Add3rLeveldObjsCb = NULL;
        BackPrepage(true);
     
    }
}

static void ShootPosBtnTextSetCb(lv_obj_t *label, uint8_t label_index, uint8_t language_index)
{
    switch (label_index) {
    case 0:
        
        lv_label_set_text(label, LayerStartPos[language_index]);
        break;
    case 1:
        lv_label_set_text(label, HotendMoveAway[language_index]);
        break;
    default:break;
    }    
}


///////////////////// SCREENS ////////////////////
void ui_camerasetting_screen_init(void)
{
    ui_camerasetting = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(ui_camerasetting, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_camerasetting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_camerasetting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_camerasetting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    init_pages(ui_camerasetting, CameraSettingsPageAddFocusObjs, LoadCameraSettingsScreen);

    uint8_t language_index = get_cur_language_index();
    char buff[40] = {0};

    ui_NavigationBar = lv_obj_create(ui_camerasetting);
    lv_obj_set_width(ui_NavigationBar, 68);
    lv_obj_set_height(ui_NavigationBar, 360);
    lv_obj_set_pos(ui_NavigationBar, 0, 60);
    lv_obj_clear_flag(ui_NavigationBar, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NavigationBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NavigationBar, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NavigationBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NavigationBar, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NavigationBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NavigationBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_NavigationBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image30 = lv_img_create(ui_NavigationBar);
    lv_img_set_src(ui_Screen1_Image30, &ui_img_pagehome_png);
    lv_obj_set_width(ui_Screen1_Image30, 68);
    lv_obj_set_height(ui_Screen1_Image30, 72);
    lv_obj_set_pos(ui_Screen1_Image30, 0, 0);
    lv_obj_add_flag(ui_Screen1_Image30, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image30, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Image30, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image31 = lv_img_create(ui_NavigationBar);
    lv_img_set_src(ui_Screen1_Image31, &ui_img_pagemove_png);
    lv_obj_set_width(ui_Screen1_Image31, 68);
    lv_obj_set_height(ui_Screen1_Image31, 72);
    lv_obj_set_pos(ui_Screen1_Image31, 0, 72);
    lv_obj_add_flag(ui_Screen1_Image31, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image31, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Image31, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Image31, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image32 = lv_img_create(ui_NavigationBar);
    lv_img_set_src(ui_Screen1_Image32, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_Screen1_Image32, 68);
    lv_obj_set_height(ui_Screen1_Image32, 72);
    lv_obj_set_pos(ui_Screen1_Image32, 0, 144);
    lv_obj_add_flag(ui_Screen1_Image32, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image32, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Image32, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Image32, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image33 = lv_img_create(ui_NavigationBar);
    lv_img_set_src(ui_Screen1_Image33, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_Screen1_Image33, 68);
    lv_obj_set_height(ui_Screen1_Image33, 72);
    lv_obj_set_pos(ui_Screen1_Image33, 0, 216);
    lv_obj_add_flag(ui_Screen1_Image33, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image33, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Image33, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Image33, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image34 = lv_img_create(ui_NavigationBar);
    lv_img_set_src(ui_Screen1_Image34, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_Screen1_Image34, 68);
    lv_obj_set_height(ui_Screen1_Image34, 72);
     lv_obj_set_pos(ui_Screen1_Image34, 0, 288);
    lv_obj_add_flag(ui_Screen1_Image34, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image34, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Image34, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Image34, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelCameraSettings = lv_obj_create(ui_camerasetting);
    lv_obj_set_pos(ui_PanelCameraSettings, 73, 68);
    lv_obj_set_size(ui_PanelCameraSettings, 556, 344); 
    lv_obj_clear_flag(ui_PanelCameraSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCameraSettings, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCameraSettings, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCameraSettings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCameraSettings, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelCameraSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

     ui_LabelTitleScreenCamera = lv_label_create(ui_PanelCameraSettings);
    lv_obj_set_size(ui_LabelTitleScreenCamera, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_LabelTitleScreenCamera, 16, 0);
    lv_label_set_text(ui_LabelTitleScreenCamera, AIFunction[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelTitleScreenCamera, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleScreenCamera, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTitleScreenCamera, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_PanelLineScreenCamera = lv_obj_create(ui_PanelCameraSettings);
    lv_obj_set_size(ui_PanelLineScreenCamera, 543, 1);
    lv_obj_set_pos(ui_PanelLineScreenCamera, 7, 49);
    lv_obj_clear_flag(ui_PanelLineScreenCamera, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelLineScreenCamera, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelLineScreenCamera, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLineScreenCamera, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLineScreenCamera, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_ButtonBackScreenCamera = lv_btn_create(ui_PanelCameraSettings);
    lv_obj_set_size(ui_ButtonBackScreenCamera, 68, 38);
    lv_obj_set_pos(ui_ButtonBackScreenCamera, 474, 6);
    lv_obj_add_flag(ui_ButtonBackScreenCamera, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonBackScreenCamera, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonBackScreenCamera, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonBackScreenCamera, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBackScreenCamera, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackScreenCamera, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonBackScreenCamera, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonBackScreenCamera, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonBackScreenCamera, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonBackScreenCamera, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackScreenCamera, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonBackScreenCamera, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonBackScreenCamera, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonBackScreenCamera, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ButtonBackScreenCamera, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonBackScreenCamera, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    

    ui_PanelDelayedPhotography = lv_obj_create(ui_PanelCameraSettings);
    lv_obj_set_size(ui_PanelDelayedPhotography, 528, 52);
    lv_obj_set_pos(ui_PanelDelayedPhotography, 12, 61);
    lv_obj_add_flag(ui_PanelDelayedPhotography, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_PanelDelayedPhotography, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_PanelDelayedPhotography, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelDelayedPhotography, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelDelayedPhotography, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelDelayedPhotography, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelDelayedPhotography, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_PanelDelayedPhotography, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式设置
    lv_obj_set_style_bg_color(ui_PanelDelayedPhotography, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_PanelDelayedPhotography, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_PanelDelayedPhotography, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_PanelDelayedPhotography, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
  
    // ui_LabelDelayedPhotography = lv_label_create(ui_PanelDelayedPhotography);
    // lv_obj_set_width(ui_LabelDelayedPhotography, LV_SIZE_CONTENT);
    // lv_obj_set_height(ui_LabelDelayedPhotography, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_LabelDelayedPhotography, 26);
    // lv_obj_set_y(ui_LabelDelayedPhotography, 90);
    // lv_label_set_long_mode(ui_LabelDelayedPhotography, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_LabelDelayedPhotography, EnableArray[language_index]);
    // lv_obj_set_style_text_color(ui_LabelDelayedPhotography, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_LabelDelayedPhotography, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_LabelDelayedPhotography, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_LabelDelayedPhotography = lv_label_create(ui_PanelDelayedPhotography);
    lv_obj_set_size(ui_LabelDelayedPhotography, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelDelayedPhotography, LV_ALIGN_LEFT_MID, 11, 1);
    lv_label_set_recolor(ui_LabelDelayedPhotography, true);
    lv_label_set_text(ui_LabelDelayedPhotography, EnableArray[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelDelayedPhotography, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelDelayedPhotography, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelDelayedPhotography, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SwitchDelayedPhotography = lv_switch_create(ui_PanelDelayedPhotography);
    lv_obj_set_width(ui_SwitchDelayedPhotography, 54);
    lv_obj_set_height(ui_SwitchDelayedPhotography, 26);
    lv_obj_align(ui_SwitchDelayedPhotography, LV_ALIGN_RIGHT_MID, -12, 0);
    lv_obj_set_style_radius(ui_SwitchDelayedPhotography, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchDelayedPhotography, lv_color_hex(0x6D6D6D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchDelayedPhotography, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SwitchDelayedPhotography, lv_color_hex(0x252525), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchDelayedPhotography, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_SwitchDelayedPhotography, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_SwitchDelayedPhotography, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(ui_SwitchDelayedPhotography, 30, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchDelayedPhotography, lv_color_hex(0x9D9D9D), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchDelayedPhotography, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchDelayedPhotography, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchDelayedPhotography, 255, LV_PART_KNOB | LV_STATE_CHECKED);
    
    //拍摄位置
    ui_PanelShootPos = lv_obj_create(ui_PanelCameraSettings);
    lv_obj_set_size(ui_PanelShootPos, 528, 52);
    lv_obj_set_pos(ui_PanelShootPos, 12, 125);
    lv_obj_add_flag(ui_PanelShootPos, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_PanelShootPos, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_PanelShootPos, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelShootPos, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelShootPos, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelShootPos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelShootPos, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_PanelShootPos, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式设置
    lv_obj_set_style_bg_color(ui_PanelShootPos, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_PanelShootPos, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_PanelShootPos, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_PanelShootPos, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
  
    ui_LabelShootPos = lv_label_create(ui_PanelShootPos);
    lv_obj_set_size(ui_LabelShootPos, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelShootPos, LV_ALIGN_LEFT_MID, 11, 1);
    lv_label_set_recolor(ui_LabelShootPos, true);
    lv_label_set_text(ui_LabelShootPos, ShootPosArray[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelShootPos, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelShootPos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelShootPos, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_ArrowImageShootPos = lv_img_create(ui_PanelShootPos);
    lv_img_set_src(ui_ArrowImageShootPos, &ui_img_rightarrow_png);
    lv_obj_set_width(ui_ArrowImageShootPos, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ArrowImageShootPos, LV_SIZE_CONTENT);
    lv_obj_align(ui_ArrowImageShootPos, LV_ALIGN_RIGHT_MID, -15, 0);
    lv_obj_add_flag(ui_ArrowImageShootPos, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ArrowImageShootPos, LV_OBJ_FLAG_SCROLLABLE); 
    
    ui_LabelSelectShootPos = lv_label_create(ui_PanelShootPos);
    lv_obj_set_size(ui_LabelSelectShootPos, 200, LV_SIZE_CONTENT);
    lv_label_set_long_mode(ui_LabelSelectShootPos, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(ui_LabelSelectShootPos, LV_ALIGN_RIGHT_MID, -35, 1);
    //lv_label_set_recolor(ui_LabelSelectShootPos, true);
    lv_label_set_text(ui_LabelSelectShootPos, LayerStartPos[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelSelectShootPos, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSelectShootPos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSelectShootPos, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelSelectShootPos, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    

    //拍照频率暂时没有用到
    ui_Screen2_Label7 = lv_label_create(ui_PanelCameraSettings);
    lv_obj_set_width(ui_Screen2_Label7, 300);
    lv_obj_set_height(ui_Screen2_Label7, 28);
    lv_obj_set_x(ui_Screen2_Label7, 26);
    lv_obj_set_y(ui_Screen2_Label7, 208);
    lv_label_set_long_mode(ui_Screen2_Label7, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_Screen2_Label7, ShootFreqArray[language_index]);
    lv_obj_set_style_text_color(ui_Screen2_Label7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen2_Label7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_Label7, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen2_Label8 = lv_label_create(ui_PanelCameraSettings);
    lv_obj_set_width(ui_Screen2_Label8, 300);
    lv_obj_set_height(ui_Screen2_Label8, 28);
    lv_obj_set_x(ui_Screen2_Label8, 26);
    lv_obj_set_y(ui_Screen2_Label8, 268);
    lv_label_set_long_mode(ui_Screen2_Label8, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_Screen2_Label8, RenderArray[language_index]);
    lv_obj_set_style_text_color(ui_Screen2_Label8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen2_Label8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_Label8, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Shoot_Pos = lv_label_create(ui_PanelCameraSettings);
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
    static Msgboxbtn_t ShootPosbtn[2]; //用于拍照位置对话框数据判断

    for (size_t i = 0; i < 2; i++)
    {
        ShootPosbtn[i].btnsCallbackArray = ShootPosSettingCb;
        ShootPosbtn[i].SetLabelText = ShootPosBtnTextSetCb;
    }
    
    ShootPosMessage.hasSubPanel = true;
    ShootPosMessage.title = &ShootPosArray[language_index];
    ShootPosMessage.btn = ShootPosbtn;
    ShootPosMessage.customStyle = &StyleDialogBtn;
    ShootPosMessage.customFocusStyle = &StyleDialogFocusBtn;

    ShootPosMessage.btnNumber = sizeof(ShootPosbtn)/sizeof(Msgboxbtn_t);
    ShootPosMessage.subPanelAttr.w = 371;
    ShootPosMessage.subPanelAttr.h = 278;

    InitDialogMessagebox(&ShootPosMessage);

    lv_obj_align(ShootPosMessage.titleLabel, LV_ALIGN_TOP_MID, 0, 11);
    
    uint8_t btnBasePos_y = 56;
    for (size_t i = 0; i < ShootPosMessage.btnNumber; i++)
    {
        //lv_obj_align(ShootPosMessage.btn[i].label, LV_ALIGN_LEFT_MID, 0, 1);
        lv_obj_set_size(ShootPosMessage.btn[i].label, 300, LV_SIZE_CONTENT);
        lv_obj_set_pos(ShootPosMessage.btn[i].label, 12, 0);
        lv_label_set_long_mode(ShootPosMessage.btn[i].label, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_align(ShootPosMessage.btn[i].label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_size(ShootPosMessage.btn[i].btn, 312, 52);
        lv_obj_set_pos(ShootPosMessage.btn[i].btn, 35, btnBasePos_y);
        btnBasePos_y += 67;
    }

    // shoot_pos_opt_name[0] = LayerStartPos[language_index];
    // shoot_pos_opt_name[1] = HotendMoveAway[language_index];
    // ui_Dropdown_Shoot_Pos = lv_dropdown_create(ui_PanelCameraSettings);
    // lv_dropdown_clear_options(ui_Dropdown_Shoot_Pos);
    // for ( int j = 0; j < 2; j++ )
    //     lv_dropdown_add_option(ui_Dropdown_Shoot_Pos, shoot_pos_opt_name[j], j);

    // lv_obj_set_width(ui_Dropdown_Shoot_Pos, 283);
    // lv_obj_set_height(ui_Dropdown_Shoot_Pos, 40);
    // lv_obj_set_x(ui_Dropdown_Shoot_Pos, 379);
    // lv_obj_set_y(ui_Dropdown_Shoot_Pos, 149);
    // lv_obj_add_flag(ui_Dropdown_Shoot_Pos, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_set_style_text_color(ui_Dropdown_Shoot_Pos, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_Dropdown_Shoot_Pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_Dropdown_Shoot_Pos, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_Dropdown_Shoot_Pos, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_radius(ui_Dropdown_Shoot_Pos, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_Dropdown_Shoot_Pos, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_Dropdown_Shoot_Pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_Dropdown_Shoot_Pos, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_Dropdown_Shoot_Pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_Dropdown_Shoot_Pos, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_left(ui_Dropdown_Shoot_Pos, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_right(ui_Dropdown_Shoot_Pos, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_top(ui_Dropdown_Shoot_Pos, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_bottom(ui_Dropdown_Shoot_Pos, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_set_style_text_color(ui_Dropdown_Shoot_Pos, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_Dropdown_Shoot_Pos, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_Dropdown_Shoot_Pos, LV_TEXT_ALIGN_LEFT, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_Dropdown_Shoot_Pos, lv_font24.font, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    // lv_dropdown_set_symbol(ui_Dropdown_Shoot_Pos, &ui_img_expand_down_png);

    ui_Screen2_Label10 = lv_label_create(ui_PanelCameraSettings);
    lv_obj_set_width(ui_Screen2_Label10, 60);
    lv_obj_set_height(ui_Screen2_Label10, 28);
    lv_obj_set_x(ui_Screen2_Label10, -262);
    lv_obj_set_y(ui_Screen2_Label10, 207);
    lv_obj_set_align(ui_Screen2_Label10, LV_ALIGN_TOP_RIGHT);
    lv_label_set_long_mode(ui_Screen2_Label10, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_Screen2_Label10, EveryArray[language_index]);
    lv_obj_set_style_text_color(ui_Screen2_Label10, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen2_Label10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Screen2_Label10, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_Label10, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Shoot_Freq = lv_label_create(ui_PanelCameraSettings);
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

    ui_Screen2_Label12 = lv_label_create(ui_PanelCameraSettings);
    lv_obj_set_width(ui_Screen2_Label12, 140);
    lv_obj_set_height(ui_Screen2_Label12, 28);
    lv_obj_set_x(ui_Screen2_Label12, 536);
    lv_obj_set_y(ui_Screen2_Label12, 207);
    lv_label_set_long_mode(ui_Screen2_Label12, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s%s", LayerArray[language_index], ShootMsg[language_index]);
    lv_label_set_text(ui_Screen2_Label12, buff);
    lv_obj_set_style_text_color(ui_Screen2_Label12, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen2_Label12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Screen2_Label12, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen2_Label12, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //渲染方式下拉列表
    ui_Dropdown_Render_Method = lv_dropdown_create(ui_PanelCameraSettings);
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


    lv_obj_add_event_cb(ui_ButtonBackScreenCamera, ui_event_Button_Back_Clicked, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelDelayedPhotography, ui_event_Switch_Delayed_photography_Clicked, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Label_Shoot_Freq, ui_event_label_shoot_freq_clicked, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Dropdown_Render_Method, ui_event_dropdown_render_method_clicked, LV_EVENT_ALL, NULL);
   // lv_obj_add_event_cb(ui_Dropdown_Shoot_Pos, ui_event_dropdown_shoot_pos_changed, LV_EVENT_ALL, NULL);

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
    lv_obj_add_event_cb(ui_PanelShootPos, ui_event_PanelShootPos, LV_EVENT_ALL, NULL);
    
    /*****************隐藏用不到的控件************************/
    //拍照频率
    lv_obj_add_flag(ui_Screen2_Label7, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Screen2_Label10, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Label_Shoot_Freq, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Screen2_Label12, LV_OBJ_FLAG_HIDDEN);
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
    if(!lv_obj_has_state(ui_SwitchDelayedPhotography, LV_STATE_CHECKED))
    {
        lv_obj_add_state(ui_SwitchDelayedPhotography, LV_STATE_CHECKED);
         send_set_camera_delayed_photography(true);
    }
    else
    {
        lv_obj_clear_state(ui_SwitchDelayedPhotography, LV_STATE_CHECKED);
        send_set_camera_delayed_photography(false);
    }
    send_get_camera_delayed_photography();
}

void edit_shoot_freq(lv_event_t * e)
{
    char buff[40] = {0};
    sprintf(buff, "摄像频率可输入范围0-%d", MAX_SHOOT_FREQ);
    numberskeyboardinput(buff, MAX_SHOOT_FREQ, 0, &shoot_freq_confirm_btn_call_back, &key_reminder_callback, 80, 0);
}

static uint8_t shoot_pos_index = 0;
void camera_settings_set_shoot_pos(uint8_t pos)
{
    uint8_t language_index = get_cur_language_index();
   
    for ( int i = 0; i < 2; i++ )
    {
        if ( pos == shoot_pos_opt_value[i]  )
        {
            shoot_pos_index = i;
            //printf("shoot_pos_index:%d\n", shoot_pos_index);
            switch (shoot_pos_index)
            {
            case 0:
                lv_label_set_text(ui_LabelSelectShootPos, LayerStartPos[language_index]);
                break;
            case 1:
                lv_label_set_text(ui_LabelSelectShootPos, HotendMoveAway[language_index]);
                break;
            default:
                break;
            } 
            // if ( ui_Dropdown_Shoot_Pos )
            // {
            //     lv_dropdown_set_selected(ui_Dropdown_Shoot_Pos, i);
            //     lv_dropdown_set_text(ui_Dropdown_Shoot_Pos, shoot_pos_opt_name[i]);
            // }  
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
    if ( ui_SwitchDelayedPhotography )
        delayed_photography_opened ? lv_obj_add_state(ui_SwitchDelayedPhotography, LV_STATE_CHECKED) : \
        lv_obj_clear_state(ui_SwitchDelayedPhotography, LV_STATE_CHECKED);
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
    if ( ui_LabelTitleScreenCamera )
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", CameraArray[language_index], SettingArray[language_index]);
        lv_label_set_text(ui_LabelTitleScreenCamera, CameraSetting[language_index]);
    }

    if ( ui_LabelDelayedPhotography )
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", EnableArray[language_index], DelayPhotograph[language_index]);
        lv_label_set_text(ui_LabelDelayedPhotography, EnableArray[language_index]);
    }

    if ( ui_LabelShootPos )
        lv_label_set_text(ui_LabelShootPos, ShootPosArray[language_index]);

    if ( ui_Screen2_Label7 )
        lv_label_set_text(ui_Screen2_Label7, ShootFreqArray[language_index]);

    if ( ui_Screen2_Label8 )
        lv_label_set_text(ui_Screen2_Label8, RenderArray[language_index]);


    // if ( ui_Dropdown_Shoot_Pos )
    // {
    //     shoot_pos_opt_name[0] = LayerStartPos[language_index];
    //     shoot_pos_opt_name[1] = HotendMoveAway[language_index];
    //     uint8_t id = lv_dropdown_get_selected(ui_Dropdown_Shoot_Pos);
    //     lv_dropdown_clear_options(ui_Dropdown_Shoot_Pos);
    //     for ( int j = 0; j < 2; j++ )
    //         lv_dropdown_add_option(ui_Dropdown_Shoot_Pos, shoot_pos_opt_name[j], j);
        
    //     lv_dropdown_set_selected(ui_Dropdown_Shoot_Pos, id);
    // }
    if (ui_LabelSelectShootPos)
    {
        switch (shoot_pos_index)
        {
        case 0:
            lv_label_set_text(ui_LabelSelectShootPos, LayerStartPos[language_index]);
            break;
        case 1:
            lv_label_set_text(ui_LabelSelectShootPos, HotendMoveAway[language_index]);
            break;
        default:
            break;
        } 
    }
       
    
    if ( ui_Screen2_Label10 )
        lv_label_set_text(ui_Screen2_Label10, EveryArray[language_index]);
    
    if ( ui_Screen2_Label12 )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s%s", LayerArray[language_index], ShootMsg[language_index]);
        lv_label_set_text(ui_Screen2_Label12, buff);
    }
}

static void LoadCameraSettingsScreen(void)
{
    _ui_screen_change(ui_camerasetting, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0); 
}
 

/**
 * @description: 拍照位置设置对象事件添加
 * @return {*}
 */
static void ShootPosMessageAddFocusObjs(void)
{
    lv_group_remove_all_objs(encoder_group);
    for (int i = 0; i < 2; i++)
    {
        lv_group_add_obj(encoder_group, ShootPosMessage.btn[i].btn);
    } 
}

/**
 * @description: 摄像头设置对象添加
 * @return {*}
 */
static void CameraSettingsPageAddFocusObjs(void)
{
    lv_group_remove_all_objs(encoder_group);
    
    PageNode *CameraSettings_node = find_page(ui_camerasetting);
    CameraSettings_node->nav_level = index;
    
    lv_group_add_obj(encoder_group, ui_ButtonBackScreenCamera);
    lv_group_add_obj(encoder_group, ui_PanelDelayedPhotography);
    lv_group_add_obj(encoder_group, ui_PanelShootPos);
}