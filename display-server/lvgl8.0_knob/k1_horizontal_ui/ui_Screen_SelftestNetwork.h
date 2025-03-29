/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-11-28 10:40:51
 * @LastEditTime: 2023-07-25 22:59:32
 */
#ifndef _SELFTESTNETWORK_H
#define _SELFTESTNETWORK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_SelftestNetwork;
extern lv_obj_t * ui_SelftestNetworktitle;
void ui_event_SelftestNetworkButton1(lv_event_t * e);
extern lv_obj_t * ui_SelftestNetworkButton1;
extern lv_obj_t * ui_SelftestNetworkBtnlabel1;
void ui_event_SelftestNetworkButton2(lv_event_t * e);
extern lv_obj_t * ui_SelftestNetworkButton2;
extern lv_obj_t * ui_SelftestNetworkBtnlabel2;
extern lv_obj_t * ui_SelftestNetworkLabel1;
extern lv_obj_t * ui_SelftestNetworkLabel2;
void ui_event_SelftestNetworkButton3(lv_event_t * e);
extern wifi_list_t *selftestwifilist_array[20];


void selftest_show_wifi_list(char *data,int len);

void selftest_network_change_language_text(void);
void refresh_selftestnetworkstate(bool connect_state);
void refresh_selftestwifilist_page(char * wifi_ip,char * wifi_mac);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif