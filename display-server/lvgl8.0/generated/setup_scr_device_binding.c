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


void setup_scr_device_binding(lv_ui *ui){

	//Write codes device_binding_cont_1
	ui->device_binding_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->device_binding_cont_1, 0, 0);
	lv_obj_set_size(ui->device_binding_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_device_binding_cont_1_main_main_default
	static lv_style_t style_device_binding_cont_1_main_main_default;
	if (style_device_binding_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_device_binding_cont_1_main_main_default);
	else
		lv_style_init(&style_device_binding_cont_1_main_main_default);
	lv_style_set_radius(&style_device_binding_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_device_binding_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_device_binding_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_device_binding_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_device_binding_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_device_binding_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_device_binding_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_device_binding_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_device_binding_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_device_binding_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_device_binding_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_device_binding_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->device_binding_cont_1, &style_device_binding_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes device_binding_label_3
	ui->device_binding_label_3 = lv_label_create(ui->device_binding_cont_1);
	lv_obj_set_pos(ui->device_binding_label_3, 8, 63);
	lv_obj_set_size(ui->device_binding_label_3, 460, 727);
	lv_label_set_text(ui->device_binding_label_3, "");
	lv_label_set_long_mode(ui->device_binding_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->device_binding_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_device_binding_label_3_main_main_default
	static lv_style_t style_device_binding_label_3_main_main_default;
	if (style_device_binding_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_device_binding_label_3_main_main_default);
	else
		lv_style_init(&style_device_binding_label_3_main_main_default);
	lv_style_set_radius(&style_device_binding_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_device_binding_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_device_binding_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_device_binding_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_device_binding_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_device_binding_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_device_binding_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_device_binding_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_device_binding_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_device_binding_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_device_binding_label_3_main_main_default, 0);
	lv_obj_add_style(ui->device_binding_label_3, &style_device_binding_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes device_binding_label_4
	ui->device_binding_label_4 = lv_label_create(ui->device_binding_cont_1);
	lv_obj_set_pos(ui->device_binding_label_4, 67, 459);
	lv_obj_set_size(ui->device_binding_label_4, 365, 27);
	lv_label_set_text(ui->device_binding_label_4, "请使用创想云app扫码绑定设备");
	lv_label_set_long_mode(ui->device_binding_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->device_binding_label_4, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_device_binding_label_4_main_main_default
	static lv_style_t style_device_binding_label_4_main_main_default;
	if (style_device_binding_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_device_binding_label_4_main_main_default);
	else
		lv_style_init(&style_device_binding_label_4_main_main_default);
	lv_style_set_radius(&style_device_binding_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_device_binding_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_device_binding_label_4_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_device_binding_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_device_binding_label_4_main_main_default, 255);
	lv_style_set_text_color(&style_device_binding_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_device_binding_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_device_binding_label_4_main_main_default, 2);
	lv_style_set_pad_left(&style_device_binding_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_device_binding_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_device_binding_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_device_binding_label_4_main_main_default, 0);
	lv_obj_add_style(ui->device_binding_label_4, &style_device_binding_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes device_binding_img_2
	ui->device_binding_img_2 = lv_img_create(ui->device_binding_cont_1);
	lv_obj_set_pos(ui->device_binding_img_2, 100, 159);
	lv_obj_set_size(ui->device_binding_img_2, 280, 280);

	//Write style state: LV_STATE_DEFAULT for style_device_binding_img_2_main_main_default
	static lv_style_t style_device_binding_img_2_main_main_default;
	if (style_device_binding_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_device_binding_img_2_main_main_default);
	else
		lv_style_init(&style_device_binding_img_2_main_main_default);
	lv_style_set_img_recolor(&style_device_binding_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_device_binding_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_device_binding_img_2_main_main_default, 255);
	lv_obj_add_style(ui->device_binding_img_2, &style_device_binding_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes device_binding_label_1
	ui->device_binding_label_1 = lv_label_create(ui->device_binding_cont_1);
	lv_obj_set_pos(ui->device_binding_label_1, 0, 0);
	lv_obj_set_size(ui->device_binding_label_1, 480, 53);
	lv_label_set_text(ui->device_binding_label_1, "");
	lv_label_set_long_mode(ui->device_binding_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->device_binding_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_device_binding_label_1_main_main_default
	static lv_style_t style_device_binding_label_1_main_main_default;
	if (style_device_binding_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_device_binding_label_1_main_main_default);
	else
		lv_style_init(&style_device_binding_label_1_main_main_default);
	lv_style_set_radius(&style_device_binding_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_device_binding_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_device_binding_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_device_binding_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_device_binding_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_device_binding_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_device_binding_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_device_binding_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_device_binding_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_device_binding_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_device_binding_label_1_main_main_default, 0);
	lv_obj_add_style(ui->device_binding_label_1, &style_device_binding_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes device_binding_img_1
	ui->device_binding_img_1 = lv_img_create(ui->device_binding_cont_1);
	lv_obj_set_pos(ui->device_binding_img_1, 21, 17);
	lv_obj_set_size(ui->device_binding_img_1, 36, 24);

	//Write style state: LV_STATE_DEFAULT for style_device_binding_img_1_main_main_default
	static lv_style_t style_device_binding_img_1_main_main_default;
	if (style_device_binding_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_device_binding_img_1_main_main_default);
	else
		lv_style_init(&style_device_binding_img_1_main_main_default);
	lv_style_set_img_recolor(&style_device_binding_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_device_binding_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_device_binding_img_1_main_main_default, 255);
	lv_obj_add_style(ui->device_binding_img_1, &style_device_binding_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->device_binding_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->device_binding_img_1,&_back_36x24);
	lv_img_set_pivot(ui->device_binding_img_1, 0,0);
	lv_img_set_angle(ui->device_binding_img_1, 0);

	//Write codes device_binding_btn_1
	ui->device_binding_btn_1 = lv_btn_create(ui->device_binding_cont_1);
	lv_obj_set_pos(ui->device_binding_btn_1, 0, 0);
	lv_obj_set_size(ui->device_binding_btn_1, 85, 50);

	//Write style state: LV_STATE_DEFAULT for style_device_binding_btn_1_main_main_default
	static lv_style_t style_device_binding_btn_1_main_main_default;
	if (style_device_binding_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_device_binding_btn_1_main_main_default);
	else
		lv_style_init(&style_device_binding_btn_1_main_main_default);
	lv_style_set_radius(&style_device_binding_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_device_binding_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_device_binding_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_device_binding_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_device_binding_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_device_binding_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_device_binding_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_device_binding_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_device_binding_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_device_binding_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->device_binding_btn_1, &style_device_binding_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->device_binding_btn_1_label = lv_label_create(ui->device_binding_btn_1);
	lv_label_set_text(ui->device_binding_btn_1_label, "");
	lv_obj_set_style_text_color(ui->device_binding_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->device_binding_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->device_binding_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes device_binding_label_2
	ui->device_binding_label_2 = lv_label_create(ui->device_binding_cont_1);
	lv_obj_set_pos(ui->device_binding_label_2, 90, 11);
	lv_obj_set_size(ui->device_binding_label_2, 300, 32);
	lv_label_set_text(ui->device_binding_label_2, "设备绑定");
	lv_label_set_long_mode(ui->device_binding_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->device_binding_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_device_binding_label_2_main_main_default
	static lv_style_t style_device_binding_label_2_main_main_default;
	if (style_device_binding_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_device_binding_label_2_main_main_default);
	else
		lv_style_init(&style_device_binding_label_2_main_main_default);
	lv_style_set_radius(&style_device_binding_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_device_binding_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_device_binding_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_device_binding_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_device_binding_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_device_binding_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_device_binding_label_2_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_device_binding_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_device_binding_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_device_binding_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_device_binding_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_device_binding_label_2_main_main_default, 0);
	lv_obj_add_style(ui->device_binding_label_2, &style_device_binding_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_device_binding(ui);
}
