/*
 * @Description : 文件上传类
 * @Author      : Yufeng Zhang
 * @Date: 2022-09-23 10:21:52
 * @LastEditTime: 2023-10-16 13:51:18
 */

#ifndef __CXY_UPLOAD_H__
#define __CXY_UPLOAD_H__

#include <string>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <vector>
#include "vod_sdk/upload.h"
#include "oss_c_sdk/oss_api.h"
#include "oss_c_sdk/aos_http_io.h"
class CxyUpload;

#define TRY_UPLOAD_MAX_TIMER        3 // 重传次数

typedef enum {
    FILE_UPLOAD_OK,
    FILE_UPLOAD_ING,
    FILE_UPLOAD_FAIL,
    FILE_UPLOAD_COMPRESS,
    FILE_UPLOAD_STOPOK,
}FileUploadState_t;

typedef struct {
    std::string fileTitle;
    std::string filePath;
    std::string appToken;
    std::string printId;
    int deploy_setting;
    CxyUpload *upload;
    std::function<int(int,CxyUpload *,int)> conStateCb;
}CxyUploadOptions_t;

typedef struct {
    std::string regionId;
	std::string accessKeyId;
	std::string accessKeySecret;
	std::string stsToken;
	int iotId;
	time_t expired;
    std::string tags;
    std::string workflowId;
    std::string userData;
}TmplyAuthority_t;


class CxyUpload
{
    public:
        ~CxyUpload();
        static CxyUpload *getInstance()
        {
            if(m_Instance == NULL) m_Instance = new CxyUpload();
            return m_Instance;
        }
        bool requestPreSubmitTimelapse(std::string token,std::string printid, int deploy);
        bool requestTmplyAuthority(std::string token, int deploy);
        void StartUploadVideo(CxyUploadOptions_t options);
        void StartUploadLog(CxyUploadOptions_t options);
        void StopUploadLog(){m_abortUpload = true;}
        bool AssociateUploadVideoToPrintJob(char *printId);
        bool RequestRecordUploadLog();
        void RemoveLogPackges();
        std::string getUploadLogId();
        CxyUploadOptions_t* getOpetions(){return (m_setOptions.size()>0)? &m_setOptions[0]:nullptr;};
        std::string getvideoid(){return m_uploadVideoId;}
    private:
        CxyUpload();
        bool PreSubmitTimelapseAnl(std::string info);
        bool TmplyAuthorityInfoAnl(std::string info);
        bool AssociateUploadVideoAnl(std::string info);
        bool RequestRecordUploadLogAnl(std::string info);
        VodApiResponse UploadLocalFileToVod(VodCredential authInfo, CxyUploadOptions_t options);
        bool GetVideoIdFromUploadResult(VodApiResponse res);
        static void UploadProgress(int64_t consumedBytes, int64_t totalBytes);
        static void UploadLogProgress(int64_t consumedBytes, int64_t totalBytes);
        void InitOptions22(oss_request_options_t *options);
        int UploadLogToOss(char *src,char *dst);
        int UploadLogToOssMultipart(char *src,char *dst);

        void UploadFileThread(void *args);
        void UploadLogThread(void *args);
        bool PackLogFiles();

        int64_t GetFileSize(const char *file_path);
        aos_status_t *UploadPartTrys(const oss_request_options_t *options,
                                        const aos_string_t *bucket, 
                                        const aos_string_t *object,
                                        const aos_string_t *upload_id, 
                                        int part_num, 
                                        oss_upload_file_t *upload_file,
                                        aos_table_t **resp_headers);
        void WaitCond();
        void NotifyOne();
        void AddOneOption(CxyUploadOptions_t &option);
        void DeleteFirstOption();
        void UploadOne(CxyUploadOptions_t &option);
    public:
        std::vector<CxyUploadOptions_t>  m_setOptions;
        CxyUploadOptions_t      m_setLogOptions;
        std::mutex              m_videoOptionMutex;
        bool                    m_abortUpload;
    private:
        std::string             m_uploadVideoPath;
        std::string             m_uploadVideoName;
        std::string             m_uploadVideoId;
        std::string             m_appToken;
        std::string             m_uploadLogId;
        TmplyAuthority_t        m_tmplyAuthority;
        std::thread             m_uploadThread;
        std::thread             m_uploadLogThread;
        CxyHttpServer           m_cxyHttpServer;
        //int                     m_deploySetting;
        bool                    m_logStatus;
        bool                    m_videoStatus;
        static CxyUpload        *m_Instance;
        std::mutex              m_condMutex;
        std::condition_variable m_videoCond;
};

#endif
