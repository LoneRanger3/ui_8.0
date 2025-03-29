#include "ui_screen_FileManage.h"
#include "src/core/lv_event.h"
#include "ui_screen_PrintHistory.h"
#include "ui_screen_SubDir.h"
#include "ui_screen_Preview.h"
#include "ui_helpers.h"
#include "ui_custom_dirent_info_part.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_HomePrinting.h"
#include "ui_Screen_Settings.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "../custom/lvgl_cmd.h"
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"
#include "ui_screen_Adjustment.h"
#include "ui_screen_AxisMove.h"
#include "ui_Screen_CustomerService.h"
#include "mult_language.h"
#include "ui_Screen_Settings.h"
#include "../lv_drivers/indev/keypad_encoder.h"
#include "global/Global.h"


static lv_obj_t * ui_ScreenFileManage;
/**********file manage page left panel*******************/
static lv_obj_t * ui_PanelPageScreenFile;
static lv_obj_t * ui_ButtonHomeScreenFile;
static lv_obj_t * ui_ButtonAxisMoveScreenFile;
static lv_obj_t * ui_ButtonFileManageScreenFile;
static lv_obj_t * ui_ButtonSettingsScreenFile;
static lv_obj_t * ui_ButtonReserveScreenFile;

/**********file manage page right panel*******************/
static lv_obj_t * ui_FilemanageMainPanel; //文件管理页主面板
static lv_obj_t * ui_FilemanageTitlePanel;
static lv_obj_t * ui_FilemanageTitleLabel;
static lv_obj_t * ui_DeviceIconPanel;

/**********file manage page right panel title*******************/
static lv_obj_t * ui_ImageWifiNormal;
static lv_obj_t * ui_ImageCamerastate;
static lv_obj_t * ui_ImageLaserState;
static lv_obj_t * ui_ButtonLocalFile;
static lv_obj_t * ui_LabelLocalScreenFile;
static lv_obj_t * ui_LabelUDiskScreenFile;
static lv_obj_t * ui_LabelPrintHistoryScreenFile;

/**********file manage page right panel file list*******************/
static lv_obj_t * ui_PanelCenter;
static lv_obj_t * ui_PanelFileList;
static lv_obj_t * ui_LabelNoContentsPrompt;

/**********file manage page right panel change page*******************/
static lv_obj_t * ui_PanelPrevFilesPage;
static lv_obj_t * ui_ImageFilesPrevPage;
static lv_obj_t * ui_PanelNextFilesPage;
static lv_obj_t * ui_ImageFilesNextPage;

/***************************custom variable*****************************************/
static bool show_checkbox_file = false;
static bool is_local_disk = true;   //
static bool udiskJsonChangeParseFlag = false;  //用于判定u盘gcode文件数目改变后更新的 json 文件信息是否更新完毕，只解析一次
static bool localJsonChangeParseFlag = false;  //用于判定本地 gcode文件数目改变后更新的 json 文件信息是否更新完毕，只解析一次
static int Localfile_count; 
int Udiskfile_count; 
static Screen_Type_t manager_screen_type = SCREEN_FILE;
static int16_t file_count_of_root_dir = 0;
static int16_t page_start_index = 0;
static int wifi_Intensity = 0;
static Msgboxbtn_t FileActionbtn[3]; //用于文件操作
static DialogMsgbox_t FileActionMessage; //文件操作对话框

static lv_obj_t * ui_FileListWaittimer = NULL;
static uint16_t preFileListCount = 0; //记录上一次分配的文件列表个数

static dirent_info_part_t *part_array[8] = {NULL};
static dirent_info_part_t **Gfilepanel = NULL;
#define MAX_FILE_COUNT 8

EventGrop_Data FileManage;

typedef void (*FileManageAdd3rdObjsCb)(void);  //添加三级导航对象
static FileManageAdd3rdObjsCb Add3rLeveldObjsCb = NULL; 

static void FileActionPageAddFocusObjs(void);
static void ShowGcodeFileInfo(bool hasUdisk, uint8_t wait_time);

/*-------------- screen event, can not modify---------------*/
static void ui_event_ButtonHomeScreenFile(lv_event_t * e);
static void ui_event_ButtonAxisMoveScreenFile(lv_event_t * e);
static void ui_event_ButtonSettingsScreenFile(lv_event_t * e);
static void ui_event_ButtonReserveScreenFile(lv_event_t * e);

static void ui_event_PanelFileInfo(lv_event_t * e);
static void ui_event_CheckboxFile1(lv_event_t * e);
static void ui_event_PanelFileInfo2(lv_event_t * e);

/*-------------- screen event call back---------------*/
static void FilePageHomeBtnClicked(lv_event_t * e);
static void FilePageAxisBtnClicked(lv_event_t * e);
static void FilePageSettingsBtnClicked(lv_event_t * e);
static void FilePageReserveBtnClicked(lv_event_t * e);
static void FilePageFileInfoPanelClicked(lv_event_t * e);
static void FilePageFileInfoPanelLongPressed(lv_event_t * e);
static void FilePageCopyFilesBtnClicked(lv_event_t * e);
static void FilePageDelFilesBtnClicked(lv_event_t * e);
static void RunGcodeParseProcess(void);
static void GcodeListAddFocusObjs(void);

/******************custom funs***********************/
static void set_root_dir_files_count(int count);  

static void FileManagePageChangeObjs(uint8_t index);
static void wait_timerout_handle(lv_timer_t * timer);

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif


///////////////////// FUNCTIONS ////////////////////

void ui_event_ButtonHomeScreenFile(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {        
        FilePageHomeBtnClicked(e);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
         FilePageHomeBtnClicked(e);
    }
    if(event_code == LV_EVENT_DEFOCUSED) { 
    }
}
void ui_event_ButtonAxisMoveScreenFile(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
 
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //LoadAxisMoveScreen();
        LoadAxixMoveScreenAndObjs(true);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
       // LoadAxisMoveScreen();
        LoadAxixMoveScreenAndObjs(false);
        wait_animmotion(false);

    }
}

lv_timer_t * FileManageNavTimer;
void FileManageNavTimerCb(lv_timer_t * timer)
{
  /*Use the user_data*/
    lv_group_focus_freeze(encoder_group, false);
    lv_timer_del(FileManageNavTimer);
}

