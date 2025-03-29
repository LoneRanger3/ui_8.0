/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2023-03-04 15:25:17
 * @LastEditTime: 2023-03-04 15:36:49
 */
#ifndef _BOOT0_H
#define _BOOT0_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_BootPart0;
void ui_BootPart0_screen_init(void);
void boot0_change_language_text(void);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif