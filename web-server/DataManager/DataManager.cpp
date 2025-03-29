/**
 * @ Author: Rui Xiong
 * @ Create Time: 2022-11-14 10:28:06
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-04-20 14:09:14
 * @ Description:
 */

#include <iostream>
#include <thread>
#include <limits>
#include <string.h>
#include "Base/Ini.h"
#include "Base/WebMsgBase.h"
#include "Message/ServerMessage.h"
#include "DataManager.h"

DataManager *DataManager::m_Instance = nullptr;

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {* args} *
 */
DataManager::DataManager()
{
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
DataManager::~DataManager()
{
    
}

int DataManager::ControlVideoFilesResult(int ret)
{
    json_object *result = json_object_new_object();
    json_object_object_add(result, "code", json_object_new_int(ret));
    //json_object_object_add(result, "msg", json_object_new_string("fail"));
    std::string response = json_object_to_json_string(result);
    sendMessageToWSClient(response);

    json_object_put(result);
}

int DataManager::PrintObjectResult(std::string objectInfo)
{
    const char *objectsStr = "", *excludedStr = "", *currentStr = "";

    // 解析对象排除信息
    json_object *infoObj = json_tokener_parse(objectInfo.c_str());
    if (infoObj) {
        json_object *tempObj = GetJsonObject(infoObj, (char*)"objects", json_type_array);
        if (tempObj) objectsStr = json_object_to_json_string(tempObj);

        tempObj = GetJsonObject(infoObj, (char*)"excluded_objects", json_type_array);
        if (tempObj) excludedStr = json_object_to_json_string(tempObj);

        tempObj = GetJsonObject(infoObj, (char*)"current_object", json_type_string);
        if (tempObj) currentStr = json_object_get_string(tempObj);
    }

    json_object *result = json_object_new_object();
    json_object_object_add(result, "current_object", json_object_new_string(currentStr));
    json_object_object_add(result, "excluded_objects", json_object_new_string(excludedStr));
    json_object_object_add(result, "objects", json_object_new_string(objectsStr));

    std::string response = json_object_to_json_string(result);
    CrLogI("get print objects:%s",response.c_str());

    sendMessageToWSClient(response);
    json_object_put(infoObj);
    json_object_put(result);
}
/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {string} path
 */
int DataManager::ReportGcodeFileNum(std::string path)
{
    // 打开文件
    FILE *fileInfoFd = fopen(path.c_str(), "r");
    if (fileInfoFd == NULL){
        CrLogE("open %s error", path.c_str());
        return -1;
    }

    std::string fileInfoStr;
    int totalNum;
    // 读取文件
    int readSizeMax = 1024;
    char readBuff[readSizeMax];
    int count = 0;
    memset(readBuff, 0, readSizeMax);
    while (fgets(readBuff, readSizeMax, fileInfoFd) != NULL){
        struct json_object* fileInfo = json_tokener_parse(readBuff);
        memset(readBuff, 0, readSizeMax);
        json_object *sumObj = json_object_object_get(fileInfo, "fileSum");
        if (sumObj != NULL){
            totalNum = json_object_get_int(sumObj);
            json_object_put(fileInfo);
            break;
        }
    }
    fclose(fileInfoFd);
    
    return totalNum;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} result
 */
int DataManager::ReportWebControlPrint(int result)
{
    // 发布RPC设置结果到WEB
    json_object *rpcReport = json_object_new_object();
    if (result) {
        json_object_object_add(rpcReport, "code", json_object_new_int(0));
        json_object_object_add(rpcReport, "msg", json_object_new_string("success"));
    }
    else json_object_object_add(rpcReport, "code", json_object_new_int(-1));

    std::string response = json_object_to_json_string(rpcReport);
    //m_mqttServerClient.ResponseRpc(response);
    json_object_put(rpcReport);

    return 0;
}
/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {string} path
 */
int DataManager::ReportOtaInfo(UpgradeInfoList* infoList)
{
    CrLogI("get ota info");

    if(infoList){
        json_object *otaInfo = json_object_new_object();
        if (infoList->linuxota) {
            UpgradeInfo *info = infoList->linuxota;
            if (info->has_version) {
                json_object *linuxOtaInfo = json_object_new_object();
                json_object_object_add(linuxOtaInfo, "version", json_object_new_string((const char*)info->version.data));
                json_object_object_add(linuxOtaInfo, "url", json_object_new_string((const char*)info->url.data));
                json_object_object_add(linuxOtaInfo, "name", json_object_new_string((const char*)info->name.data));
                json_object_object_add(linuxOtaInfo, "size", json_object_new_int(info->size));
                json_object_object_add(otaInfo, "linuxOtaInfo", linuxOtaInfo);
            }
        }
        if (infoList->mcu1ota) {
            UpgradeInfo *info = infoList->mcu1ota;
            if (info->has_version) {
                json_object *mcuOtaInfo = json_object_new_object();
                json_object_object_add(mcuOtaInfo, "version", json_object_new_string((const char*)info->version.data));
                json_object_object_add(mcuOtaInfo, "url", json_object_new_string((const char*)info->url.data));
                json_object_object_add(mcuOtaInfo, "name", json_object_new_string((const char*)info->name.data));
                json_object_object_add(mcuOtaInfo, "size", json_object_new_int(info->size));
                json_object_object_add(otaInfo, "mcuOtaInfo", mcuOtaInfo);
            }
        }        
        std::string send = json_object_to_json_string(otaInfo);
        sendMessageToWSClient(send);
        json_object_put(otaInfo);
        return 1;
    }
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {std::string} message
 */
void DataManager::sendMessageToWSClient(std::string message)
{
    WebSocket::getInstance()->sendToAllSocket(message);
}
