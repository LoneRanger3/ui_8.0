/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2023-09-13 22:10:21
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
    lv_obj_t *img_udik_png;
    lv_obj_t *label_mater_used;
    // TODO:新协议直接解析json，将解析的gcode信息直接存储在面板子结构体框架内
    int32_t   dirent_index; // dirent_index means dirent sorted index
    uint16_t   subdir_part_index; //子目录文件夹列表索引
    bool      is_local_disk;    // 本机文件：1；U盘：0 
    bool      is_udisk; // 是否有U盘 1：U盘插 
    bool      is_dir;  // 0:means dir, 1:means file
    uint32_t  totle_time;
    uint32_t  mater_used;
    char      dirent_name[64];  //只取文件名的前63个字符
    char      filament_type[64]; //材料类型
    int       nozzle_temp;
    int       bed_temp;
}dirent_info_part_t;


typedef struct Dirent_Info{
    char name[256];
    char path[256];
    char mode_thumbnail[256];
    bool is_dir;
    bool is_udisk;
    uint32_t totle_time;
    uint32_t mater_used; 
    uint32_t dirent_index;
    uint16_t  subdir_part_index; //子目录文件夹列表索引
    uint64_t dir_create_time;
    char filament_type[64];
    int nozzle_temp;
    int bed_temp;
}Dirent_Info_t;

dirent_info_part_t *create_custom_dirent_info_part(lv_obj_t *parent, void (*part_event_callback)(lv_event_t *));
void destory_custom_dirent_info_part(dirent_info_part_t *part);
void clear_custom_dirent_info_part_contents(dirent_info_part_t *part);


void hidden_file_controls(dirent_info_part_t *part);
void hidden_dir_controls(dirent_info_part_t *part);
void display_file_controls(dirent_info_part_t *part);
void display_dir_controls(dirent_info_part_t *part);

//totle_time unit is second, mater_used unit is g
void ShowPartGcodefileInfo(dirent_info_part_t *part, Dirent_Info_t*ginfo);
void ShowPartDirInfo(dirent_info_part_t *part, char *dir_name, char *create_time, 
                    uint32_t dirent_sort_index, bool isUdisk);

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