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

void setup_scr_Level_title(lv_ui *ui){

	//Write codes Level_title
//	ui->Level_title = lv_obj_create(NULL, NULL);

	//Write codes Level_title_cont_level_title
    if(ui->Level_title_cont_level_title != NULL)
    {
//        lv_obj_move_foreground(ui->Level_title_cont_level_title);
        return;
    }
	ui->Level_title_cont_level_title = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for Level_title_cont_level_title
	static lv_style_t style_Level_title_cont_level_title_main;
	lv_style_reset(&style_Level_title_cont_level_title_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_title_cont_level_title_main
	lv_style_set_radius(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_color(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
//	lv_style_set_bg_grad_dir(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_title_cont_level_title_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_title_cont_level_title, LV_CONT_PART_MAIN, &style_Level_title_cont_level_title_main);
	lv_obj_set_pos(ui->Level_title_cont_level_title, 0, 0);
	lv_obj_set_size(ui->Level_title_cont_level_title, 480, 90);
	lv_obj_set_click(ui->Level_title_cont_level_title, false);

	//Write codes Level_title_img_back
	ui->Level_title_img_back = lv_img_create(ui->Level_title_cont_level_title, NULL);

	//Write style LV_IMG_PART_MAIN for Level_title_img_back
//	static lv_style_t style_Level_title_img_back_main;
//	lv_style_reset(&style_Level_title_img_back_main);
//
//	//Write style state: LV_STATE_DEFAULT for style_Level_title_img_back_main
//	lv_style_set_image_recolor(&style_Level_title_img_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_image_recolor_opa(&style_Level_title_img_back_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_image_opa(&style_Level_title_img_back_main, LV_STATE_DEFAULT, 255);
//	lv_obj_add_style(ui->Level_title_img_back, LV_IMG_PART_MAIN, &style_Level_title_img_back_main);
	lv_obj_set_pos(ui->Level_title_img_back, 24, 30);
//	lv_obj_set_size(ui->Level_title_img_back, 45, 36);
	lv_obj_set_click(ui->Level_title_img_back, true);
	lv_img_set_src(ui->Level_title_img_back,&_return_alpha_45x36);
//	lv_img_set_pivot(ui->Level_title_img_back, 0,0);
//	lv_img_set_angle(ui->Level_title_img_back, 0);

	//Write codes Level_title_label_1
	ui->Level_title_label_1 = lv_label_create(ui->Level_title_cont_level_title, NULL);
	lv_label_set_text(ui->Level_title_label_1, level[cur_language]);
	lv_label_set_long_mode(ui->Level_title_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Level_title_label_1, LV_LABEL_ALIGN_RIGHT);

	//Write style LV_LABEL_PART_MAIN for Level_title_label_1
	static lv_style_t style_Level_title_label_1_main;
	lv_style_reset(&style_Level_title_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_title_label_1_main
	lv_style_set_radius(&style_Level_title_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_title_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_Level_title_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_Level_title_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_title_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Level_title_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
    if(cur_language > 0)
    {
        lv_style_set_text_font(&style_Level_title_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_Level_title_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_Level_title_label_1_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Level_title_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_title_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_title_label_1_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_title_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_title_label_1, LV_LABEL_PART_MAIN, &style_Level_title_label_1_main);
	lv_obj_set_pos(ui->Level_title_label_1, 113, 32);
	lv_obj_set_size(ui->Level_title_label_1, 347, 0);
	lv_cont_set_layout(ui->Level_title_cont_level_title, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->Level_title_cont_level_title, LV_FIT_NONE);

	//Init events for screen
	events_init_Level_title(ui);
}
