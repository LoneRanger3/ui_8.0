/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-01 15:59:35
 * @LastEditTime: 2023-05-19 11:34:38
 */

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "mult_language.h"
#include <sys/time.h>

lv_obj_t * ui_AboutDevice;
lv_obj_t * ui_AboutDevicePanel1;
lv_obj_t * ui_AboutDeviceImage1;
lv_obj_t * ui_AboutDeviceImage2;
lv_obj_t * ui_AboutDeviceImage3;
lv_obj_t * ui_AboutDeviceImage4;
lv_obj_t * ui_AboutDeviceImage5;
lv_obj_t * ui_AboutDevicePanel2;
lv_obj_t * ui_AboutDevicePanel3;
lv_obj_t * ui_AboutDeviceTitle;
lv_obj_t * ui_AboutDeviceLabel1;
lv_obj_t * ui_AboutDeviceButton1;
lv_obj_t * ui_AboutDeviceBtnlabel1;
lv_obj_t * ui_AboutDevicePanel4;
lv_obj_t * ui_AboutDeviceImage6;
lv_obj_t * ui_AboutDeviceLabel2;
lv_obj_t * ui_AboutDeviceLable3;
lv_obj_t * ui_AboutDeviceLable4;
lv_obj_t * ui_AboutDeviceLable5;
lv_obj_t * ui_AboutDeviceLable6;
lv_obj_t * ui_AboutDeviceLable7;
lv_obj_t * ui_AboutDeviceLable8;
lv_obj_t * ui_AboutDeviceLable9;
lv_obj_t * ui_AboutDeviceLable10;
lv_obj_t * ui_AboutDeviceLable11;
lv_obj_t * ui_AboutDeviceLable12;
lv_obj_t * ui_AboutDeviceLable13;
lv_obj_t * ui_AboutDeviceLable14;
lv_obj_t * ui_AboutDeviceLable15;
lv_obj_t * ui_AboutDeviceLable16;
lv_obj_t * ui_AboutDevicePanel5;
lv_obj_t * ui_AboutDeviceDropdown1;
lv_obj_t * ui_AboutDeviceButton2;
lv_obj_t * ui_AboutDeviceBtnlabel2;
lv_obj_t * ui_AboutDeviceButton3;
lv_obj_t * ui_AboutDeviceBtnlabel3;
lv_obj_t * ui_AboutDeviceButton4;
lv_obj_t * ui_AboutDeviceBtnlabel4;
lv_obj_t * ui_AboutDevice_Keyboard1;
lv_obj_t * ui_AboutDevice_TextArea1;
lv_obj_t * ui_AboutDevicelevelTable;
lv_obj_t * ui_AboutDeviceButton5;
lv_obj_t * ui_AboutDeviceBtnlabel5;
lv_obj_t * ui_AboutDeviceButton6;
lv_obj_t * ui_AboutDeviceBtnlabel6;
lv_obj_t * ui_AboutDevicePanel6;
lv_obj_t * ui_AboutDeviceButton7;
lv_obj_t * ui_AboutDeviceButton8;
lv_obj_t * ui_AboutDeviceButton9;
lv_obj_t * ui_AboutDeviceButton10;

#define PASSWORD "cxsw$888"
void ui_event_AboutDeviceButton1(lv_event_t * e);
void ui_event_AboutDeviceImage1(lv_event_t * e);
void ui_event_AboutDeviceImage2(lv_event_t * e);
void ui_event_AboutDeviceImage3(lv_event_t * e);
void ui_event_AboutDeviceImage4(lv_event_t * e);
void ui_event_AboutDeviceImage5(lv_event_t * e);
void ui_event_AboutDevice(lv_event_t * e);
void ui_event_AboutDeviceLable13(lv_event_t * e);
void ui_event_AboutDeviceDropdown1(lv_event_t * e);
void ui_event_AboutDeviceButton2(lv_event_t * e);
void ui_event_AboutDeviceButton3(lv_event_t * e);
void ui_event_AboutDeviceButton4(lv_event_t * e);
void ui_event_AboutDeviceButton5(lv_event_t * e);
void ui_event_AboutDeviceButton6(lv_event_t * e);
void ui_event_AboutDeviceTextArea1(lv_event_t * e);
void ui_event_AboutDeviceKeyboard1(lv_event_t * e);
void ui_event_AboutDeviceFactorymode(lv_event_t * e);

void ui_AboutDevice_screen_init(void)
{
    ui_AboutDevice = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_AboutDevice, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    ui_AboutDevicePanel1 = lv_obj_create(ui_AboutDevice);
    lv_obj_set_width(ui_AboutDevicePanel1, 80);
    lv_obj_set_height(ui_AboutDevicePanel1, 480);
    lv_obj_clear_flag(ui_AboutDevicePanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDevicePanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDevicePanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AboutDevicePanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_AboutDevicePanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceImage1 = lv_img_create(ui_AboutDevicePanel1);
    lv_img_set_src(ui_AboutDeviceImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_AboutDeviceImage1, 80);
    lv_obj_set_height(ui_AboutDeviceImage1, 96);
    lv_obj_add_flag(ui_AboutDeviceImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceImage2 = lv_img_create(ui_AboutDevicePanel1);
    lv_img_set_src(ui_AboutDeviceImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_AboutDeviceImage2, 80);
    lv_obj_set_height(ui_AboutDeviceImage2, 96);
    lv_obj_set_x(ui_AboutDeviceImage2, 0);
    lv_obj_set_y(ui_AboutDeviceImage2, 96);
    lv_obj_add_flag(ui_AboutDeviceImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceImage3 = lv_img_create(ui_AboutDevicePanel1);
    lv_img_set_src(ui_AboutDeviceImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_AboutDeviceImage3, 80);
    lv_obj_set_height(ui_AboutDeviceImage3, 96);
    lv_obj_set_x(ui_AboutDeviceImage3, 0);
    lv_obj_set_y(ui_AboutDeviceImage3, 192);
    lv_obj_add_flag(ui_AboutDeviceImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceImage4 = lv_img_create(ui_AboutDevicePanel1);
    lv_img_set_src(ui_AboutDeviceImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_AboutDeviceImage4, 80);
    lv_obj_set_height(ui_AboutDeviceImage4, 96);
    lv_obj_set_x(ui_AboutDeviceImage4, 0);
    lv_obj_set_y(ui_AboutDeviceImage4, 288);
    lv_obj_add_flag(ui_AboutDeviceImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceImage5 = lv_img_create(ui_AboutDevicePanel1);
    lv_img_set_src(ui_AboutDeviceImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_AboutDeviceImage5, 80);
    lv_obj_set_height(ui_AboutDeviceImage5, 96);
    lv_obj_set_x(ui_AboutDeviceImage5, 0);
    lv_obj_set_y(ui_AboutDeviceImage5, 384);
    lv_obj_add_flag(ui_AboutDeviceImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage5, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDevicePanel2 = lv_obj_create(ui_AboutDevice);
    lv_obj_set_width(ui_AboutDevicePanel2, 720);
    lv_obj_set_height(ui_AboutDevicePanel2, 480);
    lv_obj_set_x(ui_AboutDevicePanel2, 80);
    lv_obj_set_y(ui_AboutDevicePanel2, 0);
    lv_obj_clear_flag(ui_AboutDevicePanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDevicePanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDevicePanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDevicePanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AboutDevicePanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_AboutDevicePanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDevicePanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_AboutDevicePanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AboutDevicePanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AboutDevicePanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AboutDevicePanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDevicePanel3 = lv_obj_create(ui_AboutDevicePanel2);
    lv_obj_set_width(ui_AboutDevicePanel3, 696);
    lv_obj_set_height(ui_AboutDevicePanel3, 456);
    lv_obj_set_align(ui_AboutDevicePanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_AboutDevicePanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDevicePanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDevicePanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDevicePanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDevicePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_AboutDevicePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AboutDevicePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AboutDevicePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AboutDevicePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceTitle = lv_obj_create(ui_AboutDevicePanel3);
    lv_obj_set_width(ui_AboutDeviceTitle, 272);
    lv_obj_set_height(ui_AboutDeviceTitle, 40);
    lv_obj_set_x(ui_AboutDeviceTitle, 391);
    lv_obj_set_y(ui_AboutDeviceTitle, 25);
    lv_obj_clear_flag(ui_AboutDeviceTitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceTitle, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDeviceTitle, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AboutDeviceTitle, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_AboutDeviceTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_AboutDeviceTitle, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_AboutDeviceTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AboutDeviceTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AboutDeviceTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AboutDeviceTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLabel1 = lv_label_create(ui_AboutDeviceTitle);
    lv_obj_set_width(ui_AboutDeviceLabel1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_AboutDeviceLabel1, 28);
    lv_obj_align(ui_AboutDeviceLabel1, LV_ALIGN_LEFT_MID, 1, -3);
    lv_label_set_text(ui_AboutDeviceLabel1, AboutDevice[language_index]);
    lv_obj_set_style_text_color(ui_AboutDeviceLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLabel1, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceButton1 = lv_btn_create(ui_AboutDevicePanel3);
    lv_obj_set_width(ui_AboutDeviceButton1, 116);
    lv_obj_set_height(ui_AboutDeviceButton1, 60);
    lv_obj_set_x(ui_AboutDeviceButton1, 560);
    lv_obj_set_y(ui_AboutDeviceButton1, 381);
    lv_obj_add_flag(ui_AboutDeviceButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_AboutDeviceButton1, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_AboutDeviceButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_AboutDeviceButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_AboutDeviceButton1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceButton1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceBtnlabel1 = lv_label_create(ui_AboutDeviceButton1);
    lv_obj_set_width(ui_AboutDeviceBtnlabel1, lv_pct(100));
    lv_obj_set_height(ui_AboutDeviceBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_AboutDeviceBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_AboutDeviceBtnlabel1, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_AboutDeviceBtnlabel1, Back[language_index]);
    lv_obj_set_style_text_align(ui_AboutDeviceBtnlabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDevicePanel4 = lv_obj_create(ui_AboutDevicePanel3);
    lv_obj_set_width(ui_AboutDevicePanel4, 362);
    lv_obj_set_height(ui_AboutDevicePanel4, 426);
    lv_obj_set_x(ui_AboutDevicePanel4, 15);
    lv_obj_set_y(ui_AboutDevicePanel4, 15);
    lv_obj_clear_flag(ui_AboutDevicePanel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDevicePanel4, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDevicePanel4, lv_color_hex(0x18181B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDevicePanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDevicePanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_AboutDevicePanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AboutDevicePanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AboutDevicePanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AboutDevicePanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceButton7 = lv_btn_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceButton7, 116);
    lv_obj_set_height(ui_AboutDeviceButton7, 60);
    lv_obj_align(ui_AboutDeviceButton7, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton7, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceButton8 = lv_btn_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceButton8, 116);
    lv_obj_set_height(ui_AboutDeviceButton8, 60);
    lv_obj_align(ui_AboutDeviceButton8, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton8, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceButton9 = lv_btn_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceButton9, 116);
    lv_obj_set_height(ui_AboutDeviceButton9, 60);
    lv_obj_align(ui_AboutDeviceButton9, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton9, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceButton10 = lv_btn_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceButton10, 116);
    lv_obj_set_height(ui_AboutDeviceButton10, 60);
    lv_obj_align(ui_AboutDeviceButton10, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton10, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceImage6 = lv_img_create(ui_AboutDevicePanel4);
    lv_img_set_src(ui_AboutDeviceImage6, &ui_img_machine_png);
    lv_obj_set_width(ui_AboutDeviceImage6, 244);
    lv_obj_set_height(ui_AboutDeviceImage6, 244);
    lv_obj_set_x(ui_AboutDeviceImage6, 0);
    lv_obj_set_y(ui_AboutDeviceImage6, 41);
    lv_obj_set_align(ui_AboutDeviceImage6, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_AboutDeviceImage6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage6, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    lv_obj_add_event_cb(ui_AboutDeviceButton7, ui_event_AboutDeviceFactorymode, LV_EVENT_CLICKED, "1");
    lv_obj_add_event_cb(ui_AboutDeviceButton8, ui_event_AboutDeviceFactorymode, LV_EVENT_CLICKED, "2");
    lv_obj_add_event_cb(ui_AboutDeviceButton9, ui_event_AboutDeviceFactorymode, LV_EVENT_CLICKED, "3");
    lv_obj_add_event_cb(ui_AboutDeviceButton10, ui_event_AboutDeviceFactorymode, LV_EVENT_CLICKED, "4");
    lv_obj_add_event_cb(ui_AboutDeviceImage6, ui_event_AboutDeviceFactorymode, LV_EVENT_CLICKED, "5");

    ui_AboutDeviceLabel2 = lv_label_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceLabel2, 300);
    lv_obj_set_height(ui_AboutDeviceLabel2, 30);
    lv_obj_set_x(ui_AboutDeviceLabel2, 0);
    lv_obj_set_y(ui_AboutDeviceLabel2, 319);
    lv_obj_set_align(ui_AboutDeviceLabel2, LV_ALIGN_TOP_MID);
    lv_label_set_long_mode(ui_AboutDeviceLabel2, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_AboutDeviceLabel2, "CR K1");
    lv_obj_set_style_text_color(ui_AboutDeviceLabel2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLabel2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable3 = lv_label_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceLable3, 300);
    lv_obj_set_height(ui_AboutDeviceLable3, 30);
    lv_obj_set_x(ui_AboutDeviceLable3, 0);
    lv_obj_set_y(ui_AboutDeviceLable3, 351);
    lv_obj_set_align(ui_AboutDeviceLable3, LV_ALIGN_TOP_MID);
    lv_label_set_long_mode(ui_AboutDeviceLable3, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_AboutDeviceLable3, "220x220x250mm");
    lv_obj_set_style_text_color(ui_AboutDeviceLable3, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDevicePanel6 = lv_obj_create(ui_AboutDevicePanel3);
    lv_obj_set_width(ui_AboutDevicePanel6, 300);
    lv_obj_set_height(ui_AboutDevicePanel6, 285);
    lv_obj_set_x(ui_AboutDevicePanel6, 387);
    lv_obj_set_y(ui_AboutDevicePanel6, 67);
    lv_obj_clear_flag(ui_AboutDevicePanel6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDevicePanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDevicePanel6, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDevicePanel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AboutDevicePanel6, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDevicePanel6, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_AboutDevicePanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_AboutDevicePanel6, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable4 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable4, 240);
    lv_obj_set_height(ui_AboutDeviceLable4, 28);
    lv_obj_align(ui_AboutDeviceLable4, LV_ALIGN_TOP_LEFT, 4, 17);
    lv_label_set_long_mode(ui_AboutDeviceLable4, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_AboutDeviceLable4, DeviceNameArray[language_index]);
    lv_obj_set_style_text_color(ui_AboutDeviceLable4, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable6 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable6, 220);
    lv_obj_set_height(ui_AboutDeviceLable6, 28);
    lv_obj_align_to(ui_AboutDeviceLable6, ui_AboutDeviceLable4, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
    lv_label_set_long_mode(ui_AboutDeviceLable6, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_AboutDeviceLable6, FirmwareVersion[language_index]);
    lv_obj_set_style_text_color(ui_AboutDeviceLable6, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable6, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable7 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable7, 100);
    lv_obj_set_height(ui_AboutDeviceLable7, 28);
    lv_obj_align_to(ui_AboutDeviceLable7, ui_AboutDeviceLable6, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
    lv_label_set_long_mode(ui_AboutDeviceLable7, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_AboutDeviceLable7, MacAddrArray[language_index]);
    lv_obj_set_style_text_color(ui_AboutDeviceLable7, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable7, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable5 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable5, 220);
    lv_obj_set_height(ui_AboutDeviceLable5, 28);
    lv_obj_align_to(ui_AboutDeviceLable5, ui_AboutDeviceLable7, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
    lv_label_set_long_mode(ui_AboutDeviceLable5, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_AboutDeviceLable5, SerialNumber[language_index]);
    lv_obj_set_style_text_color(ui_AboutDeviceLable5, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable5, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable8 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable8, 200);
    lv_obj_set_height(ui_AboutDeviceLable8, 48);
    lv_obj_align_to(ui_AboutDeviceLable8, ui_AboutDeviceLable5, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
    lv_label_set_long_mode(ui_AboutDeviceLable8, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_line_space(ui_AboutDeviceLable8, -5, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
    lv_label_set_text(ui_AboutDeviceLable8, CumulativeTime[language_index]);
    lv_obj_set_style_text_color(ui_AboutDeviceLable8, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable8, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable9 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable9, 200);
    lv_obj_set_height(ui_AboutDeviceLable9, 48);
    lv_obj_align_to(ui_AboutDeviceLable9, ui_AboutDeviceLable8, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
    lv_label_set_long_mode(ui_AboutDeviceLable9, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_line_space(ui_AboutDeviceLable9, -5, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
    lv_label_set_text(ui_AboutDeviceLable9, StorageArray[language_index]);
    lv_obj_set_style_text_color(ui_AboutDeviceLable9, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable9, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable9, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable10 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable10, 300);
    lv_obj_set_height(ui_AboutDeviceLable10, 28);
    lv_obj_align(ui_AboutDeviceLable10, LV_ALIGN_TOP_RIGHT, 0, 17);
    lv_label_set_long_mode(ui_AboutDeviceLable10, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_AboutDeviceLable10, "11111");
    lv_obj_set_style_text_color(ui_AboutDeviceLable10, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable10, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable10, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable11 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable11, 300);
    lv_obj_set_height(ui_AboutDeviceLable11, 28);
    lv_obj_set_style_base_dir(ui_AboutDeviceLable11, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_AboutDeviceLable11, LV_ALIGN_TOP_RIGHT, 0, 60);
    lv_label_set_long_mode(ui_AboutDeviceLable11, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_AboutDeviceLable11, "");
    lv_obj_set_style_text_color(ui_AboutDeviceLable11, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable11, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable11, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable12 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable12, 300);
    lv_obj_set_height(ui_AboutDeviceLable12, 28);
    lv_obj_set_style_base_dir(ui_AboutDeviceLable12, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_AboutDeviceLable12, LV_ALIGN_TOP_RIGHT, 0, 103);
    lv_label_set_long_mode(ui_AboutDeviceLable12, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_AboutDeviceLable12, "");
    lv_obj_set_style_text_color(ui_AboutDeviceLable12, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable12, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable12, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable13 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable13, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_AboutDeviceLable13, 28);
    lv_obj_set_style_base_dir(ui_AboutDeviceLable13, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_AboutDeviceLable13, LV_ALIGN_TOP_RIGHT, 0, 146);
    lv_label_set_long_mode(ui_AboutDeviceLable13, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_AboutDeviceLable13, "");
    lv_obj_set_style_text_color(ui_AboutDeviceLable13, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable13, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable13, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_AboutDeviceLable13, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_ext_click_area(ui_AboutDeviceLable13, 30);

    ui_AboutDeviceLable14 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable14, 300);
    lv_obj_set_height(ui_AboutDeviceLable14, 28);
    lv_obj_set_style_base_dir(ui_AboutDeviceLable14, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_AboutDeviceLable14, LV_ALIGN_TOP_RIGHT, 0, 189);
    lv_label_set_long_mode(ui_AboutDeviceLable14, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_AboutDeviceLable14, "");
    lv_obj_set_style_text_color(ui_AboutDeviceLable14, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable14, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable14, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable15 = lv_label_create(ui_AboutDevicePanel6);
    lv_obj_set_width(ui_AboutDeviceLable15, 300);
    lv_obj_set_height(ui_AboutDeviceLable15, 28);
    lv_obj_set_style_base_dir(ui_AboutDeviceLable15, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_AboutDeviceLable15, LV_ALIGN_TOP_RIGHT, 0, 232);
    lv_label_set_long_mode(ui_AboutDeviceLable15, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_AboutDeviceLable15, "");
    lv_obj_set_style_text_color(ui_AboutDeviceLable15, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable15, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable15, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_AboutDeviceLable16 = lv_label_create(ui_AboutDevicePanel3);
    // lv_obj_set_width(ui_AboutDeviceLable16, 272);
    // lv_obj_set_height(ui_AboutDeviceLable16, 1);
    // lv_obj_set_x(ui_AboutDeviceLable16, 406);
    // lv_obj_set_y(ui_AboutDeviceLable16, 363);
    // lv_label_set_long_mode(ui_AboutDeviceLable16, LV_LABEL_LONG_DOT);
    // lv_label_set_text(ui_AboutDeviceLable16, "");
    // lv_obj_set_style_text_font(ui_AboutDeviceLable16, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_AboutDeviceLable16, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_AboutDeviceLable16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDevicePanel5 = lv_obj_create(ui_AboutDevice);
    lv_obj_set_width(ui_AboutDevicePanel5, 800);
    lv_obj_set_height(ui_AboutDevicePanel5, 480);
    lv_obj_align(ui_AboutDevicePanel5, LV_ALIGN_CENTER, 0, 0);
    lv_obj_clear_flag(ui_AboutDevicePanel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDevicePanel5, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDevicePanel5, lv_color_hex(0x18181B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDevicePanel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDevicePanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_AboutDevicePanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AboutDevicePanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AboutDevicePanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AboutDevicePanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_AboutDevicePanel5, LV_OBJ_FLAG_HIDDEN);

    char buff[150] = {0};
    sprintf(buff, "%s\n%s\n%s\n%s", "正式服务器","预发布服务器","测试服务器", "联调服务器");

    ui_AboutDeviceDropdown1 = lv_dropdown_create(ui_AboutDevicePanel5);
    lv_dropdown_set_options(ui_AboutDeviceDropdown1, buff);
    lv_obj_set_width(ui_AboutDeviceDropdown1, 300);
    lv_obj_set_height(ui_AboutDeviceDropdown1, 50);
    lv_obj_align(ui_AboutDeviceDropdown1, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_add_flag(ui_AboutDeviceDropdown1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_AboutDeviceDropdown1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceDropdown1, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceDropdown1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_AboutDeviceDropdown1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDeviceDropdown1, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AboutDeviceDropdown1, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_AboutDeviceDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceDropdown1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_AboutDeviceDropdown1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceDropdown1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceDropdown1, lv_font24.font, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_dropdown_set_symbol(ui_AboutDeviceDropdown1, &ui_img_expand_down_png);

    ui_AboutDeviceButton2 = lv_btn_create(ui_AboutDevicePanel5);
    lv_obj_set_width(ui_AboutDeviceButton2, 116);
    lv_obj_set_height(ui_AboutDeviceButton2, 60);
    lv_obj_align_to(ui_AboutDeviceButton2, ui_AboutDeviceDropdown1, LV_ALIGN_OUT_BOTTOM_MID, 0, 200);
    lv_obj_add_flag(ui_AboutDeviceButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceButton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_AboutDeviceButton2, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_AboutDeviceButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_AboutDeviceButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_AboutDeviceButton2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceButton2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceBtnlabel2 = lv_label_create(ui_AboutDeviceButton2);
    lv_obj_set_width(ui_AboutDeviceBtnlabel2, lv_pct(100));
    lv_obj_set_height(ui_AboutDeviceBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_AboutDeviceBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_AboutDeviceBtnlabel2, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_AboutDeviceBtnlabel2, Confirm[language_index]);
    lv_obj_set_style_text_align(ui_AboutDeviceBtnlabel2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDevice_TextArea1 = lv_textarea_create(ui_AboutDevicePanel5);
    lv_obj_set_width(ui_AboutDevice_TextArea1, 380);
    lv_obj_set_height(ui_AboutDevice_TextArea1, LV_SIZE_CONTENT);
    lv_obj_align(ui_AboutDevice_TextArea1, LV_ALIGN_TOP_RIGHT, -10, 10);
    lv_textarea_set_placeholder_text(ui_AboutDevice_TextArea1, InputPasswordMsg[language_index]);
    lv_obj_set_style_text_font(ui_AboutDevice_TextArea1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceButton3 = lv_btn_create(ui_AboutDevicePanel5);
    lv_obj_set_width(ui_AboutDeviceButton3, 146);
    lv_obj_set_height(ui_AboutDeviceButton3, 60);
    lv_obj_align_to(ui_AboutDeviceButton3, ui_AboutDevice_TextArea1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
    lv_obj_add_flag(ui_AboutDeviceButton3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceButton3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceButton3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton3, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_AboutDeviceButton3, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_AboutDeviceButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_AboutDeviceButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_AboutDeviceButton3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceButton3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceBtnlabel3 = lv_label_create(ui_AboutDeviceButton3);
    lv_obj_set_width(ui_AboutDeviceBtnlabel3, lv_pct(100));
    lv_obj_set_height(ui_AboutDeviceBtnlabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_AboutDeviceBtnlabel3, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_AboutDeviceBtnlabel3, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_AboutDeviceBtnlabel3, "裸板测试");
    lv_obj_set_style_text_align(ui_AboutDeviceBtnlabel3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceBtnlabel3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceButton4 = lv_btn_create(ui_AboutDevicePanel5);
    lv_obj_set_width(ui_AboutDeviceButton4, 146);
    lv_obj_set_height(ui_AboutDeviceButton4, 60);
    lv_obj_align_to(ui_AboutDeviceButton4, ui_AboutDevice_TextArea1, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 20);
    lv_obj_add_flag(ui_AboutDeviceButton4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceButton4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceButton4, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton4, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_AboutDeviceButton4, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_AboutDeviceButton4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_AboutDeviceButton4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_AboutDeviceButton4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceButton4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceButton4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceBtnlabel4 = lv_label_create(ui_AboutDeviceButton4);
    lv_obj_set_width(ui_AboutDeviceBtnlabel4, lv_pct(100));
    lv_obj_set_height(ui_AboutDeviceBtnlabel4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_AboutDeviceBtnlabel4, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_AboutDeviceBtnlabel4, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_AboutDeviceBtnlabel4, "整机测试");
    lv_obj_set_style_text_align(ui_AboutDeviceBtnlabel4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceBtnlabel4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDevicelevelTable = lv_table_create(ui_AboutDevicePanel5);
    lv_obj_set_width(ui_AboutDevicelevelTable, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_AboutDevicelevelTable, LV_SIZE_CONTENT);
    lv_obj_set_style_pad_top(ui_AboutDevicelevelTable, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AboutDevicelevelTable, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_AboutDevicelevelTable, 15, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AboutDevicelevelTable, 15, LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_table_set_row_cnt(ui_AboutDevicelevelTable, 6);
    lv_table_set_col_cnt(ui_AboutDevicelevelTable, 6);
    lv_table_set_col_width(ui_AboutDevicelevelTable, 0, 80);
    lv_table_set_col_width(ui_AboutDevicelevelTable, 1, 80);
    lv_table_set_col_width(ui_AboutDevicelevelTable, 2, 80);
    lv_table_set_col_width(ui_AboutDevicelevelTable, 3, 80);
    lv_table_set_col_width(ui_AboutDevicelevelTable, 4, 80);
    lv_table_set_col_width(ui_AboutDevicelevelTable, 5, 80);

    lv_obj_align(ui_AboutDevicelevelTable, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_obj_set_style_outline_width(ui_AboutDevicelevelTable, 1, LV_PART_ITEMS);  // 添加网格

    ui_AboutDeviceButton5 = lv_btn_create(ui_AboutDevicePanel5);
    lv_obj_set_width(ui_AboutDeviceButton5, 200);
    lv_obj_set_height(ui_AboutDeviceButton5, 60);
    lv_obj_align_to(ui_AboutDeviceButton5, ui_AboutDeviceButton2, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 20);
    lv_obj_add_flag(ui_AboutDeviceButton5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceButton5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceButton5, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton5, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_AboutDeviceButton5, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_AboutDeviceButton5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_AboutDeviceButton5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_AboutDeviceButton5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceButton5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceButton5, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceBtnlabel5 = lv_label_create(ui_AboutDeviceButton5);
    lv_obj_set_width(ui_AboutDeviceBtnlabel5, lv_pct(100));
    lv_obj_set_height(ui_AboutDeviceBtnlabel5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_AboutDeviceBtnlabel5, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_AboutDeviceBtnlabel5, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_AboutDeviceBtnlabel5, "获取调平数据");
    lv_obj_set_style_text_align(ui_AboutDeviceBtnlabel5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceBtnlabel5, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceButton6 = lv_btn_create(ui_AboutDevicePanel5);
    lv_obj_set_width(ui_AboutDeviceButton6, 200);
    lv_obj_set_height(ui_AboutDeviceButton6, 60);
    lv_obj_align_to(ui_AboutDeviceButton6, ui_AboutDeviceButton5, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 20);
    lv_obj_add_flag(ui_AboutDeviceButton6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceButton6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceButton6, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton6, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_AboutDeviceButton6, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_AboutDeviceButton6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_AboutDeviceButton6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_AboutDeviceButton6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceButton6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceButton6, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceBtnlabel6 = lv_label_create(ui_AboutDeviceButton6);
    lv_obj_set_width(ui_AboutDeviceBtnlabel6, lv_pct(100));
    lv_obj_set_height(ui_AboutDeviceBtnlabel6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_AboutDeviceBtnlabel6, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_AboutDeviceBtnlabel6, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_AboutDeviceBtnlabel6, "保存AI数据");
    lv_obj_set_style_text_align(ui_AboutDeviceBtnlabel6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceBtnlabel6, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDevice_Keyboard1 = lv_keyboard_create(ui_AboutDevicePanel5);
    lv_obj_set_width(ui_AboutDevice_Keyboard1, 780);
    lv_obj_set_height(ui_AboutDevice_Keyboard1, 260);
    lv_obj_set_x(ui_AboutDevice_Keyboard1, 0);
    lv_obj_set_y(ui_AboutDevice_Keyboard1, 0);
    lv_obj_set_style_text_color(ui_AboutDevice_Keyboard1, lv_color_hex(0x000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDevice_Keyboard1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDevice_Keyboard1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_AboutDevice_Keyboard1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_AboutDevice_Keyboard1, LV_OBJ_FLAG_HIDDEN);

    lv_obj_set_style_bg_color(ui_AboutDevice_Keyboard1, lv_color_hex(0xFFFFFF), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDevice_Keyboard1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_keyboard_set_textarea(ui_AboutDevice_Keyboard1, ui_AboutDevice_TextArea1);


    lv_obj_add_event_cb(ui_AboutDeviceButton1, ui_event_AboutDeviceButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceImage1, ui_event_AboutDeviceImage1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceImage2, ui_event_AboutDeviceImage2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceImage3, ui_event_AboutDeviceImage3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceImage4, ui_event_AboutDeviceImage4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceImage5, ui_event_AboutDeviceImage5, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_AboutDeviceLable13, ui_event_AboutDeviceLable13, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceDropdown1, ui_event_AboutDeviceDropdown1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceButton2, ui_event_AboutDeviceButton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceButton3, ui_event_AboutDeviceButton3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceButton4, ui_event_AboutDeviceButton4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceButton5, ui_event_AboutDeviceButton5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceButton6, ui_event_AboutDeviceButton6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDevice_TextArea1, ui_event_AboutDeviceTextArea1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDevice_Keyboard1, ui_event_AboutDeviceKeyboard1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDevice, ui_event_AboutDevice, LV_EVENT_SCREEN_LOADED, NULL);
}

void ui_event_AboutDeviceButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_AboutDeviceButton2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        uint16_t index;
        index = lv_dropdown_get_selected(ui_AboutDeviceDropdown1);
        CrLogI("screen_save_value set %d",index);
        switch(index)
        {
            case 0: set_printer_data(0x06,3,"n1");break;
            case 1: set_printer_data(0x06,3,"n2");break;
            case 2: set_printer_data(0x06,3,"n3");break;
            case 3: set_printer_data(0x06,3,"n4");break;
            default:break;
        }
        lv_obj_add_flag(ui_AboutDevicePanel5, LV_OBJ_FLAG_HIDDEN);
    }
}

void ui_event_AboutDeviceButton3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        CrLogI("factroy mode start");
        DisFactoryTestControl(FACTORY_TEST_START);
    }
}

void ui_event_AboutDeviceButton4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        CrLogI("machine mode start");
        DisFactoryTestControl(MACHINE_TEST_START);
    }
}

void ui_event_AboutDeviceButton5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        CrLogI("get level data");
        get_printer_data(0x09, 2, "7");
    }
}

void ui_event_AboutDeviceButton6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        create_msgbox("数据已保存", NULL, 500, lv_scr_act());
        DisSaveDataCollection(COLLECTION_AI_CAMERA_IMAGE);
        DisSaveDataCollection(COLLECTION_AI_POINT_CLOUD);
    }
}

void ui_event_AboutDeviceDropdown1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_READY) {
        lv_obj_t *list_method = lv_dropdown_get_list(ui_AboutDeviceDropdown1);
        if ( !list_method )
            return;
        lv_obj_set_style_text_color(list_method, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(list_method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(list_method, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(list_method, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(list_method, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(list_method, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(list_method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(list_method, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(list_method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(list_method, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        
        lv_obj_set_style_bg_color(list_method, lv_color_hex(0x42BDD8), LV_PART_SELECTED | LV_STATE_PRESSED);
        lv_obj_set_style_bg_opa(list_method, 255, LV_PART_SELECTED | LV_STATE_PRESSED);
    }
}

void ui_event_AboutDeviceLable13(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        static long int lasttime = 0;
        static int count = 0;

        struct timeval startTime;
        gettimeofday(&startTime, NULL);
        CrLogI("current time%Id", startTime.tv_sec);

        if(startTime.tv_sec - lasttime <= 1)//在1秒内
        {
            count++;
            lasttime = startTime.tv_sec;
            if(count > 5) //点击5次出现弹窗
            {
                count = 0;
                lv_obj_clear_flag(ui_AboutDevicePanel5, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_AboutDeviceButton3, LV_OBJ_FLAG_CLICKABLE);
                lv_obj_clear_flag(ui_AboutDeviceButton4, LV_OBJ_FLAG_CLICKABLE);
                lv_obj_set_style_bg_opa(ui_AboutDeviceButton3, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(ui_AboutDeviceButton4, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
        }
        else
        {
            lasttime = startTime.tv_sec;
            count = 0;
        }

    }
}

void ui_event_AboutDeviceFactorymode(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char *userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        static long int lasttime = 0;
        static int count = 0;

        struct timeval startTime;
        gettimeofday(&startTime, NULL);
        if(count == 0)lasttime = startTime.tv_sec;
        if(startTime.tv_sec - lasttime <= 1)//在1秒内
        {
            CrLogI("current time%Id, lasttime:%Id, userdata:%c", startTime.tv_sec, lasttime, userdata[0]);
            lasttime = startTime.tv_sec;
            if(count == 0 && userdata[0] == '1')
            {
                count++;
                CrLogI("current time%d", count);
            }
            else if(count == 1 && userdata[0] == '2')
            {
                count++;
                CrLogI("current time%d", count);
            }
            else if(count == 2 && userdata[0] == '3')
            {
                count++;
                CrLogI("current time%d", count);
            }
            else if(count == 3 && userdata[0] == '4')
            {
                count++;
                CrLogI("current time%d", count);
            }
            else if(count >= 4 && userdata[0] == '5')
            {
                CrLogI("current time%d", count);
                count++;
                if(count == 7)
                {
                    lv_obj_clear_flag(ui_AboutDevicePanel5, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_AboutDeviceButton3, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_clear_flag(ui_AboutDeviceButton4, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_opa(ui_AboutDeviceButton3, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(ui_AboutDeviceButton4, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
            else
            {
                CrLogI("reset time count");
                lasttime = startTime.tv_sec;
                count = 0;
            }
        }
        else
        {
            CrLogI("reset time count");
            lasttime = startTime.tv_sec;
            count = 0;
        }

    }
}

void ui_event_AboutDeviceImage1(lv_event_t * e)
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

void ui_event_AboutDeviceImage2(lv_event_t * e)
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

void ui_event_AboutDeviceImage3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadFileManageScreen();
    }
}

void ui_event_AboutDeviceImage4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_AboutDeviceImage5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadCustomerServiceScreen();
    }
}

void ui_event_AboutDeviceTextArea1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED) {
        send_buzzer(0x01);
        lv_keyboard_set_textarea(ui_AboutDevice_Keyboard1, ui_AboutDevice_TextArea1);
        lv_obj_clear_flag(ui_AboutDevice_Keyboard1, LV_OBJ_FLAG_HIDDEN);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {
        lv_keyboard_set_textarea(ui_AboutDevice_Keyboard1, NULL);
        lv_obj_add_flag(ui_AboutDevice_Keyboard1, LV_OBJ_FLAG_HIDDEN);
    }
}

void ui_event_AboutDeviceKeyboard1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        uint32_t id = lv_btnmatrix_get_selected_btn(target);
        lv_keyboard_mode_t mode = lv_keyboard_get_mode(target);
        CrLogI("keyboard input id: %d,mode :%d",id,mode);
        if(id == 39)
        {
            const char *passw = lv_textarea_get_text(ui_AboutDevice_TextArea1);
            if(passw != NULL)
            {
                CrLogI("PASSWORD: %s",passw);
                if(strcmp(passw, PASSWORD) == 0)//密码匹配
                {
                    lv_obj_add_flag(ui_AboutDeviceButton3, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_add_flag(ui_AboutDeviceButton4, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_opa(ui_AboutDeviceButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(ui_AboutDeviceButton4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_textarea_set_text(ui_AboutDevice_TextArea1, "");
                    lv_obj_add_flag(ui_AboutDevice_Keyboard1, LV_OBJ_FLAG_HIDDEN);
                }
                else
                {
                    create_msgbox("密码错误", NULL, 1000, lv_scr_act());
                }
            }
        }
    }
}

void ui_event_AboutDevice(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load aboutdevice page.");
        get_printer_data(0x14,1,"\0");
        get_printer_data(0x06,2,"n");
        switch (UIType)
        {
            case CR_K1:
            {
                if(IsK1C)
                    lv_label_set_text(ui_AboutDeviceLabel2, "K1C");
                else
                    lv_label_set_text(ui_AboutDeviceLabel2, "K1");
                lv_label_set_text(ui_AboutDeviceLable3, "220x220x250mm");
                lv_img_set_src(ui_AboutDeviceImage6, &ui_img_machine_png);
                break;
            }
            case CR_K1_Max: 
            {
                lv_img_set_src(ui_AboutDeviceImage6, &ui_img_k1max_about_png);
                if(IsK1MaxSe)
                    lv_label_set_text(ui_AboutDeviceLabel2, "K1 Max SE");
                else
                    lv_label_set_text(ui_AboutDeviceLabel2, "K1 Max");
                lv_label_set_text(ui_AboutDeviceLable3, "300x300x300mm");
                break;
            }
        }
        for(int i = 0; i < lv_table_get_row_cnt(ui_AboutDevicelevelTable); i++)
            for(int j = 0; j < lv_table_get_col_cnt(ui_AboutDevicelevelTable); j++)
                lv_table_set_cell_value(ui_AboutDevicelevelTable, i, j, "");
    }
}

void refresh_aboutdevice_page(MachineInfo_t machine)
{
    if(ui_AboutDeviceLable10 != NULL)
        lv_label_set_text(ui_AboutDeviceLable10, machine.MachineName);
    if(ui_AboutDeviceLable11 != NULL)
        lv_label_set_text(ui_AboutDeviceLable11, machine.ScreenVersion);
    if(ui_AboutDeviceLable12 != NULL)
        lv_label_set_text(ui_AboutDeviceLable12, machine.MacValue);
    if(ui_AboutDeviceLable13 != NULL)
    {
        char * productionSn = NULL;
        // 从文件获取生产信息
        json_object *productionInfoObj = json_object_from_file(GetMachineProductionInfo());
        if (!productionInfoObj) {
            CrLogW("no production info\n");
        }

        // 获取生产SN号
        json_object *productionSnObj = json_object_object_get(productionInfoObj, "productionSn");
        if (productionSnObj && json_object_is_type(productionSnObj, json_type_string)) {
            productionSn = json_object_get_string(productionSnObj);
        }

        json_object_put(productionInfoObj);
        CrLogI("production sn = %s\n", productionSn);
        lv_label_set_text(ui_AboutDeviceLable13, productionSn);
    }
    if(atoi(machine.PrintedTime) >= 0)
    {
        int day = 0;
        int hou = 0;
        int min = 0;
        int sec = atoi(machine.PrintedTime);

        day = sec / (60 * 60 * 24);
        hou = (sec - day * (60 * 60 * 24)) / (60 * 60);
        min = (sec - day * (60 * 60 * 24) - hou * (60 * 60)) / 60;

        char buff[100] = {0};
        if(day <= 99)
            snprintf(buff, 100, "%02dd%02dh%02dm", day, hou, min);
        else
            snprintf(buff, 100, "%dd%02dh%02dm", day, hou, min);
        if(total_time_value[0] != '\0')
            lv_label_set_text(ui_AboutDeviceLable14, buff); 
    }

    if(ui_AboutDeviceLable15 != NULL)
    {
        float used  = 0.0f;
        float total = 0.0f;
        total = atof(machine.TotalDiskCapacity);
        used  = atof(machine.UsedDiskCapacity);
        used = used / 1024;
        total = total / 1024;
        char buff[100] = {0};
        snprintf(buff, 100, "%.1f/%.1fGB", used, total);
        lv_label_set_text(ui_AboutDeviceLable15, buff);
    }
    // if(screen_ver_value[0] != '\0')
    //     lv_label_set_text(guider_ui.about_label_screen, screen_ver_value);
    // if(official_web_value[0] != '\0')
    //     lv_label_set_text(guider_ui.about_label_website, official_web_value);
}

void refresh_serverinfo_page(int state)
{
    CrLogI("refresh the server info,state:%d",state);
    switch (state)
    {
        case 1:lv_dropdown_set_selected(ui_AboutDeviceDropdown1, 0);break;
        case 2:lv_dropdown_set_selected(ui_AboutDeviceDropdown1, 1);break;
        case 3:lv_dropdown_set_selected(ui_AboutDeviceDropdown1, 2);break;
        case 4:lv_dropdown_set_selected(ui_AboutDeviceDropdown1, 3);break;
        default:
            break;
    }
}

void refresh_factoryleveldata(int len,char * data, char level_point_value)
{
    CrLogI("refresh the factoryleveldata:%s",data);
    data++;
    char tempBuff[1024] = {0};
    if (data) {
        memcpy(tempBuff, data, strlen(data));
    }
    char *tempsingle = strtok(tempBuff, "\t");
    int count = 0;
    //先获取调平点总数
    while(tempsingle)
    {
        CrLogI("single level data : %s,count: %d",tempsingle, count);
        count++;
        tempsingle = strtok(NULL,"\t");
    }


    int levelcount = 5;
    switch (count)
    {
        case 9:lv_table_set_row_cnt(ui_AboutDevicelevelTable, 3);
                 lv_table_set_col_cnt(ui_AboutDevicelevelTable, 3);
                 levelcount = 3;break;
        case 16:lv_table_set_row_cnt(ui_AboutDevicelevelTable, 4);
                 lv_table_set_col_cnt(ui_AboutDevicelevelTable, 4);
                 levelcount = 4;break;
        case 25:lv_table_set_row_cnt(ui_AboutDevicelevelTable, 5);
                 lv_table_set_col_cnt(ui_AboutDevicelevelTable, 5);
                 levelcount = 5;break;
        case 36:lv_table_set_row_cnt(ui_AboutDevicelevelTable, 6);
                 lv_table_set_col_cnt(ui_AboutDevicelevelTable, 6);
                 levelcount = 6;break;
        default:CrLogW("level point count:%d",count);
            break;
    }


    char *single = strtok(data, "\t");
    float rowcount = sqrt(count);
    int i = 0;
    int j = (int)rowcount;
    count = 0;
    while(single)
    {
        CrLogI("single level data : %s,count: %d",single, count);
        if(count % (int)rowcount != 0)
        {
            i++;
            CrLogI("1data:%d,%d", i,j);
            lv_table_set_cell_value(ui_AboutDevicelevelTable, j, i, single);
        }
        else
        {
            i = 0;
            j--;
            CrLogI("2data:%d,%d", i,j);
            lv_table_set_cell_value(ui_AboutDevicelevelTable, j, i, single);
            lv_table_set_col_width(ui_AboutDevicelevelTable, j, 80);
        }
        count++;
        single = strtok(NULL,"\t");
    }

}

void about_device_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_AboutDeviceLabel1 )
        lv_label_set_text(ui_AboutDeviceLabel1, AboutDevice[language_index]);

    if ( ui_AboutDeviceBtnlabel1 )
        lv_label_set_text(ui_AboutDeviceBtnlabel1, Back[language_index]);
    
    if ( ui_AboutDeviceLable4 )
    lv_label_set_text(ui_AboutDeviceLable4, DeviceNameArray[language_index]);

    if ( ui_AboutDeviceLable5 )
    lv_label_set_text(ui_AboutDeviceLable5, SerialNumber[language_index]);

    if ( ui_AboutDeviceLable6 )
    lv_label_set_text(ui_AboutDeviceLable6, FirmwareVersion[language_index]);

    if ( ui_AboutDeviceLable7 )
    lv_label_set_text(ui_AboutDeviceLable7, MacAddrArray[language_index]);

    if ( ui_AboutDeviceLable8 )
    {
        lv_label_set_text(ui_AboutDeviceLable8, CumulativeTime[language_index]);
        lv_obj_set_height(ui_AboutDeviceLable8, 28);
        lv_obj_align_to(ui_AboutDeviceLable8, ui_AboutDeviceLable5, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
        lv_obj_set_style_text_line_space(ui_AboutDeviceLable8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
        for(int i = 0; i < strlen(CumulativeTime[language_index]); i++)
        {
            if(CumulativeTime[language_index][i] == '\n')
            {
                lv_label_set_text(ui_AboutDeviceLable8, CumulativeTime[language_index]);
                lv_obj_set_height(ui_AboutDeviceLable8, 48);
                lv_obj_align_to(ui_AboutDeviceLable8, ui_AboutDeviceLable5, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
                lv_obj_set_style_text_line_space(ui_AboutDeviceLable8, -5, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
            }
        }
    }

    if ( ui_AboutDeviceLable9 )
    {
        lv_label_set_text(ui_AboutDeviceLable9, StorageArray[language_index]);
        lv_obj_set_height(ui_AboutDeviceLable9, 28);
        lv_obj_align_to(ui_AboutDeviceLable9, ui_AboutDeviceLable8, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 15);
        lv_obj_set_style_text_line_space(ui_AboutDeviceLable9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
        for(int i = 0; i < strlen(StorageArray[language_index]); i++)
        {
            if(StorageArray[language_index][i] == '\n')
            {
                lv_label_set_text(ui_AboutDeviceLable9, StorageArray[language_index]);
                lv_obj_set_height(ui_AboutDeviceLable9, 48);
                lv_obj_align_to(ui_AboutDeviceLable9, ui_AboutDeviceLable8, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
                lv_obj_set_style_text_line_space(ui_AboutDeviceLable9, -5, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
            }
        }
    }
    
}
