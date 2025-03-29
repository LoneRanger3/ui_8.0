/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-08 11:17:27
 * @LastEditTime: 2022-12-28 15:14:39
 */
#ifndef _UI_SCREEN_CAMERA_SETTINGS_H
#define _UI_SCREEN_CAMERA_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#define MAX_SHOOT_FREQ  100
#define MAX_RENDER_METHOD_PHOTOES 100


extern lv_obj_t * ui_camerasetting;
void ui_camerasetting_screen_init(void);
void camera_settings_set_shoot_pos(uint8_t pos);
void camera_settings_set_shoot_freq(uint8_t freq);
void camera_settings_set_delayed_photography(bool opened);
void camera_settings_set_rendering_method(uint8_t photoes);  //渲染帧数

void camera_settigns_change_language_text(void);

#ifdef __cplusplus
}
#endif

#endif