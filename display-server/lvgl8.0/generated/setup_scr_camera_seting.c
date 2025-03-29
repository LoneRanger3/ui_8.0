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

static void _camera_seting_ddlist_1_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_ddlist_1_extra_list_selected_default
	static lv_style_t style_camera_seting_ddlist_1_extra_list_selected_default;
	if (style_camera_seting_ddlist_1_extra_list_selected_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_ddlist_1_extra_list_selected_default);
	else
		lv_style_init(&style_camera_seting_ddlist_1_extra_list_selected_default);
	lv_style_set_radius(&style_camera_seting_ddlist_1_extra_list_selected_default, 0);
	lv_style_set_bg_color(&style_camera_seting_ddlist_1_extra_list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_camera_seting_ddlist_1_extra_list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_camera_seting_ddlist_1_extra_list_selected_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_ddlist_1_extra_list_selected_default, 255);
	lv_style_set_border_color(&style_camera_seting_ddlist_1_extra_list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_camera_seting_ddlist_1_extra_list_selected_default, 0);
	lv_style_set_text_color(&style_camera_seting_ddlist_1_extra_list_selected_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_ddlist_1_extra_list_selected_default, &lv_font_simsun_24);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_camera_seting_ddlist_1_extra_list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_ddlist_1_extra_list_main_default
	static lv_style_t style_camera_seting_ddlist_1_extra_list_main_default;
	if (style_camera_seting_ddlist_1_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_ddlist_1_extra_list_main_default);
	else
		lv_style_init(&style_camera_seting_ddlist_1_extra_list_main_default);
	lv_style_set_radius(&style_camera_seting_ddlist_1_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_camera_seting_ddlist_1_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_color(&style_camera_seting_ddlist_1_extra_list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_dir(&style_camera_seting_ddlist_1_extra_list_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_camera_seting_ddlist_1_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_camera_seting_ddlist_1_extra_list_main_default, 0);
	lv_style_set_text_color(&style_camera_seting_ddlist_1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_ddlist_1_extra_list_main_default, &lv_font_simsun_24);
	lv_style_set_max_height(&style_camera_seting_ddlist_1_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_camera_seting_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_ddlist_1_extra_list_scrollbar_default
	static lv_style_t style_camera_seting_ddlist_1_extra_list_scrollbar_default;
	if (style_camera_seting_ddlist_1_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_ddlist_1_extra_list_scrollbar_default);
	else
		lv_style_init(&style_camera_seting_ddlist_1_extra_list_scrollbar_default);
	lv_style_set_radius(&style_camera_seting_ddlist_1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_camera_seting_ddlist_1_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_grad_color(&style_camera_seting_ddlist_1_extra_list_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_camera_seting_ddlist_1_extra_list_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_ddlist_1_extra_list_scrollbar_default, 255);
	lv_obj_add_style(lv_dropdown_get_list(obj), &style_camera_seting_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
}
//static void kb_event_cb(lv_event_t *e)
//{
//	lv_event_code_t code = lv_event_get_code(e);
//	lv_obj_t *kb = lv_event_get_target(e);
//	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
//		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
//	}
//}
static void ta_event_cb(lv_event_t *e)
{

	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *ta = lv_event_get_target(e);
	lv_obj_t *kb = lv_event_get_user_data(e);
	if (code == LV_EVENT_FOCUSED)
	{
		lv_keyboard_set_textarea(kb, ta);
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_DEFOCUSED)
	{
		lv_keyboard_set_textarea(kb, NULL);
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}

void setup_scr_camera_seting(lv_ui *ui){

	//Write codes camera_seting_cont_1
	ui->camera_seting_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->camera_seting_cont_1, 0, 0);
	lv_obj_set_size(ui->camera_seting_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_cont_1_main_main_default
	static lv_style_t style_camera_seting_cont_1_main_main_default;
	if (style_camera_seting_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_cont_1_main_main_default);
	else
		lv_style_init(&style_camera_seting_cont_1_main_main_default);
	lv_style_set_radius(&style_camera_seting_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_camera_seting_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_camera_seting_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_camera_seting_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_camera_seting_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_camera_seting_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_camera_seting_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_camera_seting_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_camera_seting_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_camera_seting_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->camera_seting_cont_1, &style_camera_seting_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes camera_seting_label_3
	ui->camera_seting_label_3 = lv_label_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_label_3, 9, 63);
	lv_obj_set_size(ui->camera_seting_label_3, 460, 727);
	lv_label_set_text(ui->camera_seting_label_3, "");
	lv_label_set_long_mode(ui->camera_seting_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->camera_seting_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_label_3_main_main_default
	static lv_style_t style_camera_seting_label_3_main_main_default;
	if (style_camera_seting_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_label_3_main_main_default);
	else
		lv_style_init(&style_camera_seting_label_3_main_main_default);
	lv_style_set_radius(&style_camera_seting_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_camera_seting_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_camera_seting_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_camera_seting_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_camera_seting_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_camera_seting_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_camera_seting_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_camera_seting_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_camera_seting_label_3_main_main_default, 0);
	lv_obj_add_style(ui->camera_seting_label_3, &style_camera_seting_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes camera_seting_ddlist_1
	ui->camera_seting_ddlist_1 = lv_dropdown_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_ddlist_1, 238, 284);
	lv_obj_set_width(ui->camera_seting_ddlist_1, 218);
	lv_dropdown_set_options(ui->camera_seting_ddlist_1, "MP4-15\nMP4-25");
	lv_obj_add_event_cb(ui->camera_seting_ddlist_1, _camera_seting_ddlist_1_event_cb, LV_EVENT_READY, NULL);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_ddlist_1_main_main_default
	static lv_style_t style_camera_seting_ddlist_1_main_main_default;
	if (style_camera_seting_ddlist_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_ddlist_1_main_main_default);
	else
		lv_style_init(&style_camera_seting_ddlist_1_main_main_default);
	lv_style_set_radius(&style_camera_seting_ddlist_1_main_main_default, 2);
	lv_style_set_bg_color(&style_camera_seting_ddlist_1_main_main_default, lv_color_make(0x4f, 0x52, 0x55));
	lv_style_set_bg_grad_color(&style_camera_seting_ddlist_1_main_main_default, lv_color_make(0x4f, 0x52, 0x55));
	lv_style_set_bg_grad_dir(&style_camera_seting_ddlist_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_ddlist_1_main_main_default, 255);
	lv_style_set_border_color(&style_camera_seting_ddlist_1_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_camera_seting_ddlist_1_main_main_default, 0);
	lv_style_set_text_color(&style_camera_seting_ddlist_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_ddlist_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_line_space(&style_camera_seting_ddlist_1_main_main_default, 20);
	lv_obj_add_style(ui->camera_seting_ddlist_1, &style_camera_seting_ddlist_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes camera_seting_sw_1
	ui->camera_seting_sw_1 = lv_switch_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_sw_1, 380, 90);
	lv_obj_set_size(ui->camera_seting_sw_1, 74, 36);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_sw_1_main_main_default
	static lv_style_t style_camera_seting_sw_1_main_main_default;
	if (style_camera_seting_sw_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_sw_1_main_main_default);
	else
		lv_style_init(&style_camera_seting_sw_1_main_main_default);
	lv_style_set_radius(&style_camera_seting_sw_1_main_main_default, 100);
	lv_style_set_bg_color(&style_camera_seting_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_color(&style_camera_seting_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_dir(&style_camera_seting_sw_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_sw_1_main_main_default, 255);
	lv_obj_add_style(ui->camera_seting_sw_1, &style_camera_seting_sw_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_camera_seting_sw_1_main_indicator_checked
	static lv_style_t style_camera_seting_sw_1_main_indicator_checked;
	if (style_camera_seting_sw_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_sw_1_main_indicator_checked);
	else
		lv_style_init(&style_camera_seting_sw_1_main_indicator_checked);
	lv_style_set_radius(&style_camera_seting_sw_1_main_indicator_checked, 100);
	lv_style_set_bg_color(&style_camera_seting_sw_1_main_indicator_checked, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_camera_seting_sw_1_main_indicator_checked, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_camera_seting_sw_1_main_indicator_checked, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_sw_1_main_indicator_checked, 255);
	lv_obj_add_style(ui->camera_seting_sw_1, &style_camera_seting_sw_1_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_sw_1_main_knob_default
	static lv_style_t style_camera_seting_sw_1_main_knob_default;
	if (style_camera_seting_sw_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_sw_1_main_knob_default);
	else
		lv_style_init(&style_camera_seting_sw_1_main_knob_default);
	lv_style_set_radius(&style_camera_seting_sw_1_main_knob_default, 100);
	lv_style_set_bg_color(&style_camera_seting_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_camera_seting_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_camera_seting_sw_1_main_knob_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_sw_1_main_knob_default, 255);
	lv_obj_add_style(ui->camera_seting_sw_1, &style_camera_seting_sw_1_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes camera_seting_label_1
	ui->camera_seting_label_1 = lv_label_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_label_1, 0, 0);
	lv_obj_set_size(ui->camera_seting_label_1, 480, 53);
	lv_label_set_text(ui->camera_seting_label_1, "");
	lv_label_set_long_mode(ui->camera_seting_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->camera_seting_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_label_1_main_main_default
	static lv_style_t style_camera_seting_label_1_main_main_default;
	if (style_camera_seting_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_label_1_main_main_default);
	else
		lv_style_init(&style_camera_seting_label_1_main_main_default);
	lv_style_set_radius(&style_camera_seting_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_camera_seting_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_camera_seting_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_camera_seting_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_camera_seting_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_camera_seting_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_camera_seting_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_camera_seting_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_camera_seting_label_1_main_main_default, 0);
	lv_obj_add_style(ui->camera_seting_label_1, &style_camera_seting_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes camera_seting_ta_1
	ui->camera_seting_ta_1 = lv_textarea_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_ta_1, 233, 221);
	lv_obj_set_size(ui->camera_seting_ta_1, 89, 30);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_ta_1_main_main_default
	static lv_style_t style_camera_seting_ta_1_main_main_default;
	if (style_camera_seting_ta_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_ta_1_main_main_default);
	else
		lv_style_init(&style_camera_seting_ta_1_main_main_default);
	lv_style_set_radius(&style_camera_seting_ta_1_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_ta_1_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_bg_grad_color(&style_camera_seting_ta_1_main_main_default, lv_color_make(0x83, 0x86, 0x8b));
	lv_style_set_bg_grad_dir(&style_camera_seting_ta_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_ta_1_main_main_default, 255);
	lv_style_set_border_color(&style_camera_seting_ta_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_camera_seting_ta_1_main_main_default, 0);
	lv_style_set_text_color(&style_camera_seting_ta_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_ta_1_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_camera_seting_ta_1_main_main_default, 2);
	lv_style_set_text_align(&style_camera_seting_ta_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_camera_seting_ta_1_main_main_default, 2);
	lv_style_set_pad_right(&style_camera_seting_ta_1_main_main_default, 2);
	lv_style_set_pad_top(&style_camera_seting_ta_1_main_main_default, 2);
	lv_style_set_pad_bottom(&style_camera_seting_ta_1_main_main_default, 2);
	lv_obj_add_style(ui->camera_seting_ta_1, &style_camera_seting_ta_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_ta_1_main_scrollbar_default
	static lv_style_t style_camera_seting_ta_1_main_scrollbar_default;
	if (style_camera_seting_ta_1_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_ta_1_main_scrollbar_default);
	else
		lv_style_init(&style_camera_seting_ta_1_main_scrollbar_default);
	lv_style_set_radius(&style_camera_seting_ta_1_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_camera_seting_ta_1_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_camera_seting_ta_1_main_scrollbar_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_camera_seting_ta_1_main_scrollbar_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_ta_1_main_scrollbar_default, 255);
	lv_obj_add_style(ui->camera_seting_ta_1, &style_camera_seting_ta_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->camera_seting_ta_1,"3");

    ui->camera_seting_kb_1 = lv_keyboard_create(ui->camera_seting_cont_1);
    lv_obj_add_flag(ui->camera_seting_kb_1, LV_OBJ_FLAG_HIDDEN);
	lv_keyboard_set_textarea(ui->camera_seting_kb_1, ui->camera_seting_ta_1);
	lv_obj_add_event_cb(ui->camera_seting_ta_1, ta_event_cb, LV_EVENT_ALL, ui->camera_seting_kb_1);

	//Write codes camera_seting_img_1
	ui->camera_seting_img_1 = lv_img_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_img_1, 21, 17);
	lv_obj_set_size(ui->camera_seting_img_1, 36, 24);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_img_1_main_main_default
	static lv_style_t style_camera_seting_img_1_main_main_default;
	if (style_camera_seting_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_img_1_main_main_default);
	else
		lv_style_init(&style_camera_seting_img_1_main_main_default);
	lv_style_set_img_recolor(&style_camera_seting_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_camera_seting_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_camera_seting_img_1_main_main_default, 255);
	lv_obj_add_style(ui->camera_seting_img_1, &style_camera_seting_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->camera_seting_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->camera_seting_img_1,&_back_36x24);
	lv_img_set_pivot(ui->camera_seting_img_1, 0,0);
	lv_img_set_angle(ui->camera_seting_img_1, 0);

	//Write codes camera_seting_btn_1
	ui->camera_seting_btn_1 = lv_btn_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_btn_1, 0, 0);
	lv_obj_set_size(ui->camera_seting_btn_1, 85, 50);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_btn_1_main_main_default
	static lv_style_t style_camera_seting_btn_1_main_main_default;
	if (style_camera_seting_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_btn_1_main_main_default);
	else
		lv_style_init(&style_camera_seting_btn_1_main_main_default);
	lv_style_set_radius(&style_camera_seting_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_camera_seting_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_camera_seting_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_camera_seting_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_camera_seting_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_camera_seting_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_camera_seting_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_camera_seting_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->camera_seting_btn_1, &style_camera_seting_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->camera_seting_btn_1_label = lv_label_create(ui->camera_seting_btn_1);
	lv_label_set_text(ui->camera_seting_btn_1_label, "");
	lv_obj_set_style_text_color(ui->camera_seting_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->camera_seting_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->camera_seting_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes camera_seting_label_2
	ui->camera_seting_label_2 = lv_label_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_label_2, 90, 11);
	lv_obj_set_size(ui->camera_seting_label_2, 300, 32);
	lv_label_set_text(ui->camera_seting_label_2, "摄像头设置");
	lv_label_set_long_mode(ui->camera_seting_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->camera_seting_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_label_2_main_main_default
	static lv_style_t style_camera_seting_label_2_main_main_default;
	if (style_camera_seting_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_label_2_main_main_default);
	else
		lv_style_init(&style_camera_seting_label_2_main_main_default);
	lv_style_set_radius(&style_camera_seting_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_camera_seting_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_camera_seting_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_camera_seting_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_label_2_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_camera_seting_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_camera_seting_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_camera_seting_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_camera_seting_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_camera_seting_label_2_main_main_default, 0);
	lv_obj_add_style(ui->camera_seting_label_2, &style_camera_seting_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes camera_seting_label_4
	ui->camera_seting_label_4 = lv_label_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_label_4, 24, 95);
	lv_obj_set_size(ui->camera_seting_label_4, 178, 24);
	lv_label_set_text(ui->camera_seting_label_4, "启用延时摄影");
	lv_label_set_long_mode(ui->camera_seting_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->camera_seting_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_label_4_main_main_default
	static lv_style_t style_camera_seting_label_4_main_main_default;
	if (style_camera_seting_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_label_4_main_main_default);
	else
		lv_style_init(&style_camera_seting_label_4_main_main_default);
	lv_style_set_radius(&style_camera_seting_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_camera_seting_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_camera_seting_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_camera_seting_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_camera_seting_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_camera_seting_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_camera_seting_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_camera_seting_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_camera_seting_label_4_main_main_default, 0);
	lv_obj_add_style(ui->camera_seting_label_4, &style_camera_seting_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes camera_seting_label_9
	ui->camera_seting_label_9 = lv_label_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_label_9, 300, 158);
	lv_obj_set_size(ui->camera_seting_label_9, 150, 24);
	lv_label_set_text(ui->camera_seting_label_9, "每层起始位置");
	lv_label_set_long_mode(ui->camera_seting_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->camera_seting_label_9, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_label_9_main_main_default
	static lv_style_t style_camera_seting_label_9_main_main_default;
	if (style_camera_seting_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_label_9_main_main_default);
	else
		lv_style_init(&style_camera_seting_label_9_main_main_default);
	lv_style_set_radius(&style_camera_seting_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_label_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_camera_seting_label_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_camera_seting_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_camera_seting_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_label_9_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_camera_seting_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_camera_seting_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_camera_seting_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_camera_seting_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_camera_seting_label_9_main_main_default, 0);
	lv_obj_add_style(ui->camera_seting_label_9, &style_camera_seting_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes camera_seting_label_10
	ui->camera_seting_label_10 = lv_label_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_label_10, 321, 224);
	lv_obj_set_size(ui->camera_seting_label_10, 128, 24);
	lv_label_set_text(ui->camera_seting_label_10, "层拍摄一次");
	lv_label_set_long_mode(ui->camera_seting_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->camera_seting_label_10, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_label_10_main_main_default
	static lv_style_t style_camera_seting_label_10_main_main_default;
	if (style_camera_seting_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_label_10_main_main_default);
	else
		lv_style_init(&style_camera_seting_label_10_main_main_default);
	lv_style_set_radius(&style_camera_seting_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_label_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_camera_seting_label_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_camera_seting_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_camera_seting_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_label_10_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_camera_seting_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_camera_seting_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_camera_seting_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_camera_seting_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_camera_seting_label_10_main_main_default, 0);
	lv_obj_add_style(ui->camera_seting_label_10, &style_camera_seting_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes camera_seting_label_12
	ui->camera_seting_label_12 = lv_label_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_label_12, 196, 224);
	lv_obj_set_size(ui->camera_seting_label_12, 31, 24);
	lv_label_set_text(ui->camera_seting_label_12, "每");
	lv_label_set_long_mode(ui->camera_seting_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->camera_seting_label_12, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_label_12_main_main_default
	static lv_style_t style_camera_seting_label_12_main_main_default;
	if (style_camera_seting_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_label_12_main_main_default);
	else
		lv_style_init(&style_camera_seting_label_12_main_main_default);
	lv_style_set_radius(&style_camera_seting_label_12_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_label_12_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_camera_seting_label_12_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_camera_seting_label_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_label_12_main_main_default, 0);
	lv_style_set_text_color(&style_camera_seting_label_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_label_12_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_camera_seting_label_12_main_main_default, 0);
	lv_style_set_pad_left(&style_camera_seting_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_camera_seting_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_camera_seting_label_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_camera_seting_label_12_main_main_default, 0);
	lv_obj_add_style(ui->camera_seting_label_12, &style_camera_seting_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes camera_seting_label_5
	ui->camera_seting_label_5 = lv_label_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_label_5, 24, 158);
	lv_obj_set_size(ui->camera_seting_label_5, 196, 24);
	lv_label_set_text(ui->camera_seting_label_5, "拍照位置");
	lv_label_set_long_mode(ui->camera_seting_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->camera_seting_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_label_5_main_main_default
	static lv_style_t style_camera_seting_label_5_main_main_default;
	if (style_camera_seting_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_label_5_main_main_default);
	else
		lv_style_init(&style_camera_seting_label_5_main_main_default);
	lv_style_set_radius(&style_camera_seting_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_camera_seting_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_camera_seting_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_camera_seting_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_camera_seting_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_camera_seting_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_camera_seting_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_camera_seting_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_camera_seting_label_5_main_main_default, 0);
	lv_obj_add_style(ui->camera_seting_label_5, &style_camera_seting_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes camera_seting_label_6
	ui->camera_seting_label_6 = lv_label_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_label_6, 24, 221);
	lv_obj_set_size(ui->camera_seting_label_6, 175, 24);
	lv_label_set_text(ui->camera_seting_label_6, "拍照频率");
	lv_label_set_long_mode(ui->camera_seting_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->camera_seting_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_label_6_main_main_default
	static lv_style_t style_camera_seting_label_6_main_main_default;
	if (style_camera_seting_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_label_6_main_main_default);
	else
		lv_style_init(&style_camera_seting_label_6_main_main_default);
	lv_style_set_radius(&style_camera_seting_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_camera_seting_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_camera_seting_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_camera_seting_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_label_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_camera_seting_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_camera_seting_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_camera_seting_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_camera_seting_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_camera_seting_label_6_main_main_default, 0);
	lv_obj_add_style(ui->camera_seting_label_6, &style_camera_seting_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes camera_seting_label_7
	ui->camera_seting_label_7 = lv_label_create(ui->camera_seting_cont_1);
	lv_obj_set_pos(ui->camera_seting_label_7, 24, 285);
	lv_obj_set_size(ui->camera_seting_label_7, 205, 24);
	lv_label_set_text(ui->camera_seting_label_7, "渲染方式");
	lv_label_set_long_mode(ui->camera_seting_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->camera_seting_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_camera_seting_label_7_main_main_default
	static lv_style_t style_camera_seting_label_7_main_main_default;
	if (style_camera_seting_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_camera_seting_label_7_main_main_default);
	else
		lv_style_init(&style_camera_seting_label_7_main_main_default);
	lv_style_set_radius(&style_camera_seting_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_camera_seting_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_camera_seting_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_camera_seting_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_camera_seting_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_camera_seting_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_camera_seting_label_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_camera_seting_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_camera_seting_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_camera_seting_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_camera_seting_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_camera_seting_label_7_main_main_default, 0);
	lv_obj_add_style(ui->camera_seting_label_7, &style_camera_seting_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_camera_seting(ui);
}
