#include "ui.h"
#include "mult_language.h"

lv_obj_t * ui_Manualtest;
lv_obj_t * ui_ManualtestPanel1;
lv_obj_t * ui_ManualtestImage1;
lv_obj_t * ui_ManualtestImage2;
lv_obj_t * ui_ManualtestImage3;
lv_obj_t * ui_ManualtestImage4;
lv_obj_t * ui_ManualtestImage5;
lv_obj_t * ui_ManualtestPanel2;
lv_obj_t * ui_ManualtestPanel3;
lv_obj_t * ui_ManualtestPanel4;
lv_obj_t * ui_ManualtestLabel2;
lv_obj_t * ui_ManualtestButton1;
lv_obj_t * ui_ManualtestBtnlabel1;
lv_obj_t * ui_ManualtestLabel1;
lv_obj_t * ui_ManualtestCheckbox1;
lv_obj_t * ui_ManualtestCheckbox2;
lv_obj_t * ui_ManualtestCheckbox3;
lv_obj_t * ui_ManualtestCheckbox4;
lv_obj_t * ui_ManualtestCheckbox5;
lv_obj_t * ui_ManualtestCheckbox6;
lv_obj_t * ui_ManualtestCheckbox7;
lv_obj_t * ui_ManualtestCheckbox8;
lv_obj_t * ui_ManualtestCheckbox9;
lv_obj_t * ui_ManualtestButton2;
lv_obj_t * ui_ManualtestBtnlabel2;
lv_obj_t * ui_ManualtestButton3;
lv_obj_t * ui_ManualtestBtnlabel3;

static bool is_all_selected = false;

void ui_event_ManualtestButton1(lv_event_t * e);
void ui_event_ManualtestButton2(lv_event_t * e);
void ui_event_ManualtestButton3(lv_event_t * e);
void ui_event_ui_ManualtestImage1(lv_event_t * e);
void ui_event_ui_ManualtestImage2(lv_event_t * e);
void ui_event_ui_ManualtestImage3(lv_event_t * e);
void ui_event_ui_ManualtestImage4(lv_event_t * e);
void ui_event_ui_ManualtestImage5(lv_event_t * e);
void ui_event_ui_Manualtest(lv_event_t * e);
void ui_Manualtest_screen_init(void)
{
    ui_Manualtest = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Manualtest, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    char buff[80] = {0};
    ui_ManualtestPanel1 = lv_obj_create(ui_Manualtest);
    lv_obj_set_width(ui_ManualtestPanel1, 80);
    lv_obj_set_height(ui_ManualtestPanel1, 480);
    lv_obj_clear_flag(ui_ManualtestPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ManualtestPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ManualtestPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ManualtestPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ManualtestPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestImage1 = lv_img_create(ui_ManualtestPanel1);
    lv_img_set_src(ui_ManualtestImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_ManualtestImage1, 80);
    lv_obj_set_height(ui_ManualtestImage1, 96);
    lv_obj_add_flag(ui_ManualtestImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ManualtestImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestImage2 = lv_img_create(ui_ManualtestPanel1);
    lv_img_set_src(ui_ManualtestImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_ManualtestImage2, 80);
    lv_obj_set_height(ui_ManualtestImage2, 96);
    lv_obj_set_x(ui_ManualtestImage2, 0);
    lv_obj_set_y(ui_ManualtestImage2, 96);
    lv_obj_add_flag(ui_ManualtestImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ManualtestImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestImage3 = lv_img_create(ui_ManualtestPanel1);
    lv_img_set_src(ui_ManualtestImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_ManualtestImage3, 80);
    lv_obj_set_height(ui_ManualtestImage3, 96);
    lv_obj_set_x(ui_ManualtestImage3, 0);
    lv_obj_set_y(ui_ManualtestImage3, 192);
    lv_obj_add_flag(ui_ManualtestImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ManualtestImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestImage4 = lv_img_create(ui_ManualtestPanel1);
    lv_img_set_src(ui_ManualtestImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_ManualtestImage4, 80);
    lv_obj_set_height(ui_ManualtestImage4, 96);
    lv_obj_set_x(ui_ManualtestImage4, 0);
    lv_obj_set_y(ui_ManualtestImage4, 288);
    lv_obj_add_flag(ui_ManualtestImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ManualtestImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestImage5 = lv_img_create(ui_ManualtestPanel1);
    lv_img_set_src(ui_ManualtestImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_ManualtestImage5, 80);
    lv_obj_set_height(ui_ManualtestImage5, 96);
    lv_obj_set_x(ui_ManualtestImage5, 0);
    lv_obj_set_y(ui_ManualtestImage5, 384);
    lv_obj_add_flag(ui_ManualtestImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ManualtestImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestPanel2 = lv_obj_create(ui_Manualtest);
    lv_obj_set_width(ui_ManualtestPanel2, 720);
    lv_obj_set_height(ui_ManualtestPanel2, 480);
    lv_obj_set_x(ui_ManualtestPanel2, 80);
    lv_obj_set_y(ui_ManualtestPanel2, 0);
    lv_obj_clear_flag(ui_ManualtestPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ManualtestPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ManualtestPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ManualtestPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ManualtestPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestPanel3 = lv_obj_create(ui_ManualtestPanel2);
    lv_obj_set_width(ui_ManualtestPanel3, 696);
    lv_obj_set_height(ui_ManualtestPanel3, 456);
    lv_obj_set_x(ui_ManualtestPanel3, 0);
    lv_obj_set_y(ui_ManualtestPanel3, 0);
    lv_obj_set_align(ui_ManualtestPanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ManualtestPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestPanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ManualtestPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ManualtestPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ManualtestPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ManualtestPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestPanel4 = lv_obj_create(ui_ManualtestPanel3);
    lv_obj_set_width(ui_ManualtestPanel4, 660);
    lv_obj_set_height(ui_ManualtestPanel4, 65);
    lv_obj_set_x(ui_ManualtestPanel4, 18);
    lv_obj_set_y(ui_ManualtestPanel4, 2);
    lv_obj_clear_flag(ui_ManualtestPanel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestPanel4, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestPanel4, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestPanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestPanel4, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestPanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestPanel4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ManualtestPanel4, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ManualtestPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ManualtestPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ManualtestPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ManualtestPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestLabel2 = lv_label_create(ui_ManualtestPanel4);
    lv_obj_set_width(ui_ManualtestLabel2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ManualtestLabel2, 24);
    lv_obj_set_x(ui_ManualtestLabel2, 5);
    lv_obj_set_y(ui_ManualtestLabel2, 0);
    lv_obj_set_align(ui_ManualtestLabel2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ManualtestLabel2, DetectionItemArray[language_index]);
    lv_obj_set_style_text_color(ui_ManualtestLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestLabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestButton1 = lv_btn_create(ui_ManualtestPanel4);
    lv_obj_set_width(ui_ManualtestButton1, 300);
    lv_obj_set_height(ui_ManualtestButton1, 33);
    lv_obj_set_x(ui_ManualtestButton1, 0);
    lv_obj_set_y(ui_ManualtestButton1, 18);
    lv_obj_set_align(ui_ManualtestButton1, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_ManualtestButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ManualtestButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestButton1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ManualtestButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ManualtestButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ManualtestButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestButton1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestBtnlabel1 = lv_label_create(ui_ManualtestButton1);
    lv_obj_set_width(ui_ManualtestBtnlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ManualtestBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ManualtestBtnlabel1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_ManualtestBtnlabel1, SelectAll[language_index]);
    lv_obj_set_style_text_color(ui_ManualtestBtnlabel1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ManualtestBtnlabel1, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ManualtestBtnlabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ManualtestBtnlabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ManualtestBtnlabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ManualtestBtnlabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestLabel1 = lv_label_create(ui_ManualtestPanel3);
    lv_obj_set_width(ui_ManualtestLabel1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ManualtestLabel1, 30);
    lv_obj_set_x(ui_ManualtestLabel1, 28);
    lv_obj_set_y(ui_ManualtestLabel1, 340);
    lv_label_set_recolor(ui_ManualtestLabel1, true); 
    // sprintf(buff, "#6A707D %s##42bdd8 15##6A707D %s.#", SelfTestTipsMsg[language_index], MinuteArray[language_index]); 
    lv_label_set_text(ui_ManualtestLabel1, SelfTestTipsMsg[language_index]);
    lv_obj_set_style_text_opa(ui_ManualtestLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestLabel1, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestCheckbox1 = lv_checkbox_create(ui_ManualtestPanel3);
    lv_checkbox_set_text(ui_ManualtestCheckbox1, VibrationOptimization[language_index]);
    lv_obj_set_width(ui_ManualtestCheckbox1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ManualtestCheckbox1, 33);
    lv_obj_set_x(ui_ManualtestCheckbox1, 36);
    lv_obj_set_y(ui_ManualtestCheckbox1, 96);
    lv_obj_add_flag(ui_ManualtestCheckbox1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox1, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox1, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox1, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox2 = lv_checkbox_create(ui_ManualtestPanel3);
    lv_checkbox_set_text(ui_ManualtestCheckbox2, AutoLevel[language_index]);
    lv_obj_set_width(ui_ManualtestCheckbox2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ManualtestCheckbox2, 33);
    lv_obj_set_x(ui_ManualtestCheckbox2, 36);
    lv_obj_set_y(ui_ManualtestCheckbox2, 149);
    lv_obj_add_flag(ui_ManualtestCheckbox2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox2, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox2, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox2, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox2, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox3 = lv_checkbox_create(ui_ManualtestPanel3);
    memset(buff, 0, sizeof(buff));
    // sprintf(buff, "%s%s", HotendArray[language_index], PIDAdjustment[language_index]);
    lv_checkbox_set_text(ui_ManualtestCheckbox3, buff); 
    lv_obj_set_width(ui_ManualtestCheckbox3, 240);
    lv_obj_set_height(ui_ManualtestCheckbox3, 33);
    lv_obj_set_x(ui_ManualtestCheckbox3, 36);
    lv_obj_set_y(ui_ManualtestCheckbox3, 205);
    lv_obj_add_flag(ui_ManualtestCheckbox3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox3, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox3, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox3, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox3, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox4 = lv_checkbox_create(ui_ManualtestPanel3);
    memset(buff, 0, sizeof(buff));
    // sprintf(buff, "%s%s", BedArray[language_index], PIDAdjustment[language_index]);
    lv_checkbox_set_text(ui_ManualtestCheckbox4, buff);
    lv_obj_set_width(ui_ManualtestCheckbox4, 240);
    lv_obj_set_height(ui_ManualtestCheckbox4, 33);
    lv_obj_set_x(ui_ManualtestCheckbox4, 36);
    lv_obj_set_y(ui_ManualtestCheckbox4, 261);
    lv_obj_add_flag(ui_ManualtestCheckbox4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox4, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox4, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox4, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox4, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox5 = lv_checkbox_create(ui_ManualtestPanel3);
    lv_checkbox_set_text(ui_ManualtestCheckbox5, VibrationCompensation[language_index]); 
    lv_obj_set_width(ui_ManualtestCheckbox5, 340);
    lv_obj_set_height(ui_ManualtestCheckbox5, 33);
    lv_obj_set_x(ui_ManualtestCheckbox5, 36);
    lv_obj_set_y(ui_ManualtestCheckbox5, 316);
    lv_obj_add_flag(ui_ManualtestCheckbox5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox5, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox5, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox5, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox5, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox5, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox5, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox5, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox5, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox5, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox5, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox5, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox6 = lv_checkbox_create(ui_ManualtestPanel3);
    lv_obj_set_width(ui_ManualtestCheckbox6, 240);
    lv_obj_set_height(ui_ManualtestCheckbox6, 33);
    lv_obj_set_x(ui_ManualtestCheckbox6, 430);
    lv_obj_set_y(ui_ManualtestCheckbox6, 96);
    lv_obj_add_flag(ui_ManualtestCheckbox6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox6, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox6, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox6, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox6, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox6, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox6, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox6, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox6, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox6, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox6, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox6, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox7 = lv_checkbox_create(ui_ManualtestPanel3);
    memset(buff, 0, sizeof(buff));
    // sprintf(buff, "%s%s", ProbeArray[language_index], Detection[language_index]);
    lv_checkbox_set_text(ui_ManualtestCheckbox7, buff);
    lv_obj_set_width(ui_ManualtestCheckbox7, 240);
    lv_obj_set_height(ui_ManualtestCheckbox7, 33);
    lv_obj_set_x(ui_ManualtestCheckbox7, 430);
    lv_obj_set_y(ui_ManualtestCheckbox7, 149);
    lv_obj_add_flag(ui_ManualtestCheckbox7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox7, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox7, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox7, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox7, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox7, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox7, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox7, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox7, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox7, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox7, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox7, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox8 = lv_checkbox_create(ui_ManualtestPanel3);
    memset(buff, 0, sizeof(buff));
    // sprintf(buff, "%s%s", RunoutArray[language_index], Detection[language_index]);
    lv_checkbox_set_text(ui_ManualtestCheckbox8, buff);
    lv_obj_set_width(ui_ManualtestCheckbox8, 240);
    lv_obj_set_height(ui_ManualtestCheckbox8, 33);
    lv_obj_set_x(ui_ManualtestCheckbox8, 430);
    lv_obj_set_y(ui_ManualtestCheckbox8, 205);
    lv_obj_add_flag(ui_ManualtestCheckbox8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox8, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox8, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox8, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox8, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox8, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox8, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox8, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox8, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox8, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox8, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox8, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox9 = lv_checkbox_create(ui_ManualtestPanel3);
    lv_checkbox_set_text(ui_ManualtestCheckbox9, AutoLevel[language_index]);
    lv_obj_set_width(ui_ManualtestCheckbox9, 240);
    lv_obj_set_height(ui_ManualtestCheckbox9, 33);
    lv_obj_set_x(ui_ManualtestCheckbox9, 430);
    lv_obj_set_y(ui_ManualtestCheckbox9, 261);
    lv_obj_add_flag(ui_ManualtestCheckbox9, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox9, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox9, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox9, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox9, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox9, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox9, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox9, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox9, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox9, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox9, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox9, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestButton2 = lv_btn_create(ui_ManualtestPanel3);
    lv_obj_set_width(ui_ManualtestButton2, 140);
    lv_obj_set_height(ui_ManualtestButton2, 60);
    lv_obj_align(ui_ManualtestButton2, LV_ALIGN_BOTTOM_RIGHT, -20, -15);
    lv_obj_add_flag(ui_ManualtestButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ManualtestButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestButton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestButton2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ManualtestButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ManualtestButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ManualtestButton2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestButton2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestBtnlabel2 = lv_label_create(ui_ManualtestButton2);
    lv_obj_set_width(ui_ManualtestBtnlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ManualtestBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ManualtestBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ManualtestBtnlabel2, StartDetection[language_index]);
    lv_obj_set_style_text_color(ui_ManualtestBtnlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestBtnlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestButton3 = lv_btn_create(ui_ManualtestPanel3);
    lv_obj_set_width(ui_ManualtestButton3, 116);
    lv_obj_set_height(ui_ManualtestButton3, 60);
    lv_obj_align_to(ui_ManualtestButton3, ui_ManualtestButton2, LV_ALIGN_OUT_LEFT_MID, -25, 0);
    lv_obj_add_flag(ui_ManualtestButton3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ManualtestButton3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestButton3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestButton3, lv_color_hex(0x28292d), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestButton3, lv_color_hex(0x4a4e57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestButton3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ManualtestButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ManualtestButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ManualtestButton3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestButton3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestBtnlabel3 = lv_label_create(ui_ManualtestButton3);
    lv_obj_set_width(ui_ManualtestBtnlabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ManualtestBtnlabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ManualtestBtnlabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ManualtestBtnlabel3, Back[language_index]);
    lv_obj_set_style_text_color(ui_ManualtestBtnlabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestBtnlabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestBtnlabel3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ManualtestImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_ManualtestImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_ManualtestImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_ManualtestImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_ManualtestImage5, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    lv_obj_add_event_cb(ui_ManualtestButton1, ui_event_ManualtestButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ManualtestButton2, ui_event_ManualtestButton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ManualtestButton3, ui_event_ManualtestButton3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ManualtestImage1, ui_event_ui_ManualtestImage1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ManualtestImage2, ui_event_ui_ManualtestImage2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ManualtestImage3, ui_event_ui_ManualtestImage3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ManualtestImage4, ui_event_ui_ManualtestImage4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ManualtestImage5, ui_event_ui_ManualtestImage5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Manualtest, ui_event_ui_Manualtest, LV_EVENT_ALL, NULL);

}

void ui_event_ManualtestButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        uint8_t index = get_cur_language_index();

        if( !is_all_selected )
        {
            lv_obj_add_state(ui_ManualtestCheckbox1, LV_STATE_CHECKED);
            lv_obj_add_state(ui_ManualtestCheckbox2, LV_STATE_CHECKED);
            lv_obj_add_state(ui_ManualtestCheckbox3, LV_STATE_CHECKED);
            lv_obj_add_state(ui_ManualtestCheckbox4, LV_STATE_CHECKED);
            lv_obj_add_state(ui_ManualtestCheckbox5, LV_STATE_CHECKED);
            lv_obj_add_state(ui_ManualtestCheckbox6, LV_STATE_CHECKED);
            lv_obj_add_state(ui_ManualtestCheckbox7, LV_STATE_CHECKED);
            lv_obj_add_state(ui_ManualtestCheckbox8, LV_STATE_CHECKED);
            lv_obj_add_state(ui_ManualtestCheckbox9, LV_STATE_CHECKED);
            lv_label_set_text(ui_ManualtestBtnlabel1,NotSelectAll[index]);
            is_all_selected = true;
            return ;
        }
        else
        {
            lv_obj_clear_state(ui_ManualtestCheckbox1, LV_STATE_CHECKED);
            lv_obj_clear_state(ui_ManualtestCheckbox2, LV_STATE_CHECKED);
            lv_obj_clear_state(ui_ManualtestCheckbox3, LV_STATE_CHECKED);
            lv_obj_clear_state(ui_ManualtestCheckbox4, LV_STATE_CHECKED);
            lv_obj_clear_state(ui_ManualtestCheckbox5, LV_STATE_CHECKED);
            lv_obj_clear_state(ui_ManualtestCheckbox6, LV_STATE_CHECKED);
            lv_obj_clear_state(ui_ManualtestCheckbox7, LV_STATE_CHECKED);
            lv_obj_clear_state(ui_ManualtestCheckbox8, LV_STATE_CHECKED);
            lv_obj_clear_state(ui_ManualtestCheckbox9, LV_STATE_CHECKED);
            lv_label_set_text(ui_ManualtestBtnlabel1, SelectAll[get_cur_language_index()]);
            is_all_selected = false;
        }
    }
}

void ui_event_ManualtestButton2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if(print_state != 1)
        {
            CrLogI("manualtest page:machine state is print %d,don't start the print",print_state);
            create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
            return;
        }
        else
        {
            CrLogI("manualtest page:machine state is print %d,start the manualtest",print_state);
            manualtestcount = 100;
            if(lv_obj_has_state(ui_ManualtestCheckbox1,LV_STATE_CHECKED))  //振纹优化
            {
                manualtestcount += 10;
            }
            if(lv_obj_has_state(ui_ManualtestCheckbox2,LV_STATE_CHECKED))  //自动调平
            {
                manualtestcount += 1;
            }
            if(manualtestcount != 100)
                _ui_screen_change(ui_SelftestAll, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        }
        // int i = 0;
        // if(lv_obj_has_state(ui_ManualtestCheckbox1,LV_STATE_CHECKED))  //喉管风扇
        //     Manualtest[i++] = 1;
        // if(lv_obj_has_state(ui_ManualtestCheckbox2,LV_STATE_CHECKED))  //模型风扇
        //     Manualtest[i++] = 2;
        // // if(lv_obj_has_state(ui_ManualtestCheckbox3,LV_STATE_CHECKED))  //喷头PID
        // //     Manualtest[i++] = 3;
        // // if(lv_obj_has_state(ui_ManualtestCheckbox4,LV_STATE_CHECKED))  //热床PID
        // // //     Manualtest[i++] = 4;
        // // if(lv_obj_has_state(ui_ManualtestCheckbox5,LV_STATE_CHECKED))  //振动补偿
        // //     Manualtest[i++] = 5;
        // // if(lv_obj_has_state(ui_ManualtestCheckbox6,LV_STATE_CHECKED))  //归位检测
        // //     Manualtest[i++] = 6;
        // // // if(lv_obj_has_state(ui_ManualtestCheckbox8,LV_STATE_CHECKED))  //断料检测
        // // //     Manualtest[i++] = 7;
        // // if(lv_obj_has_state(ui_ManualtestCheckbox9,LV_STATE_CHECKED))  //自动调平
        // // {
        // //     // Manualtest[i++] = 8;
        // //     Manualtest[i++] = 9;
        // // }
        // Manualtest[i] = '\0';
        // Manualtestlength = i;
        // //决定跳转页面
        // if(Manualtestlength > 0)
        // {
        //     Manualtest_curpage = 0;
        //     change_manualtest_page(Manualtest[Manualtest_curpage]);
        // }

    }
}

void ui_event_ManualtestButton3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_ui_ManualtestImage1(lv_event_t * e)
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
void ui_event_ui_ManualtestImage2(lv_event_t * e)
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
void ui_event_ui_ManualtestImage3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadFileManageScreen();
    }
}
void ui_event_ui_ManualtestImage4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_ui_ManualtestImage5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadCustomerServiceScreen();
    }
}

void ui_event_ui_Manualtest(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        // lv_obj_add_flag(ui_ManualtestCheckbox1,LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(ui_ManualtestCheckbox2,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox3,LV_OBJ_FLAG_HIDDEN);

        lv_obj_add_flag(ui_ManualtestCheckbox4,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox5,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox6,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox7,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox8,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox9,LV_OBJ_FLAG_HIDDEN);

        char buff[80]; 
        uint8_t index = get_cur_language_index();
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", HomeArray[index], Detection[index]);
        // lv_checkbox_set_text(ui_ManualtestCheckbox1, buff);
        lv_checkbox_set_text(ui_ManualtestCheckbox1, VibrationOptimization[index]);
        lv_checkbox_set_text(ui_ManualtestCheckbox2, AutoLevel[index]);
    }

}

void manual_test_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    char buff[80] = {0};
    if ( ui_ManualtestLabel2 )
    lv_label_set_text(ui_ManualtestLabel2, DetectionItemArray[language_index]);

    if ( ui_ManualtestBtnlabel1 )
    lv_label_set_text(ui_ManualtestBtnlabel1, SelectAll[language_index]);

    if ( ui_ManualtestLabel1 )
    {
        // sprintf(buff, "#6A707D %s##42bdd8 15##6A707D %s.#", SelfTestTipsMsg[language_index], MinuteArray[language_index]); 
        lv_label_set_text(ui_ManualtestLabel1, SelfTestTipsMsg[language_index]);
    }

    if ( ui_ManualtestCheckbox1 )
        lv_checkbox_set_text(ui_ManualtestCheckbox1, VibrationOptimization[language_index]);

    if ( ui_ManualtestCheckbox2 )
    lv_checkbox_set_text(ui_ManualtestCheckbox2, AutoLevel[language_index]);

    // if ( ui_ManualtestCheckbox3 )
    // {
    //     memset(buff, 0, sizeof(buff));
    //     sprintf(buff, "%s%s", HotendArray[language_index], PIDAdjustment[language_index]);
    //     lv_checkbox_set_text(ui_ManualtestCheckbox3, buff); 
    // }

    // if ( ui_ManualtestCheckbox4 )
    // {
    //     memset(buff, 0, sizeof(buff));
    //     sprintf(buff, "%s%s", BedArray[language_index], PIDAdjustment[language_index]);
    //     lv_checkbox_set_text(ui_ManualtestCheckbox4, buff);
    // }


    // if ( ui_ManualtestCheckbox5 )
    //     lv_checkbox_set_text(ui_ManualtestCheckbox5, VibrationCompensation[language_index]); 

    // if ( ui_ManualtestCheckbox6 )
    // {
    //     memset(buff, 0, sizeof(buff));
    //     sprintf(buff, "%s%s", HomeArray[language_index], Detection[language_index]);
    //     lv_checkbox_set_text(ui_ManualtestCheckbox6, buff);
    // }


    // if ( ui_ManualtestCheckbox7 )
    // {
    //     memset(buff, 0, sizeof(buff));
    //     sprintf(buff, "%s%s", ProbeArray[language_index], Detection[language_index]);
    //     lv_checkbox_set_text(ui_ManualtestCheckbox7, buff);
    // }


    // if ( ui_ManualtestCheckbox8 )
    // {
    //     memset(buff, 0, sizeof(buff));
    //     sprintf(buff, "%s%s", RunoutArray[language_index], Detection[language_index]);
    //     lv_checkbox_set_text(ui_ManualtestCheckbox8, buff);
    // }

    // if ( ui_ManualtestCheckbox9 )
    //     lv_checkbox_set_text(ui_ManualtestCheckbox9, AutoLevel[language_index]);

    if ( ui_ManualtestBtnlabel2 )
    {
        lv_label_set_text(ui_ManualtestBtnlabel2, StartDetection[language_index]);
        redefine_label_size(ui_ManualtestBtnlabel2, lv_font24.font, 0, 0, 240, 0);

        lv_obj_update_layout(ui_ManualtestButton2);
        redefine_widgets_size(ui_ManualtestButton2, ui_ManualtestBtnlabel2, 10, 0, 116, 60);

        lv_obj_align_to(ui_ManualtestButton3, ui_ManualtestButton2, LV_ALIGN_OUT_LEFT_MID, -25, 0);
    }

    if ( ui_ManualtestBtnlabel3 )
        lv_label_set_text(ui_ManualtestBtnlabel3, Back[language_index]);

    if ( !ui_ManualtestBtnlabel1 )
        return ;

    if ( is_all_selected )
    {
        lv_label_set_text(ui_ManualtestBtnlabel1,NotSelectAll[language_index]);
    }
    else
        lv_label_set_text(ui_ManualtestBtnlabel1,SelectAll[language_index]);
}
