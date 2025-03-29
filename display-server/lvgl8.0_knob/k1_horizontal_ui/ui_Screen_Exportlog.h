/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-11-29 11:23:51
 * @LastEditTime: 2023-09-16 07:44:37
 */
#ifndef _EXPORTLOG_H
#define _EXPORTLOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_Exportlog;
extern lv_obj_t * ui_ExportlogPanel1;
extern lv_obj_t * ui_ExportlogImage1;
extern lv_obj_t * ui_ExportlogImage2;
extern lv_obj_t * ui_ExportlogImage3;
extern lv_obj_t * ui_ExportlogImage4;
extern lv_obj_t * ui_ExportlogImage5;
extern lv_obj_t * ui_ExportlogPanel2;
extern lv_obj_t * ui_ExportlogPanel3;
extern lv_obj_t * ui_ExportlogTitle;
extern lv_obj_t * ui_ExportlogLabel1;
extern lv_obj_t * ui_ExportlogButton1;
extern lv_obj_t * ui_ExportlogBtnlabel1;
extern lv_obj_t * ui_ExportlogPanel4;
extern lv_obj_t * ui_ExportlogButton2;
extern lv_obj_t * ui_ExportlogBtnlabel2;
extern lv_obj_t * ui_Exportmbox1;

extern bool startexprotlogtolocal;

void ui_event_ExportlogButton1(lv_event_t * e);
//void refreshmsgbox(char flag);
void refreshmsgbox(int flag, int process);

void export_log_change_language_text(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif