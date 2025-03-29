/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-11-28 16:46:23
 * @LastEditTime: 2022-12-28 17:44:11
 */
#ifndef _DEVICEBINDING_H
#define _DEVICEBINDING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_Devicebinding;
extern lv_obj_t * ui_DevicebindingPanel1;
extern lv_obj_t * ui_DevicebindingImage1;
extern lv_obj_t * ui_DevicebindingImage2;
extern lv_obj_t * ui_DevicebindingImage3;
extern lv_obj_t * ui_DevicebindingImage4;
extern lv_obj_t * ui_DevicebindingImage5;
extern lv_obj_t * ui_DevicebindingPanel2;
extern lv_obj_t * ui_DevicebindingPanel3;
extern lv_obj_t * ui_DevicebindingTitle;
extern lv_obj_t * ui_DevicebindingLabel1;
extern lv_obj_t * ui_DevicebindingButton1;
extern lv_obj_t * ui_DevicebindingBtnlabel1;
extern lv_obj_t * ui_DevicebindingLabel2;
extern lv_obj_t * ui_DevicebindingImage6;

void ui_event_DevicebindingButton1(lv_event_t * e);
void refresh_devicebingding_page(char *src);

void device_bind_change_language_text(void);
void refresh_DeviceUserInfo(bool result, CloudUserInfo_t user);
void ChangeServerOption(int ServerOption);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif