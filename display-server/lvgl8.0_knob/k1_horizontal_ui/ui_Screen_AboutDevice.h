/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-01 14:55:13
 * @LastEditTime: 2023-07-13 05:56:33
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

extern lv_obj_t * ui_AboutDevicePanel4;

extern lv_obj_t * ui_AboutDeviceLabel2;
extern lv_obj_t * ui_AboutDeviceLable3;
extern lv_obj_t * ui_AboutDeviceLable16;

void ui_event_AboutDeviceButton1(lv_event_t * e);
void refresh_aboutdevice_page(MachineInfo_t machine);
void about_device_change_language_text(void);
void refresh_factoryleveldata(int len, char * data, char level_point_value);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif