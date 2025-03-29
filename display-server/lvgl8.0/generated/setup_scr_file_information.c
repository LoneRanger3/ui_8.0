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


void setup_scr_file_information(lv_ui *ui){

	//Write codes file_information_cont_1
	ui->file_information_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->file_information_cont_1, 0, 0);
	lv_obj_set_size(ui->file_information_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_file_information_cont_1_main_main_default
	static lv_style_t style_file_information_cont_1_main_main_default;
	if (style_file_information_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_cont_1_main_main_default);
	else
		lv_style_init(&style_file_information_cont_1_main_main_default);
	lv_style_set_radius(&style_file_information_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_file_information_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_file_information_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_file_information_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_file_information_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_file_information_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_file_information_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_file_information_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_file_information_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_information_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->file_information_cont_1, &style_file_information_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_label_1
	ui->file_information_label_1 = lv_label_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_label_1, 0, 0);
	lv_obj_set_size(ui->file_information_label_1, 480, 53);
	lv_label_set_text(ui->file_information_label_1, "");
	lv_label_set_long_mode(ui->file_information_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_information_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_information_label_1_main_main_default
	static lv_style_t style_file_information_label_1_main_main_default;
	if (style_file_information_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_label_1_main_main_default);
	else
		lv_style_init(&style_file_information_label_1_main_main_default);
	lv_style_set_radius(&style_file_information_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_file_information_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_file_information_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_file_information_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_information_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_file_information_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_file_information_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_file_information_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_information_label_1_main_main_default, 0);
	lv_obj_add_style(ui->file_information_label_1, &style_file_information_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_label_3
	ui->file_information_label_3 = lv_label_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_label_3, 9, 64);
	lv_obj_set_size(ui->file_information_label_3, 460, 727);
	lv_label_set_text(ui->file_information_label_3, "");
	lv_label_set_long_mode(ui->file_information_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_information_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_information_label_3_main_main_default
	static lv_style_t style_file_information_label_3_main_main_default;
	if (style_file_information_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_label_3_main_main_default);
	else
		lv_style_init(&style_file_information_label_3_main_main_default);
	lv_style_set_radius(&style_file_information_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_file_information_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_file_information_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_file_information_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_information_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_file_information_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_file_information_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_file_information_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_information_label_3_main_main_default, 0);
	lv_obj_add_style(ui->file_information_label_3, &style_file_information_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_btn_2
	ui->file_information_btn_2 = lv_btn_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_btn_2, 27, 700);
	lv_obj_set_size(ui->file_information_btn_2, 426, 65);

	//Write style state: LV_STATE_DEFAULT for style_file_information_btn_2_main_main_default
	static lv_style_t style_file_information_btn_2_main_main_default;
	if (style_file_information_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_btn_2_main_main_default);
	else
		lv_style_init(&style_file_information_btn_2_main_main_default);
	lv_style_set_radius(&style_file_information_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_file_information_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_file_information_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_file_information_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_file_information_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_information_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_file_information_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_file_information_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_file_information_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->file_information_btn_2, &style_file_information_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_information_btn_2_label = lv_label_create(ui->file_information_btn_2);
	lv_label_set_text(ui->file_information_btn_2_label, "打印");
	lv_obj_set_style_text_color(ui->file_information_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->file_information_btn_2_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_information_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_information_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_information_label_4
	ui->file_information_label_4 = lv_label_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_label_4, 26, 76);
	lv_obj_set_size(ui->file_information_label_4, 427, 344);
	lv_label_set_text(ui->file_information_label_4, "");
	lv_label_set_long_mode(ui->file_information_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_information_label_4, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_information_label_4_main_main_default
	static lv_style_t style_file_information_label_4_main_main_default;
	if (style_file_information_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_label_4_main_main_default);
	else
		lv_style_init(&style_file_information_label_4_main_main_default);
	lv_style_set_radius(&style_file_information_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_label_4_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_information_label_4_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_information_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_label_4_main_main_default, 255);
	lv_style_set_text_color(&style_file_information_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_information_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_file_information_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_file_information_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_file_information_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_information_label_4_main_main_default, 0);
	lv_obj_add_style(ui->file_information_label_4, &style_file_information_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_img_2
	ui->file_information_img_2 = lv_img_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_img_2, 90, 93);
	lv_obj_set_size(ui->file_information_img_2, 300, 300);

	//Write style state: LV_STATE_DEFAULT for style_file_information_img_2_main_main_default
	static lv_style_t style_file_information_img_2_main_main_default;
	if (style_file_information_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_img_2_main_main_default);
	else
		lv_style_init(&style_file_information_img_2_main_main_default);
	lv_style_set_img_recolor(&style_file_information_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_information_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_file_information_img_2_main_main_default, 255);
	lv_obj_add_style(ui->file_information_img_2, &style_file_information_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_img_3
	ui->file_information_img_3 = lv_img_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_img_3, 28, 507);
	lv_obj_set_size(ui->file_information_img_3, 18, 18);

	//Write style state: LV_STATE_DEFAULT for style_file_information_img_3_main_main_default
	static lv_style_t style_file_information_img_3_main_main_default;
	if (style_file_information_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_img_3_main_main_default);
	else
		lv_style_init(&style_file_information_img_3_main_main_default);
	lv_style_set_img_recolor(&style_file_information_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_information_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_file_information_img_3_main_main_default, 255);
	lv_obj_add_style(ui->file_information_img_3, &style_file_information_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_information_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_information_img_3,&_time_18x18);
	lv_img_set_pivot(ui->file_information_img_3, 0,0);
	lv_img_set_angle(ui->file_information_img_3, 0);

	//Write codes file_information_img_4
	ui->file_information_img_4 = lv_img_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_img_4, 173, 507);
	lv_obj_set_size(ui->file_information_img_4, 16, 16);

	//Write style state: LV_STATE_DEFAULT for style_file_information_img_4_main_main_default
	static lv_style_t style_file_information_img_4_main_main_default;
	if (style_file_information_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_img_4_main_main_default);
	else
		lv_style_init(&style_file_information_img_4_main_main_default);
	lv_style_set_img_recolor(&style_file_information_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_information_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_file_information_img_4_main_main_default, 255);
	lv_obj_add_style(ui->file_information_img_4, &style_file_information_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_information_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_information_img_4,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_information_img_4, 0,0);
	lv_img_set_angle(ui->file_information_img_4, 0);

	//Write codes file_information_img_1
	ui->file_information_img_1 = lv_img_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_img_1, 21, 17);
	lv_obj_set_size(ui->file_information_img_1, 36, 24);

	//Write style state: LV_STATE_DEFAULT for style_file_information_img_1_main_main_default
	static lv_style_t style_file_information_img_1_main_main_default;
	if (style_file_information_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_img_1_main_main_default);
	else
		lv_style_init(&style_file_information_img_1_main_main_default);
	lv_style_set_img_recolor(&style_file_information_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_information_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_file_information_img_1_main_main_default, 255);
	lv_obj_add_style(ui->file_information_img_1, &style_file_information_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_information_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_information_img_1,&_back_36x24);
	lv_img_set_pivot(ui->file_information_img_1, 0,0);
	lv_img_set_angle(ui->file_information_img_1, 0);

	//Write codes file_information_btn_1
	ui->file_information_btn_1 = lv_btn_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_btn_1, 0, 0);
	lv_obj_set_size(ui->file_information_btn_1, 85, 50);

	//Write style state: LV_STATE_DEFAULT for style_file_information_btn_1_main_main_default
	static lv_style_t style_file_information_btn_1_main_main_default;
	if (style_file_information_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_btn_1_main_main_default);
	else
		lv_style_init(&style_file_information_btn_1_main_main_default);
	lv_style_set_radius(&style_file_information_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_file_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_file_information_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_file_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_information_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_file_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_file_information_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_file_information_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->file_information_btn_1, &style_file_information_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_information_btn_1_label = lv_label_create(ui->file_information_btn_1);
	lv_label_set_text(ui->file_information_btn_1_label, "");
	lv_obj_set_style_text_color(ui->file_information_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_information_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_information_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_information_label_2
	ui->file_information_label_2 = lv_label_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_label_2, 90, 11);
	lv_obj_set_size(ui->file_information_label_2, 300, 32);
	lv_label_set_text(ui->file_information_label_2, "文件详情");
	lv_label_set_long_mode(ui->file_information_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_information_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_information_label_2_main_main_default
	static lv_style_t style_file_information_label_2_main_main_default;
	if (style_file_information_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_label_2_main_main_default);
	else
		lv_style_init(&style_file_information_label_2_main_main_default);
	lv_style_set_radius(&style_file_information_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_file_information_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_file_information_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_file_information_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_information_label_2_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_file_information_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_file_information_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_file_information_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_file_information_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_information_label_2_main_main_default, 0);
	lv_obj_add_style(ui->file_information_label_2, &style_file_information_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_label_5
	ui->file_information_label_5 = lv_label_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_label_5, 29, 434);
	lv_obj_set_size(ui->file_information_label_5, 388, 24);
	lv_label_set_text(ui->file_information_label_5, "test.gcode");
	lv_label_set_long_mode(ui->file_information_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_information_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_information_label_5_main_main_default
	static lv_style_t style_file_information_label_5_main_main_default;
	if (style_file_information_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_label_5_main_main_default);
	else
		lv_style_init(&style_file_information_label_5_main_main_default);
	lv_style_set_radius(&style_file_information_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_file_information_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_file_information_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_file_information_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_information_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_information_label_5_main_main_default, 2);
	lv_style_set_pad_left(&style_file_information_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_file_information_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_file_information_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_information_label_5_main_main_default, 0);
	lv_obj_add_style(ui->file_information_label_5, &style_file_information_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_label_7
	ui->file_information_label_7 = lv_label_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_label_7, 49, 504);
	lv_obj_set_size(ui->file_information_label_7, 119, 24);
	lv_label_set_text(ui->file_information_label_7, "202h35m");
	lv_label_set_long_mode(ui->file_information_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_information_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_information_label_7_main_main_default
	static lv_style_t style_file_information_label_7_main_main_default;
	if (style_file_information_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_label_7_main_main_default);
	else
		lv_style_init(&style_file_information_label_7_main_main_default);
	lv_style_set_radius(&style_file_information_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_file_information_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_file_information_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_file_information_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_information_label_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_information_label_7_main_main_default, 2);
	lv_style_set_pad_left(&style_file_information_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_file_information_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_file_information_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_information_label_7_main_main_default, 0);
	lv_obj_add_style(ui->file_information_label_7, &style_file_information_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_label_8
	ui->file_information_label_8 = lv_label_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_label_8, 196, 504);
	lv_obj_set_size(ui->file_information_label_8, 101, 24);
	lv_label_set_text(ui->file_information_label_8, "166g");
	lv_label_set_long_mode(ui->file_information_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_information_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_information_label_8_main_main_default
	static lv_style_t style_file_information_label_8_main_main_default;
	if (style_file_information_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_label_8_main_main_default);
	else
		lv_style_init(&style_file_information_label_8_main_main_default);
	lv_style_set_radius(&style_file_information_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_file_information_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_file_information_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_file_information_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_information_label_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_information_label_8_main_main_default, 2);
	lv_style_set_pad_left(&style_file_information_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_file_information_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_file_information_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_information_label_8_main_main_default, 0);
	lv_obj_add_style(ui->file_information_label_8, &style_file_information_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_label_9
	ui->file_information_label_9 = lv_label_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_label_9, 383, 504);
	lv_obj_set_size(ui->file_information_label_9, 72, 24);
	lv_label_set_text(ui->file_information_label_9, "ABS");
	lv_label_set_long_mode(ui->file_information_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_information_label_9, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_information_label_9_main_main_default
	static lv_style_t style_file_information_label_9_main_main_default;
	if (style_file_information_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_label_9_main_main_default);
	else
		lv_style_init(&style_file_information_label_9_main_main_default);
	lv_style_set_radius(&style_file_information_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_label_9_main_main_default, lv_color_make(0xfa, 0x5a, 0x15));
	lv_style_set_bg_grad_color(&style_file_information_label_9_main_main_default, lv_color_make(0xfa, 0x5a, 0x15));
	lv_style_set_bg_grad_dir(&style_file_information_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_label_9_main_main_default, 255);
	lv_style_set_text_color(&style_file_information_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_information_label_9_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_information_label_9_main_main_default, 2);
	lv_style_set_pad_left(&style_file_information_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_file_information_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_file_information_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_information_label_9_main_main_default, 0);
	lv_obj_add_style(ui->file_information_label_9, &style_file_information_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_label_6
	ui->file_information_label_6 = lv_label_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_label_6, 27, 485);
	lv_obj_set_size(ui->file_information_label_6, 426, 1);
	lv_label_set_text(ui->file_information_label_6, "");
	lv_label_set_long_mode(ui->file_information_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_information_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_information_label_6_main_main_default
	static lv_style_t style_file_information_label_6_main_main_default;
	if (style_file_information_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_label_6_main_main_default);
	else
		lv_style_init(&style_file_information_label_6_main_main_default);
	lv_style_set_radius(&style_file_information_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_label_6_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_file_information_label_6_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_file_information_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_label_6_main_main_default, 255);
	lv_style_set_text_color(&style_file_information_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_information_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_file_information_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_file_information_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_file_information_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_information_label_6_main_main_default, 0);
	lv_obj_add_style(ui->file_information_label_6, &style_file_information_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_label_10
	ui->file_information_label_10 = lv_label_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_label_10, 27, 663);
	lv_obj_set_size(ui->file_information_label_10, 426, 1);
	lv_label_set_text(ui->file_information_label_10, "");
	lv_label_set_long_mode(ui->file_information_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_information_label_10, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_information_label_10_main_main_default
	static lv_style_t style_file_information_label_10_main_main_default;
	if (style_file_information_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_label_10_main_main_default);
	else
		lv_style_init(&style_file_information_label_10_main_main_default);
	lv_style_set_radius(&style_file_information_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_file_information_label_10_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_file_information_label_10_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_file_information_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_label_10_main_main_default, 255);
	lv_style_set_text_color(&style_file_information_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_information_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_file_information_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_file_information_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_file_information_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_information_label_10_main_main_default, 0);
	lv_obj_add_style(ui->file_information_label_10, &style_file_information_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_information_cb_1
	ui->file_information_cb_1 = lv_checkbox_create(ui->file_information_cont_1);
	lv_obj_set_pos(ui->file_information_cb_1, 30, 619);
	lv_checkbox_set_text(ui->file_information_cb_1, "自动调平");

	//Write style state: LV_STATE_DEFAULT for style_file_information_cb_1_main_main_default
	static lv_style_t style_file_information_cb_1_main_main_default;
	if (style_file_information_cb_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_cb_1_main_main_default);
	else
		lv_style_init(&style_file_information_cb_1_main_main_default);
	lv_style_set_radius(&style_file_information_cb_1_main_main_default, 6);
	lv_style_set_bg_color(&style_file_information_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_file_information_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_file_information_cb_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_cb_1_main_main_default, 0);
	lv_style_set_text_color(&style_file_information_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_information_cb_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_information_cb_1_main_main_default, 0);
	lv_obj_add_style(ui->file_information_cb_1, &style_file_information_cb_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_file_information_cb_1_main_indicator_default
	static lv_style_t style_file_information_cb_1_main_indicator_default;
	if (style_file_information_cb_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_file_information_cb_1_main_indicator_default);
	else
		lv_style_init(&style_file_information_cb_1_main_indicator_default);
	lv_style_set_radius(&style_file_information_cb_1_main_indicator_default, 2);
	lv_style_set_bg_color(&style_file_information_cb_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_file_information_cb_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_file_information_cb_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_cb_1_main_indicator_default, 255);
	lv_style_set_border_color(&style_file_information_cb_1_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_file_information_cb_1_main_indicator_default, 0);
	lv_obj_add_style(ui->file_information_cb_1, &style_file_information_cb_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_file_information_cb_1_main_indicator_checked
	static lv_style_t style_file_information_cb_1_main_indicator_checked;
	if (style_file_information_cb_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_file_information_cb_1_main_indicator_checked);
	else
		lv_style_init(&style_file_information_cb_1_main_indicator_checked);
	lv_style_set_radius(&style_file_information_cb_1_main_indicator_checked, 2);
	lv_style_set_bg_color(&style_file_information_cb_1_main_indicator_checked, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_file_information_cb_1_main_indicator_checked, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_file_information_cb_1_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_information_cb_1_main_indicator_checked, 255);
	lv_style_set_border_color(&style_file_information_cb_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_file_information_cb_1_main_indicator_checked, 0);
	lv_obj_add_style(ui->file_information_cb_1, &style_file_information_cb_1_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Init events for screen
	events_init_file_information(ui);
}
