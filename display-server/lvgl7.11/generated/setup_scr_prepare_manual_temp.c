/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "clanguage.h"

void setup_scr_prepare_manual_temp(lv_ui *ui){

	//Write codes prepare_manual_temp
//	ui->prepare_manual_temp = lv_obj_create(NULL, NULL);

	if(ui->prepare_manual_temp_cont_prepare_manual_temp != NULL)
    {
        return;
    }
	//Write codes prepare_manual_temp_cont_prepare_manual_temp
	ui->prepare_manual_temp_cont_prepare_manual_temp = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for prepare_manual_temp_cont_prepare_manual_temp
	static lv_style_t style_prepare_manual_temp_cont_prepare_manual_temp_main;
	lv_style_reset(&style_prepare_manual_temp_cont_prepare_manual_temp_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_cont_prepare_manual_temp_main
	lv_style_set_radius(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_manual_temp_cont_prepare_manual_temp_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_manual_temp_cont_prepare_manual_temp, LV_CONT_PART_MAIN, &style_prepare_manual_temp_cont_prepare_manual_temp_main);
	lv_obj_set_pos(ui->prepare_manual_temp_cont_prepare_manual_temp, 0, 0);
	lv_obj_set_size(ui->prepare_manual_temp_cont_prepare_manual_temp, 480, 674);
	lv_obj_set_click(ui->prepare_manual_temp_cont_prepare_manual_temp, false);

	//Write codes prepare_manual_temp_btn_set_hotend
	ui->prepare_manual_temp_btn_set_hotend = lv_btn_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_manual_temp_btn_set_hotend
	static lv_style_t style_prepare_manual_temp_btn_set_hotend_main;
	lv_style_reset(&style_prepare_manual_temp_btn_set_hotend_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_btn_set_hotend_main
	lv_style_set_radius(&style_prepare_manual_temp_btn_set_hotend_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_prepare_manual_temp_btn_set_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_btn_set_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_btn_set_hotend_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_btn_set_hotend_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_manual_temp_btn_set_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_manual_temp_btn_set_hotend_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_manual_temp_btn_set_hotend_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_manual_temp_btn_set_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_manual_temp_btn_set_hotend_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_manual_temp_btn_set_hotend, LV_BTN_PART_MAIN, &style_prepare_manual_temp_btn_set_hotend_main);
	lv_obj_set_pos(ui->prepare_manual_temp_btn_set_hotend, 14, 130);
	lv_obj_set_size(ui->prepare_manual_temp_btn_set_hotend, 218, 158);
//	ui->prepare_manual_temp_btn_set_hotend_label = lv_label_create(ui->prepare_manual_temp_btn_set_hotend, NULL);
//	lv_label_set_text(ui->prepare_manual_temp_btn_set_hotend_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_manual_temp_btn_set_hotend_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_manual_temp_btn_cold
	ui->prepare_manual_temp_btn_cold = lv_btn_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_manual_temp_btn_cold
	static lv_style_t style_prepare_manual_temp_btn_cold_main;
	lv_style_reset(&style_prepare_manual_temp_btn_cold_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_btn_cold_main
	lv_style_set_radius(&style_prepare_manual_temp_btn_cold_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_prepare_manual_temp_btn_cold_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_btn_cold_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_btn_cold_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_btn_cold_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_manual_temp_btn_cold_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_manual_temp_btn_cold_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_manual_temp_btn_cold_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_manual_temp_btn_cold_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_manual_temp_btn_cold_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_manual_temp_btn_cold, LV_BTN_PART_MAIN, &style_prepare_manual_temp_btn_cold_main);
	lv_obj_set_pos(ui->prepare_manual_temp_btn_cold, 246, 482);
	lv_obj_set_size(ui->prepare_manual_temp_btn_cold, 218, 158);
//	ui->prepare_manual_temp_btn_cold_label = lv_label_create(ui->prepare_manual_temp_btn_cold, NULL);
//	lv_label_set_text(ui->prepare_manual_temp_btn_cold_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_manual_temp_btn_cold_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_manual_temp_btn_fan_control
	ui->prepare_manual_temp_btn_fan_control = lv_btn_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_manual_temp_btn_fan_control
	static lv_style_t style_prepare_manual_temp_btn_fan_control_main;
	lv_style_reset(&style_prepare_manual_temp_btn_fan_control_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_btn_fan_control_main
	lv_style_set_radius(&style_prepare_manual_temp_btn_fan_control_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_prepare_manual_temp_btn_fan_control_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_btn_fan_control_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_btn_fan_control_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_btn_fan_control_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_manual_temp_btn_fan_control_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_manual_temp_btn_fan_control_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_manual_temp_btn_fan_control_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_manual_temp_btn_fan_control_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_manual_temp_btn_fan_control_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_manual_temp_btn_fan_control, LV_BTN_PART_MAIN, &style_prepare_manual_temp_btn_fan_control_main);
	lv_obj_set_pos(ui->prepare_manual_temp_btn_fan_control, 14, 482);
	lv_obj_set_size(ui->prepare_manual_temp_btn_fan_control, 218, 158);
//	ui->prepare_manual_temp_btn_fan_control_label = lv_label_create(ui->prepare_manual_temp_btn_fan_control, NULL);
//	lv_label_set_text(ui->prepare_manual_temp_btn_fan_control_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_manual_temp_btn_fan_control_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_manual_temp_btn_set_bed
	ui->prepare_manual_temp_btn_set_bed = lv_btn_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_manual_temp_btn_set_bed
	static lv_style_t style_prepare_manual_temp_btn_set_bed_main;
	lv_style_reset(&style_prepare_manual_temp_btn_set_bed_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_btn_set_bed_main
	lv_style_set_radius(&style_prepare_manual_temp_btn_set_bed_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_prepare_manual_temp_btn_set_bed_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_btn_set_bed_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_btn_set_bed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_btn_set_bed_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_manual_temp_btn_set_bed_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_manual_temp_btn_set_bed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_manual_temp_btn_set_bed_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_manual_temp_btn_set_bed_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_manual_temp_btn_set_bed_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_manual_temp_btn_set_bed, LV_BTN_PART_MAIN, &style_prepare_manual_temp_btn_set_bed_main);
	lv_obj_set_pos(ui->prepare_manual_temp_btn_set_bed, 246, 130);
	lv_obj_set_size(ui->prepare_manual_temp_btn_set_bed, 218, 158);
//	ui->prepare_manual_temp_btn_set_bed_label = lv_label_create(ui->prepare_manual_temp_btn_set_bed, NULL);
//	lv_label_set_text(ui->prepare_manual_temp_btn_set_bed_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_manual_temp_btn_set_bed_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_manual_temp_btn_preheat_PLA
	ui->prepare_manual_temp_btn_preheat_PLA = lv_btn_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_manual_temp_btn_preheat_PLA
	static lv_style_t style_prepare_manual_temp_btn_preheat_PLA_main;
	lv_style_reset(&style_prepare_manual_temp_btn_preheat_PLA_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_btn_preheat_PLA_main
	lv_style_set_radius(&style_prepare_manual_temp_btn_preheat_PLA_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_prepare_manual_temp_btn_preheat_PLA_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_btn_preheat_PLA_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_btn_preheat_PLA_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_btn_preheat_PLA_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_manual_temp_btn_preheat_PLA_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_manual_temp_btn_preheat_PLA_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_manual_temp_btn_preheat_PLA_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_manual_temp_btn_preheat_PLA_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_manual_temp_btn_preheat_PLA_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_manual_temp_btn_preheat_PLA, LV_BTN_PART_MAIN, &style_prepare_manual_temp_btn_preheat_PLA_main);
	lv_obj_set_pos(ui->prepare_manual_temp_btn_preheat_PLA, 14, 306);
	lv_obj_set_size(ui->prepare_manual_temp_btn_preheat_PLA, 218, 158);
//	ui->prepare_manual_temp_btn_preheat_PLA_label = lv_label_create(ui->prepare_manual_temp_btn_preheat_PLA, NULL);
//	lv_label_set_text(ui->prepare_manual_temp_btn_preheat_PLA_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_manual_temp_btn_preheat_PLA_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_manual_temp_btn_preheat_ABS
	ui->prepare_manual_temp_btn_preheat_ABS = lv_btn_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_manual_temp_btn_preheat_ABS
	static lv_style_t style_prepare_manual_temp_btn_preheat_ABS_main;
	lv_style_reset(&style_prepare_manual_temp_btn_preheat_ABS_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_btn_preheat_ABS_main
	lv_style_set_radius(&style_prepare_manual_temp_btn_preheat_ABS_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_prepare_manual_temp_btn_preheat_ABS_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_btn_preheat_ABS_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_btn_preheat_ABS_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_btn_preheat_ABS_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_manual_temp_btn_preheat_ABS_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_manual_temp_btn_preheat_ABS_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_manual_temp_btn_preheat_ABS_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_manual_temp_btn_preheat_ABS_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_manual_temp_btn_preheat_ABS_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_manual_temp_btn_preheat_ABS, LV_BTN_PART_MAIN, &style_prepare_manual_temp_btn_preheat_ABS_main);
	lv_obj_set_pos(ui->prepare_manual_temp_btn_preheat_ABS, 246, 306);
	lv_obj_set_size(ui->prepare_manual_temp_btn_preheat_ABS, 218, 158);
//	ui->prepare_manual_temp_btn_preheat_ABS_label = lv_label_create(ui->prepare_manual_temp_btn_preheat_ABS, NULL);
//	lv_label_set_text(ui->prepare_manual_temp_btn_preheat_ABS_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_manual_temp_btn_preheat_ABS_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_manual_temp_label_fan_state
	ui->prepare_manual_temp_label_fan_state = lv_label_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);
	lv_label_set_text(ui->prepare_manual_temp_label_fan_state, "OFF");
	lv_label_set_long_mode(ui->prepare_manual_temp_label_fan_state, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_manual_temp_label_fan_state, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_manual_temp_label_fan_state
	static lv_style_t style_prepare_manual_temp_label_fan_state_main;
	lv_style_reset(&style_prepare_manual_temp_label_fan_state_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_label_fan_state_main
	lv_style_set_radius(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_manual_temp_label_fan_state_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_manual_temp_label_fan_state, LV_LABEL_PART_MAIN, &style_prepare_manual_temp_label_fan_state_main);
	lv_obj_set_pos(ui->prepare_manual_temp_label_fan_state, 40, 596);
	lv_obj_set_size(ui->prepare_manual_temp_label_fan_state, 100, 0);

	//Write codes prepare_manual_temp_label_29
	ui->prepare_manual_temp_label_29 = lv_label_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);
	lv_label_set_long_mode(ui->prepare_manual_temp_label_29, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->prepare_manual_temp_label_29, cooling[cur_language]);
//	lv_label_set_long_mode(ui->prepare_manual_temp_label_29, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_manual_temp_label_29, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_manual_temp_label_29
	static lv_style_t style_prepare_manual_temp_label_29_main;
	lv_style_reset(&style_prepare_manual_temp_label_29_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_label_29_main
	lv_style_set_radius(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_manual_temp_label_29_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_manual_temp_label_29, LV_LABEL_PART_MAIN, &style_prepare_manual_temp_label_29_main);
	lv_obj_set_pos(ui->prepare_manual_temp_label_29, 272, 555);
	lv_obj_set_size(ui->prepare_manual_temp_label_29, 150, 42);

	//Write codes prepare_manual_temp_label_28
	ui->prepare_manual_temp_label_28 = lv_label_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);
	lv_label_set_long_mode(ui->prepare_manual_temp_label_28, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->prepare_manual_temp_label_28, fan_control[cur_language]);
//	lv_label_set_long_mode(ui->prepare_manual_temp_label_28, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_manual_temp_label_28, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_manual_temp_label_28
	static lv_style_t style_prepare_manual_temp_label_28_main;
	lv_style_reset(&style_prepare_manual_temp_label_28_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_label_28_main
	lv_style_set_radius(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_manual_temp_label_28_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_manual_temp_label_28, LV_LABEL_PART_MAIN, &style_prepare_manual_temp_label_28_main);
	lv_obj_set_pos(ui->prepare_manual_temp_label_28, 40, 555);
	lv_obj_set_size(ui->prepare_manual_temp_label_28, 150, 42);

	//Write codes prepare_manual_temp_label_27
	ui->prepare_manual_temp_label_27 = lv_label_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);
    lv_label_set_long_mode(ui->prepare_manual_temp_label_27, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->prepare_manual_temp_label_27, preheat_abs[cur_language]);
//	lv_label_set_long_mode(ui->prepare_manual_temp_label_27, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_manual_temp_label_27, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_manual_temp_label_27
	static lv_style_t style_prepare_manual_temp_label_27_main;
	lv_style_reset(&style_prepare_manual_temp_label_27_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_label_27_main
	lv_style_set_radius(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_manual_temp_label_27_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_manual_temp_label_27, LV_LABEL_PART_MAIN, &style_prepare_manual_temp_label_27_main);
	lv_obj_set_pos(ui->prepare_manual_temp_label_27, 272, 379);
	lv_obj_set_size(ui->prepare_manual_temp_label_27, 150, 42);

	//Write codes prepare_manual_temp_label_26
	ui->prepare_manual_temp_label_26 = lv_label_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);
    lv_label_set_long_mode(ui->prepare_manual_temp_label_26, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->prepare_manual_temp_label_26, preheat_pla[cur_language]);
//	lv_label_set_long_mode(ui->prepare_manual_temp_label_26, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_manual_temp_label_26, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_manual_temp_label_26
	static lv_style_t style_prepare_manual_temp_label_26_main;
	lv_style_reset(&style_prepare_manual_temp_label_26_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_label_26_main
	lv_style_set_radius(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_manual_temp_label_26_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_manual_temp_label_26, LV_LABEL_PART_MAIN, &style_prepare_manual_temp_label_26_main);
	lv_obj_set_pos(ui->prepare_manual_temp_label_26, 40, 379);
	lv_obj_set_size(ui->prepare_manual_temp_label_26, 150, 42);

	//Write codes prepare_manual_temp_img_9
	ui->prepare_manual_temp_img_9 = lv_img_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_IMG_PART_MAIN for prepare_manual_temp_img_9
//	static lv_style_t style_prepare_manual_temp_img_9_main;
//	lv_style_reset(&style_prepare_manual_temp_img_9_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_img_9_main
//	lv_style_set_image_recolor(&style_prepare_manual_temp_img_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_prepare_manual_temp_img_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_prepare_manual_temp_img_9_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->prepare_manual_temp_img_9, LV_IMG_PART_MAIN, &style_prepare_manual_temp_img_9_main);
	lv_obj_set_pos(ui->prepare_manual_temp_img_9, 272, 505);
//	lv_obj_set_size(ui->prepare_manual_temp_img_9, 44, 44);
//	lv_obj_set_click(ui->prepare_manual_temp_img_9, true);
	lv_img_set_src(ui->prepare_manual_temp_img_9,&_precold_alpha_44x44);
//	lv_img_set_pivot(ui->prepare_manual_temp_img_9, 0,0);
//	lv_img_set_angle(ui->prepare_manual_temp_img_9, 0);

	//Write codes prepare_manual_temp_img_8
	ui->prepare_manual_temp_img_8 = lv_img_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_IMG_PART_MAIN for prepare_manual_temp_img_8
//	static lv_style_t style_prepare_manual_temp_img_8_main;
//	lv_style_reset(&style_prepare_manual_temp_img_8_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_img_8_main
//	lv_style_set_image_recolor(&style_prepare_manual_temp_img_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_prepare_manual_temp_img_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_prepare_manual_temp_img_8_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->prepare_manual_temp_img_8, LV_IMG_PART_MAIN, &style_prepare_manual_temp_img_8_main);
	lv_obj_set_pos(ui->prepare_manual_temp_img_8, 40, 505);
//	lv_obj_set_size(ui->prepare_manual_temp_img_8, 44, 44);
//	lv_obj_set_click(ui->prepare_manual_temp_img_8, true);
	lv_img_set_src(ui->prepare_manual_temp_img_8,&_fan_alpha_44x44);
//	lv_img_set_pivot(ui->prepare_manual_temp_img_8, 0,0);
//	lv_img_set_angle(ui->prepare_manual_temp_img_8, 0);

	//Write codes prepare_manual_temp_img_7
	ui->prepare_manual_temp_img_7 = lv_img_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_IMG_PART_MAIN for prepare_manual_temp_img_7
//	static lv_style_t style_prepare_manual_temp_img_7_main;
//	lv_style_reset(&style_prepare_manual_temp_img_7_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_img_7_main
//	lv_style_set_image_recolor(&style_prepare_manual_temp_img_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_prepare_manual_temp_img_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_prepare_manual_temp_img_7_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->prepare_manual_temp_img_7, LV_IMG_PART_MAIN, &style_prepare_manual_temp_img_7_main);
	lv_obj_set_pos(ui->prepare_manual_temp_img_7, 272, 329);
//	lv_obj_set_size(ui->prepare_manual_temp_img_7, 44, 44);
//	lv_obj_set_click(ui->prepare_manual_temp_img_7, true);
	lv_img_set_src(ui->prepare_manual_temp_img_7,&_preABS_alpha_44x44);
//	lv_img_set_pivot(ui->prepare_manual_temp_img_7, 0,0);
//	lv_img_set_angle(ui->prepare_manual_temp_img_7, 0);

	//Write codes prepare_manual_temp_img_6
	ui->prepare_manual_temp_img_6 = lv_img_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_IMG_PART_MAIN for prepare_manual_temp_img_6
//	static lv_style_t style_prepare_manual_temp_img_6_main;
//	lv_style_reset(&style_prepare_manual_temp_img_6_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_img_6_main
//	lv_style_set_image_recolor(&style_prepare_manual_temp_img_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_prepare_manual_temp_img_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_prepare_manual_temp_img_6_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->prepare_manual_temp_img_6, LV_IMG_PART_MAIN, &style_prepare_manual_temp_img_6_main);
	lv_obj_set_pos(ui->prepare_manual_temp_img_6, 40, 329);
//	lv_obj_set_size(ui->prepare_manual_temp_img_6, 44, 44);
//	lv_obj_set_click(ui->prepare_manual_temp_img_6, true);
	lv_img_set_src(ui->prepare_manual_temp_img_6,&_prePLA_alpha_44x44);
//	lv_img_set_pivot(ui->prepare_manual_temp_img_6, 0,0);
//	lv_img_set_angle(ui->prepare_manual_temp_img_6, 0);

	//Write codes prepare_manual_temp_label_bed_mtemp
	ui->prepare_manual_temp_label_bed_mtemp = lv_label_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);
	lv_label_set_text(ui->prepare_manual_temp_label_bed_mtemp, "0");
	lv_label_set_long_mode(ui->prepare_manual_temp_label_bed_mtemp, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_manual_temp_label_bed_mtemp, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_manual_temp_label_bed_mtemp
	static lv_style_t style_prepare_manual_temp_label_bed_mtemp_main;
	lv_style_reset(&style_prepare_manual_temp_label_bed_mtemp_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_label_bed_mtemp_main
	lv_style_set_radius(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_manual_temp_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_manual_temp_label_bed_mtemp, LV_LABEL_PART_MAIN, &style_prepare_manual_temp_label_bed_mtemp_main);
	lv_obj_set_pos(ui->prepare_manual_temp_label_bed_mtemp, 272, 244);
	lv_obj_set_size(ui->prepare_manual_temp_label_bed_mtemp, 100, 0);

	//Write codes prepare_manual_temp_label_hot_mtemp
	ui->prepare_manual_temp_label_hot_mtemp = lv_label_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);
	lv_label_set_text(ui->prepare_manual_temp_label_hot_mtemp, "0");
	lv_label_set_long_mode(ui->prepare_manual_temp_label_hot_mtemp, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_manual_temp_label_hot_mtemp, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_manual_temp_label_hot_mtemp
	static lv_style_t style_prepare_manual_temp_label_hot_mtemp_main;
	lv_style_reset(&style_prepare_manual_temp_label_hot_mtemp_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_label_hot_mtemp_main
	lv_style_set_radius(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_manual_temp_label_hot_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_manual_temp_label_hot_mtemp, LV_LABEL_PART_MAIN, &style_prepare_manual_temp_label_hot_mtemp_main);
	lv_obj_set_pos(ui->prepare_manual_temp_label_hot_mtemp, 40, 244);
	lv_obj_set_size(ui->prepare_manual_temp_label_hot_mtemp, 100, 0);

	//Write codes prepare_manual_temp_label_22
	ui->prepare_manual_temp_label_22 = lv_label_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);
	lv_label_set_long_mode(ui->prepare_manual_temp_label_22, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->prepare_manual_temp_label_22, hotend_temp[cur_language]);
//	lv_label_set_long_mode(ui->prepare_manual_temp_label_22, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_manual_temp_label_22, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_manual_temp_label_22
	static lv_style_t style_prepare_manual_temp_label_22_main;
	lv_style_reset(&style_prepare_manual_temp_label_22_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_label_22_main
	lv_style_set_radius(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_manual_temp_label_22_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_manual_temp_label_22, LV_LABEL_PART_MAIN, &style_prepare_manual_temp_label_22_main);
	lv_obj_set_pos(ui->prepare_manual_temp_label_22, 40, 203);
	lv_obj_set_size(ui->prepare_manual_temp_label_22, 150, 42);

	//Write codes prepare_manual_temp_img_4
	ui->prepare_manual_temp_img_4 = lv_img_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_IMG_PART_MAIN for prepare_manual_temp_img_4
//	static lv_style_t style_prepare_manual_temp_img_4_main;
//	lv_style_reset(&style_prepare_manual_temp_img_4_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_img_4_main
//	lv_style_set_image_recolor(&style_prepare_manual_temp_img_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_prepare_manual_temp_img_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_prepare_manual_temp_img_4_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->prepare_manual_temp_img_4, LV_IMG_PART_MAIN, &style_prepare_manual_temp_img_4_main);
	lv_obj_set_pos(ui->prepare_manual_temp_img_4, 40, 153);
//	lv_obj_set_size(ui->prepare_manual_temp_img_4, 44, 44);
//	lv_obj_set_click(ui->prepare_manual_temp_img_4, true);
	lv_img_set_src(ui->prepare_manual_temp_img_4,&_hotend_alpha_44x44);
//	lv_img_set_pivot(ui->prepare_manual_temp_img_4, 0,0);
//	lv_img_set_angle(ui->prepare_manual_temp_img_4, 0);

	//Write codes prepare_manual_temp_label_24
	ui->prepare_manual_temp_label_24 = lv_label_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);
	lv_label_set_long_mode(ui->prepare_manual_temp_label_24, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->prepare_manual_temp_label_24, bed_temp[cur_language]);
//	lv_label_set_long_mode(ui->prepare_manual_temp_label_24, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_manual_temp_label_24, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_manual_temp_label_24
	static lv_style_t style_prepare_manual_temp_label_24_main;
	lv_style_reset(&style_prepare_manual_temp_label_24_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_label_24_main
	lv_style_set_radius(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_manual_temp_label_24_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_manual_temp_label_24, LV_LABEL_PART_MAIN, &style_prepare_manual_temp_label_24_main);
	lv_obj_set_pos(ui->prepare_manual_temp_label_24, 272, 203);
	lv_obj_set_size(ui->prepare_manual_temp_label_24, 150, 42);

	//Write codes prepare_manual_temp_img_5
	ui->prepare_manual_temp_img_5 = lv_img_create(ui->prepare_manual_temp_cont_prepare_manual_temp, NULL);

	//Write style LV_IMG_PART_MAIN for prepare_manual_temp_img_5
//	static lv_style_t style_prepare_manual_temp_img_5_main;
//	lv_style_reset(&style_prepare_manual_temp_img_5_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_prepare_manual_temp_img_5_main
//	lv_style_set_image_recolor(&style_prepare_manual_temp_img_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_prepare_manual_temp_img_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_prepare_manual_temp_img_5_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->prepare_manual_temp_img_5, LV_IMG_PART_MAIN, &style_prepare_manual_temp_img_5_main);
	lv_obj_set_pos(ui->prepare_manual_temp_img_5, 272, 153);
//	lv_obj_set_size(ui->prepare_manual_temp_img_5, 44, 44);
//	lv_obj_set_click(ui->prepare_manual_temp_img_5, true);
	lv_img_set_src(ui->prepare_manual_temp_img_5,&_hotbed_alpha_44x44);
//	lv_img_set_pivot(ui->prepare_manual_temp_img_5, 0,0);
//	lv_img_set_angle(ui->prepare_manual_temp_img_5, 0);
//	lv_cont_set_layout(ui->prepare_manual_temp_cont_prepare_manual_temp, LV_LAYOUT_OFF);
//	lv_cont_set_fit(ui->prepare_manual_temp_cont_prepare_manual_temp, LV_FIT_NONE);

	//Init events for screen
	events_init_prepare_manual_temp(ui);
}
