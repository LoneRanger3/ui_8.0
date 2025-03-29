#ifndef __PRUSASLICER_GCODE_PARSER_H__
#define __PRUSASLICER_GCODE_PARSER_H__
#include "GlobalGcodeParser.h"

#ifdef  __cplusplus  
extern "C" {  
#endif
char* PrusaSlicerIsMatch(char* cont);
bool PrusaSlicerGetTotalTime(char *line,uint32_t *totalTime);
bool PrusaSlicerGetFilamentUsed(char *line,double *consumables);
char* PrusaSlicerGetMaterialName(char *line);
bool PrusaSlicerGetLayerHeight(char *line,double *floorHeight);
bool PrusaSlicerMatchThumbnailsStart(char * line);
bool PrusaSlicerMatchPhotoStart(char * line);
bool PrusaSlicerMatchPhotoEnd(char * line);
#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */ 
#endif
