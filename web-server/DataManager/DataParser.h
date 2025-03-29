/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-08-21 13:32:54
 * @LastEditTime: 2023-08-21 13:37:55
 */
#pragma once
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

class DataParser {
    public:
        DataParser() {
            m_channelId = 0;
            m_channel = nullptr;
        }
        int handleMessage(const std::string& msg, enum ws_opcode opcode);
        int createId(){
            m_channelId = nowtic++;
            return m_channelId;
        }
        void setChannel(WebSocketChannelPtr channel)
        {
            m_channel = channel;
        }
        
        int getId(){
            return m_channelId;
        }
    private:
        int parseMessage(const std::string& msg);
        int parseCmd(int type,const std::string& key,json_object *val);
        int procResp(int type,const std::string& resp);
        int     m_channelId;
        WebSocketChannelPtr m_channel;
        static atomic<int> nowtic;
};
