#include "ui_screen_HomePrinting.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_Adjustment.h"
#include "ui_screen_FileManage.h"
#include <stdio.h>
#include "../custom/lvgl_cmd.h"
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"
#include "ui_Screen_Settings.h"
#include "ui_custom_print_opt_screen.h"
#include "mult_language.h"
#include "lvgl/src/misc/lv_timer.h"
#include "ui.h"
#include "ui_screen_AxisMove.h"

/********HomePrinting Page***********/
static lv_obj_t * ui_ScreenHomePagePrinting;
/***********home printing page left panel************************/
static lv_obj_t * ui_PanelPage;
static lv_obj_t * ui_ImageHomePage;
static lv_obj_t * ui_ButtonAxisMove;
static lv_obj_t * ui_ButtonFIleManage;
static lv_obj_t * ui_ButtonSettings;
static lv_obj_t * ui_ButtonReserve;

/***********home printing page right panel************************/
static lv_obj_t * ui_PanelPrintInfo;

/***********home printing page right panel print info ************************/
static lv_obj_t * ui_ImageExcludeObjectIcon;
static lv_obj_t * ui_ImageFilamentIcon;
static lv_obj_t * ui_ImageSilentModeIcon;
static lv_obj_t * ui_ImageWifiLarge;
static lv_obj_t * ui_ImageCamerastate;
static lv_obj_t * ui_LabelFileName;
static lv_obj_t * ui_ImageModelChart;
static lv_obj_t * ui_ImageChartMask;
static lv_obj_t * ui_ImageUsedTimes;
static lv_obj_t * ui_LabelPrepareTips;
static lv_obj_t * ui_LabelUsedTimes;
static lv_obj_t * ui_ImageRemainderTimes;
static lv_obj_t * ui_LabelRemainingTimes;
static lv_obj_t * ui_LabelProcess;
static lv_obj_t * ui_LabelPercentSign;
static lv_obj_t * ui_BarPrintProccess;


/***********home printing page right panel temper info ************************/
static lv_obj_t * ui_PanelTemperInfo;
static lv_obj_t * ui_ImageCompany;

static lv_obj_t * ui_PanelHotendTemp;
static lv_obj_t * ui_ImageHotend;
static lv_obj_t * ui_LabelHotendTemper;
static lv_obj_t * ui_LabelHotendTemperCelsius;

static lv_obj_t * ui_PanelBedTemp;
static lv_obj_t * ui_ImageBed;
static lv_obj_t * ui_LabelBedTemper;
static lv_obj_t * ui_LabelBedTemperCelsius;

/************喷头、热床的重叠部分**************/
static lv_obj_t * ui_StatePanelPrinting;
static lv_obj_t * ui_PanelHotendHeating;
static lv_obj_t * ui_ImageHotendHeating;
static lv_obj_t * ui_LabelHotendzCurTemper;
static lv_obj_t * ui_LabelHotendHeatingTemperCelsius;
static lv_obj_t * ui_LabelHotendTargetTemper;
static lv_obj_t * ui_ImageHotendHeatingTo;
static lv_obj_t * ui_PanelBedHeating;
static lv_obj_t * ui_ImageBedHeating;
static lv_obj_t * ui_LabelBedCurTemper;
static lv_obj_t * ui_ImageBedHeatingTo;
static lv_obj_t * ui_LabelBedTargetTemper;
static lv_obj_t * ui_LabelBedHeatingTemperCelsius;
static lv_obj_t * ui_PanelChamberTemp;
static lv_obj_t * ui_ImageChamberHeating;
static lv_obj_t * ui_LabelChamberCurTemper;
static lv_obj_t * ui_LabelChamberTemperCelsius;


static lv_obj_t * ui_PanelLine;
static lv_obj_t * ui_PanelStatus;
static lv_obj_t * ui_Panel_Lightes;
static lv_obj_t * ui_ImageLight;
static lv_obj_t * ui_PanelStatusLine;
static lv_obj_t * ui_Panel_Fans;
static lv_obj_t * ui_ImageFan;
static lv_obj_t * ui_GifFan;

/***********home printing page right panel print control ************************/
static lv_obj_t * ui_PanelPrintOpt;
static lv_obj_t * ui_ButtonPrintOpt;





/***********************custom variable********************************/
static int16_t  bed_temper_printing = -15;
static int16_t  bed_target_temper_printing = 0;
static int16_t  hotend_temper_printing = -15;
static int16_t  hotend_target_temper_printing = 0;
static bool     light_opened_printing = true;
static bool     fan_opened_printing = false;
static uint8_t  wifi_Intensity_printing = 85;
static int32_t  used_time_printing = 90;
static int32_t  remained_time_printing = 100;
static int8_t   proccess_printing = 50;
static char     file_name_printing[256] = "";//"hello world";
static char     filling_chart_name[256] = {0};
static int8_t   print_status = 1;
static bool     printing_filament_runout = false;
static uint32_t gcode_layer_count = 1;
static bool     poweloss_flag = false;
static bool     printcomplete_flag = false;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

#define SLICE_SOFTNAME "Creality"


/***********home printing page event ************************/
static void ui_event_ButtonAxisMove(lv_event_t * e);
static void ui_event_ButtonFIleManage(lv_event_t * e);
static void ui_event_ButtonSettings(lv_event_t * e);
static void ui_event_ButtonReserve(lv_event_t * e);
static void ui_event_PanelHotendTemp(lv_event_t * e);
static void ui_event_PanelBedTemp(lv_event_t * e);
static void ui_event_ImageLight(lv_event_t * e);
static void ui_event_ImageFan(lv_event_t * e);
static void ui_event_ButtonPrintOpt(lv_event_t * e);
static void ui_event_HomePrintPageload(lv_event_t * e);
static void ui_event_PanelHotendHeating(lv_event_t * e);
//static void ui_event_ImageHotendHeatingTo(lv_event_t * e);
static void ui_event_PanelBedHeating(lv_event_t * e);
static void ui_event_ExclueObject(lv_event_t * e);
//static void ui_event_ImageBedHeatingTo(lv_event_t * e);

/***********home printing page event call back ************************/
static void homePageAxisMoveBtnClicked(lv_event_t * e);
static void homePageFileManageBtnClicked(lv_event_t * e);
static void homePageSettingBtnClicked(lv_event_t * e);
static void HomePageHotendClicked(lv_event_t * e);
static void HomePageBedClicked(lv_event_t * e);
static void HomePageFanClicked(lv_event_t * e);
static void PrintOptClicked(lv_event_t * e);
static void HomePageHotendHeatingClicked(lv_event_t * e);
//void PrintPageSetHotendTargetEvent(lv_event_t * e);
static void HomePageBedHeatingClicked(lv_event_t * e);
//void PrintPageSetBedTargetEvent(lv_event_t * e);


/********************************************/
static void show_print_proccess(void);
static void show_print_used_time(void);
static void show_print_remained_time(void);
static void show_model_mask(int proccess_percent);
static void show_filling_chart(void);
static void show_printing_status(void);
static void show_printing_file_name(void);
static void printing_hotend_edit_target_temper_callback(void *param);
static void printing_bed_edit_target_temper_callback(void *param);
static void printing_pause_print_opt_callback(void);
static void printing_stop_print_opt_callback(void);
static void printing_resume_print_opt_callback(void);
static void printing_recovery_file_print_again_callback(void);
static void printing_recovery_file_stop_print_callback(void);
static void printing_replace_mater_callback();
static void printing_stop_replace_mater_callback(void);

/********HomePrinting Page 函数实现***********/
void ui_event_ButtonAxisMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        homePageAxisMoveBtnClicked(e);
    }
}

void ui_event_ButtonFIleManage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        homePageFileManageBtnClicked(e);
    }
}

void ui_event_ButtonSettings(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        homePageSettingBtnClicked(e);
    }
}

void ui_event_ButtonReserve(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        homePageReserveBtnClicked(e);
    }
}

void ui_event_PanelHotendTemp(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageHotendClicked(e);
    }
}

void ui_event_PanelBedTemp(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageBedClicked(e);
    }
}

void ui_event_ImageLight(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageLightClicked(e);
    }
}

void ui_event_ImageFan(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageFanClicked(e);
    }
}

void ui_event_ButtonPrintOpt(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PrintOptClicked(e);
    }
}

void ui_event_PanelHotendHeating(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageHotendHeatingClicked(e);
    }
}
// void ui_event_ImageHotendHeatingTo(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         PrintPageSetHotendTargetEvent(e);
//     }
// }
void ui_event_PanelBedHeating(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageBedHeatingClicked(e);
    }
}

