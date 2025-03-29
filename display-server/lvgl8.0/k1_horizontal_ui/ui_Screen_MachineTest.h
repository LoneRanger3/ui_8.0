/*
 * @Author: Fang JinLun 
 * @Date: 2023-04-19 18:15:27 
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-04-23 14:32:30
 */
#ifndef _UI_MACHINE_TEST_H
#define _UI_MACHINE_TEST_H
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



void ui_machine_test_init(void);
void ui_load_machinetestScreen(void);
#ifdef __cplusplus
}
#endif

#endif