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

void setup_scr_TempPIDSet(lv_ui *ui){

	//Write codes TempPIDSet
//	ui->TempPIDSet = lv_obj_create(NULL, NULL);

	//Write codes TempPIDSet_cont_temppid_set
	ui->TempPIDSet_cont_temppid_set = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for TempPIDSet_cont_temppid_set
	static lv_style_t style_TempPIDSet_cont_temppid_set_main;
	lv_style_reset(&style_TempPIDSet_cont_temppid_set_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_cont_temppid_set_main
	lv_style_set_radius(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_cont_temppid_set_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_cont_temppid_set, LV_CONT_PART_MAIN, &style_TempPIDSet_cont_temppid_set_main);
	lv_obj_set_pos(ui->TempPIDSet_cont_temppid_set, 0, 0);
	lv_obj_set_size(ui->TempPIDSet_cont_temppid_set, 480, 800);
	lv_obj_set_click(ui->TempPIDSet_cont_temppid_set, false);

	//Write codes TempPIDSet_btn_hotend_pid_p
	ui->TempPIDSet_btn_hotend_pid_p = lv_btn_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_BTN_PART_MAIN for TempPIDSet_btn_hotend_pid_p
	static lv_style_t style_TempPIDSet_btn_hotend_pid_p_main;
	lv_style_reset(&style_TempPIDSet_btn_hotend_pid_p_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_btn_hotend_pid_p_main
	lv_style_set_radius(&style_TempPIDSet_btn_hotend_pid_p_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_TempPIDSet_btn_hotend_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_btn_hotend_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_btn_hotend_pid_p_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_btn_hotend_pid_p_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_TempPIDSet_btn_hotend_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_TempPIDSet_btn_hotend_pid_p_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_TempPIDSet_btn_hotend_pid_p_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_TempPIDSet_btn_hotend_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_TempPIDSet_btn_hotend_pid_p_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->TempPIDSet_btn_hotend_pid_p, LV_BTN_PART_MAIN, &style_TempPIDSet_btn_hotend_pid_p_main);
	lv_obj_set_pos(ui->TempPIDSet_btn_hotend_pid_p, 10, 106);
	lv_obj_set_size(ui->TempPIDSet_btn_hotend_pid_p, 224, 206);
//	ui->TempPIDSet_btn_hotend_pid_p_label = lv_label_create(ui->TempPIDSet_btn_hotend_pid_p, NULL);
//	lv_label_set_text(ui->TempPIDSet_btn_hotend_pid_p_label, "");
//	lv_obj_set_style_local_text_color(ui->TempPIDSet_btn_hotend_pid_p_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes TempPIDSet_label_2
	ui->TempPIDSet_label_2 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_2, noz_p_value[cur_language]);
	lv_label_set_long_mode(ui->TempPIDSet_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_2, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_2
	static lv_style_t style_TempPIDSet_label_2_main;
	lv_style_reset(&style_TempPIDSet_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_2_main
	lv_style_set_radius(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_2, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_2_main);
	lv_obj_set_pos(ui->TempPIDSet_label_2, 34, 260);
	lv_obj_set_size(ui->TempPIDSet_label_2, 200, 0);

	//Write codes TempPIDSet_img_2
	ui->TempPIDSet_img_2 = lv_img_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_IMG_PART_MAIN for TempPIDSet_img_2
//	static lv_style_t style_TempPIDSet_img_2_main;
//	lv_style_reset(&style_TempPIDSet_img_2_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_img_2_main
//	lv_style_set_image_recolor(&style_TempPIDSet_img_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_TempPIDSet_img_2_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_TempPIDSet_img_2_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->TempPIDSet_img_2, LV_IMG_PART_MAIN, &style_TempPIDSet_img_2_main);
	lv_obj_set_pos(ui->TempPIDSet_img_2, 26, 119);
//	lv_obj_set_size(ui->TempPIDSet_img_2, 35, 41);
//	lv_obj_set_click(ui->TempPIDSet_img_2, true);
	lv_img_set_src(ui->TempPIDSet_img_2,&_hotends_alpha_35x41);
//	lv_img_set_pivot(ui->TempPIDSet_img_2, 0,0);
//	lv_img_set_angle(ui->TempPIDSet_img_2, 0);

	//Write codes TempPIDSet_img_back
	ui->TempPIDSet_img_back = lv_img_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_IMG_PART_MAIN for TempPIDSet_img_back
//	static lv_style_t style_TempPIDSet_img_back_main;
//	lv_style_reset(&style_TempPIDSet_img_back_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_img_back_main
//	lv_style_set_image_recolor(&style_TempPIDSet_img_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_TempPIDSet_img_back_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_TempPIDSet_img_back_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->TempPIDSet_img_back, LV_IMG_PART_MAIN, &style_TempPIDSet_img_back_main);
	lv_obj_set_pos(ui->TempPIDSet_img_back, 24, 30);
//	lv_obj_set_size(ui->TempPIDSet_img_back, 45, 36);
	lv_obj_set_click(ui->TempPIDSet_img_back, true);
	lv_img_set_src(ui->TempPIDSet_img_back,&_return_alpha_45x36);
//	lv_img_set_pivot(ui->TempPIDSet_img_back, 0,0);
//	lv_img_set_angle(ui->TempPIDSet_img_back, 0);

	//Write codes TempPIDSet_label_1
	ui->TempPIDSet_label_1 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_1, temp_pid_setting[cur_language]);
	lv_label_set_long_mode(ui->TempPIDSet_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_1, LV_LABEL_ALIGN_RIGHT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_1
	static lv_style_t style_TempPIDSet_label_1_main;
	lv_style_reset(&style_TempPIDSet_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_1_main
	lv_style_set_radius(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_1, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_1_main);
	lv_obj_set_pos(ui->TempPIDSet_label_1, 113, 32);
	lv_obj_set_size(ui->TempPIDSet_label_1, 347, 0);

	//Write codes TempPIDSet_label_6
	ui->TempPIDSet_label_6 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_6, "P");
	lv_label_set_long_mode(ui->TempPIDSet_label_6, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_6, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_6
	static lv_style_t style_TempPIDSet_label_6_main;
	lv_style_reset(&style_TempPIDSet_label_6_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_6_main
	lv_style_set_radius(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_6_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_6, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_6_main);
	lv_obj_set_pos(ui->TempPIDSet_label_6, 37, 125);
	lv_obj_set_size(ui->TempPIDSet_label_6, 20, 0);

	//Write codes TempPIDSet_label_hotend_pid_p
	ui->TempPIDSet_label_hotend_pid_p = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_hotend_pid_p, "");
	lv_label_set_long_mode(ui->TempPIDSet_label_hotend_pid_p, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_hotend_pid_p, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_hotend_pid_p
	static lv_style_t style_TempPIDSet_label_hotend_pid_p_main;
	lv_style_reset(&style_TempPIDSet_label_hotend_pid_p_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_hotend_pid_p_main
	lv_style_set_radius(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_hotend_pid_p_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_hotend_pid_p, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_hotend_pid_p_main);
	lv_obj_set_pos(ui->TempPIDSet_label_hotend_pid_p, 34, 198);
	lv_obj_set_size(ui->TempPIDSet_label_hotend_pid_p, 150, 0);

	//Write codes TempPIDSet_btn_bed_pid_p
	ui->TempPIDSet_btn_bed_pid_p = lv_btn_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_BTN_PART_MAIN for TempPIDSet_btn_bed_pid_p
	static lv_style_t style_TempPIDSet_btn_bed_pid_p_main;
	lv_style_reset(&style_TempPIDSet_btn_bed_pid_p_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_btn_bed_pid_p_main
	lv_style_set_radius(&style_TempPIDSet_btn_bed_pid_p_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_TempPIDSet_btn_bed_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_btn_bed_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_btn_bed_pid_p_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_btn_bed_pid_p_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_TempPIDSet_btn_bed_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_TempPIDSet_btn_bed_pid_p_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_TempPIDSet_btn_bed_pid_p_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_TempPIDSet_btn_bed_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_TempPIDSet_btn_bed_pid_p_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->TempPIDSet_btn_bed_pid_p, LV_BTN_PART_MAIN, &style_TempPIDSet_btn_bed_pid_p_main);
	lv_obj_set_pos(ui->TempPIDSet_btn_bed_pid_p, 246, 106);
	lv_obj_set_size(ui->TempPIDSet_btn_bed_pid_p, 225, 206);
//	ui->TempPIDSet_btn_bed_pid_p_label = lv_label_create(ui->TempPIDSet_btn_bed_pid_p, NULL);
//	lv_label_set_text(ui->TempPIDSet_btn_bed_pid_p_label, "");
//	lv_obj_set_style_local_text_color(ui->TempPIDSet_btn_bed_pid_p_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes TempPIDSet_btn_hotend_pid_i
	ui->TempPIDSet_btn_hotend_pid_i = lv_btn_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_BTN_PART_MAIN for TempPIDSet_btn_hotend_pid_i
	static lv_style_t style_TempPIDSet_btn_hotend_pid_i_main;
	lv_style_reset(&style_TempPIDSet_btn_hotend_pid_i_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_btn_hotend_pid_i_main
	lv_style_set_radius(&style_TempPIDSet_btn_hotend_pid_i_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_TempPIDSet_btn_hotend_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_btn_hotend_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_btn_hotend_pid_i_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_btn_hotend_pid_i_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_TempPIDSet_btn_hotend_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_TempPIDSet_btn_hotend_pid_i_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_TempPIDSet_btn_hotend_pid_i_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_TempPIDSet_btn_hotend_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_TempPIDSet_btn_hotend_pid_i_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->TempPIDSet_btn_hotend_pid_i, LV_BTN_PART_MAIN, &style_TempPIDSet_btn_hotend_pid_i_main);
	lv_obj_set_pos(ui->TempPIDSet_btn_hotend_pid_i, 10, 326);
	lv_obj_set_size(ui->TempPIDSet_btn_hotend_pid_i, 224, 206);
//	ui->TempPIDSet_btn_hotend_pid_i_label = lv_label_create(ui->TempPIDSet_btn_hotend_pid_i, NULL);
//	lv_label_set_text(ui->TempPIDSet_btn_hotend_pid_i_label, "");
//	lv_obj_set_style_local_text_color(ui->TempPIDSet_btn_hotend_pid_i_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes TempPIDSet_btn_bed_pid_i
	ui->TempPIDSet_btn_bed_pid_i = lv_btn_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_BTN_PART_MAIN for TempPIDSet_btn_bed_pid_i
	static lv_style_t style_TempPIDSet_btn_bed_pid_i_main;
	lv_style_reset(&style_TempPIDSet_btn_bed_pid_i_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_btn_bed_pid_i_main
	lv_style_set_radius(&style_TempPIDSet_btn_bed_pid_i_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_TempPIDSet_btn_bed_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_btn_bed_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_btn_bed_pid_i_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_btn_bed_pid_i_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_TempPIDSet_btn_bed_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_TempPIDSet_btn_bed_pid_i_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_TempPIDSet_btn_bed_pid_i_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_TempPIDSet_btn_bed_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_TempPIDSet_btn_bed_pid_i_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->TempPIDSet_btn_bed_pid_i, LV_BTN_PART_MAIN, &style_TempPIDSet_btn_bed_pid_i_main);
	lv_obj_set_pos(ui->TempPIDSet_btn_bed_pid_i, 246, 326);
	lv_obj_set_size(ui->TempPIDSet_btn_bed_pid_i, 225, 206);
//	ui->TempPIDSet_btn_bed_pid_i_label = lv_label_create(ui->TempPIDSet_btn_bed_pid_i, NULL);
//	lv_label_set_text(ui->TempPIDSet_btn_bed_pid_i_label, "");
//	lv_obj_set_style_local_text_color(ui->TempPIDSet_btn_bed_pid_i_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes TempPIDSet_img_3
	ui->TempPIDSet_img_3 = lv_img_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_IMG_PART_MAIN for TempPIDSet_img_3
//	static lv_style_t style_TempPIDSet_img_3_main;
//	lv_style_reset(&style_TempPIDSet_img_3_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_img_3_main
//	lv_style_set_image_recolor(&style_TempPIDSet_img_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_TempPIDSet_img_3_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_TempPIDSet_img_3_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->TempPIDSet_img_3, LV_IMG_PART_MAIN, &style_TempPIDSet_img_3_main);
	lv_obj_set_pos(ui->TempPIDSet_img_3, 262, 132);
//	lv_obj_set_size(ui->TempPIDSet_img_3, 44, 19);
//	lv_obj_set_click(ui->TempPIDSet_img_3, true);
	lv_img_set_src(ui->TempPIDSet_img_3,&_bed_alpha_44x19);
//	lv_img_set_pivot(ui->TempPIDSet_img_3, 0,0);
//	lv_img_set_angle(ui->TempPIDSet_img_3, 0);

	//Write codes TempPIDSet_img_4
	ui->TempPIDSet_img_4 = lv_img_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_IMG_PART_MAIN for TempPIDSet_img_4
//	static lv_style_t style_TempPIDSet_img_4_main;
//	lv_style_reset(&style_TempPIDSet_img_4_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_img_4_main
//	lv_style_set_image_recolor(&style_TempPIDSet_img_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_TempPIDSet_img_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_TempPIDSet_img_4_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->TempPIDSet_img_4, LV_IMG_PART_MAIN, &style_TempPIDSet_img_4_main);
	lv_obj_set_pos(ui->TempPIDSet_img_4, 26, 339);
//	lv_obj_set_size(ui->TempPIDSet_img_4, 35, 41);
//	lv_obj_set_click(ui->TempPIDSet_img_4, true);
	lv_img_set_src(ui->TempPIDSet_img_4,&_hotends_alpha_35x41);
//	lv_img_set_pivot(ui->TempPIDSet_img_4, 0,0);
//	lv_img_set_angle(ui->TempPIDSet_img_4, 0);

	//Write codes TempPIDSet_img_5
	ui->TempPIDSet_img_5 = lv_img_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_IMG_PART_MAIN for TempPIDSet_img_5
//	static lv_style_t style_TempPIDSet_img_5_main;
//	lv_style_reset(&style_TempPIDSet_img_5_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_img_5_main
//	lv_style_set_image_recolor(&style_TempPIDSet_img_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_TempPIDSet_img_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_TempPIDSet_img_5_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->TempPIDSet_img_5, LV_IMG_PART_MAIN, &style_TempPIDSet_img_5_main);
	lv_obj_set_pos(ui->TempPIDSet_img_5, 262, 352);
//	lv_obj_set_size(ui->TempPIDSet_img_5, 44, 19);
//	lv_obj_set_click(ui->TempPIDSet_img_5, true);
	lv_img_set_src(ui->TempPIDSet_img_5,&_bed_alpha_44x19);
//	lv_img_set_pivot(ui->TempPIDSet_img_5, 0,0);
//	lv_img_set_angle(ui->TempPIDSet_img_5, 0);

	//Write codes TempPIDSet_label_8
	ui->TempPIDSet_label_8 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_8, "P");
	lv_label_set_long_mode(ui->TempPIDSet_label_8, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_8, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_8
	static lv_style_t style_TempPIDSet_label_8_main;
	lv_style_reset(&style_TempPIDSet_label_8_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_8_main
	lv_style_set_radius(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_8_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_8, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_8_main);
	lv_obj_set_pos(ui->TempPIDSet_label_8, 277, 119);
	lv_obj_set_size(ui->TempPIDSet_label_8, 20, 0);

	//Write codes TempPIDSet_label_9
	ui->TempPIDSet_label_9 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_9, "I");
	lv_label_set_long_mode(ui->TempPIDSet_label_9, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_9, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_9
	static lv_style_t style_TempPIDSet_label_9_main;
	lv_style_reset(&style_TempPIDSet_label_9_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_9_main
	lv_style_set_radius(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_9_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_9, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_9_main);
	lv_obj_set_pos(ui->TempPIDSet_label_9, 277, 341);
	lv_obj_set_size(ui->TempPIDSet_label_9, 20, 0);

	//Write codes TempPIDSet_label_10
	ui->TempPIDSet_label_10 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_10, "I");
	lv_label_set_long_mode(ui->TempPIDSet_label_10, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_10, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_10
	static lv_style_t style_TempPIDSet_label_10_main;
	lv_style_reset(&style_TempPIDSet_label_10_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_10_main
	lv_style_set_radius(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_10_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_10, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_10_main);
	lv_obj_set_pos(ui->TempPIDSet_label_10, 40, 345);
	lv_obj_set_size(ui->TempPIDSet_label_10, 20, 0);

	//Write codes TempPIDSet_label_11
	ui->TempPIDSet_label_11 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_11, bed_i_value[cur_language]);
	lv_label_set_long_mode(ui->TempPIDSet_label_11, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_11, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_11
	static lv_style_t style_TempPIDSet_label_11_main;
	lv_style_reset(&style_TempPIDSet_label_11_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_11_main
	lv_style_set_radius(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
	else
    {
        lv_style_set_text_font(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_11_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_11, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_11_main);
	lv_obj_set_pos(ui->TempPIDSet_label_11, 270, 480);
	lv_obj_set_size(ui->TempPIDSet_label_11, 200, 0);

	//Write codes TempPIDSet_label_12
	ui->TempPIDSet_label_12 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_12, noz_i_value[cur_language]);
	lv_label_set_long_mode(ui->TempPIDSet_label_12, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_12, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_12
	static lv_style_t style_TempPIDSet_label_12_main;
	lv_style_reset(&style_TempPIDSet_label_12_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_12_main
	lv_style_set_radius(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_12_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_12, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_12_main);
	lv_obj_set_pos(ui->TempPIDSet_label_12, 34, 480);
	lv_obj_set_size(ui->TempPIDSet_label_12, 200, 0);

	//Write codes TempPIDSet_label_13
	ui->TempPIDSet_label_13 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_13, bed_p_value[cur_language]);
	lv_label_set_long_mode(ui->TempPIDSet_label_13, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_13, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_13
	static lv_style_t style_TempPIDSet_label_13_main;
	lv_style_reset(&style_TempPIDSet_label_13_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_13_main
	lv_style_set_radius(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_13_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_13, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_13_main);
	lv_obj_set_pos(ui->TempPIDSet_label_13, 270, 260);
	lv_obj_set_size(ui->TempPIDSet_label_13, 200, 0);

	//Write codes TempPIDSet_label_bed_pid_p
	ui->TempPIDSet_label_bed_pid_p = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_bed_pid_p, "");
	lv_label_set_long_mode(ui->TempPIDSet_label_bed_pid_p, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_bed_pid_p, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_bed_pid_p
	static lv_style_t style_TempPIDSet_label_bed_pid_p_main;
	lv_style_reset(&style_TempPIDSet_label_bed_pid_p_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_bed_pid_p_main
	lv_style_set_radius(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_bed_pid_p_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_bed_pid_p, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_bed_pid_p_main);
	lv_obj_set_pos(ui->TempPIDSet_label_bed_pid_p, 270, 198);
	lv_obj_set_size(ui->TempPIDSet_label_bed_pid_p, 150, 0);

	//Write codes TempPIDSet_label_hotend_pid_i
	ui->TempPIDSet_label_hotend_pid_i = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_hotend_pid_i, "");
	lv_label_set_long_mode(ui->TempPIDSet_label_hotend_pid_i, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_hotend_pid_i, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_hotend_pid_i
	static lv_style_t style_TempPIDSet_label_hotend_pid_i_main;
	lv_style_reset(&style_TempPIDSet_label_hotend_pid_i_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_hotend_pid_i_main
	lv_style_set_radius(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_hotend_pid_i_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_hotend_pid_i, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_hotend_pid_i_main);
	lv_obj_set_pos(ui->TempPIDSet_label_hotend_pid_i, 34, 418);
	lv_obj_set_size(ui->TempPIDSet_label_hotend_pid_i, 150, 0);

	//Write codes TempPIDSet_label_bed_pid_i
	ui->TempPIDSet_label_bed_pid_i = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_bed_pid_i, "");
	lv_label_set_long_mode(ui->TempPIDSet_label_bed_pid_i, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_bed_pid_i, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_bed_pid_i
	static lv_style_t style_TempPIDSet_label_bed_pid_i_main;
	lv_style_reset(&style_TempPIDSet_label_bed_pid_i_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_bed_pid_i_main
	lv_style_set_radius(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_bed_pid_i_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_bed_pid_i, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_bed_pid_i_main);
	lv_obj_set_pos(ui->TempPIDSet_label_bed_pid_i, 270, 418);
	lv_obj_set_size(ui->TempPIDSet_label_bed_pid_i, 150, 0);

	//Write codes TempPIDSet_btn_hotend_pid_d
	ui->TempPIDSet_btn_hotend_pid_d = lv_btn_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_BTN_PART_MAIN for TempPIDSet_btn_hotend_pid_d
	static lv_style_t style_TempPIDSet_btn_hotend_pid_d_main;
	lv_style_reset(&style_TempPIDSet_btn_hotend_pid_d_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_btn_hotend_pid_d_main
	lv_style_set_radius(&style_TempPIDSet_btn_hotend_pid_d_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_TempPIDSet_btn_hotend_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_btn_hotend_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_btn_hotend_pid_d_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_btn_hotend_pid_d_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_TempPIDSet_btn_hotend_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_TempPIDSet_btn_hotend_pid_d_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_TempPIDSet_btn_hotend_pid_d_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_TempPIDSet_btn_hotend_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_TempPIDSet_btn_hotend_pid_d_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->TempPIDSet_btn_hotend_pid_d, LV_BTN_PART_MAIN, &style_TempPIDSet_btn_hotend_pid_d_main);
	lv_obj_set_pos(ui->TempPIDSet_btn_hotend_pid_d, 10, 546);
	lv_obj_set_size(ui->TempPIDSet_btn_hotend_pid_d, 224, 206);
//	ui->TempPIDSet_btn_hotend_pid_d_label = lv_label_create(ui->TempPIDSet_btn_hotend_pid_d, NULL);
//	lv_label_set_text(ui->TempPIDSet_btn_hotend_pid_d_label, "");
//	lv_obj_set_style_local_text_color(ui->TempPIDSet_btn_hotend_pid_d_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes TempPIDSet_btn_bed_pid_d
	ui->TempPIDSet_btn_bed_pid_d = lv_btn_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_BTN_PART_MAIN for TempPIDSet_btn_bed_pid_d
	static lv_style_t style_TempPIDSet_btn_bed_pid_d_main;
	lv_style_reset(&style_TempPIDSet_btn_bed_pid_d_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_btn_bed_pid_d_main
	lv_style_set_radius(&style_TempPIDSet_btn_bed_pid_d_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_TempPIDSet_btn_bed_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_btn_bed_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_btn_bed_pid_d_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_btn_bed_pid_d_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_TempPIDSet_btn_bed_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_TempPIDSet_btn_bed_pid_d_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_TempPIDSet_btn_bed_pid_d_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_TempPIDSet_btn_bed_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_TempPIDSet_btn_bed_pid_d_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->TempPIDSet_btn_bed_pid_d, LV_BTN_PART_MAIN, &style_TempPIDSet_btn_bed_pid_d_main);
	lv_obj_set_pos(ui->TempPIDSet_btn_bed_pid_d, 246, 546);
	lv_obj_set_size(ui->TempPIDSet_btn_bed_pid_d, 225, 206);
//	ui->TempPIDSet_btn_bed_pid_d_label = lv_label_create(ui->TempPIDSet_btn_bed_pid_d, NULL);
//	lv_label_set_text(ui->TempPIDSet_btn_bed_pid_d_label, "");
//	lv_obj_set_style_local_text_color(ui->TempPIDSet_btn_bed_pid_d_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes TempPIDSet_label_17
	ui->TempPIDSet_label_17 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_17, noz_d_value[cur_language]);
	lv_label_set_long_mode(ui->TempPIDSet_label_17, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_17, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_17
	static lv_style_t style_TempPIDSet_label_17_main;
	lv_style_reset(&style_TempPIDSet_label_17_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_17_main
	lv_style_set_radius(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_17_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_17, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_17_main);
	lv_obj_set_pos(ui->TempPIDSet_label_17, 34, 700);
	lv_obj_set_size(ui->TempPIDSet_label_17, 200, 0);

	//Write codes TempPIDSet_label_hotend_pid_d
	ui->TempPIDSet_label_hotend_pid_d = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_hotend_pid_d, "");
	lv_label_set_long_mode(ui->TempPIDSet_label_hotend_pid_d, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_hotend_pid_d, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_hotend_pid_d
	static lv_style_t style_TempPIDSet_label_hotend_pid_d_main;
	lv_style_reset(&style_TempPIDSet_label_hotend_pid_d_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_hotend_pid_d_main
	lv_style_set_radius(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_hotend_pid_d_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_hotend_pid_d, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_hotend_pid_d_main);
	lv_obj_set_pos(ui->TempPIDSet_label_hotend_pid_d, 34, 638);
	lv_obj_set_size(ui->TempPIDSet_label_hotend_pid_d, 150, 0);

	//Write codes TempPIDSet_img_6
	ui->TempPIDSet_img_6 = lv_img_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_IMG_PART_MAIN for TempPIDSet_img_6
//	static lv_style_t style_TempPIDSet_img_6_main;
//	lv_style_reset(&style_TempPIDSet_img_6_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_img_6_main
//	lv_style_set_image_recolor(&style_TempPIDSet_img_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_TempPIDSet_img_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_TempPIDSet_img_6_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->TempPIDSet_img_6, LV_IMG_PART_MAIN, &style_TempPIDSet_img_6_main);
	lv_obj_set_pos(ui->TempPIDSet_img_6, 26, 559);
//	lv_obj_set_size(ui->TempPIDSet_img_6, 35, 41);
//	lv_obj_set_click(ui->TempPIDSet_img_6, true);
	lv_img_set_src(ui->TempPIDSet_img_6,&_hotends_alpha_35x41);
//	lv_img_set_pivot(ui->TempPIDSet_img_6, 0,0);
//	lv_img_set_angle(ui->TempPIDSet_img_6, 0);

	//Write codes TempPIDSet_label_19
	ui->TempPIDSet_label_19 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_19, "D");
	lv_label_set_long_mode(ui->TempPIDSet_label_19, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_19, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_19
	static lv_style_t style_TempPIDSet_label_19_main;
	lv_style_reset(&style_TempPIDSet_label_19_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_19_main
	lv_style_set_radius(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_19_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_19, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_19_main);
	lv_obj_set_pos(ui->TempPIDSet_label_19, 36, 565);
	lv_obj_set_size(ui->TempPIDSet_label_19, 20, 0);

	//Write codes TempPIDSet_label_20
	ui->TempPIDSet_label_20 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_20, bed_d_value[cur_language]);
	lv_label_set_long_mode(ui->TempPIDSet_label_20, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_20, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_20
	static lv_style_t style_TempPIDSet_label_20_main;
	lv_style_reset(&style_TempPIDSet_label_20_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_20_main
	lv_style_set_radius(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
	else
    {
        lv_style_set_text_font(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
    }
	lv_style_set_text_letter_space(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_20_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_20, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_20_main);
	lv_obj_set_pos(ui->TempPIDSet_label_20, 270, 700);
	lv_obj_set_size(ui->TempPIDSet_label_20, 200, 0);

	//Write codes TempPIDSet_label_bed_pid_d
	ui->TempPIDSet_label_bed_pid_d = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_bed_pid_d, "");
	lv_label_set_long_mode(ui->TempPIDSet_label_bed_pid_d, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_bed_pid_d, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_bed_pid_d
	static lv_style_t style_TempPIDSet_label_bed_pid_d_main;
	lv_style_reset(&style_TempPIDSet_label_bed_pid_d_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_bed_pid_d_main
	lv_style_set_radius(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_bed_pid_d_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_bed_pid_d, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_bed_pid_d_main);
	lv_obj_set_pos(ui->TempPIDSet_label_bed_pid_d, 270, 638);
	lv_obj_set_size(ui->TempPIDSet_label_bed_pid_d, 150, 0);

	//Write codes TempPIDSet_img_7
	ui->TempPIDSet_img_7 = lv_img_create(ui->TempPIDSet_cont_temppid_set, NULL);

	//Write style LV_IMG_PART_MAIN for TempPIDSet_img_7
//	static lv_style_t style_TempPIDSet_img_7_main;
//	lv_style_reset(&style_TempPIDSet_img_7_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_img_7_main
//	lv_style_set_image_recolor(&style_TempPIDSet_img_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_TempPIDSet_img_7_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_TempPIDSet_img_7_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->TempPIDSet_img_7, LV_IMG_PART_MAIN, &style_TempPIDSet_img_7_main);
	lv_obj_set_pos(ui->TempPIDSet_img_7, 262, 572);
//	lv_obj_set_size(ui->TempPIDSet_img_7, 44, 20);
//	lv_obj_set_click(ui->TempPIDSet_img_7, true);
	lv_img_set_src(ui->TempPIDSet_img_7,&_beda_alpha_44x20);
//	lv_img_set_pivot(ui->TempPIDSet_img_7, 0,0);
//	lv_img_set_angle(ui->TempPIDSet_img_7, 0);

	//Write codes TempPIDSet_label_22
	ui->TempPIDSet_label_22 = lv_label_create(ui->TempPIDSet_cont_temppid_set, NULL);
	lv_label_set_text(ui->TempPIDSet_label_22, "D");
	lv_label_set_long_mode(ui->TempPIDSet_label_22, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->TempPIDSet_label_22, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for TempPIDSet_label_22
	static lv_style_t style_TempPIDSet_label_22_main;
	lv_style_reset(&style_TempPIDSet_label_22_main);

	//Write style state: LV_STATE_DEFAULT for style_TempPIDSet_label_22_main
	lv_style_set_radius(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, &lv_font_simsun_22);
	lv_style_set_text_letter_space(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_TempPIDSet_label_22_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->TempPIDSet_label_22, LV_LABEL_PART_MAIN, &style_TempPIDSet_label_22_main);
	lv_obj_set_pos(ui->TempPIDSet_label_22, 277, 561);
	lv_obj_set_size(ui->TempPIDSet_label_22, 20, 0);
	lv_cont_set_layout(ui->TempPIDSet_cont_temppid_set, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->TempPIDSet_cont_temppid_set, LV_FIT_NONE);

	//Init events for screen
	events_init_TempPIDSet(ui);
}
