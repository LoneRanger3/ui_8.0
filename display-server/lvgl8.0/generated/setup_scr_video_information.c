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


void setup_scr_video_information(lv_ui *ui){

	//Write codes video_information_cont_1
	ui->video_information_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->video_information_cont_1, 0, 0);
	lv_obj_set_size(ui->video_information_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_video_information_cont_1_main_main_default
	static lv_style_t style_video_information_cont_1_main_main_default;
	if (style_video_information_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_cont_1_main_main_default);
	else
		lv_style_init(&style_video_information_cont_1_main_main_default);
	lv_style_set_radius(&style_video_information_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_video_information_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_video_information_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_video_information_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_video_information_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_video_information_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_video_information_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->video_information_cont_1, &style_video_information_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_3
	ui->video_information_label_3 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_3, 10, 63);
	lv_obj_set_size(ui->video_information_label_3, 460, 727);
	lv_label_set_text(ui->video_information_label_3, "");
	lv_label_set_long_mode(ui->video_information_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_3_main_main_default
	static lv_style_t style_video_information_label_3_main_main_default;
	if (style_video_information_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_3_main_main_default);
	else
		lv_style_init(&style_video_information_label_3_main_main_default);
	lv_style_set_radius(&style_video_information_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_video_information_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_video_information_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_video_information_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_video_information_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_video_information_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_3_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_3, &style_video_information_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_btn_2
	ui->video_information_btn_2 = lv_btn_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_btn_2, 193, 710);
	lv_obj_set_size(ui->video_information_btn_2, 116, 60);

	//Write style state: LV_STATE_DEFAULT for style_video_information_btn_2_main_main_default
	static lv_style_t style_video_information_btn_2_main_main_default;
	if (style_video_information_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_btn_2_main_main_default);
	else
		lv_style_init(&style_video_information_btn_2_main_main_default);
	lv_style_set_radius(&style_video_information_btn_2_main_main_default, 6);
	lv_style_set_bg_color(&style_video_information_btn_2_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_video_information_btn_2_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_video_information_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_video_information_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_video_information_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_video_information_btn_2_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_video_information_btn_2_main_main_default, 1);
	lv_style_set_border_opa(&style_video_information_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->video_information_btn_2, &style_video_information_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->video_information_btn_2_label = lv_label_create(ui->video_information_btn_2);
	lv_label_set_text(ui->video_information_btn_2_label, "上传云");
	lv_obj_set_style_text_color(ui->video_information_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->video_information_btn_2_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->video_information_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->video_information_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes video_information_btn_3
	ui->video_information_btn_3 = lv_btn_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_btn_3, 334, 710);
	lv_obj_set_size(ui->video_information_btn_3, 116, 60);

	//Write style state: LV_STATE_DEFAULT for style_video_information_btn_3_main_main_default
	static lv_style_t style_video_information_btn_3_main_main_default;
	if (style_video_information_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_btn_3_main_main_default);
	else
		lv_style_init(&style_video_information_btn_3_main_main_default);
	lv_style_set_radius(&style_video_information_btn_3_main_main_default, 6);
	lv_style_set_bg_color(&style_video_information_btn_3_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_video_information_btn_3_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_video_information_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_btn_3_main_main_default, 255);
	lv_style_set_shadow_color(&style_video_information_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_video_information_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_video_information_btn_3_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_video_information_btn_3_main_main_default, 1);
	lv_style_set_border_opa(&style_video_information_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->video_information_btn_3, &style_video_information_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->video_information_btn_3_label = lv_label_create(ui->video_information_btn_3);
	lv_label_set_text(ui->video_information_btn_3_label, "导出");
	lv_obj_set_style_text_color(ui->video_information_btn_3_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->video_information_btn_3_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->video_information_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->video_information_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes video_information_img_2
	ui->video_information_img_2 = lv_img_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_img_2, 30, 83);
	lv_obj_set_size(ui->video_information_img_2, 420, 315);

	//Write style state: LV_STATE_DEFAULT for style_video_information_img_2_main_main_default
	static lv_style_t style_video_information_img_2_main_main_default;
	if (style_video_information_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_img_2_main_main_default);
	else
		lv_style_init(&style_video_information_img_2_main_main_default);
	lv_style_set_img_recolor(&style_video_information_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_information_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_video_information_img_2_main_main_default, 255);
	lv_obj_add_style(ui->video_information_img_2, &style_video_information_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_1
	ui->video_information_label_1 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_1, 0, 0);
	lv_obj_set_size(ui->video_information_label_1, 480, 53);
	lv_label_set_text(ui->video_information_label_1, "");
	lv_label_set_long_mode(ui->video_information_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_1_main_main_default
	static lv_style_t style_video_information_label_1_main_main_default;
	if (style_video_information_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_1_main_main_default);
	else
		lv_style_init(&style_video_information_label_1_main_main_default);
	lv_style_set_radius(&style_video_information_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_video_information_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_video_information_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_video_information_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_1_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_1, &style_video_information_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_img_1
	ui->video_information_img_1 = lv_img_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_img_1, 21, 17);
	lv_obj_set_size(ui->video_information_img_1, 36, 24);

	//Write style state: LV_STATE_DEFAULT for style_video_information_img_1_main_main_default
	static lv_style_t style_video_information_img_1_main_main_default;
	if (style_video_information_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_img_1_main_main_default);
	else
		lv_style_init(&style_video_information_img_1_main_main_default);
	lv_style_set_img_recolor(&style_video_information_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_information_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_video_information_img_1_main_main_default, 255);
	lv_obj_add_style(ui->video_information_img_1, &style_video_information_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->video_information_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->video_information_img_1,&_back_36x24);
	lv_img_set_pivot(ui->video_information_img_1, 0,0);
	lv_img_set_angle(ui->video_information_img_1, 0);

	//Write codes video_information_btn_1
	ui->video_information_btn_1 = lv_btn_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_btn_1, 0, 0);
	lv_obj_set_size(ui->video_information_btn_1, 85, 50);

	//Write style state: LV_STATE_DEFAULT for style_video_information_btn_1_main_main_default
	static lv_style_t style_video_information_btn_1_main_main_default;
	if (style_video_information_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_btn_1_main_main_default);
	else
		lv_style_init(&style_video_information_btn_1_main_main_default);
	lv_style_set_radius(&style_video_information_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_video_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_video_information_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_video_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_video_information_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_video_information_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_video_information_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_video_information_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->video_information_btn_1, &style_video_information_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->video_information_btn_1_label = lv_label_create(ui->video_information_btn_1);
	lv_label_set_text(ui->video_information_btn_1_label, "");
	lv_obj_set_style_text_color(ui->video_information_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->video_information_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->video_information_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes video_information_label_2
	ui->video_information_label_2 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_2, 90, 11);
	lv_obj_set_size(ui->video_information_label_2, 300, 32);
	lv_label_set_text(ui->video_information_label_2, "视频详情");
	lv_label_set_long_mode(ui->video_information_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_2_main_main_default
	static lv_style_t style_video_information_label_2_main_main_default;
	if (style_video_information_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_2_main_main_default);
	else
		lv_style_init(&style_video_information_label_2_main_main_default);
	lv_style_set_radius(&style_video_information_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_2_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_video_information_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_video_information_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_2_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_2, &style_video_information_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_4
	ui->video_information_label_4 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_4, 30, 420);
	lv_obj_set_size(ui->video_information_label_4, 205, 24);
	lv_label_set_text(ui->video_information_label_4, "文件名称:");
	lv_label_set_long_mode(ui->video_information_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_4_main_main_default
	static lv_style_t style_video_information_label_4_main_main_default;
	if (style_video_information_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_4_main_main_default);
	else
		lv_style_init(&style_video_information_label_4_main_main_default);
	lv_style_set_radius(&style_video_information_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_4_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_4, &style_video_information_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_10
	ui->video_information_label_10 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_10, 260, 420);
	lv_obj_set_size(ui->video_information_label_10, 200, 24);
	lv_label_set_text(ui->video_information_label_10, "Pawn.MP4");
	lv_label_set_long_mode(ui->video_information_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_10, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_10_main_main_default
	static lv_style_t style_video_information_label_10_main_main_default;
	if (style_video_information_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_10_main_main_default);
	else
		lv_style_init(&style_video_information_label_10_main_main_default);
	lv_style_set_radius(&style_video_information_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_10_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_10_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_10, &style_video_information_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_11
	ui->video_information_label_11 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_11, 260, 457);
	lv_obj_set_size(ui->video_information_label_11, 200, 24);
	lv_label_set_text(ui->video_information_label_11, "2022/01/23 12:12");
	lv_label_set_long_mode(ui->video_information_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_11, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_11_main_main_default
	static lv_style_t style_video_information_label_11_main_main_default;
	if (style_video_information_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_11_main_main_default);
	else
		lv_style_init(&style_video_information_label_11_main_main_default);
	lv_style_set_radius(&style_video_information_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_11_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_11_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_11_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_11_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_11_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_11, &style_video_information_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_12
	ui->video_information_label_12 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_12, 260, 494);
	lv_obj_set_size(ui->video_information_label_12, 200, 24);
	lv_label_set_text(ui->video_information_label_12, "03h23m");
	lv_label_set_long_mode(ui->video_information_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_12, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_12_main_main_default
	static lv_style_t style_video_information_label_12_main_main_default;
	if (style_video_information_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_12_main_main_default);
	else
		lv_style_init(&style_video_information_label_12_main_main_default);
	lv_style_set_radius(&style_video_information_label_12_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_12_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_12_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_12_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_12_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_12_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_12_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_12, &style_video_information_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_13
	ui->video_information_label_13 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_13, 260, 548);
	lv_obj_set_size(ui->video_information_label_13, 200, 24);
	lv_label_set_text(ui->video_information_label_13, "打印机起始点");
	lv_label_set_long_mode(ui->video_information_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_13, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_13_main_main_default
	static lv_style_t style_video_information_label_13_main_main_default;
	if (style_video_information_label_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_13_main_main_default);
	else
		lv_style_init(&style_video_information_label_13_main_main_default);
	lv_style_set_radius(&style_video_information_label_13_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_13_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_13_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_13_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_13_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_13_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_13_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_13_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_13_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_13_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_13_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_13, &style_video_information_label_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_14
	ui->video_information_label_14 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_14, 260, 586);
	lv_obj_set_size(ui->video_information_label_14, 200, 24);
	lv_label_set_text(ui->video_information_label_14, "每五层拍摄一次");
	lv_label_set_long_mode(ui->video_information_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_14, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_14_main_main_default
	static lv_style_t style_video_information_label_14_main_main_default;
	if (style_video_information_label_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_14_main_main_default);
	else
		lv_style_init(&style_video_information_label_14_main_main_default);
	lv_style_set_radius(&style_video_information_label_14_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_14_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_14_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_14_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_14_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_14_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_14_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_14_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_14_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_14_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_14_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_14, &style_video_information_label_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_15
	ui->video_information_label_15 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_15, 260, 624);
	lv_obj_set_size(ui->video_information_label_15, 200, 24);
	lv_label_set_text(ui->video_information_label_15, "30帧");
	lv_label_set_long_mode(ui->video_information_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_15, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_15_main_main_default
	static lv_style_t style_video_information_label_15_main_main_default;
	if (style_video_information_label_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_15_main_main_default);
	else
		lv_style_init(&style_video_information_label_15_main_main_default);
	lv_style_set_radius(&style_video_information_label_15_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_15_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_15_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_15_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_15_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_15_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_15_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_15_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_15_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_15_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_15_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_15, &style_video_information_label_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_5
	ui->video_information_label_5 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_5, 30, 457);
	lv_obj_set_size(ui->video_information_label_5, 205, 24);
	lv_label_set_text(ui->video_information_label_5, "打印日期:");
	lv_label_set_long_mode(ui->video_information_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_5_main_main_default
	static lv_style_t style_video_information_label_5_main_main_default;
	if (style_video_information_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_5_main_main_default);
	else
		lv_style_init(&style_video_information_label_5_main_main_default);
	lv_style_set_radius(&style_video_information_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_5_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_5, &style_video_information_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_6
	ui->video_information_label_6 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_6, 30, 494);
	lv_obj_set_size(ui->video_information_label_6, 205, 24);
	lv_label_set_text(ui->video_information_label_6, "视频时长:");
	lv_label_set_long_mode(ui->video_information_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_6_main_main_default
	static lv_style_t style_video_information_label_6_main_main_default;
	if (style_video_information_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_6_main_main_default);
	else
		lv_style_init(&style_video_information_label_6_main_main_default);
	lv_style_set_radius(&style_video_information_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_6_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_6, &style_video_information_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_7
	ui->video_information_label_7 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_7, 30, 548);
	lv_obj_set_size(ui->video_information_label_7, 205, 24);
	lv_label_set_text(ui->video_information_label_7, "拍摄位置:");
	lv_label_set_long_mode(ui->video_information_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_7_main_main_default
	static lv_style_t style_video_information_label_7_main_main_default;
	if (style_video_information_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_7_main_main_default);
	else
		lv_style_init(&style_video_information_label_7_main_main_default);
	lv_style_set_radius(&style_video_information_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_7_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_7, &style_video_information_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_8
	ui->video_information_label_8 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_8, 30, 586);
	lv_obj_set_size(ui->video_information_label_8, 205, 24);
	lv_label_set_text(ui->video_information_label_8, "拍摄频率:");
	lv_label_set_long_mode(ui->video_information_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_8_main_main_default
	static lv_style_t style_video_information_label_8_main_main_default;
	if (style_video_information_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_8_main_main_default);
	else
		lv_style_init(&style_video_information_label_8_main_main_default);
	lv_style_set_radius(&style_video_information_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_8_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_8, &style_video_information_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_information_label_9
	ui->video_information_label_9 = lv_label_create(ui->video_information_cont_1);
	lv_obj_set_pos(ui->video_information_label_9, 30, 624);
	lv_obj_set_size(ui->video_information_label_9, 205, 24);
	lv_label_set_text(ui->video_information_label_9, "渲染方式:");
	lv_label_set_long_mode(ui->video_information_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_information_label_9, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_information_label_9_main_main_default
	static lv_style_t style_video_information_label_9_main_main_default;
	if (style_video_information_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_information_label_9_main_main_default);
	else
		lv_style_init(&style_video_information_label_9_main_main_default);
	lv_style_set_radius(&style_video_information_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_video_information_label_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_information_label_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_information_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_information_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_video_information_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_information_label_9_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_information_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_video_information_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_video_information_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_video_information_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_information_label_9_main_main_default, 0);
	lv_obj_add_style(ui->video_information_label_9, &style_video_information_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_video_information(ui);
}
