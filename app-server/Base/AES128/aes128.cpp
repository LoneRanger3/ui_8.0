/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-08-31 14:17:11
 * @LastEditTime: 2023-10-16 15:35:37
 */
#include <string>
#include "../AppMsgBase.h"

/**
 * @description: 
 * @return {*}
 * @param {string} str
 */
std::string AppAesEncryptToBase64(std::string str)
{
    std::string result;
    char *getStr = AesEncryptToBase64((char*)str.c_str(), str.length());
    if (getStr) {
        result = getStr;
        free(getStr);
    }
    return result;
}

/**
 * @description: 
 * @return {*}
 * @param {string} str
 */
std::string AppAesDecryptFromBase64(std::string str)
{
    std::string result;
    char *getStr = AesDecryptFromBase64((char*)str.c_str(), str.length());
    if (getStr) {
        result = getStr;
        free(getStr);
    }
    return result;
}

/**
 * @description: 
 * @return {*}
 * @param {string} path
 * @param {string} str
 */
int AppAesEncryptToFile(std::string path, std::string str)
{
    return AesEncryptToFile((char*)path.c_str(), (char*)str.c_str(), str.length());
}

/**
 * @description: 
 * @return {*}
 * @param {string} str
 */
std::string AppAesDecryptFromFile(std::string str)
{
    std::string result;
    if(access(str.c_str(),0))
    {
        CrLogI("file no exists !\n");
        return result;
    }
    char *getStr = AesDecryptFromFile((char*)str.c_str());
    if (getStr) {
        result = getStr;
        free(getStr);
    }
    return result;
}
