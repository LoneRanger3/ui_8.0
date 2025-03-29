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

void setup_scr_setting_menu(lv_ui *ui){

	//Write codes setting_menu
//	ui->setting_menu = lv_obj_create(NULL, NULL);

	//Write codes setting_menu_cont_seting_menu
	if(ui->setting_menu_cont_seting_menu != NULL)
    {
        lv_obj_move_foreground(ui->setting_menu_cont_seting_menu);
        return;
    }
	ui->setting_menu_cont_seting_menu = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for setting_menu_cont_seting_menu
	static lv_style_t style_setting_menu_cont_seting_menu_main;
	lv_style_reset(&style_setting_menu_cont_seting_menu_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_menu_cont_seting_menu_main
	lv_style_set_radius(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_setting_menu_cont_seting_menu_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_menu_cont_seting_menu, LV_CONT_PART_MAIN, &style_setting_menu_cont_seting_menu_main);
	lv_obj_set_pos(ui->setting_menu_cont_seting_menu, 0, 0);
	lv_obj_set_size(ui->setting_menu_cont_seting_menu, 480, 105);
	lv_obj_set_click(ui->setting_menu_cont_seting_menu, false);

	//Write codes setting_menu_btn_about
	ui->setting_menu_btn_about = lv_btn_create(ui->setting_menu_cont_seting_menu, NULL);

	//Write style LV_BTN_PART_MAIN for setting_menu_btn_about
	static lv_style_t style_setting_menu_btn_about_main;
	lv_style_reset(&style_setting_menu_btn_about_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_menu_btn_about_main
	lv_style_set_radius(&style_setting_menu_btn_about_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_menu_btn_about_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_menu_btn_about_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_menu_btn_about_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_menu_btn_about_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_menu_btn_about_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_setting_menu_btn_about_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_menu_btn_about_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_menu_btn_about_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_menu_btn_about_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_setting_menu_btn_about_main
	lv_style_set_radius(&style_setting_menu_btn_about_main, LV_STATE_PRESSED, 6);
	lv_style_set_bg_color(&style_setting_menu_btn_about_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_color(&style_setting_menu_btn_about_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_dir(&style_setting_menu_btn_about_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_menu_btn_about_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_setting_menu_btn_about_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_setting_menu_btn_about_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_setting_menu_btn_about_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_setting_menu_btn_about_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_menu_btn_about_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->setting_menu_btn_about, LV_BTN_PART_MAIN, &style_setting_menu_btn_about_main);
	lv_obj_set_pos(ui->setting_menu_btn_about, 320, 0);
	lv_obj_set_size(ui->setting_menu_btn_about, 158, 104);
//	ui->setting_menu_btn_about_label = lv_label_create(ui->setting_menu_btn_about, NULL);
//	lv_label_set_text(ui->setting_menu_btn_about_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_menu_btn_about_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes setting_menu_btn_ad_setting
	ui->setting_menu_btn_ad_setting = lv_btn_create(ui->setting_menu_cont_seting_menu, NULL);

	//Write style LV_BTN_PART_MAIN for setting_menu_btn_ad_setting
	static lv_style_t style_setting_menu_btn_ad_setting_main;
	lv_style_reset(&style_setting_menu_btn_ad_setting_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_menu_btn_ad_setting_main
	lv_style_set_radius(&style_setting_menu_btn_ad_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_menu_btn_ad_setting_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_menu_btn_ad_setting_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_menu_btn_ad_setting_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_menu_btn_ad_setting_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_menu_btn_ad_setting_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_setting_menu_btn_ad_setting_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_menu_btn_ad_setting_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_menu_btn_ad_setting_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_menu_btn_ad_setting_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_setting_menu_btn_ad_setting_main
	lv_style_set_radius(&style_setting_menu_btn_ad_setting_main, LV_STATE_PRESSED, 6);
	lv_style_set_bg_color(&style_setting_menu_btn_ad_setting_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_color(&style_setting_menu_btn_ad_setting_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_dir(&style_setting_menu_btn_ad_setting_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_menu_btn_ad_setting_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_setting_menu_btn_ad_setting_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_setting_menu_btn_ad_setting_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_setting_menu_btn_ad_setting_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_setting_menu_btn_ad_setting_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_menu_btn_ad_setting_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->setting_menu_btn_ad_setting, LV_BTN_PART_MAIN, &style_setting_menu_btn_ad_setting_main);
	lv_obj_set_pos(ui->setting_menu_btn_ad_setting, 160, 0);
	lv_obj_set_size(ui->setting_menu_btn_ad_setting, 158, 104);
//	ui->setting_menu_btn_ad_setting_label = lv_label_create(ui->setting_menu_btn_ad_setting, NULL);
//	lv_label_set_text(ui->setting_menu_btn_ad_setting_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_menu_btn_ad_setting_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes setting_menu_btn_device
	ui->setting_menu_btn_device = lv_btn_create(ui->setting_menu_cont_seting_menu, NULL);

	//Write style LV_BTN_PART_MAIN for setting_menu_btn_device
	static lv_style_t style_setting_menu_btn_device_main;
	lv_style_reset(&style_setting_menu_btn_device_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_menu_btn_device_main
	lv_style_set_radius(&style_setting_menu_btn_device_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_menu_btn_device_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_menu_btn_device_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_menu_btn_device_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_menu_btn_device_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_menu_btn_device_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_setting_menu_btn_device_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_menu_btn_device_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_setting_menu_btn_device_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_menu_btn_device_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_setting_menu_btn_device_main
	lv_style_set_radius(&style_setting_menu_btn_device_main, LV_STATE_PRESSED, 6);
	lv_style_set_bg_color(&style_setting_menu_btn_device_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_color(&style_setting_menu_btn_device_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_dir(&style_setting_menu_btn_device_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_menu_btn_device_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_setting_menu_btn_device_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_setting_menu_btn_device_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_setting_menu_btn_device_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_setting_menu_btn_device_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_setting_menu_btn_device_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->setting_menu_btn_device, LV_BTN_PART_MAIN, &style_setting_menu_btn_device_main);
	lv_obj_set_pos(ui->setting_menu_btn_device, 0, 0);
	lv_obj_set_size(ui->setting_menu_btn_device, 158, 104);
//	ui->setting_menu_btn_device_label = lv_label_create(ui->setting_menu_btn_device, NULL);
//	lv_label_set_text(ui->setting_menu_btn_device_label, "");
//	lv_obj_set_style_local_text_color(ui->setting_menu_btn_device_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes setting_menu_label_about
	ui->setting_menu_label_about = lv_label_create(ui->setting_menu_cont_seting_menu, NULL);
	lv_label_set_long_mode(ui->setting_menu_label_about, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_menu_label_about, about[cur_language]);
	lv_label_set_align(ui->setting_menu_label_about, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for setting_menu_label_about
	static lv_style_t style_setting_menu_label_about_main;
	lv_style_reset(&style_setting_menu_label_about_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_menu_label_about_main
	lv_style_set_radius(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_menu_label_about_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_menu_label_about, LV_LABEL_PART_MAIN, &style_setting_menu_label_about_main);
	lv_obj_set_pos(ui->setting_menu_label_about, 325, 38);
	lv_obj_set_size(ui->setting_menu_label_about, 150, 42);

	//Write codes setting_menu_label_ad_setting
	ui->setting_menu_label_ad_setting = lv_label_create(ui->setting_menu_cont_seting_menu, NULL);
	lv_label_set_long_mode(ui->setting_menu_label_ad_setting, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_menu_label_ad_setting, adv_setting[cur_language]);
	lv_label_set_align(ui->setting_menu_label_ad_setting, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for setting_menu_label_ad_setting
	static lv_style_t style_setting_menu_label_ad_setting_main;
	lv_style_reset(&style_setting_menu_label_ad_setting_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_menu_label_ad_setting_main
	lv_style_set_radius(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
	else
    {
        lv_style_set_text_font(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_menu_label_ad_setting_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_menu_label_ad_setting, LV_LABEL_PART_MAIN, &style_setting_menu_label_ad_setting_main);
	lv_obj_set_pos(ui->setting_menu_label_ad_setting, 165, 38);
	lv_obj_set_size(ui->setting_menu_label_ad_setting, 150, 42);

	//Write codes setting_menu_label_device
	ui->setting_menu_label_device = lv_label_create(ui->setting_menu_cont_seting_menu, NULL);
	lv_label_set_long_mode(ui->setting_menu_label_device, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_menu_label_device,device[cur_language]);
	lv_label_set_align(ui->setting_menu_label_device, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for setting_menu_label_device
	static lv_style_t style_setting_menu_label_device_main;
	lv_style_reset(&style_setting_menu_label_device_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_menu_label_device_main
	lv_style_set_radius(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
	else
    {
        lv_style_set_text_font(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_menu_label_device_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_menu_label_device, LV_LABEL_PART_MAIN, &style_setting_menu_label_device_main);
	lv_obj_set_pos(ui->setting_menu_label_device, 5, 38);
	lv_obj_set_size(ui->setting_menu_label_device, 150, 42);
	lv_cont_set_layout(ui->setting_menu_cont_seting_menu, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->setting_menu_cont_seting_menu, LV_FIT_NONE);

	//Init events for screen
	events_init_setting_menu(ui);
}
