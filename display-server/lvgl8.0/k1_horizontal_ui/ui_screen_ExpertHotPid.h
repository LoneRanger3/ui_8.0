/*
 * @Date         : 2023-08-21 16:01:29
 * @LastEditors  : fangjinlun fangjinlun@creality.com
 * @LastEditTime : 2023-08-25 14:40:32
 */

#ifndef _UI_SCREEN_EXPERTHOTPID_H
#define _UI_SCREEN_EXPERTHOTPID_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef enum 
{
    HOT_PREPARE = 0,
    HOT_CHECKING,
    HOT_FINISH,
    HOT_RETURN
}HotProcess_t;

void ui_ScreenHotPidPage_screen_init(void);
void ui_DiapScreenHotPidPage(HotProcess_t process);
void ui_LoadHotPidScreen(void);
void expert_hot_set_hotend_temper(int16_t curTemper, int16_t targetTemper);
void refresh_expert_hotpid_page(void);

#ifdef __cplusplus
}
#endif

#endif