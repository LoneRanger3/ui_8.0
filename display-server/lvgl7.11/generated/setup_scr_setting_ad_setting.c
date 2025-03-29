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

void setup_scr_setting_ad_setting(lv_ui *ui){

	//Write codes setting_ad_setting
//	ui->setting_ad_setting = lv_obj_create(NULL, NULL);

	if(ui->setting_ad_setting_cont_setting_ad_setting != NULL)
    {
        return;
    }
	//Write codes setting_ad_setting_cont_setting_ad_setting
	ui->setting_ad_setting_cont_setting_ad_setting = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for setting_ad_setting_cont_setting_ad_setting
	static lv_style_t style_setting_ad_setting_cont_setting_ad_setting_main;
	lv_style_reset(&style_setting_ad_setting_cont_setting_ad_setting_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_cont_setting_ad_setting_main
	lv_style_set_radius(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_setting_ad_setting_cont_setting_ad_setting_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_ad_setting_cont_setting_ad_setting, LV_CONT_PART_MAIN, &style_setting_ad_setting_cont_setting_ad_setting_main);
	lv_obj_set_pos(ui->setting_ad_setting_cont_setting_ad_setting, 0, 0);
	lv_obj_set_size(ui->setting_ad_setting_cont_setting_ad_setting, 480, 674);
	lv_obj_set_click(ui->setting_ad_setting_cont_setting_ad_setting, false);

	//Write codes setting_ad_setting_btn_restore_net
	ui->setting_ad_setting_btn_restore_net = lv_btn_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);

	//Write style LV_BTN_PART_MAIN for setting_ad_setting_btn_restore_net
	static lv_style_t style_setting_ad_setting_btn_restore_net_main;
	lv_style_reset(&style_setting_ad_setting_btn_restore_net_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_btn_restore_net_main
	lv_style_set_radius(&style_setting_ad_setting_btn_restore_net_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_setting_ad_setting_btn_restore_net_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_btn_restore_net_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_btn_restore_net_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_btn_restore_net_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_ad_setting_btn_restore_net_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_setting_ad_setting_btn_restore_net_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_ad_setting_btn_restore_net_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_ad_setting_btn_restore_net_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_ad_setting_btn_restore_net_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->setting_ad_setting_btn_restore_net, LV_BTN_PART_MAIN, &style_setting_ad_setting_btn_restore_net_main);
	lv_obj_set_pos(ui->setting_ad_setting_btn_restore_net, 14, 306);
	lv_obj_set_size(ui->setting_ad_setting_btn_restore_net, 218, 158);
//	ui->setting_ad_setting_btn_restore_net_label = lv_label_create(ui->setting_ad_setting_btn_restore_net, NULL);
//	lv_label_set_text(ui->setting_ad_setting_btn_restore_net_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_ad_setting_btn_restore_net_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes setting_ad_setting_btn_set_wifi
	ui->setting_ad_setting_btn_set_wifi = lv_btn_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);

	//Write style LV_BTN_PART_MAIN for setting_ad_setting_btn_set_wifi
	static lv_style_t style_setting_ad_setting_btn_set_wifi_main;
	lv_style_reset(&style_setting_ad_setting_btn_set_wifi_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_btn_set_wifi_main
	lv_style_set_radius(&style_setting_ad_setting_btn_set_wifi_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_setting_ad_setting_btn_set_wifi_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_btn_set_wifi_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_btn_set_wifi_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_btn_set_wifi_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_ad_setting_btn_set_wifi_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_setting_ad_setting_btn_set_wifi_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_ad_setting_btn_set_wifi_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_ad_setting_btn_set_wifi_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_ad_setting_btn_set_wifi_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->setting_ad_setting_btn_set_wifi, LV_BTN_PART_MAIN, &style_setting_ad_setting_btn_set_wifi_main);
	lv_obj_set_pos(ui->setting_ad_setting_btn_set_wifi, 14, 482);
	lv_obj_set_size(ui->setting_ad_setting_btn_set_wifi, 218, 158);
//	ui->setting_ad_setting_btn_set_wifi_label = lv_label_create(ui->setting_ad_setting_btn_set_wifi, NULL);
//	lv_label_set_text(ui->setting_ad_setting_btn_set_wifi_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_ad_setting_btn_set_wifi_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes setting_ad_setting_btn_factory
	ui->setting_ad_setting_btn_factory = lv_btn_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);

	//Write style LV_BTN_PART_MAIN for setting_ad_setting_btn_factory
	static lv_style_t style_setting_ad_setting_btn_factory_main;
	lv_style_reset(&style_setting_ad_setting_btn_factory_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_btn_factory_main
	lv_style_set_radius(&style_setting_ad_setting_btn_factory_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_setting_ad_setting_btn_factory_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_btn_factory_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_btn_factory_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_btn_factory_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_ad_setting_btn_factory_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_setting_ad_setting_btn_factory_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_ad_setting_btn_factory_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_ad_setting_btn_factory_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_ad_setting_btn_factory_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->setting_ad_setting_btn_factory, LV_BTN_PART_MAIN, &style_setting_ad_setting_btn_factory_main);
	lv_obj_set_pos(ui->setting_ad_setting_btn_factory, 246, 306);
	lv_obj_set_size(ui->setting_ad_setting_btn_factory, 218, 158);
//	ui->setting_ad_setting_btn_factory_label = lv_label_create(ui->setting_ad_setting_btn_factory, NULL);
//	lv_label_set_text(ui->setting_ad_setting_btn_factory_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_ad_setting_btn_factory_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes setting_ad_setting_label_wifi_state
	ui->setting_ad_setting_label_wifi_state = lv_label_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);
	lv_label_set_text(ui->setting_ad_setting_label_wifi_state, "OFF");
	lv_label_set_long_mode(ui->setting_ad_setting_label_wifi_state, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_ad_setting_label_wifi_state, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_ad_setting_label_wifi_state
	static lv_style_t style_setting_ad_setting_label_wifi_state_main;
	lv_style_reset(&style_setting_ad_setting_label_wifi_state_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_label_wifi_state_main
	lv_style_set_radius(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_setting_ad_setting_label_wifi_state_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_ad_setting_label_wifi_state, LV_LABEL_PART_MAIN, &style_setting_ad_setting_label_wifi_state_main);
	lv_obj_set_pos(ui->setting_ad_setting_label_wifi_state, 40, 596);
	lv_obj_set_size(ui->setting_ad_setting_label_wifi_state, 100, 0);

	//Write codes setting_ad_setting_btn_PID_set
	ui->setting_ad_setting_btn_PID_set = lv_btn_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);

	//Write style LV_BTN_PART_MAIN for setting_ad_setting_btn_PID_set
	static lv_style_t style_setting_ad_setting_btn_PID_set_main;
	lv_style_reset(&style_setting_ad_setting_btn_PID_set_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_btn_PID_set_main
	lv_style_set_radius(&style_setting_ad_setting_btn_PID_set_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_setting_ad_setting_btn_PID_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_btn_PID_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_btn_PID_set_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_btn_PID_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_ad_setting_btn_PID_set_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_setting_ad_setting_btn_PID_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_ad_setting_btn_PID_set_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_ad_setting_btn_PID_set_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_ad_setting_btn_PID_set_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->setting_ad_setting_btn_PID_set, LV_BTN_PART_MAIN, &style_setting_ad_setting_btn_PID_set_main);
	lv_obj_set_pos(ui->setting_ad_setting_btn_PID_set, 246, 130);
	lv_obj_set_size(ui->setting_ad_setting_btn_PID_set, 218, 158);
//	ui->setting_ad_setting_btn_PID_set_label = lv_label_create(ui->setting_ad_setting_btn_PID_set, NULL);
//	lv_label_set_text(ui->setting_ad_setting_btn_PID_set_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_ad_setting_btn_PID_set_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes setting_ad_setting_label_45
	ui->setting_ad_setting_label_45 = lv_label_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);
	lv_label_set_text(ui->setting_ad_setting_label_45, ">");
	lv_label_set_long_mode(ui->setting_ad_setting_label_45, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_ad_setting_label_45, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for setting_ad_setting_label_45
	static lv_style_t style_setting_ad_setting_label_45_main;
	lv_style_reset(&style_setting_ad_setting_label_45_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_label_45_main
	lv_style_set_radius(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_setting_ad_setting_label_45_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_ad_setting_label_45, LV_LABEL_PART_MAIN, &style_setting_ad_setting_label_45_main);
	lv_obj_set_pos(ui->setting_ad_setting_label_45, 432, 153);
	lv_obj_set_size(ui->setting_ad_setting_label_45, 20, 0);

	//Write codes setting_ad_setting_btn_motion_set
	ui->setting_ad_setting_btn_motion_set = lv_btn_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);

	//Write style LV_BTN_PART_MAIN for setting_ad_setting_btn_motion_set
	static lv_style_t style_setting_ad_setting_btn_motion_set_main;
	lv_style_reset(&style_setting_ad_setting_btn_motion_set_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_btn_motion_set_main
	lv_style_set_radius(&style_setting_ad_setting_btn_motion_set_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_setting_ad_setting_btn_motion_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_btn_motion_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_btn_motion_set_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_btn_motion_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_ad_setting_btn_motion_set_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_setting_ad_setting_btn_motion_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_ad_setting_btn_motion_set_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_ad_setting_btn_motion_set_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_ad_setting_btn_motion_set_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->setting_ad_setting_btn_motion_set, LV_BTN_PART_MAIN, &style_setting_ad_setting_btn_motion_set_main);
	lv_obj_set_pos(ui->setting_ad_setting_btn_motion_set, 14, 130);
	lv_obj_set_size(ui->setting_ad_setting_btn_motion_set, 218, 158);
//	ui->setting_ad_setting_btn_motion_set_label = lv_label_create(ui->setting_ad_setting_btn_motion_set, NULL);
//	lv_label_set_text(ui->setting_ad_setting_btn_motion_set_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_ad_setting_btn_motion_set_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes setting_ad_setting_img_1
	ui->setting_ad_setting_img_1 = lv_img_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);

	//Write style LV_IMG_PART_MAIN for setting_ad_setting_img_1
//	static lv_style_t style_setting_ad_setting_img_1_main;
//	lv_style_reset(&style_setting_ad_setting_img_1_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_img_1_main
//	lv_style_set_image_recolor(&style_setting_ad_setting_img_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_setting_ad_setting_img_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_setting_ad_setting_img_1_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->setting_ad_setting_img_1, LV_IMG_PART_MAIN, &style_setting_ad_setting_img_1_main);
	lv_obj_set_pos(ui->setting_ad_setting_img_1, 40, 153);
//	lv_obj_set_size(ui->setting_ad_setting_img_1, 44, 44);
//	lv_obj_set_click(ui->setting_ad_setting_img_1, true);
	lv_img_set_src(ui->setting_ad_setting_img_1,&_motion_alpha_44x44);
//	lv_img_set_pivot(ui->setting_ad_setting_img_1, 0,0);
//	lv_img_set_angle(ui->setting_ad_setting_img_1, 0);

	//Write codes setting_ad_setting_label_44
	ui->setting_ad_setting_label_44 = lv_label_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);
	lv_label_set_text(ui->setting_ad_setting_label_44, ">");
	lv_label_set_long_mode(ui->setting_ad_setting_label_44, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_ad_setting_label_44, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for setting_ad_setting_label_44
	static lv_style_t style_setting_ad_setting_label_44_main;
	lv_style_reset(&style_setting_ad_setting_label_44_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_label_44_main
	lv_style_set_radius(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_ad_setting_label_44_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_ad_setting_label_44, LV_LABEL_PART_MAIN, &style_setting_ad_setting_label_44_main);
	lv_obj_set_pos(ui->setting_ad_setting_label_44, 200, 153);
	lv_obj_set_size(ui->setting_ad_setting_label_44, 20, 0);

	//Write codes setting_ad_setting_img_16
	ui->setting_ad_setting_img_16 = lv_img_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);

	//Write style LV_IMG_PART_MAIN for setting_ad_setting_img_16
//	static lv_style_t style_setting_ad_setting_img_16_main;
//	lv_style_reset(&style_setting_ad_setting_img_16_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_img_16_main
//	lv_style_set_image_recolor(&style_setting_ad_setting_img_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_setting_ad_setting_img_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_setting_ad_setting_img_16_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->setting_ad_setting_img_16, LV_IMG_PART_MAIN, &style_setting_ad_setting_img_16_main);
	lv_obj_set_pos(ui->setting_ad_setting_img_16, 272, 329);
//	lv_obj_set_size(ui->setting_ad_setting_img_16, 44, 44);
//	lv_obj_set_click(ui->setting_ad_setting_img_16, true);
	lv_img_set_src(ui->setting_ad_setting_img_16,&_restor_alpha_44x44);
//	lv_img_set_pivot(ui->setting_ad_setting_img_16, 0,0);
//	lv_img_set_angle(ui->setting_ad_setting_img_16, 0);

	//Write codes setting_ad_setting_img_17
	ui->setting_ad_setting_img_17 = lv_img_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);

	//Write style LV_IMG_PART_MAIN for setting_ad_setting_img_17
//	static lv_style_t style_setting_ad_setting_img_17_main;
//	lv_style_reset(&style_setting_ad_setting_img_17_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_img_17_main
//	lv_style_set_image_recolor(&style_setting_ad_setting_img_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_setting_ad_setting_img_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_setting_ad_setting_img_17_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->setting_ad_setting_img_17, LV_IMG_PART_MAIN, &style_setting_ad_setting_img_17_main);
	lv_obj_set_pos(ui->setting_ad_setting_img_17, 40, 505);
//	lv_obj_set_size(ui->setting_ad_setting_img_17, 44, 44);
//	lv_obj_set_click(ui->setting_ad_setting_img_17, true);
	lv_img_set_src(ui->setting_ad_setting_img_17,&_wifi_alpha_44x44);
//	lv_img_set_pivot(ui->setting_ad_setting_img_17, 0,0);
//	lv_img_set_angle(ui->setting_ad_setting_img_17, 0);

	//Write codes setting_ad_setting_label_20
	ui->setting_ad_setting_label_20 = lv_label_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);
	lv_label_set_long_mode(ui->setting_ad_setting_label_20, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_ad_setting_label_20, restore_network[cur_language]);
//	lv_label_set_long_mode(ui->setting_ad_setting_label_20, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_ad_setting_label_20, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_ad_setting_label_20
	static lv_style_t style_setting_ad_setting_label_20_main;
	lv_style_reset(&style_setting_ad_setting_label_20_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_label_20_main
	lv_style_set_radius(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_ad_setting_label_20_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_ad_setting_label_20, LV_LABEL_PART_MAIN, &style_setting_ad_setting_label_20_main);
	lv_obj_set_pos(ui->setting_ad_setting_label_20, 40, 379);
	lv_obj_set_size(ui->setting_ad_setting_label_20, 150, 42);

	//Write codes setting_ad_setting_img_3
	ui->setting_ad_setting_img_3 = lv_img_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);

	//Write style LV_IMG_PART_MAIN for setting_ad_setting_img_3
//	static lv_style_t style_setting_ad_setting_img_3_main;
//	lv_style_reset(&style_setting_ad_setting_img_3_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_img_3_main
//	lv_style_set_image_recolor(&style_setting_ad_setting_img_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_setting_ad_setting_img_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_setting_ad_setting_img_3_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->setting_ad_setting_img_3, LV_IMG_PART_MAIN, &style_setting_ad_setting_img_3_main);
	lv_obj_set_pos(ui->setting_ad_setting_img_3, 40, 330);
//	lv_obj_set_size(ui->setting_ad_setting_img_3, 41, 41);
//	lv_obj_set_click(ui->setting_ad_setting_img_3, true);
	lv_img_set_src(ui->setting_ad_setting_img_3,&_resnet_alpha_41x41);
//	lv_img_set_pivot(ui->setting_ad_setting_img_3, 0,0);
//	lv_img_set_angle(ui->setting_ad_setting_img_3, 0);

	//Write codes setting_ad_setting_label_18
	ui->setting_ad_setting_label_18 = lv_label_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);
	lv_label_set_long_mode(ui->setting_ad_setting_label_18, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_ad_setting_label_18, temp_pid[cur_language]);
//	lv_label_set_long_mode(ui->setting_ad_setting_label_18, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_ad_setting_label_18, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_ad_setting_label_18
	static lv_style_t style_setting_ad_setting_label_18_main;
	lv_style_reset(&style_setting_ad_setting_label_18_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_label_18_main
	lv_style_set_radius(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_ad_setting_label_18_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_ad_setting_label_18, LV_LABEL_PART_MAIN, &style_setting_ad_setting_label_18_main);
	lv_obj_set_pos(ui->setting_ad_setting_label_18, 272, 203);
	lv_obj_set_size(ui->setting_ad_setting_label_18, 150, 42);

	//Write codes setting_ad_setting_label_19
	ui->setting_ad_setting_label_19 = lv_label_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);
	lv_label_set_text(ui->setting_ad_setting_label_19, "WIFI");
	lv_label_set_long_mode(ui->setting_ad_setting_label_19, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_ad_setting_label_19, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_ad_setting_label_19
	static lv_style_t style_setting_ad_setting_label_19_main;
	lv_style_reset(&style_setting_ad_setting_label_19_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_label_19_main
	lv_style_set_radius(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_ad_setting_label_19_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_ad_setting_label_19, LV_LABEL_PART_MAIN, &style_setting_ad_setting_label_19_main);
	lv_obj_set_pos(ui->setting_ad_setting_label_19, 40, 555);
	lv_obj_set_size(ui->setting_ad_setting_label_19, 100, 0);

	//Write codes setting_ad_setting_label_17
	ui->setting_ad_setting_label_17 = lv_label_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);
	lv_label_set_long_mode(ui->setting_ad_setting_label_17, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_ad_setting_label_17, restore_factory[cur_language]);
//	lv_label_set_long_mode(ui->setting_ad_setting_label_17, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_ad_setting_label_17, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_ad_setting_label_17
	static lv_style_t style_setting_ad_setting_label_17_main;
	lv_style_reset(&style_setting_ad_setting_label_17_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_label_17_main
	lv_style_set_radius(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_ad_setting_label_17_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_ad_setting_label_17, LV_LABEL_PART_MAIN, &style_setting_ad_setting_label_17_main);
	lv_obj_set_pos(ui->setting_ad_setting_label_17, 272, 380);
	lv_obj_set_size(ui->setting_ad_setting_label_17, 180, 42);

	//Write codes setting_ad_setting_img_2
	ui->setting_ad_setting_img_2 = lv_img_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);

	//Write style LV_IMG_PART_MAIN for setting_ad_setting_img_2
//	static lv_style_t style_setting_ad_setting_img_2_main;
//	lv_style_reset(&style_setting_ad_setting_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_img_2_main
//	lv_style_set_image_recolor(&style_setting_ad_setting_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_setting_ad_setting_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_setting_ad_setting_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->setting_ad_setting_img_2, LV_IMG_PART_MAIN, &style_setting_ad_setting_img_2_main);
	lv_obj_set_pos(ui->setting_ad_setting_img_2, 272, 153);
//	lv_obj_set_size(ui->setting_ad_setting_img_2, 44, 44);
//	lv_obj_set_click(ui->setting_ad_setting_img_2, true);
	lv_img_set_src(ui->setting_ad_setting_img_2,&_PID_alpha_44x44);
//	lv_img_set_pivot(ui->setting_ad_setting_img_2, 0,0);
//	lv_img_set_angle(ui->setting_ad_setting_img_2, 0);

	//Write codes setting_ad_setting_label_16
	ui->setting_ad_setting_label_16 = lv_label_create(ui->setting_ad_setting_cont_setting_ad_setting, NULL);
	lv_label_set_long_mode(ui->setting_ad_setting_label_16, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_ad_setting_label_16, motion[cur_language]);
//	lv_label_set_long_mode(ui->setting_ad_setting_label_16, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_ad_setting_label_16, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_ad_setting_label_16
	static lv_style_t style_setting_ad_setting_label_16_main;
	lv_style_reset(&style_setting_ad_setting_label_16_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_ad_setting_label_16_main
	lv_style_set_radius(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_ad_setting_label_16_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_ad_setting_label_16, LV_LABEL_PART_MAIN, &style_setting_ad_setting_label_16_main);
	lv_obj_set_pos(ui->setting_ad_setting_label_16, 40, 203);
	lv_obj_set_size(ui->setting_ad_setting_label_16, 150, 42);
	lv_cont_set_layout(ui->setting_ad_setting_cont_setting_ad_setting, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->setting_ad_setting_cont_setting_ad_setting, LV_FIT_NONE);

	//Init events for screen
	events_init_setting_ad_setting(ui);
}
