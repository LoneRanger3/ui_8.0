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

void setup_scr_MotionSet(lv_ui *ui){

	//Write codes MotionSet
//	ui->MotionSet = lv_obj_create(NULL, NULL);

	//Write codes MotionSet_cont_motion_set
	ui->MotionSet_cont_motion_set = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for MotionSet_cont_motion_set
	static lv_style_t style_MotionSet_cont_motion_set_main;
	lv_style_reset(&style_MotionSet_cont_motion_set_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_cont_motion_set_main
	lv_style_set_radius(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_cont_motion_set_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_cont_motion_set, LV_CONT_PART_MAIN, &style_MotionSet_cont_motion_set_main);
	lv_obj_set_pos(ui->MotionSet_cont_motion_set, 0, 0);
	lv_obj_set_size(ui->MotionSet_cont_motion_set, 480, 800);
	lv_obj_set_click(ui->MotionSet_cont_motion_set, false);

	//Write codes MotionSet_btn_RTOSet
	ui->MotionSet_btn_RTOSet = lv_btn_create(ui->MotionSet_cont_motion_set, NULL);

	//Write style LV_BTN_PART_MAIN for MotionSet_btn_RTOSet
	static lv_style_t style_MotionSet_btn_RTOSet_main;
	lv_style_reset(&style_MotionSet_btn_RTOSet_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_btn_RTOSet_main
	lv_style_set_radius(&style_MotionSet_btn_RTOSet_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MotionSet_btn_RTOSet_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MotionSet_btn_RTOSet_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MotionSet_btn_RTOSet_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_btn_RTOSet_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MotionSet_btn_RTOSet_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MotionSet_btn_RTOSet_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MotionSet_btn_RTOSet_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MotionSet_btn_RTOSet_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MotionSet_btn_RTOSet_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MotionSet_btn_RTOSet, LV_BTN_PART_MAIN, &style_MotionSet_btn_RTOSet_main);
	lv_obj_set_pos(ui->MotionSet_btn_RTOSet, 39, 107);
	lv_obj_set_size(ui->MotionSet_btn_RTOSet, 402, 118);
//	ui->MotionSet_btn_RTOSet_label = lv_label_create(ui->MotionSet_btn_RTOSet, NULL);
//	lv_label_set_text(ui->MotionSet_btn_RTOSet_label, "");
//	lv_obj_set_style_local_text_color(ui->MotionSet_btn_RTOSet_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MotionSet_label_2
	ui->MotionSet_label_2 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_long_mode(ui->MotionSet_label_2, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->MotionSet_label_2, steps[cur_language]);
//	lv_label_set_long_mode(ui->MotionSet_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_2, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_2
	static lv_style_t style_MotionSet_label_2_main;
	lv_style_reset(&style_MotionSet_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_2_main
	lv_style_set_radius(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_2, LV_LABEL_PART_MAIN, &style_MotionSet_label_2_main);
	lv_obj_set_pos(ui->MotionSet_label_2, 160, 152);
	lv_obj_set_size(ui->MotionSet_label_2, 220, 42);

	//Write codes MotionSet_img_2
	ui->MotionSet_img_2 = lv_img_create(ui->MotionSet_cont_motion_set, NULL);

	//Write style LV_IMG_PART_MAIN for MotionSet_img_2
//	static lv_style_t style_MotionSet_img_2_main;
//	lv_style_reset(&style_MotionSet_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MotionSet_img_2_main
//	lv_style_set_image_recolor(&style_MotionSet_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MotionSet_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MotionSet_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MotionSet_img_2, LV_IMG_PART_MAIN, &style_MotionSet_img_2_main);
	lv_obj_set_pos(ui->MotionSet_img_2, 84, 142);
//	lv_obj_set_size(ui->MotionSet_img_2, 44, 44);
//	lv_obj_set_click(ui->MotionSet_img_2, true);
	lv_img_set_src(ui->MotionSet_img_2,&_mspeed_alpha_44x44);
//	lv_img_set_pivot(ui->MotionSet_img_2, 0,0);
//	lv_img_set_angle(ui->MotionSet_img_2, 0);

	//Write codes MotionSet_img_back
	ui->MotionSet_img_back = lv_img_create(ui->MotionSet_cont_motion_set, NULL);

	//Write style LV_IMG_PART_MAIN for MotionSet_img_back
//	static lv_style_t style_MotionSet_img_back_main;
//	lv_style_reset(&style_MotionSet_img_back_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MotionSet_img_back_main
//	lv_style_set_image_recolor(&style_MotionSet_img_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MotionSet_img_back_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MotionSet_img_back_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MotionSet_img_back, LV_IMG_PART_MAIN, &style_MotionSet_img_back_main);
	lv_obj_set_pos(ui->MotionSet_img_back, 24, 30);
//	lv_obj_set_size(ui->MotionSet_img_back, 45, 36);
	lv_obj_set_click(ui->MotionSet_img_back, true);
	lv_img_set_src(ui->MotionSet_img_back,&_return_alpha_45x36);
//	lv_img_set_pivot(ui->MotionSet_img_back, 0,0);
//	lv_img_set_angle(ui->MotionSet_img_back, 0);

	//Write codes MotionSet_label_1
	ui->MotionSet_label_1 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_long_mode(ui->MotionSet_label_1, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->MotionSet_label_1, motion_setting[cur_language]);
//	lv_label_set_long_mode(ui->MotionSet_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_1, LV_LABEL_ALIGN_RIGHT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_1
	static lv_style_t style_MotionSet_label_1_main;
	lv_style_reset(&style_MotionSet_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_1_main
	lv_style_set_radius(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_1, LV_LABEL_PART_MAIN, &style_MotionSet_label_1_main);
	lv_obj_set_pos(ui->MotionSet_label_1, 113, 32);
	lv_obj_set_size(ui->MotionSet_label_1, 347, 42);

	//Write codes MotionSet_btn_MaxAcc
	ui->MotionSet_btn_MaxAcc = lv_btn_create(ui->MotionSet_cont_motion_set, NULL);

	//Write style LV_BTN_PART_MAIN for MotionSet_btn_MaxAcc
	static lv_style_t style_MotionSet_btn_MaxAcc_main;
	lv_style_reset(&style_MotionSet_btn_MaxAcc_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_btn_MaxAcc_main
	lv_style_set_radius(&style_MotionSet_btn_MaxAcc_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MotionSet_btn_MaxAcc_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MotionSet_btn_MaxAcc_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MotionSet_btn_MaxAcc_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_btn_MaxAcc_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MotionSet_btn_MaxAcc_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MotionSet_btn_MaxAcc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MotionSet_btn_MaxAcc_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MotionSet_btn_MaxAcc_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MotionSet_btn_MaxAcc_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MotionSet_btn_MaxAcc, LV_BTN_PART_MAIN, &style_MotionSet_btn_MaxAcc_main);
	lv_obj_set_pos(ui->MotionSet_btn_MaxAcc, 39, 247);
	lv_obj_set_size(ui->MotionSet_btn_MaxAcc, 402, 118);
//	ui->MotionSet_btn_MaxAcc_label = lv_label_create(ui->MotionSet_btn_MaxAcc, NULL);
//	lv_label_set_text(ui->MotionSet_btn_MaxAcc_label, "");
//	lv_obj_set_style_local_text_color(ui->MotionSet_btn_MaxAcc_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MotionSet_label_4
	ui->MotionSet_label_4 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_long_mode(ui->MotionSet_label_4, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->MotionSet_label_4, macc_setting[cur_language]);
//	lv_label_set_long_mode(ui->MotionSet_label_4, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_4, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_4
	static lv_style_t style_MotionSet_label_4_main;
	lv_style_reset(&style_MotionSet_label_4_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_4_main
	lv_style_set_radius(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_4_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_4, LV_LABEL_PART_MAIN, &style_MotionSet_label_4_main);
	lv_obj_set_pos(ui->MotionSet_label_4, 160, 292);
	lv_obj_set_size(ui->MotionSet_label_4, 250, 42);

	//Write codes MotionSet_label_6
	ui->MotionSet_label_6 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_text(ui->MotionSet_label_6, "i");
	lv_label_set_long_mode(ui->MotionSet_label_6, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_6, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_6
	static lv_style_t style_MotionSet_label_6_main;
	lv_style_reset(&style_MotionSet_label_6_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_6_main
	lv_style_set_radius(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_6, LV_LABEL_PART_MAIN, &style_MotionSet_label_6_main);
	lv_obj_set_pos(ui->MotionSet_label_6, 101, 153);
	lv_obj_set_size(ui->MotionSet_label_6, 20, 0);

	//Write codes MotionSet_label_7
	ui->MotionSet_label_7 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_text(ui->MotionSet_label_7, ">");
	lv_label_set_long_mode(ui->MotionSet_label_7, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_7, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_7
	static lv_style_t style_MotionSet_label_7_main;
	lv_style_reset(&style_MotionSet_label_7_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_7_main
	lv_style_set_radius(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_7_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_7, LV_LABEL_PART_MAIN, &style_MotionSet_label_7_main);
	lv_obj_set_pos(ui->MotionSet_label_7, 400, 152);
	lv_obj_set_size(ui->MotionSet_label_7, 20, 0);

	//Write codes MotionSet_img_6
	ui->MotionSet_img_6 = lv_img_create(ui->MotionSet_cont_motion_set, NULL);

	//Write style LV_IMG_PART_MAIN for MotionSet_img_6
//	static lv_style_t style_MotionSet_img_6_main;
//	lv_style_reset(&style_MotionSet_img_6_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MotionSet_img_6_main
//	lv_style_set_image_recolor(&style_MotionSet_img_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MotionSet_img_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MotionSet_img_6_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MotionSet_img_6, LV_IMG_PART_MAIN, &style_MotionSet_img_6_main);
	lv_obj_set_pos(ui->MotionSet_img_6, 84, 282);
//	lv_obj_set_size(ui->MotionSet_img_6, 44, 44);
//	lv_obj_set_click(ui->MotionSet_img_6, true);
	lv_img_set_src(ui->MotionSet_img_6,&_macc_alpha_44x44);
//	lv_img_set_pivot(ui->MotionSet_img_6, 0,0);
//	lv_img_set_angle(ui->MotionSet_img_6, 0);

	//Write codes MotionSet_label_8
	ui->MotionSet_label_8 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_text(ui->MotionSet_label_8, ">");
	lv_label_set_long_mode(ui->MotionSet_label_8, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_8, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_8
	static lv_style_t style_MotionSet_label_8_main;
	lv_style_reset(&style_MotionSet_label_8_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_8_main
	lv_style_set_radius(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_8, LV_LABEL_PART_MAIN, &style_MotionSet_label_8_main);
	lv_obj_set_pos(ui->MotionSet_label_8, 400, 292);
	lv_obj_set_size(ui->MotionSet_label_8, 20, 0);

	//Write codes MotionSet_btn_MaxConcor
	ui->MotionSet_btn_MaxConcor = lv_btn_create(ui->MotionSet_cont_motion_set, NULL);

	//Write style LV_BTN_PART_MAIN for MotionSet_btn_MaxConcor
	static lv_style_t style_MotionSet_btn_MaxConcor_main;
	lv_style_reset(&style_MotionSet_btn_MaxConcor_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_btn_MaxConcor_main
	lv_style_set_radius(&style_MotionSet_btn_MaxConcor_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MotionSet_btn_MaxConcor_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MotionSet_btn_MaxConcor_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MotionSet_btn_MaxConcor_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_btn_MaxConcor_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MotionSet_btn_MaxConcor_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MotionSet_btn_MaxConcor_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MotionSet_btn_MaxConcor_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MotionSet_btn_MaxConcor_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MotionSet_btn_MaxConcor_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MotionSet_btn_MaxConcor, LV_BTN_PART_MAIN, &style_MotionSet_btn_MaxConcor_main);
	lv_obj_set_pos(ui->MotionSet_btn_MaxConcor, 39, 387);
	lv_obj_set_size(ui->MotionSet_btn_MaxConcor, 402, 118);
//	ui->MotionSet_btn_MaxConcor_label = lv_label_create(ui->MotionSet_btn_MaxConcor, NULL);
//	lv_label_set_text(ui->MotionSet_btn_MaxConcor_label, "");
//	lv_obj_set_style_local_text_color(ui->MotionSet_btn_MaxConcor_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MotionSet_btn_MaxSpeed
	ui->MotionSet_btn_MaxSpeed = lv_btn_create(ui->MotionSet_cont_motion_set, NULL);

	//Write style LV_BTN_PART_MAIN for MotionSet_btn_MaxSpeed
	static lv_style_t style_MotionSet_btn_MaxSpeed_main;
	lv_style_reset(&style_MotionSet_btn_MaxSpeed_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_btn_MaxSpeed_main
	lv_style_set_radius(&style_MotionSet_btn_MaxSpeed_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MotionSet_btn_MaxSpeed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MotionSet_btn_MaxSpeed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MotionSet_btn_MaxSpeed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_btn_MaxSpeed_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MotionSet_btn_MaxSpeed_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MotionSet_btn_MaxSpeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MotionSet_btn_MaxSpeed_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MotionSet_btn_MaxSpeed_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MotionSet_btn_MaxSpeed_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MotionSet_btn_MaxSpeed, LV_BTN_PART_MAIN, &style_MotionSet_btn_MaxSpeed_main);
	lv_obj_set_pos(ui->MotionSet_btn_MaxSpeed, 39, 527);
	lv_obj_set_size(ui->MotionSet_btn_MaxSpeed, 402, 118);
//	ui->MotionSet_btn_MaxSpeed_label = lv_label_create(ui->MotionSet_btn_MaxSpeed, NULL);
//	lv_label_set_text(ui->MotionSet_btn_MaxSpeed_label, "");
//	lv_obj_set_style_local_text_color(ui->MotionSet_btn_MaxSpeed_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MotionSet_img_7
	ui->MotionSet_img_7 = lv_img_create(ui->MotionSet_cont_motion_set, NULL);

	//Write style LV_IMG_PART_MAIN for MotionSet_img_7
//	static lv_style_t style_MotionSet_img_7_main;
//	lv_style_reset(&style_MotionSet_img_7_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MotionSet_img_7_main
//	lv_style_set_image_recolor(&style_MotionSet_img_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MotionSet_img_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MotionSet_img_7_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MotionSet_img_7, LV_IMG_PART_MAIN, &style_MotionSet_img_7_main);
	lv_obj_set_pos(ui->MotionSet_img_7, 84, 562);
//	lv_obj_set_size(ui->MotionSet_img_7, 44, 39);
//	lv_obj_set_click(ui->MotionSet_img_7, true);
	lv_img_set_src(ui->MotionSet_img_7,&_mspeeda_alpha_44x39);
//	lv_img_set_pivot(ui->MotionSet_img_7, 0,0);
//	lv_img_set_angle(ui->MotionSet_img_7, 0);

	//Write codes MotionSet_img_8
	ui->MotionSet_img_8 = lv_img_create(ui->MotionSet_cont_motion_set, NULL);

	//Write style LV_IMG_PART_MAIN for MotionSet_img_8
//	static lv_style_t style_MotionSet_img_8_main;
//	lv_style_reset(&style_MotionSet_img_8_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MotionSet_img_8_main
//	lv_style_set_image_recolor(&style_MotionSet_img_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MotionSet_img_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MotionSet_img_8_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MotionSet_img_8, LV_IMG_PART_MAIN, &style_MotionSet_img_8_main);
	lv_obj_set_pos(ui->MotionSet_img_8, 84, 422);
//	lv_obj_set_size(ui->MotionSet_img_8, 44, 44);
//	lv_obj_set_click(ui->MotionSet_img_8, true);
	lv_img_set_src(ui->MotionSet_img_8,&_mconcer_alpha_44x44);
//	lv_img_set_pivot(ui->MotionSet_img_8, 0,0);
//	lv_img_set_angle(ui->MotionSet_img_8, 0);

	//Write codes MotionSet_label_9
	ui->MotionSet_label_9 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_long_mode(ui->MotionSet_label_9, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->MotionSet_label_9, mspeed_setting[cur_language]);
//	lv_label_set_long_mode(ui->MotionSet_label_9, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_9, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_9
	static lv_style_t style_MotionSet_label_9_main;
	lv_style_reset(&style_MotionSet_label_9_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_9_main
	lv_style_set_radius(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_9, LV_LABEL_PART_MAIN, &style_MotionSet_label_9_main);
	lv_obj_set_pos(ui->MotionSet_label_9, 160, 572);
	lv_obj_set_size(ui->MotionSet_label_9, 250, 42);

	//Write codes MotionSet_label_10
	ui->MotionSet_label_10 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_long_mode(ui->MotionSet_label_10, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->MotionSet_label_10, mconcor_setting[cur_language]);
//	lv_label_set_long_mode(ui->MotionSet_label_10, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_10, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_10
	static lv_style_t style_MotionSet_label_10_main;
	lv_style_reset(&style_MotionSet_label_10_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_10_main
	lv_style_set_radius(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_10, LV_LABEL_PART_MAIN, &style_MotionSet_label_10_main);
	lv_obj_set_pos(ui->MotionSet_label_10, 160, 432);
	lv_obj_set_size(ui->MotionSet_label_10, 250, 42);

	//Write codes MotionSet_label_11
	ui->MotionSet_label_11 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_text(ui->MotionSet_label_11, ">");
	lv_label_set_long_mode(ui->MotionSet_label_11, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_11, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_11
	static lv_style_t style_MotionSet_label_11_main;
	lv_style_reset(&style_MotionSet_label_11_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_11_main
	lv_style_set_radius(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_11, LV_LABEL_PART_MAIN, &style_MotionSet_label_11_main);
	lv_obj_set_pos(ui->MotionSet_label_11, 400, 432);
	lv_obj_set_size(ui->MotionSet_label_11, 20, 0);

	//Write codes MotionSet_label_12
	ui->MotionSet_label_12 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_text(ui->MotionSet_label_12, ">");
	lv_label_set_long_mode(ui->MotionSet_label_12, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_12, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_12
	static lv_style_t style_MotionSet_label_12_main;
	lv_style_reset(&style_MotionSet_label_12_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_12_main
	lv_style_set_radius(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_12, LV_LABEL_PART_MAIN, &style_MotionSet_label_12_main);
	lv_obj_set_pos(ui->MotionSet_label_12, 400, 572);
	lv_obj_set_size(ui->MotionSet_label_12, 20, 0);

	//Write codes MotionSet_label_13
	ui->MotionSet_label_13 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_text(ui->MotionSet_label_13, "S");
	lv_label_set_long_mode(ui->MotionSet_label_13, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_13, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_13
	static lv_style_t style_MotionSet_label_13_main;
	lv_style_reset(&style_MotionSet_label_13_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_13_main
	lv_style_set_radius(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_13, LV_LABEL_PART_MAIN, &style_MotionSet_label_13_main);
	lv_obj_set_pos(ui->MotionSet_label_13, 101, 571);
	lv_obj_set_size(ui->MotionSet_label_13, 20, 0);

	//Write codes MotionSet_label_14
	ui->MotionSet_label_14 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_text(ui->MotionSet_label_14, "A");
	lv_label_set_long_mode(ui->MotionSet_label_14, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_14, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_14
	static lv_style_t style_MotionSet_label_14_main;
	lv_style_reset(&style_MotionSet_label_14_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_14_main
	lv_style_set_radius(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MotionSet_label_14_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_14, LV_LABEL_PART_MAIN, &style_MotionSet_label_14_main);
	lv_obj_set_pos(ui->MotionSet_label_14, 101, 293);
	lv_obj_set_size(ui->MotionSet_label_14, 20, 0);

	//Write codes MotionSet_label_15
	ui->MotionSet_label_15 = lv_label_create(ui->MotionSet_cont_motion_set, NULL);
	lv_label_set_text(ui->MotionSet_label_15, "J");
	lv_label_set_long_mode(ui->MotionSet_label_15, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MotionSet_label_15, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MotionSet_label_15
	static lv_style_t style_MotionSet_label_15_main;
	lv_style_reset(&style_MotionSet_label_15_main);

	//Write style state: LV_STATE_DEFAULT for style_MotionSet_label_15_main
	lv_style_set_radius(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_MotionSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MotionSet_label_15, LV_LABEL_PART_MAIN, &style_MotionSet_label_15_main);
	lv_obj_set_pos(ui->MotionSet_label_15, 101, 433);
	lv_obj_set_size(ui->MotionSet_label_15, 20, 0);
	lv_cont_set_layout(ui->MotionSet_cont_motion_set, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->MotionSet_cont_motion_set, LV_FIT_NONE);

	//Init events for screen
	events_init_MotionSet(ui);
}
