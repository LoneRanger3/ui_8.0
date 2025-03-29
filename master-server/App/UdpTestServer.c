/*
 * @Description : UDP调试服务
 * @Author      : Yufeng Zhang
 * @Date: 2022-06-06 15:32:19
 * @LastEditTime: 2022-11-03 14:34:34
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "Base/MasterMsgBase.h"
#include "UdpTestServer.h"

/**
 * @description: 
 * @return {*}
 */
static int UdpTestServerAnl(char *buffer)
{
    char *strtokContext = NULL;
    char *answer = strtok_r(buffer, " ", &strtokContext);
    while (answer)
    {
        if (strstr(answer, "pause"))
        {
            GcodeCmd control = GCODE_CMD__INIT;
            GET_MESSAGE_BUFF(buff);
            size_t len = gcode_cmd__pack(&control, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_PAUSE_PRINT_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
        else if (strstr(answer, "resume"))
        {
            GcodeCmd control = GCODE_CMD__INIT;
            GET_MESSAGE_BUFF(buff);
            size_t len = gcode_cmd__pack(&control, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_RESUME_PRINT_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }
        else if (strstr(answer, "stop"))
        {
            GcodeCmd control = GCODE_CMD__INIT;
            GET_MESSAGE_BUFF(buff);
            size_t len = gcode_cmd__pack(&control, buff);
            CREATE_MESSAGE_PACKAGE(send, size, MSG_ORIGIN_APP_MANAGER, MANAGER_CMD_GCODE_STOP_PRINT_REQ, buff, len);
            MANAGER_MSG_SEND(MSG_ORIGIN_CONTROLLER, &send, size);
        }

        // 获取下一条指令
        answer = strtok_r(NULL, " ", &strtokContext);
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int UdpTestServerThread()
{
    struct sockaddr_in servaddr, cliaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // 创建套接字文件描述符
    int sockfd = -1;
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 )
    {
        CrLogE("socket creation failed\n");
        return -1;
    }
      
    // 填写服务器信息
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(UDP_TEST_SERVER_PORT);

    // 将套接字与服务器地址绑定
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 )
    {
        CrLogE("bind failed\n");
        return -1;
    }

    // 开始接收数据
    socklen_t len = (socklen_t)sizeof(cliaddr);
    while (1)
    {
        char buffer[UDP_TEST_SERVER_MAXLINE] = {0};
        recvfrom(sockfd, (char *)buffer, UDP_TEST_SERVER_MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
        CrLogI("udp server recv = %s", buffer);
        UdpTestServerAnl(buffer);
        // 指令应答
        sendto(sockfd, "ok", strlen("ok"), 0, (const struct sockaddr *) &cliaddr, len);
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
int CreateUdpTestServerThread(void)
{
    // 判断调试模式文件是否存在
    if (access(GetDevelopDebugModePtah(), F_OK) != 0) {
        CrLogW("No Create Udp Test Server Thread");
        return 0;
    }
    CrLogI("Create Udp Test Server Thread");
    
    pthread_t udpHandle;
    int res = pthread_create(&udpHandle, NULL, (void*)UdpTestServerThread, NULL);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return -1;
    }
    return 0;  
}