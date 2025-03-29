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
#include "../custom/mystyle.h"

#define REVISE_Y 50-16
#define REVISE_X -16
void setup_scr_selftest(lv_ui *ui){

	//Write selftest_cont_1
	ui->selftest_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->selftest_cont_1, 0, 0);
	lv_obj_set_size(ui->selftest_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_selftest_cont_1_main_main_default
	static lv_style_t style_selftest_cont_1_main_main_default;
	if (style_selftest_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_cont_1_main_main_default);
	else
		lv_style_init(&style_selftest_cont_1_main_main_default);
	lv_style_set_radius(&style_selftest_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_selftest_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_selftest_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_selftest_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_selftest_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->selftest_cont_1, &style_selftest_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_tabview_1
	ui->selftest_tabview_1 = lv_tabview_create(ui->selftest_cont_1, LV_DIR_TOP, 0);
	lv_obj_set_pos(ui->selftest_tabview_1, 0, 0);
	lv_obj_set_size(ui->selftest_tabview_1, 480, 800);

	//title1
	ui->selftest_tabview_1_title1 = lv_tabview_add_tab(ui->selftest_tabview_1,"title1");

	//title2
	ui->selftest_tabview_1_title2 = lv_tabview_add_tab(ui->selftest_tabview_1,"title2");

	//title3
	ui->selftest_tabview_1_title3 = lv_tabview_add_tab(ui->selftest_tabview_1,"title3");

	//Title4
	ui->selftest_tabview_1_Title4 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title4");

	//Title5
	ui->selftest_tabview_1_Title5 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title5");

	//Title6
	ui->selftest_tabview_1_Title6 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title6");

	//Title7
	ui->selftest_tabview_1_Title7 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title7");

	//Title8
	ui->selftest_tabview_1_Title8 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title8");

	//Title9
	ui->selftest_tabview_1_Title9 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title9");

	//Title10
	ui->selftest_tabview_1_Title10 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title10");

	//Title11
	ui->selftest_tabview_1_Title11 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title11");

	//Title12
	ui->selftest_tabview_1_Title12 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title12");

	//Title13
	ui->selftest_tabview_1_Title13 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title13");

	//Title14
	ui->selftest_tabview_1_Title14 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title14");

	//Title15
	ui->selftest_tabview_1_Title15 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title15");

	//Title16
	ui->selftest_tabview_1_Title16 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title16");

	//Title17
	ui->selftest_tabview_1_Title17 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title17");

	//Title18
	ui->selftest_tabview_1_Title18 = lv_tabview_add_tab(ui->selftest_tabview_1,"Title18");


	//Write style state: LV_STATE_DEFAULT for style_selftest_tabview_1_main_main_default
	static lv_style_t style_selftest_tabview_1_main_main_default;
	if (style_selftest_tabview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_tabview_1_main_main_default);
	else
		lv_style_init(&style_selftest_tabview_1_main_main_default);
	lv_style_set_bg_color(&style_selftest_tabview_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_selftest_tabview_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_selftest_tabview_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_tabview_1_main_main_default, 255);
	lv_style_set_border_color(&style_selftest_tabview_1_main_main_default, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_selftest_tabview_1_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_tabview_1_main_main_default, 100);
	lv_style_set_text_color(&style_selftest_tabview_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_selftest_tabview_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_tabview_1_main_main_default, 0);
	lv_style_set_text_line_space(&style_selftest_tabview_1_main_main_default, 16);
	lv_obj_add_style(ui->selftest_tabview_1, &style_selftest_tabview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_selftest_tabview_1_extra_btnm_main_default
	static lv_style_t style_selftest_tabview_1_extra_btnm_main_default;
	if (style_selftest_tabview_1_extra_btnm_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_tabview_1_extra_btnm_main_default);
	else
		lv_style_init(&style_selftest_tabview_1_extra_btnm_main_default);
	lv_style_set_bg_color(&style_selftest_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_selftest_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_selftest_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_border_color(&style_selftest_tabview_1_extra_btnm_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_border_opa(&style_selftest_tabview_1_extra_btnm_main_default, 100);
	lv_style_set_pad_left(&style_selftest_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_right(&style_selftest_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_top(&style_selftest_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_tabview_1_extra_btnm_main_default, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->selftest_tabview_1), &style_selftest_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_selftest_tabview_1_extra_btnm_items_default
	static lv_style_t style_selftest_tabview_1_extra_btnm_items_default;
	if (style_selftest_tabview_1_extra_btnm_items_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_tabview_1_extra_btnm_items_default);
	else
		lv_style_init(&style_selftest_tabview_1_extra_btnm_items_default);
	lv_style_set_text_color(&style_selftest_tabview_1_extra_btnm_items_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_selftest_tabview_1_extra_btnm_items_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->selftest_tabview_1), &style_selftest_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_selftest_tabview_1_extra_btnm_items_checked
	static lv_style_t style_selftest_tabview_1_extra_btnm_items_checked;
	if (style_selftest_tabview_1_extra_btnm_items_checked.prop_cnt > 1)
		lv_style_reset(&style_selftest_tabview_1_extra_btnm_items_checked);
	else
		lv_style_init(&style_selftest_tabview_1_extra_btnm_items_checked);
	lv_style_set_bg_color(&style_selftest_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_tabview_1_extra_btnm_items_checked, 60);
	lv_style_set_border_color(&style_selftest_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_tabview_1_extra_btnm_items_checked, 0);
	lv_style_set_border_opa(&style_selftest_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_side(&style_selftest_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_text_color(&style_selftest_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_text_font(&style_selftest_tabview_1_extra_btnm_items_checked, &lv_font_simsun_24);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->selftest_tabview_1), &style_selftest_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes selftest_img_1
	ui->selftest_img_1 = lv_img_create(ui->selftest_tabview_1_title1);
	lv_obj_set_pos(ui->selftest_img_1, 109 + REVISE_X, 190 + REVISE_Y);
	lv_obj_set_size(ui->selftest_img_1, 289, 37);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_1_main_main_default
	static lv_style_t style_selftest_img_1_main_main_default;
	if (style_selftest_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_1_main_main_default);
	else
		lv_style_init(&style_selftest_img_1_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_1_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_1, &style_selftest_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_1,&_creality_logo_2_289x37);
	lv_img_set_pivot(ui->selftest_img_1, 0,0);
	lv_img_set_angle(ui->selftest_img_1, 0);

	//Write codes selftest_bar_1
	ui->selftest_bar_1 = lv_bar_create(ui->selftest_tabview_1_title1);
	lv_obj_set_pos(ui->selftest_bar_1, 81 + REVISE_X, 292 + REVISE_Y);
	lv_obj_set_size(ui->selftest_bar_1, 343, 20);

	//Write style state: LV_STATE_DEFAULT for style_selftest_bar_1_main_main_default
	static lv_style_t style_selftest_bar_1_main_main_default;
	if (style_selftest_bar_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_bar_1_main_main_default);
	else
		lv_style_init(&style_selftest_bar_1_main_main_default);
	lv_style_set_radius(&style_selftest_bar_1_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_bar_1_main_main_default, lv_color_make(0x30, 0x34, 0x3e));
	lv_style_set_bg_grad_color(&style_selftest_bar_1_main_main_default, lv_color_make(0x30, 0x34, 0x3e));
	lv_style_set_bg_grad_dir(&style_selftest_bar_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_bar_1_main_main_default, 255);
	lv_style_set_pad_left(&style_selftest_bar_1_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_bar_1_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_bar_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_bar_1_main_main_default, 0);
	lv_obj_add_style(ui->selftest_bar_1, &style_selftest_bar_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_selftest_bar_1_main_indicator_default
	static lv_style_t style_selftest_bar_1_main_indicator_default;
	if (style_selftest_bar_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_bar_1_main_indicator_default);
	else
		lv_style_init(&style_selftest_bar_1_main_indicator_default);
	lv_style_set_radius(&style_selftest_bar_1_main_indicator_default, 0);
	lv_style_set_bg_color(&style_selftest_bar_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_bar_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_bar_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_bar_1_main_indicator_default, 255);
	lv_obj_add_style(ui->selftest_bar_1, &style_selftest_bar_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->selftest_bar_1, 1000, 0);
	lv_bar_set_mode(ui->selftest_bar_1, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->selftest_bar_1, 50, LV_ANIM_OFF);

	//Write codes selftest_label_1
	ui->selftest_label_1 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_1, 112 + REVISE_X, -24 + REVISE_Y);
	lv_obj_set_size(ui->selftest_label_1, 280, 32);
	lv_label_set_text(ui->selftest_label_1, "语言选择");
	lv_label_set_long_mode(ui->selftest_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_1_main_main_default
	static lv_style_t style_selftest_label_1_main_main_default;
	if (style_selftest_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_1_main_main_default);
	else
		lv_style_init(&style_selftest_label_1_main_main_default);
	lv_style_set_radius(&style_selftest_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_1_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_1_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_1, &style_selftest_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_1
	ui->selftest_btn_1 = lv_btn_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_btn_1, 179 + REVISE_X, 659 + REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_1, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_1_main_main_default
	static lv_style_t style_selftest_btn_1_main_main_default;
	if (style_selftest_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_1_main_main_default);
	else
		lv_style_init(&style_selftest_btn_1_main_main_default);
	lv_style_set_radius(&style_selftest_btn_1_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_1_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_1_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_1_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_1, &style_selftest_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_1_label = lv_label_create(ui->selftest_btn_1);
	lv_label_set_text(ui->selftest_btn_1_label, "下一步");
	lv_obj_set_style_text_color(ui->selftest_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_1_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_2
	ui->selftest_label_2 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_2, 26+ REVISE_X, 27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_2, 450, 603);
	lv_label_set_text(ui->selftest_label_2, "");
	lv_label_set_long_mode(ui->selftest_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_2_main_main_default
	static lv_style_t style_selftest_label_2_main_main_default;
	if (style_selftest_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_2_main_main_default);
	else
		lv_style_init(&style_selftest_label_2_main_main_default);
	lv_style_set_radius(&style_selftest_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_2_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_2_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_2_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_2, &style_selftest_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_3
	ui->selftest_label_3 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_3, 26+ REVISE_X, 27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_3, 450, 64);
	lv_label_set_text(ui->selftest_label_3, "");
	lv_label_set_long_mode(ui->selftest_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_3, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_style(ui->selftest_label_3, &labelstyle_check_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_3,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_label_4
	ui->selftest_label_4 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_4, 27+ REVISE_X, 91+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_4, 450, 64);
	lv_label_set_text(ui->selftest_label_4, "");
	lv_label_set_long_mode(ui->selftest_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_4, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_style(ui->selftest_label_4, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_4,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_img_2
	ui->selftest_img_2 = lv_img_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_img_2, 435+ REVISE_X, 52+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_2, 23, 13);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_2_main_main_default
	static lv_style_t style_selftest_img_2_main_main_default;
	if (style_selftest_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_2_main_main_default);
	else
		lv_style_init(&style_selftest_img_2_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_2_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_2, &style_selftest_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_2,&_choice_23x13);
	lv_img_set_pivot(ui->selftest_img_2, 0,0);
	lv_img_set_angle(ui->selftest_img_2, 0);

	//Write codes selftest_img_3
	ui->selftest_img_3 = lv_img_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_img_3, 433+ REVISE_X, 117+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_3, 23, 13);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_3_main_main_default
	static lv_style_t style_selftest_img_3_main_main_default;
	if (style_selftest_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_3_main_main_default);
	else
		lv_style_init(&style_selftest_img_3_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_3_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_3, &style_selftest_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_3,&_choice_23x13);
	lv_img_set_pivot(ui->selftest_img_3, 0,0);
	lv_img_set_angle(ui->selftest_img_3, 0);

	//Write codes selftest_label_5
	ui->selftest_label_5 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_5, 27+ REVISE_X, 155+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_5, 450, 64);
	lv_label_set_text(ui->selftest_label_5, "");
	lv_label_set_long_mode(ui->selftest_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_5, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_style(ui->selftest_label_5, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_5,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_img_4
	ui->selftest_img_4 = lv_img_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_img_4, 438+ REVISE_X, 183+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_4, 23, 13);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_4_main_main_default
	static lv_style_t style_selftest_img_4_main_main_default;
	if (style_selftest_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_4_main_main_default);
	else
		lv_style_init(&style_selftest_img_4_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_4_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_4, &style_selftest_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_4,&_choice_23x13);
	lv_img_set_pivot(ui->selftest_img_4, 0,0);
	lv_img_set_angle(ui->selftest_img_4, 0);

	//Write codes selftest_label_6
	ui->selftest_label_6 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_6, 27+ REVISE_X, 219+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_6, 450, 64);
	lv_label_set_text(ui->selftest_label_6, "");
	lv_label_set_long_mode(ui->selftest_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_6, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_style(ui->selftest_label_6, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_6,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_img_5
	ui->selftest_img_5 = lv_img_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_img_5, 439+ REVISE_X, 238+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_5, 23, 13);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_5_main_main_default
	static lv_style_t style_selftest_img_5_main_main_default;
	if (style_selftest_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_5_main_main_default);
	else
		lv_style_init(&style_selftest_img_5_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_5_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_5, &style_selftest_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_5,&_choice_23x13);
	lv_img_set_pivot(ui->selftest_img_5, 0,0);
	lv_img_set_angle(ui->selftest_img_5, 0);

	//Write codes selftest_label_7
	ui->selftest_label_7 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_7, 27+ REVISE_X, 283+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_7, 450, 64);
	lv_label_set_text(ui->selftest_label_7, "");
	lv_label_set_long_mode(ui->selftest_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_7, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_style(ui->selftest_label_7, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_7,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_img_6
	ui->selftest_img_6 = lv_img_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_img_6, 438+ REVISE_X, 308+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_6, 23, 13);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_6_main_main_default
	static lv_style_t style_selftest_img_6_main_main_default;
	if (style_selftest_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_6_main_main_default);
	else
		lv_style_init(&style_selftest_img_6_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_6_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_6, &style_selftest_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_6,&_choice_23x13);
	lv_img_set_pivot(ui->selftest_img_6, 0,0);
	lv_img_set_angle(ui->selftest_img_6, 0);

	//Write codes selftest_label_8
	ui->selftest_label_8 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_8, 27+ REVISE_X, 347+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_8, 450, 64);
	lv_label_set_text(ui->selftest_label_8, "");
	lv_label_set_long_mode(ui->selftest_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_8, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_style(ui->selftest_label_8, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_8,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_img_7
	ui->selftest_img_7 = lv_img_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_img_7, 433+ REVISE_X, 364+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_7, 23, 13);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_7_main_main_default
	static lv_style_t style_selftest_img_7_main_main_default;
	if (style_selftest_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_7_main_main_default);
	else
		lv_style_init(&style_selftest_img_7_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_7_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_7, &style_selftest_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_7,&_choice_23x13);
	lv_img_set_pivot(ui->selftest_img_7, 0,0);
	lv_img_set_angle(ui->selftest_img_7, 0);

	//Write codes selftest_label_9
	ui->selftest_label_9 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_9, 27+ REVISE_X, 411+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_9, 450, 64);
	lv_label_set_text(ui->selftest_label_9, "");
	lv_label_set_long_mode(ui->selftest_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_9, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_style(ui->selftest_label_9, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_9,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_img_8
	ui->selftest_img_8 = lv_img_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_img_8, 433+ REVISE_X, 438+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_8, 23, 13);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_8_main_main_default
	static lv_style_t style_selftest_img_8_main_main_default;
	if (style_selftest_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_8_main_main_default);
	else
		lv_style_init(&style_selftest_img_8_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_8_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_8, &style_selftest_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_8,&_choice_23x13);
	lv_img_set_pivot(ui->selftest_img_8, 0,0);
	lv_img_set_angle(ui->selftest_img_8, 0);

	//Write codes selftest_label_10
	ui->selftest_label_10 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_10, 27+ REVISE_X, 475+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_10, 450, 64);
	lv_label_set_text(ui->selftest_label_10, "");
	lv_label_set_long_mode(ui->selftest_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_10, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_style(ui->selftest_label_10, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_10,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_img_9
	ui->selftest_img_9 = lv_img_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_img_9, 431+ REVISE_X, 501+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_9, 23, 13);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_9_main_main_default
	static lv_style_t style_selftest_img_9_main_main_default;
	if (style_selftest_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_9_main_main_default);
	else
		lv_style_init(&style_selftest_img_9_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_9_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_9, &style_selftest_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_9,&_choice_23x13);
	lv_img_set_pivot(ui->selftest_img_9, 0,0);
	lv_img_set_angle(ui->selftest_img_9, 0);

	//Write codes selftest_label_11
	ui->selftest_label_11 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_11, 27+ REVISE_X, 539+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_11, 450, 64);
	lv_label_set_text(ui->selftest_label_11, "");
	lv_label_set_long_mode(ui->selftest_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_11, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_add_style(ui->selftest_label_11, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_11,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_img_10
	ui->selftest_img_10 = lv_img_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_img_10, 430+ REVISE_X, 572+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_10, 23, 13);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_10_main_main_default
	static lv_style_t style_selftest_img_10_main_main_default;
	if (style_selftest_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_10_main_main_default);
	else
		lv_style_init(&style_selftest_img_10_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_10_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_10, &style_selftest_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_10,&_choice_23x13);
	lv_img_set_pivot(ui->selftest_img_10, 0,0);
	lv_img_set_angle(ui->selftest_img_10, 0);

	//Write codes selftest_label_12
	ui->selftest_label_12 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_12, 42+ REVISE_X, 47+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_12, 187, 28);
	lv_label_set_text(ui->selftest_label_12, "中文");
	lv_label_set_long_mode(ui->selftest_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_12, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_add_style(ui->selftest_label_12, &labelstyle_opa_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_12,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_label_13
	ui->selftest_label_13 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_13, 42+ REVISE_X, 110+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_13, 187, 28);
	lv_label_set_text(ui->selftest_label_13, "English");
	lv_label_set_long_mode(ui->selftest_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_13, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_add_style(ui->selftest_label_13, &labelstyle_opa_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_13,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_label_14
	ui->selftest_label_14 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_14, 42+ REVISE_X, 169+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_14, 187, 28);
	lv_label_set_text(ui->selftest_label_14, "Deutsch");
	lv_label_set_long_mode(ui->selftest_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_14, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_add_flag(ui->selftest_label_14,LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_style(ui->selftest_label_14, &labelstyle_opa_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_15
	ui->selftest_label_15 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_15, 42+ REVISE_X, 233+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_15, 187, 28);
	lv_label_set_text(ui->selftest_label_15, "4");
	lv_label_set_long_mode(ui->selftest_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_15, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_add_style(ui->selftest_label_15, &labelstyle_opa_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_15,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_label_16
	ui->selftest_label_16 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_16, 42+ REVISE_X, 297+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_16, 187, 28);
	lv_label_set_text(ui->selftest_label_16, "5");
	lv_label_set_long_mode(ui->selftest_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_16, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_add_style(ui->selftest_label_16, &labelstyle_opa_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_16,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_label_17
	ui->selftest_label_17 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_17, 42+ REVISE_X, 361+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_17, 187, 28);
	lv_label_set_text(ui->selftest_label_17, "6");
	lv_label_set_long_mode(ui->selftest_label_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_17, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_add_style(ui->selftest_label_17, &labelstyle_opa_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_17,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_label_18
	ui->selftest_label_18 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_18, 42+ REVISE_X, 425+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_18, 187, 28);
	lv_label_set_text(ui->selftest_label_18, "7");
	lv_label_set_long_mode(ui->selftest_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_18, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_add_style(ui->selftest_label_18, &labelstyle_opa_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_18,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_label_19
	ui->selftest_label_19 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_19, 42+ REVISE_X, 489+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_19, 187, 28);
	lv_label_set_text(ui->selftest_label_19, "8");
	lv_label_set_long_mode(ui->selftest_label_19, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_19, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_add_style(ui->selftest_label_19, &labelstyle_opa_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_19,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_label_20
	ui->selftest_label_20 = lv_label_create(ui->selftest_tabview_1_title2);
	lv_obj_set_pos(ui->selftest_label_20, 42+ REVISE_X, 553+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_20, 187, 28);
	lv_label_set_text(ui->selftest_label_20, "9");
	lv_label_set_long_mode(ui->selftest_label_20, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_20, LV_TEXT_ALIGN_LEFT, 0);
	lv_obj_add_style(ui->selftest_label_20, &labelstyle_opa_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_label_20,LV_OBJ_FLAG_CLICKABLE);

	//Write codes selftest_label_21
	ui->selftest_label_21 = lv_label_create(ui->selftest_tabview_1_title3);
	lv_obj_set_pos(ui->selftest_label_21, 112+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_21, 280, 32);
	lv_label_set_text(ui->selftest_label_21, "选择时区");
	lv_label_set_long_mode(ui->selftest_label_21, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_21, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_21_main_main_default
	static lv_style_t style_selftest_label_21_main_main_default;
	if (style_selftest_label_21_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_21_main_main_default);
	else
		lv_style_init(&style_selftest_label_21_main_main_default);
	lv_style_set_radius(&style_selftest_label_21_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_21_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_21_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_21_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_21_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_21_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_21_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_21_main_main_default, 2);
	lv_style_set_pad_left(&style_selftest_label_21_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_21_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_21_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_21_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_21, &style_selftest_label_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_2
	ui->selftest_btn_2 = lv_btn_create(ui->selftest_tabview_1_title3);
	lv_obj_set_pos(ui->selftest_btn_2, 48+ REVISE_X, 659+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_2, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_2_main_main_default
	static lv_style_t style_selftest_btn_2_main_main_default;
	if (style_selftest_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_2_main_main_default);
	else
		lv_style_init(&style_selftest_btn_2_main_main_default);
	lv_style_set_radius(&style_selftest_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_2_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_color(&style_selftest_btn_2_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_dir(&style_selftest_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_2, &style_selftest_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_2_label = lv_label_create(ui->selftest_btn_2);
	lv_label_set_text(ui->selftest_btn_2_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_2_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_3
	ui->selftest_btn_3 = lv_btn_create(ui->selftest_tabview_1_title3);
	lv_obj_set_pos(ui->selftest_btn_3, 310+ REVISE_X, 659+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_3, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_3_main_main_default
	static lv_style_t style_selftest_btn_3_main_main_default;
	if (style_selftest_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_3_main_main_default);
	else
		lv_style_init(&style_selftest_btn_3_main_main_default);
	lv_style_set_radius(&style_selftest_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_3_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_3, &style_selftest_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_3_label = lv_label_create(ui->selftest_btn_3);
	lv_label_set_text(ui->selftest_btn_3_label, "下一步");
	lv_obj_set_style_text_color(ui->selftest_btn_3_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_3_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_roller_1
	ui->selftest_roller_1 = lv_roller_create(ui->selftest_tabview_1_title3);
	lv_obj_set_pos(ui->selftest_roller_1, 144+ REVISE_X, 166+ REVISE_Y);

	//Write style state: LV_STATE_DEFAULT for style_selftest_roller_1_main_main_default
	static lv_style_t style_selftest_roller_1_main_main_default;
	if (style_selftest_roller_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_roller_1_main_main_default);
	else
		lv_style_init(&style_selftest_roller_1_main_main_default);
	lv_style_set_radius(&style_selftest_roller_1_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_roller_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_selftest_roller_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_selftest_roller_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_roller_1_main_main_default, 255);
	lv_style_set_border_color(&style_selftest_roller_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_selftest_roller_1_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_roller_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_add_style(ui->selftest_roller_1, &style_selftest_roller_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_selftest_roller_1_main_selected_default
	static lv_style_t style_selftest_roller_1_main_selected_default;
	if (style_selftest_roller_1_main_selected_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_roller_1_main_selected_default);
	else
		lv_style_init(&style_selftest_roller_1_main_selected_default);
	lv_style_set_bg_color(&style_selftest_roller_1_main_selected_default, lv_color_make(0x23, 0x26, 0x2e));
	lv_style_set_bg_grad_color(&style_selftest_roller_1_main_selected_default, lv_color_make(0x23, 0x26, 0x2e));
	lv_style_set_bg_grad_dir(&style_selftest_roller_1_main_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_roller_1_main_selected_default, 255);
	lv_style_set_text_color(&style_selftest_roller_1_main_selected_default, lv_color_make(0xFF, 0xFF, 0xFF));
	lv_obj_add_style(ui->selftest_roller_1, &style_selftest_roller_1_main_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->selftest_roller_1,"1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24",LV_ROLLER_MODE_INFINITE);
	lv_obj_set_style_text_font(ui->selftest_roller_1, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_roller_1, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->selftest_roller_1, &lv_font_simsun_24, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_visible_row_count(ui->selftest_roller_1,5);

	//Write codes selftest_roller_2
	ui->selftest_roller_2 = lv_roller_create(ui->selftest_tabview_1_title3);
	lv_obj_set_pos(ui->selftest_roller_2, 274+ REVISE_X, 167+ REVISE_Y);

	//Write style state: LV_STATE_DEFAULT for style_selftest_roller_2_main_main_default
	static lv_style_t style_selftest_roller_2_main_main_default;
	if (style_selftest_roller_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_roller_2_main_main_default);
	else
		lv_style_init(&style_selftest_roller_2_main_main_default);
	lv_style_set_radius(&style_selftest_roller_2_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_roller_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_selftest_roller_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_selftest_roller_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_roller_2_main_main_default, 255);
	lv_style_set_border_color(&style_selftest_roller_2_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_selftest_roller_2_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_roller_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_add_style(ui->selftest_roller_2, &style_selftest_roller_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_selftest_roller_2_main_selected_default
	static lv_style_t style_selftest_roller_2_main_selected_default;
	if (style_selftest_roller_2_main_selected_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_roller_2_main_selected_default);
	else
		lv_style_init(&style_selftest_roller_2_main_selected_default);
	lv_style_set_bg_color(&style_selftest_roller_2_main_selected_default, lv_color_make(0x23, 0x26, 0x2e));
	lv_style_set_bg_grad_color(&style_selftest_roller_2_main_selected_default, lv_color_make(0x23, 0x26, 0x2e));
	lv_style_set_bg_grad_dir(&style_selftest_roller_2_main_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_roller_2_main_selected_default, 255);
	lv_style_set_text_color(&style_selftest_roller_2_main_selected_default, lv_color_make(0xFF, 0xFF, 0xFF));
	lv_obj_add_style(ui->selftest_roller_2, &style_selftest_roller_2_main_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->selftest_roller_2,"0\n15\n30\n45\n60",LV_ROLLER_MODE_INFINITE);
	lv_obj_set_style_text_font(ui->selftest_roller_2, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_roller_2, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->selftest_roller_2, &lv_font_simsun_24, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_visible_row_count(ui->selftest_roller_2,5);

	//Write codes selftest_label_22
	ui->selftest_label_22 = lv_label_create(ui->selftest_tabview_1_title3);
	lv_obj_set_pos(ui->selftest_label_22, 62+ REVISE_X, 80+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_22, 380, 28);
	lv_label_set_text(ui->selftest_label_22, "UTC时间 2022 09 22 17：36");
	lv_label_set_long_mode(ui->selftest_label_22, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_22, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_22_main_main_default
	static lv_style_t style_selftest_label_22_main_main_default;
	if (style_selftest_label_22_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_22_main_main_default);
	else
		lv_style_init(&style_selftest_label_22_main_main_default);
	lv_style_set_radius(&style_selftest_label_22_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_22_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_label_22_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_label_22_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_22_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_22_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_22_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_22_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_22_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_22_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_22_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_22_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_22, &style_selftest_label_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_23
	ui->selftest_label_23 = lv_label_create(ui->selftest_tabview_1_title3);
	lv_obj_set_pos(ui->selftest_label_23, 220+ REVISE_X, 267+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_23, 26, 39);
	lv_label_set_text(ui->selftest_label_23, "时");
	lv_label_set_long_mode(ui->selftest_label_23, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_23, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_23_main_main_default
	static lv_style_t style_selftest_label_23_main_main_default;
	if (style_selftest_label_23_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_23_main_main_default);
	else
		lv_style_init(&style_selftest_label_23_main_main_default);
	lv_style_set_radius(&style_selftest_label_23_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_23_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_label_23_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_label_23_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_23_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_23_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_23_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_23_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_23_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_23_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_23_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_23_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_23, &style_selftest_label_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_24
	ui->selftest_label_24 = lv_label_create(ui->selftest_tabview_1_title3);
	lv_obj_set_pos(ui->selftest_label_24, 359+ REVISE_X, 264+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_24, 26, 39);
	lv_label_set_text(ui->selftest_label_24, "分");
	lv_label_set_long_mode(ui->selftest_label_24, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_24, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_24_main_main_default
	static lv_style_t style_selftest_label_24_main_main_default;
	if (style_selftest_label_24_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_24_main_main_default);
	else
		lv_style_init(&style_selftest_label_24_main_main_default);
	lv_style_set_radius(&style_selftest_label_24_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_24_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_label_24_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_label_24_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_24_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_24_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_24_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_24_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_24_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_24_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_24_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_24_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_24, &style_selftest_label_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_25
	ui->selftest_label_25 = lv_label_create(ui->selftest_tabview_1_title3);
	lv_obj_set_pos(ui->selftest_label_25, 84+ REVISE_X, 490+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_25, 336, 24);
	lv_label_set_text(ui->selftest_label_25, "本地时间 2022 09 22 09：34");
	lv_label_set_long_mode(ui->selftest_label_25, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_25, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_25_main_main_default
	static lv_style_t style_selftest_label_25_main_main_default;
	if (style_selftest_label_25_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_25_main_main_default);
	else
		lv_style_init(&style_selftest_label_25_main_main_default);
	lv_style_set_radius(&style_selftest_label_25_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_25_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_label_25_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_label_25_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_25_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_25_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_selftest_label_25_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_25_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_25_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_25_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_25_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_25_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_25, &style_selftest_label_25_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_26
	ui->selftest_label_26 = lv_label_create(ui->selftest_tabview_1_Title4);
	lv_obj_set_pos(ui->selftest_label_26, 112+ REVISE_X, -24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_26, 280, 32);
	lv_label_set_text(ui->selftest_label_26, "语言选择");
	lv_label_set_long_mode(ui->selftest_label_26, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_26, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_26_main_main_default
	static lv_style_t style_selftest_label_26_main_main_default;
	if (style_selftest_label_26_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_26_main_main_default);
	else
		lv_style_init(&style_selftest_label_26_main_main_default);
	lv_style_set_radius(&style_selftest_label_26_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_26_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_26_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_26_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_26_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_26_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_26_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_26_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_26_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_26_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_26_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_26_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_26, &style_selftest_label_26_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_4
	ui->selftest_btn_4 = lv_btn_create(ui->selftest_tabview_1_Title4);
	lv_obj_set_pos(ui->selftest_btn_4, 47+ REVISE_X, 659+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_4, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_4_main_main_default
	static lv_style_t style_selftest_btn_4_main_main_default;
	if (style_selftest_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_4_main_main_default);
	else
		lv_style_init(&style_selftest_btn_4_main_main_default);
	lv_style_set_radius(&style_selftest_btn_4_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_4_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_color(&style_selftest_btn_4_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_dir(&style_selftest_btn_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_4_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_4_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_4_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_4, &style_selftest_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_4_label = lv_label_create(ui->selftest_btn_4);
	lv_label_set_text(ui->selftest_btn_4_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_4_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_4_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_5
	ui->selftest_btn_5 = lv_btn_create(ui->selftest_tabview_1_Title4);
	lv_obj_set_pos(ui->selftest_btn_5, 309+ REVISE_X, 659+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_5, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_5_main_main_default
	static lv_style_t style_selftest_btn_5_main_main_default;
	if (style_selftest_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_5_main_main_default);
	else
		lv_style_init(&style_selftest_btn_5_main_main_default);
	lv_style_set_radius(&style_selftest_btn_5_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_5_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_5_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_5_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_5_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_5_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_5, &style_selftest_btn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_5_label = lv_label_create(ui->selftest_btn_5);
	lv_label_set_text(ui->selftest_btn_5_label, "下一步");
	lv_obj_set_style_text_color(ui->selftest_btn_5_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_5_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_cb_1
	ui->selftest_cb_1 = lv_checkbox_create(ui->selftest_tabview_1_Title4);
	lv_obj_set_pos(ui->selftest_cb_1, 77+ REVISE_X, 617+ REVISE_Y);
	lv_checkbox_set_text(ui->selftest_cb_1, "我已阅读并同意该隐私政策");

	//Write style state: LV_STATE_DEFAULT for style_selftest_cb_1_main_main_default
	static lv_style_t style_selftest_cb_1_main_main_default;
	if (style_selftest_cb_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_cb_1_main_main_default);
	else
		lv_style_init(&style_selftest_cb_1_main_main_default);
	lv_style_set_radius(&style_selftest_cb_1_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_selftest_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_selftest_cb_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_cb_1_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_cb_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_cb_1_main_main_default, 0);
	lv_obj_add_style(ui->selftest_cb_1, &style_selftest_cb_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_selftest_cb_1_main_indicator_default
	static lv_style_t style_selftest_cb_1_main_indicator_default;
	if (style_selftest_cb_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_cb_1_main_indicator_default);
	else
		lv_style_init(&style_selftest_cb_1_main_indicator_default);
	lv_style_set_radius(&style_selftest_cb_1_main_indicator_default, 0);
	lv_style_set_bg_color(&style_selftest_cb_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_cb_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_cb_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_cb_1_main_indicator_default, 255);
	lv_style_set_border_color(&style_selftest_cb_1_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_cb_1_main_indicator_default, 0);
	lv_obj_add_style(ui->selftest_cb_1, &style_selftest_cb_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes selftest_label_27
	ui->selftest_label_27 = lv_label_create(ui->selftest_tabview_1_Title4);
	lv_obj_set_pos(ui->selftest_label_27, 32+ REVISE_X, 16+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_27, 280, 28);
	lv_label_set_text(ui->selftest_label_27, "前言");
	lv_label_set_long_mode(ui->selftest_label_27, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_27, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_27_main_main_default
	static lv_style_t style_selftest_label_27_main_main_default;
	if (style_selftest_label_27_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_27_main_main_default);
	else
		lv_style_init(&style_selftest_label_27_main_main_default);
	lv_style_set_radius(&style_selftest_label_27_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_27_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_27_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_27_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_27_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_27_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_27_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_27_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_27_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_27_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_27_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_27_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_27, &style_selftest_label_27_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_28
	ui->selftest_label_28 = lv_label_create(ui->selftest_tabview_1_Title4);
	lv_obj_set_pos(ui->selftest_label_28, 31+ REVISE_X, 58+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_28, 416, 568);
	lv_label_set_text(ui->selftest_label_28, "深圳市创想三维科技股份有限公司一向庄严承诺保护使用Creality的产品和服务（以下统称“Creality服务”）之用户（以下统称“用户”或“您”）的隐私。您在使用Creality服务时，我们可能会收集和使用您的相关信息。请注意我们会不时地检查我们的政策，因此有关的措施会随之变化。我们恳请您定期光顾本页面，以确保对我们《隐私政策》最新版本始终保持了解。在阅读完本政策之后，如您对本《隐私政策》或与本《隐私政策》相关的事宜有任何问题，请  v@creality.com联系。 您使用或继续使用Creality服务，都表示您同意我们按照本《隐私政策》收集、使用、储存和分享您的信息。");
	lv_label_set_long_mode(ui->selftest_label_28, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_28, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_28_main_main_default
	static lv_style_t style_selftest_label_28_main_main_default;
	if (style_selftest_label_28_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_28_main_main_default);
	else
		lv_style_init(&style_selftest_label_28_main_main_default);
	lv_style_set_radius(&style_selftest_label_28_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_28_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_28_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_28_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_28_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_28_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_selftest_label_28_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_28_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_28_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_28_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_28_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_28_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_28, &style_selftest_label_28_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_29
	ui->selftest_label_29 = lv_label_create(ui->selftest_tabview_1_Title5);
	lv_obj_set_pos(ui->selftest_label_29, 111+ REVISE_X, -24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_29, 280, 32);
	lv_label_set_text(ui->selftest_label_29, "网络设置");
	lv_label_set_long_mode(ui->selftest_label_29, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_29, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_29_main_main_default
	static lv_style_t style_selftest_label_29_main_main_default;
	if (style_selftest_label_29_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_29_main_main_default);
	else
		lv_style_init(&style_selftest_label_29_main_main_default);
	lv_style_set_radius(&style_selftest_label_29_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_29_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_29_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_29_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_29_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_29_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_29_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_29_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_29_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_29_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_29_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_29_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_29, &style_selftest_label_29_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_list_1
	ui->selftest_list_1 = lv_list_create(ui->selftest_tabview_1_Title5);
	lv_obj_set_pos(ui->selftest_list_1, 34+ REVISE_X, 103+ REVISE_Y);
	lv_obj_set_size(ui->selftest_list_1, 420, 493);

	//Write style state: LV_STATE_DEFAULT for style_selftest_list_1_main_main_default
	static lv_style_t style_selftest_list_1_main_main_default;
	if (style_selftest_list_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_list_1_main_main_default);
	else
		lv_style_init(&style_selftest_list_1_main_main_default);
	lv_style_set_radius(&style_selftest_list_1_main_main_default, 3);
	lv_style_set_bg_color(&style_selftest_list_1_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_list_1_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_list_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_list_1_main_main_default, 255);
	lv_style_set_border_color(&style_selftest_list_1_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_selftest_list_1_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_list_1_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_list_1_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_list_1_main_main_default, 0);
	lv_obj_add_style(ui->selftest_list_1, &style_selftest_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_list_1_main_scrollbar_default
	static lv_style_t style_settings_list_1_main_scrollbar_default;
	if (style_settings_list_1_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_settings_list_1_main_scrollbar_default);
	else
		lv_style_init(&style_settings_list_1_main_scrollbar_default);
	lv_style_set_radius(&style_settings_list_1_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_settings_list_1_main_scrollbar_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_list_1_main_scrollbar_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_list_1_main_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_list_1_main_scrollbar_default, 255);
	lv_obj_add_style(ui->settings_list_1, &style_settings_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_selftest_list_1_main_scrollbar_default
	static lv_style_t style_selftest_list_1_main_scrollbar_default;
	if (style_selftest_list_1_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_list_1_main_scrollbar_default);
	else
		lv_style_init(&style_selftest_list_1_main_scrollbar_default);
	lv_style_set_radius(&style_selftest_list_1_main_scrollbar_default, 3);
	lv_style_set_bg_color(&style_selftest_list_1_main_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_selftest_list_1_main_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_selftest_list_1_main_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_list_1_main_scrollbar_default, 255);
	lv_obj_add_style(ui->selftest_list_1, &style_selftest_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes selftest_label_30
	ui->selftest_label_30 = lv_label_create(ui->selftest_tabview_1_Title5);
	lv_obj_set_pos(ui->selftest_label_30, 75+ REVISE_X, 42+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_30, 150, 24);
	lv_label_set_text(ui->selftest_label_30, "网络设置");
	lv_label_set_long_mode(ui->selftest_label_30, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_30, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_30_main_main_default
	static lv_style_t style_selftest_label_30_main_main_default;
	if (style_selftest_label_30_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_30_main_main_default);
	else
		lv_style_init(&style_selftest_label_30_main_main_default);
	lv_style_set_radius(&style_selftest_label_30_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_30_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_30_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_30_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_30_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_30_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_30_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_30_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_30_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_30_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_30_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_30_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_30, &style_selftest_label_30_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_31
	ui->selftest_label_31 = lv_label_create(ui->selftest_tabview_1_Title5);
	lv_obj_set_pos(ui->selftest_label_31, 340+ REVISE_X, 42+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_31, 92, 24);
	lv_label_set_text(ui->selftest_label_31, "未连接");
	lv_label_set_long_mode(ui->selftest_label_31, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_31, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_31_main_main_default
	static lv_style_t style_selftest_label_31_main_main_default;
	if (style_selftest_label_31_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_31_main_main_default);
	else
		lv_style_init(&style_selftest_label_31_main_main_default);
	lv_style_set_radius(&style_selftest_label_31_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_31_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_31_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_31_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_31_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_31_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_31_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_31_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_31_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_31_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_31_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_31_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_31, &style_selftest_label_31_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_32
	ui->selftest_label_32 = lv_label_create(ui->selftest_tabview_1_Title5);
	lv_obj_set_pos(ui->selftest_label_32, 34+ REVISE_X, 78+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_32, 430, 1);
	lv_label_set_text(ui->selftest_label_32, "");
	lv_label_set_long_mode(ui->selftest_label_32, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_32, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_32_main_main_default
	static lv_style_t style_selftest_label_32_main_main_default;
	if (style_selftest_label_32_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_32_main_main_default);
	else
		lv_style_init(&style_selftest_label_32_main_main_default);
	lv_style_set_radius(&style_selftest_label_32_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_32_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_color(&style_selftest_label_32_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_dir(&style_selftest_label_32_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_32_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_32_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_32_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_32_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_32_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_32_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_32_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_32, &style_selftest_label_32_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_11
	ui->selftest_img_11 = lv_img_create(ui->selftest_tabview_1_Title5);
	lv_obj_set_pos(ui->selftest_img_11, 41+ REVISE_X, 36+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_11, 36, 36);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_11_main_main_default
	static lv_style_t style_selftest_img_11_main_main_default;
	if (style_selftest_img_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_11_main_main_default);
	else
		lv_style_init(&style_selftest_img_11_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_11_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_11_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_11, &style_selftest_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_11,&_network_36x36);
	lv_img_set_pivot(ui->selftest_img_11, 0,0);
	lv_img_set_angle(ui->selftest_img_11, 0);

	//Write codes selftest_img_12
	ui->selftest_img_12 = lv_img_create(ui->selftest_tabview_1_Title5);
	lv_obj_set_pos(ui->selftest_img_12, 438+ REVISE_X, 40+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_12, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_12_main_main_default
	static lv_style_t style_selftest_img_12_main_main_default;
	if (style_selftest_img_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_12_main_main_default);
	else
		lv_style_init(&style_selftest_img_12_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_12_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_12_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_12, &style_selftest_img_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_12, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_12,&_Vector_24_14x28);
	lv_img_set_pivot(ui->selftest_img_12, 0,0);
	lv_img_set_angle(ui->selftest_img_12, 0);

	//Write codes selftest_btn_6
	ui->selftest_btn_6 = lv_btn_create(ui->selftest_tabview_1_Title5);
	lv_obj_set_pos(ui->selftest_btn_6, 395+ REVISE_X, -35+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_6, 86, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_6_main_main_default
	static lv_style_t style_selftest_btn_6_main_main_default;
	if (style_selftest_btn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_6_main_main_default);
	else
		lv_style_init(&style_selftest_btn_6_main_main_default);
	lv_style_set_radius(&style_selftest_btn_6_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_6_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_6_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_6_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_6_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_6_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_6_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_6, &style_selftest_btn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_6_label = lv_label_create(ui->selftest_btn_6);
	lv_label_set_text(ui->selftest_btn_6_label, "跳过");
	lv_obj_set_style_text_color(ui->selftest_btn_6_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_6_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_6, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_6_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_7
	ui->selftest_btn_7 = lv_btn_create(ui->selftest_tabview_1_Title5);
	lv_obj_set_pos(ui->selftest_btn_7, 45+ REVISE_X, 658+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_7, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_7_main_main_default
	static lv_style_t style_selftest_btn_7_main_main_default;
	if (style_selftest_btn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_7_main_main_default);
	else
		lv_style_init(&style_selftest_btn_7_main_main_default);
	lv_style_set_radius(&style_selftest_btn_7_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_7_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_7_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_7_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_7_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_7_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_7_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_7, &style_selftest_btn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_7_label = lv_label_create(ui->selftest_btn_7);
	lv_label_set_text(ui->selftest_btn_7_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_7_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_7_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_7, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_7_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_8
	ui->selftest_btn_8 = lv_btn_create(ui->selftest_tabview_1_Title5);
	lv_obj_set_pos(ui->selftest_btn_8, 307+ REVISE_X, 658+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_8, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_8_main_main_default
	static lv_style_t style_selftest_btn_8_main_main_default;
	if (style_selftest_btn_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_8_main_main_default);
	else
		lv_style_init(&style_selftest_btn_8_main_main_default);
	lv_style_set_radius(&style_selftest_btn_8_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_8_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_8_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_8_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_8_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_8_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_8_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_8, &style_selftest_btn_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_8_label = lv_label_create(ui->selftest_btn_8);
	lv_label_set_text(ui->selftest_btn_8_label, "下一步");
	lv_obj_set_style_text_color(ui->selftest_btn_8_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_8_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_8, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_8_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_33
	ui->selftest_label_33 = lv_label_create(ui->selftest_tabview_1_Title6);
	lv_obj_set_pos(ui->selftest_label_33, 109+ REVISE_X, -23+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_33, 280, 32);
	lv_label_set_text(ui->selftest_label_33, "打印机自检");
	lv_label_set_long_mode(ui->selftest_label_33, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_33, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_33_main_main_default
	static lv_style_t style_selftest_label_33_main_main_default;
	if (style_selftest_label_33_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_33_main_main_default);
	else
		lv_style_init(&style_selftest_label_33_main_main_default);
	lv_style_set_radius(&style_selftest_label_33_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_33_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_33_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_33_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_33_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_33_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_33_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_33_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_33_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_33_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_33_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_33_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_33, &style_selftest_label_33_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_34
	ui->selftest_label_34 = lv_label_create(ui->selftest_tabview_1_Title6);
	lv_obj_set_pos(ui->selftest_label_34, 23+ REVISE_X, 25+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_34, 450, 235);
	lv_label_set_text(ui->selftest_label_34, "");
	lv_label_set_long_mode(ui->selftest_label_34, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_34, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_34_main_main_default
	static lv_style_t style_selftest_label_34_main_main_default;
	if (style_selftest_label_34_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_34_main_main_default);
	else
		lv_style_init(&style_selftest_label_34_main_main_default);
	lv_style_set_radius(&style_selftest_label_34_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_34_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_34_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_34_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_34_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_34_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_34_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_34_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_34_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_34_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_34_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_34, &style_selftest_label_34_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_13
	ui->selftest_img_13 = lv_img_create(ui->selftest_tabview_1_Title6);
	lv_obj_set_pos(ui->selftest_img_13, 151+ REVISE_X, 35+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_13, 192, 215);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_13_main_main_default
	static lv_style_t style_selftest_img_13_main_main_default;
	if (style_selftest_img_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_13_main_main_default);
	else
		lv_style_init(&style_selftest_img_13_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_13_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_13_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_13, &style_selftest_img_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_13, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_13,&_machine_192x215);
	lv_img_set_pivot(ui->selftest_img_13, 0,0);
	lv_img_set_angle(ui->selftest_img_13, 0);

	//Write codes selftest_label_35
	ui->selftest_label_35 = lv_label_create(ui->selftest_tabview_1_Title6);
	lv_obj_set_pos(ui->selftest_label_35, 22+ REVISE_X, 273+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_35, 450, 352);
	lv_label_set_text(ui->selftest_label_35, "");
	lv_label_set_long_mode(ui->selftest_label_35, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_35, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_35_main_main_default
	static lv_style_t style_selftest_label_35_main_main_default;
	if (style_selftest_label_35_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_35_main_main_default);
	else
		lv_style_init(&style_selftest_label_35_main_main_default);
	lv_style_set_radius(&style_selftest_label_35_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_35_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_35_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_35_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_35_main_main_default, 227);
	lv_style_set_text_color(&style_selftest_label_35_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_35_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_35_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_35_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_35_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_35_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_35, &style_selftest_label_35_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_36
	ui->selftest_label_36 = lv_label_create(ui->selftest_tabview_1_Title6);
	lv_obj_set_pos(ui->selftest_label_36, 42+ REVISE_X, 297+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_36, 377, 32);
	lv_label_set_text(ui->selftest_label_36, "欢迎来到自检流程");
	lv_label_set_long_mode(ui->selftest_label_36, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_36, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_36_main_main_default
	static lv_style_t style_selftest_label_36_main_main_default;
	if (style_selftest_label_36_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_36_main_main_default);
	else
		lv_style_init(&style_selftest_label_36_main_main_default);
	lv_style_set_radius(&style_selftest_label_36_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_36_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_label_36_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_label_36_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_36_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_36_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_36_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_36_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_36_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_36_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_36_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_36_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_36, &style_selftest_label_36_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_37
	ui->selftest_label_37 = lv_label_create(ui->selftest_tabview_1_Title6);
	lv_obj_set_pos(ui->selftest_label_37, 42+ REVISE_X, 337+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_37, 432, 24);
	lv_label_set_text(ui->selftest_label_37, "1.请保证打印机热床和喷嘴表面的清洁；");
	lv_label_set_long_mode(ui->selftest_label_37, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_37, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_37_main_main_default
	static lv_style_t style_selftest_label_37_main_main_default;
	if (style_selftest_label_37_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_37_main_main_default);
	else
		lv_style_init(&style_selftest_label_37_main_main_default);
	lv_style_set_radius(&style_selftest_label_37_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_37_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_37_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_37_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_37_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_37_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_37_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_37_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_37_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_37_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_37_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_37_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_37, &style_selftest_label_37_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_38
	ui->selftest_label_38 = lv_label_create(ui->selftest_tabview_1_Title6);
	lv_obj_set_pos(ui->selftest_label_38, 42+ REVISE_X, 375+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_38, 432, 24);
	lv_label_set_text(ui->selftest_label_38, "2.自检过程需要持续30分钟左右。");
	lv_label_set_long_mode(ui->selftest_label_38, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_38, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_38_main_main_default
	static lv_style_t style_selftest_label_38_main_main_default;
	if (style_selftest_label_38_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_38_main_main_default);
	else
		lv_style_init(&style_selftest_label_38_main_main_default);
	lv_style_set_radius(&style_selftest_label_38_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_38_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_38_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_38_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_38_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_38_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_38_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_38_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_38_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_38_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_38_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_38_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_38, &style_selftest_label_38_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_9
	ui->selftest_btn_9 = lv_btn_create(ui->selftest_tabview_1_Title6);
	lv_obj_set_pos(ui->selftest_btn_9, 387+ REVISE_X, -36+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_9, 86, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_9_main_main_default
	static lv_style_t style_selftest_btn_9_main_main_default;
	if (style_selftest_btn_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_9_main_main_default);
	else
		lv_style_init(&style_selftest_btn_9_main_main_default);
	lv_style_set_radius(&style_selftest_btn_9_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_9_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_9_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_9_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_9_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_9_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_9_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_9, &style_selftest_btn_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_9_label = lv_label_create(ui->selftest_btn_9);
	lv_label_set_text(ui->selftest_btn_9_label, "跳过");
	lv_obj_set_style_text_color(ui->selftest_btn_9_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_9_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_9, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_9_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_10
	ui->selftest_btn_10 = lv_btn_create(ui->selftest_tabview_1_Title6);
	lv_obj_set_pos(ui->selftest_btn_10, 43+ REVISE_X, 658+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_10, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_10_main_main_default
	static lv_style_t style_selftest_btn_10_main_main_default;
	if (style_selftest_btn_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_10_main_main_default);
	else
		lv_style_init(&style_selftest_btn_10_main_main_default);
	lv_style_set_radius(&style_selftest_btn_10_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_10_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_10_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_10_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_10_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_10_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_10_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_10, &style_selftest_btn_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_10_label = lv_label_create(ui->selftest_btn_10);
	lv_label_set_text(ui->selftest_btn_10_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_10_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_10_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_10, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_10_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_11
	ui->selftest_btn_11 = lv_btn_create(ui->selftest_tabview_1_Title6);
	lv_obj_set_pos(ui->selftest_btn_11, 305+ REVISE_X, 658+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_11, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_11_main_main_default
	static lv_style_t style_selftest_btn_11_main_main_default;
	if (style_selftest_btn_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_11_main_main_default);
	else
		lv_style_init(&style_selftest_btn_11_main_main_default);
	lv_style_set_radius(&style_selftest_btn_11_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_11_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_11_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_11_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_11_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_11_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_11_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_11, &style_selftest_btn_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_11_label = lv_label_create(ui->selftest_btn_11);
	lv_label_set_text(ui->selftest_btn_11_label, "开始检测");
	lv_obj_set_style_text_color(ui->selftest_btn_11_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_11_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_11, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_11_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_39
	ui->selftest_label_39 = lv_label_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_label_39, 18+ REVISE_X, -29+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_39, 17, 24);
	lv_label_set_text(ui->selftest_label_39, "1");
	lv_label_set_long_mode(ui->selftest_label_39, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_39, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_39_main_main_default
	static lv_style_t style_selftest_label_39_main_main_default;
	if (style_selftest_label_39_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_39_main_main_default);
	else
		lv_style_init(&style_selftest_label_39_main_main_default);
	lv_style_set_radius(&style_selftest_label_39_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_39_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_39_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_39_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_39_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_39_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_39_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_39_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_39_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_39_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_39_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_39_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_39, &style_selftest_label_39_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_12
	ui->selftest_btn_12 = lv_btn_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_btn_12, 387+ REVISE_X, -38+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_12, 86, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_12_main_main_default
	static lv_style_t style_selftest_btn_12_main_main_default;
	if (style_selftest_btn_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_12_main_main_default);
	else
		lv_style_init(&style_selftest_btn_12_main_main_default);
	lv_style_set_radius(&style_selftest_btn_12_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_12_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_12_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_12_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_12_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_12_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_12_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_12, &style_selftest_btn_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_12_label = lv_label_create(ui->selftest_btn_12);
	lv_label_set_text(ui->selftest_btn_12_label, "跳过");
	lv_obj_set_style_text_color(ui->selftest_btn_12_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_12_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_12, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_12_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_13
	ui->selftest_btn_13 = lv_btn_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_btn_13, 170+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_13, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_13_main_main_default
	static lv_style_t style_selftest_btn_13_main_main_default;
	if (style_selftest_btn_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_13_main_main_default);
	else
		lv_style_init(&style_selftest_btn_13_main_main_default);
	lv_style_set_radius(&style_selftest_btn_13_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_13_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_13_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_13_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_13_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_13_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_13_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_13_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_13, &style_selftest_btn_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_13_label = lv_label_create(ui->selftest_btn_13);
	lv_label_set_text(ui->selftest_btn_13_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_13_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_13_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_13, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_13_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_40
	ui->selftest_label_40 = lv_label_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_label_40, 30+ REVISE_X, -29+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_40, 26, 24);
	lv_label_set_text(ui->selftest_label_40, "/7");
	lv_label_set_long_mode(ui->selftest_label_40, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_40, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_40_main_main_default
	static lv_style_t style_selftest_label_40_main_main_default;
	if (style_selftest_label_40_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_40_main_main_default);
	else
		lv_style_init(&style_selftest_label_40_main_main_default);
	lv_style_set_radius(&style_selftest_label_40_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_40_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_40_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_40_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_40_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_40_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_40_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_40_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_40_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_40_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_40_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_40_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_40, &style_selftest_label_40_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_41
	ui->selftest_label_41 = lv_label_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_label_41, 103+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_41, 280, 32);
	lv_label_set_text(ui->selftest_label_41, "喉管散热风扇检测");
	lv_label_set_long_mode(ui->selftest_label_41, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_41, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_41_main_main_default
	static lv_style_t style_selftest_label_41_main_main_default;
	if (style_selftest_label_41_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_41_main_main_default);
	else
		lv_style_init(&style_selftest_label_41_main_main_default);
	lv_style_set_radius(&style_selftest_label_41_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_41_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_41_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_41_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_41_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_41_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_41_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_41_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_41_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_41_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_41_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_41_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_41, &style_selftest_label_41_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_42
	ui->selftest_label_42 = lv_label_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_label_42, 18+ REVISE_X, 24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_42, 450, 235);
	lv_label_set_text(ui->selftest_label_42, "");
	lv_label_set_long_mode(ui->selftest_label_42, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_42, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_42_main_main_default
	static lv_style_t style_selftest_label_42_main_main_default;
	if (style_selftest_label_42_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_42_main_main_default);
	else
		lv_style_init(&style_selftest_label_42_main_main_default);
	lv_style_set_radius(&style_selftest_label_42_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_42_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_42_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_42_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_42_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_42_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_42_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_42_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_42_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_42_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_42_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_42, &style_selftest_label_42_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_44
	ui->selftest_label_44 = lv_label_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_label_44, 18+ REVISE_X, 271+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_44, 450, 352);
	lv_label_set_text(ui->selftest_label_44, "");
	lv_label_set_long_mode(ui->selftest_label_44, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_44, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_44_main_main_default
	static lv_style_t style_selftest_label_44_main_main_default;
	if (style_selftest_label_44_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_44_main_main_default);
	else
		lv_style_init(&style_selftest_label_44_main_main_default);
	lv_style_set_radius(&style_selftest_label_44_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_44_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_44_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_44_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_44_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_44_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_44_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_44_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_44_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_44_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_44_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_44, &style_selftest_label_44_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_14
	ui->selftest_img_14 = lv_img_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_img_14, 153+ REVISE_X, 48+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_14, 164, 125);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_14_main_main_default
	static lv_style_t style_selftest_img_14_main_main_default;
	if (style_selftest_img_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_14_main_main_default);
	else
		lv_style_init(&style_selftest_img_14_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_14_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_14_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_14, &style_selftest_img_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_14, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_14,&_hotfan_164x125);
	lv_img_set_pivot(ui->selftest_img_14, 0,0);
	lv_img_set_angle(ui->selftest_img_14, 0);

	//Write codes selftest_label_43
	ui->selftest_label_43 = lv_label_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_label_43, 153+ REVISE_X, 200+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_43, 195, 24);
	lv_label_set_text(ui->selftest_label_43, "喉管散热风扇位置");
	lv_label_set_long_mode(ui->selftest_label_43, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_43, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_43_main_main_default
	static lv_style_t style_selftest_label_43_main_main_default;
	if (style_selftest_label_43_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_43_main_main_default);
	else
		lv_style_init(&style_selftest_label_43_main_main_default);
	lv_style_set_radius(&style_selftest_label_43_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_43_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_43_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_43_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_43_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_43_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_font(&style_selftest_label_43_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_43_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_43_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_43_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_43_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_43_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_43, &style_selftest_label_43_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_45
	ui->selftest_label_45 = lv_label_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_label_45, 33+ REVISE_X, 295+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_45, 422, 28);
	lv_label_set_text(ui->selftest_label_45, "5S后请查看喉管散热风扇是否正常转动");
	lv_label_set_long_mode(ui->selftest_label_45, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_45, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_45_main_main_default
	static lv_style_t style_selftest_label_45_main_main_default;
	if (style_selftest_label_45_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_45_main_main_default);
	else
		lv_style_init(&style_selftest_label_45_main_main_default);
	lv_style_set_radius(&style_selftest_label_45_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_45_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_45_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_45_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_45_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_45_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_45_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_45_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_45_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_45_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_45_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_45_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_45, &style_selftest_label_45_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_46
	ui->selftest_label_46 = lv_label_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_label_46, 33+ REVISE_X, 335+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_46, 410, 24);
	lv_label_set_text(ui->selftest_label_46, "1.正常转动将进行下一步；");
	lv_label_set_long_mode(ui->selftest_label_46, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_46, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_46_main_main_default
	static lv_style_t style_selftest_label_46_main_main_default;
	if (style_selftest_label_46_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_46_main_main_default);
	else
		lv_style_init(&style_selftest_label_46_main_main_default);
	lv_style_set_radius(&style_selftest_label_46_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_46_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_46_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_46_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_46_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_46_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_46_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_46_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_46_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_46_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_46_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_46_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_46, &style_selftest_label_46_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_47
	ui->selftest_label_47 = lv_label_create(ui->selftest_tabview_1_Title7);
	lv_obj_set_pos(ui->selftest_label_47, 33+ REVISE_X, 373+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_47, 438, 24);
	lv_label_set_text(ui->selftest_label_47, "2.如不正常请查看说明书，或联系客服。");
	lv_label_set_long_mode(ui->selftest_label_47, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_47, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_47_main_main_default
	static lv_style_t style_selftest_label_47_main_main_default;
	if (style_selftest_label_47_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_47_main_main_default);
	else
		lv_style_init(&style_selftest_label_47_main_main_default);
	lv_style_set_radius(&style_selftest_label_47_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_47_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_47_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_47_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_47_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_47_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_47_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_47_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_47_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_47_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_47_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_47_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_47, &style_selftest_label_47_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_48
	ui->selftest_label_48 = lv_label_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_label_48, 18+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_48, 12, 24);
	lv_label_set_text(ui->selftest_label_48, "2");
	lv_label_set_long_mode(ui->selftest_label_48, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_48, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_48_main_main_default
	static lv_style_t style_selftest_label_48_main_main_default;
	if (style_selftest_label_48_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_48_main_main_default);
	else
		lv_style_init(&style_selftest_label_48_main_main_default);
	lv_style_set_radius(&style_selftest_label_48_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_48_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_48_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_48_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_48_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_48_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_48_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_48_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_48_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_48_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_48_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_48_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_48, &style_selftest_label_48_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_52
	ui->selftest_label_52 = lv_label_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_label_52, 17+ REVISE_X, 24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_52, 450, 235);
	lv_label_set_text(ui->selftest_label_52, "");
	lv_label_set_long_mode(ui->selftest_label_52, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_52, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_52_main_main_default
	static lv_style_t style_selftest_label_52_main_main_default;
	if (style_selftest_label_52_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_52_main_main_default);
	else
		lv_style_init(&style_selftest_label_52_main_main_default);
	lv_style_set_radius(&style_selftest_label_52_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_52_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_52_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_52_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_52_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_52_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_52_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_52_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_52_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_52_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_52_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_52, &style_selftest_label_52_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_53
	ui->selftest_label_53 = lv_label_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_label_53, 17+ REVISE_X, 271+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_53, 450, 352);
	lv_label_set_text(ui->selftest_label_53, "");
	lv_label_set_long_mode(ui->selftest_label_53, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_53, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_53_main_main_default
	static lv_style_t style_selftest_label_53_main_main_default;
	if (style_selftest_label_53_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_53_main_main_default);
	else
		lv_style_init(&style_selftest_label_53_main_main_default);
	lv_style_set_radius(&style_selftest_label_53_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_53_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_53_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_53_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_53_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_53_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_53_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_53_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_53_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_53_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_53_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_53, &style_selftest_label_53_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_15
	ui->selftest_img_15 = lv_img_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_img_15, 160+ REVISE_X, 48+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_15, 164, 138);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_15_main_main_default
	static lv_style_t style_selftest_img_15_main_main_default;
	if (style_selftest_img_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_15_main_main_default);
	else
		lv_style_init(&style_selftest_img_15_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_15_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_15_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_15, &style_selftest_img_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_15, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_15,&_modlefan_164x138);
	lv_img_set_pivot(ui->selftest_img_15, 0,0);
	lv_img_set_angle(ui->selftest_img_15, 0);

	//Write codes selftest_btn_14
	ui->selftest_btn_14 = lv_btn_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_btn_14, 387+ REVISE_X, -38+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_14, 86, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_14_main_main_default
	static lv_style_t style_selftest_btn_14_main_main_default;
	if (style_selftest_btn_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_14_main_main_default);
	else
		lv_style_init(&style_selftest_btn_14_main_main_default);
	lv_style_set_radius(&style_selftest_btn_14_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_14_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_14_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_14_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_14_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_14_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_14_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_14_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_14, &style_selftest_btn_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_14_label = lv_label_create(ui->selftest_btn_14);
	lv_label_set_text(ui->selftest_btn_14_label, "跳过");
	lv_obj_set_style_text_color(ui->selftest_btn_14_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_14_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_14, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_14_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_15
	ui->selftest_btn_15 = lv_btn_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_btn_15, 169+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_15, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_15_main_main_default
	static lv_style_t style_selftest_btn_15_main_main_default;
	if (style_selftest_btn_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_15_main_main_default);
	else
		lv_style_init(&style_selftest_btn_15_main_main_default);
	lv_style_set_radius(&style_selftest_btn_15_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_15_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_15_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_15_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_15_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_15_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_15_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_15_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_15, &style_selftest_btn_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_15_label = lv_label_create(ui->selftest_btn_15);
	lv_label_set_text(ui->selftest_btn_15_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_15_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_15_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_15, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_15_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_49
	ui->selftest_label_49 = lv_label_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_label_49, 30+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_49, 30, 24);
	lv_label_set_text(ui->selftest_label_49, "/7");
	lv_label_set_long_mode(ui->selftest_label_49, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_49, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_49_main_main_default
	static lv_style_t style_selftest_label_49_main_main_default;
	if (style_selftest_label_49_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_49_main_main_default);
	else
		lv_style_init(&style_selftest_label_49_main_main_default);
	lv_style_set_radius(&style_selftest_label_49_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_49_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_49_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_49_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_49_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_49_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_49_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_49_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_49_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_49_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_49_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_49_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_49, &style_selftest_label_49_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_50
	ui->selftest_label_50 = lv_label_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_label_50, 103+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_50, 280, 32);
	lv_label_set_text(ui->selftest_label_50, "模型冷却风扇检测");
	lv_label_set_long_mode(ui->selftest_label_50, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_50, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_50_main_main_default
	static lv_style_t style_selftest_label_50_main_main_default;
	if (style_selftest_label_50_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_50_main_main_default);
	else
		lv_style_init(&style_selftest_label_50_main_main_default);
	lv_style_set_radius(&style_selftest_label_50_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_50_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_50_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_50_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_50_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_50_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_50_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_50_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_50_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_50_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_50_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_50_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_50, &style_selftest_label_50_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_54
	ui->selftest_label_54 = lv_label_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_label_54, 37+ REVISE_X, 295+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_54, 410, 24);
	lv_label_set_text(ui->selftest_label_54, "5S后请查看模型冷却风扇是否转动正常");
	lv_label_set_long_mode(ui->selftest_label_54, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_54, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_54_main_main_default
	static lv_style_t style_selftest_label_54_main_main_default;
	if (style_selftest_label_54_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_54_main_main_default);
	else
		lv_style_init(&style_selftest_label_54_main_main_default);
	lv_style_set_radius(&style_selftest_label_54_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_54_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_54_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_54_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_54_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_54_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_54_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_54_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_54_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_54_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_54_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_54_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_54, &style_selftest_label_54_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_55
	ui->selftest_label_55 = lv_label_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_label_55, 37+ REVISE_X, 335+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_55, 410, 24);
	lv_label_set_text(ui->selftest_label_55, "1.正常转动将进行下一步；");
	lv_label_set_long_mode(ui->selftest_label_55, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_55, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_55_main_main_default
	static lv_style_t style_selftest_label_55_main_main_default;
	if (style_selftest_label_55_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_55_main_main_default);
	else
		lv_style_init(&style_selftest_label_55_main_main_default);
	lv_style_set_radius(&style_selftest_label_55_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_55_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_55_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_55_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_55_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_55_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_55_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_55_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_55_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_55_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_55_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_55_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_55, &style_selftest_label_55_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_56
	ui->selftest_label_56 = lv_label_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_label_56, 37+ REVISE_X, 376+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_56, 410, 24);
	lv_label_set_text(ui->selftest_label_56, "2.如不正常请查看说明书或联系客服。");
	lv_label_set_long_mode(ui->selftest_label_56, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_56, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_56_main_main_default
	static lv_style_t style_selftest_label_56_main_main_default;
	if (style_selftest_label_56_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_56_main_main_default);
	else
		lv_style_init(&style_selftest_label_56_main_main_default);
	lv_style_set_radius(&style_selftest_label_56_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_56_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_56_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_56_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_56_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_56_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_56_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_56_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_56_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_56_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_56_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_56_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_56, &style_selftest_label_56_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_51
	ui->selftest_label_51 = lv_label_create(ui->selftest_tabview_1_Title8);
	lv_obj_set_pos(ui->selftest_label_51, 102+ REVISE_X, 209+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_51, 280, 24);
	lv_label_set_text(ui->selftest_label_51, "模型冷却风扇位置");
	lv_label_set_long_mode(ui->selftest_label_51, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_51, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_51_main_main_default
	static lv_style_t style_selftest_label_51_main_main_default;
	if (style_selftest_label_51_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_51_main_main_default);
	else
		lv_style_init(&style_selftest_label_51_main_main_default);
	lv_style_set_radius(&style_selftest_label_51_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_51_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_51_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_51_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_51_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_51_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_font(&style_selftest_label_51_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_51_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_51_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_51_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_51_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_51_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_51, &style_selftest_label_51_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_57
	ui->selftest_label_57 = lv_label_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_label_57, 18+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_57, 12, 24);
	lv_label_set_text(ui->selftest_label_57, "3");
	lv_label_set_long_mode(ui->selftest_label_57, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_57, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_57_main_main_default
	static lv_style_t style_selftest_label_57_main_main_default;
	if (style_selftest_label_57_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_57_main_main_default);
	else
		lv_style_init(&style_selftest_label_57_main_main_default);
	lv_style_set_radius(&style_selftest_label_57_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_57_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_57_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_57_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_57_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_57_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_57_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_57_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_57_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_57_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_57_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_57_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_57, &style_selftest_label_57_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_16
	ui->selftest_btn_16 = lv_btn_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_btn_16, 386+ REVISE_X, -38+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_16, 86, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_16_main_main_default
	static lv_style_t style_selftest_btn_16_main_main_default;
	if (style_selftest_btn_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_16_main_main_default);
	else
		lv_style_init(&style_selftest_btn_16_main_main_default);
	lv_style_set_radius(&style_selftest_btn_16_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_16_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_16_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_16_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_16_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_16_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_16_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_16_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_16, &style_selftest_btn_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_16_label = lv_label_create(ui->selftest_btn_16);
	lv_label_set_text(ui->selftest_btn_16_label, "跳过");
	lv_obj_set_style_text_color(ui->selftest_btn_16_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_16_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_16, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_16_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_17
	ui->selftest_btn_17 = lv_btn_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_btn_17, 38+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_17, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_17_main_main_default
	static lv_style_t style_selftest_btn_17_main_main_default;
	if (style_selftest_btn_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_17_main_main_default);
	else
		lv_style_init(&style_selftest_btn_17_main_main_default);
	lv_style_set_radius(&style_selftest_btn_17_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_17_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_color(&style_selftest_btn_17_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_dir(&style_selftest_btn_17_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_17_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_17_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_17_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_17_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_17, &style_selftest_btn_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_17_label = lv_label_create(ui->selftest_btn_17);
	lv_label_set_text(ui->selftest_btn_17_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_17_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_17_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_17, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_17_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_18
	ui->selftest_btn_18 = lv_btn_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_btn_18, 300+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_18, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_18_main_main_default
	static lv_style_t style_selftest_btn_18_main_main_default;
	if (style_selftest_btn_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_18_main_main_default);
	else
		lv_style_init(&style_selftest_btn_18_main_main_default);
	lv_style_set_radius(&style_selftest_btn_18_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_18_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_18_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_18_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_18_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_18_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_18_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_18_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_18_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_18_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_18, &style_selftest_btn_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_18_label = lv_label_create(ui->selftest_btn_18);
	lv_label_set_text(ui->selftest_btn_18_label, "下一步");
	lv_obj_set_style_text_color(ui->selftest_btn_18_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_18_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_18, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_18_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_58
	ui->selftest_label_58 = lv_label_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_label_58, 30+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_58, 30, 24);
	lv_label_set_text(ui->selftest_label_58, "/7");
	lv_label_set_long_mode(ui->selftest_label_58, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_58, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_58_main_main_default
	static lv_style_t style_selftest_label_58_main_main_default;
	if (style_selftest_label_58_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_58_main_main_default);
	else
		lv_style_init(&style_selftest_label_58_main_main_default);
	lv_style_set_radius(&style_selftest_label_58_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_58_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_58_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_58_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_58_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_58_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_58_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_58_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_58_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_58_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_58_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_58_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_58, &style_selftest_label_58_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_59
	ui->selftest_label_59 = lv_label_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_label_59, 102+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_59, 280, 32);
	lv_label_set_text(ui->selftest_label_59, "轴移动检测");
	lv_label_set_long_mode(ui->selftest_label_59, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_59, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_59_main_main_default
	static lv_style_t style_selftest_label_59_main_main_default;
	if (style_selftest_label_59_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_59_main_main_default);
	else
		lv_style_init(&style_selftest_label_59_main_main_default);
	lv_style_set_radius(&style_selftest_label_59_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_59_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_59_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_59_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_59_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_59_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_59_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_59_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_59_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_59_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_59_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_59_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_59, &style_selftest_label_59_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_60
	ui->selftest_label_60 = lv_label_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_label_60, 17+ REVISE_X, 24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_60, 450, 235);
	lv_label_set_text(ui->selftest_label_60, "");
	lv_label_set_long_mode(ui->selftest_label_60, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_60, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_60_main_main_default
	static lv_style_t style_selftest_label_60_main_main_default;
	if (style_selftest_label_60_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_60_main_main_default);
	else
		lv_style_init(&style_selftest_label_60_main_main_default);
	lv_style_set_radius(&style_selftest_label_60_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_60_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_60_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_60_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_60_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_60_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_60_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_60_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_60_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_60_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_60_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_60, &style_selftest_label_60_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_16
	ui->selftest_img_16 = lv_img_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_img_16, 162+ REVISE_X, 57+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_16, 160, 138);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_16_main_main_default
	static lv_style_t style_selftest_img_16_main_main_default;
	if (style_selftest_img_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_16_main_main_default);
	else
		lv_style_init(&style_selftest_img_16_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_16_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_16_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_16, &style_selftest_img_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_16, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_16,&_gohome_160x138);
	lv_img_set_pivot(ui->selftest_img_16, 0,0);
	lv_img_set_angle(ui->selftest_img_16, 0);

	//Write codes selftest_label_61
	ui->selftest_label_61 = lv_label_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_label_61, 15+ REVISE_X, 271+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_61, 450, 352);
	lv_label_set_text(ui->selftest_label_61, "");
	lv_label_set_long_mode(ui->selftest_label_61, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_61, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_61_main_main_default
	static lv_style_t style_selftest_label_61_main_main_default;
	if (style_selftest_label_61_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_61_main_main_default);
	else
		lv_style_init(&style_selftest_label_61_main_main_default);
	lv_style_set_radius(&style_selftest_label_61_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_61_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_61_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_61_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_61_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_61_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_61_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_61_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_61_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_61_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_61_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_61, &style_selftest_label_61_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_62
	ui->selftest_label_62 = lv_label_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_label_62, 102+ REVISE_X, 209+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_62, 280, 24);
	lv_label_set_text(ui->selftest_label_62, "原点位置");
	lv_label_set_long_mode(ui->selftest_label_62, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_62, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_62_main_main_default
	static lv_style_t style_selftest_label_62_main_main_default;
	if (style_selftest_label_62_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_62_main_main_default);
	else
		lv_style_init(&style_selftest_label_62_main_main_default);
	lv_style_set_radius(&style_selftest_label_62_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_62_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_62_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_62_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_62_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_62_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_font(&style_selftest_label_62_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_62_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_62_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_62_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_62_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_62_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_62, &style_selftest_label_62_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_63
	ui->selftest_label_63 = lv_label_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_label_63, 37+ REVISE_X, 295+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_63, 410, 48);
	lv_label_set_text(ui->selftest_label_63, "5S后请观察设备XYZ轴是否回归到原点。");
	lv_label_set_long_mode(ui->selftest_label_63, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_63, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_63_main_main_default
	static lv_style_t style_selftest_label_63_main_main_default;
	if (style_selftest_label_63_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_63_main_main_default);
	else
		lv_style_init(&style_selftest_label_63_main_main_default);
	lv_style_set_radius(&style_selftest_label_63_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_63_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_63_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_63_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_63_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_63_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_63_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_63_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_63_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_63_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_63_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_63_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_63, &style_selftest_label_63_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_64
	ui->selftest_label_64 = lv_label_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_label_64, 37+ REVISE_X, 367+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_64, 410, 24);
	lv_label_set_text(ui->selftest_label_64, "1.正常回归请进行下一步；");
	lv_label_set_long_mode(ui->selftest_label_64, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_64, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_64_main_main_default
	static lv_style_t style_selftest_label_64_main_main_default;
	if (style_selftest_label_64_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_64_main_main_default);
	else
		lv_style_init(&style_selftest_label_64_main_main_default);
	lv_style_set_radius(&style_selftest_label_64_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_64_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_64_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_64_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_64_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_64_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_64_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_64_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_64_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_64_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_64_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_64_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_64, &style_selftest_label_64_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_65
	ui->selftest_label_65 = lv_label_create(ui->selftest_tabview_1_Title9);
	lv_obj_set_pos(ui->selftest_label_65, 37+ REVISE_X, 405+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_65, 410, 24);
	lv_label_set_text(ui->selftest_label_65, "2.如不正常请查看说明书或联系客服。");
	lv_label_set_long_mode(ui->selftest_label_65, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_65, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_65_main_main_default
	static lv_style_t style_selftest_label_65_main_main_default;
	if (style_selftest_label_65_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_65_main_main_default);
	else
		lv_style_init(&style_selftest_label_65_main_main_default);
	lv_style_set_radius(&style_selftest_label_65_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_65_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_65_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_65_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_65_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_65_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_65_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_65_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_65_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_65_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_65_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_65_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_65, &style_selftest_label_65_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_66
	ui->selftest_label_66 = lv_label_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_label_66, 18+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_66, 12, 24);
	lv_label_set_text(ui->selftest_label_66, "4");
	lv_label_set_long_mode(ui->selftest_label_66, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_66, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_66_main_main_default
	static lv_style_t style_selftest_label_66_main_main_default;
	if (style_selftest_label_66_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_66_main_main_default);
	else
		lv_style_init(&style_selftest_label_66_main_main_default);
	lv_style_set_radius(&style_selftest_label_66_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_66_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_66_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_66_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_66_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_66_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_66_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_66_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_66_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_66_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_66_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_66_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_66, &style_selftest_label_66_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_19
	ui->selftest_btn_19 = lv_btn_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_btn_19, 386+ REVISE_X, -38+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_19, 86, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_19_main_main_default
	static lv_style_t style_selftest_btn_19_main_main_default;
	if (style_selftest_btn_19_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_19_main_main_default);
	else
		lv_style_init(&style_selftest_btn_19_main_main_default);
	lv_style_set_radius(&style_selftest_btn_19_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_19_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_19_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_19_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_19_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_19_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_19_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_19_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_19_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_19_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_19, &style_selftest_btn_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_19_label = lv_label_create(ui->selftest_btn_19);
	lv_label_set_text(ui->selftest_btn_19_label, "跳过");
	lv_obj_set_style_text_color(ui->selftest_btn_19_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_19_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_19, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_19_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_20
	ui->selftest_btn_20 = lv_btn_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_btn_20, 38+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_20, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_20_main_main_default
	static lv_style_t style_selftest_btn_20_main_main_default;
	if (style_selftest_btn_20_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_20_main_main_default);
	else
		lv_style_init(&style_selftest_btn_20_main_main_default);
	lv_style_set_radius(&style_selftest_btn_20_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_20_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_20_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_20_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_20_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_20_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_20_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_20_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_20_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_20_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_20, &style_selftest_btn_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_20_label = lv_label_create(ui->selftest_btn_20);
	lv_label_set_text(ui->selftest_btn_20_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_20_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_20_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_20, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_20_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_21
	ui->selftest_btn_21 = lv_btn_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_btn_21, 300+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_21, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_21_main_main_default
	static lv_style_t style_selftest_btn_21_main_main_default;
	if (style_selftest_btn_21_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_21_main_main_default);
	else
		lv_style_init(&style_selftest_btn_21_main_main_default);
	lv_style_set_radius(&style_selftest_btn_21_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_21_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_21_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_21_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_21_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_21_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_21_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_21_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_21_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_21_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_21, &style_selftest_btn_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_21_label = lv_label_create(ui->selftest_btn_21);
	lv_label_set_text(ui->selftest_btn_21_label, "开始校准");
	lv_obj_set_style_text_color(ui->selftest_btn_21_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_21_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_21, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_21_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_67
	ui->selftest_label_67 = lv_label_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_label_67, 31+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_67, 30, 24);
	lv_label_set_text(ui->selftest_label_67, "/7");
	lv_label_set_long_mode(ui->selftest_label_67, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_67, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_67_main_main_default
	static lv_style_t style_selftest_label_67_main_main_default;
	if (style_selftest_label_67_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_67_main_main_default);
	else
		lv_style_init(&style_selftest_label_67_main_main_default);
	lv_style_set_radius(&style_selftest_label_67_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_67_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_67_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_67_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_67_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_67_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_67_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_67_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_67_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_67_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_67_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_67_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_67, &style_selftest_label_67_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_68
	ui->selftest_label_68 = lv_label_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_label_68, 102+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_68, 280, 32);
	lv_label_set_text(ui->selftest_label_68, "断料检测");
	lv_label_set_long_mode(ui->selftest_label_68, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_68, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_68_main_main_default
	static lv_style_t style_selftest_label_68_main_main_default;
	if (style_selftest_label_68_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_68_main_main_default);
	else
		lv_style_init(&style_selftest_label_68_main_main_default);
	lv_style_set_radius(&style_selftest_label_68_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_68_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_68_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_68_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_68_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_68_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_68_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_68_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_68_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_68_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_68_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_68_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_68, &style_selftest_label_68_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_69
	ui->selftest_label_69 = lv_label_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_label_69, 17+ REVISE_X, 24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_69, 450, 235);
	lv_label_set_text(ui->selftest_label_69, "");
	lv_label_set_long_mode(ui->selftest_label_69, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_69, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_69_main_main_default
	static lv_style_t style_selftest_label_69_main_main_default;
	if (style_selftest_label_69_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_69_main_main_default);
	else
		lv_style_init(&style_selftest_label_69_main_main_default);
	lv_style_set_radius(&style_selftest_label_69_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_69_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_69_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_69_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_69_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_69_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_69_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_69_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_69_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_69_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_69_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_69, &style_selftest_label_69_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_17
	ui->selftest_img_17 = lv_img_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_img_17, 151+ REVISE_X, 24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_17, 182, 231);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_17_main_main_default
	static lv_style_t style_selftest_img_17_main_main_default;
	if (style_selftest_img_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_17_main_main_default);
	else
		lv_style_init(&style_selftest_img_17_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_17_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_17_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_17_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_17, &style_selftest_img_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_17, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_17,&_sensor_182x231);
	lv_img_set_pivot(ui->selftest_img_17, 0,0);
	lv_img_set_angle(ui->selftest_img_17, 0);

	//Write codes selftest_label_70
	ui->selftest_label_70 = lv_label_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_label_70, 17+ REVISE_X, 271+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_70, 452, 352);
	lv_label_set_text(ui->selftest_label_70, "");
	lv_label_set_long_mode(ui->selftest_label_70, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_70, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_70_main_main_default
	static lv_style_t style_selftest_label_70_main_main_default;
	if (style_selftest_label_70_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_70_main_main_default);
	else
		lv_style_init(&style_selftest_label_70_main_main_default);
	lv_style_set_radius(&style_selftest_label_70_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_70_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_70_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_70_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_70_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_70_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_70_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_70_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_70_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_70_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_70_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_70, &style_selftest_label_70_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_71
	ui->selftest_label_71 = lv_label_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_label_71, 37+ REVISE_X, 295+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_71, 410, 24);
	lv_label_set_text(ui->selftest_label_71, "请在如图所示位置插入耗材");
	lv_label_set_long_mode(ui->selftest_label_71, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_71, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_71_main_main_default
	static lv_style_t style_selftest_label_71_main_main_default;
	if (style_selftest_label_71_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_71_main_main_default);
	else
		lv_style_init(&style_selftest_label_71_main_main_default);
	lv_style_set_radius(&style_selftest_label_71_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_71_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_71_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_71_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_71_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_71_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_71_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_71_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_71_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_71_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_71_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_71_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_71, &style_selftest_label_71_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_72
	ui->selftest_label_72 = lv_label_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_label_72, 37+ REVISE_X, 335+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_72, 410, 24);
	lv_label_set_text(ui->selftest_label_72, "1.找到位置后便可开始检测；");
	lv_label_set_long_mode(ui->selftest_label_72, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_72, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_72_main_main_default
	static lv_style_t style_selftest_label_72_main_main_default;
	if (style_selftest_label_72_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_72_main_main_default);
	else
		lv_style_init(&style_selftest_label_72_main_main_default);
	lv_style_set_radius(&style_selftest_label_72_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_72_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_72_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_72_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_72_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_72_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_72_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_72_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_72_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_72_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_72_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_72_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_72, &style_selftest_label_72_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_73
	ui->selftest_label_73 = lv_label_create(ui->selftest_tabview_1_Title10);
	lv_obj_set_pos(ui->selftest_label_73, 37+ REVISE_X, 373+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_73, 410, 24);
	lv_label_set_text(ui->selftest_label_73, "2.如不正常请查看说明书或联系客服。");
	lv_label_set_long_mode(ui->selftest_label_73, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_73, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_73_main_main_default
	static lv_style_t style_selftest_label_73_main_main_default;
	if (style_selftest_label_73_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_73_main_main_default);
	else
		lv_style_init(&style_selftest_label_73_main_main_default);
	lv_style_set_radius(&style_selftest_label_73_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_73_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_73_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_73_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_73_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_73_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_73_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_73_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_73_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_73_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_73_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_73_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_73, &style_selftest_label_73_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_74
	ui->selftest_label_74 = lv_label_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_label_74, 16+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_74, 12, 24);
	lv_label_set_text(ui->selftest_label_74, "5");
	lv_label_set_long_mode(ui->selftest_label_74, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_74, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_74_main_main_default
	static lv_style_t style_selftest_label_74_main_main_default;
	if (style_selftest_label_74_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_74_main_main_default);
	else
		lv_style_init(&style_selftest_label_74_main_main_default);
	lv_style_set_radius(&style_selftest_label_74_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_74_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_74_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_74_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_74_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_74_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_74_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_74_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_74_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_74_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_74_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_74_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_74, &style_selftest_label_74_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_22
	ui->selftest_btn_22 = lv_btn_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_btn_22, 36+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_22, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_22_main_main_default
	static lv_style_t style_selftest_btn_22_main_main_default;
	if (style_selftest_btn_22_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_22_main_main_default);
	else
		lv_style_init(&style_selftest_btn_22_main_main_default);
	lv_style_set_radius(&style_selftest_btn_22_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_22_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_color(&style_selftest_btn_22_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_dir(&style_selftest_btn_22_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_22_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_22_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_22_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_22_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_22_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_22_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_22, &style_selftest_btn_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_22_label = lv_label_create(ui->selftest_btn_22);
	lv_label_set_text(ui->selftest_btn_22_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_22_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_22_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_22, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_22_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_23
	ui->selftest_btn_23 = lv_btn_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_btn_23, 298+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_23, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_23_main_main_default
	static lv_style_t style_selftest_btn_23_main_main_default;
	if (style_selftest_btn_23_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_23_main_main_default);
	else
		lv_style_init(&style_selftest_btn_23_main_main_default);
	lv_style_set_radius(&style_selftest_btn_23_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_23_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_23_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_23_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_23_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_23_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_23_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_23_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_23_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_23_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_23, &style_selftest_btn_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_23_label = lv_label_create(ui->selftest_btn_23);
	lv_label_set_text(ui->selftest_btn_23_label, "下一步");
	lv_obj_set_style_text_color(ui->selftest_btn_23_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_23_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_23, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_23_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_75
	ui->selftest_label_75 = lv_label_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_label_75, 28+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_75, 24, 20);
	lv_label_set_text(ui->selftest_label_75, "/7");
	lv_label_set_long_mode(ui->selftest_label_75, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_75, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_75_main_main_default
	static lv_style_t style_selftest_label_75_main_main_default;
	if (style_selftest_label_75_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_75_main_main_default);
	else
		lv_style_init(&style_selftest_label_75_main_main_default);
	lv_style_set_radius(&style_selftest_label_75_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_75_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_75_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_75_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_75_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_75_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_75_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_75_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_75_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_75_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_75_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_75_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_75, &style_selftest_label_75_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_76
	ui->selftest_label_76 = lv_label_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_label_76, 100+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_76, 280, 32);
	lv_label_set_text(ui->selftest_label_76, "手动调平");
	lv_label_set_long_mode(ui->selftest_label_76, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_76, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_76_main_main_default
	static lv_style_t style_selftest_label_76_main_main_default;
	if (style_selftest_label_76_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_76_main_main_default);
	else
		lv_style_init(&style_selftest_label_76_main_main_default);
	lv_style_set_radius(&style_selftest_label_76_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_76_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_76_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_76_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_76_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_76_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_76_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_76_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_76_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_76_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_76_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_76_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_76, &style_selftest_label_76_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_77
	ui->selftest_label_77 = lv_label_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_label_77, 15+ REVISE_X, 24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_77, 450, 235);
	lv_label_set_text(ui->selftest_label_77, "");
	lv_label_set_long_mode(ui->selftest_label_77, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_77, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_77_main_main_default
	static lv_style_t style_selftest_label_77_main_main_default;
	if (style_selftest_label_77_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_77_main_main_default);
	else
		lv_style_init(&style_selftest_label_77_main_main_default);
	lv_style_set_radius(&style_selftest_label_77_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_77_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_77_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_77_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_77_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_77_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_77_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_77_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_77_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_77_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_77_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_77, &style_selftest_label_77_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_78
	ui->selftest_label_78 = lv_label_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_label_78, 15+ REVISE_X, 271+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_78, 450, 352);
	lv_label_set_text(ui->selftest_label_78, "");
	lv_label_set_long_mode(ui->selftest_label_78, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_78, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_78_main_main_default
	static lv_style_t style_selftest_label_78_main_main_default;
	if (style_selftest_label_78_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_78_main_main_default);
	else
		lv_style_init(&style_selftest_label_78_main_main_default);
	lv_style_set_radius(&style_selftest_label_78_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_78_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_78_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_78_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_78_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_78_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_78_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_78_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_78_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_78_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_78_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_78, &style_selftest_label_78_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_18
	ui->selftest_img_18 = lv_img_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_img_18, 117+ REVISE_X, 37+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_18, 247, 163);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_18_main_main_default
	static lv_style_t style_selftest_img_18_main_main_default;
	if (style_selftest_img_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_18_main_main_default);
	else
		lv_style_init(&style_selftest_img_18_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_18_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_18_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_18_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_18, &style_selftest_img_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_18, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_18,&_level_247x163);
	lv_img_set_pivot(ui->selftest_img_18, 0,0);
	lv_img_set_angle(ui->selftest_img_18, 0);

	//Write codes selftest_btn_72
	ui->selftest_btn_72 = lv_btn_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_btn_72, 122+ REVISE_X, 87+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_72, 74, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_72_main_main_default
	static lv_style_t style_selftest_btn_72_main_main_default;
	if (style_selftest_btn_72_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_72_main_main_default);
	else
		lv_style_init(&style_selftest_btn_72_main_main_default);
	lv_style_set_radius(&style_selftest_btn_72_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_72_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_btn_72_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_btn_72_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_72_main_main_default, 0);
	lv_style_set_shadow_color(&style_selftest_btn_72_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_72_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_72_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_72_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_72_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_72, &style_selftest_btn_72_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_72_label = lv_label_create(ui->selftest_btn_72);
	lv_label_set_text(ui->selftest_btn_72_label, "");
	lv_obj_set_style_text_color(ui->selftest_btn_72_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_72, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_72_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_73
	ui->selftest_btn_73 = lv_btn_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_btn_73, 283+ REVISE_X, 85+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_73, 73, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_73_main_main_default
	static lv_style_t style_selftest_btn_73_main_main_default;
	if (style_selftest_btn_73_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_73_main_main_default);
	else
		lv_style_init(&style_selftest_btn_73_main_main_default);
	lv_style_set_radius(&style_selftest_btn_73_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_73_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_btn_73_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_btn_73_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_73_main_main_default, 0);
	lv_style_set_shadow_color(&style_selftest_btn_73_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_73_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_73_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_73_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_73_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_73, &style_selftest_btn_73_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_73_label = lv_label_create(ui->selftest_btn_73);
	lv_label_set_text(ui->selftest_btn_73_label, "");
	lv_obj_set_style_text_color(ui->selftest_btn_73_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_73, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_73_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_74
	ui->selftest_btn_74 = lv_btn_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_btn_74, 270+ REVISE_X, 31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_74, 73, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_74_main_main_default
	static lv_style_t style_selftest_btn_74_main_main_default;
	if (style_selftest_btn_74_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_74_main_main_default);
	else
		lv_style_init(&style_selftest_btn_74_main_main_default);
	lv_style_set_radius(&style_selftest_btn_74_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_74_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_btn_74_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_btn_74_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_74_main_main_default, 0);
	lv_style_set_shadow_color(&style_selftest_btn_74_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_74_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_74_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_74_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_74_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_74, &style_selftest_btn_74_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_74_label = lv_label_create(ui->selftest_btn_74);
	lv_label_set_text(ui->selftest_btn_74_label, "");
	lv_obj_set_style_text_color(ui->selftest_btn_74_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_74, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_74_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_75
	ui->selftest_btn_75 = lv_btn_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_btn_75, 138+ REVISE_X, 29+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_75, 62, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_75_main_main_default
	static lv_style_t style_selftest_btn_75_main_main_default;
	if (style_selftest_btn_75_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_75_main_main_default);
	else
		lv_style_init(&style_selftest_btn_75_main_main_default);
	lv_style_set_radius(&style_selftest_btn_75_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_75_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_btn_75_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_btn_75_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_75_main_main_default, 0);
	lv_style_set_shadow_color(&style_selftest_btn_75_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_75_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_75_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_75_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_75_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_75, &style_selftest_btn_75_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_75_label = lv_label_create(ui->selftest_btn_75);
	lv_label_set_text(ui->selftest_btn_75_label, "");
	lv_obj_set_style_text_color(ui->selftest_btn_75_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_75, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_75_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_79
	ui->selftest_label_79 = lv_label_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_label_79, 35+ REVISE_X, 295+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_79, 410, 28);
	lv_label_set_text(ui->selftest_label_79, "请在如图所示位置进行操作");
	lv_label_set_long_mode(ui->selftest_label_79, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_79, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_79_main_main_default
	static lv_style_t style_selftest_label_79_main_main_default;
	if (style_selftest_label_79_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_79_main_main_default);
	else
		lv_style_init(&style_selftest_label_79_main_main_default);
	lv_style_set_radius(&style_selftest_label_79_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_79_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_79_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_79_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_79_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_79_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_79_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_79_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_79_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_79_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_79_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_79_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_79, &style_selftest_label_79_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_80
	ui->selftest_label_80 = lv_label_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_label_80, 35+ REVISE_X, 335+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_80, 410, 24);
	lv_label_set_text(ui->selftest_label_80, "1.请保证热床和喷头表面的清洁;");
	lv_label_set_long_mode(ui->selftest_label_80, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_80, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_80_main_main_default
	static lv_style_t style_selftest_label_80_main_main_default;
	if (style_selftest_label_80_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_80_main_main_default);
	else
		lv_style_init(&style_selftest_label_80_main_main_default);
	lv_style_set_radius(&style_selftest_label_80_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_80_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_80_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_80_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_80_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_80_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_80_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_80_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_80_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_80_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_80_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_80_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_80, &style_selftest_label_80_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_81
	ui->selftest_label_81 = lv_label_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_label_81, 35+ REVISE_X, 373+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_81, 410, 24);
	lv_label_set_text(ui->selftest_label_81, "2.请点击左图中数字进行喷头定位;");
	lv_label_set_long_mode(ui->selftest_label_81, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_81, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_81_main_main_default
	static lv_style_t style_selftest_label_81_main_main_default;
	if (style_selftest_label_81_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_81_main_main_default);
	else
		lv_style_init(&style_selftest_label_81_main_main_default);
	lv_style_set_radius(&style_selftest_label_81_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_81_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_81_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_81_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_81_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_81_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_81_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_81_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_81_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_81_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_81_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_81_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_81, &style_selftest_label_81_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_82
	ui->selftest_label_82 = lv_label_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_label_82, 35+ REVISE_X, 411+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_82, 410, 24);
	lv_label_set_text(ui->selftest_label_82, "3.等待喷头移动到相应位置;");
	lv_label_set_long_mode(ui->selftest_label_82, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_82, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_82_main_main_default
	static lv_style_t style_selftest_label_82_main_main_default;
	if (style_selftest_label_82_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_82_main_main_default);
	else
		lv_style_init(&style_selftest_label_82_main_main_default);
	lv_style_set_radius(&style_selftest_label_82_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_82_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_82_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_82_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_82_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_82_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_82_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_82_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_82_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_82_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_82_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_82_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_82, &style_selftest_label_82_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_83
	ui->selftest_label_83 = lv_label_create(ui->selftest_tabview_1_Title11);
	lv_obj_set_pos(ui->selftest_label_83, 35+ REVISE_X, 449+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_83, 410, 24);
	lv_label_set_text(ui->selftest_label_83, "4.调整调平按钮。");
	lv_label_set_long_mode(ui->selftest_label_83, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_83, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_83_main_main_default
	static lv_style_t style_selftest_label_83_main_main_default;
	if (style_selftest_label_83_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_83_main_main_default);
	else
		lv_style_init(&style_selftest_label_83_main_main_default);
	lv_style_set_radius(&style_selftest_label_83_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_83_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_83_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_83_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_83_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_83_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_83_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_83_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_83_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_83_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_83_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_83_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_83, &style_selftest_label_83_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_84
	ui->selftest_label_84 = lv_label_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_label_84, 15+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_84, 12, 24);
	lv_label_set_text(ui->selftest_label_84, "6");
	lv_label_set_long_mode(ui->selftest_label_84, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_84, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_84_main_main_default
	static lv_style_t style_selftest_label_84_main_main_default;
	if (style_selftest_label_84_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_84_main_main_default);
	else
		lv_style_init(&style_selftest_label_84_main_main_default);
	lv_style_set_radius(&style_selftest_label_84_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_84_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_84_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_84_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_84_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_84_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_84_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_84_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_84_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_84_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_84_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_84_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_84, &style_selftest_label_84_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_19
	ui->selftest_img_19 = lv_img_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_img_19, 15+ REVISE_X, 26+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_19, 44, 44);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_19_main_main_default
	static lv_style_t style_selftest_img_19_main_main_default;
	if (style_selftest_img_19_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_19_main_main_default);
	else
		lv_style_init(&style_selftest_img_19_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_19_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_19_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_19_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_19, &style_selftest_img_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_19, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_19,&_exchange_44x44);
	lv_img_set_pivot(ui->selftest_img_19, 0,0);
	lv_img_set_angle(ui->selftest_img_19, 0);

	//Write codes selftest_btn_24
	ui->selftest_btn_24 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_24, 384+ REVISE_X, -38+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_24, 86, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_24_main_main_default
	static lv_style_t style_selftest_btn_24_main_main_default;
	if (style_selftest_btn_24_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_24_main_main_default);
	else
		lv_style_init(&style_selftest_btn_24_main_main_default);
	lv_style_set_radius(&style_selftest_btn_24_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_24_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_24_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_24_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_24_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_24_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_24_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_24_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_24_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_24_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_24, &style_selftest_btn_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_24_label = lv_label_create(ui->selftest_btn_24);
	lv_label_set_text(ui->selftest_btn_24_label, "跳过");
	lv_obj_set_style_text_color(ui->selftest_btn_24_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_24_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_24, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_24_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_25
	ui->selftest_btn_25 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_25, 76+ REVISE_X, 26+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_25, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_25_main_main_default
	static lv_style_t style_selftest_btn_25_main_main_default;
	if (style_selftest_btn_25_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_25_main_main_default);
	else
		lv_style_init(&style_selftest_btn_25_main_main_default);
	lv_style_set_radius(&style_selftest_btn_25_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_25_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_25_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_25_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_25_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_25_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_25_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_25_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_25_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_25_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_25, &style_selftest_btn_25_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_25_label = lv_label_create(ui->selftest_btn_25);
	lv_label_set_text(ui->selftest_btn_25_label, "21");
	lv_obj_set_style_text_color(ui->selftest_btn_25_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_25_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_25, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_25_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_30
	ui->selftest_btn_30 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_30, 76+ REVISE_X, 91+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_30, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_30_main_main_default
	static lv_style_t style_selftest_btn_30_main_main_default;
	if (style_selftest_btn_30_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_30_main_main_default);
	else
		lv_style_init(&style_selftest_btn_30_main_main_default);
	lv_style_set_radius(&style_selftest_btn_30_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_30_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_30_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_30_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_30_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_30_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_30_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_30_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_30_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_30_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_30, &style_selftest_btn_30_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_30_label = lv_label_create(ui->selftest_btn_30);
	lv_label_set_text(ui->selftest_btn_30_label, "20");
	lv_obj_set_style_text_color(ui->selftest_btn_30_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_30_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_30, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_30_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_31
	ui->selftest_btn_31 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_31, 141+ REVISE_X, 91+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_31, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_31_main_main_default
	static lv_style_t style_selftest_btn_31_main_main_default;
	if (style_selftest_btn_31_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_31_main_main_default);
	else
		lv_style_init(&style_selftest_btn_31_main_main_default);
	lv_style_set_radius(&style_selftest_btn_31_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_31_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_31_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_31_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_31_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_31_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_31_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_31_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_31_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_31_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_31, &style_selftest_btn_31_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_31_label = lv_label_create(ui->selftest_btn_31);
	lv_label_set_text(ui->selftest_btn_31_label, "19");
	lv_obj_set_style_text_color(ui->selftest_btn_31_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_31_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_31, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_31_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_32
	ui->selftest_btn_32 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_32, 206+ REVISE_X, 91+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_32, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_32_main_main_default
	static lv_style_t style_selftest_btn_32_main_main_default;
	if (style_selftest_btn_32_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_32_main_main_default);
	else
		lv_style_init(&style_selftest_btn_32_main_main_default);
	lv_style_set_radius(&style_selftest_btn_32_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_32_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_32_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_32_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_32_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_32_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_32_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_32_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_32_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_32_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_32, &style_selftest_btn_32_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_32_label = lv_label_create(ui->selftest_btn_32);
	lv_label_set_text(ui->selftest_btn_32_label, "18");
	lv_obj_set_style_text_color(ui->selftest_btn_32_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_32_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_32, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_32_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_33
	ui->selftest_btn_33 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_33, 271+ REVISE_X, 91+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_33, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_33_main_main_default
	static lv_style_t style_selftest_btn_33_main_main_default;
	if (style_selftest_btn_33_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_33_main_main_default);
	else
		lv_style_init(&style_selftest_btn_33_main_main_default);
	lv_style_set_radius(&style_selftest_btn_33_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_33_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_33_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_33_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_33_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_33_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_33_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_33_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_33_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_33_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_33, &style_selftest_btn_33_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_33_label = lv_label_create(ui->selftest_btn_33);
	lv_label_set_text(ui->selftest_btn_33_label, "17");
	lv_obj_set_style_text_color(ui->selftest_btn_33_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_33_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_33, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_33_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_34
	ui->selftest_btn_34 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_34, 336+ REVISE_X, 91+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_34, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_34_main_main_default
	static lv_style_t style_selftest_btn_34_main_main_default;
	if (style_selftest_btn_34_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_34_main_main_default);
	else
		lv_style_init(&style_selftest_btn_34_main_main_default);
	lv_style_set_radius(&style_selftest_btn_34_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_34_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_34_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_34_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_34_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_34_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_34_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_34_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_34_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_34_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_34, &style_selftest_btn_34_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_34_label = lv_label_create(ui->selftest_btn_34);
	lv_label_set_text(ui->selftest_btn_34_label, "16");
	lv_obj_set_style_text_color(ui->selftest_btn_34_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_34_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_34, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_34_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_35
	ui->selftest_btn_35 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_35, 76+ REVISE_X, 156+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_35, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_35_main_main_default
	static lv_style_t style_selftest_btn_35_main_main_default;
	if (style_selftest_btn_35_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_35_main_main_default);
	else
		lv_style_init(&style_selftest_btn_35_main_main_default);
	lv_style_set_radius(&style_selftest_btn_35_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_35_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_35_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_35_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_35_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_35_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_35_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_35_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_35_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_35_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_35, &style_selftest_btn_35_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_35_label = lv_label_create(ui->selftest_btn_35);
	lv_label_set_text(ui->selftest_btn_35_label, "11");
	lv_obj_set_style_text_color(ui->selftest_btn_35_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_35_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_35, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_35_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_36
	ui->selftest_btn_36 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_36, 141+ REVISE_X, 156+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_36, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_36_main_main_default
	static lv_style_t style_selftest_btn_36_main_main_default;
	if (style_selftest_btn_36_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_36_main_main_default);
	else
		lv_style_init(&style_selftest_btn_36_main_main_default);
	lv_style_set_radius(&style_selftest_btn_36_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_36_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_36_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_36_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_36_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_36_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_36_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_36_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_36_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_36_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_36, &style_selftest_btn_36_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_36_label = lv_label_create(ui->selftest_btn_36);
	lv_label_set_text(ui->selftest_btn_36_label, "12");
	lv_obj_set_style_text_color(ui->selftest_btn_36_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_36_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_36, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_36_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_37
	ui->selftest_btn_37 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_37, 206+ REVISE_X, 156+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_37, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_37_main_main_default
	static lv_style_t style_selftest_btn_37_main_main_default;
	if (style_selftest_btn_37_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_37_main_main_default);
	else
		lv_style_init(&style_selftest_btn_37_main_main_default);
	lv_style_set_radius(&style_selftest_btn_37_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_37_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_37_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_37_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_37_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_37_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_37_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_37_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_37_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_37_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_37, &style_selftest_btn_37_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_37_label = lv_label_create(ui->selftest_btn_37);
	lv_label_set_text(ui->selftest_btn_37_label, "13");
	lv_obj_set_style_text_color(ui->selftest_btn_37_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_37_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_37, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_37_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_38
	ui->selftest_btn_38 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_38, 271+ REVISE_X, 156+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_38, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_38_main_main_default
	static lv_style_t style_selftest_btn_38_main_main_default;
	if (style_selftest_btn_38_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_38_main_main_default);
	else
		lv_style_init(&style_selftest_btn_38_main_main_default);
	lv_style_set_radius(&style_selftest_btn_38_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_38_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_38_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_38_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_38_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_38_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_38_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_38_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_38_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_38_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_38, &style_selftest_btn_38_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_38_label = lv_label_create(ui->selftest_btn_38);
	lv_label_set_text(ui->selftest_btn_38_label, "14");
	lv_obj_set_style_text_color(ui->selftest_btn_38_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_38_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_38, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_38_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_39
	ui->selftest_btn_39 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_39, 336+ REVISE_X, 156+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_39, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_39_main_main_default
	static lv_style_t style_selftest_btn_39_main_main_default;
	if (style_selftest_btn_39_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_39_main_main_default);
	else
		lv_style_init(&style_selftest_btn_39_main_main_default);
	lv_style_set_radius(&style_selftest_btn_39_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_39_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_39_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_39_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_39_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_39_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_39_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_39_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_39_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_39_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_39, &style_selftest_btn_39_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_39_label = lv_label_create(ui->selftest_btn_39);
	lv_label_set_text(ui->selftest_btn_39_label, "15");
	lv_obj_set_style_text_color(ui->selftest_btn_39_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_39_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_39, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_39_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_40
	ui->selftest_btn_40 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_40, 76+ REVISE_X, 221+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_40, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_40_main_main_default
	static lv_style_t style_selftest_btn_40_main_main_default;
	if (style_selftest_btn_40_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_40_main_main_default);
	else
		lv_style_init(&style_selftest_btn_40_main_main_default);
	lv_style_set_radius(&style_selftest_btn_40_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_40_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_40_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_40_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_40_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_40_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_40_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_40_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_40_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_40_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_40, &style_selftest_btn_40_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_40_label = lv_label_create(ui->selftest_btn_40);
	lv_label_set_text(ui->selftest_btn_40_label, "10");
	lv_obj_set_style_text_color(ui->selftest_btn_40_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_40_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_40, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_40_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_41
	ui->selftest_btn_41 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_41, 141+ REVISE_X, 221+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_41, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_41_main_main_default
	static lv_style_t style_selftest_btn_41_main_main_default;
	if (style_selftest_btn_41_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_41_main_main_default);
	else
		lv_style_init(&style_selftest_btn_41_main_main_default);
	lv_style_set_radius(&style_selftest_btn_41_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_41_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_41_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_41_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_41_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_41_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_41_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_41_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_41_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_41_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_41, &style_selftest_btn_41_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_41_label = lv_label_create(ui->selftest_btn_41);
	lv_label_set_text(ui->selftest_btn_41_label, "9");
	lv_obj_set_style_text_color(ui->selftest_btn_41_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_41_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_41, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_41_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_42
	ui->selftest_btn_42 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_42, 206+ REVISE_X, 221+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_42, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_42_main_main_default
	static lv_style_t style_selftest_btn_42_main_main_default;
	if (style_selftest_btn_42_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_42_main_main_default);
	else
		lv_style_init(&style_selftest_btn_42_main_main_default);
	lv_style_set_radius(&style_selftest_btn_42_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_42_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_42_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_42_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_42_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_42_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_42_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_42_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_42_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_42_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_42, &style_selftest_btn_42_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_42_label = lv_label_create(ui->selftest_btn_42);
	lv_label_set_text(ui->selftest_btn_42_label, "8");
	lv_obj_set_style_text_color(ui->selftest_btn_42_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_42_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_42, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_42_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_43
	ui->selftest_btn_43 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_43, 271+ REVISE_X, 221+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_43, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_43_main_main_default
	static lv_style_t style_selftest_btn_43_main_main_default;
	if (style_selftest_btn_43_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_43_main_main_default);
	else
		lv_style_init(&style_selftest_btn_43_main_main_default);
	lv_style_set_radius(&style_selftest_btn_43_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_43_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_43_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_43_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_43_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_43_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_43_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_43_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_43_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_43_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_43, &style_selftest_btn_43_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_43_label = lv_label_create(ui->selftest_btn_43);
	lv_label_set_text(ui->selftest_btn_43_label, "7");
	lv_obj_set_style_text_color(ui->selftest_btn_43_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_43_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_43, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_43_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_44
	ui->selftest_btn_44 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_44, 336+ REVISE_X, 221+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_44, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_44_main_main_default
	static lv_style_t style_selftest_btn_44_main_main_default;
	if (style_selftest_btn_44_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_44_main_main_default);
	else
		lv_style_init(&style_selftest_btn_44_main_main_default);
	lv_style_set_radius(&style_selftest_btn_44_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_44_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_44_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_44_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_44_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_44_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_44_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_44_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_44_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_44_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_44, &style_selftest_btn_44_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_44_label = lv_label_create(ui->selftest_btn_44);
	lv_label_set_text(ui->selftest_btn_44_label, "6");
	lv_obj_set_style_text_color(ui->selftest_btn_44_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_44_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_44, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_44_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_45
	ui->selftest_btn_45 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_45, 76+ REVISE_X, 286+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_45, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_45_main_main_default
	static lv_style_t style_selftest_btn_45_main_main_default;
	if (style_selftest_btn_45_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_45_main_main_default);
	else
		lv_style_init(&style_selftest_btn_45_main_main_default);
	lv_style_set_radius(&style_selftest_btn_45_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_45_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_45_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_45_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_45_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_45_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_45_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_45_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_45_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_45_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_45, &style_selftest_btn_45_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_45_label = lv_label_create(ui->selftest_btn_45);
	lv_label_set_text(ui->selftest_btn_45_label, "1");
	lv_obj_set_style_text_color(ui->selftest_btn_45_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_45_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_45, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_45_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_46
	ui->selftest_btn_46 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_46, 141+ REVISE_X, 286+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_46, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_46_main_main_default
	static lv_style_t style_selftest_btn_46_main_main_default;
	if (style_selftest_btn_46_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_46_main_main_default);
	else
		lv_style_init(&style_selftest_btn_46_main_main_default);
	lv_style_set_radius(&style_selftest_btn_46_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_46_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_46_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_46_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_46_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_46_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_46_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_46_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_46_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_46_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_46, &style_selftest_btn_46_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_46_label = lv_label_create(ui->selftest_btn_46);
	lv_label_set_text(ui->selftest_btn_46_label, "2");
	lv_obj_set_style_text_color(ui->selftest_btn_46_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_46_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_46, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_46_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_47
	ui->selftest_btn_47 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_47, 206+ REVISE_X, 286+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_47, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_47_main_main_default
	static lv_style_t style_selftest_btn_47_main_main_default;
	if (style_selftest_btn_47_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_47_main_main_default);
	else
		lv_style_init(&style_selftest_btn_47_main_main_default);
	lv_style_set_radius(&style_selftest_btn_47_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_47_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_47_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_47_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_47_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_47_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_47_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_47_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_47_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_47_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_47, &style_selftest_btn_47_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_47_label = lv_label_create(ui->selftest_btn_47);
	lv_label_set_text(ui->selftest_btn_47_label, "3");
	lv_obj_set_style_text_color(ui->selftest_btn_47_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_47_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_47, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_47_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_48
	ui->selftest_btn_48 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_48, 271+ REVISE_X, 286+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_48, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_48_main_main_default
	static lv_style_t style_selftest_btn_48_main_main_default;
	if (style_selftest_btn_48_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_48_main_main_default);
	else
		lv_style_init(&style_selftest_btn_48_main_main_default);
	lv_style_set_radius(&style_selftest_btn_48_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_48_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_48_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_48_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_48_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_48_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_48_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_48_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_48_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_48_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_48, &style_selftest_btn_48_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_48_label = lv_label_create(ui->selftest_btn_48);
	lv_label_set_text(ui->selftest_btn_48_label, "4");
	lv_obj_set_style_text_color(ui->selftest_btn_48_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_48_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_48, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_48_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_49
	ui->selftest_btn_49 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_49, 336+ REVISE_X, 286+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_49, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_49_main_main_default
	static lv_style_t style_selftest_btn_49_main_main_default;
	if (style_selftest_btn_49_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_49_main_main_default);
	else
		lv_style_init(&style_selftest_btn_49_main_main_default);
	lv_style_set_radius(&style_selftest_btn_49_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_49_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_49_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_49_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_49_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_49_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_49_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_49_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_49_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_49_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_49, &style_selftest_btn_49_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_49_label = lv_label_create(ui->selftest_btn_49);
	lv_label_set_text(ui->selftest_btn_49_label, "5");
	lv_obj_set_style_text_color(ui->selftest_btn_49_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_49_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_49, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_49_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_26
	ui->selftest_btn_26 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_26, 141+ REVISE_X, 26+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_26, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_26_main_main_default
	static lv_style_t style_selftest_btn_26_main_main_default;
	if (style_selftest_btn_26_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_26_main_main_default);
	else
		lv_style_init(&style_selftest_btn_26_main_main_default);
	lv_style_set_radius(&style_selftest_btn_26_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_26_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_26_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_26_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_26_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_26_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_26_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_26_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_26_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_26_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_26, &style_selftest_btn_26_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_26_label = lv_label_create(ui->selftest_btn_26);
	lv_label_set_text(ui->selftest_btn_26_label, "22");
	lv_obj_set_style_text_color(ui->selftest_btn_26_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_26_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_26, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_26_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_27
	ui->selftest_btn_27 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_27, 206+ REVISE_X, 26+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_27, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_27_main_main_default
	static lv_style_t style_selftest_btn_27_main_main_default;
	if (style_selftest_btn_27_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_27_main_main_default);
	else
		lv_style_init(&style_selftest_btn_27_main_main_default);
	lv_style_set_radius(&style_selftest_btn_27_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_27_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_27_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_27_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_27_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_27_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_27_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_27_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_27_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_27_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_27, &style_selftest_btn_27_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_27_label = lv_label_create(ui->selftest_btn_27);
	lv_label_set_text(ui->selftest_btn_27_label, "23");
	lv_obj_set_style_text_color(ui->selftest_btn_27_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_27_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_27, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_27_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_28
	ui->selftest_btn_28 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_28, 271+ REVISE_X, 26+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_28, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_28_main_main_default
	static lv_style_t style_selftest_btn_28_main_main_default;
	if (style_selftest_btn_28_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_28_main_main_default);
	else
		lv_style_init(&style_selftest_btn_28_main_main_default);
	lv_style_set_radius(&style_selftest_btn_28_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_28_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_28_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_28_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_28_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_28_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_28_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_28_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_28_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_28_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_28, &style_selftest_btn_28_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_28_label = lv_label_create(ui->selftest_btn_28);
	lv_label_set_text(ui->selftest_btn_28_label, "24");
	lv_obj_set_style_text_color(ui->selftest_btn_28_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_28_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_28, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_28_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_29
	ui->selftest_btn_29 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_29, 336+ REVISE_X, 26+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_29, 66, 66);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_29_main_main_default
	static lv_style_t style_selftest_btn_29_main_main_default;
	if (style_selftest_btn_29_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_29_main_main_default);
	else
		lv_style_init(&style_selftest_btn_29_main_main_default);
	lv_style_set_radius(&style_selftest_btn_29_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_btn_29_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_color(&style_selftest_btn_29_main_main_default, lv_color_make(0x14, 0x14, 0x14));
	lv_style_set_bg_grad_dir(&style_selftest_btn_29_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_29_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_29_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_29_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_29_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_border_width(&style_selftest_btn_29_main_main_default, 1);
	lv_style_set_border_opa(&style_selftest_btn_29_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_29, &style_selftest_btn_29_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_29_label = lv_label_create(ui->selftest_btn_29);
	lv_label_set_text(ui->selftest_btn_29_label, "25");
	lv_obj_set_style_text_color(ui->selftest_btn_29_label, lv_color_make(0x83, 0x86, 0x8b), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_29_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_29, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_29_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_85
	ui->selftest_label_85 = lv_label_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_label_85, 28+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_85, 30, 24);
	lv_label_set_text(ui->selftest_label_85, "/7");
	lv_label_set_long_mode(ui->selftest_label_85, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_85, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_85_main_main_default
	static lv_style_t style_selftest_label_85_main_main_default;
	if (style_selftest_label_85_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_85_main_main_default);
	else
		lv_style_init(&style_selftest_label_85_main_main_default);
	lv_style_set_radius(&style_selftest_label_85_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_85_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_85_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_85_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_85_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_85_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_85_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_85_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_85_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_85_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_85_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_85_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_85, &style_selftest_label_85_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_86
	ui->selftest_label_86 = lv_label_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_label_86, 100+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_86, 280, 32);
	lv_label_set_text(ui->selftest_label_86, "自动调平");
	lv_label_set_long_mode(ui->selftest_label_86, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_86, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_86_main_main_default
	static lv_style_t style_selftest_label_86_main_main_default;
	if (style_selftest_label_86_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_86_main_main_default);
	else
		lv_style_init(&style_selftest_label_86_main_main_default);
	lv_style_set_radius(&style_selftest_label_86_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_86_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_86_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_86_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_86_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_86_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_86_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_86_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_86_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_86_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_86_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_86_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_86, &style_selftest_label_86_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_87
	ui->selftest_label_87 = lv_label_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_label_87, 15+ REVISE_X, 366+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_87, 450, 261);
	lv_label_set_text(ui->selftest_label_87, "");
	lv_label_set_long_mode(ui->selftest_label_87, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_87, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_87_main_main_default
	static lv_style_t style_selftest_label_87_main_main_default;
	if (style_selftest_label_87_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_87_main_main_default);
	else
		lv_style_init(&style_selftest_label_87_main_main_default);
	lv_style_set_radius(&style_selftest_label_87_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_87_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_87_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_87_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_87_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_87_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_87_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_87_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_87_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_87_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_87_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_87, &style_selftest_label_87_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_50
	ui->selftest_btn_50 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_50, 167+ REVISE_X, 553+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_50, 146, 60);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_50_main_main_default
	static lv_style_t style_selftest_btn_50_main_main_default;
	if (style_selftest_btn_50_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_50_main_main_default);
	else
		lv_style_init(&style_selftest_btn_50_main_main_default);
	lv_style_set_radius(&style_selftest_btn_50_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_50_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_50_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_50_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_50_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_50_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_50_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_50_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_50_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_50_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_50, &style_selftest_btn_50_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_50_label = lv_label_create(ui->selftest_btn_50);
	lv_label_set_text(ui->selftest_btn_50_label, "开始调平");
	lv_obj_set_style_text_color(ui->selftest_btn_50_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_50_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_50, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_50_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_51
	ui->selftest_btn_51 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_51, 36+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_51, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_51_main_main_default
	static lv_style_t style_selftest_btn_51_main_main_default;
	if (style_selftest_btn_51_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_51_main_main_default);
	else
		lv_style_init(&style_selftest_btn_51_main_main_default);
	lv_style_set_radius(&style_selftest_btn_51_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_51_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_color(&style_selftest_btn_51_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_dir(&style_selftest_btn_51_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_51_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_51_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_51_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_51_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_51_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_51_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_51, &style_selftest_btn_51_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_51_label = lv_label_create(ui->selftest_btn_51);
	lv_label_set_text(ui->selftest_btn_51_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_51_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_51_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_51, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_51_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_52
	ui->selftest_btn_52 = lv_btn_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_btn_52, 298+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_52, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_52_main_main_default
	static lv_style_t style_selftest_btn_52_main_main_default;
	if (style_selftest_btn_52_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_52_main_main_default);
	else
		lv_style_init(&style_selftest_btn_52_main_main_default);
	lv_style_set_radius(&style_selftest_btn_52_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_52_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_52_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_52_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_52_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_52_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_52_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_52_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_52_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_52_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_52, &style_selftest_btn_52_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_52_label = lv_label_create(ui->selftest_btn_52);
	lv_label_set_text(ui->selftest_btn_52_label, "下一步");
	lv_obj_set_style_text_color(ui->selftest_btn_52_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_52_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_52, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_52_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_88
	ui->selftest_label_88 = lv_label_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_label_88, 35+ REVISE_X, 390+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_88, 410, 28);
	lv_label_set_text(ui->selftest_label_88, "请开始自动调平");
	lv_label_set_long_mode(ui->selftest_label_88, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_88, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_88_main_main_default
	static lv_style_t style_selftest_label_88_main_main_default;
	if (style_selftest_label_88_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_88_main_main_default);
	else
		lv_style_init(&style_selftest_label_88_main_main_default);
	lv_style_set_radius(&style_selftest_label_88_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_88_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_88_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_88_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_88_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_88_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_88_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_88_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_88_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_88_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_88_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_88_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_88, &style_selftest_label_88_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_89
	ui->selftest_label_89 = lv_label_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_label_89, 35+ REVISE_X, 430+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_89, 410, 24);
	lv_label_set_text(ui->selftest_label_89, "1.请保证热床和喷嘴表面的清洁;");
	lv_label_set_long_mode(ui->selftest_label_89, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_89, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_89_main_main_default
	static lv_style_t style_selftest_label_89_main_main_default;
	if (style_selftest_label_89_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_89_main_main_default);
	else
		lv_style_init(&style_selftest_label_89_main_main_default);
	lv_style_set_radius(&style_selftest_label_89_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_89_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_89_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_89_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_89_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_89_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_89_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_89_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_89_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_89_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_89_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_89_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_89, &style_selftest_label_89_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_90
	ui->selftest_label_90 = lv_label_create(ui->selftest_tabview_1_Title12);
	lv_obj_set_pos(ui->selftest_label_90, 35+ REVISE_X, 468+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_90, 410, 24);
	lv_label_set_text(ui->selftest_label_90, "2.调平过程预计需要5分钟左右。");
	lv_label_set_long_mode(ui->selftest_label_90, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_90, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_90_main_main_default
	static lv_style_t style_selftest_label_90_main_main_default;
	if (style_selftest_label_90_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_90_main_main_default);
	else
		lv_style_init(&style_selftest_label_90_main_main_default);
	lv_style_set_radius(&style_selftest_label_90_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_90_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_90_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_90_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_90_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_90_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_90_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_90_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_90_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_90_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_90_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_90_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_90, &style_selftest_label_90_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_91
	ui->selftest_label_91 = lv_label_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_label_91, 15+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_91, 12, 24);
	lv_label_set_text(ui->selftest_label_91, "7");
	lv_label_set_long_mode(ui->selftest_label_91, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_91, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_91_main_main_default
	static lv_style_t style_selftest_label_91_main_main_default;
	if (style_selftest_label_91_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_91_main_main_default);
	else
		lv_style_init(&style_selftest_label_91_main_main_default);
	lv_style_set_radius(&style_selftest_label_91_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_91_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_91_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_91_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_91_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_91_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_91_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_91_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_91_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_91_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_91_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_91_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_91, &style_selftest_label_91_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_53
	ui->selftest_btn_53 = lv_btn_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_btn_53, 384+ REVISE_X, -38+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_53, 86, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_53_main_main_default
	static lv_style_t style_selftest_btn_53_main_main_default;
	if (style_selftest_btn_53_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_53_main_main_default);
	else
		lv_style_init(&style_selftest_btn_53_main_main_default);
	lv_style_set_radius(&style_selftest_btn_53_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_53_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_53_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_53_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_53_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_53_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_53_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_53_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_53_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_53_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_53, &style_selftest_btn_53_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_53_label = lv_label_create(ui->selftest_btn_53);
	lv_label_set_text(ui->selftest_btn_53_label, "跳过");
	lv_obj_set_style_text_color(ui->selftest_btn_53_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_53_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_53, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_53_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_54
	ui->selftest_btn_54 = lv_btn_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_btn_54, 36+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_54, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_54_main_main_default
	static lv_style_t style_selftest_btn_54_main_main_default;
	if (style_selftest_btn_54_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_54_main_main_default);
	else
		lv_style_init(&style_selftest_btn_54_main_main_default);
	lv_style_set_radius(&style_selftest_btn_54_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_54_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_color(&style_selftest_btn_54_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_dir(&style_selftest_btn_54_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_54_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_54_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_54_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_54_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_54_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_54_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_54, &style_selftest_btn_54_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_54_label = lv_label_create(ui->selftest_btn_54);
	lv_label_set_text(ui->selftest_btn_54_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_54_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_54_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_54, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_54_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_55
	ui->selftest_btn_55 = lv_btn_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_btn_55, 298+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_55, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_55_main_main_default
	static lv_style_t style_selftest_btn_55_main_main_default;
	if (style_selftest_btn_55_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_55_main_main_default);
	else
		lv_style_init(&style_selftest_btn_55_main_main_default);
	lv_style_set_radius(&style_selftest_btn_55_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_55_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_55_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_55_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_55_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_55_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_55_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_55_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_55_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_55_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_55, &style_selftest_btn_55_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_55_label = lv_label_create(ui->selftest_btn_55);
	lv_label_set_text(ui->selftest_btn_55_label, "开始自检");
	lv_obj_set_style_text_color(ui->selftest_btn_55_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_55_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_55, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_55_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_92
	ui->selftest_label_92 = lv_label_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_label_92, 28+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_92, 30, 24);
	lv_label_set_text(ui->selftest_label_92, "/7");
	lv_label_set_long_mode(ui->selftest_label_92, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_92, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_92_main_main_default
	static lv_style_t style_selftest_label_92_main_main_default;
	if (style_selftest_label_92_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_92_main_main_default);
	else
		lv_style_init(&style_selftest_label_92_main_main_default);
	lv_style_set_radius(&style_selftest_label_92_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_92_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_92_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_92_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_92_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_92_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_92_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_92_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_92_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_92_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_92_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_92_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_92, &style_selftest_label_92_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_93
	ui->selftest_label_93 = lv_label_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_label_93, 100+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_93, 280, 32);
	lv_label_set_text(ui->selftest_label_93, "振纹优化");
	lv_label_set_long_mode(ui->selftest_label_93, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_93, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_93_main_main_default
	static lv_style_t style_selftest_label_93_main_main_default;
	if (style_selftest_label_93_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_93_main_main_default);
	else
		lv_style_init(&style_selftest_label_93_main_main_default);
	lv_style_set_radius(&style_selftest_label_93_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_93_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_93_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_93_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_93_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_93_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_93_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_93_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_93_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_93_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_93_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_93_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_93, &style_selftest_label_93_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_94
	ui->selftest_label_94 = lv_label_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_label_94, 15+ REVISE_X, 24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_94, 450, 235);
	lv_label_set_text(ui->selftest_label_94, "");
	lv_label_set_long_mode(ui->selftest_label_94, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_94, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_94_main_main_default
	static lv_style_t style_selftest_label_94_main_main_default;
	if (style_selftest_label_94_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_94_main_main_default);
	else
		lv_style_init(&style_selftest_label_94_main_main_default);
	lv_style_set_radius(&style_selftest_label_94_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_94_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_94_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_94_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_94_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_94_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_94_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_94_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_94_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_94_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_94_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_94, &style_selftest_label_94_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_96
	ui->selftest_label_96 = lv_label_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_label_96, 15+ REVISE_X, 271+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_96, 450, 352);
	lv_label_set_text(ui->selftest_label_96, "");
	lv_label_set_long_mode(ui->selftest_label_96, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_96, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_96_main_main_default
	static lv_style_t style_selftest_label_96_main_main_default;
	if (style_selftest_label_96_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_96_main_main_default);
	else
		lv_style_init(&style_selftest_label_96_main_main_default);
	lv_style_set_radius(&style_selftest_label_96_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_96_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_96_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_96_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_96_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_96_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_96_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_96_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_96_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_96_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_96_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_96, &style_selftest_label_96_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_97
	ui->selftest_label_97 = lv_label_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_label_97, 35+ REVISE_X, 295+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_97, 410, 28);
	lv_label_set_text(ui->selftest_label_97, "传感器状态正常!");
	lv_label_set_long_mode(ui->selftest_label_97, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_97, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_97_main_main_default
	static lv_style_t style_selftest_label_97_main_main_default;
	if (style_selftest_label_97_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_97_main_main_default);
	else
		lv_style_init(&style_selftest_label_97_main_main_default);
	lv_style_set_radius(&style_selftest_label_97_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_97_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_97_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_97_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_97_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_97_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_97_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_97_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_97_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_97_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_97_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_97_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_97, &style_selftest_label_97_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_98
	ui->selftest_label_98 = lv_label_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_label_98, 35+ REVISE_X, 335+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_98, 420, 24);
	lv_label_set_text(ui->selftest_label_98, "1.振动补偿可以更好使打印机发挥性能;");
	lv_label_set_long_mode(ui->selftest_label_98, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_98, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_98_main_main_default
	static lv_style_t style_selftest_label_98_main_main_default;
	if (style_selftest_label_98_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_98_main_main_default);
	else
		lv_style_init(&style_selftest_label_98_main_main_default);
	lv_style_set_radius(&style_selftest_label_98_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_98_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_98_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_98_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_98_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_98_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_98_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_98_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_98_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_98_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_98_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_98_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_98, &style_selftest_label_98_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_99
	ui->selftest_label_99 = lv_label_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_label_99, 35+ REVISE_X, 373+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_99, 410, 24);
	lv_label_set_text(ui->selftest_label_99, "2.整个过程预计需要5分钟。");
	lv_label_set_long_mode(ui->selftest_label_99, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_99, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_99_main_main_default
	static lv_style_t style_selftest_label_99_main_main_default;
	if (style_selftest_label_99_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_99_main_main_default);
	else
		lv_style_init(&style_selftest_label_99_main_main_default);
	lv_style_set_radius(&style_selftest_label_99_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_99_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_99_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_99_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_99_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_99_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_99_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_99_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_99_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_99_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_99_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_99_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_99, &style_selftest_label_99_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_95
	ui->selftest_label_95 = lv_label_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_label_95, 100+ REVISE_X, 209+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_95, 280, 24);
	lv_label_set_text(ui->selftest_label_95, "检测中请勿触碰打印机");
	lv_label_set_long_mode(ui->selftest_label_95, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_95, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_95_main_main_default
	static lv_style_t style_selftest_label_95_main_main_default;
	if (style_selftest_label_95_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_95_main_main_default);
	else
		lv_style_init(&style_selftest_label_95_main_main_default);
	lv_style_set_radius(&style_selftest_label_95_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_95_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_95_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_95_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_95_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_95_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_text_font(&style_selftest_label_95_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_95_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_95_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_95_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_95_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_95_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_95, &style_selftest_label_95_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_20
	ui->selftest_img_20 = lv_img_create(ui->selftest_tabview_1_Title13);
	lv_obj_set_pos(ui->selftest_img_20, 173+ REVISE_X, 56+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_20, 163, 133);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_20_main_main_default
	static lv_style_t style_selftest_img_20_main_main_default;
	if (style_selftest_img_20_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_20_main_main_default);
	else
		lv_style_init(&style_selftest_img_20_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_20_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_20_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_20_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_20, &style_selftest_img_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_20, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_20,&_Group_1580_163x133);
	lv_img_set_pivot(ui->selftest_img_20, 0,0);
	lv_img_set_angle(ui->selftest_img_20, 0);

	//Write codes selftest_label_100
	ui->selftest_label_100 = lv_label_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_label_100, 100+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_100, 280, 32);
	lv_label_set_text(ui->selftest_label_100, "检测结果");
	lv_label_set_long_mode(ui->selftest_label_100, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_100, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_100_main_main_default
	static lv_style_t style_selftest_label_100_main_main_default;
	if (style_selftest_label_100_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_100_main_main_default);
	else
		lv_style_init(&style_selftest_label_100_main_main_default);
	lv_style_set_radius(&style_selftest_label_100_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_100_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_100_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_100_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_100_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_100_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_100_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_100_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_100_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_100_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_100_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_100_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_100, &style_selftest_label_100_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_56
	ui->selftest_btn_56 = lv_btn_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_btn_56, 36+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_56, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_56_main_main_default
	static lv_style_t style_selftest_btn_56_main_main_default;
	if (style_selftest_btn_56_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_56_main_main_default);
	else
		lv_style_init(&style_selftest_btn_56_main_main_default);
	lv_style_set_radius(&style_selftest_btn_56_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_56_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_color(&style_selftest_btn_56_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_dir(&style_selftest_btn_56_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_56_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_56_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_56_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_56_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_56_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_56_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_56, &style_selftest_btn_56_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_56_label = lv_label_create(ui->selftest_btn_56);
	lv_label_set_text(ui->selftest_btn_56_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_56_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_56_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_56, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_56_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_57
	ui->selftest_btn_57 = lv_btn_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_btn_57, 298+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_57, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_57_main_main_default
	static lv_style_t style_selftest_btn_57_main_main_default;
	if (style_selftest_btn_57_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_57_main_main_default);
	else
		lv_style_init(&style_selftest_btn_57_main_main_default);
	lv_style_set_radius(&style_selftest_btn_57_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_57_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_57_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_57_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_57_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_57_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_57_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_57_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_57_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_57_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_57, &style_selftest_btn_57_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_57_label = lv_label_create(ui->selftest_btn_57);
	lv_label_set_text(ui->selftest_btn_57_label, "完成");
	lv_obj_set_style_text_color(ui->selftest_btn_57_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_57_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_57, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_57_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_101
	ui->selftest_label_101 = lv_label_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_label_101, 12+ REVISE_X, 23+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_101, 450, 603);
	lv_label_set_text(ui->selftest_label_101, "");
	lv_label_set_long_mode(ui->selftest_label_101, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_101, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_101_main_main_default
	static lv_style_t style_selftest_label_101_main_main_default;
	if (style_selftest_label_101_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_101_main_main_default);
	else
		lv_style_init(&style_selftest_label_101_main_main_default);
	lv_style_set_radius(&style_selftest_label_101_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_101_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_101_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_101_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_101_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_101_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_101_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_101_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_101_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_101_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_101_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_101, &style_selftest_label_101_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_21
	ui->selftest_img_21 = lv_img_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_img_21, 428+ REVISE_X, 43+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_21, 26, 26);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_21_main_main_default
	static lv_style_t style_selftest_img_21_main_main_default;
	if (style_selftest_img_21_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_21_main_main_default);
	else
		lv_style_init(&style_selftest_img_21_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_21_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_21_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_21_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_21, &style_selftest_img_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_21, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_21,&_teststate1_26x26);
	lv_img_set_pivot(ui->selftest_img_21, 0,0);
	lv_img_set_angle(ui->selftest_img_21, 0);

	//Write codes selftest_img_22
	ui->selftest_img_22 = lv_img_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_img_22, 428+ REVISE_X, 111+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_22, 26, 26);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_22_main_main_default
	static lv_style_t style_selftest_img_22_main_main_default;
	if (style_selftest_img_22_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_22_main_main_default);
	else
		lv_style_init(&style_selftest_img_22_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_22_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_22_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_22_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_22, &style_selftest_img_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_22, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_22,&_teststate2_26x26);
	lv_img_set_pivot(ui->selftest_img_22, 0,0);
	lv_img_set_angle(ui->selftest_img_22, 0);

	//Write codes selftest_img_23
	ui->selftest_img_23 = lv_img_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_img_23, 428+ REVISE_X, 179+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_23, 26, 26);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_23_main_main_default
	static lv_style_t style_selftest_img_23_main_main_default;
	if (style_selftest_img_23_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_23_main_main_default);
	else
		lv_style_init(&style_selftest_img_23_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_23_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_23_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_23_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_23, &style_selftest_img_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_23, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_23,&_teststate3_26x26);
	lv_img_set_pivot(ui->selftest_img_23, 0,0);
	lv_img_set_angle(ui->selftest_img_23, 0);

	//Write codes selftest_img_24
	ui->selftest_img_24 = lv_img_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_img_24, 428+ REVISE_X, 247+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_24, 26, 26);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_24_main_main_default
	static lv_style_t style_selftest_img_24_main_main_default;
	if (style_selftest_img_24_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_24_main_main_default);
	else
		lv_style_init(&style_selftest_img_24_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_24_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_24_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_24_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_24, &style_selftest_img_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_24, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_24,&_teststate1_26x26);
	lv_img_set_pivot(ui->selftest_img_24, 0,0);
	lv_img_set_angle(ui->selftest_img_24, 0);

	//Write codes selftest_img_25
	ui->selftest_img_25 = lv_img_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_img_25, 428+ REVISE_X, 315+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_25, 26, 26);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_25_main_main_default
	static lv_style_t style_selftest_img_25_main_main_default;
	if (style_selftest_img_25_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_25_main_main_default);
	else
		lv_style_init(&style_selftest_img_25_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_25_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_25_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_25_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_25, &style_selftest_img_25_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_25, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_25,&_teststate1_26x26);
	lv_img_set_pivot(ui->selftest_img_25, 0,0);
	lv_img_set_angle(ui->selftest_img_25, 0);

	//Write codes selftest_img_26
	ui->selftest_img_26 = lv_img_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_img_26, 428+ REVISE_X, 383+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_26, 26, 26);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_26_main_main_default
	static lv_style_t style_selftest_img_26_main_main_default;
	if (style_selftest_img_26_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_26_main_main_default);
	else
		lv_style_init(&style_selftest_img_26_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_26_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_26_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_26_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_26, &style_selftest_img_26_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_26, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_26,&_teststate1_26x26);
	lv_img_set_pivot(ui->selftest_img_26, 0,0);
	lv_img_set_angle(ui->selftest_img_26, 0);

	//Write codes selftest_img_27
	ui->selftest_img_27 = lv_img_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_img_27, 428+ REVISE_X, 451+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_27, 26, 26);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_27_main_main_default
	static lv_style_t style_selftest_img_27_main_main_default;
	if (style_selftest_img_27_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_27_main_main_default);
	else
		lv_style_init(&style_selftest_img_27_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_27_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_27_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_27_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_27, &style_selftest_img_27_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_27, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_27,&_teststate1_26x26);
	lv_img_set_pivot(ui->selftest_img_27, 0,0);
	lv_img_set_angle(ui->selftest_img_27, 0);

	//Write codes selftest_label_102
	ui->selftest_label_102 = lv_label_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_label_102, 30+ REVISE_X, 43+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_102, 300, 24);
	lv_label_set_text(ui->selftest_label_102, "喉管散热风扇检测");
	lv_label_set_long_mode(ui->selftest_label_102, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_102, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_102_main_main_default
	static lv_style_t style_selftest_label_102_main_main_default;
	if (style_selftest_label_102_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_102_main_main_default);
	else
		lv_style_init(&style_selftest_label_102_main_main_default);
	lv_style_set_radius(&style_selftest_label_102_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_102_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_102_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_102_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_102_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_102_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_102_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_102_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_102_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_102_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_102_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_102_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_102, &style_selftest_label_102_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_103
	ui->selftest_label_103 = lv_label_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_label_103, 30+ REVISE_X, 111+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_103, 300, 24);
	lv_label_set_text(ui->selftest_label_103, "模型冷却风扇检测");
	lv_label_set_long_mode(ui->selftest_label_103, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_103, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_103_main_main_default
	static lv_style_t style_selftest_label_103_main_main_default;
	if (style_selftest_label_103_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_103_main_main_default);
	else
		lv_style_init(&style_selftest_label_103_main_main_default);
	lv_style_set_radius(&style_selftest_label_103_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_103_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_103_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_103_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_103_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_103_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_103_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_103_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_103_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_103_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_103_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_103_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_103, &style_selftest_label_103_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_104
	ui->selftest_label_104 = lv_label_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_label_104, 30+ REVISE_X, 179+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_104, 300, 24);
	lv_label_set_text(ui->selftest_label_104, "归位测试");
	lv_label_set_long_mode(ui->selftest_label_104, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_104, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_104_main_main_default
	static lv_style_t style_selftest_label_104_main_main_default;
	if (style_selftest_label_104_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_104_main_main_default);
	else
		lv_style_init(&style_selftest_label_104_main_main_default);
	lv_style_set_radius(&style_selftest_label_104_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_104_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_104_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_104_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_104_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_104_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_104_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_104_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_104_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_104_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_104_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_104_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_104, &style_selftest_label_104_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_105
	ui->selftest_label_105 = lv_label_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_label_105, 30+ REVISE_X, 247+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_105, 300, 24);
	lv_label_set_text(ui->selftest_label_105, "断料检测");
	lv_label_set_long_mode(ui->selftest_label_105, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_105, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_105_main_main_default
	static lv_style_t style_selftest_label_105_main_main_default;
	if (style_selftest_label_105_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_105_main_main_default);
	else
		lv_style_init(&style_selftest_label_105_main_main_default);
	lv_style_set_radius(&style_selftest_label_105_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_105_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_105_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_105_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_105_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_105_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_105_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_105_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_105_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_105_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_105_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_105_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_105, &style_selftest_label_105_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_106
	ui->selftest_label_106 = lv_label_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_label_106, 30+ REVISE_X, 315+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_106, 300, 24);
	lv_label_set_text(ui->selftest_label_106, "手动调平");
	lv_label_set_long_mode(ui->selftest_label_106, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_106, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_106_main_main_default
	static lv_style_t style_selftest_label_106_main_main_default;
	if (style_selftest_label_106_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_106_main_main_default);
	else
		lv_style_init(&style_selftest_label_106_main_main_default);
	lv_style_set_radius(&style_selftest_label_106_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_106_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_106_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_106_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_106_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_106_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_106_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_106_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_106_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_106_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_106_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_106_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_106, &style_selftest_label_106_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_107
	ui->selftest_label_107 = lv_label_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_label_107, 30+ REVISE_X, 383+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_107, 300, 24);
	lv_label_set_text(ui->selftest_label_107, "自动调平");
	lv_label_set_long_mode(ui->selftest_label_107, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_107, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_107_main_main_default
	static lv_style_t style_selftest_label_107_main_main_default;
	if (style_selftest_label_107_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_107_main_main_default);
	else
		lv_style_init(&style_selftest_label_107_main_main_default);
	lv_style_set_radius(&style_selftest_label_107_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_107_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_107_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_107_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_107_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_107_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_107_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_107_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_107_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_107_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_107_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_107_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_107, &style_selftest_label_107_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_108
	ui->selftest_label_108 = lv_label_create(ui->selftest_tabview_1_Title14);
	lv_obj_set_pos(ui->selftest_label_108, 30+ REVISE_X, 451+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_108, 300, 24);
	lv_label_set_text(ui->selftest_label_108, "振动补偿");
	lv_label_set_long_mode(ui->selftest_label_108, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_108, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_108_main_main_default
	static lv_style_t style_selftest_label_108_main_main_default;
	if (style_selftest_label_108_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_108_main_main_default);
	else
		lv_style_init(&style_selftest_label_108_main_main_default);
	lv_style_set_radius(&style_selftest_label_108_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_108_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_108_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_108_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_108_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_108_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_108_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_108_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_108_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_108_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_108_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_108_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_108, &style_selftest_label_108_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_109
	ui->selftest_label_109 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_109, 15+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_109, 12, 24);
	lv_label_set_text(ui->selftest_label_109, "1");
	lv_label_set_long_mode(ui->selftest_label_109, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_109, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_109_main_main_default
	static lv_style_t style_selftest_label_109_main_main_default;
	if (style_selftest_label_109_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_109_main_main_default);
	else
		lv_style_init(&style_selftest_label_109_main_main_default);
	lv_style_set_radius(&style_selftest_label_109_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_109_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_109_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_109_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_109_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_109_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_109_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_109_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_109_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_109_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_109_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_109_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_109, &style_selftest_label_109_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_58
	ui->selftest_btn_58 = lv_btn_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_btn_58, 36+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_58, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_58_main_main_default
	static lv_style_t style_selftest_btn_58_main_main_default;
	if (style_selftest_btn_58_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_58_main_main_default);
	else
		lv_style_init(&style_selftest_btn_58_main_main_default);
	lv_style_set_radius(&style_selftest_btn_58_main_main_default, 5);
	lv_style_set_bg_color(&style_selftest_btn_58_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_color(&style_selftest_btn_58_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_dir(&style_selftest_btn_58_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_58_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_58_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_58_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_58_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_58_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_58_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_58, &style_selftest_btn_58_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_58_label = lv_label_create(ui->selftest_btn_58);
	lv_label_set_text(ui->selftest_btn_58_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_58_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_58_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_58, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_58_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_59
	ui->selftest_btn_59 = lv_btn_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_btn_59, 296+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_59, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_59_main_main_default
	static lv_style_t style_selftest_btn_59_main_main_default;
	if (style_selftest_btn_59_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_59_main_main_default);
	else
		lv_style_init(&style_selftest_btn_59_main_main_default);
	lv_style_set_radius(&style_selftest_btn_59_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_59_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_59_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_59_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_59_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_59_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_59_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_59_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_59_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_59_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_59, &style_selftest_btn_59_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_59_label = lv_label_create(ui->selftest_btn_59);
	lv_label_set_text(ui->selftest_btn_59_label, "开始校准");
	lv_obj_set_style_text_color(ui->selftest_btn_59_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_59_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_59, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_59_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_110
	ui->selftest_label_110 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_110, 28+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_110, 30, 24);
	lv_label_set_text(ui->selftest_label_110, "/3");
	lv_label_set_long_mode(ui->selftest_label_110, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_110, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_110_main_main_default
	static lv_style_t style_selftest_label_110_main_main_default;
	if (style_selftest_label_110_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_110_main_main_default);
	else
		lv_style_init(&style_selftest_label_110_main_main_default);
	lv_style_set_radius(&style_selftest_label_110_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_110_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_110_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_110_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_110_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_110_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_110_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_110_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_110_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_110_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_110_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_110_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_110, &style_selftest_label_110_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_111
	ui->selftest_label_111 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_111, 100+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_111, 280, 32);
	lv_label_set_text(ui->selftest_label_111, "喷头PID校准");
	lv_label_set_long_mode(ui->selftest_label_111, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_111, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_111_main_main_default
	static lv_style_t style_selftest_label_111_main_main_default;
	if (style_selftest_label_111_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_111_main_main_default);
	else
		lv_style_init(&style_selftest_label_111_main_main_default);
	lv_style_set_radius(&style_selftest_label_111_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_111_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_111_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_111_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_111_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_111_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_111_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_111_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_111_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_111_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_111_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_111_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_111, &style_selftest_label_111_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_112
	ui->selftest_label_112 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_112, 15+ REVISE_X, 24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_112, 450, 235);
	lv_label_set_text(ui->selftest_label_112, "");
	lv_label_set_long_mode(ui->selftest_label_112, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_112, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_112_main_main_default
	static lv_style_t style_selftest_label_112_main_main_default;
	if (style_selftest_label_112_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_112_main_main_default);
	else
		lv_style_init(&style_selftest_label_112_main_main_default);
	lv_style_set_radius(&style_selftest_label_112_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_112_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_112_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_112_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_112_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_112_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_112_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_112_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_112_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_112_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_112_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_112, &style_selftest_label_112_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_114
	ui->selftest_label_114 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_114, 15+ REVISE_X, 271+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_114, 450, 352);
	lv_label_set_text(ui->selftest_label_114, "");
	lv_label_set_long_mode(ui->selftest_label_114, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_114, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_114_main_main_default
	static lv_style_t style_selftest_label_114_main_main_default;
	if (style_selftest_label_114_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_114_main_main_default);
	else
		lv_style_init(&style_selftest_label_114_main_main_default);
	lv_style_set_radius(&style_selftest_label_114_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_114_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_114_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_114_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_114_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_114_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_letter_space(&style_selftest_label_114_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_114_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_114_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_114_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_114_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_114, &style_selftest_label_114_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_115
	ui->selftest_label_115 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_115, 35+ REVISE_X, 295+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_115, 410, 28);
	lv_label_set_text(ui->selftest_label_115, "请进行喷头PID检测及校准");
	lv_label_set_long_mode(ui->selftest_label_115, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_115, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_115_main_main_default
	static lv_style_t style_selftest_label_115_main_main_default;
	if (style_selftest_label_115_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_115_main_main_default);
	else
		lv_style_init(&style_selftest_label_115_main_main_default);
	lv_style_set_radius(&style_selftest_label_115_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_115_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_115_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_115_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_115_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_115_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_115_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_115_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_115_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_115_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_115_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_115_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_115, &style_selftest_label_115_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_116
	ui->selftest_label_116 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_116, 35+ REVISE_X, 335+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_116, 410, 28);
	lv_label_set_text(ui->selftest_label_116, "1.预计需要5分钟左右；");
	lv_label_set_long_mode(ui->selftest_label_116, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_116, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_116_main_main_default
	static lv_style_t style_selftest_label_116_main_main_default;
	if (style_selftest_label_116_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_116_main_main_default);
	else
		lv_style_init(&style_selftest_label_116_main_main_default);
	lv_style_set_radius(&style_selftest_label_116_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_116_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_116_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_116_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_116_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_116_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_116_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_116_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_116_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_116_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_116_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_116_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_116, &style_selftest_label_116_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_117
	ui->selftest_label_117 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_117, 35+ REVISE_X, 373+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_117, 410, 28);
	lv_label_set_text(ui->selftest_label_117, "2.如不正常请查看说明书或联系客服。");
	lv_label_set_long_mode(ui->selftest_label_117, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_117, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_117_main_main_default
	static lv_style_t style_selftest_label_117_main_main_default;
	if (style_selftest_label_117_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_117_main_main_default);
	else
		lv_style_init(&style_selftest_label_117_main_main_default);
	lv_style_set_radius(&style_selftest_label_117_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_117_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_117_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_117_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_117_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_117_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_117_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_117_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_117_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_117_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_117_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_117_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_117, &style_selftest_label_117_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_113
	ui->selftest_label_113 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_113, 193+ REVISE_X, 164+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_113, 70, 28);
	lv_label_set_text(ui->selftest_label_113, "205℃");
	lv_label_set_long_mode(ui->selftest_label_113, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_113, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_113_main_main_default
	static lv_style_t style_selftest_label_113_main_main_default;
	if (style_selftest_label_113_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_113_main_main_default);
	else
		lv_style_init(&style_selftest_label_113_main_main_default);
	lv_style_set_radius(&style_selftest_label_113_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_113_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_113_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_113_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_113_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_113_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_113_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_113_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_113_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_113_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_113_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_113_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_113, &style_selftest_label_113_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_118
	ui->selftest_label_118 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_118, 149+ REVISE_X, 164+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_118, 70, 28);
	lv_label_set_text(ui->selftest_label_118, "");//205℃
	lv_label_set_long_mode(ui->selftest_label_118, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_118, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_118_main_main_default
	static lv_style_t style_selftest_label_118_main_main_default;
	if (style_selftest_label_118_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_118_main_main_default);
	else
		lv_style_init(&style_selftest_label_118_main_main_default);
	lv_style_set_radius(&style_selftest_label_118_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_118_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_118_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_118_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_118_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_118_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_118_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_118_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_118_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_118_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_118_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_118_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_118, &style_selftest_label_118_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_119
	ui->selftest_label_119 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_119, 266+ REVISE_X, 164+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_119, 70, 28);
	lv_label_set_text(ui->selftest_label_119, "");
	lv_label_set_long_mode(ui->selftest_label_119, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_119, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_119_main_main_default
	static lv_style_t style_selftest_label_119_main_main_default;
	if (style_selftest_label_119_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_119_main_main_default);
	else
		lv_style_init(&style_selftest_label_119_main_main_default);
	lv_style_set_radius(&style_selftest_label_119_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_119_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_119_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_119_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_119_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_119_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_119_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_119_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_119_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_119_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_119_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_119_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_119, &style_selftest_label_119_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_120
	ui->selftest_label_120 = lv_label_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_label_120, 193+ REVISE_X, 204+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_120, 93, 1);
	lv_label_set_text(ui->selftest_label_120, "");
	lv_label_set_long_mode(ui->selftest_label_120, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_120, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_120_main_main_default
	static lv_style_t style_selftest_label_120_main_main_default;
	if (style_selftest_label_120_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_120_main_main_default);
	else
		lv_style_init(&style_selftest_label_120_main_main_default);
	lv_style_set_radius(&style_selftest_label_120_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_120_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_selftest_label_120_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_selftest_label_120_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_120_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_120_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_120_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_120_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_120_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_120_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_120_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_120, &style_selftest_label_120_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_28
	ui->selftest_img_28 = lv_img_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_img_28, 211+ REVISE_X, 82+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_28, 62, 72);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_28_main_main_default
	static lv_style_t style_selftest_img_28_main_main_default;
	if (style_selftest_img_28_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_28_main_main_default);
	else
		lv_style_init(&style_selftest_img_28_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_28_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_28_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_28_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_28, &style_selftest_img_28_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_28, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_28,&_hotend_big_62x72);
	lv_img_set_pivot(ui->selftest_img_28, 0,0);
	lv_img_set_angle(ui->selftest_img_28, 0);

	//Write codes selftest_img_29
	ui->selftest_img_29 = lv_img_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_img_29, 262+ REVISE_X, 166+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_29, 26, 26);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_29_main_main_default
	static lv_style_t style_selftest_img_29_main_main_default;
	if (style_selftest_img_29_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_29_main_main_default);
	else
		lv_style_init(&style_selftest_img_29_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_29_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_29_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_29_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_29, &style_selftest_img_29_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_29, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_29,&_change_26x26);
	lv_img_set_pivot(ui->selftest_img_29, 0,0);
	lv_img_set_angle(ui->selftest_img_29, 0);

	//Write codes selftest_img_30
	ui->selftest_img_30 = lv_img_create(ui->selftest_tabview_1_Title15);
	lv_obj_set_pos(ui->selftest_img_30, 218+ REVISE_X, 173+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_30, 32, 20);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_30_main_main_default
	static lv_style_t style_selftest_img_30_main_main_default;
	if (style_selftest_img_30_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_30_main_main_default);
	else
		lv_style_init(&style_selftest_img_30_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_30_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_30_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_30_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_30, &style_selftest_img_30_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_30, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_30,&_Group_1419_32x20);
	lv_img_set_pivot(ui->selftest_img_30, 0,0);
	lv_img_set_angle(ui->selftest_img_30, 0);

	//Write codes selftest_label_121
	ui->selftest_label_121 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_121, 15+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_121, 12, 24);
	lv_label_set_text(ui->selftest_label_121, "2");
	lv_label_set_long_mode(ui->selftest_label_121, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_121, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_121_main_main_default
	static lv_style_t style_selftest_label_121_main_main_default;
	if (style_selftest_label_121_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_121_main_main_default);
	else
		lv_style_init(&style_selftest_label_121_main_main_default);
	lv_style_set_radius(&style_selftest_label_121_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_121_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_121_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_121_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_121_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_121_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_121_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_121_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_121_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_121_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_121_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_121_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_121, &style_selftest_label_121_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_128
	ui->selftest_label_128 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_128, 15+ REVISE_X, 24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_128, 450, 235);
	lv_label_set_text(ui->selftest_label_128, "");
	lv_label_set_long_mode(ui->selftest_label_128, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_128, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_128_main_main_default
	static lv_style_t style_selftest_label_128_main_main_default;
	if (style_selftest_label_128_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_128_main_main_default);
	else
		lv_style_init(&style_selftest_label_128_main_main_default);
	lv_style_set_radius(&style_selftest_label_128_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_128_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_128_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_128_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_128_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_128_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_128_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_128_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_128_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_128_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_128_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_128, &style_selftest_label_128_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_129
	ui->selftest_label_129 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_129, 15+ REVISE_X, 271+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_129, 450, 352);
	lv_label_set_text(ui->selftest_label_129, "");
	lv_label_set_long_mode(ui->selftest_label_129, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_129, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_129_main_main_default
	static lv_style_t style_selftest_label_129_main_main_default;
	if (style_selftest_label_129_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_129_main_main_default);
	else
		lv_style_init(&style_selftest_label_129_main_main_default);
	lv_style_set_radius(&style_selftest_label_129_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_129_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_129_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_129_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_129_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_129_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_129_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_129_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_129_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_129_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_129_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_129, &style_selftest_label_129_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_31
	ui->selftest_img_31 = lv_img_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_img_31, 202+ REVISE_X, 74+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_31, 78, 76);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_31_main_main_default
	static lv_style_t style_selftest_img_31_main_main_default;
	if (style_selftest_img_31_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_31_main_main_default);
	else
		lv_style_init(&style_selftest_img_31_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_31_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_31_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_31_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_31, &style_selftest_img_31_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_31, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_31,&_bedtemp_78x76);
	lv_img_set_pivot(ui->selftest_img_31, 0,0);
	lv_img_set_angle(ui->selftest_img_31, 0);

	//Write codes selftest_img_32
	ui->selftest_img_32 = lv_img_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_img_32, 251+ REVISE_X, 163+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_32, 26, 26);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_32_main_main_default
	static lv_style_t style_selftest_img_32_main_main_default;
	if (style_selftest_img_32_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_32_main_main_default);
	else
		lv_style_init(&style_selftest_img_32_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_32_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_32_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_32_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_32, &style_selftest_img_32_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_32, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_32,&_change_26x26);
	lv_img_set_pivot(ui->selftest_img_32, 0,0);
	lv_img_set_angle(ui->selftest_img_32, 0);

	//Write codes selftest_img_33
	ui->selftest_img_33 = lv_img_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_img_33, 222+ REVISE_X, 164+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_33, 32, 20);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_33_main_main_default
	static lv_style_t style_selftest_img_33_main_main_default;
	if (style_selftest_img_33_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_33_main_main_default);
	else
		lv_style_init(&style_selftest_img_33_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_33_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_33_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_33_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_33, &style_selftest_img_33_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_33, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_33,&_Group_1419_32x20);
	lv_img_set_pivot(ui->selftest_img_33, 0,0);
	lv_img_set_angle(ui->selftest_img_33, 0);

	//Write codes selftest_btn_60
	ui->selftest_btn_60 = lv_btn_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_btn_60, 384+ REVISE_X, -38+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_60, 86, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_60_main_main_default
	static lv_style_t style_selftest_btn_60_main_main_default;
	if (style_selftest_btn_60_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_60_main_main_default);
	else
		lv_style_init(&style_selftest_btn_60_main_main_default);
	lv_style_set_radius(&style_selftest_btn_60_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_60_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_60_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_60_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_60_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_60_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_60_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_60_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_60_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_60_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_60, &style_selftest_btn_60_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_60_label = lv_label_create(ui->selftest_btn_60);
	lv_label_set_text(ui->selftest_btn_60_label, "跳过");
	lv_obj_set_style_text_color(ui->selftest_btn_60_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_60_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_60, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_60_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_61
	ui->selftest_btn_61 = lv_btn_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_btn_61, 36+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_61, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_61_main_main_default
	static lv_style_t style_selftest_btn_61_main_main_default;
	if (style_selftest_btn_61_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_61_main_main_default);
	else
		lv_style_init(&style_selftest_btn_61_main_main_default);
	lv_style_set_radius(&style_selftest_btn_61_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_61_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_color(&style_selftest_btn_61_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_dir(&style_selftest_btn_61_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_61_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_61_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_61_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_61_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_61_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_61_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_61, &style_selftest_btn_61_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_61_label = lv_label_create(ui->selftest_btn_61);
	lv_label_set_text(ui->selftest_btn_61_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_61_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_61_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_61, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_61_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_62
	ui->selftest_btn_62 = lv_btn_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_btn_62, 298+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_62, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_62_main_main_default
	static lv_style_t style_selftest_btn_62_main_main_default;
	if (style_selftest_btn_62_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_62_main_main_default);
	else
		lv_style_init(&style_selftest_btn_62_main_main_default);
	lv_style_set_radius(&style_selftest_btn_62_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_62_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_62_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_62_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_62_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_62_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_62_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_62_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_62_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_62_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_62, &style_selftest_btn_62_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_62_label = lv_label_create(ui->selftest_btn_62);
	lv_label_set_text(ui->selftest_btn_62_label, "开始校准");
	lv_obj_set_style_text_color(ui->selftest_btn_62_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_62_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_62, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_62_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_122
	ui->selftest_label_122 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_122, 26+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_122, 30, 24);
	lv_label_set_text(ui->selftest_label_122, "/7");
	lv_label_set_long_mode(ui->selftest_label_122, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_122, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_122_main_main_default
	static lv_style_t style_selftest_label_122_main_main_default;
	if (style_selftest_label_122_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_122_main_main_default);
	else
		lv_style_init(&style_selftest_label_122_main_main_default);
	lv_style_set_radius(&style_selftest_label_122_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_122_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_122_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_122_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_122_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_122_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_122_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_122_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_122_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_122_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_122_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_122_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_122, &style_selftest_label_122_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_123
	ui->selftest_label_123 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_123, 100+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_123, 280, 32);
	lv_label_set_text(ui->selftest_label_123, "热床PID校准");
	lv_label_set_long_mode(ui->selftest_label_123, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_123, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_123_main_main_default
	static lv_style_t style_selftest_label_123_main_main_default;
	if (style_selftest_label_123_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_123_main_main_default);
	else
		lv_style_init(&style_selftest_label_123_main_main_default);
	lv_style_set_radius(&style_selftest_label_123_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_123_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_123_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_123_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_123_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_123_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_123_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_123_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_123_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_123_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_123_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_123_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_123, &style_selftest_label_123_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_124
	ui->selftest_label_124 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_124, 193+ REVISE_X, 164+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_124, 60, 24);
	lv_label_set_text(ui->selftest_label_124, "60℃");
	lv_label_set_long_mode(ui->selftest_label_124, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_124, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_124_main_main_default
	static lv_style_t style_selftest_label_124_main_main_default;
	if (style_selftest_label_124_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_124_main_main_default);
	else
		lv_style_init(&style_selftest_label_124_main_main_default);
	lv_style_set_radius(&style_selftest_label_124_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_124_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_124_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_124_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_124_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_124_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_124_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_124_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_124_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_124_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_124_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_124_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_124, &style_selftest_label_124_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_126
	ui->selftest_label_126 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_126, 149+ REVISE_X, 164+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_126, 60, 24);
	lv_label_set_text(ui->selftest_label_126, "60℃");
	lv_label_set_long_mode(ui->selftest_label_126, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_126, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_126_main_main_default
	static lv_style_t style_selftest_label_126_main_main_default;
	if (style_selftest_label_126_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_126_main_main_default);
	else
		lv_style_init(&style_selftest_label_126_main_main_default);
	lv_style_set_radius(&style_selftest_label_126_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_126_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_126_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_126_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_126_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_126_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_126_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_126_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_126_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_126_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_126_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_126_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_126, &style_selftest_label_126_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_127
	ui->selftest_label_127 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_127, 280+ REVISE_X, 164+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_127, 60, 24);
	lv_label_set_text(ui->selftest_label_127, "60℃");
	lv_label_set_long_mode(ui->selftest_label_127, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_127, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_127_main_main_default
	static lv_style_t style_selftest_label_127_main_main_default;
	if (style_selftest_label_127_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_127_main_main_default);
	else
		lv_style_init(&style_selftest_label_127_main_main_default);
	lv_style_set_radius(&style_selftest_label_127_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_127_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_127_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_127_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_127_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_127_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_127_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_127_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_127_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_127_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_127_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_127_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_127, &style_selftest_label_127_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_130
	ui->selftest_label_130 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_130, 35+ REVISE_X, 295+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_130, 410, 28);
	lv_label_set_text(ui->selftest_label_130, "请进行喷头PID检测及校准");
	lv_label_set_long_mode(ui->selftest_label_130, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_130, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_130_main_main_default
	static lv_style_t style_selftest_label_130_main_main_default;
	if (style_selftest_label_130_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_130_main_main_default);
	else
		lv_style_init(&style_selftest_label_130_main_main_default);
	lv_style_set_radius(&style_selftest_label_130_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_130_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_130_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_130_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_130_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_130_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_130_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_selftest_label_130_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_130_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_130_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_130_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_130_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_130, &style_selftest_label_130_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_131
	ui->selftest_label_131 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_131, 35+ REVISE_X, 335+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_131, 410, 24);
	lv_label_set_text(ui->selftest_label_131, "1.预计需要5分钟左右；");
	lv_label_set_long_mode(ui->selftest_label_131, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_131, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_131_main_main_default
	static lv_style_t style_selftest_label_131_main_main_default;
	if (style_selftest_label_131_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_131_main_main_default);
	else
		lv_style_init(&style_selftest_label_131_main_main_default);
	lv_style_set_radius(&style_selftest_label_131_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_131_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_131_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_131_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_131_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_131_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_131_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_131_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_131_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_131_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_131_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_131_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_131, &style_selftest_label_131_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_132
	ui->selftest_label_132 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_132, 35+ REVISE_X, 373+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_132, 410, 68);
	lv_label_set_text(ui->selftest_label_132, "2.如不正常请查看说明书或联系客服。");
	lv_label_set_long_mode(ui->selftest_label_132, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_132, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_132_main_main_default
	static lv_style_t style_selftest_label_132_main_main_default;
	if (style_selftest_label_132_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_132_main_main_default);
	else
		lv_style_init(&style_selftest_label_132_main_main_default);
	lv_style_set_radius(&style_selftest_label_132_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_132_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_132_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_132_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_132_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_132_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_132_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_132_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_132_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_132_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_132_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_132_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_132, &style_selftest_label_132_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_125
	ui->selftest_label_125 = lv_label_create(ui->selftest_tabview_1_Title16);
	lv_obj_set_pos(ui->selftest_label_125, 193+ REVISE_X, 204+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_125, 93, 1);
	lv_label_set_text(ui->selftest_label_125, "");
	lv_label_set_long_mode(ui->selftest_label_125, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_125, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_125_main_main_default
	static lv_style_t style_selftest_label_125_main_main_default;
	if (style_selftest_label_125_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_125_main_main_default);
	else
		lv_style_init(&style_selftest_label_125_main_main_default);
	lv_style_set_radius(&style_selftest_label_125_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_125_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_color(&style_selftest_label_125_main_main_default, lv_color_make(0x3a, 0x3c, 0x40));
	lv_style_set_bg_grad_dir(&style_selftest_label_125_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_125_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_125_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_125_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_125_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_125_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_125_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_125_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_125, &style_selftest_label_125_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_133
	ui->selftest_label_133 = lv_label_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_label_133, 15+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_133, 12, 24);
	lv_label_set_text(ui->selftest_label_133, "3");
	lv_label_set_long_mode(ui->selftest_label_133, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_133, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_133_main_main_default
	static lv_style_t style_selftest_label_133_main_main_default;
	if (style_selftest_label_133_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_133_main_main_default);
	else
		lv_style_init(&style_selftest_label_133_main_main_default);
	lv_style_set_radius(&style_selftest_label_133_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_133_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_133_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_133_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_133_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_133_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_selftest_label_133_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_133_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_133_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_133_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_133_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_133_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_133, &style_selftest_label_133_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_63
	ui->selftest_btn_63 = lv_btn_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_btn_63, 384+ REVISE_X, -38+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_63, 86, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_63_main_main_default
	static lv_style_t style_selftest_btn_63_main_main_default;
	if (style_selftest_btn_63_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_63_main_main_default);
	else
		lv_style_init(&style_selftest_btn_63_main_main_default);
	lv_style_set_radius(&style_selftest_btn_63_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_63_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_63_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_63_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_63_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_63_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_63_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_63_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_63_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_63_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_63, &style_selftest_btn_63_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_63_label = lv_label_create(ui->selftest_btn_63);
	lv_label_set_text(ui->selftest_btn_63_label, "跳过");
	lv_obj_set_style_text_color(ui->selftest_btn_63_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_63_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_63, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_63_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_64
	ui->selftest_btn_64 = lv_btn_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_btn_64, 36+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_64, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_64_main_main_default
	static lv_style_t style_selftest_btn_64_main_main_default;
	if (style_selftest_btn_64_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_64_main_main_default);
	else
		lv_style_init(&style_selftest_btn_64_main_main_default);
	lv_style_set_radius(&style_selftest_btn_64_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_64_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_color(&style_selftest_btn_64_main_main_default, lv_color_make(0x51, 0x54, 0x59));
	lv_style_set_bg_grad_dir(&style_selftest_btn_64_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_64_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_64_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_64_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_64_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_64_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_64_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_64, &style_selftest_btn_64_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_64_label = lv_label_create(ui->selftest_btn_64);
	lv_label_set_text(ui->selftest_btn_64_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_64_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_64_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_64, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_64_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_65
	ui->selftest_btn_65 = lv_btn_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_btn_65, 298+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_65, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_65_main_main_default
	static lv_style_t style_selftest_btn_65_main_main_default;
	if (style_selftest_btn_65_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_65_main_main_default);
	else
		lv_style_init(&style_selftest_btn_65_main_main_default);
	lv_style_set_radius(&style_selftest_btn_65_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_65_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_65_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_65_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_65_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_65_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_65_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_65_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_65_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_65_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_65, &style_selftest_btn_65_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_65_label = lv_label_create(ui->selftest_btn_65);
	lv_label_set_text(ui->selftest_btn_65_label, "下一步");
	lv_obj_set_style_text_color(ui->selftest_btn_65_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_65_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_65, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_65_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_134
	ui->selftest_label_134 = lv_label_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_label_134, 25+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_134, 30, 24);
	lv_label_set_text(ui->selftest_label_134, "/3");
	lv_label_set_long_mode(ui->selftest_label_134, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_134, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_134_main_main_default
	static lv_style_t style_selftest_label_134_main_main_default;
	if (style_selftest_label_134_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_134_main_main_default);
	else
		lv_style_init(&style_selftest_label_134_main_main_default);
	lv_style_set_radius(&style_selftest_label_134_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_134_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_134_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_134_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_134_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_134_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_134_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_134_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_134_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_134_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_134_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_134_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_134, &style_selftest_label_134_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_135
	ui->selftest_label_135 = lv_label_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_label_135, 100+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_135, 280, 32);
	lv_label_set_text(ui->selftest_label_135, "自动调平");
	lv_label_set_long_mode(ui->selftest_label_135, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_135, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_135_main_main_default
	static lv_style_t style_selftest_label_135_main_main_default;
	if (style_selftest_label_135_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_135_main_main_default);
	else
		lv_style_init(&style_selftest_label_135_main_main_default);
	lv_style_set_radius(&style_selftest_label_135_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_135_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_135_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_135_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_135_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_135_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_135_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_135_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_135_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_135_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_135_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_135_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_135, &style_selftest_label_135_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_136
	ui->selftest_label_136 = lv_label_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_label_136, 14+ REVISE_X, 23+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_136, 450, 603);
	lv_label_set_text(ui->selftest_label_136, "");
	lv_label_set_long_mode(ui->selftest_label_136, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_136, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_136_main_main_default
	static lv_style_t style_selftest_label_136_main_main_default;
	if (style_selftest_label_136_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_136_main_main_default);
	else
		lv_style_init(&style_selftest_label_136_main_main_default);
	lv_style_set_radius(&style_selftest_label_136_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_136_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_136_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_136_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_136_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_136_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_136_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_136_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_136_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_136_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_136_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_136, &style_selftest_label_136_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_img_34
	ui->selftest_img_34 = lv_img_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_img_34, 66+ REVISE_X, 143+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_34, 136, 136);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_34_main_main_default
	static lv_style_t style_selftest_img_34_main_main_default;
	if (style_selftest_img_34_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_34_main_main_default);
	else
		lv_style_init(&style_selftest_img_34_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_34_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_34_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_34_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_34, &style_selftest_img_34_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_34, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_34,&_level_3_black_136x136);
	lv_img_set_pivot(ui->selftest_img_34, 0,0);
	lv_img_set_angle(ui->selftest_img_34, 0);

	//Write codes selftest_img_35
	ui->selftest_img_35 = lv_img_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_img_35, 291+ REVISE_X, 143+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_35, 136, 136);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_35_main_main_default
	static lv_style_t style_selftest_img_35_main_main_default;
	if (style_selftest_img_35_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_35_main_main_default);
	else
		lv_style_init(&style_selftest_img_35_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_35_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_35_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_35_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_35, &style_selftest_img_35_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_35, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_35,&_level_4_black_136x136);
	lv_img_set_pivot(ui->selftest_img_35, 0,0);
	lv_img_set_angle(ui->selftest_img_35, 0);

	//Write codes selftest_img_36
	ui->selftest_img_36 = lv_img_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_img_36, 66+ REVISE_X, 360+ REVISE_Y);
	lv_obj_set_size(ui->selftest_img_36, 136, 136);

	//Write style state: LV_STATE_DEFAULT for style_selftest_img_36_main_main_default
	static lv_style_t style_selftest_img_36_main_main_default;
	if (style_selftest_img_36_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_img_36_main_main_default);
	else
		lv_style_init(&style_selftest_img_36_main_main_default);
	lv_style_set_img_recolor(&style_selftest_img_36_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_selftest_img_36_main_main_default, 0);
	lv_style_set_img_opa(&style_selftest_img_36_main_main_default, 255);
	lv_obj_add_style(ui->selftest_img_36, &style_selftest_img_36_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->selftest_img_36, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->selftest_img_36,&_level_5_blue_136x136);
	lv_img_set_pivot(ui->selftest_img_36, 0,0);
	lv_img_set_angle(ui->selftest_img_36, 0);

	//Write codes selftest_label_137
	ui->selftest_label_137 = lv_label_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_label_137, 100+ REVISE_X, 49+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_137, 280, 24);
	lv_label_set_text(ui->selftest_label_137, "请选择您需要调平的点数");
	lv_label_set_long_mode(ui->selftest_label_137, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_137, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_137_main_main_default
	static lv_style_t style_selftest_label_137_main_main_default;
	if (style_selftest_label_137_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_137_main_main_default);
	else
		lv_style_init(&style_selftest_label_137_main_main_default);
	lv_style_set_radius(&style_selftest_label_137_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_137_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_137_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_137_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_137_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_137_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_selftest_label_137_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_137_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_137_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_137_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_137_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_137_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_137, &style_selftest_label_137_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_138
	ui->selftest_label_138 = lv_label_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_label_138, 106+ REVISE_X, 287+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_138, 44, 24);
	lv_label_set_text(ui->selftest_label_138, "3X3");
	lv_label_set_long_mode(ui->selftest_label_138, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_138, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_138_main_main_default
	static lv_style_t style_selftest_label_138_main_main_default;
	if (style_selftest_label_138_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_138_main_main_default);
	else
		lv_style_init(&style_selftest_label_138_main_main_default);
	lv_style_set_radius(&style_selftest_label_138_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_138_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_138_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_138_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_138_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_138_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_selftest_label_138_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_138_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_138_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_138_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_138_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_138_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_138, &style_selftest_label_138_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_139
	ui->selftest_label_139 = lv_label_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_label_139, 331+ REVISE_X, 287+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_139, 44, 24);
	lv_label_set_text(ui->selftest_label_139, "4X4");
	lv_label_set_long_mode(ui->selftest_label_139, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_139, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_139_main_main_default
	static lv_style_t style_selftest_label_139_main_main_default;
	if (style_selftest_label_139_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_139_main_main_default);
	else
		lv_style_init(&style_selftest_label_139_main_main_default);
	lv_style_set_radius(&style_selftest_label_139_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_139_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_139_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_139_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_139_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_139_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_selftest_label_139_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_139_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_139_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_139_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_139_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_139_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_139, &style_selftest_label_139_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_140
	ui->selftest_label_140 = lv_label_create(ui->selftest_tabview_1_Title17);
	lv_obj_set_pos(ui->selftest_label_140, 112+ REVISE_X, 504+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_140, 44, 24);
	lv_label_set_text(ui->selftest_label_140, "5X5");
	lv_label_set_long_mode(ui->selftest_label_140, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_140, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_140_main_main_default
	static lv_style_t style_selftest_label_140_main_main_default;
	if (style_selftest_label_140_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_140_main_main_default);
	else
		lv_style_init(&style_selftest_label_140_main_main_default);
	lv_style_set_radius(&style_selftest_label_140_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_140_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_140_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_140_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_140_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_140_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_text_font(&style_selftest_label_140_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_140_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_140_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_140_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_140_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_140_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_140, &style_selftest_label_140_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_141
	ui->selftest_label_141 = lv_label_create(ui->selftest_tabview_1_Title18);
	lv_obj_set_pos(ui->selftest_label_141, 15+ REVISE_X, -31+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_141, 40, 24);
	lv_label_set_text(ui->selftest_label_141, "1/3");
	lv_label_set_long_mode(ui->selftest_label_141, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_141, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_141_main_main_default
	static lv_style_t style_selftest_label_141_main_main_default;
	if (style_selftest_label_141_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_141_main_main_default);
	else
		lv_style_init(&style_selftest_label_141_main_main_default);
	lv_style_set_radius(&style_selftest_label_141_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_141_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_141_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_141_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_141_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_141_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_141_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_selftest_label_141_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_141_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_141_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_141_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_141_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_141, &style_selftest_label_141_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_66
	ui->selftest_btn_66 = lv_btn_create(ui->selftest_tabview_1_Title18);
	lv_obj_set_pos(ui->selftest_btn_66, 384+ REVISE_X, -38+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_66, 86, 50);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_66_main_main_default
	static lv_style_t style_selftest_btn_66_main_main_default;
	if (style_selftest_btn_66_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_66_main_main_default);
	else
		lv_style_init(&style_selftest_btn_66_main_main_default);
	lv_style_set_radius(&style_selftest_btn_66_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_66_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_66_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_66_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_66_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_66_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_66_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_66_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_66_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_66_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_66, &style_selftest_btn_66_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_66_label = lv_label_create(ui->selftest_btn_66);
	lv_label_set_text(ui->selftest_btn_66_label, "跳过");
	lv_obj_set_style_text_color(ui->selftest_btn_66_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_66_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_66, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_66_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_label_142
	ui->selftest_label_142 = lv_label_create(ui->selftest_tabview_1_Title18);
	lv_obj_set_pos(ui->selftest_label_142, 100+ REVISE_X, -27+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_142, 280, 32);
	lv_label_set_text(ui->selftest_label_142, "探头测试");
	lv_label_set_long_mode(ui->selftest_label_142, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_142, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_142_main_main_default
	static lv_style_t style_selftest_label_142_main_main_default;
	if (style_selftest_label_142_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_142_main_main_default);
	else
		lv_style_init(&style_selftest_label_142_main_main_default);
	lv_style_set_radius(&style_selftest_label_142_main_main_default, 0);
	lv_style_set_bg_color(&style_selftest_label_142_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_selftest_label_142_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_selftest_label_142_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_142_main_main_default, 0);
	lv_style_set_text_color(&style_selftest_label_142_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_selftest_label_142_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_selftest_label_142_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_142_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_142_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_142_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_142_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_142, &style_selftest_label_142_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_label_143
	ui->selftest_label_143 = lv_label_create(ui->selftest_tabview_1_Title18);
	lv_obj_set_pos(ui->selftest_label_143, 15+ REVISE_X, 24+ REVISE_Y);
	lv_obj_set_size(ui->selftest_label_143, 450, 603);
	lv_label_set_text(ui->selftest_label_143, "");
	lv_label_set_long_mode(ui->selftest_label_143, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->selftest_label_143, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_selftest_label_143_main_main_default
	static lv_style_t style_selftest_label_143_main_main_default;
	if (style_selftest_label_143_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_label_143_main_main_default);
	else
		lv_style_init(&style_selftest_label_143_main_main_default);
	lv_style_set_radius(&style_selftest_label_143_main_main_default, 8);
	lv_style_set_bg_color(&style_selftest_label_143_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_selftest_label_143_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_selftest_label_143_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_label_143_main_main_default, 255);
	lv_style_set_text_color(&style_selftest_label_143_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_selftest_label_143_main_main_default, 0);
	lv_style_set_pad_left(&style_selftest_label_143_main_main_default, 0);
	lv_style_set_pad_right(&style_selftest_label_143_main_main_default, 0);
	lv_style_set_pad_top(&style_selftest_label_143_main_main_default, 0);
	lv_style_set_pad_bottom(&style_selftest_label_143_main_main_default, 0);
	lv_obj_add_style(ui->selftest_label_143, &style_selftest_label_143_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes selftest_btn_67
	ui->selftest_btn_67 = lv_btn_create(ui->selftest_tabview_1_Title18);
	lv_obj_set_pos(ui->selftest_btn_67, 90+ REVISE_X, 124+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_67, 300, 98);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_67_main_main_default
	static lv_style_t style_selftest_btn_67_main_main_default;
	if (style_selftest_btn_67_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_67_main_main_default);
	else
		lv_style_init(&style_selftest_btn_67_main_main_default);
	lv_style_set_radius(&style_selftest_btn_67_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_67_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_67_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_67_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_67_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_67_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_67_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_67_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_67_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_67_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_67, &style_selftest_btn_67_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_67_label = lv_label_create(ui->selftest_btn_67);
	lv_label_set_text(ui->selftest_btn_67_label, "探出");
	lv_obj_set_style_text_color(ui->selftest_btn_67_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_67_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_67, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_67_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_68
	ui->selftest_btn_68 = lv_btn_create(ui->selftest_tabview_1_Title18);
	lv_obj_set_pos(ui->selftest_btn_68, 90+ REVISE_X, 272+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_68, 300, 98);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_68_main_main_default
	static lv_style_t style_selftest_btn_68_main_main_default;
	if (style_selftest_btn_68_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_68_main_main_default);
	else
		lv_style_init(&style_selftest_btn_68_main_main_default);
	lv_style_set_radius(&style_selftest_btn_68_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_68_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_68_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_68_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_68_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_68_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_68_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_68_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_68_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_68_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_68, &style_selftest_btn_68_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_68_label = lv_label_create(ui->selftest_btn_68);
	lv_label_set_text(ui->selftest_btn_68_label, "收回");
	lv_obj_set_style_text_color(ui->selftest_btn_68_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_68_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_68, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_68_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_69
	ui->selftest_btn_69 = lv_btn_create(ui->selftest_tabview_1_Title18);
	lv_obj_set_pos(ui->selftest_btn_69, 90+ REVISE_X, 420+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_69, 300, 98);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_69_main_main_default
	static lv_style_t style_selftest_btn_69_main_main_default;
	if (style_selftest_btn_69_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_69_main_main_default);
	else
		lv_style_init(&style_selftest_btn_69_main_main_default);
	lv_style_set_radius(&style_selftest_btn_69_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_69_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_69_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_69_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_69_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_69_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_69_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_69_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_69_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_69_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_69, &style_selftest_btn_69_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_69_label = lv_label_create(ui->selftest_btn_69);
	lv_label_set_text(ui->selftest_btn_69_label, "自动测试");
	lv_obj_set_style_text_color(ui->selftest_btn_69_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_69_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_69, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_69_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_70
	ui->selftest_btn_70 = lv_btn_create(ui->selftest_tabview_1_Title18);
	lv_obj_set_pos(ui->selftest_btn_70, 36+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_70, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_70_main_main_default
	static lv_style_t style_selftest_btn_70_main_main_default;
	if (style_selftest_btn_70_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_70_main_main_default);
	else
		lv_style_init(&style_selftest_btn_70_main_main_default);
	lv_style_set_radius(&style_selftest_btn_70_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_70_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_selftest_btn_70_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_selftest_btn_70_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_70_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_70_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_70_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_70_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_70_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_70_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_70, &style_selftest_btn_70_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_70_label = lv_label_create(ui->selftest_btn_70);
	lv_label_set_text(ui->selftest_btn_70_label, "上一步");
	lv_obj_set_style_text_color(ui->selftest_btn_70_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_70_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_70, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_70_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes selftest_btn_71
	ui->selftest_btn_71 = lv_btn_create(ui->selftest_tabview_1_Title18);
	lv_obj_set_pos(ui->selftest_btn_71, 298+ REVISE_X, 656+ REVISE_Y);
	lv_obj_set_size(ui->selftest_btn_71, 146, 64);

	//Write style state: LV_STATE_DEFAULT for style_selftest_btn_71_main_main_default
	static lv_style_t style_selftest_btn_71_main_main_default;
	if (style_selftest_btn_71_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_selftest_btn_71_main_main_default);
	else
		lv_style_init(&style_selftest_btn_71_main_main_default);
	lv_style_set_radius(&style_selftest_btn_71_main_main_default, 6);
	lv_style_set_bg_color(&style_selftest_btn_71_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_selftest_btn_71_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_selftest_btn_71_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_selftest_btn_71_main_main_default, 255);
	lv_style_set_shadow_color(&style_selftest_btn_71_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_selftest_btn_71_main_main_default, 0);
	lv_style_set_border_color(&style_selftest_btn_71_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_selftest_btn_71_main_main_default, 0);
	lv_style_set_border_opa(&style_selftest_btn_71_main_main_default, 255);
	lv_obj_add_style(ui->selftest_btn_71, &style_selftest_btn_71_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->selftest_btn_71_label = lv_label_create(ui->selftest_btn_71);
	lv_label_set_text(ui->selftest_btn_71_label, "下一步");
	lv_obj_set_style_text_color(ui->selftest_btn_71_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->selftest_btn_71_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->selftest_btn_71, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->selftest_btn_71_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_selftest(ui);
}
