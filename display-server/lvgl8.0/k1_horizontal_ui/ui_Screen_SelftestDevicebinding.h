/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-08 16:05:12
 * @LastEditTime: 2023-02-02 14:49:31
 */
#ifndef _SELFTESTDEVICEBINDING_H
#define _SELFTESTDEVICEBINDING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"


extern lv_obj_t * ui_DeviceBinding;
extern lv_obj_t * ui_DeviceBindingLabel1;
extern lv_obj_t * ui_DeviceBindingButton1;
extern lv_obj_t * ui_DeviceBindingLabel2;
extern lv_obj_t * ui_DeviceBindingButton2;
extern lv_obj_t * ui_DeviceBindingLabel3;
extern lv_obj_t * ui_DeviceBindingButton3;
extern lv_obj_t * ui_DeviceBindingLabel4;
extern lv_obj_t * ui_DeviceBindingLabel5;
extern lv_obj_t * ui_DeviceBinding_Image3;

void refresh_selftestbinding_page(char *src);
void selftest_bind_change_language_text(void);
void refresh_DeviceUserInfo_selftest(CloudUserInfo_t user);
void SelftsetChangeServerOption(int ServerOption);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif