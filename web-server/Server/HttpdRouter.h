/**
 * @ Author: Rui Xiong
 * @ Create Time: 2022-11-10 14:05:01
 * @ Modified by: Rui Xiong
 * @ Modified time: 2022-11-16 17:50:47
 * @ Description:
 */

#ifndef __HTTPD_ROUTER_H__
#define __HTTPD_ROUTER_H__

#include "hv/HttpService.h"

class Router {
public:
    static void Register(hv::HttpService& router);
};

#endif //__HTTPD_ROUTER_H__
