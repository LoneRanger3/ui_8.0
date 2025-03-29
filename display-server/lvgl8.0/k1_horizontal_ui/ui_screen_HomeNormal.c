#include "ui_screen_HomeNormal.h"
#include "ui_screen_AxisMove.h"
#include "ui_screen_FileManage.h"
#include <stdio.h>
#include <string.h>
#include "ui_custom_numbers_keys.h"
#include "ui_custom_messagebox.h"
#include "../custom/lvgl_cmd.h"
#include "ui_Screen_Settings.h"
#include "ui_Screen_CustomerService.h"
#include "mult_language.h"

/********Home Normal Page***********/
static lv_obj_t * ui_ScreenHomePageNormal;
/******************Home Normal Page left panel***********************************/
static lv_obj_t * ui_PanelPageNormal;
static lv_obj_t * ui_ImageHomePageNormal;
static lv_obj_t * ui_ButtonAxisMoveNormal;
static lv_obj_t * ui_ButtonFIleManageNormal;
static lv_obj_t * ui_ButtonSettingsNormal;
static lv_obj_t * ui_ButtonReserveNormal;

/******************Home Normal Page right panel ***********************************/
static lv_obj_t * ui_PanelTemperChartNormal;
/******************Home Normal Page right panel chart***********************************/
static lv_obj_t * ui_StatePanel;
static lv_obj_t * ui_ImageWifiNormal;
static lv_obj_t * ui_ImageCamerastate;
static lv_obj_t * ui_ImageFilamentStateIcon;
static lv_obj_t * ui_ImageSilentModeStateIcon;
static lv_obj_t * ui_LabelTemperUnitNormal;
static lv_obj_t * ui_ChartTemperNormal;

/******************Home Normal Page right panel hotend temper control***********************************/
static lv_obj_t * ui_PanelTemperInfoNormal;
static lv_obj_t * ui_ImageCompanyNormal;
static lv_obj_t * ui_PanelHotendTempNormal;
static lv_obj_t * ui_ImageHotendNormal;
static lv_obj_t * ui_LabelHotendTemperNormal;
static lv_obj_t * ui_LabelHotendTemperCelsiusNormal;

static lv_obj_t * ui_PanelHotendHeatingNormal;
static lv_obj_t * ui_ImageHotendHeatingNormal;
static lv_obj_t * ui_LabelHotendzCurTemperNormal;
static lv_obj_t * ui_LabelHotendHeatingTemperCelsiusNormal;
static lv_obj_t * ui_LabelHotendTargetTemperNormal;
static lv_obj_t * ui_ImageHotendHeatingToNormal;

/******************Home Normal Page right panel bed temper control***********************************/
static lv_obj_t * ui_PanelBedTempNormal;
static lv_obj_t * ui_ImageBedNormal;
static lv_obj_t * ui_LabelBedTemperNormal;
static lv_obj_t * ui_LabelBedTemperCelsiusNormal;
static lv_obj_t * ui_PanelLineNormal;

static lv_obj_t * ui_PanelChamberTempNormal;
static lv_obj_t * ui_ImageChamberNormal;
static lv_obj_t * ui_LabelChamberTemperNormal;
static lv_obj_t * ui_LabelChamberTemperCelsiusNormal;

static lv_obj_t * ui_PanelBedHeatingNormal;
static lv_obj_t * ui_ImageBedHeatingNormal;
static lv_obj_t * ui_LabelBedCurTemperNormal;
static lv_obj_t * ui_ImageBedHeatingToNormal;
static lv_obj_t * ui_LabelBedTargetTemperNormal;
static lv_obj_t * ui_LabelBedHeatingTemperCelsiusNormal;

/******************Home Normal Page right panel light and fan***********************************/
static lv_obj_t * ui_PanelStatusNormal;
static lv_obj_t * ui_PanelLightStatus;
static lv_obj_t * ui_ImageLightNormal;
static lv_obj_t * ui_PanelStatusLineNormal;
static lv_obj_t * ui_PanelFanStatus;
static lv_obj_t * ui_ImageFanNormal;
static lv_obj_t * ui_GifFanNormal;

/******************Home Normal Page right panel Select Files***********************************/
static lv_obj_t * ui_PanelSelectFileNormal;
static lv_obj_t * ui_ButtonSelectPrintFileNormal;


/****************************custom varants****************************/
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

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif



/***********home normal page event ************************/
static void ui_event_ButtonAxisMoveNormal(lv_event_t * e);
static void ui_event_ButtonFIleManageNormal(lv_event_t * e);
static void ui_event_ButtonSettingsNormal(lv_event_t * e);
static void ui_event_ButtonReserveNormal(lv_event_t * e);
static void ui_event_PanelHotendTempNormal(lv_event_t * e);
static void ui_event_PanelBedTempNormal(lv_event_t * e);
static void ui_event_ImageLightNormal(lv_event_t * e);
static void ui_event_ImageFanNormal(lv_event_t * e);
static void ui_event_ButtonSelectPrintFileNormal(lv_event_t * e);
static void ui_event_HomeNormalPageload(lv_event_t * e);

/***********home normal page event ************************/
static void homePageNormalAxisMoveBtnClicked(lv_event_t * e);
static void homePageNormFileManageBtnClicked(lv_event_t * e);
static void homePageNormalReserveBtnClicked(lv_event_t * e);
static void HomePageNormalHotendClicked(lv_event_t * e);
static void homePageNormalSettingBtnClicked(lv_event_t * e);
static void HomePageNormalBedClicked(lv_event_t * e);
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

