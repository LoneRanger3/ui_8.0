/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2023-08-25 03:24:01
 */
#ifndef _UI_SCREEN_SUBDIR_H
#define _UI_SCREEN_SUBDIR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "ui.h"
#include "ui_screen_FileManage.h"



extern lv_obj_t * ui_ScreenSubDir;

void ui_ScreenSubDir_screen_init(void);
void LoadSubDirScreen(void);

/*****************call by filemanage**************************/
void sub_dir_set_files_count(int count);  
void sub_dir_set_file_infos(Dirent_Info_t dirent_array[8], int real_count);
void sub_dir_enter_screen_settings(dirent_info_part_t *part);
//void sub_dir_enter_screen_settings(char *dir_name, uint16_t dir_sort_index, bool parent_disk_is_local);

void sub_dir_change_language_text(void);
int GetSubDGcodeFileNum(bool udisk, uint16_t part_index);

/*****************call by filemanage**************************/


#ifdef __cplusplus
}
#endif

#endif