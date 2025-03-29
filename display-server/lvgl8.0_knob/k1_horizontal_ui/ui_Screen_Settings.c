/*
 * @Description: 
 * @Author: sunhui
 * @Date: 2023-07-10 04:05:15
 * @LastEditTime: 2023-11-04 03:59:42
 */

#include "src/misc/lv_area.h"
#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "./custom/CrlogDef.h"
#include "ui_screen_CameraList.h"
#include "custom/lvgl_cmd.h"
#include "ui_screen_camera_settings.h"
#include "ui_Screen_CustomerService.h"
#include "mult_language.h"
#include "ui_custom_messagebox.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "page_switch.h"
#include "ui_screen_DetectionAI.h"

lv_obj_t * ui_ScreenSettings;
static lv_obj_t * ui_SettingTitleLabel;
static lv_obj_t * ui_DeviceIconPanel;
/******************settings left panel***********************************/
static lv_obj_t * ui_PanelPageSettings;
static lv_obj_t * ui_ButtonHomePage; 
static lv_obj_t * ui_ImageHomePage; 
static lv_obj_t * ui_ImageAxisMove;
static lv_obj_t * ui_ButtonAxisMove;
static lv_obj_t * ui_ButtonFIleManage;
static lv_obj_t * ui_ButtonSettings;
static lv_obj_t * ui_ButtonReserve;
static lv_obj_t * ui_ImageFIleManage;
static lv_obj_t * ui_ImageSettings;
static lv_obj_t * ui_ImageReserve;

/******************settings top panel image*****************************/
static lv_obj_t * ui_ImageWifiNormal;
static lv_obj_t * ui_ImageCamerastate;
static lv_obj_t * ui_ImageLaserState;

/******************settings right panel***********************************/
static lv_obj_t * ui_SettingsItemMainPanel; //设置页主面板
static lv_obj_t * ui_SettingTitlePanel; //设置页顶层标题面板
static lv_obj_t * ui_SettingsPanelList; //设置页设置项列表

static lv_obj_t * ui_BrightnessPanel; //屏幕亮度设置
static lv_obj_t * ui_BrightnessLabel;
static lv_obj_t * ui_BrightnessValLabel;
static lv_obj_t * ui_BrightnessValSetLabel;

static lv_obj_t * ui_ScreenOffPanel; //熄屏
static lv_obj_t * ui_ScreenOffLabel;
static lv_obj_t * ui_ScreenOffTimeLabel;
static uint8_t ui_ScreenOffTimeIndex = 0;

lv_obj_t * ui_LanguageSelectPanel; //语言选择
static lv_obj_t * ui_LanguageSelectLabel;
static lv_obj_t * ui_LanguagesLabel;//语种
static lv_obj_t * ui_DeviceSelfTestPanel; //设备自检
static lv_obj_t * ui_DeviceSelfTestLabel;

static lv_obj_t * ui_TimeZoneSetPanel; //时区设置
lv_obj_t * ui_TimeZoneSetLabel;

/********************网络设置界面*********************/
static lv_obj_t * ui_NetworkSetPanel; //网络设置
static lv_obj_t * ui_NetworkSetLabel;
static lv_obj_t * ui_NetworkSettingsPanel; //网络设置子页面板 
static lv_obj_t * ui_LocalNetworkPanel; //本地网络面板
static lv_obj_t * ui_NetworkListPanel;
static lv_obj_t * ui_CurConnectedWiFiPanel;
static lv_obj_t * ui_NetworkPanelLine;
static lv_obj_t * ui_NetworksettingTitle;
static lv_obj_t * ui_NetworkSetBackBtn;
static lv_obj_t * ui_LoclNetworkImage;
static lv_obj_t * ui_LoclNetworkArrowImage;
lv_obj_t * ui_NetworkSettingPanel; 
static lv_obj_t * ui_NetworkKeyboardPanel; 
static lv_obj_t * ui_NetworkName; 
lv_obj_t * ui_NetworkPassw_TextArea;
lv_obj_t * ui_NetworkSetting_Keyboard;
//static lv_obj_t * ImageCloseNetworkKeyboard;
static lv_obj_t * ui_NetworkSettingLabel1;
static lv_obj_t * ui_NetworkSettingLabel2;
lv_obj_t * ui_NetworkName_TextArea;
static lv_obj_t * ui_NetworkDialog;
static lv_obj_t * ui_NetworkDialogPanel;
static lv_obj_t * ui_NetworkDialog_btn_1;
static lv_obj_t * ui_NetworkDialog_btn_1_label;
static lv_obj_t * ui_NetworkDialog_btn_2;
static lv_obj_t * ui_NetworkDialog_btn_2_label; 
static lv_obj_t * ui_NetworkDialog_btn_3;
static lv_obj_t * ui_NetworkDialog_btn_3_label; //取消
static lv_obj_t * ui_wifiipinfogDialog;
static lv_obj_t * ui_InfoDialog_label;
static lv_obj_t * ui_InfoDialog_label_1;
static lv_obj_t * ui_InfoDialog_label_2;
/********************网络设置界面*********************/

/********************摄像头界面*********************/
static lv_obj_t * ui_CameraItemPanel;  //摄像头设置
static lv_obj_t * ui_CameraLabel;
static lv_obj_t * ui_CameraSettingSupanel; //摄像头子页面板
static lv_obj_t * ui_CameraTitleLabel; //摄像头子页面标题
static lv_obj_t * ui_CameraSubpanelLine;
static lv_obj_t * ui_CameraSubpaneBackBtn;

static lv_obj_t * ui_VideoListPanel; //视频列表面板
static lv_obj_t * ui_CameraSettingPanel;
static lv_obj_t * ui_AIDetectPanel;

static lv_obj_t * ui_VideoSettingImage7;
static lv_obj_t * ui_VideoSettingLabel2;
static lv_obj_t * ui_VideoSettingImage8;
static lv_obj_t * ui_VideoSettingImage9;
static lv_obj_t * ui_VideoSettingLabel3;
static lv_obj_t * ui_VideoSettingImage10;

static lv_obj_t * ui_VideoSettingImage11;
static lv_obj_t * ui_VideoSettingLabel4;
static lv_obj_t * ui_VideoSettingImage12;
/********************摄像头界面*********************/

/********************绑定创想云界面*********************/
static lv_obj_t * ui_BindDevicePanel;  //绑定创想云
static lv_obj_t * ui_BindDeviceLabel;
static lv_obj_t * ui_DevicebindingPanel; //绑定创想云子页面板
static lv_obj_t * ui_BindDeviceTitleLabel; //绑定创想云子页标题
static lv_obj_t * ui_DevicebindingLabel;  //请使用创想云APP扫码绑定设备label
static lv_obj_t * ui_BindDevicePanelLine;
static lv_obj_t * ui_BindDeviceBackBtn;
static lv_obj_t * ui_DevicebindingQRCodeImage; //二维码
static lv_obj_t * ui_ServerSelectPanel; 
static lv_obj_t * ui_DevicebindingAreaLabel;
static lv_obj_t * ui_ServerSelectedLabel; 
static lv_obj_t * ui_BindQrCodeGetFailLabel;
static lv_obj_t * ui_DeviceBoundPanel;
static lv_obj_t * ui_BoundUserimgPanel;
static lv_obj_t * ui_DeviceBoundUserimg;
static lv_obj_t * ui_DeviceBoundUsername;
static lv_obj_t * ui_DeviceBoundUserid;
static lv_obj_t * ui_BoundUserLogOutBtn;
static lv_obj_t * ui_BoundUserLogOutBtnLabel;
static uint8_t ServerSelectIndex = 0;
/********************绑定创想云界面*********************/

// 更新提醒
static lv_obj_t * ui_UpdateReminderPanel; 
static lv_obj_t * ui_UpdateReminderLabel; 
static lv_obj_t * ui_SwitchUpdateReminder;
// 版本检测
lv_obj_t * ui_VersionDetectPanel; 
lv_obj_t * ui_VersionDetectLabel;
lv_obj_t * ui_VersionLabel;
lv_obj_t * ui_SystemsettingLabeltips; /*红色升级提示圆点*/
// 恢复出厂
lv_obj_t * ui_ResetMachinePanel; 
lv_obj_t * ui_ResetMachineLabel;
// 关于本机
lv_obj_t * ui_AboutDevicePanel; 
lv_obj_t * ui_AboutDeviceLabel;
// 全屏开关
lv_obj_t * ui_SystemsettingLabel3;
lv_obj_t * ui_SystemsettingSwitch1; 
//lv_obj_t * ui_SystemlightUpImage;
// 按键音
lv_obj_t * ui_SystemsettingLabel6; 
lv_obj_t * ui_SystemsettingPanel6;
// 主题
lv_obj_t * ui_SystemsettingLabel7; 
lv_obj_t * ui_SystemsettingDropdown3;

lv_style_t StyleDialogBtn; //对话按钮框样式
lv_style_t StyleDialogFocusBtn;
lv_style_t Style2DialogBtn; //对话按钮框样式2
lv_style_t Style2DialogFocusBtn;
lv_style_t StyleDialogBtnDefault;

/**************未启用的控件变量****************/
lv_obj_t * ui_VideoSetting;
lv_obj_t * ui_VideoSettingPanel1;
lv_obj_t * ui_VideoSettingImage1;
lv_obj_t * ui_VideoSettingImage2;
lv_obj_t * ui_VideoSettingImage3;
lv_obj_t * ui_VideoSettingImage4;
lv_obj_t * ui_VideoSettingImage5;

///////////////////// VARIABLES ////////////////////
EventGrop_Data ScreenSettings;
static DialogMsgbox_t ScreenOffMessage; //熄屏对话框
static DialogMsgbox_t ServerSelectMessage; //服务器环境选择对话框
static DialogMsgbox_t PrivacyPolicyMessage; //隐私政策提示对话框

lv_obj_t * wifilist_btn;
char wifilist_name[64];         //用于弹出窗口做数据交换和判断的数据
unsigned char wifilist_state;   
wifi_list_t list_array[WIFI_MAX_NUMBER] = {0};
settings_list_t *settings_array[13] = {NULL};

char Manualtest[12];
char Manualtestlength;
char Manualtest_curpage;
bool systemsettingflag = false;
static bool refresh_camera_flag = true;
static uint8_t SettingsItemIndex;
static int wifi_Intensity = 0;
static bool wifiListRefreshTimesFlag = false; //获取wifi 列表后只刷新一次，防止多次刷新影响编码器事件组的多次建立
static uint8_t wifiListCount = 0;
///////////////////// VARIABLES ////////////////////
bool GetSettingsScreenStatusVal(void);
static char *ScreenOffListLabelSet(uint8_t item_index, uint8_t language_index);
static void ScreenOffTimeSelect(uint8_t item_index);
static void SettingsGroupObjsAddLevel0(void);

static void ui_event_ButtonHomePage(lv_event_t * e);
void ui_event_ButtonAxisMove(lv_event_t * e);
void ui_event_ButtonFIleManage(lv_event_t * e);
void ui_event_ButtonSettings(lv_event_t * e);
void ui_event_ButtonReserve(lv_event_t * e);

void ui_event_VideoListPanel(lv_event_t * e);
void ui_event_CameraSettingPanel(lv_event_t * e);
void ui_event_AIDetectPanel(lv_event_t * e);

void ui_event_SystemsettingLabel9(lv_event_t * e);

void ui_event_SystemsettingPanel5(lv_event_t * e);
void ui_event_SystemsettingDropdown1(lv_event_t * e);
void ui_event_SystemsettingSlider1(lv_event_t * e);
void ui_event_SystemsettingSwitch1(lv_event_t * e);
void ui_event_NetworkSetting_Keyboard(lv_event_t * e);
void set_wifi_list_status(lv_obj_t * obj, int intensity);
void ui_event_CloseNetworkKeyboard(lv_event_t * e);
void ui_event_LocalNetworkSettingPanel(lv_event_t * e);
void ui_event_wifidialog(lv_event_t * e);

void ui_event_Pageload(lv_event_t * e);
void ui_event_SettingTitlePrePage(lv_event_t * e);
static settings_list_t *create_settings_list_item(lv_obj_t *parent, uint8_t index, int16_t pos_x, int16_t pos_y, void (*part_event_callback)(lv_event_t *));
static wifi_list_t create_wifi_list_item(lv_obj_t *parent, lv_align_t align_mode, lv_coord_t x, lv_coord_t y);
static void setting_screen_change_language_text(void);
static void ScreenOffTimePageAddFocusObjs(void);
static void NetworkPageChangeObjs(void);
static void NetworkPageAaaFocusObjs(void);
static void NetworkListUpdateFocusObjs(uint8_t index);
static void DeviceBindPageAddFocusObjs(void);
static void DeviceBindPrivacyPolicyAddFocusObjs(void);
static void ServerSelectPageAddFocusObjs(void);
static void CameraSetPageAddFocusObjs(void);
static void ui_event_NetworkFocusChange(lv_event_t * e);

typedef void (*SettingsAdd3rdObjsCb)(void);  //添加三级导航对象
static SettingsAdd3rdObjsCb Add3rLeveldObjsCb = NULL;


#define LV_KB_BTN(width) width//LV_BTNMATRIX_CTRL_POPOVER | width

static const char * const kb_map_lc[] = {"q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "\n",
                                        " ", "a", "s", "d", "f", "g", "h", "j", "k", "l", " ", "\n",
                                        "flag1", "z", "x", "c", "v", "b", "n", "m", "flag3", "\n",
                                        "123", " ", "Ender", ""
                                        };

static const char * const kb_map_uc[] = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "\n",
                                        " ", "A", "S", "D", "F", "G", "H", "J", "K", "L", " ", "\n",
                                        "flag2", "Z", "X", "C", "V", "B", "N", "M", "flag3", "\n",
                                        "123", " ", "Ender", ""
                                        };
                                
static const char * const kb_map_num_spec[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n",
                                            " ", "-", "/", ":", ";", "(", ")", "$", "&", "@", " ", "\n",
                                            "#+=",  "\"", ".", ",", "?", "!", "'", "·", "flag3", "\n",
                                            "ABC", " ", "Ender", ""
                                          };

static const char * const kb_map_spec[] = {"[", "]", "{", "}", "#", "%", "^", "*", "+", "=", "\n",
                                            " ", "_", "\\", "|", "~", "<", ">", "€", "£", "¥", " ", "\n",
                                            "123",  "\"", ".", ",", "?", "!", "'", "·", "flag3", "\n",
                                            "ABC", " ", "Ender", ""
                                          };

static const lv_btnmatrix_ctrl_t default_kb_ctrl_map[] = {
    LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), 
    LV_BTNMATRIX_CTRL_DISABLED | 1, LV_KB_BTN(2), LV_KB_BTN(2), LV_KB_BTN(2), LV_KB_BTN(2), LV_KB_BTN(2), LV_KB_BTN(2), LV_KB_BTN(2), LV_KB_BTN(2), LV_KB_BTN(2), LV_BTNMATRIX_CTRL_DISABLED | 1, 
    LV_KB_BTN(2), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(1), LV_KB_BTN(2), 
    LV_KB_BTN(2), LV_KB_BTN(2), LV_KB_BTN(2)
};


const char * * kb_map[4] = {
    (const char * *)kb_map_lc,
    (const char * *)kb_map_uc,
    (const char * *)kb_map_num_spec,
    (const char * *)kb_map_spec
    // (const char * *)default_kb_map_num,
    // (const char * *)default_kb_map_lc,
    // (const char * *)default_kb_map_lc,
    // (const char * *)default_kb_map_lc,
    // (const char * *)default_kb_map_lc,
    // (const char * *)NULL,
};

const lv_btnmatrix_ctrl_t * kb_ctrl[2] = {
    default_kb_ctrl_map,
    // default_kb_ctrl_lc_map,
    // default_kb_ctrl_uc_map,
   // default_kb_ctrl_spec_map,
    // default_kb_ctrl_num_map,
    // default_kb_ctrl_lc_map,
    // default_kb_ctrl_lc_map,
    // default_kb_ctrl_lc_map,
    // default_kb_ctrl_lc_map,
    NULL,
};

bool keyboard_spec_flag = false;

///////////////////// FUNCTIONS ////////////////////
// 屏幕亮度设置Label替换--(编辑label和默认面板显示label)
static void ScreenBrightnessSet(uint8_t flag, char *val)
{
    if (flag){
        lv_obj_add_flag(ui_BrightnessValLabel, LV_OBJ_FLAG_HIDDEN); //设置亮度时隐藏掉默认显示的label
        lv_obj_clear_flag(ui_BrightnessValSetLabel, LV_OBJ_FLAG_HIDDEN);      
    }
    else {
        lv_label_set_text(ui_BrightnessValLabel, val);
        lv_obj_clear_flag(ui_BrightnessValLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_BrightnessValSetLabel, LV_OBJ_FLAG_HIDDEN);
    }
}
/**
 * @description: 屏幕亮度事件处理
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_BrightnessPanelSet(lv_event_t * e)
{
    uint8_t ret = 0;
    static uint8_t lightvalue;
    char temp[5] = {0};
    char *value_char = NULL;
    lv_event_code_t event_code = lv_event_get_code(e);
   
    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0) {//编辑模式
        ScreenBrightnessSet(true, NULL);
    }
    else if(ret == 1) { //导航模式
        ScreenBrightnessSet(false, value_char);
    }

    value_char = EncoderChangeValue(system_state.light_value, 10, e, 10, 100);
    if (value_char != NULL)
    {
        CrLogI("system_state.light_value:%d\n", system_state.light_value);
     
        snprintf(temp,5,"e%s",value_char);
        set_printer_data(0x06,strlen(temp),temp);

        strcat(value_char, "%");
        lv_label_set_text(ui_BrightnessValSetLabel, value_char);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //
        ScreenBrightnessSet(false, value_char);
    }
}

/**
 * @description: 熄屏事件处理
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_ScreenOffTimeSet(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_SHORT_CLICKED) 
    {
        ShowDialogMessagebox(&ScreenOffMessage, ScreenOffTimePageAddFocusObjs);  
        //Add3rLeveldObjsCb = ScreenOffTimePageAddFocusObjs;
       // ChangeToScreenOffObjs(ui_ScreenOffPanel);
        //LoadPage(ui_ScreenSettings, 3);
        //printf("ShowDialogMessagebox\n");  
    }  
}

/**
 * @description: 语言选择事件处理
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_LanguageSelect(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
     // _ui_screen_change(ui_changelanguage, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
      //language_change_event_grop();
      LoadPage(ui_changelanguage, 0);
      language_set_screen_mode(false);
     
      //set_error_msg(500, 300, "test");
     // set_error_msg(2506, 100, "test");
      
     // ErrorMsgboxAddObjsToGroup();
    }
    // if(event_code == LV_EVENT_READY) {
    //     lv_obj_add_flag(lv_dropdown_get_list(target), LV_OBJ_FLAG_HIDDEN);
    // }
}

/**
 * @description: 设备自检事件处理
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_DeviceSelfTest(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        CrLogI("ui_event_DeviceSelfTest\n");
        LoadPage(ui_Manualtest, 1);
        //_ui_screen_change(ui_Manualtest, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
/**
 * @description: 时区设置
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_TimezoneSettings(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        //printf("ui_event_TimezoneSettings\n");
        LoadPage(ui_TimezoneSettings, 1);
       // _ui_screen_change(ui_TimezoneSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

/**
 * @description: 网络设置
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_NetworkSettings(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        
     
        CrLogI("wifi page init,wait wifi refresh....");
            // char te[100];
            // snprintf(te,100,"%s\t%s\t%s\t%s\t%s","11","CXSW","172.23.208.184","70","2");
            // get_response_printer_data(0x07,30,te);
        // snprintf(te,100,"%s\t%s\t%s","2MW315R:2","CXSW-guest:1","CXSW:0");
            // get_response_printer_data(0x07,30,te);
        get_printer_data(0x07,1,"1");
        get_printer_data(0x07,1,"2");//获取wifi的列表   
        wifi_wait_animmotion(3);
        lv_obj_add_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_HIDDEN); //隐藏设置主页面板
        lv_obj_clear_flag(ui_NetworkSettingsPanel, LV_OBJ_FLAG_HIDDEN); 
        wifiListRefreshTimesFlag = true;
        Add3rLeveldObjsCb = NetworkPageAaaFocusObjs;
        LoadPage(ui_ScreenSettings, 3);
    }
}

/**
 * @description: 网络设置返回按钮
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_NetworkSetBackBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        CrLogI("ui_event_NetworkSetBackBtn\n");
        lv_obj_clear_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(ui_NetworkSettingsPanel, LV_OBJ_FLAG_HIDDEN); 
       // Add3rLeveldObjsCb = NULL;
        wait_animmotion(false);
        LoadSettingsScreenAndObjs(true, NETWORK_SETTING_ITEM);
    }
}

//跳转版本升级页面
void ui_event_EnterUpdatepage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(print_state != 1)
        {
            CrLogI("updateversion page:machine state is print %d,don't start the print",print_state);
            create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
            return;
        }
        if (system_state.CxyUserInfoState != 1)
        {
            CrLogI("don't have cxyuserinfo");
            create_msgbox(DontCXYUserInfo[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
            return;
        }
        wait_animmotion(true);
        EnterUpdatepage(1);
    }
}

/**
 * @description: 摄像头设置
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_CameraItemPanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_obj_add_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_HIDDEN); //隐藏设置主页面板
        lv_obj_clear_flag(ui_CameraSettingSupanel, LV_OBJ_FLAG_HIDDEN); //显示摄像头设置子页
        Add3rLeveldObjsCb = CameraSetPageAddFocusObjs;
        LoadPage(ui_ScreenSettings, 3);

    }
    if (event_code == LV_EVENT_FOCUSED)
    {
        lv_obj_scroll_to_y(ui_SettingsPanelList, 100 , true);
    }
}

/**
 * @description: 摄像头返回页面按钮事件
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_CameraSubpaneBackBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        CrLogI("ui_event_CameraSubpaneBackBtn\n");
        Add3rLeveldObjsCb = NULL;
        BackPrepage(false);
        // LoadPage(ui_ScreenSettings, 2);
        // lv_group_focus_obj(settings_array[8]->part_panel);
        
        lv_obj_clear_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(ui_CameraSettingSupanel, LV_OBJ_FLAG_HIDDEN); 
    }

}

/**
 * @description: 绑定创想云
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_BindDeviceItemPanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_Devicebinding, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        lv_obj_add_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_HIDDEN); //隐藏设置主页面板
        lv_obj_clear_flag(ui_DevicebindingPanel, LV_OBJ_FLAG_HIDDEN); //显示绑定创想云子页
        if(!init_uiconfiginfo.AgreePrivacyPolicy)
        {
            Add3rLeveldObjsCb = DeviceBindPageAddFocusObjs;
            LoadPage(ui_ScreenSettings, 3);
            
            ShowDialogMessagebox(&PrivacyPolicyMessage, DeviceBindPrivacyPolicyAddFocusObjs); 
            lv_obj_add_flag(ui_DeviceBoundPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags 

            //Add3rLeveldObjsCb = DeviceBindPrivacyPolicyAddFocusObjs;
            //LoadPage(ui_ScreenSettings, 3);
        } 
        else
        {
            lv_obj_clear_flag(ui_ServerSelectPanel, LV_OBJ_FLAG_HIDDEN); 
            if (system_state.Mqtt_state) {
                CrLogI("device binding qrcode exist");
                char temp[64] = {0};
                snprintf(temp, 64, "%s %s", GetSystemConfig().device_sn, GetSystemConfig().device_mac);
                lv_qrcode_update(ui_DevicebindingQRCodeImage, temp, strlen(temp));

                lv_obj_clear_flag(ui_DevicebindingLabel, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_BindQrCodeGetFailLabel, LV_OBJ_FLAG_HIDDEN);
                get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态
            }
            else
            {
                CrLogI("device binding qrcode not exist");
                lv_obj_add_flag(ui_DevicebindingLabel, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_BindQrCodeGetFailLabel, LV_OBJ_FLAG_HIDDEN);
            }
            lv_obj_add_flag(ui_DeviceBoundPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags   
            get_printer_data(CONTROL_PARAMETERS, 2, "p");//查询创想云服务器状态
            
            Add3rLeveldObjsCb = DeviceBindPageAddFocusObjs;
            LoadPage(ui_ScreenSettings, 3);
        }
    }
}

/***********************绑定创想云隐私政策处理****************************/
static void PrivacyPolicyPageLeftBtn(void)
{
    
    // lv_obj_clear_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_HIDDEN); 
    // lv_obj_add_flag(ui_DevicebindingPanel, LV_OBJ_FLAG_HIDDEN); 
    // LoadPage(ui_ScreenSettings, 2);
    // lv_group_focus_obj(settings_array[8]->part_panel);
    // LoadSettingsScreenAndObjs(false, 0);
    // LoadSettingsScreenAndObjs(true, 8);
    BackPrepage(false);
    LoadPage(ui_ScreenSettings, 2);
    lv_group_focus_obj(settings_array[8]->part_panel);

    lv_obj_clear_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_HIDDEN); 
    lv_obj_add_flag(ui_DevicebindingPanel, LV_OBJ_FLAG_HIDDEN); 
}

static lv_obj_t * Waittimer = NULL;
static void wait_timerout_handle(lv_timer_t * timer)
{
    static uint8_t time_cnt = 0;
    if (++time_cnt >= 10)
    {
        if (Waittimer)
            lv_timer_del(Waittimer);
    }
    lv_timer_set_repeat_count(Waittimer, 1);
   // printf("Waittimer test.\n");
    if (system_state.Mqtt_state) {
        if (Waittimer)
        {
             lv_timer_del(Waittimer);
        }
        CrLogI("device binding qrcode exist");
         wait_animmotion(false);
        char temp[64] = {0};
        snprintf(temp, 64, "%s %s", GetSystemConfig().device_sn, GetSystemConfig().device_mac);
        lv_qrcode_update(ui_DevicebindingQRCodeImage, temp, strlen(temp));

        lv_obj_clear_flag(ui_DevicebindingLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_BindQrCodeGetFailLabel, LV_OBJ_FLAG_HIDDEN);
        get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态
    }
    // else
    // {
    //     CrLogI("device binding qrcode not exist");
    //     lv_obj_add_flag(ui_DevicebindingLabel, LV_OBJ_FLAG_HIDDEN);
    //     lv_obj_add_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_HIDDEN);
    //     lv_obj_clear_flag(ui_BindQrCodeGetFailLabel, LV_OBJ_FLAG_HIDDEN);
    // }
    // lv_obj_add_flag(ui_DeviceBoundPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags   
    get_printer_data(CONTROL_PARAMETERS, 2, "p");//查询创想云服务器状态

}

static void PrivacyPolicyPageRighBtn(void)
{
    set_printer_data(CONTROL_PARAMETERS, 3, "q1"); //同意隐私政策命令
    get_printer_data(CONTROL_MACHINE_STATE, 2, "b"); //获取IOT连接状态
    
    Waittimer = lv_timer_create(wait_timerout_handle, 1000, NULL);
    lv_timer_set_repeat_count(Waittimer, 1);
    wait_animmotion(true);
    // LoadSettingsScreenAndObjs(false, 0);
    // LoadSettingsScreenAndObjs(true, 8);
    // Add3rLeveldObjsCb = DeviceBindPageAddFocusObjs;
    // LoadPage(ui_ScreenSettings, 3);
    BackPrepage(false);
}

static void PrivacyPolicyBtnCb(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int dat = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
       CrLogI("dat :%d\n", dat);
        switch(dat) 
        {
            case 0: //返回
                HiddenDialogMessagebox(&PrivacyPolicyMessage);
                BackPrepage(true);
                LoadPage(ui_ScreenSettings, 2);
                lv_group_focus_obj(settings_array[8]->part_panel);
        
                lv_obj_clear_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_HIDDEN); 
                lv_obj_add_flag(ui_DevicebindingPanel, LV_OBJ_FLAG_HIDDEN); 

                break;
            case 1: //查看隐私政策
                HiddenDialogMessagebox(&PrivacyPolicyMessage);
                //Add3rLeveldObjsCb = NULL;
                BackPrepage(true);
                PrivacyPolicyLeftBtnCb = PrivacyPolicyPageLeftBtn;
                PrivacyPolicyRightBtnCb = PrivacyPolicyPageRighBtn;
                LoadPage(ui_SelftestPrivacyPolicy, 1);
            
                break; 

            default:break;
        }
    }
}

static void PrivacyPolicyBtnTextSetCb(lv_obj_t *label, uint8_t label_index, uint8_t language_index)
{
    switch (label_index) {
    case 0:
        lv_label_set_text(label, Back[language_index]);
        break;
    case 1:
        lv_label_set_text(label, LookOver[language_index]);
        break;
    default:break;
    }    
}


static void log_out()
{
    send_buzzer(0x01);
    CrLogI("log out cxyclound");
    set_printer_data(CONTROL_MACHINE_STATE, 3, "61");//解绑用户
    selftest_messagebox_close();
    lv_obj_add_flag(ui_DeviceBoundPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags 

    lv_obj_clear_flag(ui_ServerSelectPanel, LV_OBJ_FLAG_HIDDEN); 
    //lv_obj_clear_flag(ui_DevicebindingLabel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_HIDDEN);
    //_ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

static void not_log_out()
{
    send_buzzer(0x01);
    selftest_messagebox_close();
}
/**
 * @description: 已绑定创想云用户登出操作
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_BoundUserLogOutBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        CrLogI("user sure log out");
        void (*btns_callback[2])(void) = {&not_log_out, &log_out};
        create_selftest_messagebox(KindTips[get_cur_language_index()], LogOutTips[get_cur_language_index()],Cancel[get_cur_language_index()], ErrorBtnConfirm[get_cur_language_index()], btns_callback);
    }
}

/**
 * @description: 服务器环境选择对话框显示
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_ServerSelectBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ShowDialogMessagebox(&ServerSelectMessage, ServerSelectPageAddFocusObjs);
        //Add3rLeveldObjsCb = ServerSelectPageAddFocusObjs;
        //LoadPage(ui_ScreenSettings, 3);
    }
}

/**
 * @description: 服务器选择操作
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_SeverSelectSetting(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int dat = lv_event_get_user_data(e);
    uint8_t language_index = get_cur_language_index();
    if(event_code == LV_EVENT_SHORT_CLICKED) {
       CrLogI("dat :%d\n", dat);
        // switch(dat) 
        // {
        //     case 0: lv_label_set_text(ui_ServerSelectedLabel, AreaChinese[language_index]);break;
        //     case 1: lv_label_set_text(ui_ServerSelectedLabel, AreaOthers[language_index]);break; 
        //     default:break;
        // }

        char tempbuff[10] = {0};
        snprintf(tempbuff, 10, "p%d", dat+1);
        set_printer_data(0x06, 3, tempbuff);

        //服务器更新后再次请求绑定二维码图片
       // CrLogI("Request a QR code image.");
       // send_get_creality_cloud_qrcode_cmd();   
   
        HiddenDialogMessagebox(&ServerSelectMessage);
        lv_obj_clear_flag(ui_ServerSelectPanel, LV_OBJ_FLAG_HIDDEN);
        Add3rLeveldObjsCb = DeviceBindPageAddFocusObjs;
        LoadPage(ui_ScreenSettings, 3);
       // Add3rLeveldObjsCb = NULL;
        //BackPrepage(false);
    }
}

static void SeverSelectTextSet(lv_obj_t *label, uint8_t label_index, uint8_t language_index)
{
    switch (label_index) {
    case 0:
        lv_label_set_text(label, AreaChinese[language_index]);
        break;
    case 1:
        lv_label_set_text(label, AreaOthers[language_index]);
        break;
    default:break;
    }    
}

/**
 * @description: 绑定创想云返回按钮
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_BindDeviceBackBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        CrLogI("ui_event_BindDeviceBackBtn\n");
        // Add3rLeveldObjsCb = NULL;
        // BackPrepage(false);
        LoadPage(ui_ScreenSettings, 2);
        lv_group_focus_obj(settings_array[8]->part_panel);
        
        lv_obj_clear_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(ui_DevicebindingPanel, LV_OBJ_FLAG_HIDDEN); 
    }
}

/**
 * @description: 更新提醒处理
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_UpdateReminder(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED)
    {
        if(!lv_obj_has_state(ui_SwitchUpdateReminder, LV_STATE_CHECKED))
        {
           // lv_obj_add_state(ui_SwitchUpdateReminder, LV_STATE_CHECKED);
            set_printer_data(0x06, 2, "o1");
        }
        else
        {
           // lv_obj_clear_state(ui_SwitchUpdateReminder, LV_STATE_CHECKED);
            set_printer_data(0x06, 2, "o0");
        }
    }
}

/**
 * @description: 恢复出厂事件处理
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_ResetMachineItemPanel(lv_event_t * e)
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
        LoadPage(ui_ResetMachine, 1);
        //_ui_screen_change(ui_ResetMachine, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
/**
 * @description: 关于本机
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_AboutDevicePanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        LoadPage(ui_AboutDevice, 1);
      //  _ui_screen_change(ui_AboutDevice, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

/**
 * @description: 设置页总回调接口
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_SettingItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    settings_list_t *part = lv_event_get_user_data(e);

    if (!part) return;
    //printf("part->index :%d\n", part->index);
    SettingsItemIndex = part->index;
    switch (SettingsItemIndex)
    {
    case SCREEN_BRIGHTNESS_ITEM: //屏幕亮度设置
        ui_event_BrightnessPanelSet(e);
        break;
    case SCREEN_OFF_ITEM: //熄屏设置
        ui_event_ScreenOffTimeSet(e);
        break;
    case LANGUAGE_SELECTION_ITEM: //语言选择设置
        ui_event_LanguageSelect(e);
        break;
    case DEVICE_SELF_TEST_ITEM: //设备自检设置
        ui_event_DeviceSelfTest(e);
        break;
    case TIME_ZONE_SETTING_ITEM: //时区设置
        ui_event_TimezoneSettings(e);
        break;
    case CAMERA_SETTING_ITEM: //摄像头
        ui_event_CameraItemPanel(e);
        break;
    case NETWORK_SETTING_ITEM: //网络设置
        ui_event_NetworkSettings(e);
        break;
    case BIND_DEVICE_ITEM: //绑定创想云
        ui_event_BindDeviceItemPanel(e);
        break;
    case UPDATE_REMINDER_ITEM: //更新提醒
        ui_event_UpdateReminder(e);
        break;
    case VERSION_DETECT_ITEM: //版本检测
        ui_event_EnterUpdatepage(e);
        break;
    case RESET_MACHINE_ITEM: //恢复出厂
        ui_event_ResetMachineItemPanel(e);
        break;
    case ABOUT_DEVICE_ITEM: //关于本机
        ui_event_AboutDevicePanel(e);
        break;
    default:
        break;
    }
}


/************************************系统设置项初始化**************************************/
void ScreenBrightnessStyleInit(settings_list_t *part, const char *item_name)
{
    char buf[5] = {0};
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    
    ui_BrightnessPanel = part->part_panel;
    ui_BrightnessLabel = part->label_item_name;
    ui_BrightnessValLabel = part->label_content_name;  
    lv_obj_align(ui_BrightnessValLabel, LV_ALIGN_RIGHT_MID, -15, 1);
    
    lv_obj_add_flag(part->img_arrow_png, LV_OBJ_FLAG_HIDDEN);

    
    //lv_obj_set_style_bg_color(ui_BrightnessPanel, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BrightnessValSetLabel = lv_label_create(ui_BrightnessPanel);
    lv_obj_set_width(ui_BrightnessValSetLabel, 80); //LV_SIZE_CONTENT
    lv_obj_set_height(ui_BrightnessValSetLabel, 48); //LV_SIZE_CONTENT
    lv_obj_align(ui_BrightnessValSetLabel, LV_ALIGN_RIGHT_MID, -2, 0);
    lv_label_set_text(ui_BrightnessValSetLabel,"10%"); //默认初始化若设备没反馈显示10%
   // lv_obj_set_flex_align(ui_BrightnessValSetLabel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_BrightnessValSetLabel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BrightnessValSetLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_BrightnessValSetLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_BrightnessValSetLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BrightnessValSetLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_BrightnessValSetLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_BrightnessValSetLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_BrightnessValSetLabel, LV_OBJ_FLAG_HIDDEN);
  //  lv_obj_set_style_border_width(ui_BrightnessValSetLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);  

#if 0
     // 亮度滑动条设置
    ui_BrightnessSlider = lv_slider_create(ui_BrightnessPanel);
    lv_obj_set_width(ui_BrightnessSlider, 137);
    lv_obj_set_height(ui_BrightnessSlider, 8);
    // lv_obj_set_x(ui_BrightnessSlider, 174);
    // lv_obj_set_y(ui_BrightnessSlider, -75);
    lv_obj_set_flex_align(ui_BrightnessSlider, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_BrightnessPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_align_to(ui_BrightnessSlider, ui_BrightnessPanel, LV_ALIGN_TOP_LEFT, 362, 25);//351+11
    lv_obj_set_style_radius(ui_BrightnessSlider, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BrightnessSlider, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BrightnessSlider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_BrightnessSlider, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BrightnessSlider, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BrightnessSlider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_BrightnessSlider, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BrightnessSlider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BrightnessSlider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BrightnessSlider, 4, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BrightnessSlider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

   // lv_slider_set_range(ui_BrightnessSlider, 0, 100);
  //  lv_slider_set_value(ui_BrightnessSlider, 0, LV_ANIM_OFF);
   // lv_slider_set_mode(ui_BrightnessSlider, 10); //设置步长为10
    
    //屏幕亮度图片设置
    ui_SystemlightDownImage = lv_img_create(ui_BrightnessPanel);
    lv_img_set_src(ui_SystemlightDownImage, &ui_img_systemlightdown_png);
    lv_obj_set_width(ui_SystemlightDownImage, LV_SIZE_CONTENT);   /// 30
    lv_obj_set_height(ui_SystemlightDownImage, LV_SIZE_CONTENT);    /// 30
    lv_obj_align_to(ui_SystemlightDownImage, ui_BrightnessPanel, LV_ALIGN_TOP_LEFT, 323, 13);//312+11
    // lv_obj_set_x(ui_SystemlightDownImage, 278);
    // lv_obj_set_y(ui_SystemlightDownImage, -75);
    //lv_obj_set_align(ui_SystemlightDownImage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SystemlightDownImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemlightDownImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SystemlightUpImage = lv_img_create(ui_BrightnessPanel);
    lv_img_set_src(ui_SystemlightUpImage, &ui_img_systemlightup_png);
    lv_obj_set_width(ui_SystemlightUpImage, LV_SIZE_CONTENT);   /// 30
    lv_obj_set_height(ui_SystemlightUpImage, LV_SIZE_CONTENT);    /// 30
    // lv_obj_set_x(ui_SystemlightUpImage, 48);
    // lv_obj_set_y(ui_SystemlightUpImage, -74);
    lv_obj_align_to(ui_SystemlightUpImage, ui_BrightnessPanel, LV_ALIGN_TOP_LEFT, 507, 13);//496+11
    //lv_obj_set_align(ui_SystemlightUpImage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SystemlightUpImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SystemlightUpImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
#endif
}

void ScreenOffDialogTextSet(lv_obj_t *label, uint8_t label_index, uint8_t language_index)
{
    lv_label_set_text(label, ScreenOffListLabelSet(label_index, language_index));
}
void ui_event_ScreenOffSetting(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int dat = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
      // printf("dat :%d\n", dat);
        switch(dat) //设置屏幕亮度
        {
            case 0: set_printer_data(0x06,2,"b3");break;
            case 1: set_printer_data(0x06,2,"b5");break; 
            case 2: set_printer_data(0x06,3,"b0");break;
            // case 3: set_printer_data(0x06,2,"b0");break;
            default:break;
        }
        
        HiddenDialogMessagebox(&ScreenOffMessage);
        //Add3rLeveldObjsCb = NULL;
        CrLogI("ui_event_ScreenOffSetting BackPrepage(true)");
        BackPrepage(true);
    }
}

void ScreenOffStyleInit(settings_list_t *part, const char **item_name, uint8_t language_index)
{
    static Msgboxbtn_t ScreenOffbtn[3]; //用于熄屏弹窗数据判断

    if (!part || !item_name)
        return; 
    // printf("item_name[%d] : %s\n", language_index, item_name[language_index]);
    lv_label_set_text(part->label_item_name, item_name[language_index]);
    ui_ScreenOffPanel = part->part_panel;
    ui_ScreenOffLabel = part->label_item_name;
    ui_ScreenOffTimeLabel = part->label_content_name;

    for (size_t i = 0; i < 3; i++)
    {
        ScreenOffbtn[i].btnsCallbackArray = ui_event_ScreenOffSetting;
        ScreenOffbtn[i].SetLabelText = ScreenOffDialogTextSet;
    }
    
    ScreenOffMessage.hasSubPanel = true;
    ScreenOffMessage.title = item_name;
    ScreenOffMessage.btn = ScreenOffbtn;
    ScreenOffMessage.customStyle = &StyleDialogBtn;
    ScreenOffMessage.customFocusStyle = &StyleDialogFocusBtn;

    ScreenOffMessage.btnNumber = sizeof(ScreenOffbtn)/sizeof(Msgboxbtn_t);
    ScreenOffMessage.subPanelAttr.w = 371;
    ScreenOffMessage.subPanelAttr.h = 278;

    InitDialogMessagebox(&ScreenOffMessage);

    lv_obj_align(ScreenOffMessage.titleLabel, LV_ALIGN_TOP_MID, 0, 11);
    
    uint8_t btnBasePos_y = 56;
    for (size_t i = 0; i < ScreenOffMessage.btnNumber; i++)
    {
        lv_obj_align(ScreenOffMessage.btn[i].label, LV_ALIGN_LEFT_MID, 0, 1);
        lv_obj_set_size(ScreenOffMessage.btn[i].btn, 312, 52);
        lv_obj_set_pos(ScreenOffMessage.btn[i].btn, 35, btnBasePos_y);
        btnBasePos_y += 67;
    }
}

void LanguageSelectionStyleInit(settings_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    ui_LanguageSelectPanel = part->part_panel;
    ui_LanguageSelectLabel = part->label_item_name;
    ui_LanguagesLabel = part->label_content_name;
}

void DeviceSelfTestStyleInit(settings_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return;   
    lv_label_set_text(part->label_item_name, item_name);
    ui_DeviceSelfTestPanel = part->part_panel;
    ui_DeviceSelfTestLabel = part->label_item_name;
   
}

void TimeZoneSetStyleInit(settings_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    ui_TimeZoneSetPanel = part->part_panel;
    ui_TimeZoneSetLabel = part->label_item_name;

}

void NetworkSetStyleInit(settings_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    ui_NetworkSetPanel = part->part_panel;
    ui_NetworkSetLabel = part->label_item_name;

}

void CameraSetStyleInit(settings_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    ui_CameraItemPanel = part->part_panel;
    ui_CameraLabel = part->label_item_name;
}

void BindDeviceStyleInit(settings_list_t *part, const char *item_name)
{
    static Msgboxbtn_t PrivacyPolicybtn[2]; 

    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    ui_BindDevicePanel = part->part_panel;
    ui_BindDeviceLabel = part->label_item_name;

    for (size_t i = 0; i < 2; i++)
    {
        PrivacyPolicybtn[i].btnsCallbackArray = PrivacyPolicyBtnCb;
        PrivacyPolicybtn[i].SetLabelText = PrivacyPolicyBtnTextSetCb;
    }
    
    PrivacyPolicyMessage.hasSubPanel = true;
    PrivacyPolicyMessage.title = &KindTips[get_cur_language_index()];
    PrivacyPolicyMessage.btn = PrivacyPolicybtn;
    PrivacyPolicyMessage.customStyle = &Style2DialogBtn;
    PrivacyPolicyMessage.customFocusStyle = &Style2DialogFocusBtn;

    PrivacyPolicyMessage.btnNumber = sizeof(PrivacyPolicybtn)/sizeof(Msgboxbtn_t);
    PrivacyPolicyMessage.subPanelAttr.w = 371;
    PrivacyPolicyMessage.subPanelAttr.h = 285;
  
    InitDialogMessagebox(&PrivacyPolicyMessage);

    //lv_obj_add_style(PrivacyPolicyMessage.btn[1].btn, dialog->customStyle, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(PrivacyPolicyMessage.btn[1].btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(PrivacyPolicyMessage.titleLabel, LV_ALIGN_TOP_MID, 0, 11);
    
    lv_label_set_text(PrivacyPolicyMessage.contentLabel, PrivacyPolicyTips[get_cur_language_index()]);
    uint8_t btnBasePos_x = 26;
    for (size_t i = 0; i < PrivacyPolicyMessage.btnNumber; i++)
    {
       // lv_obj_align(PrivacyPolicyMessage.btn[i].label, LV_ALIGN_LEFT_MID, 0, 1);
        lv_obj_set_size(PrivacyPolicyMessage.btn[i].btn, 140, 52);
        lv_obj_set_pos(PrivacyPolicyMessage.btn[i].btn, btnBasePos_x, 221);
        
        btnBasePos_x += 174;
    }
}

void UpdateReminderStyleInit(settings_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    ui_UpdateReminderPanel = part->part_panel;
    ui_UpdateReminderLabel = part->label_item_name;
    lv_obj_add_flag(part->img_arrow_png, LV_OBJ_FLAG_HIDDEN);
}

void VersionDetectStyleInit(settings_list_t *part, const char *item_name, uint8_t language_index)
{
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    ui_VersionDetectPanel = part->part_panel;
    ui_VersionDetectLabel = part->label_item_name;
    ui_VersionLabel = part->label_content_name;

    lv_obj_align(ui_VersionLabel, LV_ALIGN_RIGHT_MID, -43, 1);

    char buff[150] = {0};
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%sV1.0.1", CurVersionArray[language_index]);
    lv_label_set_text(ui_VersionLabel, buff);  

    ui_SystemsettingLabeltips = lv_label_create(ui_VersionDetectPanel);
    lv_obj_set_width(ui_SystemsettingLabeltips, 9);
    lv_obj_set_height(ui_SystemsettingLabeltips, 9);
    //lv_obj_align(ui_SystemsettingLabeltips, LV_ALIGN_TOP_LEFT, 637, 0);
    lv_obj_align(ui_SystemsettingLabeltips, LV_ALIGN_TOP_RIGHT, -34, 9);
    lv_label_set_text(ui_SystemsettingLabeltips, "");
    lv_obj_set_style_opa(ui_SystemsettingLabeltips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemsettingLabeltips, lv_color_hex(0xF55254), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemsettingLabeltips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SystemsettingLabeltips, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_SystemsettingLabeltips, LV_OBJ_FLAG_HIDDEN); 
}

void ResetMachineStyleInit(settings_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    ui_ResetMachinePanel = part->part_panel;
    ui_ResetMachineLabel = part->label_item_name;
}

void AboutDeviceStyleInit(settings_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    ui_AboutDevicePanel = part->part_panel;
    ui_AboutDeviceLabel = part->label_item_name;
}


void ui_SettingCustomStyle(void)
{
    //自定义对话框按钮默认样式
    lv_style_init(&StyleDialogBtn);
	lv_style_reset(&StyleDialogBtn);
	lv_style_set_radius(&StyleDialogBtn, 0);
    lv_style_set_radius(&StyleDialogBtn, 6);
    lv_style_set_bg_color(&StyleDialogBtn, lv_color_hex(0x28292D));
    lv_style_set_bg_opa(&StyleDialogBtn, 255);
    lv_style_set_shadow_width(&StyleDialogBtn, 0);
    lv_style_set_shadow_spread(&StyleDialogBtn, 0);
    lv_style_set_border_width(&StyleDialogBtn, 1);
    lv_style_set_border_color(&StyleDialogBtn, lv_color_hex(0x4A4E57));

    // 选中后改变颜色样式    
    lv_style_init(&StyleDialogFocusBtn);
	lv_style_reset(&StyleDialogFocusBtn);
    lv_style_set_bg_color(&StyleDialogFocusBtn, lv_color_hex(0x2A2A2A));
    lv_style_set_border_side(&StyleDialogFocusBtn, LV_BORDER_SIDE_FULL);
    lv_style_set_border_color(&StyleDialogFocusBtn, lv_color_hex(0xCDF6FF));
    lv_style_set_radius(&StyleDialogFocusBtn, 6);
    lv_style_set_border_opa(&StyleDialogFocusBtn, 255);
    lv_style_set_border_width(&StyleDialogFocusBtn, 2);  
    lv_style_set_outline_pad(&StyleDialogFocusBtn, 0);
    lv_style_set_shadow_color(&StyleDialogFocusBtn, lv_color_hex(0xCDF6FF));
    lv_style_set_outline_color(&StyleDialogFocusBtn, lv_color_hex(0xCDF6FF));

    lv_style_init(&Style2DialogBtn);
	lv_style_reset(&Style2DialogBtn);
    lv_style_set_radius(&Style2DialogBtn, 0);
    lv_style_set_radius(&Style2DialogBtn, 6);
    lv_style_set_bg_color(&Style2DialogBtn, lv_color_hex(0x50535A));
    lv_style_set_bg_opa(&Style2DialogBtn, 255);
    lv_style_set_shadow_width(&Style2DialogBtn, 0);
    lv_style_set_shadow_spread(&Style2DialogBtn, 0);
    lv_style_set_border_width(&Style2DialogBtn, 0);
   // lv_style_set_border_color(&Style2DialogBtn, lv_color_hex(0x4A4E57));
    
    //选中后只改变边框颜色
    lv_style_init(&Style2DialogFocusBtn);
	lv_style_reset(&Style2DialogFocusBtn);
    lv_style_set_bg_color(&Style2DialogFocusBtn, lv_color_hex(0x2A2A2A));
    lv_style_set_border_side(&Style2DialogFocusBtn, LV_BORDER_SIDE_FULL);
    lv_style_set_border_color(&Style2DialogFocusBtn, lv_color_hex(0xCDF6FF));
    lv_style_set_radius(&Style2DialogFocusBtn, 6);
    lv_style_set_border_opa(&Style2DialogFocusBtn, 255);
    lv_style_set_border_width(&Style2DialogFocusBtn, 4);  
    lv_style_set_outline_pad(&Style2DialogFocusBtn, 0);
    lv_style_set_shadow_color(&Style2DialogFocusBtn, lv_color_hex(0xCDF6FF));
    lv_style_set_outline_color(&Style2DialogFocusBtn, lv_color_hex(0xCDF6FF));

    lv_style_init(&StyleDialogBtnDefault);
	lv_style_reset(&StyleDialogBtnDefault); 
	lv_style_set_bg_color(&StyleDialogBtnDefault, lv_color_hex(0x3C3E42));
    lv_style_set_shadow_spread(&StyleDialogBtnDefault, 0);
    lv_style_set_shadow_width(&StyleDialogBtnDefault, 0);
	lv_style_set_bg_opa(&StyleDialogBtnDefault, 0);
	lv_style_set_border_width(&StyleDialogBtnDefault, 0);
    lv_style_set_border_color(&StyleDialogBtnDefault, lv_color_hex(0x3C3E42));
    lv_style_set_radius(&StyleDialogBtnDefault, 8);
    lv_style_set_pad_all(&StyleDialogBtnDefault, 0);
    lv_style_set_outline_pad(&StyleDialogBtnDefault, 0);
    lv_style_set_text_color(&StyleDialogBtnDefault, lv_color_hex(0xFFFFFF));
	//lv_style_set_text_font(&StyleDialogBtnDefault, &lv_font_simsun_24);
}

static void SettingsPageChangeObjs(uint8_t index);
void ui_Settings_screen_init(void)
{
    ui_SettingCustomStyle();
    ui_ScreenSettings = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenSettings, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenSettings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_ScreenSettings, SettingsPageChangeObjs, LoadSettingsScreen);
    
    ScreenSettings.GropName = lv_group_create();
    ScreenSettings.stateValue = false;

    ui_PanelPageSettings = lv_obj_create(ui_ScreenSettings);
    lv_obj_set_width(ui_PanelPageSettings, 68);
    lv_obj_set_height(ui_PanelPageSettings, 360);
    lv_obj_set_pos(ui_PanelPageSettings, 0, 60);
    lv_obj_clear_flag(ui_PanelPageSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPageSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPageSettings, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    uint8_t language_index = get_cur_language_index();

    ui_ButtonHomePage = lv_btn_create(ui_PanelPageSettings);
    lv_obj_set_width(ui_ButtonHomePage, 68);
    lv_obj_set_height(ui_ButtonHomePage, 72);
   /// lv_obj_set_align(ui_ButtonHomePage, LV_ALIGN_TOP_LEFT);
    lv_obj_set_x(ui_ButtonHomePage, -18);
    lv_obj_set_y(ui_ButtonHomePage, -18);
    lv_obj_add_flag(ui_ButtonHomePage, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonHomePage, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonHomePage, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    lv_obj_set_style_border_color(ui_ButtonHomePage, lv_color_hex(0xB0F1FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonHomePage, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonHomePage, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonHomePage, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ButtonHomePage, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonHomePage, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);    

    ui_ButtonAxisMove = lv_btn_create(ui_PanelPageSettings);
    lv_obj_set_width(ui_ButtonAxisMove, 68);
    lv_obj_set_height(ui_ButtonAxisMove, 72);
    lv_obj_set_x(ui_ButtonAxisMove, -18);
    lv_obj_set_y(ui_ButtonAxisMove, 54);
    lv_obj_add_flag(ui_ButtonAxisMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonAxisMove, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMove, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMove, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonAxisMove, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonAxisMove, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonAxisMove, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonAxisMove, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    ui_ButtonFIleManage = lv_btn_create(ui_PanelPageSettings);
    lv_obj_set_width(ui_ButtonFIleManage, 68);
    lv_obj_set_height(ui_ButtonFIleManage, 72);
    lv_obj_set_x(ui_ButtonFIleManage, -18);
    lv_obj_set_y(ui_ButtonFIleManage, 126);
    lv_obj_add_flag(ui_ButtonFIleManage, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFIleManage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonFIleManage, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonFIleManage, &ui_img_pagefilemanage_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_radius(ui_ButtonFIleManage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonFIleManage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonFIleManage, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonFIleManage, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonFIleManage, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonFIleManage, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonFIleManage, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    
    //ui_ButtonSettings = lv_btn_create(ui_PanelPageSettings);
    ui_ButtonSettings = lv_obj_create(ui_PanelPageSettings);
    lv_obj_set_width(ui_ButtonSettings, 68);
    lv_obj_set_height(ui_ButtonSettings, 72);
    lv_obj_set_x(ui_ButtonSettings, -18);
    lv_obj_set_y(ui_ButtonSettings, 198);
    lv_obj_add_flag(ui_ButtonSettings, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonSettings, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_set_style_bg_img_src(ui_ButtonSettings, &ui_img_pagesettingselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonSettings, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettings, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonSettings, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonSettings, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonSettings, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonSettings, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonSettings, 1, LV_PART_MAIN | LV_STATE_PRESSED);
    
    ui_ButtonReserve = lv_btn_create(ui_PanelPageSettings);
    lv_obj_set_width(ui_ButtonReserve, 68);
    lv_obj_set_height(ui_ButtonReserve, 72);
    lv_obj_set_x(ui_ButtonReserve, -18);
    lv_obj_set_y(ui_ButtonReserve, 270);
    lv_obj_add_flag(ui_ButtonReserve, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserve, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonReserve, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonReserve, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserve, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonReserve, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonReserve, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonReserve, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonReserve, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    
    lv_obj_add_event_cb(ui_ButtonHomePage,ui_event_ButtonHomePage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMove,ui_event_ButtonAxisMove, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonFIleManage,ui_event_ButtonFIleManage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettings,ui_event_ButtonSettings, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserve,ui_event_ButtonReserve, LV_EVENT_ALL, NULL);
    

    /*-------------------------------------------系统内容设置----------------------------------------------------*/
    ui_SettingsItemMainPanel = lv_obj_create(ui_ScreenSettings);
    lv_obj_clear_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SettingsItemMainPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingsItemMainPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui_SettingsItemMainPanel, 68, 60); //页面导航栏宽度为68 
	lv_obj_set_size(ui_SettingsItemMainPanel, 572, 360);
   // lv_obj_set_align(ui_SettingsItemMainPanel, LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_radius(ui_SettingsItemMainPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_SettingsItemMainPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SettingsItemMainPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_SettingsItemMainPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
     lv_obj_set_style_border_width(ui_SettingsItemMainPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_add_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_HIDDEN);

    ui_SettingTitlePanel = lv_obj_create(ui_SettingsItemMainPanel);
    lv_obj_set_pos(ui_SettingTitlePanel, 0, 0);
    lv_obj_set_size(ui_SettingTitlePanel, 572, 46);
    lv_obj_clear_flag(ui_SettingTitlePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SettingTitlePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SettingTitlePanel, lv_color_hex(0x101011), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingTitlePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SettingTitlePanel, lv_color_hex(0x565656), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SettingTitlePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SettingTitlePanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_SettingTitlePanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SettingTitlePanel, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_SettingTitleLabel = lv_label_create(ui_SettingTitlePanel);
    lv_obj_set_size(ui_SettingTitleLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_SettingTitleLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingTitleLabel, Setting[language_index]);
    lv_obj_set_style_text_color(ui_SettingTitleLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SettingTitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SettingTitleLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SettingTitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceIconPanel = lv_obj_create(ui_SettingTitlePanel);
    lv_obj_set_size(ui_DeviceIconPanel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_clear_flag(ui_DeviceIconPanel, LV_OBJ_FLAG_SCROLLABLE);  
    lv_obj_align(ui_DeviceIconPanel, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_set_style_radius(ui_DeviceIconPanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceIconPanel, lv_color_hex(0x101011), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceIconPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_DeviceIconPanel, lv_color_hex(0x565656), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_DeviceIconPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DeviceIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_DeviceIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_DeviceIconPanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_column(ui_DeviceIconPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_align(ui_DeviceIconPanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    //激光雷达
    ui_ImageLaserState = lv_img_create(ui_DeviceIconPanel);
    lv_obj_set_size(ui_ImageLaserState, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_img_set_src(ui_ImageLaserState, &ui_img_laser_png);
    lv_obj_add_flag(ui_ImageLaserState, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageLaserState, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //lv_obj_set_flex_align(ui_ImageLaserState, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageLaserState, LV_OBJ_FLAG_HIDDEN); 

    //摄像头
    ui_ImageCamerastate = lv_img_create(ui_DeviceIconPanel);
    lv_obj_set_size(ui_ImageCamerastate, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
   // lv_obj_align(ui_ImageCamerastate, LV_ALIGN_RIGHT_MID, -65, 0);
    lv_img_set_src(ui_ImageCamerastate, &ui_img_camera_png);
    lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN); 

    //wifi图标
    ui_ImageWifiNormal = lv_img_create(ui_DeviceIconPanel);
    settings_page_set_wifi_status(wifi_Intensity);
    lv_obj_set_size(ui_ImageWifiNormal, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
   // lv_obj_align(ui_ImageWifiNormal, LV_ALIGN_RIGHT_MID, -4, -3);
   // lv_obj_set_align(ui_ImageWifiNormal, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_ImageWifiNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageWifiNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SettingsPanelList = lv_obj_create(ui_SettingsItemMainPanel);
    lv_obj_set_size(ui_SettingsPanelList, 572, 308);
    lv_obj_set_pos(ui_SettingsPanelList, 0, 52);//56
    lv_obj_set_align(ui_SettingsPanelList, LV_ALIGN_TOP_LEFT);
    lv_obj_add_flag(ui_SettingsPanelList, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SettingsPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SettingsPanelList, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingsPanelList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_SettingsPanelList, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SettingsPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_SettingsPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SettingsPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    int ui_PanelFileListY = 0;
    for (size_t index = 1; index < MAX_ITEM; index++)
    {
         settings_array[index] = create_settings_list_item(ui_SettingsPanelList, index, 9, ui_PanelFileListY, &ui_event_SettingItem);
         ui_PanelFileListY += 60;
    }

    ScreenBrightnessStyleInit(settings_array[1], ScreenBrightnessArray[language_index]);
    ScreenOffStyleInit(settings_array[2], ScreenOffArray, language_index);
    LanguageSelectionStyleInit(settings_array[3], LanguageSelection[language_index]);
    DeviceSelfTestStyleInit(settings_array[4], DeviceSelfTestArray[language_index]);
    TimeZoneSetStyleInit(settings_array[5], TimeZoneArray[language_index]);
    CameraSetStyleInit(settings_array[6], CameraArray[language_index]);
    NetworkSetStyleInit(settings_array[7], NetworkArray[language_index]);
    BindDeviceStyleInit(settings_array[8], BindDevice[language_index]);
    UpdateReminderStyleInit(settings_array[9], UpdateReminder[language_index]);
    VersionDetectStyleInit(settings_array[10], VersionArray[language_index], language_index);
    ResetMachineStyleInit(settings_array[11], ResetMachine[language_index]);
    AboutDeviceStyleInit(settings_array[12], AboutDevice[language_index]);

    char buff[150] = {0};
    memset(buff, 0, sizeof(buff));

    /*************************************网络设置 子页****************************************/
    ui_NetworkSettingsPanel = lv_obj_create(ui_ScreenSettings);
    lv_obj_set_pos(ui_NetworkSettingsPanel, 73, 68);
    lv_obj_set_size(ui_NetworkSettingsPanel, 559, 344); 
    lv_obj_set_align(ui_NetworkSettingsPanel, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_NetworkSettingsPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkSettingsPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSettingsPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSettingsPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSettingsPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_NetworkSettingsPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_NetworkSettingsPanel, LV_OBJ_FLAG_HIDDEN); 

    ui_NetworksettingTitle = lv_label_create(ui_NetworkSettingsPanel);
    lv_obj_set_size(ui_NetworksettingTitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_NetworksettingTitle, 16, 0);//6
    //lv_obj_set_align(ui_NetworksettingTitle, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_NetworksettingTitle, NetworkArray[language_index]);//DetectionItemArray[language_index]
    lv_obj_set_style_text_align(ui_NetworksettingTitle, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_NetworksettingTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworksettingTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworksettingTitle, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkPanelLine = lv_obj_create(ui_NetworkSettingsPanel);
    lv_obj_set_size(ui_NetworkPanelLine, 543, 1);
    lv_obj_set_pos(ui_NetworkPanelLine, 7, 49);
    lv_obj_clear_flag(ui_NetworkPanelLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_NetworkPanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkPanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkPanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkPanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkPanelLine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //返回按钮
    ui_NetworkSetBackBtn = lv_btn_create(ui_NetworkSettingsPanel);
    lv_obj_set_size(ui_NetworkSetBackBtn, 68, 38);
    lv_obj_set_pos(ui_NetworkSetBackBtn, 474, 6);
    lv_obj_add_flag(ui_NetworkSetBackBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_NetworkSetBackBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkSetBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSetBackBtn, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSetBackBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkSetBackBtn, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSetBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_NetworkSetBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_NetworkSetBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_NetworkSetBackBtn, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkSetBackBtn, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_NetworkSetBackBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_NetworkSetBackBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_NetworkSetBackBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_NetworkSetBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_NetworkSetBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //本地网络
    ui_LocalNetworkPanel = lv_obj_create(ui_NetworkSettingsPanel);
    lv_obj_set_size(ui_LocalNetworkPanel, 523, 56);
    lv_obj_set_pos(ui_LocalNetworkPanel, 14, 54);
    lv_obj_clear_flag(ui_LocalNetworkPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_LocalNetworkPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LocalNetworkPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LocalNetworkPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_LocalNetworkPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_LocalNetworkPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_LocalNetworkPanel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_LocalNetworkPanel, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_LocalNetworkPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LocalNetworkPanel, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_LocalNetworkPanel, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_LocalNetworkPanel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_LocalNetworkPanel, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_add_flag(ui_LocalNetworkPanel, LV_OBJ_FLAG_HIDDEN); 

    ui_LoclNetworkImage = lv_img_create(ui_LocalNetworkPanel);
    lv_img_set_src(ui_LoclNetworkImage, &ui_img_network_png);
    lv_obj_set_width(ui_LoclNetworkImage, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LoclNetworkImage, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LoclNetworkImage, 14);
    lv_obj_set_y(ui_LoclNetworkImage, 0);
    lv_obj_set_align(ui_LoclNetworkImage, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_LoclNetworkImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_LoclNetworkImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_NetworkSettingLabel1 = lv_label_create(ui_LocalNetworkPanel);
    lv_obj_set_width(ui_NetworkSettingLabel1, 260);
    lv_obj_set_height(ui_NetworkSettingLabel1, 25);
    lv_obj_align(ui_NetworkSettingLabel1, LV_ALIGN_LEFT_MID, 55, -3);
    lv_label_set_text(ui_NetworkSettingLabel1, LocalNetworkArray[language_index]);
    lv_obj_set_style_text_color(ui_NetworkSettingLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkSettingLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkSettingLabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkSettingLabel2 = lv_label_create(ui_LocalNetworkPanel);
    lv_obj_set_width(ui_NetworkSettingLabel2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_NetworkSettingLabel2, LV_SIZE_CONTENT);
    lv_label_set_text(ui_NetworkSettingLabel2, UnConnectedArray[language_index]);
    lv_obj_align(ui_NetworkSettingLabel2, LV_ALIGN_RIGHT_MID, -30, 0);
    lv_obj_set_style_text_color(ui_NetworkSettingLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkSettingLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_NetworkSettingLabel2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkSettingLabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LoclNetworkArrowImage = lv_img_create(ui_LocalNetworkPanel);
    lv_img_set_src(ui_LoclNetworkArrowImage, &ui_img_rightarrow_png);
    lv_obj_set_width(ui_LoclNetworkArrowImage, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LoclNetworkArrowImage, LV_SIZE_CONTENT);
    lv_obj_align(ui_LoclNetworkArrowImage, LV_ALIGN_RIGHT_MID, -10, 0);
    lv_obj_add_flag(ui_LoclNetworkArrowImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_LoclNetworkArrowImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

  
    //键盘样式处理
    ui_NetworkSettingPanel = lv_obj_create(ui_ScreenSettings);
    lv_obj_set_size(ui_NetworkSettingPanel, 640, 360);
    lv_obj_set_pos(ui_NetworkSettingPanel, 0, 60);
    lv_obj_clear_flag(ui_NetworkSettingPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkSettingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSettingPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSettingPanel, 240, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkSettingPanel, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkSettingPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSettingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_NetworkSettingPanel, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_NetworkSettingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // wifi名显示区域
    // ui_NetworkName = lv_obj_create(ui_NetworkSettingPanel);
    // lv_obj_set_size(ui_NetworkName, 630, 56);
    // lv_obj_set_pos(ui_NetworkName, 5, 8);
    // lv_obj_set_style_radius(ui_NetworkName, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_NetworkName, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_NetworkName, 229, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_NetworkName, lv_color_hex(0x888989), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_NetworkName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_NetworkName, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_NetworkName, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_all(ui_NetworkName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkName_TextArea = lv_textarea_create(ui_NetworkSettingPanel);
    lv_obj_set_width(ui_NetworkName_TextArea, 630);
    lv_obj_set_height(ui_NetworkName_TextArea, 56);
    lv_obj_set_pos(ui_NetworkName_TextArea, 5, 8);
    lv_textarea_set_text(ui_NetworkName_TextArea, "");
    lv_obj_set_style_text_color(ui_NetworkName_TextArea, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkName_TextArea, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
 //   lv_obj_set_style_text_align(ui_NetworkName_TextArea, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkName_TextArea, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_radius(ui_NetworkName_TextArea, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkName_TextArea, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkName_TextArea, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkName_TextArea, lv_color_hex(0x888989), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkName_TextArea, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkName_TextArea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_NetworkName_TextArea, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkName_TextArea, lv_color_hex(0x000000), LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_textarea_set_placeholder_text(ui_NetworkName_TextArea, Wifiname[language_index]);
    lv_obj_set_style_border_color(ui_NetworkName_TextArea, lv_color_hex(0x42BDD8), LV_PART_CURSOR | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_NetworkName_TextArea, 255, LV_PART_CURSOR | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_NetworkName_TextArea, 2, LV_PART_CURSOR | LV_STATE_FOCUSED);
   
    //密码输入区域
    ui_NetworkPassw_TextArea = lv_textarea_create(ui_NetworkSettingPanel);
    lv_obj_set_size(ui_NetworkPassw_TextArea, 630, 56);
    lv_obj_set_pos(ui_NetworkPassw_TextArea, 5, 71);
    lv_obj_set_style_bg_color(ui_NetworkPassw_TextArea, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkPassw_TextArea, 229, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkPassw_TextArea, lv_color_hex(0x888989), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkPassw_TextArea, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkPassw_TextArea, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_NetworkPassw_TextArea, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_NetworkPassw_TextArea, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_textarea_set_placeholder_text(ui_NetworkPassw_TextArea, InputPasswordMsg[language_index]);
    lv_obj_set_style_text_font(ui_NetworkPassw_TextArea, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkPassw_TextArea, lv_color_hex(0x42BDD8), LV_PART_CURSOR | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_NetworkPassw_TextArea, 255, LV_PART_CURSOR | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_NetworkPassw_TextArea, 2, LV_PART_CURSOR | LV_STATE_FOCUSED);

    
    ui_NetworkKeyboardPanel = lv_textarea_create(ui_NetworkSettingPanel);
    lv_obj_set_size(ui_NetworkKeyboardPanel, 640, 220);
    lv_obj_clear_flag(ui_NetworkKeyboardPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_align(ui_NetworkKeyboardPanel, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_bg_color(ui_NetworkKeyboardPanel, lv_color_hex(0x393D44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkKeyboardPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkKeyboardPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_NetworkKeyboardPanel, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);

    //键盘样式设置
    ui_NetworkSetting_Keyboard = lv_btnmatrix_create(ui_NetworkKeyboardPanel); //创建按钮矩阵（Button Matrix）对象
    lv_btnmatrix_set_map(ui_NetworkSetting_Keyboard, kb_map[KEYBOARD_MODE_TEXT_LOWER]); //设置按钮矩阵的按钮标签映射
    lv_btnmatrix_set_ctrl_map(ui_NetworkSetting_Keyboard, kb_ctrl[0]);
    // lv_btnmatrix_set_btn_width(ui_NetworkSetting_Keyboard, 36, 4);//
    lv_obj_set_size(ui_NetworkSetting_Keyboard, 644, 224); 
    lv_obj_set_style_text_font(ui_NetworkSetting_Keyboard, lv_font25.font, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_NetworkSetting_Keyboard, lv_color_hex(0xFFFFFF), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkSetting_Keyboard, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkSetting_Keyboard, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkSetting_Keyboard, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_NetworkSetting_Keyboard, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_NetworkSetting_Keyboard, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_NetworkSetting_Keyboard, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_center(ui_NetworkSetting_Keyboard);

    //隐藏键盘标图
    // ImageCloseNetworkKeyboard = lv_img_create(ui_NetworkSettingPanel);
    // lv_img_set_src(ImageCloseNetworkKeyboard, &ui_img_group_12_png);
    // lv_obj_set_width(ImageCloseNetworkKeyboard, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ImageCloseNetworkKeyboard, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ImageCloseNetworkKeyboard, 19);
    // lv_obj_set_y(ImageCloseNetworkKeyboard, 21);
    // lv_obj_add_flag(ImageCloseNetworkKeyboard, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_add_flag(ImageCloseNetworkKeyboard, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    // lv_obj_clear_flag(ImageCloseNetworkKeyboard, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_ext_click_area(ImageCloseNetworkKeyboard, 30);
    
    //网络连接文本
    // ui_NetworkSettingLabel4 = lv_label_create(ui_NetworkSettingPanel);
    // lv_obj_set_width(ui_NetworkSettingLabel4, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_NetworkSettingLabel4, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_NetworkSettingLabel4, 0);
    // lv_obj_set_y(ui_NetworkSettingLabel4, 21);
    // lv_obj_set_align(ui_NetworkSettingLabel4, LV_ALIGN_TOP_MID);
    // lv_label_set_text(ui_NetworkSettingLabel4, NetworkConnect[language_index]);
    // lv_obj_set_style_text_color(ui_NetworkSettingLabel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_NetworkSettingLabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_NetworkSettingLabel4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_NetworkSettingLabel4, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);

   // lv_keyboard_set_textarea(ui_NetworkSetting_Keyboard, ui_NetworkPassw_TextArea); //将键盘对象与文本区域（Textarea）关联
    lv_obj_add_flag(ui_NetworkSettingPanel,LV_OBJ_FLAG_HIDDEN);
    //lv_obj_add_event_cb(ImageCloseNetworkKeyboard, ui_event_CloseNetworkKeyboard, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LocalNetworkPanel, ui_event_LocalNetworkSettingPanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_NetworkName_TextArea, ui_event_NetworkFocusChange, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_NetworkPassw_TextArea, ui_event_NetworkFocusChange, LV_EVENT_ALL, NULL);

    //wifi 列表面板
    ui_NetworkListPanel = lv_obj_create(ui_NetworkSettingsPanel);
    lv_obj_set_pos(ui_NetworkListPanel, 0, 110);
    lv_obj_set_size(ui_NetworkListPanel, 559, 249);
    lv_obj_set_align(ui_NetworkListPanel, LV_ALIGN_TOP_LEFT); 
    lv_obj_add_flag(ui_NetworkListPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkListPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkListPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkListPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkListPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkListPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkListPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_NetworkListPanel, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_NetworkListPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //wifi 连接成功列表顶层显示
    ui_CurConnectedWiFiPanel = lv_obj_create(ui_NetworkListPanel);
    lv_obj_set_size(ui_CurConnectedWiFiPanel, 0, 94);
    lv_obj_align(ui_CurConnectedWiFiPanel, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_clear_flag(ui_CurConnectedWiFiPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_CurConnectedWiFiPanel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_set_style_radius(ui_CurConnectedWiFiPanel, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CurConnectedWiFiPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CurConnectedWiFiPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CurConnectedWiFiPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CurConnectedWiFiPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CurConnectedWiFiPanel, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_CurConnectedWiFiPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CurConnectedWiFiPanel, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_CurConnectedWiFiPanel, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_CurConnectedWiFiPanel, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_CurConnectedWiFiPanel, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_pad_all(ui_CurConnectedWiFiPanel, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_add_flag(ui_CurConnectedWiFiPanel,LV_OBJ_FLAG_HIDDEN);

    /*************************************绑定创想云 子页****************************************/
    ui_DevicebindingPanel = lv_obj_create(ui_ScreenSettings);
    lv_obj_set_pos(ui_DevicebindingPanel, 76, 68);
    lv_obj_set_size(ui_DevicebindingPanel, 556, 344);
    lv_obj_set_align(ui_DevicebindingPanel, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_DevicebindingPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DevicebindingPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DevicebindingPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DevicebindingPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DevicebindingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_DevicebindingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_DevicebindingPanel, LV_OBJ_FLAG_HIDDEN); 

    ui_BindDeviceTitleLabel = lv_label_create(ui_DevicebindingPanel);
    lv_obj_set_size(ui_BindDeviceTitleLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_BindDeviceTitleLabel, 16, 0);//6
    //lv_obj_set_align(ui_NetworksettingTitle, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_BindDeviceTitleLabel, BindDevice[language_index]);//DetectionItemArray[language_index]
    lv_obj_set_style_text_align(ui_BindDeviceTitleLabel, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_BindDeviceTitleLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BindDeviceTitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BindDeviceTitleLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    

    //上下分割线
    ui_BindDevicePanelLine = lv_obj_create(ui_DevicebindingPanel);
    lv_obj_set_size(ui_BindDevicePanelLine, 543, 1);
    lv_obj_set_pos(ui_BindDevicePanelLine, 7, 49);
    lv_obj_clear_flag(ui_BindDevicePanelLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_BindDevicePanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BindDevicePanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_BindDevicePanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_BindDevicePanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BindDevicePanelLine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //返回按钮
    ui_BindDeviceBackBtn = lv_btn_create(ui_DevicebindingPanel);
    lv_obj_set_size(ui_BindDeviceBackBtn, 68, 38);
    lv_obj_set_pos(ui_BindDeviceBackBtn, 474, 6);
    lv_obj_add_flag(ui_BindDeviceBackBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BindDeviceBackBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BindDeviceBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BindDeviceBackBtn, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BindDeviceBackBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_BindDeviceBackBtn, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BindDeviceBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BindDeviceBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BindDeviceBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_BindDeviceBackBtn, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_BindDeviceBackBtn, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_BindDeviceBackBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_BindDeviceBackBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_BindDeviceBackBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_BindDeviceBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_BindDeviceBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
     
    //服务器设置面板
    ui_ServerSelectPanel = lv_obj_create(ui_DevicebindingPanel);
    lv_obj_set_size(ui_ServerSelectPanel, 532, 56);
    lv_obj_set_pos(ui_ServerSelectPanel, 12, 61);
    lv_obj_set_align(ui_ServerSelectPanel, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_ServerSelectPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ServerSelectPanel, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ServerSelectPanel, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ServerSelectPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ServerSelectPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ServerSelectPanel, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ServerSelectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ServerSelectPanel, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_ServerSelectPanel, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_ServerSelectPanel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_ServerSelectPanel, 4, LV_PART_MAIN | LV_STATE_FOCUSED);

    //右箭头图
    lv_obj_t *ui_ImageArrow = lv_img_create(ui_ServerSelectPanel);
    lv_img_set_src(ui_ImageArrow, &ui_img_rightarrow_png);
    lv_obj_set_width(ui_ImageArrow, 11);  //11 LV_SIZE_CONTENT
    lv_obj_set_height(ui_ImageArrow, 21);    
    lv_obj_align(ui_ImageArrow, LV_ALIGN_RIGHT_MID, -10, 0);
    lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageArrow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    //服务器区域 
    ui_DevicebindingAreaLabel = lv_label_create(ui_ServerSelectPanel);
    lv_label_set_text(ui_DevicebindingAreaLabel, AreaOthers[language_index]);
    lv_obj_set_size(ui_DevicebindingAreaLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_DevicebindingAreaLabel, LV_ALIGN_LEFT_MID, 11, -6);
   // lv_obj_set_align(ui_DevicebindingAreaLabel, LV_ALIGN_CENTER);
    lv_obj_set_style_text_align(ui_DevicebindingAreaLabel, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingAreaLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_DevicebindingAreaLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DevicebindingAreaLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //选中的服务器
    ui_ServerSelectedLabel = lv_label_create(ui_ServerSelectPanel);
    lv_label_set_text(ui_ServerSelectedLabel, AreaChinese[language_index]);
    lv_obj_set_size(ui_ServerSelectedLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_ServerSelectedLabel, LV_ALIGN_RIGHT_MID, -30, -6);
   // lv_obj_set_align(ui_DevicebindingAreaLabel, LV_ALIGN_CENTER);
   // lv_obj_set_style_text_align(ui_ServerSelectedLabel, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ServerSelectedLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ServerSelectedLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ServerSelectedLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    static Msgboxbtn_t ServerSelectbtn[2]; 
    //服务选择弹框处理
    for (size_t i = 0; i < 2; i++)
    {
        ServerSelectbtn[i].btnsCallbackArray = ui_event_SeverSelectSetting;
        ServerSelectbtn[i].SetLabelText = SeverSelectTextSet;
    }
    
    ServerSelectMessage.hasSubPanel = true;
    ServerSelectMessage.title = Area;
    ServerSelectMessage.btn = ServerSelectbtn;
    ServerSelectMessage.customStyle = &StyleDialogBtn;
    ServerSelectMessage.customFocusStyle = &StyleDialogFocusBtn;

    ServerSelectMessage.btnNumber = sizeof(ServerSelectbtn)/sizeof(Msgboxbtn_t);
    ServerSelectMessage.subPanelAttr.w = 371;
    ServerSelectMessage.subPanelAttr.h = 285;

    InitDialogMessagebox(&ServerSelectMessage);

    lv_obj_align(ServerSelectMessage.titleLabel, LV_ALIGN_TOP_MID, 0, 15);
    
    uint8_t btnBasePos_y = 88;
    for (size_t i = 0; i < ServerSelectMessage.btnNumber; i++)
    {
        lv_obj_align(ServerSelectMessage.btn[i].label, LV_ALIGN_LEFT_MID, 0, 1);
        lv_obj_set_size(ServerSelectMessage.btn[i].btn, 312, 52);
        lv_obj_set_pos(ServerSelectMessage.btn[i].btn, 30, btnBasePos_y);
        btnBasePos_y += 77;
    }
    

    //请使用创想云APP扫码绑定设备
    ui_DevicebindingLabel = lv_label_create(ui_DevicebindingPanel);
    lv_obj_set_size(ui_DevicebindingLabel, 400, 60);
    lv_obj_set_pos(ui_DevicebindingLabel, 125, 273);
    lv_label_set_long_mode(ui_DevicebindingLabel, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DevicebindingLabel, DeviceBindTipsMsg[language_index]);
    lv_obj_set_style_text_color(ui_DevicebindingLabel, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevicebindingLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_DevicebindingLabel, LV_OBJ_FLAG_HIDDEN);      /// Flags
    
    //绑定创想云二维码
    ui_DevicebindingQRCodeImage = lv_qrcode_create(ui_DevicebindingPanel, 120, lv_color_hex(0xFFFFFF), lv_color_hex(0x2D2E31));
    lv_obj_set_size(ui_DevicebindingQRCodeImage, 124, 124);
    lv_obj_set_pos(ui_DevicebindingQRCodeImage, 217, 141);
    lv_obj_set_style_border_width(ui_DevicebindingQRCodeImage, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_DevicebindingQRCodeImage, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_HIDDEN);      /// Flags
    
    char temp[64] = {0};
    snprintf(temp, 64, "%s %s", GetSystemConfig().device_sn, GetSystemConfig().device_mac);
    lv_qrcode_update(ui_DevicebindingQRCodeImage, temp, strlen(temp));
    
    // lv_obj_add_flag(ui_DevicebindingPanel5, LV_OBJ_FLAG_HIDDEN);      /// Flags
    // get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态
 
    //服务器信息获取失败
    ui_BindQrCodeGetFailLabel = lv_label_create(ui_DevicebindingPanel);
    lv_obj_set_width(ui_BindQrCodeGetFailLabel, 400);
    lv_obj_set_height(ui_BindQrCodeGetFailLabel, LV_SIZE_CONTENT);
    lv_obj_align(ui_BindQrCodeGetFailLabel, LV_ALIGN_TOP_MID, 0, 197);
    lv_label_set_long_mode(ui_BindQrCodeGetFailLabel, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_BindQrCodeGetFailLabel, IOTTips[language_index]);
    lv_obj_set_style_text_color(ui_BindQrCodeGetFailLabel, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BindQrCodeGetFailLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BindQrCodeGetFailLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_BindQrCodeGetFailLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_add_flag(ui_BindQrCodeGetFailLabel, LV_OBJ_FLAG_HIDDEN);      /// Flags
   
    //用户绑定信息面板
    ui_DeviceBoundPanel = lv_obj_create(ui_DevicebindingPanel);
    lv_obj_set_size(ui_DeviceBoundPanel, 559, 290);
    lv_obj_set_pos(ui_DeviceBoundPanel, 0, 53);
    lv_obj_set_align(ui_DeviceBoundPanel, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_DeviceBoundPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DeviceBoundPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceBoundPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceBoundPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DeviceBoundPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_DeviceBoundPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //已绑定用户头像
    ui_BoundUserimgPanel = lv_obj_create(ui_DeviceBoundPanel);
    lv_obj_set_width(ui_BoundUserimgPanel, 73);
    lv_obj_set_height(ui_BoundUserimgPanel, 73);
    lv_obj_align(ui_BoundUserimgPanel, LV_ALIGN_TOP_LEFT, 22, 22);
    lv_obj_clear_flag(ui_BoundUserimgPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BoundUserimgPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BoundUserimgPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BoundUserimgPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BoundUserimgPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_BoundUserimgPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBoundUserimg = lv_img_create(ui_BoundUserimgPanel);
    lv_obj_set_width(ui_DeviceBoundUserimg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_DeviceBoundUserimg, LV_SIZE_CONTENT);
    lv_obj_align(ui_DeviceBoundUserimg, LV_ALIGN_CENTER, 0 ,0);
    lv_obj_add_flag(ui_DeviceBoundUserimg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_DeviceBoundUserimg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    
    //用户名
    ui_DeviceBoundUsername = lv_label_create(ui_DeviceBoundPanel);
    lv_obj_set_width(ui_DeviceBoundUsername, 400);
    lv_obj_set_height(ui_DeviceBoundUsername, 30);
    lv_obj_align_to(ui_DeviceBoundUsername, ui_BoundUserimgPanel, LV_ALIGN_OUT_RIGHT_TOP, 18, 0);
    lv_label_set_long_mode(ui_DeviceBoundUsername, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DeviceBoundUsername, UserName[language_index]);
    lv_obj_set_style_text_color(ui_DeviceBoundUsername, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBoundUsername, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBoundUsername, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //用户ID
    ui_DeviceBoundUserid = lv_label_create(ui_DeviceBoundPanel);
    lv_obj_set_width(ui_DeviceBoundUserid, 400);
    lv_obj_set_height(ui_DeviceBoundUserid, 30);
    lv_obj_align_to(ui_DeviceBoundUserid, ui_DeviceBoundUsername, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
    lv_label_set_long_mode(ui_DeviceBoundUserid, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DeviceBoundUserid, "ID:");
    lv_obj_set_style_text_color(ui_DeviceBoundUserid, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBoundUserid, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBoundUserid, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //登出按钮
    ui_BoundUserLogOutBtn = lv_btn_create(ui_DeviceBoundPanel);
    lv_obj_set_width(ui_BoundUserLogOutBtn, 106);
    lv_obj_set_height(ui_BoundUserLogOutBtn, 52);
    lv_obj_align(ui_BoundUserLogOutBtn, LV_ALIGN_TOP_RIGHT, -22, 31);
    lv_obj_add_flag(ui_BoundUserLogOutBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BoundUserLogOutBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BoundUserLogOutBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BoundUserLogOutBtn, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BoundUserLogOutBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_BoundUserLogOutBtn, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_BoundUserLogOutBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BoundUserLogOutBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BoundUserLogOutBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_BoundUserLogOutBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BoundUserLogOutBtn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
   /// lv_obj_set_style_bg_color(ui_BoundUserLogOutBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_BoundUserLogOutBtn, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_BoundUserLogOutBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_BoundUserLogOutBtn, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    

    ui_BoundUserLogOutBtnLabel = lv_label_create(ui_BoundUserLogOutBtn);
    lv_obj_set_width(ui_BoundUserLogOutBtnLabel, lv_pct(100));
    lv_obj_set_height(ui_BoundUserLogOutBtnLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_BoundUserLogOutBtnLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_BoundUserLogOutBtnLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_BoundUserLogOutBtnLabel, LogOut[language_index]);
    lv_obj_set_style_text_align(ui_BoundUserLogOutBtnLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BoundUserLogOutBtnLabel, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_BoundUserLogOutBtnLabel, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BoundUserLogOutBtnLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
     
    
    lv_obj_add_event_cb(ui_ServerSelectPanel, ui_event_ServerSelectBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BoundUserLogOutBtn, ui_event_BoundUserLogOutBtn, LV_EVENT_ALL, NULL); //已绑定用户登出事件


    /*************************************摄像头设置 子页****************************************/
    ui_CameraSettingSupanel = lv_obj_create(ui_ScreenSettings);
    lv_obj_set_pos(ui_CameraSettingSupanel, 76, 68);
    lv_obj_set_size(ui_CameraSettingSupanel, 556, 344);
    lv_obj_set_align(ui_CameraSettingSupanel, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_CameraSettingSupanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CameraSettingSupanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CameraSettingSupanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CameraSettingSupanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameraSettingSupanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_CameraSettingSupanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_CameraSettingSupanel, LV_OBJ_FLAG_HIDDEN); 


    /**********摄像头的状态显示****************/
    
    //摄像头未启用
    // lv_obj_t * ui_VideoSettingLabel1 = lv_label_create(ui_CameraSettingSupanel);
    // lv_obj_set_width(ui_VideoSettingLabel1, 409);
    // lv_obj_set_height(ui_VideoSettingLabel1, 28);
    // lv_obj_set_x(ui_VideoSettingLabel1, 15);
    // lv_obj_set_y(ui_VideoSettingLabel1, 350);
    // // memset(buff, 0, sizeof(buff));
    // // sprintf(buff, "%s%s", CameraArray[language_index], DisableArray[language_index]);
    // lv_label_set_text(ui_VideoSettingLabel1, DisableArray[language_index]);
    // lv_obj_set_style_text_color(ui_VideoSettingLabel1, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_VideoSettingLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_VideoSettingLabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_VideoSettingLabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CameraTitleLabel = lv_label_create(ui_CameraSettingSupanel);
    lv_obj_set_size(ui_CameraTitleLabel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_CameraTitleLabel, 16, 0);//
    lv_label_set_text(ui_CameraTitleLabel, CameraArray[language_index]);//DetectionItemArray[language_index]
    lv_obj_set_style_text_align(ui_CameraTitleLabel, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_CameraTitleLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CameraTitleLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CameraTitleLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    

    //上下分割线
    ui_CameraSubpanelLine = lv_obj_create(ui_CameraSettingSupanel);
    lv_obj_set_size(ui_CameraSubpanelLine, 543, 1);
    lv_obj_set_pos(ui_CameraSubpanelLine, 7, 49);
    lv_obj_clear_flag(ui_CameraSubpanelLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_CameraSubpanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CameraSubpanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CameraSubpanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CameraSubpanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameraSubpanelLine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //返回按钮
    ui_CameraSubpaneBackBtn = lv_btn_create(ui_CameraSettingSupanel);
    lv_obj_set_size(ui_CameraSubpaneBackBtn, 68, 38);
    lv_obj_set_pos(ui_CameraSubpaneBackBtn, 474, 6);
    lv_obj_add_flag(ui_CameraSubpaneBackBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_CameraSubpaneBackBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CameraSubpaneBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CameraSubpaneBackBtn, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CameraSubpaneBackBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CameraSubpaneBackBtn, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameraSubpaneBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_CameraSubpaneBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_CameraSubpaneBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_CameraSubpaneBackBtn, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CameraSubpaneBackBtn, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_CameraSubpaneBackBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_CameraSubpaneBackBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_CameraSubpaneBackBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_CameraSubpaneBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_CameraSubpaneBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    /**********视频列表****************/
    ui_VideoListPanel = lv_obj_create(ui_CameraSettingSupanel);
    lv_obj_set_size(ui_VideoListPanel, 532, 56);
    lv_obj_set_pos(ui_VideoListPanel, 12, 61);
    lv_obj_add_flag(ui_VideoListPanel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_VideoListPanel, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_VideoListPanel, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_VideoListPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_VideoListPanel, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_VideoListPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_VideoListPanel, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_VideoListPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式设置
    lv_obj_set_style_bg_color(ui_VideoListPanel, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_VideoListPanel, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_VideoListPanel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_VideoListPanel, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    
    //视频指示图标
    ui_VideoSettingImage7 = lv_img_create(ui_VideoListPanel);
    lv_img_set_src(ui_VideoSettingImage7, &ui_img_video_png);
    lv_obj_set_width(ui_VideoSettingImage7, 30);
    lv_obj_set_height(ui_VideoSettingImage7, 24);
    lv_obj_set_align(ui_VideoSettingImage7, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_VideoSettingImage7, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    
    //视频列表label
    ui_VideoSettingLabel2 = lv_label_create(ui_VideoListPanel);
    lv_obj_set_size(ui_VideoSettingLabel2, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_VideoSettingLabel2, LV_ALIGN_LEFT_MID, 11, 1);
    lv_label_set_text(ui_VideoSettingLabel2, VedioList[language_index]);
    lv_obj_set_style_text_color(ui_VideoSettingLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VideoSettingLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VideoSettingLabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //右侧箭头
    ui_VideoSettingImage8 = lv_img_create(ui_VideoListPanel);
    lv_img_set_src(ui_VideoSettingImage8, &ui_img_rightarrow_png);
    lv_obj_set_size(ui_VideoSettingImage8, 11, 21);
    lv_obj_align(ui_VideoSettingImage8, LV_ALIGN_RIGHT_MID, -15, 0);
    lv_obj_add_flag(ui_VideoSettingImage8, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    /**********摄像头设置***************/
    ui_CameraSettingPanel = lv_obj_create(ui_CameraSettingSupanel);
    lv_obj_set_size(ui_CameraSettingPanel, 532, 56);
    lv_obj_set_pos(ui_CameraSettingPanel, 12, 125);
    lv_obj_add_flag(ui_CameraSettingPanel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_CameraSettingPanel, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_CameraSettingPanel, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CameraSettingPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CameraSettingPanel, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_CameraSettingPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_CameraSettingPanel, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_CameraSettingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CameraSettingPanel, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_CameraSettingPanel, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_CameraSettingPanel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_CameraSettingPanel, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    
    //摄像头设置图标--
    ui_VideoSettingImage9 = lv_img_create(ui_CameraSettingPanel);
    lv_img_set_src(ui_VideoSettingImage9, &ui_img_seting_1_png);
    lv_obj_set_width(ui_VideoSettingImage9, 25);
    lv_obj_set_height(ui_VideoSettingImage9, 25);
    lv_obj_set_align(ui_VideoSettingImage9, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_VideoSettingImage9, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    
    //摄像头label
    ui_VideoSettingLabel3 = lv_label_create(ui_CameraSettingPanel);
    lv_obj_set_size(ui_VideoSettingLabel3, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_VideoSettingLabel3, LV_ALIGN_LEFT_MID, 11, 1);
    lv_label_set_text(ui_VideoSettingLabel3, CameraSetting[language_index]);
    lv_obj_set_style_text_color(ui_VideoSettingLabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VideoSettingLabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VideoSettingLabel3, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //右侧箭头
    ui_VideoSettingImage10 = lv_img_create(ui_CameraSettingPanel);
    lv_img_set_src(ui_VideoSettingImage10, &ui_img_rightarrow_png);
    lv_obj_set_size(ui_VideoSettingImage10, 11, 21);
    lv_obj_align(ui_VideoSettingImage10, LV_ALIGN_RIGHT_MID, -15, 0);
    lv_obj_add_flag(ui_VideoSettingImage10, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    /**********AI检测****************/
    ui_AIDetectPanel = lv_obj_create(ui_CameraSettingSupanel);
    lv_obj_set_size(ui_AIDetectPanel, 532, 56);
    lv_obj_set_pos(ui_AIDetectPanel, 12, 189);
    lv_obj_add_flag(ui_AIDetectPanel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_AIDetectPanel, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_AIDetectPanel, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AIDetectPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AIDetectPanel, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_AIDetectPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_AIDetectPanel, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_AIDetectPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AIDetectPanel, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_AIDetectPanel, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_AIDetectPanel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_AIDetectPanel, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    
    //AI指示图标--
    ui_VideoSettingImage11 = lv_img_create(ui_AIDetectPanel);
    lv_img_set_src(ui_VideoSettingImage11, &ui_img_ai_logo_png);
    lv_obj_set_width(ui_VideoSettingImage11, 32);
    lv_obj_set_height(ui_VideoSettingImage11, 32);
    lv_obj_set_align(ui_VideoSettingImage11, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_VideoSettingImage11, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    
    //AI检测Label
    ui_VideoSettingLabel4 = lv_label_create(ui_AIDetectPanel);
    lv_obj_set_size(ui_VideoSettingLabel4, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_VideoSettingLabel4, LV_ALIGN_LEFT_MID, 11, 1);
    lv_label_set_text(ui_VideoSettingLabel4, AIFunction[language_index]);
    lv_obj_set_style_text_color(ui_VideoSettingLabel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VideoSettingLabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VideoSettingLabel4, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //右侧箭头
    ui_VideoSettingImage12 = lv_img_create(ui_AIDetectPanel);
    lv_img_set_src(ui_VideoSettingImage12, &ui_img_rightarrow_png);
    lv_obj_set_size(ui_VideoSettingImage12, 11, 21);
    lv_obj_align(ui_VideoSettingImage12, LV_ALIGN_RIGHT_MID, -15, 0);
    lv_obj_add_flag(ui_VideoSettingImage12, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_VideoSettingImage12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags


    /**************更新提醒****************/    
    ui_SwitchUpdateReminder = lv_switch_create(ui_UpdateReminderPanel);
    lv_obj_set_width(ui_SwitchUpdateReminder, 54);
    lv_obj_set_height(ui_SwitchUpdateReminder, 26);
    lv_obj_align(ui_SwitchUpdateReminder, LV_ALIGN_RIGHT_MID, -14, 0);
    lv_obj_set_style_radius(ui_SwitchUpdateReminder, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchUpdateReminder, lv_color_hex(0x6D6D6D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchUpdateReminder, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SwitchUpdateReminder, lv_color_hex(0x252525), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchUpdateReminder, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_SwitchUpdateReminder, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_SwitchUpdateReminder, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(ui_SwitchUpdateReminder, 30, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchUpdateReminder, lv_color_hex(0x9D9D9D), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchUpdateReminder, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchUpdateReminder, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchUpdateReminder, 255, LV_PART_KNOB | LV_STATE_CHECKED);
    

    /*******************其他初始化操作*********************/
    // lv_obj_add_flag(ui_ButtonHomePage, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    // lv_obj_add_flag(ui_ButtonAxisMove, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    // lv_obj_add_flag(ui_ButtonFIleManage, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_add_event_cb(ui_NetworkSetBackBtn, ui_event_NetworkSetBackBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BindDeviceBackBtn, ui_event_BindDeviceBackBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_VideoListPanel, ui_event_VideoListPanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CameraSettingPanel, ui_event_CameraSettingPanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AIDetectPanel, ui_event_AIDetectPanel, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_NetworkSetting_Keyboard, ui_event_NetworkSetting_Keyboard, LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_CameraSubpaneBackBtn, ui_event_CameraSubpaneBackBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenSettings, ui_event_Pageload, LV_EVENT_SCREEN_LOADED, NULL);

    /****************修改的摄像头界面的内容********************/
    // lv_obj_add_flag(ui_VideoSettingPanel4, LV_OBJ_FLAG_HIDDEN);     /// Flags
    // lv_obj_add_flag(ui_VideoSettingImage6, LV_OBJ_FLAG_HIDDEN);     /// Flags
    // lv_obj_add_flag(ui_VideoSettingLabel1, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_add_flag(ui_VideoSettingImage7, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_add_flag(ui_VideoSettingImage9, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_add_flag(ui_VideoSettingImage11, LV_OBJ_FLAG_HIDDEN);     /// Flags
    
    switch (UIType)
    {

        case CR_K1:     
                lv_obj_add_flag(ui_LocalNetworkPanel, LV_OBJ_FLAG_HIDDEN);     /// Flags
                lv_obj_set_x(ui_NetworkListPanel, 0);
                lv_obj_set_y(ui_NetworkListPanel, 54);
                lv_obj_set_height(ui_NetworkListPanel, 290);
                break;
        case PF_05:   
        case CR_K1_Max:
                lv_obj_clear_flag(ui_LocalNetworkPanel, LV_OBJ_FLAG_HIDDEN);     /// Flags
                lv_obj_set_x(ui_NetworkListPanel, 0);
                lv_obj_set_y(ui_NetworkListPanel, 110);
                lv_obj_set_height(ui_NetworkListPanel, 235);//300
                break;
        default:
            break;
    }
}

// 熄屏操作
static char *ScreenOffListLabelSet(uint8_t item_index, uint8_t language_index)
{
    static char buff[150] = {0};
    memset(buff, 0, sizeof(buff));
    switch (item_index) {
    case 0:
        if (language_index == 0){
            sprintf(buff, "%s3%s", NoOptArray[language_index], MinuteArray[language_index]);
        }
        else {
            sprintf(buff, "3%s", MinuteArray[language_index]);
        }
        break;
    case 1:
        if (language_index == 0){
            sprintf(buff, "%s5%s", NoOptArray[language_index], MinuteArray[language_index]);
        } 
        else {
            sprintf(buff, "5%s", MinuteArray[language_index]);
        }
        break;
    case 2:
        if (language_index == 0){
            sprintf(buff, "%s",  NotSetArray[language_index]);
        }
        else {
            sprintf(buff, "%s", NotSetArray[language_index]);
        }       
        break;
    default:break;
    }    
    return buff;
}

static void ScreenOffTimeSelect(uint8_t item_index)
{
    char buff[150] = {0};
    ui_ScreenOffTimeIndex = item_index;
    uint8_t language_index = get_cur_language_index();
    sprintf(buff, "%s", ScreenOffListLabelSet(ui_ScreenOffTimeIndex, language_index));
    lv_label_set_text(ui_ScreenOffTimeLabel, buff);
    //printf("buff : %s\n", buff);
}

static settings_list_t *create_settings_list_item(lv_obj_t *parent, uint8_t index, int16_t pos_x, int16_t pos_y, void (*part_event_callback)(lv_event_t *))
{
    settings_list_t *part = (settings_list_t *)lv_mem_alloc(sizeof(settings_list_t));
    if ( !part )
        return NULL;

    lv_obj_t * ui_SettingItemPanelInfo = lv_obj_create(parent);
    lv_obj_set_width(ui_SettingItemPanelInfo, 545);//534
    lv_obj_set_height(ui_SettingItemPanelInfo, 56);
    lv_obj_set_x(ui_SettingItemPanelInfo, pos_x);
    lv_obj_set_y(ui_SettingItemPanelInfo, pos_y);
    lv_obj_add_flag(ui_SettingItemPanelInfo, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
   // lv_obj_align(ui_SettingItemPanelInfo, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_clear_flag(ui_SettingItemPanelInfo, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_SettingItemPanelInfo, lv_color_hex(0x18181B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SettingItemPanelInfo, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SettingItemPanelInfo, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SettingItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SettingItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_SettingItemPanelInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式设置
   // lv_obj_set_style_border_width(ui_SettingItemPanelInfo, 3, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui_SettingItemPanelInfo, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_opa(ui_SettingItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_SettingItemPanelInfo, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_SettingItemPanelInfo, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_SettingItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_pad_all(ui_SettingItemPanelInfo, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    part->part_panel = ui_SettingItemPanelInfo;
    
    //设置列表项名
    lv_obj_t * ui_SettingItemName = lv_label_create(ui_SettingItemPanelInfo);
    lv_obj_set_width(ui_SettingItemName, LV_SIZE_CONTENT); //261
    lv_obj_set_height(ui_SettingItemName, LV_SIZE_CONTENT); //30
    lv_obj_align(ui_SettingItemName, LV_ALIGN_LEFT_MID, 13, 1);
    lv_label_set_text(ui_SettingItemName,"");
     lv_obj_clear_flag(ui_SettingItemName, LV_OBJ_FLAG_SCROLLABLE); 
   // lv_label_set_text(ui_SettingItemName, ScreenBrightnessArray[language_index]);
    lv_obj_set_style_text_color(ui_SettingItemName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SettingItemName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SettingItemName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SettingItemName, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SettingItemName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_item_name = ui_SettingItemName;
    
    //右箭头图
    lv_obj_t *ui_ImageArrow = lv_img_create(ui_SettingItemPanelInfo);
    lv_img_set_src(ui_ImageArrow, &ui_img_rightarrow_png);
    lv_obj_set_width(ui_ImageArrow, 11);  //11 LV_SIZE_CONTENT
    lv_obj_set_height(ui_ImageArrow, 21);    
    lv_obj_align(ui_ImageArrow, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageArrow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    part->img_arrow_png = ui_ImageArrow;

    //设置列表内容
    lv_obj_t * ui_SettingContentName = lv_label_create(ui_SettingItemPanelInfo);
    lv_obj_set_width(ui_SettingContentName, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SettingContentName, LV_SIZE_CONTENT); //39
    lv_obj_align(ui_SettingContentName, LV_ALIGN_RIGHT_MID, -40, 1);
    //lv_obj_align_to(ui_SettingContentName, ui_ImageArrow, LV_ALIGN_OUT_LEFT_MID, -20, 0);
    lv_label_set_text(ui_SettingContentName,"");
    lv_obj_set_style_text_color(ui_SettingContentName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SettingContentName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SettingContentName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SettingContentName, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SettingContentName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_SettingContentName, LV_OBJ_FLAG_SCROLLABLE);

    part->label_content_name = ui_SettingContentName;

    part->index = index;
    lv_obj_add_event_cb(ui_SettingItemPanelInfo, part_event_callback, LV_EVENT_ALL, part); //事件回调接口
    
    return part;
}

//页面切换函数
void ui_event_Pageload(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        lv_event_code_t event_code = lv_event_get_code(e);
        lv_obj_t * target = lv_event_get_target(e);
        if(refresh_camera_flag)
        {
            refresh_camera_flag = false;
            // if(!system_state.Camera_model_state)
            // {
            //     CrLogI("don't have camera hidden the camera title");
            //     lv_obj_add_flag(ui_CamerasettingBtn, LV_OBJ_FLAG_HIDDEN);
            // }
        }
        CrLogI("refresh the systemsetting\n");
        get_printer_data(0x14,1,"\0");
        get_printer_data(0x06,1,"9");
        get_printer_data(0x06,1,"e"); //获取屏幕亮度
        get_printer_data(0x06,1,"b");//屏幕保护时间
        // get_printer_data(0x1a,1,"1");//查询OTA版本升级信息
        // systemsettingflag = true;   //OTA查询版本标志量
   
    }
}

static void ui_event_ButtonHomePage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        // Your code here
        if ( home_printing_is_printing_finished() )
            LoadHomeNormalScreen();
        else
            LoadHomePrintingScreen();
    }
    if(event_code == LV_EVENT_FOCUSED) {
        send_buzzer(0x01);
        // Your code here
        if ( home_printing_is_printing_finished() )
            LoadHomeNormalScreen();
        else
            LoadHomePrintingScreen();
    }

}
void ui_event_ButtonAxisMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        if ( home_printing_is_printing_finished() )
            LoadAxisMoveScreen();
        else
            LoadAxisMoveScreen();
    }
    if(event_code == LV_EVENT_FOCUSED) {  
         send_buzzer(0x01);
        if ( home_printing_is_printing_finished() )
            LoadAxisMoveScreen();
        else
            LoadAxisMoveScreen(); 
    }
}
void ui_event_ButtonFIleManage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //LoadFileManageScreen();
        LoadFileManageScreenAndObjs(false);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
       // LoadFileManageScreen(); 
        LoadFileManageScreenAndObjs(false);
    }
}

lv_timer_t * SettingNavTimer;
void SettingNavTimerCb(lv_timer_t * timer)
{
  /*Use the user_data*/
    lv_group_focus_freeze(encoder_group, false);
    lv_timer_del(SettingNavTimer);
    SettingNavTimer = NULL;
}

void ui_event_ButtonSettings(lv_event_t * e)
{
    bool IsEntered = false;
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
       
        send_buzzer(0x01);
       // LoadSettingsScreen();
        IsEntered = ScreenSettings.stateValue;
        IsEntered = !IsEntered;
        LoadSettingsScreenAndObjs(IsEntered, SCREEN_SETTINGS_BUTTON);
        // _ui_screen_change(ui_Cameralist, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
    // if(event_code == LV_EVENT_DEFOCUSED)
    // {
    //     if (ScreenSettings.stateValue)
    //     {
    //         lv_obj_set_style_bg_img_src(ui_ButtonSettings, &ui_img_pagesettingselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     }
    // }
    // if(event_code == LV_EVENT_FOCUSED)
    // {
    //     lv_obj_set_style_bg_img_src(ui_ButtonSettings, &ui_img_pagesettingselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     // if (ScreenSettings.stateValue)
    //     // {
    //     //     lv_obj_set_style_bg_img_src(ui_ButtonSettings, &ui_img_pagesettingfocus_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     //     if (page_manager.objFreezzFlag == false)
    //     //     {
    //     //         page_manager.objFreezzFlag = true;
    //     //     }
    //     //     else if (page_manager.objFreezzFlag == true)
    //     //     {
    //     //         lv_group_focus_freeze(encoder_group, true);
    //     //         if(SettingNavTimer == NULL)
    //     //             SettingNavTimer = lv_timer_create(SettingNavTimerCb, 300,  NULL);
    //     //     }
    //     // }
    // }
}

void ui_event_ButtonReserve(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        // _ui_screen_change(ui_Cameralist, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        //LoadCustomerServiceScreen();
        LoadServiceScreenAndObjs(false);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
       // LoadCustomerServiceScreen();   
        LoadServiceScreenAndObjs(false);
    }
}

void ui_event_SettingTitlePrePage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_LONG_PRESSED) {
        //FilePageReserveBtnClicked(e);
        //printf("SettingTitlePrePage-LV_EVENT_LONG_PRESSED \n");
    }
}

/**
 * @description: 视频列表面板事件
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_VideoListPanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        LoadPage(ui_Cameralist, 0);
         //_ui_screen_change(ui_Cameralist, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0); 
    }
}

/**
 * @description: 摄像头设置面板事件
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_CameraSettingPanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_camerasetting, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0); 
        LoadPage(ui_camerasetting, 0);
        send_get_camera_delayed_photography();
        send_get_camera_render_method_photoes();
        send_get_camera_shoot_freq();
        send_get_camera_shoot_pos();
    }
}

/**
 * @description: AI 检测面板事件
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_AIDetectPanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //LoadAiDetectionScreen();
         LoadPage(ui_ScreenAI, 0);
    }
}

//更改屏幕亮度
void ui_event_SystemsettingSlider1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        send_buzzer(0x01);
        // 获取滑块的当前值
        int lightvalue = lv_slider_get_value(target);
        char temp[5] = {0};
        snprintf(temp,5,"e%d",lightvalue);
        set_printer_data(0x06,strlen(temp),temp);
    }

}

//全屏开关处理
void ui_event_SystemsettingSwitch1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        send_buzzer(0x01);
        if(lv_obj_has_state(ui_SystemsettingSwitch1,LV_STATE_CHECKED))
        {
            set_printer_data(0x06,2,"j1");
            CrLogI("open the fullscreen mode");
        }
        else
        {
            set_printer_data(0x06,2,"j0");
            CrLogI("close the fullscreen mode");
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

void ui_event_CloseNetworkKeyboard(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_obj_add_flag(ui_NetworkSettingPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    }
}


//外部接口-加载设置页面
void LoadSettingsScreen(void)
{
    _ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

/**
 * @description: 设置网络 ‘2’断开已连接的网络
                         ‘1’连接已保存的网络
 * @return {*}
 * @param {lv_event_t} *e
 */
static void wifi_select_btn_ok_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    wifi_list_t *userdata = lv_event_get_user_data(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(userdata->wifi_type == 2) //断开已连接的网络
            {
                char ctemp[256] = {0};
                snprintf(ctemp, 256, "2\t%s", lv_label_get_text(userdata->wifi_name));
                set_printer_data(0x07,strlen(ctemp),ctemp);
                wifi_wait_animmotion(6);
                get_printer_data(0x07, 1, "2"); //获取 wifi 列表
                wifiListRefreshTimesFlag = true;
            } 
            else if(userdata->wifi_type == 1) //连接已保存的网络
            {
                char ctemp[256] = {0};
                snprintf(ctemp, 256, "1\t%s", lv_label_get_text(userdata->wifi_name));
                set_printer_data(0x07,strlen(ctemp),ctemp);
                wifi_wait_animmotion(6);
                get_printer_data(0x07, 1, "2");
                wifiListRefreshTimesFlag = true;
            }
            lv_obj_add_flag(ui_NetworkDialog, LV_OBJ_FLAG_HIDDEN);
            DeinitPopoutManager(&BtnDialogPopout);
            if (IsThereAnyPopout())
            {
                ManagePopoutFocus();
            }
            else
            {
                //BackPrepage(true);
                NetworkPageAaaFocusObjs();
            }
            CrLogI("hidden the msgbox,%p",ui_NetworkDialog);
    
        }
            break;
        default:
            break;
	}
}

/**
 * @description: 忘记该网络处理
 * @return {*}
 * @param {lv_event_t} *e
 */
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
                wifi_wait_animmotion(6);
                get_printer_data(0x07, 1, "2");
                wifiListRefreshTimesFlag = true;
            }
            lv_obj_add_flag(ui_NetworkDialog, LV_OBJ_FLAG_HIDDEN);
            CrLogI("wifi_select_btn_cancel_event_handler BackPrepage(true)");
            DeinitPopoutManager(&BtnDialogPopout);
            if (IsThereAnyPopout())
            {
                ManagePopoutFocus();
            }
            else
            {
               // BackPrepage(true);
               NetworkPageAaaFocusObjs();
            }
            CrLogI("hidden the msgbox,%p",ui_NetworkDialog);
        }
            break;
        default:
            break;
	}
}

static void wifi_select_btn_quit_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    wifi_list_t *user_data = lv_event_get_user_data(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            CrLogI("hidden the msgbox,%p",ui_NetworkDialog);
            lv_obj_add_flag(ui_NetworkDialog, LV_OBJ_FLAG_HIDDEN);
            CrLogI("wifi_select_btn_quit_event_handler BackPrepage(true)");
             DeinitPopoutManager(&BtnDialogPopout);
            if (IsThereAnyPopout())
            {
                ManagePopoutFocus();
            }
            else
            {
                // BackPrepage(true);
                NetworkPageChangeObjs(); //TODO:目前取消按钮退出时选择改变静态的聚焦对象，不去调用BackPrepage 获取WiFi 列表
                lv_group_focus_obj(user_data->parent);
            }
        }
            break;
        default:
            break;
	}
}

static void wifi_select_btn_infomation_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_obj_add_flag(ui_NetworkDialog, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
            _ui_screen_change(ui_NetworkInfo, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        }
            break;
        default:
            break;
	}
}

static void WifiDialogAddFocusObjs(void)
{
    //lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    lv_group_remove_all_objs(encoder_group);
    lv_group_add_obj(encoder_group, ui_NetworkDialog_btn_1);
    lv_group_add_obj(encoder_group, ui_NetworkDialog_btn_2);
    lv_group_add_obj(encoder_group, ui_NetworkDialog_btn_3);
}

void wifi_msgbox(unsigned char flag,lv_obj_t * obj, wifi_list_t * wifi)
{
    uint8_t language_index = get_cur_language_index();
    if (!IsThereAnyPopout())
    {
        RecordObjBeforePopup();
    }
    if (ui_NetworkDialog == NULL)
    {
        ui_NetworkDialog = lv_obj_create(ui_ScreenSettings);
       // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_size(ui_NetworkDialog, 640, 360);
        lv_obj_set_pos(ui_NetworkDialog, 0, 60);
        lv_obj_add_style(ui_NetworkDialog, &style_cont_msgbox, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_NetworkDialog, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_NetworkDialog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

        ui_NetworkDialogPanel = lv_obj_create(ui_NetworkDialog);
        lv_obj_set_size(ui_NetworkDialogPanel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        //lv_obj_set_size(ui_NetworkDialogPanel, 96, 168);
        //lv_obj_align_to(ui_NetworkDialogPanel, obj, LV_ALIGN_OUT_BOTTOM_RIGHT,0,0);
        lv_obj_clear_flag(ui_NetworkDialogPanel, LV_OBJ_FLAG_SCROLLABLE);  
        lv_obj_align(ui_NetworkDialogPanel, LV_ALIGN_RIGHT_MID, -15, 0);
        lv_obj_set_style_radius(ui_NetworkDialogPanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_NetworkDialogPanel, lv_color_hex(0x3C3E42), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_NetworkDialogPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_NetworkDialogPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(ui_NetworkDialogPanel, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_NetworkDialogPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_layout(ui_NetworkDialogPanel, LV_LAYOUT_FLEX);
        lv_obj_set_flex_flow(ui_NetworkDialogPanel, LV_FLEX_FLOW_COLUMN);

        //btn_1
        ui_NetworkDialog_btn_1 = lv_btn_create(ui_NetworkDialogPanel);
        lv_obj_set_size(ui_NetworkDialog_btn_1, 96, 56);
        lv_obj_set_style_radius(ui_NetworkDialog_btn_1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_NetworkDialog_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_style(ui_NetworkDialog_btn_1, &StyleDialogBtnDefault, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_add_style(ui_NetworkDialog_btn_1, &StyleDialogFocusBtn, LV_PART_MAIN|LV_STATE_FOCUS_KEY);
      
        
        ui_NetworkDialog_btn_1_label = lv_label_create(ui_NetworkDialog_btn_1);
        if(flag == 0) //断开连接
            lv_label_set_text(ui_NetworkDialog_btn_1_label, DisconnectOptArray[language_index]);
        else
            lv_label_set_text(ui_NetworkDialog_btn_1_label, ConnectOptArray[language_index]);
        lv_obj_set_style_text_color(ui_NetworkDialog_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_NetworkDialog_btn_1_label, lv_font24.font, LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_NetworkDialog_btn_1, 0, LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_NetworkDialog_btn_1_label, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT);
        lv_obj_align(ui_NetworkDialog_btn_1_label, LV_ALIGN_CENTER, 0, 0);
        // redefine_label_size(ui_NetworkDialog_btn_1_label, lv_font24.font, 0, 0, 240, 0);
        // lv_obj_update_layout(ui_NetworkDialog_btn_1_label);
        // redefine_widgets_size(ui_NetworkDialog_btn_1, ui_NetworkDialog_btn_1_label, 5, 0, 96, 60);

        //btn_2
        ui_NetworkDialog_btn_2 = lv_btn_create(ui_NetworkDialogPanel);
        lv_obj_set_size(ui_NetworkDialog_btn_2, 96, 56);
        lv_obj_set_style_shadow_width(ui_NetworkDialog_btn_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_NetworkDialog_btn_2, 0, LV_STATE_DEFAULT);
        lv_obj_add_style(ui_NetworkDialog_btn_2, &StyleDialogBtnDefault, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_add_style(ui_NetworkDialog_btn_2, &StyleDialogFocusBtn, LV_PART_MAIN|LV_STATE_FOCUS_KEY);
        
        ui_NetworkDialog_btn_2_label = lv_label_create(ui_NetworkDialog_btn_2);
        lv_label_set_text(ui_NetworkDialog_btn_2_label, ForgetPasswordArray[language_index]);
        lv_obj_set_style_text_color(ui_NetworkDialog_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_NetworkDialog_btn_2_label, lv_font24.font, LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_NetworkDialog_btn_2_label, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT);
        lv_obj_align(ui_NetworkDialog_btn_2_label, LV_ALIGN_CENTER, 0, 0);
        // redefine_label_size(ui_NetworkDialog_btn_2_label, lv_font24.font, 0, 0, 240, 0);
        // lv_obj_update_layout(ui_NetworkDialog_btn_2_label);
        // redefine_widgets_size(ui_NetworkDialog_btn_2, ui_NetworkDialog_btn_2_label, 5, 0, 96, 60);

        //取消按钮
        ui_NetworkDialog_btn_3 = lv_btn_create(ui_NetworkDialogPanel);
        lv_obj_set_size(ui_NetworkDialog_btn_3, 96, 56);
        lv_obj_set_style_shadow_width(ui_NetworkDialog_btn_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_NetworkDialog_btn_3, 0, LV_STATE_DEFAULT);
        lv_obj_add_style(ui_NetworkDialog_btn_3, &StyleDialogBtnDefault, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_add_style(ui_NetworkDialog_btn_3, &StyleDialogFocusBtn, LV_PART_MAIN|LV_STATE_FOCUS_KEY);
        
        ui_NetworkDialog_btn_3_label = lv_label_create(ui_NetworkDialog_btn_3);
        lv_label_set_text(ui_NetworkDialog_btn_3_label, Cancel[language_index]);
        lv_obj_set_style_text_color(ui_NetworkDialog_btn_3_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_NetworkDialog_btn_3_label, lv_font24.font, LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_NetworkDialog_btn_3_label, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT);
        lv_obj_align(ui_NetworkDialog_btn_3_label, LV_ALIGN_CENTER, 0, 0);
        // redefine_label_size(ui_NetworkDialog_btn_3_label, lv_font24.font, 0, 0, 240, 0);
        // lv_obj_update_layout(ui_NetworkDialog_btn_3_label);
        // redefine_widgets_size(ui_NetworkDialog_btn_3, ui_NetworkDialog_btn_3_label, 5, 0, 96, 60);  
        lv_obj_add_flag(ui_NetworkDialog,LV_OBJ_FLAG_HIDDEN);
    }
    if (lv_obj_has_flag(ui_NetworkDialog,LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(ui_NetworkDialog,LV_OBJ_FLAG_HIDDEN);
        if(flag == 0)
            lv_label_set_text(ui_NetworkDialog_btn_1_label, DisconnectOptArray[language_index]);
        else
            lv_label_set_text(ui_NetworkDialog_btn_1_label, ConnectOptArray[language_index]);
        redefine_label_size(ui_NetworkDialog_btn_1_label, lv_font24.font, 0, 0, 240, 0);
        lv_obj_update_layout(ui_NetworkDialog_btn_1_label);
        redefine_widgets_size(ui_NetworkDialog_btn_1, ui_NetworkDialog_btn_1_label, 10, 0, 96, 60);

        lv_label_set_text(ui_NetworkDialog_btn_2_label, ForgetPasswordArray[language_index]);
        redefine_label_size(ui_NetworkDialog_btn_2_label, lv_font24.font, 0, 0, 240, 0);
        lv_obj_update_layout(ui_NetworkDialog_btn_2_label);
        redefine_widgets_size(ui_NetworkDialog_btn_2, ui_NetworkDialog_btn_2_label, 10, 0, 96, 60);
        
        redefine_label_size(ui_NetworkDialog_btn_3_label, lv_font24.font, 0, 0, 240, 0);
        lv_obj_update_layout(ui_NetworkDialog_btn_3_label);
        redefine_widgets_size(ui_NetworkDialog_btn_3, ui_NetworkDialog_btn_1_label, 10, 0, 96, 60);
        lv_coord_t width  = lv_obj_get_width(ui_NetworkDialog_btn_1) > lv_obj_get_width(ui_NetworkDialog_btn_2) ? lv_obj_get_width(ui_NetworkDialog_btn_1) : lv_obj_get_width(ui_NetworkDialog_btn_2);
        lv_obj_set_width(ui_NetworkDialog_btn_1, width);
        lv_obj_set_width(ui_NetworkDialog_btn_2, width);
        lv_obj_set_width(ui_NetworkDialog_btn_3, width);

    }
    lv_obj_add_event_cb(ui_NetworkDialog_btn_1, wifi_select_btn_ok_event_handler, LV_EVENT_ALL, wifi);
    lv_obj_add_event_cb(ui_NetworkDialog_btn_2, wifi_select_btn_cancel_event_handler, LV_EVENT_ALL, wifi);
    lv_obj_add_event_cb(ui_NetworkDialog_btn_3, wifi_select_btn_quit_event_handler, LV_EVENT_ALL, wifi);

    InitPopoutManager(&BtnDialogPopout, ui_NetworkDialog, WifiDialogAddFocusObjs);
    BtnDialogPopout.obj1_flag = true;
    BtnDialogPopout.obj2_flag = true;
    BtnDialogPopout.obj3_flag = true;
    BtnDialogPopout.popout_focus_obj1 = ui_NetworkDialog_btn_1;
    BtnDialogPopout.popout_focus_obj2 = ui_NetworkDialog_btn_2;
    BtnDialogPopout.popout_focus_obj3 = ui_NetworkDialog_btn_3;
    // Add3rLeveldObjsCb = WifiDialogAddFocusObjs;
    // LoadPage(ui_ScreenSettings, 3);
    //弹框聚焦对象处理
    ManagePopoutFocus();

}

void ui_event_NetworkSetting_Keyboard(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
    if(event_code == LV_EVENT_KEY) 
    {
        char c = *((char *)lv_event_get_param(e));
        if (c==LV_KEY_LEFT)
        {
            //printf("LV_KEY_LEFT\n");

        }
        if (c==LV_KEY_RIGHT)
        {
           // printf("LV_KEY_RIGHT\n");
        }
    }
    if(event_code == LV_EVENT_DRAW_PART_BEGIN) 
    {
        lv_obj_draw_part_dsc_t * dsc = lv_event_get_param(e);
        dsc->rect_dsc->bg_color = lv_color_hex(0x696F75);
        dsc->rect_dsc->radius = 3;
        dsc->rect_dsc->shadow_width = 6;
        dsc->rect_dsc->shadow_ofs_x = 0;
        dsc->rect_dsc->shadow_ofs_y = 3;
        dsc->rect_dsc->shadow_color = lv_color_hex(0x000000);
        dsc->rect_dsc->shadow_opa = 255;
        if (dsc->id == 10 || dsc->id == 20)
        {
            dsc->rect_dsc->bg_color = lv_color_hex(0x393D44);
            dsc->rect_dsc->bg_opa = 0;
            dsc->rect_dsc->shadow_width = 0;
            dsc->rect_dsc->shadow_ofs_x = 0;
            dsc->rect_dsc->shadow_ofs_y = 0;
        }
        else if (dsc->id == 21)
        {
            dsc->rect_dsc->bg_color = lv_color_hex(0x515A64);
            dsc->rect_dsc->bg_opa = 255;
            if (!keyboard_spec_flag)
                dsc->label_dsc->opa = 0;
            else
                dsc->label_dsc->opa = 255;
        }
        else if (dsc->id == 29)
        {
            dsc->label_dsc->opa = 0;
        }
        else if(dsc->id == 30 || dsc->id == 32) {
            dsc->rect_dsc->bg_color = lv_color_hex(0x515A64);
            dsc->rect_dsc->bg_opa = 255;
        }
      

        if(lv_btnmatrix_get_selected_btn(target) == dsc->id) //键盘选中后样式修改
        {
            //printf("LV_EVENT_DRAW_PART_BEGIN dsc->id :%d\n", dsc->id);
            //dsc->rect_dsc->bg_color = lv_color_hex(0xFF954D);
            //dsc->rect_dsc->bg_color = lv_color_hex(0x42BDD8);
            dsc->rect_dsc->border_color = lv_color_hex(0xCDF6FF);
            dsc->rect_dsc->border_opa = 255;
            dsc->rect_dsc->border_width = 2;
            // dsc->rect_dsc->outline_color = lv_color_hex(0xCDF6FF);
            dsc->rect_dsc->outline_width = 0;
            //dsc->label_dsc->color = lv_color_hex(0x42BDD8);
        }
        else if(dsc->id == 21) {
            if (!keyboard_spec_flag)
            {
                dsc->label_dsc->opa = LV_OPA_TRANSP; /*Hide the text if any*/
            }
            else
            {
                dsc->label_dsc->opa = LV_OPA_COVER; 
            }
        }
        else if (dsc->id == 29)
        {
            dsc->label_dsc->opa = LV_OPA_TRANSP; /*Hide the text if any*/
        }
     
    }
    if(event_code == LV_EVENT_DRAW_PART_END) {
         if(dsc->id == 21 && !keyboard_spec_flag) {
            
            lv_img_header_t header;
            lv_res_t res = lv_img_decoder_get_info(&ui_img_keyboard_case, &header);
            if(res != LV_RES_OK) return;

            lv_area_t a;
            a.x1 = dsc->draw_area->x1 + (lv_area_get_width(dsc->draw_area) - header.w) / 2;
            a.x2 = a.x1 + header.w - 1;
            a.y1 = dsc->draw_area->y1 + (lv_area_get_height(dsc->draw_area) - header.h) / 2;
            a.y2 = a.y1 + header.h - 1;

            lv_draw_img_dsc_t img_draw_dsc;
            lv_draw_img_dsc_init(&img_draw_dsc);
            img_draw_dsc.recolor = lv_color_black();
            if(lv_btnmatrix_get_selected_btn(target) == dsc->id)  img_draw_dsc.recolor_opa = LV_OPA_30;
             lv_draw_img(dsc->draw_ctx, &img_draw_dsc, &a, &ui_img_keyboard_case);
         }
         if(dsc->id == 29) {
            
            lv_img_header_t header;
            lv_res_t res = lv_img_decoder_get_info(&ui_img_keyboard_backspace, &header);
            if(res != LV_RES_OK) return;

            lv_area_t a;
            a.x1 = dsc->draw_area->x1 + (lv_area_get_width(dsc->draw_area) - header.w) / 2;
            a.x2 = a.x1 + header.w - 1;
            a.y1 = dsc->draw_area->y1 + (lv_area_get_height(dsc->draw_area) - header.h) / 2;
            a.y2 = a.y1 + header.h - 1;

            lv_draw_img_dsc_t img_draw_dsc;
            lv_draw_img_dsc_init(&img_draw_dsc);
            img_draw_dsc.recolor = lv_color_black();
            if(lv_btnmatrix_get_selected_btn(target) == dsc->id)  img_draw_dsc.recolor_opa = LV_OPA_30;
             lv_draw_img(dsc->draw_ctx, &img_draw_dsc, &a, &ui_img_keyboard_backspace);
         }
    }
    
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        send_buzzer(0x01);
   
        uint32_t id = lv_btnmatrix_get_selected_btn(target);
        //CrLogI("keyboard input id: %d",id);
        
        const char * txt = lv_btnmatrix_get_btn_text(target, lv_btnmatrix_get_selected_btn(target));
        if(txt == NULL) return;

        if (strcmp(txt, "flag1") == 0)
        {
            lv_btnmatrix_set_map(target, kb_map[KEYBOARD_MODE_TEXT_UPPER]);
            return;
        }
        else if (strcmp(txt, "flag2") == 0)
        {
            lv_btnmatrix_set_map(target, kb_map[KEYBOARD_MODE_TEXT_LOWER]);
            return;
        }
        else if(strcmp(txt, "123") == 0) {
            lv_btnmatrix_set_map(target, kb_map[KEYBOARD_MODE_NUM]);
            keyboard_spec_flag = true;
            return;
        }
        else if(strcmp(txt, "ABC") == 0) {
            lv_btnmatrix_set_map(target, kb_map[KEYBOARD_MODE_TEXT_LOWER]);
            keyboard_spec_flag = false;
            return;
        }
        else if(strcmp(txt, "#+=") == 0) {
            lv_btnmatrix_set_map(target, kb_map[KEYBOARD_MODE_SPECIAL]);
            return;
        }
        else if(strcmp(txt, "flag3") == 0) {
            lv_textarea_del_char(lv_keyboard_get_textarea(target));
        }
        else if(strcmp(txt, "Ender") == 0) { //回车确认
            if(lv_keyboard_get_textarea(target) == ui_NetworkPassw_TextArea)
            {
                char ctemp[WIFI_NAME_LEN+4+63] = {0};
                strcat(ctemp, "0\t");
                strcat(ctemp, lv_textarea_get_text(ui_NetworkName_TextArea));
                strcat(ctemp, "\t");

                const char *passw = lv_textarea_get_text(ui_NetworkPassw_TextArea);
                if(passw != NULL)
                {
                    if((strlen(passw) < 8 && strlen(passw) != 0) || strlen(passw) > 64)
                    {
                        create_msgbox(PasswordLenLimit[get_cur_language_index()], NULL, 1000, lv_scr_act());
                        wifi_wait_animmotion(6);
                        get_printer_data(0x07, 1, "2");
                        wifiListRefreshTimesFlag = true;
                        lv_obj_add_flag(ui_NetworkSettingPanel, LV_OBJ_FLAG_HIDDEN);
                        lv_group_set_editing(encoder_group, 0); //退出编辑模式
                        DeinitPopoutManager(&BtnDialogPopout);
                        if (IsThereAnyPopout())
                            ManagePopoutFocus();
                        else
                        { 
                            BackPrepage(false); 
                        }
                        return;
                    }
                    strcat(ctemp, passw);
                    set_printer_data(0x07,strlen(ctemp),ctemp);
                    wifi_wait_animmotion(6);
                    get_printer_data(0x07, 1, "2");
                    wifiListRefreshTimesFlag = true;
                    lv_obj_add_flag(ui_NetworkSettingPanel, LV_OBJ_FLAG_HIDDEN);
                    lv_group_set_editing(encoder_group, 0); //退出编辑模式
                }
                else
                {
                    create_msgbox(PasswordError[get_cur_language_index()], NULL, 1000, lv_scr_act());
                }
               
                DeinitPopoutManager(&BtnDialogPopout);
                if (IsThereAnyPopout())
                {
                    ManagePopoutFocus();
                }
                else
                {
                    BackPrepage(false);  
                }
            }
            if(lv_keyboard_get_textarea(target) == ui_NetworkName_TextArea)
            {
                lv_keyboard_set_textarea(ui_NetworkSetting_Keyboard, ui_NetworkPassw_TextArea);
                lv_textarea_set_text(ui_NetworkPassw_TextArea,"");
                lv_obj_add_state(ui_NetworkPassw_TextArea, LV_STATE_FOCUSED);
                lv_obj_clear_state(ui_NetworkName_TextArea, LV_STATE_FOCUSED);
                lv_group_remove_all_objs(encoder_group);
                lv_group_add_obj(encoder_group, ui_NetworkSetting_Keyboard);
                lv_group_set_editing(encoder_group, 1);
            }
        }
        else
        {
            const char * txt = lv_btnmatrix_get_btn_text(target, id);
            lv_textarea_add_text(lv_keyboard_get_textarea(target), txt);
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
            if (!IsThereAnyPopout())
            {
                RecordObjBeforePopup();
            }
            switch(wifilist_state)
            {
                case 3:
                {
                    CrLogI("create the hidden network connect");
                    create_wificonect_page(lv_scr_act(), "", true);
                    lv_keyboard_set_textarea(ui_NetworkSetting_Keyboard, ui_NetworkName_TextArea);

                    // lv_group_remove_all_objs(encoder_group);
                    // lv_group_add_obj(encoder_group, ui_NetworkSetting_Keyboard);
                    
                    InitPopoutManager(&BtnDialogPopout, ui_NetworkSettingPanel, NetworkSettingPageChangeObjs);
                    BtnDialogPopout.obj1_flag = true;
                    BtnDialogPopout.popout_focus_obj1 = ui_NetworkSetting_Keyboard;
                    //弹框聚焦对象处理
                    ManagePopoutFocus();
                    lv_group_set_editing(encoder_group, 1);
                    break;
                }
                case 2:
                    CrLogI("create the wifidialog2");
                    wifi_msgbox(0, obj, user_data);
                    break;
                case 1:
                    CrLogI("create the wifidialog1");
                    wifi_msgbox(1, obj, user_data);
                    break;
                case 0:
                {
                     CrLogI("create the new network connect");
                    // lv_obj_clear_flag(ui_NetworkSettingPanel, LV_OBJ_FLAG_HIDDEN);
                    // lv_label_set_text(ui_NetworkName_TextArea,wifilist_name);
                    // lv_obj_add_state(ui_NetworkPassw_TextArea, LV_STATE_FOCUSED);
                    // lv_textarea_set_text(ui_NetworkPassw_TextArea,"");
                    create_wificonect_page(lv_scr_act(), wifilist_name, false);
                    lv_keyboard_set_textarea(ui_NetworkSetting_Keyboard, ui_NetworkPassw_TextArea);
                    // lv_group_remove_all_objs(encoder_group);
                    // lv_group_add_obj(encoder_group, ui_NetworkSetting_Keyboard);
                    InitPopoutManager(&BtnDialogPopout, ui_NetworkSettingPanel, NetworkSettingPageChangeObjs);
                    BtnDialogPopout.obj1_flag = true;
                    BtnDialogPopout.popout_focus_obj1 = ui_NetworkSetting_Keyboard;
                    //弹框聚焦对象处理
                    ManagePopoutFocus();
                    lv_group_set_editing(encoder_group, 1);
                    break;
                }
                default:
                    break;
            }
          
        break;
        }
        default:
            break;
    }
}

/**
 * @description: wifi刷新显示
 * @return {*}
 * @param {char} *data
 * @param {int} len
 */
void show_wifi_list(char *data,int len)
{
    char dis_wifi_name[60];
    char wifi_type[10] = {0};
    char wifi_dis[10] = {0};
    bool flag;
    unsigned char i = 0,k = 0;
    unsigned int WiFiListYOffset = 0;
    
    if (lv_obj_has_flag(ui_NetworkSettingsPanel, LV_OBJ_FLAG_HIDDEN))
    {
        return;
    }
    //lv_obj_clear_flag(ui_NetworkListPanel, LV_OBJ_FLAG_HIDDEN);
    if (!wifiListRefreshTimesFlag) return;
    // {
    //     wifiListRefreshTimesFlag = false;
    // }
    // else
    // {
    //     return;
    // }

    CrLogI("refresh wifi list");

    NetworkPageAaaFocusObjs();

    CrLogI("get data : %s",data);
    char *temp = strtok(data,"\t");
    lv_obj_clean(ui_NetworkListPanel);
    memset(list_array, 0, 100 * sizeof(wifi_list_t));
    k = 0;
    
    while(temp)
    {
        CrLogI("single wifi data : %s,%d",temp,k);
        flag = false;
        int result = sscanf(temp, "%[^:]:%[^:]:%[^:]",dis_wifi_name, wifi_type, wifi_dis);
        if( result < 3)
        {
            CrLogE("explain the wifi data error,result count:%d",result);
            return;
        }
        CrLogI("single wifi name : %s",dis_wifi_name);
        CrLogI("single wifi type : %s",wifi_type);
        CrLogI("single wifi dis : %s",wifi_dis);

        if(k >= WIFI_MAX_NUMBER) return;
        list_array[k] = create_wifi_list_item(ui_NetworkListPanel, LV_ALIGN_TOP_LEFT, 14, WiFiListYOffset);
        NetworkListUpdateFocusObjs(k);
        switch(wifi_type[0]){
            case '2':{ //正在使用的wifi
                WiFiListYOffset = 94;  
                //设置wifi名字并更新相关图片
                 wifiListRefreshTimesFlag = false;
               // lv_obj_set_height(list_array[k]->parent, 94); //修改wifi列表顶层高度显示ip地址
                // lv_obj_set_style_bg_color(list_array[k]->parent, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT); 
                // lv_obj_set_style_border_width(list_array[k]->parent, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                // lv_obj_set_style_border_color(list_array[k]->parent, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_DEFAULT);
                // lv_obj_set_style_radius(list_array[k]->parent, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                // lv_obj_set_style_pad_all(list_array[k]->parent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            

                lv_obj_align(list_array[k].wifi_name,LV_ALIGN_TOP_LEFT, 11, 0);//
                lv_obj_align_to(list_array[k].wifi_info,list_array[k].wifi_name,LV_ALIGN_OUT_BOTTOM_LEFT, 1, 18);

                lv_label_set_text(list_array[k].wifi_name,dis_wifi_name);
                lv_label_set_text(list_array[k].wifi_info,wifi_ip);
                lv_obj_set_style_text_color(list_array[k].wifi_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                
                lv_obj_clear_flag(list_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(list_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(list_array[k].wifi_state, &ui_img_wificheckstate_png);
                lv_obj_align_to(list_array[k].wifi_state, list_array[k].wifi_logo, LV_ALIGN_OUT_LEFT_MID,-18, -1);
                //lv_img_set_src(list_array[k].wifi_logo, &ui_img_wifi_state_png);
                set_wifi_list_status(list_array[k].wifi_logo, atoi(wifi_dis));
                // lv_img_set_src(list_array[k]->wifi_info,&ui_img_wifi_info_png);
                //绑定事件
                list_array[k].wifi_type = 2;
                lv_obj_add_event_cb(list_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &list_array[k]);
                k++;
                break;                    
            }
            case '1':{ //连接过保存的wifi
                //设置wifi名字并更新相关图片
                // lv_obj_set_style_bg_color(list_array[k]->parent, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT); 
                // lv_obj_set_style_border_width(list_array[k]->parent, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                // lv_obj_set_style_border_color(list_array[k]->parent, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_DEFAULT);
                // lv_obj_set_style_radius(list_array[k]->parent, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                // lv_obj_set_style_pad_all(list_array[k]->parent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                WiFiListYOffset += 60;
                lv_label_set_text(list_array[k].wifi_name,dis_wifi_name);
                lv_obj_set_style_text_color(list_array[k].wifi_name,lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_clear_flag(list_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(list_array[k].wifi_state,&ui_img_wifi_state_1_png); //连接过显示锁图标
                lv_obj_align_to(list_array[k].wifi_state, list_array[k].wifi_logo, LV_ALIGN_OUT_LEFT_MID,-18, -1);
                //lv_img_set_src(list_array[k].wifi_logo,&ui_img_wifi_state_png);
                set_wifi_list_status(list_array[k].wifi_logo, atoi(wifi_dis));
                lv_obj_add_flag(list_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
                //绑定事件
                list_array[k].wifi_type = 1;
                lv_obj_add_event_cb(list_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &list_array[k]);
                k++;
                break;
            }
            case '0':{ //未连接过的wifi
                //设置wifi名字并更新相关图片
                WiFiListYOffset += 60;
                lv_label_set_text(list_array[k].wifi_name,dis_wifi_name);
                lv_obj_set_style_text_color(list_array[k].wifi_name,lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_add_flag(list_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
               // lv_img_set_src(list_array[k].wifi_logo,&ui_img_wifi_state_png);
                set_wifi_list_status(list_array[k].wifi_logo, atoi(wifi_dis));
                // lv_img_set_src(list_array[k]->wifi_info,&ui_img_wifi_info_png);
                lv_obj_add_flag(list_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
                //绑定事件
                list_array[k].wifi_type = 0;
                lv_obj_add_event_cb(list_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &list_array[k]);
                k++;
                break;
            }
            default:
                break;
        }
        temp = strtok(NULL,"\t");
    }
    list_array[k] = create_wifi_list_item(ui_NetworkListPanel, LV_ALIGN_TOP_LEFT, 14, WiFiListYOffset);
    NetworkListUpdateFocusObjs(k);
    lv_label_set_text(list_array[k].wifi_name, OtherNetwork[get_cur_language_index()]);
    lv_obj_set_style_text_color(list_array[k].wifi_name,lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(list_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(list_array[k].wifi_logo,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(list_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
    
    //绑定事件
    list_array[k].wifi_type = 3;
    lv_obj_add_event_cb(list_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &list_array[k]);
    wifiListCount = k+1;
    Add3rLeveldObjsCb = NetworkPageChangeObjs; //更新backprage 回调事件
}

static wifi_list_t create_wifi_list_item(lv_obj_t *parent, lv_align_t align_mode, lv_coord_t x, lv_coord_t y)
{
   
    wifi_list_t singleList = {0};
    lv_obj_t * listPanel = lv_obj_create(parent);
    lv_obj_set_width(listPanel, 523);
    lv_obj_set_height(listPanel, 56);
    lv_obj_align(listPanel, align_mode, x, y);
    lv_obj_clear_flag(listPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(listPanel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_set_style_radius(listPanel, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(listPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(listPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(listPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(listPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(listPanel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(listPanel, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(listPanel, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(listPanel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(listPanel, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_pad_all(listPanel, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    singleList.parent = listPanel;

   
    lv_obj_t * list_text = lv_label_create(listPanel);
    lv_obj_set_size(list_text, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(list_text, LV_ALIGN_LEFT_MID, 11, -5);
    lv_label_set_text(list_text, "CXSW");
    lv_obj_set_style_text_color(list_text, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(list_text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(list_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(list_text, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    singleList.wifi_name = list_text;

    // lv_obj_t *list_img3 = lv_img_create(listPanel);
    // lv_obj_set_width(list_img3, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(list_img3, LV_SIZE_CONTENT);    /// 1
    // lv_obj_align(list_img3,LV_ALIGN_RIGHT_MID,-28,0);
    // lv_obj_add_flag(list_img3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_add_flag(list_img3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    // lv_obj_clear_flag(list_img3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_img_set_src(list_img3,&ui_img_wificheckstate_png);
    // part->wifi_info = list_img3;

    lv_obj_t *list_wifiinfo = lv_label_create(parent);
    lv_obj_set_width(list_wifiinfo, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(list_wifiinfo, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(list_wifiinfo, "");
    lv_obj_align_to(list_wifiinfo, list_text, LV_ALIGN_OUT_BOTTOM_LEFT, 2, 16);
    lv_obj_add_flag(list_wifiinfo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(list_wifiinfo, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(list_wifiinfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_color(list_wifiinfo, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(list_wifiinfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(list_wifiinfo, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(list_wifiinfo, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    singleList.wifi_info = list_wifiinfo;

    lv_obj_t *list_img2 = lv_img_create(listPanel);
    lv_img_set_src(list_img2,&ui_img_wifi_state_png);
    lv_obj_set_width(list_img2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(list_img2, LV_SIZE_CONTENT);    /// 1
    lv_obj_add_flag(list_img2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(list_img2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_align_to(list_img2, list_img3, LV_ALIGN_OUT_LEFT_MID,-28,0);
    lv_obj_align(list_img2,LV_ALIGN_RIGHT_MID,-8,0);

    singleList.wifi_logo = list_img2;

    lv_obj_t *list_img1 = lv_img_create(listPanel);
    lv_obj_set_width(list_img1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(list_img1, LV_SIZE_CONTENT);    /// 1
    lv_obj_add_flag(list_img1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(list_img1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(list_img1,&ui_img_wificheckstate_png);
    lv_obj_align_to(list_img1,list_img2,LV_ALIGN_OUT_LEFT_MID,-18, 0);
    lv_obj_add_flag(list_img1, LV_OBJ_FLAG_ADV_HITTEST); 
    singleList.wifi_state = list_img1;

    return singleList;
}

void ui_event_LocalNetworkSettingPanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
       Add3rLeveldObjsCb = NetworkPageChangeObjs;
       LoadPage(ui_NetworkInfo, 0);
        //_ui_screen_change(ui_NetworkInfo, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void settings_set_cur_language(uint8_t cur_language)
{
    if ( cur_language < 0 || cur_language > MAX_LANGUAGE - 1)
        return;

    char *lang = language_get_cur_language_text(cur_language);
    if ( lang )
        lv_label_set_text(ui_LanguagesLabel, lang);
    else
        lv_label_set_text(ui_LanguagesLabel, "");
    // if ( lang )
    //     lv_dropdown_set_text(ui_SystemsettingDropdown2, lang);ui_LanguagesLabel
    // else
    //     lv_dropdown_set_text(ui_SystemsettingDropdown2, "");
}

void ui_event_NetworkFocusChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED || event_code == LV_EVENT_CLICKED) {
        if(target == ui_NetworkName_TextArea)
        {
            CrLogI("set the keyboard textarea to name");
            lv_keyboard_set_textarea(ui_NetworkSetting_Keyboard, target);
        }
        else if(target == ui_NetworkPassw_TextArea)
        {
            CrLogI("set the keyboard textarea to password");
            lv_keyboard_set_textarea(ui_NetworkSetting_Keyboard, target);
        }
    }
}

void settings_change_language_text(void)
{
    setting_screen_change_language_text();
    language_change_language_text();
    cameralist_change_language_text();
    camera_settigns_change_language_text();
    about_device_change_language_text();
    reset_machine_change_language_text();
    //selftest_bind_change_language_text();
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
    
    if(ui_SettingTitleLabel)
        lv_label_set_text(ui_SettingTitleLabel, Setting[language_index]);
    
    if(ui_NetworkSetLabel)
        lv_label_set_text(ui_NetworkSetLabel, NetworkArray[language_index]);

    if (ui_NetworksettingTitle)
        lv_label_set_text(ui_NetworksettingTitle, NetworkArray[language_index]);
       
    if ( ui_BrightnessLabel )
        lv_label_set_text(ui_BrightnessLabel, ScreenBrightnessArray[language_index]);
    
    if (ui_ScreenOffLabel) {
        lv_label_set_text(ui_ScreenOffLabel, ScreenOffArray[language_index]);
        
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s", ScreenOffListLabelSet(ui_ScreenOffTimeIndex, language_index));
        lv_label_set_text(ui_ScreenOffTimeLabel, buff);

    }
   

    if ( ui_SystemsettingLabel3 )
        lv_label_set_text(ui_SystemsettingLabel3, FullScreenArray[language_index]);
    
    if ( ui_LanguageSelectLabel )
    {
         lv_label_set_text(ui_LanguageSelectLabel, LanguageSelection[language_index]);
    }
        
    if (ui_TimeZoneSetLabel)
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", TimeZoneArray[language_index], SettingArray[language_index]);
        lv_label_set_text(ui_TimeZoneSetLabel, TimeZoneArray[language_index]);
    }

    if ( ui_SystemsettingLabel6 )
        lv_label_set_text(ui_SystemsettingLabel6, TouchToneArray[language_index]);

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

    if (ui_VersionDetectLabel)
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", VersionArray[language_index], Detection[language_index]);
        lv_label_set_text(ui_VersionDetectLabel, VersionArray[language_index]);
    }

    if ( ui_VersionLabel )
    {
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s", screen_ver_value);
        lv_label_set_text(ui_VersionLabel, buff);
    }

    if ( ui_DeviceSelfTestLabel )
        lv_label_set_text(ui_DeviceSelfTestLabel, DeviceSelfTestArray[language_index]);

    if ( ui_NetworkSettingLabel1 )
        lv_label_set_text(ui_NetworkSettingLabel1, LocalNetworkArray[language_index]);

    if ( ui_NetworkSettingLabel2 )
        lv_label_set_text(ui_NetworkSettingLabel2, UnConnectedArray[language_index]);

    if ( ui_NetworkPassw_TextArea )
        lv_textarea_set_placeholder_text(ui_NetworkPassw_TextArea, InputPasswordMsg[language_index]);
    
    // if ( ui_NetworkSettingLabel4 )
    //     lv_label_set_text(ui_NetworkSettingLabel4, NetworkConnect[language_index]);
    if ( ui_NetworkName_TextArea )   
        lv_textarea_set_placeholder_text(ui_NetworkName_TextArea, Wifiname[language_index]);
     

    // 摄像头多语言设置
    if (ui_CameraLabel)
        lv_label_set_text(ui_CameraLabel, CameraArray[language_index]);

    if (ui_CameraTitleLabel)
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", CameraArray[language_index], DisableArray[language_index]);
        lv_label_set_text(ui_CameraTitleLabel, CameraArray[language_index]);
    }

    if ( ui_VideoSettingLabel2 )
        lv_label_set_text(ui_VideoSettingLabel2, VedioList[language_index]);

    if ( ui_VideoSettingLabel3 )
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", CameraArray[language_index], SettingArray[language_index]);
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

    if ( ui_NetworkDialog_btn_3_label )
        lv_label_set_text(ui_NetworkDialog_btn_3_label, Cancel[language_index]);

    //绑定创想云多语言设置
    if ( ui_BindDeviceLabel )
        lv_label_set_text(ui_BindDeviceLabel, BindDevice[language_index]);
   
    if ( ui_BindDeviceTitleLabel )
        lv_label_set_text(ui_BindDeviceTitleLabel, BindDevice[language_index]);

    if ( ui_DevicebindingLabel )
        lv_label_set_text(ui_DevicebindingLabel, DeviceBindTipsMsg[language_index]);

    if (ui_DevicebindingAreaLabel)
        lv_label_set_text(ui_DevicebindingAreaLabel, Area[language_index]);
    
    if ( ui_BindQrCodeGetFailLabel )
        lv_label_set_text(ui_BindQrCodeGetFailLabel, IOTTips[language_index]);
    
    if ( ui_BoundUserLogOutBtnLabel )
        lv_label_set_text(ui_BoundUserLogOutBtnLabel, LogOut[language_index]);
    if (ui_ServerSelectedLabel)
    {
        // if (ServerSelectIndex == 1)
        // {
            lv_label_set_text(ui_ServerSelectedLabel, AreaChinese[language_index]);
        //}
        if (ServerSelectIndex == 2)
        {
            lv_label_set_text(ui_ServerSelectedLabel, AreaOthers[language_index]);
        } 
    }
    
    if (PrivacyPolicyMessage.contentLabel)
        lv_label_set_text(PrivacyPolicyMessage.contentLabel, PrivacyPolicyTips[language_index]);
    
    if (ui_UpdateReminderLabel)
        lv_label_set_text(ui_UpdateReminderLabel, UpdateReminder[language_index]);
    
    if ( ui_ResetMachineLabel )
        lv_label_set_text(ui_ResetMachineLabel, ResetMachine[language_index]);

    if ( ui_AboutDeviceLabel )
        lv_label_set_text(ui_AboutDeviceLabel, AboutDevice[language_index]);


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

/*********************************************状态信息刷新***********************************************/
void refresh_wifilist_page(char * wifi_ip,char * wifi_mac)
{
    static char ip_buf[24];
    // if(wifi_ip != NULL && ui_InfoDialog_label_1 != NULL)
    // {
    //     char temp[30] = {0};
    //     snprintf(temp,30,"IP:%s",wifi_ip);
    //     lv_label_set_text(ui_InfoDialog_label_1,temp);
    // }
    // if(wifi_mac != NULL && ui_InfoDialog_label_2 != NULL)
    // {
    //     char temp[30] = {0};
    //     snprintf(temp,30,"MAC:%s",wifi_mac);
    //     lv_label_set_text(ui_InfoDialog_label_2,temp);
    // }
    if(wifi_ip != NULL)
    {
        CrLogI("refresh the wifi ip:%s", wifi_ip);
        memset(ip_buf, 0, sizeof(ip_buf));
        strcpy(ip_buf, wifi_ip);
        if (lv_obj_has_flag(ui_NetworkSettingsPanel, LV_OBJ_FLAG_HIDDEN))
            return;
        
        for(int i = 0; i < WIFI_MAX_NUMBER; i++)
        {           
            if(list_array[i].wifi_type == 2)//属于已连接wifi
            {
                if (lv_obj_is_valid(list_array[i].wifi_info) && list_array[i].wifi_info != NULL) {
                    lv_label_set_text(list_array[i].wifi_info, ip_buf);
                    CrLogI("refreshed the wifi ip.");
                }
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
        lv_label_set_text(ui_VersionLabel,temp);
        CrLogI("version_info: %s\n", version_info);
    }
}

void refresh_light_value(int lightvalue)
{
    char temp[5] = {0};
    CrLogI("refresh light setting page,lightvalue is %d",lightvalue);
    CrLogI("system_state.light_value:%d\n", system_state.light_value);
    
    if(lightvalue < 10)
    {
        lightvalue = 10;
        snprintf(temp,5,"e%d",lightvalue);
        set_printer_data(0x06,strlen(temp),temp);
    }
    if(lightvalue == 10)
    {
        //lv_obj_set_style_bg_img_src(ui_SystemlightDown, &ui_img_down_grey_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    if(lightvalue > 100)
    {
        lightvalue = 100;
        
        snprintf(temp,5,"e%d",lightvalue);
        set_printer_data(0x06,strlen(temp),temp);
    }

    sprintf(temp, "%d%%", lightvalue);
    lv_label_set_text(ui_BrightnessValLabel, temp);
   // lv_label_set_text(ui_BrightnessValSetLabel, temp);
}

/**
 * @description: 上电获取机器当前的熄屏时间
 * @return {*}
 * @param {int} option
 */
void refresh_screenoff_setting(int option)
{
    //printf("option: %d\n", option); 
    switch (option)
    {
        case 0:ScreenOffTimeSelect(2);break;
        case 3:ScreenOffTimeSelect(0);break;
        case 5:ScreenOffTimeSelect(1);break;
        default:ScreenOffTimeSelect(0);break;  
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

/**
 * @description: 刷新云端服务器
 * @return {*}
 * @param {bool} result
 * @param {CloudUserInfo_t} user
 */
void refresh_UserBoundDeviceInfo(bool result, CloudUserInfo_t user)
{
    if (selftestflag) return;
    CrLogI("Load cloud user information,reslut: %d", result);
    if(!result)return;
    if (lv_obj_has_flag(ui_DevicebindingPanel, LV_OBJ_FLAG_HIDDEN)) return;
   
    lv_obj_clear_flag(ui_DeviceBoundPanel, LV_OBJ_FLAG_HIDDEN);   //获取到用户信息，显示用户绑定面板
    lv_obj_add_flag(ui_ServerSelectPanel, LV_OBJ_FLAG_HIDDEN); 
    lv_obj_add_flag(ui_DevicebindingLabel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_HIDDEN);
    if(ui_DeviceBoundUsername != NULL)
    {
        char namebuff[100] = {0};
        snprintf(namebuff, 100, "%s:%s", UserName[get_cur_language_index()], user.UserName);
        lv_label_set_text(ui_DeviceBoundUsername, namebuff);
    }

    if(ui_DeviceBoundUserid != NULL)
    {
        char namebuff[100] = {0};
        snprintf(namebuff, 100, "ID:%s", user.UserID);
        lv_label_set_text(ui_DeviceBoundUserid, namebuff);
    }

    if(ui_DeviceBoundUserimg != NULL)
    {
        char buff[258] = {0};
        snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, user.UserImg);
        CrLogI("UserImg file path: %s", buff);
        lv_obj_clear_flag(ui_DeviceBoundUserimg, LV_OBJ_FLAG_HIDDEN);      /// Flags
        lv_img_set_src(ui_DeviceBoundUserimg, buff);
        lv_obj_update_layout(ui_DeviceBoundUserimg);
        int width = lv_obj_get_width(ui_DeviceBoundUserimg);
        int height = lv_obj_get_height(ui_DeviceBoundUserimg);
        if(width > 0 && height > 0)
        {
            int scale = 256 * 73 / width;
            CrLogI("UserImg width: %d,height:%d, scale:%d", width, height, scale);
            lv_img_set_zoom(ui_DeviceBoundUserimg, scale);

        }
        else
        {
            CrLogI("UserImg width: %d,height:%d", width, height);
            lv_obj_add_flag(ui_DeviceBoundUserimg, LV_OBJ_FLAG_HIDDEN);      /// Flags
        }
    }
    Add3rLeveldObjsCb = DeviceBindPageAddFocusObjs;
    LoadPage(ui_ScreenSettings, 3);
}

void refresh_devicebingding_page(char *src)
{
    if(src != NULL)
    {
        char buff[258] = {0};
        buff[0] = PNG_DRV_LETTER;
        strncpy(buff + 1, src, sizeof(buff) - 2);
        lv_img_set_src(ui_DevicebindingQRCodeImage, buff);
    }
}

void ChangeServerOption(int ServerOption)
{
    CrLogI("Change Server Option:%d", ServerOption);
    ServerSelectIndex = ServerOption;
    if (ServerSelectIndex == 1)
    {
        lv_label_set_text(ui_ServerSelectedLabel, AreaChinese[get_cur_language_index()]);
    }
    else if (ServerSelectIndex == 2)
    {
        lv_label_set_text(ui_ServerSelectedLabel, AreaOthers[get_cur_language_index()]);
    } 
    // if(ui_DevicebindingDropdown1)
    //     lv_dropdown_set_selected(ui_DevicebindingDropdown1, ServerOption + 1);
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
        if(!lv_obj_has_state(ui_SwitchUpdateReminder, LV_STATE_CHECKED))
            lv_obj_add_state(ui_SwitchUpdateReminder, LV_STATE_CHECKED);
    }
    else
    {
        if(lv_obj_has_state(ui_SwitchUpdateReminder, LV_STATE_CHECKED))
            lv_obj_clear_state(ui_SwitchUpdateReminder, LV_STATE_CHECKED);
    }
}

void settings_page_refresh_laserstate(int laser_state)
{
    if(laser_state)
        lv_obj_clear_flag(ui_ImageLaserState, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageLaserState, LV_OBJ_FLAG_HIDDEN);
}

void settings_page_refresh_camerastate(int camera_state)
{
    if(camera_state)
        lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
}
/*********************************************状态信息刷新***********************************************/

void set_wifi_list_status(lv_obj_t * obj, int intensity)
{
    int level = 0;
    if(intensity==0)
    {
        level = 0;
    }
    else if (intensity <= MIN_RSSI)
    {
        level = 0;
    } 
    else if (intensity >= MAX_RSSI)
    {
        level = RSSI_LEVELS - 1;
    }
    else
    {
        float inputRange = (MAX_RSSI - MIN_RSSI);
        float outputRange = (RSSI_LEVELS - 1);
        level = (int)((float)(intensity - MIN_RSSI) * outputRange / inputRange);
    }
    switch (level)
    {
        case 0:lv_img_set_src(obj, &ui_img_wifinosignel2_png);break;
        case 1:lv_img_set_src(obj, &ui_img_wifismall2_png);break;
        case 2:lv_img_set_src(obj, &ui_img_wifimid2_png);break;
        case 3:lv_img_set_src(obj, &ui_img_wififull2_png);break;
        default:lv_img_set_src(obj, &ui_img_wififull2_png);break;
    }
    // wifi_Intensity = intensity;
}

void settings_page_set_wifi_status(int intensity)
{
    int level = 0;
    if (intensity <= MIN_RSSI)
    {
        level = 0;
    } 
    else if (intensity >= MAX_RSSI)
    {
        level = RSSI_LEVELS - 1;
    }
    else
    {
        float inputRange = (MAX_RSSI - MIN_RSSI);
        float outputRange = (RSSI_LEVELS - 1);
        level = (int)((float)(intensity - MIN_RSSI) * outputRange / inputRange);
    }

    switch (level)
    {
        case 0:lv_img_set_src(ui_ImageWifiNormal, &ui_img_wifinosignel_png);break;
        case 1:lv_img_set_src(ui_ImageWifiNormal, &ui_img_wifismall_png);break;
        case 2:lv_img_set_src(ui_ImageWifiNormal, &ui_img_wifimid_png);break;
        case 3:lv_img_set_src(ui_ImageWifiNormal, &ui_img_wififull_png);break;
        default:lv_img_set_src(ui_ImageWifiNormal, &ui_img_wififull_png);break;
    }
    wifi_Intensity = intensity;
}

/*********************************************编码器事件组添加对象***********************************************/
void LoadSettingsScreenAndObjs(bool IsEntered, uint8_t index)
{
    ScreenSettings.stateValue = IsEntered;
   // ScreenStatusValue = IsEntered;
    if(ScreenSettings.stateValue == 0) //一级页面导航模式
    {
        LoadPage(ui_ScreenSettings, 1);

        lv_obj_set_style_bg_img_src(ui_ButtonSettings, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_group_focus_cycle(encoder_group, true);
    }
    else //二级页面导航模式
    {    
        LoadPage(ui_ScreenSettings, 2);
        //SettingsPageChangeObjs(2);
         if (index != SCREEN_SETTINGS_BUTTON) 
         {
            lv_group_focus_obj(settings_array[index]->part_panel);
         }
        
        // if(lv_group_get_focused(encoder_group) == ui_ButtonSettings)
        // {
        //     lv_obj_set_style_bg_img_src(ui_ButtonSettings, &ui_img_pagesettingfocus_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        // }
        // else
        // {
        //     lv_obj_set_style_bg_img_src(ui_ButtonSettings, &ui_img_pagesettingselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        // }  
        lv_obj_set_style_bg_img_src(ui_ButtonSettings, &ui_img_pagesettingselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_group_focus_cycle(encoder_group, false);
    }
}

/**
 * @description: 熄屏设置页事件对象添加
 * @return {*}
 */
static void ScreenOffTimePageAddFocusObjs(void)
{
    lv_group_remove_all_objs(encoder_group);
    for (int i = 0; i < 3; i++)
    {
        lv_group_add_obj(encoder_group, ScreenOffMessage.btn[i].btn);
    } 
}

static void NetworkPageAaaFocusObjs()
{
    lv_group_remove_all_objs(encoder_group);
    lv_group_add_obj(encoder_group, ui_NetworkSetBackBtn);
    lv_group_add_obj(encoder_group, ui_LocalNetworkPanel);

    //lv_obj_add_flag(ui_NetworkListPanel, LV_OBJ_FLAG_HIDDEN);
}

/**
 * @description: wifi列表更新事件组对象
 * @return {*}
 */
static void NetworkListUpdateFocusObjs(uint8_t index)
{
    if (!lv_obj_has_flag(ui_NetworkSettingsPanel, LV_OBJ_FLAG_HIDDEN))
    {
        if (lv_obj_is_valid(list_array[index].parent))
        {
            if (list_array[index].parent != NULL)
            {
                lv_group_add_obj(encoder_group, list_array[index].parent);
            }
        }
    }
}

static void NetworkPageChangeObjs()
{
    lv_group_remove_all_objs(encoder_group);
    lv_group_add_obj(encoder_group, ui_NetworkSetBackBtn);
    lv_group_add_obj(encoder_group, ui_LocalNetworkPanel);

    // int cnt = lv_obj_get_child_cnt(ui_NetworkListPanel);
    // for (size_t i = 0; i < cnt; i++)
    // {
    //     lv_group_add_obj(encoder_group, lv_obj_get_child(ui_NetworkListPanel, i));
    // }
    for (size_t i = 0; i < wifiListCount; i++)
    {   
        if (list_array[i].parent != NULL)
        {
            lv_group_add_obj(encoder_group, list_array[i].parent);
        }
    }
}

/**
 * @description: 网络键盘对象添加
 * @return {*}
 */
void NetworkSettingPageChangeObjs()
{
    lv_group_remove_all_objs(encoder_group);
    lv_group_add_obj(encoder_group, ui_NetworkSetting_Keyboard);
}

/**
 * @description: 摄像头设置子页添加对象到事件组
 * @return {*}
 */
static void CameraSetPageAddFocusObjs(void)
{
    lv_group_add_obj(encoder_group, ui_CameraSubpaneBackBtn);
    lv_group_add_obj(encoder_group, ui_VideoListPanel);
    lv_group_add_obj(encoder_group, ui_CameraSettingPanel);
    lv_group_add_obj(encoder_group, ui_AIDetectPanel);
}

/**
 * @description: 绑定创想云子页面事件对象添加
 * @return {*}
 */
static void DeviceBindPageAddFocusObjs(void)
{
    lv_group_add_obj(encoder_group, ui_BindDeviceBackBtn);
    if (!lv_obj_has_flag(ui_ServerSelectPanel, LV_OBJ_FLAG_HIDDEN))
    {
        lv_group_add_obj(encoder_group, ui_ServerSelectPanel);  
    } 
    if (!lv_obj_has_flag(ui_DeviceBoundPanel, LV_OBJ_FLAG_HIDDEN))
    {
        lv_group_add_obj(encoder_group, ui_BoundUserLogOutBtn); 
    }
}

/**
 * @description: 绑定创想云隐私政策弹窗事件添加
 * @return {*}
 */
static void DeviceBindPrivacyPolicyAddFocusObjs(void)
{
    lv_group_remove_all_objs(encoder_group);
    for (size_t i = 0; i < PrivacyPolicyMessage.btnNumber; i++)
    {
        lv_group_add_obj(encoder_group, PrivacyPolicyMessage.btn[i].btn);    
    }
}

/**
 * @description: 服务器挑选弹框对象事件添加
 * @return {*}
 */
static void ServerSelectPageAddFocusObjs(void)
{
    lv_group_remove_all_objs(encoder_group);
    for (int i = 0; i < 2; i++)
    {
        lv_group_add_obj(encoder_group, ServerSelectMessage.btn[i].btn);
    } 
}

/**
 * @description: 设置页编码器对象事件组设置
 * @return {*}
 * @param {uint8_t} index
 */
static void SettingsPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    // lv_indev_set_group(enc_indev, NULL); 
    // lv_indev_set_group(enc_indev, encoder_group); //关联组
    PageNode *Settings_node = find_page(ui_ScreenSettings);
    Settings_node->nav_level = index;


    switch (index)
    {
    case 1: //1级事件组
        // page_manager.objFreezzFlag = false;
        lv_group_add_obj(encoder_group, ui_ButtonSettings);
        lv_group_add_obj(encoder_group, ui_ButtonReserve);
        lv_group_add_obj(encoder_group, ui_ButtonHomePage);
        lv_group_add_obj(encoder_group, ui_ButtonAxisMove);
        lv_group_add_obj(encoder_group, ui_ButtonFIleManage);
        break;
    case 2: //2级事件组
        // page_manager.objFreezzFlag = false;
        lv_group_add_obj(encoder_group, ui_ButtonSettings);
        for (size_t i = 1; i < MAX_ITEM; i++)
        {
            lv_group_add_obj(encoder_group, settings_array[i]->part_panel);
        }
        break;
    case 3: //3级事件组
        if (Add3rLeveldObjsCb)
        {
            Add3rLeveldObjsCb();
        }
        break;
    default:
        break;
    }
}

//关闭所有子页显示
void SettingsPageCloseSubPage(void)
{
    lv_obj_add_flag(ui_DevicebindingPanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_NetworkSettingsPanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_CameraSettingSupanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_SettingsItemMainPanel, LV_OBJ_FLAG_HIDDEN); 
}
/*********************************************编码器事件组添加对象***********************************************/