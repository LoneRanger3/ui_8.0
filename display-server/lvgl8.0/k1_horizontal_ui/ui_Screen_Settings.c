#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "./custom/CrlogDef.h"
#include "ui_screen_CameraList.h"
#include "custom/lvgl_cmd.h"
#include "ui_screen_camera_settings.h"
#include "ui_Screen_CustomerService.h"
#include "mult_language.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Systemsetting;
lv_obj_t * ui_SettingTitle;
lv_obj_t * ui_SystemsettingTitle;
lv_obj_t * ui_SystemsettingImg;
lv_obj_t * ui_SystemsettingBtn;
lv_obj_t * ui_NetworksettingTitle;
lv_obj_t * ui_NetworksettingImg;
lv_obj_t * ui_NetworksettingBtn;
lv_obj_t * ui_CamerasettingTitle;
lv_obj_t * ui_CamerasettingImg;
lv_obj_t * ui_CamerasettingBtn;
lv_obj_t * ui_SystemsettingPanel1;
lv_obj_t * ui_SystemsettingImage1;
lv_obj_t * ui_SystemsettingImage2;
lv_obj_t * ui_SystemsettingImage3;
lv_obj_t * ui_SystemsettingImage4;
lv_obj_t * ui_SystemsettingImage5;
lv_obj_t * ui_SystemsettingPanel2;
lv_obj_t * ui_SystemsettingPanel3;
lv_obj_t * ui_PanelScreenSet;
lv_obj_t * ui_SystemsettingLabel1;
lv_obj_t * ui_PanelScreenOff;
lv_obj_t * ui_SystemsettingLabel2;
lv_obj_t * ui_SystemsettingDropdown1;
lv_obj_t * ui_PanelLanguage;
lv_obj_t * ui_SystemsettingLabel4;
lv_obj_t * ui_SystemlightDown;
lv_obj_t * ui_SystemlightUp;
lv_obj_t * ui_SystemsettingDropdown2;
lv_obj_t * ui_PanelTimeSet;
lv_obj_t * ui_SystemsettingImage8;
lv_obj_t * ui_SystemsettingLabel5;
lv_obj_t * ui_SystemsettingPanel5;
lv_obj_t * ui_SystemsettingImage9;
lv_obj_t * ui_SystemsettingLabel6;
lv_obj_t * ui_SystemsettingPanel6;
lv_obj_t * ui_SystemsettingLabel7;
lv_obj_t * ui_SystemsettingDropdown3;
lv_obj_t * ui_PanelDeviceBinding;
lv_obj_t * ui_SystemsettingImage10;
lv_obj_t * ui_SystemsettingLabel8;
lv_obj_t * ui_PanelExportLog;
lv_obj_t * ui_SystemsettingImage11;
lv_obj_t * ui_SystemsettingLabel9;
lv_obj_t * ui_PanelCheckVersion;
lv_obj_t * ui_SystemsettingImage12;
lv_obj_t * ui_SystemsettingLabel10;
lv_obj_t * ui_SystemsettingLabel11;
lv_obj_t * ui_SystemsettingLabeltips;
lv_obj_t * ui_PanelResetMachine;
lv_obj_t * ui_SystemsettingImage13;
lv_obj_t * ui_SystemsettingLabel12;
lv_obj_t * ui_PanelAboutDevice;
lv_obj_t * ui_SystemsettingImage14;
lv_obj_t * ui_SystemsettingLabel13;
lv_obj_t * ui_PanelDeviceCheck;
lv_obj_t * ui_SystemsettingImage15;
lv_obj_t * ui_SystemsettingLabel14;
lv_obj_t * ui_PanelUpdate;
lv_obj_t * ui_SystemsettingSwitch2;
lv_obj_t * ui_SystemsettingLabel15;
lv_obj_t * ui_PanelRoot;
lv_obj_t * ui_SystemsettingImage16;
lv_obj_t * ui_SystemsettingLabel16;
lv_obj_t * ui_PanelAdvancedMode;
lv_obj_t * ui_PanelAdvancedModeImg;
lv_obj_t * ui_PanelAdvancedModeLabel;
lv_obj_t * ui_NetworkSetting;
lv_obj_t * ui_NetworkSettingPanel1;
lv_obj_t * ui_NetworkSettingImage1;
lv_obj_t * ui_NetworkSettingImage2;
lv_obj_t * ui_NetworkSettingImage3;
lv_obj_t * ui_NetworkSettingImage4;
lv_obj_t * ui_NetworkSettingImage5;
lv_obj_t * ui_NetworkSettingPanel2;
lv_obj_t * ui_NetworkSettingPanel3;
lv_obj_t * ui_NetworkSettingPanel4;
lv_obj_t * ui_NetworkSettingImage6;
lv_obj_t * ui_NetworkSettingLabel1;
lv_obj_t * ui_NetworkSettingLabel2;
lv_obj_t * ui_NetworkSettingImage7;
lv_obj_t * ui_NetworkSettingPanel5;
lv_obj_t * ui_NetworkSettingPanel6;
lv_obj_t * ui_NetworkName;
lv_obj_t * ui_NetworkSettingLabel3;
lv_obj_t * ui_NetworkSetting_TextArea1;
lv_obj_t * ui_NetworkSetting_TextImg;
lv_obj_t * ui_NetworkSetting_Keyboard1;
lv_obj_t * ui_NetworkSettingImage8;
lv_obj_t * ui_NetworkSettingLabel4;
lv_obj_t * ui_NetworkDialog;
lv_obj_t * ui_NetworkDialog_label;
lv_obj_t * ui_NetworkDialog_btn_1;
lv_obj_t * ui_NetworkDialog_btn_1_label;
lv_obj_t * ui_NetworkDialog_btn_2;
lv_obj_t * ui_NetworkDialog_btn_2_label;
lv_obj_t * ui_wifiipinfogDialog;
lv_obj_t * ui_InfoDialog_label;
lv_obj_t * ui_InfoDialog_label_1;
lv_obj_t * ui_InfoDialog_label_2;

/**************未启用的控件变量****************/
lv_obj_t * ui_VideoSetting;
lv_obj_t * ui_VideoSettingPanel1;
lv_obj_t * ui_VideoSettingImage1;
lv_obj_t * ui_VideoSettingImage2;
lv_obj_t * ui_VideoSettingImage3;
lv_obj_t * ui_VideoSettingImage4;
lv_obj_t * ui_VideoSettingImage5;

/********************摄像头界面*********************/
lv_obj_t * ui_VideoSettingPanel2;
lv_obj_t * ui_VideoSettingPanel3;
lv_obj_t * ui_VideoSettingPanel4;
lv_obj_t * ui_VideoSettingImage6;
lv_obj_t * ui_VideoSettingLabel1;

lv_obj_t * ui_VideoSettingPanel5;
lv_obj_t * ui_VideoSettingImage7;
lv_obj_t * ui_VideoSettingLabel2;
lv_obj_t * ui_VideoSettingImage8;

lv_obj_t * ui_VideoSettingPanel6;
lv_obj_t * ui_VideoSettingImage9;
lv_obj_t * ui_VideoSettingLabel3;
lv_obj_t * ui_VideoSettingImage10;

lv_obj_t * ui_VideoSettingPanel7;
lv_obj_t * ui_VideoSettingImage11;
lv_obj_t * ui_VideoSettingLabel4;
lv_obj_t * ui_VideoSettingImage12;
/********************摄像头界面*********************/

/********************设置界面的table页*********************/
lv_obj_t * ui_Settings;
lv_obj_t * ui_SettingsTabview;
lv_obj_t * ui_Settingstitle1;
lv_obj_t * ui_Settingstitle2;
lv_obj_t * ui_Settingstitle3;
lv_obj_t * wifilist_btn;
char wifilist_name[64];         //用于弹出窗口做数据交换和判断的数据
unsigned char wifilist_state;   //用于弹出窗口做数据交换和判断的数据
wifi_list_t list_array[WIFI_MAX_NUMBER] = {0};
bool refresh_network_flag = false;
char Manualtest[12];
char Manualtestlength;
char Manualtest_curpage;
bool systemsettingflag = false;
static bool refresh_camera_flag = true;
///////////////////// VARIABLES ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_SystemsettingImage1(lv_event_t * e);
void ui_event_SystemsettingImage2(lv_event_t * e);
void ui_event_SystemsettingImage3(lv_event_t * e);
void ui_event_SystemsettingImage4(lv_event_t * e);
void ui_event_SystemsettingImage5(lv_event_t * e);

void ui_event_VideoSettingPanel5(lv_event_t * e);
void ui_event_VideoSettingPanel6(lv_event_t * e);
void ui_event_VideoSettingPanel7(lv_event_t * e);
void ui_event_SystemsettingPanel14(lv_event_t * e);
void ui_event_SystemsettingPanel11(lv_event_t * e);
void ui_event_SystemsettingPanel12(lv_event_t * e);
void ui_event_SystemsettingPanel10(lv_event_t * e);
void ui_event_SystemsettingPanel9(lv_event_t * e);
void ui_event_SystemsettingLabel9(lv_event_t * e);
void ui_event_SystemsettingPanel7(lv_event_t * e);
void ui_event_SystemsettingPanel5(lv_event_t * e);
void ui_event_SystemsettingDropdown1(lv_event_t * e);
void ui_event_SystemsettingDropdown2(lv_event_t * e);
void ui_event_SystemsettingDropdown3(lv_event_t * e);
void ui_event_SystemsettingImage4(lv_event_t * e);
void ui_event_SystemsettingPanel4(lv_event_t * e);
void ui_event_SystemsettingSlider1(lv_event_t * e);
void ui_event_SystemsettingSwitch2(lv_event_t * e);
void ui_event_AdvancedModeHandle(lv_event_t * e);
void ui_event_SettingsTabview(lv_event_t * e);
void ui_event_NetworkSetting_Keyboard1(lv_event_t * e);
void ui_event_NetworkChangeVisible(lv_event_t * e);
void ui_event_NetworkSettingImage8(lv_event_t * e);
void ui_event_NetworkSettingPanel4(lv_event_t * e);
void ui_event_wifidialog(lv_event_t * e);
void ui_event_titlechange(lv_event_t * e);
void ui_event_Pageload(lv_event_t * e);
void ui_event_NetworkFocusChange(lv_event_t * e);
void ui_event_AdvancedModeHandle(lv_event_t * e);

static wifi_list_t create_wifi_list_item(lv_obj_t *parent, lv_align_t align_mode, lv_coord_t x, lv_coord_t y);
static void setting_screen_change_language_text(void);
void create_rootinfo_message(char *username, char *password, char *atLeastTime);

static const char * const kb_map_lc[] = {"1#", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", LV_SYMBOL_BACKSPACE, "\n",
                                  "abc", "A", "S", "D", "F", "G", "H", "J", "K", "L", LV_SYMBOL_NEW_LINE, "\n",
                                  "-", "Z", "X", "C", "V", "B", "N", "M", ".", ",", ";", "\n",
                                  LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT,""
                                };

static const char * const kb_map_uc[] = {"1#", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", LV_SYMBOL_BACKSPACE, "\n",
                                                 "ABC", "a", "s", "d", "f", "g", "h", "j", "k", "l", LV_SYMBOL_NEW_LINE, "\n",
                                                 "_", "-", "z", "x", "c", "v", "b", "n", "m", ".", ",", ":", "\n",
                                                 LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ""
                                                };

static const char * const kb_map_spec[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", LV_SYMBOL_BACKSPACE, "\n",
                                            "abc", "+", "-", "/", "*", "=", "%", "!", "?", "#", "<", ">", "\n",
                                            "\\",  "@", "$", "(", ")", "{", "}" "[", "]", ";", "\"", "'", "\n",
                                             "&", "~", "|", "`",LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_NEW_LINE,""
                                        };

static const char * * kb_map[3] = {
    (const char * *)kb_map_lc,
    (const char * *)kb_map_uc,
    (const char * *)kb_map_spec
    // (const char * *)default_kb_map_num,
    // (const char * *)default_kb_map_lc,
    // (const char * *)default_kb_map_lc,
    // (const char * *)default_kb_map_lc,
    // (const char * *)default_kb_map_lc,
    // (const char * *)NULL,
};


///////////////////// FUNCTIONS ////////////////////

