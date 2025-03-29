#ifndef _SETTINGS_H
#define _SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

extern lv_obj_t * ui_Systemsetting;
extern lv_obj_t * ui_SystemsettingPanel1;
extern lv_obj_t * ui_SystemsettingImage1;
extern lv_obj_t * ui_SystemsettingImage2;
extern lv_obj_t * ui_SystemsettingImage3;
void ui_event_SystemsettingImage4(lv_event_t * e);
extern lv_obj_t * ui_SystemsettingImage4;
extern lv_obj_t * ui_SystemsettingImage5;
extern lv_obj_t * ui_SystemsettingPanel2;
extern lv_obj_t * ui_SystemsettingPanel3;
extern lv_obj_t * ui_SystemsettingLabel1;
extern lv_obj_t * ui_SystemsettingImage6;
extern lv_obj_t * ui_SystemsettingImage7;
extern lv_obj_t * ui_SystemsettingLabel2;
extern lv_obj_t * ui_SystemsettingDropdown1;
extern lv_obj_t * ui_SystemsettingLabel3;
extern lv_obj_t * ui_SystemsettingSwitch1;
extern lv_obj_t * ui_SystemsettingLabel4;
extern lv_obj_t * ui_SystemsettingSlider1;
void ui_event_SystemsettingDropdown2(lv_event_t * e);
extern lv_obj_t * ui_SystemsettingDropdown2;
void ui_event_SystemsettingPanel4(lv_event_t * e);
extern lv_obj_t * ui_SystemsettingPanel4;
extern lv_obj_t * ui_SystemsettingImage8;
extern lv_obj_t * ui_SystemsettingLabel5;
void ui_event_SystemsettingPanel5(lv_event_t * e);
extern lv_obj_t * ui_SystemsettingPanel5;
extern lv_obj_t * ui_SystemsettingImage9;
extern lv_obj_t * ui_SystemsettingLabel6;
extern lv_obj_t * ui_SystemsettingPanel6;
extern lv_obj_t * ui_SystemsettingLabel7;
extern lv_obj_t * ui_SystemsettingDropdown3;
void ui_event_SystemsettingPanel7(lv_event_t * e);
extern lv_obj_t * ui_SystemsettingPanel7;
extern lv_obj_t * ui_SystemsettingImage10;
extern lv_obj_t * ui_SystemsettingLabel8;
extern lv_obj_t * ui_SystemsettingPanel8;
extern lv_obj_t * ui_SystemsettingImage11;
void ui_event_SystemsettingPanel8(lv_event_t * e);
extern lv_obj_t * ui_SystemsettingLabel9;
void ui_event_SystemsettingPanel9(lv_event_t * e);
extern lv_obj_t * ui_SystemsettingPanel9;
extern lv_obj_t * ui_SystemsettingImage12;
extern lv_obj_t * ui_SystemsettingLabel10;
extern lv_obj_t * ui_SystemsettingLabel11;
void ui_event_SystemsettingPanel10(lv_event_t * e);
extern lv_obj_t * ui_SystemsettingPanel10;
extern lv_obj_t * ui_SystemsettingImage13;
extern lv_obj_t * ui_SystemsettingLabel12;
void ui_event_SystemsettingPanel11(lv_event_t * e);
extern lv_obj_t * ui_SystemsettingPanel11;
extern lv_obj_t * ui_SystemsettingImage14;
extern lv_obj_t * ui_SystemsettingLabel13;
extern lv_obj_t * ui_NetworkSetting;
extern lv_obj_t * ui_NetworkSettingPanel1;
extern lv_obj_t * ui_NetworkSettingImage1;
extern lv_obj_t * ui_NetworkSettingImage2;
extern lv_obj_t * ui_NetworkSettingImage3;
extern lv_obj_t * ui_NetworkSettingImage4;
extern lv_obj_t * ui_NetworkSettingImage5;
extern lv_obj_t * ui_NetworkSettingPanel2;
extern lv_obj_t * ui_NetworkSettingPanel3;
extern lv_obj_t * ui_NetworkSettingPanel4;
extern lv_obj_t * ui_NetworkSettingImage6;
extern lv_obj_t * ui_NetworkSettingLabel1;
extern lv_obj_t * ui_NetworkSettingLabel2;
extern lv_obj_t * ui_NetworkSettingImage7;
extern lv_obj_t * ui_NetworkSettingPanel6;
extern lv_obj_t * ui_NetworkSettingLabel3;
extern lv_obj_t * ui_NetworkSetting_TextArea1;
extern lv_obj_t * ui_NetworkSetting_Keyboard1;
extern lv_obj_t * ui_NetworkSettingImage8;
extern lv_obj_t * ui_NetworkSettingLabel4;
extern lv_obj_t * ui_VideoSetting;
extern lv_obj_t * ui_VideoSettingPanel1;
extern lv_obj_t * ui_VideoSettingImage1;
extern lv_obj_t * ui_VideoSettingImage2;
extern lv_obj_t * ui_VideoSettingImage3;
extern lv_obj_t * ui_VideoSettingImage4;
extern lv_obj_t * ui_VideoSettingImage5;
extern lv_obj_t * ui_VideoSettingPanel2;
extern lv_obj_t * ui_VideoSettingPanel3;
extern lv_obj_t * ui_VideoSettingPanel4;
extern lv_obj_t * ui_VideoSettingImage6;
extern lv_obj_t * ui_VideoSettingLabel1;
extern lv_obj_t * ui_VideoSettingPanel5;
extern lv_obj_t * ui_VideoSettingImage7;
extern lv_obj_t * ui_VideoSettingLabel2;
extern lv_obj_t * ui_VideoSettingImage8;
extern lv_obj_t * ui_VideoSettingPanel6;
extern lv_obj_t * ui_VideoSettingImage9;
extern lv_obj_t * ui_VideoSettingLabel3;
extern lv_obj_t * ui_VideoSettingImage10;
extern lv_obj_t * ui_VideoSettingPanel7;
extern lv_obj_t * ui_VideoSettingImage11;
extern lv_obj_t * ui_VideoSettingLabel4;
extern lv_obj_t * ui_VideoSettingImage12;
extern lv_obj_t * ui_Settings;
extern lv_obj_t * ui_SettingsTabview;
extern lv_obj_t * ui_Settingstitle1;
extern lv_obj_t * ui_Settingstitle2;
extern lv_obj_t * ui_Settingstitle3;
extern lv_obj_t * ui_Settingstitle4;
extern char Manualtest[12];
extern char Manualtestlength;
extern char Manualtest_curpage;
extern bool systemsettingflag;

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
    KEYBOARD_MODE_TEXT_UPPER= 0,
    KEYBOARD_MODE_TEXT_LOWER,
    KEYBOARD_MODE_SPECIAL,
};

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

void settings_set_cur_language(int cur_language);
void settings_change_language_text(void);
void refresh_light_value(int lightvalue);
void refresh_screenoff_setting(int option);
void refresh_versioninfo(bool show);
void refresh_networkstate(bool connect_state);
void refresh_checkupdateflag_state(int state);
void wifi_msgbox(unsigned char flag,lv_obj_t * obj, wifi_list_t * wifi);
void HasRootFile();
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif