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

void setup_scr_Level_auto(lv_ui *ui){

	//Write codes Level_auto
//	ui->Level_auto = lv_obj_create(NULL, NULL);

	//Write codes Level_auto_cont_level_auto
	ui->Level_auto_cont_level_auto = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for Level_auto_cont_level_auto
	static lv_style_t style_Level_auto_cont_level_auto_main;
	lv_style_reset(&style_Level_auto_cont_level_auto_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_auto_cont_level_auto_main
	lv_style_set_radius(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_auto_cont_level_auto_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_auto_cont_level_auto, LV_CONT_PART_MAIN, &style_Level_auto_cont_level_auto_main);
	lv_obj_set_pos(ui->Level_auto_cont_level_auto, 0, 0);
	lv_obj_set_size(ui->Level_auto_cont_level_auto, 480, 691);
	lv_obj_set_click(ui->Level_auto_cont_level_auto, false);

	//Write codes Level_auto_btn_16
	ui->Level_auto_btn_16 = lv_btn_create(ui->Level_auto_cont_level_auto, NULL);

	//Write style LV_BTN_PART_MAIN for Level_auto_btn_16
	static lv_style_t style_Level_auto_btn_16_main;
	lv_style_reset(&style_Level_auto_btn_16_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_auto_btn_16_main
	lv_style_set_radius(&style_Level_auto_btn_16_main, LV_STATE_DEFAULT, 16);
	lv_style_set_bg_color(&style_Level_auto_btn_16_main, LV_STATE_DEFAULT, lv_color_make(0x1b, 0x1e, 0x25));
	//lv_style_set_bg_grad_color(&style_Level_auto_btn_16_main, LV_STATE_DEFAULT, lv_color_make(0x1b, 0x1e, 0x25));
	//lv_style_set_bg_grad_dir(&style_Level_auto_btn_16_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_auto_btn_16_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Level_auto_btn_16_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_Level_auto_btn_16_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_auto_btn_16_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_auto_btn_16_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_auto_btn_16_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Level_auto_btn_16, LV_BTN_PART_MAIN, &style_Level_auto_btn_16_main);
	lv_obj_set_pos(ui->Level_auto_btn_16, 22, 122);
	lv_obj_set_size(ui->Level_auto_btn_16, 436, 398);
//	ui->Level_auto_btn_16_label = lv_label_create(ui->Level_auto_btn_16, NULL);
//	lv_label_set_text(ui->Level_auto_btn_16_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_auto_btn_16_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes Level_auto_label_zauto_progress
	ui->Level_auto_label_zauto_progress = lv_label_create(ui->Level_auto_cont_level_auto, NULL);
	lv_label_set_text(ui->Level_auto_label_zauto_progress, "30%");
	lv_label_set_long_mode(ui->Level_auto_label_zauto_progress, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Level_auto_label_zauto_progress, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Level_auto_label_zauto_progress
	static lv_style_t style_Level_auto_label_zauto_progress_main;
	lv_style_reset(&style_Level_auto_label_zauto_progress_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_auto_label_zauto_progress_main
	lv_style_set_radius(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_auto_label_zauto_progress_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_auto_label_zauto_progress, LV_LABEL_PART_MAIN, &style_Level_auto_label_zauto_progress_main);
	lv_obj_set_pos(ui->Level_auto_label_zauto_progress, 32, 456);
	lv_obj_set_size(ui->Level_auto_label_zauto_progress, 416, 0);

	//Write codes Level_auto_img_6
	ui->Level_auto_img_6 = lv_img_create(ui->Level_auto_cont_level_auto, NULL);

	//Write style LV_IMG_PART_MAIN for Level_auto_img_6
//	static lv_style_t style_Level_auto_img_6_main;
//	lv_style_reset(&style_Level_auto_img_6_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Level_auto_img_6_main
//	lv_style_set_image_recolor(&style_Level_auto_img_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Level_auto_img_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Level_auto_img_6_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Level_auto_img_6, LV_IMG_PART_MAIN, &style_Level_auto_img_6_main);
	lv_obj_set_pos(ui->Level_auto_img_6, 90, 310);
//	lv_obj_set_size(ui->Level_auto_img_6, 300, 78);
//	lv_obj_set_click(ui->Level_auto_img_6, true);
	lv_img_set_src(ui->Level_auto_img_6,&_level_alpha_300x78);
//	lv_img_set_pivot(ui->Level_auto_img_6, 0,0);
//	lv_img_set_angle(ui->Level_auto_img_6, 0);

	//Write codes Level_auto_label_13
	ui->Level_auto_label_13 = lv_label_create(ui->Level_auto_cont_level_auto, NULL);
	lv_label_set_long_mode(ui->Level_auto_label_13, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->Level_auto_label_13, leveling[cur_language]);
//	lv_label_set_long_mode(ui->Level_auto_label_13, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Level_auto_label_13, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Level_auto_label_13
	static lv_style_t style_Level_auto_label_13_main;
	lv_style_reset(&style_Level_auto_label_13_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_auto_label_13_main
	lv_style_set_radius(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_auto_label_13_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_auto_label_13, LV_LABEL_PART_MAIN, &style_Level_auto_label_13_main);
	lv_obj_set_pos(ui->Level_auto_label_13, 32, 171);
	lv_obj_set_size(ui->Level_auto_label_13, 416, 42);

	//Write codes Level_auto_label_14
	ui->Level_auto_label_14 = lv_label_create(ui->Level_auto_cont_level_auto, NULL);
	lv_label_set_long_mode(ui->Level_auto_label_14, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->Level_auto_label_14, waiting[cur_language]);
//	lv_label_set_long_mode(ui->Level_auto_label_14, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Level_auto_label_14, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Level_auto_label_14
	static lv_style_t style_Level_auto_label_14_main;
	lv_style_reset(&style_Level_auto_label_14_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_auto_label_14_main
	lv_style_set_radius(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_auto_label_14_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_auto_label_14, LV_LABEL_PART_MAIN, &style_Level_auto_label_14_main);
	lv_obj_set_pos(ui->Level_auto_label_14, 32, 211);
	lv_obj_set_size(ui->Level_auto_label_14, 416, 42);

	//Write codes Level_auto_btn_zauto_start
	ui->Level_auto_btn_zauto_start = lv_btn_create(ui->Level_auto_cont_level_auto, NULL);

	//Write style LV_BTN_PART_MAIN for Level_auto_btn_zauto_start
	static lv_style_t style_Level_auto_btn_zauto_start_main;
	lv_style_reset(&style_Level_auto_btn_zauto_start_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_auto_btn_zauto_start_main
	lv_style_set_radius(&style_Level_auto_btn_zauto_start_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_Level_auto_btn_zauto_start_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Level_auto_btn_zauto_start_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Level_auto_btn_zauto_start_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_auto_btn_zauto_start_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_Level_auto_btn_zauto_start_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_auto_btn_zauto_start_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_Level_auto_btn_zauto_start_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_auto_btn_zauto_start_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_auto_btn_zauto_start_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_Level_auto_btn_zauto_start_main
	lv_style_set_radius(&style_Level_auto_btn_zauto_start_main, LV_STATE_PRESSED, 50);
	lv_style_set_bg_color(&style_Level_auto_btn_zauto_start_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Level_auto_btn_zauto_start_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Level_auto_btn_zauto_start_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_auto_btn_zauto_start_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_Level_auto_btn_zauto_start_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_Level_auto_btn_zauto_start_main, LV_STATE_PRESSED, 3);
	lv_style_set_border_opa(&style_Level_auto_btn_zauto_start_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_Level_auto_btn_zauto_start_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_Level_auto_btn_zauto_start_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->Level_auto_btn_zauto_start, LV_BTN_PART_MAIN, &style_Level_auto_btn_zauto_start_main);
	lv_obj_set_pos(ui->Level_auto_btn_zauto_start, 106, 557);
	lv_obj_set_size(ui->Level_auto_btn_zauto_start, 268, 81);
	ui->Level_auto_btn_zauto_start_label = lv_label_create(ui->Level_auto_btn_zauto_start, NULL);
	lv_label_set_text(ui->Level_auto_btn_zauto_start_label, start[cur_language]);
	lv_obj_set_style_local_text_color(ui->Level_auto_btn_zauto_start_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_obj_set_style_local_text_font(ui->Level_auto_btn_zauto_start_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_obj_set_style_local_text_font(ui->Level_auto_btn_zauto_start_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }

	//Write codes Level_auto_btn_mask
	ui->Level_auto_btn_mask = lv_btn_create(ui->Level_auto_cont_level_auto, NULL);

	//Write style LV_BTN_PART_MAIN for Level_auto_btn_mask
	static lv_style_t style_Level_auto_btn_mask_main;
	lv_style_reset(&style_Level_auto_btn_mask_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_auto_btn_mask_main
	lv_style_set_radius(&style_Level_auto_btn_mask_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_auto_btn_mask_main, LV_STATE_DEFAULT, lv_color_make(0x1b, 0x1e, 0x25));
	//lv_style_set_bg_grad_color(&style_Level_auto_btn_mask_main, LV_STATE_DEFAULT, lv_color_make(0x1b, 0x1e, 0x25));
	//lv_style_set_bg_grad_dir(&style_Level_auto_btn_mask_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_auto_btn_mask_main, LV_STATE_DEFAULT, 180);
//	lv_style_set_border_color(&style_Level_auto_btn_mask_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_Level_auto_btn_mask_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_auto_btn_mask_main, LV_STATE_DEFAULT, 0);
	lv_style_set_outline_color(&style_Level_auto_btn_mask_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_Level_auto_btn_mask_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_auto_btn_mask, LV_BTN_PART_MAIN, &style_Level_auto_btn_mask_main);
	lv_obj_set_pos(ui->Level_auto_btn_mask, 90, 297);
	lv_obj_set_size(ui->Level_auto_btn_mask, 300, 50);
//	ui->Level_auto_btn_mask_label = lv_label_create(ui->Level_auto_btn_mask, NULL);
//	lv_label_set_text(ui->Level_auto_btn_mask_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_auto_btn_mask_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_cont_set_layout(ui->Level_auto_cont_level_auto, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->Level_auto_cont_level_auto, LV_FIT_NONE);

	//Init events for screen
	events_init_Level_auto(ui);
}
