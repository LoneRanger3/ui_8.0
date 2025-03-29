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

static void _settings_systems_ddlist_1_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_1_extra_list_selected_default
	static lv_style_t style_settings_systems_ddlist_1_extra_list_selected_default;
	if (style_settings_systems_ddlist_1_extra_list_selected_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_1_extra_list_selected_default);
	else
		lv_style_init(&style_settings_systems_ddlist_1_extra_list_selected_default);
	lv_style_set_radius(&style_settings_systems_ddlist_1_extra_list_selected_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_1_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_1_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_1_extra_list_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_1_extra_list_selected_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_1_extra_list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_systems_ddlist_1_extra_list_selected_default, 0);
	lv_style_set_text_color(&style_settings_systems_ddlist_1_extra_list_selected_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_1_extra_list_selected_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_1_extra_list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_1_extra_list_main_default
	static lv_style_t style_settings_systems_ddlist_1_extra_list_main_default;
	if (style_settings_systems_ddlist_1_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_1_extra_list_main_default);
	else
		lv_style_init(&style_settings_systems_ddlist_1_extra_list_main_default);
	lv_style_set_radius(&style_settings_systems_ddlist_1_extra_list_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_1_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_1_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_1_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_1_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_systems_ddlist_1_extra_list_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_ddlist_1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_1_extra_list_main_default, &lv_font_simsun_24);
	lv_style_set_max_height(&style_settings_systems_ddlist_1_extra_list_main_default, 120);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_1_extra_list_scrollbar_default
	static lv_style_t style_settings_systems_ddlist_1_extra_list_scrollbar_default;
	if (style_settings_systems_ddlist_1_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_1_extra_list_scrollbar_default);
	else
		lv_style_init(&style_settings_systems_ddlist_1_extra_list_scrollbar_default);
	lv_style_set_radius(&style_settings_systems_ddlist_1_extra_list_scrollbar_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_1_extra_list_scrollbar_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_1_extra_list_scrollbar_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_1_extra_list_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_1_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}
static void _settings_systems_ddlist_2_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_2_extra_list_selected_default
	static lv_style_t style_settings_systems_ddlist_2_extra_list_selected_default;
	if (style_settings_systems_ddlist_2_extra_list_selected_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_2_extra_list_selected_default);
	else
		lv_style_init(&style_settings_systems_ddlist_2_extra_list_selected_default);
	lv_style_set_radius(&style_settings_systems_ddlist_2_extra_list_selected_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_2_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_2_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_2_extra_list_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_2_extra_list_selected_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_2_extra_list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_systems_ddlist_2_extra_list_selected_default, 0);
	lv_style_set_text_color(&style_settings_systems_ddlist_2_extra_list_selected_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_2_extra_list_selected_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_2_extra_list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_2_extra_list_main_default
	static lv_style_t style_settings_systems_ddlist_2_extra_list_main_default;
	if (style_settings_systems_ddlist_2_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_2_extra_list_main_default);
	else
		lv_style_init(&style_settings_systems_ddlist_2_extra_list_main_default);
	lv_style_set_radius(&style_settings_systems_ddlist_2_extra_list_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_2_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_2_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_2_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_2_extra_list_main_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_2_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_systems_ddlist_2_extra_list_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_ddlist_2_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_2_extra_list_main_default, &lv_font_simsun_24);
	lv_style_set_max_height(&style_settings_systems_ddlist_2_extra_list_main_default, 120);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_2_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_2_extra_list_scrollbar_default
	static lv_style_t style_settings_systems_ddlist_2_extra_list_scrollbar_default;
	if (style_settings_systems_ddlist_2_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_2_extra_list_scrollbar_default);
	else
		lv_style_init(&style_settings_systems_ddlist_2_extra_list_scrollbar_default);
	lv_style_set_radius(&style_settings_systems_ddlist_2_extra_list_scrollbar_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_2_extra_list_scrollbar_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_2_extra_list_scrollbar_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_2_extra_list_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_2_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_2_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}
static void _settings_systems_ddlist_3_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_3_extra_list_selected_default
	static lv_style_t style_settings_systems_ddlist_3_extra_list_selected_default;
	if (style_settings_systems_ddlist_3_extra_list_selected_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_3_extra_list_selected_default);
	else
		lv_style_init(&style_settings_systems_ddlist_3_extra_list_selected_default);
	lv_style_set_radius(&style_settings_systems_ddlist_3_extra_list_selected_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_3_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_3_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_3_extra_list_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_3_extra_list_selected_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_3_extra_list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_systems_ddlist_3_extra_list_selected_default, 0);
	lv_style_set_text_color(&style_settings_systems_ddlist_3_extra_list_selected_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_3_extra_list_selected_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_3_extra_list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_3_extra_list_main_default
	static lv_style_t style_settings_systems_ddlist_3_extra_list_main_default;
	if (style_settings_systems_ddlist_3_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_3_extra_list_main_default);
	else
		lv_style_init(&style_settings_systems_ddlist_3_extra_list_main_default);
	lv_style_set_radius(&style_settings_systems_ddlist_3_extra_list_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_3_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_3_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_3_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_3_extra_list_main_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_3_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_systems_ddlist_3_extra_list_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_ddlist_3_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_3_extra_list_main_default, &lv_font_simsun_24);
	lv_style_set_max_height(&style_settings_systems_ddlist_3_extra_list_main_default, 120);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_3_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_3_extra_list_scrollbar_default
	static lv_style_t style_settings_systems_ddlist_3_extra_list_scrollbar_default;
	if (style_settings_systems_ddlist_3_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_3_extra_list_scrollbar_default);
	else
		lv_style_init(&style_settings_systems_ddlist_3_extra_list_scrollbar_default);
	lv_style_set_radius(&style_settings_systems_ddlist_3_extra_list_scrollbar_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_3_extra_list_scrollbar_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_3_extra_list_scrollbar_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_3_extra_list_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_3_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_3_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}
static void _settings_systems_ddlist_4_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_4_extra_list_selected_default
	static lv_style_t style_settings_systems_ddlist_4_extra_list_selected_default;
	if (style_settings_systems_ddlist_4_extra_list_selected_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_4_extra_list_selected_default);
	else
		lv_style_init(&style_settings_systems_ddlist_4_extra_list_selected_default);
	lv_style_set_radius(&style_settings_systems_ddlist_4_extra_list_selected_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_4_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_4_extra_list_selected_default, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_4_extra_list_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_4_extra_list_selected_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_4_extra_list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_systems_ddlist_4_extra_list_selected_default, 0);
	lv_style_set_text_color(&style_settings_systems_ddlist_4_extra_list_selected_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_4_extra_list_selected_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_4_extra_list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_4_extra_list_main_default
	static lv_style_t style_settings_systems_ddlist_4_extra_list_main_default;
	if (style_settings_systems_ddlist_4_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_4_extra_list_main_default);
	else
		lv_style_init(&style_settings_systems_ddlist_4_extra_list_main_default);
	lv_style_set_radius(&style_settings_systems_ddlist_4_extra_list_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_4_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_4_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_4_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_4_extra_list_main_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_4_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_settings_systems_ddlist_4_extra_list_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_ddlist_4_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_4_extra_list_main_default, &lv_font_simsun_24);
	lv_style_set_max_height(&style_settings_systems_ddlist_4_extra_list_main_default, 120);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_4_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_4_extra_list_scrollbar_default
	static lv_style_t style_settings_systems_ddlist_4_extra_list_scrollbar_default;
	if (style_settings_systems_ddlist_4_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_4_extra_list_scrollbar_default);
	else
		lv_style_init(&style_settings_systems_ddlist_4_extra_list_scrollbar_default);
	lv_style_set_radius(&style_settings_systems_ddlist_4_extra_list_scrollbar_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_4_extra_list_scrollbar_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_4_extra_list_scrollbar_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_4_extra_list_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_4_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_settings_systems_ddlist_4_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}

void setup_scr_settings_systems(lv_ui *ui){

    //Write codes settings_systems_cont_1
	ui->settings_systems_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->settings_systems_cont_1, 0, 0);
	lv_obj_set_size(ui->settings_systems_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_cont_1_main_main_default
	static lv_style_t style_settings_systems_cont_1_main_main_default;
	if (style_settings_systems_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_cont_1_main_main_default);
	else
		lv_style_init(&style_settings_systems_cont_1_main_main_default);
	lv_style_set_radius(&style_settings_systems_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_settings_systems_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_settings_systems_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_systems_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_systems_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_systems_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_settings_systems_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_cont_1, &style_settings_systems_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_tabview_1
	ui->settings_systems_tabview_1 = lv_tabview_create(ui->settings_systems_cont_1, LV_DIR_TOP, 50);
	lv_obj_set_pos(ui->settings_systems_tabview_1, 0, 0);
	lv_obj_set_size(ui->settings_systems_tabview_1, 480, 720);

	//title1
	ui->settings_systems_tabview_1_title1 = lv_tabview_add_tab(ui->settings_systems_tabview_1,"title1");

	//title2
	ui->settings_systems_tabview_1_title2 = lv_tabview_add_tab(ui->settings_systems_tabview_1,"title2");

	//title3
	ui->settings_systems_tabview_1_title3 = lv_tabview_add_tab(ui->settings_systems_tabview_1,"title3");

	//Title
	ui->settings_systems_tabview_1_Title = lv_tabview_add_tab(ui->settings_systems_tabview_1,"Title");


	//Write style state: LV_STATE_DEFAULT for style_settings_systems_tabview_1_main_main_default
	static lv_style_t style_settings_systems_tabview_1_main_main_default;
	if (style_settings_systems_tabview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_tabview_1_main_main_default);
	else
		lv_style_init(&style_settings_systems_tabview_1_main_main_default);
	lv_style_set_bg_color(&style_settings_systems_tabview_1_main_main_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_settings_systems_tabview_1_main_main_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_settings_systems_tabview_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_tabview_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_systems_tabview_1_main_main_default, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_settings_systems_tabview_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_systems_tabview_1_main_main_default, 100);
	lv_style_set_text_color(&style_settings_systems_tabview_1_main_main_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_settings_systems_tabview_1_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_settings_systems_tabview_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_settings_systems_tabview_1_main_main_default, 16);
	lv_obj_add_style(ui->settings_systems_tabview_1, &style_settings_systems_tabview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_tabview_1_extra_btnm_main_default
	static lv_style_t style_settings_systems_tabview_1_extra_btnm_main_default;
	if (style_settings_systems_tabview_1_extra_btnm_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_tabview_1_extra_btnm_main_default);
	else
		lv_style_init(&style_settings_systems_tabview_1_extra_btnm_main_default);
	lv_style_set_bg_color(&style_settings_systems_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_systems_tabview_1_extra_btnm_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_systems_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_border_color(&style_settings_systems_tabview_1_extra_btnm_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_systems_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_border_opa(&style_settings_systems_tabview_1_extra_btnm_main_default, 100);
	lv_style_set_pad_left(&style_settings_systems_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_tabview_1_extra_btnm_main_default, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_systems_tabview_1), &style_settings_systems_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_tabview_1_extra_btnm_items_default
	static lv_style_t style_settings_systems_tabview_1_extra_btnm_items_default;
	if (style_settings_systems_tabview_1_extra_btnm_items_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_tabview_1_extra_btnm_items_default);
	else
		lv_style_init(&style_settings_systems_tabview_1_extra_btnm_items_default);
	lv_style_set_text_color(&style_settings_systems_tabview_1_extra_btnm_items_default, lv_color_make(0x4d, 0x4d, 0x4d));
	lv_style_set_text_font(&style_settings_systems_tabview_1_extra_btnm_items_default, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_systems_tabview_1), &style_settings_systems_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_settings_systems_tabview_1_extra_btnm_items_checked
	static lv_style_t style_settings_systems_tabview_1_extra_btnm_items_checked;
	if (style_settings_systems_tabview_1_extra_btnm_items_checked.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_tabview_1_extra_btnm_items_checked);
	else
		lv_style_init(&style_settings_systems_tabview_1_extra_btnm_items_checked);
	lv_style_set_bg_color(&style_settings_systems_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_systems_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_systems_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_tabview_1_extra_btnm_items_checked, 60);
	lv_style_set_border_color(&style_settings_systems_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_systems_tabview_1_extra_btnm_items_checked, 4);
	lv_style_set_border_opa(&style_settings_systems_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_side(&style_settings_systems_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_text_color(&style_settings_systems_tabview_1_extra_btnm_items_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_text_font(&style_settings_systems_tabview_1_extra_btnm_items_checked, &lv_font_simsun_12);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->settings_systems_tabview_1), &style_settings_systems_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes settings_systems_label_2
	ui->settings_systems_label_2 = lv_label_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_label_2, 7, 61);
	lv_obj_set_size(ui->settings_systems_label_2, 460, 648);
	lv_label_set_text(ui->settings_systems_label_2, "");
	lv_label_set_long_mode(ui->settings_systems_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_systems_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_label_2_main_main_default
	static lv_style_t style_settings_systems_label_2_main_main_default;
	if (style_settings_systems_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_label_2_main_main_default);
	else
		lv_style_init(&style_settings_systems_label_2_main_main_default);
	lv_style_set_radius(&style_settings_systems_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_systems_label_2_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_systems_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_settings_systems_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_settings_systems_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_systems_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_label_2_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_label_2, &style_settings_systems_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_btn_1
	ui->settings_systems_btn_1 = lv_btn_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_btn_1, 425, 385);
	lv_obj_set_size(ui->settings_systems_btn_1, 40, 50);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_btn_1_main_main_default
	static lv_style_t style_settings_systems_btn_1_main_main_default;
	if (style_settings_systems_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_btn_1_main_main_default);
	else
		lv_style_init(&style_settings_systems_btn_1_main_main_default);
	lv_style_set_radius(&style_settings_systems_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_systems_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_systems_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_settings_systems_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_settings_systems_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_settings_systems_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_systems_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_systems_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_btn_1, &style_settings_systems_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->settings_systems_btn_1_label = lv_label_create(ui->settings_systems_btn_1);
	lv_label_set_text(ui->settings_systems_btn_1_label, "");
	lv_obj_set_style_text_color(ui->settings_systems_btn_1_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->settings_systems_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->settings_systems_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes settings_systems_btn_2
	ui->settings_systems_btn_2 = lv_btn_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_btn_2, 425, 539);
	lv_obj_set_size(ui->settings_systems_btn_2, 40, 50);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_btn_2_main_main_default
	static lv_style_t style_settings_systems_btn_2_main_main_default;
	if (style_settings_systems_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_btn_2_main_main_default);
	else
		lv_style_init(&style_settings_systems_btn_2_main_main_default);
	lv_style_set_radius(&style_settings_systems_btn_2_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_systems_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_systems_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_btn_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_settings_systems_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_settings_systems_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_settings_systems_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_systems_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_systems_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_btn_2, &style_settings_systems_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->settings_systems_btn_2_label = lv_label_create(ui->settings_systems_btn_2);
	lv_label_set_text(ui->settings_systems_btn_2_label, "");
	lv_obj_set_style_text_color(ui->settings_systems_btn_2_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->settings_systems_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->settings_systems_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes settings_systems_btn_3
	ui->settings_systems_btn_3 = lv_btn_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_btn_3, 426, 617);
	lv_obj_set_size(ui->settings_systems_btn_3, 40, 50);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_btn_3_main_main_default
	static lv_style_t style_settings_systems_btn_3_main_main_default;
	if (style_settings_systems_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_btn_3_main_main_default);
	else
		lv_style_init(&style_settings_systems_btn_3_main_main_default);
	lv_style_set_radius(&style_settings_systems_btn_3_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_settings_systems_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_settings_systems_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_btn_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_settings_systems_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_settings_systems_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_settings_systems_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_settings_systems_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_settings_systems_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_btn_3, &style_settings_systems_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->settings_systems_btn_3_label = lv_label_create(ui->settings_systems_btn_3);
	lv_label_set_text(ui->settings_systems_btn_3_label, "");
	lv_obj_set_style_text_color(ui->settings_systems_btn_3_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->settings_systems_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->settings_systems_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes settings_systems_img_6
	ui->settings_systems_img_6 = lv_img_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_img_6, 231, 87);
	lv_obj_set_size(ui->settings_systems_img_6, 38, 38);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_img_6_main_main_default
	static lv_style_t style_settings_systems_img_6_main_main_default;
	if (style_settings_systems_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_img_6_main_main_default);
	else
		lv_style_init(&style_settings_systems_img_6_main_main_default);
	lv_style_set_img_recolor(&style_settings_systems_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_systems_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_systems_img_6_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_img_6, &style_settings_systems_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_systems_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_systems_img_6,&_group_609_38x38);
	lv_img_set_pivot(ui->settings_systems_img_6, 0,0);
	lv_img_set_angle(ui->settings_systems_img_6, 0);

	//Write codes settings_systems_img_8
	ui->settings_systems_img_8 = lv_img_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_img_8, 443, 398);
	lv_obj_set_size(ui->settings_systems_img_8, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_img_8_main_main_default
	static lv_style_t style_settings_systems_img_8_main_main_default;
	if (style_settings_systems_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_img_8_main_main_default);
	else
		lv_style_init(&style_settings_systems_img_8_main_main_default);
	lv_style_set_img_recolor(&style_settings_systems_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_systems_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_systems_img_8_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_img_8, &style_settings_systems_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_systems_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_systems_img_8,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_systems_img_8, 0,0);
	lv_img_set_angle(ui->settings_systems_img_8, 0);

	//Write codes settings_systems_img_9
	ui->settings_systems_img_9 = lv_img_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_img_9, 443, 550);
	lv_obj_set_size(ui->settings_systems_img_9, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_img_9_main_main_default
	static lv_style_t style_settings_systems_img_9_main_main_default;
	if (style_settings_systems_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_img_9_main_main_default);
	else
		lv_style_init(&style_settings_systems_img_9_main_main_default);
	lv_style_set_img_recolor(&style_settings_systems_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_systems_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_systems_img_9_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_img_9, &style_settings_systems_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_systems_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_systems_img_9,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_systems_img_9, 0,0);
	lv_img_set_angle(ui->settings_systems_img_9, 0);

	//Write codes settings_systems_img_10
	ui->settings_systems_img_10 = lv_img_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_img_10, 443, 626);
	lv_obj_set_size(ui->settings_systems_img_10, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_img_10_main_main_default
	static lv_style_t style_settings_systems_img_10_main_main_default;
	if (style_settings_systems_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_img_10_main_main_default);
	else
		lv_style_init(&style_settings_systems_img_10_main_main_default);
	lv_style_set_img_recolor(&style_settings_systems_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_systems_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_systems_img_10_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_img_10, &style_settings_systems_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_systems_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_systems_img_10,&_Vector_24_14x28);
	lv_img_set_pivot(ui->settings_systems_img_10, 0,0);
	lv_img_set_angle(ui->settings_systems_img_10, 0);

	//Write codes settings_systems_img_7
	ui->settings_systems_img_7 = lv_img_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_img_7, 424, 87);
	lv_obj_set_size(ui->settings_systems_img_7, 38, 38);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_img_7_main_main_default
	static lv_style_t style_settings_systems_img_7_main_main_default;
	if (style_settings_systems_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_img_7_main_main_default);
	else
		lv_style_init(&style_settings_systems_img_7_main_main_default);
	lv_style_set_img_recolor(&style_settings_systems_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_systems_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_systems_img_7_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_img_7, &style_settings_systems_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_systems_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_systems_img_7,&_group_609_1_38x38);
	lv_img_set_pivot(ui->settings_systems_img_7, 0,0);
	lv_img_set_angle(ui->settings_systems_img_7, 0);

	//Write codes settings_systems_label_3
	ui->settings_systems_label_3 = lv_label_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_label_3, 25, 88);
	lv_obj_set_size(ui->settings_systems_label_3, 186, 24);
	lv_label_set_text(ui->settings_systems_label_3, "屏幕亮度");
	lv_label_set_long_mode(ui->settings_systems_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_systems_label_3, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_label_3_main_main_default
	static lv_style_t style_settings_systems_label_3_main_main_default;
	if (style_settings_systems_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_label_3_main_main_default);
	else
		lv_style_init(&style_settings_systems_label_3_main_main_default);
	lv_style_set_radius(&style_settings_systems_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_systems_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_systems_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_label_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_systems_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_systems_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_label_3_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_label_3, &style_settings_systems_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_label_4
	ui->settings_systems_label_4 = lv_label_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_label_4, 25, 164);
	lv_obj_set_size(ui->settings_systems_label_4, 132, 24);
	lv_label_set_text(ui->settings_systems_label_4, "息屏");
	lv_label_set_long_mode(ui->settings_systems_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_systems_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_label_4_main_main_default
	static lv_style_t style_settings_systems_label_4_main_main_default;
	if (style_settings_systems_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_label_4_main_main_default);
	else
		lv_style_init(&style_settings_systems_label_4_main_main_default);
	lv_style_set_radius(&style_settings_systems_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_systems_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_systems_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_systems_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_systems_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_label_4_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_label_4, &style_settings_systems_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_label_5
	ui->settings_systems_label_5 = lv_label_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_label_5, 25, 240);
	lv_obj_set_size(ui->settings_systems_label_5, 176, 24);
	lv_label_set_text(ui->settings_systems_label_5, "语言选择");
	lv_label_set_long_mode(ui->settings_systems_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_systems_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_label_5_main_main_default
	static lv_style_t style_settings_systems_label_5_main_main_default;
	if (style_settings_systems_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_label_5_main_main_default);
	else
		lv_style_init(&style_settings_systems_label_5_main_main_default);
	lv_style_set_radius(&style_settings_systems_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_label_5_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_systems_label_5_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_systems_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_systems_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_systems_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_label_5_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_label_5, &style_settings_systems_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_label_6
	ui->settings_systems_label_6 = lv_label_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_label_6, 25, 316);
	lv_obj_set_size(ui->settings_systems_label_6, 176, 24);
	lv_label_set_text(ui->settings_systems_label_6, "语言选择");
	lv_label_set_long_mode(ui->settings_systems_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_systems_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_label_6_main_main_default
	static lv_style_t style_settings_systems_label_6_main_main_default;
	if (style_settings_systems_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_label_6_main_main_default);
	else
		lv_style_init(&style_settings_systems_label_6_main_main_default);
	lv_style_set_radius(&style_settings_systems_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_label_6_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_systems_label_6_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_systems_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_label_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_systems_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_systems_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_label_6_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_label_6, &style_settings_systems_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_label_7
	ui->settings_systems_label_7 = lv_label_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_label_7, 25, 392);
	lv_obj_set_size(ui->settings_systems_label_7, 176, 24);
	lv_label_set_text(ui->settings_systems_label_7, "按键音");
	lv_label_set_long_mode(ui->settings_systems_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_systems_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_label_7_main_main_default
	static lv_style_t style_settings_systems_label_7_main_main_default;
	if (style_settings_systems_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_label_7_main_main_default);
	else
		lv_style_init(&style_settings_systems_label_7_main_main_default);
	lv_style_set_radius(&style_settings_systems_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_label_7_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_systems_label_7_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_systems_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_label_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_systems_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_systems_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_label_7_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_label_7, &style_settings_systems_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_label_8
	ui->settings_systems_label_8 = lv_label_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_label_8, 25, 468);
	lv_obj_set_size(ui->settings_systems_label_8, 176, 24);
	lv_label_set_text(ui->settings_systems_label_8, "主题");
	lv_label_set_long_mode(ui->settings_systems_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_systems_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_label_8_main_main_default
	static lv_style_t style_settings_systems_label_8_main_main_default;
	if (style_settings_systems_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_label_8_main_main_default);
	else
		lv_style_init(&style_settings_systems_label_8_main_main_default);
	lv_style_set_radius(&style_settings_systems_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_label_8_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_systems_label_8_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_systems_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_label_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_systems_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_systems_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_label_8_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_label_8, &style_settings_systems_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_label_9
	ui->settings_systems_label_9 = lv_label_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_label_9, 25, 544);
	lv_obj_set_size(ui->settings_systems_label_9, 176, 24);
	lv_label_set_text(ui->settings_systems_label_9, "设备绑定");
	lv_label_set_long_mode(ui->settings_systems_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_systems_label_9, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_label_9_main_main_default
	static lv_style_t style_settings_systems_label_9_main_main_default;
	if (style_settings_systems_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_label_9_main_main_default);
	else
		lv_style_init(&style_settings_systems_label_9_main_main_default);
	lv_style_set_radius(&style_settings_systems_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_label_9_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_systems_label_9_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_systems_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_label_9_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_systems_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_systems_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_label_9_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_label_9, &style_settings_systems_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_label_10
	ui->settings_systems_label_10 = lv_label_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_label_10, 25, 620);
	lv_obj_set_size(ui->settings_systems_label_10, 176, 24);
	lv_label_set_text(ui->settings_systems_label_10, "导出日志");
	lv_label_set_long_mode(ui->settings_systems_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_systems_label_10, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_label_10_main_main_default
	static lv_style_t style_settings_systems_label_10_main_main_default;
	if (style_settings_systems_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_label_10_main_main_default);
	else
		lv_style_init(&style_settings_systems_label_10_main_main_default);
	lv_style_set_radius(&style_settings_systems_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_label_10_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_settings_systems_label_10_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_settings_systems_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_settings_systems_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_label_10_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_settings_systems_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_systems_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_label_10_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_label_10, &style_settings_systems_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_label_1
	ui->settings_systems_label_1 = lv_label_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_label_1, 0, 719);
	lv_obj_set_size(ui->settings_systems_label_1, 480, 80);
	lv_label_set_text(ui->settings_systems_label_1, "");
	lv_label_set_long_mode(ui->settings_systems_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->settings_systems_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_label_1_main_main_default
	static lv_style_t style_settings_systems_label_1_main_main_default;
	if (style_settings_systems_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_label_1_main_main_default);
	else
		lv_style_init(&style_settings_systems_label_1_main_main_default);
	lv_style_set_radius(&style_settings_systems_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_settings_systems_label_1_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_settings_systems_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_settings_systems_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_settings_systems_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_settings_systems_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_label_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_label_1, &style_settings_systems_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_img_1
	ui->settings_systems_img_1 = lv_img_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_img_1, 30, 742);
	lv_obj_set_size(ui->settings_systems_img_1, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_img_1_main_main_default
	static lv_style_t style_settings_systems_img_1_main_main_default;
	if (style_settings_systems_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_img_1_main_main_default);
	else
		lv_style_init(&style_settings_systems_img_1_main_main_default);
	lv_style_set_img_recolor(&style_settings_systems_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_systems_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_systems_img_1_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_img_1, &style_settings_systems_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_systems_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_systems_img_1,&_home_48x48);
	lv_img_set_pivot(ui->settings_systems_img_1, 0,0);
	lv_img_set_angle(ui->settings_systems_img_1, 0);

	//Write codes settings_systems_img_2
	ui->settings_systems_img_2 = lv_img_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_img_2, 128, 742);
	lv_obj_set_size(ui->settings_systems_img_2, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_img_2_main_main_default
	static lv_style_t style_settings_systems_img_2_main_main_default;
	if (style_settings_systems_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_img_2_main_main_default);
	else
		lv_style_init(&style_settings_systems_img_2_main_main_default);
	lv_style_set_img_recolor(&style_settings_systems_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_systems_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_systems_img_2_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_img_2, &style_settings_systems_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_systems_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_systems_img_2,&_prepare_48x48);
	lv_img_set_pivot(ui->settings_systems_img_2, 0,0);
	lv_img_set_angle(ui->settings_systems_img_2, 0);

	//Write codes settings_systems_img_3
	ui->settings_systems_img_3 = lv_img_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_img_3, 224, 742);
	lv_obj_set_size(ui->settings_systems_img_3, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_img_3_main_main_default
	static lv_style_t style_settings_systems_img_3_main_main_default;
	if (style_settings_systems_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_img_3_main_main_default);
	else
		lv_style_init(&style_settings_systems_img_3_main_main_default);
	lv_style_set_img_recolor(&style_settings_systems_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_systems_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_systems_img_3_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_img_3, &style_settings_systems_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_systems_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_systems_img_3,&_files_48x48);
	lv_img_set_pivot(ui->settings_systems_img_3, 0,0);
	lv_img_set_angle(ui->settings_systems_img_3, 0);

	//Write codes settings_systems_img_4
	ui->settings_systems_img_4 = lv_img_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_img_4, 318, 742);
	lv_obj_set_size(ui->settings_systems_img_4, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_img_4_main_main_default
	static lv_style_t style_settings_systems_img_4_main_main_default;
	if (style_settings_systems_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_img_4_main_main_default);
	else
		lv_style_init(&style_settings_systems_img_4_main_main_default);
	lv_style_set_img_recolor(&style_settings_systems_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_systems_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_systems_img_4_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_img_4, &style_settings_systems_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_systems_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_systems_img_4,&_seting_48x48);
	lv_img_set_pivot(ui->settings_systems_img_4, 0,0);
	lv_img_set_angle(ui->settings_systems_img_4, 0);

	//Write codes settings_systems_img_5
	ui->settings_systems_img_5 = lv_img_create(ui->settings_systems_cont_1);
	lv_obj_set_pos(ui->settings_systems_img_5, 414, 742);
	lv_obj_set_size(ui->settings_systems_img_5, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_img_5_main_main_default
	static lv_style_t style_settings_systems_img_5_main_main_default;
	if (style_settings_systems_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_img_5_main_main_default);
	else
		lv_style_init(&style_settings_systems_img_5_main_main_default);
	lv_style_set_img_recolor(&style_settings_systems_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_settings_systems_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_settings_systems_img_5_main_main_default, 255);
	lv_obj_add_style(ui->settings_systems_img_5, &style_settings_systems_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->settings_systems_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_systems_img_5,&_FAQ_48x48);
	lv_img_set_pivot(ui->settings_systems_img_5, 0,0);
	lv_img_set_angle(ui->settings_systems_img_5, 0);

	//Write codes settings_systems_slider_1
	ui->settings_systems_slider_1 = lv_slider_create(ui->settings_systems);
	lv_obj_set_pos(ui->settings_systems_slider_1, 275, 102);
	lv_obj_set_size(ui->settings_systems_slider_1, 142, 8);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_slider_1_main_main_default
	static lv_style_t style_settings_systems_slider_1_main_main_default;
	if (style_settings_systems_slider_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_slider_1_main_main_default);
	else
		lv_style_init(&style_settings_systems_slider_1_main_main_default);
	lv_style_set_radius(&style_settings_systems_slider_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_slider_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_color(&style_settings_systems_slider_1_main_main_default, lv_color_make(0x50, 0x53, 0x5a));
	lv_style_set_bg_grad_dir(&style_settings_systems_slider_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_slider_1_main_main_default, 255);
	lv_style_set_outline_color(&style_settings_systems_slider_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_outline_width(&style_settings_systems_slider_1_main_main_default, 0);
	lv_style_set_outline_opa(&style_settings_systems_slider_1_main_main_default, 255);
	lv_style_set_pad_left(&style_settings_systems_slider_1_main_main_default, 0);
	lv_style_set_pad_right(&style_settings_systems_slider_1_main_main_default, 0);
	lv_style_set_pad_top(&style_settings_systems_slider_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_settings_systems_slider_1_main_main_default, 0);
	lv_obj_add_style(ui->settings_systems_slider_1, &style_settings_systems_slider_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_slider_1_main_indicator_default
	static lv_style_t style_settings_systems_slider_1_main_indicator_default;
	if (style_settings_systems_slider_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_slider_1_main_indicator_default);
	else
		lv_style_init(&style_settings_systems_slider_1_main_indicator_default);
	lv_style_set_radius(&style_settings_systems_slider_1_main_indicator_default, 0);
	lv_style_set_bg_color(&style_settings_systems_slider_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_settings_systems_slider_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_settings_systems_slider_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_slider_1_main_indicator_default, 255);
	lv_obj_add_style(ui->settings_systems_slider_1, &style_settings_systems_slider_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_slider_1_main_knob_default
	static lv_style_t style_settings_systems_slider_1_main_knob_default;
	if (style_settings_systems_slider_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_slider_1_main_knob_default);
	else
		lv_style_init(&style_settings_systems_slider_1_main_knob_default);
	lv_style_set_radius(&style_settings_systems_slider_1_main_knob_default, 0);
	lv_style_set_bg_color(&style_settings_systems_slider_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_settings_systems_slider_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_settings_systems_slider_1_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_slider_1_main_knob_default, 255);
	lv_obj_add_style(ui->settings_systems_slider_1, &style_settings_systems_slider_1_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->settings_systems_slider_1,0, 100);
	lv_slider_set_value(ui->settings_systems_slider_1,50,false);

	//Write codes settings_systems_ddlist_1
	ui->settings_systems_ddlist_1 = lv_dropdown_create(ui->settings_systems);
	lv_obj_set_pos(ui->settings_systems_ddlist_1, 216, 159);
	lv_obj_set_width(ui->settings_systems_ddlist_1, 242);
	lv_dropdown_set_options(ui->settings_systems_ddlist_1, "3分钟\n5分钟\n15分钟\n不设置");
	lv_obj_add_event_cb(ui->settings_systems_ddlist_1, _settings_systems_ddlist_1_event_cb, LV_EVENT_READY, NULL);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_1_main_main_default
	static lv_style_t style_settings_systems_ddlist_1_main_main_default;
	if (style_settings_systems_ddlist_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_1_main_main_default);
	else
		lv_style_init(&style_settings_systems_ddlist_1_main_main_default);
	lv_style_set_radius(&style_settings_systems_ddlist_1_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_1_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_1_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_1_main_main_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_1_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_settings_systems_ddlist_1_main_main_default, 1);
	lv_style_set_text_color(&style_settings_systems_ddlist_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_line_space(&style_settings_systems_ddlist_1_main_main_default, 20);
	lv_obj_add_style(ui->settings_systems_ddlist_1, &style_settings_systems_ddlist_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_ddlist_2
	ui->settings_systems_ddlist_2 = lv_dropdown_create(ui->settings_systems);
	lv_obj_set_pos(ui->settings_systems_ddlist_2, 216, 234);
	lv_obj_set_width(ui->settings_systems_ddlist_2, 242);
	lv_dropdown_set_options(ui->settings_systems_ddlist_2, "中文");
	lv_obj_add_event_cb(ui->settings_systems_ddlist_2, _settings_systems_ddlist_2_event_cb, LV_EVENT_READY, NULL);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_2_main_main_default
	static lv_style_t style_settings_systems_ddlist_2_main_main_default;
	if (style_settings_systems_ddlist_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_2_main_main_default);
	else
		lv_style_init(&style_settings_systems_ddlist_2_main_main_default);
	lv_style_set_radius(&style_settings_systems_ddlist_2_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_2_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_2_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_2_main_main_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_2_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_settings_systems_ddlist_2_main_main_default, 1);
	lv_style_set_text_color(&style_settings_systems_ddlist_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_2_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_line_space(&style_settings_systems_ddlist_2_main_main_default, 20);
	lv_obj_add_style(ui->settings_systems_ddlist_2, &style_settings_systems_ddlist_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_ddlist_3
	ui->settings_systems_ddlist_3 = lv_dropdown_create(ui->settings_systems);
	lv_obj_set_pos(ui->settings_systems_ddlist_3, 216, 309);
	lv_obj_set_width(ui->settings_systems_ddlist_3, 242);
	lv_dropdown_set_options(ui->settings_systems_ddlist_3, "中国(大陆)");
	lv_obj_add_event_cb(ui->settings_systems_ddlist_3, _settings_systems_ddlist_3_event_cb, LV_EVENT_READY, NULL);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_3_main_main_default
	static lv_style_t style_settings_systems_ddlist_3_main_main_default;
	if (style_settings_systems_ddlist_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_3_main_main_default);
	else
		lv_style_init(&style_settings_systems_ddlist_3_main_main_default);
	lv_style_set_radius(&style_settings_systems_ddlist_3_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_3_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_3_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_3_main_main_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_3_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_settings_systems_ddlist_3_main_main_default, 1);
	lv_style_set_text_color(&style_settings_systems_ddlist_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_line_space(&style_settings_systems_ddlist_3_main_main_default, 20);
	lv_obj_add_style(ui->settings_systems_ddlist_3, &style_settings_systems_ddlist_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_systems_ddlist_4
	ui->settings_systems_ddlist_4 = lv_dropdown_create(ui->settings_systems);
	lv_obj_set_pos(ui->settings_systems_ddlist_4, 216, 461);
	lv_obj_set_width(ui->settings_systems_ddlist_4, 242);
	lv_dropdown_set_options(ui->settings_systems_ddlist_4, "主题一");
	lv_obj_add_event_cb(ui->settings_systems_ddlist_4, _settings_systems_ddlist_4_event_cb, LV_EVENT_READY, NULL);

	//Write style state: LV_STATE_DEFAULT for style_settings_systems_ddlist_4_main_main_default
	static lv_style_t style_settings_systems_ddlist_4_main_main_default;
	if (style_settings_systems_ddlist_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_settings_systems_ddlist_4_main_main_default);
	else
		lv_style_init(&style_settings_systems_ddlist_4_main_main_default);
	lv_style_set_radius(&style_settings_systems_ddlist_4_main_main_default, 0);
	lv_style_set_bg_color(&style_settings_systems_ddlist_4_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_settings_systems_ddlist_4_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_settings_systems_ddlist_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_settings_systems_ddlist_4_main_main_default, 255);
	lv_style_set_border_color(&style_settings_systems_ddlist_4_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_settings_systems_ddlist_4_main_main_default, 1);
	lv_style_set_text_color(&style_settings_systems_ddlist_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_settings_systems_ddlist_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_line_space(&style_settings_systems_ddlist_4_main_main_default, 20);
	lv_obj_add_style(ui->settings_systems_ddlist_4, &style_settings_systems_ddlist_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}
