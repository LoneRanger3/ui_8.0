/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */


#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_
#include "gui_guider.h"

void events_init(lv_ui *ui);
void events_init_home(lv_ui *ui);
void events_init_menu(lv_ui *ui);
void events_init_print(lv_ui *ui);
void events_init_prepare_menu(lv_ui *ui);
void events_init_prepare_move_axis(lv_ui *ui);
void events_init_prepare_material(lv_ui *ui);
void events_init_prepare_manual_temp(lv_ui *ui);
void events_init_setting_menu(lv_ui *ui);
void events_init_setting_device(lv_ui *ui);
void events_init_setting_ad_setting(lv_ui *ui);
void events_init_Language(lv_ui *ui);
void events_init_Level_menu(lv_ui *ui);
void events_init_Level_auto(lv_ui *ui);
void events_init_Level_manual(lv_ui *ui);
void events_init_Level_title(lv_ui *ui);
void events_init_MotionSet(lv_ui *ui);
void events_init_RTOSet(lv_ui *ui);
void events_init_MaxAccSet(lv_ui *ui);
void events_init_MaxConcorSet(lv_ui *ui);
void events_init_MaxSpeedSet(lv_ui *ui);
void events_init_TempPIDSet(lv_ui *ui);
void events_init_PrintingSet(lv_ui *ui);
void events_init_ZoffsetSet(lv_ui *ui);
void events_init_Preheating(lv_ui *ui);
void events_init_Inputboxs(lv_ui *ui);
#endif /* EVENT_CB_H_ */