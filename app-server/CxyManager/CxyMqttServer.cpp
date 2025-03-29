/*
 * @Description : mqtt服务
 * @Author      : Yufeng Zhang
 * @Date: 2022-05-06 22:16:45
 * @LastEditTime: 2023-10-11 10:01:39
 */
#include <iostream>
#include <thread>
#include "MQTTAsync.h"

#include "Base/AppMsgBase.h"
#include "CxyMqttServer.h"


/************** define status ***************/
#define CONNECT_OK                  (1 << 0)
#define SUB_ATTRIBUTES_TOPIC        (1 << 1)
#define SUB_RPC_TOPIC               (1 << 2)
#define DIS_CONNECT_OVER            (1 << 3)

struct pubsub_opts opts = {
	0, 0, 1, CR_LOG_INFO, (char*)"\n", 100,  	/* debug/app options */
	NULL, NULL, 1, 0, 0, /* message options */
	MQTTVERSION_DEFAULT, (char*)"v1/devices/me/attributes", (char*)"paho-c-sub", 0, 0, NULL, NULL, NULL/*"localhost""47.114.48.45"*/, (char*)"NULL" /*"1883"*/, NULL, 30, /* MQTT options */
	NULL, NULL, 0, 0, /* will options */
	0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, /* TLS options */
	0, {NULL, NULL}, /* MQTT V5 options */
	NULL, NULL, /* HTTP and HTTPS proxies */
};

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {* args} *
 */
CxyMqttServer::CxyMqttServer():m_thStatus(0)
{
    m_mqttStatus = 0;
    m_rcpRequestNum = 0;
    m_thRun = true;
    m_tokenErr = false;
    m_thStatus = MQTT_THRUN_NUM;
    m_isReady = false;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
CxyMqttServer::~CxyMqttServer()
{
    Stop();
}

/**
 * @description: 
 * @return {*}
 * @param {MQTTProperties} *props
 */
void CxyMqttServer::logProperties(MQTTProperties *props)
{
	for (int i = 0; i < props->count; ++i)
	{
		int id = props->array[i].identifier;
		const char* name = MQTTPropertyName((MQTTPropertyCodes)id);
		switch (MQTTProperty_getType((MQTTPropertyCodes)id))
		{
		    case MQTTPROPERTY_TYPE_BYTE:
		        CrLogI("Property name %s value %d", name, props->array[i].value.byte);
		        break;
		    case MQTTPROPERTY_TYPE_TWO_BYTE_INTEGER:
                CrLogI("Property name %s value %d\n", name, props->array[i].value.integer2);
                break;
		    case MQTTPROPERTY_TYPE_FOUR_BYTE_INTEGER:
                CrLogI("Property name %s value %d\n", name, props->array[i].value.integer4);
                break;
		    case MQTTPROPERTY_TYPE_VARIABLE_BYTE_INTEGER:
                CrLogI("Property name %s value %d\n", name, props->array[i].value.integer4);
                break;
            case MQTTPROPERTY_TYPE_BINARY_DATA:
            case MQTTPROPERTY_TYPE_UTF_8_ENCODED_STRING:
                CrLogI("Property name %s value len %.*s\n", name,
                        props->array[i].value.data.len, props->array[i].value.data.data);
		        break;
            case MQTTPROPERTY_TYPE_UTF_8_STRING_PAIR:
                CrLogI("Property name %s key %.*s value %.*s\n", name,
                    props->array[i].value.data.len, props->array[i].value.data.data,
                    props->array[i].value.value.len, props->array[i].value.value.data);
                break;
		}
	}
}

/**
 * @description: 
 * @return {*}
 * @param {void} *context
 * @param {MQTTAsync_successData} *respinse
 */
void CxyMqttServer::onSubscribe(void *context, MQTTAsync_successData *respinse)
{
    CrLogI("subscribe SUB_ATTRIBUTES_TOPIC success!");
    CxyMqttServer* client = static_cast<CxyMqttServer*>(context);
    client->m_mqttStatus |= SUB_ATTRIBUTES_TOPIC;
    if((client->m_mqttStatus & (SUB_ATTRIBUTES_TOPIC | SUB_RPC_TOPIC)) == (SUB_ATTRIBUTES_TOPIC | SUB_RPC_TOPIC))
    {
        client->m_thStatus = MQTT_THRUN_OK;
        client->NotifyOne();
    }
}

/**
 * @description: 
 * @return {*}
 * @param {void} *context
 * @param {MQTTAsync_failureData} *respinse
 */
void CxyMqttServer::onSubscribeFailure(void *context, MQTTAsync_failureData *respinse)
{
    CrLogI("subscribe SUB_ATTRIBUTES_TOPIC failed!");
    CxyMqttServer* client = static_cast<CxyMqttServer*>(context);
    client->m_mqttStatus &= (~SUB_ATTRIBUTES_TOPIC);
    client->m_thStatus = MQTT_THRUN_SUB;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *context
 * @param {MQTTAsync_successData} *respinse
 */
void CxyMqttServer::onSubscribe_1(void *context, MQTTAsync_successData *respinse)
{
    CrLogI("subscribe SUB_RPC_TOPIC success!");
    CxyMqttServer* client = static_cast<CxyMqttServer*>(context);
    client->m_mqttStatus |= SUB_RPC_TOPIC;
    if((client->m_mqttStatus & (SUB_ATTRIBUTES_TOPIC | SUB_RPC_TOPIC)) == (SUB_ATTRIBUTES_TOPIC | SUB_RPC_TOPIC))
    {
        client->m_thStatus = MQTT_THRUN_OK;
        client->NotifyOne();
    }    
}

/**
 * @description: 
 * @return {*}
 * @param {void} *context
 * @param {MQTTAsync_failureData} *respinse
 */
void CxyMqttServer::onSubscribeFailure_1(void *context, MQTTAsync_failureData *respinse)
{
    CrLogI("subscribe SUB_RPC_TOPIC failed!");
    CxyMqttServer* client = static_cast<CxyMqttServer*>(context);
    client->m_mqttStatus &= (~SUB_RPC_TOPIC); 
    client->m_thStatus = MQTT_THRUN_SUB;
}

/**
 * @description: 
 * @return {*}
 * @param {void} *context
 * @param {char} *cause
 */
void CxyMqttServer::conn_lost(void *context, char *cause)
{
	CrLogI("mqtt connect lost, it will re-connect!");
    CxyMqttServer* client = static_cast<CxyMqttServer*>(context);
    client->m_mqttStatus &= (~SUB_RPC_TOPIC);   
    client->m_mqttStatus &= (~SUB_ATTRIBUTES_TOPIC);  
    //client->m_mqttStatus &= (~CONNECT_OK);
    client->m_thStatus = MQTT_THRUN_CONNECT;
    client->NotifyOne();
}

/**
 * @description: 
 * @return {*}
 * @param {void*} context
 * @param {MQTTAsync_successData*} response
 */
void CxyMqttServer::onConnect(void* context, MQTTAsync_successData* response)
{
	CrLogI("mqtt connect server success!\n");
    CxyMqttServer* client = static_cast<CxyMqttServer*>(context);
	//client->m_mqttStatus |= CONNECT_OK;      //< connect ok
    client->m_thStatus = MQTT_THRUN_SUB;
    client->NotifyOne();
}

/**
 * @description: 
 * @return {*}
 * @param {void*} context
 * @param {MQTTAsync_failureData*} response
 */
void CxyMqttServer::onConnectFailure(void* context, MQTTAsync_failureData* response)
{
	CrLogE( "Connect failed, rc %s\n", response ? MQTTAsync_strerror(response->code) : "none");
    CrLogE( "Connect failed, message %s\n", response ? response->message : "none");
    CxyMqttServer* client = static_cast<CxyMqttServer*>(context);
    //client->m_mqttStatus &= (~CONNECT_OK);
    client->m_thStatus = MQTT_THRUN_CONNECT;
}

/**
 * @description: 
 * @return {*}
 * @param {void*} context
 * @param {MQTTAsync_successData*} response
 */
void CxyMqttServer::onDisconnect(void* context, MQTTAsync_successData* response)
{
    CxyMqttServer* client = static_cast<CxyMqttServer*>(context);
    client->m_mqttStatus &= (~SUB_RPC_TOPIC);   
    client->m_mqttStatus &= (~SUB_ATTRIBUTES_TOPIC);  
	//client->m_mqttStatus &= (~CONNECT_OK); 	//< disconnect ok
    //client->m_mqttStatus  |= DIS_CONNECT_OVER;
    client->m_thRun = false;
    client->m_thStatus = MQTT_THRUN_EXIT;
    client->NotifyOne();
    CrLogI("onDisconnect m_mqttStatus %d ",client->m_mqttStatus&DIS_CONNECT_OVER);
}

/**
 * @description: 
 * @return {*}
 * @param {void*} context
 * @param {MQTTAsync_failureData*} response
 */
void CxyMqttServer::onDisconnectFailure(void* context, MQTTAsync_failureData* response)
{
    CxyMqttServer* client = static_cast<CxyMqttServer*>(context);
    //client->m_mqttStatus  |= DIS_CONNECT_OVER;
    client->m_thRun = false;
    client->m_thStatus = MQTT_THRUN_EXIT;
    client->NotifyOne();
	CrLogE("Disconnect failed, rc %d  m_mqttStatus %d\n", response->code,client->m_mqttStatus&DIS_CONNECT_OVER);
}

/**
 * @description: 
 * @return {*}
 * @param {void} *context
 * @param {char} *topicName
 * @param {int} topicLen
 * @param {MQTTAsync_message} *message
 */
int CxyMqttServer::msg_rcv_process(void *context, char *topicName, int topicLen, MQTTAsync_message *message)
{
    CxyMqttServer* client = static_cast<CxyMqttServer*>(context);
	size_t delimlen = 0;

	if (opts.verbose)
		CrLogD("len = %d, topic = %s\t", message->payloadlen, topicName);
	if (opts.delimiter)
		delimlen = strlen(opts.delimiter);
	if (opts.delimiter == NULL || ((unsigned int)message->payloadlen > delimlen &&
		strncmp(opts.delimiter, &((char*)message->payload)[message->payloadlen - delimlen], delimlen) == 0))
		CrLogD("%.*s", message->payloadlen, (char*)message->payload);
	else
		CrLogD("%.*s%s", message->payloadlen, (char*)message->payload, opts.delimiter);

	if (message->struct_version == 1 && opts.verbose)
		logProperties(&message->properties);
	fflush(stdout);
    
    // 提取json字符串内容，防止乱码
    char mqttRecv[message->payloadlen + 10];
    bzero(mqttRecv, sizeof(mqttRecv));
    memcpy(mqttRecv, (const char*)message->payload, message->payloadlen);
    
	if(topicName){
		char *p = strstr(topicName, "request/");
		if(p) {
			client->m_rcpRequestNum = atoi(p + strlen("request/"));
            client->m_recvDataCb(mqttRecv);
		}
	}
	MQTTAsync_freeMessage(&message);
	MQTTAsync_free(topicName);
	return 1;
}

/**
 * @description: 订阅属性回复、RPC请求的topic
 * @param  {*}
 * @return {*}
 * @param {MQTTAsync} &client
 */
int CxyMqttServer::SubscribeTopics(MQTTAsync &client)
{
	int ret = 0, rc = -1;
	MQTTAsync_responseOptions ropts = MQTTAsync_responseOptions_initializer;
	
	CrLogD("Subscribing to topic %s with client %s at QoS %d\n", opts.topic, opts.clientid, opts.qos);
	ropts.onSuccess = &CxyMqttServer::onSubscribe;
	ropts.onFailure = &CxyMqttServer::onSubscribeFailure;
	ropts.context = this;

	if ((rc = MQTTAsync_subscribe(client, "v1/devices/me/attributes/response/+", opts.qos, &ropts)) != MQTTASYNC_SUCCESS) {
		CrLogE( "Failed to start subscribe, return code %s\n", MQTTAsync_strerror(rc));
		ret = -1;
	}

	ropts.onSuccess = &CxyMqttServer::onSubscribe_1;
	ropts.onFailure = &CxyMqttServer::onSubscribeFailure_1;
	if ((rc = MQTTAsync_subscribe(client, "v1/devices/me/rpc/request/+", opts.qos, &ropts)) != MQTTASYNC_SUCCESS) {
		CrLogE( "Failed to start subscribe rpc, return code %s\n", MQTTAsync_strerror(rc));
		ret = -1;
	}
	
	return ret;
}

int CxyMqttServer::unSubscribeTopics(MQTTAsync &client)
{
	int ret = 0, rc = -1;
	MQTTAsync_responseOptions ropts = MQTTAsync_responseOptions_initializer;
	
	CrLogD("unSubscribing to topic %s with client %s at QoS %d\n", opts.topic, opts.clientid, opts.qos);
	ropts.onSuccess = &CxyMqttServer::onSubscribe;
	ropts.onFailure = &CxyMqttServer::onSubscribeFailure;
	ropts.context = this;

	if ((rc = MQTTAsync_unsubscribe(client, "v1/devices/me/attributes/response/+", NULL)) != MQTTASYNC_SUCCESS) {
		CrLogE( "Failed to start unsubscribe, return code %s\n", MQTTAsync_strerror(rc));
		ret = -1;
	}

	ropts.onSuccess = &CxyMqttServer::onSubscribe_1;
	ropts.onFailure = &CxyMqttServer::onSubscribeFailure_1;
	if ((rc = MQTTAsync_unsubscribe(client, "v1/devices/me/rpc/request/+", NULL)) != MQTTASYNC_SUCCESS) {
		CrLogE( "Failed to start unsubscribe rpc, return code %s\n", MQTTAsync_strerror(rc));
		ret = -1;
	}
	
	return ret;
}

int CxyMqttServer::HttpRegistor()
{
    int rc;
    // 获取创想云服务器地址
    std::string remoteUrl = m_server.url;

    CrLogD("url = %s", remoteUrl.c_str());
    if (remoteUrl.length() < 2) {
        CrLogE("get cxy remote url fail\n\n\n");
        return -1;
    }
    
    // 初始化 HTTP pai接口
    rc = m_cxyHttpServer.CxyHttpApiInit(remoteUrl, "register_dev");
    if (rc != 0) {
        CrLogE("cxy http api init fail\n\n\n");
        return -1;
    }
    return 0;
}

int CxyMqttServer::HttpGetTbInfo()
{
    if(m_tokenErr){
        CrLogE("token length <2\n");
        return -3;
    }

    RegisterInfo_t devInfo;
    if (m_cxyHttpServer.GetRegisterInfoFromFile(&devInfo) != 0) {
        CrLogE("get device sn or mac fail\n\n\n");
        return -1;
    }
    
    // 注册设备
    if (m_cxyHttpServer.GetConnectTbInfo(devInfo, &m_tbInfo) == -1) {
        CrLogW("No TB information is obtained, try again after a delay of 20 second\n");
        return -2;
    }
    
    // http请求成功，判断是否获取tb信息
    if (m_tbInfo.token.length() > 2 && m_tbInfo.devName.length() > 2)
        return 0;
    m_tokenErr = true;
    CrLogE("%s\n", m_tbInfo.httpRes.c_str());
    return -3;
}

int CxyMqttServer::CreateMqtt()
{
    int rc;
    m_server = m_cxyHttpServer.GetCxyServer(m_setting);
    /*! 获取远端tb服务器URL */
    std::string tb_server_url = m_server.iot;
	CrLogI("start mqtt for iot tb ...\n");
    if (tb_server_url.length() < 2) {
        CrLogE("get tb server url fail\n\n\n");
        return -1;
    }
    
    /*! create mqtt */
	if ((rc = MQTTAsync_create(&m_mqttClient, tb_server_url.c_str(), opts.clientid, MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTASYNC_SUCCESS) {
		CrLogD("Failed to create client, return code %d\n", rc);
		rc = EXIT_FAILURE;
		return rc;
	}

	/*! set callback function */
	if ((rc = MQTTAsync_setCallbacks(m_mqttClient, this, &CxyMqttServer::conn_lost, &CxyMqttServer::msg_rcv_process, NULL)) != MQTTASYNC_SUCCESS) {
		CrLogD("Failed to set callbacks, return code %d\n", rc);
		rc = EXIT_FAILURE;
		return rc;
	}

    return 0;
}

int CxyMqttServer::ConnectMqtt()
{
    int rc;
	/*! connect server config */
    MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
	conn_opts.keepAliveInterval = 30;
	conn_opts.cleansession = false;
	conn_opts.onSuccess = &CxyMqttServer::onConnect;
	conn_opts.onFailure = &CxyMqttServer::onConnectFailure;
	conn_opts.context = this;
	conn_opts.username = m_tbInfo.token.c_str(); 		//< is very important, will get in while(true)
	conn_opts.connectTimeout = 3;

    CrLogI("MQTTAsync_connect start!\n");
    if ((rc = MQTTAsync_connect(m_mqttClient, &conn_opts)) != MQTTASYNC_SUCCESS) {
        CrLogE("Failed to start connect, return code %d, will try again!\n", rc);
    }
    return rc;
}

int CxyMqttServer::ExitMqtt()
{
    int rc;
    CrLogI("mqtt client while exit!");
    unSubscribeTopics(m_mqttClient);
	/*! disconnect */
    MQTTAsync_disconnectOptions disc_opts = MQTTAsync_disconnectOptions_initializer;
	disc_opts.onSuccess = &CxyMqttServer::onDisconnect;
	disc_opts.onFailure = &CxyMqttServer::onDisconnectFailure;
    disc_opts.context = this;
	if ((rc = MQTTAsync_disconnect(m_mqttClient, &disc_opts)) != MQTTASYNC_SUCCESS) {
		CrLogE("Failed to start disconnect, return code %d\n", rc);
        rc = EXIT_FAILURE;
		return rc;
	}
    return 0;
}

int CxyMqttServer::WaitCond()
{
    std::unique_lock<std::mutex> lock(m_condMutex);
    m_thCond.wait_for(lock,std::chrono::seconds(m_waitSecond),[this]{return m_isReady;});
    return 0;
}

void CxyMqttServer::NotifyOne()
{
    std::unique_lock<std::mutex> lock(m_condMutex);
    m_isReady = true;
    m_thCond.notify_one();
}

int CxyMqttServer::MqttThread()
{
    if(0 != CreateMqtt())
    {
        CrLogI("CreateMqtt fail!!!");
        return -1;
    }
    while(m_thRun)
    {
        WaitCond();
        //CrLogI("MqttThread m_thStatus %d ",m_thStatus.load());
        m_isReady = false;
        switch(m_thStatus.load())
        {
            case MQTT_THRUN_REGISTOR:
                m_waitSecond = 5;
                if(0 == HttpRegistor())
                {
                    m_thStatus = MQTT_THRUN_GETTBINFO;
                    m_isReady = true;
                }
            break;
            case MQTT_THRUN_GETTBINFO:
                m_waitSecond = 10;
                if(0 == HttpGetTbInfo())
                {
                    m_thStatus = MQTT_THRUN_CONNECT;
                    m_isReady = true;
                }
            break;
            case MQTT_THRUN_CONNECT:
                m_waitSecond = 5;
                ConnectMqtt();
            break;
            case MQTT_THRUN_SUB:
                m_waitSecond = 5;
                SubscribeTopics(m_mqttClient);
            break;
            case MQTT_THRUN_OK:
                m_waitSecond = 30;
            break;
            case MQTT_THRUN_EXIT:
                CrLogI("MQTT_THRUN_EXIT");
            break;
            default:
                CrLogI("#######default");
            break;
        }
        m_conStateCb(m_thStatus.load());
    }
    MQTTAsync_destroy(&m_mqttClient);
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
void CxyMqttServer::RegisterRecvJsonCb(std::function<int(std::string)> callback)
{
    m_recvDataCb = callback;
}

/**
 * @description: 
 * @return {*}
 * @param undefined
 */
void CxyMqttServer::RegisterConStateCb(std::function<int(int)> callback)
{
    m_conStateCb = callback;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
void CxyMqttServer::Start(int setting)
{ 
    if(m_thStatus == MQTT_THRUN_NUM){
        m_thStatus = MQTT_THRUN_REGISTOR;
        m_mqttStatus = 0;
        m_setting = setting;
        m_waitSecond = 1;
        m_serverThread = std::thread(&CxyMqttServer::MqttThread, this);
    }   
}

void CxyMqttServer::Stop()
{
    if(m_thStatus != MQTT_THRUN_NUM){
        if(0!=ExitMqtt()){
            m_thRun = false;
            NotifyOne();
        }
        m_mqttStatus = 0;
        // 析构时保证子线程join进来
        if (m_serverThread.joinable()) {
            m_serverThread.join();
        }
        m_thStatus = MQTT_THRUN_NUM;
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {char } *topic
 * @param {int} datalen
 * @param {char*} data
 */
int CxyMqttServer::UserMqttSend(char *topic, int datalen, char* data)
{
    if (m_thStatus.load() <= MQTT_THRUN_CONNECT )
    {
        CrLogW("send fail, mqtt no connection\n");
        return -1;
    }

    if(datalen == 0)
    {
        CrLogW("send fail, no data\n");
        return 0;
    }

	MQTTAsync_responseOptions pub_opts = MQTTAsync_responseOptions_initializer;

	int rc = MQTTAsync_send(m_mqttClient, topic, datalen, data, opts.qos, opts.retained, &pub_opts);
	if ( rc != MQTTASYNC_SUCCESS )
        CrLogE( "Error from MQTTAsync_send: %s\n", MQTTAsync_strerror(rc));
	return rc;
}

/**
 * @description: 发布遥测
 * @param  {*}
 * @return {*}
 * @param {string} data
 */
int CxyMqttServer::SendTelemetry(std::string data)
{
    CrLogD("Telemetry len: %d; data: %s", data.length(), data.c_str());

	int rc = UserMqttSend((char*)"v1/devices/me/telemetry", data.length(), (char*)data.c_str());
    if(rc != MQTTASYNC_SUCCESS) {
        CrLogE("fail, SendTelemetry: %d\n", rc);
        return -1;
    }

    CrLogI("ok, SendTelemetry: %d\n", rc);
    return 0;
}

/**
 * @description: 发布属性
 * @param  {*}
 * @return {*}
 * @param {string} data
 */
int CxyMqttServer::SendAttributes(std::string data)
{
    CrLogD("Attributes len: %d; data: %s", data.length(), data.c_str());

	int rc = UserMqttSend((char*)"v1/devices/me/attributes", data.length(), (char*)data.c_str());
    if(rc != MQTTASYNC_SUCCESS) {
        CrLogE("fail, SendAttributes: %d\n", rc);
        return -1;
    }

    CrLogI("ok, SendAttributes: %d\n", rc);
    return 0;
}

/**
 * @description: 发送RPC响应
 * @param  {*}
 * @return {*}
 * @param {string} data
 */
int CxyMqttServer::ResponseRpc(std::string data)
{
    CrLogD("Response Rpc len: %d; data: %s", data.length(), data.c_str());

    std::string mqttRestp = "v1/devices/me/rpc/response/" + std::to_string(m_rcpRequestNum);
    CrLogD("mqtt rpc request topic: %s", mqttRestp.c_str());

	int rc = UserMqttSend((char*)mqttRestp.c_str(), data.length(), (char*)data.c_str());
    if(rc != MQTTASYNC_SUCCESS) {
        CrLogE("fail, ResponseRpc: %d\n", rc);
        return -1;
    }

    CrLogI("ok, ResponseRpc: %d  respnum %d\n", rc,m_rcpRequestNum);
    return 0;
}
