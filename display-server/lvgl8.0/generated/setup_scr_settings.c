/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "../custom/clanguage.h"
#include "../custom/custom.h"
#include "../custom/mystyle.h"

static void _settings_ddlist_1_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);

	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_1_extra_list_selected_default
	static lv_style_t style_settings_ddlist_1_extra_list_selected_default;
	if (style_settings_ddlist_1_extra_list_selected_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_1_extra_list_selected_default);
	else
		lv_style_init(&style_settings_ddlist_1_extra_list_selected_default);
	lv_style_set_radius(&style_settings_ddlist_1_extra_list_selected_default, 0);
	lv_style_set_bg_color(&style_settings_ddlist_1_extra_list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_ddlist_1_extra_list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_1_extra_list_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_1_extra_list_selected_default, 255);
	lv_style_set_border_color(&style_settings_ddlist_1_extra_list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_ddlist_1_extra_list_selected_default, 0);
	lv_style_set_text_color(&style_settings_ddlist_1_extra_list_selected_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_ddlist_1_extra_list_selected_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_ddlist_1_extra_list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_1_extra_list_main_default
	static lv_style_t style_settings_ddlist_1_extra_list_main_default;
	if (style_settings_ddlist_1_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_1_extra_list_main_default);
	else
		lv_style_init(&style_settings_ddlist_1_extra_list_main_default);
	lv_style_set_radius(&style_settings_ddlist_1_extra_list_main_default, 0);
	lv_style_set_bg_color(&style_settings_ddlist_1_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_color(&style_settings_ddlist_1_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_1_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_settings_ddlist_1_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_ddlist_1_extra_list_main_default, 0);
	lv_style_set_text_color(&style_settings_ddlist_1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_ddlist_1_extra_list_main_default, &lv_font_simsun_24);
	lv_style_set_max_height(&style_settings_ddlist_1_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_1_extra_list_scrollbar_default
	static lv_style_t style_settings_ddlist_1_extra_list_scrollbar_default;
	if (style_settings_ddlist_1_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_1_extra_list_scrollbar_default);
	else
		lv_style_init(&style_settings_ddlist_1_extra_list_scrollbar_default);
	lv_style_set_radius(&style_settings_ddlist_1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_settings_ddlist_1_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_grad_color(&style_settings_ddlist_1_extra_list_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_1_extra_list_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_1_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}
static void _settings_ddlist_2_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);

	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_2_extra_list_selected_default
	static lv_style_t style_settings_ddlist_2_extra_list_selected_default;
	if (style_settings_ddlist_2_extra_list_selected_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_2_extra_list_selected_default);
	else
		lv_style_init(&style_settings_ddlist_2_extra_list_selected_default);
	lv_style_set_radius(&style_settings_ddlist_2_extra_list_selected_default, 0);
	lv_style_set_bg_color(&style_settings_ddlist_2_extra_list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_ddlist_2_extra_list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_2_extra_list_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_2_extra_list_selected_default, 255);
	lv_style_set_border_color(&style_settings_ddlist_2_extra_list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_ddlist_2_extra_list_selected_default, 0);
	lv_style_set_text_color(&style_settings_ddlist_2_extra_list_selected_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_ddlist_2_extra_list_selected_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_ddlist_2_extra_list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_2_extra_list_main_default
	static lv_style_t style_settings_ddlist_2_extra_list_main_default;
	if (style_settings_ddlist_2_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_2_extra_list_main_default);
	else
		lv_style_init(&style_settings_ddlist_2_extra_list_main_default);
	lv_style_set_radius(&style_settings_ddlist_2_extra_list_main_default, 0);
	lv_style_set_bg_color(&style_settings_ddlist_2_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_color(&style_settings_ddlist_2_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_2_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_2_extra_list_main_default, 255);
	lv_style_set_border_color(&style_settings_ddlist_2_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_ddlist_2_extra_list_main_default, 0);
	lv_style_set_text_color(&style_settings_ddlist_2_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_ddlist_2_extra_list_main_default, &lv_font_simsun_24);
	lv_style_set_max_height(&style_settings_ddlist_2_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_ddlist_2_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_2_extra_list_scrollbar_default
	static lv_style_t style_settings_ddlist_2_extra_list_scrollbar_default;
	if (style_settings_ddlist_2_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_2_extra_list_scrollbar_default);
	else
		lv_style_init(&style_settings_ddlist_2_extra_list_scrollbar_default);
	lv_style_set_radius(&style_settings_ddlist_2_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_settings_ddlist_2_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_grad_color(&style_settings_ddlist_2_extra_list_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_2_extra_list_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_2_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_ddlist_2_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}
static void _settings_ddlist_3_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);

	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_3_extra_list_selected_default
	static lv_style_t style_settings_ddlist_3_extra_list_selected_default;
	if (style_settings_ddlist_3_extra_list_selected_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_3_extra_list_selected_default);
	else
		lv_style_init(&style_settings_ddlist_3_extra_list_selected_default);
	lv_style_set_radius(&style_settings_ddlist_3_extra_list_selected_default, 0);
	lv_style_set_bg_color(&style_settings_ddlist_3_extra_list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_ddlist_3_extra_list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_3_extra_list_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_3_extra_list_selected_default, 255);
	lv_style_set_border_color(&style_settings_ddlist_3_extra_list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_ddlist_3_extra_list_selected_default, 0);
	lv_style_set_text_color(&style_settings_ddlist_3_extra_list_selected_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_ddlist_3_extra_list_selected_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_ddlist_3_extra_list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_3_extra_list_main_default
	static lv_style_t style_settings_ddlist_3_extra_list_main_default;
	if (style_settings_ddlist_3_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_3_extra_list_main_default);
	else
		lv_style_init(&style_settings_ddlist_3_extra_list_main_default);
	lv_style_set_radius(&style_settings_ddlist_3_extra_list_main_default, 0);
	lv_style_set_bg_color(&style_settings_ddlist_3_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_color(&style_settings_ddlist_3_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_3_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_3_extra_list_main_default, 255);
	lv_style_set_border_color(&style_settings_ddlist_3_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_ddlist_3_extra_list_main_default, 0);
	lv_style_set_text_color(&style_settings_ddlist_3_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_ddlist_3_extra_list_main_default, &lv_font_simsun_24);
	lv_style_set_max_height(&style_settings_ddlist_3_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_ddlist_3_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_3_extra_list_scrollbar_default
	static lv_style_t style_settings_ddlist_3_extra_list_scrollbar_default;
	if (style_settings_ddlist_3_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_3_extra_list_scrollbar_default);
	else
		lv_style_init(&style_settings_ddlist_3_extra_list_scrollbar_default);
	lv_style_set_radius(&style_settings_ddlist_3_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_settings_ddlist_3_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_grad_color(&style_settings_ddlist_3_extra_list_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_3_extra_list_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_3_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_ddlist_3_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}

void setup_scr_settings(lv_ui *ui){

	//Write codes settings_cont_1
	ui->settings_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->settings_cont_1, 0, 0);
	lv_obj_set_size(ui->settings_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_settings_cont_1_main_main_default
	static lv_style_t style_settings_cont_1_main_main_default;
	if (style_settings_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cont_1_main_main_default);
	else
		lv_style_init(&style_settings_cont_1_main_main_default);
	lv_style_set_radius(&style_settings_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_settings_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_cont_1, &style_settings_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_tabview_1
	ui->settings_tabview_1 = lv_tabview_create(ui->settings_cont_1, LV_DIR_TOP, 52);
	lv_obj_set_pos(ui->settings_tabview_1, 0, 0);
	lv_obj_set_size(ui->settings_tabview_1, 480, 720);

	//title1
	ui->settings_tabview_1_title1 = lv_tabview_add_tab(ui->settings_tabview_1,"系统");

	//title2
	ui->settings_tabview_1_title2 = lv_tabview_add_tab(ui->settings_tabview_1,"网络");

	//title3
	ui->settings_tabview_1_title3 = lv_tabview_add_tab(ui->settings_tabview_1,"自检");

	//title4
	ui->settings_tabview_1_title4 = lv_tabview_add_tab(ui->settings_tabview_1,"摄像头");


	//Write style state: LV_STATE_DEFAULT for style_settings_tabview_1_main_main_default
	static lv_style_t style_settings_tabview_1_main_main_default;
	if (style_settings_tabview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_tabview_1_main_main_default);
	else
		lv_style_init(&style_settings_tabview_1_main_main_default);
	lv_style_set_bg_color(&style_settings_tabview_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_settings_tabview_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_settings_tabview_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_tabview_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_tabview_1_main_main_default, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_settings_tabview_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_tabview_1_main_main_default, 255);
	lv_style_set_text_color(&style_settings_tabview_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_settings_tabview_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_tabview_1_main_main_default, 0);
	lv_style_set_text_line_space(&style_settings_tabview_1_main_main_default, 16);
	lv_obj_add_style(ui->settings_tabview_1, &style_settings_tabview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_tabview_1_extra_btnm_main_default
	static lv_style_t style_settings_tabview_1_extra_btnm_main_default;
	if (style_settings_tabview_1_extra_btnm_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_tabview_1_extra_btnm_main_default);
	else
		lv_style_init(&style_settings_tabview_1_extra_btnm_main_default);
	lv_style_set_bg_color(&style_settings_tabview_1_extra_btnm_main_default, lv_color_make(0x12, 0x12, 0x12));
	lv_style_set_bg_grad_color(&style_settings_tabview_1_extra_btnm_main_default, lv_color_make(0x12, 0x12, 0x12));
	lv_style_set_bg_grad_dir(&style_settings_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_border_color(&style_settings_tabview_1_extra_btnm_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_border_opa(&style_settings_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_pad_left(&style_settings_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_right(&style_settings_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_top(&style_settings_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_tabview_1_extra_btnm_main_default, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_tabview_1), &style_settings_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_tabview_1_extra_btnm_items_default
	static lv_style_t style_settings_tabview_1_extra_btnm_items_default;
	if (style_settings_tabview_1_extra_btnm_items_default.prop_cnt > 1)
		lv_style_reset(&style_settings_tabview_1_extra_btnm_items_default);
	else
		lv_style_init(&style_settings_tabview_1_extra_btnm_items_default);
	lv_style_set_text_color(&style_settings_tabview_1_extra_btnm_items_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_settings_tabview_1_extra_btnm_items_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_tabview_1), &style_settings_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_tabview_1_extra_btnm_items_checked
	static lv_style_t style_settings_tabview_1_extra_btnm_items_checked;
	if (style_settings_tabview_1_extra_btnm_items_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_tabview_1_extra_btnm_items_checked);
	else
		lv_style_init(&style_settings_tabview_1_extra_btnm_items_checked);
	lv_style_set_bg_color(&style_settings_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_tabview_1_extra_btnm_items_checked, 60);
	lv_style_set_border_color(&style_settings_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_tabview_1_extra_btnm_items_checked, 0);
	lv_style_set_border_opa(&style_settings_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_side(&style_settings_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_text_color(&style_settings_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_text_font(&style_settings_tabview_1_extra_btnm_items_checked, &lv_font_simsun_24);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_tabview_1), &style_settings_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes settings_label_1
	ui->settings_label_1 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_1, 7, 8);
	lv_obj_set_size(ui->settings_label_1, 460, 648);
	lv_label_set_text(ui->settings_label_1, "");
	lv_label_set_long_mode(ui->settings_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_1_main_main_default
	static lv_style_t style_settings_label_1_main_main_default;
	if (style_settings_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_1_main_main_default);
	else
		lv_style_init(&style_settings_label_1_main_main_default);
	lv_style_set_radius(&style_settings_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_1_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_label_1_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_settings_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_settings_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_1, &style_settings_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_ddlist_1
	ui->settings_ddlist_1 = lv_dropdown_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_ddlist_1, 216, 183);
	lv_obj_set_width(ui->settings_ddlist_1, 242);
	lv_dropdown_set_options(ui->settings_ddlist_1, "3分钟\n5分钟\n15分钟\n不设置");
	lv_obj_add_event_cb(ui->settings_ddlist_1, _settings_ddlist_1_event_cb, LV_EVENT_READY, NULL);

	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_1_main_main_default
	static lv_style_t style_settings_ddlist_1_main_main_default;
	if (style_settings_ddlist_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_1_main_main_default);
	else
		lv_style_init(&style_settings_ddlist_1_main_main_default);
	lv_style_set_radius(&style_settings_ddlist_1_main_main_default, 2);
	lv_style_set_bg_color(&style_settings_ddlist_1_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_settings_ddlist_1_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_ddlist_1_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_settings_ddlist_1_main_main_default, 1);
	lv_style_set_text_color(&style_settings_ddlist_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_ddlist_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_line_space(&style_settings_ddlist_1_main_main_default, 20);
	lv_obj_add_style(ui->settings_ddlist_1, &style_settings_ddlist_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_ddlist_2
	ui->settings_ddlist_2 = lv_dropdown_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_ddlist_2, 216, 258);
	lv_obj_set_width(ui->settings_ddlist_2, 242);
	lv_dropdown_set_options(ui->settings_ddlist_2, "中文");
	lv_dropdown_close(ui->settings_ddlist_2);
    lv_obj_add_event_cb(ui->settings_ddlist_2, _settings_ddlist_2_event_cb, LV_EVENT_READY, NULL);


	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_2_main_main_default
	static lv_style_t style_settings_ddlist_2_main_main_default;
	if (style_settings_ddlist_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_2_main_main_default);
	else
		lv_style_init(&style_settings_ddlist_2_main_main_default);
	lv_style_set_radius(&style_settings_ddlist_2_main_main_default, 2);
	lv_style_set_bg_color(&style_settings_ddlist_2_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_settings_ddlist_2_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_2_main_main_default, 255);
	lv_style_set_border_color(&style_settings_ddlist_2_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_settings_ddlist_2_main_main_default, 1);
	lv_style_set_text_color(&style_settings_ddlist_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_ddlist_2_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_line_space(&style_settings_ddlist_2_main_main_default, 20);
	lv_obj_add_style(ui->settings_ddlist_2, &style_settings_ddlist_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_ddlist_3
	ui->settings_ddlist_3 = lv_dropdown_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_ddlist_3, 216, 485);
	lv_obj_set_width(ui->settings_ddlist_3, 242);
	lv_dropdown_set_options(ui->settings_ddlist_3, "主题一\n主题二");
	lv_obj_add_event_cb(ui->settings_ddlist_3, _settings_ddlist_3_event_cb, LV_EVENT_READY, NULL);

	//Write style state: LV_STATE_DEFAULT for style_settings_ddlist_3_main_main_default
	static lv_style_t style_settings_ddlist_3_main_main_default;
	if (style_settings_ddlist_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_ddlist_3_main_main_default);
	else
		lv_style_init(&style_settings_ddlist_3_main_main_default);
	lv_style_set_radius(&style_settings_ddlist_3_main_main_default, 2);
	lv_style_set_bg_color(&style_settings_ddlist_3_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_settings_ddlist_3_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_settings_ddlist_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_ddlist_3_main_main_default, 255);
	lv_style_set_border_color(&style_settings_ddlist_3_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_settings_ddlist_3_main_main_default, 1);
	lv_style_set_text_color(&style_settings_ddlist_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_ddlist_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_line_space(&style_settings_ddlist_3_main_main_default, 20);
	lv_obj_add_style(ui->settings_ddlist_3, &style_settings_ddlist_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_sw_1
	ui->settings_sw_1 = lv_switch_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_sw_1, 384, 112);
	lv_obj_set_size(ui->settings_sw_1, 74, 36);

	//Write style state: LV_STATE_DEFAULT for style_settings_sw_1_main_main_default
	static lv_style_t style_settings_sw_1_main_main_default;
	if (style_settings_sw_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_sw_1_main_main_default);
	else
		lv_style_init(&style_settings_sw_1_main_main_default);
	lv_style_set_radius(&style_settings_sw_1_main_main_default, 100);
	lv_style_set_bg_color(&style_settings_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_color(&style_settings_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_dir(&style_settings_sw_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_sw_1_main_main_default, 255);
	lv_obj_add_style(ui->settings_sw_1, &style_settings_sw_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_sw_1_main_indicator_checked
	static lv_style_t style_settings_sw_1_main_indicator_checked;
	if (style_settings_sw_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_sw_1_main_indicator_checked);
	else
		lv_style_init(&style_settings_sw_1_main_indicator_checked);
	lv_style_set_radius(&style_settings_sw_1_main_indicator_checked, 100);
	lv_style_set_bg_color(&style_settings_sw_1_main_indicator_checked, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_sw_1_main_indicator_checked, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_sw_1_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_sw_1_main_indicator_checked, 255);
	lv_obj_add_style(ui->settings_sw_1, &style_settings_sw_1_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_settings_sw_1_main_knob_default
	static lv_style_t style_settings_sw_1_main_knob_default;
	if (style_settings_sw_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_settings_sw_1_main_knob_default);
	else
		lv_style_init(&style_settings_sw_1_main_knob_default);
	lv_style_set_radius(&style_settings_sw_1_main_knob_default, 100);
	lv_style_set_bg_color(&style_settings_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_sw_1_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_sw_1_main_knob_default, 255);
	lv_obj_add_style(ui->settings_sw_1, &style_settings_sw_1_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes settings_slider_1
	ui->settings_slider_1 = lv_slider_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_slider_1, 275, 50);
	lv_obj_set_size(ui->settings_slider_1, 142, 8);

	//Write style state: LV_STATE_DEFAULT for style_settings_slider_1_main_main_default
	static lv_style_t style_settings_slider_1_main_main_default;
	if (style_settings_slider_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_slider_1_main_main_default);
	else
		lv_style_init(&style_settings_slider_1_main_main_default);
	lv_style_set_radius(&style_settings_slider_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_slider_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_color(&style_settings_slider_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_dir(&style_settings_slider_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_slider_1_main_main_default, 255);
	lv_style_set_outline_color(&style_settings_slider_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_settings_slider_1_main_main_default, 0);
	lv_style_set_outline_opa(&style_settings_slider_1_main_main_default, 255);
	lv_style_set_pad_left(&style_settings_slider_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_slider_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_slider_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_slider_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_slider_1, &style_settings_slider_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_slider_1_main_indicator_default
	static lv_style_t style_settings_slider_1_main_indicator_default;
	if (style_settings_slider_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_slider_1_main_indicator_default);
	else
		lv_style_init(&style_settings_slider_1_main_indicator_default);
	lv_style_set_radius(&style_settings_slider_1_main_indicator_default, 0);
	lv_style_set_bg_color(&style_settings_slider_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_slider_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_slider_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_slider_1_main_indicator_default, 255);
	lv_obj_add_style(ui->settings_slider_1, &style_settings_slider_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_slider_1_main_knob_default
	static lv_style_t style_settings_slider_1_main_knob_default;
	if (style_settings_slider_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_settings_slider_1_main_knob_default);
	else
		lv_style_init(&style_settings_slider_1_main_knob_default);
	lv_style_set_radius(&style_settings_slider_1_main_knob_default, 0);
	lv_style_set_bg_color(&style_settings_slider_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_slider_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_slider_1_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_slider_1_main_knob_default, 255);
	lv_obj_add_style(ui->settings_slider_1, &style_settings_slider_1_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->settings_slider_1,0, 100);
	lv_slider_set_value(ui->settings_slider_1,50,false);

	//Write codes settings_img_1
	ui->settings_img_1 = lv_img_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_img_1, 231, 35);
	lv_obj_set_size(ui->settings_img_1, 38, 38);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_1_main_main_default
	static lv_style_t style_settings_img_1_main_main_default;
	if (style_settings_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_1_main_main_default);
	else
		lv_style_init(&style_settings_img_1_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_1_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_1, &style_settings_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_1,&_group_609_38x38);
	lv_img_set_pivot(ui->settings_img_1, 0,0);
	lv_img_set_angle(ui->settings_img_1, 0);

	//Write codes settings_label_9
	ui->settings_label_9 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_9, 25, 340);
	lv_obj_set_size(ui->settings_label_9, 270, 28);
	lv_label_set_text(ui->settings_label_9, "时区设置");
	lv_label_set_long_mode(ui->settings_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_9, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_9_main_main_default
	static lv_style_t style_settings_label_9_main_main_default;
	if (style_settings_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_9_main_main_default);
	else
		lv_style_init(&style_settings_label_9_main_main_default);
	lv_style_set_radius(&style_settings_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_9_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_9_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_9, &style_settings_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_img_3
	ui->settings_img_3 = lv_img_create(ui->settings_tabview_1_title1);
	lv_obj_set_size(ui->settings_img_3, 14, 28);
	lv_obj_align_to(ui->settings_img_3,ui->settings_label_9,LV_ALIGN_RIGHT_MID,148,0);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_3_main_main_default
	static lv_style_t style_settings_img_3_main_main_default;
	if (style_settings_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_3_main_main_default);
	else
		lv_style_init(&style_settings_img_3_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_3_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_3, &style_settings_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_3,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_img_3, 0,0);
	lv_img_set_angle(ui->settings_img_3, 0);

	//Write codes settings_label_10
	ui->settings_label_10 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_10, 25, 416);
	lv_obj_set_size(ui->settings_label_10, 270, 28);
	lv_label_set_text(ui->settings_label_10, "按键音");
	lv_label_set_long_mode(ui->settings_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_10, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_10_main_main_default
	static lv_style_t style_settings_label_10_main_main_default;
	if (style_settings_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_10_main_main_default);
	else
		lv_style_init(&style_settings_label_10_main_main_default);
	lv_style_set_radius(&style_settings_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_10_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_10_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_10, &style_settings_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_12
	ui->settings_label_12 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_12, 25, 568);
	lv_obj_set_size(ui->settings_label_12, 270, 28);
	lv_label_set_text(ui->settings_label_12, "设备绑定");
	lv_label_set_long_mode(ui->settings_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_12, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_12_main_main_default
	static lv_style_t style_settings_label_12_main_main_default;
	if (style_settings_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_12_main_main_default);
	else
		lv_style_init(&style_settings_label_12_main_main_default);
	lv_style_set_radius(&style_settings_label_12_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_12_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_12_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_12_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_12_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_12, &style_settings_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_13
	ui->settings_label_13 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_13, 25, 644);
	lv_obj_set_size(ui->settings_label_13, 270, 28);
	lv_label_set_text(ui->settings_label_13, "导出日志");
	lv_label_set_long_mode(ui->settings_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_13, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_13_main_main_default
	static lv_style_t style_settings_label_13_main_main_default;
	if (style_settings_label_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_13_main_main_default);
	else
		lv_style_init(&style_settings_label_13_main_main_default);
	lv_style_set_radius(&style_settings_label_13_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_13_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_13_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_13_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_13_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_13_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_13_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_13_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_13_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_13, &style_settings_label_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_14
	ui->settings_label_14 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_14, 25, 720);
	lv_obj_set_size(ui->settings_label_14, 270, 28);
	lv_label_set_text(ui->settings_label_14, "版本检测");
	lv_label_set_long_mode(ui->settings_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_14, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_14_main_main_default
	static lv_style_t style_settings_label_14_main_main_default;
	if (style_settings_label_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_14_main_main_default);
	else
		lv_style_init(&style_settings_label_14_main_main_default);
	lv_style_set_radius(&style_settings_label_14_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_14_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_14_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_14_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_14_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_14_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_14_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_14_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_14_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_14_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_14, &style_settings_label_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_15
	ui->settings_label_15 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_15, 26, 796);
	lv_obj_set_size(ui->settings_label_15, 270, 28);
	lv_label_set_text(ui->settings_label_15, "关于本机");
	lv_label_set_long_mode(ui->settings_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_15, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_15_main_main_default
	static lv_style_t style_settings_label_15_main_main_default;
	if (style_settings_label_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_15_main_main_default);
	else
		lv_style_init(&style_settings_label_15_main_main_default);
	lv_style_set_radius(&style_settings_label_15_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_15_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_15_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_15_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_15_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_15_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_15_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_15_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_15_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_15_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_15, &style_settings_label_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_16
	ui->settings_label_16 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_16, 25, 872);
	lv_obj_set_size(ui->settings_label_16, 270, 28);
	lv_label_set_text(ui->settings_label_16, "恢复出厂");
	lv_label_set_long_mode(ui->settings_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_16, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_16_main_main_default
	static lv_style_t style_settings_label_16_main_main_default;
	if (style_settings_label_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_16_main_main_default);
	else
		lv_style_init(&style_settings_label_16_main_main_default);
	lv_style_set_radius(&style_settings_label_16_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_16_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_16_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_16_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_16_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_16_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_16_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_16_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_16_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_16_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_16, &style_settings_label_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_img_4
	ui->settings_img_4 = lv_img_create(ui->settings_tabview_1_title1);
	lv_obj_set_size(ui->settings_img_4, 14, 28);
	lv_obj_align_to(ui->settings_img_4,ui->settings_label_10,LV_ALIGN_RIGHT_MID,148,0);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_4_main_main_default
	static lv_style_t style_settings_img_4_main_main_default;
	if (style_settings_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_4_main_main_default);
	else
		lv_style_init(&style_settings_img_4_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_4_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_4, &style_settings_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_4,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_img_4, 0,0);
	lv_img_set_angle(ui->settings_img_4, 0);

	//Write codes settings_img_5
	ui->settings_img_5 = lv_img_create(ui->settings_tabview_1_title1);
	lv_obj_set_size(ui->settings_img_5, 14, 28);
	lv_obj_align_to(ui->settings_img_5,ui->settings_label_12,LV_ALIGN_RIGHT_MID,148,0);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_5_main_main_default
	static lv_style_t style_settings_img_5_main_main_default;
	if (style_settings_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_5_main_main_default);
	else
		lv_style_init(&style_settings_img_5_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_5_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_5, &style_settings_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_5,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_img_5, 0,0);
	lv_img_set_angle(ui->settings_img_5, 0);

	//Write codes settings_img_6
	ui->settings_img_6 = lv_img_create(ui->settings_tabview_1_title1);
	lv_obj_set_size(ui->settings_img_6, 14, 28);
	lv_obj_align_to(ui->settings_img_6,ui->settings_label_13,LV_ALIGN_RIGHT_MID,148,0);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_6_main_main_default
	static lv_style_t style_settings_img_6_main_main_default;
	if (style_settings_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_6_main_main_default);
	else
		lv_style_init(&style_settings_img_6_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_6_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_6, &style_settings_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_6,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_img_6, 0,0);
	lv_img_set_angle(ui->settings_img_6, 0);

	//Write codes settings_img_7
	ui->settings_img_7 = lv_img_create(ui->settings_tabview_1_title1);
	lv_obj_set_size(ui->settings_img_7, 14, 28);
	lv_obj_align_to(ui->settings_img_7,ui->settings_label_14,LV_ALIGN_RIGHT_MID,148,0);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_7_main_main_default
	static lv_style_t style_settings_img_7_main_main_default;
	if (style_settings_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_7_main_main_default);
	else
		lv_style_init(&style_settings_img_7_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_7_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_7, &style_settings_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_7,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_img_7, 0,0);
	lv_img_set_angle(ui->settings_img_7, 0);

	ui->settings_img_7_btn = lv_btn_create(ui->settings_tabview_1_title1);
	lv_obj_set_size(ui->settings_img_7_btn, 100, 60);
	lv_obj_align_to(ui->settings_img_7_btn,ui->settings_img_7,LV_ALIGN_RIGHT_MID,0,0);
	lv_obj_add_style(ui->settings_img_7_btn, &btnstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_img_8
	ui->settings_img_8 = lv_img_create(ui->settings_tabview_1_title1);
	lv_obj_set_size(ui->settings_img_8, 14, 28);
	lv_obj_align_to(ui->settings_img_8,ui->settings_label_15,LV_ALIGN_RIGHT_MID,148,0);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_8_main_main_default
	static lv_style_t style_settings_img_8_main_main_default;
	if (style_settings_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_8_main_main_default);
	else
		lv_style_init(&style_settings_img_8_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_8_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_8, &style_settings_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_8,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_img_8, 0,0);
	lv_img_set_angle(ui->settings_img_8, 0);

	//Write codes settings_img_9
	ui->settings_img_20 = lv_img_create(ui->settings_tabview_1_title1);
	lv_obj_set_size(ui->settings_img_20, 14, 28);
	lv_obj_align_to(ui->settings_img_20,ui->settings_label_16,LV_ALIGN_RIGHT_MID,148,0);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_8_main_main_default
	static lv_style_t style_settings_img_20_main_main_default;
	if (style_settings_img_20_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_20_main_main_default);
	else
		lv_style_init(&style_settings_img_20_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_20_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_20_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_20_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_20, &style_settings_img_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_20, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_20,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_img_20, 0,0);
	lv_img_set_angle(ui->settings_img_20, 0);

	//Write codes settings_img_2
	ui->settings_img_2 = lv_img_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_img_2, 424, 35);
	lv_obj_set_size(ui->settings_img_2, 38, 38);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_2_main_main_default
	static lv_style_t style_settings_img_2_main_main_default;
	if (style_settings_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_2_main_main_default);
	else
		lv_style_init(&style_settings_img_2_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_2_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_2, &style_settings_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_2,&_group_609_1_38x38);
	lv_img_set_pivot(ui->settings_img_2, 0,0);
	lv_img_set_angle(ui->settings_img_2, 0);

	//Write codes settings_label_5
	ui->settings_label_5 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_5, 24, 36);
	lv_obj_set_size(ui->settings_label_5, 100, 28);
	lv_label_set_text(ui->settings_label_5, "屏幕亮度");
	lv_label_set_long_mode(ui->settings_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_5_main_main_default
	static lv_style_t style_settings_label_5_main_main_default;
	if (style_settings_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_5_main_main_default);
	else
		lv_style_init(&style_settings_label_5_main_main_default);
	lv_style_set_radius(&style_settings_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_5_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_5, &style_settings_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_6
	ui->settings_label_6 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_6, 25, 112);
	lv_obj_set_size(ui->settings_label_6, 200, 28);
	lv_label_set_text(ui->settings_label_6, "全屏模式");
	lv_label_set_long_mode(ui->settings_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_6_main_main_default
	static lv_style_t style_settings_label_6_main_main_default;
	if (style_settings_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_6_main_main_default);
	else
		lv_style_init(&style_settings_label_6_main_main_default);
	lv_style_set_radius(&style_settings_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_6_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_6, &style_settings_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_7
	ui->settings_label_7 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_7, 25, 188);
	lv_obj_set_size(ui->settings_label_7, 200, 28);
	lv_label_set_text(ui->settings_label_7, "息屏");
	lv_label_set_long_mode(ui->settings_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_7_main_main_default
	static lv_style_t style_settings_label_7_main_main_default;
	if (style_settings_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_7_main_main_default);
	else
		lv_style_init(&style_settings_label_7_main_main_default);
	lv_style_set_radius(&style_settings_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_7_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_7, &style_settings_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_8
	ui->settings_label_8 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_8, 25, 264);
	lv_obj_set_size(ui->settings_label_8, 150, 28);
	lv_label_set_text(ui->settings_label_8, "语言选择");
	lv_label_set_long_mode(ui->settings_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_8_main_main_default
	static lv_style_t style_settings_label_8_main_main_default;
	if (style_settings_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_8_main_main_default);
	else
		lv_style_init(&style_settings_label_8_main_main_default);
	lv_style_set_radius(&style_settings_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_8_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_8, &style_settings_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_11
	ui->settings_label_11 = lv_label_create(ui->settings_tabview_1_title1);
	lv_obj_set_pos(ui->settings_label_11, 25, 492);
	lv_obj_set_size(ui->settings_label_11, 270, 28);
	lv_label_set_text(ui->settings_label_11, "主题");
	lv_label_set_long_mode(ui->settings_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_11, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_11_main_main_default
	static lv_style_t style_settings_label_11_main_main_default;
	if (style_settings_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_11_main_main_default);
	else
		lv_style_init(&style_settings_label_11_main_main_default);
	lv_style_set_radius(&style_settings_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_11_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_11_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_11_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_11, &style_settings_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_2
	ui->settings_label_2 = lv_label_create(ui->settings_tabview_1_title2);
	lv_obj_set_pos(ui->settings_label_2, 9, 9);
	lv_obj_set_size(ui->settings_label_2, 460, 648);
	lv_label_set_text(ui->settings_label_2, "");
	lv_label_set_long_mode(ui->settings_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_2_main_main_default
	static lv_style_t style_settings_label_2_main_main_default;
	if (style_settings_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_2_main_main_default);
	else
		lv_style_init(&style_settings_label_2_main_main_default);
	lv_style_set_radius(&style_settings_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_settings_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_settings_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_2_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_2, &style_settings_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_list_1
	ui->settings_list_1 = lv_list_create(ui->settings_tabview_1_title2);
	lv_obj_set_pos(ui->settings_list_1, 25, 23);
	lv_obj_set_size(ui->settings_list_1, 435, 620);

	//Write style state: LV_STATE_DEFAULT for style_settings_list_1_main_main_default
	static lv_style_t style_settings_list_1_main_main_default;
	if (style_settings_list_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_list_1_main_main_default);
	else
		lv_style_init(&style_settings_list_1_main_main_default);
	lv_style_set_radius(&style_settings_list_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_list_1_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_list_1_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_list_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_list_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_list_1_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_list_1_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_list_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_list_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_list_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_list_1, &style_settings_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

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

	//Write style state: LV_STATE_DEFAULT for style_settings_list_1_extra_btns_main_default
	static lv_style_t style_settings_list_1_extra_btns_main_default;
	if (style_settings_list_1_extra_btns_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_list_1_extra_btns_main_default);
	else
		lv_style_init(&style_settings_list_1_extra_btns_main_default);
	lv_style_set_radius(&style_settings_list_1_extra_btns_main_default, 3);
	lv_style_set_bg_color(&style_settings_list_1_extra_btns_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_list_1_extra_btns_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_list_1_extra_btns_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_list_1_extra_btns_main_default, 255);
	lv_style_set_text_color(&style_settings_list_1_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_list_1_extra_btns_main_default, &lv_font_simsun_24);
	lv_obj_t *settings_list_1_btn;
	settings_list_1_btn = lv_list_add_btn(ui->settings_list_1, LV_SYMBOL_GPS, "网络连接");
    ui->settings_label_31 = lv_label_create(settings_list_1_btn);
    lv_label_set_text(ui->settings_label_31,"已连接");
	lv_obj_set_size(ui->settings_label_31, 88, 33);
	lv_obj_align(ui->settings_label_31,LV_ALIGN_CENTER,0,0);

	ui->settings_list_1_item0 = settings_list_1_btn;
	lv_obj_add_style(settings_list_1_btn, &style_settings_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_3
	ui->settings_label_3 = lv_label_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_label_3, 8, 9);
	lv_obj_set_size(ui->settings_label_3, 460, 648);
	lv_label_set_text(ui->settings_label_3, "");
	lv_label_set_long_mode(ui->settings_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_3_main_main_default
	static lv_style_t style_settings_label_3_main_main_default;
	if (style_settings_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_3_main_main_default);
	else
		lv_style_init(&style_settings_label_3_main_main_default);
	lv_style_set_radius(&style_settings_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_settings_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_settings_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_3_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_3, &style_settings_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_cb_1
	ui->settings_cb_1 = lv_checkbox_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_cb_1, 26, 102);
	lv_checkbox_set_text(ui->settings_cb_1, "开启喉管散热风扇");

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_1_main_main_default
	static lv_style_t style_settings_cb_1_main_main_default;
	if (style_settings_cb_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_1_main_main_default);
	else
		lv_style_init(&style_settings_cb_1_main_main_default);
	lv_style_set_radius(&style_settings_cb_1_main_main_default, 6);
	lv_style_set_bg_color(&style_settings_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_cb_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_1_main_main_default, 0);
	lv_style_set_text_color(&style_settings_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_cb_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_cb_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_cb_1, &style_settings_cb_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_1_main_indicator_default
	static lv_style_t style_settings_cb_1_main_indicator_default;
	if (style_settings_cb_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_1_main_indicator_default);
	else
		lv_style_init(&style_settings_cb_1_main_indicator_default);
	lv_style_set_radius(&style_settings_cb_1_main_indicator_default, 2);
	lv_style_set_bg_color(&style_settings_cb_1_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_1_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_1_main_indicator_default, 255);
	lv_style_set_border_color(&style_settings_cb_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_1_main_indicator_default, 1);
	lv_obj_add_style(ui->settings_cb_1, &style_settings_cb_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_cb_1_main_indicator_checked
	static lv_style_t style_settings_cb_1_main_indicator_checked;
	if (style_settings_cb_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_1_main_indicator_checked);
	else
		lv_style_init(&style_settings_cb_1_main_indicator_checked);
	lv_style_set_radius(&style_settings_cb_1_main_indicator_checked, 2);
	lv_style_set_bg_color(&style_settings_cb_1_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_1_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_1_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_1_main_indicator_checked, 255);
	lv_style_set_border_color(&style_settings_cb_1_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_1_main_indicator_checked, 1);
	lv_obj_add_style(ui->settings_cb_1, &style_settings_cb_1_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_cb_2
	ui->settings_cb_2 = lv_checkbox_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_cb_2, 26, 181);
	lv_checkbox_set_text(ui->settings_cb_2, "开启模型冷却风扇");

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_2_main_main_default
	static lv_style_t style_settings_cb_2_main_main_default;
	if (style_settings_cb_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_2_main_main_default);
	else
		lv_style_init(&style_settings_cb_2_main_main_default);
	lv_style_set_radius(&style_settings_cb_2_main_main_default, 6);
	lv_style_set_bg_color(&style_settings_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_cb_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_2_main_main_default, 0);
	lv_style_set_text_color(&style_settings_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_cb_2_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_cb_2_main_main_default, 0);
	lv_obj_add_style(ui->settings_cb_2, &style_settings_cb_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_2_main_indicator_default
	static lv_style_t style_settings_cb_2_main_indicator_default;
	if (style_settings_cb_2_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_2_main_indicator_default);
	else
		lv_style_init(&style_settings_cb_2_main_indicator_default);
	lv_style_set_radius(&style_settings_cb_2_main_indicator_default, 2);
	lv_style_set_bg_color(&style_settings_cb_2_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_2_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_2_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_2_main_indicator_default, 255);
	lv_style_set_border_color(&style_settings_cb_2_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_2_main_indicator_default, 1);
	lv_obj_add_style(ui->settings_cb_2, &style_settings_cb_2_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_cb_2_main_indicator_checked
	static lv_style_t style_settings_cb_2_main_indicator_checked;
	if (style_settings_cb_2_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_2_main_indicator_checked);
	else
		lv_style_init(&style_settings_cb_2_main_indicator_checked);
	lv_style_set_radius(&style_settings_cb_2_main_indicator_checked, 2);
	lv_style_set_bg_color(&style_settings_cb_2_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_2_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_2_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_2_main_indicator_checked, 255);
	lv_style_set_border_color(&style_settings_cb_2_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_2_main_indicator_checked, 1);
	lv_obj_add_style(ui->settings_cb_2, &style_settings_cb_2_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_cb_3
	ui->settings_cb_3 = lv_checkbox_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_cb_3, 26, 258);
	lv_checkbox_set_text(ui->settings_cb_3, "喷头PID校准");

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_3_main_main_default
	static lv_style_t style_settings_cb_3_main_main_default;
	if (style_settings_cb_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_3_main_main_default);
	else
		lv_style_init(&style_settings_cb_3_main_main_default);
	lv_style_set_radius(&style_settings_cb_3_main_main_default, 6);
	lv_style_set_bg_color(&style_settings_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_cb_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_3_main_main_default, 0);
	lv_style_set_text_color(&style_settings_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_cb_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_cb_3_main_main_default, 0);
	lv_obj_add_style(ui->settings_cb_3, &style_settings_cb_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_3_main_indicator_default
	static lv_style_t style_settings_cb_3_main_indicator_default;
	if (style_settings_cb_3_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_3_main_indicator_default);
	else
		lv_style_init(&style_settings_cb_3_main_indicator_default);
	lv_style_set_radius(&style_settings_cb_3_main_indicator_default, 2);
	lv_style_set_bg_color(&style_settings_cb_3_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_3_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_3_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_3_main_indicator_default, 255);
	lv_style_set_border_color(&style_settings_cb_3_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_3_main_indicator_default, 1);
	lv_obj_add_style(ui->settings_cb_3, &style_settings_cb_3_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_cb_3_main_indicator_checked
	static lv_style_t style_settings_cb_3_main_indicator_checked;
	if (style_settings_cb_3_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_3_main_indicator_checked);
	else
		lv_style_init(&style_settings_cb_3_main_indicator_checked);
	lv_style_set_radius(&style_settings_cb_3_main_indicator_checked, 2);
	lv_style_set_bg_color(&style_settings_cb_3_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_3_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_3_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_3_main_indicator_checked, 255);
	lv_style_set_border_color(&style_settings_cb_3_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_3_main_indicator_checked, 1);
	lv_obj_add_style(ui->settings_cb_3, &style_settings_cb_3_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_cb_4
	ui->settings_cb_4 = lv_checkbox_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_cb_4, 26, 339);
	lv_checkbox_set_text(ui->settings_cb_4, "热床PID校准");

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_4_main_main_default
	static lv_style_t style_settings_cb_4_main_main_default;
	if (style_settings_cb_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_4_main_main_default);
	else
		lv_style_init(&style_settings_cb_4_main_main_default);
	lv_style_set_radius(&style_settings_cb_4_main_main_default, 6);
	lv_style_set_bg_color(&style_settings_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_cb_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_4_main_main_default, 0);
	lv_style_set_text_color(&style_settings_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_cb_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_cb_4_main_main_default, 0);
	lv_obj_add_style(ui->settings_cb_4, &style_settings_cb_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_4_main_indicator_default
	static lv_style_t style_settings_cb_4_main_indicator_default;
	if (style_settings_cb_4_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_4_main_indicator_default);
	else
		lv_style_init(&style_settings_cb_4_main_indicator_default);
	lv_style_set_radius(&style_settings_cb_4_main_indicator_default, 2);
	lv_style_set_bg_color(&style_settings_cb_4_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_4_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_4_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_4_main_indicator_default, 255);
	lv_style_set_border_color(&style_settings_cb_4_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_4_main_indicator_default, 1);
	lv_obj_add_style(ui->settings_cb_4, &style_settings_cb_4_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_cb_4_main_indicator_checked
	static lv_style_t style_settings_cb_4_main_indicator_checked;
	if (style_settings_cb_4_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_4_main_indicator_checked);
	else
		lv_style_init(&style_settings_cb_4_main_indicator_checked);
	lv_style_set_radius(&style_settings_cb_4_main_indicator_checked, 2);
	lv_style_set_bg_color(&style_settings_cb_4_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_4_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_4_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_4_main_indicator_checked, 255);
	lv_style_set_border_color(&style_settings_cb_4_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_4_main_indicator_checked, 1);
	lv_obj_add_style(ui->settings_cb_4, &style_settings_cb_4_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_cb_5
	ui->settings_cb_5 = lv_checkbox_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_cb_5, 26, 418);
	lv_checkbox_set_text(ui->settings_cb_5, "振动补偿");

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_5_main_main_default
	static lv_style_t style_settings_cb_5_main_main_default;
	if (style_settings_cb_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_5_main_main_default);
	else
		lv_style_init(&style_settings_cb_5_main_main_default);
	lv_style_set_radius(&style_settings_cb_5_main_main_default, 6);
	lv_style_set_bg_color(&style_settings_cb_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_cb_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_cb_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_5_main_main_default, 0);
	lv_style_set_text_color(&style_settings_cb_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_cb_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_cb_5_main_main_default, 0);
	lv_obj_add_style(ui->settings_cb_5, &style_settings_cb_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_5_main_indicator_default
	static lv_style_t style_settings_cb_5_main_indicator_default;
	if (style_settings_cb_5_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_5_main_indicator_default);
	else
		lv_style_init(&style_settings_cb_5_main_indicator_default);
	lv_style_set_radius(&style_settings_cb_5_main_indicator_default, 2);
	lv_style_set_bg_color(&style_settings_cb_5_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_5_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_5_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_5_main_indicator_default, 255);
	lv_style_set_border_color(&style_settings_cb_5_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_5_main_indicator_default, 1);
	lv_obj_add_style(ui->settings_cb_5, &style_settings_cb_5_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_cb_5_main_indicator_checked
	static lv_style_t style_settings_cb_5_main_indicator_checked;
	if (style_settings_cb_5_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_5_main_indicator_checked);
	else
		lv_style_init(&style_settings_cb_5_main_indicator_checked);
	lv_style_set_radius(&style_settings_cb_5_main_indicator_checked, 2);
	lv_style_set_bg_color(&style_settings_cb_5_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_5_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_5_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_5_main_indicator_checked, 255);
	lv_style_set_border_color(&style_settings_cb_5_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_5_main_indicator_checked, 1);
	lv_obj_add_style(ui->settings_cb_5, &style_settings_cb_5_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_cb_6
	ui->settings_cb_6 = lv_checkbox_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_cb_6, 275, 102);
	lv_checkbox_set_text(ui->settings_cb_6, "归位检测");

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_6_main_main_default
	static lv_style_t style_settings_cb_6_main_main_default;
	if (style_settings_cb_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_6_main_main_default);
	else
		lv_style_init(&style_settings_cb_6_main_main_default);
	lv_style_set_radius(&style_settings_cb_6_main_main_default, 6);
	lv_style_set_bg_color(&style_settings_cb_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_cb_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_cb_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_6_main_main_default, 0);
	lv_style_set_text_color(&style_settings_cb_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_cb_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_cb_6_main_main_default, 0);
	lv_obj_add_style(ui->settings_cb_6, &style_settings_cb_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_6_main_indicator_default
	static lv_style_t style_settings_cb_6_main_indicator_default;
	if (style_settings_cb_6_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_6_main_indicator_default);
	else
		lv_style_init(&style_settings_cb_6_main_indicator_default);
	lv_style_set_radius(&style_settings_cb_6_main_indicator_default, 2);
	lv_style_set_bg_color(&style_settings_cb_6_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_6_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_6_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_6_main_indicator_default, 255);
	lv_style_set_border_color(&style_settings_cb_6_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_6_main_indicator_default, 1);
	lv_obj_add_style(ui->settings_cb_6, &style_settings_cb_6_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_cb_6_main_indicator_checked
	static lv_style_t style_settings_cb_6_main_indicator_checked;
	if (style_settings_cb_6_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_6_main_indicator_checked);
	else
		lv_style_init(&style_settings_cb_6_main_indicator_checked);
	lv_style_set_radius(&style_settings_cb_6_main_indicator_checked, 2);
	lv_style_set_bg_color(&style_settings_cb_6_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_6_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_6_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_6_main_indicator_checked, 255);
	lv_style_set_border_color(&style_settings_cb_6_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_6_main_indicator_checked, 1);
	lv_obj_add_style(ui->settings_cb_6, &style_settings_cb_6_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_cb_7
	ui->settings_cb_7 = lv_checkbox_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_cb_7, 275, 181);
	lv_checkbox_set_text(ui->settings_cb_7, "探头检测");

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_7_main_main_default
	static lv_style_t style_settings_cb_7_main_main_default;
	if (style_settings_cb_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_7_main_main_default);
	else
		lv_style_init(&style_settings_cb_7_main_main_default);
	lv_style_set_radius(&style_settings_cb_7_main_main_default, 6);
	lv_style_set_bg_color(&style_settings_cb_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_cb_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_cb_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_7_main_main_default, 0);
	lv_style_set_text_color(&style_settings_cb_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_cb_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_cb_7_main_main_default, 0);
	lv_obj_add_style(ui->settings_cb_7, &style_settings_cb_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_7_main_indicator_default
	static lv_style_t style_settings_cb_7_main_indicator_default;
	if (style_settings_cb_7_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_7_main_indicator_default);
	else
		lv_style_init(&style_settings_cb_7_main_indicator_default);
	lv_style_set_radius(&style_settings_cb_7_main_indicator_default, 2);
	lv_style_set_bg_color(&style_settings_cb_7_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_7_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_7_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_7_main_indicator_default, 255);
	lv_style_set_border_color(&style_settings_cb_7_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_7_main_indicator_default, 1);
	lv_obj_add_style(ui->settings_cb_7, &style_settings_cb_7_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_cb_7_main_indicator_checked
	static lv_style_t style_settings_cb_7_main_indicator_checked;
	if (style_settings_cb_7_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_7_main_indicator_checked);
	else
		lv_style_init(&style_settings_cb_7_main_indicator_checked);
	lv_style_set_radius(&style_settings_cb_7_main_indicator_checked, 2);
	lv_style_set_bg_color(&style_settings_cb_7_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_7_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_7_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_7_main_indicator_checked, 255);
	lv_style_set_border_color(&style_settings_cb_7_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_7_main_indicator_checked, 1);
	lv_obj_add_style(ui->settings_cb_7, &style_settings_cb_7_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_cb_8
	ui->settings_cb_8 = lv_checkbox_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_cb_8, 275, 258);
	lv_checkbox_set_text(ui->settings_cb_8, "断料检测");

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_8_main_main_default
	static lv_style_t style_settings_cb_8_main_main_default;
	if (style_settings_cb_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_8_main_main_default);
	else
		lv_style_init(&style_settings_cb_8_main_main_default);
	lv_style_set_radius(&style_settings_cb_8_main_main_default, 6);
	lv_style_set_bg_color(&style_settings_cb_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_cb_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_cb_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_8_main_main_default, 0);
	lv_style_set_text_color(&style_settings_cb_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_cb_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_cb_8_main_main_default, 0);
	lv_obj_add_style(ui->settings_cb_8, &style_settings_cb_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_8_main_indicator_default
	static lv_style_t style_settings_cb_8_main_indicator_default;
	if (style_settings_cb_8_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_8_main_indicator_default);
	else
		lv_style_init(&style_settings_cb_8_main_indicator_default);
	lv_style_set_radius(&style_settings_cb_8_main_indicator_default, 2);
	lv_style_set_bg_color(&style_settings_cb_8_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_8_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_8_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_8_main_indicator_default, 255);
	lv_style_set_border_color(&style_settings_cb_8_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_8_main_indicator_default, 1);
	lv_obj_add_style(ui->settings_cb_8, &style_settings_cb_8_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_cb_8_main_indicator_checked
	static lv_style_t style_settings_cb_8_main_indicator_checked;
	if (style_settings_cb_8_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_8_main_indicator_checked);
	else
		lv_style_init(&style_settings_cb_8_main_indicator_checked);
	lv_style_set_radius(&style_settings_cb_8_main_indicator_checked, 2);
	lv_style_set_bg_color(&style_settings_cb_8_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_8_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_8_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_8_main_indicator_checked, 255);
	lv_style_set_border_color(&style_settings_cb_8_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_8_main_indicator_checked, 1);
	lv_obj_add_style(ui->settings_cb_8, &style_settings_cb_8_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_cb_9
	ui->settings_cb_9 = lv_checkbox_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_cb_9, 275, 339);
	lv_checkbox_set_text(ui->settings_cb_9, "自动调平");

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_9_main_main_default
	static lv_style_t style_settings_cb_9_main_main_default;
	if (style_settings_cb_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_9_main_main_default);
	else
		lv_style_init(&style_settings_cb_9_main_main_default);
	lv_style_set_radius(&style_settings_cb_9_main_main_default, 6);
	lv_style_set_bg_color(&style_settings_cb_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_cb_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_cb_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_9_main_main_default, 0);
	lv_style_set_text_color(&style_settings_cb_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_cb_9_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_cb_9_main_main_default, 0);
	lv_obj_add_style(ui->settings_cb_9, &style_settings_cb_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_cb_9_main_indicator_default
	static lv_style_t style_settings_cb_9_main_indicator_default;
	if (style_settings_cb_9_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_9_main_indicator_default);
	else
		lv_style_init(&style_settings_cb_9_main_indicator_default);
	lv_style_set_radius(&style_settings_cb_9_main_indicator_default, 2);
	lv_style_set_bg_color(&style_settings_cb_9_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_9_main_indicator_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_9_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_9_main_indicator_default, 255);
	lv_style_set_border_color(&style_settings_cb_9_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_9_main_indicator_default, 1);
	lv_obj_add_style(ui->settings_cb_9, &style_settings_cb_9_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_cb_9_main_indicator_checked
	static lv_style_t style_settings_cb_9_main_indicator_checked;
	if (style_settings_cb_9_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_cb_9_main_indicator_checked);
	else
		lv_style_init(&style_settings_cb_9_main_indicator_checked);
	lv_style_set_radius(&style_settings_cb_9_main_indicator_checked, 2);
	lv_style_set_bg_color(&style_settings_cb_9_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_cb_9_main_indicator_checked, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_cb_9_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_cb_9_main_indicator_checked, 255);
	lv_style_set_border_color(&style_settings_cb_9_main_indicator_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_settings_cb_9_main_indicator_checked, 1);
	lv_obj_add_style(ui->settings_cb_9, &style_settings_cb_9_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write codes settings_btn_1
	ui->settings_btn_1 = lv_btn_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_btn_1, 356, 26);
	lv_obj_set_size(ui->settings_btn_1, 100, 33);

	//Write style state: LV_STATE_DEFAULT for style_settings_btn_1_main_main_default
	static lv_style_t style_settings_btn_1_main_main_default;
	if (style_settings_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_btn_1_main_main_default);
	else
		lv_style_init(&style_settings_btn_1_main_main_default);
	lv_style_set_radius(&style_settings_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_settings_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_settings_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_settings_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->settings_btn_1, &style_settings_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->settings_btn_1_label = lv_label_create(ui->settings_btn_1);
	lv_label_set_text(ui->settings_btn_1_label, "全选");
	lv_obj_set_style_text_color(ui->settings_btn_1_label, lv_color_make(0x42, 0xbd, 0xd8), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->settings_btn_1_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->settings_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->settings_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes settings_btn_2
	ui->settings_btn_2 = lv_btn_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_btn_2, 27, 573);
	lv_obj_set_size(ui->settings_btn_2, 426, 65);

	//Write style state: LV_STATE_DEFAULT for style_settings_btn_2_main_main_default
	static lv_style_t style_settings_btn_2_main_main_default;
	if (style_settings_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_btn_2_main_main_default);
	else
		lv_style_init(&style_settings_btn_2_main_main_default);
	lv_style_set_radius(&style_settings_btn_2_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_settings_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_settings_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_settings_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->settings_btn_2, &style_settings_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->settings_btn_2_label = lv_label_create(ui->settings_btn_2);
	lv_label_set_text(ui->settings_btn_2_label, "开始检测");
	lv_obj_set_style_text_color(ui->settings_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->settings_btn_2_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->settings_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->settings_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes settings_label_17
	ui->settings_label_17 = lv_label_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_label_17, 25, 26);
	lv_obj_set_size(ui->settings_label_17, 236, 28);
	lv_label_set_text(ui->settings_label_17, "检测选项");
	lv_label_set_long_mode(ui->settings_label_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_17, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_17_main_main_default
	static lv_style_t style_settings_label_17_main_main_default;
	if (style_settings_label_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_17_main_main_default);
	else
		lv_style_init(&style_settings_label_17_main_main_default);
	lv_style_set_radius(&style_settings_label_17_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_label_17_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_label_17_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_17_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_17_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_17_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_17_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_17_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_17_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_17_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_17_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_17, &style_settings_label_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_18
	ui->settings_label_18 = lv_label_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_label_18, 24, 75);
	lv_obj_set_size(ui->settings_label_18, 432, 1);
	lv_label_set_text(ui->settings_label_18, "");
	lv_label_set_long_mode(ui->settings_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_18, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_18_main_main_default
	static lv_style_t style_settings_label_18_main_main_default;
	if (style_settings_label_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_18_main_main_default);
	else
		lv_style_init(&style_settings_label_18_main_main_default);
	lv_style_set_radius(&style_settings_label_18_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_18_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_label_18_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_label_18_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_18_main_main_default, 255);
	lv_style_set_text_color(&style_settings_label_18_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_label_18_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_18_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_18_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_18_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_18_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_18, &style_settings_label_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_19
	ui->settings_label_19 = lv_label_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_label_19, 24, 507);
	lv_obj_set_size(ui->settings_label_19, 432, 1);
	lv_label_set_text(ui->settings_label_19, "");
	lv_label_set_long_mode(ui->settings_label_19, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_19, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_19_main_main_default
	static lv_style_t style_settings_label_19_main_main_default;
	if (style_settings_label_19_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_19_main_main_default);
	else
		lv_style_init(&style_settings_label_19_main_main_default);
	lv_style_set_radius(&style_settings_label_19_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_19_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_label_19_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_label_19_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_19_main_main_default, 255);
	lv_style_set_text_color(&style_settings_label_19_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_label_19_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_19_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_19_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_19_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_19_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_19, &style_settings_label_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_20
	ui->settings_label_20 = lv_label_create(ui->settings_tabview_1_title3);
	lv_obj_set_pos(ui->settings_label_20, 24, 514);
	lv_obj_set_size(ui->settings_label_20, 349, 28);
	lv_label_set_text(ui->settings_label_20, "自检过程预计需要15分钟。");
	lv_label_set_long_mode(ui->settings_label_20, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_20, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_20_main_main_default
	static lv_style_t style_settings_label_20_main_main_default;
	if (style_settings_label_20_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_20_main_main_default);
	else
		lv_style_init(&style_settings_label_20_main_main_default);
	lv_style_set_radius(&style_settings_label_20_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_20_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_label_20_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_label_20_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_20_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_20_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_settings_label_20_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_20_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_20_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_20_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_20_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_20_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_20, &style_settings_label_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_4
	ui->settings_label_4 = lv_label_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_label_4, 8, 8);
	lv_obj_set_size(ui->settings_label_4, 460, 648);
	lv_label_set_text(ui->settings_label_4, "");
	lv_label_set_long_mode(ui->settings_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_4, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_4_main_main_default
	static lv_style_t style_settings_label_4_main_main_default;
	if (style_settings_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_4_main_main_default);
	else
		lv_style_init(&style_settings_label_4_main_main_default);
	lv_style_set_radius(&style_settings_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_4_main_main_default, 255);
	lv_style_set_text_color(&style_settings_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_settings_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_4_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_4, &style_settings_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_img_9
	ui->settings_img_9 = lv_img_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_img_9, 40, 379);
	lv_obj_set_size(ui->settings_img_9, 30, 24);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_9_main_main_default
	static lv_style_t style_settings_img_9_main_main_default;
	if (style_settings_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_9_main_main_default);
	else
		lv_style_init(&style_settings_img_9_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_9_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_9, &style_settings_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_9,&_video_30x24);
	lv_img_set_pivot(ui->settings_img_9, 0,0);
	lv_img_set_angle(ui->settings_img_9, 0);

	//Write codes settings_img_10
	ui->settings_img_10 = lv_img_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_img_10, 40, 457);
	lv_obj_set_size(ui->settings_img_10, 25, 25);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_10_main_main_default
	static lv_style_t style_settings_img_10_main_main_default;
	if (style_settings_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_10_main_main_default);
	else
		lv_style_init(&style_settings_img_10_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_10_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_10, &style_settings_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_10,&_seting_1_25x25);
	lv_img_set_pivot(ui->settings_img_10, 0,0);
	lv_img_set_angle(ui->settings_img_10, 0);

	//Write codes settings_img_11
	ui->settings_img_11 = lv_img_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_img_11, 40, 534);
	lv_obj_set_size(ui->settings_img_11, 32, 32);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_11_main_main_default
	static lv_style_t style_settings_img_11_main_main_default;
	if (style_settings_img_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_11_main_main_default);
	else
		lv_style_init(&style_settings_img_11_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_11_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_11_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_11, &style_settings_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_11,&_ai_logo_32x32);
	lv_img_set_pivot(ui->settings_img_11, 0,0);
	lv_img_set_angle(ui->settings_img_11, 0);

	//Write codes settings_img_12
	ui->settings_img_12 = lv_img_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_img_12, 430, 381);
	lv_obj_set_size(ui->settings_img_12, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_12_main_main_default
	static lv_style_t style_settings_img_12_main_main_default;
	if (style_settings_img_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_12_main_main_default);
	else
		lv_style_init(&style_settings_img_12_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_12_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_12_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_12, &style_settings_img_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_12, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_12,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_img_12, 0,0);
	lv_img_set_angle(ui->settings_img_12, 0);

	//Write codes settings_img_13
	ui->settings_img_13 = lv_img_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_img_13, 430, 461);
	lv_obj_set_size(ui->settings_img_13, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_13_main_main_default
	static lv_style_t style_settings_img_13_main_main_default;
	if (style_settings_img_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_13_main_main_default);
	else
		lv_style_init(&style_settings_img_13_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_13_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_13_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_13, &style_settings_img_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_13, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_13,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_img_13, 0,0);
	lv_img_set_angle(ui->settings_img_13, 0);

	//Write codes settings_img_14
	ui->settings_img_14 = lv_img_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_img_14, 430, 541);
	lv_obj_set_size(ui->settings_img_14, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_14_main_main_default
	static lv_style_t style_settings_img_14_main_main_default;
	if (style_settings_img_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_14_main_main_default);
	else
		lv_style_init(&style_settings_img_14_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_14_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_14_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_14, &style_settings_img_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_14, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_14,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_img_14, 0,0);
	lv_img_set_angle(ui->settings_img_14, 0);

	//Write codes settings_label_22
	ui->settings_label_22 = lv_label_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_label_22, 24, 24);
	lv_obj_set_size(ui->settings_label_22, 432, 324);
	lv_label_set_text(ui->settings_label_22, "");
	lv_label_set_long_mode(ui->settings_label_22, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_22, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_22_main_main_default
	static lv_style_t style_settings_label_22_main_main_default;
	if (style_settings_label_22_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_22_main_main_default);
	else
		lv_style_init(&style_settings_label_22_main_main_default);
	lv_style_set_radius(&style_settings_label_22_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_22_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_settings_label_22_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_settings_label_22_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_22_main_main_default, 255);
	lv_style_set_text_color(&style_settings_label_22_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_letter_space(&style_settings_label_22_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_22_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_22_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_22_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_22_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_22, &style_settings_label_22_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_21
	ui->settings_label_21 = lv_label_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_label_21, 165, 224);
	lv_obj_set_size(ui->settings_label_21, 161, 33);
	lv_label_set_text(ui->settings_label_21, "摄像头未启用");
	lv_label_set_long_mode(ui->settings_label_21, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_21, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_21_main_main_default
	static lv_style_t style_settings_label_21_main_main_default;
	if (style_settings_label_21_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_21_main_main_default);
	else
		lv_style_init(&style_settings_label_21_main_main_default);
	lv_style_set_radius(&style_settings_label_21_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_21_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_label_21_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_label_21_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_21_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_21_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_settings_label_21_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_21_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_21_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_21_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_21_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_21_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_21, &style_settings_label_21_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_23
	ui->settings_label_23 = lv_label_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_label_23, 27, 429);
	lv_obj_set_size(ui->settings_label_23, 426, 1);
	lv_label_set_text(ui->settings_label_23, "");
	lv_label_set_long_mode(ui->settings_label_23, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_23, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_23_main_main_default
	static lv_style_t style_settings_label_23_main_main_default;
	if (style_settings_label_23_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_23_main_main_default);
	else
		lv_style_init(&style_settings_label_23_main_main_default);
	lv_style_set_radius(&style_settings_label_23_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_23_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_label_23_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_label_23_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_23_main_main_default, 255);
	lv_style_set_text_color(&style_settings_label_23_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_letter_space(&style_settings_label_23_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_23_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_23_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_23_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_23_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_23, &style_settings_label_23_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_24
	ui->settings_label_24 = lv_label_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_label_24, 27, 510);
	lv_obj_set_size(ui->settings_label_24, 426, 1);
	lv_label_set_text(ui->settings_label_24, "");
	lv_label_set_long_mode(ui->settings_label_24, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_24, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_24_main_main_default
	static lv_style_t style_settings_label_24_main_main_default;
	if (style_settings_label_24_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_24_main_main_default);
	else
		lv_style_init(&style_settings_label_24_main_main_default);
	lv_style_set_radius(&style_settings_label_24_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_24_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_label_24_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_label_24_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_24_main_main_default, 255);
	lv_style_set_text_color(&style_settings_label_24_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_letter_space(&style_settings_label_24_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_24_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_24_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_24_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_24_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_24, &style_settings_label_24_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_25
	ui->settings_label_25 = lv_label_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_label_25, 27, 591);
	lv_obj_set_size(ui->settings_label_25, 426, 1);
	lv_label_set_text(ui->settings_label_25, "");
	lv_label_set_long_mode(ui->settings_label_25, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_25, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_25_main_main_default
	static lv_style_t style_settings_label_25_main_main_default;
	if (style_settings_label_25_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_25_main_main_default);
	else
		lv_style_init(&style_settings_label_25_main_main_default);
	lv_style_set_radius(&style_settings_label_25_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_25_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_label_25_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_label_25_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_25_main_main_default, 255);
	lv_style_set_text_color(&style_settings_label_25_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_letter_space(&style_settings_label_25_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_25_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_25_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_25_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_25_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_25, &style_settings_label_25_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_26
	ui->settings_label_26 = lv_label_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_label_26, 80, 375);
	lv_obj_set_size(ui->settings_label_26, 208, 28);
	lv_label_set_text(ui->settings_label_26, "视频列表");
	lv_label_set_long_mode(ui->settings_label_26, LV_LABEL_LONG_WRAP);
	lv_obj_add_flag(ui->settings_label_26, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_style_text_align(ui->settings_label_26, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_26_main_main_default
	static lv_style_t style_settings_label_26_main_main_default;
	if (style_settings_label_26_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_26_main_main_default);
	else
		lv_style_init(&style_settings_label_26_main_main_default);
	lv_style_set_radius(&style_settings_label_26_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_26_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_label_26_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_label_26_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_26_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_26_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_26_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_26_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_26_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_26_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_26_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_26_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_26, &style_settings_label_26_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_27
	ui->settings_label_27 = lv_label_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_label_27, 80, 452);
	lv_obj_set_size(ui->settings_label_27, 208, 28);
	lv_label_set_text(ui->settings_label_27, "摄像头设置");
	lv_label_set_long_mode(ui->settings_label_27, LV_LABEL_LONG_WRAP);
	lv_obj_add_flag(ui->settings_label_27, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_style_text_align(ui->settings_label_27, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_27_main_main_default
	static lv_style_t style_settings_label_27_main_main_default;
	if (style_settings_label_27_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_27_main_main_default);
	else
		lv_style_init(&style_settings_label_27_main_main_default);
	lv_style_set_radius(&style_settings_label_27_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_27_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_label_27_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_label_27_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_27_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_27_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_27_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_27_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_27_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_27_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_27_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_27_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_27, &style_settings_label_27_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_28
	ui->settings_label_28 = lv_label_create(ui->settings_tabview_1_title4);
	lv_obj_set_pos(ui->settings_label_28, 80, 532);
	lv_obj_set_size(ui->settings_label_28, 208, 28);
	lv_label_set_text(ui->settings_label_28, "AI检测");
	lv_label_set_long_mode(ui->settings_label_28, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_28, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_28_main_main_default
	static lv_style_t style_settings_label_28_main_main_default;
	if (style_settings_label_28_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_28_main_main_default);
	else
		lv_style_init(&style_settings_label_28_main_main_default);
	lv_style_set_radius(&style_settings_label_28_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_28_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_settings_label_28_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_label_28_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_28_main_main_default, 0);
	lv_style_set_text_color(&style_settings_label_28_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_label_28_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_label_28_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_28_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_28_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_28_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_28_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_28, &style_settings_label_28_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_29
	ui->settings_label_29 = lv_label_create(ui->settings_cont_1);
	lv_obj_set_pos(ui->settings_label_29, 0, 720);
	lv_obj_set_size(ui->settings_label_29, 480, 80);
	lv_label_set_text(ui->settings_label_29, "");
	lv_label_set_long_mode(ui->settings_label_29, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_label_29, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_label_29_main_main_default
	static lv_style_t style_settings_label_29_main_main_default;
	if (style_settings_label_29_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_label_29_main_main_default);
	else
		lv_style_init(&style_settings_label_29_main_main_default);
	lv_style_set_radius(&style_settings_label_29_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_label_29_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_settings_label_29_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_settings_label_29_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_label_29_main_main_default, 255);
	lv_style_set_text_color(&style_settings_label_29_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_label_29_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_label_29_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_label_29_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_label_29_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_label_29_main_main_default, 0);
	lv_obj_add_style(ui->settings_label_29, &style_settings_label_29_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_img_15
	ui->settings_img_15 = lv_img_create(ui->settings_cont_1);
	lv_obj_set_pos(ui->settings_img_15, 30, 742);
	lv_obj_set_size(ui->settings_img_15, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_15_main_main_default
	static lv_style_t style_settings_img_15_main_main_default;
	if (style_settings_img_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_15_main_main_default);
	else
		lv_style_init(&style_settings_img_15_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_15_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_15_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_15, &style_settings_img_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_15, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_15,&_home_48x48);
	lv_img_set_pivot(ui->settings_img_15, 0,0);
	lv_img_set_angle(ui->settings_img_15, 0);

	//Write codes settings_img_16
	ui->settings_img_16 = lv_img_create(ui->settings_cont_1);
	lv_obj_set_pos(ui->settings_img_16, 128, 742);
	lv_obj_set_size(ui->settings_img_16, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_16_main_main_default
	static lv_style_t style_settings_img_16_main_main_default;
	if (style_settings_img_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_16_main_main_default);
	else
		lv_style_init(&style_settings_img_16_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_16_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_16_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_16, &style_settings_img_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_16, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_16,&_prepare_48x48);
	lv_img_set_pivot(ui->settings_img_16, 0,0);
	lv_img_set_angle(ui->settings_img_16, 0);

	//Write codes settings_img_17
	ui->settings_img_17 = lv_img_create(ui->settings_cont_1);
	lv_obj_set_pos(ui->settings_img_17, 224, 742);
	lv_obj_set_size(ui->settings_img_17, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_17_main_main_default
	static lv_style_t style_settings_img_17_main_main_default;
	if (style_settings_img_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_17_main_main_default);
	else
		lv_style_init(&style_settings_img_17_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_17_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_17_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_17_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_17, &style_settings_img_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_17, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_17,&_files_48x48);
	lv_img_set_pivot(ui->settings_img_17, 0,0);
	lv_img_set_angle(ui->settings_img_17, 0);

	//Write codes settings_img_18
	ui->settings_img_18 = lv_img_create(ui->settings_cont_1);
	lv_obj_set_pos(ui->settings_img_18, 318, 742);
	lv_obj_set_size(ui->settings_img_18, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_18_main_main_default
	static lv_style_t style_settings_img_18_main_main_default;
	if (style_settings_img_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_18_main_main_default);
	else
		lv_style_init(&style_settings_img_18_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_18_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_18_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_18_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_18, &style_settings_img_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_18, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_18,&_seting_blue_48x48);
	lv_img_set_pivot(ui->settings_img_18, 0,0);
	lv_img_set_angle(ui->settings_img_18, 0);

	//Write codes settings_img_19
	ui->settings_img_19 = lv_img_create(ui->settings_cont_1);
	lv_obj_set_pos(ui->settings_img_19, 414, 742);
	lv_obj_set_size(ui->settings_img_19, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_img_19_main_main_default
	static lv_style_t style_settings_img_19_main_main_default;
	if (style_settings_img_19_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_img_19_main_main_default);
	else
		lv_style_init(&style_settings_img_19_main_main_default);
	lv_style_set_img_recolor(&style_settings_img_19_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_img_19_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_img_19_main_main_default, 255);
	lv_obj_add_style(ui->settings_img_19, &style_settings_img_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_img_19, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_19,&_FAQ_48x48);
	lv_img_set_pivot(ui->settings_img_19, 0,0);
	lv_img_set_angle(ui->settings_img_19, 0);

	//Init events for screen
	events_init_settings(ui);
}

void refresh_page_language()
{
//    lv_tabview_rename_tab(guider_ui.settings_tabview_1,guider_ui.settings_tabview_1_title4,Camera[cur_language]);
//    lv_tabview_rename_tab(guider_ui.settings_tabview_1,guider_ui.settings_tabview_1_title3,Selftest[cur_language]);
//    lv_tabview_rename_tab(guider_ui.settings_tabview_1,guider_ui.settings_tabview_1_title2,Network[cur_language]);
//    lv_tabview_rename_tab(guider_ui.settings_tabview_1,guider_ui.settings_tabview_1_title1,systemsettings[cur_language]);
}
