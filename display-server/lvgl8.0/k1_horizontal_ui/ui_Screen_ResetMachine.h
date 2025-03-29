/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-01 14:55:13
 * @LastEditTime: 2022-12-28 17:26:53
 */
#ifndef _RESETMACHINE_H
#define _RESETMACHINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_ResetMachine;
extern lv_obj_t * ui_ResetMachinePanel1;
extern lv_obj_t * ui_homeimg1;
extern lv_obj_t * ui_axismoveimg1;
extern lv_obj_t * ui_fileimg1;
extern lv_obj_t * ui_settingsimg1;
extern lv_obj_t * ui_faqimg1;
extern lv_obj_t * ui_resetmachinepanel2;
extern lv_obj_t * ui_resetmachinepanel3;
extern lv_obj_t * ui_resetmachinepanel4;
extern lv_obj_t * ui_resetmachinetitle;
extern lv_obj_t * ui_resetmachinelabel1;
extern lv_obj_t * ui_resetCheckbox1;
extern lv_obj_t * ui_resetCheckbox2;
extern lv_obj_t * ui_resetCheckbox3;
extern lv_obj_t * ui_resetCheckbox4;
extern lv_obj_t * ui_resetmachinebutton1;
extern lv_obj_t * ui_resetmachine_Label1;
extern lv_obj_t * ui_resetmachinebutton2;
extern lv_obj_t * ui_resetmachine_Label2;

void ui_event_resetmachinebutton2(lv_event_t * e);

void reset_machine_change_language_text(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif