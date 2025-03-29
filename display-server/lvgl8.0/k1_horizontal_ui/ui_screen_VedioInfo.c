/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-06 11:43:33
 * @LastEditTime: 2023-03-16 14:16:00
 */
#include "ui_screen_VedioInfo.h"
#include "ui.h"
#include "ui_comp.h"
#include "ui_helpers.h"
#include "ui_Screen_Settings.h"
#include <time.h>
#include "ui_screen_CameraList.h"
#include "custom/lvgl_cmd.h"
#include "mult_language.h"

#define PREVIEW_IMG_SIZE 300

lv_obj_t * ui_VedioInfo;

/*********************************/
static lv_obj_t * ui_VedioInfoPanel1;
static lv_obj_t * ui_VedioInfoImage1;
static lv_obj_t * ui_VedioInfoImage2;
static lv_obj_t * ui_VedioInfoImage3;
static lv_obj_t * ui_VedioInfoImage4;
static lv_obj_t * ui_VedioInfoImage5;
static lv_obj_t * ui_VedioInfoPanel2;
static lv_obj_t * ui_VedioInfoPanel3;
static lv_obj_t * ui_VedioInfotitle;
static lv_obj_t * ui_VedioInfoLabel1;

//static lv_obj_t * ui_VedioInfoPanel4;
static lv_obj_t * ui_VedioInfo_ImagePanle;
static lv_obj_t * ui_VedioInfo_ImageVedio;
static lv_obj_t * ui_VedioInfoLabel_FileName;
static lv_obj_t * ui_VedioInfoLabel_Datetime;
static lv_obj_t * ui_VedioInfoLabel_UsedTime;
static lv_obj_t * ui_VedioInfoLabel_ShootPos;
static lv_obj_t * ui_VedioInfoLabel_ShootFreq;
static lv_obj_t * ui_VedioInfoLabel_Render;

static lv_obj_t * ui_VedioInfoLabel_FileNameValue;
static lv_obj_t * ui_VedioInfoLabel_DatetimeValue;
static lv_obj_t * ui_VedioInfoLabel_UsedTimeValue;
static lv_obj_t * ui_VedioInfoLabel_ShootPosValue;
static lv_obj_t * ui_VedioInfoLabel_ShootFreqValue;
static lv_obj_t * ui_VedioInfoLabel_RenderValue;

static lv_obj_t * ui_VedioInfoButtonBack;
static lv_obj_t * ui_VedioInfoBtnLabelBack;
static lv_obj_t * ui_VedioInfoButton_Export;
static lv_obj_t * ui_VedioInfoBtnlabel_Export;
static lv_obj_t * ui_VedioInfoButton_Upload;
static lv_obj_t * ui_VedioInfoBtnlabel_Upload;

/*******************custom variable*********************/
static uint16_t vedio_file_index = 0;



/**********************************************/
static void ui_event_VedioInfoButton1(lv_event_t * e);
static void ui_event_VedioInfoButton2(lv_event_t * e);
static void ui_event_VedioInfoButton3(lv_event_t * e);




/********************custom funs***************************/





/******************funs ****************/

void ui_event_VedioInfoButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Cameralist, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        send_get_vedioes_count_cmd();
    }
}
void ui_event_VedioInfoButton2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //本地导出延时摄影视频
        char sendbuff[100] = {0};
        snprintf(sendbuff, 100, "32\t%d\t%d", 1, vedio_file_index);//1： 本机至U盘
        set_printer_data(CONTROL_FILE, strlen(sendbuff), sendbuff);
    }
}

void ui_event_VedioInfoButton3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //上传延时摄影视频
        // char sendbuff[100] = {0};
        // snprintf(sendbuff, 100, "3%d", vedio_file_index);
        // set_printer_data(0x1c, 20, sendbuff);
        // _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_ChangePage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
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

void ui_VedioInfo_screen_init(void)
{
    ui_VedioInfo = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_VedioInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    char buff[40] = {0};
    ui_VedioInfoPanel1 = lv_obj_create(ui_VedioInfo);
    lv_obj_set_width(ui_VedioInfoPanel1, 80);
    lv_obj_set_height(ui_VedioInfoPanel1, 480);
    lv_obj_clear_flag(ui_VedioInfoPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfoPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VedioInfoPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VedioInfoPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_VedioInfoPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VedioInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VedioInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VedioInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VedioInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoImage1 = lv_img_create(ui_VedioInfoPanel1);
    lv_img_set_src(ui_VedioInfoImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_VedioInfoImage1, 80);
    lv_obj_set_height(ui_VedioInfoImage1, 96);
    lv_obj_add_flag(ui_VedioInfoImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_VedioInfoImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_VedioInfoImage2 = lv_img_create(ui_VedioInfoPanel1);
    lv_img_set_src(ui_VedioInfoImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_VedioInfoImage2, 80);
    lv_obj_set_height(ui_VedioInfoImage2, 96);
    lv_obj_set_x(ui_VedioInfoImage2, 0);
    lv_obj_set_y(ui_VedioInfoImage2, 96);
    lv_obj_add_flag(ui_VedioInfoImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_VedioInfoImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_VedioInfoImage3 = lv_img_create(ui_VedioInfoPanel1);
    lv_img_set_src(ui_VedioInfoImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_VedioInfoImage3, 80);
    lv_obj_set_height(ui_VedioInfoImage3, 96);
    lv_obj_set_x(ui_VedioInfoImage3, 0);
    lv_obj_set_y(ui_VedioInfoImage3, 192);
    lv_obj_add_flag(ui_VedioInfoImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_VedioInfoImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_VedioInfoImage4 = lv_img_create(ui_VedioInfoPanel1);
    lv_img_set_src(ui_VedioInfoImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_VedioInfoImage4, 80);
    lv_obj_set_height(ui_VedioInfoImage4, 96);
    lv_obj_set_x(ui_VedioInfoImage4, 0);
    lv_obj_set_y(ui_VedioInfoImage4, 288);
    lv_obj_add_flag(ui_VedioInfoImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_VedioInfoImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_VedioInfoImage5 = lv_img_create(ui_VedioInfoPanel1);
    lv_img_set_src(ui_VedioInfoImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_VedioInfoImage5, 80);
    lv_obj_set_height(ui_VedioInfoImage5, 96);
    lv_obj_set_x(ui_VedioInfoImage5, 0);
    lv_obj_set_y(ui_VedioInfoImage5, 384);
    lv_obj_add_flag(ui_VedioInfoImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_VedioInfoImage5, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_VedioInfoPanel2 = lv_obj_create(ui_VedioInfo);
    lv_obj_set_width(ui_VedioInfoPanel2, 720);
    lv_obj_set_height(ui_VedioInfoPanel2, 480);
    lv_obj_set_x(ui_VedioInfoPanel2, 80);
    lv_obj_set_y(ui_VedioInfoPanel2, 0);
    lv_obj_clear_flag(ui_VedioInfoPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfoPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VedioInfoPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VedioInfoPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_VedioInfoPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoPanel3 = lv_obj_create(ui_VedioInfoPanel2);
    lv_obj_set_width(ui_VedioInfoPanel3, 696);
    lv_obj_set_height(ui_VedioInfoPanel3, 456);
    lv_obj_set_align(ui_VedioInfoPanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_VedioInfoPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoPanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfoPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VedioInfoPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VedioInfoPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VedioInfoPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VedioInfoPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VedioInfoPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfotitle = lv_obj_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfotitle, 665);
    lv_obj_set_height(ui_VedioInfotitle, 65);
    lv_obj_set_x(ui_VedioInfotitle, 10);
    lv_obj_set_y(ui_VedioInfotitle, 0);
    lv_obj_clear_flag(ui_VedioInfotitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfotitle, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfotitle, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VedioInfotitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VedioInfotitle, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_VedioInfotitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfotitle, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_VedioInfotitle, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VedioInfotitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VedioInfotitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VedioInfotitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VedioInfotitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoLabel1 = lv_label_create(ui_VedioInfotitle);
    lv_obj_set_width(ui_VedioInfoLabel1, 150);
    lv_obj_set_height(ui_VedioInfoLabel1, 28);
    lv_obj_set_x(ui_VedioInfoLabel1, 15);
    lv_obj_set_y(ui_VedioInfoLabel1, 0);
    lv_obj_set_align(ui_VedioInfoLabel1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_VedioInfoLabel1, VedioInformation[language_index]);
    lv_obj_set_style_text_color(ui_VedioInfoLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel1, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    // ui_VedioInfoPanel4 = lv_obj_create(ui_VedioInfoPanel3);
    // lv_obj_set_width(ui_VedioInfoPanel4, 300);
    // lv_obj_set_height(ui_VedioInfoPanel4, 300);
    // lv_obj_set_x(ui_VedioInfoPanel4, 13);
    // lv_obj_set_y(ui_VedioInfoPanel4, 75);
    // lv_obj_clear_flag(ui_VedioInfoPanel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_VedioInfoPanel4, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_VedioInfoPanel4, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_VedioInfoPanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_VedioInfoPanel4, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_VedioInfoPanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_VedioInfoPanel4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_VedioInfoPanel4, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_left(ui_VedioInfoPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_right(ui_VedioInfoPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_top(ui_VedioInfoPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_bottom(ui_VedioInfoPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfo_ImagePanle = lv_obj_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfo_ImagePanle, PREVIEW_IMG_SIZE);
    lv_obj_set_height(ui_VedioInfo_ImagePanle, PREVIEW_IMG_SIZE);
    lv_obj_set_x(ui_VedioInfo_ImagePanle, 10);
    lv_obj_set_y(ui_VedioInfo_ImagePanle, 80);
    lv_obj_clear_flag(ui_VedioInfo_ImagePanle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfo_ImagePanle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfo_ImagePanle, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VedioInfo_ImagePanle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VedioInfo_ImagePanle, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_VedioInfo_ImagePanle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfo_ImagePanle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_VedioInfo_ImagePanle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfo_ImageVedio = lv_img_create(ui_VedioInfo_ImagePanle);
    lv_obj_set_width(ui_VedioInfo_ImageVedio, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_VedioInfo_ImageVedio, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_VedioInfo_ImageVedio, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_VedioInfo_ImageVedio, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VedioInfo_ImageVedio, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_VedioInfoLabel_FileName = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_FileName, 130);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_FileName, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_FileName, 324);
    lv_obj_set_y(ui_VedioInfoLabel_FileName, 86);
    lv_label_set_long_mode(ui_VedioInfoLabel_FileName, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", FileNameArray[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_FileName, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_FileName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_FileName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_FileName, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_FileName, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoLabel_FileNameValue = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_FileNameValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_FileNameValue, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_FileNameValue, 460);
    lv_obj_set_y(ui_VedioInfoLabel_FileNameValue, 86);     
    lv_label_set_long_mode(ui_VedioInfoLabel_FileNameValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_FileNameValue, "file name:");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_FileNameValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_FileNameValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_FileNameValue, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_VedioInfoLabel_Datetime = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_Datetime, 130);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_Datetime, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_Datetime, 324);
    lv_obj_set_y(ui_VedioInfoLabel_Datetime, 124);   //123改为124
    lv_label_set_long_mode(ui_VedioInfoLabel_Datetime, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", PrintDatetime[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_Datetime, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_Datetime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_Datetime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_Datetime, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_Datetime, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoLabel_DatetimeValue = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_DatetimeValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_DatetimeValue, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_DatetimeValue, 460);
    lv_obj_set_y(ui_VedioInfoLabel_DatetimeValue, 124);     //123改为124
    lv_label_set_long_mode(ui_VedioInfoLabel_DatetimeValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_DatetimeValue, "2022 10 22 13:45:45");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_DatetimeValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_DatetimeValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_DatetimeValue, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoLabel_UsedTime = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_UsedTime, 130);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_UsedTime, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_UsedTime, 324);
    lv_obj_set_y(ui_VedioInfoLabel_UsedTime, 162);   //160改为162
    lv_label_set_long_mode(ui_VedioInfoLabel_UsedTime, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", PrintTime[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_UsedTime, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_UsedTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_UsedTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_UsedTime, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_UsedTime, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoLabel_UsedTimeValue = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_UsedTimeValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_UsedTimeValue, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_UsedTimeValue, 460);
    lv_obj_set_y(ui_VedioInfoLabel_UsedTimeValue, 162);    //160改为162
    lv_label_set_long_mode(ui_VedioInfoLabel_UsedTimeValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_UsedTimeValue, "file name:");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_UsedTimeValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_UsedTimeValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_UsedTimeValue, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoLabel_ShootPos = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_ShootPos, 130);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_ShootPos, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_ShootPos, 324);
    lv_obj_set_y(ui_VedioInfoLabel_ShootPos, 200);   //214改为200
    lv_label_set_long_mode(ui_VedioInfoLabel_ShootPos, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", ShootPosArray[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_ShootPos, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_ShootPos, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_ShootPos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_ShootPos, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_ShootPos, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoLabel_ShootPosValue = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_ShootPosValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_ShootPosValue, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_ShootPosValue, 460);
    lv_obj_set_y(ui_VedioInfoLabel_ShootPosValue, 200);  //214改为200
    lv_label_set_long_mode(ui_VedioInfoLabel_ShootPosValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_ShootPosValue, "file name:");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_ShootPosValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_ShootPosValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_ShootPosValue, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoLabel_ShootFreq = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_ShootFreq, 130);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_ShootFreq, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_ShootFreq, 324);
    lv_obj_set_y(ui_VedioInfoLabel_ShootFreq, 252);
    lv_label_set_long_mode(ui_VedioInfoLabel_ShootFreq, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    // sprintf(buff, "%s:", ShootFreqArray[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_ShootFreq, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_ShootFreq, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_ShootFreq, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_ShootFreq, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_ShootFreq, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoLabel_ShootFreqValue = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_ShootFreqValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_ShootFreqValue, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_ShootFreqValue, 460);
    lv_obj_set_y(ui_VedioInfoLabel_ShootFreqValue, 252);
    lv_label_set_long_mode(ui_VedioInfoLabel_ShootFreqValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_ShootFreqValue, "file name:");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_ShootFreqValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_ShootFreqValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_ShootFreqValue, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoLabel_Render = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_Render, 130);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_Render, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_Render, 324);
    lv_obj_set_y(ui_VedioInfoLabel_Render, 290);
    lv_label_set_long_mode(ui_VedioInfoLabel_Render, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    // sprintf(buff, "%s:", RenderArray[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_Render, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_Render, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_Render, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_Render, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_Render, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoLabel_RenderValue = lv_label_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoLabel_RenderValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_RenderValue, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_RenderValue, 460);
    lv_obj_set_y(ui_VedioInfoLabel_RenderValue, 290);
    lv_label_set_long_mode(ui_VedioInfoLabel_RenderValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_RenderValue, "file name:");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_RenderValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_RenderValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_RenderValue, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoButton_Export = lv_btn_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoButton_Export, 116);
    lv_obj_set_height(ui_VedioInfoButton_Export, 60);
    lv_obj_set_x(ui_VedioInfoButton_Export, 419);
    lv_obj_set_y(ui_VedioInfoButton_Export, 381);
    lv_obj_add_flag(ui_VedioInfoButton_Export, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoButton_Export, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoButton_Export, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfoButton_Export, lv_color_hex(0x28292D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VedioInfoButton_Export, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VedioInfoButton_Export, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_VedioInfoButton_Export, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoButton_Export, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_VedioInfoButton_Export, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_VedioInfoButton_Export, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_VedioInfoButton_Export, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_VedioInfoButton_Export, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_VedioInfoButton_Export, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoButton_Export, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoButton_Export, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VedioInfoButton_Export, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_VedioInfoButton_Export, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_VedioInfoButton_Export, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_VedioInfoBtnlabel_Export = lv_label_create(ui_VedioInfoButton_Export);
    lv_obj_set_width(ui_VedioInfoBtnlabel_Export, 110);
    lv_obj_set_height(ui_VedioInfoBtnlabel_Export, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_VedioInfoBtnlabel_Export, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_VedioInfoBtnlabel_Export, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoBtnlabel_Export, ExportArray[language_index]);
    lv_obj_set_style_text_align(ui_VedioInfoBtnlabel_Export, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoBtnlabel_Export, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoButton_Upload = lv_btn_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoButton_Upload, 116);
    lv_obj_set_height(ui_VedioInfoButton_Upload, 60);
    lv_obj_set_x(ui_VedioInfoButton_Upload, 278);
    lv_obj_set_y(ui_VedioInfoButton_Upload, 381);
    lv_obj_add_flag(ui_VedioInfoButton_Upload, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoButton_Upload, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoButton_Upload, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfoButton_Upload, lv_color_hex(0x28292D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VedioInfoButton_Upload, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VedioInfoButton_Upload, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_VedioInfoButton_Upload, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoButton_Upload, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_VedioInfoButton_Upload, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_VedioInfoButton_Upload, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_VedioInfoButton_Upload, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_VedioInfoButton_Upload, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_VedioInfoButton_Upload, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoButton_Upload, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoButton_Upload, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_flag(ui_VedioInfoButton_Upload, LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_VedioInfoBtnlabel_Upload = lv_label_create(ui_VedioInfoButton_Upload);
    lv_obj_set_width(ui_VedioInfoBtnlabel_Upload, 110);
    lv_obj_set_height(ui_VedioInfoBtnlabel_Upload, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_VedioInfoBtnlabel_Upload, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_VedioInfoBtnlabel_Upload, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoBtnlabel_Upload, UpLoadArray[language_index]);
    lv_obj_set_style_text_align(ui_VedioInfoBtnlabel_Upload, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoBtnlabel_Upload, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoButtonBack = lv_btn_create(ui_VedioInfoPanel3);
    lv_obj_set_width(ui_VedioInfoButtonBack, 116);
    lv_obj_set_height(ui_VedioInfoButtonBack, 60);
    lv_obj_set_x(ui_VedioInfoButtonBack, 560);
    lv_obj_set_y(ui_VedioInfoButtonBack, 381);
    lv_obj_add_flag(ui_VedioInfoButtonBack, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoButtonBack, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoButtonBack, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfoButtonBack, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VedioInfoButtonBack, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_VedioInfoButtonBack, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_VedioInfoButtonBack, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_VedioInfoButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_VedioInfoButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_VedioInfoButtonBack, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoButtonBack, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoButtonBack, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoBtnLabelBack = lv_label_create(ui_VedioInfoButtonBack);
    lv_obj_set_width(ui_VedioInfoBtnLabelBack, 110);
    lv_obj_set_height(ui_VedioInfoBtnLabelBack, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_VedioInfoBtnLabelBack, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_VedioInfoBtnLabelBack, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoBtnLabelBack, Back[language_index]);
    lv_obj_set_style_text_align(ui_VedioInfoBtnLabelBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoBtnLabelBack, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    lv_obj_add_event_cb(ui_VedioInfoButtonBack, ui_event_VedioInfoButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VedioInfoButton_Export, ui_event_VedioInfoButton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VedioInfoButton_Upload, ui_event_VedioInfoButton3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VedioInfoImage1, ui_event_ChangePage, LV_EVENT_ALL, "0");
    lv_obj_add_event_cb(ui_VedioInfoImage2, ui_event_ChangePage, LV_EVENT_ALL, "2");
    lv_obj_add_event_cb(ui_VedioInfoImage3, ui_event_ChangePage, LV_EVENT_ALL, "3");
    lv_obj_add_event_cb(ui_VedioInfoImage4, ui_event_ChangePage, LV_EVENT_ALL, "4");
    lv_obj_add_event_cb(ui_VedioInfoImage5, ui_event_ChangePage, LV_EVENT_ALL, "5");

    /*******************隐藏不用的控件*****************************/
    lv_obj_add_flag(ui_VedioInfoLabel_ShootFreq, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_VedioInfoLabel_Render, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_VedioInfoLabel_ShootFreqValue, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_VedioInfoLabel_RenderValue, LV_OBJ_FLAG_HIDDEN);

}

void vedio_set_vedioinfo(int16_t vedio_index, char *file_name, char * png_name, uint64_t datetime, 
                        uint32_t used_time, uint8_t shoot_pos, uint16_t shoot_freq, uint8_t rendering_method)
{
    if ( vedio_index <= 0 ||  !file_name|| (strlen(file_name) <= 0) )
    {
        vedio_file_index = 0;
        lv_label_set_text(ui_VedioInfoLabel_FileNameValue, "");
        lv_label_set_text(ui_VedioInfoLabel_DatetimeValue, "");
        lv_label_set_text(ui_VedioInfoLabel_UsedTimeValue, "");
        lv_label_set_text(ui_VedioInfoLabel_ShootPosValue, "");
        lv_label_set_text(ui_VedioInfoLabel_ShootFreqValue, "");
        lv_label_set_text(ui_VedioInfoLabel_RenderValue, "");
        return ;
    }

    vedio_file_index = vedio_index;
    lv_label_set_text(ui_VedioInfoLabel_FileNameValue, file_name);
    if ( png_name )
    {
        char buff[258] = {0};
        snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, png_name);
        CrLogI("png_src:%s",buff);
        lv_img_set_src(ui_VedioInfo_ImageVedio, buff);
        lv_obj_update_layout(ui_VedioInfo_ImageVedio);

        int width = lv_obj_get_width(ui_VedioInfo_ImageVedio);
        int height = lv_obj_get_height(ui_VedioInfo_ImageVedio);
        if(width > 0 && height > 0)//1280*720
        {
            int len = width > height ? width : height;//用长边做缩放
            int scale = 256 * PREVIEW_IMG_SIZE / len;//缩略图为92
            CrLogI("delay vedio infoimg width: %d,height:%d, scale:%d", width, height, scale);
            lv_img_set_zoom(ui_VedioInfo_ImageVedio, scale);
        }
        else
        {
            CrLogW("Udelay vedio infoimg width: %d,height:%d", width, height);
        }
    }

    char buff[20] = {0};
    time_t timesteamp = (time_t)datetime;
    struct tm *CurTime = localtime(&timesteamp);
    snprintf(buff , sizeof(buff) ,"%d/%02d/%02d %02d:%02d",
                                    CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
                                    CurTime->tm_hour, CurTime->tm_min);
    lv_label_set_text(ui_VedioInfoLabel_DatetimeValue, buff);

    memset(buff, 0, sizeof(buff));
    if(used_time / 60 == 0)
        sprintf(buff, "%ds", used_time);
    else
        sprintf(buff, "%dm%02ds", used_time / 60, used_time % 60);

    lv_label_set_text(ui_VedioInfoLabel_UsedTimeValue, buff);

    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s", shoot_pos ? HotendMoveAway[get_cur_language_index()] : 
                                    LayerStartPos[get_cur_language_index()]);
    lv_label_set_text(ui_VedioInfoLabel_ShootPosValue, buff);

    memset(buff, 0, sizeof(buff)); 
    sprintf(buff, "%d", shoot_freq );
    lv_label_set_text(ui_VedioInfoLabel_ShootFreqValue, buff);

    memset(buff, 0, sizeof(buff)); 
    sprintf(buff, "%d", rendering_method );
    lv_label_set_text(ui_VedioInfoLabel_RenderValue, buff);

    return ;
}

void vedio_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    char buff[256] = {0};
    if ( ui_VedioInfoLabel1 )
        lv_label_set_text(ui_VedioInfoLabel1, VedioInformation[language_index]);
    
    if ( ui_VedioInfoLabel_FileName )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", FileNameArray[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_FileName, buff);
    }
    
    if ( ui_VedioInfoLabel_Datetime )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", PrintDatetime[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_Datetime, buff);
    }
     
    if ( ui_VedioInfoLabel_UsedTime )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", PrintTime[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_UsedTime, buff);
    }
    
    if ( ui_VedioInfoLabel_ShootPos )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", ShootPosArray[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_ShootPos, buff);
    }
    
    if ( ui_VedioInfoLabel_ShootFreq )
    {
        memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s:", ShootFreqArray[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_ShootFreq, buff);
    }
    
    if ( ui_VedioInfoLabel_Render )
    {
        memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s:", RenderArray[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_Render, buff);
    }

    if ( ui_VedioInfoBtnlabel_Export )
        lv_label_set_text(ui_VedioInfoBtnlabel_Export, ExportArray[language_index]);
    
    if ( ui_VedioInfoBtnLabelBack )
        lv_label_set_text(ui_VedioInfoBtnLabelBack, Back[language_index]);

    if ( ui_VedioInfoBtnlabel_Upload )
        lv_label_set_text(ui_VedioInfoBtnlabel_Upload, UpLoadArray[language_index]);

}

void refresh_export_video_process(int process)
{
    char msgbuff[256] = {0};            
    if(process <= 100)
    {
        snprintf(msgbuff, 256, "%s:%d%%", VideoExportingMsg[get_cur_language_index()], process);
        create_msgbox(msgbuff, NULL, 0, lv_layer_top());
    }
    if(process > 100)
    {
        snprintf(msgbuff, 256, "%s", VideoExportSuccessMsg[get_cur_language_index()]);
        create_msgbox(msgbuff, NULL, 1000, lv_layer_top());
    }
    if(process == -1)
    {
        snprintf(msgbuff, 256, "%s", VideoExportFailedMsg[get_cur_language_index()]);
        create_msgbox(msgbuff, NULL, 1000, lv_layer_top());
    }
}