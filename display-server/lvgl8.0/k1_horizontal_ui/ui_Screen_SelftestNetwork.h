/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-11-28 10:40:51
 * @LastEditTime: 2022-12-30 16:00:29
 */
#ifndef _SELFTESTNETWORK_H
#define _SELFTESTNETWORK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_SelftestNetwork;
extern lv_obj_t * ui_SelftestNetworkpanel1;
extern lv_obj_t * ui_SelftestNetworktitle;
void ui_event_SelftestNetworkButton1(lv_event_t * e);
extern lv_obj_t * ui_SelftestNetworkButton1;
extern lv_obj_t * ui_SelftestNetworkBtnlabel1;
void ui_event_SelftestNetworkButton2(lv_event_t * e);
extern lv_obj_t * ui_SelftestNetworkButton2;
extern lv_obj_t * ui_SelftestNetworkBtnlabel2;
extern lv_obj_t * ui_SelftestNetworkpanel2;
extern lv_obj_t * ui_SelftestNetwork_Image1;
extern lv_obj_t * ui_SelftestNetworkLabel1;
extern lv_obj_t * ui_SelftestNetworkLabel2;
extern lv_obj_t * ui_SelftestNetwork_Image2;
extern lv_obj_t * ui_SelftestNetworkpanel3;
void ui_event_SelftestNetworkButton3(lv_event_t * e);
extern lv_obj_t * ui_SelftestNetworkButton3;
extern lv_obj_t * ui_SelftestNetworkBtnlabel3;
extern wifi_list_t selftestwifilist_array[WIFI_MAX_NUMBER];


void selftest_show_wifi_list(char *data,int len);

void selftest_network_change_language_text(void);
void refresh_selftestnetworkstate(bool connect_state);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif