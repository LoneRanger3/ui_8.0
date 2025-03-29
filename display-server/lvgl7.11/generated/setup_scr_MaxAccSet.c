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

void setup_scr_MaxAccSet(lv_ui *ui){

	//Write codes MaxAccSet
//	ui->MaxAccSet = lv_obj_create(NULL, NULL);

	//Write codes MaxAccSet_cont_max_acc_set
	ui->MaxAccSet_cont_max_acc_set = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for MaxAccSet_cont_max_acc_set
	static lv_style_t style_MaxAccSet_cont_max_acc_set_main;
	lv_style_reset(&style_MaxAccSet_cont_max_acc_set_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_cont_max_acc_set_main
	lv_style_set_radius(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_cont_max_acc_set_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_cont_max_acc_set, LV_CONT_PART_MAIN, &style_MaxAccSet_cont_max_acc_set_main);
	lv_obj_set_pos(ui->MaxAccSet_cont_max_acc_set, 0, 0);
	lv_obj_set_size(ui->MaxAccSet_cont_max_acc_set, 480, 800);
	lv_obj_set_click(ui->MaxAccSet_cont_max_acc_set, false);

	//Write codes MaxAccSet_label_20
	ui->MaxAccSet_label_20 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_20, "124 mm/s*s");
	lv_label_set_long_mode(ui->MaxAccSet_label_20, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_20, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_20
	static lv_style_t style_MaxAccSet_label_20_main;
	lv_style_reset(&style_MaxAccSet_label_20_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_20_main
	lv_style_set_radius(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_20_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_20, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_20_main);
	lv_obj_set_pos(ui->MaxAccSet_label_20, 64, 448);
	lv_obj_set_size(ui->MaxAccSet_label_20, 150, 0);

	//Write codes MaxAccSet_btn_xmacc
	ui->MaxAccSet_btn_xmacc = lv_btn_create(ui->MaxAccSet_cont_max_acc_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxAccSet_btn_xmacc
	static lv_style_t style_MaxAccSet_btn_xmacc_main;
	lv_style_reset(&style_MaxAccSet_btn_xmacc_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_btn_xmacc_main
	lv_style_set_radius(&style_MaxAccSet_btn_xmacc_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxAccSet_btn_xmacc_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_btn_xmacc_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_btn_xmacc_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_btn_xmacc_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxAccSet_btn_xmacc_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxAccSet_btn_xmacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxAccSet_btn_xmacc_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxAccSet_btn_xmacc_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxAccSet_btn_xmacc_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxAccSet_btn_xmacc, LV_BTN_PART_MAIN, &style_MaxAccSet_btn_xmacc_main);
	lv_obj_set_pos(ui->MaxAccSet_btn_xmacc, 10, 106);
	lv_obj_set_size(ui->MaxAccSet_btn_xmacc, 224, 206);
//	ui->MaxAccSet_btn_xmacc_label = lv_label_create(ui->MaxAccSet_btn_xmacc, NULL);
//	lv_label_set_text(ui->MaxAccSet_btn_xmacc_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxAccSet_btn_xmacc_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxAccSet_label_21
	ui->MaxAccSet_label_21 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_21, "mm/s*s");
	lv_label_set_long_mode(ui->MaxAccSet_label_21, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_21, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_21
	static lv_style_t style_MaxAccSet_label_21_main;
	lv_style_reset(&style_MaxAccSet_label_21_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_21_main
	lv_style_set_radius(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_21_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_21, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_21_main);
	lv_obj_set_pos(ui->MaxAccSet_label_21, 98, 198);
	lv_obj_set_size(ui->MaxAccSet_label_21, 150, 0);

	//Write codes MaxAccSet_label_2
	ui->MaxAccSet_label_2 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_long_mode(ui->MaxAccSet_label_2, LV_LABEL_LONG_SROLL_CIRC);
    char *c = malloc(strlen(macc_setting[cur_language]) + 2);
	strcpy(c, "X ");
    strcat(c, macc_setting[cur_language]);
	lv_label_set_text(ui->MaxAccSet_label_2, c);
//	lv_label_set_long_mode(ui->MaxAccSet_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_2, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_2
	static lv_style_t style_MaxAccSet_label_2_main;
	lv_style_reset(&style_MaxAccSet_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_2_main
	lv_style_set_radius(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_2, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_2_main);
	lv_obj_set_pos(ui->MaxAccSet_label_2, 34, 260);
	lv_obj_set_size(ui->MaxAccSet_label_2, 200, 42);

	//Write codes MaxAccSet_img_2
	ui->MaxAccSet_img_2 = lv_img_create(ui->MaxAccSet_cont_max_acc_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxAccSet_img_2
//	static lv_style_t style_MaxAccSet_img_2_main;
//	lv_style_reset(&style_MaxAccSet_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_img_2_main
//	lv_style_set_image_recolor(&style_MaxAccSet_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxAccSet_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxAccSet_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxAccSet_img_2, LV_IMG_PART_MAIN, &style_MaxAccSet_img_2_main);
	lv_obj_set_pos(ui->MaxAccSet_img_2, 26, 119);
//	lv_obj_set_size(ui->MaxAccSet_img_2, 44, 44);
//	lv_obj_set_click(ui->MaxAccSet_img_2, true);
	lv_img_set_src(ui->MaxAccSet_img_2,&_macc_alpha_44x44);
//	lv_img_set_pivot(ui->MaxAccSet_img_2, 0,0);
//	lv_img_set_angle(ui->MaxAccSet_img_2, 0);

	//Write codes MaxAccSet_img_back
	ui->MaxAccSet_img_back = lv_img_create(ui->MaxAccSet_cont_max_acc_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxAccSet_img_back
//	static lv_style_t style_MaxAccSet_img_back_main;
//	lv_style_reset(&style_MaxAccSet_img_back_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_img_back_main
//	lv_style_set_image_recolor(&style_MaxAccSet_img_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxAccSet_img_back_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxAccSet_img_back_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxAccSet_img_back, LV_IMG_PART_MAIN, &style_MaxAccSet_img_back_main);
	lv_obj_set_pos(ui->MaxAccSet_img_back, 24, 30);
//	lv_obj_set_size(ui->MaxAccSet_img_back, 45, 36);
	lv_obj_set_click(ui->MaxAccSet_img_back, true);
	lv_img_set_src(ui->MaxAccSet_img_back,&_return_alpha_45x36);
//	lv_img_set_pivot(ui->MaxAccSet_img_back, 0,0);
//	lv_img_set_angle(ui->MaxAccSet_img_back, 0);

	//Write codes MaxAccSet_label_1
	ui->MaxAccSet_label_1 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_1, macc_setting[cur_language]);
	lv_label_set_long_mode(ui->MaxAccSet_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_1, LV_LABEL_ALIGN_RIGHT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_1
	static lv_style_t style_MaxAccSet_label_1_main;
	lv_style_reset(&style_MaxAccSet_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_1_main
	lv_style_set_radius(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
       lv_style_set_text_font(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_1, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_1_main);
	lv_obj_set_pos(ui->MaxAccSet_label_1, 113, 32);
	lv_obj_set_size(ui->MaxAccSet_label_1, 347, 0);

	//Write codes MaxAccSet_label_6
	ui->MaxAccSet_label_6 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_6, "X");
	lv_label_set_long_mode(ui->MaxAccSet_label_6, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_6, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_6
	static lv_style_t style_MaxAccSet_label_6_main;
	lv_style_reset(&style_MaxAccSet_label_6_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_6_main
	lv_style_set_radius(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_6, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_6_main);
	lv_obj_set_pos(ui->MaxAccSet_label_6, 42, 130);
	lv_obj_set_size(ui->MaxAccSet_label_6, 20, 0);

	//Write codes MaxAccSet_label_xmacc
	ui->MaxAccSet_label_xmacc = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_xmacc, "");
	lv_label_set_long_mode(ui->MaxAccSet_label_xmacc, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_xmacc, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_xmacc
	static lv_style_t style_MaxAccSet_label_xmacc_main;
	lv_style_reset(&style_MaxAccSet_label_xmacc_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_xmacc_main
	lv_style_set_radius(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_xmacc_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_xmacc, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_xmacc_main);
	lv_obj_set_pos(ui->MaxAccSet_label_xmacc, 34, 198);
	lv_obj_set_size(ui->MaxAccSet_label_xmacc, 80, 0);

	//Write codes MaxAccSet_btn_ymacc
	ui->MaxAccSet_btn_ymacc = lv_btn_create(ui->MaxAccSet_cont_max_acc_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxAccSet_btn_ymacc
	static lv_style_t style_MaxAccSet_btn_ymacc_main;
	lv_style_reset(&style_MaxAccSet_btn_ymacc_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_btn_ymacc_main
	lv_style_set_radius(&style_MaxAccSet_btn_ymacc_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxAccSet_btn_ymacc_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_btn_ymacc_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_btn_ymacc_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_btn_ymacc_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxAccSet_btn_ymacc_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxAccSet_btn_ymacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxAccSet_btn_ymacc_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxAccSet_btn_ymacc_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxAccSet_btn_ymacc_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxAccSet_btn_ymacc, LV_BTN_PART_MAIN, &style_MaxAccSet_btn_ymacc_main);
	lv_obj_set_pos(ui->MaxAccSet_btn_ymacc, 246, 106);
	lv_obj_set_size(ui->MaxAccSet_btn_ymacc, 225, 206);
//	ui->MaxAccSet_btn_ymacc_label = lv_label_create(ui->MaxAccSet_btn_ymacc, NULL);
//	lv_label_set_text(ui->MaxAccSet_btn_ymacc_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxAccSet_btn_ymacc_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxAccSet_btn_zmacc
	ui->MaxAccSet_btn_zmacc = lv_btn_create(ui->MaxAccSet_cont_max_acc_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxAccSet_btn_zmacc
	static lv_style_t style_MaxAccSet_btn_zmacc_main;
	lv_style_reset(&style_MaxAccSet_btn_zmacc_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_btn_zmacc_main
	lv_style_set_radius(&style_MaxAccSet_btn_zmacc_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxAccSet_btn_zmacc_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_btn_zmacc_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_btn_zmacc_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_btn_zmacc_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxAccSet_btn_zmacc_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxAccSet_btn_zmacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxAccSet_btn_zmacc_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxAccSet_btn_zmacc_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxAccSet_btn_zmacc_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxAccSet_btn_zmacc, LV_BTN_PART_MAIN, &style_MaxAccSet_btn_zmacc_main);
	lv_obj_set_pos(ui->MaxAccSet_btn_zmacc, 10, 326);
	lv_obj_set_size(ui->MaxAccSet_btn_zmacc, 224, 206);
//	ui->MaxAccSet_btn_zmacc_label = lv_label_create(ui->MaxAccSet_btn_zmacc, NULL);
//	lv_label_set_text(ui->MaxAccSet_btn_zmacc_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxAccSet_btn_zmacc_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxAccSet_label_22
	ui->MaxAccSet_label_22 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_22, "mm/s*s");
	lv_label_set_long_mode(ui->MaxAccSet_label_22, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_22, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_22
	static lv_style_t style_MaxAccSet_label_22_main;
	lv_style_reset(&style_MaxAccSet_label_22_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_22_main
	lv_style_set_radius(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_22_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_22, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_22_main);
	lv_obj_set_pos(ui->MaxAccSet_label_22, 98, 418);
	lv_obj_set_size(ui->MaxAccSet_label_22, 150, 0);

	//Write codes MaxAccSet_btn_emacc
	ui->MaxAccSet_btn_emacc = lv_btn_create(ui->MaxAccSet_cont_max_acc_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxAccSet_btn_emacc
	static lv_style_t style_MaxAccSet_btn_emacc_main;
	lv_style_reset(&style_MaxAccSet_btn_emacc_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_btn_emacc_main
	lv_style_set_radius(&style_MaxAccSet_btn_emacc_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxAccSet_btn_emacc_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_btn_emacc_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_btn_emacc_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_btn_emacc_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxAccSet_btn_emacc_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxAccSet_btn_emacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxAccSet_btn_emacc_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxAccSet_btn_emacc_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxAccSet_btn_emacc_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxAccSet_btn_emacc, LV_BTN_PART_MAIN, &style_MaxAccSet_btn_emacc_main);
	lv_obj_set_pos(ui->MaxAccSet_btn_emacc, 246, 326);
	lv_obj_set_size(ui->MaxAccSet_btn_emacc, 225, 206);
//	ui->MaxAccSet_btn_emacc_label = lv_label_create(ui->MaxAccSet_btn_emacc, NULL);
//	lv_label_set_text(ui->MaxAccSet_btn_emacc_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxAccSet_btn_emacc_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxAccSet_label_24
	ui->MaxAccSet_label_24 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_24, "mm/s*s");
	lv_label_set_long_mode(ui->MaxAccSet_label_24, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_24, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_24
	static lv_style_t style_MaxAccSet_label_24_main;
	lv_style_reset(&style_MaxAccSet_label_24_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_24_main
	lv_style_set_radius(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_24_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_24, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_24_main);
	lv_obj_set_pos(ui->MaxAccSet_label_24, 334, 198);
	lv_obj_set_size(ui->MaxAccSet_label_24, 150, 0);

	//Write codes MaxAccSet_label_23
	ui->MaxAccSet_label_23 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_23, "mm/s*s");
	lv_label_set_long_mode(ui->MaxAccSet_label_23, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_23, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_23
	static lv_style_t style_MaxAccSet_label_23_main;
	lv_style_reset(&style_MaxAccSet_label_23_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_23_main
	lv_style_set_radius(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_23_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_23, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_23_main);
	lv_obj_set_pos(ui->MaxAccSet_label_23, 334, 418);
	lv_obj_set_size(ui->MaxAccSet_label_23, 150, 0);

	//Write codes MaxAccSet_img_3
	ui->MaxAccSet_img_3 = lv_img_create(ui->MaxAccSet_cont_max_acc_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxAccSet_img_3
//	static lv_style_t style_MaxAccSet_img_3_main;
//	lv_style_reset(&style_MaxAccSet_img_3_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_img_3_main
//	lv_style_set_image_recolor(&style_MaxAccSet_img_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxAccSet_img_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxAccSet_img_3_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxAccSet_img_3, LV_IMG_PART_MAIN, &style_MaxAccSet_img_3_main);
	lv_obj_set_pos(ui->MaxAccSet_img_3, 262, 119);
//	lv_obj_set_size(ui->MaxAccSet_img_3, 44, 44);
//	lv_obj_set_click(ui->MaxAccSet_img_3, true);
	lv_img_set_src(ui->MaxAccSet_img_3,&_macc_alpha_44x44);
//	lv_img_set_pivot(ui->MaxAccSet_img_3, 0,0);
//	lv_img_set_angle(ui->MaxAccSet_img_3, 0);

	//Write codes MaxAccSet_img_4
	ui->MaxAccSet_img_4 = lv_img_create(ui->MaxAccSet_cont_max_acc_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxAccSet_img_4
//	static lv_style_t style_MaxAccSet_img_4_main;
//	lv_style_reset(&style_MaxAccSet_img_4_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_img_4_main
//	lv_style_set_image_recolor(&style_MaxAccSet_img_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxAccSet_img_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxAccSet_img_4_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxAccSet_img_4, LV_IMG_PART_MAIN, &style_MaxAccSet_img_4_main);
	lv_obj_set_pos(ui->MaxAccSet_img_4, 26, 339);
//	lv_obj_set_size(ui->MaxAccSet_img_4, 44, 44);
//	lv_obj_set_click(ui->MaxAccSet_img_4, true);
	lv_img_set_src(ui->MaxAccSet_img_4,&_macc_alpha_44x44);
//	lv_img_set_pivot(ui->MaxAccSet_img_4, 0,0);
//	lv_img_set_angle(ui->MaxAccSet_img_4, 0);

	//Write codes MaxAccSet_img_5
	ui->MaxAccSet_img_5 = lv_img_create(ui->MaxAccSet_cont_max_acc_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxAccSet_img_5
//	static lv_style_t style_MaxAccSet_img_5_main;
//	lv_style_reset(&style_MaxAccSet_img_5_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_img_5_main
//	lv_style_set_image_recolor(&style_MaxAccSet_img_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxAccSet_img_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxAccSet_img_5_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxAccSet_img_5, LV_IMG_PART_MAIN, &style_MaxAccSet_img_5_main);
	lv_obj_set_pos(ui->MaxAccSet_img_5, 262, 339);
//	lv_obj_set_size(ui->MaxAccSet_img_5, 44, 44);
//	lv_obj_set_click(ui->MaxAccSet_img_5, true);
	lv_img_set_src(ui->MaxAccSet_img_5,&_macc_alpha_44x44);
//	lv_img_set_pivot(ui->MaxAccSet_img_5, 0,0);
//	lv_img_set_angle(ui->MaxAccSet_img_5, 0);

	//Write codes MaxAccSet_label_8
	ui->MaxAccSet_label_8 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_8, "Y");
	lv_label_set_long_mode(ui->MaxAccSet_label_8, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_8, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_8
	static lv_style_t style_MaxAccSet_label_8_main;
	lv_style_reset(&style_MaxAccSet_label_8_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_8_main
	lv_style_set_radius(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_8, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_8_main);
	lv_obj_set_pos(ui->MaxAccSet_label_8, 278, 130);
	lv_obj_set_size(ui->MaxAccSet_label_8, 20, 0);

	//Write codes MaxAccSet_label_9
	ui->MaxAccSet_label_9 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_9, "E");
	lv_label_set_long_mode(ui->MaxAccSet_label_9, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_9, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_9
	static lv_style_t style_MaxAccSet_label_9_main;
	lv_style_reset(&style_MaxAccSet_label_9_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_9_main
	lv_style_set_radius(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_9, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_9_main);
	lv_obj_set_pos(ui->MaxAccSet_label_9, 278, 350);
	lv_obj_set_size(ui->MaxAccSet_label_9, 20, 0);

	//Write codes MaxAccSet_label_10
	ui->MaxAccSet_label_10 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_10, "Z");
	lv_label_set_long_mode(ui->MaxAccSet_label_10, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_10, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_10
	static lv_style_t style_MaxAccSet_label_10_main;
	lv_style_reset(&style_MaxAccSet_label_10_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_10_main
	lv_style_set_radius(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_10, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_10_main);
	lv_obj_set_pos(ui->MaxAccSet_label_10, 42, 350);
	lv_obj_set_size(ui->MaxAccSet_label_10, 20, 0);

	//Write codes MaxAccSet_label_11
	ui->MaxAccSet_label_11 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_long_mode(ui->MaxAccSet_label_11, LV_LABEL_LONG_SROLL_CIRC);
	c[0] = 'E';
	lv_label_set_text(ui->MaxAccSet_label_11, c);
//	lv_label_set_long_mode(ui->MaxAccSet_label_11, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_11, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_11
	static lv_style_t style_MaxAccSet_label_11_main;
	lv_style_reset(&style_MaxAccSet_label_11_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_11_main
	lv_style_set_radius(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_11, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_11_main);
	lv_obj_set_pos(ui->MaxAccSet_label_11, 270, 480);
	lv_obj_set_size(ui->MaxAccSet_label_11, 200, 42);

	//Write codes MaxAccSet_label_12
	ui->MaxAccSet_label_12 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_long_mode(ui->MaxAccSet_label_12, LV_LABEL_LONG_SROLL_CIRC);
	c[0] = 'Z';
	lv_label_set_text(ui->MaxAccSet_label_12, c);
//	lv_label_set_long_mode(ui->MaxAccSet_label_12, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_12, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_12
	static lv_style_t style_MaxAccSet_label_12_main;
	lv_style_reset(&style_MaxAccSet_label_12_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_12_main
	lv_style_set_radius(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_12, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_12_main);
	lv_obj_set_pos(ui->MaxAccSet_label_12, 34, 480);
	lv_obj_set_size(ui->MaxAccSet_label_12, 200, 42);

	//Write codes MaxAccSet_label_13
	ui->MaxAccSet_label_13 = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_long_mode(ui->MaxAccSet_label_13, LV_LABEL_LONG_SROLL_CIRC);
	c[0] = 'Y';
	lv_label_set_text(ui->MaxAccSet_label_13, c);
//	lv_label_set_long_mode(ui->MaxAccSet_label_13, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_13, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_13
	static lv_style_t style_MaxAccSet_label_13_main;
	lv_style_reset(&style_MaxAccSet_label_13_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_13_main
	lv_style_set_radius(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_13, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_13_main);
	lv_obj_set_pos(ui->MaxAccSet_label_13, 270, 260);
	lv_obj_set_size(ui->MaxAccSet_label_13, 200, 42);

	//Write codes MaxAccSet_label_ymacc
	ui->MaxAccSet_label_ymacc = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_ymacc, "");
	lv_label_set_long_mode(ui->MaxAccSet_label_ymacc, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_ymacc, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_ymacc
	static lv_style_t style_MaxAccSet_label_ymacc_main;
	lv_style_reset(&style_MaxAccSet_label_ymacc_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_ymacc_main
	lv_style_set_radius(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_ymacc_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_ymacc, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_ymacc_main);
	lv_obj_set_pos(ui->MaxAccSet_label_ymacc, 270, 198);
	lv_obj_set_size(ui->MaxAccSet_label_ymacc, 80, 0);

	//Write codes MaxAccSet_label_zmacc
	ui->MaxAccSet_label_zmacc = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_zmacc, "");
	lv_label_set_long_mode(ui->MaxAccSet_label_zmacc, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_zmacc, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_zmacc
	static lv_style_t style_MaxAccSet_label_zmacc_main;
	lv_style_reset(&style_MaxAccSet_label_zmacc_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_zmacc_main
	lv_style_set_radius(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxAccSet_label_zmacc_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_zmacc, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_zmacc_main);
	lv_obj_set_pos(ui->MaxAccSet_label_zmacc, 34, 418);
	lv_obj_set_size(ui->MaxAccSet_label_zmacc, 80, 0);

	//Write codes MaxAccSet_label_emacc
	ui->MaxAccSet_label_emacc = lv_label_create(ui->MaxAccSet_cont_max_acc_set, NULL);
	lv_label_set_text(ui->MaxAccSet_label_emacc, "");
	lv_label_set_long_mode(ui->MaxAccSet_label_emacc, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxAccSet_label_emacc, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxAccSet_label_emacc
	static lv_style_t style_MaxAccSet_label_emacc_main;
	lv_style_reset(&style_MaxAccSet_label_emacc_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxAccSet_label_emacc_main
	lv_style_set_radius(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_MaxAccSet_label_emacc_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxAccSet_label_emacc, LV_LABEL_PART_MAIN, &style_MaxAccSet_label_emacc_main);
	lv_obj_set_pos(ui->MaxAccSet_label_emacc, 270, 418);
	lv_obj_set_size(ui->MaxAccSet_label_emacc, 80, 0);
	lv_cont_set_layout(ui->MaxAccSet_cont_max_acc_set, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->MaxAccSet_cont_max_acc_set, LV_FIT_NONE);

	//Init events for screen
	events_init_MaxAccSet(ui);
}
