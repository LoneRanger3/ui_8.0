/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-11-28 10:40:51
 * @LastEditTime: 2022-12-30 16:21:03
 */
#ifndef _SELFTESTPRIVACYPOLICY_H
#define _SELFTESTPRIVACYPOLICY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_SelftestPrivacyPolicy;
extern lv_obj_t * ui_SelftestPrivacyPolicypanel;
extern lv_obj_t * ui_SelftestPrivacyPolicytitle1;
void ui_event_SelftestPrivacyPolicyButton1(lv_event_t * e);
extern lv_obj_t * ui_SelftestPrivacyPolicyButton1;
extern lv_obj_t * ui_SelftestPrivacyPolicyBtnlabel1;
extern lv_obj_t * ui_SelftestPrivacyPolicyLabel1;
void ui_event_SelftestPrivacyPolicyButton2(lv_event_t * e);
extern lv_obj_t * ui_SelftestPrivacyPolicyButton2;
extern lv_obj_t * ui_SelftestPrivacyPolicyBtnlabel2;
extern lv_obj_t * ui_SelftestPrivacyPolicyLabel2;
extern lv_obj_t * ui_SelftestPrivacyPolicy_Checkbox1;


void privacy_policy_change_language_text(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif