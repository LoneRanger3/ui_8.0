/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-04-28 17:05:04
 * @LastEditTime: 2023-07-18 17:51:36
 */
#include "PrusaSlicerGcodeParser.h"
static char *matchstr[] = {"PrusaSlicer","OrcaSlicer","SuperSlicer","SliCR-3D","BambuStudio","A3dp-Slicer"};
char* PrusaSlicerIsMatch(char* cont)
{
    return IsMatchType(cont,matchstr,sizeof(matchstr)/sizeof(matchstr[0]));
}

bool PrusaSlicerGetTotalTime(char *line,uint32_t *totalTime)
{
    if (strstr(line, LOCAL_MODEL_TIME_1))
    {
        char *regex = "[0-9]{1,3}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(line, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &line[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            temp[i] = atoi(str);
        }

        switch (regexSize) {
            case 1: *totalTime  = temp[0]; break;
            case 2: *totalTime  = temp[0] * 60 + temp[1]; break;
            case 3: *totalTime  = (temp[0] * 60 + temp[1]) * 60 + temp[2]; break;
        }
        return true;
    }

    return false;
}

bool PrusaSlicerGetFilamentUsed(char *line,double *consumables)
{
    if (strstr(line, LOCAL_MODEL_FILAMENT_1))
    {
        char *regex = "[0-9]+(.[0-9]+)?|[0-9]+(.[0-9]+)?";
        regmatch_t regmatch[5];
        UserGetRegexStr(line, regex, regmatch, 5);

        int cnt = regmatch[0].rm_eo - regmatch[0].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &line[regmatch[0].rm_so], cnt);
        str[cnt] = '\0';

        *consumables = atof(str);
        return true;
    }
    return false;
}

char* PrusaSlicerGetMaterialName(char *line)
{
    char *materialName = NULL;
    if (strstr(line, MATERIAL_NAME_2)) {
        materialName = strstr(line, MATERIAL_NAME_2) + strlen(MATERIAL_NAME_2);
        TrimLineEnd(materialName);
    }

    return materialName;
}

bool PrusaSlicerGetLayerHeight(char *line,double *floorHeight)
{
    if (strstr(line, LOCAL_MODEL_LAYER_H_PRUSA))
    {
        char *regex = "[0-9]+(.[0-9]+)?|[0-9]+(.[0-9]+)?";
        regmatch_t regmatch[5];
        UserGetRegexStr(line, regex, regmatch, 5);

        int cnt = regmatch[0].rm_eo - regmatch[0].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &line[regmatch[0].rm_so], cnt);
        str[cnt] = '\0';
        
        *floorHeight = atof(str);
        return true;
    }
    return false;
}

bool PrusaSlicerMatchThumbnailsStart(char * line)
{
    if(strstr(line, LOCAL_PHOTO_BEGIN_PRUSA))
    {
        char *regex = "[0-9]{1,10}";
        regmatch_t regmatch[5];
        UserGetRegexStr(line, regex, regmatch, 5);

        int cnt = regmatch[0].rm_eo - regmatch[0].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &line[regmatch[0].rm_so], cnt);
        str[cnt] = '\0';
        
        int w = atoi(str);
        if(w<300)
            return true;
    }
    return false;
}

bool PrusaSlicerMatchPhotoStart(char * line)
{
    if (strstr(line, LOCAL_PHOTO_BEGIN_PRUSA))
    {
        char *regex = "[0-9]{1,10}";
        regmatch_t regmatch[5];
        UserGetRegexStr(line, regex, regmatch, 5);

        int cnt = regmatch[0].rm_eo - regmatch[0].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &line[regmatch[0].rm_so], cnt);
        str[cnt] = '\0';
        
        int w = atoi(str);
        if(w>=300)
            return true;
    }
    return false;
}

bool PrusaSlicerMatchPhotoEnd(char * line)
{
    if (strstr(line, LOCAL_THUMBNAIL_END))
        return true;
    return false;
}