/***************************************************/
/********Home Normal Page***********/
void ui_event_ButtonAxisMoveNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        homePageNormalAxisMoveBtnClicked(e);
    }
}
void ui_event_ButtonFIleManageNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        homePageNormFileManageBtnClicked(e);
    }
}
void ui_event_ButtonSettingsNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        homePageNormalSettingBtnClicked(e);
    }
}
void ui_event_ButtonReserveNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        homePageNormalReserveBtnClicked(e);
    }
}
void ui_event_PanelHotendTempNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageNormalHotendClicked(e);
    }
}
void ui_event_PanelBedTempNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageNormalBedClicked(e);
    }
}
void ui_event_ImageLightNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageNormalLightClicked(e);
    }
}
void ui_event_ImageFanNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageNormalFanClicked(e);
    }
}
void ui_event_ButtonSelectPrintFileNormal(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SelectPrintFileBtnNormalClicked(e);
    }
}

void ui_event_HomeNormalPageload(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load the homnormal page.");
        send_get_fans_status_cmd();
        send_get_light_status_cmd();
        send_get_wifi_status_cmd();
        get_printer_data(CONTROL_MACHINE_STATE, 2, "5"); //获取摄像头状态
#ifdef BRAZIL_CUSTOM_ORDER
        lv_obj_add_flag(ui_ImageWifiNormal, LV_OBJ_FLAG_HIDDEN);
#else

#endif
    }
}

void ui_ScreenHomePageNormal_screen_init(void)
{
    ui_ScreenHomePageNormal = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenHomePageNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenHomePageNormal, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenHomePageNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPageNormal = lv_obj_create(ui_ScreenHomePageNormal);
    lv_obj_set_width(ui_PanelPageNormal, 80);
    lv_obj_set_height(ui_PanelPageNormal, 480);
    lv_obj_clear_flag(ui_PanelPageNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelPageNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageHomePageNormal = lv_img_create(ui_PanelPageNormal);
    lv_img_set_src(ui_ImageHomePageNormal, &ui_img_pagehomeselected_png);
    lv_obj_set_width(ui_ImageHomePageNormal, 80);
    lv_obj_set_height(ui_ImageHomePageNormal, LV_SIZE_CONTENT);    /// 92
    lv_obj_set_x(ui_ImageHomePageNormal, -22);
    lv_obj_set_y(ui_ImageHomePageNormal, -22);
    lv_obj_add_flag(ui_ImageHomePageNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHomePageNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonAxisMoveNormal = lv_btn_create(ui_PanelPageNormal);
    lv_obj_set_width(ui_ButtonAxisMoveNormal, 80);
    lv_obj_set_height(ui_ButtonAxisMoveNormal, 96);
    lv_obj_set_x(ui_ButtonAxisMoveNormal, -22);
    lv_obj_set_y(ui_ButtonAxisMoveNormal, 74);
    lv_obj_add_flag(ui_ButtonAxisMoveNormal, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonAxisMoveNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonAxisMoveNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveNormal, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMoveNormal, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveNormal, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonFIleManageNormal = lv_btn_create(ui_PanelPageNormal);
    lv_obj_set_width(ui_ButtonFIleManageNormal, 80);
    lv_obj_set_height(ui_ButtonFIleManageNormal, 96);
    lv_obj_set_x(ui_ButtonFIleManageNormal, -22);
    lv_obj_set_y(ui_ButtonFIleManageNormal, 170);
    lv_obj_add_flag(ui_ButtonFIleManageNormal, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFIleManageNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonFIleManageNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonFIleManageNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonFIleManageNormal, &ui_img_pagefilemanage_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonFIleManageNormal, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonFIleManageNormal, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonFIleManageNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonSettingsNormal = lv_btn_create(ui_PanelPageNormal);
    lv_obj_set_width(ui_ButtonSettingsNormal, 80);
    lv_obj_set_height(ui_ButtonSettingsNormal, 96);
    lv_obj_set_x(ui_ButtonSettingsNormal, -22);
    lv_obj_set_y(ui_ButtonSettingsNormal, 266);
    lv_obj_add_flag(ui_ButtonSettingsNormal, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonSettingsNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonSettingsNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsNormal, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsNormal, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSettingsNormal, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSettingsNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonReserveNormal = lv_btn_create(ui_PanelPageNormal);
    lv_obj_set_width(ui_ButtonReserveNormal, 80);
    lv_obj_set_height(ui_ButtonReserveNormal, 96);
    lv_obj_set_x(ui_ButtonReserveNormal, -22);
    lv_obj_set_y(ui_ButtonReserveNormal, 362);
    lv_obj_add_flag(ui_ButtonReserveNormal, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonReserveNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonReserveNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonReserveNormal, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveNormal, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonReserveNormal, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonReserveNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_PanelTemperChartNormal = lv_obj_create(ui_ScreenHomePageNormal);
    lv_obj_set_width(ui_PanelTemperChartNormal, 484);
    lv_obj_set_height(ui_PanelTemperChartNormal, 460);
    lv_obj_set_x(ui_PanelTemperChartNormal, 90);
    lv_obj_set_y(ui_PanelTemperChartNormal, 10);
    lv_obj_clear_flag(ui_PanelTemperChartNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelTemperChartNormal, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTemperChartNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelTemperChartNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelTemperChartNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StatePanel = lv_obj_create(ui_PanelTemperChartNormal);
    lv_obj_set_width(ui_StatePanel, 484);
    lv_obj_set_height(ui_StatePanel, 50);
    lv_obj_align(ui_StatePanel, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_clear_flag(ui_StatePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_StatePanel, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StatePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_StatePanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_StatePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_StatePanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_StatePanel, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_AROUND);
    lv_obj_set_style_pad_column(ui_StatePanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageFilamentStateIcon = lv_img_create(ui_StatePanel);
    char imgsrc[256] = {0};
    snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "filamentTip.png");
    lv_img_set_src(ui_ImageFilamentStateIcon, imgsrc);
    lv_obj_set_width(ui_ImageFilamentStateIcon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageFilamentStateIcon, LV_SIZE_CONTENT);

    ui_ImageSilentModeStateIcon = lv_img_create(ui_StatePanel);
    char imgsrc1[256] = {0};
    snprintf(imgsrc1, 256, "S:%s/%s", GetK1ImageResourcePtah(), "silentmode.png");
    lv_img_set_src(ui_ImageSilentModeStateIcon, imgsrc1);
    lv_obj_set_width(ui_ImageSilentModeStateIcon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageSilentModeStateIcon, LV_SIZE_CONTENT);

    ui_ImageCamerastate = lv_img_create(ui_StatePanel);
    lv_obj_set_width(ui_ImageCamerastate, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageCamerastate, LV_SIZE_CONTENT);
    lv_img_set_src(ui_ImageCamerastate, &ui_img_camera_png);
    lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageWifiNormal = lv_img_create(ui_StatePanel);
    home_normal_set_wifi_status(wifi_Intensity);
    lv_obj_set_width(ui_ImageWifiNormal, 46);
    lv_obj_set_height(ui_ImageWifiNormal, 46);
    lv_obj_add_flag(ui_ImageWifiNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageWifiNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelTemperUnitNormal = lv_label_create(ui_PanelTemperChartNormal);
    lv_obj_set_width(ui_LabelTemperUnitNormal, 30);
    lv_obj_set_height(ui_LabelTemperUnitNormal, 27);
    lv_obj_align(ui_LabelTemperUnitNormal, LV_ALIGN_TOP_LEFT, 25, 15);
    lv_label_set_text(ui_LabelTemperUnitNormal, "°C");
    lv_obj_clear_flag(ui_LabelTemperUnitNormal, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags
    lv_obj_set_style_text_color(ui_LabelTemperUnitNormal, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTemperUnitNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTemperUnitNormal, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTemperUnitNormal, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChartTemperNormal = lv_chart_create(ui_PanelTemperChartNormal);
    lv_obj_set_width(ui_ChartTemperNormal, 430);
    lv_obj_set_height(ui_ChartTemperNormal, 382);
    lv_obj_align(ui_ChartTemperNormal, LV_ALIGN_TOP_LEFT, 50, 52);
    lv_chart_set_type(ui_ChartTemperNormal, LV_CHART_TYPE_LINE); 
    //lv_obj_set_style_bg_color(ui_ChartTemperNormal, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChartTemperNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChartTemperNormal, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelTemperInfoNormal = lv_obj_create(ui_ScreenHomePageNormal);
    lv_obj_set_width(ui_PanelTemperInfoNormal, 206);
    lv_obj_set_height(ui_PanelTemperInfoNormal, 460);
    lv_obj_set_x(ui_PanelTemperInfoNormal, 584);
    lv_obj_set_y(ui_PanelTemperInfoNormal, 10);
    lv_obj_clear_flag(ui_PanelTemperInfoNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelTemperInfoNormal, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTemperInfoNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelTemperInfoNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelTemperInfoNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageCompanyNormal = lv_img_create(ui_PanelTemperInfoNormal);
    lv_img_set_src(ui_ImageCompanyNormal, &ui_img_company_png);
    lv_obj_set_width(ui_ImageCompanyNormal, 155);
    lv_obj_set_height(ui_ImageCompanyNormal, 20);
    lv_obj_align(ui_ImageCompanyNormal, LV_ALIGN_TOP_MID, 0, 25);
    lv_obj_add_flag(ui_ImageCompanyNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCompanyNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ImageCompanyNormal, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ImageCompanyNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelHotendTempNormal = lv_obj_create(ui_PanelTemperInfoNormal);
    lv_obj_set_width(ui_PanelHotendTempNormal, 170);
    lv_obj_set_height(ui_PanelHotendTempNormal, 50);
    lv_obj_align(ui_PanelHotendTempNormal, LV_ALIGN_TOP_MID, 0, 76);
    lv_obj_clear_flag(ui_PanelHotendTempNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelHotendTempNormal, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHotendTempNormal, lv_color_hex(0x0D0D0D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotendTempNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelHotendTempNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelHotendTempNormal, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelHotendTempNormal, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelHotendTempNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelHotendTempNormal, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageHotendNormal = lv_img_create(ui_PanelHotendTempNormal);
    lv_img_set_src(ui_ImageHotendNormal, &ui_img_hotend_png);
    lv_obj_set_width(ui_ImageHotendNormal, 33);
    lv_obj_set_height(ui_ImageHotendNormal, 33);
    lv_obj_set_x(ui_ImageHotendNormal, 3);
    lv_obj_set_y(ui_ImageHotendNormal, -14);
    lv_obj_add_flag(ui_ImageHotendNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageHotendNormal, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageHotendNormal, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageHotendNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor(ui_ImageHotendNormal, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_img_recolor_opa(ui_ImageHotendNormal, 100, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_LabelHotendTemperNormal = lv_label_create(ui_PanelHotendTempNormal);
    lv_obj_set_width(ui_LabelHotendTemperNormal, 47);
    lv_obj_set_height(ui_LabelHotendTemperNormal, 30);
    lv_obj_set_x(ui_LabelHotendTemperNormal, 43);
    lv_obj_set_y(ui_LabelHotendTemperNormal, -16);
    lv_label_set_text(ui_LabelHotendTemperNormal, "");
    lv_obj_set_style_text_color(ui_LabelHotendTemperNormal, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTemperNormal, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelHotendTemperCelsiusNormal = lv_label_create(ui_PanelHotendTempNormal);
    lv_obj_set_width(ui_LabelHotendTemperCelsiusNormal, 25);
    lv_obj_set_height(ui_LabelHotendTemperCelsiusNormal, 30);
    lv_obj_set_x(ui_LabelHotendTemperCelsiusNormal, 90);
    lv_obj_set_y(ui_LabelHotendTemperCelsiusNormal, -10);
    lv_label_set_text(ui_LabelHotendTemperCelsiusNormal, "°C");
    lv_obj_set_style_text_color(ui_LabelHotendTemperCelsiusNormal, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTemperCelsiusNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendTemperCelsiusNormal, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTemperCelsiusNormal, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelHotendHeatingNormal = lv_obj_create(ui_PanelTemperInfoNormal);  //ui_PanelTemperInfo
    lv_obj_set_width(ui_PanelHotendHeatingNormal, 170);
    lv_obj_set_height(ui_PanelHotendHeatingNormal, 50);
    lv_obj_align(ui_PanelHotendHeatingNormal, LV_ALIGN_TOP_MID, 0, 76);
    lv_obj_clear_flag(ui_PanelHotendHeatingNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelHotendHeatingNormal, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHotendHeatingNormal, lv_color_hex(0x0D0D0D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotendHeatingNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelHotendHeatingNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelHotendHeatingNormal, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelHotendHeatingNormal, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelHotendHeatingNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelHotendHeatingNormal, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_add_flag(ui_PanelHotendHeatingNormal, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_ImageHotendHeatingNormal = lv_img_create(ui_PanelHotendHeatingNormal);
    lv_img_set_src(ui_ImageHotendHeatingNormal, &ui_img_hotendheating_png);
    lv_obj_set_width(ui_ImageHotendHeatingNormal, 28);
    lv_obj_set_height(ui_ImageHotendHeatingNormal, 28);
    lv_obj_set_x(ui_ImageHotendHeatingNormal, -15);
    lv_obj_set_y(ui_ImageHotendHeatingNormal, -11);
    lv_obj_add_flag(ui_ImageHotendHeatingNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendHeatingNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageHotendHeatingNormal, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageHotendHeatingNormal, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageHotendHeatingNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor(ui_ImageHotendHeatingNormal, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_img_recolor_opa(ui_ImageHotendHeatingNormal, 100, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_LabelHotendzCurTemperNormal = lv_label_create(ui_PanelHotendHeatingNormal);
    lv_obj_set_width(ui_LabelHotendzCurTemperNormal, 42);
    lv_obj_set_height(ui_LabelHotendzCurTemperNormal, 33);
    lv_obj_set_x(ui_LabelHotendzCurTemperNormal, 10);
    lv_obj_set_y(ui_LabelHotendzCurTemperNormal, -11);
    lv_label_set_text(ui_LabelHotendzCurTemperNormal, "");
    lv_obj_set_style_text_color(ui_LabelHotendzCurTemperNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendzCurTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendzCurTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendzCurTemperNormal, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelHotendHeatingTemperCelsiusNormal = lv_label_create(ui_PanelHotendHeatingNormal);
    lv_obj_set_width(ui_LabelHotendHeatingTemperCelsiusNormal, 30);
    lv_obj_set_height(ui_LabelHotendHeatingTemperCelsiusNormal, 30);
    lv_obj_set_x(ui_LabelHotendHeatingTemperCelsiusNormal, 114);
    lv_obj_set_y(ui_LabelHotendHeatingTemperCelsiusNormal, -5);
    lv_label_set_text(ui_LabelHotendHeatingTemperCelsiusNormal, "°C");
    lv_obj_set_style_text_color(ui_LabelHotendHeatingTemperCelsiusNormal, lv_color_hex(0x515459),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendHeatingTemperCelsiusNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendHeatingTemperCelsiusNormal, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendHeatingTemperCelsiusNormal, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelHotendTargetTemperNormal = lv_label_create(ui_PanelHotendHeatingNormal);
    lv_obj_set_width(ui_LabelHotendTargetTemperNormal, 42);
    lv_obj_set_height(ui_LabelHotendTargetTemperNormal, 33);
    lv_obj_set_x(ui_LabelHotendTargetTemperNormal, 72);
    lv_obj_set_y(ui_LabelHotendTargetTemperNormal, -11);
    lv_label_set_text(ui_LabelHotendTargetTemperNormal, "");
    lv_obj_set_style_text_color(ui_LabelHotendTargetTemperNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTargetTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendTargetTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTargetTemperNormal, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageHotendHeatingToNormal = lv_img_create(ui_PanelHotendHeatingNormal);
    lv_img_set_src(ui_ImageHotendHeatingToNormal, &ui_img_totarget_png);
    lv_obj_set_width(ui_ImageHotendHeatingToNormal, 16);
    lv_obj_set_height(ui_ImageHotendHeatingToNormal, 15);
    lv_obj_set_x(ui_ImageHotendHeatingToNormal, 53);
    lv_obj_set_y(ui_ImageHotendHeatingToNormal, -2);
    lv_obj_add_flag(ui_ImageHotendHeatingToNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendHeatingToNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageHotendHeatingToNormal, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageHotendHeatingToNormal, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageHotendHeatingToNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor(ui_ImageHotendHeatingToNormal, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_img_recolor_opa(ui_ImageHotendHeatingToNormal, 100, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_PanelBedTempNormal = lv_obj_create(ui_PanelTemperInfoNormal);
    lv_obj_set_width(ui_PanelBedTempNormal, 170);
    lv_obj_set_height(ui_PanelBedTempNormal, 50);
    lv_obj_align(ui_PanelBedTempNormal, LV_ALIGN_TOP_MID, 0, 148);
    lv_obj_clear_flag(ui_PanelBedTempNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelBedTempNormal, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelBedTempNormal, lv_color_hex(0x0D0D0D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBedTempNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBedTempNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelBedTempNormal, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelBedTempNormal, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelBedTempNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelBedTempNormal, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageBedNormal = lv_img_create(ui_PanelBedTempNormal);
    lv_img_set_src(ui_ImageBedNormal, &ui_img_bed_png);
    lv_obj_set_width(ui_ImageBedNormal, 33);
    lv_obj_set_height(ui_ImageBedNormal, 33);
    lv_obj_set_x(ui_ImageBedNormal, 3);
    lv_obj_set_y(ui_ImageBedNormal, -14);
    lv_obj_add_flag(ui_ImageBedNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBedNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageBedNormal, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageBedNormal, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageBedNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelBedTemperNormal = lv_label_create(ui_PanelBedTempNormal);
    lv_obj_set_width(ui_LabelBedTemperNormal, 47);
    lv_obj_set_height(ui_LabelBedTemperNormal, 30);
    lv_obj_set_x(ui_LabelBedTemperNormal, 43);
    lv_obj_set_y(ui_LabelBedTemperNormal, -16);
    lv_label_set_text(ui_LabelBedTemperNormal, "");
    lv_obj_set_style_text_color(ui_LabelBedTemperNormal, lv_color_hex(0x3DE4AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemperNormal, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelBedTemperCelsiusNormal = lv_label_create(ui_PanelBedTempNormal);
    lv_obj_set_width(ui_LabelBedTemperCelsiusNormal, 30);
    lv_obj_set_height(ui_LabelBedTemperCelsiusNormal, 30);
    lv_obj_set_x(ui_LabelBedTemperCelsiusNormal, 90);
    lv_obj_set_y(ui_LabelBedTemperCelsiusNormal, -10);
    lv_label_set_text(ui_LabelBedTemperCelsiusNormal, "°C");
    lv_obj_set_style_text_color(ui_LabelBedTemperCelsiusNormal, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemperCelsiusNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTemperCelsiusNormal, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemperCelsiusNormal, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelBedHeatingNormal = lv_obj_create(ui_PanelTemperInfoNormal);  //ui_PanelTemperInfo
    lv_obj_set_width(ui_PanelBedHeatingNormal, 170);
    lv_obj_set_height(ui_PanelBedHeatingNormal, 50);
    lv_obj_align(ui_PanelBedHeatingNormal, LV_ALIGN_TOP_MID, 0, 148);
    lv_obj_clear_flag(ui_PanelBedHeatingNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelBedHeatingNormal, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelBedHeatingNormal, lv_color_hex(0x0D0D0D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBedHeatingNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBedHeatingNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelBedHeatingNormal, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelBedHeatingNormal, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelBedHeatingNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelBedHeatingNormal, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_add_flag(ui_PanelBedHeatingNormal, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_ImageBedHeatingNormal = lv_img_create(ui_PanelBedHeatingNormal);
    lv_img_set_src(ui_ImageBedHeatingNormal, &ui_img_bedheating_png);
    lv_obj_set_width(ui_ImageBedHeatingNormal, 28);
    lv_obj_set_height(ui_ImageBedHeatingNormal, 28);
    lv_obj_set_x(ui_ImageBedHeatingNormal, -15);
    lv_obj_set_y(ui_ImageBedHeatingNormal, -11);
    lv_obj_add_flag(ui_ImageBedHeatingNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBedHeatingNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageBedHeatingNormal, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageBedHeatingNormal, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageBedHeatingNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelBedCurTemperNormal = lv_label_create(ui_PanelBedHeatingNormal);
    lv_obj_set_width(ui_LabelBedCurTemperNormal, 42);
    lv_obj_set_height(ui_LabelBedCurTemperNormal, 33);
    lv_obj_set_x(ui_LabelBedCurTemperNormal, 10);
    lv_obj_set_y(ui_LabelBedCurTemperNormal, -11);
    lv_label_set_text(ui_LabelBedCurTemperNormal, "");
    lv_obj_set_style_text_color(ui_LabelBedCurTemperNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedCurTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedCurTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedCurTemperNormal, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageBedHeatingToNormal = lv_img_create(ui_PanelBedHeatingNormal);
    lv_img_set_src(ui_ImageBedHeatingToNormal, &ui_img_totarget_png);
    lv_obj_set_width(ui_ImageBedHeatingToNormal, 16);
    lv_obj_set_height(ui_ImageBedHeatingToNormal, 15);
    lv_obj_set_x(ui_ImageBedHeatingToNormal, 53);
    lv_obj_set_y(ui_ImageBedHeatingToNormal, -2);
    lv_obj_add_flag(ui_ImageBedHeatingToNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBedHeatingToNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageBedHeatingToNormal, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageBedHeatingToNormal, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageBedHeatingToNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelBedTargetTemperNormal = lv_label_create(ui_PanelBedHeatingNormal);
    lv_obj_set_width(ui_LabelBedTargetTemperNormal, 42);
    lv_obj_set_height(ui_LabelBedTargetTemperNormal, 33);
    lv_obj_set_x(ui_LabelBedTargetTemperNormal, 72);
    lv_obj_set_y(ui_LabelBedTargetTemperNormal, -11);
    lv_label_set_text(ui_LabelBedTargetTemperNormal, "");
    lv_obj_set_style_text_color(ui_LabelBedTargetTemperNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTargetTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTargetTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTargetTemperNormal, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelBedHeatingTemperCelsiusNormal = lv_label_create(ui_PanelBedHeatingNormal);
    lv_obj_set_width(ui_LabelBedHeatingTemperCelsiusNormal, 30);
    lv_obj_set_height(ui_LabelBedHeatingTemperCelsiusNormal, 30);
    lv_obj_set_x(ui_LabelBedHeatingTemperCelsiusNormal, 114);
    lv_obj_set_y(ui_LabelBedHeatingTemperCelsiusNormal, -5);
    lv_label_set_text(ui_LabelBedHeatingTemperCelsiusNormal, "°C");
    lv_obj_set_style_text_color(ui_LabelBedHeatingTemperCelsiusNormal, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedHeatingTemperCelsiusNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedHeatingTemperCelsiusNormal, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedHeatingTemperCelsiusNormal, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelChamberTempNormal = lv_obj_create(ui_PanelTemperInfoNormal);
    lv_obj_set_width(ui_PanelChamberTempNormal, 170);
    lv_obj_set_height(ui_PanelChamberTempNormal, 50);
    lv_obj_align(ui_PanelChamberTempNormal, LV_ALIGN_TOP_MID, 0, 218);
    lv_obj_clear_flag(ui_PanelChamberTempNormal, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_clear_flag(ui_PanelChamberTempNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelChamberTempNormal, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelChamberTempNormal, lv_color_hex(0x0D0D0D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelChamberTempNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelChamberTempNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelChamberTempNormal, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelChamberTempNormal, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelChamberTempNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelChamberTempNormal, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_pad_all(ui_PanelChamberTempNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageChamberNormal = lv_img_create(ui_PanelChamberTempNormal);
    char tempbuff[256] = {0};
    snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "icon_chamber.png");
    lv_img_set_src(ui_ImageChamberNormal, tempbuff);
    lv_obj_set_width(ui_ImageChamberNormal, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageChamberNormal, LV_SIZE_CONTENT);
    lv_obj_align(ui_ImageChamberNormal, LV_ALIGN_LEFT_MID, 25, 0);
    lv_obj_add_flag(ui_ImageChamberNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageChamberNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageChamberNormal, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageChamberNormal, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageChamberNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelChamberTemperNormal = lv_label_create(ui_PanelChamberTempNormal);
    lv_obj_set_width(ui_LabelChamberTemperNormal, 47);
    lv_obj_set_height(ui_LabelChamberTemperNormal, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelChamberTemperNormal, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LabelChamberTemperNormal, "");
    lv_obj_set_style_text_color(ui_LabelChamberTemperNormal, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelChamberTemperNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelChamberTemperNormal, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelChamberTemperNormal, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelChamberTemperCelsiusNormal = lv_label_create(ui_PanelChamberTempNormal);
    lv_obj_set_width(ui_LabelChamberTemperCelsiusNormal, 30);
    lv_obj_set_height(ui_LabelChamberTemperCelsiusNormal, 30);
    lv_obj_align_to(ui_LabelChamberTemperCelsiusNormal, ui_LabelChamberTemperNormal, LV_ALIGN_OUT_RIGHT_BOTTOM, 5, 0);
    lv_label_set_text(ui_LabelChamberTemperCelsiusNormal, "°C");
    lv_obj_set_style_text_color(ui_LabelChamberTemperCelsiusNormal, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelChamberTemperCelsiusNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelChamberTemperCelsiusNormal, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelChamberTemperCelsiusNormal, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelLineNormal = lv_obj_create(ui_PanelTemperInfoNormal);
    lv_obj_set_width(ui_PanelLineNormal, 195);
    lv_obj_set_height(ui_PanelLineNormal, 1);
    lv_obj_align(ui_PanelLineNormal, LV_ALIGN_TOP_MID, 0, 367);
    lv_obj_clear_flag(ui_PanelLineNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelLineNormal, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLineNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelStatusNormal = lv_obj_create(ui_PanelTemperInfoNormal);
    lv_obj_set_width(ui_PanelStatusNormal, 206);
    lv_obj_set_height(ui_PanelStatusNormal, 66);
    lv_obj_align(ui_PanelStatusNormal, LV_ALIGN_TOP_MID, 0, 380);
    lv_obj_clear_flag(ui_PanelStatusNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelStatusNormal, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelStatusNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelStatusNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelStatusNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelLightStatus = lv_obj_create(ui_PanelStatusNormal);
    lv_obj_set_width(ui_PanelLightStatus, 102);
    lv_obj_set_height(ui_PanelLightStatus, 66);
    lv_obj_align(ui_PanelLightStatus, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_style_pad_all(ui_PanelLightStatus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_PanelLightStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//    lv_obj_clear_flag(ui_PanelFanStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelLightStatus, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelLightStatus, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelLightStatus, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelLightStatus, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_PanelLightStatus, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelLightStatus, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelLightStatus, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelLightStatus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageLightNormal = lv_img_create(ui_PanelLightStatus);
    lv_obj_set_width(ui_ImageLightNormal, 66);
    lv_obj_set_height(ui_ImageLightNormal, 66);
    lv_obj_set_align(ui_ImageLightNormal, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ImageLightNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    home_normal_set_light_status(light_opened);

    ui_PanelStatusLineNormal = lv_obj_create(ui_PanelStatusNormal);
    lv_obj_set_width(ui_PanelStatusLineNormal, 1);
    lv_obj_set_height(ui_PanelStatusLineNormal, 66);
    lv_obj_align(ui_PanelStatusLineNormal, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_clear_flag(ui_PanelStatusLineNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelStatusLineNormal, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelStatusLineNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelFanStatus = lv_obj_create(ui_PanelStatusNormal);
    lv_obj_set_width(ui_PanelFanStatus, 100);
    lv_obj_set_height(ui_PanelFanStatus, 66);
    lv_obj_align(ui_PanelFanStatus, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_clear_flag(ui_PanelFanStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//    lv_obj_clear_flag(ui_PanelFanStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelFanStatus, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelFanStatus, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelFanStatus, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelFanStatus, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_PanelFanStatus, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFanStatus, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFanStatus, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelFanStatus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
 
    ui_ImageFanNormal = lv_img_create(ui_PanelFanStatus);
    lv_obj_set_width(ui_ImageFanNormal, 66);
    lv_obj_set_height(ui_ImageFanNormal, 66);
    lv_obj_set_align(ui_ImageFanNormal, LV_ALIGN_CENTER);
    // lv_obj_set_x(ui_ImageFanNormal, -8);
    // lv_obj_set_y(ui_ImageFanNormal, -12);
    //lv_obj_add_flag(ui_ImageFanNormal, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ImageFanNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(ui_ImageFanNormal, &ui_img_stop_fan_png);

    ui_GifFanNormal = lv_gif_create(ui_PanelFanStatus);
    lv_obj_set_width(ui_GifFanNormal, 66);
    lv_obj_set_height(ui_GifFanNormal, 66);
    // lv_obj_set_x(ui_GifFanNormal, -8);
    // lv_obj_set_y(ui_GifFanNormal, -12);
    lv_obj_set_align(ui_GifFanNormal, LV_ALIGN_CENTER);
    lv_gif_set_src(ui_GifFanNormal, &ui_img_HomeFan);
    lv_obj_add_flag(ui_GifFanNormal, LV_OBJ_FLAG_HIDDEN);
    //lv_obj_add_flag(ui_GifFanNormal, LV_OBJ_FLAG_EVENT_BUBBLE); 

    // ui_PanelSelectFileNormal = lv_obj_create(ui_ScreenHomePageNormal);
    // lv_obj_set_width(ui_PanelSelectFileNormal, 206);
    // lv_obj_set_height(ui_PanelSelectFileNormal, 92);
    // lv_obj_set_x(ui_PanelSelectFileNormal, 584);
    // lv_obj_set_y(ui_PanelSelectFileNormal, 378);
    // lv_obj_clear_flag(ui_PanelSelectFileNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // ui_ButtonSelectPrintFileNormal = lv_btn_create(ui_ScreenHomePageNormal);
    // lv_obj_set_width(ui_ButtonSelectPrintFileNormal, 206);
    // lv_obj_set_height(ui_ButtonSelectPrintFileNormal, 92);
    // lv_obj_set_x(ui_ButtonSelectPrintFileNormal, 584);
    // lv_obj_set_y(ui_ButtonSelectPrintFileNormal, 378);
    // lv_obj_add_flag(ui_ButtonSelectPrintFileNormal, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_ButtonSelectPrintFileNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonSelectPrintFileNormal, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonSelectPrintFileNormal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_img_src(ui_ButtonSelectPrintFileNormal, &ui_img_toprint_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_ButtonSelectPrintFileNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_ButtonSelectPrintFileNormal, lv_color_hex(0x42BDD8),
    //                               LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_ButtonSelectPrintFileNormal, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_ButtonSelectPrintFileNormal, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_side(ui_ButtonSelectPrintFileNormal, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_radius(ui_ButtonSelectPrintFileNormal, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_ButtonSelectPrintFileNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_ButtonSelectPrintFileNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_ofs_x(ui_ButtonSelectPrintFileNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_ofs_y(ui_ButtonSelectPrintFileNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ButtonAxisMoveNormal, ui_event_ButtonAxisMoveNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonFIleManageNormal, ui_event_ButtonFIleManageNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsNormal, ui_event_ButtonSettingsNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserveNormal, ui_event_ButtonReserveNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelHotendTempNormal, ui_event_PanelHotendTempNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelHotendHeatingNormal, ui_event_PanelHotendTempNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelBedHeatingNormal, ui_event_PanelBedTempNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelBedTempNormal, ui_event_PanelBedTempNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelLightStatus, ui_event_ImageLightNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelFanStatus, ui_event_ImageFanNormal, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenHomePageNormal, ui_event_HomeNormalPageload, LV_EVENT_SCREEN_LOADED, NULL);
    // lv_obj_add_event_cb(ui_ButtonSelectPrintFileNormal, ui_event_ButtonSelectPrintFileNormal, LV_EVENT_ALL, NULL);

    /**********************other opt**************************/
    lv_chart_set_div_line_count(ui_ChartTemperNormal, 0, 0);
    lv_chart_set_range(ui_ChartTemperNormal, LV_CHART_AXIS_PRIMARY_Y, -15, 300);
    lv_chart_set_axis_tick(ui_ChartTemperNormal, LV_CHART_AXIS_PRIMARY_Y, 5, 3, 8, 2, true, 100);
    lv_chart_set_range(ui_ChartTemperNormal, LV_CHART_AXIS_PRIMARY_X, 0, 200);
    lv_chart_set_point_count(ui_ChartTemperNormal, 200);
    //lv_chart_set_axis_tick(ui_ChartTemperNormal, LV_CHART_AXIS_PRIMARY_X, 5, 5, 25, 1, true, 100);
    lv_obj_set_style_size(ui_ChartTemperNormal, 0, LV_PART_INDICATOR);//将点的大小设置为0
    lv_chart_set_update_mode(ui_ChartTemperNormal, LV_CHART_UPDATE_MODE_SHIFT);
    lv_obj_set_style_border_side(ui_ChartTemperNormal, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ChartTemperNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    /*Add some data series*/
    series_bed = lv_chart_add_series(ui_ChartTemperNormal, lv_color_make(0x3C, 0xE4, 0xAA), LV_CHART_AXIS_PRIMARY_Y);
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


void LoadHomeNormalScreen(void)
{
    lv_disp_load_scr(ui_ScreenHomePageNormal);
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

void HomePageNormalHotendClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    sprintf(buff, "%s #42BDD8 %d-%d#", HotendInputRangle[get_cur_language_index()],HOTEND_MIN_EDIT_TEMPER, HOTEND_MAX_EDIT_TEMPER);
    numberskeyboardinput(buff, HOTEND_MAX_EDIT_TEMPER, HOTEND_MIN_EDIT_TEMPER,
                    hotend_edit_target_temper_callback, key_reminder_callback, 92, 0);
}

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

void HomePageNormalBedClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    if(UIType == CR_K1_Max)
    {
        int maxtemp = (IsK1MaxSe == true) ? K1_MAX_SE_BED_MAX_EDIT_TEMPER : K1_MAX_BED_MAX_EDIT_TEMPER;
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, maxtemp);
        numberskeyboardinput(buff, maxtemp, BED_MIN_EDIT_TEMPER,bed_edit_target_temper_callback, key_reminder_callback, 92, 0);        
    }
    else
    {
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, BED_MAX_EDIT_TEMPER);
        numberskeyboardinput(buff, BED_MAX_EDIT_TEMPER, BED_MIN_EDIT_TEMPER,
                bed_edit_target_temper_callback, key_reminder_callback, 92, 0);        
    }

}

void HomePageNormalLightClicked(lv_event_t * e)
{
	// Your code here
    send_set_light_opt_cmd(!light_opened);
    
}

void HomePageNormalFanClicked(lv_event_t * e)
{
	// Your code here
    uint8_t percent = 100;
    if ( fan_opened )
        percent = 0;

    // send_set_model_fan_opt_cmd(percent);
    //不再发送命令改为跳转页面
    set_current_subpage(2);
    ui_change(PAGE_AXIS);
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
    lv_label_set_text(ui_LabelHotendTemperNormal, buff);
    lv_label_set_text(ui_LabelHotendzCurTemperNormal, buff);

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelHotendTargetTemperNormal, buff);
    lv_chart_set_next_value(ui_ChartTemperNormal, series_hotend, curTemper);
    if ( lv_obj_has_flag(ui_ScreenHomePageNormal, LV_OBJ_FLAG_HIDDEN) )
        lv_chart_refresh(ui_ChartTemperNormal);

    static int JudgeNozzleHeatingcount = 0;
    if(targetTemper == 0)
    {
        show_hotend_heating_status_homenormal_page(false);
        return;
    }
    if(abs(curTemper - targetTemper) <= 2)
    {
        JudgeNozzleHeatingcount++;
        if(JudgeNozzleHeatingcount >= 30)
        {
            JudgeNozzleHeatingcount = 0;
            show_hotend_heating_status_homenormal_page(false);
        }
    }
    else
    {
        JudgeNozzleHeatingcount = 0;
        show_hotend_heating_status_homenormal_page(true);
    }
}

void show_hotend_heating_status_homenormal_page(bool show)
{
    if ( show )
    {
        lv_obj_add_flag(ui_PanelHotendTempNormal, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelHotendHeatingNormal, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(ui_PanelHotendHeatingNormal, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelHotendTempNormal, LV_OBJ_FLAG_HIDDEN);
    }
}

void home_normal_set_bed_temper(int16_t curTemper, int16_t targetTemper)
{
    char buff[10] = {0};
    sprintf(buff, "%d", curTemper);
    bed_temper = curTemper;
    lv_label_set_text(ui_LabelBedTemperNormal, buff);
    lv_label_set_text(ui_LabelBedCurTemperNormal, buff);

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelBedTargetTemperNormal, buff);
    lv_chart_set_next_value(ui_ChartTemperNormal, series_bed, curTemper);
    if ( lv_obj_has_flag(ui_ScreenHomePageNormal, LV_OBJ_FLAG_HIDDEN) )
        lv_chart_refresh(ui_ChartTemperNormal);

    static int JudgeBedHeatingcount = 0;
    if(targetTemper == 0)
    {
        show_bed_heating_status_homenormal_page(false);
        return;
    }
    if(abs(curTemper - targetTemper) <= 2)
    {
        JudgeBedHeatingcount++;
        if(JudgeBedHeatingcount >= 30)
        {
            JudgeBedHeatingcount = 0;
            show_bed_heating_status_homenormal_page(false);
        }
    }
    else
    {
        JudgeBedHeatingcount = 0;
        show_bed_heating_status_homenormal_page(true);
    }
}

void home_normal_set_chamber_temper(int16_t curTemper)
{
    CrLogI("set the chamber temperature in homenormal page");
    char tempbuff[100] = {0};
    sprintf(tempbuff, "%d", curTemper);
    lv_label_set_text(ui_LabelChamberTemperNormal, tempbuff);
}

void show_bed_heating_status_homenormal_page(bool show)
{
    if ( show )
    {
        lv_obj_add_flag(ui_PanelBedTempNormal, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelBedHeatingNormal, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(ui_PanelBedHeatingNormal, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelBedTempNormal, LV_OBJ_FLAG_HIDDEN);
    }
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
    if ( light_opened )
        lv_img_set_src(ui_ImageLightNormal, &ui_img_lightopened_png);
    else
        lv_img_set_src(ui_ImageLightNormal, &ui_img_lightclosed_png);
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

void hoem_page_refresh_camerastate(int camera_state)
{
    if(camera_state)
        lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
}

void key_reminder_callback(int reminder)
{
    if ( !reminder )  //
    {
        send_set_buzzer_cmd(); //send_buzzer(0x01);
    }
}

void change_filamentsensor_normalpage(bool state)
{
    if(state)
        lv_obj_clear_flag(ui_ImageFilamentStateIcon, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageFilamentStateIcon, LV_OBJ_FLAG_HIDDEN);
}

void change_silentmode_normal(bool state)
{
    if(state)
        lv_obj_clear_flag(ui_ImageSilentModeStateIcon, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageSilentModeStateIcon, LV_OBJ_FLAG_HIDDEN);
}

