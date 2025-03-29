/*
 * @Date         : 2023-08-16 19:46:52
 * @LastEditors  : fangjinlun fangjinlun@creality.com
 * @LastEditTime : 2023-08-18 15:02:09
 */
#ifndef _BED_MESH_ADJUST_H
#define _BED_MESH_ADJUST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_BedMeshBg;

void ui_BedMesh_screen_init(void);
void refresh_BedMesh_data(int len,char * data);
void refresh_BedMesh_point(unsigned int len, char *data);
void BedMesh_AutoLeveling_completed(void);
void ui_DiapScreenAutoLevelPage(void);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif