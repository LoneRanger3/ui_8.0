/*
 * @Description : 解析gcode元数据
 * @Author      : Yufeng Zhang
 * @Date: 2023-01-04 15:59:14
 * @LastEditTime: 2023-07-20 10:03:19
 */
#include <sys/time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>

#include "Base/MasterMsgBase.h"
#include "AppPrint.h"
#include "GcodEmetadata.h"
#include "GcodeParser/GcodeParser.h"

#define READ_GCODE_SIZE                     (512 * 1024)
#define SERIAL_PORT_MAX_DATA_FRAME_LEN      2048 // 处理最大窗口数据帧长度

/**
 * @description: 
 * @return {*}
 */
static char *printMaterialName[] = {"PLA", "PETG", "PET", "TPU", "PA", "ABS", "ASA", "PC", "PLA-CF", "PA-CF", "PET-CF"};

/**
 * @description: 从不同切片软件生成的gcode文件中，获取预计打印时间
 * @return {*}
 * @param {char} *buf
 */
static bool GetPrintTtotalTimeFromGcodeFile(char *buf, uint32_t *time)
{
    if (strstr(buf, LOCAL_MODEL_TIME))
    {
        char *regex = "[0-9]{1,10}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(buf, regex, regmatch, 5);

        uint32_t temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &buf[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            temp[i] = atoll(str);
        }

        *time = temp[0];
        return true;
    }
    else if (strstr(buf, LOCAL_MODEL_TIME_1))
    {
        char *regex = "[0-9]{1,3}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(buf, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &buf[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            temp[i] = atoi(str);
        }

        switch (regexSize) {
            case 1: *time  = temp[0]; break;
            case 2: *time  = temp[0] * 60 + temp[1]; break;
            case 3: *time  = (temp[0] * 60 + temp[1]) * 60 + temp[2]; break;
        }
        return true;
    }
    else if (strstr(buf, LOCAL_MODEL_TIME_2))
    {
        char *regex = "[0-9]{1,3}";
        regmatch_t regmatch[5];
        int regexSize = UserGetRegexStr(buf, regex, regmatch, 5);

        int temp[5] = {0};
        for(int i = 0; i< regexSize; i++)
        {
            int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
            char str[cnt + 1];
            memset(str, 0, cnt + 1);
            memcpy(str, &buf[regmatch[i].rm_so], cnt);
            str[cnt] = '\0';
            temp[i] = atoi(str);
        }

        switch (regexSize) {
            case 1: *time = temp[0] * 60; break;
            case 2: *time = (temp[0] * 60 + temp[1]) * 60; break;
        }
        return true;
    }

    return false;
}

/**
 * @description: 从不同切片软件生成的gcode文件中，获取预计耗材长度
 * @return {*}
 * @param {char} *buf
 * @param {double} *consumables
 */
static bool GetPrintConsumablesFromGcodeFile(char *buf, double *consumables)
{
    if (strstr(buf, LOCAL_MODEL_FILAMENT))
    {
        char *regex = "[0-9]+(.[0-9]+)?|[0-9]+(.[0-9]+)?";
        regmatch_t regmatch[5];
        UserGetRegexStr(buf, regex, regmatch, 5);

        int cnt = regmatch[0].rm_eo - regmatch[0].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &buf[regmatch[0].rm_so], cnt);
        str[cnt] = '\0';

        *consumables = atof(str) * 1000 + 0.5;
        return true;
    }
    else if (strstr(buf, LOCAL_MODEL_FILAMENT_1))
    {
        char *regex = "[0-9]+(.[0-9]+)?|[0-9]+(.[0-9]+)?";
        regmatch_t regmatch[5];
        UserGetRegexStr(buf, regex, regmatch, 5);

        int cnt = regmatch[0].rm_eo - regmatch[0].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &buf[regmatch[0].rm_so], cnt);
        str[cnt] = '\0';

        *consumables = atof(str);
        return true;
    }
    else if (strstr(buf, LOCAL_MODEL_FILAMENT_2))
    {
        char *regex = "[0-9]+(.[0-9]+)?|[0-9]+(.[0-9]+)?";
        regmatch_t regmatch[5];
        UserGetRegexStr(buf, regex, regmatch, 5);

        int cnt = regmatch[1].rm_eo - regmatch[1].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &buf[regmatch[1].rm_so], cnt);
        str[cnt] = '\0';

        *consumables = atof(str) * 1000 + 0.5;
        return true;
    }

    return false;
}

/**
 * @description: 从不同切片软件生成的gcode文件中，获取模型层高
 * @return {*}
 * @param {double} *fileName
 * @param {char} *buf
 */
static bool GetPrintFloorHeightFromGcodeFile(char *buf, double *floorHeight)
{
    if (strstr(buf, LOCAL_MODEL_LAYER_H))
    {
        char *regex = "[0-9]+(.[0-9]+)?|[0-9]+(.[0-9]+)?";
        regmatch_t regmatch[5];
        UserGetRegexStr(buf, regex, regmatch, 5);

        int cnt = regmatch[0].rm_eo - regmatch[0].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &buf[regmatch[0].rm_so], cnt);
        str[cnt] = '\0';
        
        *floorHeight = atof(str);
        return true;
    }
    else if (strstr(buf, LOCAL_MODEL_LAYER_H_1))
    {
        char *regex = "[0-9]+(.[0-9]+)?|[0-9]+(.[0-9]+)?";
        regmatch_t regmatch[5];
        UserGetRegexStr(buf, regex, regmatch, 5);

        int cnt = regmatch[0].rm_eo - regmatch[0].rm_so;
        char str[cnt + 1];
        memset(str, 0, cnt + 1);
        memcpy(str, &buf[regmatch[0].rm_so], cnt);
        str[cnt] = '\0';
        
        *floorHeight = atof(str);
        return true;
    }

    return false;
}

/**
 * @description: 从不同切片软件生成的gcode文件中，获取打印耗材名称
 * @return {*}
 * @param {char} *fileName
 * @param {char} *buf
 */
