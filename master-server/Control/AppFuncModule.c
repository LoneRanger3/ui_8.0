/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-02-23 11:59:29
 * @LastEditTime: 2023-08-16 16:25:31
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/msg.h>
#include <errno.h>
#include <malloc.h>
#include "global/list/list.h"

#include "Base/MasterMsgBase.h"
#include "DefineGcode.h"
#include "PrintControl.h"
#include "AppPrint.h"
#include "AppFuncModule.h"
#include "Controller.h"

#include <regex.h>

#include <time.h>
#define USE_CAM_COOR //使用相机坐标系

#define LASER_Z_OFFSET   3
#define LASER_X_OFFSET   (-36)
#define LASER_Y_OFFSET   (-(16 + 7.2))

#define CALI_Z_OFFSET   1
#define CALI_X_OFFSET   7
#define CALI_Y_OFFSET   168
#define CALI_STEP2_Z_OFFSET   2

#define POINT_COUNT 24
#define LASER_LINE_WIDTH                30 // 激光线宽度单位ms
#define FIRST_LAYER_DETECT_INTERVAL     5  // 首层检测，Y轴间隔单位ms
#define FLOW_DETECT_POINT_DIR_TEMP      "/tmp/pointCloud"
#define FLOW_DETECT_GCODE_FILE_NAME     "Auto_pressure_advance_testpadvance.gcode"
#define FIRST_LAYER_SCAN_SPEED          1200  // mm/min
#define FIRST_LAYER_TIME_INTERVAL       250  // ms
#define FLOW_SCAN_TIME_INTERVAL         80 //125  // ms
#define LASER_OFFSET_AGAIN_SCAN_NUM     3  // 激光矫正，扫描点云重复次数
#define LASER_OFFSET_MOVE_SCAN_NUM      9  // 激光矫正，扫描点云移动次数
#define LASER_OFFSET_MOVE_SCAN_LEN      2  // 激光矫正，扫描点云移动长度
typedef struct {
    float start_x;
    float start_y;
    float end_x;
    float end_y;
    float interval;
    float bed_temp;
    float hotend_temp;
    int pointCount;
    float photo_start_x;
    float photo_start_y;
} AiDetectPara_t;

typedef struct {
    float confidence;
    float x_offset;
    float y_offset;
    float z_offset;
}LaserOffsetRes_t;

typedef struct {
    float start_x;
    float start_y;
    float end_y;
} LineHightPara_t;
typedef struct {
    float start_x;
    float start_y;
    float len_x;
    float len_y;
} LaserTest_t;
/**
 * @description: 
 * @return {*}
 */
static bool appFunModuleRun = false;// 独立功能模块运行标志
static bool laserTesting = false;  //激光测试正在进行中
void LaserCaliTest(void);
static int GetLaerTestPara(FILE *fd, LaserTest_t *para);

int64_t get_ticks_ms(void)
{
    struct timespec time;
    int nRet = clock_gettime(CLOCK_MONOTONIC, &time);
    int64_t llmSecMonCnt =  time.tv_sec*1000 + time.tv_nsec/1000000;

    return llmSecMonCnt;
}

void saveFlowDetectPointCloudData(json_object* pointCloudObj)
{
    CrLogI("saveFlowDetectPointCloudData\n");
    //判断保存点云的文件夹是否存在
    if (access(FLOW_DETECT_POINT_DIR_TEMP, F_OK) != 0)
    {
        char cmd[128] = {0};
        snprintf(cmd, sizeof(cmd), "mkdir -p '%s'",FLOW_DETECT_POINT_DIR_TEMP);

        // 调用系统命令
        char sysRes[512] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes))){
            CrLogW("system fail! res = %s\n", sysRes);
        }       
    }

    char path[128] = {0};
    struct timeval startTime;
    gettimeofday(&startTime, NULL);
    time_t raw_time = startTime.tv_sec;
    struct tm* timeinfo = localtime(&raw_time);
    char buffer[80]={0};
    int milliseconds = startTime.tv_usec / 1000;
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    snprintf(path,sizeof(path),"%s/%s.%03d.txt",FLOW_DETECT_POINT_DIR_TEMP,buffer,milliseconds);   
    json_object_to_file_ext(path, pointCloudObj, JSON_C_TO_STRING_PLAIN);

}



/**
 * @description: 
 * @return {*}
 */
static CmdSyncRecv_t GetFuncModuleRecv(void)
{
    CmdSyncRecv_t data = {0};
    if (GetKlipperCmdSyncRecvData(&data, KLIPPER_FUNCTION_MODULE_NUM, IPC_NOWAIT) <= 0) {
        bzero(&data, sizeof(data));
    }
    return data;
}

/**
 * @description: 
 * @return {*}
 */
static void ClearFuncModuleRecvList(void)
{
    CmdSyncRecv_t data = {0};
    while (1) {
        if (GetKlipperCmdSyncRecvData(&data, KLIPPER_FUNCTION_MODULE_NUM, IPC_NOWAIT) <= 0) break;
        bzero(&data, sizeof(data));
    }
}

/**
 * @description: 
 * @return {*}
 * @param {char} *data
 */
static void SendFuncModuleCmd(char *data)
{
    json_object *params = json_object_new_object();
    json_object_object_add(params, "script", json_object_new_string(data));
    AddKlipperCmd("gcode/script", params, KLIPPER_FUNCTION_MODULE_NUM, MSG_ORIGIN_CONTROLLER);
}

/**
 * @description: 
 * @return {*}
 */
static int GetAiServerSocket(void)
{
    unlink(GetDefaultAiClientSock());

    // 创建监听的套接字
    int cfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (cfd == -1) {
        CrLogW("create ai server socket fail\n");
        return -1;
    }

    // 绑定本地套接字文件
    struct sockaddr_un addr;
    addr.sun_family = AF_LOCAL;
    strcpy(addr.sun_path, GetDefaultAiClientSock());
    if (bind(cfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        CrLogW("bind ai server socket fail,error: %s(errno: %d)\n",strerror(errno),errno);
        return -1;
    }

    // 连接服务器
    struct sockaddr_un saddr;
    saddr.sun_family=AF_LOCAL;
    strcpy(saddr.sun_path, GetDefaultAiServerSock());
    if(connect(cfd, (struct sockaddr *)&saddr, sizeof(saddr)) == -1) {
        CrLogW("connect ai server socket fail ,error: %s(errno: %d)\n",strerror(errno),errno);
        return -1;
    }

    return cfd;
}

/**
 * @description: 
 * @return {*}
 * @param {int} fd
 * @param {json_object} *data
 */
static int SendJsonToAiServer(int fd, json_object *data)
{
    const char *jsonData = json_object_to_json_string(data);
    int res = send(fd, (char*)jsonData, strlen(jsonData), 0);
    // 通信截止符
    char buf[10] = {0};
    buf[0] = 0x03;
    res = send(fd, buf, 1, 0);

    return res;
}

/**
 * @description: 
 * @return {*}
 * @param {int} fd
 * @param {char} *data
 * @param {int} maxLen
 */
static int RecvJsonFromAiServer(int fd, char *data, int maxLen,int time_ms)
{
    int recvCount = 0;
    while (1)
    {
        // 设置系统状态监听
        fd_set fs_read;
        FD_ZERO(&fs_read); //每次循环都要清空集合，否则不能检测描述符变化
        FD_SET(fd, &fs_read); //添加描述符

        struct timeval time;
        time.tv_sec = 0; //set the rcv wait time
        time.tv_usec = time_ms * 1000; //100000us = 1s

        // 超时等待读变化，>0：就绪描述字的正数目， -1：出错， 0 ：超时
        int fs_sel = select(fd + 1, &fs_read, NULL, NULL, &time);
        if (fs_sel) {
            recvCount += read(fd, &data[recvCount], (maxLen - recvCount));
            if (data[recvCount - 1] == 0x03) return recvCount;
            if (recvCount >= maxLen) return -2;
        }
        else return -1;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {int} fd
 */
static int AiServerOpenFlow(int fd)
{
    // 激光开流
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("open_flow"));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取开流结果
    char flowRes[256] = {0};
    if (RecvJsonFromAiServer(fd, flowRes, sizeof(flowRes),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析开流结果
    json_object *laserRes = json_tokener_parse(flowRes);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                CrLogI("set open flow res = %d", json_object_get_int(codeObj));
                if (json_object_get_int(codeObj) == 0) {
                    json_object_put(laserRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {int} fd
 */
static int AiServerCloseFlow(int fd)
{
    // 激光关流
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("close_flow"));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取关流结果
    char flowRes[256] = {0};
    if (RecvJsonFromAiServer(fd, flowRes, sizeof(flowRes),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析关流结果
    json_object *laserRes = json_tokener_parse(flowRes);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                CrLogI("set close flow res = %d", json_object_get_int(codeObj));
                if (json_object_get_int(codeObj) == 0) {
                    json_object_put(laserRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {int} fd
 * @param {char} *cloud
 */
static int GetAiServerPointCloud(int fd, char *cloud, int timeout)
{
    // 获取点云数据
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("get_point_cloud"));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取点云数据结果
    char pointCloud[100 * 1024] = {0};
    if (RecvJsonFromAiServer(fd, pointCloud, sizeof(pointCloud),timeout) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析点云数据结果
    json_object *laserRes = json_tokener_parse(pointCloud);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 点云数据
        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                CrLogI("get point cloud res = %d", json_object_get_int(codeObj));
                if (json_object_get_int(codeObj) == 0) {
                    json_object *cloudObj = json_object_object_get(resultObj, "point_cloud");
                    if (cloudObj != NULL && json_object_is_type(cloudObj, json_type_array)) {
                        strcat(cloud, json_object_to_json_string(cloudObj));
                        json_object_put(laserRes);
                        return 0;
                    }
                    else CrLogW("get result json fail\n");
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {int} fd
 * @param {char} *cloud
 */
static int GetAiServerFlowResult(int fd,float *node1_width,float *node2_width,float *node3_width)
{
    // 解析点云数据结果
    json_object *aiCmd = json_object_new_object();
    json_object_object_add(aiCmd, "control", json_object_new_string("get_flow_detection"));
    if (SendJsonToAiServer(fd, aiCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(aiCmd);
        return -1;
    }
    json_object_put(aiCmd);

    // 获取AI识别结果
    char aiRecv[100*1024] = {0};
    if (RecvJsonFromAiServer(fd, aiRecv, sizeof(aiRecv),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析AI识别结果
    json_object *aiRes = json_tokener_parse(aiRecv);
    if (aiRes != NULL && json_object_is_type(aiRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(aiRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 点云数据
        json_object *resultObj = json_object_object_get(aiRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                int code = json_object_get_int(codeObj);
                CrLogI("get flow result code = %d", code);
                if (code == 0) {

                    json_object *pointCloudObj = json_object_object_get(resultObj, "point_cloud");
                    if (pointCloudObj != NULL && json_object_is_type(pointCloudObj, json_type_array)){
                        saveFlowDetectPointCloudData(pointCloudObj);
                    }

                    json_object *node1_widthObj = json_object_object_get(resultObj, "node1_width");
                    json_object *node2_widthObj = json_object_object_get(resultObj, "node2_width");
                    json_object *node3_widthObj = json_object_object_get(resultObj, "node3_width");
                    if (node1_widthObj != NULL && json_object_is_type(node1_widthObj, json_type_double) &&\
                        node2_widthObj != NULL && json_object_is_type(node2_widthObj, json_type_double) &&\
                        node3_widthObj != NULL && json_object_is_type(node3_widthObj, json_type_double) )
                    {
                        *node1_width = json_object_get_double(node1_widthObj);
                        *node2_width = json_object_get_double(node2_widthObj);
                        *node3_width = json_object_get_double(node3_widthObj);
                    }

                    json_object_put(aiRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(aiRes);
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {int} fd
 * @param {char} *tablePointFile
 * @param {char} *gcodePointFie
 * @param {json_object} *pointCloud
 */
static int GetAiServerFirstLayerResult(int fd, json_object *tableCloud, char *gcodePointFie, json_object *pointCloud)
{
    // 获取首层检测结果
    json_object *aiCmd = json_object_new_object();
    json_object_object_add(aiCmd, "control", json_object_new_string("get_first_floor_detect"));
    json_object_object_add(aiCmd, "layer1", tableCloud);
    json_object_object_add(aiCmd, "layer2", pointCloud);
    json_object_object_add(aiCmd, "layer3", json_object_new_string(gcodePointFie));
    if (SendJsonToAiServer(fd, aiCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(aiCmd);
        return -1;
    }
    json_object_put(aiCmd);

    // 获取AI识别结果
    char aiRecv[1024] = {0};
    if (RecvJsonFromAiServer(fd, aiRecv, sizeof(aiRecv),3000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }
    CrLogI("aiRecv=%s\n",aiRecv);
    // 解析AI识别结果
    int result = -1;
    json_object *aiRes = json_tokener_parse(aiRecv);
    if (aiRes != NULL && json_object_is_type(aiRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(aiRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 点云数据
        json_object *resultObj = json_object_object_get(aiRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                int code = json_object_get_int(codeObj);
                CrLogI("get first layer res = %d\n", code);
                if (code == 0)
                {
                    json_object *aiResultObj = json_object_object_get(resultObj, "result");
                    if (aiResultObj != NULL && json_object_is_type(aiResultObj, json_type_int)) {
                        result = json_object_get_int(aiResultObj);
                    }
                    json_object_put(aiRes);
                    return result;
                }else CrLogW("code =%d\n",code);
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(aiRes);
    return result;
}

/**
 * @description: 
 * @return {*}
 * @param {int} fd
 * @param {char} *tablePointFile
 * @param {char} *gcodePointFie
 * @param {json_object} *pointCloud
 */
static int GetAiServerFirstLayerNewResult(int fd, char *table_path, char *scan_path, char *gcode_path,int* result)
{
   // 解析点云数据结果
    json_object *aiCmd = json_object_new_object();
    json_object_object_add(aiCmd, "control", json_object_new_string("get_first_floor_detect_new"));
    json_object_object_add(aiCmd, "scan1_path", json_object_new_string(table_path));
    json_object_object_add(aiCmd, "scan2_path", json_object_new_string(scan_path));
    json_object_object_add(aiCmd, "gcode_path", json_object_new_string(gcode_path));

    if (SendJsonToAiServer(fd, aiCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(aiCmd);
        return -1;
    }
    json_object_put(aiCmd);

    // 获取AI识别结果
    char aiRecv[1024] = {0};
    if (RecvJsonFromAiServer(fd, aiRecv, sizeof(aiRecv),600*1000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析AI识别结果
    json_object *aiRes = json_tokener_parse(aiRecv);
    if (aiRes != NULL && json_object_is_type(aiRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(aiRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 点云数据
        json_object *resultObj = json_object_object_get(aiRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                int code = json_object_get_int(codeObj);
                CrLogI("get first layer res = %d\n", code);
                if (code == 0)
                {
                    json_object *aiResultObj = json_object_object_get(resultObj, "result");
                    if (aiResultObj != NULL && json_object_is_type(aiResultObj, json_type_int)) {
                        *result = json_object_get_int(aiResultObj);
                        json_object_put(aiRes);
                        return 0;
                    }
                }else CrLogW("code =%d\n",code);
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(aiRes);
    return -1;
}
/**
 * @description: 
 * @return {*}
 * @param {int} fd
 * @param {unsigned int} count
 * @param {float} *node1_width
 * @param {float} *node2_width
 * @param {float} *node3_width
 * @param {char*} best_line
 */
static int GetAiServerSelectLine(int fd, unsigned int count, float *node1_width,float *node2_width,float *node3_width,char* best_line)
{
    // 解析点云数据结果
    json_object *aiCmd = json_object_new_object();
    json_object_object_add(aiCmd, "control", json_object_new_string("get_select_line"));
    json_object * line1 = json_object_new_array();
    json_object * line2 = json_object_new_array();
    json_object * line3 = json_object_new_array();
    for(int i=0;i<count;i++)
    {  
        json_object_array_add(line1, json_object_new_double(node1_width[i]));
        json_object_array_add(line2, json_object_new_double(node2_width[i]));
        json_object_array_add(line3, json_object_new_double(node3_width[i]));
    }
    json_object_object_add(aiCmd, "line1", line1);
    json_object_object_add(aiCmd, "line2", line2);
    json_object_object_add(aiCmd, "line3", line3);

    if (SendJsonToAiServer(fd, aiCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(aiCmd);
        return -1;
    }
    json_object_put(aiCmd);

    // 获取AI识别结果
    char aiRecv[1024] = {0};
    if (RecvJsonFromAiServer(fd, aiRecv, sizeof(aiRecv),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析AI识别结果
    json_object *aiRes = json_tokener_parse(aiRecv);
    if (aiRes != NULL && json_object_is_type(aiRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(aiRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 点云数据
        json_object *resultObj = json_object_object_get(aiRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                int code = json_object_get_int(codeObj);
                CrLogI("get level value res = %d", code);
                if (code == 0) {
                    json_object *bestlineObj = json_object_object_get(resultObj, "best_line");
                    //返回值为字符串
                    if (bestlineObj != NULL && json_object_is_type(bestlineObj, json_type_string))
                    {
                        const char* tmp = json_object_get_string(bestlineObj);
                        snprintf(best_line,64,"%s",tmp);
                    }

                    json_object_put(aiRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(aiRes);
    return -1;
}


static int GetAiServerFlowDetectNew(int fd, char *table_path,char *line_path, char* best_line)
{
    // 解析点云数据结果
    json_object *aiCmd = json_object_new_object();
    json_object_object_add(aiCmd, "control", json_object_new_string("get_flow_detection_new"));
    json_object_object_add(aiCmd, "flow_table_path", json_object_new_string(table_path));
    json_object_object_add(aiCmd, "flow_line_path", json_object_new_string(line_path));
   
    if (SendJsonToAiServer(fd, aiCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(aiCmd);
        return -1;
    }
    json_object_put(aiCmd);

    // 获取AI识别结果
    char aiRecv[1024] = {0};
    if (RecvJsonFromAiServer(fd, aiRecv, sizeof(aiRecv),40000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析AI识别结果
    json_object *aiRes = json_tokener_parse(aiRecv);
    if (aiRes != NULL && json_object_is_type(aiRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(aiRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 点云数据
        json_object *resultObj = json_object_object_get(aiRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                int code = json_object_get_int(codeObj);
                CrLogI("get flow detect new res = %d", code);
                if (code == 0) {
                    json_object *bestlineObj = json_object_object_get(resultObj, "best_line");
                    //返回值为字符串
                    if (bestlineObj != NULL && json_object_is_type(bestlineObj, json_type_string))
                    {
                        const char* tmp = json_object_get_string(bestlineObj);
                        snprintf(best_line,64,"%s",tmp);
                    }

                    json_object_put(aiRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(aiRes);
    return -1;
}

/**
 * @description: 获取激光矫正后激光是否能够打在方框内的结果
 * @return {int} <0发送失败 ，==0调用中间件成功
 * @param {char* scan1}: 未打印方框前激光打在指定位置的点云文件路径
 * @param {char* scan2}: 打印完方框后激光打在指定位置的点云文件路径
 * @param {int* result}: 调用中间层的返回结果 1：异常  0：正常
 */
static int GetAiServerAutoTestResult(int fd, char *scan1,char *scan2, int* result)
{
    // 解析点云数据结果
    json_object *aiCmd = json_object_new_object();
    json_object_object_add(aiCmd, "control", json_object_new_string("get_laser_auto_test_result"));
    json_object_object_add(aiCmd, "scan1_path", json_object_new_string(scan1));
    json_object_object_add(aiCmd, "scan2_path", json_object_new_string(scan2));
   
    if (SendJsonToAiServer(fd, aiCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(aiCmd);
        return -1;
    }
    json_object_put(aiCmd);

    // 获取AI识别结果
    char aiRecv[1024] = {0};
    if (RecvJsonFromAiServer(fd, aiRecv, sizeof(aiRecv),40000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析AI识别结果
    json_object *aiRes = json_tokener_parse(aiRecv);
    if (aiRes != NULL && json_object_is_type(aiRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(aiRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 点云数据
        json_object *resultObj = json_object_object_get(aiRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                int code = json_object_get_int(codeObj);
                CrLogI("get laser auto test respone code = %d", code);
                if (code == 0) {
                    json_object *resObj = json_object_object_get(resultObj, "result");
                    //返回值为字符串
                    if (resObj != NULL && json_object_is_type(resObj, json_type_int))
                    {
                        *result = json_object_get_int(resObj);
                        
                    }

                    json_object_put(aiRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(aiRes);
    return -1;
}
/**
 * @description: 
 * @return {*}
 * @param {int} fd
 */
static int AiServerSetExposure(int fd,int exposure)
{
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("set_laser_exposure"));
    json_object_object_add(laserCmd, "exposure", json_object_new_int(exposure));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取结果
    char flowRes[256] = {0};
    if (RecvJsonFromAiServer(fd, flowRes, sizeof(flowRes),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析结果
    json_object *laserRes = json_tokener_parse(flowRes);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                CrLogI("set exposure res = %d", json_object_get_int(codeObj));
                if (json_object_get_int(codeObj) == 0) {
                    json_object_put(laserRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}
/**
 * @description: 
 * @return {*}
 * @param {int} fd
 */
static int AiServerGetExposure(int fd,int *exposure)
{
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("get_laser_exposure"));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取结果
    char flowRes[256] = {0};
    if (RecvJsonFromAiServer(fd, flowRes, sizeof(flowRes),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析结果
    json_object *laserRes = json_tokener_parse(flowRes);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int)&&\
                json_object_get_int(codeObj) == 0)
            {
                json_object *exposureObj = json_object_object_get(resultObj, "exposure");
                if(exposureObj != NULL && json_object_is_type(exposureObj, json_type_int)){
                    *exposure = json_object_get_int(exposureObj);
                    CrLogI("get laser exposure = %d", exposure);
                }
                else CrLogW("get exposure json fail\n");

                json_object_put(laserRes);
                return 0;   
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}
/**
 * @description: 
 * @return {*}
 * @param {int} fd
 */
static int AiServerSetGain(int fd,int gain)
{
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("set_laser_gain"));
    json_object_object_add(laserCmd, "gain", json_object_new_int(gain));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取结果
    char flowRes[256] = {0};
    if (RecvJsonFromAiServer(fd, flowRes, sizeof(flowRes),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析结果
    json_object *laserRes = json_tokener_parse(flowRes);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                CrLogI("set gain res = %d", json_object_get_int(codeObj));
                if (json_object_get_int(codeObj) == 0) {
                    json_object_put(laserRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}
/**
 * @description: 
 * @return {*}
 * @param {int} fd
 */
static int AiServerGetGain(int fd,int *gain)
{
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("get_laser_gain"));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取结果
    char flowRes[256] = {0};
    if (RecvJsonFromAiServer(fd, flowRes, sizeof(flowRes),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析结果
    json_object *laserRes = json_tokener_parse(flowRes);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int)&&\
                json_object_get_int(codeObj) == 0)
            {
                json_object *gainObj = json_object_object_get(resultObj, "gain");
                if(gainObj != NULL && json_object_is_type(gainObj, json_type_int)){
                    *gain = json_object_get_int(gainObj);
                    CrLogI("get laser gain = %d", gain);
                }
                else CrLogW("get gain json fail\n");

                json_object_put(laserRes);
                return 0;   
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}
/**
 * @description: 获取激光模组版本
 * @return {*}
 * @param {int} fd
 */
static int AiServerGetVersion(int fd,char* version)
{
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("get_laser_version"));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取结果
    char flowRes[256] = {0};
    if (RecvJsonFromAiServer(fd, flowRes, sizeof(flowRes),3000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析结果
    json_object *laserRes = json_tokener_parse(flowRes);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int)&&\
                json_object_get_int(codeObj) == 0)
            {
                json_object *verObj = json_object_object_get(resultObj, "version");
                if(verObj != NULL && json_object_is_type(verObj, json_type_string)){
                    const char* ver = json_object_get_string(verObj);
                    if(ver){
                        memcpy(version,ver,strlen(ver));
                        CrLogI("get laser version = %s\n", ver);
                    }else{
                        CrLogW("get laser version fail !!!");
                    }
                }
                else CrLogW("get version json fail\n");

                json_object_put(laserRes);
                return 0;   
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}
/**
 * @description: 
 * @return {*}AiServerSetCoor
 * @param {int} fd
 */
static int AiServerSetCoor(int fd,int coor)
{
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("set_laser_coor"));
    json_object_object_add(laserCmd, "coor", json_object_new_int(coor));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取结果
    char flowRes[256] = {0};
    if (RecvJsonFromAiServer(fd, flowRes, sizeof(flowRes),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析结果
    json_object *laserRes = json_tokener_parse(flowRes);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                CrLogI("set coor res = %d", json_object_get_int(codeObj));
                if (json_object_get_int(codeObj) == 0) {
                    json_object_put(laserRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}

/**
 * @description: 
 * @return {*}AiServerSetCoor
 * @param {int} fd
 */
static int AiServerSetTakeOver(int fd,int takeMode)
{
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("set_take_over_model"));
    json_object_object_add(laserCmd, "takeOverModel", json_object_new_int(takeMode));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取结果
    char takeOverRes[256] = {0};
    if (RecvJsonFromAiServer(fd, takeOverRes, sizeof(takeOverRes),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析结果
    json_object *laserRes = json_tokener_parse(takeOverRes);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                CrLogI("set take over res = %d", json_object_get_int(codeObj));
                if (json_object_get_int(codeObj) == 0) {
                    json_object_put(laserRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}
/**
 * @description: 
 * @return {*}
 * @param {float} x
 * @param {float} y
 */
static int AiServerOpenLaser(int fd,bool open)
{
    json_object *laserCmd = json_object_new_object();
    if(open){
        json_object_object_add(laserCmd, "control", json_object_new_string("set_laser_open"));
    }
    else{
        json_object_object_add(laserCmd, "control", json_object_new_string("set_laser_close"));
    }

    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取点云数据结果
    char res[128] = {0};
    if (RecvJsonFromAiServer(fd, res, sizeof(res),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析点云数据结果
    json_object *laserRes = json_tokener_parse(res);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 点云数据
        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                if(open)
                    CrLogI("set laser open res = %d", json_object_get_int(codeObj));
                else
                    CrLogI("get laser close res = %d", json_object_get_int(codeObj));

                if (json_object_get_int(codeObj) == 0) {
                    json_object_put(laserRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}


/**
 * @description: 
 * @return {*}
 * @param {float} x
 * @param {float} y
 */
static int AiServerOpenLight(int fd,bool open)
{
    //{"control":"set_fill_light_open"}
    //{"control":"set_fill_light_close"}
    json_object *laserCmd = json_object_new_object();
    if(open){
        json_object_object_add(laserCmd, "control", json_object_new_string("set_fill_light_open"));
    }
    else{
        json_object_object_add(laserCmd, "control", json_object_new_string("set_fill_light_close"));
    }

    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取点云数据结果
    char res[128] = {0};
    if (RecvJsonFromAiServer(fd, res, sizeof(res),2000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析点云数据结果
    json_object *laserRes = json_tokener_parse(res);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 点云数据
        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                if(open)
                    CrLogI("set laser open light res = %d", json_object_get_int(codeObj));
                else
                    CrLogI("set laser close light res = %d", json_object_get_int(codeObj));
               
                if (json_object_get_int(codeObj) == 0) {
                    json_object_put(laserRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}


/**
 * @description: 抓拍一张IR图
 * @return {*}
 * @param {int} fd
 */
static int AiServerCapIrImage(int fd,int type,int resolution,int *image_size)
{
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("create_ir_image"));
    json_object_object_add(laserCmd, "type", json_object_new_int(type));
    json_object_object_add(laserCmd, "resolution", json_object_new_int(resolution));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取开流结果
    char IrRes[256] = {0};
    if (RecvJsonFromAiServer(fd, IrRes, sizeof(IrRes),15000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析开流结果
    json_object *laserRes = json_tokener_parse(IrRes);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                CrLogI("capture ir image res = %d", json_object_get_int(codeObj));
                if (json_object_get_int(codeObj) == 0) {
                    json_object *fileSizeObj = json_object_object_get(resultObj, "file_size");
                    int file_size = json_object_get_int(fileSizeObj);
                    CrLogI("IR image file_size=%d",file_size);
                    *image_size=file_size;
                    json_object_put(laserRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}


/**
 * @description: 从激光模组获取一张IR图
 * @return {*}
 * @param {int} fd
 */
static int AiServerGetIrImage(int fd, char* image_path,int image_size)
{
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("get_an_ir_image"));
    json_object_object_add(laserCmd, "file_path", json_object_new_string(image_path));
    json_object_object_add(laserCmd, "file_size", json_object_new_int(image_size));
    
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 获取图传结果
    char IrRes[256] = {0};
    if (RecvJsonFromAiServer(fd, IrRes, sizeof(IrRes),15000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }

    // 解析图传结果
    json_object *laserRes = json_tokener_parse(IrRes);
    if (laserRes != NULL && json_object_is_type(laserRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                CrLogI("get ir image res = %d", json_object_get_int(codeObj));
                if (json_object_get_int(codeObj) == 0) {
                    CrLogI("get image success :%s\n",image_path);
                    
                    json_object_put(laserRes);
                    return 0;
                }
                else{
                    json_object_put(laserRes);
                    CrLogI("get image fail\n");
                    return -1;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserRes);
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {FILE} *fd
 * @param {char} *gcode
 */
static int GetGcodeFromFile(FILE *fd, char *gcode)
{
    #define READ_LEN    1024
    char readBuff[READ_LEN] = {0};

    // 读取指令
    while (1)
    {
        // 判断是否读取成功
        if (!fgets(readBuff, READ_LEN, fd) && !feof(fd)) {
            bzero(readBuff, READ_LEN);
            continue;
        }
        // 判断文件读取结束
        if (feof(fd)) {
            return -1;
        }

        // 解析Gcode
        if (readBuff[0] == ';' || readBuff[0] == '\r' || readBuff[0] == '\n') {
            bzero(readBuff, READ_LEN);
            continue;
        }
        else {
            char *end = strstr(readBuff, ";");
            if (end) end[0] = '\0';
            else {
                char *line1 = strstr(readBuff, "\r\n");
                char *line2 = strstr(readBuff, "\n");
                char *line3 = strstr(readBuff, "\r");
                if (line1) line1[0] = '\0';
                else if (line2) line2[0] = '\0';
                else if (line3) line3[0] = '\0';
            }

            strcat(gcode, readBuff);
            return 0;
        }
        bzero(readBuff, READ_LEN);
    }
    return -1;
}
/**
 * @description: 
 * @return {*}
 * @param {FILE} *fd
 * @param {char} *gcode
 */
static int GetFlowLineGcodeFromFile(FILE *fd)
{

    #define READ_LEN    1024
    char readBuff[READ_LEN] = {0};
    long file_size = 0;
    // 移动文件指针到文件末尾
    if (fseek(fd, 0, SEEK_END) != 0) {	
		CrLogW("fseek failed !!\n");
        return -1;
	}
    // 获取文件大小
	file_size = ftell(fd);	
	if (file_size == -1) {
		CrLogW("ftell failed!!\n");
        return -1;
	}
    rewind(fd);

    char gcode[file_size];
    if(file_size>0){
        bzero(gcode,sizeof(gcode));
    }else{
        return -1;
    }

    while (1)
    {
        // 判断是否读取成功
        if (!fgets(readBuff, READ_LEN, fd) && !feof(fd)) {
            bzero(readBuff, READ_LEN);
            continue;
        }
        // 判断文件读取结束
        if (feof(fd)) {
            break;
        }

        // 解析Gcode
        if (readBuff[0] == ';' || readBuff[0] == '\r' || readBuff[0] == '\n') {
            bzero(readBuff, READ_LEN);
            continue;
        }
        else {
            // char *end = strstr(readBuff, ";");
            // if (end) end[0] = '\0';
            // else {
            //     char *line1 = strstr(readBuff, "\r\n");
            //     char *line2 = strstr(readBuff, "\n");
            //     char *line3 = strstr(readBuff, "\r");
            //     if (line1) line1[0] = '\0';
            //     else if (line2) line2[0] = '\0';
            //     else if (line3) line3[0] = '\0';
            // }

            strcat(gcode, readBuff);
            
        }
        bzero(readBuff, READ_LEN);
    }
    SendFuncModuleCmd(gcode);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    return 0;
}


/**
 * @description: 
 * @return {*}
 * @param {int} fd
 */
static int AiServerLaserCali(int fd,int step)
{
    // 激光b标定步骤
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("set_laser_cali_step"));
    json_object_object_add(laserCmd, "step", json_object_new_int(step));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogI("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 
    int timeout=0;
    char CalistepRes[256] = {0};
    while(1){
        if (RecvJsonFromAiServer(fd, CalistepRes, sizeof(CalistepRes),3000) >=0) {        
            break;
        }
        //超过5s结束接收
        if(timeout++ >=6){
            CrLogI("recv json from ai server fail\n");
            return -1;
        }
    }
    // 
    json_object *laserCaliRes = json_tokener_parse(CalistepRes);
    if (laserCaliRes != NULL && json_object_is_type(laserCaliRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserCaliRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s\n", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserCaliRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");    
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                CrLogI("set laser calibration step %d res = %d\n", step, json_object_get_int(codeObj));
                if (json_object_get_int(codeObj) == 0) {
                    json_object_put(laserCaliRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserCaliRes);
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {int} fd
 */
static int AiServerLaserPointCloudLevel(int fd,int level)
{
    // 激光b标定步骤
    json_object *laserCmd = json_object_new_object();
    json_object_object_add(laserCmd, "control", json_object_new_string("set_point_cloud_level"));
    json_object_object_add(laserCmd, "level", json_object_new_int(level));
    if (SendJsonToAiServer(fd, laserCmd) < 0) {
        CrLogI("send json to ai server fail\n");
        json_object_put(laserCmd);
        return -1;
    }
    json_object_put(laserCmd);

    // 
    int timeout=0;
    char CalistepRes[256] = {0};
    while(1){
        if (RecvJsonFromAiServer(fd, CalistepRes, sizeof(CalistepRes),3000) >=0) {        
            break;
        }
        //超过5s结束接收
        if(timeout++ >=6){
            CrLogI("recv json from ai server fail\n");
            return -1;
        }
    }
    // 
    json_object *laserCaliRes = json_tokener_parse(CalistepRes);
    if (laserCaliRes != NULL && json_object_is_type(laserCaliRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(laserCaliRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s\n", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");

        json_object *resultObj = json_object_object_get(laserCaliRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");    
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                CrLogI("set laser point cloud level %d res = %d\n", level, json_object_get_int(codeObj));
                if (json_object_get_int(codeObj) == 0) {
                    json_object_put(laserCaliRes);
                    return 0;
                }
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(laserCaliRes);
    return -1;
}
/**
 * @description: 
 * @return {*}
 */
LaserConfig_t GetSaveLaserOffset(void)
{
    LaserConfig_t returnLaserCfg = {0};
    // 读取配置文件
    json_object *offsetObj = json_object_from_file(GetLaserOffsetInfo());
    if (offsetObj != NULL || json_object_is_type(offsetObj, json_type_object))
    {
        json_object *xOffsetObj = json_object_object_get(offsetObj, "laser_offset_x");
        json_object *yOffsetObj = json_object_object_get(offsetObj, "laser_offset_y");
        json_object *zOffsetObj = json_object_object_get(offsetObj, "laser_offset_z");

        if (xOffsetObj != NULL && json_object_is_type(xOffsetObj, json_type_double) &&
            yOffsetObj != NULL && json_object_is_type(yOffsetObj, json_type_double) &&
            zOffsetObj != NULL && json_object_is_type(zOffsetObj, json_type_double))
        {
            returnLaserCfg.x_offset = json_object_get_double(xOffsetObj);
            returnLaserCfg.y_offset = json_object_get_double(yOffsetObj);
            returnLaserCfg.z_offset = json_object_get_double(zOffsetObj);
            CrLogI("get laser offset; x = %f, y = %f, z = %f",
                    returnLaserCfg.x_offset, returnLaserCfg.y_offset, returnLaserCfg.z_offset);

            if (offsetObj) json_object_put(offsetObj);
            return returnLaserCfg;
        }
    }
    if (offsetObj) json_object_put(offsetObj);

    // 从结构参数读取配置文件
    json_object *structureObj = json_object_from_file(GetDeviceStructureConfig());
    if (structureObj != NULL || json_object_is_type(structureObj, json_type_object))
    {
        json_object *laserOffsetObj = json_object_object_get(structureObj, "laser_offset");
        if (laserOffsetObj != NULL || json_object_is_type(laserOffsetObj, json_type_object))
        {
            json_object *xOffsetObj = json_object_object_get(laserOffsetObj, "laser_x_offset");
            json_object *yOffsetObj = json_object_object_get(laserOffsetObj, "laser_y_offset");
            json_object *zOffsetObj = json_object_object_get(laserOffsetObj, "laser_z_offset");

            if (xOffsetObj != NULL && json_object_is_type(xOffsetObj, json_type_double) &&
                yOffsetObj != NULL && json_object_is_type(yOffsetObj, json_type_double) &&
                zOffsetObj != NULL && json_object_is_type(zOffsetObj, json_type_double))
            {
                returnLaserCfg.x_offset = json_object_get_double(xOffsetObj);
                returnLaserCfg.y_offset = json_object_get_double(yOffsetObj);
                returnLaserCfg.z_offset = json_object_get_double(zOffsetObj);
                CrLogI("get default laser offset; x = %f, y = %f, z = %f",
                        returnLaserCfg.x_offset, returnLaserCfg.y_offset, returnLaserCfg.z_offset);

                json_object_put(structureObj);
                return returnLaserCfg;
            }
        }
    }
    if (structureObj) json_object_put(structureObj);

    CrLogW("get laser offset info obj fail\n");
    returnLaserCfg = *GetLaserOffset();
    return returnLaserCfg;
}

/**
 * @description: 
 * @return {*}
 */
LaserConfig_t GetSavesTickerOffset(void)
{
    LaserConfig_t returnStickerCfg = {0};
    // 从结构参数读取配置文件
    json_object *structureObj = json_object_from_file(GetDeviceStructureConfig());
    if (structureObj != NULL || json_object_is_type(structureObj, json_type_object))
    {
        json_object *laserOffsetObj = json_object_object_get(structureObj, "laser_offset");
        if (laserOffsetObj != NULL || json_object_is_type(laserOffsetObj, json_type_object))
        {
            json_object *xOffsetObj = json_object_object_get(laserOffsetObj, "cali_x_offset");
            json_object *yOffsetObj = json_object_object_get(laserOffsetObj, "cali_y_offset");
            json_object *zOffsetObj = json_object_object_get(laserOffsetObj, "cali_z_offset");

            if (xOffsetObj != NULL && json_object_is_type(xOffsetObj, json_type_double) &&
                yOffsetObj != NULL && json_object_is_type(yOffsetObj, json_type_double) &&
                zOffsetObj != NULL && json_object_is_type(zOffsetObj, json_type_double))
            {
                returnStickerCfg.x_offset = json_object_get_double(xOffsetObj);
                returnStickerCfg.y_offset = json_object_get_double(yOffsetObj);
                returnStickerCfg.z_offset = json_object_get_double(zOffsetObj);
                CrLogI("get default sticker offset; x = %f, y = %f, z = %f",
                        returnStickerCfg.x_offset, returnStickerCfg.y_offset, returnStickerCfg.z_offset);

                json_object_put(structureObj);
                return returnStickerCfg;
            }
        }
    }
    if (structureObj) json_object_put(structureObj);

    CrLogW("get sticker offset info obj fail\n");
    return returnStickerCfg;
}

/**
 * @description: 
 * @return {*}
 * @param {int} fd
 * @param {json_object} *pointCloud
 * @param {char} *gcodePointFie
 * @param {LaserConfig_t} *laserCfg
 */
static int GetAiServerLaserOffsetResult(int fd, json_object *pointCloud, char *gcodePointFie, LaserConfig_t *laserCfg)
{
    // 获取激光偏移结果
    json_object *aiCmd = json_object_new_object();
    json_object_object_add(aiCmd, "control", json_object_new_string("get_laser_offset"));
    json_object_object_add(aiCmd, "scan_point", pointCloud);
    json_object_object_add(aiCmd, "gcode_point", json_object_new_string(gcodePointFie));
    if (SendJsonToAiServer(fd, aiCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(aiCmd);
        return -1;
    }
    json_object_put(aiCmd);

    // 获取AI识别结果
    char aiRecv[1024] = {0};
    if (RecvJsonFromAiServer(fd, aiRecv, sizeof(aiRecv),3000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }
    CrLogI("aiRecv=%s\n",aiRecv);

    // 解析AI识别结果
    int result = -1;
    json_object *aiRes = json_tokener_parse(aiRecv);
    if (aiRes != NULL && json_object_is_type(aiRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(aiRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 矫正结果
        json_object *resultObj = json_object_object_get(aiRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                int code = json_object_get_int(codeObj);
                CrLogI("get first layer res = %d\n", code);
                if (code == 0)
                {
                    json_object *x_offsetObj = json_object_object_get(resultObj, "x_offset");
                    json_object *y_offsetObj = json_object_object_get(resultObj, "y_offset");
                    if (x_offsetObj != NULL && json_object_is_type(x_offsetObj, json_type_double) &&
                        y_offsetObj != NULL && json_object_is_type(y_offsetObj, json_type_double))
                    {
                        laserCfg->x_offset = json_object_get_double(x_offsetObj);
                        laserCfg->y_offset = json_object_get_double(y_offsetObj);
                    }
                    json_object_put(aiRes);
                    return 0;
                }else CrLogW("code =%d\n",code);
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(aiRes);
    return result;
}
/**
 * @description: 
 * @return {*}
 * @param {int} fd
 * @param {json_object} *pointCloud
 * @param {char} *gcodePointFie
 * @param {LaserConfig_t} *laserCfg
 */
static int GetAiServerLaserOffsetTwoPointResult(int fd, json_object *pcExp1000, json_object *pcExp2000, LaserConfig_t *laserCfg)
{
    // 获取激光偏移结果
    json_object *aiCmd = json_object_new_object();
    json_object_object_add(aiCmd, "control", json_object_new_string("get_laser_offset_two_point"));
    json_object_object_add(aiCmd, "pcExp1000", pcExp1000);
    json_object_object_add(aiCmd, "pcExp2000", pcExp2000);
    if (SendJsonToAiServer(fd, aiCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(aiCmd);
        return -1;
    }
    json_object_put(aiCmd);

    // 获取AI识别结果
    char aiRecv[1024] = {0};
    if (RecvJsonFromAiServer(fd, aiRecv, sizeof(aiRecv),15000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }
    CrLogI("aiRecv=%s\n",aiRecv);

    // 解析AI识别结果
    int result = -1;
    json_object *aiRes = json_tokener_parse(aiRecv);
    if (aiRes != NULL && json_object_is_type(aiRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(aiRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 矫正结果
        json_object *resultObj = json_object_object_get(aiRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                int code = json_object_get_int(codeObj);
                CrLogI("get first layer res = %d\n", code);
                if (code == 0)
                {
                    json_object *x_offsetObj = json_object_object_get(resultObj, "x_offset");
                    json_object *y_offsetObj = json_object_object_get(resultObj, "y_offset");
                    if (x_offsetObj != NULL && json_object_is_type(x_offsetObj, json_type_double) &&
                        y_offsetObj != NULL && json_object_is_type(y_offsetObj, json_type_double))
                    {
                        laserCfg->x_offset = json_object_get_double(x_offsetObj);
                        laserCfg->y_offset = json_object_get_double(y_offsetObj);
                    }
                    json_object_put(aiRes);
                    return 0;
                }else CrLogW("code =%d\n",code);
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(aiRes);
    return result;
}
/**
 * @description: 
 * @return {*}
 */
static int GetAiServerLaserOffsetNewResult(int fd,
                                        json_object *tablePoint, json_object *scanPoint,
                                        double cx, double cy,
                                        LaserOffsetRes_t *laserCfg)
{
    // 获取激光偏移结果
    json_object *aiCmd = json_object_new_object();
    json_object_object_add(aiCmd, "control", json_object_new_string("get_laser_offset_0.2mm"));
    json_object_object_add(aiCmd, "table_point", tablePoint);
    json_object_object_add(aiCmd, "scan_point", scanPoint);
    json_object_object_add(aiCmd, "local_cx", json_object_new_double(cx));
    json_object_object_add(aiCmd, "local_cy", json_object_new_double(cy));
    if (SendJsonToAiServer(fd, aiCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(aiCmd);
        return -1;
    }
    json_object_put(aiCmd);

    // 获取AI识别结果
    char aiRecv[1024] = {0};
    if (RecvJsonFromAiServer(fd, aiRecv, sizeof(aiRecv),3000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }
    CrLogI("aiRecv=%s\n",aiRecv);

    // 解析AI识别结果
    int result = -1;
    json_object *aiRes = json_tokener_parse(aiRecv);
    if (aiRes != NULL && json_object_is_type(aiRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(aiRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 矫正结果
        json_object *resultObj = json_object_object_get(aiRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                int code = json_object_get_int(codeObj);
                CrLogI("get first layer res = %d\n", code);
                if (code == 0)
                {
                    json_object *confidenceObj = json_object_object_get(resultObj, "confidence");
                    json_object *x_offsetObj = json_object_object_get(resultObj, "x_offset");
                    json_object *y_offsetObj = json_object_object_get(resultObj, "y_offset");
                    if (confidenceObj != NULL && json_object_is_type(confidenceObj, json_type_double) &&
                        x_offsetObj != NULL && json_object_is_type(x_offsetObj, json_type_double) &&
                        y_offsetObj != NULL && json_object_is_type(y_offsetObj, json_type_double))
                    {
                        laserCfg->confidence = json_object_get_double(confidenceObj);
                        laserCfg->x_offset = json_object_get_double(x_offsetObj);
                        laserCfg->y_offset = json_object_get_double(y_offsetObj);
                    }
                    json_object_put(aiRes);
                    return 0;
                }else CrLogW("code =%d\n",code);
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(aiRes);
    return result;
}
static int GetAiServerLaserOffset02mmResult(int fd,char* scan_path,char* table_path,
                                        double *x_offset, double *y_offset)
{
    // 获取激光偏移结果
    json_object *aiCmd = json_object_new_object();
    json_object_object_add(aiCmd, "control", json_object_new_string("get_laser_offset_0.2mm_new"));
    json_object_object_add(aiCmd, "table_pc_path", json_object_new_string(table_path));
    json_object_object_add(aiCmd, "scan_pc_path", json_object_new_string(scan_path));
    if (SendJsonToAiServer(fd, aiCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(aiCmd);
        return -1;
    }
    json_object_put(aiCmd);

    // 获取AI识别结果
    char aiRecv[1024] = {0};
    if (RecvJsonFromAiServer(fd, aiRecv, sizeof(aiRecv),300000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }
    CrLogI("aiRecv=%s\n",aiRecv);

    // 解析AI识别结果
    int result = -1;
    json_object *aiRes = json_tokener_parse(aiRecv);
    if (aiRes != NULL && json_object_is_type(aiRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(aiRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 矫正结果
        json_object *resultObj = json_object_object_get(aiRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                int code = json_object_get_int(codeObj);
                if (code == 0)
                {
                    json_object *x_offsetObj = json_object_object_get(resultObj, "x_offset");
                    json_object *y_offsetObj = json_object_object_get(resultObj, "y_offset");
                    if (x_offsetObj != NULL && json_object_is_type(x_offsetObj, json_type_double) &&
                        y_offsetObj != NULL && json_object_is_type(y_offsetObj, json_type_double))
                    {
                        *x_offset = json_object_get_double(x_offsetObj);
                        *y_offset = json_object_get_double(y_offsetObj);
                        CrLogI("x_offset=%lf  y_offset=%lf\n",*x_offset,*y_offset);
                    }
                    json_object_put(aiRes);
                    return 0;
                }else CrLogW("code =%d\n",code);
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(aiRes);
    return result;
}
/**
 * @description: 
 * @return {*}
 * @param {int} fd
 * @param {json_object} *pointCloud
 * @param {char} *gcodePointFie
 * @param {LaserConfig_t} *laserCfg
 */
static int GetAiServerLaserZHightResult(int fd, json_object *pointCloud, double* z_hight)
{
    // 获取激光偏移结果
    json_object *aiCmd = json_object_new_object();
    json_object_object_add(aiCmd, "control", json_object_new_string("get_level_value"));
    json_object_object_add(aiCmd, "point_cloud", pointCloud);
    if (SendJsonToAiServer(fd, aiCmd) < 0) {
        CrLogW("send json to ai server fail\n");
        json_object_put(aiCmd);
        return -1;
    }
    json_object_put(aiCmd);

    // 获取AI识别结果
    char aiRecv[1024] = {0};
    if (RecvJsonFromAiServer(fd, aiRecv, sizeof(aiRecv),3000) < 0) {
        CrLogW("recv json from ai server fail\n");
        return -1;
    }
    CrLogI("aiRecv=%s\n",aiRecv);

    // 解析AI识别结果
    int result = -1;
    json_object *aiRes = json_tokener_parse(aiRecv);
    if (aiRes != NULL && json_object_is_type(aiRes, json_type_object))
    {
        json_object *controlObj = json_object_object_get(aiRes, "control");
        if (controlObj != NULL && json_object_is_type(controlObj, json_type_string)) {
            CrLogI("control cmd = %s", json_object_get_string(controlObj));
        }
        else CrLogW("get result json fail\n");
        
        // 矫正结果
        json_object *resultObj = json_object_object_get(aiRes, "result");
        if (resultObj != NULL && json_object_is_type(resultObj, json_type_object))
        {
            json_object *codeObj = json_object_object_get(resultObj, "code");
            if (codeObj != NULL && json_object_is_type(codeObj, json_type_int))
            {
                int code = json_object_get_int(codeObj);
                CrLogI("get first layer res = %d\n", code);
                if (code == 0)
                {
                    json_object *z_hightObj = json_object_object_get(resultObj, "value");
                    if (z_hightObj != NULL && json_object_is_type(z_hightObj, json_type_double))
                    {
                       *z_hight = json_object_get_double(z_hightObj);
                    }
                    json_object_put(aiRes);
                    return 0;
                }else CrLogW("code =%d\n",code);
            }
            else CrLogW("get result json fail\n");
        }
        else CrLogW("get result json fail\n");
    }
    else CrLogW("get result json fail\n");

    json_object_put(aiRes);
    return result;
}



/*********************************************************
 ******************** AI流量检测 *************************
 *********************************************************/
/**
 * @description: 
 * @return {*}
 * @param {FILE} *fd
 */
static int SendNextDrawLineGcode(FILE *fd)
{
    char readBuff[1024] = {0};
    if (GetGcodeFromFile(fd, readBuff) != 0) {
        CrLogW("gcode file invalid\n");
        return -1;
    }
    SendFuncModuleCmd(readBuff);
    return 0;
}

static int SendDrawFlowLineGcode(FILE *fd)
{
    if (GetFlowLineGcodeFromFile(fd) != 0) {
        CrLogW("gcode file invalid\n");
        return -1;
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {float} x
 * @param {float} y
 */
static void SendLightGcode(float value)
{
    char gcodeCmd[256] = {0};
    snprintf(gcodeCmd, sizeof(gcodeCmd), "SET_PIN PIN=LED VALUE=%.2f",value);
    SendFuncModuleCmd(gcodeCmd);
}


/**
 * @description: 
 * @return {*}
 * @param {float} x
 * @param {float} y
 */
static void SendDetectMoveGcode(float x, float y, float z,float speed)
{
    CrLogI("detect move x = %f, y = %f, z = %f\n", x, y, z);
    char gcodeCmd[256] = {0};
    snprintf(gcodeCmd, sizeof(gcodeCmd), "G0 X%0.2f Y%0.2f Z%0.2f F%0.2f\nM400", x, y, z,speed);
    SendFuncModuleCmd(gcodeCmd);
}
/**
 * @description: 
 * @return {*}
 * @param {float} x
 * @param {float} y
 */
static void SendDetectMoveXYGcode(float x, float y,float speed)
{
    CrLogI("detect move x = %f, y = %f\n", x, y);
    char gcodeCmd[256] = {0};
    snprintf(gcodeCmd, sizeof(gcodeCmd), "G0 X%0.2f Y%0.2f F%0.2f\nM400", x, y,speed);
    SendFuncModuleCmd(gcodeCmd);
}
/**
 * @description: 
 * @return {*}
 * @param {float} x
 * @param {float} y
 */
static void SendDetectMoveZGcode(float z,float speed)
{
    CrLogI("detect move z = %f\n", z);
    char gcodeCmd[256] = {0};
    snprintf(gcodeCmd, sizeof(gcodeCmd), "G0 Z%0.2f F%0.2f\nM400", z,speed);
    SendFuncModuleCmd(gcodeCmd);
}
/** 
 * @description: 
 * @return {*}
 * @param {char} *gcode
 */
static void DeleteGcodeTerminator(char *gcode)
{
    char *line1 = strstr(gcode, "\r\n");
    char *line2 = strstr(gcode, "\n");
    char *line3 = strstr(gcode, "\r");
    if (line1) line1[0] = '\0';
    else if (line2) line2[0] = '\0';
    else if (line3) line3[0] = '\0';
}

/**
 * @description: 
 * @return {*}
 * @param {FILE} *fd
 * @param {FlowDetectPara_t} para
 */
static int GetFlowDetectPara(FILE *fd, AiDetectPara_t *para)
{
    #define READ_LEN    1024
    char readBuff[READ_LEN] = {0};
    fseek(fd, 0, SEEK_SET);

    // 读取指令
    while (1)
    {
        // 判断是否读取成功
        if (!fgets(readBuff, READ_LEN, fd) && !feof(fd)) {
            bzero(readBuff, READ_LEN);
            continue;
        }
        // 判断文件读取结束
        if (feof(fd)) {
            return -1;
        }

        // 获取AI检测参数
        if (strstr(readBuff, "; Flow Detection Start x = ")) {
            DeleteGcodeTerminator(readBuff);
            para->start_x = atoi(readBuff + strlen("; Flow Detection Start x = "));
        }
        if (strstr(readBuff, "; Flow Detection Start y = ")) {
            DeleteGcodeTerminator(readBuff);
            para->start_y = atoi(readBuff + strlen("; Flow Detection Start y = "));
        }
        if (strstr(readBuff, "; Flow Detection End x = ")) {
            DeleteGcodeTerminator(readBuff);
            para->end_x = atoi(readBuff + strlen("; Flow Detection End x = "));
        }
        if (strstr(readBuff, "; Flow Detection End y = ")) {
            DeleteGcodeTerminator(readBuff);
            para->end_y = atoi(readBuff + strlen("; Flow Detection End y = "));
        }
        if (strstr(readBuff, "; Flow Detection interval = ")) {
            DeleteGcodeTerminator(readBuff);
            para->interval = atoi(readBuff + strlen("; Flow Detection interval = "));
        }
       
        if (strstr(readBuff, "; Flow Detection PointCount = ")) {
            DeleteGcodeTerminator(readBuff);
            para->pointCount = atoi(readBuff + strlen("; Flow Detection PointCount = "));
            
        }
        if (strstr(readBuff, "; Flow Detection Photo Start y = ")) {
            DeleteGcodeTerminator(readBuff);
            para->photo_start_y = atoi(readBuff + strlen("; Flow Detection Photo Start y = "));
            
        }
        if (strstr(readBuff, "; Flow Detection Photo Start x = ")) {
            DeleteGcodeTerminator(readBuff);
            para->photo_start_x = atoi(readBuff + strlen("; Flow Detection Photo Start x = "));
            
        }
        

        bzero(readBuff, READ_LEN);
    }
}
/**
 * @description: 
 * @return {*}
 */
//START_PRINT EXTRUDER_TEMP=220 BED_TEMP=50 //打印温度
//;Outer Wall Speed:200                     //外壁速度 mm/s
//;Outer Wall Acceleration:5000             //外壁速加度
//;Acceleration to decelerate:50            //外壁减速加速度，这个值是外壁加速度的百分比，50为外壁加速度的百分之50
//打开打印Gcode文件，获取喷嘴和热床的目标温度，写入划线Gcode
static int GetFileBedHotendTemp(char* gcodePath, double *bedtmep)
{
    #define READ_LEN   1024
    char readBuff[READ_LEN] = {0};
    char buf[READ_LEN]={0};
    char temp[256]={0};
    double extruder_temp=0;
    double bed_temp=0;
    double accel=0;
    double decel=0;
    double out_wall_speed=0;
    double max_volume_speed=0;
    double layer_height=0;
    double outer_wall_line_width=0;
    //int count=0;
    FILE *gcodeFileFd=NULL;
    FILE *fp=NULL;
    FILE *fp_tmp=NULL;

    if(!gcodePath)
        return -1;

    gcodeFileFd = fopen(gcodePath, "r");
    if(!gcodeFileFd)
        goto END;
    fseek(gcodeFileFd, 0, SEEK_SET);
    // 读取指令
    while (1)
    {
        // 判断是否读取成功
        if (!fgets(readBuff, READ_LEN, gcodeFileFd) && !feof(gcodeFileFd)) {
            bzero(readBuff, READ_LEN);
            continue;
        }
        // 判断文件读取结束
        if (feof(gcodeFileFd)) {
            break;
        }
        // 获取打印Gcode文件的热床和喷嘴目标盘温度
        // if (strstr(readBuff, "START_PRINT EXTRUDER_TEMP=")) {
        //     if(sscanf(readBuff, "START_PRINT EXTRUDER_TEMP=%lf BED_TEMP=%lf", \
        //         &extruder_temp, &bed_temp)==2){
        //         CrLogI("extruder_temp=%lf,bed_temp=%lf\n",extruder_temp,bed_temp);
        //     }
        // }else if(strstr(readBuff, ";Outer Wall Speed:")){
        if(strstr(readBuff, ";Outer Wall Speed:")){
            if(sscanf(readBuff, ";Outer Wall Speed:%lf",&out_wall_speed)==1){
                out_wall_speed=out_wall_speed*60;
                CrLogI("Outer Wall Speed=%lf\n",out_wall_speed);
            }  
        }else if(strstr(readBuff, ";Outer Wall Acceleration:")){
            if(sscanf(readBuff, ";Outer Wall Acceleration:%lf",&accel)==1){
                CrLogI("Outer Wall Acceleration=%lf\n",accel);
            }  
        }else if(strstr(readBuff,"; outer_wall_acceleration =")){
            if(sscanf(readBuff, "; outer_wall_acceleration = %lf",&accel)==1){
                CrLogI("outer_wall_acceleration=%lf\n",accel);
            }  
        }else if(strstr(readBuff, ";Acceleration to decelerate:")){
            if(sscanf(readBuff, ";Acceleration to decelerate:%lf",&decel)==1){
                decel=accel*(decel/100);
                CrLogI("Acceleration to decelerate=%lf\n",decel);
            }  
        }else if(strstr(readBuff, ";Acceleration to decelerate:")){
            if(sscanf(readBuff, ";Acceleration to decelerate:%lf",&decel)==1){
                decel=accel*(decel/100);
                CrLogI("Acceleration to decelerate=%lf\n",decel);
            }  
        }else if(strstr(readBuff, "; filament_max_volumetric_speed =")){
            if(sscanf(readBuff, "; filament_max_volumetric_speed = %lf",&max_volume_speed)==1){
                
                CrLogI("filament_max_volumetric_speed=%lf\n",max_volume_speed);
            }  
        }else if(strstr(readBuff,";Max volumetric speed:")){
            if(sscanf(readBuff, ";Max volumetric speed:%lf",&max_volume_speed)==1){
                
                CrLogI("Max volumetric speed=%lf\n",max_volume_speed);
            }  
        }else if(strstr(readBuff, "; layer_height =" ) ){
            if(sscanf(readBuff, "; layer_height = %lf",&layer_height)==1){
                
                CrLogI("layer_height=%lf\n",layer_height);
            }  
        }else if(strstr(readBuff, ";Layer Height:")){
            if(sscanf(readBuff, ";Layer Height:%lf",&layer_height)==1){
                
                CrLogI(";Layer Height=%lf\n",layer_height);
            }  
        }else if(strstr(readBuff, ";Layer height:")){
            if(sscanf(readBuff, ";Layer height:%lf",&layer_height)==1){
                
                CrLogI(";Layer height=%lf\n",layer_height);
            }  
        }else if(strstr(readBuff, "; outer_wall_line_width =")){
            if(sscanf(readBuff, "; outer_wall_line_width = %lf",&outer_wall_line_width)==1){
                CrLogI("outer_wall_line_width=%lf\n",outer_wall_line_width);
            }  
        }else if(strstr(readBuff, ";Out Wall Line Width:")){
            if(sscanf(readBuff, ";Out Wall Line Width:%lf",&outer_wall_line_width)==1){
                CrLogI("Out Wall Line Width=%lf\n",outer_wall_line_width);
            }  
        }else if(strstr(readBuff, "; outer_wall_speed =")){
            if(sscanf(readBuff, "; outer_wall_speed = %lf",&out_wall_speed)==1){
                out_wall_speed = out_wall_speed * 60;
                CrLogI("out_wall_speed=%lf\n",out_wall_speed);
            }  
        }
        bzero(readBuff, READ_LEN);
    }

    extruder_temp = GetPrinter()->current_file.nozzle_target_temp;
    bed_temp = GetPrinter()->current_file.bed_target_temp;
    
    //检查参数是否都存在，不存在的话就不支持流量检测
    if(extruder_temp<=0 || bed_temp<=0 || accel<=0 || decel<=0 || out_wall_speed<=0 || max_volume_speed<=0 || \
        outer_wall_line_width<=0 || layer_height<=0 ) {
        CrLogW("extruder_temp=%lf \nbed_temp=%lf \naccel=%lf \ndecel=%lf \nout_wall_speed=%lf \nmax_volume_speed=%lf \nouter_wall_line_width=%lf \nlayer_height=%lf",\
            extruder_temp,bed_temp,accel,decel,out_wall_speed,max_volume_speed,outer_wall_line_width,layer_height);
        goto END;
    }

    double speed = max_volume_speed / layer_height / outer_wall_line_width * 60;
    if(speed>out_wall_speed){
        speed=out_wall_speed;
    }

    if(extruder_temp<=0){
        extruder_temp=220;
    }
    if(bed_temp<=0){
        bed_temp=60;
    }
    if(accel<=0){
        accel=5000;
    }
    if(decel<=0){
        decel=2500;
    }
    if(speed<=0){
        speed=10800;
    }
    *bedtmep = bed_temp;

    char *filePath = GetFlowDetectGcodeFilePath();
    fp = fopen(filePath, "r");
    char tmpfile[256]={0};
    snprintf(tmpfile,sizeof(tmpfile),"/tmp/%s.tmp",FLOW_DETECT_GCODE_FILE_NAME);
    //打开一个临时文件
    fp_tmp = fopen(tmpfile, "w");
    if(!fp || !fp_tmp)
        goto END;

    fseek(fp, 0, SEEK_SET);
    fseek(fp_tmp, 0, SEEK_SET);

    while(1)
    {
        // 判断是否读取成功
        if (!fgets(readBuff, READ_LEN, fp) && !feof(fp)) {
            bzero(readBuff, READ_LEN);
            continue;
        }
        // 判断文件读取结束
        if (feof(fp)) {
            break;
        }
        if (strstr(readBuff,"M109 S") ) {
            snprintf(buf,sizeof(buf),"M109 S%0.1lf\r\n",extruder_temp);
            fputs(buf, fp_tmp);
        } else if(strstr(readBuff,"M190 S")) {
            snprintf(buf,sizeof(buf),"M190 S%0.1lf\r\n",bed_temp);
            fputs(buf, fp_tmp);
        } else if(strstr(readBuff,"M140 S")) {
            snprintf(buf,sizeof(buf),"M140 S%0.1lf\r\n",bed_temp);
            fputs(buf, fp_tmp);
        }else if(strstr(readBuff,"SET_VELOCITY_LIMIT ACCEL=")) {
            snprintf(buf,sizeof(buf),"SET_VELOCITY_LIMIT ACCEL=%0.0lf\r\n",accel);
            fputs(buf, fp_tmp);
        }else if(strstr(readBuff,"SET_VELOCITY_LIMIT ACCEL_TO_DECEL=")) {
            snprintf(buf,sizeof(buf),"SET_VELOCITY_LIMIT ACCEL_TO_DECEL=%0.0lf\r\n",decel);
            fputs(buf, fp_tmp);
        }else{
            char *move_str = strstr(readBuff,"F10800");
            if(move_str) {
                int p=move_str-readBuff;
                memcpy(temp,readBuff,p);
                snprintf(buf,sizeof(buf),"%s F%0.0lf\r\n",temp,speed);
                fputs(buf, fp_tmp);
            }else {
                fputs(readBuff, fp_tmp);
            }
        }
        
        bzero(temp,sizeof(temp));
        bzero(buf,sizeof(buf));
    }
    if (fp) fclose(fp);
    if (fp_tmp) fclose(fp_tmp);
    if (gcodeFileFd) fclose(gcodeFileFd);
    //remove(filePath);
    //rename(tmpfile, filePath);
    return 0;

END:
    if (fp) fclose(fp);
    if (fp_tmp) fclose(fp_tmp);
    if (gcodeFileFd) fclose(gcodeFileFd);
    return -1;
}


static int AiFlowDetectRun_Quick_Step1(void)
{
     // 初始化环境
    CrLogI("ai flow detect test step1 run");
    int res = -1;
    int aiServerSocket = -1;
    //double bedtemp=0;
    int scan_speed=800;
    int time_interval=FLOW_SCAN_TIME_INTERVAL;
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists!!!\n");
        return res;
    }
#endif
    ClearFuncModuleRecvList();
    // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z)
    {
        SendFuncModuleCmd("CX_ROUGH_G28 EXTRUDER_TEMP=220 BED_TEMP=60");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
            usleep(10 * 1000);
        } while (1);
        SendFuncModuleCmd("CX_NOZZLE_CLEAR");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        // 细归零
        SendFuncModuleCmd("ACCURATE_G28");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
    }
    // 读取划线gcode文件
    char *filePath = GetFlowDetectGcodeFilePath();
    FILE *gcodeFileFd = fopen(filePath, "r");
    if (gcodeFileFd == NULL) {
        CrLogW("gcode file open failed = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }
    // 获取AI检测参数
    AiDetectPara_t aiDetectPara = {0};
    GetFlowDetectPara(gcodeFileFd, &aiDetectPara);
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if(laserCfg.x_offset==0 || laserCfg.y_offset==0){
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }

    float curLocationX=0.0;
    float curLocationY=0.0;
    float curLocationZ=0.0;
    // 移动到检测起点
    curLocationX = aiDetectPara.start_x - laserCfg.x_offset;
    curLocationY = aiDetectPara.start_y - laserCfg.y_offset;
    curLocationZ = laserCfg.z_offset;
    
    // 判断任务是否取消
    if (appFunModuleRun) {
        // 连接AI服务
        aiServerSocket = GetAiServerSocket();
        if (aiServerSocket <= 0) {
            CrLogW("connect ai server fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //设置相机坐标系
        if (AiServerCloseFlow(aiServerSocket) != 0) {
            CrLogW("set laser flow close fail\n");
            goto THREAD_RUN_CANCEL;
        }

        //设置相机坐标系
        if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
            CrLogW("set laser coor fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //设置稀疏档位
        if (AiServerLaserPointCloudLevel(aiServerSocket,0x02) != 0) {
            CrLogW("set laser point cloud level fail\n");
            goto THREAD_RUN_CANCEL;
        }
        
        //设置并行取流 0x01并行，0x00串行
        if (AiServerSetTakeOver(aiServerSocket,0x01) != 0) {
            CrLogW("set laser coor fail\n");
            goto THREAD_RUN_CANCEL;
        }
    }
    //扫描床面
    //int talbe_count=0;
    int table_num=0;
    char table_key[64]={0};
    uint64_t table_last_ms=0;
    json_object *saveTableObj=json_object_new_object();
    //移动到起点
    SendDetectMoveZGcode(curLocationZ, 600);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    SendDetectMoveXYGcode(curLocationX, curLocationY, 12000);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
   
    //因为加热会导致热床形变，所以先加热热床再扫描床面
    char bedTempCmd[64]={0};
    snprintf(bedTempCmd,sizeof(bedTempCmd),"M190 S%0.1f",60.0);
    SendFuncModuleCmd(bedTempCmd);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }

    // 开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set ai server open flow fail\n");
        goto THREAD_RUN_CANCEL;
    }
    usleep(500*1000);
    //读取一帧点云丢掉，因为第一帧点云会非常慢
    char cloud[10*1024]={0};
    GetAiServerPointCloud(aiServerSocket, cloud,2000);
    
    //移动到终点并开始读点云
    SendDetectMoveXYGcode(curLocationX, aiDetectPara.end_y - laserCfg.y_offset, scan_speed);
    //记录开始移动的时间戳
    
    struct timeval tv_table_start;
    gettimeofday(&tv_table_start, NULL);
    uint64_t table_start_ms=0;
    table_start_ms = (tv_table_start.tv_sec * 1000000 + tv_table_start.tv_usec) / 1000;

    while(appFunModuleRun){

        struct timeval tv_table_now;
        gettimeofday(&tv_table_now, NULL);
        uint64_t table_now_ms=0;
        table_now_ms = (tv_table_now.tv_sec * 1000000 + tv_table_now.tv_usec) / 1000;

        //每隔250ms读取一次点云
        if(table_now_ms-table_last_ms >= time_interval){
            table_last_ms = table_now_ms;
            //CrLogI("scan[%d] now_ms-last_ms=%ld\n",scan_count++,now_ms-last_ms);
            char pointCloud[100 * 1024] = {0};
            struct timeval tv_table_read;
            gettimeofday(&tv_table_read, NULL);
            uint64_t table_read_ms=0;
            table_read_ms = (tv_table_read.tv_sec * 1000000 + tv_table_read.tv_usec) / 1000;

            //CrLogW("tableScan[%d] read_ms=%ld\n",talbe_count++,table_read_ms-table_start_ms);
            //读取点云
            if (GetAiServerPointCloud(aiServerSocket, pointCloud, 2000) != 0) {
                CrLogW("get point cloud fail\n");
                json_object *PointArray = json_object_new_array();
                snprintf(table_key,sizeof(table_key),"table%d",table_num);
                table_num++;
                json_object_object_add(saveTableObj,table_key,PointArray);
            
            }else{
                json_object *pointCloudObj = json_tokener_parse(pointCloud);
                //CrLogI("pointCloud length =%ld\n",json_object_array_length(pointCloudObj));
                for (int i = 0; i < json_object_array_length(pointCloudObj); i++)
                {
                    // 获取点数据
                    json_object *pointObj = json_object_array_get_idx(pointCloudObj, i);
                    // 纠正Y坐标
                    json_object *value1Obj = json_object_array_get_idx(pointObj, 1);
                    int valueY=0;
#ifdef USE_CAM_COOR 
                    valueY = aiDetectPara.start_y*1000 + (table_read_ms-table_start_ms) * scan_speed/60 + json_object_get_int(value1Obj) ;
#else
                    valueY = aiDetectPara.start_y*1000 + (table_read_ms-table_start_ms) * scan_speed/60 - json_object_get_int(value1Obj) ;
#endif              
                    json_object_set_int(value1Obj, valueY);
                }
                // 保存点数据
                snprintf(table_key,sizeof(table_key),"table%d",table_num);
                json_object_object_add(saveTableObj,table_key,pointCloudObj);
                table_num++;
            }  
        }else{
            usleep(500);
        }
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
    }
   
    // 点云数据保存文件
    if (appFunModuleRun) json_object_to_file_ext(GetTempScanFlowTbalePoint(), saveTableObj, JSON_C_TO_STRING_PLAIN);
    json_object_put(saveTableObj);

    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
        goto THREAD_RUN_CANCEL;
    }
    
    //移动到等待加热位置
    SendDetectMoveXYGcode(0, 0,12000);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    SendDetectMoveZGcode(0.1,600);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }

    //文件回到开始位置
    fseek(gcodeFileFd, 0, SEEK_SET);
    if(SendDrawFlowLineGcode(gcodeFileFd) != 0) {
        CrLogW("gcode file invalid = %s\n", tmpfile);
        goto THREAD_RUN_CANCEL;
    }
    

    SendFuncModuleCmd("M104 S170");
    while(appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }

    //移动到等待加热位置
    SendDetectMoveXYGcode(10, 10,12000);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    SendDetectMoveZGcode(0.1,600);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }

THREAD_RUN_CANCEL:
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }

    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);

    CrLogI("ai flow detect test step1 end\n");
    return res;
}

static int AiFlowDetectRun_Quick_Step2(int count_num)
{
    CrLogI("ai flow detect test step2 run");
    int res = -1;
    int aiServerSocket = -1;
    //double bedtemp=0;
    int scan_speed=800;
    int time_interval=FLOW_SCAN_TIME_INTERVAL;
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists!!!\n");
        return res;
    }
#endif

    // 读取划线gcode文件
    char *filePath = GetFlowDetectGcodeFilePath();
    FILE *gcodeFileFd = fopen(filePath, "r");
    if (gcodeFileFd == NULL) {
        CrLogW("gcode file open failed = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }
    // 获取AI检测参数
    AiDetectPara_t aiDetectPara = {0};
    GetFlowDetectPara(gcodeFileFd, &aiDetectPara);
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if(laserCfg.x_offset==0 || laserCfg.y_offset==0){
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }

    float curLocationX=0.0;
    float curLocationY=0.0;
    float curLocationZ=0.0;
    // 移动到检测起点
    curLocationX = aiDetectPara.start_x - laserCfg.x_offset;
    curLocationY = aiDetectPara.start_y - laserCfg.y_offset;
    curLocationZ = laserCfg.z_offset;
    
    // 判断任务是否取消
    if (appFunModuleRun) {
        // 连接AI服务
        aiServerSocket = GetAiServerSocket();
        if (aiServerSocket <= 0) {
            CrLogW("connect ai server fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //设置相机坐标系
        if (AiServerCloseFlow(aiServerSocket) != 0) {
            CrLogW("set laser flow close fail\n");
            goto THREAD_RUN_CANCEL;
        }

        //设置相机坐标系
        if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
            CrLogW("set laser coor fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //设置稀疏档位
        if (AiServerLaserPointCloudLevel(aiServerSocket,0x02) != 0) {
            CrLogW("set laser point cloud level fail\n");
            goto THREAD_RUN_CANCEL;
        }
        
        //设置并行取流 0x01并行，0x00串行
        if (AiServerSetTakeOver(aiServerSocket,0x01) != 0) {
            CrLogW("set laser coor fail\n");
            goto THREAD_RUN_CANCEL;
        }
    }

    //int scan_count=0;
    int num=0;
    int len = 0;
    char key[64]={0};
    char buff[256]={0};
    uint64_t last_ms=0;
    json_object *savePointObj=json_object_new_object();
    //移动到起点
    SendDetectMoveZGcode(curLocationZ,600);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    SendDetectMoveXYGcode(curLocationX, curLocationY,12000);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    // 开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set ai server open flow fail\n");
        goto THREAD_RUN_CANCEL;
    }
    usleep(500*1000);
    //读取一帧点云丢掉，因为第一帧点云会非常慢
    char cloud1[10*1024]={0};
    GetAiServerPointCloud(aiServerSocket, cloud1, 2000);

    SendDetectMoveXYGcode(curLocationX, aiDetectPara.end_y - laserCfg.y_offset, scan_speed);
    //记录开始移动的时间戳
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    uint64_t start_ms=0;
    start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;

    while(appFunModuleRun){
        struct timeval tv_now;
        gettimeofday(&tv_now, NULL);
        uint64_t now_ms=0;
        now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

        //每隔250ms读取一次点云
        if(now_ms-last_ms>=time_interval){
            last_ms=now_ms;
            char pointCloud[100 * 1024] = {0};
            
            struct timeval tv_read;
            gettimeofday(&tv_read, NULL);
            uint64_t read_ms=0;
            read_ms = (tv_read.tv_sec * 1000000 + tv_read.tv_usec) / 1000;

            //CrLogI("lineScan[%d] read_ms=%ld\n",scan_count++,read_ms-start_ms);
            //读取点云
            if (GetAiServerPointCloud(aiServerSocket, pointCloud,2000) != 0) {
                CrLogW("get point cloud fail\n");
                json_object *PointArray = json_object_new_array();
                snprintf(key,sizeof(key),"scan%d",num);
                num++;
                json_object_object_add(savePointObj,key,PointArray);
            
            }else{
                json_object *pointCloudObj = json_tokener_parse(pointCloud);
                CrLogI("pointCloud length =%d\n",json_object_array_length(pointCloudObj));
                for (int i = 0; i < json_object_array_length(pointCloudObj); i++)
                {
                    // 获取点数据
                    json_object *pointObj = json_object_array_get_idx(pointCloudObj, i);

                    // 纠正Y坐标
                    json_object *value1Obj = json_object_array_get_idx(pointObj, 1);
                    int valueY=0;
#ifdef USE_CAM_COOR 
                    valueY = aiDetectPara.start_y*1000 + (read_ms-start_ms) * scan_speed/60 + json_object_get_int(value1Obj) ;
#else
                    valueY = aiDetectPara.start_y*1000 + (read_ms-start_ms) * scan_speed/60 - json_object_get_int(value1Obj) ;
#endif              
                    json_object_set_int(value1Obj, valueY);
                }
                // 保存点数据
                snprintf(key,sizeof(key),"scan%d",num);
                json_object_object_add(savePointObj,key,pointCloudObj);
                num++;
            }  
        }else{
            usleep(500);
        }
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
    }
    
    char saveFile[256]={0};
    snprintf(saveFile,sizeof(saveFile),"%s%d",GetTempScanFlowLinePoint(),count_num);
    // 点云数据保存文件
    if (appFunModuleRun) json_object_to_file_ext(saveFile, savePointObj, JSON_C_TO_STRING_PLAIN);
    json_object_put(savePointObj);
    //同步文件
    char cmd[128] = {0};
    snprintf(cmd, sizeof(cmd), "sync");
    // 调用系统命令
    char sysRes[512] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes))){
        CrLogW("system fail! res = %s\n", sysRes);
    }   
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }

    //移动到等待加热位置
    SendDetectMoveXYGcode(0, 0,12000);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    SendDetectMoveZGcode(0.1,600);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }

    // 判断任务是否取消
    char best_line[64]={0};
    if (appFunModuleRun) {
        // 调用AI获取流量检测结果
        if (GetAiServerFlowDetectNew(aiServerSocket,GetTempScanFlowTbalePoint(),saveFile,best_line) != 0) {
            CrLogI("get select line fail\n");    
            goto THREAD_RUN_CANCEL;
        }
        else{
            CrLogI("best_line = %s\n", best_line);
            //发送结果给UI
            char buff[256]={0};
            snprintf(buff,sizeof(buff),"5 %d %s",count_num,best_line);
            int len = strlen(buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
            res = 0;
            goto END;
        }
    }
THREAD_RUN_CANCEL:
    //发送结果给UI
    snprintf(buff,sizeof(buff),"5 %d %s",count_num,"error");
    len = strlen(buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
END:
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }

    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);

    CrLogI("ai flow detect test end\n");
    return res;
}
/**
 * @description: 
 * @return {*}
 */
static int AiFlowDetectRun_Quick(bool syncState, char *result)
{
    // 初始化环境
    CrLogI("ai flow detect quick run");
    int res = -1;
    int aiServerSocket = -1;
    double bedtemp=0;
    int scan_speed=800;
    int time_interval=FLOW_SCAN_TIME_INTERVAL;
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists!!!\n");
        return res;
    }
#endif
    ClearFuncModuleRecvList();
    if (syncState) UpdataWithSelfTest(PREPARE_STEP_FLOW_SCAN_TABLE);

    // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z)
    {
        // 打印机归零
        SendFuncModuleCmd("G28");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
    }

    //获取打印任务的gcode，替换划线gcode的喷嘴温度和热床温度
    char* gcode = GetPrinter()->current_file.fileName;
    //char* gcode = "/home/adams/gcode_files/综合性能模型_K1_0.4_1h56m-V0.3.gcode";
    if(GetFileBedHotendTemp(gcode,&bedtemp)){
        CrLogW("parse gcode fail!!!\n");
        return res;
    }

    // 读取划线gcode文件
    char tmpfile[256]={0};
    snprintf(tmpfile,sizeof(tmpfile),"/tmp/%s.tmp",FLOW_DETECT_GCODE_FILE_NAME);
    FILE *gcodeFileFd = fopen(tmpfile, "r");
    if (gcodeFileFd == NULL) {
        CrLogW("gcode file open failed = %s\n", tmpfile);
        goto THREAD_RUN_CANCEL;
    }
    // 获取AI检测参数
    AiDetectPara_t aiDetectPara = {0};
    GetFlowDetectPara(gcodeFileFd, &aiDetectPara);
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if(laserCfg.x_offset==0 || laserCfg.y_offset==0){
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }

    float curLocationX=0.0;
    float curLocationY=0.0;
    float curLocationZ=0.0;
    // 移动到检测起点
    curLocationX = aiDetectPara.start_x - laserCfg.x_offset;
    curLocationY = aiDetectPara.start_y - laserCfg.y_offset;
    curLocationZ = laserCfg.z_offset;
    
    // 判断任务是否取消
    if (appFunModuleRun) {
        // 连接AI服务
        aiServerSocket = GetAiServerSocket();
        if (aiServerSocket <= 0) {
            CrLogW("connect ai server fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //关流
        if (AiServerCloseFlow(aiServerSocket) != 0) {
            CrLogW("set laser flow close fail\n");
            goto THREAD_RUN_CANCEL;
        }

        //设置相机坐标系
        if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
            CrLogW("set laser coor fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //设置稀疏档位
        if (AiServerLaserPointCloudLevel(aiServerSocket,0x02) != 0) {
            CrLogW("set laser point cloud level fail\n");
            goto THREAD_RUN_CANCEL;
        }
        
        //设置并行取流 0x01并行，0x00串行
        if (AiServerSetTakeOver(aiServerSocket,0x01) != 0) {
            CrLogW("set laser coor fail\n");
            goto THREAD_RUN_CANCEL;
        }
    }
    //扫描床面
    //int talbe_count=0;
    int table_num=0;
    char table_key[64]={0};
    uint64_t table_last_ms=0;
    json_object *saveTableObj=json_object_new_object();
    //移动到起点
    SendDetectMoveZGcode(curLocationZ, 600);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    SendDetectMoveXYGcode(curLocationX, curLocationY, 12000);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
   
    //因为加热会导致热床形变，所以先加热热床再扫描床面
    char bedTempCmd[64]={0};
    snprintf(bedTempCmd,sizeof(bedTempCmd),"M190 S%0.1lf",bedtemp);
    SendFuncModuleCmd(bedTempCmd);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }

    // 开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set ai server open flow fail\n");
        goto THREAD_RUN_CANCEL;
    }
    usleep(500*1000);
    //读取一帧点云丢掉，因为第一帧点云会非常慢
    char cloud[10*1024]={0};
    GetAiServerPointCloud(aiServerSocket, cloud,2000);
    
    //移动到终点并开始读点云
    SendDetectMoveXYGcode(curLocationX, aiDetectPara.end_y - laserCfg.y_offset, scan_speed);
    //记录开始移动的时间戳
    
    struct timeval tv_table_start;
    gettimeofday(&tv_table_start, NULL);
    uint64_t table_start_ms=0;
    table_start_ms = (tv_table_start.tv_sec * 1000000 + tv_table_start.tv_usec) / 1000;

    while(appFunModuleRun){

        struct timeval tv_table_now;
        gettimeofday(&tv_table_now, NULL);
        uint64_t table_now_ms=0;
        table_now_ms = (tv_table_now.tv_sec * 1000000 + tv_table_now.tv_usec) / 1000;

        //每隔250ms读取一次点云
        if(table_now_ms-table_last_ms >= time_interval){
            table_last_ms = table_now_ms;
            //CrLogI("scan[%d] now_ms-last_ms=%ld\n",scan_count++,now_ms-last_ms);
            char pointCloud[100 * 1024] = {0};
            struct timeval tv_table_read;
            gettimeofday(&tv_table_read, NULL);
            uint64_t table_read_ms=0;
            table_read_ms = (tv_table_read.tv_sec * 1000000 + tv_table_read.tv_usec) / 1000;

            //CrLogW("tableScan[%d] read_ms=%ld\n",talbe_count++,table_read_ms-table_start_ms);
            //读取点云
            if (GetAiServerPointCloud(aiServerSocket, pointCloud, 2000) != 0) {
                CrLogW("get point cloud fail\n");
                json_object *PointArray = json_object_new_array();
                snprintf(table_key,sizeof(table_key),"table%d",table_num);
                table_num++;
                json_object_object_add(saveTableObj,table_key,PointArray);
            
            }else{
                json_object *pointCloudObj = json_tokener_parse(pointCloud);
                //CrLogI("pointCloud length =%ld\n",json_object_array_length(pointCloudObj));
                for (int i = 0; i < json_object_array_length(pointCloudObj); i++)
                {
                    // 获取点数据
                    json_object *pointObj = json_object_array_get_idx(pointCloudObj, i);
                    // 纠正Y坐标
                    json_object *value1Obj = json_object_array_get_idx(pointObj, 1);
                    int valueY=0;
#ifdef USE_CAM_COOR 
                    valueY = aiDetectPara.start_y*1000 + (table_read_ms-table_start_ms) * scan_speed/60 + json_object_get_int(value1Obj) ;
#else
                    valueY = aiDetectPara.start_y*1000 + (table_read_ms-table_start_ms) * scan_speed/60 - json_object_get_int(value1Obj) ;
#endif              
                    json_object_set_int(value1Obj, valueY);
                }
                // 保存点数据
                snprintf(table_key,sizeof(table_key),"table%d",table_num);
                json_object_object_add(saveTableObj,table_key,pointCloudObj);
                table_num++;
            }  
        }else{
            usleep(500);
        }
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
    }
   
    // 点云数据保存文件
    if (appFunModuleRun) json_object_to_file_ext(GetTempScanFlowTbalePoint(), saveTableObj, JSON_C_TO_STRING_PLAIN);
    json_object_put(saveTableObj);

    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
        goto THREAD_RUN_CANCEL;
    }
    
    if (syncState) UpdataWithSelfTest(PREPARE_STEP_FLOW_PRINT_LINE);
    //移动到等待加热位置
    SendDetectMoveXYGcode(0, 0,12000);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    SendDetectMoveZGcode(0.2,600);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }

    //文件回到开始位置
    fseek(gcodeFileFd, 0, SEEK_SET);
    if(SendDrawFlowLineGcode(gcodeFileFd) != 0) {
        CrLogW("gcode file invalid = %s\n", tmpfile);
        goto THREAD_RUN_CANCEL;
    }
    //读取划线指令
    // if (SendNextDrawLineGcode(gcodeFileFd) != 0) {
    //     CrLogW("gcode file invalid = %s\n", tmpfile);
    //     goto THREAD_RUN_CANCEL;
    // }
    // // 开始划线
    // while (appFunModuleRun)
    // {
    //     // 获取前一帧指令响应
    //     CmdSyncRecv_t recv = GetFuncModuleRecv();
    //     if (recv.mtype != 0) {
    //         // 读取划线指令
    //         if (SendNextDrawLineGcode(gcodeFileFd) != 0) {
    //             CrLogI("draw line finish");
    //             break;
    //         }
    //     }
    //     usleep(300);
    // }

    //降温
    if (syncState) UpdataWithSelfTest(PREPARE_STEP_FLOW_COOL_DOWN);
    // 保存当前打印状态
    int nozzleTargetTemp[NOZZLE_TEMP_SIZE] = {0}; // 喷嘴目标温度
    int fanState[MULTI_FAN_SIZE] = {0}; // 风扇状态
    
    for (int i = 0; i < NOZZLE_TEMP_SIZE; i++) {
        nozzleTargetTemp[i] = GetPrintState().nozzleMaxTemp[i];
        CrLogI("nozzleTargetTemp[%d] = %d", i, nozzleTargetTemp[i]);
    }
    for (int i = 0; i < MULTI_FAN_SIZE; i++) {
        fanState[i] = GetPrintState().fanState[i];
        CrLogI("fanState[%d] = %d", i, fanState[i]);
    }
    CrLogI("Save parameters complete\n");
    
    // 打开风扇快速降温
    SendFuncModuleCmd("M106 P0 S255");
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);

    SendFuncModuleCmd("M106 P2 S255");
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);

    // 喷嘴移动到暂停位置，降温
    SendFuncModuleCmd("FIRST_FLOOR_PAUSE_POSITION");
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);

    // 等待温度
    sleep(1);
    while (1) {
        if (GetPrintState().nozzleCurTemp[NOZZLE_TEMP]/100 > (GetPrintState().nozzleMaxTemp[NOZZLE_TEMP]/100 - 5) &&
            GetPrintState().nozzleCurTemp[NOZZLE_TEMP]/100 < (GetPrintState().nozzleMaxTemp[NOZZLE_TEMP]/100 + 5)
        ) break;
        usleep(10 * 1000);
    }

    // 关闭风扇
    SendFuncModuleCmd("M106 P0 S0");
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);

    SendFuncModuleCmd("M106 P2 S0");
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);



    //扫描打印线
    if (syncState) UpdataWithSelfTest(PREPARE_STEP_FLOW_SCAN_MODEL);
    //int scan_count=0;
    int num=0;
    char key[64]={0};
    uint64_t last_ms=0;
    json_object *savePointObj=json_object_new_object();
    //移动到起点
    SendDetectMoveXYGcode(curLocationX, curLocationY,12000);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    SendDetectMoveZGcode(curLocationZ,600);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    
    // 开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set ai server open flow fail\n");
        goto THREAD_RUN_CANCEL;
    }
    usleep(500*1000);
    //读取一帧点云丢掉，因为第一帧点云会非常慢
    char cloud1[10*1024]={0};
    GetAiServerPointCloud(aiServerSocket, cloud1,2000);

    SendDetectMoveXYGcode(curLocationX, aiDetectPara.end_y - laserCfg.y_offset, scan_speed);
    //记录开始移动的时间戳
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    uint64_t start_ms=0;
    start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;

    while(appFunModuleRun){
        struct timeval tv_now;
        gettimeofday(&tv_now, NULL);
        uint64_t now_ms=0;
        now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

        //每隔250ms读取一次点云
        if(now_ms-last_ms>=time_interval){
            last_ms=now_ms;
            char pointCloud[100 * 1024] = {0};
            
            struct timeval tv_read;
            gettimeofday(&tv_read, NULL);
            uint64_t read_ms=0;
            read_ms = (tv_read.tv_sec * 1000000 + tv_read.tv_usec) / 1000;
            //CrLogI("lineScan[%d] read_ms=%ld\n",scan_count++,read_ms-start_ms);
            //读取点云
            if (GetAiServerPointCloud(aiServerSocket, pointCloud, 2000) != 0) {
                CrLogW("get point cloud fail\n");
                json_object *PointArray = json_object_new_array();
                snprintf(key,sizeof(key),"scan%d",num);
                num++;
                json_object_object_add(savePointObj,key,PointArray);
            
            }else{
                json_object *pointCloudObj = json_tokener_parse(pointCloud);
                CrLogI("pointCloud length =%d\n",json_object_array_length(pointCloudObj));
                for (int i = 0; i < json_object_array_length(pointCloudObj); i++)
                {
                    // 获取点数据
                    json_object *pointObj = json_object_array_get_idx(pointCloudObj, i);

                    // 纠正Y坐标
                    json_object *value1Obj = json_object_array_get_idx(pointObj, 1);
                    int valueY=0;
#ifdef USE_CAM_COOR 
                    valueY = aiDetectPara.start_y*1000 + (read_ms-start_ms) * scan_speed/60 + json_object_get_int(value1Obj) ;
#else
                    valueY = aiDetectPara.start_y*1000 + (read_ms-start_ms) * scan_speed/60 - json_object_get_int(value1Obj) ;
#endif              
                    json_object_set_int(value1Obj, valueY);
                }
                // 保存点数据
                snprintf(key,sizeof(key),"scan%d",num);
                json_object_object_add(savePointObj,key,pointCloudObj);
                num++;
            }  
        }else{
            usleep(500);
        }
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
    }
    
    // 点云数据保存文件
    if (appFunModuleRun) json_object_to_file_ext(GetTempScanFlowLinePoint(), savePointObj, JSON_C_TO_STRING_PLAIN);
    json_object_put(savePointObj);
    //同步文件
    char cmd[128] = {0};
    snprintf(cmd, sizeof(cmd), "sync");
    // 调用系统命令
    char sysRes[512] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes))){
        CrLogW("system fail! res = %s\n", sysRes);
    }   
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }

    if (syncState) UpdataWithSelfTest(PREPARE_STEP_FLOW_AI_CALCULATE);
    //移动到等待加热位置
    SendDetectMoveXYGcode(0, 0,12000);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    SendDetectMoveZGcode(0.2,600);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }

    // 判断任务是否取消
    if (appFunModuleRun) {
        // 调用AI获取流量检测结果
        if (GetAiServerFlowDetectNew(aiServerSocket,GetTempScanFlowTbalePoint(),GetTempScanFlowLinePoint(),result) != 0) {
            CrLogI("get select line fail\n");
            res = 0;
        }
        else res = 0;
    }
    
THREAD_RUN_CANCEL:
    //设置稀疏档位,全点云
    if (AiServerLaserPointCloudLevel(aiServerSocket,0x00) != 0) {
        CrLogW("set laser point cloud level fail\n");
    }
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }

    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);

    CrLogI("ai flow detect quick end\n");
    return res;
}
/**
 * @description: 
 * @return {*}
 */
static int AiFlowDetectTakePhotoRun(void)
{
    // 初始化环境
    CrLogI("ai flow detect take photo run");
    int res = 0;
    int aiServerSocket = -1;
    double bedtmep=0;
    double curLocationX=0.0;
    double curLocationY=0.0;
    double curLocationZ=0.0;
    char image1[256]={0};
    int num=0;

#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists!!!\n");
        return res;
    }
#endif
    ClearFuncModuleRecvList();

    // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z)
    {
        // 打印机归零
        SendFuncModuleCmd("G28");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
    }
 

    //获取打印任务的gcode，替换划线gcode的喷嘴温度和热床温度
    char* gcode = GetPrinter()->current_file.fileName;
    if(GetFileBedHotendTemp(gcode,&bedtmep)){
        CrLogW("parse gcode fail!!!\n");
        return res;
    }
   
    // 读取划线gcode文件
    char filePath[256]={0};
    snprintf(filePath,sizeof(filePath),"/tmp/%s.tmp",FLOW_DETECT_GCODE_FILE_NAME);
    FILE *gcodeFileFd = fopen(filePath, "r");
    if (gcodeFileFd == NULL) {
        CrLogW("gcode file open failed = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }

    //文件回到开始位置
    fseek(gcodeFileFd, 0, SEEK_SET);
    // 开始划线
    if(SendDrawFlowLineGcode(gcodeFileFd) != 0) {
        CrLogW("gcode file invalid = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }

    // 获取AI检测参数
    AiDetectPara_t aiDetectPara = {0};
    GetFlowDetectPara(gcodeFileFd, &aiDetectPara);

    // 获取激光结果偏移
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if ((laserCfg.x_offset > -0.0001 && laserCfg.x_offset < 0.0001) &&
        (laserCfg.y_offset > -0.0001 && laserCfg.y_offset < 0.0001))
    {
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }
  
    
    // 移动到检测起点
    curLocationX = aiDetectPara.photo_start_x - laserCfg.x_offset;
    curLocationY = aiDetectPara.photo_start_y - laserCfg.y_offset;
    curLocationZ = laserCfg.z_offset;

    // 判断任务是否取消
    if (appFunModuleRun) {
        // 连接AI服务
        aiServerSocket = GetAiServerSocket();
        if (aiServerSocket <= 0) {
            CrLogW("connect ai server fail\n");
            goto THREAD_RUN_CANCEL;
        }

        //设置相机坐标系
        if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
            CrLogW("set laser coor fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //设置曝光参数
        AiServerSetExposure(aiServerSocket,3500);
        //设置曝光参数
        AiServerSetGain(aiServerSocket,2000);

    }

    //移动到起点
    SendDetectMoveZGcode(curLocationZ, 600);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }

    while(appFunModuleRun){
        CrLogI("curLocationY=%lf\n",curLocationY);
        SendDetectMoveXYGcode(curLocationX, curLocationY, 12000);
        while(appFunModuleRun){
            // 采集床板数据
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) {
                break;
            }
            usleep(500);
        }
        curLocationY+=aiDetectPara.interval;
        
        int image_size=0;
        if(appFunModuleRun){
            //开灯
            res = AiServerOpenLight(aiServerSocket,true);
            if(res){
                CrLogW("[machine test]open light fail\n");
                goto THREAD_RUN_CANCEL;
            }
            //抓拍一张IR图,保存格式为JPG 
            res = AiServerCapIrImage(aiServerSocket,2,0,&image_size);
            if(res){
                CrLogW("[machine test]capture image fail\n");
                goto THREAD_RUN_CANCEL;
            }
        }
        //获取IR图写到路径文件中
       
        if(image_size>0 && appFunModuleRun){
            //判断保存图片的文件夹是否存在
            if (access(GetUserAiImageDirPtah(), F_OK) != 0)
            {
                char cmd[128] = {0};
                snprintf(cmd, sizeof(cmd), "mkdir -p '%s'", GetUserAiImageDirPtah());
                // 调用系统命令
                char sysRes[512] = {0};
                if (!PopenSystem(cmd, sysRes, sizeof(sysRes))){
                    CrLogW("system fail! res = %s\n", sysRes);
                }       
            }
            //从模组中获取图片保存在本地
            snprintf(image1,sizeof(image1),"%s/%s%d.jpg",GetUserAiImageDirPtah(),"FlowIrImage",num);
            CrLogI("%s\n",image1);
            res = AiServerGetIrImage(aiServerSocket,image1,image_size);
            if(res){
                CrLogI("[machine test]get image fail\n");
                goto THREAD_RUN_CANCEL;
            }
           
        }
      
        //关灯
        res = AiServerOpenLight(aiServerSocket,false);
        if(res){
            CrLogW("[machine test]open light fail\n");
            goto THREAD_RUN_CANCEL;
        }
        num++;
        if(curLocationY > aiDetectPara.end_y - laserCfg.y_offset)
            break;
    }

    
THREAD_RUN_CANCEL:
    //设置曝光参数
    AiServerSetExposure(aiServerSocket,1000);
    //设置曝光参数
    AiServerSetGain(aiServerSocket,1000);
    //关灯
    res = AiServerOpenLight(aiServerSocket,false);
    if(res){
        CrLogW("[machine test]open light fail\n");
    }
    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);

    CrLogI("ai flow detect take photo end\n");
    return res;
}
/*********************************************************
 ******************** 激光标定 *************************
 *********************************************************/
/**
 * @description: 
 * @return {*}
 */
static int LaserCalibrationRun(void)
{
    CrLogI("laser calibration run\n");
    int res = -1;
    int aiServerSocket = -1;

#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif
    ClearFuncModuleRecvList();

    // 获取标定贴纸偏移
    LaserConfig_t tickerOffset = GetSavesTickerOffset();
    if ((tickerOffset.x_offset > -0.0001 && tickerOffset.x_offset < 0.0001) &&
        (tickerOffset.y_offset > -0.0001 && tickerOffset.y_offset < 0.0001))
    {
        tickerOffset.x_offset=CALI_X_OFFSET;
        tickerOffset.y_offset=CALI_Y_OFFSET;
        tickerOffset.z_offset = CALI_Z_OFFSET;
    }
    
    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogW("connect ai server fail\n");
        goto THREAD_RUN_CANCEL;
    }   

    // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z)
    {
        // 打印机归零
        SendFuncModuleCmd("G28");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
    }

    //关机器LED灯
    // if (appFunModuleRun ) {
    //     SendLightGcode(0);
    //     while (appFunModuleRun)
    //     {
    //         // 获取前一帧指令响应
    //         CmdSyncRecv_t recv = GetFuncModuleRecv();
    //         if (recv.mtype != 0) break;
    //         usleep(100 * 1000);
    //     }
    // }
   
    if (appFunModuleRun) {
        // 关流
        if (AiServerCloseFlow(aiServerSocket) != 0) {
            CrLogW("set ai server close flow fail\n");
            goto THREAD_RUN_CANCEL;
        } 
        //关灯
        if (AiServerOpenLight(aiServerSocket,false) != 0) {
            CrLogW("set ai server close light fail\n");
            goto THREAD_RUN_CANCEL;
        }
    }
   
   
    int stepcount=0;
    float y_offset=tickerOffset.y_offset;
    while(appFunModuleRun){
        //移动到标定板位置
        SendDetectMoveXYGcode(tickerOffset.x_offset, y_offset, 8000); 
        //获取前一帧指令响应
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        SendDetectMoveZGcode(tickerOffset.z_offset, 600); 
        //获取前一帧指令响应
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        usleep(200 * 1000);

        //尝试10次
        if(stepcount++ >10){
            CrLogI("set ai server calibration fail\n");
            res = -1;
            goto THREAD_RUN_CANCEL;
        }
        //设定标定步骤1
        if(AiServerLaserCali(aiServerSocket,1)!=0){
            //如果标定失败，则前5次往Y轴正方向偏移，后5次往Y轴负方向偏移来矫正标定位置
            CrLogW("set ai server calibration step 1 fail\n");
            if(stepcount<5){
                y_offset+=(float)((stepcount+1)*0.1);
            }else{
                y_offset-=(float)((stepcount+5)*0.1);  
            } 
        }else {
            //标定第一步成功
            usleep(200 * 1000);
            //Z轴抬高2mm
            SendDetectMoveZGcode(tickerOffset.z_offset+CALI_STEP2_Z_OFFSET, 600);
            //等待移动
            while (appFunModuleRun){
                CmdSyncRecv_t recv = GetFuncModuleRecv();
                if (recv.mtype != 0) break;
                usleep(10 * 1000);
            }
            usleep(100 * 1000);
            //设定标定步骤2
            if(AiServerLaserCali(aiServerSocket,2)!=0){
                CrLogW("set ai server calibration step 2 fail\n");
            }else{
                res = 0;
                break;
            } 
        }
        usleep(10 * 1000);
    }

    SendDetectMoveXYGcode(10, 10, 12000);
    while (appFunModuleRun)
    {
        // 获取前一帧指令响应
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveZGcode(0.2, 600);
    while (appFunModuleRun)
    {
        // 获取前一帧指令响应
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    
THREAD_RUN_CANCEL:
    if (aiServerSocket) close(aiServerSocket);
    CrLogI("laser calibration end\n");
    return res;
}

/*********************************************************
 ************************ 扫描床面 ************************
 *********************************************************/


/*********************************************************
 ************************ 首层检测 ************************
 *********************************************************/

/**
 * @description: 
 * @return {*}
 */
static int LaserScanningTableRun_Quick(void)
{
    int res = -1;
    int detectNumX = 0;
    int detectNumY = 0;
    int aiServerSocket = -1;
    int scan_speed = FIRST_LAYER_SCAN_SPEED;
    int time_interval = FIRST_LAYER_TIME_INTERVAL;
    double scan_time = 0; //扫描时间
    double size_x=0;
    double size_y=0;
    double area=0;
    CrLogI("laser quick scanning table run\n");
    
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif
    ClearFuncModuleRecvList();

    // 获取AI检测参数
    AiDetectPara_t modelLocal = {0};
    GetGcodeModelSize(&modelLocal.end_x, &modelLocal.end_y, &modelLocal.start_x, &modelLocal.start_y);
    size_x=modelLocal.end_x-modelLocal.start_x;
    size_y=modelLocal.end_y-modelLocal.start_y ;
    area=size_x*size_y;
    CrLogI("max_x = %f, max_y = %f, min_x = %f, min_y = %f  area=%lf",
            modelLocal.end_x, modelLocal.end_y, modelLocal.start_x, modelLocal.start_y, area);
    //如果Gcode还原出来的点云范围起始点跟终点是同个位置，测退出首层检测
    if(modelLocal.end_x == modelLocal.start_x || modelLocal.end_y == modelLocal.start_y){
        CrLogW("gocde model size error !!!\n");
        return res;
    }
    
    detectNumX = (modelLocal.end_x - modelLocal.start_x) / LASER_LINE_WIDTH + 1;
    
    // 获取激光结果偏移
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if(laserCfg.x_offset==0 || laserCfg.y_offset==0){
        laserCfg.x_offset = LASER_X_OFFSET ;
        laserCfg.y_offset = LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }
    CrLogI("laserCfg, x_offset = %f, y_offset = %f, z_offset = %f\n", laserCfg.x_offset, laserCfg.y_offset, laserCfg.z_offset);

    // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z)
    {
        // 打印机归零
        SendFuncModuleCmd("G28");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) {
                break;
            }
            usleep(10 * 1000);
        }
    }

    // 连接AI服务
    if (appFunModuleRun) {
        aiServerSocket = GetAiServerSocket();
        if (aiServerSocket <= 0) {
            CrLogW("connect ai server fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //设置坐标系 0x00标定板坐标系  0x01相机坐标系
#ifdef USE_CAM_COOR 
        if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
#else
        if (AiServerSetCoor(aiServerSocket,0x00) != 0) {
#endif
            CrLogW("set laser coor fail\n");
            goto THREAD_RUN_CANCEL;
        }
        // 关流
        if (AiServerCloseFlow(aiServerSocket) != 0) {
            CrLogW("set ai server open flow fail\n");
            goto THREAD_RUN_CANCEL;
        } 
        //光灯
        if (AiServerOpenLight(aiServerSocket,false) != 0) {
            CrLogW("set ai server close light fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //设置并行取流 0x01并行，0x00串行
        if (AiServerSetTakeOver(aiServerSocket,0x01) != 0) {
            CrLogW("set laser coor fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //根据模型大小调整扫描间隔和点云的稀疏档位
        if(area<=100*100){
            //设置稀疏档位
            if (AiServerLaserPointCloudLevel(aiServerSocket,0x02) != 0) {
                CrLogW("set laser point cloud level fail\n");
                goto THREAD_RUN_CANCEL;
            }
            //scan_speed=600;
            time_interval=150;
        } else if(area<=150*150){
            //设置稀疏档位
            if (AiServerLaserPointCloudLevel(aiServerSocket,0x02) != 0) {
                CrLogW("set laser point cloud level fail\n");
                goto THREAD_RUN_CANCEL;
            }
            //scan_speed=900;
            time_interval=200;
        }else {
            //设置稀疏档位
            if (AiServerLaserPointCloudLevel(aiServerSocket,0x04) != 0) {
                CrLogW("set laser point cloud level fail\n");
                goto THREAD_RUN_CANCEL;
            }
        }
    }

    scan_time = size_y /(scan_speed / 60) * 1000 ;
    CrLogI("table scan_time = %0.2lf\n",scan_time);
    // 扫描热床
    if (appFunModuleRun) {
        // 移动到点
        int count = 0;
        
        // 计算扫描XY间隔
        float intervalX = (modelLocal.end_x - modelLocal.start_x) / detectNumX;
        detectNumY = (modelLocal.end_y - modelLocal.start_y)*1000 / ((time_interval)*(scan_speed/60)) + 4;
        CrLogI("detectNumX = %d, detectNumY = %d\n",detectNumX,detectNumY);
        // 移动到起点
        float curLocationX = modelLocal.start_x - laserCfg.x_offset + LASER_LINE_WIDTH/2;
        float curLocationY = modelLocal.start_y - laserCfg.y_offset;
        float curLocationZ = laserCfg.z_offset;

        // 开始检测
        int moveDirection = 0;
        int num=0;
        int scan_count=0;
        char key[64]={0};
        json_object *tableObj = json_object_new_object();

        //Z先往下移动多10
        SendDetectMoveZGcode(curLocationZ+10, 600);
        while(appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) {
                break;
            }
            usleep(5 * 1000);
        }

        SendDetectMoveXYGcode(curLocationX, curLocationY, 12000);
        while(appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) {
                break;
            }
            usleep(5 * 1000);
        }
        SendDetectMoveZGcode(curLocationZ, 600);
        while(appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) {
                break;
            }
            usleep(5 * 1000);
        }
        //开流
        if (AiServerOpenFlow(aiServerSocket) != 0) {
            CrLogW("set ai server open flow fail\n");
            goto THREAD_RUN_CANCEL;
        }
        while (appFunModuleRun)
        { 
            int Y_scan_count = 0;
            uint64_t last_ms=0;
            //移动到扫描起点  
            SendDetectMoveXYGcode(curLocationX, curLocationY, 12000);
            while(appFunModuleRun){
                // 采集床板数据
                CmdSyncRecv_t recv = GetFuncModuleRecv();
                if (recv.mtype != 0) {
                    break;
                }
                usleep(500);
            }
            // if(moveDirection%2){
            //     curLocationY = modelLocal.start_y - laserCfg.y_offset;
            // }else{  
            //     if(modelLocal.end_y - laserCfg.y_offset >= GetPrintSavePara().devMaxSize.y){
            //         curLocationY = GetPrintSavePara().devMaxSize.y + laserCfg.y_offset;
            //     }else{
            //         curLocationY = modelLocal.end_y - laserCfg.y_offset;
            //     }    
            // } 
            if(modelLocal.end_y - laserCfg.y_offset >= GetPrintSavePara().devMaxSize.y/100){
                curLocationY = GetPrintSavePara().devMaxSize.y/100 - 1 ;
            }else{
                curLocationY = modelLocal.end_y - laserCfg.y_offset;
            }      
            if(Y_scan_count==0){
                //丢掉第一帧点云数据
                char cloud[10*1024]={0};
                GetAiServerPointCloud(aiServerSocket, cloud, time_interval);
                //usleep(500*1000);
            }
            //移动到Y扫描
            SendDetectMoveXYGcode(curLocationX, curLocationY, scan_speed);
            struct timeval tv_start;
            gettimeofday(&tv_start, NULL);
            uint64_t start_ms=0;
            start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
            
            while(appFunModuleRun){      
                struct timeval tv_now;
                gettimeofday(&tv_now, NULL);
                uint64_t now_ms=0;
                now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

                //if(now_ms-last_ms>=time_interval && now_ms-start_ms<=scan_time+time_interval*2){
                //每隔time_interval ms读取一次点云 并且如果Y_scan_count小于detectNumY的话，要扫描够detectNumY帧的点云
                if(now_ms-last_ms>=time_interval && Y_scan_count < detectNumY ){
                    CrLogI("table[%d] Y_scan_count=%d\n",scan_count,Y_scan_count);
                    Y_scan_count++;
                    
                    last_ms=now_ms;
                    char pointCloud[100 * 1024] = {0};

                    struct timeval tv_read;
                    gettimeofday(&tv_read, NULL);
                    uint64_t read_ms=0;
                    read_ms = (tv_read.tv_sec * 1000000 + tv_read.tv_usec) / 1000;

                    CrLogI("table[%d] read_ms=%ld\n",scan_count,(read_ms-start_ms));
                    scan_count++;
                    if (GetAiServerPointCloud(aiServerSocket, pointCloud, time_interval) != 0) {
                        CrLogW("get point cloud fail\n");
                        json_object *PointArray = json_object_new_array();
                        json_object *PointArray1 = json_object_new_array();
                        snprintf(key,sizeof(key),"table%d",num);
                        json_object_array_add(PointArray1,json_object_new_int(0));
                        json_object_array_add(PointArray1,json_object_new_int(0));
                        json_object_array_add(PointArray1,json_object_new_int(0));
                        json_object_array_add(PointArray,PointArray1);
                        num++;
                        json_object_object_add(tableObj,key,PointArray);
                    
                    }
                    else{
                        json_object *pointCloudObj = json_tokener_parse(pointCloud);
                        CrLogI("pointCloud length =%d\n",json_object_array_length(pointCloudObj));
                        for (int i = 0; i < json_object_array_length(pointCloudObj); i++)
                        {
                            // 获取点数据
                            json_object *pointObj = json_object_array_get_idx(pointCloudObj, i);

                            // 纠正X坐标
                            json_object *value0Obj = json_object_array_get_idx(pointObj, 0);
                            //因为激光轮廓仪的相机坐标系X轴正方向与热床方向相反，所以这里是实际点云的X坐标取反
                            int valueX =  (curLocationX + laserCfg.x_offset  ) * 1000 - json_object_get_int(value0Obj) ;
                            json_object_set_int(value0Obj, valueX);

                            // 纠正Y坐标
                            json_object *value1Obj = json_object_array_get_idx(pointObj, 1);
                            int valueY=0;

#ifdef USE_CAM_COOR 
                            valueY = modelLocal.start_y*1000 + (read_ms-start_ms) * scan_speed/60 -10000;//Y方向强制减10MM，为了与gocde还原的点云坐标对上
#else
                            valueY = modelLocal.start_y*1000 + (read_ms-start_ms) * scan_speed/60 -10000;//Y方向强制减10MM，为了与gocde还原的点云坐标对上
#endif                       
                            //换方向扫描
//                             if(moveDirection%2){
//                                 if(modelLocal.end_y - laserCfg.y_offset >= GetPrintSavePara().devMaxSize.y/100){
// #ifdef USE_CAM_COOR 
//                                     valueY = modelLocal.end_y *1000 - (read_ms-start_ms) * scan_speed/60 + json_object_get_int(value1Obj) ;
// #else
//                                     valueY = modelLocal.end_y *1000 - (read_ms-start_ms) * scan_speed/60 - json_object_get_int(value1Obj) ;
// #endif                          
//                                 }else{
// #ifdef USE_CAM_COOR 
//                                     valueY = GetPrintSavePara().devMaxSize.y/100 + laserCfg.y_offset *1000 - (read_ms-start_ms) * scan_speed/60 + json_object_get_int(value1Obj) ;
// #else
//                                     valueY = GetPrintSavePara().devMaxSize.y/100 + laserCfg.y_offset - (read_ms-start_ms) * scan_speed/60 - json_object_get_int(value1Obj) ;
// #endif                          
//                                 }
//                             }else{
// #ifdef USE_CAM_COOR 
//                                 valueY = modelLocal.start_y*1000 + (read_ms-start_ms) * scan_speed/60 + json_object_get_int(value1Obj) ;
// #else
//                                 valueY = modelLocal.start_y*1000 + (read_ms-start_ms) * scan_speed/60 - json_object_get_int(value1Obj) ;
// #endif  
//                             }
                            json_object_set_int(value1Obj, valueY);
                        }
                        // 保存点数据
                        snprintf(key,sizeof(key),"table%d",num);
                        json_object_object_add(tableObj,key,pointCloudObj);
                        num++;
                    }
                }
                if(Y_scan_count >= detectNumY){
                    CmdSyncRecv_t recv = GetFuncModuleRecv();
                    if (recv.mtype != 0) {
                        break;
                    }
                }
                usleep(500);
            }
            moveDirection++;
            curLocationX += intervalX;
            count++;
            if(modelLocal.start_y - laserCfg.y_offset >= GetPrintSavePara().devMaxSize.y/100){
                curLocationY = GetPrintSavePara().devMaxSize.y/100 - 1;
            }else{
                curLocationY = modelLocal.start_y - laserCfg.y_offset;
            }
            if(count>=detectNumX || curLocationX > GetPrintSavePara().devMaxSize.x/100)break;
             
        }
      
        // 点云数据保存文件
        if (appFunModuleRun) json_object_to_file_ext(GetTempScanTablePoint(), tableObj, JSON_C_TO_STRING_PLAIN);
        json_object_put(tableObj);
        malloc_trim(0); // 强制释放内存给系统
       
    }
    //同步文件
    char cmd[128] = {0};
    snprintf(cmd, sizeof(cmd), "sync");
    // 调用系统命令
    char sysRes[512] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes))){
        CrLogW("system fail! res = %s\n", sysRes);
    }   


    
THREAD_RUN_CANCEL:
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }

    if (aiServerSocket) close(aiServerSocket);
    CrLogI("laser scanning table end");
    return res;
}

/**
 * @description: 
 * @return {*}
 */
static int LaserFirstLayerDetectRun_Quick(bool syncState)
{
    // 检测点数
    int res = -1;
    int detectNumX = 0;
    int detectNumY = 0;
    int aiServerSocket = -1;
    int scan_speed = FIRST_LAYER_SCAN_SPEED;
    int time_interval = FIRST_LAYER_TIME_INTERVAL;
    int result=0;
    double scan_time = 0; //扫描时间
    double size_x=0;
    double size_y=0;
    double area=0;
    CrLogI("first layer detect run\n");
    
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif
    ClearFuncModuleRecvList();
    if (syncState) UpdataWithSelfTest(PREPARE_STEP_FLOOR_SCAN_MODEL);

    // 获取AI检测参数
    AiDetectPara_t modelLocal = {0};
    GetGcodeModelSize(&modelLocal.end_x, &modelLocal.end_y, &modelLocal.start_x, &modelLocal.start_y);
    size_x=modelLocal.end_x-modelLocal.start_x;
    size_y=modelLocal.end_y-modelLocal.start_y;
    area=size_x*size_y;
    CrLogI("max_x = %f, max_y = %f, min_x = %f, min_y = %f area=%lf",
            modelLocal.end_x, modelLocal.end_y, modelLocal.start_x, modelLocal.start_y, area);
    //如果Gcode还原出来的点云范围起始点跟终点是同个位置，测退出首层检测
    if(modelLocal.end_x == modelLocal.start_x || modelLocal.end_y == modelLocal.start_y){
        CrLogW("gocde model size error !!!\n");
        return res;
    }

    // 动态计算检测点数
    detectNumX = (modelLocal.end_x - modelLocal.start_x) / LASER_LINE_WIDTH + 1;

    // 获取激光结果偏移
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if(laserCfg.x_offset==0 || laserCfg.y_offset==0){
        laserCfg.x_offset = LASER_X_OFFSET;
        laserCfg.y_offset = LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }
    CrLogI("laserCfg, x_offset = %f, y_offset = %f, z_offset = %f \n", laserCfg.x_offset, laserCfg.y_offset, laserCfg.z_offset );
    
    // 连接AI服务
    if (appFunModuleRun) {
        aiServerSocket = GetAiServerSocket();
        if (aiServerSocket <= 0) {
            CrLogW("connect ai server fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //设置坐标系 0x00标定板坐标系  0x01相机坐标系
#ifdef USE_CAM_COOR 
        if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
#else
        if (AiServerSetCoor(aiServerSocket,0x00) != 0) {
#endif
            CrLogW("set laser coor fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //关灯
        if (AiServerOpenLight(aiServerSocket,false) != 0) {
            CrLogW("set ai server close light fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //设置并行取流 0x01并行，0x00串行
        if (AiServerSetTakeOver(aiServerSocket,0x01) != 0) {
            CrLogW("set laser coor fail\n");
            goto THREAD_RUN_CANCEL;
        }
        //根据模型大小调整扫描间隔和点云的稀疏档位
        if(area<=100*100){
            //设置稀疏档位
            if (AiServerLaserPointCloudLevel(aiServerSocket,0x02) != 0) {
                CrLogW("set laser point cloud level fail\n");
                goto THREAD_RUN_CANCEL;
            }
            //scan_speed=600;
            time_interval=150;
        } else if(area<=150*150){
            //设置稀疏档位
            if (AiServerLaserPointCloudLevel(aiServerSocket,0x02) != 0) {
                CrLogW("set laser point cloud level fail\n");
                goto THREAD_RUN_CANCEL;
            }
            //scan_speed=900;
            time_interval=200;
        }else {
            //设置稀疏档位
            if (AiServerLaserPointCloudLevel(aiServerSocket,0x04) != 0) {
                CrLogW("set laser point cloud level fail\n");
                goto THREAD_RUN_CANCEL;
            }
        }  
    }
    scan_time = size_y /(scan_speed / 60) * 1000;
    CrLogI("scan_time = %0.2lf\n",scan_time);
    // 首层AI检测
    if (appFunModuleRun) {
        int count = 0;

        // 计算扫描XY间隔
        float intervalX = (modelLocal.end_x - modelLocal.start_x) / detectNumX;
        detectNumY = (modelLocal.end_y - modelLocal.start_y)*1000 / ((time_interval)*(scan_speed/60)) + 4;
        CrLogI("detectNumX = %d, detectNumY = %d\n",detectNumX,detectNumY);
        // 移动到点
        float curLocationX = modelLocal.start_x - laserCfg.x_offset + LASER_LINE_WIDTH / 2;
        float curLocationY = modelLocal.start_y - laserCfg.y_offset;
        float curLocationZ = laserCfg.z_offset;

        // 开始检测
        int moveDirection = 0;
        int num=0;
        int scan_count=0;
        char key[64]={0};
        json_object *savePointObj = json_object_new_object();
        
        //Z先往下移动多10
        SendDetectMoveZGcode(curLocationZ+10, 600);
        while(appFunModuleRun){ 
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) {
                break;
            }
            usleep(5 * 1000);
        }
        SendDetectMoveXYGcode(curLocationX, curLocationY, 12000);
        while(appFunModuleRun){ 
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0){
                break;   
            }
            usleep(5 * 1000);
        }
    
        SendDetectMoveZGcode(curLocationZ, 600);
        while(appFunModuleRun){ 
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        //开流
        if (AiServerOpenFlow(aiServerSocket) != 0) {
            CrLogW("set ai server open flow fail\n");
            goto THREAD_RUN_CANCEL;
        }
        while (appFunModuleRun)
        {
            int Y_scan_count=0;
            uint64_t last_ms=0;
            //移动到扫描开始位置 
            SendDetectMoveXYGcode(curLocationX, curLocationY, 12000);                
            while(appFunModuleRun){
                // 采集床板数据
                CmdSyncRecv_t recv = GetFuncModuleRecv();
                if (recv.mtype != 0) {
                    break;   
                }
                usleep(500);
            }
            //切换Y移动方向
            // if(moveDirection%2){
            //     curLocationY = modelLocal.start_y - laserCfg.y_offset;
            // }else{  
            //     if(modelLocal.end_y - laserCfg.y_offset >= GetPrintSavePara().devMaxSize.y/100){
            //         curLocationY = GetPrintSavePara().devMaxSize.y/100 + laserCfg.y_offset;
            //     }else{
            //         curLocationY = modelLocal.end_y - laserCfg.y_offset;
            //     }    
            // } 
            if(modelLocal.end_y - laserCfg.y_offset >= GetPrintSavePara().devMaxSize.y/100){
                curLocationY = GetPrintSavePara().devMaxSize.y/100 - 1;
            }else{
                curLocationY = modelLocal.end_y - laserCfg.y_offset;
            }   
            if(Y_scan_count==0){
                //丢掉第一帧点云数据
                char cloud[10*1024]={0};
                GetAiServerPointCloud(aiServerSocket, cloud, time_interval);
                //usleep(500*1000);
            }
            SendDetectMoveXYGcode(curLocationX, curLocationY, scan_speed);
            //记录开始移动的时间戳
            struct timeval tv_start;
            gettimeofday(&tv_start, NULL);
            uint64_t start_ms=0;
            start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
            
            while(appFunModuleRun){
                struct timeval tv_now;
                gettimeofday(&tv_now, NULL);
                uint64_t now_ms=0;
                now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;
               
                //if(now_ms-last_ms>=time_interval && now_ms-start_ms<=scan_time+time_interval*2){
                 //每隔time_interval ms读取一次点云 并且如果Y_scan_count小于detectNumY的话，要扫描够detectNumY帧的点云
                if(now_ms-last_ms>=time_interval && Y_scan_count < detectNumY){
                    CrLogI("scan[%d] Y_scan_count=%d\n",scan_count,Y_scan_count);
                    Y_scan_count++;
                    
                    last_ms=now_ms;
                    char pointCloud[100 * 1024] = {0};

                    struct timeval tv_read;
                    gettimeofday(&tv_read, NULL);
                    uint64_t read_ms=0;
                    read_ms = (tv_read.tv_sec * 1000000 + tv_read.tv_usec) / 1000;

                    CrLogI("scan[%d] read_ms=%ld\n", scan_count, read_ms-start_ms);
                    scan_count++;
                    //读取点云
                    if (GetAiServerPointCloud(aiServerSocket, pointCloud, time_interval) != 0) {
                        CrLogW("get point cloud fail\n");
                        json_object *PointArray = json_object_new_array();
                        json_object *PointArray1 = json_object_new_array();
                        snprintf(key,sizeof(key),"scan%d",num);
                        json_object_array_add(PointArray1,json_object_new_int(0));
                        json_object_array_add(PointArray1,json_object_new_int(0));
                        json_object_array_add(PointArray1,json_object_new_int(0));
                        json_object_array_add(PointArray,PointArray1);
                        num++;
                        json_object_object_add(savePointObj,key,PointArray);
                    
                    }
                    else{
                        json_object *pointCloudObj = json_tokener_parse(pointCloud);
                        CrLogI("pointCloud length =%d\n",json_object_array_length(pointCloudObj));
                        for (int i = 0; i < json_object_array_length(pointCloudObj); i++)
                        {
                            // 获取点数据
                            json_object *pointObj = json_object_array_get_idx(pointCloudObj, i);

                            // 纠正X坐标
                            json_object *value0Obj = json_object_array_get_idx(pointObj, 0);
                            //因为激光轮廓仪的相机坐标系X轴正方向与热床方向相反，所以这里是实际点云的X坐标取反
                            int valueX =  (curLocationX + laserCfg.x_offset ) * 1000 - json_object_get_int(value0Obj);
                            json_object_set_int(value0Obj, valueX);
                    
                            // 纠正Y坐标
                            json_object *value1Obj = json_object_array_get_idx(pointObj, 1);
                            int valueY=0;
#ifdef USE_CAM_COOR 
                            valueY = modelLocal.start_y*1000 + (read_ms-start_ms) * scan_speed/60 -10000;//Y方向强制减10MM，为了与gocde还原的点云坐标对上
#else
                            valueY = modelLocal.start_y*1000 + (read_ms-start_ms) * scan_speed/60 -10000;//Y方向强制减10MM，为了与gocde还原的点云坐标对上
#endif                  
//                             if(moveDirection%2){
//                                 if(modelLocal.end_y - laserCfg.y_offset >= GetPrintSavePara().devMaxSize.y/100){
// #ifdef USE_CAM_COOR 
//                                     valueY = modelLocal.end_y *1000 - (read_ms-start_ms) * scan_speed/60 + json_object_get_int(value1Obj) ;
// #else
//                                     valueY = modelLocal.end_y *1000 - (read_ms-start_ms) * scan_speed/60 - json_object_get_int(value1Obj) ;
// #endif                          
//                                 }else{
// #ifdef USE_CAM_COOR 
//                                     valueY = GetPrintSavePara().devMaxSize.y/100 + laserCfg.y_offset *1000 - (read_ms-start_ms) * scan_speed/60 + json_object_get_int(value1Obj) ;
// #else
//                                     valueY = GetPrintSavePara().devMaxSize.y/100 + laserCfg.y_offset - (read_ms-start_ms) * scan_speed/60 - json_object_get_int(value1Obj) ;
// #endif                                             

//                                 }
//                             }else{
// #ifdef USE_CAM_COOR 
//                                 valueY = modelLocal.start_y*1000 + (read_ms-start_ms) * scan_speed/60 + json_object_get_int(value1Obj) ;
// #else
//                                 valueY = modelLocal.start_y*1000 + (read_ms-start_ms) * scan_speed/60 - json_object_get_int(value1Obj) ;
// #endif  
//                             }
                            json_object_set_int(value1Obj, valueY);
                        }
                        // 保存点数据
                        snprintf(key,sizeof(key),"scan%d",num);
                        json_object_object_add(savePointObj,key,pointCloudObj);
                        num++;
                   }  
                }
                if(Y_scan_count >= detectNumY){
                     // 采集床板数据
                    CmdSyncRecv_t recv = GetFuncModuleRecv();
                    if (recv.mtype != 0) {
                        break;
                    }
                }
                usleep(500);
            }
            //X方向偏移
            curLocationX += intervalX;
            moveDirection++;
            count++;
            //Y方向扫描重点的值
            if(modelLocal.start_y - laserCfg.y_offset >= GetPrintSavePara().devMaxSize.y/100){
                curLocationY = GetPrintSavePara().devMaxSize.y/100 - 1;
            }else{
                curLocationY = modelLocal.start_y - laserCfg.y_offset;
            }
            if(count>=detectNumX || curLocationX > GetPrintSavePara().devMaxSize.x/100)break;
             
        }
        // 点云数据保存文件
        if (appFunModuleRun) json_object_to_file_ext(GetTempScanFirstLayerPoint(), savePointObj, JSON_C_TO_STRING_PLAIN);
        json_object_put(savePointObj);
        malloc_trim(0); // 强制释放内存给系统
    }
    //同步文件
    char cmd[128] = {0};
    snprintf(cmd, sizeof(cmd), "sync");
    // 调用系统命令
    char sysRes[512] = {0};
    if (!PopenSystem(cmd, sysRes, sizeof(sysRes))){
        CrLogW("system fail! res = %s\n", sysRes);
    }   
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }
  
    if (syncState) UpdataWithSelfTest(PREPARE_STEP_FLOOR_AI_CALCULATE);
    SendFuncModuleCmd("FIRST_FLOOR_PAUSE_POSITION");
    // 喷嘴移动到暂停位置，降温
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(10 * 1000);
    } while (1);
    

    res = GetAiServerFirstLayerNewResult(aiServerSocket,GetTempScanTablePoint(),GetTempScanFirstLayerPoint(),\
            GetTempGcodeReductionPoint(),&result);
    if(res==0){
        if(result>0){
            CrLogI("GetAiServerFirstLayerNewResult abnormal",res);
            res=-1;
        }else{
            CrLogI("GetAiServerFirstLayerNewResult normal",res);
            res=0;
        }
    }else {
        CrLogW("GetAiServerFirstLayerNewResult fail res=%d\n",res);
        res=-1;
        goto THREAD_RUN_CANCEL;
    }
   
    

THREAD_RUN_CANCEL:
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }
    if (aiServerSocket) close(aiServerSocket);
    CrLogI("first layer detect result = %d", res);
    CrLogI("first layer detect end");
    return res;
}


/**
 * @description: 
 * @return {*}
 */
static int LaserOffsetCorrectionRun(void)
{
    // 初始化环境
    CrLogI("laser offset correction run\n");
    int res = -1;
    int aiServerSocket = -1;
    FILE *gcodeFileFd = NULL;
    int correctCount=0;
    int correct_Y=0;
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif 
    laserTesting=true;
    appFunModuleRun=true;
    ClearFuncModuleRecvList();
     // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z) {
        SendFuncModuleCmd("CX_ROUGH_G28 EXTRUDER_TEMP=220 BED_TEMP=60");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
            usleep(10 * 1000);
        } while (1);
        SendFuncModuleCmd("CX_NOZZLE_CLEAR");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        // 细归零
        SendFuncModuleCmd("ACCURATE_G28");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
    }
    
    //删除原来的偏移参数文件
    char rm_cmd[128]={0};
    snprintf(rm_cmd,sizeof(rm_cmd),"rm %s",GetLaserOffsetInfo());
    system(rm_cmd);

    // 读取划线gcode文件
    char *filePath = GetLaserCorrectionGcodeFilePath();
    gcodeFileFd = fopen(filePath, "r");
    if (gcodeFileFd == NULL) {
        CrLogW("gcode file open failed = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }

    // //读取划线指令
    // if (SendNextDrawLineGcode(gcodeFileFd) != 0) {
    //     CrLogW("gcode file invalid = %s\n", filePath);
    //     goto THREAD_RUN_CANCEL;
    // }
    
    // // 开始划线
    // do {
    //     CmdSyncRecv_t recv = GetFuncModuleRecv();
    //     if (recv.mtype != 0) {
    //         if (SendNextDrawLineGcode(gcodeFileFd) != 0) break;
    //     }
    //     if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
    //     usleep(300);
    // } while (1);
    // CrLogI("draw line finish");
    //文件回到开始位置
    if(SendDrawFlowLineGcode(gcodeFileFd) != 0) {
        CrLogW("gcode file invalid = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }

    // 获取点云还原数据
    GetGcodePointCloudFromFile(GetLaserCorrectionGcodeFilePath(), 1.0);
    AiDetectPara_t modelLocal = {0};
    GetGcodeModelSize(&modelLocal.end_x, &modelLocal.end_y, &modelLocal.start_x, &modelLocal.start_y);
    CrLogI("max_x = %f, max_y = %f, min_x = %f, min_y = %f",
            modelLocal.end_x, modelLocal.end_y, modelLocal.start_x, modelLocal.start_y);

    // 获取激光偏移参数
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if ((laserCfg.x_offset > -0.0001 && laserCfg.x_offset < 0.0001) &&
        (laserCfg.y_offset > -0.0001 && laserCfg.y_offset < 0.0001))
    {
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }

   

    // 移动到检测起点
    float curLocationX = 95 - laserCfg.x_offset;
    float curLocationY = 100 - laserCfg.y_offset;
    CrLogI("curLocationX = %f, curLocationY = %f", curLocationX, curLocationY);
    
    SendDetectMoveXYGcode(curLocationX, curLocationY, 6000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogW("connect ai server fail\n");
        goto THREAD_RUN_CANCEL;
    }

    //设置相机坐标系
    if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
        CrLogW("set laser coor fail\n");
        goto THREAD_RUN_CANCEL;
    }
    //设置稀疏档位 0x00为全点云
    if (AiServerLaserPointCloudLevel(aiServerSocket,0x00) != 0) {
        CrLogW("set laser point cloud level fail\n");
        goto THREAD_RUN_CANCEL;
    }
    //设置曝光参数
    AiServerSetExposure(aiServerSocket,1000);
    //设置曝光参数
    AiServerSetGain(aiServerSocket,1000);

    // 开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set ai server open flow fail\n");
        goto THREAD_RUN_CANCEL;
    }

     // 扫描点云数据
    int moveNum = 0, againNum = 0, stepValue = 0;
    do {
        char pointCloud[100 * 1024] = {0};
        if (GetAiServerPointCloud(aiServerSocket, pointCloud, 2000) != 0) {
            CrLogW("get point cloud fail\n");
            goto THREAD_RUN_CANCEL;
        }
        else {
            // 纠正点云坐标数据
            json_object *pointCloudObj = json_tokener_parse(pointCloud);
            CrLogI("pointCloud length = %d\n",json_object_array_length(pointCloudObj));
#if 0
            for (int i = 0; i < json_object_array_length(pointCloudObj); i++)
            {
                // 获取点数据
                json_object *pointObj = json_object_array_get_idx(pointCloudObj, i);

                // 纠正X坐标
                json_object *value0Obj = json_object_array_get_idx(pointObj, 0);
                //因为激光轮廓仪的相机坐标系X轴正方向与热床方向相反，所以这里是实际点云的X坐标取反
                int valueX = (curLocationX + laserCfg.x_offset  ) * 1000 - json_object_get_int(value0Obj) ;
                json_object_set_int(value0Obj, valueX);

                // 纠正Y坐标
                json_object *value1Obj = json_object_array_get_idx(pointObj, 1);
#ifdef USE_CAM_COOR 
                int valueY =  (curLocationY + laserCfg.y_offset ) * 1000 + json_object_get_int(value1Obj) ;
#else
                int valueY =  (curLocationY + laserCfg.y_offset ) * 1000 - json_object_get_int(value1Obj) ;
#endif
                json_object_set_int(value1Obj, valueY);
            }
#endif
            // 保存点数据
            json_object_to_file_ext(GetTempOffsetCorrectionPoint(), pointCloudObj, JSON_C_TO_STRING_PRETTY);

            // 解析当前点ai结果
            LaserConfig_t diff = {0};
            GetAiServerLaserOffsetResult(aiServerSocket, pointCloudObj, GetTempGcodeReductionPoint(), &diff);
            CrLogI("laser offset correction, x = %f, y = %f, z = %f\n", diff.x_offset, diff.y_offset, diff.z_offset);

            // 保存偏移值
            if (diff.x_offset > -8 && diff.x_offset < 8 && diff.y_offset > -8 && diff.y_offset < 8) {
                json_object *laserOffsetValueObj = json_object_new_object();
                json_object_object_add(laserOffsetValueObj, "laser_offset_x", json_object_new_double(laserCfg.x_offset - diff.x_offset - stepValue));
                json_object_object_add(laserOffsetValueObj, "laser_offset_y", json_object_new_double(laserCfg.y_offset + diff.y_offset + correct_Y));
                json_object_object_add(laserOffsetValueObj, "laser_offset_z", json_object_new_double(laserCfg.z_offset));
                json_object_to_file_ext(GetLaserOffsetInfo(), laserOffsetValueObj, JSON_C_TO_STRING_PRETTY);
                json_object_put(laserOffsetValueObj);
                res = 0;
                break;
            }
            else
            {
                if (++againNum >= LASER_OFFSET_AGAIN_SCAN_NUM)
                {
                    if (++moveNum >= LASER_OFFSET_MOVE_SCAN_NUM) {
                        UpdataErrorStateToManager(FAULT_AI_LASER_OFFSET_CORRECT_FAIL, "laser offset correct fail", NULL);
                        break;
                    }
                    againNum = 0;
                    if(correctCount<2){
                        correct_Y += (correctCount+1)*2;
                    }else if(correctCount<5){
                        correct_Y = 0;
                        stepValue += LASER_OFFSET_MOVE_SCAN_LEN;
                    }else {
                        if(correctCount==5){
                            stepValue=0;
                        }
                        stepValue -= LASER_OFFSET_MOVE_SCAN_LEN;
                    }
                    correctCount++;
                    CrLogI("correctCount=%d\n",correctCount);
                    
                    SendDetectMoveXYGcode(curLocationX + stepValue, curLocationY + correct_Y, 6000);
                    do {
                        CmdSyncRecv_t recv = GetFuncModuleRecv();
                        if (recv.mtype != 0) break;
                        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
                        usleep(10 * 1000);
                    } while (1);
                }
            }
        }
    } while (1);
    
    CrLogI("moveNum = %d, againNum = %d, stepValue = %d", moveNum, againNum, stepValue);

    SendDetectMoveXYGcode(10, 10, 12000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(0.2, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);

THREAD_RUN_CANCEL:

    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }

    // 释放资源
    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);
    CrLogI("laser offset correction end\n");

    laserTesting=false;
    appFunModuleRun=false;
    return res;
}
/**
 * @description: 
 * @return {*}
 */
static int LaserOffsetCorrection_TwoPoint_Run(void)
{
    // 初始化环境
    CrLogI("laser offset correction two point run\n");
    int res = -1;
    int aiServerSocket = -1;
    FILE *gcodeFileFd = NULL;
    int correctCount=0;
    int correct_Y=0;
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif 
    laserTesting=true;
    appFunModuleRun=true;
    ClearFuncModuleRecvList();
     // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z) {
        SendFuncModuleCmd("CX_ROUGH_G28 EXTRUDER_TEMP=220 BED_TEMP=60");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
            usleep(10 * 1000);
        } while (1);
        SendFuncModuleCmd("CX_NOZZLE_CLEAR");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        // 细归零
        SendFuncModuleCmd("ACCURATE_G28");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
    }
    
    // 读取划线gcode文件
    char *filePath = GetLaserCorrectionGcodeFilePath();
    gcodeFileFd = fopen(filePath, "r");
    if (gcodeFileFd == NULL) {
        CrLogW("gcode file open failed = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }

    if(SendDrawFlowLineGcode(gcodeFileFd) != 0) {
        CrLogW("gcode file invalid = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }

    // 获取点云还原数据
    GetGcodePointCloudFromFile(GetLaserCorrectionGcodeFilePath(), 1.0);
    AiDetectPara_t modelLocal = {0};
    GetGcodeModelSize(&modelLocal.end_x, &modelLocal.end_y, &modelLocal.start_x, &modelLocal.start_y);
    CrLogI("max_x = %f, max_y = %f, min_x = %f, min_y = %f",
            modelLocal.end_x, modelLocal.end_y, modelLocal.start_x, modelLocal.start_y);

    //删除原来的偏移参数文件
    char rm_cmd[128]={0};
    snprintf(rm_cmd,sizeof(rm_cmd),"rm %s",GetLaserOffsetInfo());
    system(rm_cmd);

    // 获取激光偏移参数
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if ((laserCfg.x_offset > -0.0001 && laserCfg.x_offset < 0.0001) &&
        (laserCfg.y_offset > -0.0001 && laserCfg.y_offset < 0.0001))
    {
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }

    // 移动到检测起点
    float curLocationX = 95 - laserCfg.x_offset;
    float curLocationY = 100 - laserCfg.y_offset;
    CrLogI("curLocationX = %f, curLocationY = %f", curLocationX, curLocationY);
    
    SendDetectMoveXYGcode(curLocationX, curLocationY, 6000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogW("connect ai server fail\n");
        goto THREAD_RUN_CANCEL;
    }

    //设置相机坐标系
    if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
        CrLogW("set laser coor fail\n");
        goto THREAD_RUN_CANCEL;
    }
    //设置稀疏档位 0x00为全点云
    if (AiServerLaserPointCloudLevel(aiServerSocket,0x00) != 0) {
        CrLogW("set laser point cloud level fail\n");
        goto THREAD_RUN_CANCEL;
    }

    // 开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set ai server open flow fail\n");
        goto THREAD_RUN_CANCEL;
    }

     // 扫描点云数据
    int moveNum = 0, againNum = 0, stepValue = 0;
    do {
        char pointCloud1[100 * 1024] = {0};
        //设置曝光参数2000
        AiServerSetExposure(aiServerSocket,2000);
        if (GetAiServerPointCloud(aiServerSocket, pointCloud1, 2000) != 0) {
            CrLogW("get point cloud fail\n");
            goto THREAD_RUN_CANCEL;
        }
        else {
            // 保存点云到文件
            json_object *pointCloudExp2000Obj = json_tokener_parse(pointCloud1);
            if(pointCloudExp2000Obj){
                json_object_to_file_ext(GetTempOffsetCorrectionPointExp2000(), pointCloudExp2000Obj, JSON_C_TO_STRING_PRETTY);
                CrLogI("pointCloud exp2000 length = %d\n",json_object_array_length(pointCloudExp2000Obj));
            }
         
            char pointCloud2[100 * 1024] = {0};
            //设置曝光参数1000
            AiServerSetExposure(aiServerSocket,1000);
            if (GetAiServerPointCloud(aiServerSocket, pointCloud2, 2000) != 0) {
                CrLogW("get point cloud fail\n");
                goto THREAD_RUN_CANCEL;
            }else{
                // 保存点云到文件
                json_object *pointCloudExp1000Obj = json_tokener_parse(pointCloud2);
                if(pointCloudExp1000Obj){
                    json_object_to_file_ext(GetTempOffsetCorrectionPointExp1000(), pointCloudExp1000Obj, JSON_C_TO_STRING_PRETTY);
                    CrLogI("pointCloud exp1000 length = %d\n",json_object_array_length(pointCloudExp1000Obj));
                }
                
                // 解析当前点ai结果
                LaserConfig_t diff = {0};
                if(GetAiServerLaserOffsetTwoPointResult(aiServerSocket, pointCloudExp1000Obj, pointCloudExp2000Obj, &diff)!=0){
                    UpdataErrorStateToManager(FAULT_AI_LASER_OFFSET_CORRECT_FAIL, "laser offset correct fail", NULL);
                    break;
                }
                CrLogI("laser offset correction, x = %f, y = %f, z = %f\n", diff.x_offset, diff.y_offset, diff.z_offset);

                // 保存偏移值
                if (diff.x_offset > -8 && diff.x_offset < 8 && diff.y_offset > -8 && diff.y_offset < 8) {
                    json_object *laserOffsetValueObj = json_object_new_object();
                    json_object_object_add(laserOffsetValueObj, "laser_offset_x", json_object_new_double(laserCfg.x_offset - diff.x_offset - stepValue));
                    json_object_object_add(laserOffsetValueObj, "laser_offset_y", json_object_new_double(laserCfg.y_offset + diff.y_offset + correct_Y));
                    json_object_object_add(laserOffsetValueObj, "laser_offset_z", json_object_new_double(laserCfg.z_offset));
                    json_object_to_file_ext(GetLaserOffsetInfo(), laserOffsetValueObj, JSON_C_TO_STRING_PRETTY);
                    json_object_put(laserOffsetValueObj);
                    res = 0;
                    break;
                }
                else
                {
                    if (++againNum >= 2)
                    {
                        if (++moveNum >= 5) {
                            UpdataErrorStateToManager(FAULT_AI_LASER_OFFSET_CORRECT_FAIL, "laser offset correct fail", NULL);
                            break;
                        }
                        stepValue-=1;
                        correct_Y+=1;
                       
                        CrLogI("correctCount=%d\n",correctCount++);
                        
                        SendDetectMoveXYGcode(curLocationX + stepValue, curLocationY + correct_Y, 1200);
                        do {
                            CmdSyncRecv_t recv = GetFuncModuleRecv();
                            if (recv.mtype != 0) break;
                            if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
                            usleep(10 * 1000);
                        } while (1);
                    }
                }
            }
        }
    } while (1);
    
    CrLogI("moveNum = %d, againNum = %d, stepValue = %d correct_Y = %d", moveNum, againNum, stepValue, correct_Y);

    SendDetectMoveXYGcode(10, 10, 12000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(0.2, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
THREAD_RUN_CANCEL:
    //设置回默认曝光值
    if (AiServerSetExposure(aiServerSocket,1000)!=0){
        CrLogW("set ai server close flow fail\n");
    }
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }

    // 释放资源
    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);
    CrLogI("laser offset correction end\n");

    laserTesting=false;
    appFunModuleRun=false;
    return res;
}

/**
 * @description: 
 * @return {*}
 */
static int LaserOffsetCorrectionSingleRun(void)
{
    // 初始化环境
    CrLogI("laser offset correction run\n");
    int res = -1;
    int aiServerSocket = -1;
    FILE *gcodeFileFd = NULL;
   
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif 
    laserTesting=true;
    appFunModuleRun=true;
    ClearFuncModuleRecvList();

    // 获取点云还原数据
    GetGcodePointCloudFromFile(GetLaserCorrectionNewGcodePath(), 1.0);
    AiDetectPara_t modelLocal = {0};
    GetGcodeModelSize(&modelLocal.end_x, &modelLocal.end_y, &modelLocal.start_x, &modelLocal.start_y);
    CrLogI("max_x = %f, max_y = %f, min_x = %f, min_y = %f",
            modelLocal.end_x, modelLocal.end_y, modelLocal.start_x, modelLocal.start_y);

    // 获取激光偏移参数
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if ((laserCfg.x_offset > -0.0001 && laserCfg.x_offset < 0.0001) &&
        (laserCfg.y_offset > -0.0001 && laserCfg.y_offset < 0.0001))
    {
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }

    // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z) {
        SendFuncModuleCmd("G28");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
            usleep(10 * 1000);
        } while (1);
    }

    // 移动到检测起点
    float curLocationX = 80 - laserCfg.x_offset;
    float curLocationY = 100 - laserCfg.y_offset;
    CrLogI("curLocationX = %f, curLocationY = %f", curLocationX, curLocationY);
    
    SendDetectMoveXYGcode(curLocationX, curLocationY, 6000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(LASER_Z_OFFSET, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);

    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogW("connect ai server fail\n");
        goto THREAD_RUN_CANCEL;
    }

    //设置相机坐标系
    if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
        CrLogW("set laser coor fail\n");
        goto THREAD_RUN_CANCEL;
    }
    //设置稀疏档位 0x00为全点云
    if (AiServerLaserPointCloudLevel(aiServerSocket,0x00) != 0) {
        CrLogW("set laser point cloud level fail\n");
        goto THREAD_RUN_CANCEL;
    }

    // 开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set ai server open flow fail\n");
        goto THREAD_RUN_CANCEL;
    }

    // 扫描空床
    json_object *tablePoint = json_object_new_array();
    do {
        // 获取点云
        char pointCloud[100 * 1024] = {0};
        GetAiServerPointCloud(aiServerSocket, pointCloud, 2000);

        json_object *pointCloudObj = json_tokener_parse(pointCloud);
        CrLogI("pointCloud length = %d\n",json_object_array_length(pointCloudObj));
        json_object_array_add(tablePoint, pointCloudObj);

        // 移动是否扫描完成
        curLocationX += 5;
        if (curLocationX > (110 - laserCfg.x_offset)) break;

        // 移动到下一个点
        SendDetectMoveXYGcode(curLocationX, curLocationY, 6000);
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
            usleep(10 * 1000);
        } while (1);
    } while (1);

    // 保存点数据
    json_object_to_file_ext(GetTempOffsetTablePoint(), tablePoint, JSON_C_TO_STRING_PRETTY);
    json_object_put(tablePoint);

    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
        goto THREAD_RUN_CANCEL;
    }

    // 读取划线gcode文件
    char *filePath = GetLaserCorrectionNewGcodePath();
    gcodeFileFd = fopen(filePath, "r");
    if (gcodeFileFd == NULL) {
        CrLogW("gcode file open failed = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }

    //读取划线指令
    if (SendNextDrawLineGcode(gcodeFileFd) != 0) {
        CrLogW("gcode file invalid = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }
    
    // 开始划线
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            if (SendNextDrawLineGcode(gcodeFileFd) != 0) break;
        }
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(300);
    } while (1);
    CrLogI("draw line finish");

    // 移动到检测起点
    curLocationX = 80 - laserCfg.x_offset;
    curLocationY = 100 - laserCfg.y_offset;
    CrLogI("curLocationX = %f, curLocationY = %f", curLocationX, curLocationY);
    
    SendDetectMoveXYGcode(curLocationX, curLocationY, 6000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(LASER_Z_OFFSET, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);

    // 开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set ai server open flow fail\n");
        goto THREAD_RUN_CANCEL;
    }

    // 扫描校准模型
    json_object *offsetPoint = json_object_new_array();
    do {
        // 获取点云
        char pointCloud[100 * 1024] = {0};
        GetAiServerPointCloud(aiServerSocket, pointCloud,2000);

        json_object *pointCloudObj = json_tokener_parse(pointCloud);
        CrLogI("pointCloud length = %d\n",json_object_array_length(pointCloudObj));
        json_object_array_add(offsetPoint, pointCloudObj);

        // 移动是否扫描完成
        curLocationX += 5;
        if (curLocationX > (110 - laserCfg.x_offset)) break;

        // 移动到下一个点
        SendDetectMoveXYGcode(curLocationX, curLocationY, 6000);
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
            usleep(10 * 1000);
        } while (1);
    } while (1);

    // 保存点数据
    json_object_to_file_ext(GetTempOffsetCorrectionPoint(), offsetPoint, JSON_C_TO_STRING_PRETTY);
    json_object_put(offsetPoint);

    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
        goto THREAD_RUN_CANCEL;
    }

    // 计算偏移结果
    curLocationX = 80;
    curLocationY = 100;
    LaserOffsetRes_t result[7] = {0};
    json_object *getTablePoint = json_object_from_file(GetTempOffsetTablePoint());
    json_object *getOffsetPoint = json_object_from_file(GetTempOffsetCorrectionPoint());
    // 逐个计算
    for (int i = 0; i < 7; i++) {
        json_object *tablePoint = json_object_array_get_idx(getTablePoint, i);
        json_object *scanPoint = json_object_array_get_idx(getOffsetPoint, i);
        json_object_get(tablePoint);
        json_object_get(scanPoint);

        GetAiServerLaserOffsetNewResult(aiServerSocket, tablePoint, scanPoint, (curLocationX + 5 * i), curLocationY, &result[i]);
        CrLogI("laser offset correction, confidence = %f, x = %f, y = %f, z = %f\n",
            result[i].confidence, result[i].x_offset, result[i].y_offset, result[i].z_offset);
    }
    json_object_put(getTablePoint);
    json_object_put(getOffsetPoint);

    // 获取可信度最高的偏移结果
    LaserOffsetRes_t diff = {0};
    for (int i = 0; i < 7; i++) {
        if (result[i].confidence > diff.confidence) diff = result[i];
    }
    CrLogI("diff, confidence = %f, x = %f, y = %f, z = %f\n",
            diff.confidence, diff.x_offset, diff.y_offset, diff.z_offset);

    // 保存偏移值
    if (diff.confidence > 90) {
        json_object *laserOffsetValueObj = json_object_new_object();
        json_object_object_add(laserOffsetValueObj, "laser_offset_x", json_object_new_double(laserCfg.x_offset - diff.x_offset));
        json_object_object_add(laserOffsetValueObj, "laser_offset_y", json_object_new_double(laserCfg.y_offset + diff.y_offset));
        json_object_object_add(laserOffsetValueObj, "laser_offset_z", json_object_new_double(laserCfg.z_offset));
        json_object_to_file_ext(GetLaserOffsetInfo(), laserOffsetValueObj, JSON_C_TO_STRING_PRETTY);
        json_object_put(laserOffsetValueObj);
        res = 0;
    }
    else UpdataErrorStateToManager(FAULT_AI_LASER_OFFSET_CORRECT_FAIL, "laser offset correct fail", NULL);

THREAD_RUN_CANCEL:
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }

    // 释放资源
    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);
    CrLogI("laser offset correction end\n");

    laserTesting=false;
    appFunModuleRun=false;
    return res;
}

/**
 * @description: 
 * @return {*}
 */
static int LaserOffsetCorrection_New02mm_Run(void)
{
    // 初始化环境
    CrLogI("laser offset correction run\n");
    int res = -1;
    int aiServerSocket = -1;
    FILE *gcodeFileFd = NULL;
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif 
    laserTesting=true;
    appFunModuleRun=true;
    ClearFuncModuleRecvList();
     // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z) {
        SendFuncModuleCmd("CX_ROUGH_G28 EXTRUDER_TEMP=220 BED_TEMP=60");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
            usleep(10 * 1000);
        } while (1);
        SendFuncModuleCmd("CX_NOZZLE_CLEAR");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        // 细归零
        SendFuncModuleCmd("ACCURATE_G28");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
    }
    
    //删除原来的偏移参数文件
    char rm_cmd[128]={0};
    snprintf(rm_cmd,sizeof(rm_cmd),"rm %s",GetLaserOffsetInfo());
    system(rm_cmd);

    //SendDetectMoveXYGcode(10, 10, 12000);
    // do {
    //     CmdSyncRecv_t recv = GetFuncModuleRecv();
    //     if (recv.mtype != 0) break;
    //     if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
    //     usleep(10 * 1000);
    // } while (1);
    // SendDetectMoveZGcode(0.2, 600);
    // do {
    //     CmdSyncRecv_t recv = GetFuncModuleRecv();
    //     if (recv.mtype != 0) break;
    //     if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
    //     usleep(10 * 1000);
    // } while (1);
    //因为加热会导致热床形变，所以先加热热床再扫描床面
    char bedTempCmd[64]={0};
    snprintf(bedTempCmd,sizeof(bedTempCmd),"M190 S%0.1f",60.0);
    SendFuncModuleCmd(bedTempCmd);
    while(appFunModuleRun){
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
        usleep(500);
    }
    // SendFuncModuleCmd("BED_MESH_CLEAR");
    // while(appFunModuleRun){
    //     // 采集床板数据
    //     CmdSyncRecv_t recv = GetFuncModuleRecv();
    //     if (recv.mtype != 0) {
    //         break;
    //     }
    //     usleep(500);
    // }
  
    // 获取点云还原数据
    GetGcodePointCloudFromFile(GetLaserCorrectionNewGcodePath(), 1.0);
    AiDetectPara_t modelLocal = {0};
    GetGcodeModelSize(&modelLocal.end_x, &modelLocal.end_y, &modelLocal.start_x, &modelLocal.start_y);
    CrLogI("max_x = %f, max_y = %f, min_x = %f, min_y = %f",
            modelLocal.end_x, modelLocal.end_y, modelLocal.start_x, modelLocal.start_y);

    // 获取激光偏移参数
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if ((laserCfg.x_offset > -0.0001 && laserCfg.x_offset < 0.0001) &&
        (laserCfg.y_offset > -0.0001 && laserCfg.y_offset < 0.0001))
    {
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }

    // 移动到检测起点
    float curLocationX = 100 - laserCfg.x_offset;
    float curLocationY = 100 - laserCfg.y_offset;
    CrLogI("curLocationX = %f, curLocationY = %f", curLocationX, curLocationY);

    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogW("connect ai server fail\n");
        goto THREAD_RUN_CANCEL;
    }

    //设置相机坐标系
    if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
        CrLogW("set laser coor fail\n");
        goto THREAD_RUN_CANCEL;
    }
    //设置稀疏档位 0x05为全点云
    if (AiServerLaserPointCloudLevel(aiServerSocket,0x05) != 0) {
        CrLogW("set laser point cloud level fail\n");
        goto THREAD_RUN_CANCEL;
    }
    //设置曝光参数
    AiServerSetExposure(aiServerSocket,1000);
    //设置增益参数
    AiServerSetGain(aiServerSocket,1000);
    //设置并行取流 0x01并行，0x00串行
    if (AiServerSetTakeOver(aiServerSocket,0x00) != 0) {
        CrLogW("set laser take over fail\n");
        goto THREAD_RUN_CANCEL;
    }

    SendDetectMoveZGcode(8, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveXYGcode(curLocationX, curLocationY, 6000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    // 开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set ai server open flow fail\n");
        goto THREAD_RUN_CANCEL;
    }
    usleep(50*1000);
    // 扫描点云数据
    char tablePC[100 * 1024] = {0};
    if (GetAiServerPointCloud(aiServerSocket, tablePC, 2000) != 0) {
        CrLogW("get point cloud fail\n");
        goto THREAD_RUN_CANCEL;
    }
    else {
        // 纠正点云坐标数据
        json_object *table1CloudObj = json_tokener_parse(tablePC);
        CrLogI("pointCloud length = %d\n",json_object_array_length(table1CloudObj));
        // 保存点数据
        json_object_to_file_ext(GetTempOffsetCorrect02mmTablePc(), table1CloudObj, JSON_C_TO_STRING_PRETTY);
        if(table1CloudObj)json_object_put(table1CloudObj);
    }

    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }
    SendDetectMoveZGcode(8, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveXYGcode(5, 5, 6000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(0.2, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    // SendFuncModuleCmd("BED_MESH_PROFILE LOAD=default");
    // while(appFunModuleRun){
    //     // 采集床板数据
    //     CmdSyncRecv_t recv = GetFuncModuleRecv();
    //     if (recv.mtype != 0) {
    //         break;
    //     }
    //     usleep(500);
    // }
    // 读取划线gcode文件
    char *filePath = GetLaserCorrectionNewGcodePath();
    gcodeFileFd = fopen(filePath, "r");
    if (gcodeFileFd == NULL) {
        CrLogW("gcode file open failed = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }
    
    if(SendDrawFlowLineGcode(gcodeFileFd) != 0) {
        CrLogW("gcode file invalid = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }

    // SendFuncModuleCmd("BED_MESH_CLEAR");
    // while(appFunModuleRun){
    //     // 采集床板数据
    //     CmdSyncRecv_t recv = GetFuncModuleRecv();
    //     if (recv.mtype != 0) {
    //         break;
    //     }
    //     usleep(500);
    // }
    SendDetectMoveZGcode(8, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveXYGcode(curLocationX, curLocationY, 6000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    // 开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set ai server open flow fail\n");
        goto THREAD_RUN_CANCEL;
    }
    usleep(50*1000);
    // 扫描点云数据
    json_object *save_pcObj = json_object_new_object();
    for(int i=0;i<10;i++){
        char pointCloud[100 * 1024] = {0};
        if (GetAiServerPointCloud(aiServerSocket, pointCloud, 2000) != 0) {
            CrLogW("get point cloud fail\n");
            UpdataErrorStateToManager(FAULT_AI_LASER_OFFSET_CORRECT_FAIL, "laser offset correct fail", NULL);
            goto THREAD_RUN_CANCEL;
            
        }
        else {
            // 纠正点云坐标数据
            json_object *pointCloudObj = json_tokener_parse(pointCloud);
            CrLogI("pointCloud length = %d\n",json_object_array_length(pointCloudObj));
            char key[64]={0};
            snprintf(key,sizeof(key),"scan%d",i);
            json_object_object_add(save_pcObj,key,pointCloudObj);

        }
        usleep(1000);
    }
    json_object_to_file_ext(GetTempOffsetCorrect02mmScanPc(), save_pcObj, JSON_C_TO_STRING_PRETTY);
    json_object_put(save_pcObj);

    system("sync");
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }
    // SendFuncModuleCmd("BED_MESH_PROFILE LOAD=default");
    // while(appFunModuleRun){
    //     // 采集床板数据
    //     CmdSyncRecv_t recv = GetFuncModuleRecv();
    //     if (recv.mtype != 0) {
    //         break;
    //     }
    //     usleep(500);
    // }
    SendDetectMoveXYGcode(10, 10, 12000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(0.2, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    
    SendFuncModuleCmd("M104 S0");
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendFuncModuleCmd("M140 S0");
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }

    double get_x_offset=0.0;
    double get_y_offset=0.0;
    if(GetAiServerLaserOffset02mmResult(aiServerSocket,\
                    GetTempOffsetCorrect02mmScanPc(), \
                    GetTempOffsetCorrect02mmTablePc(), &get_x_offset , &get_y_offset)<0){
        UpdataErrorStateToManager(FAULT_AI_LASER_OFFSET_CORRECT_FAIL, "laser offset correct fail", NULL);
        CrLogW("GetAiServerLaserOffset02mmResult  fail!!!\n"); 

    }else{
        CrLogI("get_x_offset=%lf,get_y_offset=%lf\n",get_x_offset,get_y_offset);
        // 保存偏移值
        if (get_x_offset > -8 && get_x_offset < 8 && get_y_offset > -8 && get_y_offset < 8) {  
            json_object *laserOffsetValueObj = json_object_new_object();
            json_object_object_add(laserOffsetValueObj, "laser_offset_x", json_object_new_double(laserCfg.x_offset + get_x_offset));
            json_object_object_add(laserOffsetValueObj, "laser_offset_y", json_object_new_double(laserCfg.y_offset + get_y_offset));
            json_object_object_add(laserOffsetValueObj, "laser_offset_z", json_object_new_double(laserCfg.z_offset));
            json_object_to_file_ext(GetLaserOffsetInfo(), laserOffsetValueObj, JSON_C_TO_STRING_PRETTY);
            json_object_put(laserOffsetValueObj);
            res = 0;
        }else{
            UpdataErrorStateToManager(FAULT_AI_LASER_OFFSET_CORRECT_FAIL, "laser offset correct fail", NULL);
            CrLogW("get_x_offset or get_y_offset out of range !!!\n"); 
        }
    }

   
THREAD_RUN_CANCEL:

    
    // 关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }
    //设置曝光参数
    AiServerSetExposure(aiServerSocket,1000);
    // 释放资源
    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);
    CrLogI("laser offset correction end\n");

    laserTesting=false;
    appFunModuleRun=false;
    return res;
}

/**
 * @description: 
 * @return {*}
 */
int StartAiFlowDetect(bool syncState, char *result)
{
    // 判断独立功能模块是否忙碌
    if (appFunModuleRun) {
        CrLogW("app fun module run busy!\n");
        return -1;
    }

    CrLogI("start ai flow detect");
    appFunModuleRun = true;
    
    // 启动流量检测，并自动应用检测结果
    int res = AiFlowDetectRun_Quick(syncState, result);
    //int res = AiFlowDetectTakePhotoRun();
    appFunModuleRun = false;
    return res;
}

/**
 * @description: 
 * @return {*}
 */
int StartLaserCalibration(void)
{
    // 判断独立功能模块是否忙碌
    if (appFunModuleRun) {
        CrLogW("app fun module run busy!\n");
        return -1;
    }

    CrLogI("start laser calibration");
    appFunModuleRun = true;
    
    //开始标定
    int res = LaserCalibrationRun();
    appFunModuleRun = false;
    CrLogI("end laser calibration");
    return res;
}

/**
 * @description: 
 * @return {*}
 */
int StartLaserScanningTable(void)
{
    // 判断独立功能模块是否忙碌
    if (appFunModuleRun) {
        CrLogW("app fun module run busy!\n");
        return -1;
    }

    CrLogI("start laser scanning table");
    appFunModuleRun = true;
    
    // 开始扫描床面
    //int res = LaserScanningTableRun();
    int res =LaserScanningTableRun_Quick();
    appFunModuleRun = false;
    CrLogI("end laser scanning table");
    return res;
}

/**
 * @description: 
 * @return {*}
 */
int StartLaserOffsetCorrection(void)
{
    // 判断独立功能模块是否忙碌
    if (appFunModuleRun) {
        CrLogW("app fun module run busy!\n");
        return -1;
    }

    CrLogI("start laser offset correction");
    appFunModuleRun = true;
    
    // 开始扫描床面
    int res = LaserOffsetCorrectionRun();
    // int res = LaserOffsetCorrectionSingleRun();
    appFunModuleRun = false;
    CrLogI("end laser offset correction");
    return res;
}


/**
 * @description: 
 * @return {*}
 * @param {FILE} *fd
 * @param {FlowDetectPara_t} para
 */
static int GetLineHighDetectPara(FILE *fd, LineHightPara_t *para)
{
    #define READ_LEN    1024
    char readBuff[READ_LEN] = {0};
    fseek(fd, 0, SEEK_SET);
    // 读取指令
    while (1)
    {
        // 判断是否读取成功
        if (!fgets(readBuff, READ_LEN, fd) && !feof(fd)) {
            bzero(readBuff, READ_LEN);
            continue;
        }
        // 判断文件读取结束
        if (feof(fd)) {
            return -1;
        }

        // 获取AI检测参数
        if (strstr(readBuff, "; Start x = ")) {
            DeleteGcodeTerminator(readBuff);
            para->start_x = atoi(readBuff + strlen("; Start x = "));
        }
        if (strstr(readBuff, "; Start y = ")) {
            DeleteGcodeTerminator(readBuff);
            para->start_y = atoi(readBuff + strlen("; Start y = "));
        }
        if (strstr(readBuff, "; End y = ")) {
            DeleteGcodeTerminator(readBuff);
            para->end_y = atoi(readBuff + strlen("; End y = "));
        }

        bzero(readBuff, READ_LEN);
    }
}

int laser_scan_start(int aiSocket,double start_x,double start_y,double end_y,int scan_speed,\
                int time_interval, char* key_text, char* save_path)
{
    int res = -1;
    int num = 0;
    char key[64]={0};
    int64_t last_ms = 0;

    if(aiSocket<=0)
        return -1;
    
    // 获取激光偏移参数
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if ((laserCfg.x_offset > -0.0001 && laserCfg.x_offset < 0.0001) &&
        (laserCfg.y_offset > -0.0001 && laserCfg.y_offset < 0.0001))
    {
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }


    // 开流
    if (AiServerOpenFlow(aiSocket) != 0) {
        CrLogW("set ai server open flow fail\n");
        goto FAIL;
    }
    usleep(100*1000);
    //读取一帧点云丢掉，因为第一帧点云会非常慢
    char cloud[10*1024]={0};
    GetAiServerPointCloud(aiSocket, cloud,2000);
    
    //创建保存json
    json_object *saveObj=json_object_new_object();
    //移动到终点并开始读点云
    SendDetectMoveXYGcode(start_x, end_y, scan_speed);
    //记录开始移动的时间戳
    int64_t start_ms = get_ticks_ms();
   
    while(appFunModuleRun){

        int64_t now_ms=get_ticks_ms();
        //每隔(time_interval)ms读取一次点云
        if(now_ms-last_ms >= time_interval){
            last_ms = now_ms;
            char pointCloud[100 * 1024] = {0};
            int64_t read_ms=get_ticks_ms();

            CrLogI("Scan[%d] read_ms=%ld\n",num,read_ms-start_ms);
            //读取点云
            if (GetAiServerPointCloud(aiSocket, pointCloud, 2000) != 0) {
                CrLogW("get point cloud fail\n");
                json_object *PointArray = json_object_new_array();
                snprintf(key,sizeof(key),"%s%d",key_text,num);
                num++;
                json_object_object_add(saveObj,key,PointArray);
            
            }else{
                json_object *pointCloudObj = json_tokener_parse(pointCloud);
                for (int i = 0; i < json_object_array_length(pointCloudObj); i++)
                {
                    // 获取点数据
                    json_object *pointObj = json_object_array_get_idx(pointCloudObj, i);
                    // 纠正Y坐标
                    json_object *value1Obj = json_object_array_get_idx(pointObj, 1);
                    int valueY=0;
#ifdef USE_CAM_COOR 
                    valueY = (start_y+laserCfg.y_offset)*1000 + (read_ms-start_ms) * scan_speed/60 + json_object_get_int(value1Obj) ;
#else
                    valueY = (start_y+laserCfg.y_offset)*1000 + (read_ms-start_ms) * scan_speed/60 - json_object_get_int(value1Obj) ;
#endif              
                    json_object_set_int(value1Obj, valueY);
                }
                // 保存点数据
                snprintf(key,sizeof(key),"%s%d",key_text,num);
                json_object_object_add(saveObj,key,pointCloudObj);
                num++;
            }  
        }else{
            usleep(500);
        }
        // 采集床板数据
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            break;
        }
    }
    // 点云数据保存文件
    if (appFunModuleRun) json_object_to_file_ext(save_path, saveObj, JSON_C_TO_STRING_PLAIN);
    
    res = 0;
 
FAIL:
    if(saveObj)json_object_put(saveObj);
    // 关流
    if (AiServerCloseFlow(aiSocket) != 0) {
        CrLogW("set ai server close flow fail\n");
    }
    return res;
}

/**
 * @description: 
 * @return {*}
 */
static int LaserDetectLineHightRun(void)
{
    CrLogI("laser detect line hight run\n");
    int res = -1;
    int aiServerSocket = -1;
    FILE *gcodeFileFd = NULL;
    LineHightPara_t linePara={0};
    char bed_temp_cmd[128]={0};
    char nozzle_temp_cmd[128]={0};
    int scan_speed=800;
    int time_interval=80;

#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif 
    laserTesting=true;
    appFunModuleRun=true;

    ClearFuncModuleRecvList();
     // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z) {
        SendFuncModuleCmd("CX_ROUGH_G28 EXTRUDER_TEMP=220 BED_TEMP=60");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
        SendFuncModuleCmd("CX_NOZZLE_CLEAR");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        // 细归零
        SendFuncModuleCmd("ACCURATE_G28");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
    }
    
    // 获取激光偏移参数
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if ((laserCfg.x_offset > -0.0001 && laserCfg.x_offset < 0.0001) &&
        (laserCfg.y_offset > -0.0001 && laserCfg.y_offset < 0.0001))
    {
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }

    //if (GetPrinter()->current_file.nozzle_target_temp > 0) {
        sprintf(nozzle_temp_cmd, "M190 S%f ", 60.0);//GetPrinter()->current_file.nozzle_target_temp);
    //} 
    //if (GetPrinter()->current_file.bed_target_temp > 0) {
        sprintf(bed_temp_cmd, "M109 S%f ", 140.0 );//GetPrinter()->current_file.bed_target_temp);
    //}
    SendFuncModuleCmd(bed_temp_cmd);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendFuncModuleCmd(nozzle_temp_cmd);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }

    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogW("connect ai server fail\n");
        goto THREAD_RUN_CANCEL;
    }
    //设置相机坐标系
    if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
        CrLogW("set laser coor fail\n");
        goto THREAD_RUN_CANCEL;
    }
    //设置稀疏档位
    if (AiServerLaserPointCloudLevel(aiServerSocket,0x02) != 0) {
        CrLogW("set laser point cloud level fail\n");
        goto THREAD_RUN_CANCEL;
    }
    
    //设置并行取流 0x01并行，0x00串行
    if (AiServerSetTakeOver(aiServerSocket,0x01) != 0) {
        CrLogW("set laser coor fail\n");
        goto THREAD_RUN_CANCEL;
    }
    //设置曝光参数
    AiServerSetExposure(aiServerSocket,1000);
    //设置曝光参数
    AiServerSetGain(aiServerSocket,1000);

    // 读取划线gcode文件
    char *filePath = GetLineHeightGcodeFilePath();
    gcodeFileFd = fopen(filePath, "r");
    if (gcodeFileFd == NULL) {
        CrLogI("gcode file open failed = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }
    //获取Gcode里的参数
    GetLineHighDetectPara(gcodeFileFd,&linePara);
    float start_x = linePara.start_x-laserCfg.x_offset;
    float start_y = linePara.start_y-laserCfg.y_offset;
    float end_y = linePara.end_y-laserCfg.y_offset;


    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveXYGcode(start_x, start_y, 6000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);

    //开始扫描
    laser_scan_start(aiServerSocket, start_x, start_y, end_y, scan_speed, time_interval,\
                    "table",GetTempLineHeightTablePoint());
    //回到等待加热位置
    SendDetectMoveXYGcode(10, 10, 12000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(0.1, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);

    bzero(bed_temp_cmd,sizeof(bed_temp_cmd));
    sprintf(bed_temp_cmd, "M109 S%f ", 220.0 );//GetPrinter()->current_file.bed_target_temp);
    //}
    SendFuncModuleCmd(bed_temp_cmd);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    //画线
    if(SendDrawFlowLineGcode(gcodeFileFd) != 0) {
        CrLogI("gcode file invalid = %s\n", filePath);
        goto THREAD_RUN_CANCEL;
    }

    // 保存当前打印状态
    int nozzleTargetTemp[NOZZLE_TEMP_SIZE] = {0}; // 喷嘴目标温度
    int fanState[MULTI_FAN_SIZE] = {0}; // 风扇状态
    for (int i = 0; i < NOZZLE_TEMP_SIZE; i++) {
        nozzleTargetTemp[i] = GetPrintState().nozzleMaxTemp[i];
        CrLogI("nozzleTargetTemp[%d] = %d", i, nozzleTargetTemp[i]);
    }
    for (int i = 0; i < MULTI_FAN_SIZE; i++) {
        fanState[i] = GetPrintState().fanState[i];
        CrLogI("fanState[%d] = %d", i, fanState[i]);
    }
    // 打开风扇快速降温
    SendFuncModuleCmd("M106 P0 S255");
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);
    SendFuncModuleCmd("M106 P2 S255");
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);
    // 喷嘴移动到暂停位置，降温
    SendFuncModuleCmd("FIRST_FLOOR_PAUSE_POSITION");
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);

    // 等待温度
    sleep(1);
    while (1) {
        if (GetPrintState().nozzleCurTemp[NOZZLE_TEMP]/100 > (GetPrintState().nozzleMaxTemp[NOZZLE_TEMP]/100 - 5) &&
            GetPrintState().nozzleCurTemp[NOZZLE_TEMP]/100 < (GetPrintState().nozzleMaxTemp[NOZZLE_TEMP]/100 + 5)
        ) break;
        usleep(10 * 1000);
    }
    // 关闭风扇
    SendFuncModuleCmd("M106 P0 S0");
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);

    SendFuncModuleCmd("M106 P2 S0");
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    } while (1);
    //移动到扫码起点
    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveXYGcode(start_x, start_y, 6000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);

    laser_scan_start(aiServerSocket,start_x, start_y, end_y, scan_speed, time_interval,\
                    "line",GetTempLineHeightLinePoint());

    SendDetectMoveXYGcode(10, 10, 12000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(0.1, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto THREAD_RUN_CANCEL;
        usleep(10 * 1000);
    } while (1);

THREAD_RUN_CANCEL:

    // 释放资源
    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);
    laserTesting=false;
    appFunModuleRun=false;
    CrLogI("laser detect line hight end\n");

    return res;
}


/****************************************************************************
 ************************ 轮廓仪整机测试 **************************************
 ****************************************************************************/
;

/**
 * @description: 
 * @return {*}
 * @param {FILE} *fd
 * @param {FlowDetectPara_t} para
 */
int GetLaerTestPara(FILE *fd, LaserTest_t *para)
{
    #define READ_LEN    1024
    char readBuff[READ_LEN] = {0};
    fseek(fd, 0, SEEK_SET);

    // 读取指令
    while (1)
    {
        // 判断是否读取成功
        if (!fgets(readBuff, READ_LEN, fd) && !feof(fd)) {
            bzero(readBuff, READ_LEN);
            continue;
        }
        // 判断文件读取结束
        if (feof(fd)) {
            return -1;
        }

        // 获取AI检测参数
        if (strstr(readBuff, "; Laser test start x = ")) {
            DeleteGcodeTerminator(readBuff);
            para->start_x = atoi(readBuff + strlen("; Laser test start x = "));
        }
        else if (strstr(readBuff, "; Laser test start y = ")) {
            DeleteGcodeTerminator(readBuff);
            para->start_y = atoi(readBuff + strlen("; Laser test start y = "));
        }
        else if (strstr(readBuff, "; Laser test len x = ")) {
            DeleteGcodeTerminator(readBuff);
            para->len_x = atoi(readBuff + strlen("; Laser test len x = "));
        }
        else if (strstr(readBuff, "; Laser test len y = ")) {
            DeleteGcodeTerminator(readBuff);
            para->len_y = atof(readBuff + strlen("; Laser test len y = "));
        }
   
        bzero(readBuff, READ_LEN);
    }
}

/**
 * @description: 整机激光模组跟热床装配自检
 * @return {*}
 */
int StartLaserBedSelfTest(void)
{
    CrLogI("laser bed self test start\n");
    int res = -1;
    int aiServerSocket = -1;
    LaserTest_t laserPara={0};
 #ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif 
    laserTesting=true;
    appFunModuleRun=true;
    ClearFuncModuleRecvList();

    // 读取划线gcode文件
    char *filePath = GetLaserTestGcodeFilePath();
    FILE *gcodeFileFd = fopen(filePath, "r");
    if (gcodeFileFd == NULL) {
        CrLogI("gcode file open failed = %s\n", filePath);
        goto FAIL;
    }

    // 获取激光偏移参数
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if ((laserCfg.x_offset > -0.0001 && laserCfg.x_offset < 0.0001) &&
        (laserCfg.y_offset > -0.0001 && laserCfg.y_offset < 0.0001))
    {
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }

    // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z)
    {
        SendFuncModuleCmd("CX_ROUGH_G28 EXTRUDER_TEMP=220 BED_TEMP=60");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto FAIL;
            usleep(10 * 1000);
        } while (1);
        SendFuncModuleCmd("CX_NOZZLE_CLEAR");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        // 细归零
        SendFuncModuleCmd("ACCURATE_G28");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
    }
   

#if 1
    //读取划线指令
    if (SendNextDrawLineGcode(gcodeFileFd) != 0) {
        CrLogI("gcode file invalid = %s\n", filePath);
        goto FAIL;
    }
    // 开始划线
    while (appFunModuleRun)
    {
        // 获取前一帧指令响应
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            // 读取划线指令
            if (SendNextDrawLineGcode(gcodeFileFd) != 0) {
                CrLogI("draw line finish");
                break;
            }
        }
        usleep(10 * 1000);
    }
#endif
    GetLaerTestPara(gcodeFileFd,&laserPara);
    CrLogI("laser test param len_x= %f\n",laserPara.len_x);
    CrLogI("laser test param len_y= %f\n",laserPara.len_y);
    CrLogI("laser test param start_x= %f\n",laserPara.start_x);
    CrLogI("laser test param start_y= %f\n",laserPara.start_y);
    //激光移动到打印区域内
    float laser_x = laserPara.start_x + laserPara.len_x/2 - laserCfg.x_offset;
    float laser_y = laserPara.start_y + laserPara.len_y/2 - laserCfg.y_offset;
    CrLogI("laser_x = %f\n",laser_x);
    CrLogI("laser_y = %f\n",laser_y);
    // 判断任务是否取消
   
    SendDetectMoveXYGcode(laser_x, laser_y, 9000);
    //获取前一帧指令响应
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    //获取前一帧指令响应
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    

    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogI("connect ai server fail\n");
        goto FAIL;
    }
     //设置曝光参数
    AiServerSetExposure(aiServerSocket,3500);
    //设置曝光参数
    AiServerSetGain(aiServerSocket,2000);
    //开激光
    res = AiServerOpenLaser(aiServerSocket,true);
    if(res){
        CrLogI("open laser fail\n");
        goto FAIL;
    }
    //开灯
    res = AiServerOpenLight(aiServerSocket,true);
    if(res){
        CrLogI("open light fail\n");
        goto FAIL;
    }

    //抓拍一张IR图,保存格式为JPG 
    int image_size=0;
    res = AiServerCapIrImage(aiServerSocket,2,1,&image_size);
    if(res){
        CrLogI("capture image fail\n");
        goto FAIL;
    }

    //获取IR图写到路径文件中
    char image2[128]={0};
    if(image_size>0 && appFunModuleRun){
        //判断保存图片的文件夹是否存在
        if (access(GetUserAiImageDirPtah(), F_OK) != 0)
        {
            char cmd[128] = {0};
            snprintf(cmd, sizeof(cmd), "mkdir -p '%s'", GetUserAiImageDirPtah());

            // 调用系统命令
            char sysRes[512] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes))){
                CrLogW("system fail! res = %s\n", sysRes);
            }       
        }
        snprintf(image2,sizeof(image2),"%s/%s",GetUserAiImageDirPtah(),"irImage2.jpg");
        CrLogI("IR image write to %s\n",image2);
        res = AiServerGetIrImage(aiServerSocket,image2,image_size);
        if(res){
            CrLogI("get image fail\n");
            goto FAIL;
        }

        char buff[256]={0};
        snprintf(buff,sizeof(buff),"2 %s",image2);
        int len = strlen(buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    }
    
    
    //关灯
    res = AiServerOpenLight(aiServerSocket,false);
    if(res){
        CrLogI("open light fail\n");
        goto FAIL;
    }
    //关激光
    res = AiServerOpenLaser(aiServerSocket,false);
    if(res){
        CrLogI("close laser fail\n");
        goto FAIL;
    }

 

FAIL:
    //关灯
    AiServerOpenLight(aiServerSocket,false);
    //关激光
    AiServerOpenLaser(aiServerSocket,false);
    //设置曝光参数
    AiServerSetExposure(aiServerSocket,1000);
    //设置曝光参数
    AiServerSetGain(aiServerSocket,1000);
    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);
    laserTesting=false;
    appFunModuleRun=false;
    CrLogI("laser bed self test end\n");
    return res;
    
}
/**
 * @description: 整机激光模组跟热床装配自检,通过拍照判断是否通过
 * @return {*}
 */
int StartLaserBedTakePhotoAutoSelfTest(void)
{
    CrLogI("laser bed self test start\n");
    int res = -1;
    int aiServerSocket = -1;
    LaserTest_t laserPara={0};
 #ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif 
    laserTesting=true;
    appFunModuleRun=true;
    ClearFuncModuleRecvList();

    // 获取激光偏移参数
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if ((laserCfg.x_offset > -0.0001 && laserCfg.x_offset < 0.0001) &&
        (laserCfg.y_offset > -0.0001 && laserCfg.y_offset < 0.0001))
    {
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }

    // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z)
    {
        SendFuncModuleCmd("CX_ROUGH_G28 EXTRUDER_TEMP=220 BED_TEMP=60");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto FAIL;
            usleep(10 * 1000);
        } while (1);
        SendFuncModuleCmd("CX_NOZZLE_CLEAR");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        // 细归零
        SendFuncModuleCmd("ACCURATE_G28");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
    }
   
#if 1
    // 读取划线gcode文件
    char *filePath = GetLaserAutoTestGcodeFilePath();
    FILE *gcodeFileFd = fopen(filePath, "r");
    if (gcodeFileFd == NULL) {
        CrLogI("gcode file open failed = %s\n", filePath);
        goto FAIL;
    }
    //读取划线指令
    if (SendNextDrawLineGcode(gcodeFileFd) != 0) {
        CrLogI("gcode file invalid = %s\n", filePath);
        goto FAIL;
    }
    // 开始划线
    while (appFunModuleRun)
    {
        // 获取前一帧指令响应
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            // 读取划线指令
            if (SendNextDrawLineGcode(gcodeFileFd) != 0) {
                CrLogI("draw line finish");
                break;
            }
        }
        usleep(10 * 1000);
    }
#endif
    GetLaerTestPara(gcodeFileFd,&laserPara);
    CrLogI("laser test param len_x= %f\n",laserPara.len_x);
    CrLogI("laser test param len_y= %f\n",laserPara.len_y);
    CrLogI("laser test param start_x= %f\n",laserPara.start_x);
    CrLogI("laser test param start_y= %f\n",laserPara.start_y);
    //激光移动到打印区域内
    float laser_x = laserPara.start_x + laserPara.len_x/2 - laserCfg.x_offset;
    float laser_y = laserPara.start_y + laserPara.len_y/2 - laserCfg.y_offset;
    CrLogI("laser_x = %f\n",laser_x);
    CrLogI("laser_y = %f\n",laser_y);
    // 判断任务是否取消
    SendDetectMoveXYGcode(laser_x, laser_y, 9000);
    //获取前一帧指令响应
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    //获取前一帧指令响应
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    

    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogI("connect ai server fail\n");
        goto FAIL;
    }
    //设置曝光参数
    AiServerSetExposure(aiServerSocket,3500);
    //设置曝光参数
    AiServerSetGain(aiServerSocket,2000);
    //开激光
    res = AiServerOpenLaser(aiServerSocket,true);
    if(res){
        CrLogI("open laser fail\n");
        goto FAIL;
    }
    //开灯
    res = AiServerOpenLight(aiServerSocket,true);
    if(res){
        CrLogI("open light fail\n");
        goto FAIL;
    }

    //抓拍一张IR图,保存格式为JPG 
    int image_size=0;
    res = AiServerCapIrImage(aiServerSocket,2,1,&image_size);
    if(res){
        CrLogI("capture image fail\n");
        goto FAIL;
    }

    //获取IR图写到路径文件中
    char image2[128]={0};
    if(image_size>0 && appFunModuleRun){
        //判断保存图片的文件夹是否存在
        if (access(GetUserAiImageDirPtah(), F_OK) != 0)
        {
            char cmd[128] = {0};
            snprintf(cmd, sizeof(cmd), "mkdir -p '%s'", GetUserAiImageDirPtah());

            // 调用系统命令
            char sysRes[512] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes))){
                CrLogW("system fail! res = %s\n", sysRes);
            }       
        }
        snprintf(image2,sizeof(image2),"%s/%s",GetUserAiImageDirPtah(),"LaserIrImage2.jpg");
        CrLogI("IR image write to %s\n",image2);
        res = AiServerGetIrImage(aiServerSocket,image2,image_size);
        if(res){
            CrLogI("get image fail\n");
            goto FAIL;
        }

        char buff[256]={0};
        snprintf(buff,sizeof(buff),"2 %s",image2);
        int len = strlen(buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    }
    
    //抓拍一张IR图,保存格式为JPG 
    int AiImage_size=0;
    res = AiServerCapIrImage(aiServerSocket,2,3,&AiImage_size);
    if(res){
        CrLogI("capture ai image fail\n");
        goto FAIL;
    }

    //获取IR图写到路径文件中
    char AiImage[128]={0};
    if(AiImage_size>0 && appFunModuleRun){
        //判断保存图片的文件夹是否存在
        if (access(GetUserAiImageDirPtah(), F_OK) != 0)
        {
            char cmd[128] = {0};
            snprintf(cmd, sizeof(cmd), "mkdir -p '%s'", GetUserAiImageDirPtah());

            // 调用系统命令
            char sysRes[512] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes))){
                CrLogW("system fail! res = %s\n", sysRes);
            }       
        }
        snprintf(AiImage,sizeof(AiImage),"%s/%s",GetUserAiImageDirPtah(),"AiIrImage.jpg");
        CrLogI("AI IR image write to %s\n",AiImage);
        res = AiServerGetIrImage(aiServerSocket,AiImage,AiImage_size);
        if(res){
            CrLogI("get image fail\n");
            goto FAIL;
        }
    }

 
FAIL:
    //关灯
    AiServerOpenLight(aiServerSocket,false);
    //关激光
    AiServerOpenLaser(aiServerSocket,false);
    //设置曝光参数
    AiServerSetExposure(aiServerSocket,1000);
    //设置曝光参数
    AiServerSetGain(aiServerSocket,1000);

    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);
    laserTesting=false;
    appFunModuleRun=false;
    CrLogI("laser bed self test end\n");
    return res;
    
}



/**
 * @description: 整机激光模组跟热床装配自检,通过两帧点云拟合判断是否通过
 * @return {*}
 */
int StartLaserBedGetCloudAutoSelfTest(void)
{
    CrLogI("laser bed self test start\n");
    int res = -1;
    int aiServerSocket = -1;
    LaserTest_t laserPara={0};
 #ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif 
    laserTesting=true;
    appFunModuleRun=true;
    ClearFuncModuleRecvList();

    // 获取激光偏移参数
    LaserConfig_t laserCfg = GetSaveLaserOffset();
    if ((laserCfg.x_offset > -0.0001 && laserCfg.x_offset < 0.0001) &&
        (laserCfg.y_offset > -0.0001 && laserCfg.y_offset < 0.0001))
    {
        laserCfg.x_offset=LASER_X_OFFSET;
        laserCfg.y_offset=LASER_Y_OFFSET;
        laserCfg.z_offset = LASER_Z_OFFSET;
    }

    // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z)
    {
        SendFuncModuleCmd("CX_ROUGH_G28 EXTRUDER_TEMP=220 BED_TEMP=60");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto FAIL;
            usleep(10 * 1000);
        } while (1);
        SendFuncModuleCmd("CX_NOZZLE_CLEAR");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        // 细归零
        SendFuncModuleCmd("ACCURATE_G28");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
    }
    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogI("connect ai server fail\n");
        goto FAIL;
    }
    
    //关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set laser flow close fail\n");
        goto FAIL;
    }

    //设置相机坐标系
    if (AiServerSetCoor(aiServerSocket,0x01) != 0) {
        CrLogW("set laser coor fail\n");
        goto FAIL;
    }
    //设置稀疏档位
    if (AiServerLaserPointCloudLevel(aiServerSocket,0x00) != 0) {
        CrLogW("set laser point cloud level fail\n");
        goto FAIL;
    }

    //设置并行取流 0x01并行，0x00串行
    if (AiServerSetTakeOver(aiServerSocket,0x00) != 0) {
        CrLogW("set laser coor fail\n");
        goto FAIL;
    }
    //关灯
    AiServerOpenLight(aiServerSocket,false);
    //关激光
    AiServerOpenLaser(aiServerSocket,false);
    //设置曝光参数
    AiServerSetExposure(aiServerSocket,1000);
    //设置曝光参数
    AiServerSetGain(aiServerSocket,1000);


    // 读取划线gcode文件
    char *filePath = GetLaserAutoTestGcodeFilePath();
    FILE *gcodeFileFd = fopen(filePath, "r");
    if (gcodeFileFd == NULL) {
        CrLogI("gcode file open failed = %s\n", filePath);
        goto FAIL;
    }
    GetLaerTestPara(gcodeFileFd,&laserPara);
    CrLogI("laser test param len_x= %f\n",laserPara.len_x);
    CrLogI("laser test param len_y= %f\n",laserPara.len_y);
    CrLogI("laser test param start_x= %f\n",laserPara.start_x);
    CrLogI("laser test param start_y= %f\n",laserPara.start_y);
    //激光移动到打印区域内
    float laser_x = laserPara.start_x + laserPara.len_x/2 - laserCfg.x_offset;
    float laser_y = laserPara.start_y + laserPara.len_y/2 - laserCfg.y_offset;
    CrLogI("laser_x = %f\n",laser_x);
    CrLogI("laser_y = %f\n",laser_y);

    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    //获取前一帧指令响应
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveXYGcode(laser_x, laser_y, 9000);
    //获取前一帧指令响应
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    //获取前一帧指令响应
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }

    //开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set laser flow close fail\n");
        goto FAIL;
    }
    usleep(50*1000);
    char pointCloud1[100 * 1024] = {0};
    if (GetAiServerPointCloud(aiServerSocket, pointCloud1, 2000) != 0) {
        CrLogW("get point cloud fail\n");
        goto FAIL;
    }
    else {
        // 保存点云到文件
        json_object *tablePcObj = json_tokener_parse(pointCloud1);
        if(tablePcObj){
            json_object_to_file_ext(GetTempAutoTestScanTablePoint(), tablePcObj, JSON_C_TO_STRING_PRETTY);
            CrLogI("tablePcObj length = %d\n",json_object_array_length(tablePcObj));
            json_object_put(tablePcObj);
        }
    }
    //关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set laser flow close fail\n");
        goto FAIL;
    }

    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    //获取前一帧指令响应
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveXYGcode(10, 10, 12000);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto FAIL;
        usleep(10 * 1000);
    } while (1);
    SendDetectMoveZGcode(0.2, 600);
    do {
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        if (!appFunModuleRun) goto FAIL;
        usleep(10 * 1000);
    } while (1);

#if 1
    fseek(gcodeFileFd, 0, SEEK_SET);
    //读取划线指令
    if (SendNextDrawLineGcode(gcodeFileFd) != 0) {
        CrLogI("gcode file invalid = %s\n", filePath);
        goto FAIL;
    }
    // 开始划线
    while (appFunModuleRun)
    {
        // 获取前一帧指令响应
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) {
            // 读取划线指令
            if (SendNextDrawLineGcode(gcodeFileFd) != 0) {
                CrLogI("draw line finish");
                break;
            }
        }
        usleep(10 * 1000);
    }
#endif
    
    
    // 判断任务是否取消
    SendDetectMoveXYGcode(laser_x, laser_y, 9000);
    //获取前一帧指令响应
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveZGcode(laserCfg.z_offset, 600);
    //获取前一帧指令响应
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }

    //开流
    if (AiServerOpenFlow(aiServerSocket) != 0) {
        CrLogW("set laser flow close fail\n");
        goto FAIL;
    }
    usleep(50*1000);
    char pointCloud2[100 * 1024] = {0};
    if (GetAiServerPointCloud(aiServerSocket, pointCloud2, 2000) != 0) {
        CrLogW("get point cloud fail\n");
        goto FAIL;
    }
    else {
        // 保存点云到文件
        json_object *scanPcObj = json_tokener_parse(pointCloud2);
        if(scanPcObj){
            json_object_to_file_ext(GetTempAutoTestScanLinePoint(), scanPcObj, JSON_C_TO_STRING_PRETTY);
            CrLogI("scanPcObj length = %d\n",json_object_array_length(scanPcObj));
            json_object_put(scanPcObj);
        }
    }
    //关流
    if (AiServerCloseFlow(aiServerSocket) != 0) {
        CrLogW("set laser flow close fail\n");
        goto FAIL;
    }

    int test_res=-1;
    res = GetAiServerAutoTestResult(aiServerSocket,GetTempAutoTestScanTablePoint(),GetTempAutoTestScanLinePoint(),&test_res);
    if(res==0){
        if(test_res==0){
            //发送结果给到UI
            char buff[256]={0};
            snprintf(buff,sizeof(buff),"8 OK");
            int len = strlen(buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
        }else{
            //发送结果给到UI
            char buff[256]={0};
            snprintf(buff,sizeof(buff),"8 NG");
            int len = strlen(buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
        }
        CrLogI("[GetAiServerAutoTestResult] test_res = %d\n",test_res);
        
    }else{
        CrLogI("[GetAiServerAutoTestResult] get result fail, test_res= %d\n",test_res);
        //发送结果给到UI
        char buff[256]={0};
        snprintf(buff,sizeof(buff),"8 NG");
        int len = strlen(buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    }


    //设置曝光参数
    AiServerSetExposure(aiServerSocket,3500);
    //设置曝光参数
    AiServerSetGain(aiServerSocket,2000);
    //开激光
    res = AiServerOpenLaser(aiServerSocket,true);
    if(res){
        CrLogI("open laser fail\n");
        goto FAIL;
    }
    //开灯
    res = AiServerOpenLight(aiServerSocket,true);
    if(res){
        CrLogI("open light fail\n");
        goto FAIL;
    }

    //抓拍一张IR图,保存格式为JPG 
    int image_size=0;
    res = AiServerCapIrImage(aiServerSocket,2,1,&image_size);
    if(res){
        CrLogI("capture image fail\n");
        goto FAIL;
    }

    //获取IR图写到路径文件中
    char image2[128]={0};
    if(image_size>0 && appFunModuleRun){
        //判断保存图片的文件夹是否存在
        if (access(GetUserAiImageDirPtah(), F_OK) != 0)
        {
            char cmd[128] = {0};
            snprintf(cmd, sizeof(cmd), "mkdir -p '%s'", GetUserAiImageDirPtah());

            // 调用系统命令
            char sysRes[512] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes))){
                CrLogW("system fail! res = %s\n", sysRes);
            }       
        }
        snprintf(image2,sizeof(image2),"%s/%s",GetUserAiImageDirPtah(),"LaserIrImage2.jpg");
        CrLogI("IR image write to %s\n",image2);
        res = AiServerGetIrImage(aiServerSocket,image2,image_size);
        if(res){
            CrLogI("get image fail\n");
            goto FAIL;
        }

        char buff[256]={0};
        snprintf(buff,sizeof(buff),"2 %s",image2);
        int len = strlen(buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    }
    
   

 
FAIL:
    //关灯
    AiServerOpenLight(aiServerSocket,false);
    //关激光
    AiServerOpenLaser(aiServerSocket,false);
    //设置曝光参数
    AiServerSetExposure(aiServerSocket,1000);
    //设置曝光参数
    AiServerSetGain(aiServerSocket,1000);

    if (aiServerSocket) close(aiServerSocket);
    if (gcodeFileFd) fclose(gcodeFileFd);
    laserTesting=false;
    appFunModuleRun=false;
    CrLogI("laser bed self test end\n");
    return res;
    
}
/**
 * @description: 整机激光模组和标定板装配自检
 * @return {*}
 */
int StartLaserCaliBoardSelfTest(void)
{
    CrLogI("laser cali board self test start\n");
    int res = -1;
    int aiServerSocket = -1;  
    int stepcount=0;
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif
    laserTesting=true;
    appFunModuleRun=true;
    ClearFuncModuleRecvList();

    // 获取标定贴纸偏移
    LaserConfig_t tickerOffset = GetSavesTickerOffset();
    if ((tickerOffset.x_offset > -0.0001 && tickerOffset.x_offset < 0.0001) &&
        (tickerOffset.y_offset > -0.0001 && tickerOffset.y_offset < 0.0001))
    {
        tickerOffset.x_offset=CALI_X_OFFSET;
        tickerOffset.y_offset=CALI_Y_OFFSET;
        tickerOffset.z_offset = CALI_Z_OFFSET;
    }

    // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z)
    {
        SendFuncModuleCmd("CX_ROUGH_G28 EXTRUDER_TEMP=220 BED_TEMP=60");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto FAIL;
            usleep(10 * 1000);
        } while (1);
        SendFuncModuleCmd("CX_NOZZLE_CLEAR");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto FAIL;
            usleep(10 * 1000);
        }
        // 细归零
        SendFuncModuleCmd("ACCURATE_G28");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto FAIL;
            usleep(10 * 1000);
        } while (1);
    }
   

    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogW("[machine test]connect ai server fail\n");
        goto FAIL;
    }

    //标定流程
    if (appFunModuleRun) {
        // 关流
        if (AiServerCloseFlow(aiServerSocket) != 0) {
            CrLogW("[machine test]set ai server close flow fail\n");
            goto FAIL;
        } 
        //关灯
        if (AiServerOpenLight(aiServerSocket,false) != 0) {
            CrLogW("[machine test]set ai server close light fail\n");
            goto FAIL;
        }
    }

    float y_offset=tickerOffset.y_offset;
    while(appFunModuleRun){
        //移动到标定板位置
        SendDetectMoveXYGcode(tickerOffset.x_offset, y_offset, 8000); 
        //获取前一帧指令响应
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        SendDetectMoveZGcode(tickerOffset.z_offset, 600); 
        //获取前一帧指令响应
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        usleep(200 * 1000);

        //尝试10次
        if(stepcount++ >10){
            CrLogI("[machine test]set ai server calibration fail\n");
            //发送结果给UI
            char buff[256]={0};
            snprintf(buff,sizeof(buff),"3 %s","NG");
            int len = strlen(buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
            break;
        }
        //设定标定步骤1
        if(AiServerLaserCali(aiServerSocket,1)!=0){
            //如果标定失败，则前5次往Y轴正方向偏移，后5次往Y轴负方向偏移来矫正标定位置
            CrLogW("[machine test]set ai server calibration step 1 fail\n");
            if(stepcount<5){
                y_offset+=(float)((stepcount+1)*0.1);
            }else{
                y_offset-=(float)((stepcount+5)*0.1);  
            } 
        }else {
            //标定第一步成功
            usleep(200 * 1000);
            //Z轴抬高2mm
            SendDetectMoveZGcode(tickerOffset.z_offset + CALI_STEP2_Z_OFFSET, 600);
            //等待移动
            while (appFunModuleRun){
                CmdSyncRecv_t recv = GetFuncModuleRecv();
                if (recv.mtype != 0) break;
                usleep(10 * 1000);
            }
            usleep(100 * 1000);
            //设定标定步骤2
            if(AiServerLaserCali(aiServerSocket,2)!=0){
                CrLogW("[machine test]set ai server calibration step 2 fail\n");
            }else{
                //发送结果给UI
                char buff[256]={0};
                snprintf(buff,sizeof(buff),"3 %s","OK");
                int len = strlen(buff);
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
                MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
                break;
            } 
        }
        usleep(10 * 1000);
    }

    SendDetectMoveZGcode(tickerOffset.z_offset,600);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }

    // 判断任务是否取消
    if (appFunModuleRun) {
        //移动到标定板位置
        SendDetectMoveXYGcode(tickerOffset.x_offset, tickerOffset.y_offset,6000);
        //获取前一帧指令响应
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
    }

    int image_size=0;
    if(appFunModuleRun){
        //开激光
        res = AiServerOpenLaser(aiServerSocket,true);
        if(res){
            CrLogW("[machine test]open laser fail\n");
            goto FAIL;
        }
        //开灯
        res = AiServerOpenLight(aiServerSocket,true);
        if(res){
            CrLogW("[machine test]open light fail\n");
            goto FAIL;
        }

        //抓拍一张IR图,保存格式为JPG 
        res = AiServerCapIrImage(aiServerSocket,2,1,&image_size);
        if(res){
            CrLogW("[machine test]capture image fail\n");
            goto FAIL;
        }
    }
    //获取IR图写到路径文件中
    char image1[128]={0};
    if(image_size>0 && appFunModuleRun){
        //判断保存图片的文件夹是否存在
        if (access(GetUserAiImageDirPtah(), F_OK) != 0)
        {
            char cmd[128] = {0};
            snprintf(cmd, sizeof(cmd), "mkdir -p '%s'", GetUserAiImageDirPtah());

            // 调用系统命令
            char sysRes[512] = {0};
            if (!PopenSystem(cmd, sysRes, sizeof(sysRes))){
                CrLogW("system fail! res = %s\n", sysRes);
            }       
        }
        snprintf(image1,sizeof(image1),"%s/%s",GetUserAiImageDirPtah(),"LaserIrImage1.jpg");
        CrLogI("%s\n",image1);
        res = AiServerGetIrImage(aiServerSocket,image1,image_size);
        if(res){
            CrLogI("[machine test]get image fail\n");
            goto FAIL;
        }
        //发送结果给UI
        char buff[256]={0};
        snprintf(buff,sizeof(buff),"1 %s",image1);
        int len = strlen(buff);
        CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
        MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    }
    //关灯
    res = AiServerOpenLight(aiServerSocket,false);
    if(res){
        CrLogW("[machine test]open light fail\n");
        goto FAIL;
    }
    //关激光
    res = AiServerOpenLaser(aiServerSocket,false);
    if(res){
        CrLogW("[machine test]close laser fail\n");
        goto FAIL;
    }



FAIL:
    if (aiServerSocket) close(aiServerSocket);
    laserTesting=false;
    appFunModuleRun=false;
    CrLogI("laser cali board self test end\n"); 
    return res;
}

int startLaserPressureTest(void)
{
    CrLogI("laser pressure test start\n");
    int res = -1;
    int aiServerSocket = -1;  
    int stepcount=0;
    char endBuf[256]={0};
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return res;
    }
#endif
    laserTesting=true;
    appFunModuleRun=true;
    ClearFuncModuleRecvList();

    // 获取标定贴纸偏移
    LaserConfig_t tickerOffset = GetSavesTickerOffset();
    if ((tickerOffset.x_offset > -0.0001 && tickerOffset.x_offset < 0.0001) &&
        (tickerOffset.y_offset > -0.0001 && tickerOffset.y_offset < 0.0001))
    {
        tickerOffset.x_offset=CALI_X_OFFSET;
        tickerOffset.y_offset=CALI_Y_OFFSET;
        tickerOffset.z_offset = CALI_Z_OFFSET;
    }

    // 判断轴是否归位
    if (!GetPrintState().homedAxes.x || !GetPrintState().homedAxes.y || !GetPrintState().homedAxes.z)
    {
        SendFuncModuleCmd("CX_ROUGH_G28 EXTRUDER_TEMP=220 BED_TEMP=60");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            if (!appFunModuleRun) goto FAIL;
            usleep(10 * 1000);
        } while (1);
        SendFuncModuleCmd("CX_NOZZLE_CLEAR");
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        // 细归零
        SendFuncModuleCmd("ACCURATE_G28");
        do {
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        } while (1);
    }
   

    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogW("[pressure test]connect ai server fail\n");
        goto FAIL;
    }

    //标定流程
    if (appFunModuleRun) {
        // 关流
        if (AiServerCloseFlow(aiServerSocket) != 0) {
            CrLogW("[pressure test]set ai server close flow fail\n");
            goto FAIL;
        } 
        //关灯
        if (AiServerOpenLight(aiServerSocket,false) != 0) {
            CrLogW("[pressure test]set ai server close light fail\n");
            goto FAIL;
        }
    }

    float y_offset=tickerOffset.y_offset;
    while(appFunModuleRun){
        //移动到标定板位置
        SendDetectMoveXYGcode(tickerOffset.x_offset, y_offset, 8000); 
        //获取前一帧指令响应
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        SendDetectMoveZGcode(tickerOffset.z_offset, 600); 
        //获取前一帧指令响应
        while (appFunModuleRun){
            CmdSyncRecv_t recv = GetFuncModuleRecv();
            if (recv.mtype != 0) break;
            usleep(10 * 1000);
        }
        usleep(200 * 1000);

        //尝试10次
        if(stepcount++ >10){
            CrLogI("[pressure test]set ai server calibration fail\n");
            //发送结果给UI
            char buff[256]={0};
            snprintf(buff,sizeof(buff),"7 %s","NG");
            int len = strlen(buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
            break;
        }
        //设定标定步骤1
        if(AiServerLaserCali(aiServerSocket,1)!=0){
            //如果标定失败，则前5次往Y轴正方向偏移，后5次往Y轴负方向偏移来矫正标定位置
            CrLogW("[pressure test]set ai server calibration step 1 fail\n");
            if(stepcount<5){
                y_offset+=(float)((stepcount+1)*0.1);
            }else{
                y_offset-=(float)((stepcount+5)*0.1);  
            } 
        }else {
            //标定第一步成功
            usleep(200 * 1000);
            //Z轴抬高2mm
            SendDetectMoveZGcode(tickerOffset.z_offset + CALI_STEP2_Z_OFFSET, 600);
            //等待移动
            while (appFunModuleRun){
                CmdSyncRecv_t recv = GetFuncModuleRecv();
                if (recv.mtype != 0) break;
                usleep(10 * 1000);
            }
            usleep(300 * 1000);
            //设定标定步骤2
            if(AiServerLaserCali(aiServerSocket,2)!=0){
                CrLogW("[pressure test]set ai server calibration step 2 fail\n");
            }else{
                //发送结果给UI
                char buff[256]={0};
                snprintf(buff,sizeof(buff),"7 %s","OK");
                int len = strlen(buff);
                CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
                MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
                break;
            } 
        }
        usleep(10 * 1000);
    }

    SendDetectMoveZGcode(tickerOffset.z_offset,600);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }

    SendDetectMoveXYGcode(GetPrintSavePara().devMaxSize.y/100 - 1,150,12000);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
   

FAIL:
    //发送结果给UI
    snprintf(endBuf,sizeof(endBuf),"7 %s","END");
    int len = strlen(endBuf);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, endBuf, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);

    if (aiServerSocket) close(aiServerSocket);
    laserTesting=false;
    appFunModuleRun=false;
    CrLogI("laser pressure test end\n");
    return res;
}

/**
 * @description: 整机激光模组测试激光开关
 * @return {*}
 */
int StartLaserTestOpenLaser(bool open)
{
    CrLogI("laser test %s laser \n",open? "open":"close");
    int res = -1;
    int aiServerSocket = -1;
     if(laserTesting) {
        CrLogI("laser testing\n");
        return -1;
    }
    laserTesting=true;
    appFunModuleRun=true;
    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogW("connect ai server fail\n");
        goto FAIL;
    }
   
    //开激光
    res = AiServerOpenLaser(aiServerSocket,open);
    if(res){
        CrLogW("%s laser fail\n",open? "open":"close");
        goto FAIL;
    }
    
   
FAIL:

    if (aiServerSocket) close(aiServerSocket);
    laserTesting=false;
    appFunModuleRun=false;
    return res;
}

void *laserTestStep1(void* arg)
{
    //LaserDetectLineHightRun();
    StartLaserCaliBoardSelfTest();
    SendFuncModuleCmd("M104 S0");
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendFuncModuleCmd("M140 S0");
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveZGcode(4,600);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveXYGcode(10,10,12000);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveZGcode(0.2,600);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    return NULL;
}

void *laserTestStep2(void* arg)
{
    if(LaserOffsetCorrection_New02mm_Run()>=0){
    //if(LaserOffsetCorrectionRun()>=0){
        //StartLaserBedSelfTest();
        StartLaserBedGetCloudAutoSelfTest();
    }
    SendFuncModuleCmd("M104 S0");
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendFuncModuleCmd("M140 S0");
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
   
    return NULL;
}

void *flowDetectTest(void* arg)
{
    laserTesting=true;
    appFunModuleRun=true;
    AiFlowDetectRun_Quick_Step1();
    for(int i=0;i<5;i++){
        AiFlowDetectRun_Quick_Step2(i); 
    }
    SendFuncModuleCmd("M104 S0");
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendFuncModuleCmd("M140 S0");
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveZGcode(15,600);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendDetectMoveXYGcode(150,150,12000);
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendFuncModuleCmd("M84");
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    
    laserTesting=false;
    appFunModuleRun=false;
    return NULL;
}

void *laserPressureTest(void* arg)
{
    startLaserPressureTest();
    SendFuncModuleCmd("M104 S0");
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    SendFuncModuleCmd("M140 S0");
    while (appFunModuleRun){
        CmdSyncRecv_t recv = GetFuncModuleRecv();
        if (recv.mtype != 0) break;
        usleep(10 * 1000);
    }
    return NULL;
}

/**
 * @description: 
 * @return {*}
 */
int StartLaserTest(int step)
{
    int res = 0;
    static pthread_t handle = -1;
    if(step==6){
        // res = pthread_cancel(handle);
        // if (res != 0) {
        //     CrLogI("pthread cancel fail!!!\n");
        // }
        laserTesting=false;
        appFunModuleRun=false;
    }
    // 判断独立功能模块是否忙碌
    if (appFunModuleRun) {
        CrLogW("app fun module run busy!\n");
        return -1;
    }
     if(laserTesting) {
        CrLogI("laser testing\n");
        return -1;
    }
    CrLogI("start laser test");
    
    if(step==1){
        pthread_create(&handle, NULL,laserTestStep1, NULL);
        pthread_detach(handle);
    }else if(step==2){
        pthread_create(&handle, NULL, laserTestStep2, NULL);
        pthread_detach(handle);
    }else if(step==3){
        res = StartLaserTestOpenLaser(true);
    }else if(step==4){
        res = StartLaserTestOpenLaser(false);
    }else if(step==5){
        pthread_create(&handle, NULL, flowDetectTest, NULL);
        pthread_detach(handle);
    }else if(step==7){
        pthread_create(&handle, NULL, laserPressureTest, NULL);
        pthread_detach(handle);
    }

    CrLogI("end laser test");
    return res;
}

void getLaserVersion(void)
{
    int aiServerSocket = -1;
#ifdef CROSS_COMPILE
    // 判断激光雷达是否存在
    if (!GetPrintState().laserExists) {
        CrLogW("laser no exists\n");
        return;
    }
#endif
    // 连接AI服务
    aiServerSocket = GetAiServerSocket();
    if (aiServerSocket <= 0) {
        CrLogW("connect ai server fail\n");
        return;
    }
    char ver[256]={0};
    AiServerGetVersion(aiServerSocket,ver);
    CrLogI("laser version %s\n",ver);
    //发送结果给UI
    char buff[512]={0};
    snprintf(buff,sizeof(buff),"9 %s\0",ver);
    int len = strlen(buff);
    CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_DISPLAY_MANAGER, MANAGER_CMD_START_LASER_TEST_ANS, buff, len);
    MANAGER_MSG_SEND(MSG_ORIGIN_DISPLAY_MANAGER, &send, size);
    if (aiServerSocket) close(aiServerSocket);
}
/**
 * @description: 
 * @return {*}
 */
int StartFirstLayerDetect(bool syncState)
{
    // 判断独立功能模块是否忙碌
    if (appFunModuleRun) {
        CrLogW("app fun module run busy!\n");
        return -1;
    }

    CrLogI("start first layer detect");
    appFunModuleRun = true;
    
    // 开始首层检测
    //int res = LaserFirstLayerDetectRun();
    int res = LaserFirstLayerDetectRun_Quick(syncState);
    appFunModuleRun = false;
    CrLogI("end first layer detect");
    return res;
}

/*********************************************************
 ******************** 通用宏指令 *************************
 *********************************************************/
typedef struct {
    json_object *gcode;
    MACRO_RES resCb;
    struct list_head node;
} RunGcodeMacro_t;

/**
 * @description: 
 * @return {*}
 */
static struct list_head macroList;   // 定义宏指令链表
static pthread_rwlock_t macroRwLock; // 定义读写锁

/**
 * @description: 
 * @return {*}
 * @param {json_object} *gcode
 * @param {MACRO_RES} resCb
 */
int AppGcodeMacroRecv(json_object *gcode, MACRO_RES resCb)
{
    // 判断指针是否为空
    if (!gcode || !resCb) {
        CrLogW("gcode macro invalid data\n");
        return -1;
    }

    // 申请指令内存空间
    RunGcodeMacro_t *recv = (RunGcodeMacro_t *)malloc(sizeof(RunGcodeMacro_t));
    if (recv == NULL) {
        CrLogW("Unable to allocate memory\n");
        return -1;
    }
    bzero(recv, sizeof(RunGcodeMacro_t));
    
    // 缓存至链表
    recv->gcode = gcode;
    recv->resCb = resCb;

    pthread_rwlock_wrlock(&macroRwLock);
    list_add(&recv->node, &macroList);
    pthread_rwlock_unlock(&macroRwLock);

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static RunGcodeMacro_t *GetGcodeMacroRecv(void)
{
    if (macroList.prev == NULL || macroList.next == NULL) return NULL;
    if (list_empty(&macroList)) return NULL;
    return list_entry(macroList.next, RunGcodeMacro_t, node);
}

/**
 * @description: 
 * @return {*}
 * @param {RunGcodeMacro_t} *del
 */
static int DeleteGcodeMacroRecv(RunGcodeMacro_t *del)
{
    if (list_empty(&macroList)) {
        CrLogW("linked list is empty\n");
        return -1;
    }

    pthread_rwlock_wrlock(&macroRwLock);
    list_del_init(&del->node);
    pthread_rwlock_unlock(&macroRwLock);

    free(del);
    del = NULL;
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static void ClearGcodeMacroRecvList(void)
{
    if (list_empty(&macroList)) {
        CrLogW("linked list is empty\n");
        return;
    }

    RunGcodeMacro_t *del = NULL, *snext = NULL;
    list_for_each_entry_safe(del, snext, &macroList, node)
    {
        pthread_rwlock_wrlock(&macroRwLock);
        list_del_init(&del->node);
        pthread_rwlock_unlock(&macroRwLock);

        free(del);
        del = NULL;
    }
}

/**
 * @description: 
 * @return {*}
 * @param {RunGcodeMacro_t} *runMacro
 * @param {int} *gcodeCount
 */
static void RunMacroGcode(RunGcodeMacro_t *runMacro, int *gcodeCount)
{
    // 获取gcode指令
    json_object *gcodeObj = json_object_array_get_idx(runMacro->gcode, *gcodeCount);
    const char *gcode = json_object_get_string(gcodeObj);
    *gcodeCount += 1;

    // 判断是特殊宏指令
    if(strcmp(gcode, "LASER_CALIBRATION")==0) //激光标定
    {
        runMacro->resCb(*gcodeCount);
        LaserCalibrationRun();
        // 应答宏指令结果
        SaveKlipperCmdSyncRecvData((char*)"{}", KLIPPER_FUNCTION_MODULE_NUM);
    }
    else {
        SendFuncModuleCmd((char*)gcode);
        runMacro->resCb(*gcodeCount);
    }
}

/**
 * @description: 
 * @return {*}
 * @param {void} *arg
 */
static void *GcodeMacroThread(void *arg)
{
    while (1)
    {
        // 判断独立功能模块是否忙碌
        if (appFunModuleRun) {
            usleep(10 * 1000);
            continue;
        }

        // 获取宏指令
        RunGcodeMacro_t *runMacro = GetGcodeMacroRecv();
        if (runMacro)
        {
            appFunModuleRun = true;
            int gcodeCount = 0;
            int gcodeSize = json_object_array_length(runMacro->gcode);

            // 清空接收链表，发送第一条指令
            ClearFuncModuleRecvList();
            RunMacroGcode(runMacro, &gcodeCount);

            // 循环任务
            while (appFunModuleRun)
            {
                CmdSyncRecv_t recv = GetFuncModuleRecv();
                if (recv.mtype != 0) {
                    // 循环执行
                    if (gcodeCount < gcodeSize) RunMacroGcode(runMacro, &gcodeCount);
                    else break;
                }
                usleep(10 * 1000);
            }
            
            runMacro->resCb(100);
            DeleteGcodeMacroRecv(runMacro);
            appFunModuleRun = false;
        }
        usleep(10 * 1000);
    }

    return NULL;
}

/**
 * @description: 
 * @return {*}
 */
static int AppGcodeMacroInit(void)
{
    CrLogI("gcode macro init");
    pthread_rwlock_init(&macroRwLock, NULL);
    INIT_LIST_HEAD(&macroList);

    static pthread_t handle = -1;
    if (pthread_create(&handle, NULL, (void *)GcodeMacroThread, NULL)) {
        CrLogW("create pthread error!\n");
        return -1;
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
void AppFuncModuleInit(void)
{
    CrLogI("funtion module init");
    AppGcodeMacroInit();
}

/**
 * @description: 
 * @return {*}
 */
void CancelFuncModule(void)
{
    appFunModuleRun = false;
    ClearGcodeMacroRecvList();
}
