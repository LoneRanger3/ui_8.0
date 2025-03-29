/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2023-03-10 11:47:57
 * @LastEditTime: 2023-03-10 11:49:22
 */
#ifndef _SELFTESTALL_H
#define _SELFTESTALL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t *ui_SelftestAll;
extern lv_obj_t *ui_SelftestAlltitle;
extern lv_obj_t *ui_SelftestAll_Panel1;
extern lv_obj_t *ui_SelftestAll_Panel2;
extern bool start_selftest_upload;

void ui_SelftestAll_screen_init();
void check_singleprocess_completed(int SeqNumber, bool result);
void selftest_check_cxyuserinfo(bool result);
void JudgeHeatingIsNormal(int hotendtemp, int bedtemp);
void JudgeAILiDARIsNormal(int state);
void JudgeCameraIsNormal(int state);
void JudgeAILiDARIsNormal(int state);
void manual_test_completed(int num, bool result);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif