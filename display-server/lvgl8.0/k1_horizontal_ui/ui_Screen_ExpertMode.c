/*
 * @Date         : 2023-08-16 13:56:03
 * @LastEditors  : fangjinlun fangjinlun@creality.com
 * @LastEditTime : 2023-08-18 15:24:07
 */

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "./custom/CrlogDef.h"
#include "ui_screen_CameraList.h"
#include "custom/lvgl_cmd.h"
#include "ui_Screen_ExpertMode.h"
#include "mult_language.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_ExpertModePage;
lv_obj_t * ui_ExpertMode_navi_obj;
lv_obj_t * ui_PageImage1;
lv_obj_t * ui_PageImage2;
lv_obj_t * ui_PageImage3;
lv_obj_t * ui_PageImage4;
lv_obj_t * ui_PageImage5;
lv_obj_t * ui_ExpertMode;
lv_obj_t * ui_ExpertMode_bg;
lv_obj_t * ui_ExpertMode_title_label;
lv_obj_t * ui_ExpertMode_line_obj;
lv_obj_t * ui_ExpertMode_obj;
lv_obj_t * ui_ExpertMode_return_btn;
lv_obj_t * ui_ExpertMode_return_label;
///////////////////// VARIABLES ////////////////////

///////////////////// FUNCTIONS ////////////////////

void ui_event_ExpertMode_return_btn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        ui_change(PAGE_SETING);
    }
}

void ui_event_SubPageChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        switch (atoi(userdata))
        {
            case SubPageZOffset:ui_DiapScreenZoffsetPage();break;
            case SubPageFlowSet:ui_DiapScreenTrafficPage();break;
            case SubPageBedLevel:get_printer_data(0x09, 2, "7");ui_DiapScreenAutoLevelPage();break;
            case SubPageNozzlePID:ui_DiapScreenHotPidPage(0);break;
            case SubPageBedPID:ui_DiapScreenBedPidPage(0);break;
            default:break;
        }
    }
}

void ui_event_FlowAdjust_obj(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        // ui_DiapScreenTrafficPage();
    }
}

void ui_event_NozzlePidAdjust_obj(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        // ui_DiapScreenHotPidPage(0);
    }
}

void ui_event_BedPidAdjust_obj(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        // ui_DiapScreenBedPidPage(0);
    }
}

void ui_event_BedMeshAdjust_obj(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        get_printer_data(0x09, 2, "7");
        // lv_obj_clear_flag(ui_BedMesh,LV_OBJ_FLAG_HIDDEN);
        
    }
}

void ui_event_PageHandle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        switch(atoi(userdata))
        {
            case PAGE_HOME:home_printing_is_printing_finished() ? ui_change(PAGE_HOME) : ui_change(PAGE_HOME_PRINT);break;
            case PAGE_AXIS:ui_change(PAGE_AXIS);break;
            case PAGE_FILEMANAGE:ui_change(PAGE_FILEMANAGE);break;
            case PAGE_SETING:ui_change(PAGE_SETING);break;
            case PAGE_HELP:ui_change(PAGE_HELP);break;
            default:break;
        }
    }
}


///////////////////// FUNCTIONS ////////////////////

lv_obj_t* ui_add_item(lv_obj_t* parent, const char* text, lv_event_cb_t event_cb,  void * user_data)
{
    lv_obj_t* item_obj = lv_obj_create(parent);
    lv_obj_set_width(item_obj, 685);
    lv_obj_set_height(item_obj, 75);
    lv_obj_clear_flag(item_obj, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(item_obj, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(item_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(item_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(item_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(item_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(item_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(item_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(item_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(item_obj, event_cb, LV_EVENT_CLICKED, user_data);

    lv_obj_t* item_img = lv_img_create(item_obj);
    lv_img_set_src(item_img, &ui_img_vector_24_png);
    lv_obj_set_width(item_img, 14);
    lv_obj_set_height(item_img, 28);
    lv_obj_set_x(item_img, -25);
    lv_obj_set_y(item_img, 0);
    lv_obj_set_align(item_img, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(item_img, LV_OBJ_FLAG_ADV_HITTEST);     
    lv_obj_clear_flag(item_img, LV_OBJ_FLAG_SCROLLABLE);     
    lv_obj_add_flag(item_img, LV_OBJ_FLAG_CLICKABLE);  

    lv_obj_t* item_label = lv_label_create(item_obj);
    lv_obj_set_width(item_label, 500);
    lv_obj_set_height(item_label, 24);
    lv_obj_set_x(item_label, 24);
    lv_obj_set_y(item_label, 0);
    lv_obj_set_align(item_label, LV_ALIGN_LEFT_MID);
    lv_label_set_text(item_label, text);
    lv_obj_set_style_text_color(item_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(item_label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(item_label, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(item_label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    return item_obj;
}


void ui_Expert_mode_screen_init(void)
{
    uint8_t language_index = get_cur_language_index();
    ui_ExpertModePage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ExpertModePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ExpertMode = lv_obj_create(ui_ExpertModePage);
    lv_obj_set_size(ui_ExpertMode, 720,480);
    lv_obj_align(ui_ExpertMode,LV_ALIGN_RIGHT_MID,0,0);
    lv_obj_clear_flag(ui_ExpertMode, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ExpertMode, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExpertMode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExpertMode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_ExpertMode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ExpertMode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ExpertMode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExpertMode_navi_obj = lv_obj_create(ui_ExpertModePage);
    lv_obj_set_size(ui_ExpertMode_navi_obj, 80,480);
    lv_obj_align(ui_ExpertMode_navi_obj,LV_ALIGN_TOP_LEFT,0,0);
    lv_obj_clear_flag(ui_ExpertMode_navi_obj, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ExpertMode_navi_obj, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExpertMode_navi_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_ExpertMode_navi_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ExpertMode_navi_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ExpertMode_navi_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_ExpertMode_navi_obj, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ExpertMode_navi_obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_obj_set_style_pad_column(ui_ExpertMode_navi_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PageImage1 = lv_img_create(ui_ExpertMode_navi_obj);
    lv_img_set_src(ui_PageImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_PageImage1, 80);
    lv_obj_set_height(ui_PageImage1, 96);
    lv_obj_add_flag(ui_PageImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_PageImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PageImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PageImage2 = lv_img_create(ui_ExpertMode_navi_obj);
    lv_img_set_src(ui_PageImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_PageImage2, 80);
    lv_obj_set_height(ui_PageImage2, 96);
    lv_obj_add_flag(ui_PageImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_PageImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PageImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PageImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PageImage3 = lv_img_create(ui_ExpertMode_navi_obj);
    lv_img_set_src(ui_PageImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_PageImage3, 80);
    lv_obj_set_height(ui_PageImage3, 96);
    lv_obj_add_flag(ui_PageImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_PageImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PageImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PageImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PageImage4 = lv_img_create(ui_ExpertMode_navi_obj);
    lv_img_set_src(ui_PageImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_PageImage4, 80);
    lv_obj_set_height(ui_PageImage4, 96);
    lv_obj_add_flag(ui_PageImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_PageImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PageImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PageImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PageImage5 = lv_img_create(ui_ExpertMode_navi_obj);
    lv_img_set_src(ui_PageImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_PageImage5, 80);
    lv_obj_set_height(ui_PageImage5, 96);
    lv_obj_add_flag(ui_PageImage5, LV_OBJ_FLAG_CLICKABLE );     /// Flags
    lv_obj_clear_flag(ui_PageImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PageImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PageImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_PageImage1, ui_event_PageHandle, LV_EVENT_CLICKED, "0");
    lv_obj_add_event_cb(ui_PageImage2, ui_event_PageHandle, LV_EVENT_CLICKED, "2");
    lv_obj_add_event_cb(ui_PageImage3, ui_event_PageHandle, LV_EVENT_CLICKED, "3");
    lv_obj_add_event_cb(ui_PageImage4, ui_event_PageHandle, LV_EVENT_CLICKED, "4");
    lv_obj_add_event_cb(ui_PageImage5, ui_event_PageHandle, LV_EVENT_CLICKED, "5");

    ui_ExpertMode_bg = lv_obj_create(ui_ExpertMode);
    lv_obj_set_size(ui_ExpertMode_bg, 696,456);
    lv_obj_align(ui_ExpertMode_bg,LV_ALIGN_CENTER,0,0);
    lv_obj_clear_flag(ui_ExpertMode_bg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ExpertMode_bg, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExpertMode_bg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExpertMode_bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_ExpertMode_bg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ExpertMode_bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ExpertMode_bg, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExpertMode_title_label = lv_label_create(ui_ExpertMode_bg);
    lv_label_set_text(ui_ExpertMode_title_label, AdvancedMode[language_index]);
    lv_obj_set_size(ui_ExpertMode_title_label,LV_SIZE_CONTENT,110);
    lv_obj_set_style_text_align(ui_ExpertMode_title_label,LV_TEXT_ALIGN_LEFT,LV_PART_MAIN);
    lv_obj_align(ui_ExpertMode_title_label,LV_ALIGN_TOP_LEFT,20,20);
    lv_obj_set_style_text_color(ui_ExpertMode_title_label, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ExpertMode_title_label, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExpertMode_line_obj = lv_obj_create(ui_ExpertMode_bg);
    lv_obj_set_size(ui_ExpertMode_line_obj, 660,1);
    lv_obj_align(ui_ExpertMode_line_obj,LV_ALIGN_TOP_MID,0,65);
    lv_obj_clear_flag(ui_ExpertMode_line_obj, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ExpertMode_line_obj, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExpertMode_line_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExpertMode_line_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ExpertMode_line_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExpertMode_obj = lv_obj_create(ui_ExpertMode_bg);
    lv_obj_set_size(ui_ExpertMode_obj, 696,390);
    lv_obj_align(ui_ExpertMode_obj,LV_ALIGN_BOTTOM_MID,0,0);
    lv_obj_set_style_bg_color(ui_ExpertMode_obj, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExpertMode_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExpertMode_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(ui_ExpertMode_obj,LV_SCROLLBAR_MODE_AUTO);
    lv_obj_set_style_pad_left(ui_ExpertMode_obj,0,LV_PART_MAIN);
    lv_obj_set_style_pad_right(ui_ExpertMode_obj,0,LV_PART_MAIN);
    lv_obj_set_style_pad_row(ui_ExpertMode_obj,1,LV_PART_MAIN);
    lv_obj_set_flex_flow(ui_ExpertMode_obj, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_top(ui_ExpertMode_obj,2,LV_PART_MAIN);
    lv_obj_set_style_pad_bottom(ui_ExpertMode_obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_add_item(ui_ExpertMode_obj,Zoffset[language_index],ui_event_SubPageChange, "0");
    ui_add_item(ui_ExpertMode_obj,Flow[language_index],ui_event_SubPageChange, "1");
    ui_add_item(ui_ExpertMode_obj,BedMeshAdjust[language_index],ui_event_SubPageChange, "2");
    ui_add_item(ui_ExpertMode_obj,NozzlePidDetect[language_index],ui_event_SubPageChange, "3");
    ui_add_item(ui_ExpertMode_obj,BedPidDetect[language_index],ui_event_SubPageChange, "4");

    ui_ExpertMode_return_btn = lv_btn_create(ui_ExpertMode_obj);
    lv_obj_set_size(ui_ExpertMode_return_btn, 116, 60);
    lv_obj_set_style_pad_all(ui_ExpertMode_return_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ExpertMode_return_btn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExpertMode_return_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExpertMode_return_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ExpertMode_return_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ExpertMode_return_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ExpertMode_return_btn, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(ui_ExpertMode_return_btn,LV_ALIGN_BOTTOM_RIGHT,-18,-10);
    lv_obj_add_event_cb(ui_ExpertMode_return_btn, ui_event_ExpertMode_return_btn, LV_EVENT_CLICKED, NULL);

    ui_ExpertMode_return_label = lv_label_create(ui_ExpertMode_return_btn);
    lv_label_set_text(ui_ExpertMode_return_label, Back[language_index]);
    lv_obj_set_size(ui_ExpertMode_return_label,110,60);
    lv_obj_set_style_text_align(ui_ExpertMode_return_label,LV_TEXT_ALIGN_CENTER,LV_PART_MAIN);
    lv_label_set_long_mode(ui_ExpertMode_return_label,LV_LABEL_LONG_DOT);
    lv_obj_align_to(ui_ExpertMode_return_label,ui_ExpertMode_return_btn,LV_ALIGN_CENTER,0,15);
    lv_obj_set_style_text_color(ui_ExpertMode_return_label, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ExpertMode_return_label, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
}