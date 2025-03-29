/*
 * @Description : 文件上传类
 * @Author      : Yufeng Zhang
 * @Date: 2022-09-23 10:21:03
 * @LastEditTime: 2023-10-27 16:23:46
 */

#include "vod_sdk/upload.h"
#include "Base/AppMsgBase.h"

#include "CxyHttpServer.h"
#include "CxyUpload.hh"

char endpoint[64];
char bucket_name[32];
static char object_name[512];
static char local_filename[256];
CxyUpload *CxyUpload::m_Instance = NULL;
/**
 * @description: 
 * @return {*}
 * @param {* args} *
 */
CxyUpload::CxyUpload()
{
    m_uploadVideoPath.clear();
    m_uploadVideoName.clear();
    m_uploadVideoId.clear();
    m_appToken.clear();
    m_logStatus = false;
    m_videoStatus = true;
    m_abortUpload = false;
    m_uploadThread = std::thread(&CxyUpload::UploadFileThread, this, (void*)NULL);
    //m_uploadThread.detach();
}

/**
 * @description: 
 * @return {*}
 */
CxyUpload::~CxyUpload()
{
    m_videoStatus = false;
    m_videoCond.notify_all();
    // 析构时保证子线程join进来
    if (m_uploadThread.joinable()) {
        m_uploadThread.join();
    }
    if (m_uploadLogThread.joinable()) {
        m_uploadLogThread.join();
    }
    m_setLogOptions.upload = NULL;
}

/**
 * @description: 
 * @return {*}
 * @param {string} info
 */
bool CxyUpload::TmplyAuthorityInfoAnl(std::string info)
{
    CrLogI("tmply authority info anl");
    // 解析获取的授权信息
    json_object *infoObj = json_tokener_parse(info.c_str());
    if (infoObj == NULL || !json_object_is_type(infoObj, json_type_object))
    {
        CrLogW("return information parsing error\n");
        if (infoObj != NULL) json_object_put(infoObj);
        return false;
    }

    // 判断code值
    json_object *codeObj = json_object_object_get(infoObj, "code");
    json_object *msgObj = json_object_object_get(infoObj, "msg");
    if (codeObj == NULL || !json_object_is_type(codeObj, json_type_int) ||
        msgObj == NULL || !json_object_is_type(msgObj, json_type_string))
    {
        CrLogW("no code or msg\n");
        json_object_put(infoObj);
        return false;
    }

    // 判断请求信息是否成功
    CrLogI("code = %d; msg = %s", json_object_get_int(codeObj), json_object_get_string(msgObj));
    if (json_object_get_int(codeObj) != 0 || strcmp(json_object_get_string(msgObj), "ok") != 0)
    {
        CrLogW("code or msg fail\n");
        json_object_put(infoObj);
        return false;
    }

    // 判断是否有返回结果
    json_object *resultObj = json_object_object_get(infoObj, "result");
    if (resultObj == NULL || !json_object_is_type(resultObj, json_type_object))
    {
        CrLogW("no return result\n");
        json_object_put(infoObj);
        return false;
    }

    // 获取授权信息
    json_object *accessKeyIdObj = json_object_object_get(resultObj, "accessKeyId");
    if (accessKeyIdObj != NULL && json_object_is_type(accessKeyIdObj, json_type_string))
    {
        m_tmplyAuthority.accessKeyId = json_object_get_string(accessKeyIdObj);
        CrLogI("accessKeyId = %s", AppAesEncryptToBase64(m_tmplyAuthority.accessKeyId).c_str());
    }
    json_object *secretAccessKeyObj = json_object_object_get(resultObj, "secretAccessKey");
    if (secretAccessKeyObj != NULL && json_object_is_type(secretAccessKeyObj, json_type_string))
    {
        m_tmplyAuthority.accessKeySecret = json_object_get_string(secretAccessKeyObj);
        CrLogI("secretAccessKey = %s", AppAesEncryptToBase64(m_tmplyAuthority.accessKeySecret).c_str());
    }
    json_object *expiredTimeObj = json_object_object_get(resultObj, "expiredTime");
    if (expiredTimeObj != NULL && json_object_is_type(expiredTimeObj, json_type_int))
    {
        m_tmplyAuthority.expired = json_object_get_int(expiredTimeObj);
        CrLogI("expiredTime = %u", m_tmplyAuthority.expired);
    }
    json_object *sessionTokenObj = json_object_object_get(resultObj, "sessionToken");
    if (sessionTokenObj != NULL && json_object_is_type(sessionTokenObj, json_type_string))
    {
        m_tmplyAuthority.stsToken = json_object_get_string(sessionTokenObj);
        CrLogI("sessionToken = %s\n", AppAesEncryptToBase64(m_tmplyAuthority.stsToken).c_str());
    }

    // 释放资源
    json_object_put(infoObj);
    return true;
}

/**
 * @description: 
 * @return {*}
 */
bool CxyUpload::requestTmplyAuthority(std::string token, int deploy)
{
    CrLogI("token = %s\n", token.c_str());
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(deploy);
    std::string url = server.url;
    m_cxyHttpServer.CxyHttpApiInit(url, "aliyun_authority");
    std::string tmplyAuthorityInfo;
    m_cxyHttpServer.HttpGetTmplyAuthorityInfo(token, &tmplyAuthorityInfo);

    if (!TmplyAuthorityInfoAnl(tmplyAuthorityInfo)) {
        CrLogW("TmplyAuthorityInfoAnl fail\n");
        return false;
    }
    // 记录 app token
    m_appToken = token;

    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {string} info
 */
bool CxyUpload::PreSubmitTimelapseAnl(std::string info)
{
    CrLogI("PreSubmitTimelapseAnl");
    // 解析获取的授权信息
    json_object *infoObj = json_tokener_parse(info.c_str());
    if (infoObj == NULL || !json_object_is_type(infoObj, json_type_object))
    {
        CrLogW("return information parsing error\n");
        if (infoObj != NULL) json_object_put(infoObj);
        return false;
    }

    // 判断code值
    json_object *codeObj = json_object_object_get(infoObj, "code");
    json_object *msgObj = json_object_object_get(infoObj, "msg");
    if (codeObj == NULL || !json_object_is_type(codeObj, json_type_int) ||
        msgObj == NULL || !json_object_is_type(msgObj, json_type_string))
    {
        CrLogW("no code or msg\n");
        json_object_put(infoObj);
        return false;
    }

    // 判断请求信息是否成功
    CrLogI("code = %d; msg = %s", json_object_get_int(codeObj), json_object_get_string(msgObj));
    if (json_object_get_int(codeObj) != 0 || strcmp(json_object_get_string(msgObj), "ok") != 0)
    {
        CrLogW("code or msg fail\n");
        json_object_put(infoObj);
        return false;
    }

    // 判断是否有返回结果
    json_object *resultObj = json_object_object_get(infoObj, "result");
    if (resultObj == NULL || !json_object_is_type(resultObj, json_type_object))
    {
        CrLogW("no return result\n");
        json_object_put(infoObj);
        return false;
    }

    json_object *enoughobj = json_object_object_get(resultObj, "enough");
    if (enoughobj == NULL || !json_object_is_type(enoughobj, json_type_boolean))
    {
        CrLogW("no return enoughobj\n");
        json_object_put(infoObj);
        return false;
    }

    bool enough = json_object_get_boolean(enoughobj);
    if (enough == false)
    {
        CrLogW("no enough space\n");
        json_object_put(infoObj);
        return false;
    }

    json_object *vodCredential = json_object_object_get(resultObj, "vodCredential");
    if (vodCredential == NULL || !json_object_is_type(vodCredential, json_type_object))
    {
        CrLogW("no return vodCredential\n");
        json_object_put(infoObj);
        return false;
    }
    
    // 获取授权信息
    json_object *regionIdObj = json_object_object_get(vodCredential, "regionId");
    if (regionIdObj != NULL && json_object_is_type(regionIdObj, json_type_string))
    {
        m_tmplyAuthority.regionId = json_object_get_string(regionIdObj);
        CrLogI("regionId = %s", m_tmplyAuthority.regionId.c_str());
    }    
    json_object *accessKeyIdObj = json_object_object_get(vodCredential, "accessKeyId");
    if (accessKeyIdObj != NULL && json_object_is_type(accessKeyIdObj, json_type_string))
    {
        m_tmplyAuthority.accessKeyId = json_object_get_string(accessKeyIdObj);
        CrLogI("accessKeyId = %s", AppAesEncryptToBase64(m_tmplyAuthority.accessKeyId).c_str());
    }
    json_object *secretAccessKeyObj = json_object_object_get(vodCredential, "accessKeySecret");
    if (secretAccessKeyObj != NULL && json_object_is_type(secretAccessKeyObj, json_type_string))
    {
        m_tmplyAuthority.accessKeySecret = json_object_get_string(secretAccessKeyObj);
        CrLogI("accessKeySecret = %s", AppAesEncryptToBase64(m_tmplyAuthority.accessKeySecret).c_str());
    }
    json_object *sessionTokenObj = json_object_object_get(vodCredential, "securityToken");
    if (sessionTokenObj != NULL && json_object_is_type(sessionTokenObj, json_type_string))
    {
        m_tmplyAuthority.stsToken = json_object_get_string(sessionTokenObj);
        CrLogI("securityToken = %s\n", AppAesEncryptToBase64(m_tmplyAuthority.stsToken).c_str());
    }

    json_object *VideoRequest = json_object_object_get(resultObj, "createUploadVideoRequest");
    if (VideoRequest == NULL || !json_object_is_type(VideoRequest, json_type_object))
    {
        CrLogW("no return VideoRequest\n");
        json_object_put(infoObj);
        return false;
    }

    json_object *tagsObj = json_object_object_get(VideoRequest, "tags");
    if (tagsObj != NULL && json_object_is_type(tagsObj, json_type_string))
    {
        m_tmplyAuthority.tags = json_object_get_string(tagsObj);
        CrLogI("tags = %s\n", AppAesEncryptToBase64(m_tmplyAuthority.tags).c_str());
    }

    json_object *userDataObj = json_object_object_get(VideoRequest, "userData");
    if (userDataObj != NULL && json_object_is_type(userDataObj, json_type_string))
    {
        m_tmplyAuthority.userData = json_object_get_string(userDataObj);
        CrLogI("userData = %s\n", AppAesEncryptToBase64(m_tmplyAuthority.userData).c_str());
    }

    json_object *workflowIdObj = json_object_object_get(VideoRequest, "workflowId");
    if (workflowIdObj != NULL && json_object_is_type(workflowIdObj, json_type_string))
    {
        m_tmplyAuthority.workflowId = json_object_get_string(workflowIdObj);
        CrLogI("workflowId = %s\n", AppAesEncryptToBase64(m_tmplyAuthority.workflowId).c_str());
    }
    // 释放资源
    json_object_put(infoObj);
    return true;
}
/**
 * @description: 
 * @return {*}
 */
bool CxyUpload::requestPreSubmitTimelapse(std::string token,std::string printid, int deploy)
{
    RegisterInfo_t devInfo;
    m_cxyHttpServer.GetRegisterInfoFromFile(&devInfo);
    DeviceTbInfo_t tbInfo;
    m_cxyHttpServer.GetTbInfoFromFile(&tbInfo);
    // 获取视频文件MD5码
    char fileMd5[256] = {0};
    if (!getFileMD5((char*)m_uploadVideoPath.c_str(), fileMd5))
        CrLogW("get file Md5 fail!\n");
    CrLogI("voide file md5 = [%d] %s", strlen(fileMd5), fileMd5);

    VideoAssociate_t para;
    para.mac = devInfo.mac;
    para.printId = printid;
    para.deviceName = tbInfo.devId;
    para.md5 = fileMd5;
    para.manually = false;
    para.name = m_uploadVideoName;
    para.size = GetFileSize((char*)m_uploadVideoPath.c_str());
    CrLogI("token = %s\n", token.c_str());
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(deploy);
    std::string url = server.url;
    m_cxyHttpServer.CxyHttpApiInit(url, "presubmit_timelapse");
    std::string presubmitInfo;
    m_cxyHttpServer.HttpGetPreSubmitTimelapse(token,para, &presubmitInfo);
    CrLogI("##RET = %s\n", presubmitInfo.c_str());
    if (!PreSubmitTimelapseAnl(presubmitInfo)) {
        CrLogW("PreSubmitTimelapseAnl fail\n");
        return false;
    }
    // 记录 app token
    m_appToken = token;

    return true;
}

/**
 * @description: 
 * @return {bool}
 * @param {char *} token
 */
bool CxyUpload::RequestRecordUploadLog()
{
    DeviceTbInfo_t tbInfo;
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(m_setLogOptions.deploy_setting);
    std::string url = server.url;
    m_cxyHttpServer.GetTbInfoFromFile(&tbInfo);
    m_cxyHttpServer.CxyHttpApiInit(url, "submit_log_file");
    std::string recordUploadLogInfo;
    m_cxyHttpServer.HttpCallRecordUploadLog2server(m_appToken, tbInfo.devName, object_name, &recordUploadLogInfo);

    if (!RequestRecordUploadLogAnl(recordUploadLogInfo)) {
        CrLogW("RequestRecordUploadLogAnl fail\n");
        return false;
    }
    // 记录 app token
    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {int64_t} consumedBytes
 * @param {int64_t} totalBytes
 */
void CxyUpload::UploadProgress(int64_t consumedBytes, int64_t totalBytes)
{
    int progress = consumedBytes * 100 / totalBytes ;
    CrLogI("upload progress :%lld/%lld (%d%%)", consumedBytes, totalBytes, progress);
    std::lock_guard<std::mutex> lock(CxyUpload::getInstance()->m_videoOptionMutex);
    if(CxyUpload::getInstance()->m_setOptions.size()>0)
        CxyUpload::getInstance()->m_setOptions[0].conStateCb(FILE_UPLOAD_ING,CxyUpload::getInstance(),progress);
}

/**
 * @description: 
 * @return {*}
 * @param {VodCredential} authInfo
 * @param {string} filePath
 * @param {string} uploadTitle
 */
VodApiResponse CxyUpload::UploadLocalFileToVod(VodCredential authInfo, CxyUploadOptions_t options)
{
    // 获取文件名称
    std::string filePath = options.filePath;
    char buff[1024] = {0};
	unsigned int index = filePath.rfind("/") + 1;
    filePath.copy(buff, (filePath.length() - index), index);
	m_uploadVideoName = buff;
    CrLogI("voide file name = %s", m_uploadVideoName.c_str());

    CreateUploadVideoRequest request;
	request.fileName = m_uploadVideoName;
	request.title = options.fileTitle;
    request.tags = m_tmplyAuthority.tags;
    request.workflowId = m_tmplyAuthority.workflowId;
    request.userData = m_tmplyAuthority.userData;
    
    UploadOptions uploadOptions;
    uploadOptions.uploadProgressCallback = UploadProgress;

    // 开始上传, 最大重传次数 TRY_UPLOAD_MAX_TIMER
    int tryUploadCount = 0;
	VodApiResponse result;
    do {
        if (tryUploadCount) {
            CrLogW("httpCode = %d", result.httpCode);
            CrLogW("result = %s", result.result.c_str());
            CrLogW("upload local Video fail, restart upload\n");
            usleep(1000 * 100);
        }
        result = uploadLocalVideo(authInfo, request, filePath, uploadOptions);
    } while (result.httpCode != 200 && ++tryUploadCount <= TRY_UPLOAD_MAX_TIMER);

    CrLogI("upload local file to vod finish");
    m_uploadVideoPath = filePath;
	return result;
}

/**
 * @description: 
 * @return {*}
 * @param {VodApiResponse} res
 */
bool CxyUpload::GetVideoIdFromUploadResult(VodApiResponse res)
{
    int httpCode = res.httpCode;
    std::string infor = res.result;
    m_uploadVideoId.clear();

    // 获取返回结果json对象
    json_object *infoObj = json_tokener_parse(infor.c_str());
    if (infoObj == NULL || !json_object_is_type(infoObj, json_type_object))
    {
        CrLogW("upload result parse fail\n");
        if (infoObj) json_object_put(infoObj);
        return false;
    }

    // 解析http code
    switch (httpCode) {
        case 200: break;

        case -1: {
            CrLogE("code = %d, error: %s\n", httpCode, infor.c_str());
            json_object_put(infoObj);
            return false;
        }

        case 400:
        case 404: {
            json_object *messageObj = json_object_object_get(infoObj, "Message");
            if (messageObj != NULL && json_object_is_type(messageObj, json_type_string))
                CrLogE("code = %d, error: %s\n", httpCode, json_object_get_string(messageObj));
            else CrLogE("code = %d, error: AK or token error\n",  httpCode);

            json_object_put(infoObj);
            return false;
        }

        default: {
            json_object *messageObj = json_object_object_get(infoObj, "Message");
            if (messageObj != NULL && json_object_is_type(messageObj, json_type_string))
                CrLogE("code = %d, error: %s\n", httpCode, json_object_get_string(messageObj));
            else CrLogE("code = %d, error: unknown error\n", httpCode);

            json_object_put(infoObj);
            return false;
        }
    }

    // 解析上传视频结果
    // {
    //     "RequestId": "25818875-5F78-4AF6-04D5-D7393642****",
    //     "UploadAddress": "eyJTZWN1cml0a2VuIjoiQ0FJU3p3TjF****",
    //     "VideoId": "93ab850b4f6f54b6e91d24d81d44****",
    //     "UploadAuth": "eyJFbmRwb2ludCI6Imm****"
    // }

    // 获取 VideoId
    json_object *videoIdObj = json_object_object_get(infoObj, "VideoId");
    if (videoIdObj != NULL && json_object_is_type(videoIdObj, json_type_string))
        m_uploadVideoId = json_object_get_string(videoIdObj);
    else CrLogE("code = %d, error: not find VideoId infor\n",  httpCode);

    CrLogI("get video id = %s\n", m_uploadVideoId.c_str());
    // 释放json
    json_object_put(infoObj);
    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {oss_request_options_t *} options
 */
void CxyUpload::InitOptions22(oss_request_options_t *options)
{
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(m_setLogOptions.deploy_setting);
    snprintf(endpoint,sizeof(endpoint),"%s",server.endpoint.c_str());
    options->config = oss_config_create(options->pool);
    aos_str_set(&options->config->endpoint, endpoint);
    aos_str_set(&options->config->access_key_id, m_tmplyAuthority.accessKeyId.c_str());
    aos_str_set(&options->config->access_key_secret, m_tmplyAuthority.accessKeySecret.c_str());
    aos_str_set(&options->config->sts_token, m_tmplyAuthority.stsToken.c_str());
    options->config->is_cname = 0;
    options->ctl = aos_http_controller_create(options->pool, 0);
}

void CxyUpload::UploadLogProgress(int64_t consumedBytes, int64_t totalBytes)
{
    int progress = consumedBytes * 100 / totalBytes ;
    if(CxyUpload::getInstance()->m_abortUpload == false)
        CxyUpload::getInstance()->m_setLogOptions.conStateCb(FILE_UPLOAD_ING,CxyUpload::getInstance(),progress);
    CrLogI("UploadLogProgress %d consumed_bytes = %lld total_bytes = %lld\n",progress,consumedBytes, totalBytes);
}

/**
 * @description: 
 * @return {int}
 * @param {char*} src
 * @param {char*} dst
 */
int CxyUpload::UploadLogToOss(char *src,char *dst)
{
    int iRet = -1;
    aos_pool_t *pool;
    aos_pool_create(&pool, NULL);
    oss_request_options_t *oss_client_options;
    oss_client_options = oss_request_options_create(pool);
    InitOptions22(oss_client_options);
    aos_string_t bucket;
    aos_string_t object;
    aos_string_t file;
    aos_table_t *headers = NULL;
    aos_table_t *resp_headers = NULL;
    aos_status_t *resp_status = NULL;
    aos_http_request_t *req;
    apr_time_t now;
    char *url_str;
    aos_string_t url;
    int64_t expire_time;
    int one_hour = 3600;
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(m_setLogOptions.deploy_setting);
    snprintf(bucket_name,sizeof(bucket_name),"%s",server.bucket.c_str());
    aos_str_set(&bucket, bucket_name);
    aos_str_set(&object, dst);
    aos_str_set(&file, src);
    headers = aos_table_make(pool, 0);
    req = aos_http_request_create(pool);
    req->method = HTTP_PUT;
    now = apr_time_now();
    expire_time = now / 1000000 + one_hour;
    url_str = oss_gen_signed_url(oss_client_options, &bucket, &object, expire_time, req);
    aos_str_set(&url, url_str);

    // 开始上传, 最大重传次数 TRY_UPLOAD_MAX_TIMER
    int tryUploadCount = 0;
    do {
        if (tryUploadCount) {
            CrLogW("code = %d", resp_status->code);
            if (resp_status->error_code) CrLogW("error_code = %s", resp_status->error_code);
            if (resp_status->error_msg) CrLogW("error_msg = %s", resp_status->error_msg);
            if (resp_status->req_id) CrLogW("req_id = %s", resp_status->req_id);
            CrLogW("upload log fail, restart upload\n");
            usleep(1000 * 100);
        }

        aos_list_t resp_body;
        resp_status = oss_do_put_object_from_file(oss_client_options,
                                          &bucket, &object, 
                                          &file,
                                          headers, 
                                          NULL,
                                          UploadLogProgress,
                                          &resp_headers,
                                          &resp_body);
        CrLogI("UploadLogToOss ff resp_status = %d\n", resp_status->code);                        
        //resp_status = oss_put_object_from_file_by_url(oss_client_options, &url, &file, headers, &resp_headers);
    } while (!aos_status_is_ok(resp_status) && ++tryUploadCount <= TRY_UPLOAD_MAX_TIMER);
    
    if (aos_status_is_ok(resp_status)){
        iRet = 0;
        m_setLogOptions.conStateCb(FILE_UPLOAD_OK,m_setLogOptions.upload,0);
    }
    else{
        m_setLogOptions.conStateCb(FILE_UPLOAD_FAIL,m_setLogOptions.upload,0);
        iRet = -1;
    }
    aos_pool_destroy(pool);

    return iRet;
}

int64_t CxyUpload::GetFileSize(const char *file_path)
{
    int64_t filesize = 0;
    struct stat statbuff;
    if(stat(file_path, &statbuff) < 0){
        return filesize;
    } else {
        filesize = statbuff.st_size;
    }
    return filesize;
}

aos_status_t *CxyUpload::UploadPartTrys(const oss_request_options_t *options,
                                        const aos_string_t *bucket, 
                                        const aos_string_t *object,
                                        const aos_string_t *upload_id, 
                                        int part_num, 
                                        oss_upload_file_t *upload_file,
                                        aos_table_t **resp_headers)
{
    aos_status_t *resp_status = NULL;
    int tryUploadCount = 0;
    do {
        if (tryUploadCount) {
            CrLogW("code = %d", resp_status->code);
            if (resp_status->error_code) CrLogW("error_code = %s", resp_status->error_code);
            if (resp_status->error_msg) CrLogW("error_msg = %s", resp_status->error_msg);
            if (resp_status->req_id) CrLogW("req_id = %s", resp_status->req_id);
            CrLogW("part trys upload log fail, restart upload\n");
            usleep(1000 * 100);
        }

        resp_status = oss_upload_part_from_file(options, bucket, object, upload_id, part_num, upload_file, resp_headers);
    } while (!aos_status_is_ok(resp_status) && ++tryUploadCount <= TRY_UPLOAD_MAX_TIMER);
    return resp_status;
}

int CxyUpload::UploadLogToOssMultipart(char *src,char *dst)
{
    int iRet = -1;
    aos_pool_t *pool;
    aos_pool_create(&pool, NULL);
    oss_request_options_t *oss_client_options;
    oss_client_options = oss_request_options_create(pool);
    InitOptions22(oss_client_options);
    aos_string_t bucket;
    aos_string_t object;
    aos_string_t file;
    aos_table_t *headers = NULL;
    aos_table_t *complete_headers = NULL;
    aos_table_t *resp_headers = NULL;
    aos_status_t *resp_status = NULL;
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(m_setLogOptions.deploy_setting);
    snprintf(bucket_name,sizeof(bucket_name),"%s",server.bucket.c_str());
    aos_str_set(&bucket, bucket_name);
    aos_str_set(&object, dst);
    aos_str_set(&file, src);
    headers = aos_table_make(pool, 1);
    complete_headers = aos_table_make(pool, 1);
    aos_string_t upload_id;
    aos_str_null(&upload_id);
    /* 初始化分片上传，获取一个上传ID(upload_id)。*/
    resp_status = oss_init_multipart_upload(oss_client_options, &bucket, &object, &upload_id, headers, &resp_headers);
    /* 判断是否初始化分片上传成功。 */
    if (aos_status_is_ok(resp_status)) {
        CrLogI("UploadLogToOssMultipart upload_id:%.*s\n", upload_id.len, upload_id.data);  
    } else {
        CrLogW("UploadLogToOssMultipart fail upload_id:%.*s\n", upload_id.len, upload_id.data); 
        aos_pool_destroy(pool);
        return -1;
    }

    int64_t file_length = 0;
    int64_t pos = 0;
    aos_list_t complete_part_list;
    oss_complete_part_content_t* complete_content = NULL;
    char* part_num_str = NULL;
    char* etag = NULL;
    aos_list_init(&complete_part_list);
    file_length = GetFileSize(src);
    oss_upload_file_t *upload_file = NULL;
    int part_num = 1;
    int sucupload = true;
    if(file_length < 0)
        sucupload = false;
    while(pos < file_length) {
        upload_file = oss_create_upload_file(pool);
        aos_str_set(&upload_file->filename, src);
        upload_file->file_pos = pos;
        pos += 100 * 1024;
        upload_file->file_last = pos < file_length ? pos : file_length;
        resp_status = UploadPartTrys(oss_client_options, &bucket, &object, &upload_id, part_num++, upload_file, &resp_headers);

        if (aos_status_is_ok(resp_status)) {
            int progress = pos * 100 / file_length ;
            if(progress>100 ) progress = 100;
            m_setLogOptions.conStateCb(FILE_UPLOAD_ING,CxyUpload::getInstance(),progress);
            CrLogI("Multipart upload part from file succeeded %d\n",progress);
        } else {
            CrLogI("Multipart upload part from file failed\n");
            sucupload = false;
            break;
        }

        if(m_abortUpload)
        {
            /* 取消这次分片上传。*/
            resp_status = oss_abort_multipart_upload(oss_client_options, &bucket, &object, &upload_id, &resp_headers);
            /* 判断取消分片上传是否成功。*/
            if (aos_status_is_ok(resp_status)) {
                CrLogI("Abort multipart upload succeeded, upload_id::%.*s\n", 
                    upload_id.len, upload_id.data);
                iRet = 0;
                m_setLogOptions.conStateCb(FILE_UPLOAD_STOPOK,m_setLogOptions.upload,0);
            } else {
                CrLogW("Abort multipart upload failed\n"); 
            }
            
            sucupload = false;
            break;
        }

        /* 保存分片号和ETag。*/
        complete_content = oss_create_complete_part_content(pool);
        part_num_str = apr_psprintf(pool, "%d", part_num-1);
        aos_str_set(&complete_content->part_number, part_num_str);
        etag = apr_pstrdup(pool,
        (char*)apr_table_get(resp_headers, "ETag"));
        aos_str_set(&complete_content->etag, etag);
        aos_list_add_tail(&complete_content->node, &complete_part_list);
    }

    if(sucupload)
    {
        /* 完成分片上传。*/
        resp_status = oss_complete_multipart_upload(oss_client_options, &bucket, &object, &upload_id,
                &complete_part_list, complete_headers, &resp_headers);
        /* 判断分片上传是否完成。*/
        if (aos_status_is_ok(resp_status)) {
            iRet = 0;
            m_setLogOptions.conStateCb(FILE_UPLOAD_OK,m_setLogOptions.upload,0);
            CrLogI("Complete multipart upload from file success\n");
        } else {
            CrLogI("Complete multipart upload from file failed\n");
        }
    }
    
    if(iRet != 0)
        m_setLogOptions.conStateCb(FILE_UPLOAD_FAIL,m_setLogOptions.upload,0);
    
    aos_pool_destroy(pool);

    return iRet;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *args
 */
void CxyUpload::UploadFileThread(void *args)
{
    while(m_videoStatus)
    {
        WaitCond();
        while(m_setOptions.size()>0)
        {
            UploadOne(m_setOptions[0]);
            DeleteFirstOption();
        }
    }
}

/**
 * @description: 
 * @return {*}
 * @param 
 */
void CxyUpload::UploadLogThread(void *args)
{
    CrLogI("start upload log ...");
    m_setLogOptions.conStateCb(FILE_UPLOAD_COMPRESS,m_setLogOptions.upload,0);

    // 压缩日志
    if(!PackLogFiles()) {
        CrLogE("pack log files fail, %s not exist \r\n",local_filename);
        goto UPLOAD_LOG_END;
    }
    m_setLogOptions.conStateCb(FILE_UPLOAD_ING,m_setLogOptions.upload,0);

    // 获取阿里云权限
    if (!requestTmplyAuthority(m_setLogOptions.appToken,m_setLogOptions.deploy_setting)) {
        CrLogW("get aliyun tmply authority fail\n");
        goto UPLOAD_LOG_END;
    }
    CrLogI("get aliyun tmply authority successfully");

    // 初始化oss库
    if (aos_http_io_initialize(NULL, 0) != AOSE_OK) {
        CrLogE("aos_http_io_initialize fail\r\n");
        goto UPLOAD_LOG_END;
    }

    // 开始上传
    UploadLogToOssMultipart(local_filename,object_name);
    aos_http_io_deinitialize();
    m_logStatus = false;
    return;

UPLOAD_LOG_END:
    m_logStatus = false;
    m_setLogOptions.conStateCb(FILE_UPLOAD_FAIL,m_setLogOptions.upload,0);
}

/**
 * @description: 
 * @return {*}
 * @param {CxyUploadOptions_t} options
 */
void CxyUpload::StartUploadVideo(CxyUploadOptions_t options)
{
    AddOneOption(options);
    NotifyOne();
}

/**
 * @description: 
 * @return {*}
 * @param {CxyUploadOptions_t} options
 */
void CxyUpload::StartUploadLog(CxyUploadOptions_t options)
{
    if(m_logStatus){
        options.conStateCb(FILE_UPLOAD_FAIL,this,0);
        return;
    }
    m_abortUpload = false;
    m_logStatus = true;
    m_setLogOptions = options;
    m_uploadLogThread = std::thread(&CxyUpload::UploadLogThread, this, (void*)NULL);
    m_uploadLogThread.detach();
}

/**
 * @description: 
 * @return {*}
 * @param {string} info
 */
bool CxyUpload::AssociateUploadVideoAnl(std::string info)
{
    CrLogI("associate upload video anl");
    // 解析返回结果
    json_object *infoObj = json_tokener_parse(info.c_str());
    if (infoObj == NULL || !json_object_is_type(infoObj, json_type_object))
    {
        CrLogW("return information parsing error\n");
        if (infoObj != NULL) json_object_put(infoObj);
        return false;
    }

    // 判断code值
    json_object *codeObj = json_object_object_get(infoObj, "code");
    json_object *msgObj = json_object_object_get(infoObj, "msg");
    if (codeObj == NULL || !json_object_is_type(codeObj, json_type_int) ||
        msgObj == NULL || !json_object_is_type(msgObj, json_type_string))
    {
        CrLogW("no code or msg\n");
        json_object_put(infoObj);
        return false;
    }

    // 判断请求信息是否成功
    CrLogI("code = %d; msg = %s", json_object_get_int(codeObj), json_object_get_string(msgObj));
    if (json_object_get_int(codeObj) != 0 || strcmp(json_object_get_string(msgObj), "ok") != 0)
    {
        CrLogW("code or msg fail\n");
        json_object_put(infoObj);
        return false;
    }

    CrLogI("associate upload video to print jod finish\n");
    // 释放资源
    json_object_put(infoObj);
    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {string} info
 */
bool CxyUpload::RequestRecordUploadLogAnl(std::string info)
{
    CrLogI("record upload log anl");
    // 解析返回结果
    json_object *infoObj = json_tokener_parse(info.c_str());
    if (infoObj == NULL || !json_object_is_type(infoObj, json_type_object))
    {
        CrLogW("return information parsing error\n");
        if (infoObj != NULL) json_object_put(infoObj);
        return false;
    }

    // 判断code值
    json_object *codeObj = json_object_object_get(infoObj, "code");
    json_object *msgObj = json_object_object_get(infoObj, "msg");
    if (codeObj == NULL || !json_object_is_type(codeObj, json_type_int) ||
        msgObj == NULL || !json_object_is_type(msgObj, json_type_string))
    {
        CrLogW("no code or msg\n");
        json_object_put(infoObj);
        return false;
    }

    // 判断请求信息是否成功
    CrLogI("code = %d; msg = %s", json_object_get_int(codeObj), json_object_get_string(msgObj));
    if (json_object_get_int(codeObj) != 0 || strcmp(json_object_get_string(msgObj), "ok") != 0)
    {
        CrLogW("code or msg fail\n");
        json_object_put(infoObj);
        return false;
    }

    CrLogI("record upload log to server finish\n");
    // 释放资源
    json_object_put(infoObj);
    return true;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *token
 * @param {char} *mac
 * @param {char} *printIdUploadLogToOss
 * @param {char} *deviceId
 */
bool CxyUpload::AssociateUploadVideoToPrintJob(char *printId)
{
    // 获取设备IOT信息
    RegisterInfo_t devInfo;
    m_cxyHttpServer.GetRegisterInfoFromFile(&devInfo);
    DeviceTbInfo_t tbInfo;
    m_cxyHttpServer.GetTbInfoFromFile(&tbInfo);
    // 获取视频文件MD5码
    char fileMd5[256] = {0};
    if (!getFileMD5((char*)m_uploadVideoPath.c_str(), fileMd5))
        CrLogW("get file Md5 fail!\n");
    CrLogI("voide file md5 = [%d] %s", strlen(fileMd5), fileMd5);

    VideoAssociate_t para;
    para.mac = devInfo.mac;
    para.videoId = m_uploadVideoId;
    para.printId = printId;
    para.deviceName = tbInfo.devId;
    para.md5 = fileMd5;
    para.manually = false;
    para.name = m_uploadVideoName;
    int deploy_setting = 0;
    if(m_setOptions.size()>0)
        deploy_setting = m_setOptions[0].deploy_setting;
    // 初始化 http 接口
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(deploy_setting);
    std::string url = server.url;
    m_cxyHttpServer.CxyHttpApiInit(url, "video_associate");
    // 关联流逝影像视频到打印任务
    std::string httpRes;
    if (m_cxyHttpServer.HttpAssociateVideoToPrintJob(m_appToken, para, &httpRes) == CURLE_OK)
    {
        CrLogI("upload result = %s", httpRes.c_str());
        if (AssociateUploadVideoAnl(httpRes)) return true;
    }

    return false;
}

/**
 * @description: 
 * @return {*}
 * @param 
 */
bool CxyUpload::PackLogFiles()
{
    #define TIMESTR_FMT "%Y-%m-%d__%H-%M-%S" //"%Y%m%d_%H%M%S"
    char cmd[512]= {0};
    char ctime[128];
    struct tm *stTime;
    time_t now = time(NULL);
    stTime = localtime(&now);
    strftime(ctime, sizeof(ctime),TIMESTR_FMT, stTime);

    DeviceTbInfo_t tbInfo;
    m_cxyHttpServer.GetTbInfoFromFile(&tbInfo);
    char* logPath = GetUserDataLogDirPtah();
    bzero(local_filename, sizeof(local_filename));
    snprintf(local_filename,sizeof(local_filename),"%slog-%s.7z",logPath,ctime);

    // 获取系统信息
    GetSaveSystemInfoToFile(GetTempSaveSystemInfoPath());

    // 构建压缩命令
    snprintf(cmd, sizeof(cmd), GetDefaultLog7zNoPasswordScript(),
        local_filename, GetUserDataLogDirPtah(), GetUserDataKlipperLogDirPtah(),
        GetDefaultSystemKernelLogPtah(), GetUserDataConfigDirPtah(), GetTempSaveSystemInfoPath());
    CrLogI("export log cmd = %s\n", cmd);

    // 调用系统命令
    char sysRes[1024] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);

    CrLogD("done.\n");

    json_object *systemConfig = json_object_from_file(GetUserSystemConfigFilePath());
    const char *modelStr = NULL;
    if (systemConfig){
        json_object *devInfoObj = NULL , *modelObj = NULL;
        devInfoObj = json_object_object_get(systemConfig, "device_info");
        if(devInfoObj){
            modelObj = json_object_object_get(devInfoObj, "model_str");
            if(modelObj){
                modelStr = json_object_get_string(modelObj);
            }
        }
    }

    snprintf(object_name,sizeof(object_name),"FDM_HS/%s/%s/log/%.10s/%s",modelStr,tbInfo.devName.c_str(),ctime,&local_filename[strlen(logPath)]);
    CrLogD("object_name:%s\n", object_name);
    m_uploadLogId = object_name;
    return (access(local_filename, R_OK) == 0) ;
}

/**
 * @description: 
 * @return {*}
 * @param 
 */
void CxyUpload::RemoveLogPackges()
{
    char cmd[256]= {0};
    char* logPath = GetUserDataLogDirPtah();
    snprintf(cmd,sizeof(cmd),"rm -f %s*.7z && sync",logPath);
    CrLogD("cmd:[%s]\n",cmd);

    // 调用系统命令
    char sysRes[1024] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
        CrLogW("system fail! res = %s\n", sysRes);
}

/**
 * @description: 
 * @return {*}
 * @param 
 */
std::string CxyUpload::getUploadLogId()
{
    return m_uploadLogId;
}

void CxyUpload::WaitCond()
{
    CrLogI("WaitCond start");
    std::unique_lock<std::mutex> lock(m_condMutex);
    m_videoCond.wait(lock);
}

void CxyUpload::NotifyOne()
{
    CrLogI("NotifyOne start");
    std::unique_lock<std::mutex> lock(m_condMutex);
    m_videoCond.notify_one();
}

void CxyUpload::AddOneOption(CxyUploadOptions_t &option)
{
    std::lock_guard<std::mutex> lock(m_videoOptionMutex);
    m_setOptions.push_back(option);
    CrLogI("AddOneOption %d %s",m_setOptions.size(),option.filePath.c_str());
}

void CxyUpload::DeleteFirstOption()
{
    std::lock_guard<std::mutex> lock(m_videoOptionMutex);
    if(m_setOptions.size()>0){
        CrLogI("DeleteFirstOption size:%d path:%s",m_setOptions.size(),m_setOptions[0].filePath.c_str());
        m_setOptions.erase(m_setOptions.begin());
    }
}

void CxyUpload::UploadOne(CxyUploadOptions_t &option)
{
    // 获取阿里云权限
    if (!requestPreSubmitTimelapse(option.appToken,option.printId,option.deploy_setting)) {
        CrLogW("requestPreSubmitTimelapse fail\n");
        option.conStateCb(FILE_UPLOAD_FAIL,option.upload,0);
        return;
    }
    CrLogI("requestPreSubmitTimelapse successfully");
    //CrLogI("start upload video ...");
    CrLogI("path = %s, title = %s", option.filePath.c_str(), option.fileTitle.c_str());
    option.conStateCb(FILE_UPLOAD_ING,option.upload,0);

    // 开始上传
	VodCredential authInfo;
    authInfo.regionId = m_tmplyAuthority.regionId;
    authInfo.accessKeyId = m_tmplyAuthority.accessKeyId;
    authInfo.accessKeySecret = m_tmplyAuthority.accessKeySecret;
    authInfo.securityToken = m_tmplyAuthority.stsToken;
    // authInfo.regionId = (m_tmplyAuthority.iotId) ? "cn-shanghai" : "ap-southeast-1";
    CxyServer_t server = m_cxyHttpServer.GetCxyServer(option.deploy_setting);
    authInfo.regionId = server.vod;

	VodApiResponse response = UploadLocalFileToVod(authInfo, option);
	CrLogI("httpCode: %d, result len: %d", response.httpCode, response.result.length());
    if (GetVideoIdFromUploadResult(response)) option.conStateCb(FILE_UPLOAD_OK,option.upload,0);
    else option.conStateCb(FILE_UPLOAD_FAIL,option.upload,0);
}
