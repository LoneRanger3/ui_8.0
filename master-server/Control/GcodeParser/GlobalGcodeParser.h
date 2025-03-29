/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-04-28 16:56:04
 * @LastEditTime: 2023-07-18 17:47:28
 */
#ifndef __GLOBAL_GCODE_PARSER_H__
#define __GLOBAL_GCODE_PARSER_H__
#include <sys/time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "../AppPrint.h"
#include "../GcodEmetadata.h"

#ifdef  __cplusplus  
extern "C" {  
#endif
char* IsMatchType(char *cont,char **matchstr,int size);
void TrimLineEnd(char* line);
void getvalue(char *line,char* flag,double *value);
char* GlobalIsMatch(char* cont);
bool GlobalMatchThumbnailsStart(char * line);
bool GlobalMatchPhotoStart(char * line);
bool GlobalMatchPhotoEnd(char * line);
char* GlobalGetPhotoData(char *line);
bool GlobalGetLayerHeight(char *line,double *floorHeight);
bool GlobalGetTotalTime(char *line,uint32_t *totalTime);
bool GlobalGetFilamentUsed(char *line,double *consumables);
bool GlobalGetMinX(char *line,double *value);
bool GlobalGetMinY(char *line,double *value);
bool GlobalGetMinZ(char *line,double *value);
bool GlobalGetMaxX(char *line,double *value);
bool GlobalGetMaxY(char *line,double *value);
bool GlobalGetMaxZ(char *line,double *value);
char* GlobalGetMaterialName(char *line);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */ 
#endif