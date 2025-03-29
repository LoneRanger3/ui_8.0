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

void setup_scr_Language(lv_ui *ui){

	//Write codes Language
//	ui->Language = lv_obj_create(NULL, NULL);

	//Write codes Language_cont_language
	ui->Language_cont_language = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for Language_cont_language
	static lv_style_t style_Language_cont_language_main;
	lv_style_reset(&style_Language_cont_language_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_cont_language_main
	lv_style_set_radius(&style_Language_cont_language_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Language_cont_language_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_Language_cont_language_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_Language_cont_language_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_cont_language_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Language_cont_language_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_Language_cont_language_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Language_cont_language_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_Language_cont_language_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Language_cont_language_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Language_cont_language_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Language_cont_language_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Language_cont_language, LV_CONT_PART_MAIN, &style_Language_cont_language_main);
	lv_obj_set_pos(ui->Language_cont_language, 0, 0);
	lv_obj_set_size(ui->Language_cont_language, 480, 800);
	lv_obj_set_click(ui->Language_cont_language, false);

	//Write codes Language_btn_china
	ui->Language_btn_china = lv_btn_create(ui->Language_cont_language, NULL);

	//Write style LV_BTN_PART_MAIN for Language_btn_china
	static lv_style_t style_Language_btn_china_main;
	lv_style_reset(&style_Language_btn_china_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_btn_china_main
	lv_style_set_radius(&style_Language_btn_china_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Language_btn_china_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Language_btn_china_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Language_btn_china_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_china_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Language_btn_china_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Language_btn_china_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Language_btn_china_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Language_btn_china_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Language_btn_china_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Language_btn_china_main
	lv_style_set_radius(&style_Language_btn_china_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Language_btn_china_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Language_btn_china_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x40, 0x42));
	//lv_style_set_bg_grad_dir(&style_Language_btn_china_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_china_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Language_btn_china_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Language_btn_china_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_Language_btn_china_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Language_btn_china_main, LV_STATE_PRESSED, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_Language_btn_china_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Language_btn_china, LV_BTN_PART_MAIN, &style_Language_btn_china_main);
	lv_obj_set_pos(ui->Language_btn_china, 20, 105);
	lv_obj_set_size(ui->Language_btn_china, 210, 115);
//	ui->Language_btn_china_label = lv_label_create(ui->Language_btn_china, NULL);
//	lv_label_set_text(ui->Language_btn_china_label, "");
//	lv_obj_set_style_local_text_color(ui->Language_btn_china_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes Language_img_2
	ui->Language_img_2 = lv_img_create(ui->Language_cont_language, NULL);

	//Write style LV_IMG_PART_MAIN for Language_img_2
//	static lv_style_t style_Language_img_2_main;
//	lv_style_reset(&style_Language_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Language_img_2_main
//	lv_style_set_image_recolor(&style_Language_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Language_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Language_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Language_img_2, LV_IMG_PART_MAIN, &style_Language_img_2_main);
	lv_obj_set_pos(ui->Language_img_2, 27, 145);
//	lv_obj_set_size(ui->Language_img_2, 48, 32);
//	lv_obj_set_click(ui->Language_img_2, true);
	lv_img_set_src(ui->Language_img_2,&_la1_alpha_48x32);
//	lv_img_set_pivot(ui->Language_img_2, 0,0);
//	lv_img_set_angle(ui->Language_img_2, 0);

	//Write codes Language_img_back
	ui->Language_img_back = lv_img_create(ui->Language_cont_language, NULL);

	//Write style LV_IMG_PART_MAIN for Language_img_back
//	static lv_style_t style_Language_img_back_main;
//	lv_style_reset(&style_Language_img_back_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Language_img_back_main
//	lv_style_set_image_recolor(&style_Language_img_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Language_img_back_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Language_img_back_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Language_img_back, LV_IMG_PART_MAIN, &style_Language_img_back_main);
	lv_obj_set_pos(ui->Language_img_back, 24, 30);
//	lv_obj_set_size(ui->Language_img_back, 45, 36);
	lv_obj_set_click(ui->Language_img_back, true);
	lv_img_set_src(ui->Language_img_back,&_return_alpha_45x36);
//	lv_img_set_pivot(ui->Language_img_back, 0,0);
//	lv_img_set_angle(ui->Language_img_back, 0);

	//Write codes Language_label_1
	ui->Language_label_1 = lv_label_create(ui->Language_cont_language, NULL);
	lv_label_set_text(ui->Language_label_1, language[cur_language]);
	lv_label_set_long_mode(ui->Language_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Language_label_1, LV_LABEL_ALIGN_RIGHT);

	//Write style LV_LABEL_PART_MAIN for Language_label_1
	static lv_style_t style_Language_label_1_main;
	lv_style_reset(&style_Language_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_label_1_main
	lv_style_set_radius(&style_Language_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Language_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Language_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Language_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Language_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(&style_Language_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Language_label_1_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Language_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Language_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Language_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Language_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Language_label_1, LV_LABEL_PART_MAIN, &style_Language_label_1_main);
	lv_obj_set_pos(ui->Language_label_1, 113, 32);
	lv_obj_set_size(ui->Language_label_1, 347, 0);

	//Write codes Language_btn_english
	ui->Language_btn_english = lv_btn_create(ui->Language_cont_language, NULL);

	//Write style LV_BTN_PART_MAIN for Language_btn_english
	static lv_style_t style_Language_btn_english_main;
	lv_style_reset(&style_Language_btn_english_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_btn_english_main
	lv_style_set_radius(&style_Language_btn_english_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Language_btn_english_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Language_btn_english_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Language_btn_english_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_english_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Language_btn_english_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Language_btn_english_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Language_btn_english_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Language_btn_english_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Language_btn_english_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Language_btn_english_main
	lv_style_set_radius(&style_Language_btn_english_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Language_btn_english_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Language_btn_english_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Language_btn_english_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_english_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Language_btn_english_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Language_btn_english_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_Language_btn_english_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Language_btn_english_main, LV_STATE_PRESSED, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_Language_btn_english_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Language_btn_english, LV_BTN_PART_MAIN, &style_Language_btn_english_main);
	lv_obj_set_pos(ui->Language_btn_english, 250, 105);
	lv_obj_set_size(ui->Language_btn_english, 210, 115);
//	ui->Language_btn_english_label = lv_label_create(ui->Language_btn_english, NULL);
//	lv_label_set_text(ui->Language_btn_english_label, "");
//	lv_obj_set_style_local_text_color(ui->Language_btn_english_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes Language_img_3
	ui->Language_img_3 = lv_img_create(ui->Language_cont_language, NULL);

	//Write style LV_IMG_PART_MAIN for Language_img_3
//	static lv_style_t style_Language_img_3_main;
//	lv_style_reset(&style_Language_img_3_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Language_img_3_main
//	lv_style_set_image_recolor(&style_Language_img_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Language_img_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Language_img_3_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Language_img_3, LV_IMG_PART_MAIN, &style_Language_img_3_main);
	lv_obj_set_pos(ui->Language_img_3, 257, 145);
//	lv_obj_set_size(ui->Language_img_3, 48, 32);
//	lv_obj_set_click(ui->Language_img_3, true);
	lv_img_set_src(ui->Language_img_3,&_la2_alpha_48x32);
//	lv_img_set_pivot(ui->Language_img_3, 0,0);
//	lv_img_set_angle(ui->Language_img_3, 0);

	//Write codes Language_label_2
	ui->Language_label_2 = lv_label_create(ui->Language_cont_language, NULL);
	lv_label_set_text(ui->Language_label_2, "English");
	lv_label_set_long_mode(ui->Language_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Language_label_2, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Language_label_2
	static lv_style_t style_Language_label_2_main;
	lv_style_reset(&style_Language_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_label_2_main
	lv_style_set_radius(&style_Language_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Language_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Language_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Language_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Language_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Language_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Language_label_2_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Language_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Language_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Language_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Language_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Language_label_2, LV_LABEL_PART_MAIN, &style_Language_label_2_main);
	lv_obj_set_pos(ui->Language_label_2, 317, 145);
	lv_obj_set_size(ui->Language_label_2, 120, 0);

	//Write codes Language_label_3
	ui->Language_label_3 = lv_label_create(ui->Language_cont_language, NULL);
	lv_label_set_text(ui->Language_label_3, "中文");
	lv_label_set_long_mode(ui->Language_label_3, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Language_label_3, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Language_label_3
	static lv_style_t style_Language_label_3_main;
	lv_style_reset(&style_Language_label_3_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_label_3_main
	lv_style_set_radius(&style_Language_label_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Language_label_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Language_label_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Language_label_3_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_label_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Language_label_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Language_label_3_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Language_label_3_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Language_label_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Language_label_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Language_label_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Language_label_3_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Language_label_3, LV_LABEL_PART_MAIN, &style_Language_label_3_main);
	lv_obj_set_pos(ui->Language_label_3, 87, 145);
	lv_obj_set_size(ui->Language_label_3, 120, 0);

	//Write codes Language_btn_deutsch
	ui->Language_btn_deutsch = lv_btn_create(ui->Language_cont_language, NULL);

	//Write style LV_BTN_PART_MAIN for Language_btn_deutsch
	static lv_style_t style_Language_btn_deutsch_main;
	lv_style_reset(&style_Language_btn_deutsch_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_btn_deutsch_main
	lv_style_set_radius(&style_Language_btn_deutsch_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Language_btn_deutsch_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Language_btn_deutsch_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Language_btn_deutsch_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_deutsch_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Language_btn_deutsch_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Language_btn_deutsch_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Language_btn_deutsch_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Language_btn_deutsch_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Language_btn_deutsch_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Language_btn_deutsch_main
	lv_style_set_radius(&style_Language_btn_deutsch_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Language_btn_deutsch_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Language_btn_deutsch_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Language_btn_deutsch_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_deutsch_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Language_btn_deutsch_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Language_btn_deutsch_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_Language_btn_deutsch_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Language_btn_deutsch_main, LV_STATE_PRESSED, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_Language_btn_deutsch_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Language_btn_deutsch, LV_BTN_PART_MAIN, &style_Language_btn_deutsch_main);
	lv_obj_set_pos(ui->Language_btn_deutsch, 20, 240);
	lv_obj_set_size(ui->Language_btn_deutsch, 210, 115);
//	ui->Language_btn_deutsch_label = lv_label_create(ui->Language_btn_deutsch, NULL);
//	lv_label_set_text(ui->Language_btn_deutsch_label, "");
//	lv_obj_set_style_local_text_color(ui->Language_btn_deutsch_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes Language_btn_espanol
	ui->Language_btn_espanol = lv_btn_create(ui->Language_cont_language, NULL);

	//Write style LV_BTN_PART_MAIN for Language_btn_espanol
	static lv_style_t style_Language_btn_espanol_main;
	lv_style_reset(&style_Language_btn_espanol_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_btn_espanol_main
	lv_style_set_radius(&style_Language_btn_espanol_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Language_btn_espanol_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Language_btn_espanol_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Language_btn_espanol_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_espanol_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Language_btn_espanol_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Language_btn_espanol_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Language_btn_espanol_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Language_btn_espanol_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Language_btn_espanol_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Language_btn_espanol_main
	lv_style_set_radius(&style_Language_btn_espanol_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Language_btn_espanol_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Language_btn_espanol_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Language_btn_espanol_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_espanol_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Language_btn_espanol_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Language_btn_espanol_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_Language_btn_espanol_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Language_btn_espanol_main, LV_STATE_PRESSED, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_Language_btn_espanol_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Language_btn_espanol, LV_BTN_PART_MAIN, &style_Language_btn_espanol_main);
	lv_obj_set_pos(ui->Language_btn_espanol, 250, 240);
	lv_obj_set_size(ui->Language_btn_espanol, 210, 115);
//	ui->Language_btn_espanol_label = lv_label_create(ui->Language_btn_espanol, NULL);
//	lv_label_set_text(ui->Language_btn_espanol_label, "");
//	lv_obj_set_style_local_text_color(ui->Language_btn_espanol_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes Language_label_13
	ui->Language_label_13 = lv_label_create(ui->Language_cont_language, NULL);
	lv_label_set_text(ui->Language_label_13, "Español");
	lv_label_set_long_mode(ui->Language_label_13, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Language_label_13, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Language_label_13
	static lv_style_t style_Language_label_13_main;
	lv_style_reset(&style_Language_label_13_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_label_13_main
	lv_style_set_radius(&style_Language_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Language_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Language_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Language_label_13_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Language_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Language_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Language_label_13_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Language_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Language_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Language_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Language_label_13_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Language_label_13, LV_LABEL_PART_MAIN, &style_Language_label_13_main);
	lv_obj_set_pos(ui->Language_label_13, 317, 280);
	lv_obj_set_size(ui->Language_label_13, 150, 0);

	//Write codes Language_btn_france
	ui->Language_btn_france = lv_btn_create(ui->Language_cont_language, NULL);

	//Write style LV_BTN_PART_MAIN for Language_btn_france
	static lv_style_t style_Language_btn_france_main;
	lv_style_reset(&style_Language_btn_france_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_btn_france_main
	lv_style_set_radius(&style_Language_btn_france_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Language_btn_france_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Language_btn_france_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Language_btn_france_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_france_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Language_btn_france_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Language_btn_france_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Language_btn_france_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Language_btn_france_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Language_btn_france_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Language_btn_france_main
	lv_style_set_radius(&style_Language_btn_france_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Language_btn_france_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Language_btn_france_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Language_btn_france_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_france_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Language_btn_france_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Language_btn_france_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_Language_btn_france_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Language_btn_france_main, LV_STATE_PRESSED, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_Language_btn_france_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Language_btn_france, LV_BTN_PART_MAIN, &style_Language_btn_france_main);
	lv_obj_set_pos(ui->Language_btn_france, 20, 375);
	lv_obj_set_size(ui->Language_btn_france, 210, 115);
//	ui->Language_btn_france_label = lv_label_create(ui->Language_btn_france, NULL);
//	lv_label_set_text(ui->Language_btn_france_label, "");
//	lv_obj_set_style_local_text_color(ui->Language_btn_france_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes Language_btn_italy
	ui->Language_btn_italy = lv_btn_create(ui->Language_cont_language, NULL);

	//Write style LV_BTN_PART_MAIN for Language_btn_italy
	static lv_style_t style_Language_btn_italy_main;
	lv_style_reset(&style_Language_btn_italy_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_btn_italy_main
	lv_style_set_radius(&style_Language_btn_italy_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Language_btn_italy_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Language_btn_italy_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Language_btn_italy_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_italy_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Language_btn_italy_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Language_btn_italy_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Language_btn_italy_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Language_btn_italy_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Language_btn_italy_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Language_btn_italy_main
	lv_style_set_radius(&style_Language_btn_italy_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Language_btn_italy_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Language_btn_italy_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Language_btn_italy_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_italy_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Language_btn_italy_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Language_btn_italy_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_Language_btn_italy_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Language_btn_italy_main, LV_STATE_PRESSED, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_Language_btn_italy_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Language_btn_italy, LV_BTN_PART_MAIN, &style_Language_btn_italy_main);
	lv_obj_set_pos(ui->Language_btn_italy, 250, 375);
	lv_obj_set_size(ui->Language_btn_italy, 210, 115);
//	ui->Language_btn_italy_label = lv_label_create(ui->Language_btn_italy, NULL);
//	lv_label_set_text(ui->Language_btn_italy_label, "");
//	lv_obj_set_style_local_text_color(ui->Language_btn_italy_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes Language_btn_portugues
	ui->Language_btn_portugues = lv_btn_create(ui->Language_cont_language, NULL);

	//Write style LV_BTN_PART_MAIN for Language_btn_portugues
	static lv_style_t style_Language_btn_portugues_main;
	lv_style_reset(&style_Language_btn_portugues_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_btn_portugues_main
	lv_style_set_radius(&style_Language_btn_portugues_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Language_btn_portugues_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Language_btn_portugues_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Language_btn_portugues_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_portugues_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Language_btn_portugues_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Language_btn_portugues_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Language_btn_portugues_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Language_btn_portugues_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Language_btn_portugues_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Language_btn_portugues_main
	lv_style_set_radius(&style_Language_btn_portugues_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Language_btn_portugues_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Language_btn_portugues_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Language_btn_portugues_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_portugues_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Language_btn_portugues_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Language_btn_portugues_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_Language_btn_portugues_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Language_btn_portugues_main, LV_STATE_PRESSED, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_Language_btn_portugues_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Language_btn_portugues, LV_BTN_PART_MAIN, &style_Language_btn_portugues_main);
	lv_obj_set_pos(ui->Language_btn_portugues, 20, 510);
	lv_obj_set_size(ui->Language_btn_portugues, 210, 115);
//	ui->Language_btn_portugues_label = lv_label_create(ui->Language_btn_portugues, NULL);
//	lv_label_set_text(ui->Language_btn_portugues_label, "");
//	lv_obj_set_style_local_text_color(ui->Language_btn_portugues_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes Language_btn_russian
	ui->Language_btn_russian = lv_btn_create(ui->Language_cont_language, NULL);

	//Write style LV_BTN_PART_MAIN for Language_btn_russian
	static lv_style_t style_Language_btn_russian_main;
	lv_style_reset(&style_Language_btn_russian_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_btn_russian_main
	lv_style_set_radius(&style_Language_btn_russian_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Language_btn_russian_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Language_btn_russian_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Language_btn_russian_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_russian_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Language_btn_russian_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Language_btn_russian_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Language_btn_russian_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Language_btn_russian_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Language_btn_russian_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Language_btn_russian_main
	lv_style_set_radius(&style_Language_btn_russian_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Language_btn_russian_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Language_btn_russian_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Language_btn_russian_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_russian_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Language_btn_russian_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Language_btn_russian_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_Language_btn_russian_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Language_btn_russian_main, LV_STATE_PRESSED, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_Language_btn_russian_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Language_btn_russian, LV_BTN_PART_MAIN, &style_Language_btn_russian_main);
	lv_obj_set_pos(ui->Language_btn_russian, 250, 510);
	lv_obj_set_size(ui->Language_btn_russian, 210, 115);
//	ui->Language_btn_russian_label = lv_label_create(ui->Language_btn_russian, NULL);
//	lv_label_set_text(ui->Language_btn_russian_label, "");
//	lv_obj_set_style_local_text_color(ui->Language_btn_russian_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes Language_btn_turkish
	ui->Language_btn_turkish = lv_btn_create(ui->Language_cont_language, NULL);

	//Write style LV_BTN_PART_MAIN for Language_btn_turkish
	static lv_style_t style_Language_btn_turkish_main;
	lv_style_reset(&style_Language_btn_turkish_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_btn_turkish_main
	lv_style_set_radius(&style_Language_btn_turkish_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Language_btn_turkish_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Language_btn_turkish_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Language_btn_turkish_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_turkish_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Language_btn_turkish_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Language_btn_turkish_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Language_btn_turkish_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Language_btn_turkish_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Language_btn_turkish_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Language_btn_turkish_main
	lv_style_set_radius(&style_Language_btn_turkish_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Language_btn_turkish_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Language_btn_turkish_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Language_btn_turkish_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_btn_turkish_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Language_btn_turkish_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Language_btn_turkish_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_Language_btn_turkish_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Language_btn_turkish_main, LV_STATE_PRESSED, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_Language_btn_turkish_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Language_btn_turkish, LV_BTN_PART_MAIN, &style_Language_btn_turkish_main);
	lv_obj_set_pos(ui->Language_btn_turkish, 20, 645);
	lv_obj_set_size(ui->Language_btn_turkish, 210, 115);
//	ui->Language_btn_turkish_label = lv_label_create(ui->Language_btn_turkish, NULL);
//	lv_label_set_text(ui->Language_btn_turkish_label, "");
//	lv_obj_set_style_local_text_color(ui->Language_btn_turkish_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes Language_label_12
	ui->Language_label_12 = lv_label_create(ui->Language_cont_language, NULL);
	lv_label_set_text(ui->Language_label_12, "Français");
	lv_label_set_long_mode(ui->Language_label_12, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Language_label_12, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Language_label_12
	static lv_style_t style_Language_label_12_main;
	lv_style_reset(&style_Language_label_12_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_label_12_main
	lv_style_set_radius(&style_Language_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Language_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Language_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Language_label_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Language_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Language_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Language_label_12_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Language_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Language_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Language_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Language_label_12_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Language_label_12, LV_LABEL_PART_MAIN, &style_Language_label_12_main);
	lv_obj_set_pos(ui->Language_label_12, 87, 415);
	lv_obj_set_size(ui->Language_label_12, 150, 0);

	//Write codes Language_label_11
	ui->Language_label_11 = lv_label_create(ui->Language_cont_language, NULL);
	lv_label_set_text(ui->Language_label_11, "Português");
	lv_label_set_long_mode(ui->Language_label_11, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Language_label_11, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Language_label_11
	static lv_style_t style_Language_label_11_main;
	lv_style_reset(&style_Language_label_11_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_label_11_main
	lv_style_set_radius(&style_Language_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Language_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Language_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Language_label_11_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Language_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Language_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Language_label_11_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Language_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Language_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Language_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Language_label_11_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Language_label_11, LV_LABEL_PART_MAIN, &style_Language_label_11_main);
	lv_obj_set_pos(ui->Language_label_11, 87, 550);
	lv_obj_set_size(ui->Language_label_11, 150, 0);

	//Write codes Language_label_10
	ui->Language_label_10 = lv_label_create(ui->Language_cont_language, NULL);
	lv_label_set_text(ui->Language_label_10, "Русский");
	lv_label_set_long_mode(ui->Language_label_10, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Language_label_10, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Language_label_10
	static lv_style_t style_Language_label_10_main;
	lv_style_reset(&style_Language_label_10_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_label_10_main
	lv_style_set_radius(&style_Language_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Language_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Language_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Language_label_10_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Language_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Language_label_10_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Language_label_10_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Language_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Language_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Language_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Language_label_10_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Language_label_10, LV_LABEL_PART_MAIN, &style_Language_label_10_main);
	lv_obj_set_pos(ui->Language_label_10, 317, 550);
	lv_obj_set_size(ui->Language_label_10, 150, 0);

	//Write codes Language_img_4
	ui->Language_img_4 = lv_img_create(ui->Language_cont_language, NULL);

	//Write style LV_IMG_PART_MAIN for Language_img_4
//	static lv_style_t style_Language_img_4_main;
//	lv_style_reset(&style_Language_img_4_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Language_img_4_main
//	lv_style_set_image_recolor(&style_Language_img_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Language_img_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Language_img_4_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Language_img_4, LV_IMG_PART_MAIN, &style_Language_img_4_main);
	lv_obj_set_pos(ui->Language_img_4, 27, 280);
//	lv_obj_set_size(ui->Language_img_4, 48, 32);
//	lv_obj_set_click(ui->Language_img_4, true);
	lv_img_set_src(ui->Language_img_4,&_la5_alpha_48x32);
//	lv_img_set_pivot(ui->Language_img_4, 0,0);
//	lv_img_set_angle(ui->Language_img_4, 0);

	//Write codes Language_img_5
	ui->Language_img_5 = lv_img_create(ui->Language_cont_language, NULL);

	//Write style LV_IMG_PART_MAIN for Language_img_5
//	static lv_style_t style_Language_img_5_main;
//	lv_style_reset(&style_Language_img_5_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Language_img_5_main
//	lv_style_set_image_recolor(&style_Language_img_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Language_img_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Language_img_5_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Language_img_5, LV_IMG_PART_MAIN, &style_Language_img_5_main);
	lv_obj_set_pos(ui->Language_img_5, 257, 280);
//	lv_obj_set_size(ui->Language_img_5, 48, 32);
//	lv_obj_set_click(ui->Language_img_5, true);
	lv_img_set_src(ui->Language_img_5,&_la4_alpha_48x32);
//	lv_img_set_pivot(ui->Language_img_5, 0,0);
//	lv_img_set_angle(ui->Language_img_5, 0);

	//Write codes Language_img_6
	ui->Language_img_6 = lv_img_create(ui->Language_cont_language, NULL);

	//Write style LV_IMG_PART_MAIN for Language_img_6
//	static lv_style_t style_Language_img_6_main;
//	lv_style_reset(&style_Language_img_6_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Language_img_6_main
//	lv_style_set_image_recolor(&style_Language_img_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Language_img_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Language_img_6_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Language_img_6, LV_IMG_PART_MAIN, &style_Language_img_6_main);
	lv_obj_set_pos(ui->Language_img_6, 27, 415);
//	lv_obj_set_size(ui->Language_img_6, 48, 32);
//	lv_obj_set_click(ui->Language_img_6, true);
	lv_img_set_src(ui->Language_img_6,&_la6_alpha_48x32);
//	lv_img_set_pivot(ui->Language_img_6, 0,0);
//	lv_img_set_angle(ui->Language_img_6, 0);

	//Write codes Language_img_7
	ui->Language_img_7 = lv_img_create(ui->Language_cont_language, NULL);

	//Write style LV_IMG_PART_MAIN for Language_img_7
//	static lv_style_t style_Language_img_7_main;
//	lv_style_reset(&style_Language_img_7_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Language_img_7_main
//	lv_style_set_image_recolor(&style_Language_img_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Language_img_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Language_img_7_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Language_img_7, LV_IMG_PART_MAIN, &style_Language_img_7_main);
	lv_obj_set_pos(ui->Language_img_7, 257, 415);
//	lv_obj_set_size(ui->Language_img_7, 48, 32);
//	lv_obj_set_click(ui->Language_img_7, true);
	lv_img_set_src(ui->Language_img_7,&_la8_alpha_48x32);
//	lv_img_set_pivot(ui->Language_img_7, 0,0);
//	lv_img_set_angle(ui->Language_img_7, 0);

	//Write codes Language_img_8
	ui->Language_img_8 = lv_img_create(ui->Language_cont_language, NULL);

	//Write style LV_IMG_PART_MAIN for Language_img_8
//	static lv_style_t style_Language_img_8_main;
//	lv_style_reset(&style_Language_img_8_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Language_img_8_main
//	lv_style_set_image_recolor(&style_Language_img_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Language_img_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Language_img_8_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Language_img_8, LV_IMG_PART_MAIN, &style_Language_img_8_main);
	lv_obj_set_pos(ui->Language_img_8, 27, 550);
//	lv_obj_set_size(ui->Language_img_8, 48, 32);
//	lv_obj_set_click(ui->Language_img_8, true);
	lv_img_set_src(ui->Language_img_8,&_la3_alpha_48x32);
//	lv_img_set_pivot(ui->Language_img_8, 0,0);
//	lv_img_set_angle(ui->Language_img_8, 0);

	//Write codes Language_img_9
	ui->Language_img_9 = lv_img_create(ui->Language_cont_language, NULL);

	//Write style LV_IMG_PART_MAIN for Language_img_9
//	static lv_style_t style_Language_img_9_main;
//	lv_style_reset(&style_Language_img_9_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Language_img_9_main
//	lv_style_set_image_recolor(&style_Language_img_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Language_img_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Language_img_9_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Language_img_9, LV_IMG_PART_MAIN, &style_Language_img_9_main);
	lv_obj_set_pos(ui->Language_img_9, 257, 550);
//	lv_obj_set_size(ui->Language_img_9, 48, 32);
//	lv_obj_set_click(ui->Language_img_9, true);
	lv_img_set_src(ui->Language_img_9,&_la9_alpha_48x32);
//	lv_img_set_pivot(ui->Language_img_9, 0,0);
//	lv_img_set_angle(ui->Language_img_9, 0);

	//Write codes Language_img_10
	ui->Language_img_10 = lv_img_create(ui->Language_cont_language, NULL);

	//Write style LV_IMG_PART_MAIN for Language_img_10
//	static lv_style_t style_Language_img_10_main;
//	lv_style_reset(&style_Language_img_10_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Language_img_10_main
//	lv_style_set_image_recolor(&style_Language_img_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Language_img_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Language_img_10_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Language_img_10, LV_IMG_PART_MAIN, &style_Language_img_10_main);
	lv_obj_set_pos(ui->Language_img_10, 27, 685);
//	lv_obj_set_size(ui->Language_img_10, 48, 32);
//	lv_obj_set_click(ui->Language_img_10, true);
	lv_img_set_src(ui->Language_img_10,&_la7_alpha_48x32);
//	lv_img_set_pivot(ui->Language_img_10, 0,0);
//	lv_img_set_angle(ui->Language_img_10, 0);

	//Write codes Language_label_4
	ui->Language_label_4 = lv_label_create(ui->Language_cont_language, NULL);
	lv_label_set_text(ui->Language_label_4, "Deutsch");
	lv_label_set_long_mode(ui->Language_label_4, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Language_label_4, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Language_label_4
	static lv_style_t style_Language_label_4_main;
	lv_style_reset(&style_Language_label_4_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_label_4_main
	lv_style_set_radius(&style_Language_label_4_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Language_label_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Language_label_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Language_label_4_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_label_4_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Language_label_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Language_label_4_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Language_label_4_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Language_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Language_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Language_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Language_label_4_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Language_label_4, LV_LABEL_PART_MAIN, &style_Language_label_4_main);
	lv_obj_set_pos(ui->Language_label_4, 87, 280);
	lv_obj_set_size(ui->Language_label_4, 120, 0);

	//Write codes Language_label_7
	ui->Language_label_7 = lv_label_create(ui->Language_cont_language, NULL);
	lv_label_set_text(ui->Language_label_7, "Turkish");
	lv_label_set_long_mode(ui->Language_label_7, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Language_label_7, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Language_label_7
	static lv_style_t style_Language_label_7_main;
	lv_style_reset(&style_Language_label_7_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_label_7_main
	lv_style_set_radius(&style_Language_label_7_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Language_label_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Language_label_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Language_label_7_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_label_7_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Language_label_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Language_label_7_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Language_label_7_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Language_label_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Language_label_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Language_label_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Language_label_7_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Language_label_7, LV_LABEL_PART_MAIN, &style_Language_label_7_main);
	lv_obj_set_pos(ui->Language_label_7, 87, 685);
	lv_obj_set_size(ui->Language_label_7, 120, 0);

	//Write codes Language_label_9
	ui->Language_label_9 = lv_label_create(ui->Language_cont_language, NULL);
	lv_label_set_text(ui->Language_label_9, "Italiano");
	lv_label_set_long_mode(ui->Language_label_9, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Language_label_9, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Language_label_9
	static lv_style_t style_Language_label_9_main;
	lv_style_reset(&style_Language_label_9_main);

	//Write style state: LV_STATE_DEFAULT for style_Language_label_9_main
	lv_style_set_radius(&style_Language_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Language_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Language_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Language_label_9_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Language_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Language_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Language_label_9_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Language_label_9_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Language_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Language_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Language_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Language_label_9_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Language_label_9, LV_LABEL_PART_MAIN, &style_Language_label_9_main);
	lv_obj_set_pos(ui->Language_label_9, 317, 415);
	lv_obj_set_size(ui->Language_label_9, 136, 0);
	lv_cont_set_layout(ui->Language_cont_language, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->Language_cont_language, LV_FIT_NONE);

	//Init events for screen
	events_init_Language(ui);
}
