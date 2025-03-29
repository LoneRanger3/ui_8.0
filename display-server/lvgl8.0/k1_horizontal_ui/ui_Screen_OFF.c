/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2023-01-04 17:42:33
 * @LastEditTime: 2023-02-28 11:19:10
 */
#include "ui.h"
#include "mult_language.h"

lv_obj_t * ui_Screenoff;
lv_obj_t * ui_ScreenoffPanel1;
lv_obj_t * last_screen_page;

void ui_event_Screenoff(lv_event_t * e);

void ui_Screenoff_screen_init(void)
{
    ui_Screenoff = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screenoff, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScreenoffPanel1 = lv_obj_create(lv_layer_sys());
    lv_obj_set_width(ui_ScreenoffPanel1, 800);
    lv_obj_set_height(ui_ScreenoffPanel1, 480);
    lv_obj_clear_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenoffPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenoffPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ScreenoffPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ScreenoffPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN);      /// Flags

    lv_obj_add_event_cb(ui_ScreenoffPanel1, ui_event_Screenoff, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screenoff, ui_event_Screenoff, LV_EVENT_ALL, NULL);

}

void ui_event_Screenoff(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load screen_off page");
        lv_obj_move_to_index(ui_ScreenoffPanel1, -1);
    }
    if(event_code == LV_EVENT_CLICKED) {
        CrLogI("quit screen_off page.");
        set_printer_data(0x1b,1,"2");//退出息屏
        lv_obj_add_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN);      /// Flags
        // _ui_screen_change(last_screen_page, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void enter_screenoff_mode(lv_obj_t * target)
{
    last_screen_page = target;
    // _ui_screen_change(ui_Screenoff, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    lv_obj_clear_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN);      /// Flags
}

