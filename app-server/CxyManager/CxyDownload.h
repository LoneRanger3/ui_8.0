/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-05-06 22:16:45
 * @LastEditTime: 2023-03-20 19:56:12
 */

#ifndef __CXY_DOWNLOAD_H__
#define __CXY_DOWNLOAD_H__

#include <functional>
#include <thread>

typedef struct {
    std::string url;
    std::string filePath;
    std::function<int(int, std::string)> conStateCb;
    std::function<int(int)> progressCb;
}CxyDownloadOptions_t;

class CxyDownload
{
    public:
        CxyDownload();
        ~CxyDownload();

        void Init(CxyDownloadOptions_t options);
        void Start(void);
        void Stop(void);

    private:
        static int DownloadWriteFile(void *buffer, size_t size, size_t nmemb, void *user_p);
        static int DownloadFileProgress(void *data, double t, double d, double ultotal, double ulnow);
        static size_t DownloadHttpHeade(char *buffer, size_t size, size_t nitems, void *userdata);

        unsigned char FromHex(unsigned char x);
        std::string UrlDecode(const std::string str);

        void DownloadFileThread(void *args);

    private:
        CxyDownloadOptions_t        m_setOptions;
        std::thread                 m_dowmloadThread;
        FILE                        *m_fileHandle;
        int                         m_continueDownload;
        int                         m_lastProgress;
        std::string                 m_downloadFileName;
        std::string                 m_downloadFileCrc64;
};

#endif
