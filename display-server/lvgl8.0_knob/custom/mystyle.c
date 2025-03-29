/*
 * mystyle.c
 *
 *  Created on: April 11, 2022
 *      Author: liuxinchao
 */

#include "mystyle.h"
#include "Base/DisplayMsgBase.h"

lv_style_t style_cont_default;
lv_style_t style_cont_msgbox;
lv_style_t style_img_pressed;
lv_style_t style_img_default;
lv_style_t style_white24_text_creality;

lv_style_t style_main_menu_btn_default;
lv_style_t style_main_menu_btn_disable;
lv_style_t style_background_btn_default;
lv_style_t style_background2_btn_default;
lv_style_t style_background3_btn_default;
lv_style_t style_normal_btn_default;
lv_style_t style_normal_btn_pressed;
lv_style_t style_fillet_btn_default;
lv_style_t style_fillet_btn_pressed;
lv_style_t style_btn_as_text_default;
lv_style_t style_hidden_btn_default;
lv_style_t style_unit_btn_default;
lv_style_t style_unit_btn_pressed;

lv_style_t style_white32_text_default;
lv_style_t style_color32_text_default;
lv_style_t style_white24_text_default;
lv_style_t style_white28_text_default;
lv_style_t style_black24_text_default;
lv_style_t style_color28_text_default;
lv_style_t style_grey24_text_default;

lv_style_t style_bar_progress_default;
lv_style_t style_bar_progress_indicator_default;
lv_style_t style_cb_default;
lv_style_t style_cb_indicator_default;

/*************************已确定的样式****************************************************/
lv_style_t btnstyle_check_default;
lv_style_t btnstyle_uncheck_default;
lv_style_t labelstyle_check_default;
lv_style_t labelstyle_uncheck_default;
lv_style_t labelstyle_opa_default;

/*************************字体文件******************************/

lv_ft_info_t lv_font14;
lv_ft_info_t lv_font18;
lv_ft_info_t lv_font22;
lv_ft_info_t lv_font24;
lv_ft_info_t lv_font25;
lv_ft_info_t lv_font26;
lv_ft_info_t lv_font28;
lv_ft_info_t lv_font30;
lv_ft_info_t lv_font32;
/*************************字体文件******************************/

