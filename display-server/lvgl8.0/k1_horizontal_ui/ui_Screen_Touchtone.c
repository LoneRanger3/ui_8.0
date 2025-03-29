/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-11-28 10:40:40
 * @LastEditTime: 2022-12-30 10:25:52
 */

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "mult_language.h"

lv_obj_t * ui_Keytonesetting;
lv_obj_t * ui_KeytonesettingPanel1;
lv_obj_t * ui_KeytonesettingImage1;
lv_obj_t * ui_KeytonesettingImage2;
lv_obj_t * ui_KeytonesettingImage3;
lv_obj_t * ui_KeytonesettingImage4;
lv_obj_t * ui_KeytonesettingImage5;
lv_obj_t * ui_KeytonesettingPanel2;
lv_obj_t * ui_KeytonesettingPanel3;
lv_obj_t * ui_KeytonesettingTitle;
lv_obj_t * ui_KeytonesettingButton1;
lv_obj_t * ui_KeytonesettingBtnLabel1;
lv_obj_t * ui_KeytonesettingLabel1;
lv_obj_t * ui_KeytonesettingSwitch1;
lv_obj_t * ui_KeytonesettingLabel2;
lv_obj_t * ui_KeytonesettingLabel3;
lv_obj_t * ui_KeytonesettingDropdown1;
lv_obj_t * ui_KeytonesettingSlider1;
lv_obj_t * ui_KeytonesettingImage6;
lv_obj_t * ui_KeytonesettingImage7;

void ui_Keytonesetting_screen_init(void)
{
    ui_Keytonesetting = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Keytonesetting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    ui_KeytonesettingPanel1 = lv_obj_create(ui_Keytonesetting);
    lv_obj_set_width(ui_KeytonesettingPanel1, 80);
    lv_obj_set_height(ui_KeytonesettingPanel1, 480);
    lv_obj_clear_flag(ui_KeytonesettingPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_KeytonesettingPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_KeytonesettingPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_KeytonesettingPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_KeytonesettingPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_KeytonesettingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_KeytonesettingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_KeytonesettingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_KeytonesettingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_KeytonesettingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingImage1 = lv_img_create(ui_KeytonesettingPanel1);
    lv_img_set_src(ui_KeytonesettingImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_KeytonesettingImage1, 80);
    lv_obj_set_height(ui_KeytonesettingImage1, 96);
    lv_obj_add_flag(ui_KeytonesettingImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_KeytonesettingImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingImage2 = lv_img_create(ui_KeytonesettingPanel1);
    lv_img_set_src(ui_KeytonesettingImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_KeytonesettingImage2, 80);
    lv_obj_set_height(ui_KeytonesettingImage2, 96);
    lv_obj_set_x(ui_KeytonesettingImage2, 0);
    lv_obj_set_y(ui_KeytonesettingImage2, 96);
    lv_obj_add_flag(ui_KeytonesettingImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_KeytonesettingImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_KeytonesettingImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingImage3 = lv_img_create(ui_KeytonesettingPanel1);
    lv_img_set_src(ui_KeytonesettingImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_KeytonesettingImage3, 80);
    lv_obj_set_height(ui_KeytonesettingImage3, 96);
    lv_obj_set_x(ui_KeytonesettingImage3, 0);
    lv_obj_set_y(ui_KeytonesettingImage3, 192);
    lv_obj_add_flag(ui_KeytonesettingImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_KeytonesettingImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_KeytonesettingImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingImage4 = lv_img_create(ui_KeytonesettingPanel1);
    lv_img_set_src(ui_KeytonesettingImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_KeytonesettingImage4, 80);
    lv_obj_set_height(ui_KeytonesettingImage4, 96);
    lv_obj_set_x(ui_KeytonesettingImage4, 0);
    lv_obj_set_y(ui_KeytonesettingImage4, 288);
    lv_obj_add_flag(ui_KeytonesettingImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_KeytonesettingImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_KeytonesettingImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingImage5 = lv_img_create(ui_KeytonesettingPanel1);
    lv_img_set_src(ui_KeytonesettingImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_KeytonesettingImage5, 80);
    lv_obj_set_height(ui_KeytonesettingImage5, 96);
    lv_obj_set_x(ui_KeytonesettingImage5, 0);
    lv_obj_set_y(ui_KeytonesettingImage5, 384);
    lv_obj_add_flag(ui_KeytonesettingImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_KeytonesettingImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_KeytonesettingImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingPanel2 = lv_obj_create(ui_Keytonesetting);
    lv_obj_set_width(ui_KeytonesettingPanel2, 720);
    lv_obj_set_height(ui_KeytonesettingPanel2, 480);
    lv_obj_set_x(ui_KeytonesettingPanel2, 80);
    lv_obj_set_y(ui_KeytonesettingPanel2, 0);
    lv_obj_clear_flag(ui_KeytonesettingPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_KeytonesettingPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_KeytonesettingPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_KeytonesettingPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_KeytonesettingPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_KeytonesettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_KeytonesettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_KeytonesettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_KeytonesettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_KeytonesettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingPanel3 = lv_obj_create(ui_KeytonesettingPanel2);
    lv_obj_set_width(ui_KeytonesettingPanel3, 696);
    lv_obj_set_height(ui_KeytonesettingPanel3, 456);
    lv_obj_set_x(ui_KeytonesettingPanel3, -1);
    lv_obj_set_y(ui_KeytonesettingPanel3, -1);
    lv_obj_set_align(ui_KeytonesettingPanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_KeytonesettingPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingPanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_KeytonesettingPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_KeytonesettingPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_KeytonesettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_KeytonesettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_KeytonesettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_KeytonesettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_KeytonesettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingTitle = lv_obj_create(ui_KeytonesettingPanel3);
    lv_obj_set_width(ui_KeytonesettingTitle, 665);
    lv_obj_set_height(ui_KeytonesettingTitle, 75);
    lv_obj_set_x(ui_KeytonesettingTitle, 12);
    lv_obj_set_y(ui_KeytonesettingTitle, 363);
    lv_obj_clear_flag(ui_KeytonesettingTitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingTitle, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_KeytonesettingTitle, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_KeytonesettingTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_KeytonesettingTitle, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_KeytonesettingTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_KeytonesettingTitle, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_KeytonesettingTitle, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_KeytonesettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_KeytonesettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_KeytonesettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_KeytonesettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingButton1 = lv_btn_create(ui_KeytonesettingTitle);
    lv_obj_set_width(ui_KeytonesettingButton1, 116);
    lv_obj_set_height(ui_KeytonesettingButton1, 60);
    lv_obj_set_x(ui_KeytonesettingButton1, 0);
    lv_obj_set_y(ui_KeytonesettingButton1, 10);
    lv_obj_set_align(ui_KeytonesettingButton1, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_KeytonesettingButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_KeytonesettingButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_KeytonesettingButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_KeytonesettingButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_KeytonesettingButton1, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_KeytonesettingButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_KeytonesettingButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_KeytonesettingButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_KeytonesettingButton1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_KeytonesettingButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_KeytonesettingButton1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingBtnLabel1 = lv_label_create(ui_KeytonesettingButton1);
    lv_obj_set_width(ui_KeytonesettingBtnLabel1, lv_pct(100));
    lv_obj_set_height(ui_KeytonesettingBtnLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_KeytonesettingBtnLabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_KeytonesettingBtnLabel1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_KeytonesettingBtnLabel1, Back[language_index]);
    lv_obj_set_style_text_align(ui_KeytonesettingBtnLabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_KeytonesettingBtnLabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingLabel1 = lv_label_create(ui_KeytonesettingPanel3);
    lv_obj_set_width(ui_KeytonesettingLabel1, 300);
    lv_obj_set_height(ui_KeytonesettingLabel1, 28);
    lv_obj_set_x(ui_KeytonesettingLabel1, 30);
    lv_obj_set_y(ui_KeytonesettingLabel1, 35);
    lv_label_set_long_mode(ui_KeytonesettingLabel1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_KeytonesettingLabel1, TouchToneSwitch[language_index]);
    lv_obj_set_style_text_color(ui_KeytonesettingLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_KeytonesettingLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_KeytonesettingLabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingSwitch1 = lv_switch_create(ui_KeytonesettingPanel3);
    lv_obj_set_width(ui_KeytonesettingSwitch1, 74);
    lv_obj_set_height(ui_KeytonesettingSwitch1, 36);
    lv_obj_set_x(ui_KeytonesettingSwitch1, 602);
    lv_obj_set_y(ui_KeytonesettingSwitch1, 35);

    lv_obj_set_style_bg_color(ui_KeytonesettingSwitch1, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_KeytonesettingSwitch1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_KeytonesettingLabel2 = lv_label_create(ui_KeytonesettingPanel3);
    lv_obj_set_width(ui_KeytonesettingLabel2, 300);
    lv_obj_set_height(ui_KeytonesettingLabel2, 28);
    lv_obj_set_x(ui_KeytonesettingLabel2, 30);
    lv_obj_set_y(ui_KeytonesettingLabel2, 105);
    lv_label_set_long_mode(ui_KeytonesettingLabel2, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_KeytonesettingLabel2, VolumeArray[language_index]);
    lv_obj_set_style_text_color(ui_KeytonesettingLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_KeytonesettingLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_KeytonesettingLabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    char buff[100] = {0};
    ui_KeytonesettingLabel3 = lv_label_create(ui_KeytonesettingPanel3);
    lv_obj_set_width(ui_KeytonesettingLabel3, 300);
    lv_obj_set_height(ui_KeytonesettingLabel3, 28);
    lv_obj_set_x(ui_KeytonesettingLabel3, 30);
    lv_obj_set_y(ui_KeytonesettingLabel3, 181);
    lv_label_set_long_mode(ui_KeytonesettingLabel3, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_KeytonesettingLabel3, SoundEffect[language_index]);
    lv_obj_set_style_text_color(ui_KeytonesettingLabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_KeytonesettingLabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_KeytonesettingLabel3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    memset(buff, 0, sizeof(buff));
    // sprintf(buff, "%s\n%s\n%s\n%s", Technology[language_index], Agile[language_index], 
    //             Brief[language_index], Crisp[language_index]);
    // sprintf(buff, "%s\n%s\n%s\n%s", Technology[0], Agile[0], Brief[0], Crisp[0]);

    ui_KeytonesettingDropdown1 = lv_dropdown_create(ui_KeytonesettingPanel3);
    lv_dropdown_set_options(ui_KeytonesettingDropdown1, buff);
    lv_obj_set_width(ui_KeytonesettingDropdown1, 300);
    lv_obj_set_height(ui_KeytonesettingDropdown1, 50);
    lv_obj_set_x(ui_KeytonesettingDropdown1, 376);
    lv_obj_set_y(ui_KeytonesettingDropdown1, 171);
    lv_obj_add_flag(ui_KeytonesettingDropdown1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_KeytonesettingDropdown1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_KeytonesettingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_KeytonesettingDropdown1, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_KeytonesettingDropdown1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_KeytonesettingDropdown1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_KeytonesettingDropdown1, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_KeytonesettingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_KeytonesettingDropdown1, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_KeytonesettingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_KeytonesettingDropdown1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_KeytonesettingDropdown1, 17, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_KeytonesettingDropdown1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_KeytonesettingDropdown1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_KeytonesettingDropdown1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_KeytonesettingDropdown1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_KeytonesettingDropdown1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_KeytonesettingDropdown1, LV_TEXT_ALIGN_LEFT, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_KeytonesettingDropdown1, lv_font24.font, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_KeytonesettingSlider1 = lv_slider_create(ui_KeytonesettingPanel3);
    lv_slider_set_range(ui_KeytonesettingSlider1, 0, 10);
    lv_slider_set_value(ui_KeytonesettingSlider1, 10, LV_ANIM_OFF);
    lv_obj_set_width(ui_KeytonesettingSlider1, 207);
    lv_obj_set_height(ui_KeytonesettingSlider1, 8);
    lv_obj_set_x(ui_KeytonesettingSlider1, 419);
    lv_obj_set_y(ui_KeytonesettingSlider1, 118);
    lv_obj_set_style_radius(ui_KeytonesettingSlider1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_KeytonesettingSlider1, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_KeytonesettingSlider1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_KeytonesettingSlider1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_KeytonesettingSlider1, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_KeytonesettingSlider1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_KeytonesettingSlider1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_KeytonesettingSlider1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_KeytonesettingSlider1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_KeytonesettingImage6 = lv_img_create(ui_KeytonesettingPanel3);
    lv_img_set_src(ui_KeytonesettingImage6, &ui_img_group_246_png);
    lv_obj_set_width(ui_KeytonesettingImage6, 38);
    lv_obj_set_height(ui_KeytonesettingImage6, 38);
    lv_obj_set_x(ui_KeytonesettingImage6, 381);
    lv_obj_set_y(ui_KeytonesettingImage6, 103);
    lv_obj_add_flag(ui_KeytonesettingImage6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_KeytonesettingImage6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingImage6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeytonesettingImage7 = lv_img_create(ui_KeytonesettingPanel3);
    lv_img_set_src(ui_KeytonesettingImage7, &ui_img_group_245_png);
    lv_obj_set_width(ui_KeytonesettingImage7, 38);
    lv_obj_set_height(ui_KeytonesettingImage7, 38);
    lv_obj_set_x(ui_KeytonesettingImage7, 638);
    lv_obj_set_y(ui_KeytonesettingImage7, 103);
    lv_obj_add_flag(ui_KeytonesettingImage7, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_KeytonesettingImage7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_KeytonesettingImage7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_KeytonesettingButton1, ui_event_KeytonesettingButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_KeytonesettingSwitch1, ui_event_KeytonesettingSwitch1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_KeytonesettingSlider1, ui_event_KeytonesettingSlider1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_KeytonesettingDropdown1, ui_event_KeytonesettingDropdown1, LV_EVENT_ALL, NULL);
}

void ui_event_KeytonesettingButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_KeytonesettingSwitch1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if(lv_obj_has_state(ui_KeytonesettingSwitch1, LV_STATE_CHECKED))
        {
            CrLogI("open the sound");
            set_printer_data(0x06,2,"a1");
        }
        else
        {
            CrLogI("close the sound");
            set_printer_data(0x06,2,"a0");
        }
    }
}

void ui_event_KeytonesettingSlider1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED){
        int volumevalue = 0;
        volumevalue = lv_slider_get_value(ui_KeytonesettingSlider1);
        char temp[5] = {0};
        snprintf(temp,5,"h%d",volumevalue);
        set_printer_data(0x06,strlen(temp),temp);
    }
}

void ui_event_KeytonesettingDropdown1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        send_buzzer(0x01);
        uint16_t index;
        index = lv_dropdown_get_selected(ui_KeytonesettingDropdown1);
        CrLogI("keytone_setting_ddlist_1 value is %d\n",index);
        switch(index)
        {
            case 0: set_printer_data(0x06,2,"i1");break;
            case 1: set_printer_data(0x06,2,"i2");break;
            case 2: set_printer_data(0x06,2,"i3");break;
            case 3: set_printer_data(0x06,2,"i4");break;
            default:break;
        }
    }
    if(event_code == LV_EVENT_READY) {
        static lv_style_t list_selected_default;
        if (list_selected_default.prop_cnt > 1)
            lv_style_reset(&list_selected_default);
        else
            lv_style_init(&list_selected_default);
        lv_style_set_radius(&list_selected_default, 0);
        lv_style_set_bg_color(&list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
        lv_style_set_bg_grad_color(&list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
        lv_style_set_bg_grad_dir(&list_selected_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&list_selected_default, 255);
        lv_style_set_border_color(&list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
        lv_style_set_border_width(&list_selected_default, 0);
        lv_style_set_text_color(&list_selected_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_text_font(&list_selected_default, lv_font24.font);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

        static lv_style_t list_main_default;
        if (list_main_default.prop_cnt > 1)
            lv_style_reset(&list_main_default);
        else
            lv_style_init(&list_main_default);
        lv_style_set_radius(&list_main_default, 0);
        lv_style_set_bg_color(&list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
        lv_style_set_bg_grad_color(&list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
        lv_style_set_bg_grad_dir(&list_main_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&list_main_default, 255);
        lv_style_set_border_color(&list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
        lv_style_set_border_width(&list_main_default, 0);
        lv_style_set_text_color(&list_main_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_text_font(&list_main_default, lv_font24.font);
        // lv_style_set_max_height(&list_main_default, 150);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

        static lv_style_t list_scrollbar_default;
        if (list_scrollbar_default.prop_cnt > 1)
            lv_style_reset(&list_scrollbar_default);
        else
            lv_style_init(&list_scrollbar_default);
        lv_style_set_radius(&list_scrollbar_default, 3);
        lv_style_set_bg_color(&list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
        lv_style_set_bg_grad_color(&list_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_bg_grad_dir(&list_scrollbar_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&list_scrollbar_default, 255);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    }
}

void touch_tone_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    char buff[100] = {0};
    if ( ui_KeytonesettingBtnLabel1 )
        lv_label_set_text(ui_KeytonesettingBtnLabel1, Back[language_index]);
    
    // if ( ui_KeytonesettingLabel1 )
    //     lv_label_set_text(ui_KeytonesettingLabel1, TouchToneSwitch[language_index]);
    
    // if ( ui_KeytonesettingLabel2 )
    //     lv_label_set_text(ui_KeytonesettingLabel2, VolumeArray[language_index]);

    // if ( ui_KeytonesettingLabel3 )
    // {
    //     lv_label_set_text(ui_KeytonesettingLabel3, SoundEffect[language_index]);
    // }

    // if ( ui_KeytonesettingDropdown1 )
    // {
    //     memset(buff, 0, sizeof(buff));
    //     sprintf(buff, "%s\n%s\n%s\n%s", Technology[language_index], Agile[language_index], 
    //                 Brief[language_index], Crisp[language_index]);

    //     uint8_t id = lv_dropdown_get_selected(ui_KeytonesettingDropdown1);
    //     lv_dropdown_clear_options(ui_KeytonesettingDropdown1);
    //     lv_dropdown_set_options(ui_KeytonesettingDropdown1, buff);
    //     lv_dropdown_set_selected(ui_KeytonesettingDropdown1, id);
    // }
}