/*
 * @Description: 正常首页
 * @Author: chenwenke
 * @Date: 2023-07-07 01:43:52
 * @LastEditTime: 2023-11-04 04:00:29
 */

#include "ui_screen_HomeNormal.h"
#include "page_switch.h"
#include "ui_screen_AxisMove.h"
#include "ui_screen_FileManage.h"
//#include "keypad_encoder.h"
#include <stdio.h>
#include <string.h>
#include "ui_custom_numbers_keys.h"
#include "ui_custom_messagebox.h"
#include "../custom/lvgl_cmd.h"
#include "ui_Screen_Settings.h"
#include "ui_Screen_CustomerService.h"
#include "mult_language.h"


/********************************正常首页***************************************/
static lv_obj_t * ui_ScreenHomePageNormal;

/*****************************左边 页导航按钮************************************/
static lv_obj_t * ui_PanelPageNormal;
// static lv_obj_t * ui_ImageHomePageNormal;
static lv_obj_t * ui_ButtonHomePageNormal;
static lv_obj_t * ui_ButtonAxisMoveNormal;
static lv_obj_t * ui_ButtonFIleManageNormal;
static lv_obj_t * ui_ButtonSettingsNormal;
static lv_obj_t * ui_ButtonReserveNormal;

/****************************中间 状态栏和温度图**********************************/
static lv_obj_t * ui_PanelTemperChartNormal;
static lv_obj_t * ui_DeviceIconPanel;
static lv_obj_t * ui_ImageLaserState;
static lv_obj_t * ui_ImageWifiNormal;
static lv_obj_t * ui_ImageCamerastate;
static lv_obj_t * ui_LabelTemperUnitNormal;
static lv_obj_t * ui_ChartTemperNormal;

/***********************右边 温度信息，灯和风扇状态等*******************************/
static lv_obj_t * ui_PanelTemperInfoNormal;
static lv_obj_t * ui_ImageCompanyNormal;

//喷嘴温度
static lv_obj_t * ui_PanelHotendTempNormal;
static lv_obj_t * ui_ImageHotendNormal;
// static lv_obj_t * ui_LabelHotendTemperNormal;
static lv_obj_t * ui_LabelHotendTemperCelsiusNormal;
// static lv_obj_t * ui_PanelHotendHeatingNormal;
// static lv_obj_t * ui_ImageHotendHeatingNormal;
static lv_obj_t * ui_LabelHotendCurTemperNormal;
// static lv_obj_t * ui_LabelHotendLeftSlashNormal;   // '/'
// static lv_obj_t * ui_LabelHotendHeatingTemperCelsiusNormal;
static lv_obj_t * ui_LabelHotendTargetTemperNormal;
static lv_obj_t * ui_LabelHotendSettingTemperNormal;
static lv_obj_t * ui_ImageHotendHeatingToNormal;

//热床温度
static lv_obj_t * ui_PanelBedTempNormal;
static lv_obj_t * ui_ImageBedNormal;
// static lv_obj_t * ui_LabelBedTemperNormal;
static lv_obj_t * ui_LabelBedTemperCelsiusNormal;
static lv_obj_t * ui_PanelLineNormal;
// static lv_obj_t * ui_PanelBedHeatingNormal;
// static lv_obj_t * ui_ImageBedHeatingNormal;
static lv_obj_t * ui_LabelBedCurTemperNormal;
// static lv_obj_t * ui_LabelBedLeftSlashNormal; // "/"
static lv_obj_t * ui_ImageBedHeatingToNormal;
static lv_obj_t * ui_LabelBedTargetTemperNormal;
static lv_obj_t * ui_LabelBedSettingTemperNormal;
// static lv_obj_t * ui_LabelBedHeatingTemperCelsiusNormal;

//灯和风扇状态
static lv_obj_t * ui_PanelStatusNormal;
static lv_obj_t * ui_PanelLightStatus;
static lv_obj_t * ui_ImageLightNormal;
static lv_obj_t * ui_PanelStatusLineNormal;
static lv_obj_t * ui_PanelFanStatus;
static lv_obj_t * ui_ImageFanNormal;
static lv_obj_t * ui_GifFanNormal;

/******************************************************************************/

/*******************************custom varants*********************************/
typedef struct 
{
    lv_obj_t *obj;
    lv_chart_series_t *series_list[2];
} chart_area_stack_t;

static lv_chart_series_t *series_hotend = NULL;
static lv_chart_series_t *series_bed = NULL;
static bool light_opened = true;
static bool fan_opened = false;
static int16_t bed_temper = -15;
static int16_t hotend_temper = -15;
static int wifi_Intensity = 0;
static chart_area_stack_t chart_area_stack;
static lv_timer_t * HomeNormalNavTimer;
static EventGrop_Data HomePageNormalManage;

typedef void (*add_3rd_level_nav_objs_f)(void);  //添加三级导航对象
static add_3rd_level_nav_objs_f add_3rd_level_nav_objs = NULL;

/***********home normal page event ************************/
static void ui_event_ButtonHomePageNormal(lv_event_t * e);
static void ui_event_ButtonAxisMoveNormal(lv_event_t * e);
static void ui_event_ButtonFIleManageNormal(lv_event_t * e);
static void ui_event_ButtonSettingsNormal(lv_event_t * e);
static void ui_event_ButtonReserveNormal(lv_event_t * e);
static void ui_event_PanelHotendTempNormal(lv_event_t * e);
static void ui_event_PanelBedTempNormal(lv_event_t * e);
static void ui_event_ImageLightNormal(lv_event_t * e);
static void ui_event_ImageFanNormal(lv_event_t * e);
static void ui_event_LabelHotendTargetTemper(lv_event_t * e);
static void ui_event_ButtonSelectPrintFileNormal(lv_event_t * e);

/***********home normal page event ************************/
static void homePageNormalHomePageBtnClicked(lv_event_t * e);
static void homePageNormalAxisMoveBtnClicked(lv_event_t * e);
static void homePageNormFileManageBtnClicked(lv_event_t * e);
static void homePageNormalReserveBtnClicked(lv_event_t * e);
// static void HomePageNormalHotendClicked(lv_event_t * e);
static void homePageNormalSettingBtnClicked(lv_event_t * e);
// static void HomePageNormalBedClicked(lv_event_t * e);
static void HomePageNormalLightClicked(lv_event_t * e);
static void HomePageNormalFanClicked(lv_event_t * e);
static void SelectPrintFileBtnNormalClicked(lv_event_t * e);

/***********************custom funs********************************/
static void bed_edit_target_temper_callback(void *param);
static void hotend_edit_target_temper_callback(void *param);
static void home_normal_draw_event_cb(lv_event_t *e);

/**
 * Helper function to round a fixed point number
 **/
static int32_t round_fixed_point(int32_t n, int8_t shift);
static void HomeNormalPageChangeObjs(uint8_t index);
static void HomeNormalNavFreezeTimerCb(lv_timer_t * timer);
static void ShowHotendHeatingStatus(bool show);
static void ShowBedHeatingStatus(bool show);

/**
 * @description: 事件组冻结定时解冻
 * @return {*}
 * @param {lv_timer_t *} timer
 */
void HomeNormalNavFreezeTimerCb(lv_timer_t * timer)
{
    lv_group_focus_freeze(encoder_group, false);
    lv_timer_del(HomeNormalNavTimer);
}

