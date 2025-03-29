/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-08-15 17:36:26
 * @LastEditTime: 2023-08-29 15:21:35
 */
#ifndef __WEBSOCKET_H__
#define __WEBSOCKET_H__

#include "hv/WebSocketServer.h"
#include "hv/EventLoop.h"
#include "hv/htime.h"
#include "hv/hssl.h"
#include "hv/hlog.h"
#include <ctime>
#include <atomic>
#include <memory>
#include "global/Global.h"

using namespace hv;
using namespace std;

class WebSocket : public HttpServer {
public:
    static shared_ptr<WebSocket> getInstance(){
        return m_instance;
    }

    ~WebSocket() { stop(); }
    void sendToAllSocket(std::string &message);
    void sendToSocket(int socketId,std::string &message);
    int getSocketCount() {return m_webSocketMap.size();}
private:
    WebSocket();
    void onclose(const WebSocketChannelPtr& channel);
    void onopen(const WebSocketChannelPtr& channel, const HttpRequestPtr& req);
    void onmessage(const WebSocketChannelPtr& channel, const std::string& msg);
    void AddPropTimer();
    void RemovePropTimer();
    void TimerProc();
private:
    HttpService             m_http;
    WebSocketService        m_webservice;
    std::map<int, WebSocketChannelPtr>  m_webSocketMap;
    std::mutex                                  m_mapmutex;
    TimerID timerID;
    static shared_ptr<WebSocket> m_instance;
};
#endif
