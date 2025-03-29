#include "ui_custom_print_history_part.h"
#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>
#include <time.h>
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"
#include "ui_screen_HomePrinting.h"
#include "../custom/lvgl_cmd.h"
#include "mult_language.h"

static void HistoryPagePrintAgainBtnClicked(lv_event_t * e);
static void ui_event_ButtonPrintAgain(lv_event_t * e);
static void history_part_set_print_file(char *file_name);
//static void history_send_print_file_cmd(int32_t record_index);

void ui_event_ButtonPrintAgain(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HistoryPagePrintAgainBtnClicked(e);
    }
}

print_history_part_t *create_custom_print_history_part(lv_obj_t *parent, int16_t pos_x, int16_t pos_y)
{
    print_history_part_t *part = (print_history_part_t *)lv_mem_alloc(sizeof(print_history_part_t));
    if ( !part )
        return NULL;

    lv_obj_t *ui_PanelHistoryColumn = lv_obj_create(parent);
    lv_obj_set_width(ui_PanelHistoryColumn, 696);
    lv_obj_set_height(ui_PanelHistoryColumn, 96);
    lv_obj_set_x(ui_PanelHistoryColumn, pos_x);
    lv_obj_set_y(ui_PanelHistoryColumn, pos_y);
    lv_obj_clear_flag(ui_PanelHistoryColumn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelHistoryColumn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHistoryColumn, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHistoryColumn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelHistoryColumn, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->parent = parent;
    part->history_panel = ui_PanelHistoryColumn;

    lv_obj_t *ui_ImageHistoryThumbnail = lv_img_create(ui_PanelHistoryColumn);
    lv_obj_set_width(ui_ImageHistoryThumbnail, 96);
    lv_obj_set_height(ui_ImageHistoryThumbnail, 96);
    lv_obj_set_x(ui_ImageHistoryThumbnail, -22);
    lv_obj_set_y(ui_ImageHistoryThumbnail, -22);
    lv_obj_add_flag(ui_ImageHistoryThumbnail, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHistoryThumbnail, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    part->img_thumbnail = ui_ImageHistoryThumbnail;

    lv_obj_t *ui_LabelHistoryFileName = lv_label_create(ui_PanelHistoryColumn);
    lv_obj_set_width(ui_LabelHistoryFileName, 200);
    lv_obj_set_height(ui_LabelHistoryFileName, 36);
    lv_obj_set_x(ui_LabelHistoryFileName, 78);    //不变
    lv_obj_set_y(ui_LabelHistoryFileName, 8);
    lv_label_set_long_mode(ui_LabelHistoryFileName, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_LabelHistoryFileName, "");
    lv_obj_set_style_text_color(ui_LabelHistoryFileName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHistoryFileName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHistoryFileName, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_file_name = ui_LabelHistoryFileName;

    lv_obj_t *ui_LabelHistoryStartTime = lv_label_create(ui_PanelHistoryColumn);
    lv_obj_set_width(ui_LabelHistoryStartTime, 180);
    lv_obj_set_height(ui_LabelHistoryStartTime, 36);
    lv_obj_set_x(ui_LabelHistoryStartTime, 280);  // 236 + 100
    lv_obj_set_y(ui_LabelHistoryStartTime, 8);
    lv_label_set_long_mode(ui_LabelHistoryStartTime, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelHistoryStartTime, "");
    lv_obj_set_style_text_color(ui_LabelHistoryStartTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHistoryStartTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHistoryStartTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHistoryStartTime, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_start_time = ui_LabelHistoryStartTime;

    lv_obj_t *ui_LabelHistoryTotleTime = lv_label_create(ui_PanelHistoryColumn);
    lv_obj_set_width(ui_LabelHistoryTotleTime, 120);
    lv_obj_set_height(ui_LabelHistoryTotleTime, 36);
    lv_obj_set_x(ui_LabelHistoryTotleTime, 464);   //368 + 100
    lv_obj_set_y(ui_LabelHistoryTotleTime, 8);
    lv_label_set_long_mode(ui_LabelHistoryTotleTime, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelHistoryTotleTime, "");
    lv_obj_set_style_text_color(ui_LabelHistoryTotleTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHistoryTotleTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHistoryTotleTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHistoryTotleTime, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_real_totle_time = ui_LabelHistoryTotleTime;

    lv_obj_t *ui_ImageStatus = lv_img_create(ui_PanelHistoryColumn);
    lv_img_set_src(ui_ImageStatus, &ui_img_cross_png);
    lv_obj_set_width(ui_ImageStatus, 30);
    lv_obj_set_height(ui_ImageStatus, 30);
    lv_obj_set_x(ui_ImageStatus, 610);   //514
    lv_obj_set_y(ui_ImageStatus, 11);
    lv_obj_add_flag(ui_ImageStatus, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    part->img_state = ui_ImageStatus;

    // lv_obj_t *ui_ButtonPrintAgain = lv_btn_create(ui_PanelHistoryColumn);
    // lv_obj_set_width(ui_ButtonPrintAgain, 100);
    // lv_obj_set_height(ui_ButtonPrintAgain, 50);
    // lv_obj_set_x(ui_ButtonPrintAgain, 571);
    // lv_obj_set_y(ui_ButtonPrintAgain, 0);
    // lv_obj_add_flag(ui_ButtonPrintAgain, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_ButtonPrintAgain, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_ButtonPrintAgain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ButtonPrintAgain, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonPrintAgain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_ButtonPrintAgain, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_ButtonPrintAgain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_ButtonPrintAgain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_ofs_x(ui_ButtonPrintAgain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_ofs_y(ui_ButtonPrintAgain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_color(ui_ButtonPrintAgain, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ButtonPrintAgain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_ButtonPrintAgain, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_color(ui_ButtonPrintAgain, lv_color_hex(0x4190A2),
    //                               LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_ButtonPrintAgain, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_ButtonPrintAgain, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    // part->btn_print_again = ui_ButtonPrintAgain;

    // lv_obj_t *ui_LabelPrintAgain = lv_label_create(ui_ButtonPrintAgain);
    // lv_obj_set_width(ui_LabelPrintAgain, 96);
    // lv_obj_set_height(ui_LabelPrintAgain, 30);
    // lv_obj_set_x(ui_LabelPrintAgain, -18);
    // lv_obj_set_y(ui_LabelPrintAgain, 0);
    // lv_label_set_long_mode(ui_LabelPrintAgain, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_LabelPrintAgain, PrintAgain[get_cur_language_index()]);
    // lv_obj_set_style_text_align(ui_LabelPrintAgain, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_LabelPrintAgain, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // part->lable_print_again = ui_LabelPrintAgain;

    part->history_record_index = 0;

    lv_obj_add_event_cb(part->history_panel, ui_event_ButtonPrintAgain, LV_EVENT_ALL, part);

    return part;
}

void HistoryPagePrintAgainBtnClicked(lv_event_t * e)
{
    if(print_state != 1)
    {
        CrLogI("history page:machine state is print %d,don't start the print",print_state);
        create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
        return;
    }
	// Your code here
    if ( e )
    {
        uint8_t index = get_cur_language_index();
        print_history_part_t *part = lv_event_get_user_data(e);
        if ( !part )
            return ;
        
        if ( part->history_record_index <= 0 )
        {
            char *btns[1] = {Confirm[index]};
            void (*btns_array[1])(void) = {NULL}; 
            create_custom_messagebox(Warning[index], RecordIndexTipsMsg[index], btns, btns_array, 1, true, false);

            return ;
        }

        //history_send_print_file_cmd(part->history_record_index);
        // send_set_print_start_cmd(part->history_record_index, true, false);
        // LoadHomePrintingScreen();
        // if ( part->label_file_name )
        //     history_part_set_print_file(lv_label_get_text(part->label_file_name));
        // else
        //     history_part_set_print_file("");
        char sendbuff[32] = {0};
        snprintf(sendbuff, 32, "22\t%d", part->history_record_index);
        get_printer_data(CONTROL_FILE, strlen(sendbuff), sendbuff);
        CrLogI("send the history index to print");
    }
}


void destory_custom_print_history_part(print_history_part_t *part)
{
    if ( !part )
        return ;
    
    if ( part->history_panel )
        lv_obj_del(part->history_panel);
    
    lv_memset_00(part, sizeof(print_history_part_t));
    lv_mem_free(part);
}

void history_part_set_print_record_info(print_history_part_t *part, int32_t recode_index, char *thumbnail_name, char *file_name,
                                int64_t start_time, int32_t print_used_time, bool state_ok, bool is_print_file_exsit)
{
    if ( !part )
        return;

    part->history_record_index = recode_index;
    CrLogI("recode_index :%d",recode_index);
    if ( part->label_file_name )
        if (  file_name && (strlen(file_name) > 0) )
        {
            char *ch = strrchr(file_name, '.');
            if ( ch )
                *ch = '\0';
                
            lv_label_set_text(part->label_file_name, file_name);
        }
        else
            lv_label_set_text(part->label_file_name, "");

    
    if ( part->img_thumbnail )
    {
        if ( !thumbnail_name || strlen(thumbnail_name) <= 0 )
            lv_img_set_src(part->img_thumbnail, &ui_img_crealitylogo96_png); 
        else
        {
            char buff[258] = {0};
            snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, thumbnail_name);
            lv_img_set_src(part->img_thumbnail, buff);
        }

    }

    if ( part->label_real_totle_time )
    {
        int32_t time = print_used_time / 60; // trans to minter
        char buff[20] = {0};
        sprintf(buff, "%dh%0dm", time / 60, time % 60);
        lv_label_set_text(part->label_real_totle_time, buff);
    }
    
    if (part->img_state)
        lv_img_set_src(part->img_state, state_ok ? &ui_img_hook_png : &ui_img_cross_png);

    if ( part->history_panel )
    {
        // if ( is_print_file_exsit )
        // {
        //     lv_obj_add_flag(part->history_panel, LV_OBJ_FLAG_CLICKABLE);
        // }
        // else
        // {
        //     lv_obj_clear_flag(part->history_panel, LV_OBJ_FLAG_CLICKABLE);
        // }
    }

    if ( part->label_start_time )
    {
        time_t timesteamp = (time_t)start_time;//atol(start_time);
        struct tm *CurTime = localtime(&timesteamp);
        char timepath[20] = {0};
        snprintf(timepath , sizeof(timepath) ,"%d/%02d/%02d %02d:%02d",
                                    CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
                                    CurTime->tm_hour, CurTime->tm_min);
        lv_label_set_text(part->label_start_time, timepath);   //打印时间
    }

    // if ( part->btn_print_again )
    //     if ( is_print_file_exsit )
    //         lv_obj_add_flag(part->btn_print_again, LV_OBJ_FLAG_CLICKABLE);
    //     else
    //         lv_obj_clear_flag(part->btn_print_again, LV_OBJ_FLAG_CLICKABLE);

    return ;
}

void history_part_set_print_file(char *file_name)
{
    home_printing_set_print_file_name(file_name);
}

void history_part_change_language_text(print_history_part_t *part)
{
    // if ( !part || part->lable_print_again )
    //     lv_label_set_text(part->lable_print_again, PrintAgain[get_cur_language_index()]);
}