/***************************************************/
/********Home Normal Page***********/
void ui_event_ButtonHomePageNormal(lv_event_t * e)
{
    bool IsEntered = false;
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        // printf("ui_event_ButtonHomePageNormal\n");
        send_buzzer(0x01);
        IsEntered = HomePageNormalManage.stateValue;
        IsEntered = !IsEntered;
        LoadHomeNormalPageAndObjs(IsEntered);
    }
    // if(event_code == LV_EVENT_DEFOCUSED)
    // {
    //     if (HomePageNormalManage.stateValue)
    //     {
    //         lv_obj_set_style_bg_img_src(ui_ButtonHomePageNormal, &ui_img_pagehomeselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     }
    // }
    // if(event_code == LV_EVENT_FOCUSED)
    // {
    //     //lv_obj_set_style_bg_img_src(ui_ButtonHomePageNormal, &ui_img_pagehomeselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     // if (HomePageNormalManage.stateValue)
    //     // {
    //     //     lv_obj_set_style_bg_img_src(ui_ButtonHomePageNormal, &ui_img_pagehomefocus_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     //     if (page_manager.objFreezzFlag == false)
    //     //     {
    //     //         page_manager.objFreezzFlag = true;
    //     //     }
    //     //     else if (page_manager.objFreezzFlag == true)
    //     //     {
    //     //         lv_group_focus_freeze(encoder_group, true);
    //     //         HomeNormalNavTimer = lv_timer_create(HomeNormalNavFreezeTimerCb, 300,  NULL);
    //     //     }
    //     // }
    // }
}

void ui_event_ButtonAxisMoveNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        LoadAxixMoveScreenAndObjs(true);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
        LoadAxixMoveScreenAndObjs(false);
    }
}

void ui_event_ButtonFIleManageNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //LoadFileManageScreen();
        LoadFileManageScreenAndObjs(true);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
       // LoadFileManageScreen(); 
        LoadFileManageScreenAndObjs(false);
    }
}

void ui_event_ButtonSettingsNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //LoadSettingsScreen();
        // LoadSettingsScreenAndObjs(false, SCREEN_SETTINGS_BUTTON);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
      //  LoadSettingsScreen(); 
        // LoadSettingsScreenAndObjs(false, SCREEN_SETTINGS_BUTTON);
    }
}

void ui_event_ButtonReserveNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        // _ui_screen_change(ui_Cameralist, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        LoadServiceScreenAndObjs(true);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
        //LoadCustomerServiceScreen();   
        LoadServiceScreenAndObjs(false);
    }
}

