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


void setup_scr_video_list(lv_ui *ui){

	//Write codes video_list_cont_1
	ui->video_list_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->video_list_cont_1, 0, 0);
	lv_obj_set_size(ui->video_list_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_video_list_cont_1_main_main_default
	static lv_style_t style_video_list_cont_1_main_main_default;
	if (style_video_list_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_cont_1_main_main_default);
	else
		lv_style_init(&style_video_list_cont_1_main_main_default);
	lv_style_set_radius(&style_video_list_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&style_video_list_cont_1_main_main_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&style_video_list_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_video_list_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_video_list_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_video_list_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_video_list_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->video_list_cont_1, &style_video_list_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_3
	ui->video_list_label_3 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_3, 10, 63);
	lv_obj_set_size(ui->video_list_label_3, 460, 727);
	lv_label_set_text(ui->video_list_label_3, "");
	lv_label_set_long_mode(ui->video_list_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_3, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_3_main_main_default
	static lv_style_t style_video_list_label_3_main_main_default;
	if (style_video_list_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_3_main_main_default);
	else
		lv_style_init(&style_video_list_label_3_main_main_default);
	lv_style_set_radius(&style_video_list_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_color(&style_video_list_label_3_main_main_default, lv_color_make(0x2d, 0x2e, 0x31));
	lv_style_set_bg_grad_dir(&style_video_list_label_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_3_main_main_default, 255);
	lv_style_set_text_color(&style_video_list_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_video_list_label_3_main_main_default, 2);
	lv_style_set_pad_left(&style_video_list_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_3_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_3, &style_video_list_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_btn_2
	ui->video_list_btn_2 = lv_btn_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_btn_2, 418, 645);
	lv_obj_set_size(ui->video_list_btn_2, 60, 60);

	//Write style state: LV_STATE_DEFAULT for style_video_list_btn_2_main_main_default
	static lv_style_t style_video_list_btn_2_main_main_default;
	if (style_video_list_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_btn_2_main_main_default);
	else
		lv_style_init(&style_video_list_btn_2_main_main_default);
	lv_style_set_radius(&style_video_list_btn_2_main_main_default, 30);
	lv_style_set_bg_color(&style_video_list_btn_2_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_video_list_btn_2_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_video_list_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_video_list_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_video_list_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_video_list_btn_2_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_video_list_btn_2_main_main_default, 1);
	lv_style_set_border_opa(&style_video_list_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->video_list_btn_2, &style_video_list_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->video_list_btn_2_label = lv_label_create(ui->video_list_btn_2);
	lv_label_set_text(ui->video_list_btn_2_label, "");
	lv_obj_set_style_text_color(ui->video_list_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->video_list_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->video_list_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes video_list_btn_3
	ui->video_list_btn_3 = lv_btn_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_btn_3, 418, 717);
	lv_obj_set_size(ui->video_list_btn_3, 60, 60);

	//Write style state: LV_STATE_DEFAULT for style_video_list_btn_3_main_main_default
	static lv_style_t style_video_list_btn_3_main_main_default;
	if (style_video_list_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_btn_3_main_main_default);
	else
		lv_style_init(&style_video_list_btn_3_main_main_default);
	lv_style_set_radius(&style_video_list_btn_3_main_main_default, 30);
	lv_style_set_bg_color(&style_video_list_btn_3_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_color(&style_video_list_btn_3_main_main_default, lv_color_make(0x28, 0x29, 0x2d));
	lv_style_set_bg_grad_dir(&style_video_list_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_btn_3_main_main_default, 255);
	lv_style_set_shadow_color(&style_video_list_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_video_list_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_video_list_btn_3_main_main_default, lv_color_make(0x4a, 0x4e, 0x57));
	lv_style_set_border_width(&style_video_list_btn_3_main_main_default, 1);
	lv_style_set_border_opa(&style_video_list_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->video_list_btn_3, &style_video_list_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->video_list_btn_3_label = lv_label_create(ui->video_list_btn_3);
	lv_label_set_text(ui->video_list_btn_3_label, "");
	lv_obj_set_style_text_color(ui->video_list_btn_3_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->video_list_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->video_list_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes video_list_img_2
	ui->video_list_img_2 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_2, 23, 80);
	lv_obj_set_size(ui->video_list_img_2, 96, 96);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_2_main_main_default
	static lv_style_t style_video_list_img_2_main_main_default;
	if (style_video_list_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_2_main_main_default);
	else
		lv_style_init(&style_video_list_img_2_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_2_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_2, &style_video_list_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_img_3
	ui->video_list_img_3 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_3, 28, 196);
	lv_obj_set_size(ui->video_list_img_3, 96, 96);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_3_main_main_default
	static lv_style_t style_video_list_img_3_main_main_default;
	if (style_video_list_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_3_main_main_default);
	else
		lv_style_init(&style_video_list_img_3_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_3_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_3, &style_video_list_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_img_4
	ui->video_list_img_4 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_4, 28, 312);
	lv_obj_set_size(ui->video_list_img_4, 96, 96);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_4_main_main_default
	static lv_style_t style_video_list_img_4_main_main_default;
	if (style_video_list_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_4_main_main_default);
	else
		lv_style_init(&style_video_list_img_4_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_4_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_4, &style_video_list_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_img_5
	ui->video_list_img_5 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_5, 28, 428);
	lv_obj_set_size(ui->video_list_img_5, 96, 96);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_5_main_main_default
	static lv_style_t style_video_list_img_5_main_main_default;
	if (style_video_list_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_5_main_main_default);
	else
		lv_style_init(&style_video_list_img_5_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_5_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_5, &style_video_list_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_img_6
	ui->video_list_img_6 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_6, 28, 544);
	lv_obj_set_size(ui->video_list_img_6, 96, 96);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_6_main_main_default
	static lv_style_t style_video_list_img_6_main_main_default;
	if (style_video_list_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_6_main_main_default);
	else
		lv_style_init(&style_video_list_img_6_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_6_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_6, &style_video_list_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_img_7
	ui->video_list_img_7 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_7, 436, 668);
	lv_obj_set_size(ui->video_list_img_7, 24, 14);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_7_main_main_default
	static lv_style_t style_video_list_img_7_main_main_default;
	if (style_video_list_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_7_main_main_default);
	else
		lv_style_init(&style_video_list_img_7_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_7_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_7, &style_video_list_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->video_list_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->video_list_img_7,&_Vector_2_24x14);
	lv_img_set_pivot(ui->video_list_img_7, 0,0);
	lv_img_set_angle(ui->video_list_img_7, 0);

	//Write codes video_list_img_9
	ui->video_list_img_9 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_9, 433, 114);
	lv_obj_set_size(ui->video_list_img_9, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_9_main_main_default
	static lv_style_t style_video_list_img_9_main_main_default;
	if (style_video_list_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_9_main_main_default);
	else
		lv_style_init(&style_video_list_img_9_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_9_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_9, &style_video_list_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->video_list_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->video_list_img_9,&_Vector_24_14x28);
	lv_img_set_pivot(ui->video_list_img_9, 0,0);
	lv_img_set_angle(ui->video_list_img_9, 0);

	//Write codes video_list_img_10
	ui->video_list_img_10 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_10, 433, 230);
	lv_obj_set_size(ui->video_list_img_10, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_10_main_main_default
	static lv_style_t style_video_list_img_10_main_main_default;
	if (style_video_list_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_10_main_main_default);
	else
		lv_style_init(&style_video_list_img_10_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_10_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_10, &style_video_list_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->video_list_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->video_list_img_10,&_Vector_24_14x28);
	lv_img_set_pivot(ui->video_list_img_10, 0,0);
	lv_img_set_angle(ui->video_list_img_10, 0);

	//Write codes video_list_img_11
	ui->video_list_img_11 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_11, 433, 346);
	lv_obj_set_size(ui->video_list_img_11, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_11_main_main_default
	static lv_style_t style_video_list_img_11_main_main_default;
	if (style_video_list_img_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_11_main_main_default);
	else
		lv_style_init(&style_video_list_img_11_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_11_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_11_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_11, &style_video_list_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->video_list_img_11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->video_list_img_11,&_Vector_24_14x28);
	lv_img_set_pivot(ui->video_list_img_11, 0,0);
	lv_img_set_angle(ui->video_list_img_11, 0);

	//Write codes video_list_img_12
	ui->video_list_img_12 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_12, 433, 462);
	lv_obj_set_size(ui->video_list_img_12, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_12_main_main_default
	static lv_style_t style_video_list_img_12_main_main_default;
	if (style_video_list_img_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_12_main_main_default);
	else
		lv_style_init(&style_video_list_img_12_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_12_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_12_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_12, &style_video_list_img_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->video_list_img_12, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->video_list_img_12,&_Vector_24_14x28);
	lv_img_set_pivot(ui->video_list_img_12, 0,0);
	lv_img_set_angle(ui->video_list_img_12, 0);

	//Write codes video_list_img_13
	ui->video_list_img_13 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_13, 433, 576);
	lv_obj_set_size(ui->video_list_img_13, 14, 28);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_13_main_main_default
	static lv_style_t style_video_list_img_13_main_main_default;
	if (style_video_list_img_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_13_main_main_default);
	else
		lv_style_init(&style_video_list_img_13_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_13_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_13_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_13, &style_video_list_img_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->video_list_img_13, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->video_list_img_13,&_Vector_24_14x28);
	lv_img_set_pivot(ui->video_list_img_13, 0,0);
	lv_img_set_angle(ui->video_list_img_13, 0);

	//Write codes video_list_img_8
	ui->video_list_img_8 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_8, 436, 740);
	lv_obj_set_size(ui->video_list_img_8, 24, 14);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_8_main_main_default
	static lv_style_t style_video_list_img_8_main_main_default;
	if (style_video_list_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_8_main_main_default);
	else
		lv_style_init(&style_video_list_img_8_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_8_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_8, &style_video_list_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->video_list_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->video_list_img_8,&_Vector_3_24x14);
	lv_img_set_pivot(ui->video_list_img_8, 0,0);
	lv_img_set_angle(ui->video_list_img_8, 0);

	//Write codes video_list_label_1
	ui->video_list_label_1 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_1, 0, 0);
	lv_obj_set_size(ui->video_list_label_1, 480, 53);
	lv_label_set_text(ui->video_list_label_1, "");
	lv_label_set_long_mode(ui->video_list_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_1_main_main_default
	static lv_style_t style_video_list_label_1_main_main_default;
	if (style_video_list_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_1_main_main_default);
	else
		lv_style_init(&style_video_list_label_1_main_main_default);
	lv_style_set_radius(&style_video_list_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_video_list_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_video_list_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_video_list_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_1_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_1, &style_video_list_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_img_1
	ui->video_list_img_1 = lv_img_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_img_1, 20, 16);
	lv_obj_set_size(ui->video_list_img_1, 36, 24);

	//Write style state: LV_STATE_DEFAULT for style_video_list_img_1_main_main_default
	static lv_style_t style_video_list_img_1_main_main_default;
	if (style_video_list_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_img_1_main_main_default);
	else
		lv_style_init(&style_video_list_img_1_main_main_default);
	lv_style_set_img_recolor(&style_video_list_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_video_list_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_video_list_img_1_main_main_default, 255);
	lv_obj_add_style(ui->video_list_img_1, &style_video_list_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->video_list_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->video_list_img_1,&_back_36x24);
	lv_img_set_pivot(ui->video_list_img_1, 0,0);
	lv_img_set_angle(ui->video_list_img_1, 0);

	//Write codes video_list_btn_1
	ui->video_list_btn_1 = lv_btn_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_btn_1, 0, 0);
	lv_obj_set_size(ui->video_list_btn_1, 85, 50);

	//Write style state: LV_STATE_DEFAULT for style_video_list_btn_1_main_main_default
	static lv_style_t style_video_list_btn_1_main_main_default;
	if (style_video_list_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_btn_1_main_main_default);
	else
		lv_style_init(&style_video_list_btn_1_main_main_default);
	lv_style_set_radius(&style_video_list_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_video_list_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_video_list_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_video_list_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_video_list_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_video_list_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_video_list_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_video_list_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->video_list_btn_1, &style_video_list_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->video_list_btn_1_label = lv_label_create(ui->video_list_btn_1);
	lv_label_set_text(ui->video_list_btn_1_label, "");
	lv_obj_set_style_text_color(ui->video_list_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->video_list_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->video_list_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes video_list_label_2
	ui->video_list_label_2 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_2, 90, 11);
	lv_obj_set_size(ui->video_list_label_2, 300, 32);
	lv_label_set_text(ui->video_list_label_2, "视频列表");
	lv_label_set_long_mode(ui->video_list_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_2_main_main_default
	static lv_style_t style_video_list_label_2_main_main_default;
	if (style_video_list_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_2_main_main_default);
	else
		lv_style_init(&style_video_list_label_2_main_main_default);
	lv_style_set_radius(&style_video_list_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_2_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_video_list_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_video_list_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_2_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_2, &style_video_list_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_4
	ui->video_list_label_4 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_4, 131, 80);
	lv_obj_set_size(ui->video_list_label_4, 260, 24);
	lv_label_set_text(ui->video_list_label_4, "Pawn.MP4");
	lv_label_set_long_mode(ui->video_list_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_4, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_4_main_main_default
	static lv_style_t style_video_list_label_4_main_main_default;
	if (style_video_list_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_4_main_main_default);
	else
		lv_style_init(&style_video_list_label_4_main_main_default);
	lv_style_set_radius(&style_video_list_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_4_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_4_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_4, &style_video_list_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_10
	ui->video_list_label_10 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_10, 131, 312);
	lv_obj_set_size(ui->video_list_label_10, 200, 24);
	lv_label_set_text(ui->video_list_label_10, "Pawn.MP4");
	lv_label_set_long_mode(ui->video_list_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_10, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_10_main_main_default
	static lv_style_t style_video_list_label_10_main_main_default;
	if (style_video_list_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_10_main_main_default);
	else
		lv_style_init(&style_video_list_label_10_main_main_default);
	lv_style_set_radius(&style_video_list_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_10_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_10_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_10, &style_video_list_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_11
	ui->video_list_label_11 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_11, 131, 348);
	lv_obj_set_size(ui->video_list_label_11, 253, 24);
	lv_label_set_text(ui->video_list_label_11, "2022/01/23 12:12");
	lv_label_set_long_mode(ui->video_list_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_11, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_11_main_main_default
	static lv_style_t style_video_list_label_11_main_main_default;
	if (style_video_list_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_11_main_main_default);
	else
		lv_style_init(&style_video_list_label_11_main_main_default);
	lv_style_set_radius(&style_video_list_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_11_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_11_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_11_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_11_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_11_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_11, &style_video_list_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_12
	ui->video_list_label_12 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_12, 131, 384);
	lv_obj_set_size(ui->video_list_label_12, 300, 24);
	lv_label_set_text(ui->video_list_label_12, "打印日期:2022/03/07 10:33");
	lv_label_set_long_mode(ui->video_list_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_12, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_12_main_main_default
	static lv_style_t style_video_list_label_12_main_main_default;
	if (style_video_list_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_12_main_main_default);
	else
		lv_style_init(&style_video_list_label_12_main_main_default);
	lv_style_set_radius(&style_video_list_label_12_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_12_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_12_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_12_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_12_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_12_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_12_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_12_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_12, &style_video_list_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_13
	ui->video_list_label_13 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_13, 131, 428);
	lv_obj_set_size(ui->video_list_label_13, 200, 24);
	lv_label_set_text(ui->video_list_label_13, "测试文件.gcode");
	lv_label_set_long_mode(ui->video_list_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_13, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_13_main_main_default
	static lv_style_t style_video_list_label_13_main_main_default;
	if (style_video_list_label_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_13_main_main_default);
	else
		lv_style_init(&style_video_list_label_13_main_main_default);
	lv_style_set_radius(&style_video_list_label_13_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_13_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_13_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_13_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_13_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_13_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_13_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_13_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_13_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_13_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_13_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_13, &style_video_list_label_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_14
	ui->video_list_label_14 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_14, 131, 464);
	lv_obj_set_size(ui->video_list_label_14, 261, 24);
	lv_label_set_text(ui->video_list_label_14, "2022/01/23 12:12");
	lv_label_set_long_mode(ui->video_list_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_14, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_14_main_main_default
	static lv_style_t style_video_list_label_14_main_main_default;
	if (style_video_list_label_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_14_main_main_default);
	else
		lv_style_init(&style_video_list_label_14_main_main_default);
	lv_style_set_radius(&style_video_list_label_14_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_14_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_14_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_14_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_14_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_14_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_14_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_14_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_14_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_14_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_14_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_14, &style_video_list_label_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_15
	ui->video_list_label_15 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_15, 131, 496);
	lv_obj_set_size(ui->video_list_label_15, 300, 24);
	lv_label_set_text(ui->video_list_label_15, "打印日期:2022/03/07 10:33");
	lv_label_set_long_mode(ui->video_list_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_15, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_15_main_main_default
	static lv_style_t style_video_list_label_15_main_main_default;
	if (style_video_list_label_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_15_main_main_default);
	else
		lv_style_init(&style_video_list_label_15_main_main_default);
	lv_style_set_radius(&style_video_list_label_15_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_15_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_15_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_15_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_15_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_15_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_15_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_15_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_15_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_15_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_15_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_15, &style_video_list_label_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_18
	ui->video_list_label_18 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_18, 131, 612);
	lv_obj_set_size(ui->video_list_label_18, 300, 24);
	lv_label_set_text(ui->video_list_label_18, "打印日期:2022/03/07 10:33");
	lv_label_set_long_mode(ui->video_list_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_18, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_18_main_main_default
	static lv_style_t style_video_list_label_18_main_main_default;
	if (style_video_list_label_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_18_main_main_default);
	else
		lv_style_init(&style_video_list_label_18_main_main_default);
	lv_style_set_radius(&style_video_list_label_18_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_18_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_18_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_18_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_18_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_18_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_18_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_18_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_18_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_18_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_18_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_18_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_18, &style_video_list_label_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_16
	ui->video_list_label_16 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_16, 131, 544);
	lv_obj_set_size(ui->video_list_label_16, 282, 24);
	lv_label_set_text(ui->video_list_label_16, "测试文件.gcode");
	lv_label_set_long_mode(ui->video_list_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_16, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_16_main_main_default
	static lv_style_t style_video_list_label_16_main_main_default;
	if (style_video_list_label_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_16_main_main_default);
	else
		lv_style_init(&style_video_list_label_16_main_main_default);
	lv_style_set_radius(&style_video_list_label_16_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_16_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_16_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_16_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_16_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_16_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_16_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_16_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_16_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_16_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_16_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_16, &style_video_list_label_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_17
	ui->video_list_label_17 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_17, 131, 576);
	lv_obj_set_size(ui->video_list_label_17, 282, 24);
	lv_label_set_text(ui->video_list_label_17, "2022/01/23 12:12");
	lv_label_set_long_mode(ui->video_list_label_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_17, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_17_main_main_default
	static lv_style_t style_video_list_label_17_main_main_default;
	if (style_video_list_label_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_17_main_main_default);
	else
		lv_style_init(&style_video_list_label_17_main_main_default);
	lv_style_set_radius(&style_video_list_label_17_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_17_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_17_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_17_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_17_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_17_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_17_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_17_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_17_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_17_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_17_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_17_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_17, &style_video_list_label_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_5
	ui->video_list_label_5 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_5, 131, 116);
	lv_obj_set_size(ui->video_list_label_5, 260, 24);
	lv_label_set_text(ui->video_list_label_5, "实际打印时间:19h22m");
	lv_label_set_long_mode(ui->video_list_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_5, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_5_main_main_default
	static lv_style_t style_video_list_label_5_main_main_default;
	if (style_video_list_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_5_main_main_default);
	else
		lv_style_init(&style_video_list_label_5_main_main_default);
	lv_style_set_radius(&style_video_list_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_5_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_5_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_5, &style_video_list_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_6
	ui->video_list_label_6 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_6, 130, 152);
	lv_obj_set_size(ui->video_list_label_6, 300, 24);
	lv_label_set_text(ui->video_list_label_6, "打印日期:2022/03/07 10:33");
	lv_label_set_long_mode(ui->video_list_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_6, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_6_main_main_default
	static lv_style_t style_video_list_label_6_main_main_default;
	if (style_video_list_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_6_main_main_default);
	else
		lv_style_init(&style_video_list_label_6_main_main_default);
	lv_style_set_radius(&style_video_list_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_6_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_6_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_6, &style_video_list_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_7
	ui->video_list_label_7 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_7, 131, 196);
	lv_obj_set_size(ui->video_list_label_7, 205, 24);
	lv_label_set_text(ui->video_list_label_7, "Pawn.MP4");
	lv_label_set_long_mode(ui->video_list_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_7, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_7_main_main_default
	static lv_style_t style_video_list_label_7_main_main_default;
	if (style_video_list_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_7_main_main_default);
	else
		lv_style_init(&style_video_list_label_7_main_main_default);
	lv_style_set_radius(&style_video_list_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_7_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_7, &style_video_list_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_8
	ui->video_list_label_8 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_8, 131, 232);
	lv_obj_set_size(ui->video_list_label_8, 260, 24);
	lv_label_set_text(ui->video_list_label_8, "实际打印时间:19h22m");
	lv_label_set_long_mode(ui->video_list_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_8_main_main_default
	static lv_style_t style_video_list_label_8_main_main_default;
	if (style_video_list_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_8_main_main_default);
	else
		lv_style_init(&style_video_list_label_8_main_main_default);
	lv_style_set_radius(&style_video_list_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_8_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_8, &style_video_list_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes video_list_label_9
	ui->video_list_label_9 = lv_label_create(ui->video_list_cont_1);
	lv_obj_set_pos(ui->video_list_label_9, 131, 268);
	lv_obj_set_size(ui->video_list_label_9, 300, 24);
	lv_label_set_text(ui->video_list_label_9, "打印日期:2022/03/07 10:33");
	lv_label_set_long_mode(ui->video_list_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->video_list_label_9, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_video_list_label_9_main_main_default
	static lv_style_t style_video_list_label_9_main_main_default;
	if (style_video_list_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_video_list_label_9_main_main_default);
	else
		lv_style_init(&style_video_list_label_9_main_main_default);
	lv_style_set_radius(&style_video_list_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_video_list_label_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_video_list_label_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_video_list_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_video_list_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_video_list_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_video_list_label_9_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_video_list_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_video_list_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_video_list_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_video_list_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_video_list_label_9_main_main_default, 0);
	lv_obj_add_style(ui->video_list_label_9, &style_video_list_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_video_list(ui);
}
