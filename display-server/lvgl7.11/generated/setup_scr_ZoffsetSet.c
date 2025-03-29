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

void setup_scr_ZoffsetSet(lv_ui *ui){

	//Write codes ZoffsetSet
//	ui->ZoffsetSet = lv_obj_create(NULL, NULL);

	//Write codes ZoffsetSet_cont_zoffset_set
	ui->ZoffsetSet_cont_zoffset_set = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for ZoffsetSet_cont_zoffset_set
	static lv_style_t style_ZoffsetSet_cont_zoffset_set_main;
	lv_style_reset(&style_ZoffsetSet_cont_zoffset_set_main);

	//Write style state: LV_STATE_DEFAULT for style_ZoffsetSet_cont_zoffset_set_main
	lv_style_set_radius(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_ZoffsetSet_cont_zoffset_set_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->ZoffsetSet_cont_zoffset_set, LV_CONT_PART_MAIN, &style_ZoffsetSet_cont_zoffset_set_main);
	lv_obj_set_pos(ui->ZoffsetSet_cont_zoffset_set, 0, 0);
	lv_obj_set_size(ui->ZoffsetSet_cont_zoffset_set, 480, 800);
	lv_obj_set_click(ui->ZoffsetSet_cont_zoffset_set, false);

	//Write codes ZoffsetSet_btn_zoffset_up
	ui->ZoffsetSet_btn_zoffset_up = lv_btn_create(ui->ZoffsetSet_cont_zoffset_set, NULL);

	//Write style LV_BTN_PART_MAIN for ZoffsetSet_btn_zoffset_up
	static lv_style_t style_ZoffsetSet_btn_zoffset_up_main;
	lv_style_reset(&style_ZoffsetSet_btn_zoffset_up_main);

	//Write style state: LV_STATE_DEFAULT for style_ZoffsetSet_btn_zoffset_up_main
	lv_style_set_radius(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x10, 0x16));
	lv_style_set_border_width(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_ZoffsetSet_btn_zoffset_up_main
	lv_style_set_radius(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_color(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_dir(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_PRESSED, 2);
	lv_style_set_border_opa(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_ZoffsetSet_btn_zoffset_up_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->ZoffsetSet_btn_zoffset_up, LV_BTN_PART_MAIN, &style_ZoffsetSet_btn_zoffset_up_main);
	lv_obj_set_pos(ui->ZoffsetSet_btn_zoffset_up, 130, 156);
	lv_obj_set_size(ui->ZoffsetSet_btn_zoffset_up, 220, 104);
//	ui->ZoffsetSet_btn_zoffset_up_label = lv_label_create(ui->ZoffsetSet_btn_zoffset_up, NULL);
//	lv_label_set_text(ui->ZoffsetSet_btn_zoffset_up_label, "");
//	lv_obj_set_style_local_text_color(ui->ZoffsetSet_btn_zoffset_up_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes ZoffsetSet_img_zoffset_up
	ui->ZoffsetSet_img_zoffset_up = lv_img_create(ui->ZoffsetSet_cont_zoffset_set, NULL);

	//Write style LV_IMG_PART_MAIN for ZoffsetSet_img_zoffset_up
//	static lv_style_t style_ZoffsetSet_img_zoffset_up_main;
//	lv_style_reset(&style_ZoffsetSet_img_zoffset_up_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_ZoffsetSet_img_zoffset_up_main
//	lv_style_set_image_recolor(&style_ZoffsetSet_img_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_ZoffsetSet_img_zoffset_up_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_ZoffsetSet_img_zoffset_up_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->ZoffsetSet_img_zoffset_up, LV_IMG_PART_MAIN, &style_ZoffsetSet_img_zoffset_up_main);
	lv_obj_set_pos(ui->ZoffsetSet_img_zoffset_up, 209, 180);
//	lv_obj_set_size(ui->ZoffsetSet_img_zoffset_up, 61, 55);
//	lv_obj_set_click(ui->ZoffsetSet_img_zoffset_up, true);
	lv_img_set_src(ui->ZoffsetSet_img_zoffset_up,&_Zoffsetup_alpha_61x55);
//	lv_img_set_pivot(ui->ZoffsetSet_img_zoffset_up, 0,0);
//	lv_img_set_angle(ui->ZoffsetSet_img_zoffset_up, 0);

	//Write codes ZoffsetSet_label_1
	ui->ZoffsetSet_label_1 = lv_label_create(ui->ZoffsetSet_cont_zoffset_set, NULL);
    lv_label_set_long_mode(ui->ZoffsetSet_label_1, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->ZoffsetSet_label_1, z_offset[cur_language]);
//	lv_label_set_long_mode(ui->ZoffsetSet_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->ZoffsetSet_label_1, LV_LABEL_ALIGN_RIGHT);

	//Write style LV_LABEL_PART_MAIN for ZoffsetSet_label_1
	static lv_style_t style_ZoffsetSet_label_1_main;
	lv_style_reset(&style_ZoffsetSet_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_ZoffsetSet_label_1_main
	lv_style_set_radius(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_ZoffsetSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->ZoffsetSet_label_1, LV_LABEL_PART_MAIN, &style_ZoffsetSet_label_1_main);
	lv_obj_set_pos(ui->ZoffsetSet_label_1, 113, 32);
	lv_obj_set_size(ui->ZoffsetSet_label_1, 347, 42);

	//Write codes ZoffsetSet_btn_zoffset_value
	ui->ZoffsetSet_btn_zoffset_value = lv_btn_create(ui->ZoffsetSet_cont_zoffset_set, NULL);

	//Write style LV_BTN_PART_MAIN for ZoffsetSet_btn_zoffset_value
	static lv_style_t style_ZoffsetSet_btn_zoffset_value_main;
	lv_style_reset(&style_ZoffsetSet_btn_zoffset_value_main);

	//Write style state: LV_STATE_DEFAULT for style_ZoffsetSet_btn_zoffset_value_main
	lv_style_set_radius(&style_ZoffsetSet_btn_zoffset_value_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_ZoffsetSet_btn_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_ZoffsetSet_btn_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_ZoffsetSet_btn_zoffset_value_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_ZoffsetSet_btn_zoffset_value_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_ZoffsetSet_btn_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_ZoffsetSet_btn_zoffset_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_ZoffsetSet_btn_zoffset_value_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_ZoffsetSet_btn_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_ZoffsetSet_btn_zoffset_value_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->ZoffsetSet_btn_zoffset_value, LV_BTN_PART_MAIN, &style_ZoffsetSet_btn_zoffset_value_main);
	lv_obj_set_pos(ui->ZoffsetSet_btn_zoffset_value, 165, 316);
	lv_obj_set_size(ui->ZoffsetSet_btn_zoffset_value, 150, 68);
//	ui->ZoffsetSet_btn_zoffset_value_label = lv_label_create(ui->ZoffsetSet_btn_zoffset_value, NULL);
//	lv_label_set_text(ui->ZoffsetSet_btn_zoffset_value_label, "");
//	lv_obj_set_style_local_text_color(ui->ZoffsetSet_btn_zoffset_value_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes ZoffsetSet_label_zoffset_value
	ui->ZoffsetSet_label_zoffset_value = lv_label_create(ui->ZoffsetSet_cont_zoffset_set, NULL);
	lv_label_set_text(ui->ZoffsetSet_label_zoffset_value, "0.00");
	lv_label_set_long_mode(ui->ZoffsetSet_label_zoffset_value, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->ZoffsetSet_label_zoffset_value, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for ZoffsetSet_label_zoffset_value
	static lv_style_t style_ZoffsetSet_label_zoffset_value_main;
	lv_style_reset(&style_ZoffsetSet_label_zoffset_value_main);

	//Write style state: LV_STATE_DEFAULT for style_ZoffsetSet_label_zoffset_value_main
	lv_style_set_radius(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_ZoffsetSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->ZoffsetSet_label_zoffset_value, LV_LABEL_PART_MAIN, &style_ZoffsetSet_label_zoffset_value_main);
	lv_obj_set_pos(ui->ZoffsetSet_label_zoffset_value, 160, 336);
	lv_obj_set_size(ui->ZoffsetSet_label_zoffset_value, 160, 0);

	//Write codes ZoffsetSet_btn_zoffset_down
	ui->ZoffsetSet_btn_zoffset_down = lv_btn_create(ui->ZoffsetSet_cont_zoffset_set, NULL);

	//Write style LV_BTN_PART_MAIN for ZoffsetSet_btn_zoffset_down
	static lv_style_t style_ZoffsetSet_btn_zoffset_down_main;
	lv_style_reset(&style_ZoffsetSet_btn_zoffset_down_main);

	//Write style state: LV_STATE_DEFAULT for style_ZoffsetSet_btn_zoffset_down_main
	lv_style_set_radius(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_ZoffsetSet_btn_zoffset_down_main
	lv_style_set_radius(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_PRESSED, 16);
	lv_style_set_bg_color(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_color(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x26, 0x2c));
	//lv_style_set_bg_grad_dir(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_PRESSED, 2);
	lv_style_set_border_opa(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_ZoffsetSet_btn_zoffset_down_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->ZoffsetSet_btn_zoffset_down, LV_BTN_PART_MAIN, &style_ZoffsetSet_btn_zoffset_down_main);
	lv_obj_set_pos(ui->ZoffsetSet_btn_zoffset_down, 130, 440);
	lv_obj_set_size(ui->ZoffsetSet_btn_zoffset_down, 220, 104);
//	ui->ZoffsetSet_btn_zoffset_down_label = lv_label_create(ui->ZoffsetSet_btn_zoffset_down, NULL);
//	lv_label_set_text(ui->ZoffsetSet_btn_zoffset_down_label, "");
//	lv_obj_set_style_local_text_color(ui->ZoffsetSet_btn_zoffset_down_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes ZoffsetSet_img_zoffset_down
	ui->ZoffsetSet_img_zoffset_down = lv_img_create(ui->ZoffsetSet_cont_zoffset_set, NULL);

	//Write style LV_IMG_PART_MAIN for ZoffsetSet_img_zoffset_down
//	static lv_style_t style_ZoffsetSet_img_zoffset_down_main;
//	lv_style_reset(&style_ZoffsetSet_img_zoffset_down_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_ZoffsetSet_img_zoffset_down_main
//	lv_style_set_image_recolor(&style_ZoffsetSet_img_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_ZoffsetSet_img_zoffset_down_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_ZoffsetSet_img_zoffset_down_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->ZoffsetSet_img_zoffset_down, LV_IMG_PART_MAIN, &style_ZoffsetSet_img_zoffset_down_main);
	lv_obj_set_pos(ui->ZoffsetSet_img_zoffset_down, 209, 464);
//	lv_obj_set_size(ui->ZoffsetSet_img_zoffset_down, 61, 55);
//	lv_obj_set_click(ui->ZoffsetSet_img_zoffset_down, true);
	lv_img_set_src(ui->ZoffsetSet_img_zoffset_down,&_Zoffsetdown_alpha_61x55);
//	lv_img_set_pivot(ui->ZoffsetSet_img_zoffset_down, 0,0);
//	lv_img_set_angle(ui->ZoffsetSet_img_zoffset_down, 0);

	//Write codes ZoffsetSet_img_back
	ui->ZoffsetSet_img_back = lv_img_create(ui->ZoffsetSet_cont_zoffset_set, NULL);

	//Write style LV_IMG_PART_MAIN for ZoffsetSet_img_back
//	static lv_style_t style_ZoffsetSet_img_back_main;
//	lv_style_reset(&style_ZoffsetSet_img_back_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_ZoffsetSet_img_back_main
//	lv_style_set_image_recolor(&style_ZoffsetSet_img_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_ZoffsetSet_img_back_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_ZoffsetSet_img_back_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->ZoffsetSet_img_back, LV_IMG_PART_MAIN, &style_ZoffsetSet_img_back_main);
	lv_obj_set_pos(ui->ZoffsetSet_img_back, 24, 30);
//	lv_obj_set_size(ui->ZoffsetSet_img_back, 45, 36);
	lv_obj_set_click(ui->ZoffsetSet_img_back, true);
	lv_img_set_src(ui->ZoffsetSet_img_back,&_return_alpha_45x36);
//	lv_img_set_pivot(ui->ZoffsetSet_img_back, 0,0);
//	lv_img_set_angle(ui->ZoffsetSet_img_back, 0);
//	lv_cont_set_layout(ui->ZoffsetSet_cont_zoffset_set, LV_LAYOUT_OFF);
//	lv_cont_set_fit(ui->ZoffsetSet_cont_zoffset_set, LV_FIT_NONE);

	//Init events for screen
	events_init_ZoffsetSet(ui);
}
