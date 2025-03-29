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

#define X_POSITION -16
#define Y_POSITION -16-50
void setup_scr_file_management(lv_ui *ui){

    //Write codes file_management_cont_1
	ui->file_management_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->file_management_cont_1, 0, 0);
	lv_obj_set_size(ui->file_management_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_file_management_cont_1_main_main_default
	static lv_style_t style_file_management_cont_1_main_main_default;
	if (style_file_management_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_cont_1_main_main_default);
	else
		lv_style_init(&style_file_management_cont_1_main_main_default);
	lv_style_set_radius(&style_file_management_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_file_management_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_file_management_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_file_management_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_file_management_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_file_management_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_file_management_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->file_management_cont_1, &style_file_management_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_tabview_1
	ui->file_management_tabview_1 = lv_tabview_create(ui->file_management_cont_1, LV_DIR_TOP, 47);
	lv_obj_set_pos(ui->file_management_tabview_1, 0, 0);
	lv_obj_set_size(ui->file_management_tabview_1, 480, 720);

	//title1
	ui->file_management_tabview_1_title1 = lv_tabview_add_tab(ui->file_management_tabview_1,"本地");

	//title2
	ui->file_management_tabview_1_title2 = lv_tabview_add_tab(ui->file_management_tabview_1,"U盘");

	//title3
	ui->file_management_tabview_1_title3 = lv_tabview_add_tab(ui->file_management_tabview_1,"历史记录");

    lv_obj_scroll_to_view_recursive(ui->file_management_tabview_1_title1, LV_ANIM_ON);
    lv_obj_scroll_to_view_recursive(ui->file_management_tabview_1_title2, LV_ANIM_ON);
    lv_obj_scroll_to_view_recursive(ui->file_management_tabview_1_title3, LV_ANIM_ON);

	//Write style state: LV_STATE_DEFAULT for style_file_management_tabview_1_main_main_default
	static lv_style_t style_file_management_tabview_1_main_main_default;
	if (style_file_management_tabview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_tabview_1_main_main_default);
	else
		lv_style_init(&style_file_management_tabview_1_main_main_default);
	lv_style_set_bg_color(&style_file_management_tabview_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_file_management_tabview_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_file_management_tabview_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_tabview_1_main_main_default, 255);
	lv_style_set_border_color(&style_file_management_tabview_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_file_management_tabview_1_main_main_default, 0);
	lv_style_set_border_opa(&style_file_management_tabview_1_main_main_default, 100);
	lv_style_set_text_color(&style_file_management_tabview_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_file_management_tabview_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_tabview_1_main_main_default, 0);
	lv_style_set_text_line_space(&style_file_management_tabview_1_main_main_default, 16);
	lv_obj_add_style(ui->file_management_tabview_1, &style_file_management_tabview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_file_management_tabview_1_extra_btnm_main_default
	static lv_style_t style_file_management_tabview_1_extra_btnm_main_default;
	if (style_file_management_tabview_1_extra_btnm_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_tabview_1_extra_btnm_main_default);
	else
		lv_style_init(&style_file_management_tabview_1_extra_btnm_main_default);
	lv_style_set_bg_color(&style_file_management_tabview_1_extra_btnm_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_file_management_tabview_1_extra_btnm_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_file_management_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_border_color(&style_file_management_tabview_1_extra_btnm_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_file_management_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_border_opa(&style_file_management_tabview_1_extra_btnm_main_default, 100);
	lv_style_set_pad_left(&style_file_management_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_right(&style_file_management_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_top(&style_file_management_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_tabview_1_extra_btnm_main_default, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->file_management_tabview_1), &style_file_management_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_file_management_tabview_1_extra_btnm_items_default
	static lv_style_t style_file_management_tabview_1_extra_btnm_items_default;
	if (style_file_management_tabview_1_extra_btnm_items_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_tabview_1_extra_btnm_items_default);
	else
		lv_style_init(&style_file_management_tabview_1_extra_btnm_items_default);
	lv_style_set_text_color(&style_file_management_tabview_1_extra_btnm_items_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_file_management_tabview_1_extra_btnm_items_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->file_management_tabview_1), &style_file_management_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_file_management_tabview_1_extra_btnm_items_checked
	static lv_style_t style_file_management_tabview_1_extra_btnm_items_checked;
	if (style_file_management_tabview_1_extra_btnm_items_checked.prop_cnt > 1)
		lv_style_reset(&style_file_management_tabview_1_extra_btnm_items_checked);
	else
		lv_style_init(&style_file_management_tabview_1_extra_btnm_items_checked);
	lv_style_set_bg_color(&style_file_management_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_file_management_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_file_management_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_tabview_1_extra_btnm_items_checked, 60);
	lv_style_set_border_color(&style_file_management_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_file_management_tabview_1_extra_btnm_items_checked, 4);
	lv_style_set_border_opa(&style_file_management_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_side(&style_file_management_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_text_color(&style_file_management_tabview_1_extra_btnm_items_checked, lv_color_make(0xFF, 0xFF, 0xFF));
	lv_style_set_text_font(&style_file_management_tabview_1_extra_btnm_items_checked, &lv_font_simsun_24);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->file_management_tabview_1), &style_file_management_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes file_management_label_1
	ui->file_management_label_1 = lv_label_create(ui->file_management_cont_1);
	lv_obj_set_pos(ui->file_management_label_1, 0, 720);
	lv_obj_set_size(ui->file_management_label_1, 480, 80);
	lv_label_set_text(ui->file_management_label_1, "");
	lv_label_set_long_mode(ui->file_management_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_1_main_main_default
	static lv_style_t style_file_management_label_1_main_main_default;
	if (style_file_management_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_1_main_main_default);
	else
		lv_style_init(&style_file_management_label_1_main_main_default);
	lv_style_set_radius(&style_file_management_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_file_management_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_file_management_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_1_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_1, &style_file_management_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_26_main_main_default
	static lv_style_t style_file_management_label_26_main_main_default;
	if (style_file_management_label_26_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_26_main_main_default);
	else
		lv_style_init(&style_file_management_label_26_main_main_default);
	lv_style_set_radius(&style_file_management_label_26_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_26_main_main_default, lv_color_make(0x2D, 0x2E, 0x31));
	lv_style_set_bg_grad_color(&style_file_management_label_26_main_main_default, lv_color_make(0x2D, 0x2E, 0x31));
	lv_style_set_bg_grad_dir(&style_file_management_label_26_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_26_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_26_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_letter_space(&style_file_management_label_26_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_26_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_26_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_26_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_26_main_main_default, 0);

	//Write codes file_management_label_26
	ui->file_management_label_26 = lv_label_create(ui->file_management_tabview_1_title1);
	lv_obj_set_size(ui->file_management_label_26, 450, 647);
	lv_obj_align(ui->file_management_label_26,LV_ALIGN_TOP_LEFT,-2,-10);
	lv_label_set_text(ui->file_management_label_26, "");
	lv_label_set_long_mode(ui->file_management_label_26, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_26, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_style(ui->file_management_label_26, &style_file_management_label_26_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_27
	ui->file_management_label_27 = lv_label_create(ui->file_management_tabview_1_title2);
	lv_obj_set_size(ui->file_management_label_27, 450, 647);
	lv_obj_align(ui->file_management_label_27,LV_ALIGN_TOP_LEFT,-2,-10);
	lv_label_set_text(ui->file_management_label_27, "");
	lv_label_set_long_mode(ui->file_management_label_27, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_27, LV_TEXT_ALIGN_CENTER, 0);

	lv_obj_add_style(ui->file_management_label_27, &style_file_management_label_26_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_28_main_main_default
	static lv_style_t style_file_management_label_28_main_main_default;
	if (style_file_management_label_28_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_28_main_main_default);
	else
		lv_style_init(&style_file_management_label_28_main_main_default);
	lv_style_set_radius(&style_file_management_label_28_main_main_default, 8);
	lv_style_set_bg_color(&style_file_management_label_28_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_28_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_28_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_28_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_28_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_label_28_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_28_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_28_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_28_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_28_main_main_default, 0);

	//Write codes file_management_label_28
	ui->file_management_label_28 = lv_label_create(ui->file_management_tabview_1_title2);
	lv_obj_set_size(ui->file_management_label_28, 96, 36);
	lv_obj_align(ui->file_management_label_28,LV_ALIGN_CENTER,0,0);
	lv_label_set_text(ui->file_management_label_28, "");
	lv_label_set_long_mode(ui->file_management_label_28, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_28, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_style(ui->file_management_label_28, &style_file_management_label_28_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_29
	ui->file_management_label_29 = lv_label_create(ui->file_management_tabview_1_title1);
	lv_obj_set_size(ui->file_management_label_29, 96, 36);
	lv_obj_align(ui->file_management_label_29,LV_ALIGN_CENTER,0,0);
	lv_label_set_text(ui->file_management_label_29, "");
	lv_label_set_long_mode(ui->file_management_label_29, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_29, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_style(ui->file_management_label_29, &style_file_management_label_28_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_2
	ui->file_management_label_2 = lv_label_create(ui->file_management_tabview_1_title1);
    lv_obj_align(ui->file_management_label_2,LV_ALIGN_TOP_LEFT,0,0);
	lv_obj_set_size(ui->file_management_label_2, 215, 203);
	lv_label_set_text(ui->file_management_label_2, "");
	lv_obj_add_flag(ui->file_management_label_2, LV_OBJ_FLAG_CLICKABLE);
	lv_label_set_long_mode(ui->file_management_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_2_main_main_default
	static lv_style_t style_file_management_label_2_main_main_default;
	if (style_file_management_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_2_main_main_default);
	else
		lv_style_init(&style_file_management_label_2_main_main_default);
	lv_style_set_radius(&style_file_management_label_2_main_main_default, 8);
	lv_style_set_bg_color(&style_file_management_label_2_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_2_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_2_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_2, &style_file_management_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_6
	ui->file_management_label_6 = lv_label_create(ui->file_management_tabview_1_title1);
    lv_obj_align(ui->file_management_label_6,LV_ALIGN_TOP_RIGHT,0,0);
	lv_obj_set_size(ui->file_management_label_6, 215, 203);
	lv_label_set_text(ui->file_management_label_6, "");
	lv_obj_add_flag(ui->file_management_label_6, LV_OBJ_FLAG_CLICKABLE);
	lv_label_set_long_mode(ui->file_management_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_6, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_6_main_main_default
	static lv_style_t style_file_management_label_6_main_main_default;
	if (style_file_management_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_6_main_main_default);
	else
		lv_style_init(&style_file_management_label_6_main_main_default);
	lv_style_set_radius(&style_file_management_label_6_main_main_default, 8);
	lv_style_set_bg_color(&style_file_management_label_6_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_6_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_6_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_6_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_6, &style_file_management_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_10
	ui->file_management_label_10 = lv_label_create(ui->file_management_tabview_1_title1);
	lv_obj_align_to(ui->file_management_label_10,ui->file_management_label_2,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
	lv_obj_set_size(ui->file_management_label_10, 215, 203);
	lv_label_set_text(ui->file_management_label_10, "");
	lv_obj_add_flag(ui->file_management_label_10, LV_OBJ_FLAG_CLICKABLE);
	lv_label_set_long_mode(ui->file_management_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_10, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_10_main_main_default
	static lv_style_t style_file_management_label_10_main_main_default;
	if (style_file_management_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_10_main_main_default);
	else
		lv_style_init(&style_file_management_label_10_main_main_default);
	lv_style_set_radius(&style_file_management_label_10_main_main_default, 8);
	lv_style_set_bg_color(&style_file_management_label_10_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_10_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_10_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_10_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_10, &style_file_management_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_11
	ui->file_management_label_11 = lv_label_create(ui->file_management_tabview_1_title1);
    lv_obj_set_size(ui->file_management_label_11, 215, 203);
	lv_obj_align_to(ui->file_management_label_11,ui->file_management_label_6,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
	lv_label_set_text(ui->file_management_label_11, "");
	lv_obj_add_flag(ui->file_management_label_11, LV_OBJ_FLAG_CLICKABLE);
	lv_label_set_long_mode(ui->file_management_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_11, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_11_main_main_default
	static lv_style_t style_file_management_label_11_main_main_default;
	if (style_file_management_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_11_main_main_default);
	else
		lv_style_init(&style_file_management_label_11_main_main_default);
	lv_style_set_radius(&style_file_management_label_11_main_main_default, 8);
	lv_style_set_bg_color(&style_file_management_label_11_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_11_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_11_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_label_11_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_11_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_11, &style_file_management_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_12
	ui->file_management_label_12 = lv_label_create(ui->file_management_tabview_1_title1);
	lv_obj_align_to(ui->file_management_label_12,ui->file_management_label_10,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
	lv_obj_set_size(ui->file_management_label_12, 215, 203);
	lv_label_set_text(ui->file_management_label_12, "");
	lv_obj_add_flag(ui->file_management_label_12, LV_OBJ_FLAG_CLICKABLE);
	lv_label_set_long_mode(ui->file_management_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_12, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_12_main_main_default
	static lv_style_t style_file_management_label_12_main_main_default;
	if (style_file_management_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_12_main_main_default);
	else
		lv_style_init(&style_file_management_label_12_main_main_default);
	lv_style_set_radius(&style_file_management_label_12_main_main_default, 8);
	lv_style_set_bg_color(&style_file_management_label_12_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_12_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_12_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_label_12_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_12_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_12, &style_file_management_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_13
	ui->file_management_label_13 = lv_label_create(ui->file_management_tabview_1_title1);
	lv_obj_align_to(ui->file_management_label_13,ui->file_management_label_11,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
	lv_obj_set_size(ui->file_management_label_13, 215, 203);
	lv_label_set_text(ui->file_management_label_13, "");
	lv_obj_add_flag(ui->file_management_label_13, LV_OBJ_FLAG_CLICKABLE);
	lv_label_set_long_mode(ui->file_management_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_13, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_13_main_main_default
	static lv_style_t style_file_management_label_13_main_main_default;
	if (style_file_management_label_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_13_main_main_default);
	else
		lv_style_init(&style_file_management_label_13_main_main_default);
	lv_style_set_radius(&style_file_management_label_13_main_main_default, 8);
	lv_style_set_bg_color(&style_file_management_label_13_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_13_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_13_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_13_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_file_management_label_13_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_13_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_13_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_13_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_13_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_13, &style_file_management_label_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_6
	ui->file_management_img_6 = lv_img_create(ui->file_management_label_2);
	lv_obj_set_size(ui->file_management_img_6, 96, 96);
	lv_obj_align(ui->file_management_img_6,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_6_main_main_default
	static lv_style_t style_file_management_img_6_main_main_default;
	if (style_file_management_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_6_main_main_default);
	else
		lv_style_init(&style_file_management_img_6_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_6_main_main_default, 255);
	lv_img_set_src(ui->file_management_img_6,&_time_18x18);
	lv_obj_add_style(ui->file_management_img_6, &style_file_management_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//Write codes file_management_label_3
	ui->file_management_label_3 = lv_label_create(ui->file_management_label_2);
    lv_obj_set_size(ui->file_management_label_3, 199, 42);
	lv_obj_align_to(ui->file_management_label_3,ui->file_management_img_6,LV_ALIGN_OUT_BOTTOM_MID,0,10);
	lv_label_set_text(ui->file_management_label_3, "test.gcod111e");
	lv_label_set_long_mode(ui->file_management_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_3, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_3_main_main_default
	static lv_style_t style_file_management_label_3_main_main_default;
	if (style_file_management_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_3_main_main_default);
	else
		lv_style_init(&style_file_management_label_3_main_main_default);
	lv_style_set_radius(&style_file_management_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_3_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_3_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_3_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_3, &style_file_management_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_7
	ui->file_management_img_7 = lv_img_create(ui->file_management_label_2);
	lv_obj_set_size(ui->file_management_img_7, 18, 18);
    lv_obj_align(ui->file_management_img_7,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_7_main_main_default
	static lv_style_t style_file_management_img_7_main_main_default;
	if (style_file_management_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_7_main_main_default);
	else
		lv_style_init(&style_file_management_img_7_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_7_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_7, &style_file_management_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_7,&_time_18x18);
	lv_img_set_pivot(ui->file_management_img_7, 0,0);
	lv_img_set_angle(ui->file_management_img_7, 0);

    //Write codes file_management_label_4
	ui->file_management_label_4 = lv_label_create(ui->file_management_label_2);
	lv_obj_set_size(ui->file_management_label_4, 57, 24);
	lv_obj_align_to(ui->file_management_label_4,ui->file_management_img_7,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_4, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_4_main_main_default
	static lv_style_t style_file_management_label_4_main_main_default;
	if (style_file_management_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_4_main_main_default);
	else
		lv_style_init(&style_file_management_label_4_main_main_default);
	lv_style_set_radius(&style_file_management_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_4_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_4_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_4_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_4, &style_file_management_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_8
	ui->file_management_img_8 = lv_img_create(ui->file_management_label_2);
	lv_obj_set_size(ui->file_management_img_8, 16, 16);
	lv_obj_align_to(ui->file_management_img_8,ui->file_management_img_7,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_8_main_main_default
	static lv_style_t style_file_management_img_8_main_main_default;
	if (style_file_management_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_8_main_main_default);
	else
		lv_style_init(&style_file_management_img_8_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_8_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_8, &style_file_management_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_8,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_img_8, 0,0);
	lv_img_set_angle(ui->file_management_img_8, 0);

    //Write codes file_management_label_5
	ui->file_management_label_5 = lv_label_create(ui->file_management_label_2);
	lv_obj_set_size(ui->file_management_label_5, 57, 24);
	lv_obj_align_to(ui->file_management_label_5,ui->file_management_img_8,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_5, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_5_main_main_default
	static lv_style_t style_file_management_label_5_main_main_default;
	if (style_file_management_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_5_main_main_default);
	else
		lv_style_init(&style_file_management_label_5_main_main_default);
	lv_style_set_radius(&style_file_management_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_5_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_5_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_5_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_5, &style_file_management_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_9
	ui->file_management_img_9 = lv_img_create(ui->file_management_label_6);
	lv_obj_set_size(ui->file_management_img_9, 96, 96);
	lv_obj_align(ui->file_management_img_9,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_9_main_main_default
	static lv_style_t style_file_management_img_9_main_main_default;
	if (style_file_management_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_9_main_main_default);
	else
		lv_style_init(&style_file_management_img_9_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_9_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_9, &style_file_management_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_label_7
	ui->file_management_label_7 = lv_label_create(ui->file_management_label_6);
	lv_obj_align_to(ui->file_management_label_7,ui->file_management_label_6,LV_ALIGN_TOP_LEFT,10,116);
	lv_obj_set_size(ui->file_management_label_7, 199, 42);
	lv_label_set_text(ui->file_management_label_7, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_7_main_main_default
	static lv_style_t style_file_management_label_7_main_main_default;
	if (style_file_management_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_7_main_main_default);
	else
		lv_style_init(&style_file_management_label_7_main_main_default);
	lv_style_set_radius(&style_file_management_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_7_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_7_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_7_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_7_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_7, &style_file_management_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

		//Write codes file_management_img_10
	ui->file_management_img_10 = lv_img_create(ui->file_management_label_6);
	lv_obj_set_size(ui->file_management_img_10, 18, 18);
	lv_obj_align_to(ui->file_management_img_10,ui->file_management_label_6,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_10_main_main_default
	static lv_style_t style_file_management_img_10_main_main_default;
	if (style_file_management_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_10_main_main_default);
	else
		lv_style_init(&style_file_management_img_10_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_10_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_10, &style_file_management_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_10,&_time_18x18);
	lv_img_set_pivot(ui->file_management_img_10, 0,0);
	lv_img_set_angle(ui->file_management_img_10, 0);

	//Write codes file_management_label_8
	ui->file_management_label_8 = lv_label_create(ui->file_management_label_6);
	lv_obj_set_size(ui->file_management_label_8, 57, 24);
	lv_obj_align_to(ui->file_management_label_8,ui->file_management_img_10,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_8, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_8_main_main_default
	static lv_style_t style_file_management_label_8_main_main_default;
	if (style_file_management_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_8_main_main_default);
	else
		lv_style_init(&style_file_management_label_8_main_main_default);
	lv_style_set_radius(&style_file_management_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_8_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_8_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_8_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_8, &style_file_management_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_11
	ui->file_management_img_11 = lv_img_create(ui->file_management_label_6);
	lv_obj_set_size(ui->file_management_img_11, 16, 16);
	lv_obj_align_to(ui->file_management_img_11,ui->file_management_img_10,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_11_main_main_default
	static lv_style_t style_file_management_img_11_main_main_default;
	if (style_file_management_img_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_11_main_main_default);
	else
		lv_style_init(&style_file_management_img_11_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_11_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_11_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_11, &style_file_management_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_11,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_img_11, 0,0);
	lv_img_set_angle(ui->file_management_img_11, 0);

    //Write codes file_management_label_9
	ui->file_management_label_9 = lv_label_create(ui->file_management_label_6);
	lv_obj_set_size(ui->file_management_label_9, 57, 24);
	lv_obj_align_to(ui->file_management_label_9,ui->file_management_img_11,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_9, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_9, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_9_main_main_default
	static lv_style_t style_file_management_label_9_main_main_default;
	if (style_file_management_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_9_main_main_default);
	else
		lv_style_init(&style_file_management_label_9_main_main_default);
	lv_style_set_radius(&style_file_management_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_9_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_9_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_9_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_9_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_9, &style_file_management_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_12
	ui->file_management_img_12 = lv_img_create(ui->file_management_label_10);
	lv_obj_set_size(ui->file_management_img_12, 96, 96);
	lv_obj_align(ui->file_management_img_12,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_12_main_main_default
	static lv_style_t style_file_management_img_12_main_main_default;
	if (style_file_management_img_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_12_main_main_default);
	else
		lv_style_init(&style_file_management_img_12_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_12_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_12_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_12, &style_file_management_img_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_label_14
	ui->file_management_label_14 = lv_label_create(ui->file_management_label_10);
	lv_obj_set_size(ui->file_management_label_14, 199, 42);
	lv_obj_align_to(ui->file_management_label_14,ui->file_management_label_10,LV_ALIGN_TOP_LEFT,10,116);
	lv_label_set_text(ui->file_management_label_14, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_14, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_14_main_main_default
	static lv_style_t style_file_management_label_14_main_main_default;
	if (style_file_management_label_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_14_main_main_default);
	else
		lv_style_init(&style_file_management_label_14_main_main_default);
	lv_style_set_radius(&style_file_management_label_14_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_14_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_14_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_14_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_14_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_14_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_14_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_14_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_14_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_14_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_14_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_14, &style_file_management_label_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_13
	ui->file_management_img_13 = lv_img_create(ui->file_management_label_10);
	lv_obj_set_size(ui->file_management_img_13, 18, 18);
	lv_obj_align_to(ui->file_management_img_13,ui->file_management_label_10,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_13_main_main_default
	static lv_style_t style_file_management_img_13_main_main_default;
	if (style_file_management_img_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_13_main_main_default);
	else
		lv_style_init(&style_file_management_img_13_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_13_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_13_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_13, &style_file_management_img_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_13, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_13,&_time_18x18);
	lv_img_set_pivot(ui->file_management_img_13, 0,0);
	lv_img_set_angle(ui->file_management_img_13, 0);

    //Write codes file_management_label_15
	ui->file_management_label_15 = lv_label_create(ui->file_management_label_10);
	lv_obj_set_size(ui->file_management_label_15, 57, 24);
	lv_obj_align_to(ui->file_management_label_15,ui->file_management_img_13,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_15, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_15, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_15_main_main_default
	static lv_style_t style_file_management_label_15_main_main_default;
	if (style_file_management_label_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_15_main_main_default);
	else
		lv_style_init(&style_file_management_label_15_main_main_default);
	lv_style_set_radius(&style_file_management_label_15_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_15_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_15_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_15_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_15_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_15_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_15_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_15_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_15_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_15_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_15_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_15, &style_file_management_label_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_14
	ui->file_management_img_14 = lv_img_create(ui->file_management_label_10);
	lv_obj_set_size(ui->file_management_img_14, 16, 16);
	lv_obj_align_to(ui->file_management_img_14,ui->file_management_img_13,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_14_main_main_default
	static lv_style_t style_file_management_img_14_main_main_default;
	if (style_file_management_img_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_14_main_main_default);
	else
		lv_style_init(&style_file_management_img_14_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_14_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_14_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_14, &style_file_management_img_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_14, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_14,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_img_14, 0,0);
	lv_img_set_angle(ui->file_management_img_14, 0);

    //Write codes file_management_label_16
	ui->file_management_label_16 = lv_label_create(ui->file_management_label_10);
	lv_obj_set_size(ui->file_management_label_16, 57, 24);
	lv_obj_align_to(ui->file_management_label_16,ui->file_management_img_14,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_16, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_16, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_16_main_main_default
	static lv_style_t style_file_management_label_16_main_main_default;
	if (style_file_management_label_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_16_main_main_default);
	else
		lv_style_init(&style_file_management_label_16_main_main_default);
	lv_style_set_radius(&style_file_management_label_16_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_16_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_16_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_16_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_16_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_16_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_16_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_16_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_16_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_16_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_16_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_16, &style_file_management_label_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_15
	ui->file_management_img_15 = lv_img_create(ui->file_management_label_11);
	lv_obj_set_size(ui->file_management_img_15, 96, 96);
	lv_obj_align(ui->file_management_img_15,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_15_main_main_default
	static lv_style_t style_file_management_img_15_main_main_default;
	if (style_file_management_img_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_15_main_main_default);
	else
		lv_style_init(&style_file_management_img_15_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_15_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_15_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_15, &style_file_management_img_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_img_set_src(ui->file_management_img_15,&_time_18x18);

	//Write codes file_management_label_17
	ui->file_management_label_17 = lv_label_create(ui->file_management_label_11);
	lv_obj_set_size(ui->file_management_label_17, 199, 42);
	lv_obj_align(ui->file_management_label_17,LV_ALIGN_TOP_MID,0,116);
	lv_label_set_text(ui->file_management_label_17, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_17, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_17_main_main_default
	static lv_style_t style_file_management_label_17_main_main_default;
	if (style_file_management_label_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_17_main_main_default);
	else
		lv_style_init(&style_file_management_label_17_main_main_default);
	lv_style_set_radius(&style_file_management_label_17_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_17_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_17_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_17_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_17_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_17_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_17_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_17_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_17_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_17_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_17_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_17_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_17, &style_file_management_label_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_16
	ui->file_management_img_16 = lv_img_create(ui->file_management_label_11);
	lv_obj_set_size(ui->file_management_img_16, 18, 18);
	lv_obj_align_to(ui->file_management_img_16,ui->file_management_label_11,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_16_main_main_default
	static lv_style_t style_file_management_img_16_main_main_default;
	if (style_file_management_img_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_16_main_main_default);
	else
		lv_style_init(&style_file_management_img_16_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_16_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_16_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_16, &style_file_management_img_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_16, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_16,&_time_18x18);
	lv_img_set_pivot(ui->file_management_img_16, 0,0);
	lv_img_set_angle(ui->file_management_img_16, 0);

    //Write codes file_management_label_18
	ui->file_management_label_18 = lv_label_create(ui->file_management_label_11);
	lv_obj_set_size(ui->file_management_label_18, 57, 24);
	lv_obj_align_to(ui->file_management_label_18,ui->file_management_img_16,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_18, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_18, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_18_main_main_default
	static lv_style_t style_file_management_label_18_main_main_default;
	if (style_file_management_label_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_18_main_main_default);
	else
		lv_style_init(&style_file_management_label_18_main_main_default);
	lv_style_set_radius(&style_file_management_label_18_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_18_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_18_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_18_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_18_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_18_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_18_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_18_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_18_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_18_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_18_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_18_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_18, &style_file_management_label_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_17
	ui->file_management_img_17 = lv_img_create(ui->file_management_label_11);
	lv_obj_set_size(ui->file_management_img_17, 16, 16);
	lv_obj_align_to(ui->file_management_img_17,ui->file_management_img_16,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_17_main_main_default
	static lv_style_t style_file_management_img_17_main_main_default;
	if (style_file_management_img_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_17_main_main_default);
	else
		lv_style_init(&style_file_management_img_17_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_17_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_17_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_17_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_17, &style_file_management_img_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_17, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_17,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_img_17, 0,0);
	lv_img_set_angle(ui->file_management_img_17, 0);

	//Write codes file_management_label_19
	ui->file_management_label_19 = lv_label_create(ui->file_management_label_11);
	lv_obj_set_size(ui->file_management_label_19, 57, 24);
	lv_obj_align_to(ui->file_management_label_19,ui->file_management_img_17,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_19, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_19, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_19, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_19_main_main_default
	static lv_style_t style_file_management_label_19_main_main_default;
	if (style_file_management_label_19_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_19_main_main_default);
	else
		lv_style_init(&style_file_management_label_19_main_main_default);
	lv_style_set_radius(&style_file_management_label_19_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_19_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_19_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_19_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_19_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_19_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_19_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_19_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_19_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_19_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_19_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_19_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_19, &style_file_management_label_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_18
	ui->file_management_img_18 = lv_img_create(ui->file_management_label_12);
	lv_obj_set_size(ui->file_management_img_18, 96, 96);
	lv_obj_align(ui->file_management_img_18,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_18_main_main_default
	static lv_style_t style_file_management_img_18_main_main_default;
	if (style_file_management_img_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_18_main_main_default);
	else
		lv_style_init(&style_file_management_img_18_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_18_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_18_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_18_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_18, &style_file_management_img_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_20
	ui->file_management_label_20 = lv_label_create(ui->file_management_label_12);
	lv_obj_set_size(ui->file_management_label_20, 199, 42);
	lv_obj_align(ui->file_management_label_20,LV_ALIGN_TOP_MID,0,116);
	lv_label_set_text(ui->file_management_label_20, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_20, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_20, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_20_main_main_default
	static lv_style_t style_file_management_label_20_main_main_default;
	if (style_file_management_label_20_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_20_main_main_default);
	else
		lv_style_init(&style_file_management_label_20_main_main_default);
	lv_style_set_radius(&style_file_management_label_20_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_20_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_20_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_20_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_20_main_main_default, 255);
	lv_style_set_text_color(&style_file_management_label_20_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_20_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_20_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_20_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_20_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_20_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_20_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_20, &style_file_management_label_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_19
	ui->file_management_img_19 = lv_img_create(ui->file_management_label_12);
	lv_obj_set_size(ui->file_management_img_19, 18, 18);
	lv_obj_align_to(ui->file_management_img_19,ui->file_management_label_12,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_19_main_main_default
	static lv_style_t style_file_management_img_19_main_main_default;
	if (style_file_management_img_19_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_19_main_main_default);
	else
		lv_style_init(&style_file_management_img_19_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_19_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_19_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_19_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_19, &style_file_management_img_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_19, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_19,&_time_18x18);
	lv_img_set_pivot(ui->file_management_img_19, 0,0);
	lv_img_set_angle(ui->file_management_img_19, 0);

	//Write codes file_management_label_21
	ui->file_management_label_21 = lv_label_create(ui->file_management_label_12);
	lv_obj_set_size(ui->file_management_label_21, 57, 24);
	lv_obj_align_to(ui->file_management_label_21,ui->file_management_img_19,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_21, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_21, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_21, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_21_main_main_default
	static lv_style_t style_file_management_label_21_main_main_default;
	if (style_file_management_label_21_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_21_main_main_default);
	else
		lv_style_init(&style_file_management_label_21_main_main_default);
	lv_style_set_radius(&style_file_management_label_21_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_21_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_21_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_21_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_21_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_21_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_21_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_21_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_21_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_21_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_21_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_21_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_21, &style_file_management_label_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_20
	ui->file_management_img_20 = lv_img_create(ui->file_management_label_12);
	lv_obj_set_size(ui->file_management_img_20, 16, 16);
	lv_obj_align_to(ui->file_management_img_20,ui->file_management_img_19,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_20_main_main_default
	static lv_style_t style_file_management_img_20_main_main_default;
	if (style_file_management_img_20_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_20_main_main_default);
	else
		lv_style_init(&style_file_management_img_20_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_20_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_20_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_20_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_20, &style_file_management_img_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_20, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_20,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_img_20, 0,0);
	lv_img_set_angle(ui->file_management_img_20, 0);

	//Write codes file_management_label_22
	ui->file_management_label_22 = lv_label_create(ui->file_management_label_12);
	lv_obj_set_size(ui->file_management_label_22, 57, 24);
	lv_obj_align_to(ui->file_management_label_22,ui->file_management_img_20,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_22, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_22, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_22, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_22_main_main_default
	static lv_style_t style_file_management_label_22_main_main_default;
	if (style_file_management_label_22_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_22_main_main_default);
	else
		lv_style_init(&style_file_management_label_22_main_main_default);
	lv_style_set_radius(&style_file_management_label_22_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_22_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_22_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_22_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_22_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_22_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_22_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_22_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_22_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_22_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_22_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_22_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_22, &style_file_management_label_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_21
	ui->file_management_img_21 = lv_img_create(ui->file_management_label_13);
	lv_obj_set_size(ui->file_management_img_21, 96, 96);
	lv_obj_align(ui->file_management_img_21,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_21_main_main_default
	static lv_style_t style_file_management_img_21_main_main_default;
	if (style_file_management_img_21_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_21_main_main_default);
	else
		lv_style_init(&style_file_management_img_21_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_21_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_21_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_21_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_21, &style_file_management_img_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_23
	ui->file_management_label_23 = lv_label_create(ui->file_management_label_13);
	lv_obj_set_size(ui->file_management_label_23, 199, 42);
	lv_obj_align(ui->file_management_label_23,LV_ALIGN_TOP_MID,0,116);
	lv_label_set_text(ui->file_management_label_23, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_23, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_23, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_23_main_main_default
	static lv_style_t style_file_management_label_23_main_main_default;
	if (style_file_management_label_23_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_23_main_main_default);
	else
		lv_style_init(&style_file_management_label_23_main_main_default);
	lv_style_set_radius(&style_file_management_label_23_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_23_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_23_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_23_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_23_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_23_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_23_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_23_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_23_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_23_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_23_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_23_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_23, &style_file_management_label_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_22
	ui->file_management_img_22 = lv_img_create(ui->file_management_label_13);
	lv_obj_set_size(ui->file_management_img_22, 18, 18);
	lv_obj_align_to(ui->file_management_img_22,ui->file_management_label_13,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_22_main_main_default
	static lv_style_t style_file_management_img_22_main_main_default;
	if (style_file_management_img_22_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_22_main_main_default);
	else
		lv_style_init(&style_file_management_img_22_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_22_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_22_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_22_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_22, &style_file_management_img_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_22, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_22,&_time_18x18);
	lv_img_set_pivot(ui->file_management_img_22, 0,0);
	lv_img_set_angle(ui->file_management_img_22, 0);

	//Write codes file_management_label_24
	ui->file_management_label_24 = lv_label_create(ui->file_management_label_13);
	lv_obj_set_size(ui->file_management_label_24, 57, 24);
	lv_obj_align_to(ui->file_management_label_24,ui->file_management_img_22,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_24, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_24, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_24, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_24_main_main_default
	static lv_style_t style_file_management_label_24_main_main_default;
	if (style_file_management_label_24_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_24_main_main_default);
	else
		lv_style_init(&style_file_management_label_24_main_main_default);
	lv_style_set_radius(&style_file_management_label_24_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_24_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_24_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_24_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_24_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_24_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_24_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_24_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_24_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_24_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_24_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_24_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_24, &style_file_management_label_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_23
	ui->file_management_img_23 = lv_img_create(ui->file_management_label_13);
	lv_obj_set_size(ui->file_management_img_23, 16, 16);
	lv_obj_align_to(ui->file_management_img_23,ui->file_management_img_22,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_23_main_main_default
	static lv_style_t style_file_management_img_23_main_main_default;
	if (style_file_management_img_23_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_23_main_main_default);
	else
		lv_style_init(&style_file_management_img_23_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_23_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_23_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_23_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_23, &style_file_management_img_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_23, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_23,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_img_23, 0,0);
	lv_img_set_angle(ui->file_management_img_23, 0);

	//Write codes file_management_label_25
	ui->file_management_label_25 = lv_label_create(ui->file_management_label_13);
	lv_obj_set_size(ui->file_management_label_25, 57, 24);
	lv_obj_align_to(ui->file_management_label_25,ui->file_management_img_23,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_label_25, "test.gcode");
	lv_label_set_long_mode(ui->file_management_label_25, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_label_25, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_25_main_main_default
	static lv_style_t style_file_management_label_25_main_main_default;
	if (style_file_management_label_25_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_label_25_main_main_default);
	else
		lv_style_init(&style_file_management_label_25_main_main_default);
	lv_style_set_radius(&style_file_management_label_25_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_label_25_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_file_management_label_25_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_file_management_label_25_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_label_25_main_main_default, 0);
	lv_style_set_text_color(&style_file_management_label_25_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_management_label_25_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_file_management_label_25_main_main_default, 0);
	lv_style_set_pad_left(&style_file_management_label_25_main_main_default, 0);
	lv_style_set_pad_right(&style_file_management_label_25_main_main_default, 0);
	lv_style_set_pad_top(&style_file_management_label_25_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_management_label_25_main_main_default, 0);
	lv_obj_add_style(ui->file_management_label_25, &style_file_management_label_25_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_btn_2
	ui->file_management_btn_2 = lv_btn_create(ui->file_management_tabview_1_title1);
	lv_obj_set_size(ui->file_management_btn_2, 60, 60);
	lv_obj_align(ui->file_management_btn_2,LV_ALIGN_BOTTOM_RIGHT,0,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_btn_2_main_main_default
	static lv_style_t style_file_management_btn_2_main_main_default;
	if (style_file_management_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_btn_2_main_main_default);
	else
		lv_style_init(&style_file_management_btn_2_main_main_default);
	lv_style_set_radius(&style_file_management_btn_2_main_main_default, 30);
	lv_style_set_bg_color(&style_file_management_btn_2_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_color(&style_file_management_btn_2_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_dir(&style_file_management_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_btn_2_main_main_default, 227);
	lv_style_set_shadow_color(&style_file_management_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_management_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_file_management_btn_2_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_border_width(&style_file_management_btn_2_main_main_default, 1);
	lv_style_set_border_opa(&style_file_management_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->file_management_btn_2, &style_file_management_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_management_btn_2_label = lv_label_create(ui->file_management_btn_2);
	lv_label_set_text(ui->file_management_btn_2_label, "");
	lv_obj_set_style_text_color(ui->file_management_btn_2_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_management_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_management_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_management_img_25
	ui->file_management_img_25 = lv_img_create(ui->file_management_btn_2);
	lv_obj_set_size(ui->file_management_img_25, 24, 14);
	lv_obj_align(ui->file_management_img_25,LV_ALIGN_CENTER,0,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_25_main_main_default
	static lv_style_t style_file_management_img_25_main_main_default;
	if (style_file_management_img_25_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_25_main_main_default);
	else
		lv_style_init(&style_file_management_img_25_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_25_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_25_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_25_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_25, &style_file_management_img_25_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_25, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_25,&_Vector_3_24x14);
	lv_img_set_pivot(ui->file_management_img_25, 0,0);
	lv_img_set_angle(ui->file_management_img_25, 0);

    //Write codes file_management_btn_1
	ui->file_management_btn_1 = lv_btn_create(ui->file_management_tabview_1_title1);
	lv_obj_set_size(ui->file_management_btn_1, 60, 60);
	lv_obj_align_to(ui->file_management_btn_1,ui->file_management_btn_2,LV_ALIGN_OUT_TOP_MID,0,-14);

	//Write style state: LV_STATE_DEFAULT for style_file_management_btn_1_main_main_default
	static lv_style_t style_file_management_btn_1_main_main_default;
	if (style_file_management_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_btn_1_main_main_default);
	else
		lv_style_init(&style_file_management_btn_1_main_main_default);
	lv_style_set_radius(&style_file_management_btn_1_main_main_default, 30);
	lv_style_set_bg_color(&style_file_management_btn_1_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_color(&style_file_management_btn_1_main_main_default, lv_color_make(0x26, 0x28, 0x2a));
	lv_style_set_bg_grad_dir(&style_file_management_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_file_management_btn_1_main_main_default, 227);
	lv_style_set_shadow_color(&style_file_management_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_management_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_file_management_btn_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_border_width(&style_file_management_btn_1_main_main_default, 1);
	lv_style_set_border_opa(&style_file_management_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->file_management_btn_1, &style_file_management_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_management_btn_1_label = lv_label_create(ui->file_management_btn_1);
	lv_label_set_text(ui->file_management_btn_1_label, "");
	lv_obj_set_style_text_color(ui->file_management_btn_1_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_management_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_management_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_management_img_24
	ui->file_management_img_24 = lv_img_create(ui->file_management_btn_1);
	lv_obj_set_size(ui->file_management_img_24, 24, 14);
	lv_obj_align(ui->file_management_img_24,LV_ALIGN_CENTER,0,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_24_main_main_default
	static lv_style_t style_file_management_img_24_main_main_default;
	if (style_file_management_img_24_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_24_main_main_default);
	else
		lv_style_init(&style_file_management_img_24_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_24_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_24_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_24_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_24, &style_file_management_img_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_24, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_24,&_Vector_2_24x14);
	lv_img_set_pivot(ui->file_management_img_24, 0,0);
	lv_img_set_angle(ui->file_management_img_24, 0);

    //tab2
    //Write codes file_management_label_2
	ui->file_management_sd_label_2 = lv_label_create(ui->file_management_tabview_1_title2);
    lv_obj_align(ui->file_management_sd_label_2,LV_ALIGN_TOP_LEFT,0,0);
	lv_obj_set_size(ui->file_management_sd_label_2, 215, 203);
	lv_label_set_text(ui->file_management_sd_label_2, "");
	lv_label_set_long_mode(ui->file_management_sd_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_2_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_2, &style_file_management_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_6
	ui->file_management_sd_label_6 = lv_label_create(ui->file_management_tabview_1_title2);
    lv_obj_align(ui->file_management_sd_label_6,LV_ALIGN_TOP_RIGHT,0,0);
	lv_obj_set_size(ui->file_management_sd_label_6, 215, 203);
	lv_label_set_text(ui->file_management_sd_label_6, "");
	lv_label_set_long_mode(ui->file_management_sd_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_6, LV_TEXT_ALIGN_CENTER, 0);

	lv_obj_add_style(ui->file_management_sd_label_6, &style_file_management_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_10
	ui->file_management_sd_label_10 = lv_label_create(ui->file_management_tabview_1_title2);
	lv_obj_align_to(ui->file_management_sd_label_10,ui->file_management_sd_label_2,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
	lv_obj_set_size(ui->file_management_sd_label_10, 215, 203);
	lv_label_set_text(ui->file_management_sd_label_10, "");
	lv_label_set_long_mode(ui->file_management_sd_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_10, LV_TEXT_ALIGN_CENTER, 0);

	lv_obj_add_style(ui->file_management_sd_label_10, &style_file_management_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_11
	ui->file_management_sd_label_11 = lv_label_create(ui->file_management_tabview_1_title2);
    lv_obj_set_size(ui->file_management_sd_label_11, 215, 203);
	lv_obj_align_to(ui->file_management_sd_label_11,ui->file_management_sd_label_6,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
	lv_label_set_text(ui->file_management_sd_label_11, "");
	lv_label_set_long_mode(ui->file_management_sd_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_11, LV_TEXT_ALIGN_CENTER, 0);

	lv_obj_add_style(ui->file_management_sd_label_11, &style_file_management_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_12
	ui->file_management_sd_label_12 = lv_label_create(ui->file_management_tabview_1_title2);
	lv_obj_align_to(ui->file_management_sd_label_12,ui->file_management_sd_label_10,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
	lv_obj_set_size(ui->file_management_sd_label_12, 215, 203);
	lv_label_set_text(ui->file_management_sd_label_12, "");
	lv_label_set_long_mode(ui->file_management_sd_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_12, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_12_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_12, &style_file_management_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_13
	ui->file_management_sd_label_13 = lv_label_create(ui->file_management_tabview_1_title2);
	lv_obj_align_to(ui->file_management_sd_label_13,ui->file_management_sd_label_11,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
	lv_obj_set_size(ui->file_management_sd_label_13, 215, 203);
	lv_label_set_text(ui->file_management_sd_label_13, "");
	lv_label_set_long_mode(ui->file_management_sd_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_13, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_13_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_13, &style_file_management_label_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_6
	ui->file_management_sd_img_6 = lv_img_create(ui->file_management_sd_label_2);
	lv_obj_set_size(ui->file_management_sd_img_6, 96, 96);
	lv_obj_align(ui->file_management_sd_img_6,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_6_main_main_default
	lv_img_set_src(ui->file_management_sd_img_6,&_time_18x18);
	lv_obj_add_style(ui->file_management_sd_img_6, &style_file_management_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//Write codes file_management_label_3
	ui->file_management_sd_label_3 = lv_label_create(ui->file_management_sd_label_2);
    lv_obj_set_size(ui->file_management_sd_label_3, 199, 42);
	lv_obj_align_to(ui->file_management_sd_label_3,ui->file_management_sd_img_6,LV_ALIGN_OUT_BOTTOM_MID,0,10);
	lv_label_set_text(ui->file_management_sd_label_3, "test.gcod111e");
	lv_label_set_long_mode(ui->file_management_sd_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_3, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_3_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_3, &style_file_management_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_7
	ui->file_management_sd_img_7 = lv_img_create(ui->file_management_sd_label_2);
	lv_obj_set_size(ui->file_management_sd_img_7, 18, 18);
    lv_obj_align(ui->file_management_sd_img_7,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_7_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_7, &style_file_management_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_7,&_time_18x18);
	lv_img_set_pivot(ui->file_management_sd_img_7, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_7, 0);

    //Write codes file_management_label_4
	ui->file_management_sd_label_4 = lv_label_create(ui->file_management_sd_label_2);
	lv_obj_set_size(ui->file_management_sd_label_4, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_4,ui->file_management_sd_img_7,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_4, "test.gcode");
	lv_label_set_long_mode(ui->file_management_sd_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_4_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_4, &style_file_management_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_8
	ui->file_management_sd_img_8 = lv_img_create(ui->file_management_sd_label_2);
	lv_obj_set_size(ui->file_management_sd_img_8, 16, 16);
	lv_obj_align_to(ui->file_management_sd_img_8,ui->file_management_sd_img_7,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_8_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_8, &style_file_management_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_8,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_sd_img_8, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_8, 0);

    //Write codes file_management_label_5
	ui->file_management_sd_label_5 = lv_label_create(ui->file_management_sd_label_2);
	lv_obj_set_size(ui->file_management_sd_label_5, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_5,ui->file_management_sd_img_8,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_5, "test.gcode");
	lv_label_set_long_mode(ui->file_management_sd_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_5_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_5, &style_file_management_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_9
	ui->file_management_sd_img_9 = lv_img_create(ui->file_management_sd_label_6);
	lv_obj_set_size(ui->file_management_sd_img_9, 96, 96);
	lv_obj_align(ui->file_management_sd_img_9,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_9_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_9, &style_file_management_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_label_7
	ui->file_management_sd_label_7 = lv_label_create(ui->file_management_sd_label_6);
	lv_obj_align_to(ui->file_management_sd_label_7,ui->file_management_sd_label_6,LV_ALIGN_TOP_LEFT,10,116);
	lv_obj_set_size(ui->file_management_sd_label_7, 199, 42);
	lv_label_set_text(ui->file_management_sd_label_7, "test.gcode");
	lv_label_set_long_mode(ui->file_management_sd_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_7_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_7, &style_file_management_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

		//Write codes file_management_img_10
	ui->file_management_sd_img_10 = lv_img_create(ui->file_management_sd_label_6);
	lv_obj_set_size(ui->file_management_sd_img_10, 18, 18);
	lv_obj_align_to(ui->file_management_sd_img_10,ui->file_management_sd_label_6,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_10_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_10, &style_file_management_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_10,&_time_18x18);
	lv_img_set_pivot(ui->file_management_sd_img_10, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_10, 0);

	//Write codes file_management_label_8
	ui->file_management_sd_label_8 = lv_label_create(ui->file_management_sd_label_6);
	lv_obj_set_size(ui->file_management_sd_label_8, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_8,ui->file_management_sd_img_10,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_8, "");
	lv_label_set_long_mode(ui->file_management_sd_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_8_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_8, &style_file_management_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_11
	ui->file_management_sd_img_11 = lv_img_create(ui->file_management_sd_label_6);
	lv_obj_set_size(ui->file_management_sd_img_11, 16, 16);
	lv_obj_align_to(ui->file_management_sd_img_11,ui->file_management_sd_img_10,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_11_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_11, &style_file_management_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_11,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_sd_img_11, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_11, 0);

    //Write codes file_management_label_9
	ui->file_management_sd_label_9 = lv_label_create(ui->file_management_sd_label_6);
	lv_obj_set_size(ui->file_management_sd_label_9, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_9,ui->file_management_sd_img_11,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_9, "");
	lv_label_set_long_mode(ui->file_management_sd_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_9, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_9_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_9, &style_file_management_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_12
	ui->file_management_sd_img_12 = lv_img_create(ui->file_management_sd_label_10);
	lv_obj_set_size(ui->file_management_sd_img_12, 96, 96);
	lv_obj_align(ui->file_management_sd_img_12,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_12_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_12, &style_file_management_img_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_label_14
	ui->file_management_sd_label_14 = lv_label_create(ui->file_management_sd_label_10);
	lv_obj_set_size(ui->file_management_sd_label_14, 199, 42);
	lv_obj_align_to(ui->file_management_sd_label_14,ui->file_management_sd_label_10,LV_ALIGN_TOP_LEFT,10,116);
	lv_label_set_text(ui->file_management_sd_label_14, "");
	lv_label_set_long_mode(ui->file_management_sd_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_14, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_14_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_14, &style_file_management_label_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_13
	ui->file_management_sd_img_13 = lv_img_create(ui->file_management_sd_label_10);
	lv_obj_set_size(ui->file_management_sd_img_13, 18, 18);
	lv_obj_align_to(ui->file_management_sd_img_13,ui->file_management_sd_label_10,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_13_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_13, &style_file_management_img_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_13, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_13,&_time_18x18);
	lv_img_set_pivot(ui->file_management_sd_img_13, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_13, 0);

    //Write codes file_management_label_15
	ui->file_management_sd_label_15 = lv_label_create(ui->file_management_sd_label_10);
	lv_obj_set_size(ui->file_management_sd_label_15, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_15,ui->file_management_sd_img_13,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_15, "");
	lv_label_set_long_mode(ui->file_management_sd_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_15, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_15_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_15, &style_file_management_label_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_14
	ui->file_management_sd_img_14 = lv_img_create(ui->file_management_sd_label_10);
	lv_obj_set_size(ui->file_management_sd_img_14, 16, 16);
	lv_obj_align_to(ui->file_management_sd_img_14,ui->file_management_sd_img_13,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_14_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_14, &style_file_management_img_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_14, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_14,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_sd_img_14, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_14, 0);

    //Write codes file_management_label_16
	ui->file_management_sd_label_16 = lv_label_create(ui->file_management_sd_label_10);
	lv_obj_set_size(ui->file_management_sd_label_16, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_16,ui->file_management_sd_img_14,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_16, "");
	lv_label_set_long_mode(ui->file_management_sd_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_16, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_16_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_16, &style_file_management_label_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes file_management_img_15
	ui->file_management_sd_img_15 = lv_img_create(ui->file_management_sd_label_11);
	lv_obj_set_size(ui->file_management_sd_img_15, 96, 96);
	lv_obj_align(ui->file_management_sd_img_15,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_15_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_15, &style_file_management_img_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_img_set_src(ui->file_management_sd_img_15,&_time_18x18);

	//Write codes file_management_label_17
	ui->file_management_sd_label_17 = lv_label_create(ui->file_management_sd_label_11);
	lv_obj_set_size(ui->file_management_sd_label_17, 199, 42);
	lv_obj_align(ui->file_management_sd_label_17,LV_ALIGN_TOP_MID,0,116);
	lv_label_set_text(ui->file_management_sd_label_17, "");
	lv_label_set_long_mode(ui->file_management_sd_label_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_17, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_17_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_17, &style_file_management_label_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_16
	ui->file_management_sd_img_16 = lv_img_create(ui->file_management_sd_label_11);
	lv_obj_set_size(ui->file_management_sd_img_16, 18, 18);
	lv_obj_align_to(ui->file_management_sd_img_16,ui->file_management_sd_label_11,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_16_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_16, &style_file_management_img_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_16, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_16,&_time_18x18);
	lv_img_set_pivot(ui->file_management_sd_img_16, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_16, 0);

    //Write codes file_management_label_18
	ui->file_management_sd_label_18 = lv_label_create(ui->file_management_sd_label_11);
	lv_obj_set_size(ui->file_management_sd_label_18, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_18,ui->file_management_sd_img_16,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_18, "");
	lv_label_set_long_mode(ui->file_management_sd_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_18, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_18_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_18, &style_file_management_label_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_17
	ui->file_management_sd_img_17 = lv_img_create(ui->file_management_sd_label_11);
	lv_obj_set_size(ui->file_management_sd_img_17, 16, 16);
	lv_obj_align_to(ui->file_management_sd_img_17,ui->file_management_sd_img_16,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_17_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_17, &style_file_management_img_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_17, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_17,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_sd_img_17, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_17, 0);

	//Write codes file_management_label_19
	ui->file_management_sd_label_19 = lv_label_create(ui->file_management_sd_label_11);
	lv_obj_set_size(ui->file_management_sd_label_19, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_19,ui->file_management_sd_img_17,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_19, "");
	lv_label_set_long_mode(ui->file_management_sd_label_19, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_19, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_19_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_19, &style_file_management_label_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_18
	ui->file_management_sd_img_18 = lv_img_create(ui->file_management_sd_label_12);
	lv_obj_set_size(ui->file_management_sd_img_18, 96, 96);
	lv_obj_align(ui->file_management_sd_img_18,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_18_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_18, &style_file_management_img_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_20
	ui->file_management_sd_label_20 = lv_label_create(ui->file_management_sd_label_12);
	lv_obj_set_size(ui->file_management_sd_label_20, 199, 42);
	lv_obj_align(ui->file_management_sd_label_20,LV_ALIGN_TOP_MID,0,116);
	lv_label_set_text(ui->file_management_sd_label_20, "");
	lv_label_set_long_mode(ui->file_management_sd_label_20, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_20, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_20_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_20, &style_file_management_label_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_19
	ui->file_management_sd_img_19 = lv_img_create(ui->file_management_sd_label_12);
	lv_obj_set_size(ui->file_management_sd_img_19, 18, 18);
	lv_obj_align_to(ui->file_management_sd_img_19,ui->file_management_sd_label_12,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_19_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_19, &style_file_management_img_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_19, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_19,&_time_18x18);
	lv_img_set_pivot(ui->file_management_sd_img_19, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_19, 0);

	//Write codes file_management_label_21
	ui->file_management_sd_label_21 = lv_label_create(ui->file_management_sd_label_12);
	lv_obj_set_size(ui->file_management_sd_label_21, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_21,ui->file_management_sd_img_19,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_21, "");
	lv_label_set_long_mode(ui->file_management_sd_label_21, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_21, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_21_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_21, &style_file_management_label_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_20
	ui->file_management_sd_img_20 = lv_img_create(ui->file_management_sd_label_12);
	lv_obj_set_size(ui->file_management_sd_img_20, 16, 16);
	lv_obj_align_to(ui->file_management_sd_img_20,ui->file_management_sd_img_19,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_20_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_20, &style_file_management_img_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_20, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_20,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_sd_img_20, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_20, 0);

	//Write codes file_management_label_22
	ui->file_management_sd_label_22 = lv_label_create(ui->file_management_sd_label_12);
	lv_obj_set_size(ui->file_management_sd_label_22, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_22,ui->file_management_sd_img_20,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_22, "");
	lv_label_set_long_mode(ui->file_management_sd_label_22, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_22, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_22_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_22, &style_file_management_label_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_21
	ui->file_management_sd_img_21 = lv_img_create(ui->file_management_sd_label_13);
	lv_obj_set_size(ui->file_management_sd_img_21, 96, 96);
	lv_obj_align(ui->file_management_sd_img_21,LV_ALIGN_TOP_MID,0,10);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_21_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_21, &style_file_management_img_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_label_23
	ui->file_management_sd_label_23 = lv_label_create(ui->file_management_sd_label_13);
	lv_obj_set_size(ui->file_management_sd_label_23, 199, 42);
	lv_obj_align(ui->file_management_sd_label_23,LV_ALIGN_TOP_MID,0,116);
	lv_label_set_text(ui->file_management_sd_label_23, "");
	lv_label_set_long_mode(ui->file_management_sd_label_23, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_23, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_23_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_23, &style_file_management_label_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_22
	ui->file_management_sd_img_22 = lv_img_create(ui->file_management_sd_label_13);
	lv_obj_set_size(ui->file_management_sd_img_22, 18, 18);
	lv_obj_align_to(ui->file_management_sd_img_22,ui->file_management_sd_label_13,LV_ALIGN_BOTTOM_LEFT,10,-18);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_22_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_22, &style_file_management_img_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_22, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_22,&_time_18x18);
	lv_img_set_pivot(ui->file_management_sd_img_22, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_22, 0);

	//Write codes file_management_label_24
	ui->file_management_sd_label_24 = lv_label_create(ui->file_management_sd_label_13);
	lv_obj_set_size(ui->file_management_sd_label_24, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_24,ui->file_management_sd_img_22,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_24, "");
	lv_label_set_long_mode(ui->file_management_sd_label_24, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_24, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_24_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_24, &style_file_management_label_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_img_23
	ui->file_management_sd_img_23 = lv_img_create(ui->file_management_sd_label_13);
	lv_obj_set_size(ui->file_management_sd_img_23, 16, 16);
	lv_obj_align_to(ui->file_management_sd_img_23,ui->file_management_sd_img_22,LV_ALIGN_OUT_RIGHT_TOP,67,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_23_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_23, &style_file_management_img_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_23, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_23,&_file_logo2_16x16);
	lv_img_set_pivot(ui->file_management_sd_img_23, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_23, 0);

	//Write codes file_management_label_25
	ui->file_management_sd_label_25 = lv_label_create(ui->file_management_sd_label_13);
	lv_obj_set_size(ui->file_management_sd_label_25, 57, 24);
	lv_obj_align_to(ui->file_management_sd_label_25,ui->file_management_sd_img_23,LV_ALIGN_OUT_RIGHT_TOP,0,-8);
	lv_label_set_text(ui->file_management_sd_label_25, "");
	lv_label_set_long_mode(ui->file_management_sd_label_25, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->file_management_sd_label_25, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_label_25_main_main_default
	lv_obj_add_style(ui->file_management_sd_label_25, &style_file_management_label_25_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes file_management_btn_2
	ui->file_management_sd_btn_2 = lv_btn_create(ui->file_management_tabview_1_title2);
	lv_obj_set_size(ui->file_management_sd_btn_2, 60, 60);
	lv_obj_align(ui->file_management_sd_btn_2,LV_ALIGN_BOTTOM_RIGHT,0,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_btn_2_main_main_default
	lv_obj_add_style(ui->file_management_sd_btn_2, &style_file_management_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_management_sd_btn_2_label = lv_label_create(ui->file_management_sd_btn_2);
	lv_label_set_text(ui->file_management_sd_btn_2_label, "");
	lv_obj_set_style_text_color(ui->file_management_sd_btn_2_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_management_sd_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_management_sd_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_management_img_25
	ui->file_management_sd_img_25 = lv_img_create(ui->file_management_sd_btn_2);
	lv_obj_set_size(ui->file_management_sd_img_25, 24, 14);
	lv_obj_align(ui->file_management_sd_img_25,LV_ALIGN_CENTER,0,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_25_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_25, &style_file_management_img_25_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_25, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_25,&_Vector_3_24x14);
	lv_img_set_pivot(ui->file_management_sd_img_25, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_25, 0);

    //Write codes file_management_btn_1
	ui->file_management_sd_btn_1 = lv_btn_create(ui->file_management_tabview_1_title2);
	lv_obj_set_size(ui->file_management_sd_btn_1, 60, 60);
	lv_obj_align_to(ui->file_management_sd_btn_1,ui->file_management_sd_btn_2,LV_ALIGN_OUT_TOP_MID,0,-14);

	//Write style state: LV_STATE_DEFAULT for style_file_management_btn_1_main_main_default
	lv_obj_add_style(ui->file_management_sd_btn_1, &style_file_management_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->file_management_sd_btn_1_label = lv_label_create(ui->file_management_sd_btn_1);
	lv_label_set_text(ui->file_management_sd_btn_1_label, "");
	lv_obj_set_style_text_color(ui->file_management_sd_btn_1_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->file_management_sd_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->file_management_sd_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes file_management_img_24
	ui->file_management_sd_img_24 = lv_img_create(ui->file_management_sd_btn_1);
	lv_obj_set_size(ui->file_management_sd_img_24, 24, 14);
	lv_obj_align(ui->file_management_sd_img_24,LV_ALIGN_CENTER,0,0);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_24_main_main_default
	lv_obj_add_style(ui->file_management_sd_img_24, &style_file_management_img_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_sd_img_24, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_sd_img_24,&_Vector_2_24x14);
	lv_img_set_pivot(ui->file_management_sd_img_24, 0,0);
	lv_img_set_angle(ui->file_management_sd_img_24, 0);

	//Write codes file_managemen_history_label_2
	ui->file_management_history_label_2 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_2, 15+X_POSITION, 59+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_label_2, 450, 630);
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
	ui->file_management_history_label_3 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_3, 130+X_POSITION, 85+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_label_3, 207, 24);
	lv_label_set_text(ui->file_management_history_label_3, "");
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
	ui->file_management_history_label_11 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_11, 130+X_POSITION, 201+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_label_11, 207, 24);
	lv_label_set_text(ui->file_management_history_label_11, "");
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
	ui->file_management_history_label_12 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_12, 130+X_POSITION, 317+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_label_12, 207, 24);
	lv_label_set_text(ui->file_management_history_label_12, "");
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
	ui->file_management_history_label_13 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_13, 130+X_POSITION, 433+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_label_13, 207, 24);
	lv_label_set_text(ui->file_management_history_label_13, "");
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
	ui->file_management_history_label_14 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_14, 130+X_POSITION, 549+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_label_14, 207, 24);
	lv_label_set_text(ui->file_management_history_label_14, "");
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
	ui->file_management_history_label_4 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_4, 130+X_POSITION, 117+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_label_4, 183, 24);
	lv_label_set_text(ui->file_management_history_label_4, "");
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
	ui->file_management_history_label_15 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_15, 130+X_POSITION, 233+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_label_15, 183, 24);
	lv_label_set_text(ui->file_management_history_label_15, "");
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
	ui->file_management_history_label_16 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_16, 130+X_POSITION, 349+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_label_16, 183, 24);
	lv_label_set_text(ui->file_management_history_label_16, " ");
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
	ui->file_management_history_label_17 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_17, 130+X_POSITION, 465+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_label_17, 183, 24);
	lv_label_set_text(ui->file_management_history_label_17, " ");
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
	ui->file_management_history_label_18 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_18, 130+X_POSITION, 581+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_label_18, 183, 24);
	lv_label_set_text(ui->file_management_history_label_18, "");
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
	ui->file_management_history_label_5 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_5, 130+X_POSITION, 149+Y_POSITION);
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
	ui->file_management_history_label_19 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_19, 130+X_POSITION, 265+Y_POSITION);
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
	ui->file_management_history_label_20 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_20, 130+X_POSITION, 381+Y_POSITION);
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
	ui->file_management_history_label_21 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_21, 130+X_POSITION, 497+Y_POSITION);
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
	ui->file_management_history_label_22 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_22, 130+X_POSITION, 613+Y_POSITION);
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
	ui->file_management_history_label_6 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_6, 20+X_POSITION, 191+Y_POSITION);
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
	ui->file_management_history_label_7 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_7, 20+X_POSITION, 307+Y_POSITION);
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
	ui->file_management_history_label_8 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_8, 20+X_POSITION, 423+Y_POSITION);
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
	ui->file_management_history_label_9 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_9, 20+X_POSITION, 539+Y_POSITION);
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
	ui->file_management_history_label_10 = lv_label_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_label_10, 20+X_POSITION, 655+Y_POSITION);
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
	ui->file_management_history_btn_1 = lv_btn_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_btn_1, 400+X_POSITION, 572+Y_POSITION);
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
	ui->file_management_history_btn_2 = lv_btn_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_btn_2, 400+X_POSITION, 646+Y_POSITION);
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
	ui->file_management_history_btn_3 = lv_btn_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_btn_3, 366+X_POSITION, 117+Y_POSITION);
	lv_obj_set_size(ui->file_management_history_btn_3, 97, 32);

	//Write style state: LV_STATE_DEFAULT for style_file_management_history_btn_3_main_main_default
	static lv_style_t style_file_management_history_btn_3_main_main_default;
	if (style_file_management_history_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_history_btn_3_main_main_default);
	else
		lv_style_init(&style_file_management_history_btn_3_main_main_default);
	lv_style_set_radius(&style_file_management_history_btn_3_main_main_default, 0);
	lv_style_set_bg_color(&style_file_management_history_btn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_file_management_history_btn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
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
	ui->file_management_history_btn_4 = lv_btn_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_btn_4, 366+X_POSITION, 233+Y_POSITION);
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
	ui->file_management_history_btn_5 = lv_btn_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_btn_5, 366+X_POSITION, 349+Y_POSITION);
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
	ui->file_management_history_btn_6 = lv_btn_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_btn_6, 366+X_POSITION, 462+Y_POSITION);
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
	ui->file_management_history_btn_7 = lv_btn_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_btn_7, 366+X_POSITION, 581+Y_POSITION);
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
	ui->file_management_history_img_6 = lv_img_create(ui->file_management_history_btn_1);
	lv_obj_set_size(ui->file_management_history_img_6, 24, 14);
    lv_obj_align(ui->file_management_history_img_6,LV_ALIGN_CENTER,0,0);

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
	ui->file_management_history_img_8 = lv_img_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_img_8, 20+X_POSITION, 85+Y_POSITION);
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
	ui->file_management_history_img_9 = lv_img_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_img_9, 20+X_POSITION, 201+Y_POSITION);
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
	ui->file_management_history_img_10 = lv_img_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_img_10, 19+X_POSITION, 317+Y_POSITION);
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
	ui->file_management_history_img_11 = lv_img_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_img_11, 20+X_POSITION, 433+Y_POSITION);
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
	ui->file_management_history_img_12 = lv_img_create(ui->file_management_tabview_1_title3);
	lv_obj_set_pos(ui->file_management_history_img_12, 23+X_POSITION, 549+Y_POSITION);
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
	ui->file_management_history_img_7 = lv_img_create(ui->file_management_history_btn_2);
	lv_obj_set_size(ui->file_management_history_img_7, 24, 14);
    lv_obj_align(ui->file_management_history_img_7,LV_ALIGN_CENTER,0,0);

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

	//Write codes file_management_img_1
	ui->file_management_img_1 = lv_img_create(ui->file_management_cont_1);
	lv_obj_set_pos(ui->file_management_img_1, 30, 742);
	lv_obj_set_size(ui->file_management_img_1, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_1_main_main_default
	static lv_style_t style_file_management_img_1_main_main_default;
	if (style_file_management_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_1_main_main_default);
	else
		lv_style_init(&style_file_management_img_1_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_1_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_1, &style_file_management_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_1,&_home_48x48);
	lv_img_set_pivot(ui->file_management_img_1, 0,0);
	lv_img_set_angle(ui->file_management_img_1, 0);

	//Write codes file_management_img_2
	ui->file_management_img_2 = lv_img_create(ui->file_management_cont_1);
	lv_obj_set_pos(ui->file_management_img_2, 128, 742);
	lv_obj_set_size(ui->file_management_img_2, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_2_main_main_default
	static lv_style_t style_file_management_img_2_main_main_default;
	if (style_file_management_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_2_main_main_default);
	else
		lv_style_init(&style_file_management_img_2_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_2_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_2, &style_file_management_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_2,&_prepare_48x48);
	lv_img_set_pivot(ui->file_management_img_2, 0,0);
	lv_img_set_angle(ui->file_management_img_2, 0);

	//Write codes file_management_img_3
	ui->file_management_img_3 = lv_img_create(ui->file_management_cont_1);
	lv_obj_set_pos(ui->file_management_img_3, 224, 742);
	lv_obj_set_size(ui->file_management_img_3, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_3_main_main_default
	static lv_style_t style_file_management_img_3_main_main_default;
	if (style_file_management_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_3_main_main_default);
	else
		lv_style_init(&style_file_management_img_3_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_3_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_3, &style_file_management_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_3,&_files_blue_48x48);
	lv_img_set_pivot(ui->file_management_img_3, 0,0);
	lv_img_set_angle(ui->file_management_img_3, 0);

	//Write codes file_management_img_4
	ui->file_management_img_4 = lv_img_create(ui->file_management_cont_1);
	lv_obj_set_pos(ui->file_management_img_4, 318, 742);
	lv_obj_set_size(ui->file_management_img_4, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_4_main_main_default
	static lv_style_t style_file_management_img_4_main_main_default;
	if (style_file_management_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_4_main_main_default);
	else
		lv_style_init(&style_file_management_img_4_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_4_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_4, &style_file_management_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_4,&_seting_48x48);
	lv_img_set_pivot(ui->file_management_img_4, 0,0);
	lv_img_set_angle(ui->file_management_img_4, 0);

	//Write codes file_management_img_5
	ui->file_management_img_5 = lv_img_create(ui->file_management_cont_1);
	lv_obj_set_pos(ui->file_management_img_5, 414, 742);
	lv_obj_set_size(ui->file_management_img_5, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_file_management_img_5_main_main_default
	static lv_style_t style_file_management_img_5_main_main_default;
	if (style_file_management_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_management_img_5_main_main_default);
	else
		lv_style_init(&style_file_management_img_5_main_main_default);
	lv_style_set_img_recolor(&style_file_management_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_file_management_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_file_management_img_5_main_main_default, 255);
	lv_obj_add_style(ui->file_management_img_5, &style_file_management_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->file_management_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->file_management_img_5,&_FAQ_48x48);
	lv_img_set_pivot(ui->file_management_img_5, 0,0);
	lv_img_set_angle(ui->file_management_img_5, 0);

	lv_obj_add_flag(ui->file_management_sd_label_2, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_flag(ui->file_management_sd_label_6, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_flag(ui->file_management_sd_label_10, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_flag(ui->file_management_sd_label_11, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_flag(ui->file_management_sd_label_12, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_flag(ui->file_management_sd_label_13, LV_OBJ_FLAG_CLICKABLE);

	//Init events for screen
	events_init_file_management(ui);
}
