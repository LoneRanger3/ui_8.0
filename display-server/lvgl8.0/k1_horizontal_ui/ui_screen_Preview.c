#include "ui_screen_Preview.h"
#include "ui_screen_FileManage.h"
#include "ui_helpers.h"
#include <stdio.h>
#include "ui_screen_SubDir.h"
#include "ui_custom_messagebox.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_HomePrinting.h"
#include "../custom/lvgl_cmd.h"
#include "ui_Screen_Settings.h"
#include "mult_language.h"
#include "lvgl/src/misc/lv_timer.h"

static lv_obj_t * ui_ScreenPreview;
/**********preview page left panel*******************/
static lv_obj_t * ui_PanelPageScreenPreview;
static lv_obj_t * ui_ButtonHomeScreenPreview;
static lv_obj_t * ui_ButtonAxisMoveScreenPreview;
static lv_obj_t * ui_ImageFileManageScreenPreview;
static lv_obj_t * ui_ButtonSettingsScreenPreview;
static lv_obj_t * ui_ButtonReserveScreenPreview;


/**********preview page right panel*******************/
static lv_obj_t * ui_PanelBackGroudScreenPreview;
/**********preview page right panel filling chart*******************/
static lv_obj_t * ui_PanelCenterScreenPreview;
static lv_obj_t * ui_PanelFillingChartScreenPreview;
static lv_obj_t * ui_ImageFillingChartScreenPreview;

/**********preview page right panel gcode mode info*******************/
static lv_obj_t * ui_PanelPrintOptAndFileInfo;
static lv_obj_t * ui_LabelFileNameScreenPreview;
static lv_obj_t * ui_PanelLine1ScreenPreview;
static lv_obj_t * ui_ImageTotelTimeScreenPreview;
static lv_obj_t * ui_LabelTotleTimeScreenPreview_;
static lv_obj_t * ui_PanelMaterType;
static lv_obj_t * ui_LabelMaterType;
static lv_obj_t * ui_ImageUsageMaterScreenPreview;
static lv_obj_t * ui_LabelUsageMaterScreenPreview;
static lv_obj_t * ui_ImageHotendTemperScreenPreview;
static lv_obj_t * ui_LabelHotendTemperScreenPreview;
static lv_obj_t * ui_ImageBedTemperScreenPreview;
static lv_obj_t * ui_LabelBedTemperScreenPreview;
static lv_obj_t * ui_CheckboxAutoLevelScreenPreview;
static lv_obj_t * ui_PanelLine2ScreenPreview;

/**********preview page right panel control gcode mode print*******************/
static lv_obj_t * ui_PanelActionPrintScreenPreview;
static lv_obj_t * ui_ButtonBackFileListScreenPreview;
static lv_obj_t * ui_LabelBackFileListScreenPreview;
static lv_obj_t * ui_ButtonStartPrintScreenPreview;
static lv_obj_t * ui_LabelBackFileListScreenPreview1;

/**************************custom variable******************************/
static bool is_preview_file_from_root_dir = true;
static char preview_filling_chart_name[256] = {0};
static char preview_file_name[64] = {0};
static uint16_t chart_pixel_start = 0, chart_pixel_end = 0;
static float chart_mode_height = 0.0f, chart_mode_layer_height = 0.0f;
static int32_t chart_file_index = 0;
static PrintFrom print_from;
static uint32_t level_mode = PEOBE_LEVEL;

/*********************** preview page event, can not modify***********************/
static void ui_event_ButtonHomeScreenPreview(lv_event_t * e);
static void ui_event_ButtonAxisMoveScreenPreview(lv_event_t * e);
static void ui_event_ButtonSettingsScreenPreview(lv_event_t * e);
static void ui_event_ButtonReserveScreenPreview(lv_event_t * e);
// static void ui_event_PanelFillingChartScreenPreview(lv_event_t * e);
// static void ui_event_ImageFillingChartScreenPreview(lv_event_t * e);
static void ui_event_ButtonBackFileListScreenPreview(lv_event_t * e);
static void ui_event_ButtonStartPrintScreenPreview(lv_event_t * e);


/*********************** preview page event call back***********************/
static void PreviewPageHomeBtnClicked(lv_event_t * e);
static void PreviewPageAxisBtnClicked(lv_event_t * e);
static void PreviewPageSettingsBtnClicked(lv_event_t * e);
static void PreviewPageReserveBtnClicked(lv_event_t * e);
// static void SubDPagePrevFilesPageBtnClicked(lv_event_t * e);
// static void FilePagePrevPageBtnClicked(lv_event_t * e);
static void PreviewPageBackFileListBtnClicke(lv_event_t * e);
static void PreviewPageStartPrintBtnClicked(lv_event_t * e);



