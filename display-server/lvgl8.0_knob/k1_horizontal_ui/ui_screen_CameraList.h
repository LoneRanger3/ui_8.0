/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-06 16:20:37
 * @LastEditTime: 2022-12-28 11:32:05
 */
#ifndef _UI_SCREEN_CAMERALIST_H
#define _UI_SCREEN_CAMERALIST_H


#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

#define MAX_VEDIO_INFOS_PER_PAGE 3

typedef struct print_vedio_info
{
    char        vedio_name[256];
    char        vedio_img_name[256];
    uint32_t    used_time;
    uint32_t    vedio_total_time;
    uint64_t    print_datetime;
    uint8_t     shoot_pos;
    uint8_t     shoot_freq;  //shoot_interval_layers
    uint16_t    render_photoes;   //没多少张图片进行一次渲染
}print_vedio_info_t;


extern lv_obj_t * ui_Cameralist;
void ui_Cameralist_screen_init(void);
void cameralist_set_vedio_count(uint16_t count);
void cameralist_set_vedioes_info(print_vedio_info_t info_array[3], int real_count);

void cameralist_change_language_text(void);

#ifdef __cplusplus
}
#endif

#endif