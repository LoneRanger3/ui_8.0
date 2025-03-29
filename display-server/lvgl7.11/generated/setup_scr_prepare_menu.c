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

void setup_scr_prepare_menu(lv_ui *ui){

	//Write codes prepare_menu
//	ui->prepare_menu = lv_obj_create(NULL, NULL);

	//Write codes prepare_menu_cont_prepare_menu
    if(ui->prepare_menu_cont_prepare_menu != NULL)
    {
        lv_obj_move_foreground(ui->prepare_menu_cont_prepare_menu);
        return;
    }
	ui->prepare_menu_cont_prepare_menu = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for prepare_menu_cont_prepare_menu
	static lv_style_t style_prepare_menu_cont_prepare_menu_main;
	lv_style_reset(&style_prepare_menu_cont_prepare_menu_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_menu_cont_prepare_menu_main
	lv_style_set_radius(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_prepare_menu_cont_prepare_menu_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_menu_cont_prepare_menu, LV_CONT_PART_MAIN, &style_prepare_menu_cont_prepare_menu_main);
	lv_obj_set_pos(ui->prepare_menu_cont_prepare_menu, 0, 0);
	lv_obj_set_size(ui->prepare_menu_cont_prepare_menu, 480, 105);
	lv_obj_set_click(ui->prepare_menu_cont_prepare_menu, false);

	//Write codes prepare_menu_btn_move_axis
	ui->prepare_menu_btn_move_axis = lv_btn_create(ui->prepare_menu_cont_prepare_menu, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_menu_btn_move_axis
	static lv_style_t style_prepare_menu_btn_move_axis_main;
	lv_style_reset(&style_prepare_menu_btn_move_axis_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_menu_btn_move_axis_main
	lv_style_set_radius(&style_prepare_menu_btn_move_axis_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_menu_btn_move_axis_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_prepare_menu_btn_move_axis_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_prepare_menu_btn_move_axis_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_menu_btn_move_axis_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_menu_btn_move_axis_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_menu_btn_move_axis_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_menu_btn_move_axis_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_menu_btn_move_axis_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_menu_btn_move_axis_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_prepare_menu_btn_move_axis_main
	lv_style_set_radius(&style_prepare_menu_btn_move_axis_main, LV_STATE_PRESSED, 6);
	lv_style_set_bg_color(&style_prepare_menu_btn_move_axis_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_color(&style_prepare_menu_btn_move_axis_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_dir(&style_prepare_menu_btn_move_axis_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_menu_btn_move_axis_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_prepare_menu_btn_move_axis_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_prepare_menu_btn_move_axis_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_prepare_menu_btn_move_axis_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_prepare_menu_btn_move_axis_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_menu_btn_move_axis_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->prepare_menu_btn_move_axis, LV_BTN_PART_MAIN, &style_prepare_menu_btn_move_axis_main);
	lv_obj_set_pos(ui->prepare_menu_btn_move_axis, 0, 0);
	lv_obj_set_size(ui->prepare_menu_btn_move_axis, 158, 104);
//	ui->prepare_menu_btn_move_axis_label = lv_label_create(ui->prepare_menu_btn_move_axis, NULL);
//	lv_label_set_text(ui->prepare_menu_btn_move_axis_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_menu_btn_move_axis_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes prepare_menu_btn_move_e
	ui->prepare_menu_btn_move_e = lv_btn_create(ui->prepare_menu_cont_prepare_menu, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_menu_btn_move_e
	static lv_style_t style_prepare_menu_btn_move_e_main;
	lv_style_reset(&style_prepare_menu_btn_move_e_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_menu_btn_move_e_main
	lv_style_set_radius(&style_prepare_menu_btn_move_e_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_menu_btn_move_e_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_prepare_menu_btn_move_e_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_prepare_menu_btn_move_e_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_menu_btn_move_e_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_menu_btn_move_e_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_menu_btn_move_e_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_menu_btn_move_e_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_menu_btn_move_e_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_menu_btn_move_e_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_prepare_menu_btn_move_e_main
	lv_style_set_radius(&style_prepare_menu_btn_move_e_main, LV_STATE_PRESSED, 6);
	lv_style_set_bg_color(&style_prepare_menu_btn_move_e_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_color(&style_prepare_menu_btn_move_e_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_dir(&style_prepare_menu_btn_move_e_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_menu_btn_move_e_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_prepare_menu_btn_move_e_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_prepare_menu_btn_move_e_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_prepare_menu_btn_move_e_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_prepare_menu_btn_move_e_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_menu_btn_move_e_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->prepare_menu_btn_move_e, LV_BTN_PART_MAIN, &style_prepare_menu_btn_move_e_main);
	lv_obj_set_pos(ui->prepare_menu_btn_move_e, 160, 0);
	lv_obj_set_size(ui->prepare_menu_btn_move_e, 158, 104);
//	ui->prepare_menu_btn_move_e_label = lv_label_create(ui->prepare_menu_btn_move_e, NULL);
//	lv_label_set_text(ui->prepare_menu_btn_move_e_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_menu_btn_move_e_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes prepare_menu_btn_manual_temp
	ui->prepare_menu_btn_manual_temp = lv_btn_create(ui->prepare_menu_cont_prepare_menu, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_menu_btn_manual_temp
	static lv_style_t style_prepare_menu_btn_manual_temp_main;
	lv_style_reset(&style_prepare_menu_btn_manual_temp_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_menu_btn_manual_temp_main
	lv_style_set_radius(&style_prepare_menu_btn_manual_temp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_menu_btn_manual_temp_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_color(&style_prepare_menu_btn_manual_temp_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
//	lv_style_set_bg_grad_dir(&style_prepare_menu_btn_manual_temp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_menu_btn_manual_temp_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_menu_btn_manual_temp_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_prepare_menu_btn_manual_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_menu_btn_manual_temp_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_menu_btn_manual_temp_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_menu_btn_manual_temp_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_prepare_menu_btn_manual_temp_main
	lv_style_set_radius(&style_prepare_menu_btn_manual_temp_main, LV_STATE_PRESSED, 6);
	lv_style_set_bg_color(&style_prepare_menu_btn_manual_temp_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_color(&style_prepare_menu_btn_manual_temp_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
//	lv_style_set_bg_grad_dir(&style_prepare_menu_btn_manual_temp_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_menu_btn_manual_temp_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_prepare_menu_btn_manual_temp_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_prepare_menu_btn_manual_temp_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_prepare_menu_btn_manual_temp_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_prepare_menu_btn_manual_temp_main, LV_STATE_PRESSED, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_menu_btn_manual_temp_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->prepare_menu_btn_manual_temp, LV_BTN_PART_MAIN, &style_prepare_menu_btn_manual_temp_main);
	lv_obj_set_pos(ui->prepare_menu_btn_manual_temp, 320, 0);
	lv_obj_set_size(ui->prepare_menu_btn_manual_temp, 158, 104);
//	ui->prepare_menu_btn_manual_temp_label = lv_label_create(ui->prepare_menu_btn_manual_temp, NULL);
//	lv_label_set_text(ui->prepare_menu_btn_manual_temp_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_menu_btn_manual_temp_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));

	//Write codes prepare_menu_label_manual_temp
	ui->prepare_menu_label_manual_temp = lv_label_create(ui->prepare_menu_cont_prepare_menu, NULL);
	lv_label_set_long_mode(ui->prepare_menu_label_manual_temp, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->prepare_menu_label_manual_temp, manual_temp[cur_language]);
//	lv_label_set_long_mode(ui->prepare_menu_label_manual_temp, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_menu_label_manual_temp, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_menu_label_manual_temp
	static lv_style_t style_prepare_menu_label_manual_temp_main;
	lv_style_reset(&style_prepare_menu_label_manual_temp_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_menu_label_manual_temp_main
	lv_style_set_radius(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_menu_label_manual_temp_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_menu_label_manual_temp, LV_LABEL_PART_MAIN, &style_prepare_menu_label_manual_temp_main);
	lv_obj_set_pos(ui->prepare_menu_label_manual_temp, 325, 38);
	lv_obj_set_size(ui->prepare_menu_label_manual_temp, 150, 42);

	//Write codes prepare_menu_label_move_axis
	ui->prepare_menu_label_move_axis = lv_label_create(ui->prepare_menu_cont_prepare_menu, NULL);
    lv_label_set_long_mode(ui->prepare_menu_label_move_axis, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->prepare_menu_label_move_axis, move_axis[cur_language]);
//	lv_label_set_long_mode(ui->prepare_menu_label_move_axis, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_menu_label_move_axis, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_menu_label_move_axis
	static lv_style_t style_prepare_menu_label_move_axis_main;
	lv_style_reset(&style_prepare_menu_label_move_axis_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_menu_label_move_axis_main
	lv_style_set_radius(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_menu_label_move_axis_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_menu_label_move_axis, LV_LABEL_PART_MAIN, &style_prepare_menu_label_move_axis_main);
	lv_obj_set_pos(ui->prepare_menu_label_move_axis, 5, 38);
	lv_obj_set_size(ui->prepare_menu_label_move_axis, 150, 42);

	//Write codes prepare_menu_label_material
	ui->prepare_menu_label_material = lv_label_create(ui->prepare_menu_cont_prepare_menu, NULL);
	lv_label_set_long_mode(ui->prepare_menu_label_material, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->prepare_menu_label_material, in_out_material[cur_language]);
//	lv_label_set_long_mode(ui->prepare_menu_label_material, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_menu_label_material, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_menu_label_material
	static lv_style_t style_prepare_menu_label_material_main;
	lv_style_reset(&style_prepare_menu_label_material_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_menu_label_material_main
	lv_style_set_radius(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_color(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_bg_grad_dir(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_menu_label_material_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_menu_label_material, LV_LABEL_PART_MAIN, &style_prepare_menu_label_material_main);
	lv_obj_set_pos(ui->prepare_menu_label_material, 165, 38);
	lv_obj_set_size(ui->prepare_menu_label_material, 150, 42);
	lv_cont_set_layout(ui->prepare_menu_cont_prepare_menu, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->prepare_menu_cont_prepare_menu, LV_FIT_NONE);

	//Init events for screen
	events_init_prepare_menu(ui);
}
