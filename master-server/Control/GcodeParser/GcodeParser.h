/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-04-28 11:15:23
 * @LastEditTime: 2023-07-18 17:37:06
 */
/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-04-28 11:15:23
 * @LastEditTime: 2023-04-28 16:24:07
 */
#ifndef __GCODE_PARSER_H__
#define __GCODE_PARSER_H__
#include "../AppPrint.h"
#include "../GcodEmetadata.h"
#include "GlobalGcodeParser.h"
#include "PrusaSlicerGcodeParser.h"
#include "SimplifyGcodeParser.h"
#include "CuraGcodeParser.h"

#ifdef  __cplusplus  
extern "C" {  
#endif

struct GcodeParser
{
    char *name;
    char* (*ismatch)(char *);
    bool (*matchthumbnailsstart)(char *);
    bool (*matchphotostart)(char *);
    bool (*matchphotoend)(char *);
    char* (*getphotodata)(char *);
    bool (*getlayerheight)(char *,double*);  
    bool (*gettotaltime)(char *,uint32_t*); 
    bool (*getfilamentused)(char *,double*);
    bool (*getminx)(char *,double*);  
    bool (*getminy)(char *,double*);  
    bool (*getminz)(char *,double*);  
    bool (*getmaxx)(char *,double*);  
    bool (*getmaxy)(char *,double*);  
    bool (*getmaxz)(char *,double*); 
    char* (*getmaterialname)(char *);  
};

struct GcodeParser* GcodeParserGet(char * filename);
struct GcodeParser* GcodeParserGetByStr(char *content);
struct GcodeParser* GcodeParserGetByName(char *fileName);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */ 
#endif
