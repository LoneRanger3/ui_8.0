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

void setup_scr_MaxConcorSet(lv_ui *ui){

	//Write codes MaxConcorSet
//	ui->MaxConcorSet = lv_obj_create(NULL, NULL);

	//Write codes MaxConcorSet_cont_max_concor_set
	ui->MaxConcorSet_cont_max_concor_set = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for MaxConcorSet_cont_max_concor_set
	static lv_style_t style_MaxConcorSet_cont_max_concor_set_main;
	lv_style_reset(&style_MaxConcorSet_cont_max_concor_set_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_cont_max_concor_set_main
	lv_style_set_radius(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_cont_max_concor_set_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_cont_max_concor_set, LV_CONT_PART_MAIN, &style_MaxConcorSet_cont_max_concor_set_main);
	lv_obj_set_pos(ui->MaxConcorSet_cont_max_concor_set, 0, 0);
	lv_obj_set_size(ui->MaxConcorSet_cont_max_concor_set, 480, 800);
	lv_obj_set_click(ui->MaxConcorSet_cont_max_concor_set, false);

	//Write codes MaxConcorSet_btn_xmcon
	ui->MaxConcorSet_btn_xmcon = lv_btn_create(ui->MaxConcorSet_cont_max_concor_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxConcorSet_btn_xmcon
	static lv_style_t style_MaxConcorSet_btn_xmcon_main;
	lv_style_reset(&style_MaxConcorSet_btn_xmcon_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_btn_xmcon_main
	lv_style_set_radius(&style_MaxConcorSet_btn_xmcon_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxConcorSet_btn_xmcon_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_btn_xmcon_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_btn_xmcon_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_btn_xmcon_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxConcorSet_btn_xmcon_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxConcorSet_btn_xmcon_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxConcorSet_btn_xmcon_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxConcorSet_btn_xmcon_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxConcorSet_btn_xmcon_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxConcorSet_btn_xmcon, LV_BTN_PART_MAIN, &style_MaxConcorSet_btn_xmcon_main);
	lv_obj_set_pos(ui->MaxConcorSet_btn_xmcon, 10, 106);
	lv_obj_set_size(ui->MaxConcorSet_btn_xmcon, 224, 206);
//	ui->MaxConcorSet_btn_xmcon_label = lv_label_create(ui->MaxConcorSet_btn_xmcon, NULL);
//	lv_label_set_text(ui->MaxConcorSet_btn_xmcon_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxConcorSet_btn_xmcon_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxConcorSet_label_14
	ui->MaxConcorSet_label_14 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_14, "mm/s");
	lv_label_set_long_mode(ui->MaxConcorSet_label_14, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_14, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_14
	static lv_style_t style_MaxConcorSet_label_14_main;
	lv_style_reset(&style_MaxConcorSet_label_14_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_14_main
	lv_style_set_radius(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_14_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_14, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_14_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_14, 98, 198);
	lv_obj_set_size(ui->MaxConcorSet_label_14, 150, 0);

	//Write codes MaxConcorSet_label_2
	ui->MaxConcorSet_label_2 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_long_mode(ui->MaxConcorSet_label_2, LV_LABEL_LONG_SROLL_CIRC);
	char *c = malloc(strlen(mconcor_setting[cur_language]) + 2);
	strcpy(c, "X ");
    strcat(c, mconcor_setting[cur_language]);
	lv_label_set_text(ui->MaxConcorSet_label_2, c);
//	lv_label_set_long_mode(ui->MaxConcorSet_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_2, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_2
	static lv_style_t style_MaxConcorSet_label_2_main;
	lv_style_reset(&style_MaxConcorSet_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_2_main
	lv_style_set_radius(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_2, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_2_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_2, 34, 260);
	lv_obj_set_size(ui->MaxConcorSet_label_2, 200, 42);

	//Write codes MaxConcorSet_img_2
	ui->MaxConcorSet_img_2 = lv_img_create(ui->MaxConcorSet_cont_max_concor_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxConcorSet_img_2
//	static lv_style_t style_MaxConcorSet_img_2_main;
//	lv_style_reset(&style_MaxConcorSet_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_img_2_main
//	lv_style_set_image_recolor(&style_MaxConcorSet_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxConcorSet_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxConcorSet_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxConcorSet_img_2, LV_IMG_PART_MAIN, &style_MaxConcorSet_img_2_main);
	lv_obj_set_pos(ui->MaxConcorSet_img_2, 26, 119);
//	lv_obj_set_size(ui->MaxConcorSet_img_2, 44, 44);
//	lv_obj_set_click(ui->MaxConcorSet_img_2, true);
	lv_img_set_src(ui->MaxConcorSet_img_2,&_mconcer_alpha_44x44);
//	lv_img_set_pivot(ui->MaxConcorSet_img_2, 0,0);
//	lv_img_set_angle(ui->MaxConcorSet_img_2, 0);

	//Write codes MaxConcorSet_img_back
	ui->MaxConcorSet_img_back = lv_img_create(ui->MaxConcorSet_cont_max_concor_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxConcorSet_img_back
//	static lv_style_t style_MaxConcorSet_img_back_main;
//	lv_style_reset(&style_MaxConcorSet_img_back_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_img_back_main
//	lv_style_set_image_recolor(&style_MaxConcorSet_img_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxConcorSet_img_back_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxConcorSet_img_back_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxConcorSet_img_back, LV_IMG_PART_MAIN, &style_MaxConcorSet_img_back_main);
	lv_obj_set_pos(ui->MaxConcorSet_img_back, 24, 30);
//	lv_obj_set_size(ui->MaxConcorSet_img_back, 45, 36);
	lv_obj_set_click(ui->MaxConcorSet_img_back, true);
	lv_img_set_src(ui->MaxConcorSet_img_back,&_return_alpha_45x36);
//	lv_img_set_pivot(ui->MaxConcorSet_img_back, 0,0);
//	lv_img_set_angle(ui->MaxConcorSet_img_back, 0);

	//Write codes MaxConcorSet_label_1
	ui->MaxConcorSet_label_1 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_long_mode(ui->MaxConcorSet_label_1, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->MaxConcorSet_label_1, mconcor_setting[cur_language]);
//	lv_label_set_long_mode(ui->MaxConcorSet_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_1, LV_LABEL_ALIGN_RIGHT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_1
	static lv_style_t style_MaxConcorSet_label_1_main;
	lv_style_reset(&style_MaxConcorSet_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_1_main
	lv_style_set_radius(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_1, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_1_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_1, 113, 32);
	lv_obj_set_size(ui->MaxConcorSet_label_1, 347, 42);

	//Write codes MaxConcorSet_label_6
	ui->MaxConcorSet_label_6 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_6, "X");
	lv_label_set_long_mode(ui->MaxConcorSet_label_6, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_6, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_6
	static lv_style_t style_MaxConcorSet_label_6_main;
	lv_style_reset(&style_MaxConcorSet_label_6_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_6_main
	lv_style_set_radius(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_6, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_6_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_6, 42, 132);
	lv_obj_set_size(ui->MaxConcorSet_label_6, 20, 0);

	//Write codes MaxConcorSet_label_xmconcor
	ui->MaxConcorSet_label_xmconcor = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_xmconcor, "");
	lv_label_set_long_mode(ui->MaxConcorSet_label_xmconcor, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_xmconcor, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_xmconcor
	static lv_style_t style_MaxConcorSet_label_xmconcor_main;
	lv_style_reset(&style_MaxConcorSet_label_xmconcor_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_xmconcor_main
	lv_style_set_radius(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_xmconcor_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_xmconcor, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_xmconcor_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_xmconcor, 34, 198);
	lv_obj_set_size(ui->MaxConcorSet_label_xmconcor, 80, 0);

	//Write codes MaxConcorSet_btn_ymcon
	ui->MaxConcorSet_btn_ymcon = lv_btn_create(ui->MaxConcorSet_cont_max_concor_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxConcorSet_btn_ymcon
	static lv_style_t style_MaxConcorSet_btn_ymcon_main;
	lv_style_reset(&style_MaxConcorSet_btn_ymcon_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_btn_ymcon_main
	lv_style_set_radius(&style_MaxConcorSet_btn_ymcon_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxConcorSet_btn_ymcon_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_btn_ymcon_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_btn_ymcon_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_btn_ymcon_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxConcorSet_btn_ymcon_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxConcorSet_btn_ymcon_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxConcorSet_btn_ymcon_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxConcorSet_btn_ymcon_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxConcorSet_btn_ymcon_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxConcorSet_btn_ymcon, LV_BTN_PART_MAIN, &style_MaxConcorSet_btn_ymcon_main);
	lv_obj_set_pos(ui->MaxConcorSet_btn_ymcon, 246, 106);
	lv_obj_set_size(ui->MaxConcorSet_btn_ymcon, 225, 206);
//	ui->MaxConcorSet_btn_ymcon_label = lv_label_create(ui->MaxConcorSet_btn_ymcon, NULL);
//	lv_label_set_text(ui->MaxConcorSet_btn_ymcon_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxConcorSet_btn_ymcon_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxConcorSet_label_15
	ui->MaxConcorSet_label_15 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_15, "mm/s");
	lv_label_set_long_mode(ui->MaxConcorSet_label_15, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_15, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_15
	static lv_style_t style_MaxConcorSet_label_15_main;
	lv_style_reset(&style_MaxConcorSet_label_15_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_15_main
	lv_style_set_radius(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_15, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_15_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_15, 334, 198);
	lv_obj_set_size(ui->MaxConcorSet_label_15, 150, 0);

	//Write codes MaxConcorSet_btn_zmcon
	ui->MaxConcorSet_btn_zmcon = lv_btn_create(ui->MaxConcorSet_cont_max_concor_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxConcorSet_btn_zmcon
	static lv_style_t style_MaxConcorSet_btn_zmcon_main;
	lv_style_reset(&style_MaxConcorSet_btn_zmcon_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_btn_zmcon_main
	lv_style_set_radius(&style_MaxConcorSet_btn_zmcon_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxConcorSet_btn_zmcon_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_btn_zmcon_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_btn_zmcon_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_btn_zmcon_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxConcorSet_btn_zmcon_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxConcorSet_btn_zmcon_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxConcorSet_btn_zmcon_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxConcorSet_btn_zmcon_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxConcorSet_btn_zmcon_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxConcorSet_btn_zmcon, LV_BTN_PART_MAIN, &style_MaxConcorSet_btn_zmcon_main);
	lv_obj_set_pos(ui->MaxConcorSet_btn_zmcon, 10, 326);
	lv_obj_set_size(ui->MaxConcorSet_btn_zmcon, 224, 206);
//	ui->MaxConcorSet_btn_zmcon_label = lv_label_create(ui->MaxConcorSet_btn_zmcon, NULL);
//	lv_label_set_text(ui->MaxConcorSet_btn_zmcon_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxConcorSet_btn_zmcon_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxConcorSet_btn_emcon
	ui->MaxConcorSet_btn_emcon = lv_btn_create(ui->MaxConcorSet_cont_max_concor_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxConcorSet_btn_emcon
	static lv_style_t style_MaxConcorSet_btn_emcon_main;
	lv_style_reset(&style_MaxConcorSet_btn_emcon_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_btn_emcon_main
	lv_style_set_radius(&style_MaxConcorSet_btn_emcon_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxConcorSet_btn_emcon_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_btn_emcon_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_btn_emcon_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_btn_emcon_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxConcorSet_btn_emcon_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxConcorSet_btn_emcon_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxConcorSet_btn_emcon_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxConcorSet_btn_emcon_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxConcorSet_btn_emcon_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxConcorSet_btn_emcon, LV_BTN_PART_MAIN, &style_MaxConcorSet_btn_emcon_main);
	lv_obj_set_pos(ui->MaxConcorSet_btn_emcon, 246, 326);
	lv_obj_set_size(ui->MaxConcorSet_btn_emcon, 225, 206);
//	ui->MaxConcorSet_btn_emcon_label = lv_label_create(ui->MaxConcorSet_btn_emcon, NULL);
//	lv_label_set_text(ui->MaxConcorSet_btn_emcon_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxConcorSet_btn_emcon_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxConcorSet_label_17
	ui->MaxConcorSet_label_17 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_17, "mm/s");
	lv_label_set_long_mode(ui->MaxConcorSet_label_17, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_17, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_17
	static lv_style_t style_MaxConcorSet_label_17_main;
	lv_style_reset(&style_MaxConcorSet_label_17_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_17_main
	lv_style_set_radius(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_17_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_17, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_17_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_17, 334, 418);
	lv_obj_set_size(ui->MaxConcorSet_label_17, 150, 0);

	//Write codes MaxConcorSet_label_16
	ui->MaxConcorSet_label_16 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_16, "mm/s");
	lv_label_set_long_mode(ui->MaxConcorSet_label_16, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_16, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_16
	static lv_style_t style_MaxConcorSet_label_16_main;
	lv_style_reset(&style_MaxConcorSet_label_16_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_16_main
	lv_style_set_radius(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_16_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_16, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_16_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_16, 98, 418);
	lv_obj_set_size(ui->MaxConcorSet_label_16, 150, 0);

	//Write codes MaxConcorSet_img_3
	ui->MaxConcorSet_img_3 = lv_img_create(ui->MaxConcorSet_cont_max_concor_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxConcorSet_img_3
//	static lv_style_t style_MaxConcorSet_img_3_main;
//	lv_style_reset(&style_MaxConcorSet_img_3_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_img_3_main
//	lv_style_set_image_recolor(&style_MaxConcorSet_img_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxConcorSet_img_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxConcorSet_img_3_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxConcorSet_img_3, LV_IMG_PART_MAIN, &style_MaxConcorSet_img_3_main);
	lv_obj_set_pos(ui->MaxConcorSet_img_3, 262, 119);
//	lv_obj_set_size(ui->MaxConcorSet_img_3, 44, 44);
//	lv_obj_set_click(ui->MaxConcorSet_img_3, true);
	lv_img_set_src(ui->MaxConcorSet_img_3,&_mconcer_alpha_44x44);
//	lv_img_set_pivot(ui->MaxConcorSet_img_3, 0,0);
//	lv_img_set_angle(ui->MaxConcorSet_img_3, 0);

	//Write codes MaxConcorSet_img_4
	ui->MaxConcorSet_img_4 = lv_img_create(ui->MaxConcorSet_cont_max_concor_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxConcorSet_img_4
//	static lv_style_t style_MaxConcorSet_img_4_main;
//	lv_style_reset(&style_MaxConcorSet_img_4_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_img_4_main
//	lv_style_set_image_recolor(&style_MaxConcorSet_img_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxConcorSet_img_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxConcorSet_img_4_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxConcorSet_img_4, LV_IMG_PART_MAIN, &style_MaxConcorSet_img_4_main);
	lv_obj_set_pos(ui->MaxConcorSet_img_4, 26, 339);
//	lv_obj_set_size(ui->MaxConcorSet_img_4, 44, 44);
//	lv_obj_set_click(ui->MaxConcorSet_img_4, true);
	lv_img_set_src(ui->MaxConcorSet_img_4,&_mconcer_alpha_44x44);
//	lv_img_set_pivot(ui->MaxConcorSet_img_4, 0,0);
//	lv_img_set_angle(ui->MaxConcorSet_img_4, 0);

	//Write codes MaxConcorSet_img_5
	ui->MaxConcorSet_img_5 = lv_img_create(ui->MaxConcorSet_cont_max_concor_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxConcorSet_img_5
//	static lv_style_t style_MaxConcorSet_img_5_main;
//	lv_style_reset(&style_MaxConcorSet_img_5_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_img_5_main
//	lv_style_set_image_recolor(&style_MaxConcorSet_img_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxConcorSet_img_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxConcorSet_img_5_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxConcorSet_img_5, LV_IMG_PART_MAIN, &style_MaxConcorSet_img_5_main);
	lv_obj_set_pos(ui->MaxConcorSet_img_5, 262, 339);
//	lv_obj_set_size(ui->MaxConcorSet_img_5, 44, 44);
//	lv_obj_set_click(ui->MaxConcorSet_img_5, true);
	lv_img_set_src(ui->MaxConcorSet_img_5,&_mconcer_alpha_44x44);
//	lv_img_set_pivot(ui->MaxConcorSet_img_5, 0,0);
//	lv_img_set_angle(ui->MaxConcorSet_img_5, 0);

	//Write codes MaxConcorSet_label_8
	ui->MaxConcorSet_label_8 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_8, "Y");
	lv_label_set_long_mode(ui->MaxConcorSet_label_8, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_8, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_8
	static lv_style_t style_MaxConcorSet_label_8_main;
	lv_style_reset(&style_MaxConcorSet_label_8_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_8_main
	lv_style_set_radius(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_8, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_8_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_8, 278, 132);
	lv_obj_set_size(ui->MaxConcorSet_label_8, 20, 0);

	//Write codes MaxConcorSet_label_9
	ui->MaxConcorSet_label_9 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_9, "E");
	lv_label_set_long_mode(ui->MaxConcorSet_label_9, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_9, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_9
	static lv_style_t style_MaxConcorSet_label_9_main;
	lv_style_reset(&style_MaxConcorSet_label_9_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_9_main
	lv_style_set_radius(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_9, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_9_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_9, 278, 352);
	lv_obj_set_size(ui->MaxConcorSet_label_9, 20, 0);

	//Write codes MaxConcorSet_label_10
	ui->MaxConcorSet_label_10 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_10, "Z");
	lv_label_set_long_mode(ui->MaxConcorSet_label_10, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_10, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_10
	static lv_style_t style_MaxConcorSet_label_10_main;
	lv_style_reset(&style_MaxConcorSet_label_10_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_10_main
	lv_style_set_radius(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_10, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_10_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_10, 42, 352);
	lv_obj_set_size(ui->MaxConcorSet_label_10, 20, 0);

	//Write codes MaxConcorSet_label_11
	ui->MaxConcorSet_label_11 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_long_mode(ui->MaxConcorSet_label_11, LV_LABEL_LONG_SROLL_CIRC);
	c[0] = 'E';
	lv_label_set_text(ui->MaxConcorSet_label_11, c);
//	lv_label_set_long_mode(ui->MaxConcorSet_label_11, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_11, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_11
	static lv_style_t style_MaxConcorSet_label_11_main;
	lv_style_reset(&style_MaxConcorSet_label_11_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_11_main
	lv_style_set_radius(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_11, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_11_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_11, 270, 480);
	lv_obj_set_size(ui->MaxConcorSet_label_11, 200, 42);

	//Write codes MaxConcorSet_label_12
	ui->MaxConcorSet_label_12 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_long_mode(ui->MaxConcorSet_label_12, LV_LABEL_LONG_SROLL_CIRC);
	c[0] = 'Z';
	lv_label_set_text(ui->MaxConcorSet_label_12, c);
//	lv_label_set_long_mode(ui->MaxConcorSet_label_12, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_12, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_12
	static lv_style_t style_MaxConcorSet_label_12_main;
	lv_style_reset(&style_MaxConcorSet_label_12_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_12_main
	lv_style_set_radius(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_12, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_12_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_12, 34, 480);
	lv_obj_set_size(ui->MaxConcorSet_label_12, 200, 42);

	//Write codes MaxConcorSet_label_13
	ui->MaxConcorSet_label_13 = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
    lv_label_set_long_mode(ui->MaxConcorSet_label_13, LV_LABEL_LONG_SROLL_CIRC);
	c[0] = 'Y';
	lv_label_set_text(ui->MaxConcorSet_label_13, c);
//	lv_label_set_long_mode(ui->MaxConcorSet_label_13, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_13, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_13
	static lv_style_t style_MaxConcorSet_label_13_main;
	lv_style_reset(&style_MaxConcorSet_label_13_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_13_main
	lv_style_set_radius(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_13, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_13_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_13, 270, 260);
	lv_obj_set_size(ui->MaxConcorSet_label_13, 200, 42);

	//Write codes MaxConcorSet_label_ymconcor
	ui->MaxConcorSet_label_ymconcor = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_ymconcor, "");
	lv_label_set_long_mode(ui->MaxConcorSet_label_ymconcor, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_ymconcor, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_ymconcor
	static lv_style_t style_MaxConcorSet_label_ymconcor_main;
	lv_style_reset(&style_MaxConcorSet_label_ymconcor_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_ymconcor_main
	lv_style_set_radius(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_ymconcor_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_ymconcor, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_ymconcor_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_ymconcor, 270, 198);
	lv_obj_set_size(ui->MaxConcorSet_label_ymconcor, 80, 0);

	//Write codes MaxConcorSet_label_zmconcor
	ui->MaxConcorSet_label_zmconcor = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_zmconcor, "");
	lv_label_set_long_mode(ui->MaxConcorSet_label_zmconcor, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_zmconcor, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_zmconcor
	static lv_style_t style_MaxConcorSet_label_zmconcor_main;
	lv_style_reset(&style_MaxConcorSet_label_zmconcor_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_zmconcor_main
	lv_style_set_radius(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxConcorSet_label_zmconcor_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_zmconcor, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_zmconcor_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_zmconcor, 34, 418);
	lv_obj_set_size(ui->MaxConcorSet_label_zmconcor, 80, 0);

	//Write codes MaxConcorSet_label_emconcor
	ui->MaxConcorSet_label_emconcor = lv_label_create(ui->MaxConcorSet_cont_max_concor_set, NULL);
	lv_label_set_text(ui->MaxConcorSet_label_emconcor, "");
	lv_label_set_long_mode(ui->MaxConcorSet_label_emconcor, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxConcorSet_label_emconcor, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxConcorSet_label_emconcor
	static lv_style_t style_MaxConcorSet_label_emconcor_main;
	lv_style_reset(&style_MaxConcorSet_label_emconcor_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxConcorSet_label_emconcor_main
	lv_style_set_radius(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_MaxConcorSet_label_emconcor_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxConcorSet_label_emconcor, LV_LABEL_PART_MAIN, &style_MaxConcorSet_label_emconcor_main);
	lv_obj_set_pos(ui->MaxConcorSet_label_emconcor, 270, 418);
	lv_obj_set_size(ui->MaxConcorSet_label_emconcor, 80, 0);
	lv_cont_set_layout(ui->MaxConcorSet_cont_max_concor_set, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->MaxConcorSet_cont_max_concor_set, LV_FIT_NONE);

	//Init events for screen
	events_init_MaxConcorSet(ui);
}
