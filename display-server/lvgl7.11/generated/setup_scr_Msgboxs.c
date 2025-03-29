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

void setup_scr_Msgboxs(lv_ui *ui){

	//Write codes Msgboxs
//	ui->Msgboxs = lv_obj_create(NULL, NULL);

	//Write codes Msgboxs_cont_msgboxs
	ui->Msgboxs_cont_msgboxs = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for Msgboxs_cont_msgboxs
	static lv_style_t style_Msgboxs_cont_msgboxs_main;
	lv_style_reset(&style_Msgboxs_cont_msgboxs_main);

	//Write style state: LV_STATE_DEFAULT for style_Msgboxs_cont_msgboxs_main
	lv_style_set_radius(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_color(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	//lv_style_set_bg_grad_dir(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	lv_style_set_border_width(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_pad_left(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Msgboxs_cont_msgboxs_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Msgboxs_cont_msgboxs, LV_CONT_PART_MAIN, &style_Msgboxs_cont_msgboxs_main);
	lv_obj_set_pos(ui->Msgboxs_cont_msgboxs, 22, 216);
	lv_obj_set_size(ui->Msgboxs_cont_msgboxs, 436, 336);
	lv_obj_set_click(ui->Msgboxs_cont_msgboxs, false);

	//Write codes Msgboxs_label_msgbox_secondline
	ui->Msgboxs_label_msgbox_secondline = lv_label_create(ui->Msgboxs_cont_msgboxs, NULL);
	lv_label_set_long_mode(ui->Msgboxs_label_msgbox_secondline, LV_LABEL_LONG_SROLL_CIRC);
	lv_label_set_text(ui->Msgboxs_label_msgbox_secondline, "提示信息第二行");
//	lv_label_set_long_mode(ui->Msgboxs_label_msgbox_secondline, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Msgboxs_label_msgbox_secondline, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Msgboxs_label_msgbox_secondline
	static lv_style_t style_Msgboxs_label_msgbox_secondline_main;
	lv_style_reset(&style_Msgboxs_label_msgbox_secondline_main);

	//Write style state: LV_STATE_DEFAULT for style_Msgboxs_label_msgbox_secondline_main
	lv_style_set_radius(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Msgboxs_label_msgbox_secondline_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Msgboxs_label_msgbox_secondline, LV_LABEL_PART_MAIN, &style_Msgboxs_label_msgbox_secondline_main);
	lv_obj_set_pos(ui->Msgboxs_label_msgbox_secondline, 8, 122);
	lv_obj_set_size(ui->Msgboxs_label_msgbox_secondline, 420, 42);

	//Write codes Msgboxs_label_title
	ui->Msgboxs_label_title = lv_label_create(ui->Msgboxs_cont_msgboxs, NULL);
	lv_label_set_text(ui->Msgboxs_label_title, "打印文件");
	lv_label_set_long_mode(ui->Msgboxs_label_title, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->Msgboxs_label_title, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for Msgboxs_label_title
	static lv_style_t style_Msgboxs_label_title_main;
	lv_style_reset(&style_Msgboxs_label_title_main);

	//Write style state: LV_STATE_DEFAULT for style_Msgboxs_label_title_main
	lv_style_set_radius(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_color(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_bg_grad_dir(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_style_set_text_font(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_style_set_text_font(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_style_set_text_letter_space(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, 2);
//	lv_style_set_pad_left(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_right(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_top(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_pad_bottom(&style_Msgboxs_label_title_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->Msgboxs_label_title, LV_LABEL_PART_MAIN, &style_Msgboxs_label_title_main);
	lv_obj_set_pos(ui->Msgboxs_label_title, 8, 43);
	lv_obj_set_size(ui->Msgboxs_label_title, 420, 0);

	//Write codes Msgboxs_btn_confirm
	ui->Msgboxs_btn_confirm = lv_btn_create(ui->Msgboxs_cont_msgboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Msgboxs_btn_confirm
	static lv_style_t style_Msgboxs_btn_confirm_main;
	lv_style_reset(&style_Msgboxs_btn_confirm_main);

	//Write style state: LV_STATE_DEFAULT for style_Msgboxs_btn_confirm_main
	lv_style_set_radius(&style_Msgboxs_btn_confirm_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Msgboxs_btn_confirm_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Msgboxs_btn_confirm_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Msgboxs_btn_confirm_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Msgboxs_btn_confirm_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Msgboxs_btn_confirm_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Msgboxs_btn_confirm_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Msgboxs_btn_confirm_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Msgboxs_btn_confirm_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Msgboxs_btn_confirm_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Msgboxs_btn_confirm, LV_BTN_PART_MAIN, &style_Msgboxs_btn_confirm_main);
	lv_obj_set_pos(ui->Msgboxs_btn_confirm, 3, 241);
	lv_obj_set_size(ui->Msgboxs_btn_confirm, 211, 92);
	ui->Msgboxs_btn_confirm_label = lv_label_create(ui->Msgboxs_btn_confirm, NULL);
	lv_label_set_text(ui->Msgboxs_btn_confirm_label, confirm[cur_language]);
	lv_obj_set_style_local_text_color(ui->Msgboxs_btn_confirm_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_obj_set_style_local_text_font(ui->Msgboxs_btn_confirm_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_obj_set_style_local_text_font(ui->Msgboxs_btn_confirm_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }

	//Write codes Msgboxs_btn_cancel
	ui->Msgboxs_btn_cancel = lv_btn_create(ui->Msgboxs_cont_msgboxs, NULL);

	//Write style LV_BTN_PART_MAIN for Msgboxs_btn_cancel
	static lv_style_t style_Msgboxs_btn_cancel_main;
	lv_style_reset(&style_Msgboxs_btn_cancel_main);

	//Write style state: LV_STATE_DEFAULT for style_Msgboxs_btn_cancel_main
	lv_style_set_radius(&style_Msgboxs_btn_cancel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_Msgboxs_btn_cancel_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_color(&style_Msgboxs_btn_cancel_main, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
	//lv_style_set_bg_grad_dir(&style_Msgboxs_btn_cancel_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_Msgboxs_btn_cancel_main, LV_STATE_DEFAULT, 255);
//	lv_style_set_border_color(&style_Msgboxs_btn_cancel_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_border_width(&style_Msgboxs_btn_cancel_main, LV_STATE_DEFAULT, 0);
//	lv_style_set_border_opa(&style_Msgboxs_btn_cancel_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_Msgboxs_btn_cancel_main, LV_STATE_DEFAULT, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_outline_opa(&style_Msgboxs_btn_cancel_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->Msgboxs_btn_cancel, LV_BTN_PART_MAIN, &style_Msgboxs_btn_cancel_main);
	lv_obj_set_pos(ui->Msgboxs_btn_cancel, 222, 241);
	lv_obj_set_size(ui->Msgboxs_btn_cancel, 211, 92);
	ui->Msgboxs_btn_cancel_label = lv_label_create(ui->Msgboxs_btn_cancel, NULL);
	lv_label_set_text(ui->Msgboxs_btn_cancel_label, cancel[cur_language]);
	lv_obj_set_style_local_text_color(ui->Msgboxs_btn_cancel_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	if(cur_language > 0)
    {
        lv_obj_set_style_local_text_font(ui->Msgboxs_btn_cancel_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_18);
    }
    else
    {
        lv_obj_set_style_local_text_font(ui->Msgboxs_btn_cancel_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_28);
    }
	lv_cont_set_layout(ui->Msgboxs_cont_msgboxs, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->Msgboxs_cont_msgboxs, LV_FIT_NONE);
}
