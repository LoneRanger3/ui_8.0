/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-05-04 17:14:27
 * @LastEditTime: 2023-07-18 18:08:43
 */
#include "CuraGcodeParser.h"
static char *matchstr[] = {"Cura_SteamEngine"};
char* CuraIsMatch(char* cont)
{
    return IsMatchType(cont,matchstr,sizeof(matchstr)/sizeof(matchstr[0]));
}