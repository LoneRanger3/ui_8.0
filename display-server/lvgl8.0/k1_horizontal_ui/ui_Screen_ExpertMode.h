/*
 * @Date         : 2023-08-16 13:56:03
 * @LastEditors  : fangjinlun fangjinlun@creality.com
 * @LastEditTime : 2023-08-18 15:24:30
 */
#ifndef _EXPERT_MODE_H
#define _EXPERT_MODE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

typedef enum {
    SubPageZOffset = 0,
    SubPageFlowSet,
    SubPageBedLevel,
    SubPageNozzlePID,
    SubPageBedPID,
    SubPageCount,
}SubPage;

extern lv_obj_t * ui_ExpertModePage;
extern lv_obj_t * ui_ExpertMode;
extern lv_obj_t * ui_ExpertMode_navi_obj;
void ui_Expert_mode_screen_init(void);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif