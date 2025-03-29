/*
 * @Description : 创想云下载服务
 * @Author      : Yufeng Zhang
 * @Date: 2022-05-06 22:16:45
 * @LastEditTime: 2023-08-04 08:58:31
 */
#include <iostream>
#include <algorithm>
#include <thread>
#include <curl/curl.h>

#include "Base/AppMsgBase.h"
#include "Base/AliyunCrc64/Crc64.h"
#include "CxyDownload.h"

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
CxyDownload::CxyDownload()
{
    m_lastProgress = 0;
    m_downloadFileName.clear();
    m_downloadFileCrc64.clear();
    m_setOptions.url.clear();
    m_setOptions.filePath.clear();
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
CxyDownload::~CxyDownload()
{
    m_downloadFileName.clear();
    m_downloadFileCrc64.clear();
    // 析构时保证子线程join进来
    if (m_dowmloadThread.joinable()) {
        m_dowmloadThread.join();
    }
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
unsigned char CxyDownload::FromHex(unsigned char x)
{   
    unsigned char y;  
    if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;  
    else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;  
    else if (x >= '0' && x <= '9') y = x - '0';  
    else return 0;  
    return y;  
}  

/**
 * @description: 
 * @return {*}
 * @param undefined
 * @param undefined
 */
std::string CxyDownload::UrlDecode(const std::string str)
{  
    std::string dst = "";
    size_t length = str.length();  
    for (size_t i = 0; i < length; i++) {  
        if (str[i] == '+') {
            dst += ' ';  
        } else if (i + 2 < length && str[i] == '%') {
            unsigned char high = FromHex((unsigned char)str[++i]);  
            unsigned char low = FromHex((unsigned char)str[++i]);  
            dst += high*16 + low;  
        } else {
            dst += str[i];  
        }
    }
    return dst;  
}

/**
 * @description: 
 * @return {*}
 */
int CxyDownload::DownloadFileProgress(void *data, double t, double d, double ultotal, double ulnow)
{
    CxyDownload* client = static_cast<CxyDownload*>(data);

    int progress = d / t * 100 + 0.5;
    if (progress >= 0 && client->m_lastProgress != progress)
    {
        client->m_setOptions.progressCb(client->m_lastProgress);
        client->m_lastProgress = progress;
    }
    
    // 判断是否取消下载
    if (client->m_continueDownload) return 0;
    else return 1;  
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 * @param undefined
 * @param undefined
 * @param undefined
 */
size_t CxyDownload::DownloadHttpHeade(char *buffer, size_t size, size_t nitems, void *userdata)
{
    CxyDownload* client = static_cast<CxyDownload*>(userdata);
    if(!buffer)
    {
        return nitems * size;
    }
    CrLogD("DownloadHttpHeade buffer = %s size = %d", buffer,size);
    if (strstr(buffer, "Content-Disposition:"))
    {
        const char *temp = NULL, *endTemp = NULL;
        temp = strstr(buffer, "attachment;filename=\""); 
        if (temp)
        {
            temp+=strlen("attachment;filename=\"");
            endTemp = strstr(temp, "\"");
            int fileNameLen = endTemp - temp;

            char fileNameBuff[fileNameLen + 1];
            memset(fileNameBuff, 0, fileNameLen + 1);
            memcpy(fileNameBuff, temp, fileNameLen);

            std::string fileName = std::string(fileNameBuff);
            fileName = client->UrlDecode(fileName);
            CrLogI("download file name = %s", fileName.c_str());
            client->m_downloadFileName = fileName;
        }
        else CrLogW("http response file name fail\n");
    }
    else if (strstr(buffer, "x-oss-hash-crc64ecma: "))
    {
        char *temp = strstr(buffer, "x-oss-hash-crc64ecma: ");
        if (temp) {
            temp+=strlen("x-oss-hash-crc64ecma: ");
            int crcLen = 0;
            const char *line1 = strstr(temp, "\r\n");
            const char *line2 = strstr(temp, "\n");
            const char *line3 = strstr(temp, "\r");
            if (line1) crcLen = line1 - temp;
            else if (line2) crcLen = line2 - temp;
            else if (line3) crcLen = line3 - temp;

            char crcBuff[crcLen + 1];
            bzero(crcBuff, sizeof(crcBuff));
            memcpy(crcBuff, temp, crcLen);
            CrLogI("crc64 str = %s", crcBuff);

            client->m_downloadFileCrc64 = std::string(crcBuff);
        }
        else CrLogW("http response crc64 fail\n");
    }
    return nitems * size;
}

/**
 * @description: 下载文件数据接收函数
 * @param  {*}
 * @return {*}
 * @param {void} *buffer
 * @param {size_t} size
 * @param {size_t} nmemb
 * @param {void} *user_p
 */
int CxyDownload::DownloadWriteFile(void *buffer, size_t size, size_t nmemb, void *user_p)
{
    CxyDownload* client = static_cast<CxyDownload*>(user_p);

	size_t return_size = fwrite(buffer, size, nmemb, client->m_fileHandle);
	return return_size;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {void} *args
 */
void CxyDownload::DownloadFileThread(void *args)
{
    CrLogI("download url = %s", m_setOptions.url.c_str());
    CrLogI("download path = %s", m_setOptions.filePath.c_str());

    // 临时文件
    std::string tempFileName = m_setOptions.filePath + "/download_temp.gz";
    m_fileHandle = fopen(tempFileName.c_str(), "wb");
    if (!m_fileHandle) {
        CrLogW("open file fail, name = %s\n", tempFileName.c_str());
        std::string tempString;
        m_setOptions.conStateCb(FILE_DOWNLOAD_FAIL, tempString);

        return;
    }
    
	// curl初始化
	CURLcode res;
	CURL *curl = curl_easy_init();
	
	if (curl)
	{
		//设置curl的请求头
		struct curl_slist* header_list = NULL;
        header_list = curl_slist_append(header_list, "Content-Type: application/json; charset=UTF-8");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);

		//不接收响应头数据0代表不接收 1代表接收
		curl_easy_setopt(curl, CURLOPT_HEADER, 0);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, &CxyDownload::DownloadHttpHeade);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, this);

		//设置请求的URL地址 
		curl_easy_setopt(curl, CURLOPT_URL, m_setOptions.url.c_str());

		//设置ssl验证
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);

		//CURLOPT_VERBOSE的值为1时，会显示详细的调试信息
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);

		//设置数据接收函数
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CxyDownload::DownloadWriteFile);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);

        //设置打印进度回调
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, &CxyDownload::DownloadFileProgress);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, this);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);

        //设置信号
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

		//设置超时时间
		curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 60); // set transport and time out time  
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3600);

        CrLogI("start download file ......\n");
        std::string tempString;
        m_setOptions.conStateCb(FILE_DOWNLOAD_ING, tempString);
		// 开启请求  
        CrLogI("curl_easy_perform ......\n");
		res = curl_easy_perform(curl);
        CrLogI("curl_easy_perform end\n");
        curl_slist_free_all(header_list);
	}

	//释放文件资源
	curl_easy_cleanup(curl);
	fclose(m_fileHandle);

    if (res == CURLE_OK)
    {
        CrLogI("download file success\n");
        // 压缩包重命名
        std::string newName = m_setOptions.filePath + "/" + m_downloadFileName;
        std::string systemCmd = "mv " + tempFileName + " " + "'"+ newName + "'" + " && sync";
        CrLogD("systemCmd = %s", systemCmd.c_str());

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem((char*)systemCmd.c_str(), sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);

        // 检查下载文件的完整性
        std::string checkCrc64 = std::to_string(AlibabaCloud::OSS::CRC64::GetFileCRC64(newName));
        CrLogI("m_downloadFileCrc64 = %s, checkCrc64 = %s", m_downloadFileCrc64.c_str(), checkCrc64.c_str());

        if (strcmp(m_downloadFileCrc64.c_str(), checkCrc64.c_str()) == 0) {
            CrLogI("crc64 check success\n");
            m_setOptions.conStateCb(FILE_DOWNLOAD_OK, newName);
        }
        else {
            CrLogW("crc64 check fail\n");
            m_setOptions.conStateCb(FILE_DOWNLOAD_FAIL, newName);
        }
    }
    else
    {
        CrLogW("download file fail!!!, code = %d", res);
        std::string tempString;
        if (m_continueDownload) m_setOptions.conStateCb(FILE_DOWNLOAD_FAIL, tempString);
        else m_setOptions.conStateCb(FILE_DOWNLOAD_CANCEL, tempString);
    }

    // 删除临时文件
    if (access(tempFileName.c_str(), F_OK) == 0) remove(tempFileName.c_str());
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
void CxyDownload::Init(CxyDownloadOptions_t options)
{
    m_fileHandle = NULL;
    m_lastProgress = 0;
    m_downloadFileName.clear();
    m_downloadFileCrc64.clear();
    m_setOptions.url.clear();
    m_setOptions.filePath.clear();
    m_setOptions = options;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {CxyDownloadOptions_t} options
 */
void CxyDownload::Start(void)
{
    m_continueDownload = 1;
    m_dowmloadThread = std::thread(&CxyDownload::DownloadFileThread, this, (void*)NULL);
    m_dowmloadThread.detach();
}

/**
 * @description: 
 * @return {*}
 */
void CxyDownload::Stop(void) { m_continueDownload = 0; }
