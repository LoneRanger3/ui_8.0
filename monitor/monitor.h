/*
 * @Description : ServerMessage.h
 * @Author      : Yufeng Zhang
 * @Date: 2022-07-04 14:09:07
 * @LastEditTime: 2023-09-07 16:34:02
 */
#ifndef __MONITOR_H__
#define __MONITOR_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#define MASTER_SERVER       "/usr/bin/master-server"
#define WIFI_SERVER         "/usr/bin/wifi-server"
#define AUDIO_SERVER        "/usr/bin/audio-server"
#define APP_SERVER          "/usr/bin/app-server"
#define DISPLAY_SERVER      "/usr/bin/display-server"
#define UPGRADE_SERVER      "/usr/bin/upgrade-server"
#define WEB_SERVER          "/usr/bin/web-server"
#define WEBRTC              "/usr/bin/webrtc"
#define WEBRTC_RESTART      "/etc/init.d/S97webrtc restart"
#define LOG_MAIN            "/usr/bin/log_main"
#define LOG_MAIN_RESTART    "/usr/bin/report.sh restart"
#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif