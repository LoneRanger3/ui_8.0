/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-06-06 16:06:15
 * @LastEditTime: 2022-11-03 21:57:00
 */

#ifndef __UDP_TEST_SERVER_H__
#define __UDP_TEST_SERVER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#define UDP_TEST_SERVER_PORT        7766
#define UDP_TEST_SERVER_MAXLINE     1024

int CreateUdpTestServerThread(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif