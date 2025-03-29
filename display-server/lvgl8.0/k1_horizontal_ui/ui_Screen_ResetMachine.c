/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-01 14:54:52
 * @LastEditTime: 2023-02-15 17:23:05
 */
#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "mult_language.h"

lv_obj_t * ui_ResetMachine;
lv_obj_t * ui_ResetMachinePanel1;
lv_obj_t * ui_homeimg1;
lv_obj_t * ui_axismoveimg1;
lv_obj_t * ui_fileimg1;
lv_obj_t * ui_settingsimg1;
lv_obj_t * ui_faqimg1;
lv_obj_t * ui_resetmachinepanel2;
lv_obj_t * ui_resetmachinepanel3;
lv_obj_t * ui_resetmachinepanel4;
lv_obj_t * ui_resetmachinetitle;
lv_obj_t * ui_resetmachinelabel1;
lv_obj_t * ui_resetCheckbox1;
lv_obj_t * ui_resetCheckbox2;
lv_obj_t * ui_resetCheckbox3;
lv_obj_t * ui_resetCheckbox4;
lv_obj_t * ui_resetmachinebutton1;
lv_obj_t * ui_resetmachine_Label1;
lv_obj_t * ui_resetmachinebutton2;
lv_obj_t * ui_resetmachine_Label2;

void ui_event_resetmachinebutton2(lv_event_t * e);
void ui_event_resetmachinebutton1(lv_event_t * e);
void ui_event_resetmachinehomeimg1(lv_event_t * e);
void ui_event_resetmachineaxismoveimg1(lv_event_t * e);
void ui_event_resetmachinefileimg1(lv_event_t * e);
void ui_event_resetmachinesettingsimg1(lv_event_t * e);
void ui_event_resetmachinefaqimg1(lv_event_t * e);
void ui_event_ResetMachine(lv_event_t * e);

