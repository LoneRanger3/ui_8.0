/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-07-26 16:09:15
 * @LastEditTime: 2022-12-30 17:47:25
 */
#ifndef __SOCKET_KLIPPER_H__
#define __SOCKET_KLIPPER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#define KLIPPER_SOCKET_ADDR         "172.23.213.71"
#define KLIPPER_SOCKET_PORT         8898
#define KLIPPER_RECV_OUT_RIME       10000 // 超时时间 单位ms

bool GetKlipperSocketFlag(void);
int KlipperSocketRead(char *buff, size_t len);
int KlipperSocketWrite(char *buff, size_t len);
int KlipperSocketInit(void);
int KlipperSocketDeinit(void);

int CreateKlipperRemoteDebug(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
