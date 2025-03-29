/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2023-03-03 12:09:04
 */
#ifndef _UI_CUSTOM_DIRENT_INFO_PART_H
#define _UI_CUSTOM_DIRENT_INFO_PART_H


#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"



typedef struct dirent_info_part
{
    lv_obj_t *parent;
    lv_obj_t *part_panel;
    lv_obj_t *checkbox_file;
    lv_obj_t *img_file_png;
    lv_obj_t *img_dir_png;
    lv_obj_t *label_dirent_name;
    lv_obj_t *label_dir_time;
    lv_obj_t *img_time_png;
    lv_obj_t *label_totle_time;
    lv_obj_t *img_mater_png;
    lv_obj_t *label_mater_used;
    int32_t   dirent_index; // dirent_index means dirent sorted index
    bool      is_local_disk;    // 本机文件：1；U盘：0
    bool      is_dir;  // 0:means dir, 1:means file
    uint32_t  totle_time;
    uint32_t  mater_used;
    char      dirent_name[64];  //只取文件名的前63个字符
    char      filament_type[64];
    int       nozzle_temp;
    int       bed_temp;
}dirent_info_part_t;


dirent_info_part_t *create_custom_dirent_info_part(lv_obj_t *parent, int16_t pos_x, int16_t pos_y, void (*part_event_callback)(lv_event_t *));
void destory_custom_dirent_info_part(dirent_info_part_t *part);
void clear_custom_dirent_info_part_contents(dirent_info_part_t *part);

//totle_time unit is second, mater_used unit is g
void part_show_mode_file_info(dirent_info_part_t *part, char *file_name, char *mode_thumbnail, uint32_t totle_time, 
                        uint32_t mater_used, uint32_t dirent_sort_index, bool local_disk, char *filament_type, int nozzle_temp, int bed_temp);

void part_show_Dir_info(dirent_info_part_t *part, char *dir_name, char *create_time, 
                    uint32_t dirent_sort_index, bool local_disk);

char *part_get_dirent_info_name(dirent_info_part_t *part);
bool part_dirent_is_local_desk(dirent_info_part_t *part);
int32_t part_dirent_index(dirent_info_part_t *part);

void part_display_controls(dirent_info_part_t *part, bool display);
void part_set_file_checkbox_state(dirent_info_part_t *part, bool checked);
void part_set_file_checkbox_dispaly(dirent_info_part_t *part, bool display);
bool part_get_file_checkbox_checkedstate(dirent_info_part_t *part);

#ifdef __cplusplus
}
#endif

#endif