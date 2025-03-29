/**
 * @ Author: Rui xiong
 * @ Create Time: 2022-11-11 14:17:49
 * @ Modified by: Rui Xiong
 * @ Modified time: 2022-11-11 16:24:12
 * @ Description:
 */

#ifndef __MSG_BASE_H__
#define __MSG_BASE_H__

#include <stdint.h>

#include "global/Global.h"
#include "Base/Proto/WebServer.pb-c.h"

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