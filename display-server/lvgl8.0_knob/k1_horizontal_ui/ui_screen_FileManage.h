/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2023-09-22 23:50:51
 */
#ifndef _UI_SCREEN_FILEMANAGE_H
#define _UI_SCREEN_FILEMANAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "ui.h"

#define PAGE_MAX_DIRENT_COUNT 3

typedef enum Screen_Type
{
    SCREEN_FILE,
    SCREEN_SUBDIR,
    SCREEN_HISTORY,
}Screen_Type_t;


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

//文件拷贝、删除时存储起目录

void ui_ScreenFileManage_screen_init(void);
void LoadFileManageScreen(void);
void LoadFileManageScreenAndObjs(bool IsEntered);

/***************call by subdir screen and PrintHistory screen************************/
void file_manage_switch_screen(Screen_Type_t screen);
void file_manage_switch_disk(bool is_local); 
/*****************************************/

/***************call by cmd respone thread************************/
void file_manage_set_files_count(int count);  
void file_manage_set_print_record_info(print_record_info_t record_arry[3], int real_record_count); // row_no is 0 to 2
void file_manage_set_print_record_count(int count);
void file_manage_set_u_disk_status(bool inserted);
void refresh_copyprocess(int process, int copyto);
/***************************************/
void file_manage_change_language_text(void);
void filemanage_page_set_wifi_status(int intensity);
void filemanage_page_refresh_laserstate(int laser_state);
void filemanage_page_refresh_camerastate(int camera_state);
bool get_is_local_disk(void);
void set_is_local_disk(bool state);
int GetFileGcodeListNum(void);
bool FileListNumberHasChanged(void);
void MonitorLocalDirectory(char *localPath);
void MonitorUdiskDirectory(char *uDiskPath);

#ifdef __cplusplus
}
#endif

#endif