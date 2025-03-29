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
#include "../custom/mystyle.h"
#include "../custom/clanguage.h"


void setup_scr_inputboard_wifi(lv_ui *ui){

	//Write codes inputboard_wifi_cont_1
	ui->inputboard_wifi_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->inputboard_wifi_cont_1, 0, 0);
	lv_obj_set_size(ui->inputboard_wifi_cont_1, 480, 800);

	//Write style state: LV_STATE_DEFAULT for style_inputboard_wifi_cont_1_main_main_default
	static lv_style_t style_inputboard_wifi_cont_1_main_main_default;
	if (style_inputboard_wifi_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_inputboard_wifi_cont_1_main_main_default);
	else
		lv_style_init(&style_inputboard_wifi_cont_1_main_main_default);
	lv_style_set_radius(&style_inputboard_wifi_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_inputboard_wifi_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_inputboard_wifi_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_inputboard_wifi_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_inputboard_wifi_cont_1_main_main_default, 150);
	lv_style_set_border_color(&style_inputboard_wifi_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_inputboard_wifi_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_inputboard_wifi_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_inputboard_wifi_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_inputboard_wifi_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_inputboard_wifi_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_inputboard_wifi_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->inputboard_wifi_cont_1, &style_inputboard_wifi_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes inputboard_wifi_img_1
	ui->inputboard_wifi_img_1 = lv_img_create(ui->inputboard_wifi_cont_1);
	lv_obj_set_pos(ui->inputboard_wifi_img_1, 21, 17);
	lv_obj_set_size(ui->inputboard_wifi_img_1, 36, 24);

	//Write style state: LV_STATE_DEFAULT for style_inputboard_wifi_img_1_main_main_default
	static lv_style_t style_inputboard_wifi_img_1_main_main_default;
	if (style_inputboard_wifi_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_inputboard_wifi_img_1_main_main_default);
	else
		lv_style_init(&style_inputboard_wifi_img_1_main_main_default);
	lv_style_set_img_recolor(&style_inputboard_wifi_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_inputboard_wifi_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_inputboard_wifi_img_1_main_main_default, 255);
	lv_obj_add_style(ui->inputboard_wifi_img_1, &style_inputboard_wifi_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->inputboard_wifi_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->inputboard_wifi_img_1,&_back_36x24);
	lv_img_set_pivot(ui->inputboard_wifi_img_1, 0,0);
	lv_img_set_angle(ui->inputboard_wifi_img_1, 0);

	//Write codes inputboard_wifi_btn_1
	ui->inputboard_wifi_btn_1 = lv_btn_create(ui->inputboard_wifi_cont_1);
	lv_obj_set_pos(ui->inputboard_wifi_btn_1, 0, 0);
	lv_obj_set_size(ui->inputboard_wifi_btn_1, 85, 50);

	//Write style state: LV_STATE_DEFAULT for style_inputboard_wifi_btn_1_main_main_default
	static lv_style_t style_inputboard_wifi_btn_1_main_main_default;
	if (style_inputboard_wifi_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_inputboard_wifi_btn_1_main_main_default);
	else
		lv_style_init(&style_inputboard_wifi_btn_1_main_main_default);
	lv_style_set_radius(&style_inputboard_wifi_btn_1_main_main_default, 0);
	lv_style_set_bg_color(&style_inputboard_wifi_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_inputboard_wifi_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_inputboard_wifi_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_inputboard_wifi_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_inputboard_wifi_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_inputboard_wifi_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_inputboard_wifi_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_inputboard_wifi_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_inputboard_wifi_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->inputboard_wifi_btn_1, &style_inputboard_wifi_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->inputboard_wifi_btn_1_label = lv_label_create(ui->inputboard_wifi_btn_1);
	lv_label_set_text(ui->inputboard_wifi_btn_1_label, "");
	lv_obj_set_style_text_color(ui->inputboard_wifi_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->inputboard_wifi_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->inputboard_wifi_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes inputboard_wifi_label_1
	ui->inputboard_wifi_label_1 = lv_label_create(ui->inputboard_wifi_cont_1);
	lv_obj_set_pos(ui->inputboard_wifi_label_1, 90, 11);
	lv_obj_set_size(ui->inputboard_wifi_label_1, 300, 32);
	lv_label_set_text(ui->inputboard_wifi_label_1, "其他网络");
	lv_label_set_long_mode(ui->inputboard_wifi_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->inputboard_wifi_label_1, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_inputboard_wifi_label_1_main_main_default
	static lv_style_t style_inputboard_wifi_label_1_main_main_default;
	if (style_inputboard_wifi_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_inputboard_wifi_label_1_main_main_default);
	else
		lv_style_init(&style_inputboard_wifi_label_1_main_main_default);
	lv_style_set_radius(&style_inputboard_wifi_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_inputboard_wifi_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_inputboard_wifi_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_inputboard_wifi_label_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_inputboard_wifi_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_inputboard_wifi_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_inputboard_wifi_label_1_main_main_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_inputboard_wifi_label_1_main_main_default, 2);
	lv_style_set_pad_left(&style_inputboard_wifi_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_inputboard_wifi_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_inputboard_wifi_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_inputboard_wifi_label_1_main_main_default, 0);
	lv_obj_add_style(ui->inputboard_wifi_label_1, &style_inputboard_wifi_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes inputboard_wifi_label_2
	ui->inputboard_wifi_label_2 = lv_label_create(ui->inputboard_wifi_cont_1);
	lv_obj_set_pos(ui->inputboard_wifi_label_2, 1, 123);
	lv_obj_set_size(ui->inputboard_wifi_label_2, 139, 24);
	lv_label_set_text(ui->inputboard_wifi_label_2, "WIFI名称");
	lv_label_set_long_mode(ui->inputboard_wifi_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->inputboard_wifi_label_2, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_inputboard_wifi_label_2_main_main_default
	static lv_style_t style_inputboard_wifi_label_2_main_main_default;
	if (style_inputboard_wifi_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_inputboard_wifi_label_2_main_main_default);
	else
		lv_style_init(&style_inputboard_wifi_label_2_main_main_default);
	lv_style_set_radius(&style_inputboard_wifi_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_inputboard_wifi_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_inputboard_wifi_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_inputboard_wifi_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_inputboard_wifi_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_inputboard_wifi_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_inputboard_wifi_label_2_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_inputboard_wifi_label_2_main_main_default, 2);
	lv_style_set_pad_left(&style_inputboard_wifi_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_inputboard_wifi_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_inputboard_wifi_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_inputboard_wifi_label_2_main_main_default, 0);
	lv_obj_add_style(ui->inputboard_wifi_label_2, &style_inputboard_wifi_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    /*Create a text area. The keyboard will write here*/
    ui->wifi_seting_ta= lv_textarea_create(ui->inputboard_wifi_cont_1);
    lv_obj_set_size(ui->wifi_seting_ta, 480, 76);
    lv_obj_align(ui->wifi_seting_ta,LV_ALIGN_CENTER,0,-50);
    lv_textarea_set_password_mode(ui->wifi_seting_ta,true);
    lv_textarea_set_max_length(ui->wifi_seting_ta,63);
    lv_textarea_set_one_line(ui->wifi_seting_ta, true);
    lv_textarea_set_placeholder_text(ui->wifi_seting_ta, input_wifi_password[1]);

    static lv_style_t style_ta_default;
	if (style_ta_default.prop_cnt > 1)
		lv_style_reset(&style_ta_default);
	else
		lv_style_init(&style_ta_default);
	lv_style_set_radius(&style_ta_default, 3);
	lv_style_set_bg_color(&style_ta_default, lv_color_make(0x3e, 0x3e, 0x3e));
	lv_style_set_bg_grad_color(&style_ta_default, lv_color_make(0x3e, 0x3e, 0x3e));
	lv_style_set_bg_grad_dir(&style_ta_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_ta_default, 255);
	lv_style_set_border_width(&style_ta_default, 0);
	lv_style_set_text_color(&style_ta_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_ta_default, &lv_font_simsun_28);
    lv_obj_add_style(ui->wifi_seting_ta, &style_ta_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->wifi_seting_ta, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_seting_ta, &lv_font_simsun_28, LV_STATE_DEFAULT);

    ui->wifi_seting_pwd_hidden_img = lv_img_create(ui->inputboard_wifi_cont_1);
	lv_obj_set_size(ui->wifi_seting_pwd_hidden_img, 40, 40);
	lv_obj_align_to(ui->wifi_seting_pwd_hidden_img, ui->wifi_seting_ta,LV_ALIGN_RIGHT_MID, 0, 0);

	//Write style state: LV_STATE_DEFAULT for style_wifi_select_pwd_hidden_img_main_default
	static lv_style_t style_wifi_select_pwd_hidden_img_main_default;
	if (style_wifi_select_pwd_hidden_img_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_select_pwd_hidden_img_main_default);
	else
		lv_style_init(&style_wifi_select_pwd_hidden_img_main_default);
	lv_style_set_img_recolor(&style_wifi_select_pwd_hidden_img_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_wifi_select_pwd_hidden_img_main_default, 0);
	lv_style_set_img_opa(&style_wifi_select_pwd_hidden_img_main_default, 255);
	lv_obj_add_style(ui->wifi_seting_pwd_hidden_img, &style_wifi_select_pwd_hidden_img_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->wifi_seting_pwd_hidden_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->wifi_seting_pwd_hidden_img, &_pwm_img1_40x40);
	lv_img_set_pivot(ui->wifi_seting_pwd_hidden_img, 0,0);
	lv_img_set_angle(ui->wifi_seting_pwd_hidden_img, 0);

	/*Create a keyboard to use it with an of the text areas*/
    ui->wifi_seting_kb = lv_keyboard_create(ui->inputboard_wifi_cont_1);
	lv_obj_set_size(ui->wifi_seting_kb, 480, 372);
	lv_obj_align(ui->wifi_seting_kb,LV_ALIGN_BOTTOM_MID, 0, 20);

    static lv_style_t style_kb_items_default;
	if (style_kb_items_default.prop_cnt > 1)
		lv_style_reset(&style_kb_items_default);
	else
		lv_style_init(&style_kb_items_default);
	lv_style_set_radius(&style_kb_items_default, 5);
	lv_style_set_bg_color(&style_kb_items_default, lv_color_make(0xa6, 0xa6, 0xa6));
	lv_style_set_bg_grad_color(&style_kb_items_default, lv_color_make(0xa3, 0x9e, 0x9e));
	lv_style_set_bg_grad_dir(&style_kb_items_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_kb_items_default, 255);
	lv_style_set_border_color(&style_kb_items_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_kb_items_default, 1);
	lv_style_set_text_color(&style_kb_items_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_kb_items_default, &lv_font_simsun_28);
    lv_obj_add_style(ui->wifi_seting_kb, &style_kb_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->wifi_seting_kb, &style_kb_items_default, LV_PART_ITEMS|LV_STATE_CHECKED);
    lv_obj_align_to(ui->wifi_seting_kb, ui->wifi_seting_ta, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

    lv_style_t style_kb_default;
	lv_style_init(&style_kb_default);
	lv_style_reset(&style_kb_default);
	lv_style_set_radius(&style_kb_default, 0);
	lv_style_set_bg_color(&style_kb_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_kb_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_kb_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_kb_default, 0);
	lv_style_set_shadow_color(&style_kb_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_shadow_opa(&style_kb_default, 0);
	lv_style_set_border_color(&style_kb_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_kb_default, 0);
//    lv_obj_add_style(ui->wifi_seting_kb, &style_kb_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    lv_keyboard_set_textarea(ui->wifi_seting_kb, ui->wifi_seting_ta);


	//Init events for screen
	events_init_inputboard_wifi(ui);
}
