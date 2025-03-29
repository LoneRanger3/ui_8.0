/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-08-21 13:33:12
 * @LastEditTime: 2023-09-12 12:01:04
 */
#include "DataParser.h"
#include "CommondProc.h"
#include "json-c/linkhash.h"

atomic<int> DataParser::nowtic(0);

int DataParser::parseCmd(int type,const std::string& key,json_object *val)
{
    string ret;
    if(type == 0)
        ret = CommondProc::getInstance()->GetCmdProc(m_channelId,key,val);
    else
        ret = CommondProc::getInstance()->SetCmdProc(m_channelId,key,val);
    return procResp(type,ret);
}

int DataParser::procResp(int type,const std::string& resp)
{
    if(resp.size() == 0)
    {
        //no resp
    }
    else if(resp == "-1")
    {
        //resp err
    }
    else{
        CrLogI("procResp send m_channelId = %d,resp %s \n", m_channelId,resp.c_str());
        m_channel->send(resp);
    }
}

int DataParser::parseMessage(const std::string& msg)
{
    json_object *req = json_tokener_parse(msg.c_str());
    if (req == NULL || !json_object_is_type(req, json_type_object))
    {
        if (req) json_object_put(req);
        return -1;
    }
    json_object *modecode = json_object_object_get(req, "ModeCode");
    if (modecode != NULL && json_object_is_type(modecode, json_type_string)){
        if (req) json_object_put(req);
        m_channel->send("ok");
        return 0;
    }
    json_object *method = json_object_object_get(req, "method");
    json_object *params = json_object_object_get(req, "params");

    if (method != NULL && json_object_is_type(method, json_type_string) && json_object_get_string(method) &&
        params != NULL && json_object_is_type(params, json_type_object))
    {
        if(!strcmp(json_object_get_string(method), "set")){
            json_object *opgcode = nullptr;
            json_object_object_foreach(params,key,val)
            {
                if(string(key) == "opGcodeFile") opgcode = val;
                else
                    parseCmd(1,key,val);
            }
            if(opgcode)
                parseCmd(1,"opGcodeFile",opgcode);
		}
		else if(!strcmp(json_object_get_string(method), "get")){
            json_object_object_foreach(params,key,val)
            {
                parseCmd(0,key,val);
            }
		}
    }
	else{
		CrLogE("ignore:%s \n",msg.c_str());
	}
    json_object_put(req);

	return 0;
}

int DataParser::handleMessage(const std::string& msg, enum ws_opcode opcode) {
    //CrLogI("handleMessage opcode = %d,msg %s \n", opcode,msg.c_str());
    parseMessage(msg);
    return msg.size();
}
