/*
 * @Description : 
 * @Author      : 
 * @Date: 2023-8-8 10:00:32
 * @LastEditTime: 2023-03-15 14:55:22
 */
#ifndef _UI_SCREEN_EXPERTTRAFFIC_H
#define _UI_SCREEN_EXPERTTRAFFIC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"


void ui_ScreenTrafficPage_screen_init(void);
void ui_DiapScreenTrafficPage(void);
void ui_HideScreenTrafficPage(void);
void ui_LoadTrafficScreen(void);
void expert_set_traffic_percent(int);
lv_obj_t * ui_AddTrafficCheckbox(lv_obj_t * parent, uint16_t x, uint16_t y, const char * txt);
lv_obj_t * ui_AddTrafficCheckboxBg(lv_obj_t * parent);

#ifdef __cplusplus
}
#endif

#endif