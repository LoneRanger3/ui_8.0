/*
 * @Description : 串口通信
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-14 15:47:26
 * @LastEditTime: 2022-08-25 13:43:10
 */
#include <stdio.h>      //标准输入输出,如printf、scanf以及文件操作
#include <stdlib.h>     //标准库头文件，定义了五种类型、一些宏和通用工具函数
#include <unistd.h>     //定义 read write close lseek 等Unix标准函数
#include <sys/types.h>  //定义数据类型，如 ssiz e_t off_t 等
#include <sys/stat.h>   //文件状态
#include <fcntl.h>      //文件控制定义
#include <termios.h>    //终端I/O
#include <errno.h>      //与全局变量 errno 相关的定义
#include <getopt.h>     //处理命令行参数
#include <string.h>     //字符串操作
#include <time.h>       //时间
#include <sys/select.h> //select函数
#include <sys/socket.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>

#include "Base/MasterMsgBase.h"
#include "SerialPort.h"

#define UEVENT_BUFFER_SIZE        2048              /* buffer for the variables */

#ifdef SERIAL_PORT
#define SERIAL_PORT_DEV_NAME        SERIAL_PORT
#else
#define SERIAL_PORT_DEV_NAME        "/dev/ttyUSB0"  // 串口设备
#endif
#define SERIAL_PORT_SPEED           115200          // 波特率
#define SERIAL_PORT_BITS            8               // 数据位   取值为 7 或者8
#define SERIAL_PORT_STOP            'N'             // 效验类型 取值为 N,E,O,,S
#define SERIAL_PORT_PARITY          1               // 停止位   取值为 1 或者2
#define SERIAL_PORT_RECV_OUT_RIME   10000           // 超时时间 单位ms

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int fdSerial = -1;    // 串口句柄

/**@brief       设置串口参数： 波特率，数据位，停止位和效验位
 * @param[in]   fd          类型  int   打开的串口文件句柄
 * @param[in]   nSpeed      类型  int   波特率
 * @param[in]   nBits       类型  int   数据位   取值 为 7 或者8
 * @param[in]   nParity     类型  int   停止位   取值为 1 或者2
 * @param[in]   nStop       类型  int   效验类型 取值为N,E,O,,S
 * @return      返回设置结果
 * - 0          设置成功
 * - -1         设置失败
 */
static int setOpt(int fd, int nSpeed, int nBits, int nParity, int nStop)
{
    struct termios newtio, oldtio;

    // 保存测试现有串口参数设置，在这里如果串口号等出错，会有相关的出错信息
    if (tcgetattr(fd, &oldtio) != 0)
    {
        CrLogE("Setup Serial fail 1!\n");
        return -1;
    }

    bzero(&newtio, sizeof(newtio));     //新termios参数清零
    newtio.c_cflag |= CLOCAL | CREAD;   //CLOCAL--忽略 modem 控制线,本地连线, 不具数据机控制功能, CREAD--使能接收标志
    newtio.c_cflag &= ~CSIZE;           //清数据位标志
    // 设置数据位数
    switch (nBits)
    {
        case 7:
            newtio.c_cflag |= CS7;
        break;
        case 8:
            newtio.c_cflag |= CS8;
        break;
        default:
            CrLogW("Unsupported data size\n");
            return -1;
    }
    // 设置校验位
    switch (nParity)
    {
        case 'o':
        case 'O':                   //奇校验
            newtio.c_cflag |= PARENB;
            newtio.c_cflag |= PARODD;
            newtio.c_iflag |= (INPCK | ISTRIP);
            break;
        case 'e':
        case 'E':                   //偶校验
            newtio.c_iflag |= (INPCK | ISTRIP);
            newtio.c_cflag |= PARENB;
            newtio.c_cflag &= ~PARODD;
            break;
        case 'n':
        case 'N':                   //无校验
            newtio.c_cflag &= ~PARENB;
            break;
        default:
            CrLogW("Unsupported parity\n");
            return -1;
    }
    // 设置停止位
    switch (nStop)
    {
        case 1:
            newtio.c_cflag &= ~CSTOPB;
        break;
        case 2:
            newtio.c_cflag |= CSTOPB;
        break;
        default:
            CrLogW("Unsupported stop bits\n");
            return -1;
    }
    // 设置波特率 2400/4800/9600/19200/38400/57600/115200/230400
    switch (nSpeed)
    {
        case 2400:
            cfsetispeed(&newtio, B2400);
            cfsetospeed(&newtio, B2400);
            break;
        case 4800:
            cfsetispeed(&newtio, B4800);
            cfsetospeed(&newtio, B4800);
            break;
        case 9600:
            cfsetispeed(&newtio, B9600);
            cfsetospeed(&newtio, B9600);
            break;
        case 19200:
            cfsetispeed(&newtio, B19200);
            cfsetospeed(&newtio, B19200);
            break;
        case 38400:
            cfsetispeed(&newtio, B38400);
            cfsetospeed(&newtio, B38400);
            break;
        case 57600:
            cfsetispeed(&newtio, B57600);
            cfsetospeed(&newtio, B57600);
            break;
        case 115200:
            cfsetispeed(&newtio, B115200);
            cfsetospeed(&newtio, B115200);
            break;
        case 230400:
            cfsetispeed(&newtio, B230400);
            cfsetospeed(&newtio, B230400);
            break;
        default:
            CrLogW("\tSorry, Unsupported baud rate, set default 9600!\n");
            cfsetispeed(&newtio, B9600);
            cfsetospeed(&newtio, B9600);
            break;
    }
    // 设置read读取最小字节数和超时时间
    newtio.c_cc[VTIME] = 1; // 读取一个字符等待1*(1/10)s
    newtio.c_cc[VMIN] = 1;  // 读取字符的最少个数为1

    tcflush(fd,TCIFLUSH);   //清空缓冲区
    if (tcsetattr(fd, TCSANOW, &newtio) != 0)    //激活新设置
    {
        CrLogE("Setup Serial fail 2!\n");
        return -1;
    }

    CrLogI("Serial set done!");
    return 0;
}

/**@brief 串口读取函数
 * @param[in]   *rcv_buf    接收缓存指针
 * @param[in]   *data_len   读取数据长度
 * @return      返回设置结果
 * - >0         设置成功
 * - 其他       读取超时或错误
 */
int UART_Recv(char *rcv_buf, int *data_len)
{
    if(fdSerial < 0)
    {
        CrLogE("The device cannot be used, name = %s\n", SERIAL_PORT_DEV_NAME);
        sleep(2);
        return -1;
    }

    int len, fs_sel;
    fd_set fs_read;
    struct timeval time;

    time.tv_sec = SERIAL_PORT_RECV_OUT_RIME / 1000;           //set the rcv wait time
    time.tv_usec = SERIAL_PORT_RECV_OUT_RIME % 1000 * 1000;   //100000us = 0.1s

    FD_ZERO(&fs_read);          //每次循环都要清空集合，否则不能检测描述符变化
    FD_SET(fdSerial, &fs_read); //添加描述符

    // 超时等待读变化，>0：就绪描述字的正数目， -1：出错， 0 ：超时
    fs_sel = select(fdSerial + 1, &fs_read, NULL, NULL, &time);
    if(fs_sel)
    {
        len = read(fdSerial, rcv_buf, SERIAL_PORT_RECV_MAX_LEN);
        *data_len = len;
        return len;
    }
    else
    {
        return -1;
    }
}

/**@brief 串口发送函数
 * @param[in]   *send_buf   发送数据指针
 * @param[in]   data_len    发送数据长度
 * @return      返回结果
 * - data_len   成功
 * - -1         失败
 */
int UART_Send(char *send_buf, int data_len)
{
    if(fdSerial < 0)
    {
        CrLogE("The device cannot be used, name = %s\n", SERIAL_PORT_DEV_NAME);
        return -1;
    }

    ssize_t ret = 0;

    ret = write(fdSerial, send_buf, data_len);
    if (ret == data_len)
    {
        return ret;
    }
    else
    {
        CrLogW("write device error\n");
        tcflush(fdSerial, TCOFLUSH);
        return -1;
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int GetSerialPortFd(void) { return fdSerial; }

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int SerialPortInit()
{
    // 打开串口设备
    fdSerial = open(SERIAL_PORT_DEV_NAME, O_RDWR | O_NOCTTY | O_NDELAY);
    if(fdSerial < 0)
    {
        CrLogE("device open fail, name = %s\n", SERIAL_PORT_DEV_NAME);
        return -1;
    }
    // 设置串口阻塞， 0：阻塞， FNDELAY：非阻塞
    if (fcntl(fdSerial, F_SETFL, 0) < 0)    //阻塞，即使前面在open串口设备时设置的是非阻塞的
    {
        CrLogE("fcntl failed!\n");
    }
    else
    {
        CrLogI("fcntl=%d", fcntl(fdSerial, F_SETFL, 0));
    }
    if (isatty(fdSerial) == 0)
    {
        CrLogE("standard input is not a terminal device\n");
        close(fdSerial);
        fdSerial = -1;
        return -1;
    }
    else
    {
        CrLogI("is a tty success!, name = %s\n", SERIAL_PORT_DEV_NAME);
    }
    CrLogI("fd-open=%d", fdSerial);

    // 设置串口参数, 设置8位数据位、1位停止位、无校验
    if (setOpt(fdSerial, SERIAL_PORT_SPEED, SERIAL_PORT_BITS, SERIAL_PORT_STOP, SERIAL_PORT_PARITY)== -1)
    {
        fprintf(stderr, "Set opt Error\n");
        close(fdSerial);
        fdSerial = -1;
        exit(1);
    }

    tcflush(fdSerial, TCIOFLUSH);   //清掉串口缓存
    fcntl(fdSerial, F_SETFL, 0);    //串口阻塞

    CrLogI("Serial Port Init success!");
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static int SerialPortReconnect()
{
    if (fdSerial != -1)
    {
        close(fdSerial);
        fdSerial = -1;
    }
    SerialPortInit();

    return 0;
}

/**
 * @description: Kernel Netlink
 * @param  {*}
 * @return {*}
 */
static int CUSBListenerInitSock(void)
{
    const int buffersize = UEVENT_BUFFER_SIZE;
    int ret;
    int on = 1;
 
    struct sockaddr_nl snl;
    bzero(&snl, sizeof(struct sockaddr_nl));
    snl.nl_family = AF_NETLINK;
    snl.nl_pid = getpid();
    snl.nl_groups = RTMGRP_LINK | RTMGRP_IPV4_IFADDR | RTMGRP_IPV6_IFADDR;
 
    int s = socket(PF_NETLINK, SOCK_DGRAM, NETLINK_KOBJECT_UEVENT);
    if (s == -1)
    {
		return -1;
    }
    if (setsockopt(s, SOL_SOCKET, SO_RCVBUF, &buffersize, sizeof(buffersize)) < 0)
    {
		CrLogE("setsockopet error\n");
		return -1;
    }
    if((setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)))<0)
    {
		CrLogE("setsockopet error\n");
		return -1;
    }
 
    ret = bind(s, (struct sockaddr *)&snl, sizeof(struct sockaddr_nl));
    if (ret < 0)
    {
		return -2;
    }
    return s;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static void CUSBListenerOnUSB(const char *msg)
{
    char devName[100] = "/tty";
    strcat(devName, strrchr(SERIAL_PORT_DEV_NAME, '/'));

    if (!memcmp(msg, "add@", 4))
    {
		// 识别串口
		if (!memcmp(&msg[strlen(msg) - strlen(devName)], devName, strlen(devName)))
        {
			CrLogI("Found U Disk %s\n", devName);
            usleep(1000 * 100);
            SerialPortReconnect();
		}
    }
    else if (!memcmp(msg, "remove@", 7))
    {
        // 释放串口资源
		if (!memcmp(&msg[strlen(msg) - strlen(devName)], devName, strlen(devName)))
        {
			CrLogI("remove U Disk %s\n", devName);
            close(fdSerial);
            fdSerial = -1;
		}
    }
}
 
/**
 * @description: listener for USB Event message
 * @param  {*}
 * @return {*}
 */
int CUSBListenerRun(void)
{
    int sock = CUSBListenerInitSock();
    while(sock > 0)
    {
        char buf[UEVENT_BUFFER_SIZE * 2] = {0};
		int len = recv(sock, &buf, sizeof(buf), 0);
		if(len > 0)
		{
			CUSBListenerOnUSB(buf);
		}
        usleep(1000 * 10);
    }
    CrLogE("Create Netlink failed\n");

    return 0;
}