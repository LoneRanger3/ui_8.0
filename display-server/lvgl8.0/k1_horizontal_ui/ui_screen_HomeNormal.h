/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-08 10:54:20
 * @LastEditTime: 2023-03-20 19:39:27
 */
#ifndef _UI_SCREEN_HOMENORMAL_H
#define _UI_SCREEN_HOMENORMAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
#include "ui_helpers.h"

#define HOTEND_MAX_EDIT_TEMPER 300
#define HOTEND_MIN_EDIT_TEMPER 0
#define BED_MAX_EDIT_TEMPER 100
#define K1_MAX_BED_MAX_EDIT_TEMPER 100
#define K1_MAX_SE_BED_MAX_EDIT_TEMPER 120
#define BED_MIN_EDIT_TEMPER 0


// wifi intensity
#define MIN_RSSI    (-100)
#define MAX_RSSI    (-55)
#define RSSI_LEVELS (4)

void ui_ScreenHomePageNormal_screen_init(void);
void LoadHomeNormalScreen(void);
void home_normal_set_hotend_temper(int16_t curTemper, int16_t targetTemper);
void home_normal_set_bed_temper(int16_t curTemper, int16_t targetTemper);
void home_normal_set_fan_status(bool open);
void home_normal_set_light_status(bool open);
void home_normal_set_wifi_status(int intensity);
void home_normal_set_print_status(int8_t print_status); // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
void home_normal_set_chamber_temper(int16_t curTemper);

void key_reminder_callback(int reminder);  //number keys pressed reminder
void hoem_page_refresh_camerastate(int camera_state);
void change_filamentsensor_normalpage(bool state);
void change_silentmode_normal(bool state);

#ifdef __cplusplus
}
#endif

#endif