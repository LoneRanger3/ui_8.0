/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2022-12-23 16:43:53
 */
#ifndef _UI_SCREEN_FULLSCREEN_H
#define _UI_SCREEN_FULLSCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
#include "ui_helpers.h"

void ui_ScreenFull_screen_init(void);
void LoadFullScreenScreen(void);

void full_screen_set_print_proccess(uint16_t proccess);
void full_screen_set_Filling_chart (char *png_name);
void full_screen_set_display_status(bool open_full_screen);
void full_screen_set_gcode_layers_count(uint32_t layer_count);
void full_screen_set_gcode_cur_layer_index(uint32_t layer_index);

#ifdef __cplusplus
}
#endif

#endif