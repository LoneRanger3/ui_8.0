/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2022-12-27 14:37:49
 */
#ifndef _UI_SCREEN_ADJUSTMENT_H
#define _UI_SCREEN_ADJUSTMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>

void ui_ScreenAdjustmentPage_screen_init(void);
void LoadAdjustmentScreen(void);
void adjustment_set_offset_z(float offset_z);
void adjustment_set_speed_percent(int percent);
void adjustment_set_flow_percent(int percent);
void adjustment_set_print_status(int8_t print_status);  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
void adjustment_change_language_text(void);

#ifdef __cplusplus
}
#endif

#endif