void ui_Settings_screen_init(void)
{
    ui_Settings = lv_obj_create(NULL);

    uint8_t language_index = get_cur_language_index();
    ui_SystemsettingImage1 = lv_img_create(ui_Settings);
    //lv_img_set_src(ui_SystemsettingImage1, &ui_img_pagehome_png);
    lv_img_set_src(ui_SystemsettingImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_SystemsettingImage1, 80);
    lv_obj_set_height(ui_SystemsettingImage1, 96);
    lv_obj_add_flag(ui_SystemsettingImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SystemsettingImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage2 = lv_img_create(ui_Settings);
    lv_img_set_src(ui_SystemsettingImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_SystemsettingImage2, 80);
    lv_obj_set_height(ui_SystemsettingImage2, 96);
    lv_obj_set_x(ui_SystemsettingImage2, 0);
    lv_obj_set_y(ui_SystemsettingImage2, 96);
    lv_obj_add_flag(ui_SystemsettingImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SystemsettingImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SystemsettingImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage3 = lv_img_create(ui_Settings);
    lv_img_set_src(ui_SystemsettingImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_SystemsettingImage3, 80);
    lv_obj_set_height(ui_SystemsettingImage3, 96);
    lv_obj_set_x(ui_SystemsettingImage3, 0);
    lv_obj_set_y(ui_SystemsettingImage3, 192);
    lv_obj_add_flag(ui_SystemsettingImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SystemsettingImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SystemsettingImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage4 = lv_img_create(ui_Settings);
    lv_img_set_src(ui_SystemsettingImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_SystemsettingImage4, 80);
    lv_obj_set_height(ui_SystemsettingImage4, 96);
    lv_obj_set_x(ui_SystemsettingImage4, 0);
    lv_obj_set_y(ui_SystemsettingImage4, 288);
    lv_obj_add_flag(ui_SystemsettingImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SystemsettingImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SystemsettingImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage5 = lv_img_create(ui_Settings);
    lv_img_set_src(ui_SystemsettingImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_SystemsettingImage5, 80);
    lv_obj_set_height(ui_SystemsettingImage5, 96);
    lv_obj_set_x(ui_SystemsettingImage5, 0);
    lv_obj_set_y(ui_SystemsettingImage5, 384);
    lv_obj_add_flag(ui_SystemsettingImage5, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE );     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SystemsettingImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SystemsettingImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_SystemsettingImage1,ui_event_SystemsettingImage1,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage2,ui_event_SystemsettingImage2,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage3,ui_event_SystemsettingImage3,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage4,ui_event_SystemsettingImage4,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage5,ui_event_SystemsettingImage5,LV_EVENT_CLICKED,NULL);

	//Write codes settings_tabview_1
	ui_SettingsTabview = lv_tabview_create(ui_Settings, LV_DIR_TOP, 50);
	lv_obj_set_pos(ui_SettingsTabview, 80, 0);
	lv_obj_set_size(ui_SettingsTabview,720, 480);

	//title1
	ui_Settingstitle1 = lv_tabview_add_tab(ui_SettingsTabview,SystemArray[language_index]);

    //title2
	ui_Settingstitle2 = lv_tabview_add_tab(ui_SettingsTabview, NetworkArray[language_index]);

	//title3
	ui_Settingstitle3 = lv_tabview_add_tab(ui_SettingsTabview,CameraArray[language_index]);
	lv_obj_set_style_pad_all(ui_Settingstitle1,0,LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui_Settingstitle2,0,LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui_Settingstitle3,0,LV_STATE_DEFAULT);

	//tab样式设置
	//设置字体
	lv_obj_set_style_text_font(ui_SettingsTabview, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
	//设置tab整体背景颜色
    lv_obj_set_style_bg_color(lv_tabview_get_tab_btns(ui_SettingsTabview), lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    //设置tab标题字体颜色
    lv_obj_set_style_text_color(lv_tabview_get_tab_btns(ui_SettingsTabview), lv_color_hex(0x6a707d), LV_PART_MAIN|LV_STATE_DEFAULT);
    //设置选中tab的覆盖颜色
    lv_obj_set_style_bg_color(lv_tabview_get_tab_btns(ui_SettingsTabview), lv_color_hex(0xffffff), LV_PART_ITEMS|LV_STATE_CHECKED);
//    lv_obj_set_style_bg_color(lv_tabview_get_tab_btns(ui_SettingsTabview), lv_color_hex(0x232426), LV_PART_MAIN|LV_STATE_CHECKED);
//    lv_obj_set_style_text_color(lv_tabview_get_tab_btns(ui_SettingsTabview), lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);

    ui_SettingTitle = lv_obj_create(ui_Settings);
    lv_obj_set_width(ui_SettingTitle, 720);
    lv_obj_set_height(ui_SettingTitle, 50);
    lv_obj_set_x(ui_SettingTitle, 80);
    lv_obj_set_y(ui_SettingTitle, 0);
    lv_obj_clear_flag(ui_SettingTitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SettingTitle, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SettingTitle, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SettingTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingBtn = lv_btn_create(ui_SettingTitle);
    lv_obj_set_width(ui_SystemsettingBtn, 165);
    lv_obj_set_height(ui_SystemsettingBtn, 45);
    lv_obj_set_x(ui_SystemsettingBtn, 23);
    lv_obj_set_y(ui_SystemsettingBtn, 5);
    lv_obj_set_align(ui_SystemsettingBtn, LV_ALIGN_TOP_LEFT);
    lv_obj_add_flag(ui_SystemsettingBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SystemsettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemsettingBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemsettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SystemsettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SystemsettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_SystemsettingBtn, &ui_img_settingtitleimg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingTitle = lv_label_create(ui_SystemsettingBtn);
    lv_obj_set_width(ui_SystemsettingTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SystemsettingTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SystemsettingTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SystemsettingTitle, SystemArray[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingTitle, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SystemsettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SystemsettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SystemsettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SystemsettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_NetworksettingBtn = lv_btn_create(ui_SettingTitle);
    lv_obj_set_width(ui_NetworksettingBtn, 165);
    lv_obj_set_height(ui_NetworksettingBtn, 45);
    // lv_obj_set_x(ui_NetworksettingBtn, 23);
    // lv_obj_set_y(ui_NetworksettingBtn, 5);
    // lv_obj_set_align(ui_NetworksettingBtn, LV_ALIGN_TOP_LEFT);
    lv_obj_align_to(ui_NetworksettingBtn, ui_SystemsettingBtn, LV_ALIGN_OUT_RIGHT_MID,10,0);

    lv_obj_add_flag(ui_NetworksettingBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_NetworksettingBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworksettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworksettingBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworksettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_NetworksettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_NetworksettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_NetworksettingBtn, &ui_img_settingtitleimg_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_NetworksettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworksettingTitle = lv_label_create(ui_NetworksettingBtn);
    lv_obj_set_width(ui_NetworksettingTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_NetworksettingTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_NetworksettingTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_NetworksettingTitle, NetworkArray[language_index]);
    lv_obj_set_style_text_color(ui_NetworksettingTitle, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworksettingTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworksettingTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NetworksettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NetworksettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NetworksettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NetworksettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CamerasettingBtn = lv_btn_create(ui_SettingTitle);
    lv_obj_set_width(ui_CamerasettingBtn, 165);
    lv_obj_set_height(ui_CamerasettingBtn, 45);
    // lv_obj_set_x(ui_CamerasettingBtn, 23);
    // lv_obj_set_y(ui_CamerasettingBtn, 5);
    // lv_obj_set_align(ui_CamerasettingBtn, LV_ALIGN_TOP_LEFT);
    lv_obj_align_to(ui_CamerasettingBtn, ui_NetworksettingBtn, LV_ALIGN_OUT_RIGHT_MID,10,0);
    lv_obj_add_flag(ui_CamerasettingBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_CamerasettingBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CamerasettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CamerasettingBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CamerasettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_CamerasettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_CamerasettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_CamerasettingBtn, &ui_img_settingtitleimg_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_CamerasettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CamerasettingTitle = lv_label_create(ui_CamerasettingBtn);
    lv_obj_set_width(ui_CamerasettingTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_CamerasettingTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_CamerasettingTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_CamerasettingTitle, CameraArray[language_index]);
    lv_obj_set_style_text_color(ui_CamerasettingTitle, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CamerasettingTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CamerasettingTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CamerasettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CamerasettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CamerasettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CamerasettingTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingPanel2 = lv_obj_create(ui_Settingstitle1);
    lv_obj_set_width(ui_SystemsettingPanel2, 720);
    lv_obj_set_height(ui_SystemsettingPanel2, 430);
    lv_obj_set_x(ui_SystemsettingPanel2, 0);
    lv_obj_set_y(ui_SystemsettingPanel2, 0);
    lv_obj_clear_flag(ui_SystemsettingPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SystemsettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemsettingPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemsettingPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SystemsettingPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SystemsettingPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SystemsettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SystemsettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SystemsettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SystemsettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SystemsettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingPanel3 = lv_obj_create(ui_SystemsettingPanel2);
    lv_obj_set_width(ui_SystemsettingPanel3, 696);
    lv_obj_set_height(ui_SystemsettingPanel3, 406);
    lv_obj_set_align(ui_SystemsettingPanel3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SystemsettingPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags=
    lv_obj_set_style_bg_color(ui_SystemsettingPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemsettingPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SystemsettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SystemsettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_SystemsettingPanel3, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_SystemsettingPanel3, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_obj_set_style_pad_row(ui_SystemsettingPanel3, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SystemsettingPanel3, 26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelScreenSet = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelScreenSet, 685);
    lv_obj_set_height(ui_PanelScreenSet, 52);
    lv_obj_set_style_bg_color(ui_PanelScreenSet, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelScreenSet, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelScreenSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelScreenSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingLabel1 = lv_label_create(ui_PanelScreenSet);
    lv_obj_set_width(ui_SystemsettingLabel1, 300);
    lv_obj_set_height(ui_SystemsettingLabel1, 24);
    lv_obj_align(ui_SystemsettingLabel1, LV_ALIGN_LEFT_MID, 24, 0);
    lv_label_set_text(ui_SystemsettingLabel1, ScreenBrightnessArray[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SystemsettingLabel1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemlightDown = lv_btn_create(ui_PanelScreenSet);
    lv_obj_set_width(ui_SystemlightDown, 151);
    lv_obj_set_height(ui_SystemlightDown, 52);
    lv_obj_align(ui_SystemlightDown, LV_ALIGN_LEFT_MID, 372, 0);
    lv_obj_add_flag(ui_SystemlightDown, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SystemlightDown, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SystemlightDown, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemlightDown, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemlightDown, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SystemlightDown, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SystemlightDown, lv_color_hex(0x60646C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SystemlightDown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SystemlightDown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_SystemlightDown, &ui_img_down_white_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_SystemlightDown, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemlightUp = lv_btn_create(ui_PanelScreenSet);
    lv_obj_set_width(ui_SystemlightUp, 151);
    lv_obj_set_height(ui_SystemlightUp, 52);
    lv_obj_align(ui_SystemlightUp, LV_ALIGN_LEFT_MID, 521, 0);
    lv_obj_add_flag(ui_SystemlightUp, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SystemlightUp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SystemlightUp, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemlightUp, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemlightUp, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SystemlightUp, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SystemlightUp, lv_color_hex(0x60646C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SystemlightUp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SystemlightUp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_SystemlightUp, &ui_img_up_white_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_SystemlightUp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelScreenOff = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelScreenOff, 685);
    lv_obj_set_height(ui_PanelScreenOff, 50);
    lv_obj_set_style_bg_color(ui_PanelScreenOff, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelScreenOff, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelScreenOff, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelScreenOff, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingLabel2 = lv_label_create(ui_PanelScreenOff);
    lv_obj_set_width(ui_SystemsettingLabel2, 300);
    lv_obj_set_height(ui_SystemsettingLabel2, 24);
    lv_obj_align(ui_SystemsettingLabel2, LV_ALIGN_LEFT_MID, 24, 0);
    lv_label_set_text(ui_SystemsettingLabel2, ScreenOffArray[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    char buff[150] = {0};
    sprintf(buff, "3%s\n5%s\n%s", MinuteArray[language_index], MinuteArray[language_index], NotSetArray[language_index]);

    ui_SystemsettingDropdown1 = lv_dropdown_create(ui_PanelScreenOff);
    lv_dropdown_set_options(ui_SystemsettingDropdown1, buff);
    lv_obj_set_width(ui_SystemsettingDropdown1, 300);
    lv_obj_set_height(ui_SystemsettingDropdown1, 50);
    lv_obj_align(ui_SystemsettingDropdown1, LV_ALIGN_LEFT_MID, 371, 0);
    lv_obj_add_flag(ui_SystemsettingDropdown1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_SystemsettingDropdown1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SystemsettingDropdown1, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingDropdown1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SystemsettingDropdown1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemsettingDropdown1, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemsettingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SystemsettingDropdown1, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SystemsettingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SystemsettingDropdown1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_SystemsettingDropdown1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingDropdown1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingDropdown1, lv_font25.font, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_SystemsettingDropdown1, LV_OBJ_FLAG_SCROLLABLE);
    lv_dropdown_set_symbol(ui_SystemsettingDropdown1, &ui_img_expand_down_png);

    ui_PanelLanguage = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelLanguage, 685);
    lv_obj_set_height(ui_PanelLanguage, 50);
    lv_obj_set_style_bg_color(ui_PanelLanguage, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelLanguage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLanguage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelLanguage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingLabel4 = lv_label_create(ui_PanelLanguage);
    lv_obj_set_width(ui_SystemsettingLabel4, 300);
    lv_obj_set_height(ui_SystemsettingLabel4, 24);
    lv_obj_align(ui_SystemsettingLabel4, LV_ALIGN_LEFT_MID, 24, 0);
    lv_label_set_text(ui_SystemsettingLabel4, LanguageSelection[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel4, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingDropdown2 = lv_dropdown_create(ui_PanelLanguage);
    lv_dropdown_set_options(ui_SystemsettingDropdown2, "Option 1\nOption 2\nOption 3\nOption 4");
    lv_dropdown_set_dir(ui_SystemsettingDropdown2,LV_DIR_BOTTOM);
    lv_obj_set_width(ui_SystemsettingDropdown2, 300);
    lv_obj_set_height(ui_SystemsettingDropdown2, 50);
    lv_obj_align(ui_SystemsettingDropdown2, LV_ALIGN_LEFT_MID, 371, 0);
    lv_obj_add_flag(ui_SystemsettingDropdown2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_SystemsettingDropdown2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingDropdown2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SystemsettingDropdown2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingDropdown2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SystemsettingDropdown2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemsettingDropdown2, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemsettingDropdown2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SystemsettingDropdown2, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SystemsettingDropdown2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SystemsettingDropdown2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_SystemsettingDropdown2, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingDropdown2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingDropdown2, lv_font25.font, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_dropdown_set_symbol(ui_SystemsettingDropdown2, &ui_img_expand_down_png);

    ui_PanelDeviceCheck = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelDeviceCheck, 685);
    lv_obj_set_height(ui_PanelDeviceCheck, 39);
    lv_obj_set_style_bg_color(ui_PanelDeviceCheck, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelDeviceCheck, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelDeviceCheck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelDeviceCheck, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelDeviceCheck, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage15 = lv_img_create(ui_PanelDeviceCheck);
    lv_img_set_src(ui_SystemsettingImage15, &ui_img_vector_24_png);
    lv_obj_set_width(ui_SystemsettingImage15, 14);
    lv_obj_set_height(ui_SystemsettingImage15, 28);
    lv_obj_set_x(ui_SystemsettingImage15, -20);
    lv_obj_set_y(ui_SystemsettingImage15, 0);
    lv_obj_set_align(ui_SystemsettingImage15, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_SystemsettingImage15, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage15, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_SystemsettingImage15, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_SystemsettingLabel14 = lv_label_create(ui_PanelDeviceCheck);
    lv_obj_set_width(ui_SystemsettingLabel14, 500);
    lv_obj_set_height(ui_SystemsettingLabel14, 24);
    lv_obj_set_x(ui_SystemsettingLabel14, 24);
    lv_obj_set_y(ui_SystemsettingLabel14, 0);
    lv_obj_set_align(ui_SystemsettingLabel14, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SystemsettingLabel14, DeviceSelfTestArray[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel14, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel14, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SystemsettingLabel14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
 
    ui_PanelRoot = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelRoot, 685);
    lv_obj_set_height(ui_PanelRoot, 39);
    lv_obj_set_style_bg_color(ui_PanelRoot, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelRoot, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelRoot, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelRoot, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelRoot, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage16 = lv_img_create(ui_PanelRoot);
    lv_img_set_src(ui_SystemsettingImage16, &ui_img_vector_24_png);
    lv_obj_set_width(ui_SystemsettingImage16, 14);
    lv_obj_set_height(ui_SystemsettingImage16, 28);
    lv_obj_set_x(ui_SystemsettingImage16, -20);
    lv_obj_set_y(ui_SystemsettingImage16, 0);
    lv_obj_set_align(ui_SystemsettingImage16, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_SystemsettingImage16, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage16, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_SystemsettingImage16, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_SystemsettingLabel16 = lv_label_create(ui_PanelRoot);
    lv_obj_set_width(ui_SystemsettingLabel16, 500);
    lv_obj_set_height(ui_SystemsettingLabel16, 24);
    lv_obj_set_x(ui_SystemsettingLabel16, 24);
    lv_obj_set_y(ui_SystemsettingLabel16, 0);
    lv_obj_set_align(ui_SystemsettingLabel16, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SystemsettingLabel16, RootInfoTips[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel16, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel16, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SystemsettingLabel16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelUpdate = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelUpdate, 685);
    lv_obj_set_height(ui_PanelUpdate, 39);
    lv_obj_set_style_bg_color(ui_PanelUpdate, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelUpdate, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelUpdate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelUpdate, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelUpdate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingSwitch2 = lv_switch_create(ui_PanelUpdate);
    lv_obj_set_width(ui_SystemsettingSwitch2, 74);
    lv_obj_set_height(ui_SystemsettingSwitch2, 36);
    lv_obj_set_x(ui_SystemsettingSwitch2, -20);
    lv_obj_set_y(ui_SystemsettingSwitch2, 0);
    lv_obj_set_align(ui_SystemsettingSwitch2, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_SystemsettingSwitch2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_radius(ui_SystemsettingSwitch2, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemsettingSwitch2, lv_color_hex(0x43454A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemsettingSwitch2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SystemsettingSwitch2, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SystemsettingSwitch2, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(ui_SystemsettingSwitch2, 30, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemsettingSwitch2, lv_color_hex(0x5F646C), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemsettingSwitch2, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemsettingSwitch2, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SystemsettingSwitch2, 255, LV_PART_KNOB | LV_STATE_CHECKED);

    ui_SystemsettingLabel15 = lv_label_create(ui_PanelUpdate);
    lv_obj_set_width(ui_SystemsettingLabel15, 500);
    lv_obj_set_height(ui_SystemsettingLabel15, 24);
    lv_obj_set_x(ui_SystemsettingLabel15, 24);
    lv_obj_set_y(ui_SystemsettingLabel15, 0);
    lv_obj_set_align(ui_SystemsettingLabel15, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SystemsettingLabel15, UpdateReminder[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel15, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel15, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SystemsettingLabel15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelTimeSet = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelTimeSet, 685);
    lv_obj_set_height(ui_PanelTimeSet, 39);
    lv_obj_set_style_bg_color(ui_PanelTimeSet, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTimeSet, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelTimeSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelTimeSet, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelTimeSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage8 = lv_img_create(ui_PanelTimeSet);
    lv_img_set_src(ui_SystemsettingImage8, &ui_img_vector_24_png);
    lv_obj_set_width(ui_SystemsettingImage8, 14);
    lv_obj_set_height(ui_SystemsettingImage8, 28);
    lv_obj_set_x(ui_SystemsettingImage8, -20);
    lv_obj_set_y(ui_SystemsettingImage8, 0);
    lv_obj_set_align(ui_SystemsettingImage8, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_SystemsettingImage8, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_SystemsettingImage8, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_SystemsettingLabel5 = lv_label_create(ui_PanelTimeSet);
    lv_obj_set_width(ui_SystemsettingLabel5, 500);
    lv_obj_set_height(ui_SystemsettingLabel5, 24);
    lv_obj_set_x(ui_SystemsettingLabel5, 24);
    lv_obj_set_y(ui_SystemsettingLabel5, 0);
    lv_obj_set_align(ui_SystemsettingLabel5, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SystemsettingLabel5, TimeZoneArray[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel5, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SystemsettingLabel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelDeviceBinding = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelDeviceBinding, 685);
    lv_obj_set_height(ui_PanelDeviceBinding, 39);
    lv_obj_set_style_bg_color(ui_PanelDeviceBinding, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelDeviceBinding, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelDeviceBinding, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelDeviceBinding, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelDeviceBinding, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage10 = lv_img_create(ui_PanelDeviceBinding);
    lv_img_set_src(ui_SystemsettingImage10, &ui_img_vector_24_png);
    lv_obj_set_width(ui_SystemsettingImage10, 14);
    lv_obj_set_height(ui_SystemsettingImage10, 28);
    lv_obj_set_x(ui_SystemsettingImage10, -20);
    lv_obj_set_y(ui_SystemsettingImage10, 0);
    lv_obj_set_align(ui_SystemsettingImage10, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_SystemsettingImage10, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_SystemsettingImage10, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_SystemsettingLabel8 = lv_label_create(ui_PanelDeviceBinding);
    lv_obj_set_width(ui_SystemsettingLabel8, 500);
    lv_obj_set_height(ui_SystemsettingLabel8, 24);
    lv_obj_set_x(ui_SystemsettingLabel8, 24);
    lv_obj_set_y(ui_SystemsettingLabel8, 0);
    lv_obj_set_align(ui_SystemsettingLabel8, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SystemsettingLabel8, BindDevice[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel8, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SystemsettingLabel8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelExportLog = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelExportLog, 685);
    lv_obj_set_height(ui_PanelExportLog, 39);
    lv_obj_set_style_bg_color(ui_PanelExportLog, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelExportLog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelExportLog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelExportLog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelExportLog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage11 = lv_img_create(ui_PanelExportLog);
    lv_img_set_src(ui_SystemsettingImage11, &ui_img_vector_24_png);
    lv_obj_set_width(ui_SystemsettingImage11, 14);
    lv_obj_set_height(ui_SystemsettingImage11, 28);
    lv_obj_set_x(ui_SystemsettingImage11, -20);
    lv_obj_set_y(ui_SystemsettingImage11, 0);
    lv_obj_set_align(ui_SystemsettingImage11, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_SystemsettingImage11, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_SystemsettingImage11, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_SystemsettingLabel9 = lv_label_create(ui_PanelExportLog);
    lv_obj_set_width(ui_SystemsettingLabel9, 500);
    lv_obj_set_height(ui_SystemsettingLabel9, 24);
    lv_obj_set_x(ui_SystemsettingLabel9, 24);
    lv_obj_set_y(ui_SystemsettingLabel9, 0);
    lv_obj_set_align(ui_SystemsettingLabel9, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SystemsettingLabel9, ExportLogArray[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel9, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SystemsettingLabel9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelCheckVersion = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelCheckVersion, 685);
    lv_obj_set_height(ui_PanelCheckVersion, 39);
    lv_obj_set_style_bg_color(ui_PanelCheckVersion, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCheckVersion, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelCheckVersion, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelCheckVersion, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelCheckVersion, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage12 = lv_img_create(ui_PanelCheckVersion);
    lv_img_set_src(ui_SystemsettingImage12, &ui_img_vector_24_png);
    lv_obj_set_width(ui_SystemsettingImage12, 14);
    lv_obj_set_height(ui_SystemsettingImage12, 28);
    lv_obj_set_x(ui_SystemsettingImage12, -20);
    lv_obj_set_y(ui_SystemsettingImage12, 0);
    lv_obj_set_align(ui_SystemsettingImage12, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_SystemsettingImage12, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_SystemsettingImage12, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_SystemsettingLabel10 = lv_label_create(ui_PanelCheckVersion);
    lv_obj_set_width(ui_SystemsettingLabel10, 500);
    lv_obj_set_height(ui_SystemsettingLabel10, 24);
    lv_obj_set_x(ui_SystemsettingLabel10, 24);
    lv_obj_set_y(ui_SystemsettingLabel10, 0);
    lv_obj_set_align(ui_SystemsettingLabel10, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SystemsettingLabel10, VersionArray[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel10, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel10, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SystemsettingLabel10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%sV1.0.1", CurVersionArray[language_index]);
    ui_SystemsettingLabel11 = lv_label_create(ui_PanelCheckVersion);
    lv_obj_set_width(ui_SystemsettingLabel11, 300);
    lv_obj_set_height(ui_SystemsettingLabel11, 24);
    lv_obj_align(ui_SystemsettingLabel11, LV_ALIGN_RIGHT_MID, -60, 0);
    lv_label_set_text(ui_SystemsettingLabel11, buff);
    lv_obj_set_style_text_color(ui_SystemsettingLabel11, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SystemsettingLabel11, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel11, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SystemsettingLabel11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingLabeltips = lv_label_create(ui_PanelCheckVersion);
    lv_obj_set_width(ui_SystemsettingLabeltips, 9);
    lv_obj_set_height(ui_SystemsettingLabeltips, 9);
    lv_obj_align(ui_SystemsettingLabeltips, LV_ALIGN_TOP_LEFT, 637, 0);
    lv_label_set_text(ui_SystemsettingLabeltips, "");
    lv_obj_set_style_opa(ui_SystemsettingLabeltips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemsettingLabeltips, lv_color_hex(0xF55254), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemsettingLabeltips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SystemsettingLabeltips, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_SystemsettingLabeltips, LV_OBJ_FLAG_HIDDEN); 

    ui_PanelResetMachine = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelResetMachine, 685);
    lv_obj_set_height(ui_PanelResetMachine, 39);
    lv_obj_set_style_bg_color(ui_PanelResetMachine, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelResetMachine, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelResetMachine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelResetMachine, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelResetMachine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage13 = lv_img_create(ui_PanelResetMachine);
    lv_img_set_src(ui_SystemsettingImage13, &ui_img_vector_24_png);
    lv_obj_set_width(ui_SystemsettingImage13, 14);
    lv_obj_set_height(ui_SystemsettingImage13, 28);
    lv_obj_set_x(ui_SystemsettingImage13, -20);
    lv_obj_set_y(ui_SystemsettingImage13, 0);
    lv_obj_set_align(ui_SystemsettingImage13, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_SystemsettingImage13, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage13, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_SystemsettingImage13, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_SystemsettingLabel12 = lv_label_create(ui_PanelResetMachine);
    lv_obj_set_width(ui_SystemsettingLabel12, 500);
    lv_obj_set_height(ui_SystemsettingLabel12, 24);
    lv_obj_set_x(ui_SystemsettingLabel12, 24);
    lv_obj_set_y(ui_SystemsettingLabel12, 0);
    lv_obj_set_align(ui_SystemsettingLabel12, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SystemsettingLabel12, ResetMachine[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel12, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel12, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SystemsettingLabel12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelAdvancedMode = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelAdvancedMode, 685);
    lv_obj_set_height(ui_PanelAdvancedMode, 39);
    lv_obj_set_style_bg_color(ui_PanelAdvancedMode, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelAdvancedMode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelAdvancedMode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelAdvancedMode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelAdvancedMode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelAdvancedModeImg = lv_img_create(ui_PanelAdvancedMode);
    lv_img_set_src(ui_PanelAdvancedModeImg, &ui_img_vector_24_png);
    lv_obj_set_width(ui_PanelAdvancedModeImg, 14);
    lv_obj_set_height(ui_PanelAdvancedModeImg, 28);
    lv_obj_set_x(ui_PanelAdvancedModeImg, -20);
    lv_obj_set_y(ui_PanelAdvancedModeImg, 0);
    lv_obj_set_align(ui_PanelAdvancedModeImg, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_PanelAdvancedModeImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PanelAdvancedModeImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_PanelAdvancedModeImg, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_PanelAdvancedModeLabel = lv_label_create(ui_PanelAdvancedMode);
    lv_obj_set_width(ui_PanelAdvancedModeLabel, 500);
    lv_obj_set_height(ui_PanelAdvancedModeLabel, 24);
    lv_obj_set_x(ui_PanelAdvancedModeLabel, 24);
    lv_obj_set_y(ui_PanelAdvancedModeLabel, 0);
    lv_obj_set_align(ui_PanelAdvancedModeLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_PanelAdvancedModeLabel, AdvancedMode[language_index]);
    lv_obj_set_style_text_color(ui_PanelAdvancedModeLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_PanelAdvancedModeLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_PanelAdvancedModeLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelAdvancedModeLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelAboutDevice = lv_obj_create(ui_SystemsettingPanel3);
    lv_obj_set_width(ui_PanelAboutDevice, 685);
    lv_obj_set_height(ui_PanelAboutDevice, 39);
    lv_obj_set_style_bg_color(ui_PanelAboutDevice, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelAboutDevice, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelAboutDevice, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelAboutDevice, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelAboutDevice, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SystemsettingImage14 = lv_img_create(ui_PanelAboutDevice);
    lv_img_set_src(ui_SystemsettingImage14, &ui_img_vector_24_png);
    lv_obj_set_width(ui_SystemsettingImage14, 14);
    lv_obj_set_height(ui_SystemsettingImage14, 28);
    lv_obj_set_x(ui_SystemsettingImage14, -20);
    lv_obj_set_y(ui_SystemsettingImage14, 0);
    lv_obj_set_align(ui_SystemsettingImage14, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_SystemsettingImage14, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemsettingImage14, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_SystemsettingImage14, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_SystemsettingLabel13 = lv_label_create(ui_PanelAboutDevice);
    lv_obj_set_width(ui_SystemsettingLabel13, 500);
    lv_obj_set_height(ui_SystemsettingLabel13, 24);
    lv_obj_set_x(ui_SystemsettingLabel13, 24);
    lv_obj_set_y(ui_SystemsettingLabel13, 0);
    lv_obj_set_align(ui_SystemsettingLabel13, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SystemsettingLabel13, AboutDevice[language_index]);
    lv_obj_set_style_text_color(ui_SystemsettingLabel13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SystemsettingLabel13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SystemsettingLabel13, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SystemsettingLabel13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_SystemsettingImage4, ui_event_SystemsettingImage4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemsettingDropdown1, ui_event_SystemsettingDropdown1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemsettingDropdown2, ui_event_SystemsettingDropdown2, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_SystemsettingDropdown3, ui_event_SystemsettingDropdown3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemlightDown, ui_event_SystemsettingSlider1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemlightUp, ui_event_SystemsettingSlider1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelTimeSet, ui_event_SystemsettingPanel4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage8, ui_event_SystemsettingPanel4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemsettingSwitch2, ui_event_SystemsettingSwitch2, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_SystemsettingPanel5, ui_event_SystemsettingPanel5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelDeviceBinding, ui_event_SystemsettingPanel7, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage10, ui_event_SystemsettingPanel7, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelExportLog, ui_event_SystemsettingPanel8, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage11, ui_event_SystemsettingPanel8, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelCheckVersion, ui_event_SystemsettingPanel9, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage12, ui_event_SystemsettingPanel9, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelResetMachine, ui_event_SystemsettingPanel10, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage13, ui_event_SystemsettingPanel10, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelAboutDevice, ui_event_SystemsettingPanel11, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage14, ui_event_SystemsettingPanel11, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelDeviceCheck, ui_event_SystemsettingPanel12, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage15, ui_event_SystemsettingPanel12, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelRoot, ui_event_SystemsettingPanel14, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SystemsettingImage16, ui_event_SystemsettingPanel14, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelAdvancedMode, ui_event_AdvancedModeHandle, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelAdvancedModeImg, ui_event_AdvancedModeHandle, LV_EVENT_ALL, NULL);

    /****Network****/
    ui_NetworkSettingPanel2 = lv_obj_create(ui_Settingstitle2);
    lv_obj_set_width(ui_NetworkSettingPanel2, 720);
    lv_obj_set_height(ui_NetworkSettingPanel2, 430);
    lv_obj_set_x(ui_NetworkSettingPanel2, 0);
    lv_obj_set_y(ui_NetworkSettingPanel2, 0);
    lv_obj_clear_flag(ui_NetworkSettingPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSettingPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSettingPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkSettingPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkSettingPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NetworkSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NetworkSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NetworkSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NetworkSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkSettingPanel3 = lv_obj_create(ui_NetworkSettingPanel2);
    lv_obj_set_width(ui_NetworkSettingPanel3, 696);
    lv_obj_set_height(ui_NetworkSettingPanel3, 406);
    lv_obj_set_align(ui_NetworkSettingPanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_NetworkSettingPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkSettingPanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSettingPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSettingPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NetworkSettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NetworkSettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NetworkSettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NetworkSettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkSettingPanel4 = lv_obj_create(ui_NetworkSettingPanel3);
    lv_obj_set_width(ui_NetworkSettingPanel4, 676);
    lv_obj_set_height(ui_NetworkSettingPanel4, 65);
    lv_obj_set_x(ui_NetworkSettingPanel4, 10);
    lv_obj_set_y(ui_NetworkSettingPanel4, 0);
    lv_obj_clear_flag(ui_NetworkSettingPanel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkSettingPanel4, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSettingPanel4, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSettingPanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkSettingPanel4, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkSettingPanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSettingPanel4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_NetworkSettingPanel4, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NetworkSettingPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NetworkSettingPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NetworkSettingPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NetworkSettingPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkSettingImage6 = lv_img_create(ui_NetworkSettingPanel4);
    lv_img_set_src(ui_NetworkSettingImage6, &ui_img_network_png);
    lv_obj_set_width(ui_NetworkSettingImage6, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_NetworkSettingImage6, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_NetworkSettingImage6, 14);
    lv_obj_set_y(ui_NetworkSettingImage6, 0);
    lv_obj_set_align(ui_NetworkSettingImage6, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_NetworkSettingImage6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkSettingImage6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_NetworkSettingLabel1 = lv_label_create(ui_NetworkSettingPanel4);
    lv_obj_set_width(ui_NetworkSettingLabel1, 260);
    lv_obj_set_height(ui_NetworkSettingLabel1, 25);
    lv_obj_set_x(ui_NetworkSettingLabel1, 55);
    lv_obj_set_y(ui_NetworkSettingLabel1, -3);
    lv_obj_set_align(ui_NetworkSettingLabel1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_NetworkSettingLabel1, LocalNetworkArray[language_index]);
    lv_obj_set_style_text_color(ui_NetworkSettingLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkSettingLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkSettingLabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkSettingLabel2 = lv_label_create(ui_NetworkSettingPanel4);
    lv_obj_set_width(ui_NetworkSettingLabel2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_NetworkSettingLabel2, LV_SIZE_CONTENT);
    lv_label_set_text(ui_NetworkSettingLabel2, UnConnectedArray[language_index]);
    lv_obj_align(ui_NetworkSettingLabel2, LV_ALIGN_RIGHT_MID, -45, 0);
    lv_obj_set_style_text_color(ui_NetworkSettingLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkSettingLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_NetworkSettingLabel2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkSettingLabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkSettingImage7 = lv_img_create(ui_NetworkSettingPanel4);
    lv_img_set_src(ui_NetworkSettingImage7, &ui_img_vector_24_png);
    lv_obj_set_width(ui_NetworkSettingImage7, 14);
    lv_obj_set_height(ui_NetworkSettingImage7, 28);
    lv_obj_set_x(ui_NetworkSettingImage7, -24);
    lv_obj_set_y(ui_NetworkSettingImage7, 0);
    lv_obj_set_align(ui_NetworkSettingImage7, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_NetworkSettingImage7, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkSettingImage7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_NetworkSettingPanel5 = lv_obj_create(ui_NetworkSettingPanel3);
    lv_obj_set_width(ui_NetworkSettingPanel5, 672);
    lv_obj_set_height(ui_NetworkSettingPanel5, 300);
    lv_obj_set_x(ui_NetworkSettingPanel5, 20);
    lv_obj_set_y(ui_NetworkSettingPanel5, 80);
    lv_obj_add_flag(ui_NetworkSettingPanel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkSettingPanel5, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSettingPanel5, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSettingPanel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkSettingPanel5, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkSettingPanel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSettingPanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_NetworkSettingPanel5, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NetworkSettingPanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NetworkSettingPanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NetworkSettingPanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NetworkSettingPanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_NetworkSettingPanel5, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_NetworkSettingPanel5, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
    lv_obj_set_style_pad_column(ui_NetworkSettingPanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkSettingPanel6 = lv_obj_create(ui_Settings);
    lv_obj_set_width(ui_NetworkSettingPanel6, 800);
    lv_obj_set_height(ui_NetworkSettingPanel6, 480);
    lv_obj_clear_flag(ui_NetworkSettingPanel6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkSettingPanel6, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSettingPanel6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSettingPanel6, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkSettingPanel6, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkSettingPanel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSettingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_NetworkSettingPanel6, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NetworkSettingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NetworkSettingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NetworkSettingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NetworkSettingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_NetworkSettingLabel3 = lv_textarea_create(ui_NetworkSettingPanel6);
    lv_obj_set_width(ui_NetworkSettingLabel3, 776);
    lv_obj_set_height(ui_NetworkSettingLabel3, 54);
    lv_obj_set_x(ui_NetworkSettingLabel3, 12);
    lv_obj_set_y(ui_NetworkSettingLabel3, 73);
    lv_textarea_set_text(ui_NetworkSettingLabel3, "");
    lv_obj_set_style_bg_color(ui_NetworkSettingLabel3, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSettingLabel3, 229, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkSettingLabel3, lv_color_hex(0x888989), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkSettingLabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSettingLabel3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_NetworkSettingLabel3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_NetworkSettingLabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkSettingLabel3, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSettingLabel3, lv_color_hex(0x000000), LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_textarea_set_placeholder_text(ui_NetworkSettingLabel3, Wifiname[language_index]);

    ui_NetworkSetting_TextArea1 = lv_textarea_create(ui_NetworkSettingPanel6);
    lv_obj_set_width(ui_NetworkSetting_TextArea1, 776);
    lv_obj_set_height(ui_NetworkSetting_TextArea1, 54);
    lv_obj_set_x(ui_NetworkSetting_TextArea1, 12);
    lv_obj_set_y(ui_NetworkSetting_TextArea1, 143);
    lv_obj_set_style_bg_color(ui_NetworkSetting_TextArea1, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSetting_TextArea1, 229, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkSetting_TextArea1, lv_color_hex(0x888989), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkSetting_TextArea1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSetting_TextArea1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_NetworkSetting_TextArea1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_NetworkSetting_TextArea1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_textarea_set_placeholder_text(ui_NetworkSetting_TextArea1, InputPasswordMsg[language_index]);
    lv_obj_set_style_text_font(ui_NetworkSetting_TextArea1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSetting_TextArea1, lv_color_hex(0x000000), LV_PART_CURSOR | LV_STATE_DEFAULT);

    ui_NetworkSetting_TextImg = lv_img_create(ui_NetworkSetting_TextArea1);
    lv_obj_set_width(ui_NetworkSetting_TextImg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_NetworkSetting_TextImg, LV_SIZE_CONTENT);
    lv_obj_align(ui_NetworkSetting_TextImg, LV_ALIGN_RIGHT_MID, 0, 0);
    char tempbuff[256] = {0};
    snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "Visible.png");
    lv_img_set_src(ui_NetworkSetting_TextImg, tempbuff);
    lv_obj_add_flag(ui_NetworkSetting_TextImg, LV_OBJ_FLAG_CLICKABLE);

    ui_NetworkSetting_Keyboard1 = lv_btnmatrix_create(ui_NetworkSettingPanel6);
    lv_btnmatrix_set_map(ui_NetworkSetting_Keyboard1, kb_map[KEYBOARD_MODE_TEXT_LOWER]);
    lv_btnmatrix_set_btn_width(ui_NetworkSetting_Keyboard1, 35, 4);        
    // lv_btnmatrix_set_btn_ctrl(ui_NetworkSetting_Keyboard1, 10, LV_BTNMATRIX_CTRL_CHECKABLE);
    // lv_btnmatrix_set_btn_ctrl(ui_NetworkSetting_Keyboard1, 11, LV_BTNMATRIX_CTRL_CHECKED);
    lv_obj_align(ui_NetworkSetting_Keyboard1, LV_ALIGN_BOTTOM_MID, 0, -10);

    lv_obj_set_width(ui_NetworkSetting_Keyboard1, 776);
    lv_obj_set_height(ui_NetworkSetting_Keyboard1, 260);
    // lv_obj_set_x(ui_NetworkSetting_Keyboard1, 0);
    // lv_obj_set_y(ui_NetworkSetting_Keyboard1, 0);
    lv_obj_set_style_text_font(ui_NetworkSetting_Keyboard1, lv_font25.font, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_NetworkSetting_Keyboard1, lv_color_hex(0xFFFFFF), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSetting_Keyboard1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSetting_Keyboard1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_NetworkSetting_Keyboard1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSetting_Keyboard1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSetting_Keyboard1, lv_color_hex(0x4C5057), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSetting_Keyboard1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_NetworkSetting_Keyboard1, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);

    ui_NetworkSettingImage8 = lv_img_create(ui_NetworkSettingPanel6);
    lv_img_set_src(ui_NetworkSettingImage8, &ui_img_group_12_png);
    lv_obj_set_width(ui_NetworkSettingImage8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_NetworkSettingImage8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_NetworkSettingImage8, 19);
    lv_obj_set_y(ui_NetworkSettingImage8, 21);
    lv_obj_add_flag(ui_NetworkSettingImage8, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_NetworkSettingImage8, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_NetworkSettingImage8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_ext_click_area(ui_NetworkSettingImage8, 30);

    ui_NetworkSettingLabel4 = lv_label_create(ui_NetworkSettingPanel6);
    lv_obj_set_width(ui_NetworkSettingLabel4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_NetworkSettingLabel4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_NetworkSettingLabel4, 0);
    lv_obj_set_y(ui_NetworkSettingLabel4, 21);
    lv_obj_set_align(ui_NetworkSettingLabel4, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_NetworkSettingLabel4, NetworkConnect[language_index]);
    lv_obj_set_style_text_color(ui_NetworkSettingLabel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkSettingLabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_NetworkSettingLabel4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkSettingLabel4, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_keyboard_set_textarea(ui_NetworkSetting_Keyboard1, ui_NetworkSetting_TextArea1);
    lv_obj_add_flag(ui_NetworkSettingPanel6,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(ui_NetworkSettingImage8, ui_event_NetworkSettingImage8, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_NetworkSettingPanel4, ui_event_NetworkSettingPanel4, LV_EVENT_ALL, NULL);


    /******Camerasetting*******/
    ui_VideoSettingPanel2 = lv_obj_create(ui_Settingstitle3);
    lv_obj_set_width(ui_VideoSettingPanel2, 720);
    lv_obj_set_height(ui_VideoSettingPanel2, 430);
    lv_obj_set_x(ui_VideoSettingPanel2, 0);
    lv_obj_set_y(ui_VideoSettingPanel2, 0);
    lv_obj_clear_flag(ui_VideoSettingPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VideoSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VideoSettingPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VideoSettingPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VideoSettingPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_VideoSettingPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VideoSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VideoSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VideoSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VideoSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VideoSettingPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VideoSettingPanel3 = lv_obj_create(ui_VideoSettingPanel2);
    lv_obj_set_width(ui_VideoSettingPanel3, 696);
    lv_obj_set_height(ui_VideoSettingPanel3, 406);
    lv_obj_set_align(ui_VideoSettingPanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_VideoSettingPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VideoSettingPanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VideoSettingPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VideoSettingPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VideoSettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VideoSettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VideoSettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VideoSettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VideoSettingPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    /**********摄像头的状态显示****************/
    ui_VideoSettingPanel4 = lv_obj_create(ui_VideoSettingPanel3);
    lv_obj_set_width(ui_VideoSettingPanel4, 409);
    lv_obj_set_height(ui_VideoSettingPanel4, 308);
    lv_obj_set_x(ui_VideoSettingPanel4, 15);
    lv_obj_set_y(ui_VideoSettingPanel4, 32);
    lv_obj_clear_flag(ui_VideoSettingPanel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_VideoSettingPanel4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_VideoSettingPanel4, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VideoSettingPanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VideoSettingPanel4, lv_color_hex(0x383A3C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_VideoSettingPanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VideoSettingPanel4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VideoSettingImage6 = lv_img_create(ui_VideoSettingPanel4);
    lv_img_set_src(ui_VideoSettingImage6, &ui_img_camera_png);
    lv_obj_set_width(ui_VideoSettingImage6, 109);
    lv_obj_set_height(ui_VideoSettingImage6, 109);
    lv_obj_set_align(ui_VideoSettingImage6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_VideoSettingImage6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_VideoSettingLabel1 = lv_label_create(ui_VideoSettingPanel3);
    lv_obj_set_width(ui_VideoSettingLabel1, 409);
    lv_obj_set_height(ui_VideoSettingLabel1, 28);
    lv_obj_set_x(ui_VideoSettingLabel1, 15);
    lv_obj_set_y(ui_VideoSettingLabel1, 350);
    // memset(buff, 0, sizeof(buff));
    // sprintf(buff, "%s%s", CameraArray[language_index], DisableArray[language_index]);
    lv_label_set_text(ui_VideoSettingLabel1, CameraArray[language_index]);
    lv_obj_set_style_text_color(ui_VideoSettingLabel1, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VideoSettingLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_VideoSettingLabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VideoSettingLabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    /**********视频列表****************/
    ui_VideoSettingPanel5 = lv_obj_create(ui_VideoSettingPanel3);
    lv_obj_set_width(ui_VideoSettingPanel5, 696);  //220改为696
    lv_obj_set_height(ui_VideoSettingPanel5, 80);
    lv_obj_set_x(ui_VideoSettingPanel5, 0);    //坐标446左移为0
    lv_obj_set_y(ui_VideoSettingPanel5, 28);
    lv_obj_clear_flag(ui_VideoSettingPanel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_VideoSettingPanel5, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VideoSettingPanel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_VideoSettingPanel5, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_VideoSettingPanel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_VideoSettingPanel5, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_VideoSettingPanel5, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VideoSettingPanel5, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VideoSettingPanel5, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VideoSettingPanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VideoSettingPanel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VideoSettingImage7 = lv_img_create(ui_VideoSettingPanel5);
    lv_img_set_src(ui_VideoSettingImage7, &ui_img_video_png);
    lv_obj_set_width(ui_VideoSettingImage7, 30);
    lv_obj_set_height(ui_VideoSettingImage7, 24);
    lv_obj_set_align(ui_VideoSettingImage7, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_VideoSettingImage7, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_VideoSettingLabel2 = lv_label_create(ui_VideoSettingPanel5);
    lv_obj_set_width(ui_VideoSettingLabel2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_VideoSettingLabel2, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_VideoSettingLabel2, 2);
    lv_obj_set_y(ui_VideoSettingLabel2, 0);
    lv_obj_set_align(ui_VideoSettingLabel2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_VideoSettingLabel2, VedioList[language_index]);
    lv_obj_set_style_text_color(ui_VideoSettingLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VideoSettingLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VideoSettingLabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VideoSettingImage8 = lv_img_create(ui_VideoSettingPanel5);
    lv_img_set_src(ui_VideoSettingImage8, &ui_img_vector_24_png);
    lv_obj_set_width(ui_VideoSettingImage8, 14);
    lv_obj_set_height(ui_VideoSettingImage8, 28);
    lv_obj_set_align(ui_VideoSettingImage8, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_VideoSettingImage8, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    /**********摄像头设置***************/
    ui_VideoSettingPanel6 = lv_obj_create(ui_VideoSettingPanel3);
    lv_obj_set_width(ui_VideoSettingPanel6, 696);   //220改为696
    lv_obj_set_height(ui_VideoSettingPanel6, 80);
    lv_obj_set_x(ui_VideoSettingPanel6, 0);   //坐标446左移为0
    lv_obj_set_y(ui_VideoSettingPanel6, 108);
    lv_obj_clear_flag(ui_VideoSettingPanel6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_VideoSettingPanel6, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VideoSettingPanel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_VideoSettingPanel6, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_VideoSettingPanel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_VideoSettingPanel6, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_VideoSettingPanel6, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VideoSettingPanel6, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VideoSettingPanel6, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VideoSettingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VideoSettingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VideoSettingImage9 = lv_img_create(ui_VideoSettingPanel6);
    lv_img_set_src(ui_VideoSettingImage9, &ui_img_seting_1_png);
    lv_obj_set_width(ui_VideoSettingImage9, 25);
    lv_obj_set_height(ui_VideoSettingImage9, 25);
    lv_obj_set_align(ui_VideoSettingImage9, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_VideoSettingImage9, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_VideoSettingLabel3 = lv_label_create(ui_VideoSettingPanel6);
    lv_obj_set_width(ui_VideoSettingLabel3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_VideoSettingLabel3, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_VideoSettingLabel3, 2);
    lv_obj_set_y(ui_VideoSettingLabel3, 0);
    lv_obj_set_align(ui_VideoSettingLabel3, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_VideoSettingLabel3, CameraSetting[language_index]);
    lv_obj_set_style_text_color(ui_VideoSettingLabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VideoSettingLabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VideoSettingLabel3, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VideoSettingImage10 = lv_img_create(ui_VideoSettingPanel6);
    lv_img_set_src(ui_VideoSettingImage10, &ui_img_vector_24_png);
    lv_obj_set_width(ui_VideoSettingImage10, 14);
    lv_obj_set_height(ui_VideoSettingImage10, 28);
    lv_obj_set_align(ui_VideoSettingImage10, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_VideoSettingImage10, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    /**********AI检测****************/
    ui_VideoSettingPanel7 = lv_obj_create(ui_VideoSettingPanel3);
    lv_obj_set_width(ui_VideoSettingPanel7, 696);  //220改为696
    lv_obj_set_height(ui_VideoSettingPanel7, 80);
    lv_obj_set_x(ui_VideoSettingPanel7, 0);      //坐标446左移为0
    lv_obj_set_y(ui_VideoSettingPanel7, 189);
    lv_obj_clear_flag(ui_VideoSettingPanel7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_VideoSettingPanel7, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VideoSettingPanel7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_VideoSettingPanel7, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_VideoSettingPanel7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_VideoSettingPanel7, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_VideoSettingPanel7, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_VideoSettingPanel7, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_VideoSettingPanel7, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_VideoSettingPanel7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_VideoSettingPanel7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VideoSettingImage11 = lv_img_create(ui_VideoSettingPanel7);
    lv_img_set_src(ui_VideoSettingImage11, &ui_img_ai_logo_png);
    lv_obj_set_width(ui_VideoSettingImage11, 32);
    lv_obj_set_height(ui_VideoSettingImage11, 32);
    lv_obj_set_align(ui_VideoSettingImage11, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_VideoSettingImage11, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_VideoSettingLabel4 = lv_label_create(ui_VideoSettingPanel7);
    lv_obj_set_width(ui_VideoSettingLabel4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_VideoSettingLabel4, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_VideoSettingLabel4, 2);
    lv_obj_set_y(ui_VideoSettingLabel4, 0);
    lv_obj_set_align(ui_VideoSettingLabel4, LV_ALIGN_LEFT_MID);
    // memset(buff, 0, sizeof(buff));
    // sprintf(buff, "AI%s", Detection[language_index]);
    lv_label_set_text(ui_VideoSettingLabel4, AIFunction[language_index]);
    lv_obj_set_style_text_color(ui_VideoSettingLabel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VideoSettingLabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VideoSettingLabel4, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VideoSettingImage12 = lv_img_create(ui_VideoSettingPanel7);
    lv_img_set_src(ui_VideoSettingImage12, &ui_img_vector_24_png);
    lv_obj_set_width(ui_VideoSettingImage12, 14);
    lv_obj_set_height(ui_VideoSettingImage12, 28);
    lv_obj_set_align(ui_VideoSettingImage12, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_VideoSettingImage12, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    

    /*******************其他初始化操作*********************/
#ifdef BRAZIL_CUSTOM_ORDER
        //屏蔽网络连接
        lv_obj_add_flag(ui_NetworksettingBtn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_align_to(ui_CamerasettingBtn, ui_SystemsettingBtn, LV_ALIGN_OUT_RIGHT_MID,10,0);

        //屏蔽系统设置
        lv_obj_add_flag(ui_PanelDeviceBinding, LV_OBJ_FLAG_HIDDEN);
        lv_obj_align_to(ui_PanelExportLog, ui_PanelTimeSet, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 44);
        lv_obj_align_to(ui_PanelCheckVersion, ui_PanelExportLog, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 44);
        lv_obj_align_to(ui_PanelResetMachine, ui_PanelCheckVersion, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 44);
        lv_obj_align_to(ui_PanelAboutDevice, ui_PanelResetMachine, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 44);
#else

#endif
    lv_obj_add_flag(ui_SystemsettingImage1, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_add_flag(ui_SystemsettingImage2, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_add_flag(ui_SystemsettingImage3, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_clear_flag(lv_tabview_get_content(ui_SettingsTabview), LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_VideoSettingPanel5, ui_event_VideoSettingPanel5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VideoSettingPanel6, ui_event_VideoSettingPanel6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VideoSettingPanel7, ui_event_VideoSettingPanel7, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_SettingsTabview, ui_event_SettingsTabview, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_NetworkSetting_Keyboard1, ui_event_NetworkSetting_Keyboard1, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_NetworkSetting_TextImg, ui_event_NetworkChangeVisible, LV_EVENT_CLICKED, NULL);

    lv_obj_add_event_cb(ui_SystemsettingBtn, ui_event_titlechange, LV_EVENT_ALL, '0');
    lv_obj_add_event_cb(ui_NetworksettingBtn, ui_event_titlechange, LV_EVENT_ALL, '1');
    lv_obj_add_event_cb(ui_CamerasettingBtn, ui_event_titlechange, LV_EVENT_ALL, '2');
    
    lv_obj_add_event_cb(ui_Settings, ui_event_Pageload, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_NetworkSettingLabel3, ui_event_NetworkFocusChange, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_NetworkSetting_TextArea1, ui_event_NetworkFocusChange, LV_EVENT_ALL, NULL);

    /****************修改的摄像头界面的内容********************/
    lv_obj_add_flag(ui_VideoSettingPanel4, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_add_flag(ui_VideoSettingImage6, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_add_flag(ui_VideoSettingLabel1, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_add_flag(ui_VideoSettingImage7, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_add_flag(ui_VideoSettingImage9, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_add_flag(ui_VideoSettingImage11, LV_OBJ_FLAG_HIDDEN);     /// Flags
    
    switch (UIType)
    {
        case CR_K1:     
                lv_obj_add_flag(ui_NetworkSettingPanel4, LV_OBJ_FLAG_HIDDEN);     /// Flags
                lv_obj_set_x(ui_NetworkSettingPanel5, 20);
                lv_obj_set_y(ui_NetworkSettingPanel5, 20);
                lv_obj_set_height(ui_NetworkSettingPanel5, 350);
                break;
        case CR_K1_Max:
                lv_obj_clear_flag(ui_NetworkSettingPanel4, LV_OBJ_FLAG_HIDDEN);     /// Flags
                lv_obj_set_x(ui_NetworkSettingPanel5, 20);
                lv_obj_set_y(ui_NetworkSettingPanel5, 80);
                lv_obj_set_height(ui_NetworkSettingPanel5, 300);
                break;
        default:
            break;
    }
}
//页面切换函数
void ui_event_Pageload(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        if(refresh_camera_flag)
        {
            refresh_camera_flag = false;
            // if(!system_state.Camera_model_state)
            // {
            //     CrLogI("don't have camera hidden the camera title");
            //     lv_obj_add_flag(ui_CamerasettingBtn, LV_OBJ_FLAG_HIDDEN);
            // }
        }
        int current_page = lv_tabview_get_tab_act(ui_SettingsTabview);
        switch (current_page)
        {
            case 0:lv_event_send(ui_SystemsettingBtn,LV_EVENT_CLICKED,"0");break;   //通知系统设置页面更新数据
            case 1:lv_event_send(ui_NetworksettingBtn,LV_EVENT_CLICKED,"1");break;  //通知系统设置页面更新数据
            case 2:lv_event_send(ui_CamerasettingBtn,LV_EVENT_CLICKED,"2");break;   //通知系统设置页面更新数据
            default:lv_event_send(ui_SystemsettingBtn,LV_EVENT_CLICKED,"0");break;  //通知系统设置页面更新数据
        }
        refresh_network_flag = true;
    }
    else if(event_code == LV_EVENT_SCREEN_UNLOADED) {
        refresh_network_flag = false;
    }
}

void ui_event_SystemsettingImage1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        // Your code here
        if ( home_printing_is_printing_finished() )
            LoadHomeNormalScreen();
        else
            LoadHomePrintingScreen();
    }
}
void ui_event_SystemsettingImage2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if ( home_printing_is_printing_finished() )
            LoadAxisMoveScreen();
        else
            LoadAxisMoveScreen();
    }
}
void ui_event_SystemsettingImage3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadFileManageScreen();
    }
}
void ui_event_SystemsettingImage4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        // _ui_screen_change(ui_Cameralist, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_SystemsettingImage5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        // _ui_screen_change(ui_Cameralist, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        LoadCustomerServiceScreen();
    }
}

void ui_event_titlechange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        uint16_t input_char = lv_event_get_user_data(e);
        CrLogI("%c",input_char);
        switch(input_char)
        {
            case '0':
                lv_obj_set_style_bg_img_opa(ui_SystemsettingBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_img_opa(ui_NetworksettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_img_opa(ui_CamerasettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_SystemsettingTitle, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_NetworksettingTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_CamerasettingTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_tabview_set_act(ui_SettingsTabview,0,LV_ANIM_OFF);
                break;
            case '1':
                lv_obj_set_style_bg_img_opa(ui_SystemsettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_img_opa(ui_NetworksettingBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_img_opa(ui_CamerasettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_SystemsettingTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_NetworksettingTitle, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_CamerasettingTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_tabview_set_act(ui_SettingsTabview,1,LV_ANIM_OFF); 
                break;
            case '2':
                lv_obj_set_style_bg_img_opa(ui_SystemsettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_img_opa(ui_NetworksettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_img_opa(ui_CamerasettingBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_SystemsettingTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_NetworksettingTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_CamerasettingTitle, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_tabview_set_act(ui_SettingsTabview,2,LV_ANIM_OFF); 
                break;
            default:
                lv_obj_set_style_bg_img_opa(ui_SystemsettingBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_img_opa(ui_NetworksettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_img_opa(ui_CamerasettingBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_SystemsettingTitle, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_NetworksettingTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_CamerasettingTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_tabview_set_act(ui_SettingsTabview,0,LV_ANIM_OFF);
                break;

        }
        lv_event_send(ui_SettingsTabview,LV_EVENT_CLICKED,NULL);
    }
}

void ui_event_VideoSettingPanel5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Cameralist, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        send_get_vedioes_count_cmd();
    }
}
void ui_event_VideoSettingPanel6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_camerasetting, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        send_get_camera_delayed_photography();
        send_get_camera_render_method_photoes();
        send_get_camera_shoot_freq();
        send_get_camera_shoot_pos();
    }
}
void ui_event_VideoSettingPanel7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        LoadAiDetectionScreen();
    }
}

//更改屏幕亮度
void ui_event_SystemsettingSlider1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        int lightvalue = system_state.light_value;    //获取当前亮度值
        if(target == ui_SystemlightDown)
        {
            CrLogI("light value down, current lightvalue:%d", lightvalue);
            lightvalue -= 10;
            if(lightvalue <= 10)//低于最低亮度值
            {
                lightvalue = 10;
            }
            char temp[5] = {0};
            snprintf(temp,5,"e%d",lightvalue);
            set_printer_data(0x06,strlen(temp),temp);
        }
        if(target == ui_SystemlightUp)
        {
            CrLogI("light value up, current lightvalue:%d", lightvalue);
            lightvalue += 10;
            if(lightvalue >= 100)//高于最大亮度值
            {
                lightvalue = 100;
            }
            char temp[5] = {0};
            snprintf(temp,5,"e%d",lightvalue);
            set_printer_data(0x06,strlen(temp),temp);
        }
    }
}

//息屏下拉列表事件处理
void ui_event_SystemsettingDropdown1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        send_buzzer(0x01);
        uint16_t index;
        index = lv_dropdown_get_selected(ui_SystemsettingDropdown1);
        CrLogI("screen_save_value set %d",index);
        switch(index)
        {
            case 0: set_printer_data(0x06,2,"b3");break;
            case 1: set_printer_data(0x06,2,"b5");break;
            case 2: set_printer_data(0x06,3,"b0");break;
            // case 3: set_printer_data(0x06,2,"b0");break;
            default:break;
        }
    }
    if(event_code == LV_EVENT_READY) {
        static lv_style_t list_selected_default;
        if (list_selected_default.prop_cnt > 1)
            lv_style_reset(&list_selected_default);
        else
            lv_style_init(&list_selected_default);
        lv_style_set_radius(&list_selected_default, 0);
        lv_style_set_bg_color(&list_selected_default, lv_color_hex(0x42BDD8));
        // lv_style_set_bg_grad_color(&list_selected_default, lv_color_hex(0x42BDD8));
        lv_style_set_bg_grad_dir(&list_selected_default, LV_GRAD_DIR_NONE);
        lv_style_set_bg_opa(&list_selected_default, 255);
        lv_style_set_border_color(&list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
        lv_style_set_border_width(&list_selected_default, 0);
        lv_style_set_text_color(&list_selected_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_text_font(&list_selected_default, lv_font25.font);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_selected_default, LV_PART_SELECTED|LV_STATE_FOCUSED);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_selected_default, LV_PART_SELECTED|LV_STATE_PRESSED);

        static lv_style_t list_main_default;
        if (list_main_default.prop_cnt > 1)
            lv_style_reset(&list_main_default);
        else
            lv_style_init(&list_main_default);
        lv_style_set_radius(&list_main_default, 0);
        lv_style_set_bg_color(&list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
        lv_style_set_bg_grad_color(&list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
        lv_style_set_bg_grad_dir(&list_main_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&list_main_default, 255);
        lv_style_set_border_color(&list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
        lv_style_set_border_width(&list_main_default, 0);
        lv_style_set_text_color(&list_main_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_text_font(&list_main_default, lv_font25.font);
        lv_style_set_max_height(&list_main_default, 150);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

        static lv_style_t scrollbar_default;
        if (scrollbar_default.prop_cnt > 1)
            lv_style_reset(&scrollbar_default);
        else
            lv_style_init(&scrollbar_default);
        lv_style_set_radius(&scrollbar_default, 3);
        lv_style_set_bg_grad_color(&scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_bg_grad_dir(&scrollbar_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&scrollbar_default, 0);
        lv_obj_add_style(lv_dropdown_get_list(target), &scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    }
}

//语言选择下拉列表事件处理
void ui_event_SystemsettingDropdown2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_changelanguage, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
    if(event_code == LV_EVENT_READY) {
        lv_obj_add_flag(lv_dropdown_get_list(target), LV_OBJ_FLAG_HIDDEN);
    }
}

//主题选择下拉列表事件处理
void ui_event_SystemsettingDropdown3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        uint16_t index;
        index = lv_dropdown_get_selected(ui_SystemsettingDropdown3);
        CrLogI("theme set: %d",index);
        switch(index)
        {
            // case 0: set_printer_data(0x06,2,"b3");break;
            // case 1: set_printer_data(0x06,2,"b5");break;
            // case 2: set_printer_data(0x06,3,"b15");break;
            // case 3: set_printer_data(0x06,2,"b0");break;
            default:break;
        }
    }
    if(event_code == LV_EVENT_READY) {
        static lv_style_t list_selected_default;
        if (list_selected_default.prop_cnt > 1)
            lv_style_reset(&list_selected_default);
        else
            lv_style_init(&list_selected_default);
        lv_style_set_radius(&list_selected_default, 0);
        lv_style_set_bg_color(&list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
        lv_style_set_bg_grad_color(&list_selected_default, lv_color_make(0x42, 0xbd, 0xd8));
        lv_style_set_bg_grad_dir(&list_selected_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&list_selected_default, 255);
        lv_style_set_border_color(&list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
        lv_style_set_border_width(&list_selected_default, 0);
        lv_style_set_text_color(&list_selected_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_text_font(&list_selected_default, lv_font25.font);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);

        static lv_style_t list_main_default;
        if (list_main_default.prop_cnt > 1)
            lv_style_reset(&list_main_default);
        else
            lv_style_init(&list_main_default);
        lv_style_set_radius(&list_main_default, 0);
        lv_style_set_bg_color(&list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
        lv_style_set_bg_grad_color(&list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
        lv_style_set_bg_grad_dir(&list_main_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&list_main_default, 255);
        lv_style_set_border_color(&list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
        lv_style_set_border_width(&list_main_default, 0);
        lv_style_set_text_color(&list_main_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_text_font(&list_main_default, lv_font25.font);
        lv_style_set_max_height(&list_main_default, 150);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

        static lv_style_t list_scrollbar_default;
        if (list_scrollbar_default.prop_cnt > 1)
            lv_style_reset(&list_scrollbar_default);
        else
            lv_style_init(&list_scrollbar_default);
        lv_style_set_radius(&list_scrollbar_default, 3);
        lv_style_set_bg_color(&list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
        lv_style_set_bg_grad_color(&list_scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_bg_grad_dir(&list_scrollbar_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&list_scrollbar_default, 255);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    }
}

void ui_event_SystemsettingPanel4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_TimezoneSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_SystemsettingSwitch2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(lv_obj_has_state(ui_SystemsettingSwitch2, LV_STATE_CHECKED))
        {
            set_printer_data(0x06, 2, "o1");
        }
        else
        {
            set_printer_data(0x06, 2, "o0");
        }
    }
}

void ui_event_SystemsettingPanel5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Keytonesetting, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_SystemsettingPanel7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Devicebinding, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_SystemsettingPanel8(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(print_state != 1)
        {
            CrLogI("exportlog page:machine state is print %d,don't start the print",print_state);
            create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
            return;
        }
        _ui_screen_change(ui_Exportlog, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_SystemsettingPanel10(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(print_state != 1)
        {
            CrLogI("resetmachine page:machine state is print %d,don't start the print",print_state);
            create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
            return;
        }
        _ui_screen_change(ui_ResetMachine, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_SystemsettingPanel11(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_AboutDevice, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_SystemsettingPanel12(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Manualtest, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
//root信息提示
void ui_event_SystemsettingPanel14(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //提示用户查看root信息政策
        create_rootpolicy_page();
    }
}

//专家模式
void ui_event_AdvancedModeHandle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //跳转专家模式页面
        ui_change(PAGE_ADVANCEDMODE);
    }
}

void ui_event_PrivacypolicyHandle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(target == userdata)//btn1
        {   
            _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        }
        else//btn2
        {
            if(print_state != 1)
            {
                CrLogI("updateversion page:machine state is print %d,don't start the print",print_state);
                create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
                return;
            }
            wifi_wait_animmotion(true);
            EnterUpdatepage(1);
        }
    }
}

//跳转版本升级页面
void ui_event_SystemsettingPanel9(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
#ifndef BRAZIL_CUSTOM_ORDER
        if(!init_uiconfiginfo.AgreePrivacyPolicy)
        {
            int index = get_cur_language_index();
            create_PrivacyMessagebox(PrivacyPolicyTips[index], NotAgree[index], Agree[index], ui_event_PrivacypolicyHandle, ui_event_PrivacypolicyHandle);
            return;
        }
        if(print_state != 1)
        {
            CrLogI("updateversion page:machine state is print %d,don't start the print",print_state);
            create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
            return;
        }
        wifi_wait_animmotion(true);
        EnterUpdatepage(1);
#endif
    }
}

void ui_event_NetworkSettingImage8(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_obj_add_flag(ui_NetworkSettingPanel6, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    }
}

//外部接口
void LoadSettingsScreen(void)
{
    _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
// //wifi处理事件
static void wifi_select_btn_ok_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    wifi_list_t *userdata = lv_event_get_user_data(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(userdata->wifi_type == 2)
            {
                char ctemp[256] = {0};
                snprintf(ctemp, 256, "2\t%s", lv_label_get_text(userdata->wifi_name));
                set_printer_data(0x07,strlen(ctemp),ctemp);
                wifi_wait_animmotion(1);
                get_printer_data(0x07, 1, "2");
            }
            else if(userdata->wifi_type == 1)
            {
                char ctemp[256] = {0};
                snprintf(ctemp, 256, "1\t%s", lv_label_get_text(userdata->wifi_name));
                set_printer_data(0x07,strlen(ctemp),ctemp);
                wifi_wait_animmotion(1);
                get_printer_data(0x07, 1, "2");
            }
            CrLogI("hidden the msgbox,%p",ui_NetworkDialog);
            lv_obj_add_flag(ui_NetworkDialog, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        }
            break;
        default:
            break;
	}
}

static void wifi_select_btn_cancel_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    wifi_list_t *userdata = lv_event_get_user_data(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(userdata->wifi_type == 1 || userdata->wifi_type == 2)
            {
                char ctemp[256] = {0};
                snprintf(ctemp, 256, "3\t%s", lv_label_get_text(userdata->wifi_name));
                set_printer_data(0x07,strlen(ctemp),ctemp);
                wifi_wait_animmotion(1);
                get_printer_data(0x07, 1, "2");
            }
            CrLogI("hidden the msgbox,%p",ui_NetworkDialog);
            lv_obj_add_flag(ui_NetworkDialog, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        }
            break;
        default:
            break;
	}
}

static void wifi_select_btn_quit_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            CrLogI("hidden the msgbox,%p",ui_NetworkDialog);
            lv_obj_add_flag(ui_NetworkDialog, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        }
            break;
        default:
            break;
	}
}

void wifi_msgbox(unsigned char flag,lv_obj_t * obj, wifi_list_t * wifi)
{
    uint8_t language_index = get_cur_language_index();
    if (ui_NetworkDialog == NULL)
    {
        ui_NetworkDialog = lv_obj_create(lv_layer_top());
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_size(ui_NetworkDialog, 800, 480);
        lv_obj_add_style(ui_NetworkDialog, &style_cont_msgbox, LV_PART_MAIN|LV_STATE_DEFAULT);
        ui_NetworkDialog_label = lv_obj_create(ui_NetworkDialog);
        lv_obj_set_size(ui_NetworkDialog_label, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        lv_obj_clear_flag(ui_NetworkDialog_label, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_NetworkDialog_label, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_NetworkDialog_label, lv_color_hex(0x3C3E42), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_NetworkDialog_label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_NetworkDialog_label, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(ui_NetworkDialog_label, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_NetworkDialog_label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_align_to(ui_NetworkDialog_label,obj,LV_ALIGN_OUT_BOTTOM_MID,0,0);
        lv_obj_set_layout(ui_NetworkDialog_label, LV_LAYOUT_FLEX);
        lv_obj_set_flex_flow(ui_NetworkDialog_label, LV_FLEX_FLOW_COLUMN);
        //btn_1
        ui_NetworkDialog_btn_1 = lv_btn_create(ui_NetworkDialog_label);
        lv_obj_set_size(ui_NetworkDialog_btn_1, 96, 60);
        lv_obj_add_style(ui_NetworkDialog_btn_1, &style_background_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_radius(ui_NetworkDialog_btn_1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_NetworkDialog_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_NetworkDialog_btn_1_label = lv_label_create(ui_NetworkDialog_btn_1);
        if(flag == 0)
        {
            lv_label_set_text(ui_NetworkDialog_btn_1_label, DisconnectOptArray[language_index]);
        }
        else
        {
            lv_label_set_text(ui_NetworkDialog_btn_1_label, ConnectOptArray[language_index]);
        }

        lv_obj_set_style_text_color(ui_NetworkDialog_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_NetworkDialog_btn_1_label, lv_font24.font, LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_NetworkDialog_btn_1, 0, LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_NetworkDialog_btn_1_label, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT);
        lv_obj_align(ui_NetworkDialog_btn_1_label, LV_ALIGN_CENTER, 0, 0);
        redefine_label_size(ui_NetworkDialog_btn_1_label, lv_font24.font, 0, 0, 240, 0);

        lv_obj_update_layout(ui_NetworkDialog_btn_1_label);
        redefine_widgets_size(ui_NetworkDialog_btn_1, ui_NetworkDialog_btn_1_label, 5, 0, 96, 60);

        //btn_2
        ui_NetworkDialog_btn_2 = lv_btn_create(ui_NetworkDialog_label);
        lv_obj_set_size(ui_NetworkDialog_btn_2, 96, 60);
        lv_obj_add_style(ui_NetworkDialog_btn_2, &style_background_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_radius(ui_NetworkDialog_btn_2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_NetworkDialog_btn_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_NetworkDialog_btn_2, 0, LV_STATE_DEFAULT);

        ui_NetworkDialog_btn_2_label = lv_label_create(ui_NetworkDialog_btn_2);
        lv_label_set_text(ui_NetworkDialog_btn_2_label, ForgetPasswordArray[language_index]);
        lv_obj_set_style_text_color(ui_NetworkDialog_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_NetworkDialog_btn_2_label, lv_font24.font, LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_NetworkDialog_btn_2_label, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT);
        lv_obj_align(ui_NetworkDialog_btn_2_label, LV_ALIGN_CENTER, 0, 0);
        redefine_label_size(ui_NetworkDialog_btn_2_label, lv_font24.font, 0, 0, 240, 0);
        lv_obj_update_layout(ui_NetworkDialog_btn_2_label);
        redefine_widgets_size(ui_NetworkDialog_btn_2, ui_NetworkDialog_btn_2_label, 5, 0, 96, 60);

        lv_obj_add_event_cb(ui_NetworkDialog_btn_1, wifi_select_btn_ok_event_handler, LV_EVENT_ALL, wifi);
        lv_obj_add_event_cb(ui_NetworkDialog_btn_2, wifi_select_btn_cancel_event_handler, LV_EVENT_ALL, wifi);
        lv_obj_add_event_cb(ui_NetworkDialog, wifi_select_btn_quit_event_handler, LV_EVENT_ALL, NULL);
    }
    if (lv_obj_has_flag(ui_NetworkDialog,LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(ui_NetworkDialog,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        if(flag == 0)
            lv_label_set_text(ui_NetworkDialog_btn_1_label, DisconnectOptArray[language_index]);
        else
            lv_label_set_text(ui_NetworkDialog_btn_1_label, ConnectOptArray[language_index]);
        redefine_label_size(ui_NetworkDialog_btn_1_label, lv_font24.font, 0, 0, 240, 0);
        
        lv_obj_update_layout(ui_NetworkDialog_btn_1_label);
        redefine_widgets_size(ui_NetworkDialog_btn_1, ui_NetworkDialog_btn_1_label, 5, 0, 96, 60);

        lv_label_set_text(ui_NetworkDialog_btn_2_label, ForgetPasswordArray[language_index]);
        redefine_label_size(ui_NetworkDialog_btn_2_label, lv_font24.font, 0, 0, 240, 0);
        
        lv_obj_update_layout(ui_NetworkDialog_btn_2_label);
        redefine_widgets_size(ui_NetworkDialog_btn_2, ui_NetworkDialog_btn_2_label, 5, 0, 96, 60);
        lv_coord_t width  = lv_obj_get_width(ui_NetworkDialog_btn_1) > lv_obj_get_width(ui_NetworkDialog_btn_2) ? lv_obj_get_width(ui_NetworkDialog_btn_1) : lv_obj_get_width(ui_NetworkDialog_btn_2);
        lv_obj_set_width(ui_NetworkDialog_btn_1, width);
        lv_obj_set_width(ui_NetworkDialog_btn_2, width);
    }
}

void ui_event_NetworkSetting_Keyboard1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        send_buzzer(0x01);
        uint32_t id = lv_btnmatrix_get_selected_btn(target);
        CrLogI("keyboard input id: %d",id);
        
        const char * txt = lv_btnmatrix_get_btn_text(target, lv_btnmatrix_get_selected_btn(target));
        if(txt == NULL) return;

        if(strcmp(txt, "abc") == 0) {
            lv_btnmatrix_set_map(target, kb_map[KEYBOARD_MODE_TEXT_LOWER]);
            return;
        }
        else if(strcmp(txt, "ABC") == 0) {
            lv_btnmatrix_set_map(target, kb_map[KEYBOARD_MODE_TEXT_UPPER]);
            return;
        }
        else if(strcmp(txt, "1#") == 0) {
            lv_btnmatrix_set_map(target, kb_map[KEYBOARD_MODE_SPECIAL]);
            return;
        }else if(strcmp(txt, LV_SYMBOL_LEFT) == 0) {
            lv_textarea_cursor_left(lv_keyboard_get_textarea(target));
        }
        else if(strcmp(txt, LV_SYMBOL_RIGHT) == 0) {
            lv_textarea_cursor_right(lv_keyboard_get_textarea(target));
        }
        else if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
            lv_textarea_del_char(lv_keyboard_get_textarea(target));
        }
        else if(strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) {
            if(lv_keyboard_get_textarea(target) == ui_NetworkSetting_TextArea1)
            {
                char ctemp[WIFI_NAME_LEN+4+63] = {0};
                strcat(ctemp, "0\t");
                strcat(ctemp, lv_textarea_get_text(ui_NetworkSettingLabel3));
                strcat(ctemp, "\t");

                const char *passw = lv_textarea_get_text(ui_NetworkSetting_TextArea1);
                if(passw != NULL)
                {
                    if(strlen(passw) < 8 && strlen(passw) != 0)
                    {
                        create_msgbox(PasswordTooShort[get_cur_language_index()], NULL, 1000, lv_scr_act());
                        lv_obj_add_flag(ui_NetworkSettingPanel6, LV_OBJ_FLAG_HIDDEN);
                        return;
                    }
                    else if(strlen(passw) > 64)
                    {
                        create_msgbox(PasswordTooLong[get_cur_language_index()], NULL, 1000, lv_scr_act());
                        lv_obj_add_flag(ui_NetworkSettingPanel6, LV_OBJ_FLAG_HIDDEN);
                        return;
                    }
                    strcat(ctemp, passw);
                    set_printer_data(0x07,strlen(ctemp),ctemp);
                    wifi_wait_animmotion(1);
                    get_printer_data(0x07, 1, "2");
                }
                else
                {
                    create_msgbox(PasswordError[get_cur_language_index()], NULL, 1000, lv_scr_act());
                }
                lv_obj_add_flag(ui_NetworkSettingPanel6, LV_OBJ_FLAG_HIDDEN);
            }
        }
        else
        {
            const char * txt = lv_btnmatrix_get_btn_text(target, id);
            lv_textarea_add_text(lv_keyboard_get_textarea(target), txt);
        }
    }
}

void ui_event_NetworkChangeVisible(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        char tempbuff[256] = {0};
	    if(lv_textarea_get_password_mode(ui_NetworkSetting_TextArea1))
        {
            lv_textarea_set_password_mode(ui_NetworkSetting_TextArea1,false);
            snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "Visible.png");
            lv_img_set_src(ui_NetworkSetting_TextImg, tempbuff);
        }
        else
        {
            lv_textarea_set_password_mode(ui_NetworkSetting_TextArea1,true);
            snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "NotVisible.png");
            lv_img_set_src(ui_NetworkSetting_TextImg, tempbuff);
        }
    }
}

static void wifi_list_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * obj = lv_event_get_target(e);
	unsigned char i = 0;
    switch (code)
    {
        case LV_EVENT_CLICKED:
        {
            wifi_list_t *user_data = lv_event_get_user_data(e);
            wifilist_state = user_data->wifi_type;
            const char * src = lv_label_get_text(user_data->wifi_name);
            if (src == NULL)
                return;
            for(i=0;i<sizeof(wifilist_name);i++)
                wifilist_name[i] = '\0';
            i = 0;
            while (*src)
            {
                wifilist_name[i++] = *src++;
            }
            switch(wifilist_state)
            {
                case 0:
                {
                    CrLogI("create the new network connect");
                    create_wificonect_page(lv_scr_act(), wifilist_name, false);
                    break;
                }
                case 1:
                {
                    CrLogI("create the wifidialog1");
                    wifi_msgbox(1, obj, user_data);
                    break;
                }
                case 2:
                {
                    CrLogI("create the wifidialog2");
                    wifi_msgbox(0, obj, user_data);
                    break;
                }
                case 3:
                {
                    CrLogI("create the hidden network connect");
                    create_wificonect_page(lv_scr_act(), "", true);
                    break;
                }
                case 4:
                {
                    CrLogI("connect the open network");
                    char ctemp[256] = {0};
                    snprintf(ctemp, 256, "0\t%s\t%s", wifilist_name, "");
                    set_printer_data(0x07,strlen(ctemp),ctemp);
                    wifi_wait_animmotion(1);
                    get_printer_data(0x07, 1, "2");
                    break;
                }
                default:CrLogE("don't have suitable type");
                    break;
            }
        break;
        }
        default:
            break;
    }
        
    
}

void getWifiLevelImgSrc(char * src, int levelnumber)
{
    int level = 0;
    char tempbuff[256] = {0};
    if (levelnumber <= MIN_RSSI)
        level = 0;
    else if (levelnumber >= MAX_RSSI)
        level = RSSI_LEVELS - 1;
    else
    {
        float inputRange = (MAX_RSSI - MIN_RSSI);
        float outputRange = (RSSI_LEVELS - 1);
        level = (int)((float)(levelnumber - MIN_RSSI) * outputRange / inputRange);
    }
    switch (level)
    {
        case 0:snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "wifi_state_1.png");break;
        case 1:snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "wifi_state_2.png");break;
        case 2:snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "wifi_state_3.png");break;
        case 3:snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "wifi_state_4.png");break;
        default:snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "wifi_state_4.png");break;
    }
    strcpy(src, tempbuff);
}

void show_wifi_list(char *data,int len)
{
    if(!refresh_network_flag)return;
    char dis_wifi_name[60];
    char wifi_type[10] = {0};
    char wifi_dis[10] = {0};
    char wifi_encryption_type[256] = {0};
    bool flag;
    unsigned char i = 0,k = 0;

    CrLogI("get data : %s",data);
    char *temp = strtok(data,"\t");
    lv_obj_clean(ui_NetworkSettingPanel5);
    memset(list_array, 0, 100 * sizeof(wifi_list_t));
    k = 0;
    while(temp)
    {
        CrLogI("single wifi data : %s,%d",temp,k);
        flag = false;
        int result = sscanf(temp, "%[^:]:%[^:]:%[^:]:%[^:]",dis_wifi_name, wifi_type, wifi_dis, wifi_encryption_type);
        if( result < 3)
        {
            CrLogE("explain the wifi data error,result count:%d",result);
            return;
        }
        CrLogI("single wifi name : %s",dis_wifi_name);
        CrLogI("single wifi type : %s",wifi_type);
        CrLogI("single wifi dis : %s",wifi_dis);
        CrLogI("single wifi encryption_type : %s",wifi_encryption_type);

        if(k >= WIFI_MAX_NUMBER) return;
        list_array[k] = create_wifi_list_item(ui_NetworkSettingPanel5, LV_ALIGN_TOP_LEFT, 0, 0);
        char tempbuff[256] = {0};
        getWifiLevelImgSrc(tempbuff, atoi(wifi_dis));
        switch(wifi_type[0]){
            case '2':{  //当前连接wifi
                //设置wifi名字并更新相关图片
                lv_obj_align(list_array[k].wifi_name,LV_ALIGN_TOP_LEFT,0,0);
                lv_obj_align_to(list_array[k].wifi_info,list_array[k].wifi_name,LV_ALIGN_OUT_BOTTOM_LEFT,0,0);

                lv_label_set_text(list_array[k].wifi_name,dis_wifi_name);
                lv_label_set_text(list_array[k].wifi_info,wifi_ip);
                lv_obj_set_style_text_color(list_array[k].wifi_name,lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_clear_flag(list_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(list_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(list_array[k].wifi_state,&ui_img_state_normal_png);
                lv_img_set_src(list_array[k].wifi_logo, tempbuff);
                //绑定事件
                list_array[k].wifi_type = 2;
                lv_obj_add_event_cb(list_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &list_array[k]);
                k++;
                break;
            }
            case '1':{  //已保存wifi
                //设置wifi名字并更新相关图片
                lv_label_set_text(list_array[k].wifi_name,dis_wifi_name);
                lv_obj_set_style_text_color(list_array[k].wifi_name,lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_add_flag(list_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(list_array[k].wifi_logo, tempbuff);
                lv_obj_add_flag(list_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
                //绑定事件
                list_array[k].wifi_type = 1;
                lv_obj_add_event_cb(list_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &list_array[k]);
                k++;
                break;
            }
            case '0':{  //未保存wifi
                //设置wifi名字并更新相关图片
                lv_label_set_text(list_array[k].wifi_name,dis_wifi_name);
                lv_obj_set_style_text_color(list_array[k].wifi_name,lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_img_set_src(list_array[k].wifi_logo, tempbuff);
                lv_obj_add_flag(list_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
                //绑定事件
                if(strcmp(wifi_encryption_type, "[ESS]") == 0)
                {
                    list_array[k].wifi_type = 4;
                    lv_obj_add_flag(list_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
                }
                else
                {
                    list_array[k].wifi_type = 0;
                    lv_obj_clear_flag(list_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
                    lv_img_set_src(list_array[k].wifi_state,&ui_img_wifi_state_1_png);
                }
                lv_obj_add_event_cb(list_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &list_array[k]);
                k++;
                break;
            }
            default:
                break;
        }
        temp = strtok(NULL,"\t");
    }
    list_array[k] = create_wifi_list_item(ui_NetworkSettingPanel5, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_label_set_text(list_array[k].wifi_name, OtherNetwork[get_cur_language_index()]);
    lv_obj_set_style_text_color(list_array[k].wifi_name,lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(list_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(list_array[k].wifi_logo,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(list_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
    //绑定事件
    list_array[k].wifi_type = 3;
    lv_obj_add_event_cb(list_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &list_array[k]);
}

//tab响应事件
void ui_event_SettingsTabview(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        int i = lv_tabview_get_tab_act(ui_SettingsTabview);
        if(i == 0)
        {
            CrLogI("refresh the systemsetting");
            get_printer_data(0x14,1,"\0");
            get_printer_data(0x06,1,"9");
            get_printer_data(0x06,1,"e");
            get_printer_data(0x06,1,"b");//屏幕保护时间
        }
        if(i == 1)
        {
            CrLogI("wifi page init,wait wifi refresh....");
            // char te[200];
            // snprintf(te,200,"%s\t%s\t%s\t%s\t%s","11","CXSW","172.23.208.184","70","2");
            // get_response_printer_data(0x07,100,te);
            // snprintf(te,200,"%s\t%s\t%s","2MW315R:2:-30:[WPA-PSK-CCMP+TKIP][WPA2-PSK-CCMP+TKIP][ESS]","CXSW-guest:1:-60:[WPA-PSK-CCMP+TKIP][WPA2-PSK-CCMP+TKIP][ESS]","CXSW:0:-80:[ESS]");
            // get_response_printer_d@ata(0x07,100,te);
            get_printer_data(0x07,1,"1");
            get_printer_data(0x07,1,"2");
            wifi_wait_animmotion(1);
        }

    }
}

static wifi_list_t create_wifi_list_item(lv_obj_t *parent, lv_align_t align_mode, lv_coord_t x, lv_coord_t y)
{
    wifi_list_t singleList = {0};
    lv_obj_t * listPanel = lv_obj_create(parent);
    lv_obj_set_width(listPanel, 670);
    lv_obj_set_height(listPanel, 60);
    lv_obj_align(listPanel, align_mode, x, y);
    lv_obj_clear_flag(listPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(listPanel, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(listPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(listPanel, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(listPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    singleList.parent = listPanel;

    lv_obj_t * list_text = lv_label_create(listPanel);
    lv_obj_set_width(list_text, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(list_text, LV_SIZE_CONTENT); /// 1
    lv_obj_align(list_text,LV_ALIGN_LEFT_MID,0,0);
    lv_label_set_text(list_text, "");
    lv_obj_set_style_text_color(list_text, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(list_text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(list_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(list_text, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    singleList.wifi_name = list_text;

    // lv_obj_t *list_img3 = lv_img_create(listPanel);
    // lv_obj_set_width(list_img3, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(list_img3, LV_SIZE_CONTENT);    /// 1
    // lv_obj_align(list_img3,LV_ALIGN_RIGHT_MID,-28,0);
    // lv_obj_add_flag(list_img3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_add_flag(list_img3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    // lv_obj_clear_flag(list_img3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_img_set_src(list_img3,&ui_img_state_normal_png);
    // part->wifi_info = list_img3;

    lv_obj_t *list_wifiinfo = lv_label_create(listPanel);
    lv_obj_set_width(list_wifiinfo, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(list_wifiinfo, LV_SIZE_CONTENT);    /// 1
    lv_obj_align_to(list_wifiinfo, list_text, LV_ALIGN_OUT_BOTTOM_LEFT,0,0);
    lv_obj_add_flag(list_wifiinfo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(list_wifiinfo, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(list_wifiinfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_color(list_wifiinfo, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(list_wifiinfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(list_wifiinfo, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(list_wifiinfo, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    singleList.wifi_info = list_wifiinfo;

    lv_obj_t *list_img2 = lv_img_create(listPanel);
    lv_img_set_src(list_img2,&ui_img_state_normal_png);
    lv_obj_set_width(list_img2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(list_img2, LV_SIZE_CONTENT);    /// 1
    lv_obj_add_flag(list_img2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(list_img2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_align_to(list_img2, list_img3, LV_ALIGN_OUT_LEFT_MID,-28,0);
    lv_obj_align(list_img2,LV_ALIGN_RIGHT_MID,-28,0);

    singleList.wifi_logo = list_img2;

    lv_obj_t *list_img1 = lv_img_create(listPanel);
    lv_obj_set_width(list_img1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(list_img1, LV_SIZE_CONTENT);    /// 1
    lv_obj_add_flag(list_img1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(list_img1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(list_img1,&ui_img_state_normal_png);
    lv_obj_align_to(list_img1,list_img2,LV_ALIGN_OUT_LEFT_MID,-28,0);
    singleList.wifi_state = list_img1;

    return singleList;
}

void ui_event_NetworkSettingPanel4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_NetworkInfo, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_NetworkFocusChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED || event_code == LV_EVENT_CLICKED) {
        if(target == ui_NetworkSettingLabel3)
        {
            CrLogI("set the keyboard textarea to name");
            lv_keyboard_set_textarea(ui_NetworkSetting_Keyboard1, target);
        }
        else if(target == ui_NetworkSetting_TextArea1)
        {
            CrLogI("set the keyboard textarea to password");
            lv_keyboard_set_textarea(ui_NetworkSetting_Keyboard1, target);
        }
    }
}

void settings_set_cur_language(int cur_language)
{
    if ( cur_language < 0 || cur_language > MAX_LANGUAGE - 1)
        return;

    char *lang = language_get_cur_language_text(cur_language);
    if ( lang )
        lv_dropdown_set_text(ui_SystemsettingDropdown2, lang);
    else
        lv_dropdown_set_text(ui_SystemsettingDropdown2, "");
}

void settings_change_language_text(void)
{
    setting_screen_change_language_text();
    language_change_language_text();
    cameralist_change_language_text();
    camera_settigns_change_language_text();
    about_device_change_language_text();
    reset_machine_change_language_text();
    device_bind_change_language_text();
    touch_tone_change_language_text();
    update_version_change_language_text();
    export_log_change_language_text();
    manual_test_change_language_text();
    network_info_change_language_text();
}

void setting_screen_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    char buff[150] = {0};
    
    if ( ui_SystemsettingTitle )
        lv_label_set_text(ui_SystemsettingTitle, SystemArray[language_index]);
    
    if ( ui_NetworksettingTitle )
    lv_label_set_text(ui_NetworksettingTitle, NetworkArray[language_index]);
    
    if ( ui_CamerasettingTitle )
        lv_label_set_text(ui_CamerasettingTitle, CameraArray[language_index]);
    
    if ( ui_SystemsettingLabel1 )
        lv_label_set_text(ui_SystemsettingLabel1, ScreenBrightnessArray[language_index]);
    
    if ( ui_SystemsettingLabel2 )
        lv_label_set_text(ui_SystemsettingLabel2, ScreenOffArray[language_index]);

    if ( ui_SystemsettingDropdown1 )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "3%s\n5%s\n%s", MinuteArray[language_index], MinuteArray[language_index], NotSetArray[language_index]);

        uint8_t id = lv_dropdown_get_selected(ui_SystemsettingDropdown1);
        lv_dropdown_clear_options(ui_SystemsettingDropdown1);
        lv_dropdown_set_options(ui_SystemsettingDropdown1, buff);
        lv_dropdown_set_selected(ui_SystemsettingDropdown1, id);
    }
    
    if ( ui_SystemsettingLabel4 )
        lv_label_set_text(ui_SystemsettingLabel4, LanguageSelection[language_index]);

    if ( ui_SystemsettingLabel5 )
    {
        lv_label_set_text(ui_SystemsettingLabel5, TimeZoneArray[language_index]);
    }

    // if ( ui_SystemsettingLabel6 )
    //     lv_label_set_text(ui_SystemsettingLabel6, TouchToneArray[language_index]);

    if ( ui_SystemsettingLabel7 )
        lv_label_set_text(ui_SystemsettingLabel7, TopicArray[language_index]);

    if ( ui_SystemsettingDropdown3 )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s1\n%s2\n%s3", TopicArray[language_index], TopicArray[language_index], TopicArray[language_index]);
        uint8_t id = lv_dropdown_get_selected(ui_SystemsettingDropdown3);
        lv_dropdown_clear_options(ui_SystemsettingDropdown3);
        lv_dropdown_set_options(ui_SystemsettingDropdown3, buff);
        lv_dropdown_set_selected(ui_SystemsettingDropdown3, id);
    }


    if ( ui_SystemsettingLabel8 )
        lv_label_set_text(ui_SystemsettingLabel8, BindDevice[language_index]);

    if ( ui_SystemsettingLabel9 )
        lv_label_set_text(ui_SystemsettingLabel9, ExportLogArray[language_index]);

    if ( ui_SystemsettingLabel10 )
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", VersionArray[language_index], Detection[language_index]);
        lv_label_set_text(ui_SystemsettingLabel10, VersionArray[language_index]);
    }

    if ( ui_SystemsettingLabel11 )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s", screen_ver_value);
        lv_label_set_text(ui_SystemsettingLabel11, buff);
    }

    if ( ui_SystemsettingLabel12 )
        lv_label_set_text(ui_SystemsettingLabel12, ResetMachine[language_index]);

    if ( ui_SystemsettingLabel13 )
        lv_label_set_text(ui_SystemsettingLabel13, AboutDevice[language_index]);

    if ( ui_SystemsettingLabel14 )
        lv_label_set_text(ui_SystemsettingLabel14, DeviceSelfTestArray[language_index]);
    if ( ui_SystemsettingLabel14 )
        lv_label_set_text(ui_SystemsettingLabel16, RootInfoTips[language_index]);

    if( ui_SystemsettingLabel15 )
        lv_label_set_text(ui_SystemsettingLabel15, UpdateReminder[language_index]);

    if ( ui_NetworkSettingLabel1 )
        lv_label_set_text(ui_NetworkSettingLabel1, LocalNetworkArray[language_index]);

    if ( ui_NetworkSettingLabel2 )
        lv_label_set_text(ui_NetworkSettingLabel2, UnConnectedArray[language_index]);

    if( ui_NetworkSettingLabel3 )
        lv_textarea_set_placeholder_text(ui_NetworkSettingLabel3, Wifiname[language_index]);

    if ( ui_NetworkSetting_TextArea1 )
        lv_textarea_set_placeholder_text(ui_NetworkSetting_TextArea1, InputPasswordMsg[language_index]);

    if ( ui_NetworkSettingLabel4 )
        lv_label_set_text(ui_NetworkSettingLabel4, NetworkConnect[language_index]);

    if ( ui_VideoSettingLabel1 )
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", CameraArray[language_index], DisableArray[language_index]);
        // lv_label_set_text(ui_VideoSettingLabel1, buff);
    }

    if ( ui_VideoSettingLabel2 )
        lv_label_set_text(ui_VideoSettingLabel2, VedioList[language_index]);

    if ( ui_VideoSettingLabel3 )
    {
        lv_label_set_text(ui_VideoSettingLabel3, CameraSetting[language_index]);
    }

    if ( ui_VideoSettingLabel4 )
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "AI%s", Detection[language_index]);
        lv_label_set_text(ui_VideoSettingLabel4, AIFunction[language_index]);
    }

    if ( ui_NetworkDialog_btn_2_label )
        lv_label_set_text(ui_NetworkDialog_btn_2_label, ForgetPasswordArray[language_index]);

}

void ui_event_wifiipinfogDialog(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_obj_add_flag(ui_wifiipinfogDialog, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    }
}

static void ipinfo_dialog(lv_obj_t * obj)
{
    uint8_t language_index = get_cur_language_index();
    if (ui_wifiipinfogDialog == NULL)
    {
        ui_wifiipinfogDialog = lv_obj_create(lv_layer_top());
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_size(ui_wifiipinfogDialog, 800, 480);
        lv_obj_add_style(ui_wifiipinfogDialog, &style_cont_msgbox, LV_PART_MAIN|LV_STATE_DEFAULT);
        ui_InfoDialog_label = lv_label_create(ui_wifiipinfogDialog);
        lv_obj_set_size(ui_InfoDialog_label, 308, 86);
        lv_obj_align_to(ui_InfoDialog_label,obj,LV_ALIGN_OUT_LEFT_BOTTOM,0,108);
        lv_label_set_text(ui_InfoDialog_label,"");
        lv_obj_set_style_bg_color(ui_InfoDialog_label,lv_color_hex(0x3c3e42), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_InfoDialog_label,255,LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(ui_InfoDialog_label, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

        //label_1
        ui_InfoDialog_label_1 = lv_label_create(ui_InfoDialog_label);
        lv_obj_set_width(ui_InfoDialog_label_1, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_InfoDialog_label_1, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_style_text_color(ui_InfoDialog_label_1, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_InfoDialog_label_1, lv_font24.font, LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_InfoDialog_label_1, 0, LV_STATE_DEFAULT);
        lv_obj_align(ui_InfoDialog_label_1, LV_ALIGN_TOP_MID, 0, 8);
        lv_label_set_text(ui_InfoDialog_label_1,"IP:");

        //label_2
        ui_InfoDialog_label_2 = lv_label_create(ui_InfoDialog_label);
        lv_obj_set_width(ui_InfoDialog_label_2, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_InfoDialog_label_2, LV_SIZE_CONTENT);    /// 1
        lv_label_set_text(ui_InfoDialog_label_2, "MAC:");
        lv_obj_set_style_text_color(ui_InfoDialog_label_2, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_InfoDialog_label_2, lv_font24.font, LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_InfoDialog_label_2, 0, LV_STATE_DEFAULT);
        lv_obj_align(ui_InfoDialog_label_2, LV_ALIGN_BOTTOM_MID, 0, -8);

        lv_obj_add_event_cb(ui_wifiipinfogDialog, ui_event_wifiipinfogDialog, LV_EVENT_ALL, NULL);
    }
    if (lv_obj_has_flag(ui_wifiipinfogDialog,LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(ui_wifiipinfogDialog,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    }
}

void ui_event_wifidialog(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ipinfo_dialog(target);
        //请求ip地址和mac地址
        get_printer_data(0x07,1,"1");
    }
}

void refresh_wifilist_page(char * wifi_ip,char * wifi_mac)
{
    if(wifi_ip != NULL)
    {
        CrLogI("refresh the wifi ip:%s", wifi_ip);
        for(int i = 0; i < WIFI_MAX_NUMBER; i++)
        {
            if(list_array[i].wifi_type == 2)//属于已连接wifi
            {
                lv_label_set_text(list_array[i].wifi_info,wifi_ip);
                break;
            }
        }
        for(int i = 0; i < WIFI_MAX_NUMBER; i++)
        {
            if(selftestwifilist_array[i].wifi_type == 2)
            {
                lv_label_set_text(selftestwifilist_array[i].wifi_info,wifi_ip);
                break;
            }
        }
    }
}

void set_versioninfo_settingpage(char * version_info)
{
    if(version_info != NULL)
    {
        char temp[30] = {0};
        snprintf(temp,30,"V%s",version_info);
        lv_label_set_text(ui_SystemsettingLabel11,temp);
    }
}

void refresh_light_value(int lightvalue)
{
    CrLogI("refresh light setting page,lightvalue is %d",lightvalue);
    if(lightvalue < 10)
    {
        lightvalue = 10;
        char temp[5] = {0};
        snprintf(temp,5,"e%d",lightvalue);
        set_printer_data(0x06,strlen(temp),temp);
    }
    if(lightvalue == 10)
    {
        lv_obj_set_style_bg_img_src(ui_SystemlightDown, &ui_img_down_grey_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if(lightvalue > 100)
    {
        lightvalue = 100;
        char temp[5] = {0};
        snprintf(temp,5,"e%d",lightvalue);
        set_printer_data(0x06,strlen(temp),temp);
    }
    if(lightvalue == 100)
    {
        lv_obj_set_style_bg_img_src(ui_SystemlightUp, &ui_img_up_grey_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if(lightvalue < 100 && lightvalue > 10)
    {
        lv_obj_set_style_bg_img_src(ui_SystemlightUp, &ui_img_up_white_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_img_src(ui_SystemlightDown, &ui_img_down_white_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

void refresh_screenoff_setting(int option)
{
    if(ui_SystemsettingDropdown1 != NULL)
    {
        switch (option)
        {
            case 0:lv_dropdown_set_selected(ui_SystemsettingDropdown1, 2);break;
            case 3:lv_dropdown_set_selected(ui_SystemsettingDropdown1, 0);break;
            case 5:lv_dropdown_set_selected(ui_SystemsettingDropdown1, 1);break;
            default:lv_dropdown_set_selected(ui_SystemsettingDropdown1, 0);break;
        }
    }
}

void refresh_versioninfo(bool show)
{
    systemsettingflag = false;
    if(show)
    {
        CrLogI("find new version");
        lv_obj_clear_flag(ui_SystemsettingLabeltips, LV_OBJ_FLAG_HIDDEN); 
    }
    else
    {
        CrLogI("don't find new version");
        lv_obj_add_flag(ui_SystemsettingLabeltips, LV_OBJ_FLAG_HIDDEN); 
    }
}

void refresh_networkstate(bool connect_state)
{
    if(connect_state)
    {
        lv_label_set_text(ui_NetworkSettingLabel2, ConnectedArray[get_cur_language_index()]);
    }
    else
    {
        lv_label_set_text(ui_NetworkSettingLabel2, UnConnectedArray[get_cur_language_index()]);
    }
}

void refresh_checkupdateflag_state(int state)
{
    if(state)
    {
        if( !lv_obj_has_state(ui_SystemsettingSwitch2, LV_STATE_CHECKED) )
            lv_obj_add_state(ui_SystemsettingSwitch2, LV_STATE_CHECKED);
    }
    else
    {
        if( lv_obj_has_state(ui_SystemsettingSwitch2, LV_STATE_CHECKED) )
            lv_obj_clear_state(ui_SystemsettingSwitch2, LV_STATE_CHECKED);
    }
}
lv_timer_t * timer = NULL;
static int count = 0;
void policyeventHandle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(strcmp(userdata, "2") == 0) //btn2
        {
            lv_obj_t * parent = lv_obj_get_parent(target);
            if(lv_obj_has_state(lv_obj_get_child(parent, 5), LV_STATE_CHECKED))
            {
                char psCmd[256] = {0};
                snprintf(psCmd, 256, "touch %s", GetUserAgreeRootPolicyPath());
                system(psCmd);
                #ifdef CROSS_COMPILE
                system("/etc/init.d/S50dropbear restart");
                #endif

                create_rootinfo_message("root","creality_2023","30");
                //删除弹窗
                lv_obj_del(lv_obj_get_parent(target));
            }
        }
        else
        {
            if(timer != NULL)
            {
                lv_timer_del(timer);
                timer = NULL;
            }
            //删除弹窗
            lv_obj_del(lv_obj_get_parent(target));
        }
    }
}

void timerHandle(lv_timer_t * e)
{
    CrLogI("timer count");
    lv_obj_t * userdata = e->user_data;
    if (count >= 30) {
        lv_timer_del(timer);
        timer = NULL;
        lv_obj_add_flag(lv_obj_get_parent(userdata), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_bg_opa(lv_obj_get_parent(userdata), 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(userdata, Confirm[get_cur_language_index()]);
    }
    else
    {
        count++;
        char temp[256] = {0};
        snprintf(temp, 256, "%s(%ds)", Confirm[get_cur_language_index()], 30-count);
        lv_label_set_text(userdata, temp);
    }
}

//创建root用户政策页面
void create_rootpolicy_page()
{
    uint8_t language_index = get_cur_language_index();
    lv_obj_t * policyBg = lv_obj_create(lv_scr_act());
    lv_obj_set_width(policyBg, 800);
    lv_obj_set_height(policyBg, 480);
    lv_obj_clear_flag(policyBg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(policyBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(policyBg, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(policyBg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(policyBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(policyBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * policyTitle = lv_label_create(policyBg);
    lv_obj_set_width(policyTitle, 600);
    lv_obj_set_height(policyTitle, 34);
    lv_obj_set_x(policyTitle, 0);
    lv_obj_set_y(policyTitle, 20);
    lv_obj_set_align(policyTitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(policyTitle, Warning[language_index]);
    lv_obj_set_style_text_color(policyTitle, lv_color_hex(0xFF9B2F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(policyTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(policyTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(policyTitle, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * policyButton1 = lv_btn_create(policyBg);
    lv_obj_set_width(policyButton1, 146);
    lv_obj_set_height(policyButton1, 60);
    lv_obj_set_x(policyButton1, 196);
    lv_obj_set_y(policyButton1, 400);
    lv_obj_add_flag(policyButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(policyButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(policyButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(policyButton1, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(policyButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(policyButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(policyButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * policyBtnlabel1 = lv_label_create(policyButton1);
    lv_obj_set_width(policyBtnlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(policyBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(policyBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(policyBtnlabel1, Back[language_index]);
    lv_obj_set_style_text_color(policyBtnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(policyBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(policyBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * policyButton2 = lv_btn_create(policyBg);
    lv_obj_set_width(policyButton2, 146);
    lv_obj_set_height(policyButton2, 60);
    lv_obj_set_x(policyButton2, 459);
    lv_obj_set_y(policyButton2, 400);
    lv_obj_add_flag(policyButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(policyButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(policyButton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(policyButton2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(policyButton2, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(policyButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(policyButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * policyBtnlabel2 = lv_label_create(policyButton2);
    lv_obj_set_width(policyBtnlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(policyBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(policyBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(policyBtnlabel2, Confirm[language_index]);
    lv_obj_set_style_text_color(policyBtnlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(policyBtnlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(policyBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //初始化按钮
    char temp[256] = {0};
    snprintf(temp, 256, "%s(%ds)", Confirm[language_index], 30);
    lv_label_set_text(policyBtnlabel2, temp);
    lv_obj_clear_flag(policyButton2, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_t * policyTextPanel = lv_obj_create(policyBg);
    lv_obj_set_width(policyTextPanel, 687);
    lv_obj_set_height(policyTextPanel, 289);
    lv_obj_set_x(policyTextPanel, 0);
    lv_obj_set_y(policyTextPanel, 96);
    lv_obj_set_align(policyTextPanel, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(policyTextPanel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_radius(policyTextPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(policyTextPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(policyTextPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(policyTextPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(policyTextPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * policyTextlabel = lv_label_create(policyTextPanel);
    lv_obj_add_flag(policyTextlabel, LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_width(policyTextlabel, 687);   /// 1
    lv_obj_set_height(policyTextlabel, LV_SIZE_CONTENT);    /// 1
    lv_label_set_long_mode(policyTextlabel, LV_LABEL_LONG_WRAP);
    lv_label_set_text(policyTextlabel, RootPolicyContent[language_index]);
    lv_obj_set_style_text_color(policyTextlabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(policyTextlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(policyTextlabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(policyTextlabel, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * policyTextMask = lv_img_create(policyBg);
    lv_img_set_src(policyTextMask, &ui_img_mask2_png);
    lv_obj_set_width(policyTextMask, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(policyTextMask, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(policyTextMask, 0);
    lv_obj_set_y(policyTextMask, 270);
    lv_obj_set_align(policyTextMask, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(policyTextMask, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(policyTextMask, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * policyCheckbox1 = lv_checkbox_create(policyBg);
    lv_obj_set_width(policyCheckbox1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(policyCheckbox1, LV_SIZE_CONTENT);    /// 1
    lv_checkbox_set_text(policyCheckbox1, AgreeRootPolicy[language_index]);
    lv_obj_align(policyCheckbox1, LV_ALIGN_TOP_MID, 0, 343);
    lv_obj_add_flag(policyCheckbox1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(policyCheckbox1, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(policyCheckbox1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(policyCheckbox1, lv_font24.font,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(policyCheckbox1, 6, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(policyCheckbox1, lv_color_hex(0x42BDD8),
                              LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(policyCheckbox1, lv_color_hex(0x42BDD8),
                              LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(policyCheckbox1, 6, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(policyCheckbox1, lv_color_hex(0x42BDD8),
                                  LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(policyCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(policyCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    timer = lv_timer_create(timerHandle, 1000 * 1, policyBtnlabel2);
    count = 0;
    lv_obj_add_event_cb(policyButton1, policyeventHandle, LV_EVENT_ALL, "1");
    lv_obj_add_event_cb(policyButton2, policyeventHandle, LV_EVENT_ALL, "2");
}

void rootinfo_event_handle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_obj_t * parent = lv_obj_get_parent(target);
        //跳回首页
        if ( home_printing_is_printing_finished() )
            LoadHomeNormalScreen();
        else
            LoadHomePrintingScreen();

        //删除弹窗
        lv_obj_del(lv_obj_get_parent(parent));
        CrLogI("delete the rootinfo msgbox success");
    }
}

void create_rootinfo_message(char *username, char *password, char *atLeastTime)
{
    uint8_t language_index = get_cur_language_index();
    lv_obj_t * rootinfoBg = lv_obj_create(lv_scr_act());
    lv_obj_set_width(rootinfoBg, 800);
    lv_obj_set_height(rootinfoBg, 480);
    lv_obj_clear_flag(rootinfoBg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(rootinfoBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(rootinfoBg, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(rootinfoBg, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(rootinfoBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(rootinfoBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * rootinfo = lv_obj_create(rootinfoBg);
    lv_obj_set_width(rootinfo, 418);
    lv_obj_set_height(rootinfo, 300);
    lv_obj_set_x(rootinfo, 191);
    lv_obj_set_y(rootinfo, 79);
    lv_obj_clear_flag(rootinfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(rootinfo, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(rootinfo, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(rootinfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(rootinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(rootinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(rootinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(rootinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(rootinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * usernamelabel = lv_label_create(rootinfo);
    lv_obj_set_width(usernamelabel, 349);   /// 1
    lv_obj_set_height(usernamelabel, 38);    /// 1
    lv_obj_set_x(usernamelabel, 0);
    lv_obj_set_y(usernamelabel, 66);
    lv_obj_set_align(usernamelabel, LV_ALIGN_TOP_MID);
    lv_label_set_long_mode(usernamelabel, LV_LABEL_LONG_SCROLL);
    char tempbuffa[256] = {0};
    snprintf(tempbuffa, 256, "%s:%s", Account[language_index], username);
    lv_label_set_text(usernamelabel, tempbuffa);
    lv_obj_set_style_text_color(usernamelabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(usernamelabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(usernamelabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(usernamelabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * passwordlabel = lv_label_create(rootinfo);
    lv_obj_set_width(passwordlabel, 349);
    lv_obj_set_height(passwordlabel, 38);
    lv_obj_align(passwordlabel, LV_ALIGN_TOP_MID, 0, 113);
    char tempbuffb[256] = {0};
    snprintf(tempbuffb, 256, "%s:%s", PassWord[language_index], password);
    lv_label_set_text(passwordlabel, tempbuffb);
    lv_obj_set_style_text_color(passwordlabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(passwordlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(passwordlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(passwordlabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * btn1 = lv_btn_create(rootinfo);
    lv_obj_set_width(btn1, 146);
    lv_obj_set_height(btn1, 60);
    lv_obj_align(btn1, LV_ALIGN_TOP_MID, 0, 220);
    lv_obj_add_flag(btn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(btn1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(btn1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(btn1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(btn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(btn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * btn1label = lv_label_create(btn1);
    lv_obj_set_width(btn1label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(btn1label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(btn1label, LV_ALIGN_CENTER);
    lv_label_set_text(btn1label, Confirm[language_index]);
    lv_obj_set_style_text_color(btn1label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(btn1label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(btn1label, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(btn1, rootinfo_event_handle, LV_EVENT_ALL, NULL);
    CrLogI("create rootinfo msgbox success");
}

void HasRootFile()
{
    //判断是否有root同意后的创建文件
    if (access(GetUserAgreeRootPolicyPath(), F_OK) == 0) {
        CrLogI("has rootagree file, start the S50dropbear server");
        #ifdef CROSS_COMPILE
        system("/etc/init.d/S50dropbear restart");
        #endif
    }
}
