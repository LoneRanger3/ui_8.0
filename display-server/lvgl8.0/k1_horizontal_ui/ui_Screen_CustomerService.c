/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-22 17:40:08
 * @LastEditTime: 2023-03-17 20:39:08
 */
#include "ui_Screen_CustomerService.h"
#include "ui.h"
#include "ui_helpers.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_FileManage.h"
#include "ui_screen_AxisMove.h"
#include "ui_Screen_Settings.h"
#include "ui_screen_Adjustment.h"
#include "ui_screen_HomePrinting.h"
#include <stdio.h>
#include "mult_language.h"
#include <time.h>

/****************************************************/
//#define QRCODE_IMG_SIZE 160
#define QRCODE_IMG_SIZE 280

static lv_obj_t * ui_ScreenCustomerServicePage;
/******************screen left panel**********************/
static lv_obj_t * ui_PanelPageScreenService;
static lv_obj_t * ui_ButtonHomeScreenService;
static lv_obj_t * ui_ImageServicePage;
static lv_obj_t * ui_ButtonFileManageScreenService;
static lv_obj_t * ui_ButtonSettingsScreenService;
static lv_obj_t * ui_ButtonAxisMoveScreenService;

static lv_obj_t * ui_PanelServiceTop;
static lv_obj_t * ui_ServiceBtn;
static lv_obj_t * ui_LabelServiceTitle;
static lv_obj_t * ui_ServiceBtnImgLeft;
static lv_obj_t * ui_ServiceBtnImgRight;
static lv_obj_t * ui_ErrorlistBtn;
static lv_obj_t * ui_ErrorlistBtnlabel;
static lv_obj_t * ui_ErrorlistBtnImgLeft;
static lv_obj_t * ui_ErrorlistBtnImgRight;
static lv_obj_t * ui_UploadLogBtn;
static lv_obj_t * ui_UploadLogBtnlabel;
static lv_obj_t * ui_UploadLogBtnImgLeft;
static lv_obj_t * ui_UploadLogBtnImgRight;
static lv_obj_t * ui_ScreenServicePageCenterPanel;

static lv_obj_t * ui_PanelImageShowScreenService;
static lv_obj_t * ui_ImageFeedbackScreenService;

static lv_obj_t * ui_CustomServicePanel1;
static lv_obj_t * ui_CustomServiceImage1;
static lv_obj_t * ui_CustomServiceLabel1;
static lv_obj_t * ui_CustomServicePanel2;
static lv_obj_t * ui_CustomServiceImage2;
static lv_obj_t * ui_CustomServiceLabel2;
static lv_obj_t * ui_CustomServicePanel3;
static lv_obj_t * ui_CustomServiceImage3;
static lv_obj_t * ui_CustomServiceLabel3;
//错误历史
static lv_obj_t * ui_ErrorhistoryPanel;
static lv_obj_t * ui_Errorhistorytitle;
static lv_obj_t * ui_TitleError;
static lv_obj_t * ui_TitleTime;
static lv_obj_t * ui_TitleOption;
static lv_obj_t * ui_ErrorlistPanel;

static lv_obj_t * ui_UploadLogPanel;
static lv_obj_t * ui_UploadTips;
static lv_obj_t * ui_UploadBtn;
static lv_obj_t * ui_UploadBtnlabel;



/***************************************************/
static void ServicePageHomeBtnClicked(lv_event_t * e);
static void ServicePageFileManageBtnClicked(lv_event_t * e);
static void ServicePageSettingBtnClicked(lv_event_t * e);
static void ServicePageMoveBtnClicked(lv_event_t * e);
static void ui_event_ButtonHomeScreenService(lv_event_t * e);
static void ui_event_ButtonFileManageScreenService(lv_event_t * e);
static void ui_event_ButtonSettingsScreenService(lv_event_t * e);
static void ui_event_ButtonMoveScreenService(lv_event_t * e);
static void ui_event_CustomServicePanel1(lv_event_t * e);
static void ui_event_CustomServicePanel2(lv_event_t * e);
static void ui_event_CustomServicePanel3(lv_event_t * e);
static void ui_event_upload(lv_event_t * e);
static void ui_event_ErrorcodeOption(lv_event_t * e);

/**************************************************/
bool start_uploadlog = false;
/********axis Move Page***********/
void ui_event_ButtonHomeScreenService(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ServicePageHomeBtnClicked(e);
    }
}
void ui_event_ButtonFileManageScreenService(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ServicePageFileManageBtnClicked(e);
    }
}
void ui_event_ButtonSettingsScreenService(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ServicePageSettingBtnClicked(e);
    }
}
void ui_event_ButtonMoveScreenService(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ServicePageMoveBtnClicked(e);
    }
}

static void ui_event_CustomServicePanel1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_CustomerFaq, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

static void ui_event_CustomServicePanel2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_CustomerWiki, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

static void ui_event_CustomServicePanel3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
    }
}

static void ui_event_ServicePage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load customer service page");
        lv_obj_clear_flag(ui_PanelImageShowScreenService, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ErrorhistoryPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_UploadLogPanel, LV_OBJ_FLAG_HIDDEN);
        lv_event_send(ui_ServiceBtn, LV_EVENT_CLICKED, NULL);
        //查询用户绑定信息
        get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态
    }
}

static void ui_event_PanelChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(target == ui_ServiceBtn)
        {
            lv_obj_clear_flag(ui_PanelImageShowScreenService, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_ErrorhistoryPanel, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_UploadLogPanel, LV_OBJ_FLAG_HIDDEN);

            lv_obj_clear_flag(ui_ServiceBtnImgLeft, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_ServiceBtnImgRight, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_ErrorlistBtnImgLeft, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_ErrorlistBtnImgRight, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_UploadLogBtnImgLeft, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_UploadLogBtnImgRight, LV_OBJ_FLAG_HIDDEN);

            lv_obj_set_style_bg_opa(ui_ServiceBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(ui_ErrorlistBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(ui_UploadLogBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelServiceTitle, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_ErrorlistBtnlabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_UploadLogBtnlabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        if(target == ui_ErrorlistBtn)
        {
            lv_obj_add_flag(ui_PanelImageShowScreenService, LV_OBJ_FLAG_HIDDEN);  
            lv_obj_clear_flag(ui_ErrorhistoryPanel, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_UploadLogPanel, LV_OBJ_FLAG_HIDDEN);

            lv_obj_add_flag(ui_ServiceBtnImgLeft, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_ServiceBtnImgRight, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_ErrorlistBtnImgLeft, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_ErrorlistBtnImgRight, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_UploadLogBtnImgLeft, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_UploadLogBtnImgRight, LV_OBJ_FLAG_HIDDEN);

            lv_obj_set_style_bg_opa(ui_ServiceBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(ui_ErrorlistBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(ui_UploadLogBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelServiceTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_ErrorlistBtnlabel, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_UploadLogBtnlabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            //解析错误历史列表
            lv_obj_clean(ui_ErrorlistPanel);
            lv_obj_update_layout(ui_ErrorlistPanel);
            
            get_fault_codelist();

        }
        if(target == ui_UploadLogBtn)
        {
            lv_obj_add_flag(ui_PanelImageShowScreenService, LV_OBJ_FLAG_HIDDEN);  
            lv_obj_add_flag(ui_ErrorhistoryPanel, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_UploadLogPanel, LV_OBJ_FLAG_HIDDEN);

            lv_obj_add_flag(ui_ServiceBtnImgLeft, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_ServiceBtnImgRight, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_ErrorlistBtnImgLeft, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_ErrorlistBtnImgRight, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_UploadLogBtnImgLeft, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_UploadLogBtnImgRight, LV_OBJ_FLAG_HIDDEN);

            lv_obj_set_style_bg_opa(ui_ServiceBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(ui_ErrorlistBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(ui_UploadLogBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelServiceTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_ErrorlistBtnlabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_UploadLogBtnlabel, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            start_uploadlog = false;
        }
    }
}

static void ui_event_upload(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(!init_uiconfiginfo.AgreePrivacyPolicy)
        {
            int index = get_cur_language_index();
            create_PrivacyMessagebox(PrivacyPolicyTips[index], NotAgree[index], Agree[index], NULL, NULL);
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
            if ( wifi_state == '1'  || wire_net_state == '1')    //网络已连接
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

void faultcodemsg_close()
{
    send_buzzer(0x01);
    selftest_messagebox_close();
}

void upload_faultcodemsg()
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

typedef struct Error_Info
{
    lv_obj_t * parent;
    lv_obj_t * errorcode;
    lv_obj_t * Occurrencetime;
    lv_obj_t * Option;
    lv_obj_t * Errorlevel;
}Error_Info_t;

Error_Info_t create_single_error(lv_obj_t * parent, char * error, char * time, char * option, int errorlevel)
{
    Error_Info_t singleerror;
    uint8_t language_index = get_cur_language_index();
    singleerror.parent = lv_obj_create(parent);
    lv_obj_set_width(singleerror.parent, 650);
    lv_obj_set_height(singleerror.parent, 60);
    lv_obj_clear_flag(singleerror.parent, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(singleerror.parent, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(singleerror.parent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(singleerror.parent, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(singleerror.parent, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(singleerror.parent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(singleerror.parent, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(singleerror.parent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    singleerror.errorcode = lv_label_create(singleerror.parent);
    lv_obj_set_width(singleerror.errorcode, LV_SIZE_CONTENT);
    lv_obj_set_height(singleerror.errorcode, 30);
    lv_obj_align(singleerror.errorcode, LV_ALIGN_LEFT_MID, 20, 0);
    lv_label_set_text(singleerror.errorcode, error);
    lv_obj_set_style_text_color(singleerror.errorcode, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(singleerror.errorcode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(singleerror.errorcode, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(singleerror.errorcode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    singleerror.Occurrencetime = lv_label_create(singleerror.parent);
    lv_obj_set_width(singleerror.Occurrencetime, LV_SIZE_CONTENT);
    lv_obj_set_height(singleerror.Occurrencetime, 30);
    lv_obj_align(singleerror.Occurrencetime, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(singleerror.Occurrencetime, time);
    lv_obj_set_style_text_color(singleerror.Occurrencetime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(singleerror.Occurrencetime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(singleerror.Occurrencetime, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(singleerror.Occurrencetime, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(singleerror.Occurrencetime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    singleerror.Option = lv_label_create(singleerror.parent);
    lv_obj_set_width(singleerror.Option, LV_SIZE_CONTENT);
    lv_obj_set_height(singleerror.Option, 30);
    lv_obj_align(singleerror.Option, LV_ALIGN_RIGHT_MID, -10, 0);
    lv_label_set_text(singleerror.Option, option);
    lv_obj_set_style_text_color(singleerror.Option, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(singleerror.Option, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(singleerror.Option, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(singleerror.Option, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(singleerror.Option, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(singleerror.Option, LV_OBJ_FLAG_CLICKABLE);

    singleerror.Errorlevel = lv_label_create(singleerror.parent);
    lv_obj_set_width(singleerror.Errorlevel, LV_SIZE_CONTENT);
    lv_obj_set_height(singleerror.Errorlevel, 30);
    lv_obj_align(singleerror.Errorlevel, LV_ALIGN_RIGHT_MID, -10, 0);
    char tempbuff[256] = {0};
    snprintf(tempbuff, 256, "%d", errorlevel);
    lv_label_set_text(singleerror.Errorlevel, tempbuff);
    lv_obj_add_flag(singleerror.Errorlevel, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_event_cb(singleerror.Option, ui_event_ErrorcodeOption, LV_EVENT_CLICKED, singleerror.Errorlevel);
    return singleerror;
}

void ui_ScreenCustomerService_screen_init(void)
{
    uint8_t language_index = get_cur_language_index();
    ui_ScreenCustomerServicePage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenCustomerServicePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenCustomerServicePage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCustomerServicePage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_ScreenCustomerServicePage, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPageScreenService = lv_obj_create(ui_ScreenCustomerServicePage);
    lv_obj_set_width(ui_PanelPageScreenService, 80);
    lv_obj_set_height(ui_PanelPageScreenService, 480);
    lv_obj_clear_flag(ui_PanelPageScreenService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelPageScreenService, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelPageScreenService, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelPageScreenService, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonHomeScreenService = lv_btn_create(ui_PanelPageScreenService);
    lv_obj_set_width(ui_ButtonHomeScreenService, 80);
    lv_obj_set_height(ui_ButtonHomeScreenService, 96);
    lv_obj_set_x(ui_ButtonHomeScreenService, 0);
    lv_obj_set_y(ui_ButtonHomeScreenService, 0);
    lv_obj_add_flag(ui_ButtonHomeScreenService, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonHomeScreenService, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonHomeScreenService, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenService, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonHomeScreenService, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_ButtonHomeScreenService, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenService, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenService, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonAxisMoveScreenService = lv_btn_create(ui_PanelPageScreenService);
    lv_obj_set_width(ui_ButtonAxisMoveScreenService, 80);
    lv_obj_set_height(ui_ButtonAxisMoveScreenService, 96);
    lv_obj_align_to(ui_ButtonAxisMoveScreenService, ui_ButtonHomeScreenService, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_add_flag(ui_ButtonAxisMoveScreenService, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveScreenService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveScreenService, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonAxisMoveScreenService, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveScreenService, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveScreenService, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonAxisMoveScreenService, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonFileManageScreenService = lv_btn_create(ui_PanelPageScreenService);
    lv_obj_set_width(ui_ButtonFileManageScreenService, 80);
    lv_obj_set_height(ui_ButtonFileManageScreenService, 96);
    lv_obj_align_to(ui_ButtonFileManageScreenService, ui_ButtonAxisMoveScreenService, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_add_flag(ui_ButtonFileManageScreenService, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFileManageScreenService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonFileManageScreenService, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonFileManageScreenService, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenService, &ui_img_pagefilemanage_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonFileManageScreenService, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonFileManageScreenService, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonFileManageScreenService, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonFileManageScreenService, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonSettingsScreenService = lv_btn_create(ui_PanelPageScreenService);
    lv_obj_set_width(ui_ButtonSettingsScreenService, 80);
    lv_obj_set_height(ui_ButtonSettingsScreenService, 96);
    lv_obj_align_to(ui_ButtonSettingsScreenService, ui_ButtonFileManageScreenService, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_add_flag(ui_ButtonSettingsScreenService, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonSettingsScreenService, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonSettingsScreenService, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenService, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenService, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenService, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenService, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonSettingsScreenService, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageServicePage = lv_img_create(ui_PanelPageScreenService);
    lv_img_set_src(ui_ImageServicePage, &ui_img_pagereserveselected_png);
    lv_obj_set_width(ui_ImageServicePage, 80);
    lv_obj_set_height(ui_ImageServicePage, LV_SIZE_CONTENT);    /// 92
    lv_obj_align_to(ui_ImageServicePage, ui_ButtonSettingsScreenService, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_add_flag(ui_ImageServicePage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageServicePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    //顶部按钮栏
    ui_PanelServiceTop = lv_obj_create(ui_ScreenCustomerServicePage);
    lv_obj_set_width(ui_PanelServiceTop, 720);
    lv_obj_set_height(ui_PanelServiceTop, 50);
    lv_obj_set_x(ui_PanelServiceTop, 80);
    lv_obj_set_y(ui_PanelServiceTop, 0);
    lv_obj_clear_flag(ui_PanelServiceTop, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelServiceTop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelServiceTop, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelServiceTop, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelServiceTop, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelServiceTop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelServiceTop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_PanelServiceTop, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelServiceTop, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_END);
    lv_obj_set_style_pad_column(ui_PanelServiceTop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //客服按钮
    ui_ServiceBtnImgLeft = lv_img_create(ui_PanelServiceTop);
    char tempbuffa[256] = {0};
    snprintf(tempbuffa, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TilteLeftstyle.png");
    lv_img_set_src(ui_ServiceBtnImgLeft, tempbuffa);
    lv_obj_set_width(ui_ServiceBtnImgLeft, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ServiceBtnImgLeft, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ServiceBtnImgLeft, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ServiceBtnImgLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ServiceBtn = lv_btn_create(ui_PanelServiceTop);
    lv_obj_set_width(ui_ServiceBtn, 165);
    lv_obj_set_height(ui_ServiceBtn, 45);
    lv_obj_add_flag(ui_ServiceBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ServiceBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ServiceBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ServiceBtn, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ServiceBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ServiceBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ServiceBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ServiceBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ServiceBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelServiceTitle = lv_label_create(ui_ServiceBtn);
    lv_obj_set_width(ui_LabelServiceTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelServiceTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelServiceTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelServiceTitle, FaqArray[language_index]);
    lv_obj_set_style_text_color(ui_LabelServiceTitle, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelServiceTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelServiceTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_LabelServiceTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_LabelServiceTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_LabelServiceTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_LabelServiceTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ServiceBtnImgRight = lv_img_create(ui_PanelServiceTop);
    char tempbuffb[256] = {0};
    snprintf(tempbuffb, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TitleRightstyle.png");
    lv_img_set_src(ui_ServiceBtnImgRight, tempbuffb);
    lv_obj_set_width(ui_ServiceBtnImgRight, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ServiceBtnImgRight, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ServiceBtnImgRight, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ServiceBtnImgRight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ErrorlistBtnImgLeft = lv_img_create(ui_PanelServiceTop);
    memset(tempbuffa, 0, 256);
    snprintf(tempbuffa, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TilteLeftstyle.png");
    lv_img_set_src(ui_ErrorlistBtnImgLeft, tempbuffa);
    lv_obj_set_width(ui_ErrorlistBtnImgLeft, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ErrorlistBtnImgLeft, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ErrorlistBtnImgLeft, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ErrorlistBtnImgLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ErrorlistBtn = lv_btn_create(ui_PanelServiceTop);
    lv_obj_set_width(ui_ErrorlistBtn, 165);
    lv_obj_set_height(ui_ErrorlistBtn, 44);
    lv_obj_add_flag(ui_ErrorlistBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ErrorlistBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ErrorlistBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ErrorlistBtn, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ErrorlistBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ErrorlistBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ErrorlistBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ErrorlistBtnlabel = lv_label_create(ui_ErrorlistBtn);
    lv_obj_set_width(ui_ErrorlistBtnlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ErrorlistBtnlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ErrorlistBtnlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ErrorlistBtnlabel, Errorhistory[language_index]);
    lv_obj_set_style_text_color(ui_ErrorlistBtnlabel, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ErrorlistBtnlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ErrorlistBtnlabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ErrorlistBtnlabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ErrorlistBtnlabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ErrorlistBtnlabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ErrorlistBtnlabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ErrorlistBtnImgRight = lv_img_create(ui_PanelServiceTop);
    memset(tempbuffb, 0, 256);
    snprintf(tempbuffb, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TitleRightstyle.png");
    lv_img_set_src(ui_ErrorlistBtnImgRight, tempbuffb);
    lv_obj_set_width(ui_ErrorlistBtnImgRight, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ErrorlistBtnImgRight, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ErrorlistBtnImgRight, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ErrorlistBtnImgRight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_UploadLogBtnImgLeft = lv_img_create(ui_PanelServiceTop);
    memset(tempbuffa, 0, 256);
    snprintf(tempbuffa, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TilteLeftstyle.png");
    lv_img_set_src(ui_UploadLogBtnImgLeft, tempbuffa);
    lv_obj_set_width(ui_UploadLogBtnImgLeft, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_UploadLogBtnImgLeft, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_UploadLogBtnImgLeft, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_UploadLogBtnImgLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_UploadLogBtn = lv_btn_create(ui_PanelServiceTop);
    lv_obj_set_width(ui_UploadLogBtn, 165);
    lv_obj_set_height(ui_UploadLogBtn, 45);
    lv_obj_add_flag(ui_UploadLogBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_UploadLogBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_UploadLogBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_UploadLogBtn, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UploadLogBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_UploadLogBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_UploadLogBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UploadLogBtnlabel = lv_label_create(ui_UploadLogBtn);
    lv_obj_set_width(ui_UploadLogBtnlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_UploadLogBtnlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_UploadLogBtnlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_UploadLogBtnlabel, UploadLog[language_index]);
    lv_obj_set_style_text_color(ui_UploadLogBtnlabel, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_UploadLogBtnlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UploadLogBtnlabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_UploadLogBtnlabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_UploadLogBtnlabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_UploadLogBtnlabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_UploadLogBtnlabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UploadLogBtnImgRight = lv_img_create(ui_PanelServiceTop);
    memset(tempbuffb, 0, 256);
    snprintf(tempbuffb, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TitleRightstyle.png");
    lv_img_set_src(ui_UploadLogBtnImgRight, tempbuffb);
    lv_obj_set_width(ui_UploadLogBtnImgRight, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_UploadLogBtnImgRight, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_UploadLogBtnImgRight, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_UploadLogBtnImgRight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScreenServicePageCenterPanel = lv_obj_create(ui_ScreenCustomerServicePage);
    lv_obj_set_width(ui_ScreenServicePageCenterPanel, 720);
    lv_obj_set_height(ui_ScreenServicePageCenterPanel, 430);
    lv_obj_set_x(ui_ScreenServicePageCenterPanel, 80);
    lv_obj_set_y(ui_ScreenServicePageCenterPanel, 50);
    lv_obj_clear_flag(ui_ScreenServicePageCenterPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScreenServicePageCenterPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenServicePageCenterPanel, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenServicePageCenterPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ScreenServicePageCenterPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ScreenServicePageCenterPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenServicePageCenterPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenServicePageCenterPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenServicePageCenterPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelImageShowScreenService = lv_obj_create(ui_ScreenServicePageCenterPanel);
    lv_obj_set_width(ui_PanelImageShowScreenService, 696);
    lv_obj_set_height(ui_PanelImageShowScreenService, 406);
    lv_obj_set_x(ui_PanelImageShowScreenService, 12);
    lv_obj_set_y(ui_PanelImageShowScreenService, 12);
    lv_obj_clear_flag(ui_PanelImageShowScreenService, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelImageShowScreenService, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelImageShowScreenService, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelImageShowScreenService, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelImageShowScreenService, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelImageShowScreenService, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelImageShowScreenService, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelImageShowScreenService, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelImageShowScreenService, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomServicePanel1 = lv_obj_create(ui_PanelImageShowScreenService);
    lv_obj_set_width(ui_CustomServicePanel1, 685);
    lv_obj_set_height(ui_CustomServicePanel1, 39);
    lv_obj_set_x(ui_CustomServicePanel1, 0);
    lv_obj_set_y(ui_CustomServicePanel1, 32);
    lv_obj_clear_flag(ui_CustomServicePanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_CustomServicePanel1, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomServicePanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomServicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_CustomServicePanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CustomServicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CustomServicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CustomServicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CustomServicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomServiceImage1 = lv_img_create(ui_CustomServicePanel1);
    lv_img_set_src(ui_CustomServiceImage1, &ui_img_vector_24_png);
    lv_obj_set_width(ui_CustomServiceImage1, 14);
    lv_obj_set_height(ui_CustomServiceImage1, 28);
    lv_obj_set_x(ui_CustomServiceImage1, -20);
    lv_obj_set_y(ui_CustomServiceImage1, 0);
    lv_obj_set_align(ui_CustomServiceImage1, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_CustomServiceImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomServiceImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_CustomServiceLabel1 = lv_label_create(ui_CustomServicePanel1);
    lv_obj_set_width(ui_CustomServiceLabel1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CustomServiceLabel1, 24);
    lv_obj_set_x(ui_CustomServiceLabel1, 24);
    lv_obj_set_y(ui_CustomServiceLabel1, 0);
    lv_obj_set_align(ui_CustomServiceLabel1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_CustomServiceLabel1, FAQ[language_index]);
    lv_obj_set_style_text_color(ui_CustomServiceLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CustomServiceLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CustomServiceLabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_CustomServiceLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomServicePanel2 = lv_obj_create(ui_PanelImageShowScreenService);
    lv_obj_set_width(ui_CustomServicePanel2, 685);
    lv_obj_set_height(ui_CustomServicePanel2, 39);
    lv_obj_set_x(ui_CustomServicePanel2, 0);
    lv_obj_set_y(ui_CustomServicePanel2, 112);
    lv_obj_clear_flag(ui_CustomServicePanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_CustomServicePanel2, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomServicePanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomServicePanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_CustomServicePanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CustomServicePanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CustomServicePanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CustomServicePanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CustomServicePanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomServiceImage2 = lv_img_create(ui_CustomServicePanel2);
    lv_img_set_src(ui_CustomServiceImage2, &ui_img_vector_24_png);
    lv_obj_set_width(ui_CustomServiceImage2, 14);
    lv_obj_set_height(ui_CustomServiceImage2, 28);
    lv_obj_set_x(ui_CustomServiceImage2, -20);
    lv_obj_set_y(ui_CustomServiceImage2, 0);
    lv_obj_set_align(ui_CustomServiceImage2, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_CustomServiceImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomServiceImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_CustomServiceLabel2 = lv_label_create(ui_CustomServicePanel2);
    lv_obj_set_width(ui_CustomServiceLabel2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CustomServiceLabel2, 24);
    lv_obj_set_x(ui_CustomServiceLabel2, 24);
    lv_obj_set_y(ui_CustomServiceLabel2, 0);
    lv_obj_set_align(ui_CustomServiceLabel2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_CustomServiceLabel2, "在线说明书");
    lv_obj_set_style_text_color(ui_CustomServiceLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CustomServiceLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CustomServiceLabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_CustomServiceLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomServicePanel3 = lv_obj_create(ui_PanelImageShowScreenService);
    lv_obj_set_width(ui_CustomServicePanel3, 685);
    lv_obj_set_height(ui_CustomServicePanel3, 39);
    lv_obj_set_x(ui_CustomServicePanel3, 0);
    lv_obj_set_y(ui_CustomServicePanel3, 194);
    lv_obj_clear_flag(ui_CustomServicePanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_CustomServicePanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomServicePanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomServicePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_CustomServicePanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CustomServicePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CustomServicePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CustomServicePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CustomServicePanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomServiceImage3 = lv_img_create(ui_CustomServicePanel3);
    lv_img_set_src(ui_CustomServiceImage3, &ui_img_vector_24_png);
    lv_obj_set_width(ui_CustomServiceImage3, 14);
    lv_obj_set_height(ui_CustomServiceImage3, 28);
    lv_obj_set_x(ui_CustomServiceImage3, -20);
    lv_obj_set_y(ui_CustomServiceImage3, 0);
    lv_obj_set_align(ui_CustomServiceImage3, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_CustomServiceImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomServiceImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_CustomServiceLabel3 = lv_label_create(ui_CustomServicePanel3);
    lv_obj_set_width(ui_CustomServiceLabel3, 200);
    lv_obj_set_height(ui_CustomServiceLabel3, 24);
    lv_obj_set_x(ui_CustomServiceLabel3, 24);
    lv_obj_set_y(ui_CustomServiceLabel3, 0);
    lv_obj_set_align(ui_CustomServiceLabel3, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_CustomServiceLabel3, "上传日志");
    lv_obj_set_style_text_color(ui_CustomServiceLabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CustomServiceLabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CustomServiceLabel3, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_CustomServiceLabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_CustomServicePanel3, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_event_cb(ui_ButtonHomeScreenService, ui_event_ButtonHomeScreenService, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonFileManageScreenService, ui_event_ButtonFileManageScreenService, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsScreenService, ui_event_ButtonSettingsScreenService, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMoveScreenService, ui_event_ButtonMoveScreenService, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CustomServicePanel1, ui_event_CustomServicePanel1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CustomServicePanel2, ui_event_CustomServicePanel2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CustomServicePanel3, ui_event_CustomServicePanel3, LV_EVENT_ALL, NULL);

    //错误历史页面
    ui_ErrorhistoryPanel = lv_obj_create(ui_ScreenServicePageCenterPanel);
    lv_obj_set_width(ui_ErrorhistoryPanel, 696);
    lv_obj_set_height(ui_ErrorhistoryPanel, 406);
    lv_obj_set_x(ui_ErrorhistoryPanel, 12);
    lv_obj_set_y(ui_ErrorhistoryPanel, 12);
    lv_obj_clear_flag(ui_ErrorhistoryPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ErrorhistoryPanel, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ErrorhistoryPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ErrorhistoryPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ErrorhistoryPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ErrorhistoryPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Errorhistorytitle = lv_obj_create(ui_ErrorhistoryPanel);
    lv_obj_set_width(ui_Errorhistorytitle, 660);
    lv_obj_set_height(ui_Errorhistorytitle, 60);
    lv_obj_align(ui_Errorhistorytitle, LV_ALIGN_TOP_MID, 0, 2);
    lv_obj_clear_flag(ui_Errorhistorytitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Errorhistorytitle, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Errorhistorytitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Errorhistorytitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Errorhistorytitle, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Errorhistorytitle, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Errorhistorytitle, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_Errorhistorytitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TitleError = lv_label_create(ui_Errorhistorytitle);
    lv_obj_set_width(ui_TitleError, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TitleError, 30);
    lv_obj_align(ui_TitleError, LV_ALIGN_LEFT_MID, 10, 0);
    lv_label_set_text(ui_TitleError, ErrorCode[language_index]);
    lv_obj_set_style_text_color(ui_TitleError, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TitleError, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TitleError, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TitleError, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_TitleError, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TitleTime = lv_label_create(ui_Errorhistorytitle);
    lv_obj_set_width(ui_TitleTime, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TitleTime, 30);
    lv_obj_align(ui_TitleTime, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_TitleTime, ErrorTime[language_index]);
    lv_obj_set_style_text_color(ui_TitleTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TitleTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TitleTime, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_TitleTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TitleOption = lv_label_create(ui_Errorhistorytitle);
    lv_obj_set_width(ui_TitleOption, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_TitleOption, 30);
    lv_obj_align(ui_TitleOption, LV_ALIGN_RIGHT_MID, -15, 0);
    lv_label_set_text(ui_TitleOption, Action[language_index]);
    lv_obj_set_style_text_color(ui_TitleOption, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TitleOption, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TitleOption, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TitleOption, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_TitleOption, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ErrorlistPanel = lv_obj_create(ui_ErrorhistoryPanel);
    lv_obj_set_width(ui_ErrorlistPanel, 660);
    lv_obj_set_height(ui_ErrorlistPanel, 320);
    lv_obj_align(ui_ErrorlistPanel, LV_ALIGN_TOP_MID, 0, 66);
    lv_obj_set_style_bg_color(ui_ErrorlistPanel, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ErrorlistPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ErrorlistPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ErrorlistPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ErrorlistPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_ErrorlistPanel, LV_FLEX_FLOW_COLUMN);

    //上传日志页面
    ui_UploadLogPanel = lv_obj_create(ui_ScreenServicePageCenterPanel);
    lv_obj_set_width(ui_UploadLogPanel, 696);
    lv_obj_set_height(ui_UploadLogPanel, 406);
    lv_obj_set_x(ui_UploadLogPanel, 12);
    lv_obj_set_y(ui_UploadLogPanel, 12);
    lv_obj_clear_flag(ui_UploadLogPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_UploadLogPanel, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UploadLogPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_UploadLogPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_UploadLogPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_UploadLogPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UploadTips = lv_label_create(ui_UploadLogPanel);
    lv_obj_set_width(ui_UploadTips, 616);
    lv_obj_set_height(ui_UploadTips, LV_SIZE_CONTENT);
    lv_obj_align(ui_UploadTips, LV_ALIGN_TOP_MID, 0, 144);
    lv_label_set_text(ui_UploadTips, UploadTips[language_index]);
    lv_obj_set_style_text_color(ui_UploadTips, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_UploadTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UploadTips, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_UploadTips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_UploadTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_UploadBtn = lv_btn_create(ui_UploadLogPanel);
    lv_obj_set_width(ui_UploadBtn, 146);
    lv_obj_set_height(ui_UploadBtn, 60);
    lv_obj_align(ui_UploadBtn, LV_ALIGN_TOP_MID, 0, 208);
    lv_obj_add_flag(ui_UploadBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_UploadBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_UploadBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_UploadBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_UploadBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_UploadBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_UploadBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_UploadBtn, ui_event_upload, LV_EVENT_ALL, NULL);

    ui_UploadBtnlabel = lv_label_create(ui_UploadBtn);
    lv_obj_set_width(ui_UploadBtnlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_UploadBtnlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_UploadBtnlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_UploadBtnlabel, UploadLog[language_index]);
    lv_obj_set_style_text_color(ui_UploadBtnlabel, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_UploadBtnlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_UploadBtnlabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_UploadBtnlabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ScreenCustomerServicePage, ui_event_ServicePage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ServiceBtn, ui_event_PanelChange, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ErrorlistBtn, ui_event_PanelChange, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_UploadLogBtn, ui_event_PanelChange, LV_EVENT_ALL, NULL);

#ifdef BRAZIL_CUSTOM_ORDER
        //屏蔽上传日志
        lv_obj_add_flag(ui_UploadLogBtn, LV_OBJ_FLAG_HIDDEN);
#else

#endif
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


void ServicePageHomeBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( home_printing_is_printing_finished() )
        LoadHomeNormalScreen();
    else
        LoadHomePrintingScreen();
}

void ServicePageFileManageBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadFileManageScreen();
}

void ServicePageSettingBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadSettingsScreen();
}

void ServicePageMoveBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( home_printing_is_printing_finished() )
        LoadAxisMoveScreen();
    else
        LoadAxisMoveScreen();
}

void service_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_LabelServiceTitle )
    {
        lv_label_set_text(ui_LabelServiceTitle, FaqArray[language_index]);
        redefine_label_size(ui_LabelServiceTitle, lv_font25.font, 0, 0, 240, 0);
        
        lv_obj_update_layout(ui_ServiceBtn);
        redefine_widgets_size(ui_ServiceBtn, ui_LabelServiceTitle, 5, 0, 165, 45);
    }
    
    if ( ui_CustomServiceLabel3 )
        lv_label_set_text(ui_CustomServiceLabel3, UploadLog[language_index]);

    if ( ui_CustomServiceLabel1 )
        lv_label_set_text(ui_CustomServiceLabel1, FAQ[language_index]);
    if ( ui_CustomServiceLabel2 )
        lv_label_set_text(ui_CustomServiceLabel2, OnlineManual[language_index]);

    if ( ui_UploadLogBtnlabel )
    {
        lv_label_set_text(ui_UploadLogBtnlabel, UploadLog[language_index]);
        redefine_label_size(ui_UploadLogBtnlabel, lv_font25.font, 0, 0, 300, 0);
        
        lv_obj_update_layout(ui_UploadLogBtn);
        redefine_widgets_size(ui_UploadLogBtn, ui_UploadLogBtnlabel, 5, 0, 165, 45);
    }
    if( ui_ErrorlistBtnlabel)
    {
        lv_label_set_text(ui_ErrorlistBtnlabel, Errorhistory[language_index]);
        redefine_label_size(ui_ErrorlistBtnlabel, lv_font25.font, 0, 0, 300, 0);
        
        lv_obj_update_layout(ui_ErrorlistBtn);
        redefine_widgets_size(ui_ErrorlistBtn, ui_ErrorlistBtnlabel, 5, 0, 165, 45);
    }
    if( ui_UploadTips)
        lv_label_set_text(ui_UploadTips, UploadTips[language_index]);
    if( ui_UploadBtnlabel)
    {
        lv_label_set_text(ui_UploadBtnlabel, UploadLog[language_index]);
        redefine_label_size(ui_UploadBtnlabel, lv_font25.font, 0, 0, 300, 0);
        
        lv_obj_update_layout(ui_UploadBtn);
        redefine_widgets_size(ui_UploadBtn, ui_UploadBtnlabel, 10, 0, 146, 60);
    }
    if( ui_TitleError )
    {
        if(language_index == 3 || language_index == 7)
        {
            lv_obj_set_style_text_letter_space(ui_TitleError, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(ui_TitleError, ErrorCode[language_index]);
        }
        else
        {
            lv_obj_set_style_text_letter_space(ui_TitleError, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(ui_TitleError, ErrorCode[language_index]);
        }
    }

    if( ui_TitleTime )
    {
        if(language_index == 3 || language_index == 7)
        {
            lv_obj_set_style_text_letter_space(ui_TitleTime, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(ui_TitleTime, ErrorTime[language_index]);
        }
        else
        {
            lv_obj_set_style_text_letter_space(ui_TitleTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(ui_TitleTime, ErrorTime[language_index]);
        }
    }

    if( ui_TitleOption )
    {
        if(language_index == 3 || language_index == 7)
        {
            lv_obj_set_style_text_letter_space(ui_TitleOption, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(ui_TitleOption, Action[language_index]);
        }
        else
        {
            lv_obj_set_style_text_letter_space(ui_TitleOption, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(ui_TitleOption, Action[language_index]);
        }
    }
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

void get_fault_codelist()
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
                    create_single_error(ui_ErrorlistPanel, keyvalue, tempbuff, ErrorBtnInfo[get_cur_language_index()], errorlevel);
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
