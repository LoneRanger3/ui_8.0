#include "ui_screen_SubDir.h"
#include "custom.h"
#include "src/core/lv_obj_pos.h"
#include "ui_screen_FileManage.h"
#include "ui_screen_Preview.h"
#include "ui_helpers.h"
#include <json-c/json_object.h>
#include <openssl/ec.h>
#include <stdio.h>
#include <time.h>
#include "ui_custom_dirent_info_part.h"
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_HomePrinting.h"
#include "ui_screen_Adjustment.h"
#include "ui_screen_AxisMove.h"
#include "../custom/lvgl_cmd.h"
#include "ui_Screen_Settings.h"
#include "mult_language.h"


lv_obj_t * ui_ScreenSubDir;
/*--------------left panel---------------*/
static lv_obj_t * ui_PanelPageScreenSubDir;
static lv_obj_t * ui_ButtonHomeScreenSubDir;
static lv_obj_t * ui_ButtonAxisMoveScreenSubDir;
static lv_obj_t * ui_ImageFileManageScreenSubDir;
static lv_obj_t * ui_ButtonSettingsScreenSubDir;
static lv_obj_t * ui_ButtonReserveScreenSubDir;

/*--------------right panel---------------*/
static lv_obj_t * ui_PanelCenterScreenSubD;
static lv_obj_t * ui_PanelScreenSubD;
static lv_obj_t * ui_PanelFileListSubD;

/*--------------right panel title---------------*/

static lv_obj_t * ui_LabelRootDirScreenSubDir;

static lv_obj_t * ui_LabelParentDirScreenSubDir;
static lv_obj_t * ui_PanelSeparateLine;
static lv_obj_t * ui_SubDirBackBtn;
static dirent_info_part_t *sub_dir_dirent_part_array[8] = {NULL};
static lv_obj_t * ui_LabelNoContentsPromptScreenSubD;

/*--------------right panel file action---------------*/


static lv_obj_t * ui_LabelCopyUsbFiles;

static lv_obj_t * ui_LabelDelUsbFiles;

/*--------------right panel file change page---------------*/
static lv_obj_t * ui_PanelPrevFilesPageScreenSubD;
static lv_obj_t * ui_ImageFilesPrevPageScreenSubD;
static lv_obj_t * ui_PanelNextFilesPageScreenSubD;
static lv_obj_t * ui_ImageFilesNextPageScreenSubD;

/************************custom variable**********************************/
#define ROOT_DIR_NAME "/"

static bool sub_dir_show_checkbox_file = false;
//static bool is_parent_disk_type_is_local = true;   //
static bool parent_disk_type_is_udisk = false;   //
static uint16_t parent_disk_part_index = 0;   //
static uint16_t cur_dir_file_count = 0;
static uint16_t cur_page_start_index = 0;
static dirent_info_part_t **GfilepanelSubD = NULL;
static Msgboxbtn_t SubDFileActionbtn[3]; //用于子目录文件操作
static DialogMsgbox_t SubDFileActionMessage; //文件操作对话框

static int SubDGcodeFileNum = 0;  //记录文件夹下 gcode 文件数,不包含文件夹

typedef void (*SubDFileManageAdd3rdObjsCb)(void);
static SubDFileManageAdd3rdObjsCb SubDAdd3rLeveldObjsCb = NULL; 

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
// static void ui_event_ButtonCopyFilesScreenSubD(lv_event_t * e);
// static void ui_event_ButtonDelFilesScreenSubD(lv_event_t * e);
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
static void SubDlocalGcodeFileInfoParse(void);
static void FileManageSubDPageChangeObjs(uint8_t index);
static void SubDShowGcodeInfo(uint8_t isUdisk);
static void SubDFileActionPageAddFocusObjs(void);

void RefreshSubDShowGcodeInfo(uint8_t wait_time);

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

//子目录文件名按钮单击
void ui_event_ButtonParentDirScreenSubDir(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SubDPageParentDirBtnClicked(e);
    }
}

/**
 * @description: 子目录文件单击和长按处理
 * @return {*}
 * @param {lv_event_t *} e
 */
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

static void ui_event_SubDirBackBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        if (FileListNumberHasChanged()) //文件夹内返回列表首页需判断文件列表个数是否有变化
        {
            LoadFileManageScreenAndObjs(false);
            LoadFileManageScreenAndObjs(true);
        }
        else
        {
            BackPrepage(false);
        }
    }
}

void ui_event_SubDFileAction(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int dat = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        switch(dat) //子目录文件操作
        {
            case 0: 
                SubDPageCopyFilesBtnClicked(e);
                //RefreshSubDShowGcodeInfo(10);
                break; //拷贝文件事件处理
            case 1: 
                SubDPageDelFilesBtnClicked(e);
                RefreshSubDShowGcodeInfo(10);
                break;  //删除事件处理
            case 2: HiddenDialogMessagebox(&SubDFileActionMessage); break;
            default:break;
        }
        
        HiddenDialogMessagebox(&SubDFileActionMessage);
        //SubDAdd3rLeveldObjsCb = NULL;
        CrLogI("ui_event_SubDFileAction BackPrepage(true)");
        
        // GetSubDGcodeFileNum(parent_disk_type_is_udisk, parent_disk_part_index);
        // LoadSubDirScreen();
        // SubDShowGcodeInfo(parent_disk_type_is_udisk);
        // FileManageSubDPageChangeObjs(1);
       // SubDShowGcodeInfo();
        BackPrepage(true);
      
    }
}

