/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-04-28 17:11:25
 * @LastEditTime: 2023-07-18 18:10:22
 */
#include "SimplifyGcodeParser.h"
static char *matchstr[] = {"Simplify"};
char* SimplifyIsMatch(char* cont)
{
    return IsMatchType(cont,matchstr,sizeof(matchstr)/sizeof(matchstr[0]));
}

bool SimplifyGetLayerHeight(char *line,double *floorHeight)
{
    if (strstr(line, LOCAL_MODEL_LAYER_H_1))
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

bool SimplifyGetTotalTime(char *line,uint32_t *totalTime)
{
    if (strstr(line, LOCAL_MODEL_TIME_2))
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
            case 1: *totalTime = temp[0] * 60; break;
            case 2: *totalTime = (temp[0] * 60 + temp[1]) * 60; break;
        }
        return true;
    }
    return false;
}

bool SimplifyGetFilamentUsed(char *line,double *consumables)
{
    if (strstr(line, LOCAL_MODEL_FILAMENT_2))
    {
        char *regex = "[0-9]+(.[0-9]+)?|[0-9]+(.[0-9]+)?";
        regmatch_t regmatch[5];
        UserGetRegexStr(line, regex, regmatch, 5);

        int cnt = regmatch[1].rm_eo - regmatch[1].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &line[regmatch[1].rm_so], cnt);
        str[cnt] = '\0';

        *consumables = atof(str) * 1000 + 0.5;
        return true;
    }
    return false;
}

char* SimplifyGetMaterialName(char *line)
{
    char *materialName = NULL;
    if (strstr(line, MATERIAL_NAME_SIMP)) {
        materialName = strstr(line, MATERIAL_NAME_SIMP) + strlen(MATERIAL_NAME_SIMP);
        TrimLineEnd(materialName);
    }

    return materialName;
}
