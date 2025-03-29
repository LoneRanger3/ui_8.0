#include "ui_screen_PrintHistory.h"

#include "ui_screen_FileManage.h"
#include "ui_screen_Preview.h"
#include "ui_helpers.h"
#include <stdio.h>
#include <time.h>
#include "ui_custom_print_history_part.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_HomePrinting.h"
#include "ui_screen_Adjustment.h"
#include "ui_screen_AxisMove.h"
#include "ui_custom_reminderbox.h"
#include "../custom/lvgl_cmd.h"
#include "ui_Screen_Settings.h"
#include "mult_language.h"

static lv_obj_t * ui_ScreenPrintHistory;
/**********print history page left panel*******************/
static lv_obj_t * ui_PanelPageScreenHistory;
static lv_obj_t * ui_ButtonHomeScreenHistory;
static lv_obj_t * ui_ButtonAxisMoveScreenHistory;
static lv_obj_t * ui_ImageFileManageScreenHistory;
static lv_obj_t * ui_ButtonSettingsScreenHistory;
static lv_obj_t * ui_ButtonReserveScreenHistory;

/**********print history page right panel*******************/
static lv_obj_t * ui_PanelFileOptScreenHistory;
/**********print history page right panel title*******************/
static lv_obj_t * ui_ButtonLocalFileScreenHistory;
static lv_obj_t * ui_LabelLocalScreenHistory;
static lv_obj_t * ui_ButtonUsbFileScreenHistory;
static lv_obj_t * ui_LabelUDiskScreenHistory;
static lv_obj_t * ui_ButtonPrintHistoryFileScreenHist;
static lv_obj_t * ui_LabelPrintHistoryScreenHist;

/**********print history page right panel history record list title*******************/
static lv_obj_t * ui_PanelCenterScreenHistory;
static lv_obj_t * ui_PanelPrinteFileListScreenHistory;
static lv_obj_t * ui_PanelListHeadScreenHistory;
static lv_obj_t * ui_LabelFileNameScreenHistory;
static lv_obj_t * ui_LabelStartTimeScreenHistory;
static lv_obj_t * ui_LabelTotleTimeScreenHistory;
static lv_obj_t * ui_LabelStatusScreenHistory;
static lv_obj_t * ui_LabelOperateScreenHistory = NULL;
static print_history_part_t *print_record[3] = {NULL};
static lv_obj_t * ui_LabelNoContentsPromptScreenHisto;
static lv_obj_t * ui_PanelLineScreenHistory;

/**********print history page right panel history record change page *******************/
static lv_obj_t * ui_PanelPrevFilesPageScreenHistory;
static lv_obj_t * ui_ImageFilesPrevPageScreenHistory;
static lv_obj_t * ui_PanelNextFilesPageScreenHistory;
static lv_obj_t * ui_ImageFilesNextPageScreenHistory;

/**********print history page right panel history record action*******************/
static lv_obj_t * ui_PanelFileActionScreenHistory;
static lv_obj_t * ui_ButtonCopyFilesScreenHistory;
static lv_obj_t * ui_LabelCopyHistory;
static lv_obj_t * ui_ButtonDelFilesScreenHistory;
static lv_obj_t * ui_LabelDelHistory;

/***********************custom variable***********************/
#define PAGE_MAX_RECORDS 3

static int16_t record_start_index = 1;
static int16_t record_count = 0;

/*********************** print history event***********************/
static void ui_event_ButtonHomeScreenHistory(lv_event_t * e);
static void ui_event_ButtonAxisMoveScreenHistory(lv_event_t * e);
static void ui_event_ButtonSettingsScreenHistory(lv_event_t * e);
static void ui_event_ButtonReserveScreenHistory(lv_event_t * e);
static void ui_event_ButtonLocalFileScreenHistory(lv_event_t * e);
static void ui_event_ButtonUsbFileScreenHistory(lv_event_t * e);
static void ui_event_PanelPrevFilesPageScreenHistory(lv_event_t * e);
static void ui_event_PanelNextFilesPageScreenHistory(lv_event_t * e);
static void ui_event_ButtonCopyFilesScreenHistory(lv_event_t * e);
static void ui_event_ButtonDelFilesScreenHistory(lv_event_t * e);

/*********************** print history event call back***********************/
static void HistoryPageHomeBtnClicked(lv_event_t * e);
static void HistoryPageAxisBtnClicked(lv_event_t * e);
static void HistoryPageSettingsBtnClicked(lv_event_t * e);
static void HistoryPageReserveBtnClicked(lv_event_t * e);
static void HistoryPageLocalFileBtnClicked(lv_event_t * e);
static void HistoryPageUsbFileBtnClicked(lv_event_t * e);
static void HistoryPagePrevPageBtnClicked(lv_event_t * e);
static void HistoryPageNextPageBtnClicked(lv_event_t * e);
static void HistoryPageCopyFilesBtnClicked(lv_event_t * e);
static void HistoryPageDelFilesBtnClicked(lv_event_t * e);


/*************************custom funs*********************************/

/*  History  */
void ui_event_ButtonHomeScreenHistory(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HistoryPageHomeBtnClicked(e);
    }
}
void ui_event_ButtonAxisMoveScreenHistory(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HistoryPageAxisBtnClicked(e);
    }
}
void ui_event_ButtonSettingsScreenHistory(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HistoryPageSettingsBtnClicked(e);
    }
}
void ui_event_ButtonReserveScreenHistory(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HistoryPageReserveBtnClicked(e);
    }
}
void ui_event_ButtonLocalFileScreenHistory(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HistoryPageLocalFileBtnClicked(e);
    }
}
void ui_event_ButtonUsbFileScreenHistory(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HistoryPageUsbFileBtnClicked(e);
    }
}

void ui_event_PanelPrevFilesPageScreenHistory(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HistoryPagePrevPageBtnClicked(e);
    }
}
void ui_event_PanelNextFilesPageScreenHistory(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HistoryPageNextPageBtnClicked(e);
    }
}
void ui_event_ButtonCopyFilesScreenHistory(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HistoryPageCopyFilesBtnClicked(e);
    }
}
void ui_event_ButtonDelFilesScreenHistory(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HistoryPageDelFilesBtnClicked(e);
    }
}

void ui_ScreenPrintHistory_screen_init(void)
{
    ui_ScreenPrintHistory = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenPrintHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenPrintHistory, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenPrintHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    uint8_t language_index = get_cur_language_index();
    ui_PanelPageScreenHistory = lv_obj_create(ui_ScreenPrintHistory);
    lv_obj_set_width(ui_PanelPageScreenHistory, 68);
    lv_obj_set_height(ui_PanelPageScreenHistory, 360);
    lv_obj_clear_flag(ui_PanelPageScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPageScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPageScreenHistory, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui_PanelPageScreenHistory, 0, 60);

    ui_ButtonHomeScreenHistory = lv_btn_create(ui_PanelPageScreenHistory);
    lv_obj_set_width(ui_ButtonHomeScreenHistory, 68);
    lv_obj_set_height(ui_ButtonHomeScreenHistory, 72);
    lv_obj_set_x(ui_ButtonHomeScreenHistory, -18);
    lv_obj_set_y(ui_ButtonHomeScreenHistory, -18);
    lv_obj_add_flag(ui_ButtonHomeScreenHistory, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenHistory, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonHomeScreenHistory, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenHistory, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenHistory, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonHomeScreenHistory, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonAxisMoveScreenHistory = lv_btn_create(ui_PanelPageScreenHistory);
    lv_obj_set_width(ui_ButtonAxisMoveScreenHistory, 68);
    lv_obj_set_height(ui_ButtonAxisMoveScreenHistory, 72);
    lv_obj_set_x(ui_ButtonAxisMoveScreenHistory, -18);
    lv_obj_set_y(ui_ButtonAxisMoveScreenHistory, 54);
    lv_obj_add_flag(ui_ButtonAxisMoveScreenHistory, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveScreenHistory, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMoveScreenHistory, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveScreenHistory, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveScreenHistory, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonAxisMoveScreenHistory, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageFileManageScreenHistory = lv_img_create(ui_PanelPageScreenHistory);
    lv_img_set_src(ui_ImageFileManageScreenHistory, &ui_img_pagefilemanageselected_png);
    lv_obj_set_width(ui_ImageFileManageScreenHistory, 68);
    lv_obj_set_height(ui_ImageFileManageScreenHistory, 72);
    lv_obj_set_x(ui_ImageFileManageScreenHistory, -18);
    lv_obj_set_y(ui_ImageFileManageScreenHistory, 126);
    lv_obj_add_flag(ui_ImageFileManageScreenHistory, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFileManageScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonSettingsScreenHistory = lv_btn_create(ui_PanelPageScreenHistory);
    lv_obj_set_width(ui_ButtonSettingsScreenHistory, 68);
    lv_obj_set_height(ui_ButtonSettingsScreenHistory, 72);
    lv_obj_set_x(ui_ButtonSettingsScreenHistory, -18);
    lv_obj_set_y(ui_ButtonSettingsScreenHistory, 198);
    lv_obj_add_flag(ui_ButtonSettingsScreenHistory, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenHistory, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenHistory, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenHistory, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenHistory, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonSettingsScreenHistory, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonReserveScreenHistory = lv_btn_create(ui_PanelPageScreenHistory);
    lv_obj_set_width(ui_ButtonReserveScreenHistory, 68);
    lv_obj_set_height(ui_ButtonReserveScreenHistory, 72);
    lv_obj_set_x(ui_ButtonReserveScreenHistory, -18);
    lv_obj_set_y(ui_ButtonReserveScreenHistory, 270);
    lv_obj_add_flag(ui_ButtonReserveScreenHistory, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenHistory, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveScreenHistory, lv_color_hex(0x4190A5),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonReserveScreenHistory, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonReserveScreenHistory, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonReserveScreenHistory, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    
    //文件设置顶层面板
    ui_PanelFileOptScreenHistory = lv_obj_create(ui_ScreenPrintHistory);
    lv_obj_set_width(ui_PanelFileOptScreenHistory, 572);
    lv_obj_set_height(ui_PanelFileOptScreenHistory, 50);
    lv_obj_set_x(ui_PanelFileOptScreenHistory, 68);
    lv_obj_set_y(ui_PanelFileOptScreenHistory, 60);
    lv_obj_set_flex_flow(ui_PanelFileOptScreenHistory, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelFileOptScreenHistory, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelFileOptScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFileOptScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFileOptScreenHistory, lv_color_hex(0x101011), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFileOptScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFileOptScreenHistory, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //本地
    ui_ButtonLocalFileScreenHistory = lv_btn_create(ui_PanelFileOptScreenHistory);
    lv_obj_set_width(ui_ButtonLocalFileScreenHistory, 165);
    lv_obj_set_height(ui_ButtonLocalFileScreenHistory, 45);
    lv_obj_set_x(ui_ButtonLocalFileScreenHistory, 71);
    lv_obj_set_y(ui_ButtonLocalFileScreenHistory, 8);
    lv_obj_set_flex_flow(ui_ButtonLocalFileScreenHistory, LV_FLEX_FLOW_ROW);//M
    lv_obj_set_flex_align(ui_ButtonLocalFileScreenHistory, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonLocalFileScreenHistory, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonLocalFileScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonLocalFileScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonLocalFileScreenHistory, lv_color_hex(0x101011), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonLocalFileScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonLocalFileScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonLocalFileScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonLocalFileScreenHistory, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonLocalFileScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonLocalFileScreenHistory, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonLocalFileScreenHistory, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonLocalFileScreenHistory, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonLocalFileScreenHistory, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelLocalScreenHistory = lv_label_create(ui_ButtonLocalFileScreenHistory);
    lv_obj_set_width(ui_LabelLocalScreenHistory, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelLocalScreenHistory, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_LabelLocalScreenHistory, -18);
    // lv_obj_set_y(ui_LabelLocalScreenHistory, 0);
    lv_obj_set_align(ui_LabelLocalScreenHistory, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelLocalScreenHistory, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelLocalScreenHistory, Local[language_index]);
    lv_obj_set_style_text_align(ui_LabelLocalScreenHistory, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //U盘
    ui_ButtonUsbFileScreenHistory = lv_btn_create(ui_PanelFileOptScreenHistory);
    lv_obj_set_width(ui_ButtonUsbFileScreenHistory, 165);
    lv_obj_set_height(ui_ButtonUsbFileScreenHistory, 45);
    // lv_obj_set_x(ui_ButtonUsbFileScreenHistory, 162);
    // lv_obj_set_y(ui_ButtonUsbFileScreenHistory, -18);
    lv_obj_align_to(ui_ButtonUsbFileScreenHistory, ui_ButtonLocalFileScreenHistory, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_add_flag(ui_ButtonUsbFileScreenHistory, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonUsbFileScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonUsbFileScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonUsbFileScreenHistory, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonUsbFileScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonUsbFileScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonUsbFileScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonUsbFileScreenHistory, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonUsbFileScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonUsbFileScreenHistory, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonUsbFileScreenHistory, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonUsbFileScreenHistory, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonUsbFileScreenHistory, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    
    //打印历史
    ui_LabelUDiskScreenHistory = lv_label_create(ui_ButtonUsbFileScreenHistory);
    // lv_obj_set_width(ui_LabelUDiskScreenHistory, 155);
    // lv_obj_set_height(ui_LabelUDiskScreenHistory, 35);
     lv_obj_set_width(ui_LabelUDiskScreenHistory, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelUDiskScreenHistory, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_LabelUDiskScreenHistory, -18);
    // lv_obj_set_y(ui_LabelUDiskScreenHistory, 0);
    lv_obj_set_align(ui_LabelUDiskScreenHistory, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelUDiskScreenHistory, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelUDiskScreenHistory, DiskU[language_index]);
//    lv_obj_set_style_text_color(ui_LabelUDiskScreenHistory, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
//    lv_obj_set_style_text_opa(ui_LabelUDiskScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelUDiskScreenHistory, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonPrintHistoryFileScreenHist = lv_btn_create(ui_PanelFileOptScreenHistory);
    lv_obj_set_width(ui_ButtonPrintHistoryFileScreenHist, 165);
    lv_obj_set_height(ui_ButtonPrintHistoryFileScreenHist, 45);
    // lv_obj_set_x(ui_ButtonPrintHistoryFileScreenHist, 323);
    // lv_obj_set_y(ui_ButtonPrintHistoryFileScreenHist, -18);
    lv_obj_align_to(ui_ButtonPrintHistoryFileScreenHist, ui_ButtonUsbFileScreenHistory, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_add_flag(ui_ButtonPrintHistoryFileScreenHist, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPrintHistoryFileScreenHist, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonPrintHistoryFileScreenHist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonPrintHistoryFileScreenHist, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPrintHistoryFileScreenHist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
     lv_obj_set_style_shadow_width(ui_ButtonPrintHistoryFileScreenHist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonPrintHistoryFileScreenHist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonPrintHistoryFileScreenHist, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonPrintHistoryFileScreenHist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonPrintHistoryFileScreenHist, lv_font25.font,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_ButtonPrintHistoryFileScreenHist, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonPrintHistoryFileScreenHist, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonPrintHistoryFileScreenHist, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelPrintHistoryScreenHist = lv_label_create(ui_ButtonPrintHistoryFileScreenHist);
    lv_obj_set_width(ui_LabelPrintHistoryScreenHist, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelPrintHistoryScreenHist, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_LabelPrintHistoryScreenHist, -18);
    // lv_obj_set_y(ui_LabelPrintHistoryScreenHist, 0);
    lv_obj_set_align(ui_LabelPrintHistoryScreenHist, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelPrintHistoryScreenHist, LV_LABEL_LONG_SCROLL_CIRCULAR);
    char buff[30] = {0};
    sprintf(buff, "%s", History[language_index]);
    lv_label_set_text(ui_LabelPrintHistoryScreenHist, buff);
    //lv_obj_set_style_text_color(ui_LabelPrintHistoryScreenHist, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_opa(ui_LabelPrintHistoryScreenHist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelPrintHistoryScreenHist, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelCenterScreenHistory = lv_obj_create(ui_ScreenPrintHistory);
    lv_obj_set_width(ui_PanelCenterScreenHistory, 572); //720
    lv_obj_set_height(ui_PanelCenterScreenHistory, 210); //430
    lv_obj_set_x(ui_PanelCenterScreenHistory, 68);
    lv_obj_set_y(ui_PanelCenterScreenHistory, 110);
    lv_obj_clear_flag(ui_PanelCenterScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCenterScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCenterScreenHistory, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCenterScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCenterScreenHistory, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPrinteFileListScreenHistory = lv_obj_create(ui_PanelCenterScreenHistory);
    lv_obj_set_width(ui_PanelPrinteFileListScreenHistory, 548);//696
    lv_obj_set_height(ui_PanelPrinteFileListScreenHistory, 186);//406
    lv_obj_set_x(ui_PanelPrinteFileListScreenHistory, -12);
    lv_obj_set_y(ui_PanelPrinteFileListScreenHistory, -12);
    lv_obj_clear_flag(ui_PanelPrinteFileListScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelPrinteFileListScreenHistory, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrinteFileListScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPrinteFileListScreenHistory, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_PanelPrinteFileListScreenHistory, lv_color_hex(0x000000),
                                   LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_PanelPrinteFileListScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_PanelPrinteFileListScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_PanelPrinteFileListScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelListHeadScreenHistory = lv_obj_create(ui_PanelPrinteFileListScreenHistory);
    lv_obj_set_width(ui_PanelListHeadScreenHistory, 548); //696
    lv_obj_set_height(ui_PanelListHeadScreenHistory, 50);//
    lv_obj_set_x(ui_PanelListHeadScreenHistory, -18);//-22
    lv_obj_set_y(ui_PanelListHeadScreenHistory, -18);//-22
    lv_obj_clear_flag(ui_PanelListHeadScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelListHeadScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelListHeadScreenHistory, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelListHeadScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelListHeadScreenHistory, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFileNameScreenHistory = lv_label_create(ui_PanelListHeadScreenHistory);
    lv_obj_set_width(ui_LabelFileNameScreenHistory, 150);
    lv_obj_set_height(ui_LabelFileNameScreenHistory, 36);
    lv_obj_set_x(ui_LabelFileNameScreenHistory, 90);    //78
    lv_obj_set_y(ui_LabelFileNameScreenHistory, -10);
    lv_label_set_long_mode(ui_LabelFileNameScreenHistory, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelFileNameScreenHistory, FileNameArray[language_index]);
    lv_obj_set_style_text_color(ui_LabelFileNameScreenHistory, lv_color_hex(0x64707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFileNameScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelFileNameScreenHistory, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFileNameScreenHistory, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelStartTimeScreenHistory = lv_label_create(ui_PanelListHeadScreenHistory);
    lv_obj_set_width(ui_LabelStartTimeScreenHistory, 180);
    lv_obj_set_height(ui_LabelStartTimeScreenHistory, 36);
    lv_obj_set_x(ui_LabelStartTimeScreenHistory, 280);  //335
    lv_obj_set_y(ui_LabelStartTimeScreenHistory, -10);
    lv_label_set_long_mode(ui_LabelStartTimeScreenHistory, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelStartTimeScreenHistory, StartTimeArray[language_index]);
    lv_obj_set_style_text_color(ui_LabelStartTimeScreenHistory, lv_color_hex(0x64707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelStartTimeScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelStartTimeScreenHistory, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelStartTimeScreenHistory, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTotleTimeScreenHistory = lv_label_create(ui_PanelListHeadScreenHistory);
    lv_obj_set_width(ui_LabelTotleTimeScreenHistory, 140);
    lv_obj_set_height(ui_LabelTotleTimeScreenHistory, 36);
    lv_obj_set_x(ui_LabelTotleTimeScreenHistory, 438);   //464
    lv_obj_set_y(ui_LabelTotleTimeScreenHistory, -10);
    lv_label_set_long_mode(ui_LabelTotleTimeScreenHistory, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_LabelTotleTimeScreenHistory, TotleTimeArray[language_index]);
    lv_obj_set_style_text_color(ui_LabelTotleTimeScreenHistory, lv_color_hex(0x64707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTotleTimeScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTotleTimeScreenHistory, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTotleTimeScreenHistory, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelStatusScreenHistory = lv_label_create(ui_PanelListHeadScreenHistory);
    lv_obj_set_width(ui_LabelStatusScreenHistory, 80);
    lv_obj_set_height(ui_LabelStatusScreenHistory, 36);
    lv_obj_set_x(ui_LabelStatusScreenHistory, 585);   //589
    lv_obj_set_y(ui_LabelStatusScreenHistory, -10);
    lv_label_set_long_mode(ui_LabelStatusScreenHistory, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelStatusScreenHistory, StatusArray[language_index]);
    lv_obj_set_style_text_color(ui_LabelStatusScreenHistory, lv_color_hex(0x64707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelStatusScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelStatusScreenHistory, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelStatusScreenHistory, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelOperateScreenHistory = lv_label_create(ui_PanelListHeadScreenHistory);
    // lv_obj_set_width(ui_LabelOperateScreenHistory, 100);
    // lv_obj_set_height(ui_LabelOperateScreenHistory, 36);
    // lv_obj_set_x(ui_LabelOperateScreenHistory, 573);
    // lv_obj_set_y(ui_LabelOperateScreenHistory, -10);
    // lv_label_set_long_mode(ui_LabelOperateScreenHistory, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_LabelOperateScreenHistory, Action[language_index]);
    // lv_obj_set_style_text_color(ui_LabelOperateScreenHistory, lv_color_hex(0x64707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_LabelOperateScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_LabelOperateScreenHistory, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_LabelOperateScreenHistory, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelNoContentsPromptScreenHisto = lv_label_create(ui_PanelPrinteFileListScreenHistory);
    lv_obj_set_width(ui_LabelNoContentsPromptScreenHisto, 200);
    lv_obj_set_height(ui_LabelNoContentsPromptScreenHisto, 38);
    lv_obj_set_x(ui_LabelNoContentsPromptScreenHisto, 251);
    lv_obj_set_y(ui_LabelNoContentsPromptScreenHisto, 155);
    lv_label_set_text(ui_LabelNoContentsPromptScreenHisto, NoRecords[language_index]);
    lv_obj_add_flag(ui_LabelNoContentsPromptScreenHisto, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_LabelNoContentsPromptScreenHisto, lv_color_hex(0x6A707D),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelNoContentsPromptScreenHisto, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelNoContentsPromptScreenHisto, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelNoContentsPromptScreenHisto, lv_font25.font,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LabelNoContentsPromptScreenHisto, LV_LABEL_LONG_SCROLL_CIRCULAR);

    ui_PanelLineScreenHistory = lv_obj_create(ui_PanelPrinteFileListScreenHistory);
    lv_obj_set_width(ui_PanelLineScreenHistory, 679);
    lv_obj_set_height(ui_PanelLineScreenHistory, 1);
    lv_obj_set_x(ui_PanelLineScreenHistory, -12);
    lv_obj_set_y(ui_PanelLineScreenHistory, 33);
    lv_obj_clear_flag(ui_PanelLineScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelLineScreenHistory, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLineScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLineScreenHistory, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    int index = 0;
    print_record[index++] = create_custom_print_history_part(ui_PanelPrinteFileListScreenHistory, -22, 58);
    print_record[index++] = create_custom_print_history_part(ui_PanelPrinteFileListScreenHistory, -22, 164);
    print_record[index++] = create_custom_print_history_part(ui_PanelPrinteFileListScreenHistory, -22, 270);

    ui_PanelPrevFilesPageScreenHistory = lv_obj_create(ui_PanelCenterScreenHistory);
    lv_obj_set_width(ui_PanelPrevFilesPageScreenHistory, 70);
    lv_obj_set_height(ui_PanelPrevFilesPageScreenHistory, 70);
    lv_obj_set_x(ui_PanelPrevFilesPageScreenHistory, 623);
    lv_obj_set_y(ui_PanelPrevFilesPageScreenHistory, 252);
    lv_obj_clear_flag(ui_PanelPrevFilesPageScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPrevFilesPageScreenHistory, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPrevFilesPageScreenHistory, lv_color_hex(0x232527), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrevFilesPageScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPrevFilesPageScreenHistory, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelPrevFilesPageScreenHistory, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelPrevFilesPageScreenHistory, 255,
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelPrevFilesPageScreenHistory, 2,
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelPrevFilesPageScreenHistory, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_img_src(ui_PanelPrevFilesPageScreenHistory, &ui_img_newprev_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ImageFilesPrevPageScreenHistory = lv_img_create(ui_PanelPrevFilesPageScreenHistory);
    // lv_img_set_src(ui_ImageFilesPrevPageScreenHistory, &ui_img_newprev_png);
    // lv_obj_set_width(ui_ImageFilesPrevPageScreenHistory, 24);
    // lv_obj_set_height(ui_ImageFilesPrevPageScreenHistory, 14);
    // lv_obj_set_x(ui_ImageFilesPrevPageScreenHistory, 0);
    // lv_obj_set_y(ui_ImageFilesPrevPageScreenHistory, 5);
    // lv_obj_add_flag(ui_ImageFilesPrevPageScreenHistory, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageFilesPrevPageScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    

    ui_PanelNextFilesPageScreenHistory = lv_obj_create(ui_PanelCenterScreenHistory);
    lv_obj_set_width(ui_PanelNextFilesPageScreenHistory, 70);
    lv_obj_set_height(ui_PanelNextFilesPageScreenHistory, 70);
    lv_obj_set_x(ui_PanelNextFilesPageScreenHistory, 623);
    lv_obj_set_y(ui_PanelNextFilesPageScreenHistory, 334);
    lv_obj_clear_flag(ui_PanelNextFilesPageScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelNextFilesPageScreenHistory, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelNextFilesPageScreenHistory, lv_color_hex(0x232527), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelNextFilesPageScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelNextFilesPageScreenHistory, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelNextFilesPageScreenHistory, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelNextFilesPageScreenHistory, 255,
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelNextFilesPageScreenHistory, 2,
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelNextFilesPageScreenHistory, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_img_src(ui_PanelNextFilesPageScreenHistory, &ui_img_newnext_png, LV_PART_MAIN | LV_STATE_DEFAULT);    

    // ui_ImageFilesNextPageScreenHistory = lv_img_create(ui_PanelNextFilesPageScreenHistory);
    // lv_img_set_src(ui_ImageFilesNextPageScreenHistory, &ui_img_newnext_png);
    // lv_obj_set_width(ui_ImageFilesNextPageScreenHistory, 24);
    // lv_obj_set_height(ui_ImageFilesNextPageScreenHistory, 14);
    // lv_obj_set_x(ui_ImageFilesNextPageScreenHistory, 0);
    // lv_obj_set_y(ui_ImageFilesNextPageScreenHistory, 5);
    // lv_obj_add_flag(ui_ImageFilesNextPageScreenHistory, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageFilesNextPageScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PanelFileActionScreenHistory = lv_obj_create(ui_PanelCenterScreenHistory);
    lv_obj_set_width(ui_PanelFileActionScreenHistory, 130);
    lv_obj_set_height(ui_PanelFileActionScreenHistory, 140);
    lv_obj_set_x(ui_PanelFileActionScreenHistory, 560);
    lv_obj_set_y(ui_PanelFileActionScreenHistory, 43);
    lv_obj_add_flag(ui_PanelFileActionScreenHistory, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_PanelFileActionScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFileActionScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFileActionScreenHistory, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonCopyFilesScreenHistory = lv_btn_create(ui_PanelFileActionScreenHistory);
    lv_obj_set_width(ui_ButtonCopyFilesScreenHistory, 130);
    lv_obj_set_height(ui_ButtonCopyFilesScreenHistory, 70);
    lv_obj_set_x(ui_ButtonCopyFilesScreenHistory, -22);
    lv_obj_set_y(ui_ButtonCopyFilesScreenHistory, -22);
    lv_obj_add_flag(ui_ButtonCopyFilesScreenHistory, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonCopyFilesScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonCopyFilesScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonCopyFilesScreenHistory, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonCopyFilesScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonCopyFilesScreenHistory, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonCopyFilesScreenHistory, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonCopyFilesScreenHistory, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelCopyHistory = lv_label_create(ui_ButtonCopyFilesScreenHistory);
    lv_obj_set_width(ui_LabelCopyHistory, 124);
    lv_obj_set_height(ui_LabelCopyHistory, 30);
    lv_obj_set_x(ui_LabelCopyHistory, -18);
    lv_obj_set_y(ui_LabelCopyHistory, 10);
    lv_label_set_long_mode(ui_LabelCopyHistory, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelCopyHistory, Copy[language_index]);
    lv_obj_set_style_text_align(ui_LabelCopyHistory, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCopyHistory, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonDelFilesScreenHistory = lv_btn_create(ui_PanelFileActionScreenHistory);
    lv_obj_set_width(ui_ButtonDelFilesScreenHistory, 130);
    lv_obj_set_height(ui_ButtonDelFilesScreenHistory, 70);
    lv_obj_set_x(ui_ButtonDelFilesScreenHistory, -22);
    lv_obj_set_y(ui_ButtonDelFilesScreenHistory, 48);
    lv_obj_add_flag(ui_ButtonDelFilesScreenHistory, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonDelFilesScreenHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonDelFilesScreenHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonDelFilesScreenHistory, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonDelFilesScreenHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_ButtonDelFilesScreenHistory, lv_color_hex(0x4190A2), LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_ButtonDelFilesScreenHistory, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_ButtonDelFilesScreenHistory, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonDelFilesScreenHistory, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonDelFilesScreenHistory, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelDelHistory = lv_label_create(ui_ButtonDelFilesScreenHistory);
    lv_obj_set_width(ui_LabelDelHistory, 124);
    lv_obj_set_height(ui_LabelDelHistory, 30);
    lv_obj_set_x(ui_LabelDelHistory, -18);
    lv_obj_set_y(ui_LabelDelHistory, 10);
    lv_label_set_long_mode(ui_LabelDelHistory, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelDelHistory, Delete[language_index]);
    lv_obj_set_style_text_align(ui_LabelDelHistory, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelDelHistory, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ButtonHomeScreenHistory, ui_event_ButtonHomeScreenHistory, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMoveScreenHistory, ui_event_ButtonAxisMoveScreenHistory, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsScreenHistory, ui_event_ButtonSettingsScreenHistory, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserveScreenHistory, ui_event_ButtonReserveScreenHistory, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonLocalFileScreenHistory, ui_event_ButtonLocalFileScreenHistory, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonUsbFileScreenHistory, ui_event_ButtonUsbFileScreenHistory, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ButtonPrintHistoryFileScreenHist, ui_event_ButtonPrintHistoryFileScreenHist, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ButtonPrintAgain, ui_event_ButtonPrintAgain, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ButtonPrintAgain1, ui_event_ButtonPrintAgain1, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ButtonPrintAgain2, ui_event_ButtonPrintAgain2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelPrevFilesPageScreenHistory, ui_event_PanelPrevFilesPageScreenHistory, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelNextFilesPageScreenHistory, ui_event_PanelNextFilesPageScreenHistory, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonCopyFilesScreenHistory, ui_event_ButtonCopyFilesScreenHistory, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonDelFilesScreenHistory, ui_event_ButtonDelFilesScreenHistory, LV_EVENT_ALL, NULL);

    /*****************************/
    for ( int i = 0; i < 3; i++ )
        lv_obj_add_flag(print_record[i]->history_panel, LV_OBJ_FLAG_HIDDEN);

}

void LoadPrintHistoryScreen(void)
{
    lv_disp_load_scr(ui_ScreenPrintHistory);
    //if ( record_count == 0 )
    send_get_print_record_count_cmd();
}

void HistoryPageHomeBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( home_printing_is_printing_finished() )
        LoadHomeNormalScreen();
    else
        LoadHomePrintingScreen();
}

void HistoryPageAxisBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( home_printing_is_printing_finished() )
        LoadAxisMoveScreen();
    else
        LoadAxisMoveScreen();
}

void HistoryPageSettingsBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadSettingsScreen();
}

void HistoryPageReserveBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadCustomerServiceScreen();
}

void HistoryPageLocalFileBtnClicked(lv_event_t * e)
{
	// Your code here
   // file_manage_switch_screen(SCREEN_FILE);
    set_is_local_disk(true);
    LoadFileManageScreen();
    // file_manage_switch_disk(true);
}

void HistoryPageUsbFileBtnClicked(lv_event_t * e)
{
	// Your code here
//    file_manage_switch_screen(SCREEN_FILE);
    set_is_local_disk(false);
    LoadFileManageScreen();
    // file_manage_switch_disk(false);
}

void HistoryPagePrevPageBtnClicked(lv_event_t * e)
{
	// Your code here
    uint8_t index = get_cur_language_index();
    if ( record_count == 0 )
    {
        create_custom_reminderbox(NoRecords[index], false);
        set_custom_reminderbox_display_timeout(3, NULL);
        return ;
    }

    if ( record_start_index <= 1 )
    {
        create_custom_reminderbox(FirstPageMsg[index], false);
        set_custom_reminderbox_display_timeout(3, NULL);
    }
    else
    {
        record_start_index -= PAGE_MAX_RECORDS;
        if (record_start_index < 1)
            record_start_index = 1;

        send_get_records_cmd(record_start_index, PAGE_MAX_RECORDS);
    }
}

void HistoryPageNextPageBtnClicked(lv_event_t * e)
{
	// Your code here
    uint8_t index = get_cur_language_index();
    if ( record_count == 0 )
    {
        create_custom_reminderbox(NoRecords[index], false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return ;
    }

    if ( record_start_index + PAGE_MAX_RECORDS > record_count )
    {
        create_custom_reminderbox(LastPageMsg[index], false);
        set_custom_reminderbox_display_timeout(1, NULL);
    }
    else
    {
        record_start_index += PAGE_MAX_RECORDS;
        send_get_records_cmd(record_start_index , PAGE_MAX_RECORDS);
    }
}

void HistoryPageCopyFilesBtnClicked(lv_event_t * e)
{
	// Your code here
}

void HistoryPageDelFilesBtnClicked(lv_event_t * e)
{
	// Your code here
}

void history_set_print_record_info(print_record_info_t record_arry[3], int real_record_count)
{
    if ( !record_arry )
        return;
    
    uint8_t index = get_cur_language_index();
    if ( real_record_count == 0)
    {
        char buff[40] = {0};
        sprintf(buff, "%s %d %s", Page[index], (record_start_index / 3) + 1, NoRecords[index]);
        lv_label_set_text(ui_LabelNoContentsPromptScreenHisto, buff);
        lv_obj_clear_flag(ui_LabelNoContentsPromptScreenHisto, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_label_set_text(ui_LabelNoContentsPromptScreenHisto, "");
        lv_obj_add_flag(ui_LabelNoContentsPromptScreenHisto, LV_OBJ_FLAG_HIDDEN);
    }
        

    for ( int i = 0; i < 3; i++ )
    {
        if ( !print_record[i] || !(print_record[i]->history_panel) )
            continue;

        if ( i < real_record_count )
        {
            record_arry[i].recode_index = i + record_start_index;
            lv_obj_clear_flag(print_record[i]->history_panel, LV_OBJ_FLAG_HIDDEN);
            history_part_set_print_record_info(print_record[i], record_arry[i].recode_index, record_arry[i].thumbnail_name,
                                                record_arry[i].file_name, record_arry[i].start_time, 
                                                record_arry[i].print_used_time, record_arry[i].state_ok, record_arry[i].file_exsit);
        }
        else
        {
            lv_obj_add_flag(print_record[i]->history_panel, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void history_set_print_record_count(int count)
{
    if ( count == 0 )
    {
        record_count = 0;
        record_start_index = 1;
        for ( int i = 0; i < 3; i++ )
        {
            lv_obj_add_flag(print_record[i]->history_panel, LV_OBJ_FLAG_HIDDEN);
        }

        lv_label_set_text(ui_LabelNoContentsPromptScreenHisto, NoRecords[get_cur_language_index()]);
        lv_obj_clear_flag(ui_LabelNoContentsPromptScreenHisto, LV_OBJ_FLAG_HIDDEN);

        return 0;
    }

    send_get_records_cmd(1, PAGE_MAX_RECORDS);
    record_start_index = 1;
    record_count = count;
}

void history_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_LabelLocalScreenHistory )
        lv_label_set_text(ui_LabelLocalScreenHistory, Local[language_index]);
    
    if ( ui_LabelUDiskScreenHistory )
        lv_label_set_text(ui_LabelUDiskScreenHistory, DiskU[language_index]);

    if ( ui_LabelPrintHistoryScreenHist )
    {
        char buff[30] = {0};
        sprintf(buff, "%s", History[language_index]);
        lv_label_set_text(ui_LabelPrintHistoryScreenHist, buff);
    }

    if ( ui_LabelFileNameScreenHistory )
        lv_label_set_text(ui_LabelFileNameScreenHistory, FileNameArray[language_index]);
 
    if ( ui_LabelStartTimeScreenHistory )
        lv_label_set_text(ui_LabelStartTimeScreenHistory, StartTimeArray[language_index]);

    if ( ui_LabelTotleTimeScreenHistory )
        lv_label_set_text(ui_LabelTotleTimeScreenHistory, TotleTimeArray[language_index]);
    
    if ( ui_LabelStatusScreenHistory )
        lv_label_set_text(ui_LabelStatusScreenHistory, StatusArray[language_index]);
    
    if ( ui_LabelOperateScreenHistory )
        lv_label_set_text(ui_LabelOperateScreenHistory, Action[language_index]);

    if ( ui_LabelCopyHistory )
        lv_label_set_text(ui_LabelCopyHistory, Copy[language_index]);

    if ( ui_LabelDelHistory )
        lv_label_set_text(ui_LabelDelHistory, Delete[language_index]);

    for ( int8_t i = 0; i < 3; i++ )
        history_part_change_language_text(print_record[i]);
}