void ui_event_PanelHotendTempNormal(lv_event_t * e)
{
    uint8_t ret = 0;
    int16_t value = 0;
    char value_char[6] = {0};
    lv_event_code_t event_code = lv_event_get_code(e);
    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0)
    {//编辑模式
        if (lv_obj_has_flag(ui_ImageHotendHeatingToNormal,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
        {//非加热状态
            lv_obj_add_flag(ui_LabelHotendCurTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_LabelHotendSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {//加热状态
            lv_obj_add_flag(ui_LabelHotendTargetTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_LabelHotendSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        value = atoi(lv_label_get_text(ui_LabelHotendTargetTemperNormal));
        sprintf(value_char, "%d", value);
        lv_label_set_text(ui_LabelHotendSettingTemperNormal, value_char);        
    }
    else if(ret == 1)
    {//导航模式
        if (lv_obj_has_flag(ui_ImageHotendHeatingToNormal,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
        {//非加热状态
            lv_obj_clear_flag(ui_LabelHotendCurTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelHotendSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {//加热状态
            lv_obj_clear_flag(ui_LabelHotendTargetTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelHotendSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        //設置目標溫度
        value = atoi(lv_label_get_text(ui_LabelHotendSettingTemperNormal));
        lv_label_set_text(ui_LabelHotendTargetTemperNormal, lv_label_get_text(ui_LabelHotendSettingTemperNormal)); 
        send_set_target_temper_cmd(value, true);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //
        if (lv_obj_has_flag(ui_ImageHotendHeatingToNormal,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
        {//非加热状态
            lv_obj_clear_flag(ui_LabelHotendCurTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelHotendSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {//加热状态
            lv_obj_clear_flag(ui_LabelHotendTargetTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelHotendSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        //設置目標溫度
        value = atoi(lv_label_get_text(ui_LabelHotendSettingTemperNormal));
        lv_label_set_text(ui_LabelHotendTargetTemperNormal, lv_label_get_text(ui_LabelHotendSettingTemperNormal)); 
    }

    EncoderChangeLableValue(ui_LabelHotendSettingTemperNormal, e, HOTEND_MIN_EDIT_TEMPER, HOTEND_MAX_EDIT_TEMPER);

}

void ui_event_PanelBedTempNormal(lv_event_t * e)
{
    uint8_t ret = 0;
    int16_t value = 0;
    char value_char[6] = {0};
    lv_event_code_t event_code = lv_event_get_code(e);
    // if(event_code == LV_EVENT_LONG_PRESSED) {   //长按退出
    //     lv_obj_add_flag(ui_LabelBedSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
    //     lv_obj_clear_flag(ui_LabelBedTargetTemperNormal, LV_OBJ_FLAG_HIDDEN);
    //     PageMenuChange(MENU_RETURN, MENU_LEVEL_2, NULL);
    // }
    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0)
    {//编辑模式
        if (lv_obj_has_flag(ui_ImageBedHeatingToNormal,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
        {//非加热状态
            lv_obj_add_flag(ui_LabelBedCurTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_LabelBedSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {//加热状态
            lv_obj_add_flag(ui_LabelBedTargetTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_LabelBedSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        value = atoi(lv_label_get_text(ui_LabelBedTargetTemperNormal));
        sprintf(value_char, "%d", value);
        lv_label_set_text(ui_LabelBedSettingTemperNormal, value_char);    
    }
    else if(ret == 1)
    {//导航模式
        if (lv_obj_has_flag(ui_ImageBedHeatingToNormal,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
        {//非加热状态
            lv_obj_clear_flag(ui_LabelBedCurTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelBedSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {//加热状态
            lv_obj_clear_flag(ui_LabelBedTargetTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelBedSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        //設置目標溫度
        value = atoi(lv_label_get_text(ui_LabelBedSettingTemperNormal));
        lv_label_set_text(ui_LabelBedTargetTemperNormal, lv_label_get_text(ui_LabelBedSettingTemperNormal)); 
        send_set_target_temper_cmd(value, false);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //处理息屏后聚焦对象改变造成的问题
        if (lv_obj_has_flag(ui_ImageBedHeatingToNormal,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
        {//非加热状态
            lv_obj_clear_flag(ui_LabelBedCurTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelBedSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {//加热状态
            lv_obj_clear_flag(ui_LabelBedTargetTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelBedSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);
        }
        //設置目標溫度
        value = atoi(lv_label_get_text(ui_LabelBedSettingTemperNormal));
        lv_label_set_text(ui_LabelBedTargetTemperNormal, lv_label_get_text(ui_LabelBedSettingTemperNormal)); 
    }

    EncoderChangeLableValue(ui_LabelBedSettingTemperNormal, e, BED_MIN_EDIT_TEMPER, BED_MAX_EDIT_TEMPER);
}

void ui_event_ImageLightNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageNormalLightClicked(e);
    }
}

void ui_event_ImageFanNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        HomePageNormalFanClicked(e);
    }
}

void ui_event_LabelHotendTargetTemper(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        //HomePageNormalFanClicked(e);
    }
    if(event_code == LV_EVENT_LONG_PRESSED) {   //长按退出
        //PageMenuChange(MENU_RETURN, MENU_LEVEL_2, NULL);
    }
}

void ui_event_ButtonSelectPrintFileNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        SelectPrintFileBtnNormalClicked(e);
    }
}

void ui_ScreenHomePageNormal_screen_init(void)
{
    ui_ScreenHomePageNormal = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenHomePageNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenHomePageNormal, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenHomePageNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //HomePageNormalManage.GropName = lv_group_create();
    HomePageNormalManage.stateValue = false;
    init_pages(ui_ScreenHomePageNormal, HomeNormalPageChangeObjs, LoadHomeNormalScreen);
#if 1
    //左边导航面板
    ui_PanelPageNormal = lv_obj_create(ui_ScreenHomePageNormal);
    lv_obj_set_size(ui_PanelPageNormal, 68, 360);
    lv_obj_set_pos(ui_PanelPageNormal, 0, 60);
    lv_obj_clear_flag(ui_PanelPageNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelPageNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPageNormal, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //home按键
    //ui_ButtonHomePageNormal = lv_btn_create(ui_PanelPageNormal);
    ui_ButtonHomePageNormal = lv_obj_create(ui_PanelPageNormal);
    lv_obj_set_size(ui_ButtonHomePageNormal, 68, 72);
    lv_obj_set_pos(ui_ButtonHomePageNormal, -18, -18);
    lv_obj_add_flag(ui_ButtonHomePageNormal, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomePageNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //默认样式
    lv_obj_set_style_radius(ui_ButtonHomePageNormal, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonHomePageNormal, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_radius(ui_ButtonFileManageScreenFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonHomePageNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_ButtonHomePageNormal, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonHomePageNormal, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonHomePageNormal, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonHomePageNormal, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonHomePageNormal, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonHomePageNormal, 1, LV_PART_MAIN | LV_STATE_PRESSED);

    //准备按键
    ui_ButtonAxisMoveNormal = lv_btn_create(ui_PanelPageNormal);
    lv_obj_set_size(ui_ButtonAxisMoveNormal, 68, 72);
    lv_obj_set_pos(ui_ButtonAxisMoveNormal, -18, 54);
    lv_obj_add_flag(ui_ButtonAxisMoveNormal, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonAxisMoveNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonAxisMoveNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //默认样式
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveNormal, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式   
    lv_obj_set_style_radius(ui_ButtonAxisMoveNormal, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(ui_ButtonAxisMoveNormal, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);                   
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveNormal, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveNormal, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonAxisMoveNormal, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonAxisMoveNormal, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //文件按钮
    ui_ButtonFIleManageNormal = lv_btn_create(ui_PanelPageNormal);
    lv_obj_set_size(ui_ButtonFIleManageNormal, 68, 72);
    lv_obj_set_pos(ui_ButtonFIleManageNormal, -18, 126);
    lv_obj_add_flag(ui_ButtonFIleManageNormal, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFIleManageNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonFIleManageNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonFIleManageNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //默认样式
    lv_obj_set_style_bg_img_src(ui_ButtonFIleManageNormal, &ui_img_pagefilemanage_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式  
    lv_obj_set_style_radius(ui_ButtonFIleManageNormal, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(ui_ButtonFIleManageNormal, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonFIleManageNormal, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonFIleManageNormal, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonFIleManageNormal, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonFIleManageNormal, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //设置按钮
    ui_ButtonSettingsNormal = lv_btn_create(ui_PanelPageNormal);
    lv_obj_set_size(ui_ButtonSettingsNormal, 68, 72);
    lv_obj_set_pos(ui_ButtonSettingsNormal, -18, 198);
    lv_obj_add_flag(ui_ButtonSettingsNormal, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonSettingsNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonSettingsNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //默认样式
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsNormal, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式 
    lv_obj_set_style_radius(ui_ButtonSettingsNormal, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(ui_ButtonSettingsNormal, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonSettingsNormal, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonSettingsNormal, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonSettingsNormal, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonSettingsNormal, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //客服按钮
    ui_ButtonReserveNormal = lv_btn_create(ui_PanelPageNormal);
    lv_obj_set_size(ui_ButtonReserveNormal, 68, 72);
    lv_obj_set_pos(ui_ButtonReserveNormal, -18, 270);
    lv_obj_add_flag(ui_ButtonReserveNormal, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonReserveNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonReserveNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //默认样式
    lv_obj_set_style_bg_img_src(ui_ButtonReserveNormal, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式 
    lv_obj_set_style_radius(ui_ButtonReserveNormal, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(ui_ButtonReserveNormal, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonReserveNormal, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonReserveNormal, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonReserveNormal, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonReserveNormal, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

#endif 

    //中间温度图表面板
    ui_PanelTemperChartNormal = lv_obj_create(ui_ScreenHomePageNormal);
    lv_obj_set_size(ui_PanelTemperChartNormal, 363, 360);
    lv_obj_set_pos(ui_PanelTemperChartNormal, 68, 60);
    lv_obj_clear_flag(ui_PanelTemperChartNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_all(ui_PanelTemperChartNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelTemperChartNormal, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTemperChartNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelTemperChartNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    // //wifi
    // ui_ImageWifiNormal = lv_img_create(ui_PanelTemperChartNormal);
    // lv_img_set_src(ui_ImageWifiNormal, &ui_img_wifinosignel_png);
    // lv_obj_set_size(ui_ImageWifiNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // lv_obj_align(ui_ImageWifiNormal, LV_ALIGN_TOP_RIGHT, 0, 0);
    // lv_obj_add_flag(ui_ImageWifiNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageWifiNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // //摄像头
    // ui_ImageCamerastate = lv_img_create(ui_PanelTemperChartNormal);
    // lv_obj_set_size(ui_ImageCamerastate, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // lv_obj_align(ui_ImageCamerastate, LV_ALIGN_TOP_RIGHT, -52, 9);
    // lv_img_set_src(ui_ImageCamerastate, &ui_img_camera_png);
    // lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_SCROLLABLE); 
    // lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);


    ui_DeviceIconPanel = lv_obj_create(ui_PanelTemperChartNormal);
    lv_obj_set_size(ui_DeviceIconPanel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_clear_flag(ui_DeviceIconPanel, LV_OBJ_FLAG_SCROLLABLE);  
    lv_obj_align(ui_DeviceIconPanel, LV_ALIGN_TOP_RIGHT, -5, 5);
    lv_obj_set_style_radius(ui_DeviceIconPanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceIconPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceIconPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_DeviceIconPanel, lv_color_hex(0x565656), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_DeviceIconPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DeviceIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_DeviceIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_DeviceIconPanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_column(ui_DeviceIconPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_align(ui_DeviceIconPanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    //激光雷达
    ui_ImageLaserState = lv_img_create(ui_DeviceIconPanel);
    lv_obj_set_size(ui_ImageLaserState, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_img_set_src(ui_ImageLaserState, &ui_img_laser_png);
    lv_obj_add_flag(ui_ImageLaserState, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageLaserState, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_ImageLaserState, LV_OBJ_FLAG_HIDDEN); 

    //摄像头
    ui_ImageCamerastate = lv_img_create(ui_DeviceIconPanel);
    lv_obj_set_size(ui_ImageCamerastate, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_img_set_src(ui_ImageCamerastate, &ui_img_camera_png);
    lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN); 

    //wifi图标
    ui_ImageWifiNormal = lv_img_create(ui_DeviceIconPanel);
    home_normal_set_wifi_status(wifi_Intensity);
    lv_obj_set_size(ui_ImageWifiNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_add_flag(ui_ImageWifiNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageWifiNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    //单位 "°C"
    ui_LabelTemperUnitNormal = lv_label_create(ui_PanelTemperChartNormal);
    lv_obj_set_size(ui_LabelTemperUnitNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_LabelTemperUnitNormal, 55, 27);
    lv_label_set_text(ui_LabelTemperUnitNormal, "°C");
    lv_obj_clear_flag(ui_LabelTemperUnitNormal, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags
    lv_obj_set_style_text_color(ui_LabelTemperUnitNormal, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTemperUnitNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTemperUnitNormal, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTemperUnitNormal, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //图表
    ui_ChartTemperNormal = lv_chart_create(ui_PanelTemperChartNormal);
    lv_obj_set_size(ui_ChartTemperNormal, 305, 330);
    lv_obj_align(ui_ChartTemperNormal, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_chart_set_type(ui_ChartTemperNormal, LV_CHART_TYPE_LINE); 
    lv_obj_set_style_bg_opa(ui_ChartTemperNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChartTemperNormal, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //温度信息面板
    ui_PanelTemperInfoNormal = lv_obj_create(ui_ScreenHomePageNormal);
    lv_obj_set_size(ui_PanelTemperInfoNormal, 205, 268);
    lv_obj_set_pos(ui_PanelTemperInfoNormal, 431, 64);
    lv_obj_clear_flag(ui_PanelTemperInfoNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelTemperInfoNormal, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTemperInfoNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelTemperInfoNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelTemperInfoNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //公司LOGO
    ui_ImageCompanyNormal = lv_img_create(ui_PanelTemperInfoNormal);
    lv_img_set_src(ui_ImageCompanyNormal, &ui_img_company_png);
    lv_obj_set_size(ui_ImageCompanyNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_ImageCompanyNormal, LV_ALIGN_TOP_MID, 0, 17);
    lv_obj_add_flag(ui_ImageCompanyNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCompanyNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ImageCompanyNormal, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ImageCompanyNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //喷嘴温度控制板
    ui_PanelHotendTempNormal = lv_obj_create(ui_PanelTemperInfoNormal);
    lv_obj_set_size(ui_PanelHotendTempNormal, 173, 60);
    lv_obj_align(ui_PanelHotendTempNormal, LV_ALIGN_TOP_MID, 0, 47);
    lv_obj_clear_flag(ui_PanelHotendTempNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags   
    //默认样式
    lv_obj_set_style_bg_color(ui_PanelHotendTempNormal, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotendTempNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelHotendTempNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelHotendTempNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelHotendTempNormal, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式 
    lv_obj_set_style_border_color(ui_PanelHotendTempNormal, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_PanelHotendTempNormal, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_PanelHotendTempNormal, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_PanelHotendTempNormal, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //喷嘴图片
    ui_ImageHotendNormal = lv_img_create(ui_PanelHotendTempNormal);
    lv_img_set_src(ui_ImageHotendNormal, &ui_img_hotend_png);
    lv_obj_set_size(ui_ImageHotendNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_ImageHotendNormal, 13, 12);
    lv_obj_add_flag(ui_ImageHotendNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    //当前温度标签
    ui_LabelHotendCurTemperNormal = lv_label_create(ui_PanelHotendTempNormal);
    lv_obj_set_size(ui_LabelHotendCurTemperNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //默认非加热状态下，居中显示
    lv_obj_align(ui_LabelHotendCurTemperNormal, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LabelHotendCurTemperNormal, "0");
    lv_obj_set_style_text_color(ui_LabelHotendCurTemperNormal, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendCurTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendCurTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendCurTemperNormal, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //温度设置标签
    ui_LabelHotendSettingTemperNormal = lv_label_create(ui_PanelHotendTempNormal);
    lv_obj_set_size(ui_LabelHotendSettingTemperNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //默认非加热状态下，点击后出现，居中显示
    lv_obj_align(ui_LabelHotendSettingTemperNormal, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(ui_LabelHotendSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_label_set_text(ui_LabelHotendSettingTemperNormal, "0");
    lv_obj_set_style_bg_color(ui_LabelHotendSettingTemperNormal, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LabelHotendSettingTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_LabelHotendSettingTemperNormal, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelHotendSettingTemperNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendSettingTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendSettingTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendSettingTemperNormal, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //温度加热箭头
    ui_ImageHotendHeatingToNormal = lv_img_create(ui_PanelHotendTempNormal);
    lv_img_set_src(ui_ImageHotendHeatingToNormal, &ui_img_totarget2_png);
    lv_obj_set_size(ui_ImageHotendHeatingToNormal, 16, 15);
    //默认非加热状态，不设位置，并且隐藏
    lv_obj_align(ui_ImageHotendHeatingToNormal, LV_ALIGN_CENTER, 4, 0);
    lv_obj_add_flag(ui_ImageHotendHeatingToNormal, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendHeatingToNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_border_color(ui_ImageHotendHeatingToNormal, lv_color_hex(0x0000FF),
    //                               LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_ImageHotendHeatingToNormal, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_ImageHotendHeatingToNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    //lv_obj_set_style_img_recolor(ui_ImageHotendHeatingToNormal, lv_color_hex(0x0BD25B), LV_PART_MAIN | LV_STATE_DISABLED);
    //lv_obj_set_style_img_recolor_opa(ui_ImageHotendHeatingToNormal, 100, LV_PART_MAIN | LV_STATE_DISABLED);

    //目标温度
    ui_LabelHotendTargetTemperNormal = lv_label_create(ui_PanelHotendTempNormal);
    lv_obj_set_size(ui_LabelHotendTargetTemperNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_add_flag(ui_LabelHotendTargetTemperNormal, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(ui_LabelHotendTargetTemperNormal, "0");
    lv_obj_set_style_radius(ui_LabelHotendTargetTemperNormal, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelHotendTargetTemperNormal, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTargetTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendTargetTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTargetTemperNormal, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //喷嘴温度摄氏度单位标签
    ui_LabelHotendTemperCelsiusNormal = lv_label_create(ui_PanelHotendTempNormal);
    lv_obj_set_size(ui_LabelHotendTemperCelsiusNormal, 25, 30);
    lv_obj_set_pos(ui_LabelHotendTemperCelsiusNormal, 125, 15);
    lv_label_set_text(ui_LabelHotendTemperCelsiusNormal, "°C");
    lv_obj_set_style_text_color(ui_LabelHotendTemperCelsiusNormal, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTemperCelsiusNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendTemperCelsiusNormal, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTemperCelsiusNormal, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //分割线
    ui_PanelLineNormal = lv_obj_create(ui_PanelTemperInfoNormal);
    lv_obj_set_size(ui_PanelLineNormal, 195, 1);
    lv_obj_align(ui_PanelLineNormal, LV_ALIGN_TOP_MID, 0, 114);
    lv_obj_clear_flag(ui_PanelLineNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelLineNormal, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLineNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //热床温度控制面板
    ui_PanelBedTempNormal = lv_obj_create(ui_PanelTemperInfoNormal);
    lv_obj_set_size(ui_PanelBedTempNormal, 173, 60);
    lv_obj_align_to(ui_PanelBedTempNormal, ui_PanelLineNormal, LV_ALIGN_OUT_BOTTOM_MID, 0, 8);
    lv_obj_clear_flag(ui_PanelBedTempNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //默认样式
    lv_obj_set_style_bg_color(ui_PanelBedTempNormal, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBedTempNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBedTempNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelBedTempNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelBedTempNormal, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式 
    lv_obj_set_style_border_color(ui_PanelBedTempNormal, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_PanelBedTempNormal, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_PanelBedTempNormal, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_PanelBedTempNormal, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //正常热床图片
    ui_ImageBedNormal = lv_img_create(ui_PanelBedTempNormal);
    lv_img_set_src(ui_ImageBedNormal, &ui_img_bed_png);
    lv_obj_set_size(ui_ImageBedNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_ImageBedNormal, 15, 17);
    lv_obj_add_flag(ui_ImageBedNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    //热床当前温度
    ui_LabelBedCurTemperNormal = lv_label_create(ui_PanelBedTempNormal);
    lv_obj_set_size(ui_LabelBedCurTemperNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align_to(ui_LabelBedCurTemperNormal, ui_LabelBedLeftSlashNormal, LV_ALIGN_OUT_LEFT_MID, 0, -5);
    lv_obj_align(ui_LabelBedCurTemperNormal, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LabelBedCurTemperNormal, "0");
    lv_obj_set_style_text_color(ui_LabelBedCurTemperNormal, lv_color_hex(0x0BD25B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedCurTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedCurTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedCurTemperNormal, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //热床目标温度设置
    ui_LabelBedSettingTemperNormal = lv_label_create(ui_PanelBedTempNormal);
    lv_obj_set_size(ui_LabelBedSettingTemperNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelBedSettingTemperNormal, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LabelBedSettingTemperNormal, "0");
    lv_obj_set_style_bg_color(ui_LabelBedSettingTemperNormal, lv_color_hex(0x42D87E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LabelBedSettingTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_LabelBedSettingTemperNormal, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelBedSettingTemperNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedSettingTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedSettingTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedSettingTemperNormal, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_LabelBedSettingTemperNormal, LV_OBJ_FLAG_HIDDEN);

    //热床加热箭头
    ui_ImageBedHeatingToNormal = lv_img_create(ui_PanelBedTempNormal);
    lv_img_set_src(ui_ImageBedHeatingToNormal, &ui_img_totarget_png);
    lv_obj_set_size(ui_ImageBedHeatingToNormal, 16, 15);
    //默认非加热状态，不设位置，并且隐藏
    lv_obj_align(ui_ImageBedHeatingToNormal, LV_ALIGN_CENTER, 4, 0);
    lv_obj_add_flag(ui_ImageBedHeatingToNormal, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_ImageBedHeatingToNormal, LV_OBJ_FLAG_SCROLLABLE); 

    //热床目标温度 
    ui_LabelBedTargetTemperNormal = lv_label_create(ui_PanelBedTempNormal);
    lv_obj_set_size(ui_LabelBedTargetTemperNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_add_flag(ui_LabelBedTargetTemperNormal, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(ui_LabelBedTargetTemperNormal, "0");
    lv_obj_set_style_radius(ui_LabelBedTargetTemperNormal, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelBedTargetTemperNormal, lv_color_hex(0x3DE4AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTargetTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTargetTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTargetTemperNormal, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //温度摄氏度单位标签
    ui_LabelBedTemperCelsiusNormal = lv_label_create(ui_PanelBedTempNormal);
    lv_obj_set_size(ui_LabelBedTemperCelsiusNormal, 25, 30);
    lv_obj_set_pos(ui_LabelBedTemperCelsiusNormal, 125, 15);
    lv_label_set_text(ui_LabelBedTemperCelsiusNormal, "°C");
    lv_obj_set_style_text_color(ui_LabelBedTemperCelsiusNormal, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemperCelsiusNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTemperCelsiusNormal, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemperCelsiusNormal, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //状态面板
    ui_PanelStatusNormal = lv_obj_create(ui_ScreenHomePageNormal);
    lv_obj_set_width(ui_PanelStatusNormal, 205);
    lv_obj_set_height(ui_PanelStatusNormal, 80);
    lv_obj_set_x(ui_PanelStatusNormal, 431);
    lv_obj_set_y(ui_PanelStatusNormal, 336);
    lv_obj_clear_flag(ui_PanelStatusNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelStatusNormal, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelStatusNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelStatusNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelStatusNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //灯状态面板
    ui_PanelLightStatus = lv_obj_create(ui_PanelStatusNormal);
    lv_obj_set_size(ui_PanelLightStatus, 80, 60);
    lv_obj_align(ui_PanelLightStatus, LV_ALIGN_LEFT_MID, 10, 0);
    lv_obj_set_style_pad_all(ui_PanelLightStatus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_PanelLightStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //默认样式
    lv_obj_set_style_bg_color(ui_PanelLightStatus, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelLightStatus, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelLightStatus, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelLightStatus, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_PanelLightStatus, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_PanelLightStatus, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_PanelLightStatus, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_PanelLightStatus, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //灯的图片
    ui_ImageLightNormal = lv_img_create(ui_PanelLightStatus);
    lv_obj_set_size(ui_ImageLightNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_ImageLightNormal, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ImageLightNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(ui_ImageLightNormal, &ui_img_lightclosed_png);
    //home_normal_set_light_status(light_opened);

    //状态中间分割线
    ui_PanelStatusLineNormal = lv_obj_create(ui_PanelStatusNormal);
    lv_obj_set_size(ui_PanelStatusLineNormal, 1, 60);
    lv_obj_align(ui_PanelStatusLineNormal, LV_ALIGN_CENTER, 0, 0);
    lv_obj_clear_flag(ui_PanelStatusLineNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelStatusLineNormal, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelStatusLineNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //风扇状态面板
    ui_PanelFanStatus = lv_obj_create(ui_PanelStatusNormal);
    lv_obj_set_size(ui_PanelFanStatus, 80, 60);
    lv_obj_align(ui_PanelFanStatus, LV_ALIGN_RIGHT_MID, -10, 0);
    lv_obj_clear_flag(ui_PanelFanStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//    lv_obj_clear_flag(ui_PanelFanStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //默认样式
    lv_obj_set_style_bg_color(ui_PanelFanStatus, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFanStatus, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFanStatus, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelFanStatus, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_PanelFanStatus, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_PanelFanStatus, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_PanelFanStatus, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_PanelFanStatus, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //关闭状态的风扇图片    
    ui_ImageFanNormal = lv_img_create(ui_PanelFanStatus);
    lv_obj_set_size(ui_ImageFanNormal, 66, 66);
    lv_obj_set_align(ui_ImageFanNormal, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ImageFanNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(ui_ImageFanNormal, &ui_img_stop_fan_png);

    //打开状态的风扇图片
    ui_GifFanNormal = lv_gif_create(ui_PanelFanStatus);
    lv_obj_set_size(ui_GifFanNormal, 66, 66);
    lv_obj_set_align(ui_GifFanNormal, LV_ALIGN_CENTER);
    lv_gif_set_src(ui_GifFanNormal, &ui_img_HomeFan);
    lv_obj_add_flag(ui_GifFanNormal, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_event_cb(ui_ButtonHomePageNormal, ui_event_ButtonHomePageNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMoveNormal, ui_event_ButtonAxisMoveNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonFIleManageNormal, ui_event_ButtonFIleManageNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsNormal, ui_event_ButtonSettingsNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserveNormal, ui_event_ButtonReserveNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelHotendTempNormal, ui_event_PanelHotendTempNormal, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_PanelHotendHeatingNormal, ui_event_PanelHotendTempNormal, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_PanelBedHeatingNormal, ui_event_PanelBedTempNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelBedTempNormal, ui_event_PanelBedTempNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelLightStatus, ui_event_ImageLightNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelFanStatus, ui_event_ImageFanNormal, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ButtonSelectPrintFileNormal, ui_event_ButtonSelectPrintFileNormal, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_LabelHotendTargetTemperNormal, ui_event_LabelHotendTargetTemper, LV_EVENT_ALL, NULL);

    /**********************other opt**************************/
    lv_chart_set_div_line_count(ui_ChartTemperNormal, 0, 0);
    lv_chart_set_range(ui_ChartTemperNormal, LV_CHART_AXIS_PRIMARY_Y, 0, 300);
    lv_chart_set_axis_tick(ui_ChartTemperNormal, LV_CHART_AXIS_PRIMARY_Y, 5, 3, 4, 2, true, 100);
    lv_chart_set_range(ui_ChartTemperNormal, LV_CHART_AXIS_PRIMARY_X, 0, 200);
    lv_chart_set_point_count(ui_ChartTemperNormal, 200);
    //lv_chart_set_axis_tick(ui_ChartTemperNormal, LV_CHART_AXIS_PRIMARY_X, 5, 5, 25, 1, true, 100);
    lv_obj_set_style_size(ui_ChartTemperNormal, 0, LV_PART_INDICATOR);//将点的大小设置为0
    lv_chart_set_update_mode(ui_ChartTemperNormal, LV_CHART_UPDATE_MODE_SHIFT);
    lv_obj_set_style_border_side(ui_ChartTemperNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ChartTemperNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    /*Add some data series*/
    series_bed = lv_chart_add_series(ui_ChartTemperNormal, lv_color_make(0x42, 0xD8, 0x7E), LV_CHART_AXIS_PRIMARY_Y);
    series_hotend = lv_chart_add_series(ui_ChartTemperNormal, lv_color_make(0x42, 0xBD, 0xD8), LV_CHART_AXIS_PRIMARY_Y);
    //lv_chart_series_t *series = lv_chart_add_series(ui_ChartTemperNormal, lv_color_make(0x00, 0x00, 0x00), LV_CHART_AXIS_PRIMARY_Y);
    chart_area_stack.series_list[0] = series_hotend;
    chart_area_stack.series_list[1] = series_bed;
    //chart_area_stack.series_list[2] = series_bed;
    chart_area_stack.obj = ui_ChartTemperNormal;
    lv_chart_set_all_value(ui_ChartTemperNormal, series_bed, 15);
    lv_chart_set_all_value(ui_ChartTemperNormal, series_hotend, 20);
    lv_obj_add_event_cb(chart_area_stack.obj, home_normal_draw_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);

}

//static int IsEntered = 0;
void LoadHomeNormalScreen(void)
{
    // printf("LoadHomeNormalScreen\n");
    lv_disp_load_scr(ui_ScreenHomePageNormal);
    // RefreshModelFanFlag = true;
    send_get_fans_status_cmd();
    send_get_light_status_cmd();
    send_get_wifi_status_cmd();
    //get_printer_data(CONTROL_MACHINE_STATE, 2, "5"); //获取摄像头状态
    // send_get_print_status();
}




void homePageNormalHomePageBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadHomeNormalScreen();
}

void homePageNormalAxisMoveBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadAxisMoveScreen();
}

void homePageNormFileManageBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadFileManageScreen();
}


void homePageNormalSettingBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadSettingsScreen();
    
}

void homePageNormalReserveBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadCustomerServiceScreen();
}

void hotend_edit_target_temper_callback(void *param)
{
    char *number_buff = (char*)param;
    if ( number_buff )
    {
        char *ch = strchr(number_buff, '.');
        if ( ch )
            *ch = '\0';

        send_set_target_temper_cmd(atoi(number_buff), true);
    }
}

// void HomePageNormalHotendClicked(lv_event_t * e)
// {
// 	// Your code here
//     char buff[300] = {0};
//     sprintf(buff, "%s #42BDD8 %d-%d#", HotendInputRangle[get_cur_language_index()],HOTEND_MIN_EDIT_TEMPER, HOTEND_MAX_EDIT_TEMPER);
//     numberskeyboardinput(buff, HOTEND_MAX_EDIT_TEMPER, HOTEND_MIN_EDIT_TEMPER,
//                     hotend_edit_target_temper_callback, key_reminder_callback, 92, 0);
// }

void bed_edit_target_temper_callback(void *param)
{
    char *number_buff = (char*)param;
    if ( number_buff )
    {
        char *ch = strchr(number_buff, '.');
        if ( ch )
            *ch = '\0';
            
        send_set_target_temper_cmd(atoi(number_buff), false);
    }
}

// void HomePageNormalBedClicked(lv_event_t * e)
// {
// 	// Your code here
//     char buff[300] = {0};
//     if(UIType == CR_K1_Max)
//     {
//         sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, K1_MAX_BED_MAX_EDIT_TEMPER);
//         numberskeyboardinput(buff, K1_MAX_BED_MAX_EDIT_TEMPER, BED_MIN_EDIT_TEMPER,
//                 bed_edit_target_temper_callback, key_reminder_callback, 92, 0);        
//     }
//     else
//     {
//         sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, BED_MAX_EDIT_TEMPER);
//         numberskeyboardinput(buff, BED_MAX_EDIT_TEMPER, BED_MIN_EDIT_TEMPER,
//                 bed_edit_target_temper_callback, key_reminder_callback, 92, 0);        
//     }

// }

void HomePageNormalLightClicked(lv_event_t * e)
{
	// Your code here
    send_set_light_opt_cmd(!light_opened);
    
}

void HomePageNormalFanClicked(lv_event_t * e)
{
	// Your code here
    // uint8_t percent = 100;
    // if ( fan_opened )
    // {
    //     percent = 0;
    //     home_normal_set_fan_status(false);
    // }
    // else
    // {
    //     home_normal_set_fan_status(true);
    // }
        
    // send_set_model_fan_opt_cmd(percent);

    ShowCoolSubPage(ui_ScreenHomePageNormal);
    add_3rd_level_nav_objs = AddFanCtrlNavObjs;
    LoadPage(ui_ScreenHomePageNormal, 3);

    //不再发送命令改为跳转页面
    //LoadCoolScreen();
}

void SelectPrintFileBtnNormalClicked(lv_event_t * e)
{
    LoadFileManageScreen();
}


/**
 * Callback which draws the blocks of colour under the lines
 **/
void home_normal_draw_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);

    /*Add the faded area before the lines are drawn*/
    lv_obj_draw_part_dsc_t *dsc = lv_event_get_draw_part_dsc(e);
    if (dsc->part == LV_PART_ITEMS)
    {
        if (!dsc->p1 || !dsc->p2)
            return;

        /*Add a line mask that keeps the area below the line*/
        lv_draw_mask_line_param_t line_mask_param;
        lv_draw_mask_line_points_init(&line_mask_param, dsc->p1->x, dsc->p1->y, dsc->p2->x, dsc->p2->y, LV_DRAW_MASK_LINE_SIDE_BOTTOM);
        int16_t line_mask_id = lv_draw_mask_add(&line_mask_param, NULL);

        // /*Add a fade effect: transparent bottom covering top*/
        lv_coord_t h = lv_obj_get_height(obj);
        lv_draw_mask_fade_param_t fade_mask_param;
        lv_draw_mask_fade_init(&fade_mask_param, &obj->coords, LV_OPA_COVER, obj->coords.y1 + h / 8, LV_OPA_TRANSP,obj->coords.y2);
        int16_t fade_mask_id = lv_draw_mask_add(&fade_mask_param, NULL);

        /*Draw a rectangle that will be affected by the mask*/
        lv_draw_rect_dsc_t draw_rect_dsc;
        lv_draw_rect_dsc_init(&draw_rect_dsc);
        draw_rect_dsc.bg_opa = LV_OPA_70;
        draw_rect_dsc.bg_color = dsc->line_dsc->color;

        lv_area_t area;
        area.x1 = dsc->p1->x;
        area.x2 = dsc->p2->x;
        area.y1 = LV_MIN(dsc->p1->y, dsc->p2->y);
        area.y2 = obj->coords.y2 - 13; /* -13 cuts off where the rectangle draws over the chart margin. Without this an area of 0 doesnt look like 0 */
        lv_draw_rect(dsc->draw_ctx, &draw_rect_dsc, &area);

        /*Remove the mask*/
        lv_draw_mask_free_param(&line_mask_param);
        lv_draw_mask_remove_id(line_mask_id);
        lv_draw_mask_remove_id(fade_mask_id);
    }
}

/**
 * Helper function to round a fixed point number
 **/
int32_t round_fixed_point(int32_t n, int8_t shift)
{
    /* Create a bitmask to isolates the decimal part of the fixed point number */
    int32_t mask = 1;
    for (int32_t bit_pos = 0; bit_pos < shift; bit_pos++)
    {
        mask = (mask << 1) + 1;
    }

    int32_t decimal_part = n & mask;

    /* Get 0.5 as fixed point */
    int32_t rounding_boundary = 1 << (shift - 1);

    /* Return either the integer part of n or the integer part + 1 */
    return (decimal_part < rounding_boundary) ? (n & ~mask) : ((n >> shift) + 1) << shift;
}



void home_normal_set_hotend_temper(int16_t curTemper, int16_t targetTemper)
{
    char buff[10] = {0};
    sprintf(buff, "%d", curTemper);
    hotend_temper = curTemper;
    //lv_label_set_text(ui_LabelHotendTemperNormal, buff);
    lv_label_set_text(ui_LabelHotendCurTemperNormal, buff);

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelHotendTargetTemperNormal, buff);
    lv_chart_set_next_value(ui_ChartTemperNormal, series_hotend, curTemper);
    if ( lv_obj_has_flag(ui_ScreenHomePageNormal, LV_OBJ_FLAG_HIDDEN) )
        lv_chart_refresh(ui_ChartTemperNormal);

    static int JudgeNozzleHeatingcount = 0;
    if(targetTemper == 0)
    {
        ShowHotendHeatingStatus(false);
        return;
    }
    if(abs(curTemper - targetTemper) <= 2)
    {
        JudgeNozzleHeatingcount++;
        if(JudgeNozzleHeatingcount >= 30)
        {
            JudgeNozzleHeatingcount = 0;
            ShowHotendHeatingStatus(false);
        }
        else
        {
            if (!lv_obj_has_flag(ui_ImageHotendHeatingToNormal, LV_OBJ_FLAG_HIDDEN))
            {
                lv_obj_align_to(ui_LabelHotendCurTemperNormal, ui_ImageHotendHeatingToNormal, LV_ALIGN_OUT_LEFT_MID, -3, 0);
            }
        }
    }
    else
    {
        JudgeNozzleHeatingcount = 0;
        ShowHotendHeatingStatus(true);
    }
}

void ShowHotendHeatingStatus(bool show)
{
    if ( show )
    { //加热状态
        //改变喷嘴转态：改变图片，改变位置        
        lv_img_set_src(ui_ImageHotendNormal, &ui_img_hotendheating_png);
        lv_obj_set_pos(ui_ImageHotendNormal, 0, 12);
        
        //改变字体颜色
        lv_obj_set_style_text_color(ui_LabelHotendCurTemperNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_LabelHotendTargetTemperNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

        //改变当前温度：改变位置
        lv_obj_align_to(ui_LabelHotendCurTemperNormal, ui_ImageHotendHeatingToNormal, LV_ALIGN_OUT_LEFT_MID, -3, 0);

        //改变箭头：改变隐藏
        lv_obj_clear_flag(ui_ImageHotendHeatingToNormal, LV_OBJ_FLAG_HIDDEN);

        //改变目标温度：改变隐藏
        if(lv_obj_has_flag(ui_LabelHotendSettingTemperNormal, LV_OBJ_FLAG_HIDDEN))
        {
            lv_obj_clear_flag(ui_LabelHotendTargetTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_align_to(ui_LabelHotendTargetTemperNormal, ui_ImageHotendHeatingToNormal, LV_ALIGN_OUT_RIGHT_MID, 2, 0);
        }

        //改变℃：改变位置
        lv_obj_set_pos(ui_LabelHotendTemperCelsiusNormal, 145, 15);

        //改变编辑温度：改变位置
        lv_obj_align_to(ui_LabelHotendSettingTemperNormal, ui_ImageHotendHeatingToNormal, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    }
    else
    { //非加热状态
        //改变喷嘴转态：改变图片，改变位置        
        lv_img_set_src(ui_ImageHotendNormal, &ui_img_hotend_png);
        lv_obj_set_pos(ui_ImageHotendNormal, 13, 12);
        
        //改变字体颜色
        lv_obj_set_style_text_color(ui_LabelHotendCurTemperNormal, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_LabelHotendTargetTemperNormal, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);

        //改变当前温度：改变位置
        lv_obj_align(ui_LabelHotendCurTemperNormal, LV_ALIGN_CENTER, 0, 0);

        //改变箭头：改变隐藏
        lv_obj_add_flag(ui_ImageHotendHeatingToNormal, LV_OBJ_FLAG_HIDDEN);

        //改变目标温度：改变隐藏
        lv_obj_add_flag(ui_LabelHotendTargetTemperNormal, LV_OBJ_FLAG_HIDDEN);

        //改变℃：改变位置
        lv_obj_set_pos(ui_LabelHotendTemperCelsiusNormal, 125, 15);

        //改变编辑温度：改变位置
        lv_obj_align(ui_LabelHotendSettingTemperNormal, LV_ALIGN_CENTER, 0, 0);
    }
}

void home_normal_set_bed_temper(int16_t curTemper, int16_t targetTemper)
{
    char buff[10] = {0};
    sprintf(buff, "%d", curTemper);
    bed_temper = curTemper;
    //lv_label_set_text(ui_LabelBedTemperNormal, buff);
    lv_label_set_text(ui_LabelBedCurTemperNormal, buff);

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelBedTargetTemperNormal, buff);
    lv_chart_set_next_value(ui_ChartTemperNormal, series_bed, curTemper);
    if ( lv_obj_has_flag(ui_ScreenHomePageNormal, LV_OBJ_FLAG_HIDDEN) )
        lv_chart_refresh(ui_ChartTemperNormal);

    static int JudgeBedHeatingcount = 0;
    if(targetTemper == 0)
    {
        ShowBedHeatingStatus(false);
        return;
    }
    if(abs(curTemper - targetTemper) <= 2)
    {
        JudgeBedHeatingcount++;
        if(JudgeBedHeatingcount >= 30)
        {
            JudgeBedHeatingcount = 0;
            ShowBedHeatingStatus(false);
        }
        else
        {
            if (!lv_obj_has_flag(ui_ImageBedHeatingToNormal, LV_OBJ_FLAG_HIDDEN))
            {
                lv_obj_align_to(ui_LabelBedCurTemperNormal, ui_ImageBedHeatingToNormal, LV_ALIGN_OUT_LEFT_MID, -3, 0);
            }
        }
    }
    else
    {
        JudgeBedHeatingcount = 0;
        ShowBedHeatingStatus(true);
    }
}

void ShowBedHeatingStatus(bool show)
{
    if ( show )
    { //加热状态
        //改变喷嘴转态：改变图片，改变位置        
        lv_img_set_src(ui_ImageBedNormal, &ui_img_bedheating_png);
        lv_obj_set_pos(ui_ImageBedNormal, 2, 17);

        //改变字体颜色
        lv_obj_set_style_text_color(ui_LabelBedCurTemperNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_LabelBedTargetTemperNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

        //改变当前温度：改变位置
        lv_obj_align_to(ui_LabelBedCurTemperNormal, ui_ImageBedHeatingToNormal, LV_ALIGN_OUT_LEFT_MID, -3, 0);

        //改变箭头：改变隐藏
        lv_obj_clear_flag(ui_ImageBedHeatingToNormal, LV_OBJ_FLAG_HIDDEN);

        //改变目标温度：改变隐藏
        if(lv_obj_has_flag(ui_LabelBedSettingTemperNormal, LV_OBJ_FLAG_HIDDEN))
        {
            lv_obj_clear_flag(ui_LabelBedTargetTemperNormal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_align_to(ui_LabelBedTargetTemperNormal, ui_ImageBedHeatingToNormal, LV_ALIGN_OUT_RIGHT_MID, 2, 0);
        }

        //改变℃：改变位置
        lv_obj_set_pos(ui_LabelBedTemperCelsiusNormal, 145, 15);

        //改变编辑温度：改变位置
        lv_obj_align_to(ui_LabelBedSettingTemperNormal, ui_ImageBedHeatingToNormal, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    }
    else
    {//非加热状态
        //改变喷嘴转态：改变图片，改变位置        
        lv_img_set_src(ui_ImageBedNormal, &ui_img_bed_png);
        lv_obj_set_pos(ui_ImageBedNormal, 15, 17);

        //改变字体颜色
        lv_obj_set_style_text_color(ui_LabelBedCurTemperNormal, lv_color_hex(0x42D87E), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_LabelBedTargetTemperNormal, lv_color_hex(0x42D87E), LV_PART_MAIN | LV_STATE_DEFAULT);

        //改变当前温度：改变位置
        lv_obj_align(ui_LabelBedCurTemperNormal, LV_ALIGN_CENTER, 0, 0);

        //改变箭头：改变隐藏
        lv_obj_add_flag(ui_ImageBedHeatingToNormal, LV_OBJ_FLAG_HIDDEN);

        //改变目标温度：改变隐藏
        lv_obj_add_flag(ui_LabelBedTargetTemperNormal, LV_OBJ_FLAG_HIDDEN);

        //改变℃：改变位置
        lv_obj_set_pos(ui_LabelBedTemperCelsiusNormal, 125, 15);

        //改变编辑温度：改变位置
        lv_obj_align(ui_LabelBedSettingTemperNormal, LV_ALIGN_CENTER, 0, 0);
    }
}

void home_normal_set_chamber_temper(int16_t curTemper)
{
    CrLogI("set the chamber temperature in homenormal page");
    //TODO:腔体温度设置，待后期扩展
    // char tempbuff[100] = {0};
    // sprintf(tempbuff, "%d", curTemper);
    //lv_label_set_text(ui_LabelChamberTemperNormal, tempbuff);
}

void home_normal_set_fan_status(bool open)
{
    fan_opened = open;
    if ( ui_ImageFanNormal )
        fan_opened ? lv_obj_add_flag(ui_ImageFanNormal, LV_OBJ_FLAG_HIDDEN) : 
                     lv_obj_clear_flag(ui_ImageFanNormal, LV_OBJ_FLAG_HIDDEN);
        
    if ( ui_GifFanNormal )
        fan_opened ? lv_obj_clear_flag(ui_GifFanNormal, LV_OBJ_FLAG_HIDDEN) : 
                     lv_obj_add_flag(ui_GifFanNormal, LV_OBJ_FLAG_HIDDEN);
}

void home_normal_set_light_status(bool open)
{
    light_opened = open;
    // if ( light_opened )
    //     lv_img_set_src(ui_ImageLightNormal, &ui_img_lightopened_png);
    // else
    //     lv_img_set_src(ui_ImageLightNormal, &ui_img_lightclosed_png);
}

void home_normal_refresh_laserstate(int laser_state)
{
    if(laser_state)
        lv_obj_clear_flag(ui_ImageLaserState, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageLaserState, LV_OBJ_FLAG_HIDDEN);
}

void home_normal_refresh_camerastate(int camera_state)
{
    if(camera_state)
        lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
}

void home_normal_set_wifi_status(int intensity)
{
    int level = 0;
    if (intensity <= MIN_RSSI)
    {
        level = 0;
    } 
    else if (intensity >= MAX_RSSI)
    {
        level = RSSI_LEVELS - 1;
    }
    else
    {
        float inputRange = (MAX_RSSI - MIN_RSSI);
        float outputRange = (RSSI_LEVELS - 1);
        level = (int)((float)(intensity - MIN_RSSI) * outputRange / inputRange);
    }
    switch (level)
    {
        case 0:lv_img_set_src(ui_ImageWifiNormal, &ui_img_wifinosignel_png);break;
        case 1:lv_img_set_src(ui_ImageWifiNormal, &ui_img_wifismall_png);break;
        case 2:lv_img_set_src(ui_ImageWifiNormal, &ui_img_wifimid_png);break;
        case 3:lv_img_set_src(ui_ImageWifiNormal, &ui_img_wififull_png);break;
        default:lv_img_set_src(ui_ImageWifiNormal, &ui_img_wififull_png);break;
    }
    wifi_Intensity = intensity;
}


void home_normal_set_print_status(int8_t print_status)
{
    // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
    // if ( (print_status == 2) || (print_status == 3) )
    // {
    //     if ( lv_obj_is_visible(ui_ScreenHomePageNormal) )
    //         LoadHomePrintingScreen();
    // }
}

void key_reminder_callback(int reminder)
{
    if ( !reminder )  //
    {
        send_set_buzzer_cmd(); //send_buzzer(0x01);
    }
}

/**
 * @description:  改变正常首页编码器的导航对象
 * @return {void}
 * @param {levelIndex: 表示导航对象的等级，IsEntered：是否进入}
 */
void LoadHomeNormalPageAndObjs(bool IsEntered)
{
    HomePageNormalManage.stateValue = IsEntered;
   // ScreenStatusValue = IsEntered;
    if(HomePageNormalManage.stateValue == 0) //一级页面导航模式
    {
        //PageMenuChange(MENU_RETURN, MENU_LEVEL_2, NULL);
        // printf("ScreenStatusValue = 0\n");
        LoadPage(ui_ScreenHomePageNormal, 1);
        lv_obj_set_style_bg_img_src(ui_ButtonHomePageNormal, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_group_focus_cycle(encoder_group, true);
    }
    else //二级页面导航模式
    {    
        // printf("ScreenStatusValue = 1\n");
        //PageMenuChange(MENU_ENTER, MENU_LEVEL_1, ui_ButtonHomePageNormal);
        LoadPage(ui_ScreenHomePageNormal, 2);
        // if(lv_group_get_focused(encoder_group) == ui_ButtonHomePageNormal)
        // {
        //     lv_obj_set_style_bg_img_src(ui_ButtonHomePageNormal, &ui_img_pagehomefocus_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        // }
        // else
        // {
        //     lv_obj_set_style_bg_img_src(ui_ButtonHomePageNormal, &ui_img_pagehomeselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        // }
        lv_obj_set_style_bg_img_src(ui_ButtonHomePageNormal, &ui_img_pagehomeselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_group_focus_cycle(encoder_group, false);
    }
}


static void HomeNormalPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    // lv_indev_set_group(enc_indev, NULL); 
    // lv_indev_set_group(enc_indev, encoder_group); //关联组
    PageNode *HomeNormalPage_node = find_page(ui_ScreenHomePageNormal);
    HomeNormalPage_node->nav_level = index;
    // page_manager.objFreezzFlag = false;

    switch (index)
    {
    case 1: //1级事件组
        lv_group_add_obj( encoder_group, ui_ButtonHomePageNormal);
        lv_group_add_obj( encoder_group, ui_ButtonAxisMoveNormal);
        lv_group_add_obj( encoder_group, ui_ButtonFIleManageNormal);
        lv_group_add_obj( encoder_group, ui_ButtonSettingsNormal);
        lv_group_add_obj( encoder_group, ui_ButtonReserveNormal);
        break;
    case 2: //2级事件组
        lv_group_add_obj( encoder_group, ui_ButtonHomePageNormal);
        lv_group_add_obj( encoder_group, ui_PanelHotendTempNormal);
        lv_group_add_obj( encoder_group, ui_PanelBedTempNormal);
        //lv_group_add_obj( encoder_group, ui_PanelLightStatus);
        lv_group_add_obj( encoder_group, ui_PanelFanStatus);
        break;
    case 3: //3级事件组
        if (add_3rd_level_nav_objs)
        {
            add_3rd_level_nav_objs();
        }
        break;
    default:
        break;
    }
 
}

