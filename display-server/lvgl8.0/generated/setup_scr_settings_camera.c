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


void setup_scr_settings_camera(lv_ui *ui){

	//Write codes settings_camera
	ui->settings_camera = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_main_main_default
	static lv_style_t style_settings_camera_main_main_default;
	if (style_settings_camera_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_main_main_default);
	else
		lv_style_init(&style_settings_camera_main_main_default);
	lv_style_set_bg_color(&style_settings_camera_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_settings_camera_main_main_default, 0);
	lv_obj_add_style(ui->settings_camera, &style_settings_camera_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_tabview_1
	ui->settings_camera_tabview_1 = lv_tabview_create(ui->settings_camera, LV_DIR_TOP, 50);
	lv_obj_set_pos(ui->settings_camera_tabview_1, 0, 0);
	lv_obj_set_size(ui->settings_camera_tabview_1, 480, 720);

	//title1
	ui->settings_camera_tabview_1_title1 = lv_tabview_add_tab(ui->settings_camera_tabview_1,"title1");

	//title2
	ui->settings_camera_tabview_1_title2 = lv_tabview_add_tab(ui->settings_camera_tabview_1,"title2");

	//title3
	ui->settings_camera_tabview_1_title3 = lv_tabview_add_tab(ui->settings_camera_tabview_1,"title3");

	//Title
	ui->settings_camera_tabview_1_Title = lv_tabview_add_tab(ui->settings_camera_tabview_1,"Title");


	//Write style state: LV_STATE_DEFAULT for style_settings_camera_tabview_1_main_main_default
	static lv_style_t style_settings_camera_tabview_1_main_main_default;
	if (style_settings_camera_tabview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_tabview_1_main_main_default);
	else
		lv_style_init(&style_settings_camera_tabview_1_main_main_default);
	lv_style_set_bg_color(&style_settings_camera_tabview_1_main_main_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_settings_camera_tabview_1_main_main_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_settings_camera_tabview_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_tabview_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_camera_tabview_1_main_main_default, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_settings_camera_tabview_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_camera_tabview_1_main_main_default, 100);
	lv_style_set_text_color(&style_settings_camera_tabview_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_settings_camera_tabview_1_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_settings_camera_tabview_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_settings_camera_tabview_1_main_main_default, 16);
	lv_obj_add_style(ui->settings_camera_tabview_1, &style_settings_camera_tabview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_tabview_1_extra_btnm_main_default
	static lv_style_t style_settings_camera_tabview_1_extra_btnm_main_default;
	if (style_settings_camera_tabview_1_extra_btnm_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_tabview_1_extra_btnm_main_default);
	else
		lv_style_init(&style_settings_camera_tabview_1_extra_btnm_main_default);
	lv_style_set_bg_color(&style_settings_camera_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_camera_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_camera_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_border_color(&style_settings_camera_tabview_1_extra_btnm_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_camera_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_border_opa(&style_settings_camera_tabview_1_extra_btnm_main_default, 100);
	lv_style_set_pad_left(&style_settings_camera_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_right(&style_settings_camera_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_top(&style_settings_camera_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_camera_tabview_1_extra_btnm_main_default, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_camera_tabview_1), &style_settings_camera_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_tabview_1_extra_btnm_items_default
	static lv_style_t style_settings_camera_tabview_1_extra_btnm_items_default;
	if (style_settings_camera_tabview_1_extra_btnm_items_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_tabview_1_extra_btnm_items_default);
	else
		lv_style_init(&style_settings_camera_tabview_1_extra_btnm_items_default);
	lv_style_set_text_color(&style_settings_camera_tabview_1_extra_btnm_items_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_settings_camera_tabview_1_extra_btnm_items_default, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_camera_tabview_1), &style_settings_camera_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_camera_tabview_1_extra_btnm_items_checked
	static lv_style_t style_settings_camera_tabview_1_extra_btnm_items_checked;
	if (style_settings_camera_tabview_1_extra_btnm_items_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_tabview_1_extra_btnm_items_checked);
	else
		lv_style_init(&style_settings_camera_tabview_1_extra_btnm_items_checked);
	lv_style_set_bg_color(&style_settings_camera_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_camera_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_camera_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_tabview_1_extra_btnm_items_checked, 60);
	lv_style_set_border_color(&style_settings_camera_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_camera_tabview_1_extra_btnm_items_checked, 4);
	lv_style_set_border_opa(&style_settings_camera_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_side(&style_settings_camera_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_text_color(&style_settings_camera_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_text_font(&style_settings_camera_tabview_1_extra_btnm_items_checked, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_camera_tabview_1), &style_settings_camera_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes settings_camera_cont_1
	ui->settings_camera_cont_1 = lv_obj_create(ui->settings_camera);
	lv_obj_set_pos(ui->settings_camera_cont_1, 0, 0);
	lv_obj_set_size(ui->settings_camera_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_cont_1_main_main_default
	static lv_style_t style_settings_camera_cont_1_main_main_default;
	if (style_settings_camera_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_cont_1_main_main_default);
	else
		lv_style_init(&style_settings_camera_cont_1_main_main_default);
	lv_style_set_radius(&style_settings_camera_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_settings_camera_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_settings_camera_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_camera_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_camera_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_camera_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_settings_camera_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_camera_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_camera_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_camera_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_camera_cont_1, &style_settings_camera_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_label_2
	ui->settings_camera_label_2 = lv_label_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_label_2, 9, 52);
	lv_obj_set_size(ui->settings_camera_label_2, 460, 648);
	lv_label_set_text(ui->settings_camera_label_2, "");
	lv_label_set_long_mode(ui->settings_camera_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_camera_label_2, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_label_2_main_main_default
	static lv_style_t style_settings_camera_label_2_main_main_default;
	if (style_settings_camera_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_label_2_main_main_default);
	else
		lv_style_init(&style_settings_camera_label_2_main_main_default);
	lv_style_set_radius(&style_settings_camera_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_camera_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_camera_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_settings_camera_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_camera_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_camera_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_camera_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_camera_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_camera_label_2_main_main_default, 0);
	lv_obj_add_style(ui->settings_camera_label_2, &style_settings_camera_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_img_6
	ui->settings_camera_img_6 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_6, 24, 76);
	lv_obj_set_size(ui->settings_camera_img_6, 432, 324);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_6_main_main_default
	static lv_style_t style_settings_camera_img_6_main_main_default;
	if (style_settings_camera_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_6_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_6_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_6_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_6, &style_settings_camera_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_btn_1
	ui->settings_camera_btn_1 = lv_btn_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_btn_1, 409, 420);
	lv_obj_set_size(ui->settings_camera_btn_1, 50, 50);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_btn_1_main_main_default
	static lv_style_t style_settings_camera_btn_1_main_main_default;
	if (style_settings_camera_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_btn_1_main_main_default);
	else
		lv_style_init(&style_settings_camera_btn_1_main_main_default);
	lv_style_set_radius(&style_settings_camera_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_camera_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_camera_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_settings_camera_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_settings_camera_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_settings_camera_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_camera_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_camera_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_btn_1, &style_settings_camera_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->settings_camera_btn_1_label = lv_label_create(ui->settings_camera_btn_1);
	lv_label_set_text(ui->settings_camera_btn_1_label, "");
	lv_obj_set_style_text_color(ui->settings_camera_btn_1_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->settings_camera_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->settings_camera_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes settings_camera_btn_2
	ui->settings_camera_btn_2 = lv_btn_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_btn_2, 409, 504);
	lv_obj_set_size(ui->settings_camera_btn_2, 50, 50);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_btn_2_main_main_default
	static lv_style_t style_settings_camera_btn_2_main_main_default;
	if (style_settings_camera_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_btn_2_main_main_default);
	else
		lv_style_init(&style_settings_camera_btn_2_main_main_default);
	lv_style_set_radius(&style_settings_camera_btn_2_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_camera_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_camera_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_btn_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_settings_camera_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_settings_camera_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_settings_camera_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_camera_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_camera_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_btn_2, &style_settings_camera_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->settings_camera_btn_2_label = lv_label_create(ui->settings_camera_btn_2);
	lv_label_set_text(ui->settings_camera_btn_2_label, "");
	lv_obj_set_style_text_color(ui->settings_camera_btn_2_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->settings_camera_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->settings_camera_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes settings_camera_btn_3
	ui->settings_camera_btn_3 = lv_btn_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_btn_3, 409, 585);
	lv_obj_set_size(ui->settings_camera_btn_3, 50, 50);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_btn_3_main_main_default
	static lv_style_t style_settings_camera_btn_3_main_main_default;
	if (style_settings_camera_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_btn_3_main_main_default);
	else
		lv_style_init(&style_settings_camera_btn_3_main_main_default);
	lv_style_set_radius(&style_settings_camera_btn_3_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_camera_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_camera_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_btn_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_settings_camera_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_settings_camera_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_settings_camera_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_camera_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_camera_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_btn_3, &style_settings_camera_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->settings_camera_btn_3_label = lv_label_create(ui->settings_camera_btn_3);
	lv_label_set_text(ui->settings_camera_btn_3_label, "");
	lv_obj_set_style_text_color(ui->settings_camera_btn_3_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->settings_camera_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->settings_camera_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes settings_camera_label_3
	ui->settings_camera_label_3 = lv_label_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_label_3, 176, 277);
	lv_obj_set_size(ui->settings_camera_label_3, 159, 33);
	lv_label_set_text(ui->settings_camera_label_3, "摄像头未启用");
	lv_label_set_long_mode(ui->settings_camera_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_camera_label_3, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_label_3_main_main_default
	static lv_style_t style_settings_camera_label_3_main_main_default;
	if (style_settings_camera_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_label_3_main_main_default);
	else
		lv_style_init(&style_settings_camera_label_3_main_main_default);
	lv_style_set_radius(&style_settings_camera_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_camera_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_camera_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_settings_camera_label_3_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_settings_camera_label_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_camera_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_camera_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_camera_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_camera_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_camera_label_3_main_main_default, 0);
	lv_obj_add_style(ui->settings_camera_label_3, &style_settings_camera_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_label_4
	ui->settings_camera_label_4 = lv_label_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_label_4, 80, 432);
	lv_obj_set_size(ui->settings_camera_label_4, 263, 24);
	lv_label_set_text(ui->settings_camera_label_4, "视频列表");
	lv_label_set_long_mode(ui->settings_camera_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_camera_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_label_4_main_main_default
	static lv_style_t style_settings_camera_label_4_main_main_default;
	if (style_settings_camera_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_label_4_main_main_default);
	else
		lv_style_init(&style_settings_camera_label_4_main_main_default);
	lv_style_set_radius(&style_settings_camera_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_camera_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_camera_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_settings_camera_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_camera_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_camera_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_camera_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_camera_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_camera_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_camera_label_4_main_main_default, 0);
	lv_obj_add_style(ui->settings_camera_label_4, &style_settings_camera_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_label_5
	ui->settings_camera_label_5 = lv_label_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_label_5, 80, 509);
	lv_obj_set_size(ui->settings_camera_label_5, 260, 24);
	lv_label_set_text(ui->settings_camera_label_5, "摄像头设置");
	lv_label_set_long_mode(ui->settings_camera_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_camera_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_label_5_main_main_default
	static lv_style_t style_settings_camera_label_5_main_main_default;
	if (style_settings_camera_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_label_5_main_main_default);
	else
		lv_style_init(&style_settings_camera_label_5_main_main_default);
	lv_style_set_radius(&style_settings_camera_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_label_5_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_camera_label_5_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_camera_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_settings_camera_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_camera_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_camera_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_camera_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_camera_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_camera_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_camera_label_5_main_main_default, 0);
	lv_obj_add_style(ui->settings_camera_label_5, &style_settings_camera_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_label_6
	ui->settings_camera_label_6 = lv_label_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_label_6, 80, 590);
	lv_obj_set_size(ui->settings_camera_label_6, 260, 24);
	lv_label_set_text(ui->settings_camera_label_6, "AI检测");
	lv_label_set_long_mode(ui->settings_camera_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_camera_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_label_6_main_main_default
	static lv_style_t style_settings_camera_label_6_main_main_default;
	if (style_settings_camera_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_label_6_main_main_default);
	else
		lv_style_init(&style_settings_camera_label_6_main_main_default);
	lv_style_set_radius(&style_settings_camera_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_label_6_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_camera_label_6_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_camera_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_settings_camera_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_camera_label_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_camera_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_camera_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_camera_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_camera_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_camera_label_6_main_main_default, 0);
	lv_obj_add_style(ui->settings_camera_label_6, &style_settings_camera_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_label_7
	ui->settings_camera_label_7 = lv_label_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_label_7, 27, 481);
	lv_obj_set_size(ui->settings_camera_label_7, 426, 1);
	lv_label_set_text(ui->settings_camera_label_7, "");
	lv_label_set_long_mode(ui->settings_camera_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_camera_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_label_7_main_main_default
	static lv_style_t style_settings_camera_label_7_main_main_default;
	if (style_settings_camera_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_label_7_main_main_default);
	else
		lv_style_init(&style_settings_camera_label_7_main_main_default);
	lv_style_set_radius(&style_settings_camera_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_label_7_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_camera_label_7_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_camera_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_label_7_main_main_default, 255);
	lv_style_set_text_color(&style_settings_camera_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_camera_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_camera_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_camera_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_camera_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_camera_label_7_main_main_default, 0);
	lv_obj_add_style(ui->settings_camera_label_7, &style_settings_camera_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_label_8
	ui->settings_camera_label_8 = lv_label_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_label_8, 27, 562);
	lv_obj_set_size(ui->settings_camera_label_8, 426, 1);
	lv_label_set_text(ui->settings_camera_label_8, "");
	lv_label_set_long_mode(ui->settings_camera_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_camera_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_label_8_main_main_default
	static lv_style_t style_settings_camera_label_8_main_main_default;
	if (style_settings_camera_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_label_8_main_main_default);
	else
		lv_style_init(&style_settings_camera_label_8_main_main_default);
	lv_style_set_radius(&style_settings_camera_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_label_8_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_camera_label_8_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_camera_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_label_8_main_main_default, 255);
	lv_style_set_text_color(&style_settings_camera_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_camera_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_camera_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_camera_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_camera_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_camera_label_8_main_main_default, 0);
	lv_obj_add_style(ui->settings_camera_label_8, &style_settings_camera_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_label_9
	ui->settings_camera_label_9 = lv_label_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_label_9, 27, 643);
	lv_obj_set_size(ui->settings_camera_label_9, 426, 1);
	lv_label_set_text(ui->settings_camera_label_9, "");
	lv_label_set_long_mode(ui->settings_camera_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_camera_label_9, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_label_9_main_main_default
	static lv_style_t style_settings_camera_label_9_main_main_default;
	if (style_settings_camera_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_label_9_main_main_default);
	else
		lv_style_init(&style_settings_camera_label_9_main_main_default);
	lv_style_set_radius(&style_settings_camera_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_label_9_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_camera_label_9_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_camera_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_label_9_main_main_default, 255);
	lv_style_set_text_color(&style_settings_camera_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_camera_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_camera_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_camera_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_camera_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_camera_label_9_main_main_default, 0);
	lv_obj_add_style(ui->settings_camera_label_9, &style_settings_camera_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_img_7
	ui->settings_camera_img_7 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_7, 186, 154);
	lv_obj_set_size(ui->settings_camera_img_7, 109, 109);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_7_main_main_default
	static lv_style_t style_settings_camera_img_7_main_main_default;
	if (style_settings_camera_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_7_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_7_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_7_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_7, &style_settings_camera_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_img_8
	ui->settings_camera_img_8 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_8, 40, 431);
	lv_obj_set_size(ui->settings_camera_img_8, 30, 24);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_8_main_main_default
	static lv_style_t style_settings_camera_img_8_main_main_default;
	if (style_settings_camera_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_8_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_8_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_8_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_8, &style_settings_camera_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_camera_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_camera_img_8,&_video_30x24);
	lv_img_set_pivot(ui->settings_camera_img_8, 0,0);
	lv_img_set_angle(ui->settings_camera_img_8, 0);

	//Write codes settings_camera_img_11
	ui->settings_camera_img_11 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_11, 430, 431);
	lv_obj_set_size(ui->settings_camera_img_11, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_11_main_main_default
	static lv_style_t style_settings_camera_img_11_main_main_default;
	if (style_settings_camera_img_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_11_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_11_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_11_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_11_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_11, &style_settings_camera_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_camera_img_11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_camera_img_11,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_camera_img_11, 0,0);
	lv_img_set_angle(ui->settings_camera_img_11, 0);

	//Write codes settings_camera_img_12
	ui->settings_camera_img_12 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_12, 430, 513);
	lv_obj_set_size(ui->settings_camera_img_12, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_12_main_main_default
	static lv_style_t style_settings_camera_img_12_main_main_default;
	if (style_settings_camera_img_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_12_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_12_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_12_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_12_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_12, &style_settings_camera_img_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_camera_img_12, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_camera_img_12,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_camera_img_12, 0,0);
	lv_img_set_angle(ui->settings_camera_img_12, 0);

	//Write codes settings_camera_img_13
	ui->settings_camera_img_13 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_13, 430, 593);
	lv_obj_set_size(ui->settings_camera_img_13, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_13_main_main_default
	static lv_style_t style_settings_camera_img_13_main_main_default;
	if (style_settings_camera_img_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_13_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_13_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_13_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_13_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_13, &style_settings_camera_img_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_camera_img_13, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_camera_img_13,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_camera_img_13, 0,0);
	lv_img_set_angle(ui->settings_camera_img_13, 0);

	//Write codes settings_camera_img_9
	ui->settings_camera_img_9 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_9, 40, 509);
	lv_obj_set_size(ui->settings_camera_img_9, 25, 25);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_9_main_main_default
	static lv_style_t style_settings_camera_img_9_main_main_default;
	if (style_settings_camera_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_9_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_9_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_9_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_9, &style_settings_camera_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_camera_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_camera_img_9,&_seting_1_25x25);
	lv_img_set_pivot(ui->settings_camera_img_9, 0,0);
	lv_img_set_angle(ui->settings_camera_img_9, 0);

	//Write codes settings_camera_img_10
	ui->settings_camera_img_10 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_10, 40, 586);
	lv_obj_set_size(ui->settings_camera_img_10, 32, 32);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_10_main_main_default
	static lv_style_t style_settings_camera_img_10_main_main_default;
	if (style_settings_camera_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_10_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_10_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_10_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_10, &style_settings_camera_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_camera_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_camera_img_10,&_ai_logo_32x32);
	lv_img_set_pivot(ui->settings_camera_img_10, 0,0);
	lv_img_set_angle(ui->settings_camera_img_10, 0);

	//Write codes settings_camera_label_1
	ui->settings_camera_label_1 = lv_label_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_label_1, 0, 719);
	lv_obj_set_size(ui->settings_camera_label_1, 480, 80);
	lv_label_set_text(ui->settings_camera_label_1, "");
	lv_label_set_long_mode(ui->settings_camera_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_camera_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_label_1_main_main_default
	static lv_style_t style_settings_camera_label_1_main_main_default;
	if (style_settings_camera_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_label_1_main_main_default);
	else
		lv_style_init(&style_settings_camera_label_1_main_main_default);
	lv_style_set_radius(&style_settings_camera_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_camera_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_settings_camera_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_settings_camera_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_camera_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_settings_camera_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_camera_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_camera_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_camera_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_camera_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_camera_label_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_camera_label_1, &style_settings_camera_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_camera_img_1
	ui->settings_camera_img_1 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_1, 30, 742);
	lv_obj_set_size(ui->settings_camera_img_1, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_1_main_main_default
	static lv_style_t style_settings_camera_img_1_main_main_default;
	if (style_settings_camera_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_1_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_1_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_1_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_1, &style_settings_camera_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_camera_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_camera_img_1,&_home_48x48);
	lv_img_set_pivot(ui->settings_camera_img_1, 0,0);
	lv_img_set_angle(ui->settings_camera_img_1, 0);

	//Write codes settings_camera_img_2
	ui->settings_camera_img_2 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_2, 128, 742);
	lv_obj_set_size(ui->settings_camera_img_2, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_2_main_main_default
	static lv_style_t style_settings_camera_img_2_main_main_default;
	if (style_settings_camera_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_2_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_2_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_2_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_2, &style_settings_camera_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_camera_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_camera_img_2,&_prepare_48x48);
	lv_img_set_pivot(ui->settings_camera_img_2, 0,0);
	lv_img_set_angle(ui->settings_camera_img_2, 0);

	//Write codes settings_camera_img_3
	ui->settings_camera_img_3 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_3, 224, 742);
	lv_obj_set_size(ui->settings_camera_img_3, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_3_main_main_default
	static lv_style_t style_settings_camera_img_3_main_main_default;
	if (style_settings_camera_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_3_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_3_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_3_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_3, &style_settings_camera_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_camera_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_camera_img_3,&_files_48x48);
	lv_img_set_pivot(ui->settings_camera_img_3, 0,0);
	lv_img_set_angle(ui->settings_camera_img_3, 0);

	//Write codes settings_camera_img_4
	ui->settings_camera_img_4 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_4, 318, 742);
	lv_obj_set_size(ui->settings_camera_img_4, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_4_main_main_default
	static lv_style_t style_settings_camera_img_4_main_main_default;
	if (style_settings_camera_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_4_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_4_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_4_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_4, &style_settings_camera_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_camera_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_camera_img_4,&_seting_48x48);
	lv_img_set_pivot(ui->settings_camera_img_4, 0,0);
	lv_img_set_angle(ui->settings_camera_img_4, 0);

	//Write codes settings_camera_img_5
	ui->settings_camera_img_5 = lv_img_create(ui->settings_camera_cont_1);
	lv_obj_set_pos(ui->settings_camera_img_5, 414, 742);
	lv_obj_set_size(ui->settings_camera_img_5, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_camera_img_5_main_main_default
	static lv_style_t style_settings_camera_img_5_main_main_default;
	if (style_settings_camera_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_camera_img_5_main_main_default);
	else
		lv_style_init(&style_settings_camera_img_5_main_main_default);
	lv_style_set_img_recolor(&style_settings_camera_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_camera_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_camera_img_5_main_main_default, 255);
	lv_obj_add_style(ui->settings_camera_img_5, &style_settings_camera_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_camera_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_camera_img_5,&_FAQ_48x48);
	lv_img_set_pivot(ui->settings_camera_img_5, 0,0);
	lv_img_set_angle(ui->settings_camera_img_5, 0);
}
