/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-02-02 15:51:27
 * @LastEditTime: 2023-02-24 11:20:49
 */
#ifndef _UI_SCREEN_DETECTIONAI_H
#define _UI_SCREEN_DETECTIONAI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
#include "ui_helpers.h"

void ui_ScreenAI_screen_init(void);
void LoadAiDetectionScreen(void);

void ai_set_detection_state(AIConfigState_t aistate);
void ai_set_first_layer_detection(bool opened);
void ai_set_fault_action(bool is_detection_in_printing);
void refreshSharePictrueState(bool state);


#ifdef __cplusplus
}
#endif

#endif