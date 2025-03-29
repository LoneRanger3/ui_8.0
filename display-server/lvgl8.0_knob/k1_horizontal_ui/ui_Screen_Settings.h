/*
 * @Description: 
 * @Author: sunhui
 * @Date: 2023-09-04 02:58:51
 * @LastEditTime: 2023-10-29 23:23:08
 */
#ifndef _SETTINGS_H
#define _SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_ScreenSettings;

extern lv_style_t StyleDialogBtn; //对话按钮框样式
extern lv_style_t StyleDialogFocusBtn;
extern lv_style_t StyleDialogBtnDefault;

extern lv_obj_t * ui_NetworkSetting_Keyboard;
extern lv_obj_t * ui_NetworkSettingWifilist;
extern lv_obj_t * ui_SettingstitleNetwork;
extern lv_obj_t * ui_NetworkSettingPanel; 
extern lv_obj_t * ui_NetworkName_TextArea;
extern lv_obj_t * ui_NetworkPassw_TextArea;
extern lv_obj_t * ui_TimeZoneSetLabel;


extern char Manualtest[12];
extern char Manualtestlength;
extern char Manualtest_curpage;
extern bool systemsettingflag;
extern bool keyboard_spec_flag;

typedef struct settings_list
{
    lv_obj_t *parent;
    lv_obj_t *part_panel;
    lv_obj_t *label_item_name; //设置列表项名
    lv_obj_t *label_content_name; //设置列表项名
    lv_obj_t *img_arrow_png;
    uint8_t index;
}settings_list_t;



typedef struct wifi_list
{
    lv_obj_t *parent;
    lv_obj_t *wifi_name;
    lv_obj_t *wifi_state;
    lv_obj_t *wifi_logo;
    lv_obj_t *wifi_info;
    int wifi_type;
}wifi_list_t;

enum {
    KEYBOARD_MODE_TEXT_LOWER = 0,
    KEYBOARD_MODE_TEXT_UPPER,
    KEYBOARD_MODE_NUM,
    KEYBOARD_MODE_SPECIAL,
};

enum {
    SCREEN_SETTINGS_BUTTON = 0,
    SCREEN_BRIGHTNESS_ITEM,
    SCREEN_OFF_ITEM, 
    LANGUAGE_SELECTION_ITEM,
    DEVICE_SELF_TEST_ITEM,
    TIME_ZONE_SETTING_ITEM,
    CAMERA_SETTING_ITEM,
    NETWORK_SETTING_ITEM,
    BIND_DEVICE_ITEM,
    UPDATE_REMINDER_ITEM,
    VERSION_DETECT_ITEM,
    RESET_MACHINE_ITEM,
    ABOUT_DEVICE_ITEM,
    MAX_ITEM
};

void LoadSettingsScreenAndObjs(bool IsEntered, uint8_t index);
void ui_event_VideoSettingPanel5(lv_event_t * e);
void ui_event_VideoSettingPanel6(lv_event_t * e);
void ui_event_VideoSettingPanel7(lv_event_t * e);

void ui_event_SystemsettingDropdown3(lv_event_t * e);
void LoadSettingsScreen(void);
void show_wifi_list(char *data,int len);
void refresh_wifilist_page(char * wifi_ip,char * wifi_mac);
void set_versioninfo_settingpage(char * version_info);
#define WIFI_MAX_NUMBER 100
extern wifi_list_t list_array[WIFI_MAX_NUMBER];
void wifi_msgbox(unsigned char flag,lv_obj_t * obj, wifi_list_t * wifi);

void settings_set_cur_language(uint8_t cur_language);
void settings_change_language_text(void);
void refresh_light_value(int lightvalue);
void refresh_screenoff_setting(int option);
void refresh_versioninfo(bool show);
void refresh_networkstate(bool connect_state);
void refresh_checkupdateflag_state(int state);
void settings_page_refresh_laserstate(int laser_state);
void settings_page_refresh_camerastate(int camera_state);
void settings_page_set_wifi_status(int intensity);
void refresh_UserBoundDeviceInfo(bool result, CloudUserInfo_t user);
void ChangeServerOption(int ServerOption);
void refresh_devicebingding_page(char *src);
void SettingsPageCloseSubPage(void);
void NetworkSettingPageChangeObjs(void);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif