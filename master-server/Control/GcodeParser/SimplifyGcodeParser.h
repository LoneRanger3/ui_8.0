/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-05-05 09:53:11
 * @LastEditTime: 2023-07-18 17:49:48
 */
/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-04-28 17:11:15
 * @LastEditTime: 2023-05-04 19:53:01
 */
#ifndef __SIMPLIFY_GCODE_PARSER_H__
#define __SIMPLIFY_GCODE_PARSER_H__
#include "GlobalGcodeParser.h"

#ifdef  __cplusplus  
extern "C" {  
#endif
char* SimplifyIsMatch(char* cont);
bool SimplifyGetLayerHeight(char *line,double *floorHeight);
bool SimplifyGetTotalTime(char *line,uint32_t *totalTime);
bool SimplifyGetFilamentUsed(char *line,double *consumables);
char* SimplifyGetMaterialName(char *line);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */ 
#endif