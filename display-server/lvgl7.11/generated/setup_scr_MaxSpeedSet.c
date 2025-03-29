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

void setup_scr_MaxSpeedSet(lv_ui *ui){

	//Write codes MaxSpeedSet
//	ui->MaxSpeedSet = lv_obj_create(NULL, NULL);

	//Write codes MaxSpeedSet_cont_max_speed_set
	ui->MaxSpeedSet_cont_max_speed_set = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for MaxSpeedSet_cont_max_speed_set
	static lv_style_t style_MaxSpeedSet_cont_max_speed_set_main;
	lv_style_reset(&style_MaxSpeedSet_cont_max_speed_set_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_cont_max_speed_set_main
	lv_style_set_radius(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_cont_max_speed_set_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_cont_max_speed_set, LV_CONT_PART_MAIN, &style_MaxSpeedSet_cont_max_speed_set_main);
	lv_obj_set_pos(ui->MaxSpeedSet_cont_max_speed_set, 0, 0);
	lv_obj_set_size(ui->MaxSpeedSet_cont_max_speed_set, 480, 800);
	lv_obj_set_click(ui->MaxSpeedSet_cont_max_speed_set, false);

	//Write codes MaxSpeedSet_btn_xmspeed
	ui->MaxSpeedSet_btn_xmspeed = lv_btn_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxSpeedSet_btn_xmspeed
	static lv_style_t style_MaxSpeedSet_btn_xmspeed_main;
	lv_style_reset(&style_MaxSpeedSet_btn_xmspeed_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_btn_xmspeed_main
	lv_style_set_radius(&style_MaxSpeedSet_btn_xmspeed_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxSpeedSet_btn_xmspeed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_btn_xmspeed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_btn_xmspeed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_btn_xmspeed_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxSpeedSet_btn_xmspeed_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxSpeedSet_btn_xmspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxSpeedSet_btn_xmspeed_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxSpeedSet_btn_xmspeed_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxSpeedSet_btn_xmspeed_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxSpeedSet_btn_xmspeed, LV_BTN_PART_MAIN, &style_MaxSpeedSet_btn_xmspeed_main);
	lv_obj_set_pos(ui->MaxSpeedSet_btn_xmspeed, 10, 106);
	lv_obj_set_size(ui->MaxSpeedSet_btn_xmspeed, 224, 206);
//	ui->MaxSpeedSet_btn_xmspeed_label = lv_label_create(ui->MaxSpeedSet_btn_xmspeed, NULL);
//	lv_label_set_text(ui->MaxSpeedSet_btn_xmspeed_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxSpeedSet_btn_xmspeed_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxSpeedSet_label_17
	ui->MaxSpeedSet_label_17 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_17, "mm/s");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_17, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_17, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_17
	static lv_style_t style_MaxSpeedSet_label_17_main;
	lv_style_reset(&style_MaxSpeedSet_label_17_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_17_main
	lv_style_set_radius(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_17_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_17, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_17_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_17, 98, 198);
	lv_obj_set_size(ui->MaxSpeedSet_label_17, 150, 0);

	//Write codes MaxSpeedSet_label_2
	ui->MaxSpeedSet_label_2 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
    lv_label_set_long_mode(ui->MaxSpeedSet_label_2, LV_LABEL_LONG_SROLL_CIRC);
	char *c = malloc(strlen(mspeed_setting[cur_language]) + 2);
	strcpy(c, "X ");
    strcat(c, mspeed_setting[cur_language]);
	lv_label_set_text(ui->MaxSpeedSet_label_2, c);
//	lv_label_set_long_mode(ui->MaxSpeedSet_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_2, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_2
	static lv_style_t style_MaxSpeedSet_label_2_main;
	lv_style_reset(&style_MaxSpeedSet_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_2_main
	lv_style_set_radius(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_2, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_2_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_2, 34, 260);
	lv_obj_set_size(ui->MaxSpeedSet_label_2, 200, 42);

	//Write codes MaxSpeedSet_img_2
	ui->MaxSpeedSet_img_2 = lv_img_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxSpeedSet_img_2
//	static lv_style_t style_MaxSpeedSet_img_2_main;
//	lv_style_reset(&style_MaxSpeedSet_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_img_2_main
//	lv_style_set_image_recolor(&style_MaxSpeedSet_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxSpeedSet_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxSpeedSet_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxSpeedSet_img_2, LV_IMG_PART_MAIN, &style_MaxSpeedSet_img_2_main);
	lv_obj_set_pos(ui->MaxSpeedSet_img_2, 26, 119);
//	lv_obj_set_size(ui->MaxSpeedSet_img_2, 44, 39);
//	lv_obj_set_click(ui->MaxSpeedSet_img_2, true);
	lv_img_set_src(ui->MaxSpeedSet_img_2,&_mspeeda_alpha_44x39);
//	lv_img_set_pivot(ui->MaxSpeedSet_img_2, 0,0);
//	lv_img_set_angle(ui->MaxSpeedSet_img_2, 0);

	//Write codes MaxSpeedSet_label_1
	ui->MaxSpeedSet_label_1 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_long_mode(ui->MaxSpeedSet_label_1, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->MaxSpeedSet_label_1, mspeed_setting[cur_language]);
//	lv_label_set_long_mode(ui->MaxSpeedSet_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_1, LV_LABEL_ALIGN_RIGHT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_1
	static lv_style_t style_MaxSpeedSet_label_1_main;
	lv_style_reset(&style_MaxSpeedSet_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_1_main
	lv_style_set_radius(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_1, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_1_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_1, 113, 32);
	lv_obj_set_size(ui->MaxSpeedSet_label_1, 347, 42);

	//Write codes MaxSpeedSet_img_back
	ui->MaxSpeedSet_img_back = lv_img_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxSpeedSet_img_back
//	static lv_style_t style_MaxSpeedSet_img_back_main;
//	lv_style_reset(&style_MaxSpeedSet_img_back_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_img_back_main
//	lv_style_set_image_recolor(&style_MaxSpeedSet_img_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxSpeedSet_img_back_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxSpeedSet_img_back_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxSpeedSet_img_back, LV_IMG_PART_MAIN, &style_MaxSpeedSet_img_back_main);
	lv_obj_set_pos(ui->MaxSpeedSet_img_back, 24, 30);
//	lv_obj_set_size(ui->MaxSpeedSet_img_back, 45, 36);
	lv_obj_set_click(ui->MaxSpeedSet_img_back, true);
	lv_img_set_src(ui->MaxSpeedSet_img_back,&_return_alpha_45x36);
//	lv_img_set_pivot(ui->MaxSpeedSet_img_back, 0,0);
//	lv_img_set_angle(ui->MaxSpeedSet_img_back, 0);

	//Write codes MaxSpeedSet_label_6
	ui->MaxSpeedSet_label_6 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_6, "X");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_6, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_6, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_6
	static lv_style_t style_MaxSpeedSet_label_6_main;
	lv_style_reset(&style_MaxSpeedSet_label_6_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_6_main
	lv_style_set_radius(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_6, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_6_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_6, 42, 130);
	lv_obj_set_size(ui->MaxSpeedSet_label_6, 20, 0);

	//Write codes MaxSpeedSet_label_xmspeed
	ui->MaxSpeedSet_label_xmspeed = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_xmspeed, "");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_xmspeed, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_xmspeed, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_xmspeed
	static lv_style_t style_MaxSpeedSet_label_xmspeed_main;
	lv_style_reset(&style_MaxSpeedSet_label_xmspeed_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_xmspeed_main
	lv_style_set_radius(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_xmspeed_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_xmspeed, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_xmspeed_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_xmspeed, 34, 198);
	lv_obj_set_size(ui->MaxSpeedSet_label_xmspeed, 80, 0);

	//Write codes MaxSpeedSet_btn_ymspeed
	ui->MaxSpeedSet_btn_ymspeed = lv_btn_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxSpeedSet_btn_ymspeed
	static lv_style_t style_MaxSpeedSet_btn_ymspeed_main;
	lv_style_reset(&style_MaxSpeedSet_btn_ymspeed_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_btn_ymspeed_main
	lv_style_set_radius(&style_MaxSpeedSet_btn_ymspeed_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxSpeedSet_btn_ymspeed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_btn_ymspeed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_btn_ymspeed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_btn_ymspeed_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxSpeedSet_btn_ymspeed_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxSpeedSet_btn_ymspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxSpeedSet_btn_ymspeed_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxSpeedSet_btn_ymspeed_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxSpeedSet_btn_ymspeed_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxSpeedSet_btn_ymspeed, LV_BTN_PART_MAIN, &style_MaxSpeedSet_btn_ymspeed_main);
	lv_obj_set_pos(ui->MaxSpeedSet_btn_ymspeed, 246, 106);
	lv_obj_set_size(ui->MaxSpeedSet_btn_ymspeed, 225, 206);
//	ui->MaxSpeedSet_btn_ymspeed_label = lv_label_create(ui->MaxSpeedSet_btn_ymspeed, NULL);
//	lv_label_set_text(ui->MaxSpeedSet_btn_ymspeed_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxSpeedSet_btn_ymspeed_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxSpeedSet_label_16
	ui->MaxSpeedSet_label_16 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_16, "mm/s");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_16, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_16, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_16
	static lv_style_t style_MaxSpeedSet_label_16_main;
	lv_style_reset(&style_MaxSpeedSet_label_16_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_16_main
	lv_style_set_radius(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_16_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_16, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_16_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_16, 334, 198);
	lv_obj_set_size(ui->MaxSpeedSet_label_16, 150, 0);

	//Write codes MaxSpeedSet_btn_zmspeed
	ui->MaxSpeedSet_btn_zmspeed = lv_btn_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxSpeedSet_btn_zmspeed
	static lv_style_t style_MaxSpeedSet_btn_zmspeed_main;
	lv_style_reset(&style_MaxSpeedSet_btn_zmspeed_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_btn_zmspeed_main
	lv_style_set_radius(&style_MaxSpeedSet_btn_zmspeed_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxSpeedSet_btn_zmspeed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_btn_zmspeed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_btn_zmspeed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_btn_zmspeed_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxSpeedSet_btn_zmspeed_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxSpeedSet_btn_zmspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxSpeedSet_btn_zmspeed_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxSpeedSet_btn_zmspeed_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxSpeedSet_btn_zmspeed_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxSpeedSet_btn_zmspeed, LV_BTN_PART_MAIN, &style_MaxSpeedSet_btn_zmspeed_main);
	lv_obj_set_pos(ui->MaxSpeedSet_btn_zmspeed, 10, 326);
	lv_obj_set_size(ui->MaxSpeedSet_btn_zmspeed, 224, 206);
//	ui->MaxSpeedSet_btn_zmspeed_label = lv_label_create(ui->MaxSpeedSet_btn_zmspeed, NULL);
//	lv_label_set_text(ui->MaxSpeedSet_btn_zmspeed_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxSpeedSet_btn_zmspeed_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxSpeedSet_label_15
	ui->MaxSpeedSet_label_15 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_15, "mm/s");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_15, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_15, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_15
	static lv_style_t style_MaxSpeedSet_label_15_main;
	lv_style_reset(&style_MaxSpeedSet_label_15_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_15_main
	lv_style_set_radius(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_15_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_15, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_15_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_15, 98, 418);
	lv_obj_set_size(ui->MaxSpeedSet_label_15, 150, 0);

	//Write codes MaxSpeedSet_btn_emspeed
	ui->MaxSpeedSet_btn_emspeed = lv_btn_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);

	//Write style LV_BTN_PART_MAIN for MaxSpeedSet_btn_emspeed
	static lv_style_t style_MaxSpeedSet_btn_emspeed_main;
	lv_style_reset(&style_MaxSpeedSet_btn_emspeed_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_btn_emspeed_main
	lv_style_set_radius(&style_MaxSpeedSet_btn_emspeed_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_MaxSpeedSet_btn_emspeed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_btn_emspeed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_btn_emspeed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_btn_emspeed_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_MaxSpeedSet_btn_emspeed_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_MaxSpeedSet_btn_emspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_MaxSpeedSet_btn_emspeed_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_MaxSpeedSet_btn_emspeed_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_MaxSpeedSet_btn_emspeed_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->MaxSpeedSet_btn_emspeed, LV_BTN_PART_MAIN, &style_MaxSpeedSet_btn_emspeed_main);
	lv_obj_set_pos(ui->MaxSpeedSet_btn_emspeed, 246, 326);
	lv_obj_set_size(ui->MaxSpeedSet_btn_emspeed, 225, 206);
//	ui->MaxSpeedSet_btn_emspeed_label = lv_label_create(ui->MaxSpeedSet_btn_emspeed, NULL);
//	lv_label_set_text(ui->MaxSpeedSet_btn_emspeed_label, "");
//	lv_obj_set_style_local_text_color(ui->MaxSpeedSet_btn_emspeed_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes MaxSpeedSet_label_14
	ui->MaxSpeedSet_label_14 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_14, "mm/s");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_14, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_14, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_14
	static lv_style_t style_MaxSpeedSet_label_14_main;
	lv_style_reset(&style_MaxSpeedSet_label_14_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_14_main
	lv_style_set_radius(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_14_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_14, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_14_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_14, 334, 418);
	lv_obj_set_size(ui->MaxSpeedSet_label_14, 150, 0);

	//Write codes MaxSpeedSet_img_3
	ui->MaxSpeedSet_img_3 = lv_img_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxSpeedSet_img_3
//	static lv_style_t style_MaxSpeedSet_img_3_main;
//	lv_style_reset(&style_MaxSpeedSet_img_3_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_img_3_main
//	lv_style_set_image_recolor(&style_MaxSpeedSet_img_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxSpeedSet_img_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxSpeedSet_img_3_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxSpeedSet_img_3, LV_IMG_PART_MAIN, &style_MaxSpeedSet_img_3_main);
	lv_obj_set_pos(ui->MaxSpeedSet_img_3, 262, 119);
//	lv_obj_set_size(ui->MaxSpeedSet_img_3, 44, 39);
//	lv_obj_set_click(ui->MaxSpeedSet_img_3, true);
	lv_img_set_src(ui->MaxSpeedSet_img_3,&_mspeeda_alpha_44x39);
//	lv_img_set_pivot(ui->MaxSpeedSet_img_3, 0,0);
//	lv_img_set_angle(ui->MaxSpeedSet_img_3, 0);

	//Write codes MaxSpeedSet_img_4
	ui->MaxSpeedSet_img_4 = lv_img_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxSpeedSet_img_4
//	static lv_style_t style_MaxSpeedSet_img_4_main;
//	lv_style_reset(&style_MaxSpeedSet_img_4_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_img_4_main
//	lv_style_set_image_recolor(&style_MaxSpeedSet_img_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxSpeedSet_img_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxSpeedSet_img_4_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxSpeedSet_img_4, LV_IMG_PART_MAIN, &style_MaxSpeedSet_img_4_main);
	lv_obj_set_pos(ui->MaxSpeedSet_img_4, 26, 339);
//	lv_obj_set_size(ui->MaxSpeedSet_img_4, 44, 39);
//	lv_obj_set_click(ui->MaxSpeedSet_img_4, true);
	lv_img_set_src(ui->MaxSpeedSet_img_4,&_mspeeda_alpha_44x39);
//	lv_img_set_pivot(ui->MaxSpeedSet_img_4, 0,0);
//	lv_img_set_angle(ui->MaxSpeedSet_img_4, 0);

	//Write codes MaxSpeedSet_img_5
	ui->MaxSpeedSet_img_5 = lv_img_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);

	//Write style LV_IMG_PART_MAIN for MaxSpeedSet_img_5
//	static lv_style_t style_MaxSpeedSet_img_5_main;
//	lv_style_reset(&style_MaxSpeedSet_img_5_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_img_5_main
//	lv_style_set_image_recolor(&style_MaxSpeedSet_img_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_MaxSpeedSet_img_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_MaxSpeedSet_img_5_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->MaxSpeedSet_img_5, LV_IMG_PART_MAIN, &style_MaxSpeedSet_img_5_main);
	lv_obj_set_pos(ui->MaxSpeedSet_img_5, 262, 339);
//	lv_obj_set_size(ui->MaxSpeedSet_img_5, 44, 39);
//	lv_obj_set_click(ui->MaxSpeedSet_img_5, true);
	lv_img_set_src(ui->MaxSpeedSet_img_5,&_mspeeda_alpha_44x39);
//	lv_img_set_pivot(ui->MaxSpeedSet_img_5, 0,0);
//	lv_img_set_angle(ui->MaxSpeedSet_img_5, 0);

	//Write codes MaxSpeedSet_label_8
	ui->MaxSpeedSet_label_8 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_8, "Y");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_8, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_8, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_8
	static lv_style_t style_MaxSpeedSet_label_8_main;
	lv_style_reset(&style_MaxSpeedSet_label_8_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_8_main
	lv_style_set_radius(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_8, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_8_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_8, 278, 130);
	lv_obj_set_size(ui->MaxSpeedSet_label_8, 20, 0);

	//Write codes MaxSpeedSet_label_9
	ui->MaxSpeedSet_label_9 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_9, "E");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_9, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_9, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_9
	static lv_style_t style_MaxSpeedSet_label_9_main;
	lv_style_reset(&style_MaxSpeedSet_label_9_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_9_main
	lv_style_set_radius(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_9, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_9_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_9, 278, 350);
	lv_obj_set_size(ui->MaxSpeedSet_label_9, 20, 0);

	//Write codes MaxSpeedSet_label_10
	ui->MaxSpeedSet_label_10 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_10, "Z");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_10, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_10, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_10
	static lv_style_t style_MaxSpeedSet_label_10_main;
	lv_style_reset(&style_MaxSpeedSet_label_10_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_10_main
	lv_style_set_radius(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_10, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_10_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_10, 42, 350);
	lv_obj_set_size(ui->MaxSpeedSet_label_10, 20, 0);

	//Write codes MaxSpeedSet_label_11
	ui->MaxSpeedSet_label_11 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_long_mode(ui->MaxSpeedSet_label_11, LV_LABEL_LONG_SROLL_CIRC);
	c[0] = 'E';
	lv_label_set_text(ui->MaxSpeedSet_label_11, c);
//	lv_label_set_long_mode(ui->MaxSpeedSet_label_11, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_11, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_11
	static lv_style_t style_MaxSpeedSet_label_11_main;
	lv_style_reset(&style_MaxSpeedSet_label_11_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_11_main
	lv_style_set_radius(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_11, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_11_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_11, 270, 480);
	lv_obj_set_size(ui->MaxSpeedSet_label_11, 200, 42);

	//Write codes MaxSpeedSet_label_12
	ui->MaxSpeedSet_label_12 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
    lv_label_set_long_mode(ui->MaxSpeedSet_label_12, LV_LABEL_LONG_SROLL_CIRC);
	c[0] = 'Z';
	lv_label_set_text(ui->MaxSpeedSet_label_12, c);
//	lv_label_set_long_mode(ui->MaxSpeedSet_label_12, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_12, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_12
	static lv_style_t style_MaxSpeedSet_label_12_main;
	lv_style_reset(&style_MaxSpeedSet_label_12_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_12_main
	lv_style_set_radius(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_12, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_12_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_12, 34, 480);
	lv_obj_set_size(ui->MaxSpeedSet_label_12, 200, 42);

	//Write codes MaxSpeedSet_label_13
	ui->MaxSpeedSet_label_13 = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
    lv_label_set_long_mode(ui->MaxSpeedSet_label_13, LV_LABEL_LONG_SROLL_CIRC);
	c[0] = 'Y';
	lv_label_set_text(ui->MaxSpeedSet_label_13, c);
//	lv_label_set_long_mode(ui->MaxSpeedSet_label_13, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_13, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_13
	static lv_style_t style_MaxSpeedSet_label_13_main;
	lv_style_reset(&style_MaxSpeedSet_label_13_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_13_main
	lv_style_set_radius(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_13, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_13_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_13, 270, 260);
	lv_obj_set_size(ui->MaxSpeedSet_label_13, 200, 42);

	//Write codes MaxSpeedSet_label_ymspeed
	ui->MaxSpeedSet_label_ymspeed = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_ymspeed, "");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_ymspeed, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_ymspeed, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_ymspeed
	static lv_style_t style_MaxSpeedSet_label_ymspeed_main;
	lv_style_reset(&style_MaxSpeedSet_label_ymspeed_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_ymspeed_main
	lv_style_set_radius(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_ymspeed_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_ymspeed, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_ymspeed_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_ymspeed, 270, 198);
	lv_obj_set_size(ui->MaxSpeedSet_label_ymspeed, 80, 0);

	//Write codes MaxSpeedSet_label_zmspeed
	ui->MaxSpeedSet_label_zmspeed = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_zmspeed, "");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_zmspeed, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_zmspeed, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_zmspeed
	static lv_style_t style_MaxSpeedSet_label_zmspeed_main;
	lv_style_reset(&style_MaxSpeedSet_label_zmspeed_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_zmspeed_main
	lv_style_set_radius(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_zmspeed_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_zmspeed, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_zmspeed_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_zmspeed, 34, 418);
	lv_obj_set_size(ui->MaxSpeedSet_label_zmspeed, 80, 0);

	//Write codes MaxSpeedSet_label_emspeed
	ui->MaxSpeedSet_label_emspeed = lv_label_create(ui->MaxSpeedSet_cont_max_speed_set, NULL);
	lv_label_set_text(ui->MaxSpeedSet_label_emspeed, "");
	lv_label_set_long_mode(ui->MaxSpeedSet_label_emspeed, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->MaxSpeedSet_label_emspeed, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for MaxSpeedSet_label_emspeed
	static lv_style_t style_MaxSpeedSet_label_emspeed_main;
	lv_style_reset(&style_MaxSpeedSet_label_emspeed_main);

	//Write style state: LV_STATE_DEFAULT for style_MaxSpeedSet_label_emspeed_main
	lv_style_set_radius(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_MaxSpeedSet_label_emspeed_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->MaxSpeedSet_label_emspeed, LV_LABEL_PART_MAIN, &style_MaxSpeedSet_label_emspeed_main);
	lv_obj_set_pos(ui->MaxSpeedSet_label_emspeed, 270, 418);
	lv_obj_set_size(ui->MaxSpeedSet_label_emspeed, 80, 0);
	lv_cont_set_layout(ui->MaxSpeedSet_cont_max_speed_set, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->MaxSpeedSet_cont_max_speed_set, LV_FIT_NONE);

	//Init events for screen
	events_init_MaxSpeedSet(ui);
}
