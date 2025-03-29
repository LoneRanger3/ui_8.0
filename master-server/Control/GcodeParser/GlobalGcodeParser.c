#include "GlobalGcodeParser.h"

char* IsMatchType(char *cont,char **matchstr,int size)
{
    char* ret = NULL;

    for (int i = 0; i < size; i++)
    {
        if(strstr(cont,matchstr[i]))
        {
            ret = matchstr[i];
            break;
        }
    }
    return ret;
}

void TrimLineEnd(char* line)
{
    char *line1 = strstr(line, "\r\n");
    if (line1) {
        line1[0] = '\0';
        return;
    }
    char *line2 = strstr(line, "\n");
    if (line2) {
        line2[0] = '\0';
        return ;
    }
    char *line3 = strstr(line, "\r");
    if (line3) 
    {
        line3[0] = '\0';
        return;
    }
}

static char *matchstr[] = {"Creality"};
char* GlobalIsMatch(char* cont)
{
    return IsMatchType(cont,matchstr,sizeof(matchstr)/sizeof(matchstr[0]));
}

bool GlobalMatchThumbnailsStart(char * line)
{
    if(strstr(line, LOCAL_IMAGE_BEGIN) || strstr(line, LOCAL_IMAGE_BEGIN_1))
        return true;
    return false;
}

bool GlobalMatchPhotoStart(char * line)
{
    if (strstr(line, LOCAL_PHOTO_BEGIN))
        return true;
    return false;
}

bool GlobalMatchPhotoEnd(char * line)
{
    if (strstr(line, LOCAL_PNG_END))
        return true;
    return false;
}

char* GlobalGetPhotoData(char *line)
{
    char *validData = line + strlen("; ");
    TrimLineEnd(validData);
    return validData;
}

bool GlobalGetLayerHeight(char *line,double *floorHeight)
{
    if (strstr(line, LOCAL_MODEL_LAYER_H))
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

bool GlobalGetTotalTime(char *line,uint32_t *totalTime)
{
    if (strstr(line, LOCAL_MODEL_TIME))
    {
        char *regex = "[0-9]{1,10}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(line, regex, regmatch, 5);

        uint32_t temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &line[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            temp[i] = atoll(str);
        }

        *totalTime = temp[0];
        return true;
    }
    return false;
}

bool GlobalGetFilamentUsed(char *line,double *consumables)
{
    if (strstr(line, LOCAL_MODEL_FILAMENT))
    {
        char *regex = "[0-9]+(.[0-9]+)?|[0-9]+(.[0-9]+)?";
        regmatch_t regmatch[5];
        UserGetRegexStr(line, regex, regmatch, 5);

        int cnt = regmatch[0].rm_eo - regmatch[0].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &line[regmatch[0].rm_so], cnt);
        str[cnt] = '\0';

        *consumables = atof(str) * 1000 + 0.5;
        return true;
    }
    return false;
}

void getvalue(char *line,char* flag,double *value)
{
    char *vstr = strstr(line, flag) + strlen(flag);
    *value = atof(vstr);
}

bool GlobalGetMinX(char *line,double *value)
{
    if (strstr(line, LOCAL_MODEL_MIN_X))
    {
        getvalue(line, LOCAL_MODEL_MIN_X,value);
        return true;
    }
    return false;
}

bool GlobalGetMinY(char *line,double *value)
{
    if (strstr(line, LOCAL_MODEL_MIN_Y))
    {
        getvalue(line, LOCAL_MODEL_MIN_Y,value);
        return true;
    }
    return false;
}

bool GlobalGetMinZ(char *line,double *value)
{
    if (strstr(line, LOCAL_MODEL_MIN_Z))
    {
        getvalue(line, LOCAL_MODEL_MIN_Z,value);
        return true;
    }
    return false;
}

bool GlobalGetMaxX(char *line,double *value)
{
    if (strstr(line, LOCAL_MODEL_MAX_X))
    {
        getvalue(line, LOCAL_MODEL_MAX_X,value);
        return true;
    }
    return false;
}

bool GlobalGetMaxY(char *line,double *value)
{
    if (strstr(line, LOCAL_MODEL_MAX_Y))
    {
        getvalue(line, LOCAL_MODEL_MAX_Y,value);
        return true;
    }
    return false;
}

bool GlobalGetMaxZ(char *line,double *value)
{
    if (strstr(line, LOCAL_MODEL_MAX_Z))
    {
        getvalue(line, LOCAL_MODEL_MAX_Z,value);
        return true;
    }
    return false;
}

char* GlobalGetMaterialName(char *line)
{
    char *materialName = NULL;
    if (strstr(line, MATERIAL_NAME_1)) {
        materialName = strstr(line, MATERIAL_NAME_1) + strlen(MATERIAL_NAME_1);
        TrimLineEnd(materialName);
    }
    else if (strstr(line, MATERIAL_NAME_3)) {
        materialName = strstr(line, MATERIAL_NAME_3) + strlen(MATERIAL_NAME_3);
        TrimLineEnd(materialName);
    }
    else if (strstr(line, MATERIAL_NAME_4)) {
        materialName = strstr(line, MATERIAL_NAME_4) + strlen(MATERIAL_NAME_4);
        TrimLineEnd(materialName);
    }

    return materialName;
}