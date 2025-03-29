/*
 * @Description : 自定义系统命令
 * @Author      : Yufeng Zhang
 * @Date: 2022-10-31 11:46:58
 * @LastEditTime: 2023-10-30 11:03:01
 */
#define OPENSSL_API_COMPAT      0x10100000L  // 指定OpenSSL使用版本
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <regex.h>
#include <openssl/aes.h>
#include <fcntl.h>
#include <semaphore.h>
#include <jpeglib.h>
#include <png.h>

#include "../Global.h"
#include "SystemCmd.h"

#define USER_KEY_LENGTH     16
#define IVEC_LENGTH         16
#define AES_BLOCK_SIZE      16
#define BITS_LENGTH         (USER_KEY_LENGTH * 8)

/**
 * @description: 
 * @return {*}
 * @param {unsigned char} *in
 * @param {unsigned char} *out
 * @param {size_t} length
 */
static bool AES_CBC256_Encrypt(const unsigned char *in, unsigned char *out, size_t length)
{
    // 检查数据长度是否符合要求
    if ((length % AES_BLOCK_SIZE) != 0) {
        printf("length is not a multiple of 16 bytes\n");
        return false;
    }

    // 获取AES128加密密码
    unsigned char userKey [USER_KEY_LENGTH];
    unsigned char ivec [IVEC_LENGTH];
    memcpy(userKey, AES128_PASSWORD, USER_KEY_LENGTH);
    memcpy(ivec, AES128_IV, IVEC_LENGTH);

    // 初始化加密key
    AES_KEY aes_key;
    AES_set_encrypt_key(userKey, BITS_LENGTH, &aes_key);
 
    // AES加密
    AES_cbc_encrypt(in, out, length, &aes_key, ivec, AES_ENCRYPT);
    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {unsigned char} *in
 * @param {unsigned char} *out
 * @param {size_t} length
 */
static bool AES_CBC256_Decrypt(const unsigned char *in, unsigned char *out, size_t length)
{
    // 检查数据长度是否符合要求
    if ((length % AES_BLOCK_SIZE) != 0) {
        printf("length is not a multiple of 16 bytes\n");
        return false;
    }

    // 获取AES128加密密码
    unsigned char userKey [USER_KEY_LENGTH];
    unsigned char ivec [IVEC_LENGTH];
    memcpy(userKey, AES128_PASSWORD, USER_KEY_LENGTH);
    memcpy(ivec, AES128_IV, IVEC_LENGTH);

    // 初始化解密key
    AES_KEY aes_key;
    AES_set_decrypt_key(userKey, BITS_LENGTH, &aes_key);

    // AES解密
    AES_cbc_encrypt(in, out, length, &aes_key, ivec, AES_DECRYPT);
    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {string} str
 */
char *AesEncryptToBase64(char *str, int len)
{
    // 判断数据是否有效
    if (len <= 0) return NULL;

    // 计算加密数据长度
    size_t length = 0;
    if ((len % AES_BLOCK_SIZE) == 0) length = len;
    else length = len + (AES_BLOCK_SIZE - len % AES_BLOCK_SIZE);

    // 定义加密接收缓存
    unsigned char *aes128 = (unsigned char *) malloc (length);
    bzero(aes128, length);

    // AES加密
    bool encrypt_ret = AES_CBC256_Encrypt((unsigned char*)str, aes128, length);
    if (false == encrypt_ret) printf("encrypt error!\n");

    // 计算编码数据长度
    int base64StrLen = length * 8;

    // 定义编码接收缓存
    char *base64Str = (char *) malloc (base64StrLen);
    bzero(base64Str, base64StrLen);

    // base64编码字符串
    Base64_encode(base64Str, base64StrLen, aes128, length);

    // 获取返回值，释放资源
    free(aes128);
    return base64Str;
}

/**
 * @description: 
 * @return {*}
 * @param {string} str
 */
char *AesDecryptFromBase64(char *str, int len)
{
    // 判断数据是否有效
    if (len <= 0) return NULL;

    // 计算解码数据长度
    int aes128Len = len;

    // 定义解码接收缓存
    unsigned char *aes128 = (unsigned char *) malloc (aes128Len);
    bzero(aes128, aes128Len);

    // base64解码aes128密文
    int decodeLen = Base64_decode(aes128, aes128Len, str, len);
    
    // 计算解密数据长度
    int length = decodeLen;
    
    // 定义解密数据缓存
    unsigned char *data = (unsigned char *) malloc (length);
    bzero(data, length);

    // AES解密
    bool decrypt_ret = AES_CBC256_Decrypt(aes128, data, length);
    if (false == decrypt_ret) printf("decrypt error!\n");

    // 获取返回值，释放资源
    free(aes128);
    return (char*)data;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *path
 * @param {char} *str
 * @param {int} len
 */
int AesEncryptToFile(char *path, char *str, int len)
{
    char *getStr = AesEncryptToBase64(str, len);
    if (getStr) {
        SaveConfigToFile(path, getStr, strlen(getStr));
        free(getStr);
        return 0;
    }
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *path
 */
char *AesDecryptFromFile(char *path)
{
    // 获取文件大小
	size_t filesize = GetUserFileSize(path) + 10;
    char *readConfig = (char*) malloc (filesize);
    bzero(readConfig, filesize);

    // 读取文件
    GetConfigFromFile(path, readConfig, filesize);
    // 解密
    char *getStr = AesDecryptFromBase64(readConfig, strlen(readConfig));
    free(readConfig);
    return getStr;
}

/**
 * @description: 正则表达式
 * @param  {*}
 * @return {*}
 */
int UserGetRegexStr(const char *__restrict __String,
                    const char *__restrict __pattern,
                    regmatch_t __pmatch[__restrict_arr],
                    size_t __nmatch)
{
    int curLocal = 0;
    int regexCount = 0;
    regex_t comment;
    regmatch_t regmatch[100];

    int res = regcomp(&comment, __pattern, REG_EXTENDED|REG_NEWLINE);
    if (res != 0)
    {
        size_t eLen = regerror (res, &comment, NULL, 0);
        char eBuf[eLen + 1];
        memset(eBuf, 0, eLen + 1);
        regerror(res, &comment, eBuf, eLen);
        regfree(&comment);
        return -1;
    }

    int nmatchSize = sizeof(regmatch)/sizeof(regmatch_t);
    while(1)
    {
        if(regexec(&comment, __String, nmatchSize, regmatch, 0) != 0)
            goto EXIT;

        for(int i = 0; i< nmatchSize && regmatch[i].rm_so != -1; i++)
        {
            __pmatch[regexCount].rm_so = regmatch[i].rm_so + curLocal;
            __pmatch[regexCount].rm_eo = regmatch[i].rm_eo + curLocal;
            if (++regexCount >= __nmatch)
                goto EXIT;
        }
 
        if(regmatch[0].rm_so != -1)
        {
            curLocal += regmatch[0].rm_eo;
            __String += regmatch[0].rm_eo;
        }
    }

EXIT:
    regfree(&comment);
    return regexCount;
}

/**
 * @description: 字符串倒叙
 * @return {*}
 * @param {char*} str
 */
void ReverseString(char* str)
{
    int k = strlen(str);
    for (int i = 0; i < k/2; i++) {
        char c = str[i];
        str[i] = str[k-i-1];
        str[k-i-1] = c;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {char} *cmd
 * @param {char} *res
 */
bool PopenSystem(char *cmd, char *resStr, int resLen)
{
	FILE *fp = popen(cmd, "r");
    if (fp) {
        fread(resStr, 1, resLen, fp);
        pclose(fp);

        char *endStr = strrchr(resStr, '\n');
        if (endStr) endStr[0] = '\0';
        return true;
    }
    
	return false;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *filePath
 * @param {char} *md5
 */
bool getFileMD5(char *filePath, char *md5)
{
    char getMd5Cmd[300] = {0};
    snprintf(getMd5Cmd, 300, "md5sum '%s'", filePath);

    char sysRes[1024] = {0};
    if (PopenSystem(getMd5Cmd, sysRes, sizeof(sysRes)))
    {
        char *endStr = strchr(sysRes, ' ');
        if (endStr) endStr[0] = '\0';
        strcat(md5, sysRes);
        return true;
    }
    return false;
}

/**
 * @description: 
 * @return {*}
 * @param {EthernetInfo_t} *info
 */
bool GetEthernetInfo(EthernetInfo_t *info)
{
    bool res = false;
    char buff[10240] = {0};

    // 获取以太网ip地址
    if (!PopenSystem("ip -j address", buff, sizeof(buff))) {
        CrLogW("get system ip addr fail !!\n");
        return res;
    }

    // 解析返回结果
    json_object *resultObj = json_tokener_parse(buff);
    if (!resultObj) {
        CrLogW("get ip info obj fail, buff = %s\n", buff);
        return res;
    }

    // 解析json结果
    for (int i = 0; i < json_object_array_length(resultObj); i++)
    {
        json_object *networkObj = json_object_array_get_idx(resultObj, i);
        // 筛选以太网信息
        json_object *ifnameObj = json_object_object_get(networkObj, "ifname");
        if (!strstr(json_object_get_string(ifnameObj), "eth0")) continue;
        
        // 判断以太网是否连接
        json_object *operstateObj = json_object_object_get(networkObj, "operstate");
        if (!strstr(json_object_get_string(operstateObj), "UP") &&
            !strstr(json_object_get_string(operstateObj), "UNKNOWN"))
            break;
        
        // 以太网连接，获取ip地址
        json_object *addr_infoObj = json_object_object_get(networkObj, "addr_info");
        if (addr_infoObj &&
            json_object_is_type(addr_infoObj, json_type_array) &&
            json_object_array_length(addr_infoObj) > 0)
        {
            // 提取以太网ip
            json_object *ipInfoObj = json_object_array_get_idx(addr_infoObj, 0);
            json_object *ifnameObj = json_object_object_get(ipInfoObj, "local");
            strcat(info->ip, json_object_get_string(ifnameObj));
            CrLogI("get ethernet local ip finish");
            res = true;
        }
    }
    json_object_put(resultObj);
    
    // 判断是否获取有线网络IP
    if (!res) return res;

    // 获取网关
    char ethernetRecv[1024] = {0};
    if (!PopenSystem("ip route | grep \"default via.*eth0\" | awk '{print $3}'", ethernetRecv, sizeof(ethernetRecv)))
        CrLogW("get info fail !!\n");
    strcat(info->gateway, ethernetRecv);

    // 获取子网掩码
    bzero(ethernetRecv, sizeof(ethernetRecv));
    if (!PopenSystem("ifconfig eth0 | grep Mask | cut -d ':' -f 4", ethernetRecv, sizeof(ethernetRecv)))
        CrLogW("get info fail !!\n");
    strcat(info->subnetMask, ethernetRecv);

    // 获取DNS服务器
    bzero(ethernetRecv, sizeof(ethernetRecv));
    if (!PopenSystem("cat /etc/resolv.conf | grep eth0 | awk '{print $2}'", ethernetRecv, sizeof(ethernetRecv)))
        CrLogW("get info fail !!\n");
    strcat(info->dnsServer, ethernetRecv);

    // 成功获取有线网络信息
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {json_object} *source
 * @param {char} *key
 * @param {json_type} type
 */
json_object *GetJsonObject(json_object *source, char *key, json_type type)
{
    json_object *getObj = json_object_object_get(source, key);
    if (getObj && json_object_is_type(getObj, type)) return getObj;
    else return NULL;      
}

/**
 * @description: 
 * @return {*}
 * @param {char} *semPath
 * @param {char} *shmFile
 * @param {int} size
 * @param {bool} isCreate
 */
sem_shm_t CreateSemShm(const char *semPath, const char *shmFile, int size, bool isCreate)
{
    // 初始化数据
    sem_shm_t getShm = {
        .result = GET_SHM_IDLE,
        .mutex = NULL,
        .isLock = false,
        .fd = -1,
        .ptr = NULL,
        .ptrSize = size,
    };

    // 创建信号量
    if (isCreate) getShm.mutex = sem_open(semPath, O_CREAT, 0777, 1);
    else getShm.mutex = sem_open(semPath, 0);
    if (getShm.mutex == SEM_FAILED) {
        CrLogE("sem_open failed\n");
        getShm.result = GET_SHM_OPEN_SEM_FAIL;
        goto ERROR;
    }

    // 创建共享内存
    if (isCreate) getShm.fd = shm_open(shmFile, O_RDWR | O_CREAT, 0777);
    else getShm.fd = shm_open(shmFile, O_RDWR, 0);
    if (getShm.fd < 0) {
        CrLogE("fail to shm_open\n");
        getShm.result = GET_SHM_OPEN_SHM_FAIL;
        goto ERROR;
    }

    // 调整确定文件共享内存的空间
    if (isCreate) {
        if (ftruncate(getShm.fd, getShm.ptrSize) == -1) {
            CrLogE("ftruncate shm_fd failed\n");
            getShm.result = GET_SHM_FTRUNCATE_SHM_FAIL;
            goto ERROR;
        }
    }
    else {
        struct stat shmFdInfo;
        fstat(getShm.fd, &shmFdInfo);
        getShm.ptrSize = shmFdInfo.st_size;
    }

    // 映射目标文件的存储区
    getShm.ptr = mmap(NULL, getShm.ptrSize, PROT_READ | PROT_WRITE, MAP_SHARED, getShm.fd, SEEK_SET);
    if (getShm.ptr == NULL) {
        CrLogE("fail to mmap\n");
        getShm.result = GET_SHM_MMAP_SHM_FAIL;
        goto ERROR;
    }

    // 创建共享内存成功
    getShm.result = GET_SHM_OK;
    return getShm;

ERROR:
    if (getShm.mutex != SEM_FAILED) sem_unlink(semPath);
    if (getShm.ptr != NULL) munmap(getShm.ptr, getShm.ptrSize);
    if (getShm.fd > 0) shm_unlink(shmFile);
    return getShm;
}

/**
 * @description: 
 * @return {*}
 * @param {sem_shm_t} *shmInfo
 */
int CloseSemShm(sem_shm_t *shmInfo)
{
    // 判断共享内存是否正常
    if (shmInfo->result != GET_SHM_OK) {
        CrLogW("shm no read\n");
        return -1;
    }

    // 关闭信号量、共享内存
    if (shmInfo->isLock) sem_post(shmInfo->mutex);
    if (shmInfo->mutex != SEM_FAILED) sem_close(shmInfo->mutex);
    if (shmInfo->fd > 0) close(shmInfo->fd);
    if (shmInfo->ptr != NULL) munmap(shmInfo->ptr, shmInfo->ptrSize);
    
    // 重置状态
    shmInfo->result = GET_SHM_IDLE;
    shmInfo->mutex = NULL;
    shmInfo->isLock = false;
    shmInfo->fd = -1;
    shmInfo->ptr = NULL;
    shmInfo->ptrSize = 0;
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {sem_shm_t} *shmInfo
 * @param {void} *data
 * @param {int} len
 */
int WriteDataToShm(sem_shm_t *shmInfo, void *data, int len)
{
    // 判断共享内存是否正常
    if (shmInfo->result != GET_SHM_OK) {
        CrLogW("shm no read\n");
        return -1;
    }

    // 获取信号量
    sem_wait(shmInfo->mutex);
    shmInfo->isLock = true;

    bzero(shmInfo->ptr, shmInfo->ptrSize);
    memcpy(shmInfo->ptr, data, (len < shmInfo->ptrSize ? len : shmInfo->ptrSize));
    msync(shmInfo->ptr, shmInfo->ptrSize, MS_SYNC);
    
    // 释放信号量
    sem_post(shmInfo->mutex);
    shmInfo->isLock = false;
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {sem_shm_t} *shmInfo
 * @param {void} *data
 * @param {int} len
 */
int ReadDataFromShm(sem_shm_t *shmInfo, void *data, int len)
{
    // 判断共享内存是否正常
    if (shmInfo->result != GET_SHM_OK) {
        CrLogW("shm no read\n");
        return -1;
    }

    // 获取信号量
    sem_wait(shmInfo->mutex);
    shmInfo->isLock = true;

    memcpy(data, shmInfo->ptr, (len < shmInfo->ptrSize ? len : shmInfo->ptrSize));

    // 释放信号量
    sem_post(shmInfo->mutex);
    shmInfo->isLock = false;
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {sem_shm_t} *shmInfo
 */
int ShmExceptionHandleSemPost(sem_shm_t *shmInfo)
{
    // 判断共享内存是否正常
    if (shmInfo->result != GET_SHM_OK) {
        CrLogW("shm no read\n");
        return -1;
    }
    
    if (shmInfo->isLock) {
        sem_post(shmInfo->mutex);
        shmInfo->isLock = false;
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *path
 */
int GetSaveSystemInfoToFile(char *path)
{
    // 获取系统信息
    if (!path) return -1;
    const char *productionSnStr = "", *dnStr = "", *macStr = "", *modelStr = "", *sysVersionStr = "", *hwVersionStr = "";

    // 获取生产SN号
    json_object *productionInfoObj = json_object_from_file(GetMachineProductionInfo());
    if (productionInfoObj) {
        json_object *productionSnObj = GetJsonObject(productionInfoObj, "productionSn", json_type_string);
        if (productionSnObj) productionSnStr = json_object_get_string(productionSnObj);
    }
    else CrLogW("no production info\n");

    // 获取DN、MAC、机型
    json_object *configObj = json_object_from_file(GetUserSystemConfigFilePath());
    if (configObj) {
        json_object *deviceInfoObj = GetJsonObject(configObj, "device_info", json_type_object);
        if (deviceInfoObj) {
            // DN
            json_object *dnObj = GetJsonObject(deviceInfoObj, "device_sn", json_type_string);
            if (dnObj) dnStr = json_object_get_string(dnObj);
            // MAC
            json_object *macObj = GetJsonObject(deviceInfoObj, "device_mac", json_type_string);
            if (macObj) macStr = json_object_get_string(macObj);
            // 机型
            json_object *modelObj = GetJsonObject(deviceInfoObj, "model_str", json_type_string);
            if (modelObj) modelStr = json_object_get_string(modelObj);
        }
    }
    else CrLogW("no system config\n");

    // 获取版本
    json_object *versionObj = json_object_from_file(GetUserSystemVersionFilePath());
    if (versionObj) {
        // 固件版本号
        json_object *sysVersionObj = GetJsonObject(versionObj, "sys_version", json_type_string);
        if (sysVersionObj) sysVersionStr = json_object_get_string(sysVersionObj);
        // 硬件版本
        json_object *hwVersionObj = GetJsonObject(versionObj, "hw_version", json_type_string);
        if (hwVersionObj) hwVersionStr = json_object_get_string(hwVersionObj);
    }
    else CrLogW("no version config\n");

    // 生成临时系统信息
    json_object *systemInfoObj = json_object_new_object();
    json_object_object_add(systemInfoObj, "整机SN", json_object_new_string(productionSnStr));
    json_object_object_add(systemInfoObj, "DN", json_object_new_string(dnStr));
    json_object_object_add(systemInfoObj, "MAC", json_object_new_string(macStr));
    json_object_object_add(systemInfoObj, "机型", json_object_new_string(modelStr));
    json_object_object_add(systemInfoObj, "固件版本", json_object_new_string(sysVersionStr));
    json_object_object_add(systemInfoObj, "硬件版本", json_object_new_string(hwVersionStr));

    // 保存信息
    int res = json_object_to_file_ext(path, systemInfoObj, JSON_C_TO_STRING_PRETTY);

    // 释放资源
    if (productionInfoObj) json_object_put(productionInfoObj);
    if (configObj) json_object_put(configObj);
    if (versionObj) json_object_put(versionObj);
    if (systemInfoObj) json_object_put(systemInfoObj);
    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *file
 * @param {img_pic_data} *data
 */
static int LoadJPG(char *file, img_pic_data *data, int zoom)
{
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jem;
    FILE *jpeg_fp;
    JSAMPARRAY buffer;
    int row_stride;
    int pos;
    int i;

    //打开jpeg格式图片
    if((jpeg_fp = fopen(file, "rb")) == NULL) {
        CrLogE("can't open %s\n", file);
        return -1;
    }

    //初始化并申请解码器
    cinfo.err = jpeg_std_error(&jem);
    jpeg_create_decompress(&cinfo);
    //指定图片文件信息
    jpeg_stdio_src(&cinfo, jpeg_fp);
    //读取头部信息
    jpeg_read_header(&cinfo, TRUE);
    cinfo.scale_num = 1;
    cinfo.scale_denom = zoom;
    //开始解码
    jpeg_start_decompress(&cinfo);

    row_stride = cinfo.output_width * cinfo.output_components;
    data->width = cinfo.output_width;
    data->height = cinfo.output_height;
    data->bit_depth = 8;
    data->flag = 1;
    data->col_type = PNG_COLOR_TYPE_RGB_ALPHA;
    pos = 0;

    //给一行数据分配内存
    buffer = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo, JPOOL_IMAGE, row_stride, 1);
    //一行一行读取
    while(cinfo.output_scanline < cinfo.output_height)
    {
        jpeg_read_scanlines(&cinfo, buffer, 1);
        for(i=0; i<cinfo.output_width; i++)
        {
            data->rgba[4*pos+0] = buffer[0][3*i+0];
            data->rgba[4*pos+1] = buffer[0][3*i+1];
            data->rgba[4*pos+2] = buffer[0][3*i+2];
            data->rgba[4*pos+3] = 255;
            pos++;
        }
    }

    //读取结束
    jpeg_finish_decompress(&cinfo);
    //释放编码器对象
    jpeg_destroy_decompress(&cinfo);
    //关闭jpeg格式图片
    fclose(jpeg_fp);

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *file
 * @param {img_pic_data} *data
 */
static int PutPNG(char *file, img_pic_data *data)
{
    FILE *pic_fp;
    png_structp png_ptr;
    png_infop info_ptr;
    png_bytep *row_pointers;
    int temp;
    int i, j;
    int pos = 0;

    //打开png空文件
    pic_fp = fopen(file, "wb");
    if(pic_fp == NULL) {
        CrLogE("can't open %s\n", file);
        return -1;
    }

    temp = data->width * 4;
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if(!png_ptr) {
        CrLogE("png_create_write_struct failed\n");
        return -1;
    }

    info_ptr = png_create_info_struct(png_ptr);
    if(!info_ptr) {
        CrLogE("png_create_info_struct failed\n");
        return -1;
    }

    if(setjmp(png_jmpbuf(png_ptr))) {
        CrLogE("write error on init io\n");
        return -1;
    }

    png_init_io(png_ptr, pic_fp);
    if(setjmp(png_jmpbuf(png_ptr))) {
        CrLogE("write error on write header\n");
        return -1;
    }

    png_set_IHDR(png_ptr, info_ptr, data->width, data->height, data->bit_depth, data->col_type, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
    png_write_info(png_ptr, info_ptr);

    if(setjmp(png_jmpbuf(png_ptr))) {
        CrLogE("write error on writing bytes\n");
        return -1;
    }

    if(data->flag == 1)
    {
        pos = 0;
        row_pointers = (png_bytep *)malloc(data->height * sizeof(png_bytep));
        for(i=0; i<data->height; i++)
        {
            row_pointers[i] = (png_bytep)malloc(temp * sizeof(unsigned char));
            for(j=0; j<temp; j+=4)
            {
                row_pointers[i][j+0] = data->rgba[pos*4 + 0];
                row_pointers[i][j+1] = data->rgba[pos*4 + 1];
                row_pointers[i][j+2] = data->rgba[pos*4 + 2];
                row_pointers[i][j+3] = data->rgba[pos*4 + 3];
                pos++;
            }
        }

        png_write_image(png_ptr, row_pointers);
        if(setjmp(png_jmpbuf(png_ptr))) {
            CrLogE("write error on write end\n");
            return -1;
        }

        png_write_end(png_ptr, NULL);
        for(i=0; i<data->height; i++) {
            free(row_pointers[i]);
        }

        free(row_pointers);
    }

    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(pic_fp);

    return 0;
}

/**
 * @description: jpeg转png
 * @return {*}
 * @param {char} *jpegName
 * @param {char} *pngName
 */
int JpegToPng(char *jpegName, char *pngName, int zoom)
{
    img_pic_data pic_data = {0};
    pic_data.rgba = (unsigned char *) malloc (16 * 3840 * 2160);
    if(!pic_data.rgba) {
        CrLogE(" malloc error!\n");
        return -1;
    }

    int ret = LoadJPG(jpegName, &pic_data, zoom);
    if(ret < 0) {
        CrLogE(" LoadJPG error!\n");
        free(pic_data.rgba);
        return -1;
    }

    ret = PutPNG(pngName, &pic_data);
    if(ret < 0) {
        CrLogE(" PutPNG error!\n");
        free(pic_data.rgba);
        return -1;
    }

    free(pic_data.rgba);
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
void RestartNowAppServer(void)
{
    // 删除IOT信息
    if (remove(GetUserIotTbInfoFilePtah()) != 0)
        CrLogW("remove iot tb info fail\n,");

    // 重启app-server服务
    CrLogE("active restart app server\n");
    char touchCmd[256] = {0};
    snprintf(touchCmd, sizeof(touchCmd), "touch %s", GetUserMonitorExecuteRunPtah());
    system(touchCmd);
    system("killall -9 app-server");
}

/**
 * @description: 
 * @return {*}
 */
void RestartNowDisplayServer(void)
{
    // 重启display-server服务
    CrLogE("active restart display server\n");
    char touchCmd[256] = {0};
    snprintf(touchCmd, sizeof(touchCmd), "touch %s", GetUserMonitorExecuteRunPtah());
    system(touchCmd);
    system("killall -9 display-server");
}

/**
 * @description: 
 * @return {*}
 */
void RestartNowMasterServer(void)
{
    // 重启master-server服务
    CrLogE("active restart master server\n");
    char touchCmd[256] = {0};
    snprintf(touchCmd, sizeof(touchCmd), "touch %s", GetUserMonitorExecuteRunPtah());
    system(touchCmd);
    system("killall -9 master-server");
}
