/*
 * @Description: 
 * @Author: chenwenke
 * @Date: 2023-07-14 05:23:47
 * @LastEditTime: 2023-11-04 03:57:30
 */

#include "ui_Screen_CustomerService.h"
#include "page_switch.h"
#include "ui.h"
#include "ui_helpers.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_FileManage.h"
#include "ui_screen_AxisMove.h"
#include "ui_Screen_Settings.h"
#include "ui_screen_Adjustment.h"
#include "ui_screen_HomePrinting.h"
#include <stdint.h>
#include <stdio.h>
#include "mult_language.h"

/****************************************************/
//#define QRCODE_IMG_SIZE 160
#define QRCODE_IMG_SIZE 280

static lv_obj_t * ui_ScreenCustomerServicePage;
/******************screen left panel**********************/
static lv_obj_t * ui_PanelPageScreenService;
static lv_obj_t * ui_ButtonHomeScreenService;
// static lv_obj_t * ui_ImageServicePage;
static lv_obj_t * ui_ButtonServicePage;
static lv_obj_t * ui_ButtonFileManageScreenService;
static lv_obj_t * ui_ButtonSettingsScreenService;
static lv_obj_t * ui_ButtonAxisMoveScreenService;

/******************screen right menu panel**********************/
static lv_obj_t * ui_PanelRightServicePage;
static lv_obj_t * ui_PanelTitleAndStatusServicePage;
static lv_obj_t * ui_DeviceIconPanel;
static lv_obj_t * ui_LabelCustomerService;
static lv_obj_t * ui_ImageWifiService;
static lv_obj_t * ui_ImageCameraService;
static lv_obj_t * ui_ImageLaserService;
static lv_obj_t * ui_ServicePanelList;

/******************FAQ子页**********************/
static lv_obj_t * ui_PanelFAQ;
static lv_obj_t * ui_LableFAQTitle;
static lv_obj_t * ui_ButtonBackFAQ;
static lv_obj_t * ui_LineFAQDividing;
static lv_obj_t * ui_LableFAQTip;
static lv_obj_t * ui_ImageFAQQRCode;

/******************在线说明书子页**********************/
static lv_obj_t * ui_PanelOnlineManual;
static lv_obj_t * ui_LableOnlineManualTitle;
static lv_obj_t * ui_ButtonBackOnlineManual;
static lv_obj_t * ui_LineOnlineManualDividing;
static lv_obj_t * ui_LableOnlineManualTip;
static lv_obj_t * ui_ImageOnlineManualQRCode;

/******************打印历史子页**********************/
static lv_obj_t * ui_PanelPrintHistory;
static lv_obj_t * ui_LablePrintHistory;
static lv_obj_t * ui_ButtonBackPrintHistory;
static lv_obj_t * ui_LinePrintHistoryDividing;
static lv_obj_t * ui_PrintHistoryPanelList;
static lv_obj_t * ui_LableNoPrintHistoryRecord;

/******************错误历史子页**********************/
static lv_obj_t * ui_PanelErrorHistory;
static lv_obj_t * ui_LableErrorHistory;
static lv_obj_t * ui_ButtonBackErrorHistory;
static lv_obj_t * ui_LineErrorHistoryDividing;
static lv_obj_t * ui_LableErrorCodeTitle;
static lv_obj_t * ui_LableOccurTimeTitle;
static lv_obj_t * ui_LableOperateTitle;
static lv_obj_t * ui_ErrorHistoryPanelList;
static lv_obj_t * ui_LableNoErrorHistoryRecord;

/******************导出日志子页**********************/
static lv_obj_t * ui_PanelExportLog;
static lv_obj_t * ui_LableExportLog;
static lv_obj_t * ui_ButtonBackExportLog;
static lv_obj_t * ui_LineExportLogDividing;
static lv_obj_t * ui_ExportLogPanelList;

// static lv_obj_t * ui_ServiceBtn;
// static lv_obj_t * ui_LabelServiceTitle;
// static lv_obj_t * ui_ErrorlistBtn;
// static lv_obj_t * ui_ErrorlistBtnlabel;
// static lv_obj_t * ui_UploadLogBtn;
// static lv_obj_t * ui_UploadLogBtnlabel;
// static lv_obj_t * ui_ScreenServicePageCenterPanel;

// static lv_obj_t * ui_PanelImageShowScreenService;
static lv_obj_t * ui_ImageFeedbackScreenService;
// static lv_obj_t * ui_LabelFeedbackScreenService;

// static lv_obj_t * ui_CustomServicePanel1;
// static lv_obj_t * ui_CustomServiceImage1;
// static lv_obj_t * ui_CustomServiceLabel1;
// static lv_obj_t * ui_CustomServicePanel2;
// static lv_obj_t * ui_CustomServiceImage2;
// static lv_obj_t * ui_CustomServiceLabel2;
// static lv_obj_t * ui_CustomServicePanel3;
// static lv_obj_t * ui_CustomServiceImage3;
// static lv_obj_t * ui_CustomServiceLabel3;
//错误历史
// static lv_obj_t * ui_ErrorhistoryPanel;
// static lv_obj_t * ui_Errorhistorytitle;
// static lv_obj_t * ui_TitleError;
// static lv_obj_t * ui_TitleTime;
// static lv_obj_t * ui_TitleOption;
// static lv_obj_t * ui_ErrorlistPanel;

// static lv_obj_t * ui_UploadLogPanel;
// static lv_obj_t * ui_UploadTips;
// static lv_obj_t * ui_UploadBtn;
// static lv_obj_t * ui_UploadBtnlabel;

EventGrop_Data ServiceScreen;
MenuItem_t *ServicesArray[6] = {NULL};

MenuItem_t *ExportLogMenuArray[5] = {NULL};

static int wifi_Intensity = 0;
static uint16_t HistoryRecordCnt = 0;
static uint16_t ErrorHistoryCnt = 0;

typedef void (*CustomerServiceAdd3rdLevelObjsCb_f)(void);  //添加三级导航对象回调函数
static CustomerServiceAdd3rdLevelObjsCb_f Add3rdLevelObjsCb = NULL;
static print_history_part_t **listPanel = NULL;     //打印历史菜单池，用于动态存储菜单信息
static ErrorMenuItemObj_t **ErrorMenuPool = NULL;      //错误历史菜单池，用于动态存储菜单信息

static lv_timer_t * ui_HistoryRecordListWaittimer = NULL;

typedef struct Error_Info
{
    lv_obj_t * parent;
    lv_obj_t * errorcode;
    lv_obj_t * Occurrencetime;
    lv_obj_t * Option;
    lv_obj_t * WarningImg;
    lv_obj_t * Errorlevel;
}Error_Info_t;

static Error_Info_t **ErrorHistoryMenuPool = NULL;      //错误历史菜单池，用于动态存储菜单信息
static lv_timer_t * CustomerServideNavTimer;

//U盘
static lv_obj_t * ui_PanelInsertUdiskTipDialog = NULL;
static lv_obj_t * ui_InsertUdiskTipMsgbox = NULL;
static lv_obj_t * ui_ImageUdisk = NULL;
static lv_obj_t * ui_LableInsertUdiskTip = NULL;
static lv_timer_t * ui_TipWaittimer = NULL;


static void ShowMenuSubPage(SubPageType_t PageType);

/***************************************************/
static void ui_event_ButtonHomeScreenService(lv_event_t * e);
static void ui_event_ButtonFileManageScreenService(lv_event_t * e);
static void ui_event_ButtonSettingsScreenService(lv_event_t * e);
static void ui_event_ButtonMoveScreenService(lv_event_t * e);
static void ui_event_ButtonServicePage(lv_event_t * e);
static void ui_event_upload(lv_event_t * e);

static void CustomerServicePageChangeObjs(uint8_t index);
static MenuItem_t *CreateServiceListItem(lv_obj_t *parent, uint8_t index, int16_t pos_x, int16_t pos_y, void (*part_event_callback)(lv_event_t *));
static MenuItem_t *CreateNormalListItem(lv_obj_t *parent, uint8_t index, int16_t pos_x, int16_t pos_y, void (*part_event_callback)(lv_event_t *));
static print_history_part_t *CreateCustomPrintHistoryPart(lv_obj_t *parent, void (*part_event_callback)(lv_event_t *));
static ErrorMenuItemObj_t *CreateErrorHistoryListItem(lv_obj_t *parent, uint8_t index, void (*part_event_callback)(lv_event_t *));
static void MenuItemCommonStyleInit(MenuItem_t *part, const char *item_name, bool IsShowArrow);
static void CustomerServideNavTimerCb(lv_timer_t * timer);
static void CloseInsertUdiskTipDialog(void);
static void TipWaitTimeoutCb(struct _lv_timer_t * timer);

static void AddFAQNavObjs(void);
static void AddOnlineManualNavObjs(void);
static void AddPrintHistoryNavObjs(void);
static void AddErrorHistoryNavObjs(void);
static void AddExportLogNavObjs(void);
static void AddExportUdiskNavObjs(void);

static void ShowPrintHistoryInfo(uint8_t wait_time);
// static void ShowErrorHistoryInfo(void);
static void get_fault_codelist(void);
static bool ErrorMenuPoolManager(uint16_t newErrorHistoryNum);
static Error_Info_t *create_single_error(lv_obj_t * parent, char * error, char * time, char * option, int errorlevel);
static void ui_event_PanelErrorHistoryInfo(lv_event_t * e);
static void InsertUdiskTipDialogAddObjsToGroup(void);

static void ExportUdiskBtnClicked(lv_event_t * e);
static void faultcodemsg_close(void);
static void upload_faultcodemsg(void);
static int GetPrintHistoryItemNum(void);
static int GetErrorHistoryItemNum(void);
static void HistroyRecordPanelClicked(lv_event_t * e);
static void ui_event_PanelPrintHistoryInfo(lv_event_t * e);
// static void ErrorHistoryConfirmBntCb(void);
static void ErrorRecordPanelClicked(lv_event_t * e);
static bool PrintHistoryMenuPoolManager(uint16_t NewPrintHistoryNum);
static void ShowPartRecordInfo(print_history_part_t *part, print_record_info_t *RecordInfo);
static void FillSingleErrorInfo(ErrorMenuItemObj_t *part, ErrorMenuItemInfo_t *RecordInfo);
static void ShowErrorHistoryInfoDynamicly(void);


/**************************************************/
bool start_uploadlog = false;
void ui_event_ButtonHomeScreenService(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        if ( home_printing_is_printing_finished() )
        {
            LoadHomeNormalPageAndObjs(true);
        }
        else
        {
            LoadHomePrintingPageAndObjs(true);
        }
    }
    if(event_code == LV_EVENT_FOCUSED) {  
        if ( home_printing_is_printing_finished() )
        {
            LoadHomeNormalPageAndObjs(false);
        }
        else
        {
            LoadHomePrintingPageAndObjs(false);
        }
    }
}  
void ui_event_ButtonFileManageScreenService(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        LoadFileManageScreenAndObjs(true);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
       // LoadFileManageScreen(); 
        LoadFileManageScreenAndObjs(false);
    }
}
void ui_event_ButtonSettingsScreenService(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //LoadSettingsScreen();
        LoadSettingsScreenAndObjs(false, SCREEN_SETTINGS_BUTTON);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
      //  LoadSettingsScreen(); 
        LoadSettingsScreenAndObjs(false, SCREEN_SETTINGS_BUTTON);
    }
}
void ui_event_ButtonMoveScreenService(lv_event_t * e)
{
    // bool IsEntered = false;
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //LoadAxisMoveScreen();
        LoadAxixMoveScreenAndObjs(true);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
        //LoadAxisMoveScreen();
        LoadAxixMoveScreenAndObjs(false);
    }
}


void CustomerServideNavTimerCb(lv_timer_t * timer)
{
  /*Use the user_data*/
    lv_group_focus_freeze(encoder_group, false);
    lv_timer_del(CustomerServideNavTimer);
}
void ui_event_ButtonServicePage(lv_event_t * e)
{
    bool IsEntered = false;
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        CrLogI("ui_event_ButtonServicePage\n");
        
        IsEntered = ServiceScreen.stateValue;
        IsEntered = !IsEntered;
        LoadServiceScreenAndObjs(IsEntered);      
    }
    // if(event_code == LV_EVENT_DEFOCUSED)
    // {
    //     if (ServiceScreen.stateValue)
    //     {
    //         lv_obj_set_style_bg_img_src(ui_ButtonServicePage, &ui_img_pagereserveselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     }
    // }
    // if(event_code == LV_EVENT_FOCUSED)
    // {
    //     lv_obj_set_style_bg_img_src(ui_ButtonServicePage, &ui_img_pagereserveselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     // if (ServiceScreen.stateValue)
    //     // {
    //     //     lv_obj_set_style_bg_img_src(ui_ButtonServicePage, &ui_img_pagereservefocus_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     //     if (page_manager.objFreezzFlag == false)
    //     //     {
    //     //         page_manager.objFreezzFlag = true;
    //     //     }
    //     //     else if (page_manager.objFreezzFlag == true)
    //     //     {
    //     //         lv_group_focus_freeze(encoder_group, true);
    //     //         CustomerServideNavTimer = lv_timer_create(CustomerServideNavTimerCb, 300,  NULL);
    //     //     }
    //     // }
    // }
}


static void ui_event_FAQItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        ShowMenuSubPage(FAQ_PAGE);
        Add3rdLevelObjsCb = AddFAQNavObjs;
        LoadPage(ui_ScreenCustomerServicePage, 3);
    }
}

static void ui_event_OnlineManualItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //_ui_screen_change(ui_CustomerFaq, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        CrLogI("ui_event_OnlineManualItem\n");
        ShowMenuSubPage(ONLINE_MANUAL_PAGE);
        Add3rdLevelObjsCb = AddOnlineManualNavObjs;
        LoadPage(ui_ScreenCustomerServicePage, 3);
    }
}

static void ui_event_PrintHistoryItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //_ui_screen_change(ui_CustomerFaq, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        CrLogI("ui_event_PrintHistoryItem\n");
        ShowPrintHistoryInfo(10);
        ShowMenuSubPage(PRINT_HISTORY_PAGE);
        Add3rdLevelObjsCb = AddPrintHistoryNavObjs;
        LoadPage(ui_ScreenCustomerServicePage, 3);
        //LoadPrintHistoryScreen();
    }
}


static void ui_event_ErrorHistoryItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //_ui_screen_change(ui_CustomerFaq, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        CrLogI("ui_event_ErrorHistoryItem\n");
        //ShowErrorHistoryInfo();
        ShowMenuSubPage(ERROR_HISTORY_PAGE);
        lv_obj_clean(ui_ErrorHistoryPanelList);
        lv_obj_update_layout(ui_ErrorHistoryPanelList);
        get_fault_codelist();
        Add3rdLevelObjsCb = AddErrorHistoryNavObjs;
        
        LoadPage(ui_ScreenCustomerServicePage, 3);
    }
}

static void ui_event_ExportLogItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //_ui_screen_change(ui_CustomerFaq, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        CrLogI("ui_event_ExportLogItem\n");
        ShowMenuSubPage(EXPORT_LOG_PAGE);
        Add3rdLevelObjsCb = AddExportLogNavObjs;
        LoadPage(ui_ScreenCustomerServicePage, 3);
        
    }
}

void CloseInsertUdiskTipDialog(void)
{
    DeinitPopoutManager(&MsgPopout);
    lv_obj_add_flag(ui_PanelInsertUdiskTipDialog, LV_OBJ_FLAG_HIDDEN);
    //lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    //lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    if (IsThereAnyPopout())
    {
        ManagePopoutFocus();
    }
    else
    {
        CrLogI("cancle_msgbox BackPrepage");
        BackPrepage(true);
    }
}

void TipWaitTimeoutCb(struct _lv_timer_t * timer)
{
    CloseInsertUdiskTipDialog();
    lv_timer_del(ui_TipWaittimer);
}

void InsertUdiskTipDialogAddObjsToGroup(void)
{
    lv_group_focus_freeze(encoder_group, false); //用于解决导航按钮加冻结后解冻前，错误弹框无法聚焦的情况
    lv_group_remove_all_objs(encoder_group);

    lv_group_add_obj(encoder_group, ui_PanelInsertUdiskTipDialog);
}

//传入title对象，按键对象数组（包括按键，label，回调函数），按键个数，按键大小
void CreateInsertUdiskTipDialog(uint32_t continue_length)
{
    uint8_t language_index = get_cur_language_index();
    if (!IsThereAnyPopout())
    {
        RecordObjBeforePopup();
    }

    if(ui_PanelInsertUdiskTipDialog == NULL)
    {        
        //消息背景面板
        ui_PanelInsertUdiskTipDialog = lv_obj_create(lv_scr_act());
        lv_obj_set_width(ui_PanelInsertUdiskTipDialog, 640);
        lv_obj_set_height(ui_PanelInsertUdiskTipDialog, 360);
        lv_obj_set_pos(ui_PanelInsertUdiskTipDialog, 0, 60);
        lv_obj_clear_flag(ui_PanelInsertUdiskTipDialog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_PanelInsertUdiskTipDialog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_PanelInsertUdiskTipDialog, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_PanelInsertUdiskTipDialog, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_PanelInsertUdiskTipDialog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_PanelInsertUdiskTipDialog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        // lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
        //lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);

        //消息框
        ui_InsertUdiskTipMsgbox = lv_obj_create(ui_PanelInsertUdiskTipDialog);
        lv_obj_set_width(ui_InsertUdiskTipMsgbox, 371);
        lv_obj_set_height(ui_InsertUdiskTipMsgbox, 285);
        lv_obj_align(ui_InsertUdiskTipMsgbox, LV_ALIGN_CENTER, 0, 0);
        lv_obj_clear_flag(ui_InsertUdiskTipMsgbox, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_InsertUdiskTipMsgbox, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_InsertUdiskTipMsgbox, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_InsertUdiskTipMsgbox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_InsertUdiskTipMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_InsertUdiskTipMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
 
        //打印结果图片
        ui_ImageUdisk = lv_img_create(ui_InsertUdiskTipMsgbox);
        lv_obj_set_size(ui_ImageUdisk, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        lv_obj_align(ui_ImageUdisk, LV_ALIGN_TOP_MID, 0, 68);
        lv_img_set_src(ui_ImageUdisk, &ui_img_udiskbig_png);

        //打印结果lable
        ui_LableInsertUdiskTip = lv_label_create(ui_InsertUdiskTipMsgbox);
        lv_obj_set_size(ui_LableInsertUdiskTip, 300, LV_SIZE_CONTENT);
        //lv_obj_align_to(ui_LableInsertUdiskTip, ui_ImagePrintResult, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
        lv_obj_align(ui_LableInsertUdiskTip, LV_ALIGN_TOP_MID, 0, 180);
        lv_label_set_long_mode(ui_LableInsertUdiskTip, LV_LABEL_LONG_WRAP);
        lv_obj_set_style_text_color(ui_LableInsertUdiskTip, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_LableInsertUdiskTip, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_LableInsertUdiskTip, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_LableInsertUdiskTip, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_LableInsertUdiskTip, InsertUdisk[language_index]);
    }
    else
    {
        lv_obj_set_parent(ui_PanelInsertUdiskTipDialog, lv_scr_act());
        if(lv_obj_has_flag(ui_PanelInsertUdiskTipDialog,LV_OBJ_FLAG_HIDDEN))
        {
            // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(ui_PanelInsertUdiskTipDialog, LV_OBJ_FLAG_HIDDEN);     /// Flags  
            CrLogI("cancle the msgbox hidden!");
        }
        else
        {
            CrLogI("msgbox exists,quit!");
            return;
        }
    }

    // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    // RecordObjBeforePopup();//记录原来的导航对象
    // ResultMsgboxAddObjsToGroup();

    ui_TipWaittimer = lv_timer_create(TipWaitTimeoutCb, continue_length, NULL);
    //lv_timer_set_repeat_count(ui_TipWaittimer, 1);

    InitPopoutManager(&MsgPopout, ui_PanelInsertUdiskTipDialog, InsertUdiskTipDialogAddObjsToGroup);
    MsgPopout.obj1_flag = true;
    MsgPopout.popout_focus_obj1 = ui_PanelInsertUdiskTipDialog;

    //弹框聚焦对象处理
    ManagePopoutFocus();
}


static void ui_event_ExportUDiskItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //发送日志导出指令
        send_buzzer(0x01);
        startexprotlogtolocal = true;
        set_printer_data(0x1c,1,"1");
        CrLogI("ui_event_ExportUDiskItem\n");
    }
}

static void ui_event_UploadLogItem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //_ui_screen_change(ui_CustomerFaq, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        CrLogI("ui_event_UploadLogItem\n");

    }
}

//返回按钮回调
static void ui_event_BackBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        //printf("ui_event_BackBtn 888start\n");
        ShowMenuSubPage(MAIN_MENU_PAGE);
        BackPrepage(false);
        //printf("ui_event_BackBtn end\n");
    }
}

/***********************绑定创想云隐私政策处理****************************/
static void PrivacyPolicyReconsiderBtnCb(void)
{
    BackPrepage(false);
}

static void PrivacyPolicyAgreeBtnCb(void)
{
    set_printer_data(CONTROL_PARAMETERS, 3, "q1"); //同意隐私政策命令
    get_printer_data(CONTROL_MACHINE_STATE, 2, "b"); //获取IOT连接状态
    
    // Waittimer = lv_timer_create(wait_timerout_handle, 1000, NULL);
    // lv_timer_set_repeat_count(Waittimer, 1);
    // wait_animmotion(true);
    // LoadSettingsScreenAndObjs(false, 0);
    // LoadSettingsScreenAndObjs(true, 8);
    // Add3rLeveldObjsCb = DeviceBindPageAddFocusObjs;
    // LoadPage(ui_ScreenSettings, 3);
    BackPrepage(false);
    //加载设备绑定页面
}

static void GoBackCb(void)
{
    BackPrepage(true);
}

static void LookOverCb(void)
{
    PrivacyPolicyLeftBtnCb = PrivacyPolicyReconsiderBtnCb;
    PrivacyPolicyRightBtnCb = PrivacyPolicyAgreeBtnCb;
    BackPrepage(true);
    LoadPage(ui_SelftestPrivacyPolicy, 1);
}

static void ui_event_upload(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(!init_uiconfiginfo.AgreePrivacyPolicy)
        {
            int index = get_cur_language_index();
            char *btns[2] = {0};
            btns[0] = Back[index];
            btns[1] = LookOver[index];
            void (*btns_callback[2])(void) = {&GoBackCb, &LookOverCb};
            create_custom_messagebox(KindTips[index], PrivacyPolicyTips[index], btns, btns_callback, 2, true, false);
            set_custom_messagebox_btn_bg_color(0, lv_color_hex(0x50535A));
            return;
        }
        if(print_state != 1)
        {
            CrLogI("can't upload log, because the print_state:%d ",print_state);
            create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
            return;
        }
        if(system_state.CxyUserInfoState == 1)//有绑定信息
        {
            if ( wifi_state == '1' )    //网络已连接
            {
                CrLogI("start upload log");
                start_uploadlog = true;
                set_printer_data(CONTROL_MACHINE_LOG, 2, "2");
            }
            else
            {
                CrLogI("don't have network");
                create_msgbox(DontNetwork[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
            }
        }
        else
        {
            CrLogI("don't have cxyuserinfo");
            create_msgbox(DontCXYUserInfo[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
        }
    }
}

static void ui_event_ServiceItems(lv_event_t * e)
{
    MenuItem_t *part = lv_event_get_user_data(e);

    if (!part) return;

    switch (part->index)
    {
    case 1: //FAQ
        ui_event_FAQItem(e);
        break;
    case 2: //在线说明书
        ui_event_OnlineManualItem(e);
        break;
    case 3: //打印历史
        ui_event_PrintHistoryItem(e);
        break;
    case 4: //错误历史
        ui_event_ErrorHistoryItem(e);
        break;
    case 5: //输出日志
        ui_event_ExportLogItem(e);
        break;
    default:
        break;
    }
}


static void ui_event_ExportLogItems(lv_event_t * e)
{
    MenuItem_t *part = lv_event_get_user_data(e);

    if (!part) return;

    switch (part->index)
    {
    case 1: //导出U盘
        ui_event_ExportUDiskItem(e);
        break;
    case 2: //上传日志
        //ui_event_UploadLogItem(e);
        ui_event_upload(e);
        break;
    default:
        break;
    }
}

void faultcodemsg_close(void)
{
    send_buzzer(0x01);
    selftest_messagebox_close();
}

void upload_faultcodemsg(void)
{
    send_buzzer(0x01);
    selftest_messagebox_close();
    if(print_state != 1)
    {
        CrLogI("can't upload log, because the print_state:%d ",print_state);
        create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
        return;
    }
    if(system_state.CxyUserInfoState == 1)//有绑定信息
    {
        if ( wifi_state == '1'  || wire_net_state == '1')    //网络已连接
        {
            CrLogI("start upload log");
            start_selftest_upload = true;
            set_printer_data(CONTROL_MACHINE_LOG, 2, "2");
        }
        else
        {
            CrLogI("don't have network");
            create_msgbox(DontNetwork[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
        }
    }
    else
    {
        CrLogI("don't have cxyuserinfo"); 
        create_msgbox(DontCXYUserInfo[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
    }
}

// void faultcodemsg_close()
// {
//     send_buzzer(0x01);
//     selftest_messagebox_close();
// }

// void upload_faultcodemsg()
// {
//     send_buzzer(0x01);
//     selftest_messagebox_close();
//     if(print_state != 1)
//     {
//         CrLogI("can't upload log, because the print_state:%d ",print_state);
//         create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
//         return;
//     }
//     if(system_state.CxyUserInfoState == 1)//有绑定信息
//     {
//         if ( wifi_state == '1'  || wire_net_state == '1')    //网络已连接
//         {
//             CrLogI("start upload log");
//             start_selftest_upload = true;
//             set_printer_data(CONTROL_MACHINE_LOG, 2, "2");
//         }
//         else
//         {
//             CrLogI("don't have network");
//             create_msgbox(DontNetwork[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
//         }
//     }
//     else
//     {
//         CrLogI("don't have cxyuserinfo");
//         create_msgbox(DontCXYUserInfo[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
//     }
// }

static void ui_event_ErrorcodeOption(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * codevalue = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        CrLogI("load errorcode msgoption page.%d",atoi(lv_label_get_text(codevalue)));
        lv_obj_t * parent = lv_obj_get_parent(codevalue);
        lv_obj_t * errorcode = lv_obj_get_child(parent, 0);
        uint8_t language_index = get_cur_language_index();
        if(atoi(lv_label_get_text(codevalue)) <= 200)//
        {
            void (*btns_callback[2])(void) = {&faultcodemsg_close, &upload_faultcodemsg};
            create_selftest_messagebox(KindTips[language_index], get_errorcode_info(atoi(lv_label_get_text(errorcode))), Confirm[language_index],  UploadLog[language_index], btns_callback);
        }
        else
        {
            void (*btns_callback[2])(void) = {NULL, &faultcodemsg_close};
            create_selftest_messagebox(KindTips[language_index], get_errorcode_info(atoi(lv_label_get_text(errorcode))), NULL, Confirm[language_index], btns_callback);
        }
    }
}

Error_Info_t *create_single_error(lv_obj_t * parent, char * error, char * time, char * option, int errorlevel)
{
    Error_Info_t *singleerror = (Error_Info_t *)lv_mem_alloc(sizeof(Error_Info_t));
    if ( !singleerror )
        return NULL;

    singleerror->parent = lv_obj_create(parent);
    lv_obj_set_width(singleerror->parent, 523);
    lv_obj_set_height(singleerror->parent, 60);
    lv_obj_add_flag(singleerror->parent, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(singleerror->parent, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(singleerror->parent, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(singleerror->parent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(singleerror->parent, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(singleerror->parent, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(singleerror->parent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(singleerror->parent, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(singleerror->parent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式设置
    //lv_obj_set_style_border_width(singleerror->parent, 3, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(singleerror->parent, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(singleerror->parent, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(singleerror->parent, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(singleerror->parent, 4, LV_PART_MAIN | LV_STATE_FOCUSED);

    singleerror->errorcode = lv_label_create(singleerror->parent);
    lv_obj_set_width(singleerror->errorcode, LV_SIZE_CONTENT);
    lv_obj_set_height(singleerror->errorcode, 30);
    lv_obj_align(singleerror->errorcode, LV_ALIGN_LEFT_MID, 20, 0);
    lv_label_set_text(singleerror->errorcode, error);
    lv_obj_set_style_text_color(singleerror->errorcode, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(singleerror->errorcode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(singleerror->errorcode, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(singleerror->errorcode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    singleerror->Occurrencetime = lv_label_create(singleerror->parent);
    lv_obj_set_width(singleerror->Occurrencetime, LV_SIZE_CONTENT);
    lv_obj_set_height(singleerror->Occurrencetime, 30);
    lv_obj_align(singleerror->Occurrencetime, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(singleerror->Occurrencetime, time);
    lv_obj_set_style_text_color(singleerror->Occurrencetime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(singleerror->Occurrencetime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(singleerror->Occurrencetime, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(singleerror->Occurrencetime, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(singleerror->Occurrencetime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    singleerror->Option = lv_label_create(singleerror->parent);
    lv_obj_set_width(singleerror->Option, LV_SIZE_CONTENT);
    lv_obj_set_height(singleerror->Option, 30);
    lv_obj_align(singleerror->Option, LV_ALIGN_RIGHT_MID, -10, 0);
    lv_label_set_text(singleerror->Option, option);
    lv_obj_set_style_text_color(singleerror->Option, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(singleerror->Option, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(singleerror->Option, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(singleerror->Option, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(singleerror->Option, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(singleerror->Option, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(singleerror->Option, LV_OBJ_FLAG_HIDDEN);

    singleerror->WarningImg = lv_img_create(singleerror->parent);
    lv_obj_set_width(singleerror->WarningImg, LV_SIZE_CONTENT);
    lv_obj_set_height(singleerror->WarningImg, LV_SIZE_CONTENT);
    lv_obj_align(singleerror->WarningImg, LV_ALIGN_RIGHT_MID, -36, 0);
    lv_img_set_src(singleerror->WarningImg, &ui_img_warning_png);

    singleerror->Errorlevel = lv_label_create(singleerror->parent);
    lv_obj_set_width(singleerror->Errorlevel, LV_SIZE_CONTENT);
    lv_obj_set_height(singleerror->Errorlevel, 30);
    lv_obj_align(singleerror->Errorlevel, LV_ALIGN_RIGHT_MID, -10, 0);
    char tempbuff[256] = {0};
    snprintf(tempbuff, 256, "%d", errorlevel);
    lv_label_set_text(singleerror->Errorlevel, tempbuff);
    lv_obj_add_flag(singleerror->Errorlevel, LV_OBJ_FLAG_HIDDEN);


    lv_obj_add_event_cb(singleerror->parent, ui_event_ErrorcodeOption, LV_EVENT_ALL, singleerror->Errorlevel);
    //lv_obj_add_event_cb(singleerror->parent, ui_event_PanelErrorHistoryInfo, LV_EVENT_ALL, singleerror->Errorlevel);
    return singleerror;
}

void service_page_refresh_laserstate(int laser_state)
{
    if(laser_state)
        lv_obj_clear_flag(ui_ImageLaserService, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageLaserService, LV_OBJ_FLAG_HIDDEN);
}

void service_page_refresh_camerastate(int camera_state)
{
    if(camera_state)
        lv_obj_clear_flag(ui_ImageCameraService, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageCameraService, LV_OBJ_FLAG_HIDDEN);
}

void service_page_set_wifi_status(int intensity)
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
        case 0:lv_img_set_src(ui_ImageWifiService, &ui_img_wifinosignel_png);break;
        case 1:lv_img_set_src(ui_ImageWifiService, &ui_img_wifismall_png);break;
        case 2:lv_img_set_src(ui_ImageWifiService, &ui_img_wifimid_png);break;
        case 3:lv_img_set_src(ui_ImageWifiService, &ui_img_wififull_png);break;
        default:lv_img_set_src(ui_ImageWifiService, &ui_img_wififull_png);break;
    }
    wifi_Intensity = intensity;
}

MenuItem_t *CreateServiceListItem(lv_obj_t *parent, uint8_t index, int16_t pos_x, int16_t pos_y, void (*part_event_callback)(lv_event_t *))
{
    MenuItem_t *part = (MenuItem_t *)lv_mem_alloc(sizeof(MenuItem_t));
    if ( !part )
        return NULL;

    lv_obj_t * ui_ServicesItemPanelInfo = lv_obj_create(parent);
    lv_obj_set_width(ui_ServicesItemPanelInfo, 545);//534
    lv_obj_set_height(ui_ServicesItemPanelInfo, 56);
    lv_obj_set_x(ui_ServicesItemPanelInfo, pos_x);
    lv_obj_set_y(ui_ServicesItemPanelInfo, pos_y);
    lv_obj_add_flag(ui_ServicesItemPanelInfo, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    //lv_obj_align_to(ui_ServicesItemPanelInfo, ui_SettingstitleSystem, LV_ALIGN_TOP_LEFT, 10, 10);
   // lv_obj_align(ui_ServicesItemPanelInfo, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_clear_flag(ui_ServicesItemPanelInfo, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_ServicesItemPanelInfo, lv_color_hex(0x18181B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ServicesItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ServicesItemPanelInfo, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ServicesItemPanelInfo, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_ServicesItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ServicesItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_ServicesItemPanelInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式设置
    //lv_obj_set_style_border_width(ui_ServicesItemPanelInfo, 3, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui_ServicesItemPanelInfo, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_ServicesItemPanelInfo, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_ServicesItemPanelInfo, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_ServicesItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    part->part_panel = ui_ServicesItemPanelInfo;
    
    //设置列表项名
    lv_obj_t * ui_ServicesItemName = lv_label_create(ui_ServicesItemPanelInfo);
    lv_obj_set_width(ui_ServicesItemName, LV_SIZE_CONTENT); //261
    lv_obj_set_height(ui_ServicesItemName, LV_SIZE_CONTENT); //30
    lv_obj_align(ui_ServicesItemName, LV_ALIGN_LEFT_MID, 13, 1);
    lv_label_set_text(ui_ServicesItemName,"");
     lv_obj_clear_flag(ui_ServicesItemName, LV_OBJ_FLAG_SCROLLABLE); 
   // lv_label_set_text(ui_ServicesItemName, ScreenBrightnessArray[language_index]);
    lv_obj_set_style_text_color(ui_ServicesItemName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ServicesItemName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ServicesItemName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ServicesItemName, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ServicesItemName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_item_name = ui_ServicesItemName;
    
    //右箭头图
    lv_obj_t *ui_ImageArrow = lv_img_create(ui_ServicesItemPanelInfo);
    lv_img_set_src(ui_ImageArrow, &ui_img_rightarrow_png);
    lv_obj_set_width(ui_ImageArrow, 11);  //11 LV_SIZE_CONTENT
    lv_obj_set_height(ui_ImageArrow, 21);    
    lv_obj_align(ui_ImageArrow, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageArrow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    part->img_arrow_png = ui_ImageArrow;

    // //设置列表内容
    // lv_obj_t * ui_ServicesContentName = lv_label_create(ui_ServicesItemPanelInfo);
    // lv_obj_set_width(ui_ServicesItemName, LV_SIZE_CONTENT);
    // lv_obj_set_height(ui_ServicesItemName, LV_SIZE_CONTENT); //39
    // lv_obj_align(ui_ServicesItemName, LV_ALIGN_RIGHT_MID, -40, 1);
    // //lv_obj_align_to(ui_ServicesItemName, ui_ImageArrow, LV_ALIGN_OUT_LEFT_MID, -20, 0);
    // lv_label_set_text(ui_ServicesItemName,"");
    // lv_obj_set_style_text_color(ui_ServicesItemName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ServicesItemName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_ServicesItemName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_ServicesItemName, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_all(ui_ServicesItemName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_clear_flag(ui_ServicesItemName, LV_OBJ_FLAG_SCROLLABLE);

    // part->label_content_name = ui_ServicesItemName;

    part->index = index;
    lv_obj_add_event_cb(ui_ServicesItemPanelInfo, part_event_callback, LV_EVENT_ALL, part); //事件回调接口
    
    return part;
}

MenuItem_t *CreateNormalListItem(lv_obj_t *parent, uint8_t index, int16_t pos_x, int16_t pos_y, void (*part_event_callback)(lv_event_t *))
{
    MenuItem_t *part = (MenuItem_t *)lv_mem_alloc(sizeof(MenuItem_t));
    if ( !part )
        return NULL;

    lv_obj_t * ui_ServicesItemPanelInfo = lv_obj_create(parent);
    lv_obj_set_width(ui_ServicesItemPanelInfo, 530);//534
    lv_obj_set_height(ui_ServicesItemPanelInfo, 56);
    // lv_obj_set_x(ui_ServicesItemPanelInfo, pos_x);
    // lv_obj_set_y(ui_ServicesItemPanelInfo, pos_y);
    lv_obj_add_flag(ui_ServicesItemPanelInfo, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    //lv_obj_align_to(ui_ServicesItemPanelInfo, ui_SettingstitleSystem, LV_ALIGN_TOP_LEFT, 10, 10);
   // lv_obj_align(ui_ServicesItemPanelInfo, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_clear_flag(ui_ServicesItemPanelInfo, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_ServicesItemPanelInfo, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ServicesItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ServicesItemPanelInfo, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ServicesItemPanelInfo, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_ServicesItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ServicesItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_ServicesItemPanelInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式设置
    //lv_obj_set_style_border_width(ui_ServicesItemPanelInfo, 3, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui_ServicesItemPanelInfo, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_ServicesItemPanelInfo, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_ServicesItemPanelInfo, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_ServicesItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    part->part_panel = ui_ServicesItemPanelInfo;
    
    //设置列表项名
    lv_obj_t * ui_ServicesItemName = lv_label_create(ui_ServicesItemPanelInfo);
    lv_obj_set_width(ui_ServicesItemName, LV_SIZE_CONTENT); //261
    lv_obj_set_height(ui_ServicesItemName, LV_SIZE_CONTENT); //30
    lv_obj_align(ui_ServicesItemName, LV_ALIGN_LEFT_MID, 13, 1);
    lv_label_set_text(ui_ServicesItemName,"");
     lv_obj_clear_flag(ui_ServicesItemName, LV_OBJ_FLAG_SCROLLABLE); 
   // lv_label_set_text(ui_ServicesItemName, ScreenBrightnessArray[language_index]);
    lv_obj_set_style_text_color(ui_ServicesItemName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ServicesItemName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ServicesItemName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ServicesItemName, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ServicesItemName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_item_name = ui_ServicesItemName;
    
    //右箭头图
    lv_obj_t *ui_ImageArrow = lv_img_create(ui_ServicesItemPanelInfo);
    lv_img_set_src(ui_ImageArrow, &ui_img_rightarrow_png);
    lv_obj_set_width(ui_ImageArrow, 11);  //11 LV_SIZE_CONTENT
    lv_obj_set_height(ui_ImageArrow, 21);    
    lv_obj_align(ui_ImageArrow, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageArrow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_HIDDEN);      /// Flags

    part->img_arrow_png = ui_ImageArrow;
    part->index = index;
    lv_obj_add_event_cb(ui_ServicesItemPanelInfo, part_event_callback, LV_EVENT_ALL, part); //事件回调接口
    
    return part;
}

ErrorMenuItemObj_t *CreateErrorHistoryListItem(lv_obj_t *parent, uint8_t index, void (*part_event_callback)(lv_event_t *))
{
    ErrorMenuItemObj_t *part = (ErrorMenuItemObj_t *)lv_mem_alloc(sizeof(ErrorMenuItemObj_t));
    if ( !part )
        return NULL;

    //单条菜单面板
    lv_obj_t * ui_HistoryErrorItemPanelInfo = lv_obj_create(parent);
    lv_obj_set_width(ui_HistoryErrorItemPanelInfo, 523);//534
    lv_obj_set_height(ui_HistoryErrorItemPanelInfo, 60);
    // lv_obj_set_x(ui_HistoryErrorItemPanelInfo, pos_x);
    // lv_obj_set_y(ui_HistoryErrorItemPanelInfo, pos_y);
    lv_obj_add_flag(ui_HistoryErrorItemPanelInfo, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    //lv_obj_align_to(ui_HistoryErrorItemPanelInfo, ui_SettingstitleSystem, LV_ALIGN_TOP_LEFT, 10, 10);
   // lv_obj_align(ui_HistoryErrorItemPanelInfo, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_clear_flag(ui_HistoryErrorItemPanelInfo, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_HistoryErrorItemPanelInfo, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HistoryErrorItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_HistoryErrorItemPanelInfo, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_HistoryErrorItemPanelInfo, lv_color_hex(0x9398A1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_HistoryErrorItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_HistoryErrorItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_HistoryErrorItemPanelInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式设置
    //lv_obj_set_style_border_width(ui_HistoryErrorItemPanelInfo, 3, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui_HistoryErrorItemPanelInfo, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_HistoryErrorItemPanelInfo, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_HistoryErrorItemPanelInfo, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_HistoryErrorItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    part->part_panel = ui_HistoryErrorItemPanelInfo;
    
    //错误码标签
    lv_obj_t * ui_LabelErrorCode = lv_label_create(ui_HistoryErrorItemPanelInfo);
    lv_obj_set_width(ui_LabelErrorCode, LV_SIZE_CONTENT); //261
    lv_obj_set_height(ui_LabelErrorCode, LV_SIZE_CONTENT); //30
    lv_obj_align(ui_LabelErrorCode, LV_ALIGN_LEFT_MID, 13, 1);
    lv_label_set_text(ui_LabelErrorCode,"");
    lv_obj_clear_flag(ui_LabelErrorCode, LV_OBJ_FLAG_SCROLLABLE); 
   // lv_label_set_text(ui_LabelErrorCode, ScreenBrightnessArray[language_index]);
    lv_obj_set_style_text_color(ui_LabelErrorCode, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelErrorCode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelErrorCode, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelErrorCode, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_LabelErrorCode, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_error_code = ui_LabelErrorCode;

    //设置列表内容
    lv_obj_t * ui_LabelErrorTime = lv_label_create(ui_HistoryErrorItemPanelInfo);
    lv_obj_set_width(ui_LabelErrorTime, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelErrorTime, LV_SIZE_CONTENT); //39
    lv_obj_align(ui_LabelErrorTime, LV_ALIGN_CENTER, 0, 0);
    //lv_obj_align_to(ui_LabelErrorTime, ui_ImageArrow, LV_ALIGN_OUT_LEFT_MID, -20, 0);
    lv_label_set_text(ui_LabelErrorTime,"");
    lv_obj_set_style_text_color(ui_LabelErrorTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelErrorTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelErrorTime, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelErrorTime, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_LabelErrorTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_LabelErrorTime, LV_OBJ_FLAG_SCROLLABLE);
    part->label_error_time = ui_LabelErrorTime;
    
    //错误详情
    lv_obj_t * ui_LabelErrorDetail = lv_label_create(ui_HistoryErrorItemPanelInfo);
    lv_obj_set_width(ui_LabelErrorDetail, 90);
    lv_obj_set_height(ui_LabelErrorDetail, LV_SIZE_CONTENT); //39
    //lv_obj_align(ui_LabelErrorDetail, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align(ui_LabelErrorDetail, LV_ALIGN_RIGHT_MID, -20, 0);
    //lv_obj_align_to(ui_LabelErrorDetail, ui_ImageArrow, LV_ALIGN_OUT_LEFT_MID, -20, 0);
    lv_label_set_text(ui_LabelErrorDetail, ErrorBtnInfo[get_cur_language_index()]);
    lv_label_set_long_mode(ui_LabelErrorDetail, LV_LABEL_LONG_SCROLL);
    lv_obj_set_style_text_color(ui_LabelErrorDetail, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelErrorDetail, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelErrorDetail, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelErrorDetail, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_LabelErrorDetail, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_LabelErrorDetail, LV_OBJ_FLAG_SCROLLABLE);
    part->label_error_detail = ui_LabelErrorDetail;
 
    part->index = index;
    lv_obj_add_event_cb(ui_HistoryErrorItemPanelInfo, part_event_callback, LV_EVENT_ALL, part); //事件回调接口
    
    return part;
}

void MenuItemCommonStyleInit(MenuItem_t *part, const char *item_name, bool IsShowArrow)
{
    if (!part || !item_name)
        return;   
    lv_label_set_text(part->label_item_name, item_name);
    if (IsShowArrow)
    {
        lv_obj_clear_flag(part->img_arrow_png, LV_OBJ_FLAG_HIDDEN);
    }
    else {
        lv_obj_add_flag(part->img_arrow_png, LV_OBJ_FLAG_HIDDEN);
    }
}

//TODO:页面切换和聚集切换要完善
void ShowMenuSubPage(SubPageType_t PageType)
{
    lv_obj_add_flag(ui_PanelRightServicePage, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelFAQ, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelOnlineManual, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelPrintHistory, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelErrorHistory, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelExportLog, LV_OBJ_FLAG_HIDDEN);

    switch (PageType)
    {
    case MAIN_MENU_PAGE:
        /* code */
        lv_obj_clear_flag(ui_PanelRightServicePage, LV_OBJ_FLAG_HIDDEN);
        break;
    case FAQ_PAGE:
        /* code */
        lv_obj_clear_flag(ui_PanelFAQ, LV_OBJ_FLAG_HIDDEN);
        break;
    case ONLINE_MANUAL_PAGE:
        /* code */
        lv_obj_clear_flag(ui_PanelOnlineManual, LV_OBJ_FLAG_HIDDEN);
        break;
    case PRINT_HISTORY_PAGE:
        /* code */
        lv_obj_clear_flag(ui_PanelPrintHistory, LV_OBJ_FLAG_HIDDEN);
        break;
    case ERROR_HISTORY_PAGE:
        /* code */
        lv_obj_clear_flag(ui_PanelErrorHistory, LV_OBJ_FLAG_HIDDEN);
        //lv_obj_add_flag(ui_ErrorHistoryPanelList, LV_OBJ_FLAG_HIDDEN);
        break;
    case EXPORT_LOG_PAGE:
        /* code */
        lv_obj_clear_flag(ui_PanelExportLog, LV_OBJ_FLAG_HIDDEN);
        break;
    
    default:
        break;
    }
    
}

int GetPrintHistoryItemNum(void)
{
    int printfHistoryCount = 0; 
    if (access(GetuserPrintHistoryRecordPtah(), F_OK) == 0) {
        json_object *jsonObj = json_object_from_file(GetuserPrintHistoryRecordPtah());
        if(jsonObj){
            json_object *listObj = json_object_object_get(jsonObj, "list");
            printfHistoryCount = json_object_array_length(listObj);
            json_object_put(jsonObj);
        }
    }
    CrLogI("printfHistoryCount:%d\n", printfHistoryCount);
    return printfHistoryCount;
}

int GetErrorHistoryItemNum(void)
{
    int ErrorHistoryCount = 0; 
    if (access(GetUserFaultCodeInfoPtah(), F_OK) == 0) {
        json_object *jsonObj = json_object_from_file(GetUserFaultCodeInfoPtah());
        if(jsonObj){
            json_object *listObj = json_object_object_get(jsonObj, "list");
            ErrorHistoryCount = json_object_array_length(listObj);
            json_object_put(jsonObj);
        }
    }
    CrLogI("ErrorHistoryCount:%d\n", ErrorHistoryCount);
    return ErrorHistoryCount;
}

/*打印历史列表单击 */
void HistroyRecordPanelClicked(lv_event_t * e)
{
	// Your code here
    print_history_part_t *part = lv_event_get_user_data(e);
    if ( !part )
        return ;

    //TODO:添加文件不存在处理

    
    // 根据记录中文件名，从文件记录Json中找对应的项，并获取相应的信息填充到预览页面
    if ( part->history_record_index )
    {
        // char *file_name = part_get_dirent_info_name(part); //part_dirent_index(part) 此处索引和gcode打印文件相关联需注意
        preview_set_history_file_info(part->history_record_index);
        // preview_set_file_info(file_name, part->totle_time, part->mater_used, part_dirent_index(part), part->filament_type, part->nozzle_temp, part->bed_temp, FROM_LOCAL);
    }

     // LoadPreviewScreen();
    LoadPage(ui_ScreenPreview, 2);
    preview_set_mode_file_from_dir_type(true);
    
}

void ui_event_PanelPrintHistoryInfo(lv_event_t * e)
{
    static int encoder_last_tick = 0;
    static bool flag = true;
    static uint8_t focuse_cnt = 0;
    static uint16_t preId = 0; 
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int id = 0;

    if(event_code == LV_EVENT_SHORT_CLICKED) {
        id = lv_obj_get_child_id(target);
        HistroyRecordPanelClicked(e);
        CrLogI("LV_EVENT_SHORT_CLICKED.id=%d\n", id);
    }
    if(event_code == LV_EVENT_LONG_PRESSED) {
        id = lv_obj_get_child_id(target);
        CrLogI("LV_EVENT_LONG_PRESSED.id=%d\n", id);
    }
    if(event_code == LV_EVENT_FOCUSED) {        
        focuse_cnt ++;

        int diff = lv_tick_get() - encoder_last_tick;
        encoder_last_tick = lv_tick_get();
        id = lv_obj_get_child_id(target);
        
        if (id && id > preId)
        {
           // printf("右旋\n");
            if(get_is_local_disk() == true && id % 3 == 0) {
                

            }
        }
        else if (id && id < preId )
        {
            if(get_is_local_disk() == false) {
                
            }
            
            //printf("左旋\n");
        }
        preId = id;

        CrLogI("id=%d\n",id);
        if(diff < 50)
        {   
            if(flag){
                flag=false;
                CrLogI("lv_group_focus_next\n");
                lv_group_focus_next(encoder_group);
            }else{
                if (focuse_cnt%2 == 0)
                    flag=true;
            }
           // 
           // lv_group_focus_freeze(FileManage.GropName, true);
              
             // lv_tick_inc(100);
            
        }
       // lv_group_focus_freeze(FileManage.GropName, false);        
    }
}

//这个是回调的回调函数，在回调函数里已经调用BackPrepage，所以这里不需要BackPrepage了
// void ErrorHistoryConfirmBntCb(void)
// {
//     selftest_messagebox_close();
//     //BackPrepage(true);
// }

void ErrorRecordPanelClicked(lv_event_t * e)
{
	// Your code here
    // ErrorMenuItemObj_t *part = lv_event_get_user_data(e);
    // if ( !part )
    //     return ;

    // char title[36] = {0};
    // snprintf(title, 36, "%s%d", ErrorTitile2[get_cur_language_index()], part->error_info.code);

    // char message[256] = {0};
    // snprintf(message, 256, "%s", part->error_info.msg);

    // void (*btns_callback[2])(void) = {&ErrorHistoryConfirmBntCb, NULL};
    // create_selftest_messagebox(title, message, Confirm[get_cur_language_index()], NULL, btns_callback);
    
    lv_obj_t * codevalue = lv_event_get_user_data(e);
    CrLogI("load errorcode msgoption page.%d",atoi(lv_label_get_text(codevalue)));
    uint8_t language_index = get_cur_language_index();
    if(atoi(lv_label_get_text(codevalue)) <= 200)//
    {
        void (*btns_callback[2])(void) = {&faultcodemsg_close, &upload_faultcodemsg};
        create_selftest_messagebox(KindTips[language_index], get_errorcode_info(atoi(lv_label_get_text(codevalue))), Confirm[language_index],  UploadLog[language_index], btns_callback);
    }
    else
    {
        void (*btns_callback[2])(void) = {NULL, &faultcodemsg_close};
        create_selftest_messagebox(KindTips[language_index], get_errorcode_info(atoi(lv_label_get_text(codevalue))), NULL, Confirm[language_index], btns_callback);
    }
}

void ui_event_PanelErrorHistoryInfo(lv_event_t * e)
{
    static int encoder_last_tick = 0;
    static bool flag = true;
    static uint8_t focuse_cnt = 0;
    static uint16_t preId = 0; 
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int id = 0;
    
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        //TODO:显示错误弹框
        ErrorRecordPanelClicked(e);
        CrLogI("LV_EVENT_SHORT_CLICKED.id=%d\n", id);
    }
    // if(event_code == LV_EVENT_LONG_PRESSED) {
    //    // id = lv_obj_get_child_id(target);
    //     printf("LV_EVENT_LONG_PRESSED.id=%d\n", id);
    // }
    if(event_code == LV_EVENT_FOCUSED) {        
        //static uint8_t index = 0;
        ///lv_group_get_focused();
        id = lv_obj_get_child_id(target);
        focuse_cnt ++;

        int diff = lv_tick_get() - encoder_last_tick;
        encoder_last_tick = lv_tick_get();
        
        lv_obj_set_style_text_color(ErrorHistoryMenuPool[id]->Option, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT); 
        
        if (id && id > preId)
        {
           // printf("右旋\n");
            if(get_is_local_disk() == true && id % 3 == 0) {
                

            }
        }
        else if (id && id < preId )
        {
            if(get_is_local_disk() == false) {
                
            }
            
            //printf("左旋\n");
        }
        preId = id;

        CrLogI("id=%d\n",id);
        if(diff < 50)
        {   
            if(flag){
                flag=false;
                //printf("lv_group_focus_next\n");
                lv_group_focus_next(encoder_group);
            }else{
                if (focuse_cnt%2 == 0)
                    flag=true;
            }
           // 
           // lv_group_focus_freeze(FileManage.GropName, true);
              
             // lv_tick_inc(100);
            
        }
       // lv_group_focus_freeze(FileManage.GropName, false);        
    }
    if(event_code == LV_EVENT_DEFOCUSED) { 
        id = lv_obj_get_child_id(target);    
        lv_obj_set_style_text_color(ErrorHistoryMenuPool[id]->Option, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT); 
    }
}

print_history_part_t *CreateCustomPrintHistoryPart(lv_obj_t *parent, void (*part_event_callback)(lv_event_t *))
{
    print_history_part_t *part = (print_history_part_t *)lv_mem_alloc(sizeof(print_history_part_t));
    if ( !part )
        return NULL;

    lv_obj_t *ui_PanelHistoryColumn = lv_obj_create(parent);
    lv_obj_set_width(ui_PanelHistoryColumn, 523);
    lv_obj_set_height(ui_PanelHistoryColumn, 90);
    // lv_obj_set_x(ui_PanelHistoryColumn, pos_x);
    // lv_obj_set_y(ui_PanelHistoryColumn, pos_y);
    lv_obj_add_flag(ui_PanelHistoryColumn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_PanelHistoryColumn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelHistoryColumn, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHistoryColumn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_set_style_border_side(ui_PanelHistoryColumn, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_border_side(ui_PanelHistoryColumn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_PanelHistoryColumn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelHistoryColumn, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelHistoryColumn, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelHistoryColumn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式                              
    lv_obj_set_style_bg_color(ui_PanelHistoryColumn, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_PanelHistoryColumn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_PanelHistoryColumn, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_PanelHistoryColumn, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_PanelHistoryColumn, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_pad_all(ui_PanelHistoryColumn, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    
    part->parent = parent;
    part->history_panel = ui_PanelHistoryColumn;

    lv_obj_t *ui_ImageHistoryThumbnail = lv_img_create(ui_PanelHistoryColumn);
    lv_obj_set_width(ui_ImageHistoryThumbnail, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageHistoryThumbnail, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_ImageHistoryThumbnail, 0);
    lv_obj_set_y(ui_ImageHistoryThumbnail, -6);
    lv_obj_add_flag(ui_ImageHistoryThumbnail, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHistoryThumbnail, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(ui_ImageHistoryThumbnail, &ui_img_crealitylogo96_png);
    lv_img_set_zoom(ui_ImageHistoryThumbnail, 220);
    part->img_thumbnail = ui_ImageHistoryThumbnail;

    lv_obj_t *ui_LabelHistoryFileName = lv_label_create(ui_PanelHistoryColumn);
    lv_obj_set_width(ui_LabelHistoryFileName, 261);
    lv_obj_set_height(ui_LabelHistoryFileName, 34);
    lv_obj_set_x(ui_LabelHistoryFileName, 92);    //不变
    lv_obj_set_y(ui_LabelHistoryFileName, 8);
    lv_label_set_long_mode(ui_LabelHistoryFileName, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_LabelHistoryFileName, "");
    lv_obj_set_style_text_color(ui_LabelHistoryFileName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHistoryFileName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHistoryFileName, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_file_name = ui_LabelHistoryFileName;

    lv_obj_t *ui_LabelHistoryStartTime = lv_label_create(ui_PanelHistoryColumn);
    lv_obj_set_width(ui_LabelHistoryStartTime, 216);
    lv_obj_set_height(ui_LabelHistoryStartTime, 27);
    lv_obj_set_x(ui_LabelHistoryStartTime, 92);  // 236 + 100
    lv_obj_set_y(ui_LabelHistoryStartTime, 51);
    lv_label_set_long_mode(ui_LabelHistoryStartTime, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelHistoryStartTime, "");
    lv_obj_set_style_text_color(ui_LabelHistoryStartTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHistoryStartTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_align(ui_LabelHistoryStartTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHistoryStartTime, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_start_time = ui_LabelHistoryStartTime;

    lv_obj_t *ui_LabelHistoryTotleTime = lv_label_create(ui_PanelHistoryColumn);
    lv_obj_set_width(ui_LabelHistoryTotleTime, 91);
    lv_obj_set_height(ui_LabelHistoryTotleTime, 27);
    lv_obj_set_x(ui_LabelHistoryTotleTime, 340);   //368 + 100
    lv_obj_set_y(ui_LabelHistoryTotleTime, 51);
    lv_label_set_long_mode(ui_LabelHistoryTotleTime, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelHistoryTotleTime, "");
    lv_obj_set_style_text_color(ui_LabelHistoryTotleTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHistoryTotleTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHistoryTotleTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHistoryTotleTime, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_real_totle_time = ui_LabelHistoryTotleTime;

    lv_obj_t *ui_ImageStatus = lv_img_create(ui_PanelHistoryColumn);
    lv_img_set_src(ui_ImageStatus, &ui_img_cross_png);
    lv_obj_set_width(ui_ImageStatus, 30);
    lv_obj_set_height(ui_ImageStatus, 30);
    lv_obj_set_x(ui_ImageStatus, 480);   //514
    lv_obj_set_y(ui_ImageStatus, 10);
    lv_obj_add_flag(ui_ImageStatus, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    part->img_state = ui_ImageStatus;

    // lv_obj_t *ui_ButtonPrintAgain = lv_btn_create(ui_PanelHistoryColumn);
    // lv_obj_set_width(ui_ButtonPrintAgain, 100);
    // lv_obj_set_height(ui_ButtonPrintAgain, 50);
    // lv_obj_set_x(ui_ButtonPrintAgain, 571);
    // lv_obj_set_y(ui_ButtonPrintAgain, 0);
    // lv_obj_add_flag(ui_ButtonPrintAgain, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_ButtonPrintAgain, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_ButtonPrintAgain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ButtonPrintAgain, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonPrintAgain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_ButtonPrintAgain, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_ButtonPrintAgain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_ButtonPrintAgain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_ofs_x(ui_ButtonPrintAgain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_ofs_y(ui_ButtonPrintAgain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_color(ui_ButtonPrintAgain, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ButtonPrintAgain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_ButtonPrintAgain, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_color(ui_ButtonPrintAgain, lv_color_hex(0x4190A2),
    //                               LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_ButtonPrintAgain, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_ButtonPrintAgain, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    // part->btn_print_again = ui_ButtonPrintAgain;

    // lv_obj_t *ui_LabelPrintAgain = lv_label_create(ui_ButtonPrintAgain);
    // lv_obj_set_width(ui_LabelPrintAgain, 96);
    // lv_obj_set_height(ui_LabelPrintAgain, 30);
    // lv_obj_set_x(ui_LabelPrintAgain, -18);
    // lv_obj_set_y(ui_LabelPrintAgain, 0);
    // lv_label_set_long_mode(ui_LabelPrintAgain, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_LabelPrintAgain, PrintAgain[get_cur_language_index()]);
    // lv_obj_set_style_text_align(ui_LabelPrintAgain, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_LabelPrintAgain, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // part->lable_print_again = ui_LabelPrintAgain;

    part->history_record_index = 0;

    lv_obj_add_event_cb(part->history_panel, part_event_callback, LV_EVENT_ALL, part);

    return part;
}

bool PrintHistoryMenuPoolManager(uint16_t NewPrintHistoryNum)
{
    static uint16_t PrintHistoryNum = 0;
    //static int ui_PanelListY = 0;
    print_history_part_t **NewHistoryMenuPool = NULL;

    if(PrintHistoryNum == NewPrintHistoryNum)
    {//无需任何改变
        CrLogI("No need to change PrintHistoryMenuPool!!!");
        return true;
    }
    else if (PrintHistoryNum < NewPrintHistoryNum)
    {//增加池空间，增加菜单项
        //给菜单池分配新的空间
        NewHistoryMenuPool = (print_history_part_t **)calloc(NewPrintHistoryNum, sizeof(print_history_part_t *));
        if(NewHistoryMenuPool == NULL)
        {
            CrLogE("NewHistoryMenuPool malloc fail!!!");
            return false;
        }

        //已经创建过的情况，并把内容拷贝到新空间，释放旧空间
        if(listPanel)
        {
            memcpy(NewHistoryMenuPool, listPanel, PrintHistoryNum * sizeof(print_history_part_t *));
            free(listPanel);
        }
        
        //添加菜单项
        for (size_t i = PrintHistoryNum; i < NewPrintHistoryNum; i++)
        {
            NewHistoryMenuPool[i] = CreateCustomPrintHistoryPart(ui_PrintHistoryPanelList, &ui_event_PanelPrintHistoryInfo);
            //ui_PanelListY += 100;
        }
        
        listPanel = NewHistoryMenuPool;
        PrintHistoryNum = NewPrintHistoryNum;
    }
    else if (PrintHistoryNum > NewPrintHistoryNum)
    {//减少池空间，减少菜单项
        //给菜单池分配新的空间
        if (NewPrintHistoryNum == 0)
        {//考虑减少到0个的极端情况
            NewHistoryMenuPool = NULL;
        }
        else 
        {
            NewHistoryMenuPool = (print_history_part_t **)calloc(NewPrintHistoryNum, sizeof(print_history_part_t *));
            if(NewHistoryMenuPool == NULL)
            {
                CrLogE("NewHistoryMenuPool malloc fail!!!");
                return false;
            }
        }
        
        //减少菜单项，释放退出面板对象占用空间
        for (size_t i = NewPrintHistoryNum; i < PrintHistoryNum; i++) 
        {
            lv_obj_del(listPanel[i]->history_panel);
            lv_mem_free(listPanel[i]);
            listPanel[i] = NULL;
            //ui_PanelListY -= 100;
            // part_array[i] = create_custom_dirent_info_part(ui_PanelFileList, 9, ui_PanelFileListY, &ui_event_PanelFileInfo);
        }
        if (listPanel != NULL) {
            if(NewPrintHistoryNum)
            {
                memcpy(NewHistoryMenuPool, listPanel, NewPrintHistoryNum * sizeof(print_history_part_t *));
            }
            free(listPanel);
        }
        listPanel = NewHistoryMenuPool;
        PrintHistoryNum = NewPrintHistoryNum;
    }
    CrLogI("PrintHistoryMenuPoolManager\n");
    return true;
}

//管理错误菜单池，根据传入的菜单个数，动态调整菜单池空间大小和菜单个数
bool ErrorMenuPoolManager(uint16_t newErrorHistoryNum)
{
    static uint16_t ErrorHistoryNum = 0;
    //static int ui_PanelListY = 0;
    ErrorMenuItemObj_t **NewErrorMenuPool = NULL;

    if(ErrorHistoryNum == newErrorHistoryNum)
    {//无需任何改变
        CrLogI("No need to change NewErrorMenuPool!!!");
        return true;
    }
    else if (ErrorHistoryNum < newErrorHistoryNum)
    {//增加池空间，增加菜单项
        //给菜单池分配新的空间
        NewErrorMenuPool = (ErrorMenuItemObj_t **)calloc(newErrorHistoryNum, sizeof(ErrorMenuItemObj_t *));
        if(NewErrorMenuPool == NULL)
        {
            CrLogE("NewErrorMenuPool malloc fail!!!");
            return false;
        }

        //已经创建过的情况，并把内容拷贝到新空间，释放旧空间
        if(ErrorMenuPool)
        {
            memcpy(NewErrorMenuPool, ErrorMenuPool, ErrorHistoryNum * sizeof(ErrorMenuItemObj_t *));
            free(ErrorMenuPool);
        }
        
        //添加菜单项
        for (size_t i = ErrorHistoryNum; i < newErrorHistoryNum; i++)
        {
            NewErrorMenuPool[i] = CreateErrorHistoryListItem(ui_ErrorHistoryPanelList, i, &ui_event_PanelErrorHistoryInfo);
            //ui_PanelListY += 68;
        }
        
        ErrorMenuPool = NewErrorMenuPool;
        ErrorHistoryNum = newErrorHistoryNum;
    }
    else if (ErrorHistoryNum > newErrorHistoryNum)
    {//减少池空间，减少菜单项
        //给菜单池分配新的空间
        if (newErrorHistoryNum == 0)
        {//考虑减少到0个的极端情况
            NewErrorMenuPool = NULL;
        }
        else 
        {
            NewErrorMenuPool = (ErrorMenuItemObj_t **)calloc(newErrorHistoryNum, sizeof(ErrorMenuItemObj_t *));
            if(NewErrorMenuPool == NULL)
            {
                CrLogE("NewErrorMenuPool malloc fail!!!");
                return false;
            }
        }
        
        //减少菜单项，释放退出面板对象占用空间
        for (size_t i = newErrorHistoryNum; i < ErrorHistoryNum; i++) 
        {
            lv_obj_del(ErrorMenuPool[i]->part_panel);
            lv_mem_free(ErrorMenuPool[i]);
        }
        if (ErrorMenuPool != NULL) {
            if(newErrorHistoryNum)
            {
                memcpy(NewErrorMenuPool, ErrorMenuPool, newErrorHistoryNum * sizeof(ErrorMenuItemObj_t *));
            }
            free(ErrorMenuPool);
        }
        ErrorMenuPool = NewErrorMenuPool;
        ErrorHistoryNum = newErrorHistoryNum;
    }
    CrLogI("ErrorMenuPoolManager\n");
    return true;
}

void ShowPartRecordInfo(print_history_part_t *part, print_record_info_t *RecordInfo)
{
    if ( !part )
        return;

    part->history_record_index = RecordInfo->recode_index;
    CrLogI("recode_index :%d",RecordInfo->recode_index);
    if (part->label_file_name)
    {
        if (RecordInfo->file_name && (strlen(RecordInfo->file_name) > 0))
        {
            char *ch = strrchr(RecordInfo->file_name, '.');
            if ( ch )
                *ch = '\0';
                
            lv_label_set_text(part->label_file_name, RecordInfo->file_name);
        }
        else
        {
            lv_label_set_text(part->label_file_name, "");
        }
    }

    if ( part->img_thumbnail )
    {
        if ( !RecordInfo->thumbnail_name || strlen(RecordInfo->thumbnail_name) <= 0 )
            lv_img_set_src(part->img_thumbnail, &ui_img_crealitylogo76_png); 
        else
        {
            char buff[258] = {0};
            snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, RecordInfo->thumbnail_name);
            //printf("img_thumbnail: %s\n", buff);
            lv_img_set_src(part->img_thumbnail, buff);
        }

    }

    if ( part->label_real_totle_time )
    {
        int32_t time = RecordInfo->print_used_time / 60; // trans to minter
        char buff[20] = {0};
        sprintf(buff, "%dh%0dm", time / 60, time % 60);
        lv_label_set_text(part->label_real_totle_time, buff);
    }
    
    if (part->img_state)
        lv_img_set_src(part->img_state, RecordInfo->state_ok ? &ui_img_hook_png : &ui_img_cross_png);

    if ( part->history_panel )
    {
        // if ( is_print_file_exsit )
        // {
        //     lv_obj_add_flag(part->history_panel, LV_OBJ_FLAG_CLICKABLE);
        // }
        // else
        // {
        //     lv_obj_clear_flag(part->history_panel, LV_OBJ_FLAG_CLICKABLE);
        // } 
    }

    if ( part->label_start_time )
    {
        time_t timesteamp = (time_t)RecordInfo->start_time;//atol(start_time);
        struct tm *CurTime = localtime(&timesteamp);
        char timepath[20] = {0};
        snprintf(timepath , sizeof(timepath) ,"%d %02d %02d %02d: %02d",
                                    CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
                                    CurTime->tm_hour, CurTime->tm_min);
        lv_label_set_text(part->label_start_time, timepath);   //打印时间
    }
    
    // if ( part->btn_print_again )
    //     if ( is_print_file_exsit )
    //         lv_obj_add_flag(part->btn_print_again, LV_OBJ_FLAG_CLICKABLE);
    //     else
    //         lv_obj_clear_flag(part->btn_print_again, LV_OBJ_FLAG_CLICKABLE);

    return ;
}

//填充单条菜单信息到菜单面板
void FillSingleErrorInfo(ErrorMenuItemObj_t *part, ErrorMenuItemInfo_t *RecordInfo)
{
    if ( !part )
        return;

    if (part->label_error_code)
    {
        char buff[10] = {0};
        snprintf(buff, 5, "%d", RecordInfo->code);
        lv_label_set_text(part->label_error_code, buff);
    }

    if (part->label_error_time)
    {
        time_t timesteamp = (time_t)RecordInfo->time;//atol(start_time);
        struct tm *CurTime = localtime(&timesteamp);
        char timepath[20] = {0};
        snprintf(timepath , sizeof(timepath) ,"%d %02d %02d %02d: %02d",
                                    CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
                                    CurTime->tm_hour, CurTime->tm_min);
        lv_label_set_text(part->label_error_time, timepath);   //打印时间
    }

    if (part->label_error_detail)
    {
        lv_label_set_text(part->label_error_detail, ErrorBtnInfo[get_cur_language_index()]);
    }

    return ;
}

static void PrintHistoryInfoParse(char *PrintHistoryRecordFile)
{
    print_record_info_t RecordInfo;
    if (access(PrintHistoryRecordFile, F_OK) != 0) 
        return;
    CrLogI("PrintHistoryInfoParse.\n");
    json_object *JsonObj = json_object_from_file(PrintHistoryRecordFile);
    if(JsonObj == NULL)
        return;

    json_object *SubObj = json_object_object_get(JsonObj, "list");
    int RecordTotalNum = json_object_array_length(SubObj);
    
    for (int i = 0; i < RecordTotalNum; i++) 
    {
        json_object *elem = json_object_array_get_idx(SubObj, i);
        if(elem)
        {
            // int id = json_object_get_int(json_object_object_get(elem, "id"));
            //printf("id = %d\n", id);
            RecordInfo.recode_index = i + 1;

            char *filename = json_object_get_string(json_object_object_get(elem, "filename"));
            if (filename)
            {
                CrLogI("filename = %s\n", filename);
                char *buf = strrchr(filename, '/');
                strcpy(RecordInfo.file_name, buf + 1);
            }
            

            char *thumbnail = json_object_get_string(json_object_object_get(elem, "thumbnail"));
            if (thumbnail)
            {
                CrLogI("thumbnail = %s\n", thumbnail);
                strcpy(RecordInfo.thumbnail_name, thumbnail);
            }
            

            int starttime = json_object_get_int(json_object_object_get(elem, "starttime"));
            RecordInfo.start_time = starttime;
            CrLogI("starttime = %d\n", starttime);

            int usagetime = json_object_get_int(json_object_object_get(elem, "usagetime"));
            CrLogI("usagetime = %d\n", usagetime);
            RecordInfo.print_used_time = usagetime;

            int printfinish = json_object_get_int(json_object_object_get(elem, "printfinish"));
            CrLogI("printfinish = %d\n", printfinish);
            RecordInfo.state_ok = printfinish;

            // 文件是否存在
            if (access(filename, F_OK) == 0)
            {
                //printf("文件存在\n");
                RecordInfo.file_exsit = 1;
            }
            else
            {
                CrLogI("%s文件不存在\n", filename);
                RecordInfo.file_exsit = 0;
            }

            ShowPartRecordInfo(listPanel[i], &RecordInfo);
        }  
    }

//PARSE_FAIL:
    json_object_put(JsonObj);
}

static void ErrorHistoryInfoParse(char *ErrorHistoryRecordFile)
{
    if (access(ErrorHistoryRecordFile, F_OK) != 0) 
        return;
    //printf("ErrorHistoryInfoParse.\n");
    json_object *JsonObj = json_object_from_file(ErrorHistoryRecordFile);
    if(JsonObj == NULL)
        return;

    json_object *SubObj = json_object_object_get(JsonObj, "list");
    int RecordTotalNum = json_object_array_length(SubObj);
    
    CrLogI("RecordTotalNum %d\n", RecordTotalNum);
    for (int i = 0; i < RecordTotalNum; i++) 
    {
        json_object *elem = json_object_array_get_idx(SubObj, i);
        if(elem)
        {
            ErrorMenuPool[i]->error_info.time = json_object_get_int64(json_object_object_get(elem, "time"));
            ErrorMenuPool[i]->error_info.code = json_object_get_int(json_object_object_get(elem, "code"));
            ErrorMenuPool[i]->error_info.error = json_object_get_int(json_object_object_get(elem, "error"));
            const char *msg = json_object_get_string(json_object_object_get(elem, "msg"));
            if (msg)
            {
                //printf("msg = %s\n", msg);
                strncpy(ErrorMenuPool[i]->error_info.msg, msg, 256);
            }

            const char *value = json_object_get_string(json_object_object_get(elem, "value"));
            if (value)
            {
                strncpy(ErrorMenuPool[i]->error_info.value, value, 64);
            }
            //printf("start json_object_array_get_idx %d\n", i);
            FillSingleErrorInfo(ErrorMenuPool[i], &ErrorMenuPool[i]->error_info);
            //printf("end json_object_array_get_idx %d\n", i);
        }  
    }

//PARSE_FAIL:
    json_object_put(JsonObj);
}

// static void wait_timerout_handle(lv_timer_t * timer)
// {
//     static uint8_t prePrintHistoryListCount = 0;
//     if(lv_scr_act() == ui_ScreenCustomerServicePage && !lv_obj_has_flag(ui_PanelPrintHistory, LV_OBJ_FLAG_HIDDEN))
//     {
//         HistoryRecordCnt = GetPrintHistoryItemNum();
//         PrintHistoryMenuPoolManager(HistoryRecordCnt);
//         //wait_animmotion(false);
//         if (access(GetuserPrintHistoryRecordPtah(), F_OK) == 0)
//         {
//             printf("========start PrintHistoryInfoParse========\n");
//             PrintHistoryInfoParse(GetuserPrintHistoryRecordPtah());
//         }  
        
//         if(ServiceScreen.stateValue) //二级页面导航模式
//         {
//             if( prePrintHistoryListCount != HistoryRecordCnt) //列表数目发生变化重新映射编码器事件组对象
//                CustomerServicePageChangeObjs(3); 
//         }
            
//        // ui_FileListWaittimer = NULL;
//         prePrintHistoryListCount = HistoryRecordCnt;
//         if (ui_HistoryRecordListWaittimer)
//         {
//             lv_timer_del(ui_HistoryRecordListWaittimer);
//             ui_HistoryRecordListWaittimer = NULL;
//         }

//     }
//     LoadPage(ui_ScreenCustomerServicePage, 3);
// }

void ShowPrintHistoryInfo(uint8_t wait_time)
{
    static uint8_t preFileListCount = 0;

    // wait_animmotion(true);
    // ui_HistoryRecordListWaittimer = lv_timer_create(wait_timerout_handle, 50*wait_time, NULL);
    // lv_timer_set_repeat_count(ui_HistoryRecordListWaittimer, 1);
    if(lv_scr_act() == ui_ScreenCustomerServicePage /* && !lv_obj_has_flag(ui_PanelPrintHistory, LV_OBJ_FLAG_HIDDEN)*/)
    {
        HistoryRecordCnt = GetPrintHistoryItemNum();
        PrintHistoryMenuPoolManager(HistoryRecordCnt);
        if (access(GetuserPrintHistoryRecordPtah(), F_OK) == 0)
        {
           // printf("========start PrintHistoryInfoParse========\n");
            PrintHistoryInfoParse(GetuserPrintHistoryRecordPtah());
        }  

        // if(ServiceScreen.stateValue) //二级页面导航模式
        // {
        //     if( preFileListCount != HistoryRecordCnt) //列表数目发生变化重新映射编码器事件组对象
        //        CustomerServicePageChangeObjs(3); 
        // }

        preFileListCount = HistoryRecordCnt;
    }

    //preFileListCount = GetPrintHistoryItemNum();

    if (preFileListCount == 0)
    {
        lv_obj_clear_flag(ui_LableNoPrintHistoryRecord, LV_OBJ_FLAG_HIDDEN);//显示“空”
    }
    else
    {
        lv_obj_add_flag(ui_LableNoPrintHistoryRecord, LV_OBJ_FLAG_HIDDEN);//显示“空”
    }
}

// //显示错误历史信息
// void ShowErrorHistoryInfo(void)
// {
//     uint16_t CurErrorHistoryCnt = 0;
    
//     if(lv_scr_act() == ui_ScreenCustomerServicePage/* && !lv_obj_has_flag(ui_PanelErrorHistory, LV_OBJ_FLAG_HIDDEN)*/)
//     {
//         //TODO:参照研究院的代码逻辑修改，不是说有错误都需要显示，不用错误码的弹框可能不太一样
//         CurErrorHistoryCnt = GetErrorHistoryItemNum();
//         lv_obj_clear_flag(ui_ErrorHistoryPanelList, LV_OBJ_FLAG_HIDDEN);
//         ErrorMenuPoolManager(CurErrorHistoryCnt);
        
//         if (access(GetUserFaultCodeInfoPtah(), F_OK) == 0)
//         {
//             printf("========start ErrorHistoryInfoParse========\n");
//             ErrorHistoryInfoParse(GetUserFaultCodeInfoPtah());
//         }
//         // if(ServiceScreen.stateValue) //二级页面导航模式
//         // {
//         //     if( ErrorHistoryCnt != CurErrorHistoryCnt) //列表数目发生变化重新映射编码器事件组对象
//         //        CustomerServicePageChangeObjs(3); 
//         // }
//     }

//     if (CurErrorHistoryCnt == 0)
//     {
//         lv_obj_clear_flag(ui_LableNoErrorHistoryRecord, LV_OBJ_FLAG_HIDDEN);//显示“空”
//     }
//     else
//     {
//         lv_obj_add_flag(ui_LableNoErrorHistoryRecord, LV_OBJ_FLAG_HIDDEN);//显示“空”
//     }
//     ErrorHistoryCnt = CurErrorHistoryCnt;
// }

/**
 * @description: 动态显示错误历史
 * @return {*}
 */
void ShowErrorHistoryInfoDynamicly(void)
{
    uint16_t CurErrorHistoryCnt = 0;
    
    if(lv_scr_act() == ui_ScreenCustomerServicePage/* && !lv_obj_has_flag(ui_PanelErrorHistory, LV_OBJ_FLAG_HIDDEN)*/)
    {
        //TODO:参照研究院的代码逻辑修改，不是说有错误都需要显示，不用错误码的弹框可能不太一样
        CurErrorHistoryCnt = GetErrorHistoryItemNum();
        ErrorMenuPoolManager(CurErrorHistoryCnt);
        
        if (access(GetUserFaultCodeInfoPtah(), F_OK) == 0)
        {
           // printf("========start PrintHistoryInfoParse========\n");
            ErrorHistoryInfoParse(GetUserFaultCodeInfoPtah());
        }
        
        // if(ServiceScreen.stateValue) //二级页面导航模式
        // {
        //     if( ErrorHistoryCnt != CurErrorHistoryCnt) //列表数目发生变化重新映射编码器事件组对象
        //        CustomerServicePageChangeObjs(3); 
        // }
    }

    if (CurErrorHistoryCnt == 0)
    {
        lv_obj_clear_flag(ui_LableNoErrorHistoryRecord, LV_OBJ_FLAG_HIDDEN);//显示“空”
    }
    else
    {
        lv_obj_add_flag(ui_LableNoErrorHistoryRecord, LV_OBJ_FLAG_HIDDEN);//显示“空”
    }
    ErrorHistoryCnt = CurErrorHistoryCnt;
}

void ui_ScreenCustomerService_screen_init(void)
{
    ServiceScreen.stateValue = false;

    uint8_t language_index = get_cur_language_index();
    ui_ScreenCustomerServicePage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenCustomerServicePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenCustomerServicePage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCustomerServicePage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_ScreenCustomerServicePage, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_ScreenCustomerServicePage, CustomerServicePageChangeObjs, LoadCustomerServiceScreen);

/*************************************左边导航栏****************************************/
    //左边导航面板
    ui_PanelPageScreenService = lv_obj_create(ui_ScreenCustomerServicePage);
    lv_obj_set_size(ui_PanelPageScreenService, 68, 360);
    lv_obj_set_pos(ui_PanelPageScreenService, 0, 60);
    lv_obj_clear_flag(ui_PanelPageScreenService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelPageScreenService, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_all(ui_PanelPageScreenService, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_PanelPageScreenService, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //home按键
    ui_ButtonHomeScreenService = lv_btn_create(ui_PanelPageScreenService);
    lv_obj_set_size(ui_ButtonHomeScreenService, 68, 72);
    lv_obj_set_pos(ui_ButtonHomeScreenService, -18, -18);
    lv_obj_add_flag(ui_ButtonHomeScreenService, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonHomeScreenService, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ButtonHomeScreenService, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonHomeScreenService, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenService, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonHomeScreenService, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenService, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenService, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonHomeScreenService, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonHomeScreenService, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //准备按键
    ui_ButtonAxisMoveScreenService = lv_btn_create(ui_PanelPageScreenService);
    lv_obj_set_size(ui_ButtonAxisMoveScreenService, 68, 72);
    lv_obj_set_pos(ui_ButtonAxisMoveScreenService, -18, 54);
    lv_obj_add_flag(ui_ButtonAxisMoveScreenService, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveScreenService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonAxisMoveScreenService, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveScreenService, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMoveScreenService, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveScreenService, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveScreenService, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonAxisMoveScreenService, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonAxisMoveScreenService, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //文件按钮
    ui_ButtonFileManageScreenService = lv_btn_create(ui_PanelPageScreenService);
    lv_obj_set_size(ui_ButtonFileManageScreenService, 68, 72);
    lv_obj_set_pos(ui_ButtonFileManageScreenService, -18, 126);
    //lv_obj_align_to(ui_ButtonFileManageScreenService, ui_ButtonAxisMoveScreenService, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_add_flag(ui_ButtonFileManageScreenService, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFileManageScreenService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonFileManageScreenService, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ButtonFileManageScreenService, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonFileManageScreenService, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenService, &ui_img_pagefilemanage_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonFileManageScreenService, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonFileManageScreenService, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonFileManageScreenService, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonFileManageScreenService, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonFileManageScreenService, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //设置按钮
    ui_ButtonSettingsScreenService = lv_btn_create(ui_PanelPageScreenService);
    lv_obj_set_size(ui_ButtonSettingsScreenService, 68, 72);
    lv_obj_set_pos(ui_ButtonSettingsScreenService, -18, 198);
    //lv_obj_align_to(ui_ButtonSettingsScreenService, ui_ButtonFileManageScreenService, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_add_flag(ui_ButtonSettingsScreenService, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonSettingsScreenService, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenService, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenService, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenService, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenService, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonSettingsScreenService, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonSettingsScreenService, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //客服按钮
    //ui_ButtonServicePage = lv_btn_create(ui_PanelPageScreenService);
    ui_ButtonServicePage = lv_obj_create(ui_PanelPageScreenService);
    lv_obj_set_size(ui_ButtonServicePage, 68, 72);
    lv_obj_set_pos(ui_ButtonServicePage, -18, 270);
    lv_obj_add_flag(ui_ButtonServicePage, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonServicePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonServicePage, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonServicePage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonServicePage, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonServicePage, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonServicePage, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonServicePage, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonServicePage, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonServicePage, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonServicePage, 1, LV_PART_MAIN | LV_STATE_PRESSED);

/*************************************右边菜单子页****************************************/
    //客服页面右边菜单面板
    ui_PanelRightServicePage = lv_obj_create(ui_ScreenCustomerServicePage);
    lv_obj_clear_flag(ui_PanelRightServicePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelRightServicePage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelRightServicePage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui_PanelRightServicePage, 68, 60); //页面导航栏宽度为68 
	lv_obj_set_size(ui_PanelRightServicePage, 572, 360);
   // lv_obj_set_align(ui_PanelRightServicePage, LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_radius(ui_PanelRightServicePage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelRightServicePage, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelRightServicePage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_PanelRightServicePage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelRightServicePage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_add_flag(ui_PanelRightServicePage, LV_OBJ_FLAG_HIDDEN);

    //顶部标题状态栏
    ui_PanelTitleAndStatusServicePage = lv_obj_create(ui_PanelRightServicePage);
    lv_obj_set_pos(ui_PanelTitleAndStatusServicePage, 0, 0);
    lv_obj_set_size(ui_PanelTitleAndStatusServicePage, 572, 46);
    lv_obj_clear_flag(ui_PanelTitleAndStatusServicePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelTitleAndStatusServicePage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelTitleAndStatusServicePage, lv_color_hex(0x101011), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTitleAndStatusServicePage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelTitleAndStatusServicePage, lv_color_hex(0x565656), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelTitleAndStatusServicePage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelTitleAndStatusServicePage, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelTitleAndStatusServicePage, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelTitleAndStatusServicePage, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    //帮助标题
    ui_LabelCustomerService = lv_label_create(ui_PanelTitleAndStatusServicePage);
    lv_obj_set_size(ui_LabelCustomerService, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_LabelCustomerService, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_LabelCustomerService, FaqArray[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelCustomerService, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCustomerService, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCustomerService, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LabelCustomerService, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceIconPanel = lv_obj_create(ui_PanelTitleAndStatusServicePage);
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
    ui_ImageLaserService = lv_img_create(ui_DeviceIconPanel);
    lv_obj_set_size(ui_ImageLaserService, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_img_set_src(ui_ImageLaserService, &ui_img_laser_png);
    lv_obj_add_flag(ui_ImageLaserService, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageLaserService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_ImageLaserService, LV_OBJ_FLAG_HIDDEN); 

    //摄像头
    ui_ImageCameraService = lv_img_create(ui_DeviceIconPanel);
    lv_obj_set_size(ui_ImageCameraService, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_img_set_src(ui_ImageCameraService, &ui_img_camera_png);
    lv_obj_add_flag(ui_ImageCameraService, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCameraService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_ImageCameraService, LV_OBJ_FLAG_HIDDEN); 

    //wifi图标
    ui_ImageWifiService = lv_img_create(ui_DeviceIconPanel);
    service_page_set_wifi_status(wifi_Intensity);
    lv_obj_set_size(ui_ImageWifiService, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_add_flag(ui_ImageWifiService, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageWifiService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    
    //客服菜单列表面板
    ui_ServicePanelList = lv_obj_create(ui_PanelRightServicePage);
    lv_obj_set_size(ui_ServicePanelList, 572, 310);
    lv_obj_set_pos(ui_ServicePanelList, 0, 52);
    lv_obj_set_align(ui_ServicePanelList, LV_ALIGN_TOP_LEFT);
    lv_obj_add_flag(ui_ServicePanelList, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ServicePanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ServicePanelList, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ServicePanelList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ServicePanelList, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ServicePanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_ServicePanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ServicePanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    int y_pos_offset = 0;
    for (size_t index = 1; index < 6; index++)
    {
         ServicesArray[index] = CreateServiceListItem(ui_ServicePanelList, index, 9, y_pos_offset, ui_event_ServiceItems);
         y_pos_offset += 60;
    }

    MenuItemCommonStyleInit(ServicesArray[1], FAQ[language_index], true);
    MenuItemCommonStyleInit(ServicesArray[2], OnlineManual[language_index], true);
    MenuItemCommonStyleInit(ServicesArray[3], History[language_index], true);
    MenuItemCommonStyleInit(ServicesArray[4], Errorhistory[language_index], true);
    MenuItemCommonStyleInit(ServicesArray[5], ExportLogArray[language_index], true);


    lv_obj_add_event_cb(ui_ButtonHomeScreenService, ui_event_ButtonHomeScreenService, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonFileManageScreenService, ui_event_ButtonFileManageScreenService, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsScreenService, ui_event_ButtonSettingsScreenService, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMoveScreenService, ui_event_ButtonMoveScreenService, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonServicePage, ui_event_ButtonServicePage, LV_EVENT_ALL, NULL);

    

/*************************************FAQ 子页****************************************/
    //FAQ面板
    ui_PanelFAQ = lv_obj_create(ui_ScreenCustomerServicePage);
    lv_obj_set_pos(ui_PanelFAQ, 76, 68);
    lv_obj_set_size(ui_PanelFAQ, 556, 344);
    lv_obj_set_align(ui_PanelFAQ, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_PanelFAQ, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFAQ, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFAQ, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFAQ, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelFAQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelFAQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelFAQ, LV_OBJ_FLAG_HIDDEN);

    //FAQ标题
    ui_LableFAQTitle = lv_label_create(ui_PanelFAQ);
    lv_obj_set_size(ui_LableFAQTitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align(ui_LableFAQTitle, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_pos(ui_LableFAQTitle, 16, 0);
    lv_label_set_text(ui_LableFAQTitle, FAQ[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableFAQTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableFAQTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableFAQTitle, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableFAQTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //返回按钮
    ui_ButtonBackFAQ = lv_btn_create(ui_PanelFAQ);
    lv_obj_set_size(ui_ButtonBackFAQ, 68, 38);
    lv_obj_set_pos(ui_ButtonBackFAQ, 474, 6);
    lv_obj_add_flag(ui_ButtonBackFAQ, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonBackFAQ, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonBackFAQ, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonBackFAQ, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBackFAQ, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackFAQ, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonBackFAQ, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonBackFAQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonBackFAQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonBackFAQ, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackFAQ, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonBackFAQ, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonBackFAQ, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonBackFAQ, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ButtonBackFAQ, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonBackFAQ, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //上下分割线
    ui_LineFAQDividing = lv_obj_create(ui_PanelFAQ);
    lv_obj_set_size(ui_LineFAQDividing, 543, 1);
    lv_obj_set_pos(ui_LineFAQDividing, 6, 52);
    lv_obj_clear_flag(ui_LineFAQDividing, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_LineFAQDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LineFAQDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_LineFAQDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_LineFAQDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_LineFAQDividing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //FAQ 提示
    ui_LableFAQTip = lv_label_create(ui_PanelFAQ);
    lv_obj_set_size(ui_LableFAQTip, 520, LV_SIZE_CONTENT);
    //lv_obj_align(ui_LableFAQTip, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_pos(ui_LableFAQTip, 16, 55);
    lv_label_set_text(ui_LableFAQTip, FaqTips[get_cur_language_index()]);
    lv_label_set_long_mode(ui_LableFAQTip, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(ui_LableFAQTip, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableFAQTip, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableFAQTip, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_LableFAQTip, -10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableFAQTip, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //FAQ二维码
    ui_ImageFAQQRCode = lv_qrcode_create(ui_PanelFAQ, 143, lv_color_hex(0xFFFFFF), lv_color_hex(0x2D2E31));
    lv_obj_set_width(ui_ImageFAQQRCode, 147);
    lv_obj_set_height(ui_ImageFAQQRCode, 147);
    //lv_obj_set_pos(ui_ImageFAQQRCode, 189, 127);
    lv_obj_align_to(ui_ImageFAQQRCode, ui_LableFAQTip, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_obj_set_style_border_width(ui_ImageFAQQRCode, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ImageFAQQRCode, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ImageFAQQRCode, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageFAQQRCode, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // char FAQUrltemp[64] = {0};
    // snprintf(FAQUrltemp, 64, "https://www.crealitycloud.com/product");
    // lv_qrcode_update(ui_ImageFAQQRCode, FAQUrltemp, strlen(FAQUrltemp));
    lv_qrcode_update(ui_ImageFAQQRCode, "https://www.crealitycloud.com/product", strlen("https://www.crealitycloud.com/product"));


/*************************************在线说明书子页****************************************/
    //在线说明书面板
    ui_PanelOnlineManual = lv_obj_create(ui_ScreenCustomerServicePage);
    lv_obj_set_pos(ui_PanelOnlineManual, 76, 68);
    lv_obj_set_size(ui_PanelOnlineManual, 556, 344);
    lv_obj_set_align(ui_PanelOnlineManual, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_PanelOnlineManual, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelOnlineManual, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelOnlineManual, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelOnlineManual, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelOnlineManual, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelOnlineManual, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelOnlineManual, LV_OBJ_FLAG_HIDDEN);

    //在线说明书标题
    ui_LableOnlineManualTitle = lv_label_create(ui_PanelOnlineManual);
    lv_obj_set_size(ui_LableOnlineManualTitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align(ui_LableOnlineManualTitle, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_pos(ui_LableOnlineManualTitle, 16, 0);
    lv_label_set_text(ui_LableOnlineManualTitle, OnlineManual[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableOnlineManualTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableOnlineManualTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableOnlineManualTitle, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableOnlineManualTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //返回按钮
    ui_ButtonBackOnlineManual = lv_btn_create(ui_PanelOnlineManual);
    lv_obj_set_size(ui_ButtonBackOnlineManual, 68, 38);
    lv_obj_set_pos(ui_ButtonBackOnlineManual, 474, 6);
    lv_obj_add_flag(ui_ButtonBackOnlineManual, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonBackOnlineManual, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonBackOnlineManual, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonBackOnlineManual, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBackOnlineManual, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackOnlineManual, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonBackOnlineManual, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonBackOnlineManual, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonBackOnlineManual, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonBackOnlineManual, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackOnlineManual, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonBackOnlineManual, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonBackOnlineManual, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonBackOnlineManual, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ButtonBackOnlineManual, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonBackOnlineManual, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //上下分割线
    ui_LineOnlineManualDividing = lv_obj_create(ui_PanelOnlineManual);
    lv_obj_set_size(ui_LineOnlineManualDividing, 543, 1);
    lv_obj_set_pos(ui_LineOnlineManualDividing, 6, 52);
    lv_obj_clear_flag(ui_LineOnlineManualDividing, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_LineOnlineManualDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LineOnlineManualDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_LineOnlineManualDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_LineOnlineManualDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_LineOnlineManualDividing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //在线说明书 提示
    ui_LableOnlineManualTip = lv_label_create(ui_PanelOnlineManual);
    lv_obj_set_size(ui_LableOnlineManualTip, 520, LV_SIZE_CONTENT);
    //lv_obj_align(ui_LableOnlineManualTip, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_pos(ui_LableOnlineManualTip, 16, 55);
    lv_label_set_text(ui_LableOnlineManualTip, WikiTips[get_cur_language_index()]);
    lv_label_set_long_mode(ui_LableOnlineManualTip, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(ui_LableOnlineManualTip, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableOnlineManualTip, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableOnlineManualTip, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_LableOnlineManualTip, -10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableOnlineManualTip, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //在线文说明书二维码
    ui_ImageOnlineManualQRCode = lv_qrcode_create(ui_PanelOnlineManual, 143, lv_color_hex(0xFFFFFF), lv_color_hex(0x2D2E31));
    lv_obj_set_width(ui_ImageOnlineManualQRCode, 147);
    lv_obj_set_height(ui_ImageOnlineManualQRCode, 147);
    // lv_obj_set_pos(ui_ImageOnlineManualQRCode, 185, 119);
    lv_obj_align_to(ui_ImageOnlineManualQRCode, ui_LableOnlineManualTip, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_obj_set_style_border_width(ui_ImageOnlineManualQRCode, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ImageOnlineManualQRCode, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ImageOnlineManualQRCode, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageOnlineManualQRCode, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // char OnlineManualUrltemp[64] = {0};
    // snprintf(OnlineManualUrltemp, 64, "https://www.crealitycloud.com/product");
    // lv_qrcode_update(ui_ImageOnlineManualQRCode, OnlineManualUrltemp, strlen(OnlineManualUrltemp));
    lv_qrcode_update(ui_ImageOnlineManualQRCode, "https://www.crealitycloud.com/product", strlen("https://www.crealitycloud.com/product"));


/*************************************打印历史子页****************************************/
    //打印历史面板
    ui_PanelPrintHistory = lv_obj_create(ui_ScreenCustomerServicePage);
    lv_obj_set_pos(ui_PanelPrintHistory, 76, 68);
    lv_obj_set_size(ui_PanelPrintHistory, 556, 344);
    lv_obj_set_align(ui_PanelPrintHistory, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_PanelPrintHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPrintHistory, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPrintHistory, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrintHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelPrintHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelPrintHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelPrintHistory, LV_OBJ_FLAG_HIDDEN);

    //打印历史标题
    ui_LablePrintHistory = lv_label_create(ui_PanelPrintHistory);
    lv_obj_set_size(ui_LablePrintHistory, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align(ui_LablePrintHistory, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_pos(ui_LablePrintHistory, 16, 0);  //6
    lv_label_set_text(ui_LablePrintHistory, History[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LablePrintHistory, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LablePrintHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LablePrintHistory, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LablePrintHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //返回按钮
    ui_ButtonBackPrintHistory = lv_btn_create(ui_PanelPrintHistory);
    lv_obj_set_size(ui_ButtonBackPrintHistory, 68, 38);
    lv_obj_set_pos(ui_ButtonBackPrintHistory, 474, 6);
    lv_obj_add_flag(ui_ButtonBackPrintHistory, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonBackPrintHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonBackPrintHistory, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonBackPrintHistory, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBackPrintHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackPrintHistory, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonBackPrintHistory, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonBackPrintHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonBackPrintHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonBackPrintHistory, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackPrintHistory, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonBackPrintHistory, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonBackPrintHistory, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonBackPrintHistory, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ButtonBackPrintHistory, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonBackPrintHistory, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //上下分割线
    ui_LinePrintHistoryDividing = lv_obj_create(ui_PanelPrintHistory);
    lv_obj_set_size(ui_LinePrintHistoryDividing, 543, 1);
    lv_obj_set_pos(ui_LinePrintHistoryDividing, 6, 52);
    lv_obj_clear_flag(ui_LinePrintHistoryDividing, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_LinePrintHistoryDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LinePrintHistoryDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_LinePrintHistoryDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_LinePrintHistoryDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_LinePrintHistoryDividing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //打印历史列表面板
    ui_PrintHistoryPanelList = lv_obj_create(ui_PanelPrintHistory);
    lv_obj_set_size(ui_PrintHistoryPanelList, 552, 275);
    lv_obj_set_pos(ui_PrintHistoryPanelList, 0, 61);
    lv_obj_set_align(ui_PrintHistoryPanelList, LV_ALIGN_TOP_LEFT);
    lv_obj_add_flag(ui_PrintHistoryPanelList, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PrintHistoryPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PrintHistoryPanelList, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PrintHistoryPanelList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PrintHistoryPanelList, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PrintHistoryPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_PrintHistoryPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PrintHistoryPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_PrintHistoryPanelList, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_left(ui_PrintHistoryPanelList, 9, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_PrintHistoryPanelList, 12, LV_PART_MAIN | LV_STATE_DEFAULT);

    //无记录时显示
    ui_LableNoPrintHistoryRecord = lv_label_create(ui_PanelPrintHistory);
    lv_obj_set_width(ui_LableNoPrintHistoryRecord, 200);
    lv_obj_set_height(ui_LableNoPrintHistoryRecord, 38);
    lv_obj_align(ui_LableNoPrintHistoryRecord, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LableNoPrintHistoryRecord, NoRecords[language_index]);
    lv_obj_add_flag(ui_LableNoPrintHistoryRecord, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_LableNoPrintHistoryRecord, lv_color_hex(0x6A707D),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableNoPrintHistoryRecord, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LableNoPrintHistoryRecord, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableNoPrintHistoryRecord, lv_font25.font,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LableNoPrintHistoryRecord, LV_LABEL_LONG_SCROLL_CIRCULAR);


/*************************************错误历史子页****************************************/
    //错误历史面板
    ui_PanelErrorHistory = lv_obj_create(ui_ScreenCustomerServicePage);
    lv_obj_set_pos(ui_PanelErrorHistory, 76, 68);
    lv_obj_set_size(ui_PanelErrorHistory, 552, 344);
    lv_obj_set_align(ui_PanelErrorHistory, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_PanelErrorHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelErrorHistory, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelErrorHistory, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelErrorHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelErrorHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelErrorHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelErrorHistory, LV_OBJ_FLAG_HIDDEN);

    //错误历史标题
    ui_LableErrorHistory = lv_label_create(ui_PanelErrorHistory);
    lv_obj_set_size(ui_LableErrorHistory, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align(ui_LableErrorHistory, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_pos(ui_LableErrorHistory, 16, 0);
    lv_label_set_text(ui_LableErrorHistory, Errorhistory[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableErrorHistory, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableErrorHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableErrorHistory, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableErrorHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //返回按钮
    ui_ButtonBackErrorHistory = lv_btn_create(ui_PanelErrorHistory);
    lv_obj_set_size(ui_ButtonBackErrorHistory, 68, 38);
    lv_obj_set_pos(ui_ButtonBackErrorHistory, 474, 6);
    lv_obj_add_flag(ui_ButtonBackErrorHistory, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonBackErrorHistory, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonBackErrorHistory, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonBackErrorHistory, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBackErrorHistory, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackErrorHistory, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonBackErrorHistory, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonBackErrorHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonBackErrorHistory, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonBackErrorHistory, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackErrorHistory, lv_color_hex(0xB0F1FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonBackErrorHistory, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonBackErrorHistory, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonBackErrorHistory, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ButtonBackErrorHistory, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonBackErrorHistory, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //上下分割线
    ui_LineErrorHistoryDividing = lv_obj_create(ui_PanelErrorHistory);
    lv_obj_set_size(ui_LineErrorHistoryDividing, 543, 1);
    lv_obj_set_pos(ui_LineErrorHistoryDividing, 6, 52);
    lv_obj_clear_flag(ui_LineErrorHistoryDividing, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_LineErrorHistoryDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LineErrorHistoryDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_LineErrorHistoryDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_LineErrorHistoryDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_LineErrorHistoryDividing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //错误码
    ui_LableErrorCodeTitle = lv_label_create(ui_PanelErrorHistory);
    lv_obj_set_size(ui_LableErrorCodeTitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align(ui_LableErrorCodeTitle, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_pos(ui_LableErrorCodeTitle, 26, 61);
    lv_label_set_text(ui_LableErrorCodeTitle, ErrorCode[get_cur_language_index()]);
    lv_label_set_long_mode(ui_LableErrorCodeTitle, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(ui_LableErrorCodeTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableErrorCodeTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableErrorCodeTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableErrorCodeTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //发生时间
    ui_LableOccurTimeTitle = lv_label_create(ui_PanelErrorHistory);
    lv_obj_set_size(ui_LableOccurTimeTitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LableOccurTimeTitle, LV_ALIGN_TOP_MID, 0, 61);
    //lv_obj_set_pos(ui_LableOccurTimeTitle, 232, 61);
    lv_label_set_text(ui_LableOccurTimeTitle, ErrorTime[get_cur_language_index()]);
    lv_label_set_long_mode(ui_LableOccurTimeTitle, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(ui_LableOccurTimeTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableOccurTimeTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableOccurTimeTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LableOccurTimeTitle, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableOccurTimeTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //操作
    ui_LableOperateTitle = lv_label_create(ui_PanelErrorHistory);
    lv_obj_set_size(ui_LableOperateTitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LableOperateTitle, LV_ALIGN_TOP_RIGHT, -37, 61);
   // lv_obj_set_pos(ui_LableOperateTitle, 457, 61);
    lv_label_set_text(ui_LableOperateTitle, Action[get_cur_language_index()]);
    lv_label_set_long_mode(ui_LableOperateTitle, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(ui_LableOperateTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableOperateTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableOperateTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LableOperateTitle, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableOperateTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //错误历史列表面板
    ui_ErrorHistoryPanelList = lv_obj_create(ui_PanelErrorHistory);
    lv_obj_set_size(ui_ErrorHistoryPanelList, 552, 229);
    lv_obj_set_pos(ui_ErrorHistoryPanelList, 0, 106);
    lv_obj_set_align(ui_ErrorHistoryPanelList, LV_ALIGN_TOP_LEFT);
    lv_obj_add_flag(ui_ErrorHistoryPanelList, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ErrorHistoryPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ErrorHistoryPanelList, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ErrorHistoryPanelList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ErrorHistoryPanelList, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ErrorHistoryPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_ErrorHistoryPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ErrorHistoryPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_ErrorHistoryPanelList, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_left(ui_ErrorHistoryPanelList, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ErrorHistoryPanelList, 8, LV_PART_MAIN | LV_STATE_DEFAULT);


    //无记录时显示
    ui_LableNoErrorHistoryRecord = lv_label_create(ui_PanelErrorHistory);
    lv_obj_set_width(ui_LableNoErrorHistoryRecord, 200);
    lv_obj_set_height(ui_LableNoErrorHistoryRecord, 38);
    lv_obj_align(ui_LableNoErrorHistoryRecord, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LableNoErrorHistoryRecord, NoRecords[language_index]);
    lv_obj_add_flag(ui_LableNoErrorHistoryRecord, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_LableNoErrorHistoryRecord, lv_color_hex(0x6A707D),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableNoErrorHistoryRecord, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LableNoErrorHistoryRecord, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableNoErrorHistoryRecord, lv_font25.font,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LableNoErrorHistoryRecord, LV_LABEL_LONG_SCROLL_CIRCULAR);

/*************************************导出日志子页****************************************/
    //导出日志面板
    ui_PanelExportLog = lv_obj_create(ui_ScreenCustomerServicePage);
    lv_obj_set_pos(ui_PanelExportLog, 76, 68);
    lv_obj_set_size(ui_PanelExportLog, 556, 344);
    lv_obj_set_align(ui_PanelExportLog, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_PanelExportLog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelExportLog, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelExportLog, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelExportLog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelExportLog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelExportLog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelExportLog, LV_OBJ_FLAG_HIDDEN);

    //导出日志标题
    ui_LableExportLog = lv_label_create(ui_PanelExportLog);
    lv_obj_set_size(ui_LableExportLog, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align(ui_LableExportLog, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_pos(ui_LableExportLog, 16, 0);
    lv_label_set_text(ui_LableExportLog, ExportLogArray[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableExportLog, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableExportLog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableExportLog, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableExportLog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //返回按钮
    ui_ButtonBackExportLog = lv_btn_create(ui_PanelExportLog);
    lv_obj_set_size(ui_ButtonBackExportLog, 68, 38);
    lv_obj_set_pos(ui_ButtonBackExportLog, 474, 6);
    lv_obj_add_flag(ui_ButtonBackExportLog, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonBackExportLog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonBackExportLog, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonBackExportLog, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBackExportLog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackExportLog, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonBackExportLog, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonBackExportLog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonBackExportLog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonBackExportLog, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackExportLog, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonBackExportLog, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonBackExportLog, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonBackExportLog, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ButtonBackExportLog, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonBackExportLog, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //上下分割线
    ui_LineExportLogDividing = lv_obj_create(ui_PanelExportLog);
    lv_obj_set_size(ui_LineExportLogDividing, 543, 1);
    lv_obj_set_pos(ui_LineExportLogDividing, 7, 52);
    lv_obj_clear_flag(ui_LineExportLogDividing, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_LineExportLogDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LineExportLogDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_LineExportLogDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_LineExportLogDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_LineExportLogDividing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //导出菜单列表面板
    ui_ExportLogPanelList = lv_obj_create(ui_PanelExportLog);
    lv_obj_set_size(ui_ExportLogPanelList, 540, 275);
    //lv_obj_set_pos(ui_ExportLogPanelList, 0, 61);
    //lv_obj_set_align(ui_ExportLogPanelList, LV_ALIGN_TOP_LEFT);
    lv_obj_align(ui_ExportLogPanelList, LV_ALIGN_TOP_MID, 0, 61);
    lv_obj_add_flag(ui_ExportLogPanelList, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExportLogPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExportLogPanelList, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExportLogPanelList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ExportLogPanelList, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ExportLogPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_ExportLogPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExportLogPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_ExportLogPanelList, LV_FLEX_FLOW_COLUMN);
    //lv_obj_set_style_pad_left(ui_ExportLogPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ExportLogPanelList, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_align(ui_ExportLogPanelList, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER);


    for (size_t index = 1; index < 3; index++)
    {
         ExportLogMenuArray[index] = CreateNormalListItem(ui_ExportLogPanelList, index, 9, 0, ui_event_ExportLogItems);
    }

    MenuItemCommonStyleInit(ExportLogMenuArray[1], ExportUdisk[get_cur_language_index()], false);
    MenuItemCommonStyleInit(ExportLogMenuArray[2], UploadLog[get_cur_language_index()], false);


    lv_obj_add_event_cb(ui_ButtonBackFAQ, ui_event_BackBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonBackOnlineManual, ui_event_BackBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonBackPrintHistory, ui_event_BackBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonBackErrorHistory, ui_event_BackBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonBackExportLog, ui_event_BackBtn, LV_EVENT_ALL, NULL);
}

void LoadCustomerServiceScreen(void)
{
    lv_disp_load_scr(ui_ScreenCustomerServicePage);
    // send_get_faq_qrcode_cmd();
}

void service_set_feedback_QRcode_png(char *QRcode_png_name)
{
    if ( ui_ImageFeedbackScreenService && QRcode_png_name )
    {
        char buff[258] = {0};
        buff[0] = PNG_DRV_LETTER;
        strncpy(buff + 1, QRcode_png_name, sizeof(buff) - 1);
        lv_img_set_src(ui_ImageFeedbackScreenService, buff);
        lv_img_set_zoom(ui_ImageFeedbackScreenService, 140);
    }
}

void service_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if (ui_LableInsertUdiskTip)
        lv_label_set_text(ui_LableInsertUdiskTip, InsertUdisk[language_index]);

    //lv_label_set_text(ui_LabelErrorDetail, ErrorBtnInfo[language_index]);
    //lv_label_set_text(ui_LabelErrorDetail, ErrorBtnInfo[language_index]
    lv_label_set_text(ServicesArray[1]->label_item_name, FAQ[language_index]);
    lv_label_set_text(ServicesArray[2]->label_item_name, OnlineManual[language_index]);
    lv_label_set_text(ServicesArray[3]->label_item_name, History[language_index]);
    lv_label_set_text(ServicesArray[4]->label_item_name, Errorhistory[language_index]);
    lv_label_set_text(ServicesArray[5]->label_item_name, ExportLogArray[language_index]);
    lv_label_set_text(ui_LabelCustomerService, FaqArray[language_index]);
    lv_label_set_text(ui_LableFAQTitle, FAQ[language_index]);
    lv_label_set_text(ui_LableFAQTip, FaqTips[language_index]);
    lv_obj_align_to(ui_ImageFAQQRCode, ui_LableFAQTip, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_label_set_text(ui_LableOnlineManualTitle, OnlineManual[language_index]);
    lv_label_set_text(ui_LableOnlineManualTip, WikiTips[language_index]);
    lv_obj_align_to(ui_ImageOnlineManualQRCode, ui_LableOnlineManualTip, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_label_set_text(ui_LablePrintHistory, History[language_index]);
    lv_label_set_text(ui_LableNoPrintHistoryRecord, NoRecords[language_index]);
    lv_label_set_text(ui_LableErrorHistory, Errorhistory[language_index]);
    lv_label_set_text(ui_LableErrorCodeTitle, ErrorCode[language_index]);
    lv_label_set_text(ui_LableOccurTimeTitle, ErrorTime[language_index]);
    lv_label_set_text(ui_LableOperateTitle, Action[language_index]);
    lv_label_set_text(ui_LableNoErrorHistoryRecord, NoRecords[language_index]);
    lv_label_set_text(ui_LableExportLog, ExportLogArray[language_index]);
    lv_label_set_text(ExportLogMenuArray[1]->label_item_name, ExportUdisk[language_index]);
    lv_label_set_text(ExportLogMenuArray[2]->label_item_name, UploadLog[language_index]);
}

void refresh_uploadlog_process(int state, int process, char * SN)
{
    if(!start_uploadlog)return;
    CrLogI("refresh the upload log ,state is %d.",process);
    switch (state)
    {
        case 0:
        {
            if(process > 0)
            {
                char tempbuff[256] = {0};
                snprintf(tempbuff, 256, "%s : %d%%", LogUploadingMsg[get_cur_language_index()], process);
                create_msgbox(tempbuff, NULL, 0, lv_scr_act());
            }
            else
            {
                create_msgbox(LogUploadingMsg[get_cur_language_index()], NULL, 0, lv_scr_act());
            }
            break;
        }
        case 1:create_msgbox(LogUploadSuccessMsg[get_cur_language_index()], NULL, 2000, lv_scr_act());start_uploadlog = false;break;
        case 2:create_msgbox(LogUploadFailedMsg[get_cur_language_index()], NULL, 2000, lv_scr_act());start_uploadlog = false;break;
    }
}

void get_fault_codelist(void)
{
    // 判断错误码文件是否存在，读取文件，获取json数据
    if (access(GetUserFaultCodeInfoPtah(), F_OK) == 0)
    {
        int codecount = 0;

        json_object *falutlist = json_object_from_file(GetUserFaultCodeInfoPtah());
        if (falutlist) {
            // 提取错误码列表
            json_object *listObj = json_object_object_get(falutlist, "list");
            codecount = json_object_array_length(listObj);
            CrLogI("fault code Size = %d", codecount);

            ErrorHistoryMenuPool = (Error_Info_t **)calloc(codecount, sizeof(Error_Info_t *));

            int j = 0;
            // 循环提取记录
            for (int i = 0; i < codecount; i++)
            {
                
                json_object *faultcode = json_object_array_get_idx(listObj, i);
                //错误时间
                time_t timesteamp = (time_t)json_object_get_int64(json_object_object_get(faultcode, "time"));
                struct tm *CurTime = localtime(&timesteamp);

                char tempbuff[1024] = {0};
                snprintf(tempbuff , sizeof(tempbuff) ,"%d/%02d/%02d %02d:%02d:%02d",
                                    CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
                                    CurTime->tm_hour, CurTime->tm_min, CurTime->tm_sec);
                
                //key值
                const char * keyvalue = json_object_get_string(json_object_object_get(faultcode, "code"));

                //错误等级
                int errorlevel = json_object_get_int(json_object_object_get(faultcode, "error"));

                //过滤部分不需要显示的错误码
                if(errorlevel < 800)
                {
                    ErrorHistoryMenuPool[j] = create_single_error(ui_ErrorHistoryPanelList, keyvalue, tempbuff, ErrorBtnInfo[get_cur_language_index()], errorlevel);
                    j++;
                }

            }

            json_object_put(falutlist);
        }
        else CrLogW("read json object fail\n");
    }
    else
    {
        CrLogW("json file not exist.");
    }
}

void AddFAQNavObjs(void)
{
    lv_group_add_obj(encoder_group, ui_ButtonBackFAQ);
    //lv_group_add_obj(encoder_group, ui_ButtonServicePage);
}

void AddOnlineManualNavObjs(void)
{
    lv_group_add_obj(encoder_group, ui_ButtonBackOnlineManual);
    //lv_group_add_obj(encoder_group, ui_ButtonServicePage);
}

void AddPrintHistoryNavObjs(void)
{
    lv_group_add_obj(encoder_group, ui_ButtonBackPrintHistory);
    for(int i = 0; i < HistoryRecordCnt; i++)
    {
        lv_group_add_obj(encoder_group, listPanel[i]->history_panel);
    }
}

void AddErrorHistoryNavObjs(void)
{
    lv_group_add_obj(encoder_group, ui_ButtonBackErrorHistory);
    // for(int i = 0; i < ErrorHistoryCnt; i++)
    // {
    //     lv_group_add_obj(encoder_group, ErrorMenuPool[i]->part_panel);
    // }
    int cnt = lv_obj_get_child_cnt(ui_ErrorHistoryPanelList);
    for (int i = 0; i < cnt; i++)
    {
        lv_group_add_obj(encoder_group, lv_obj_get_child(ui_ErrorHistoryPanelList, i));
        //lv_group_add_obj(encoder_group, ErrorHistoryMenuPool[i]->parent);
    }
}

void AddExportLogNavObjs(void)
{
    lv_group_add_obj(encoder_group, ui_ButtonBackExportLog);
    lv_group_add_obj(encoder_group, ExportLogMenuArray[1]->part_panel);
    lv_group_add_obj(encoder_group, ExportLogMenuArray[2]->part_panel);
}


void LoadServiceScreenAndObjs(bool IsEntered)
{
    ServiceScreen.stateValue = IsEntered;
   // ScreenStatusValue = IsEntered;
    if(ServiceScreen.stateValue == 0) //一级页面导航模式
    {
        LoadPage(ui_ScreenCustomerServicePage, 1);
        lv_obj_set_style_bg_img_src(ui_ButtonServicePage, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        ShowMenuSubPage(MAIN_MENU_PAGE);
        lv_group_focus_cycle(encoder_group, true);
    }
    else //二级页面导航模式
    {    
        LoadPage(ui_ScreenCustomerServicePage, 2);
        // if(lv_group_get_focused(encoder_group) == ui_ButtonServicePage)
        // {
        //     lv_obj_set_style_bg_img_src(ui_ButtonServicePage, &ui_img_pagereservefocus_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        // }
        // else
        // {
        //     lv_obj_set_style_bg_img_src(ui_ButtonServicePage, &ui_img_pagereserveselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        // }
        lv_obj_set_style_bg_img_src(ui_ButtonServicePage, &ui_img_pagereserveselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_group_focus_cycle(encoder_group, false);
    }
}

static void CustomerServicePageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *HomeNormalPage_node = find_page(ui_ScreenCustomerServicePage);
    HomeNormalPage_node->nav_level = index;

    switch (index)
    {
    case 1: //1级事件组  
        // page_manager.objFreezzFlag = false;
        Add3rdLevelObjsCb = NULL;
        lv_group_add_obj(encoder_group, ui_ButtonServicePage);
        lv_group_add_obj(encoder_group, ui_ButtonHomeScreenService);
        lv_group_add_obj(encoder_group, ui_ButtonAxisMoveScreenService);
        lv_group_add_obj(encoder_group, ui_ButtonFileManageScreenService);
        lv_group_add_obj(encoder_group, ui_ButtonSettingsScreenService);
        break;
    case 2: //2级事件组
        // page_manager.objFreezzFlag = false;
        Add3rdLevelObjsCb = NULL;
        lv_group_add_obj(encoder_group, ui_ButtonServicePage);
        for (size_t i = 1; i < 6; i++)
        {
            lv_group_add_obj(encoder_group, ServicesArray[i]->part_panel);
        }
        break;
    case 3:  //3级事件组
        if(Add3rdLevelObjsCb)
        {
            Add3rdLevelObjsCb();
        }
    default:
        break;
    }
 
}

void refresh_compressed_process(int process)
{
    CrLogI("refresh the compressed log ,process is %d.",process);
    if(!start_uploadlog && !start_selftest_upload && !startexprotlogtolocal)return;
    if(process > 0)
    {
        char tempbuff[256] = {0};
        snprintf(tempbuff, 256, "%s : %d%%", LogExporCompressing[get_cur_language_index()], process);
        create_msgbox(tempbuff, NULL, 0, lv_scr_act());
    }
    else
    {
        create_msgbox(LogExporCompressing[get_cur_language_index()], NULL, 0, lv_scr_act());
    }
}

void CustomerServicePageCloseSubPage(void)
{
    ShowMenuSubPage(MAIN_MENU_PAGE);
}