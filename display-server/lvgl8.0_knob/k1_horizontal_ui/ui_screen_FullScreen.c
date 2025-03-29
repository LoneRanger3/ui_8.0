#include "ui_screen_FullScreen.h"
#include "ui_screen_HomePrinting.h"
#include "../custom/lvgl_cmd.h"
#include <stdio.h>

/********full screen Page ***********/

static lv_obj_t * ui_ScreenFull;
static lv_obj_t * ui_ImageFillingChartScreenFull;
static lv_obj_t * ui_ImageMaskScreenFull;
static lv_obj_t * ui_LabelPercentFlagScreenFull;
static lv_obj_t * ui_LabelPrintProccessScreenFull;

/******************custom variable************************/
static char chart_name[256] = {0};
static uint32_t full_model_layers_count = 1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif



/********full screen Page event,can not modify ***********/
static void ui_event_ScreenFull(lv_event_t * e);
//static void ui_event_ImageFillingChartScreenFull(lv_event_t * e);


/********full screen Page event call back ***********/
//static void FullScreenClicked(lv_event_t * e);
static void OutFullScreen(lv_event_t * e);


/**************custom funs******************/
static void full_screen_show_model_mask(int proccess_percent);


void ui_event_ScreenFull(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //FullScreenClicked(e);
        OutFullScreen(e);
    }
}
// void ui_event_ImageFillingChartScreenFull(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         OutFullScreen(e);
//     }
// }

void ui_ScreenFull_screen_init(void)
{
    ui_ScreenFull = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenFull, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenFull, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenFull, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageFillingChartScreenFull = lv_img_create(ui_ScreenFull);
    lv_img_set_src(ui_ImageFillingChartScreenFull, &ui_img_crealitylogo_png);
    lv_obj_set_width(ui_ImageFillingChartScreenFull, 300);
    lv_obj_set_height(ui_ImageFillingChartScreenFull, 300);
    lv_obj_set_x(ui_ImageFillingChartScreenFull, 250);
    lv_obj_set_y(ui_ImageFillingChartScreenFull, 90);
    lv_obj_add_flag(ui_ImageFillingChartScreenFull, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFillingChartScreenFull, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageMaskScreenFull = lv_img_create(ui_ScreenFull);
    lv_obj_set_width(ui_ImageMaskScreenFull, 300);
    lv_obj_set_height(ui_ImageMaskScreenFull, 300);
    lv_obj_set_x(ui_ImageMaskScreenFull, 250);
    lv_obj_set_y(ui_ImageMaskScreenFull, 90);
    //lv_obj_set_align(ui_ImageMaskScreenFull, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageMaskScreenFull, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageMaskScreenFull, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ImageMaskScreenFull, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ImageMaskScreenFull, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelPercentFlagScreenFull = lv_label_create(ui_ScreenFull);
    lv_obj_set_width(ui_LabelPercentFlagScreenFull, 25);
    lv_obj_set_height(ui_LabelPercentFlagScreenFull, 30);
    lv_obj_set_x(ui_LabelPercentFlagScreenFull, 423);
    lv_obj_set_y(ui_LabelPercentFlagScreenFull, 410);
    //lv_obj_set_align(ui_LabelPercentFlagScreenFull, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPercentFlagScreenFull, "%");
    lv_obj_set_style_text_color(ui_LabelPercentFlagScreenFull, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelPercentFlagScreenFull, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPercentFlagScreenFull, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelPrintProccessScreenFull = lv_label_create(ui_ScreenFull);
    lv_obj_set_width(ui_LabelPrintProccessScreenFull, 60);
    lv_obj_set_height(ui_LabelPrintProccessScreenFull, 54);
    lv_obj_set_x(ui_LabelPrintProccessScreenFull, 360);
    lv_obj_set_y(ui_LabelPrintProccessScreenFull, 398);
    lv_label_set_text(ui_LabelPrintProccessScreenFull, "");
    lv_obj_set_style_text_color(ui_LabelPrintProccessScreenFull, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelPrintProccessScreenFull, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelPrintProccessScreenFull, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPrintProccessScreenFull, &ui_font_lvfontsimsun36, LV_PART_MAIN | LV_STATE_DEFAULT);

    //lv_obj_add_event_cb(ui_ImageFillingChartScreenFull, ui_event_ImageFillingChartScreenFull, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenFull, ui_event_ScreenFull, LV_EVENT_ALL, NULL);

}



void LoadFullScreenScreen(void)
{
    send_get_print_proccess();
    lv_disp_load_scr(ui_ScreenFull);
    full_screen_set_Filling_chart(chart_name);
}

// void FullScreenClicked(lv_event_t * e)
// {
// 	// Your code here
// }

void OutFullScreen(lv_event_t * e)
{
	// Your code here
    send_set_stop_fullscreen_cmd();
    LoadHomePrintingScreen();
}

void full_screen_set_print_proccess(uint16_t proccess)
{
    if ( proccess > 100 )
        proccess = 100;
    
    char buf[10] = {0};
    sprintf(buf, "%d", proccess);

    lv_label_set_text(ui_LabelPrintProccessScreenFull, buf);

    if ( lv_obj_has_flag(ui_ScreenFull, LV_OBJ_FLAG_HIDDEN) )
        return;

    full_screen_show_model_mask(proccess);
}

void full_screen_set_Filling_chart (char *png_name)
{
    if ( !png_name )
    {
        strcpy(chart_name, "");
    }
    else
        strncpy(chart_name, png_name, sizeof(chart_name) - 1);

    if ( !lv_obj_is_visible(ui_ScreenFull) )
        return;

    lv_obj_clear_flag(ui_ImageMaskScreenFull, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_width(ui_ImageMaskScreenFull, MAX_FILLINF_CHART_MASK_HEIGHT);
    lv_obj_set_height(ui_ImageMaskScreenFull, MAX_FILLINF_CHART_MASK_HEIGHT);
    if ( strlen(chart_name) <= 0 )
    {
        // use crelitylogo png
        lv_img_set_src(ui_ImageFillingChartScreenFull, &ui_img_crealitylogo_png);
        lv_img_set_src(ui_ImageMaskScreenFull, &ui_img_crealitylogo_png);
    }
    else
    {
        // use chart name file
        char buff[258] = {0};
        buff[0] = PNG_DRV_LETTER;
        strncpy(buff + 1, png_name, sizeof(buff) - 2);
        lv_img_set_src(ui_ImageFillingChartScreenFull, buff);
        lv_img_set_src(ui_ImageMaskScreenFull, buff);
    }

    // lv_obj_set_style_img_recolor(ui_ImageMaskScreenFull, lv_color_hex(0x42BDD8), 200);
    lv_obj_set_style_img_recolor(ui_ImageMaskScreenFull, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_ImageMaskScreenFull, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void full_screen_set_display_status(bool open_full_screen)
{
    if ( open_full_screen )
        LoadFullScreenScreen();
    else
        LoadHomePrintingScreen();
}

void full_screen_show_model_mask(int proccess_percent)
{
    lv_obj_clear_flag(ui_ImageMaskScreenFull, LV_OBJ_FLAG_HIDDEN);
    if ( proccess_percent > 100 )
        proccess_percent = 100;
    if ( proccess_percent < 0 )
        proccess_percent = 0;

    if ( ui_ImageMaskScreenFull && (full_model_layers_count <= 0) )
    {
        int height = ((100 - proccess_percent) * MAX_FILLINF_CHART_MASK_HEIGHT) / 100;
        lv_obj_set_height(ui_ImageMaskScreenFull, height);
    }
}

void full_screen_set_gcode_layers_count(uint32_t layer_count)
{
    if ( !layer_count )
        layer_count = 1;
    
    full_model_layers_count = layer_count;
}

void full_screen_set_gcode_cur_layer_index(uint32_t layer_index)
{
    lv_obj_clear_flag(ui_ImageMaskScreenFull, LV_OBJ_FLAG_HIDDEN);

    if ( ui_ImageMaskScreenFull && full_model_layers_count )
    {
        if ( layer_index >  full_model_layers_count )
            layer_index = full_model_layers_count;

        int height = ((full_model_layers_count - layer_index) * MAX_FILLINF_CHART_MASK_HEIGHT) / full_model_layers_count;
        lv_obj_set_height(ui_ImageMaskScreenFull, height);
    }
}