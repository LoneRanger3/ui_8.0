#include "ui_screen_FileManage.h"
#include "ui_screen_PrintHistory.h"
#include "ui_screen_SubDir.h"
#include "ui_screen_Preview.h"
#include "ui_helpers.h"
#include "ui_custom_dirent_info_part.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_HomePrinting.h"
#include "ui_Screen_Settings.h"
#include <stdio.h>
#include <time.h>
#include "../custom/lvgl_cmd.h"
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"
#include "ui_screen_Adjustment.h"
#include "ui_screen_AxisMove.h"
#include "ui_Screen_CustomerService.h"
#include "mult_language.h"
#include "ui_Screen_Settings.h"

static lv_obj_t * ui_ScreenFileManage;
/**********file manage page left panel*******************/
static lv_obj_t * ui_PanelPageScreenFile;
static lv_obj_t * ui_ButtonHomeScreenFile;
static lv_obj_t * ui_ButtonAxisMoveScreenFile;
static lv_obj_t * ui_ImageFileManage;
static lv_obj_t * ui_ButtonSettingsScreenFile;
static lv_obj_t * ui_ButtonReserveScreenFile;

/**********file manage page right panel*******************/
static dirent_info_part_t *part_array[8] = {NULL};
static lv_obj_t * ui_PanelFileOpt;
/**********file manage page right panel title*******************/
static lv_obj_t * ui_ImgLocalLeft;
static lv_obj_t * ui_ImgLocalRight;
static lv_obj_t * ui_ButtonLocalFile;
static lv_obj_t * ui_LabelLocalScreenFile;
static lv_obj_t * ui_ImgUsbLeft;
static lv_obj_t * ui_ImgUsbRight;
static lv_obj_t * ui_ButtonUsbFile;
static lv_obj_t * ui_LabelUDiskScreenFile;
static lv_obj_t * ui_ImgHistoryLeft;
static lv_obj_t * ui_ImgHistoryRight;
static lv_obj_t * ui_ButtonPrintHistoryFile;
static lv_obj_t * ui_LabelPrintHistoryScreenFile;

/**********file manage page right panel file list*******************/
static lv_obj_t * ui_PanelCenter;
static lv_obj_t * ui_PanelFileList;
/**********file manage page right panel file info*******************/
static lv_obj_t * ui_LabelNoContentsPrompt;

/**********file manage page right panel change page*******************/
static lv_obj_t * ui_PanelPrevFilesPage;
static lv_obj_t * ui_ImageFilesPrevPage;
static lv_obj_t * ui_PanelNextFilesPage;
static lv_obj_t * ui_ImageFilesNextPage;
/**********file manage page right panel file action*******************/
static lv_obj_t * ui_PanelFileAction;
static lv_obj_t * ui_ButtonCopyFiles;
static lv_obj_t * ui_LabelCopyLocalFiles;
static lv_obj_t * ui_ButtonDelFiles;
static lv_obj_t * ui_LabelDelLocalFile;

static lv_obj_t * ui_FileSortIcon;
static lv_obj_t * ui_FileSortOperation;
static lv_obj_t * ui_FileSortOperationBg;
static lv_obj_t * ui_FileSortActionBg;
static lv_obj_t * ui_FileSortActionTitle;
static lv_obj_t * ui_FileSortBysize;
static lv_obj_t * ui_FileSortByTime;
static lv_obj_t * ui_FileSortByName;
static lv_obj_t * ui_SizeSortOrderIcon;
static lv_obj_t * ui_TimeSortOrderIcon;

/***************************custom variable*****************************************/
static bool show_checkbox_file = false;
static bool is_local_disk = true;   //
static Screen_Type_t manager_screen_type = SCREEN_FILE;
static int16_t file_count_of_root_dir = 0;
static int16_t page_start_index = 0;
static int16_t page_last_index = 0;
char sortmode = '2';
#define MAX_FILE_COUNT 8

/*-------------- screen event, can not modify---------------*/
static void ui_event_ButtonHomeScreenFile(lv_event_t * e);
static void ui_event_ButtonAxisMoveScreenFile(lv_event_t * e);
static void ui_event_ButtonSettingsScreenFile(lv_event_t * e);
static void ui_event_ButtonReserveScreenFile(lv_event_t * e);
static void ui_event_TitleChange(lv_event_t * e);
static void ui_event_PanelFileInfo(lv_event_t * e);
static void ui_event_CheckboxFile1(lv_event_t * e);
static void ui_event_PanelFileInfo2(lv_event_t * e);
static void ui_event_PanelPrevFilesPage(lv_event_t * e);
static void ui_event_PanelNextFilesPage(lv_event_t * e);
static void ui_event_ButtonCopyFiles(lv_event_t * e);
static void ui_event_ButtonDelFiles(lv_event_t * e);
static void ui_event_FileSortHandle(lv_event_t * e);
static void ui_event_ShowSortHandle(lv_event_t * e);

/*-------------- screen event call back---------------*/
static void FilePageHomeBtnClicked(lv_event_t * e);
static void FilePageAxisBtnClicked(lv_event_t * e);
static void FilePageSettingsBtnClicked(lv_event_t * e);
static void FilePageReserveBtnClicked(lv_event_t * e);
static void FilePageLocalFileBtnClicked(lv_event_t * e);
static void FilePageUsbFileBtnClicked(lv_event_t * e);
static void FilePagePrintHistBtnClicked(lv_event_t * e);
static void FilePageFileInfoPanelClicked(lv_event_t * e);
static void FilePageFileInfoPanelLongPressed(lv_event_t * e);
static void FilePagePrevPageBtnClicked(lv_event_t * e);
static void FilePageNextPageBtnClicked(lv_event_t * e);
static void FilePageCopyFilesBtnClicked(lv_event_t * e);
static void FilePageDelFilesBtnClicked(lv_event_t * e);


/******************custom funs***********************/
static void show_checkboxes(bool show);
void show_file_action(bool show, bool is_local);
static void set_root_dir_files_count(int count);  
static void set_root_dir_file_infos(Dirent_Info_t dirent_array[8], int real_count);
static void switch_selected_disk_btn_backgroud_color(bool is_local);

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif


///////////////////// FUNCTIONS ////////////////////
void ui_event_ScreenFileManage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        show_file_action(false, is_local_disk);
        show_checkboxes(false);
        show_checkbox_file = false;
        //通知标题栏同步样式
        if(is_local_disk)
        {
            lv_event_send(ui_ButtonLocalFile, LV_EVENT_CLICKED, "1");
        }
        else
        {
            lv_event_send(ui_ButtonUsbFile, LV_EVENT_CLICKED, "2");
        }
    }
    if(event_code == LV_EVENT_CLICKED)
    {
        if(show_checkbox_file)
        {
            show_file_action(false, is_local_disk);
            show_checkboxes(false);
            show_checkbox_file = false;
        }
    }
}

void ui_event_FileSortHandle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        if(target == ui_FileSortOperation)//点到空白处
        {
            CrLogI("close the file sort page");
            lv_obj_add_flag(ui_FileSortOperation, LV_OBJ_FLAG_HIDDEN);     /// Flags
            return;
        }
        CrLogI("Change the file sort option");
        char tempsortmode = '0';
        char buff[100] = {0};
        switch (userdata[0])
        {
            case '0': tempsortmode = '0';lv_obj_clear_state(ui_FileSortBysize, LV_STATE_CHECKED);lv_obj_clear_state(ui_FileSortByTime, LV_STATE_CHECKED);break;
            case '1': tempsortmode = '1';lv_obj_clear_state(ui_FileSortByName, LV_STATE_CHECKED);lv_obj_clear_state(ui_FileSortByTime, LV_STATE_CHECKED);break;
            case '2': tempsortmode = '2';lv_obj_clear_state(ui_FileSortBysize, LV_STATE_CHECKED);lv_obj_clear_state(ui_FileSortByName, LV_STATE_CHECKED);break;
            case '3': tempsortmode = '5';break;
            case '4': tempsortmode = '4';break;
            default:  tempsortmode = '0';lv_obj_clear_state(ui_FileSortBysize, LV_STATE_CHECKED);lv_obj_clear_state(ui_FileSortByTime, LV_STATE_CHECKED);break;
        }

        wifi_wait_animmotion(true);
        if( tempsortmode == '0' || tempsortmode == '1' || tempsortmode == '2')//按当前模式排序，顺序默认
        {
            sortmode = tempsortmode;
            snprintf(buff, 100, "10\t%c\t%c", is_local_disk ? 'A' : 'B', sortmode);
        }
        else//当前模式顺序取反
        {
            if(tempsortmode == '4')//大小排序取反
            {
                if(sortmode == '1')
                    sortmode = '4';
                else
                    sortmode = '1';
            }
            else if(tempsortmode == '5')//时间排序取反
            {
                if(sortmode == '5')
                    sortmode = '2';
                else
                    sortmode = '5';
            }
            snprintf(buff, 100, "10\t%c\t%c", is_local_disk ? 'A' : 'B', sortmode);
        }
        send_lvgl_cmd(CMD_GET_PRINT_FILE_INFO, buff, strlen(buff) + 1, false);

        //把三个选项都置为空，排序都置为灰色再退出
        lv_obj_clear_state(ui_FileSortBysize, LV_STATE_CHECKED);
        lv_obj_clear_state(ui_FileSortByName, LV_STATE_CHECKED);
        lv_obj_clear_state(ui_FileSortByTime, LV_STATE_CHECKED);
        char tempbuff[256] = {0};
        snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "SortDownUnSelect.png");
        lv_img_set_src(ui_SizeSortOrderIcon, tempbuff);
        lv_img_set_src(ui_TimeSortOrderIcon, tempbuff);
        lv_obj_add_flag(ui_FileSortOperation, LV_OBJ_FLAG_HIDDEN);     /// Flags
    }
}

void ui_event_ShowSortHandle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        CrLogI("open the filesort page");
        char tempbuff[256] = {0};
        snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "SortDownUnSelect.png");

        switch (sortmode)
        {
            case '0': lv_obj_add_state(ui_FileSortByName, LV_STATE_CHECKED);break;
            case '1': 
            {
                lv_obj_add_state(ui_FileSortBysize, LV_STATE_CHECKED);
                snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "SortDownSelect.png");
                lv_img_set_src(ui_SizeSortOrderIcon, tempbuff);
                break;
            }
            case '2':
            {
                lv_obj_add_state(ui_FileSortByTime, LV_STATE_CHECKED);
                snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "SortDownSelect.png");
                lv_img_set_src(ui_TimeSortOrderIcon, tempbuff);
                break;
            }
            case '4':
            {
                lv_obj_add_state(ui_FileSortBysize, LV_STATE_CHECKED);
                snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "SortUpSelect.png");
                lv_img_set_src(ui_SizeSortOrderIcon, tempbuff);
                break;
            }
            case '5':
            {
                lv_obj_add_state(ui_FileSortByTime, LV_STATE_CHECKED);
                snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "SortUpSelect.png");
                lv_img_set_src(ui_TimeSortOrderIcon, tempbuff);
                break;
            }
            default:CrLogI("sortmode is illegal:%c",sortmode);
        }
        lv_obj_clear_flag(ui_FileSortOperation, LV_OBJ_FLAG_HIDDEN);     /// Flags
    }
}

void ui_event_ButtonHomeScreenFile(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        FilePageHomeBtnClicked(e);
    }
}
void ui_event_ButtonAxisMoveScreenFile(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        FilePageAxisBtnClicked(e);
    }
}
void ui_event_ButtonSettingsScreenFile(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        FilePageSettingsBtnClicked(e);
    }
}
void ui_event_ButtonReserveScreenFile(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        FilePageReserveBtnClicked(e);
    }
}
void ui_event_TitleChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(strcmp(userdata, "1") == 0)
        {
            FilePageLocalFileBtnClicked(e);
            lv_obj_set_style_img_opa(ui_ImgLocalLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgLocalRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgUsbLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgUsbRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgHistoryLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgHistoryRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(strcmp(userdata, "2") == 0)
        {
            FilePageUsbFileBtnClicked(e);
            lv_obj_set_style_img_opa(ui_ImgLocalLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgLocalRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgUsbLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgUsbRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgHistoryLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgHistoryRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else
        {
            FilePagePrintHistBtnClicked(e);
            lv_obj_set_style_img_opa(ui_ImgLocalLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgLocalRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgUsbLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgUsbRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgHistoryLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgHistoryRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}
void ui_event_PanelFileInfo(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    //if(event_code == LV_EVENT_CLICKED) {
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        FilePageFileInfoPanelClicked(e);
    }
    if(event_code == LV_EVENT_LONG_PRESSED) {
        FilePageFileInfoPanelLongPressed(e);
    }
}
void ui_event_PanelPrevFilesPage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        FilePagePrevPageBtnClicked(e);
    }
}
void ui_event_PanelNextFilesPage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        FilePageNextPageBtnClicked(e);
    }
}
void ui_event_ButtonCopyFiles(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        FilePageCopyFilesBtnClicked(e);
    }
}
void ui_event_ButtonDelFiles(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        FilePageDelFilesBtnClicked(e);
    }
}