void SubDFileActionTextSet(lv_obj_t *label, uint8_t label_index, uint8_t language_index)
{
    switch (label_index) {
    case 0:
        lv_label_set_text(label, CopyToUSB[language_index]);
        break;
    case 1:
        lv_label_set_text(label, Delete[language_index]);
        break;
    case 2:
        lv_label_set_text(label, Back[language_index]);  
        break;
    default:break;
    }    
}

void ui_ScreenSubDir_screen_init(void)
{
    ui_ScreenSubDir = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenSubDir, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenSubDir, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    init_pages(ui_ScreenSubDir, FileManageSubDPageChangeObjs, LoadSubDirScreen);
    int language_index = get_cur_language_index();

    ui_PanelPageScreenSubDir = lv_obj_create(ui_ScreenSubDir);
    lv_obj_set_width(ui_PanelPageScreenSubDir, 68);
    lv_obj_set_height(ui_PanelPageScreenSubDir, 360);
    lv_obj_set_pos(ui_PanelPageScreenSubDir, 0, 60);
    lv_obj_clear_flag(ui_PanelPageScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPageScreenSubDir, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPageScreenSubDir, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonHomeScreenSubDir = lv_btn_create(ui_PanelPageScreenSubDir);
    lv_obj_set_width(ui_ButtonHomeScreenSubDir, 68);
    lv_obj_set_height(ui_ButtonHomeScreenSubDir, 72);
    lv_obj_set_x(ui_ButtonHomeScreenSubDir, -18);
    lv_obj_set_y(ui_ButtonHomeScreenSubDir, -18);
    lv_obj_add_flag(ui_ButtonHomeScreenSubDir, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenSubDir, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonHomeScreenSubDir, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenSubDir, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenSubDir, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonAxisMoveScreenSubDir = lv_btn_create(ui_PanelPageScreenSubDir);
    lv_obj_set_width(ui_ButtonAxisMoveScreenSubDir, 68);
    lv_obj_set_height(ui_ButtonAxisMoveScreenSubDir, 72);
    lv_obj_set_x(ui_ButtonAxisMoveScreenSubDir, -18);
    lv_obj_set_y(ui_ButtonAxisMoveScreenSubDir, 54);
    lv_obj_add_flag(ui_ButtonAxisMoveScreenSubDir, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveScreenSubDir, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMoveScreenSubDir, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveScreenSubDir, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveScreenSubDir, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageFileManageScreenSubDir = lv_img_create(ui_PanelPageScreenSubDir);
    lv_img_set_src(ui_ImageFileManageScreenSubDir, &ui_img_pagefilemanageselected_png);
    lv_obj_set_width(ui_ImageFileManageScreenSubDir, 68);
    lv_obj_set_height(ui_ImageFileManageScreenSubDir, 72);
    lv_obj_set_x(ui_ImageFileManageScreenSubDir, -18);
    lv_obj_set_y(ui_ImageFileManageScreenSubDir, 126);
    lv_obj_add_flag(ui_ImageFileManageScreenSubDir, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFileManageScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonSettingsScreenSubDir = lv_btn_create(ui_PanelPageScreenSubDir);
    lv_obj_set_width(ui_ButtonSettingsScreenSubDir, 68);
    lv_obj_set_height(ui_ButtonSettingsScreenSubDir, 72);
    lv_obj_set_x(ui_ButtonSettingsScreenSubDir, -18);
    lv_obj_set_y(ui_ButtonSettingsScreenSubDir, 198);
    lv_obj_add_flag(ui_ButtonSettingsScreenSubDir, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenSubDir, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenSubDir, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenSubDir, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenSubDir, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonReserveScreenSubDir = lv_btn_create(ui_PanelPageScreenSubDir);
    lv_obj_set_width(ui_ButtonReserveScreenSubDir, 68);
    lv_obj_set_height(ui_ButtonReserveScreenSubDir, 72);
    lv_obj_set_x(ui_ButtonReserveScreenSubDir, -18);
    lv_obj_set_y(ui_ButtonReserveScreenSubDir, 270);
   // lv_obj_add_flag(ui_ButtonReserveScreenSubDir, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveScreenSubDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenSubDir, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveScreenSubDir, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonReserveScreenSubDir, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonReserveScreenSubDir, 2, LV_PART_MAIN | LV_STATE_PRESSED);


    ui_PanelScreenSubD = lv_obj_create(ui_ScreenSubDir);
    lv_obj_set_pos(ui_PanelScreenSubD, 73, 68);
    lv_obj_set_size(ui_PanelScreenSubD, 559, 344);
    lv_obj_set_align(ui_PanelScreenSubD, LV_ALIGN_TOP_LEFT);
   // lv_obj_clear_flag(ui_PanelScreenSubD, LV_OBJ_FLAG_SCROLLABLE); 
    //lv_obj_add_flag(ui_PanelScreenSubD, LV_OBJ_FLAG_SCROLL_ON_FOCUS);       /// Flags
    lv_obj_set_style_radius(ui_PanelScreenSubD, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelScreenSubD, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelScreenSubD, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelScreenSubD, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelScreenSubD, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_LabelRootDirScreenSubDir = lv_label_create(ui_PanelScreenSubD);
    lv_obj_set_size(ui_LabelRootDirScreenSubDir, 55, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_LabelRootDirScreenSubDir, 26, 0);
    //lv_obj_set_align(ui_NetworkLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_LabelRootDirScreenSubDir, Local[language_index]);//DetectionItemArray[language_index]
    lv_obj_set_style_text_align(ui_LabelRootDirScreenSubDir, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelRootDirScreenSubDir, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelRootDirScreenSubDir, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelRootDirScreenSubDir, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LabelRootDirScreenSubDir, LV_LABEL_LONG_SCROLL_CIRCULAR);

    ui_LabelParentDirScreenSubDir = lv_label_create(ui_PanelScreenSubD);
    lv_obj_set_size(ui_LabelParentDirScreenSubDir, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align_to(ui_LabelParentDirScreenSubDir, ui_LabelRootDirScreenSubDir, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    lv_label_set_long_mode(ui_LabelParentDirScreenSubDir, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelParentDirScreenSubDir, "");
    lv_obj_set_style_text_align(ui_LabelParentDirScreenSubDir, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelParentDirScreenSubDir, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelParentDirScreenSubDir, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelParentDirScreenSubDir, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_PanelSeparateLine = lv_obj_create(ui_PanelScreenSubD);
    lv_obj_set_size(ui_PanelSeparateLine, 543, 1);
    lv_obj_set_pos(ui_PanelSeparateLine, 7, 49);
    lv_obj_clear_flag(ui_PanelSeparateLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_PanelSeparateLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelSeparateLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelSeparateLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelSeparateLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelSeparateLine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    // 返回按钮
    ui_SubDirBackBtn = lv_btn_create(ui_PanelScreenSubD);
    lv_obj_set_size(ui_SubDirBackBtn, 68, 38);
    lv_obj_set_pos(ui_SubDirBackBtn, 474, 6);
    lv_obj_add_flag(ui_SubDirBackBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SubDirBackBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SubDirBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SubDirBackBtn, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SubDirBackBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SubDirBackBtn, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SubDirBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SubDirBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SubDirBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_SubDirBackBtn, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SubDirBackBtn, lv_color_hex(0xB0F1FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_SubDirBackBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_SubDirBackBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_SubDirBackBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_SubDirBackBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_SubDirBackBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    
    ui_PanelFileListSubD = lv_obj_create(ui_PanelScreenSubD);
    lv_obj_set_width(ui_PanelFileListSubD, 559);
    lv_obj_set_height(ui_PanelFileListSubD, 270);
    lv_obj_set_x(ui_PanelFileListSubD, 0);
    lv_obj_set_y(ui_PanelFileListSubD, 58);
   // lv_obj_add_flag(ui_PanelFileListSubD, LV_OBJ_FLAG_SCROLL_ON_FOCUS);  
   // lv_obj_clear_flag(ui_PanelFileListSubD, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFileListSubD, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFileListSubD, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFileListSubD, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFileListSubD, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_add_flag(ui_PanelFileListSubD, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_style_pad_all(ui_PanelFileListSubD, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_set_scroll_snap_y(ui_PanelFileListSubD, LV_SCROLL_SNAP_NONE);
    lv_obj_set_flex_flow(ui_PanelFileListSubD, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_left(ui_PanelFileListSubD, 9, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_PanelFileListSubD, 12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelNoContentsPromptScreenSubD = lv_label_create(ui_PanelFileListSubD);
    lv_obj_set_width(ui_LabelNoContentsPromptScreenSubD, 160);
    lv_obj_set_height(ui_LabelNoContentsPromptScreenSubD, 36);
    lv_obj_set_x(ui_LabelNoContentsPromptScreenSubD, 200);
    lv_obj_set_y(ui_LabelNoContentsPromptScreenSubD, 120);
    lv_label_set_text(ui_LabelNoContentsPromptScreenSubD, NoContentsMsg[language_index]);
    lv_obj_add_flag(ui_LabelNoContentsPromptScreenSubD, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_LabelNoContentsPromptScreenSubD, lv_color_hex(0x6A707D),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelNoContentsPromptScreenSubD, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelNoContentsPromptScreenSubD, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelNoContentsPromptScreenSubD, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LabelNoContentsPromptScreenSubD, LV_LABEL_LONG_SCROLL_CIRCULAR);

    
     // 文件操作对话框初始化
    for (size_t i = 0; i < 3; i++)
    {
        SubDFileActionbtn[i].btnsCallbackArray = ui_event_SubDFileAction;
        SubDFileActionbtn[i].SetLabelText = SubDFileActionTextSet;
    }
    SubDFileActionMessage.hasSubPanel = true;
    SubDFileActionMessage.title = Action;
    SubDFileActionMessage.btn = SubDFileActionbtn;
    SubDFileActionMessage.customStyle = &StyleDialogBtn;
    SubDFileActionMessage.customFocusStyle = &StyleDialogFocusBtn;

    SubDFileActionMessage.btnNumber = sizeof(SubDFileActionbtn)/sizeof(Msgboxbtn_t);
    SubDFileActionMessage.subPanelAttr.w = 373;
    SubDFileActionMessage.subPanelAttr.h = 278;

    InitDialogMessagebox(&SubDFileActionMessage);
    lv_obj_align(SubDFileActionMessage.titleLabel, LV_ALIGN_TOP_MID, 0, 11);
    
    uint8_t btnBasePos_y = 56;
    for (size_t i = 0; i < SubDFileActionMessage.btnNumber; i++)
    {
        lv_obj_align(SubDFileActionMessage.btn[i].label, LV_ALIGN_LEFT_MID, 0, 1);
        lv_obj_set_size(SubDFileActionMessage.btn[i].btn, 312, 52);
        lv_obj_set_pos(SubDFileActionMessage.btn[i].btn, 35, btnBasePos_y);
        btnBasePos_y += 67;
    }

    lv_obj_add_event_cb(ui_ButtonHomeScreenSubDir, ui_event_ButtonHomeScreenSubDir, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMoveScreenSubDir, ui_event_ButtonAxisMoveScreenSubDir, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsScreenSubDir, ui_event_ButtonSettingsScreenSubDir, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserveScreenSubDir, ui_event_ButtonReserveScreenSubDir, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenSubDir, ui_event_SubDirPage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SubDirBackBtn, ui_event_SubDirBackBtn, LV_EVENT_ALL, NULL);
}


void LoadSubDirScreen(void)
{
    SubDGcodePanelMemoryManager(SubDGcodeFileNum);
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
        create_custom_reminderbox(RootDirTipsMsg[get_cur_language_index()], false);
        set_custom_reminderbox_display_timeout(1, &enter_sub_dir_handle);
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
    
    if (part->is_dir)
    {
        send_get_cur_dir_file_count_cmd(part_dirent_index(part));
        char buff[256] = {0};
        sprintf(buff, "%s/%s", lv_label_get_text(ui_LabelParentDirScreenSubDir), part_get_dirent_info_name(part));
        lv_label_set_text(ui_LabelParentDirScreenSubDir, buff);
    }
    else
    {
        //LoadPreviewScreen();
        LoadPage(ui_ScreenPreview, 2);
        preview_set_mode_file_from_dir_type(false);
        //get_mode_file_filling_chart_info(part_dirent_index(part));
        //send_get_filling_chart_info_cmd(part_dirent_index(part));
        if ( part->label_dirent_name && part->label_totle_time && part->label_mater_used )
        {
            //char *file_name = part_get_dirent_info_name(part);
            preview_set_file_info(part, false);
           // preview_set_file_info(file_name, part->totle_time, part->mater_used, part_dirent_index(part), part->filament_type, part->nozzle_temp, part->bed_temp, FROM_UDISK);
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
    // if ( show )
    //     lv_obj_clear_flag(ui_PanelFileActionScreenSubD, LV_OBJ_FLAG_HIDDEN);
    // else
    //     lv_obj_add_flag(ui_PanelFileActionScreenSubD, LV_OBJ_FLAG_HIDDEN);
    
    // char buff[30] = {0};
    uint8_t index = get_cur_language_index();
    // if ( is_parent_disk_type_is_local )
    // {
    //     // if ( ui_LabelCopyUsbFiles )
    //     // {
    //     //     // sprintf(buff, "%s%s", CopyTo[index], DiskU[index]);
    //     //     lv_label_set_text(ui_LabelCopyUsbFiles, CopyToUSB[index]);
    //     // }
    // }
    // else
    // {
    //     // if ( ui_LabelCopyUsbFiles )
    //     // {
    //     //     // sprintf(buff, "%s%s", CopyTo[index], Local[index]);
    //     //     lv_label_set_text(ui_LabelCopyUsbFiles, CopyToLocal[index]);
    //     // }
    // }

}

void SubDPageFileInfoPanelLongPressed(lv_event_t * e)
{
    dirent_info_part_t *part = lv_event_get_user_data(e);
    if (!part)
        return ;
	ShowDialogMessagebox(&SubDFileActionMessage, SubDFileActionPageAddFocusObjs);
    uint8_t language_index = get_cur_language_index();
    //SubDAdd3rLeveldObjsCb = SubDFileActionPageAddFocusObjs;
    
    //LoadPage(ui_ScreenSubDir, 2);

    ActionGcodes.isUdiskFile = part->is_udisk;
    ActionGcodes.gcodeIndex = part->dirent_index;
    if(ActionGcodes.isUdiskFile) {
        lv_label_set_text(SubDFileActionMessage.btn[0].label, CopyToLocal[language_index]);
           
        json_object *udiskFileObj = json_object_from_file(GetUserUdiskGcodeFileInfoPtah());
        if (udiskFileObj != NULL)
        {
            json_object *elem = json_object_array_get_idx(udiskFileObj, part->subdir_part_index);
            json_object *subelem = json_object_array_get_idx(json_object_object_get(elem, "file"), part->dirent_index);
            char *path = json_object_get_string(json_object_object_get(subelem, "path"));
            memset(ActionGcodes.filePath, 0, sizeof(ActionGcodes.filePath));
            if (path != NULL)
                strncpy(ActionGcodes.filePath, path, sizeof(ActionGcodes.filePath));
        
            json_object_put(udiskFileObj);  
        }
    }
    else {
        lv_label_set_text(SubDFileActionMessage.btn[0].label, CopyToUSB[language_index]);

        json_object *localFileObj = json_object_from_file(GetUserLocalGcodeFileInfoPtah());
        if (localFileObj != NULL)
        {
            json_object *elem = json_object_array_get_idx(localFileObj, part->subdir_part_index);
            json_object *subelem = json_object_array_get_idx(json_object_object_get(elem, "file"), part->dirent_index);
            char *path = json_object_get_string(json_object_object_get(subelem, "path"));
            memset(ActionGcodes.filePath, 0, sizeof(ActionGcodes.filePath));
            if (path != NULL)
                strncpy(ActionGcodes.filePath, path, sizeof(ActionGcodes.filePath));
            json_object_put(localFileObj);
        }
    }
}

void SubDPageCopyFilesBtnClicked(lv_event_t * e)
{
	// Your code here
    //获取当前的索引序列号
    char sendbuff[100] = {"12"};

    if(ActionGcodes.isUdiskFile)
        strcat(sendbuff, "\t2");    
    else
        strcat(sendbuff, "\t1");    
    
    if (system_state.Udisk_state)
    {
        set_printer_data(CONTROL_FILE, strlen(sendbuff), sendbuff);
        HiddenDialogMessagebox(&SubDFileActionMessage);
        CrLogI("key is %d",sub_dir_show_checkbox_file);
    }
    else
    {
        create_msgbox(DiskUMsg[get_cur_language_index()], NULL, 1000, lv_scr_act());
        HiddenDialogMessagebox(&SubDFileActionMessage);
        BackPrepage(true);
    }
   // }
}

void SubDPageDelFilesBtnClicked(lv_event_t * e)
{
	// Your code here
    //获取当前的索引序列号
    char sendbuff[100] = {"13"};
    set_printer_data(CONTROL_FILE, strlen(sendbuff), sendbuff);
}

void SubDPagePrevFilesPageBtnClicked(lv_event_t * e)
{
	// Your code here
    uint8_t index = get_cur_language_index();
    if ( cur_dir_file_count == 0 )
    {
        create_custom_reminderbox(FileCountTipsMsg[index], false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return;
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

    if ( cur_page_start_index + PAGE_MAX_DIRENT_COUNT >= cur_dir_file_count )
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

/**
 * @description: 根据gcode的文件数动态管理内存
 * @return {*}
 * @param {uint16_t} file_number
 */
void SubDGcodePanelMemoryManager(int file_number)
{
    static uint16_t preFileNum = 0;
    dirent_info_part_t **NewGfilepanel = NULL;
    
    if (preFileNum == 0)
    {
        GfilepanelSubD = (dirent_info_part_t **)malloc(file_number*sizeof(dirent_info_part_t *));
        if (GfilepanelSubD != NULL)
        {
            for (size_t i = preFileNum; i < file_number; i++)
            {
                GfilepanelSubD[i] = create_custom_dirent_info_part(ui_PanelFileListSubD, &ui_event_PanelFileInfoScreenSubD);
                lv_obj_set_size(GfilepanelSubD[i]->part_panel, 528, 82);
                lv_obj_set_y(GfilepanelSubD[i]->img_time_png, 51);
                lv_obj_set_y(GfilepanelSubD[i]->img_mater_png, 52);
                lv_obj_set_y(GfilepanelSubD[i]->label_totle_time, 46);
                lv_obj_set_y(GfilepanelSubD[i]->label_mater_used, 46);
                lv_obj_set_y(GfilepanelSubD[i]->img_file_png, -10);
                lv_obj_set_x(GfilepanelSubD[i]->img_udik_png, 490);
                lv_img_set_zoom(GfilepanelSubD[i]->img_file_png, 195);
            }
        }
    }  
    else if (file_number > preFileNum)
    {
        NewGfilepanel = (dirent_info_part_t **)realloc(GfilepanelSubD, file_number*sizeof(dirent_info_part_t *));
        if (GfilepanelSubD != NULL)
        {
            GfilepanelSubD = NewGfilepanel;
            for (size_t i = preFileNum; i < file_number; i++)
            {
                GfilepanelSubD[i] = create_custom_dirent_info_part(ui_PanelFileListSubD, &ui_event_PanelFileInfoScreenSubD);
                lv_obj_set_size(GfilepanelSubD[i]->part_panel, 528, 82);
                lv_obj_set_y(GfilepanelSubD[i]->img_time_png, 51);
                lv_obj_set_y(GfilepanelSubD[i]->img_mater_png, 52);
                lv_obj_set_y(GfilepanelSubD[i]->label_totle_time, 46);
                lv_obj_set_y(GfilepanelSubD[i]->label_mater_used, 46);
                lv_obj_set_y(GfilepanelSubD[i]->img_file_png, -10);
                lv_obj_set_x(GfilepanelSubD[i]->img_udik_png, 490);
                lv_img_set_zoom(GfilepanelSubD[i]->img_file_png, 195);
            }
        }
      
    }
    else if (file_number < preFileNum)
    {

        NewGfilepanel = (dirent_info_part_t **)malloc(file_number*sizeof(dirent_info_part_t *));
        
        for (size_t i = file_number; i < preFileNum; i++) //释放退出面板对象占用空间
        {
            lv_obj_del(GfilepanelSubD[i]->part_panel); 
            // part_array[i] = create_custom_dirent_info_part(ui_PanelFileListSubD, 9, ui_PanelFileListY, &ui_event_PanelFileInfo);
        }
        if (GfilepanelSubD != NULL) {
             memcpy(NewGfilepanel, GfilepanelSubD, file_number * sizeof(dirent_info_part_t *));
             free(GfilepanelSubD);
             GfilepanelSubD = NULL;
        }
        GfilepanelSubD = NewGfilepanel;
        
    }
    CrLogI("GcodePanelMemoryManager file_number:%d, preFileNum:%d", file_number, preFileNum);
    preFileNum = file_number;
}

/**
 * @description: 获取本地文件夹 gcode 文件数，过滤掉子文件夹
 * @return {*}
 * @param {uint16_t} part_index
 */
int GetSubDlocalGcodeFileNum(uint16_t part_index)
{
    int count_cnt = 0;
    if (access(GetUserLocalGcodeInfoDirPtah(), F_OK) == 0) {
        json_object *udiskFileObj = json_object_from_file(GetUserLocalGcodeFileInfoPtah());
        if (udiskFileObj != NULL) 
        {
            json_object *elem = json_object_array_get_idx(udiskFileObj, part_index);
            // int type = json_object_get_int(json_object_object_get(elem, "type"));
            // if (type != 4) return 0;

            json_object *SubDlocalObj = json_object_object_get(elem, "file");
            int SubDTotalFileNum = json_object_array_length(SubDlocalObj);
            for (size_t i = 0; i < SubDTotalFileNum; i++)
            {
                json_object *subelem = json_object_array_get_idx(SubDlocalObj, i);
                int SubDtype = json_object_get_int(json_object_object_get(subelem, "type"));
                if (SubDtype == 8) 
                    count_cnt++;
            }
            json_object_put(udiskFileObj);
        }
        SubDGcodeFileNum = count_cnt;
    }
    return SubDGcodeFileNum;   
}

/**
 * @description: 本地子目录解析
 * @return {*}
 */
static void SubDlocalGcodeFileInfoParse(void)
{
    int j = 0;
    Dirent_Info_t GcodeInfo;
    memset(&GcodeInfo, 0, sizeof(GcodeInfo));
    if (access(GetUserLocalGcodeInfoDirPtah(), F_OK) != 0) 
        return;
    CrLogI("SubDlocalGcodeFileInfoParse.");
    json_object *udiskFileObj = json_object_from_file(GetUserLocalGcodeFileInfoPtah());
    if (udiskFileObj == NULL) 
        goto PARSE_FAIL;
 
    json_object *elem = json_object_array_get_idx(udiskFileObj, parent_disk_part_index); 
    int type = json_object_get_int(json_object_object_get(elem, "type"));
    if (type != 4)  //此处文件类型必须为4，解析子目录下的文件
        goto PARSE_FAIL;

    json_object *SubDlocalObj = json_object_object_get(elem, "file");
    int SubDlocalTotalNum =  json_object_array_length(SubDlocalObj);
    for (size_t i = 0; i < SubDlocalTotalNum; i++)
    {
        json_object *subelem = json_object_array_get_idx(SubDlocalObj, i);
        int SubDtype = json_object_get_int(json_object_object_get(subelem, "type"));
        if (SubDtype == 4)
        {
            //二级子目录
        }
        if (SubDtype == 8)
        {
            char *name = json_object_get_string(json_object_object_get(subelem, "name"));
            strncpy(GcodeInfo.name, name, sizeof(GcodeInfo.name));

            // char *path = json_object_get_string(json_object_object_get(subelem, "path"));
            // strncpy(GcodeInfo.path, path, sizeof(GcodeInfo.path));
            // printf("GcodeInfo2.name :%s\n", GcodeInfo.name);
            GcodeInfo.dir_create_time = (uint64_t)json_object_get_int64(json_object_object_get(subelem, "create_time"));
          //  printf("GcodeInfo2.dir_create_time :%lld\n", GcodeInfo.dir_create_time);

            GcodeInfo.totle_time = json_object_get_int(json_object_object_get(subelem, "timeCost")); 
          //  printf("GcodeInfo.totle_time :%d\n", GcodeInfo.totle_time);

            GcodeInfo.mater_used = json_object_get_int(json_object_object_get(subelem, "consumables")); //使用耗材长度
          //  printf("GcodeInfo.mater_used :%d\n", GcodeInfo.mater_used);
            char *material = json_object_get_string(json_object_object_get(subelem, "material")); //材料类型
          //  printf("material :%s\n", material);
            if (material != NULL)
                strncpy(GcodeInfo.filament_type, material, sizeof(GcodeInfo.filament_type)); 

            GcodeInfo.nozzle_temp = json_object_get_int(json_object_object_get(subelem, "nozzleTemp")); //喷嘴温度
            GcodeInfo.bed_temp = json_object_get_int(json_object_object_get(subelem, "bedTemp")); //热床温度
            char *mode_thumbnail = json_object_get_string(json_object_object_get(subelem, "thumbnail")); //热床温度
            if (mode_thumbnail != NULL)
                strncpy(GcodeInfo.mode_thumbnail, mode_thumbnail, sizeof(GcodeInfo.mode_thumbnail));  
            
            GcodeInfo.is_udisk = false;
            GcodeInfo.dirent_index = i;
            GcodeInfo.subdir_part_index = parent_disk_part_index;
            if (j < SubDGcodeFileNum) 
                ShowPartGcodefileInfo(GfilepanelSubD[j++], &GcodeInfo); 
        }
    } 

PARSE_FAIL:             
    json_object_put(udiskFileObj);
}

/**
 * @description: 获取u盘文件夹 gcode 文件数，过滤掉子文件夹
 * @return {*}
 * @param {uint16_t} part_index
 */
int GetSubDUdiskGcodeFileNum(uint16_t part_index)
{
    int count = 0;
 
    if (access(GetUserUdiskGcodeInfoDirPtah(), F_OK) == 0) {
        json_object *udiskFileObj = json_object_from_file(GetUserUdiskGcodeFileInfoPtah());
        if (udiskFileObj != NULL) 
        {
            json_object *elem = json_object_array_get_idx(udiskFileObj, part_index);
            int type = json_object_get_int(json_object_object_get(elem, "type"));
            if (type != 4) return 0;

            json_object *SubDlocalObj = json_object_object_get(elem, "file");
            int SubDTotalFileNum = json_object_array_length(SubDlocalObj);
            for (size_t i = 0; i < SubDTotalFileNum; i++)
            {
                json_object *subelem = json_object_array_get_idx(SubDlocalObj, i);
                int SubDtype = json_object_get_int(json_object_object_get(subelem, "type"));
                if (SubDtype == 8)
                {
                    count++;
                }
            }
            json_object_put(udiskFileObj);
        }
        SubDGcodeFileNum = count;
        CrLogI(" GetSubDUdiskGcodeFileNum --SubDGcodeFileNum: %d\n", SubDGcodeFileNum);
    }
    return SubDGcodeFileNum;   
}

/**
 * @description: u盘子目录解析
 * @return {*}
 */
static void SubDUdiskGcodeFileInfoParse(void)
{
    int j = 0;
    Dirent_Info_t GcodeInfo;
    memset(&GcodeInfo, 0, sizeof(GcodeInfo));
    if (access(GetUserUdiskGcodeInfoDirPtah(), F_OK) != 0) 
        return;
    CrLogI("SubDUdiskGcodeFileInfoParse.");
    json_object *udiskFileObj = json_object_from_file(GetUserUdiskGcodeFileInfoPtah());
    if (udiskFileObj == NULL) 
        goto PARSE_FAIL;
 
    json_object *elem = json_object_array_get_idx(udiskFileObj, parent_disk_part_index);
    int type = json_object_get_int(json_object_object_get(elem, "type"));
    if (type != 4)  //此处文件类型必须为4，解析子目录下的文件
        goto PARSE_FAIL;

    json_object *SubDlocalObj = json_object_object_get(elem, "file");
    int SubDlocalTotalNum =  json_object_array_length(SubDlocalObj);
       // 打印格式化的 JSON 字符串
    // const char* json_str = json_object_to_json_string_ext(SubDlocalObj, JSON_C_TO_STRING_PRETTY);
    // printf("%s\n", json_str);
    for (size_t i = 0; i < SubDlocalTotalNum; i++)
    {
        
        json_object *subelem = json_object_array_get_idx(SubDlocalObj, i);
        int SubDtype = json_object_get_int(json_object_object_get(subelem, "type"));
        if (SubDtype == 4)
        {
            //二级子目录
        }
        if (SubDtype == 8)
        {
            char *name = json_object_get_string(json_object_object_get(subelem, "name"));
            strncpy(GcodeInfo.name, name, sizeof(GcodeInfo.name));

            // char *path = json_object_get_string(json_object_object_get(subelem, "path"));
            // strncpy(GcodeInfo.path, path, sizeof(GcodeInfo.path));
            // printf("GcodeInfo2.name :%s\n", GcodeInfo.name);
            GcodeInfo.dir_create_time = (uint64_t)json_object_get_int64(json_object_object_get(subelem, "create_time"));
          //  printf("GcodeInfo2.dir_create_time :%lld\n", GcodeInfo.dir_create_time);

            GcodeInfo.totle_time = json_object_get_int(json_object_object_get(subelem, "timeCost")); 
         //   printf("GcodeInfo.totle_time :%d\n", GcodeInfo.totle_time);

            GcodeInfo.mater_used = json_object_get_int(json_object_object_get(subelem, "consumables")); //使用耗材长度
          //  printf("GcodeInfo.mater_used :%d\n", GcodeInfo.mater_used);
            char *material = json_object_get_string(json_object_object_get(subelem, "material")); //材料类型
          //  printf("material :%s\n", material);
            if (material != NULL)
                strncpy(GcodeInfo.filament_type, material, sizeof(GcodeInfo.filament_type)); 

            GcodeInfo.nozzle_temp = json_object_get_int(json_object_object_get(subelem, "nozzleTemp")); //喷嘴温度
            GcodeInfo.bed_temp = json_object_get_int(json_object_object_get(subelem, "bedTemp")); //热床温度
            char *mode_thumbnail = json_object_get_string(json_object_object_get(subelem, "thumbnail")); //热床温度
            
            if (mode_thumbnail != NULL)
                strncpy(GcodeInfo.mode_thumbnail, mode_thumbnail, sizeof(GcodeInfo.mode_thumbnail)); 

            GcodeInfo.is_udisk = true;
            GcodeInfo.dirent_index = i;
            GcodeInfo.subdir_part_index = parent_disk_part_index;
            if (j < SubDGcodeFileNum) 
                ShowPartGcodefileInfo(GfilepanelSubD[j++], &GcodeInfo); 
        }
    } 
PARSE_FAIL:               
    json_object_put(udiskFileObj);
}

static void SubDShowGcodeInfo(uint8_t isUdisk)
{
    if (SubDGcodeFileNum == 0) return;
    if (isUdisk)
    {
        SubDUdiskGcodeFileInfoParse();
    }
    else
    {
        SubDlocalGcodeFileInfoParse();
    }
}

int GetSubDGcodeFileNum(bool udisk, uint16_t part_index)
{
    CrLogI("udisk :%d, part_index : %d", udisk, part_index);
    if (udisk)
    {
        GetSubDUdiskGcodeFileNum(part_index);
    }
    else
    {
        GetSubDlocalGcodeFileNum(part_index);
    }
    return SubDGcodeFileNum;
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
            // if ( dirent_array[i].is_dir )
            // {
            //     time_t timesteamp = (time_t)dirent_array[i].dir_create_time;//atol(dirent_array[i].dir_create_time);
            //     struct tm *CurTime = localtime(&timesteamp);
            //     char timepath[20] = {0};
            //     snprintf(timepath , sizeof(timepath) ,"%d%02d%02d %02d:%02d",
            //                         CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
            //     //                     CurTime->tm_hour, CurTime->tm_min);
            //     // part_show_Dir_info(sub_dir_dirent_part_array[i], dirent_array[i].name, 
            //     //                    timepath,  dirent_array[i].dirent_index, is_parent_disk_type_is_local);
                
            // }
            // else
            // {
            //     // part_show_mode_file_info(sub_dir_dirent_part_array[i], dirent_array[i].name, dirent_array[i].mode_thumbnail,
            //     //                         dirent_array[i].totle_time, dirent_array[i].mater_used, 
            //     //                         dirent_array[i].dirent_index, is_parent_disk_type_is_local, dirent_array[i].filament_type, dirent_array[i].nozzle_temp, dirent_array[i].bed_temp);
            // }

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
    LoadFileManageScreen();
}

// void sub_dir_enter_screen_settings(char *dir_name, uint16_t dir_sort_index, bool parent_disk_is_local)
void sub_dir_enter_screen_settings(dirent_info_part_t *part)
{
    uint8_t language_index = get_cur_language_index();
    if ( !part->dirent_name ||strlen(part->dirent_name) <= 0 )
    {
        create_custom_reminderbox(DirNameTipsMsg[language_index], false);
        set_custom_reminderbox_display_timeout(1, &enter_sub_dir_handle);
        return;
    }

    if (part->dirent_index  > GetFileGcodeListNum())
    {
        create_custom_reminderbox(DirIndexTipsMsg[language_index], false);
        set_custom_reminderbox_display_timeout(1, &enter_sub_dir_handle);
        return ;
    }

    if (ui_LabelParentDirScreenSubDir)
    {
        char buff[100] = {0};
        sprintf(buff, "/%s", part->dirent_name);
        lv_label_set_text(ui_LabelParentDirScreenSubDir, buff);
    }
    if (part->is_udisk)
    {
        parent_disk_type_is_udisk = true;
    }
    else
    {
        parent_disk_type_is_udisk = false;
    }
    CrLogI("parent_disk_type_is_udisk:%d\n", parent_disk_type_is_udisk);

    parent_disk_part_index = part->dirent_index; 
    CrLogI("parent_disk_part_index:%d", parent_disk_part_index);
    //dirent_index = dir_sort_index;
    // is_parent_disk_type_is_local = parent_disk_is_local;
    // send_get_cur_dir_file_count_cmd(dir_sort_index);
  //  cur_page_start_index = 0;
    if (ui_LabelRootDirScreenSubDir)
    {
        if ( parent_disk_type_is_udisk )
        {
            lv_label_set_text(ui_LabelRootDirScreenSubDir, DiskU[language_index]);
        }
        else
        {
            lv_label_set_text(ui_LabelRootDirScreenSubDir, Local[language_index]);
        }
    }
    SubDShowGcodeInfo(parent_disk_type_is_udisk);

}

void sub_dir_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_LabelRootDirScreenSubDir )
    {
        if (parent_disk_type_is_udisk)
            lv_label_set_text(ui_LabelRootDirScreenSubDir, DiskU[language_index]);
        else
            lv_label_set_text(ui_LabelRootDirScreenSubDir, Local[language_index]);
    }

    if ( ui_LabelNoContentsPromptScreenSubD )
        lv_label_set_text(ui_LabelNoContentsPromptScreenSubD, NoContentsMsg[language_index]);

    // if ( ui_LabelCopyUsbFiles )
    // {
    //     // char buff[30] = {0};
    //     // sprintf(buff, "%s%s", CopyTo[language_index], Local[language_index]);
    //     lv_label_set_text(ui_LabelCopyUsbFiles, CopyToLocal[language_index]);
    // }

    // if ( ui_LabelDelUsbFiles )
    //     lv_label_set_text(ui_LabelDelUsbFiles, Delete[language_index]);

}

static lv_timer_t * ui_SubDFileListWaittimer;
static void wait_timerout_handle(lv_timer_t * timer)
{
    
    GetSubDGcodeFileNum(parent_disk_type_is_udisk, parent_disk_part_index);
    LoadSubDirScreen();
    SubDShowGcodeInfo(parent_disk_type_is_udisk);
    FileManageSubDPageChangeObjs(1);
    wait_animmotion(false);
//     if (ui_SubDFileListWaittimer)
//         lv_timer_del(ui_SubDFileListWaittimer);
}

void RefreshSubDShowGcodeInfo(uint8_t wait_time)
{
   
    ui_SubDFileListWaittimer = lv_timer_create(wait_timerout_handle, 200*wait_time, NULL);
    lv_timer_set_repeat_count(ui_SubDFileListWaittimer, 1);
}


/**
 * @description: 文件操作编码器事件组
 * @return {*}
 */
static void SubDFileActionPageAddFocusObjs(void)
{
    lv_group_remove_all_objs(encoder_group);
    for (int i = 0; i < 3; i++)
    {
        lv_group_add_obj(encoder_group, SubDFileActionMessage.btn[i].btn);
    } 
}

static void FileManageSubDPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    // lv_indev_set_group(enc_indev, NULL); 
    // lv_indev_set_group(enc_indev, encoder_group); //关联组
    PageNode *fileManageSubD_node = find_page(ui_ScreenSubDir);
    fileManageSubD_node->nav_level = index;

    switch (index)
    {
    case 1: //1级事件组
        lv_group_add_obj(encoder_group, ui_SubDirBackBtn);
        if (SubDGcodeFileNum > 0 )
        {
             for(int i = 0;i < SubDGcodeFileNum; i++)
            {
                lv_group_add_obj(encoder_group, GfilepanelSubD[i]->part_panel);
            }
            //lv_group_focus_obj(GfilepanelSubD[0]->part_panel);
        }
        break;
    case 2: //2级事件组
        if (SubDAdd3rLeveldObjsCb)
        {
            SubDAdd3rLeveldObjsCb();
        }
    default:
    
        break;
    }

}