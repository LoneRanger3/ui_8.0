/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-06 11:43:33
 * @LastEditTime: 2023-09-27 05:14:10
 */
#include "ui_screen_VedioInfo.h"
#include "page_switch.h"
#include "ui.h"
#include "ui_comp.h"
#include "ui_helpers.h"
#include "ui_Screen_Settings.h"
#include <time.h>
#include "ui_screen_CameraList.h"
#include "custom/lvgl_cmd.h"
#include "mult_language.h"

#define PREVIEW_IMG_SIZE 158

lv_obj_t * ui_VedioInfo;

/*********************************/
static lv_obj_t * ui_PanelScreenVedioInfo;
static lv_obj_t * ui_VedioInfoImage1;
static lv_obj_t * ui_VedioInfoImage2;
static lv_obj_t * ui_VedioInfoImage3;
static lv_obj_t * ui_VedioInfoImage4;
static lv_obj_t * ui_VedioInfoImage5;
//static lv_obj_t * ui_VedioInfoPanel2;
static lv_obj_t * ui_VedioInfoPanel;
static lv_obj_t * ui_VedioInfotitle;
static lv_obj_t * ui_VedioInfoPanelLine;

//static lv_obj_t * ui_VedioInfoPanel4;
static lv_obj_t * ui_VedioInfo_ImagePanle;
static lv_obj_t * ui_VedioInfo_ImageVedio;
static lv_obj_t * ui_VedioInfoLabel_FileName;
static lv_obj_t * ui_VedioInfoLabel_Datetime;
static lv_obj_t * ui_VedioInfoLabel_VedioTime;
static lv_obj_t * ui_VedioInfoLabel_ShootPos;
static lv_obj_t * ui_VedioInfoLabel_ShootFreq;
static lv_obj_t * ui_VedioInfoLabel_Render;

static lv_obj_t * ui_VedioInfoLabel_FileNameValue;
static lv_obj_t * ui_VedioInfoLabel_DatetimeValue;
static lv_obj_t * ui_VedioInfoLabel_VedioTimeValue;
static lv_obj_t * ui_VedioInfoLabel_ShootPosValue;
static lv_obj_t * ui_VedioInfoLabel_ShootFreqValue;
static lv_obj_t * ui_VedioInfoLabel_RenderValue;

static lv_obj_t * ui_VedioInfoButtonBack;
//static lv_obj_t * ui_VedioInfoBtnLabelBack;
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
static void VedioInfoPageChangeObjs(uint8_t index);
static void LoadVedioInfoPage(void);



/******************funs ****************/

void ui_event_VedioInfoButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        BackPrepage(false);
        //_ui_screen_change(ui_Cameralist, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
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
        CrLogI("vedio_file_index :%d", vedio_file_index);
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

void ui_VedioInfo_screen_init(void)
{
    ui_VedioInfo = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_VedioInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_VedioInfo, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VedioInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_VedioInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    init_pages(ui_VedioInfo, VedioInfoPageChangeObjs, LoadVedioInfoPage);

    uint8_t language_index = get_cur_language_index();
    char buff[40] = {0};
    ui_PanelScreenVedioInfo = lv_obj_create(ui_VedioInfo);
    lv_obj_set_width(ui_PanelScreenVedioInfo, 68);
    lv_obj_set_height(ui_PanelScreenVedioInfo, 360);
    lv_obj_set_pos(ui_PanelScreenVedioInfo, 0, 60);
    lv_obj_clear_flag(ui_PanelScreenVedioInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelScreenVedioInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelScreenVedioInfo, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelScreenVedioInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelScreenVedioInfo, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelScreenVedioInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelScreenVedioInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelScreenVedioInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelScreenVedioInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelScreenVedioInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelScreenVedioInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoImage1 = lv_img_create(ui_PanelScreenVedioInfo);
    lv_img_set_src(ui_VedioInfoImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_VedioInfoImage1, 68);
    lv_obj_set_height(ui_VedioInfoImage1, 72);
    lv_obj_set_pos(ui_VedioInfoImage1, 0, 0);
    lv_obj_add_flag(ui_VedioInfoImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoImage2 = lv_img_create(ui_PanelScreenVedioInfo);
    lv_img_set_src(ui_VedioInfoImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_VedioInfoImage2, 68);
    lv_obj_set_height(ui_VedioInfoImage2, 72);
    lv_obj_set_pos(ui_VedioInfoImage2, 0, 72);
    lv_obj_add_flag(ui_VedioInfoImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoImage3 = lv_img_create(ui_PanelScreenVedioInfo);
    lv_img_set_src(ui_VedioInfoImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_VedioInfoImage3, 68);
    lv_obj_set_height(ui_VedioInfoImage3, 72);
    lv_obj_set_pos(ui_VedioInfoImage3, 0, 144);
    lv_obj_add_flag(ui_VedioInfoImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoImage4 = lv_img_create(ui_PanelScreenVedioInfo);
    lv_img_set_src(ui_VedioInfoImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_VedioInfoImage4, 68);
    lv_obj_set_height(ui_VedioInfoImage4, 72);
    lv_obj_set_pos(ui_VedioInfoImage4, 0, 216);
    lv_obj_add_flag(ui_VedioInfoImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoImage5 = lv_img_create(ui_PanelScreenVedioInfo);
    lv_img_set_src(ui_VedioInfoImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_VedioInfoImage5, 68);
    lv_obj_set_height(ui_VedioInfoImage5, 72);
    lv_obj_set_pos(ui_VedioInfoImage5, 0, 288);
    lv_obj_add_flag(ui_VedioInfoImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_VedioInfoPanel2 = lv_obj_create(ui_VedioInfo);
    // lv_obj_set_width(ui_VedioInfoPanel2, 720);
    // lv_obj_set_height(ui_VedioInfoPanel2, 480);
    // lv_obj_set_x(ui_VedioInfoPanel2, 80);
    // lv_obj_set_y(ui_VedioInfoPanel2, 0);
    // lv_obj_clear_flag(ui_VedioInfoPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_VedioInfoPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_VedioInfoPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_VedioInfoPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_VedioInfoPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_left(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_right(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_top(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_bottom(ui_VedioInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfoPanel = lv_obj_create(ui_VedioInfo);
    lv_obj_set_pos(ui_VedioInfoPanel, 73, 68);
    lv_obj_set_size(ui_VedioInfoPanel, 559, 344); 
    lv_obj_set_align(ui_VedioInfoPanel, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_VedioInfoPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfoPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VedioInfoPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_VedioInfoPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_VedioInfotitle = lv_label_create(ui_VedioInfoPanel);
    // lv_obj_set_width(ui_VedioInfotitle, 150);
    // lv_obj_set_height(ui_VedioInfotitle, 28);
    // lv_obj_set_x(ui_VedioInfotitle, 15);
    // lv_obj_set_y(ui_VedioInfotitle, 0);
    //lv_obj_set_align(ui_VedioInfotitle, LV_ALIGN_LEFT_MID);
    lv_obj_set_size(ui_VedioInfotitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_VedioInfotitle, 16, 0);//6
    lv_label_set_text(ui_VedioInfotitle, VedioInformation[language_index]);
    lv_obj_set_style_text_color(ui_VedioInfotitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfotitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfotitle, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    
    // ui_VedioInfoPanel4 = lv_obj_create(ui_VedioInfoPanel);
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
    ui_VedioInfoPanelLine = lv_obj_create(ui_VedioInfoPanel);
    lv_obj_set_size(ui_VedioInfoPanelLine, 543, 1);
    lv_obj_set_pos(ui_VedioInfoPanelLine, 7, 49);
    lv_obj_clear_flag(ui_VedioInfoPanelLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_VedioInfoPanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfoPanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VedioInfoPanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_VedioInfoPanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoPanelLine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VedioInfo_ImagePanle = lv_obj_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfo_ImagePanle, PREVIEW_IMG_SIZE);
    lv_obj_set_height(ui_VedioInfo_ImagePanle, PREVIEW_IMG_SIZE);
    lv_obj_set_x(ui_VedioInfo_ImagePanle, 16);
    lv_obj_set_y(ui_VedioInfo_ImagePanle, 69);
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
    
    //文件名称
    ui_VedioInfoLabel_FileName = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_FileName, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_FileName, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_FileName, 186);
    lv_obj_set_y(ui_VedioInfoLabel_FileName, 80);
    lv_label_set_long_mode(ui_VedioInfoLabel_FileName, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", FileNameArray[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_FileName, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_FileName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_FileName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_FileName, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_FileName, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    ui_VedioInfoLabel_FileNameValue = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_FileNameValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_FileNameValue, 30);    /// 1
    // lv_obj_set_x(ui_VedioInfoLabel_FileNameValue, 296);
    // lv_obj_set_y(ui_VedioInfoLabel_FileNameValue, 80);     
    lv_obj_align_to(ui_VedioInfoLabel_FileNameValue, ui_VedioInfoLabel_FileName, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_label_set_long_mode(ui_VedioInfoLabel_FileNameValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_FileNameValue, "file name:");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_FileNameValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_FileNameValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_FileNameValue, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //视频时长
    ui_VedioInfoLabel_VedioTime = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_VedioTime, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_VedioTime, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_VedioTime, 186);
    lv_obj_set_y(ui_VedioInfoLabel_VedioTime, 113);   
    lv_label_set_long_mode(ui_VedioInfoLabel_VedioTime, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", VedioTime[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_VedioTime, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_VedioTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_VedioTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_VedioTime, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_VedioTime, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    ui_VedioInfoLabel_VedioTimeValue = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_VedioTimeValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_VedioTimeValue, 30);    /// 1
    // lv_obj_set_x(ui_VedioInfoLabel_VedioTimeValue, 460);
    // lv_obj_set_y(ui_VedioInfoLabel_VedioTimeValue, 162);    //160改为162
    lv_obj_align_to(ui_VedioInfoLabel_VedioTimeValue, ui_VedioInfoLabel_VedioTime, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_label_set_long_mode(ui_VedioInfoLabel_VedioTimeValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_VedioTimeValue, "file name:");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_VedioTimeValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_VedioTimeValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_VedioTimeValue, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //打印日期
    ui_VedioInfoLabel_Datetime = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_Datetime, LV_SIZE_CONTENT);   
    lv_obj_set_height(ui_VedioInfoLabel_Datetime, 30);    
    lv_obj_set_x(ui_VedioInfoLabel_Datetime, 186);
    lv_obj_set_y(ui_VedioInfoLabel_Datetime, 146);   
    lv_label_set_long_mode(ui_VedioInfoLabel_Datetime, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", PrintDatetime[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_Datetime, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_Datetime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_Datetime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_Datetime, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_Datetime, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_VedioInfoLabel_DatetimeValue = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_DatetimeValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_DatetimeValue, 30);    /// 1
    // lv_obj_set_x(ui_VedioInfoLabel_DatetimeValue, 460);
    // lv_obj_set_y(ui_VedioInfoLabel_DatetimeValue, 124);     
    lv_obj_align_to(ui_VedioInfoLabel_DatetimeValue, ui_VedioInfoLabel_Datetime, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_label_set_long_mode(ui_VedioInfoLabel_DatetimeValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_DatetimeValue, "2022 10 22 13:45:45");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_DatetimeValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_DatetimeValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_DatetimeValue, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    //拍摄位置
    ui_VedioInfoLabel_ShootPos = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_ShootPos, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_ShootPos, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_ShootPos, 186);
    lv_obj_set_y(ui_VedioInfoLabel_ShootPos, 179);   //214改为200
    lv_label_set_long_mode(ui_VedioInfoLabel_ShootPos, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", ShootPosArray[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_ShootPos, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_ShootPos, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_ShootPos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_ShootPos, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_ShootPos, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    ui_VedioInfoLabel_ShootPosValue = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_ShootPosValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_ShootPosValue, 30);    /// 1
    // lv_obj_set_x(ui_VedioInfoLabel_ShootPosValue, 460);
    // lv_obj_set_y(ui_VedioInfoLabel_ShootPosValue, 200);  //214改为200
    lv_obj_align_to(ui_VedioInfoLabel_ShootPosValue, ui_VedioInfoLabel_ShootPos, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_label_set_long_mode(ui_VedioInfoLabel_ShootPosValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_ShootPosValue, "file name:");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_ShootPosValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_ShootPosValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_ShootPosValue, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //拍照频率
    ui_VedioInfoLabel_ShootFreq = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_ShootFreq, 130);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_ShootFreq, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_ShootFreq, 266);
    lv_obj_set_y(ui_VedioInfoLabel_ShootFreq, 252);
    lv_label_set_long_mode(ui_VedioInfoLabel_ShootFreq, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", ShootFreqArray[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_ShootFreq, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_ShootFreq, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_ShootFreq, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_ShootFreq, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_ShootFreq, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    ui_VedioInfoLabel_ShootFreqValue = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_ShootFreqValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_ShootFreqValue, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_ShootFreqValue, 460);
    lv_obj_set_y(ui_VedioInfoLabel_ShootFreqValue, 252);
    lv_label_set_long_mode(ui_VedioInfoLabel_ShootFreqValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_ShootFreqValue, "file name:");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_ShootFreqValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_ShootFreqValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_ShootFreqValue, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //渲染方式
    ui_VedioInfoLabel_Render = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_Render, 130);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_Render, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_Render, 266);
    lv_obj_set_y(ui_VedioInfoLabel_Render, 290);
    lv_label_set_long_mode(ui_VedioInfoLabel_Render, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", RenderArray[language_index]);
    lv_label_set_text(ui_VedioInfoLabel_Render, buff);
    lv_obj_set_style_text_color(ui_VedioInfoLabel_Render, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_Render, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_Render, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VedioInfoLabel_Render, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    ui_VedioInfoLabel_RenderValue = lv_label_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoLabel_RenderValue, 220);   /// 1
    lv_obj_set_height(ui_VedioInfoLabel_RenderValue, 30);    /// 1
    lv_obj_set_x(ui_VedioInfoLabel_RenderValue, 460);
    lv_obj_set_y(ui_VedioInfoLabel_RenderValue, 290);
    lv_label_set_long_mode(ui_VedioInfoLabel_RenderValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoLabel_RenderValue, "file name:");
    lv_obj_set_style_text_color(ui_VedioInfoLabel_RenderValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VedioInfoLabel_RenderValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoLabel_RenderValue, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //导出按钮
    ui_VedioInfoButton_Export = lv_btn_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoButton_Export, 140);
    lv_obj_set_height(ui_VedioInfoButton_Export, 60);
    lv_obj_align(ui_VedioInfoButton_Export, LV_ALIGN_BOTTOM_RIGHT, -4, -8);
    lv_obj_add_flag(ui_VedioInfoButton_Export, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoButton_Export, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoButton_Export, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfoButton_Export, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
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
    lv_obj_set_style_border_color(ui_VedioInfoButton_Export, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_VedioInfoButton_Export, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_VedioInfoButton_Export, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_VedioInfoButton_Export, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_VedioInfoButton_Export, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_VedioInfoButton_Export, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
   
    ui_VedioInfoBtnlabel_Export = lv_label_create(ui_VedioInfoButton_Export);
    lv_obj_set_width(ui_VedioInfoBtnlabel_Export, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_VedioInfoBtnlabel_Export, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_VedioInfoBtnlabel_Export, LV_ALIGN_CENTER);
   // lv_label_set_long_mode(ui_VedioInfoBtnlabel_Export, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_VedioInfoBtnlabel_Export, ExportArray[language_index]);
    lv_obj_set_style_text_align(ui_VedioInfoBtnlabel_Export, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VedioInfoBtnlabel_Export, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    ui_VedioInfoButton_Upload = lv_btn_create(ui_VedioInfoPanel);
    lv_obj_set_width(ui_VedioInfoButton_Upload, 140);
    lv_obj_set_height(ui_VedioInfoButton_Upload, 60);
    lv_obj_set_x(ui_VedioInfoButton_Upload, 244);
    lv_obj_set_y(ui_VedioInfoButton_Upload, 280);
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
    
    //返回按钮
    ui_VedioInfoButtonBack = lv_btn_create(ui_VedioInfoPanel);
    lv_obj_set_size(ui_VedioInfoButtonBack, 68, 38);
    lv_obj_set_pos(ui_VedioInfoButtonBack, 474, 6);
    lv_obj_add_flag(ui_VedioInfoButtonBack, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_VedioInfoButtonBack, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VedioInfoButtonBack, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VedioInfoButtonBack, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VedioInfoButtonBack, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VedioInfoButtonBack, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VedioInfoButtonBack, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_VedioInfoButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_VedioInfoButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_VedioInfoButtonBack, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VedioInfoButtonBack, lv_color_hex(0xB0F1FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_VedioInfoButtonBack, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_VedioInfoButtonBack, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_VedioInfoButtonBack, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_VedioInfoButtonBack, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_VedioInfoButtonBack, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    // ui_VedioInfoBtnLabelBack = lv_label_create(ui_VedioInfoButtonBack);
    // lv_obj_set_width(ui_VedioInfoBtnLabelBack, 110);
    // lv_obj_set_height(ui_VedioInfoBtnLabelBack, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_align(ui_VedioInfoBtnLabelBack, LV_ALIGN_CENTER);
    // lv_label_set_long_mode(ui_VedioInfoBtnLabelBack, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_VedioInfoBtnLabelBack, Back[language_index]);
    // lv_obj_set_style_text_align(ui_VedioInfoBtnLabelBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_VedioInfoBtnLabelBack, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
   
   
    lv_obj_add_event_cb(ui_VedioInfoButtonBack, ui_event_VedioInfoButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VedioInfoButton_Export, ui_event_VedioInfoButton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VedioInfoButton_Upload, ui_event_VedioInfoButton3, LV_EVENT_ALL, NULL);
   
    /*******************隐藏不用的控件*****************************/
    lv_obj_add_flag(ui_VedioInfoLabel_ShootFreq, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_VedioInfoLabel_Render, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_VedioInfoLabel_ShootFreqValue, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_VedioInfoLabel_RenderValue, LV_OBJ_FLAG_HIDDEN);

}

void vedio_set_vedioinfo(int16_t vedio_index, char *file_name, char * png_name, uint64_t datetime, 
                        uint32_t vedio_time, uint8_t shoot_pos, uint16_t shoot_freq, uint8_t rendering_method)
{
    if (!file_name|| (strlen(file_name) <= 0) )
    {
        lv_label_set_text(ui_VedioInfoLabel_FileNameValue, "");
        lv_label_set_text(ui_VedioInfoLabel_DatetimeValue, "");
        lv_label_set_text(ui_VedioInfoLabel_VedioTimeValue, "");
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
    if(vedio_time / 60 == 0)
        sprintf(buff, "%ds", vedio_time);
    else
        sprintf(buff, "%dm%02ds", vedio_time / 60, vedio_time % 60);

    lv_label_set_text(ui_VedioInfoLabel_VedioTimeValue, buff);
   
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
    if ( ui_VedioInfotitle )
        lv_label_set_text(ui_VedioInfotitle, VedioInformation[language_index]);
    
    if ( ui_VedioInfoLabel_FileName )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", FileNameArray[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_FileName, buff);
        lv_obj_align_to(ui_VedioInfoLabel_FileNameValue, ui_VedioInfoLabel_FileName, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    }
    
    if ( ui_VedioInfoLabel_Datetime )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", PrintDatetime[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_Datetime, buff);
        //redefine_label_size(ui_VedioInfoLabel_Datetime, lv_font22.font, 0, 0, 150, 0);
        lv_obj_align_to(ui_VedioInfoLabel_DatetimeValue, ui_VedioInfoLabel_Datetime, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    }
     
    if ( ui_VedioInfoLabel_VedioTime )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", VedioTime[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_VedioTime, buff);
        lv_obj_align_to(ui_VedioInfoLabel_VedioTimeValue, ui_VedioInfoLabel_VedioTime, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    }
    
    if ( ui_VedioInfoLabel_ShootPos )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", ShootPosArray[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_ShootPos, buff);
        lv_obj_align_to(ui_VedioInfoLabel_ShootPosValue, ui_VedioInfoLabel_ShootPos, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    }
    
    if ( ui_VedioInfoLabel_ShootFreq )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", ShootFreqArray[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_ShootFreq, buff);
    }
    
    if ( ui_VedioInfoLabel_Render )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", RenderArray[language_index]);
        lv_label_set_text(ui_VedioInfoLabel_Render, buff);
    }
  
    if ( ui_VedioInfoBtnlabel_Export )
    {
        lv_label_set_text(ui_VedioInfoBtnlabel_Export, ExportArray[language_index]);
        lv_obj_update_layout(ui_VedioInfoButton_Export);
        redefine_widgets_size(ui_VedioInfoButton_Export, ui_VedioInfoBtnlabel_Export, 10, 0, 110, 60);
    }
        
    
    // if ( ui_VedioInfoBtnLabelBack )
    //     lv_label_set_text(ui_VedioInfoBtnLabelBack, Back[language_index]);
   
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

static void LoadVedioInfoPage()
{
    _ui_screen_change(ui_VedioInfo, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

static void VedioInfoPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *VedioInfo_node = find_page(ui_VedioInfo);
    VedioInfo_node->nav_level = index;
  
    lv_group_add_obj(encoder_group, ui_VedioInfoButtonBack);
    lv_group_add_obj(encoder_group, ui_VedioInfoButton_Export);
    
}
