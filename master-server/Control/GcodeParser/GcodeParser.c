/*
 * @Description :
 * @Author      : Yufeng Zhang
 * @Date: 2023-04-28 13:50:17
 * @LastEditTime: 2023-07-18 17:39:37
 */
#include <sys/time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

#include "Base/MasterMsgBase.h"
#include "GcodeParser.h"
#define SERIAL_PORT_MAX_DATA_FRAME_LEN      2048 // 处理最大窗口数据帧长度

struct GcodeParser GlobleParser = {
    .name = NULL,
    .ismatch = GlobalIsMatch,
    .matchthumbnailsstart = GlobalMatchThumbnailsStart,
    .matchphotostart = GlobalMatchPhotoStart,
    .matchphotoend = GlobalMatchPhotoEnd,
    .getphotodata = GlobalGetPhotoData,
    .getlayerheight = GlobalGetLayerHeight,
    .gettotaltime = GlobalGetTotalTime,
    .getfilamentused = GlobalGetFilamentUsed,
    .getminx = GlobalGetMinX,
    .getminy = GlobalGetMinY,
    .getminz = GlobalGetMinZ,
    .getmaxx = GlobalGetMaxX,
    .getmaxy = GlobalGetMaxY,
    .getmaxz = GlobalGetMaxZ,
    .getmaterialname = GlobalGetMaterialName,
};

struct GcodeParser PrusaSlicerParser = {
    .name = NULL,
    .ismatch = PrusaSlicerIsMatch,
    .matchthumbnailsstart = PrusaSlicerMatchThumbnailsStart,
    .matchphotostart = PrusaSlicerMatchPhotoStart,
    .matchphotoend = PrusaSlicerMatchPhotoEnd,
    .getphotodata = GlobalGetPhotoData,
    .getlayerheight = PrusaSlicerGetLayerHeight,
    .gettotaltime = PrusaSlicerGetTotalTime,
    .getfilamentused = PrusaSlicerGetFilamentUsed,
    .getminx = GlobalGetMinX,
    .getminy = GlobalGetMinY,
    .getminz = GlobalGetMinZ,
    .getmaxx = GlobalGetMaxX,
    .getmaxy = GlobalGetMaxY,
    .getmaxz = GlobalGetMaxZ,
    .getmaterialname = PrusaSlicerGetMaterialName,
};

struct GcodeParser CuraParser = {
    .name = NULL,
    .ismatch = CuraIsMatch,
    .matchthumbnailsstart = GlobalMatchThumbnailsStart,
    .matchphotostart = GlobalMatchPhotoStart,
    .matchphotoend = GlobalMatchPhotoEnd,
    .getphotodata = GlobalGetPhotoData,
    .getlayerheight = GlobalGetLayerHeight,
    .gettotaltime = GlobalGetTotalTime,
    .getfilamentused = GlobalGetFilamentUsed,
    .getminx = GlobalGetMinX,
    .getminy = GlobalGetMinY,
    .getminz = GlobalGetMinZ,
    .getmaxx = GlobalGetMaxX,
    .getmaxy = GlobalGetMaxY,
    .getmaxz = GlobalGetMaxZ,
    .getmaterialname = GlobalGetMaterialName,
};

struct GcodeParser SimplifyParser = {
    .name = NULL,
    .ismatch = SimplifyIsMatch,
    .matchthumbnailsstart = GlobalMatchThumbnailsStart,
    .matchphotostart = GlobalMatchPhotoStart,
    .matchphotoend = GlobalMatchPhotoEnd,
    .getphotodata = GlobalGetPhotoData,
    .getlayerheight = SimplifyGetLayerHeight,
    .gettotaltime = SimplifyGetTotalTime,
    .getfilamentused = SimplifyGetFilamentUsed,
    .getminx = GlobalGetMinX,
    .getminy = GlobalGetMinY,
    .getminz = GlobalGetMinZ,
    .getmaxx = GlobalGetMaxX,
    .getmaxy = GlobalGetMaxY,
    .getmaxz = GlobalGetMaxZ,
    .getmaterialname = SimplifyGetMaterialName,
};

struct GcodeParser *parserlist[] = {&GlobleParser,&PrusaSlicerParser,&CuraParser,&SimplifyParser};

struct GcodeParser *GcodeParserGet(char *filename)
{
    if (filename == NULL)
        return parserlist[0];
    //CrLogI("GcodeParserGet filename %s\n",filename);
    int cmdlen = strlen(filename) + 100;
    char *cmd = malloc(cmdlen);
    if (cmd == NULL)
        return parserlist[0];
    memset(cmd,0,cmdlen);
    strcpy(cmd, "grep -i generated '");
    strcat(cmd, filename);
    strcat(cmd, "'");
    char sysRes[1024] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
    {
        free(cmd);
        return parserlist[0];
    }
    free(cmd);
    if (strlen(sysRes) < 1)
        return parserlist[0];

    for(int i=0;i<sizeof(parserlist)/sizeof(parserlist[0]); i++)
    {
        if(parserlist[i]->ismatch(sysRes)){
            //CrLogI("GcodeParserGet ret %d\n",i);
            return parserlist[i];
        }
    }
    
    return parserlist[0];
}

struct GcodeParser* GcodeParserGetByName(char *fileName)
{
    struct GcodeParser* Parser = NULL;
    FILE *fd = fopen(fileName, "r");
    if (fd == NULL)
    {
        CrLogW("gcode file open failed = %s\n", fileName);
        return 0;
    }
    char readb[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
    while (fgets(readb, SERIAL_PORT_MAX_DATA_FRAME_LEN, fd) != NULL)
    {
        if (strstr(readb, "enerated"))
        {
            break;
        }
    }
    Parser = GcodeParserGetByStr(readb);
    fclose(fd);
    return Parser;
}

struct GcodeParser* GcodeParserGetByStr(char *content)
{
    for(int i=0;i<sizeof(parserlist)/sizeof(parserlist[0]); i++)
    {
        parserlist[i]->name = parserlist[i]->ismatch(content);
        if(parserlist[i]->name){
            //CrLogI("GcodeParserGetByStr ret %d\n",i);
            return parserlist[i];
        }
    }
    
    return parserlist[0];
}

