/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-05-06 22:16:45
 * @LastEditTime: 2023-10-11 10:00:24
 */

#ifndef __CXY_MQTT_SERVER_H__
#define __CXY_MQTT_SERVER_H__

#include <functional>
#include <thread>
#include <atomic>
#include "MQTTAsync.h"
#include "MQTTClientPersistence.h"
#include "CxyHttpServer.h"
#include <mutex>
#include <condition_variable>

struct pubsub_opts
{
	/* debug app options */
	int publisher;  /* publisher app? */
	int quiet;
	int verbose;
	int tracelevel;
	char* delimiter;
	int maxdatalen;
	/* message options */
	char* message;
	char* filename;
	int stdin_lines;
	int stdlin_complete;
	int null_message;
	/* MQTT options */
	int MQTTVersion;
	char* topic;
	char* clientid;
	int qos;
	int retained;
	char* username;
	char* password;
	char* host;
	char* port;
	char* connection;
	int keepalive;
	/* will options */
	char* will_topic;
	char* will_payload;
	int will_qos;
	int will_retain;
	/* TLS options */
	int insecure;
	char* capath;
	char* cert;
	char* cafile;
	char* key;
	char* keypass;
	char* ciphers;
	char* psk_identity;
	char* psk;
	/* MQTT V5 options */
	int message_expiry;
	struct {
		char *name;
		char *value;
	} user_property;
	/* websocket HTTP proxies */
	char* http_proxy;
	char* https_proxy;
};

class CxyMqttServer
{
    public:
        CxyMqttServer();
        ~CxyMqttServer();
        
        void RegisterRecvJsonCb(std::function<int(std::string)> callback);
        void RegisterConStateCb(std::function<int(int)> callback);
        void Start(int setting);
        void Stop();
        int SendTelemetry(std::string data);
        int SendAttributes(std::string data);
        int ResponseRpc(std::string data);

    private:
        static void logProperties(MQTTProperties *props);
        static void onSubscribe(void *context, MQTTAsync_successData *respinse);
        static void onSubscribeFailure(void *context, MQTTAsync_failureData *respinse);
        static void onSubscribe_1(void *context, MQTTAsync_successData *respinse);
        static void onSubscribeFailure_1(void *context, MQTTAsync_failureData *respinse);
        static void conn_lost(void *context, char *cause);
        static void onConnect(void* context, MQTTAsync_successData* response);
        static void onConnectFailure(void* context, MQTTAsync_failureData* response);
        static void onDisconnect(void* context, MQTTAsync_successData* response);
        static void onDisconnectFailure(void* context, MQTTAsync_failureData* response);
        static int msg_rcv_process(void *context, char *topicName, int topicLen, MQTTAsync_message *message);

        std::string GetCxyServerUrlFromConfigFile(void);
        
        int UserMqttSend(char  *topic, int datalen, char* data);
        int SubscribeTopics(MQTTAsync &client);
        int unSubscribeTopics(MQTTAsync &client);
        int MqttThread();
        int HttpRegistor();
        int HttpGetTbInfo();
        int CreateMqtt();
        int ConnectMqtt();
        int ExitMqtt();
        int WaitCond();
        void NotifyOne();
    private:
        std::function<int(int)>             m_conStateCb;
        std::function<int(std::string)>     m_recvDataCb;
        bool                m_thRun;

        MQTTAsync           m_mqttClient;
        int                 m_rcpRequestNum;
        int                 m_mqttStatus;
        std::thread         m_serverThread;
		CxyHttpServer       m_cxyHttpServer;
        std::atomic<int>    m_thStatus;
        int                 m_setting;
        DeviceTbInfo_t      m_tbInfo;
        CxyServer_t         m_server;
        std::mutex              m_condMutex;
        std::condition_variable m_thCond;
        int                 m_waitSecond;
        bool                m_tokenErr;
        bool                m_isReady;
};

#endif
