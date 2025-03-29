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


void setup_scr_menu(lv_ui *ui){

	//Write codes menu
//	ui->home = lv_obj_create(NULL, NULL);

	//Write codes menu_cont_menu
	if(ui->menu_cont_menu != NULL)
    {
        lv_obj_move_foreground(ui->menu_cont_menu);
        return;
    }
	ui->menu_cont_menu = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for menu_cont_menu
	static lv_style_t style_menu_cont_menu_main;
	lv_style_reset(&style_menu_cont_menu_main);
	lv_style_init(&style_menu_cont_menu_main);

	//Write style state: LV_STATE_DEFAULT for style_menu_cont_menu_main
	lv_style_set_radius(&style_menu_cont_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_menu_cont_menu_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_menu_cont_menu_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_menu_cont_menu_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_cont_menu_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_menu_cont_menu_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_menu_cont_menu_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_menu_cont_menu_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_menu_cont_menu_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_menu_cont_menu_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_menu_cont_menu_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_menu_cont_menu_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->menu_cont_menu, LV_CONT_PART_MAIN, &style_menu_cont_menu_main);
	lv_obj_set_pos(ui->menu_cont_menu, 0, 0);
	lv_obj_set_size(ui->menu_cont_menu, 480, 800);
	lv_obj_set_click(ui->menu_cont_menu, false);

	//Write codes menu_btn_home
	ui->menu_btn_home = lv_btn_create(ui->menu_cont_menu, NULL);

	//Write style LV_BTN_PART_MAIN for menu_btn_home
	static lv_style_t style_menu_btn_home_main;
	lv_style_reset(&style_menu_btn_home_main);
	lv_style_init(&style_menu_btn_home_main);

	//Write style state: LV_STATE_DEFAULT for style_menu_btn_home_main
	lv_style_set_radius(&style_menu_btn_home_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_menu_btn_home_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_menu_btn_home_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_menu_btn_home_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_btn_home_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_menu_btn_home_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_menu_btn_home_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_menu_btn_home_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_menu_btn_home_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_outline_opa(&style_menu_btn_home_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_menu_btn_home_main
	lv_style_set_radius(&style_menu_btn_home_main, LV_STATE_PRESSED, 0);
	lv_style_set_bg_color(&style_menu_btn_home_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_color(&style_menu_btn_home_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_dir(&style_menu_btn_home_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_btn_home_main, LV_STATE_PRESSED, 255);
//	lv_style_set_border_color(&style_menu_btn_home_main, LV_STATE_PRESSED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_menu_btn_home_main, LV_STATE_PRESSED, 0);
//	lv_style_set_border_opa(&style_menu_btn_home_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_menu_btn_home_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_menu_btn_home_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->menu_btn_home, LV_BTN_PART_MAIN, &style_menu_btn_home_main);
	lv_obj_set_pos(ui->menu_btn_home, 0, 674);
	lv_obj_set_size(ui->menu_btn_home, 119, 126);
//	ui->menu_btn_home_label = lv_label_create(ui->menu_btn_home, NULL);
//	lv_label_set_text(ui->menu_btn_home_label, "");
//	lv_obj_set_style_local_text_color(ui->menu_btn_home_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes menu_btn_print
	ui->menu_btn_print = lv_btn_create(ui->menu_cont_menu, NULL);

	//Write style LV_BTN_PART_MAIN for menu_btn_print
	static lv_style_t style_menu_btn_print_main;
	lv_style_reset(&style_menu_btn_print_main);
	lv_style_init(&style_menu_btn_print_main);

	//Write style state: LV_STATE_DEFAULT for style_menu_btn_print_main
	lv_style_set_radius(&style_menu_btn_print_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_menu_btn_print_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_menu_btn_print_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_menu_btn_print_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_btn_print_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_menu_btn_print_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_menu_btn_print_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_menu_btn_print_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_menu_btn_print_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_outline_opa(&style_menu_btn_print_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_menu_btn_print_main
	lv_style_set_radius(&style_menu_btn_print_main, LV_STATE_PRESSED, 0);
	lv_style_set_bg_color(&style_menu_btn_print_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_color(&style_menu_btn_print_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_dir(&style_menu_btn_print_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_btn_print_main, LV_STATE_PRESSED, 255);
//	lv_style_set_border_color(&style_menu_btn_print_main, LV_STATE_PRESSED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_menu_btn_print_main, LV_STATE_PRESSED, 0);
//	lv_style_set_border_opa(&style_menu_btn_print_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_menu_btn_print_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_menu_btn_print_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->menu_btn_print, LV_BTN_PART_MAIN, &style_menu_btn_print_main);
	lv_obj_set_pos(ui->menu_btn_print, 120, 674);
	lv_obj_set_size(ui->menu_btn_print, 119, 126);
//	ui->menu_btn_print_label = lv_label_create(ui->menu_btn_print, NULL);
//	lv_label_set_text(ui->menu_btn_print_label, "");
//	lv_obj_set_style_local_text_color(ui->menu_btn_print_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes menu_btn_prepare
	ui->menu_btn_prepare = lv_btn_create(ui->menu_cont_menu, NULL);

	//Write style LV_BTN_PART_MAIN for menu_btn_prepare
	static lv_style_t style_menu_btn_prepare_main;
	lv_style_reset(&style_menu_btn_prepare_main);
	lv_style_init(&style_menu_btn_prepare_main);

	//Write style state: LV_STATE_DEFAULT for style_menu_btn_prepare_main
	lv_style_set_radius(&style_menu_btn_prepare_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_menu_btn_prepare_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_menu_btn_prepare_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_menu_btn_prepare_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_btn_prepare_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_menu_btn_prepare_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_menu_btn_prepare_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_menu_btn_prepare_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_menu_btn_prepare_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_outline_opa(&style_menu_btn_prepare_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_menu_btn_prepare_main
	lv_style_set_radius(&style_menu_btn_prepare_main, LV_STATE_PRESSED, 0);
	lv_style_set_bg_color(&style_menu_btn_prepare_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_color(&style_menu_btn_prepare_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_dir(&style_menu_btn_prepare_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_btn_prepare_main, LV_STATE_PRESSED, 255);
//	lv_style_set_border_color(&style_menu_btn_prepare_main, LV_STATE_PRESSED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_menu_btn_prepare_main, LV_STATE_PRESSED, 0);
//	lv_style_set_border_opa(&style_menu_btn_prepare_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_menu_btn_prepare_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_menu_btn_prepare_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->menu_btn_prepare, LV_BTN_PART_MAIN, &style_menu_btn_prepare_main);
	lv_obj_set_pos(ui->menu_btn_prepare, 240, 674);
	lv_obj_set_size(ui->menu_btn_prepare, 119, 126);
//	ui->menu_btn_prepare_label = lv_label_create(ui->menu_btn_prepare, NULL);
//	lv_label_set_text(ui->menu_btn_prepare_label, "");
//	lv_obj_set_style_local_text_color(ui->menu_btn_prepare_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes menu_btn_setting
	ui->menu_btn_setting = lv_btn_create(ui->menu_cont_menu, NULL);

	//Write style LV_BTN_PART_MAIN for menu_btn_setting
	static lv_style_t style_menu_btn_setting_main;
	lv_style_reset(&style_menu_btn_setting_main);
	lv_style_init(&style_menu_btn_setting_main);

	//Write style state: LV_STATE_DEFAULT for style_menu_btn_setting_main
	lv_style_set_radius(&style_menu_btn_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_menu_btn_setting_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_menu_btn_setting_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_menu_btn_setting_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_btn_setting_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_menu_btn_setting_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_menu_btn_setting_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_menu_btn_setting_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_menu_btn_setting_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_outline_opa(&style_menu_btn_setting_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_menu_btn_setting_main
	lv_style_set_radius(&style_menu_btn_setting_main, LV_STATE_PRESSED, 0);
	lv_style_set_bg_color(&style_menu_btn_setting_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_color(&style_menu_btn_setting_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_dir(&style_menu_btn_setting_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_btn_setting_main, LV_STATE_PRESSED, 255);
//	lv_style_set_border_color(&style_menu_btn_setting_main, LV_STATE_PRESSED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_menu_btn_setting_main, LV_STATE_PRESSED, 0);
//	lv_style_set_border_opa(&style_menu_btn_setting_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_menu_btn_setting_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_menu_btn_setting_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->menu_btn_setting, LV_BTN_PART_MAIN, &style_menu_btn_setting_main);
	lv_obj_set_pos(ui->menu_btn_setting, 360, 674);
	lv_obj_set_size(ui->menu_btn_setting, 120, 126);
//	ui->menu_btn_setting_label = lv_label_create(ui->menu_btn_setting, NULL);
//	lv_label_set_text(ui->menu_btn_setting_label, "");
//	lv_obj_set_style_local_text_color(ui->menu_btn_setting_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes menu_img_home
	ui->menu_img_home = lv_img_create(ui->menu_cont_menu, NULL);

	//Write style LV_IMG_PART_MAIN for menu_img_home
//	static lv_style_t style_menu_img_home_main;
//	lv_style_reset(&style_menu_img_home_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_menu_img_home_main
//	lv_style_set_image_recolor(&style_menu_img_home_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_menu_img_home_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_menu_img_home_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->menu_img_home, LV_IMG_PART_MAIN, &style_menu_img_home_main);
	lv_obj_set_pos(ui->menu_img_home, 37, 695);
//	lv_obj_set_size(ui->menu_img_home, 49, 47);
//	lv_obj_set_click(ui->menu_img_home, true);
	lv_img_set_src(ui->menu_img_home,&_home_alpha_49x47);
//	lv_img_set_pivot(ui->menu_img_home, 0,0);
//	lv_img_set_angle(ui->menu_img_home, 0);

	//Write codes menu_img_print
	ui->menu_img_print = lv_img_create(ui->menu_cont_menu, NULL);

	//Write style LV_IMG_PART_MAIN for menu_img_print
//	static lv_style_t style_menu_img_print_main;
//	lv_style_reset(&style_menu_img_print_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_menu_img_print_main
//	lv_style_set_image_recolor(&style_menu_img_print_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_menu_img_print_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_menu_img_print_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->menu_img_print, LV_IMG_PART_MAIN, &style_menu_img_print_main);
	lv_obj_set_pos(ui->menu_img_print, 154, 695);
//	lv_obj_set_size(ui->menu_img_print, 52, 52);
//	lv_obj_set_click(ui->menu_img_print, true);
	lv_img_set_src(ui->menu_img_print,&_print_alpha_52x52);
//	lv_img_set_pivot(ui->menu_img_print, 0,0);
//	lv_img_set_angle(ui->menu_img_print, 0);

	//Write codes menu_img_prepare
	ui->menu_img_prepare = lv_img_create(ui->menu_cont_menu, NULL);

	//Write style LV_IMG_PART_MAIN for menu_img_prepare
//	static lv_style_t style_menu_img_prepare_main;
//	lv_style_reset(&style_menu_img_prepare_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_menu_img_prepare_main
//	lv_style_set_image_recolor(&style_menu_img_prepare_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_menu_img_prepare_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_menu_img_prepare_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->menu_img_prepare, LV_IMG_PART_MAIN, &style_menu_img_prepare_main);
	lv_obj_set_pos(ui->menu_img_prepare, 274, 695);
//	lv_obj_set_size(ui->menu_img_prepare, 52, 52);
//	lv_obj_set_click(ui->menu_img_prepare, true);
	lv_img_set_src(ui->menu_img_prepare,&_prepare_alpha_52x52);
//	lv_img_set_pivot(ui->menu_img_prepare, 0,0);
//	lv_img_set_angle(ui->menu_img_prepare, 0);

	//Write codes menu_img_setting
	ui->menu_img_setting = lv_img_create(ui->menu_cont_menu, NULL);

	//Write style LV_IMG_PART_MAIN for menu_img_setting
//	static lv_style_t style_menu_img_setting_main;
//	lv_style_reset(&style_menu_img_setting_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_menu_img_setting_main
//	lv_style_set_image_recolor(&style_menu_img_setting_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_menu_img_setting_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_menu_img_setting_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->menu_img_setting, LV_IMG_PART_MAIN, &style_menu_img_setting_main);
	lv_obj_set_pos(ui->menu_img_setting, 394, 695);
//	lv_obj_set_size(ui->menu_img_setting, 52, 52);
//	lv_obj_set_click(ui->menu_img_setting, true);
	lv_img_set_src(ui->menu_img_setting,&_setting_alpha_52x52);
//	lv_img_set_pivot(ui->menu_img_setting, 0,0);
//	lv_img_set_angle(ui->menu_img_setting, 0);

	//Write codes menu_label_mainpage
	ui->menu_label_mainpage = lv_label_create(ui->menu_cont_menu, NULL);
	lv_label_set_text(ui->menu_label_mainpage, home[cur_language]);
	lv_label_set_long_mode(ui->menu_label_mainpage, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->menu_label_mainpage, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for menu_label_mainpage
	static lv_style_t style_menu_label_mainpage_main;
	lv_style_reset(&style_menu_label_mainpage_main);
	lv_style_init(&style_menu_label_mainpage_main);

	//Write style state: LV_STATE_DEFAULT for style_menu_label_mainpage_main
	lv_style_set_radius(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_menu_label_mainpage_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->menu_label_mainpage, LV_LABEL_PART_MAIN, &style_menu_label_mainpage_main);
	lv_obj_set_pos(ui->menu_label_mainpage, 0, 760);
	lv_obj_set_size(ui->menu_label_mainpage, 120, 0);

	//Write codes menu_label_print
	ui->menu_label_print = lv_label_create(ui->menu_cont_menu, NULL);
	lv_label_set_text(ui->menu_label_print,  print[cur_language]);
	lv_label_set_long_mode(ui->menu_label_print, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->menu_label_print, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for menu_label_print
	static lv_style_t style_menu_label_print_main;
	lv_style_reset(&style_menu_label_print_main);
	lv_style_init(&style_menu_label_print_main);

	//Write style state: LV_STATE_DEFAULT for style_menu_label_print_main
	lv_style_set_radius(&style_menu_label_print_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_menu_label_print_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_menu_label_print_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_menu_label_print_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_label_print_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_menu_label_print_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_menu_label_print_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_menu_label_print_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_menu_label_print_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_menu_label_print_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_menu_label_print_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_menu_label_print_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_menu_label_print_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->menu_label_print, LV_LABEL_PART_MAIN, &style_menu_label_print_main);
	lv_obj_set_pos(ui->menu_label_print, 120, 760);
	lv_obj_set_size(ui->menu_label_print, 120, 0);

	//Write codes menu_label_prepare
	ui->menu_label_prepare = lv_label_create(ui->menu_cont_menu, NULL);
	lv_label_set_text(ui->menu_label_prepare, prepare[cur_language]);
	lv_label_set_long_mode(ui->menu_label_prepare, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->menu_label_prepare, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for menu_label_prepare
	static lv_style_t style_menu_label_prepare_main;
	lv_style_reset(&style_menu_label_prepare_main);
	lv_style_init(&style_menu_label_prepare_main);

	//Write style state: LV_STATE_DEFAULT for style_menu_label_prepare_main
	lv_style_set_radius(&style_menu_label_prepare_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_menu_label_prepare_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_menu_label_prepare_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_menu_label_prepare_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_label_prepare_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_menu_label_prepare_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_menu_label_prepare_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_menu_label_prepare_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_menu_label_prepare_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_menu_label_prepare_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_menu_label_prepare_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_menu_label_prepare_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_menu_label_prepare_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->menu_label_prepare, LV_LABEL_PART_MAIN, &style_menu_label_prepare_main);
	lv_obj_set_pos(ui->menu_label_prepare, 240, 760);
	lv_obj_set_size(ui->menu_label_prepare, 120, 0);

	//Write codes menu_label_setting
	ui->menu_label_setting = lv_label_create(ui->menu_cont_menu, NULL);
	lv_label_set_text(ui->menu_label_setting, setting[cur_language]);
	lv_label_set_long_mode(ui->menu_label_setting, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->menu_label_setting, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for menu_label_setting
	static lv_style_t style_menu_label_setting_main;
	lv_style_reset(&style_menu_label_setting_main);
	lv_style_init(&style_menu_label_setting_main);

	//Write style state: LV_STATE_DEFAULT for style_menu_label_setting_main
	lv_style_set_radius(&style_menu_label_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_menu_label_setting_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_menu_label_setting_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_menu_label_setting_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_menu_label_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_menu_label_setting_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_menu_label_setting_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_menu_label_setting_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_menu_label_setting_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_menu_label_setting_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_menu_label_setting_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_menu_label_setting_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_menu_label_setting_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->menu_label_setting, LV_LABEL_PART_MAIN, &style_menu_label_setting_main);
	lv_obj_set_pos(ui->menu_label_setting, 360, 760);
	lv_obj_set_size(ui->menu_label_setting, 120, 0);
	lv_cont_set_layout(ui->menu_cont_menu, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->menu_cont_menu, LV_FIT_NONE);

	//Init events for screen
	events_init_menu(ui);
}
