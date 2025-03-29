/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2023-03-02 13:52:10
 */
#ifndef _UI_SCREEN_FILEMANAGE_H
#define _UI_SCREEN_FILEMANAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "ui.h"

#define PAGE_MAX_DIRENT_COUNT 8

typedef enum Screen_Type
{
    SCREEN_FILE,
    SCREEN_SUBDIR,
    SCREEN_HISTORY,
}Screen_Type_t;


typedef struct Dirent_Info{
    char name[256];
    char mode_thumbnail[256];
    bool is_dir;
    uint32_t totle_time;
    uint32_t mater_used; 
    uint32_t dirent_index;
    uint64_t dir_create_time;
    char filament_type[64];
    int nozzle_temp;
    int bed_temp;
}Dirent_Info_t;

typedef struct print_record_info
{
    char thumbnail_name[256];
    char file_name[256];
    int32_t recode_index;
    int64_t start_time;
    int32_t print_used_time;
    bool state_ok;
    bool file_exsit;
}print_record_info_t;

void ui_ScreenFileManage_screen_init(void);
void LoadFileManageScreen(void);

/***************call by subdir screen and PrintHistory screen************************/
void file_manage_switch_screen(Screen_Type_t screen);
void file_manage_switch_disk(bool is_local); 
/*****************************************/

/***************call by cmd respone thread************************/
void file_manage_set_files_count(int count);  
void file_manage_set_file_infos(Dirent_Info_t dirent_array[8], int real_count);
void file_manage_set_print_record_info(print_record_info_t record_arry[3], int real_record_count); // row_no is 0 to 2
void file_manage_set_print_record_count(int count);
void file_manage_set_u_disk_status(bool inserted);
void refresh_copyprocess(int process, int copyto);
/***************************************/
void file_manage_change_language_text(void);
bool get_is_local_disk(void);
void set_is_local_disk(bool state);
int get_current_page_number(void);
void set_last_index(int index);
#ifdef __cplusplus
}
#endif

#endif