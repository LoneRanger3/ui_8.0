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

void setup_scr_prepare_material(lv_ui *ui){

	//Write codes prepare_material
//	ui->prepare_material = lv_obj_create(NULL, NULL);

	if(ui->prepare_material_cont_prepare_material != NULL)
    {
        return;
    }
	//Write codes prepare_material_cont_prepare_material
	ui->prepare_material_cont_prepare_material = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for prepare_material_cont_prepare_material
	static lv_style_t style_prepare_material_cont_prepare_material_main;
	lv_style_reset(&style_prepare_material_cont_prepare_material_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_cont_prepare_material_main
	lv_style_set_radius(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_material_cont_prepare_material_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_material_cont_prepare_material, LV_CONT_PART_MAIN, &style_prepare_material_cont_prepare_material_main);
	lv_obj_set_pos(ui->prepare_material_cont_prepare_material, 0, 0);
	lv_obj_set_size(ui->prepare_material_cont_prepare_material, 480, 674);
	lv_obj_set_click(ui->prepare_material_cont_prepare_material, false);

	//Write codes prepare_material_label_material_length
	ui->prepare_material_label_material_length = lv_label_create(ui->prepare_material_cont_prepare_material, NULL);
	lv_label_set_text(ui->prepare_material_label_material_length, "1");
	lv_label_set_long_mode(ui->prepare_material_label_material_length, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_material_label_material_length, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_material_label_material_length
	static lv_style_t style_prepare_material_label_material_length_main;
	lv_style_reset(&style_prepare_material_label_material_length_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_label_material_length_main
	lv_style_set_radius(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_material_label_material_length_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_material_label_material_length, LV_LABEL_PART_MAIN, &style_prepare_material_label_material_length_main);
	lv_obj_set_pos(ui->prepare_material_label_material_length, 180, 555);
	lv_obj_set_size(ui->prepare_material_label_material_length, 120, 0);

	//Write codes prepare_material_slider_1
	ui->prepare_material_slider_1 = lv_slider_create(ui->prepare_material_cont_prepare_material, NULL);

	//Write style LV_SLIDER_PART_INDIC for prepare_material_slider_1
	static lv_style_t style_prepare_material_slider_1_indic;
	lv_style_reset(&style_prepare_material_slider_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_slider_1_indic
	lv_style_set_radius(&style_prepare_material_slider_1_indic, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_prepare_material_slider_1_indic, LV_STATE_DEFAULT, lv_color_make(0x02, 0xa2, 0xb1));
	//lv_style_set_bg_grad_color(&style_prepare_material_slider_1_indic, LV_STATE_DEFAULT, lv_color_make(0x02, 0xa2, 0xb1));
	//lv_style_set_bg_grad_dir(&style_prepare_material_slider_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_slider_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_material_slider_1, LV_SLIDER_PART_INDIC, &style_prepare_material_slider_1_indic);

	//Write style LV_SLIDER_PART_BG for prepare_material_slider_1
	static lv_style_t style_prepare_material_slider_1_bg;
	lv_style_reset(&style_prepare_material_slider_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_slider_1_bg
	lv_style_set_radius(&style_prepare_material_slider_1_bg, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_prepare_material_slider_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	//lv_style_set_bg_grad_color(&style_prepare_material_slider_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	//lv_style_set_bg_grad_dir(&style_prepare_material_slider_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_slider_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_material_slider_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_prepare_material_slider_1_bg, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_left(&style_prepare_material_slider_1_bg, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_material_slider_1_bg, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_material_slider_1_bg, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_material_slider_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_material_slider_1, LV_SLIDER_PART_BG, &style_prepare_material_slider_1_bg);

	//Write style LV_SLIDER_PART_KNOB for prepare_material_slider_1
	static lv_style_t style_prepare_material_slider_1_knob;
	lv_style_reset(&style_prepare_material_slider_1_knob);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_slider_1_knob
	lv_style_set_radius(&style_prepare_material_slider_1_knob, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_prepare_material_slider_1_knob, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_color(&style_prepare_material_slider_1_knob, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_dir(&style_prepare_material_slider_1_knob, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_slider_1_knob, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_material_slider_1, LV_SLIDER_PART_KNOB, &style_prepare_material_slider_1_knob);
	lv_obj_set_pos(ui->prepare_material_slider_1, 125, 600);
	lv_obj_set_size(ui->prepare_material_slider_1, 230, 12);
	lv_slider_set_range(ui->prepare_material_slider_1,1, 100);
	lv_slider_set_value(ui->prepare_material_slider_1,1,false);

	//Write codes prepare_material_btn_hotend_temp
	ui->prepare_material_btn_hotend_temp = lv_btn_create(ui->prepare_material_cont_prepare_material, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_material_btn_hotend_temp
	static lv_style_t style_prepare_material_btn_hotend_temp_main;
	lv_style_reset(&style_prepare_material_btn_hotend_temp_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_btn_hotend_temp_main
	lv_style_set_radius(&style_prepare_material_btn_hotend_temp_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_prepare_material_btn_hotend_temp_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_material_btn_hotend_temp_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_material_btn_hotend_temp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_btn_hotend_temp_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_material_btn_hotend_temp_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_material_btn_hotend_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_material_btn_hotend_temp_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_material_btn_hotend_temp_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_material_btn_hotend_temp_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_material_btn_hotend_temp, LV_BTN_PART_MAIN, &style_prepare_material_btn_hotend_temp_main);
	lv_obj_set_pos(ui->prepare_material_btn_hotend_temp, 14, 306);
	lv_obj_set_size(ui->prepare_material_btn_hotend_temp, 218, 158);
//	ui->prepare_material_btn_hotend_temp_label = lv_label_create(ui->prepare_material_btn_hotend_temp, NULL);
//	lv_label_set_text(ui->prepare_material_btn_hotend_temp_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_material_btn_hotend_temp_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_material_btn_material_out
	ui->prepare_material_btn_material_out = lv_btn_create(ui->prepare_material_cont_prepare_material, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_material_btn_material_out
	static lv_style_t style_prepare_material_btn_material_out_main;
	lv_style_reset(&style_prepare_material_btn_material_out_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_btn_material_out_main
	lv_style_set_radius(&style_prepare_material_btn_material_out_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_prepare_material_btn_material_out_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_material_btn_material_out_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_material_btn_material_out_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_btn_material_out_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_material_btn_material_out_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_material_btn_material_out_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_material_btn_material_out_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_material_btn_material_out_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_material_btn_material_out_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_material_btn_material_out, LV_BTN_PART_MAIN, &style_prepare_material_btn_material_out_main);
	lv_obj_set_pos(ui->prepare_material_btn_material_out, 246, 130);
	lv_obj_set_size(ui->prepare_material_btn_material_out, 218, 158);
//	ui->prepare_material_btn_material_out_label = lv_label_create(ui->prepare_material_btn_material_out, NULL);
//	lv_label_set_text(ui->prepare_material_btn_material_out_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_material_btn_material_out_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_material_btn_material_in
	ui->prepare_material_btn_material_in = lv_btn_create(ui->prepare_material_cont_prepare_material, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_material_btn_material_in
	static lv_style_t style_prepare_material_btn_material_in_main;
	lv_style_reset(&style_prepare_material_btn_material_in_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_btn_material_in_main
	lv_style_set_radius(&style_prepare_material_btn_material_in_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_prepare_material_btn_material_in_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_material_btn_material_in_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_material_btn_material_in_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_btn_material_in_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_material_btn_material_in_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_material_btn_material_in_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_material_btn_material_in_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_material_btn_material_in_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_material_btn_material_in_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_material_btn_material_in, LV_BTN_PART_MAIN, &style_prepare_material_btn_material_in_main);
	lv_obj_set_pos(ui->prepare_material_btn_material_in, 14, 130);
	lv_obj_set_size(ui->prepare_material_btn_material_in, 218, 158);
//	ui->prepare_material_btn_material_in_label = lv_label_create(ui->prepare_material_btn_material_in, NULL);
//	lv_label_set_text(ui->prepare_material_btn_material_in_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_material_btn_material_in_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_material_label_hotend_cur_temp
	ui->prepare_material_label_hotend_cur_temp = lv_label_create(ui->prepare_material_cont_prepare_material, NULL);
	lv_label_set_text(ui->prepare_material_label_hotend_cur_temp, "36");
	lv_label_set_long_mode(ui->prepare_material_label_hotend_cur_temp, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_material_label_hotend_cur_temp, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_material_label_hotend_cur_temp
	static lv_style_t style_prepare_material_label_hotend_cur_temp_main;
	lv_style_reset(&style_prepare_material_label_hotend_cur_temp_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_label_hotend_cur_temp_main
	lv_style_set_radius(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_material_label_hotend_cur_temp_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_material_label_hotend_cur_temp, LV_LABEL_PART_MAIN, &style_prepare_material_label_hotend_cur_temp_main);
	lv_obj_set_pos(ui->prepare_material_label_hotend_cur_temp, 40, 420);
	lv_obj_set_size(ui->prepare_material_label_hotend_cur_temp, 100, 0);

	//Write codes prepare_material_label_20
	ui->prepare_material_label_20 = lv_label_create(ui->prepare_material_cont_prepare_material, NULL);
	lv_label_set_text(ui->prepare_material_label_20, hotend_temp[cur_language]);
	lv_label_set_long_mode(ui->prepare_material_label_20, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_material_label_20, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_material_label_20
	static lv_style_t style_prepare_material_label_20_main;
	lv_style_reset(&style_prepare_material_label_20_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_label_20_main
	lv_style_set_radius(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_material_label_20_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_material_label_20, LV_LABEL_PART_MAIN, &style_prepare_material_label_20_main);
	lv_obj_set_pos(ui->prepare_material_label_20, 40, 379);
	lv_obj_set_size(ui->prepare_material_label_20, 150, 0);

	//Write codes prepare_material_img_3
	ui->prepare_material_img_3 = lv_img_create(ui->prepare_material_cont_prepare_material, NULL);

	//Write style LV_IMG_PART_MAIN for prepare_material_img_3
//	static lv_style_t style_prepare_material_img_3_main;
//	lv_style_reset(&style_prepare_material_img_3_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_prepare_material_img_3_main
//	lv_style_set_image_recolor(&style_prepare_material_img_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_prepare_material_img_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_prepare_material_img_3_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->prepare_material_img_3, LV_IMG_PART_MAIN, &style_prepare_material_img_3_main);
	lv_obj_set_pos(ui->prepare_material_img_3, 40, 329);
//	lv_obj_set_size(ui->prepare_material_img_3, 44, 44);
//	lv_obj_set_click(ui->prepare_material_img_3, true);
	lv_img_set_src(ui->prepare_material_img_3,&_hotend_alpha_44x44);
//	lv_img_set_pivot(ui->prepare_material_img_3, 0,0);
//	lv_img_set_angle(ui->prepare_material_img_3, 0);

	//Write codes prepare_material_label_18
	ui->prepare_material_label_18 = lv_label_create(ui->prepare_material_cont_prepare_material, NULL);
	lv_label_set_text(ui->prepare_material_label_18, meterial_out[cur_language]);
	lv_label_set_long_mode(ui->prepare_material_label_18, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_material_label_18, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_material_label_18
	static lv_style_t style_prepare_material_label_18_main;
	lv_style_reset(&style_prepare_material_label_18_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_label_18_main
	lv_style_set_radius(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_material_label_18_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_material_label_18, LV_LABEL_PART_MAIN, &style_prepare_material_label_18_main);
	lv_obj_set_pos(ui->prepare_material_label_18, 272, 203);
	lv_obj_set_size(ui->prepare_material_label_18, 150, 0);

	//Write codes prepare_material_img_2
	ui->prepare_material_img_2 = lv_img_create(ui->prepare_material_cont_prepare_material, NULL);

	//Write style LV_IMG_PART_MAIN for prepare_material_img_2
//	static lv_style_t style_prepare_material_img_2_main;
//	lv_style_reset(&style_prepare_material_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_prepare_material_img_2_main
//	lv_style_set_image_recolor(&style_prepare_material_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_prepare_material_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_prepare_material_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->prepare_material_img_2, LV_IMG_PART_MAIN, &style_prepare_material_img_2_main);
	lv_obj_set_pos(ui->prepare_material_img_2, 277, 155);
//	lv_obj_set_size(ui->prepare_material_img_2, 33, 39);
//	lv_obj_set_click(ui->prepare_material_img_2, true);
	lv_img_set_src(ui->prepare_material_img_2,&_hotendup_alpha_33x39);
//	lv_img_set_pivot(ui->prepare_material_img_2, 0,0);
//	lv_img_set_angle(ui->prepare_material_img_2, 0);

	//Write codes prepare_material_label_16
	ui->prepare_material_label_16 = lv_label_create(ui->prepare_material_cont_prepare_material, NULL);
	lv_label_set_text(ui->prepare_material_label_16, meterial_in[cur_language]);
	lv_label_set_long_mode(ui->prepare_material_label_16, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_material_label_16, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for prepare_material_label_16
	static lv_style_t style_prepare_material_label_16_main;
	lv_style_reset(&style_prepare_material_label_16_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_material_label_16_main
	lv_style_set_radius(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_material_label_16_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_material_label_16, LV_LABEL_PART_MAIN, &style_prepare_material_label_16_main);
	lv_obj_set_pos(ui->prepare_material_label_16, 40, 203);
	lv_obj_set_size(ui->prepare_material_label_16, 150, 0);

	//Write codes prepare_material_img_1
	ui->prepare_material_img_1 = lv_img_create(ui->prepare_material_cont_prepare_material, NULL);

	//Write style LV_IMG_PART_MAIN for prepare_material_img_1
//	static lv_style_t style_prepare_material_img_1_main;
//	lv_style_reset(&style_prepare_material_img_1_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_prepare_material_img_1_main
//	lv_style_set_image_recolor(&style_prepare_material_img_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_prepare_material_img_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_prepare_material_img_1_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->prepare_material_img_1, LV_IMG_PART_MAIN, &style_prepare_material_img_1_main);
	lv_obj_set_pos(ui->prepare_material_img_1, 45, 155);
//	lv_obj_set_size(ui->prepare_material_img_1, 34, 41);
//	lv_obj_set_click(ui->prepare_material_img_1, true);
	lv_img_set_src(ui->prepare_material_img_1,&_hotenddown_alpha_34x41);
//	lv_img_set_pivot(ui->prepare_material_img_1, 0,0);
//	lv_img_set_angle(ui->prepare_material_img_1, 0);
//	lv_cont_set_layout(ui->prepare_material_cont_prepare_material, LV_LAYOUT_OFF);
//	lv_cont_set_fit(ui->prepare_material_cont_prepare_material, LV_FIT_NONE);

	//Init events for screen
	events_init_prepare_material(ui);
}
