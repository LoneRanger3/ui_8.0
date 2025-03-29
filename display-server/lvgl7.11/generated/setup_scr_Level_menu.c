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

void setup_scr_Level_menu(lv_ui *ui){

	//Write codes Level_menu
//	ui->Level_menu = lv_obj_create(NULL, NULL);

	//Write codes Level_menu_cont_level_menu
    if(ui->Level_menu_cont_level_menu != NULL)
    {
        return;
    }
	ui->Level_menu_cont_level_menu = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for Level_menu_cont_level_menu
	static lv_style_t style_Level_menu_cont_level_menu_main;
	lv_style_reset(&style_Level_menu_cont_level_menu_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_menu_cont_level_menu_main
	lv_style_set_radius(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_menu_cont_level_menu_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_menu_cont_level_menu, LV_CONT_PART_MAIN, &style_Level_menu_cont_level_menu_main);
	lv_obj_set_pos(ui->Level_menu_cont_level_menu, 0, 0);
	lv_obj_set_size(ui->Level_menu_cont_level_menu, 480, 800);
	lv_obj_set_click(ui->Level_menu_cont_level_menu, false);

	//Write codes Level_menu_btn_manual_level
	ui->Level_menu_btn_manual_level = lv_btn_create(ui->Level_menu_cont_level_menu, NULL);

	//Write style LV_BTN_PART_MAIN for Level_menu_btn_manual_level
	static lv_style_t style_Level_menu_btn_manual_level_main;
	lv_style_reset(&style_Level_menu_btn_manual_level_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_menu_btn_manual_level_main
	lv_style_set_radius(&style_Level_menu_btn_manual_level_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_menu_btn_manual_level_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_Level_menu_btn_manual_level_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_Level_menu_btn_manual_level_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_menu_btn_manual_level_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Level_menu_btn_manual_level_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Level_menu_btn_manual_level_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_menu_btn_manual_level_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_menu_btn_manual_level_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_menu_btn_manual_level_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_CHECKED for style_Level_menu_btn_manual_level_main
	lv_style_set_radius(&style_Level_menu_btn_manual_level_main, LV_STATE_CHECKED, 0);
	lv_style_set_bg_color(&style_Level_menu_btn_manual_level_main, LV_STATE_CHECKED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Level_menu_btn_manual_level_main, LV_STATE_CHECKED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Level_menu_btn_manual_level_main, LV_STATE_CHECKED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_menu_btn_manual_level_main, LV_STATE_CHECKED, 255);
//	lv_style_set_border_color(&style_Level_menu_btn_manual_level_main, LV_STATE_CHECKED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Level_menu_btn_manual_level_main, LV_STATE_CHECKED, 0);
//	lv_style_set_border_opa(&style_Level_menu_btn_manual_level_main, LV_STATE_CHECKED, 255);
	lv_style_set_outline_color(&style_Level_menu_btn_manual_level_main, LV_STATE_CHECKED, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_menu_btn_manual_level_main, LV_STATE_CHECKED, 255);
	lv_obj_add_style(ui->Level_menu_btn_manual_level, LV_BTN_PART_MAIN, &style_Level_menu_btn_manual_level_main);
	lv_obj_set_pos(ui->Level_menu_btn_manual_level, 0, 691);
	lv_obj_set_size(ui->Level_menu_btn_manual_level, 239, 109);
//	ui->Level_menu_btn_manual_level_label = lv_label_create(ui->Level_menu_btn_manual_level, NULL);
//	lv_label_set_text(ui->Level_menu_btn_manual_level_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_menu_btn_manual_level_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes Level_menu_btn_auto_level
	ui->Level_menu_btn_auto_level = lv_btn_create(ui->Level_menu_cont_level_menu, NULL);

	//Write style LV_BTN_PART_MAIN for Level_menu_btn_auto_level
	static lv_style_t style_Level_menu_btn_auto_level_main;
	lv_style_reset(&style_Level_menu_btn_auto_level_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_menu_btn_auto_level_main
	lv_style_set_radius(&style_Level_menu_btn_auto_level_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_menu_btn_auto_level_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_Level_menu_btn_auto_level_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_Level_menu_btn_auto_level_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_menu_btn_auto_level_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Level_menu_btn_auto_level_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Level_menu_btn_auto_level_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Level_menu_btn_auto_level_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Level_menu_btn_auto_level_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_menu_btn_auto_level_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_CHECKED for style_Level_menu_btn_auto_level_main
	lv_style_set_radius(&style_Level_menu_btn_auto_level_main, LV_STATE_CHECKED, 0);
	lv_style_set_bg_color(&style_Level_menu_btn_auto_level_main, LV_STATE_CHECKED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Level_menu_btn_auto_level_main, LV_STATE_CHECKED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Level_menu_btn_auto_level_main, LV_STATE_CHECKED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_menu_btn_auto_level_main, LV_STATE_CHECKED, 255);
//	lv_style_set_border_color(&style_Level_menu_btn_auto_level_main, LV_STATE_CHECKED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_Level_menu_btn_auto_level_main, LV_STATE_CHECKED, 0);
//	lv_style_set_border_opa(&style_Level_menu_btn_auto_level_main, LV_STATE_CHECKED, 255);
	lv_style_set_outline_color(&style_Level_menu_btn_auto_level_main, LV_STATE_CHECKED, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Level_menu_btn_auto_level_main, LV_STATE_CHECKED, 255);
	lv_obj_add_style(ui->Level_menu_btn_auto_level, LV_BTN_PART_MAIN, &style_Level_menu_btn_auto_level_main);
	lv_obj_set_pos(ui->Level_menu_btn_auto_level, 240, 691);
	lv_obj_set_size(ui->Level_menu_btn_auto_level, 239, 109);
//	ui->Level_menu_btn_auto_level_label = lv_label_create(ui->Level_menu_btn_auto_level, NULL);
//	lv_label_set_text(ui->Level_menu_btn_auto_level_label, "");
//	lv_obj_set_style_local_text_color(ui->Level_menu_btn_auto_level_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes Level_menu_label_auto_level
	ui->Level_menu_label_auto_level = lv_label_create(ui->Level_menu_cont_level_menu, NULL);
	lv_label_set_long_mode(ui->Level_menu_label_auto_level, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->Level_menu_label_auto_level, auto_level[cur_language]);
//	lv_label_set_long_mode(ui->Level_menu_label_auto_level, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Level_menu_label_auto_level, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Level_menu_label_auto_level
	static lv_style_t style_Level_menu_label_auto_level_main;
	lv_style_reset(&style_Level_menu_label_auto_level_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_menu_label_auto_level_main
	lv_style_set_radius(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_menu_label_auto_level_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_menu_label_auto_level, LV_LABEL_PART_MAIN, &style_Level_menu_label_auto_level_main);
	lv_obj_set_pos(ui->Level_menu_label_auto_level, 245, 730);
	lv_obj_set_size(ui->Level_menu_label_auto_level, 230, 42);

	//Write codes Level_menu_label_aux_level
	ui->Level_menu_label_aux_level = lv_label_create(ui->Level_menu_cont_level_menu, NULL);
	lv_label_set_long_mode(ui->Level_menu_label_aux_level, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->Level_menu_label_aux_level, aux_level[cur_language]);
//	lv_label_set_long_mode(ui->Level_menu_label_aux_level, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Level_menu_label_aux_level, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Level_menu_label_aux_level
	static lv_style_t style_Level_menu_label_aux_level_main;
	lv_style_reset(&style_Level_menu_label_aux_level_main);

	//Write style state: LV_STATE_DEFAULT for style_Level_menu_label_aux_level_main
	lv_style_set_radius(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Level_menu_label_aux_level_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Level_menu_label_aux_level, LV_LABEL_PART_MAIN, &style_Level_menu_label_aux_level_main);
	lv_obj_set_pos(ui->Level_menu_label_aux_level, 5, 730);
	lv_obj_set_size(ui->Level_menu_label_aux_level, 230, 42);
	lv_cont_set_layout(ui->Level_menu_cont_level_menu, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->Level_menu_cont_level_menu, LV_FIT_NONE);

	//Init events for screen
	events_init_Level_menu(ui);
}
