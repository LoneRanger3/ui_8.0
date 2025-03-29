/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_Inputboxs(lv_ui *ui){

	//Write codes Inputboxs
//	ui->Inputboxs = lv_obj_create(NULL, NULL);

	//Write codes Inputboxs_cont_inputboxs
	ui->Inputboxs_cont_inputboxs = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for Inputboxs_cont_inputboxs
	static lv_style_t style_Inputboxs_cont_inputboxs_main;
	lv_style_reset(&style_Inputboxs_cont_inputboxs_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_cont_inputboxs_main
	lv_style_set_radius(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Inputboxs_cont_inputboxs_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Inputboxs_cont_inputboxs, LV_CONT_PART_MAIN, &style_Inputboxs_cont_inputboxs_main);
	lv_obj_set_pos(ui->Inputboxs_cont_inputboxs, 0, 0);
	lv_obj_set_size(ui->Inputboxs_cont_inputboxs, 480, 800);
	lv_obj_set_click(ui->Inputboxs_cont_inputboxs, false);

	//Write codes Inputboxs_btn_1
	ui->Inputboxs_btn_1 = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_1
	static lv_style_t style_Inputboxs_btn_1_main;
	lv_style_reset(&style_Inputboxs_btn_1_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_1_main
	lv_style_set_radius(&style_Inputboxs_btn_1_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Inputboxs_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_1_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Inputboxs_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_Inputboxs_btn_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Inputboxs_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_outline_opa(&style_Inputboxs_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_1, LV_BTN_PART_MAIN, &style_Inputboxs_btn_1_main);
	lv_obj_set_pos(ui->Inputboxs_btn_1, 0, 362);
	lv_obj_set_size(ui->Inputboxs_btn_1, 480, 438);
//	ui->Inputboxs_btn_1_label = lv_label_create(ui->Inputboxs_btn_1, NULL);
//	lv_label_set_text(ui->Inputboxs_btn_1_label, "");
//	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Inputboxs_btn_input
	ui->Inputboxs_btn_input = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_input
	static lv_style_t style_Inputboxs_btn_input_main;
	lv_style_reset(&style_Inputboxs_btn_input_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_input_main
	lv_style_set_radius(&style_Inputboxs_btn_input_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_input_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_input_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_input_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_input_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_input_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_input_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_input_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_input_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_input_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_input, LV_BTN_PART_MAIN, &style_Inputboxs_btn_input_main);
	lv_obj_set_pos(ui->Inputboxs_btn_input, 17, 385);
	lv_obj_set_size(ui->Inputboxs_btn_input, 446, 63);
	ui->Inputboxs_btn_input_label = lv_label_create(ui->Inputboxs_btn_input, NULL);
	lv_label_set_text(ui->Inputboxs_btn_input_label, "123");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_input_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_input_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_backspace
	ui->Inputboxs_btn_backspace = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_backspace
	static lv_style_t style_Inputboxs_btn_backspace_main;
	lv_style_reset(&style_Inputboxs_btn_backspace_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_backspace_main
	lv_style_set_radius(&style_Inputboxs_btn_backspace_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_backspace_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_backspace_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_backspace_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_backspace_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_backspace_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_backspace_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_backspace_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_backspace_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_backspace_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_backspace, LV_BTN_PART_MAIN, &style_Inputboxs_btn_backspace_main);
	lv_obj_set_pos(ui->Inputboxs_btn_backspace, 356, 465);
	lv_obj_set_size(ui->Inputboxs_btn_backspace, 107, 72);
//	ui->Inputboxs_btn_backspace_label = lv_label_create(ui->Inputboxs_btn_backspace, NULL);
//	lv_label_set_text(ui->Inputboxs_btn_backspace_label, "");
//	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_backspace_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Inputboxs_img_2
	ui->Inputboxs_img_2 = lv_img_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_IMG_PART_MAIN for Inputboxs_img_2
//	static lv_style_t style_Inputboxs_img_2_main;
//	lv_style_reset(&style_Inputboxs_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_img_2_main
//	lv_style_set_image_recolor(&style_Inputboxs_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Inputboxs_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Inputboxs_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Inputboxs_img_2, LV_IMG_PART_MAIN, &style_Inputboxs_img_2_main);
	lv_obj_set_pos(ui->Inputboxs_img_2, 382, 483);
//	lv_obj_set_size(ui->Inputboxs_img_2, 54, 38);
//	lv_obj_set_click(ui->Inputboxs_img_2, true);
	lv_img_set_src(ui->Inputboxs_img_2,&_backspace_alpha_54x38);
//	lv_img_set_pivot(ui->Inputboxs_img_2, 0,0);
//	lv_img_set_angle(ui->Inputboxs_img_2, 0);

	//Write codes Inputboxs_btn_confirm
	ui->Inputboxs_btn_confirm = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_confirm
	static lv_style_t style_Inputboxs_btn_confirm_main;
	lv_style_reset(&style_Inputboxs_btn_confirm_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_confirm_main
	lv_style_set_radius(&style_Inputboxs_btn_confirm_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_confirm_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_confirm_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_confirm_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_confirm_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_confirm_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_confirm_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_confirm_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_confirm_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_confirm_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_confirm, LV_BTN_PART_MAIN, &style_Inputboxs_btn_confirm_main);
	lv_obj_set_pos(ui->Inputboxs_btn_confirm, 356, 623);
	lv_obj_set_size(ui->Inputboxs_btn_confirm, 107, 151);
//	ui->Inputboxs_btn_confirm_label = lv_label_create(ui->Inputboxs_btn_confirm, NULL);
//	lv_label_set_text(ui->Inputboxs_btn_confirm_label, "");
//	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_confirm_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Inputboxs_line_2
	ui->Inputboxs_line_2 = lv_line_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_LINE_PART_MAIN for Inputboxs_line_2
	static lv_style_t style_Inputboxs_line_2_main;
	lv_style_reset(&style_Inputboxs_line_2_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_line_2_main
	lv_style_set_line_color(&style_Inputboxs_line_2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_line_width(&style_Inputboxs_line_2_main, LV_STATE_DEFAULT, 7);
	lv_obj_add_style(ui->Inputboxs_line_2, LV_LINE_PART_MAIN, &style_Inputboxs_line_2_main);
	lv_obj_set_pos(ui->Inputboxs_line_2, 402, 679);
	lv_obj_set_size(ui->Inputboxs_line_2, 32, 32);
	static lv_point_t Inputboxs_line_2[] ={{29,0},{0,30}};
	lv_line_set_points(ui->Inputboxs_line_2,Inputboxs_line_2,2);

	//Write codes Inputboxs_line_1
	ui->Inputboxs_line_1 = lv_line_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_LINE_PART_MAIN for Inputboxs_line_1
	static lv_style_t style_Inputboxs_line_1_main;
	lv_style_reset(&style_Inputboxs_line_1_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_line_1_main
	lv_style_set_line_color(&style_Inputboxs_line_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_line_width(&style_Inputboxs_line_1_main, LV_STATE_DEFAULT, 7);
	lv_obj_add_style(ui->Inputboxs_line_1, LV_LINE_PART_MAIN, &style_Inputboxs_line_1_main);
	lv_obj_set_pos(ui->Inputboxs_line_1, 387, 692);
	lv_obj_set_size(ui->Inputboxs_line_1, 20, 20);
	static lv_point_t Inputboxs_line_1[] ={{0,0},{18,18}};
	lv_line_set_points(ui->Inputboxs_line_1,Inputboxs_line_1,2);

	//Write codes Inputboxs_btn_esc
	ui->Inputboxs_btn_esc = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_esc
	static lv_style_t style_Inputboxs_btn_esc_main;
	lv_style_reset(&style_Inputboxs_btn_esc_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_esc_main
	lv_style_set_radius(&style_Inputboxs_btn_esc_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_esc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_esc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_esc_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_esc_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_esc_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_esc_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_esc_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_esc_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_esc_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_esc, LV_BTN_PART_MAIN, &style_Inputboxs_btn_esc_main);
	lv_obj_set_pos(ui->Inputboxs_btn_esc, 356, 544);
	lv_obj_set_size(ui->Inputboxs_btn_esc, 107, 72);
	ui->Inputboxs_btn_esc_label = lv_label_create(ui->Inputboxs_btn_esc, NULL);
	lv_label_set_text(ui->Inputboxs_btn_esc_label, "ESC");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_esc_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_esc_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_num3
	ui->Inputboxs_btn_num3 = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_num3
	static lv_style_t style_Inputboxs_btn_num3_main;
	lv_style_reset(&style_Inputboxs_btn_num3_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_num3_main
	lv_style_set_radius(&style_Inputboxs_btn_num3_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_num3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_num3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_num3_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_num3_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_num3_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_num3_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_num3_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_num3_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_num3_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_num3, LV_BTN_PART_MAIN, &style_Inputboxs_btn_num3_main);
	lv_obj_set_pos(ui->Inputboxs_btn_num3, 243, 465);
	lv_obj_set_size(ui->Inputboxs_btn_num3, 107, 72);
	ui->Inputboxs_btn_num3_label = lv_label_create(ui->Inputboxs_btn_num3, NULL);
	lv_label_set_text(ui->Inputboxs_btn_num3_label, "3");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_num3_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_num3_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_num2
	ui->Inputboxs_btn_num2 = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_num2
	static lv_style_t style_Inputboxs_btn_num2_main;
	lv_style_reset(&style_Inputboxs_btn_num2_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_num2_main
	lv_style_set_radius(&style_Inputboxs_btn_num2_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_num2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_num2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_num2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_num2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_num2_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_num2_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_num2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_num2_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_num2_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_num2, LV_BTN_PART_MAIN, &style_Inputboxs_btn_num2_main);
	lv_obj_set_pos(ui->Inputboxs_btn_num2, 130, 465);
	lv_obj_set_size(ui->Inputboxs_btn_num2, 107, 72);
	ui->Inputboxs_btn_num2_label = lv_label_create(ui->Inputboxs_btn_num2, NULL);
	lv_label_set_text(ui->Inputboxs_btn_num2_label, "2");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_num2_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_num2_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_num1
	ui->Inputboxs_btn_num1 = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_num1
	static lv_style_t style_Inputboxs_btn_num1_main;
	lv_style_reset(&style_Inputboxs_btn_num1_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_num1_main
	lv_style_set_radius(&style_Inputboxs_btn_num1_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_num1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_num1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_num1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_num1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_num1_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_num1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_num1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_num1_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_num1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_num1, LV_BTN_PART_MAIN, &style_Inputboxs_btn_num1_main);
	lv_obj_set_pos(ui->Inputboxs_btn_num1, 17, 465);
	lv_obj_set_size(ui->Inputboxs_btn_num1, 107, 72);
	ui->Inputboxs_btn_num1_label = lv_label_create(ui->Inputboxs_btn_num1, NULL);
	lv_label_set_text(ui->Inputboxs_btn_num1_label, "1");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_num1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_num1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_num6
	ui->Inputboxs_btn_num6 = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_num6
	static lv_style_t style_Inputboxs_btn_num6_main;
	lv_style_reset(&style_Inputboxs_btn_num6_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_num6_main
	lv_style_set_radius(&style_Inputboxs_btn_num6_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_num6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_num6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_num6_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_num6_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_num6_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_num6_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_num6_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_num6_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_num6_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_num6, LV_BTN_PART_MAIN, &style_Inputboxs_btn_num6_main);
	lv_obj_set_pos(ui->Inputboxs_btn_num6, 243, 544);
	lv_obj_set_size(ui->Inputboxs_btn_num6, 107, 72);
	ui->Inputboxs_btn_num6_label = lv_label_create(ui->Inputboxs_btn_num6, NULL);
	lv_label_set_text(ui->Inputboxs_btn_num6_label, "6");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_num6_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_num6_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_num5
	ui->Inputboxs_btn_num5 = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_num5
	static lv_style_t style_Inputboxs_btn_num5_main;
	lv_style_reset(&style_Inputboxs_btn_num5_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_num5_main
	lv_style_set_radius(&style_Inputboxs_btn_num5_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_num5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_num5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_num5_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_num5_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_num5_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_num5_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_num5_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_num5_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_num5_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_num5, LV_BTN_PART_MAIN, &style_Inputboxs_btn_num5_main);
	lv_obj_set_pos(ui->Inputboxs_btn_num5, 130, 544);
	lv_obj_set_size(ui->Inputboxs_btn_num5, 107, 72);
	ui->Inputboxs_btn_num5_label = lv_label_create(ui->Inputboxs_btn_num5, NULL);
	lv_label_set_text(ui->Inputboxs_btn_num5_label, "5");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_num5_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_num5_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_num4
	ui->Inputboxs_btn_num4 = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_num4
	static lv_style_t style_Inputboxs_btn_num4_main;
	lv_style_reset(&style_Inputboxs_btn_num4_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_num4_main
	lv_style_set_radius(&style_Inputboxs_btn_num4_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_num4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_num4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_num4_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_num4_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_num4_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_num4_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_num4_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_num4_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_num4_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_num4, LV_BTN_PART_MAIN, &style_Inputboxs_btn_num4_main);
	lv_obj_set_pos(ui->Inputboxs_btn_num4, 17, 544);
	lv_obj_set_size(ui->Inputboxs_btn_num4, 107, 72);
	ui->Inputboxs_btn_num4_label = lv_label_create(ui->Inputboxs_btn_num4, NULL);
	lv_label_set_text(ui->Inputboxs_btn_num4_label, "4");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_num4_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_num4_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_num8
	ui->Inputboxs_btn_num8 = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_num8
	static lv_style_t style_Inputboxs_btn_num8_main;
	lv_style_reset(&style_Inputboxs_btn_num8_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_num8_main
	lv_style_set_radius(&style_Inputboxs_btn_num8_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_num8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_num8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_num8_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_num8_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_num8_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_num8_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_num8_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_num8_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_num8_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_num8, LV_BTN_PART_MAIN, &style_Inputboxs_btn_num8_main);
	lv_obj_set_pos(ui->Inputboxs_btn_num8, 130, 623);
	lv_obj_set_size(ui->Inputboxs_btn_num8, 107, 72);
	ui->Inputboxs_btn_num8_label = lv_label_create(ui->Inputboxs_btn_num8, NULL);
	lv_label_set_text(ui->Inputboxs_btn_num8_label, "8");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_num8_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_num8_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_num9
	ui->Inputboxs_btn_num9 = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_num9
	static lv_style_t style_Inputboxs_btn_num9_main;
	lv_style_reset(&style_Inputboxs_btn_num9_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_num9_main
	lv_style_set_radius(&style_Inputboxs_btn_num9_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_num9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_num9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_num9_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_num9_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_num9_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_num9_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_num9_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_num9_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_num9_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_num9, LV_BTN_PART_MAIN, &style_Inputboxs_btn_num9_main);
	lv_obj_set_pos(ui->Inputboxs_btn_num9, 243, 623);
	lv_obj_set_size(ui->Inputboxs_btn_num9, 107, 72);
	ui->Inputboxs_btn_num9_label = lv_label_create(ui->Inputboxs_btn_num9, NULL);
	lv_label_set_text(ui->Inputboxs_btn_num9_label, "9");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_num9_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_num9_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_num7
	ui->Inputboxs_btn_num7 = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_num7
	static lv_style_t style_Inputboxs_btn_num7_main;
	lv_style_reset(&style_Inputboxs_btn_num7_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_num7_main
	lv_style_set_radius(&style_Inputboxs_btn_num7_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_num7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_num7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_num7_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_num7_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_num7_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_num7_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_num7_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_num7_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_num7_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_num7, LV_BTN_PART_MAIN, &style_Inputboxs_btn_num7_main);
	lv_obj_set_pos(ui->Inputboxs_btn_num7, 17, 623);
	lv_obj_set_size(ui->Inputboxs_btn_num7, 107, 72);
	ui->Inputboxs_btn_num7_label = lv_label_create(ui->Inputboxs_btn_num7, NULL);
	lv_label_set_text(ui->Inputboxs_btn_num7_label, "7");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_num7_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_num7_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_dot
	ui->Inputboxs_btn_dot = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_dot
	static lv_style_t style_Inputboxs_btn_dot_main;
	lv_style_reset(&style_Inputboxs_btn_dot_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_dot_main
	lv_style_set_radius(&style_Inputboxs_btn_dot_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_dot_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_dot_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_dot_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_dot_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_dot_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_dot_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_dot_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_dot_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_dot_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_dot, LV_BTN_PART_MAIN, &style_Inputboxs_btn_dot_main);
	lv_obj_set_pos(ui->Inputboxs_btn_dot, 243, 702);
	lv_obj_set_size(ui->Inputboxs_btn_dot, 107, 72);
	ui->Inputboxs_btn_dot_label = lv_label_create(ui->Inputboxs_btn_dot, NULL);
	lv_label_set_text(ui->Inputboxs_btn_dot_label, ".");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_dot_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_dot_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_num0
	ui->Inputboxs_btn_num0 = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_num0
	static lv_style_t style_Inputboxs_btn_num0_main;
	lv_style_reset(&style_Inputboxs_btn_num0_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_num0_main
	lv_style_set_radius(&style_Inputboxs_btn_num0_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_num0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_num0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_num0_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_num0_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_num0_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_num0_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_num0_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_num0_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_num0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_num0, LV_BTN_PART_MAIN, &style_Inputboxs_btn_num0_main);
	lv_obj_set_pos(ui->Inputboxs_btn_num0, 130, 702);
	lv_obj_set_size(ui->Inputboxs_btn_num0, 107, 72);
	ui->Inputboxs_btn_num0_label = lv_label_create(ui->Inputboxs_btn_num0, NULL);
	lv_label_set_text(ui->Inputboxs_btn_num0_label, "0");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_num0_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_num0_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes Inputboxs_btn_neg
	ui->Inputboxs_btn_neg = lv_btn_create(ui->Inputboxs_cont_inputboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Inputboxs_btn_neg
	static lv_style_t style_Inputboxs_btn_neg_main;
	lv_style_reset(&style_Inputboxs_btn_neg_main);

	//Write style state: LV_STATE_DEFAULT for style_Inputboxs_btn_neg_main
	lv_style_set_radius(&style_Inputboxs_btn_neg_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_Inputboxs_btn_neg_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Inputboxs_btn_neg_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Inputboxs_btn_neg_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Inputboxs_btn_neg_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Inputboxs_btn_neg_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Inputboxs_btn_neg_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Inputboxs_btn_neg_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Inputboxs_btn_neg_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_Inputboxs_btn_neg_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Inputboxs_btn_neg, LV_BTN_PART_MAIN, &style_Inputboxs_btn_neg_main);
	lv_obj_set_pos(ui->Inputboxs_btn_neg, 17, 702);
	lv_obj_set_size(ui->Inputboxs_btn_neg, 107, 72);
	ui->Inputboxs_btn_neg_label = lv_label_create(ui->Inputboxs_btn_neg, NULL);
	lv_label_set_text(ui->Inputboxs_btn_neg_label, "-");
	lv_obj_set_style_local_text_color(ui->Inputboxs_btn_neg_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->Inputboxs_btn_neg_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_cont_set_layout(ui->Inputboxs_cont_inputboxs, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->Inputboxs_cont_inputboxs, LV_FIT_NONE);

	//Init events for screen
	events_init_Inputboxs(ui);
}
