/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2023-02-02 14:14:00
 * @LastEditTime: 2023-03-17 11:33:38
 */
#ifndef _TIMEZONESETTINGS_H
#define _TIMEZONESETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_TimezoneSettings;
void refresh_timezoneseting(char * timezone);
void timezone_change_language_text(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif