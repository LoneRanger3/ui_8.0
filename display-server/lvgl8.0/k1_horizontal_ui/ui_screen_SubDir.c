#include "ui_screen_SubDir.h"
#include "ui_screen_FileManage.h"
#include "ui_screen_Preview.h"
#include "ui_helpers.h"
#include <stdio.h>
#include <time.h>
#include "ui_custom_dirent_info_part.h"
#include "ui_custom_reminderbox.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_HomePrinting.h"
#include "ui_screen_Adjustment.h"
#include "ui_screen_AxisMove.h"
#include "../custom/lvgl_cmd.h"
#include "ui_Screen_Settings.h"
#include "mult_language.h"


static lv_obj_t * ui_ScreenSubDir;
/*--------------left panel---------------*/
static lv_obj_t * ui_PanelPageScreenSubDir;
static lv_obj_t * ui_ButtonHomeScreenSubDir;
static lv_obj_t * ui_ButtonAxisMoveScreenSubDir;
static lv_obj_t * ui_ImageFileManageScreenSubDir;
static lv_obj_t * ui_ButtonSettingsScreenSubDir;
static lv_obj_t * ui_ButtonReserveScreenSubDir;

/*--------------right panel---------------*/
static lv_obj_t * ui_PanelCenterScreenSubD;
static lv_obj_t * ui_PanelFileListScreenSubD;

/*--------------right panel title---------------*/
static lv_obj_t * ui_ButtonRootDirScreenSubDir;
static lv_obj_t * ui_LabelRootDirScreenSubDir;
static lv_obj_t * ui_ButtonParentDirScreenSubDir;
static lv_obj_t * ui_LabelParentDirScreenSubDir;
static lv_obj_t * ui_PanelSeparateLine;

static dirent_info_part_t *sub_dir_dirent_part_array[8] = {NULL};
static lv_obj_t * ui_LabelNoContentsPromptScreenSubD;

/*--------------right panel file action---------------*/
static lv_obj_t * ui_PanelFileActionScreenSubD;
static lv_obj_t * ui_ButtonCopyFilesScreenSubD;
static lv_obj_t * ui_LabelCopyUsbFiles;
static lv_obj_t * ui_ButtonDelFilesScreenSubD;
static lv_obj_t * ui_LabelDelUsbFiles;

/*--------------right panel file change page---------------*/
static lv_obj_t * ui_PanelPrevFilesPageScreenSubD;
static lv_obj_t * ui_ImageFilesPrevPageScreenSubD;
static lv_obj_t * ui_PanelNextFilesPageScreenSubD;
static lv_obj_t * ui_ImageFilesNextPageScreenSubD;

/************************custom variable**********************************/
#define ROOT_DIR_NAME "/"

static bool sub_dir_show_checkbox_file = false;
static bool is_parent_disk_type_is_local = true;   //
static uint16_t cur_dir_file_count = 0;
static uint16_t cur_page_start_index = 0;
//static char cur_dir_name[256] = {0};

/*-------------- screen event, can not modify---------------*/
static void ui_event_ButtonHomeScreenSubDir(lv_event_t * e);
static void ui_event_ButtonAxisMoveScreenSubDir(lv_event_t * e);
static void ui_event_ButtonSettingsScreenSubDir(lv_event_t * e);
static void ui_event_ButtonReserveScreenSubDir(lv_event_t * e);
static void ui_event_ButtonRootDirScreenSubDir(lv_event_t * e);
static void ui_event_ButtonParentDirScreenSubDir(lv_event_t * e);
static void ui_event_PanelFileInfoScreenSubD(lv_event_t * e);
// static void ui_event_CheckboxFile1ScreenSubD(lv_event_t * e);
//static void ui_event_PanelFileInfo2ScreenSubD(lv_event_t * e);
static void ui_event_ButtonCopyFilesScreenSubD(lv_event_t * e);
static void ui_event_ButtonDelFilesScreenSubD(lv_event_t * e);
static void ui_event_PanelPrevFilesPageScreenSubD(lv_event_t * e);
//static void ui_event_ImageFilesPrevPageScreenSubD(lv_event_t * e);
static void ui_event_PanelNextFilesPageScreenSubD(lv_event_t * e);
//static void ui_event_ImageFilesNextPageScreenSubD(lv_event_t * e);

/*--------------screen event call back---------------*/
/* SubDir */
static void SubDirPageHomeBtnClicked(lv_event_t * e);
static void SubDirPageAxisBtnClicked(lv_event_t * e);
static void SubDirPageSettingsBtnClicked(lv_event_t * e);
static void SubDirPageReserveBtnClicked(lv_event_t * e);
static void SubDPageRootDirBtnClicked(lv_event_t * e);
static void SubDPageParentDirBtnClicked(lv_event_t * e);
static void FilePageFileInfoPanelClicked(lv_event_t * e);
static void SubDPageFileInfoPanelLongPressed(lv_event_t * e);
static void SubDPageFileInfoPanelClicked(lv_event_t * e);
//static void SubDPageFileInfoChecked(lv_event_t * e);
//static void SubDPageDirInfoPanelClicked(lv_event_t * e);
static void SubDPageCopyFilesBtnClicked(lv_event_t * e);
static void SubDPageDelFilesBtnClicked(lv_event_t * e);
static void SubDPagePrevFilesPageBtnClicked(lv_event_t * e);
//static void FilePagePrevPageBtnClicked(lv_event_t * e);
static void SubDPageNextFilesPageBtnClicked(lv_event_t * e);
//static void FilePagePrevPageBtnClicked(lv_event_t * e);


