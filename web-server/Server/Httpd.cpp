/**
 * @ Author: Rui Xiong
 * @ Create Time: 2022-11-10 14:05:01
 * @ Modified by: Rui Xiong
 * @ Modified time: 2023-03-17 16:51:13
 * @ Description:
 */

#include "Httpd.h"
#include "../Base/WebMsgBase.h"
Httpd::Httpd(){
    
}

Httpd::~Httpd(){
    
}

// short options
static const char options[] = "hvc:ts:dp:";
// long options
static const option_t long_options[] = {
    {'h', "help",       NO_ARGUMENT},
    {'v', "version",    NO_ARGUMENT},
    {'c', "confile",    REQUIRED_ARGUMENT},
    {'t', "test",       NO_ARGUMENT},
    {'s', "signal",     REQUIRED_ARGUMENT},
    {'d', "daemon",     NO_ARGUMENT},
    {'p', "port",       REQUIRED_ARGUMENT}
};
static const char detail_options[] = R"(
  -h|--help                 Print this information
  -v|--version              Print version
  -c|--confile <confile>    Set configure file, default etc/{program}.conf
  -t|--test                 Test configure file and exit
  -s|--signal <signal>      Send <signal> to process,
                            <signal>=[start,stop,restart,status,reload]
  -d|--daemon               Daemonize
  -p|--port <port>          Set listen port
)";

int Httpd::ParseConfile(const char* confile) {
    IniParser ini;
    int ret = ini.LoadFromFile(confile);
    if (ret != 0) {
        CrLogE("Load confile [%s] failed: %d\n", confile, ret);
        exit(-40);
    }

    // logfile
    std::string str = ini.GetValue("logfile");
    if (!str.empty()) {
        strncpy(g_main_ctx.logfile, str.c_str(), sizeof(g_main_ctx.logfile));
    }
    hlog_set_file(g_main_ctx.logfile);
    // loglevel
    str = ini.GetValue("loglevel");
    if (!str.empty()) {
        hlog_set_level_by_str(str.c_str());
    }
    // log_filesize
    str = ini.GetValue("log_filesize");
    if (!str.empty()) {
        hlog_set_max_filesize_by_str(str.c_str());
    }
    // log_remain_days
    str = ini.GetValue("log_remain_days");
    if (!str.empty()) {
        hlog_set_remain_days(atoi(str.c_str()));
    }
    // log_fsync
    str = ini.GetValue("log_fsync");
    if (!str.empty()) {
        logger_enable_fsync(hlog, hv_getboolean(str.c_str()));
    }
    hlogi("%s version: %s", g_main_ctx.program_name, hv_compile_version());
    hlog_fsync();

    // worker_processes
    int worker_processes = 0;
// #ifdef DEBUG
//     // Disable multi-processes mode for debugging
//     worker_processes = 0;
// #else
//     str = ini.GetValue("worker_processes");
//     if (str.size() != 0) {
//         if (strcmp(str.c_str(), "auto") == 0) {
//             worker_processes = get_ncpu();
//             hlogd("worker_processes=ncpu=%d", worker_processes);
//         }
//         else {
//             worker_processes = atoi(str.c_str());
//         }
//     }
// #endif
    m_http_server.worker_processes = LIMIT(0, worker_processes, MAXNUM_WORKER_PROCESSES);
    // worker_threads
    int worker_threads = 0;
    str = ini.GetValue("worker_threads");
    if (str.size() != 0) {
        if (strcmp(str.c_str(), "auto") == 0) {
            worker_threads = get_ncpu();
            hlogd("worker_threads=ncpu=%d", worker_threads);
        }
        else {
            worker_threads = atoi(str.c_str());
        }
    }
    m_http_server.worker_threads = LIMIT(0, worker_threads, 64);

    // worker_connections
    str = ini.GetValue("worker_connections");
    if (str.size() != 0) {
        m_http_server.worker_connections = atoi(str.c_str());
    }

    // http_port
    int port = 0;
    const char* szPort = get_arg("p");
    if (szPort) {
        port = atoi(szPort);
    }
    if (port == 0) {
        port = ini.Get<int>("port");
    }
    if (port == 0) {
        port = ini.Get<int>("http_port");
    }
    m_http_server.port = port;
    // https_port
    if (HV_WITH_SSL) {
        m_http_server.https_port = ini.Get<int>("https_port");
    }
    if (m_http_server.port == 0 && m_http_server.https_port == 0) {
        CrLogE("Please config listen port!\n");
        exit(-10);
    }

    // base_url
    str = ini.GetValue("base_url");
    if (str.size() != 0) {
        m_http_service.base_url = str;
    }
    //document_root
    // str = ini.GetValue("document_root");
    // if (str.size() != 0) {
    //     m_http_service.document_root = str;
    // }
    char rootPath[DEF_PATH_LEN] = {0};
    snprintf(rootPath, DEF_PATH_LEN, "%s/%s",GetUserDataPath(), USER_DATA_CREALITY_DIR);
    CrLogI("%s", rootPath);
    m_http_service.document_root = rootPath;
    // home_page
    str = ini.GetValue("home_page");
    if (str.size() != 0) {
        m_http_service.home_page = str;
    }
    // error_page
    str = ini.GetValue("error_page");
    if (str.size() != 0) {
        m_http_service.error_page = str;
    }
    // index_of
    // str = ini.GetValue("index_of");
    // if (str.size() != 0) {
    //     m_http_service.index_of = str;
    // }
    char logPath[DEF_PATH_LEN] = {0};
    snprintf(logPath, DEF_PATH_LEN, "/%s", USER_DELAY_IMAGE_DIR);
    m_http_service.index_of = logPath;
    // limit_rate
    str = ini.GetValue("limit_rate");
    if (str.size() != 0) {
        m_http_service.limit_rate = atoi(str.c_str());
    }
    // ssl
    if (m_http_server.https_port > 0) {
        std::string crt_file = ini.GetValue("ssl_certificate");
        std::string key_file = ini.GetValue("ssl_privatekey");
        std::string ca_file = ini.GetValue("ssl_ca_certificate");
        hlogi("SSL backend is %s", hssl_backend());
        hssl_ctx_init_param_t param;
        memset(&param, 0, sizeof(param));
        param.crt_file = crt_file.c_str();
        param.key_file = key_file.c_str();
        param.ca_file = ca_file.c_str();
        param.endpoint = HSSL_SERVER;
        if (hssl_ctx_init(&param) == NULL) {
            hloge("SSL certificate verify failed!");
            exit(0);
        }
        else {
            hlogi("SSL certificate verify ok!");
        }
    }

    hlogi("parse_confile('%s') OK", confile);
    return 0;
}

int Httpd::Initialization() {
    // logfile
    hlog_set_file(g_main_ctx.logfile);
    // loglevel
    hlog_set_level_by_str("SILENT");
    // log_filesize
    hlog_set_max_filesize_by_str("64M");
    // log_remain_days
    hlog_set_remain_days(3);
    // log_fsync
    hlogi("%s version: %s", g_main_ctx.program_name, hv_compile_version());
    hlog_fsync();
    // worker_processes
    int worker_processes = 0;
    m_http_server.worker_processes = LIMIT(0, worker_processes, MAXNUM_WORKER_PROCESSES);
    // worker_threads
    int worker_threads = 0;
    m_http_server.worker_threads = LIMIT(0, worker_threads, 64);
    // worker_connections
    m_http_server.worker_connections = 1024;
    // https_port
    CrLogI("HV_WITH_SSL :%d\n",HV_WITH_SSL);
    if (HV_WITH_SSL) {
        m_http_server.https_port = DEFAULT_HTTPS_PORT;
    }
    // http_port
    else {
        m_http_server.port = DEFAULT_HTTP_PORT;
    }
    if (m_http_server.port == 0 && m_http_server.https_port == 0) {
        CrLogW("Please config listen port!\n");
        exit(-10);
    }
    // base_url
    // str = ini.GetValue("base_url");
    // if (str.size() != 0) {
    //     m_http_service.base_url = str;
    // }
    //document_root
    char rootPath[DEF_PATH_LEN] = {0};
    snprintf(rootPath, DEF_PATH_LEN, "%s", USER_SHARE_FRONTEND_DIR);
    CrLogI("%s", rootPath);
    m_http_service.document_root = rootPath;
    // home_page
    m_http_service.home_page = "index.html";
    // error_page
    // str = ini.GetValue("error_page");
    // if (str.size() != 0) {
    //     m_http_service.error_page = str;
    // }
    // index_of
    char downPath[DEF_PATH_LEN] = {0};
    snprintf(downPath, DEF_PATH_LEN, "%s", FRONTEND_DOWNLOADS_DIR);
    m_http_service.index_of = downPath;
    // limit_rate
    //m_http_service.limit_rate = 500;
    // ssl
    if (m_http_server.https_port > 0) {
        hlogi("SSL backend is %s", hssl_backend());
        hssl_ctx_init_param_t param;
        memset(&param, 0, sizeof(param));
        param.crt_file = GetHttpCrtFile(); 
        param.key_file = GetHttpKeyFile();
        param.ca_file = GetHttpPemFile();
        param.endpoint = HSSL_SERVER;
        //printf("param.crt_file :%s\n",param.crt_file);
        //printf("param.ca_file :%s\n",param.ca_file);
        //printf("param.key_file :%s\n",param.key_file);
        if (hssl_ctx_init(&param) == NULL) {
            hloge("SSL certificate verify failed!");
            exit(0);
        }
        else {
            hlogi("SSL certificate verify ok!");
        }
    }

    // hlogi("parse_confile('%s') OK", confile);
    return 0;
}

void Httpd::Start(){
    //ParseConfile(g_main_ctx.confile);
    hlog_disable();
    //ParseConfile("etc/httpd.conf");
    //ParseConfile(GetUserHttpdConfigFilePath());
    Initialization();
    Router::Register(m_http_service);
    m_http_server.registerHttpService(&m_http_service);
    m_http_server.run(1);
}
