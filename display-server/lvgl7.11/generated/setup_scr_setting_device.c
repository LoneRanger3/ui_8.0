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

void setup_scr_setting_device(lv_ui *ui){

	//Write codes setting_device
//	ui->setting_device = lv_obj_create(NULL, NULL);

	if(ui->setting_device_cont_seting_device != NULL)
    {
        return;
    }

	//Write codes setting_device_cont_seting_device
	ui->setting_device_cont_seting_device = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for setting_device_cont_seting_device
	static lv_style_t style_setting_device_cont_seting_device_main;
	lv_style_reset(&style_setting_device_cont_seting_device_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_cont_seting_device_main
	lv_style_set_radius(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_setting_device_cont_seting_device_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_cont_seting_device, LV_CONT_PART_MAIN, &style_setting_device_cont_seting_device_main);
	lv_obj_set_pos(ui->setting_device_cont_seting_device, 0, 0);
	lv_obj_set_size(ui->setting_device_cont_seting_device, 480, 674);
	lv_obj_set_click(ui->setting_device_cont_seting_device, false);

	//Write codes setting_device_btn_poweroff
	ui->setting_device_btn_poweroff = lv_btn_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_BTN_PART_MAIN for setting_device_btn_poweroff
	static lv_style_t style_setting_device_btn_poweroff_main;
	lv_style_reset(&style_setting_device_btn_poweroff_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_btn_poweroff_main
	lv_style_set_radius(&style_setting_device_btn_poweroff_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_setting_device_btn_poweroff_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_btn_poweroff_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_btn_poweroff_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_btn_poweroff_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_device_btn_poweroff_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_setting_device_btn_poweroff_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_device_btn_poweroff_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_device_btn_poweroff_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_device_btn_poweroff_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->setting_device_btn_poweroff, LV_BTN_PART_MAIN, &style_setting_device_btn_poweroff_main);
	lv_obj_set_pos(ui->setting_device_btn_poweroff, 246, 482);
	lv_obj_set_size(ui->setting_device_btn_poweroff, 218, 158);
//	ui->setting_device_btn_poweroff_label = lv_label_create(ui->setting_device_btn_poweroff, NULL);
//	lv_label_set_text(ui->setting_device_btn_poweroff_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_device_btn_poweroff_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes setting_device_btn_23
	ui->setting_device_btn_23 = lv_btn_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_BTN_PART_MAIN for setting_device_btn_23
	static lv_style_t style_setting_device_btn_23_main;
	lv_style_reset(&style_setting_device_btn_23_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_btn_23_main
	lv_style_set_radius(&style_setting_device_btn_23_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_setting_device_btn_23_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_btn_23_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_btn_23_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_btn_23_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_device_btn_23_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_setting_device_btn_23_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_device_btn_23_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_device_btn_23_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_device_btn_23_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->setting_device_btn_23, LV_BTN_PART_MAIN, &style_setting_device_btn_23_main);
	lv_obj_set_pos(ui->setting_device_btn_23, 14, 130);
	lv_obj_set_size(ui->setting_device_btn_23, 218, 158);
//	ui->setting_device_btn_23_label = lv_label_create(ui->setting_device_btn_23, NULL);
//	lv_label_set_text(ui->setting_device_btn_23_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_device_btn_23_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes setting_device_btn_light_control
	ui->setting_device_btn_light_control = lv_btn_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_BTN_PART_MAIN for setting_device_btn_light_control
	static lv_style_t style_setting_device_btn_light_control_main;
	lv_style_reset(&style_setting_device_btn_light_control_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_btn_light_control_main
	lv_style_set_radius(&style_setting_device_btn_light_control_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_setting_device_btn_light_control_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_btn_light_control_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_btn_light_control_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_btn_light_control_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_device_btn_light_control_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_setting_device_btn_light_control_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_device_btn_light_control_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_device_btn_light_control_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_device_btn_light_control_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->setting_device_btn_light_control, LV_BTN_PART_MAIN, &style_setting_device_btn_light_control_main);
	lv_obj_set_pos(ui->setting_device_btn_light_control, 14, 482);
	lv_obj_set_size(ui->setting_device_btn_light_control, 218, 158);
//	ui->setting_device_btn_light_control_label = lv_label_create(ui->setting_device_btn_light_control, NULL);
//	lv_label_set_text(ui->setting_device_btn_light_control_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_device_btn_light_control_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes setting_device_btn_26
	ui->setting_device_btn_26 = lv_btn_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_BTN_PART_MAIN for setting_device_btn_26
	static lv_style_t style_setting_device_btn_26_main;
	lv_style_reset(&style_setting_device_btn_26_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_btn_26_main
	lv_style_set_radius(&style_setting_device_btn_26_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_setting_device_btn_26_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_btn_26_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_btn_26_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_btn_26_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_device_btn_26_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_setting_device_btn_26_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_device_btn_26_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_device_btn_26_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_device_btn_26_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->setting_device_btn_26, LV_BTN_PART_MAIN, &style_setting_device_btn_26_main);
	lv_obj_set_pos(ui->setting_device_btn_26, 246, 306);
	lv_obj_set_size(ui->setting_device_btn_26, 218, 158);
//	ui->setting_device_btn_26_label = lv_label_create(ui->setting_device_btn_26, NULL);
//	lv_label_set_text(ui->setting_device_btn_26_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_device_btn_26_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes setting_device_btn_25
	ui->setting_device_btn_25 = lv_btn_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_BTN_PART_MAIN for setting_device_btn_25
	static lv_style_t style_setting_device_btn_25_main;
	lv_style_reset(&style_setting_device_btn_25_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_btn_25_main
	lv_style_set_radius(&style_setting_device_btn_25_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_setting_device_btn_25_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_btn_25_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_btn_25_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_btn_25_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_device_btn_25_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_setting_device_btn_25_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_device_btn_25_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_device_btn_25_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_device_btn_25_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->setting_device_btn_25, LV_BTN_PART_MAIN, &style_setting_device_btn_25_main);
	lv_obj_set_pos(ui->setting_device_btn_25, 14, 306);
	lv_obj_set_size(ui->setting_device_btn_25, 218, 158);
//	ui->setting_device_btn_25_label = lv_label_create(ui->setting_device_btn_25, NULL);
//	lv_label_set_text(ui->setting_device_btn_25_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_device_btn_25_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes setting_device_btn_24
	ui->setting_device_btn_24 = lv_btn_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_BTN_PART_MAIN for setting_device_btn_24
	static lv_style_t style_setting_device_btn_24_main;
	lv_style_reset(&style_setting_device_btn_24_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_btn_24_main
	lv_style_set_radius(&style_setting_device_btn_24_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_setting_device_btn_24_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_btn_24_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_btn_24_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_btn_24_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_device_btn_24_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_setting_device_btn_24_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_device_btn_24_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_device_btn_24_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_device_btn_24_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->setting_device_btn_24, LV_BTN_PART_MAIN, &style_setting_device_btn_24_main);
	lv_obj_set_pos(ui->setting_device_btn_24, 246, 130);
	lv_obj_set_size(ui->setting_device_btn_24, 218, 158);
//	ui->setting_device_btn_24_label = lv_label_create(ui->setting_device_btn_24, NULL);
//	lv_label_set_text(ui->setting_device_btn_24_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_device_btn_24_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes setting_device_label_43
	ui->setting_device_label_43 = lv_label_create(ui->setting_device_cont_seting_device, NULL);
	lv_label_set_text(ui->setting_device_label_43, ">");
	lv_label_set_long_mode(ui->setting_device_label_43, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_device_label_43, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for setting_device_label_43
	static lv_style_t style_setting_device_label_43_main;
	lv_style_reset(&style_setting_device_label_43_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_label_43_main
	lv_style_set_radius(&style_setting_device_label_43_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_label_43_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_label_43_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_label_43_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_label_43_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_device_label_43_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_device_label_43_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_device_label_43_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_device_label_43_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_device_label_43_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_device_label_43_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_device_label_43_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_label_43, LV_LABEL_PART_MAIN, &style_setting_device_label_43_main);
	lv_obj_set_pos(ui->setting_device_label_43, 200, 329);
	lv_obj_set_size(ui->setting_device_label_43, 20, 0);

	//Write codes setting_device_label_42
	ui->setting_device_label_42 = lv_label_create(ui->setting_device_cont_seting_device, NULL);
	lv_label_set_text(ui->setting_device_label_42, ">");
	lv_label_set_long_mode(ui->setting_device_label_42, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_device_label_42, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for setting_device_label_42
	static lv_style_t style_setting_device_label_42_main;
	lv_style_reset(&style_setting_device_label_42_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_label_42_main
	lv_style_set_radius(&style_setting_device_label_42_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_label_42_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_label_42_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_label_42_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_label_42_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_device_label_42_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_device_label_42_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_device_label_42_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_device_label_42_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_device_label_42_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_device_label_42_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_device_label_42_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_label_42, LV_LABEL_PART_MAIN, &style_setting_device_label_42_main);
	lv_obj_set_pos(ui->setting_device_label_42, 432, 329);
	lv_obj_set_size(ui->setting_device_label_42, 20, 0);

	//Write codes setting_device_label_41
	ui->setting_device_label_41 = lv_label_create(ui->setting_device_cont_seting_device, NULL);
	lv_label_set_text(ui->setting_device_label_41, ">");
	lv_label_set_long_mode(ui->setting_device_label_41, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_device_label_41, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for setting_device_label_41
	static lv_style_t style_setting_device_label_41_main;
	lv_style_reset(&style_setting_device_label_41_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_label_41_main
	lv_style_set_radius(&style_setting_device_label_41_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_label_41_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_label_41_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_label_41_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_label_41_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_device_label_41_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_device_label_41_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_device_label_41_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_device_label_41_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_device_label_41_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_device_label_41_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_device_label_41_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_label_41, LV_LABEL_PART_MAIN, &style_setting_device_label_41_main);
	lv_obj_set_pos(ui->setting_device_label_41, 432, 153);
	lv_obj_set_size(ui->setting_device_label_41, 20, 0);

	//Write codes setting_device_label_40
	ui->setting_device_label_40 = lv_label_create(ui->setting_device_cont_seting_device, NULL);
	lv_label_set_text(ui->setting_device_label_40, ">");
	lv_label_set_long_mode(ui->setting_device_label_40, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_device_label_40, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for setting_device_label_40
	static lv_style_t style_setting_device_label_40_main;
	lv_style_reset(&style_setting_device_label_40_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_label_40_main
	lv_style_set_radius(&style_setting_device_label_40_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_label_40_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_label_40_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_label_40_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_label_40_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_device_label_40_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_device_label_40_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_device_label_40_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_device_label_40_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_device_label_40_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_device_label_40_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_device_label_40_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_label_40, LV_LABEL_PART_MAIN, &style_setting_device_label_40_main);
	lv_obj_set_pos(ui->setting_device_label_40, 200, 153);
	lv_obj_set_size(ui->setting_device_label_40, 20, 0);

	//Write codes setting_device_label_light_state
	ui->setting_device_label_light_state = lv_label_create(ui->setting_device_cont_seting_device, NULL);
	lv_label_set_text(ui->setting_device_label_light_state, "OFF");
	lv_label_set_long_mode(ui->setting_device_label_light_state, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_device_label_light_state, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_device_label_light_state
	static lv_style_t style_setting_device_label_light_state_main;
	lv_style_reset(&style_setting_device_label_light_state_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_label_light_state_main
	lv_style_set_radius(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_device_label_light_state_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_label_light_state, LV_LABEL_PART_MAIN, &style_setting_device_label_light_state_main);
	lv_obj_set_pos(ui->setting_device_label_light_state, 40, 596);
	lv_obj_set_size(ui->setting_device_label_light_state, 100, 0);

	//Write codes setting_device_label_38
	ui->setting_device_label_38 = lv_label_create(ui->setting_device_cont_seting_device, NULL);
	lv_label_set_long_mode(ui->setting_device_label_38, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_device_label_38, poweroff[cur_language]);
//	lv_label_set_long_mode(ui->setting_device_label_38, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_device_label_38, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_device_label_38
	static lv_style_t style_setting_device_label_38_main;
	lv_style_reset(&style_setting_device_label_38_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_label_38_main
	lv_style_set_radius(&style_setting_device_label_38_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_label_38_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_label_38_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_label_38_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_label_38_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_device_label_38_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_device_label_38_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_device_label_38_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_device_label_38_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_device_label_38_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_device_label_38_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_device_label_38_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_device_label_38_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_label_38, LV_LABEL_PART_MAIN, &style_setting_device_label_38_main);
	lv_obj_set_pos(ui->setting_device_label_38, 272, 555);
	lv_obj_set_size(ui->setting_device_label_38, 180, 42);

	//Write codes setting_device_label_37
	ui->setting_device_label_37 = lv_label_create(ui->setting_device_cont_seting_device, NULL);
	lv_label_set_long_mode(ui->setting_device_label_37, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_device_label_37,light_control[cur_language]);
//	lv_label_set_long_mode(ui->setting_device_label_37, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_device_label_37, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_device_label_37
	static lv_style_t style_setting_device_label_37_main;
	lv_style_reset(&style_setting_device_label_37_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_label_37_main
	lv_style_set_radius(&style_setting_device_label_37_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_label_37_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_label_37_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_label_37_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_label_37_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_device_label_37_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_device_label_37_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_device_label_37_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
    lv_style_set_text_letter_space(&style_setting_device_label_37_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_device_label_37_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_device_label_37_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_device_label_37_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_device_label_37_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_label_37, LV_LABEL_PART_MAIN, &style_setting_device_label_37_main);
	lv_obj_set_pos(ui->setting_device_label_37, 40, 555);
	lv_obj_set_size(ui->setting_device_label_37, 180, 42);

	//Write codes setting_device_label_36
	ui->setting_device_label_36 = lv_label_create(ui->setting_device_cont_seting_device, NULL);
	lv_label_set_long_mode(ui->setting_device_label_36, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_device_label_36, language[cur_language]);
//	lv_label_set_long_mode(ui->setting_device_label_36, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_device_label_36, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_device_label_36
	static lv_style_t style_setting_device_label_36_main;
	lv_style_reset(&style_setting_device_label_36_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_label_36_main
	lv_style_set_radius(&style_setting_device_label_36_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_label_36_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_label_36_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_label_36_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_label_36_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_device_label_36_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_device_label_36_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_device_label_36_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_device_label_36_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_device_label_36_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_device_label_36_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_device_label_36_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_device_label_36_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_label_36, LV_LABEL_PART_MAIN, &style_setting_device_label_36_main);
	lv_obj_set_pos(ui->setting_device_label_36, 272, 379);
	lv_obj_set_size(ui->setting_device_label_36, 180, 42);

	//Write codes setting_device_label_35
	ui->setting_device_label_35 = lv_label_create(ui->setting_device_cont_seting_device, NULL);
	lv_label_set_long_mode(ui->setting_device_label_35, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_device_label_35, level[cur_language]);
//	lv_label_set_long_mode(ui->setting_device_label_35, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_device_label_35, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_device_label_35
	static lv_style_t style_setting_device_label_35_main;
	lv_style_reset(&style_setting_device_label_35_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_label_35_main
	lv_style_set_radius(&style_setting_device_label_35_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_label_35_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_label_35_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_label_35_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_label_35_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_device_label_35_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_device_label_35_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
	else
    {
        lv_style_set_text_font(&style_setting_device_label_35_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_device_label_35_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_device_label_35_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_device_label_35_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_device_label_35_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_device_label_35_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_label_35, LV_LABEL_PART_MAIN, &style_setting_device_label_35_main);
	lv_obj_set_pos(ui->setting_device_label_35, 40, 379);
	lv_obj_set_size(ui->setting_device_label_35, 180, 42);

	//Write codes setting_device_label_34
	ui->setting_device_label_34 = lv_label_create(ui->setting_device_cont_seting_device, NULL);
	lv_label_set_long_mode(ui->setting_device_label_34, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_device_label_34, abs_setting[cur_language]);
//	lv_label_set_long_mode(ui->setting_device_label_34, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_device_label_34, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_device_label_34
	static lv_style_t style_setting_device_label_34_main;
	lv_style_reset(&style_setting_device_label_34_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_label_34_main
	lv_style_set_radius(&style_setting_device_label_34_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_label_34_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_label_34_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_label_34_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_label_34_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_device_label_34_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_device_label_34_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_device_label_34_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_device_label_34_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_device_label_34_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_device_label_34_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_device_label_34_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_device_label_34_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_label_34, LV_LABEL_PART_MAIN, &style_setting_device_label_34_main);
	lv_obj_set_pos(ui->setting_device_label_34, 272, 203);
	lv_obj_set_size(ui->setting_device_label_34, 180, 42);

	//Write codes setting_device_label_33
	ui->setting_device_label_33 = lv_label_create(ui->setting_device_cont_seting_device, NULL);
	lv_label_set_long_mode(ui->setting_device_label_33, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_device_label_33, pla_setting[cur_language]);
//	lv_label_set_long_mode(ui->setting_device_label_33, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_device_label_33, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_device_label_33
	static lv_style_t style_setting_device_label_33_main;
	lv_style_reset(&style_setting_device_label_33_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_device_label_33_main
	lv_style_set_radius(&style_setting_device_label_33_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_device_label_33_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_device_label_33_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_device_label_33_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_device_label_33_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_device_label_33_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_device_label_33_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
	    lv_style_set_text_font(&style_setting_device_label_33_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_device_label_33_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_device_label_33_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_device_label_33_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_device_label_33_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_device_label_33_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_device_label_33, LV_LABEL_PART_MAIN, &style_setting_device_label_33_main);
	lv_obj_set_pos(ui->setting_device_label_33, 40, 203);
	lv_obj_set_size(ui->setting_device_label_33, 180, 42);

	//Write codes setting_device_img_15
	ui->setting_device_img_15 = lv_img_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_IMG_PART_MAIN for setting_device_img_15
//	static lv_style_t style_setting_device_img_15_main;
//	lv_style_reset(&style_setting_device_img_15_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_setting_device_img_15_main
//	lv_style_set_image_recolor(&style_setting_device_img_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_setting_device_img_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_setting_device_img_15_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->setting_device_img_15, LV_IMG_PART_MAIN, &style_setting_device_img_15_main);
	lv_obj_set_pos(ui->setting_device_img_15, 272, 505);
//	lv_obj_set_size(ui->setting_device_img_15, 44, 44);
//	lv_obj_set_click(ui->setting_device_img_15, true);
	lv_img_set_src(ui->setting_device_img_15,&_poweroff_alpha_44x44);
//	lv_img_set_pivot(ui->setting_device_img_15, 0,0);
//	lv_img_set_angle(ui->setting_device_img_15, 0);

	//Write codes setting_device_img_14
	ui->setting_device_img_14 = lv_img_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_IMG_PART_MAIN for setting_device_img_14
//	static lv_style_t style_setting_device_img_14_main;
//	lv_style_reset(&style_setting_device_img_14_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_setting_device_img_14_main
//	lv_style_set_image_recolor(&style_setting_device_img_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_setting_device_img_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_setting_device_img_14_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->setting_device_img_14, LV_IMG_PART_MAIN, &style_setting_device_img_14_main);
	lv_obj_set_pos(ui->setting_device_img_14, 40, 505);
//	lv_obj_set_size(ui->setting_device_img_14, 44, 44);
//	lv_obj_set_click(ui->setting_device_img_14, true);
	lv_img_set_src(ui->setting_device_img_14,&_lightctl_alpha_44x44);
//	lv_img_set_pivot(ui->setting_device_img_14, 0,0);
//	lv_img_set_angle(ui->setting_device_img_14, 0);

	//Write codes setting_device_img_13
	ui->setting_device_img_13 = lv_img_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_IMG_PART_MAIN for setting_device_img_13
//	static lv_style_t style_setting_device_img_13_main;
//	lv_style_reset(&style_setting_device_img_13_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_setting_device_img_13_main
//	lv_style_set_image_recolor(&style_setting_device_img_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_setting_device_img_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_setting_device_img_13_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->setting_device_img_13, LV_IMG_PART_MAIN, &style_setting_device_img_13_main);
	lv_obj_set_pos(ui->setting_device_img_13, 272, 329);
//	lv_obj_set_size(ui->setting_device_img_13, 44, 44);
//	lv_obj_set_click(ui->setting_device_img_13, true);
	lv_img_set_src(ui->setting_device_img_13,&_language_alpha_44x44);
//	lv_img_set_pivot(ui->setting_device_img_13, 0,0);
//	lv_img_set_angle(ui->setting_device_img_13, 0);

	//Write codes setting_device_img_12
	ui->setting_device_img_12 = lv_img_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_IMG_PART_MAIN for setting_device_img_12
//	static lv_style_t style_setting_device_img_12_main;
//	lv_style_reset(&style_setting_device_img_12_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_setting_device_img_12_main
//	lv_style_set_image_recolor(&style_setting_device_img_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_setting_device_img_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_setting_device_img_12_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->setting_device_img_12, LV_IMG_PART_MAIN, &style_setting_device_img_12_main);
	lv_obj_set_pos(ui->setting_device_img_12, 40, 329);
//	lv_obj_set_size(ui->setting_device_img_12, 44, 44);
//	lv_obj_set_click(ui->setting_device_img_12, true);
	lv_img_set_src(ui->setting_device_img_12,&_offset_alpha_44x44);
//	lv_img_set_pivot(ui->setting_device_img_12, 0,0);
//	lv_img_set_angle(ui->setting_device_img_12, 0);

	//Write codes setting_device_img_11
	ui->setting_device_img_11 = lv_img_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_IMG_PART_MAIN for setting_device_img_11
//	static lv_style_t style_setting_device_img_11_main;
//	lv_style_reset(&style_setting_device_img_11_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_setting_device_img_11_main
//	lv_style_set_image_recolor(&style_setting_device_img_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_setting_device_img_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_setting_device_img_11_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->setting_device_img_11, LV_IMG_PART_MAIN, &style_setting_device_img_11_main);
	lv_obj_set_pos(ui->setting_device_img_11, 272, 153);
//	lv_obj_set_size(ui->setting_device_img_11, 44, 44);
//	lv_obj_set_click(ui->setting_device_img_11, true);
	lv_img_set_src(ui->setting_device_img_11,&_ABSset_alpha_44x44);
//	lv_img_set_pivot(ui->setting_device_img_11, 0,0);
//	lv_img_set_angle(ui->setting_device_img_11, 0);

	//Write codes setting_device_img_10
	ui->setting_device_img_10 = lv_img_create(ui->setting_device_cont_seting_device, NULL);

	//Write style LV_IMG_PART_MAIN for setting_device_img_10
//	static lv_style_t style_setting_device_img_10_main;
//	lv_style_reset(&style_setting_device_img_10_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_setting_device_img_10_main
//	lv_style_set_image_recolor(&style_setting_device_img_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_setting_device_img_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_setting_device_img_10_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->setting_device_img_10, LV_IMG_PART_MAIN, &style_setting_device_img_10_main);
	lv_obj_set_pos(ui->setting_device_img_10, 40, 153);
//	lv_obj_set_size(ui->setting_device_img_10, 44, 44);
//	lv_obj_set_click(ui->setting_device_img_10, true);
	lv_img_set_src(ui->setting_device_img_10,&_PLAset_alpha_44x44);
//	lv_img_set_pivot(ui->setting_device_img_10, 0,0);
//	lv_img_set_angle(ui->setting_device_img_10, 0);
//	lv_cont_set_layout(ui->setting_device_cont_seting_device, LV_LAYOUT_OFF);
//	lv_cont_set_fit(ui->setting_device_cont_seting_device, LV_FIT_NONE);

	//Init events for screen
	events_init_setting_device(ui);
}