void mystyle_init()
{
    lv_style_init(&style_cont_default);
	lv_style_reset(&style_cont_default);
	lv_style_set_radius(&style_cont_default, 0);
	lv_style_set_bg_color(&style_cont_default, lv_color_make(0x29, 0x29, 0x2C));
	lv_style_set_bg_grad_color(&style_cont_default, lv_color_make(0x29, 0x29, 0x2C));
	lv_style_set_bg_grad_dir(&style_cont_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cont_default, 255);
	lv_style_set_border_color(&style_cont_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_cont_default, 0);
	lv_style_set_border_opa(&style_cont_default, 255);
	lv_style_set_pad_left(&style_cont_default, 0);
	lv_style_set_pad_right(&style_cont_default, 0);
	lv_style_set_pad_top(&style_cont_default, 0);
	lv_style_set_pad_bottom(&style_cont_default, 0);

    lv_style_init(&style_cont_msgbox);
	lv_style_reset(&style_cont_msgbox);
	lv_style_set_radius(&style_cont_msgbox,6);
	lv_style_set_bg_color(&style_cont_msgbox, lv_color_make(0x05, 0x05, 0x05));
	lv_style_set_bg_grad_color(&style_cont_msgbox, lv_color_make(0x05, 0x05, 0x05));
	lv_style_set_bg_grad_dir(&style_cont_msgbox, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cont_msgbox, 150);
	lv_style_set_border_color(&style_cont_msgbox, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_cont_msgbox, 0);
	lv_style_set_border_opa(&style_cont_msgbox, 255);
	lv_style_set_pad_left(&style_cont_msgbox, 0);
	lv_style_set_pad_right(&style_cont_msgbox, 0);
	lv_style_set_pad_top(&style_cont_msgbox, 0);
	lv_style_set_pad_bottom(&style_cont_msgbox, 0);

	lv_style_init(&style_img_default);
    lv_style_reset(&style_img_default);
    lv_style_set_img_recolor(&style_img_default, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_img_recolor_opa(&style_img_default, 0);
    lv_style_set_img_opa(&style_img_default, 255);

	lv_style_init(&style_img_pressed);
    lv_style_reset(&style_img_pressed);
    lv_style_set_img_recolor(&style_img_pressed, lv_color_make(0x42, 0xbd, 0xd8));
    lv_style_set_img_recolor_opa(&style_img_pressed, 0);
    lv_style_set_img_opa(&style_img_pressed, 130);

    lv_style_init(&style_main_menu_btn_default);
	lv_style_reset(&style_main_menu_btn_default);
	lv_style_set_radius(&style_main_menu_btn_default, 10);
	lv_style_set_bg_color(&style_main_menu_btn_default, lv_color_make(0x16, 0x16, 0x16));
	lv_style_set_bg_grad_color(&style_main_menu_btn_default, lv_color_make(0x16, 0x16, 0x16));
	lv_style_set_bg_grad_dir(&style_main_menu_btn_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_main_menu_btn_default, 255);
	lv_style_set_shadow_color(&style_main_menu_btn_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_shadow_opa(&style_main_menu_btn_default, 255);
	lv_style_set_border_color(&style_main_menu_btn_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_main_menu_btn_default, 0);
	lv_style_set_border_opa(&style_main_menu_btn_default, 255);

	lv_style_init(&style_main_menu_btn_disable);
	lv_style_reset(&style_main_menu_btn_disable);
	lv_style_set_radius(&style_main_menu_btn_disable, 10);
	lv_style_set_bg_color(&style_main_menu_btn_disable, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_main_menu_btn_disable, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_main_menu_btn_disable, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_main_menu_btn_disable, 255);
	lv_style_set_shadow_color(&style_main_menu_btn_disable, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_shadow_opa(&style_main_menu_btn_disable, 255);
	lv_style_set_border_color(&style_main_menu_btn_disable, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&style_main_menu_btn_disable, 0);
	lv_style_set_border_opa(&style_main_menu_btn_disable, 255);

	lv_style_init(&style_background_btn_default);
	if (style_background_btn_default.prop_cnt > 1)
		lv_style_reset(&style_background_btn_default);
	else
		lv_style_init(&style_background_btn_default);
	lv_style_set_radius(&style_background_btn_default, 0);
	lv_style_set_bg_color(&style_background_btn_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_color(&style_background_btn_default, lv_color_make(0x3c, 0x3e, 0x42));
	lv_style_set_bg_grad_dir(&style_background_btn_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_background_btn_default, 255);
	lv_style_set_border_color(&style_background_btn_default, lv_color_make(0x16, 0x16, 0x16));
	lv_style_set_border_width(&style_background_btn_default, 0);
    lv_style_set_text_color(&style_background_btn_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_background_btn_default, &lv_font_simsun_24);

	lv_style_init(&style_background2_btn_default);
	lv_style_reset(&style_background2_btn_default);
	lv_style_set_radius(&style_background2_btn_default, 20);
	lv_style_set_bg_color(&style_background2_btn_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_background2_btn_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_background2_btn_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_background2_btn_default, 255);
	lv_style_set_shadow_color(&style_background2_btn_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_shadow_opa(&style_background2_btn_default, 0);
	lv_style_set_border_color(&style_background2_btn_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_background2_btn_default, 0);
	lv_style_set_text_color(&style_background2_btn_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_background2_btn_default, &lv_font_simsun_28);
//	lv_style_set_border_opa(&style_background2_btn_default, 255);

	lv_style_init(&style_background3_btn_default);
	lv_style_reset(&style_background3_btn_default);
	lv_style_set_radius(&style_background3_btn_default, 34);
	lv_style_set_bg_color(&style_background3_btn_default, lv_color_make(0x16, 0x16, 0x16));
	lv_style_set_bg_grad_color(&style_background3_btn_default, lv_color_make(0x16, 0x16, 0x16));
	lv_style_set_bg_grad_dir(&style_background3_btn_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_background3_btn_default, 255);
	lv_style_set_shadow_color(&style_background3_btn_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_background3_btn_default, 0);
	lv_style_set_border_color(&style_background3_btn_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_background3_btn_default, 2);
	lv_style_set_border_opa(&style_background3_btn_default, 255);

	lv_style_init(&style_normal_btn_default);
	lv_style_reset(&style_normal_btn_default);
	lv_style_set_radius(&style_normal_btn_default, 10);
	lv_style_set_bg_color(&style_normal_btn_default, lv_color_make(0x4c, 0x50, 0x57));
	lv_style_set_bg_grad_color(&style_normal_btn_default, lv_color_make(0x4c, 0x50, 0x57));
	lv_style_set_bg_grad_dir(&style_normal_btn_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_normal_btn_default, 255);
	lv_style_set_shadow_color(&style_normal_btn_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_shadow_opa(&style_normal_btn_default, 0);
	lv_style_set_border_color(&style_normal_btn_default, lv_color_make(0x16, 0x16, 0x16));
	lv_style_set_border_width(&style_normal_btn_default, 0);
	lv_style_set_border_opa(&style_normal_btn_default, 255);

	lv_style_init(&style_normal_btn_pressed);
    lv_style_reset(&style_normal_btn_pressed);
	lv_style_set_radius(&style_normal_btn_pressed, 10);
	lv_style_set_bg_color(&style_normal_btn_pressed, lv_color_make(0x4f, 0x4f, 0x4f));
	lv_style_set_bg_grad_color(&style_normal_btn_pressed, lv_color_make(0x4f, 0x4f, 0x4f));
	lv_style_set_bg_grad_dir(&style_normal_btn_pressed, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_normal_btn_pressed, 255);
	lv_style_set_shadow_color(&style_normal_btn_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_normal_btn_pressed, 0);
	lv_style_set_border_color(&style_normal_btn_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_normal_btn_pressed, 0);
	lv_style_set_border_opa(&style_normal_btn_pressed, 255);

	lv_style_init(&style_fillet_btn_default);
	lv_style_reset(&style_fillet_btn_default);
	lv_style_set_radius(&style_fillet_btn_default, 40);
	lv_style_set_bg_color(&style_fillet_btn_default, lv_color_make(0x16, 0x16, 0x16));
	lv_style_set_bg_grad_color(&style_fillet_btn_default, lv_color_make(0x16, 0x1f, 0x3e));
	lv_style_set_bg_grad_dir(&style_fillet_btn_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_fillet_btn_default, 255);
	lv_style_set_shadow_color(&style_fillet_btn_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_shadow_opa(&style_fillet_btn_default, 255);
	lv_style_set_border_color(&style_fillet_btn_default, lv_color_make(0x16, 0x16, 0x16));
	lv_style_set_border_width(&style_fillet_btn_default, 0);
	lv_style_set_border_opa(&style_fillet_btn_default, 255);

	lv_style_init(&style_fillet_btn_pressed);
	lv_style_reset(&style_fillet_btn_pressed);
	lv_style_set_radius(&style_fillet_btn_pressed, 40);
	lv_style_set_bg_color(&style_fillet_btn_pressed, lv_color_make(0x4f, 0x4f, 0x4f));
	lv_style_set_bg_grad_color(&style_fillet_btn_pressed, lv_color_make(0x4f, 0x4f, 0x4f));
	lv_style_set_bg_grad_dir(&style_fillet_btn_pressed, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_fillet_btn_pressed, 255);
	lv_style_set_shadow_color(&style_fillet_btn_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_fillet_btn_pressed, 0);
	lv_style_set_border_color(&style_fillet_btn_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_fillet_btn_pressed, 0);
	lv_style_set_border_opa(&style_fillet_btn_pressed, 255);

	lv_style_init(&style_btn_as_text_default);
	lv_style_reset(&style_btn_as_text_default);
	lv_style_set_radius(&style_btn_as_text_default, 5);
	lv_style_set_bg_color(&style_btn_as_text_default, lv_color_make(0x3e, 0x3e, 0x3e));
	lv_style_set_bg_grad_color(&style_btn_as_text_default, lv_color_make(0x3e, 0x3e, 0x3e));
	lv_style_set_bg_grad_dir(&style_btn_as_text_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_btn_as_text_default, 255);
	lv_style_set_shadow_color(&style_btn_as_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_btn_as_text_default, 0);
	lv_style_set_border_color(&style_btn_as_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_btn_as_text_default, 0);
	lv_style_set_border_opa(&style_btn_as_text_default, 255);

	lv_style_init(&style_hidden_btn_default);
	lv_style_reset(&style_hidden_btn_default);
	lv_style_set_radius(&style_hidden_btn_default, 5);
	lv_style_set_bg_color(&style_hidden_btn_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_hidden_btn_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_hidden_btn_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_hidden_btn_default, 0);
	lv_style_set_shadow_color(&style_hidden_btn_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_hidden_btn_default, 0);
	lv_style_set_border_color(&style_hidden_btn_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_hidden_btn_default, 0);
	lv_style_set_border_opa(&style_hidden_btn_default, 3);

	lv_style_init(&style_unit_btn_default);
	lv_style_reset(&style_unit_btn_default);
	lv_style_set_radius(&style_unit_btn_default, 34);
	lv_style_set_bg_color(&style_unit_btn_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_unit_btn_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_unit_btn_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_unit_btn_default, 255);
	lv_style_set_shadow_color(&style_unit_btn_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_unit_btn_default, 0);
	lv_style_set_border_color(&style_unit_btn_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_unit_btn_default, 0);
	lv_style_set_border_opa(&style_unit_btn_default, 255);

	lv_style_init(&style_unit_btn_pressed);
	lv_style_reset(&style_unit_btn_pressed);
	lv_style_set_radius(&style_unit_btn_pressed, 34);
	lv_style_set_bg_color(&style_unit_btn_pressed, lv_color_make(0x16, 0x16, 0x16));
	lv_style_set_bg_grad_color(&style_unit_btn_pressed, lv_color_make(0x16, 0x16, 0x16));
	lv_style_set_bg_grad_dir(&style_unit_btn_pressed, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_unit_btn_pressed, 255);
	lv_style_set_shadow_color(&style_unit_btn_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_unit_btn_pressed, 0);
	lv_style_set_border_color(&style_unit_btn_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_unit_btn_pressed, 0);
	lv_style_set_border_opa(&style_unit_btn_pressed, 255);

	lv_style_init(&style_white32_text_default);
	lv_style_reset(&style_white32_text_default);
	lv_style_set_radius(&style_white32_text_default, 0);
	lv_style_set_bg_color(&style_white32_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_white32_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_white32_text_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_white32_text_default, 0);
	lv_style_set_text_color(&style_white32_text_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_white32_text_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_white32_text_default, 2);
	lv_style_set_pad_left(&style_white32_text_default, 0);
	lv_style_set_pad_right(&style_white32_text_default, 0);
	lv_style_set_pad_top(&style_white32_text_default, 0);
	lv_style_set_pad_bottom(&style_white32_text_default, 0);

	lv_style_init(&style_color32_text_default);
	lv_style_reset(&style_color32_text_default);
	lv_style_set_radius(&style_color32_text_default, 0);
	lv_style_set_bg_color(&style_color32_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_color32_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_color32_text_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_color32_text_default, 0);
	lv_style_set_text_color(&style_color32_text_default, lv_color_make(0xff, 0xb6, 0x60));
	lv_style_set_text_font(&style_color32_text_default, &lv_font_simsun_32);
	lv_style_set_text_letter_space(&style_color32_text_default, 2);
	lv_style_set_pad_left(&style_color32_text_default, 0);
	lv_style_set_pad_right(&style_color32_text_default, 0);
	lv_style_set_pad_top(&style_color32_text_default, 0);
	lv_style_set_pad_bottom(&style_color32_text_default, 0);

	lv_style_init(&style_white24_text_default);
	lv_style_reset(&style_white24_text_default);
	lv_style_set_radius(&style_white24_text_default, 0);
	lv_style_set_bg_color(&style_white24_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_white24_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_white24_text_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_white24_text_default, 0);
	lv_style_set_text_color(&style_white24_text_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_white24_text_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_white24_text_default, 2);
	lv_style_set_pad_left(&style_white24_text_default, 0);
	lv_style_set_pad_right(&style_white24_text_default, 0);
	lv_style_set_pad_top(&style_white24_text_default, 0);
	lv_style_set_pad_bottom(&style_white24_text_default, 0);
    //创想蓝
	lv_style_init(&style_white24_text_creality);
	lv_style_reset(&style_white24_text_creality);
	lv_style_set_radius(&style_white24_text_creality, 0);
	lv_style_set_bg_color(&style_white24_text_creality, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_white24_text_creality, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_white24_text_creality, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_white24_text_creality, 0);
	lv_style_set_text_color(&style_white24_text_creality, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_white24_text_creality, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_white24_text_creality, 2);
	lv_style_set_pad_left(&style_white24_text_creality, 0);
	lv_style_set_pad_right(&style_white24_text_creality, 0);
	lv_style_set_pad_top(&style_white24_text_creality, 0);
	lv_style_set_pad_bottom(&style_white24_text_creality, 0);

	lv_style_init(&style_white28_text_default);
	lv_style_reset(&style_white28_text_default);
	lv_style_set_radius(&style_white28_text_default, 0);
	lv_style_set_bg_color(&style_white28_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_white28_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_white28_text_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_white28_text_default, 0);
    lv_style_set_shadow_opa(&style_white28_text_default, 0);
	lv_style_set_border_width(&style_white28_text_default, 0);
	lv_style_set_text_color(&style_white28_text_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_white28_text_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_white28_text_default, 2);
	lv_style_set_pad_left(&style_white28_text_default, 0);
	lv_style_set_pad_right(&style_white28_text_default, 0);
	lv_style_set_pad_top(&style_white28_text_default, 0);
	lv_style_set_pad_bottom(&style_white28_text_default, 0);

    lv_style_init(&style_black24_text_default);
	lv_style_reset(&style_black24_text_default);
	lv_style_set_radius(&style_black24_text_default, 0);
	lv_style_set_bg_color(&style_black24_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_black24_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_black24_text_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_black24_text_default, 0);
	lv_style_set_text_color(&style_black24_text_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_black24_text_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_black24_text_default, 2);
	lv_style_set_pad_left(&style_black24_text_default, 0);
	lv_style_set_pad_right(&style_black24_text_default, 0);
	lv_style_set_pad_top(&style_black24_text_default, 0);
	lv_style_set_pad_bottom(&style_black24_text_default, 0);

	lv_style_init(&style_color28_text_default);
	lv_style_reset(&style_color28_text_default);
	lv_style_set_radius(&style_color28_text_default, 0);
	lv_style_set_bg_color(&style_color28_text_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_color28_text_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_color28_text_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_color28_text_default, 0);
	lv_style_set_text_color(&style_color28_text_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_color28_text_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_color28_text_default, 2);
	lv_style_set_pad_left(&style_color28_text_default, 0);
	lv_style_set_pad_right(&style_color28_text_default, 0);
	lv_style_set_pad_top(&style_color28_text_default, 0);
	lv_style_set_pad_bottom(&style_color28_text_default, 0);

	lv_style_init(&style_grey24_text_default);
	lv_style_reset(&style_grey24_text_default);
	lv_style_set_radius(&style_grey24_text_default, 0);
	lv_style_set_bg_color(&style_grey24_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_grey24_text_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_grey24_text_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_grey24_text_default, 0);
	lv_style_set_text_color(&style_grey24_text_default, lv_color_make(0x79, 0x79, 0x79));
	lv_style_set_text_font(&style_grey24_text_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_grey24_text_default, 2);
	lv_style_set_pad_left(&style_grey24_text_default, 0);
	lv_style_set_pad_right(&style_grey24_text_default, 0);
	lv_style_set_pad_top(&style_grey24_text_default, 0);
	lv_style_set_pad_bottom(&style_grey24_text_default, 0);

	lv_style_init(&style_bar_progress_default);
	lv_style_reset(&style_bar_progress_default);
	lv_style_set_radius(&style_bar_progress_default, 20);
	lv_style_set_bg_color(&style_bar_progress_default, lv_color_make(0x2b, 0x2b, 0x2b));
	lv_style_set_bg_grad_color(&style_bar_progress_default, lv_color_make(0x2b, 0x2b, 0x2b));
	lv_style_set_bg_grad_dir(&style_bar_progress_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_bar_progress_default, 60);
	lv_style_set_pad_left(&style_bar_progress_default, 0);
	lv_style_set_pad_right(&style_bar_progress_default, 0);
	lv_style_set_pad_top(&style_bar_progress_default, 0);
	lv_style_set_pad_bottom(&style_bar_progress_default, 0);

	lv_style_init(&style_bar_progress_indicator_default);
	lv_style_reset(&style_bar_progress_indicator_default);
	lv_style_set_radius(&style_bar_progress_indicator_default, 10);
	lv_style_set_bg_color(&style_bar_progress_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_bar_progress_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_bar_progress_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_bar_progress_indicator_default, 255);

	lv_style_init(&style_cb_default);
	lv_style_reset(&style_cb_default);
	lv_style_set_radius(&style_cb_default, 6);
	lv_style_set_bg_color(&style_cb_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_cb_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_cb_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cb_default, 0);
	lv_style_set_text_color(&style_cb_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_letter_space(&style_cb_default, 0);

	lv_style_init(&style_cb_indicator_default);
	lv_style_reset(&style_cb_indicator_default);
	lv_style_set_radius(&style_cb_indicator_default, 6);
	lv_style_set_bg_color(&style_cb_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_cb_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_cb_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_cb_indicator_default, 255);
	lv_style_set_border_color(&style_cb_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_cb_indicator_default, 2);

/*************************已确定的样式****************************************************/
	lv_style_init(&btnstyle_check_default);
	lv_style_reset(&btnstyle_check_default);
	lv_style_set_radius(&btnstyle_check_default, 32);
	lv_style_set_bg_color(&btnstyle_check_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&btnstyle_check_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&btnstyle_check_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&btnstyle_check_default, 73);
	lv_style_set_shadow_color(&btnstyle_check_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&btnstyle_check_default, 0);
	lv_style_set_border_color(&btnstyle_check_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&btnstyle_check_default, 2);
	lv_style_set_border_opa(&btnstyle_check_default, 255);

    lv_style_init(&btnstyle_uncheck_default);
	lv_style_reset(&btnstyle_uncheck_default);
	lv_style_set_radius(&btnstyle_uncheck_default, 32);
	lv_style_set_bg_color(&btnstyle_uncheck_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&btnstyle_uncheck_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&btnstyle_uncheck_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&btnstyle_uncheck_default, 0);
	lv_style_set_shadow_color(&btnstyle_uncheck_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&btnstyle_uncheck_default, 0);
	lv_style_set_border_color(&btnstyle_uncheck_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_border_width(&btnstyle_uncheck_default, 0);
	lv_style_set_border_opa(&btnstyle_uncheck_default, 255);

    lv_style_init(&labelstyle_check_default);
    lv_style_set_radius(&labelstyle_check_default, 0);
	lv_style_set_bg_color(&labelstyle_check_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&labelstyle_check_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&labelstyle_check_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&labelstyle_check_default, 255);
	lv_style_set_text_color(&labelstyle_check_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&labelstyle_check_default, 0);
	lv_style_set_pad_left(&labelstyle_check_default, 0);
	lv_style_set_pad_right(&labelstyle_check_default, 0);
	lv_style_set_pad_top(&labelstyle_check_default, 0);
	lv_style_set_pad_bottom(&labelstyle_check_default, 0);

    lv_style_init(&labelstyle_uncheck_default);
	lv_style_set_radius(&labelstyle_uncheck_default, 0);
	lv_style_set_bg_color(&labelstyle_uncheck_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&labelstyle_uncheck_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&labelstyle_uncheck_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&labelstyle_uncheck_default, 255);
	lv_style_set_text_color(&labelstyle_uncheck_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&labelstyle_uncheck_default, 0);
	lv_style_set_pad_left(&labelstyle_uncheck_default, 0);
	lv_style_set_pad_right(&labelstyle_uncheck_default, 0);
	lv_style_set_pad_top(&labelstyle_uncheck_default, 0);
	lv_style_set_pad_bottom(&labelstyle_uncheck_default, 0);

    lv_style_init(&labelstyle_opa_default);
    lv_style_set_radius(&labelstyle_opa_default, 0);
	lv_style_set_bg_color(&labelstyle_opa_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_color(&labelstyle_opa_default, lv_color_make(0x23, 0x24, 0x26));
	lv_style_set_bg_grad_dir(&labelstyle_opa_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&labelstyle_opa_default, 0);
	lv_style_set_text_color(&labelstyle_opa_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&labelstyle_opa_default, 0);
	lv_style_set_pad_left(&labelstyle_opa_default, 0);
	lv_style_set_pad_right(&labelstyle_opa_default, 0);
	lv_style_set_pad_top(&labelstyle_opa_default, 0);
	lv_style_set_pad_bottom(&labelstyle_opa_default, 0);

	//字体初始化
	lv_freetype_font_init();
}

void lv_freetype_font_init()
{
	lv_font14.name = GetSourceHanSansFilePath();
    lv_font14.weight = 14;
    lv_font14.style = FT_FONT_STYLE_NORMAL;
    lv_font14.mem = NULL;
	if(!lv_ft_font_init(&lv_font14)) {
        CrLogE("lv_font14 init failed.");
    }
	lv_font14.font->base_line += 2;
	lv_font14.font->line_height -= 3;

    lv_font18.name = GetSourceHanSansFilePath();
    lv_font18.weight = 18;
    lv_font18.style = FT_FONT_STYLE_NORMAL;
    lv_font18.mem = NULL;
	if(!lv_ft_font_init(&lv_font18)) {
        CrLogE("lv_font18 init failed.");
    }
	lv_font18.font->base_line += 2;
	lv_font18.font->line_height -= 3;

	lv_font22.name = GetSourceHanSansFilePath();
    lv_font22.weight = 22;
    lv_font22.style = FT_FONT_STYLE_NORMAL;
    lv_font22.mem = NULL;
	if(!lv_ft_font_init(&lv_font22)) {
        CrLogE("lv_font22 init failed.");
    }
	lv_font22.font->base_line += 3;
	lv_font22.font->line_height -= 6;

	lv_font24.name = GetSourceHanSansFilePath();
    lv_font24.weight = 24;
    lv_font24.style = FT_FONT_STYLE_NORMAL;
    lv_font24.mem = NULL;
	if(!lv_ft_font_init(&lv_font24)) {
        CrLogE("lv_font24 init failed.");
    }
	lv_font24.font->base_line += 3;
	lv_font24.font->line_height -= 7;

	lv_font25.name = GetSourceHanSansFilePath();
    lv_font25.weight = 25;
    lv_font25.style = FT_FONT_STYLE_NORMAL;
    lv_font25.mem = NULL;
	if(!lv_ft_font_init(&lv_font25)) {
        CrLogE("lv_font25 init failed.");
    }
	lv_font25.font->base_line += 2;
	lv_font25.font->line_height -= 9;

	lv_font26.name = GetSourceHanSansFilePath();
    lv_font26.weight = 26;
    lv_font26.style = FT_FONT_STYLE_NORMAL;
    lv_font26.mem = NULL;
	if(!lv_ft_font_init(&lv_font26)) {
        CrLogE("lv_font26 init failed.");
    }

	lv_font28.name = GetSourceHanSansFilePath();
    lv_font28.weight = 28;
    lv_font28.style = FT_FONT_STYLE_NORMAL;
    lv_font28.mem = NULL;
	if(!lv_ft_font_init(&lv_font28)) {
        CrLogE("lv_font28 init failed.");
    }
	lv_font28.font->base_line += 3;
	lv_font28.font->line_height -= 6;

	lv_font30.name = GetSourceHanSansFilePath();
    lv_font30.weight = 30;
    lv_font30.style = FT_FONT_STYLE_NORMAL;
    lv_font30.mem = NULL;
	if(!lv_ft_font_init(&lv_font30)) {
        CrLogE("lv_font30 init failed.");
    }
	lv_font30.font->base_line += 4;
	lv_font30.font->line_height -= 9;

	lv_font32.name = GetSourceHanSansFilePath();
    lv_font32.weight = 32;
    lv_font32.style = FT_FONT_STYLE_NORMAL;
    lv_font32.mem = NULL;
	if(!lv_ft_font_init(&lv_font32)) {
        CrLogE("lv_font32 init failed.");
    }
	lv_font32.font->base_line += 6;
	lv_font32.font->line_height -= 9;

}

