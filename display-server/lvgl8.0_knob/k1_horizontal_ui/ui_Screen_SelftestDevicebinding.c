/*
 * @Description: 出厂设置-时区设置
 * @Author: chenwenke
 * @Date: 2023-07-07 01:43:52
 * @LastEditTime: 2023-11-03 04:28:21
 */
#include "src/core/lv_obj_pos.h"
#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "mult_language.h"
#include "ui_custom_messagebox.h"
#include "lvgl_cmd.h"




lv_obj_t * ui_DevicebindingPanel1;
lv_obj_t * ui_DevicebindingImage1;
lv_obj_t * ui_DevicebindingImage2;
lv_obj_t * ui_DevicebindingImage3;
lv_obj_t * ui_DevicebindingImage4;
lv_obj_t * ui_DevicebindingImage5;
lv_obj_t * ui_DevicebindingPanel2;
lv_obj_t * ui_DevicebindingPanel3;
lv_obj_t * ui_DevicebindingPanel4;
lv_obj_t * ui_DevicebindingTitle;
lv_obj_t * ui_DevicebindingLabel1;
lv_obj_t * ui_DevicebindingButton1;
lv_obj_t * ui_DevicebindingBtnlabel1;
lv_obj_t * ui_DevicebindingLabel2;
lv_obj_t * ui_DevicebindingImage6;
lv_obj_t * ui_DevicebindingPanel5;
lv_obj_t * ui_DevicebindingPanel6;
lv_obj_t * ui_DevicebindingUserimg;
lv_obj_t * ui_DevicebindingUsername;
lv_obj_t * ui_DevicebindingUserid;
lv_obj_t * ui_DevicebindingUserBtn;
lv_obj_t * ui_DevicebindingUserBtnlabel;

lv_obj_t * ui_SelfTestPageDeviceBinding;
static lv_obj_t * ui_PanelDeviceBinding;
static lv_obj_t * ui_TitleDeviceBinding;
static lv_obj_t * ui_PanelAreaServerSelect;
static lv_obj_t * ui_LabelArea;
static lv_obj_t * ui_LabelAreaContent;
static lv_obj_t * ui_ImageArrow;

static DialogMsgbox_t ServerSelectMessage; //熄屏对话框


static lv_obj_t * ui_ServerSelectPanel;
static lv_obj_t * ui_DevicebindingAreaLabel;
static lv_obj_t * ui_ServerSelectedLabel;
static lv_obj_t * ui_DevicebindingLabel;  //请使用创想云APP扫码绑定设备label
static lv_obj_t * ui_DevicebindingQRCodeImage; //二维码
static lv_obj_t * ui_BindQrCodeGetFailLabel;
static lv_obj_t * ui_DeviceBoundPanel;
static lv_obj_t * ui_LabelHasBinded;
static lv_obj_t * ui_BoundUserimgPanel;
static lv_obj_t * ui_DeviceBoundUserimg;
static lv_obj_t * ui_DeviceBoundUsername;
static lv_obj_t * ui_DeviceBoundUserid;
static lv_obj_t * ui_BoundUserLogOutBtn;
static lv_obj_t * ui_BoundUserLogOutBtnLabel;
static lv_obj_t * ui_ButtonDeviceBindingLeft;
static lv_obj_t * ui_LabelDeviceBindingLeft;
static lv_obj_t * ui_ButtonDeviceBindingRight;
static lv_obj_t * ui_LabelDeviceBindingRight;

static int IsrefreshCxyUserInfo = 0;
bool SelfTestDevicebindingFlag = false;
bool SelfTestDevicebindingAgreeFlag = false;

typedef void (*DeviceBindingAdd3rdObjsCb)(void);  //添加三级导航对象
static DeviceBindingAdd3rdObjsCb Add3rLevelObjsCb = NULL;

static uint8_t SelftestServerSelectIndex = 0;

void ui_event_Devicebinding(lv_event_t * e);

void LoadDeviceBindingScreen(void);

/**
 * @description: 绑定创想云子页面事件对象添加
 * @return {*}
 */
static void DeviceBindPageAddFocusObjs(void)
{
    lv_group_add_obj(encoder_group, ui_ServerSelectPanel);  
    //lv_group_add_obj(encoder_group, ui_BindDeviceBackBtn);
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
 * @description: 服务器选择操作
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_SeverSelectSetting(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int dat = lv_event_get_user_data(e);
    uint8_t language_index = get_cur_language_index();
    if(event_code == LV_EVENT_SHORT_CLICKED) {
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
        Add3rLevelObjsCb = DeviceBindPageAddFocusObjs;
        LoadPage(ui_SelfTestPageDeviceBinding, 1);
       // Add3rLevelObjsCb = NULL;
        //BackPrepage(false);
    }
}

/**
 * @description: 服务器选择对话框显示
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_ServerSelectBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ShowDialogMessagebox(&ServerSelectMessage, ServerSelectPageAddFocusObjs);
        //Add3rLevelObjsCb = ServerSelectPageAddFocusObjs;
        //LoadPage(ui_SelfTestPageDeviceBinding, 3);
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
    lv_obj_clear_flag(ui_DevicebindingLabel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_HIDDEN);
    LoadPage(ui_SelfTestPageDeviceBinding, 1);
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

void ui_event_BntDeviceBindingLeft(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        // if(lv_obj_has_state(ui_CheckboxAgree,LV_STATE_CHECKED))
        // {
        //     CrLogI("agree the policy.");
            //_ui_screen_change(ui_SelftestNetwork, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
        // }
        LoadPage(ui_TimezoneSettings, 0);
    }
}

void ui_event_BntDeviceBindingRight(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_changelanguage, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
        LoadPage(ui_SelftestTips, 1);
    }
}

void SeverSelectTextSet(lv_obj_t *label, uint8_t label_index, uint8_t language_index)
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


void ui_SelfTestDevicebinding_screen_init(void)
{
    uint8_t language_index = get_cur_language_index();
    ui_SelfTestPageDeviceBinding = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SelfTestPageDeviceBinding, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelfTestPageDeviceBinding, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelfTestPageDeviceBinding, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelfTestPageDeviceBinding, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_SelfTestPageDeviceBinding, DeviceBindingPageChangeObjs, LoadDeviceBindingScreen);
    //页面板
    ui_PanelDeviceBinding = lv_obj_create(ui_SelfTestPageDeviceBinding);
    lv_obj_set_width(ui_PanelDeviceBinding, 640);
    lv_obj_set_height(ui_PanelDeviceBinding, 360);
    lv_obj_set_align(ui_PanelDeviceBinding, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelDeviceBinding, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelDeviceBinding, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelDeviceBinding, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelDeviceBinding, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelDeviceBinding, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelDeviceBinding, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelDeviceBinding, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelDeviceBinding, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelDeviceBinding, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //设备绑定标题
    ui_TitleDeviceBinding = lv_label_create(ui_PanelDeviceBinding);
    lv_obj_set_width(ui_TitleDeviceBinding, 640);
    lv_obj_set_height(ui_TitleDeviceBinding, 60);
    lv_obj_set_x(ui_TitleDeviceBinding, 0);
    lv_obj_set_y(ui_TitleDeviceBinding, 20);
    lv_obj_set_align(ui_TitleDeviceBinding, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_TitleDeviceBinding, DeviceMachine[language_index]);
    lv_obj_set_style_text_color(ui_TitleDeviceBinding, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TitleDeviceBinding, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TitleDeviceBinding, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TitleDeviceBinding, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    //服务器设置面板
    ui_ServerSelectPanel = lv_obj_create(ui_PanelDeviceBinding);
    lv_obj_set_size(ui_ServerSelectPanel, 600, 56);
    lv_obj_set_pos(ui_ServerSelectPanel, 20, 60);
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
    //lv_obj_add_flag(ui_ServerSelectPanel, LV_OBJ_FLAG_HIDDEN); 

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
    lv_label_set_text(ui_DevicebindingAreaLabel, Area[language_index]);
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
   

    static Msgboxbtn_t ServerSelectbtn[2]; //用于熄屏弹窗数据判断
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
    ui_DevicebindingLabel = lv_label_create(ui_PanelDeviceBinding);
    lv_obj_set_size(ui_DevicebindingLabel, 400, 60);
    //lv_obj_set_pos(ui_DevicebindingLabel, 168, 255);
    lv_obj_align(ui_DevicebindingLabel, LV_ALIGN_TOP_MID, 0, 255);
    lv_label_set_long_mode(ui_DevicebindingLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_DevicebindingLabel, DeviceBindTipsMsg[language_index]);
    lv_obj_set_style_text_color(ui_DevicebindingLabel, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DevicebindingLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DevicebindingLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DevicebindingLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_add_flag(ui_DevicebindingLabel, LV_OBJ_FLAG_HIDDEN);      /// Flags
    
    //绑定创想云二维码
    ui_DevicebindingQRCodeImage = lv_qrcode_create(ui_PanelDeviceBinding, 122, lv_color_hex(0xFFFFFF), lv_color_hex(0x2D2E31));
    lv_obj_set_size(ui_DevicebindingQRCodeImage, 124, 124);
    lv_obj_set_pos(ui_DevicebindingQRCodeImage, 260, 128);
    lv_obj_set_style_border_width(ui_DevicebindingQRCodeImage, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_DevicebindingQRCodeImage, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //lv_obj_add_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_HIDDEN);      /// Flags
    
    char temp[64] = {0};
    snprintf(temp, 64, "%s %s", GetSystemConfig().device_sn, GetSystemConfig().device_mac);
    lv_qrcode_update(ui_DevicebindingQRCodeImage, temp, strlen(temp));
    
    // lv_obj_add_flag(ui_DevicebindingPanel5, LV_OBJ_FLAG_HIDDEN);      /// Flags
    // get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态
 
    //服务器信息获取失败
    ui_BindQrCodeGetFailLabel = lv_label_create(ui_PanelDeviceBinding);
    lv_obj_set_width(ui_BindQrCodeGetFailLabel, 400);
    lv_obj_set_height(ui_BindQrCodeGetFailLabel, LV_SIZE_CONTENT);
    lv_obj_align(ui_BindQrCodeGetFailLabel, LV_ALIGN_TOP_MID, 0, 197);
    lv_label_set_long_mode(ui_BindQrCodeGetFailLabel, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_BindQrCodeGetFailLabel, IOTTips[language_index]);
    lv_obj_set_style_text_color(ui_BindQrCodeGetFailLabel, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BindQrCodeGetFailLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BindQrCodeGetFailLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_BindQrCodeGetFailLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_BindQrCodeGetFailLabel, LV_OBJ_FLAG_HIDDEN);      /// Flags
   
    //用户绑定信息面板
    ui_DeviceBoundPanel = lv_obj_create(ui_PanelDeviceBinding);
    lv_obj_set_size(ui_DeviceBoundPanel, 640, 140);
    // lv_obj_set_pos(ui_DeviceBoundPanel, 0, 63);
    lv_obj_align(ui_DeviceBoundPanel, LV_ALIGN_TOP_MID, 0, 63);
    lv_obj_clear_flag(ui_DeviceBoundPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DeviceBoundPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceBoundPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceBoundPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DeviceBoundPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_DeviceBoundPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_DeviceBoundPanel, LV_OBJ_FLAG_HIDDEN); 
    
    //已绑定创想云
    ui_LabelHasBinded = lv_label_create(ui_DeviceBoundPanel);
    lv_obj_set_width(ui_LabelHasBinded, 400);
    lv_obj_set_height(ui_LabelHasBinded, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelHasBinded, LV_ALIGN_TOP_MID, 0, 10);
    lv_label_set_long_mode(ui_LabelHasBinded, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_LabelHasBinded, BindingTips[language_index]);
    lv_obj_set_style_text_color(ui_LabelHasBinded, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHasBinded, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHasBinded, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHasBinded, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_add_flag(ui_LabelHasBinded, LV_OBJ_FLAG_HIDDEN);      /// Flags

    //已绑定用户头像
    ui_BoundUserimgPanel = lv_obj_create(ui_DeviceBoundPanel);
    lv_obj_set_width(ui_BoundUserimgPanel, 73);
    lv_obj_set_height(ui_BoundUserimgPanel, 73);
    lv_obj_set_pos(ui_BoundUserimgPanel, 20, 65);
    //lv_obj_align(ui_BoundUserimgPanel, LV_ALIGN_TOP_LEFT, 22, 22);
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
    //lv_obj_align_to(ui_DeviceBoundUsername, ui_BoundUserimgPanel, LV_ALIGN_OUT_RIGHT_TOP, 18, 0);
    lv_obj_set_pos(ui_DeviceBoundUsername, 111, 65);
    lv_label_set_long_mode(ui_DeviceBoundUsername, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DeviceBoundUsername, UserName[language_index]);
    lv_obj_set_style_text_color(ui_DeviceBoundUsername, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBoundUsername, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBoundUsername, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //用户ID
    ui_DeviceBoundUserid = lv_label_create(ui_DeviceBoundPanel);
    lv_obj_set_width(ui_DeviceBoundUserid, 400);
    lv_obj_set_height(ui_DeviceBoundUserid, 30);
    //lv_obj_align_to(ui_DeviceBoundUserid, ui_DeviceBoundUsername, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
    lv_obj_set_pos(ui_DeviceBoundUserid, 111, 105);
    lv_label_set_long_mode(ui_DeviceBoundUserid, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DeviceBoundUserid, "ID:");
    lv_obj_set_style_text_color(ui_DeviceBoundUserid, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBoundUserid, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBoundUserid, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //登出按钮
    ui_BoundUserLogOutBtn = lv_btn_create(ui_DeviceBoundPanel);
    lv_obj_set_width(ui_BoundUserLogOutBtn, 106);
    lv_obj_set_height(ui_BoundUserLogOutBtn, 52);
    //lv_obj_align(ui_BoundUserLogOutBtn, LV_ALIGN_TOP_RIGHT, -22, 31);
    lv_obj_set_pos(ui_BoundUserLogOutBtn, 514, 80);
    lv_obj_add_flag(ui_BoundUserLogOutBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BoundUserLogOutBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BoundUserLogOutBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BoundUserLogOutBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BoundUserLogOutBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_BoundUserLogOutBtn, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_BoundUserLogOutBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BoundUserLogOutBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BoundUserLogOutBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_BoundUserLogOutBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BoundUserLogOutBtn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_BoundUserLogOutBtn, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_BoundUserLogOutBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_BoundUserLogOutBtn, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_BoundUserLogOutBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_BoundUserLogOutBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    

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
    
    //上一步按钮
    ui_ButtonDeviceBindingLeft = lv_btn_create(ui_PanelDeviceBinding);
    lv_obj_set_width(ui_ButtonDeviceBindingLeft, 176);
    lv_obj_set_height(ui_ButtonDeviceBindingLeft, 52);
    lv_obj_set_x(ui_ButtonDeviceBindingLeft, 96);
    lv_obj_set_y(ui_ButtonDeviceBindingLeft, 294);
    lv_obj_add_flag(ui_ButtonDeviceBindingLeft, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonDeviceBindingLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonDeviceBindingLeft, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonDeviceBindingLeft, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonDeviceBindingLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonDeviceBindingLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonDeviceBindingLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_ButtonDeviceBindingLeft, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonDeviceBindingLeft, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonDeviceBindingLeft, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonDeviceBindingLeft, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonDeviceBindingLeft, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //上一步按钮标签
    ui_LabelDeviceBindingLeft = lv_label_create(ui_ButtonDeviceBindingLeft);
    lv_obj_set_width(ui_LabelDeviceBindingLeft, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelDeviceBindingLeft, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelDeviceBindingLeft, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelDeviceBindingLeft, PrevStep[language_index]);
    lv_obj_set_style_text_color(ui_LabelDeviceBindingLeft, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelDeviceBindingLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelDeviceBindingLeft, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //下一步按钮
    ui_ButtonDeviceBindingRight = lv_btn_create(ui_PanelDeviceBinding);
    lv_obj_set_width(ui_ButtonDeviceBindingRight, 176);
    lv_obj_set_height(ui_ButtonDeviceBindingRight, 52);
    lv_obj_set_x(ui_ButtonDeviceBindingRight, 368);
    lv_obj_set_y(ui_ButtonDeviceBindingRight, 294);
    lv_obj_add_flag(ui_ButtonDeviceBindingRight, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonDeviceBindingRight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonDeviceBindingRight, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonDeviceBindingRight, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonDeviceBindingRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonDeviceBindingRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonDeviceBindingRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_ButtonDeviceBindingRight, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonDeviceBindingRight, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonDeviceBindingRight, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonDeviceBindingRight, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonDeviceBindingRight, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //下一步按钮标签
    ui_LabelDeviceBindingRight = lv_label_create(ui_ButtonDeviceBindingRight);
    lv_obj_set_width(ui_LabelDeviceBindingRight, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelDeviceBindingRight, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelDeviceBindingRight, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelDeviceBindingRight, NextStep[language_index]);
    lv_obj_set_style_text_color(ui_LabelDeviceBindingRight, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelDeviceBindingRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelDeviceBindingRight, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    
    lv_obj_add_event_cb(ui_ServerSelectPanel, ui_event_ServerSelectBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BoundUserLogOutBtn, ui_event_BoundUserLogOutBtn, LV_EVENT_ALL, NULL); //已绑定用户登出事件
    lv_obj_add_event_cb(ui_ButtonDeviceBindingRight, ui_event_BntDeviceBindingRight, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonDeviceBindingLeft, ui_event_BntDeviceBindingLeft, LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_SelfTestPageDeviceBinding, ui_event_Devicebinding, LV_EVENT_ALL, NULL);
}

/**
 * @description: 设备绑定进入隐私政策页面，点击再想想的回调函数
 * @return {*}
 */
void PrivacyPolicyReconsiderBtnCb()
{
    SelfTestDevicebindingFlag = false;
    LoadPage(ui_SelftestTips, 1);
}

static lv_timer_t * SelfTestWaitTimer = NULL;
static void self_test_wait_timerout_handle(lv_timer_t * timer)
{
    static uint8_t time_cnt = 0;
    if (++time_cnt >= 10)
    {
        if (SelfTestWaitTimer)
            lv_timer_del(SelfTestWaitTimer);
        lv_obj_clear_flag(ui_BindQrCodeGetFailLabel, LV_OBJ_FLAG_HIDDEN);      /// Flags
    }
    lv_timer_set_repeat_count(SelfTestWaitTimer, 1);
   // printf("SelfTestWaitTimer test.\n");
    if (system_state.Mqtt_state) {
        if (SelfTestWaitTimer)
        {
             lv_timer_del(SelfTestWaitTimer);
        }
        CrLogI("device binding qrcode exist");
        wait_animmotion(false);
        char temp[64] = {0};
        snprintf(temp, 64, "%s %s", GetSystemConfig().device_sn, GetSystemConfig().device_mac);
        lv_obj_clear_flag(ui_ServerSelectPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags
        lv_qrcode_update(ui_DevicebindingQRCodeImage, temp, strlen(temp));
        lv_obj_clear_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_DevicebindingLabel, LV_OBJ_FLAG_HIDDEN);
        IsrefreshCxyUserInfo = 1;
        lv_obj_add_flag(ui_DeviceBoundPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags
        lv_obj_add_flag(ui_BindQrCodeGetFailLabel, LV_OBJ_FLAG_HIDDEN);;      /// Flags
        get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态
    }
    else
    {
        wait_animmotion(true);
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

/**
 * @description: 设备绑定进入隐私政策页面，点击同意按钮的回调
 * @return {*}
 */
void PrivacyPolicyAgreeBtnCb()
{
    set_printer_data(CONTROL_PARAMETERS, 3, "q1");  //同意隐私政策命令
    get_printer_data(CONTROL_MACHINE_STATE, 2, "b"); //获取IOT连接状态

    SelfTestDevicebindingAgreeFlag = true;
    SelfTestDevicebindingFlag = false;  //退出
    
    LoadPage(ui_SelfTestPageDeviceBinding, 1);
}

void ui_event_SelftestPrivacyPolicyTipHandle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(target == userdata)//btn1
        {   
            LoadPage(ui_SelftestTips, 1);
        }
        else                  //btn2
        {
            SelfTestDevicebindingFlag = true;
            PrivacyPolicyLeftBtnCb = PrivacyPolicyReconsiderBtnCb;
            PrivacyPolicyRightBtnCb = PrivacyPolicyAgreeBtnCb;
            IsrefreshCxyUserInfo = 1;
            LoadPage(ui_SelftestPrivacyPolicy, 1);
        }
    }
}

static void JumpOverCb(void)
{
    LoadPage(ui_SelftestTips, 1);
}

static void LookOverCb(void)
{
    SelfTestDevicebindingFlag = true;
    PrivacyPolicyLeftBtnCb = PrivacyPolicyReconsiderBtnCb;
    PrivacyPolicyRightBtnCb = PrivacyPolicyAgreeBtnCb;
    IsrefreshCxyUserInfo = 1;
    LoadPage(ui_SelftestPrivacyPolicy, 1);
}

void ui_event_Devicebinding(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("Load SelftestDevice bingding page");

        if(!init_uiconfiginfo.AgreePrivacyPolicy && !SelfTestDevicebindingAgreeFlag)
        {//如果前面隐私政策没有同意，弹出隐私政策查看温馨提示
            int index = get_cur_language_index();
            char *btns[2] = {0};
            btns[0] = JumpOver[index];
            btns[1] = LookOver[index];
            void (*btns_callback[2])(void) = {&JumpOverCb, &LookOverCb};
            create_custom_messagebox(KindTips[index], PrivacyPolicyTips[index], btns, btns_callback, 2, true, false);
            set_custom_messagebox_btn_bg_color(0, lv_color_hex(0x50535A));

            //create_PrivacyMessagebox(PrivacyPolicyTips[index], JumpOver[index], LookOver[index], ui_event_SelftestPrivacyPolicyTipHandle, ui_event_SelftestPrivacyPolicyTipHandle);
            // lv_obj_add_flag(ui_DeviceBindingDropdown1, LV_OBJ_FLAG_HIDDEN);      /// Flags
            // lv_obj_add_flag(ui_DeviceBindingLabel6, LV_OBJ_FLAG_HIDDEN);      /// Flags
            // lv_obj_add_flag(ui_DeviceBinding_Image3, LV_OBJ_FLAG_HIDDEN);

            // lv_obj_add_flag(ui_DeviceBindingPanel, LV_OBJ_FLAG_HIDDEN);      //隐藏创想云已绑定页面
            return;
        }
        else
        {//如果前面隐私政策同意了
            //lv_label_set_text(ui_DeviceBindingLabel5, DeviceBindTipsMsg[get_cur_language_index()]);
            //启用定时器，获取system_state.Mqtt_state == 1的情况
            SelfTestWaitTimer = lv_timer_create(self_test_wait_timerout_handle, 1000, NULL);
            lv_timer_set_repeat_count(SelfTestWaitTimer, 1);
            wait_animmotion(true);
            IsrefreshCxyUserInfo = 1;
            CrLogI("device binding qrcode not exist");
            lv_obj_add_flag(ui_DevicebindingQRCodeImage, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_DevicebindingLabel, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_ServerSelectPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags
            lv_obj_add_flag(ui_BindQrCodeGetFailLabel, LV_OBJ_FLAG_HIDDEN);      /// Flags

            get_printer_data(CONTROL_PARAMETERS, 2, "p");//查询创想云服务器状态
        }
        //请求二维码图片
        // CrLogI("Request a QR code image.");
        // //get_printer_data(0x15,1,"\0");
        // send_get_creality_cloud_qrcode_cmd();  
              
        // char temp[64] = {0};
        // printf("device_sn : %s device_mac : %s\n", GetSystemConfig().device_sn, GetSystemConfig().device_mac);
        // snprintf(temp, 64, "%s %s", GetSystemConfig().device_sn, GetSystemConfig().device_mac);
        // lv_qrcode_update(ui_DevicebindingImage6, temp, strlen(temp));
        
        // lv_obj_add_flag(ui_DevicebindingPanel5, LV_OBJ_FLAG_HIDDEN);      /// Flags
        // get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态

        // get_printer_data(CONTROL_PARAMETERS, 2, "p");//查询创想云服务器状态
    }
}

void refresh_selftestbinding_page(char *src)
{
    if(src != NULL)
    {
        char buff[258] = {0};
        buff[0] = PNG_DRV_LETTER;
        strncpy(buff + 1, src, sizeof(buff) - 2);
        lv_img_set_src(ui_DevicebindingImage6, buff);
    }
}

void selftest_bind_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    lv_label_set_text(ui_DevicebindingLabel, DeviceBindTipsMsg[language_index]);
    lv_label_set_text(ui_ServerSelectedLabel, AreaChinese[language_index]);
    if (SelftestServerSelectIndex == 2)
    {
        lv_label_set_text(ui_ServerSelectedLabel, AreaOthers[language_index]);
    } 
    lv_label_set_text(ui_TitleDeviceBinding, DeviceMachine[language_index]);
    lv_label_set_text(ui_DevicebindingAreaLabel, Area[language_index]);
    lv_label_set_text(ui_BindQrCodeGetFailLabel, IOTTips[language_index]);
    lv_label_set_text(ui_LabelHasBinded, BindingTips[language_index]);
    lv_label_set_text(ui_DeviceBoundUsername, UserName[language_index]);
    lv_label_set_text(ui_BoundUserLogOutBtnLabel, LogOut[language_index]);
    lv_label_set_text(ui_LabelDeviceBindingLeft, PrevStep[language_index]);
    lv_label_set_text(ui_LabelDeviceBindingRight, NextStep[language_index]);
}


void refresh_SelftestDeviceUserInfo(CloudUserInfo_t user)
{
    if(IsrefreshCxyUserInfo != 1)return;
    CrLogI("Load cloud user information,Device bingding page");
    if(lv_scr_act() != ui_SelfTestPageDeviceBinding) return;
    IsrefreshCxyUserInfo = 0;

    CrLogI("system_state.CxyUserInfoState = %d\n", system_state.CxyUserInfoState);

    if(!system_state.CxyUserInfoState)return;   //如果无创想云用户信息
    lv_obj_clear_flag(ui_DeviceBoundPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags
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

    LoadPage(ui_SelfTestPageDeviceBinding, 2);
}

void SelftsetChangeServerOption(int ServerOption)
{
    uint8_t language_index = get_cur_language_index();
    CrLogI("selftestdevicepage Change Server Option:%d", ServerOption);

    SelftestServerSelectIndex = ServerOption;
    if (SelftestServerSelectIndex == 1)
    {
        lv_label_set_text(ui_ServerSelectedLabel, AreaChinese[language_index]);
    }
    else if (SelftestServerSelectIndex == 2)
    {
        lv_label_set_text(ui_ServerSelectedLabel, AreaOthers[language_index]);
    }
}

void LoadDeviceBindingScreen(void)
{
    uint8_t language_index = get_cur_language_index();
    lv_disp_load_scr(ui_SelfTestPageDeviceBinding);
}

void LoadDeviceBindingPageAndObjs()
{
    LoadPage(ui_SelfTestPageDeviceBinding, 1);
}

void DeviceBindingPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *DeviceBingdingPage_node = find_page(ui_SelfTestPageDeviceBinding);
    DeviceBingdingPage_node->nav_level = index;

    switch (index) 
    {
    case 1:
        lv_group_add_obj(encoder_group, ui_ServerSelectPanel);
        lv_group_add_obj(encoder_group, ui_ButtonDeviceBindingLeft);
        lv_group_add_obj(encoder_group, ui_ButtonDeviceBindingRight);
        break;
    case 2:
        lv_group_add_obj(encoder_group, ui_BoundUserLogOutBtn);
        lv_group_add_obj(encoder_group, ui_ButtonDeviceBindingLeft);
        lv_group_add_obj(encoder_group, ui_ButtonDeviceBindingRight);
        break;
    case 3: //3级事件组
        if (Add3rLevelObjsCb)
        {
            Add3rLevelObjsCb();
        }
        break;
    default:
        break;
    }
    
}
