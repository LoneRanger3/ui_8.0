/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-21 13:45:46
 * @LastEditTime: 2022-12-21 14:52:49
 */
#ifndef _UI_CUSTOM_PRINT_OPT_SCREEN_H
#define _UI_CUSTOM_PRINT_OPT_SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

void create_custom_print_opt_screen(bool is_pause_action, void(*opt_callback)(void)
        , void(*stop_callback)(void));

#ifdef __cplusplus
}
#endif

#endif