void ui_event_ExclueObject(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ExcludeObject, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
// void ui_event_ImageBedHeatingTo(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         PrintPageSetBedTargetEvent(e);
//     }
// }
void ui_event_HomePrintPageload(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load the homeprint page");
        send_get_cur_print_gcode_info_cmd();
        send_get_fans_status_cmd();
        send_get_light_status_cmd();
        send_get_wifi_status_cmd();
        send_get_print_proccess();
        get_printer_data(CONTROL_MACHINE_STATE, 2, "5"); //获取摄像头状态
        show_printing_status();
        home_printing_set_hotend_temper(hotend_temper_printing, hotend_target_temper_printing);
        home_printing_set_bed_temper(bed_temper_printing, bed_target_temper_printing);
        show_filling_chart();
        show_model_mask(proccess_printing);
        show_printing_file_name();

#ifdef BRAZIL_CUSTOM_ORDER
        lv_obj_add_flag(ui_ImageWifiLarge, LV_OBJ_FLAG_HIDDEN);
#else

#endif
    }
}

void ui_ScreenHomePagePrinting_screen_init(void)
{
    ui_ScreenHomePagePrinting = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenHomePagePrinting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenHomePagePrinting, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenHomePagePrinting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPage = lv_obj_create(ui_ScreenHomePagePrinting);
    lv_obj_set_width(ui_PanelPage, 80);
    lv_obj_set_height(ui_PanelPage, 480);
    lv_obj_clear_flag(ui_PanelPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelPage, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageHomePage = lv_img_create(ui_PanelPage);
    lv_img_set_src(ui_ImageHomePage, &ui_img_pagehomeselected_png);
    lv_obj_set_width(ui_ImageHomePage, 80);
    lv_obj_set_height(ui_ImageHomePage, LV_SIZE_CONTENT);    /// 92
    lv_obj_set_x(ui_ImageHomePage, -22);
    lv_obj_set_y(ui_ImageHomePage, -22);
    lv_obj_add_flag(ui_ImageHomePage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHomePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonAxisMove = lv_btn_create(ui_PanelPage);
    lv_obj_set_width(ui_ButtonAxisMove, 80);
    lv_obj_set_height(ui_ButtonAxisMove, 96);
    lv_obj_set_x(ui_ButtonAxisMove, -22);
    lv_obj_set_y(ui_ButtonAxisMove, 74);
    lv_obj_add_flag(ui_ButtonAxisMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonAxisMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMove, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMove, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonAxisMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonAxisMove, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonFIleManage = lv_btn_create(ui_PanelPage);
    lv_obj_set_width(ui_ButtonFIleManage, 80);
    lv_obj_set_height(ui_ButtonFIleManage, 96);
    lv_obj_set_x(ui_ButtonFIleManage, -22);
    lv_obj_set_y(ui_ButtonFIleManage, 170);
    lv_obj_add_flag(ui_ButtonFIleManage, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFIleManage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonFIleManage, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonFIleManage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonFIleManage, &ui_img_pagefilemanage_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonFIleManage, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonFIleManage, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonFIleManage, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonSettings = lv_btn_create(ui_PanelPage);
    lv_obj_set_width(ui_ButtonSettings, 80);
    lv_obj_set_height(ui_ButtonSettings, 96);
    lv_obj_set_x(ui_ButtonSettings, -22);
    lv_obj_set_y(ui_ButtonSettings, 266);
    lv_obj_add_flag(ui_ButtonSettings, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonSettings, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonSettings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonSettings, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettings, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSettings, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSettings, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonReserve = lv_btn_create(ui_PanelPage);
    lv_obj_set_width(ui_ButtonReserve, 80);
    lv_obj_set_height(ui_ButtonReserve, 96);
    lv_obj_set_x(ui_ButtonReserve, -22);
    lv_obj_set_y(ui_ButtonReserve, 362);
    lv_obj_add_flag(ui_ButtonReserve, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserve, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonReserve, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonReserve, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonReserve, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserve, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonReserve, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonReserve, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_PanelPrintInfo = lv_obj_create(ui_ScreenHomePagePrinting);
    lv_obj_set_width(ui_PanelPrintInfo, 484);
    lv_obj_set_height(ui_PanelPrintInfo, 460);
    lv_obj_set_x(ui_PanelPrintInfo, 90);
    lv_obj_set_y(ui_PanelPrintInfo, 10);
    lv_obj_clear_flag(ui_PanelPrintInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelPrintInfo, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrintInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPrintInfo, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelPrintInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StatePanelPrinting = lv_obj_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_StatePanelPrinting, 400);
    lv_obj_set_height(ui_StatePanelPrinting, 50);
    lv_obj_align(ui_StatePanelPrinting, LV_ALIGN_TOP_LEFT, 84, 0);
    lv_obj_clear_flag(ui_StatePanelPrinting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_StatePanelPrinting, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StatePanelPrinting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_StatePanelPrinting, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_StatePanelPrinting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_StatePanelPrinting, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_StatePanelPrinting, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_AROUND);
    lv_obj_set_style_pad_column(ui_StatePanelPrinting, 10, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_ImageExcludeObjectIcon = lv_img_create(ui_PanelPrintInfo);
    char imgsrc[256] = {0};
    snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "excluceObjectIcon.png");
    lv_img_set_src(ui_ImageExcludeObjectIcon, imgsrc);
    lv_obj_set_width(ui_ImageExcludeObjectIcon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageExcludeObjectIcon, LV_SIZE_CONTENT);
    lv_obj_add_flag(ui_ImageExcludeObjectIcon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_align(ui_ImageExcludeObjectIcon, LV_ALIGN_TOP_LEFT, 17, 14);

    ui_ImageFilamentIcon = lv_img_create(ui_StatePanelPrinting);
    char imgsrc1[256] = {0};
    snprintf(imgsrc1, 256, "S:%s/%s", GetK1ImageResourcePtah(), "filamentTip.png");
    lv_img_set_src(ui_ImageFilamentIcon, imgsrc1);
    lv_obj_set_width(ui_ImageFilamentIcon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageFilamentIcon, LV_SIZE_CONTENT);

    ui_ImageSilentModeIcon = lv_img_create(ui_StatePanelPrinting);
    char imgsrc2[256] = {0};
    snprintf(imgsrc2, 256, "S:%s/%s", GetK1ImageResourcePtah(), "silentmode.png");
    lv_img_set_src(ui_ImageSilentModeIcon, imgsrc2);
    lv_obj_set_width(ui_ImageSilentModeIcon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageSilentModeIcon, LV_SIZE_CONTENT);

    ui_ImageCamerastate = lv_img_create(ui_StatePanelPrinting);
    lv_obj_set_width(ui_ImageCamerastate, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageCamerastate, LV_SIZE_CONTENT);
    lv_img_set_src(ui_ImageCamerastate, &ui_img_camera_png);
    lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageWifiLarge = lv_img_create(ui_StatePanelPrinting);
    lv_img_set_src(ui_ImageWifiLarge, &ui_img_wifinosignel_png);
    lv_obj_set_width(ui_ImageWifiLarge, 46);
    lv_obj_set_height(ui_ImageWifiLarge, 46);
    lv_obj_add_flag(ui_ImageWifiLarge, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageWifiLarge, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageModelChart = lv_img_create(ui_PanelPrintInfo);
    lv_img_set_src(ui_ImageModelChart, &ui_img_crealitylogo_png);
    lv_obj_set_width(ui_ImageModelChart, 300);
    lv_obj_set_height(ui_ImageModelChart, 300);
    lv_obj_align(ui_ImageModelChart, LV_ALIGN_TOP_MID, 0, 55);
    lv_obj_add_flag(ui_ImageModelChart, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageModelChart, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_ImageModelChart, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageChartMask = lv_img_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_ImageChartMask, 300);
    lv_obj_set_height(ui_ImageChartMask, 300);
    lv_obj_align(ui_ImageChartMask, LV_ALIGN_TOP_MID, 0, 55);
    lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageChartMask, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ImageChartMask, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ImageChartMask, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageUsedTimes = lv_img_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_ImageUsedTimes, 22);
    lv_obj_set_height(ui_ImageUsedTimes, 22);
    lv_obj_align(ui_ImageUsedTimes, LV_ALIGN_TOP_LEFT, 48, 401);
    lv_obj_clear_flag(ui_ImageUsedTimes, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(ui_ImageUsedTimes, &ui_img_home_used_png);

    ui_LabelUsedTimes = lv_label_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_LabelUsedTimes, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelUsedTimes, 24);
    lv_obj_align_to(ui_LabelUsedTimes, ui_ImageUsedTimes, LV_ALIGN_OUT_RIGHT_BOTTOM, 0, -5);
    lv_label_set_text(ui_LabelUsedTimes, "");
    lv_obj_set_style_text_color(ui_LabelUsedTimes, lv_color_hex(0x50535B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelUsedTimes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelUsedTimes, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelUsedTimes, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFileName = lv_label_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_LabelFileName, 370);
    lv_obj_set_height(ui_LabelFileName, 46);
    lv_obj_align(ui_LabelFileName, LV_ALIGN_TOP_MID, 0, 340);
    lv_obj_set_style_text_color(ui_LabelFileName, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFileName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelFileName, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LabelFileName, LV_LABEL_LONG_DOT);
    lv_obj_set_style_text_font(ui_LabelFileName, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelPrepareTips = lv_label_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_LabelPrepareTips, 395);
    lv_obj_set_height(ui_LabelPrepareTips, 28);
    lv_label_set_text(ui_LabelPrepareTips, "");
    lv_obj_align(ui_LabelPrepareTips, LV_ALIGN_TOP_MID, 0, 340);
    lv_obj_set_style_text_color(ui_LabelPrepareTips, lv_color_hex(0x50535B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelPrepareTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelPrepareTips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPrepareTips, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelRemainingTimes = lv_label_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_LabelRemainingTimes, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelRemainingTimes, 24);
    lv_obj_align(ui_LabelRemainingTimes, LV_ALIGN_TOP_RIGHT, -49, 398);
    lv_label_set_text(ui_LabelRemainingTimes, "");
    lv_label_set_recolor(ui_LabelRemainingTimes, "true");
    lv_obj_set_style_text_color(ui_LabelRemainingTimes, lv_color_hex(0x50535B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelRemainingTimes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelRemainingTimes, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelRemainingTimes, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageRemainderTimes = lv_img_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_ImageRemainderTimes, 19);
    lv_obj_set_height(ui_ImageRemainderTimes, 23);
    lv_obj_align_to(ui_ImageRemainderTimes, ui_LabelRemainingTimes, LV_ALIGN_OUT_LEFT_BOTTOM, -5, 2);
    lv_obj_clear_flag(ui_ImageRemainderTimes, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(ui_ImageRemainderTimes, &ui_img_home_remainder_png);

    ui_LabelProcess = lv_label_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_LabelProcess, 60);
    lv_obj_set_height(ui_LabelProcess, 45);
    lv_obj_align(ui_LabelProcess, LV_ALIGN_TOP_MID, 0, 390);
    lv_label_set_text(ui_LabelProcess, "");
    lv_obj_add_flag(ui_LabelProcess, LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_obj_clear_flag(ui_LabelProcess, LV_OBJ_FLAG_CLICK_FOCUSABLE);      /// Flags
    lv_obj_set_style_text_color(ui_LabelProcess, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelProcess, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelProcess, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelProcess, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelPercentSign = lv_label_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_LabelPercentSign, 24);
    lv_obj_set_height(ui_LabelPercentSign, 36);
    lv_obj_align_to(ui_LabelPercentSign, ui_LabelProcess, LV_ALIGN_OUT_RIGHT_BOTTOM, 5, -3);
    lv_label_set_text(ui_LabelPercentSign, "%");
    lv_obj_add_flag(ui_LabelPercentSign, LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_obj_set_style_text_color(ui_LabelPercentSign, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelPercentSign, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelPercentSign, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPercentSign, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BarPrintProccess = lv_bar_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_BarPrintProccess, 390);
    lv_obj_set_height(ui_BarPrintProccess, 10);
    lv_obj_align(ui_BarPrintProccess, LV_ALIGN_TOP_MID, 0, 437);
    lv_obj_set_style_bg_color(ui_BarPrintProccess, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BarPrintProccess, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BarPrintProccess, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BarPrintProccess, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_BarPrintProccess, &ui_img_proccess_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_tiled(ui_BarPrintProccess, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_BarPrintProccess, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_bar_set_mode(ui_BarPrintProccess, LV_BAR_MODE_RANGE);
    lv_bar_set_start_value(ui_BarPrintProccess, 0, LV_ANIM_OFF);

    ui_PanelTemperInfo = lv_obj_create(ui_ScreenHomePagePrinting);
    lv_obj_set_width(ui_PanelTemperInfo, 206);
    lv_obj_set_height(ui_PanelTemperInfo, 358);
    lv_obj_set_x(ui_PanelTemperInfo, 582);
    lv_obj_set_y(ui_PanelTemperInfo, 9);
    lv_obj_clear_flag(ui_PanelTemperInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelTemperInfo, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTemperInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelTemperInfo, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageCompany = lv_img_create(ui_PanelTemperInfo);
    lv_img_set_src(ui_ImageCompany, &ui_img_company_png);
    lv_obj_set_width(ui_ImageCompany, 155);
    lv_obj_set_height(ui_ImageCompany, 20);
    lv_obj_set_x(ui_ImageCompany, 4);
    lv_obj_set_y(ui_ImageCompany, 3);
    lv_obj_add_flag(ui_ImageCompany, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCompany, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ImageCompany, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ImageCompany, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelHotendTemp = lv_obj_create(ui_PanelTemperInfo);
    lv_obj_set_width(ui_PanelHotendTemp, 170);
    lv_obj_set_height(ui_PanelHotendTemp, 50);
    lv_obj_set_x(ui_PanelHotendTemp, -4);
    lv_obj_set_y(ui_PanelHotendTemp, 44);
    lv_obj_clear_flag(ui_PanelHotendTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelHotendTemp, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHotendTemp, lv_color_hex(0x0D0D0D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotendTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelHotendTemp, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelHotendTemp, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelHotendTemp, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelHotendTemp, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelHotendTemp, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageHotend = lv_img_create(ui_PanelHotendTemp);
    lv_img_set_src(ui_ImageHotend, &ui_img_hotend_png);
    lv_obj_set_width(ui_ImageHotend, 33);
    lv_obj_set_height(ui_ImageHotend, 33);
    lv_obj_set_x(ui_ImageHotend, 13);
    lv_obj_set_y(ui_ImageHotend, -16);
    lv_obj_add_flag(ui_ImageHotend, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotend, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageHotend, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageHotend, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageHotend, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor(ui_ImageHotend, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_img_recolor_opa(ui_ImageHotend, 100, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_LabelHotendTemper = lv_label_create(ui_PanelHotendTemp);
    lv_obj_set_width(ui_LabelHotendTemper, 47);
    lv_obj_set_height(ui_LabelHotendTemper, 39);
    lv_obj_set_x(ui_LabelHotendTemper, 43);
    lv_obj_set_y(ui_LabelHotendTemper, -16);
    lv_label_set_text(ui_LabelHotendTemper, "");
    lv_obj_set_style_text_color(ui_LabelHotendTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTemper, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelHotendTemperCelsius = lv_label_create(ui_PanelHotendTemp);
    lv_obj_set_width(ui_LabelHotendTemperCelsius, 25);
    lv_obj_set_height(ui_LabelHotendTemperCelsius, 27);
    lv_obj_set_x(ui_LabelHotendTemperCelsius, 90);
    lv_obj_set_y(ui_LabelHotendTemperCelsius, -10);
    lv_label_set_text(ui_LabelHotendTemperCelsius, "°C");
    lv_obj_set_style_text_color(ui_LabelHotendTemperCelsius, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTemperCelsius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendTemperCelsius, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTemperCelsius, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelBedTemp = lv_obj_create(ui_PanelTemperInfo);
    lv_obj_set_width(ui_PanelBedTemp, 170);
    lv_obj_set_height(ui_PanelBedTemp, 50);
    lv_obj_set_x(ui_PanelBedTemp, -4);
    lv_obj_set_y(ui_PanelBedTemp, 116);
    lv_obj_clear_flag(ui_PanelBedTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelBedTemp, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelBedTemp, lv_color_hex(0x0D0D0D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBedTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBedTemp, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelBedTemp, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelBedTemp, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelBedTemp, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelBedTemp, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageBed = lv_img_create(ui_PanelBedTemp);
    lv_img_set_src(ui_ImageBed, &ui_img_bed_png);
    lv_obj_set_width(ui_ImageBed, 33);
    lv_obj_set_height(ui_ImageBed, 33);
    lv_obj_set_x(ui_ImageBed, 13);
    lv_obj_set_y(ui_ImageBed, -16);
    lv_obj_add_flag(ui_ImageBed, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageBed, lv_color_hex(0x0000FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageBed, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageBed, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelBedTemper = lv_label_create(ui_PanelBedTemp);
    lv_obj_set_width(ui_LabelBedTemper, 47);
    lv_obj_set_height(ui_LabelBedTemper, 33);
    lv_obj_set_x(ui_LabelBedTemper, 43);
    lv_obj_set_y(ui_LabelBedTemper, -16);
    lv_label_set_text(ui_LabelBedTemper, "");
    lv_obj_set_style_text_color(ui_LabelBedTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemper, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelBedTemperCelsius = lv_label_create(ui_PanelBedTemp);
    lv_obj_set_width(ui_LabelBedTemperCelsius, 25);
    lv_obj_set_height(ui_LabelBedTemperCelsius, 30);
    lv_obj_set_x(ui_LabelBedTemperCelsius, 90);
    lv_obj_set_y(ui_LabelBedTemperCelsius, -10);
    lv_label_set_text(ui_LabelBedTemperCelsius, "°C");
    lv_obj_set_style_text_color(ui_LabelBedTemperCelsius, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemperCelsius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTemperCelsius, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemperCelsius, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    /*********************重叠部分***************************/
    ui_PanelHotendHeating = lv_obj_create(ui_PanelTemperInfo);  //ui_PanelTemperInfo
    lv_obj_set_width(ui_PanelHotendHeating, 170);
    lv_obj_set_height(ui_PanelHotendHeating, 50);
    lv_obj_set_x(ui_PanelHotendHeating, -4);
    lv_obj_set_y(ui_PanelHotendHeating, 44);
    lv_obj_clear_flag(ui_PanelHotendHeating, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelHotendHeating, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHotendHeating, lv_color_hex(0x0D0D0D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotendHeating, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelHotendHeating, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelHotendHeating, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelHotendHeating, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelHotendHeating, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelHotendHeating, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageHotendHeating = lv_img_create(ui_PanelHotendHeating);
    lv_img_set_src(ui_ImageHotendHeating, &ui_img_hotendheating_png);
    lv_obj_set_width(ui_ImageHotendHeating, 28);
    lv_obj_set_height(ui_ImageHotendHeating, 28);
    lv_obj_set_x(ui_ImageHotendHeating, -15);
    lv_obj_set_y(ui_ImageHotendHeating, -11);
    lv_obj_add_flag(ui_ImageHotendHeating, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendHeating, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageHotendHeating, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageHotendHeating, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageHotendHeating, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor(ui_ImageHotendHeating, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_img_recolor_opa(ui_ImageHotendHeating, 100, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_LabelHotendzCurTemper = lv_label_create(ui_PanelHotendHeating);
    lv_obj_set_width(ui_LabelHotendzCurTemper, 42);
    lv_obj_set_height(ui_LabelHotendzCurTemper, 33);
    lv_obj_set_x(ui_LabelHotendzCurTemper, 10);
    lv_obj_set_y(ui_LabelHotendzCurTemper, -11);
    lv_label_set_text(ui_LabelHotendzCurTemper, "");
    lv_obj_set_style_text_color(ui_LabelHotendzCurTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendzCurTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendzCurTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendzCurTemper, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelHotendHeatingTemperCelsius = lv_label_create(ui_PanelHotendHeating);
    lv_obj_set_width(ui_LabelHotendHeatingTemperCelsius, 30);
    lv_obj_set_height(ui_LabelHotendHeatingTemperCelsius, 30);
    lv_obj_set_x(ui_LabelHotendHeatingTemperCelsius, 114);
    lv_obj_set_y(ui_LabelHotendHeatingTemperCelsius, -5);
    lv_label_set_text(ui_LabelHotendHeatingTemperCelsius, "°C");
    lv_obj_set_style_text_color(ui_LabelHotendHeatingTemperCelsius, lv_color_hex(0x515459),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendHeatingTemperCelsius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendHeatingTemperCelsius, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendHeatingTemperCelsius, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelHotendTargetTemper = lv_label_create(ui_PanelHotendHeating);
    lv_obj_set_width(ui_LabelHotendTargetTemper, 42);
    lv_obj_set_height(ui_LabelHotendTargetTemper, 33);
    lv_obj_set_x(ui_LabelHotendTargetTemper, 72);
    lv_obj_set_y(ui_LabelHotendTargetTemper, -11);
    lv_label_set_text(ui_LabelHotendTargetTemper, "");
    lv_obj_set_style_text_color(ui_LabelHotendTargetTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTargetTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendTargetTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTargetTemper, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageHotendHeatingTo = lv_img_create(ui_PanelHotendHeating);
    lv_img_set_src(ui_ImageHotendHeatingTo, &ui_img_totarget_png);
    lv_obj_set_width(ui_ImageHotendHeatingTo, 16);
    lv_obj_set_height(ui_ImageHotendHeatingTo, 15);
    lv_obj_set_x(ui_ImageHotendHeatingTo, 53);
    lv_obj_set_y(ui_ImageHotendHeatingTo, -2);
    lv_obj_add_flag(ui_ImageHotendHeatingTo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendHeatingTo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageHotendHeatingTo, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageHotendHeatingTo, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageHotendHeatingTo, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor(ui_ImageHotendHeatingTo, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_img_recolor_opa(ui_ImageHotendHeatingTo, 100, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_PanelBedHeating = lv_obj_create(ui_PanelTemperInfo);  //ui_PanelTemperInfo
    lv_obj_set_width(ui_PanelBedHeating, 170);
    lv_obj_set_height(ui_PanelBedHeating, 50);
    lv_obj_set_x(ui_PanelBedHeating, -4);
    lv_obj_set_y(ui_PanelBedHeating, 116);
    lv_obj_clear_flag(ui_PanelBedHeating, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelBedHeating, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelBedHeating, lv_color_hex(0x0D0D0D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBedHeating, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBedHeating, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelBedHeating, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelBedHeating, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelBedHeating, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelBedHeating, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageBedHeating = lv_img_create(ui_PanelBedHeating);
    lv_img_set_src(ui_ImageBedHeating, &ui_img_bedheating_png);
    lv_obj_set_width(ui_ImageBedHeating, 28);
    lv_obj_set_height(ui_ImageBedHeating, 28);
    lv_obj_set_x(ui_ImageBedHeating, -15);
    lv_obj_set_y(ui_ImageBedHeating, -11);
    lv_obj_add_flag(ui_ImageBedHeating, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBedHeating, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageBedHeating, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageBedHeating, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageBedHeating, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelBedCurTemper = lv_label_create(ui_PanelBedHeating);
    lv_obj_set_width(ui_LabelBedCurTemper, 42);
    lv_obj_set_height(ui_LabelBedCurTemper, 33);
    lv_obj_set_x(ui_LabelBedCurTemper, 10);
    lv_obj_set_y(ui_LabelBedCurTemper, -11);
    lv_label_set_text(ui_LabelBedCurTemper, "");
    lv_obj_set_style_text_color(ui_LabelBedCurTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedCurTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedCurTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedCurTemper, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageBedHeatingTo = lv_img_create(ui_PanelBedHeating);
    lv_img_set_src(ui_ImageBedHeatingTo, &ui_img_totarget_png);
    lv_obj_set_width(ui_ImageBedHeatingTo, 16);
    lv_obj_set_height(ui_ImageBedHeatingTo, 15);
    lv_obj_set_x(ui_ImageBedHeatingTo, 53);
    lv_obj_set_y(ui_ImageBedHeatingTo, -2);
    lv_obj_add_flag(ui_ImageBedHeatingTo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBedHeatingTo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageBedHeatingTo, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageBedHeatingTo, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageBedHeatingTo, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelBedTargetTemper = lv_label_create(ui_PanelBedHeating);
    lv_obj_set_width(ui_LabelBedTargetTemper, 42);
    lv_obj_set_height(ui_LabelBedTargetTemper, 33);
    lv_obj_set_x(ui_LabelBedTargetTemper, 72);
    lv_obj_set_y(ui_LabelBedTargetTemper, -11);
    lv_label_set_text(ui_LabelBedTargetTemper, "");
    lv_obj_set_style_text_color(ui_LabelBedTargetTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTargetTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTargetTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTargetTemper, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelBedHeatingTemperCelsius = lv_label_create(ui_PanelBedHeating);
    lv_obj_set_width(ui_LabelBedHeatingTemperCelsius, 30);
    lv_obj_set_height(ui_LabelBedHeatingTemperCelsius, 30);
    lv_obj_set_x(ui_LabelBedHeatingTemperCelsius, 114);
    lv_obj_set_y(ui_LabelBedHeatingTemperCelsius, -5);
    lv_label_set_text(ui_LabelBedHeatingTemperCelsius, "°C");
    lv_obj_set_style_text_color(ui_LabelBedHeatingTemperCelsius, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedHeatingTemperCelsius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedHeatingTemperCelsius, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedHeatingTemperCelsius, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelChamberTemp = lv_obj_create(ui_PanelTemperInfo);  //ui_PanelTemperInfo
    lv_obj_set_width(ui_PanelChamberTemp, 170);
    lv_obj_set_height(ui_PanelChamberTemp, 50);
    lv_obj_set_x(ui_PanelChamberTemp, -4);
    lv_obj_set_y(ui_PanelChamberTemp, 184);
    lv_obj_clear_flag(ui_PanelChamberTemp, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_clear_flag(ui_PanelChamberTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelChamberTemp, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelChamberTemp, lv_color_hex(0x0D0D0D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelChamberTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelChamberTemp, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelChamberTemp, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelChamberTemp, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelChamberTemp, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelChamberTemp, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageChamberHeating = lv_img_create(ui_PanelChamberTemp);
    char tempbuff[256] = {0};
    snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "icon_chamber.png");
    lv_img_set_src(ui_ImageChamberHeating, tempbuff);
    lv_obj_set_width(ui_ImageChamberHeating, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageChamberHeating, LV_SIZE_CONTENT);
    lv_obj_align(ui_ImageChamberHeating, LV_ALIGN_LEFT_MID, 18, 0);
    lv_obj_add_flag(ui_ImageChamberHeating, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageChamberHeating, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_ImageChamberHeating, lv_color_hex(0x0000FF),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ImageChamberHeating, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ImageChamberHeating, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelChamberCurTemper = lv_label_create(ui_PanelChamberTemp);
    lv_obj_set_width(ui_LabelChamberCurTemper, 47);
    lv_obj_set_height(ui_LabelChamberCurTemper, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelChamberCurTemper, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LabelChamberCurTemper, "");
    lv_obj_set_style_text_color(ui_LabelChamberCurTemper, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelChamberCurTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelChamberCurTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelChamberCurTemper, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelChamberTemperCelsius = lv_label_create(ui_PanelChamberTemp);
    lv_obj_set_width(ui_LabelChamberTemperCelsius, 30);
    lv_obj_set_height(ui_LabelChamberTemperCelsius, 30);
    lv_obj_align_to(ui_LabelChamberTemperCelsius, ui_LabelChamberCurTemper, LV_ALIGN_OUT_RIGHT_BOTTOM, 5, 0);
    lv_label_set_text(ui_LabelChamberTemperCelsius, "°C");
    lv_obj_set_style_text_color(ui_LabelChamberTemperCelsius, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelChamberTemperCelsius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelChamberTemperCelsius, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelChamberTemperCelsius, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    /**************重叠部分根据目标温度来进行控制是否显示***********/
    lv_obj_add_flag(ui_PanelBedHeating, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelHotendHeating, LV_OBJ_FLAG_HIDDEN);    

    /********************重叠部分**********************************/

    ui_PanelLine = lv_obj_create(ui_PanelTemperInfo);
    lv_obj_set_width(ui_PanelLine, 195);
    lv_obj_set_height(ui_PanelLine, 1);
    lv_obj_set_x(ui_PanelLine, -17);
    lv_obj_set_y(ui_PanelLine, 245);
    lv_obj_clear_flag(ui_PanelLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelLine, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLine, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelStatus = lv_obj_create(ui_PanelTemperInfo);
    lv_obj_set_width(ui_PanelStatus, 206);
    lv_obj_set_height(ui_PanelStatus, 96);
    lv_obj_set_x(ui_PanelStatus, -22);
    lv_obj_set_y(ui_PanelStatus, 246);
    lv_obj_clear_flag(ui_PanelStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelStatus, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelStatus, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelStatus, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel_Lightes = lv_obj_create(ui_PanelStatus);
    lv_obj_set_width(ui_Panel_Lightes, 94);
    lv_obj_set_height(ui_Panel_Lightes, 86);
    lv_obj_set_x(ui_Panel_Lightes, -17);
    lv_obj_set_y(ui_Panel_Lightes, -18);
    lv_obj_clear_flag(ui_Panel_Lightes, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_border_color(ui_PanelStatusLine, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_PanelStatusLine, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel_Lightes, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_Panel_Lightes, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_Panel_Lightes, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_Panel_Lightes, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel_Lightes, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_Panel_Lightes, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_Lightes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Panel_Lightes, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_ImageLight = lv_img_create(ui_Panel_Lightes);
    lv_img_set_src(ui_ImageLight, &ui_img_lightclosed_png);
    lv_obj_set_width(ui_ImageLight, 66);
    lv_obj_set_height(ui_ImageLight, 66);
    // lv_obj_set_x(ui_ImageLight, -2);
    // lv_obj_set_y(ui_ImageLight, -12);
    lv_obj_set_align(ui_ImageLight, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ImageLight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_border_color(ui_ImageLight, lv_color_hex(0x42BDD8),
    //                               LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_ImageLight, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_ImageLight, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_PanelStatusLine = lv_obj_create(ui_PanelStatus);
    lv_obj_set_width(ui_PanelStatusLine, 1);
    lv_obj_set_height(ui_PanelStatusLine, 56);
    lv_obj_set_x(ui_PanelStatusLine, 80);
    lv_obj_set_y(ui_PanelStatusLine, -5);
    lv_obj_clear_flag(ui_PanelStatusLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelStatusLine, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelStatusLine, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel_Fans = lv_obj_create(ui_PanelStatus);
    lv_obj_set_width(ui_Panel_Fans, 94);
    lv_obj_set_height(ui_Panel_Fans, 86);
    lv_obj_set_x(ui_Panel_Fans, 85);
    lv_obj_set_y(ui_Panel_Fans, -18);
    lv_obj_clear_flag(ui_Panel_Fans, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_border_color(ui_PanelStatusLine, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_PanelStatusLine, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel_Fans, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_Panel_Fans, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_Panel_Fans, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_Panel_Fans, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel_Fans, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_Panel_Fans, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_Fans, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Panel_Fans, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageFan = lv_img_create(ui_Panel_Fans);
    lv_img_set_src(ui_ImageFan, &ui_img_stop_fan_png);
    lv_obj_set_width(ui_ImageFan, 66);
    lv_obj_set_height(ui_ImageFan, 66);
    lv_obj_set_align(ui_ImageFan, LV_ALIGN_CENTER);
    // lv_obj_set_x(ui_ImageFan, -8);
    // lv_obj_set_y(ui_ImageFan, -12);

    ui_GifFan = lv_gif_create(ui_Panel_Fans);
    lv_gif_set_src(ui_GifFan, &ui_img_HomeFan);
    lv_obj_set_width(ui_GifFan, 66);
    lv_obj_set_height(ui_GifFan, 66);
    lv_obj_set_align(ui_GifFan, LV_ALIGN_CENTER);
    // lv_obj_set_x(ui_GifFan, -8);
    // lv_obj_set_y(ui_GifFan, -12);
    lv_obj_add_flag(ui_GifFan, LV_OBJ_FLAG_HIDDEN);     /// Flags

    // ui_PanelPrintOpt = lv_obj_create(ui_ScreenHomePagePrinting);
    // lv_obj_set_width(ui_PanelPrintOpt, 206);
    // lv_obj_set_height(ui_PanelPrintOpt, 92);
    // lv_obj_set_x(ui_PanelPrintOpt, 584);
    // lv_obj_set_y(ui_PanelPrintOpt, 378);
    // lv_obj_clear_flag(ui_PanelPrintOpt, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonPrintOpt = lv_btn_create(ui_ScreenHomePagePrinting);
    lv_obj_set_width(ui_ButtonPrintOpt, 206);
    lv_obj_set_height(ui_ButtonPrintOpt, 92);
    lv_obj_set_x(ui_ButtonPrintOpt, 584);
    lv_obj_set_y(ui_ButtonPrintOpt, 378);
    lv_obj_add_flag(ui_ButtonPrintOpt, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPrintOpt, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonPrintOpt, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPrintOpt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonPrintOpt, &ui_img_start_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonPrintOpt, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ButtonPrintOpt, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonPrintOpt, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonPrintOpt, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonPrintOpt, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonPrintOpt, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_ButtonPrintOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonPrintOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


    lv_obj_add_event_cb(ui_ButtonAxisMove, ui_event_ButtonAxisMove, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonFIleManage, ui_event_ButtonFIleManage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettings, ui_event_ButtonSettings, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserve, ui_event_ButtonReserve, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelHotendTemp, ui_event_PanelHotendTemp, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelBedTemp, ui_event_PanelBedTemp, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Panel_Lightes, ui_event_ImageLight, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Panel_Fans, ui_event_ImageFan, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonPrintOpt, ui_event_ButtonPrintOpt, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenHomePagePrinting, ui_event_HomePrintPageload, LV_EVENT_SCREEN_LOADED, NULL);
    /***********重叠部分*******************/
    //lv_obj_add_event_cb(ui_ImageHotendHeatingTo, ui_event_ImageHotendHeatingTo, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelHotendHeating, ui_event_PanelHotendHeating, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_ImageBedHeatingTo, ui_event_ImageBedHeatingTo, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelBedHeating, ui_event_PanelBedHeating, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ImageExcludeObjectIcon, ui_event_ExclueObject, LV_EVENT_ALL, NULL);

    /**********************add ******************/
}


void LoadHomePrintingScreen(void)
{
    lv_disp_load_scr(ui_ScreenHomePagePrinting);
}

void homePageAxisMoveBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadAxisMoveScreen();
}

void homePageFileManageBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadFileManageScreen();
}

void homePageSettingBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadSettingsScreen();
}

void homePageReserveBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadCustomerServiceScreen();
}


void HomePageHotendClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    sprintf(buff, "%s #42BDD8 %d-%d#", HotendInputRangle[get_cur_language_index()],HOTEND_MIN_EDIT_TEMPER, HOTEND_MAX_EDIT_TEMPER);
    numberskeyboardinput(buff, HOTEND_MAX_EDIT_TEMPER, HOTEND_MIN_EDIT_TEMPER,
                    printing_hotend_edit_target_temper_callback, key_reminder_callback, 92, 0);
}

void HomePageBedClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    if(UIType == CR_K1_Max)
    {
        int maxtemp = (IsK1MaxSe == true) ? K1_MAX_SE_BED_MAX_EDIT_TEMPER : K1_MAX_BED_MAX_EDIT_TEMPER;
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, maxtemp);
        numberskeyboardinput(buff, maxtemp, BED_MIN_EDIT_TEMPER,printing_bed_edit_target_temper_callback, key_reminder_callback, 92, 0);
    }
    else
    {
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, BED_MAX_EDIT_TEMPER);
        numberskeyboardinput(buff, BED_MAX_EDIT_TEMPER, BED_MIN_EDIT_TEMPER,
                    printing_bed_edit_target_temper_callback, key_reminder_callback, 92, 0);        
    }

}

void HomePageLightClicked(lv_event_t * e)
{
	// Your code here
    send_set_light_opt_cmd(!light_opened_printing);
}

void HomePageFanClicked(lv_event_t * e)
{
	// Your code here
    uint8_t percent = 100;
    if ( fan_opened_printing )
        percent = 0;

    // send_set_model_fan_opt_cmd(percent);
    //不再发送命令改为跳转页面
    set_current_subpage(2);
    ui_change(PAGE_AXIS);
}

void PrintOptClicked(lv_event_t * e)
{
	// Your code here
    // if(system_state.PreStartprint_state)    //当前处于打印前准备
    // {
    //     create_msgbox(PrintingTips[get_cur_language_index()], NULL, 2000, lv_scr_act());
    //     return;
    // }
    if ( print_status == 3)  // 1 is printing
    {
        create_custom_print_opt_screen(true, &printing_pause_print_opt_callback, &printing_stop_print_opt_callback);
    }
    else if( print_status == 2 )
    {
        create_custom_print_opt_screen(false, &printing_resume_print_opt_callback, &printing_stop_print_opt_callback);
    }
    else if( print_status == APP_PRINT_STATE_TO_WORK)
    {
        create_msgbox(PrintingTips_Startprint[get_cur_language_index()], NULL, 1000, lv_scr_act());
    }
    else if( print_status == APP_PRINT_STATE_TO_PAUSE)
    {
        create_msgbox(PrintingTips_Pauseprint[get_cur_language_index()], NULL, 1000, lv_scr_act());
    }
    else if( print_status == APP_PRINT_STATE_TO_RESUME)
    {
        create_msgbox(PrintingTips_Resumeprint[get_cur_language_index()], NULL, 1000, lv_scr_act());
    }
    else if( print_status == APP_PRINT_STATE_TO_STOP)
    {
        create_msgbox(PrintingTips_Stopprint[get_cur_language_index()], NULL, 1000, lv_scr_act());
    }
}


void printing_hotend_edit_target_temper_callback(void *param)
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


void printing_bed_edit_target_temper_callback(void *param)
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

void HomePageHotendHeatingClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    sprintf(buff, "%s #42BDD8 %d-%d#", HotendInputRangle[get_cur_language_index()], HOTEND_MIN_EDIT_TEMPER, HOTEND_MAX_EDIT_TEMPER);
    numberskeyboardinput(buff, HOTEND_MAX_EDIT_TEMPER, HOTEND_MIN_EDIT_TEMPER,
                    printing_hotend_edit_target_temper_callback, key_reminder_callback, 92, 0);
}

// void PrintPageSetHotendTargetEvent(lv_event_t * e)
// {
// 	// Your code here
// }

void HomePageBedHeatingClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    if(UIType == CR_K1_Max)
    {
        int maxtemp = (IsK1MaxSe == true) ? K1_MAX_SE_BED_MAX_EDIT_TEMPER : K1_MAX_BED_MAX_EDIT_TEMPER;
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, maxtemp);
        numberskeyboardinput(buff, maxtemp, BED_MIN_EDIT_TEMPER,printing_bed_edit_target_temper_callback, key_reminder_callback, 92, 0);        
    }
    else
    {
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, BED_MAX_EDIT_TEMPER);
        numberskeyboardinput(buff, BED_MAX_EDIT_TEMPER, BED_MIN_EDIT_TEMPER,
                printing_bed_edit_target_temper_callback, key_reminder_callback, 92, 0);        
    }

}

// void PrintPageSetBedTargetEvent(lv_event_t * e)
// {
// 	// Your code here
// }


void show_hotend_heating_status(bool show)
{
    if ( show )
    {
        lv_obj_add_flag(ui_PanelHotendTemp, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelHotendHeating, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(ui_PanelHotendHeating, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelHotendTemp, LV_OBJ_FLAG_HIDDEN);
    }
}

void show_bed_heating_status(bool show)
{
    if ( show )
    {
        lv_obj_add_flag(ui_PanelBedTemp, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelBedHeating, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(ui_PanelBedHeating, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelBedTemp, LV_OBJ_FLAG_HIDDEN);
    }
}

void home_printing_set_hotend_temper(int16_t curTemper, int16_t targetTemper)
{
    char buff[10] = {0};
    sprintf(buff, "%d", curTemper);
    lv_label_set_text(ui_LabelHotendzCurTemper, buff);
    lv_label_set_text(ui_LabelHotendTemper, buff);
    hotend_temper_printing = curTemper;

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelHotendTargetTemper, buff);
    hotend_target_temper_printing = targetTemper;

    // bool show_heating = false;
    // if ( targetTemper > 0 )
    //     show_heating = true;
    
    // show_hotend_heating_status(show_heating);

    static int NozzleHeatingcount = 0;
    if(targetTemper == 0)
    {
        show_hotend_heating_status(false);
        return;
    }
    if(abs(curTemper - targetTemper) <= 2)
    {
        NozzleHeatingcount++;
        if(NozzleHeatingcount >= 20)
        {
            NozzleHeatingcount = 0;
            show_hotend_heating_status(false);
        }
    }
    else
    {
        NozzleHeatingcount = 0;
        show_hotend_heating_status(true);
    }
}

void home_printing_set_bed_temper(int16_t curTemper, int16_t targetTemper)
{
    char buff[10] = {0};
    sprintf(buff, "%d", curTemper);
    lv_label_set_text(ui_LabelBedCurTemper, buff);
    lv_label_set_text(ui_LabelBedTemper, buff);
    bed_temper_printing = curTemper;

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelBedTargetTemper, buff);
    bed_target_temper_printing = targetTemper;

    // bool show_heating = false;
    // if ( targetTemper > 0 )
    //     show_heating = true;
    
    // show_bed_heating_status(show_heating);

    static int BedHeatingcount = 0;
    if(targetTemper == 0)
    {
        show_bed_heating_status(false);
        return;
    }
    if(abs(curTemper - targetTemper) <= 2)
    {
        BedHeatingcount++;
        if(BedHeatingcount >= 20)
        {
            BedHeatingcount = 0;
            show_bed_heating_status(false);
        }
    }
    else
    {
        BedHeatingcount = 0;
        show_bed_heating_status(true);
    }
}

void home_printing_set_fan_status(bool open)
{
    fan_opened_printing = open;
    if ( ui_ImageFan )
    {
        fan_opened_printing ? lv_obj_add_flag(ui_ImageFan, LV_OBJ_FLAG_HIDDEN) :
                              lv_obj_clear_flag(ui_ImageFan, LV_OBJ_FLAG_HIDDEN);
    }

    if ( ui_GifFan )
        fan_opened_printing ? lv_obj_clear_flag(ui_GifFan, LV_OBJ_FLAG_HIDDEN) :
                              lv_obj_add_flag(ui_GifFan, LV_OBJ_FLAG_HIDDEN);

}

void home_printing_set_light_status(bool open)
{
    light_opened_printing = open;
    if ( light_opened_printing )
        lv_img_set_src(ui_ImageLight, &ui_img_lightopened_png);
    else
        lv_img_set_src(ui_ImageLight, &ui_img_lightclosed_png);
}

void home_printing_set_wifi_status(int intensity)
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
        case 0:lv_img_set_src(ui_ImageWifiLarge, &ui_img_wifinosignel_png);break;
        case 1:lv_img_set_src(ui_ImageWifiLarge, &ui_img_wifismall_png);break;
        case 2:lv_img_set_src(ui_ImageWifiLarge, &ui_img_wifimid_png);break;
        case 3:lv_img_set_src(ui_ImageWifiLarge, &ui_img_wififull_png);break;
        default:lv_img_set_src(ui_ImageWifiLarge, &ui_img_wififull_png);break;
    }

    wifi_Intensity_printing = intensity;
}

void home_printing_set_chamber_temper(int16_t curTemper)
{
    CrLogI("set the chamber temperature in printing page");
    char tempbuff[100] = {0};
    sprintf(tempbuff, "%d", curTemper);
    lv_label_set_text(ui_LabelChamberCurTemper, tempbuff);
}

void show_print_proccess(void)
{
    char buff[5] = {0};
    sprintf(buff, "%d", proccess_printing);
    lv_label_set_text(ui_LabelProcess, buff);
    lv_bar_set_value(ui_BarPrintProccess, proccess_printing, LV_ANIM_OFF);
}

void show_print_used_time(void)
{
    char buff[10] = {0};
    int32_t used_time_m = used_time_printing / 60; //trans to minters
    sprintf(buff, "%dh%02dm", used_time_m / 60, used_time_m % 60);
    lv_label_set_text(ui_LabelUsedTimes, buff);
}

void show_print_remained_time(void)
{
    char buff[10] = {0};
    int32_t temainder_time_m = remained_time_printing / 60; //trans to minters
    sprintf(buff, "%dh%02dm", temainder_time_m / 60, (temainder_time_m % 60));
    lv_label_set_text(ui_LabelRemainingTimes, buff);
    //更新关联的图片位置
    lv_obj_align_to(ui_ImageRemainderTimes, ui_LabelRemainingTimes, LV_ALIGN_OUT_LEFT_BOTTOM, -5, 2);
}

void show_model_mask(int proccess_percent)
{
    if(strcmp(print_job.gcode_type, SLICE_SOFTNAME) == 0)
    {
        lv_obj_clear_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    }
    if ( proccess_percent > 100 )
        proccess_percent = 100;
    if ( proccess_percent < 0 )
        proccess_percent = 0;

    // if ( ui_ImageChartMask && (gcode_layer_count <= 0) )
    // {
    //     // int height = ((100 - proccess_percent) * MAX_FILLINF_CHART_MASK_HEIGHT) / 100;
    //     int height = ((100 - proccess_percent) * (model_end_pix - model_start_pix)) / 100 + (MAX_FILLINF_CHART_MASK_HEIGHT - model_end_pix);
    //     lv_obj_set_height(ui_ImageChartMask, height <= (MAX_FILLINF_CHART_MASK_HEIGHT - model_end_pix) ? 0 : height);
    // }
}

static void show_printing_file_name(void)
{
    lv_label_set_text(ui_LabelFileName, file_name_printing);
}

void home_printing_set_print_proccess_info(int32_t used_time, int32_t left_time, int8_t proccess)
{
    if ( proccess > 100 )
        proccess = 100;
    used_time_printing = used_time;
    remained_time_printing = left_time;
    proccess_printing = proccess;
    show_print_proccess();
    show_print_remained_time();
    show_print_used_time();
    //update mask png
    show_model_mask(proccess_printing);
    //update print opt button
    // if ( proccess >= 100 )
    // {
    //     LoadHomeNormalScreen();
    //     used_time_printing = 0;
    //     remained_time_printing = 0;
    //     proccess_printing = 0;
    //     lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    // }

}

void home_printing_set_print_file_name(char *file_name)
{
    if ( file_name )
    {
        char *ch = strrchr(file_name, '.');
        if ( ch )
            *ch = '\0';

        strncpy(file_name_printing, file_name, sizeof(file_name_printing));
    }
    else
        strcpy(file_name_printing, "");
        
    show_printing_file_name();
}

void show_filling_chart(void)
{   
    lv_obj_set_style_img_recolor(ui_ImageModelChart, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_ImageModelChart, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    if ( home_printing_is_printing_finished() )
    {
        lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    }
    else
        lv_obj_clear_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);

    if(strcmp(print_job.gcode_type, SLICE_SOFTNAME) == 0)
    {
        lv_obj_clear_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_style_img_recolor_opa(ui_ImageModelChart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    if ( strlen(filling_chart_name) )
    {
        char buff[258] = {0};
        // buff[0] = PNG_DRV_LETTER;
        // strncpy(buff + 1, filling_chart_name, sizeof(buff) - 2);
        snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, filling_chart_name);
        lv_img_set_src(ui_ImageModelChart, buff);
        lv_img_set_src(ui_ImageChartMask, buff);
    }
    else
    {
        lv_img_set_src(ui_ImageModelChart, &ui_img_crealitylogo_png);
        lv_img_set_src(ui_ImageChartMask, &ui_img_crealitylogo_png);
    }
    lv_obj_set_width(ui_ImageChartMask, 300);

    lv_obj_set_style_img_recolor(ui_ImageChartMask, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_ImageChartMask, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void home_printing_set_filling_chart_name(char *chart_name, uint16_t pixel_start, 
                                          uint16_t pixel_end, float model_height,float model_layer_height)
{
    if ( !chart_name )
    {
        memset(filling_chart_name, 0, sizeof(filling_chart_name));
    }
    else
    {
        strncpy(filling_chart_name, chart_name, sizeof(filling_chart_name) - 1);
    }

    if ( lv_obj_is_visible(ui_ScreenHomePagePrinting) )
        show_filling_chart();
}


void show_printing_status(void)
{
    if ( print_status ==  3)  //0: finished , 1:stoped, 2:paused, 3:printing.
    {
        lv_obj_set_style_bg_img_src(ui_ButtonPrintOpt, &ui_img_start_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else
    {
        lv_obj_set_style_bg_img_src(ui_ButtonPrintOpt, &ui_img_pause_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

void printcompleted_msg_close(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        set_printer_data(0x0f, 1, "1");
        close_printcompleted_msg();
        printcomplete_flag = false;
        if( CheckUpdataFlag )
        {
            DotCheckVersion = 1;
            EnterUpdatepage(1); //打印完成后查询版本信息
        }
    }

}

void home_printing_set_printing_status(int status)
{
    // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
    if ( print_status == status )
        return;
    print_status = status;
    if ( (print_status == 2) || (print_status == 3) )
    {
        if(printcomplete_flag == true)
        {
            close_printcompleted_msg();
            printcomplete_flag = false;
        }
        LoadHomePrintingScreen();
    }
    else if ( (print_status == 1) )
    {
        if(printcomplete_flag == true)
        {
            close_printcompleted_msg();
            printcomplete_flag = false;
        }
        LoadHomeNormalScreen();
    }
    else if( print_status == 0 ){
        printcomplete_flag = true;
        char tempbuff[256] = {0};
        int32_t used_time_m = used_time_printing / 60; //trans to minters
        snprintf(tempbuff, 256, "%dh%02dm", used_time_m / 60, used_time_m % 60);
        create_printcompleted_msg(1, tempbuff, printcompleted_msg_close);

        used_time_printing = 0;
        remained_time_printing = 0;
        proccess_printing = 0;
        lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    }
}

bool home_printing_is_printing_finished()  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
{
    if ( (print_status == 0) || (print_status == 1) )
        return true;
    
    return false;
}

bool home_printing_is_printing()  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
{
    return print_status == 3 ?  true : false;
}

bool home_printing_is_paused()  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
{
    return print_status == 2 ? true : false;
}

void printing_pause_print_opt_callback(void)
{
    if( system_state.PreStartprint_state )
    {
        create_msgbox(PrintingTips_CantPause[get_cur_language_index()], NULL, 1000, lv_scr_act());
    }
    else
    {
        send_set_pause_print_cmd();
    }
    // print_status = 2;
    // home_printing_set_printing_status(print_status);
}

void stop_print_confirm_callback(struct _lv_timer_t *timer)
{
    memset(file_name_printing, 0, sizeof(file_name_printing));
    memset(filling_chart_name, 0, sizeof(filling_chart_name));
}

void printing_stop_print_opt_callback(void)
{
    send_set_stop_print_cmd();
    //print_status = 1;
    //home_printing_set_printing_status(print_status);
    
    //LoadHomeNormalScreen();

    lv_timer_t *timer_offset = lv_timer_create(stop_print_confirm_callback, 2000, NULL);
    lv_timer_set_repeat_count(timer_offset, 1);
}

void printing_resume_print_opt_callback(void)
{
    if(material_seneor == '4')
    {
        set_filament_runout(true);
    }
    else if( get_fila_action_type() != FILA_ACTION_NONE )
    {
        if( get_fila_action_type() == FILA_ACTION_IN)
            create_msgbox(ResumePrintTip1[get_cur_language_index()], NULL, 1000, lv_scr_act());
        else
            create_msgbox(ResumePrintTip2[get_cur_language_index()], NULL, 1000, lv_scr_act());
    }
    else
    {
        send_set_resume_print_cmd();
    }
}

void printing_recovery_file_print_again_callback(void)
{
    poweloss_flag = false;
    send_set_start_print_recovery_file();
}

void printing_recovery_file_stop_print_callback(void)
{
    poweloss_flag = false;
    send_set_stop_print_recovery_file();
}

void home_printing_set_powerloss_recovery_info(int state)
{
    if(state)
    {
        if(poweloss_flag)
        {
            CrLogI("powerloss tips is exist.");
            return;
        }
        poweloss_flag = true;
        uint8_t cur_language = get_cur_language_index();
        char *btns[2] = {0};
        btns[0] = ErrorBtnContinuePrint[cur_language];
        btns[1] = Cancel[cur_language];
        void (*btns_callback[2])(void) = {&printing_recovery_file_print_again_callback, &printing_recovery_file_stop_print_callback};
        create_custom_messagebox(KindTips[cur_language], PowerLossRecoverMsg[cur_language], btns, btns_callback, 2, true, false);
        set_custom_messagebox_btn_bg_color(0, lv_color_hex(0x42BDD8));
    }
    else
    {
        if(poweloss_flag)
        {
            CrLogI("cancle the powerloss tips");
            poweloss_flag = false;
            // printing_recovery_file_stop_print_callback();
            messagebox_close();
        }
        if(FirstInitFlag && CheckUpdataFlag)//首次UI初始化查询版本更新信息
        {
            FirstInitFlag = false;
            DotCheckVersion = 1;
            EnterUpdatepage(1);
        }
    }
}

void printing_replace_mater_callback()
{
    selftest_messagebox_close();
}

void printing_stop_replace_mater_callback(void)
{
    selftest_messagebox_close();
    set_current_subpage(1);
    ui_change(PAGE_AXIS);
}

void home_printing_set_filament_runout(bool filamen_runout)
{
    if ( home_printing_is_printing_finished() )
        return;

    if ( filamen_runout )
    {
        uint8_t cur_language = get_cur_language_index();
        void (*btns_callback[2])(void) = {&printing_replace_mater_callback, &printing_stop_replace_mater_callback};
        create_selftest_messagebox(KindTips[cur_language], FilamentRunOutMsg[cur_language], ForgetPasswordArray[cur_language],ToChangeFilament[cur_language], btns_callback);
    }

    printing_filament_runout = filamen_runout;
}

void home_printing_set_home_status(bool is_homing)
{
    // if ( is_homing )
    // {
    //     //if ( !lv_obj_has_flag(ui_ScreenHomePagePrinting, LV_OBJ_FLAG_HIDDEN) )
    //     if ( home_printing_is_printing() )
    //     {
    //         create_custom_reminderbox("printing homing...", false);
    //         set_custom_reminderbox_clickable(false);
    //         set_custom_reminderbox_display_timeout(30, NULL);
    //     }
    // }
    // else
    // {
    //     if ( !lv_obj_has_flag(ui_ScreenHomePagePrinting, LV_OBJ_FLAG_HIDDEN) )
    //         close_custom_reminderbox();
    // }
}

void home_printing_set_gcode_layers_count(uint32_t layer_count)
{
    gcode_layer_count = layer_count;
}

void home_printing_set_gcode_cur_layer_index(uint32_t layer_index)
{
    lv_obj_clear_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);

    if ( ui_ImageChartMask )
    {
        if ( gcode_layer_count > 0)
        {
            // int height = ((gcode_layer_count - layer_index) * MAX_FILLINF_CHART_MASK_HEIGHT) / gcode_layer_count;
            int height = ((gcode_layer_count - layer_index) * (print_job.end_px - print_job.start_px)) / gcode_layer_count + (MAX_FILLINF_CHART_MASK_HEIGHT - print_job.end_px);
            CrLogI("height count is:%d,%d,%d,%d,%d",height,gcode_layer_count,layer_index,print_job.end_px,print_job.start_px);
            lv_obj_set_height(ui_ImageChartMask, height <= (MAX_FILLINF_CHART_MASK_HEIGHT - print_job.end_px) ? 0 : height);
        }
        else
        {
            lv_obj_set_height(ui_ImageChartMask, 300);
        }
    }
}

void print_page_refresh_camerastate(int camera_state)
{
    if(camera_state)
        lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
}

void refresh_prepare_process(int process)
{
    CrLogI("current prepart print process:%d", process);
    int language = get_cur_language_index();
    lv_obj_add_flag(ui_LabelFileName, LV_OBJ_FLAG_HIDDEN);
    switch(process)
    {
        case PREPARE_STEP_NULL:             lv_label_set_text(ui_LabelPrepareTips, "");break;
        case PREPARE_STEP_FOREIGN_BODY:     lv_label_set_text(ui_LabelPrepareTips, FOREIGN_BODY[language]);break;
        case PREPARE_STEP_NOZZLE_CLEAR:     lv_label_set_text(ui_LabelPrepareTips, NOZZLE_CLEAR[language]);break;
        case PREPARE_STEP_ROUGH_G28:        lv_label_set_text(ui_LabelPrepareTips, ROUGH_G28[language]);break;
        case PREPARE_STEP_ACCURATE_G28:     lv_label_set_text(ui_LabelPrepareTips, ACCURATE_G28[language]);break;
        case PREPARE_STEP_LEVEL_DELECT:     lv_label_set_text(ui_LabelPrepareTips, LEVEL_DELECT[language]);break;
        case PREPARE_STEP_LASER_CALIBRATION:lv_label_set_text(ui_LabelPrepareTips, LASER_CALIBRATION[language]);break;
        // 流量检测
        case PREPARE_STEP_FLOW_SCAN_TABLE:  
        case PREPARE_STEP_FLOW_PRINT_LINE:  lv_label_set_text(ui_LabelPrepareTips, PRINT_LINE[language]);break;
        case PREPARE_STEP_FLOW_COOL_DOWN :  lv_label_set_text(ui_LabelPrepareTips, COOL_DOWN[language]);break;
        case PREPARE_STEP_FLOW_SCAN_MODEL:  lv_label_set_text(ui_LabelPrepareTips, SCAN_MODEL[language] );break;
        case PREPARE_STEP_FLOW_AI_CALCULATE:break;
        // 首层检测
        case PREPARE_STEP_FLOOR_SCAN_TABLE: lv_label_set_text(ui_LabelPrepareTips, FLOOR_SCAN_TABLE[language]);break;
        case PREPARE_STEP_FLOOR_PRINT_LINE: lv_label_set_text(ui_LabelPrepareTips, FLOOR_PRINT_LINE[language]);break;
        case PREPARE_STEP_FLOOR_COOL_DOWN:  lv_label_set_text(ui_LabelPrepareTips, FLOOR_COOL_DOWN[language]);break;
        case PREPARE_STEP_FLOOR_SCAN_MODEL: lv_label_set_text(ui_LabelPrepareTips, FLOOR_SCAN_MODEL[language]);break;
        case PREPARE_STEP_FLOOR_AI_CALCULATE:lv_label_set_text(ui_LabelPrepareTips,FLOOR_AI_CALCULATE[language]);break;
        case PREPARE_STEP_FLOOR_HEAT_UP:    lv_label_set_text(ui_LabelPrepareTips, FLOOR_HEAT_UP[language]);break;
        // 完成
        case PREPARE_STEP_FINISH:           lv_label_set_text(ui_LabelPrepareTips, "");lv_obj_clear_flag(ui_LabelFileName, LV_OBJ_FLAG_HIDDEN);break;
        default:                            CrLogW("process error");break;
    }
}

void change_exclueobject_state(bool state)
{
    if(state)
        lv_obj_clear_flag(ui_ImageExcludeObjectIcon, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageExcludeObjectIcon, LV_OBJ_FLAG_HIDDEN);
}

void change_filamentsensor_state(bool state)
{
    if(state)
        lv_obj_clear_flag(ui_ImageFilamentIcon, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageFilamentIcon, LV_OBJ_FLAG_HIDDEN);
}

void change_silentmode_print(bool state)
{
    if(state)
        lv_obj_clear_flag(ui_ImageSilentModeIcon, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageSilentModeIcon, LV_OBJ_FLAG_HIDDEN);
}

