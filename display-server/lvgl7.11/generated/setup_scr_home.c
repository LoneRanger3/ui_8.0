/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_home(lv_ui *ui){

	//Write codes home
//	ui->home = lv_obj_create(NULL, NULL);

	//Write codes home_cont_home
	if(ui->home_cont_home != NULL)
    {
        return;
    }
	ui->home_cont_home = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for home_cont_home
	static lv_style_t style_home_cont_home_main;
	lv_style_reset(&style_home_cont_home_main);
	lv_style_init(&style_home_cont_home_main);

	//Write style state: LV_STATE_DEFAULT for style_home_cont_home_main
	lv_style_set_radius(&style_home_cont_home_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_cont_home_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_home_cont_home_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_home_cont_home_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_cont_home_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_home_cont_home_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_home_cont_home_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_home_cont_home_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_home_cont_home_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_cont_home_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_cont_home_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_cont_home_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_cont_home, LV_CONT_PART_MAIN, &style_home_cont_home_main);
	lv_obj_set_pos(ui->home_cont_home, 0, 0);
	lv_obj_set_size(ui->home_cont_home, 480, 674);
	lv_obj_set_click(ui->home_cont_home, false);

	//Write codes home_img_model
	ui->home_img_model = lv_img_create(ui->home_cont_home, NULL);

	//Write style LV_IMG_PART_MAIN for home_img_model
//	static lv_style_t style_home_img_model_main;
//	lv_style_reset(&style_home_img_model_main);

	//Write style state: LV_STATE_DEFAULT for style_home_img_model_main
//	lv_style_set_image_recolor(&style_home_img_model_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_home_img_model_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_home_img_model_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->home_img_model, LV_IMG_PART_MAIN, &style_home_img_model_main);
	lv_obj_set_pos(ui->home_img_model, 90, 258);
	lv_obj_set_size(ui->home_img_model, 300, 300);

	//Write codes home_btn_mask
	ui->home_btn_mask = lv_btn_create(ui->home_cont_home, NULL);

	//Write style LV_BTN_PART_MAIN for home_btn_mask
	static lv_style_t style_home_btn_mask_main;
	lv_style_reset(&style_home_btn_mask_main);
	lv_style_init(&style_home_btn_mask_main);

	//Write style state: LV_STATE_DEFAULT for style_home_btn_mask_main
	lv_style_set_radius(&style_home_btn_mask_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_btn_mask_main, LV_STATE_DEFAULT, lv_color_make(0xbe, 0xff, 0xb4));
//	lv_style_set_bg_grad_color(&style_home_btn_mask_main, LV_STATE_DEFAULT, lv_color_make(0xbe, 0xff, 0xb4));
//	lv_style_set_bg_grad_dir(&style_home_btn_mask_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_btn_mask_main, LV_STATE_DEFAULT, 180);
//	lv_style_set_border_color(&style_home_btn_mask_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_home_btn_mask_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_home_btn_mask_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_outline_color(&style_home_btn_mask_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
//	lv_style_set_outline_opa(&style_home_btn_mask_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->home_btn_mask, LV_BTN_PART_MAIN, &style_home_btn_mask_main);
	lv_obj_set_pos(ui->home_btn_mask, 90, 258);
	lv_obj_set_size(ui->home_btn_mask, 300, 300);
	lv_obj_set_click(ui->home_btn_mask, false);
//	ui->home_btn_mask_label = lv_label_create(ui->home_btn_mask, NULL);
//	lv_label_set_text(ui->home_btn_mask_label, "");
//	lv_obj_set_style_local_text_color(ui->home_btn_mask_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes home_btn_background
	ui->home_btn_background = lv_btn_create(ui->home_cont_home, NULL);

	//Write style LV_BTN_PART_MAIN for home_btn_background
	static lv_style_t style_home_btn_background_main;
	lv_style_reset(&style_home_btn_background_main);
	lv_style_init(&style_home_btn_background_main);

	//Write style state: LV_STATE_DEFAULT for style_home_btn_background_main
	lv_style_set_radius(&style_home_btn_background_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_home_btn_background_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_home_btn_background_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_home_btn_background_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_btn_background_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_home_btn_background_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_home_btn_background_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_home_btn_background_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_home_btn_background_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_outline_opa(&style_home_btn_background_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->home_btn_background, LV_BTN_PART_MAIN, &style_home_btn_background_main);
	lv_obj_set_pos(ui->home_btn_background, 32, 571);
	lv_obj_set_size(ui->home_btn_background, 416, 82);
//	ui->home_btn_background_label = lv_label_create(ui->home_btn_background, NULL);
//	lv_label_set_text(ui->home_btn_background_label, "");
//	lv_obj_set_style_local_text_color(ui->home_btn_background_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes home_img_finish
	ui->home_img_finish = lv_img_create(ui->home_cont_home, NULL);

	//Write style LV_IMG_PART_MAIN for home_img_finish
//	static lv_style_t style_home_img_finish_main;
//	lv_style_reset(&style_home_img_finish_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_home_img_finish_main
//	lv_style_set_image_recolor(&style_home_img_finish_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_home_img_finish_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_home_img_finish_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->home_img_finish, LV_IMG_PART_MAIN, &style_home_img_finish_main);
	lv_obj_set_pos(ui->home_img_finish, 219, 598);
//	lv_obj_set_size(ui->home_img_finish, 42, 28);
	lv_obj_set_click(ui->home_img_finish, true);
	lv_img_set_src(ui->home_img_finish,&_finish_alpha_42x28);
//	lv_img_set_pivot(ui->home_img_finish, 0,0);
//	lv_img_set_angle(ui->home_img_finish, 0);

	//Write codes home_img_logo
	ui->home_img_logo = lv_img_create(ui->home_cont_home, NULL);

	//Write style LV_IMG_PART_MAIN for home_img_logo
//	static lv_style_t style_home_img_logo_main;
//	lv_style_reset(&style_home_img_logo_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_home_img_logo_main
//	lv_style_set_image_recolor(&style_home_img_logo_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_home_img_logo_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_home_img_logo_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->home_img_logo, LV_IMG_PART_MAIN, &style_home_img_logo_main);
	lv_obj_set_pos(ui->home_img_logo, 106, 213);
//	lv_obj_set_size(ui->home_img_logo, 268, 36);
//	lv_obj_set_click(ui->home_img_logo, true);
	lv_img_set_src(ui->home_img_logo,&_LOGO1_alpha_268x36);
//	lv_img_set_pivot(ui->home_img_logo, 0,0);
//	lv_img_set_angle(ui->home_img_logo, 0);

	//Write codes home_img_start
	ui->home_img_start = lv_img_create(ui->home_cont_home, NULL);

	//Write style LV_IMG_PART_MAIN for home_img_start
//	static lv_style_t style_home_img_start_main;
//	lv_style_reset(&style_home_img_start_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_home_img_start_main
//	lv_style_set_image_recolor(&style_home_img_start_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_home_img_start_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_home_img_start_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->home_img_start, LV_IMG_PART_MAIN, &style_home_img_start_main);
	lv_obj_set_pos(ui->home_img_start, 334, 597);
//	lv_obj_set_size(ui->home_img_start, 25, 28);
	lv_obj_set_click(ui->home_img_start, true);
	lv_img_set_src(ui->home_img_start,&_start_alpha_25x28);
//	lv_img_set_pivot(ui->home_img_start, 0,0);
//	lv_img_set_angle(ui->home_img_start, 0);

	//Write codes home_img_pause
	ui->home_img_pause = lv_img_create(ui->home_cont_home, NULL);

	//Write style LV_IMG_PART_MAIN for home_img_pause
//	static lv_style_t style_home_img_pause_main;
//	lv_style_reset(&style_home_img_pause_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_home_img_pause_main
//	lv_style_set_image_recolor(&style_home_img_pause_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_home_img_pause_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_home_img_pause_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->home_img_pause, LV_IMG_PART_MAIN, &style_home_img_pause_main);
	lv_obj_set_pos(ui->home_img_pause, 335, 598);
//	lv_obj_set_size(ui->home_img_pause, 27, 27);
	lv_obj_set_click(ui->home_img_pause, true);
	lv_img_set_src(ui->home_img_pause,&_pause_alpha_27x27);
//	lv_img_set_pivot(ui->home_img_pause, 0,0);
//	lv_img_set_angle(ui->home_img_pause, 0);

	//Write codes home_btn_printing
	ui->home_btn_printing = lv_btn_create(ui->home_cont_home, NULL);

	//Write style LV_BTN_PART_MAIN for home_btn_printing
	static lv_style_t style_home_btn_printing_main;
	lv_style_reset(&style_home_btn_printing_main);
	lv_style_init(&style_home_btn_printing_main);

	//Write style state: LV_STATE_DEFAULT for style_home_btn_printing_main
	lv_style_set_radius(&style_home_btn_printing_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_home_btn_printing_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_home_btn_printing_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_home_btn_printing_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_btn_printing_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_color(&style_home_btn_printing_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_home_btn_printing_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_home_btn_printing_main, LV_STATE_DEFAULT, 0);
	lv_style_set_outline_color(&style_home_btn_printing_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_home_btn_printing_main, LV_STATE_DEFAULT, 0);

	//Write style state: LV_STATE_PRESSED for style_home_btn_printing_main
	lv_style_set_radius(&style_home_btn_printing_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_home_btn_printing_main, LV_STATE_PRESSED, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_home_btn_printing_main, LV_STATE_PRESSED, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_home_btn_printing_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_btn_printing_main, LV_STATE_PRESSED, 0);
//	lv_style_set_border_color(&style_home_btn_printing_main, LV_STATE_PRESSED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_home_btn_printing_main, LV_STATE_PRESSED, 0);
//	lv_style_set_border_opa(&style_home_btn_printing_main, LV_STATE_PRESSED, 0);
	lv_style_set_outline_color(&style_home_btn_printing_main, LV_STATE_PRESSED, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_home_btn_printing_main, LV_STATE_PRESSED, 0);

	//Write style state: LV_STATE_CHECKED for style_home_btn_printing_main
	lv_style_set_radius(&style_home_btn_printing_main, LV_STATE_CHECKED, 16);
	lv_style_set_bg_color(&style_home_btn_printing_main, LV_STATE_CHECKED, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_home_btn_printing_main, LV_STATE_CHECKED, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_home_btn_printing_main, LV_STATE_CHECKED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_btn_printing_main, LV_STATE_CHECKED, 0);
//	lv_style_set_border_color(&style_home_btn_printing_main, LV_STATE_CHECKED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_home_btn_printing_main, LV_STATE_CHECKED, 0);
//	lv_style_set_border_opa(&style_home_btn_printing_main, LV_STATE_CHECKED, 0);
	lv_style_set_outline_color(&style_home_btn_printing_main, LV_STATE_CHECKED, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_home_btn_printing_main, LV_STATE_CHECKED, 0);
	lv_obj_add_style(ui->home_btn_printing, LV_BTN_PART_MAIN, &style_home_btn_printing_main);
	lv_obj_set_pos(ui->home_btn_printing, 10, 38);
	lv_obj_set_size(ui->home_btn_printing, 460, 130);
//	ui->home_btn_printing_label = lv_label_create(ui->home_btn_printing, NULL);
//	lv_label_set_text(ui->home_btn_printing_label, "default");
//	lv_obj_set_style_local_text_color(ui->home_btn_printing_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
//	lv_obj_set_style_local_text_font(ui->home_btn_printing_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_18);

	//Write codes home_btn_stop
	ui->home_btn_stop = lv_btn_create(ui->home_cont_home, NULL);

	//Write style LV_BTN_PART_MAIN for home_btn_stop
	static lv_style_t style_home_btn_stop_main;
	lv_style_reset(&style_home_btn_stop_main);
	lv_style_init(&style_home_btn_stop_main);

	//Write style state: LV_STATE_DEFAULT for style_home_btn_stop_main
	lv_style_set_radius(&style_home_btn_stop_main, LV_STATE_DEFAULT, 1);
	lv_style_set_bg_color(&style_home_btn_stop_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_home_btn_stop_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_home_btn_stop_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_btn_stop_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_home_btn_stop_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_home_btn_stop_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_home_btn_stop_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_home_btn_stop_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_home_btn_stop_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->home_btn_stop, LV_BTN_PART_MAIN, &style_home_btn_stop_main);
	lv_obj_set_pos(ui->home_btn_stop, 118, 601);
	lv_obj_set_size(ui->home_btn_stop, 25, 23);
//	ui->home_btn_stop_label = lv_label_create(ui->home_btn_stop, NULL);
//	lv_label_set_text(ui->home_btn_stop_label, "");
//	lv_obj_set_style_local_text_color(ui->home_btn_stop_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes home_line_fenge
	ui->home_line_fenge = lv_line_create(ui->home_cont_home, NULL);

	//Write style LV_LINE_PART_MAIN for home_line_fenge
	static lv_style_t style_home_line_fenge_main;
	lv_style_reset(&style_home_line_fenge_main);
	lv_style_init(&style_home_line_fenge_main);

	//Write style state: LV_STATE_DEFAULT for style_home_line_fenge_main
	lv_style_set_line_color(&style_home_line_fenge_main, LV_STATE_DEFAULT, lv_color_make(0x39, 0x3e, 0x46));
	lv_style_set_line_width(&style_home_line_fenge_main, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->home_line_fenge, LV_LINE_PART_MAIN, &style_home_line_fenge_main);
	lv_obj_set_pos(ui->home_line_fenge, 239, 588);
	lv_obj_set_size(ui->home_line_fenge, 2, 48);
	static lv_point_t home_line_fenge[] ={{0,0},{0,48}};
	lv_line_set_points(ui->home_line_fenge,home_line_fenge,2);

	//Write codes home_img_12
	ui->home_img_12 = lv_img_create(ui->home_cont_home, NULL);

	//Write style LV_IMG_PART_MAIN for home_img_12
//	static lv_style_t style_home_img_12_main;
//	lv_style_reset(&style_home_img_12_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_home_img_12_main
//	lv_style_set_image_recolor(&style_home_img_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_home_img_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_home_img_12_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->home_img_12, LV_IMG_PART_MAIN, &style_home_img_12_main);
	lv_obj_set_pos(ui->home_img_12, 141, 310);
//	lv_obj_set_size(ui->home_img_12, 198, 269);
//	lv_obj_set_click(ui->home_img_12, true);
	lv_img_set_src(ui->home_img_12,&_kuwei_alpha_198x269);
//	lv_img_set_src(ui->home_img_12,"lv_lib_png/png_decoder_test.png");
//	lv_img_set_pivot(ui->home_img_12, 0,0);
//	lv_img_set_angle(ui->home_img_12, 0);

	//Write codes home_label_file_name
	ui->home_label_file_name = lv_label_create(ui->home_cont_home, NULL);
	lv_label_set_long_mode(ui->home_label_file_name, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->home_label_file_name, "0");
//	lv_label_set_long_mode(ui->home_label_file_name, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_label_file_name, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_label_file_name
	static lv_style_t style_home_label_file_name_main;
	lv_style_reset(&style_home_label_file_name_main);
	lv_style_init(&style_home_label_file_name_main);

	//Write style state: LV_STATE_DEFAULT for style_home_label_file_name_main
	lv_style_set_radius(&style_home_label_file_name_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_label_file_name_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_home_label_file_name_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_home_label_file_name_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_label_file_name_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_home_label_file_name_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_file_name_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_home_label_file_name_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_home_label_file_name_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_label_file_name_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_label_file_name_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_label_file_name_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_label_file_name, LV_LABEL_PART_MAIN, &style_home_label_file_name_main);
	lv_obj_set_pos(ui->home_label_file_name, 90, 210);
	lv_obj_set_size(ui->home_label_file_name, 300, 42);

	//Write codes home_label_remain_time
	ui->home_label_remain_time = lv_label_create(ui->home_cont_home, NULL);
	lv_label_set_text(ui->home_label_remain_time, "10:15");
	lv_label_set_long_mode(ui->home_label_remain_time, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_label_remain_time, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_label_remain_time
	static lv_style_t style_home_label_remain_time_main;
	lv_style_reset(&style_home_label_remain_time_main);
	lv_style_init(&style_home_label_remain_time_main);

	//Write style state: LV_STATE_DEFAULT for style_home_label_remain_time_main
	lv_style_set_radius(&style_home_label_remain_time_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_label_remain_time_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_home_label_remain_time_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_home_label_remain_time_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_label_remain_time_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_home_label_remain_time_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_remain_time_main, LV_STATE_DEFAULT, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_home_label_remain_time_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_home_label_remain_time_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_label_remain_time_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_label_remain_time_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_label_remain_time_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_label_remain_time, LV_LABEL_PART_MAIN, &style_home_label_remain_time_main);
	lv_obj_set_pos(ui->home_label_remain_time, 140, 410);
	lv_obj_set_size(ui->home_label_remain_time, 200, 0);

	//Write codes home_label_fin_percent
	ui->home_label_fin_percent = lv_label_create(ui->home_cont_home, NULL);
	lv_label_set_text(ui->home_label_fin_percent, "");
	lv_label_set_long_mode(ui->home_label_fin_percent, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_label_fin_percent, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_label_fin_percent
	static lv_style_t style_home_label_fin_percent_main;
	lv_style_reset(&style_home_label_fin_percent_main);
	lv_style_init(&style_home_label_fin_percent_main);

	//Write style state: LV_STATE_DEFAULT for style_home_label_fin_percent_main
	lv_style_set_radius(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_label_fin_percent_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_label_fin_percent, LV_LABEL_PART_MAIN, &style_home_label_fin_percent_main);
	lv_obj_set_pos(ui->home_label_fin_percent, 190, 350);
	lv_obj_set_size(ui->home_label_fin_percent, 100, 0);

	//Write codes home_arc_progress
	ui->home_arc_progress = lv_arc_create(ui->home_cont_home, NULL);

	//Write style LV_ARC_PART_BG for home_arc_progress
	static lv_style_t style_home_arc_progress_bg;
	lv_style_reset(&style_home_arc_progress_bg);
	lv_style_init(&style_home_arc_progress_bg);

	//Write style state: LV_STATE_DEFAULT for style_home_arc_progress_bg
	lv_style_set_bg_color(&style_home_arc_progress_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_home_arc_progress_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_home_arc_progress_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_arc_progress_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_width(&style_home_arc_progress_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_line_color(&style_home_arc_progress_bg, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_line_width(&style_home_arc_progress_bg, LV_STATE_DEFAULT, 20);
	lv_obj_add_style(ui->home_arc_progress, LV_ARC_PART_BG, &style_home_arc_progress_bg);

	//Write style LV_ARC_PART_INDIC for home_arc_progress
	static lv_style_t style_home_arc_progress_indic;
	lv_style_reset(&style_home_arc_progress_indic);
	lv_style_init(&style_home_arc_progress_indic);

	//Write style state: LV_STATE_DEFAULT for style_home_arc_progress_indic
	lv_style_set_line_color(&style_home_arc_progress_indic, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_line_width(&style_home_arc_progress_indic, LV_STATE_DEFAULT, 20);
	lv_obj_add_style(ui->home_arc_progress, LV_ARC_PART_INDIC, &style_home_arc_progress_indic);
	lv_obj_set_pos(ui->home_arc_progress, 90, 258);
	lv_obj_set_size(ui->home_arc_progress, 300, 300);
	lv_arc_set_bg_angles(ui->home_arc_progress, 0, 360);
	lv_arc_set_angles(ui->home_arc_progress, 360, 360);
	lv_arc_set_rotation(ui->home_arc_progress, 270);
	lv_obj_set_style_local_pad_top(ui->home_arc_progress, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_bottom(ui->home_arc_progress, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_left(ui->home_arc_progress, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_right(ui->home_arc_progress, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_line_rounded(ui->home_arc_progress, LV_ARC_PART_INDIC, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_line_rounded(ui->home_arc_progress, LV_ARC_PART_BG, LV_STATE_DEFAULT, 0);

	//Write codes home_cont_2
	ui->home_cont_2 = lv_cont_create(ui->home_cont_home, NULL);

	//Write style LV_CONT_PART_MAIN for home_cont_2
	static lv_style_t style_home_cont_2_main;
	lv_style_reset(&style_home_cont_2_main);
	lv_style_init(&style_home_cont_2_main);

	//Write style state: LV_STATE_DEFAULT for style_home_cont_2_main
	lv_style_set_radius(&style_home_cont_2_main, LV_STATE_DEFAULT, 8);
	lv_style_set_bg_color(&style_home_cont_2_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_home_cont_2_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_home_cont_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_cont_2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_home_cont_2_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_border_width(&style_home_cont_2_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_home_cont_2_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_home_cont_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_cont_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_cont_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_cont_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_cont_2, LV_CONT_PART_MAIN, &style_home_cont_2_main);
	lv_obj_set_pos(ui->home_cont_2, 14, 108);
	lv_obj_set_size(ui->home_cont_2, 220, 60);
	lv_obj_set_click(ui->home_cont_2, false);
	lv_cont_set_layout(ui->home_cont_2, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->home_cont_2, LV_FIT_NONE);

	//Write codes home_cont_3
	ui->home_cont_3 = lv_cont_create(ui->home_cont_home, NULL);

	//Write style LV_CONT_PART_MAIN for home_cont_3
	static lv_style_t style_home_cont_3_main;
	lv_style_reset(&style_home_cont_3_main);
	lv_style_init(&style_home_cont_3_main);

	//Write style state: LV_STATE_DEFAULT for style_home_cont_3_main
	lv_style_set_radius(&style_home_cont_3_main, LV_STATE_DEFAULT, 8);
	lv_style_set_bg_color(&style_home_cont_3_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_home_cont_3_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_home_cont_3_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_cont_3_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_home_cont_3_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_border_width(&style_home_cont_3_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_home_cont_3_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_home_cont_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_cont_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_cont_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_cont_3_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_cont_3, LV_CONT_PART_MAIN, &style_home_cont_3_main);
	lv_obj_set_pos(ui->home_cont_3, 14, 38);
	lv_obj_set_size(ui->home_cont_3, 220, 60);
	lv_obj_set_click(ui->home_cont_3, false);
	lv_cont_set_layout(ui->home_cont_3, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->home_cont_3, LV_FIT_NONE);

	//Write codes home_img_6
	ui->home_img_6 = lv_img_create(ui->home_cont_home, NULL);

	//Write style LV_IMG_PART_MAIN for home_img_6
//	static lv_style_t style_home_img_6_main;
//	lv_style_reset(&style_home_img_6_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_home_img_6_main
//	lv_style_set_image_recolor(&style_home_img_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_home_img_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_home_img_6_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->home_img_6, LV_IMG_PART_MAIN, &style_home_img_6_main);
	lv_obj_set_pos(ui->home_img_6, 32, 46);
//	lv_obj_set_size(ui->home_img_6, 44, 44);
//	lv_obj_set_click(ui->home_img_6, true);
	lv_img_set_src(ui->home_img_6,&_hotend_alpha_44x44);
//	lv_img_set_pivot(ui->home_img_6, 0,0);
//	lv_img_set_angle(ui->home_img_6, 0);

	//Write codes home_img_7
	ui->home_img_7 = lv_img_create(ui->home_cont_home, NULL);

	//Write style LV_IMG_PART_MAIN for home_img_7
//	static lv_style_t style_home_img_7_main;
//	lv_style_reset(&style_home_img_7_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_home_img_7_main
//	lv_style_set_image_recolor(&style_home_img_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_home_img_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_home_img_7_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->home_img_7, LV_IMG_PART_MAIN, &style_home_img_7_main);
	lv_obj_set_pos(ui->home_img_7, 32, 116);
//	lv_obj_set_size(ui->home_img_7, 44, 44);
//	lv_obj_set_click(ui->home_img_7, true);
	lv_img_set_src(ui->home_img_7,&_hotbed_alpha_44x44);
//	lv_img_set_pivot(ui->home_img_7, 0,0);
//	lv_img_set_angle(ui->home_img_7, 0);

	//Write codes home_cont_5
	ui->home_cont_5 = lv_cont_create(ui->home_cont_home, NULL);

	//Write style LV_CONT_PART_MAIN for home_cont_5
	static lv_style_t style_home_cont_5_main;
	lv_style_reset(&style_home_cont_5_main);
	lv_style_init(&style_home_cont_5_main);

	//Write style state: LV_STATE_DEFAULT for style_home_cont_5_main
	lv_style_set_radius(&style_home_cont_5_main, LV_STATE_DEFAULT, 8);
	lv_style_set_bg_color(&style_home_cont_5_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_home_cont_5_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_home_cont_5_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_cont_5_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_home_cont_5_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_border_width(&style_home_cont_5_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_home_cont_5_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_home_cont_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_cont_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_cont_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_cont_5_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_cont_5, LV_CONT_PART_MAIN, &style_home_cont_5_main);
	lv_obj_set_pos(ui->home_cont_5, 246, 38);
	lv_obj_set_size(ui->home_cont_5, 220, 60);
	lv_obj_set_click(ui->home_cont_5, false);
	lv_cont_set_layout(ui->home_cont_5, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->home_cont_5, LV_FIT_NONE);

	//Write codes home_img_8
	ui->home_img_8 = lv_img_create(ui->home_cont_home, NULL);

	//Write style LV_IMG_PART_MAIN for home_img_8
//	static lv_style_t style_home_img_8_main;
//	lv_style_reset(&style_home_img_8_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_home_img_8_main
//	lv_style_set_image_recolor(&style_home_img_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_home_img_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_home_img_8_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->home_img_8, LV_IMG_PART_MAIN, &style_home_img_8_main);
	lv_obj_set_pos(ui->home_img_8, 268, 56);
//	lv_obj_set_size(ui->home_img_8, 38, 24);
//	lv_obj_set_click(ui->home_img_8, true);
	lv_img_set_src(ui->home_img_8,&_speed_alpha_38x24);
//	lv_img_set_pivot(ui->home_img_8, 0,0);
//	lv_img_set_angle(ui->home_img_8, 0);

	//Write codes home_cont_4
	ui->home_cont_4 = lv_cont_create(ui->home_cont_home, NULL);

	//Write style LV_CONT_PART_MAIN for home_cont_4
	static lv_style_t style_home_cont_4_main;
	lv_style_reset(&style_home_cont_4_main);
	lv_style_init(&style_home_cont_4_main);

	//Write style state: LV_STATE_DEFAULT for style_home_cont_4_main
	lv_style_set_radius(&style_home_cont_4_main, LV_STATE_DEFAULT, 8);
	lv_style_set_bg_color(&style_home_cont_4_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_home_cont_4_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_home_cont_4_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_cont_4_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_home_cont_4_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_border_width(&style_home_cont_4_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_home_cont_4_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_home_cont_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_cont_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_cont_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_cont_4_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_cont_4, LV_CONT_PART_MAIN, &style_home_cont_4_main);
	lv_obj_set_pos(ui->home_cont_4, 246, 108);
	lv_obj_set_size(ui->home_cont_4, 220, 60);
	lv_obj_set_click(ui->home_cont_4, false);
	lv_cont_set_layout(ui->home_cont_4, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->home_cont_4, LV_FIT_NONE);

	//Write codes home_img_9
	ui->home_img_9 = lv_img_create(ui->home_cont_home, NULL);

	//Write style LV_IMG_PART_MAIN for home_img_9
//	static lv_style_t style_home_img_9_main;
//	lv_style_reset(&style_home_img_9_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_home_img_9_main
//	lv_style_set_image_recolor(&style_home_img_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_home_img_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_home_img_9_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->home_img_9, LV_IMG_PART_MAIN, &style_home_img_9_main);
	lv_obj_set_pos(ui->home_img_9, 271, 122);
//	lv_obj_set_size(ui->home_img_9, 33, 31);
//	lv_obj_set_click(ui->home_img_9, true);
	lv_img_set_src(ui->home_img_9,&_zoffset_alpha_33x31);
//	lv_img_set_pivot(ui->home_img_9, 0,0);
//	lv_img_set_angle(ui->home_img_9, 0);

	//Write codes home_label_cur_ht_temp
	ui->home_label_cur_ht_temp = lv_label_create(ui->home_cont_home, NULL);
	lv_label_set_text(ui->home_label_cur_ht_temp, "");
	lv_label_set_long_mode(ui->home_label_cur_ht_temp, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_label_cur_ht_temp, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_label_cur_ht_temp
	static lv_style_t style_home_label_cur_ht_temp_main;
	lv_style_reset(&style_home_label_cur_ht_temp_main);
	lv_style_init(&style_home_label_cur_ht_temp_main);

	//Write style state: LV_STATE_DEFAULT for style_home_label_cur_ht_temp_main
	lv_style_set_radius(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_label_cur_ht_temp_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_label_cur_ht_temp, LV_LABEL_PART_MAIN, &style_home_label_cur_ht_temp_main);
	lv_obj_set_pos(ui->home_label_cur_ht_temp, 97, 54);
	lv_obj_set_size(ui->home_label_cur_ht_temp, 48, 0);

	//Write codes home_label_max_ht_temp
	ui->home_label_max_ht_temp = lv_label_create(ui->home_cont_home, NULL);
	lv_label_set_text(ui->home_label_max_ht_temp, "0");
	lv_label_set_long_mode(ui->home_label_max_ht_temp, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_label_max_ht_temp, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_label_max_ht_temp
	static lv_style_t style_home_label_max_ht_temp_main;
	lv_style_reset(&style_home_label_max_ht_temp_main);
	lv_style_init(&style_home_label_max_ht_temp_main);

	//Write style state: LV_STATE_DEFAULT for style_home_label_max_ht_temp_main
	lv_style_set_radius(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_label_max_ht_temp_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_label_max_ht_temp, LV_LABEL_PART_MAIN, &style_home_label_max_ht_temp_main);
	lv_obj_set_pos(ui->home_label_max_ht_temp, 172, 54);
	lv_obj_set_size(ui->home_label_max_ht_temp, 48, 0);

	//Write codes home_label_cur_bed_temp
	ui->home_label_cur_bed_temp = lv_label_create(ui->home_cont_home, NULL);
	lv_label_set_text(ui->home_label_cur_bed_temp, "");
	lv_label_set_long_mode(ui->home_label_cur_bed_temp, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_label_cur_bed_temp, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_label_cur_bed_temp
	static lv_style_t style_home_label_cur_bed_temp_main;
	lv_style_reset(&style_home_label_cur_bed_temp_main);
	lv_style_init(&style_home_label_cur_bed_temp_main);

	//Write style state: LV_STATE_DEFAULT for style_home_label_cur_bed_temp_main
	lv_style_set_radius(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_label_cur_bed_temp_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_label_cur_bed_temp, LV_LABEL_PART_MAIN, &style_home_label_cur_bed_temp_main);
	lv_obj_set_pos(ui->home_label_cur_bed_temp, 97, 124);
	lv_obj_set_size(ui->home_label_cur_bed_temp, 48, 0);

	//Write codes home_label_max_bed_temp
	ui->home_label_max_bed_temp = lv_label_create(ui->home_cont_home, NULL);
	lv_label_set_text(ui->home_label_max_bed_temp, "0");
	lv_label_set_long_mode(ui->home_label_max_bed_temp, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_label_max_bed_temp, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_label_max_bed_temp
	static lv_style_t style_home_label_max_bed_temp_main;
	lv_style_reset(&style_home_label_max_bed_temp_main);
	lv_style_init(&style_home_label_max_bed_temp_main);

	//Write style state: LV_STATE_DEFAULT for style_home_label_max_bed_temp_main
	lv_style_set_radius(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_label_max_bed_temp_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_label_max_bed_temp, LV_LABEL_PART_MAIN, &style_home_label_max_bed_temp_main);
	lv_obj_set_pos(ui->home_label_max_bed_temp, 172, 124);
	lv_obj_set_size(ui->home_label_max_bed_temp, 48, 0);

	//Write codes home_label_cur_speed
	ui->home_label_cur_speed = lv_label_create(ui->home_cont_home, NULL);
	lv_label_set_text(ui->home_label_cur_speed, "100%");
	lv_label_set_long_mode(ui->home_label_cur_speed, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_label_cur_speed, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_label_cur_speed
	static lv_style_t style_home_label_cur_speed_main;
	lv_style_reset(&style_home_label_cur_speed_main);
	lv_style_init(&style_home_label_cur_speed_main);

	//Write style state: LV_STATE_DEFAULT for style_home_label_cur_speed_main
	lv_style_set_radius(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_label_cur_speed_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_label_cur_speed, LV_LABEL_PART_MAIN, &style_home_label_cur_speed_main);
	lv_obj_set_pos(ui->home_label_cur_speed, 360, 54);
	lv_obj_set_size(ui->home_label_cur_speed, 80, 0);

	//Write codes home_label_cur_zoffset
	ui->home_label_cur_zoffset = lv_label_create(ui->home_cont_home, NULL);
	lv_label_set_text(ui->home_label_cur_zoffset, "0.00");
	lv_label_set_long_mode(ui->home_label_cur_zoffset, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_label_cur_zoffset, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_label_cur_zoffset
	static lv_style_t style_home_label_cur_zoffset_main;
	lv_style_reset(&style_home_label_cur_zoffset_main);
	lv_style_init(&style_home_label_cur_zoffset_main);

	//Write style state: LV_STATE_DEFAULT for style_home_label_cur_zoffset_main
	lv_style_set_radius(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_home_label_cur_zoffset_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_label_cur_zoffset, LV_LABEL_PART_MAIN, &style_home_label_cur_zoffset_main);
	lv_obj_set_pos(ui->home_label_cur_zoffset, 360, 124);
	lv_obj_set_size(ui->home_label_cur_zoffset, 80, 0);

	//Write codes home_line_1
	ui->home_line_1 = lv_line_create(ui->home_cont_home, NULL);

	//Write style LV_LINE_PART_MAIN for home_line_1
	static lv_style_t style_home_line_1_main;
	lv_style_reset(&style_home_line_1_main);
	lv_style_init(&style_home_line_1_main);

	//Write style state: LV_STATE_DEFAULT for style_home_line_1_main
	lv_style_set_line_color(&style_home_line_1_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_line_width(&style_home_line_1_main, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->home_line_1, LV_LINE_PART_MAIN, &style_home_line_1_main);
	lv_obj_set_pos(ui->home_line_1, 156, 58);
	lv_obj_set_size(ui->home_line_1, 2, 19);
	static lv_point_t home_line_1[] ={{0,0},{0,19}};
	lv_line_set_points(ui->home_line_1,home_line_1,2);

	//Write codes home_line_2
	ui->home_line_2 = lv_line_create(ui->home_cont_home, NULL);

	//Write style LV_LINE_PART_MAIN for home_line_2
	static lv_style_t style_home_line_2_main;
	lv_style_reset(&style_home_line_2_main);
	lv_style_init(&style_home_line_2_main);

	//Write style state: LV_STATE_DEFAULT for style_home_line_2_main
	lv_style_set_line_color(&style_home_line_2_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_line_width(&style_home_line_2_main, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->home_line_2, LV_LINE_PART_MAIN, &style_home_line_2_main);
	lv_obj_set_pos(ui->home_line_2, 157, 128);
	lv_obj_set_size(ui->home_line_2, 2, 19);
	static lv_point_t home_line_2[] ={{0,0},{0,19}};
	lv_line_set_points(ui->home_line_2,home_line_2,2);
	lv_cont_set_layout(ui->home_cont_home, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->home_cont_home, LV_FIT_NONE);

	//Init events for screen
	events_init_home(ui);
}
