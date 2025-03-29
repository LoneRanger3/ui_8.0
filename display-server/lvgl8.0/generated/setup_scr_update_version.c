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


void setup_scr_update_version(lv_ui *ui){

	//Write codes update_version_cont_1
	ui->update_version_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->update_version_cont_1, 0, 0);
	lv_obj_set_size(ui->update_version_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_update_version_cont_1_main_main_default
	static lv_style_t style_update_version_cont_1_main_main_default;
	if (style_update_version_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_cont_1_main_main_default);
	else
		lv_style_init(&style_update_version_cont_1_main_main_default);
	lv_style_set_radius(&style_update_version_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_update_version_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_update_version_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_update_version_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_cont_1_main_main_default, 144);
	lv_style_set_border_color(&style_update_version_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_update_version_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_update_version_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_update_version_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_update_version_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_update_version_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_update_version_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->update_version_cont_1, &style_update_version_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes update_version_label_1
	ui->update_version_label_1 = lv_label_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_label_1, 32, 179);
	lv_obj_set_size(ui->update_version_label_1, 418, 451);
	lv_label_set_text(ui->update_version_label_1, "");
	lv_label_set_long_mode(ui->update_version_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->update_version_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_update_version_label_1_main_main_default
	static lv_style_t style_update_version_label_1_main_main_default;
	if (style_update_version_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_label_1_main_main_default);
	else
		lv_style_init(&style_update_version_label_1_main_main_default);
	lv_style_set_radius(&style_update_version_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_update_version_label_1_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_update_version_label_1_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_update_version_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_update_version_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_update_version_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_update_version_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_update_version_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_update_version_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_update_version_label_1_main_main_default, 0);
	lv_obj_add_style(ui->update_version_label_1, &style_update_version_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes update_version_label_2
	ui->update_version_label_2 = lv_label_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_label_2, 99, 199);
	lv_obj_set_size(ui->update_version_label_2, 281, 32);
	lv_label_set_text(ui->update_version_label_2, "发现新版本");
	lv_label_set_long_mode(ui->update_version_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->update_version_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_update_version_label_2_main_main_default
	static lv_style_t style_update_version_label_2_main_main_default;
	if (style_update_version_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_label_2_main_main_default);
	else
		lv_style_init(&style_update_version_label_2_main_main_default);
	lv_style_set_radius(&style_update_version_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_update_version_label_2_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_update_version_label_2_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_update_version_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_update_version_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_update_version_label_2_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_update_version_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_update_version_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_update_version_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_update_version_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_update_version_label_2_main_main_default, 0);
	lv_obj_add_style(ui->update_version_label_2, &style_update_version_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes update_version_label_3
	ui->update_version_label_3 = lv_label_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_label_3, 51, 259);
	lv_obj_set_size(ui->update_version_label_3, 107, 24);
	lv_label_set_text(ui->update_version_label_3, "当前版本");
	lv_label_set_long_mode(ui->update_version_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->update_version_label_3, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_update_version_label_3_main_main_default
	static lv_style_t style_update_version_label_3_main_main_default;
	if (style_update_version_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_label_3_main_main_default);
	else
		lv_style_init(&style_update_version_label_3_main_main_default);
	lv_style_set_radius(&style_update_version_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_update_version_label_3_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_update_version_label_3_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_update_version_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_update_version_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_update_version_label_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_update_version_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_update_version_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_update_version_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_update_version_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_update_version_label_3_main_main_default, 0);
	lv_obj_add_style(ui->update_version_label_3, &style_update_version_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes update_version_label_4
	ui->update_version_label_4 = lv_label_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_label_4, 175, 257);
	lv_obj_set_size(ui->update_version_label_4, 233, 24);
	lv_label_set_text(ui->update_version_label_4, "1.0.1");
	lv_label_set_long_mode(ui->update_version_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->update_version_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_update_version_label_4_main_main_default
	static lv_style_t style_update_version_label_4_main_main_default;
	if (style_update_version_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_label_4_main_main_default);
	else
		lv_style_init(&style_update_version_label_4_main_main_default);
	lv_style_set_radius(&style_update_version_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_update_version_label_4_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_update_version_label_4_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_update_version_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_update_version_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_update_version_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_update_version_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_update_version_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_update_version_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_update_version_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_update_version_label_4_main_main_default, 0);
	lv_obj_add_style(ui->update_version_label_4, &style_update_version_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes update_version_label_6
	ui->update_version_label_6 = lv_label_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_label_6, 175, 291);
	lv_obj_set_size(ui->update_version_label_6, 100, 24);
	lv_label_set_text(ui->update_version_label_6, "1.0.1");
	lv_label_set_long_mode(ui->update_version_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->update_version_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_update_version_label_6_main_main_default
	static lv_style_t style_update_version_label_6_main_main_default;
	if (style_update_version_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_label_6_main_main_default);
	else
		lv_style_init(&style_update_version_label_6_main_main_default);
	lv_style_set_radius(&style_update_version_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_update_version_label_6_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_update_version_label_6_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_update_version_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_update_version_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_update_version_label_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_update_version_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_update_version_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_update_version_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_update_version_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_update_version_label_6_main_main_default, 0);
	lv_obj_add_style(ui->update_version_label_6, &style_update_version_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes update_version_label_10
	ui->update_version_label_10 = lv_label_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_label_10, 338, 289);
	lv_obj_set_size(ui->update_version_label_10, 120, 24);
	lv_label_set_text(ui->update_version_label_10, "15MB");
	lv_label_set_long_mode(ui->update_version_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->update_version_label_10, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_update_version_label_10_main_main_default
	static lv_style_t style_update_version_label_10_main_main_default;
	if (style_update_version_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_label_10_main_main_default);
	else
		lv_style_init(&style_update_version_label_10_main_main_default);
	lv_style_set_radius(&style_update_version_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_update_version_label_10_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_update_version_label_10_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_update_version_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_update_version_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_update_version_label_10_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_update_version_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_update_version_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_update_version_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_update_version_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_update_version_label_10_main_main_default, 0);
	lv_obj_add_style(ui->update_version_label_10, &style_update_version_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes update_version_label_11
	ui->update_version_label_11 = lv_label_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_label_11, 148, 473);
	lv_obj_set_size(ui->update_version_label_11, 198, 24);
	lv_label_set_text(ui->update_version_label_11, "10%");
	lv_label_set_long_mode(ui->update_version_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->update_version_label_11, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_update_version_label_11_main_main_default
	static lv_style_t style_update_version_label_11_main_main_default;
	if (style_update_version_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_label_11_main_main_default);
	else
		lv_style_init(&style_update_version_label_11_main_main_default);
	lv_style_set_radius(&style_update_version_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_update_version_label_11_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_update_version_label_11_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_update_version_label_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_update_version_label_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_update_version_label_11_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_update_version_label_11_main_main_default, 0);
	lv_style_set_pad_left(&style_update_version_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_update_version_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_update_version_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_update_version_label_11_main_main_default, 0);
	lv_obj_add_style(ui->update_version_label_11, &style_update_version_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes update_version_label_7
	ui->update_version_label_7 = lv_label_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_label_7, 56, 332);
	lv_obj_set_size(ui->update_version_label_7, 365, 130);
	lv_label_set_text(ui->update_version_label_7, "1、...");
	lv_label_set_long_mode(ui->update_version_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->update_version_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_update_version_label_7_main_main_default
	static lv_style_t style_update_version_label_7_main_main_default;
	if (style_update_version_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_label_7_main_main_default);
	else
		lv_style_init(&style_update_version_label_7_main_main_default);
	lv_style_set_radius(&style_update_version_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_update_version_label_7_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_update_version_label_7_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_update_version_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_update_version_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_update_version_label_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_update_version_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_update_version_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_update_version_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_update_version_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_update_version_label_7_main_main_default, 0);
	lv_obj_add_style(ui->update_version_label_7, &style_update_version_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes update_version_label_5
	ui->update_version_label_5 = lv_label_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_label_5, 51, 291);
	lv_obj_set_size(ui->update_version_label_5, 96, 24);
	lv_label_set_text(ui->update_version_label_5, "新版本盘");
	lv_label_set_long_mode(ui->update_version_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->update_version_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_update_version_label_5_main_main_default
	static lv_style_t style_update_version_label_5_main_main_default;
	if (style_update_version_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_label_5_main_main_default);
	else
		lv_style_init(&style_update_version_label_5_main_main_default);
	lv_style_set_radius(&style_update_version_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_update_version_label_5_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_update_version_label_5_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_update_version_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_update_version_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_update_version_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_update_version_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_update_version_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_update_version_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_update_version_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_update_version_label_5_main_main_default, 0);
	lv_obj_add_style(ui->update_version_label_5, &style_update_version_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes update_version_btn_1
	ui->update_version_btn_1 = lv_btn_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_btn_1, 59, 541);
	lv_obj_set_size(ui->update_version_btn_1, 146, 60);

	//Write style state: LV_STATE_DEFAULT for style_update_version_btn_1_main_main_default
	static lv_style_t style_update_version_btn_1_main_main_default;
	if (style_update_version_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_btn_1_main_main_default);
	else
		lv_style_init(&style_update_version_btn_1_main_main_default);
	lv_style_set_radius(&style_update_version_btn_1_main_main_default, 8);
	lv_style_set_bg_color(&style_update_version_btn_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_color(&style_update_version_btn_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_dir(&style_update_version_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_btn_1_main_main_default, 255);
	lv_style_set_shadow_color(&style_update_version_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_update_version_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_update_version_btn_1_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_update_version_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_update_version_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->update_version_btn_1, &style_update_version_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->update_version_btn_1_label = lv_label_create(ui->update_version_btn_1);
	lv_label_set_text(ui->update_version_btn_1_label, "取消");
	lv_obj_set_style_text_color(ui->update_version_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->update_version_btn_1_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->update_version_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->update_version_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes update_version_btn_2
	ui->update_version_btn_2 = lv_btn_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_btn_2, 275, 541);
	lv_obj_set_size(ui->update_version_btn_2, 146, 60);

	//Write style state: LV_STATE_DEFAULT for style_update_version_btn_2_main_main_default
	static lv_style_t style_update_version_btn_2_main_main_default;
	if (style_update_version_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_btn_2_main_main_default);
	else
		lv_style_init(&style_update_version_btn_2_main_main_default);
	lv_style_set_radius(&style_update_version_btn_2_main_main_default, 8);
	lv_style_set_bg_color(&style_update_version_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_update_version_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_update_version_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_update_version_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_update_version_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_update_version_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_update_version_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_update_version_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->update_version_btn_2, &style_update_version_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->update_version_btn_2_label = lv_label_create(ui->update_version_btn_2);
	lv_label_set_text(ui->update_version_btn_2_label, "下载");
	lv_obj_set_style_text_color(ui->update_version_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->update_version_btn_2_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->update_version_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->update_version_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes update_version_btn_3
	ui->update_version_btn_3 = lv_btn_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_btn_3, 167, 550);
	lv_obj_set_size(ui->update_version_btn_3, 146, 60);

	//Write style state: LV_STATE_DEFAULT for style_update_version_btn_3_main_main_default
	static lv_style_t style_update_version_btn_3_main_main_default;
	if (style_update_version_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_btn_3_main_main_default);
	else
		lv_style_init(&style_update_version_btn_3_main_main_default);
	lv_style_set_radius(&style_update_version_btn_3_main_main_default, 8);
	lv_style_set_bg_color(&style_update_version_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_update_version_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_update_version_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_btn_3_main_main_default, 255);
	lv_style_set_shadow_color(&style_update_version_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_update_version_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_update_version_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_update_version_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_update_version_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->update_version_btn_3, &style_update_version_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->update_version_btn_3_label = lv_label_create(ui->update_version_btn_3);
	lv_label_set_text(ui->update_version_btn_3_label, "取消下载");
	lv_obj_set_style_text_color(ui->update_version_btn_3_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->update_version_btn_3_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->update_version_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->update_version_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes update_version_bar_1
	ui->update_version_bar_1 = lv_bar_create(ui->update_version_cont_1);
	lv_obj_set_pos(ui->update_version_bar_1, 67, 511);
	lv_obj_set_size(ui->update_version_bar_1, 349, 14);

	//Write style state: LV_STATE_DEFAULT for style_update_version_bar_1_main_main_default
	static lv_style_t style_update_version_bar_1_main_main_default;
	if (style_update_version_bar_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_bar_1_main_main_default);
	else
		lv_style_init(&style_update_version_bar_1_main_main_default);
	lv_style_set_radius(&style_update_version_bar_1_main_main_default, 0);
	lv_style_set_bg_color(&style_update_version_bar_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_color(&style_update_version_bar_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_dir(&style_update_version_bar_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_bar_1_main_main_default, 255);
	lv_style_set_pad_left(&style_update_version_bar_1_main_main_default, 0);
	lv_style_set_pad_right(&style_update_version_bar_1_main_main_default, 0);
	lv_style_set_pad_top(&style_update_version_bar_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_update_version_bar_1_main_main_default, 0);
	lv_obj_add_style(ui->update_version_bar_1, &style_update_version_bar_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_update_version_bar_1_main_indicator_default
	static lv_style_t style_update_version_bar_1_main_indicator_default;
	if (style_update_version_bar_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_update_version_bar_1_main_indicator_default);
	else
		lv_style_init(&style_update_version_bar_1_main_indicator_default);
	lv_style_set_radius(&style_update_version_bar_1_main_indicator_default, 0);
	lv_style_set_bg_color(&style_update_version_bar_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_update_version_bar_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_update_version_bar_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_update_version_bar_1_main_indicator_default, 255);
	lv_obj_add_style(ui->update_version_bar_1, &style_update_version_bar_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->update_version_bar_1, 1000, 0);
	lv_bar_set_mode(ui->update_version_bar_1, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->update_version_bar_1, 50, LV_ANIM_OFF);

	//Init events for screen
	events_init_update_version(ui);
}
