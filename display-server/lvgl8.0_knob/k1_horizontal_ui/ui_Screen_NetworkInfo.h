/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-11-28 10:40:51
 * @LastEditTime: 2023-08-25 23:15:50
 */
#ifndef _NETWORKINFO_H
#define _NETWORKINFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_NetworkInfo;

extern lv_obj_t * ui_NetworkInfoImage1;
extern lv_obj_t * ui_NetworkInfoImage2;
extern lv_obj_t * ui_NetworkInfoImage3;
extern lv_obj_t * ui_NetworkInfoImage4;
extern lv_obj_t * ui_NetworkInfoImage5;


void ui_event_NetworkInfoButton1(lv_event_t * e);

// extern lv_obj_t * ui_NetworkInfoLabel2;
// extern lv_obj_t * ui_NetworkInfoLabel3;
// extern lv_obj_t * ui_NetworkInfoLabel4;
// extern lv_obj_t * ui_NetworkInfoLabel5;

void refresh_networkinfo_page();

void network_info_change_language_text(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif