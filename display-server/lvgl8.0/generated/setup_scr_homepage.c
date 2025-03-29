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

lv_chart_series_t * ser_h_hotend;
lv_chart_series_t * ser_h_bed;

static void draw_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);

    /*Add the faded area before the lines are drawn*/
    lv_obj_draw_part_dsc_t *dsc = lv_event_get_draw_part_dsc(e);
    if (dsc->part == LV_PART_ITEMS)
    {
        if (!dsc->p1 || !dsc->p2)
            return;

        /*Add a line mask that keeps the area below the line*/
        lv_draw_mask_line_param_t line_mask_param;
        lv_draw_mask_line_points_init(&line_mask_param, dsc->p1->x, dsc->p1->y, dsc->p2->x, dsc->p2->y, LV_DRAW_MASK_LINE_SIDE_BOTTOM);
        int16_t line_mask_id = lv_draw_mask_add(&line_mask_param, NULL);

        /*Add a fade effect: transparent bottom covering top*/
        lv_coord_t h = lv_obj_get_height(obj);
        lv_draw_mask_fade_param_t fade_mask_param;
        lv_draw_mask_fade_init(&fade_mask_param, &obj->coords, LV_OPA_COVER, obj->coords.y1 + h / 8, LV_OPA_TRANSP,obj->coords.y2);
        int16_t fade_mask_id = lv_draw_mask_add(&fade_mask_param, NULL);

        /*Draw a rectangle that will be affected by the mask*/
        lv_draw_rect_dsc_t draw_rect_dsc;
        lv_draw_rect_dsc_init(&draw_rect_dsc);
        draw_rect_dsc.bg_opa = LV_OPA_70;
        draw_rect_dsc.bg_color = dsc->line_dsc->color;

        lv_area_t a;
        a.x1 = dsc->p1->x;
        a.x2 = dsc->p2->x;
        a.y1 = LV_MIN(dsc->p1->y, dsc->p2->y);
        a.y2 = obj->coords.y2 - 13; /* -13 cuts off where the rectangle draws over the chart margin. Without this an area of 0 doesnt look like 0 */
        lv_draw_rect(dsc->draw_ctx, &draw_rect_dsc, &a);

        /*Remove the mask*/
        lv_draw_mask_free_param(&line_mask_param);
        lv_draw_mask_remove_id(line_mask_id);
        lv_draw_mask_remove_id(fade_mask_id);
    }
}

static int32_t round_fixed_point(int32_t n, int8_t shift)
{
    /* Create a bitmask to isolates the decimal part of the fixed point number */
    int32_t mask = 1;
    for (int32_t bit_pos = 0; bit_pos < shift; bit_pos++)
    {
        mask = (mask << 1) + 1;
    }

    int32_t decimal_part = n & mask;

    /* Get 0.5 as fixed point */
    int32_t rounding_boundary = 1 << (shift - 1);

    /* Return either the integer part of n or the integer part + 1 */
    return (decimal_part < rounding_boundary) ? (n & ~mask) : ((n >> shift) + 1) << shift;
}

/**
 * Stacked area chart
 */
void lv_example_chart_10(void)
{
    /*Create a stacked_area_chart.obj*/
    //Write style state: LV_STATE_DEFAULT for style_homepage_chart_1_main_main_default
	static lv_style_t style_homepage_chart_1_main_main_default;
	if (style_homepage_chart_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_chart_1_main_main_default);
	else
		lv_style_init(&style_homepage_chart_1_main_main_default);
	lv_style_set_bg_color(&style_homepage_chart_1_main_main_default, lv_color_make(0x21, 0x21, 0x22));
	lv_style_set_bg_grad_color(&style_homepage_chart_1_main_main_default, lv_color_make(0x21, 0x21, 0x22));
	lv_style_set_bg_grad_dir(&style_homepage_chart_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_border_width(&style_homepage_chart_1_main_main_default,0);
	lv_style_set_bg_opa(&style_homepage_chart_1_main_main_default, 255);
	lv_style_set_pad_left(&style_homepage_chart_1_main_main_default, 0);
	lv_style_set_pad_right(&style_homepage_chart_1_main_main_default, 0);
	lv_style_set_pad_top(&style_homepage_chart_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_homepage_chart_1_main_main_default, 0);
	lv_style_set_line_color(&style_homepage_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_homepage_chart_1_main_main_default, 0);
    lv_style_set_line_dash_width(&style_homepage_chart_1_main_main_default, 1);
	lv_style_set_line_opa(&style_homepage_chart_1_main_main_default, 255);

    (guider_ui.stacked_area_chart).obj= lv_chart_create(guider_ui.homepage_cont_1);
	lv_obj_add_style((guider_ui.stacked_area_chart).obj, &style_homepage_chart_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size((guider_ui.stacked_area_chart).obj, 440, 460);
	lv_obj_set_pos((guider_ui.stacked_area_chart).obj, 30, 152);
    lv_chart_set_type((guider_ui.stacked_area_chart).obj, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count((guider_ui.stacked_area_chart).obj, 5, 0);
    lv_obj_add_event_cb((guider_ui.stacked_area_chart).obj, draw_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);

    /* Set range to 0 to 100 for percentages. Draw ticks */
    lv_chart_set_range((guider_ui.stacked_area_chart).obj,LV_CHART_AXIS_PRIMARY_Y,0,300);
    lv_chart_set_axis_tick((guider_ui.stacked_area_chart).obj, LV_CHART_AXIS_PRIMARY_Y, 3, 0, 6, 1, true, 30);
	lv_chart_set_point_count((guider_ui.stacked_area_chart).obj, 200);

    /*Set point size to 0 so the lines are smooth */
    lv_obj_set_style_size((guider_ui.stacked_area_chart).obj, 0, LV_PART_INDICATOR);//将点的大小设置为0

    /*Add some data series*/
    guider_ui.stacked_area_chart.series_list[0] = lv_chart_add_series((guider_ui.stacked_area_chart).obj, lv_color_make(0x00, 0x00, 0x00), LV_CHART_AXIS_PRIMARY_Y);
    guider_ui.stacked_area_chart.series_list[1] = lv_chart_add_series((guider_ui.stacked_area_chart).obj, lv_color_make(0x42, 0xbd, 0xd8), LV_CHART_AXIS_PRIMARY_Y);
    guider_ui.stacked_area_chart.series_list[2] = lv_chart_add_series((guider_ui.stacked_area_chart).obj, lv_color_make(0x3c, 0xe4, 0xaa), LV_CHART_AXIS_PRIMARY_Y);

//    for (int point = 0; point < 10; point++)
//    {
//        /* Make some random data */
//        uint32_t vals[3] = {100, 60, 300};
//
//        int8_t fixed_point_shift = 5;
//        uint32_t total = 300;
//        uint32_t draw_heights[3];
//        uint32_t int_sum = 0;
//        uint32_t decimal_sum = 0;
//
//        /* Fixed point cascade rounding ensures percentages add to 100 */
//        for (int32_t series_index = 0; series_index < 3; series_index++)
//        {
//            decimal_sum += (((vals[series_index] * 100) << fixed_point_shift) / total);
//            int_sum += 60;
//
//            int32_t modifier = (round_fixed_point(decimal_sum, fixed_point_shift) >> fixed_point_shift) - int_sum;
//
//            /*  The draw heights are equal to the percentage of the total each value is + the cumulative sum of the previous percentages.
//                The accumulation is how the values get "stacked" */
//            draw_heights[series_index] =  int_sum;
//
//            /*  Draw to the series in the reverse order to which they were initialised.
//                Without this the higher values will draw on top of the lower ones.
//                This is because the Z-height of a series matches the order it was initialsied */
//            lv_chart_set_next_value((guider_ui.stacked_area_chart).obj, guider_ui.stacked_area_chart.series_list[3 - series_index - 1], draw_heights[series_index]);
//        }
//    }
//
//    lv_chart_refresh((guider_ui.stacked_area_chart).obj);
}

void setup_scr_homepage(lv_ui *ui){

	//Write codes homepage_cont_1
	ui->homepage_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->homepage_cont_1, 0, 0);
	lv_obj_set_size(ui->homepage_cont_1, 480, 800);
	//Write style state: LV_STATE_DEFAULT for style_homepage_cont_1_main_main_default
	static lv_style_t style_homepage_cont_1_main_main_default;
	if (style_homepage_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_cont_1_main_main_default);
	else
		lv_style_init(&style_homepage_cont_1_main_main_default);
	lv_style_set_radius(&style_homepage_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_homepage_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_homepage_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_homepage_cont_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_homepage_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_homepage_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_homepage_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_homepage_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_homepage_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_homepage_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_homepage_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->homepage_cont_1, &style_homepage_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

//	//Write codes homepage_chart_1
//	ui->homepage_chart_1 = lv_chart_create(ui->homepage_cont_1);
//	lv_obj_set_pos(ui->homepage_chart_1, 10, 152);
//	lv_obj_set_size(ui->homepage_chart_1, 460, 460);
//
//	//Write style state: LV_STATE_DEFAULT for style_homepage_chart_1_main_main_default
//	static lv_style_t style_homepage_chart_1_main_main_default;
//	if (style_homepage_chart_1_main_main_default.prop_cnt > 1)
//		lv_style_reset(&style_homepage_chart_1_main_main_default);
//	else
//		lv_style_init(&style_homepage_chart_1_main_main_default);
//	lv_style_set_bg_color(&style_homepage_chart_1_main_main_default, lv_color_make(0x21, 0x21, 0x22));
//	lv_style_set_bg_grad_color(&style_homepage_chart_1_main_main_default, lv_color_make(0x21, 0x21, 0x22));
//	lv_style_set_bg_grad_dir(&style_homepage_chart_1_main_main_default, LV_GRAD_DIR_VER);
//	lv_style_set_bg_opa(&style_homepage_chart_1_main_main_default, 255);
//	lv_style_set_pad_left(&style_homepage_chart_1_main_main_default, 0);
//	lv_style_set_pad_right(&style_homepage_chart_1_main_main_default, 0);
//	lv_style_set_pad_top(&style_homepage_chart_1_main_main_default, 0);
//	lv_style_set_pad_bottom(&style_homepage_chart_1_main_main_default, 0);
//	lv_style_set_line_color(&style_homepage_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
//	lv_style_set_line_width(&style_homepage_chart_1_main_main_default, 0);
//    lv_style_set_line_dash_width(&style_homepage_chart_1_main_main_default, 1);
//	lv_style_set_line_opa(&style_homepage_chart_1_main_main_default, 255);
//	lv_obj_set_style_size(ui->homepage_chart_1,0,LV_PART_INDICATOR);    //将点的大小设置为0
//	lv_obj_add_style(ui->homepage_chart_1, &style_homepage_chart_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_chart_axis_t home_chart_y = LV_CHART_AXIS_PRIMARY_Y;
//
//	lv_chart_set_axis_tick(ui->homepage_chart_1,home_chart_y,10,5,6,1,true,10); //增加刻度线
//	lv_chart_set_type(ui->homepage_chart_1, LV_CHART_TYPE_LINE);
//	lv_chart_set_range(ui->homepage_chart_1,LV_CHART_AXIS_PRIMARY_Y, 0, 250);
//	lv_chart_set_div_line_count(ui->homepage_chart_1, 6, 20);
//	lv_chart_set_point_count(ui->homepage_chart_1, 50);
//	ser_h_hotend = lv_chart_add_series(ui->homepage_chart_1, lv_color_make(0x42, 0xBD, 0xD8), LV_CHART_AXIS_PRIMARY_Y);
//    ser_h_bed = lv_chart_add_series(ui->homepage_chart_1, lv_color_make(0x3C, 0xE4, 0xAA), LV_CHART_AXIS_PRIMARY_Y);

	//Write codes homepage_label_6
	ui->homepage_label_6 = lv_label_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_label_6, 9, 153);
	lv_obj_set_size(ui->homepage_label_6, 460, 460);
	lv_label_set_text(ui->homepage_label_6, "");
	lv_label_set_long_mode(ui->homepage_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->homepage_label_6, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_homepage_label_6_main_main_default
	static lv_style_t style_homepage_label_6_main_main_default;
	if (style_homepage_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_label_6_main_main_default);
	else
		lv_style_init(&style_homepage_label_6_main_main_default);
	lv_style_set_radius(&style_homepage_label_6_main_main_default, 6);
	lv_style_set_bg_color(&style_homepage_label_6_main_main_default, lv_color_make(0x21, 0x21, 0x22));
	lv_style_set_bg_grad_color(&style_homepage_label_6_main_main_default, lv_color_make(0x21, 0x21, 0x22));
	lv_style_set_bg_grad_dir(&style_homepage_label_6_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_label_6_main_main_default, 255);
	lv_style_set_text_color(&style_homepage_label_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_homepage_label_6_main_main_default, 0);
	lv_style_set_pad_left(&style_homepage_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_homepage_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_homepage_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_homepage_label_6_main_main_default, 0);
	lv_obj_add_style(ui->homepage_label_6, &style_homepage_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes homepage_bar_1
	ui->homepage_bar_1 = lv_bar_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_bar_1, 52, 568);
	lv_obj_set_size(ui->homepage_bar_1, 377, 24);

	//Write style state: LV_STATE_DEFAULT for style_homepage_bar_1_main_main_default
	static lv_style_t style_homepage_bar_1_main_main_default;
	if (style_homepage_bar_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_bar_1_main_main_default);
	else
		lv_style_init(&style_homepage_bar_1_main_main_default);
	lv_style_set_radius(&style_homepage_bar_1_main_main_default, 16);
	lv_style_set_bg_color(&style_homepage_bar_1_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_color(&style_homepage_bar_1_main_main_default, lv_color_make(0x3a, 0x3d, 0x42));
	lv_style_set_bg_grad_dir(&style_homepage_bar_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_bar_1_main_main_default, 255);
	lv_style_set_pad_left(&style_homepage_bar_1_main_main_default, 0);
	lv_style_set_pad_right(&style_homepage_bar_1_main_main_default, 0);
	lv_style_set_pad_top(&style_homepage_bar_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_homepage_bar_1_main_main_default, 0);
	lv_obj_add_style(ui->homepage_bar_1, &style_homepage_bar_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_homepage_bar_1_main_indicator_default
	static lv_style_t style_homepage_bar_1_main_indicator_default;
	if (style_homepage_bar_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_bar_1_main_indicator_default);
	else
		lv_style_init(&style_homepage_bar_1_main_indicator_default);
	lv_style_set_radius(&style_homepage_bar_1_main_indicator_default, 16);
	lv_style_set_bg_color(&style_homepage_bar_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_color(&style_homepage_bar_1_main_indicator_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_bg_grad_dir(&style_homepage_bar_1_main_indicator_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_bar_1_main_indicator_default, 255);
	lv_obj_add_style(ui->homepage_bar_1, &style_homepage_bar_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->homepage_bar_1, 1000, 0);
	lv_bar_set_mode(ui->homepage_bar_1, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->homepage_bar_1, 50, LV_ANIM_OFF);

	//Write codes homepage_img_16
	ui->homepage_img_16 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_16, 90, 205);
	lv_obj_set_size(ui->homepage_img_16, 300, 300);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_16_main_main_default
	static lv_style_t style_homepage_img_16_main_main_default;
	if (style_homepage_img_16_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_16_main_main_default);
	else
		lv_style_init(&style_homepage_img_16_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_16_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_16_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_16_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_16, &style_homepage_img_16_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes homepage_label_7
	ui->homepage_label_7 = lv_label_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_label_7, 40, 166);
	lv_obj_set_size(ui->homepage_label_7, 400, 32);
	lv_label_set_text(ui->homepage_label_7, "test");
	lv_label_set_long_mode(ui->homepage_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->homepage_label_7, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_homepage_label_7_main_main_default
	static lv_style_t style_homepage_label_7_main_main_default;
	if (style_homepage_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_label_7_main_main_default);
	else
		lv_style_init(&style_homepage_label_7_main_main_default);
	lv_style_set_radius(&style_homepage_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_homepage_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_homepage_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_homepage_label_7_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_homepage_label_7_main_main_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_font(&style_homepage_label_7_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_homepage_label_7_main_main_default, 0);
	lv_style_set_pad_left(&style_homepage_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_homepage_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_homepage_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_homepage_label_7_main_main_default, 0);
	lv_obj_add_style(ui->homepage_label_7, &style_homepage_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes homepage_label_8
	ui->homepage_label_8 = lv_label_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_label_8, 53, 529);
	lv_obj_set_size(ui->homepage_label_8, 79, 24);
	lv_label_set_text(ui->homepage_label_8, "0h0m");
	lv_label_set_long_mode(ui->homepage_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->homepage_label_8, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_homepage_label_8_main_main_default
	static lv_style_t style_homepage_label_8_main_main_default;
	if (style_homepage_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_label_8_main_main_default);
	else
		lv_style_init(&style_homepage_label_8_main_main_default);
	lv_style_set_radius(&style_homepage_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_homepage_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_homepage_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_homepage_label_8_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_homepage_label_8_main_main_default, lv_color_make(0x50, 0x53, 0x5b));
	lv_style_set_text_font(&style_homepage_label_8_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_homepage_label_8_main_main_default, 0);
	lv_style_set_pad_left(&style_homepage_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_homepage_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_homepage_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_homepage_label_8_main_main_default, 0);
	lv_obj_add_style(ui->homepage_label_8, &style_homepage_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes homepage_label_11
	ui->homepage_label_11 = lv_label_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_label_11, 341, 529);
	lv_obj_set_size(ui->homepage_label_11, 79, 24);
	lv_label_set_text(ui->homepage_label_11, "0h0m");
	lv_label_set_long_mode(ui->homepage_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->homepage_label_11, LV_TEXT_ALIGN_RIGHT, 0);

	//Write style state: LV_STATE_DEFAULT for style_homepage_label_11_main_main_default
	static lv_style_t style_homepage_label_11_main_main_default;
	if (style_homepage_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_label_11_main_main_default);
	else
		lv_style_init(&style_homepage_label_11_main_main_default);
	lv_style_set_radius(&style_homepage_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_homepage_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_homepage_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_homepage_label_11_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_homepage_label_11_main_main_default, lv_color_make(0x50, 0x53, 0x5b));
	lv_style_set_text_font(&style_homepage_label_11_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_homepage_label_11_main_main_default, 0);
	lv_style_set_pad_left(&style_homepage_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_homepage_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_homepage_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_homepage_label_11_main_main_default, 0);
	lv_obj_add_style(ui->homepage_label_11, &style_homepage_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes homepage_label_9
	ui->homepage_label_9 = lv_label_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_label_9, 219, 526);
	lv_obj_set_size(ui->homepage_label_9, 42, 28);
	lv_label_set_text(ui->homepage_label_9, "100");
	lv_label_set_long_mode(ui->homepage_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->homepage_label_9, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_homepage_label_9_main_main_default
	static lv_style_t style_homepage_label_9_main_main_default;
	if (style_homepage_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_label_9_main_main_default);
	else
		lv_style_init(&style_homepage_label_9_main_main_default);
	lv_style_set_radius(&style_homepage_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_homepage_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_homepage_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_homepage_label_9_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_homepage_label_9_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_homepage_label_9_main_main_default, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_homepage_label_9_main_main_default, 0);
	lv_style_set_pad_left(&style_homepage_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_homepage_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_homepage_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_homepage_label_9_main_main_default, 0);
	lv_obj_add_style(ui->homepage_label_9, &style_homepage_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes homepage_label_10
	ui->homepage_label_10 = lv_label_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_label_10, 267, 529);
	lv_obj_set_size(ui->homepage_label_10, 17, 24);
	lv_label_set_text(ui->homepage_label_10, "%");
	lv_label_set_long_mode(ui->homepage_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->homepage_label_10, LV_TEXT_ALIGN_LEFT, 0);

	//Write style state: LV_STATE_DEFAULT for style_homepage_label_10_main_main_default
	static lv_style_t style_homepage_label_10_main_main_default;
	if (style_homepage_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_label_10_main_main_default);
	else
		lv_style_init(&style_homepage_label_10_main_main_default);
	lv_style_set_radius(&style_homepage_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_homepage_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_homepage_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_homepage_label_10_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_homepage_label_10_main_main_default, lv_color_make(0x42, 0xbd, 0xd8));
	lv_style_set_text_font(&style_homepage_label_10_main_main_default, &lv_font_simsun_24);
	lv_style_set_text_letter_space(&style_homepage_label_10_main_main_default, 0);
	lv_style_set_pad_left(&style_homepage_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_homepage_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_homepage_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_homepage_label_10_main_main_default, 0);
	lv_obj_add_style(ui->homepage_label_10, &style_homepage_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes homepage_label_5
	ui->homepage_label_5 = lv_label_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_label_5, 0, 720);
	lv_obj_set_size(ui->homepage_label_5, 480, 80);
	lv_label_set_text(ui->homepage_label_5, "");
	lv_label_set_long_mode(ui->homepage_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->homepage_label_5, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_homepage_label_5_main_main_default
	static lv_style_t style_homepage_label_5_main_main_default;
	if (style_homepage_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_label_5_main_main_default);
	else
		lv_style_init(&style_homepage_label_5_main_main_default);
	lv_style_set_radius(&style_homepage_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_homepage_label_5_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_color(&style_homepage_label_5_main_main_default, lv_color_make(0x0e, 0x0e, 0x0e));
	lv_style_set_bg_grad_dir(&style_homepage_label_5_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_label_5_main_main_default, 255);
	lv_style_set_text_color(&style_homepage_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_letter_space(&style_homepage_label_5_main_main_default, 0);
	lv_style_set_pad_left(&style_homepage_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_homepage_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_homepage_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_homepage_label_5_main_main_default, 0);
	lv_obj_add_style(ui->homepage_label_5, &style_homepage_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes homepage_img_11
	ui->homepage_img_11 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_11, 30, 742);
	lv_obj_set_size(ui->homepage_img_11, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_11_main_main_default
	static lv_style_t style_homepage_img_11_main_main_default;
	if (style_homepage_img_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_11_main_main_default);
	else
		lv_style_init(&style_homepage_img_11_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_11_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_11_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_11, &style_homepage_img_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_11, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_11,&_home_blue_48x48);
	lv_img_set_pivot(ui->homepage_img_11, 0,0);
	lv_img_set_angle(ui->homepage_img_11, 0);

	//Write codes homepage_img_12
	ui->homepage_img_12 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_12, 128, 742);
	lv_obj_set_size(ui->homepage_img_12, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_12_main_main_default
	static lv_style_t style_homepage_img_12_main_main_default;
	if (style_homepage_img_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_12_main_main_default);
	else
		lv_style_init(&style_homepage_img_12_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_12_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_12_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_12, &style_homepage_img_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_12, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_12,&_prepare_48x48);
	lv_img_set_pivot(ui->homepage_img_12, 0,0);
	lv_img_set_angle(ui->homepage_img_12, 0);

	//Write codes homepage_img_13
	ui->homepage_img_13 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_13, 224, 742);
	lv_obj_set_size(ui->homepage_img_13, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_13_main_main_default
	static lv_style_t style_homepage_img_13_main_main_default;
	if (style_homepage_img_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_13_main_main_default);
	else
		lv_style_init(&style_homepage_img_13_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_13_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_13_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_13, &style_homepage_img_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_13, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_13,&_files_48x48);
	lv_img_set_pivot(ui->homepage_img_13, 0,0);
	lv_img_set_angle(ui->homepage_img_13, 0);

	//Write codes homepage_img_14
	ui->homepage_img_14 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_14, 318, 742);
	lv_obj_set_size(ui->homepage_img_14, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_14_main_main_default
	static lv_style_t style_homepage_img_14_main_main_default;
	if (style_homepage_img_14_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_14_main_main_default);
	else
		lv_style_init(&style_homepage_img_14_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_14_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_14_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_14_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_14, &style_homepage_img_14_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_14, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_14,&_seting_48x48);
	lv_img_set_pivot(ui->homepage_img_14, 0,0);
	lv_img_set_angle(ui->homepage_img_14, 0);

	//Write codes homepage_img_15
	ui->homepage_img_15 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_15, 414, 742);
	lv_obj_set_size(ui->homepage_img_15, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_15_main_main_default
	static lv_style_t style_homepage_img_15_main_main_default;
	if (style_homepage_img_15_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_15_main_main_default);
	else
		lv_style_init(&style_homepage_img_15_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_15_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_15_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_15_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_15, &style_homepage_img_15_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_15, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_15,&_FAQ_48x48);
	lv_img_set_pivot(ui->homepage_img_15, 0,0);
	lv_img_set_angle(ui->homepage_img_15, 0);

	//Write codes homepage_btn_4
	ui->homepage_btn_4 = lv_btn_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_btn_4, 222, 623);
	lv_obj_set_size(ui->homepage_btn_4, 248, 82);

	//Write style state: LV_STATE_DEFAULT for style_homepage_btn_4_main_main_default
	static lv_style_t style_homepage_btn_4_main_main_default;
	if (style_homepage_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_btn_4_main_main_default);
	else
		lv_style_init(&style_homepage_btn_4_main_main_default);
	lv_style_set_radius(&style_homepage_btn_4_main_main_default, 8);
	lv_style_set_bg_color(&style_homepage_btn_4_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_homepage_btn_4_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_homepage_btn_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_btn_4_main_main_default, 255);
	lv_style_set_shadow_color(&style_homepage_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_homepage_btn_4_main_main_default, 0);
	lv_style_set_border_color(&style_homepage_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_homepage_btn_4_main_main_default, 0);
	lv_style_set_border_opa(&style_homepage_btn_4_main_main_default, 255);
	lv_obj_add_style(ui->homepage_btn_4, &style_homepage_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->homepage_btn_4_label = lv_label_create(ui->homepage_btn_4);
	lv_label_set_text(ui->homepage_btn_4_label, "");
	lv_obj_set_style_text_color(ui->homepage_btn_4_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->homepage_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->homepage_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes homepage_img_10
	ui->homepage_img_10 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_10, 328, 646);
	lv_obj_set_size(ui->homepage_img_10, 36, 36);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_10_main_main_default
	static lv_style_t style_homepage_img_10_main_main_default;
	if (style_homepage_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_10_main_main_default);
	else
		lv_style_init(&style_homepage_img_10_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_10_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_10, &style_homepage_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_10,&_Group_1179_36x36);
	lv_img_set_pivot(ui->homepage_img_10, 0,0);
	lv_img_set_angle(ui->homepage_img_10, 0);

	//Write codes homepage_img_17
	ui->homepage_img_17 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_17, 295, 638);
	lv_obj_set_size(ui->homepage_img_17, 102, 53);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_17_main_main_default
	static lv_style_t style_homepage_img_17_main_main_default;
	if (style_homepage_img_17_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_17_main_main_default);
	else
		lv_style_init(&style_homepage_img_17_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_17_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_17_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_17_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_17, &style_homepage_img_17_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_17, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_17,&_pause_102x53);
	lv_img_set_pivot(ui->homepage_img_17, 0,0);
	lv_img_set_angle(ui->homepage_img_17, 0);

	//Write codes homepage_img_3
	ui->homepage_img_3 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_3, 10, 61);
	lv_obj_set_size(ui->homepage_img_3, 460, 82);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_3_main_main_default
	static lv_style_t style_homepage_img_3_main_main_default;
	if (style_homepage_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_3_main_main_default);
	else
		lv_style_init(&style_homepage_img_3_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_3_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_3, &style_homepage_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_3,&_homepage_back1_460x82);
	lv_img_set_pivot(ui->homepage_img_3, 0,0);
	lv_img_set_angle(ui->homepage_img_3, 0);

	//Write codes homepage_label_4
	ui->homepage_label_4 = lv_label_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_label_4, 10, 623);
	lv_obj_set_size(ui->homepage_label_4, 202, 82);
	lv_label_set_text(ui->homepage_label_4, "");
	lv_label_set_long_mode(ui->homepage_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->homepage_label_4, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_homepage_label_4_main_main_default
	static lv_style_t style_homepage_label_4_main_main_default;
	if (style_homepage_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_label_4_main_main_default);
	else
		lv_style_init(&style_homepage_label_4_main_main_default);
	lv_style_set_radius(&style_homepage_label_4_main_main_default, 8);
	lv_style_set_bg_color(&style_homepage_label_4_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_color(&style_homepage_label_4_main_main_default, lv_color_make(0x1c, 0x1c, 0x1e));
	lv_style_set_bg_grad_dir(&style_homepage_label_4_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_label_4_main_main_default, 255);
	lv_style_set_text_color(&style_homepage_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_homepage_label_4_main_main_default, 0);
	lv_style_set_pad_left(&style_homepage_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_homepage_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_homepage_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_homepage_label_4_main_main_default, 0);
	lv_obj_add_style(ui->homepage_label_4, &style_homepage_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes homepage_img_9
	ui->homepage_img_9 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_9, 141, 639);
	lv_obj_set_size(ui->homepage_img_9, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_9_main_main_default
	static lv_style_t style_homepage_img_9_main_main_default;
	if (style_homepage_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_9_main_main_default);
	else
		lv_style_init(&style_homepage_img_9_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_9_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_9, &style_homepage_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_9,&_fan_48x48);
	lv_img_set_pivot(ui->homepage_img_9, 0,0);
	lv_img_set_angle(ui->homepage_img_9, 0);

	//Write codes homepage_img_8
	ui->homepage_img_8 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_8, 111, 628);
	lv_obj_set_size(ui->homepage_img_8, 1, 70);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_8_main_main_default
	static lv_style_t style_homepage_img_8_main_main_default;
	if (style_homepage_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_8_main_main_default);
	else
		lv_style_init(&style_homepage_img_8_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_8_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_8, &style_homepage_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_8,&_Rectangle_1439_1x70);
	lv_img_set_pivot(ui->homepage_img_8, 0,0);
	lv_img_set_angle(ui->homepage_img_8, 0);

	//Write codes homepage_img_7
	ui->homepage_img_7 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_7, 40, 639);
	lv_obj_set_size(ui->homepage_img_7, 48, 48);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_7_main_main_default
	static lv_style_t style_homepage_img_7_main_main_default;
	if (style_homepage_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_7_main_main_default);
	else
		lv_style_init(&style_homepage_img_7_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_7_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_7, &style_homepage_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_7,&_LED2_48x48);
	lv_img_set_pivot(ui->homepage_img_7, 0,0);
	lv_img_set_angle(ui->homepage_img_7, 0);

	//Write codes homepage_btn_1
	ui->homepage_btn_1 = lv_btn_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_btn_1, 17, 77);
	lv_obj_set_size(ui->homepage_btn_1, 142, 50);

	//Write style state: LV_STATE_DEFAULT for style_homepage_btn_1_main_main_default
	static lv_style_t style_homepage_btn_1_main_main_default;
	if (style_homepage_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_btn_1_main_main_default);
	else
		lv_style_init(&style_homepage_btn_1_main_main_default);
	lv_style_set_radius(&style_homepage_btn_1_main_main_default, 35);
	lv_style_set_bg_color(&style_homepage_btn_1_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_homepage_btn_1_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_homepage_btn_1_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_btn_1_main_main_default, 255);
	lv_style_set_shadow_color(&style_homepage_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_homepage_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_homepage_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_homepage_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_homepage_btn_1_main_main_default, 255);
	lv_obj_add_style(ui->homepage_btn_1, &style_homepage_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->homepage_btn_1_label = lv_label_create(ui->homepage_btn_1);
	lv_label_set_text(ui->homepage_btn_1_label, "210");
	lv_obj_set_style_text_color(ui->homepage_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->homepage_btn_1_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->homepage_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->homepage_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes homepage_img_18
	ui->homepage_img_18 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_18, 109, 96);
	lv_obj_set_size(ui->homepage_img_18, 18, 15);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_18_main_main_default
	static lv_style_t style_homepage_img_18_main_main_default;
	if (style_homepage_img_18_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_18_main_main_default);
	else
		lv_style_init(&style_homepage_img_18_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_18_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_18_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_18_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_18, &style_homepage_img_18_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_18, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_18,&_temprature_18x15);
	lv_img_set_pivot(ui->homepage_img_18, 0,0);
	lv_img_set_angle(ui->homepage_img_18, 0);

	//Write codes homepage_btn_2
	ui->homepage_btn_2 = lv_btn_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_btn_2, 169, 77);
	lv_obj_set_size(ui->homepage_btn_2, 142, 50);

	//Write style state: LV_STATE_DEFAULT for style_homepage_btn_2_main_main_default
	static lv_style_t style_homepage_btn_2_main_main_default;
	if (style_homepage_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_btn_2_main_main_default);
	else
		lv_style_init(&style_homepage_btn_2_main_main_default);
	lv_style_set_radius(&style_homepage_btn_2_main_main_default, 35);
	lv_style_set_bg_color(&style_homepage_btn_2_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_homepage_btn_2_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_homepage_btn_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_btn_2_main_main_default, 255);
	lv_style_set_shadow_color(&style_homepage_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_homepage_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_homepage_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_homepage_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_homepage_btn_2_main_main_default, 255);
	lv_obj_add_style(ui->homepage_btn_2, &style_homepage_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->homepage_btn_2_label = lv_label_create(ui->homepage_btn_2);
	lv_label_set_text(ui->homepage_btn_2_label, "60");
	lv_obj_set_style_text_color(ui->homepage_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->homepage_btn_2_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->homepage_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->homepage_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes homepage_img_19
	ui->homepage_img_19 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_19, 255, 96);
	lv_obj_set_size(ui->homepage_img_19, 18, 15);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_19_main_main_default
	static lv_style_t style_homepage_img_19_main_main_default;
	if (style_homepage_img_19_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_19_main_main_default);
	else
		lv_style_init(&style_homepage_img_19_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_19_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_19_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_19_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_19, &style_homepage_img_19_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_19, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_19,&_temprature_18x15);
	lv_img_set_pivot(ui->homepage_img_19, 0,0);
	lv_img_set_angle(ui->homepage_img_19, 0);

	//Write codes homepage_btn_3
	ui->homepage_btn_3 = lv_btn_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_btn_3, 321, 77);
	lv_obj_set_size(ui->homepage_btn_3, 142, 50);

	//Write style state: LV_STATE_DEFAULT for style_homepage_btn_3_main_main_default
	static lv_style_t style_homepage_btn_3_main_main_default;
	if (style_homepage_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_btn_3_main_main_default);
	else
		lv_style_init(&style_homepage_btn_3_main_main_default);
	lv_style_set_radius(&style_homepage_btn_3_main_main_default, 35);
	lv_style_set_bg_color(&style_homepage_btn_3_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_homepage_btn_3_main_main_default, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_bg_grad_dir(&style_homepage_btn_3_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_homepage_btn_3_main_main_default, 255);
	lv_style_set_shadow_color(&style_homepage_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_homepage_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_homepage_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_homepage_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_homepage_btn_3_main_main_default, 255);
	lv_obj_add_style(ui->homepage_btn_3, &style_homepage_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->homepage_btn_3_label = lv_label_create(ui->homepage_btn_3);
	lv_label_set_text(ui->homepage_btn_3_label, "100");
	lv_obj_set_style_text_color(ui->homepage_btn_3_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->homepage_btn_3_label, &lv_font_simsun_24, LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->homepage_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->homepage_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes homepage_img_20
	ui->homepage_img_20 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_20, 415, 96);
	lv_obj_set_size(ui->homepage_img_20, 17, 15);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_20_main_main_default
	static lv_style_t style_homepage_img_20_main_main_default;
	if (style_homepage_img_20_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_20_main_main_default);
	else
		lv_style_init(&style_homepage_img_20_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_20_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_20_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_20_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_20, &style_homepage_img_20_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_20, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_20,&_percent_17x15);
	lv_img_set_pivot(ui->homepage_img_20, 0,0);
	lv_img_set_angle(ui->homepage_img_20, 0);

	//Write codes homepage_img_4
	ui->homepage_img_4 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_4, 37, 89);
	lv_obj_set_size(ui->homepage_img_4, 28, 28);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_4_main_main_default
	static lv_style_t style_homepage_img_4_main_main_default;
	if (style_homepage_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_4_main_main_default);
	else
		lv_style_init(&style_homepage_img_4_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_4_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_4, &style_homepage_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_4,&_hotend_28x28);
	lv_img_set_pivot(ui->homepage_img_4, 0,0);
	lv_img_set_angle(ui->homepage_img_4, 0);

	//Write codes homepage_img_5
	ui->homepage_img_5 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_5, 191, 89);
	lv_obj_set_size(ui->homepage_img_5, 28, 28);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_5_main_main_default
	static lv_style_t style_homepage_img_5_main_main_default;
	if (style_homepage_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_5_main_main_default);
	else
		lv_style_init(&style_homepage_img_5_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_5_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_5, &style_homepage_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_5,&_bed_28x28);
	lv_img_set_pivot(ui->homepage_img_5, 0,0);
	lv_img_set_angle(ui->homepage_img_5, 0);

	//Write codes homepage_img_6
	ui->homepage_img_6 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_6, 340, 89);
	lv_obj_set_size(ui->homepage_img_6, 28, 28);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_6_main_main_default
	static lv_style_t style_homepage_img_6_main_main_default;
	if (style_homepage_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_6_main_main_default);
	else
		lv_style_init(&style_homepage_img_6_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_6_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_6, &style_homepage_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_6,&_speed_28x28);
	lv_img_set_pivot(ui->homepage_img_6, 0,0);
	lv_img_set_angle(ui->homepage_img_6, 0);

	//Write codes homepage_img_2
	ui->homepage_img_2 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_2, 432, 13);
	lv_obj_set_size(ui->homepage_img_2, 36, 36);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_2_main_main_default
	static lv_style_t style_homepage_img_2_main_main_default;
	if (style_homepage_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_2_main_main_default);
	else
		lv_style_init(&style_homepage_img_2_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_2_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_2, &style_homepage_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_2,&_wifi03_36x36);
	lv_img_set_pivot(ui->homepage_img_2, 0,0);
	lv_img_set_angle(ui->homepage_img_2, 0);

	//Write codes homepage_img_1
	ui->homepage_img_1 = lv_img_create(ui->homepage_cont_1);
	lv_obj_set_pos(ui->homepage_img_1, 12, 20);
	lv_obj_set_size(ui->homepage_img_1, 156, 21);

	//Write style state: LV_STATE_DEFAULT for style_homepage_img_1_main_main_default
	static lv_style_t style_homepage_img_1_main_main_default;
	if (style_homepage_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_homepage_img_1_main_main_default);
	else
		lv_style_init(&style_homepage_img_1_main_main_default);
	lv_style_set_img_recolor(&style_homepage_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_homepage_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_homepage_img_1_main_main_default, 255);
	lv_obj_add_style(ui->homepage_img_1, &style_homepage_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->homepage_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->homepage_img_1,&_creality_logo_156x21);
	lv_img_set_pivot(ui->homepage_img_1, 0,0);
	lv_img_set_angle(ui->homepage_img_1, 0);

    lv_example_chart_10();
    //Init events for screen
	events_init_homepage(ui);
}
