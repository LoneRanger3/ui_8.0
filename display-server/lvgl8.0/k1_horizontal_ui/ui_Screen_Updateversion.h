/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-11-28 10:40:51
 * @LastEditTime: 2023-02-23 15:24:22
 */
#ifndef _UPDATEVERSION_H
#define _UPDATEVERSION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_UpdateVersion;
extern lv_obj_t * ui_UpdateVersionPanel1;
extern lv_obj_t * ui_UpdateVersionBtn1;
extern lv_obj_t * ui_UpdateVersionBtnlabel1;
extern lv_obj_t * ui_UpdateVersionBtn2;
extern lv_obj_t * ui_UpdateVersionBtnlabel2;
extern lv_obj_t * ui_UpdateVersionTitle;
extern lv_obj_t * ui_OldVersion;
extern lv_obj_t * ui_NewVersion;
extern lv_obj_t * ui_VersionSize;
extern lv_obj_t * ui_UpdateContent;
extern lv_obj_t * ui_VersionSize1;
extern lv_obj_t * ui_UpdateVersionBar1;
extern lv_obj_t * ui_UpdateVersionPanel2;
extern lv_obj_t * ui_UpdateVersionLabel1;
extern lv_obj_t * ui_UpdateVersionLabel2;
extern lv_obj_t * ui_UpdateVersionBtn3;
extern lv_obj_t * ui_UpdateVersionBtnlabel3;
extern lv_obj_t * ui_UpdateVersionBtn4;
extern lv_obj_t * ui_UpdateVersionBtnlabel4;

void ui_event_UpdateVersionBtn1(lv_event_t * e);
void ui_event_UpdateVersionBtn2(lv_event_t * e);
void ui_event_UpdateVersionBtn3(lv_event_t * e);
void ui_event_UpdateVersionBtn4(lv_event_t * e);

void EnterUpdatepage(int mode); //进版本升级弹窗
void refresh_updatepage(int flag, char * current_version, char * new_version, char * version_size, char * content,  int result);
void RefreshUpdateVersionProgress(char version_flag, char * upgrade_progress);

void update_version_change_language_text(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif