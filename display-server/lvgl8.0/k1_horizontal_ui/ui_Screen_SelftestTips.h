/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-11-28 10:40:51
 * @LastEditTime: 2022-12-30 14:45:30
 */
#ifndef _SELFTESTTIPS_H
#define _SELFTESTTIPS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_SelftestTips;
extern lv_obj_t * ui_SelftestTipstitle;
extern lv_obj_t * ui_SelftestTipsButton1;
extern lv_obj_t * ui_SelftestTipsBtnlabel1;
extern lv_obj_t * ui_SelftestTipsButton2;
extern lv_obj_t * ui_SelftestTipsBtnlabel2;
extern lv_obj_t * ui_SelftestTipsButton3;
extern lv_obj_t * ui_SelftestTipsBtnlabel3;
extern lv_obj_t * ui_SelftestTips_Panel1;
extern lv_obj_t * ui_SelftestTips_Image1;
extern lv_obj_t * ui_SelftestTips_Panel2;
extern lv_obj_t * ui_SelftestTipslabel1;
extern lv_obj_t * ui_SelftestTipslabel2;
extern lv_obj_t * ui_SelftestTipslabel3;

void ui_event_SelftestTipsButton1(lv_event_t * e);
void ui_event_SelftestTipsButton2(lv_event_t * e);
void ui_event_SelftestTipsButton3(lv_event_t *e);

void self_test_tip_change_language_text(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif