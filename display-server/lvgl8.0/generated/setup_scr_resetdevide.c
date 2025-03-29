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


void setup_scr_resetdevide(lv_ui *ui){

	//Write codes resetdevide_cont_1
	ui->resetdevide_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->resetdevide_cont_1, 0, 0);
	lv_obj_set_size(ui->resetdevide_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_cont_1_main_main_default
	static lv_style_t style_resetdevide_cont_1_main_main_default;
	if (style_resetdevide_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cont_1_main_main_default);
	else
		lv_style_init(&style_resetdevide_cont_1_main_main_default);
	lv_style_set_radius(&style_resetdevide_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_resetdevide_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_resetdevide_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_resetdevide_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_resetdevide_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_resetdevide_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_resetdevide_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_resetdevide_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_resetdevide_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_resetdevide_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_resetdevide_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->resetdevide_cont_1, &style_resetdevide_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes resetdevide_label_3
	ui->resetdevide_label_3 = lv_label_create(ui->resetdevide_cont_1);
	lv_obj_set_pos(ui->resetdevide_label_3, 10, 56);
	lv_obj_set_size(ui->resetdevide_label_3, 460, 727);
	lv_label_set_text(ui->resetdevide_label_3, "");
	lv_label_set_long_mode(ui->resetdevide_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->resetdevide_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_label_3_main_main_default
	static lv_style_t style_resetdevide_label_3_main_main_default;
	if (style_resetdevide_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_label_3_main_main_default);
	else
		lv_style_init(&style_resetdevide_label_3_main_main_default);
	lv_style_set_radius(&style_resetdevide_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_resetdevide_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_resetdevide_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_resetdevide_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_resetdevide_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_resetdevide_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_resetdevide_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_resetdevide_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_resetdevide_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_resetdevide_label_3_main_main_default, 0);
	lv_obj_add_style(ui->resetdevide_label_3, &style_resetdevide_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes resetdevide_cb_1
	ui->resetdevide_cb_1 = lv_checkbox_create(ui->resetdevide_cont_1);
	lv_obj_set_pos(ui->resetdevide_cb_1, 36, 147);
	lv_checkbox_set_text(ui->resetdevide_cb_1, "日志");

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_cb_1_main_main_default
	static lv_style_t style_resetdevide_cb_1_main_main_default;
	if (style_resetdevide_cb_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_1_main_main_default);
	else
		lv_style_init(&style_resetdevide_cb_1_main_main_default);
	lv_style_set_radius(&style_resetdevide_cb_1_main_main_default, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_1_main_main_default, 0);
	lv_style_set_text_color(&style_resetdevide_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_resetdevide_cb_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_resetdevide_cb_1_main_main_default, 0);
	lv_obj_add_style(ui->resetdevide_cb_1, &style_resetdevide_cb_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_cb_1_main_indicator_default
	static lv_style_t style_resetdevide_cb_1_main_indicator_default;
	if (style_resetdevide_cb_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_1_main_indicator_default);
	else
		lv_style_init(&style_resetdevide_cb_1_main_indicator_default);
	lv_style_set_radius(&style_resetdevide_cb_1_main_indicator_default, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_1_main_indicator_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_1_main_indicator_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_1_main_indicator_default, 0);
	lv_style_set_border_color(&style_resetdevide_cb_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_resetdevide_cb_1_main_indicator_default, 2);
	lv_obj_add_style(ui->resetdevide_cb_1, &style_resetdevide_cb_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_resetdevide_cb_1_main_indicator_checked
	static lv_style_t style_resetdevide_cb_1_main_indicator_checked;
	if (style_resetdevide_cb_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_1_main_indicator_checked);
	else
		lv_style_init(&style_resetdevide_cb_1_main_indicator_checked);
	lv_style_set_radius(&style_resetdevide_cb_1_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_1_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_1_main_indicator_checked, 0);
	lv_style_set_border_color(&style_resetdevide_cb_1_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_resetdevide_cb_1_main_indicator_checked, 2);
	lv_obj_add_style(ui->resetdevide_cb_1, &style_resetdevide_cb_1_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes resetdevide_cb_2
	ui->resetdevide_cb_2 = lv_checkbox_create(ui->resetdevide_cont_1);
	lv_obj_set_pos(ui->resetdevide_cb_2, 36, 207);
	lv_checkbox_set_text(ui->resetdevide_cb_2, "延时摄影视频");

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_cb_2_main_main_default
	static lv_style_t style_resetdevide_cb_2_main_main_default;
	if (style_resetdevide_cb_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_2_main_main_default);
	else
		lv_style_init(&style_resetdevide_cb_2_main_main_default);
	lv_style_set_radius(&style_resetdevide_cb_2_main_main_default, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_2_main_main_default, 0);
	lv_style_set_text_color(&style_resetdevide_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_resetdevide_cb_2_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_resetdevide_cb_2_main_main_default, 0);
	lv_obj_add_style(ui->resetdevide_cb_2, &style_resetdevide_cb_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_cb_2_main_indicator_default
	static lv_style_t style_resetdevide_cb_2_main_indicator_default;
	if (style_resetdevide_cb_2_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_2_main_indicator_default);
	else
		lv_style_init(&style_resetdevide_cb_2_main_indicator_default);
	lv_style_set_radius(&style_resetdevide_cb_2_main_indicator_default, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_2_main_indicator_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_2_main_indicator_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_2_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_2_main_indicator_default, 0);
	lv_style_set_border_color(&style_resetdevide_cb_2_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_resetdevide_cb_2_main_indicator_default, 2);
	lv_obj_add_style(ui->resetdevide_cb_2, &style_resetdevide_cb_2_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_resetdevide_cb_2_main_indicator_checked
	static lv_style_t style_resetdevide_cb_2_main_indicator_checked;
	if (style_resetdevide_cb_2_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_2_main_indicator_checked);
	else
		lv_style_init(&style_resetdevide_cb_2_main_indicator_checked);
	lv_style_set_radius(&style_resetdevide_cb_2_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_2_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_2_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_2_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_2_main_indicator_checked, 0);
	lv_style_set_border_color(&style_resetdevide_cb_2_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_resetdevide_cb_2_main_indicator_checked, 2);
	lv_obj_add_style(ui->resetdevide_cb_2, &style_resetdevide_cb_2_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes resetdevide_cb_3
	ui->resetdevide_cb_3 = lv_checkbox_create(ui->resetdevide_cont_1);
	lv_obj_set_pos(ui->resetdevide_cb_3, 36, 268);
	lv_checkbox_set_text(ui->resetdevide_cb_3, "Gcode文件");

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_cb_3_main_main_default
	static lv_style_t style_resetdevide_cb_3_main_main_default;
	if (style_resetdevide_cb_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_3_main_main_default);
	else
		lv_style_init(&style_resetdevide_cb_3_main_main_default);
	lv_style_set_radius(&style_resetdevide_cb_3_main_main_default, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_3_main_main_default, 0);
	lv_style_set_text_color(&style_resetdevide_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_resetdevide_cb_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_resetdevide_cb_3_main_main_default, 0);
	lv_obj_add_style(ui->resetdevide_cb_3, &style_resetdevide_cb_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_cb_3_main_indicator_default
	static lv_style_t style_resetdevide_cb_3_main_indicator_default;
	if (style_resetdevide_cb_3_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_3_main_indicator_default);
	else
		lv_style_init(&style_resetdevide_cb_3_main_indicator_default);
	lv_style_set_radius(&style_resetdevide_cb_3_main_indicator_default, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_3_main_indicator_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_3_main_indicator_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_3_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_3_main_indicator_default, 0);
	lv_style_set_border_color(&style_resetdevide_cb_3_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_resetdevide_cb_3_main_indicator_default, 2);
	lv_obj_add_style(ui->resetdevide_cb_3, &style_resetdevide_cb_3_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_resetdevide_cb_3_main_indicator_checked
	static lv_style_t style_resetdevide_cb_3_main_indicator_checked;
	if (style_resetdevide_cb_3_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_3_main_indicator_checked);
	else
		lv_style_init(&style_resetdevide_cb_3_main_indicator_checked);
	lv_style_set_radius(&style_resetdevide_cb_3_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_3_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_3_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_3_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_3_main_indicator_checked, 0);
	lv_style_set_border_color(&style_resetdevide_cb_3_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_resetdevide_cb_3_main_indicator_checked, 2);
	lv_obj_add_style(ui->resetdevide_cb_3, &style_resetdevide_cb_3_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes resetdevide_cb_4
	ui->resetdevide_cb_4 = lv_checkbox_create(ui->resetdevide_cont_1);
	lv_obj_set_pos(ui->resetdevide_cb_4, 36, 325);
	lv_checkbox_set_text(ui->resetdevide_cb_4, "打印记录");

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_cb_4_main_main_default
	static lv_style_t style_resetdevide_cb_4_main_main_default;
	if (style_resetdevide_cb_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_4_main_main_default);
	else
		lv_style_init(&style_resetdevide_cb_4_main_main_default);
	lv_style_set_radius(&style_resetdevide_cb_4_main_main_default, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_4_main_main_default, 0);
	lv_style_set_text_color(&style_resetdevide_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_resetdevide_cb_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_resetdevide_cb_4_main_main_default, 0);
	lv_obj_add_style(ui->resetdevide_cb_4, &style_resetdevide_cb_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_cb_4_main_indicator_default
	static lv_style_t style_resetdevide_cb_4_main_indicator_default;
	if (style_resetdevide_cb_4_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_4_main_indicator_default);
	else
		lv_style_init(&style_resetdevide_cb_4_main_indicator_default);
	lv_style_set_radius(&style_resetdevide_cb_4_main_indicator_default, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_4_main_indicator_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_4_main_indicator_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_4_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_4_main_indicator_default, 0);
	lv_style_set_border_color(&style_resetdevide_cb_4_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_resetdevide_cb_4_main_indicator_default, 2);
	lv_obj_add_style(ui->resetdevide_cb_4, &style_resetdevide_cb_4_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_resetdevide_cb_4_main_indicator_checked
	static lv_style_t style_resetdevide_cb_4_main_indicator_checked;
	if (style_resetdevide_cb_4_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_cb_4_main_indicator_checked);
	else
		lv_style_init(&style_resetdevide_cb_4_main_indicator_checked);
	lv_style_set_radius(&style_resetdevide_cb_4_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_resetdevide_cb_4_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_resetdevide_cb_4_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_resetdevide_cb_4_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_cb_4_main_indicator_checked, 0);
	lv_style_set_border_color(&style_resetdevide_cb_4_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_resetdevide_cb_4_main_indicator_checked, 2);
	lv_obj_add_style(ui->resetdevide_cb_4, &style_resetdevide_cb_4_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes resetdevide_btn_2
	ui->resetdevide_btn_2 = lv_btn_create(ui->resetdevide_cont_1);
	lv_obj_set_pos(ui->resetdevide_btn_2, 27, 700);
	lv_obj_set_size(ui->resetdevide_btn_2, 426, 65);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_btn_2_main_main_default
	static lv_style_t style_resetdevide_btn_2_main_main_default;
	if (style_resetdevide_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_btn_2_main_main_default);
	else
		lv_style_init(&style_resetdevide_btn_2_main_main_default);
	lv_style_set_radius(&style_resetdevide_btn_2_main_main_default, 8);
	lv_style_set_bg_color(&style_resetdevide_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_resetdevide_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_resetdevide_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_resetdevide_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_resetdevide_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_resetdevide_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_resetdevide_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_resetdevide_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->resetdevide_btn_2, &style_resetdevide_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->resetdevide_btn_2_label = lv_label_create(ui->resetdevide_btn_2);
	lv_label_set_text(ui->resetdevide_btn_2_label, "恢复");
	lv_obj_set_style_text_color(ui->resetdevide_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->resetdevide_btn_2_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->resetdevide_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->resetdevide_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes resetdevide_label_1
	ui->resetdevide_label_1 = lv_label_create(ui->resetdevide_cont_1);
	lv_obj_set_pos(ui->resetdevide_label_1, 0, 0);
	lv_obj_set_size(ui->resetdevide_label_1, 480, 53);
	lv_label_set_text(ui->resetdevide_label_1, "");
	lv_label_set_long_mode(ui->resetdevide_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->resetdevide_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_label_1_main_main_default
	static lv_style_t style_resetdevide_label_1_main_main_default;
	if (style_resetdevide_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_label_1_main_main_default);
	else
		lv_style_init(&style_resetdevide_label_1_main_main_default);
	lv_style_set_radius(&style_resetdevide_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_resetdevide_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_resetdevide_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_resetdevide_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_resetdevide_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_resetdevide_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_resetdevide_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_resetdevide_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_resetdevide_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_resetdevide_label_1_main_main_default, 0);
	lv_obj_add_style(ui->resetdevide_label_1, &style_resetdevide_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes resetdevide_label_4
	ui->resetdevide_label_4 = lv_label_create(ui->resetdevide_cont_1);
	lv_obj_set_pos(ui->resetdevide_label_4, 36, 80);
	lv_obj_set_size(ui->resetdevide_label_4, 350, 28);
	lv_label_set_text(ui->resetdevide_label_4, "清除选项");
	lv_label_set_long_mode(ui->resetdevide_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->resetdevide_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_label_4_main_main_default
	static lv_style_t style_resetdevide_label_4_main_main_default;
	if (style_resetdevide_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_label_4_main_main_default);
	else
		lv_style_init(&style_resetdevide_label_4_main_main_default);
	lv_style_set_radius(&style_resetdevide_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_resetdevide_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_resetdevide_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_resetdevide_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_resetdevide_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_resetdevide_label_4_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_resetdevide_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_resetdevide_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_resetdevide_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_resetdevide_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_resetdevide_label_4_main_main_default, 0);
	lv_obj_add_style(ui->resetdevide_label_4, &style_resetdevide_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes resetdevide_img_1
	ui->resetdevide_img_1 = lv_img_create(ui->resetdevide_cont_1);
	lv_obj_set_pos(ui->resetdevide_img_1, 21, 17);
	lv_obj_set_size(ui->resetdevide_img_1, 36, 24);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_img_1_main_main_default
	static lv_style_t style_resetdevide_img_1_main_main_default;
	if (style_resetdevide_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_img_1_main_main_default);
	else
		lv_style_init(&style_resetdevide_img_1_main_main_default);
	lv_style_set_img_recolor(&style_resetdevide_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_resetdevide_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_resetdevide_img_1_main_main_default, 255);
	lv_obj_add_style(ui->resetdevide_img_1, &style_resetdevide_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->resetdevide_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->resetdevide_img_1,&_back_36x24);
	lv_img_set_pivot(ui->resetdevide_img_1, 0,0);
	lv_img_set_angle(ui->resetdevide_img_1, 0);

	//Write codes resetdevide_btn_1
	ui->resetdevide_btn_1 = lv_btn_create(ui->resetdevide_cont_1);
	lv_obj_set_pos(ui->resetdevide_btn_1, 0, 0);
	lv_obj_set_size(ui->resetdevide_btn_1, 85, 50);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_btn_1_main_main_default
	static lv_style_t style_resetdevide_btn_1_main_main_default;
	if (style_resetdevide_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_btn_1_main_main_default);
	else
		lv_style_init(&style_resetdevide_btn_1_main_main_default);
	lv_style_set_radius(&style_resetdevide_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_resetdevide_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_resetdevide_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_resetdevide_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_resetdevide_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_resetdevide_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_resetdevide_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_resetdevide_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_resetdevide_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->resetdevide_btn_1, &style_resetdevide_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->resetdevide_btn_1_label = lv_label_create(ui->resetdevide_btn_1);
	lv_label_set_text(ui->resetdevide_btn_1_label, "");
	lv_obj_set_style_text_color(ui->resetdevide_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->resetdevide_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->resetdevide_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes resetdevide_label_2
	ui->resetdevide_label_2 = lv_label_create(ui->resetdevide_cont_1);
	lv_obj_set_pos(ui->resetdevide_label_2, 90, 11);
	lv_obj_set_size(ui->resetdevide_label_2, 300, 32);
	lv_label_set_text(ui->resetdevide_label_2, "恢复出厂");
	lv_label_set_long_mode(ui->resetdevide_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->resetdevide_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_resetdevide_label_2_main_main_default
	static lv_style_t style_resetdevide_label_2_main_main_default;
	if (style_resetdevide_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_resetdevide_label_2_main_main_default);
	else
		lv_style_init(&style_resetdevide_label_2_main_main_default);
	lv_style_set_radius(&style_resetdevide_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_resetdevide_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_resetdevide_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_resetdevide_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_resetdevide_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_resetdevide_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_resetdevide_label_2_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_resetdevide_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_resetdevide_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_resetdevide_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_resetdevide_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_resetdevide_label_2_main_main_default, 0);
	lv_obj_add_style(ui->resetdevide_label_2, &style_resetdevide_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_resetdevide(ui);
}
