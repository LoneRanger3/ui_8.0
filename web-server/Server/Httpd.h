/**
 * @ Author: Rui Xiong
 * @ Create Time: 2022-11-21 17:00:56
 * @ Modified by: Rui Xiong
 * @ Modified time: 2022-12-30 14:41:35
 * @ Description:
 */

#ifndef __HTTPD_H__
#define __HTTPD_H__

#include "hv/hv.h"
#include "hv/hssl.h"
#include "hv/hmain.h"
#include "hv/iniparser.h"
#include "hv/hlog.h"
#include "hv/HttpServer.h"
#include "hv/hasync.h"     // import hv::async
#include "HttpdRouter.h"
#include "global/Global.h"

class Httpd {
    public:
        Httpd();
        ~Httpd();
        void SetConfile();
        void Start();
    private:
        int ParseConfile(const char* confile);  
        int Initialization();
        hv::HttpServer  m_http_server;
        hv::HttpService m_http_service;          

};
#endif // __HTTPD_H__
