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


void setup_scr_select_language(lv_ui *ui){

	//Write codes select_language_cont_1
	ui->select_language_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->select_language_cont_1, 0, 0);
	lv_obj_set_size(ui->select_language_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_select_language_cont_1_main_main_default
	static lv_style_t style_select_language_cont_1_main_main_default;
	if (style_select_language_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_select_language_cont_1_main_main_default);
	else
		lv_style_init(&style_select_language_cont_1_main_main_default);
	lv_style_set_radius(&style_select_language_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_select_language_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_select_language_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_select_language_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_select_language_cont_1_main_main_default, 144);
	lv_style_set_border_color(&style_select_language_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_select_language_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_select_language_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_select_language_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_select_language_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_select_language_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_select_language_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->select_language_cont_1, &style_select_language_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes select_language_btn_1
	ui->select_language_btn_1 = lv_btn_create(ui->select_language_cont_1);
	lv_obj_set_pos(ui->select_language_btn_1, 17, 107);
	lv_obj_set_size(ui->select_language_btn_1, 218, 108);

	//Write style state: LV_STATE_DEFAULT for style_select_language_btn_1_main_main_default
	static lv_style_t style_select_language_btn_1_main_main_default;
	if (style_select_language_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_select_language_btn_1_main_main_default);
	else
		lv_style_init(&style_select_language_btn_1_main_main_default);
	lv_style_set_radius(&style_select_language_btn_1_main_main_default, 8);
	lv_style_set_bg_color(&style_select_language_btn_1_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_select_language_btn_1_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_select_language_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_select_language_btn_1_main_main_default, 255);
	lv_style_set_shadow_color(&style_select_language_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_select_language_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_select_language_btn_1_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_select_language_btn_1_main_main_default, 2);
	lv_style_set_border_opa(&style_select_language_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->select_language_btn_1, &style_select_language_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->select_language_btn_1_label = lv_label_create(ui->select_language_btn_1);
	lv_label_set_text(ui->select_language_btn_1_label, "中文");
	lv_obj_set_style_text_color(ui->select_language_btn_1_label, lv_color_make(0x42, 0xbd, 0xd8), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->select_language_btn_1_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->select_language_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->select_language_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes select_language_btn_2
	ui->select_language_btn_2 = lv_btn_create(ui->select_language_cont_1);
	lv_obj_set_pos(ui->select_language_btn_2, 247, 107);
	lv_obj_set_size(ui->select_language_btn_2, 218, 108);

	//Write style state: LV_STATE_DEFAULT for style_select_language_btn_2_main_main_default
	static lv_style_t style_select_language_btn_2_main_main_default;
	if (style_select_language_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_select_language_btn_2_main_main_default);
	else
		lv_style_init(&style_select_language_btn_2_main_main_default);
	lv_style_set_radius(&style_select_language_btn_2_main_main_default, 8);
	lv_style_set_bg_color(&style_select_language_btn_2_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_select_language_btn_2_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_select_language_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_select_language_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_select_language_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_select_language_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_select_language_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_select_language_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_select_language_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->select_language_btn_2, &style_select_language_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->select_language_btn_2_label = lv_label_create(ui->select_language_btn_2);
	lv_label_set_text(ui->select_language_btn_2_label, "English");
	lv_obj_set_style_text_color(ui->select_language_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->select_language_btn_2_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->select_language_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->select_language_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes select_language_btn_3
	ui->select_language_btn_3 = lv_btn_create(ui->select_language_cont_1);
	lv_obj_set_pos(ui->select_language_btn_3, 17, 227);
	lv_obj_set_size(ui->select_language_btn_3, 218, 108);

	//Write style state: LV_STATE_DEFAULT for style_select_language_btn_3_main_main_default
	static lv_style_t style_select_language_btn_3_main_main_default;
	if (style_select_language_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_select_language_btn_3_main_main_default);
	else
		lv_style_init(&style_select_language_btn_3_main_main_default);
	lv_style_set_radius(&style_select_language_btn_3_main_main_default, 8);
	lv_style_set_bg_color(&style_select_language_btn_3_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_select_language_btn_3_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_select_language_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_select_language_btn_3_main_main_default, 255);
	lv_style_set_shadow_color(&style_select_language_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_select_language_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_select_language_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_select_language_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_select_language_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->select_language_btn_3, &style_select_language_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->select_language_btn_3_label = lv_label_create(ui->select_language_btn_3);
	lv_label_set_text(ui->select_language_btn_3_label, "3");
	lv_obj_set_style_text_color(ui->select_language_btn_3_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->select_language_btn_3_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->select_language_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->select_language_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes select_language_btn_4
	ui->select_language_btn_4 = lv_btn_create(ui->select_language_cont_1);
	lv_obj_set_pos(ui->select_language_btn_4, 247, 227);
	lv_obj_set_size(ui->select_language_btn_4, 218, 108);

	//Write style state: LV_STATE_DEFAULT for style_select_language_btn_4_main_main_default
	static lv_style_t style_select_language_btn_4_main_main_default;
	if (style_select_language_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_select_language_btn_4_main_main_default);
	else
		lv_style_init(&style_select_language_btn_4_main_main_default);
	lv_style_set_radius(&style_select_language_btn_4_main_main_default, 8);
	lv_style_set_bg_color(&style_select_language_btn_4_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_select_language_btn_4_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_select_language_btn_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_select_language_btn_4_main_main_default, 255);
	lv_style_set_shadow_color(&style_select_language_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_select_language_btn_4_main_main_default, 0);
	lv_style_set_border_color(&style_select_language_btn_4_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_select_language_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_select_language_btn_4_main_main_default, 255);
	lv_obj_add_style(ui->select_language_btn_4, &style_select_language_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->select_language_btn_4_label = lv_label_create(ui->select_language_btn_4);
	lv_label_set_text(ui->select_language_btn_4_label, "4");
	lv_obj_set_style_text_color(ui->select_language_btn_4_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->select_language_btn_4_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->select_language_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->select_language_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes select_language_btn_5
	ui->select_language_btn_5 = lv_btn_create(ui->select_language_cont_1);
	lv_obj_set_pos(ui->select_language_btn_5, 17, 347);
	lv_obj_set_size(ui->select_language_btn_5, 218, 108);

	//Write style state: LV_STATE_DEFAULT for style_select_language_btn_5_main_main_default
	static lv_style_t style_select_language_btn_5_main_main_default;
	if (style_select_language_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_select_language_btn_5_main_main_default);
	else
		lv_style_init(&style_select_language_btn_5_main_main_default);
	lv_style_set_radius(&style_select_language_btn_5_main_main_default, 8);
	lv_style_set_bg_color(&style_select_language_btn_5_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_select_language_btn_5_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_select_language_btn_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_select_language_btn_5_main_main_default, 255);
	lv_style_set_shadow_color(&style_select_language_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_select_language_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_select_language_btn_5_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_select_language_btn_5_main_main_default, 0);
	lv_style_set_border_opa(&style_select_language_btn_5_main_main_default, 255);
	lv_obj_add_style(ui->select_language_btn_5, &style_select_language_btn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->select_language_btn_5_label = lv_label_create(ui->select_language_btn_5);
	lv_label_set_text(ui->select_language_btn_5_label, "5");
	lv_obj_set_style_text_color(ui->select_language_btn_5_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->select_language_btn_5_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->select_language_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->select_language_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes select_language_btn_6
	ui->select_language_btn_6 = lv_btn_create(ui->select_language_cont_1);
	lv_obj_set_pos(ui->select_language_btn_6, 247, 347);
	lv_obj_set_size(ui->select_language_btn_6, 218, 108);

	//Write style state: LV_STATE_DEFAULT for style_select_language_btn_6_main_main_default
	static lv_style_t style_select_language_btn_6_main_main_default;
	if (style_select_language_btn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_select_language_btn_6_main_main_default);
	else
		lv_style_init(&style_select_language_btn_6_main_main_default);
	lv_style_set_radius(&style_select_language_btn_6_main_main_default, 8);
	lv_style_set_bg_color(&style_select_language_btn_6_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_select_language_btn_6_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_select_language_btn_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_select_language_btn_6_main_main_default, 255);
	lv_style_set_shadow_color(&style_select_language_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_select_language_btn_6_main_main_default, 0);
	lv_style_set_border_color(&style_select_language_btn_6_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_select_language_btn_6_main_main_default, 0);
	lv_style_set_border_opa(&style_select_language_btn_6_main_main_default, 255);
	lv_obj_add_style(ui->select_language_btn_6, &style_select_language_btn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->select_language_btn_6_label = lv_label_create(ui->select_language_btn_6);
	lv_label_set_text(ui->select_language_btn_6_label, "6");
	lv_obj_set_style_text_color(ui->select_language_btn_6_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->select_language_btn_6_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->select_language_btn_6, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->select_language_btn_6_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes select_language_btn_7
	ui->select_language_btn_7 = lv_btn_create(ui->select_language_cont_1);
	lv_obj_set_pos(ui->select_language_btn_7, 17, 467);
	lv_obj_set_size(ui->select_language_btn_7, 218, 108);

	//Write style state: LV_STATE_DEFAULT for style_select_language_btn_7_main_main_default
	static lv_style_t style_select_language_btn_7_main_main_default;
	if (style_select_language_btn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_select_language_btn_7_main_main_default);
	else
		lv_style_init(&style_select_language_btn_7_main_main_default);
	lv_style_set_radius(&style_select_language_btn_7_main_main_default, 8);
	lv_style_set_bg_color(&style_select_language_btn_7_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_select_language_btn_7_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_select_language_btn_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_select_language_btn_7_main_main_default, 255);
	lv_style_set_shadow_color(&style_select_language_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_select_language_btn_7_main_main_default, 0);
	lv_style_set_border_color(&style_select_language_btn_7_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_select_language_btn_7_main_main_default, 0);
	lv_style_set_border_opa(&style_select_language_btn_7_main_main_default, 255);
	lv_obj_add_style(ui->select_language_btn_7, &style_select_language_btn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->select_language_btn_7_label = lv_label_create(ui->select_language_btn_7);
	lv_label_set_text(ui->select_language_btn_7_label, "7");
	lv_obj_set_style_text_color(ui->select_language_btn_7_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->select_language_btn_7_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->select_language_btn_7, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->select_language_btn_7_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes select_language_btn_8
	ui->select_language_btn_8 = lv_btn_create(ui->select_language_cont_1);
	lv_obj_set_pos(ui->select_language_btn_8, 247, 467);
	lv_obj_set_size(ui->select_language_btn_8, 218, 108);

	//Write style state: LV_STATE_DEFAULT for style_select_language_btn_8_main_main_default
	static lv_style_t style_select_language_btn_8_main_main_default;
	if (style_select_language_btn_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_select_language_btn_8_main_main_default);
	else
		lv_style_init(&style_select_language_btn_8_main_main_default);
	lv_style_set_radius(&style_select_language_btn_8_main_main_default, 8);
	lv_style_set_bg_color(&style_select_language_btn_8_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_select_language_btn_8_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_select_language_btn_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_select_language_btn_8_main_main_default, 255);
	lv_style_set_shadow_color(&style_select_language_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_select_language_btn_8_main_main_default, 0);
	lv_style_set_border_color(&style_select_language_btn_8_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_select_language_btn_8_main_main_default, 0);
	lv_style_set_border_opa(&style_select_language_btn_8_main_main_default, 255);
	lv_obj_add_style(ui->select_language_btn_8, &style_select_language_btn_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->select_language_btn_8_label = lv_label_create(ui->select_language_btn_8);
	lv_label_set_text(ui->select_language_btn_8_label, "8");
	lv_obj_set_style_text_color(ui->select_language_btn_8_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->select_language_btn_8_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->select_language_btn_8, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->select_language_btn_8_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes select_language_btn_9
	ui->select_language_btn_9 = lv_btn_create(ui->select_language_cont_1);
	lv_obj_set_pos(ui->select_language_btn_9, 17, 587);
	lv_obj_set_size(ui->select_language_btn_9, 218, 108);

	//Write style state: LV_STATE_DEFAULT for style_select_language_btn_9_main_main_default
	static lv_style_t style_select_language_btn_9_main_main_default;
	if (style_select_language_btn_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_select_language_btn_9_main_main_default);
	else
		lv_style_init(&style_select_language_btn_9_main_main_default);
	lv_style_set_radius(&style_select_language_btn_9_main_main_default, 8);
	lv_style_set_bg_color(&style_select_language_btn_9_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_select_language_btn_9_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_select_language_btn_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_select_language_btn_9_main_main_default, 255);
	lv_style_set_shadow_color(&style_select_language_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_select_language_btn_9_main_main_default, 0);
	lv_style_set_border_color(&style_select_language_btn_9_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_select_language_btn_9_main_main_default, 0);
	lv_style_set_border_opa(&style_select_language_btn_9_main_main_default, 255);
	lv_obj_add_style(ui->select_language_btn_9, &style_select_language_btn_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->select_language_btn_9_label = lv_label_create(ui->select_language_btn_9);
	lv_label_set_text(ui->select_language_btn_9_label, "9");
	lv_obj_set_style_text_color(ui->select_language_btn_9_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->select_language_btn_9_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->select_language_btn_9, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->select_language_btn_9_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_select_language(ui);
}
