/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-01-29 11:17:32
 * @LastEditTime: 2023-03-17 18:24:16
 */
#ifndef _UI_SCREEN_COOL_H
#define _UI_SCREEN_COOL_H

#ifdef __cplusplus
extern "C" {
#endif    

#include "ui.h"
#include "ui_helpers.h"

void ui_ScreenCool_screen_init(void);
void LoadCoolScreen(void);

void cool_set_model_fan_duty_percent(uint8_t percent);
void cool_set_cool_fan_duty_percent(uint8_t percent);
void cool_set_Chassis_fan_duty_percent(uint8_t percent);
void cool_change_language_text();

#ifdef __cplusplus
}
#endif

#endif