/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-04-06 21:25:04
 * @LastEditTime: 2023-05-12 20:41:11
 */
#ifndef __GCODE_POINT_H__
#define __GCODE_POINT_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

int GetGcodePointCloudFromFile(char *gcodeFile, float segmentLen);
bool IsPointCloudRestored(void);
int GetGcodeModelSize(float *max_x, float *max_y, float *min_x, float *min_y);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
