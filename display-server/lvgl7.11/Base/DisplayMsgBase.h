/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-06 20:56:59
 * @LastEditTime: 2022-06-17 09:31:45
 */

#ifndef __MSG_BASE_H__
#define __MSG_BASE_H__

#include <stdint.h>

#include "global/Global.h"
#include "Base/Proto/DisplayServer.pb-c.h"

#ifdef  __cplusplus  
extern "C" {  
#endif

/**
 * @description: 线程间消息命令字
 */
typedef enum {
    SYSTEM_MANAGER_CMD_MIX = 4096,
    MANAGER_CMD_MESSAGE_TEST = 5000,
}MsgCmd;


#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif