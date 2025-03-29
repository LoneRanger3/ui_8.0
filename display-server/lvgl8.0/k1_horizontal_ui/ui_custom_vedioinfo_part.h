/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-07 13:51:57
 * @LastEditTime: 2022-12-28 11:08:14
 */

#ifndef _UI_CUSTOM_VEDIOINFO_PART_H
#define _UI_CUSTOM_VEDIOINFO_PART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "ui_screen_CameraList.h"

typedef struct vedio_info_part
{
    lv_obj_t *parent;
    lv_obj_t *info_panel;
    lv_obj_t *img_vedio_thumbnail;
    lv_obj_t *label_file_name;
    lv_obj_t *label_file_name_value;
    lv_obj_t *label_start_datetime;
    lv_obj_t *label_start_datetime_value;
    lv_obj_t *label_used_time;
    lv_obj_t *label_used_time_value;
    lv_obj_t *img_to_preview;
    int16_t  vedio_index;
    char     vedio_thumbnail_name[256];
    uint32_t used_time;
    uint64_t vedio_shoot_datetime;
    uint32_t vedio_total_time;
    uint8_t  shoot_pos;
    uint8_t  shoot_freq;  //shoot_interval_layers
    uint16_t render_photoes;   //
}vedio_info_part_t;

vedio_info_part_t *create_custom_vedio_info_part(lv_obj_t *parent, int16_t pos_x, int16_t pos_y);
void destory_custom_vedio_info_part(vedio_info_part_t * part);
void vedio_info_part_set_vedioes_info(vedio_info_part_t * part, print_vedio_info_t *info, uint16_t print_vedio_index);

void vedio_info_change_language_text(vedio_info_part_t *part);

#ifdef __cplusplus
}
#endif

#endif