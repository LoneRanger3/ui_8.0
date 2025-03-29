/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "../custom/custom.h"

static void _keytone_setting_ddlist_1_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_ddlist_1_extra_list_selected_default
	static lv_style_t style_keytone_setting_ddlist_1_extra_list_selected_default;
	if (style_keytone_setting_ddlist_1_extra_list_selected_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_ddlist_1_extra_list_selected_default);
	else
		lv_style_init(&style_keytone_setting_ddlist_1_extra_list_selected_default);
	lv_style_set_radius(&style_keytone_setting_ddlist_1_extra_list_selected_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_ddlist_1_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_keytone_setting_ddlist_1_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_keytone_setting_ddlist_1_extra_list_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_ddlist_1_extra_list_selected_default, 255);
	lv_style_set_border_color(&style_keytone_setting_ddlist_1_extra_list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_keytone_setting_ddlist_1_extra_list_selected_default, 0);
	lv_style_set_text_color(&style_keytone_setting_ddlist_1_extra_list_selected_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_keytone_setting_ddlist_1_extra_list_selected_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_keytone_setting_ddlist_1_extra_list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_ddlist_1_extra_list_main_default
	static lv_style_t style_keytone_setting_ddlist_1_extra_list_main_default;
	if (style_keytone_setting_ddlist_1_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_ddlist_1_extra_list_main_default);
	else
		lv_style_init(&style_keytone_setting_ddlist_1_extra_list_main_default);
	lv_style_set_radius(&style_keytone_setting_ddlist_1_extra_list_main_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_ddlist_1_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_color(&style_keytone_setting_ddlist_1_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_dir(&style_keytone_setting_ddlist_1_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_keytone_setting_ddlist_1_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_keytone_setting_ddlist_1_extra_list_main_default, 0);
	lv_style_set_text_color(&style_keytone_setting_ddlist_1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_keytone_setting_ddlist_1_extra_list_main_default, &lv_font_simsun_24);
	lv_style_set_max_height(&style_keytone_setting_ddlist_1_extra_list_main_default, 130);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_keytone_setting_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_ddlist_1_extra_list_scrollbar_default
	static lv_style_t style_keytone_setting_ddlist_1_extra_list_scrollbar_default;
	if (style_keytone_setting_ddlist_1_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_ddlist_1_extra_list_scrollbar_default);
	else
		lv_style_init(&style_keytone_setting_ddlist_1_extra_list_scrollbar_default);
	lv_style_set_radius(&style_keytone_setting_ddlist_1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_keytone_setting_ddlist_1_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_grad_color(&style_keytone_setting_ddlist_1_extra_list_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_keytone_setting_ddlist_1_extra_list_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_ddlist_1_extra_list_scrollbar_default, 0);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_keytone_setting_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}

void setup_scr_keytone_setting(lv_ui *ui){

	//Write codes keytone_setting_cont_1
	ui->keytone_setting_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->keytone_setting_cont_1, 0, 0);
	lv_obj_set_size(ui->keytone_setting_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_cont_1_main_main_default
	static lv_style_t style_keytone_setting_cont_1_main_main_default;
	if (style_keytone_setting_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_cont_1_main_main_default);
	else
		lv_style_init(&style_keytone_setting_cont_1_main_main_default);
	lv_style_set_radius(&style_keytone_setting_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_keytone_setting_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_keytone_setting_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_keytone_setting_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_keytone_setting_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_keytone_setting_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_keytone_setting_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_keytone_setting_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_keytone_setting_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_keytone_setting_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->keytone_setting_cont_1, &style_keytone_setting_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes keytone_setting_label_3
	ui->keytone_setting_label_3 = lv_label_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_label_3, 8, 63);
	lv_obj_set_size(ui->keytone_setting_label_3, 460, 727);
	lv_label_set_text(ui->keytone_setting_label_3, "");
	lv_label_set_long_mode(ui->keytone_setting_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->keytone_setting_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_label_3_main_main_default
	static lv_style_t style_keytone_setting_label_3_main_main_default;
	if (style_keytone_setting_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_label_3_main_main_default);
	else
		lv_style_init(&style_keytone_setting_label_3_main_main_default);
	lv_style_set_radius(&style_keytone_setting_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_keytone_setting_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_keytone_setting_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_keytone_setting_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_keytone_setting_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_keytone_setting_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_keytone_setting_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_keytone_setting_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_keytone_setting_label_3_main_main_default, 0);
	lv_obj_add_style(ui->keytone_setting_label_3, &style_keytone_setting_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes keytone_setting_ddlist_1
	ui->keytone_setting_ddlist_1 = lv_dropdown_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_ddlist_1, 216, 279);
	lv_obj_set_width(ui->keytone_setting_ddlist_1, 242);
	lv_dropdown_set_options(ui->keytone_setting_ddlist_1, "科技\n灵动\n简短\n清脆");
	lv_obj_add_event_cb(ui->keytone_setting_ddlist_1, _keytone_setting_ddlist_1_event_cb, LV_EVENT_READY, NULL);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_ddlist_1_main_main_default
	static lv_style_t style_keytone_setting_ddlist_1_main_main_default;
	if (style_keytone_setting_ddlist_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_ddlist_1_main_main_default);
	else
		lv_style_init(&style_keytone_setting_ddlist_1_main_main_default);
	lv_style_set_radius(&style_keytone_setting_ddlist_1_main_main_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_ddlist_1_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_keytone_setting_ddlist_1_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_keytone_setting_ddlist_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_ddlist_1_main_main_default, 255);
	lv_style_set_border_color(&style_keytone_setting_ddlist_1_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_keytone_setting_ddlist_1_main_main_default, 1);
	lv_style_set_text_color(&style_keytone_setting_ddlist_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_keytone_setting_ddlist_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_line_space(&style_keytone_setting_ddlist_1_main_main_default, 20);
	lv_obj_add_style(ui->keytone_setting_ddlist_1, &style_keytone_setting_ddlist_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes keytone_setting_label_4
	ui->keytone_setting_label_4 = lv_label_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_label_4, 26, 100);
	lv_obj_set_size(ui->keytone_setting_label_4, 308, 24);
	lv_label_set_text(ui->keytone_setting_label_4, "按键音开关");
	lv_label_set_long_mode(ui->keytone_setting_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->keytone_setting_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_label_4_main_main_default
	static lv_style_t style_keytone_setting_label_4_main_main_default;
	if (style_keytone_setting_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_label_4_main_main_default);
	else
		lv_style_init(&style_keytone_setting_label_4_main_main_default);
	lv_style_set_radius(&style_keytone_setting_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_keytone_setting_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_keytone_setting_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_keytone_setting_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_keytone_setting_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_keytone_setting_label_4_main_main_default, 1);
	lv_style_set_pad_left(&style_keytone_setting_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_keytone_setting_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_keytone_setting_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_keytone_setting_label_4_main_main_default, 0);
	lv_obj_add_style(ui->keytone_setting_label_4, &style_keytone_setting_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes keytone_setting_slider_1
	ui->keytone_setting_slider_1 = lv_slider_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_slider_1, 249, 205);
	lv_obj_set_size(ui->keytone_setting_slider_1, 160, 8);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_slider_1_main_main_default
	static lv_style_t style_keytone_setting_slider_1_main_main_default;
	if (style_keytone_setting_slider_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_slider_1_main_main_default);
	else
		lv_style_init(&style_keytone_setting_slider_1_main_main_default);
	lv_style_set_radius(&style_keytone_setting_slider_1_main_main_default, 50);
	lv_style_set_bg_color(&style_keytone_setting_slider_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_color(&style_keytone_setting_slider_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_dir(&style_keytone_setting_slider_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_slider_1_main_main_default, 255);
	lv_style_set_outline_color(&style_keytone_setting_slider_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_keytone_setting_slider_1_main_main_default, 0);
	lv_style_set_outline_opa(&style_keytone_setting_slider_1_main_main_default, 255);
	lv_style_set_pad_left(&style_keytone_setting_slider_1_main_main_default, 0);
	lv_style_set_pad_right(&style_keytone_setting_slider_1_main_main_default, 0);
	lv_style_set_pad_top(&style_keytone_setting_slider_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_keytone_setting_slider_1_main_main_default, 0);
	lv_obj_add_style(ui->keytone_setting_slider_1, &style_keytone_setting_slider_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_slider_1_main_indicator_default
	static lv_style_t style_keytone_setting_slider_1_main_indicator_default;
	if (style_keytone_setting_slider_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_slider_1_main_indicator_default);
	else
		lv_style_init(&style_keytone_setting_slider_1_main_indicator_default);
	lv_style_set_radius(&style_keytone_setting_slider_1_main_indicator_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_slider_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_keytone_setting_slider_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_keytone_setting_slider_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_slider_1_main_indicator_default, 255);
	lv_obj_add_style(ui->keytone_setting_slider_1, &style_keytone_setting_slider_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_slider_1_main_knob_default
	static lv_style_t style_keytone_setting_slider_1_main_knob_default;
	if (style_keytone_setting_slider_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_slider_1_main_knob_default);
	else
		lv_style_init(&style_keytone_setting_slider_1_main_knob_default);
	lv_style_set_radius(&style_keytone_setting_slider_1_main_knob_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_slider_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_keytone_setting_slider_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_keytone_setting_slider_1_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_slider_1_main_knob_default, 255);
	lv_obj_add_style(ui->keytone_setting_slider_1, &style_keytone_setting_slider_1_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->keytone_setting_slider_1,0, 10);
	lv_slider_set_value(ui->keytone_setting_slider_1,50,false);

	//Write codes keytone_setting_label_5
	ui->keytone_setting_label_5 = lv_label_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_label_5, 26, 193);
	lv_obj_set_size(ui->keytone_setting_label_5, 181, 24);
	lv_label_set_text(ui->keytone_setting_label_5, "音量");
	lv_label_set_long_mode(ui->keytone_setting_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->keytone_setting_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_label_5_main_main_default
	static lv_style_t style_keytone_setting_label_5_main_main_default;
	if (style_keytone_setting_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_label_5_main_main_default);
	else
		lv_style_init(&style_keytone_setting_label_5_main_main_default);
	lv_style_set_radius(&style_keytone_setting_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_label_5_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_keytone_setting_label_5_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_keytone_setting_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_keytone_setting_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_keytone_setting_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_keytone_setting_label_5_main_main_default, 1);
	lv_style_set_pad_left(&style_keytone_setting_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_keytone_setting_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_keytone_setting_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_keytone_setting_label_5_main_main_default, 0);
	lv_obj_add_style(ui->keytone_setting_label_5, &style_keytone_setting_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes keytone_setting_label_6
	ui->keytone_setting_label_6 = lv_label_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_label_6, 26, 288);
	lv_obj_set_size(ui->keytone_setting_label_6, 181, 24);
	lv_label_set_text(ui->keytone_setting_label_6, "音效设置");
	lv_label_set_long_mode(ui->keytone_setting_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->keytone_setting_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_label_6_main_main_default
	static lv_style_t style_keytone_setting_label_6_main_main_default;
	if (style_keytone_setting_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_label_6_main_main_default);
	else
		lv_style_init(&style_keytone_setting_label_6_main_main_default);
	lv_style_set_radius(&style_keytone_setting_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_label_6_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_keytone_setting_label_6_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_keytone_setting_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_keytone_setting_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_keytone_setting_label_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_keytone_setting_label_6_main_main_default, 1);
	lv_style_set_pad_left(&style_keytone_setting_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_keytone_setting_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_keytone_setting_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_keytone_setting_label_6_main_main_default, 0);
	lv_obj_add_style(ui->keytone_setting_label_6, &style_keytone_setting_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes keytone_setting_sw_1
	ui->keytone_setting_sw_1 = lv_switch_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_sw_1, 380, 93);
	lv_obj_set_size(ui->keytone_setting_sw_1, 74, 36);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_sw_1_main_main_default
	static lv_style_t style_keytone_setting_sw_1_main_main_default;
	if (style_keytone_setting_sw_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_sw_1_main_main_default);
	else
		lv_style_init(&style_keytone_setting_sw_1_main_main_default);
	lv_style_set_radius(&style_keytone_setting_sw_1_main_main_default, 100);
	lv_style_set_bg_color(&style_keytone_setting_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_color(&style_keytone_setting_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_dir(&style_keytone_setting_sw_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_sw_1_main_main_default, 255);
	lv_obj_add_style(ui->keytone_setting_sw_1, &style_keytone_setting_sw_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_keytone_setting_sw_1_main_indicator_checked
	static lv_style_t style_keytone_setting_sw_1_main_indicator_checked;
	if (style_keytone_setting_sw_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_sw_1_main_indicator_checked);
	else
		lv_style_init(&style_keytone_setting_sw_1_main_indicator_checked);
	lv_style_set_radius(&style_keytone_setting_sw_1_main_indicator_checked, 100);
	lv_style_set_bg_color(&style_keytone_setting_sw_1_main_indicator_checked, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_keytone_setting_sw_1_main_indicator_checked, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_keytone_setting_sw_1_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_sw_1_main_indicator_checked, 255);
	lv_obj_add_style(ui->keytone_setting_sw_1, &style_keytone_setting_sw_1_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_sw_1_main_knob_default
	static lv_style_t style_keytone_setting_sw_1_main_knob_default;
	if (style_keytone_setting_sw_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_sw_1_main_knob_default);
	else
		lv_style_init(&style_keytone_setting_sw_1_main_knob_default);
	lv_style_set_radius(&style_keytone_setting_sw_1_main_knob_default, 100);
	lv_style_set_bg_color(&style_keytone_setting_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_keytone_setting_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_keytone_setting_sw_1_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_sw_1_main_knob_default, 255);
	lv_obj_add_style(ui->keytone_setting_sw_1, &style_keytone_setting_sw_1_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes keytone_setting_label_1
	ui->keytone_setting_label_1 = lv_label_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_label_1, 0, 0);
	lv_obj_set_size(ui->keytone_setting_label_1, 480, 53);
	lv_label_set_text(ui->keytone_setting_label_1, "");
	lv_label_set_long_mode(ui->keytone_setting_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->keytone_setting_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_label_1_main_main_default
	static lv_style_t style_keytone_setting_label_1_main_main_default;
	if (style_keytone_setting_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_label_1_main_main_default);
	else
		lv_style_init(&style_keytone_setting_label_1_main_main_default);
	lv_style_set_radius(&style_keytone_setting_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_keytone_setting_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_keytone_setting_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_keytone_setting_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_keytone_setting_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_keytone_setting_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_keytone_setting_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_keytone_setting_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_keytone_setting_label_1_main_main_default, 0);
	lv_obj_add_style(ui->keytone_setting_label_1, &style_keytone_setting_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes keytone_setting_img_1
	ui->keytone_setting_img_1 = lv_img_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_img_1, 21, 17);
	lv_obj_set_size(ui->keytone_setting_img_1, 36, 24);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_img_1_main_main_default
	static lv_style_t style_keytone_setting_img_1_main_main_default;
	if (style_keytone_setting_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_img_1_main_main_default);
	else
		lv_style_init(&style_keytone_setting_img_1_main_main_default);
	lv_style_set_img_recolor(&style_keytone_setting_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_keytone_setting_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_keytone_setting_img_1_main_main_default, 255);
	lv_obj_add_style(ui->keytone_setting_img_1, &style_keytone_setting_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->keytone_setting_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->keytone_setting_img_1,&_back_36x24);
	lv_img_set_pivot(ui->keytone_setting_img_1, 0,0);
	lv_img_set_angle(ui->keytone_setting_img_1, 0);

	//Write codes keytone_setting_btn_1
	ui->keytone_setting_btn_1 = lv_btn_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_btn_1, 0, 0);
	lv_obj_set_size(ui->keytone_setting_btn_1, 85, 50);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_btn_1_main_main_default
	static lv_style_t style_keytone_setting_btn_1_main_main_default;
	if (style_keytone_setting_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_btn_1_main_main_default);
	else
		lv_style_init(&style_keytone_setting_btn_1_main_main_default);
	lv_style_set_radius(&style_keytone_setting_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_keytone_setting_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_keytone_setting_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_keytone_setting_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_keytone_setting_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_keytone_setting_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_keytone_setting_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_keytone_setting_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->keytone_setting_btn_1, &style_keytone_setting_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->keytone_setting_btn_1_label = lv_label_create(ui->keytone_setting_btn_1);
	lv_label_set_text(ui->keytone_setting_btn_1_label, "");
	lv_obj_set_style_text_color(ui->keytone_setting_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->keytone_setting_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->keytone_setting_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes keytone_setting_img_2
	ui->keytone_setting_img_2 = lv_img_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_img_2, 216, 192);
	lv_obj_set_size(ui->keytone_setting_img_2, 38, 38);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_img_2_main_main_default
	static lv_style_t style_keytone_setting_img_2_main_main_default;
	if (style_keytone_setting_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_img_2_main_main_default);
	else
		lv_style_init(&style_keytone_setting_img_2_main_main_default);
	lv_style_set_img_recolor(&style_keytone_setting_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_keytone_setting_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_keytone_setting_img_2_main_main_default, 255);
	lv_obj_add_style(ui->keytone_setting_img_2, &style_keytone_setting_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->keytone_setting_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->keytone_setting_img_2,&_group_246_38x38);
	lv_img_set_pivot(ui->keytone_setting_img_2, 0,0);
	lv_img_set_angle(ui->keytone_setting_img_2, 0);

	//Write codes keytone_setting_img_3
	ui->keytone_setting_img_3 = lv_img_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_img_3, 416, 192);
	lv_obj_set_size(ui->keytone_setting_img_3, 38, 38);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_img_3_main_main_default
	static lv_style_t style_keytone_setting_img_3_main_main_default;
	if (style_keytone_setting_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_img_3_main_main_default);
	else
		lv_style_init(&style_keytone_setting_img_3_main_main_default);
	lv_style_set_img_recolor(&style_keytone_setting_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_keytone_setting_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_keytone_setting_img_3_main_main_default, 255);
	lv_obj_add_style(ui->keytone_setting_img_3, &style_keytone_setting_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->keytone_setting_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->keytone_setting_img_3,&_group_245_38x38);
	lv_img_set_pivot(ui->keytone_setting_img_3, 0,0);
	lv_img_set_angle(ui->keytone_setting_img_3, 0);

	//Write codes keytone_setting_label_2
	ui->keytone_setting_label_2 = lv_label_create(ui->keytone_setting_cont_1);
	lv_obj_set_pos(ui->keytone_setting_label_2, 90, 11);
	lv_obj_set_size(ui->keytone_setting_label_2, 300, 32);
	lv_label_set_text(ui->keytone_setting_label_2, "按键音");
	lv_label_set_long_mode(ui->keytone_setting_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->keytone_setting_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_keytone_setting_label_2_main_main_default
	static lv_style_t style_keytone_setting_label_2_main_main_default;
	if (style_keytone_setting_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_keytone_setting_label_2_main_main_default);
	else
		lv_style_init(&style_keytone_setting_label_2_main_main_default);
	lv_style_set_radius(&style_keytone_setting_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_keytone_setting_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_keytone_setting_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_keytone_setting_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keytone_setting_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_keytone_setting_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_keytone_setting_label_2_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_keytone_setting_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_keytone_setting_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_keytone_setting_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_keytone_setting_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_keytone_setting_label_2_main_main_default, 0);
	lv_obj_add_style(ui->keytone_setting_label_2, &style_keytone_setting_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_keytone_setting(ui);
}
