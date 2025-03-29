/*
 * @Author: Fang JinLun 
 * @Date: 2023-06-07 21:05:06 
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-06-08 11:03:15
 */


#ifndef _UI_SCREEN_MACHINE_MCU_VERSION_H
#define _UI_SCREEN_MACHINE_MCU_VERSION_H
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

void ui_machine_mcu_version_init(lv_obj_t* parents);
void set_laser_version_label(char* ver);

#ifdef __cplusplus
}
#endif

#endif