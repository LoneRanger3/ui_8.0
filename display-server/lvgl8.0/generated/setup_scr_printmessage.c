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


void setup_scr_printmessage(lv_ui *ui){

	//Write codes printmessage_cont_1
	ui->printmessage_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->printmessage_cont_1, 0, 0);
	lv_obj_set_size(ui->printmessage_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_printmessage_cont_1_main_main_default
	static lv_style_t style_printmessage_cont_1_main_main_default;
	if (style_printmessage_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printmessage_cont_1_main_main_default);
	else
		lv_style_init(&style_printmessage_cont_1_main_main_default);
	lv_style_set_radius(&style_printmessage_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_printmessage_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_printmessage_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_printmessage_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printmessage_cont_1_main_main_default, 144);
	lv_style_set_border_color(&style_printmessage_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_printmessage_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_printmessage_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_printmessage_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_printmessage_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_printmessage_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printmessage_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->printmessage_cont_1, &style_printmessage_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printmessage_label_1
	ui->printmessage_label_1 = lv_label_create(ui->printmessage_cont_1);
	lv_obj_set_pos(ui->printmessage_label_1, 32, 179);
	lv_obj_set_size(ui->printmessage_label_1, 418, 451);
	lv_label_set_text(ui->printmessage_label_1, "");
	lv_label_set_long_mode(ui->printmessage_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printmessage_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printmessage_label_1_main_main_default
	static lv_style_t style_printmessage_label_1_main_main_default;
	if (style_printmessage_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printmessage_label_1_main_main_default);
	else
		lv_style_init(&style_printmessage_label_1_main_main_default);
	lv_style_set_radius(&style_printmessage_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_printmessage_label_1_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_printmessage_label_1_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_printmessage_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printmessage_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_printmessage_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_printmessage_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_printmessage_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_printmessage_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_printmessage_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printmessage_label_1_main_main_default, 0);
	lv_obj_add_style(ui->printmessage_label_1, &style_printmessage_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printmessage_label_2
	ui->printmessage_label_2 = lv_label_create(ui->printmessage_cont_1);
	lv_obj_set_pos(ui->printmessage_label_2, 99, 199);
	lv_obj_set_size(ui->printmessage_label_2, 281, 32);
	lv_label_set_text(ui->printmessage_label_2, "提示");
	lv_label_set_long_mode(ui->printmessage_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printmessage_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printmessage_label_2_main_main_default
	static lv_style_t style_printmessage_label_2_main_main_default;
	if (style_printmessage_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printmessage_label_2_main_main_default);
	else
		lv_style_init(&style_printmessage_label_2_main_main_default);
	lv_style_set_radius(&style_printmessage_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_printmessage_label_2_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_printmessage_label_2_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_printmessage_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printmessage_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_printmessage_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_printmessage_label_2_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_printmessage_label_2_main_main_default, 0);
	lv_style_set_pad_left(&style_printmessage_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_printmessage_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_printmessage_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printmessage_label_2_main_main_default, 0);
	lv_obj_add_style(ui->printmessage_label_2, &style_printmessage_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printmessage_label_3
	ui->printmessage_label_3 = lv_label_create(ui->printmessage_cont_1);
	lv_obj_set_pos(ui->printmessage_label_3, 60, 309);
	lv_obj_set_size(ui->printmessage_label_3, 365, 130);
	lv_label_set_text(ui->printmessage_label_3, "已检测到耗材使用完，请检查并更换耗材后点击按钮重新开始打印。");
	lv_label_set_long_mode(ui->printmessage_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->printmessage_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_printmessage_label_3_main_main_default
	static lv_style_t style_printmessage_label_3_main_main_default;
	if (style_printmessage_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printmessage_label_3_main_main_default);
	else
		lv_style_init(&style_printmessage_label_3_main_main_default);
	lv_style_set_radius(&style_printmessage_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_printmessage_label_3_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_color(&style_printmessage_label_3_main_main_default, lv_color_make(0x29, 0x29, 0x2c));
	lv_style_set_bg_grad_dir(&style_printmessage_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printmessage_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_printmessage_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_printmessage_label_3_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_printmessage_label_3_main_main_default, 0);
	lv_style_set_pad_left(&style_printmessage_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_printmessage_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_printmessage_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_printmessage_label_3_main_main_default, 0);
	lv_obj_add_style(ui->printmessage_label_3, &style_printmessage_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes printmessage_btn_3
	ui->printmessage_btn_3 = lv_btn_create(ui->printmessage_cont_1);
	lv_obj_set_pos(ui->printmessage_btn_3, 167, 550);
	lv_obj_set_size(ui->printmessage_btn_3, 146, 60);

	//Write style state: LV_STATE_DEFAULT for style_printmessage_btn_3_main_main_default
	static lv_style_t style_printmessage_btn_3_main_main_default;
	if (style_printmessage_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_printmessage_btn_3_main_main_default);
	else
		lv_style_init(&style_printmessage_btn_3_main_main_default);
	lv_style_set_radius(&style_printmessage_btn_3_main_main_default, 8);
	lv_style_set_bg_color(&style_printmessage_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_printmessage_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_printmessage_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_printmessage_btn_3_main_main_default, 255);
	lv_style_set_shadow_color(&style_printmessage_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_printmessage_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_printmessage_btn_3_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_printmessage_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_printmessage_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->printmessage_btn_3, &style_printmessage_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->printmessage_btn_3_label = lv_label_create(ui->printmessage_btn_3);
	lv_label_set_text(ui->printmessage_btn_3_label, "确定");
	lv_obj_set_style_text_color(ui->printmessage_btn_3_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->printmessage_btn_3_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->printmessage_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->printmessage_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_printmessage(ui);
}
