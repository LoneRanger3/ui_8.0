/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-04-18 17:36:01
 * @LastEditTime: 2023-06-07 12:06:26
 */
/**
 * @ Author: Rui Xiong
 * @ Create Time: 2022-11-10 14:05:01
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-03-07 20:03:49
 * @ Description:
 */

#ifndef __HTTPD_HANDLER_H__
#define __HTTPD_HANDLER_H__

#include "hv/HttpService.h"
using namespace std;

class recvlargefile
{
    public:
    recvlargefile(){file = nullptr;}
    ~recvlargefile(){
        if(file) {
            file->remove();
            delete file;
        }
    }
    HFile* file;
    std::string strBoundary;
    std::string save_path;
    std::string filename;
    std::string filepath;
    std::string tmppath;
};

class Handler {
public:
    // preprocessor => api_handlers => postprocessor
    static int preprocessor(HttpRequest* req, HttpResponse* resp);
    static int postprocessor(HttpRequest* req, HttpResponse* resp);
    static int errorHandler(const HttpContextPtr& ctx);

    static int sleep(const HttpRequestPtr& req, const HttpResponseWriterPtr& writer);
    static int setTimeout(const HttpContextPtr& ctx);
    static int query(const HttpContextPtr& ctx);

    static int kv(HttpRequest* req, HttpResponse* resp);
    static int json(HttpRequest* req, HttpResponse* resp);
    static int form(HttpRequest* req, HttpResponse* resp);
    static int grpc(HttpRequest* req, HttpResponse* resp);

    static int test(const HttpContextPtr& ctx);
    static int restful(const HttpContextPtr& ctx);

    static int login(const HttpContextPtr& ctx);
    static int upload(const HttpContextPtr& ctx);
    // SSE: Server Send Events
    static int sse(const HttpContextPtr& ctx);

    // LargeFile
    static int sendVideoFile(const HttpContextPtr& ctx);
    static int sendGcodeFile(const HttpContextPtr& ctx);
    static int sendLargeFile(const HttpContextPtr& ctx,string &filepath);
    static int recvLargeFile(const HttpContextPtr& ctx, http_parser_state state, const char* data, size_t size);

    static int info(HttpRequest* req, HttpResponse* resp);
    
private:
    static int response_status(HttpResponse* resp, int code = 200, const char* message = NULL) {
        if (message == NULL) message = http_status_str((enum http_status)code);
        resp->Set("code", code);
        resp->Set("message", message);
        return code;
    }
    static int response_status(const HttpResponseWriterPtr& writer, int code = 200, const char* message = NULL) {
        response_status(writer->response.get(), code, message);
        writer->End();
        return code;
    }
    static int response_status(const HttpContextPtr& ctx, int code = 200, const char* message = NULL) {
        response_status(ctx->response.get(), code, message);
        ctx->send();
        return code;
    }
};

#endif // __HTTPD_HANDLER_H__
