/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-11-29 19:21:26
 * @LastEditTime: 2023-09-26 23:14:40
 */

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "mult_language.h"
#include <stdio.h>
#include <string.h>
#include "mult_language.h"

lv_obj_t * ui_UpdateVersion;
lv_obj_t * ui_UpdateVersionPanel1;
lv_obj_t * ui_UpdateVersionBtn1;
lv_obj_t * ui_UpdateVersionBtnlabel1;
lv_obj_t * ui_UpdateVersionBtn2;
lv_obj_t * ui_UpdateVersionBtnlabel2;
lv_obj_t * ui_UpdateVersionTitle;
lv_obj_t * ui_OldVersion;
lv_obj_t * ui_NewVersion;
lv_obj_t * ui_VersionSize;
lv_obj_t * ui_UpdateContent;
lv_obj_t * ui_VersionSize1;
lv_obj_t * ui_UpdateVersionBar1;
lv_obj_t * ui_UpdateVersionPanel2;
lv_obj_t * ui_UpdateVersionLabel1;
lv_obj_t * ui_UpdateVersionLabel2;
lv_obj_t * ui_UpdateVersionBtn3;
lv_obj_t * ui_UpdateVersionBtnlabel3;
lv_obj_t * ui_UpdateVersionBtn4;
lv_obj_t * ui_UpdateVersionBtnlabel4;

void ui_event_UpdateVersionBtn1(lv_event_t * e);
void ui_event_UpdateVersionBtn2(lv_event_t * e);
void ui_event_UpdateVersionBtn3(lv_event_t * e);
void ui_event_UpdateVersionBtn4(lv_event_t * e);
void ui_event_UpdateVersion(lv_event_t * e);

static void UpdateversionPageChangeObjs(void);