static bool GetPrintMaterialFromGcodeFile(char *buf, char *material)
{
    char *materialName = NULL;
    if (strstr(buf, MATERIAL_NAME_1)) {
        materialName = strstr(buf, MATERIAL_NAME_1) + strlen(MATERIAL_NAME_1);
    }
    else if (strstr(buf, MATERIAL_NAME_2)) {
        materialName = strstr(buf, MATERIAL_NAME_2) + strlen(MATERIAL_NAME_2);
    }
    else if (strstr(buf, MATERIAL_NAME_3)) {
        materialName = strstr(buf, MATERIAL_NAME_3) + strlen(MATERIAL_NAME_3);
    }
    else if (strstr(buf, MATERIAL_NAME_4)) {
        materialName = strstr(buf, MATERIAL_NAME_4) + strlen(MATERIAL_NAME_4);
    }
    else return false;

    // 去除结束符
    char *line1 = strstr(materialName, "\r\n");
    char *line2 = strstr(materialName, "\n");
    char *line3 = strstr(materialName, "\r");
    if (line1) line1[0] = '\0';
    else if (line2) line2[0] = '\0';
    else if (line3) line3[0] = '\0';

    // 匹配符合字段
    int materialNum = sizeof(printMaterialName)/sizeof(printMaterialName[0]);
    for (int i = 0; i < materialNum; i++)
    {
        if (strcmp(materialName, printMaterialName[i]) == 0) {
            strcat(material, materialName);
            return true;
        }
    }

    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {FILE} *fb
 */
long GetGcodeStartByte(FILE *fb)
{
    // 读取文件数据
    char readBuff[READ_GCODE_SIZE] = {0};
    fseek(fb, 0, SEEK_SET);
    fread(readBuff, 1, READ_GCODE_SIZE, fb);

    // // 匹配G指令或M指令
    // char *regex = "\n[MG][0-9]+[ \f\n\r\t\v].*\n";
    // 匹配G0指令或G1指令
    char *regex = "\n[G][0-1]+[ \f\n\r\t\v].*\n";
    regmatch_t regmatch[5];
    int regexSize = UserGetRegexStr(readBuff, regex, regmatch, 5);

    // 记录第一次出现匹配指令的位置
    if (regexSize > 0) {
        CrLogI("gcode start byte = %d", regmatch[0].rm_so);
        return regmatch[0].rm_so;
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {FILE} *fb
 */
long GetGcodeEndByte(FILE *fb)
{
    // 计算文件大小
    fseek(fb, 0, SEEK_END);
    long size = ftell(fb);

    // 读取文件数据
    char readBuff[READ_GCODE_SIZE] = {0};
    if (size < READ_GCODE_SIZE) {
        fseek(fb, 0, SEEK_SET);
        fread(readBuff, 1, READ_GCODE_SIZE, fb);
    }
    else {
        fseek(fb, -READ_GCODE_SIZE, SEEK_END);
        fread(readBuff, 1, READ_GCODE_SIZE, fb);
    }

    // 文件数据倒叙
    ReverseString(readBuff);

    // 匹配G指令或M指令
    char *regex = "\n.*[ \f\n\r\t\v][0-9]+[MG]\n";
    regmatch_t regmatch[5];
    int regexSize = UserGetRegexStr(readBuff, regex, regmatch, 5);

    // 记录倒叙后第一次出现匹配指令的位置
    if (regexSize > 0) {
        long gcodeEndByte = size - regmatch[0].rm_so;
        CrLogI("gcode end byte = %d", gcodeEndByte);
        return gcodeEndByte;
    }
    return 0;
}

/**
 * @description: 从gcode文件获取元数据
 * @return {*}
 * @param {char} *fileName
 * @param {CurrentFile_t} *para
 */
int GetPrintParaFromGcodeFile(char *fileName, CurrentFile_t *para)
{
    // 判断路径是否为空
    if (fileName == NULL) {
        CrLogW("path is empty !!\n");
        return 0;
    }

    CrLogI("get gcode para from gcode gile");
    // 获取并创建文件夹路径
    if (para->thumbnails) {
        char *temp = strrchr(para->thumbnails, '/');
        if (temp) {
            char folderPath[256] = {0};
            memcpy(folderPath, para->thumbnails, temp - para->thumbnails);
            if (access(folderPath, F_OK) != 0)
            {
                char cmd[300] = {0};
                snprintf(cmd, sizeof(cmd), "mkdir -p '%s'", folderPath);

                // 调用系统命令
                char sysRes[1024] = {0};
                if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
                    CrLogW("system fail! res = %s\n", sysRes);
            }
        }
    }

    // 获取文件大小、创建时间
    struct stat stat_info;
    int ret = lstat(fileName, &stat_info);
    if (ret == 0) {
        para->size = stat_info.st_size;
        para->cTime = stat_info.st_ctim.tv_sec;
    }
    else CrLogW("%s get info error !", fileName);

    struct GcodeParser* Parser = GcodeParserGetByName(fileName);
    if (Parser == NULL) {
        CrLogW("Gcode Parser Get By Name fail\n");
        return 0;
    }
    if(Parser->name)
    {
        int len = strlen(Parser->name);
        memcpy(para->software,Parser->name,(len<sizeof(para->software))? len:(sizeof(para->software)-1));
    }
    // 打开gcode文件
    FILE *gcodeFileFd = fopen(fileName, "r");
    if (gcodeFileFd == NULL)
    {
        CrLogW("gcode file open failed = %s\n", fileName);
        return 0;
    }

    // image文件
    int saveImageFd = -1;

    // 读取gcode文件
    CrLogI("start read gcode file image");
    uint32_t timeCost = 0;
    double consumables = 0;
    double floorHeight = 0;
    char material[25] = {0};
    char *pmaterial = NULL;
    double modelMinX = 0, modelMinY = 0, modelMinZ = 0;
    double modelMaxX = 0, modelMaxY = 0, modelMaxZ = 0;
    bool startRecvImageFlag = false;
    bool successFlag = false;
    bool getGcodeInfoFromFileEnd = false;
    bool getGcodeInfoSuccess = false;
    char readBuff[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
    int lastImageOverBufLen = 0;
    char lastImageOverBuff[SERIAL_PORT_MAX_DATA_FRAME_LEN * 2] = {0};
    
    while (fgets(readBuff, SERIAL_PORT_MAX_DATA_FRAME_LEN, gcodeFileFd) != NULL)
    {
        // 从文件开始位置，或者文件结束前(READ_GCODE_SIZE)k位置；获取gcode信息
        if (!getGcodeInfoFromFileEnd && (strstr(readBuff, "G0 X") || strstr(readBuff, "G1 X")))
        {
            if (getGcodeInfoSuccess) break;
            else {
                // 如果在文件头部没有获取到gcode信息，就跳转到文件结束前(READ_GCODE_SIZE)k继续遍历获取信息
                getGcodeInfoFromFileEnd = true;
                long curLocal = ftell(gcodeFileFd);
                fseek(gcodeFileFd, 0, SEEK_END);

                long remainSize = ftell(gcodeFileFd) - curLocal;
                if (remainSize > READ_GCODE_SIZE)
                    fseek(gcodeFileFd, -READ_GCODE_SIZE, SEEK_END);
                else
                    fseek(gcodeFileFd, -remainSize, SEEK_END);
            }
        }
        else if (Parser->gettotaltime(readBuff, &timeCost))
        {
            para->estimated_time = timeCost;
            getGcodeInfoSuccess = true;
        }
        else if (Parser->getfilamentused(readBuff, &consumables))
        {
            para->filament_total = consumables;
        }
        else if (Parser->getlayerheight(readBuff, &floorHeight))
        {
            para->layer_height = floorHeight;
            CrLogI("layer_height = %f", para->layer_height);
        }
        else if (Parser->getminx(readBuff, &modelMinX))
        {
            //char *minX = strstr(readBuff, LOCAL_MODEL_MIN_X) + strlen(LOCAL_MODEL_MIN_X);
            //modelMinX = atof(minX);
        }
        else if (Parser->getminy(readBuff, &modelMinY))
        {
            //char *minY = strstr(readBuff, LOCAL_MODEL_MIN_Y) + strlen(LOCAL_MODEL_MIN_Y);
            //modelMinY = atof(minY);
        }
        else if (Parser->getminz(readBuff, &modelMinZ))
        {
            //char *minZ = strstr(readBuff, LOCAL_MODEL_MIN_Z) + strlen(LOCAL_MODEL_MIN_Z);
            //modelMinZ = atof(minZ);
        }
        else if (Parser->getmaxx(readBuff, &modelMaxX))
        {
            //char *maxX = strstr(readBuff, LOCAL_MODEL_MAX_X) + strlen(LOCAL_MODEL_MAX_X);
            para->object_light = modelMaxX - modelMinX;
        }
        else if (Parser->getmaxy(readBuff, &modelMaxY))
        {
            //char *maxY = strstr(readBuff, LOCAL_MODEL_MAX_Y) + strlen(LOCAL_MODEL_MAX_Y);
            para->object_weight = modelMaxY - modelMinY;
        }
        else if (Parser->getmaxz(readBuff, &modelMaxZ))
        {
            //char *maxZ = strstr(readBuff, LOCAL_MODEL_MAX_Z) + strlen(LOCAL_MODEL_MAX_Z);
            para->object_height = modelMaxZ - modelMinZ;
        }
        else if (pmaterial = Parser->getmaterialname(readBuff))
        {
            bzero(para->material, sizeof(para->material));
            memcpy(para->material, pmaterial, (strlen(pmaterial)<sizeof(para->material))? strlen(pmaterial):(sizeof(para->material)-1));
            CrLogI("material type = %s", para->material);
        }
        else if (strncmp(readBuff, FILE_START_PRINT, strlen(FILE_START_PRINT)) == 0)
        {
            char *regex = "[0-9]{1,3}.[0-9]*";
            regmatch_t regmatch[5];
            int regexSize = UserGetRegexStr(readBuff, regex, regmatch, 5);

            double temp[5] = {0};
            for(int i = 0; i< regexSize; i++)
            {
                int cnt = regmatch[i].rm_eo - regmatch[i].rm_so;
                char str[cnt + 1];
                memset(str, 0, cnt + 1);
                memcpy(str, &readBuff[regmatch[i].rm_so], cnt);
                str[cnt] = '\0';
                temp[i] = atof(str);
            }
            para->nozzle_target_temp = temp[0];
            para->bed_target_temp = temp[1];
        }
        else if (saveImageFd == -1 && Parser->matchthumbnailsstart(readBuff))
        {
            startRecvImageFlag = true;
            if (para->thumbnails) {
                saveImageFd = open(para->thumbnails, O_RDWR | O_CREAT | O_TRUNC , S_IRWXG | S_IRWXO | S_IRWXU);
                if(saveImageFd < 0) CrLogE("open %s failed.Fd = %d.", para->thumbnails, saveImageFd);
            }
        }
        else if (saveImageFd > 0 && Parser->matchphotoend(readBuff))
        {
            if (successFlag == false && startRecvImageFlag)
            {
                successFlag = true;
                startRecvImageFlag = false;
                // base64解码
                unsigned char decodeBuf[SERIAL_PORT_MAX_DATA_FRAME_LEN * 2] = {0};
                int decodeLen = Base64_decode(decodeBuf, sizeof(decodeBuf), lastImageOverBuff, strlen(lastImageOverBuff));

                // 写入image文件
                int lenTemp = write(saveImageFd, decodeBuf, decodeLen);
                CrLogI("write image file len = %d, state = ", lenTemp, strerror(errno));
            }
        }
        else if (startRecvImageFlag)
        {
            char *validData = readBuff + strlen("; ");
            if (!validData) break;
            // 去除文本换行符
            char *line1 = strstr(validData, "\r\n");
            char *line2 = strstr(validData, "\n");
            char *line3 = strstr(validData, "\r");
            if (line1) line1[0] = '\0';
            else if (line2) line2[0] = '\0';
            else if (line3) line3[0] = '\0';
                        
            strcat(lastImageOverBuff, validData);
            lastImageOverBufLen += strlen(validData);

            if (lastImageOverBufLen > SERIAL_PORT_MAX_DATA_FRAME_LEN)
            {
                int overLen = lastImageOverBufLen % 4;
                int convertLen = lastImageOverBufLen - overLen;
                char convertBuf[convertLen+1];
                memset(convertBuf, 0, convertLen+1);
                memcpy(convertBuf, lastImageOverBuff, convertLen);

                // 保存剩余数据
                char tempBuf[4] = {0};
                memcpy(tempBuf, &lastImageOverBuff[convertLen], overLen);
                memset(lastImageOverBuff, 0, sizeof(lastImageOverBuff)/sizeof(lastImageOverBuff[0]));
                memcpy(lastImageOverBuff, tempBuf, overLen);
                lastImageOverBufLen = overLen;

                // base64解码
                unsigned char decodeBuf[SERIAL_PORT_MAX_DATA_FRAME_LEN * 2] = {0};
                int decodeLen = Base64_decode(decodeBuf, sizeof(decodeBuf), convertBuf, strlen(convertBuf));

                // 写入image文件
                int lenTemp = write(saveImageFd, decodeBuf, decodeLen);
                CrLogI("write image file len = %d, state = ", lenTemp, strerror(errno));
            }
        }
        memset(readBuff, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
    }
    
    // 获取gcode起始、结束位置
    para->gcode_start_byte = GetGcodeStartByte(gcodeFileFd);
    para->gcode_end_byte = GetGcodeEndByte(gcodeFileFd);

    // 关闭文件
    fclose(gcodeFileFd);
    close(saveImageFd);

    // 更新缓存文件
    if (successFlag) {
        CrLogI("save local gcode thumbnail finish\n");
        return 1;
    }
    else {
        CrLogW("There is no thumbnail for this gcode file\n");
        char cmd[512] = {0};
        snprintf(cmd, sizeof(cmd), "cp '%s' '%s' && sync", GetDefaultFileIconPtah(), para->thumbnails);

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
        return 0;
    }
}

/**
 * @description: 从gcode文件获取注水图
 * @return {*}
 * @param {char} *fileName
 * @param {CurrentFile_t} *para
 * @param {GcodePhotoType_t} type
 */
int GetLocalGcodePhotoToFile(char *fileName, CurrentFile_t *para, GcodePhotoType_t type)
{
    // 判断路径是否为空
    if (fileName == NULL || para->preview == NULL) {
        CrLogW("path is empty !!\n");
        return 0;
    }

    // 获取gcode文件注水图
    CrLogI("start get local gcode Normal");
    int res = 0;

    // 获取并创建文件夹路径
    char *temp = strrchr(para->preview, '/');
    if (temp) {
        char folderPath[256] = {0};
        memcpy(folderPath, para->preview, temp - para->preview);
        if (access(folderPath, F_OK) != 0)
        {
            char cmd[300] = {0};
            snprintf(cmd, sizeof(cmd), "mkdir -p '%s'", folderPath);

            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
                CrLogW("system fail! res = %s\n", sysRes);
        }
    }

    // 在临时目录创建保存注水图文件
    int savePreviewFd = -1;
    struct GcodeParser* Parser = GcodeParserGetByName(fileName);
    if (Parser == NULL) {
        CrLogW("Gcode Parser Get By Name fail\n");
        return res;
    }
    
    // 打开gcode文件
    CrLogI("current gcode file = %s", fileName);
    FILE *gcodeFileFd = fopen(fileName, "r");
    if (gcodeFileFd == NULL) {
        CrLogW("gcode file open failed = %s\n", fileName);
        return res;
    }
    else {
        CrLogI("start read gcode file photo");
        int lastImageOverBufLen = 0;
        char lastImageOverBuff[SERIAL_PORT_MAX_DATA_FRAME_LEN * 2] = {0};
        uint32_t photoParaBuf[10] = {0};
        bool startRecvImageFlag = false;
        bool successFlag = false;
        char readBuff[SERIAL_PORT_MAX_DATA_FRAME_LEN] = {0};
        // 循环读取gcode文件数据
        while (fgets(readBuff, SERIAL_PORT_MAX_DATA_FRAME_LEN, gcodeFileFd) != NULL)
        {
            if (strstr(readBuff, "G0 X") || strstr(readBuff, "G1 X")) 
                break;
            else if (Parser->matchphotostart(readBuff))
            {
                startRecvImageFlag = true;
                // 获取注水图参数
                int photoParaCount = 0;
                char *strtokContext = NULL;
                char *token = strtok_r(readBuff, " ", &strtokContext);
                while( token != NULL )
                {
                    if (++photoParaCount >= 6)
                    {
                        float value = atof(token);
                        if (value <= 0) photoParaBuf[photoParaCount-6] = 0;
                        else photoParaBuf[photoParaCount-6] = value * 100 + 0.5;
                        CrLogI("photoParaBuf[%d] = %d", photoParaCount-6, photoParaBuf[photoParaCount-6]);
                    }
                    token = strtok_r(NULL, " ", &strtokContext);
                }
                
                // 打开预览图文件
                savePreviewFd = open(para->preview, O_RDWR | O_CREAT | O_TRUNC , S_IRWXG | S_IRWXO | S_IRWXU);
                if(savePreviewFd < 0) CrLogE("open %s failed.Fd = %d.", para->preview, savePreviewFd);
            }
            else if (savePreviewFd > 0 && Parser->matchphotoend(readBuff))
            {
                if (successFlag == false && startRecvImageFlag)
                {
                    successFlag = true;
                    startRecvImageFlag = false;
                    // base64解码
                    unsigned char decodeBuf[SERIAL_PORT_MAX_DATA_FRAME_LEN * 2] = {0};
                    int decodeLen = Base64_decode(decodeBuf, sizeof(decodeBuf), lastImageOverBuff, strlen(lastImageOverBuff));

                    // 写入image文件
                    int lenTemp = write(savePreviewFd, decodeBuf, decodeLen);
                    CrLogI("write image file len = %d, state = ", lenTemp, strerror(errno));
                    break;
                }
            }
            else if (savePreviewFd > 0 && startRecvImageFlag)
            {
                char *validData = readBuff + strlen("; ");
                char *line1 = strstr(validData, "\r\n");
                char *line2 = strstr(validData, "\n");
                char *line3 = strstr(validData, "\r");
                if (line1) line1[0] = '\0';
                else if (line2) line2[0] = '\0';
                else if (line3) line3[0] = '\0';
                        
                strcat(lastImageOverBuff, validData);
                lastImageOverBufLen += strlen(validData);

                if (lastImageOverBufLen > SERIAL_PORT_MAX_DATA_FRAME_LEN)
                {
                    int overLen = lastImageOverBufLen % 4;
                    int convertLen = lastImageOverBufLen - overLen;
                    char convertBuf[convertLen+1];
                    memset(convertBuf, 0, convertLen+1);
                    memcpy(convertBuf, lastImageOverBuff, convertLen);

                    // 保存剩余数据
                    char tempBuf[4] = {0};
                    memcpy(tempBuf, &lastImageOverBuff[convertLen], overLen);
                    memset(lastImageOverBuff, 0, sizeof(lastImageOverBuff)/sizeof(lastImageOverBuff[0]));
                    memcpy(lastImageOverBuff, tempBuf, overLen);
                    lastImageOverBufLen = overLen;

                    // base64解码
                    unsigned char decodeBuf[SERIAL_PORT_MAX_DATA_FRAME_LEN * 2] = {0};
                    int decodeLen = Base64_decode(decodeBuf, sizeof(decodeBuf), convertBuf, strlen(convertBuf));

                    // 写入image文件
                    int lenTemp = write(savePreviewFd, decodeBuf, decodeLen);
                    CrLogI("write image file len = %d, state = ", lenTemp, strerror(errno));
                }
            }
            memset(readBuff, 0, SERIAL_PORT_MAX_DATA_FRAME_LEN);
        }

        // 更新缓存文件
        if (successFlag) {
            CrLogI("save local gcode Normal finish\n");
            para->startPixel = photoParaBuf[0];
            para->endPixel = photoParaBuf[1];
            para->modelHeight = photoParaBuf[2];
            para->layerHeight = photoParaBuf[3];
            res = 1;
        }
        else {
            CrLogW("There is no Normal for this gcode file\n");
            char cmd[512] = {0};
            switch (type)
            {
                case GCODE_PHOTO_TYPE_PREVIEW: {
                    snprintf(cmd, sizeof(cmd), "cp '%s' '%s' && sync", GetDefaultFilePreviewPtah(), para->preview);
                    break;
                }
                case GCODE_PHOTO_TYPE_PRINT: {
                    snprintf(cmd, sizeof(cmd), "cp '%s' '%s' && sync", GetDefaultFilePrintPhotoPtah(), para->preview);
                    break;
                }
            }

            // 调用系统命令
            char sysRes[1024] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
                CrLogW("system fail! res = %s\n", sysRes);
            res = 1;
        }
    }

    // 关闭文件
    fclose(gcodeFileFd);
    close(savePreviewFd);
    return res;
}