/******************custom funs***************************/
static void enter_sub_dir_handle(void);
static void sub_dir_show_checkboxes(bool show);
static void sub_dir_show_file_action(bool show, bool is_local_disk);


/*  SubDir  */
void ui_event_ButtonHomeScreenSubDir(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SubDirPageHomeBtnClicked(e);
    }
}
void ui_event_ButtonAxisMoveScreenSubDir(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SubDirPageAxisBtnClicked(e);
    }
}
void ui_event_ButtonSettingsScreenSubDir(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SubDirPageSettingsBtnClicked(e);
    }
}
void ui_event_ButtonReserveScreenSubDir(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SubDirPageReserveBtnClicked(e);
    }
}
void ui_event_ButtonRootDirScreenSubDir(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SubDPageRootDirBtnClicked(e);
    }
}
void ui_event_ButtonParentDirScreenSubDir(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SubDPageParentDirBtnClicked(e);
    }
}
void ui_event_PanelFileInfoScreenSubD(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    //if(event_code == LV_EVENT_CLICKED) {
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        SubDPageFileInfoPanelClicked(e);
    }
    if(event_code == LV_EVENT_LONG_PRESSED) {
        SubDPageFileInfoPanelLongPressed(e);
    }
}

// void ui_event_CheckboxFile1ScreenSubD(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
//         SubDPageFileInfoChecked(e);
//     }
// }
// void ui_event_PanelFileInfo2ScreenSubD(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         SubDPageDirInfoPanelClicked(e);
//     }
// }
void ui_event_ButtonCopyFilesScreenSubD(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SubDPageCopyFilesBtnClicked(e);
    }
}
void ui_event_ButtonDelFilesScreenSubD(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SubDPageDelFilesBtnClicked(e);
    }
}
void ui_event_PanelPrevFilesPageScreenSubD(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SubDPagePrevFilesPageBtnClicked(e);
    }
}

// void ui_event_ImageFilesPrevPageScreenSubD(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilePagePrevPageBtnClicked(e);
//     }
// }

void ui_event_PanelNextFilesPageScreenSubD(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SubDPageNextFilesPageBtnClicked(e);
    }
}

void ui_event_SubDirPage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(sub_dir_show_checkbox_file)
        {
            sub_dir_show_file_action(false, false);
            sub_dir_show_checkboxes(false);
            sub_dir_show_checkbox_file = false;
        }
    }
}

// void ui_event_ImageFilesNextPageScreenSubD(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilePagePrevPageBtnClicked(e);
//     }
// }

