/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2023-08-23 05:48:42
 */
#ifndef _UI_SCREEN_VEDIOINFO_H
#define _UI_SCREEN_VEDIOINFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

extern lv_obj_t * ui_VedioInfo;

void ui_VedioInfo_screen_init(void);
void vedio_set_vedioinfo(int16_t vedio_index, char *file_name, char * png_name, uint64_t datetime, 
                        uint32_t vedio_time, uint8_t shoot_pos, uint16_t shoot_freq, uint8_t rendering_method);

void vedio_change_language_text(void);
void refresh_export_video_process(int process);

#ifdef __cplusplus
}
#endif

#endif