/****************custom funs***********************/
//static void preview_send_print_file_cmd(int file_index);
static void preview_set_print_file_name_and_chart(char *file_name, char *chart_name);
//static void preview_send_auto_level_cmd();


void preview_timeout_callback(struct _lv_timer_t *timer)
{
    lv_obj_clear_flag(ui_ImageFillingChartScreenPreview, LV_OBJ_FLAG_HIDDEN);
}

/*  Preview  */
void ui_event_ButtonHomeScreenPreview(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PreviewPageHomeBtnClicked(e);
    }
}
void ui_event_ButtonAxisMoveScreenPreview(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PreviewPageAxisBtnClicked(e);
    }
}
void ui_event_ButtonSettingsScreenPreview(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PreviewPageSettingsBtnClicked(e);
    }
}
void ui_event_ButtonReserveScreenPreview(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PreviewPageReserveBtnClicked(e);
    }
}

// void ui_event_PanelFillingChartScreenPreview(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         SubDPagePrevFilesPageBtnClicked(e);
//     }
// }
// void ui_event_ImageFillingChartScreenPreview(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilePagePrevPageBtnClicked(e);
//     }
// }

void ui_event_ButtonBackFileListScreenPreview(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PreviewPageBackFileListBtnClicke(e);
    }
}
void ui_event_ButtonStartPrintScreenPreview(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PreviewPageStartPrintBtnClicked(e);
    }
}

