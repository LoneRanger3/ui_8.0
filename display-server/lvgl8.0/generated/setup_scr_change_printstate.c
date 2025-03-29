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


void setup_scr_change_printstate(lv_ui *ui){

	//Write codes change_printstate_cont_1
	ui->change_printstate_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->change_printstate_cont_1, 0, 0);
	lv_obj_set_size(ui->change_printstate_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_change_printstate_cont_1_main_main_default
	static lv_style_t style_change_printstate_cont_1_main_main_default;
	if (style_change_printstate_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_change_printstate_cont_1_main_main_default);
	else
		lv_style_init(&style_change_printstate_cont_1_main_main_default);
	lv_style_set_radius(&style_change_printstate_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_change_printstate_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_change_printstate_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_change_printstate_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_change_printstate_cont_1_main_main_default, 144);
	lv_style_set_border_color(&style_change_printstate_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_change_printstate_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_change_printstate_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_change_printstate_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_change_printstate_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_change_printstate_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_change_printstate_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->change_printstate_cont_1, &style_change_printstate_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes change_printstate_label_1
	ui->change_printstate_label_1 = lv_label_create(ui->change_printstate_cont_1);
	lv_obj_set_pos(ui->change_printstate_label_1, 50, 155);
	lv_obj_set_size(ui->change_printstate_label_1, 380, 32);
	lv_label_set_text(ui->change_printstate_label_1, "请选择您需要进行的操作!");
	lv_label_set_long_mode(ui->change_printstate_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->change_printstate_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_change_printstate_label_1_main_main_default
	static lv_style_t style_change_printstate_label_1_main_main_default;
	if (style_change_printstate_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_change_printstate_label_1_main_main_default);
	else
		lv_style_init(&style_change_printstate_label_1_main_main_default);
	lv_style_set_radius(&style_change_printstate_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_change_printstate_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_change_printstate_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_change_printstate_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_change_printstate_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_change_printstate_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_change_printstate_label_1_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_change_printstate_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_change_printstate_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_change_printstate_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_change_printstate_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_change_printstate_label_1_main_main_default, 0);
	lv_obj_add_style(ui->change_printstate_label_1, &style_change_printstate_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes change_printstate_btn_1
	ui->change_printstate_btn_1 = lv_btn_create(ui->change_printstate_cont_1);
	lv_obj_set_pos(ui->change_printstate_btn_1, 167, 243);
	lv_obj_set_size(ui->change_printstate_btn_1, 146, 60);

	//Write style state: LV_STATE_DEFAULT for style_change_printstate_btn_1_main_main_default
	static lv_style_t style_change_printstate_btn_1_main_main_default;
	if (style_change_printstate_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_change_printstate_btn_1_main_main_default);
	else
		lv_style_init(&style_change_printstate_btn_1_main_main_default);
	lv_style_set_radius(&style_change_printstate_btn_1_main_main_default, 8);
	lv_style_set_bg_color(&style_change_printstate_btn_1_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_change_printstate_btn_1_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_change_printstate_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_change_printstate_btn_1_main_main_default, 255);
	lv_style_set_shadow_color(&style_change_printstate_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_change_printstate_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_change_printstate_btn_1_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_change_printstate_btn_1_main_main_default, 2);
	lv_style_set_border_opa(&style_change_printstate_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->change_printstate_btn_1, &style_change_printstate_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->change_printstate_btn_1_label = lv_label_create(ui->change_printstate_btn_1);
	lv_label_set_text(ui->change_printstate_btn_1_label, "继续");
	lv_obj_set_style_text_color(ui->change_printstate_btn_1_label, lv_color_make(0x42, 0xbd, 0xd8), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->change_printstate_btn_1_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->change_printstate_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->change_printstate_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes change_printstate_btn_2
	ui->change_printstate_btn_2 = lv_btn_create(ui->change_printstate_cont_1);
	lv_obj_set_pos(ui->change_printstate_btn_2, 167, 351);
	lv_obj_set_size(ui->change_printstate_btn_2, 146, 60);

	//Write style state: LV_STATE_DEFAULT for style_change_printstate_btn_2_main_main_default
	static lv_style_t style_change_printstate_btn_2_main_main_default;
	if (style_change_printstate_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_change_printstate_btn_2_main_main_default);
	else
		lv_style_init(&style_change_printstate_btn_2_main_main_default);
	lv_style_set_radius(&style_change_printstate_btn_2_main_main_default, 8);
	lv_style_set_bg_color(&style_change_printstate_btn_2_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_change_printstate_btn_2_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_change_printstate_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_change_printstate_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_change_printstate_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_change_printstate_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_change_printstate_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_change_printstate_btn_2_main_main_default, 2);
	lv_style_set_border_opa(&style_change_printstate_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->change_printstate_btn_2, &style_change_printstate_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->change_printstate_btn_2_label = lv_label_create(ui->change_printstate_btn_2);
	lv_label_set_text(ui->change_printstate_btn_2_label, "停止");
	lv_obj_set_style_text_color(ui->change_printstate_btn_2_label, lv_color_make(0x42, 0xbd, 0xd8), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->change_printstate_btn_2_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->change_printstate_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->change_printstate_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes change_printstate_btn_3
	ui->change_printstate_btn_3 = lv_btn_create(ui->change_printstate_cont_1);
	lv_obj_set_pos(ui->change_printstate_btn_3, 167, 459);
	lv_obj_set_size(ui->change_printstate_btn_3, 146, 60);

	//Write style state: LV_STATE_DEFAULT for style_change_printstate_btn_3_main_main_default
	static lv_style_t style_change_printstate_btn_3_main_main_default;
	if (style_change_printstate_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_change_printstate_btn_3_main_main_default);
	else
		lv_style_init(&style_change_printstate_btn_3_main_main_default);
	lv_style_set_radius(&style_change_printstate_btn_3_main_main_default, 8);
	lv_style_set_bg_color(&style_change_printstate_btn_3_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_change_printstate_btn_3_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_change_printstate_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_change_printstate_btn_3_main_main_default, 255);
	lv_style_set_shadow_color(&style_change_printstate_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_change_printstate_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_change_printstate_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_change_printstate_btn_3_main_main_default, 2);
	lv_style_set_border_opa(&style_change_printstate_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->change_printstate_btn_3, &style_change_printstate_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->change_printstate_btn_3_label = lv_label_create(ui->change_printstate_btn_3);
	lv_label_set_text(ui->change_printstate_btn_3_label, "返回");
	lv_obj_set_style_text_color(ui->change_printstate_btn_3_label, lv_color_make(0x42, 0xbd, 0xd8), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->change_printstate_btn_3_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->change_printstate_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->change_printstate_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_change_printstate(ui);
}