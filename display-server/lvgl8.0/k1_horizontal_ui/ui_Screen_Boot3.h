/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-08 16:05:12
 * @LastEditTime: 2023-03-12 11:39:18
 */
#ifndef _BOOT3_H
#define _BOOT3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
extern lv_obj_t * ui_BootPart3;
void ui_BootPart3_screen_init(void);
void boot3_change_language_text(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif