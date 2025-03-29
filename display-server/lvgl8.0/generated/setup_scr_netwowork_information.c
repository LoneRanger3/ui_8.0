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


void setup_scr_netwowork_information(lv_ui *ui){

	//Write codes netwowork_information_cont_1
	ui->netwowork_information_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->netwowork_information_cont_1, 0, 0);
	lv_obj_set_size(ui->netwowork_information_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_cont_1_main_main_default
	static lv_style_t style_netwowork_information_cont_1_main_main_default;
	if (style_netwowork_information_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_cont_1_main_main_default);
	else
		lv_style_init(&style_netwowork_information_cont_1_main_main_default);
	lv_style_set_radius(&style_netwowork_information_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_netwowork_information_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_netwowork_information_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_netwowork_information_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_netwowork_information_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_netwowork_information_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_netwowork_information_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_cont_1, &style_netwowork_information_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes netwowork_information_label_3
	ui->netwowork_information_label_3 = lv_label_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_label_3, 10, 63);
	lv_obj_set_size(ui->netwowork_information_label_3, 460, 727);
	lv_label_set_text(ui->netwowork_information_label_3, "");
	lv_label_set_long_mode(ui->netwowork_information_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->netwowork_information_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_label_3_main_main_default
	static lv_style_t style_netwowork_information_label_3_main_main_default;
	if (style_netwowork_information_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_label_3_main_main_default);
	else
		lv_style_init(&style_netwowork_information_label_3_main_main_default);
	lv_style_set_radius(&style_netwowork_information_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_netwowork_information_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_netwowork_information_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_netwowork_information_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_netwowork_information_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_netwowork_information_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_label_3_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_label_3, &style_netwowork_information_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes netwowork_information_label_1
	ui->netwowork_information_label_1 = lv_label_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_label_1, 0, 0);
	lv_obj_set_size(ui->netwowork_information_label_1, 480, 53);
	lv_label_set_text(ui->netwowork_information_label_1, "");
	lv_label_set_long_mode(ui->netwowork_information_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->netwowork_information_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_label_1_main_main_default
	static lv_style_t style_netwowork_information_label_1_main_main_default;
	if (style_netwowork_information_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_label_1_main_main_default);
	else
		lv_style_init(&style_netwowork_information_label_1_main_main_default);
	lv_style_set_radius(&style_netwowork_information_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_netwowork_information_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_netwowork_information_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_netwowork_information_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_netwowork_information_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_netwowork_information_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_label_1_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_label_1, &style_netwowork_information_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes netwowork_information_img_1
	ui->netwowork_information_img_1 = lv_img_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_img_1, 21, 17);
	lv_obj_set_size(ui->netwowork_information_img_1, 36, 24);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_img_1_main_main_default
	static lv_style_t style_netwowork_information_img_1_main_main_default;
	if (style_netwowork_information_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_img_1_main_main_default);
	else
		lv_style_init(&style_netwowork_information_img_1_main_main_default);
	lv_style_set_img_recolor(&style_netwowork_information_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_netwowork_information_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_netwowork_information_img_1_main_main_default, 255);
	lv_obj_add_style(ui->netwowork_information_img_1, &style_netwowork_information_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->netwowork_information_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->netwowork_information_img_1,&_back_36x24);
	lv_img_set_pivot(ui->netwowork_information_img_1, 0,0);
	lv_img_set_angle(ui->netwowork_information_img_1, 0);

	//Write codes netwowork_information_btn_1
	ui->netwowork_information_btn_1 = lv_btn_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_btn_1, 0, 0);
	lv_obj_set_size(ui->netwowork_information_btn_1, 85, 50);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_btn_1_main_main_default
	static lv_style_t style_netwowork_information_btn_1_main_main_default;
	if (style_netwowork_information_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_btn_1_main_main_default);
	else
		lv_style_init(&style_netwowork_information_btn_1_main_main_default);
	lv_style_set_radius(&style_netwowork_information_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_netwowork_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_netwowork_information_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_netwowork_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_netwowork_information_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_netwowork_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_netwowork_information_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_netwowork_information_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->netwowork_information_btn_1, &style_netwowork_information_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->netwowork_information_btn_1_label = lv_label_create(ui->netwowork_information_btn_1);
	lv_label_set_text(ui->netwowork_information_btn_1_label, "");
	lv_obj_set_style_text_color(ui->netwowork_information_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->netwowork_information_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->netwowork_information_btn_1_label, LV_ALIGN_CENTER, 0, 0);


	//Write codes netwowork_information_label_2
	ui->netwowork_information_label_2 = lv_label_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_label_2, 90, 11);
	lv_obj_set_size(ui->netwowork_information_label_2, 300, 32);
	lv_label_set_text(ui->netwowork_information_label_2, "本地网络");
	lv_label_set_long_mode(ui->netwowork_information_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->netwowork_information_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_label_2_main_main_default
	static lv_style_t style_netwowork_information_label_2_main_main_default;
	if (style_netwowork_information_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_label_2_main_main_default);
	else
		lv_style_init(&style_netwowork_information_label_2_main_main_default);
	lv_style_set_radius(&style_netwowork_information_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_netwowork_information_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_netwowork_information_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_netwowork_information_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_netwowork_information_label_2_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_netwowork_information_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_netwowork_information_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_label_2_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_label_2, &style_netwowork_information_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes netwowork_information_label_4
	ui->netwowork_information_label_4 = lv_label_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_label_4, 30, 80);
	lv_obj_set_size(ui->netwowork_information_label_4, 178, 24);
	lv_label_set_text(ui->netwowork_information_label_4, "IP地址:");
	lv_label_set_long_mode(ui->netwowork_information_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->netwowork_information_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_label_4_main_main_default
	static lv_style_t style_netwowork_information_label_4_main_main_default;
	if (style_netwowork_information_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_label_4_main_main_default);
	else
		lv_style_init(&style_netwowork_information_label_4_main_main_default);
	lv_style_set_radius(&style_netwowork_information_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_netwowork_information_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_netwowork_information_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_netwowork_information_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_netwowork_information_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_netwowork_information_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_netwowork_information_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_label_4_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_label_4, &style_netwowork_information_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes netwowork_information_label_8
	ui->netwowork_information_label_8 = lv_label_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_label_8, 252, 80);
	lv_obj_set_size(ui->netwowork_information_label_8, 200, 24);
	lv_label_set_text(ui->netwowork_information_label_8, "");
	lv_label_set_long_mode(ui->netwowork_information_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->netwowork_information_label_8, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_label_8_main_main_default
	static lv_style_t style_netwowork_information_label_8_main_main_default;
	if (style_netwowork_information_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_label_8_main_main_default);
	else
		lv_style_init(&style_netwowork_information_label_8_main_main_default);
	lv_style_set_radius(&style_netwowork_information_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_netwowork_information_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_netwowork_information_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_netwowork_information_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_netwowork_information_label_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_netwowork_information_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_netwowork_information_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_label_8_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_label_8, &style_netwowork_information_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes netwowork_information_label_9
	ui->netwowork_information_label_9 = lv_label_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_label_9, 252, 130);
	lv_obj_set_size(ui->netwowork_information_label_9, 200, 24);
	lv_label_set_text(ui->netwowork_information_label_9, "");
	lv_label_set_long_mode(ui->netwowork_information_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->netwowork_information_label_9, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_label_9_main_main_default
	static lv_style_t style_netwowork_information_label_9_main_main_default;
	if (style_netwowork_information_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_label_9_main_main_default);
	else
		lv_style_init(&style_netwowork_information_label_9_main_main_default);
	lv_style_set_radius(&style_netwowork_information_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_label_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_netwowork_information_label_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_netwowork_information_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_netwowork_information_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_netwowork_information_label_9_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_netwowork_information_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_netwowork_information_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_label_9_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_label_9, &style_netwowork_information_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes netwowork_information_label_10
	ui->netwowork_information_label_10 = lv_label_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_label_10, 252, 177);
	lv_obj_set_size(ui->netwowork_information_label_10, 200, 24);
	lv_label_set_text(ui->netwowork_information_label_10, "");
	lv_label_set_long_mode(ui->netwowork_information_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->netwowork_information_label_10, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_label_10_main_main_default
	static lv_style_t style_netwowork_information_label_10_main_main_default;
	if (style_netwowork_information_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_label_10_main_main_default);
	else
		lv_style_init(&style_netwowork_information_label_10_main_main_default);
	lv_style_set_radius(&style_netwowork_information_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_label_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_netwowork_information_label_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_netwowork_information_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_netwowork_information_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_netwowork_information_label_10_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_netwowork_information_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_netwowork_information_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_label_10_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_label_10, &style_netwowork_information_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes netwowork_information_label_11
	ui->netwowork_information_label_11 = lv_label_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_label_11, 252, 224);
	lv_obj_set_size(ui->netwowork_information_label_11, 200, 24);
	lv_label_set_text(ui->netwowork_information_label_11, "");
	lv_label_set_long_mode(ui->netwowork_information_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->netwowork_information_label_11, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_label_11_main_main_default
	static lv_style_t style_netwowork_information_label_11_main_main_default;
	if (style_netwowork_information_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_label_11_main_main_default);
	else
		lv_style_init(&style_netwowork_information_label_11_main_main_default);
	lv_style_set_radius(&style_netwowork_information_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_label_11_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_netwowork_information_label_11_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_netwowork_information_label_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_netwowork_information_label_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_netwowork_information_label_11_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_netwowork_information_label_11_main_main_default, 0);
	lv_style_set_pad_left(&style_netwowork_information_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_label_11_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_label_11, &style_netwowork_information_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes netwowork_information_label_5
	ui->netwowork_information_label_5 = lv_label_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_label_5, 30, 130);
	lv_obj_set_size(ui->netwowork_information_label_5, 196, 24);
	lv_label_set_text(ui->netwowork_information_label_5, "网关:");
	lv_label_set_long_mode(ui->netwowork_information_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->netwowork_information_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_label_5_main_main_default
	static lv_style_t style_netwowork_information_label_5_main_main_default;
	if (style_netwowork_information_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_label_5_main_main_default);
	else
		lv_style_init(&style_netwowork_information_label_5_main_main_default);
	lv_style_set_radius(&style_netwowork_information_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_netwowork_information_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_netwowork_information_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_netwowork_information_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_netwowork_information_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_netwowork_information_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_netwowork_information_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_label_5_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_label_5, &style_netwowork_information_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes netwowork_information_label_6
	ui->netwowork_information_label_6 = lv_label_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_label_6, 30, 177);
	lv_obj_set_size(ui->netwowork_information_label_6, 195, 24);
	lv_label_set_text(ui->netwowork_information_label_6, "子网掩码:");
	lv_label_set_long_mode(ui->netwowork_information_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->netwowork_information_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_label_6_main_main_default
	static lv_style_t style_netwowork_information_label_6_main_main_default;
	if (style_netwowork_information_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_label_6_main_main_default);
	else
		lv_style_init(&style_netwowork_information_label_6_main_main_default);
	lv_style_set_radius(&style_netwowork_information_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_netwowork_information_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_netwowork_information_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_netwowork_information_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_netwowork_information_label_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_netwowork_information_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_netwowork_information_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_label_6_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_label_6, &style_netwowork_information_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes netwowork_information_label_7
	ui->netwowork_information_label_7 = lv_label_create(ui->netwowork_information_cont_1);
	lv_obj_set_pos(ui->netwowork_information_label_7, 30, 224);
	lv_obj_set_size(ui->netwowork_information_label_7, 205, 24);
	lv_label_set_text(ui->netwowork_information_label_7, "DNS服务器:");
	lv_label_set_long_mode(ui->netwowork_information_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->netwowork_information_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_netwowork_information_label_7_main_main_default
	static lv_style_t style_netwowork_information_label_7_main_main_default;
	if (style_netwowork_information_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_netwowork_information_label_7_main_main_default);
	else
		lv_style_init(&style_netwowork_information_label_7_main_main_default);
	lv_style_set_radius(&style_netwowork_information_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_netwowork_information_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_netwowork_information_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_netwowork_information_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_netwowork_information_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_netwowork_information_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_netwowork_information_label_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_netwowork_information_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_netwowork_information_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_netwowork_information_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_netwowork_information_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_netwowork_information_label_7_main_main_default, 0);
	lv_obj_add_style(ui->netwowork_information_label_7, &style_netwowork_information_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_netwowork_information(ui);
}
