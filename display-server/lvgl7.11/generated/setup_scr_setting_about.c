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

void setup_scr_setting_about(lv_ui *ui){

	//Write codes setting_about
//	ui->setting_about = lv_obj_create(NULL, NULL);

	if(ui->setting_about_cont_setting_about != NULL)
    {
        return;
    }
	//Write codes setting_about_cont_setting_about
	ui->setting_about_cont_setting_about = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for setting_about_cont_setting_about
	static lv_style_t style_setting_about_cont_setting_about_main;
	lv_style_reset(&style_setting_about_cont_setting_about_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_cont_setting_about_main
	lv_style_set_radius(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_cont_setting_about_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_cont_setting_about, LV_CONT_PART_MAIN, &style_setting_about_cont_setting_about_main);
	lv_obj_set_pos(ui->setting_about_cont_setting_about, 0, 0);
	lv_obj_set_size(ui->setting_about_cont_setting_about, 480, 674);
	lv_obj_set_click(ui->setting_about_cont_setting_about, false);

	//Write codes setting_about_label_screen_ver
	ui->setting_about_label_screen_ver = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_text(ui->setting_about_label_screen_ver, "default");
	lv_label_set_long_mode(ui->setting_about_label_screen_ver, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_screen_ver, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_screen_ver
	static lv_style_t style_setting_about_label_screen_ver_main;
	lv_style_reset(&style_setting_about_label_screen_ver_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_screen_ver_main
	lv_style_set_radius(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_screen_ver_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_screen_ver, LV_LABEL_PART_MAIN, &style_setting_about_label_screen_ver_main);
	lv_obj_set_pos(ui->setting_about_label_screen_ver, 280, 315);
	lv_obj_set_size(ui->setting_about_label_screen_ver, 180, 0);

	//Write codes setting_about_label_official_web
	ui->setting_about_label_official_web = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_text(ui->setting_about_label_official_web, "default");
	lv_label_set_long_mode(ui->setting_about_label_official_web, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_official_web, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_official_web
	static lv_style_t style_setting_about_label_official_web_main;
	lv_style_reset(&style_setting_about_label_official_web_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_official_web_main
	lv_style_set_radius(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_official_web_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_official_web, LV_LABEL_PART_MAIN, &style_setting_about_label_official_web_main);
	lv_obj_set_pos(ui->setting_about_label_official_web, 280, 585);
	lv_obj_set_size(ui->setting_about_label_official_web, 180, 0);

	//Write codes setting_about_label_print_size
	ui->setting_about_label_print_size = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_text(ui->setting_about_label_print_size, "default");
	lv_label_set_long_mode(ui->setting_about_label_print_size, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_print_size, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_print_size
	static lv_style_t style_setting_about_label_print_size_main;
	lv_style_reset(&style_setting_about_label_print_size_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_print_size_main
	lv_style_set_radius(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_print_size_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_print_size, LV_LABEL_PART_MAIN, &style_setting_about_label_print_size_main);
	lv_obj_set_pos(ui->setting_about_label_print_size, 280, 495);
	lv_obj_set_size(ui->setting_about_label_print_size, 180, 0);

	//Write codes setting_about_label_hardware_ver
	ui->setting_about_label_hardware_ver = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_text(ui->setting_about_label_hardware_ver, "default");
	lv_label_set_long_mode(ui->setting_about_label_hardware_ver, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_hardware_ver, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_hardware_ver
	static lv_style_t style_setting_about_label_hardware_ver_main;
	lv_style_reset(&style_setting_about_label_hardware_ver_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_hardware_ver_main
	lv_style_set_radius(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_hardware_ver_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_hardware_ver, LV_LABEL_PART_MAIN, &style_setting_about_label_hardware_ver_main);
	lv_obj_set_pos(ui->setting_about_label_hardware_ver, 280, 405);
	lv_obj_set_size(ui->setting_about_label_hardware_ver, 180, 0);

	//Write codes setting_about_label_29
	ui->setting_about_label_29 = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_long_mode(ui->setting_about_label_29, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_about_label_29, company_web[cur_language]);
//	lv_label_set_long_mode(ui->setting_about_label_29, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_29, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_29
	static lv_style_t style_setting_about_label_29_main;
	lv_style_reset(&style_setting_about_label_29_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_29_main
	lv_style_set_radius(&style_setting_about_label_29_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_29_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_setting_about_label_29_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_setting_about_label_29_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_29_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_29_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_about_label_29_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_about_label_29_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_about_label_29_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_29_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_29_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_29_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_29_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_29, LV_LABEL_PART_MAIN, &style_setting_about_label_29_main);
	lv_obj_set_pos(ui->setting_about_label_29, 20, 585);
	lv_obj_set_size(ui->setting_about_label_29, 250, 42);

	//Write codes setting_about_label_28
	ui->setting_about_label_28 = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_long_mode(ui->setting_about_label_28, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_about_label_28, print_size[cur_language]);
//	lv_label_set_long_mode(ui->setting_about_label_28, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_28, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_28
	static lv_style_t style_setting_about_label_28_main;
	lv_style_reset(&style_setting_about_label_28_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_28_main
	lv_style_set_radius(&style_setting_about_label_28_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_28_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_setting_about_label_28_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_setting_about_label_28_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_28_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_28_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_about_label_28_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_about_label_28_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_about_label_28_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_28_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_28_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_28_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_28_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_28, LV_LABEL_PART_MAIN, &style_setting_about_label_28_main);
	lv_obj_set_pos(ui->setting_about_label_28, 20, 495);
	lv_obj_set_size(ui->setting_about_label_28, 250, 42);

	//Write codes setting_about_label_27
	ui->setting_about_label_27 = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_long_mode(ui->setting_about_label_27, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_about_label_27, hardware_ver[cur_language]);
//	lv_label_set_long_mode(ui->setting_about_label_27, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_27, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_27
	static lv_style_t style_setting_about_label_27_main;
	lv_style_reset(&style_setting_about_label_27_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_27_main
	lv_style_set_radius(&style_setting_about_label_27_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_27_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_setting_about_label_27_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_setting_about_label_27_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_27_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_27_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_about_label_27_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_about_label_27_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_about_label_27_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_27_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_27_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_27_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_27_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_27, LV_LABEL_PART_MAIN, &style_setting_about_label_27_main);
	lv_obj_set_pos(ui->setting_about_label_27, 20, 405);
	lv_obj_set_size(ui->setting_about_label_27, 250, 42);

	//Write codes setting_about_label_26
	ui->setting_about_label_26 = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_long_mode(ui->setting_about_label_26, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_about_label_26, screen_ver[cur_language]);
//	lv_label_set_long_mode(ui->setting_about_label_26, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_26, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_26
	static lv_style_t style_setting_about_label_26_main;
	lv_style_reset(&style_setting_about_label_26_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_26_main
	lv_style_set_radius(&style_setting_about_label_26_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_26_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_setting_about_label_26_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_setting_about_label_26_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_26_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_26_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_about_label_26_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_about_label_26_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_about_label_26_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_26_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_26_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_26_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_26_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_26, LV_LABEL_PART_MAIN, &style_setting_about_label_26_main);
	lv_obj_set_pos(ui->setting_about_label_26, 20, 315);
	lv_obj_set_size(ui->setting_about_label_26, 250, 42);

	//Write codes setting_about_label_machine_type
	ui->setting_about_label_machine_type = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_text(ui->setting_about_label_machine_type, "default");
	lv_label_set_long_mode(ui->setting_about_label_machine_type, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_machine_type, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_machine_type
	static lv_style_t style_setting_about_label_machine_type_main;
	lv_style_reset(&style_setting_about_label_machine_type_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_machine_type_main
	lv_style_set_radius(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_machine_type_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_machine_type, LV_LABEL_PART_MAIN, &style_setting_about_label_machine_type_main);
	lv_obj_set_pos(ui->setting_about_label_machine_type, 280, 135);
	lv_obj_set_size(ui->setting_about_label_machine_type, 180, 0);

	//Write codes setting_about_label_fireware_ver
	ui->setting_about_label_fireware_ver = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_text(ui->setting_about_label_fireware_ver, "default");
	lv_label_set_long_mode(ui->setting_about_label_fireware_ver, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_fireware_ver, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_fireware_ver
	static lv_style_t style_setting_about_label_fireware_ver_main;
	lv_style_reset(&style_setting_about_label_fireware_ver_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_fireware_ver_main
	lv_style_set_radius(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_fireware_ver_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_fireware_ver, LV_LABEL_PART_MAIN, &style_setting_about_label_fireware_ver_main);
	lv_obj_set_pos(ui->setting_about_label_fireware_ver, 280, 225);
	lv_obj_set_size(ui->setting_about_label_fireware_ver, 180, 0);

	//Write codes setting_about_label_22
	ui->setting_about_label_22 = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_long_mode(ui->setting_about_label_22, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_about_label_22, machine_type[cur_language]);
//	lv_label_set_long_mode(ui->setting_about_label_22, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_22, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_22
	static lv_style_t style_setting_about_label_22_main;
	lv_style_reset(&style_setting_about_label_22_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_22_main
	lv_style_set_radius(&style_setting_about_label_22_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_22_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_setting_about_label_22_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_setting_about_label_22_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_22_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_22_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_about_label_22_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_about_label_22_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_about_label_22_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_22_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_22, LV_LABEL_PART_MAIN, &style_setting_about_label_22_main);
	lv_obj_set_pos(ui->setting_about_label_22, 20, 135);
	lv_obj_set_size(ui->setting_about_label_22, 250, 42);

	//Write codes setting_about_label_24
	ui->setting_about_label_24 = lv_label_create(ui->setting_about_cont_setting_about, NULL);
	lv_label_set_long_mode(ui->setting_about_label_24, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->setting_about_label_24, fireware_ver[cur_language]);
//	lv_label_set_long_mode(ui->setting_about_label_24, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->setting_about_label_24, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for setting_about_label_24
	static lv_style_t style_setting_about_label_24_main;
	lv_style_reset(&style_setting_about_label_24_main);

	//Write style state: LV_STATE_DEFAULT for style_setting_about_label_24_main
	lv_style_set_radius(&style_setting_about_label_24_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_setting_about_label_24_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_setting_about_label_24_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_setting_about_label_24_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_setting_about_label_24_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_setting_about_label_24_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_setting_about_label_24_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_setting_about_label_24_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_setting_about_label_24_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_setting_about_label_24_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_setting_about_label_24_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_setting_about_label_24_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_setting_about_label_24_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->setting_about_label_24, LV_LABEL_PART_MAIN, &style_setting_about_label_24_main);
	lv_obj_set_pos(ui->setting_about_label_24, 20, 225);
	lv_obj_set_size(ui->setting_about_label_24, 250, 42);
	lv_cont_set_layout(ui->setting_about_cont_setting_about, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->setting_about_cont_setting_about, LV_FIT_NONE);
}
