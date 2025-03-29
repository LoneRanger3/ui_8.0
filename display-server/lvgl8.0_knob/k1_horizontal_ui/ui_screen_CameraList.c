/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-06 16:20:41
 * @LastEditTime: 2023-10-22 23:43:17
 */
#include "ui_screen_CameraList.h"
#include "page_switch.h"
#include "src/core/lv_obj.h"
#include "src/core/lv_obj_pos.h"
#include "src/misc/lv_area.h"
#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>
#include "ui_screen_VedioInfo.h"
#include "custom/lvgl_cmd.h"
#include "ui_custom_reminderbox.h"
#include "ui_custom_vedioinfo_part.h"
#include "mult_language.h"

lv_obj_t * ui_Cameralist;
/**************left panel*******************/
static lv_obj_t * ui_CameralistPanel1;
static lv_obj_t * ui_CameralistImage1;
static lv_obj_t * ui_CameralistImage2;
static lv_obj_t * ui_CameralistImage3;
static lv_obj_t * ui_CameralistImage4;
static lv_obj_t * ui_CameralistImage5;

/****************right panel**************/
static lv_obj_t * ui_PanelCameralist;
static lv_obj_t * ui_PanelCenterCameralist;
static lv_obj_t * ui_Cameralisttitle;
static lv_obj_t * ui_PanelLineCameralist;

#if 0
static lv_obj_t * ui_CameravedioList1;
static lv_obj_t * ui_CameralistLabel2;
static lv_obj_t * ui_CameralistImage6;
static lv_obj_t * ui_CameralistLabel3;
static lv_obj_t * ui_CameralistLabel4;
static lv_obj_t * ui_CameralistImage7;
static lv_obj_t * ui_CameravedioList2;
static lv_obj_t * ui_CameralistLabel5;
static lv_obj_t * ui_CameralistImage8;
static lv_obj_t * ui_CameralistLabel6;
static lv_obj_t * ui_CameralistLabel7;
static lv_obj_t * ui_CameralistImage9;
static lv_obj_t * ui_CameravedioList3;
static lv_obj_t * ui_CameralistLabel8;
static lv_obj_t * ui_CameralistImage10;
static lv_obj_t * ui_CameralistLabel9;
static lv_obj_t * ui_CameralistLabel10;
static lv_obj_t * ui_CameralistImage11;
#endif

static lv_obj_t * ui_CameralistButtonBack;
static lv_obj_t * ui_LabelNoContentsPrompt;

/***************custom variable************************/
static uint16_t vedioes_count = 0;
static uint16_t cur_page_vedio_start_index = 0;
static vedio_info_part_t *part_array[3] = {NULL};
static vedio_info_part_t **VedioePart = NULL;

/*****************************************/

static void ui_event_CameralistButtonBack_click(lv_event_t * e);
static void ui_event_jump_list(lv_event_t * e);

/*******************custom funs**************************/
static void get_next_page(void);
static void get_prev_page(void);
static void VideoFilesInfoParse(void);
static uint16_t GetVedioListsCount(void);
static void VedioPanelMemoryManager(uint16_t file_number);
static void VedioListPageChangeObjs(uint8_t index);
static void LoadVedioListPage(void);
/***********************************************/

void ui_event_CameralistButtonBack_click(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        BackPrepage(false);
        //_ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_jump_list(lv_event_t * e)
{
    // lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    lv_indev_wait_release(lv_indev_get_act());
    lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
    if(dir == LV_DIR_BOTTOM) {
        get_prev_page();
    }
    else if ( dir == LV_DIR_TOP)
    {
        get_next_page();
    }
}

void ui_event_changepage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(target == ui_CameralistImage1)
        {
            if ( home_printing_is_printing_finished() )
                LoadHomeNormalScreen();
            else
                LoadHomePrintingScreen();
        }
        if(target == ui_CameralistImage2)LoadAxisMoveScreen();
        if(target == ui_CameralistImage3)LoadFileManageScreen();
        if(target == ui_CameralistImage4)LoadSettingsScreen();
        if(target == ui_CameralistImage5)LoadCustomerServiceScreen();
    }
}

