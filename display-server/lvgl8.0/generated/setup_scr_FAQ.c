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


void setup_scr_FAQ(lv_ui *ui){

	//Write codes FAQ_cont_1
	ui->FAQ_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->FAQ_cont_1, 0, 0);
	lv_obj_set_size(ui->FAQ_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_faq_cont_1_main_main_default
	static lv_style_t style_faq_cont_1_main_main_default;
	if (style_faq_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_cont_1_main_main_default);
	else
		lv_style_init(&style_faq_cont_1_main_main_default);
	lv_style_set_radius(&style_faq_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_faq_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_faq_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_faq_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_faq_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_faq_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_faq_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_faq_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_faq_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_faq_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_faq_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_faq_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->FAQ_cont_1, &style_faq_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes FAQ_tabview_1
	ui->FAQ_tabview_1 = lv_tabview_create(ui->FAQ_cont_1, LV_DIR_TOP, 50);
	lv_obj_set_pos(ui->FAQ_tabview_1, 0, 0);
	lv_obj_set_size(ui->FAQ_tabview_1, 480, 720);

	//title1
	ui->FAQ_tabview_1_title1 = lv_tabview_add_tab(ui->FAQ_tabview_1,"title1");

	//title2
	ui->FAQ_tabview_1_title2 = lv_tabview_add_tab(ui->FAQ_tabview_1,"title2");

	//title3
	ui->FAQ_tabview_1_title3 = lv_tabview_add_tab(ui->FAQ_tabview_1,"title3");

	//Title
	ui->FAQ_tabview_1_Title = lv_tabview_add_tab(ui->FAQ_tabview_1,"Title");


	//Write style state: LV_STATE_DEFAULT for style_faq_tabview_1_main_main_default
	static lv_style_t style_faq_tabview_1_main_main_default;
	if (style_faq_tabview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_tabview_1_main_main_default);
	else
		lv_style_init(&style_faq_tabview_1_main_main_default);
	lv_style_set_bg_color(&style_faq_tabview_1_main_main_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_faq_tabview_1_main_main_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_faq_tabview_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_faq_tabview_1_main_main_default, 255);
	lv_style_set_border_color(&style_faq_tabview_1_main_main_default, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_faq_tabview_1_main_main_default, 0);
	lv_style_set_border_opa(&style_faq_tabview_1_main_main_default, 100);
	lv_style_set_text_color(&style_faq_tabview_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_faq_tabview_1_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_faq_tabview_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_faq_tabview_1_main_main_default, 16);
	lv_obj_add_style(ui->FAQ_tabview_1, &style_faq_tabview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_faq_tabview_1_extra_btnm_main_default
	static lv_style_t style_faq_tabview_1_extra_btnm_main_default;
	if (style_faq_tabview_1_extra_btnm_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_tabview_1_extra_btnm_main_default);
	else
		lv_style_init(&style_faq_tabview_1_extra_btnm_main_default);
	lv_style_set_bg_color(&style_faq_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_faq_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_faq_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_faq_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_border_color(&style_faq_tabview_1_extra_btnm_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_faq_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_border_opa(&style_faq_tabview_1_extra_btnm_main_default, 100);
	lv_style_set_pad_left(&style_faq_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_right(&style_faq_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_top(&style_faq_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_bottom(&style_faq_tabview_1_extra_btnm_main_default, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->FAQ_tabview_1), &style_faq_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_faq_tabview_1_extra_btnm_items_default
	static lv_style_t style_faq_tabview_1_extra_btnm_items_default;
	if (style_faq_tabview_1_extra_btnm_items_default.prop_cnt > 1)
		lv_style_reset(&style_faq_tabview_1_extra_btnm_items_default);
	else
		lv_style_init(&style_faq_tabview_1_extra_btnm_items_default);
	lv_style_set_text_color(&style_faq_tabview_1_extra_btnm_items_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_faq_tabview_1_extra_btnm_items_default, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->FAQ_tabview_1), &style_faq_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_faq_tabview_1_extra_btnm_items_checked
	static lv_style_t style_faq_tabview_1_extra_btnm_items_checked;
	if (style_faq_tabview_1_extra_btnm_items_checked.prop_cnt > 1)
		lv_style_reset(&style_faq_tabview_1_extra_btnm_items_checked);
	else
		lv_style_init(&style_faq_tabview_1_extra_btnm_items_checked);
	lv_style_set_bg_color(&style_faq_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_faq_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_faq_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_faq_tabview_1_extra_btnm_items_checked, 60);
	lv_style_set_border_color(&style_faq_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_faq_tabview_1_extra_btnm_items_checked, 4);
	lv_style_set_border_opa(&style_faq_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_side(&style_faq_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_text_color(&style_faq_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_text_font(&style_faq_tabview_1_extra_btnm_items_checked, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->FAQ_tabview_1), &style_faq_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes FAQ_label_2
	ui->FAQ_label_2 = lv_label_create(ui->FAQ_cont_1);
	lv_obj_set_pos(ui->FAQ_label_2, 9, 52);
	lv_obj_set_size(ui->FAQ_label_2, 460, 648);
	lv_label_set_text(ui->FAQ_label_2, "");
	lv_label_set_long_mode(ui->FAQ_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->FAQ_label_2, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_faq_label_2_main_main_default
	static lv_style_t style_faq_label_2_main_main_default;
	if (style_faq_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_label_2_main_main_default);
	else
		lv_style_init(&style_faq_label_2_main_main_default);
	lv_style_set_radius(&style_faq_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_faq_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_faq_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_faq_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_faq_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_faq_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_faq_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_faq_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_faq_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_faq_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_faq_label_2_main_main_default, 0);
	lv_obj_add_style(ui->FAQ_label_2, &style_faq_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes FAQ_img_6
	ui->FAQ_img_6 = lv_img_create(ui->FAQ_cont_1);
	lv_obj_set_pos(ui->FAQ_img_6, 160, 250);
	lv_obj_set_size(ui->FAQ_img_6, 160, 160);

	//Write style state: LV_STATE_DEFAULT for style_faq_img_6_main_main_default
	static lv_style_t style_faq_img_6_main_main_default;
	if (style_faq_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_img_6_main_main_default);
	else
		lv_style_init(&style_faq_img_6_main_main_default);
	lv_style_set_img_recolor(&style_faq_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_faq_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_faq_img_6_main_main_default, 255);
	lv_obj_add_style(ui->FAQ_img_6, &style_faq_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes FAQ_label_3
	ui->FAQ_label_3 = lv_label_create(ui->FAQ_cont_1);
	lv_obj_set_pos(ui->FAQ_label_3, 86, 416);
	lv_obj_set_size(ui->FAQ_label_3, 300, 32);
	lv_label_set_text(ui->FAQ_label_3, "扫码进行意见反馈");
	lv_label_set_long_mode(ui->FAQ_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->FAQ_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_faq_label_3_main_main_default
	static lv_style_t style_faq_label_3_main_main_default;
	if (style_faq_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_label_3_main_main_default);
	else
		lv_style_init(&style_faq_label_3_main_main_default);
	lv_style_set_radius(&style_faq_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_faq_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_faq_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_faq_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_faq_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_faq_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_faq_label_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_faq_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_faq_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_faq_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_faq_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_faq_label_3_main_main_default, 0);
	lv_obj_add_style(ui->FAQ_label_3, &style_faq_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes FAQ_label_1
	ui->FAQ_label_1 = lv_label_create(ui->FAQ_cont_1);
	lv_obj_set_pos(ui->FAQ_label_1, 0, 719);
	lv_obj_set_size(ui->FAQ_label_1, 480, 80);
	lv_label_set_text(ui->FAQ_label_1, "");
	lv_label_set_long_mode(ui->FAQ_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->FAQ_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_faq_label_1_main_main_default
	static lv_style_t style_faq_label_1_main_main_default;
	if (style_faq_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_label_1_main_main_default);
	else
		lv_style_init(&style_faq_label_1_main_main_default);
	lv_style_set_radius(&style_faq_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_faq_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_faq_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_faq_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_faq_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_faq_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_faq_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_faq_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_faq_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_faq_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_faq_label_1_main_main_default, 0);
	lv_obj_add_style(ui->FAQ_label_1, &style_faq_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes FAQ_img_1
	ui->FAQ_img_1 = lv_img_create(ui->FAQ_cont_1);
	lv_obj_set_pos(ui->FAQ_img_1, 30, 742);
	lv_obj_set_size(ui->FAQ_img_1, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_faq_img_1_main_main_default
	static lv_style_t style_faq_img_1_main_main_default;
	if (style_faq_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_img_1_main_main_default);
	else
		lv_style_init(&style_faq_img_1_main_main_default);
	lv_style_set_img_recolor(&style_faq_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_faq_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_faq_img_1_main_main_default, 255);
	lv_obj_add_style(ui->FAQ_img_1, &style_faq_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->FAQ_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->FAQ_img_1,&_home_48x48);
	lv_img_set_pivot(ui->FAQ_img_1, 0,0);
	lv_img_set_angle(ui->FAQ_img_1, 0);

	//Write codes FAQ_img_2
	ui->FAQ_img_2 = lv_img_create(ui->FAQ_cont_1);
	lv_obj_set_pos(ui->FAQ_img_2, 128, 742);
	lv_obj_set_size(ui->FAQ_img_2, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_faq_img_2_main_main_default
	static lv_style_t style_faq_img_2_main_main_default;
	if (style_faq_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_img_2_main_main_default);
	else
		lv_style_init(&style_faq_img_2_main_main_default);
	lv_style_set_img_recolor(&style_faq_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_faq_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_faq_img_2_main_main_default, 255);
	lv_obj_add_style(ui->FAQ_img_2, &style_faq_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->FAQ_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->FAQ_img_2,&_prepare_48x48);
	lv_img_set_pivot(ui->FAQ_img_2, 0,0);
	lv_img_set_angle(ui->FAQ_img_2, 0);

	//Write codes FAQ_img_3
	ui->FAQ_img_3 = lv_img_create(ui->FAQ_cont_1);
	lv_obj_set_pos(ui->FAQ_img_3, 224, 742);
	lv_obj_set_size(ui->FAQ_img_3, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_faq_img_3_main_main_default
	static lv_style_t style_faq_img_3_main_main_default;
	if (style_faq_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_img_3_main_main_default);
	else
		lv_style_init(&style_faq_img_3_main_main_default);
	lv_style_set_img_recolor(&style_faq_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_faq_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_faq_img_3_main_main_default, 255);
	lv_obj_add_style(ui->FAQ_img_3, &style_faq_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->FAQ_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->FAQ_img_3,&_files_48x48);
	lv_img_set_pivot(ui->FAQ_img_3, 0,0);
	lv_img_set_angle(ui->FAQ_img_3, 0);

	//Write codes FAQ_img_4
	ui->FAQ_img_4 = lv_img_create(ui->FAQ_cont_1);
	lv_obj_set_pos(ui->FAQ_img_4, 318, 742);
	lv_obj_set_size(ui->FAQ_img_4, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_faq_img_4_main_main_default
	static lv_style_t style_faq_img_4_main_main_default;
	if (style_faq_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_img_4_main_main_default);
	else
		lv_style_init(&style_faq_img_4_main_main_default);
	lv_style_set_img_recolor(&style_faq_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_faq_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_faq_img_4_main_main_default, 255);
	lv_obj_add_style(ui->FAQ_img_4, &style_faq_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->FAQ_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->FAQ_img_4,&_seting_48x48);
	lv_img_set_pivot(ui->FAQ_img_4, 0,0);
	lv_img_set_angle(ui->FAQ_img_4, 0);

	//Write codes FAQ_img_5
	ui->FAQ_img_5 = lv_img_create(ui->FAQ_cont_1);
	lv_obj_set_pos(ui->FAQ_img_5, 414, 742);
	lv_obj_set_size(ui->FAQ_img_5, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_faq_img_5_main_main_default
	static lv_style_t style_faq_img_5_main_main_default;
	if (style_faq_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_faq_img_5_main_main_default);
	else
		lv_style_init(&style_faq_img_5_main_main_default);
	lv_style_set_img_recolor(&style_faq_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_faq_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_faq_img_5_main_main_default, 255);
	lv_obj_add_style(ui->FAQ_img_5, &style_faq_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->FAQ_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->FAQ_img_5,&_FAQ_blue_48x48);
	lv_img_set_pivot(ui->FAQ_img_5, 0,0);
	lv_img_set_angle(ui->FAQ_img_5, 0);

	//Init events for screen
	events_init_FAQ(ui);
}
