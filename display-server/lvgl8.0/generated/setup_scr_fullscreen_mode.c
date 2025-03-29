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


void setup_scr_fullscreen_mode(lv_ui *ui){

	//Write codes fullscreen_mode_cont_1
	ui->fullscreen_mode_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->fullscreen_mode_cont_1, 0, 0);
	lv_obj_set_size(ui->fullscreen_mode_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_fullscreen_mode_cont_1_main_main_default
	static lv_style_t style_fullscreen_mode_cont_1_main_main_default;
	if (style_fullscreen_mode_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_fullscreen_mode_cont_1_main_main_default);
	else
		lv_style_init(&style_fullscreen_mode_cont_1_main_main_default);
	lv_style_set_radius(&style_fullscreen_mode_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_fullscreen_mode_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_fullscreen_mode_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_fullscreen_mode_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_fullscreen_mode_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_fullscreen_mode_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_fullscreen_mode_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_fullscreen_mode_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_fullscreen_mode_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_fullscreen_mode_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_fullscreen_mode_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_fullscreen_mode_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->fullscreen_mode_cont_1, &style_fullscreen_mode_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes fullscreen_mode_img_1
	ui->fullscreen_mode_img_1 = lv_img_create(ui->fullscreen_mode_cont_1);
	lv_obj_set_pos(ui->fullscreen_mode_img_1, 90, 220);
	lv_obj_set_size(ui->fullscreen_mode_img_1, 300, 300);

	//Write style state: LV_STATE_DEFAULT for style_fullscreen_mode_img_1_main_main_default
	static lv_style_t style_fullscreen_mode_img_1_main_main_default;
	if (style_fullscreen_mode_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_fullscreen_mode_img_1_main_main_default);
	else
		lv_style_init(&style_fullscreen_mode_img_1_main_main_default);
	lv_style_set_img_recolor(&style_fullscreen_mode_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_fullscreen_mode_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_fullscreen_mode_img_1_main_main_default, 255);
	lv_obj_add_style(ui->fullscreen_mode_img_1, &style_fullscreen_mode_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes print_printing_img_mask
	ui->fullscreen_mode_img_mask = lv_img_create(ui->fullscreen_mode_cont_1);
	lv_obj_set_pos(ui->fullscreen_mode_img_mask, 90, 220);
	lv_obj_set_size(ui->fullscreen_mode_img_mask, 300, 300);

	//Write style state: LV_STATE_DEFAULT for style_fullscreen_mode_img_mask_main_main_default
	static lv_style_t style_fullscreen_mode_img_mask_main_main_default;
	if (style_fullscreen_mode_img_mask_main_main_default.prop_cnt > 1)
	lv_style_reset(&style_fullscreen_mode_img_mask_main_main_default);
	else
		lv_style_init(&style_fullscreen_mode_img_mask_main_main_default);
	lv_style_set_img_recolor(&style_fullscreen_mode_img_mask_main_main_default, lv_color_make(0, 0, 0));
	lv_style_set_img_recolor_opa(&style_fullscreen_mode_img_mask_main_main_default, 255);
	lv_style_set_img_opa(&style_fullscreen_mode_img_mask_main_main_default, 255);
	lv_obj_add_style(ui->fullscreen_mode_img_mask, &style_fullscreen_mode_img_mask_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->fullscreen_mode_img_mask, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_pivot(ui->fullscreen_mode_img_mask, 0,0);
	lv_img_set_angle(ui->fullscreen_mode_img_mask, 0);

	//Write codes fullscreen_mode_label_1
	ui->fullscreen_mode_label_1 = lv_label_create(ui->fullscreen_mode_cont_1);
	lv_obj_set_pos(ui->fullscreen_mode_label_1, 100, 600);
	lv_obj_set_size(ui->fullscreen_mode_label_1, 280, 32);
	lv_label_set_text(ui->fullscreen_mode_label_1, "30%");
	lv_label_set_long_mode(ui->fullscreen_mode_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->fullscreen_mode_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_fullscreen_mode_label_1_main_main_default
	static lv_style_t style_fullscreen_mode_label_1_main_main_default;
	if (style_fullscreen_mode_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_fullscreen_mode_label_1_main_main_default);
	else
		lv_style_init(&style_fullscreen_mode_label_1_main_main_default);
	lv_style_set_radius(&style_fullscreen_mode_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_fullscreen_mode_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_fullscreen_mode_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_fullscreen_mode_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_fullscreen_mode_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_fullscreen_mode_label_1_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_fullscreen_mode_label_1_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_fullscreen_mode_label_1_main_main_default, 0);
	lv_style_set_pad_left(&style_fullscreen_mode_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_fullscreen_mode_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_fullscreen_mode_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_fullscreen_mode_label_1_main_main_default, 0);
	lv_obj_add_style(ui->fullscreen_mode_label_1, &style_fullscreen_mode_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Init events for screen
	events_init_fullscreen_mode(ui);
}
