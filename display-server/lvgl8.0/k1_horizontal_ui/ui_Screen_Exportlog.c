/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-11-29 11:23:59
 * @LastEditTime: 2023-03-08 19:52:38
 */
#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "mult_language.h"

lv_obj_t * ui_Exportlog;
lv_obj_t * ui_ExportlogPanel1;
lv_obj_t * ui_ExportlogImage1;
lv_obj_t * ui_ExportlogImage2;
lv_obj_t * ui_ExportlogImage3;
lv_obj_t * ui_ExportlogImage4;
lv_obj_t * ui_ExportlogImage5;
lv_obj_t * ui_ExportlogPanel2;
lv_obj_t * ui_ExportlogPanel3;
lv_obj_t * ui_ExportlogTitle;
lv_obj_t * ui_ExportlogLabel1;
lv_obj_t * ui_ExportlogButton1;
lv_obj_t * ui_ExportlogBtnlabel1;
lv_obj_t * ui_ExportlogPanel4;
lv_obj_t * ui_ExportlogPanel4label;
lv_obj_t * ui_ExportlogButton2;
lv_obj_t * ui_ExportlogBtnlabel2;
lv_obj_t * ui_Exportmbox1;
lv_obj_t * export_timer;
bool startexprotlogtolocal = false;
void ui_event_ExportlogButton1(lv_event_t * e);
void ui_event_ExportlogButton2(lv_event_t * e);
void ui_event_ExportlogImage1(lv_event_t * e);
void ui_event_ExportlogImage2(lv_event_t * e);
void ui_event_ExportlogImage3(lv_event_t * e);
void ui_event_ExportlogImage4(lv_event_t * e);
void ui_event_ExportlogImage5(lv_event_t * e);

void ui_Exportlog_screen_init(void)
{
    ui_Exportlog = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Exportlog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ExportlogPanel1 = lv_obj_create(ui_Exportlog);
    lv_obj_set_width(ui_ExportlogPanel1, 80);
    lv_obj_set_height(ui_ExportlogPanel1, 480);
    lv_obj_clear_flag(ui_ExportlogPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExportlogPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExportlogPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ExportlogPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ExportlogPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExportlogPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ExportlogPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ExportlogPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ExportlogPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ExportlogPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogImage1 = lv_img_create(ui_ExportlogPanel1);
    lv_img_set_src(ui_ExportlogImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_ExportlogImage1, 80);
    lv_obj_set_height(ui_ExportlogImage1, 96);
    lv_obj_add_flag(ui_ExportlogImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_ExportlogImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ExportlogImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogImage2 = lv_img_create(ui_ExportlogPanel1);
    lv_img_set_src(ui_ExportlogImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_ExportlogImage2, 80);
    lv_obj_set_height(ui_ExportlogImage2, 96);
    lv_obj_set_x(ui_ExportlogImage2, 0);
    lv_obj_set_y(ui_ExportlogImage2, 96);
    lv_obj_add_flag(ui_ExportlogImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_ExportlogImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ExportlogImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExportlogImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogImage3 = lv_img_create(ui_ExportlogPanel1);
    lv_img_set_src(ui_ExportlogImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_ExportlogImage3, 80);
    lv_obj_set_height(ui_ExportlogImage3, 96);
    lv_obj_set_x(ui_ExportlogImage3, 0);
    lv_obj_set_y(ui_ExportlogImage3, 192);
    lv_obj_add_flag(ui_ExportlogImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_ExportlogImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ExportlogImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExportlogImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogImage4 = lv_img_create(ui_ExportlogPanel1);
    lv_img_set_src(ui_ExportlogImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_ExportlogImage4, 80);
    lv_obj_set_height(ui_ExportlogImage4, 96);
    lv_obj_set_x(ui_ExportlogImage4, 0);
    lv_obj_set_y(ui_ExportlogImage4, 288);
    lv_obj_add_flag(ui_ExportlogImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_ExportlogImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ExportlogImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExportlogImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogImage5 = lv_img_create(ui_ExportlogPanel1);
    lv_img_set_src(ui_ExportlogImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_ExportlogImage5, 80);
    lv_obj_set_height(ui_ExportlogImage5, 96);
    lv_obj_set_x(ui_ExportlogImage5, 0);
    lv_obj_set_y(ui_ExportlogImage5, 384);
    lv_obj_add_flag(ui_ExportlogImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_ExportlogImage5, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ExportlogImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExportlogImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogPanel2 = lv_obj_create(ui_Exportlog);
    lv_obj_set_width(ui_ExportlogPanel2, 720);
    lv_obj_set_height(ui_ExportlogPanel2, 480);
    lv_obj_set_x(ui_ExportlogPanel2, 80);
    lv_obj_set_y(ui_ExportlogPanel2, 0);
    lv_obj_clear_flag(ui_ExportlogPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExportlogPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExportlogPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ExportlogPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ExportlogPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExportlogPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ExportlogPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ExportlogPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ExportlogPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ExportlogPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogPanel3 = lv_obj_create(ui_ExportlogPanel2);
    lv_obj_set_width(ui_ExportlogPanel3, 696);
    lv_obj_set_height(ui_ExportlogPanel3, 456);
    lv_obj_set_align(ui_ExportlogPanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ExportlogPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogPanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExportlogPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExportlogPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExportlogPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ExportlogPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ExportlogPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ExportlogPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ExportlogPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogTitle = lv_obj_create(ui_ExportlogPanel3);
    lv_obj_set_width(ui_ExportlogTitle, 665);
    lv_obj_set_height(ui_ExportlogTitle, 65);
    lv_obj_set_x(ui_ExportlogTitle, 10);
    lv_obj_set_y(ui_ExportlogTitle, 0);
    lv_obj_clear_flag(ui_ExportlogTitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogTitle, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExportlogTitle, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExportlogTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ExportlogTitle, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ExportlogTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExportlogTitle, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ExportlogTitle, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ExportlogTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ExportlogTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ExportlogTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ExportlogTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    uint8_t language_index = get_cur_language_index();
    ui_ExportlogLabel1 = lv_label_create(ui_ExportlogTitle);
    lv_obj_set_width(ui_ExportlogLabel1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ExportlogLabel1, 28);
    lv_obj_set_x(ui_ExportlogLabel1, 15);
    lv_obj_set_y(ui_ExportlogLabel1, 0);
    lv_obj_set_align(ui_ExportlogLabel1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ExportlogLabel1, ExportLogArray[language_index]);
    lv_obj_set_style_text_color(ui_ExportlogLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ExportlogLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ExportlogLabel1, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogButton2 = lv_btn_create(ui_ExportlogPanel3);
    lv_obj_set_width(ui_ExportlogButton2, 116);
    lv_obj_set_height(ui_ExportlogButton2, 60);
    lv_obj_align(ui_ExportlogButton2, LV_ALIGN_BOTTOM_RIGHT, -20, -15);
    lv_obj_add_flag(ui_ExportlogButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ExportlogButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogButton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExportlogButton2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExportlogButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ExportlogButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_ExportlogButton2, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_ExportlogButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ExportlogButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ExportlogButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ExportlogButton2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ExportlogButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ExportlogButton2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogBtnlabel2 = lv_label_create(ui_ExportlogButton2);
    lv_obj_set_width(ui_ExportlogBtnlabel2, lv_pct(100));
    lv_obj_set_height(ui_ExportlogBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ExportlogBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_ExportlogBtnlabel2, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_ExportlogBtnlabel2, ExportArray[language_index]);
    lv_obj_set_style_text_align(ui_ExportlogBtnlabel2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ExportlogBtnlabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogButton1 = lv_btn_create(ui_ExportlogPanel3);
    lv_obj_set_width(ui_ExportlogButton1, 116);
    lv_obj_set_height(ui_ExportlogButton1, 60);
    lv_obj_align_to(ui_ExportlogButton1, ui_ExportlogButton2, LV_ALIGN_OUT_LEFT_MID, -25, 0);
    lv_obj_add_flag(ui_ExportlogButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ExportlogButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExportlogButton1, lv_color_hex(0x28292D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExportlogButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ExportlogButton1, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ExportlogButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExportlogButton1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_ExportlogButton1, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_ExportlogButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ExportlogButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ExportlogButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ExportlogButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ExportlogButton1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ExportlogButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ExportlogButton1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogBtnlabel1 = lv_label_create(ui_ExportlogButton1);
    lv_obj_set_width(ui_ExportlogBtnlabel1, lv_pct(100));
    lv_obj_set_height(ui_ExportlogBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ExportlogBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_ExportlogBtnlabel1, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_ExportlogBtnlabel1, Back[language_index]);
    lv_obj_set_style_text_align(ui_ExportlogBtnlabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ExportlogBtnlabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogPanel4 = lv_obj_create(ui_ExportlogPanel3);
    lv_obj_set_width(ui_ExportlogPanel4, 636);
    lv_obj_set_height(ui_ExportlogPanel4, 280);
    lv_obj_set_x(ui_ExportlogPanel4, 32);
    lv_obj_set_y(ui_ExportlogPanel4, 89);
    lv_obj_clear_flag(ui_ExportlogPanel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportlogPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExportlogPanel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExportlogPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExportlogPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExportlogPanel4label = lv_label_create(ui_ExportlogPanel4);
    lv_obj_set_width(ui_ExportlogPanel4label, 556);
    lv_obj_set_height(ui_ExportlogPanel4label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ExportlogPanel4label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ExportlogPanel4label, "插入U盘后点击导出即可将日志导出到U盘");
    lv_obj_set_style_text_align(ui_ExportlogPanel4label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ExportlogPanel4label, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ExportlogPanel4label, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ExportlogButton1, ui_event_ExportlogButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ExportlogButton2, ui_event_ExportlogButton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ExportlogImage1, ui_event_ExportlogImage1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ExportlogImage2, ui_event_ExportlogImage2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ExportlogImage3, ui_event_ExportlogImage3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ExportlogImage4, ui_event_ExportlogImage4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ExportlogImage5, ui_event_ExportlogImage5, LV_EVENT_ALL, NULL);
}
void ui_event_ExportlogImage1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        // Your code here
        if ( home_printing_is_printing_finished() )
            LoadHomeNormalScreen();
        else
            LoadHomePrintingScreen();
    }
}

void ui_event_ExportlogImage2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if ( home_printing_is_printing_finished() )
            LoadAxisMoveScreen();
        else
            LoadAxisMoveScreen();
    }
}

void ui_event_ExportlogImage3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadFileManageScreen();
    }
}

void ui_event_ExportlogImage4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_ExportlogImage5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadCustomerServiceScreen();
    }
}

void ui_event_ExportlogButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

static void event_cb(lv_event_t * e)
{
    // LV_LOG_USER("Button %s clicked", lv_msgbox_get_active_btn_text(ui_Exportmbox1));
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_msgbox_close(ui_Exportmbox1);
    }
}

void ui_event_ExportlogButton2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //发送日志导出指令
        send_buzzer(0x01);
        startexprotlogtolocal = true;
        set_printer_data(0x1c,1,"1");
    }
}

void exportpage_timeout_handle(lv_timer_t * timer)
{
    lv_msgbox_close(ui_Exportmbox1);
}

void refreshmsgbox(int flag, int process)
{
    CrLogI("refresh the exprot log ,state is %d, process: %d.",flag, process);
    if(!startexprotlogtolocal)return;
    switch (flag)
    {
        case 0:
        {
            char tempbuff[256] = {0};
            snprintf(tempbuff, 256, "%s : %d%%", LogExportingMsg[get_cur_language_index()], process);
            create_msgbox(tempbuff, NULL, 0, lv_scr_act());
            break;
        }
        case 1:create_msgbox(LogExportSuccessMsg[get_cur_language_index()], NULL, 2000, lv_scr_act());startexprotlogtolocal = false;break;
        case 2:create_msgbox(LogExportFailedMsg[get_cur_language_index()], NULL, 2000, lv_scr_act());startexprotlogtolocal = false;break;
        case 3:create_msgbox(DiskUMsg[get_cur_language_index()], NULL, 2000, lv_scr_act());break;
        case 4:create_msgbox(LogExporCompressing[get_cur_language_index()], NULL, 0, lv_scr_act());break;
        default:
            break;
    }   
}

void export_log_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ExportLogArray )
        lv_label_set_text(ui_ExportlogLabel1, ExportLogArray[language_index]);

    if ( ui_ExportlogBtnlabel1 )
        lv_label_set_text(ui_ExportlogBtnlabel1, Back[language_index]);

    if ( ui_ExportlogBtnlabel2 )
    {
        lv_label_set_text(ui_ExportlogBtnlabel2, ExportArray[language_index]);
        redefine_label_size(ui_ExportlogBtnlabel2, lv_font25.font, 0, 0, 300, 0);
        
        lv_obj_update_layout(ui_ExportlogButton2);
        redefine_widgets_size(ui_ExportlogButton2, ui_ExportlogBtnlabel2, 5, 0, 116, 60);
        
        lv_obj_align_to(ui_ExportlogButton1, ui_ExportlogButton2, LV_ALIGN_OUT_LEFT_MID, -25, 0);
    }

    if ( ui_ExportlogPanel4label )
        lv_label_set_text(ui_ExportlogPanel4label, ExportTips[language_index]);

}
