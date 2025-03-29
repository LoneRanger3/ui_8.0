/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_prepare_move_axis(lv_ui *ui){

	//Write codes prepare_move_axis
//	ui->prepare_move_axis = lv_obj_create(NULL, NULL);

	if(ui->prepare_move_axis_cont_prepare_move_axis != NULL)
    {
        return;
    }
	//Write codes prepare_move_axis_cont_prepare_move_axis
	ui->prepare_move_axis_cont_prepare_move_axis = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for prepare_move_axis_cont_prepare_move_axis
	static lv_style_t style_prepare_move_axis_cont_prepare_move_axis_main;
	lv_style_reset(&style_prepare_move_axis_cont_prepare_move_axis_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_cont_prepare_move_axis_main
	lv_style_set_radius(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_move_axis_cont_prepare_move_axis_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_move_axis_cont_prepare_move_axis, LV_CONT_PART_MAIN, &style_prepare_move_axis_cont_prepare_move_axis_main);
	lv_obj_set_pos(ui->prepare_move_axis_cont_prepare_move_axis, 0, 0);
	lv_obj_set_size(ui->prepare_move_axis_cont_prepare_move_axis, 480, 674);
	lv_obj_set_click(ui->prepare_move_axis_cont_prepare_move_axis, false);

	//Write codes prepare_move_axis_btn_13
	ui->prepare_move_axis_btn_13 = lv_btn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_move_axis_btn_13
	static lv_style_t style_prepare_move_axis_btn_13_main;
	lv_style_reset(&style_prepare_move_axis_btn_13_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_btn_13_main
	lv_style_set_radius(&style_prepare_move_axis_btn_13_main, LV_STATE_DEFAULT, 150);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_13_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_13_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_13_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_13_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_prepare_move_axis_btn_13_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_prepare_move_axis_btn_13_main, LV_STATE_DEFAULT, 3);
	lv_style_set_border_opa(&style_prepare_move_axis_btn_13_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_13_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_13_main, LV_STATE_DEFAULT, 100);

	//Write style state: LV_STATE_PRESSED for style_prepare_move_axis_btn_13_main
	lv_style_set_radius(&style_prepare_move_axis_btn_13_main, LV_STATE_PRESSED, 150);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_13_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_13_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_13_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_13_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_prepare_move_axis_btn_13_main, LV_STATE_PRESSED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_move_axis_btn_13_main, LV_STATE_PRESSED, 3);
	lv_style_set_border_opa(&style_prepare_move_axis_btn_13_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_13_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_13_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->prepare_move_axis_btn_13, LV_BTN_PART_MAIN, &style_prepare_move_axis_btn_13_main);
	lv_obj_set_pos(ui->prepare_move_axis_btn_13, 360, 336);
	lv_obj_set_size(ui->prepare_move_axis_btn_13, 100, 100);
//	ui->prepare_move_axis_btn_13_label = lv_label_create(ui->prepare_move_axis_btn_13, NULL);
//	lv_label_set_text(ui->prepare_move_axis_btn_13_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_move_axis_btn_13_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_move_axis_btn_5
	ui->prepare_move_axis_btn_5 = lv_btn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_move_axis_btn_5
	static lv_style_t style_prepare_move_axis_btn_5_main;
	lv_style_reset(&style_prepare_move_axis_btn_5_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_btn_5_main
	lv_style_set_radius(&style_prepare_move_axis_btn_5_main, LV_STATE_DEFAULT, 26);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_5_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_5_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_move_axis_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_prepare_move_axis_btn_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_move_axis_btn_5_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_5_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_btn_5, LV_BTN_PART_MAIN, &style_prepare_move_axis_btn_5_main);
	lv_obj_set_pos(ui->prepare_move_axis_btn_5, 14, 574);
	lv_obj_set_size(ui->prepare_move_axis_btn_5, 452, 52);
//	ui->prepare_move_axis_btn_5_label = lv_label_create(ui->prepare_move_axis_btn_5, NULL);
//	lv_label_set_text(ui->prepare_move_axis_btn_5_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_move_axis_btn_5_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_move_axis_btn_12
	ui->prepare_move_axis_btn_12 = lv_btn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_move_axis_btn_12
	static lv_style_t style_prepare_move_axis_btn_12_main;
	lv_style_reset(&style_prepare_move_axis_btn_12_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_btn_12_main
	lv_style_set_radius(&style_prepare_move_axis_btn_12_main, LV_STATE_DEFAULT, 150);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_12_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_12_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_12_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_prepare_move_axis_btn_12_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_prepare_move_axis_btn_12_main, LV_STATE_DEFAULT, 3);
	lv_style_set_border_opa(&style_prepare_move_axis_btn_12_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_12_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_12_main, LV_STATE_DEFAULT, 100);

	//Write style state: LV_STATE_PRESSED for style_prepare_move_axis_btn_12_main
	lv_style_set_radius(&style_prepare_move_axis_btn_12_main, LV_STATE_PRESSED, 150);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_12_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_12_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_12_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_12_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_prepare_move_axis_btn_12_main, LV_STATE_PRESSED, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_prepare_move_axis_btn_12_main, LV_STATE_PRESSED, 3);
	lv_style_set_border_opa(&style_prepare_move_axis_btn_12_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_12_main, LV_STATE_PRESSED, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_12_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->prepare_move_axis_btn_12, LV_BTN_PART_MAIN, &style_prepare_move_axis_btn_12_main);
	lv_obj_set_pos(ui->prepare_move_axis_btn_12, 115, 336);
	lv_obj_set_size(ui->prepare_move_axis_btn_12, 100, 100);
