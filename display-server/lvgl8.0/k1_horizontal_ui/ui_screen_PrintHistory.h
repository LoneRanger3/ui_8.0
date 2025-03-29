/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2022-12-27 17:31:28
 */
#ifndef _UI_SCREEN_PRINTHISTORY_H
#define _UI_SCREEN_PRINTHISTORY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "ui.h"
#include "ui_screen_FileManage.h"


void ui_ScreenPrintHistory_screen_init(void);
void LoadPrintHistoryScreen(void);
void history_set_print_record_info(print_record_info_t record_arry[3], int real_record_count); // row_no is 0 to 2
void history_set_print_record_count(int count);

void history_change_language_text(void);

#ifdef __cplusplus
}
#endif

#endif