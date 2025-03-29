/*
 * @Description : 
 * @Author      : 
 * @Date: 2023-8-8 10:00:32
 * @LastEditTime: 2023-03-15 14:55:22
 */
#ifndef _UI_SCREEN_EXPERTBEDPID_H
#define _UI_SCREEN_EXPERTBEDPID_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef enum 
{
    BED_PREPARE = 0,
    BED_CHECKING,
    BED_FINISH,
    BED_RETURN
}BedProcess_t;

void ui_ScreenBedPidPage_screen_init(void);
void ui_DiapScreenBedPidPage(BedProcess_t process);
void ui_LoadBedPidScreen(void);
void expert_bed_set_bed_temper(int16_t curTemper, int16_t targetTemper);
void refresh_expert_bedpid_page(void);

#ifdef __cplusplus
}
#endif

#endif