//	ui->prepare_move_axis_btn_12_label = lv_label_create(ui->prepare_move_axis_btn_12, NULL);
//	lv_label_set_text(ui->prepare_move_axis_btn_12_label, "");
//	lv_obj_set_style_local_text_color(ui->prepare_move_axis_btn_12_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));

	//Write codes prepare_move_axis_btn_move_uintc
	ui->prepare_move_axis_btn_move_uintc = lv_btn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_move_axis_btn_move_uintc
	static lv_style_t style_prepare_move_axis_btn_move_uintc_main;
	lv_style_reset(&style_prepare_move_axis_btn_move_uintc_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_btn_move_uintc_main
	lv_style_set_radius(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_prepare_move_axis_btn_move_uintc_main
	lv_style_set_radius(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_PRESSED, 50);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_PRESSED, 255);
//	lv_style_set_border_color(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_PRESSED, 0);
//	lv_style_set_border_opa(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_move_uintc_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->prepare_move_axis_btn_move_uintc, LV_BTN_PART_MAIN, &style_prepare_move_axis_btn_move_uintc_main);
	lv_obj_set_pos(ui->prepare_move_axis_btn_move_uintc, 321, 578);
	lv_obj_set_size(ui->prepare_move_axis_btn_move_uintc, 142, 44);
	lv_btn_set_checkable(ui->prepare_move_axis_btn_move_uintc, true);
	ui->prepare_move_axis_btn_move_uintc_label = lv_label_create(ui->prepare_move_axis_btn_move_uintc, NULL);
	lv_label_set_text(ui->prepare_move_axis_btn_move_uintc_label, "10mm");
	lv_obj_set_style_local_text_color(ui->prepare_move_axis_btn_move_uintc_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->prepare_move_axis_btn_move_uintc_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes prepare_move_axis_btn_move_uintb
	ui->prepare_move_axis_btn_move_uintb = lv_btn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_move_axis_btn_move_uintb
	static lv_style_t style_prepare_move_axis_btn_move_uintb_main;
	lv_style_reset(&style_prepare_move_axis_btn_move_uintb_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_btn_move_uintb_main
	lv_style_set_radius(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_DEFAULT, 100);

	//Write style state: LV_STATE_PRESSED for style_prepare_move_axis_btn_move_uintb_main
	lv_style_set_radius(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_PRESSED, 50);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_PRESSED, 255);
//	lv_style_set_border_color(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_PRESSED, 0);
//	lv_style_set_border_opa(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_move_uintb_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->prepare_move_axis_btn_move_uintb, LV_BTN_PART_MAIN, &style_prepare_move_axis_btn_move_uintb_main);
	lv_obj_set_pos(ui->prepare_move_axis_btn_move_uintb, 168, 578);
	lv_obj_set_size(ui->prepare_move_axis_btn_move_uintb, 146, 44);
	lv_btn_set_checkable(ui->prepare_move_axis_btn_move_uintb, true);
	ui->prepare_move_axis_btn_move_uintb_label = lv_label_create(ui->prepare_move_axis_btn_move_uintb, NULL);
	lv_label_set_text(ui->prepare_move_axis_btn_move_uintb_label, "1mm");
	lv_obj_set_style_local_text_color(ui->prepare_move_axis_btn_move_uintb_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->prepare_move_axis_btn_move_uintb_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes prepare_move_axis_btn_move_uinta
	ui->prepare_move_axis_btn_move_uinta = lv_btn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_move_axis_btn_move_uinta
	static lv_style_t style_prepare_move_axis_btn_move_uinta_main;
	lv_style_reset(&style_prepare_move_axis_btn_move_uinta_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_btn_move_uinta_main
	lv_style_set_radius(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_DEFAULT, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_DEFAULT, 100);

	//Write style state: LV_STATE_PRESSED for style_prepare_move_axis_btn_move_uinta_main
	lv_style_set_radius(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_PRESSED, 50);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_PRESSED, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_PRESSED, 255);
	lv_style_set_border_color(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_PRESSED, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_PRESSED, 1);
	lv_style_set_border_opa(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_PRESSED, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_PRESSED, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_move_uinta_main, LV_STATE_PRESSED, 100);
	lv_obj_add_style(ui->prepare_move_axis_btn_move_uinta, LV_BTN_PART_MAIN, &style_prepare_move_axis_btn_move_uinta_main);
	lv_obj_set_pos(ui->prepare_move_axis_btn_move_uinta, 18, 578);
	lv_obj_set_size(ui->prepare_move_axis_btn_move_uinta, 142, 44);
	lv_btn_set_checkable(ui->prepare_move_axis_btn_move_uinta, true);
	ui->prepare_move_axis_btn_move_uinta_label = lv_label_create(ui->prepare_move_axis_btn_move_uinta, NULL);
	lv_label_set_text(ui->prepare_move_axis_btn_move_uinta_label, "0.1mm");
	lv_obj_set_style_local_text_color(ui->prepare_move_axis_btn_move_uinta_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->prepare_move_axis_btn_move_uinta_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);

	//Write codes prepare_move_axis_btn_cur_xposition
	ui->prepare_move_axis_btn_cur_xposition = lv_btn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_move_axis_btn_cur_xposition
	static lv_style_t style_prepare_move_axis_btn_cur_xposition_main;
	lv_style_reset(&style_prepare_move_axis_btn_cur_xposition_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_btn_cur_xposition_main
	lv_style_set_radius(&style_prepare_move_axis_btn_cur_xposition_main, LV_STATE_DEFAULT, 7);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_cur_xposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_cur_xposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_cur_xposition_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_cur_xposition_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_move_axis_btn_cur_xposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_prepare_move_axis_btn_cur_xposition_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_move_axis_btn_cur_xposition_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_cur_xposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_cur_xposition_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_btn_cur_xposition, LV_BTN_PART_MAIN, &style_prepare_move_axis_btn_cur_xposition_main);
	lv_obj_set_pos(ui->prepare_move_axis_btn_cur_xposition, 50, 125);
	lv_obj_set_size(ui->prepare_move_axis_btn_cur_xposition, 88, 36);
	ui->prepare_move_axis_btn_cur_xposition_label = lv_label_create(ui->prepare_move_axis_btn_cur_xposition, NULL);
	lv_label_set_text(ui->prepare_move_axis_btn_cur_xposition_label, "?");
	lv_obj_set_style_local_text_color(ui->prepare_move_axis_btn_cur_xposition_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->prepare_move_axis_btn_cur_xposition_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_22);

	//Write codes prepare_move_axis_btn_cur_yposition
	ui->prepare_move_axis_btn_cur_yposition = lv_btn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_move_axis_btn_cur_yposition
	static lv_style_t style_prepare_move_axis_btn_cur_yposition_main;
	lv_style_reset(&style_prepare_move_axis_btn_cur_yposition_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_btn_cur_yposition_main
	lv_style_set_radius(&style_prepare_move_axis_btn_cur_yposition_main, LV_STATE_DEFAULT, 7);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_cur_yposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_cur_yposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_cur_yposition_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_cur_yposition_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_move_axis_btn_cur_yposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_prepare_move_axis_btn_cur_yposition_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_move_axis_btn_cur_yposition_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_cur_yposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_cur_yposition_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_btn_cur_yposition, LV_BTN_PART_MAIN, &style_prepare_move_axis_btn_cur_yposition_main);
	lv_obj_set_pos(ui->prepare_move_axis_btn_cur_yposition, 210, 125);
	lv_obj_set_size(ui->prepare_move_axis_btn_cur_yposition, 88, 36);
	ui->prepare_move_axis_btn_cur_yposition_label = lv_label_create(ui->prepare_move_axis_btn_cur_yposition, NULL);
	lv_label_set_text(ui->prepare_move_axis_btn_cur_yposition_label, "?");
	lv_obj_set_style_local_text_color(ui->prepare_move_axis_btn_cur_yposition_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->prepare_move_axis_btn_cur_yposition_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_22);

	//Write codes prepare_move_axis_imgbtn_motor_z_down
	ui->prepare_move_axis_imgbtn_motor_z_down = lv_imgbtn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_IMGBTN_PART_MAIN for prepare_move_axis_imgbtn_motor_z_down
	static lv_style_t style_prepare_move_axis_imgbtn_motor_z_down_main;
	lv_style_reset(&style_prepare_move_axis_imgbtn_motor_z_down_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_z_down_main
	lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_imgbtn_motor_z_down, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_z_down_main);
	lv_obj_set_pos(ui->prepare_move_axis_imgbtn_motor_z_down, 359, 460);
	lv_obj_set_size(ui->prepare_move_axis_imgbtn_motor_z_down, 98, 64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_down,LV_BTN_STATE_RELEASED,&_downa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_down,LV_BTN_STATE_PRESSED,&_downa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_down,LV_BTN_STATE_CHECKED_RELEASED,&_downa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_down,LV_BTN_STATE_CHECKED_PRESSED,&_downa_alpha_98x64);
	lv_imgbtn_set_checkable(ui->prepare_move_axis_imgbtn_motor_z_down, true);

	//Write codes prepare_move_axis_btn_cur_zposition
	ui->prepare_move_axis_btn_cur_zposition = lv_btn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_BTN_PART_MAIN for prepare_move_axis_btn_cur_zposition
	static lv_style_t style_prepare_move_axis_btn_cur_zposition_main;
	lv_style_reset(&style_prepare_move_axis_btn_cur_zposition_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_btn_cur_zposition_main
	lv_style_set_radius(&style_prepare_move_axis_btn_cur_zposition_main, LV_STATE_DEFAULT, 7);
	lv_style_set_bg_color(&style_prepare_move_axis_btn_cur_zposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_btn_cur_zposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_btn_cur_zposition_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_btn_cur_zposition_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_prepare_move_axis_btn_cur_zposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_border_width(&style_prepare_move_axis_btn_cur_zposition_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_prepare_move_axis_btn_cur_zposition_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_prepare_move_axis_btn_cur_zposition_main, LV_STATE_DEFAULT, lv_color_make(0x10, 0x12, 0x16));
	lv_style_set_outline_opa(&style_prepare_move_axis_btn_cur_zposition_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_btn_cur_zposition, LV_BTN_PART_MAIN, &style_prepare_move_axis_btn_cur_zposition_main);
	lv_obj_set_pos(ui->prepare_move_axis_btn_cur_zposition, 370, 125);
	lv_obj_set_size(ui->prepare_move_axis_btn_cur_zposition, 88, 36);
	ui->prepare_move_axis_btn_cur_zposition_label = lv_label_create(ui->prepare_move_axis_btn_cur_zposition, NULL);
	lv_label_set_text(ui->prepare_move_axis_btn_cur_zposition_label, "?");
	lv_obj_set_style_local_text_color(ui->prepare_move_axis_btn_cur_zposition_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_obj_set_style_local_text_font(ui->prepare_move_axis_btn_cur_zposition_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_22);

	//Write codes prepare_move_axis_imgbtn_motor_z_up
	ui->prepare_move_axis_imgbtn_motor_z_up = lv_imgbtn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_IMGBTN_PART_MAIN for prepare_move_axis_imgbtn_motor_z_up
	static lv_style_t style_prepare_move_axis_imgbtn_motor_z_up_main;
	lv_style_reset(&style_prepare_move_axis_imgbtn_motor_z_up_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_z_up_main
	lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_imgbtn_motor_z_up, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_z_up_main);
	lv_obj_set_pos(ui->prepare_move_axis_imgbtn_motor_z_up, 359, 242);
	lv_obj_set_size(ui->prepare_move_axis_imgbtn_motor_z_up, 98, 64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_up,LV_BTN_STATE_RELEASED,&_upa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_up,LV_BTN_STATE_PRESSED,&_upa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_up,LV_BTN_STATE_CHECKED_RELEASED,&_upa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_up,LV_BTN_STATE_CHECKED_PRESSED,&_upa_alpha_98x64);
	lv_imgbtn_set_checkable(ui->prepare_move_axis_imgbtn_motor_z_up, true);

	//Write codes prepare_move_axis_imgbtn_motor_x_right
	ui->prepare_move_axis_imgbtn_motor_x_right = lv_imgbtn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_IMGBTN_PART_MAIN for prepare_move_axis_imgbtn_motor_x_right
	static lv_style_t style_prepare_move_axis_imgbtn_motor_x_right_main;
	lv_style_reset(&style_prepare_move_axis_imgbtn_motor_x_right_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_x_right_main
	lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_imgbtn_motor_x_right, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_x_right_main);
	lv_obj_set_pos(ui->prepare_move_axis_imgbtn_motor_x_right, 251, 335);
	lv_obj_set_size(ui->prepare_move_axis_imgbtn_motor_x_right, 61, 102);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_x_right,LV_BTN_STATE_RELEASED,&_righta_alpha_61x102);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_x_right,LV_BTN_STATE_PRESSED,&_righta_alpha_61x102);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_x_right,LV_BTN_STATE_CHECKED_RELEASED,&_righta_alpha_61x102);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_x_right,LV_BTN_STATE_CHECKED_PRESSED,&_righta_alpha_61x102);
	lv_imgbtn_set_checkable(ui->prepare_move_axis_imgbtn_motor_x_right, true);

	//Write codes prepare_move_axis_imgbtn_motor_x_left
	ui->prepare_move_axis_imgbtn_motor_x_left = lv_imgbtn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_IMGBTN_PART_MAIN for prepare_move_axis_imgbtn_motor_x_left
	static lv_style_t style_prepare_move_axis_imgbtn_motor_x_left_main;
	lv_style_reset(&style_prepare_move_axis_imgbtn_motor_x_left_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_x_left_main
	lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_imgbtn_motor_x_left, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_x_left_main);
	lv_obj_set_pos(ui->prepare_move_axis_imgbtn_motor_x_left, 19, 335);
	lv_obj_set_size(ui->prepare_move_axis_imgbtn_motor_x_left, 61, 102);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_x_left,LV_BTN_STATE_RELEASED,&_lefta_alpha_61x102);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_x_left,LV_BTN_STATE_PRESSED,&_lefta_alpha_61x102);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_x_left,LV_BTN_STATE_CHECKED_RELEASED,&_lefta_alpha_61x102);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_x_left,LV_BTN_STATE_CHECKED_PRESSED,&_lefta_alpha_61x102);
	lv_imgbtn_set_checkable(ui->prepare_move_axis_imgbtn_motor_x_left, true);

	//Write codes prepare_move_axis_imgbtn_motor_y_down
	ui->prepare_move_axis_imgbtn_motor_y_down = lv_imgbtn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_IMGBTN_PART_MAIN for prepare_move_axis_imgbtn_motor_y_down
	static lv_style_t style_prepare_move_axis_imgbtn_motor_y_down_main;
	lv_style_reset(&style_prepare_move_axis_imgbtn_motor_y_down_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_y_down_main
	lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_imgbtn_motor_y_down, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_y_down_main);
	lv_obj_set_pos(ui->prepare_move_axis_imgbtn_motor_y_down, 114, 460);
	lv_obj_set_size(ui->prepare_move_axis_imgbtn_motor_y_down, 98, 64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_y_down,LV_BTN_STATE_RELEASED,&_downa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_y_down,LV_BTN_STATE_PRESSED,&_downa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_y_down,LV_BTN_STATE_CHECKED_RELEASED,&_downa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_y_down,LV_BTN_STATE_CHECKED_PRESSED,&_downa_alpha_98x64);
	lv_imgbtn_set_checkable(ui->prepare_move_axis_imgbtn_motor_y_down, true);

	//Write codes prepare_move_axis_imgbtn_motor_y_up
	ui->prepare_move_axis_imgbtn_motor_y_up = lv_imgbtn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_IMGBTN_PART_MAIN for prepare_move_axis_imgbtn_motor_y_up
	static lv_style_t style_prepare_move_axis_imgbtn_motor_y_up_main;
	lv_style_reset(&style_prepare_move_axis_imgbtn_motor_y_up_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_y_up_main
	lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_imgbtn_motor_y_up, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_y_up_main);
	lv_obj_set_pos(ui->prepare_move_axis_imgbtn_motor_y_up, 114, 242);
	lv_obj_set_size(ui->prepare_move_axis_imgbtn_motor_y_up, 98, 64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_y_up,LV_BTN_STATE_RELEASED,&_upa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_y_up,LV_BTN_STATE_PRESSED,&_upa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_y_up,LV_BTN_STATE_CHECKED_RELEASED,&_upa_alpha_98x64);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_y_up,LV_BTN_STATE_CHECKED_PRESSED,&_upa_alpha_98x64);

	//Write codes prepare_move_axis_label_6
	ui->prepare_move_axis_label_6 = lv_label_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);
	lv_label_set_text(ui->prepare_move_axis_label_6, "Z");
	lv_label_set_long_mode(ui->prepare_move_axis_label_6, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_move_axis_label_6, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_move_axis_label_6
	static lv_style_t style_prepare_move_axis_label_6_main;
	lv_style_reset(&style_prepare_move_axis_label_6_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_label_6_main
	lv_style_set_radius(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_move_axis_label_6_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_move_axis_label_6, LV_LABEL_PART_MAIN, &style_prepare_move_axis_label_6_main);
	lv_obj_set_pos(ui->prepare_move_axis_label_6, 338, 128);
	lv_obj_set_size(ui->prepare_move_axis_label_6, 20, 0);

	//Write codes prepare_move_axis_label_15
	ui->prepare_move_axis_label_15 = lv_label_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);
	lv_label_set_text(ui->prepare_move_axis_label_15, "Z");
	lv_label_set_long_mode(ui->prepare_move_axis_label_15, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_move_axis_label_15, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_move_axis_label_15
	static lv_style_t style_prepare_move_axis_label_15_main;
	lv_style_reset(&style_prepare_move_axis_label_15_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_label_15_main
	lv_style_set_radius(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_move_axis_label_15_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_move_axis_label_15, LV_LABEL_PART_MAIN, &style_prepare_move_axis_label_15_main);
	lv_obj_set_pos(ui->prepare_move_axis_label_15, 398, 470);
	lv_obj_set_size(ui->prepare_move_axis_label_15, 20, 0);

	//Write codes prepare_move_axis_label_14
	ui->prepare_move_axis_label_14 = lv_label_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);
	lv_label_set_text(ui->prepare_move_axis_label_14, "Z");
	lv_label_set_long_mode(ui->prepare_move_axis_label_14, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_move_axis_label_14, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_move_axis_label_14
	static lv_style_t style_prepare_move_axis_label_14_main;
	lv_style_reset(&style_prepare_move_axis_label_14_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_label_14_main
	lv_style_set_radius(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_move_axis_label_14_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_move_axis_label_14, LV_LABEL_PART_MAIN, &style_prepare_move_axis_label_14_main);
	lv_obj_set_pos(ui->prepare_move_axis_label_14, 398, 260);
	lv_obj_set_size(ui->prepare_move_axis_label_14, 20, 0);

	//Write codes prepare_move_axis_label_13
	ui->prepare_move_axis_label_13 = lv_label_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);
	lv_label_set_text(ui->prepare_move_axis_label_13, "Y");
	lv_label_set_long_mode(ui->prepare_move_axis_label_13, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_move_axis_label_13, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_move_axis_label_13
	static lv_style_t style_prepare_move_axis_label_13_main;
	lv_style_reset(&style_prepare_move_axis_label_13_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_label_13_main
	lv_style_set_radius(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_move_axis_label_13_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_move_axis_label_13, LV_LABEL_PART_MAIN, &style_prepare_move_axis_label_13_main);
	lv_obj_set_pos(ui->prepare_move_axis_label_13, 153, 470);
	lv_obj_set_size(ui->prepare_move_axis_label_13, 20, 0);

	//Write codes prepare_move_axis_label_12
	ui->prepare_move_axis_label_12 = lv_label_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);
	lv_label_set_text(ui->prepare_move_axis_label_12, "Y");
	lv_label_set_long_mode(ui->prepare_move_axis_label_12, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_move_axis_label_12, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_move_axis_label_12
	static lv_style_t style_prepare_move_axis_label_12_main;
	lv_style_reset(&style_prepare_move_axis_label_12_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_label_12_main
	lv_style_set_radius(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_move_axis_label_12_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_move_axis_label_12, LV_LABEL_PART_MAIN, &style_prepare_move_axis_label_12_main);
	lv_obj_set_pos(ui->prepare_move_axis_label_12, 153, 260);
	lv_obj_set_size(ui->prepare_move_axis_label_12, 20, 0);

	//Write codes prepare_move_axis_imgbtn_motor_z_home
	ui->prepare_move_axis_imgbtn_motor_z_home = lv_imgbtn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_IMGBTN_PART_MAIN for prepare_move_axis_imgbtn_motor_z_home
	static lv_style_t style_prepare_move_axis_imgbtn_motor_z_home_main;
	lv_style_reset(&style_prepare_move_axis_imgbtn_motor_z_home_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_z_home_main
	lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_z_home_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_z_home_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_z_home_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_z_home_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_imgbtn_motor_z_home, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_z_home_main);
	lv_obj_set_pos(ui->prepare_move_axis_imgbtn_motor_z_home, 386, 362);
	lv_obj_set_size(ui->prepare_move_axis_imgbtn_motor_z_home, 48, 46);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_home,LV_BTN_STATE_RELEASED,&_homea_alpha_48x46);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_home,LV_BTN_STATE_PRESSED,&_homea_alpha_48x46);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_home,LV_BTN_STATE_CHECKED_RELEASED,&_homea_alpha_48x46);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_z_home,LV_BTN_STATE_CHECKED_PRESSED,&_homea_alpha_48x46);
	lv_imgbtn_set_checkable(ui->prepare_move_axis_imgbtn_motor_z_home, true);

	//Write codes prepare_move_axis_imgbtn_motor_xy_home
	ui->prepare_move_axis_imgbtn_motor_xy_home = lv_imgbtn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_IMGBTN_PART_MAIN for prepare_move_axis_imgbtn_motor_xy_home
	static lv_style_t style_prepare_move_axis_imgbtn_motor_xy_home_main;
	lv_style_reset(&style_prepare_move_axis_imgbtn_motor_xy_home_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_xy_home_main
	lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_xy_home_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_xy_home_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_xy_home_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_xy_home_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_imgbtn_motor_xy_home, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_xy_home_main);
	lv_obj_set_pos(ui->prepare_move_axis_imgbtn_motor_xy_home, 141, 362);
	lv_obj_set_size(ui->prepare_move_axis_imgbtn_motor_xy_home, 48, 46);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_xy_home,LV_BTN_STATE_RELEASED,&_homea_alpha_48x46);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_xy_home,LV_BTN_STATE_PRESSED,&_homea_alpha_48x46);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_xy_home,LV_BTN_STATE_CHECKED_RELEASED,&_homea_alpha_48x46);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_xy_home,LV_BTN_STATE_CHECKED_PRESSED,&_homea_alpha_48x46);

	//Write codes prepare_move_axis_imgbtn_motor_loss
	ui->prepare_move_axis_imgbtn_motor_loss = lv_imgbtn_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);

	//Write style LV_IMGBTN_PART_MAIN for prepare_move_axis_imgbtn_motor_loss
	static lv_style_t style_prepare_move_axis_imgbtn_motor_loss_main;
	lv_style_reset(&style_prepare_move_axis_imgbtn_motor_loss_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_loss_main
	lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->prepare_move_axis_imgbtn_motor_loss, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_loss_main);
	lv_obj_set_pos(ui->prepare_move_axis_imgbtn_motor_loss, 14, 180);
	lv_obj_set_size(ui->prepare_move_axis_imgbtn_motor_loss, 128, 62);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_loss,LV_BTN_STATE_RELEASED,&_motorstart_alpha_128x62);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_loss,LV_BTN_STATE_PRESSED,&_motorstart_alpha_128x62);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_loss,LV_BTN_STATE_CHECKED_RELEASED,&_motorstop_alpha_128x62);
	lv_imgbtn_set_src(ui->prepare_move_axis_imgbtn_motor_loss,LV_BTN_STATE_CHECKED_PRESSED,&_motorstop_alpha_128x62);

	//Write codes prepare_move_axis_label_5
	ui->prepare_move_axis_label_5 = lv_label_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);
	lv_label_set_text(ui->prepare_move_axis_label_5, "Y");
	lv_label_set_long_mode(ui->prepare_move_axis_label_5, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_move_axis_label_5, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_move_axis_label_5
	static lv_style_t style_prepare_move_axis_label_5_main;
	lv_style_reset(&style_prepare_move_axis_label_5_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_label_5_main
	lv_style_set_radius(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_move_axis_label_5_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_move_axis_label_5, LV_LABEL_PART_MAIN, &style_prepare_move_axis_label_5_main);
	lv_obj_set_pos(ui->prepare_move_axis_label_5, 178, 128);
	lv_obj_set_size(ui->prepare_move_axis_label_5, 20, 0);

	//Write codes prepare_move_axis_label_11
	ui->prepare_move_axis_label_11 = lv_label_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);
	lv_label_set_text(ui->prepare_move_axis_label_11, "X");
	lv_label_set_long_mode(ui->prepare_move_axis_label_11, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_move_axis_label_11, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_move_axis_label_11
	static lv_style_t style_prepare_move_axis_label_11_main;
	lv_style_reset(&style_prepare_move_axis_label_11_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_label_11_main
	lv_style_set_radius(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_move_axis_label_11_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_move_axis_label_11, LV_LABEL_PART_MAIN, &style_prepare_move_axis_label_11_main);
	lv_obj_set_pos(ui->prepare_move_axis_label_11, 264, 370);
	lv_obj_set_size(ui->prepare_move_axis_label_11, 20, 0);

	//Write codes prepare_move_axis_label_10
	ui->prepare_move_axis_label_10 = lv_label_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);
	lv_label_set_text(ui->prepare_move_axis_label_10, "X");
	lv_label_set_long_mode(ui->prepare_move_axis_label_10, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_move_axis_label_10, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_move_axis_label_10
	static lv_style_t style_prepare_move_axis_label_10_main;
	lv_style_reset(&style_prepare_move_axis_label_10_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_label_10_main
	lv_style_set_radius(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_move_axis_label_10_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_move_axis_label_10, LV_LABEL_PART_MAIN, &style_prepare_move_axis_label_10_main);
	lv_obj_set_pos(ui->prepare_move_axis_label_10, 46, 370);
	lv_obj_set_size(ui->prepare_move_axis_label_10, 20, 0);

	//Write codes prepare_move_axis_label_4
	ui->prepare_move_axis_label_4 = lv_label_create(ui->prepare_move_axis_cont_prepare_move_axis, NULL);
	lv_label_set_text(ui->prepare_move_axis_label_4, "X");
	lv_label_set_long_mode(ui->prepare_move_axis_label_4, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->prepare_move_axis_label_4, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for prepare_move_axis_label_4
	static lv_style_t style_prepare_move_axis_label_4_main;
	lv_style_reset(&style_prepare_move_axis_label_4_main);

	//Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_label_4_main
	lv_style_set_radius(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_prepare_move_axis_label_4_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->prepare_move_axis_label_4, LV_LABEL_PART_MAIN, &style_prepare_move_axis_label_4_main);
	lv_obj_set_pos(ui->prepare_move_axis_label_4, 18, 128);
	lv_obj_set_size(ui->prepare_move_axis_label_4, 20, 0);
	lv_cont_set_layout(ui->prepare_move_axis_cont_prepare_move_axis, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->prepare_move_axis_cont_prepare_move_axis, LV_FIT_NONE);

	//Init events for screen
	events_init_prepare_move_axis(ui);
}
