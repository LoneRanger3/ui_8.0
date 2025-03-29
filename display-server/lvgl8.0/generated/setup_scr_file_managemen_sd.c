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


void setup_scr_file_managemen_sd(lv_ui *ui){
//
//	//Write codes file_managemen_sd_tabview_1
//	ui->file_managemen_sd_tabview_1 = lv_tabview_create(ui->file_managemen_sd, LV_DIR_TOP, 47);
//	lv_obj_set_pos(ui->file_managemen_sd_tabview_1, 0, 0);
//	lv_obj_set_size(ui->file_managemen_sd_tabview_1, 480, 720);
//
//	//title1
//	ui->file_managemen_sd_tabview_1_title1 = lv_tabview_add_tab(ui->file_managemen_sd_tabview_1,"title1");
//
//	//title2
//	ui->file_managemen_sd_tabview_1_title2 = lv_tabview_add_tab(ui->file_managemen_sd_tabview_1,"title2");
//
//	//title3
//	ui->file_managemen_sd_tabview_1_title3 = lv_tabview_add_tab(ui->file_managemen_sd_tabview_1,"title3");
//
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_tabview_1_main_main_default
//	static lv_style_t style_file_managemen_sd_tabview_1_main_main_default;
//	if (style_file_managemen_sd_tabview_1_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_tabview_1_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_tabview_1_main_main_default);
//	lv_style_set_bg_color(&style_file_managemen_sd_tabview_1_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_tabview_1_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_tabview_1_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_tabview_1_main_main_default, 255);
//	lv_style_set_border_color(&style_file_managemen_sd_tabview_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_border_width(&style_file_managemen_sd_tabview_1_main_main_default, 0);
//	lv_style_set_border_opa(&style_file_managemen_sd_tabview_1_main_main_default, 100);
//	lv_style_set_text_color(&style_file_managemen_sd_tabview_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
//	lv_style_set_text_font(&style_file_managemen_sd_tabview_1_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_tabview_1_main_main_default, 0);
//	lv_style_set_text_line_space(&style_file_managemen_sd_tabview_1_main_main_default, 16);
//	lv_obj_add_style(ui->file_managemen_sd_tabview_1, &style_file_managemen_sd_tabview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_tabview_1_extra_btnm_main_default
//	static lv_style_t style_file_managemen_sd_tabview_1_extra_btnm_main_default;
//	if (style_file_managemen_sd_tabview_1_extra_btnm_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_tabview_1_extra_btnm_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_tabview_1_extra_btnm_main_default);
//	lv_style_set_bg_color(&style_file_managemen_sd_tabview_1_extra_btnm_main_default, lv_color_make(0x23, 0x24, 0x26));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_tabview_1_extra_btnm_main_default, lv_color_make(0x23, 0x24, 0x26));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_tabview_1_extra_btnm_main_default, 255);
//	lv_style_set_border_color(&style_file_managemen_sd_tabview_1_extra_btnm_main_default, lv_color_make(0x21, 0x95, 0xf6));
//	lv_style_set_border_width(&style_file_managemen_sd_tabview_1_extra_btnm_main_default, 0);
//	lv_style_set_border_opa(&style_file_managemen_sd_tabview_1_extra_btnm_main_default, 100);
//	lv_style_set_pad_left(&style_file_managemen_sd_tabview_1_extra_btnm_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_tabview_1_extra_btnm_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_tabview_1_extra_btnm_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_tabview_1_extra_btnm_main_default, 0);
//	lv_obj_add_style(lv_tabview_get_tab_btns(ui->file_managemen_sd_tabview_1), &style_file_managemen_sd_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_tabview_1_extra_btnm_items_default
//	static lv_style_t style_file_managemen_sd_tabview_1_extra_btnm_items_default;
//	if (style_file_managemen_sd_tabview_1_extra_btnm_items_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_tabview_1_extra_btnm_items_default);
//	else
//		lv_style_init(&style_file_managemen_sd_tabview_1_extra_btnm_items_default);
//	lv_style_set_text_color(&style_file_managemen_sd_tabview_1_extra_btnm_items_default, lv_color_make(0x4d, 0x4d, 0x4d));
//	lv_style_set_text_font(&style_file_managemen_sd_tabview_1_extra_btnm_items_default, &lv_font_simsun_12);
//	lv_obj_add_style(lv_tabview_get_tab_btns(ui->file_managemen_sd_tabview_1), &style_file_managemen_sd_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);
//
//	//Write style state: LV_STATE_CHECKED for style_file_managemen_sd_tabview_1_extra_btnm_items_checked
//	static lv_style_t style_file_managemen_sd_tabview_1_extra_btnm_items_checked;
//	if (style_file_managemen_sd_tabview_1_extra_btnm_items_checked.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked);
//	else
//		lv_style_init(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked);
//	lv_style_set_bg_color(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked, 60);
//	lv_style_set_border_color(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
//	lv_style_set_border_width(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked, 4);
//	lv_style_set_border_opa(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked, 255);
//	lv_style_set_border_side(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
//	lv_style_set_text_color(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
//	lv_style_set_text_font(&style_file_managemen_sd_tabview_1_extra_btnm_items_checked, &lv_font_simsun_12);
//	lv_obj_add_style(lv_tabview_get_tab_btns(ui->file_managemen_sd_tabview_1), &style_file_managemen_sd_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);
//
//	//Write codes file_managemen_sd_cont_1
//	ui->file_managemen_sd_cont_1 = lv_obj_create(ui->file_managemen_sd);
//	lv_obj_set_pos(ui->file_managemen_sd_cont_1, 0, 0);
//	lv_obj_set_size(ui->file_managemen_sd_cont_1, 480, 800);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_cont_1_main_main_default
//	static lv_style_t style_file_managemen_sd_cont_1_main_main_default;
//	if (style_file_managemen_sd_cont_1_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_cont_1_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_cont_1_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_cont_1_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_cont_1_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_cont_1_main_main_default, 255);
//	lv_style_set_border_color(&style_file_managemen_sd_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
//	lv_style_set_border_width(&style_file_managemen_sd_cont_1_main_main_default, 0);
//	lv_style_set_border_opa(&style_file_managemen_sd_cont_1_main_main_default, 255);
//	lv_style_set_pad_left(&style_file_managemen_sd_cont_1_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_cont_1_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_cont_1_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_cont_1_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_cont_1, &style_file_managemen_sd_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_1
//	ui->file_managemen_sd_label_1 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_1, 0, 720);
//	lv_obj_set_size(ui->file_managemen_sd_label_1, 480, 80);
//	lv_label_set_text(ui->file_managemen_sd_label_1, "");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_1, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_1, LV_TEXT_ALIGN_CENTER, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_1_main_main_default
//	static lv_style_t style_file_managemen_sd_label_1_main_main_default;
//	if (style_file_managemen_sd_label_1_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_1_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_1_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_1_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_1_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_1_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_1_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_1_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_1_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_1_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_1_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_1, &style_file_managemen_sd_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_2
//	ui->file_managemen_sd_label_2 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_2, 20, 72);
//	lv_obj_set_size(ui->file_managemen_sd_label_2, 215, 203);
//	lv_label_set_text(ui->file_managemen_sd_label_2, "");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_2, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_2, LV_TEXT_ALIGN_CENTER, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_2_main_main_default
//	static lv_style_t style_file_managemen_sd_label_2_main_main_default;
//	if (style_file_managemen_sd_label_2_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_2_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_2_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_2_main_main_default, 8);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_2_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_2_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_2_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_2_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_2_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_2_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_2_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_2_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_2_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_2, &style_file_managemen_sd_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_6
//	ui->file_managemen_sd_label_6 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_6, 245, 72);
//	lv_obj_set_size(ui->file_managemen_sd_label_6, 215, 203);
//	lv_label_set_text(ui->file_managemen_sd_label_6, "");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_6, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_6, LV_TEXT_ALIGN_CENTER, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_6_main_main_default
//	static lv_style_t style_file_managemen_sd_label_6_main_main_default;
//	if (style_file_managemen_sd_label_6_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_6_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_6_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_6_main_main_default, 8);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_6_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_6_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_6_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_6_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_6_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_6_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_6_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_6_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_6_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_6, &style_file_managemen_sd_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_10
//	ui->file_managemen_sd_label_10 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_10, 20, 285);
//	lv_obj_set_size(ui->file_managemen_sd_label_10, 215, 203);
//	lv_label_set_text(ui->file_managemen_sd_label_10, "");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_10, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_10, LV_TEXT_ALIGN_CENTER, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_10_main_main_default
//	static lv_style_t style_file_managemen_sd_label_10_main_main_default;
//	if (style_file_managemen_sd_label_10_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_10_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_10_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_10_main_main_default, 8);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_10_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_10_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_10_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_10_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_10_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_10_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_10_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_10_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_10_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_10, &style_file_managemen_sd_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_11
//	ui->file_managemen_sd_label_11 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_11, 245, 285);
//	lv_obj_set_size(ui->file_managemen_sd_label_11, 215, 203);
//	lv_label_set_text(ui->file_managemen_sd_label_11, "");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_11, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_11, LV_TEXT_ALIGN_CENTER, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_11_main_main_default
//	static lv_style_t style_file_managemen_sd_label_11_main_main_default;
//	if (style_file_managemen_sd_label_11_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_11_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_11_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_11_main_main_default, 8);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_11_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_11_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_11_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_11_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_11_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_11_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_11_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_11_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_11_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_11, &style_file_managemen_sd_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_12
//	ui->file_managemen_sd_label_12 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_12, 20, 498);
//	lv_obj_set_size(ui->file_managemen_sd_label_12, 215, 203);
//	lv_label_set_text(ui->file_managemen_sd_label_12, "");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_12, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_12, LV_TEXT_ALIGN_CENTER, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_12_main_main_default
//	static lv_style_t style_file_managemen_sd_label_12_main_main_default;
//	if (style_file_managemen_sd_label_12_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_12_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_12_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_12_main_main_default, 8);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_12_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_12_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_12_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_12_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_12_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_12_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_12_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_12_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_12_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_12, &style_file_managemen_sd_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_13
//	ui->file_managemen_sd_label_13 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_13, 245, 498);
//	lv_obj_set_size(ui->file_managemen_sd_label_13, 215, 203);
//	lv_label_set_text(ui->file_managemen_sd_label_13, "");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_13, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_13, LV_TEXT_ALIGN_CENTER, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_13_main_main_default
//	static lv_style_t style_file_managemen_sd_label_13_main_main_default;
//	if (style_file_managemen_sd_label_13_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_13_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_13_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_13_main_main_default, 8);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_13_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_13_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_13_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_13_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_13_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_13_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_13_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_13_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_13_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_13, &style_file_managemen_sd_label_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_3
//	ui->file_managemen_sd_label_3 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_3, 30, 190);
//	lv_obj_set_size(ui->file_managemen_sd_label_3, 199, 42);
//	lv_label_set_text(ui->file_managemen_sd_label_3, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_3, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_3, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_3_main_main_default
//	static lv_style_t style_file_managemen_sd_label_3_main_main_default;
//	if (style_file_managemen_sd_label_3_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_3_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_3_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_3_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_3_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_3_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_3_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_3_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_3_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_3_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_3_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_3_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_3_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_3_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_3, &style_file_managemen_sd_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_btn_1
//	ui->file_managemen_sd_btn_1 = lv_btn_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_btn_1, 418, 592);
//	lv_obj_set_size(ui->file_managemen_sd_btn_1, 60, 60);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_btn_1_main_main_default
//	static lv_style_t style_file_managemen_sd_btn_1_main_main_default;
//	if (style_file_managemen_sd_btn_1_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_btn_1_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_btn_1_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_btn_1_main_main_default, 30);
//	lv_style_set_bg_color(&style_file_managemen_sd_btn_1_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_btn_1_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_btn_1_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_btn_1_main_main_default, 227);
//	lv_style_set_shadow_color(&style_file_managemen_sd_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
//	lv_style_set_shadow_opa(&style_file_managemen_sd_btn_1_main_main_default, 0);
//	lv_style_set_border_color(&style_file_managemen_sd_btn_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
//	lv_style_set_border_width(&style_file_managemen_sd_btn_1_main_main_default, 1);
//	lv_style_set_border_opa(&style_file_managemen_sd_btn_1_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_btn_1, &style_file_managemen_sd_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	ui->file_managemen_sd_btn_1_label = lv_label_create(ui->file_managemen_sd_btn_1);
//	lv_label_set_text(ui->file_managemen_sd_btn_1_label, "");
//	lv_obj_set_style_text_color(ui->file_managemen_sd_btn_1_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
//	lv_obj_set_style_pad_all(ui->file_managemen_sd_btn_1, 0, LV_STATE_DEFAULT);
//	lv_obj_align(ui->file_managemen_sd_btn_1_label, LV_ALIGN_CENTER, 0, 0);
//
//	//Write codes file_managemen_sd_btn_2
//	ui->file_managemen_sd_btn_2 = lv_btn_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_btn_2, 418, 666);
//	lv_obj_set_size(ui->file_managemen_sd_btn_2, 60, 60);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_btn_2_main_main_default
//	static lv_style_t style_file_managemen_sd_btn_2_main_main_default;
//	if (style_file_managemen_sd_btn_2_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_btn_2_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_btn_2_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_btn_2_main_main_default, 30);
//	lv_style_set_bg_color(&style_file_managemen_sd_btn_2_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_btn_2_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_btn_2_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_btn_2_main_main_default, 227);
//	lv_style_set_shadow_color(&style_file_managemen_sd_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
//	lv_style_set_shadow_opa(&style_file_managemen_sd_btn_2_main_main_default, 0);
//	lv_style_set_border_color(&style_file_managemen_sd_btn_2_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
//	lv_style_set_border_width(&style_file_managemen_sd_btn_2_main_main_default, 1);
//	lv_style_set_border_opa(&style_file_managemen_sd_btn_2_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_btn_2, &style_file_managemen_sd_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	ui->file_managemen_sd_btn_2_label = lv_label_create(ui->file_managemen_sd_btn_2);
//	lv_label_set_text(ui->file_managemen_sd_btn_2_label, "");
//	lv_obj_set_style_text_color(ui->file_managemen_sd_btn_2_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
//	lv_obj_set_style_pad_all(ui->file_managemen_sd_btn_2, 0, LV_STATE_DEFAULT);
//	lv_obj_align(ui->file_managemen_sd_btn_2_label, LV_ALIGN_CENTER, 0, 0);
//
//	//Write codes file_managemen_sd_label_14
//	ui->file_managemen_sd_label_14 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_14, 30, 403);
//	lv_obj_set_size(ui->file_managemen_sd_label_14, 199, 42);
//	lv_label_set_text(ui->file_managemen_sd_label_14, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_14, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_14, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_14_main_main_default
//	static lv_style_t style_file_managemen_sd_label_14_main_main_default;
//	if (style_file_managemen_sd_label_14_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_14_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_14_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_14_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_14_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_14_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_14_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_14_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_14_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_14_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_14_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_14_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_14_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_14_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_14, &style_file_managemen_sd_label_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_17
//	ui->file_managemen_sd_label_17 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_17, 255, 403);
//	lv_obj_set_size(ui->file_managemen_sd_label_17, 199, 42);
//	lv_label_set_text(ui->file_managemen_sd_label_17, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_17, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_17, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_17_main_main_default
//	static lv_style_t style_file_managemen_sd_label_17_main_main_default;
//	if (style_file_managemen_sd_label_17_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_17_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_17_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_17_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_17_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_17_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_17_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_17_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_17_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_17_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_17_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_17_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_17_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_17_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_17_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_17, &style_file_managemen_sd_label_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_20
//	ui->file_managemen_sd_label_20 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_20, 30, 616);
//	lv_obj_set_size(ui->file_managemen_sd_label_20, 199, 42);
//	lv_label_set_text(ui->file_managemen_sd_label_20, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_20, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_20, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_20_main_main_default
//	static lv_style_t style_file_managemen_sd_label_20_main_main_default;
//	if (style_file_managemen_sd_label_20_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_20_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_20_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_20_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_20_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_20_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_20_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_20_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_20_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_20_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_20_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_20_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_20_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_20_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_20_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_20, &style_file_managemen_sd_label_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_23
//	ui->file_managemen_sd_label_23 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_23, 255, 616);
//	lv_obj_set_size(ui->file_managemen_sd_label_23, 199, 42);
//	lv_label_set_text(ui->file_managemen_sd_label_23, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_23, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_23, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_23_main_main_default
//	static lv_style_t style_file_managemen_sd_label_23_main_main_default;
//	if (style_file_managemen_sd_label_23_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_23_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_23_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_23_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_23_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_23_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_23_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_23_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_23_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_23_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_23_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_23_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_23_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_23_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_23_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_23, &style_file_managemen_sd_label_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_7
//	ui->file_managemen_sd_label_7 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_7, 255, 190);
//	lv_obj_set_size(ui->file_managemen_sd_label_7, 199, 42);
//	lv_label_set_text(ui->file_managemen_sd_label_7, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_7, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_7, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_7_main_main_default
//	static lv_style_t style_file_managemen_sd_label_7_main_main_default;
//	if (style_file_managemen_sd_label_7_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_7_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_7_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_7_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_7_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_7_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_7_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_7_main_main_default, 255);
//	lv_style_set_text_color(&style_file_managemen_sd_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_7_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_7_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_7_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_7_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_7_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_7_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_7, &style_file_managemen_sd_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_4
//	ui->file_managemen_sd_label_4 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_4, 49, 240);
//	lv_obj_set_size(ui->file_managemen_sd_label_4, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_4, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_4, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_4, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_4_main_main_default
//	static lv_style_t style_file_managemen_sd_label_4_main_main_default;
//	if (style_file_managemen_sd_label_4_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_4_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_4_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_4_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_4_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_4_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_4_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_4_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_4_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_4_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_4_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_4_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_4_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_4_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_4, &style_file_managemen_sd_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_15
//	ui->file_managemen_sd_label_15 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_15, 49, 452);
//	lv_obj_set_size(ui->file_managemen_sd_label_15, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_15, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_15, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_15, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_15_main_main_default
//	static lv_style_t style_file_managemen_sd_label_15_main_main_default;
//	if (style_file_managemen_sd_label_15_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_15_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_15_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_15_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_15_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_15_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_15_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_15_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_15_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_15_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_15_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_15_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_15_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_15_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_15, &style_file_managemen_sd_label_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_21
//	ui->file_managemen_sd_label_21 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_21, 49, 665);
//	lv_obj_set_size(ui->file_managemen_sd_label_21, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_21, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_21, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_21, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_21_main_main_default
//	static lv_style_t style_file_managemen_sd_label_21_main_main_default;
//	if (style_file_managemen_sd_label_21_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_21_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_21_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_21_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_21_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_21_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_21_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_21_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_21_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_21_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_21_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_21_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_21_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_21_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_21_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_21, &style_file_managemen_sd_label_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_24
//	ui->file_managemen_sd_label_24 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_24, 275, 665);
//	lv_obj_set_size(ui->file_managemen_sd_label_24, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_24, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_24, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_24, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_24_main_main_default
//	static lv_style_t style_file_managemen_sd_label_24_main_main_default;
//	if (style_file_managemen_sd_label_24_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_24_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_24_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_24_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_24_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_24_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_24_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_24_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_24_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_24_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_24_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_24_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_24_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_24_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_24_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_24, &style_file_managemen_sd_label_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_25
//	ui->file_managemen_sd_label_25 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_25, 369, 665);
//	lv_obj_set_size(ui->file_managemen_sd_label_25, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_25, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_25, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_25, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_25_main_main_default
//	static lv_style_t style_file_managemen_sd_label_25_main_main_default;
//	if (style_file_managemen_sd_label_25_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_25_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_25_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_25_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_25_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_25_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_25_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_25_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_25_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_25_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_25_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_25_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_25_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_25_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_25_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_25, &style_file_managemen_sd_label_25_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_22
//	ui->file_managemen_sd_label_22 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_22, 143, 665);
//	lv_obj_set_size(ui->file_managemen_sd_label_22, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_22, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_22, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_22, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_22_main_main_default
//	static lv_style_t style_file_managemen_sd_label_22_main_main_default;
//	if (style_file_managemen_sd_label_22_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_22_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_22_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_22_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_22_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_22_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_22_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_22_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_22_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_22_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_22_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_22_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_22_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_22_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_22_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_22, &style_file_managemen_sd_label_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_18
//	ui->file_managemen_sd_label_18 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_18, 275, 452);
//	lv_obj_set_size(ui->file_managemen_sd_label_18, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_18, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_18, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_18, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_18_main_main_default
//	static lv_style_t style_file_managemen_sd_label_18_main_main_default;
//	if (style_file_managemen_sd_label_18_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_18_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_18_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_18_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_18_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_18_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_18_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_18_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_18_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_18_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_18_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_18_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_18_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_18_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_18_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_18, &style_file_managemen_sd_label_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_19
//	ui->file_managemen_sd_label_19 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_19, 369, 452);
//	lv_obj_set_size(ui->file_managemen_sd_label_19, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_19, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_19, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_19, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_19_main_main_default
//	static lv_style_t style_file_managemen_sd_label_19_main_main_default;
//	if (style_file_managemen_sd_label_19_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_19_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_19_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_19_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_19_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_19_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_19_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_19_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_19_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_19_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_19_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_19_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_19_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_19_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_19_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_19, &style_file_managemen_sd_label_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_16
//	ui->file_managemen_sd_label_16 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_16, 143, 452);
//	lv_obj_set_size(ui->file_managemen_sd_label_16, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_16, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_16, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_16, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_16_main_main_default
//	static lv_style_t style_file_managemen_sd_label_16_main_main_default;
//	if (style_file_managemen_sd_label_16_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_16_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_16_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_16_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_16_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_16_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_16_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_16_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_16_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_16_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_16_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_16_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_16_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_16_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_16, &style_file_managemen_sd_label_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_8
//	ui->file_managemen_sd_label_8 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_8, 275, 240);
//	lv_obj_set_size(ui->file_managemen_sd_label_8, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_8, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_8, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_8, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_8_main_main_default
//	static lv_style_t style_file_managemen_sd_label_8_main_main_default;
//	if (style_file_managemen_sd_label_8_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_8_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_8_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_8_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_8_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_8_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_8_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_8_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_8_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_8_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_8_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_8_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_8_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_8_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_8, &style_file_managemen_sd_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_5
//	ui->file_managemen_sd_label_5 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_5, 143, 240);
//	lv_obj_set_size(ui->file_managemen_sd_label_5, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_5, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_5, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_5, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_5_main_main_default
//	static lv_style_t style_file_managemen_sd_label_5_main_main_default;
//	if (style_file_managemen_sd_label_5_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_5_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_5_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_5_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_5_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_5_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_5_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_5_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_5_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_5_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_5_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_5_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_5_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_5_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_5, &style_file_managemen_sd_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_label_9
//	ui->file_managemen_sd_label_9 = lv_label_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_label_9, 369, 240);
//	lv_obj_set_size(ui->file_managemen_sd_label_9, 57, 24);
//	lv_label_set_text(ui->file_managemen_sd_label_9, "test.gcode");
//	lv_label_set_long_mode(ui->file_managemen_sd_label_9, LV_LABEL_LONG_WRAP);
//	lv_obj_set_style_text_align(ui->file_managemen_sd_label_9, LV_TEXT_ALIGN_LEFT, 0);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_label_9_main_main_default
//	static lv_style_t style_file_managemen_sd_label_9_main_main_default;
//	if (style_file_managemen_sd_label_9_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_label_9_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_label_9_main_main_default);
//	lv_style_set_radius(&style_file_managemen_sd_label_9_main_main_default, 0);
//	lv_style_set_bg_color(&style_file_managemen_sd_label_9_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_color(&style_file_managemen_sd_label_9_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
//	lv_style_set_bg_grad_dir(&style_file_managemen_sd_label_9_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_file_managemen_sd_label_9_main_main_default, 0);
//	lv_style_set_text_color(&style_file_managemen_sd_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_file_managemen_sd_label_9_main_main_default, &lv_font_simsun_24);
//	lv_style_set_text_letter_space(&style_file_managemen_sd_label_9_main_main_default, 0);
//	lv_style_set_pad_left(&style_file_managemen_sd_label_9_main_main_default, 0);
//	lv_style_set_pad_right(&style_file_managemen_sd_label_9_main_main_default, 0);
//	lv_style_set_pad_top(&style_file_managemen_sd_label_9_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_file_managemen_sd_label_9_main_main_default, 0);
//	lv_obj_add_style(ui->file_managemen_sd_label_9, &style_file_managemen_sd_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_img_6
//	ui->file_managemen_sd_img_6 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_6, 80, 82);
//	lv_obj_set_size(ui->file_managemen_sd_img_6, 96, 96);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_6_main_main_default
//	static lv_style_t style_file_managemen_sd_img_6_main_main_default;
//	if (style_file_managemen_sd_img_6_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_6_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_6_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_6_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_6_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_6, &style_file_managemen_sd_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_img_9
//	ui->file_managemen_sd_img_9 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_9, 304, 82);
//	lv_obj_set_size(ui->file_managemen_sd_img_9, 96, 96);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_9_main_main_default
//	static lv_style_t style_file_managemen_sd_img_9_main_main_default;
//	if (style_file_managemen_sd_img_9_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_9_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_9_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_9_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_9_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_9, &style_file_managemen_sd_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_img_15
//	ui->file_managemen_sd_img_15 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_15, 304, 295);
//	lv_obj_set_size(ui->file_managemen_sd_img_15, 96, 96);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_15_main_main_default
//	static lv_style_t style_file_managemen_sd_img_15_main_main_default;
//	if (style_file_managemen_sd_img_15_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_15_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_15_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_15_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_15_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_15, &style_file_managemen_sd_img_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_img_18
//	ui->file_managemen_sd_img_18 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_18, 80, 508);
//	lv_obj_set_size(ui->file_managemen_sd_img_18, 96, 96);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_18_main_main_default
//	static lv_style_t style_file_managemen_sd_img_18_main_main_default;
//	if (style_file_managemen_sd_img_18_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_18_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_18_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_18_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_18_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_18_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_18, &style_file_managemen_sd_img_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_img_21
//	ui->file_managemen_sd_img_21 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_21, 304, 508);
//	lv_obj_set_size(ui->file_managemen_sd_img_21, 96, 96);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_21_main_main_default
//	static lv_style_t style_file_managemen_sd_img_21_main_main_default;
//	if (style_file_managemen_sd_img_21_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_21_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_21_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_21_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_21_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_21_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_21, &style_file_managemen_sd_img_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_img_24
//	ui->file_managemen_sd_img_24 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_24, 436, 615);
//	lv_obj_set_size(ui->file_managemen_sd_img_24, 24, 14);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_24_main_main_default
//	static lv_style_t style_file_managemen_sd_img_24_main_main_default;
//	if (style_file_managemen_sd_img_24_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_24_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_24_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_24_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_24_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_24_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_24, &style_file_managemen_sd_img_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_24, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_24,&_Vector_2_24x14);
//	lv_img_set_pivot(ui->file_managemen_sd_img_24, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_24, 0);
//
//	//Write codes file_managemen_sd_img_25
//	ui->file_managemen_sd_img_25 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_25, 436, 689);
//	lv_obj_set_size(ui->file_managemen_sd_img_25, 24, 14);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_25_main_main_default
//	static lv_style_t style_file_managemen_sd_img_25_main_main_default;
//	if (style_file_managemen_sd_img_25_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_25_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_25_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_25_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_25_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_25_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_25, &style_file_managemen_sd_img_25_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_25, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_25,&_Vector_3_24x14);
//	lv_img_set_pivot(ui->file_managemen_sd_img_25, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_25, 0);
//
//	//Write codes file_managemen_sd_img_12
//	ui->file_managemen_sd_img_12 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_12, 80, 295);
//	lv_obj_set_size(ui->file_managemen_sd_img_12, 96, 96);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_12_main_main_default
//	static lv_style_t style_file_managemen_sd_img_12_main_main_default;
//	if (style_file_managemen_sd_img_12_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_12_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_12_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_12_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_12_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_12, &style_file_managemen_sd_img_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//
//	//Write codes file_managemen_sd_img_7
//	ui->file_managemen_sd_img_7 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_7, 29, 244);
//	lv_obj_set_size(ui->file_managemen_sd_img_7, 18, 18);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_7_main_main_default
//	static lv_style_t style_file_managemen_sd_img_7_main_main_default;
//	if (style_file_managemen_sd_img_7_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_7_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_7_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_7_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_7_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_7, &style_file_managemen_sd_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_7, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_7,&_time_18x18);
//	lv_img_set_pivot(ui->file_managemen_sd_img_7, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_7, 0);
//
//	//Write codes file_managemen_sd_img_13
//	ui->file_managemen_sd_img_13 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_13, 29, 457);
//	lv_obj_set_size(ui->file_managemen_sd_img_13, 18, 18);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_13_main_main_default
//	static lv_style_t style_file_managemen_sd_img_13_main_main_default;
//	if (style_file_managemen_sd_img_13_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_13_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_13_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_13_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_13_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_13, &style_file_managemen_sd_img_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_13, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_13,&_time_18x18);
//	lv_img_set_pivot(ui->file_managemen_sd_img_13, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_13, 0);
//
//	//Write codes file_managemen_sd_img_19
//	ui->file_managemen_sd_img_19 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_19, 29, 670);
//	lv_obj_set_size(ui->file_managemen_sd_img_19, 18, 18);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_19_main_main_default
//	static lv_style_t style_file_managemen_sd_img_19_main_main_default;
//	if (style_file_managemen_sd_img_19_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_19_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_19_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_19_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_19_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_19_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_19, &style_file_managemen_sd_img_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_19, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_19,&_time_18x18);
//	lv_img_set_pivot(ui->file_managemen_sd_img_19, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_19, 0);
//
//	//Write codes file_managemen_sd_img_22
//	ui->file_managemen_sd_img_22 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_22, 255, 670);
//	lv_obj_set_size(ui->file_managemen_sd_img_22, 18, 18);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_22_main_main_default
//	static lv_style_t style_file_managemen_sd_img_22_main_main_default;
//	if (style_file_managemen_sd_img_22_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_22_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_22_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_22_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_22_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_22_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_22, &style_file_managemen_sd_img_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_22, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_22,&_time_18x18);
//	lv_img_set_pivot(ui->file_managemen_sd_img_22, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_22, 0);
//
//	//Write codes file_managemen_sd_img_16
//	ui->file_managemen_sd_img_16 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_16, 255, 457);
//	lv_obj_set_size(ui->file_managemen_sd_img_16, 18, 18);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_16_main_main_default
//	static lv_style_t style_file_managemen_sd_img_16_main_main_default;
//	if (style_file_managemen_sd_img_16_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_16_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_16_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_16_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_16_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_16, &style_file_managemen_sd_img_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_16, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_16,&_time_18x18);
//	lv_img_set_pivot(ui->file_managemen_sd_img_16, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_16, 0);
//
//	//Write codes file_managemen_sd_img_10
//	ui->file_managemen_sd_img_10 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_10, 255, 244);
//	lv_obj_set_size(ui->file_managemen_sd_img_10, 18, 18);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_10_main_main_default
//	static lv_style_t style_file_managemen_sd_img_10_main_main_default;
//	if (style_file_managemen_sd_img_10_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_10_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_10_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_10_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_10_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_10, &style_file_managemen_sd_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_10, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_10,&_time_18x18);
//	lv_img_set_pivot(ui->file_managemen_sd_img_10, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_10, 0);
//
//	//Write codes file_managemen_sd_img_8
//	ui->file_managemen_sd_img_8 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_8, 124, 246);
//	lv_obj_set_size(ui->file_managemen_sd_img_8, 16, 16);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_8_main_main_default
//	static lv_style_t style_file_managemen_sd_img_8_main_main_default;
//	if (style_file_managemen_sd_img_8_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_8_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_8_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_8_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_8_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_8, &style_file_managemen_sd_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_8, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_8,&_file_logo2_16x16);
//	lv_img_set_pivot(ui->file_managemen_sd_img_8, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_8, 0);
//
//	//Write codes file_managemen_sd_img_14
//	ui->file_managemen_sd_img_14 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_14, 124, 459);
//	lv_obj_set_size(ui->file_managemen_sd_img_14, 16, 16);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_14_main_main_default
//	static lv_style_t style_file_managemen_sd_img_14_main_main_default;
//	if (style_file_managemen_sd_img_14_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_14_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_14_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_14_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_14_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_14, &style_file_managemen_sd_img_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_14, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_14,&_file_logo2_16x16);
//	lv_img_set_pivot(ui->file_managemen_sd_img_14, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_14, 0);
//
//	//Write codes file_managemen_sd_img_20
//	ui->file_managemen_sd_img_20 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_20, 124, 672);
//	lv_obj_set_size(ui->file_managemen_sd_img_20, 16, 16);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_20_main_main_default
//	static lv_style_t style_file_managemen_sd_img_20_main_main_default;
//	if (style_file_managemen_sd_img_20_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_20_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_20_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_20_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_20_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_20_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_20, &style_file_managemen_sd_img_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_20, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_20,&_file_logo2_16x16);
//	lv_img_set_pivot(ui->file_managemen_sd_img_20, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_20, 0);
//
//	//Write codes file_managemen_sd_img_23
//	ui->file_managemen_sd_img_23 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_23, 350, 672);
//	lv_obj_set_size(ui->file_managemen_sd_img_23, 16, 16);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_23_main_main_default
//	static lv_style_t style_file_managemen_sd_img_23_main_main_default;
//	if (style_file_managemen_sd_img_23_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_23_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_23_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_23_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_23_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_23_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_23, &style_file_managemen_sd_img_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_23, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_23,&_file_logo2_16x16);
//	lv_img_set_pivot(ui->file_managemen_sd_img_23, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_23, 0);
//
//	//Write codes file_managemen_sd_img_17
//	ui->file_managemen_sd_img_17 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_17, 350, 459);
//	lv_obj_set_size(ui->file_managemen_sd_img_17, 16, 16);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_17_main_main_default
//	static lv_style_t style_file_managemen_sd_img_17_main_main_default;
//	if (style_file_managemen_sd_img_17_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_17_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_17_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_17_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_17_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_17_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_17, &style_file_managemen_sd_img_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_17, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_17,&_file_logo2_16x16);
//	lv_img_set_pivot(ui->file_managemen_sd_img_17, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_17, 0);
//
//	//Write codes file_managemen_sd_img_11
//	ui->file_managemen_sd_img_11 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_11, 350, 246);
//	lv_obj_set_size(ui->file_managemen_sd_img_11, 16, 16);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_11_main_main_default
//	static lv_style_t style_file_managemen_sd_img_11_main_main_default;
//	if (style_file_managemen_sd_img_11_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_11_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_11_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_11_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_11_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_11, &style_file_managemen_sd_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_11, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_11,&_file_logo2_16x16);
//	lv_img_set_pivot(ui->file_managemen_sd_img_11, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_11, 0);
//
//	//Write codes file_managemen_sd_img_1
//	ui->file_managemen_sd_img_1 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_1, 30, 742);
//	lv_obj_set_size(ui->file_managemen_sd_img_1, 48, 48);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_1_main_main_default
//	static lv_style_t style_file_managemen_sd_img_1_main_main_default;
//	if (style_file_managemen_sd_img_1_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_1_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_1_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_1_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_1_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_1, &style_file_managemen_sd_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_1, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_1,&_home_48x48);
//	lv_img_set_pivot(ui->file_managemen_sd_img_1, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_1, 0);
//
//	//Write codes file_managemen_sd_img_2
//	ui->file_managemen_sd_img_2 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_2, 128, 742);
//	lv_obj_set_size(ui->file_managemen_sd_img_2, 48, 48);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_2_main_main_default
//	static lv_style_t style_file_managemen_sd_img_2_main_main_default;
//	if (style_file_managemen_sd_img_2_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_2_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_2_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_2_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_2_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_2, &style_file_managemen_sd_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_2, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_2,&_prepare_48x48);
//	lv_img_set_pivot(ui->file_managemen_sd_img_2, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_2, 0);
//
//	//Write codes file_managemen_sd_img_3
//	ui->file_managemen_sd_img_3 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_3, 224, 742);
//	lv_obj_set_size(ui->file_managemen_sd_img_3, 48, 48);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_3_main_main_default
//	static lv_style_t style_file_managemen_sd_img_3_main_main_default;
//	if (style_file_managemen_sd_img_3_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_3_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_3_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_3_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_3_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_3, &style_file_managemen_sd_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_3, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_3,&_files_48x48);
//	lv_img_set_pivot(ui->file_managemen_sd_img_3, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_3, 0);
//
//	//Write codes file_managemen_sd_img_4
//	ui->file_managemen_sd_img_4 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_4, 318, 742);
//	lv_obj_set_size(ui->file_managemen_sd_img_4, 48, 48);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_4_main_main_default
//	static lv_style_t style_file_managemen_sd_img_4_main_main_default;
//	if (style_file_managemen_sd_img_4_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_4_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_4_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_4_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_4_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_4, &style_file_managemen_sd_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_4, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_4,&_seting_48x48);
//	lv_img_set_pivot(ui->file_managemen_sd_img_4, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_4, 0);
//
//	//Write codes file_managemen_sd_img_5
//	ui->file_managemen_sd_img_5 = lv_img_create(ui->file_managemen_sd_cont_1);
//	lv_obj_set_pos(ui->file_managemen_sd_img_5, 414, 742);
//	lv_obj_set_size(ui->file_managemen_sd_img_5, 48, 48);
//
//	//Write style state: LV_STATE_DEFAULT for style_file_managemen_sd_img_5_main_main_default
//	static lv_style_t style_file_managemen_sd_img_5_main_main_default;
//	if (style_file_managemen_sd_img_5_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_file_managemen_sd_img_5_main_main_default);
//	else
//		lv_style_init(&style_file_managemen_sd_img_5_main_main_default);
//	lv_style_set_img_recolor(&style_file_managemen_sd_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_img_recolor_opa(&style_file_managemen_sd_img_5_main_main_default, 0);
//	lv_style_set_img_opa(&style_file_managemen_sd_img_5_main_main_default, 255);
//	lv_obj_add_style(ui->file_managemen_sd_img_5, &style_file_managemen_sd_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_add_flag(ui->file_managemen_sd_img_5, LV_OBJ_FLAG_CLICKABLE);
//	lv_img_set_src(ui->file_managemen_sd_img_5,&_FAQ_48x48);
//	lv_img_set_pivot(ui->file_managemen_sd_img_5, 0,0);
//	lv_img_set_angle(ui->file_managemen_sd_img_5, 0);
}
