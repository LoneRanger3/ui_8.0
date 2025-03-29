/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-21 13:45:49
 * @LastEditTime: 2023-03-20 20:16:54
 */
#include "ui_custom_print_opt_screen.h"
#include "ui.h"
#include "mult_language.h"

static lv_obj_t * print_opt_screen = NULL;
static lv_obj_t * ui_LabelTitle;
static lv_obj_t * ui_LabelOpt;
static lv_obj_t * ui_LabelStop;
static lv_obj_t * ui_LabelBack;
static lv_obj_t * ui_ButtonOpt;
static lv_obj_t * ui_ButtonStop;
static lv_obj_t * ui_ButtonBack;
static bool is_pause_opt  = false;

static void close_print_opt_screen();
static void btn_opt_click_event_handler(lv_event_t * e);
static void btn_stop_click_event_handler(lv_event_t * e);
static void btn_back_click_event_handler(lv_event_t * e);
static void (*print_opt_callback)(void) = NULL;
static void (*print_stop_callback)(void) = NULL;

void close_print_opt_screen()
{
    lv_obj_add_flag(print_opt_screen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_opa(lv_layer_top(), 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(print_opt_screen, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(print_opt_screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void btn_opt_click_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            close_print_opt_screen();
            if ( print_opt_callback )
                print_opt_callback();
        }
        break;
        default:
		break;
	}
}

void btn_stop_click_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            close_print_opt_screen();
            if ( print_stop_callback )
                print_stop_callback();
        }
        break;
        default:
		break;
	}
}

void btn_back_click_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            close_print_opt_screen();
        }
        break;
        default:
		break;
	}
}

void create_custom_print_opt_screen(bool is_pause_action, void(*opt_callback)(void)
        , void(*stop_callback)(void))
{
    ///////////////////// VARIABLES ////////////////////
    if ( print_opt_screen == NULL )
    {
        lv_obj_t * ui_PanelScreen;
        ui_PanelScreen = lv_obj_create(lv_layer_top());
        print_opt_screen = ui_PanelScreen;
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_width(ui_PanelScreen, 800);
        lv_obj_set_height(ui_PanelScreen, 480);
        lv_obj_set_align(ui_PanelScreen, LV_ALIGN_CENTER);
        lv_obj_clear_flag(ui_PanelScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_PanelScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_PanelScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_PanelScreen, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_PanelScreen, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_LabelTitle = lv_label_create(print_opt_screen);
        lv_obj_set_width(ui_LabelTitle, LV_SIZE_CONTENT);
        lv_obj_set_height(ui_LabelTitle, LV_SIZE_CONTENT);
        lv_obj_align(ui_LabelTitle, LV_ALIGN_TOP_MID, 0, 81);
        lv_obj_set_style_text_color(ui_LabelTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_LabelTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_LabelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_LabelTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);        

        ui_ButtonOpt = lv_btn_create(print_opt_screen);
        lv_obj_set_width(ui_ButtonOpt, 146);
        lv_obj_set_height(ui_ButtonOpt, 60);
        lv_obj_align(ui_ButtonOpt, LV_ALIGN_TOP_MID, 0, 163);
        lv_obj_add_flag(ui_ButtonOpt, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ButtonOpt, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_ButtonOpt, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_ButtonOpt, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ButtonOpt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ButtonOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ButtonOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_ButtonOpt, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_color(ui_ButtonOpt, lv_color_hex(0x42BDD8),
                                    LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_opa(ui_ButtonOpt, 255, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_width(ui_ButtonOpt, 2, LV_PART_MAIN | LV_STATE_PRESSED);

        ui_LabelOpt = lv_label_create(ui_ButtonOpt);
        lv_obj_set_width(ui_LabelOpt, 110);
        lv_obj_set_height(ui_LabelOpt, 35);
        lv_obj_set_align(ui_LabelOpt, LV_ALIGN_CENTER);
        lv_label_set_long_mode(ui_LabelOpt, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_font(ui_LabelOpt, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(ui_LabelOpt, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_align(ui_LabelOpt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ButtonStop = lv_btn_create(print_opt_screen);
        lv_obj_set_width(ui_ButtonStop, 146);
        lv_obj_set_height(ui_ButtonStop, 60);
        lv_obj_align(ui_ButtonStop, LV_ALIGN_TOP_MID, 0, 266);
        lv_obj_add_flag(ui_ButtonStop, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ButtonStop, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_ButtonStop, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_ButtonStop, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ButtonStop, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ButtonStop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ButtonStop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_ButtonStop, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_color(ui_ButtonStop, lv_color_hex(0x42BDD8),
                                    LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_opa(ui_ButtonStop, 255, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_width(ui_ButtonStop, 2, LV_PART_MAIN | LV_STATE_PRESSED);

        ui_LabelStop = lv_label_create(ui_ButtonStop);
        lv_obj_set_width(ui_LabelStop, 110);
        lv_obj_set_height(ui_LabelStop, 35);
        lv_obj_set_align(ui_LabelStop, LV_ALIGN_CENTER);
        lv_label_set_long_mode(ui_LabelStop, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_font(ui_LabelStop, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(ui_LabelStop, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_align(ui_LabelStop, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        

        // ui_ButtonBack = lv_btn_create(print_opt_screen);
        // lv_obj_set_width(ui_ButtonBack, 146);
        // lv_obj_set_height(ui_ButtonBack, 60);
        // lv_obj_set_x(ui_ButtonBack, 103);
        // lv_obj_set_y(ui_ButtonBack, 280);
        // lv_obj_add_flag(ui_ButtonBack, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        // lv_obj_clear_flag(ui_ButtonBack, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        // lv_obj_set_style_radius(ui_ButtonBack, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_obj_set_style_bg_color(ui_ButtonBack, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_obj_set_style_bg_opa(ui_ButtonBack, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_obj_set_style_shadow_width(ui_ButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_obj_set_style_shadow_spread(ui_ButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_obj_set_style_border_side(ui_ButtonBack, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
        // lv_obj_set_style_border_color(ui_ButtonBack, lv_color_hex(0x42BDD8),
        //                             LV_PART_MAIN | LV_STATE_PRESSED);
        // lv_obj_set_style_border_opa(ui_ButtonBack, 255, LV_PART_MAIN | LV_STATE_PRESSED);
        // lv_obj_set_style_border_width(ui_ButtonBack, 2, LV_PART_MAIN | LV_STATE_PRESSED);

        // ui_LabelBack = lv_label_create(ui_ButtonBack);
        // lv_obj_set_width(ui_LabelBack, 110);
        // lv_obj_set_height(ui_LabelBack, 35);
        // lv_obj_set_align(ui_LabelBack, LV_ALIGN_CENTER);
        // lv_label_set_long_mode(ui_LabelBack, LV_LABEL_LONG_SCROLL_CIRCULAR);
        // lv_obj_set_style_text_font(ui_LabelBack, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_label_set_long_mode(ui_LabelBack, LV_LABEL_LONG_SCROLL_CIRCULAR);
        // lv_obj_set_style_text_align(ui_LabelBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        
        
        lv_obj_add_event_cb(ui_ButtonOpt, btn_opt_click_event_handler, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(ui_ButtonStop, btn_stop_click_event_handler, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(print_opt_screen, btn_back_click_event_handler, LV_EVENT_ALL, NULL);

    }
    else
    {
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    }

    uint8_t language_index = get_cur_language_index();
    if ( is_pause_action )
    {
        lv_label_set_text(ui_LabelOpt, Pause[language_index]);
    }
    else
    {
        lv_label_set_text(ui_LabelOpt, Resume[language_index]);
    }

    lv_label_set_text(ui_LabelStop, Stop[language_index]);
    // lv_label_set_text(ui_LabelBack, Back[language_index]);
    lv_label_set_text(ui_LabelTitle, PrintActionTipTitle[language_index]);

    is_pause_opt = is_pause_action;
    print_stop_callback = stop_callback;
    print_opt_callback = opt_callback;

    lv_obj_set_style_bg_color(lv_layer_top(), lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_layer_top(), 204, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(print_opt_screen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(print_opt_screen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  
    lv_obj_clear_flag(print_opt_screen, LV_OBJ_FLAG_HIDDEN);  
}