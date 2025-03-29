/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include <stdlib.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "clanguage.h"

void setup_scr_RTOSet(lv_ui *ui){

	//Write codes RTOSet
//	ui->RTOSet = lv_obj_create(NULL, NULL);

	//Write codes RTOSet_cont_rto_set
	ui->RTOSet_cont_rto_set = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for RTOSet_cont_rto_set
	static lv_style_t style_RTOSet_cont_rto_set_main;
	lv_style_reset(&style_RTOSet_cont_rto_set_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_cont_rto_set_main
	lv_style_set_radius(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_cont_rto_set_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_cont_rto_set, LV_CONT_PART_MAIN, &style_RTOSet_cont_rto_set_main);
	lv_obj_set_pos(ui->RTOSet_cont_rto_set, 0, 0);
	lv_obj_set_size(ui->RTOSet_cont_rto_set, 480, 800);
	lv_obj_set_click(ui->RTOSet_cont_rto_set, false);

	//Write codes RTOSet_btn_xrto
	ui->RTOSet_btn_xrto = lv_btn_create(ui->RTOSet_cont_rto_set, NULL);

	//Write style LV_BTN_PART_MAIN for RTOSet_btn_xrto
	static lv_style_t style_RTOSet_btn_xrto_main;
	lv_style_reset(&style_RTOSet_btn_xrto_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_btn_xrto_main
	lv_style_set_radius(&style_RTOSet_btn_xrto_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_RTOSet_btn_xrto_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_RTOSet_btn_xrto_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_RTOSet_btn_xrto_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_btn_xrto_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_RTOSet_btn_xrto_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_RTOSet_btn_xrto_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_RTOSet_btn_xrto_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_RTOSet_btn_xrto_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_RTOSet_btn_xrto_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->RTOSet_btn_xrto, LV_BTN_PART_MAIN, &style_RTOSet_btn_xrto_main);
	lv_obj_set_pos(ui->RTOSet_btn_xrto, 10, 106);
	lv_obj_set_size(ui->RTOSet_btn_xrto, 224, 206);
//	ui->RTOSet_btn_xrto_label = lv_label_create(ui->RTOSet_btn_xrto, NULL);
//	lv_label_set_text(ui->RTOSet_btn_xrto_label, "");
//	lv_obj_set_style_local_text_color(ui->RTOSet_btn_xrto_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	//Write codes RTOSet_label_14
	ui->RTOSet_label_14 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_14, "steps/mm");
	lv_label_set_long_mode(ui->RTOSet_label_14, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_14, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_14
	static lv_style_t style_RTOSet_label_14_main;
	lv_style_reset(&style_RTOSet_label_14_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_14_main
	lv_style_set_radius(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_bg_color(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_14_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_14, LV_LABEL_PART_MAIN, &style_RTOSet_label_14_main);
	lv_obj_set_pos(ui->RTOSet_label_14, 112, 198);
	lv_obj_set_size(ui->RTOSet_label_14, 120, 0);

	//Write codes RTOSet_label_2
	ui->RTOSet_label_2 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	char *c = malloc(strlen(steps[cur_language]) + 2);
	strcpy(c, "X ");
    strcat(c, steps[cur_language]);
	lv_label_set_text(ui->RTOSet_label_2, c);
	lv_label_set_long_mode(ui->RTOSet_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_2, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_2
	static lv_style_t style_RTOSet_label_2_main;
	lv_style_reset(&style_RTOSet_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_2_main
	lv_style_set_radius(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_2, LV_LABEL_PART_MAIN, &style_RTOSet_label_2_main);
	lv_obj_set_pos(ui->RTOSet_label_2, 34, 260);
	lv_obj_set_size(ui->RTOSet_label_2, 200, 0);

	//Write codes RTOSet_img_2
	ui->RTOSet_img_2 = lv_img_create(ui->RTOSet_cont_rto_set, NULL);

	//Write style LV_IMG_PART_MAIN for RTOSet_img_2
//	static lv_style_t style_RTOSet_img_2_main;
//	lv_style_reset(&style_RTOSet_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_RTOSet_img_2_main
//	lv_style_set_image_recolor(&style_RTOSet_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_RTOSet_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_RTOSet_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->RTOSet_img_2, LV_IMG_PART_MAIN, &style_RTOSet_img_2_main);
	lv_obj_set_pos(ui->RTOSet_img_2, 26, 119);
//	lv_obj_set_size(ui->RTOSet_img_2, 44, 44);
//	lv_obj_set_click(ui->RTOSet_img_2, true);
	lv_img_set_src(ui->RTOSet_img_2,&_mspeed_alpha_44x44);
//	lv_img_set_pivot(ui->RTOSet_img_2, 0,0);
//	lv_img_set_angle(ui->RTOSet_img_2, 0);

	//Write codes RTOSet_img_back
	ui->RTOSet_img_back = lv_img_create(ui->RTOSet_cont_rto_set, NULL);

	//Write style LV_IMG_PART_MAIN for RTOSet_img_back
//	static lv_style_t style_RTOSet_img_back_main;
//	lv_style_reset(&style_RTOSet_img_back_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_RTOSet_img_back_main
//	lv_style_set_image_recolor(&style_RTOSet_img_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_RTOSet_img_back_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_RTOSet_img_back_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->RTOSet_img_back, LV_IMG_PART_MAIN, &style_RTOSet_img_back_main);
	lv_obj_set_pos(ui->RTOSet_img_back, 24, 30);
//	lv_obj_set_size(ui->RTOSet_img_back, 45, 36);
	lv_obj_set_click(ui->RTOSet_img_back, true);
	lv_img_set_src(ui->RTOSet_img_back,&_return_alpha_45x36);
//	lv_img_set_pivot(ui->RTOSet_img_back, 0,0);
//	lv_img_set_angle(ui->RTOSet_img_back, 0);

	//Write codes RTOSet_label_1
	ui->RTOSet_label_1 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_1, steps_setting[cur_language]);
	lv_label_set_long_mode(ui->RTOSet_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_1, LV_LABEL_ALIGN_RIGHT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_1
	static lv_style_t style_RTOSet_label_1_main;
	lv_style_reset(&style_RTOSet_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_1_main
	lv_style_set_radius(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_1, LV_LABEL_PART_MAIN, &style_RTOSet_label_1_main);
	lv_obj_set_pos(ui->RTOSet_label_1, 113, 32);
	lv_obj_set_size(ui->RTOSet_label_1, 347, 0);

	//Write codes RTOSet_label_6
	ui->RTOSet_label_6 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_6, "X");
	lv_label_set_long_mode(ui->RTOSet_label_6, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_6, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_6
	static lv_style_t style_RTOSet_label_6_main;
	lv_style_reset(&style_RTOSet_label_6_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_6_main
	lv_style_set_radius(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_6, LV_LABEL_PART_MAIN, &style_RTOSet_label_6_main);
	lv_obj_set_pos(ui->RTOSet_label_6, 42, 130);
	lv_obj_set_size(ui->RTOSet_label_6, 20, 0);

	//Write codes RTOSet_label_xRTO
	ui->RTOSet_label_xRTO = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_xRTO, "");
	lv_label_set_long_mode(ui->RTOSet_label_xRTO, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_xRTO, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_xRTO
	static lv_style_t style_RTOSet_label_xRTO_main;
	lv_style_reset(&style_RTOSet_label_xRTO_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_xRTO_main
	lv_style_set_radius(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_xRTO_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_xRTO, LV_LABEL_PART_MAIN, &style_RTOSet_label_xRTO_main);
	lv_obj_set_pos(ui->RTOSet_label_xRTO, 34, 198);
	lv_obj_set_size(ui->RTOSet_label_xRTO, 80, 0);

	//Write codes RTOSet_btn_yrto
	ui->RTOSet_btn_yrto = lv_btn_create(ui->RTOSet_cont_rto_set, NULL);

	//Write style LV_BTN_PART_MAIN for RTOSet_btn_yrto
	static lv_style_t style_RTOSet_btn_yrto_main;
	lv_style_reset(&style_RTOSet_btn_yrto_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_btn_yrto_main
	lv_style_set_radius(&style_RTOSet_btn_yrto_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_RTOSet_btn_yrto_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_RTOSet_btn_yrto_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_RTOSet_btn_yrto_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_btn_yrto_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_RTOSet_btn_yrto_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_RTOSet_btn_yrto_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_RTOSet_btn_yrto_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_RTOSet_btn_yrto_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_RTOSet_btn_yrto_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->RTOSet_btn_yrto, LV_BTN_PART_MAIN, &style_RTOSet_btn_yrto_main);
	lv_obj_set_pos(ui->RTOSet_btn_yrto, 246, 106);
	lv_obj_set_size(ui->RTOSet_btn_yrto, 225, 206);
//	ui->RTOSet_btn_yrto_label = lv_label_create(ui->RTOSet_btn_yrto, NULL);
//	lv_label_set_text(ui->RTOSet_btn_yrto_label, "");
//	lv_obj_set_style_local_text_color(ui->RTOSet_btn_yrto_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	//Write codes RTOSet_label_15
	ui->RTOSet_label_15 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_15, "steps/mm");
	lv_label_set_long_mode(ui->RTOSet_label_15, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_15, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_15
	static lv_style_t style_RTOSet_label_15_main;
	lv_style_reset(&style_RTOSet_label_15_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_15_main
	lv_style_set_radius(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_bg_color(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_15, LV_LABEL_PART_MAIN, &style_RTOSet_label_15_main);
	lv_obj_set_pos(ui->RTOSet_label_15, 348, 198);
	lv_obj_set_size(ui->RTOSet_label_15, 120, 0);

	//Write codes RTOSet_btn_zrto
	ui->RTOSet_btn_zrto = lv_btn_create(ui->RTOSet_cont_rto_set, NULL);

	//Write style LV_BTN_PART_MAIN for RTOSet_btn_zrto
	static lv_style_t style_RTOSet_btn_zrto_main;
	lv_style_reset(&style_RTOSet_btn_zrto_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_btn_zrto_main
	lv_style_set_radius(&style_RTOSet_btn_zrto_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_RTOSet_btn_zrto_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_RTOSet_btn_zrto_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_RTOSet_btn_zrto_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_btn_zrto_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_RTOSet_btn_zrto_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_RTOSet_btn_zrto_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_RTOSet_btn_zrto_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_RTOSet_btn_zrto_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_RTOSet_btn_zrto_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->RTOSet_btn_zrto, LV_BTN_PART_MAIN, &style_RTOSet_btn_zrto_main);
	lv_obj_set_pos(ui->RTOSet_btn_zrto, 10, 326);
	lv_obj_set_size(ui->RTOSet_btn_zrto, 224, 206);
//	ui->RTOSet_btn_zrto_label = lv_label_create(ui->RTOSet_btn_zrto, NULL);
//	lv_label_set_text(ui->RTOSet_btn_zrto_label, "");
//	lv_obj_set_style_local_text_color(ui->RTOSet_btn_zrto_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	//Write codes RTOSet_label_16
	ui->RTOSet_label_16 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_16, "steps/mm");
	lv_label_set_long_mode(ui->RTOSet_label_16, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_16, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_16
	static lv_style_t style_RTOSet_label_16_main;
	lv_style_reset(&style_RTOSet_label_16_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_16_main
	lv_style_set_radius(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_bg_color(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_16_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_16, LV_LABEL_PART_MAIN, &style_RTOSet_label_16_main);
	lv_obj_set_pos(ui->RTOSet_label_16, 112, 418);
	lv_obj_set_size(ui->RTOSet_label_16, 120, 0);

	//Write codes RTOSet_btn_erto
	ui->RTOSet_btn_erto = lv_btn_create(ui->RTOSet_cont_rto_set, NULL);

	//Write style LV_BTN_PART_MAIN for RTOSet_btn_erto
	static lv_style_t style_RTOSet_btn_erto_main;
	lv_style_reset(&style_RTOSet_btn_erto_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_btn_erto_main
	lv_style_set_radius(&style_RTOSet_btn_erto_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_RTOSet_btn_erto_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_RTOSet_btn_erto_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_RTOSet_btn_erto_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_btn_erto_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_RTOSet_btn_erto_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_RTOSet_btn_erto_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_RTOSet_btn_erto_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_RTOSet_btn_erto_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_RTOSet_btn_erto_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->RTOSet_btn_erto, LV_BTN_PART_MAIN, &style_RTOSet_btn_erto_main);
	lv_obj_set_pos(ui->RTOSet_btn_erto, 246, 326);
	lv_obj_set_size(ui->RTOSet_btn_erto, 225, 206);
//	ui->RTOSet_btn_erto_label = lv_label_create(ui->RTOSet_btn_erto, NULL);
//	lv_label_set_text(ui->RTOSet_btn_erto_label, "");
//	lv_obj_set_style_local_text_color(ui->RTOSet_btn_erto_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	//Write codes RTOSet_label_17
	ui->RTOSet_label_17 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_17, "steps/mm");
	lv_label_set_long_mode(ui->RTOSet_label_17, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_17, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_17
	static lv_style_t style_RTOSet_label_17_main;
	lv_style_reset(&style_RTOSet_label_17_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_17_main
	lv_style_set_radius(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_bg_color(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_17_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_17, LV_LABEL_PART_MAIN, &style_RTOSet_label_17_main);
	lv_obj_set_pos(ui->RTOSet_label_17, 348, 418);
	lv_obj_set_size(ui->RTOSet_label_17, 120, 0);

	//Write codes RTOSet_img_3
	ui->RTOSet_img_3 = lv_img_create(ui->RTOSet_cont_rto_set, NULL);

	//Write style LV_IMG_PART_MAIN for RTOSet_img_3
//	static lv_style_t style_RTOSet_img_3_main;
//	lv_style_reset(&style_RTOSet_img_3_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_RTOSet_img_3_main
//	lv_style_set_image_recolor(&style_RTOSet_img_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_RTOSet_img_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_RTOSet_img_3_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->RTOSet_img_3, LV_IMG_PART_MAIN, &style_RTOSet_img_3_main);
	lv_obj_set_pos(ui->RTOSet_img_3, 262, 119);
//	lv_obj_set_size(ui->RTOSet_img_3, 44, 44);
//	lv_obj_set_click(ui->RTOSet_img_3, true);
	lv_img_set_src(ui->RTOSet_img_3,&_mspeed_alpha_44x44);
//	lv_img_set_pivot(ui->RTOSet_img_3, 0,0);
//	lv_img_set_angle(ui->RTOSet_img_3, 0);

	//Write codes RTOSet_img_4
	ui->RTOSet_img_4 = lv_img_create(ui->RTOSet_cont_rto_set, NULL);

	//Write style LV_IMG_PART_MAIN for RTOSet_img_4
//	static lv_style_t style_RTOSet_img_4_main;
//	lv_style_reset(&style_RTOSet_img_4_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_RTOSet_img_4_main
//	lv_style_set_image_recolor(&style_RTOSet_img_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_RTOSet_img_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_RTOSet_img_4_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->RTOSet_img_4, LV_IMG_PART_MAIN, &style_RTOSet_img_4_main);
	lv_obj_set_pos(ui->RTOSet_img_4, 26, 339);
//	lv_obj_set_size(ui->RTOSet_img_4, 44, 44);
//	lv_obj_set_click(ui->RTOSet_img_4, true);
	lv_img_set_src(ui->RTOSet_img_4,&_mspeed_alpha_44x44);
//	lv_img_set_pivot(ui->RTOSet_img_4, 0,0);
//	lv_img_set_angle(ui->RTOSet_img_4, 0);

	//Write codes RTOSet_img_5
	ui->RTOSet_img_5 = lv_img_create(ui->RTOSet_cont_rto_set, NULL);

	//Write style LV_IMG_PART_MAIN for RTOSet_img_5
//	static lv_style_t style_RTOSet_img_5_main;
//	lv_style_reset(&style_RTOSet_img_5_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_RTOSet_img_5_main
//	lv_style_set_image_recolor(&style_RTOSet_img_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_RTOSet_img_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_RTOSet_img_5_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->RTOSet_img_5, LV_IMG_PART_MAIN, &style_RTOSet_img_5_main);
	lv_obj_set_pos(ui->RTOSet_img_5, 262, 339);
//	lv_obj_set_size(ui->RTOSet_img_5, 44, 44);
//	lv_obj_set_click(ui->RTOSet_img_5, true);
	lv_img_set_src(ui->RTOSet_img_5,&_mspeed_alpha_44x44);
//	lv_img_set_pivot(ui->RTOSet_img_5, 0,0);
//	lv_img_set_angle(ui->RTOSet_img_5, 0);

	//Write codes RTOSet_label_8
	ui->RTOSet_label_8 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_8, "Y");
	lv_label_set_long_mode(ui->RTOSet_label_8, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_8, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_8
	static lv_style_t style_RTOSet_label_8_main;
	lv_style_reset(&style_RTOSet_label_8_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_8_main
	lv_style_set_radius(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_8, LV_LABEL_PART_MAIN, &style_RTOSet_label_8_main);
	lv_obj_set_pos(ui->RTOSet_label_8, 278, 130);
	lv_obj_set_size(ui->RTOSet_label_8, 20, 0);

	//Write codes RTOSet_label_9
	ui->RTOSet_label_9 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_9, "E");
	lv_label_set_long_mode(ui->RTOSet_label_9, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_9, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_9
	static lv_style_t style_RTOSet_label_9_main;
	lv_style_reset(&style_RTOSet_label_9_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_9_main
	lv_style_set_radius(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_9, LV_LABEL_PART_MAIN, &style_RTOSet_label_9_main);
	lv_obj_set_pos(ui->RTOSet_label_9, 278, 350);
	lv_obj_set_size(ui->RTOSet_label_9, 20, 0);

	//Write codes RTOSet_label_10
	ui->RTOSet_label_10 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_10, "Z");
	lv_label_set_long_mode(ui->RTOSet_label_10, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_10, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_10
	static lv_style_t style_RTOSet_label_10_main;
	lv_style_reset(&style_RTOSet_label_10_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_10_main
	lv_style_set_radius(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_10, LV_LABEL_PART_MAIN, &style_RTOSet_label_10_main);
	lv_obj_set_pos(ui->RTOSet_label_10, 42, 350);
	lv_obj_set_size(ui->RTOSet_label_10, 20, 0);

	//Write codes RTOSet_label_11
	ui->RTOSet_label_11 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
    c[0] = 'E';
	lv_label_set_text(ui->RTOSet_label_11, c);
	lv_label_set_long_mode(ui->RTOSet_label_11, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_11, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_11
	static lv_style_t style_RTOSet_label_11_main;
	lv_style_reset(&style_RTOSet_label_11_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_11_main
	lv_style_set_radius(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_11, LV_LABEL_PART_MAIN, &style_RTOSet_label_11_main);
	lv_obj_set_pos(ui->RTOSet_label_11, 270, 480);
	lv_obj_set_size(ui->RTOSet_label_11, 200, 0);

	//Write codes RTOSet_label_12
	ui->RTOSet_label_12 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	c[0] = 'Z';
	lv_label_set_text(ui->RTOSet_label_12, c);
	lv_label_set_long_mode(ui->RTOSet_label_12, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_12, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_12
	static lv_style_t style_RTOSet_label_12_main;
	lv_style_reset(&style_RTOSet_label_12_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_12_main
	lv_style_set_radius(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_12, LV_LABEL_PART_MAIN, &style_RTOSet_label_12_main);
	lv_obj_set_pos(ui->RTOSet_label_12, 34, 480);
	lv_obj_set_size(ui->RTOSet_label_12, 200, 0);

	//Write codes RTOSet_label_13
	ui->RTOSet_label_13 = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	c[0] = 'Y';
	lv_label_set_text(ui->RTOSet_label_13, c);
	lv_label_set_long_mode(ui->RTOSet_label_13, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_13, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_13
	static lv_style_t style_RTOSet_label_13_main;
	lv_style_reset(&style_RTOSet_label_13_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_13_main
	lv_style_set_radius(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_13, LV_LABEL_PART_MAIN, &style_RTOSet_label_13_main);
	lv_obj_set_pos(ui->RTOSet_label_13, 270, 260);
	lv_obj_set_size(ui->RTOSet_label_13, 200, 0);

	//Write codes RTOSet_label_yRTO
	ui->RTOSet_label_yRTO = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_yRTO, "");
	lv_label_set_long_mode(ui->RTOSet_label_yRTO, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_yRTO, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_yRTO
	static lv_style_t style_RTOSet_label_yRTO_main;
	lv_style_reset(&style_RTOSet_label_yRTO_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_yRTO_main
	lv_style_set_radius(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_yRTO_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_yRTO, LV_LABEL_PART_MAIN, &style_RTOSet_label_yRTO_main);
	lv_obj_set_pos(ui->RTOSet_label_yRTO, 270, 198);
	lv_obj_set_size(ui->RTOSet_label_yRTO, 80, 0);

	//Write codes RTOSet_label_zRTO
	ui->RTOSet_label_zRTO = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_zRTO, "");
	lv_label_set_long_mode(ui->RTOSet_label_zRTO, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_zRTO, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_zRTO
	static lv_style_t style_RTOSet_label_zRTO_main;
	lv_style_reset(&style_RTOSet_label_zRTO_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_zRTO_main
	lv_style_set_radius(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_zRTO_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_zRTO, LV_LABEL_PART_MAIN, &style_RTOSet_label_zRTO_main);
	lv_obj_set_pos(ui->RTOSet_label_zRTO, 34, 418);
	lv_obj_set_size(ui->RTOSet_label_zRTO, 80, 0);

	//Write codes RTOSet_label_eRTO
	ui->RTOSet_label_eRTO = lv_label_create(ui->RTOSet_cont_rto_set, NULL);
	lv_label_set_text(ui->RTOSet_label_eRTO, "");
	lv_label_set_long_mode(ui->RTOSet_label_eRTO, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->RTOSet_label_eRTO, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for RTOSet_label_eRTO
	static lv_style_t style_RTOSet_label_eRTO_main;
	lv_style_reset(&style_RTOSet_label_eRTO_main);

	//Write style state: LV_STATE_DEFAULT for style_RTOSet_label_eRTO_main
	lv_style_set_radius(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_bg_color(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_RTOSet_label_eRTO_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->RTOSet_label_eRTO, LV_LABEL_PART_MAIN, &style_RTOSet_label_eRTO_main);
	lv_obj_set_pos(ui->RTOSet_label_eRTO, 270, 418);
	lv_obj_set_size(ui->RTOSet_label_eRTO, 80, 0);
	lv_cont_set_layout(ui->RTOSet_cont_rto_set, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->RTOSet_cont_rto_set, LV_FIT_NONE);

	//Init events for screen
	events_init_RTOSet(ui);
}