void ui_ScreenPreview_screen_init(void)
{
    ui_ScreenPreview = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();

    ui_PanelPageScreenPreview = lv_obj_create(ui_ScreenPreview);
    lv_obj_set_width(ui_PanelPageScreenPreview, 80);
    lv_obj_set_height(ui_PanelPageScreenPreview, 480);
    lv_obj_clear_flag(ui_PanelPageScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPageScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPageScreenPreview, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonHomeScreenPreview = lv_btn_create(ui_PanelPageScreenPreview);
    lv_obj_set_width(ui_ButtonHomeScreenPreview, 80);
    lv_obj_set_height(ui_ButtonHomeScreenPreview, 96);
    lv_obj_set_x(ui_ButtonHomeScreenPreview, -22);
    lv_obj_set_y(ui_ButtonHomeScreenPreview, -22);
    lv_obj_add_flag(ui_ButtonHomeScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenPreview, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonHomeScreenPreview, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenPreview, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenPreview, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_ButtonAxisMoveScreenPreview = lv_btn_create(ui_PanelPageScreenPreview);
    lv_obj_set_width(ui_ButtonAxisMoveScreenPreview, 80);
    lv_obj_set_height(ui_ButtonAxisMoveScreenPreview, 96);
    lv_obj_set_x(ui_ButtonAxisMoveScreenPreview, -22);
    lv_obj_set_y(ui_ButtonAxisMoveScreenPreview, 74);
    lv_obj_add_flag(ui_ButtonAxisMoveScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveScreenPreview, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMoveScreenPreview, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveScreenPreview, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveScreenPreview, 1, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_ImageFileManageScreenPreview = lv_img_create(ui_PanelPageScreenPreview);
    lv_img_set_src(ui_ImageFileManageScreenPreview, &ui_img_pagefilemanageselected_png);
    lv_obj_set_width(ui_ImageFileManageScreenPreview, 80);
    lv_obj_set_height(ui_ImageFileManageScreenPreview, 96);
    lv_obj_set_x(ui_ImageFileManageScreenPreview, -22);
    lv_obj_set_y(ui_ImageFileManageScreenPreview, 170);
    lv_obj_add_flag(ui_ImageFileManageScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFileManageScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonSettingsScreenPreview = lv_btn_create(ui_PanelPageScreenPreview);
    lv_obj_set_width(ui_ButtonSettingsScreenPreview, 80);
    lv_obj_set_height(ui_ButtonSettingsScreenPreview, 96);
    lv_obj_set_x(ui_ButtonSettingsScreenPreview, -22);
    lv_obj_set_y(ui_ButtonSettingsScreenPreview, 266);
    lv_obj_add_flag(ui_ButtonSettingsScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenPreview, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenPreview, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenPreview, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenPreview, 1, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_ButtonReserveScreenPreview = lv_btn_create(ui_PanelPageScreenPreview);
    lv_obj_set_width(ui_ButtonReserveScreenPreview, 80);
    lv_obj_set_height(ui_ButtonReserveScreenPreview, 96);
    lv_obj_set_x(ui_ButtonReserveScreenPreview, -22);
    lv_obj_set_y(ui_ButtonReserveScreenPreview, 362);
    lv_obj_add_flag(ui_ButtonReserveScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenPreview, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveScreenPreview, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonReserveScreenPreview, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonReserveScreenPreview, 1, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_PanelBackGroudScreenPreview = lv_obj_create(ui_ScreenPreview);
    lv_obj_set_width(ui_PanelBackGroudScreenPreview, 720);
    lv_obj_set_height(ui_PanelBackGroudScreenPreview, 480);
    lv_obj_set_x(ui_PanelBackGroudScreenPreview, 80);
    lv_obj_set_y(ui_PanelBackGroudScreenPreview, 0);
    lv_obj_clear_flag(ui_PanelBackGroudScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelBackGroudScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelBackGroudScreenPreview, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBackGroudScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBackGroudScreenPreview, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelCenterScreenPreview = lv_obj_create(ui_PanelBackGroudScreenPreview);
    lv_obj_set_width(ui_PanelCenterScreenPreview, 696);
    lv_obj_set_height(ui_PanelCenterScreenPreview, 456);
    lv_obj_set_x(ui_PanelCenterScreenPreview, -10);
    lv_obj_set_y(ui_PanelCenterScreenPreview, -10);
    lv_obj_clear_flag(ui_PanelCenterScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCenterScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCenterScreenPreview, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCenterScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCenterScreenPreview, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelFillingChartScreenPreview = lv_obj_create(ui_PanelCenterScreenPreview);
    lv_obj_set_width(ui_PanelFillingChartScreenPreview, 373);
    lv_obj_set_height(ui_PanelFillingChartScreenPreview, 426);
    lv_obj_set_x(ui_PanelFillingChartScreenPreview, -7);
    lv_obj_set_y(ui_PanelFillingChartScreenPreview, -7);
    lv_obj_clear_flag(ui_PanelFillingChartScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFillingChartScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFillingChartScreenPreview, lv_color_hex(0x0D0D0D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFillingChartScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFillingChartScreenPreview, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelFillingChartScreenPreview, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelFillingChartScreenPreview, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelFillingChartScreenPreview, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelFillingChartScreenPreview, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelFillingChartScreenPreview, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelFillingChartScreenPreview, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelFillingChartScreenPreview, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_ImageFillingChartScreenPreview = lv_img_create(ui_PanelFillingChartScreenPreview);
    lv_obj_set_width(ui_ImageFillingChartScreenPreview, 300);
    lv_obj_set_height(ui_ImageFillingChartScreenPreview, 300);
    lv_obj_set_x(ui_ImageFillingChartScreenPreview, 11);
    lv_obj_set_y(ui_ImageFillingChartScreenPreview, 42);
    lv_obj_add_flag(ui_ImageFillingChartScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFillingChartScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ImageFillingChartScreenPreview, lv_color_hex(0x070809), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ImageFillingChartScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPrintOptAndFileInfo = lv_obj_create(ui_PanelCenterScreenPreview);
    lv_obj_set_width(ui_PanelPrintOptAndFileInfo, 294);
    lv_obj_set_height(ui_PanelPrintOptAndFileInfo, 426);
    lv_obj_set_x(ui_PanelPrintOptAndFileInfo, 367);
    lv_obj_set_y(ui_PanelPrintOptAndFileInfo, -7);
    lv_obj_clear_flag(ui_PanelPrintOptAndFileInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPrintOptAndFileInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPrintOptAndFileInfo, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrintOptAndFileInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPrintOptAndFileInfo, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFileNameScreenPreview = lv_label_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_LabelFileNameScreenPreview, 260);
    lv_obj_set_height(ui_LabelFileNameScreenPreview, 70);
    lv_obj_set_x(ui_LabelFileNameScreenPreview, -2);
    lv_obj_set_y(ui_LabelFileNameScreenPreview, -13);
    lv_label_set_long_mode(ui_LabelFileNameScreenPreview, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_LabelFileNameScreenPreview, "");
    lv_obj_set_style_text_color(ui_LabelFileNameScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFileNameScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFileNameScreenPreview, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelLine1ScreenPreview = lv_obj_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_PanelLine1ScreenPreview, 272);
    lv_obj_set_height(ui_PanelLine1ScreenPreview, 1);
    lv_obj_set_x(ui_PanelLine1ScreenPreview, -4);
    lv_obj_set_y(ui_PanelLine1ScreenPreview, 65);
    lv_obj_clear_flag(ui_PanelLine1ScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelLine1ScreenPreview, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLine1ScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLine1ScreenPreview, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageTotelTimeScreenPreview = lv_img_create(ui_PanelPrintOptAndFileInfo);
    lv_img_set_src(ui_ImageTotelTimeScreenPreview, &ui_img_totaltime_png);
    lv_obj_set_width(ui_ImageTotelTimeScreenPreview, 22);
    lv_obj_set_height(ui_ImageTotelTimeScreenPreview, 22);
    lv_obj_set_x(ui_ImageTotelTimeScreenPreview, 0);
    lv_obj_set_y(ui_ImageTotelTimeScreenPreview, 153);
    lv_obj_add_flag(ui_ImageTotelTimeScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageTotelTimeScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelTotleTimeScreenPreview_ = lv_label_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_LabelTotleTimeScreenPreview_, 160);
    lv_obj_set_height(ui_LabelTotleTimeScreenPreview_, 35);
    lv_obj_set_x(ui_LabelTotleTimeScreenPreview_, 25);
    lv_obj_set_y(ui_LabelTotleTimeScreenPreview_, 151);
    lv_label_set_long_mode(ui_LabelTotleTimeScreenPreview_, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelTotleTimeScreenPreview_, "");
    lv_obj_set_style_text_color(ui_LabelTotleTimeScreenPreview_, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTotleTimeScreenPreview_, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTotleTimeScreenPreview_, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelMaterType = lv_obj_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_PanelMaterType, 70);
    lv_obj_set_height(ui_PanelMaterType, 32);
    lv_obj_set_x(ui_PanelMaterType, 196);
    lv_obj_set_y(ui_PanelMaterType, 75);
    lv_obj_clear_flag(ui_PanelMaterType, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //lv_obj_set_style_radius(ui_PanelMaterType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelMaterType, lv_color_hex(0xFA5A15), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMaterType, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelMaterType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelMaterType, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelMaterType = lv_label_create(ui_PanelMaterType);
    lv_obj_set_width(ui_LabelMaterType, 60);
    lv_obj_set_height(ui_LabelMaterType, 25);
    lv_obj_set_align(ui_LabelMaterType, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelMaterType, "ABS");
    lv_obj_set_style_text_align(ui_LabelMaterType, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelMaterType, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelMaterType, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelMaterType, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageUsageMaterScreenPreview = lv_img_create(ui_PanelPrintOptAndFileInfo);
    lv_img_set_src(ui_ImageUsageMaterScreenPreview, &ui_img_materialusage_png);
    lv_obj_set_width(ui_ImageUsageMaterScreenPreview, 22);
    lv_obj_set_height(ui_ImageUsageMaterScreenPreview, 22);
    lv_obj_set_x(ui_ImageUsageMaterScreenPreview, 0);
    lv_obj_set_y(ui_ImageUsageMaterScreenPreview, 190);
    lv_obj_add_flag(ui_ImageUsageMaterScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageUsageMaterScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelUsageMaterScreenPreview = lv_label_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_LabelUsageMaterScreenPreview, 160);
    lv_obj_set_height(ui_LabelUsageMaterScreenPreview, 35);
    lv_obj_set_x(ui_LabelUsageMaterScreenPreview, 25);
    lv_obj_set_y(ui_LabelUsageMaterScreenPreview, 188);
    lv_label_set_long_mode(ui_LabelUsageMaterScreenPreview, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelUsageMaterScreenPreview, "");
    lv_obj_set_style_text_color(ui_LabelUsageMaterScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelUsageMaterScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelUsageMaterScreenPreview, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageHotendTemperScreenPreview = lv_img_create(ui_PanelPrintOptAndFileInfo);
    lv_img_set_src(ui_ImageHotendTemperScreenPreview, &ui_img_preview_hotend_png);
    lv_obj_set_width(ui_ImageHotendTemperScreenPreview, 22);
    lv_obj_set_height(ui_ImageHotendTemperScreenPreview, 22);
    lv_obj_set_x(ui_ImageHotendTemperScreenPreview, 0);
    lv_obj_set_y(ui_ImageHotendTemperScreenPreview, 116);
    lv_obj_add_flag(ui_ImageHotendTemperScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendTemperScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelHotendTemperScreenPreview = lv_label_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_LabelHotendTemperScreenPreview, 160);
    lv_obj_set_height(ui_LabelHotendTemperScreenPreview, 35);
    lv_obj_set_x(ui_LabelHotendTemperScreenPreview, 25);
    lv_obj_set_y(ui_LabelHotendTemperScreenPreview, 113);
    lv_label_set_long_mode(ui_LabelHotendTemperScreenPreview, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelHotendTemperScreenPreview, "200°C");
    lv_obj_set_style_text_color(ui_LabelHotendTemperScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTemperScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTemperScreenPreview, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageBedTemperScreenPreview = lv_img_create(ui_PanelPrintOptAndFileInfo);
    lv_img_set_src(ui_ImageBedTemperScreenPreview, &ui_img_preview_bed_png);
    lv_obj_set_width(ui_ImageBedTemperScreenPreview, 22);
    lv_obj_set_height(ui_ImageBedTemperScreenPreview, 22);
    lv_obj_set_x(ui_ImageBedTemperScreenPreview, 0);
    lv_obj_set_y(ui_ImageBedTemperScreenPreview, 79);
    lv_obj_add_flag(ui_ImageBedTemperScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBedTemperScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelBedTemperScreenPreview = lv_label_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_LabelBedTemperScreenPreview, 160);
    lv_obj_set_height(ui_LabelBedTemperScreenPreview, 35);
    lv_obj_set_x(ui_LabelBedTemperScreenPreview, 25);
    lv_obj_set_y(ui_LabelBedTemperScreenPreview, 78);
    lv_label_set_long_mode(ui_LabelBedTemperScreenPreview, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelBedTemperScreenPreview, "60°C");
    lv_obj_set_style_text_color(ui_LabelBedTemperScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemperScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemperScreenPreview, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CheckboxAutoLevelScreenPreview = lv_checkbox_create(ui_PanelPrintOptAndFileInfo);
    lv_checkbox_set_text(ui_CheckboxAutoLevelScreenPreview, PrinterAdjust[language_index]);
    lv_obj_set_width(ui_CheckboxAutoLevelScreenPreview, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CheckboxAutoLevelScreenPreview, 32);
    lv_obj_set_x(ui_CheckboxAutoLevelScreenPreview, 6);
    lv_obj_set_y(ui_CheckboxAutoLevelScreenPreview, 281);
    lv_obj_add_flag(ui_CheckboxAutoLevelScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CheckboxAutoLevelScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CheckboxAutoLevelScreenPreview, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_CheckboxAutoLevelScreenPreview, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_CheckboxAutoLevelScreenPreview, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_CheckboxAutoLevelScreenPreview, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CheckboxAutoLevelScreenPreview, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CheckboxAutoLevelScreenPreview, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CheckboxAutoLevelScreenPreview, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_CheckboxAutoLevelScreenPreview, 20);

    ui_PanelLine2ScreenPreview = lv_obj_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_PanelLine2ScreenPreview, 272);
    lv_obj_set_height(ui_PanelLine2ScreenPreview, 1);
    lv_obj_set_x(ui_PanelLine2ScreenPreview, -4);
    lv_obj_set_y(ui_PanelLine2ScreenPreview, 325);
    lv_obj_clear_flag(ui_PanelLine2ScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelLine2ScreenPreview, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLine2ScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLine2ScreenPreview, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelActionPrintScreenPreview = lv_obj_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_PanelActionPrintScreenPreview, 294);
    lv_obj_set_height(ui_PanelActionPrintScreenPreview, 60);
    lv_obj_set_x(ui_PanelActionPrintScreenPreview, -22);
    lv_obj_set_y(ui_PanelActionPrintScreenPreview, 343);
    lv_obj_clear_flag(ui_PanelActionPrintScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelActionPrintScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelActionPrintScreenPreview, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelActionPrintScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelActionPrintScreenPreview, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonBackFileListScreenPreview = lv_btn_create(ui_PanelActionPrintScreenPreview);
    lv_obj_set_width(ui_ButtonBackFileListScreenPreview, 116);
    lv_obj_set_height(ui_ButtonBackFileListScreenPreview, 60);
    lv_obj_set_x(ui_ButtonBackFileListScreenPreview, -4);
    lv_obj_set_y(ui_ButtonBackFileListScreenPreview, -22);
    lv_obj_add_flag(ui_ButtonBackFileListScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonBackFileListScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonBackFileListScreenPreview, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonBackFileListScreenPreview, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBackFileListScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonBackFileListScreenPreview, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonBackFileListScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonBackFileListScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackFileListScreenPreview, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonBackFileListScreenPreview, 255,
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonBackFileListScreenPreview, 2,
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonBackFileListScreenPreview, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelBackFileListScreenPreview = lv_label_create(ui_ButtonBackFileListScreenPreview);
    lv_obj_set_width(ui_LabelBackFileListScreenPreview, 110);
    lv_obj_set_height(ui_LabelBackFileListScreenPreview, 35);
    lv_obj_set_align(ui_LabelBackFileListScreenPreview, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelBackFileListScreenPreview, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelBackFileListScreenPreview, Back[language_index]);
    lv_obj_set_style_text_align(ui_LabelBackFileListScreenPreview, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBackFileListScreenPreview, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonStartPrintScreenPreview = lv_btn_create(ui_PanelActionPrintScreenPreview);
    lv_obj_set_width(ui_ButtonStartPrintScreenPreview, 146);
    lv_obj_set_height(ui_ButtonStartPrintScreenPreview, 60);
    lv_obj_set_x(ui_ButtonStartPrintScreenPreview, 126);
    lv_obj_set_y(ui_ButtonStartPrintScreenPreview, -22);
    lv_obj_add_flag(ui_ButtonStartPrintScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonStartPrintScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonStartPrintScreenPreview, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonStartPrintScreenPreview, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonStartPrintScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonStartPrintScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonStartPrintScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonStartPrintScreenPreview, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_ButtonStartPrintScreenPreview, lv_color_hex(0x4190A2),
    //                               LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_ButtonStartPrintScreenPreview, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_ButtonStartPrintScreenPreview, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_ButtonStartPrintScreenPreview, lv_color_hex(0x000000),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonStartPrintScreenPreview, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonStartPrintScreenPreview, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonStartPrintScreenPreview, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelBackFileListScreenPreview1 = lv_label_create(ui_ButtonStartPrintScreenPreview);
    lv_obj_set_width(ui_LabelBackFileListScreenPreview1, 140);
    lv_obj_set_height(ui_LabelBackFileListScreenPreview1, 35);
    lv_obj_set_align(ui_LabelBackFileListScreenPreview1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelBackFileListScreenPreview1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelBackFileListScreenPreview1, Print[language_index]);
    lv_obj_set_style_text_align(ui_LabelBackFileListScreenPreview1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBackFileListScreenPreview1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ButtonHomeScreenPreview, ui_event_ButtonHomeScreenPreview, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMoveScreenPreview, ui_event_ButtonAxisMoveScreenPreview, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsScreenPreview, ui_event_ButtonSettingsScreenPreview, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserveScreenPreview, ui_event_ButtonReserveScreenPreview, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ImageFillingChartScreenPreview, ui_event_ImageFillingChartScreenPreview, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_PanelFillingChartScreenPreview, ui_event_PanelFillingChartScreenPreview, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonBackFileListScreenPreview, ui_event_ButtonBackFileListScreenPreview, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonStartPrintScreenPreview, ui_event_ButtonStartPrintScreenPreview, LV_EVENT_ALL, NULL);

}


void LoadPreviewScreen()
{
    lv_disp_load_scr(ui_ScreenPreview);
    lv_obj_add_state(ui_CheckboxAutoLevelScreenPreview, LV_STATE_CHECKED);
    get_printer_data(0x06,1,"7");
}


void PreviewPageHomeBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( home_printing_is_printing_finished() )
        LoadHomeNormalScreen();
    else
        LoadHomePrintingScreen();
}

void PreviewPageAxisBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadAxisMoveScreen();
}

void PreviewPageSettingsBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadSettingsScreen();
}

void PreviewPageReserveBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadCustomerServiceScreen();
}

void PreviewPageBackFileListBtnClicke(lv_event_t * e)
{
    if(print_from != FROM_HISTORY)
        set_last_index(get_current_page_number());
	// Your code here
    if ( is_preview_file_from_root_dir )
        LoadFileManageScreen();
    else
        LoadSubDirScreen();
    
    //memset(preview_filling_chart_name, 0, sizeof(preview_filling_chart_name));
}

void stop_print()
{
    CrLogI("don't have material_seneor,stop print");
    selftest_messagebox_close();
}

void continue_print()
{
    CrLogI("don't have material_seneor,continue print");
    selftest_messagebox_close();

    bool Isautolevel = false;
    if ( lv_obj_has_state(ui_CheckboxAutoLevelScreenPreview, LV_STATE_CHECKED) )
        Isautolevel = true;
    switch (print_from)
    {
        case FROM_LOCAL:send_set_print_start_cmd(chart_file_index, 1, Isautolevel);break;
        case FROM_UDISK:send_set_print_start_cmd(chart_file_index, 2, Isautolevel);break;
        case FROM_HISTORY:send_set_print_start_cmd(chart_file_index, 3, Isautolevel);break;
        default:
            break;
    }        
    send_get_filling_chart_info_cmd(chart_file_index);
}

void PreviewPageStartPrintBtnClicked(lv_event_t * e)
{
    if(print_state != 1)
    {
        CrLogI("preview page:machine state is print %d,don't start the print",print_state);
        create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
        return;
    }
    if(material_seneor == '4')
    {
        CrLogI("material_seneor state: %c",material_seneor);
        // //错误弹窗形式
        void (*btns_callback[2])(void) = {&continue_print, &stop_print};
        create_selftest_messagebox(KindTips[get_cur_language_index()], MaterialSeneorTips[get_cur_language_index()], ErrorBtnContinuePrint[get_cur_language_index()], ErrorBtnStopPrint[get_cur_language_index()], btns_callback);

        // create_msgbox(FilamentRunOutMsg[get_cur_language_index()], NULL, 1000, lv_scr_act());
        return;
    }
	// Your code here
    if ( chart_file_index <= 0 )
    {
        char *btns[1] = {Confirm[get_cur_language_index()]};
        //char btns[1][20] = {"confirm"};  // error used
        void (*btns_array[1])(void) = {NULL}; 
        create_custom_messagebox(Warning[get_cur_language_index()],FileIndexInvalid[get_cur_language_index()], btns, btns_array, 1, true, false);

        return ;
    }

    // if ( lv_obj_has_state(ui_CheckboxAutoLevelScreenPreview, LV_STATE_CHECKED) )
    // {
    //     if ( level_mode == PEOBE_LEVEL )
    //     {
    //         printprelevel_flag = true;
    //         set_printer_data(0x09,2,"42");  //调平前设置点数避免无法调平
    //         send_set_start_auto_level_cmd();
    //     }
    //     else if ( level_mode ==  PRESSURE_SENSOR_LEVEL )
    //     {

    //     }
    //     else if ( level_mode ==  (PRESSURE_SENSOR_LEVEL + PEOBE_LEVEL ))
    //     {

    //     }
    // }
        

    //preview_send_print_file_cmd(chart_file_index);
    bool Isautolevel = false;
    if ( lv_obj_has_state(ui_CheckboxAutoLevelScreenPreview, LV_STATE_CHECKED) )
        Isautolevel = true;
    switch (print_from)
    {
        case FROM_LOCAL:send_set_print_start_cmd(chart_file_index, 1, Isautolevel);break;
        case FROM_UDISK:send_set_print_start_cmd(chart_file_index, 2, Isautolevel);break;
        case FROM_HISTORY:send_set_print_start_cmd(chart_file_index, 3, Isautolevel);break;
        default:
            break;
    }        
    send_get_filling_chart_info_cmd(chart_file_index);
    // create_custom_reminderbox(OpeningFileMsg[get_cur_language_index()], true);
    // //update_custom_reminderbox_image(const lv_img_dsc_t * img_png); 
    // set_custom_reminderbox_display_timeout(5, &preview_jump_to_printing_event_callback);
}

void preview_set_file_info(char *file_name, uint32_t totel_time, uint32_t mater_used, int32_t file_index, char * filament_type, int nozzletemp, int bedtemp, PrintFrom type)
{
    if ( !file_name )
    {
        totel_time = 0;
        mater_used = 0;
        file_index = -1;
    }

    if ( ui_LabelUsageMaterScreenPreview )
    {
        char buff[10] = {0};
        uint8_t temp = mater_used % 100;  //计算分米的余数
        float fused = mater_used / 1000.0f;

        sprintf(buff, "%.1fm", fused + 0.05);

        lv_label_set_text(ui_LabelUsageMaterScreenPreview, buff);
    }

    if ( ui_LabelFileNameScreenPreview )
    {
        if ( !file_name )
        {
            lv_label_set_text(ui_LabelFileNameScreenPreview, "");
            strcpy(preview_file_name, "");
        }
        else
        {
            lv_label_set_text(ui_LabelFileNameScreenPreview, file_name);
            strncpy(preview_file_name, file_name, sizeof(preview_file_name) - 1);
        }
    }

    if ( ui_LabelTotleTimeScreenPreview_ )
    {
        int32_t time = totel_time ;  // totel time unit is seconds
        char buff[10] = {0};
        sprintf(buff, "%dmin", time / 60);
        lv_label_set_text(ui_LabelTotleTimeScreenPreview_, buff);
    }

    if( ui_LabelMaterType )
    {
        CrLogI("the filament type is %s.",filament_type);
        if( filament_type[0] != '\0')
        {
            lv_obj_clear_flag(ui_PanelMaterType,LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_LabelMaterType, filament_type);
        }
        else
        {
            lv_obj_add_flag(ui_PanelMaterType,LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_LabelMaterType, "");
        }
    }
        
    preview_set_model_printer_temper(nozzletemp, bedtemp);   
    chart_file_index = file_index;
    print_from = type;
    // if ( ui_ImageFillingChartScreenPreview )
    //     lv_img_set_src(ui_ImageFillingChartScreenPreview, &ui_img_crealitylogo_png);
    
}

void preview_set_filling_chart_info(char *chart_png_name, uint16_t pixel_start, uint16_t pixel_end, float mode_height, float mode_layer_height)
{
    if ( chart_png_name )
    {
        memset(preview_filling_chart_name, 0, sizeof(preview_filling_chart_name));
        strncpy(preview_filling_chart_name, chart_png_name, sizeof(preview_filling_chart_name) - 1);
    }
    else
        memset(preview_filling_chart_name, 0, sizeof(preview_filling_chart_name));

    chart_pixel_start = pixel_start;
    chart_pixel_end = pixel_end;
    chart_mode_height = mode_height;
    chart_mode_layer_height = mode_layer_height;

    CrLogI("preview file name: %s, length:%d ", preview_filling_chart_name, strlen( preview_filling_chart_name ));
    // if ( !lv_obj_is_visible(ui_PanelPageScreenPreview) )
    //     return;

    //lv_img_cache_invalidate_src(NULL);
    if ( strlen( preview_filling_chart_name ) > 0 )
    {
        char buff[258] = {0};
        snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, preview_filling_chart_name);
        // strncpy(buff + 1, preview_filling_chart_name, sizeof(buff) - 2);
        CrLogI("-----------rename preview file name: %s, ", buff);
        lv_img_set_src(ui_ImageFillingChartScreenPreview, buff);
    }
    else
    {
        lv_img_set_src(ui_ImageFillingChartScreenPreview, &ui_img_crealitylogo_png);
    }

    // lv_obj_add_flag(ui_ImageFillingChartScreenPreview, LV_OBJ_FLAG_HIDDEN);

    // lv_timer_t *reminder_display_timer = lv_timer_create(preview_timeout_callback, 10, NULL);
    // lv_timer_set_repeat_count(reminder_display_timer, 1);
}

void preview_set_model_printer_temper(uint16_t hotend_temper, uint8_t bed_temper)
{
    char buff[10] = {0};
    if ( ui_LabelBedTemperScreenPreview )
    {
        if(bed_temper > 0)   //代表解析到数据
        {
            sprintf(buff, "%d°C", bed_temper);
            lv_label_set_text(ui_LabelBedTemperScreenPreview, buff);
            lv_obj_clear_flag(ui_LabelBedTemperScreenPreview, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_ImageBedTemperScreenPreview, LV_OBJ_FLAG_HIDDEN);

        }
        else
        {
            lv_obj_add_flag(ui_LabelBedTemperScreenPreview, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_ImageBedTemperScreenPreview, LV_OBJ_FLAG_HIDDEN);
        }

    }

    if ( ui_LabelHotendTemperScreenPreview )
    {
        if(hotend_temper > 0)
        {
            memset(buff, 0, sizeof(buff));
            sprintf(buff, "%d°C", hotend_temper);
            lv_label_set_text(ui_LabelHotendTemperScreenPreview, buff);
            lv_obj_clear_flag(ui_LabelHotendTemperScreenPreview, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_ImageHotendTemperScreenPreview, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            lv_obj_add_flag(ui_LabelHotendTemperScreenPreview, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_ImageHotendTemperScreenPreview, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void preview_set_print_file_name_and_chart(char *file_name, char *chart_name)
{
    if ( !file_name )
        return ;

    
}

void preview_set_mode_file_from_dir_type(bool root_dir)
{
    is_preview_file_from_root_dir = root_dir;
}

void preview_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_CheckboxAutoLevelScreenPreview )
        lv_checkbox_set_text(ui_CheckboxAutoLevelScreenPreview, PrinterAdjust[language_index]);

    if ( ui_LabelBackFileListScreenPreview )
        lv_label_set_text(ui_LabelBackFileListScreenPreview, Back[language_index]);

    if ( ui_LabelBackFileListScreenPreview1 )
        lv_label_set_text(ui_LabelBackFileListScreenPreview1, Print[language_index]);
}

void preview_set_level_mode(uint32_t Mode)
{
    level_mode = Mode;
}

void create_tips(int percent)
{
    char temp[100] = {0};
    if(percent < 100)
    {
        snprintf(temp, 100, "%s:%d%%", CopyProcess[get_cur_language_index()],percent);
        create_msgbox(temp, NULL, 0, lv_scr_act());
    }
    if(percent >= 100)
    {
        snprintf(temp, 100, "%s:%d%%", CopyProcess[get_cur_language_index()],percent);
        create_msgbox(temp, NULL, 1000, lv_scr_act());
    }
    if(percent == -1)
    {
        snprintf(temp, 100, "%s", CopyErrorResult[get_cur_language_index()]);
        create_msgbox(temp, NULL, 1000, lv_scr_act());
    }
}

void FromHistoryToPreview(bool flag, HistoryInfo_t singlefile)
{
    if(!flag)
    {
        create_msgbox(NoRecords[get_cur_language_index()], NULL, 1000, lv_scr_act());
    }
    else
    {
        preview_set_file_info(singlefile.filename, atoi(singlefile.timecost),atoi(singlefile.consumables), atoi(singlefile.index), singlefile.filamenttype, atoi(singlefile.nozzletemp)/100, atoi(singlefile.bedtemp)/100, FROM_HISTORY);
        preview_set_filling_chart_info(singlefile.preview, 0, 300, 0, 0);
        preview_set_mode_file_from_dir_type(true);
        LoadPreviewScreen();
    }
}