void ui_ScreenFileManage_screen_init(void)
{
    ui_ScreenFileManage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenFileManage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    ui_PanelPageScreenFile = lv_obj_create(ui_ScreenFileManage);
    lv_obj_set_width(ui_PanelPageScreenFile, 80);
    lv_obj_set_height(ui_PanelPageScreenFile, 480);
    lv_obj_clear_flag(ui_PanelPageScreenFile, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPageScreenFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPageScreenFile, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonHomeScreenFile = lv_btn_create(ui_PanelPageScreenFile);
    lv_obj_set_width(ui_ButtonHomeScreenFile, 80);
    lv_obj_set_height(ui_ButtonHomeScreenFile, 96);
    lv_obj_set_x(ui_ButtonHomeScreenFile, -22);
    lv_obj_set_y(ui_ButtonHomeScreenFile, -22);
    lv_obj_add_flag(ui_ButtonHomeScreenFile, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenFile, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenFile, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonHomeScreenFile, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenFile, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenFile, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonAxisMoveScreenFile = lv_btn_create(ui_PanelPageScreenFile);
    lv_obj_set_width(ui_ButtonAxisMoveScreenFile, 80);
    lv_obj_set_height(ui_ButtonAxisMoveScreenFile, 96);
    lv_obj_set_x(ui_ButtonAxisMoveScreenFile, -22);
    lv_obj_set_y(ui_ButtonAxisMoveScreenFile, 74);
    lv_obj_add_flag(ui_ButtonAxisMoveScreenFile, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveScreenFile, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveScreenFile, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMoveScreenFile, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveScreenFile, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveScreenFile, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageFileManage = lv_img_create(ui_PanelPageScreenFile);
    lv_img_set_src(ui_ImageFileManage, &ui_img_pagefilemanageselected_png);
    lv_obj_set_width(ui_ImageFileManage, 80);
    lv_obj_set_height(ui_ImageFileManage, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_ImageFileManage, -22);
    lv_obj_set_y(ui_ImageFileManage, 170);
    lv_obj_add_flag(ui_ImageFileManage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFileManage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonSettingsScreenFile = lv_btn_create(ui_PanelPageScreenFile);
    lv_obj_set_width(ui_ButtonSettingsScreenFile, 80);
    lv_obj_set_height(ui_ButtonSettingsScreenFile, 96);
    lv_obj_set_x(ui_ButtonSettingsScreenFile, -22);
    lv_obj_set_y(ui_ButtonSettingsScreenFile, 266);
    lv_obj_add_flag(ui_ButtonSettingsScreenFile, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenFile, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenFile, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenFile, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenFile, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenFile, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonReserveScreenFile = lv_btn_create(ui_PanelPageScreenFile);
    lv_obj_set_width(ui_ButtonReserveScreenFile, 80);
    lv_obj_set_height(ui_ButtonReserveScreenFile, 96);
    lv_obj_set_x(ui_ButtonReserveScreenFile, -22);
    lv_obj_set_y(ui_ButtonReserveScreenFile, 362);
    lv_obj_add_flag(ui_ButtonReserveScreenFile, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveScreenFile, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenFile, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveScreenFile, lv_color_hex(0x4190A5),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonReserveScreenFile, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonReserveScreenFile, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_PanelFileOpt = lv_obj_create(ui_ScreenFileManage);
    lv_obj_set_width(ui_PanelFileOpt, 720);
    lv_obj_set_height(ui_PanelFileOpt, 50);
    lv_obj_set_x(ui_PanelFileOpt, 80);
    lv_obj_set_y(ui_PanelFileOpt, 0);
    lv_obj_clear_flag(ui_PanelFileOpt, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFileOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFileOpt, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFileOpt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFileOpt, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_PanelFileOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelFileOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelFileOpt, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_style_pad_all(ui_PanelFileOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_PanelFileOpt, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelFileOpt, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_END);
    lv_obj_set_style_pad_column(ui_PanelFileOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImgLocalLeft = lv_img_create(ui_PanelFileOpt);
    char tempbuffb[256] = {0};
    snprintf(tempbuffb, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TilteLeftstyle.png");
    lv_img_set_src(ui_ImgLocalLeft, tempbuffb);
    lv_obj_set_width(ui_ImgLocalLeft, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgLocalLeft, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ImgLocalLeft, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgLocalLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonLocalFile = lv_btn_create(ui_PanelFileOpt);
    lv_obj_set_width(ui_ButtonLocalFile, 161);
    lv_obj_set_height(ui_ButtonLocalFile, 46);
    lv_obj_set_style_radius(ui_ButtonLocalFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonLocalFile, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonLocalFile, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonLocalFile, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonLocalFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ButtonLocalFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ButtonLocalFile, LV_OBJ_FLAG_EVENT_BUBBLE);

    ui_LabelLocalScreenFile = lv_label_create(ui_ButtonLocalFile);
    lv_obj_set_width(ui_LabelLocalScreenFile, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelLocalScreenFile, 35);
    lv_obj_align(ui_LabelLocalScreenFile, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_long_mode(ui_LabelLocalScreenFile, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelLocalScreenFile, Local[language_index]);

    ui_ImgLocalRight = lv_img_create(ui_PanelFileOpt);
    char tempbuffa[256] = {0};
    snprintf(tempbuffa, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TitleRightstyle.png");
    lv_img_set_src(ui_ImgLocalRight, tempbuffa);
    lv_obj_set_width(ui_ImgLocalRight, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgLocalRight, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ImgLocalRight, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgLocalRight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImgUsbLeft = lv_img_create(ui_PanelFileOpt);
    memset(tempbuffb, 0, 256);
    snprintf(tempbuffb, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TilteLeftstyle.png");
    lv_img_set_src(ui_ImgUsbLeft, tempbuffb);
    lv_obj_set_width(ui_ImgUsbLeft, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgUsbLeft, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ImgUsbLeft, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgUsbLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonUsbFile = lv_btn_create(ui_PanelFileOpt);
    lv_obj_set_width(ui_ButtonUsbFile, 161);
    lv_obj_set_height(ui_ButtonUsbFile, 46);
    lv_obj_set_style_radius(ui_ButtonUsbFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonUsbFile, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonUsbFile, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonUsbFile, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonUsbFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ButtonUsbFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ButtonUsbFile, LV_OBJ_FLAG_EVENT_BUBBLE);

    ui_LabelUDiskScreenFile = lv_label_create(ui_ButtonUsbFile);
    lv_obj_set_width(ui_LabelUDiskScreenFile, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelUDiskScreenFile, 35);
    lv_obj_align(ui_LabelUDiskScreenFile, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_long_mode(ui_LabelUDiskScreenFile, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelUDiskScreenFile, DiskU[language_index]);

    ui_ImgUsbRight = lv_img_create(ui_PanelFileOpt);
    memset(tempbuffa, 0, 256);
    snprintf(tempbuffa, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TitleRightstyle.png");
    lv_img_set_src(ui_ImgUsbRight, tempbuffa);
    lv_obj_set_width(ui_ImgUsbRight, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgUsbRight, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ImgUsbRight, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgUsbRight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImgHistoryLeft = lv_img_create(ui_PanelFileOpt);
    memset(tempbuffb, 0, 256);
    snprintf(tempbuffb, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TilteLeftstyle.png");
    lv_img_set_src(ui_ImgHistoryLeft, tempbuffb);
    lv_obj_set_width(ui_ImgHistoryLeft, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgHistoryLeft, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ImgHistoryLeft, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgHistoryLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonPrintHistoryFile = lv_btn_create(ui_PanelFileOpt);
    lv_obj_set_width(ui_ButtonPrintHistoryFile, 161);
    lv_obj_set_height(ui_ButtonPrintHistoryFile, 46);
    lv_obj_set_style_radius(ui_ButtonPrintHistoryFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonPrintHistoryFile, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonPrintHistoryFile, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonPrintHistoryFile, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonPrintHistoryFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ButtonPrintHistoryFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelPrintHistoryScreenFile = lv_label_create(ui_ButtonPrintHistoryFile);
    lv_obj_set_width(ui_LabelPrintHistoryScreenFile, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelPrintHistoryScreenFile, 35);
    lv_obj_align(ui_LabelPrintHistoryScreenFile, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LabelPrintHistoryScreenFile, History[language_index]);

    ui_ImgHistoryRight = lv_img_create(ui_PanelFileOpt);
    memset(tempbuffa, 0, 256);
    snprintf(tempbuffa, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TitleRightstyle.png");
    lv_img_set_src(ui_ImgHistoryRight, tempbuffa);
    lv_obj_set_width(ui_ImgHistoryRight, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgHistoryRight, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ImgHistoryRight, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgHistoryRight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //标题栏显示效果初始化
    lv_obj_set_style_img_opa(ui_ImgLocalLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui_ImgLocalRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui_ImgUsbLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui_ImgUsbRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui_ImgHistoryLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui_ImgHistoryRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelCenter = lv_obj_create(ui_ScreenFileManage);
    lv_obj_set_width(ui_PanelCenter, 720);
    lv_obj_set_height(ui_PanelCenter, 430);
    lv_obj_set_x(ui_PanelCenter, 80);
    lv_obj_set_y(ui_PanelCenter, 50);
    lv_obj_clear_flag(ui_PanelCenter, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCenter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCenter, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCenter, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCenter, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelCenter, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_style_pad_all(ui_PanelCenter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelFileList = lv_obj_create(ui_PanelCenter);
    lv_obj_set_width(ui_PanelFileList, 696);
    lv_obj_set_height(ui_PanelFileList, 406);
    lv_obj_align(ui_PanelFileList, LV_ALIGN_CENTER, 0, 0);
    lv_obj_clear_flag(ui_PanelFileList, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelFileList, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFileList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFileList, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelFileList, LV_OBJ_FLAG_EVENT_BUBBLE);

    int8_t index = 0;
    part_array[index++] = create_custom_dirent_info_part(ui_PanelFileList, -8, -13, &ui_event_PanelFileInfo);
    part_array[index++] = create_custom_dirent_info_part(ui_PanelFileList, 162, -13, &ui_event_PanelFileInfo);
    part_array[index++] = create_custom_dirent_info_part(ui_PanelFileList, 332, -13, &ui_event_PanelFileInfo);
    part_array[index++] = create_custom_dirent_info_part(ui_PanelFileList, 503, -13, &ui_event_PanelFileInfo);
    part_array[index++] = create_custom_dirent_info_part(ui_PanelFileList, -8, 186, &ui_event_PanelFileInfo);
    part_array[index++] = create_custom_dirent_info_part(ui_PanelFileList, 162, 186, &ui_event_PanelFileInfo);
    part_array[index++] = create_custom_dirent_info_part(ui_PanelFileList, 332, 186, &ui_event_PanelFileInfo);
    part_array[index++] = create_custom_dirent_info_part(ui_PanelFileList, 503, 186, &ui_event_PanelFileInfo);
    
    ui_LabelNoContentsPrompt = lv_label_create(ui_PanelFileList);
    lv_obj_set_width(ui_LabelNoContentsPrompt, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelNoContentsPrompt, 36);
    lv_obj_set_x(ui_LabelNoContentsPrompt, 251);
    lv_obj_set_y(ui_LabelNoContentsPrompt, 155);
    lv_label_set_text(ui_LabelNoContentsPrompt, NoContentsMsg[language_index]);
    lv_obj_add_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_LabelNoContentsPrompt, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelNoContentsPrompt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelNoContentsPrompt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelNoContentsPrompt, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LabelNoContentsPrompt, LV_LABEL_LONG_SCROLL_CIRCULAR);

    ui_PanelPrevFilesPage = lv_obj_create(ui_PanelCenter);
    lv_obj_set_width(ui_PanelPrevFilesPage, 70);
    lv_obj_set_height(ui_PanelPrevFilesPage, 70);
    lv_obj_align(ui_PanelPrevFilesPage, LV_ALIGN_TOP_LEFT, 645, 270);
    lv_obj_clear_flag(ui_PanelPrevFilesPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPrevFilesPage, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPrevFilesPage, lv_color_hex(0x232527), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrevFilesPage, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPrevFilesPage, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelPrevFilesPage, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelPrevFilesPage, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelPrevFilesPage, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelPrevFilesPage, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_img_src(ui_PanelPrevFilesPage, &ui_img_newprev_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelPrevFilesPage, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_style_bg_img_opa(ui_PanelPrevFilesPage, 190, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelNextFilesPage = lv_obj_create(ui_PanelCenter);
    lv_obj_set_width(ui_PanelNextFilesPage, 70);
    lv_obj_set_height(ui_PanelNextFilesPage, 70);
    lv_obj_align(ui_PanelNextFilesPage, LV_ALIGN_BOTTOM_LEFT, 645, -6);
    lv_obj_clear_flag(ui_PanelNextFilesPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelNextFilesPage, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelNextFilesPage, lv_color_hex(0x232527), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelNextFilesPage, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelNextFilesPage, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelNextFilesPage, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelNextFilesPage, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelNextFilesPage, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_PanelNextFilesPage, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_img_src(ui_PanelNextFilesPage, &ui_img_newnext_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelNextFilesPage, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_style_bg_img_opa(ui_PanelNextFilesPage, 190, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelFileAction = lv_obj_create(ui_PanelCenter);
    lv_obj_set_width(ui_PanelFileAction, 130);
    lv_obj_set_height(ui_PanelFileAction, 140);
    lv_obj_align(ui_PanelFileAction, LV_ALIGN_TOP_RIGHT, -15, 60);
    lv_obj_add_flag(ui_PanelFileAction, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_PanelFileAction, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFileAction, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFileAction, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFileAction, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFileAction, 240, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonCopyFiles = lv_btn_create(ui_PanelFileAction);
    lv_obj_set_width(ui_ButtonCopyFiles, 130);
    lv_obj_set_height(ui_ButtonCopyFiles, 70);
    lv_obj_set_x(ui_ButtonCopyFiles, -22);
    lv_obj_set_y(ui_ButtonCopyFiles, -22);
    lv_obj_add_flag(ui_ButtonCopyFiles, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonCopyFiles, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonCopyFiles, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonCopyFiles, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonCopyFiles, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonCopyFiles, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonCopyFiles, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonCopyFiles, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_ButtonCopyFiles, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCopyLocalFiles = lv_label_create(ui_ButtonCopyFiles);
    lv_obj_set_width(ui_LabelCopyLocalFiles, 124);
    lv_obj_set_height(ui_LabelCopyLocalFiles, 30);
    lv_obj_align(ui_LabelCopyLocalFiles, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_long_mode(ui_LabelCopyLocalFiles, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelCopyLocalFiles, CopyToUSB[language_index]);
    lv_obj_set_style_text_color(ui_LabelCopyLocalFiles, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCopyLocalFiles, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelCopyLocalFiles, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCopyLocalFiles, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonDelFiles = lv_btn_create(ui_PanelFileAction);
    lv_obj_set_width(ui_ButtonDelFiles, 130);
    lv_obj_set_height(ui_ButtonDelFiles, 70);
    lv_obj_set_x(ui_ButtonDelFiles, -22);
    lv_obj_set_y(ui_ButtonDelFiles, 48);
    lv_obj_add_flag(ui_ButtonDelFiles, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonDelFiles, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonDelFiles, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonDelFiles, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonDelFiles, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_ButtonDelFiles, lv_color_hex(0x4190A2), LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_ButtonDelFiles, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_ButtonDelFiles, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonDelFiles, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonDelFiles, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_ButtonDelFiles, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelDelLocalFile = lv_label_create(ui_ButtonDelFiles);
    lv_obj_set_width(ui_LabelDelLocalFile, 124);
    lv_obj_set_height(ui_LabelDelLocalFile, 30);
    lv_obj_align(ui_LabelDelLocalFile, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_long_mode(ui_LabelDelLocalFile, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelDelLocalFile, Delete[language_index]);
    lv_obj_set_style_text_color(ui_LabelDelLocalFile, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelDelLocalFile, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelDelLocalFile, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelDelLocalFile, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FileSortIcon = lv_img_create(ui_PanelCenter);
    lv_obj_set_width(ui_FileSortIcon, 68);
    lv_obj_set_height(ui_FileSortIcon, 68);
    lv_obj_align(ui_FileSortIcon, LV_ALIGN_TOP_LEFT, 645, 108);
    lv_obj_add_flag(ui_FileSortIcon, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    char tempbuff[256] = {0};
    snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "SortIcon.png");
    lv_img_set_src(ui_FileSortIcon, tempbuff);

    ui_FileSortOperation = lv_obj_create(ui_ScreenFileManage);
    lv_obj_set_width(ui_FileSortOperation, 800);
    lv_obj_set_height(ui_FileSortOperation, 480);
    lv_obj_align(ui_FileSortOperation, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(ui_FileSortOperation, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_add_flag(ui_FileSortOperation, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_set_style_radius(ui_FileSortOperation, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FileSortOperation, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_FileSortOperation, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FileSortOperation, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FileSortOperationBg = lv_obj_create(ui_FileSortOperation);
    lv_obj_set_width(ui_FileSortOperationBg, 462);
    lv_obj_set_height(ui_FileSortOperationBg, 480);
    lv_obj_align(ui_FileSortOperationBg, LV_ALIGN_TOP_LEFT, 338, 0);
    lv_obj_set_style_radius(ui_FileSortOperationBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FileSortOperationBg, 204, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FileSortOperationBg, lv_color_hex(0x050505), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_FileSortOperationBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FileSortOperationBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FileSortActionBg = lv_obj_create(ui_FileSortOperationBg);
    lv_obj_set_width(ui_FileSortActionBg, 370);
    lv_obj_set_height(ui_FileSortActionBg, 430);
    lv_obj_align(ui_FileSortActionBg, LV_ALIGN_TOP_LEFT, 52, 25);
    lv_obj_set_style_radius(ui_FileSortActionBg, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FileSortActionBg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FileSortActionBg, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_FileSortActionBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FileSortActionBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FileSortActionTitle = lv_label_create(ui_FileSortActionBg);
    lv_obj_set_width(ui_FileSortActionTitle, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FileSortActionTitle, 35);
    lv_label_set_text(ui_FileSortActionTitle, Screening[language_index]);
    lv_obj_align(ui_FileSortActionTitle, LV_ALIGN_TOP_MID, 0, 19);
    lv_obj_set_style_text_color(ui_FileSortActionTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FileSortActionTitle, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FileSortBysize = lv_checkbox_create(ui_FileSortActionBg);
    lv_checkbox_set_text(ui_FileSortBysize, "按大小排序");
    lv_obj_set_width(ui_FileSortBysize, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FileSortBysize, LV_SIZE_CONTENT);
    lv_obj_align(ui_FileSortBysize, LV_ALIGN_TOP_LEFT, 48, 84);
    lv_obj_set_style_text_color(ui_FileSortBysize, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FileSortBysize, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FileSortBysize, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FileSortBysize, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_FileSortBysize, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_FileSortBysize, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_FileSortBysize, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_FileSortBysize, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_FileSortBysize, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_FileSortBysize, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FileSortBysize, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FileSortBysize, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FileSortBysize, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_FileSortBysize, LV_RADIUS_CIRCLE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_FileSortBysize, 20);

    ui_SizeSortOrderIcon = lv_img_create(ui_FileSortActionBg);
    lv_obj_set_width(ui_SizeSortOrderIcon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SizeSortOrderIcon, LV_SIZE_CONTENT);
    lv_obj_align(ui_SizeSortOrderIcon, LV_ALIGN_TOP_LEFT, 241, 84);
    lv_obj_add_flag(ui_SizeSortOrderIcon, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    char tempbuff1[256] = {0};
    snprintf(tempbuff1, 256, "S:%s/%s", GetK1ImageResourcePtah(), "SortSelect.png");
    lv_img_set_src(ui_SizeSortOrderIcon, tempbuff1);

    ui_FileSortByTime = lv_checkbox_create(ui_FileSortActionBg);
    lv_checkbox_set_text(ui_FileSortByTime, "按时间排序");
    lv_obj_set_width(ui_FileSortByTime, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FileSortByTime, LV_SIZE_CONTENT);
    lv_obj_align(ui_FileSortByTime, LV_ALIGN_TOP_LEFT, 48, 223);
    lv_obj_set_style_text_color(ui_FileSortByTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FileSortByTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FileSortByTime, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FileSortByTime, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_FileSortByTime, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_FileSortByTime, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_FileSortByTime, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_FileSortByTime, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_FileSortByTime, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_FileSortByTime, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FileSortByTime, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FileSortByTime, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FileSortByTime, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_FileSortByTime, LV_RADIUS_CIRCLE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_FileSortByTime, 20);

    ui_TimeSortOrderIcon = lv_img_create(ui_FileSortActionBg);
    lv_obj_set_width(ui_TimeSortOrderIcon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TimeSortOrderIcon, LV_SIZE_CONTENT);
    lv_obj_align(ui_TimeSortOrderIcon, LV_ALIGN_TOP_LEFT, 241, 84);
    lv_obj_add_flag(ui_TimeSortOrderIcon, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    char tempbuff2[256] = {0};
    snprintf(tempbuff2, 256, "S:%s/%s", GetK1ImageResourcePtah(), "SortSelect.png");
    lv_img_set_src(ui_TimeSortOrderIcon, tempbuff2);

    ui_FileSortByName = lv_checkbox_create(ui_FileSortActionBg);
    lv_checkbox_set_text(ui_FileSortByName, "按名称排序(A~Z)");
    lv_obj_set_width(ui_FileSortByName, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FileSortByName, LV_SIZE_CONTENT);
    lv_obj_align(ui_FileSortByName, LV_ALIGN_TOP_LEFT, 48, 351);
    lv_obj_set_style_text_color(ui_FileSortByName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FileSortByName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FileSortByName, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FileSortByName, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_FileSortByName, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_FileSortByName, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_FileSortByName, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_FileSortByName, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_FileSortByName, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_FileSortByName, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FileSortByName, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FileSortByName, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FileSortByName, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_FileSortByName, LV_RADIUS_CIRCLE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_FileSortByName, 20);

    lv_obj_add_event_cb(ui_ButtonHomeScreenFile, ui_event_ButtonHomeScreenFile, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMoveScreenFile, ui_event_ButtonAxisMoveScreenFile, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsScreenFile, ui_event_ButtonSettingsScreenFile, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserveScreenFile, ui_event_ButtonReserveScreenFile, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonLocalFile, ui_event_TitleChange, LV_EVENT_ALL, "1");
    lv_obj_add_event_cb(ui_ButtonUsbFile, ui_event_TitleChange, LV_EVENT_ALL, "2");
    lv_obj_add_event_cb(ui_ButtonPrintHistoryFile, ui_event_TitleChange, LV_EVENT_ALL, "3");
    lv_obj_add_event_cb(ui_PanelPrevFilesPage, ui_event_PanelPrevFilesPage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelNextFilesPage, ui_event_PanelNextFilesPage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonCopyFiles, ui_event_ButtonCopyFiles, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonDelFiles, ui_event_ButtonDelFiles, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenFileManage, ui_event_ScreenFileManage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FileSortByName, ui_event_FileSortHandle, LV_EVENT_ALL, "0");
    lv_obj_add_event_cb(ui_FileSortBysize, ui_event_FileSortHandle, LV_EVENT_ALL, "1");
    lv_obj_add_event_cb(ui_FileSortByTime, ui_event_FileSortHandle, LV_EVENT_ALL, "2");
    lv_obj_add_event_cb(ui_TimeSortOrderIcon, ui_event_FileSortHandle, LV_EVENT_ALL, "3");
    lv_obj_add_event_cb(ui_SizeSortOrderIcon, ui_event_FileSortHandle, LV_EVENT_ALL, "4");
    lv_obj_add_event_cb(ui_FileSortOperation, ui_event_FileSortHandle, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FileSortIcon, ui_event_ShowSortHandle, LV_EVENT_ALL, NULL);

}

void LoadFileManageScreen(void)
{
    if ( manager_screen_type == SCREEN_SUBDIR )
    {
        LoadSubDirScreen();
    }
    else if ( manager_screen_type == SCREEN_HISTORY )
    {
        LoadPrintHistoryScreen();
    }
    else
    {
        lv_disp_load_scr(ui_ScreenFileManage);
    }
}


void FilePageHomeBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( home_printing_is_printing_finished() )
        LoadHomeNormalScreen();
    else
        LoadHomePrintingScreen();
}

void FilePageAxisBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( home_printing_is_printing_finished() )
        LoadAxisMoveScreen();
    else
        LoadAxisMoveScreen();
}

void FilePageSettingsBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadSettingsScreen();
}

void FilePageReserveBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadCustomerServiceScreen();
}

void switch_selected_disk_btn_backgroud_color(bool is_local)
{
    if ( ui_ButtonUsbFile )
    {
            lv_obj_set_style_bg_color(ui_ButtonUsbFile, is_local ? lv_color_hex(0x121212) : lv_color_hex(0x232426), 
                                        LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_ButtonUsbFile, is_local ? lv_color_hex(0x6A707D) : lv_color_hex(0xFFFFFF), 
                                        LV_PART_MAIN | LV_STATE_DEFAULT);
    }
            
    if (ui_ButtonLocalFile)
    {
        lv_obj_set_style_bg_color(ui_ButtonLocalFile, is_local ? lv_color_hex(0x232426) : lv_color_hex(0x121212), 
                                        LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_ButtonLocalFile, is_local ? lv_color_hex(0xFFFFFF) : lv_color_hex(0x6A707D), 
                                        LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

void FilePageLocalFileBtnClicked(lv_event_t * e)
{
	// Your code here
    file_manage_switch_screen(SCREEN_FILE);
    file_manage_switch_disk(true);
}

void FilePageUsbFileBtnClicked(lv_event_t * e)
{
	// Your code here
    file_manage_switch_screen(SCREEN_FILE);
    file_manage_switch_disk(false);
}

void FilePagePrintHistBtnClicked(lv_event_t * e)
{
	// Your code here
    file_manage_switch_screen(SCREEN_HISTORY);
    LoadPrintHistoryScreen();
}

void FilePageFileInfoPanelClicked(lv_event_t * e)
{
	// Your code here
    dirent_info_part_t *part = lv_event_get_user_data(e);
    if ( !part )
        return ;
    
    if ( part->is_dir )
    {
        LoadSubDirScreen();
        file_manage_switch_screen(SCREEN_SUBDIR);
        /***get sub dir filelist***/
        sub_dir_enter_screen_settings(part_get_dirent_info_name(part), part_dirent_index(part), is_local_disk ? true : false);
    }
    else
    {
        if( show_checkbox_file )
        {
            bool status = part_get_file_checkbox_checkedstate(part);
            part_set_file_checkbox_state(part, !status);
            return;
        }
        LoadPreviewScreen();
        preview_set_mode_file_from_dir_type(true);
        send_get_filling_chart_info_cmd(part_dirent_index(part));
        if ( part->label_dirent_name && part->label_totle_time && part->label_mater_used )
        {
            char *file_name = part_get_dirent_info_name(part);
            preview_set_file_info(file_name, part->totle_time, part->mater_used, part_dirent_index(part), part->filament_type, part->nozzle_temp, part->bed_temp, FROM_LOCAL);
        }
    }
}

void show_checkboxes(bool show)
{
    for ( int i = 0; i < 8; i++ )
    {
        if ( !part_array[i] || !(part_array[i]->checkbox_file) )
            continue;
        
        if ( part_array[i]->is_dir )
            continue;

        if ( show )
            lv_obj_clear_flag(part_array[i]->checkbox_file, LV_OBJ_FLAG_HIDDEN);
        else
        {
            lv_obj_add_flag(part_array[i]->checkbox_file, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_state(part_array[i]->checkbox_file, LV_STATE_CHECKED);
        }
    }

    return ;
}

void show_file_action(bool show, bool is_local)
{
	// Your code here
    uint8_t language_index = get_cur_language_index();
    if ( show )
        lv_obj_clear_flag(ui_PanelFileAction, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_PanelFileAction, LV_OBJ_FLAG_HIDDEN);
    
    // char buff[30] = {0};
    if ( ui_LabelCopyLocalFiles )
    {
        if( is_local )
            lv_label_set_text(ui_LabelCopyLocalFiles, CopyToUSB[language_index]);
        else
            lv_label_set_text(ui_LabelCopyLocalFiles, CopyToLocal[language_index]);
        redefine_label_size(ui_LabelCopyLocalFiles, lv_font24.font, 0, 0, 400, 0);
        
        lv_obj_update_layout(ui_ButtonCopyFiles);
        redefine_widgets_size(ui_ButtonCopyFiles, ui_LabelCopyLocalFiles, 10, 0, 130, 70);
    }
    if ( ui_LabelDelLocalFile )
    {
        lv_label_set_text(ui_LabelDelLocalFile, Delete[language_index]);
        redefine_label_size(ui_LabelDelLocalFile, lv_font24.font, 0, 0, 400, 0);
        
        lv_obj_update_layout(ui_ButtonDelFiles);
        redefine_widgets_size(ui_ButtonDelFiles, ui_LabelDelLocalFile, 10, 0, 130, 70);
    }
    lv_coord_t width  = lv_obj_get_width(ui_ButtonCopyFiles) > lv_obj_get_width(ui_ButtonDelFiles) ? lv_obj_get_width(ui_ButtonCopyFiles) : lv_obj_get_width(ui_ButtonDelFiles);
    lv_obj_set_width(ui_ButtonCopyFiles, width);
    lv_obj_set_width(ui_ButtonDelFiles, width);
    lv_obj_set_width(ui_PanelFileAction, width);
}

void FilePageFileInfoPanelLongPressed(lv_event_t * e)
{

    show_file_action(!show_checkbox_file, is_local_disk);
    show_checkboxes(!show_checkbox_file);
    show_checkbox_file = !show_checkbox_file;
}

void FilePagePrevPageBtnClicked(lv_event_t * e)
{
	// Your code here
    uint8_t language_index = get_cur_language_index();
    if ( file_count_of_root_dir == 0 )
    {
        create_custom_reminderbox(FileCountTipsMsg[language_index], false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return ;
    }

    if ( (page_start_index <= 1) )
    {
        create_custom_reminderbox(FirstPageMsg[language_index], false);
        set_custom_reminderbox_display_timeout(1, NULL);
    }
    else
    {
        page_start_index -= PAGE_MAX_DIRENT_COUNT;
        if ( page_start_index < 1 )
            page_start_index = 1;

        send_get_cur_dir_dirent_infos_cmd(page_start_index, PAGE_MAX_DIRENT_COUNT);
    }
}

void FilePageNextPageBtnClicked(lv_event_t * e)
{
	// Your code here
    uint8_t language_index = get_cur_language_index();
    if ( file_count_of_root_dir == 0 )
    {
        create_custom_reminderbox(FileCountTipsMsg[language_index], false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return ;
    }

    if ( page_start_index + PAGE_MAX_DIRENT_COUNT > file_count_of_root_dir )
    {
        create_custom_reminderbox(LastPageMsg[language_index], false);
        set_custom_reminderbox_display_timeout(1, NULL);
    }
    else
    {
        page_start_index += PAGE_MAX_DIRENT_COUNT;
        send_get_cur_dir_dirent_infos_cmd(page_start_index, PAGE_MAX_DIRENT_COUNT);
    }
}

void FilePageCopyFilesBtnClicked(lv_event_t * e)
{
	// Your code here
    //获取当前的索引序列号
    char sendbuff[100] = {"12"};
    bool send_flag = false;
    if(part_array[0]->is_local_disk)
        strcat(sendbuff, "\t1");    
    else
        strcat(sendbuff, "\t2");    
    for ( int i = 0; i < MAX_FILE_COUNT; i++ )
    {
        if ( part_get_file_checkbox_checkedstate(part_array[i]) && part_array[i]->dirent_index )
        {
            send_flag = true;
            CrLogI("copy file index:%d,%d",part_array[i]->dirent_index,part_array[i]->is_local_disk);
            char temp[10] = {0};
            snprintf(temp, 10, "\t%d", part_array[i]->dirent_index);
            strcat(&sendbuff[strlen(sendbuff)], temp);
            CrLogI("copy file:%s",sendbuff);
        }
    }
    if(send_flag)
    {
        if(system_state.Udisk_state)
        {
            set_printer_data(CONTROL_FILE, strlen(sendbuff), sendbuff);
        }
        else
        {
            create_msgbox(DiskUMsg[get_cur_language_index()], NULL, 1000, lv_scr_act());
        }
    }
    CrLogI("key is %d",show_checkbox_file);
    show_checkboxes(!show_checkbox_file);
    show_file_action(!show_checkbox_file, part_array[0]->is_local_disk);
    show_checkbox_file = !show_checkbox_file;
}

void FilePageDelFilesBtnClicked(lv_event_t * e)
{
	// Your code here
    //获取当前的索引序列号
    char sendbuff[100] = {"13"};
    bool send_flag = false;  
    for ( int i = 0; i < MAX_FILE_COUNT; i++ )
    {
        if ( part_get_file_checkbox_checkedstate(part_array[i]) && part_array[i]->dirent_index )
        {
            send_flag = true;
            CrLogI("deleta file index:%d,%d",part_array[i]->dirent_index,part_array[i]->is_local_disk);
            char temp[10] = {0};
            snprintf(temp, 10, "\t%d", part_array[i]->dirent_index);
            strcat(&sendbuff[strlen(sendbuff)], temp);
            CrLogI("deleta file:%s",sendbuff);
        }
    }
    if(send_flag)
    {
        set_printer_data(CONTROL_FILE, strlen(sendbuff), sendbuff);
    }
    show_checkboxes(!show_checkbox_file);
    show_checkbox_file = !show_checkbox_file;
}

void file_manage_switch_screen(Screen_Type_t screen)
{
    manager_screen_type = screen;
}

void file_manage_switch_disk(bool is_local)
{
    // if ( is_local != is_local_disk )
    // {
        is_local_disk = is_local;
        if(page_last_index != 0)
        {
            page_last_index = 0;
        }
        else
        {
            wifi_wait_animmotion(true);
            send_get_root_dir_file_count_cmd(is_local_disk);
        }
        switch_selected_disk_btn_backgroud_color(is_local_disk);
    // }
}

void file_manage_set_files_count(int count)
{
    if ( manager_screen_type == SCREEN_FILE )
    {
        set_root_dir_files_count(count);
    }
    else if ( manager_screen_type == SCREEN_SUBDIR )
    {
        sub_dir_set_files_count(count);
    }
}

void file_manage_set_file_infos(Dirent_Info_t dirent_array[8], int real_count)
{
    if ( manager_screen_type == SCREEN_FILE )
    {
        set_root_dir_file_infos(dirent_array, real_count);
        wait_animmotion(false);
    }
    else if ( manager_screen_type == SCREEN_SUBDIR )
    {
        sub_dir_set_file_infos(dirent_array, real_count);
    }
}

void file_manage_set_print_record_info(print_record_info_t record_arry[3], int real_record_count)
{
    history_set_print_record_info(record_arry, real_record_count);
}

void file_manage_set_print_record_count(int count)
{
    history_set_print_record_count(count);
}

void set_root_dir_files_count(int count)
{
    CrLogI("enter the files page.count :%d",count);
    if ( count <= 0)
    {
        CrLogI("the files count < 0");
        wait_animmotion(0);
        lv_obj_clear_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);
        for ( int i = 0; i < 8; i++ )
        {
            if ( part_array[i] && part_array[i]->part_panel )
                lv_obj_add_flag(part_array[i]->part_panel, LV_OBJ_FLAG_HIDDEN);
        }
        page_start_index = 0;
        file_count_of_root_dir = 0;
    }
    else
    {
        CrLogI("the files count > 0");
        lv_obj_add_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);
        send_get_cur_dir_dirent_infos_cmd(1, PAGE_MAX_DIRENT_COUNT);
        page_start_index = 1;
        file_count_of_root_dir = count;
    }
} 

void set_root_dir_file_infos(Dirent_Info_t dirent_array[8], int real_count)
{
    if ( real_count <= 0 || !dirent_array)
    {
        lv_obj_clear_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);
        for ( int i = 0; i < 8; i++ )
        {
            if ( part_array[i] && part_array[i]->part_panel )
                lv_obj_add_flag(part_array[i]->part_panel, LV_OBJ_FLAG_HIDDEN);
        }

        return;
    }  
    else
        lv_obj_add_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);


    for ( int i = 0; i < 8; i++ )
    {
        if ( i < real_count )
        {
            if ( part_array[i] && part_array[i]->part_panel )
                lv_obj_clear_flag(part_array[i]->part_panel, LV_OBJ_FLAG_HIDDEN);

            dirent_array[i].dirent_index = i + page_start_index;
            if ( dirent_array[i].is_dir )
            {

                time_t timesteamp = (time_t)dirent_array[i].dir_create_time;
                struct tm *CurTime = localtime(&timesteamp);

                char timepath[20] = {0};
                snprintf(timepath , sizeof(timepath) ,"%d%02d%02d %02d:%02d",
                                    CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
                                    CurTime->tm_hour, CurTime->tm_min);

                part_show_Dir_info(part_array[i], dirent_array[i].name, 
                                   timepath,  dirent_array[i].dirent_index, is_local_disk);   
            }
            else
            {
                part_show_mode_file_info(part_array[i], dirent_array[i].name, dirent_array[i].mode_thumbnail,
                                        dirent_array[i].totle_time, dirent_array[i].mater_used, 
                                        dirent_array[i].dirent_index, is_local_disk, dirent_array[i].filament_type, dirent_array[i].nozzle_temp, dirent_array[i].bed_temp);
            }
        }
        else
        {
            if ( part_array[i] && part_array[i]->part_panel )
                lv_obj_add_flag(part_array[i]->part_panel, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void file_manage_set_u_disk_status(bool inserted)
{
    if( inserted && system_state.Udisk_state){
        create_msgbox(DiskIn[get_cur_language_index()], NULL, 2000, lv_scr_act());
        if(lv_scr_act() == ui_ScreenFileManage)
        {
            CrLogI("on the filemanage page,refresh the file");
            if(is_local_disk == false)
            {
                CrLogI("local disk page.");
                file_manage_switch_disk(false);
            }
        }
    }
    else{
        create_msgbox(DiskOut[get_cur_language_index()], NULL, 2000, lv_scr_act());
        if(lv_scr_act() == ui_ScreenFileManage){
            CrLogI("on the filemanage page,refresh the file");
            if(is_local_disk == false){
                CrLogI("local disk page.");
                file_manage_switch_disk(false);
            }
        }
    }
}

void file_manage_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_LabelLocalScreenFile )
    {
        lv_label_set_text(ui_LabelLocalScreenFile, Local[language_index]);
        redefine_label_size(ui_LabelLocalScreenFile, lv_font25.font, 0, 0, 360, 0);
        
        lv_obj_update_layout(ui_ButtonLocalFile);
        redefine_widgets_size(ui_ButtonLocalFile, ui_LabelLocalScreenFile, 5, 0, 146, 46);
    }

    if ( ui_LabelUDiskScreenFile )
    {
        lv_label_set_text(ui_LabelUDiskScreenFile, DiskU[language_index]);
        redefine_label_size(ui_LabelUDiskScreenFile, lv_font25.font, 0, 0, 360, 0);
        
        lv_obj_update_layout(ui_ButtonUsbFile);
        redefine_widgets_size(ui_ButtonUsbFile, ui_LabelUDiskScreenFile, 5, 0, 146, 46);
    }

    if ( ui_LabelPrintHistoryScreenFile )
    {
        lv_label_set_text(ui_LabelPrintHistoryScreenFile, History[language_index]);
        redefine_label_size(ui_LabelPrintHistoryScreenFile, lv_font25.font, 0, 0, 360, 0);
        
        lv_obj_update_layout(ui_ButtonPrintHistoryFile);
        redefine_widgets_size(ui_ButtonPrintHistoryFile, ui_LabelPrintHistoryScreenFile, 5, 0, 146, 46);
    }

    if ( ui_LabelNoContentsPrompt )
        lv_label_set_text(ui_LabelNoContentsPrompt, NoContentsMsg[language_index]);

    if ( ui_LabelCopyLocalFiles )
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", CopyTo[language_index], DiskU[language_index]);
        lv_label_set_text(ui_LabelCopyLocalFiles, CopyToUSB[language_index]);
    } 

    if ( ui_LabelDelLocalFile )
        lv_label_set_text(ui_LabelDelLocalFile, Delete[language_index]);

    if(ui_FileSortActionTitle)
        lv_label_set_text(ui_FileSortActionTitle, Screening[language_index]);

    if ( ui_FileSortByName )
    {
        lv_checkbox_set_text(ui_FileSortByName, SortByName[language_index]);
    }

    if ( ui_FileSortBysize )
    {
        lv_checkbox_set_text(ui_FileSortBysize, SortBySize[language_index]);
        lv_obj_align_to(ui_SizeSortOrderIcon, ui_FileSortBysize, LV_ALIGN_OUT_RIGHT_MID, 30, 0);

    }

    if ( ui_FileSortByTime )
    {
        lv_checkbox_set_text(ui_FileSortByTime, SortByTime[language_index]);
        lv_obj_align_to(ui_TimeSortOrderIcon, ui_FileSortByTime, LV_ALIGN_OUT_RIGHT_MID, 30, 0);
    }
    preview_change_language_text();
    history_change_language_text();
    sub_dir_change_language_text();
}

void refresh_copyprocess(int process, int copyto)
{
    char msgbuff[256] = {0};
    if(copyto == 2)//2是复制
    {
        if(process <= 100)
        {
            snprintf(msgbuff, 256, "%s:%d%%", CopyProcess[get_cur_language_index()], process);
            create_msgbox(msgbuff, NULL, 0, lv_layer_top());
        }
        if(process > 100)
        {
            snprintf(msgbuff, 256, "%s:%d%%", CopyProcess[get_cur_language_index()], 100);
            create_msgbox(msgbuff, NULL, 1000, lv_layer_top());
            wait_animmotion(true);
            send_get_root_dir_file_count_cmd(is_local_disk); 
        }
        if(process == -1)
        {
            snprintf(msgbuff, 256, "%s", CopyErrorResult[get_cur_language_index()]);
            create_msgbox(msgbuff, NULL, 1000, lv_layer_top());
        }
    }
    if( copyto == 3)//3是删除
    {
        if(process < 100)
        {
            snprintf(msgbuff, 256, "%s:%d%%", Delete[get_cur_language_index()], process);
            create_msgbox(msgbuff, NULL, 0, lv_layer_top());
        }
        if(process >= 100)
        {
            snprintf(msgbuff, 256, "%s:%d%%", Delete[get_cur_language_index()], 100);
            create_msgbox(msgbuff, NULL, 1000, lv_layer_top());
            wait_animmotion(true);
            // send_get_root_dir_file_count_cmd(is_local_disk); 
            LoadFileManageScreen();
        }
        if(process == -1)
        {
            snprintf(msgbuff, 256, "%s", CopyErrorResult[get_cur_language_index()]);
            create_msgbox(msgbuff, NULL, 1000, lv_layer_top());
        }
    }

}

bool get_is_local_disk()
{
    return is_local_disk;
}

void set_is_local_disk(bool state)
{
    is_local_disk = state;
}

int get_current_page_number(void)
{
    return (page_start_index / PAGE_MAX_DIRENT_COUNT) + 1;
}

void set_last_index(int index)
{
    return page_last_index = index;
}