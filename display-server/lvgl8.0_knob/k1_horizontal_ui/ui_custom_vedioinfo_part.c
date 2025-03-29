/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-07 13:51:59
 * @LastEditTime: 2023-10-22 23:41:19
 */
#include "ui_custom_vedioinfo_part.h"
#include "src/core/lv_obj_pos.h"
#include "ui.h"
#include "ui_helpers.h"
#include "ui_screen_VedioInfo.h"
#include <stdio.h>
#include <time.h>
#include "mult_language.h"

#define IMG_SIZE 76

/************************************/


vedio_info_part_t *create_custom_vedio_info_part(lv_obj_t *parent, void (*part_event_callback)(lv_event_t *))
{
    vedio_info_part_t *part = (vedio_info_part_t *)lv_mem_alloc(sizeof(vedio_info_part_t));
    if ( !part )
        return;

    uint8_t language_index = get_cur_language_index();
    lv_obj_t *ui_vedio_info_panel= lv_obj_create(parent);
    part->parent = parent;
    part->info_panel = ui_vedio_info_panel;
    lv_obj_set_width(ui_vedio_info_panel, 523);
    lv_obj_set_height(ui_vedio_info_panel, 104);
    // lv_obj_set_x(ui_vedio_info_panel, pos_x);
    // lv_obj_set_y(ui_vedio_info_panel, pos_y);
     lv_obj_add_flag(ui_vedio_info_panel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);  
    lv_obj_clear_flag(ui_vedio_info_panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_vedio_info_panel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_vedio_info_panel, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_vedio_info_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_vedio_info_panel, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_vedio_info_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_vedio_info_panel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_border_side(ui_vedio_info_panel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_vedio_info_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中样式
    lv_obj_set_style_bg_color(ui_vedio_info_panel, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_bg_opa(ui_vedio_info_panel, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(ui_vedio_info_panel, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(ui_vedio_info_panel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_vedio_info_panel, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_vedio_info_panel, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
     lv_obj_set_style_pad_all(ui_vedio_info_panel, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
   // lv_obj_set_style_border_side(ui_vedio_info_panel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    char buff[30] = {0};
    lv_obj_t *ui_label_file_name = lv_label_create(ui_vedio_info_panel);
    part->label_file_name = ui_label_file_name;
    lv_obj_set_width(ui_label_file_name, 160);   /// 150
    lv_obj_set_height(ui_label_file_name, 30);    /// 28
    lv_obj_set_x(ui_label_file_name, 117);
    lv_obj_set_y(ui_label_file_name, 2);
    lv_label_set_long_mode(ui_label_file_name, LV_LABEL_LONG_SCROLL);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", FileNameArray[language_index]);
    lv_label_set_text(ui_label_file_name, buff);
    lv_obj_set_style_text_color(ui_label_file_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_label_file_name, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_label_file_name, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_label_file_name, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_label_file_nameValue = lv_label_create(ui_vedio_info_panel);
    part->label_file_name_value = ui_label_file_nameValue;
    lv_obj_set_width(ui_label_file_nameValue, 480);   /// 150  //为了显示的整齐性，将文件名称标题隐藏，将值label320扩大为480
    lv_obj_set_height(ui_label_file_nameValue, 30);    /// 28
   // lv_obj_set_x(ui_label_file_nameValue, 117);    //为了显示的整齐性，将文件名称标题隐藏，将值label坐标300前移为132
   // lv_obj_set_y(ui_label_file_nameValue, 2);
    lv_obj_align(ui_label_file_nameValue, LV_ALIGN_TOP_LEFT, 117, 2);
    lv_label_set_long_mode(ui_label_file_nameValue, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_label_file_nameValue, "");
    lv_obj_set_style_text_color(ui_label_file_nameValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_label_file_nameValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_label_file_nameValue, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_label_file_nameValue, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_img_vedio = lv_img_create(ui_vedio_info_panel);
    part->img_vedio_thumbnail = ui_img_vedio;
    lv_obj_set_pos(ui_img_vedio, 8, 2);
    lv_obj_set_width(ui_img_vedio, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_img_vedio, LV_SIZE_CONTENT);    /// 1
    lv_obj_add_flag(ui_img_vedio, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_img_vedio, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t *ui_label_vedio_time = lv_label_create(ui_vedio_info_panel);
    part->label_vedio_time = ui_label_vedio_time;
    lv_obj_set_width(ui_label_vedio_time, LV_SIZE_CONTENT);   /// 150
    lv_obj_set_height(ui_label_vedio_time, 30);    /// 28
    // lv_obj_set_x(ui_label_vedio_time, 132);
    // lv_obj_set_y(ui_label_vedio_time, 0);
    // lv_obj_set_align(ui_label_vedio_time, LV_ALIGN_LEFT_MID);
    lv_obj_align(ui_label_vedio_time, LV_ALIGN_LEFT_MID, 117, 1);
    lv_label_set_long_mode(ui_label_vedio_time, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", VedioTime[language_index]);
    lv_label_set_text(ui_label_vedio_time, buff);
    lv_obj_set_style_text_color(ui_label_vedio_time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_label_vedio_time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_label_vedio_time, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_label_vedio_time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_label_vedio_time_value = lv_label_create(ui_vedio_info_panel);
    part->label_vedio_time_value = ui_label_vedio_time_value;
    lv_obj_set_width(ui_label_vedio_time_value, 300);   /// 150
    lv_obj_set_height(ui_label_vedio_time_value, 30);    /// 28
    // lv_obj_set_x(ui_label_vedio_time_value, 300);
    // lv_obj_set_y(ui_label_vedio_time_value, 0);
    lv_obj_align_to(ui_label_vedio_time_value, ui_label_vedio_time, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_label_set_long_mode(ui_label_vedio_time_value, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_label_vedio_time_value, "");
    lv_obj_set_style_text_color(ui_label_vedio_time_value, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_label_vedio_time_value, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_label_vedio_time_value, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_label_vedio_time_value, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_label_print_datetime = lv_label_create(ui_vedio_info_panel);
    part->label_start_datetime = ui_label_print_datetime;
    lv_obj_set_width(ui_label_print_datetime, LV_SIZE_CONTENT);   /// 150
    lv_obj_set_height(ui_label_print_datetime, 30);    /// 28
    // lv_obj_set_x(ui_label_print_datetime, 117);
    // lv_obj_set_y(ui_label_print_datetime, 0);
    // lv_obj_set_align(ui_label_print_datetime, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_align(ui_label_print_datetime, LV_ALIGN_BOTTOM_LEFT, 117, 0);
    lv_label_set_long_mode(ui_label_print_datetime, LV_LABEL_LONG_SCROLL);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", PrintDatetime[language_index]);
    lv_label_set_text(ui_label_print_datetime, buff);
    lv_obj_set_style_text_color(ui_label_print_datetime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_label_print_datetime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_label_print_datetime, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_label_print_datetime, LV_TEXT_ALIGN_LEFT,LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_label_print_datetime_value = lv_label_create(ui_vedio_info_panel);
    part->label_start_datetime_value = ui_label_print_datetime_value;
    lv_obj_set_width(ui_label_print_datetime_value, 300);   /// 150
    lv_obj_set_height(ui_label_print_datetime_value, 30);    /// 28
    // lv_obj_set_x(ui_label_print_datetime_value, 285);
    // lv_obj_set_y(ui_label_print_datetime_value, 0);
    lv_obj_align_to(ui_label_print_datetime_value, ui_label_print_datetime, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    //lv_obj_set_align(ui_label_print_datetime_value, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_long_mode(ui_label_print_datetime_value, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_label_print_datetime_value, "");
    lv_obj_set_style_text_color(ui_label_print_datetime_value, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_label_print_datetime_value, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_label_print_datetime_value, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_label_print_datetime_value, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_img_to_preview = lv_img_create(ui_vedio_info_panel);
    part->img_to_preview = ui_img_to_preview;
    lv_img_set_src(ui_img_to_preview, &ui_img_vector_24_png);
    lv_obj_set_width(ui_img_to_preview, 14);   /// 1
    lv_obj_set_height(ui_img_to_preview, 28);    /// 1
    lv_obj_set_x(ui_img_to_preview, -16);
    lv_obj_set_y(ui_img_to_preview, 0);
    lv_obj_set_align(ui_img_to_preview, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_img_to_preview, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_img_to_preview, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(part->info_panel, part_event_callback, LV_EVENT_ALL, part);

    /*****************隐藏部分控件*************************/
    lv_obj_add_flag(part->label_file_name, LV_OBJ_FLAG_HIDDEN);
    
    return part;
}

void destory_custom_vedio_info_part(vedio_info_part_t * part)
{
    if ( !part )
        return;
    
    if ( part->info_panel )
        lv_obj_del(part->info_panel);
    
    lv_memset_00(part, sizeof(vedio_info_part_t));
    lv_mem_free(part);
}

void vedio_info_part_set_vedioes_info(vedio_info_part_t * part, print_vedio_info_t *info, uint16_t print_vedio_index)
{
    if ( !part  )
        return;

    part->vedio_index = print_vedio_index;
    if ( !info )
    {
        if ( part->label_file_name_value )
            lv_label_set_text(part->label_file_name_value, "");
        
        if ( part->label_start_datetime_value )
            lv_label_set_text(part->label_start_datetime_value, "");

        if ( part->label_vedio_time_value )
            lv_label_set_text(part->label_vedio_time_value, "");
        
        // if ( part->img_vedio_thumbnail )
        //     lv_img_set_src(part->img_vedio_thumbnail, "");
        
        part->used_time = 0;
        part->shoot_pos = 0;
        part->shoot_freq = 0;
        part->render_photoes = 0;
        part->vedio_shoot_datetime = 0;
        part->vedio_total_time = 0;
        memset(part->vedio_thumbnail_name, 0, sizeof(part->vedio_thumbnail_name));
    }
    else
    {
        if (part->label_file_name_value )
        {
            char *filename = strrchr(info->vedio_name, '/');

            if (filename) {
                filename++;
                char newfilename[64];
                strncpy(newfilename, filename, sizeof(newfilename));
                lv_label_set_text(part->label_file_name_value, newfilename);

            }
        }      
        
        char buff[20] = {0};
        time_t timesteamp = (time_t)info->print_datetime;//atol(dirent_array[i].dir_create_time);
        struct tm *CurTime = localtime(&timesteamp);
                snprintf(buff , sizeof(buff) ,"%d/%02d/%02d %02d:%02d",
                                    CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
                                    CurTime->tm_hour, CurTime->tm_min);
        if ( part->label_start_datetime_value )
            lv_label_set_text(part->label_start_datetime_value, buff);

        memset(buff, 0, sizeof(buff));
        if(info->vedio_total_time / 60 == 0)
            sprintf(buff, "%ds", info->vedio_total_time);
        else
            sprintf(buff, "%dm%02ds", info->vedio_total_time / 60, info->vedio_total_time % 60);
        if ( part->label_vedio_time_value )
            lv_label_set_text(part->label_vedio_time_value, buff);
        
        if ( part->img_vedio_thumbnail )
        {
            char buff[258] = {0};
            snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, info->vedio_img_name);
            lv_img_set_src(part->img_vedio_thumbnail, buff);
            lv_obj_update_layout(part->img_vedio_thumbnail);

            int width = lv_obj_get_width(part->img_vedio_thumbnail);
            int height = lv_obj_get_height(part->img_vedio_thumbnail);
            if(width > 0 && height > 0)//1280*720
            {
                int len = width > height ? width : height;//用长边做缩放
                int scale = 256 * 92 / len;//缩略图为92
                CrLogI("delay vedio img width: %d,height:%d, scale:%d", width, height, scale);
                lv_img_set_zoom(part->img_vedio_thumbnail, scale);

            }
            else
            {
                CrLogW("delay vedio img width: %d,height:%d", width, height);
            }
        }

        part->used_time = info->used_time;
        part->render_photoes = info->render_photoes;
        part->shoot_freq = info->shoot_freq;
        part->shoot_pos = info->shoot_pos;
        part->vedio_shoot_datetime = info->print_datetime;
        part->vedio_total_time = info->vedio_total_time;
        strncpy(part->vedio_thumbnail_name, info->vedio_img_name, sizeof(part->vedio_thumbnail_name));
    }

}

void part_clicked(vedio_info_part_t *part)
{
    if ( part )
    {
        vedio_set_vedioinfo(part->vedio_index, lv_label_get_text(part->label_file_name_value), 
                            part->vedio_thumbnail_name, part->vedio_shoot_datetime,
                            part->vedio_total_time, part->shoot_pos, part->shoot_freq,
                            part->render_photoes);
    }
}

void vedio_info_change_language_text(vedio_info_part_t *part)
{
    if ( !part )
        return ;

    uint8_t language_index = get_cur_language_index();
    char buff[30] = {0};
    if ( part->label_file_name )
    {
        sprintf(buff, "%s:", FileNameArray[language_index]);
        lv_label_set_text(part->label_file_name, buff);
    }

    if ( part->label_vedio_time )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", VedioTime[language_index]);
        lv_label_set_text(part->label_vedio_time, buff);
      //  redefine_label_size(part->label_vedio_time, lv_font22.font, 0, 0, 300, 0);
        lv_obj_align_to(part->label_vedio_time_value, part->label_vedio_time, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    }

    if ( part->label_start_datetime )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s:", PrintDatetime[language_index]);
        lv_label_set_text(part->label_start_datetime, buff);
        //redefine_label_size(part->label_start_datetime, lv_font22.font, 0, 0, 300, 0);
        lv_obj_align_to(part->label_start_datetime_value, part->label_start_datetime, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    }

}