void ui_event_ButtonFileManage(lv_event_t * e)
{
    bool IsEntered = false;
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
       // LoadFileManageScreen();
       IsEntered = FileManage.stateValue;
       IsEntered = !IsEntered;
       LoadFileManageScreenAndObjs(IsEntered);
    }
    // if(event_code == LV_EVENT_DEFOCUSED)
    // {
    //     if (FileManage.stateValue)
    //     {
    //         lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenFile, &ui_img_pagefilemanageselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     }
    // }
    // if(event_code == LV_EVENT_FOCUSED)
    // {
    //     lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenFile, &ui_img_pagefilemanageselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     // if (FileManage.stateValue)
    //     // {
    //     //     lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenFile, &ui_img_pagefilemanagefocus_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     //     if (page_manager.objFreezzFlag == false)
    //     //     {
    //     //         page_manager.objFreezzFlag = true;
    //     //     }
    //     //     else if (page_manager.objFreezzFlag == true)
    //     //     {
    //     //         lv_group_focus_freeze(encoder_group, true);
    //     //         FileManageNavTimer = lv_timer_create(FileManageNavTimerCb, 300,  NULL);
    //     //     }
    //     // }
    // }
}
void ui_event_ButtonSettingsScreenFile(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        FilePageSettingsBtnClicked(e);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
      //  LoadSettingsScreen();
        LoadSettingsScreenAndObjs(false, SCREEN_SETTINGS_BUTTON);
        wait_animmotion(false);
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

/**
 * @description: 文件列表单击和长按操作
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_PanelFileInfo(lv_event_t * e)
{
    static int encoder_last_tick = 0;
    static bool flag = true;
    static uint8_t focuse_cnt = 0;
    static uint16_t preId = 0; 
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    //if(event_code == LV_EVENT_CLICKED) {
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        FilePageFileInfoPanelClicked(e);
    }
    if(event_code == LV_EVENT_LONG_PRESSED) {
        FilePageFileInfoPanelLongPressed(e);
        int id = lv_obj_get_child_id(target);
        CrLogI("LV_EVENT_LONG_PRESSED.id=%d", id);
    }

#if 0
    if(event_code == LV_EVENT_FOCUSED) {   
     
        focuse_cnt ++;

        int diff = lv_tick_get() - encoder_last_tick;
        encoder_last_tick = lv_tick_get();
        int id = lv_obj_get_child_id(target);
        
        if (id && id > preId)
        {
            printf("右旋\n");
            if(get_is_local_disk() == true && id % 3 == 0) {
                

            }
        }
        else if (id && id < preId )
        {
            if(get_is_local_disk() == false) {
                
            }
            
            printf("左旋\n");
        }
        preId = id;

        printf("id=%d\n",id);
        if(diff < 50)
        {   
            if(flag){
                flag=false;
                printf("lv_group_focus_next\n");
                lv_group_focus_next(encoder_group);
            }else{
                if (focuse_cnt%2 == 0)
                    flag=true;
            } 
        }  
    }
#endif
}

/**
 * @description: 长按文件列表对话框回调处理
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_FileAction(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int dat = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
       CrLogI("ui_event_FileAction dat :%d\n", dat);

        switch(dat) //文件操作
        {
            case 0: 
                FilePageCopyFilesBtnClicked(e);
                break;
            case 1: 
                FilePageDelFilesBtnClicked(e);
                HiddenDialogMessagebox(&FileActionMessage);
                LoadFileManageScreenAndObjs(true);
                break; 
            case 2: 
                HiddenDialogMessagebox(&FileActionMessage);
                BackPrepage(true);
                CrLogI("ui_event_FileAction BackPrepage(true)");
                break;
            default:break;
        }
    }
}

/**
 * @description: 对话框列表多语言设置
 * @return {*}
 * @param {lv_obj_t} *label
 * @param {uint8_t} label_index
 * @param {uint8_t} language_index
 */
void FileActionTextSet(lv_obj_t *label, uint8_t label_index, uint8_t language_index)
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

/**************************************初始化处理************************************************/
void ui_ScreenFileManage_screen_init(void)
{
    
    ui_ScreenFileManage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenFileManage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenFileManage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenFileManage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    FileManage.GropName = lv_group_create();
    FileManage.stateValue =  false;
    init_pages(ui_ScreenFileManage, FileManagePageChangeObjs, LoadFileManageScreen);


    uint8_t language_index = get_cur_language_index();
    ui_PanelPageScreenFile = lv_obj_create(ui_ScreenFileManage);
    lv_obj_set_width(ui_PanelPageScreenFile, 68);
    lv_obj_set_height(ui_PanelPageScreenFile, 360);
    lv_obj_set_pos(ui_PanelPageScreenFile, 0, 60);

    lv_obj_clear_flag(ui_PanelPageScreenFile, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPageScreenFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPageScreenFile, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

 
    ui_ButtonHomeScreenFile = lv_btn_create(ui_PanelPageScreenFile);
    lv_obj_set_width(ui_ButtonHomeScreenFile, 68);
    lv_obj_set_height(ui_ButtonHomeScreenFile, 72);
   /// lv_obj_set_align(ui_ButtonHomeScreenFile, LV_ALIGN_TOP_LEFT);
    lv_obj_set_x(ui_ButtonHomeScreenFile, -18);
    lv_obj_set_y(ui_ButtonHomeScreenFile, -18);
    lv_obj_add_flag(ui_ButtonHomeScreenFile, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenFile, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonHomeScreenFile, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenFile, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    lv_obj_set_style_border_color(ui_ButtonHomeScreenFile, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenFile, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenFile, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonHomeScreenFile, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ButtonHomeScreenFile, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonHomeScreenFile, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    ui_ButtonAxisMoveScreenFile = lv_btn_create(ui_PanelPageScreenFile);
    lv_obj_set_width(ui_ButtonAxisMoveScreenFile, 68);
    lv_obj_set_height(ui_ButtonAxisMoveScreenFile, 72);
    lv_obj_set_x(ui_ButtonAxisMoveScreenFile, -18);
    lv_obj_set_y(ui_ButtonAxisMoveScreenFile, 54);
    lv_obj_add_flag(ui_ButtonAxisMoveScreenFile, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveScreenFile, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonAxisMoveScreenFile, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveScreenFile, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMoveScreenFile, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveScreenFile, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveScreenFile, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonAxisMoveScreenFile, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonAxisMoveScreenFile, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    
    //ui_ButtonFileManageScreenFile = lv_btn_create(ui_PanelPageScreenFile);
    ui_ButtonFileManageScreenFile = lv_obj_create(ui_PanelPageScreenFile);
    lv_obj_set_width(ui_ButtonFileManageScreenFile, 68);
    lv_obj_set_height(ui_ButtonFileManageScreenFile, 72);
    lv_obj_set_x(ui_ButtonFileManageScreenFile, -18);
    lv_obj_set_y(ui_ButtonFileManageScreenFile, 126);
    lv_obj_add_flag(ui_ButtonFileManageScreenFile, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFileManageScreenFile, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonFileManageScreenFile, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenFile, &ui_img_pagefilemanageselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_radius(ui_ButtonFileManageScreenFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonFileManageScreenFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonFileManageScreenFile, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonFileManageScreenFile, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonFileManageScreenFile, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonFileManageScreenFile, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonFileManageScreenFile, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonFileManageScreenFile, 1, LV_PART_MAIN | LV_STATE_PRESSED);


    ui_ButtonSettingsScreenFile = lv_btn_create(ui_PanelPageScreenFile);
    lv_obj_set_width(ui_ButtonSettingsScreenFile, 68);
    lv_obj_set_height(ui_ButtonSettingsScreenFile, 72);
    lv_obj_set_x(ui_ButtonSettingsScreenFile, -18);
    lv_obj_set_y(ui_ButtonSettingsScreenFile, 198);
    lv_obj_add_flag(ui_ButtonSettingsScreenFile, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenFile, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonSettingsScreenFile, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenFile, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenFile, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenFile, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenFile, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonSettingsScreenFile, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonSettingsScreenFile, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    ui_ButtonReserveScreenFile = lv_btn_create(ui_PanelPageScreenFile);
    lv_obj_set_width(ui_ButtonReserveScreenFile, 68);
    lv_obj_set_height(ui_ButtonReserveScreenFile, 72);
    lv_obj_set_x(ui_ButtonReserveScreenFile, -18);
    lv_obj_set_y(ui_ButtonReserveScreenFile, 270);
    lv_obj_add_flag(ui_ButtonReserveScreenFile, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveScreenFile, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonReserveScreenFile, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenFile, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveScreenFile, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonReserveScreenFile, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonReserveScreenFile, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonReserveScreenFile, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonReserveScreenFile, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    ui_FilemanageMainPanel = lv_obj_create(ui_ScreenFileManage);
    lv_obj_clear_flag(ui_FilemanageMainPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_FilemanageMainPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FilemanageMainPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui_FilemanageMainPanel, 68, 60); //页面导航栏宽度为68 
	lv_obj_set_size(ui_FilemanageMainPanel, 572, 360);
   // lv_obj_set_align(ui_FilemanageMainPanel, LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_radius(ui_FilemanageMainPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_FilemanageMainPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_FilemanageMainPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_FilemanageMainPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FilemanageMainPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FilemanageTitlePanel = lv_obj_create(ui_FilemanageMainPanel);
    lv_obj_set_pos(ui_FilemanageTitlePanel, 0, 0);
    lv_obj_set_size(ui_FilemanageTitlePanel, 572, 46);
    lv_obj_clear_flag(ui_FilemanageTitlePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_FilemanageTitlePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FilemanageTitlePanel, lv_color_hex(0x101011), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FilemanageTitlePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_FilemanageTitlePanel, lv_color_hex(0x565656), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_FilemanageTitlePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FilemanageTitlePanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_FilemanageTitlePanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_FilemanageTitlePanel, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_FilemanageTitleLabel = lv_label_create(ui_FilemanageTitlePanel);
    lv_obj_set_size(ui_FilemanageTitleLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_FilemanageTitleLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_FilemanageTitleLabel, File[language_index]);
    lv_obj_set_style_text_color(ui_FilemanageTitleLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FilemanageTitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FilemanageTitleLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_FilemanageTitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceIconPanel = lv_obj_create(ui_FilemanageTitlePanel);
    lv_obj_set_size(ui_DeviceIconPanel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_clear_flag(ui_DeviceIconPanel, LV_OBJ_FLAG_SCROLLABLE);  
    lv_obj_align(ui_DeviceIconPanel, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_set_style_radius(ui_DeviceIconPanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceIconPanel, lv_color_hex(0x101011), LV_PART_MAIN | LV_STATE_DEFAULT);
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
    //lv_obj_set_flex_align(ui_ImageLaserState, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
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
    filemanage_page_set_wifi_status(wifi_Intensity);
    lv_obj_set_size(ui_ImageWifiNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_add_flag(ui_ImageWifiNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageWifiNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PanelFileList = lv_obj_create(ui_FilemanageMainPanel);
    lv_obj_set_width(ui_PanelFileList, 572);
    lv_obj_set_height(ui_PanelFileList, 310);
    lv_obj_set_x(ui_PanelFileList, 0);
    lv_obj_set_y(ui_PanelFileList, 51);
    lv_obj_add_flag(ui_PanelFileList, LV_OBJ_FLAG_SCROLL_ON_FOCUS);  
    //lv_obj_add_flag(ui_PanelFileList, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFileList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFileList, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFileList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFileList, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelFileList, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_style_pad_all(ui_PanelFileList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scroll_snap_y(ui_PanelFileList, LV_SCROLL_SNAP_NONE);
    lv_obj_set_flex_flow(ui_PanelFileList, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_left(ui_PanelFileList, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_PanelFileList, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

    
    // "空"
    ui_LabelNoContentsPrompt = lv_label_create(ui_FilemanageMainPanel);
    lv_obj_set_width(ui_LabelNoContentsPrompt, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelNoContentsPrompt, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_LabelNoContentsPrompt, 200);//251
    // lv_obj_set_y(ui_LabelNoContentsPrompt, 120);//155
    lv_obj_set_align(ui_LabelNoContentsPrompt, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelNoContentsPrompt, NoContentsMsg[language_index]);
    lv_obj_add_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_LabelNoContentsPrompt, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelNoContentsPrompt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelNoContentsPrompt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelNoContentsPrompt, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LabelNoContentsPrompt, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_style_pad_all(ui_LabelNoContentsPrompt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 文件操作对话框初始化
    for (size_t i = 0; i < 3; i++)
    {
        FileActionbtn[i].btnsCallbackArray = ui_event_FileAction;
        FileActionbtn[i].SetLabelText = FileActionTextSet;
    }
    
    FileActionMessage.hasSubPanel = true;
    FileActionMessage.title = Action;
    FileActionMessage.btn = FileActionbtn;
    FileActionMessage.customStyle = &StyleDialogBtn;
    FileActionMessage.customFocusStyle = &StyleDialogFocusBtn;

    FileActionMessage.btnNumber = sizeof(FileActionbtn)/sizeof(Msgboxbtn_t);
    FileActionMessage.subPanelAttr.w = 373;
    FileActionMessage.subPanelAttr.h = 278;

    InitDialogMessagebox(&FileActionMessage);
    lv_obj_align(FileActionMessage.titleLabel, LV_ALIGN_TOP_MID, 0, 11);
    
    uint8_t btnBasePos_y = 56;
    for (size_t i = 0; i < FileActionMessage.btnNumber; i++)
    {
        lv_obj_align(FileActionMessage.btn[i].label, LV_ALIGN_LEFT_MID, 0, 1);
        lv_obj_set_size(FileActionMessage.btn[i].btn, 312, 52);
        lv_obj_set_pos(FileActionMessage.btn[i].btn, 35, btnBasePos_y);
        btnBasePos_y += 67;
    }
    
    lv_obj_add_event_cb(ui_ButtonHomeScreenFile, ui_event_ButtonHomeScreenFile, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMoveScreenFile, ui_event_ButtonAxisMoveScreenFile, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonFileManageScreenFile, ui_event_ButtonFileManage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsScreenFile, ui_event_ButtonSettingsScreenFile, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserveScreenFile, ui_event_ButtonReserveScreenFile, LV_EVENT_ALL, NULL);

    /***************test*********************/
    // Dirent_Info_t dirent_array[2] = {0};
    // dirent_array[0].is_dir = true;
    // strcpy(dirent_array[0].name, "test");
    // dirent_array[0].dir_create_time = 0x88888888;
    // dirent_array[0].dirent_index = 3;
    // dirent_array[1].dirent_index = 5;
    // dirent_array[1].is_dir = false;
    // dirent_array[1].totle_time = 100000;
    // dirent_array[1].mater_used = 1000;
    // strcpy(dirent_array[1].name, "test.gcode");
    // strcpy(dirent_array[1].mode_thumbnail, "");
    // set_root_dir_file_infos(dirent_array, 2);

}


void LoadFileManageScreen(void)
{
  
    lv_disp_load_scr(ui_ScreenFileManage);
    
   // ShowGcodeFileInfo(udisk_state, 1);
    RunGcodeParseProcess();

    lv_obj_clear_state(ui_ButtonHomeScreenFile, LV_OBJ_FLAG_CLICK_FOCUSABLE);
}

/*********************************左侧导航列表单击跳转处理****************************************/
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
/*********************************************************************************************/

/*gcode 文件列表单击 */
void FilePageFileInfoPanelClicked(lv_event_t * e)
{
	// Your code here
    dirent_info_part_t *part = lv_event_get_user_data(e);
    if ( !part )
        return ;
    
    if ( part->is_dir )
    {
        CrLogI("part->is_udisk :%d, part->dirent_index : %d\n", part->is_udisk, part->dirent_index);
        GetSubDGcodeFileNum(part->is_udisk, part->dirent_index);
        LoadPage(ui_ScreenSubDir, 1);
       // LoadSubDirScreen();
       // file_manage_switch_screen(SCREEN_SUBDIR);
        /***get sub dir filelist***/
       // sub_dir_enter_screen_settings(part_get_dirent_info_name(part), part_dirent_index(part), is_local_disk ? true : false);
        sub_dir_enter_screen_settings(part);
    }
    else
    {
        if( show_checkbox_file )
        {
            bool status = part_get_file_checkbox_checkedstate(part);
            part_set_file_checkbox_state(part, !status);
            return;
        }
        preview_set_mode_file_from_dir_type(true);
       // send_get_filling_chart_info_cmd(part_dirent_index(part)); //TODO: 协议一:字符串协议发送命令去master获取预览图
        if ( part->label_dirent_name && part->label_totle_time && part->label_mater_used )
        {
           // char *file_name = part_get_dirent_info_name(part); //part_dirent_index(part) 此处索引和gcode打印文件相关联需注意
            if(preview_set_file_info(part, false) == 0)
            {
                LoadPage(ui_ScreenPreview, 2);
            }
            else
            {
                CrLogI("index error refresh list and reload preview.\n");
                RunGcodeParseProcess();
                char msgbuff[100] = {0};
                snprintf(msgbuff, 256, "%s", FileIndexUpdate[get_cur_language_index()]);
                create_msgbox(msgbuff, NULL, 500, lv_layer_top());
                
            }
            
           // preview_set_file_info(file_name, part->totle_time, part->mater_used, part_dirent_index(part), part->filament_type, part->nozzle_temp, part->bed_temp, FROM_LOCAL);
        }
         // LoadPreviewScreen();
       
    }
}

/**
 * @description: 文件列表长按操作
 * @return {*}
 * @param {lv_event_t *} e
 */
void FilePageFileInfoPanelLongPressed(lv_event_t * e)
{
    dirent_info_part_t *part = lv_event_get_user_data(e);
    if (!part)
        return ;
    uint8_t language_index = get_cur_language_index();
    if (part->is_dir)
    {
        GetSubDGcodeFileNum(part->is_udisk, part->dirent_index);
        LoadPage(ui_ScreenSubDir, 1);
        //file_manage_switch_screen(SCREEN_SUBDIR);
        sub_dir_enter_screen_settings(part);
        
    }
    else
    {
        ShowDialogMessagebox(&FileActionMessage, FileActionPageAddFocusObjs);
        ActionGcodes.isUdiskFile = part->is_udisk;
        ActionGcodes.gcodeIndex = part->dirent_index;
       // CrLogI("ActionGcodes.isUdiskFile : %d, ActionGcodes.gcodeIndex : %d\n", ActionGcodes.isUdiskFile, ActionGcodes.gcodeIndex);
        
        if(ActionGcodes.isUdiskFile) {
            lv_label_set_text(FileActionMessage.btn[0].label, CopyToLocal[language_index]);
            json_object *udiskFileObj = json_object_from_file(GetUserUdiskGcodeFileInfoPtah());
            if(udiskFileObj) {
                json_object *elem = json_object_array_get_idx(udiskFileObj, ActionGcodes.gcodeIndex);
                char *path = json_object_get_string(json_object_object_get(elem, "path"));
                memset(ActionGcodes.filePath, 0, sizeof(ActionGcodes.filePath));
                if (path != NULL)
                    strncpy(ActionGcodes.filePath, path, sizeof(ActionGcodes.filePath));
                json_object_put(udiskFileObj);  
            }
        }
        else {
            lv_label_set_text(FileActionMessage.btn[0].label, CopyToUSB[language_index]);
            json_object *localFileObj = json_object_from_file(GetUserLocalGcodeFileInfoPtah());
            if(localFileObj) {
                json_object *elem = json_object_array_get_idx(localFileObj, ActionGcodes.gcodeIndex);
                char *path = json_object_get_string(json_object_object_get(elem, "path"));
                memset(ActionGcodes.filePath, 0, sizeof(ActionGcodes.filePath));
                if (path != NULL)
                    strncpy(ActionGcodes.filePath, path, sizeof(ActionGcodes.filePath));
               // printf("ActionGcodes.filePath :%s\n", ActionGcodes.filePath);
                json_object_put(localFileObj);  
            }
        }
    }
}

/**
 * @description: 拷贝处理
 * @return {*}
 * @param {lv_event_t *} e
 */
void FilePageCopyFilesBtnClicked(lv_event_t * e)
{
	// Your code here
    //获取当前的索引序列号
    char sendbuff[100] = {"12"};

    if(ActionGcodes.isUdiskFile)
        strcat(sendbuff, "\t2");    
    else
        strcat(sendbuff, "\t1");    
    // for ( int i = 0; i < MAX_FILE_COUNT; i++ )
    // {
    //     if ( part_get_file_checkbox_checkedstate(part_array[i]) && part_array[i]->dirent_index )
    //     {
    // //         send_flag = true;
    //       //  CrLogI("copy file index:%d,%d",part_array[i]->dirent_index,part_array[i]->is_local_disk);
    //         char temp[10] = {0};
    //         snprintf(temp, 10, "\t%d", part_array[i]->dirent_index);
    //         strcat(&sendbuff[strlen(sendbuff)], temp);
    //         CrLogI("copy file:%s",sendbuff);
    // //     }
    // }
    // if(send_flag)
    // {
    if (system_state.Udisk_state)
    {
        set_printer_data(CONTROL_FILE, strlen(sendbuff), sendbuff);
        HiddenDialogMessagebox(&FileActionMessage);
        LoadFileManageScreenAndObjs(true);
    }
    else
    {
        create_msgbox(DiskUMsg[get_cur_language_index()], NULL, 1000, lv_scr_act());
        HiddenDialogMessagebox(&FileActionMessage);
        BackPrepage(true);
    }
    if(ActionGcodes.isUdiskFile) {
        localJsonChangeParseFlag = true;
        CrLogI("Copy localJsonChangeParseFlag set\n");
    }
    else {
        udiskJsonChangeParseFlag = true;
        CrLogI("Copy udiskJsonChangeParseFlag set\n");
    }
    CrLogI("Localfile_count : %d, Udiskfile_count: %d", Localfile_count, Udiskfile_count);
    CrLogI("preFileListCount : %d\n", preFileListCount);
}

/**
 * @description: 文件删除处理
 * @return {*}
 * @param {lv_event_t *} e
 */
void FilePageDelFilesBtnClicked(lv_event_t * e)
{
	// Your code here
    //获取当前的索引序列号
    char sendbuff[100] = {"13"};
    bool send_flag = false;  
    // for ( int i = 0; i < MAX_FILE_COUNT; i++ )
    // {
    //     if ( part_get_file_checkbox_checkedstate(part_array[i]) && part_array[i]->dirent_index )
    //     {
    //         send_flag = true;
    //         CrLogI("deleta file index:%d,%d",part_array[i]->dirent_index,part_array[i]->is_local_disk);
    //         char temp[10] = {0};
    //         snprintf(temp, 10, "\t%d", part_array[i]->dirent_index);
    //         strcat(&sendbuff[strlen(sendbuff)], temp);
    //         CrLogI("deleta file:%s",sendbuff);
    //     }
    // }

    set_printer_data(CONTROL_FILE, strlen(sendbuff), sendbuff);

    if(ActionGcodes.isUdiskFile) {
        udiskJsonChangeParseFlag = true;
       // printf("Del udiskJsonChangeParseFlag set\n");
    }
    else {
        localJsonChangeParseFlag = true;
       // printf("Del localJsonChangeParseFlag set\n");
    }
   
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
    // if ( manager_screen_type == SCREEN_FILE )
    // {
    //     set_root_dir_file_infos(dirent_array, real_count);
    // }
    // else if ( manager_screen_type == SCREEN_SUBDIR )
    // {
    //     sub_dir_set_file_infos(dirent_array, real_count);
    // }
}

void file_manage_set_print_record_info(print_record_info_t record_arry[3], int real_record_count)
{
    history_set_print_record_info(record_arry, real_record_count);
}

void file_manage_set_print_record_count(int count)
{
    history_set_print_record_count(count);
}

/*根目录文件数*/

void set_root_dir_files_count(int count)
{
    CrLogI("enter the files page.count :%d",count);
    if ( count <= 0)
    {
        CrLogI("the files count < 0");
        lv_obj_clear_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);//显示“空”
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

/**
 * @description: 根据gcode的文件数动态管理内存
 * @return {*}
 * @param {uint16_t} file_number
 */
void GcodePanelMemoryManager(uint16_t file_number)
{
    static uint16_t preFileNum = 0;
    static int ui_PanelFileListY = 0;
    dirent_info_part_t **NewGfilepanel = NULL;
    
    if (preFileNum == 0)
    {
        Gfilepanel = (dirent_info_part_t **)malloc(file_number*sizeof(dirent_info_part_t *));
        if (Gfilepanel != NULL) {
            for (size_t i = preFileNum; i < file_number; i++)
            {   
                Gfilepanel[i] = create_custom_dirent_info_part(ui_PanelFileList, &ui_event_PanelFileInfo);
            }
        }
    }  
    else if (file_number > preFileNum)
    {
        NewGfilepanel = (dirent_info_part_t **)realloc(Gfilepanel, file_number*sizeof(dirent_info_part_t *));
        if (Gfilepanel != NULL) {
            Gfilepanel = NewGfilepanel;
            for (size_t i = preFileNum; i < file_number; i++)
            {
                Gfilepanel[i] = create_custom_dirent_info_part(ui_PanelFileList, &ui_event_PanelFileInfo);
            } 
        }
    }
    else if (file_number < preFileNum)
    {
        NewGfilepanel = (dirent_info_part_t **)malloc(file_number*sizeof(dirent_info_part_t *)); 
        for (size_t i = file_number; i < preFileNum; i++) //释放退出面板对象占用空间
        {
            lv_obj_del(Gfilepanel[i]->part_panel); 
            lv_mem_free(Gfilepanel[i]);
            Gfilepanel[i] = NULL;
        }
        if (Gfilepanel != NULL) {
             memcpy(NewGfilepanel, Gfilepanel, file_number * sizeof(dirent_info_part_t *));
             free(Gfilepanel);
             Gfilepanel = NULL;
        }
        Gfilepanel = NewGfilepanel;
    }
    CrLogI("GcodePanelMemoryManager.");
    preFileNum = file_number;
}


static void LocalGcodeFileInfoParse(void)
{
    Dirent_Info_t GcodeInfo;
    if (access(GetUserLocalGcodeInfoDirPtah(), F_OK) == 0) 
    {
        CrLogI("start parse local gcode gson file.");

        json_object *localFileObj = json_object_from_file(GetUserLocalGcodeFileInfoPtah());
        if(localFileObj) {
            //打印格式化的 JSON 字符串
            // const char* json_str = json_object_to_json_string_ext(localFileObj, JSON_C_TO_STRING_PRETTY);
            // printf("%s\n", json_str);

            int totalNum = json_object_array_length(localFileObj);
            Localfile_count = totalNum;
            
            for (int i = 0; i < totalNum; i++) 
            {
                json_object *elem = json_object_array_get_idx(localFileObj, i);
                int type = json_object_get_int(json_object_object_get(elem, "type"));

                if(type == 4) {
                    struct stat buf = {0};
                    char *dir_name = json_object_get_string(json_object_object_get(elem, "name"));
                    char *path = json_object_get_string(json_object_object_get(elem, "path"));
                
                    stat(path, &buf);
                    time_t timesteamp = buf.st_ctime; //gcode 文件导入时间
                    struct tm *CurTime = localtime(&timesteamp);

                    char timepath[20] = {0};
                    snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d %02d:%02d",
                                        CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
                                        CurTime->tm_hour, CurTime->tm_min);
                
                    ShowPartDirInfo(Gfilepanel[Udiskfile_count+i], dir_name, timepath, i, false);
                    
                }
                if(type == 8) {
                    // 文件名
                    char *name = json_object_get_string(json_object_object_get(elem, "name"));
                    strncpy(GcodeInfo.name, name, sizeof(GcodeInfo.name));
                    // printf("GcodeInfo.name :%s\n", GcodeInfo.name);
   
                    // 打印使用时间
                    int totle_time = json_object_get_int(json_object_object_get(elem, "timeCost"));
                    GcodeInfo.totle_time = json_object_get_int(json_object_object_get(elem, "timeCost")); 
                    //printf("GcodeInfo.totle_time :%d\n", GcodeInfo.totle_time);
                    // 使用耗材长度
                    GcodeInfo.mater_used = json_object_get_int(json_object_object_get(elem, "consumables")); 
                    // 材料类型
                    char *material = json_object_get_string(json_object_object_get(elem, "material")); 
                        //printf("material :%s\n", material);
                    if (material != NULL) {
                        strncpy(GcodeInfo.filament_type, material, sizeof(GcodeInfo.filament_type));
                    }
                    // 喷嘴温度
                    GcodeInfo.nozzle_temp = json_object_get_int(json_object_object_get(elem, "nozzleTemp")); 
                    // 热床温度
                    GcodeInfo.bed_temp = json_object_get_int(json_object_object_get(elem, "bedTemp")); 
                    // 缩略图地址
                    char *mode_thumbnail = json_object_get_string(json_object_object_get(elem, "thumbnail")); 
                    if (mode_thumbnail != NULL) {
                        strncpy(GcodeInfo.mode_thumbnail, mode_thumbnail, sizeof(GcodeInfo.mode_thumbnail));
                    }

                    GcodeInfo.is_udisk = false;
                    
                    // printf("the %d file content: filename:%s, fileCreatTime:%ld, totletime:%d, mater_used:%d, material:%s, nozzle_temp:%d, bedtemp:%d, thumbnail:%s", 
                    //         i, GcodeInfo.name, GcodeInfo.dir_create_time, GcodeInfo.totle_time, GcodeInfo.mater_used, GcodeInfo.filament_type, 
                    //         GcodeInfo.nozzle_temp, GcodeInfo.bed_temp, GcodeInfo.mode_thumbnail);
            
                    GcodeInfo.dirent_index = i;
                    if (GcodeInfo.mode_thumbnail[0] != '\0' && GcodeInfo.name[0] != '\0') {
                        ShowPartGcodefileInfo(Gfilepanel[Udiskfile_count+i], &GcodeInfo); //u盘未插入时Udiskfile_count值为0
                    }
                }       
            }
            CrLogI("finish parse local gcode gson file.");
            json_object_put(localFileObj);
        }  
        else CrLogW("read json object fail\n");
    }
    else CrLogI("no local gcode file\n");
}

static void UdiskGcodeFileInfoParse(void)
{
    Dirent_Info_t GcodeInfo;
    memset(&GcodeInfo, 0, sizeof(GcodeInfo));
    if (access(GetUserUdiskGcodeInfoDirPtah(), F_OK) == 0)
    {  
        CrLogI("start parse udisk gcode gson file.");

        json_object *udiskFileObj = json_object_from_file(GetUserUdiskGcodeFileInfoPtah());
        if(udiskFileObj) {
            // 打印格式化的 JSON 字符串
            // const char* json_str = json_object_to_json_string_ext(udiskFileObj, JSON_C_TO_STRING_PRETTY);
            // printf("%s\n", json_str);
            int totalNum = json_object_array_length(udiskFileObj);
            Udiskfile_count = totalNum;
            for (int i = 0; i < totalNum; i++) 
            {
                json_object *elem = json_object_array_get_idx(udiskFileObj, i);
                int type = json_object_get_int(json_object_object_get(elem, "type"));
                if(type == 4) {
                    struct stat buf = {0};
                    char *dir_name = json_object_get_string(json_object_object_get(elem, "name"));
                    char *path = json_object_get_string(json_object_object_get(elem, "path"));
                    stat(path, &buf);
                    time_t timesteamp = buf.st_ctime; //gcode 文件导入时间
                    struct tm *CurTime = localtime(&timesteamp);

                    char timepath[20] = {0};
                    snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d %02d:%02d",
                                        CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
                                        CurTime->tm_hour, CurTime->tm_min);
                    // printf("timepath : %s\n", timepath);
                    
                    ShowPartDirInfo(Gfilepanel[i], dir_name, timepath, i, true);
                
                }
                if(type == 8) {
                    // 文件名
                    char *name = json_object_get_string(json_object_object_get(elem, "name"));
                    strncpy(GcodeInfo.name, name, sizeof(GcodeInfo.name));
                    // GcodeInfo.dir_create_time = (uint64_t)json_object_get_int64(json_object_object_get(elem, "create_time"));
                    // 打印使用时间
                    GcodeInfo.totle_time = json_object_get_int(json_object_object_get(elem, "timeCost"));
                    // 使用耗材长度 
                    GcodeInfo.mater_used = json_object_get_int(json_object_object_get(elem, "consumables")); 
                    // 材料类型
                    char *material = json_object_get_string(json_object_object_get(elem, "material")); 
                    if (material != NULL) {
                        strncpy(GcodeInfo.filament_type, material, sizeof(GcodeInfo.filament_type)); 
                    }
                    // 喷嘴温度
                    GcodeInfo.nozzle_temp = json_object_get_int(json_object_object_get(elem, "nozzleTemp")); 
                    // 热床温度
                    GcodeInfo.bed_temp = json_object_get_int(json_object_object_get(elem, "bedTemp")); 
                    // 缩略图地址
                    char *mode_thumbnail = json_object_get_string(json_object_object_get(elem, "thumbnail")); 
                    if (mode_thumbnail != NULL) {
                        strncpy(GcodeInfo.mode_thumbnail, mode_thumbnail, sizeof(GcodeInfo.mode_thumbnail));
                    }
                    GcodeInfo.is_udisk = true;
                    GcodeInfo.dirent_index = i;
                    //CrLogI
                    // printf("the %d file content: filename:%s, fileCreatTime:%lld, totletime:%d, mater_used:%d, material:%s, nozzle_temp:%d, bedtemp:%d, thumbnail:%s", 
                    //         i, GcodeInfo.name, GcodeInfo.dir_create_time, GcodeInfo.totle_time, GcodeInfo.mater_used, GcodeInfo.filament_type, 
                    //         GcodeInfo.nozzle_temp, GcodeInfo.bed_temp, GcodeInfo.mode_thumbnail);
                    ShowPartGcodefileInfo(Gfilepanel[i], &GcodeInfo);     
                }       
            }
            CrLogI("finish parse udisk gcode gson file.");
            json_object_put(udiskFileObj);
        }
        else CrLogW("read json object fail\n");
    }
    else CrLogI("no udisk gcode file\n");
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {dirent} *entry
 */
static int FindDirAndGcode(const struct dirent *entry)
{
    if ((entry->d_type != 4 && entry->d_type != 8) ||
        strcmp(".", entry->d_name) == 0 ||
        strcmp("..", entry->d_name) == 0 ||
        entry->d_name[0] == '.' ||
        (entry->d_type == 4 && strstr(entry->d_name, "System Volume Information")) ||
        (entry->d_type == 8 && strlen(entry->d_name) < strlen(".gcode")) || 
        (entry->d_type == 8 && strcmp(entry->d_name + (strlen(entry->d_name) - strlen(".gcode")), ".gcode")))
    {
        return 0;
    }
    return 1;
}

/**
 * @description: 监听本地 gcode gson文件信息解析
 * @return {*}
 * @param {char} *localPath
 */
void MonitorLocalDirectory(char *localPath)
{
   // if (access(uDiskPath, F_OK) != 0) return;
    if (access(GetUserLocalGcodeFileInfoPtah(), F_OK) != 0) return;
    if(lv_scr_act() != ui_ScreenFileManage) return;

    int count1 = 0, count2 = 0;
    struct dirent **entry_list = NULL;

    count1 = scandir(localPath, &entry_list, FindDirAndGcode, alphasort);
    
    json_object *localFileObj = json_object_from_file(GetUserLocalGcodeFileInfoPtah());
    if(localFileObj){
        int totalNum = json_object_array_length(localFileObj);
        for (size_t i = 0; i < totalNum; i++)
        {
            json_object *elem = json_object_array_get_idx(localFileObj, i);
            int type = json_object_get_int(json_object_object_get(elem, "type"));
            if(type == 4){
                count2++;
            }
            if(type == 8){
                char *preview = json_object_get_string(json_object_object_get(elem, "preview")); //根据 gcode 有效信息判定udisk/sda1 目录下文件个数
                if (preview)
                {
                    count2++;
                }
                else {
                    break;
                }
            } 
        }
        json_object_put(localFileObj);
    }
  //  printf("count1 :%d, count2 :%d, localJsonChangeParseFlag : %d\n", count1, count2,localJsonChangeParseFlag);
    if (count1 == count2 && localJsonChangeParseFlag) //
    {
        localJsonChangeParseFlag = false;
        CrLogI("start local parse gcode json");
        RunGcodeParseProcess();
    }
}

/**
 * @description: 监听U盘插入解析
 * @return {*}
 * @param {char} *uDiskPath
 */
void MonitorUdiskDirectory(char *uDiskPath)
{
    if (access(uDiskPath, F_OK) != 0) return;
    if (access(GetUserUdiskGcodeFileInfoPtah(), F_OK) != 0) return;
    if(lv_scr_act() != ui_ScreenFileManage) return;

    int count1 = 0, count2 = 0;
    struct dirent **entry_list = NULL;

    count1 = scandir(uDiskPath, &entry_list, FindDirAndGcode, alphasort);
    
    json_object *udiskFileObj = json_object_from_file(GetUserUdiskGcodeFileInfoPtah());
    if(udiskFileObj){
      //  count2 = json_object_array_length(udiskFileObj);
        int totalNum = json_object_array_length(udiskFileObj);
        for (size_t i = 0; i < totalNum; i++)
        {
            json_object *elem = json_object_array_get_idx(udiskFileObj, i);
            int type = json_object_get_int(json_object_object_get(elem, "type"));
            if(type == 4){
                count2++;
            }
            if(type == 8){
                char *preview = json_object_get_string(json_object_object_get(elem, "preview")); //根据 gcode 有效信息判定udisk/sda1 目录下文件个数
                if (preview)
                {
                    count2++;
                }
                else {
                    break;
                }
            } 
        }
        json_object_put(udiskFileObj);
    }
    
    CrLogI("count1 :%d, count2 :%d", count1, count2);
    if (count1 == count2 && udiskJsonChangeParseFlag) //
    {
        udiskJsonChangeParseFlag = false;
        CrLogI("start udisk parse gcode json");
       //ShowGcodeFileInfo(udisk_state, 1);
        RunGcodeParseProcess();
    }
}

static void wait_timerout_handle(lv_timer_t * timer)
{
    if(lv_scr_act() == ui_ScreenFileManage)
    {
        GcodePanelMemoryManager(GetFileGcodeListNum());
        CrLogI("Localfile_count : %d", Localfile_count);

        if (system_state.Udisk_state)
        {
            CrLogI("start udisk gcode fileinfo parse.");
            CrLogI("Udiskfile_count : %d", Udiskfile_count);
            UdiskGcodeFileInfoParse();
            LocalGcodeFileInfoParse();

        }
        else
        {
            CrLogI("start local gcode fileinfo parse.");
            LocalGcodeFileInfoParse();
        }  
        CrLogI("FileManage.stateValue : %d, preFileListCount :%d, GetFileGcodeListNum() :%d", FileManage.stateValue, preFileListCount, GetFileGcodeListNum());
        if(FileManage.stateValue) //二级页面导航模式
        {
            if( preFileListCount != GetFileGcodeListNum()) //列表数目发生变化重新映射编码器事件组对象
            {
                FileManagePageChangeObjs(2); 
                CrLogI("gcode file number changed remap encoder event group.");
            }     
        }
        else
        {
            LoadFileManageScreenAndObjs(false); 
        }
            
       // ui_FileListWaittimer = NULL;
        preFileListCount = GetFileGcodeListNum();
        // if (ui_FileListWaittimer)
        // {
        //     lv_timer_del(ui_FileListWaittimer);
        // }

    }

    if (!lv_obj_has_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN))
    {
        CrLogI("Screenoff is show,chage focus obj");
        ChangeFocusObjBeforePopup(ui_ButtonFileManageScreenFile);
    }
    wait_animmotion(false);
   // ui_waittimer = NULL;
}

static pthread_t showGodeList_t;

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *GcodeParseProcess(void *arg)
{
    pthread_detach(pthread_self());
    ui_pthread_mutex_lock();
    if(lv_scr_act() == ui_ScreenFileManage)
    {
        CrLogI("GcodeParseProcess...");
        lv_obj_update_layout(ui_PanelFileList);
        GcodePanelMemoryManager(GetFileGcodeListNum());
        CrLogI("Localfile_count : %d", Localfile_count);

        if (system_state.Udisk_state)
        {
            CrLogI("start udisk gcode fileinfo parse.");
            CrLogI("Udiskfile_count : %d", Udiskfile_count);
            UdiskGcodeFileInfoParse();
            LocalGcodeFileInfoParse();
        }
        else
        {
            CrLogI("start local gcode fileinfo parse.");
            LocalGcodeFileInfoParse();
        }  
        CrLogI("FileManage.stateValue : %d, preFileListCount :%d, GetFileGcodeListNum() :%d", FileManage.stateValue, preFileListCount, GetFileGcodeListNum());
        if(FileManage.stateValue) //二级页面导航模式
        {
            if (FileListNumberHasChanged()) //列表数目发生变化重新映射编码器事件组对象
            {
                GcodeListAddFocusObjs();
                CrLogI("gcode file number changed remap encoder event group.");
            }      
        }
        else
        {
            LoadFileManageScreenAndObjs(false); 
        }
        preFileListCount = GetFileGcodeListNum();
    }

    // if (!lv_obj_has_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN))
    // {
    //     CrLogI("Screenoff is show,chage focus obj");
    //     ChangeFocusObjBeforePopup(ui_ButtonFileManageScreenFile);
    // }
 
    wait_animmotion(false);
    ui_pthread_mutex_unlock();
    pthread_exit(NULL);

}

/**
 * @description: 
 * @return {*}
 */
static void RunGcodeParseProcess(void)
{
    wait_animmotion(true);
    if (!system_state.Udisk_state)
    {
        Udiskfile_count = 0;
    }

    if (!GetFileGcodeListNum()) {
        lv_obj_clear_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);//显示“空”
    }
    else {
        lv_obj_add_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);//显示“空”
    }
    
    if (!FileListNumberHasChanged()) //列表个数未发生改变，不进行解析
    {
        wait_animmotion(false);
        return;
    }
        
    int res = pthread_create(&showGodeList_t, NULL, GcodeParseProcess, NULL);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return NULL;
    }
    // if (pthread_join(showGodeList_t, NULL) != 0) {
    //     CrLogE("pthread_join GcodeParseProcess thread failed");
    // }
    if (!lv_obj_has_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN))
    {
        CrLogI("Screenoff is show,chage focus obj");
        ChangeFocusObjBeforePopup(ui_ButtonFileManageScreenFile);
    }
}


static void ShowGcodeFileInfo(bool hasUdisk, uint8_t wait_time)
{
   // if( preFileListCount = GetFileGcodeListNum())
   // GetFileGcodeListNum();
    if (!system_state.Udisk_state)
    {
        Udiskfile_count = 0;
    }

    if (!GetFileGcodeListNum())
    {
        //lv_obj_clear_flag(ui_PanelFileList, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);//显示“空”
    }
    else
    {
        lv_obj_add_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);//显示“空”
    }

    //wait_animmotion(true);
    ui_FileListWaittimer = lv_timer_create(wait_timerout_handle, 200*wait_time, NULL);
    lv_timer_set_repeat_count(ui_FileListWaittimer, 1);
    if (!lv_obj_has_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN))
    {
        CrLogI("Screenoff is show,chage focus obj");
        ChangeFocusObjBeforePopup(ui_ButtonFileManageScreenFile);
    }
}


int GetFileGcodeListNum(void)
{
    if ((access(GetUserUdiskGcodeInfoDirPtah(), F_OK)== 0 && system_state.Udisk_state)) {
    //printf("UdiskGcodeFileInfoParse.\n");
        json_object *udiskFileObj = json_object_from_file(GetUserUdiskGcodeFileInfoPtah());
        if(udiskFileObj){
            Udiskfile_count = json_object_array_length(udiskFileObj);
            json_object_put(udiskFileObj);
        }
    }
    else {
        Udiskfile_count = 0;
    }
    if (access(GetUserLocalGcodeInfoDirPtah(), F_OK) == 0) {
        json_object *localFileObj = json_object_from_file(GetUserLocalGcodeFileInfoPtah());
        if(localFileObj){
            Localfile_count = json_object_array_length(localFileObj);
            json_object_put(localFileObj);
        }
    }
   // printf("Localfile_count : %d, Udiskfile_count: %d\n", Localfile_count, Udiskfile_count);
    return Localfile_count + Udiskfile_count;
}

// u盘插入检测
void file_manage_set_u_disk_status(bool inserted)
{
    if( inserted && system_state.Udisk_state){
        udiskJsonChangeParseFlag = true;
        create_msgbox(DiskIn[get_cur_language_index()], NULL, 2000, lv_scr_act());
       // udisk_state = true;
        if(lv_scr_act() == ui_ScreenFileManage)
        {
            CrLogI("on the filemanage page,refresh the file");
           // is_local_disk = false;
           // udisk_state = true;
            wait_animmotion(true);
        }
    }
    else{
        create_msgbox(DiskOut[get_cur_language_index()], NULL, 2000, lv_scr_act());
      // udisk_state = false;
        if(lv_scr_act() == ui_ScreenFileManage){
            CrLogI("on the filemanage page,refresh the file");
            Udiskfile_count = 0;
           // preFileListCount = Localfile_count;
            //GcodePanelMemoryManager(GetFileGcodeListNum());
            // GcodePanelMemoryManager(Localfile_count);
            // LocalGcodeFileInfoParse();
            RunGcodeParseProcess();
            // if(FileManage.stateValue) //二级页面导航模式,u盘拔出后根据对列表对象数目重新建立事件组
            // {   
            //     FileManagePageChangeObjs(2); 
            //     CrLogI("gcode file number changed remap encoder event group.");   
            // }
            // else
            // {
            //     LoadFileManageScreenAndObjs(false); 
            // }
 
            if (!lv_obj_has_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN))
            {
                CrLogI("Screenoff is show,chage focus obj\n");
                ChangeFocusObjBeforePopup(ui_ButtonFileManageScreenFile);
            }
        }  
    }
}

bool FileListNumberHasChanged()
{
    // if (system_state.Udisk_state)
    // {
        if( preFileListCount != GetFileGcodeListNum()) 
            return 1;
    //}
    return 0;
}

void file_manage_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();

    if(ui_FilemanageTitleLabel)
        lv_label_set_text(ui_FilemanageTitleLabel, File[language_index]);

    char buff[30] = {0};

    if ( ui_LabelNoContentsPrompt )
        lv_label_set_text(ui_LabelNoContentsPrompt, NoContentsMsg[language_index]);

    // if ( ui_LabelCopyLocalFiles )
    // {
    //     lv_label_set_text(ui_LabelCopyLocalFiles, CopyToUSB[language_index]);
    // } 

    // if ( ui_LabelDelLocalFile )
    //     lv_label_set_text(ui_LabelDelLocalFile, Delete[language_index]);
    
    
    preview_change_language_text();
    history_change_language_text();
    sub_dir_change_language_text();
}

void refresh_copyprocess(int process, int copyto)
{
    char msgbuff[100] = {0};
    if(copyto == 2)//2是复制
    {
        if(process <= 100)
        {
            snprintf(msgbuff, 100, "%s:%d%%", CopyProcess[get_cur_language_index()], process);
            create_msgbox(msgbuff, NULL, 0, lv_layer_top());
        }
        if(process > 100)
        {
            snprintf(msgbuff, 100, "%s:%d%%", CopyProcess[get_cur_language_index()], 100);
            create_msgbox(msgbuff, NULL, 1000, lv_layer_top());
            //send_get_root_dir_file_count_cmd(is_local_disk); 
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
            snprintf(msgbuff, 100, "%s:%d%%", Delete[get_cur_language_index()], process);
            create_msgbox(msgbuff, NULL, 0, lv_layer_top());
        }
        if(process >= 100)
        {
            snprintf(msgbuff, 100, "%s:%d%%", Delete[get_cur_language_index()], 100);
            create_msgbox(msgbuff, NULL, 1000, lv_layer_top());
            //wait_animmotion(true); 
        }
        if(process == -1)
        {
            snprintf(msgbuff, 256, "%s", CopyErrorResult[get_cur_language_index()]);
            create_msgbox(msgbuff, NULL, 1000, lv_layer_top());
        }
    }
}

void filemanage_page_refresh_laserstate(int laser_state)
{
    if(laser_state)
        lv_obj_clear_flag(ui_ImageLaserState, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageLaserState, LV_OBJ_FLAG_HIDDEN);
}

void filemanage_page_refresh_camerastate(int camera_state)
{
    if(camera_state)
        lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
}

void filemanage_page_set_wifi_status(int intensity)
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

bool get_is_local_disk()
{
    return is_local_disk;
}

void set_is_local_disk(bool state)
{
    is_local_disk = state;
}


void LoadFileManageScreenAndObjs(bool IsEntered)
{
    FileManage.stateValue = IsEntered;
   // ScreenStatusValue = IsEntered;
    if(FileManage.stateValue == 0) //一级页面导航模式
    {
        LoadPage(ui_ScreenFileManage, 1);
        lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenFile, &ui_img_pagefilemanage_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_group_focus_cycle(encoder_group, true);
    }
    else //二级页面导航模式
    {    
        LoadPage(ui_ScreenFileManage, 2);
        // if(lv_group_get_focused(encoder_group) == ui_ButtonFileManageScreenFile)
        // {
        //     lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenFile, &ui_img_pagefilemanagefocus_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        // }
        // else
        // {
        //     lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenFile, &ui_img_pagefilemanageselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        // } 
        lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenFile, &ui_img_pagefilemanageselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_group_focus_cycle(encoder_group, false);
    }
}

static void FileActionPageAddFocusObjs(void)
{
    lv_group_remove_all_objs(encoder_group);
    for (int i = 0; i < 3; i++)
    {
        lv_group_add_obj(encoder_group, FileActionMessage.btn[i].btn);
    } 
}

static void GcodeListAddFocusObjs(void)
{   
    int cnt = lv_obj_get_child_cnt(ui_PanelFileList);
    for (size_t i = 0; i < cnt; i++)
    {
        // if (Gfilepanel != NULL)
        //     lv_group_add_obj(encoder_group,  Gfilepanel[i]->part_panel);
        lv_group_add_obj(encoder_group, lv_obj_get_child(ui_PanelFileList, i));
    }
}

static void FileManagePageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    // lv_indev_set_group(enc_indev, NULL); 
    // lv_indev_set_group(enc_indev, encoder_group); //关联组
    PageNode *fileManage_node = find_page(ui_ScreenFileManage);
    fileManage_node->nav_level = index;

    switch (index)
    {
    case 1: //1级事件组
        // page_manager.objFreezzFlag = false;
        lv_group_add_obj(encoder_group, ui_ButtonFileManageScreenFile);
        lv_group_add_obj(encoder_group, ui_ButtonSettingsScreenFile);
        lv_group_add_obj(encoder_group, ui_ButtonReserveScreenFile);
        lv_group_add_obj(encoder_group, ui_ButtonHomeScreenFile);
        lv_group_add_obj(encoder_group, ui_ButtonAxisMoveScreenFile);
        break;
    case 2: //2级事件组
        // page_manager.objFreezzFlag = false;
        lv_group_add_obj(encoder_group, ui_ButtonFileManageScreenFile);
        CrLogI("add gcode file list to envent group.");
        // if (!FileListNumberHasChanged()) //此处只添加固定列表父类到事件组，若列表数发生改变在列表重新建立后 GcodeParseProcess 会添加GcodeListAddFocusObjs();重新映射事件组对象
        // {
        GcodeListAddFocusObjs();
       // }
        break;
    case 3: //3级事件组
        if (Add3rLeveldObjsCb)
        {
            Add3rLeveldObjsCb();
        }
        break;
    default:
        break;
    }

}