/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2023-01-31 14:02:08
 */
#ifndef _UI_CUSTOM_PRINT_HISTORY_PART_H
#define _UI_CUSTOM_PRINT_HISTORY_PART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef struct print_history_part
{
    lv_obj_t *parent;
    lv_obj_t *history_panel;
    lv_obj_t *img_thumbnail;
    lv_obj_t *label_file_name;
    lv_obj_t *label_start_time;
    lv_obj_t *label_real_totle_time;
    lv_obj_t *img_state;
    // lv_obj_t *btn_print_again;
    // lv_obj_t *lable_print_again;
    int32_t history_record_index;
}print_history_part_t;



print_history_part_t *create_custom_print_history_part(lv_obj_t *parent, int16_t pos_x, int16_t pos_y);
void destory_custom_print_history_part(print_history_part_t *part);
void history_part_set_print_record_info(print_history_part_t *part, int32_t recode_index, char *thumbnail_name, char *file_name,
                                int64_t start_time, int32_t print_used_time, bool state_ok, bool is_print_file_exsit);

void history_part_change_language_text(print_history_part_t *part);


#ifdef __cplusplus
}
#endif

#endif