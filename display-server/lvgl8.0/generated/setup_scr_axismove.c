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


void setup_scr_axismove(lv_ui *ui){

	//Write codes axismove_cont_1
	ui->axismove_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->axismove_cont_1, 0, 0);
	lv_obj_set_size(ui->axismove_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_axismove_cont_1_main_main_default
	static lv_style_t style_axismove_cont_1_main_main_default;
	if (style_axismove_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_cont_1_main_main_default);
	else
		lv_style_init(&style_axismove_cont_1_main_main_default);
	lv_style_set_radius(&style_axismove_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_axismove_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_axismove_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_axismove_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_axismove_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_axismove_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_axismove_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_axismove_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_axismove_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->axismove_cont_1, &style_axismove_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes axismove_label_2
	ui->axismove_label_2 = lv_label_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_label_2, 0, 47);
	lv_obj_set_size(ui->axismove_label_2, 480, 670);
	lv_label_set_text(ui->axismove_label_2, "");
	lv_label_set_long_mode(ui->axismove_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->axismove_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_axismove_label_2_main_main_default
	static lv_style_t style_axismove_label_2_main_main_default;
	if (style_axismove_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_label_2_main_main_default);
	else
		lv_style_init(&style_axismove_label_2_main_main_default);
	lv_style_set_radius(&style_axismove_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_label_2_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_axismove_label_2_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_axismove_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_axismove_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_axismove_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_axismove_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_axismove_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_axismove_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_axismove_label_2_main_main_default, 0);
	lv_obj_add_style(ui->axismove_label_2, &style_axismove_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes axismove_btn_2
	ui->axismove_btn_2 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_2, 12, 79);
	lv_obj_set_size(ui->axismove_btn_2, 450, 100);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_2_main_main_default
	static lv_style_t style_axismove_btn_2_main_main_default;
	if (style_axismove_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_2_main_main_default);
	else
		lv_style_init(&style_axismove_btn_2_main_main_default);
	lv_style_set_radius(&style_axismove_btn_2_main_main_default, 8);
	lv_style_set_bg_color(&style_axismove_btn_2_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_axismove_btn_2_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_axismove_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_axismove_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_2_main_main_default, lv_color_make(0x43, 0x45, 0x49));
	lv_style_set_border_width(&style_axismove_btn_2_main_main_default, 1);
	lv_style_set_border_opa(&style_axismove_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_2, &style_axismove_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_2_label = lv_label_create(ui->axismove_btn_2);
	lv_label_set_text(ui->axismove_btn_2_label, "");
	lv_obj_set_style_text_color(ui->axismove_btn_2_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_label_3
	ui->axismove_label_3 = lv_label_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_label_3, 37, 130);
	lv_obj_set_size(ui->axismove_label_3, 44, 24);
	lv_label_set_text(ui->axismove_label_3, "220");
	lv_label_set_long_mode(ui->axismove_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_add_flag(ui->axismove_label_3, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_style_text_align(ui->axismove_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_axismove_label_3_main_main_default
	static lv_style_t style_axismove_label_3_main_main_default;
	if (style_axismove_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_label_3_main_main_default);
	else
		lv_style_init(&style_axismove_label_3_main_main_default);
	lv_style_set_radius(&style_axismove_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_axismove_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_axismove_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_axismove_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_axismove_label_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_axismove_label_3_main_main_default, 1);
	lv_style_set_pad_left(&style_axismove_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_axismove_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_axismove_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_axismove_label_3_main_main_default, 0);
	lv_obj_add_style(ui->axismove_label_3, &style_axismove_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes axismove_label_8
	ui->axismove_label_8 = lv_label_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_label_8, 390, 312);
	lv_obj_set_size(ui->axismove_label_8, 80, 24);
	lv_label_set_text(ui->axismove_label_8, "进退料");
	lv_label_set_long_mode(ui->axismove_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->axismove_label_8, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_axismove_label_8_main_main_default
	static lv_style_t style_axismove_label_8_main_main_default;
	if (style_axismove_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_label_8_main_main_default);
	else
		lv_style_init(&style_axismove_label_8_main_main_default);
	lv_style_set_radius(&style_axismove_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_axismove_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_axismove_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_axismove_label_8_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_axismove_label_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_axismove_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_axismove_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_axismove_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_axismove_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_axismove_label_8_main_main_default, 0);
	lv_obj_add_style(ui->axismove_label_8, &style_axismove_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes axismove_label_4
	ui->axismove_label_4 = lv_label_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_label_4, 154, 130);
	lv_obj_set_size(ui->axismove_label_4, 44, 24);
	lv_label_set_text(ui->axismove_label_4, "60");
	lv_label_set_long_mode(ui->axismove_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_add_flag(ui->axismove_label_4, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_style_text_align(ui->axismove_label_4, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_axismove_label_4_main_main_default
	static lv_style_t style_axismove_label_4_main_main_default;
	if (style_axismove_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_label_4_main_main_default);
	else
		lv_style_init(&style_axismove_label_4_main_main_default);
	lv_style_set_radius(&style_axismove_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_axismove_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_axismove_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_axismove_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_axismove_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_axismove_label_4_main_main_default, 1);
	lv_style_set_pad_left(&style_axismove_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_axismove_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_axismove_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_axismove_label_4_main_main_default, 0);
	lv_obj_add_style(ui->axismove_label_4, &style_axismove_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes axismove_label_5
	ui->axismove_label_5 = lv_label_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_label_5, 262, 130);
	lv_obj_set_size(ui->axismove_label_5, 44, 24);
	lv_label_set_text(ui->axismove_label_5, "100");
    lv_obj_add_flag(ui->axismove_label_5, LV_OBJ_FLAG_CLICKABLE);
	lv_label_set_long_mode(ui->axismove_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->axismove_label_5, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_axismove_label_5_main_main_default
	static lv_style_t style_axismove_label_5_main_main_default;
	if (style_axismove_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_label_5_main_main_default);
	else
		lv_style_init(&style_axismove_label_5_main_main_default);
	lv_style_set_radius(&style_axismove_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_axismove_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_axismove_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_axismove_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_axismove_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_axismove_label_5_main_main_default, 1);
	lv_style_set_pad_left(&style_axismove_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_axismove_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_axismove_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_axismove_label_5_main_main_default, 0);
	lv_obj_add_style(ui->axismove_label_5, &style_axismove_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes axismove_label_6
	ui->axismove_label_6 = lv_label_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_label_6, 356, 136);
	lv_obj_set_size(ui->axismove_label_6, 100, 24);
	lv_label_set_text(ui->axismove_label_6, "模型风扇");
	lv_label_set_long_mode(ui->axismove_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->axismove_label_6, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_axismove_label_6_main_main_default
	static lv_style_t style_axismove_label_6_main_main_default;
	if (style_axismove_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_label_6_main_main_default);
	else
		lv_style_init(&style_axismove_label_6_main_main_default);
	lv_style_set_radius(&style_axismove_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_axismove_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_axismove_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_axismove_label_6_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_axismove_label_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_axismove_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_axismove_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_axismove_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_axismove_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_axismove_label_6_main_main_default, 0);
	lv_obj_add_flag(ui->axismove_label_6, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_style(ui->axismove_label_6, &style_axismove_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes axismove_label_7
	ui->axismove_label_7 = lv_label_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_label_7, 15, 217);
	lv_obj_set_size(ui->axismove_label_7, 456, 56);
	lv_label_set_text(ui->axismove_label_7, "");
	lv_label_set_long_mode(ui->axismove_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->axismove_label_7, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_axismove_label_7_main_main_default
	static lv_style_t style_axismove_label_7_main_main_default;
	if (style_axismove_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_label_7_main_main_default);
	else
		lv_style_init(&style_axismove_label_7_main_main_default);
	lv_style_set_radius(&style_axismove_label_7_main_main_default, 40);
	lv_style_set_bg_color(&style_axismove_label_7_main_main_default, lv_color_make(0x43, 0x45, 0x49));
	lv_style_set_bg_grad_color(&style_axismove_label_7_main_main_default, lv_color_make(0x43, 0x45, 0x49));
	lv_style_set_bg_grad_dir(&style_axismove_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_label_7_main_main_default, 255);
	lv_style_set_text_color(&style_axismove_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_axismove_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_axismove_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_axismove_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_axismove_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_axismove_label_7_main_main_default, 0);
	lv_obj_add_style(ui->axismove_label_7, &style_axismove_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes axismove_btn_3
	ui->axismove_btn_3 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_3, 15, 217);
	lv_obj_set_size(ui->axismove_btn_3, 152, 56);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_3_main_main_default
	static lv_style_t style_axismove_btn_3_main_main_default;
	if (style_axismove_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_3_main_main_default);
	else
		lv_style_init(&style_axismove_btn_3_main_main_default);
	lv_style_set_radius(&style_axismove_btn_3_main_main_default, 32);
	lv_style_set_bg_color(&style_axismove_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_3_main_main_default, 120);
	lv_style_set_shadow_color(&style_axismove_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_3_main_main_default, 2);
	lv_style_set_border_opa(&style_axismove_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_3, &style_axismove_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_3_label = lv_label_create(ui->axismove_btn_3);
	lv_label_set_text(ui->axismove_btn_3_label, "0.1mm");
	lv_obj_set_style_text_color(ui->axismove_btn_3_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->axismove_btn_3_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_btn_4
	ui->axismove_btn_4 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_4, 167, 217);
	lv_obj_set_size(ui->axismove_btn_4, 152, 56);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_4_main_main_default
	static lv_style_t style_axismove_btn_4_main_main_default;
	if (style_axismove_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_4_main_main_default);
	else
		lv_style_init(&style_axismove_btn_4_main_main_default);
	lv_style_set_radius(&style_axismove_btn_4_main_main_default, 32);
	lv_style_set_bg_color(&style_axismove_btn_4_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_4_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_4_main_main_default, 120);
	lv_style_set_shadow_color(&style_axismove_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_4_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_4_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_4_main_main_default, 2);
	lv_style_set_border_opa(&style_axismove_btn_4_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_4, &style_axismove_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_4_label = lv_label_create(ui->axismove_btn_4);
	lv_label_set_text(ui->axismove_btn_4_label, "1mm");
	lv_obj_set_style_text_color(ui->axismove_btn_4_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->axismove_btn_4_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_btn_5
	ui->axismove_btn_5 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_5, 319, 217);
	lv_obj_set_size(ui->axismove_btn_5, 152, 56);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_5_main_main_default
	static lv_style_t style_axismove_btn_5_main_main_default;
	if (style_axismove_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_5_main_main_default);
	else
		lv_style_init(&style_axismove_btn_5_main_main_default);
	lv_style_set_radius(&style_axismove_btn_5_main_main_default, 32);
	lv_style_set_bg_color(&style_axismove_btn_5_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_5_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_5_main_main_default, 120);
	lv_style_set_shadow_color(&style_axismove_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_5_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_5_main_main_default, 2);
	lv_style_set_border_opa(&style_axismove_btn_5_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_5, &style_axismove_btn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_5_label = lv_label_create(ui->axismove_btn_5);
	lv_label_set_text(ui->axismove_btn_5_label, "10mm");
	lv_obj_set_style_text_color(ui->axismove_btn_5_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->axismove_btn_5_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_img_6
	ui->axismove_img_6 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_6, 55, 97);
	lv_obj_set_size(ui->axismove_img_6, 28, 28);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_6_main_main_default
	static lv_style_t style_axismove_img_6_main_main_default;
	if (style_axismove_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_6_main_main_default);
	else
		lv_style_init(&style_axismove_img_6_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_6_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_6, &style_axismove_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_6,&_hotend_white_28x28);
	lv_img_set_pivot(ui->axismove_img_6, 0,0);
	lv_img_set_angle(ui->axismove_img_6, 0);

	//Write codes axismove_img_8
	ui->axismove_img_8 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_8, 164, 97);
	lv_obj_set_size(ui->axismove_img_8, 32, 26);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_8_main_main_default
	static lv_style_t style_axismove_img_8_main_main_default;
	if (style_axismove_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_8_main_main_default);
	else
		lv_style_init(&style_axismove_img_8_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_8_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_8, &style_axismove_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_8,&_bed_white_32x26);
	lv_img_set_pivot(ui->axismove_img_8, 0,0);
	lv_img_set_angle(ui->axismove_img_8, 0);

	//Write codes axismove_img_13
	ui->axismove_img_13 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_13, 274, 100);
	lv_obj_set_size(ui->axismove_img_13, 32, 21);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_13_main_main_default
	static lv_style_t style_axismove_img_13_main_main_default;
	if (style_axismove_img_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_13_main_main_default);
	else
		lv_style_init(&style_axismove_img_13_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_13_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_13_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_13, &style_axismove_img_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_13, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_13,&_speed_white_32x21);
	lv_img_set_pivot(ui->axismove_img_13, 0,0);
	lv_img_set_angle(ui->axismove_img_13, 0);

	//Write codes axismove_img_15
	ui->axismove_img_15 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_15, 387, 95);
	lv_obj_set_size(ui->axismove_img_15, 41, 41);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_15_main_main_default
	static lv_style_t style_axismove_img_15_main_main_default;
	if (style_axismove_img_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_15_main_main_default);
	else
		lv_style_init(&style_axismove_img_15_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_15_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_15_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_15, &style_axismove_img_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_15, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_15,&_fan_white_41x41);
	lv_img_set_pivot(ui->axismove_img_15, 0,0);
	lv_img_set_angle(ui->axismove_img_15, 0);

	//Write codes axismove_img_16
	ui->axismove_img_16 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_16, 16, 351);
	lv_obj_set_size(ui->axismove_img_16, 453, 304);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_16_main_main_default
	static lv_style_t style_axismove_img_16_main_main_default;
	if (style_axismove_img_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_16_main_main_default);
	else
		lv_style_init(&style_axismove_img_16_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_16_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_16_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_16, &style_axismove_img_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_16, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_16,&_Group_1524_453x304);
	lv_img_set_pivot(ui->axismove_img_16, 0,0);
	lv_img_set_angle(ui->axismove_img_16, 0);

	//Write codes axismove_btn_6
	ui->axismove_btn_6 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_6, 18, 411);
	lv_obj_set_size(ui->axismove_btn_6, 64, 81);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_6_main_main_default
	static lv_style_t style_axismove_btn_6_main_main_default;
	if (style_axismove_btn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_6_main_main_default);
	else
		lv_style_init(&style_axismove_btn_6_main_main_default);
	lv_style_set_radius(&style_axismove_btn_6_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_btn_6_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_6_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_6_main_main_default, 0);
	lv_style_set_shadow_color(&style_axismove_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_6_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_6_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_6_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_btn_6_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_6, &style_axismove_btn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_6_label = lv_label_create(ui->axismove_btn_6);
	lv_label_set_text(ui->axismove_btn_6_label, "");
	lv_obj_set_style_text_color(ui->axismove_btn_6_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_6, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_6_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_btn_7
	ui->axismove_btn_7 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_7, 18, 493);
	lv_obj_set_size(ui->axismove_btn_7, 64, 81);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_7_main_main_default
	static lv_style_t style_axismove_btn_7_main_main_default;
	if (style_axismove_btn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_7_main_main_default);
	else
		lv_style_init(&style_axismove_btn_7_main_main_default);
	lv_style_set_radius(&style_axismove_btn_7_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_btn_7_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_7_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_7_main_main_default, 0);
	lv_style_set_shadow_color(&style_axismove_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_7_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_7_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_7_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_btn_7_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_7, &style_axismove_btn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_7_label = lv_label_create(ui->axismove_btn_7);
	lv_label_set_text(ui->axismove_btn_7_label, "");
	lv_obj_set_style_text_color(ui->axismove_btn_7_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_7, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_7_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_btn_8
	ui->axismove_btn_8 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_8, 175, 367);
	lv_obj_set_size(ui->axismove_btn_8, 139, 46);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_8_main_main_default
	static lv_style_t style_axismove_btn_8_main_main_default;
	if (style_axismove_btn_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_8_main_main_default);
	else
		lv_style_init(&style_axismove_btn_8_main_main_default);
	lv_style_set_radius(&style_axismove_btn_8_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_btn_8_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_8_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_8_main_main_default, 0);
	lv_style_set_shadow_color(&style_axismove_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_8_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_8_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_8_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_btn_8_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_8, &style_axismove_btn_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_8_label = lv_label_create(ui->axismove_btn_8);
	lv_label_set_text(ui->axismove_btn_8_label, "");
	lv_obj_set_style_text_color(ui->axismove_btn_8_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_8, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_8_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_btn_9
	ui->axismove_btn_9 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_9, 171, 568);
	lv_obj_set_size(ui->axismove_btn_9, 139, 46);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_9_main_main_default
	static lv_style_t style_axismove_btn_9_main_main_default;
	if (style_axismove_btn_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_9_main_main_default);
	else
		lv_style_init(&style_axismove_btn_9_main_main_default);
	lv_style_set_radius(&style_axismove_btn_9_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_btn_9_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_9_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_9_main_main_default, 0);
	lv_style_set_shadow_color(&style_axismove_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_9_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_9_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_9_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_btn_9_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_9, &style_axismove_btn_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_9_label = lv_label_create(ui->axismove_btn_9);
	lv_label_set_text(ui->axismove_btn_9_label, "");
	lv_obj_set_style_text_color(ui->axismove_btn_9_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_9, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_9_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_btn_10
	ui->axismove_btn_10 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_10, 310, 419);
	lv_obj_set_size(ui->axismove_btn_10, 76, 137);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_10_main_main_default
	static lv_style_t style_axismove_btn_10_main_main_default;
	if (style_axismove_btn_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_10_main_main_default);
	else
		lv_style_init(&style_axismove_btn_10_main_main_default);
	lv_style_set_radius(&style_axismove_btn_10_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_btn_10_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_10_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_10_main_main_default, 0);
	lv_style_set_shadow_color(&style_axismove_btn_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_10_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_10_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_10_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_btn_10_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_10, &style_axismove_btn_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_10_label = lv_label_create(ui->axismove_btn_10);
	lv_label_set_text(ui->axismove_btn_10_label, "");
	lv_obj_set_style_text_color(ui->axismove_btn_10_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_10, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_10_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_btn_11
	ui->axismove_btn_11 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_11, 99, 422);
	lv_obj_set_size(ui->axismove_btn_11, 76, 137);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_11_main_main_default
	static lv_style_t style_axismove_btn_11_main_main_default;
	if (style_axismove_btn_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_11_main_main_default);
	else
		lv_style_init(&style_axismove_btn_11_main_main_default);
	lv_style_set_radius(&style_axismove_btn_11_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_btn_11_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_11_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_11_main_main_default, 0);
	lv_style_set_shadow_color(&style_axismove_btn_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_11_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_11_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_11_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_btn_11_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_11, &style_axismove_btn_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_11_label = lv_label_create(ui->axismove_btn_11);
	lv_label_set_text(ui->axismove_btn_11_label, "");
	lv_obj_set_style_text_color(ui->axismove_btn_11_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_11, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_11_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_btn_12
	ui->axismove_btn_12 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_12, 204, 456);
	lv_obj_set_size(ui->axismove_btn_12, 76, 76);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_12_main_main_default
	static lv_style_t style_axismove_btn_12_main_main_default;
	if (style_axismove_btn_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_12_main_main_default);
	else
		lv_style_init(&style_axismove_btn_12_main_main_default);
	lv_style_set_radius(&style_axismove_btn_12_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_btn_12_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_12_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_12_main_main_default, 0);
	lv_style_set_shadow_color(&style_axismove_btn_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_12_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_12_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_12_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_btn_12_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_12, &style_axismove_btn_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_12_label = lv_label_create(ui->axismove_btn_12);
	lv_label_set_text(ui->axismove_btn_12_label, "");
	lv_obj_set_style_text_color(ui->axismove_btn_12_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_12, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_12_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_btn_13
	ui->axismove_btn_13 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_13, 394, 342);
	lv_obj_set_size(ui->axismove_btn_13, 76, 76);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_13_main_main_default
	static lv_style_t style_axismove_btn_13_main_main_default;
	if (style_axismove_btn_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_13_main_main_default);
	else
		lv_style_init(&style_axismove_btn_13_main_main_default);
	lv_style_set_radius(&style_axismove_btn_13_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_btn_13_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_13_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_13_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_13_main_main_default, 0);
	lv_style_set_shadow_color(&style_axismove_btn_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_13_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_13_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_13_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_btn_13_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_13, &style_axismove_btn_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_13_label = lv_label_create(ui->axismove_btn_13);
	lv_label_set_text(ui->axismove_btn_13_label, "");
	lv_obj_set_style_text_color(ui->axismove_btn_13_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_13, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_13_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_btn_14
	ui->axismove_btn_14 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_14, 393, 578);
	lv_obj_set_size(ui->axismove_btn_14, 76, 76);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_14_main_main_default
	static lv_style_t style_axismove_btn_14_main_main_default;
	if (style_axismove_btn_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_14_main_main_default);
	else
		lv_style_init(&style_axismove_btn_14_main_main_default);
	lv_style_set_radius(&style_axismove_btn_14_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_btn_14_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_axismove_btn_14_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_axismove_btn_14_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_14_main_main_default, 0);
	lv_style_set_shadow_color(&style_axismove_btn_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_14_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_14_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_axismove_btn_14_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_btn_14_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_14, &style_axismove_btn_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_14_label = lv_label_create(ui->axismove_btn_14);
	lv_label_set_text(ui->axismove_btn_14_label, "");
	lv_obj_set_style_text_color(ui->axismove_btn_14_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_14, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_14_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_img_9
	ui->axismove_img_9 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_9, 124, 91);
	lv_obj_set_size(ui->axismove_img_9, 1, 80);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_9_main_main_default
	static lv_style_t style_axismove_img_9_main_main_default;
	if (style_axismove_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_9_main_main_default);
	else
		lv_style_init(&style_axismove_img_9_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_9_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_9, &style_axismove_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_9,&_Rectangle_1357_1x80);
	lv_img_set_pivot(ui->axismove_img_9, 0,0);
	lv_img_set_angle(ui->axismove_img_9, 0);

	//Write codes axismove_img_11
	ui->axismove_img_11 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_11, 234, 91);
	lv_obj_set_size(ui->axismove_img_11, 1, 80);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_11_main_main_default
	static lv_style_t style_axismove_img_11_main_main_default;
	if (style_axismove_img_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_11_main_main_default);
	else
		lv_style_init(&style_axismove_img_11_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_11_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_11_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_11, &style_axismove_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_11,&_Rectangle_1357_1x80);
	lv_img_set_pivot(ui->axismove_img_11, 0,0);
	lv_img_set_angle(ui->axismove_img_11, 0);

	//Write codes axismove_img_12
	ui->axismove_img_12 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_12, 344, 91);
	lv_obj_set_size(ui->axismove_img_12, 1, 80);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_12_main_main_default
	static lv_style_t style_axismove_img_12_main_main_default;
	if (style_axismove_img_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_12_main_main_default);
	else
		lv_style_init(&style_axismove_img_12_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_12_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_12_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_12, &style_axismove_img_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_12, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_12,&_Rectangle_1357_1x80);
	lv_img_set_pivot(ui->axismove_img_12, 0,0);
	lv_img_set_angle(ui->axismove_img_12, 0);

	//Write codes axismove_img_7
	ui->axismove_img_7 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_7, 85, 136);
	lv_obj_set_size(ui->axismove_img_7, 18, 15);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_7_main_main_default
	static lv_style_t style_axismove_img_7_main_main_default;
	if (style_axismove_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_7_main_main_default);
	else
		lv_style_init(&style_axismove_img_7_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_7_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_7, &style_axismove_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_7,&_temp_18x15);
	lv_img_set_pivot(ui->axismove_img_7, 0,0);
	lv_img_set_angle(ui->axismove_img_7, 0);

	//Write codes axismove_img_10
	ui->axismove_img_10 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_10, 189, 136);
	lv_obj_set_size(ui->axismove_img_10, 18, 15);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_10_main_main_default
	static lv_style_t style_axismove_img_10_main_main_default;
	if (style_axismove_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_10_main_main_default);
	else
		lv_style_init(&style_axismove_img_10_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_10_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_10, &style_axismove_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_10,&_temp_18x15);
	lv_img_set_pivot(ui->axismove_img_10, 0,0);
	lv_img_set_angle(ui->axismove_img_10, 0);

	//Write codes axismove_img_14
	ui->axismove_img_14 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_14, 307, 136);
	lv_obj_set_size(ui->axismove_img_14, 18, 15);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_14_main_main_default
	static lv_style_t style_axismove_img_14_main_main_default;
	if (style_axismove_img_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_14_main_main_default);
	else
		lv_style_init(&style_axismove_img_14_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_14_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_14_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_14, &style_axismove_img_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_14, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_14,&_percent_17x15);
	lv_img_set_pivot(ui->axismove_img_14, 0,0);
	lv_img_set_angle(ui->axismove_img_14, 0);

	//Write codes axismove_btn_1
	ui->axismove_btn_1 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_1, 25, 5);
	lv_obj_set_size(ui->axismove_btn_1, 194, 46);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_1_main_main_default
	static lv_style_t style_axismove_btn_1_main_main_default;
	if (style_axismove_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_1_main_main_default);
	else
		lv_style_init(&style_axismove_btn_1_main_main_default);
	lv_style_set_radius(&style_axismove_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_btn_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_axismove_btn_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_axismove_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_1_main_main_default, 255);
	lv_style_set_shadow_color(&style_axismove_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_axismove_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_1, &style_axismove_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_1_label = lv_label_create(ui->axismove_btn_1);
	lv_label_set_text(ui->axismove_btn_1_label, "轴移动/温度");
	lv_obj_set_style_text_color(ui->axismove_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->axismove_btn_1_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_btn_15
	ui->axismove_btn_15 = lv_btn_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_btn_15, 225, 5);
	lv_obj_set_size(ui->axismove_btn_15, 150, 42);

	//Write style state: LV_STATE_DEFAULT for style_axismove_btn_15_main_main_default
	static lv_style_t style_axismove_btn_15_main_main_default;
	if (style_axismove_btn_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_btn_15_main_main_default);
	else
		lv_style_init(&style_axismove_btn_15_main_main_default);
	lv_style_set_radius(&style_axismove_btn_15_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_btn_15_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_axismove_btn_15_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_axismove_btn_15_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_btn_15_main_main_default, 255);
	lv_style_set_shadow_color(&style_axismove_btn_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_axismove_btn_15_main_main_default, 0);
	lv_style_set_border_color(&style_axismove_btn_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_axismove_btn_15_main_main_default, 0);
	lv_style_set_border_opa(&style_axismove_btn_15_main_main_default, 255);
	lv_obj_add_style(ui->axismove_btn_15, &style_axismove_btn_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->axismove_btn_15_label = lv_label_create(ui->axismove_btn_15);
	lv_label_set_text(ui->axismove_btn_15_label, "调整");
	lv_obj_set_style_text_color(ui->axismove_btn_15_label, lv_color_make(0x91, 0x93, 0x97), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->axismove_btn_15_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->axismove_btn_15, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->axismove_btn_15_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes axismove_label_1
	ui->axismove_label_1 = lv_label_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_label_1, 0, 720);
	lv_obj_set_size(ui->axismove_label_1, 480, 80);
	lv_label_set_text(ui->axismove_label_1, "");
	lv_label_set_long_mode(ui->axismove_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->axismove_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_axismove_label_1_main_main_default
	static lv_style_t style_axismove_label_1_main_main_default;
	if (style_axismove_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_label_1_main_main_default);
	else
		lv_style_init(&style_axismove_label_1_main_main_default);
	lv_style_set_radius(&style_axismove_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_axismove_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_axismove_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_axismove_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_axismove_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_axismove_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_axismove_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_axismove_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_axismove_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_axismove_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_axismove_label_1_main_main_default, 0);
	lv_obj_add_style(ui->axismove_label_1, &style_axismove_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes axismove_img_1
	ui->axismove_img_1 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_1, 30, 742);
	lv_obj_set_size(ui->axismove_img_1, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_1_main_main_default
	static lv_style_t style_axismove_img_1_main_main_default;
	if (style_axismove_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_1_main_main_default);
	else
		lv_style_init(&style_axismove_img_1_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_1_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_1, &style_axismove_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_1,&_home_48x48);
	lv_img_set_pivot(ui->axismove_img_1, 0,0);
	lv_img_set_angle(ui->axismove_img_1, 0);

	//Write codes axismove_img_2
	ui->axismove_img_2 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_2, 128, 742);
	lv_obj_set_size(ui->axismove_img_2, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_2_main_main_default
	static lv_style_t style_axismove_img_2_main_main_default;
	if (style_axismove_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_2_main_main_default);
	else
		lv_style_init(&style_axismove_img_2_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_2_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_2, &style_axismove_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_2,&_prepare_blue_48x48);
	lv_img_set_pivot(ui->axismove_img_2, 0,0);
	lv_img_set_angle(ui->axismove_img_2, 0);

	//Write codes axismove_img_3
	ui->axismove_img_3 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_3, 224, 742);
	lv_obj_set_size(ui->axismove_img_3, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_3_main_main_default
	static lv_style_t style_axismove_img_3_main_main_default;
	if (style_axismove_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_3_main_main_default);
	else
		lv_style_init(&style_axismove_img_3_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_3_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_3, &style_axismove_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_3,&_files_48x48);
	lv_img_set_pivot(ui->axismove_img_3, 0,0);
	lv_img_set_angle(ui->axismove_img_3, 0);

	//Write codes axismove_img_4
	ui->axismove_img_4 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_4, 318, 742);
	lv_obj_set_size(ui->axismove_img_4, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_4_main_main_default
	static lv_style_t style_axismove_img_4_main_main_default;
	if (style_axismove_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_4_main_main_default);
	else
		lv_style_init(&style_axismove_img_4_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_4_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_4, &style_axismove_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_4,&_seting_48x48);
	lv_img_set_pivot(ui->axismove_img_4, 0,0);
	lv_img_set_angle(ui->axismove_img_4, 0);

	//Write codes axismove_img_5
	ui->axismove_img_5 = lv_img_create(ui->axismove_cont_1);
	lv_obj_set_pos(ui->axismove_img_5, 414, 742);
	lv_obj_set_size(ui->axismove_img_5, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_axismove_img_5_main_main_default
	static lv_style_t style_axismove_img_5_main_main_default;
	if (style_axismove_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_axismove_img_5_main_main_default);
	else
		lv_style_init(&style_axismove_img_5_main_main_default);
	lv_style_set_img_recolor(&style_axismove_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_axismove_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_axismove_img_5_main_main_default, 255);
	lv_obj_add_style(ui->axismove_img_5, &style_axismove_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->axismove_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->axismove_img_5,&_FAQ_48x48);
	lv_img_set_pivot(ui->axismove_img_5, 0,0);
	lv_img_set_angle(ui->axismove_img_5, 0);

	//Init events for screen
	events_init_axismove(ui);
}
