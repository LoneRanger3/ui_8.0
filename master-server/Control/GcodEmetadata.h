/*
 * @Description : 解析gcode元数据
 * @Author      : Yufeng Zhang
 * @Date: 2023-01-04 15:59:27
 * @LastEditTime: 2023-06-13 12:08:09
 */

#ifndef __GCODE_EMETADATA_H__
#define __GCODE_EMETADATA_H__

#include "AppPrint.h"

#ifdef  __cplusplus  
extern "C" {  
#endif

#define BIG_IMAGE_PARA_SIZE     4

typedef enum {
    GCODE_PHOTO_TYPE_PREVIEW,
    GCODE_PHOTO_TYPE_PRINT,
}GcodePhotoType_t;

int GetPrintParaFromGcodeFile(char *fileName, CurrentFile_t *para);
int GetLocalGcodePhotoToFile(char *fileName, CurrentFile_t *para, GcodePhotoType_t type);

// gcode 本地文件字符串协议定义
#define LOCAL_IMAGE_BEGIN       "png begin 48*48"
#define LOCAL_IMAGE_BEGIN_1     "png begin 96*96"
#define LOCAL_PHOTO_BEGIN       "png begin 300*300"
#define LOCAL_PNG_END           "png end"

#define LOCAL_PHOTO_BEGIN_PRUSA   "thumbnail begin"
#define LOCAL_THUMBNAIL_END       "thumbnail end"

#define GET_LAYER_CHANGES       ";LAYER:"
#define GET_LAYER_CHANGES_1     "; LAYER:"
#define GET_LAYER_CHANGES_2     ";layer"
#define GET_LAYER_CHANGES_3     "; layer"
#define GET_LAYER_CHANGES_4     ";AFTER_LAYER_CHANGE" 
#define LOCAL_MODEL_TIME        "TIME:"
#define LOCAL_MODEL_TIME_1      "estimated printing time (normal mode)"
#define LOCAL_MODEL_TIME_2      "Build time:"
#define LOCAL_MODEL_FILAMENT    "Filament used:"
#define LOCAL_MODEL_FILAMENT_1  "filament used [mm]"
#define LOCAL_MODEL_FILAMENT_2  "Filament length:"
#define LOCAL_MODEL_LAYER_H     "Layer height:"
#define LOCAL_MODEL_LAYER_H_1   "layerHeight"
#define LOCAL_MODEL_LAYER_H_PRUSA   "; layer_height"
#define LOCAL_MODEL_MIN_X       "MINX:"
#define LOCAL_MODEL_MIN_Y       "MINY:"
#define LOCAL_MODEL_MIN_Z       "MINZ:"
#define LOCAL_MODEL_MAX_X       "MAXX:"
#define LOCAL_MODEL_MAX_Y       "MAXY:"
#define LOCAL_MODEL_MAX_Z       "MAXZ:"
#define MATERIAL_NAME_1         "Material Type:"
#define MATERIAL_NAME_2         "filament_type = "
#define MATERIAL_NAME_3         "Material Name:"
#define MATERIAL_NAME_4         "Material name:"
#define MATERIAL_NAME_SIMP      "printMaterial,"
#define FILE_START_PRINT        "START_PRINT "

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
