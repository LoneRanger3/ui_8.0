/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-01 14:55:13
 * @LastEditTime: 2022-12-28 16:40:42
 */
#ifndef _ABOUTDEVICE_H
#define _ABOUTDEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_AboutDevice;
extern lv_obj_t * ui_AboutDevicePanel1;
extern lv_obj_t * ui_AboutDeviceImage1;
extern lv_obj_t * ui_AboutDeviceImage2;
extern lv_obj_t * ui_AboutDeviceImage3;
extern lv_obj_t * ui_AboutDeviceImage4;
extern lv_obj_t * ui_AboutDeviceImage5;
extern lv_obj_t * ui_AboutDevicePanel2;
extern lv_obj_t * ui_AboutDevicePanel3;
extern lv_obj_t * ui_AboutDeviceTitle;
extern lv_obj_t * ui_AboutDeviceLabel1;
extern lv_obj_t * ui_AboutDeviceButton1;
extern lv_obj_t * ui_AboutDeviceBtnlabel1;
extern lv_obj_t * ui_AboutDevicePanel4;
extern lv_obj_t * ui_AboutDeviceImage6;
extern lv_obj_t * ui_AboutDeviceLabel2;
extern lv_obj_t * ui_AboutDeviceLable3;
extern lv_obj_t * ui_AboutDeviceLable4;
extern lv_obj_t * ui_AboutDeviceLable5;
extern lv_obj_t * ui_AboutDeviceLable6;
extern lv_obj_t * ui_AboutDeviceLable7;
extern lv_obj_t * ui_AboutDeviceLable8;
extern lv_obj_t * ui_AboutDeviceLable9;
extern lv_obj_t * ui_AboutDeviceLable10;
extern lv_obj_t * ui_AboutDeviceLable11;
extern lv_obj_t * ui_AboutDeviceLable12;
extern lv_obj_t * ui_AboutDeviceLable13;
extern lv_obj_t * ui_AboutDeviceLable14;
extern lv_obj_t * ui_AboutDeviceLable15;
extern lv_obj_t * ui_AboutDeviceLable16;

void ui_event_AboutDeviceButton1(lv_event_t * e);
void refresh_aboutdevice_page(MachineInfo_t machine);
void about_device_change_language_text(void);
void refresh_factoryleveldata(int len, char * data, char level_point_value);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif