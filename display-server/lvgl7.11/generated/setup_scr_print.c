/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_print(lv_ui *ui){

	//Write codes print
//	ui->print = lv_obj_create(NULL, NULL);

	//Write codes print_cont_print
	ui->print_cont_print = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for print_cont_print
	static lv_style_t style_print_cont_print_main;
	lv_style_reset(&style_print_cont_print_main);
	lv_style_init(&style_print_cont_print_main);

	//Write style state: LV_STATE_DEFAULT for style_print_cont_print_main
	lv_style_set_radius(&style_print_cont_print_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_print_cont_print_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_print_cont_print_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_print_cont_print_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_print_cont_print_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_print_cont_print_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_print_cont_print_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_print_cont_print_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_print_cont_print_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_print_cont_print_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_print_cont_print_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_print_cont_print_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->print_cont_print, LV_CONT_PART_MAIN, &style_print_cont_print_main);
	lv_obj_set_pos(ui->print_cont_print, 0, 0);
	lv_obj_set_size(ui->print_cont_print, 480, 674);
	lv_obj_set_click(ui->print_cont_print, false);

	//Write codes print_btn_page_num
	ui->print_btn_page_num = lv_btn_create(ui->print_cont_print, NULL);

	//Write style LV_BTN_PART_MAIN for print_btn_page_num
	static lv_style_t style_print_btn_page_num_main;
	lv_style_reset(&style_print_btn_page_num_main);
	lv_style_init(&style_print_btn_page_num_main);

	//Write style state: LV_STATE_DEFAULT for style_print_btn_page_num_main
	lv_style_set_radius(&style_print_btn_page_num_main, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_print_btn_page_num_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_print_btn_page_num_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_print_btn_page_num_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_print_btn_page_num_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_print_btn_page_num_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_print_btn_page_num_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_print_btn_page_num_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_print_btn_page_num_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_print_btn_page_num_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->print_btn_page_num, LV_BTN_PART_MAIN, &style_print_btn_page_num_main);
	lv_obj_set_pos(ui->print_btn_page_num, 210, 592);
	lv_obj_set_size(ui->print_btn_page_num, 60, 60);
	lv_obj_set_click(ui->print_btn_page_num,false);
	ui->print_btn_page_num_label = lv_label_create(ui->print_btn_page_num, NULL);
	lv_label_set_text(ui->print_btn_page_num_label, "");
	lv_obj_set_style_local_text_color(ui->print_btn_page_num_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->print_btn_page_num_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_22);

	//Write codes print_btn_page_end
	ui->print_btn_page_end = lv_btn_create(ui->print_cont_print, NULL);

	//Write style LV_BTN_PART_MAIN for print_btn_page_end
	static lv_style_t style_print_btn_page_end_main;
	lv_style_reset(&style_print_btn_page_end_main);
	lv_style_init(&style_print_btn_page_end_main);

	//Write style state: LV_STATE_DEFAULT for style_print_btn_page_end_main
	lv_style_set_radius(&style_print_btn_page_end_main, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_print_btn_page_end_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_print_btn_page_end_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_print_btn_page_end_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_print_btn_page_end_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_print_btn_page_end_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_print_btn_page_end_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_print_btn_page_end_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_print_btn_page_end_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_print_btn_page_end_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->print_btn_page_end, LV_BTN_PART_MAIN, &style_print_btn_page_end_main);
	lv_obj_set_pos(ui->print_btn_page_end, 388, 582);
	lv_obj_set_size(ui->print_btn_page_end, 80, 80);
//	ui->print_btn_page_end_label = lv_label_create(ui->print_btn_page_end, NULL);
//	lv_label_set_text(ui->print_btn_page_end_label, "");
//	lv_obj_set_style_local_text_color(ui->print_btn_page_end_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes print_btn_page_next
	ui->print_btn_page_next = lv_btn_create(ui->print_cont_print, NULL);

	//Write style LV_BTN_PART_MAIN for print_btn_page_next
	static lv_style_t style_print_btn_page_next_main;
	lv_style_reset(&style_print_btn_page_next_main);
	lv_style_init(&style_print_btn_page_next_main);

	//Write style state: LV_STATE_DEFAULT for style_print_btn_page_next_main
	lv_style_set_radius(&style_print_btn_page_next_main, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_print_btn_page_next_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_print_btn_page_next_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_print_btn_page_next_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_print_btn_page_next_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_print_btn_page_next_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_print_btn_page_next_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_print_btn_page_next_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_print_btn_page_next_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_print_btn_page_next_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->print_btn_page_next, LV_BTN_PART_MAIN, &style_print_btn_page_next_main);
	lv_obj_set_pos(ui->print_btn_page_next, 296, 582);
	lv_obj_set_size(ui->print_btn_page_next, 80, 80);
//	ui->print_btn_page_next_label = lv_label_create(ui->print_btn_page_next, NULL);
//	lv_label_set_text(ui->print_btn_page_next_label, "");
//	lv_obj_set_style_local_text_color(ui->print_btn_page_next_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes print_img_page_next
	ui->print_img_page_next = lv_img_create(ui->print_cont_print, NULL);

	//Write style LV_IMG_PART_MAIN for print_img_page_next
//	static lv_style_t style_print_img_page_next_main;
//	lv_style_reset(&style_print_img_page_next_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_print_img_page_next_main
//	lv_style_set_image_recolor(&style_print_img_page_next_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_print_img_page_next_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_print_img_page_next_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->print_img_page_next, LV_IMG_PART_MAIN, &style_print_img_page_next_main);
	lv_obj_set_pos(ui->print_img_page_next, 320, 605);
	lv_obj_set_size(ui->print_img_page_next, 37, 34);
	lv_obj_set_click(ui->print_img_page_next, true);
	lv_img_set_src(ui->print_img_page_next,&_pagenext_alpha_37x34);
//	lv_img_set_pivot(ui->print_img_page_next, 0,0);
//	lv_img_set_angle(ui->print_img_page_next, 0);

	//Write codes print_btn_page_pre
	ui->print_btn_page_pre = lv_btn_create(ui->print_cont_print, NULL);

	//Write style LV_BTN_PART_MAIN for print_btn_page_pre
	static lv_style_t style_print_btn_page_pre_main;
	lv_style_reset(&style_print_btn_page_pre_main);
	lv_style_init(&style_print_btn_page_pre_main);

	//Write style state: LV_STATE_DEFAULT for style_print_btn_page_pre_main
	lv_style_set_radius(&style_print_btn_page_pre_main, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_print_btn_page_pre_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_print_btn_page_pre_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_print_btn_page_pre_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_print_btn_page_pre_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_print_btn_page_pre_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_print_btn_page_pre_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_print_btn_page_pre_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_print_btn_page_pre_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_print_btn_page_pre_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->print_btn_page_pre, LV_BTN_PART_MAIN, &style_print_btn_page_pre_main);
	lv_obj_set_pos(ui->print_btn_page_pre, 104, 582);
	lv_obj_set_size(ui->print_btn_page_pre, 80, 80);
//	ui->print_btn_page_pre_label = lv_label_create(ui->print_btn_page_pre, NULL);
//	lv_label_set_text(ui->print_btn_page_pre_label, "");
//	lv_obj_set_style_local_text_color(ui->print_btn_page_pre_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes print_img_page_pre
	ui->print_img_page_pre = lv_img_create(ui->print_cont_print, NULL);

	//Write style LV_IMG_PART_MAIN for print_img_page_pre
//	static lv_style_t style_print_img_page_pre_main;
//	lv_style_reset(&style_print_img_page_pre_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_print_img_page_pre_main
//	lv_style_set_image_recolor(&style_print_img_page_pre_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_print_img_page_pre_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_print_img_page_pre_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->print_img_page_pre, LV_IMG_PART_MAIN, &style_print_img_page_pre_main);
	lv_obj_set_pos(ui->print_img_page_pre, 128, 605);
	lv_obj_set_size(ui->print_img_page_pre, 37, 34);
	lv_obj_set_click(ui->print_img_page_pre, true);
	lv_img_set_src(ui->print_img_page_pre,&_pagepre_alpha_37x34);
//	lv_img_set_pivot(ui->print_img_page_pre, 0,0);
//	lv_img_set_angle(ui->print_img_page_pre, 0);

	//Write codes print_img_page_end
	ui->print_img_page_end = lv_img_create(ui->print_cont_print, NULL);

	//Write style LV_IMG_PART_MAIN for print_img_page_end
//	static lv_style_t style_print_img_page_end_main;
//	lv_style_reset(&style_print_img_page_end_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_print_img_page_end_main
//	lv_style_set_image_recolor(&style_print_img_page_end_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_print_img_page_end_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_print_img_page_end_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->print_img_page_end, LV_IMG_PART_MAIN, &style_print_img_page_end_main);
	lv_obj_set_pos(ui->print_img_page_end, 411, 605);
	lv_obj_set_size(ui->print_img_page_end, 34, 34);
	lv_obj_set_click(ui->print_img_page_end, true);
	lv_img_set_src(ui->print_img_page_end,&_pageend_alpha_34x34);
//	lv_img_set_pivot(ui->print_img_page_end, 0,0);
//	lv_img_set_angle(ui->print_img_page_end, 0);

	//Write codes print_btn_page_home
	ui->print_btn_page_home = lv_btn_create(ui->print_cont_print, NULL);

	//Write style LV_BTN_PART_MAIN for print_btn_page_home
	static lv_style_t style_print_btn_page_home_main;
	lv_style_reset(&style_print_btn_page_home_main);
	lv_style_init(&style_print_btn_page_home_main);

	//Write style state: LV_STATE_DEFAULT for style_print_btn_page_home_main
	lv_style_set_radius(&style_print_btn_page_home_main, LV_STATE_DEFAULT, 6);
	lv_style_set_bg_color(&style_print_btn_page_home_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_print_btn_page_home_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_print_btn_page_home_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_print_btn_page_home_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_print_btn_page_home_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_print_btn_page_home_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_print_btn_page_home_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_print_btn_page_home_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_print_btn_page_home_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->print_btn_page_home, LV_BTN_PART_MAIN, &style_print_btn_page_home_main);
	lv_obj_set_pos(ui->print_btn_page_home, 12, 582);
	lv_obj_set_size(ui->print_btn_page_home, 80, 80);
//	ui->print_btn_page_home_label = lv_label_create(ui->print_btn_page_home, NULL);
//	lv_label_set_text(ui->print_btn_page_home_label, "");
//	lv_obj_set_style_local_text_color(ui->print_btn_page_home_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes print_img_page_home
	ui->print_img_page_home = lv_img_create(ui->print_cont_print, NULL);

	//Write style LV_IMG_PART_MAIN for print_img_page_home
//	static lv_style_t style_print_img_page_home_main;
//	lv_style_reset(&style_print_img_page_home_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_print_img_page_home_main
//	lv_style_set_image_recolor(&style_print_img_page_home_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_print_img_page_home_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_print_img_page_home_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->print_img_page_home, LV_IMG_PART_MAIN, &style_print_img_page_home_main);
	lv_obj_set_pos(ui->print_img_page_home, 35, 605);
	lv_obj_set_size(ui->print_img_page_home, 34, 34);
	lv_obj_set_click(ui->print_img_page_home, true);
	lv_img_set_src(ui->print_img_page_home,&_pagehome_alpha_34x34);
//	lv_img_set_pivot(ui->print_img_page_home, 0,0);
//	lv_img_set_angle(ui->print_img_page_home, 0);

	//Write codes print_list_1
	ui->print_list_1 = lv_list_create(ui->print_cont_print, NULL);
	lv_list_set_edge_flash(ui->print_list_1, true);
//	lv_list_set_scroll_propagation(ui->print_list_1, false);
	lv_list_set_scrollbar_mode(ui->print_list_1, LV_SCROLLBAR_MODE_OFF);

	//Write style LV_LIST_PART_BG for print_list_1
	static lv_style_t style_print_list_1_bg;
	lv_style_reset(&style_print_list_1_bg);
	lv_style_init(&style_print_list_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_print_list_1_bg
	lv_style_set_bg_color(&style_print_list_1_bg, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_radius(&style_print_list_1_bg, LV_STATE_DEFAULT, 3);
//	lv_style_set_border_color(&style_print_list_1_bg, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_print_list_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_left(&style_print_list_1_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_print_list_1_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_print_list_1_bg, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->print_list_1, LV_LIST_PART_BG, &style_print_list_1_bg);

	//Write style LV_LIST_PART_SCROLLABLE for print_list_1
	static lv_style_t style_print_list_1_scrollable;
	lv_style_reset(&style_print_list_1_scrollable);
	lv_style_init(&style_print_list_1_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_print_list_1_scrollable
	lv_style_set_radius(&style_print_list_1_scrollable, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_print_list_1_scrollable, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_print_list_1_scrollable, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_print_list_1_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_print_list_1_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->print_list_1, LV_LIST_PART_SCROLLABLE, &style_print_list_1_scrollable);

	//Write style LV_BTN_PART_MAIN for print_list_1
//	static lv_style_t style_print_list_1_main_child;
//	lv_style_reset(&style_print_list_1_main_child);
//
//	//Write style state: LV_STATE_DEFAULT for style_print_list_1_main_child
//	lv_style_set_radius(&style_print_list_1_main_child, LV_STATE_DEFAULT, 3);
//	lv_style_set_bg_color(&style_print_list_1_main_child, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_print_list_1_main_child, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_print_list_1_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_print_list_1_main_child, LV_STATE_DEFAULT, 255);
//	lv_style_set_text_color(&style_print_list_1_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_text_font(&style_print_list_1_main_child, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_obj_set_pos(ui->print_list_1, 10, 80);
	lv_obj_set_size(ui->print_list_1, 460, 490);

	//Write codes print_arc_1
	ui->print_arc_s = lv_arc_create(ui->print_cont_print, NULL);

	//Write style LV_ARC_PART_BG for print_arc_s
	static lv_style_t style_print_arc_s_bg;
	lv_style_reset(&style_print_arc_s_bg);
	lv_style_init(&style_print_arc_s_bg);

	//Write style state: LV_STATE_DEFAULT for style_print_arc_s_bg
//	lv_style_set_bg_color(&style_print_arc_s_bg, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_print_arc_s_bg, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_print_arc_s_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_print_arc_s_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_width(&style_print_arc_s_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_line_color(&style_print_arc_s_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_line_width(&style_print_arc_s_bg, LV_STATE_DEFAULT, 16);
	lv_obj_add_style(ui->print_arc_s, LV_ARC_PART_BG, &style_print_arc_s_bg);

	//Write style LV_ARC_PART_INDIC for print_arc_s
	static lv_style_t style_print_arc_s_indic;
	lv_style_reset(&style_print_arc_s_indic);
	lv_style_init(&style_print_arc_s_indic);

	//Write style state: LV_STATE_DEFAULT for style_print_arc_s_indic
	lv_style_set_line_color(&style_print_arc_s_indic, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_line_width(&style_print_arc_s_indic, LV_STATE_DEFAULT, 16);
	lv_obj_add_style(ui->print_arc_s, LV_ARC_PART_INDIC, &style_print_arc_s_indic);
	lv_obj_set_pos(ui->print_arc_s, 130, 220);
	lv_obj_set_size(ui->print_arc_s, 220, 220);
	lv_arc_set_bg_angles(ui->print_arc_s, 0, 360);
	lv_arc_set_angles(ui->print_arc_s, 360, 360);
	lv_arc_set_rotation(ui->print_arc_s, 270);
	lv_obj_set_style_local_pad_top(ui->print_arc_s, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_bottom(ui->print_arc_s, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_left(ui->print_arc_s, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_right(ui->print_arc_s, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_line_rounded(ui->print_arc_s, LV_ARC_PART_INDIC, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_line_rounded(ui->print_arc_s, LV_ARC_PART_BG, LV_STATE_DEFAULT, 0);

	//Write codes print_label_2
	ui->print_label_2 = lv_label_create(ui->print_cont_print, NULL);
	lv_label_set_text(ui->print_label_2, "Loading...");
	lv_label_set_long_mode(ui->print_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->print_label_2, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for print_label_2
	static lv_style_t style_print_label_2_main;
	lv_style_reset(&style_print_label_2_main);
	lv_style_init(&style_print_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_print_label_2_main
	lv_style_set_radius(&style_print_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_print_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_print_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_print_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_print_label_2_main, LV_STATE_DEFAULT, 3);
	lv_style_set_text_color(&style_print_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_print_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_print_label_2_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_print_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_print_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_print_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_print_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->print_label_2, LV_LABEL_PART_MAIN, &style_print_label_2_main);
	lv_obj_set_pos(ui->print_label_2, 174, 320);
	lv_obj_set_size(ui->print_label_2, 140, 0);

	//Write codes print_label_1
	ui->print_label_1 = lv_label_create(ui->print_cont_print, NULL);
	lv_label_set_text(ui->print_label_1, "请选择打印文件");
	lv_label_set_long_mode(ui->print_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->print_label_1, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for print_label_1
	static lv_style_t style_print_label_1_main;
	lv_style_reset(&style_print_label_1_main);
	lv_style_init(&style_print_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_print_label_1_main
	lv_style_set_radius(&style_print_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_print_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_print_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_print_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_print_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_print_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_print_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_print_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_print_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_print_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_print_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_print_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->print_label_1, LV_LABEL_PART_MAIN, &style_print_label_1_main);
	lv_obj_set_pos(ui->print_label_1, 48, 31);
	lv_obj_set_size(ui->print_label_1, 380, 0);
	lv_cont_set_layout(ui->print_cont_print, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->print_cont_print, LV_FIT_NONE);

	//Init events for screen
	events_init_print(ui);
}
