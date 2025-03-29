/*
 * @Author: Fang JinLun 
 * @Date: 2023-06-01 20:00:25 
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-06-01 20:00:48
 */

#ifndef _UI_SCREEN_LASER_FLOW_DETECT_TEST_H
#define _UI_SCREEN_LASER_FLOW_DETECT_TEST_H
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

void ui_laser_flow_test_init(lv_obj_t* parents);
void flow_test_show_result(int num,char *result);
void LaserFloeDetectTestAddObjToGroup(void);
#ifdef __cplusplus
}
#endif

#endif