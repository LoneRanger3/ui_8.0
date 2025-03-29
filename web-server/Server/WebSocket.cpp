/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-08-15 18:00:59
 * @LastEditTime: 2023-08-29 15:22:35
 */
#include "WebSocket.h"
#include "DataManager/DataParser.h"
#include "DataManager/AttributeProc.h"

shared_ptr<WebSocket> WebSocket::m_instance(new WebSocket());
WebSocket::WebSocket(): HttpServer()
{
    hlog_disable();
    m_http.GET("/ping", [](const HttpContextPtr& ctx) {
        return ctx->send("pong");
    });
    registerHttpService(&m_http);
    m_webservice.onclose = [&](const WebSocketChannelPtr& channel) {onclose(channel);};
    m_webservice.onopen = [&](const WebSocketChannelPtr& channel, const HttpRequestPtr& req) {onopen(channel,req);};
    m_webservice.onmessage = [&](const WebSocketChannelPtr& channel, const std::string& msg) {onmessage(channel,msg);};
    setPort(9999);
    this->ws = &m_webservice;
    timerID = INVALID_TIMER_ID;
    start();
}

void WebSocket::onclose(const WebSocketChannelPtr& channel)
{
    CrLogI("onclose = %s", channel->peeraddr().c_str());
    auto ctx = channel->getContextPtr<DataParser>();
    int channelId = ctx->getId();
    m_mapmutex.lock();
    m_webSocketMap.erase(channelId);
    m_mapmutex.unlock();
    if(m_webSocketMap.size()==0)
        RemovePropTimer();
    channel->deleteContextPtr();
}

void WebSocket::onopen(const WebSocketChannelPtr& channel, const HttpRequestPtr& req)
{
    CrLogI("onopen: %s socknum %d\n", req->Path().c_str(),m_webSocketMap.size());
    auto ctx = channel->newContextPtr<DataParser>();
    int channelId = ctx->createId();
    ctx->setChannel(channel);
    m_mapmutex.lock();
    m_webSocketMap[channelId] = channel;
    m_mapmutex.unlock();
    // send(time) every 1s
    AddPropTimer();
    string ret = AttributeProc::getInstance()->detectAllAttr();
    if(ret.size())
        channel->send(ret);
}

void WebSocket::onmessage(const WebSocketChannelPtr& channel, const std::string& msg)
{
    CrLogI("onmessage addr = %s msg:%s", channel->peeraddr().c_str(),msg.c_str());
    auto ctx = channel->getContextPtr<DataParser>();
    ctx->handleMessage(msg, channel->opcode);
    //channel->send("ok");
}

void WebSocket::sendToAllSocket(std::string &message)
{
    //CrLogI("send socketnum = %d msg:%s",m_webSocketMap.size() ,message.c_str());
    std::map<int, WebSocketChannelPtr>::iterator it;
    m_mapmutex.lock();
    for(it=m_webSocketMap.begin();it!=m_webSocketMap.end();++it){
        it->second->send(message);
    } 
    m_mapmutex.unlock();
}

void WebSocket::sendToSocket(int socketId,std::string &message)
{
    m_mapmutex.lock();
    auto sckt = m_webSocketMap.find(socketId);
    if(sckt != m_webSocketMap.end())
    {
        sckt->second->send(message);
    }
    m_mapmutex.unlock();
}

void WebSocket::AddPropTimer()
{
    if(timerID == INVALID_TIMER_ID)
    {
        timerID = setInterval(1000, [&](TimerID id) {   
            TimerProc();
        });
    }
}

void WebSocket::RemovePropTimer()
{
    if (timerID != INVALID_TIMER_ID) {
        killTimer(timerID);
        timerID = INVALID_TIMER_ID;
    }
}

void WebSocket::TimerProc()
{
    string ret = AttributeProc::getInstance()->detectTimeoutAttr();
    if(ret.size())
        sendToAllSocket(ret);
}