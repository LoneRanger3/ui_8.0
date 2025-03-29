/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-06 16:20:41
 * @LastEditTime: 2022-12-29 09:38:12
 */
#include "ui_screen_CameraList.h"
#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>
#include "ui_screen_VedioInfo.h"
#include "custom/lvgl_cmd.h"
#include "ui_custom_reminderbox.h"
#include "ui_custom_vedioinfo_part.h"
#include "mult_language.h"

lv_obj_t * ui_Cameralist;
static lv_obj_t * ui_CameralistPanel1;
static lv_obj_t * ui_CameralistImage1;
static lv_obj_t * ui_CameralistImage2;
static lv_obj_t * ui_CameralistImage3;
static lv_obj_t * ui_CameralistImage4;
static lv_obj_t * ui_CameralistImage5;
static lv_obj_t * ui_CameralistPanel2;
static lv_obj_t * ui_CameralistPanel3;
static lv_obj_t * ui_Cameralisttitle;
static lv_obj_t * ui_CameralistLabel1;
#if 0
static lv_obj_t * ui_CameravedioList1;
static lv_obj_t * ui_CameralistLabel2;
static lv_obj_t * ui_CameralistImage6;
static lv_obj_t * ui_CameralistLabel3;
static lv_obj_t * ui_CameralistLabel4;
static lv_obj_t * ui_CameralistImage7;
static lv_obj_t * ui_CameravedioList2;
static lv_obj_t * ui_CameralistLabel5;
static lv_obj_t * ui_CameralistImage8;
static lv_obj_t * ui_CameralistLabel6;
static lv_obj_t * ui_CameralistLabel7;
static lv_obj_t * ui_CameralistImage9;
static lv_obj_t * ui_CameravedioList3;
static lv_obj_t * ui_CameralistLabel8;
static lv_obj_t * ui_CameralistImage10;
static lv_obj_t * ui_CameralistLabel9;
static lv_obj_t * ui_CameralistLabel10;
static lv_obj_t * ui_CameralistImage11;
#endif
static lv_obj_t * ui_CameralistButton_Back;
static lv_obj_t * ui_CameralistBtnlabel_Back;

/***************custom variable************************/
static uint16_t vedioes_count = 0;
static uint16_t cur_index = 0;
static int currentPage = 0;
static vedio_info_part_t *part_array[3] = {NULL};


/*****************************************/

static void ui_event_CameralistButtonBack_click(lv_event_t * e);
static void ui_event_jump_list(lv_event_t * e);

/*******************custom funs**************************/
static void get_next_page(void);
static void get_prev_page(void);

/***********************************************/

void ui_event_CameralistButtonBack_click(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_jump_list(lv_event_t * e)
{
    // lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    lv_indev_wait_release(lv_indev_get_act());
    lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
    if(dir == LV_DIR_BOTTOM) {
        get_prev_page();
    }
    else if ( dir == LV_DIR_TOP)
    {
        get_next_page();
    }
}

void ui_event_changepage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(target == ui_CameralistImage1)
        {
            if ( home_printing_is_printing_finished() )
                LoadHomeNormalScreen();
            else
                LoadHomePrintingScreen();
        }
        if(target == ui_CameralistImage2)LoadAxisMoveScreen();
        if(target == ui_CameralistImage3)LoadFileManageScreen();
        if(target == ui_CameralistImage4)LoadSettingsScreen();
        if(target == ui_CameralistImage5)LoadCustomerServiceScreen();
    }
}

void ui_Cameralist_screen_init(void)
{
    ui_Cameralist = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Cameralist, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    ui_CameralistPanel1 = lv_obj_create(ui_Cameralist);
    lv_obj_set_width(ui_CameralistPanel1, 80);
    lv_obj_set_height(ui_CameralistPanel1, 480);
    lv_obj_clear_flag(ui_CameralistPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistPanel1, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CameralistPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CameralistPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CameralistPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CameralistPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CameralistPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CameralistImage1 = lv_img_create(ui_CameralistPanel1);
    lv_img_set_src(ui_CameralistImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_CameralistImage1, 80);
    lv_obj_set_height(ui_CameralistImage1, 96);
    lv_obj_add_flag(ui_CameralistImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CameralistImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistImage1, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CameralistImage2 = lv_img_create(ui_CameralistPanel1);
    lv_img_set_src(ui_CameralistImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_CameralistImage2, 80);
    lv_obj_set_height(ui_CameralistImage2, 96);
    lv_obj_set_x(ui_CameralistImage2, 0);
    lv_obj_set_y(ui_CameralistImage2, 96);
    lv_obj_add_flag(ui_CameralistImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CameralistImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistImage2, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CameralistImage3 = lv_img_create(ui_CameralistPanel1);
    lv_img_set_src(ui_CameralistImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_CameralistImage3, 80);
    lv_obj_set_height(ui_CameralistImage3, 96);
    lv_obj_set_x(ui_CameralistImage3, 0);
    lv_obj_set_y(ui_CameralistImage3, 192);
    lv_obj_add_flag(ui_CameralistImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CameralistImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistImage3, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CameralistImage4 = lv_img_create(ui_CameralistPanel1);
    lv_img_set_src(ui_CameralistImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_CameralistImage4, 80);
    lv_obj_set_height(ui_CameralistImage4, 96);
    lv_obj_set_x(ui_CameralistImage4, 0);
    lv_obj_set_y(ui_CameralistImage4, 288);
    lv_obj_add_flag(ui_CameralistImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CameralistImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistImage4, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CameralistImage5 = lv_img_create(ui_CameralistPanel1);
    lv_img_set_src(ui_CameralistImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_CameralistImage5, 80);
    lv_obj_set_height(ui_CameralistImage5, 96);
    lv_obj_set_x(ui_CameralistImage5, 0);
    lv_obj_set_y(ui_CameralistImage5, 384);
    lv_obj_add_flag(ui_CameralistImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CameralistImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_CameralistImage5, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_CameralistImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CameralistPanel2 = lv_obj_create(ui_Cameralist);
    lv_obj_set_width(ui_CameralistPanel2, 720);
    lv_obj_set_height(ui_CameralistPanel2, 480);
    lv_obj_set_x(ui_CameralistPanel2, 80);
    lv_obj_set_y(ui_CameralistPanel2, 0);
    lv_obj_clear_flag(ui_CameralistPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CameralistPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CameralistPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CameralistPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CameralistPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CameralistPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CameralistPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CameralistPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CameralistPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CameralistPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CameralistPanel3 = lv_obj_create(ui_CameralistPanel2);
    lv_obj_set_width(ui_CameralistPanel3, 696);
    lv_obj_set_height(ui_CameralistPanel3, 456);
    lv_obj_set_align(ui_CameralistPanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_CameralistPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CameralistPanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CameralistPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CameralistPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameralistPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CameralistPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CameralistPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CameralistPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CameralistPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Cameralisttitle = lv_obj_create(ui_CameralistPanel3);
    lv_obj_set_width(ui_Cameralisttitle, 665);
    lv_obj_set_height(ui_Cameralisttitle, 65);
    lv_obj_set_x(ui_Cameralisttitle, 10);
    lv_obj_set_y(ui_Cameralisttitle, 0);
    lv_obj_clear_flag(ui_Cameralisttitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_Cameralisttitle, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_radius(ui_Cameralisttitle, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Cameralisttitle, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Cameralisttitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Cameralisttitle, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Cameralisttitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Cameralisttitle, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Cameralisttitle, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Cameralisttitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Cameralisttitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Cameralisttitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Cameralisttitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CameralistLabel1 = lv_label_create(ui_Cameralisttitle);
    lv_obj_set_width(ui_CameralistLabel1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CameralistLabel1, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_CameralistLabel1, 15);
    lv_obj_set_y(ui_CameralistLabel1, 0);
    lv_obj_set_align(ui_CameralistLabel1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_CameralistLabel1, VedioList[language_index]);
    lv_obj_clear_flag(ui_CameralistLabel1, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_text_color(ui_CameralistLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CameralistLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CameralistLabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    int8_t index = 0;
    part_array[index++] = create_custom_vedio_info_part(ui_CameralistPanel3, 0, 90);
    part_array[index++] = create_custom_vedio_info_part(ui_CameralistPanel3, 0, 208);
    part_array[index++] = create_custom_vedio_info_part(ui_CameralistPanel3, 0, 326);  

    ui_CameralistButton_Back = lv_btn_create(ui_CameralistPanel3);
    lv_obj_set_width(ui_CameralistButton_Back, 116);
    lv_obj_set_height(ui_CameralistButton_Back, 60);
    lv_obj_set_x(ui_CameralistButton_Back, 560);
    lv_obj_set_y(ui_CameralistButton_Back, 381);
    lv_obj_add_flag(ui_CameralistButton_Back, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_CameralistButton_Back, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CameralistButton_Back, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CameralistButton_Back, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CameralistButton_Back, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_CameralistButton_Back, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_CameralistButton_Back, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_CameralistButton_Back, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_CameralistButton_Back, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_CameralistButton_Back, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CameralistButton_Back, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CameralistButton_Back, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CameralistBtnlabel_Back = lv_label_create(ui_CameralistButton_Back);
    lv_obj_set_width(ui_CameralistBtnlabel_Back, lv_pct(100));
    lv_obj_set_height(ui_CameralistBtnlabel_Back, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_CameralistBtnlabel_Back, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_CameralistBtnlabel_Back, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_CameralistBtnlabel_Back, Back[language_index]);
    lv_obj_set_style_text_align(ui_CameralistBtnlabel_Back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CameralistBtnlabel_Back, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_CameralistButton_Back, ui_event_CameralistButtonBack_click, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Cameralist, ui_event_jump_list, LV_EVENT_GESTURE, NULL);
    
    lv_obj_add_flag(ui_CameralistImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CameralistImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CameralistImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CameralistImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CameralistImage5, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    lv_obj_add_event_cb(ui_CameralistImage1, ui_event_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CameralistImage2, ui_event_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CameralistImage3, ui_event_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CameralistImage4, ui_event_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CameralistImage5, ui_event_changepage, LV_EVENT_ALL, NULL);

}

void get_next_page(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( !vedioes_count )
    {
        create_custom_reminderbox(NoVedioes[language_index], false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return;
    }

    if ( cur_index >= vedioes_count )
    {
        create_custom_reminderbox(LastPageMsg[language_index], false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return ;
    }

    currentPage++;
    if(cur_index + MAX_VEDIO_INFOS_PER_PAGE <= vedioes_count)
    {
        send_get_vedio_infos_cmd(cur_index, MAX_VEDIO_INFOS_PER_PAGE);
        cur_index += MAX_VEDIO_INFOS_PER_PAGE;
    }
    else
    {
        send_get_vedio_infos_cmd(cur_index, vedioes_count - cur_index);
        cur_index += (vedioes_count - cur_index);
    }
}

void get_prev_page(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( !vedioes_count )
    {
        create_custom_reminderbox(NoVedioes[language_index], false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return;
    }

    if ( currentPage  == 0 )
    {
        create_custom_reminderbox(FirstPageMsg[language_index], false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(1, NULL);
        return ;
    }

    currentPage--;
    cur_index -= MAX_VEDIO_INFOS_PER_PAGE;
    send_get_vedio_infos_cmd(currentPage * MAX_VEDIO_INFOS_PER_PAGE, MAX_VEDIO_INFOS_PER_PAGE);
}

void cameralist_set_vedio_count(uint16_t count)
{
    vedioes_count = count;
    if ( !count )
    {
        vedioes_count = 0;
        cur_index = 0;
        //
        cameralist_set_vedioes_info(NULL, 1);

        return;
    }

    cur_index = 0;
    currentPage = 0;
    if(cur_index + MAX_VEDIO_INFOS_PER_PAGE <= vedioes_count)
    {
        send_get_vedio_infos_cmd(cur_index + 1, MAX_VEDIO_INFOS_PER_PAGE);
        cur_index += MAX_VEDIO_INFOS_PER_PAGE;
    }
    else
    {
        send_get_vedio_infos_cmd(cur_index, vedioes_count - cur_index);
        cur_index += (vedioes_count - cur_index);
    }
}


void cameralist_set_vedioes_info(print_vedio_info_t info_array[3], int real_count)
{
    if ( !info_array || real_count < 0)
        real_count = 0;

    for ( int i = 0; i < 3 ; i++ )
    {
        if ( !part_array[i] || !(part_array[i]->info_panel) )
            continue;

        if ( (i < real_count) )
        {
            lv_obj_clear_flag(part_array[i]->info_panel, LV_OBJ_FLAG_HIDDEN);
            vedio_info_part_set_vedioes_info(part_array[i], &info_array[i], currentPage * MAX_VEDIO_INFOS_PER_PAGE + i + 1);
        }
        else
        {
            lv_obj_add_flag(part_array[i]->info_panel, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void cameralist_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_CameralistBtnlabel_Back )
    {
        lv_label_set_text(ui_CameralistBtnlabel_Back, Back[language_index]);
        redefine_label_size(ui_CameralistBtnlabel_Back, lv_font24.font, 0, 0, 300, 0);
        
        lv_obj_update_layout(ui_CameralistButton_Back);
        redefine_widgets_size(ui_CameralistButton_Back, ui_CameralistBtnlabel_Back, 10, 0, 116, 60);
    }
    
    if ( ui_CameralistLabel1 )
        lv_label_set_text(ui_CameralistLabel1, VedioList[language_index]);
    
    for ( int8_t i = 0; i < 3; i++ )
        vedio_info_change_language_text(part_array[i]);

    vedio_change_language_text();
}
