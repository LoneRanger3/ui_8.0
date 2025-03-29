/*
 * @Author: Fang JinLun 
 * @Date: 2023-04-19 18:15:27 
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-04-20 14:19:24
 */
#ifndef _UI_SCREEN_LASERTEST_H
#define _UI_SCREEN_LASERTEST_H
#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>
#include <string.h>
#include "ui_custom_numbers_keys.h"
#include "ui_custom_messagebox.h"
#include "../custom/lvgl_cmd.h"
#include "ui_Screen_Settings.h"
#include "ui_Screen_CustomerService.h"
#include "mult_language.h"
#include "Base/DisplayMsgBase.h"
#include "custom/commu_thread.h"
#include "../lvgl/src/widgets/lv_canvas.h"
#include "../Message/ServerMessage.h"



void ui_laser_test_init(lv_obj_t* parents);
void set_step1_image(char* image_path);
void set_step2_image(char* image_path);
void set_step1_laser_cali_status(char* status);
void set_step2_laser_cali_status(char* status);
void refresh_laser_test_temp(int hotend_temp, int bed_temp);
void LaserTestAddObjToGroup(void);

#ifdef __cplusplus
}
#endif

#endif