/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-01 14:55:13
 * @LastEditTime: 2023-07-13 22:44:35
 */
#ifndef _RESETMACHINE_H
#define _RESETMACHINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_ResetMachine;




void ui_event_resetmachinebutton2(lv_event_t * e);

void reset_machine_change_language_text(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif