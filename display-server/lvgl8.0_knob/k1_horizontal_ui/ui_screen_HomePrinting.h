/*
 * @Description :   
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2023-09-23 04:54:14
 */
#ifndef _UI_SCREEN_HOMEPRINTING_H
#define _UI_SCREEN_HOMEPRINTING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>

#define MAX_FILLINF_CHART_MASK_HEIGHT 300

extern lv_obj_t * ui_PanelPrintResultMsgboxBg;

void LoadHomePrintingPageAndObjs(bool IsEntered);
void ui_ScreenHomePagePrinting_screen_init(void);
void LoadHomePrintingScreen(void);

void home_printing_set_hotend_temper(int16_t curTemper, int16_t targetTemper);
void home_printing_set_bed_temper(int16_t curTemper, int16_t targetTemper);
void home_printing_set_chamber_temper(int16_t curTemper);
void home_printing_set_fan_status(bool open);
void home_printing_set_light_status(bool open);
void home_printing_set_wifi_status(int intensity);
void home_printing_set_print_proccess_info(int32_t used_time, int32_t left_time, int8_t proccess); //time unit is minter

void home_printing_set_filling_chart_name(char *chart_name, uint16_t pixel_start, 
                                          uint16_t pixel_end, float model_height,float model_layer_height);
void home_printing_set_printing_status(int status);  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
void home_printing_set_powerloss_recovery_info(int state);
void home_printing_set_filament_runout(bool filamen_runout);
void home_printing_set_home_status(bool is_homing);
void home_printing_set_print_file_name(char *file_name);

bool home_printing_is_printing_finished();  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
bool home_printing_is_printing();  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
bool home_printing_is_paused();  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议

void home_printing_set_gcode_layers_count(uint32_t layer_count);
void home_printing_set_gcode_cur_layer_index(uint32_t layer_index);
void print_page_refresh_camerastate(int camera_state);
void print_page_refresh_laserstate(int laser_state);
void ResultMsgboxAddObjsToGroup(void);
void refresh_prepare_process(int process);
#ifdef __cplusplus
}
#endif

#endif