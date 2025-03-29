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


void setup_scr_settings_network(lv_ui *ui){

	//Write codes settings_network
	ui->settings_network = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_main_main_default
	static lv_style_t style_settings_network_main_main_default;
	if (style_settings_network_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_main_main_default);
	else
		lv_style_init(&style_settings_network_main_main_default);
	lv_style_set_bg_color(&style_settings_network_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_settings_network_main_main_default, 0);
	lv_obj_add_style(ui->settings_network, &style_settings_network_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_network_tabview_1
	ui->settings_network_tabview_1 = lv_tabview_create(ui->settings_network, LV_DIR_TOP, 50);
	lv_obj_set_pos(ui->settings_network_tabview_1, 0, 0);
	lv_obj_set_size(ui->settings_network_tabview_1, 480, 720);

	//title1
	ui->settings_network_tabview_1_title1 = lv_tabview_add_tab(ui->settings_network_tabview_1,"title1");

	//title2
	ui->settings_network_tabview_1_title2 = lv_tabview_add_tab(ui->settings_network_tabview_1,"title2");

	//title3
	ui->settings_network_tabview_1_title3 = lv_tabview_add_tab(ui->settings_network_tabview_1,"title3");

	//Title
	ui->settings_network_tabview_1_Title = lv_tabview_add_tab(ui->settings_network_tabview_1,"Title");


	//Write style state: LV_STATE_DEFAULT for style_settings_network_tabview_1_main_main_default
	static lv_style_t style_settings_network_tabview_1_main_main_default;
	if (style_settings_network_tabview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_tabview_1_main_main_default);
	else
		lv_style_init(&style_settings_network_tabview_1_main_main_default);
	lv_style_set_bg_color(&style_settings_network_tabview_1_main_main_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_settings_network_tabview_1_main_main_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_settings_network_tabview_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_tabview_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_network_tabview_1_main_main_default, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_settings_network_tabview_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_network_tabview_1_main_main_default, 100);
	lv_style_set_text_color(&style_settings_network_tabview_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_settings_network_tabview_1_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_settings_network_tabview_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_settings_network_tabview_1_main_main_default, 16);
	lv_obj_add_style(ui->settings_network_tabview_1, &style_settings_network_tabview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_tabview_1_extra_btnm_main_default
	static lv_style_t style_settings_network_tabview_1_extra_btnm_main_default;
	if (style_settings_network_tabview_1_extra_btnm_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_tabview_1_extra_btnm_main_default);
	else
		lv_style_init(&style_settings_network_tabview_1_extra_btnm_main_default);
	lv_style_set_bg_color(&style_settings_network_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_network_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_network_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_border_color(&style_settings_network_tabview_1_extra_btnm_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_network_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_border_opa(&style_settings_network_tabview_1_extra_btnm_main_default, 100);
	lv_style_set_pad_left(&style_settings_network_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_right(&style_settings_network_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_top(&style_settings_network_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_network_tabview_1_extra_btnm_main_default, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_network_tabview_1), &style_settings_network_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_tabview_1_extra_btnm_items_default
	static lv_style_t style_settings_network_tabview_1_extra_btnm_items_default;
	if (style_settings_network_tabview_1_extra_btnm_items_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_tabview_1_extra_btnm_items_default);
	else
		lv_style_init(&style_settings_network_tabview_1_extra_btnm_items_default);
	lv_style_set_text_color(&style_settings_network_tabview_1_extra_btnm_items_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_settings_network_tabview_1_extra_btnm_items_default, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_network_tabview_1), &style_settings_network_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_network_tabview_1_extra_btnm_items_checked
	static lv_style_t style_settings_network_tabview_1_extra_btnm_items_checked;
	if (style_settings_network_tabview_1_extra_btnm_items_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_network_tabview_1_extra_btnm_items_checked);
	else
		lv_style_init(&style_settings_network_tabview_1_extra_btnm_items_checked);
	lv_style_set_bg_color(&style_settings_network_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_network_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_network_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_tabview_1_extra_btnm_items_checked, 60);
	lv_style_set_border_color(&style_settings_network_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_network_tabview_1_extra_btnm_items_checked, 4);
	lv_style_set_border_opa(&style_settings_network_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_side(&style_settings_network_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_text_color(&style_settings_network_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_text_font(&style_settings_network_tabview_1_extra_btnm_items_checked, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_network_tabview_1), &style_settings_network_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes settings_network_cont_1
	ui->settings_network_cont_1 = lv_obj_create(ui->settings_network);
	lv_obj_set_pos(ui->settings_network_cont_1, 0, 0);
	lv_obj_set_size(ui->settings_network_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_cont_1_main_main_default
	static lv_style_t style_settings_network_cont_1_main_main_default;
	if (style_settings_network_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_cont_1_main_main_default);
	else
		lv_style_init(&style_settings_network_cont_1_main_main_default);
	lv_style_set_radius(&style_settings_network_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_network_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_settings_network_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_settings_network_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_network_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_network_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_network_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_settings_network_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_network_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_network_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_network_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_network_cont_1, &style_settings_network_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_network_label_4
	ui->settings_network_label_4 = lv_label_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_label_4, 7, 61);
	lv_obj_set_size(ui->settings_network_label_4, 460, 648);
	lv_label_set_text(ui->settings_network_label_4, "");
	lv_label_set_long_mode(ui->settings_network_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_network_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_label_4_main_main_default
	static lv_style_t style_settings_network_label_4_main_main_default;
	if (style_settings_network_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_label_4_main_main_default);
	else
		lv_style_init(&style_settings_network_label_4_main_main_default);
	lv_style_set_radius(&style_settings_network_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_network_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_network_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_network_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_label_4_main_main_default, 255);
	lv_style_set_text_color(&style_settings_network_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_network_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_network_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_network_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_network_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_network_label_4_main_main_default, 0);
	lv_obj_add_style(ui->settings_network_label_4, &style_settings_network_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_network_list_1
	ui->settings_network_list_1 = lv_list_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_list_1, 25, 154);
	lv_obj_set_size(ui->settings_network_list_1, 430, 500);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_list_1_main_main_default
	static lv_style_t style_settings_network_list_1_main_main_default;
	if (style_settings_network_list_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_list_1_main_main_default);
	else
		lv_style_init(&style_settings_network_list_1_main_main_default);
	lv_style_set_radius(&style_settings_network_list_1_main_main_default, 3);
	lv_style_set_bg_color(&style_settings_network_list_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_network_list_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_network_list_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_list_1_main_main_default, 0);
	lv_style_set_border_color(&style_settings_network_list_1_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_network_list_1_main_main_default, 1);
	lv_style_set_pad_left(&style_settings_network_list_1_main_main_default, 5);
	lv_style_set_pad_right(&style_settings_network_list_1_main_main_default, 5);
	lv_style_set_pad_top(&style_settings_network_list_1_main_main_default, 5);
	lv_obj_add_style(ui->settings_network_list_1, &style_settings_network_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_list_1_main_scrollbar_default
	static lv_style_t style_settings_network_list_1_main_scrollbar_default;
	if (style_settings_network_list_1_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_list_1_main_scrollbar_default);
	else
		lv_style_init(&style_settings_network_list_1_main_scrollbar_default);
	lv_style_set_radius(&style_settings_network_list_1_main_scrollbar_default, 3);
	lv_style_set_bg_color(&style_settings_network_list_1_main_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_network_list_1_main_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_network_list_1_main_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_list_1_main_scrollbar_default, 255);
	lv_obj_add_style(ui->settings_network_list_1, &style_settings_network_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_list_1_extra_btns_main_default
	static lv_style_t style_settings_network_list_1_extra_btns_main_default;
	if (style_settings_network_list_1_extra_btns_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_list_1_extra_btns_main_default);
	else
		lv_style_init(&style_settings_network_list_1_extra_btns_main_default);
	lv_style_set_radius(&style_settings_network_list_1_extra_btns_main_default, 3);
	lv_style_set_bg_color(&style_settings_network_list_1_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_network_list_1_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_network_list_1_extra_btns_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_list_1_extra_btns_main_default, 255);
	lv_style_set_text_color(&style_settings_network_list_1_extra_btns_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_settings_network_list_1_extra_btns_main_default, &lv_font_simsun_24);
	lv_obj_t *settings_network_list_1_btn;
	settings_network_list_1_btn = lv_list_add_btn(ui->settings_network_list_1, LV_SYMBOL_SAVE, "save");
	ui->settings_network_list_1_item0 = settings_network_list_1_btn;
	lv_obj_add_style(settings_network_list_1_btn, &style_settings_network_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_network_img_6
	ui->settings_network_img_6 = lv_img_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_img_6, 439, 76);
	lv_obj_set_size(ui->settings_network_img_6, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_img_6_main_main_default
	static lv_style_t style_settings_network_img_6_main_main_default;
	if (style_settings_network_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_img_6_main_main_default);
	else
		lv_style_init(&style_settings_network_img_6_main_main_default);
	lv_style_set_img_recolor(&style_settings_network_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_network_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_network_img_6_main_main_default, 255);
	lv_obj_add_style(ui->settings_network_img_6, &style_settings_network_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_network_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_network_img_6,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_network_img_6, 0,0);
	lv_img_set_angle(ui->settings_network_img_6, 0);

	//Write codes settings_network_label_3
	ui->settings_network_label_3 = lv_label_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_label_3, 25, 78);
	lv_obj_set_size(ui->settings_network_label_3, 110, 24);
	lv_label_set_text(ui->settings_network_label_3, "本地网络");
	lv_label_set_long_mode(ui->settings_network_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_network_label_3, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_label_3_main_main_default
	static lv_style_t style_settings_network_label_3_main_main_default;
	if (style_settings_network_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_label_3_main_main_default);
	else
		lv_style_init(&style_settings_network_label_3_main_main_default);
	lv_style_set_radius(&style_settings_network_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_network_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_network_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_network_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_settings_network_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_network_label_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_network_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_network_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_network_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_network_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_network_label_3_main_main_default, 0);
	lv_obj_add_style(ui->settings_network_label_3, &style_settings_network_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_network_label_5
	ui->settings_network_label_5 = lv_label_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_label_5, 360, 78);
	lv_obj_set_size(ui->settings_network_label_5, 73, 24);
	lv_label_set_text(ui->settings_network_label_5, "已连接");
	lv_label_set_long_mode(ui->settings_network_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_network_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_label_5_main_main_default
	static lv_style_t style_settings_network_label_5_main_main_default;
	if (style_settings_network_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_label_5_main_main_default);
	else
		lv_style_init(&style_settings_network_label_5_main_main_default);
	lv_style_set_radius(&style_settings_network_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_network_label_5_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_network_label_5_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_network_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_settings_network_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_network_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_network_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_network_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_network_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_network_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_network_label_5_main_main_default, 0);
	lv_obj_add_style(ui->settings_network_label_5, &style_settings_network_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_network_btn_1
	ui->settings_network_btn_1 = lv_btn_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_btn_1, 357, 66);
	lv_obj_set_size(ui->settings_network_btn_1, 100, 50);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_btn_1_main_main_default
	static lv_style_t style_settings_network_btn_1_main_main_default;
	if (style_settings_network_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_btn_1_main_main_default);
	else
		lv_style_init(&style_settings_network_btn_1_main_main_default);
	lv_style_set_radius(&style_settings_network_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_network_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_network_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_network_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_settings_network_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_settings_network_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_settings_network_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_network_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_network_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->settings_network_btn_1, &style_settings_network_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->settings_network_btn_1_label = lv_label_create(ui->settings_network_btn_1);
	lv_label_set_text(ui->settings_network_btn_1_label, "");
	lv_obj_set_style_text_color(ui->settings_network_btn_1_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->settings_network_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->settings_network_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes settings_network_label_1
	ui->settings_network_label_1 = lv_label_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_label_1, 0, 719);
	lv_obj_set_size(ui->settings_network_label_1, 480, 80);
	lv_label_set_text(ui->settings_network_label_1, "");
	lv_label_set_long_mode(ui->settings_network_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_network_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_label_1_main_main_default
	static lv_style_t style_settings_network_label_1_main_main_default;
	if (style_settings_network_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_label_1_main_main_default);
	else
		lv_style_init(&style_settings_network_label_1_main_main_default);
	lv_style_set_radius(&style_settings_network_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_network_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_settings_network_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_settings_network_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_network_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_settings_network_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_network_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_network_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_network_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_network_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_network_label_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_network_label_1, &style_settings_network_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_network_img_1
	ui->settings_network_img_1 = lv_img_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_img_1, 30, 742);
	lv_obj_set_size(ui->settings_network_img_1, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_img_1_main_main_default
	static lv_style_t style_settings_network_img_1_main_main_default;
	if (style_settings_network_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_img_1_main_main_default);
	else
		lv_style_init(&style_settings_network_img_1_main_main_default);
	lv_style_set_img_recolor(&style_settings_network_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_network_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_network_img_1_main_main_default, 255);
	lv_obj_add_style(ui->settings_network_img_1, &style_settings_network_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_network_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_network_img_1,&_home_48x48);
	lv_img_set_pivot(ui->settings_network_img_1, 0,0);
	lv_img_set_angle(ui->settings_network_img_1, 0);

	//Write codes settings_network_img_2
	ui->settings_network_img_2 = lv_img_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_img_2, 128, 742);
	lv_obj_set_size(ui->settings_network_img_2, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_img_2_main_main_default
	static lv_style_t style_settings_network_img_2_main_main_default;
	if (style_settings_network_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_img_2_main_main_default);
	else
		lv_style_init(&style_settings_network_img_2_main_main_default);
	lv_style_set_img_recolor(&style_settings_network_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_network_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_network_img_2_main_main_default, 255);
	lv_obj_add_style(ui->settings_network_img_2, &style_settings_network_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_network_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_network_img_2,&_prepare_48x48);
	lv_img_set_pivot(ui->settings_network_img_2, 0,0);
	lv_img_set_angle(ui->settings_network_img_2, 0);

	//Write codes settings_network_img_3
	ui->settings_network_img_3 = lv_img_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_img_3, 224, 742);
	lv_obj_set_size(ui->settings_network_img_3, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_img_3_main_main_default
	static lv_style_t style_settings_network_img_3_main_main_default;
	if (style_settings_network_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_img_3_main_main_default);
	else
		lv_style_init(&style_settings_network_img_3_main_main_default);
	lv_style_set_img_recolor(&style_settings_network_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_network_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_network_img_3_main_main_default, 255);
	lv_obj_add_style(ui->settings_network_img_3, &style_settings_network_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_network_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_network_img_3,&_files_48x48);
	lv_img_set_pivot(ui->settings_network_img_3, 0,0);
	lv_img_set_angle(ui->settings_network_img_3, 0);

	//Write codes settings_network_img_4
	ui->settings_network_img_4 = lv_img_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_img_4, 318, 742);
	lv_obj_set_size(ui->settings_network_img_4, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_img_4_main_main_default
	static lv_style_t style_settings_network_img_4_main_main_default;
	if (style_settings_network_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_img_4_main_main_default);
	else
		lv_style_init(&style_settings_network_img_4_main_main_default);
	lv_style_set_img_recolor(&style_settings_network_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_network_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_network_img_4_main_main_default, 255);
	lv_obj_add_style(ui->settings_network_img_4, &style_settings_network_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_network_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_network_img_4,&_seting_48x48);
	lv_img_set_pivot(ui->settings_network_img_4, 0,0);
	lv_img_set_angle(ui->settings_network_img_4, 0);

	//Write codes settings_network_img_5
	ui->settings_network_img_5 = lv_img_create(ui->settings_network_cont_1);
	lv_obj_set_pos(ui->settings_network_img_5, 414, 742);
	lv_obj_set_size(ui->settings_network_img_5, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_network_img_5_main_main_default
	static lv_style_t style_settings_network_img_5_main_main_default;
	if (style_settings_network_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_network_img_5_main_main_default);
	else
		lv_style_init(&style_settings_network_img_5_main_main_default);
	lv_style_set_img_recolor(&style_settings_network_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_network_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_network_img_5_main_main_default, 255);
	lv_obj_add_style(ui->settings_network_img_5, &style_settings_network_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_network_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_network_img_5,&_FAQ_48x48);
	lv_img_set_pivot(ui->settings_network_img_5, 0,0);
	lv_img_set_angle(ui->settings_network_img_5, 0);
}