void ui_event_loadcurpage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        VedioPanelMemoryManager(GetVedioListsCount());
        if (!vedioes_count) {
            lv_obj_clear_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);
        }
        else {
            VideoFilesInfoParse();
            lv_obj_add_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void ui_event_CameravedioList(lv_event_t * e)
{
    static uint16_t preId = 0; 

    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    vedio_info_part_t *part = lv_event_get_user_data(e);
    int id = lv_obj_get_child_id(target);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(ui_VedioInfo, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        LoadPage(ui_VedioInfo, 0);
        part_clicked(part);
    }
    // if(event_code == LV_EVENT_FOCUSED) {
    //     if (id && id > preId)
    //     {
    //         printf("右旋\n");
    //         // if(get_is_local_disk() == true && id % 3 == 0) {
                

    //         // }
    //     }
    //     else if (id && id < preId )
    //     {
    //         // if(get_is_local_disk() == false) {
                
    //         // }
            
    //         printf("左旋\n");
    //     }
    //     preId = id;
    //     printf("id : %d\n", id);
    // }
}

void ui_Cameralist_screen_init(void)
{
    ui_Cameralist = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Cameralist, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Cameralist, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Cameralist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_Cameralist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    init_pages(ui_Cameralist, VedioListPageChangeObjs, LoadVedioListPage);
    /****************left panel**************/
    uint8_t language_index = get_cur_language_index();
    ui_CameralistPanel1 = lv_obj_create(ui_Cameralist);
    lv_obj_set_width(ui_CameralistPanel1, 68);
    lv_obj_set_height(ui_CameralistPanel1, 360);
    lv_obj_set_pos(ui_CameralistPanel1, 0, 60);
    lv_obj_clear_flag(ui_CameralistPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistPanel1, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CameralistPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CameralistPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CameralistPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CameralistPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_CameralistImage1 = lv_img_create(ui_CameralistPanel1);
    lv_img_set_src(ui_CameralistImage1, &ui_img_pagehome_png);
    lv_obj_set_size(ui_CameralistImage1, 68, 72);
    lv_obj_set_pos(ui_CameralistImage1, 0, 0);
    lv_obj_add_flag(ui_CameralistImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CameralistImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistImage1, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_CameralistImage2 = lv_img_create(ui_CameralistPanel1);
    lv_img_set_src(ui_CameralistImage2, &ui_img_pagemove_png);
    lv_obj_set_size(ui_CameralistImage2, 68, 72);
    lv_obj_set_pos(ui_CameralistImage2, 0, 72);
    lv_obj_add_flag(ui_CameralistImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CameralistImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistImage2, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_CameralistImage3 = lv_img_create(ui_CameralistPanel1);
    lv_img_set_src(ui_CameralistImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_size(ui_CameralistImage3, 68, 72);
    lv_obj_set_pos(ui_CameralistImage3, 0, 144);
    lv_obj_add_flag(ui_CameralistImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CameralistImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistImage3, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_CameralistImage4 = lv_img_create(ui_CameralistPanel1);
    lv_img_set_src(ui_CameralistImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_size(ui_CameralistImage4, 68, 72);
    lv_obj_set_pos(ui_CameralistImage4, 0, 216);
    lv_obj_add_flag(ui_CameralistImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CameralistImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistImage4, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_CameralistImage5 = lv_img_create(ui_CameralistPanel1);
    lv_img_set_src(ui_CameralistImage5, &ui_img_pagereserve_png);
    lv_obj_set_size(ui_CameralistImage5, 68, 72);
    lv_obj_set_pos(ui_CameralistImage5, 0, 288);
    lv_obj_add_flag(ui_CameralistImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CameralistImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistImage5, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    /****************right panel**************/
    ui_PanelCameralist = lv_obj_create(ui_Cameralist);
    lv_obj_set_pos(ui_PanelCameralist, 73, 68);
    lv_obj_set_size(ui_PanelCameralist, 556, 344); 
    lv_obj_clear_flag(ui_PanelCameralist, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCameralist, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCameralist, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCameralist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCameralist, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelCameralist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    ui_PanelCenterCameralist = lv_obj_create(ui_PanelCameralist);
    lv_obj_set_pos(ui_PanelCenterCameralist, -1, 59);
    lv_obj_set_size(ui_PanelCenterCameralist, 556, 284); 
    lv_obj_add_flag(ui_PanelCenterCameralist, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCenterCameralist, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCenterCameralist, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCenterCameralist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCenterCameralist, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelCenterCameralist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_PanelCenterCameralist, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_left(ui_PanelCenterCameralist, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_PanelCenterCameralist, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Cameralisttitle = lv_label_create(ui_PanelCameralist);
    lv_obj_set_size(ui_Cameralisttitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_Cameralisttitle, 16, 0);
    lv_label_set_text(ui_Cameralisttitle, VedioList[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_Cameralisttitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Cameralisttitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Cameralisttitle, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_PanelLineCameralist = lv_obj_create(ui_PanelCameralist);
    lv_obj_set_size(ui_PanelLineCameralist, 543, 1);
    lv_obj_set_pos(ui_PanelLineCameralist, 7, 49);
    lv_obj_clear_flag(ui_PanelLineCameralist, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelLineCameralist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelLineCameralist, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLineCameralist, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLineCameralist, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    // int8_t index = 0;
    // part_array[index++] = create_custom_vedio_info_part(ui_PanelCenterCameralist, 11, 0,  ui_event_CameravedioList);
    // part_array[index++] = create_custom_vedio_info_part(ui_PanelCenterCameralist, 11, 96, ui_event_CameravedioList);
    // part_array[index++] = create_custom_vedio_info_part(ui_PanelCenterCameralist, 11, 192, ui_event_CameravedioList);  
    
    ui_CameralistButtonBack = lv_btn_create(ui_PanelCameralist);
    lv_obj_set_size(ui_CameralistButtonBack, 68, 38);
    lv_obj_set_pos(ui_CameralistButtonBack, 474, 6);
    lv_obj_add_flag(ui_CameralistButtonBack, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_CameralistButtonBack, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CameralistButtonBack, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CameralistButtonBack, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CameralistButtonBack, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CameralistButtonBack, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistButtonBack, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_CameralistButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_CameralistButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_CameralistButtonBack, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CameralistButtonBack, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_CameralistButtonBack, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_CameralistButtonBack, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_CameralistButtonBack, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_CameralistButtonBack, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_CameralistButtonBack, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    
    // "空"
    ui_LabelNoContentsPrompt = lv_label_create(ui_PanelCameralist);
    lv_obj_set_size(ui_LabelNoContentsPrompt, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_LabelNoContentsPrompt, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelNoContentsPrompt, NoContentsMsg[language_index]);
    lv_obj_add_flag(ui_LabelNoContentsPrompt, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_LabelNoContentsPrompt, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelNoContentsPrompt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelNoContentsPrompt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelNoContentsPrompt, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LabelNoContentsPrompt, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_style_pad_all(ui_LabelNoContentsPrompt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_CameralistButtonBack, ui_event_CameralistButtonBack_click, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Cameralist, ui_event_jump_list, LV_EVENT_GESTURE, NULL);
    
    lv_obj_add_flag(ui_CameralistImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CameralistImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CameralistImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CameralistImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CameralistImage5, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    
    lv_obj_add_event_cb(ui_CameralistImage1, ui_event_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CameralistImage2, ui_event_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CameralistImage3, ui_event_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CameralistImage4, ui_event_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CameralistImage5, ui_event_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Cameralist, ui_event_loadcurpage, LV_EVENT_ALL, NULL);
}

/**
 * @description: 根据gcode的文件数动态管理内存
 * @return {*}
 * @param {uint16_t} file_number
 */
void VedioPanelMemoryManager(uint16_t file_number)
{
    static uint16_t preFileNum = 0;
    static int ui_PanelFileListY = 0;
    vedio_info_part_t **NewVediopanel = NULL;
    
    if (preFileNum == 0)
    {
        VedioePart = (vedio_info_part_t **)malloc(file_number*sizeof(vedio_info_part_t *));
        if (VedioePart != NULL)
        {
            for (size_t i = preFileNum; i < file_number; i++)
            {
                VedioePart[i] = create_custom_vedio_info_part(ui_PanelCenterCameralist, ui_event_CameravedioList);  
            }
        }
    }  
    else if (file_number > preFileNum)
    {
        NewVediopanel = (vedio_info_part_t **)realloc(VedioePart, file_number*sizeof(vedio_info_part_t *));
        if (VedioePart != NULL)
        {
            VedioePart = NewVediopanel;
            for (size_t i = preFileNum; i < file_number; i++)
            {
                //printf("file_index: %d, ui_PanelFileListY:%d\n", i, ui_PanelFileListY);
                VedioePart[i] = create_custom_vedio_info_part(ui_PanelCenterCameralist, ui_event_CameravedioList);
                //ui_PanelFileListY += 100; 
                //printf("VedioePart[%d]:%p\n", i, VedioePart[i]);
            }
           // memcpy(NewVediopanel, VedioePart, preFileNum * sizeof(vedio_info_part_t *));
          //  free(VedioePart); 
          //  VedioePart = NULL;  
        }
      
    }
    else if (file_number < preFileNum)
    {

        NewVediopanel = (vedio_info_part_t **)malloc(file_number*sizeof(vedio_info_part_t *));
        
        for (size_t i = file_number; i < preFileNum; i++) //释放退出面板对象占用空间
        {
            lv_obj_del(VedioePart[i]->info_panel); 
            lv_mem_free(VedioePart[i]);
        }
        if (VedioePart != NULL) {
             memcpy(NewVediopanel, VedioePart, file_number * sizeof(vedio_info_part_t *));
             free(VedioePart);
             VedioePart = NULL;
        }
        VedioePart = NewVediopanel;
        
    }
    CrLogI("VedioePartMemoryManager");
    preFileNum = file_number;
}

uint16_t GetVedioListsCount(void)
{
    if (access(GetUserDelayImageInfoPtah(), F_OK) == 0) {
        json_object *vedioesObj = json_object_from_file(GetUserDelayImageInfoPtah());
        json_object *listObj = json_object_object_get(vedioesObj, "list");
        if(listObj)
        {
            vedioes_count = json_object_array_length(listObj);
        }
    }
    CrLogI("vedioes_count:%d", vedioes_count);
    return vedioes_count;
}

void VideoFilesInfoParse()
{
    print_vedio_info_t VedioInfo;
    
    // 判断延时摄影是否存在，读取文件，获取json数据
    if (access(GetUserDelayImageInfoPtah(), F_OK) != 0)
    {
        CrLogW("no delay image\n");
        return;
    }
    json_object *delayImage = json_object_from_file(GetUserDelayImageInfoPtah());
    if (!delayImage) {
        CrLogW("read json object fail\n");
        return;
    }
    // 提取延时摄影列表
    json_object *listObj = json_object_object_get(delayImage, "list");
    if(listObj)
    {
        int imageSize = json_object_array_length(listObj);
        CrLogI("imageSize = %d\n", imageSize);
        int starti = 0;
        int endi = imageSize;
        // 循环提取记录
        for (int i = starti; i < endi; i++)
        {
            json_object *image = json_object_array_get_idx(listObj, i);
            // 文件名
            const char *filePath = json_object_get_string(json_object_object_get(image, "video"));
            if(filePath)
            {
                strncpy(VedioInfo.vedio_name, filePath, sizeof(VedioInfo.vedio_name));
                CrLogI("filePath:%s", filePath);
            }

            // time_t t = 0;
            // 开始打印时间
            uint64_t starttime = (uint64_t)json_object_get_int64(json_object_object_get(image, "starttime")); 
            //struct tm* timeinfo1 = localtime(&starttime);
           // char buffer1[80]={0};
           // strftime(buffer1, 80, "%Y-%m-%d_%H-%M-%S", timeinfo1);  
            VedioInfo.print_datetime = starttime;
            CrLogI("starttime:%ld", starttime);   
            // 打印使用时间
            uint64_t printtime = (uint64_t)json_object_get_int64(json_object_object_get(image, "printtime"));
            // struct tm* timeinfo2 = localtime(&printtime);
            // char buffer2[80]={0};
            // strftime(buffer2, 80, "%Y-%m-%d_%H-%M-%S", timeinfo2);   
            VedioInfo.used_time = printtime;
            CrLogI("printtime:%ld", printtime);   
            // 视频时长
            uint32_t duration = json_object_get_int(json_object_object_get(image, "duration"));
            VedioInfo.vedio_total_time = duration;
            CrLogI("duration:%d", duration);   
            // 喷嘴位置
            int location = json_object_get_int(json_object_object_get(image, "location"));
            VedioInfo.shoot_pos = location;
            CrLogI("location:%d", location);   
            // 拍摄间隔
            int interval = json_object_get_int(json_object_object_get(image, "interval"));
            CrLogI("interval:%d", interval);   
            // 渲染帧数
            int render = json_object_get_int(json_object_object_get(image, "render"));
            VedioInfo.render_photoes = render;
            CrLogI("render:%d", render);   
            // 图片地址
            const char *cover = json_object_get_string(json_object_object_get(image, "cover"));
            if (cover)
            {
                strncpy(VedioInfo.vedio_img_name, cover, sizeof(VedioInfo.vedio_img_name));
                CrLogI("cover:%s", cover);   
            }
            
            vedio_info_part_set_vedioes_info(VedioePart[i], &VedioInfo, i+1);
        }
    }
    json_object_put(delayImage);     
}

void get_next_page(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( !vedioes_count )
    {
        create_custom_reminderbox(NoVedioes[language_index], false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return;
    }

    if ( cur_page_vedio_start_index >= vedioes_count )
    {
        create_custom_reminderbox(LastPageMsg[language_index], false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return ;
    }

    cur_page_vedio_start_index += MAX_VEDIO_INFOS_PER_PAGE;
    send_get_vedio_infos_cmd(cur_page_vedio_start_index, MAX_VEDIO_INFOS_PER_PAGE);
}

void get_prev_page(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( !vedioes_count )
    {
        create_custom_reminderbox(NoVedioes[language_index], false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return;
    }

    if ( cur_page_vedio_start_index <= 1 )
    {
        create_custom_reminderbox(FirstPageMsg[language_index], false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return ;
    }

    cur_page_vedio_start_index -= MAX_VEDIO_INFOS_PER_PAGE;
    if ( cur_page_vedio_start_index < 1 )
        cur_page_vedio_start_index = 1;

    send_get_vedio_infos_cmd(cur_page_vedio_start_index, MAX_VEDIO_INFOS_PER_PAGE);
}

/**
 * @description: 刷新视频列表数目
 * @return {*}
 * @param {uint16_t} count
 */
void cameralist_set_vedio_count(uint16_t count)
{
#if 0 //旧协议
    vedioes_count = count;
    if ( !count )
    {
        vedioes_count = 0;
        cur_page_vedio_start_index = 0;
        //
        cameralist_set_vedioes_info(NULL, 1); //vedioes_count 数量为0 传入NULL, 隐藏所有视频列表面板

        return;
    }

    cur_page_vedio_start_index = 1;
    send_get_vedio_infos_cmd(cur_page_vedio_start_index, MAX_VEDIO_INFOS_PER_PAGE);
#endif
}

/**
 * @description: 刷新显示视频列表信息
 * @return {*}
 * @param {print_vedio_info_t} info_array
 * @param {int} real_count
 */
void cameralist_set_vedioes_info(print_vedio_info_t info_array[3], int real_count)
{
    if ( !info_array || real_count < 0)
        real_count = 0;
#if 0 //旧协议
    for ( int i = 0; i < 3 ; i++ )
    {
        if ( !part_array[i] || !(part_array[i]->info_panel) )
            continue;

        if ( (i < real_count) ) //每页3个视频文件，在固定的三个面板上显示，若每次发送请求的视频文件命令后返回的数目real_count 小于3，剩余的面板则隐藏
        {
            lv_obj_clear_flag(part_array[i]->info_panel, LV_OBJ_FLAG_HIDDEN);
            vedio_info_part_set_vedioes_info(part_array[i], &info_array[i], cur_page_vedio_start_index + i);
        }
        else 
        {
            lv_obj_add_flag(part_array[i]->info_panel, LV_OBJ_FLAG_HIDDEN);
        }
    }
#endif 
}

void cameralist_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    // if ( ui_CameralistBtnlabel_Back )
    // {
    //     lv_label_set_text(ui_CameralistBtnlabel_Back, Back[language_index]);
    //     redefine_label_size(ui_CameralistBtnlabel_Back, lv_font24.font, 0, 0, 300, 0);
        
    //     lv_obj_update_layout(ui_CameralistButtonBack);
    //     redefine_widgets_size(ui_CameralistButtonBack, ui_CameralistBtnlabel_Back, 10, 0, 116, 60);
    // }
    
    if ( ui_Cameralisttitle )
        lv_label_set_text(ui_Cameralisttitle, VedioList[language_index]);
    
    for ( int8_t i = 0; i < vedioes_count; i++ )
        vedio_info_change_language_text(VedioePart[i]);

    if (ui_LabelNoContentsPrompt)
    {
        lv_label_set_text(ui_LabelNoContentsPrompt, NoContentsMsg[language_index]);
    }

    vedio_change_language_text();
}

static void LoadVedioListPage()
{
     _ui_screen_change(ui_Cameralist, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

static void VedioListPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *VedioList_node = find_page(ui_Cameralist);
    VedioList_node->nav_level = index;
  
    lv_group_add_obj(encoder_group, ui_CameralistButtonBack);
    for (size_t i = 0; i < vedioes_count; i++)
    {
        if (VedioePart != NULL)
            lv_group_add_obj(encoder_group,  VedioePart[i]->info_panel);
    }
}
