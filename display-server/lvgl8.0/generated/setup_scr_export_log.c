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


void setup_scr_export_log(lv_ui *ui){

	//Write codes export_log_cont_1
	ui->export_log_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->export_log_cont_1, 0, 0);
	lv_obj_set_size(ui->export_log_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_export_log_cont_1_main_main_default
	static lv_style_t style_export_log_cont_1_main_main_default;
	if (style_export_log_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_export_log_cont_1_main_main_default);
	else
		lv_style_init(&style_export_log_cont_1_main_main_default);
	lv_style_set_radius(&style_export_log_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_export_log_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_export_log_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_export_log_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_export_log_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_export_log_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_export_log_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_export_log_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_export_log_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_export_log_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_export_log_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_export_log_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->export_log_cont_1, &style_export_log_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes export_log_label_3
	ui->export_log_label_3 = lv_label_create(ui->export_log_cont_1);
	lv_obj_set_pos(ui->export_log_label_3, 10, 58);
	lv_obj_set_size(ui->export_log_label_3, 460, 727);
	lv_label_set_text(ui->export_log_label_3, "");
	lv_label_set_long_mode(ui->export_log_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->export_log_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_export_log_label_3_main_main_default
	static lv_style_t style_export_log_label_3_main_main_default;
	if (style_export_log_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_export_log_label_3_main_main_default);
	else
		lv_style_init(&style_export_log_label_3_main_main_default);
	lv_style_set_radius(&style_export_log_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_export_log_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_export_log_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_export_log_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_export_log_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_export_log_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_export_log_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_export_log_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_export_log_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_export_log_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_export_log_label_3_main_main_default, 0);
	lv_obj_add_style(ui->export_log_label_3, &style_export_log_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes export_log_btn_2
	ui->export_log_btn_2 = lv_btn_create(ui->export_log_cont_1);
	lv_obj_set_pos(ui->export_log_btn_2, 27, 700);
	lv_obj_set_size(ui->export_log_btn_2, 426, 65);

	//Write style state: LV_STATE_DEFAULT for style_export_log_btn_2_main_main_default
	static lv_style_t style_export_log_btn_2_main_main_default;
	if (style_export_log_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_export_log_btn_2_main_main_default);
	else
		lv_style_init(&style_export_log_btn_2_main_main_default);
	lv_style_set_radius(&style_export_log_btn_2_main_main_default, 8);
	lv_style_set_bg_color(&style_export_log_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_export_log_btn_2_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_export_log_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_export_log_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_export_log_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_export_log_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_export_log_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_export_log_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_export_log_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->export_log_btn_2, &style_export_log_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->export_log_btn_2_label = lv_label_create(ui->export_log_btn_2);
	lv_label_set_text(ui->export_log_btn_2_label, "导出");
	lv_obj_set_style_text_color(ui->export_log_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->export_log_btn_2_label, &lv_font_simsun_28, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->export_log_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->export_log_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes export_log_label_1
	ui->export_log_label_1 = lv_label_create(ui->export_log_cont_1);
	lv_obj_set_pos(ui->export_log_label_1, 0, 0);
	lv_obj_set_size(ui->export_log_label_1, 480, 53);
	lv_label_set_text(ui->export_log_label_1, "");
	lv_label_set_long_mode(ui->export_log_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->export_log_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_export_log_label_1_main_main_default
	static lv_style_t style_export_log_label_1_main_main_default;
	if (style_export_log_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_export_log_label_1_main_main_default);
	else
		lv_style_init(&style_export_log_label_1_main_main_default);
	lv_style_set_radius(&style_export_log_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_export_log_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_export_log_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_export_log_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_export_log_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_export_log_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_export_log_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_export_log_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_export_log_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_export_log_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_export_log_label_1_main_main_default, 0);
	lv_obj_add_style(ui->export_log_label_1, &style_export_log_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes export_log_label_4
	ui->export_log_label_4 = lv_label_create(ui->export_log_cont_1);
	lv_obj_set_pos(ui->export_log_label_4, 39, 86);
	lv_obj_set_size(ui->export_log_label_4, 350, 28);
	lv_label_set_text(ui->export_log_label_4, "默认导出到U盘根目录");
	lv_label_set_long_mode(ui->export_log_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->export_log_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_export_log_label_4_main_main_default
	static lv_style_t style_export_log_label_4_main_main_default;
	if (style_export_log_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_export_log_label_4_main_main_default);
	else
		lv_style_init(&style_export_log_label_4_main_main_default);
	lv_style_set_radius(&style_export_log_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_export_log_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_export_log_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_export_log_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_export_log_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_export_log_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_export_log_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_export_log_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_export_log_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_export_log_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_export_log_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_export_log_label_4_main_main_default, 0);
	lv_obj_add_style(ui->export_log_label_4, &style_export_log_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes export_log_img_1
	ui->export_log_img_1 = lv_img_create(ui->export_log_cont_1);
	lv_obj_set_pos(ui->export_log_img_1, 21, 17);
	lv_obj_set_size(ui->export_log_img_1, 36, 24);

	//Write style state: LV_STATE_DEFAULT for style_export_log_img_1_main_main_default
	static lv_style_t style_export_log_img_1_main_main_default;
	if (style_export_log_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_export_log_img_1_main_main_default);
	else
		lv_style_init(&style_export_log_img_1_main_main_default);
	lv_style_set_img_recolor(&style_export_log_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_export_log_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_export_log_img_1_main_main_default, 255);
	lv_obj_add_style(ui->export_log_img_1, &style_export_log_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->export_log_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->export_log_img_1,&_back_36x24);
	lv_img_set_pivot(ui->export_log_img_1, 0,0);
	lv_img_set_angle(ui->export_log_img_1, 0);

	//Write codes export_log_btn_1
	ui->export_log_btn_1 = lv_btn_create(ui->export_log_cont_1);
	lv_obj_set_pos(ui->export_log_btn_1, 0, 0);
	lv_obj_set_size(ui->export_log_btn_1, 85, 50);

	//Write style state: LV_STATE_DEFAULT for style_export_log_btn_1_main_main_default
	static lv_style_t style_export_log_btn_1_main_main_default;
	if (style_export_log_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_export_log_btn_1_main_main_default);
	else
		lv_style_init(&style_export_log_btn_1_main_main_default);
	lv_style_set_radius(&style_export_log_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_export_log_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_export_log_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_export_log_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_export_log_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_export_log_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_export_log_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_export_log_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_export_log_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_export_log_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->export_log_btn_1, &style_export_log_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->export_log_btn_1_label = lv_label_create(ui->export_log_btn_1);
	lv_label_set_text(ui->export_log_btn_1_label, "");
	lv_obj_set_style_text_color(ui->export_log_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->export_log_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->export_log_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes export_log_label_2
	ui->export_log_label_2 = lv_label_create(ui->export_log_cont_1);
	lv_obj_set_pos(ui->export_log_label_2, 90, 11);
	lv_obj_set_size(ui->export_log_label_2, 300, 32);
	lv_label_set_text(ui->export_log_label_2, "导出日志");
	lv_label_set_long_mode(ui->export_log_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->export_log_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_export_log_label_2_main_main_default
	static lv_style_t style_export_log_label_2_main_main_default;
	if (style_export_log_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_export_log_label_2_main_main_default);
	else
		lv_style_init(&style_export_log_label_2_main_main_default);
	lv_style_set_radius(&style_export_log_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_export_log_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_export_log_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_export_log_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_export_log_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_export_log_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_export_log_label_2_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_export_log_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_export_log_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_export_log_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_export_log_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_export_log_label_2_main_main_default, 0);
	lv_obj_add_style(ui->export_log_label_2, &style_export_log_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_export_log(ui);
}
