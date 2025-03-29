/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-11-28 10:40:51
 * @LastEditTime: 2023-02-08 17:31:09
 */
#ifndef _SCREENOFF_H
#define _SCREENOFF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_ScreenoffPanel1;

void enter_screenoff_mode(lv_obj_t * target);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif