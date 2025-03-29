/*
 * @Description : Appointment.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:21:15
 * @LastEditTime: 2022-01-18 21:18:42
 */
#ifndef __APPOINTMENT_H__
#define __APPOINTMENT_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

MsgHandle_t *AppointmentInit(void *arg);
int AppointmentExceptionHandleSemPost(void);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif