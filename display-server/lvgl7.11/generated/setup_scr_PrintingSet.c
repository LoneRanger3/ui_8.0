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

void setup_scr_PrintingSet(lv_ui *ui){

	//Write codes PrintingSet
//	ui->PrintingSet = lv_obj_create(NULL, NULL);

	//Write codes PrintingSet_cont_printing_set
	ui->PrintingSet_cont_printing_set = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for PrintingSet_cont_printing_set
	static lv_style_t style_PrintingSet_cont_printing_set_main;
	lv_style_reset(&style_PrintingSet_cont_printing_set_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_cont_printing_set_main
	lv_style_set_radius(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_cont_printing_set_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_cont_printing_set, LV_CONT_PART_MAIN, &style_PrintingSet_cont_printing_set_main);
	lv_obj_set_pos(ui->PrintingSet_cont_printing_set, 0, 0);
	lv_obj_set_size(ui->PrintingSet_cont_printing_set, 480, 800);
	lv_obj_set_click(ui->PrintingSet_cont_printing_set, false);

	//Write codes PrintingSet_btn_hotend
	ui->PrintingSet_btn_hotend = lv_btn_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_BTN_PART_MAIN for PrintingSet_btn_hotend
	static lv_style_t style_PrintingSet_btn_hotend_main;
	lv_style_reset(&style_PrintingSet_btn_hotend_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_btn_hotend_main
	lv_style_set_radius(&style_PrintingSet_btn_hotend_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_PrintingSet_btn_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_PrintingSet_btn_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_btn_hotend_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_btn_hotend_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_PrintingSet_btn_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_PrintingSet_btn_hotend_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_PrintingSet_btn_hotend_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_PrintingSet_btn_hotend_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_PrintingSet_btn_hotend_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->PrintingSet_btn_hotend, LV_BTN_PART_MAIN, &style_PrintingSet_btn_hotend_main);
	lv_obj_set_pos(ui->PrintingSet_btn_hotend, 10, 106);
	lv_obj_set_size(ui->PrintingSet_btn_hotend, 224, 158);
//	ui->PrintingSet_btn_hotend_label = lv_label_create(ui->PrintingSet_btn_hotend, NULL);
//	lv_label_set_text(ui->PrintingSet_btn_hotend_label, "");
//	lv_obj_set_style_local_text_color(ui->PrintingSet_btn_hotend_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes PrintingSet_label_hotend_mtemp_value
	ui->PrintingSet_label_hotend_mtemp_value = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_text(ui->PrintingSet_label_hotend_mtemp_value, "0");
	lv_label_set_long_mode(ui->PrintingSet_label_hotend_mtemp_value, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_hotend_mtemp_value, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_hotend_mtemp_value
	static lv_style_t style_PrintingSet_label_hotend_mtemp_value_main;
	lv_style_reset(&style_PrintingSet_label_hotend_mtemp_value_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_hotend_mtemp_value_main
	lv_style_set_radius(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_hotend_mtemp_value_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_hotend_mtemp_value, LV_LABEL_PART_MAIN, &style_PrintingSet_label_hotend_mtemp_value_main);
	lv_obj_set_pos(ui->PrintingSet_label_hotend_mtemp_value, 34, 230);
	lv_obj_set_size(ui->PrintingSet_label_hotend_mtemp_value, 200, 0);

	//Write codes PrintingSet_img_2
	ui->PrintingSet_img_2 = lv_img_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_IMG_PART_MAIN for PrintingSet_img_2
//	static lv_style_t style_PrintingSet_img_2_main;
//	lv_style_reset(&style_PrintingSet_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_img_2_main
//	lv_style_set_image_recolor(&style_PrintingSet_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_PrintingSet_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_PrintingSet_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->PrintingSet_img_2, LV_IMG_PART_MAIN, &style_PrintingSet_img_2_main);
	lv_obj_set_pos(ui->PrintingSet_img_2, 26, 119);
//	lv_obj_set_size(ui->PrintingSet_img_2, 44, 44);
//	lv_obj_set_click(ui->PrintingSet_img_2, true);
	lv_img_set_src(ui->PrintingSet_img_2,&_hotend_alpha_44x44);
//	lv_img_set_pivot(ui->PrintingSet_img_2, 0,0);
//	lv_img_set_angle(ui->PrintingSet_img_2, 0);

	//Write codes PrintingSet_img_back
	ui->PrintingSet_img_back = lv_img_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_IMG_PART_MAIN for PrintingSet_img_back
//	static lv_style_t style_PrintingSet_img_back_main;
//	lv_style_reset(&style_PrintingSet_img_back_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_img_back_main
//	lv_style_set_image_recolor(&style_PrintingSet_img_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_PrintingSet_img_back_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_PrintingSet_img_back_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->PrintingSet_img_back, LV_IMG_PART_MAIN, &style_PrintingSet_img_back_main);
	lv_obj_set_pos(ui->PrintingSet_img_back, 24, 30);
//	lv_obj_set_size(ui->PrintingSet_img_back, 45, 36);
	lv_obj_set_click(ui->PrintingSet_img_back, true);
	lv_img_set_src(ui->PrintingSet_img_back,&_return_alpha_45x36);
//	lv_img_set_pivot(ui->PrintingSet_img_back, 0,0);
//	lv_img_set_angle(ui->PrintingSet_img_back, 0);

	//Write codes PrintingSet_label_title
	ui->PrintingSet_label_title = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_text(ui->PrintingSet_label_title, printing_set[cur_language]);
	lv_label_set_long_mode(ui->PrintingSet_label_title, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_title, LV_LABEL_ALIGN_RIGHT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_title
	static lv_style_t style_PrintingSet_label_title_main;
	lv_style_reset(&style_PrintingSet_label_title_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_title_main
	lv_style_set_radius(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_title_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_title, LV_LABEL_PART_MAIN, &style_PrintingSet_label_title_main);
	lv_obj_set_pos(ui->PrintingSet_label_title, 113, 32);
	lv_obj_set_size(ui->PrintingSet_label_title, 347, 42);

	//Write codes PrintingSet_label_hotend_mtemp
	ui->PrintingSet_label_hotend_mtemp = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_long_mode(ui->PrintingSet_label_hotend_mtemp, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->PrintingSet_label_hotend_mtemp, hotend_temp[cur_language]);
//	lv_label_set_long_mode(ui->PrintingSet_label_hotend_mtemp, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_hotend_mtemp, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_hotend_mtemp
	static lv_style_t style_PrintingSet_label_hotend_mtemp_main;
	lv_style_reset(&style_PrintingSet_label_hotend_mtemp_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_hotend_mtemp_main
	lv_style_set_radius(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_hotend_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_hotend_mtemp, LV_LABEL_PART_MAIN, &style_PrintingSet_label_hotend_mtemp_main);
	lv_obj_set_pos(ui->PrintingSet_label_hotend_mtemp, 34, 184);
	lv_obj_set_size(ui->PrintingSet_label_hotend_mtemp, 180, 42);

	//Write codes PrintingSet_btn_bed
	ui->PrintingSet_btn_bed = lv_btn_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_BTN_PART_MAIN for PrintingSet_btn_bed
	static lv_style_t style_PrintingSet_btn_bed_main;
	lv_style_reset(&style_PrintingSet_btn_bed_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_btn_bed_main
	lv_style_set_radius(&style_PrintingSet_btn_bed_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_PrintingSet_btn_bed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_PrintingSet_btn_bed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_btn_bed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_btn_bed_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_PrintingSet_btn_bed_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_PrintingSet_btn_bed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_PrintingSet_btn_bed_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_PrintingSet_btn_bed_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_PrintingSet_btn_bed_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->PrintingSet_btn_bed, LV_BTN_PART_MAIN, &style_PrintingSet_btn_bed_main);
	lv_obj_set_pos(ui->PrintingSet_btn_bed, 246, 106);
	lv_obj_set_size(ui->PrintingSet_btn_bed, 225, 158);
//	ui->PrintingSet_btn_bed_label = lv_label_create(ui->PrintingSet_btn_bed, NULL);
//	lv_label_set_text(ui->PrintingSet_btn_bed_label, "");
//	lv_obj_set_style_local_text_color(ui->PrintingSet_btn_bed_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes PrintingSet_btn_speed
	ui->PrintingSet_btn_speed = lv_btn_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_BTN_PART_MAIN for PrintingSet_btn_speed
	static lv_style_t style_PrintingSet_btn_speed_main;
	lv_style_reset(&style_PrintingSet_btn_speed_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_btn_speed_main
	lv_style_set_radius(&style_PrintingSet_btn_speed_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_PrintingSet_btn_speed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_PrintingSet_btn_speed_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_btn_speed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_btn_speed_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_PrintingSet_btn_speed_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_PrintingSet_btn_speed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_PrintingSet_btn_speed_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_PrintingSet_btn_speed_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_PrintingSet_btn_speed_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->PrintingSet_btn_speed, LV_BTN_PART_MAIN, &style_PrintingSet_btn_speed_main);
	lv_obj_set_pos(ui->PrintingSet_btn_speed, 10, 280);
	lv_obj_set_size(ui->PrintingSet_btn_speed, 224, 158);
//	ui->PrintingSet_btn_speed_label = lv_label_create(ui->PrintingSet_btn_speed, NULL);
//	lv_label_set_text(ui->PrintingSet_btn_speed_label, "");
//	lv_obj_set_style_local_text_color(ui->PrintingSet_btn_speed_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes PrintingSet_btn_fan
	ui->PrintingSet_btn_fan = lv_btn_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_BTN_PART_MAIN for PrintingSet_btn_fan
	static lv_style_t style_PrintingSet_btn_fan_main;
	lv_style_reset(&style_PrintingSet_btn_fan_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_btn_fan_main
	lv_style_set_radius(&style_PrintingSet_btn_fan_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_PrintingSet_btn_fan_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_PrintingSet_btn_fan_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_btn_fan_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_btn_fan_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_PrintingSet_btn_fan_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_PrintingSet_btn_fan_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_PrintingSet_btn_fan_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_PrintingSet_btn_fan_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_PrintingSet_btn_fan_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->PrintingSet_btn_fan, LV_BTN_PART_MAIN, &style_PrintingSet_btn_fan_main);
	lv_obj_set_pos(ui->PrintingSet_btn_fan, 246, 280);
	lv_obj_set_size(ui->PrintingSet_btn_fan, 225, 158);
//	ui->PrintingSet_btn_fan_label = lv_label_create(ui->PrintingSet_btn_fan, NULL);
//	lv_label_set_text(ui->PrintingSet_btn_fan_label, "");
//	lv_obj_set_style_local_text_color(ui->PrintingSet_btn_fan_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes PrintingSet_img_3
	ui->PrintingSet_img_3 = lv_img_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_IMG_PART_MAIN for PrintingSet_img_3
//	static lv_style_t style_PrintingSet_img_3_main;
//	lv_style_reset(&style_PrintingSet_img_3_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_img_3_main
//	lv_style_set_image_recolor(&style_PrintingSet_img_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_PrintingSet_img_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_PrintingSet_img_3_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->PrintingSet_img_3, LV_IMG_PART_MAIN, &style_PrintingSet_img_3_main);
	lv_obj_set_pos(ui->PrintingSet_img_3, 262, 119);
//	lv_obj_set_size(ui->PrintingSet_img_3, 44, 44);
//	lv_obj_set_click(ui->PrintingSet_img_3, true);
	lv_img_set_src(ui->PrintingSet_img_3,&_hotbed_alpha_44x44);
//	lv_img_set_pivot(ui->PrintingSet_img_3, 0,0);
//	lv_img_set_angle(ui->PrintingSet_img_3, 0);

	//Write codes PrintingSet_img_4
	ui->PrintingSet_img_4 = lv_img_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_IMG_PART_MAIN for PrintingSet_img_4
//	static lv_style_t style_PrintingSet_img_4_main;
//	lv_style_reset(&style_PrintingSet_img_4_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_img_4_main
//	lv_style_set_image_recolor(&style_PrintingSet_img_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_PrintingSet_img_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_PrintingSet_img_4_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->PrintingSet_img_4, LV_IMG_PART_MAIN, &style_PrintingSet_img_4_main);
	lv_obj_set_pos(ui->PrintingSet_img_4, 29, 303);
//	lv_obj_set_size(ui->PrintingSet_img_4, 38, 24);
//	lv_obj_set_click(ui->PrintingSet_img_4, true);
	lv_img_set_src(ui->PrintingSet_img_4,&_speed_alpha_38x24);
//	lv_img_set_pivot(ui->PrintingSet_img_4, 0,0);
//	lv_img_set_angle(ui->PrintingSet_img_4, 0);

	//Write codes PrintingSet_img_5
	ui->PrintingSet_img_5 = lv_img_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_IMG_PART_MAIN for PrintingSet_img_5
//	static lv_style_t style_PrintingSet_img_5_main;
//	lv_style_reset(&style_PrintingSet_img_5_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_img_5_main
//	lv_style_set_image_recolor(&style_PrintingSet_img_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_PrintingSet_img_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_PrintingSet_img_5_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->PrintingSet_img_5, LV_IMG_PART_MAIN, &style_PrintingSet_img_5_main);
	lv_obj_set_pos(ui->PrintingSet_img_5, 262, 293);
//	lv_obj_set_size(ui->PrintingSet_img_5, 44, 44);
//	lv_obj_set_click(ui->PrintingSet_img_5, true);
	lv_img_set_src(ui->PrintingSet_img_5,&_fan_alpha_44x44);
//	lv_img_set_pivot(ui->PrintingSet_img_5, 0,0);
//	lv_img_set_angle(ui->PrintingSet_img_5, 0);

	//Write codes PrintingSet_label_fan_state_value
	ui->PrintingSet_label_fan_state_value = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_text(ui->PrintingSet_label_fan_state_value, "");
	lv_label_set_long_mode(ui->PrintingSet_label_fan_state_value, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_fan_state_value, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_fan_state_value
	static lv_style_t style_PrintingSet_label_fan_state_value_main;
	lv_style_reset(&style_PrintingSet_label_fan_state_value_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_fan_state_value_main
	lv_style_set_radius(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_fan_state_value_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_fan_state_value, LV_LABEL_PART_MAIN, &style_PrintingSet_label_fan_state_value_main);
	lv_obj_set_pos(ui->PrintingSet_label_fan_state_value, 270, 404);
	lv_obj_set_size(ui->PrintingSet_label_fan_state_value, 200, 0);

	//Write codes PrintingSet_label_cur_speed_value
	ui->PrintingSet_label_cur_speed_value = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_text(ui->PrintingSet_label_cur_speed_value, "100%");
	lv_label_set_long_mode(ui->PrintingSet_label_cur_speed_value, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_cur_speed_value, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_cur_speed_value
	static lv_style_t style_PrintingSet_label_cur_speed_value_main;
	lv_style_reset(&style_PrintingSet_label_cur_speed_value_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_cur_speed_value_main
	lv_style_set_radius(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_cur_speed_value_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_cur_speed_value, LV_LABEL_PART_MAIN, &style_PrintingSet_label_cur_speed_value_main);
	lv_obj_set_pos(ui->PrintingSet_label_cur_speed_value, 34, 404);
	lv_obj_set_size(ui->PrintingSet_label_cur_speed_value, 200, 0);

	//Write codes PrintingSet_label_bed_mtemp_value
	ui->PrintingSet_label_bed_mtemp_value = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_text(ui->PrintingSet_label_bed_mtemp_value, "0");
	lv_label_set_long_mode(ui->PrintingSet_label_bed_mtemp_value, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_bed_mtemp_value, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_bed_mtemp_value
	static lv_style_t style_PrintingSet_label_bed_mtemp_value_main;
	lv_style_reset(&style_PrintingSet_label_bed_mtemp_value_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_bed_mtemp_value_main
	lv_style_set_radius(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_bed_mtemp_value_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_bed_mtemp_value, LV_LABEL_PART_MAIN, &style_PrintingSet_label_bed_mtemp_value_main);
	lv_obj_set_pos(ui->PrintingSet_label_bed_mtemp_value, 270, 230);
	lv_obj_set_size(ui->PrintingSet_label_bed_mtemp_value, 200, 0);

	//Write codes PrintingSet_label_bed_mtemp
	ui->PrintingSet_label_bed_mtemp = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_long_mode(ui->PrintingSet_label_bed_mtemp, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->PrintingSet_label_bed_mtemp, bed_temp[cur_language]);
//	lv_label_set_long_mode(ui->PrintingSet_label_bed_mtemp, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_bed_mtemp, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_bed_mtemp
	static lv_style_t style_PrintingSet_label_bed_mtemp_main;
	lv_style_reset(&style_PrintingSet_label_bed_mtemp_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_bed_mtemp_main
	lv_style_set_radius(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_bed_mtemp_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_bed_mtemp, LV_LABEL_PART_MAIN, &style_PrintingSet_label_bed_mtemp_main);
	lv_obj_set_pos(ui->PrintingSet_label_bed_mtemp, 270, 184);
	lv_obj_set_size(ui->PrintingSet_label_bed_mtemp, 180, 42);

	//Write codes PrintingSet_label_cur_speed
	ui->PrintingSet_label_cur_speed = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_long_mode(ui->PrintingSet_label_cur_speed, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->PrintingSet_label_cur_speed, print_speed[cur_language]);
//	lv_label_set_long_mode(ui->PrintingSet_label_cur_speed, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_cur_speed, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_cur_speed
	static lv_style_t style_PrintingSet_label_cur_speed_main;
	lv_style_reset(&style_PrintingSet_label_cur_speed_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_cur_speed_main
	lv_style_set_radius(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_cur_speed_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_cur_speed, LV_LABEL_PART_MAIN, &style_PrintingSet_label_cur_speed_main);
	lv_obj_set_pos(ui->PrintingSet_label_cur_speed, 34, 358);
	lv_obj_set_size(ui->PrintingSet_label_cur_speed, 180, 42);

	//Write codes PrintingSet_label_fan_state
	ui->PrintingSet_label_fan_state = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_long_mode(ui->PrintingSet_label_fan_state, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->PrintingSet_label_fan_state, fan_control[cur_language]);
//	lv_label_set_long_mode(ui->PrintingSet_label_fan_state, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_fan_state, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_fan_state
	static lv_style_t style_PrintingSet_label_fan_state_main;
	lv_style_reset(&style_PrintingSet_label_fan_state_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_fan_state_main
	lv_style_set_radius(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_fan_state_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_fan_state, LV_LABEL_PART_MAIN, &style_PrintingSet_label_fan_state_main);
	lv_obj_set_pos(ui->PrintingSet_label_fan_state, 270, 358);
	lv_obj_set_size(ui->PrintingSet_label_fan_state, 180, 42);

	//Write codes PrintingSet_btn_light
	ui->PrintingSet_btn_light = lv_btn_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_BTN_PART_MAIN for PrintingSet_btn_light
	static lv_style_t style_PrintingSet_btn_light_main;
	lv_style_reset(&style_PrintingSet_btn_light_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_btn_light_main
	lv_style_set_radius(&style_PrintingSet_btn_light_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_PrintingSet_btn_light_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_PrintingSet_btn_light_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_btn_light_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_btn_light_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_PrintingSet_btn_light_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_PrintingSet_btn_light_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_PrintingSet_btn_light_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_PrintingSet_btn_light_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_PrintingSet_btn_light_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->PrintingSet_btn_light, LV_BTN_PART_MAIN, &style_PrintingSet_btn_light_main);
	lv_obj_set_pos(ui->PrintingSet_btn_light, 10, 454);
	lv_obj_set_size(ui->PrintingSet_btn_light, 224, 158);
//	ui->PrintingSet_btn_light_label = lv_label_create(ui->PrintingSet_btn_light, NULL);
//	lv_label_set_text(ui->PrintingSet_btn_light_label, "");
//	lv_obj_set_style_local_text_color(ui->PrintingSet_btn_light_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes PrintingSet_label_light_state_value
	ui->PrintingSet_label_light_state_value = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_text(ui->PrintingSet_label_light_state_value, "");
	lv_label_set_long_mode(ui->PrintingSet_label_light_state_value, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_light_state_value, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_light_state_value
	static lv_style_t style_PrintingSet_label_light_state_value_main;
	lv_style_reset(&style_PrintingSet_label_light_state_value_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_light_state_value_main
	lv_style_set_radius(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_light_state_value_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_light_state_value, LV_LABEL_PART_MAIN, &style_PrintingSet_label_light_state_value_main);
	lv_obj_set_pos(ui->PrintingSet_label_light_state_value, 34, 578);
	lv_obj_set_size(ui->PrintingSet_label_light_state_value, 200, 0);

	//Write codes PrintingSet_label_light_state
	ui->PrintingSet_label_light_state = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_long_mode(ui->PrintingSet_label_light_state, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->PrintingSet_label_light_state, light_control[cur_language]);
//	lv_label_set_long_mode(ui->PrintingSet_label_light_state, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_light_state, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_light_state
	static lv_style_t style_PrintingSet_label_light_state_main;
	lv_style_reset(&style_PrintingSet_label_light_state_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_light_state_main
	lv_style_set_radius(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_light_state_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_light_state, LV_LABEL_PART_MAIN, &style_PrintingSet_label_light_state_main);
	lv_obj_set_pos(ui->PrintingSet_label_light_state, 34, 532);
	lv_obj_set_size(ui->PrintingSet_label_light_state, 180, 42);

	//Write codes PrintingSet_img_6
	ui->PrintingSet_img_6 = lv_img_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_IMG_PART_MAIN for PrintingSet_img_6
//	static lv_style_t style_PrintingSet_img_6_main;
//	lv_style_reset(&style_PrintingSet_img_6_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_img_6_main
//	lv_style_set_image_recolor(&style_PrintingSet_img_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_PrintingSet_img_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_PrintingSet_img_6_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->PrintingSet_img_6, LV_IMG_PART_MAIN, &style_PrintingSet_img_6_main);
	lv_obj_set_pos(ui->PrintingSet_img_6, 26, 467);
//	lv_obj_set_size(ui->PrintingSet_img_6, 44, 44);
//	lv_obj_set_click(ui->PrintingSet_img_6, true);
	lv_img_set_src(ui->PrintingSet_img_6,&_lightctl_alpha_44x44);
//	lv_img_set_pivot(ui->PrintingSet_img_6, 0,0);
//	lv_img_set_angle(ui->PrintingSet_img_6, 0);

	//Write codes PrintingSet_btn_poweroff
	ui->PrintingSet_btn_poweroff = lv_btn_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_BTN_PART_MAIN for PrintingSet_btn_poweroff
	static lv_style_t style_PrintingSet_btn_poweroff_main;
	lv_style_reset(&style_PrintingSet_btn_poweroff_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_btn_poweroff_main
	lv_style_set_radius(&style_PrintingSet_btn_poweroff_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_PrintingSet_btn_poweroff_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_PrintingSet_btn_poweroff_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_btn_poweroff_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_btn_poweroff_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_PrintingSet_btn_poweroff_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_PrintingSet_btn_poweroff_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_PrintingSet_btn_poweroff_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_PrintingSet_btn_poweroff_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_PrintingSet_btn_poweroff_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->PrintingSet_btn_poweroff, LV_BTN_PART_MAIN, &style_PrintingSet_btn_poweroff_main);
	lv_obj_set_pos(ui->PrintingSet_btn_poweroff, 246, 454);
	lv_obj_set_size(ui->PrintingSet_btn_poweroff, 225, 158);
//	ui->PrintingSet_btn_poweroff_label = lv_label_create(ui->PrintingSet_btn_poweroff, NULL);
//	lv_label_set_text(ui->PrintingSet_btn_poweroff_label, "");
//	lv_obj_set_style_local_text_color(ui->PrintingSet_btn_poweroff_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes PrintingSet_btn_zoffset
	ui->PrintingSet_btn_zoffset = lv_btn_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_BTN_PART_MAIN for PrintingSet_btn_zoffset
	static lv_style_t style_PrintingSet_btn_zoffset_main;
	lv_style_reset(&style_PrintingSet_btn_zoffset_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_btn_zoffset_main
	lv_style_set_radius(&style_PrintingSet_btn_zoffset_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_PrintingSet_btn_zoffset_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_PrintingSet_btn_zoffset_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_btn_zoffset_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_btn_zoffset_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_PrintingSet_btn_zoffset_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_PrintingSet_btn_zoffset_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_PrintingSet_btn_zoffset_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_PrintingSet_btn_zoffset_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_PrintingSet_btn_zoffset_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->PrintingSet_btn_zoffset, LV_BTN_PART_MAIN, &style_PrintingSet_btn_zoffset_main);
	lv_obj_set_pos(ui->PrintingSet_btn_zoffset, 10, 628);
	lv_obj_set_size(ui->PrintingSet_btn_zoffset, 225, 158);
//	ui->PrintingSet_btn_zoffset_label = lv_label_create(ui->PrintingSet_btn_zoffset, NULL);
//	lv_label_set_text(ui->PrintingSet_btn_zoffset_label, "");
//	lv_obj_set_style_local_text_color(ui->PrintingSet_btn_zoffset_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes PrintingSet_label_zoffset_value
	ui->PrintingSet_label_zoffset_value = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_text(ui->PrintingSet_label_zoffset_value, "");
	lv_label_set_long_mode(ui->PrintingSet_label_zoffset_value, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_zoffset_value, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_zoffset_value
	static lv_style_t style_PrintingSet_label_zoffset_value_main;
	lv_style_reset(&style_PrintingSet_label_zoffset_value_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_zoffset_value_main
	lv_style_set_radius(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_zoffset_value_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_zoffset_value, LV_LABEL_PART_MAIN, &style_PrintingSet_label_zoffset_value_main);
	lv_obj_set_pos(ui->PrintingSet_label_zoffset_value, 34, 752);
	lv_obj_set_size(ui->PrintingSet_label_zoffset_value, 200, 0);

	//Write codes PrintingSet_label_auto_poweroff_value
	ui->PrintingSet_label_auto_poweroff_value = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_text(ui->PrintingSet_label_auto_poweroff_value, "");
	lv_label_set_long_mode(ui->PrintingSet_label_auto_poweroff_value, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_auto_poweroff_value, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_auto_poweroff_value
	static lv_style_t style_PrintingSet_label_auto_poweroff_value_main;
	lv_style_reset(&style_PrintingSet_label_auto_poweroff_value_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_auto_poweroff_value_main
	lv_style_set_radius(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_auto_poweroff_value_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_auto_poweroff_value, LV_LABEL_PART_MAIN, &style_PrintingSet_label_auto_poweroff_value_main);
	lv_obj_set_pos(ui->PrintingSet_label_auto_poweroff_value, 270, 578);
	lv_obj_set_size(ui->PrintingSet_label_auto_poweroff_value, 200, 0);

	//Write codes PrintingSet_label_auto_poweroff
	ui->PrintingSet_label_auto_poweroff = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_long_mode(ui->PrintingSet_label_auto_poweroff, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->PrintingSet_label_auto_poweroff, auto_power_off[cur_language]);
//	lv_label_set_long_mode(ui->PrintingSet_label_auto_poweroff, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_auto_poweroff, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_auto_poweroff
	static lv_style_t style_PrintingSet_label_auto_poweroff_main;
	lv_style_reset(&style_PrintingSet_label_auto_poweroff_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_auto_poweroff_main
	lv_style_set_radius(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_auto_poweroff_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_auto_poweroff, LV_LABEL_PART_MAIN, &style_PrintingSet_label_auto_poweroff_main);
	lv_obj_set_pos(ui->PrintingSet_label_auto_poweroff, 270, 532);
	lv_obj_set_size(ui->PrintingSet_label_auto_poweroff, 180, 42);

	//Write codes PrintingSet_img_7
	ui->PrintingSet_img_7 = lv_img_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_IMG_PART_MAIN for PrintingSet_img_7
//	static lv_style_t style_PrintingSet_img_7_main;
//	lv_style_reset(&style_PrintingSet_img_7_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_img_7_main
//	lv_style_set_image_recolor(&style_PrintingSet_img_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_PrintingSet_img_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_PrintingSet_img_7_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->PrintingSet_img_7, LV_IMG_PART_MAIN, &style_PrintingSet_img_7_main);
	lv_obj_set_pos(ui->PrintingSet_img_7, 262, 467);
//	lv_obj_set_size(ui->PrintingSet_img_7, 44, 44);
//	lv_obj_set_click(ui->PrintingSet_img_7, true);
	lv_img_set_src(ui->PrintingSet_img_7,&_poweroff_alpha_44x44);
//	lv_img_set_pivot(ui->PrintingSet_img_7, 0,0);
//	lv_img_set_angle(ui->PrintingSet_img_7, 0);

	//Write codes PrintingSet_label_zoffset
	ui->PrintingSet_label_zoffset = lv_label_create(ui->PrintingSet_cont_printing_set, NULL);
	lv_label_set_long_mode(ui->PrintingSet_label_zoffset, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->PrintingSet_label_zoffset, z_offset[cur_language]);
//	lv_label_set_long_mode(ui->PrintingSet_label_zoffset, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->PrintingSet_label_zoffset, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for PrintingSet_label_zoffset
	static lv_style_t style_PrintingSet_label_zoffset_main;
	lv_style_reset(&style_PrintingSet_label_zoffset_main);

	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_label_zoffset_main
	lv_style_set_radius(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
	{
        lv_style_set_text_font(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
	}
    else
    {
        lv_style_set_text_font(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_PrintingSet_label_zoffset_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->PrintingSet_label_zoffset, LV_LABEL_PART_MAIN, &style_PrintingSet_label_zoffset_main);
	lv_obj_set_pos(ui->PrintingSet_label_zoffset, 34, 706);
	lv_obj_set_size(ui->PrintingSet_label_zoffset, 180, 42);

	//Write codes PrintingSet_img_8
	ui->PrintingSet_img_8 = lv_img_create(ui->PrintingSet_cont_printing_set, NULL);

	//Write style LV_IMG_PART_MAIN for PrintingSet_img_8
//	static lv_style_t style_PrintingSet_img_8_main;
//	lv_style_reset(&style_PrintingSet_img_8_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_PrintingSet_img_8_main
//	lv_style_set_image_recolor(&style_PrintingSet_img_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_PrintingSet_img_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_PrintingSet_img_8_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->PrintingSet_img_8, LV_IMG_PART_MAIN, &style_PrintingSet_img_8_main);
	lv_obj_set_pos(ui->PrintingSet_img_8, 32, 648);
//	lv_obj_set_size(ui->PrintingSet_img_8, 33, 31);
//	lv_obj_set_click(ui->PrintingSet_img_8, true);
	lv_img_set_src(ui->PrintingSet_img_8,&_zoffset_alpha_33x31);
//	lv_img_set_pivot(ui->PrintingSet_img_8, 0,0);
//	lv_img_set_angle(ui->PrintingSet_img_8, 0);
//	lv_cont_set_layout(ui->PrintingSet_cont_printing_set, LV_LAYOUT_OFF);
//	lv_cont_set_fit(ui->PrintingSet_cont_printing_set, LV_FIT_NONE);

	//Init events for screen
	events_init_PrintingSet(ui);
}
