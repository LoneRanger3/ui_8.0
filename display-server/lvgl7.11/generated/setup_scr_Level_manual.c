/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_Level_manual(lv_ui *ui){

	//Write codes Level_manual
//	ui->Level_manual = lv_obj_create(NULL, NULL);

	//Write codes Level_manual_cont_level_manual
	ui->Level_manual_cont_level_manual = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for Level_manual_cont_level_manual
	static lv_style_t style_Level_manual_cont_level_manual_main;
	lv_style_reset(&style_Level_manual_cont_level_manual_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_cont_level_manual_main
	lv_style_set_radius(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_manual_cont_level_manual_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_manual_cont_level_manual, LV_CONT_PART_MAIN, &style_Level_manual_cont_level_manual_main);
	lv_obj_set_pos(ui->Level_manual_cont_level_manual, 0, 0);
	lv_obj_set_size(ui->Level_manual_cont_level_manual, 480, 691);
	lv_obj_set_click(ui->Level_manual_cont_level_manual, false);

	//Write codes Level_manual_btn_11
	ui->Level_manual_btn_11 = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_11
	static lv_style_t style_Level_manual_btn_11_main;
	lv_style_reset(&style_Level_manual_btn_11_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_11_main
	lv_style_set_radius(&style_Level_manual_btn_11_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_11_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_11_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_11_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_color(&style_Level_manual_btn_11_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_Level_manual_btn_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_manual_btn_11_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_11_main, LV_STATE_DEFAULT, lv_color_make(0x3b, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_manual_btn_11_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Level_manual_btn_11, LV_BTN_PART_MAIN, &style_Level_manual_btn_11_main);
	lv_obj_set_pos(ui->Level_manual_btn_11, 36, 106);
	lv_obj_set_size(ui->Level_manual_btn_11, 408, 266);
//	ui->Level_manual_btn_11_label = lv_label_create(ui->Level_manual_btn_11, NULL);
//	lv_label_set_text(ui->Level_manual_btn_11_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_manual_btn_11_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Level_manual_btn_zone
	ui->Level_manual_btn_zone = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_zone
	static lv_style_t style_Level_manual_btn_zone_main;
	lv_style_reset(&style_Level_manual_btn_zone_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_zone_main
	lv_style_set_radius(&style_Level_manual_btn_zone_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_zone_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_zone_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_zone_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zone_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zone_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zone_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Level_manual_btn_zone_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zone_main, LV_STATE_DEFAULT, lv_color_make(0x3b, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_manual_btn_zone_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Level_manual_btn_zone_main
	lv_style_set_radius(&style_Level_manual_btn_zone_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_zone_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_zone_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_zone_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zone_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zone_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zone_main, LV_STATE_PRESSED, 2);
	lv_style_set_border_opa(&style_Level_manual_btn_zone_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zone_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_Level_manual_btn_zone_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Level_manual_btn_zone, LV_BTN_PART_MAIN, &style_Level_manual_btn_zone_main);
	lv_obj_set_pos(ui->Level_manual_btn_zone, 170, 195);
	lv_obj_set_size(ui->Level_manual_btn_zone, 140, 88);
//	ui->Level_manual_btn_zone_label = lv_label_create(ui->Level_manual_btn_zone, NULL);
//	lv_label_set_text(ui->Level_manual_btn_zone_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_manual_btn_zone_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Level_manual_arc_num1
	ui->Level_manual_arc_num1 = lv_arc_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_ARC_PART_BG for Level_manual_arc_num1
	static lv_style_t style_Level_manual_arc_num1_bg;
	lv_style_reset(&style_Level_manual_arc_num1_bg);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_arc_num1_bg
	lv_style_set_bg_color(&style_Level_manual_arc_num1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_manual_arc_num1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_manual_arc_num1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_arc_num1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_width(&style_Level_manual_arc_num1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_line_color(&style_Level_manual_arc_num1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_Level_manual_arc_num1_bg, LV_STATE_DEFAULT, 2);
	lv_obj_add_style(ui->Level_manual_arc_num1, LV_ARC_PART_BG, &style_Level_manual_arc_num1_bg);

	//Write style LV_ARC_PART_INDIC for Level_manual_arc_num1
	static lv_style_t style_Level_manual_arc_num1_indic;
	lv_style_reset(&style_Level_manual_arc_num1_indic);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_arc_num1_indic
	lv_style_set_line_color(&style_Level_manual_arc_num1_indic, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_Level_manual_arc_num1_indic, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_manual_arc_num1, LV_ARC_PART_INDIC, &style_Level_manual_arc_num1_indic);
	lv_obj_set_pos(ui->Level_manual_arc_num1, 180, 179);
	lv_obj_set_size(ui->Level_manual_arc_num1, 120, 120);
	lv_arc_set_bg_angles(ui->Level_manual_arc_num1, 0, 360);
	lv_arc_set_angles(ui->Level_manual_arc_num1, 90, 180);
	lv_arc_set_rotation(ui->Level_manual_arc_num1, 0);
	lv_obj_set_style_local_pad_top(ui->Level_manual_arc_num1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_bottom(ui->Level_manual_arc_num1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_left(ui->Level_manual_arc_num1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_right(ui->Level_manual_arc_num1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_line_rounded(ui->Level_manual_arc_num1, LV_ARC_PART_INDIC, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_line_rounded(ui->Level_manual_arc_num1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 0);

	//Write codes Level_manual_label_8
	ui->Level_manual_label_8 = lv_label_create(ui->Level_manual_cont_level_manual, NULL);
	lv_label_set_text(ui->Level_manual_label_8, "1");
	lv_label_set_long_mode(ui->Level_manual_label_8, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Level_manual_label_8, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Level_manual_label_8
	static lv_style_t style_Level_manual_label_8_main;
	lv_style_reset(&style_Level_manual_label_8_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_label_8_main
	lv_style_set_radius(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_manual_label_8_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_manual_label_8, LV_LABEL_PART_MAIN, &style_Level_manual_label_8_main);
	lv_obj_set_pos(ui->Level_manual_label_8, 200, 225);
	lv_obj_set_size(ui->Level_manual_label_8, 80, 0);

	//Write codes Level_manual_btn_zfour
	ui->Level_manual_btn_zfour = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_zfour
	static lv_style_t style_Level_manual_btn_zfour_main;
	lv_style_reset(&style_Level_manual_btn_zfour_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_zfour_main
	lv_style_set_radius(&style_Level_manual_btn_zfour_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_zfour_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_zfour_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_zfour_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zfour_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zfour_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zfour_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Level_manual_btn_zfour_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zfour_main, LV_STATE_DEFAULT, lv_color_make(0x3b, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_manual_btn_zfour_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Level_manual_btn_zfour_main
	lv_style_set_radius(&style_Level_manual_btn_zfour_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_zfour_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_zfour_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_zfour_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zfour_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zfour_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zfour_main, LV_STATE_PRESSED, 2);
	lv_style_set_border_opa(&style_Level_manual_btn_zfour_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zfour_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_Level_manual_btn_zfour_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Level_manual_btn_zfour, LV_BTN_PART_MAIN, &style_Level_manual_btn_zfour_main);
	lv_obj_set_pos(ui->Level_manual_btn_zfour, 304, 106);
	lv_obj_set_size(ui->Level_manual_btn_zfour, 140, 88);
//	ui->Level_manual_btn_zfour_label = lv_label_create(ui->Level_manual_btn_zfour, NULL);
//	lv_label_set_text(ui->Level_manual_btn_zfour_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_manual_btn_zfour_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Level_manual_arc_num4
	ui->Level_manual_arc_num4 = lv_arc_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_ARC_PART_BG for Level_manual_arc_num4
	static lv_style_t style_Level_manual_arc_num4_bg;
	lv_style_reset(&style_Level_manual_arc_num4_bg);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_arc_num4_bg
	lv_style_set_bg_color(&style_Level_manual_arc_num4_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_manual_arc_num4_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_manual_arc_num4_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_arc_num4_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_width(&style_Level_manual_arc_num4_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_line_color(&style_Level_manual_arc_num4_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_Level_manual_arc_num4_bg, LV_STATE_DEFAULT, 2);
	lv_obj_add_style(ui->Level_manual_arc_num4, LV_ARC_PART_BG, &style_Level_manual_arc_num4_bg);

	//Write style LV_ARC_PART_INDIC for Level_manual_arc_num4
	static lv_style_t style_Level_manual_arc_num4_indic;
	lv_style_reset(&style_Level_manual_arc_num4_indic);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_arc_num4_indic
	lv_style_set_line_color(&style_Level_manual_arc_num4_indic, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_Level_manual_arc_num4_indic, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_manual_arc_num4, LV_ARC_PART_INDIC, &style_Level_manual_arc_num4_indic);
	lv_obj_set_pos(ui->Level_manual_arc_num4, 315, 90);
	lv_obj_set_size(ui->Level_manual_arc_num4, 120, 120);
	lv_arc_set_bg_angles(ui->Level_manual_arc_num4, 0, 360);
	lv_arc_set_angles(ui->Level_manual_arc_num4, 90, 180);
	lv_arc_set_rotation(ui->Level_manual_arc_num4, 0);
	lv_obj_set_style_local_pad_top(ui->Level_manual_arc_num4, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_bottom(ui->Level_manual_arc_num4, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_left(ui->Level_manual_arc_num4, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_right(ui->Level_manual_arc_num4, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_line_rounded(ui->Level_manual_arc_num4, LV_ARC_PART_INDIC, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_line_rounded(ui->Level_manual_arc_num4, LV_ARC_PART_BG, LV_STATE_DEFAULT, 0);

	//Write codes Level_manual_label_11
	ui->Level_manual_label_11 = lv_label_create(ui->Level_manual_cont_level_manual, NULL);
	lv_label_set_text(ui->Level_manual_label_11, "4");
	lv_label_set_long_mode(ui->Level_manual_label_11, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Level_manual_label_11, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Level_manual_label_11
	static lv_style_t style_Level_manual_label_11_main;
	lv_style_reset(&style_Level_manual_label_11_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_label_11_main
	lv_style_set_radius(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_manual_label_11_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_manual_label_11, LV_LABEL_PART_MAIN, &style_Level_manual_label_11_main);
	lv_obj_set_pos(ui->Level_manual_label_11, 335, 136);
	lv_obj_set_size(ui->Level_manual_label_11, 80, 0);

	//Write codes Level_manual_btn_zfive
	ui->Level_manual_btn_zfive = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_zfive
	static lv_style_t style_Level_manual_btn_zfive_main;
	lv_style_reset(&style_Level_manual_btn_zfive_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_zfive_main
	lv_style_set_radius(&style_Level_manual_btn_zfive_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_zfive_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_zfive_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_zfive_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zfive_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zfive_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zfive_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Level_manual_btn_zfive_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zfive_main, LV_STATE_DEFAULT, lv_color_make(0x3b, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_manual_btn_zfive_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Level_manual_btn_zfive_main
	lv_style_set_radius(&style_Level_manual_btn_zfive_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_zfive_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_zfive_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_zfive_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zfive_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zfive_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zfive_main, LV_STATE_PRESSED, 2);
	lv_style_set_border_opa(&style_Level_manual_btn_zfive_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zfive_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_Level_manual_btn_zfive_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Level_manual_btn_zfive, LV_BTN_PART_MAIN, &style_Level_manual_btn_zfive_main);
	lv_obj_set_pos(ui->Level_manual_btn_zfive, 36, 106);
	lv_obj_set_size(ui->Level_manual_btn_zfive, 140, 88);
//	ui->Level_manual_btn_zfive_label = lv_label_create(ui->Level_manual_btn_zfive, NULL);
//	lv_label_set_text(ui->Level_manual_btn_zfive_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_manual_btn_zfive_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Level_manual_label_12
	ui->Level_manual_label_12 = lv_label_create(ui->Level_manual_cont_level_manual, NULL);
	lv_label_set_text(ui->Level_manual_label_12, "5");
	lv_label_set_long_mode(ui->Level_manual_label_12, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Level_manual_label_12, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Level_manual_label_12
	static lv_style_t style_Level_manual_label_12_main;
	lv_style_reset(&style_Level_manual_label_12_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_label_12_main
	lv_style_set_radius(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_manual_label_12_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_manual_label_12, LV_LABEL_PART_MAIN, &style_Level_manual_label_12_main);
	lv_obj_set_pos(ui->Level_manual_label_12, 66, 136);
	lv_obj_set_size(ui->Level_manual_label_12, 80, 0);

	//Write codes Level_manual_arc_num5
	ui->Level_manual_arc_num5 = lv_arc_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_ARC_PART_BG for Level_manual_arc_num5
	static lv_style_t style_Level_manual_arc_num5_bg;
	lv_style_reset(&style_Level_manual_arc_num5_bg);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_arc_num5_bg
	lv_style_set_bg_color(&style_Level_manual_arc_num5_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_manual_arc_num5_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_manual_arc_num5_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_arc_num5_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_width(&style_Level_manual_arc_num5_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_line_color(&style_Level_manual_arc_num5_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_Level_manual_arc_num5_bg, LV_STATE_DEFAULT, 2);
	lv_obj_add_style(ui->Level_manual_arc_num5, LV_ARC_PART_BG, &style_Level_manual_arc_num5_bg);

	//Write style LV_ARC_PART_INDIC for Level_manual_arc_num5
	static lv_style_t style_Level_manual_arc_num5_indic;
	lv_style_reset(&style_Level_manual_arc_num5_indic);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_arc_num5_indic
	lv_style_set_line_color(&style_Level_manual_arc_num5_indic, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_Level_manual_arc_num5_indic, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_manual_arc_num5, LV_ARC_PART_INDIC, &style_Level_manual_arc_num5_indic);
	lv_obj_set_pos(ui->Level_manual_arc_num5, 46, 90);
	lv_obj_set_size(ui->Level_manual_arc_num5, 120, 120);
	lv_arc_set_bg_angles(ui->Level_manual_arc_num5, 0, 360);
	lv_arc_set_angles(ui->Level_manual_arc_num5, 90, 180);
	lv_arc_set_rotation(ui->Level_manual_arc_num5, 0);
	lv_obj_set_style_local_pad_top(ui->Level_manual_arc_num5, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_bottom(ui->Level_manual_arc_num5, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_left(ui->Level_manual_arc_num5, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_right(ui->Level_manual_arc_num5, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_line_rounded(ui->Level_manual_arc_num5, LV_ARC_PART_INDIC, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_line_rounded(ui->Level_manual_arc_num5, LV_ARC_PART_BG, LV_STATE_DEFAULT, 0);

	//Write codes Level_manual_btn_zthree
	ui->Level_manual_btn_zthree = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_zthree
	static lv_style_t style_Level_manual_btn_zthree_main;
	lv_style_reset(&style_Level_manual_btn_zthree_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_zthree_main
	lv_style_set_radius(&style_Level_manual_btn_zthree_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_zthree_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_zthree_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_zthree_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zthree_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zthree_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zthree_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Level_manual_btn_zthree_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zthree_main, LV_STATE_DEFAULT, lv_color_make(0x3b, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_manual_btn_zthree_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Level_manual_btn_zthree_main
	lv_style_set_radius(&style_Level_manual_btn_zthree_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_zthree_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_zthree_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_zthree_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zthree_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zthree_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zthree_main, LV_STATE_PRESSED, 2);
	lv_style_set_border_opa(&style_Level_manual_btn_zthree_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zthree_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_Level_manual_btn_zthree_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Level_manual_btn_zthree, LV_BTN_PART_MAIN, &style_Level_manual_btn_zthree_main);
	lv_obj_set_pos(ui->Level_manual_btn_zthree, 304, 284);
	lv_obj_set_size(ui->Level_manual_btn_zthree, 140, 88);
//	ui->Level_manual_btn_zthree_label = lv_label_create(ui->Level_manual_btn_zthree, NULL);
//	lv_label_set_text(ui->Level_manual_btn_zthree_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_manual_btn_zthree_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Level_manual_label_10
	ui->Level_manual_label_10 = lv_label_create(ui->Level_manual_cont_level_manual, NULL);
	lv_label_set_text(ui->Level_manual_label_10, "3");
	lv_label_set_long_mode(ui->Level_manual_label_10, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Level_manual_label_10, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Level_manual_label_10
	static lv_style_t style_Level_manual_label_10_main;
	lv_style_reset(&style_Level_manual_label_10_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_label_10_main
	lv_style_set_radius(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_manual_label_10_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_manual_label_10, LV_LABEL_PART_MAIN, &style_Level_manual_label_10_main);
	lv_obj_set_pos(ui->Level_manual_label_10, 335, 315);
	lv_obj_set_size(ui->Level_manual_label_10, 80, 0);

	//Write codes Level_manual_btn_ztwo
	ui->Level_manual_btn_ztwo = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_ztwo
	static lv_style_t style_Level_manual_btn_ztwo_main;
	lv_style_reset(&style_Level_manual_btn_ztwo_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_ztwo_main
	lv_style_set_radius(&style_Level_manual_btn_ztwo_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_ztwo_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_ztwo_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_ztwo_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_ztwo_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Level_manual_btn_ztwo_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_ztwo_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Level_manual_btn_ztwo_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_ztwo_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_manual_btn_ztwo_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Level_manual_btn_ztwo_main
	lv_style_set_radius(&style_Level_manual_btn_ztwo_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_ztwo_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_ztwo_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_ztwo_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_ztwo_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Level_manual_btn_ztwo_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_ztwo_main, LV_STATE_PRESSED, 2);
	lv_style_set_border_opa(&style_Level_manual_btn_ztwo_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_ztwo_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_Level_manual_btn_ztwo_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Level_manual_btn_ztwo, LV_BTN_PART_MAIN, &style_Level_manual_btn_ztwo_main);
	lv_obj_set_pos(ui->Level_manual_btn_ztwo, 36, 284);
	lv_obj_set_size(ui->Level_manual_btn_ztwo, 140, 88);
//	ui->Level_manual_btn_ztwo_label = lv_label_create(ui->Level_manual_btn_ztwo, NULL);
//	lv_label_set_text(ui->Level_manual_btn_ztwo_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_manual_btn_ztwo_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Level_manual_label_9
	ui->Level_manual_label_9 = lv_label_create(ui->Level_manual_cont_level_manual, NULL);
	lv_label_set_text(ui->Level_manual_label_9, "2");
	lv_label_set_long_mode(ui->Level_manual_label_9, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Level_manual_label_9, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Level_manual_label_9
	static lv_style_t style_Level_manual_label_9_main;
	lv_style_reset(&style_Level_manual_label_9_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_label_9_main
	lv_style_set_radius(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_manual_label_9_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_manual_label_9, LV_LABEL_PART_MAIN, &style_Level_manual_label_9_main);
	lv_obj_set_pos(ui->Level_manual_label_9, 66, 315);
	lv_obj_set_size(ui->Level_manual_label_9, 80, 0);

	//Write codes Level_manual_arc_num3
	ui->Level_manual_arc_num3 = lv_arc_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_ARC_PART_BG for Level_manual_arc_num3
	static lv_style_t style_Level_manual_arc_num3_bg;
	lv_style_reset(&style_Level_manual_arc_num3_bg);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_arc_num3_bg
	lv_style_set_bg_color(&style_Level_manual_arc_num3_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_manual_arc_num3_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_manual_arc_num3_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_arc_num3_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_width(&style_Level_manual_arc_num3_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_line_color(&style_Level_manual_arc_num3_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_Level_manual_arc_num3_bg, LV_STATE_DEFAULT, 2);
	lv_obj_add_style(ui->Level_manual_arc_num3, LV_ARC_PART_BG, &style_Level_manual_arc_num3_bg);

	//Write style LV_ARC_PART_INDIC for Level_manual_arc_num3
	static lv_style_t style_Level_manual_arc_num3_indic;
	lv_style_reset(&style_Level_manual_arc_num3_indic);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_arc_num3_indic
	lv_style_set_line_color(&style_Level_manual_arc_num3_indic, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_Level_manual_arc_num3_indic, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_manual_arc_num3, LV_ARC_PART_INDIC, &style_Level_manual_arc_num3_indic);
	lv_obj_set_pos(ui->Level_manual_arc_num3, 315, 268);
	lv_obj_set_size(ui->Level_manual_arc_num3, 120, 120);
	lv_arc_set_bg_angles(ui->Level_manual_arc_num3, 0, 360);
	lv_arc_set_angles(ui->Level_manual_arc_num3, 90, 180);
	lv_arc_set_rotation(ui->Level_manual_arc_num3, 0);
	lv_obj_set_style_local_pad_top(ui->Level_manual_arc_num3, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_bottom(ui->Level_manual_arc_num3, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_left(ui->Level_manual_arc_num3, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_right(ui->Level_manual_arc_num3, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_line_rounded(ui->Level_manual_arc_num3, LV_ARC_PART_INDIC, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_line_rounded(ui->Level_manual_arc_num3, LV_ARC_PART_BG, LV_STATE_DEFAULT, 0);

	//Write codes Level_manual_arc_num2
	ui->Level_manual_arc_num2 = lv_arc_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_ARC_PART_BG for Level_manual_arc_num2
	static lv_style_t style_Level_manual_arc_num2_bg;
	lv_style_reset(&style_Level_manual_arc_num2_bg);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_arc_num2_bg
	lv_style_set_bg_color(&style_Level_manual_arc_num2_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_manual_arc_num2_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_manual_arc_num2_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_arc_num2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_width(&style_Level_manual_arc_num2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_line_color(&style_Level_manual_arc_num2_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_Level_manual_arc_num2_bg, LV_STATE_DEFAULT, 2);
	lv_obj_add_style(ui->Level_manual_arc_num2, LV_ARC_PART_BG, &style_Level_manual_arc_num2_bg);

	//Write style LV_ARC_PART_INDIC for Level_manual_arc_num2
	static lv_style_t style_Level_manual_arc_num2_indic;
	lv_style_reset(&style_Level_manual_arc_num2_indic);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_arc_num2_indic
	lv_style_set_line_color(&style_Level_manual_arc_num2_indic, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_Level_manual_arc_num2_indic, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_manual_arc_num2, LV_ARC_PART_INDIC, &style_Level_manual_arc_num2_indic);
	lv_obj_set_pos(ui->Level_manual_arc_num2, 46, 268);
	lv_obj_set_size(ui->Level_manual_arc_num2, 120, 120);
	lv_arc_set_bg_angles(ui->Level_manual_arc_num2, 0, 360);
	lv_arc_set_angles(ui->Level_manual_arc_num2, 90, 180);
	lv_arc_set_rotation(ui->Level_manual_arc_num2, 0);
	lv_obj_set_style_local_pad_top(ui->Level_manual_arc_num2, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_bottom(ui->Level_manual_arc_num2, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_left(ui->Level_manual_arc_num2, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_right(ui->Level_manual_arc_num2, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_line_rounded(ui->Level_manual_arc_num2, LV_ARC_PART_INDIC, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_line_rounded(ui->Level_manual_arc_num2, LV_ARC_PART_BG, LV_STATE_DEFAULT, 0);

	//Write codes Level_manual_btn_5
	ui->Level_manual_btn_5 = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_5
	static lv_style_t style_Level_manual_btn_5_main;
	lv_style_reset(&style_Level_manual_btn_5_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_5_main
	lv_style_set_radius(&style_Level_manual_btn_5_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Level_manual_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_5_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_color(&style_Level_manual_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_Level_manual_btn_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_manual_btn_5_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0x3b, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_manual_btn_5_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Level_manual_btn_5, LV_BTN_PART_MAIN, &style_Level_manual_btn_5_main);
	lv_obj_set_pos(ui->Level_manual_btn_5, 36, 385);
	lv_obj_set_size(ui->Level_manual_btn_5, 408, 289);
//	ui->Level_manual_btn_5_label = lv_label_create(ui->Level_manual_btn_5, NULL);
//	lv_label_set_text(ui->Level_manual_btn_5_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_manual_btn_5_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	//Write codes Level_manual_btn_12
	ui->Level_manual_btn_12 = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_12
	static lv_style_t style_Level_manual_btn_12_main;
	lv_style_reset(&style_Level_manual_btn_12_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_12_main
	lv_style_set_radius(&style_Level_manual_btn_12_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_Level_manual_btn_12_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_Level_manual_btn_12_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_Level_manual_btn_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_12_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Level_manual_btn_12_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_Level_manual_btn_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_manual_btn_12_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_12_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Level_manual_btn_12_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Level_manual_btn_12, LV_BTN_PART_MAIN, &style_Level_manual_btn_12_main);
	lv_obj_set_pos(ui->Level_manual_btn_12, 58, 607);
	lv_obj_set_size(ui->Level_manual_btn_12, 180, 44);
//	ui->Level_manual_btn_12_label = lv_label_create(ui->Level_manual_btn_12, NULL);
//	lv_label_set_text(ui->Level_manual_btn_12_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_manual_btn_12_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Level_manual_btn_zoffset_unita
	ui->Level_manual_btn_zoffset_unita = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_zoffset_unita
	static lv_style_t style_Level_manual_btn_zoffset_unita_main;
	lv_style_reset(&style_Level_manual_btn_zoffset_unita_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_zoffset_unita_main
	lv_style_set_radius(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Level_manual_btn_zoffset_unita_main
	lv_style_set_radius(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_PRESSED, 50);
	lv_style_set_bg_color(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
//	lv_style_set_bg_grad_color(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
//	lv_style_set_bg_grad_dir(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_Level_manual_btn_zoffset_unita_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Level_manual_btn_zoffset_unita, LV_BTN_PART_MAIN, &style_Level_manual_btn_zoffset_unita_main);
	lv_obj_set_pos(ui->Level_manual_btn_zoffset_unita, 62, 611);
	lv_obj_set_size(ui->Level_manual_btn_zoffset_unita, 84, 36);
	lv_btn_set_checkable(ui->Level_manual_btn_zoffset_unita, true);
	ui->Level_manual_btn_zoffset_unita_label = lv_label_create(ui->Level_manual_btn_zoffset_unita, NULL);
	lv_label_set_text(ui->Level_manual_btn_zoffset_unita_label, "0.01");
	lv_obj_set_style_local_text_color(ui->Level_manual_btn_zoffset_unita_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->Level_manual_btn_zoffset_unita_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Level_manual_btn_zoffset_unitb
	ui->Level_manual_btn_zoffset_unitb = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_zoffset_unitb
	static lv_style_t style_Level_manual_btn_zoffset_unitb_main;
	lv_style_reset(&style_Level_manual_btn_zoffset_unitb_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_zoffset_unitb_main
	lv_style_set_radius(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Level_manual_btn_zoffset_unitb_main
	lv_style_set_radius(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_PRESSED, 50);
	lv_style_set_bg_color(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
//	lv_style_set_bg_grad_color(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
//	lv_style_set_bg_grad_dir(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_Level_manual_btn_zoffset_unitb_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Level_manual_btn_zoffset_unitb, LV_BTN_PART_MAIN, &style_Level_manual_btn_zoffset_unitb_main);
	lv_obj_set_pos(ui->Level_manual_btn_zoffset_unitb, 150, 611);
	lv_obj_set_size(ui->Level_manual_btn_zoffset_unitb, 84, 36);
	lv_btn_set_checkable(ui->Level_manual_btn_zoffset_unitb, true);
	ui->Level_manual_btn_zoffset_unitb_label = lv_label_create(ui->Level_manual_btn_zoffset_unitb, NULL);
	lv_label_set_text(ui->Level_manual_btn_zoffset_unitb_label, "0.1");
	lv_obj_set_style_local_text_color(ui->Level_manual_btn_zoffset_unitb_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->Level_manual_btn_zoffset_unitb_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Level_manual_img_zoffset_down
	ui->Level_manual_img_zoffset_down = lv_img_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_IMG_PART_MAIN for Level_manual_img_zoffset_down
//	static lv_style_t style_Level_manual_img_zoffset_down_main;
//	lv_style_reset(&style_Level_manual_img_zoffset_down_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Level_manual_img_zoffset_down_main
//	lv_style_set_image_recolor(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Level_manual_img_zoffset_down, LV_IMG_PART_MAIN, &style_Level_manual_img_zoffset_down_main);
	lv_obj_set_pos(ui->Level_manual_img_zoffset_down, 274, 594);
//	lv_obj_set_size(ui->Level_manual_img_zoffset_down, 98, 64);
//	lv_obj_set_click(ui->Level_manual_img_zoffset_down, true);
	lv_img_set_src(ui->Level_manual_img_zoffset_down,&_downa_alpha_98x64);
//	lv_img_set_pivot(ui->Level_manual_img_zoffset_down, 0,0);
//	lv_img_set_angle(ui->Level_manual_img_zoffset_down, 0);

	//Write codes Level_manual_img_zoffset_up
	ui->Level_manual_img_zoffset_up = lv_img_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_IMG_PART_MAIN for Level_manual_img_zoffset_up
//	static lv_style_t style_Level_manual_img_zoffset_up_main;
//	lv_style_reset(&style_Level_manual_img_zoffset_up_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Level_manual_img_zoffset_up_main
//	lv_style_set_image_recolor(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Level_manual_img_zoffset_up, LV_IMG_PART_MAIN, &style_Level_manual_img_zoffset_up_main);
	lv_obj_set_pos(ui->Level_manual_img_zoffset_up, 274, 401);
//	lv_obj_set_size(ui->Level_manual_img_zoffset_up, 98, 64);
//	lv_obj_set_click(ui->Level_manual_img_zoffset_up, true);
	lv_img_set_src(ui->Level_manual_img_zoffset_up,&_upa_alpha_98x64);
//	lv_img_set_pivot(ui->Level_manual_img_zoffset_up, 0,0);
//	lv_img_set_angle(ui->Level_manual_img_zoffset_up, 0);

	//Write codes Level_manual_imgbtn_zoffset_up
	ui->Level_manual_imgbtn_zoffset_up = lv_imgbtn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_IMGBTN_PART_MAIN for Level_manual_imgbtn_zoffset_up
	static lv_style_t style_Level_manual_imgbtn_zoffset_up_main;
	lv_style_reset(&style_Level_manual_imgbtn_zoffset_up_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_imgbtn_zoffset_up_main
	lv_style_set_text_color(&style_Level_manual_imgbtn_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_Level_manual_imgbtn_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_Level_manual_imgbtn_zoffset_up_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_Level_manual_imgbtn_zoffset_up_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Level_manual_imgbtn_zoffset_up, LV_IMGBTN_PART_MAIN, &style_Level_manual_imgbtn_zoffset_up_main);
	lv_obj_set_pos(ui->Level_manual_imgbtn_zoffset_up, 304, 418);
	lv_obj_set_size(ui->Level_manual_imgbtn_zoffset_up, 37, 32);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_up,LV_BTN_STATE_RELEASED,&_levelup_alpha_37x32);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_up,LV_BTN_STATE_PRESSED,&_levelup_alpha_37x32);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_up,LV_BTN_STATE_CHECKED_RELEASED,&_levelup_alpha_37x32);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_up,LV_BTN_STATE_CHECKED_PRESSED,&_levelup_alpha_37x32);
	lv_imgbtn_set_checkable(ui->Level_manual_imgbtn_zoffset_up, true);

	//Write codes Level_manual_imgbtn_zoffset_down
	ui->Level_manual_imgbtn_zoffset_down = lv_imgbtn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_IMGBTN_PART_MAIN for Level_manual_imgbtn_zoffset_down
	static lv_style_t style_Level_manual_imgbtn_zoffset_down_main;
	lv_style_reset(&style_Level_manual_imgbtn_zoffset_down_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_imgbtn_zoffset_down_main
	lv_style_set_text_color(&style_Level_manual_imgbtn_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_Level_manual_imgbtn_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_Level_manual_imgbtn_zoffset_down_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_Level_manual_imgbtn_zoffset_down_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Level_manual_imgbtn_zoffset_down, LV_IMGBTN_PART_MAIN, &style_Level_manual_imgbtn_zoffset_down_main);
	lv_obj_set_pos(ui->Level_manual_imgbtn_zoffset_down, 302, 602);
	lv_obj_set_size(ui->Level_manual_imgbtn_zoffset_down, 41, 33);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_down,LV_BTN_STATE_RELEASED,&_leveldown_alpha_41x33);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_down,LV_BTN_STATE_PRESSED,&_leveldown_alpha_41x33);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_down,LV_BTN_STATE_CHECKED_RELEASED,&_leveldown_alpha_41x33);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_down,LV_BTN_STATE_CHECKED_PRESSED,&_leveldown_alpha_41x33);
	lv_imgbtn_set_checkable(ui->Level_manual_imgbtn_zoffset_down, true);

	//Write codes Level_manual_btn_zoffset_home
	ui->Level_manual_btn_zoffset_home = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_zoffset_home
	static lv_style_t style_Level_manual_btn_zoffset_home_main;
	lv_style_reset(&style_Level_manual_btn_zoffset_home_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_zoffset_home_main
	lv_style_set_radius(&style_Level_manual_btn_zoffset_home_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_Level_manual_btn_zoffset_home_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_zoffset_home_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_zoffset_home_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zoffset_home_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zoffset_home_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zoffset_home_main, LV_STATE_DEFAULT, 3);
	lv_style_set_border_opa(&style_Level_manual_btn_zoffset_home_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zoffset_home_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_manual_btn_zoffset_home_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Level_manual_btn_zoffset_home_main
	lv_style_set_radius(&style_Level_manual_btn_zoffset_home_main, LV_STATE_PRESSED, 50);
	lv_style_set_bg_color(&style_Level_manual_btn_zoffset_home_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_zoffset_home_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_zoffset_home_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zoffset_home_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Level_manual_btn_zoffset_home_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_manual_btn_zoffset_home_main, LV_STATE_PRESSED, 3);
	lv_style_set_border_opa(&style_Level_manual_btn_zoffset_home_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zoffset_home_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_Level_manual_btn_zoffset_home_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Level_manual_btn_zoffset_home, LV_BTN_PART_MAIN, &style_Level_manual_btn_zoffset_home_main);
	lv_obj_set_pos(ui->Level_manual_btn_zoffset_home, 277, 483);
	lv_obj_set_size(ui->Level_manual_btn_zoffset_home, 92, 92);
//	ui->Level_manual_btn_zoffset_home_label = lv_label_create(ui->Level_manual_btn_zoffset_home, NULL);
//	lv_label_set_text(ui->Level_manual_btn_zoffset_home_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_manual_btn_zoffset_home_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Level_manual_imgbtn_zoffset_home
	ui->Level_manual_imgbtn_zoffset_home = lv_imgbtn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_IMGBTN_PART_MAIN for Level_manual_imgbtn_zoffset_home
	static lv_style_t style_Level_manual_imgbtn_zoffset_home_main;
	lv_style_reset(&style_Level_manual_imgbtn_zoffset_home_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_imgbtn_zoffset_home_main
	lv_style_set_text_color(&style_Level_manual_imgbtn_zoffset_home_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_Level_manual_imgbtn_zoffset_home_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_Level_manual_imgbtn_zoffset_home_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_Level_manual_imgbtn_zoffset_home_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Level_manual_imgbtn_zoffset_home, LV_IMGBTN_PART_MAIN, &style_Level_manual_imgbtn_zoffset_home_main);
	lv_obj_set_pos(ui->Level_manual_imgbtn_zoffset_home, 299, 506);
	lv_obj_set_size(ui->Level_manual_imgbtn_zoffset_home, 48, 46);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_home,LV_BTN_STATE_RELEASED,&_homea_alpha_48x46);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_home,LV_BTN_STATE_PRESSED,&_homea_alpha_48x46);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_home,LV_BTN_STATE_CHECKED_RELEASED,&_homea_alpha_48x46);
	lv_imgbtn_set_src(ui->Level_manual_imgbtn_zoffset_home,LV_BTN_STATE_CHECKED_PRESSED,&_homea_alpha_48x46);
	lv_imgbtn_set_checkable(ui->Level_manual_imgbtn_zoffset_home, true);

	//Write codes Level_manual_btn_zoffset_value
	ui->Level_manual_btn_zoffset_value = lv_btn_create(ui->Level_manual_cont_level_manual, NULL);

	//Write style LV_BTN_PART_MAIN for Level_manual_btn_zoffset_value
	static lv_style_t style_Level_manual_btn_zoffset_value_main;
	lv_style_reset(&style_Level_manual_btn_zoffset_value_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_manual_btn_zoffset_value_main
	lv_style_set_radius(&style_Level_manual_btn_zoffset_value_main, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_Level_manual_btn_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_Level_manual_btn_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_Level_manual_btn_zoffset_value_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_manual_btn_zoffset_value_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Level_manual_btn_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_Level_manual_btn_zoffset_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_manual_btn_zoffset_value_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_manual_btn_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0x3b, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_manual_btn_zoffset_value_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Level_manual_btn_zoffset_value, LV_BTN_PART_MAIN, &style_Level_manual_btn_zoffset_value_main);
	lv_obj_set_pos(ui->Level_manual_btn_zoffset_value, 84, 422);
	lv_obj_set_size(ui->Level_manual_btn_zoffset_value, 128, 162);
	ui->Level_manual_btn_zoffset_value_label = lv_label_create(ui->Level_manual_btn_zoffset_value, NULL);
	lv_label_set_text(ui->Level_manual_btn_zoffset_value_label, "0.00");
	lv_obj_set_style_local_text_color(ui->Level_manual_btn_zoffset_value_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->Level_manual_btn_zoffset_value_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_cont_set_layout(ui->Level_manual_cont_level_manual, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->Level_manual_cont_level_manual, LV_FIT_NONE);

	//Init events for screen
	events_init_Level_manual(ui);
}
