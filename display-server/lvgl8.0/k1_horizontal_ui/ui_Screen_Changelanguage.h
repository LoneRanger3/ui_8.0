/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-11-26 17:03:12
 * @LastEditTime: 2023-02-01 14:13:46
 */
#ifndef _CHANGELANGUAGE_H
#define _CHANGELANGUAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_changelanguage;
extern lv_obj_t * ui_changelanguagetitle;
extern lv_obj_t * ui_ChangelanguageButton1;
extern lv_obj_t * ui_ChangelanguageBtnlabel1;
extern lv_obj_t * ui_ChangelanguageButton2;
extern lv_obj_t * ui_ChangelanguageBtnlabel2;
extern lv_obj_t * ui_ChangelanguageButton3;
extern lv_obj_t * ui_ChangelanguageBtnlabel3;
extern lv_obj_t * ui_ChangelanguageButton4;
extern lv_obj_t * ui_ChangelanguageBtnlabel4;
extern lv_obj_t * ui_ChangelanguageButton5;
extern lv_obj_t * ui_ChangelanguageBtnlabel5;
extern lv_obj_t * ui_ChangelanguageButton6;
extern lv_obj_t * ui_ChangelanguageBtnlabel6;
extern lv_obj_t * ui_ChangelanguageButton7;
extern lv_obj_t * ui_ChangelanguageBtnlabel7;
extern lv_obj_t * ui_ChangelanguageButton8;
extern lv_obj_t * ui_ChangelanguageBtnlabel8;
extern lv_obj_t * ui_ChangelanguageButton9;
extern lv_obj_t * ui_ChangelanguageBtnlabel9;
#define SELFTEST_FIRMWARE  "debugmode_SelftestFireware"

void ui_event_changelanguage(lv_event_t * e);

char *language_get_cur_language_text(int8_t language_index);  //语言范围时是0到8
void language_change_language_text(void);  //翻译label内容
void change_language_end(unsigned char language);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif