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


void setup_scr_file_management_history(lv_ui *ui){

	//Write codes file_management_history
	ui->file_management_history = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_main_main_default
	static lv_style_t style_file_management_history_main_main_default;
	if (style_file_management_history_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_main_main_default);
	else
		lv_style_init(&style_file_management_history_main_main_default);
	lv_style_set_bg_color(&style_file_management_history_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_file_management_history_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history, &style_file_management_history_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_tabview_1
	ui->file_management_history_tabview_1 = lv_tabview_create(ui->file_management_history, LV_DIR_TOP, 47);
	lv_obj_set_pos(ui->file_management_history_tabview_1, 0, 0);
	lv_obj_set_size(ui->file_management_history_tabview_1, 480, 720);

	//title1
	ui->file_management_history_tabview_1_title1 = lv_tabview_add_tab(ui->file_management_history_tabview_1,"title1");

	//title2
	ui->file_management_history_tabview_1_title2 = lv_tabview_add_tab(ui->file_management_history_tabview_1,"title2");

	//title3
	ui->file_management_history_tabview_1_title3 = lv_tabview_add_tab(ui->file_management_history_tabview_1,"title3");


	//Write style state: LV_STATE_DEFAULT for style_file_management_history_tabview_1_main_main_default
	static lv_style_t style_file_management_history_tabview_1_main_main_default;
	if (style_file_management_history_tabview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_tabview_1_main_main_default);
	else
		lv_style_init(&style_file_management_history_tabview_1_main_main_default);
	lv_style_set_bg_color(&style_file_management_history_tabview_1_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_file_management_history_tabview_1_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_file_management_history_tabview_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_tabview_1_main_main_default, 255);
	lv_style_set_border_color(&style_file_management_history_tabview_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_file_management_history_tabview_1_main_main_default, 0);
	lv_style_set_border_opa(&style_file_management_history_tabview_1_main_main_default, 100);
	lv_style_set_text_color(&style_file_management_history_tabview_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_file_management_history_tabview_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_tabview_1_main_main_default, 0);
	lv_style_set_text_line_space(&style_file_management_history_tabview_1_main_main_default, 16);
	lv_obj_add_style(ui->file_management_history_tabview_1, &style_file_management_history_tabview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_tabview_1_extra_btnm_main_default
	static lv_style_t style_file_management_history_tabview_1_extra_btnm_main_default;
	if (style_file_management_history_tabview_1_extra_btnm_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_tabview_1_extra_btnm_main_default);
	else
		lv_style_init(&style_file_management_history_tabview_1_extra_btnm_main_default);
	lv_style_set_bg_color(&style_file_management_history_tabview_1_extra_btnm_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_file_management_history_tabview_1_extra_btnm_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_file_management_history_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_border_color(&style_file_management_history_tabview_1_extra_btnm_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_file_management_history_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_border_opa(&style_file_management_history_tabview_1_extra_btnm_main_default, 100);
	lv_style_set_pad_left(&style_file_management_history_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_tabview_1_extra_btnm_main_default, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->file_management_history_tabview_1), &style_file_management_history_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_tabview_1_extra_btnm_items_default
	static lv_style_t style_file_management_history_tabview_1_extra_btnm_items_default;
	if (style_file_management_history_tabview_1_extra_btnm_items_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_tabview_1_extra_btnm_items_default);
	else
		lv_style_init(&style_file_management_history_tabview_1_extra_btnm_items_default);
	lv_style_set_text_color(&style_file_management_history_tabview_1_extra_btnm_items_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_file_management_history_tabview_1_extra_btnm_items_default, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->file_management_history_tabview_1), &style_file_management_history_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_file_management_history_tabview_1_extra_btnm_items_checked
	static lv_style_t style_file_management_history_tabview_1_extra_btnm_items_checked;
	if (style_file_management_history_tabview_1_extra_btnm_items_checked.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_tabview_1_extra_btnm_items_checked);
	else
		lv_style_init(&style_file_management_history_tabview_1_extra_btnm_items_checked);
	lv_style_set_bg_color(&style_file_management_history_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_file_management_history_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_file_management_history_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_tabview_1_extra_btnm_items_checked, 60);
	lv_style_set_border_color(&style_file_management_history_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_file_management_history_tabview_1_extra_btnm_items_checked, 4);
	lv_style_set_border_opa(&style_file_management_history_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_side(&style_file_management_history_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_text_color(&style_file_management_history_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_text_font(&style_file_management_history_tabview_1_extra_btnm_items_checked, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->file_management_history_tabview_1), &style_file_management_history_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes file_management_history_cont_1
	ui->file_management_history_cont_1 = lv_obj_create(ui->file_management_history);
	lv_obj_set_pos(ui->file_management_history_cont_1, 0, 0);
	lv_obj_set_size(ui->file_management_history_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_cont_1_main_main_default
	static lv_style_t style_file_management_history_cont_1_main_main_default;
	if (style_file_management_history_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_cont_1_main_main_default);
	else
		lv_style_init(&style_file_management_history_cont_1_main_main_default);
	lv_style_set_radius(&style_file_management_history_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_file_management_history_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_file_management_history_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_file_management_history_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_file_management_history_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_file_management_history_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_file_management_history_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_cont_1, &style_file_management_history_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_1
	ui->file_management_history_label_1 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_1, 0, 720);
	lv_obj_set_size(ui->file_management_history_label_1, 480, 80);
	lv_label_set_text(ui->file_management_history_label_1, "");
	lv_label_set_long_mode(ui->file_management_history_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_1_main_main_default
	static lv_style_t style_file_management_history_label_1_main_main_default;
	if (style_file_management_history_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_1_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_1_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_history_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_history_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_1_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_1, &style_file_management_history_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_2
	ui->file_management_history_label_2 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_2, 7, 59);
	lv_obj_set_size(ui->file_management_history_label_2, 460, 647);
	lv_label_set_text(ui->file_management_history_label_2, "");
	lv_label_set_long_mode(ui->file_management_history_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_2_main_main_default
	static lv_style_t style_file_management_history_label_2_main_main_default;
	if (style_file_management_history_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_2_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_2_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_file_management_history_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_history_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_history_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_2_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_2, &style_file_management_history_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_3
	ui->file_management_history_label_3 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_3, 130, 85);
	lv_obj_set_size(ui->file_management_history_label_3, 207, 24);
	lv_label_set_text(ui->file_management_history_label_3, "test.gcode");
	lv_label_set_long_mode(ui->file_management_history_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_3, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_3_main_main_default
	static lv_style_t style_file_management_history_label_3_main_main_default;
	if (style_file_management_history_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_3_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_3_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_3_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_3_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_3_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_3, &style_file_management_history_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_11
	ui->file_management_history_label_11 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_11, 130, 201);
	lv_obj_set_size(ui->file_management_history_label_11, 207, 24);
	lv_label_set_text(ui->file_management_history_label_11, "test.gcode");
	lv_label_set_long_mode(ui->file_management_history_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_11, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_11_main_main_default
	static lv_style_t style_file_management_history_label_11_main_main_default;
	if (style_file_management_history_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_11_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_11_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_11_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_11_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_11_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_11_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_11_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_11, &style_file_management_history_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_12
	ui->file_management_history_label_12 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_12, 130, 317);
	lv_obj_set_size(ui->file_management_history_label_12, 207, 24);
	lv_label_set_text(ui->file_management_history_label_12, "test.gcode");
	lv_label_set_long_mode(ui->file_management_history_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_12, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_12_main_main_default
	static lv_style_t style_file_management_history_label_12_main_main_default;
	if (style_file_management_history_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_12_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_12_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_12_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_12_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_12_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_12_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_12_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_12_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_12_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_12, &style_file_management_history_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_13
	ui->file_management_history_label_13 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_13, 130, 433);
	lv_obj_set_size(ui->file_management_history_label_13, 207, 24);
	lv_label_set_text(ui->file_management_history_label_13, "test.gcode");
	lv_label_set_long_mode(ui->file_management_history_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_13, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_13_main_main_default
	static lv_style_t style_file_management_history_label_13_main_main_default;
	if (style_file_management_history_label_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_13_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_13_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_13_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_13_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_13_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_13_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_13_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_13_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_13_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_13_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_13_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_13_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_13_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_13, &style_file_management_history_label_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_14
	ui->file_management_history_label_14 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_14, 130, 549);
	lv_obj_set_size(ui->file_management_history_label_14, 207, 24);
	lv_label_set_text(ui->file_management_history_label_14, "test.gcode");
	lv_label_set_long_mode(ui->file_management_history_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_14, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_14_main_main_default
	static lv_style_t style_file_management_history_label_14_main_main_default;
	if (style_file_management_history_label_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_14_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_14_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_14_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_14_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_14_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_14_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_14_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_14_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_14_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_14_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_14_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_14_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_14_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_14, &style_file_management_history_label_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_4
	ui->file_management_history_label_4 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_4, 130, 117);
	lv_obj_set_size(ui->file_management_history_label_4, 183, 24);
	lv_label_set_text(ui->file_management_history_label_4, "3月4日 11：50");
	lv_label_set_long_mode(ui->file_management_history_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_4_main_main_default
	static lv_style_t style_file_management_history_label_4_main_main_default;
	if (style_file_management_history_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_4_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_4_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_4_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_4_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_4_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_4, &style_file_management_history_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_15
	ui->file_management_history_label_15 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_15, 130, 233);
	lv_obj_set_size(ui->file_management_history_label_15, 183, 24);
	lv_label_set_text(ui->file_management_history_label_15, "3月4日 11：50");
	lv_label_set_long_mode(ui->file_management_history_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_15, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_15_main_main_default
	static lv_style_t style_file_management_history_label_15_main_main_default;
	if (style_file_management_history_label_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_15_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_15_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_15_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_15_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_15_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_15_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_15_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_15_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_15_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_15_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_15_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_15_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_15_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_15, &style_file_management_history_label_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_16
	ui->file_management_history_label_16 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_16, 130, 349);
	lv_obj_set_size(ui->file_management_history_label_16, 183, 24);
	lv_label_set_text(ui->file_management_history_label_16, "3月4日 11：50");
	lv_label_set_long_mode(ui->file_management_history_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_16, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_16_main_main_default
	static lv_style_t style_file_management_history_label_16_main_main_default;
	if (style_file_management_history_label_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_16_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_16_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_16_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_16_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_16_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_16_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_16_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_16_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_16_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_16_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_16_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_16_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_16_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_16, &style_file_management_history_label_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_17
	ui->file_management_history_label_17 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_17, 130, 465);
	lv_obj_set_size(ui->file_management_history_label_17, 183, 24);
	lv_label_set_text(ui->file_management_history_label_17, "3月4日 11：50");
	lv_label_set_long_mode(ui->file_management_history_label_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_17, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_17_main_main_default
	static lv_style_t style_file_management_history_label_17_main_main_default;
	if (style_file_management_history_label_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_17_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_17_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_17_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_17_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_17_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_17_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_17_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_17_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_17_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_17_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_17_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_17_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_17_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_17_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_17, &style_file_management_history_label_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_18
	ui->file_management_history_label_18 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_18, 130, 581);
	lv_obj_set_size(ui->file_management_history_label_18, 183, 24);
	lv_label_set_text(ui->file_management_history_label_18, "3月4日 11：50");
	lv_label_set_long_mode(ui->file_management_history_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_18, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_18_main_main_default
	static lv_style_t style_file_management_history_label_18_main_main_default;
	if (style_file_management_history_label_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_18_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_18_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_18_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_18_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_18_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_18_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_18_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_18_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_18_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_18_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_18_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_18_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_18_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_18_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_18, &style_file_management_history_label_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_5
	ui->file_management_history_label_5 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_5, 130, 149);
	lv_obj_set_size(ui->file_management_history_label_5, 183, 24);
	lv_label_set_text(ui->file_management_history_label_5, "11h25m");
	lv_label_set_long_mode(ui->file_management_history_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_5_main_main_default
	static lv_style_t style_file_management_history_label_5_main_main_default;
	if (style_file_management_history_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_5_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_5_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_5_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_5_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_5_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_5, &style_file_management_history_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_19
	ui->file_management_history_label_19 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_19, 130, 265);
	lv_obj_set_size(ui->file_management_history_label_19, 183, 24);
	lv_label_set_text(ui->file_management_history_label_19, "11h25m");
	lv_label_set_long_mode(ui->file_management_history_label_19, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_19, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_19_main_main_default
	static lv_style_t style_file_management_history_label_19_main_main_default;
	if (style_file_management_history_label_19_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_19_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_19_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_19_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_19_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_19_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_19_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_19_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_19_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_19_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_19_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_19_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_19_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_19_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_19_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_19, &style_file_management_history_label_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_20
	ui->file_management_history_label_20 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_20, 130, 381);
	lv_obj_set_size(ui->file_management_history_label_20, 183, 24);
	lv_label_set_text(ui->file_management_history_label_20, "11h25m");
	lv_label_set_long_mode(ui->file_management_history_label_20, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_20, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_20_main_main_default
	static lv_style_t style_file_management_history_label_20_main_main_default;
	if (style_file_management_history_label_20_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_20_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_20_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_20_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_20_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_20_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_20_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_20_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_20_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_20_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_20_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_20_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_20_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_20_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_20_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_20, &style_file_management_history_label_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_21
	ui->file_management_history_label_21 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_21, 130, 497);
	lv_obj_set_size(ui->file_management_history_label_21, 183, 24);
	lv_label_set_text(ui->file_management_history_label_21, "11h25m");
	lv_label_set_long_mode(ui->file_management_history_label_21, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_21, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_21_main_main_default
	static lv_style_t style_file_management_history_label_21_main_main_default;
	if (style_file_management_history_label_21_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_21_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_21_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_21_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_21_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_21_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_21_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_21_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_21_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_21_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_21_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_21_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_21_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_21_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_21_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_21, &style_file_management_history_label_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_22
	ui->file_management_history_label_22 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_22, 130, 613);
	lv_obj_set_size(ui->file_management_history_label_22, 183, 24);
	lv_label_set_text(ui->file_management_history_label_22, "11h25m");
	lv_label_set_long_mode(ui->file_management_history_label_22, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_22, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_22_main_main_default
	static lv_style_t style_file_management_history_label_22_main_main_default;
	if (style_file_management_history_label_22_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_22_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_22_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_22_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_22_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_history_label_22_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_22_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_22_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_history_label_22_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_history_label_22_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_history_label_22_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_22_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_22_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_22_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_22_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_22, &style_file_management_history_label_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_6
	ui->file_management_history_label_6 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_6, 20, 191);
	lv_obj_set_size(ui->file_management_history_label_6, 440, 1);
	lv_label_set_text(ui->file_management_history_label_6, "");
	lv_label_set_long_mode(ui->file_management_history_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_6_main_main_default
	static lv_style_t style_file_management_history_label_6_main_main_default;
	if (style_file_management_history_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_6_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_6_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_6_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_file_management_history_label_6_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_6_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_history_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_history_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_6_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_6, &style_file_management_history_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_7
	ui->file_management_history_label_7 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_7, 20, 307);
	lv_obj_set_size(ui->file_management_history_label_7, 440, 1);
	lv_label_set_text(ui->file_management_history_label_7, "");
	lv_label_set_long_mode(ui->file_management_history_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_7_main_main_default
	static lv_style_t style_file_management_history_label_7_main_main_default;
	if (style_file_management_history_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_7_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_7_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_7_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_file_management_history_label_7_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_7_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_history_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_history_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_7_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_7, &style_file_management_history_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_8
	ui->file_management_history_label_8 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_8, 20, 423);
	lv_obj_set_size(ui->file_management_history_label_8, 440, 1);
	lv_label_set_text(ui->file_management_history_label_8, "");
	lv_label_set_long_mode(ui->file_management_history_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_8_main_main_default
	static lv_style_t style_file_management_history_label_8_main_main_default;
	if (style_file_management_history_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_8_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_8_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_8_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_file_management_history_label_8_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_8_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_history_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_history_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_8_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_8, &style_file_management_history_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_9
	ui->file_management_history_label_9 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_9, 20, 539);
	lv_obj_set_size(ui->file_management_history_label_9, 440, 1);
	lv_label_set_text(ui->file_management_history_label_9, "");
	lv_label_set_long_mode(ui->file_management_history_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_9, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_9_main_main_default
	static lv_style_t style_file_management_history_label_9_main_main_default;
	if (style_file_management_history_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_9_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_9_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_9_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_file_management_history_label_9_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_9_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_history_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_history_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_9_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_9, &style_file_management_history_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_label_10
	ui->file_management_history_label_10 = lv_label_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_label_10, 20, 655);
	lv_obj_set_size(ui->file_management_history_label_10, 440, 1);
	lv_label_set_text(ui->file_management_history_label_10, "");
	lv_label_set_long_mode(ui->file_management_history_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_history_label_10, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_label_10_main_main_default
	static lv_style_t style_file_management_history_label_10_main_main_default;
	if (style_file_management_history_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_label_10_main_main_default);
	else
		lv_style_init(&style_file_management_history_label_10_main_main_default);
	lv_style_set_radius(&style_file_management_history_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_label_10_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_file_management_history_label_10_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_file_management_history_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_label_10_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_history_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_history_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_history_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_history_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_history_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_history_label_10_main_main_default, 0);
	lv_obj_add_style(ui->file_management_history_label_10, &style_file_management_history_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_btn_1
	ui->file_management_history_btn_1 = lv_btn_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_btn_1, 418, 592);
	lv_obj_set_size(ui->file_management_history_btn_1, 60, 60);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_btn_1_main_main_default
	static lv_style_t style_file_management_history_btn_1_main_main_default;
	if (style_file_management_history_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_btn_1_main_main_default);
	else
		lv_style_init(&style_file_management_history_btn_1_main_main_default);
	lv_style_set_radius(&style_file_management_history_btn_1_main_main_default, 30);
	lv_style_set_bg_color(&style_file_management_history_btn_1_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_color(&style_file_management_history_btn_1_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_dir(&style_file_management_history_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_btn_1_main_main_default, 227);
	lv_style_set_shadow_color(&style_file_management_history_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_management_history_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_file_management_history_btn_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_border_width(&style_file_management_history_btn_1_main_main_default, 1);
	lv_style_set_border_opa(&style_file_management_history_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_btn_1, &style_file_management_history_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_management_history_btn_1_label = lv_label_create(ui->file_management_history_btn_1);
	lv_label_set_text(ui->file_management_history_btn_1_label, "");
	lv_obj_set_style_text_color(ui->file_management_history_btn_1_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_management_history_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_management_history_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_management_history_btn_2
	ui->file_management_history_btn_2 = lv_btn_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_btn_2, 418, 666);
	lv_obj_set_size(ui->file_management_history_btn_2, 60, 60);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_btn_2_main_main_default
	static lv_style_t style_file_management_history_btn_2_main_main_default;
	if (style_file_management_history_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_btn_2_main_main_default);
	else
		lv_style_init(&style_file_management_history_btn_2_main_main_default);
	lv_style_set_radius(&style_file_management_history_btn_2_main_main_default, 30);
	lv_style_set_bg_color(&style_file_management_history_btn_2_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_color(&style_file_management_history_btn_2_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_dir(&style_file_management_history_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_btn_2_main_main_default, 227);
	lv_style_set_shadow_color(&style_file_management_history_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_management_history_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_file_management_history_btn_2_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_border_width(&style_file_management_history_btn_2_main_main_default, 1);
	lv_style_set_border_opa(&style_file_management_history_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_btn_2, &style_file_management_history_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_management_history_btn_2_label = lv_label_create(ui->file_management_history_btn_2);
	lv_label_set_text(ui->file_management_history_btn_2_label, "");
	lv_obj_set_style_text_color(ui->file_management_history_btn_2_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_management_history_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_management_history_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_management_history_btn_3
	ui->file_management_history_btn_3 = lv_btn_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_btn_3, 366, 117);
	lv_obj_set_size(ui->file_management_history_btn_3, 97, 32);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_btn_3_main_main_default
	static lv_style_t style_file_management_history_btn_3_main_main_default;
	if (style_file_management_history_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_btn_3_main_main_default);
	else
		lv_style_init(&style_file_management_history_btn_3_main_main_default);
	lv_style_set_radius(&style_file_management_history_btn_3_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_btn_3_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_color(&style_file_management_history_btn_3_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_dir(&style_file_management_history_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_btn_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_file_management_history_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_management_history_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_file_management_history_btn_3_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_border_width(&style_file_management_history_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_file_management_history_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_btn_3, &style_file_management_history_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_management_history_btn_3_label = lv_label_create(ui->file_management_history_btn_3);
	lv_label_set_text(ui->file_management_history_btn_3_label, "再次打印");
	lv_obj_set_style_text_color(ui->file_management_history_btn_3_label, lv_color_make(0x42, 0xbd, 0xd8), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->file_management_history_btn_3_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_management_history_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_management_history_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_management_history_btn_4
	ui->file_management_history_btn_4 = lv_btn_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_btn_4, 366, 233);
	lv_obj_set_size(ui->file_management_history_btn_4, 97, 32);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_btn_4_main_main_default
	static lv_style_t style_file_management_history_btn_4_main_main_default;
	if (style_file_management_history_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_btn_4_main_main_default);
	else
		lv_style_init(&style_file_management_history_btn_4_main_main_default);
	lv_style_set_radius(&style_file_management_history_btn_4_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_btn_4_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_color(&style_file_management_history_btn_4_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_dir(&style_file_management_history_btn_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_btn_4_main_main_default, 0);
	lv_style_set_shadow_color(&style_file_management_history_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_management_history_btn_4_main_main_default, 0);
	lv_style_set_border_color(&style_file_management_history_btn_4_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_border_width(&style_file_management_history_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_file_management_history_btn_4_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_btn_4, &style_file_management_history_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_management_history_btn_4_label = lv_label_create(ui->file_management_history_btn_4);
	lv_label_set_text(ui->file_management_history_btn_4_label, "再次打印");
	lv_obj_set_style_text_color(ui->file_management_history_btn_4_label, lv_color_make(0x42, 0xbd, 0xd8), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->file_management_history_btn_4_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_management_history_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_management_history_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_management_history_btn_5
	ui->file_management_history_btn_5 = lv_btn_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_btn_5, 366, 349);
	lv_obj_set_size(ui->file_management_history_btn_5, 97, 32);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_btn_5_main_main_default
	static lv_style_t style_file_management_history_btn_5_main_main_default;
	if (style_file_management_history_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_btn_5_main_main_default);
	else
		lv_style_init(&style_file_management_history_btn_5_main_main_default);
	lv_style_set_radius(&style_file_management_history_btn_5_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_btn_5_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_color(&style_file_management_history_btn_5_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_dir(&style_file_management_history_btn_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_btn_5_main_main_default, 0);
	lv_style_set_shadow_color(&style_file_management_history_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_management_history_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_file_management_history_btn_5_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_border_width(&style_file_management_history_btn_5_main_main_default, 0);
	lv_style_set_border_opa(&style_file_management_history_btn_5_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_btn_5, &style_file_management_history_btn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_management_history_btn_5_label = lv_label_create(ui->file_management_history_btn_5);
	lv_label_set_text(ui->file_management_history_btn_5_label, "再次打印");
	lv_obj_set_style_text_color(ui->file_management_history_btn_5_label, lv_color_make(0x42, 0xbd, 0xd8), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->file_management_history_btn_5_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_management_history_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_management_history_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_management_history_btn_6
	ui->file_management_history_btn_6 = lv_btn_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_btn_6, 366, 462);
	lv_obj_set_size(ui->file_management_history_btn_6, 97, 32);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_btn_6_main_main_default
	static lv_style_t style_file_management_history_btn_6_main_main_default;
	if (style_file_management_history_btn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_btn_6_main_main_default);
	else
		lv_style_init(&style_file_management_history_btn_6_main_main_default);
	lv_style_set_radius(&style_file_management_history_btn_6_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_btn_6_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_color(&style_file_management_history_btn_6_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_dir(&style_file_management_history_btn_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_btn_6_main_main_default, 0);
	lv_style_set_shadow_color(&style_file_management_history_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_management_history_btn_6_main_main_default, 0);
	lv_style_set_border_color(&style_file_management_history_btn_6_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_border_width(&style_file_management_history_btn_6_main_main_default, 0);
	lv_style_set_border_opa(&style_file_management_history_btn_6_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_btn_6, &style_file_management_history_btn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_management_history_btn_6_label = lv_label_create(ui->file_management_history_btn_6);
	lv_label_set_text(ui->file_management_history_btn_6_label, "再次打印");
	lv_obj_set_style_text_color(ui->file_management_history_btn_6_label, lv_color_make(0x42, 0xbd, 0xd8), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->file_management_history_btn_6_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_management_history_btn_6, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_management_history_btn_6_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_management_history_btn_7
	ui->file_management_history_btn_7 = lv_btn_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_btn_7, 366, 581);
	lv_obj_set_size(ui->file_management_history_btn_7, 97, 32);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_btn_7_main_main_default
	static lv_style_t style_file_management_history_btn_7_main_main_default;
	if (style_file_management_history_btn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_btn_7_main_main_default);
	else
		lv_style_init(&style_file_management_history_btn_7_main_main_default);
	lv_style_set_radius(&style_file_management_history_btn_7_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_btn_7_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_color(&style_file_management_history_btn_7_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_dir(&style_file_management_history_btn_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_history_btn_7_main_main_default, 0);
	lv_style_set_shadow_color(&style_file_management_history_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_management_history_btn_7_main_main_default, 0);
	lv_style_set_border_color(&style_file_management_history_btn_7_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_border_width(&style_file_management_history_btn_7_main_main_default, 0);
	lv_style_set_border_opa(&style_file_management_history_btn_7_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_btn_7, &style_file_management_history_btn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_management_history_btn_7_label = lv_label_create(ui->file_management_history_btn_7);
	lv_label_set_text(ui->file_management_history_btn_7_label, "再次打印");
	lv_obj_set_style_text_color(ui->file_management_history_btn_7_label, lv_color_make(0x42, 0xbd, 0xd8), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->file_management_history_btn_7_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_management_history_btn_7, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_management_history_btn_7_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_management_history_img_6
	ui->file_management_history_img_6 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_6, 436, 615);
	lv_obj_set_size(ui->file_management_history_img_6, 24, 14);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_6_main_main_default
	static lv_style_t style_file_management_history_img_6_main_main_default;
	if (style_file_management_history_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_6_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_6_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_6_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_6, &style_file_management_history_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_history_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_history_img_6,&_Vector_2_24x14);
	lv_img_set_pivot(ui->file_management_history_img_6, 0,0);
	lv_img_set_angle(ui->file_management_history_img_6, 0);

	//Write codes file_management_history_img_8
	ui->file_management_history_img_8 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_8, 20, 85);
	lv_obj_set_size(ui->file_management_history_img_8, 96, 96);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_8_main_main_default
	static lv_style_t style_file_management_history_img_8_main_main_default;
	if (style_file_management_history_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_8_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_8_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_8_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_8, &style_file_management_history_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_img_9
	ui->file_management_history_img_9 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_9, 20, 201);
	lv_obj_set_size(ui->file_management_history_img_9, 96, 96);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_9_main_main_default
	static lv_style_t style_file_management_history_img_9_main_main_default;
	if (style_file_management_history_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_9_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_9_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_9_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_9, &style_file_management_history_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_img_10
	ui->file_management_history_img_10 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_10, 19, 317);
	lv_obj_set_size(ui->file_management_history_img_10, 96, 96);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_10_main_main_default
	static lv_style_t style_file_management_history_img_10_main_main_default;
	if (style_file_management_history_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_10_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_10_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_10_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_10, &style_file_management_history_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_img_11
	ui->file_management_history_img_11 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_11, 20, 433);
	lv_obj_set_size(ui->file_management_history_img_11, 96, 96);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_11_main_main_default
	static lv_style_t style_file_management_history_img_11_main_main_default;
	if (style_file_management_history_img_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_11_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_11_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_11_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_11_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_11, &style_file_management_history_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_img_12
	ui->file_management_history_img_12 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_12, 23, 549);
	lv_obj_set_size(ui->file_management_history_img_12, 96, 96);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_12_main_main_default
	static lv_style_t style_file_management_history_img_12_main_main_default;
	if (style_file_management_history_img_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_12_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_12_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_12_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_12_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_12, &style_file_management_history_img_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_history_img_7
	ui->file_management_history_img_7 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_7, 436, 689);
	lv_obj_set_size(ui->file_management_history_img_7, 24, 14);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_7_main_main_default
	static lv_style_t style_file_management_history_img_7_main_main_default;
	if (style_file_management_history_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_7_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_7_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_7_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_7, &style_file_management_history_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_history_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_history_img_7,&_Vector_3_24x14);
	lv_img_set_pivot(ui->file_management_history_img_7, 0,0);
	lv_img_set_angle(ui->file_management_history_img_7, 0);

	//Write codes file_management_history_img_1
	ui->file_management_history_img_1 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_1, 30, 742);
	lv_obj_set_size(ui->file_management_history_img_1, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_1_main_main_default
	static lv_style_t style_file_management_history_img_1_main_main_default;
	if (style_file_management_history_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_1_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_1_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_1_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_1, &style_file_management_history_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_history_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_history_img_1,&_home_48x48);
	lv_img_set_pivot(ui->file_management_history_img_1, 0,0);
	lv_img_set_angle(ui->file_management_history_img_1, 0);

	//Write codes file_management_history_img_2
	ui->file_management_history_img_2 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_2, 128, 742);
	lv_obj_set_size(ui->file_management_history_img_2, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_2_main_main_default
	static lv_style_t style_file_management_history_img_2_main_main_default;
	if (style_file_management_history_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_2_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_2_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_2_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_2, &style_file_management_history_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_history_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_history_img_2,&_prepare_48x48);
	lv_img_set_pivot(ui->file_management_history_img_2, 0,0);
	lv_img_set_angle(ui->file_management_history_img_2, 0);

	//Write codes file_management_history_img_3
	ui->file_management_history_img_3 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_3, 224, 742);
	lv_obj_set_size(ui->file_management_history_img_3, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_3_main_main_default
	static lv_style_t style_file_management_history_img_3_main_main_default;
	if (style_file_management_history_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_3_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_3_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_3_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_3, &style_file_management_history_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_history_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_history_img_3,&_files_48x48);
	lv_img_set_pivot(ui->file_management_history_img_3, 0,0);
	lv_img_set_angle(ui->file_management_history_img_3, 0);

	//Write codes file_management_history_img_4
	ui->file_management_history_img_4 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_4, 318, 742);
	lv_obj_set_size(ui->file_management_history_img_4, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_4_main_main_default
	static lv_style_t style_file_management_history_img_4_main_main_default;
	if (style_file_management_history_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_4_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_4_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_4_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_4, &style_file_management_history_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_history_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_history_img_4,&_seting_48x48);
	lv_img_set_pivot(ui->file_management_history_img_4, 0,0);
	lv_img_set_angle(ui->file_management_history_img_4, 0);

	//Write codes file_management_history_img_5
	ui->file_management_history_img_5 = lv_img_create(ui->file_management_history_cont_1);
	lv_obj_set_pos(ui->file_management_history_img_5, 414, 742);
	lv_obj_set_size(ui->file_management_history_img_5, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_img_5_main_main_default
	static lv_style_t style_file_management_history_img_5_main_main_default;
	if (style_file_management_history_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_img_5_main_main_default);
	else
		lv_style_init(&style_file_management_history_img_5_main_main_default);
	lv_style_set_img_recolor(&style_file_management_history_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_history_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_history_img_5_main_main_default, 255);
	lv_obj_add_style(ui->file_management_history_img_5, &style_file_management_history_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_history_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_history_img_5,&_FAQ_48x48);
	lv_img_set_pivot(ui->file_management_history_img_5, 0,0);
	lv_img_set_angle(ui->file_management_history_img_5, 0);
}