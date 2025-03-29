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


void setup_scr_settings_selftest(lv_ui *ui){

	//Write codes settings_selftest
	ui->settings_selftest = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_main_main_default
	static lv_style_t style_settings_selftest_main_main_default;
	if (style_settings_selftest_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_main_main_default);
	else
		lv_style_init(&style_settings_selftest_main_main_default);
	lv_style_set_bg_color(&style_settings_selftest_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_settings_selftest_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest, &style_settings_selftest_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_selftest_tabview_1
	ui->settings_selftest_tabview_1 = lv_tabview_create(ui->settings_selftest, LV_DIR_TOP, 50);
	lv_obj_set_pos(ui->settings_selftest_tabview_1, 0, 0);
	lv_obj_set_size(ui->settings_selftest_tabview_1, 480, 720);

	//title1
	ui->settings_selftest_tabview_1_title1 = lv_tabview_add_tab(ui->settings_selftest_tabview_1,"title1");

	//title2
	ui->settings_selftest_tabview_1_title2 = lv_tabview_add_tab(ui->settings_selftest_tabview_1,"title2");

	//title3
	ui->settings_selftest_tabview_1_title3 = lv_tabview_add_tab(ui->settings_selftest_tabview_1,"title3");

	//Title
	ui->settings_selftest_tabview_1_Title = lv_tabview_add_tab(ui->settings_selftest_tabview_1,"Title");


	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_tabview_1_main_main_default
	static lv_style_t style_settings_selftest_tabview_1_main_main_default;
	if (style_settings_selftest_tabview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_tabview_1_main_main_default);
	else
		lv_style_init(&style_settings_selftest_tabview_1_main_main_default);
	lv_style_set_bg_color(&style_settings_selftest_tabview_1_main_main_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_settings_selftest_tabview_1_main_main_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_settings_selftest_tabview_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_tabview_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_selftest_tabview_1_main_main_default, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_settings_selftest_tabview_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_selftest_tabview_1_main_main_default, 100);
	lv_style_set_text_color(&style_settings_selftest_tabview_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_settings_selftest_tabview_1_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_settings_selftest_tabview_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_settings_selftest_tabview_1_main_main_default, 16);
	lv_obj_add_style(ui->settings_selftest_tabview_1, &style_settings_selftest_tabview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_tabview_1_extra_btnm_main_default
	static lv_style_t style_settings_selftest_tabview_1_extra_btnm_main_default;
	if (style_settings_selftest_tabview_1_extra_btnm_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_tabview_1_extra_btnm_main_default);
	else
		lv_style_init(&style_settings_selftest_tabview_1_extra_btnm_main_default);
	lv_style_set_bg_color(&style_settings_selftest_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_border_color(&style_settings_selftest_tabview_1_extra_btnm_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_selftest_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_border_opa(&style_settings_selftest_tabview_1_extra_btnm_main_default, 100);
	lv_style_set_pad_left(&style_settings_selftest_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_right(&style_settings_selftest_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_top(&style_settings_selftest_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_selftest_tabview_1_extra_btnm_main_default, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_selftest_tabview_1), &style_settings_selftest_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_tabview_1_extra_btnm_items_default
	static lv_style_t style_settings_selftest_tabview_1_extra_btnm_items_default;
	if (style_settings_selftest_tabview_1_extra_btnm_items_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_tabview_1_extra_btnm_items_default);
	else
		lv_style_init(&style_settings_selftest_tabview_1_extra_btnm_items_default);
	lv_style_set_text_color(&style_settings_selftest_tabview_1_extra_btnm_items_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_settings_selftest_tabview_1_extra_btnm_items_default, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_selftest_tabview_1), &style_settings_selftest_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_selftest_tabview_1_extra_btnm_items_checked
	static lv_style_t style_settings_selftest_tabview_1_extra_btnm_items_checked;
	if (style_settings_selftest_tabview_1_extra_btnm_items_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_tabview_1_extra_btnm_items_checked);
	else
		lv_style_init(&style_settings_selftest_tabview_1_extra_btnm_items_checked);
	lv_style_set_bg_color(&style_settings_selftest_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_selftest_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_selftest_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_tabview_1_extra_btnm_items_checked, 60);
	lv_style_set_border_color(&style_settings_selftest_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_selftest_tabview_1_extra_btnm_items_checked, 4);
	lv_style_set_border_opa(&style_settings_selftest_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_side(&style_settings_selftest_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_text_color(&style_settings_selftest_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_text_font(&style_settings_selftest_tabview_1_extra_btnm_items_checked, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_selftest_tabview_1), &style_settings_selftest_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes settings_selftest_cont_1
	ui->settings_selftest_cont_1 = lv_obj_create(ui->settings_selftest);
	lv_obj_set_pos(ui->settings_selftest_cont_1, 0, 0);
	lv_obj_set_size(ui->settings_selftest_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cont_1_main_main_default
	static lv_style_t style_settings_selftest_cont_1_main_main_default;
	if (style_settings_selftest_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cont_1_main_main_default);
	else
		lv_style_init(&style_settings_selftest_cont_1_main_main_default);
	lv_style_set_radius(&style_settings_selftest_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_settings_selftest_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_selftest_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_selftest_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_selftest_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_settings_selftest_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_selftest_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_selftest_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_selftest_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_cont_1, &style_settings_selftest_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_selftest_label_2
	ui->settings_selftest_label_2 = lv_label_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_label_2, 10, 53);
	lv_obj_set_size(ui->settings_selftest_label_2, 460, 648);
	lv_label_set_text(ui->settings_selftest_label_2, "");
	lv_label_set_long_mode(ui->settings_selftest_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_selftest_label_2, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_label_2_main_main_default
	static lv_style_t style_settings_selftest_label_2_main_main_default;
	if (style_settings_selftest_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_label_2_main_main_default);
	else
		lv_style_init(&style_settings_selftest_label_2_main_main_default);
	lv_style_set_radius(&style_settings_selftest_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_selftest_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_selftest_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_settings_selftest_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_selftest_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_selftest_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_selftest_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_selftest_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_selftest_label_2_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_label_2, &style_settings_selftest_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_selftest_btn_2
	ui->settings_selftest_btn_2 = lv_btn_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_btn_2, 27, 625);
	lv_obj_set_size(ui->settings_selftest_btn_2, 426, 65);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_btn_2_main_main_default
	static lv_style_t style_settings_selftest_btn_2_main_main_default;
	if (style_settings_selftest_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_btn_2_main_main_default);
	else
		lv_style_init(&style_settings_selftest_btn_2_main_main_default);
	lv_style_set_radius(&style_settings_selftest_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_settings_selftest_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_selftest_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_selftest_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_settings_selftest_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_settings_selftest_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_settings_selftest_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_selftest_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_selftest_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->settings_selftest_btn_2, &style_settings_selftest_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->settings_selftest_btn_2_label = lv_label_create(ui->settings_selftest_btn_2);
	lv_label_set_text(ui->settings_selftest_btn_2_label, "开始检测");
	lv_obj_set_style_text_color(ui->settings_selftest_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->settings_selftest_btn_2_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->settings_selftest_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->settings_selftest_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes settings_selftest_label_5
	ui->settings_selftest_label_5 = lv_label_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_label_5, 24, 559);
	lv_obj_set_size(ui->settings_selftest_label_5, 432, 1);
	lv_label_set_text(ui->settings_selftest_label_5, "");
	lv_label_set_long_mode(ui->settings_selftest_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_selftest_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_label_5_main_main_default
	static lv_style_t style_settings_selftest_label_5_main_main_default;
	if (style_settings_selftest_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_label_5_main_main_default);
	else
		lv_style_init(&style_settings_selftest_label_5_main_main_default);
	lv_style_set_radius(&style_settings_selftest_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_label_5_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_selftest_label_5_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_selftest_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_label_5_main_main_default, 255);
	lv_style_set_text_color(&style_settings_selftest_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_selftest_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_selftest_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_selftest_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_selftest_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_selftest_label_5_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_label_5, &style_settings_selftest_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_selftest_btn_1
	ui->settings_selftest_btn_1 = lv_btn_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_btn_1, 405, 78);
	lv_obj_set_size(ui->settings_selftest_btn_1, 55, 33);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_btn_1_main_main_default
	static lv_style_t style_settings_selftest_btn_1_main_main_default;
	if (style_settings_selftest_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_btn_1_main_main_default);
	else
		lv_style_init(&style_settings_selftest_btn_1_main_main_default);
	lv_style_set_radius(&style_settings_selftest_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_selftest_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_selftest_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_settings_selftest_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_settings_selftest_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_settings_selftest_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_selftest_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_selftest_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->settings_selftest_btn_1, &style_settings_selftest_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->settings_selftest_btn_1_label = lv_label_create(ui->settings_selftest_btn_1);
	lv_label_set_text(ui->settings_selftest_btn_1_label, "全选");
	lv_obj_set_style_text_color(ui->settings_selftest_btn_1_label, lv_color_make(0x42, 0xdb, 0xd8), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->settings_selftest_btn_1_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->settings_selftest_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->settings_selftest_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes settings_selftest_label_6
	ui->settings_selftest_label_6 = lv_label_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_label_6, 24, 566);
	lv_obj_set_size(ui->settings_selftest_label_6, 379, 24);
	lv_label_set_text(ui->settings_selftest_label_6, "自检过程预计需要15分钟。");
	lv_label_set_long_mode(ui->settings_selftest_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_selftest_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_label_6_main_main_default
	static lv_style_t style_settings_selftest_label_6_main_main_default;
	if (style_settings_selftest_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_label_6_main_main_default);
	else
		lv_style_init(&style_settings_selftest_label_6_main_main_default);
	lv_style_set_radius(&style_settings_selftest_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_label_6_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_selftest_label_6_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_selftest_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_settings_selftest_label_6_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_settings_selftest_label_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_selftest_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_selftest_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_selftest_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_selftest_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_selftest_label_6_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_label_6, &style_settings_selftest_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_selftest_cb_1
	ui->settings_selftest_cb_1 = lv_checkbox_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_cb_1, 26, 154);
	lv_checkbox_set_text(ui->settings_selftest_cb_1, "开启喉管散热风扇");

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_1_main_main_default
	static lv_style_t style_settings_selftest_cb_1_main_main_default;
	if (style_settings_selftest_cb_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_1_main_main_default);
	else
		lv_style_init(&style_settings_selftest_cb_1_main_main_default);
	lv_style_set_radius(&style_settings_selftest_cb_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_1_main_main_default, 0);
	lv_style_set_text_color(&style_settings_selftest_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_selftest_cb_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_selftest_cb_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_cb_1, &style_settings_selftest_cb_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_1_main_indicator_default
	static lv_style_t style_settings_selftest_cb_1_main_indicator_default;
	if (style_settings_selftest_cb_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_1_main_indicator_default);
	else
		lv_style_init(&style_settings_selftest_cb_1_main_indicator_default);
	lv_style_set_radius(&style_settings_selftest_cb_1_main_indicator_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_1_main_indicator_default, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_1_main_indicator_default, 3);
	lv_obj_add_style(ui->settings_selftest_cb_1, &style_settings_selftest_cb_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_selftest_cb_1_main_indicator_checked
	static lv_style_t style_settings_selftest_cb_1_main_indicator_checked;
	if (style_settings_selftest_cb_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_1_main_indicator_checked);
	else
		lv_style_init(&style_settings_selftest_cb_1_main_indicator_checked);
	lv_style_set_radius(&style_settings_selftest_cb_1_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_1_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_1_main_indicator_checked, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_1_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_1_main_indicator_checked, 3);
	lv_obj_add_style(ui->settings_selftest_cb_1, &style_settings_selftest_cb_1_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_selftest_cb_3
	ui->settings_selftest_cb_3 = lv_checkbox_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_cb_3, 26, 233);
	lv_checkbox_set_text(ui->settings_selftest_cb_3, "开启模型冷却风扇");

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_3_main_main_default
	static lv_style_t style_settings_selftest_cb_3_main_main_default;
	if (style_settings_selftest_cb_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_3_main_main_default);
	else
		lv_style_init(&style_settings_selftest_cb_3_main_main_default);
	lv_style_set_radius(&style_settings_selftest_cb_3_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_3_main_main_default, 0);
	lv_style_set_text_color(&style_settings_selftest_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_selftest_cb_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_selftest_cb_3_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_cb_3, &style_settings_selftest_cb_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_3_main_indicator_default
	static lv_style_t style_settings_selftest_cb_3_main_indicator_default;
	if (style_settings_selftest_cb_3_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_3_main_indicator_default);
	else
		lv_style_init(&style_settings_selftest_cb_3_main_indicator_default);
	lv_style_set_radius(&style_settings_selftest_cb_3_main_indicator_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_3_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_3_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_3_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_3_main_indicator_default, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_3_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_3_main_indicator_default, 3);
	lv_obj_add_style(ui->settings_selftest_cb_3, &style_settings_selftest_cb_3_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_selftest_cb_3_main_indicator_checked
	static lv_style_t style_settings_selftest_cb_3_main_indicator_checked;
	if (style_settings_selftest_cb_3_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_3_main_indicator_checked);
	else
		lv_style_init(&style_settings_selftest_cb_3_main_indicator_checked);
	lv_style_set_radius(&style_settings_selftest_cb_3_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_3_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_3_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_3_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_3_main_indicator_checked, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_3_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_3_main_indicator_checked, 3);
	lv_obj_add_style(ui->settings_selftest_cb_3, &style_settings_selftest_cb_3_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_selftest_cb_5
	ui->settings_selftest_cb_5 = lv_checkbox_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_cb_5, 26, 310);
	lv_checkbox_set_text(ui->settings_selftest_cb_5, "喷头PID校准");

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_5_main_main_default
	static lv_style_t style_settings_selftest_cb_5_main_main_default;
	if (style_settings_selftest_cb_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_5_main_main_default);
	else
		lv_style_init(&style_settings_selftest_cb_5_main_main_default);
	lv_style_set_radius(&style_settings_selftest_cb_5_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_5_main_main_default, 0);
	lv_style_set_text_color(&style_settings_selftest_cb_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_selftest_cb_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_selftest_cb_5_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_cb_5, &style_settings_selftest_cb_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_5_main_indicator_default
	static lv_style_t style_settings_selftest_cb_5_main_indicator_default;
	if (style_settings_selftest_cb_5_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_5_main_indicator_default);
	else
		lv_style_init(&style_settings_selftest_cb_5_main_indicator_default);
	lv_style_set_radius(&style_settings_selftest_cb_5_main_indicator_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_5_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_5_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_5_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_5_main_indicator_default, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_5_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_5_main_indicator_default, 3);
	lv_obj_add_style(ui->settings_selftest_cb_5, &style_settings_selftest_cb_5_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_selftest_cb_5_main_indicator_checked
	static lv_style_t style_settings_selftest_cb_5_main_indicator_checked;
	if (style_settings_selftest_cb_5_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_5_main_indicator_checked);
	else
		lv_style_init(&style_settings_selftest_cb_5_main_indicator_checked);
	lv_style_set_radius(&style_settings_selftest_cb_5_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_5_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_5_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_5_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_5_main_indicator_checked, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_5_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_5_main_indicator_checked, 3);
	lv_obj_add_style(ui->settings_selftest_cb_5, &style_settings_selftest_cb_5_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_selftest_cb_7
	ui->settings_selftest_cb_7 = lv_checkbox_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_cb_7, 26, 391);
	lv_checkbox_set_text(ui->settings_selftest_cb_7, "热床PID校准");

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_7_main_main_default
	static lv_style_t style_settings_selftest_cb_7_main_main_default;
	if (style_settings_selftest_cb_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_7_main_main_default);
	else
		lv_style_init(&style_settings_selftest_cb_7_main_main_default);
	lv_style_set_radius(&style_settings_selftest_cb_7_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_7_main_main_default, 0);
	lv_style_set_text_color(&style_settings_selftest_cb_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_selftest_cb_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_selftest_cb_7_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_cb_7, &style_settings_selftest_cb_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_7_main_indicator_default
	static lv_style_t style_settings_selftest_cb_7_main_indicator_default;
	if (style_settings_selftest_cb_7_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_7_main_indicator_default);
	else
		lv_style_init(&style_settings_selftest_cb_7_main_indicator_default);
	lv_style_set_radius(&style_settings_selftest_cb_7_main_indicator_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_7_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_7_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_7_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_7_main_indicator_default, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_7_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_7_main_indicator_default, 3);
	lv_obj_add_style(ui->settings_selftest_cb_7, &style_settings_selftest_cb_7_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_selftest_cb_7_main_indicator_checked
	static lv_style_t style_settings_selftest_cb_7_main_indicator_checked;
	if (style_settings_selftest_cb_7_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_7_main_indicator_checked);
	else
		lv_style_init(&style_settings_selftest_cb_7_main_indicator_checked);
	lv_style_set_radius(&style_settings_selftest_cb_7_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_7_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_7_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_7_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_7_main_indicator_checked, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_7_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_7_main_indicator_checked, 3);
	lv_obj_add_style(ui->settings_selftest_cb_7, &style_settings_selftest_cb_7_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_selftest_cb_9
	ui->settings_selftest_cb_9 = lv_checkbox_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_cb_9, 26, 470);
	lv_checkbox_set_text(ui->settings_selftest_cb_9, "振动补偿");

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_9_main_main_default
	static lv_style_t style_settings_selftest_cb_9_main_main_default;
	if (style_settings_selftest_cb_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_9_main_main_default);
	else
		lv_style_init(&style_settings_selftest_cb_9_main_main_default);
	lv_style_set_radius(&style_settings_selftest_cb_9_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_9_main_main_default, 0);
	lv_style_set_text_color(&style_settings_selftest_cb_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_selftest_cb_9_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_selftest_cb_9_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_cb_9, &style_settings_selftest_cb_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_9_main_indicator_default
	static lv_style_t style_settings_selftest_cb_9_main_indicator_default;
	if (style_settings_selftest_cb_9_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_9_main_indicator_default);
	else
		lv_style_init(&style_settings_selftest_cb_9_main_indicator_default);
	lv_style_set_radius(&style_settings_selftest_cb_9_main_indicator_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_9_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_9_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_9_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_9_main_indicator_default, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_9_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_9_main_indicator_default, 3);
	lv_obj_add_style(ui->settings_selftest_cb_9, &style_settings_selftest_cb_9_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_selftest_cb_9_main_indicator_checked
	static lv_style_t style_settings_selftest_cb_9_main_indicator_checked;
	if (style_settings_selftest_cb_9_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_9_main_indicator_checked);
	else
		lv_style_init(&style_settings_selftest_cb_9_main_indicator_checked);
	lv_style_set_radius(&style_settings_selftest_cb_9_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_9_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_9_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_9_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_9_main_indicator_checked, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_9_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_9_main_indicator_checked, 3);
	lv_obj_add_style(ui->settings_selftest_cb_9, &style_settings_selftest_cb_9_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_selftest_cb_8
	ui->settings_selftest_cb_8 = lv_checkbox_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_cb_8, 275, 391);
	lv_checkbox_set_text(ui->settings_selftest_cb_8, "自动调平");

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_8_main_main_default
	static lv_style_t style_settings_selftest_cb_8_main_main_default;
	if (style_settings_selftest_cb_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_8_main_main_default);
	else
		lv_style_init(&style_settings_selftest_cb_8_main_main_default);
	lv_style_set_radius(&style_settings_selftest_cb_8_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_8_main_main_default, 0);
	lv_style_set_text_color(&style_settings_selftest_cb_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_selftest_cb_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_selftest_cb_8_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_cb_8, &style_settings_selftest_cb_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_8_main_indicator_default
	static lv_style_t style_settings_selftest_cb_8_main_indicator_default;
	if (style_settings_selftest_cb_8_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_8_main_indicator_default);
	else
		lv_style_init(&style_settings_selftest_cb_8_main_indicator_default);
	lv_style_set_radius(&style_settings_selftest_cb_8_main_indicator_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_8_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_8_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_8_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_8_main_indicator_default, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_8_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_8_main_indicator_default, 3);
	lv_obj_add_style(ui->settings_selftest_cb_8, &style_settings_selftest_cb_8_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_selftest_cb_8_main_indicator_checked
	static lv_style_t style_settings_selftest_cb_8_main_indicator_checked;
	if (style_settings_selftest_cb_8_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_8_main_indicator_checked);
	else
		lv_style_init(&style_settings_selftest_cb_8_main_indicator_checked);
	lv_style_set_radius(&style_settings_selftest_cb_8_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_8_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_8_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_8_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_8_main_indicator_checked, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_8_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_8_main_indicator_checked, 3);
	lv_obj_add_style(ui->settings_selftest_cb_8, &style_settings_selftest_cb_8_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_selftest_cb_6
	ui->settings_selftest_cb_6 = lv_checkbox_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_cb_6, 275, 310);
	lv_checkbox_set_text(ui->settings_selftest_cb_6, "断料检测");

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_6_main_main_default
	static lv_style_t style_settings_selftest_cb_6_main_main_default;
	if (style_settings_selftest_cb_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_6_main_main_default);
	else
		lv_style_init(&style_settings_selftest_cb_6_main_main_default);
	lv_style_set_radius(&style_settings_selftest_cb_6_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_6_main_main_default, 0);
	lv_style_set_text_color(&style_settings_selftest_cb_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_selftest_cb_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_selftest_cb_6_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_cb_6, &style_settings_selftest_cb_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_6_main_indicator_default
	static lv_style_t style_settings_selftest_cb_6_main_indicator_default;
	if (style_settings_selftest_cb_6_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_6_main_indicator_default);
	else
		lv_style_init(&style_settings_selftest_cb_6_main_indicator_default);
	lv_style_set_radius(&style_settings_selftest_cb_6_main_indicator_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_6_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_6_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_6_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_6_main_indicator_default, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_6_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_6_main_indicator_default, 3);
	lv_obj_add_style(ui->settings_selftest_cb_6, &style_settings_selftest_cb_6_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_selftest_cb_6_main_indicator_checked
	static lv_style_t style_settings_selftest_cb_6_main_indicator_checked;
	if (style_settings_selftest_cb_6_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_6_main_indicator_checked);
	else
		lv_style_init(&style_settings_selftest_cb_6_main_indicator_checked);
	lv_style_set_radius(&style_settings_selftest_cb_6_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_6_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_6_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_6_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_6_main_indicator_checked, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_6_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_6_main_indicator_checked, 3);
	lv_obj_add_style(ui->settings_selftest_cb_6, &style_settings_selftest_cb_6_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_selftest_cb_4
	ui->settings_selftest_cb_4 = lv_checkbox_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_cb_4, 275, 233);
	lv_checkbox_set_text(ui->settings_selftest_cb_4, "探头检测");

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_4_main_main_default
	static lv_style_t style_settings_selftest_cb_4_main_main_default;
	if (style_settings_selftest_cb_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_4_main_main_default);
	else
		lv_style_init(&style_settings_selftest_cb_4_main_main_default);
	lv_style_set_radius(&style_settings_selftest_cb_4_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_4_main_main_default, 0);
	lv_style_set_text_color(&style_settings_selftest_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_selftest_cb_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_selftest_cb_4_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_cb_4, &style_settings_selftest_cb_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_4_main_indicator_default
	static lv_style_t style_settings_selftest_cb_4_main_indicator_default;
	if (style_settings_selftest_cb_4_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_4_main_indicator_default);
	else
		lv_style_init(&style_settings_selftest_cb_4_main_indicator_default);
	lv_style_set_radius(&style_settings_selftest_cb_4_main_indicator_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_4_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_4_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_4_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_4_main_indicator_default, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_4_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_4_main_indicator_default, 3);
	lv_obj_add_style(ui->settings_selftest_cb_4, &style_settings_selftest_cb_4_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_selftest_cb_4_main_indicator_checked
	static lv_style_t style_settings_selftest_cb_4_main_indicator_checked;
	if (style_settings_selftest_cb_4_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_4_main_indicator_checked);
	else
		lv_style_init(&style_settings_selftest_cb_4_main_indicator_checked);
	lv_style_set_radius(&style_settings_selftest_cb_4_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_4_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_4_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_4_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_4_main_indicator_checked, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_4_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_4_main_indicator_checked, 3);
	lv_obj_add_style(ui->settings_selftest_cb_4, &style_settings_selftest_cb_4_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_selftest_cb_2
	ui->settings_selftest_cb_2 = lv_checkbox_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_cb_2, 275, 154);
	lv_checkbox_set_text(ui->settings_selftest_cb_2, "归位检测");

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_2_main_main_default
	static lv_style_t style_settings_selftest_cb_2_main_main_default;
	if (style_settings_selftest_cb_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_2_main_main_default);
	else
		lv_style_init(&style_settings_selftest_cb_2_main_main_default);
	lv_style_set_radius(&style_settings_selftest_cb_2_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_2_main_main_default, 0);
	lv_style_set_text_color(&style_settings_selftest_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_selftest_cb_2_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_selftest_cb_2_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_cb_2, &style_settings_selftest_cb_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_cb_2_main_indicator_default
	static lv_style_t style_settings_selftest_cb_2_main_indicator_default;
	if (style_settings_selftest_cb_2_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_2_main_indicator_default);
	else
		lv_style_init(&style_settings_selftest_cb_2_main_indicator_default);
	lv_style_set_radius(&style_settings_selftest_cb_2_main_indicator_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_2_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_2_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_2_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_2_main_indicator_default, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_2_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_2_main_indicator_default, 3);
	lv_obj_add_style(ui->settings_selftest_cb_2, &style_settings_selftest_cb_2_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_selftest_cb_2_main_indicator_checked
	static lv_style_t style_settings_selftest_cb_2_main_indicator_checked;
	if (style_settings_selftest_cb_2_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_cb_2_main_indicator_checked);
	else
		lv_style_init(&style_settings_selftest_cb_2_main_indicator_checked);
	lv_style_set_radius(&style_settings_selftest_cb_2_main_indicator_checked, 0);
	lv_style_set_bg_color(&style_settings_selftest_cb_2_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_selftest_cb_2_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_selftest_cb_2_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_cb_2_main_indicator_checked, 0);
	lv_style_set_border_color(&style_settings_selftest_cb_2_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_selftest_cb_2_main_indicator_checked, 3);
	lv_obj_add_style(ui->settings_selftest_cb_2, &style_settings_selftest_cb_2_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_selftest_label_3
	ui->settings_selftest_label_3 = lv_label_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_label_3, 26, 78);
	lv_obj_set_size(ui->settings_selftest_label_3, 96, 28);
	lv_label_set_text(ui->settings_selftest_label_3, "检测选项");
	lv_label_set_long_mode(ui->settings_selftest_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_selftest_label_3, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_label_3_main_main_default
	static lv_style_t style_settings_selftest_label_3_main_main_default;
	if (style_settings_selftest_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_label_3_main_main_default);
	else
		lv_style_init(&style_settings_selftest_label_3_main_main_default);
	lv_style_set_radius(&style_settings_selftest_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_selftest_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_selftest_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_settings_selftest_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_selftest_label_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_selftest_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_selftest_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_selftest_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_selftest_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_selftest_label_3_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_label_3, &style_settings_selftest_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_selftest_label_4
	ui->settings_selftest_label_4 = lv_label_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_label_4, 24, 127);
	lv_obj_set_size(ui->settings_selftest_label_4, 432, 1);
	lv_label_set_text(ui->settings_selftest_label_4, "");
	lv_label_set_long_mode(ui->settings_selftest_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_selftest_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_label_4_main_main_default
	static lv_style_t style_settings_selftest_label_4_main_main_default;
	if (style_settings_selftest_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_label_4_main_main_default);
	else
		lv_style_init(&style_settings_selftest_label_4_main_main_default);
	lv_style_set_radius(&style_settings_selftest_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_label_4_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_selftest_label_4_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_selftest_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_label_4_main_main_default, 255);
	lv_style_set_text_color(&style_settings_selftest_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_selftest_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_selftest_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_selftest_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_selftest_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_selftest_label_4_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_label_4, &style_settings_selftest_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_selftest_label_1
	ui->settings_selftest_label_1 = lv_label_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_label_1, 0, 719);
	lv_obj_set_size(ui->settings_selftest_label_1, 480, 80);
	lv_label_set_text(ui->settings_selftest_label_1, "");
	lv_label_set_long_mode(ui->settings_selftest_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_selftest_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_label_1_main_main_default
	static lv_style_t style_settings_selftest_label_1_main_main_default;
	if (style_settings_selftest_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_label_1_main_main_default);
	else
		lv_style_init(&style_settings_selftest_label_1_main_main_default);
	lv_style_set_radius(&style_settings_selftest_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_selftest_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_settings_selftest_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_settings_selftest_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_selftest_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_settings_selftest_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_selftest_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_selftest_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_selftest_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_selftest_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_selftest_label_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_selftest_label_1, &style_settings_selftest_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_selftest_img_1
	ui->settings_selftest_img_1 = lv_img_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_img_1, 30, 742);
	lv_obj_set_size(ui->settings_selftest_img_1, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_img_1_main_main_default
	static lv_style_t style_settings_selftest_img_1_main_main_default;
	if (style_settings_selftest_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_img_1_main_main_default);
	else
		lv_style_init(&style_settings_selftest_img_1_main_main_default);
	lv_style_set_img_recolor(&style_settings_selftest_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_selftest_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_selftest_img_1_main_main_default, 255);
	lv_obj_add_style(ui->settings_selftest_img_1, &style_settings_selftest_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_selftest_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_selftest_img_1,&_home_48x48);
	lv_img_set_pivot(ui->settings_selftest_img_1, 0,0);
	lv_img_set_angle(ui->settings_selftest_img_1, 0);

	//Write codes settings_selftest_img_2
	ui->settings_selftest_img_2 = lv_img_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_img_2, 128, 742);
	lv_obj_set_size(ui->settings_selftest_img_2, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_img_2_main_main_default
	static lv_style_t style_settings_selftest_img_2_main_main_default;
	if (style_settings_selftest_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_img_2_main_main_default);
	else
		lv_style_init(&style_settings_selftest_img_2_main_main_default);
	lv_style_set_img_recolor(&style_settings_selftest_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_selftest_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_selftest_img_2_main_main_default, 255);
	lv_obj_add_style(ui->settings_selftest_img_2, &style_settings_selftest_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_selftest_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_selftest_img_2,&_prepare_48x48);
	lv_img_set_pivot(ui->settings_selftest_img_2, 0,0);
	lv_img_set_angle(ui->settings_selftest_img_2, 0);

	//Write codes settings_selftest_img_3
	ui->settings_selftest_img_3 = lv_img_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_img_3, 224, 742);
	lv_obj_set_size(ui->settings_selftest_img_3, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_img_3_main_main_default
	static lv_style_t style_settings_selftest_img_3_main_main_default;
	if (style_settings_selftest_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_img_3_main_main_default);
	else
		lv_style_init(&style_settings_selftest_img_3_main_main_default);
	lv_style_set_img_recolor(&style_settings_selftest_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_selftest_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_selftest_img_3_main_main_default, 255);
	lv_obj_add_style(ui->settings_selftest_img_3, &style_settings_selftest_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_selftest_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_selftest_img_3,&_files_48x48);
	lv_img_set_pivot(ui->settings_selftest_img_3, 0,0);
	lv_img_set_angle(ui->settings_selftest_img_3, 0);

	//Write codes settings_selftest_img_4
	ui->settings_selftest_img_4 = lv_img_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_img_4, 318, 742);
	lv_obj_set_size(ui->settings_selftest_img_4, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_img_4_main_main_default
	static lv_style_t style_settings_selftest_img_4_main_main_default;
	if (style_settings_selftest_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_img_4_main_main_default);
	else
		lv_style_init(&style_settings_selftest_img_4_main_main_default);
	lv_style_set_img_recolor(&style_settings_selftest_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_selftest_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_selftest_img_4_main_main_default, 255);
	lv_obj_add_style(ui->settings_selftest_img_4, &style_settings_selftest_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_selftest_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_selftest_img_4,&_seting_48x48);
	lv_img_set_pivot(ui->settings_selftest_img_4, 0,0);
	lv_img_set_angle(ui->settings_selftest_img_4, 0);

	//Write codes settings_selftest_img_5
	ui->settings_selftest_img_5 = lv_img_create(ui->settings_selftest_cont_1);
	lv_obj_set_pos(ui->settings_selftest_img_5, 414, 742);
	lv_obj_set_size(ui->settings_selftest_img_5, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_selftest_img_5_main_main_default
	static lv_style_t style_settings_selftest_img_5_main_main_default;
	if (style_settings_selftest_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_selftest_img_5_main_main_default);
	else
		lv_style_init(&style_settings_selftest_img_5_main_main_default);
	lv_style_set_img_recolor(&style_settings_selftest_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_selftest_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_selftest_img_5_main_main_default, 255);
	lv_obj_add_style(ui->settings_selftest_img_5, &style_settings_selftest_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_selftest_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_selftest_img_5,&_FAQ_48x48);
	lv_img_set_pivot(ui->settings_selftest_img_5, 0,0);
	lv_img_set_angle(ui->settings_selftest_img_5, 0);
}
