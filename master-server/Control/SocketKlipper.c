/*
 * @Description : klipper通信
 * @Author      : Yufeng Zhang
 * @Date: 2022-07-26 16:09:02
 * @LastEditTime: 2023-04-03 15:35:53
 */
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/un.h>
#include <errno.h>

#include "Base/MasterMsgBase.h"
#include "SocketKlipper.h"

/**
 * @description: 定义静态变量
 * @return {*}
 */
static int klipperSocket = -1; // klipper本地socket
static bool klipperSocketFlag = false; // klipper本地socket标志位

/**
 * @description: 静态函数声明
 * @return {*}
 * @param {char} *msg
 * @param {int} len
 */
static int KlipperRemoteDebugSend(char *msg, int len);

/**
 * @description: 
 * @return {*}
 */
bool GetKlipperSocketFlag(void) { return klipperSocketFlag; }

/**
 * @description: 
 * @return {*}
 * @param {int} fd
 */
static int MyCloseSocket(int fd)
{
    int rc = shutdown(fd, SHUT_RDWR);
    if (rc < 0)
    {
        CrLogE("rc = %d; shutdown error, %s\n", rc, strerror(errno));
        return -1;
    }

    rc = close(fd);
    if (rc < 0)
    {
        CrLogE("rc = %d; close error, %s\n", rc, strerror(errno));
        return -1;
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int CreateKlipperSocket(void)
{
    // 断开原有连接
    if (klipperSocket != -1) {
        MyCloseSocket(klipperSocket);
        klipperSocket = -1;
        klipperSocketFlag = false;
    }

#ifdef CROSS_COMPILE
    // 避免因文件已存在导致的bind()失败
    unlink(GetDefaultKlipperClientSock());
    
    // 创建klipper通信socket
    int createSocket = socket(AF_LOCAL, SOCK_STREAM, 0);
    if(createSocket == -1) {
		CrLogE("create socket error\n");
		return -1;
	}
    CrLogI("create klipper socket = %d", createSocket);

    // 绑定本地套接字文件
    struct sockaddr_un clientAddr;
    clientAddr.sun_family = AF_LOCAL;
    strcpy(clientAddr.sun_path, GetDefaultKlipperClientSock());
    int ret = bind(createSocket, (struct sockaddr *)&clientAddr, sizeof(clientAddr));
    if(ret == -1) {
		CrLogE("bind socket error, %s\n", strerror(errno));
		MyCloseSocket(createSocket);
        createSocket = -1;
		return -1;
	}

    // 连接klipper
    struct sockaddr_un serverAddr;
    serverAddr.sun_family = AF_LOCAL;
    strcpy(serverAddr.sun_path, GetDefaultKlipperServerSock());
    ret = connect(createSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if(ret == -1) {
        CrLogE("connect error, %s\n", strerror(errno));
        MyCloseSocket(createSocket);
        createSocket = -1;
		return -1;
    }
#else
    // 创建klipper通信socket
    int createSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(createSocket == -1) {
		CrLogE("create socket error\n");
		return -1;
	}
    CrLogI("create klipper socket = %d", createSocket);

	// 连接klipper
	struct sockaddr_in klipperAddr;
	klipperAddr.sin_family = AF_INET;
	klipperAddr.sin_addr.s_addr = inet_addr(KLIPPER_SOCKET_ADDR);;
    klipperAddr.sin_port = htons(KLIPPER_SOCKET_PORT);
	int ret = connect(createSocket, (struct sockaddr *)&klipperAddr, sizeof(klipperAddr));
    if (ret == -1) {
		CrLogE("connect error, %s\n", strerror(errno));
        MyCloseSocket(createSocket);
        createSocket = -1;
		return -1;
	}
#endif

    klipperSocket = createSocket;
    klipperSocketFlag = true;
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *buff
 * @param {size_t} len
 */
int KlipperSocketRead(char *buff, size_t len)
{
    if(!klipperSocketFlag) {
        CrLogE("klipper socket fail\n");
        sleep(2);
        return -1;
    }

    // 设置系统状态监听
    fd_set fs_read;
    FD_ZERO(&fs_read); //每次循环都要清空集合，否则不能检测描述符变化
    FD_SET(klipperSocket, &fs_read); //添加描述符

    struct timeval time;
    time.tv_sec = KLIPPER_RECV_OUT_RIME / 1000; //set the rcv wait time
    time.tv_usec = KLIPPER_RECV_OUT_RIME % 1000 * 1000; //100000us = 0.1s

    // 超时等待读变化，>0：就绪描述字的正数目， -1：出错， 0 ：超时
    int fs_sel = select(klipperSocket + 1, &fs_read, NULL, NULL, &time);
    if(fs_sel)
    {
        int ret = read(klipperSocket, buff, len);
        if (ret == -1)
        {
            CrLogE("receive data error, %s\n", strerror(errno));
            return -1;
        }
        KlipperRemoteDebugSend(buff, ret);
        return ret;
    }
    
    else return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *buff
 * @param {size_t} len
 */
int KlipperSocketWrite(char *buff, size_t len)
{
    if(!klipperSocketFlag) {
        CrLogE("klipper socket fail\n");
        return -1;
    }
    
	int ret = write(klipperSocket, buff, len);
    if (ret == 0)
    {
        CrLogW("send buffer full\n");
        return -1;
    }
    else if (ret == -1)
    {
        CrLogE("send data error, %s\n", strerror(errno));
        return -1;
    }
	else if (ret != len)
    {
		CrLogW("send data error = %s", buff);
		return -1;
	}

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
int KlipperSocketInit(void)
{
    // 创建 klipper socket
    int res = CreateKlipperSocket();
    if (res < 0)
    {
        CrLogE("create klipper socket fail\n");
        return -1;
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
int KlipperSocketDeinit(void)
{
    CrLogW("Actively disconnect the socket connection and wait for reconnection!\n\n\n");
    MyCloseSocket(klipperSocket);
    klipperSocket = -1;
    klipperSocketFlag = false;
    return 0;
}



/**
 * @description: 开发人员远程调试应用服务
 * @return {*}
 */

#define BACKLOG_MAX     5           // 完成三次握手但没有accept的队列的长度
#define CONCURRENT_MAX  8           // 应用层同时可以处理的连接
#define BUFFER_SIZE     (1024 * 4)  // 数据缓冲数组最大值
int clientFds[CONCURRENT_MAX];      // 保存客户端连接句柄

/**
 * @description: 
 * @return {*}
 */
static int KlipperRemoteDebugSend(char *msg, int len)
{
    for(int i = 0; i < CONCURRENT_MAX; i++) {
        if(clientFds[i] != 0) {
            send(clientFds[i], msg, len, 0);
        }
    }
    return 0;
}

/**
 * @description: 
 * @return {*}
 */
static int KlipperRemoteDebugThread()
{
    // 本地地址
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(KLIPPER_SOCKET_PORT);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bzero(&(serverAddr.sin_zero), 8);

    // 创建socket
    int serverSockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSockFd == -1) {
        CrLogE("remote debug socket error\n");
        return 1;
    }

    // 绑定socket
    int bindResult = bind(serverSockFd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (bindResult == -1) {
        CrLogE("remote debug bind error\n");
        return 1;
    }

    // listen
    if (listen(serverSockFd, BACKLOG_MAX) == -1) {
        CrLogE("remote debug listen error\n");
        return 1;
    }

    // 定义
    char inputMsg[BUFFER_SIZE];
    char recvMsg[BUFFER_SIZE];
    fd_set serverFdSet;
    FD_ZERO(&serverFdSet);
    int maxFd = -1;

    while(1)
    {  
        // 服务器端socket
        FD_SET(serverSockFd, &serverFdSet);
        if (maxFd < serverSockFd) {
            maxFd = serverSockFd;
        }
        
        //客户端连接
        for (int i = 0; i < CONCURRENT_MAX; i++)
        {
            if (clientFds[i] != 0)
            {
                FD_SET(clientFds[i], &serverFdSet);
                if (maxFd < clientFds[i]) {
                    maxFd = clientFds[i];
                }
            }
        }
        
        // 等待数据接收
        int ret = select(maxFd + 1, &serverFdSet, NULL, NULL, NULL);
        if (ret < 0) {
            CrLogE("remote debug select fail\n");
            continue;
        }
        else {
            // ret 为未状态发生变化的文件描述符的个数
            if (FD_ISSET(serverSockFd, &serverFdSet))
            {
                //有新的连接请求
                struct sockaddr_in clientAddress;
                socklen_t addressLen;
                int clientSockFd = accept(serverSockFd, (struct sockaddr *)&clientAddress, &addressLen);
                CrLogI("new connection clientSockFd = %d", clientSockFd);

                if (clientSockFd > 0)
                {
                    int index = -1;
                    for (int i = 0; i < CONCURRENT_MAX; i++)
                    {
                        if(clientFds[i] == 0)
                        {
                            index = i;
                            clientFds[i] = clientSockFd;
                            break;
                        }
                    }
                    if (index >= 0) {
                        CrLogI("new client (%d) join success %s:%d", index, inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
                    }
                    else {
                        bzero(inputMsg, BUFFER_SIZE);
                        strcpy(inputMsg, "The number of clients joined by the server has reached the maximum value and cannot join!\n");
                        send(clientSockFd, inputMsg, BUFFER_SIZE, 0);
                        CrLogI("client connec max, new client join fail %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
                    }
                }
            }

            for (int i = 0; i < CONCURRENT_MAX; i++)
            {
                if (clientFds[i] !=0)
                {
                    if (FD_ISSET(clientFds[i], &serverFdSet))
                    {
                        bzero(recvMsg, BUFFER_SIZE);
                        long byteNum = recv(clientFds[i], recvMsg, BUFFER_SIZE, 0);
                        if (byteNum > 0)
                        {
                            if (byteNum > BUFFER_SIZE) {
                                byteNum = BUFFER_SIZE;
                            }
                            recvMsg[byteNum] = '\0';
                            KlipperSocketWrite(recvMsg, byteNum);
                        }
                        else if (byteNum < 0) {
                            CrLogW("client (%d) recv fail\n", i);
                        }
                        else {
                            FD_CLR(clientFds[i], &serverFdSet);
                            clientFds[i] = 0;
                            CrLogI("client (%d) exit\n", i);
                        }
                    }
                }
            }
        }
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 */
int CreateKlipperRemoteDebug(void)
{
    #ifdef CROSS_COMPILE       
    // 判断调试模式文件是否存在
    if (access(GetDevelopDebugModePtah(), F_OK) != 0) {
        CrLogW("No Create Klipper Remote Debug Thread");
        return 0;
    }
    CrLogI("Create Klipper Remote Debug Thread");

    pthread_t udpHandle;
    int res = pthread_create(&udpHandle, NULL, (void*)KlipperRemoteDebugThread, NULL);
    if (res)
    {
        CrLogE("create pthread error!\n");
        return -1;
    }
    #endif
    return 0;
}
