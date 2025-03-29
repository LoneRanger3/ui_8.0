#include "ui_screen_Preview.h"
#include "src/core/lv_obj_pos.h"
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


lv_obj_t * ui_ScreenPreview;
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
char preview_filling_chart_name[256] = {0};
static char print_gcode_path[256] = {0};
static char preview_file_name[64] = {0};
static uint16_t chart_pixel_start = 0, chart_pixel_end = 0;
static float chart_mode_height = 0.0f, chart_mode_layer_height = 0.0f;
static int16_t chart_file_index = 0;
static PrintFrom print_from;
static uint32_t level_mode = PEOBE_LEVEL;
EventGrop_Data FilePreview;

void send_print_file_info(void);
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
static void PreviewPageChangeObjs(uint8_t index);
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
    lv_obj_set_style_bg_color(ui_ScreenPreview, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

   // FilePreview.GropName = lv_group_create();
    init_pages(ui_ScreenPreview, PreviewPageChangeObjs, LoadPreviewScreen);

    uint8_t language_index = get_cur_language_index();

    ui_PanelPageScreenPreview = lv_obj_create(ui_ScreenPreview);
    lv_obj_set_width(ui_PanelPageScreenPreview, 68);
    lv_obj_set_height(ui_PanelPageScreenPreview, 360);
    lv_obj_clear_flag(ui_PanelPageScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPageScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPageScreenPreview, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui_PanelPageScreenPreview, 0, 60);

    ui_ButtonHomeScreenPreview = lv_btn_create(ui_PanelPageScreenPreview);
    lv_obj_set_width(ui_ButtonHomeScreenPreview, 68);
    lv_obj_set_height(ui_ButtonHomeScreenPreview, 72);
    lv_obj_set_x(ui_ButtonHomeScreenPreview, -18);
    lv_obj_set_y(ui_ButtonHomeScreenPreview, -18);
    lv_obj_add_flag(ui_ButtonHomeScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenPreview, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonHomeScreenPreview, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenPreview, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenPreview, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_ButtonAxisMoveScreenPreview = lv_btn_create(ui_PanelPageScreenPreview);
    lv_obj_set_width(ui_ButtonAxisMoveScreenPreview, 68);
    lv_obj_set_height(ui_ButtonAxisMoveScreenPreview, 72);
    lv_obj_set_x(ui_ButtonAxisMoveScreenPreview, -18);
    lv_obj_set_y(ui_ButtonAxisMoveScreenPreview, 54);
    lv_obj_add_flag(ui_ButtonAxisMoveScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveScreenPreview, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMoveScreenPreview, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveScreenPreview, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveScreenPreview, 1, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_ImageFileManageScreenPreview = lv_img_create(ui_PanelPageScreenPreview);
    lv_img_set_src(ui_ImageFileManageScreenPreview, &ui_img_pagefilemanageselected_png);
    lv_obj_set_width(ui_ImageFileManageScreenPreview, 68);
    lv_obj_set_height(ui_ImageFileManageScreenPreview, 72);
    lv_obj_set_x(ui_ImageFileManageScreenPreview, -18);
    lv_obj_set_y(ui_ImageFileManageScreenPreview, 126);
    lv_obj_add_flag(ui_ImageFileManageScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFileManageScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonSettingsScreenPreview = lv_btn_create(ui_PanelPageScreenPreview);
    lv_obj_set_width(ui_ButtonSettingsScreenPreview, 68);
    lv_obj_set_height(ui_ButtonSettingsScreenPreview, 72);
    lv_obj_set_x(ui_ButtonSettingsScreenPreview, -18);
    lv_obj_set_y(ui_ButtonSettingsScreenPreview, 198);
    lv_obj_add_flag(ui_ButtonSettingsScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenPreview, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenPreview, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenPreview, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenPreview, 1, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_ButtonReserveScreenPreview = lv_btn_create(ui_PanelPageScreenPreview);
    lv_obj_set_width(ui_ButtonReserveScreenPreview, 68);
    lv_obj_set_height(ui_ButtonReserveScreenPreview, 72);
    lv_obj_set_x(ui_ButtonReserveScreenPreview, -18);
    lv_obj_set_y(ui_ButtonReserveScreenPreview, 270);
    lv_obj_add_flag(ui_ButtonReserveScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenPreview, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveScreenPreview, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonReserveScreenPreview, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonReserveScreenPreview, 1, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);


    // ui_PanelBackGroudScreenPreview = lv_obj_create(ui_ScreenPreview);
    // lv_obj_set_width(ui_PanelBackGroudScreenPreview, 720);
    // lv_obj_set_height(ui_PanelBackGroudScreenPreview, 480);
    // lv_obj_set_x(ui_PanelBackGroudScreenPreview, 80);
    // lv_obj_set_y(ui_PanelBackGroudScreenPreview, 0);
    // lv_obj_clear_flag(ui_PanelBackGroudScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_PanelBackGroudScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_PanelBackGroudScreenPreview, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_PanelBackGroudScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_PanelBackGroudScreenPreview, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelCenterScreenPreview = lv_obj_create(ui_ScreenPreview);
    lv_obj_set_width(ui_PanelCenterScreenPreview, 556);
    lv_obj_set_height(ui_PanelCenterScreenPreview, 344);
    lv_obj_set_x(ui_PanelCenterScreenPreview, 76);
    lv_obj_set_y(ui_PanelCenterScreenPreview, 68);
    lv_obj_clear_flag(ui_PanelCenterScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCenterScreenPreview, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCenterScreenPreview, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCenterScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCenterScreenPreview, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelCenterScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelFillingChartScreenPreview = lv_obj_create(ui_PanelCenterScreenPreview);
    lv_obj_set_width(ui_PanelFillingChartScreenPreview, 274);
    lv_obj_set_height(ui_PanelFillingChartScreenPreview, 324);
    lv_obj_set_x(ui_PanelFillingChartScreenPreview, 12);
    lv_obj_set_y(ui_PanelFillingChartScreenPreview, 10);
    lv_obj_clear_flag(ui_PanelFillingChartScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFillingChartScreenPreview, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_align(ui_PanelFillingChartScreenPreview, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_opa(ui_PanelFillingChartScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_PanelFillingChartScreenPreview, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFillingChartScreenPreview, lv_color_hex(0x000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelFillingChartScreenPreview, lv_color_hex(0x000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_PanelFillingChartScreenPreview, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_PanelFillingChartScreenPreview, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_color(ui_PanelFillingChartScreenPreview, lv_color_hex(0x4190A2),
    //                               LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_PanelFillingChartScreenPreview, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_PanelFillingChartScreenPreview, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    // lv_obj_set_style_border_side(ui_PanelFillingChartScreenPreview, LV_BORDER_SIDE_FULL,
    //                              LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_pad_all(ui_PanelFillingChartScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageFillingChartScreenPreview = lv_img_create(ui_PanelFillingChartScreenPreview);
    lv_obj_set_width(ui_ImageFillingChartScreenPreview, 300); 
    lv_obj_set_height(ui_ImageFillingChartScreenPreview, 300); 
    lv_obj_set_x(ui_ImageFillingChartScreenPreview, 1);
    lv_obj_set_y(ui_ImageFillingChartScreenPreview, 21);
    lv_obj_add_flag(ui_ImageFillingChartScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFillingChartScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ImageFillingChartScreenPreview, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ImageFillingChartScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ImageFillingChartScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //详细信息面板
    ui_PanelPrintOptAndFileInfo = lv_obj_create(ui_PanelCenterScreenPreview);
    lv_obj_set_width(ui_PanelPrintOptAndFileInfo, 264); //270
    lv_obj_set_height(ui_PanelPrintOptAndFileInfo, 344);
    // lv_obj_set_x(ui_PanelPrintOptAndFileInfo, 298);
    // lv_obj_set_y(ui_PanelPrintOptAndFileInfo, 0);
    lv_obj_set_align(ui_PanelPrintOptAndFileInfo, LV_ALIGN_RIGHT_MID);
    lv_obj_clear_flag(ui_PanelPrintOptAndFileInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPrintOptAndFileInfo, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(ui_PanelPrintOptAndFileInfo, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPrintOptAndFileInfo, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrintOptAndFileInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPrintOptAndFileInfo, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelPrintOptAndFileInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelPrintOptAndFileInfo, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFileNameScreenPreview = lv_label_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_LabelFileNameScreenPreview, 234); //260 LV_SIZE_CONTENT
    lv_obj_set_height(ui_LabelFileNameScreenPreview, 30);
    // lv_obj_set_x(ui_LabelFileNameScreenPreview, -2);
    // lv_obj_set_y(ui_LabelFileNameScreenPreview, -13);
    lv_obj_set_pos(ui_LabelFileNameScreenPreview, 18, 16);
    lv_label_set_long_mode(ui_LabelFileNameScreenPreview, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_LabelFileNameScreenPreview, "");
    lv_obj_set_style_text_color(ui_LabelFileNameScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFileNameScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFileNameScreenPreview, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelLine1ScreenPreview = lv_obj_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_PanelLine1ScreenPreview, 247);//272
    lv_obj_set_height(ui_PanelLine1ScreenPreview, 1);
    lv_obj_set_x(ui_PanelLine1ScreenPreview, 9);
    lv_obj_set_y(ui_PanelLine1ScreenPreview, 53);
    lv_obj_clear_flag(ui_PanelLine1ScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelLine1ScreenPreview, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLine1ScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLine1ScreenPreview, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageTotelTimeScreenPreview = lv_img_create(ui_PanelPrintOptAndFileInfo);
    lv_img_set_src(ui_ImageTotelTimeScreenPreview, &ui_img_totaltime_png);
    lv_obj_set_width(ui_ImageTotelTimeScreenPreview, 22);
    lv_obj_set_height(ui_ImageTotelTimeScreenPreview, 22);
    lv_obj_set_x(ui_ImageTotelTimeScreenPreview, 16);
    lv_obj_set_y(ui_ImageTotelTimeScreenPreview, 140);
    lv_obj_add_flag(ui_ImageTotelTimeScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageTotelTimeScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelTotleTimeScreenPreview_ = lv_label_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_LabelTotleTimeScreenPreview_, 160);
    lv_obj_set_height(ui_LabelTotleTimeScreenPreview_, 35);
    lv_obj_set_x(ui_LabelTotleTimeScreenPreview_, 41);
    lv_obj_set_y(ui_LabelTotleTimeScreenPreview_, 138);
    //lv_obj_align_to(ui_LabelTotleTimeScreenPreview_, ui_ImageTotelTimeScreenPreview, LV_ALIGN_OUT_RIGHT_MID, 3, 3);
    lv_label_set_long_mode(ui_LabelTotleTimeScreenPreview_, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelTotleTimeScreenPreview_, "");
    lv_obj_set_style_text_color(ui_LabelTotleTimeScreenPreview_, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTotleTimeScreenPreview_, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTotleTimeScreenPreview_, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelMaterType = lv_obj_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_PanelMaterType, 66);
    lv_obj_set_height(ui_PanelMaterType, 30);
    lv_obj_set_x(ui_PanelMaterType, 187);
    lv_obj_set_y(ui_PanelMaterType, 67);
    lv_obj_clear_flag(ui_PanelMaterType, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //lv_obj_set_style_radius(ui_PanelMaterType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelMaterType, lv_color_hex(0xFA6D31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMaterType, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelMaterType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelMaterType, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelMaterType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelMaterType = lv_label_create(ui_PanelMaterType);
    lv_obj_set_width(ui_LabelMaterType, 40);
    lv_obj_set_height(ui_LabelMaterType, 30);
    //lv_obj_align_to(ui_LabelMaterType, ui_PanelMaterType, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_align(ui_LabelMaterType, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelMaterType, "PLA"); //ABS
    lv_obj_set_style_text_align(ui_LabelMaterType, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelMaterType, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelMaterType, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelMaterType, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_LabelMaterType, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_ImageUsageMaterScreenPreview = lv_img_create(ui_PanelPrintOptAndFileInfo);
    lv_img_set_src(ui_ImageUsageMaterScreenPreview, &ui_img_materialusage_png);
    lv_obj_set_width(ui_ImageUsageMaterScreenPreview, 20); //22
    lv_obj_set_height(ui_ImageUsageMaterScreenPreview, 20); //22
    lv_obj_set_x(ui_ImageUsageMaterScreenPreview, 17);
    lv_obj_set_y(ui_ImageUsageMaterScreenPreview, 175);
    lv_obj_add_flag(ui_ImageUsageMaterScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageUsageMaterScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelUsageMaterScreenPreview = lv_label_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_LabelUsageMaterScreenPreview, 160);
    lv_obj_set_height(ui_LabelUsageMaterScreenPreview, 35);
    lv_obj_set_x(ui_LabelUsageMaterScreenPreview, 41);
    lv_obj_set_y(ui_LabelUsageMaterScreenPreview, 171);
    //lv_obj_align_to(ui_LabelUsageMaterScreenPreview, ui_ImageUsageMaterScreenPreview, LV_ALIGN_OUT_RIGHT_MID, 3, 3);
    lv_label_set_long_mode(ui_LabelUsageMaterScreenPreview, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelUsageMaterScreenPreview, "");
    lv_obj_set_style_text_color(ui_LabelUsageMaterScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelUsageMaterScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelUsageMaterScreenPreview, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //喷嘴
    ui_ImageHotendTemperScreenPreview = lv_img_create(ui_PanelPrintOptAndFileInfo);
    lv_img_set_src(ui_ImageHotendTemperScreenPreview, &ui_img_preview_hotend_png);
    lv_obj_set_width(ui_ImageHotendTemperScreenPreview, 22);
    lv_obj_set_height(ui_ImageHotendTemperScreenPreview, 22);
    lv_obj_set_x(ui_ImageHotendTemperScreenPreview, 16);
    lv_obj_set_y(ui_ImageHotendTemperScreenPreview, 107);
    lv_obj_add_flag(ui_ImageHotendTemperScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendTemperScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    
    ui_LabelHotendTemperScreenPreview = lv_label_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_LabelHotendTemperScreenPreview, 160);
    lv_obj_set_height(ui_LabelHotendTemperScreenPreview, 35);
    lv_obj_set_x(ui_LabelHotendTemperScreenPreview, 41);
    lv_obj_set_y(ui_LabelHotendTemperScreenPreview, 105);
    //lv_obj_align_to(ui_LabelHotendTemperScreenPreview, ui_ImageHotendTemperScreenPreview, LV_ALIGN_OUT_RIGHT_MID, 3, 3);
    lv_label_set_long_mode(ui_LabelHotendTemperScreenPreview, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelHotendTemperScreenPreview, "200°C");
    lv_obj_set_style_text_color(ui_LabelHotendTemperScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTemperScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTemperScreenPreview, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //热床
    ui_ImageBedTemperScreenPreview = lv_img_create(ui_PanelPrintOptAndFileInfo);
    lv_img_set_src(ui_ImageBedTemperScreenPreview, &ui_img_preview_bed_png);
    lv_obj_set_width(ui_ImageBedTemperScreenPreview, 22);
    lv_obj_set_height(ui_ImageBedTemperScreenPreview, 22);
    lv_obj_set_x(ui_ImageBedTemperScreenPreview, 15);
    lv_obj_set_y(ui_ImageBedTemperScreenPreview, 77);
    lv_obj_add_flag(ui_ImageBedTemperScreenPreview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBedTemperScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_all(ui_ImageBedTemperScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelBedTemperScreenPreview = lv_label_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_LabelBedTemperScreenPreview, 47);
    lv_obj_set_height(ui_LabelBedTemperScreenPreview, 32);
    lv_obj_set_x(ui_LabelBedTemperScreenPreview, 41);
    lv_obj_set_y(ui_LabelBedTemperScreenPreview, 76);
    //lv_obj_align_to(ui_LabelBedTemperScreenPreview, ui_ImageBedTemperScreenPreview, LV_ALIGN_OUT_RIGHT_MID, 3, 3);
   // lv_label_set_long_mode(ui_LabelBedTemperScreenPreview, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelBedTemperScreenPreview, "60°C");
    lv_obj_set_style_text_color(ui_LabelBedTemperScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemperScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemperScreenPreview, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //打印校准
    ui_CheckboxAutoLevelScreenPreview = lv_checkbox_create(ui_PanelPrintOptAndFileInfo);
    lv_checkbox_set_text(ui_CheckboxAutoLevelScreenPreview, PrinterAdjust[language_index]);
    // lv_obj_set_width(ui_CheckboxAutoLevelScreenPreview, 180);
    // lv_obj_set_height(ui_CheckboxAutoLevelScreenPreview, 32);
    lv_obj_set_x(ui_CheckboxAutoLevelScreenPreview, 18);
    lv_obj_set_y(ui_CheckboxAutoLevelScreenPreview, 226);
    lv_obj_clear_flag(ui_CheckboxAutoLevelScreenPreview, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_add_flag(ui_CheckboxAutoLevelScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CheckboxAutoLevelScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CheckboxAutoLevelScreenPreview, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_CheckboxAutoLevelScreenPreview, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_CheckboxAutoLevelScreenPreview, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_CheckboxAutoLevelScreenPreview, 1, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CheckboxAutoLevelScreenPreview, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CheckboxAutoLevelScreenPreview, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CheckboxAutoLevelScreenPreview, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_CheckboxAutoLevelScreenPreview, 20);
    //选中后样式
    lv_obj_set_style_border_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0xCDF6FF),
                                    LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_CheckboxAutoLevelScreenPreview, 255, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_CheckboxAutoLevelScreenPreview, 5, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_CheckboxAutoLevelScreenPreview, 0, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_CheckboxAutoLevelScreenPreview, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
  //  lv_obj_set_style_outline_color(ui_ManualtestCheckbox1, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_opa(ui_CheckboxAutoLevelScreenPreview, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
  //  lv_obj_set_style_pad_all(ui_CheckboxAutoLevelScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelLine2ScreenPreview = lv_obj_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_PanelLine2ScreenPreview, 250);
    lv_obj_set_height(ui_PanelLine2ScreenPreview, 1);
    lv_obj_set_x(ui_PanelLine2ScreenPreview, 6);
    lv_obj_set_y(ui_PanelLine2ScreenPreview, 265);
    lv_obj_clear_flag(ui_PanelLine2ScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelLine2ScreenPreview, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLine2ScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLine2ScreenPreview, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelActionPrintScreenPreview = lv_obj_create(ui_PanelPrintOptAndFileInfo);
    lv_obj_set_width(ui_PanelActionPrintScreenPreview, 258);
    lv_obj_set_height(ui_PanelActionPrintScreenPreview, 56);
    lv_obj_set_x(ui_PanelActionPrintScreenPreview, 6);
    lv_obj_set_y(ui_PanelActionPrintScreenPreview, 280);
    lv_obj_clear_flag(ui_PanelActionPrintScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelActionPrintScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelActionPrintScreenPreview, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelActionPrintScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelActionPrintScreenPreview, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelActionPrintScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //返回
    ui_ButtonBackFileListScreenPreview = lv_btn_create(ui_PanelActionPrintScreenPreview);
    lv_obj_set_width(ui_ButtonBackFileListScreenPreview, 100);
    lv_obj_set_height(ui_ButtonBackFileListScreenPreview, 52);
    lv_obj_set_x(ui_ButtonBackFileListScreenPreview, 0);
    lv_obj_set_y(ui_ButtonBackFileListScreenPreview, 0);
    lv_obj_add_flag(ui_ButtonBackFileListScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonBackFileListScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonBackFileListScreenPreview, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonBackFileListScreenPreview, lv_color_hex(0x28292D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBackFileListScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonBackFileListScreenPreview, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonBackFileListScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonBackFileListScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackFileListScreenPreview, lv_color_hex(0x4A4E57),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonBackFileListScreenPreview, 255,
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonBackFileListScreenPreview, 4,
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonBackFileListScreenPreview, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_pad_all(ui_ButtonBackFileListScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_ButtonBackFileListScreenPreview, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonBackFileListScreenPreview, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonBackFileListScreenPreview, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonBackFileListScreenPreview, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ButtonBackFileListScreenPreview, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonBackFileListScreenPreview, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    ui_LabelBackFileListScreenPreview = lv_label_create(ui_ButtonBackFileListScreenPreview);
    // lv_obj_set_width(ui_LabelBackFileListScreenPreview, 110);
    // lv_obj_set_height(ui_LabelBackFileListScreenPreview, 35);
    lv_obj_set_align(ui_LabelBackFileListScreenPreview, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelBackFileListScreenPreview, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelBackFileListScreenPreview, Back[language_index]);
    lv_obj_set_style_text_align(ui_LabelBackFileListScreenPreview, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBackFileListScreenPreview, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //打印
    ui_ButtonStartPrintScreenPreview = lv_btn_create(ui_PanelActionPrintScreenPreview);
    lv_obj_set_width(ui_ButtonStartPrintScreenPreview, 140);
    lv_obj_set_height(ui_ButtonStartPrintScreenPreview, 52);
    // lv_obj_set_x(ui_ButtonStartPrintScreenPreview, 116);
    // lv_obj_set_y(ui_ButtonStartPrintScreenPreview, 0);
    //lv_obj_align_to(ui_ButtonStartPrintScreenPreview, ui_ButtonBackFileListScreenPreview, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_obj_align(ui_ButtonStartPrintScreenPreview, LV_ALIGN_RIGHT_MID, -4, 0);
    lv_obj_add_flag(ui_ButtonStartPrintScreenPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonStartPrintScreenPreview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonStartPrintScreenPreview, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonStartPrintScreenPreview, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonStartPrintScreenPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonStartPrintScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonStartPrintScreenPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonStartPrintScreenPreview, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_ButtonStartPrintScreenPreview, lv_color_hex(0x4190A2),
    //                               LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_ButtonStartPrintScreenPreview, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_ButtonStartPrintScreenPreview, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_ButtonStartPrintScreenPreview, lv_color_hex(0x000000),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonStartPrintScreenPreview, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonStartPrintScreenPreview, 4, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonStartPrintScreenPreview, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);
    //滚动选中后样式                            
    lv_obj_set_style_border_color(ui_ButtonStartPrintScreenPreview, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonStartPrintScreenPreview, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonStartPrintScreenPreview, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonStartPrintScreenPreview, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ButtonStartPrintScreenPreview, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonStartPrintScreenPreview, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    

    ui_LabelBackFileListScreenPreview1 = lv_label_create(ui_ButtonStartPrintScreenPreview);
    // lv_obj_set_width(ui_LabelBackFileListScreenPreview1, 92);
    // lv_obj_set_height(ui_LabelBackFileListScreenPreview1, 32);
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
}

void PreviewPageBackFileListBtnClicke(lv_event_t * e)
{
	// Your code here
    // if ( is_preview_file_from_root_dir )
    // {
        //LoadFileManageScreen();
        BackPrepage(false);
    // }
    // else
    //     LoadSubDirScreen();
    
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
    // switch (print_from)
    // {
    //     case FROM_LOCAL:send_set_print_start_cmd(chart_file_index, 1, Isautolevel);break;
    //     case FROM_UDISK:send_set_print_start_cmd(chart_file_index, 2, Isautolevel);break;
    //     case FROM_HISTORY:send_set_print_start_cmd(chart_file_index, 3, Isautolevel);break;
    //     default:
    //         break;
    // }        
    //send_get_filling_chart_info_cmd(chart_file_index); //TODO: 协议一:字符串协议发送命令去master获取预览图 跳转到首页打印中
    send_print_file_info();
}

static void WarningConfirmCb(void)
{
    BackPrepage(true);
}

/**
 * @description: 点击预览打印按钮开始打印
 * @return {*}
 * @param {lv_event_t *} e
 */
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
    if ( strlen(preview_filling_chart_name) == 0 ) //最新协议不需要依据索引去控制打印
    {
        //char *btns[2] = {0};
        char *btns[1] = {Confirm[get_cur_language_index()]};
        //char btns[1][20] = {"confirm"};  // error used
        void (*btns_array[1])(void) = {&WarningConfirmCb}; 
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
    //TODO: 
    #if 0
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
    #endif
    send_print_file_info();
  //  send_get_filling_chart_info_cmd(chart_file_index); //TODO:最新协议此处不发获取预览图的命令，此处待研究
    // create_custom_reminderbox(OpeningFileMsg[get_cur_language_index()], true);
    // //update_custom_reminderbox_image(const lv_img_dsc_t * img_png); 
    // set_custom_reminderbox_display_timeout(5, &preview_jump_to_printing_event_callback);
}

void send_print_file_info(void)
{
    bool Isautolevel = false;

    MutableTypeData startPrint = MUTABLE_TYPE_DATA__INIT;
    startPrint.has_bytes_v = 1;

    startPrint.bytes_v.data = (uint8_t*)print_gcode_path;
    startPrint.bytes_v.len = strlen(print_gcode_path) + 1; //paraBuff
    
        
    if ( lv_obj_has_state(ui_CheckboxAutoLevelScreenPreview, LV_STATE_CHECKED) )
        Isautolevel = true;

    startPrint.has_int_v = Isautolevel;
    startPrint.int_v = 1;



    DisControlPrint disControl = DIS_CONTROL_PRINT__INIT;
    disControl.print = &startPrint;
    
    CrLogI("send_print_file_info\n");

    GET_MESSAGE_BUFF(buff);
    size_t len = dis_control_print__pack(&disControl, buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_SERVER, SERVER_CMD_DIS_CONTROL_PRINT_REQ, buff, len);
    SendProcessMsgBuff(&send, size);
}


/**
 * @description: 解析gcode路径和预览图
 * @return {*}
 * @param {uint16_t} dirent_info_part_t
 * preview_type: true为打印历史预览，false为文件管理页预览
 */
int preview_filling_chart(dirent_info_part_t *part, bool preview_type)
{
    bool is_local_disk = part->is_local_disk;

    chart_file_index = part->dirent_index;
    CrLogI("chart_file_index:%d", chart_file_index);

    if (is_preview_file_from_root_dir) //来自根目录的gcode文件
    {
        if (is_local_disk == true) {
            json_object *localFileObj = json_object_from_file(GetUserLocalGcodeFileInfoPtah());
            if(!localFileObj) {
                CrLogW("read json object fail\n");
                goto GET_LOCAL_INFO_ERR;
            }

            json_object *elem = json_object_array_get_idx(localFileObj, chart_file_index);//chart_file_index
            if (!elem) {
                CrLogW("read json object fail\n");
                goto GET_LOCAL_INFO_ERR;
            }

            char *preview = json_object_get_string(json_object_object_get(elem, "preview"));
            if (!preview) {
                CrLogW("get preview fail");
                goto GET_LOCAL_INFO_ERR;
            }
            
            if (!strstr(preview, part->dirent_name)) {
                CrLogW("preview chart is error");
                goto GET_LOCAL_INFO_ERR;
            }
            memset(preview_filling_chart_name, 0, sizeof(preview_filling_chart_name));
            strncpy(preview_filling_chart_name, preview, sizeof(preview_filling_chart_name) - 1);
            CrLogI("LocalGcode preview_filling_chart_name:%s\n", preview_filling_chart_name);
            char *path = json_object_get_string(json_object_object_get(elem, "path"));
            memset(print_gcode_path, 0, sizeof(print_gcode_path));
            strncpy(print_gcode_path, path, sizeof(print_gcode_path) - 1);
            //strcpy(print_gcode_path, path);
            CrLogI("LocalGcode print_gcode_path:%s\n", print_gcode_path);
                
            json_object_put(localFileObj);
            return 0;
            
        GET_LOCAL_INFO_ERR:
            if (localFileObj) json_object_put(localFileObj);           
        }
        else {
            json_object *udiskFileObj = json_object_from_file(GetUserUdiskGcodeFileInfoPtah());
            if(!udiskFileObj) {
                CrLogW("read json object fail\n");
                goto GET_UDISK_INFO_ERR;
            }
               
            json_object *elem = json_object_array_get_idx(udiskFileObj, chart_file_index);
            if (!elem) {
                CrLogW("read json object fail\n");
                goto GET_UDISK_INFO_ERR;
            }

            char *preview = json_object_get_string(json_object_object_get(elem, "preview"));
            if (!preview) {
                CrLogW("get preview fail");
                goto GET_UDISK_INFO_ERR;
            }  

            if (!strstr(preview, part->dirent_name)) {
                CrLogW("preview chart is error");
                goto GET_UDISK_INFO_ERR;
            }
                   
            memset(preview_filling_chart_name, 0, sizeof(preview_filling_chart_name));
            strncpy(preview_filling_chart_name, preview, sizeof(preview_filling_chart_name) - 1);
            CrLogI("LocalGcode preview_filling_chart_name:%s\n", preview_filling_chart_name);
    
            char *path = json_object_get_string(json_object_object_get(elem, "path"));
            memset(print_gcode_path, 0, sizeof(print_gcode_path));
            strncpy(print_gcode_path, path, sizeof(print_gcode_path) - 1);
            //strcpy(print_gcode_path, path);
            CrLogI("LocalGcode print_gcode_path:%s\n", print_gcode_path);

            json_object_put(udiskFileObj);
            return 0;
            
        GET_UDISK_INFO_ERR:
            if (udiskFileObj) json_object_put(udiskFileObj);              
        }
    }
    else //子目录下的gcode 文件//TODO: 文件夹下预览图暂未做异常处理
    {
        uint16_t subdir_part_index = part->subdir_part_index;

        if (!part->is_udisk) {//本地子目录
            json_object *localFileObj = json_object_from_file(GetUserLocalGcodeFileInfoPtah());
            if (!localFileObj) {
                CrLogW("read json object fail\n");
                goto GET_DIRLOCAL_INFO_ERR;
            }
            
            json_object *elem = json_object_array_get_idx(localFileObj, subdir_part_index);
            if (!elem) {
                CrLogW("read json object fail\n");
                goto GET_DIRLOCAL_INFO_ERR;
            }

            json_object *subelem = json_object_array_get_idx(json_object_object_get(elem, "file"), chart_file_index);
            if (!subelem) {
                CrLogW("read json object fail\n");
                goto GET_DIRLOCAL_INFO_ERR;
            }
            
            char *preview = json_object_get_string(json_object_object_get(subelem, "preview"));
            if (!preview) {
                CrLogW("get preview fail");
                goto GET_DIRLOCAL_INFO_ERR;
            }
                
            memset(preview_filling_chart_name, 0, sizeof(preview_filling_chart_name));
            strncpy(preview_filling_chart_name, preview, sizeof(preview_filling_chart_name) - 1);
            CrLogI("LocalGcode preview_filling_chart_name:%s\n", preview_filling_chart_name);
    
            char *path = json_object_get_string(json_object_object_get(subelem, "path"));
            memset(print_gcode_path, 0, sizeof(print_gcode_path));
            strncpy(print_gcode_path, path, sizeof(print_gcode_path) - 1);
            //strcpy(print_gcode_path, path);
            CrLogI("LocalGcode print_gcode_path:%s\n", print_gcode_path);  

            json_object_put(localFileObj);
            return 0;
            
        GET_DIRLOCAL_INFO_ERR:
            if (localFileObj) json_object_put(localFileObj);
        }
        else { //U盘子目录
            CrLogI("subdir_part_index:%d, chart_file_index %d\n", subdir_part_index, chart_file_index);

            json_object *udiskFileObj = json_object_from_file(GetUserUdiskGcodeFileInfoPtah());
            if (!udiskFileObj) {
                CrLogW("read json object fail\n");
                goto GET_DIRUDISK_INFO_ERR;
            }
            
            json_object *elem = json_object_array_get_idx(udiskFileObj, subdir_part_index);
            if (!elem) {
                CrLogW("read json object fail\n");
                goto GET_DIRUDISK_INFO_ERR;
            }
         
            json_object *subelem = json_object_array_get_idx(json_object_object_get(elem, "file"), chart_file_index);
            if (!subelem) {
                CrLogW("read json object fail\n");
                goto GET_DIRUDISK_INFO_ERR;
            }
            
            char *preview = json_object_get_string(json_object_object_get(subelem, "preview"));
            if (!preview) {
                CrLogW("get preview fail");
                goto GET_DIRUDISK_INFO_ERR;
            }
            memset(preview_filling_chart_name, 0, sizeof(preview_filling_chart_name));
            strncpy(preview_filling_chart_name, preview, sizeof(preview_filling_chart_name) - 1);
            CrLogI("LocalGcode preview_filling_chart_name:%s\n", preview_filling_chart_name);
    
            char *path = json_object_get_string(json_object_object_get(subelem, "path"));
            memset(print_gcode_path, 0, sizeof(print_gcode_path));
            strncpy(print_gcode_path, path, sizeof(print_gcode_path) - 1);
            //strcpy(print_gcode_path, path);
            CrLogI("LocalGcode print_gcode_path:%s\n", print_gcode_path); 

            json_object_put(udiskFileObj);
            return 0;
            
        GET_DIRUDISK_INFO_ERR:
            if (udiskFileObj) json_object_put(udiskFileObj); 
        }
    }
    return -1;
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
    lv_img_set_zoom(ui_ImageFillingChartScreenPreview, 200);//图片缩小

    // lv_obj_set_style_img_recolor(ui_ImageFillingChartScreenPreview, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_img_recolor_opa(ui_ImageFillingChartScreenPreview, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_add_flag(ui_ImageFillingChartScreenPreview, LV_OBJ_FLAG_HIDDEN);

    // lv_timer_t *reminder_display_timer = lv_timer_create(preview_timeout_callback, 10, NULL);
    // lv_timer_set_repeat_count(reminder_display_timer, 1);
}


void preview_set_history_file_info(int32_t history_record_index)
{
    dirent_info_part_t part = {0};

    CrLogI("get history record from file");

    // 判断历史记录是否存在，读取文件，获取json数据
    if (access(GetuserPrintHistoryRecordPtah(), F_OK) != 0) {
        CrLogW("no history record\n");
        return;
    }
    // 提取历史记录
    json_object *historyRecord = json_object_from_file(GetuserPrintHistoryRecordPtah());
    if (!historyRecord) {
        CrLogW("read json object fail\n");
        return;
    }
    // 提取历史记录列表
    json_object *listObj = json_object_object_get(historyRecord, "list");
    if (!listObj) {
        CrLogW("read list object fail\n");
        json_object_put(historyRecord);
        return;
    }
    // 获取指定历史记录
    json_object *record = json_object_array_get_idx(listObj, history_record_index - 1);
    if (!record) {
        CrLogW("read history object fail\n");
        json_object_put(historyRecord);
        return;
    }

    // 提取文件名
    json_object *fileName = json_object_object_get(record, "filename");
    if (!fileName) {
        CrLogW("read name object fail\n");
        json_object_put(historyRecord);
        return;
    }

    // 获取文件名
    char result[256] = {0};
    strcat(result, json_object_get_string(fileName));
    json_object_put(historyRecord);

    CrLogI("history_record_index = %d, filename: %s\n", history_record_index, result);

    //TODO:判断文件名是本地还是U盘的
    //printf("GetUserLocalGcodeFileInfoPtah(): %s\n", GetUserLocalGcodeFileInfoPtah());
    if(!strstr(result, "udisk"))
    {
        //从本地文件列表查询文件信息
        CrLogI("get historyfile from local file,%s",result);
        // 判断本地是否存在，读取文件，获取json数据
        part.is_local_disk = true;
        if (access(GetUserLocalGcodeFileInfoPtah(), F_OK) != 0) {
            CrLogW("no local record\n");
            return;
        }
        // 提取本地文件信息
        //printf("history: %s\n", GetUserLocalGcodeFileInfoPtah());
        json_object *localfile = json_object_from_file(GetUserLocalGcodeFileInfoPtah());
        if (!localfile) {
            CrLogW("read json object fail\n");
            return;
        }

        for (int i = 0; i < json_object_array_length(localfile); i++)
        {
            
            json_object *singlefile = json_object_array_get_idx(localfile, i);
            json_object *name = json_object_object_get(singlefile, "path");
            if(strcmp(json_object_get_string(name), result) == 0)   //找到目标json
            {
                name = json_object_object_get(singlefile, "name");
                const char *filename = json_object_get_string(name);
                strcat(part.dirent_name, filename);

                name = json_object_object_get(singlefile, "bedTemp");
                const char *bedTemp = json_object_get_string(name);
                part.bed_temp = atoi(bedTemp);

                name = json_object_object_get(singlefile, "nozzleTemp");
                const char *nozzleTemp = json_object_get_string(name);
                part.nozzle_temp = atoi(nozzleTemp);

                name = json_object_object_get(singlefile, "timeCost");
                const char *timeCost = json_object_get_string(name);
                part.totle_time = atoi(timeCost);

                name = json_object_object_get(singlefile, "consumables");
                const char *consumables = json_object_get_string(name);
                part.mater_used = atoi(consumables);

                name = json_object_object_get(singlefile, "material");
                const char *material1 = json_object_get_string(name);
                strcat(part.filament_type, material1);
                part.dirent_index = i;
            }
        }
    }
    else
    {
        
    }

    //TODO:这个接口太冗余了，后面优化
    preview_set_file_info(&part, true);
}

/**
 * @description: 
 * @return {*}
 * @param {dirent_info_part_t} *part
 * @param {bool} preview_type:true为打印历史预览，false为文件管理页预览 
 */
int preview_set_file_info(dirent_info_part_t *part, bool preview_type)
{
    static int ret = 0;
    if (!part)
        return;
#if 0
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
#endif   
    if (!part->dirent_name)
    {
        part->totle_time = 0;
        part->mater_used = 0;
        part->dirent_index = -1;
    }

    if ( ui_LabelUsageMaterScreenPreview )
    {
        char buff[10] = {0};
        uint8_t temp = part->mater_used % 100;  //计算分米的余数
        float fused = part->mater_used / 1000.0f;

        sprintf(buff, "%.1fm", fused + 0.05);

        lv_label_set_text(ui_LabelUsageMaterScreenPreview, buff);
        CrLogI("UsageMater: %s\n", buff);
    }

    if ( ui_LabelFileNameScreenPreview )
    {
        if ( !part->dirent_name) //文件名
        {
            lv_label_set_text(ui_LabelFileNameScreenPreview, "");
            strcpy(preview_file_name, "");
        }
        else
        {
            lv_label_set_text(ui_LabelFileNameScreenPreview, part->dirent_name);
            strncpy(preview_file_name, part->dirent_name, sizeof(preview_file_name));
        }
    }

    if ( ui_LabelTotleTimeScreenPreview_ )
    {
        int32_t time = part->totle_time;  // totel time unit is seconds
        char buff[10] = {0};
        sprintf(buff, "%dmin", time / 60);
        lv_label_set_text(ui_LabelTotleTimeScreenPreview_, buff);
         CrLogI("totle_time: %s\n", buff);
    }

    if( ui_LabelMaterType )
    {
        CrLogI("the filament type is %s.",part->filament_type);
        if(!part->filament_type)
        {
            lv_obj_clear_flag(ui_PanelMaterType,LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_LabelMaterType, part->filament_type);
        }
        else
        {
            lv_obj_add_flag(ui_PanelMaterType,LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_LabelMaterType, "");
        }
    }
        
    preview_set_model_printer_temper(part->nozzle_temp, part->bed_temp);   
    CrLogI("part->nozzle_temp :%d\n", part->nozzle_temp);
    CrLogI("part->bed_temp :%d\n", part->bed_temp);
    
    chart_file_index = part->dirent_index;
    CrLogI("==chart_file_index:%d\n", chart_file_index);
    
    // chart_file_index = file_index; //打印开始
    // print_from = type;
    
    if (strlen(part->dirent_name))
    {
        preview_filling_chart(part, preview_type);
        //预览图解析处理
        CrLogI("preview file name: %s, length:%d ", preview_filling_chart_name, strlen( preview_filling_chart_name ));
    }
    else
    {
        memset(preview_filling_chart_name, 0, sizeof(preview_filling_chart_name));
    }

    if (strlen(preview_filling_chart_name) > 0 && ui_ImageFillingChartScreenPreview)
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
    lv_img_set_zoom(ui_ImageFillingChartScreenPreview, 200);//图片缩小
    
    return ret;
}


void preview_set_model_printer_temper(uint16_t hotend_temper, uint16_t bed_temper)
{
    char buff[10] = {0};
    if ( ui_LabelBedTemperScreenPreview )
    {
        if(bed_temper > 0)   //代表解析到数据
        {
            sprintf(buff, "%d°C", bed_temper/100);
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
            sprintf(buff, "%d°C", hotend_temper/100);
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
        //preview_set_file_info(singlefile.filename, atoi(singlefile.timecost),atoi(singlefile.consumables), atoi(singlefile.index), singlefile.filamenttype, atoi(singlefile.nozzletemp)/100, atoi(singlefile.bedtemp)/100, FROM_HISTORY);
        preview_set_filling_chart_info(singlefile.preview, 0, 300, 0, 0);
        preview_set_mode_file_from_dir_type(true);
       // LoadPreviewScreen();
        LoadPage(ui_ScreenPreview, 2);
    }
}

static void PreviewPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    // lv_indev_set_group(enc_indev, NULL); 
    // lv_indev_set_group(enc_indev, encoder_group); //关联组
    

    lv_group_add_obj(encoder_group, ui_CheckboxAutoLevelScreenPreview);
    lv_group_add_obj(encoder_group, ui_ButtonBackFileListScreenPreview);
    lv_group_add_obj(encoder_group, ui_ButtonStartPrintScreenPreview);

}