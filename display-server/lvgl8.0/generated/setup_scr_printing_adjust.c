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


void setup_scr_printing_adjust(lv_ui *ui){

	//Write codes printing_adjust_cont_1
	ui->printing_adjust_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->printing_adjust_cont_1, 0, 0);
	lv_obj_set_size(ui->printing_adjust_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_cont_1_main_main_default
	static lv_style_t style_printing_adjust_cont_1_main_main_default;
	if (style_printing_adjust_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_cont_1_main_main_default);
	else
		lv_style_init(&style_printing_adjust_cont_1_main_main_default);
	lv_style_set_radius(&style_printing_adjust_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_printing_adjust_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_printing_adjust_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_printing_adjust_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_printing_adjust_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_printing_adjust_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_printing_adjust_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_printing_adjust_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_cont_1, &style_printing_adjust_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_btn_1
	ui->printing_adjust_btn_1 = lv_btn_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_btn_1, 25, 5);
	lv_obj_set_size(ui->printing_adjust_btn_1, 194, 46);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_btn_1_main_main_default
	static lv_style_t style_printing_adjust_btn_1_main_main_default;
	if (style_printing_adjust_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_btn_1_main_main_default);
	else
		lv_style_init(&style_printing_adjust_btn_1_main_main_default);
	lv_style_set_radius(&style_printing_adjust_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_printing_adjust_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_printing_adjust_btn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_printing_adjust_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_btn_1_main_main_default, 255);
	lv_style_set_shadow_color(&style_printing_adjust_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printing_adjust_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_printing_adjust_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_printing_adjust_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_printing_adjust_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_btn_1, &style_printing_adjust_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->printing_adjust_btn_1_label = lv_label_create(ui->printing_adjust_btn_1);
	lv_label_set_text(ui->printing_adjust_btn_1_label, "轴移动/温度");
	lv_obj_set_style_text_color(ui->printing_adjust_btn_1_label, lv_color_make(0x91, 0x93, 0x97), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->printing_adjust_btn_1_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->printing_adjust_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->printing_adjust_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes printing_adjust_btn_2
	ui->printing_adjust_btn_2 = lv_btn_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_btn_2, 225, 5);
	lv_obj_set_size(ui->printing_adjust_btn_2, 150, 46);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_btn_2_main_main_default
	static lv_style_t style_printing_adjust_btn_2_main_main_default;
	if (style_printing_adjust_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_btn_2_main_main_default);
	else
		lv_style_init(&style_printing_adjust_btn_2_main_main_default);
	lv_style_set_radius(&style_printing_adjust_btn_2_main_main_default, 0);
	lv_style_set_bg_color(&style_printing_adjust_btn_2_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_printing_adjust_btn_2_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_printing_adjust_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_printing_adjust_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printing_adjust_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_printing_adjust_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_printing_adjust_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_printing_adjust_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_btn_2, &style_printing_adjust_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->printing_adjust_btn_2_label = lv_label_create(ui->printing_adjust_btn_2);
	lv_label_set_text(ui->printing_adjust_btn_2_label, "调整");
	lv_obj_set_style_text_color(ui->printing_adjust_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->printing_adjust_btn_2_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->printing_adjust_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->printing_adjust_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes printing_adjust_label_1
	ui->printing_adjust_label_1 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_1, 0, 720);
	lv_obj_set_size(ui->printing_adjust_label_1, 480, 80);
	lv_label_set_text(ui->printing_adjust_label_1, "");
	lv_label_set_long_mode(ui->printing_adjust_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_1_main_main_default
	static lv_style_t style_printing_adjust_label_1_main_main_default;
	if (style_printing_adjust_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_1_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_1_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_printing_adjust_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_printing_adjust_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_printing_adjust_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_1_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_1, &style_printing_adjust_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_2
	ui->printing_adjust_label_2 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_2, 0, 49);
	lv_obj_set_size(ui->printing_adjust_label_2, 480, 670);
	lv_label_set_text(ui->printing_adjust_label_2, "");
	lv_label_set_long_mode(ui->printing_adjust_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_2_main_main_default
	static lv_style_t style_printing_adjust_label_2_main_main_default;
	if (style_printing_adjust_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_2_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_2_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_printing_adjust_label_2_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_2_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_printing_adjust_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_printing_adjust_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_2_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_2, &style_printing_adjust_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_3
	ui->printing_adjust_label_3 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_3, 15, 65);
	lv_obj_set_size(ui->printing_adjust_label_3, 150, 28);
	lv_label_set_text(ui->printing_adjust_label_3, "移动距离");
	lv_label_set_long_mode(ui->printing_adjust_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_3, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_3_main_main_default
	static lv_style_t style_printing_adjust_label_3_main_main_default;
	if (style_printing_adjust_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_3_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_3_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_printing_adjust_label_3_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_3_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_printing_adjust_label_3_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_font(&style_printing_adjust_label_3_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_printing_adjust_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_3_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_3, &style_printing_adjust_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_8
	ui->printing_adjust_label_8 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_8, 15, 335);
	lv_obj_set_size(ui->printing_adjust_label_8, 150, 28);
	lv_label_set_text(ui->printing_adjust_label_8, "单位设置");
	lv_label_set_long_mode(ui->printing_adjust_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_8_main_main_default
	static lv_style_t style_printing_adjust_label_8_main_main_default;
	if (style_printing_adjust_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_8_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_8_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_printing_adjust_label_8_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_8_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_printing_adjust_label_8_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_font(&style_printing_adjust_label_8_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_printing_adjust_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_8_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_8, &style_printing_adjust_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_5
	ui->printing_adjust_label_5 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_5, 15, 193);
	lv_obj_set_size(ui->printing_adjust_label_5, 450, 106);
	lv_label_set_text(ui->printing_adjust_label_5, "");
	lv_label_set_long_mode(ui->printing_adjust_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_5, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_5_main_main_default
	static lv_style_t style_printing_adjust_label_5_main_main_default;
	if (style_printing_adjust_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_5_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_5_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_5_main_main_default, 6);
	lv_style_set_bg_color(&style_printing_adjust_label_5_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_5_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_5_main_main_default, 255);
	lv_style_set_text_color(&style_printing_adjust_label_5_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_letter_space(&style_printing_adjust_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_5_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_5, &style_printing_adjust_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_10
	ui->printing_adjust_label_10 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_10, 15, 463);
	lv_obj_set_size(ui->printing_adjust_label_10, 450, 106);
	lv_label_set_text(ui->printing_adjust_label_10, "");
	lv_label_set_long_mode(ui->printing_adjust_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_10, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_10_main_main_default
	static lv_style_t style_printing_adjust_label_10_main_main_default;
	if (style_printing_adjust_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_10_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_10_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_10_main_main_default, 6);
	lv_style_set_bg_color(&style_printing_adjust_label_10_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_10_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_10_main_main_default, 255);
	lv_style_set_text_color(&style_printing_adjust_label_10_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_letter_space(&style_printing_adjust_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_10_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_10, &style_printing_adjust_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_11
	ui->printing_adjust_label_11 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_11, 15, 589);
	lv_obj_set_size(ui->printing_adjust_label_11, 450, 106);
	lv_label_set_text(ui->printing_adjust_label_11, "");
	lv_label_set_long_mode(ui->printing_adjust_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_11, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_11_main_main_default
	static lv_style_t style_printing_adjust_label_11_main_main_default;
	if (style_printing_adjust_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_11_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_11_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_11_main_main_default, 6);
	lv_style_set_bg_color(&style_printing_adjust_label_11_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_11_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_11_main_main_default, 255);
	lv_style_set_text_color(&style_printing_adjust_label_11_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_letter_space(&style_printing_adjust_label_11_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_11_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_11, &style_printing_adjust_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_6
	ui->printing_adjust_label_6 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_6, 166, 220);
	lv_obj_set_size(ui->printing_adjust_label_6, 148, 52);
	lv_label_set_text(ui->printing_adjust_label_6, "");
	lv_label_set_long_mode(ui->printing_adjust_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_6, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_6_main_main_default
	static lv_style_t style_printing_adjust_label_6_main_main_default;
	if (style_printing_adjust_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_6_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_6_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_6_main_main_default, 6);
	lv_style_set_bg_color(&style_printing_adjust_label_6_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_6_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_6_main_main_default, 255);
	lv_style_set_text_color(&style_printing_adjust_label_6_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_letter_space(&style_printing_adjust_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_6_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_6, &style_printing_adjust_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_12
	ui->printing_adjust_label_12 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_12, 166, 490);
	lv_obj_set_size(ui->printing_adjust_label_12, 148, 52);
	lv_label_set_text(ui->printing_adjust_label_12, "");
	lv_label_set_long_mode(ui->printing_adjust_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_12, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_12_main_main_default
	static lv_style_t style_printing_adjust_label_12_main_main_default;
	if (style_printing_adjust_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_12_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_12_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_12_main_main_default, 6);
	lv_style_set_bg_color(&style_printing_adjust_label_12_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_12_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_12_main_main_default, 255);
	lv_style_set_text_color(&style_printing_adjust_label_12_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_letter_space(&style_printing_adjust_label_12_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_12_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_12, &style_printing_adjust_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_14
	ui->printing_adjust_label_14 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_14, 166, 616);
	lv_obj_set_size(ui->printing_adjust_label_14, 148, 52);
	lv_label_set_text(ui->printing_adjust_label_14, "");
	lv_label_set_long_mode(ui->printing_adjust_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_14, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_14_main_main_default
	static lv_style_t style_printing_adjust_label_14_main_main_default;
	if (style_printing_adjust_label_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_14_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_14_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_14_main_main_default, 6);
	lv_style_set_bg_color(&style_printing_adjust_label_14_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_14_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_14_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_14_main_main_default, 255);
	lv_style_set_text_color(&style_printing_adjust_label_14_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_letter_space(&style_printing_adjust_label_14_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_14_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_14_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_14_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_14_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_14, &style_printing_adjust_label_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_7
	ui->printing_adjust_label_7 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_7, 197, 232);
	lv_obj_set_size(ui->printing_adjust_label_7, 90, 28);
	lv_label_set_text(ui->printing_adjust_label_7, "0.00mm");
	lv_label_set_long_mode(ui->printing_adjust_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_7, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_7_main_main_default
	static lv_style_t style_printing_adjust_label_7_main_main_default;
	if (style_printing_adjust_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_7_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_7_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_7_main_main_default, 6);
	lv_style_set_bg_color(&style_printing_adjust_label_7_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_7_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_printing_adjust_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_printing_adjust_label_7_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_printing_adjust_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_7_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_7, &style_printing_adjust_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_13
	ui->printing_adjust_label_13 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_13, 197, 502);
	lv_obj_set_size(ui->printing_adjust_label_13, 90, 28);
	lv_label_set_text(ui->printing_adjust_label_13, "100%");
	lv_label_set_long_mode(ui->printing_adjust_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_13, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_13_main_main_default
	static lv_style_t style_printing_adjust_label_13_main_main_default;
	if (style_printing_adjust_label_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_13_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_13_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_13_main_main_default, 6);
	lv_style_set_bg_color(&style_printing_adjust_label_13_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_13_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_13_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_13_main_main_default, 0);
	lv_style_set_text_color(&style_printing_adjust_label_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_printing_adjust_label_13_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_printing_adjust_label_13_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_13_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_13_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_13_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_13_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_13, &style_printing_adjust_label_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_15
	ui->printing_adjust_label_15 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_15, 194, 629);
	lv_obj_set_size(ui->printing_adjust_label_15, 90, 28);
	lv_label_set_text(ui->printing_adjust_label_15, "100%");
	lv_label_set_long_mode(ui->printing_adjust_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_15, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_15_main_main_default
	static lv_style_t style_printing_adjust_label_15_main_main_default;
	if (style_printing_adjust_label_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_15_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_15_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_15_main_main_default, 6);
	lv_style_set_bg_color(&style_printing_adjust_label_15_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_15_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_15_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_15_main_main_default, 0);
	lv_style_set_text_color(&style_printing_adjust_label_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_printing_adjust_label_15_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_printing_adjust_label_15_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_15_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_15_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_15_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_15_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_15, &style_printing_adjust_label_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_4
	ui->printing_adjust_label_4 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_4, 15, 113);
	lv_obj_set_size(ui->printing_adjust_label_4, 450, 56);
	lv_label_set_text(ui->printing_adjust_label_4, "");
	lv_label_set_long_mode(ui->printing_adjust_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_4, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_4_main_main_default
	static lv_style_t style_printing_adjust_label_4_main_main_default;
	if (style_printing_adjust_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_4_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_4_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_4_main_main_default, 32);
	lv_style_set_bg_color(&style_printing_adjust_label_4_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_4_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_4_main_main_default, 255);
	lv_style_set_text_color(&style_printing_adjust_label_4_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_letter_space(&style_printing_adjust_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_4_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_4, &style_printing_adjust_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_label_9
	ui->printing_adjust_label_9 = lv_label_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_label_9, 15, 383);
	lv_obj_set_size(ui->printing_adjust_label_9, 450, 56);
	lv_label_set_text(ui->printing_adjust_label_9, "");
	lv_label_set_long_mode(ui->printing_adjust_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printing_adjust_label_9, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_label_9_main_main_default
	static lv_style_t style_printing_adjust_label_9_main_main_default;
	if (style_printing_adjust_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_label_9_main_main_default);
	else
		lv_style_init(&style_printing_adjust_label_9_main_main_default);
	lv_style_set_radius(&style_printing_adjust_label_9_main_main_default, 32);
	lv_style_set_bg_color(&style_printing_adjust_label_9_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_color(&style_printing_adjust_label_9_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_dir(&style_printing_adjust_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_label_9_main_main_default, 255);
	lv_style_set_text_color(&style_printing_adjust_label_9_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_letter_space(&style_printing_adjust_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_printing_adjust_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_printing_adjust_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_printing_adjust_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printing_adjust_label_9_main_main_default, 0);
	lv_obj_add_style(ui->printing_adjust_label_9, &style_printing_adjust_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printing_adjust_btn_3
	ui->printing_adjust_btn_3 = lv_btn_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_btn_3, 15, 113);
	lv_obj_set_size(ui->printing_adjust_btn_3, 225, 56);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_btn_3_main_main_default
	static lv_style_t style_printing_adjust_btn_3_main_main_default;
	if (style_printing_adjust_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_btn_3_main_main_default);
	else
		lv_style_init(&style_printing_adjust_btn_3_main_main_default);
	lv_style_set_radius(&style_printing_adjust_btn_3_main_main_default, 32);
	lv_style_set_bg_color(&style_printing_adjust_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_printing_adjust_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_printing_adjust_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_btn_3_main_main_default, 73);
	lv_style_set_shadow_color(&style_printing_adjust_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printing_adjust_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_printing_adjust_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_printing_adjust_btn_3_main_main_default, 2);
	lv_style_set_border_opa(&style_printing_adjust_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_btn_3, &style_printing_adjust_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->printing_adjust_btn_3_label = lv_label_create(ui->printing_adjust_btn_3);
	lv_label_set_text(ui->printing_adjust_btn_3_label, "0.01mm");
	lv_obj_set_style_text_color(ui->printing_adjust_btn_3_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->printing_adjust_btn_3_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->printing_adjust_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->printing_adjust_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes printing_adjust_btn_5
	ui->printing_adjust_btn_5 = lv_btn_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_btn_5, 15, 383);
	lv_obj_set_size(ui->printing_adjust_btn_5, 112, 56);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_btn_5_main_main_default
	static lv_style_t style_printing_adjust_btn_5_main_main_default;
	if (style_printing_adjust_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_btn_5_main_main_default);
	else
		lv_style_init(&style_printing_adjust_btn_5_main_main_default);
	lv_style_set_radius(&style_printing_adjust_btn_5_main_main_default, 32);
	lv_style_set_bg_color(&style_printing_adjust_btn_5_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_printing_adjust_btn_5_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_printing_adjust_btn_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_btn_5_main_main_default, 73);
	lv_style_set_shadow_color(&style_printing_adjust_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printing_adjust_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_printing_adjust_btn_5_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_printing_adjust_btn_5_main_main_default, 2);
	lv_style_set_border_opa(&style_printing_adjust_btn_5_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_btn_5, &style_printing_adjust_btn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->printing_adjust_btn_5_label = lv_label_create(ui->printing_adjust_btn_5);
	lv_label_set_text(ui->printing_adjust_btn_5_label, "1%");
	lv_obj_set_style_text_color(ui->printing_adjust_btn_5_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->printing_adjust_btn_5_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->printing_adjust_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->printing_adjust_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes printing_adjust_btn_6
	ui->printing_adjust_btn_6 = lv_btn_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_btn_6, 127, 383);
	lv_obj_set_size(ui->printing_adjust_btn_6, 112, 56);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_btn_6_main_main_default
	static lv_style_t style_printing_adjust_btn_6_main_main_default;
	if (style_printing_adjust_btn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_btn_6_main_main_default);
	else
		lv_style_init(&style_printing_adjust_btn_6_main_main_default);
	lv_style_set_radius(&style_printing_adjust_btn_6_main_main_default, 32);
	lv_style_set_bg_color(&style_printing_adjust_btn_6_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_printing_adjust_btn_6_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_printing_adjust_btn_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_btn_6_main_main_default, 0);
	lv_style_set_shadow_color(&style_printing_adjust_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printing_adjust_btn_6_main_main_default, 0);
	lv_style_set_border_color(&style_printing_adjust_btn_6_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_printing_adjust_btn_6_main_main_default, 0);
	lv_style_set_border_opa(&style_printing_adjust_btn_6_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_btn_6, &style_printing_adjust_btn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->printing_adjust_btn_6_label = lv_label_create(ui->printing_adjust_btn_6);
	lv_label_set_text(ui->printing_adjust_btn_6_label, "5%");
	lv_obj_set_style_text_color(ui->printing_adjust_btn_6_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->printing_adjust_btn_6_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->printing_adjust_btn_6, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->printing_adjust_btn_6_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes printing_adjust_btn_7
	ui->printing_adjust_btn_7 = lv_btn_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_btn_7, 239, 383);
	lv_obj_set_size(ui->printing_adjust_btn_7, 112, 56);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_btn_7_main_main_default
	static lv_style_t style_printing_adjust_btn_7_main_main_default;
	if (style_printing_adjust_btn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_btn_7_main_main_default);
	else
		lv_style_init(&style_printing_adjust_btn_7_main_main_default);
	lv_style_set_radius(&style_printing_adjust_btn_7_main_main_default, 32);
	lv_style_set_bg_color(&style_printing_adjust_btn_7_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_printing_adjust_btn_7_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_printing_adjust_btn_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_btn_7_main_main_default, 0);
	lv_style_set_shadow_color(&style_printing_adjust_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printing_adjust_btn_7_main_main_default, 0);
	lv_style_set_border_color(&style_printing_adjust_btn_7_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_printing_adjust_btn_7_main_main_default, 0);
	lv_style_set_border_opa(&style_printing_adjust_btn_7_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_btn_7, &style_printing_adjust_btn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->printing_adjust_btn_7_label = lv_label_create(ui->printing_adjust_btn_7);
	lv_label_set_text(ui->printing_adjust_btn_7_label, "10%");
	lv_obj_set_style_text_color(ui->printing_adjust_btn_7_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->printing_adjust_btn_7_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->printing_adjust_btn_7, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->printing_adjust_btn_7_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes printing_adjust_btn_8
	ui->printing_adjust_btn_8 = lv_btn_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_btn_8, 351, 383);
	lv_obj_set_size(ui->printing_adjust_btn_8, 112, 56);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_btn_8_main_main_default
	static lv_style_t style_printing_adjust_btn_8_main_main_default;
	if (style_printing_adjust_btn_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_btn_8_main_main_default);
	else
		lv_style_init(&style_printing_adjust_btn_8_main_main_default);
	lv_style_set_radius(&style_printing_adjust_btn_8_main_main_default, 32);
	lv_style_set_bg_color(&style_printing_adjust_btn_8_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_printing_adjust_btn_8_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_printing_adjust_btn_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_btn_8_main_main_default, 0);
	lv_style_set_shadow_color(&style_printing_adjust_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printing_adjust_btn_8_main_main_default, 0);
	lv_style_set_border_color(&style_printing_adjust_btn_8_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_printing_adjust_btn_8_main_main_default, 0);
	lv_style_set_border_opa(&style_printing_adjust_btn_8_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_btn_8, &style_printing_adjust_btn_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->printing_adjust_btn_8_label = lv_label_create(ui->printing_adjust_btn_8);
	lv_label_set_text(ui->printing_adjust_btn_8_label, "25%");
	lv_obj_set_style_text_color(ui->printing_adjust_btn_8_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->printing_adjust_btn_8_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->printing_adjust_btn_8, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->printing_adjust_btn_8_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes printing_adjust_btn_4
	ui->printing_adjust_btn_4 = lv_btn_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_btn_4, 240, 113);
	lv_obj_set_size(ui->printing_adjust_btn_4, 225, 56);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_btn_4_main_main_default
	static lv_style_t style_printing_adjust_btn_4_main_main_default;
	if (style_printing_adjust_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_btn_4_main_main_default);
	else
		lv_style_init(&style_printing_adjust_btn_4_main_main_default);
	lv_style_set_radius(&style_printing_adjust_btn_4_main_main_default, 32);
	lv_style_set_bg_color(&style_printing_adjust_btn_4_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_printing_adjust_btn_4_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_printing_adjust_btn_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printing_adjust_btn_4_main_main_default, 0);
	lv_style_set_shadow_color(&style_printing_adjust_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printing_adjust_btn_4_main_main_default, 0);
	lv_style_set_border_color(&style_printing_adjust_btn_4_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_printing_adjust_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_printing_adjust_btn_4_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_btn_4, &style_printing_adjust_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->printing_adjust_btn_4_label = lv_label_create(ui->printing_adjust_btn_4);
	lv_label_set_text(ui->printing_adjust_btn_4_label, "0.05mm");
	lv_obj_set_style_text_color(ui->printing_adjust_btn_4_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->printing_adjust_btn_4_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->printing_adjust_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->printing_adjust_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes printing_adjust_img_1
	ui->printing_adjust_img_1 = lv_img_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_img_1, 30, 742);
	lv_obj_set_size(ui->printing_adjust_img_1, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_img_1_main_main_default
	static lv_style_t style_printing_adjust_img_1_main_main_default;
	if (style_printing_adjust_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_img_1_main_main_default);
	else
		lv_style_init(&style_printing_adjust_img_1_main_main_default);
	lv_style_set_img_recolor(&style_printing_adjust_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printing_adjust_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_printing_adjust_img_1_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_img_1, &style_printing_adjust_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printing_adjust_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printing_adjust_img_1,&_home_48x48);
	lv_img_set_pivot(ui->printing_adjust_img_1, 0,0);
	lv_img_set_angle(ui->printing_adjust_img_1, 0);

	//Write codes printing_adjust_img_2
	ui->printing_adjust_img_2 = lv_img_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_img_2, 128, 742);
	lv_obj_set_size(ui->printing_adjust_img_2, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_img_2_main_main_default
	static lv_style_t style_printing_adjust_img_2_main_main_default;
	if (style_printing_adjust_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_img_2_main_main_default);
	else
		lv_style_init(&style_printing_adjust_img_2_main_main_default);
	lv_style_set_img_recolor(&style_printing_adjust_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printing_adjust_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_printing_adjust_img_2_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_img_2, &style_printing_adjust_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printing_adjust_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printing_adjust_img_2,&_prepare_blue_48x48);
	lv_img_set_pivot(ui->printing_adjust_img_2, 0,0);
	lv_img_set_angle(ui->printing_adjust_img_2, 0);

	//Write codes printing_adjust_img_3
	ui->printing_adjust_img_3 = lv_img_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_img_3, 224, 742);
	lv_obj_set_size(ui->printing_adjust_img_3, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_img_3_main_main_default
	static lv_style_t style_printing_adjust_img_3_main_main_default;
	if (style_printing_adjust_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_img_3_main_main_default);
	else
		lv_style_init(&style_printing_adjust_img_3_main_main_default);
	lv_style_set_img_recolor(&style_printing_adjust_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printing_adjust_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_printing_adjust_img_3_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_img_3, &style_printing_adjust_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printing_adjust_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printing_adjust_img_3,&_files_48x48);
	lv_img_set_pivot(ui->printing_adjust_img_3, 0,0);
	lv_img_set_angle(ui->printing_adjust_img_3, 0);

	//Write codes printing_adjust_img_4
	ui->printing_adjust_img_4 = lv_img_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_img_4, 318, 742);
	lv_obj_set_size(ui->printing_adjust_img_4, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_img_4_main_main_default
	static lv_style_t style_printing_adjust_img_4_main_main_default;
	if (style_printing_adjust_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_img_4_main_main_default);
	else
		lv_style_init(&style_printing_adjust_img_4_main_main_default);
	lv_style_set_img_recolor(&style_printing_adjust_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printing_adjust_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_printing_adjust_img_4_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_img_4, &style_printing_adjust_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printing_adjust_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printing_adjust_img_4,&_seting_48x48);
	lv_img_set_pivot(ui->printing_adjust_img_4, 0,0);
	lv_img_set_angle(ui->printing_adjust_img_4, 0);

	//Write codes printing_adjust_img_5
	ui->printing_adjust_img_5 = lv_img_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_img_5, 414, 742);
	lv_obj_set_size(ui->printing_adjust_img_5, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_img_5_main_main_default
	static lv_style_t style_printing_adjust_img_5_main_main_default;
	if (style_printing_adjust_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_img_5_main_main_default);
	else
		lv_style_init(&style_printing_adjust_img_5_main_main_default);
	lv_style_set_img_recolor(&style_printing_adjust_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printing_adjust_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_printing_adjust_img_5_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_img_5, &style_printing_adjust_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printing_adjust_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printing_adjust_img_5,&_FAQ_48x48);
	lv_img_set_pivot(ui->printing_adjust_img_5, 0,0);
	lv_img_set_angle(ui->printing_adjust_img_5, 0);

	//Write codes printing_adjust_img_6
	ui->printing_adjust_img_6 = lv_img_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_img_6, 72, 210);
	lv_obj_set_size(ui->printing_adjust_img_6, 37, 72);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_img_6_main_main_default
	static lv_style_t style_printing_adjust_img_6_main_main_default;
	if (style_printing_adjust_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_img_6_main_main_default);
	else
		lv_style_init(&style_printing_adjust_img_6_main_main_default);
	lv_style_set_img_recolor(&style_printing_adjust_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printing_adjust_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_printing_adjust_img_6_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_img_6, &style_printing_adjust_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printing_adjust_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printing_adjust_img_6,&_z_down_37x72);
	lv_img_set_pivot(ui->printing_adjust_img_6, 0,0);
	lv_img_set_angle(ui->printing_adjust_img_6, 0);

	//Write codes printing_adjust_img_7
	ui->printing_adjust_img_7 = lv_img_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_img_7, 371, 210);
	lv_obj_set_size(ui->printing_adjust_img_7, 37, 72);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_img_7_main_main_default
	static lv_style_t style_printing_adjust_img_7_main_main_default;
	if (style_printing_adjust_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_img_7_main_main_default);
	else
		lv_style_init(&style_printing_adjust_img_7_main_main_default);
	lv_style_set_img_recolor(&style_printing_adjust_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printing_adjust_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_printing_adjust_img_7_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_img_7, &style_printing_adjust_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printing_adjust_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printing_adjust_img_7,&_z_up_37x72);
	lv_img_set_pivot(ui->printing_adjust_img_7, 0,0);
	lv_img_set_angle(ui->printing_adjust_img_7, 0);

	//Write codes printing_adjust_img_8
	ui->printing_adjust_img_8 = lv_img_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_img_8, 47, 480);
	lv_obj_set_size(ui->printing_adjust_img_8, 87, 72);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_img_8_main_main_default
	static lv_style_t style_printing_adjust_img_8_main_main_default;
	if (style_printing_adjust_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_img_8_main_main_default);
	else
		lv_style_init(&style_printing_adjust_img_8_main_main_default);
	lv_style_set_img_recolor(&style_printing_adjust_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printing_adjust_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_printing_adjust_img_8_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_img_8, &style_printing_adjust_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printing_adjust_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printing_adjust_img_8,&_speed_down_87x72);
	lv_img_set_pivot(ui->printing_adjust_img_8, 0,0);
	lv_img_set_angle(ui->printing_adjust_img_8, 0);

	//Write codes printing_adjust_img_9
	ui->printing_adjust_img_9 = lv_img_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_img_9, 343, 480);
	lv_obj_set_size(ui->printing_adjust_img_9, 87, 72);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_img_9_main_main_default
	static lv_style_t style_printing_adjust_img_9_main_main_default;
	if (style_printing_adjust_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_img_9_main_main_default);
	else
		lv_style_init(&style_printing_adjust_img_9_main_main_default);
	lv_style_set_img_recolor(&style_printing_adjust_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printing_adjust_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_printing_adjust_img_9_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_img_9, &style_printing_adjust_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printing_adjust_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printing_adjust_img_9,&_speed_up_87x72);
	lv_img_set_pivot(ui->printing_adjust_img_9, 0,0);
	lv_img_set_angle(ui->printing_adjust_img_9, 0);

	//Write codes printing_adjust_img_10
	ui->printing_adjust_img_10 = lv_img_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_img_10, 47, 606);
	lv_obj_set_size(ui->printing_adjust_img_10, 87, 72);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_img_10_main_main_default
	static lv_style_t style_printing_adjust_img_10_main_main_default;
	if (style_printing_adjust_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_img_10_main_main_default);
	else
		lv_style_init(&style_printing_adjust_img_10_main_main_default);
	lv_style_set_img_recolor(&style_printing_adjust_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printing_adjust_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_printing_adjust_img_10_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_img_10, &style_printing_adjust_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printing_adjust_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printing_adjust_img_10,&_printflow_down_87x72);
	lv_img_set_pivot(ui->printing_adjust_img_10, 0,0);
	lv_img_set_angle(ui->printing_adjust_img_10, 0);

	//Write codes printing_adjust_img_11
	ui->printing_adjust_img_11 = lv_img_create(ui->printing_adjust_cont_1);
	lv_obj_set_pos(ui->printing_adjust_img_11, 343, 606);
	lv_obj_set_size(ui->printing_adjust_img_11, 87, 72);

	//Write style state: LV_STATE_DEFAULT for style_printing_adjust_img_11_main_main_default
	static lv_style_t style_printing_adjust_img_11_main_main_default;
	if (style_printing_adjust_img_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printing_adjust_img_11_main_main_default);
	else
		lv_style_init(&style_printing_adjust_img_11_main_main_default);
	lv_style_set_img_recolor(&style_printing_adjust_img_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_printing_adjust_img_11_main_main_default, 0);
	lv_style_set_img_opa(&style_printing_adjust_img_11_main_main_default, 255);
	lv_obj_add_style(ui->printing_adjust_img_11, &style_printing_adjust_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->printing_adjust_img_11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->printing_adjust_img_11,&_printflow_up_87x72);
	lv_img_set_pivot(ui->printing_adjust_img_11, 0,0);
	lv_img_set_angle(ui->printing_adjust_img_11, 0);

	//Init events for screen
	events_init_printing_adjust(ui);
}
