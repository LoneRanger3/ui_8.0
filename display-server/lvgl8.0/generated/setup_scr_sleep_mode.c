/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "../custom/custom.h"


void setup_scr_sleep_mode(lv_ui *ui){

	//Write codes sleep_mode_cont_1
	ui->sleep_mode_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->sleep_mode_cont_1, 0, 0);
	lv_obj_set_size(ui->sleep_mode_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_sleep_mode_cont_1_main_main_default
	static lv_style_t style_sleep_mode_cont_1_main_main_default;
	if (style_sleep_mode_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sleep_mode_cont_1_main_main_default);
	else
		lv_style_init(&style_sleep_mode_cont_1_main_main_default);
	lv_style_set_radius(&style_sleep_mode_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sleep_mode_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_sleep_mode_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_sleep_mode_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_sleep_mode_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_sleep_mode_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sleep_mode_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_sleep_mode_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_sleep_mode_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sleep_mode_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sleep_mode_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sleep_mode_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->sleep_mode_cont_1, &style_sleep_mode_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Init events for screen
	events_init_sleep_mode(ui);
}
