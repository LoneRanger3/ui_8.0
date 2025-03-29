/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-01-06 14:01:51
 * @LastEditTime: 2023-02-01 16:08:40
 */
#ifndef _UI_CUSTOM_NUMBRES_KEYS_H
#define _UI_CUSTOM_NUMBRES_KEYS_H


#ifdef __cplusplus
extern "C" {
#endif


#include "lvgl/lvgl.h"



void numberskeyboardinput(char *msg, int *inputmax, int *inputmin, void (*confirm_btn_call_back)(void *), void (*key_reminder)(int), uint16_t pos_x, uint16_t pos_y);


#ifdef __cplusplus
}
#endif

#endif
