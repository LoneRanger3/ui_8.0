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


void setup_scr_messagebox(lv_ui *ui){

	//Write codes messagebox_cont_1
	ui->messagebox_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->messagebox_cont_1, 0, 0);
	lv_obj_set_size(ui->messagebox_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_messagebox_cont_1_main_main_default
	static lv_style_t style_messagebox_cont_1_main_main_default;
	if (style_messagebox_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_messagebox_cont_1_main_main_default);
	else
		lv_style_init(&style_messagebox_cont_1_main_main_default);
	lv_style_set_radius(&style_messagebox_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_messagebox_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_messagebox_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_messagebox_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_messagebox_cont_1_main_main_default, 144);
	lv_style_set_border_color(&style_messagebox_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_messagebox_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_messagebox_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_messagebox_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_messagebox_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_messagebox_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_messagebox_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->messagebox_cont_1, &style_messagebox_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes messagebox_label_1
	ui->messagebox_label_1 = lv_label_create(ui->messagebox_cont_1);
	lv_obj_set_pos(ui->messagebox_label_1, 31, 220);
	lv_obj_set_size(ui->messagebox_label_1, 418, 300);
	lv_label_set_text(ui->messagebox_label_1, "");
	lv_label_set_long_mode(ui->messagebox_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->messagebox_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_messagebox_label_1_main_main_default
	static lv_style_t style_messagebox_label_1_main_main_default;
	if (style_messagebox_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_messagebox_label_1_main_main_default);
	else
		lv_style_init(&style_messagebox_label_1_main_main_default);
	lv_style_set_radius(&style_messagebox_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_messagebox_label_1_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_messagebox_label_1_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_messagebox_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_messagebox_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_messagebox_label_1_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_letter_space(&style_messagebox_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_messagebox_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_messagebox_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_messagebox_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_messagebox_label_1_main_main_default, 0);
	lv_obj_add_style(ui->messagebox_label_1, &style_messagebox_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes messagebox_btn_1
	ui->messagebox_btn_1 = lv_btn_create(ui->messagebox_cont_1);
	lv_obj_set_pos(ui->messagebox_btn_1, 59, 440);
	lv_obj_set_size(ui->messagebox_btn_1, 146, 60);

	//Write style state: LV_STATE_DEFAULT for style_messagebox_btn_1_main_main_default
	static lv_style_t style_messagebox_btn_1_main_main_default;
	if (style_messagebox_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_messagebox_btn_1_main_main_default);
	else
		lv_style_init(&style_messagebox_btn_1_main_main_default);
	lv_style_set_radius(&style_messagebox_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_messagebox_btn_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_color(&style_messagebox_btn_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_dir(&style_messagebox_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_messagebox_btn_1_main_main_default, 255);
	lv_style_set_shadow_color(&style_messagebox_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_messagebox_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_messagebox_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_messagebox_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_messagebox_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->messagebox_btn_1, &style_messagebox_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->messagebox_btn_1_label = lv_label_create(ui->messagebox_btn_1);
	lv_label_set_text(ui->messagebox_btn_1_label, "不正常");
	lv_obj_set_style_text_color(ui->messagebox_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->messagebox_btn_1_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->messagebox_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->messagebox_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes messagebox_btn_2
	ui->messagebox_btn_2 = lv_btn_create(ui->messagebox_cont_1);
	lv_obj_set_pos(ui->messagebox_btn_2, 275, 440);
	lv_obj_set_size(ui->messagebox_btn_2, 146, 60);

	//Write style state: LV_STATE_DEFAULT for style_messagebox_btn_2_main_main_default
	static lv_style_t style_messagebox_btn_2_main_main_default;
	if (style_messagebox_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_messagebox_btn_2_main_main_default);
	else
		lv_style_init(&style_messagebox_btn_2_main_main_default);
	lv_style_set_radius(&style_messagebox_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_messagebox_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_messagebox_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_messagebox_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_messagebox_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_messagebox_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_messagebox_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_messagebox_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_messagebox_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_messagebox_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->messagebox_btn_2, &style_messagebox_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->messagebox_btn_2_label = lv_label_create(ui->messagebox_btn_2);
	lv_label_set_text(ui->messagebox_btn_2_label, "正常");
	lv_obj_set_style_text_color(ui->messagebox_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->messagebox_btn_2_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->messagebox_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->messagebox_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes messagebox_label_2
	ui->messagebox_label_2 = lv_label_create(ui->messagebox_cont_1);
	lv_obj_set_pos(ui->messagebox_label_2, 31, 238);
	lv_obj_set_size(ui->messagebox_label_2, 418, 24);
	lv_label_set_text(ui->messagebox_label_2, "温馨提示");
	lv_label_set_long_mode(ui->messagebox_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->messagebox_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_messagebox_label_2_main_main_default
	static lv_style_t style_messagebox_label_2_main_main_default;
	if (style_messagebox_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_messagebox_label_2_main_main_default);
	else
		lv_style_init(&style_messagebox_label_2_main_main_default);
	lv_style_set_radius(&style_messagebox_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_messagebox_label_2_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_messagebox_label_2_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_messagebox_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_messagebox_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_messagebox_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_messagebox_label_2_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_messagebox_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_messagebox_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_messagebox_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_messagebox_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_messagebox_label_2_main_main_default, 0);
	lv_obj_add_style(ui->messagebox_label_2, &style_messagebox_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes messagebox_label_3
	ui->messagebox_label_3 = lv_label_create(ui->messagebox_cont_1);
	lv_obj_set_pos(ui->messagebox_label_3, 59, 268);
	lv_obj_set_size(ui->messagebox_label_3, 370, 157);
	lv_label_set_text(ui->messagebox_label_3, "");
	lv_label_set_long_mode(ui->messagebox_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->messagebox_label_3, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_messagebox_label_3_main_main_default
	static lv_style_t style_messagebox_label_3_main_main_default;
	if (style_messagebox_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_messagebox_label_3_main_main_default);
	else
		lv_style_init(&style_messagebox_label_3_main_main_default);
	lv_style_set_radius(&style_messagebox_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_messagebox_label_3_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_messagebox_label_3_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_messagebox_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_messagebox_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_messagebox_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_messagebox_label_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_messagebox_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_messagebox_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_messagebox_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_messagebox_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_messagebox_label_3_main_main_default, 0);
	lv_obj_add_style(ui->messagebox_label_3, &style_messagebox_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_messagebox(ui);
}
