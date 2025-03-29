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

void setup_scr_Preheating(lv_ui *ui){

	//Write codes Preheating
//	ui->Preheating = lv_obj_create(NULL, NULL);

	//Write codes Preheating_cont_preheating
	ui->Preheating_cont_preheating = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for Preheating_cont_preheating
	static lv_style_t style_Preheating_cont_preheating_main;
	lv_style_reset(&style_Preheating_cont_preheating_main);

	//Write style state: LV_STATE_DEFAULT for style_Preheating_cont_preheating_main
	lv_style_set_radius(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Preheating_cont_preheating_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Preheating_cont_preheating, LV_CONT_PART_MAIN, &style_Preheating_cont_preheating_main);
	lv_obj_set_pos(ui->Preheating_cont_preheating, 0, 0);
	lv_obj_set_size(ui->Preheating_cont_preheating, 480, 800);
	lv_obj_set_click(ui->Preheating_cont_preheating, false);

	//Write codes Preheating_btn_preheat_hotend
	ui->Preheating_btn_preheat_hotend = lv_btn_create(ui->Preheating_cont_preheating, NULL);

	//Write style LV_BTN_PART_MAIN for Preheating_btn_preheat_hotend
	static lv_style_t style_Preheating_btn_preheat_hotend_main;
	lv_style_reset(&style_Preheating_btn_preheat_hotend_main);

	//Write style state: LV_STATE_DEFAULT for style_Preheating_btn_preheat_hotend_main
	lv_style_set_radius(&style_Preheating_btn_preheat_hotend_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Preheating_btn_preheat_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Preheating_btn_preheat_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Preheating_btn_preheat_hotend_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Preheating_btn_preheat_hotend_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Preheating_btn_preheat_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Preheating_btn_preheat_hotend_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Preheating_btn_preheat_hotend_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Preheating_btn_preheat_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Preheating_btn_preheat_hotend_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Preheating_btn_preheat_hotend, LV_BTN_PART_MAIN, &style_Preheating_btn_preheat_hotend_main);
	lv_obj_set_pos(ui->Preheating_btn_preheat_hotend, 39, 107);
	lv_obj_set_size(ui->Preheating_btn_preheat_hotend, 402, 118);
//	ui->Preheating_btn_preheat_hotend_label = lv_label_create(ui->Preheating_btn_preheat_hotend, NULL);
//	lv_label_set_text(ui->Preheating_btn_preheat_hotend_label, "");
//	lv_obj_set_style_local_text_color(ui->Preheating_btn_preheat_hotend_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Preheating_label_2
	ui->Preheating_label_2 = lv_label_create(ui->Preheating_cont_preheating, NULL);
	lv_label_set_text(ui->Preheating_label_2, hotend_temp[cur_language]);
	lv_label_set_long_mode(ui->Preheating_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Preheating_label_2, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Preheating_label_2
	static lv_style_t style_Preheating_label_2_main;
	lv_style_reset(&style_Preheating_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_Preheating_label_2_main
	lv_style_set_radius(&style_Preheating_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Preheating_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Preheating_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Preheating_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Preheating_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Preheating_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_Preheating_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_Preheating_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_Preheating_label_2_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Preheating_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Preheating_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Preheating_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Preheating_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Preheating_label_2, LV_LABEL_PART_MAIN, &style_Preheating_label_2_main);
	lv_obj_set_pos(ui->Preheating_label_2, 155, 126);
	lv_obj_set_size(ui->Preheating_label_2, 250, 42);

	//Write codes Preheating_img_2
	ui->Preheating_img_2 = lv_img_create(ui->Preheating_cont_preheating, NULL);

	//Write style LV_IMG_PART_MAIN for Preheating_img_2
//	static lv_style_t style_Preheating_img_2_main;
//	lv_style_reset(&style_Preheating_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Preheating_img_2_main
//	lv_style_set_image_recolor(&style_Preheating_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Preheating_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Preheating_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Preheating_img_2, LV_IMG_PART_MAIN, &style_Preheating_img_2_main);
	lv_obj_set_pos(ui->Preheating_img_2, 84, 142);
//	lv_obj_set_size(ui->Preheating_img_2, 44, 44);
//	lv_obj_set_click(ui->Preheating_img_2, true);
	lv_img_set_src(ui->Preheating_img_2,&_hotend_alpha_44x44);
//	lv_img_set_pivot(ui->Preheating_img_2, 0,0);
//	lv_img_set_angle(ui->Preheating_img_2, 0);

	//Write codes Preheating_img_back
	ui->Preheating_img_back = lv_img_create(ui->Preheating_cont_preheating, NULL);

	//Write style LV_IMG_PART_MAIN for Preheating_img_back
//	static lv_style_t style_Preheating_img_back_main;
//	lv_style_reset(&style_Preheating_img_back_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Preheating_img_back_main
//	lv_style_set_image_recolor(&style_Preheating_img_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Preheating_img_back_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Preheating_img_back_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Preheating_img_back, LV_IMG_PART_MAIN, &style_Preheating_img_back_main);
	lv_obj_set_pos(ui->Preheating_img_back, 24, 30);
//	lv_obj_set_size(ui->Preheating_img_back, 45, 36);
	lv_obj_set_click(ui->Preheating_img_back, true);
	lv_img_set_src(ui->Preheating_img_back,&_return_alpha_45x36);
//	lv_img_set_pivot(ui->Preheating_img_back, 0,0);
//	lv_img_set_angle(ui->Preheating_img_back, 0);

	//Write codes Preheating_label_preheat_title
	ui->Preheating_label_preheat_title = lv_label_create(ui->Preheating_cont_preheating, NULL);
    lv_label_set_long_mode(ui->Preheating_label_preheat_title, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->Preheating_label_preheat_title, pla_setting[cur_language]);
//	lv_label_set_long_mode(ui->Preheating_label_preheat_title, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Preheating_label_preheat_title, LV_LABEL_ALIGN_RIGHT);

	//Write style LV_LABEL_PART_MAIN for Preheating_label_preheat_title
	static lv_style_t style_Preheating_label_preheat_title_main;
	lv_style_reset(&style_Preheating_label_preheat_title_main);

	//Write style state: LV_STATE_DEFAULT for style_Preheating_label_preheat_title_main
	lv_style_set_radius(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
	else
    {
        lv_style_set_text_font(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Preheating_label_preheat_title_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Preheating_label_preheat_title, LV_LABEL_PART_MAIN, &style_Preheating_label_preheat_title_main);
	lv_obj_set_pos(ui->Preheating_label_preheat_title, 113, 32);
	lv_obj_set_size(ui->Preheating_label_preheat_title, 347, 42);

	//Write codes Preheating_label_preheat_hotend
	ui->Preheating_label_preheat_hotend = lv_label_create(ui->Preheating_cont_preheating, NULL);
	lv_label_set_text(ui->Preheating_label_preheat_hotend, "");
	lv_label_set_long_mode(ui->Preheating_label_preheat_hotend, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Preheating_label_preheat_hotend, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Preheating_label_preheat_hotend
	static lv_style_t style_Preheating_label_preheat_hotend_main;
	lv_style_reset(&style_Preheating_label_preheat_hotend_main);

	//Write style state: LV_STATE_DEFAULT for style_Preheating_label_preheat_hotend_main
	lv_style_set_radius(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Preheating_label_preheat_hotend_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Preheating_label_preheat_hotend, LV_LABEL_PART_MAIN, &style_Preheating_label_preheat_hotend_main);
	lv_obj_set_pos(ui->Preheating_label_preheat_hotend, 154, 167);
	lv_obj_set_size(ui->Preheating_label_preheat_hotend, 250, 0);

	//Write codes Preheating_btn_preheat_bed
	ui->Preheating_btn_preheat_bed = lv_btn_create(ui->Preheating_cont_preheating, NULL);

	//Write style LV_BTN_PART_MAIN for Preheating_btn_preheat_bed
	static lv_style_t style_Preheating_btn_preheat_bed_main;
	lv_style_reset(&style_Preheating_btn_preheat_bed_main);

	//Write style state: LV_STATE_DEFAULT for style_Preheating_btn_preheat_bed_main
	lv_style_set_radius(&style_Preheating_btn_preheat_bed_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Preheating_btn_preheat_bed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Preheating_btn_preheat_bed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Preheating_btn_preheat_bed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Preheating_btn_preheat_bed_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Preheating_btn_preheat_bed_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Preheating_btn_preheat_bed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Preheating_btn_preheat_bed_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Preheating_btn_preheat_bed_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Preheating_btn_preheat_bed_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Preheating_btn_preheat_bed, LV_BTN_PART_MAIN, &style_Preheating_btn_preheat_bed_main);
	lv_obj_set_pos(ui->Preheating_btn_preheat_bed, 39, 247);
	lv_obj_set_size(ui->Preheating_btn_preheat_bed, 402, 118);
//	ui->Preheating_btn_preheat_bed_label = lv_label_create(ui->Preheating_btn_preheat_bed, NULL);
//	lv_label_set_text(ui->Preheating_btn_preheat_bed_label, "");
//	lv_obj_set_style_local_text_color(ui->Preheating_btn_preheat_bed_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Preheating_img_3
	ui->Preheating_img_3 = lv_img_create(ui->Preheating_cont_preheating, NULL);

	//Write style LV_IMG_PART_MAIN for Preheating_img_3
//	static lv_style_t style_Preheating_img_3_main;
//	lv_style_reset(&style_Preheating_img_3_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Preheating_img_3_main
//	lv_style_set_image_recolor(&style_Preheating_img_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Preheating_img_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Preheating_img_3_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Preheating_img_3, LV_IMG_PART_MAIN, &style_Preheating_img_3_main);
	lv_obj_set_pos(ui->Preheating_img_3, 84, 285);
//	lv_obj_set_size(ui->Preheating_img_3, 44, 44);
//	lv_obj_set_click(ui->Preheating_img_3, true);
	lv_img_set_src(ui->Preheating_img_3,&_hotbed_alpha_44x44);
//	lv_img_set_pivot(ui->Preheating_img_3, 0,0);
//	lv_img_set_angle(ui->Preheating_img_3, 0);

	//Write codes Preheating_label_4
	ui->Preheating_label_4 = lv_label_create(ui->Preheating_cont_preheating, NULL);
	lv_label_set_text(ui->Preheating_label_4, bed_temp[cur_language]);
	lv_label_set_long_mode(ui->Preheating_label_4, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Preheating_label_4, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Preheating_label_4
	static lv_style_t style_Preheating_label_4_main;
	lv_style_reset(&style_Preheating_label_4_main);

	//Write style state: LV_STATE_DEFAULT for style_Preheating_label_4_main
	lv_style_set_radius(&style_Preheating_label_4_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Preheating_label_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Preheating_label_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Preheating_label_4_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Preheating_label_4_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Preheating_label_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_Preheating_label_4_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_Preheating_label_4_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_Preheating_label_4_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Preheating_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Preheating_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Preheating_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Preheating_label_4_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Preheating_label_4, LV_LABEL_PART_MAIN, &style_Preheating_label_4_main);
	lv_obj_set_pos(ui->Preheating_label_4, 155, 265);
	lv_obj_set_size(ui->Preheating_label_4, 250, 0);

	//Write codes Preheating_label_preheat_bed
	ui->Preheating_label_preheat_bed = lv_label_create(ui->Preheating_cont_preheating, NULL);
	lv_label_set_text(ui->Preheating_label_preheat_bed, "");
	lv_label_set_long_mode(ui->Preheating_label_preheat_bed, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Preheating_label_preheat_bed, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for Preheating_label_preheat_bed
	static lv_style_t style_Preheating_label_preheat_bed_main;
	lv_style_reset(&style_Preheating_label_preheat_bed_main);

	//Write style state: LV_STATE_DEFAULT for style_Preheating_label_preheat_bed_main
	lv_style_set_radius(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_Preheating_label_preheat_bed_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Preheating_label_preheat_bed, LV_LABEL_PART_MAIN, &style_Preheating_label_preheat_bed_main);
	lv_obj_set_pos(ui->Preheating_label_preheat_bed, 154, 306);
	lv_obj_set_size(ui->Preheating_label_preheat_bed, 250, 0);
	lv_cont_set_layout(ui->Preheating_cont_preheating, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->Preheating_cont_preheating, LV_FIT_NONE);

	//Init events for screen
	events_init_Preheating(ui);
}