void ui_ScreenSubDir_screen_init(void)
{
    ui_ScreenSubDir = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    int language_index = get_cur_language_index();

    ui_PanelPageScreenSubDir = lv_obj_create(ui_ScreenSubDir);
    lv_obj_set_width(ui_PanelPageScreenSubDir, 80);
    lv_obj_set_height(ui_PanelPageScreenSubDir, 480);
    lv_obj_clear_flag(ui_PanelPageScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPageScreenSubDir, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPageScreenSubDir, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonHomeScreenSubDir = lv_btn_create(ui_PanelPageScreenSubDir);
    lv_obj_set_width(ui_ButtonHomeScreenSubDir, 80);
    lv_obj_set_height(ui_ButtonHomeScreenSubDir, 96);
    lv_obj_set_x(ui_ButtonHomeScreenSubDir, -22);
    lv_obj_set_y(ui_ButtonHomeScreenSubDir, -22);
    lv_obj_add_flag(ui_ButtonHomeScreenSubDir, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenSubDir, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonHomeScreenSubDir, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenSubDir, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenSubDir, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonAxisMoveScreenSubDir = lv_btn_create(ui_PanelPageScreenSubDir);
    lv_obj_set_width(ui_ButtonAxisMoveScreenSubDir, 80);
    lv_obj_set_height(ui_ButtonAxisMoveScreenSubDir, 96);
    lv_obj_set_x(ui_ButtonAxisMoveScreenSubDir, -22);
    lv_obj_set_y(ui_ButtonAxisMoveScreenSubDir, 74);
    lv_obj_add_flag(ui_ButtonAxisMoveScreenSubDir, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveScreenSubDir, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMoveScreenSubDir, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveScreenSubDir, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveScreenSubDir, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageFileManageScreenSubDir = lv_img_create(ui_PanelPageScreenSubDir);
    lv_img_set_src(ui_ImageFileManageScreenSubDir, &ui_img_pagefilemanageselected_png);
    lv_obj_set_width(ui_ImageFileManageScreenSubDir, 80);
    lv_obj_set_height(ui_ImageFileManageScreenSubDir, 96);
    lv_obj_set_x(ui_ImageFileManageScreenSubDir, -22);
    lv_obj_set_y(ui_ImageFileManageScreenSubDir, 170);
    lv_obj_add_flag(ui_ImageFileManageScreenSubDir, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFileManageScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonSettingsScreenSubDir = lv_btn_create(ui_PanelPageScreenSubDir);
    lv_obj_set_width(ui_ButtonSettingsScreenSubDir, 80);
    lv_obj_set_height(ui_ButtonSettingsScreenSubDir, 96);
    lv_obj_set_x(ui_ButtonSettingsScreenSubDir, -22);
    lv_obj_set_y(ui_ButtonSettingsScreenSubDir, 266);
    lv_obj_add_flag(ui_ButtonSettingsScreenSubDir, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenSubDir, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenSubDir, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenSubDir, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenSubDir, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonReserveScreenSubDir = lv_btn_create(ui_PanelPageScreenSubDir);
    lv_obj_set_width(ui_ButtonReserveScreenSubDir, 80);
    lv_obj_set_height(ui_ButtonReserveScreenSubDir, 96);
    lv_obj_set_x(ui_ButtonReserveScreenSubDir, -22);
    lv_obj_set_y(ui_ButtonReserveScreenSubDir, 362);
    lv_obj_add_flag(ui_ButtonReserveScreenSubDir, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenSubDir, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveScreenSubDir, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonReserveScreenSubDir, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonReserveScreenSubDir, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_PanelCenterScreenSubD = lv_obj_create(ui_ScreenSubDir);
    lv_obj_set_width(ui_PanelCenterScreenSubD, 720);
    lv_obj_set_height(ui_PanelCenterScreenSubD, 480);
    lv_obj_set_x(ui_PanelCenterScreenSubD, 80);
    lv_obj_set_y(ui_PanelCenterScreenSubD, 0);
    lv_obj_clear_flag(ui_PanelCenterScreenSubD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCenterScreenSubD, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCenterScreenSubD, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCenterScreenSubD, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCenterScreenSubD, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelCenterScreenSubD, LV_OBJ_FLAG_EVENT_BUBBLE);

    ui_PanelFileListScreenSubD = lv_obj_create(ui_PanelCenterScreenSubD);
    lv_obj_set_width(ui_PanelFileListScreenSubD, 696);
    lv_obj_set_height(ui_PanelFileListScreenSubD, 480);
    lv_obj_set_x(ui_PanelFileListScreenSubD, -11);
    lv_obj_set_y(ui_PanelFileListScreenSubD, -22);
    lv_obj_clear_flag(ui_PanelFileListScreenSubD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelFileListScreenSubD, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFileListScreenSubD, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFileListScreenSubD, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelFileListScreenSubD, LV_OBJ_FLAG_EVENT_BUBBLE);

    ui_ButtonRootDirScreenSubDir = lv_btn_create(ui_PanelFileListScreenSubD);
    lv_obj_set_width(ui_ButtonRootDirScreenSubDir, 80);
    lv_obj_set_height(ui_ButtonRootDirScreenSubDir, 50);
    lv_obj_set_x(ui_ButtonRootDirScreenSubDir, -8);
    lv_obj_set_y(ui_ButtonRootDirScreenSubDir, -9);
    lv_obj_add_flag(ui_ButtonRootDirScreenSubDir, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonRootDirScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonRootDirScreenSubDir, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonRootDirScreenSubDir, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonRootDirScreenSubDir, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonRootDirScreenSubDir, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonRootDirScreenSubDir, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonRootDirScreenSubDir, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonRootDirScreenSubDir, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonRootDirScreenSubDir, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelRootDirScreenSubDir = lv_label_create(ui_ButtonRootDirScreenSubDir);
    lv_obj_set_width(ui_LabelRootDirScreenSubDir, 80);
    lv_obj_set_height(ui_LabelRootDirScreenSubDir, 35);
    // lv_obj_set_x(ui_LabelRootDirScreenSubDir, -18);
    // lv_obj_set_y(ui_LabelRootDirScreenSubDir, 0);
    lv_obj_set_align(ui_LabelRootDirScreenSubDir, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelRootDirScreenSubDir, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelRootDirScreenSubDir, DiskU[language_index]);
    lv_obj_set_style_text_align(ui_LabelRootDirScreenSubDir, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonRootDirScreenSubDir, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonRootDirScreenSubDir, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonRootDirScreenSubDir, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonParentDirScreenSubDir = lv_btn_create(ui_PanelFileListScreenSubD);
    lv_obj_set_width(ui_ButtonParentDirScreenSubDir, 600);
    lv_obj_set_height(ui_ButtonParentDirScreenSubDir, 50);
    lv_obj_set_x(ui_ButtonParentDirScreenSubDir, 72);
    lv_obj_set_y(ui_ButtonParentDirScreenSubDir, -9);
    lv_obj_add_flag(ui_ButtonParentDirScreenSubDir, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonParentDirScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonParentDirScreenSubDir, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonParentDirScreenSubDir, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonParentDirScreenSubDir, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonParentDirScreenSubDir, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonParentDirScreenSubDir, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonParentDirScreenSubDir, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ButtonParentDirScreenSubDir, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonParentDirScreenSubDir, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonParentDirScreenSubDir, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonParentDirScreenSubDir, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonParentDirScreenSubDir, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonParentDirScreenSubDir, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelParentDirScreenSubDir = lv_label_create(ui_ButtonParentDirScreenSubDir);
    lv_obj_set_width(ui_LabelParentDirScreenSubDir, 594);
    lv_obj_set_height(ui_LabelParentDirScreenSubDir, 35);
    // lv_obj_set_x(ui_LabelParentDirScreenSubDir, -18);
    // lv_obj_set_y(ui_LabelParentDirScreenSubDir, 0);
    lv_obj_set_align(ui_LabelParentDirScreenSubDir, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelParentDirScreenSubDir, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelParentDirScreenSubDir, "");
    lv_obj_set_style_text_align(ui_LabelParentDirScreenSubDir, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelParentDirScreenSubDir, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelParentDirScreenSubDir, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelParentDirScreenSubDir, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_PanelSeparateLine = lv_obj_create(ui_PanelFileListScreenSubD);
    lv_obj_set_width(ui_PanelSeparateLine, 720);
    lv_obj_set_height(ui_PanelSeparateLine, 1);
    lv_obj_set_x(ui_PanelSeparateLine, -8);
    lv_obj_set_y(ui_PanelSeparateLine, 50);
    lv_obj_clear_flag(ui_PanelSeparateLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelSeparateLine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelSeparateLine, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelSeparateLine, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelSeparateLine, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    int8_t index = 0;
    sub_dir_dirent_part_array[index++] = create_custom_dirent_info_part(ui_PanelFileListScreenSubD, -8, 62, &ui_event_PanelFileInfoScreenSubD);
    sub_dir_dirent_part_array[index++] = create_custom_dirent_info_part(ui_PanelFileListScreenSubD, 162, 62, &ui_event_PanelFileInfoScreenSubD);
    sub_dir_dirent_part_array[index++] = create_custom_dirent_info_part(ui_PanelFileListScreenSubD, 332, 62, &ui_event_PanelFileInfoScreenSubD);
    sub_dir_dirent_part_array[index++] = create_custom_dirent_info_part(ui_PanelFileListScreenSubD, 503, 62, &ui_event_PanelFileInfoScreenSubD);
    sub_dir_dirent_part_array[index++] = create_custom_dirent_info_part(ui_PanelFileListScreenSubD, -8, 261, &ui_event_PanelFileInfoScreenSubD);
    sub_dir_dirent_part_array[index++] = create_custom_dirent_info_part(ui_PanelFileListScreenSubD, 162, 261, &ui_event_PanelFileInfoScreenSubD);
    sub_dir_dirent_part_array[index++] = create_custom_dirent_info_part(ui_PanelFileListScreenSubD, 332, 261, &ui_event_PanelFileInfoScreenSubD);
    sub_dir_dirent_part_array[index++] = create_custom_dirent_info_part(ui_PanelFileListScreenSubD, 503, 261, &ui_event_PanelFileInfoScreenSubD);


    ui_LabelNoContentsPromptScreenSubD = lv_label_create(ui_PanelFileListScreenSubD);
    lv_obj_set_width(ui_LabelNoContentsPromptScreenSubD, 160);
    lv_obj_set_height(ui_LabelNoContentsPromptScreenSubD, 36);
    lv_obj_set_x(ui_LabelNoContentsPromptScreenSubD, 251);
    lv_obj_set_y(ui_LabelNoContentsPromptScreenSubD, 155);
    lv_label_set_text(ui_LabelNoContentsPromptScreenSubD, NoContentsMsg[language_index]);
    lv_obj_add_flag(ui_LabelNoContentsPromptScreenSubD, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_LabelNoContentsPromptScreenSubD, lv_color_hex(0x6A707D),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelNoContentsPromptScreenSubD, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelNoContentsPromptScreenSubD, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelNoContentsPromptScreenSubD, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LabelNoContentsPromptScreenSubD, LV_LABEL_LONG_SCROLL_CIRCULAR);

    ui_PanelFileActionScreenSubD = lv_obj_create(ui_PanelCenterScreenSubD);
    lv_obj_set_width(ui_PanelFileActionScreenSubD, 130);
    lv_obj_set_height(ui_PanelFileActionScreenSubD, 140);
    lv_obj_align(ui_PanelFileActionScreenSubD, LV_ALIGN_TOP_RIGHT, -15, 60);
    lv_obj_add_flag(ui_PanelFileActionScreenSubD, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_PanelFileActionScreenSubD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFileActionScreenSubD, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFileActionScreenSubD, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFileActionScreenSubD, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFileActionScreenSubD, 240, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonCopyFilesScreenSubD = lv_btn_create(ui_PanelFileActionScreenSubD);
    lv_obj_set_width(ui_ButtonCopyFilesScreenSubD, 130);
    lv_obj_set_height(ui_ButtonCopyFilesScreenSubD, 70);
    lv_obj_set_x(ui_ButtonCopyFilesScreenSubD, -22);
    lv_obj_set_y(ui_ButtonCopyFilesScreenSubD, -22);
    lv_obj_add_flag(ui_ButtonCopyFilesScreenSubD, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonCopyFilesScreenSubD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonCopyFilesScreenSubD, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonCopyFilesScreenSubD, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonCopyFilesScreenSubD, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonCopyFilesScreenSubD, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonCopyFilesScreenSubD, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonCopyFilesScreenSubD, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_ButtonCopyFilesScreenSubD, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCopyUsbFiles = lv_label_create(ui_ButtonCopyFilesScreenSubD);
    lv_obj_set_width(ui_LabelCopyUsbFiles, 124);
    lv_obj_set_height(ui_LabelCopyUsbFiles, 30);
    lv_obj_align(ui_LabelCopyUsbFiles, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_long_mode(ui_LabelCopyUsbFiles, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // char buff[30] = {0};
    // sprintf(buff, "%s%s", CopyTo[language_index], Local[language_index]);
    lv_label_set_text(ui_LabelCopyUsbFiles, CopyToLocal[language_index]);
    lv_obj_set_style_text_color(ui_LabelCopyUsbFiles, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCopyUsbFiles, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelCopyUsbFiles, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCopyUsbFiles, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonDelFilesScreenSubD = lv_btn_create(ui_PanelFileActionScreenSubD);
    lv_obj_set_width(ui_ButtonDelFilesScreenSubD, 130);
    lv_obj_set_height(ui_ButtonDelFilesScreenSubD, 70);
    lv_obj_set_x(ui_ButtonDelFilesScreenSubD, -22);
    lv_obj_set_y(ui_ButtonDelFilesScreenSubD, 48);
    lv_obj_add_flag(ui_ButtonDelFilesScreenSubD, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonDelFilesScreenSubD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonDelFilesScreenSubD, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonDelFilesScreenSubD, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonDelFilesScreenSubD, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonDelFilesScreenSubD, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonDelFilesScreenSubD, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonDelFilesScreenSubD, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_ButtonDelFilesScreenSubD, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelDelUsbFiles = lv_label_create(ui_ButtonDelFilesScreenSubD);
    lv_obj_set_width(ui_LabelDelUsbFiles, 124);
    lv_obj_set_height(ui_LabelDelUsbFiles, 30);
    lv_obj_align(ui_LabelDelUsbFiles, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_long_mode(ui_LabelDelUsbFiles, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelDelUsbFiles, Delete[language_index]);
    lv_obj_set_style_text_color(ui_LabelDelUsbFiles, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelDelUsbFiles, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelDelUsbFiles, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelDelUsbFiles, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPrevFilesPageScreenSubD = lv_obj_create(ui_PanelCenterScreenSubD);
    lv_obj_set_width(ui_PanelPrevFilesPageScreenSubD, 70);
    lv_obj_set_height(ui_PanelPrevFilesPageScreenSubD, 70);
    lv_obj_set_x(ui_PanelPrevFilesPageScreenSubD, 623);
    lv_obj_set_y(ui_PanelPrevFilesPageScreenSubD, 302);
    lv_obj_clear_flag(ui_PanelPrevFilesPageScreenSubD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPrevFilesPageScreenSubD, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPrevFilesPageScreenSubD, lv_color_hex(0x232527), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrevFilesPageScreenSubD, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPrevFilesPageScreenSubD, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_PanelPrevFilesPageScreenSubD, lv_color_hex(0x4190A2), LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_PanelPrevFilesPageScreenSubD, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_PanelPrevFilesPageScreenSubD, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelPrevFilesPageScreenSubD, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelPrevFilesPageScreenSubD, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelPrevFilesPageScreenSubD, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelPrevFilesPageScreenSubD, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_img_src(ui_PanelPrevFilesPageScreenSubD, &ui_img_newprev_png, LV_PART_MAIN | LV_STATE_DEFAULT);   
    lv_obj_add_flag(ui_PanelPrevFilesPageScreenSubD, LV_OBJ_FLAG_EVENT_BUBBLE);

    // ui_ImageFilesPrevPageScreenSubD = lv_img_create(ui_PanelPrevFilesPageScreenSubD);
    // lv_img_set_src(ui_ImageFilesPrevPageScreenSubD, &ui_img_newprev_png);
    // lv_obj_set_width(ui_ImageFilesPrevPageScreenSubD, 24);
    // lv_obj_set_height(ui_ImageFilesPrevPageScreenSubD, 14);
    // lv_obj_set_x(ui_ImageFilesPrevPageScreenSubD, 0);
    // lv_obj_set_y(ui_ImageFilesPrevPageScreenSubD, 5);
    // lv_obj_add_flag(ui_ImageFilesPrevPageScreenSubD, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageFilesPrevPageScreenSubD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PanelNextFilesPageScreenSubD = lv_obj_create(ui_PanelCenterScreenSubD);
    lv_obj_set_width(ui_PanelNextFilesPageScreenSubD, 70);
    lv_obj_set_height(ui_PanelNextFilesPageScreenSubD, 70);
    lv_obj_set_x(ui_PanelNextFilesPageScreenSubD, 623);
    lv_obj_set_y(ui_PanelNextFilesPageScreenSubD, 384);
    lv_obj_clear_flag(ui_PanelNextFilesPageScreenSubD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelNextFilesPageScreenSubD, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelNextFilesPageScreenSubD, lv_color_hex(0x232527), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelNextFilesPageScreenSubD, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelNextFilesPageScreenSubD, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_PanelNextFilesPageScreenSubD, lv_color_hex(0x4190A2), LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_PanelNextFilesPageScreenSubD, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_PanelNextFilesPageScreenSubD, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelNextFilesPageScreenSubD, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelNextFilesPageScreenSubD, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelNextFilesPageScreenSubD, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelNextFilesPageScreenSubD, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelNextFilesPageScreenSubD, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_img_src(ui_PanelNextFilesPageScreenSubD, &ui_img_newnext_png, LV_PART_MAIN | LV_STATE_DEFAULT);   
    lv_obj_add_flag(ui_PanelNextFilesPageScreenSubD, LV_OBJ_FLAG_EVENT_BUBBLE);

    // ui_ImageFilesNextPageScreenSubD = lv_img_create(ui_PanelNextFilesPageScreenSubD);
    // lv_img_set_src(ui_ImageFilesNextPageScreenSubD, &ui_img_newnext_png);
    // lv_obj_set_width(ui_ImageFilesNextPageScreenSubD, 24);
    // lv_obj_set_height(ui_ImageFilesNextPageScreenSubD, 14);
    // lv_obj_set_x(ui_ImageFilesNextPageScreenSubD, 0);
    // lv_obj_set_y(ui_ImageFilesNextPageScreenSubD, 5);
    // lv_obj_add_flag(ui_ImageFilesNextPageScreenSubD, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageFilesNextPageScreenSubD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_ButtonHomeScreenSubDir, ui_event_ButtonHomeScreenSubDir, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMoveScreenSubDir, ui_event_ButtonAxisMoveScreenSubDir, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsScreenSubDir, ui_event_ButtonSettingsScreenSubDir, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserveScreenSubDir, ui_event_ButtonReserveScreenSubDir, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonRootDirScreenSubDir, ui_event_ButtonRootDirScreenSubDir, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonParentDirScreenSubDir, ui_event_ButtonParentDirScreenSubDir, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_CheckboxFile1ScreenSubD, ui_event_CheckboxFile1ScreenSubD, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_PanelFileInfo1ScreenSubD, ui_event_PanelFileInfoScreenSubD, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_PanelFileInfo2ScreenSubD, ui_event_PanelFileInfo2ScreenSubD, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonCopyFilesScreenSubD, ui_event_ButtonCopyFilesScreenSubD, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonDelFilesScreenSubD, ui_event_ButtonDelFilesScreenSubD, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_ImageFilesPrevPageScreenSubD, ui_event_ImageFilesPrevPageScreenSubD, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelPrevFilesPageScreenSubD, ui_event_PanelPrevFilesPageScreenSubD, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_ImageFilesNextPageScreenSubD, ui_event_ImageFilesNextPageScreenSubD, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelNextFilesPageScreenSubD, ui_event_PanelNextFilesPageScreenSubD, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenSubDir, ui_event_SubDirPage, LV_EVENT_ALL, NULL);

}


void LoadSubDirScreen(void)
{
    lv_disp_load_scr(ui_ScreenSubDir);
}

void SubDirPageHomeBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( home_printing_is_printing_finished() )
        LoadHomeNormalScreen();
    else
        LoadHomePrintingScreen();
}

void SubDirPageAxisBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( home_printing_is_printing_finished() )
        LoadAxisMoveScreen();
    else
        LoadAxisMoveScreen();
}

void SubDirPageSettingsBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadSettingsScreen();
}

void SubDirPageReserveBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadCustomerServiceScreen();
}

void SubDPageRootDirBtnClicked(lv_event_t * e)
{
    // Your code here
    enter_sub_dir_handle();
}

void SubDPageParentDirBtnClicked(lv_event_t * e)
{
	// Your code here
    char *parent_name = lv_label_get_text(ui_LabelParentDirScreenSubDir);
    if ( !parent_name ) 
    {

        return ;
    }

    char *dir_flag_pos = strrchr(parent_name, '/');
    if ( !dir_flag_pos || (parent_name - dir_flag_pos) == 0 )
    {
        // create_custom_reminderbox(RootDirTipsMsg[get_cur_language_index()], false);
        // set_custom_reminderbox_display_timeout(1, &enter_sub_dir_handle);
    }
    else
    {
        send_get_parent_dir_file_count_cmd();
        char buff[256] = {0};
        strncpy(buff, parent_name, (dir_flag_pos - parent_name));
        lv_label_set_text(ui_LabelParentDirScreenSubDir, buff);
    }
}


void SubDPageFileInfoPanelClicked(lv_event_t * e)
{
    // Your code here
    dirent_info_part_t *part = lv_event_get_user_data(e);
    if ( !part )
        return ;
    
    if ( part->is_dir )
    {
        send_get_cur_dir_file_count_cmd(part_dirent_index(part));
        char buff[256] = {0};
        sprintf(buff, "%s/%s", lv_label_get_text(ui_LabelParentDirScreenSubDir), part_get_dirent_info_name(part));
        lv_label_set_text(ui_LabelParentDirScreenSubDir, buff);
    }
    else
    {
        if( sub_dir_show_checkbox_file )
        {
            bool status = part_get_file_checkbox_checkedstate(part);
            part_set_file_checkbox_state(part, !status);
            return;
        }
        LoadPreviewScreen();
        preview_set_mode_file_from_dir_type(false);
        //get_mode_file_filling_chart_info(part_dirent_index(part));
        send_get_filling_chart_info_cmd(part_dirent_index(part));
        if ( part->label_dirent_name && part->label_totle_time && part->label_mater_used )
        {
            char *file_name = part_get_dirent_info_name(part);
            preview_set_file_info(file_name, part->totle_time, part->mater_used, part_dirent_index(part), part->filament_type, part->nozzle_temp, part->bed_temp, FROM_UDISK);
        }
    }
}

void sub_dir_show_checkboxes(bool show)
{
    for ( int i = 0; i < 8; i++ )
    {
        if ( !sub_dir_dirent_part_array[i] || !(sub_dir_dirent_part_array[i]->checkbox_file) )
            continue;
        
        if ( sub_dir_dirent_part_array[i]->is_dir )
            continue;

        if ( show )
            lv_obj_clear_flag(sub_dir_dirent_part_array[i]->checkbox_file, LV_OBJ_FLAG_HIDDEN);
        else
        {
            lv_obj_add_flag(sub_dir_dirent_part_array[i]->checkbox_file, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_state(sub_dir_dirent_part_array[i]->checkbox_file, LV_STATE_CHECKED);
        }
            
    }

    return ;
}

void sub_dir_show_file_action(bool show, bool is_local_disk)
{
	// Your code here
    if ( show )
        lv_obj_clear_flag(ui_PanelFileActionScreenSubD, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_PanelFileActionScreenSubD, LV_OBJ_FLAG_HIDDEN);
    
    // char buff[30] = {0};
    uint8_t index = get_cur_language_index();
    if ( ui_LabelCopyUsbFiles )
    {
        if( is_parent_disk_type_is_local )
            lv_label_set_text(ui_LabelCopyUsbFiles, CopyToUSB[index]);
        else
            lv_label_set_text(ui_LabelCopyUsbFiles, CopyToLocal[index]);
        redefine_label_size(ui_LabelCopyUsbFiles, lv_font24.font, 0, 0, 300, 0);
        
        lv_obj_update_layout(ui_ButtonCopyFilesScreenSubD);
        redefine_widgets_size(ui_ButtonCopyFilesScreenSubD, ui_LabelCopyUsbFiles, 10, 0, 130, 70);
    }
    if ( ui_LabelDelUsbFiles )
    {
        lv_label_set_text(ui_LabelDelUsbFiles, Delete[index]);
        redefine_label_size(ui_LabelDelUsbFiles, lv_font24.font, 0, 0, 300, 0);
        
        lv_obj_update_layout(ui_ButtonDelFilesScreenSubD);
        redefine_widgets_size(ui_ButtonDelFilesScreenSubD, ui_LabelDelUsbFiles, 10, 0, 130, 70);
    }
    lv_coord_t width  = lv_obj_get_width(ui_ButtonCopyFilesScreenSubD) > lv_obj_get_width(ui_ButtonDelFilesScreenSubD) ? lv_obj_get_width(ui_ButtonCopyFilesScreenSubD) : lv_obj_get_width(ui_ButtonDelFilesScreenSubD);
    lv_obj_set_width(ui_ButtonCopyFilesScreenSubD, width);
    lv_obj_set_width(ui_ButtonDelFilesScreenSubD, width);
    lv_obj_set_width(ui_PanelFileActionScreenSubD, width);

}

void SubDPageFileInfoPanelLongPressed(lv_event_t * e)
{
	// Your code here
    sub_dir_show_file_action(!sub_dir_show_checkbox_file, is_parent_disk_type_is_local);
    sub_dir_show_checkboxes(!sub_dir_show_checkbox_file);
    sub_dir_show_checkbox_file = !sub_dir_show_checkbox_file;
}

void SubDPageCopyFilesBtnClicked(lv_event_t * e)
{
	// Your code here
    //获取当前的索引序列号
    char sendbuff[100] = {"12"};
    bool send_flag = false;
    if(sub_dir_dirent_part_array[0]->is_local_disk)
        strcat(sendbuff, "\t1");    
    else
        strcat(sendbuff, "\t2");    
    for ( int i = 0; i < 8; i++ )
    {
        if ( part_get_file_checkbox_checkedstate(sub_dir_dirent_part_array[i]) && sub_dir_dirent_part_array[i]->dirent_index )
        {
            send_flag = true;
            CrLogI("copy file index:%d,%d",sub_dir_dirent_part_array[i]->dirent_index,sub_dir_dirent_part_array[i]->is_local_disk);
            char temp[10] = {0};
            snprintf(temp, 10, "\t%d", sub_dir_dirent_part_array[i]->dirent_index);
            strcat(&sendbuff[strlen(sendbuff)], temp);
            CrLogI("copy file:%s",sendbuff);
        }
    }
    if(send_flag)
    {
        if(system_state.Udisk_state)
            set_printer_data(CONTROL_FILE, strlen(sendbuff), sendbuff);
        else
            create_msgbox(DiskUMsg[get_cur_language_index()], NULL, 1000, lv_scr_act());
    }
    CrLogI("key is %d",sub_dir_show_checkbox_file);
    sub_dir_show_file_action(!sub_dir_show_checkbox_file, sub_dir_dirent_part_array[0]->is_local_disk);
    sub_dir_show_checkboxes(!sub_dir_show_checkbox_file);
    sub_dir_show_checkbox_file = !sub_dir_show_checkbox_file;
}

void SubDPageDelFilesBtnClicked(lv_event_t * e)
{
	// Your code here
    //获取当前的索引序列号
    char sendbuff[100] = {"13"};
    bool send_flag = false;  
    for ( int i = 0; i < 8; i++ )
    {
        if ( part_get_file_checkbox_checkedstate(sub_dir_dirent_part_array[i]) && sub_dir_dirent_part_array[i]->dirent_index )
        {
            send_flag = true;
            CrLogI("deleta file index:%d,%d",sub_dir_dirent_part_array[i]->dirent_index,sub_dir_dirent_part_array[i]->is_local_disk);
            char temp[10] = {0};
            snprintf(temp, 10, "\t%d", sub_dir_dirent_part_array[i]->dirent_index);
            strcat(&sendbuff[strlen(sendbuff)], temp);
            CrLogI("deleta file:%s",sendbuff);
        }
    }
    if(send_flag)
    {
        set_printer_data(CONTROL_FILE, strlen(sendbuff), sendbuff);
    }
    sub_dir_show_checkboxes(false);
    sub_dir_show_checkbox_file = false;
}

void SubDPagePrevFilesPageBtnClicked(lv_event_t * e)
{
	// Your code here
    uint8_t index = get_cur_language_index();
    if ( cur_dir_file_count == 0 )
    {
        create_custom_reminderbox(FileCountTipsMsg[index], false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return ;
    }

    if ( (cur_page_start_index <= 1) )
    {
        create_custom_reminderbox(FirstPageMsg[index], false);
        set_custom_reminderbox_display_timeout(1, NULL);
    }
    else
    {
        cur_page_start_index -= PAGE_MAX_DIRENT_COUNT;
        if ( cur_page_start_index < 1 )
            cur_page_start_index = 1;

        send_get_cur_dir_dirent_infos_cmd(cur_page_start_index, PAGE_MAX_DIRENT_COUNT);
    }

}

void SubDPageNextFilesPageBtnClicked(lv_event_t * e)
{
	// Your code here
    uint8_t index = get_cur_language_index();
    if ( cur_dir_file_count == 0 )
    {
        create_custom_reminderbox(FileCountTipsMsg[index], false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return ;
    }

    if ( cur_page_start_index + PAGE_MAX_DIRENT_COUNT > cur_dir_file_count )
    {
        create_custom_reminderbox(LastPageMsg[index], false);
        set_custom_reminderbox_display_timeout(1, NULL);
    }
    else
    {
        cur_page_start_index += PAGE_MAX_DIRENT_COUNT;
        send_get_cur_dir_dirent_infos_cmd(cur_page_start_index, PAGE_MAX_DIRENT_COUNT);
    }
}


void sub_dir_set_files_count(int count)
{
    if ( count <= 0)
    {
        lv_obj_clear_flag(ui_LabelNoContentsPromptScreenSubD, LV_OBJ_FLAG_HIDDEN);
        for ( int i = 0; i < 8; i++ )
        {
            if ( sub_dir_dirent_part_array[i] && sub_dir_dirent_part_array[i]->part_panel )
                lv_obj_add_flag(sub_dir_dirent_part_array[i]->part_panel, LV_OBJ_FLAG_HIDDEN);
        }
        cur_page_start_index = 0;
        cur_dir_file_count = 0;
    }
    else
    {
        lv_obj_add_flag(ui_LabelNoContentsPromptScreenSubD, LV_OBJ_FLAG_HIDDEN);
        send_get_cur_dir_dirent_infos_cmd(1, PAGE_MAX_DIRENT_COUNT);
        cur_page_start_index = 1;
        cur_dir_file_count = count;
    }

}

void sub_dir_set_file_infos(Dirent_Info_t dirent_array[8], int real_count)
{
    if ( real_count <= 0 || !dirent_array)
    {
        lv_obj_clear_flag(ui_LabelNoContentsPromptScreenSubD, LV_OBJ_FLAG_HIDDEN);
        for ( int i = 0; i < 8; i++ )
        {
            if ( sub_dir_dirent_part_array[i] && sub_dir_dirent_part_array[i]->part_panel )
                lv_obj_add_flag(sub_dir_dirent_part_array[i]->part_panel, LV_OBJ_FLAG_HIDDEN);
        }

        return;
    }  
    else
        lv_obj_add_flag(ui_LabelNoContentsPromptScreenSubD, LV_OBJ_FLAG_HIDDEN);

    for ( int i = 0; i < 8; i++ )
    {
        if ( i < real_count )
        {
            if ( sub_dir_dirent_part_array[i] && sub_dir_dirent_part_array[i]->part_panel )
                lv_obj_clear_flag(sub_dir_dirent_part_array[i]->part_panel, LV_OBJ_FLAG_HIDDEN);
            
            dirent_array[i].dirent_index = i + cur_page_start_index;
            if ( dirent_array[i].is_dir )
            {
                time_t timesteamp = (time_t)dirent_array[i].dir_create_time;//atol(dirent_array[i].dir_create_time);
                struct tm *CurTime = localtime(&timesteamp);
                char timepath[20] = {0};
                snprintf(timepath , sizeof(timepath) ,"%d%02d%02d %02d:%02d",
                                    CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
                                    CurTime->tm_hour, CurTime->tm_min);
                part_show_Dir_info(sub_dir_dirent_part_array[i], dirent_array[i].name, 
                                   timepath,  dirent_array[i].dirent_index, is_parent_disk_type_is_local);
                
            }
            else
            {
                part_show_mode_file_info(sub_dir_dirent_part_array[i], dirent_array[i].name, dirent_array[i].mode_thumbnail,
                                        dirent_array[i].totle_time, dirent_array[i].mater_used, 
                                        dirent_array[i].dirent_index, is_parent_disk_type_is_local, dirent_array[i].filament_type, dirent_array[i].nozzle_temp, dirent_array[i].bed_temp);
            }

        }
        else
        {
            if ( sub_dir_dirent_part_array[i] && sub_dir_dirent_part_array[i]->part_panel )
                lv_obj_add_flag(sub_dir_dirent_part_array[i]->part_panel, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void enter_sub_dir_handle(void)
{
    file_manage_switch_screen(SCREEN_FILE);
    LoadFileManageScreen();
}

void sub_dir_enter_screen_settings(char *dir_name, uint16_t dir_sort_index, bool parent_disk_is_local)
{
    uint8_t language_index = get_cur_language_index();
    if ( !dir_name ||strlen(dir_name) <= 0 )
    {
        // create_custom_reminderbox(DirNameTipsMsg[language_index], false);
        // set_custom_reminderbox_display_timeout(1, &enter_sub_dir_handle);
        return ;
    }

    if ( !dir_sort_index )
    {
        // create_custom_reminderbox(DirIndexTipsMsg[language_index], false);
        // set_custom_reminderbox_display_timeout(1, &enter_sub_dir_handle);
        return ;
    }

    if ( ui_LabelParentDirScreenSubDir )
    {
        char buff[100] = {0};
        sprintf(buff, "/%s", dir_name);
        lv_label_set_text(ui_LabelParentDirScreenSubDir, buff);
    }

    //dirent_index = dir_sort_index;
    is_parent_disk_type_is_local = parent_disk_is_local;
    send_get_cur_dir_file_count_cmd(dir_sort_index);
    cur_page_start_index = 0;
    if (ui_LabelRootDirScreenSubDir)
    {
        if ( is_parent_disk_type_is_local )
        {
            lv_label_set_text(ui_LabelRootDirScreenSubDir, Local[language_index]);
        }
        else
        {
            lv_label_set_text(ui_LabelRootDirScreenSubDir, DiskU[language_index]);
        }
    }
}

void sub_dir_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_LabelRootDirScreenSubDir )
    {
        if ( !is_parent_disk_type_is_local )
            lv_label_set_text(ui_LabelRootDirScreenSubDir, DiskU[language_index]);
        else
            lv_label_set_text(ui_LabelRootDirScreenSubDir, Local[language_index]);
    }

    if ( ui_LabelNoContentsPromptScreenSubD )
        lv_label_set_text(ui_LabelNoContentsPromptScreenSubD, NoContentsMsg[language_index]);

    if ( ui_LabelCopyUsbFiles )
    {
        // char buff[30] = {0};
        // sprintf(buff, "%s%s", CopyTo[language_index], Local[language_index]);
        lv_label_set_text(ui_LabelCopyUsbFiles, CopyToLocal[language_index]);
    }

    if ( ui_LabelDelUsbFiles )
        lv_label_set_text(ui_LabelDelUsbFiles, Delete[language_index]);

}