void ui_UpdateVersion_screen_init(void)
{
    ui_UpdateVersion = lv_obj_create(ui_ScreenSettings);
    lv_obj_clear_flag(ui_UpdateVersion, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_width(ui_UpdateVersion, 640);
    lv_obj_set_height(ui_UpdateVersion, 360);
    lv_obj_set_x(ui_UpdateVersion, 0);
    lv_obj_set_y(ui_UpdateVersion, 60);
    lv_obj_set_style_bg_color(ui_UpdateVersion, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UpdateVersion, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_UpdateVersion, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_UpdateVersion, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_flag(ui_UpdateVersion, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_pad_all(ui_UpdateVersion, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    uint8_t language_index = get_cur_language_index();
    ui_UpdateVersionPanel1 = lv_obj_create(ui_UpdateVersion);
    lv_obj_set_width(ui_UpdateVersionPanel1, 418); //
    lv_obj_set_height(ui_UpdateVersionPanel1, 320);//442
    lv_obj_set_x(ui_UpdateVersionPanel1, 0);
    lv_obj_set_y(ui_UpdateVersionPanel1, 16);
    lv_obj_set_align(ui_UpdateVersionPanel1, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_UpdateVersionPanel1, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_UpdateVersionPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_UpdateVersionPanel1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_UpdateVersionPanel1, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UpdateVersionPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_UpdateVersionPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_UpdateVersionPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_UpdateVersionPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_UpdateVersionPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_UpdateVersionPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UpdateVersionBtn1 = lv_btn_create(ui_UpdateVersionPanel1);
    lv_obj_set_width(ui_UpdateVersionBtn1, 146);
    lv_obj_set_height(ui_UpdateVersionBtn1, 60);
    lv_obj_set_x(ui_UpdateVersionBtn1, 244);
    lv_obj_set_y(ui_UpdateVersionBtn1, 240);
    lv_obj_add_flag(ui_UpdateVersionBtn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_UpdateVersionBtn1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_UpdateVersionBtn1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_UpdateVersionBtn1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UpdateVersionBtn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_UpdateVersionBtn1, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_UpdateVersionBtn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_UpdateVersionBtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_UpdateVersionBtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_UpdateVersionBtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_UpdateVersionBtn1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_UpdateVersionBtn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UpdateVersionBtn1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_UpdateVersionBtn1, lv_color_hex(0xB0F1FF),LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_UpdateVersionBtn1, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_UpdateVersionBtn1, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_UpdateVersionBtn1, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_UpdateVersionBtn1, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    ui_UpdateVersionBtnlabel1 = lv_label_create(ui_UpdateVersionBtn1);
    lv_obj_set_width(ui_UpdateVersionBtnlabel1, lv_pct(100));
    lv_obj_set_height(ui_UpdateVersionBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_UpdateVersionBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_UpdateVersionBtnlabel1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_UpdateVersionBtnlabel1, UpgradeArray[language_index]);
    lv_obj_set_style_text_align(ui_UpdateVersionBtnlabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UpdateVersionBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UpdateVersionBtn2 = lv_btn_create(ui_UpdateVersionPanel1);
    lv_obj_set_width(ui_UpdateVersionBtn2, 146);
    lv_obj_set_height(ui_UpdateVersionBtn2, 60);
    lv_obj_set_x(ui_UpdateVersionBtn2, 28);
    lv_obj_set_y(ui_UpdateVersionBtn2, 240);
    lv_obj_add_flag(ui_UpdateVersionBtn2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_UpdateVersionBtn2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_UpdateVersionBtn2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_UpdateVersionBtn2, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UpdateVersionBtn2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_UpdateVersionBtn2, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_UpdateVersionBtn2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_UpdateVersionBtn2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_UpdateVersionBtn2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_UpdateVersionBtn2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_UpdateVersionBtn2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UpdateVersionBtn2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_UpdateVersionBtn2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_UpdateVersionBtn2, lv_color_hex(0xB0F1FF),LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_UpdateVersionBtn2, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_UpdateVersionBtn2, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_UpdateVersionBtn2, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_UpdateVersionBtn2, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    ui_UpdateVersionBtnlabel2 = lv_label_create(ui_UpdateVersionBtn2);
    lv_obj_set_width(ui_UpdateVersionBtnlabel2, lv_pct(100));
    lv_obj_set_height(ui_UpdateVersionBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_UpdateVersionBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_UpdateVersionBtnlabel2, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_UpdateVersionBtnlabel2, Cancel[language_index]);
    lv_obj_set_style_text_align(ui_UpdateVersionBtnlabel2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UpdateVersionBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UpdateVersionTitle = lv_label_create(ui_UpdateVersionPanel1);
    lv_obj_set_width(ui_UpdateVersionTitle, 400);
    lv_obj_set_height(ui_UpdateVersionTitle, 24);
    lv_obj_set_x(ui_UpdateVersionTitle, 0);
    lv_obj_set_y(ui_UpdateVersionTitle, 23);
    lv_obj_set_align(ui_UpdateVersionTitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_UpdateVersionTitle, DiscoverNewVersionArray[language_index]);
    lv_obj_set_style_text_color(ui_UpdateVersionTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_UpdateVersionTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_UpdateVersionTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UpdateVersionTitle, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_OldVersion = lv_label_create(ui_UpdateVersionPanel1);
    lv_obj_set_width(ui_OldVersion, 360);
    lv_obj_set_height(ui_OldVersion, 24);
    lv_obj_set_x(ui_OldVersion, 35);
    lv_obj_set_y(ui_OldVersion, 74);
    char buff[50] = {0};
    sprintf(buff, "%s:", CurVersionArray[language_index]);
    lv_label_set_text(ui_OldVersion, buff);
    lv_obj_set_style_text_color(ui_OldVersion, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_OldVersion, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_OldVersion, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_OldVersion, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NewVersion = lv_label_create(ui_UpdateVersionPanel1);
    lv_obj_set_width(ui_NewVersion, 250);
    lv_obj_set_height(ui_NewVersion, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_NewVersion, 35);
    lv_obj_set_y(ui_NewVersion, 111);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", NewVersionArray[language_index]);
    lv_label_set_text(ui_NewVersion, buff);
    lv_obj_set_style_text_color(ui_NewVersion, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NewVersion, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_NewVersion, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NewVersion, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VersionSize = lv_label_create(ui_UpdateVersionPanel1);
    lv_obj_set_width(ui_VersionSize, 200);
    lv_obj_set_height(ui_VersionSize, 24);
    lv_obj_set_x(ui_VersionSize, -16);
    lv_obj_set_y(ui_VersionSize, 111);
    lv_obj_set_align(ui_VersionSize, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_VersionSize, "15MB");
    lv_obj_set_style_text_color(ui_VersionSize, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VersionSize, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VersionSize, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VersionSize, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UpdateContent = lv_label_create(ui_UpdateVersionPanel1);
    lv_obj_set_width(ui_UpdateContent, 364);
    lv_obj_set_height(ui_UpdateContent, 120);
    lv_obj_set_x(ui_UpdateContent, 27);
    lv_obj_set_y(ui_UpdateContent, 163);
    lv_label_set_long_mode(ui_UpdateContent, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_UpdateContent, "");
    lv_obj_set_style_text_color(ui_UpdateContent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_UpdateContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_UpdateContent, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UpdateContent, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VersionSize1 = lv_label_create(ui_UpdateVersionPanel1);
    lv_obj_set_width(ui_VersionSize1, 200);
    lv_obj_set_height(ui_VersionSize1, 24);
    // lv_obj_set_x(ui_VersionSize1, 117);
    // lv_obj_set_y(ui_VersionSize1, 290);
    lv_obj_align(ui_VersionSize1, LV_ALIGN_BOTTOM_MID, 0, -40);
    lv_label_set_text(ui_VersionSize1, "");
    lv_obj_set_style_text_color(ui_VersionSize1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VersionSize1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VersionSize1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VersionSize1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UpdateVersionBar1 = lv_bar_create(ui_UpdateVersionPanel1);
    lv_bar_set_value(ui_UpdateVersionBar1, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_UpdateVersionBar1, 350);
    lv_obj_set_height(ui_UpdateVersionBar1, 14);
    // lv_obj_set_x(ui_UpdateVersionBar1, 0);
    // lv_obj_set_y(ui_UpdateVersionBar1, 328);
    lv_obj_align(ui_UpdateVersionBar1, LV_ALIGN_BOTTOM_MID, 0, -20);
   // lv_obj_set_align(ui_UpdateVersionBar1, LV_ALIGN_TOP_MID);
    lv_obj_set_style_radius(ui_UpdateVersionBar1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_UpdateVersionBar1, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UpdateVersionBar1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_UpdateVersionBar1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_UpdateVersionBar1, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UpdateVersionBar1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_UpdateVersionPanel2 = lv_obj_create(ui_UpdateVersion);
    lv_obj_set_width(ui_UpdateVersionPanel2, 418);
    lv_obj_set_height(ui_UpdateVersionPanel2, 300);
    lv_obj_set_align(ui_UpdateVersionPanel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_UpdateVersionPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_UpdateVersionPanel2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_UpdateVersionPanel2, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UpdateVersionPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_UpdateVersionPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_UpdateVersionPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_UpdateVersionPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_UpdateVersionPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_UpdateVersionPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UpdateVersionLabel1 = lv_label_create(ui_UpdateVersionPanel2);
    lv_obj_set_width(ui_UpdateVersionLabel1, 400);
    lv_obj_set_height(ui_UpdateVersionLabel1, 24);
    lv_obj_set_x(ui_UpdateVersionLabel1, 0);
    lv_obj_set_y(ui_UpdateVersionLabel1, 20);
    lv_obj_set_align(ui_UpdateVersionLabel1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_UpdateVersionLabel1, KindTips[language_index]);
    lv_obj_set_style_text_color(ui_UpdateVersionLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_UpdateVersionLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_UpdateVersionLabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UpdateVersionLabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UpdateVersionLabel2 = lv_label_create(ui_UpdateVersionPanel2);
    lv_obj_set_width(ui_UpdateVersionLabel2, 400);
    lv_obj_set_height(ui_UpdateVersionLabel2, 24);
    lv_obj_set_x(ui_UpdateVersionLabel2, 0);
    lv_obj_set_y(ui_UpdateVersionLabel2, 91);
    lv_obj_set_align(ui_UpdateVersionLabel2, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_UpdateVersionLabel2, CurVersionIsLastest[language_index]);
    lv_obj_set_style_text_color(ui_UpdateVersionLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_UpdateVersionLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_UpdateVersionLabel2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UpdateVersionLabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UpdateVersionBtn3 = lv_btn_create(ui_UpdateVersionPanel2);
    lv_obj_set_width(ui_UpdateVersionBtn3, 146);
    lv_obj_set_height(ui_UpdateVersionBtn3, 60);
    lv_obj_set_x(ui_UpdateVersionBtn3, 244);
    lv_obj_set_y(ui_UpdateVersionBtn3, 220);
    lv_obj_add_flag(ui_UpdateVersionBtn3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_UpdateVersionBtn3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_UpdateVersionBtn3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_UpdateVersionBtn3, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UpdateVersionBtn3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_UpdateVersionBtn3, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_UpdateVersionBtn3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_UpdateVersionBtn3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_UpdateVersionBtn3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_UpdateVersionBtn3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_UpdateVersionBtn3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_UpdateVersionBtn3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_UpdateVersionBtn3, lv_color_hex(0xB0F1FF),LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_UpdateVersionBtn3, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_UpdateVersionBtn3, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_UpdateVersionBtn3, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_UpdateVersionBtn3, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    ui_UpdateVersionBtnlabel3 = lv_label_create(ui_UpdateVersionBtn3);
    lv_obj_set_width(ui_UpdateVersionBtnlabel3, lv_pct(100));
    lv_obj_set_height(ui_UpdateVersionBtnlabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_UpdateVersionBtnlabel3, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_UpdateVersionBtnlabel3, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_UpdateVersionBtnlabel3, Confirm[language_index]);
    lv_obj_set_style_text_align(ui_UpdateVersionBtnlabel3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UpdateVersionBtnlabel3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UpdateVersionBtn4 = lv_btn_create(ui_UpdateVersionPanel2);
    lv_obj_set_width(ui_UpdateVersionBtn4, 146);
    lv_obj_set_height(ui_UpdateVersionBtn4, 60);
    lv_obj_set_x(ui_UpdateVersionBtn4, 28);
    lv_obj_set_y(ui_UpdateVersionBtn4, 220);
    lv_obj_add_flag(ui_UpdateVersionBtn4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_UpdateVersionBtn4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_UpdateVersionBtn4, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_UpdateVersionBtn4, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UpdateVersionBtn4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_UpdateVersionBtn4, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_UpdateVersionBtn4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_UpdateVersionBtn4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_UpdateVersionBtn4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_UpdateVersionBtn4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_UpdateVersionBtn4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UpdateVersionBtn4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_UpdateVersionBtn4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_UpdateVersionBtn4, lv_color_hex(0xB0F1FF),LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_UpdateVersionBtn4, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_UpdateVersionBtn4, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_UpdateVersionBtn4, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_UpdateVersionBtn4, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    ui_UpdateVersionBtnlabel4 = lv_label_create(ui_UpdateVersionBtn4);
    lv_obj_set_width(ui_UpdateVersionBtnlabel4, lv_pct(100));
    lv_obj_set_height(ui_UpdateVersionBtnlabel4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_UpdateVersionBtnlabel4, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_UpdateVersionBtnlabel4, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_UpdateVersionBtnlabel4, Cancel[language_index]);
    lv_obj_set_style_text_align(ui_UpdateVersionBtnlabel4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UpdateVersionBtnlabel4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_UpdateVersionBtn1, ui_event_UpdateVersionBtn1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_UpdateVersionBtn2, ui_event_UpdateVersionBtn2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_UpdateVersionBtn3, ui_event_UpdateVersionBtn3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_UpdateVersionBtn4, ui_event_UpdateVersionBtn4, LV_EVENT_ALL, NULL);
}
//升级按钮
void ui_event_UpdateVersionBtn1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if(print_state != 1)
        {
            CrLogI("can't UpdateVersion, because the print_state:%d ",print_state);
            create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
            return;
        }
        const char * text = lv_label_get_text(ui_UpdateVersionBtnlabel1);
        if(strcmp(text, UpgradeArray[get_cur_language_index()]) == 0)
        {
            set_printer_data(0x1a,1,"2");
            lv_obj_clear_flag(ui_VersionSize1,LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_UpdateVersionBtn1,LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_bg_color(ui_UpdateVersionBtn1, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(ui_UpdateVersionBtn2,LV_OBJ_FLAG_HIDDEN);
        }
        if(strcmp(text, Download[get_cur_language_index()]) == 0)
        {
            set_printer_data(0x1a,1,"1");
            lv_obj_clear_flag(ui_VersionSize1,LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_UpdateVersionBar1,LV_OBJ_FLAG_HIDDEN);

            lv_obj_add_flag(ui_UpdateVersionBtn1,LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_bg_color(ui_UpdateVersionBtn1, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(ui_UpdateVersionBtn2,LV_OBJ_FLAG_HIDDEN);
        }
    }
}
//取消升级
void ui_event_UpdateVersionBtn2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        lv_obj_add_flag(ui_UpdateVersion, LV_OBJ_FLAG_HIDDEN);     /// Flags
        
        DeinitPopoutManager(&BtnDialogPopout);
        if (IsThereAnyPopout())
        {
            ManagePopoutFocus();
        }
        else
        {
             BackPrepage(true);
        }
    }
}
void ui_event_UpdateVersionBtn3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        lv_obj_add_flag(ui_UpdateVersion, LV_OBJ_FLAG_HIDDEN);     /// Flags

        DeinitPopoutManager(&BtnDialogPopout);
        if (IsThereAnyPopout())
        {
            ManagePopoutFocus();
        }
        else
        {
             BackPrepage(true);
        }
    }
}
void ui_event_UpdateVersionBtn4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        lv_obj_add_flag(ui_UpdateVersion, LV_OBJ_FLAG_HIDDEN);     /// Flags
       
        DeinitPopoutManager(&BtnDialogPopout);
        if (IsThereAnyPopout())
        {
            ManagePopoutFocus();
        }
        else
        {
             BackPrepage(true);
        }
    }
}

void EnterUpdatepage(int mode) //进版本升级弹窗
{
    CrLogI("enter the updatepage,mode :%d",mode);
    switch (mode)
    {
        case 0: break;
        case 1: get_printer_data(0x1a,1,"1");break;
        case 2: get_printer_data(0x1a,1,"2");break;
        case 3: get_printer_data(0x1a,1,"3");break;
        case 4: get_printer_data(0x1a,1,"4");break;
        default:
            break;
    }
}

void RefreshUpdateVersionProgress(char version_flag, char * upgrade_progress)
{
    switch (version_flag)
    {
        case '0':lv_label_set_text(ui_VersionSize1, DownloadSuccess[get_cur_language_index()]);lv_obj_add_flag(ui_UpdateVersionBar1,LV_OBJ_FLAG_HIDDEN);break;
        case '1':lv_label_set_text(ui_VersionSize1, Downloading[get_cur_language_index()]);break;
        case '2':lv_label_set_text(ui_VersionSize1, DownloadFailed[get_cur_language_index()]);
                 lv_obj_clear_flag(ui_UpdateVersionBtn1,LV_OBJ_FLAG_HIDDEN);
                 lv_obj_set_style_bg_color(ui_UpdateVersionBtn1, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
                 lv_obj_clear_flag(ui_UpdateVersionBtn2,LV_OBJ_FLAG_HIDDEN);
            break;
        case '3':lv_label_set_text(ui_VersionSize1, UnpackSuccess[get_cur_language_index()]);break;
        case '4':lv_label_set_text(ui_VersionSize1, Unpacking[get_cur_language_index()]);break;
        case '5':lv_label_set_text(ui_VersionSize1, UnpackFailed[get_cur_language_index()]);
                 lv_obj_clear_flag(ui_UpdateVersionBtn1,LV_OBJ_FLAG_HIDDEN);
                 lv_obj_set_style_bg_color(ui_UpdateVersionBtn1, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
                 lv_obj_clear_flag(ui_UpdateVersionBtn2,LV_OBJ_FLAG_HIDDEN);
            break;
        case '6':lv_label_set_text(ui_VersionSize1, InstallSuccess[get_cur_language_index()]);break;
        case '7':lv_label_set_text(ui_VersionSize1, Installing[get_cur_language_index()]);break;
        case '8':lv_label_set_text(ui_VersionSize1, InstallFailed[get_cur_language_index()]);
                 lv_obj_clear_flag(ui_UpdateVersionBtn1,LV_OBJ_FLAG_HIDDEN);
                 lv_obj_set_style_bg_color(ui_UpdateVersionBtn1, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
                 lv_obj_clear_flag(ui_UpdateVersionBtn2,LV_OBJ_FLAG_HIDDEN);
            break;
        default:
            break;
    }
    CrLogI("download flag:%c,upgrade_progress:%s.", version_flag, upgrade_progress);
    lv_bar_set_value(ui_UpdateVersionBar1, atoi(upgrade_progress), LV_ANIM_OFF);
}

void refresh_updatepage(int flag, char * current_version, char * new_version, char * version_size, char * content, int result)
{
    if (!IsThereAnyPopout())
    {
        RecordObjBeforePopup();
    }

    //lv_obj_set_parent(ui_UpdateVersion, lv_layer_top());
    lv_obj_set_parent(ui_UpdateVersion, lv_scr_act());
    lv_obj_add_flag(ui_UpdateVersion, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_add_flag(ui_VersionSize1,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_UpdateVersionBar1,LV_OBJ_FLAG_HIDDEN);
    wait_animmotion(false);//默认取消一次等待弹窗
    if(result)
    {
        CrLogI("has new version!");
        char ctemp[100];
        if(content[0] != '\0')
        {
            lv_label_set_text(ui_UpdateContent, content);
        }
        if(current_version[0] != '\0')
        {
            sprintf(ctemp, "%s:%s", CurVersionArray[get_cur_language_index()], current_version);
            lv_label_set_text(ui_OldVersion,ctemp);
        }
        if(new_version[0] != '\0')
        {

            sprintf(ctemp, "%s:%s", LastVersionArray[get_cur_language_index()], new_version);
            lv_label_set_text(ui_NewVersion,ctemp);
        }
        if(version_size[0] != '\0')
        {
            float temp = atoi(version_size);
            temp = temp / 1024.0 / 1024.0;
            if(temp < 0.1)  //小于0.1MB认为无大小数据字段隐藏
            {
                lv_obj_add_flag(ui_VersionSize,LV_OBJ_FLAG_HIDDEN);
            }
            else
            {
                lv_obj_clear_flag(ui_VersionSize,LV_OBJ_FLAG_HIDDEN);
            }
            char tempchar[100] = {0};
            snprintf(tempchar,100,"%.2fMB",temp);
            lv_label_set_text(ui_VersionSize,tempchar);
        }
        switch(flag)
        {
            case 0: break;
            case 1: lv_label_set_text(ui_UpdateVersionBtnlabel1,Download[get_cur_language_index()]);break;
            case 2: lv_label_set_text(ui_UpdateVersionBtnlabel1,UpgradeArray[get_cur_language_index()]);break;
            case 3: break;
            case 4: break;
            default:break;
        }

        lv_obj_clear_flag(ui_UpdateVersion,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_UpdateVersionPanel1,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_UpdateVersionPanel2,LV_OBJ_FLAG_HIDDEN);

        InitPopoutManager(&BtnDialogPopout, ui_UpdateVersion, UpdateversionPageChangeObjs);
        BtnDialogPopout.obj1_flag = true;
        BtnDialogPopout.obj2_flag = true;
        BtnDialogPopout.popout_focus_obj1 = ui_UpdateVersionBtn1;
        BtnDialogPopout.popout_focus_obj2 = ui_UpdateVersionBtn2;

    }
    else
    {
        CrLogI("not new version!");
        lv_obj_clear_flag(ui_UpdateVersion,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_UpdateVersionPanel1,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_UpdateVersionPanel2,LV_OBJ_FLAG_HIDDEN);

        InitPopoutManager(&BtnDialogPopout, ui_UpdateVersion, UpdateversionPageChangeObjs);
        BtnDialogPopout.obj1_flag = true;
        BtnDialogPopout.obj2_flag = true;
        BtnDialogPopout.popout_focus_obj1 = ui_UpdateVersionBtn3;
        BtnDialogPopout.popout_focus_obj2 = ui_UpdateVersionBtn4;
    }

    //弹框聚焦对象处理
    ManagePopoutFocus();
}

void update_version_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_UpdateVersionBtnlabel1 )
        lv_label_set_text(ui_UpdateVersionBtnlabel1, UpgradeArray[language_index]);

    if ( ui_UpdateVersionBtnlabel2 )
        lv_label_set_text(ui_UpdateVersionBtnlabel2, Cancel[language_index]);

    if ( ui_UpdateVersionTitle )
        lv_label_set_text(ui_UpdateVersionTitle, DiscoverNewVersionArray[language_index]);

    if ( ui_OldVersion )
    {
        char *text = lv_label_get_text(ui_OldVersion);
        char *ch = NULL;
        if ( text )
            ch = strchr(text, ':');
        char buff[50] = {0};
        strcpy(buff, CurVersionArray[language_index]);
        if ( ch )
            strcat(buff, ch);

        lv_label_set_text(ui_OldVersion, buff);
    }
        

    if ( ui_NewVersion )
    {
        char *text1 = lv_label_get_text(ui_NewVersion);
        char *ch1 = NULL;
        if ( text1 )
            ch1 = strchr(text1, ':');

        char buff[50] = {0};
        if ( ch1 )
        {
            if ( strlen((ch1 + 1)) > 0 )
            {
                strcpy(buff, LastVersionArray[language_index]);
                strcat(buff, ch1);
            }
            else
            {
                strcpy(buff, NewVersionArray[language_index]);
                strcat(buff, ":");
            }
        }
        else
        {
            strcpy(buff, NewVersionArray[language_index]);
            strcat(buff, ":");
        }

        lv_label_set_text(ui_NewVersion, buff);
    }

    if ( ui_UpdateVersionLabel1 )
        lv_label_set_text(ui_UpdateVersionLabel1, KindTips[language_index]);

    if ( ui_UpdateVersionLabel2 )
        lv_label_set_text(ui_UpdateVersionLabel2, CurVersionIsLastest[language_index]);

    if ( ui_UpdateVersionBtnlabel3 )
        lv_label_set_text(ui_UpdateVersionBtnlabel3, Confirm[language_index]);

    if ( ui_UpdateVersionBtnlabel4 )
        lv_label_set_text(ui_UpdateVersionBtnlabel4, Cancel[language_index]);
    
}

/**
 * @description: 
 * @return {*}
 */
static void UpdateversionPageChangeObjs()
{
    lv_group_remove_all_objs(encoder_group);

    if (!lv_obj_has_flag(ui_UpdateVersionPanel1,LV_OBJ_FLAG_HIDDEN))
    {
        lv_group_add_obj(encoder_group, ui_UpdateVersionBtn1);
        lv_group_add_obj(encoder_group, ui_UpdateVersionBtn2);

    }
    if (!lv_obj_has_flag(ui_UpdateVersionPanel2,LV_OBJ_FLAG_HIDDEN))
    {
        lv_group_add_obj(encoder_group, ui_UpdateVersionBtn3);
        lv_group_add_obj(encoder_group, ui_UpdateVersionBtn4);
    } 
}