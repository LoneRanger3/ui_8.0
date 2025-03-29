/*
 * @Author: Fang JinLun 
 * @Date: 2023-06-01 20:00:25 
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-06-08 13:52:32
 */

#ifndef _UI_LASER_PRESSURE_TEST_H
#define _UI_LASER_PRESSURE_TEST_H
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

void ui_laser_pressure_test_init(lv_obj_t* parents);
void set_laser_pressure_status(char* status);

#ifdef __cplusplus
}
#endif

#endif