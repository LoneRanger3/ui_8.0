#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "mult_language.h"

lv_obj_t * ui_Devicebinding;
lv_obj_t * ui_DevicebindingPanel1;
lv_obj_t * ui_DevicebindingImage1;
lv_obj_t * ui_DevicebindingImage2;
lv_obj_t * ui_DevicebindingImage3;
lv_obj_t * ui_DevicebindingImage4;
lv_obj_t * ui_DevicebindingImage5;
lv_obj_t * ui_DevicebindingPanel2;
lv_obj_t * ui_DevicebindingPanel3;
lv_obj_t * ui_DevicebindingPanel4;
lv_obj_t * ui_DevicebindingTitle;
lv_obj_t * ui_DevicebindingLabel1;
lv_obj_t * ui_DevicebindingButton1;
lv_obj_t * ui_DevicebindingBtnlabel1;
lv_obj_t * ui_DevicebindingLabel2;
lv_obj_t * ui_DevicebindingLabel3;
lv_obj_t * ui_DevicebindingDropdown1;
lv_obj_t * ui_DevicebindingImage6;
lv_obj_t * ui_DevicebindingLabel4;
lv_obj_t * ui_DevicebindingPanel5;
lv_obj_t * ui_DevicebindingPanel6;
lv_obj_t * ui_DevicebindingUserimg;
lv_obj_t * ui_DevicebindingUsername;
lv_obj_t * ui_DevicebindingUserid;
lv_obj_t * ui_DevicebindingUserBtn;
lv_obj_t * ui_DevicebindingUserBtnlabel;

lv_timer_t * refreshTimer = NULL;
lv_timer_t * createTimerForRefreshState();
void deleteTimerForRefreshState(lv_timer_t * timer);

void ui_event_Devicebinding(lv_event_t * e);
void ui_event_DevicebindingImage1(lv_event_t * e);
void ui_event_DevicebindingImage2(lv_event_t * e);
void ui_event_DevicebindingImage3(lv_event_t * e);
void ui_event_DevicebindingImage4(lv_event_t * e);
void ui_event_DevicebindingImage5(lv_event_t * e);
void ui_event_DevicebindingDropdown(lv_event_t * e);
void ui_event_DevicebindingUserBtn(lv_event_t * e);

void ui_Devicebinding_screen_init(void)
{
    ui_Devicebinding = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Devicebinding, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    ui_DevicebindingPanel1 = lv_obj_create(ui_Devicebinding);
    lv_obj_set_width(ui_DevicebindingPanel1, 80);
    lv_obj_set_height(ui_DevicebindingPanel1, 480);
    lv_obj_clear_flag(ui_DevicebindingPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DevicebindingPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DevicebindingPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_DevicebindingPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_DevicebindingPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_DevicebindingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_DevicebindingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_DevicebindingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_DevicebindingPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingImage1 = lv_img_create(ui_DevicebindingPanel1);
    lv_img_set_src(ui_DevicebindingImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_DevicebindingImage1, 80);
    lv_obj_set_height(ui_DevicebindingImage1, 96);
    lv_obj_add_flag(ui_DevicebindingImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_DevicebindingImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_DevicebindingImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingImage2 = lv_img_create(ui_DevicebindingPanel1);
    lv_img_set_src(ui_DevicebindingImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_DevicebindingImage2, 80);
    lv_obj_set_height(ui_DevicebindingImage2, 96);
    lv_obj_set_x(ui_DevicebindingImage2, 0);
    lv_obj_set_y(ui_DevicebindingImage2, 96);
    lv_obj_add_flag(ui_DevicebindingImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_DevicebindingImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_DevicebindingImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingImage3 = lv_img_create(ui_DevicebindingPanel1);
    lv_img_set_src(ui_DevicebindingImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_DevicebindingImage3, 80);
    lv_obj_set_height(ui_DevicebindingImage3, 96);
    lv_obj_set_x(ui_DevicebindingImage3, 0);
    lv_obj_set_y(ui_DevicebindingImage3, 192);
    lv_obj_add_flag(ui_DevicebindingImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_DevicebindingImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_DevicebindingImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingImage4 = lv_img_create(ui_DevicebindingPanel1);
    lv_img_set_src(ui_DevicebindingImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_DevicebindingImage4, 80);
    lv_obj_set_height(ui_DevicebindingImage4, 96);
    lv_obj_set_x(ui_DevicebindingImage4, 0);
    lv_obj_set_y(ui_DevicebindingImage4, 288);
    lv_obj_add_flag(ui_DevicebindingImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_DevicebindingImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_DevicebindingImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingImage5 = lv_img_create(ui_DevicebindingPanel1);
    lv_img_set_src(ui_DevicebindingImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_DevicebindingImage5, 80);
    lv_obj_set_height(ui_DevicebindingImage5, 96);
    lv_obj_set_x(ui_DevicebindingImage5, 0);
    lv_obj_set_y(ui_DevicebindingImage5, 384);
    lv_obj_add_flag(ui_DevicebindingImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_DevicebindingImage5, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_DevicebindingImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingPanel2 = lv_obj_create(ui_Devicebinding);
    lv_obj_set_width(ui_DevicebindingPanel2, 720);
    lv_obj_set_height(ui_DevicebindingPanel2, 480);
    lv_obj_set_x(ui_DevicebindingPanel2, 80);
    lv_obj_set_y(ui_DevicebindingPanel2, 0);
    lv_obj_clear_flag(ui_DevicebindingPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DevicebindingPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DevicebindingPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_DevicebindingPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_DevicebindingPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_DevicebindingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_DevicebindingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_DevicebindingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_DevicebindingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingPanel3 = lv_obj_create(ui_DevicebindingPanel2);
    lv_obj_set_width(ui_DevicebindingPanel3, 696);
    lv_obj_set_height(ui_DevicebindingPanel3, 456);
    lv_obj_set_align(ui_DevicebindingPanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_DevicebindingPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingPanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DevicebindingPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DevicebindingPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_DevicebindingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_DevicebindingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_DevicebindingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_DevicebindingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingTitle = lv_obj_create(ui_DevicebindingPanel3);
    lv_obj_set_width(ui_DevicebindingTitle, 665);
    lv_obj_set_height(ui_DevicebindingTitle, 65);
    lv_obj_set_x(ui_DevicebindingTitle, 10);
    lv_obj_set_y(ui_DevicebindingTitle, 0);
    lv_obj_clear_flag(ui_DevicebindingTitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingTitle, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DevicebindingTitle, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DevicebindingTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_DevicebindingTitle, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_DevicebindingTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingTitle, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_DevicebindingTitle, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_DevicebindingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_DevicebindingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_DevicebindingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_DevicebindingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingLabel1 = lv_label_create(ui_DevicebindingTitle);
    lv_obj_set_width(ui_DevicebindingLabel1, 600);
    lv_obj_set_height(ui_DevicebindingLabel1, 28);
    lv_obj_set_x(ui_DevicebindingLabel1, 15);
    lv_obj_set_y(ui_DevicebindingLabel1, 0);
    lv_obj_set_align(ui_DevicebindingLabel1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_DevicebindingLabel1, BindDevice[language_index]);
    lv_obj_set_style_text_color(ui_DevicebindingLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevicebindingLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingLabel1, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingButton1 = lv_btn_create(ui_DevicebindingPanel3);
    lv_obj_set_width(ui_DevicebindingButton1, 116);
    lv_obj_set_height(ui_DevicebindingButton1, 60);
    lv_obj_set_x(ui_DevicebindingButton1, 560);
    lv_obj_set_y(ui_DevicebindingButton1, 381);
    lv_obj_add_flag(ui_DevicebindingButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_DevicebindingButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DevicebindingButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DevicebindingButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_DevicebindingButton1, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_DevicebindingButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_DevicebindingButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_DevicebindingButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_DevicebindingButton1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevicebindingButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingButton1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingBtnlabel1 = lv_label_create(ui_DevicebindingButton1);
    lv_obj_set_width(ui_DevicebindingBtnlabel1, lv_pct(100));
    lv_obj_set_height(ui_DevicebindingBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_DevicebindingBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_DevicebindingBtnlabel1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_DevicebindingBtnlabel1, Back[language_index]);
    lv_obj_set_style_text_align(ui_DevicebindingBtnlabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingLabel2 = lv_label_create(ui_DevicebindingPanel3);
    lv_obj_set_width(ui_DevicebindingLabel2, 600);
    lv_obj_set_height(ui_DevicebindingLabel2, 60);
    lv_obj_set_x(ui_DevicebindingLabel2, 25);
    lv_obj_set_y(ui_DevicebindingLabel2, 87);
    lv_label_set_long_mode(ui_DevicebindingLabel2, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DevicebindingLabel2, DeviceBindTipsMsg[language_index]);
    lv_obj_set_style_text_color(ui_DevicebindingLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevicebindingLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingLabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingLabel3 = lv_label_create(ui_DevicebindingPanel3);
    lv_label_set_text(ui_DevicebindingLabel3, "区域");
    lv_obj_set_width(ui_DevicebindingLabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DevicebindingLabel3, 28);    /// 1
    lv_obj_align_to(ui_DevicebindingLabel3, ui_DevicebindingLabel2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
    lv_obj_set_style_text_font(ui_DevicebindingLabel3, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_DevicebindingLabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DevicebindingLabel3, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    char buff[150] = {0};
    sprintf(buff, "%s\n%s", "中国大陆","国际");

    ui_DevicebindingDropdown1 = lv_dropdown_create(ui_DevicebindingPanel3);
    lv_dropdown_set_options(ui_DevicebindingDropdown1, buff);
    lv_obj_set_width(ui_DevicebindingDropdown1, 363);
    lv_obj_set_height(ui_DevicebindingDropdown1, 52);
    lv_obj_align_to(ui_DevicebindingDropdown1, ui_DevicebindingLabel3, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_obj_add_flag(ui_DevicebindingDropdown1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_DevicebindingDropdown1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevicebindingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DevicebindingDropdown1, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingDropdown1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_DevicebindingDropdown1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DevicebindingDropdown1, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DevicebindingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_DevicebindingDropdown1, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_DevicebindingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingDropdown1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_DevicebindingDropdown1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevicebindingDropdown1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingDropdown1, lv_font25.font, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_dropdown_set_symbol(ui_DevicebindingDropdown1, &ui_img_expand_down_png);

    ui_DevicebindingImage6 = lv_qrcode_create(ui_DevicebindingPanel3, 160, lv_color_hex(0xFFFFFF), lv_color_hex(0x000000));
    lv_obj_set_width(ui_DevicebindingImage6, 160);
    lv_obj_set_height(ui_DevicebindingImage6, 160);
    lv_obj_align(ui_DevicebindingImage6, LV_ALIGN_TOP_MID, 0, 217);
    lv_obj_add_flag(ui_DevicebindingImage6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_DevicebindingImage6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_DevicebindingLabel4 = lv_label_create(ui_DevicebindingPanel3);
    lv_obj_set_width(ui_DevicebindingLabel4, 600);
    lv_obj_set_height(ui_DevicebindingLabel4, LV_SIZE_CONTENT);
    lv_obj_align(ui_DevicebindingLabel4, LV_ALIGN_TOP_MID, 0, 217);
    lv_label_set_long_mode(ui_DevicebindingLabel4, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DevicebindingLabel4, IOTTips[language_index]);
    lv_obj_set_style_text_color(ui_DevicebindingLabel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevicebindingLabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingLabel4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DevicebindingLabel4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingPanel5 = lv_obj_create(ui_DevicebindingPanel3);
    lv_obj_set_width(ui_DevicebindingPanel5, 696);
    lv_obj_set_height(ui_DevicebindingPanel5, 300);
    lv_obj_align(ui_DevicebindingPanel5, LV_ALIGN_TOP_MID, 0, 80);
    lv_obj_clear_flag(ui_DevicebindingPanel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingPanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DevicebindingPanel5, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DevicebindingPanel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingPanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_DevicebindingPanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingPanel6 = lv_obj_create(ui_DevicebindingPanel5);
    lv_obj_set_width(ui_DevicebindingPanel6, 78);
    lv_obj_set_height(ui_DevicebindingPanel6, 78);
    lv_obj_align(ui_DevicebindingPanel6, LV_ALIGN_TOP_LEFT, 20, 20);
    lv_obj_clear_flag(ui_DevicebindingPanel6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DevicebindingPanel6, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DevicebindingPanel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_DevicebindingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingUserimg = lv_img_create(ui_DevicebindingPanel6);
    lv_obj_set_width(ui_DevicebindingUserimg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_DevicebindingUserimg, LV_SIZE_CONTENT);
    lv_obj_align(ui_DevicebindingUserimg, LV_ALIGN_CENTER, 0 ,0);
    lv_obj_add_flag(ui_DevicebindingUserimg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_DevicebindingUserimg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_DevicebindingUsername = lv_label_create(ui_DevicebindingPanel5);
    lv_obj_set_width(ui_DevicebindingUsername, 600);
    lv_obj_set_height(ui_DevicebindingUsername, 30);
    lv_obj_align_to(ui_DevicebindingUsername, ui_DevicebindingPanel6, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
    lv_label_set_long_mode(ui_DevicebindingUsername, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DevicebindingUsername, UserName[language_index]);
    lv_obj_set_style_text_color(ui_DevicebindingUsername, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevicebindingUsername, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingUsername, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingUserid = lv_label_create(ui_DevicebindingPanel5);
    lv_obj_set_width(ui_DevicebindingUserid, 600);
    lv_obj_set_height(ui_DevicebindingUserid, 30);
    lv_obj_align_to(ui_DevicebindingUserid, ui_DevicebindingUsername, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
    lv_label_set_long_mode(ui_DevicebindingUserid, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DevicebindingUserid, "ID:");
    lv_obj_set_style_text_color(ui_DevicebindingUserid, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevicebindingUserid, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingUserid, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingUserBtn = lv_btn_create(ui_DevicebindingPanel5);
    lv_obj_set_width(ui_DevicebindingUserBtn, 106);
    lv_obj_set_height(ui_DevicebindingUserBtn, 50);
    lv_obj_align(ui_DevicebindingUserBtn, LV_ALIGN_TOP_RIGHT, -25, 31);
    lv_obj_add_flag(ui_DevicebindingUserBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_DevicebindingUserBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingUserBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DevicebindingUserBtn, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DevicebindingUserBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_DevicebindingUserBtn, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_DevicebindingUserBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_DevicebindingUserBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_DevicebindingUserBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_DevicebindingUserBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingUserBtn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_DevicebindingUserBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevicebindingUserBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingUserBtn, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DevicebindingUserBtnlabel = lv_label_create(ui_DevicebindingUserBtn);
    lv_obj_set_width(ui_DevicebindingUserBtnlabel, lv_pct(100));
    lv_obj_set_height(ui_DevicebindingUserBtnlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_DevicebindingUserBtnlabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_DevicebindingUserBtnlabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_DevicebindingUserBtnlabel, LogOut[language_index]);
    lv_obj_set_style_text_align(ui_DevicebindingUserBtnlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingUserBtnlabel, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_DevicebindingUserBtnlabel, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_DevicebindingButton1, ui_event_DevicebindingButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DevicebindingUserBtn, ui_event_DevicebindingUserBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DevicebindingImage1, ui_event_DevicebindingImage1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DevicebindingImage2, ui_event_DevicebindingImage2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DevicebindingImage3, ui_event_DevicebindingImage3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DevicebindingImage4, ui_event_DevicebindingImage4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DevicebindingImage5, ui_event_DevicebindingImage5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DevicebindingDropdown1, ui_event_DevicebindingDropdown, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Devicebinding, ui_event_Devicebinding, LV_EVENT_ALL, NULL);
}

void ui_event_DevicebindingImage1(lv_event_t * e)
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
void ui_event_DevicebindingImage2(lv_event_t * e)
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
void ui_event_DevicebindingImage3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadFileManageScreen();
    }
}
void ui_event_DevicebindingImage4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_DevicebindingImage5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadCustomerServiceScreen();
    }
}
void ui_event_DevicebindingDropdown(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        int option = lv_dropdown_get_selected(target);
        CrLogI("Change the Serveroptions:%d", option);
        char tempbuff[10] = {0};
        snprintf(tempbuff, 10, "p%d", option+1);
        set_printer_data(0x06, 3, tempbuff);
    }
    else if(event_code == LV_EVENT_READY)
    {
        lv_obj_t *list_method = lv_dropdown_get_list(target);
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

void ui_event_DevicebindingButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void log_out()
{
    send_buzzer(0x01);
    CrLogI("log out cxyclound");
    set_printer_data(CONTROL_MACHINE_STATE, 3, "61");//解绑用户
    selftest_messagebox_close();
    _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

void not_log_out()
{
    send_buzzer(0x01);
    selftest_messagebox_close();
}

void ui_event_DevicebindingUserBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        CrLogI("user sure log out");
        void (*btns_callback[2])(void) = {&not_log_out, &log_out};
        create_selftest_messagebox(KindTips[get_cur_language_index()], LogOutTips[get_cur_language_index()],Cancel[get_cur_language_index()], ErrorBtnConfirm[get_cur_language_index()], btns_callback);
    }
}

void ui_event_DevicebingdingPrivacypolicyHandle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(target == userdata)//btn1
        {
            _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        }
        else//btn2
        {
            //创建状态刷新定时器
            if(refreshTimer != NULL)
                refreshTimer = NULL;
            refreshTimer = createTimerForRefreshState();

            lv_obj_add_flag(ui_DevicebindingPanel5, LV_OBJ_FLAG_HIDDEN);      /// Flags
            get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态
        }
    }
}

void ui_event_Devicebinding(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load the devicebingding page");
        if(!init_uiconfiginfo.AgreePrivacyPolicy)
        {
            int index = get_cur_language_index();
            create_PrivacyMessagebox(PrivacyPolicyTips[index], NotAgree[index], Agree[index], ui_event_DevicebingdingPrivacypolicyHandle, ui_event_DevicebingdingPrivacypolicyHandle);
            lv_obj_add_flag(ui_DevicebindingPanel5, LV_OBJ_FLAG_HIDDEN);      /// Flags
            lv_obj_add_flag(ui_DevicebindingImage6, LV_OBJ_FLAG_HIDDEN);
            return;
        }
        else
        {
            //创建状态刷新定时器
            if(refreshTimer != NULL)
                refreshTimer = NULL;
            refreshTimer = createTimerForRefreshState();
            lv_obj_add_flag(ui_DevicebindingImage6, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_DevicebindingPanel5, LV_OBJ_FLAG_HIDDEN);      /// Flags
            get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态
            get_printer_data(CONTROL_PARAMETERS, 2, "p");//查询创想云服务器状态
        }
    }
    else if(event_code == LV_EVENT_SCREEN_UNLOADED)
    {
        if(refreshTimer != NULL)
            deleteTimerForRefreshState(refreshTimer);
    }
}

void refresh_devicebingding_page(char *src)
{
    if(src != NULL)
    {
        char buff[258] = {0};
        buff[0] = PNG_DRV_LETTER;
        strncpy(buff + 1, src, sizeof(buff) - 2);
        lv_img_set_src(ui_DevicebindingImage6, buff);
    }
}

void device_bind_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_DevicebindingLabel1 )
        lv_label_set_text(ui_DevicebindingLabel1, BindDevice[language_index]);
    if ( ui_DevicebindingBtnlabel1 )
        lv_label_set_text(ui_DevicebindingBtnlabel1, Back[language_index]);
    if ( ui_DevicebindingLabel2 )
        lv_label_set_text(ui_DevicebindingLabel2, DeviceBindTipsMsg[language_index]);
    if ( ui_DevicebindingUserBtnlabel )
        lv_label_set_text(ui_DevicebindingUserBtnlabel, LogOut[language_index]);
    if ( ui_DevicebindingLabel3 )
    {
        lv_label_set_text(ui_DevicebindingLabel3, Area[language_index]);
        lv_obj_align_to(ui_DevicebindingDropdown1, ui_DevicebindingLabel3, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    }
    if ( ui_DevicebindingDropdown1 )
    {
        char buff[256] = {0};
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s\n%s", AreaChinese[language_index], AreaOthers[language_index]);

        uint8_t id = lv_dropdown_get_selected(ui_DevicebindingDropdown1);
        lv_dropdown_clear_options(ui_DevicebindingDropdown1);
        lv_dropdown_set_options(ui_DevicebindingDropdown1, buff);
        lv_dropdown_set_selected(ui_DevicebindingDropdown1, id);
    }
    if ( ui_DevicebindingLabel4 )
        lv_label_set_text(ui_DevicebindingLabel4, IOTTips[language_index]);
}

void img_zoom_function(struct _lv_timer_t *timer)
{
    int width = lv_obj_get_width(ui_DevicebindingUserimg);
    int height = lv_obj_get_height(ui_DevicebindingUserimg);
    int scale = 256 * 78 / width;
    CrLogI("UserImg width: %d,height:%d, scale:%d", width, height, scale);
    lv_img_set_zoom(ui_DevicebindingUserimg, scale);
}

void refresh_DeviceUserInfo(bool result, CloudUserInfo_t user)
{
    CrLogI("Load cloud user information,reslut: %d", result);
    if(!result)return;
    lv_obj_clear_flag(ui_DevicebindingPanel5, LV_OBJ_FLAG_HIDDEN);      /// Flags
    if(ui_DevicebindingUsername != NULL)
    {
        char namebuff[100] = {0};
        snprintf(namebuff, 100, "%s:%s", UserName[get_cur_language_index()], user.UserName);
        lv_label_set_text(ui_DevicebindingUsername, namebuff);
    }

    if(ui_DevicebindingUserid != NULL)
    {
        char namebuff[100] = {0};
        snprintf(namebuff, 100, "ID:%s", user.UserID);
        lv_label_set_text(ui_DevicebindingUserid, namebuff);
    }

    if(ui_DevicebindingUserimg != NULL)
    {
        char buff[258] = {0};
        snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, user.UserImg);
        CrLogI("UserImg file path: %s", buff);
        lv_obj_clear_flag(ui_DevicebindingUserimg, LV_OBJ_FLAG_HIDDEN);      /// Flags
        lv_img_set_src(ui_DevicebindingUserimg, buff);
        lv_obj_update_layout(ui_DevicebindingUserimg);
        int width = lv_obj_get_width(ui_DevicebindingUserimg);
        int height = lv_obj_get_height(ui_DevicebindingUserimg);
        if(width > 0 && height > 0)
        {
            int scale = 256 * 78 / width;
            CrLogI("UserImg width: %d,height:%d, scale:%d", width, height, scale);
            lv_img_set_zoom(ui_DevicebindingUserimg, scale);

        }
        else
        {
            CrLogI("UserImg width: %d,height:%d", width, height);
            lv_obj_add_flag(ui_DevicebindingUserimg, LV_OBJ_FLAG_HIDDEN);      /// Flags
        }
    }
}

void ChangeServerOption(int ServerOption)
{
    CrLogI("Change Server Option:%d", ServerOption);
    if(ui_DevicebindingDropdown1)
        lv_dropdown_set_selected(ui_DevicebindingDropdown1, ServerOption - 1);
}

void refresHandle(lv_timer_t *timer)
{
    CrLogI("refresh the Mqttstate");
    if (system_state.Mqtt_state) {
        CrLogI("device binding qrcode exist");
        char temp[64] = {0};
        snprintf(temp, 64, "%s %s", GetSystemConfig().device_sn, GetSystemConfig().device_mac);
        lv_qrcode_update(ui_DevicebindingImage6, temp, strlen(temp));

        lv_obj_clear_flag(ui_DevicebindingLabel2, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_DevicebindingImage6, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_style_text_opa(ui_DevicebindingLabel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else
    {
        CrLogI("device binding qrcode not exist");
        lv_obj_add_flag(ui_DevicebindingLabel2, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_DevicebindingImage6, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_style_text_opa(ui_DevicebindingLabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

//创建定时器，用于定时刷新服务器状态
lv_timer_t * createTimerForRefreshState()
{
    lv_timer_t * timer = lv_timer_create(refresHandle, 1000 * 1, NULL);
    lv_timer_set_repeat_count(timer, -1);
    return timer;
}

//删除定时器
void deleteTimerForRefreshState(lv_timer_t * timer)
{
    CrLogI("delete the refreshstate timer");
    if(timer == NULL)return;
    lv_timer_del(timer);
    timer == NULL;
    CrLogI("delete the refreshtate timer success");
}