void ui_ResetMachine_screen_init(void)
{
    ui_ResetMachine = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ResetMachine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    ui_ResetMachinePanel1 = lv_obj_create(ui_ResetMachine);
    lv_obj_set_width(ui_ResetMachinePanel1, 80);
    lv_obj_set_height(ui_ResetMachinePanel1, 480);
    lv_obj_clear_flag(ui_ResetMachinePanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ResetMachinePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ResetMachinePanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ResetMachinePanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ResetMachinePanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ResetMachinePanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ResetMachinePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ResetMachinePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ResetMachinePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ResetMachinePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ResetMachinePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_homeimg1 = lv_img_create(ui_ResetMachinePanel1);
    lv_img_set_src(ui_homeimg1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_homeimg1, 80);
    lv_obj_set_height(ui_homeimg1, 96);
    lv_obj_add_flag(ui_homeimg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_homeimg1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_homeimg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_homeimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_axismoveimg1 = lv_img_create(ui_ResetMachinePanel1);
    lv_img_set_src(ui_axismoveimg1, &ui_img_pagemove_png);
    lv_obj_set_width(ui_axismoveimg1, 80);
    lv_obj_set_height(ui_axismoveimg1, 96);
    lv_obj_set_x(ui_axismoveimg1, 0);
    lv_obj_set_y(ui_axismoveimg1, 96);
    lv_obj_add_flag(ui_axismoveimg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_axismoveimg1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_axismoveimg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_axismoveimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_axismoveimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_fileimg1 = lv_img_create(ui_ResetMachinePanel1);
    lv_img_set_src(ui_fileimg1, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_fileimg1, 80);
    lv_obj_set_height(ui_fileimg1, 96);
    lv_obj_set_x(ui_fileimg1, 0);
    lv_obj_set_y(ui_fileimg1, 192);
    lv_obj_add_flag(ui_fileimg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_fileimg1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_fileimg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_fileimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_fileimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingsimg1 = lv_img_create(ui_ResetMachinePanel1);
    lv_img_set_src(ui_settingsimg1, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_settingsimg1, 80);
    lv_obj_set_height(ui_settingsimg1, 96);
    lv_obj_set_x(ui_settingsimg1, 0);
    lv_obj_set_y(ui_settingsimg1, 288);
    lv_obj_add_flag(ui_settingsimg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_settingsimg1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_settingsimg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_settingsimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_settingsimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_faqimg1 = lv_img_create(ui_ResetMachinePanel1);
    lv_img_set_src(ui_faqimg1, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_faqimg1, 80);
    lv_obj_set_height(ui_faqimg1, 96);
    lv_obj_set_x(ui_faqimg1, 0);
    lv_obj_set_y(ui_faqimg1, 384);
    lv_obj_add_flag(ui_faqimg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_faqimg1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_faqimg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_faqimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_faqimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetmachinepanel2 = lv_obj_create(ui_ResetMachine);
    lv_obj_set_width(ui_resetmachinepanel2, 720);
    lv_obj_set_height(ui_resetmachinepanel2, 480);
    lv_obj_set_x(ui_resetmachinepanel2, 80);
    lv_obj_set_y(ui_resetmachinepanel2, 0);
    lv_obj_clear_flag(ui_resetmachinepanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_resetmachinepanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_resetmachinepanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetmachinepanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_resetmachinepanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_resetmachinepanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetmachinepanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_resetmachinepanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_resetmachinepanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_resetmachinepanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_resetmachinepanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetmachinepanel3 = lv_obj_create(ui_resetmachinepanel2);
    lv_obj_set_width(ui_resetmachinepanel3, 696);
    lv_obj_set_height(ui_resetmachinepanel3, 456);
    lv_obj_set_x(ui_resetmachinepanel3, 0);
    lv_obj_set_y(ui_resetmachinepanel3, -1);
    lv_obj_set_align(ui_resetmachinepanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_resetmachinepanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_resetmachinepanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_resetmachinepanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetmachinepanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetmachinepanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_resetmachinepanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_resetmachinepanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_resetmachinepanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_resetmachinepanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetmachinepanel4 = lv_obj_create(ui_resetmachinepanel3);
    lv_obj_set_width(ui_resetmachinepanel4, 676);
    lv_obj_set_height(ui_resetmachinepanel4, 65);
    lv_obj_set_x(ui_resetmachinepanel4, 10);
    lv_obj_set_y(ui_resetmachinepanel4, 0);
    lv_obj_clear_flag(ui_resetmachinepanel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_resetmachinepanel4, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_resetmachinepanel4, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetmachinepanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_resetmachinepanel4, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_resetmachinepanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetmachinepanel4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_resetmachinepanel4, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_resetmachinepanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_resetmachinepanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_resetmachinepanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_resetmachinepanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetmachinetitle = lv_label_create(ui_resetmachinepanel4);
    lv_obj_set_width(ui_resetmachinetitle, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_resetmachinetitle, 24);
    lv_obj_set_x(ui_resetmachinetitle, 15);
    lv_obj_set_y(ui_resetmachinetitle, 0);
    lv_obj_set_align(ui_resetmachinetitle, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_resetmachinetitle, ResetMachine[language_index]);
    lv_obj_set_style_text_color(ui_resetmachinetitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetmachinetitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetmachinetitle, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetmachinelabel1 = lv_label_create(ui_resetmachinepanel3);
    lv_obj_set_width(ui_resetmachinelabel1, 500);
    lv_obj_set_height(ui_resetmachinelabel1, 28);
    lv_obj_set_x(ui_resetmachinelabel1, 29);
    lv_obj_set_y(ui_resetmachinelabel1, 90);
    lv_label_set_text(ui_resetmachinelabel1, CleanItemArray[language_index]);
    lv_obj_set_style_text_color(ui_resetmachinelabel1, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetmachinelabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetmachinelabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetCheckbox1 = lv_checkbox_create(ui_resetmachinepanel3);
    lv_checkbox_set_text(ui_resetCheckbox1, LogArray[language_index]);
    lv_obj_set_width(ui_resetCheckbox1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_resetCheckbox1, 33);
    lv_obj_align_to(ui_resetCheckbox1, ui_resetmachinelabel1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 17);
    lv_obj_add_flag(ui_resetCheckbox1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_resetCheckbox1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetCheckbox1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetCheckbox1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_resetCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_resetCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox1, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_resetCheckbox1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_resetCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox1, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox1, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_resetCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_resetCheckbox2 = lv_checkbox_create(ui_resetmachinepanel3);
    lv_checkbox_set_text(ui_resetCheckbox2, DelayPhotographVedioes[language_index]);
    lv_obj_set_width(ui_resetCheckbox2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_resetCheckbox2, 33);
    lv_obj_set_x(ui_resetCheckbox2, 29);
    lv_obj_set_y(ui_resetCheckbox2, 205);
    lv_obj_align_to(ui_resetCheckbox2, ui_resetCheckbox1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 30);
    lv_obj_add_flag(ui_resetCheckbox2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_resetCheckbox2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetCheckbox2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetCheckbox2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_resetCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_resetCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox2, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_resetCheckbox2, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_resetCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox2, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox2, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_resetCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_resetCheckbox3 = lv_checkbox_create(ui_resetmachinepanel3);
    // char buff[30] = {0};
    // sprintf(buff, "Gcode%s", FileArray[language_index]);
    lv_checkbox_set_text(ui_resetCheckbox3, FileArray[language_index]);
    lv_obj_set_width(ui_resetCheckbox3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_resetCheckbox3, 33);
    lv_obj_set_x(ui_resetCheckbox3, 423);
    lv_obj_set_y(ui_resetCheckbox3, 148);
    lv_obj_align_to(ui_resetCheckbox3, ui_resetCheckbox2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 30);
    lv_obj_add_flag(ui_resetCheckbox3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_resetCheckbox3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetCheckbox3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetCheckbox3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_resetCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_resetCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox3, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_resetCheckbox3, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_resetCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox3, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox3, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_resetCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_resetCheckbox4 = lv_checkbox_create(ui_resetmachinepanel3);
    // memset(buff, 0, sizeof(buff));
    // sprintf(buff, "%s%s", Print[language_index], RecordsArray[language_index]);
    lv_checkbox_set_text(ui_resetCheckbox4, RecordsArray[language_index]);
    lv_obj_set_width(ui_resetCheckbox4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_resetCheckbox4, 33);
    lv_obj_set_x(ui_resetCheckbox4, 423);
    lv_obj_set_y(ui_resetCheckbox4, 205);
    lv_obj_align_to(ui_resetCheckbox4, ui_resetCheckbox3, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 30);
    lv_obj_add_flag(ui_resetCheckbox4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_resetCheckbox4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetCheckbox4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetCheckbox4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_resetCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_resetCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox4, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_resetCheckbox4, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_resetCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox4, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox4, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_resetCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_resetmachinebutton1 = lv_btn_create(ui_resetmachinepanel3);
    lv_obj_set_width(ui_resetmachinebutton1, 116);
    lv_obj_set_height(ui_resetmachinebutton1, 60);
    lv_obj_align(ui_resetmachinebutton1, LV_ALIGN_BOTTOM_RIGHT, -20, -15);
    lv_obj_add_flag(ui_resetmachinebutton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_resetmachinebutton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_resetmachinebutton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_resetmachinebutton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetmachinebutton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_resetmachinebutton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_resetmachinebutton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_resetmachinebutton1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetmachinebutton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetmachinebutton1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetmachine_Label1 = lv_label_create(ui_resetmachinebutton1);
    lv_obj_set_width(ui_resetmachine_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_resetmachine_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_resetmachine_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_resetmachine_Label1, ResetArray[language_index]);
    lv_obj_set_style_text_font(ui_resetmachine_Label1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetmachinebutton2 = lv_btn_create(ui_resetmachinepanel3);
    lv_obj_set_width(ui_resetmachinebutton2, 116);
    lv_obj_set_height(ui_resetmachinebutton2, 60);
    lv_obj_align_to(ui_resetmachinebutton2, ui_resetmachinebutton1, LV_ALIGN_OUT_LEFT_MID, -25, 0);
    lv_obj_add_flag(ui_resetmachinebutton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_resetmachinebutton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_resetmachinebutton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_resetmachinebutton2, lv_color_hex(0x28292D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetmachinebutton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_resetmachinebutton2, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_resetmachinebutton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetmachinebutton2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_resetmachinebutton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_resetmachinebutton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_resetmachinebutton2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetmachinebutton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetmachinebutton2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetmachine_Label2 = lv_label_create(ui_resetmachinebutton2);
    lv_obj_set_width(ui_resetmachine_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_resetmachine_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_resetmachine_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_resetmachine_Label2, Back[language_index]);
    lv_obj_set_style_text_font(ui_resetmachine_Label2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_resetmachinebutton2, ui_event_resetmachinebutton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_resetmachinebutton1, ui_event_resetmachinebutton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_homeimg1, ui_event_resetmachinehomeimg1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_axismoveimg1, ui_event_resetmachineaxismoveimg1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_fileimg1, ui_event_resetmachinefileimg1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_settingsimg1, ui_event_resetmachinesettingsimg1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_faqimg1, ui_event_resetmachinefaqimg1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ResetMachine, ui_event_ResetMachine, LV_EVENT_ALL, NULL);

}

void ui_event_ResetMachine(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load the resetmachine page");
        if(!lv_obj_get_state(ui_resetCheckbox1)) lv_obj_add_state(ui_resetCheckbox1, LV_STATE_CHECKED);
        if(!lv_obj_get_state(ui_resetCheckbox2)) lv_obj_add_state(ui_resetCheckbox2, LV_STATE_CHECKED);
        if(!lv_obj_get_state(ui_resetCheckbox3)) lv_obj_add_state(ui_resetCheckbox3, LV_STATE_CHECKED);
        if(!lv_obj_get_state(ui_resetCheckbox4)) lv_obj_add_state(ui_resetCheckbox4, LV_STATE_CHECKED);
    }
}

void ui_event_resetmachinehomeimg1(lv_event_t * e)
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

void ui_event_resetmachineaxismoveimg1(lv_event_t * e)
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

void ui_event_resetmachinefileimg1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadFileManageScreen();
    }
}

void ui_event_resetmachinesettingsimg1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_resetmachinefaqimg1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadCustomerServiceScreen();
    }
}

void ui_event_resetmachinebutton2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

bool IsFactorySnExists(void)
{
    bool snExistFlag = false;
    json_object* machineInfoObj = json_object_from_file(GetMachineProductionInfo());
    if(machineInfoObj) {
        json_object* snObj = json_object_object_get(machineInfoObj,"productionSn");
        if(snObj) {
            if (json_object_get_string_len(snObj) > 10) snExistFlag = true;
        }
    }

    if(machineInfoObj) json_object_put(machineInfoObj);
    return snExistFlag;
}

void clear_data()
{
    send_buzzer(0x01);
    int state[4] = {0};
    state[0] = lv_obj_get_state(ui_resetCheckbox1) & LV_STATE_CHECKED ? 1 : 0;  //日志
    state[1] = lv_obj_get_state(ui_resetCheckbox2) & LV_STATE_CHECKED ? 1 : 0;  //延时摄影视频
    state[2] = lv_obj_get_state(ui_resetCheckbox3) & LV_STATE_CHECKED ? 1 : 0;  //Gcode文件
    state[3] = lv_obj_get_state(ui_resetCheckbox4) & LV_STATE_CHECKED ? 1 : 0;  //打印记录
    CrLogI("reset options is %d%d%d%d.",state[0],state[1],state[2],state[3]);
    char temp[6]= {0};
    snprintf(temp,6,"6%d%d%d%d",state[0],state[1],state[2],state[3]);
    set_printer_data(0x06,6,temp);
    set_printer_data(0x06,2,"91");
    selftest_messagebox_close();
    create_msgbox(ResetMachineTips[get_cur_language_index()], &ui_img_wait_png, 20 * 1000, lv_scr_act());
}

void not_clear_data()
{
    send_buzzer(0x01);
    selftest_messagebox_close();
}

void ui_event_resetmachinebutton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        uint8_t language_index = get_cur_language_index();
        void (*btns_callback[2])(void) = {&not_clear_data, &clear_data};
        char tempbuff[512] = {0};
        if(IsFactorySnExists())
            create_selftest_messagebox(KindTips[language_index], ResetUserData[language_index],Cancel[language_index], Confirm[language_index], btns_callback);
        else
        {
            snprintf(tempbuff, 512, "%s\n#FF0000 %s#", ResetUserData[language_index], "!!!!!!");
            create_selftest_messagebox(KindTips[language_index], tempbuff,Cancel[language_index], Confirm[language_index], btns_callback);
        }

    }
}

void reset_machine_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_resetmachinetitle )
        lv_label_set_text(ui_resetmachinetitle, ResetMachine[language_index]);
        
    if ( ui_resetmachinelabel1 )
        lv_label_set_text(ui_resetmachinelabel1, CleanItemArray[language_index]);
    
    if ( ui_resetCheckbox1 )
        lv_checkbox_set_text(ui_resetCheckbox1, LogArray[language_index]);
    
    if ( ui_resetCheckbox2 )
        lv_checkbox_set_text(ui_resetCheckbox2, DelayPhotographVedioes[language_index]);
    
    char buff[30] = {0};
    if ( ui_resetCheckbox3 )
    {
        // sprintf(buff, "Gcode%s", FileArray[language_index]);
        lv_checkbox_set_text(ui_resetCheckbox3, FileArray[language_index]);
    }

    if ( ui_resetCheckbox4 )
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", Print[language_index], RecordsArray[language_index]);
        lv_checkbox_set_text(ui_resetCheckbox4, RecordsArray[language_index]);
    }

    if ( ui_resetmachine_Label1 )
    {
        lv_label_set_text(ui_resetmachine_Label1, ResetArray[language_index]);
        redefine_label_size(ui_resetmachine_Label1, lv_font24.font, 0, 0, 240, 0);

        lv_obj_update_layout(ui_resetmachinebutton1);
        redefine_widgets_size(ui_resetmachinebutton1, ui_resetmachine_Label1, 10, 0, 116, 60);

        lv_obj_align_to(ui_resetmachinebutton2, ui_resetmachinebutton1, LV_ALIGN_OUT_LEFT_MID, -25, 0);
    }

    if ( ui_resetmachine_Label2 )
        lv_label_set_text(ui_resetmachine_Label2, Back[language_index]);
}