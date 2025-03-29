/*
 * @Description : 
 * @Author      : 
 * @Date: 2023-8-8 10:00:32
 * @LastEditTime: 2023-03-15 14:55:22
 */
#ifndef _UI_SCREEN_EXPERTZOFFSET_H
#define _UI_SCREEN_EXPERTZOFFSET_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"


void ui_ScreenZoffsetPage_screen_init(void);
void ui_DiapScreenZoffsetPage(void);
void ui_HideScreenZoffsetPage(void);
void ui_LoadZoffsetScreen(void);
void expert_set_offset_z(double offset_z);

#ifdef __cplusplus
}
#endif

#endif