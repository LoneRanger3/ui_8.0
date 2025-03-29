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


void setup_scr_about_device(lv_ui *ui){

	//Write codes about_device_cont_1
	ui->about_device_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->about_device_cont_1, 0, 0);
	lv_obj_set_size(ui->about_device_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_about_device_cont_1_main_main_default
	static lv_style_t style_about_device_cont_1_main_main_default;
	if (style_about_device_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_cont_1_main_main_default);
	else
		lv_style_init(&style_about_device_cont_1_main_main_default);
	lv_style_set_radius(&style_about_device_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_about_device_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_about_device_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_about_device_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_about_device_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_about_device_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_about_device_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->about_device_cont_1, &style_about_device_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_3
	ui->about_device_label_3 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_3, 10, 58);
	lv_obj_set_size(ui->about_device_label_3, 460, 727);
	lv_label_set_text(ui->about_device_label_3, "");
	lv_label_set_long_mode(ui->about_device_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_3_main_main_default
	static lv_style_t style_about_device_label_3_main_main_default;
	if (style_about_device_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_3_main_main_default);
	else
		lv_style_init(&style_about_device_label_3_main_main_default);
	lv_style_set_radius(&style_about_device_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_about_device_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_about_device_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_about_device_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_about_device_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_about_device_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_3_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_3, &style_about_device_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_4
	ui->about_device_label_4 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_4, 26, 76);
	lv_obj_set_size(ui->about_device_label_4, 427, 344);
	lv_label_set_text(ui->about_device_label_4, "");
	lv_label_set_long_mode(ui->about_device_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_4, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_4_main_main_default
	static lv_style_t style_about_device_label_4_main_main_default;
	if (style_about_device_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_4_main_main_default);
	else
		lv_style_init(&style_about_device_label_4_main_main_default);
	lv_style_set_radius(&style_about_device_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_4_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_4_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_4_main_main_default, 255);
	lv_style_set_text_color(&style_about_device_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_about_device_label_4_main_main_default, 2);
	lv_style_set_pad_left(&style_about_device_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_4_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_4, &style_about_device_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_5
	ui->about_device_label_5 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_5, 90, 340);
	lv_obj_set_size(ui->about_device_label_5, 300, 32);
	lv_label_set_text(ui->about_device_label_5, "CR-10 H1");
	lv_label_set_long_mode(ui->about_device_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_5, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_5_main_main_default
	static lv_style_t style_about_device_label_5_main_main_default;
	if (style_about_device_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_5_main_main_default);
	else
		lv_style_init(&style_about_device_label_5_main_main_default);
	lv_style_set_radius(&style_about_device_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_5_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_5_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_5_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_about_device_label_5_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_about_device_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_5_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_5, &style_about_device_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_6
	ui->about_device_label_6 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_6, 90, 370);
	lv_obj_set_size(ui->about_device_label_6, 300, 32);
	lv_label_set_text(ui->about_device_label_6, "200X200X200mm");
	lv_label_set_long_mode(ui->about_device_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_6, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_6_main_main_default
	static lv_style_t style_about_device_label_6_main_main_default;
	if (style_about_device_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_6_main_main_default);
	else
		lv_style_init(&style_about_device_label_6_main_main_default);
	lv_style_set_radius(&style_about_device_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_6_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_6_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_6_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_about_device_label_6_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_about_device_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_6_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_6, &style_about_device_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_7
	ui->about_device_label_7 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_7, 21, 440);
	lv_obj_set_size(ui->about_device_label_7, 190, 24);
	lv_label_set_text(ui->about_device_label_7, "设备名称");
	lv_label_set_long_mode(ui->about_device_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_7_main_main_default
	static lv_style_t style_about_device_label_7_main_main_default;
	if (style_about_device_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_7_main_main_default);
	else
		lv_style_init(&style_about_device_label_7_main_main_default);
	lv_style_set_radius(&style_about_device_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_7_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_7_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_7_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_about_device_label_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_7_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_7, &style_about_device_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_8
	ui->about_device_label_8 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_8, 21, 484);
	lv_obj_set_size(ui->about_device_label_8, 190, 24);
	lv_label_set_text(ui->about_device_label_8, "机器型号");
	lv_label_set_long_mode(ui->about_device_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_8_main_main_default
	static lv_style_t style_about_device_label_8_main_main_default;
	if (style_about_device_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_8_main_main_default);
	else
		lv_style_init(&style_about_device_label_8_main_main_default);
	lv_style_set_radius(&style_about_device_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_8_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_8_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_8_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_about_device_label_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_8_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_8, &style_about_device_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_9
	ui->about_device_label_9 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_9, 21, 528);
	lv_obj_set_size(ui->about_device_label_9, 190, 24);
	lv_label_set_text(ui->about_device_label_9, "固件版本");
	lv_label_set_long_mode(ui->about_device_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_9, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_9_main_main_default
	static lv_style_t style_about_device_label_9_main_main_default;
	if (style_about_device_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_9_main_main_default);
	else
		lv_style_init(&style_about_device_label_9_main_main_default);
	lv_style_set_radius(&style_about_device_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_9_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_9_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_9_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_about_device_label_9_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_9_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_9, &style_about_device_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_10
	ui->about_device_label_10 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_10, 21, 572);
	lv_obj_set_size(ui->about_device_label_10, 190, 24);
	lv_label_set_text(ui->about_device_label_10, "Mac地址");
	lv_label_set_long_mode(ui->about_device_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_10, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_10_main_main_default
	static lv_style_t style_about_device_label_10_main_main_default;
	if (style_about_device_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_10_main_main_default);
	else
		lv_style_init(&style_about_device_label_10_main_main_default);
	lv_style_set_radius(&style_about_device_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_10_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_10_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_10_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_about_device_label_10_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_10_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_10, &style_about_device_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_11
	ui->about_device_label_11 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_11, 21, 616);
	lv_obj_set_size(ui->about_device_label_11, 190, 24);
	lv_label_set_text(ui->about_device_label_11, "累计打印");
	lv_label_set_long_mode(ui->about_device_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_11, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_11_main_main_default
	static lv_style_t style_about_device_label_11_main_main_default;
	if (style_about_device_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_11_main_main_default);
	else
		lv_style_init(&style_about_device_label_11_main_main_default);
	lv_style_set_radius(&style_about_device_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_11_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_11_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_11_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_about_device_label_11_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_11_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_11_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_11, &style_about_device_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_12
	ui->about_device_label_12 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_12, 21, 660);
	lv_obj_set_size(ui->about_device_label_12, 190, 24);
	lv_label_set_text(ui->about_device_label_12, "存储空间");
	lv_label_set_long_mode(ui->about_device_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_12, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_12_main_main_default
	static lv_style_t style_about_device_label_12_main_main_default;
	if (style_about_device_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_12_main_main_default);
	else
		lv_style_init(&style_about_device_label_12_main_main_default);
	lv_style_set_radius(&style_about_device_label_12_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_12_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_12_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_12_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_12_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_about_device_label_12_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_12_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_12_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_12, &style_about_device_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_13
	ui->about_device_label_13 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_13, 266, 440);
	lv_obj_set_size(ui->about_device_label_13, 190, 24);
	lv_label_set_text(ui->about_device_label_13, "");
	lv_label_set_long_mode(ui->about_device_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_13, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_13_main_main_default
	static lv_style_t style_about_device_label_13_main_main_default;
	if (style_about_device_label_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_13_main_main_default);
	else
		lv_style_init(&style_about_device_label_13_main_main_default);
	lv_style_set_radius(&style_about_device_label_13_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_13_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_13_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_13_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_13_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_13_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_about_device_label_13_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_13_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_13_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_13_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_13_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_13_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_13, &style_about_device_label_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_14
	ui->about_device_label_14 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_14, 266, 484);
	lv_obj_set_size(ui->about_device_label_14, 190, 24);
	lv_label_set_text(ui->about_device_label_14, "");
	lv_label_set_long_mode(ui->about_device_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_14, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_14_main_main_default
	static lv_style_t style_about_device_label_14_main_main_default;
	if (style_about_device_label_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_14_main_main_default);
	else
		lv_style_init(&style_about_device_label_14_main_main_default);
	lv_style_set_radius(&style_about_device_label_14_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_14_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_14_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_14_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_14_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_14_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_about_device_label_14_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_14_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_14_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_14_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_14_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_14_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_14, &style_about_device_label_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_15
	ui->about_device_label_15 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_15, 266, 528);
	lv_obj_set_size(ui->about_device_label_15, 190, 24);
	lv_label_set_text(ui->about_device_label_15, "");
	lv_label_set_long_mode(ui->about_device_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_15, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_15_main_main_default
	static lv_style_t style_about_device_label_15_main_main_default;
	if (style_about_device_label_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_15_main_main_default);
	else
		lv_style_init(&style_about_device_label_15_main_main_default);
	lv_style_set_radius(&style_about_device_label_15_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_15_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_15_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_15_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_15_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_15_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_about_device_label_15_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_15_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_15_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_15_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_15_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_15_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_15, &style_about_device_label_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_16
	ui->about_device_label_16 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_16, 200, 572);
	lv_obj_set_size(ui->about_device_label_16, 256, 24);
	lv_label_set_text(ui->about_device_label_16, "");
	lv_label_set_long_mode(ui->about_device_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_16, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_16_main_main_default
	static lv_style_t style_about_device_label_16_main_main_default;
	if (style_about_device_label_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_16_main_main_default);
	else
		lv_style_init(&style_about_device_label_16_main_main_default);
	lv_style_set_radius(&style_about_device_label_16_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_16_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_16_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_16_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_16_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_16_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_about_device_label_16_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_16_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_16_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_16_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_16_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_16_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_16, &style_about_device_label_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_17
	ui->about_device_label_17 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_17, 266, 616);
	lv_obj_set_size(ui->about_device_label_17, 190, 24);
	lv_label_set_text(ui->about_device_label_17, "");
	lv_label_set_long_mode(ui->about_device_label_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_17, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_17_main_main_default
	static lv_style_t style_about_device_label_17_main_main_default;
	if (style_about_device_label_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_17_main_main_default);
	else
		lv_style_init(&style_about_device_label_17_main_main_default);
	lv_style_set_radius(&style_about_device_label_17_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_17_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_17_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_17_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_17_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_17_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_about_device_label_17_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_17_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_17_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_17_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_17_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_17_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_17, &style_about_device_label_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_label_18
	ui->about_device_label_18 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_18, 266, 660);
	lv_obj_set_size(ui->about_device_label_18, 190, 24);
	lv_label_set_text(ui->about_device_label_18, "");
	lv_label_set_long_mode(ui->about_device_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_18, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_18_main_main_default
	static lv_style_t style_about_device_label_18_main_main_default;
	if (style_about_device_label_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_18_main_main_default);
	else
		lv_style_init(&style_about_device_label_18_main_main_default);
	lv_style_set_radius(&style_about_device_label_18_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_18_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_about_device_label_18_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_about_device_label_18_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_18_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_18_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_about_device_label_18_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_about_device_label_18_main_main_default, 0);
	lv_style_set_pad_left(&style_about_device_label_18_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_18_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_18_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_18_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_18, &style_about_device_label_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_img_2
	ui->about_device_img_2 = lv_img_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_img_2, 129, 89);
	lv_obj_set_size(ui->about_device_img_2, 222, 249);

	//Write style state: LV_STATE_DEFAULT for style_about_device_img_2_main_main_default
	static lv_style_t style_about_device_img_2_main_main_default;
	if (style_about_device_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_img_2_main_main_default);
	else
		lv_style_init(&style_about_device_img_2_main_main_default);
	lv_style_set_img_recolor(&style_about_device_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_about_device_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_about_device_img_2_main_main_default, 255);
	lv_obj_add_style(ui->about_device_img_2, &style_about_device_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->about_device_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->about_device_img_2,&_machine_222x249);
	lv_img_set_pivot(ui->about_device_img_2, 0,0);
	lv_img_set_angle(ui->about_device_img_2, 0);

	//Write codes about_device_label_1
	ui->about_device_label_1 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_1, 0, 0);
	lv_obj_set_size(ui->about_device_label_1, 480, 53);
	lv_label_set_text(ui->about_device_label_1, "");
	lv_label_set_long_mode(ui->about_device_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_1_main_main_default
	static lv_style_t style_about_device_label_1_main_main_default;
	if (style_about_device_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_1_main_main_default);
	else
		lv_style_init(&style_about_device_label_1_main_main_default);
	lv_style_set_radius(&style_about_device_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_about_device_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_about_device_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_about_device_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_about_device_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_about_device_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_1_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_1, &style_about_device_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_device_img_1
	ui->about_device_img_1 = lv_img_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_img_1, 21, 17);
	lv_obj_set_size(ui->about_device_img_1, 36, 24);

	//Write style state: LV_STATE_DEFAULT for style_about_device_img_1_main_main_default
	static lv_style_t style_about_device_img_1_main_main_default;
	if (style_about_device_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_img_1_main_main_default);
	else
		lv_style_init(&style_about_device_img_1_main_main_default);
	lv_style_set_img_recolor(&style_about_device_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_about_device_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_about_device_img_1_main_main_default, 255);
	lv_obj_add_style(ui->about_device_img_1, &style_about_device_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->about_device_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->about_device_img_1,&_back_36x24);
	lv_img_set_pivot(ui->about_device_img_1, 0,0);
	lv_img_set_angle(ui->about_device_img_1, 0);

	//Write codes about_device_btn_1
	ui->about_device_btn_1 = lv_btn_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_btn_1, 0, 0);
	lv_obj_set_size(ui->about_device_btn_1, 85, 50);

	//Write style state: LV_STATE_DEFAULT for style_about_device_btn_1_main_main_default
	static lv_style_t style_about_device_btn_1_main_main_default;
	if (style_about_device_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_btn_1_main_main_default);
	else
		lv_style_init(&style_about_device_btn_1_main_main_default);
	lv_style_set_radius(&style_about_device_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_about_device_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_about_device_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_about_device_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_about_device_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_about_device_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_about_device_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_about_device_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->about_device_btn_1, &style_about_device_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->about_device_btn_1_label = lv_label_create(ui->about_device_btn_1);
	lv_label_set_text(ui->about_device_btn_1_label, "");
	lv_obj_set_style_text_color(ui->about_device_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->about_device_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->about_device_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes about_device_label_2
	ui->about_device_label_2 = lv_label_create(ui->about_device_cont_1);
	lv_obj_set_pos(ui->about_device_label_2, 90, 11);
	lv_obj_set_size(ui->about_device_label_2, 300, 32);
	lv_label_set_text(ui->about_device_label_2, "关于本机");
	lv_label_set_long_mode(ui->about_device_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->about_device_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_about_device_label_2_main_main_default
	static lv_style_t style_about_device_label_2_main_main_default;
	if (style_about_device_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_device_label_2_main_main_default);
	else
		lv_style_init(&style_about_device_label_2_main_main_default);
	lv_style_set_radius(&style_about_device_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_about_device_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_about_device_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_about_device_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_about_device_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_about_device_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_about_device_label_2_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_about_device_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_about_device_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_about_device_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_about_device_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_about_device_label_2_main_main_default, 0);
	lv_obj_add_style(ui->about_device_label_2, &style_about_device_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_about_device(ui);
}
