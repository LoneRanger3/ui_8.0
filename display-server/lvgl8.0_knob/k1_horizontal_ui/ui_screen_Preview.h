/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2023-10-20 05:33:54
 */
#ifndef _UI_SCREEN_PREVIEW_H
#define _UI_SCREEN_PREVIEW_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "ui.h"
#include "ui_custom_dirent_info_part.h"

// 调平方式
#define NONE_LEVEL   0         //没有任何调平
#define PEOBE_LEVEL  (1 << 0)  //crtouch or bltouch 
#define PRESSURE_SENSOR_LEVEL (1 << 1)   //压力传感器调平
typedef enum {
    FROM_LOCAL = 1,
    FROM_UDISK = 2,
    FROM_HISTORY = 3,
}PrintFrom;

extern lv_obj_t * ui_ScreenPreview;


void ui_ScreenPreview_screen_init(void);
void LoadPreviewScreen(void); //preview file`s dir type 

int preview_set_file_info(dirent_info_part_t *part, bool preview_type);
void preview_set_history_file_info(int32_t history_record_index);
//void preview_set_file_info(char *file_name, uint32_t totel_time, uint32_t mater_used, int32_t file_index, char * filament_type, int nozzletemp, int bedtemp, PrintFrom type);
void preview_set_mode_file_from_dir_type(bool root_dir);

void preview_set_filling_chart_info(char *chart_png_name, uint16_t pixel_start, uint16_t pixel_end, float mode_height, float mode_layer_height);
void preview_set_model_printer_temper(uint16_t hotend_temper, uint16_t bed_temper);
void preview_set_level_mode(uint32_t Mode);  //具体的调平方式参考宏定义

void create_tips(int percent);
void preview_change_language_text(void);
void FromHistoryToPreview(bool flag, HistoryInfo_t singlefile);

#ifdef __cplusplus
}
#endif

#endif