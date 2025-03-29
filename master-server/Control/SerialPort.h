/*
 * @Description : SerialPort.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-14 15:47:47
 * @LastEditTime: 2022-04-18 11:54:36
 */
#ifndef __SERIAL_PORT_H__
#define __SERIAL_PORT_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#define SERIAL_PORT_RECV_MAX_LEN            1024 // 默认接收最大长度

int SerialPortInit();
int GetSerialPortFd(void);
int CUSBListenerRun();
int UART_Recv(char *rcv_buf, int *data_len);
int UART_Send(char *send_buf, int data_len);


#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif