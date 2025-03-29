/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-11-28 10:40:51
 * @LastEditTime: 2022-12-29 10:53:09
 */
#ifndef _TOUCHTONE_H
#define _TOUCHTONE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_Keytonesetting;
extern lv_obj_t * ui_KeytonesettingPanel1;
extern lv_obj_t * ui_KeytonesettingImage1;
extern lv_obj_t * ui_KeytonesettingImage2;
extern lv_obj_t * ui_KeytonesettingImage3;
extern lv_obj_t * ui_KeytonesettingImage4;
extern lv_obj_t * ui_KeytonesettingImage5;
extern lv_obj_t * ui_KeytonesettingPanel2;
extern lv_obj_t * ui_KeytonesettingPanel3;
extern lv_obj_t * ui_KeytonesettingTitle;
extern lv_obj_t * ui_KeytonesettingButton1;
extern lv_obj_t * ui_KeytonesettingBtnLabel1;
extern lv_obj_t * ui_KeytonesettingLabel1;
extern lv_obj_t * ui_KeytonesettingSwitch1;
extern lv_obj_t * ui_KeytonesettingLabel2;
extern lv_obj_t * ui_KeytonesettingLabel3;
extern lv_obj_t * ui_KeytonesettingDropdown1;
extern lv_obj_t * ui_KeytonesettingSlider1;
extern lv_obj_t * ui_KeytonesettingImage6;
extern lv_obj_t * ui_KeytonesettingImage7;

void ui_event_KeytonesettingButton1(lv_event_t * e);
void ui_event_KeytonesettingSwitch1(lv_event_t * e);
void ui_event_KeytonesettingSlider1(lv_event_t * e);
void ui_event_KeytonesettingDropdown1(lv_event_t * e);

void touch_tone_change_language_text(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif