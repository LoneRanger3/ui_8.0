/*
 * @Description: 
 * @Author: sunhui
 * @Date: 2023-08-11 22:53:01
 * @LastEditTime: 2023-10-23 02:47:08
 */

#include "page_switch.h"
#include "src/core/lv_group.h"
#include "src/core/lv_obj_pos.h"
#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "mult_language.h"
#include <stdio.h>
#include <sys/time.h>

lv_obj_t * ui_AboutDevice;
lv_obj_t * ui_AboutDevicePanel1;
lv_obj_t * ui_AboutDeviceImage1;
lv_obj_t * ui_AboutDeviceImage2;
lv_obj_t * ui_AboutDeviceImage3;
lv_obj_t * ui_AboutDeviceImage4;
lv_obj_t * ui_AboutDeviceImage5;

static lv_obj_t * ui_AboutDeviceMainPanel;
static lv_obj_t * ui_AboutDeviceTitle;
static lv_obj_t * ui_AboutDevicePanelLine;
static lv_obj_t * ui_AboutDeviceBackBtn;
// static lv_obj_t * ui_AboutDeviceBackBtnlabel;
static lv_obj_t * ui_DeviceNameLabel;
static lv_obj_t * ui_DeviceNameValueLabel;
// static lv_obj_t * ui_DeviceModeLable;
// static lv_obj_t * ui_DeviceModeValueLable;
static lv_obj_t * ui_FirmwareVersionLabel;
static lv_obj_t * ui_FirmVersionValueLabel;
static lv_obj_t * ui_DeviceMacAddrLabel;
static lv_obj_t * ui_DeviceMacAddrValueLabel; 
static lv_obj_t * ui_SerialNumberLabel;
static lv_obj_t * ui_SerialNumberValueLabel;
static lv_obj_t * ui_CumulativeTimeLabel;
static lv_obj_t * ui_CumulativeTimeValueLabel;
static lv_obj_t * ui_StorageSpaceLabel;
static lv_obj_t * ui_StorageSpaceValueLabel;


lv_obj_t * ui_AboutDevicePanel4;
lv_obj_t * ui_AboutDeviceImage;
lv_obj_t * ui_AboutDeviceLabel2;
lv_obj_t * ui_AboutDeviceLable3;


lv_obj_t * ui_AboutDeviceLable16;
lv_obj_t * ui_FactorymodePanel;
lv_obj_t * ui_FactorymodeServerSetDropdown;
lv_obj_t * ui_FactorymodeConfirmBtn;
lv_obj_t * ui_FactorymodeConfirmBtnLabel;
lv_obj_t * ui_FactorymodeBareBoardTestBtn;
lv_obj_t * ui_FactorymodeBareBoardTestBtnLabal;
lv_obj_t * ui_FactorymodeMachineTestBtn;
lv_obj_t * ui_FactorymodeMachineTestBtnLabel;
lv_obj_t * ui_FactorymodeKeyboard;
lv_obj_t * ui_FactorymodeKeyboardTextArea;
lv_obj_t * ui_FactorymodeLevelTable;
lv_obj_t * ui_FactorymodeGetLevelDataBtn;
lv_obj_t * ui_FactorymodeGetLevelDataBtnLabel;
lv_obj_t * ui_FactorymodeSaveAIdataBtn;
lv_obj_t * ui_FactorymodeSaveAIdataBtnLabel;
lv_obj_t * ui_AboutDeviceInfoPanel; //设备详细信息右侧面板
lv_obj_t * ui_AboutDeviceButton7;
lv_obj_t * ui_AboutDeviceButton8;
lv_obj_t * ui_AboutDeviceButton9;
lv_obj_t * ui_AboutDeviceBackBtn0;

static bool FactorymodeFlag = false;
static lv_obj_t * ui_AboutDeviceWaittimer = NULL;

#define PASSWORD "cxsw$888"
void ui_event_AboutDeviceBackBtn(lv_event_t * e);
void ui_event_AboutDeviceImage1(lv_event_t * e);
void ui_event_AboutDeviceImage2(lv_event_t * e);
void ui_event_AboutDeviceImage3(lv_event_t * e);
void ui_event_AboutDeviceImage4(lv_event_t * e);
void ui_event_AboutDeviceImage5(lv_event_t * e);
void ui_event_AboutDevice(lv_event_t * e);
void ui_event_AboutDeviceLable13(lv_event_t * e);
void ui_event_AboutDeviceDropdown1(lv_event_t * e);
void ui_event_FactorymodeConfirmBtn(lv_event_t * e);
void ui_event_FactorymodeBareBoardTestBtn(lv_event_t * e);
void ui_event_AboutDeviceButton4(lv_event_t * e);
void ui_event_AboutDeviceButton5(lv_event_t * e);
void ui_event_AboutDeviceButton6(lv_event_t * e);
void ui_event_AboutDeviceTextArea1(lv_event_t * e);
void ui_event_AboutDeviceKeyboard1(lv_event_t * e);
void ui_event_AboutDeviceFactorymode(lv_event_t * e);
static void AboutDevicePageChangeObjs(uint8_t index);
static void LoadAboutDevicePage(void);
static void FactoryModePageChangeObjs(void);
static bool VerifyPasswdFlag = false;

void ui_AboutDevice_screen_init(void)
{
    ui_AboutDevice = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_AboutDevice, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_AboutDevice, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_AboutDevice, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDevice, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_AboutDevice, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_AboutDevice, AboutDevicePageChangeObjs, LoadAboutDevicePage);

    uint8_t language_index = get_cur_language_index();
    ui_AboutDevicePanel1 = lv_obj_create(ui_AboutDevice);
    lv_obj_set_width(ui_AboutDevicePanel1, 68);
    lv_obj_set_height(ui_AboutDevicePanel1, 360);
    lv_obj_set_pos(ui_AboutDevicePanel1, 0, 60);
    lv_obj_clear_flag(ui_AboutDevicePanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDevicePanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDevicePanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AboutDevicePanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_AboutDevicePanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AboutDevicePanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceImage1 = lv_img_create(ui_AboutDevicePanel1);
    lv_img_set_src(ui_AboutDeviceImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_AboutDeviceImage1, 68);
    lv_obj_set_height(ui_AboutDeviceImage1, 72);
    lv_obj_add_flag(ui_AboutDeviceImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceImage2 = lv_img_create(ui_AboutDevicePanel1);
    lv_img_set_src(ui_AboutDeviceImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_AboutDeviceImage2, 68);
    lv_obj_set_height(ui_AboutDeviceImage2, 72);
    lv_obj_set_x(ui_AboutDeviceImage2, 0);
    lv_obj_set_y(ui_AboutDeviceImage2, 72);
    lv_obj_add_flag(ui_AboutDeviceImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceImage3 = lv_img_create(ui_AboutDevicePanel1);
    lv_img_set_src(ui_AboutDeviceImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_AboutDeviceImage3, 68);
    lv_obj_set_height(ui_AboutDeviceImage3, 72);
    lv_obj_set_x(ui_AboutDeviceImage3, 0);
    lv_obj_set_y(ui_AboutDeviceImage3, 144);
    lv_obj_add_flag(ui_AboutDeviceImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceImage4 = lv_img_create(ui_AboutDevicePanel1);
    lv_img_set_src(ui_AboutDeviceImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_AboutDeviceImage4, 68);
    lv_obj_set_height(ui_AboutDeviceImage4, 72);
    lv_obj_set_x(ui_AboutDeviceImage4, 0);
    lv_obj_set_y(ui_AboutDeviceImage4, 216);
    lv_obj_add_flag(ui_AboutDeviceImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceImage5 = lv_img_create(ui_AboutDevicePanel1);
    lv_img_set_src(ui_AboutDeviceImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_AboutDeviceImage5, 68);
    lv_obj_set_height(ui_AboutDeviceImage5, 72);
    lv_obj_set_x(ui_AboutDeviceImage5, 0);
    lv_obj_set_y(ui_AboutDeviceImage5, 288);
    lv_obj_add_flag(ui_AboutDeviceImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage5, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //关于本机子页主面板 
    ui_AboutDeviceMainPanel = lv_obj_create(ui_AboutDevice);
    lv_obj_set_pos(ui_AboutDeviceMainPanel, 76, 68);
    lv_obj_set_size(ui_AboutDeviceMainPanel, 556, 344);
    lv_obj_set_align(ui_AboutDeviceMainPanel, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_AboutDeviceMainPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceMainPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDeviceMainPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceMainPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceMainPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_AboutDeviceMainPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //关于本机标题
    ui_AboutDeviceTitle = lv_label_create(ui_AboutDeviceMainPanel);
    lv_obj_set_size(ui_AboutDeviceTitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_AboutDeviceTitle, 16, 0);
    lv_label_set_text(ui_AboutDeviceTitle, AboutDevice[language_index]);
    lv_obj_set_style_text_align(ui_AboutDeviceTitle, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_AboutDeviceTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceTitle, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_AboutDevicePanelLine = lv_obj_create(ui_AboutDeviceMainPanel);
    lv_obj_set_size(ui_AboutDevicePanelLine, 543, 1);
    lv_obj_set_pos(ui_AboutDevicePanelLine, 7, 49);
    lv_obj_clear_flag(ui_AboutDevicePanelLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_AboutDevicePanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDevicePanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AboutDevicePanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_AboutDevicePanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDevicePanelLine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //返回按钮
    ui_AboutDeviceBackBtn = lv_btn_create(ui_AboutDeviceMainPanel);
    lv_obj_set_size(ui_AboutDeviceBackBtn, 68, 38);
    lv_obj_set_pos(ui_AboutDeviceBackBtn, 474, 6);
    lv_obj_add_flag(ui_AboutDeviceBackBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceBackBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDeviceBackBtn, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceBackBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AboutDeviceBackBtn, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_AboutDeviceBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_AboutDeviceBackBtn, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AboutDeviceBackBtn, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_AboutDeviceBackBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_AboutDeviceBackBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_AboutDeviceBackBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_AboutDeviceBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_AboutDeviceBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    // ui_AboutDeviceBackBtnlabel = lv_label_create(ui_AboutDeviceBackBtn);
    // lv_obj_set_width(ui_AboutDeviceBackBtnlabel, lv_pct(100));
    // lv_obj_set_height(ui_AboutDeviceBackBtnlabel, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_align(ui_AboutDeviceBackBtnlabel, LV_ALIGN_CENTER);
    // lv_label_set_long_mode(ui_AboutDeviceBackBtnlabel, LV_LABEL_LONG_WRAP);
    // lv_label_set_text(ui_AboutDeviceBackBtnlabel, Back[language_index]);
    // lv_obj_set_style_text_align(ui_AboutDeviceBackBtnlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_AboutDeviceBackBtnlabel, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //关于本机图像面板
    ui_AboutDevicePanel4 = lv_obj_create(ui_AboutDeviceMainPanel);
    lv_obj_set_size(ui_AboutDevicePanel4, 186, 253);//160, 253
    lv_obj_set_pos(ui_AboutDevicePanel4, 12, 73);
    lv_obj_clear_flag(ui_AboutDevicePanel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDevicePanel4, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDevicePanel4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDevicePanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDevicePanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_AboutDevicePanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_AboutDevicePanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_AboutDevicePanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_AboutDevicePanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //依次点击图像的左上角、右上角、左下角、右下角、中间图片位置会显示设备测试页
    ui_AboutDeviceButton7 = lv_btn_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceButton7, 116);
    lv_obj_set_height(ui_AboutDeviceButton7, 60);
    lv_obj_align(ui_AboutDeviceButton7, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton7, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceButton8 = lv_btn_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceButton8, 116);
    lv_obj_set_height(ui_AboutDeviceButton8, 60);
    lv_obj_align(ui_AboutDeviceButton8, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton8, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceButton9 = lv_btn_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceButton9, 116);
    lv_obj_set_height(ui_AboutDeviceButton9, 60);
    lv_obj_align(ui_AboutDeviceButton9, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    lv_obj_set_style_bg_color(ui_AboutDeviceButton9, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceButton9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceButton9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceBackBtn0 = lv_btn_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceBackBtn0, 116);
    lv_obj_set_height(ui_AboutDeviceBackBtn0, 60);
    lv_obj_align(ui_AboutDeviceBackBtn0, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_obj_set_style_bg_color(ui_AboutDeviceBackBtn0, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceBackBtn0, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_AboutDeviceBackBtn0, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //机器图片
    ui_AboutDeviceImage = lv_img_create(ui_AboutDevicePanel4);
    lv_img_set_src(ui_AboutDeviceImage, &ui_img_machine_png);
    lv_obj_set_width(ui_AboutDeviceImage, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_AboutDeviceImage, LV_SIZE_CONTENT); 
    lv_obj_set_x(ui_AboutDeviceImage, 0);
    lv_obj_set_y(ui_AboutDeviceImage, 24);
    lv_obj_set_align(ui_AboutDeviceImage, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_AboutDeviceImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_AboutDeviceImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_AboutDeviceImage, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    lv_obj_add_event_cb(ui_AboutDeviceButton7, ui_event_AboutDeviceFactorymode, LV_EVENT_CLICKED, "1");
    lv_obj_add_event_cb(ui_AboutDeviceButton8, ui_event_AboutDeviceFactorymode, LV_EVENT_CLICKED, "2");
    lv_obj_add_event_cb(ui_AboutDeviceButton9, ui_event_AboutDeviceFactorymode, LV_EVENT_CLICKED, "3");
    lv_obj_add_event_cb(ui_AboutDeviceBackBtn0, ui_event_AboutDeviceFactorymode, LV_EVENT_CLICKED, "4");
    lv_obj_add_event_cb(ui_AboutDeviceImage, ui_event_AboutDeviceFactorymode, LV_EVENT_CLICKED, "5");

    //机型显示label
    ui_AboutDeviceLabel2 = lv_label_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceLabel2, 300);
    lv_obj_set_height(ui_AboutDeviceLabel2, 30);
    lv_obj_set_x(ui_AboutDeviceLabel2, 0);
    lv_obj_set_y(ui_AboutDeviceLabel2, 190);
    lv_obj_set_align(ui_AboutDeviceLabel2, LV_ALIGN_TOP_MID);
    lv_label_set_long_mode(ui_AboutDeviceLabel2, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_AboutDeviceLabel2, "CR K1");
    lv_obj_set_style_text_color(ui_AboutDeviceLabel2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLabel2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLabel2, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AboutDeviceLable3 = lv_label_create(ui_AboutDevicePanel4);
    lv_obj_set_width(ui_AboutDeviceLable3, 300);
    lv_obj_set_height(ui_AboutDeviceLable3, 30);
    lv_obj_set_x(ui_AboutDeviceLable3, 0);
    lv_obj_set_y(ui_AboutDeviceLable3, 216);
    lv_obj_set_align(ui_AboutDeviceLable3, LV_ALIGN_TOP_MID);
    lv_label_set_long_mode(ui_AboutDeviceLable3, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_AboutDeviceLable3, "220x220x250mm");
    lv_obj_set_style_text_color(ui_AboutDeviceLable3, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AboutDeviceLable3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AboutDeviceLable3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AboutDeviceLable3, lv_font18.font, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    //关于本机详细右侧面板
    ui_AboutDeviceInfoPanel = lv_obj_create(ui_AboutDeviceMainPanel);
    lv_obj_set_width(ui_AboutDeviceInfoPanel, 340);
    lv_obj_set_height(ui_AboutDeviceInfoPanel, 252);
    // lv_obj_set_x(ui_AboutDeviceInfoPanel, 200);//188
    // lv_obj_set_y(ui_AboutDeviceInfoPanel, 73);
    lv_obj_align_to(ui_AboutDeviceInfoPanel, ui_AboutDevicePanel4, LV_ALIGN_OUT_RIGHT_MID, 12, 0);
    lv_obj_clear_flag(ui_AboutDeviceInfoPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AboutDeviceInfoPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AboutDeviceInfoPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AboutDeviceInfoPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AboutDeviceInfoPanel, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AboutDeviceInfoPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_AboutDeviceInfoPanel, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_AboutDeviceInfoPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_set_style_border_side(ui_AboutDeviceInfoPanel, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_set_style_border_side(ui_AboutDeviceInfoPanel, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    //设备名称
    ui_DeviceNameLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_DeviceNameLabel, 230);
    lv_obj_set_height(ui_DeviceNameLabel, 28);
    lv_obj_align(ui_DeviceNameLabel, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_label_set_long_mode(ui_DeviceNameLabel, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_DeviceNameLabel, DeviceNameArray[language_index]);
    lv_obj_set_style_text_color(ui_DeviceNameLabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceNameLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DeviceNameLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceNameLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    // //机器型号
    // ui_DeviceModeLable = lv_label_create(ui_AboutDeviceInfoPanel);
    // lv_obj_set_width(ui_DeviceModeLable, 230);
    // lv_obj_set_height(ui_DeviceModeLable, 56);
    // lv_obj_align_to(ui_DeviceModeLable, ui_DeviceNameLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 24);
    // lv_label_set_long_mode(ui_DeviceModeLable, LV_LABEL_LONG_DOT);
    // lv_label_set_text(ui_DeviceModeLable, DeviceModelArray[language_index]);
    // lv_obj_set_style_text_color(ui_DeviceModeLable, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_DeviceModeLable, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_DeviceModeLable, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_DeviceModeLable, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //固件版本
    ui_FirmwareVersionLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_FirmwareVersionLabel, 200);
    lv_obj_set_height(ui_FirmwareVersionLabel, 28);
    lv_obj_align_to(ui_FirmwareVersionLabel, ui_DeviceNameLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 17);
    lv_label_set_long_mode(ui_FirmwareVersionLabel, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_FirmwareVersionLabel, Version[language_index]);
    lv_obj_set_style_text_color(ui_FirmwareVersionLabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FirmwareVersionLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_FirmwareVersionLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FirmwareVersionLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //设备mac地址
    ui_DeviceMacAddrLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_DeviceMacAddrLabel, 120);
    lv_obj_set_height(ui_DeviceMacAddrLabel, 28);
    lv_obj_align_to(ui_DeviceMacAddrLabel, ui_FirmwareVersionLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 17);
    lv_label_set_long_mode(ui_DeviceMacAddrLabel, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_DeviceMacAddrLabel, MacAddrArray[language_index]);
    lv_obj_set_style_text_color(ui_DeviceMacAddrLabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceMacAddrLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DeviceMacAddrLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceMacAddrLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //SN号
    ui_SerialNumberLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_SerialNumberLabel, 100);
    lv_obj_set_height(ui_SerialNumberLabel, 28);
    lv_obj_align_to(ui_SerialNumberLabel, ui_DeviceMacAddrLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 17);
    lv_label_set_long_mode(ui_SerialNumberLabel, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_SerialNumberLabel, SerialNumber[language_index]);
    lv_obj_set_style_text_color(ui_SerialNumberLabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SerialNumberLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SerialNumberLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SerialNumberLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //累计打印时间
    ui_CumulativeTimeLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_CumulativeTimeLabel, 200);
    lv_obj_set_height(ui_CumulativeTimeLabel, 48);
    lv_obj_align_to(ui_CumulativeTimeLabel, ui_SerialNumberLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 17);
    lv_label_set_long_mode(ui_CumulativeTimeLabel, LV_LABEL_LONG_WRAP); //LV_LABEL_LONG_WRAP
    lv_obj_set_style_text_line_space(ui_CumulativeTimeLabel, -5, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
    lv_label_set_text(ui_CumulativeTimeLabel, CumulativeTime[language_index]);
    lv_obj_set_style_text_color(ui_CumulativeTimeLabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CumulativeTimeLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_CumulativeTimeLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CumulativeTimeLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
      
    //存储空间
    ui_StorageSpaceLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_StorageSpaceLabel, 300);
    lv_obj_set_height(ui_StorageSpaceLabel, 28);
    lv_obj_align_to(ui_StorageSpaceLabel, ui_CumulativeTimeLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 17);
    lv_label_set_long_mode(ui_StorageSpaceLabel, LV_LABEL_LONG_WRAP);//LV_LABEL_LONG_WRAP
    lv_obj_set_style_text_line_space(ui_StorageSpaceLabel, -5, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
    lv_label_set_text(ui_StorageSpaceLabel, StorageArray[language_index]);
    lv_obj_set_style_text_color(ui_StorageSpaceLabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StorageSpaceLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_StorageSpaceLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_StorageSpaceLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceNameValueLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_DeviceNameValueLabel, 150);
    lv_obj_set_height(ui_DeviceNameValueLabel, 28);
    lv_obj_align(ui_DeviceNameValueLabel, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_label_set_long_mode(ui_DeviceNameValueLabel, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_DeviceNameValueLabel, "");
    lv_obj_set_style_text_color(ui_DeviceNameValueLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceNameValueLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DeviceNameValueLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceNameValueLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_DeviceModeValueLable = lv_label_create(ui_AboutDeviceInfoPanel);
//     lv_obj_set_width(ui_DeviceModeValueLable, 150);
//     lv_obj_set_height(ui_DeviceModeValueLable, 28);
//     lv_obj_set_style_base_dir(ui_DeviceModeValueLable, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
//    // lv_obj_align(ui_DeviceModeValueLable, LV_ALIGN_TOP_RIGHT, 0, 40);
//     lv_obj_align_to(ui_DeviceModeValueLable, ui_DeviceNameValueLabel, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 24);
//     lv_label_set_long_mode(ui_DeviceModeValueLable, LV_LABEL_LONG_WRAP);
//     lv_label_set_text(ui_DeviceModeValueLable, "");
//     lv_obj_set_style_text_color(ui_DeviceModeValueLable, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_DeviceModeValueLable, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_DeviceModeValueLable, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_DeviceModeValueLable, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FirmVersionValueLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_FirmVersionValueLabel, 160);
    lv_obj_set_height(ui_FirmVersionValueLabel, 28);
    lv_obj_set_style_base_dir(ui_FirmVersionValueLabel, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_FirmVersionValueLabel, LV_ALIGN_TOP_RIGHT, 0, 45);
    lv_label_set_long_mode(ui_FirmVersionValueLabel, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_FirmVersionValueLabel, "");
    lv_obj_set_style_text_color(ui_FirmVersionValueLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FirmVersionValueLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_FirmVersionValueLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FirmVersionValueLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceMacAddrValueLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_DeviceMacAddrValueLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_DeviceMacAddrValueLabel, 28);
    lv_obj_set_style_base_dir(ui_DeviceMacAddrValueLabel, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_DeviceMacAddrValueLabel, LV_ALIGN_TOP_RIGHT, 0, 90);
    lv_label_set_long_mode(ui_DeviceMacAddrValueLabel, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_DeviceMacAddrValueLabel, "");
    lv_obj_set_style_text_color(ui_DeviceMacAddrValueLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceMacAddrValueLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DeviceMacAddrValueLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceMacAddrValueLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_DeviceMacAddrValueLabel, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_ext_click_area(ui_DeviceMacAddrValueLabel, 30);
    
    ui_SerialNumberValueLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_SerialNumberValueLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SerialNumberValueLabel, 28);
    lv_obj_set_style_base_dir(ui_SerialNumberValueLabel, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_SerialNumberValueLabel, LV_ALIGN_TOP_RIGHT, 0, 135);
    lv_label_set_long_mode(ui_SerialNumberValueLabel, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_SerialNumberValueLabel, "");
    lv_obj_set_style_text_color(ui_SerialNumberValueLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SerialNumberValueLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SerialNumberValueLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SerialNumberValueLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_SerialNumberValueLabel, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_ext_click_area(ui_SerialNumberValueLabel, 30);

    ui_CumulativeTimeValueLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_CumulativeTimeValueLabel, 300);
    lv_obj_set_height(ui_CumulativeTimeValueLabel, 28);
    lv_obj_set_style_base_dir(ui_CumulativeTimeValueLabel, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_CumulativeTimeValueLabel, LV_ALIGN_TOP_RIGHT, 0, 180);
    lv_label_set_long_mode(ui_CumulativeTimeValueLabel, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_CumulativeTimeValueLabel, "");
    lv_obj_set_style_text_color(ui_CumulativeTimeValueLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CumulativeTimeValueLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_CumulativeTimeValueLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CumulativeTimeValueLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StorageSpaceValueLabel = lv_label_create(ui_AboutDeviceInfoPanel);
    lv_obj_set_width(ui_StorageSpaceValueLabel, 300);
    lv_obj_set_height(ui_StorageSpaceValueLabel, 28);
    lv_obj_set_style_base_dir(ui_StorageSpaceValueLabel, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_StorageSpaceValueLabel, LV_ALIGN_TOP_RIGHT, 0, 225);
    lv_label_set_long_mode(ui_StorageSpaceValueLabel, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_StorageSpaceValueLabel, "");
    lv_obj_set_style_text_color(ui_StorageSpaceValueLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StorageSpaceValueLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_StorageSpaceValueLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_StorageSpaceValueLabel, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_AboutDeviceLable16 = lv_label_create(ui_AboutDeviceMainPanel);
    // lv_obj_set_width(ui_AboutDeviceLable16, 272);
    // lv_obj_set_height(ui_AboutDeviceLable16, 1);
    // lv_obj_set_x(ui_AboutDeviceLable16, 406);
    // lv_obj_set_y(ui_AboutDeviceLable16, 363);
    // lv_label_set_long_mode(ui_AboutDeviceLable16, LV_LABEL_LONG_DOT);
    // lv_label_set_text(ui_AboutDeviceLable16, "");
    // lv_obj_set_style_text_font(ui_AboutDeviceLable16, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_AboutDeviceLable16, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_AboutDeviceLable16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FactorymodePanel = lv_obj_create(ui_AboutDevice);
    lv_obj_set_width(ui_FactorymodePanel, 640);
    lv_obj_set_height(ui_FactorymodePanel, 360);
    lv_obj_set_pos(ui_FactorymodePanel, 0, 60);
    lv_obj_align(ui_FactorymodePanel, LV_ALIGN_CENTER, 0, 0);
    lv_obj_clear_flag(ui_FactorymodePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_FactorymodePanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FactorymodePanel, lv_color_hex(0x18181B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FactorymodePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FactorymodePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_FactorymodePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_FactorymodePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_FactorymodePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_FactorymodePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_FactorymodePanel, LV_OBJ_FLAG_HIDDEN);

    char buff[150] = {0};
    sprintf(buff, "%s\n%s\n%s\n%s", "正式服务器","预发布服务器","测试服务器", "联调服务器");

    ui_FactorymodeServerSetDropdown = lv_dropdown_create(ui_FactorymodePanel);
    lv_dropdown_set_options(ui_FactorymodeServerSetDropdown, buff);
    lv_obj_set_width(ui_FactorymodeServerSetDropdown, 220);
    lv_obj_set_height(ui_FactorymodeServerSetDropdown, 50);
    lv_obj_align(ui_FactorymodeServerSetDropdown, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_add_flag(ui_FactorymodeServerSetDropdown, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_FactorymodeServerSetDropdown, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FactorymodeServerSetDropdown, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_FactorymodeServerSetDropdown, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeServerSetDropdown, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_FactorymodeServerSetDropdown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FactorymodeServerSetDropdown, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FactorymodeServerSetDropdown, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_FactorymodeServerSetDropdown, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_FactorymodeServerSetDropdown, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FactorymodeServerSetDropdown, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_FactorymodeServerSetDropdown, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FactorymodeServerSetDropdown, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeServerSetDropdown, lv_font24.font, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_FactorymodeServerSetDropdown, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_FactorymodeServerSetDropdown, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_FactorymodeServerSetDropdown, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_FactorymodeServerSetDropdown, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_FactorymodeServerSetDropdown, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_FactorymodeServerSetDropdown, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_dropdown_set_symbol(ui_FactorymodeServerSetDropdown, &ui_img_expand_down_png);

    ui_FactorymodeConfirmBtn = lv_btn_create(ui_FactorymodePanel);
    lv_obj_set_width(ui_FactorymodeConfirmBtn, 116);
    lv_obj_set_height(ui_FactorymodeConfirmBtn, 50);
    lv_obj_align_to(ui_FactorymodeConfirmBtn, ui_FactorymodeServerSetDropdown, LV_ALIGN_OUT_BOTTOM_MID, 30, 100);
    lv_obj_add_flag(ui_FactorymodeConfirmBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_FactorymodeConfirmBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_FactorymodeConfirmBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FactorymodeConfirmBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FactorymodeConfirmBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_FactorymodeConfirmBtn, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_FactorymodeConfirmBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_FactorymodeConfirmBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_FactorymodeConfirmBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_FactorymodeConfirmBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FactorymodeConfirmBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeConfirmBtn, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_FactorymodeConfirmBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_FactorymodeConfirmBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_FactorymodeConfirmBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_FactorymodeConfirmBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_FactorymodeConfirmBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_FactorymodeConfirmBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    ui_FactorymodeConfirmBtnLabel = lv_label_create(ui_FactorymodeConfirmBtn);
    lv_obj_set_width(ui_FactorymodeConfirmBtnLabel, lv_pct(100));
    lv_obj_set_height(ui_FactorymodeConfirmBtnLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_FactorymodeConfirmBtnLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_FactorymodeConfirmBtnLabel, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_FactorymodeConfirmBtnLabel, Confirm[language_index]);
    lv_obj_set_style_text_align(ui_FactorymodeConfirmBtnLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeConfirmBtnLabel, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    ui_FactorymodeKeyboardTextArea = lv_textarea_create(ui_FactorymodePanel);
    lv_obj_set_width(ui_FactorymodeKeyboardTextArea, 300);
    lv_obj_set_height(ui_FactorymodeKeyboardTextArea, LV_SIZE_CONTENT);
    lv_obj_align(ui_FactorymodeKeyboardTextArea, LV_ALIGN_TOP_RIGHT, -10, 10);
    lv_textarea_set_placeholder_text(ui_FactorymodeKeyboardTextArea, InputPasswordMsg[language_index]);
    lv_obj_set_style_text_font(ui_FactorymodeKeyboardTextArea, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_FactorymodeKeyboardTextArea, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_FactorymodeKeyboardTextArea, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_FactorymodeKeyboardTextArea, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_FactorymodeKeyboardTextArea, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_FactorymodeKeyboardTextArea, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_FactorymodeKeyboardTextArea, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    
    //裸板测试
    ui_FactorymodeBareBoardTestBtn = lv_btn_create(ui_FactorymodePanel);
    lv_obj_set_width(ui_FactorymodeBareBoardTestBtn, 146);
    lv_obj_set_height(ui_FactorymodeBareBoardTestBtn, 50);
    lv_obj_align_to(ui_FactorymodeBareBoardTestBtn, ui_FactorymodeKeyboardTextArea, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 14);
    lv_obj_add_flag(ui_FactorymodeBareBoardTestBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_FactorymodeBareBoardTestBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_FactorymodeBareBoardTestBtn, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_radius(ui_FactorymodeBareBoardTestBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FactorymodeBareBoardTestBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FactorymodeBareBoardTestBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_FactorymodeBareBoardTestBtn, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_FactorymodeBareBoardTestBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_FactorymodeBareBoardTestBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_FactorymodeBareBoardTestBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_FactorymodeBareBoardTestBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FactorymodeBareBoardTestBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeBareBoardTestBtn, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(ui_FactorymodeBareBoardTestBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_FactorymodeBareBoardTestBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_FactorymodeBareBoardTestBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_FactorymodeBareBoardTestBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_FactorymodeBareBoardTestBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_FactorymodeBareBoardTestBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    ui_FactorymodeBareBoardTestBtnLabal = lv_label_create(ui_FactorymodeBareBoardTestBtn);
    lv_obj_set_width(ui_FactorymodeBareBoardTestBtnLabal, lv_pct(100));
    lv_obj_set_height(ui_FactorymodeBareBoardTestBtnLabal, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_FactorymodeBareBoardTestBtnLabal, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_FactorymodeBareBoardTestBtnLabal, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_FactorymodeBareBoardTestBtnLabal, "裸板测试");
    lv_obj_set_style_text_align(ui_FactorymodeBareBoardTestBtnLabal, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeBareBoardTestBtnLabal, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //整机测试
    ui_FactorymodeMachineTestBtn = lv_btn_create(ui_FactorymodePanel);
    lv_obj_set_width(ui_FactorymodeMachineTestBtn, 146);
    lv_obj_set_height(ui_FactorymodeMachineTestBtn, 50);
    lv_obj_align_to(ui_FactorymodeMachineTestBtn, ui_FactorymodeKeyboardTextArea, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 14);
    lv_obj_add_flag(ui_FactorymodeMachineTestBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_FactorymodeMachineTestBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_clear_flag(ui_FactorymodeMachineTestBtn, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_radius(ui_FactorymodeMachineTestBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FactorymodeMachineTestBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FactorymodeMachineTestBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_FactorymodeMachineTestBtn, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_FactorymodeMachineTestBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_FactorymodeMachineTestBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_FactorymodeMachineTestBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_FactorymodeMachineTestBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FactorymodeMachineTestBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeMachineTestBtn, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_FactorymodeMachineTestBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_FactorymodeMachineTestBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_FactorymodeMachineTestBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_FactorymodeMachineTestBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_FactorymodeMachineTestBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_FactorymodeMachineTestBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    ui_FactorymodeMachineTestBtnLabel = lv_label_create(ui_FactorymodeMachineTestBtn);
    lv_obj_set_width(ui_FactorymodeMachineTestBtnLabel, lv_pct(100));
    lv_obj_set_height(ui_FactorymodeMachineTestBtnLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_FactorymodeMachineTestBtnLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_FactorymodeMachineTestBtnLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_FactorymodeMachineTestBtnLabel, "整机测试");
    lv_obj_set_style_text_align(ui_FactorymodeMachineTestBtnLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeMachineTestBtnLabel, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //调平数据网格
    ui_FactorymodeLevelTable = lv_table_create(ui_FactorymodePanel);
    lv_obj_set_width(ui_FactorymodeLevelTable, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FactorymodeLevelTable, LV_SIZE_CONTENT);
    lv_obj_set_style_pad_top(ui_FactorymodeLevelTable, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_FactorymodeLevelTable, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_FactorymodeLevelTable, 15, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_FactorymodeLevelTable, 15, LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_table_set_row_cnt(ui_FactorymodeLevelTable, 6);
    lv_table_set_col_cnt(ui_FactorymodeLevelTable, 6);
    lv_table_set_col_width(ui_FactorymodeLevelTable, 0, 70);
    lv_table_set_col_width(ui_FactorymodeLevelTable, 1, 70);
    lv_table_set_col_width(ui_FactorymodeLevelTable, 2, 70);
    lv_table_set_col_width(ui_FactorymodeLevelTable, 3, 70);
    lv_table_set_col_width(ui_FactorymodeLevelTable, 4, 70);
    lv_table_set_col_width(ui_FactorymodeLevelTable, 5, 70);

    lv_obj_align(ui_FactorymodeLevelTable, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_obj_set_style_outline_width(ui_FactorymodeLevelTable, 1, LV_PART_ITEMS);  // 添加网格
    
    //获取调平数据
    ui_FactorymodeGetLevelDataBtn = lv_btn_create(ui_FactorymodePanel);
    lv_obj_set_width(ui_FactorymodeGetLevelDataBtn, 200);
    lv_obj_set_height(ui_FactorymodeGetLevelDataBtn, 50);
    lv_obj_align_to(ui_FactorymodeGetLevelDataBtn, ui_FactorymodeConfirmBtn, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 20);
    lv_obj_add_flag(ui_FactorymodeGetLevelDataBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_FactorymodeGetLevelDataBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_FactorymodeGetLevelDataBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FactorymodeGetLevelDataBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FactorymodeGetLevelDataBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_FactorymodeGetLevelDataBtn, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_FactorymodeGetLevelDataBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_FactorymodeGetLevelDataBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_FactorymodeGetLevelDataBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_FactorymodeGetLevelDataBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FactorymodeGetLevelDataBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeGetLevelDataBtn, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_FactorymodeGetLevelDataBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_FactorymodeGetLevelDataBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_FactorymodeGetLevelDataBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_FactorymodeGetLevelDataBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_FactorymodeGetLevelDataBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_FactorymodeGetLevelDataBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    ui_FactorymodeGetLevelDataBtnLabel = lv_label_create(ui_FactorymodeGetLevelDataBtn);
    lv_obj_set_width(ui_FactorymodeGetLevelDataBtnLabel, lv_pct(100));
    lv_obj_set_height(ui_FactorymodeGetLevelDataBtnLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_FactorymodeGetLevelDataBtnLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_FactorymodeGetLevelDataBtnLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_FactorymodeGetLevelDataBtnLabel, "获取调平数据");
    lv_obj_set_style_text_align(ui_FactorymodeGetLevelDataBtnLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeGetLevelDataBtnLabel, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //保存AI数据
    ui_FactorymodeSaveAIdataBtn = lv_btn_create(ui_FactorymodePanel);
    lv_obj_set_width(ui_FactorymodeSaveAIdataBtn, 200);
    lv_obj_set_height(ui_FactorymodeSaveAIdataBtn, 50);
    lv_obj_align_to(ui_FactorymodeSaveAIdataBtn, ui_FactorymodeGetLevelDataBtn, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 20);
    lv_obj_add_flag(ui_FactorymodeSaveAIdataBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_FactorymodeSaveAIdataBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_FactorymodeSaveAIdataBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FactorymodeSaveAIdataBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FactorymodeSaveAIdataBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_FactorymodeSaveAIdataBtn, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_FactorymodeSaveAIdataBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_FactorymodeSaveAIdataBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_FactorymodeSaveAIdataBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_FactorymodeSaveAIdataBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FactorymodeSaveAIdataBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeSaveAIdataBtn, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_FactorymodeSaveAIdataBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_FactorymodeSaveAIdataBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_FactorymodeSaveAIdataBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_FactorymodeSaveAIdataBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_FactorymodeSaveAIdataBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_FactorymodeSaveAIdataBtn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    ui_FactorymodeSaveAIdataBtnLabel = lv_label_create(ui_FactorymodeSaveAIdataBtn);
    lv_obj_set_width(ui_FactorymodeSaveAIdataBtnLabel, lv_pct(100));
    lv_obj_set_height(ui_FactorymodeSaveAIdataBtnLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_FactorymodeSaveAIdataBtnLabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_FactorymodeSaveAIdataBtnLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_FactorymodeSaveAIdataBtnLabel, "保存AI数据");
    lv_obj_set_style_text_align(ui_FactorymodeSaveAIdataBtnLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FactorymodeSaveAIdataBtnLabel, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FactorymodeKeyboard = lv_keyboard_create(ui_FactorymodePanel);
    lv_obj_set_width(ui_FactorymodeKeyboard, 620);
    lv_obj_set_height(ui_FactorymodeKeyboard, 180);
    lv_obj_set_x(ui_FactorymodeKeyboard, 0);
    lv_obj_set_y(ui_FactorymodeKeyboard, 0);
    //lv_obj_add_flag(ui_FactorymodeKeyboard, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_text_color(ui_FactorymodeKeyboard, lv_color_hex(0x000000), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FactorymodeKeyboard, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FactorymodeKeyboard, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_FactorymodeKeyboard, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_FactorymodeKeyboard, LV_OBJ_FLAG_HIDDEN);

    lv_obj_set_style_bg_color(ui_FactorymodeKeyboard, lv_color_hex(0xFFFFFF), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FactorymodeKeyboard, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_keyboard_set_textarea(ui_FactorymodeKeyboard, ui_FactorymodeKeyboardTextArea);

    lv_obj_set_style_outline_width(ui_FactorymodeKeyboard, 0, LV_PART_MAIN | LV_STATE_EDITED);
    lv_obj_set_style_outline_width(ui_FactorymodeKeyboard, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    lv_obj_add_event_cb(ui_AboutDeviceBackBtn, ui_event_AboutDeviceBackBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceImage1, ui_event_AboutDeviceImage1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceImage2, ui_event_AboutDeviceImage2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceImage3, ui_event_AboutDeviceImage3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceImage4, ui_event_AboutDeviceImage4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDeviceImage5, ui_event_AboutDeviceImage5, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_DeviceMacAddrValueLabel, ui_event_AboutDeviceLable13, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FactorymodeServerSetDropdown, ui_event_AboutDeviceDropdown1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FactorymodeConfirmBtn, ui_event_FactorymodeConfirmBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FactorymodeBareBoardTestBtn, ui_event_FactorymodeBareBoardTestBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FactorymodeMachineTestBtn, ui_event_AboutDeviceButton4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FactorymodeGetLevelDataBtn, ui_event_AboutDeviceButton5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FactorymodeSaveAIdataBtn, ui_event_AboutDeviceButton6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FactorymodeKeyboardTextArea, ui_event_AboutDeviceTextArea1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FactorymodeKeyboard, ui_event_AboutDeviceKeyboard1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AboutDevice, ui_event_AboutDevice, LV_EVENT_SCREEN_LOADED, NULL);
}

static void wait_timerout_handle(lv_timer_t * timer)
{
    FactorymodeFlag = false;
    if (ui_AboutDeviceWaittimer)
    {
        lv_timer_del(ui_AboutDeviceWaittimer);
    }
}

/**
 * @description: 关于本机返回按钮
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_AboutDeviceBackBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
       // _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);

        static long int lasttime = 0;
        static int count = 0;
        struct timeval startTime;

        gettimeofday(&startTime, NULL);
        CrLogI("FactorymodeFlag%d, current time%Id", FactorymodeFlag, startTime.tv_sec);

        if (FactorymodeFlag == true)
        {
            if(startTime.tv_sec - lasttime <= 2)//在2秒内
            {
                count++;
                lasttime = startTime.tv_sec;
                CrLogI("count %d", count);
                if(count > 4) //点击5次出现弹窗
                {
                    count = 0;
                    FactorymodeFlag = false;
                    CrLogI("Enter factory mode");
                    lv_obj_clear_flag(ui_FactorymodePanel, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_FactorymodeBareBoardTestBtn, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_clear_flag(ui_FactorymodeMachineTestBtn, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_opa(ui_FactorymodeBareBoardTestBtn, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(ui_FactorymodeMachineTestBtn, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    //FactoryModePageChangeObjs();
                    LoadPage(ui_AboutDevice, 2);
                }
            }
            else
            {       
                lasttime = startTime.tv_sec;
                count = 0;
            }
        }
        else {
            // BackPrepage(false);
            // LoadPage(ui_ScreenSettings, 2);
            // lv_group_focus_obj(ui_AboutDevicePanel);
            LoadSettingsScreenAndObjs(false, 0);
            LoadSettingsScreenAndObjs(true, ABOUT_DEVICE_ITEM);
        }
    }

    if (event_code == LV_EVENT_LONG_PRESSED)
    {
        FactorymodeFlag = true;
        ui_AboutDeviceWaittimer = lv_timer_create(wait_timerout_handle, 2300, NULL);
        lv_timer_set_repeat_count(ui_AboutDeviceWaittimer, 1);
    }
}

void ui_event_FactorymodeConfirmBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        uint16_t index;
        index = lv_dropdown_get_selected(ui_FactorymodeServerSetDropdown);
        CrLogI("screen_save_value set %d",index);
        switch(index)
        {
            case 0: set_printer_data(0x06,3,"n1");break;
            case 1: set_printer_data(0x06,3,"n2");break;
            case 2: set_printer_data(0x06,3,"n3");break;
            case 3: set_printer_data(0x06,3,"n4");break;
            default:break;
        }
        lv_obj_add_flag(ui_FactorymodePanel, LV_OBJ_FLAG_HIDDEN);
       //AboutDevicePageChangeObjs(0);
        //BackPrepage(false);
        LoadPage(ui_AboutDevice, 1);
    }
}

void ui_event_FactorymodeBareBoardTestBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if (VerifyPasswdFlag)
        {
            CrLogI("factroy mode start");
            DisFactoryTestControl(FACTORY_TEST_START);
        }
        else
        {
            create_msgbox("请输入密码", NULL, 500, lv_scr_act());
        }
       
    }
}

void ui_event_AboutDeviceButton4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if (VerifyPasswdFlag)
        {
            CrLogI("machine mode start");
            DisFactoryTestControl(MACHINE_TEST_START);
        }
        else
        {
            create_msgbox("请输入密码", NULL, 500, lv_scr_act());
        }
    }
}

void ui_event_AboutDeviceButton5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        CrLogI("get level data");
        get_printer_data(0x09, 2, "7");
    }
}

void ui_event_AboutDeviceButton6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        create_msgbox("数据已保存", NULL, 500, lv_scr_act());
        DisSaveDataCollection(COLLECTION_AI_CAMERA_IMAGE);
        DisSaveDataCollection(COLLECTION_AI_POINT_CLOUD);
    }
}

void ui_event_AboutDeviceDropdown1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_READY) {
        lv_obj_t *list_method = lv_dropdown_get_list(ui_FactorymodeServerSetDropdown);
        if ( !list_method )
            return;
        lv_obj_set_style_text_color(list_method, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(list_method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(list_method, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(list_method, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(list_method, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(list_method, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(list_method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(list_method, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(list_method, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(list_method, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        
        lv_obj_set_style_bg_color(list_method, lv_color_hex(0x42BDD8), LV_PART_SELECTED | LV_STATE_PRESSED);
        lv_obj_set_style_bg_opa(list_method, 255, LV_PART_SELECTED | LV_STATE_PRESSED);
    }
}

void ui_event_AboutDeviceLable13(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        static long int lasttime = 0;
        static int count = 0;
        struct timeval startTime;

        gettimeofday(&startTime, NULL);
        CrLogI("current time%Id", startTime.tv_sec);


        if(startTime.tv_sec - lasttime <= 1)//在1秒内
        {
            count++;
            lasttime = startTime.tv_sec;
            if(count > 5) //点击5次出现弹窗
            {
                count = 0;
                lv_obj_clear_flag(ui_FactorymodePanel, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_FactorymodeBareBoardTestBtn, LV_OBJ_FLAG_CLICKABLE);
                lv_obj_clear_flag(ui_FactorymodeMachineTestBtn, LV_OBJ_FLAG_CLICKABLE);
                lv_obj_set_style_bg_opa(ui_FactorymodeBareBoardTestBtn, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(ui_FactorymodeMachineTestBtn, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
        }
        else
        {
            lasttime = startTime.tv_sec;
            count = 0;
        }

    }
}

void ui_event_AboutDeviceFactorymode(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char *userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        static long int lasttime = 0;
        static int count = 0;

        struct timeval startTime;
        gettimeofday(&startTime, NULL);
        if(count == 0)lasttime = startTime.tv_sec;
        if(startTime.tv_sec - lasttime <= 1)//在1秒内
        {
            CrLogI("current time%Id, lasttime:%Id, userdata:%c", startTime.tv_sec, lasttime, userdata[0]);
            lasttime = startTime.tv_sec;
            if(count == 0 && userdata[0] == '1')
            {
                count++;
                CrLogI("current time%d", count);
            }
            else if(count == 1 && userdata[0] == '2')
            {
                count++;
                CrLogI("current time%d", count);
            }
            else if(count == 2 && userdata[0] == '3')
            {
                count++;
                CrLogI("current time%d", count);
            }
            else if(count == 3 && userdata[0] == '4')
            {
                count++;
                CrLogI("current time%d", count);
            }
            else if(count >= 4 && userdata[0] == '5')
            {
                CrLogI("current time%d", count);
                count++;
                if(count == 7)
                {
                    lv_obj_clear_flag(ui_FactorymodePanel, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_FactorymodeBareBoardTestBtn, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_clear_flag(ui_FactorymodeMachineTestBtn, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_opa(ui_FactorymodeBareBoardTestBtn, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(ui_FactorymodeMachineTestBtn, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
            else
            {
                CrLogI("reset time count");
                lasttime = startTime.tv_sec;
                count = 0;
            }
        }
        else
        {
            CrLogI("reset time count");
            lasttime = startTime.tv_sec;
            count = 0;
        }

    }
}

void ui_event_AboutDeviceImage1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        // Your code here
        if ( home_printing_is_printing_finished() )
            LoadHomeNormalScreen();
        else
            LoadHomePrintingScreen();
    }
}

void ui_event_AboutDeviceImage2(lv_event_t * e)
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

void ui_event_AboutDeviceImage3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadFileManageScreen();
    }
}

void ui_event_AboutDeviceImage4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        //_ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_AboutDeviceImage5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadCustomerServiceScreen();
    }
}

void ui_event_AboutDeviceTextArea1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED) {
        send_buzzer(0x01);
        lv_keyboard_set_textarea(ui_FactorymodeKeyboard, ui_FactorymodeKeyboardTextArea);
        lv_obj_clear_flag(ui_FactorymodeKeyboard, LV_OBJ_FLAG_HIDDEN);
        //lv_group_remove_all_objs(encoder_group);
       // lv_group_add_obj(encoder_group, ui_FactorymodeKeyboard);
        lv_group_focus_obj(ui_FactorymodeKeyboard);
        lv_group_set_editing(encoder_group, 1);
    }

    // if(event_code == LV_EVENT_DEFOCUSED) {
    //     lv_keyboard_set_textarea(ui_FactorymodeKeyboard, NULL);
    //     lv_obj_add_flag(ui_FactorymodeKeyboard, LV_OBJ_FLAG_HIDDEN);
    // }
}

void ui_event_AboutDeviceKeyboard1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        uint32_t id = lv_btnmatrix_get_selected_btn(target);
        lv_keyboard_mode_t mode = lv_keyboard_get_mode(target);
        CrLogI("keyboard input id: %d,mode :%d",id,mode);
        if(id == 39)
        {
            const char *passw = lv_textarea_get_text(ui_FactorymodeKeyboardTextArea);
            if(passw != NULL)
            {
                CrLogI("PASSWORD: %s",passw);
                if(strcmp(passw, PASSWORD) == 0)//密码匹配
                {
                    lv_obj_add_flag(ui_FactorymodeBareBoardTestBtn, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_add_flag(ui_FactorymodeMachineTestBtn, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_opa(ui_FactorymodeBareBoardTestBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(ui_FactorymodeMachineTestBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_textarea_set_text(ui_FactorymodeKeyboardTextArea, "");
                    lv_obj_add_flag(ui_FactorymodeKeyboard, LV_OBJ_FLAG_HIDDEN);

                    lv_group_set_editing(encoder_group, 0); //退出编辑模式
                    lv_group_focus_obj(ui_FactorymodeBareBoardTestBtn);
                    create_msgbox("密码正确", NULL, 1000, lv_scr_act());
                    VerifyPasswdFlag = true;
                }
                else
                {
                    
                    lv_keyboard_set_textarea(ui_FactorymodeKeyboard, NULL);
                    lv_obj_add_flag(ui_FactorymodeKeyboard, LV_OBJ_FLAG_HIDDEN);
                    lv_group_set_editing(encoder_group, 0); //退出编辑模式
                    lv_group_focus_obj(ui_FactorymodeBareBoardTestBtn);
                    create_msgbox("密码错误", NULL, 1000, lv_scr_act());
                    //FactoryModePageChangeObjs();
                   // lv_group_focus_next(encoder_group);
                }
            

            }
        }
    }
    if(event_code == LV_EVENT_DRAW_PART_BEGIN) 
    {
        lv_obj_draw_part_dsc_t * dsc = lv_event_get_param(e);

        if(lv_btnmatrix_get_selected_btn(target) == dsc->id) //键盘选中后样式修改
        {
            //printf("LV_EVENT_DRAW_PART_BEGIN dsc->id :%d\n", dsc->id);
            //dsc->rect_dsc->bg_color = lv_color_hex(0xFF954D);
            dsc->rect_dsc->bg_color = lv_color_hex(0x14ae5c);
            dsc->rect_dsc->bg_opa = 200;
            dsc->rect_dsc->border_color = lv_color_hex(0xCDF6FF);
            dsc->rect_dsc->border_opa = 255;
            dsc->rect_dsc->outline_color = lv_color_hex(0xCDF6FF);
            dsc->rect_dsc->outline_width = 0;
            //dsc->label_dsc->color = lv_color_hex(0x42BDD8);
          

        }
    }

}

void ui_event_AboutDevice(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load aboutdevice page.");
        get_printer_data(0x14,1,"\0");
        get_printer_data(0x06,2,"n");
        switch (UIType)
        {
            case CR_K1:
            {
                lv_label_set_text(ui_AboutDeviceLabel2, "K1");
                lv_label_set_text(ui_AboutDeviceLable3, "220x220x250mm");
                lv_img_set_src(ui_AboutDeviceImage, &ui_img_machine_png);
                break;
            }
            case CR_K1_Max: 
            {
                lv_img_set_src(ui_AboutDeviceImage, &ui_img_k1max_about_png);
                lv_label_set_text(ui_AboutDeviceLabel2, "K1 MAX");
                lv_label_set_text(ui_AboutDeviceLable3, "300x300x300mm");
                break;
            }
        }
        lv_img_set_src(ui_AboutDeviceImage, &ui_img_f001_machine_png);
        lv_label_set_text(ui_AboutDeviceLabel2, "F001");
        lv_label_set_text(ui_AboutDeviceLable3, "220x220x250mm");
        // int width = lv_obj_get_width(ui_AboutDeviceImage);
        // int scale = 256 * 244 / width;
        // lv_img_set_zoom(ui_AboutDeviceImage, scale);

        for(int i = 0; i < lv_table_get_row_cnt(ui_FactorymodeLevelTable); i++)
            for(int j = 0; j < lv_table_get_col_cnt(ui_FactorymodeLevelTable); j++)
                lv_table_set_cell_value(ui_FactorymodeLevelTable, i, j, "");
    }
}

void refresh_aboutdevice_page(MachineInfo_t machine)
{
    if(ui_DeviceNameValueLabel != NULL)
        lv_label_set_text(ui_DeviceNameValueLabel, machine.MachineName);
    if(ui_FirmVersionValueLabel != NULL)
        lv_label_set_text(ui_FirmVersionValueLabel, machine.ScreenVersion);
    if(ui_DeviceMacAddrValueLabel != NULL)
        lv_label_set_text(ui_DeviceMacAddrValueLabel, machine.MacValue);

    lv_label_set_text(ui_SerialNumberValueLabel, GetSystemConfig().device_sn);
    //TODO:SN号后期需更新为工厂的SN号
    // if(ui_SerialNumberValueLabel != NULL)
    // {
    //     char * productionSn = NULL;
    //     // 从文件获取生产信息
    //     json_object *productionInfoObj = json_object_from_file(GetMachineProductionInfo());
    //     if (!productionInfoObj) {
    //         CrLogW("no production info\n");
    //     }
    //     // 获取生产SN号
    //     json_object *productionSnObj = json_object_object_get(productionInfoObj, "productionSn");
    //     if (productionSnObj && json_object_is_type(productionSnObj, json_type_string)) {
    //         productionSn = json_object_get_string(productionSnObj);
    //     }
    //     json_object_put(productionInfoObj);
    //     CrLogI("production sn = %s\n", productionSn);
    //     lv_label_set_text(ui_SerialNumberValueLabel, productionSn);
    // }

    if(atoi(machine.PrintedTime) >= 0)
    {
        int day = 0;
        int hou = 0;
        int min = 0;
        int sec = atoi(machine.PrintedTime);

        day = sec / (60 * 60 * 24);
        hou = (sec - day * (60 * 60 * 24)) / (60 * 60);
        min = (sec - day * (60 * 60 * 24) - hou * (60 * 60)) / 60;

        char buff[100] = {0};
        if(day <= 99)
            snprintf(buff, 100, "%02dd%02dh%02dm", day, hou, min);
        else
            snprintf(buff, 100, "%dd%02dh%02dm", day, hou, min);
        if(total_time_value[0] != '\0')
            lv_label_set_text(ui_CumulativeTimeValueLabel, buff); 
    }

    if(ui_StorageSpaceValueLabel != NULL)
    {
        float used  = 0.0f;
        float total = 0.0f;
        total = atof(machine.TotalDiskCapacity);
        used  = atof(machine.UsedDiskCapacity);
        used = used / 1024;
        total = total / 1024;
        char buff[100] = {0};
        snprintf(buff, 100, "%.1f/%.1fGB", used, total);
        lv_label_set_text(ui_StorageSpaceValueLabel, buff);
    }
    // if(screen_ver_value[0] != '\0')
    //     lv_label_set_text(guider_ui.about_label_screen, screen_ver_value);
    // if(official_web_value[0] != '\0')
    //     lv_label_set_text(guider_ui.about_label_website, official_web_value);
}

void refresh_serverinfo_page(int state)
{
    CrLogI("refresh the server info,state:%d",state);
    switch (state)
    {
        case 1:lv_dropdown_set_selected(ui_FactorymodeServerSetDropdown, 0);break;
        case 2:lv_dropdown_set_selected(ui_FactorymodeServerSetDropdown, 1);break;
        case 3:lv_dropdown_set_selected(ui_FactorymodeServerSetDropdown, 2);break;
        case 4:lv_dropdown_set_selected(ui_FactorymodeServerSetDropdown, 3);break;
        default:
            break;
    }
}

void refresh_factoryleveldata(int len,char * data, char level_point_value)
{
    CrLogI("refresh the factoryleveldata:%s",data);
    data++;
    char tempBuff[1024] = {0};
    if (data) {
        memcpy(tempBuff, data, strlen(data));
    }
    char *tempsingle = strtok(tempBuff, "\t");
    int count = 0;
    //先获取调平点总数
    while(tempsingle)
    {
        CrLogI("single level data : %s,count: %d",tempsingle, count);
        count++;
        tempsingle = strtok(NULL,"\t");
    }


    int levelcount = 5;
    switch (count)
    {
        case 9:lv_table_set_row_cnt(ui_FactorymodeLevelTable, 3);
                 lv_table_set_col_cnt(ui_FactorymodeLevelTable, 3);
                 levelcount = 3;break;
        case 16:lv_table_set_row_cnt(ui_FactorymodeLevelTable, 4);
                 lv_table_set_col_cnt(ui_FactorymodeLevelTable, 4);
                 levelcount = 4;break;
        case 25:lv_table_set_row_cnt(ui_FactorymodeLevelTable, 5);
                 lv_table_set_col_cnt(ui_FactorymodeLevelTable, 5);
                 levelcount = 5;break;
         case 36:lv_table_set_row_cnt(ui_FactorymodeLevelTable, 6);
                 lv_table_set_col_cnt(ui_FactorymodeLevelTable, 6);
                 levelcount = 6;break;
        default:CrLogW("level point count:%d",count);
            break;
    }


    char *single = strtok(data, "\t");
    float rowcount = sqrt(count);
    int i = 0;
    int j = (int)rowcount;
    count = 0;
    while(single)
    {
        CrLogI("single level data : %s,count: %d",single, count);
        if(count % (int)rowcount != 0)
        {
            i++;
            CrLogI("1data:%d,%d", i,j);
            lv_table_set_cell_value(ui_FactorymodeLevelTable, j, i, single);
        }
        else
        {
            i = 0;
            j--;
            CrLogI("2data:%d,%d", i,j);
            lv_table_set_cell_value(ui_FactorymodeLevelTable, j, i, single);
            lv_table_set_col_width(ui_FactorymodeLevelTable, j,70);
        }
        count++;
        single = strtok(NULL,"\t");
    }

}

void about_device_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_AboutDeviceTitle )
        lv_label_set_text(ui_AboutDeviceTitle, AboutDevice[language_index]);

    // if ( ui_AboutDeviceBackBtnlabel )
    //     lv_label_set_text(ui_AboutDeviceBackBtnlabel, Back[language_index]);
    
    if ( ui_DeviceNameLabel )
        lv_label_set_text(ui_DeviceNameLabel, DeviceNameArray[language_index]);

    // if ( ui_DeviceModeLable )
    //     lv_label_set_text(ui_DeviceModeLable, DeviceModelArray[language_index]);

    if ( ui_FirmwareVersionLabel )
        lv_label_set_text(ui_FirmwareVersionLabel, Version[language_index]);

    if ( ui_DeviceMacAddrLabel )
        lv_label_set_text(ui_DeviceMacAddrLabel, MacAddrArray[language_index]);

    if ( ui_CumulativeTimeLabel )
    {
        lv_label_set_text(ui_CumulativeTimeLabel, CumulativeTime[language_index]);
        lv_obj_set_height(ui_CumulativeTimeLabel, 28);
        lv_obj_align_to(ui_CumulativeTimeLabel, ui_SerialNumberLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 17);
        lv_obj_set_style_text_line_space(ui_CumulativeTimeLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
        for(int i = 0; i < strlen(CumulativeTime[language_index]); i++)
        {
            if(CumulativeTime[language_index][i] == '\n')
            {
                lv_label_set_text(ui_CumulativeTimeLabel, CumulativeTime[language_index]);
                lv_obj_set_height(ui_CumulativeTimeLabel, 48);
                lv_obj_align_to(ui_CumulativeTimeLabel, ui_SerialNumberLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
                lv_obj_set_style_text_line_space(ui_CumulativeTimeLabel, -5, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
            }
        }
    }

    if ( ui_StorageSpaceLabel )
    {
        lv_label_set_text(ui_StorageSpaceLabel, StorageArray[language_index]);
        lv_obj_set_height(ui_StorageSpaceLabel, 28);
        lv_obj_align_to(ui_StorageSpaceLabel, ui_CumulativeTimeLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 17);
        lv_obj_set_style_text_line_space(ui_StorageSpaceLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
        for(int i = 0; i < strlen(StorageArray[language_index]); i++)
        {
            if(StorageArray[language_index][i] == '\n')
            {
                lv_label_set_text(ui_StorageSpaceLabel, StorageArray[language_index]);
                lv_obj_set_height(ui_StorageSpaceLabel, 48);
                lv_obj_align_to(ui_StorageSpaceLabel, ui_CumulativeTimeLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
                lv_obj_set_style_text_line_space(ui_StorageSpaceLabel, -5, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距

            }
        }
    }
}

static lv_obj_t * ui_ChangeObjsWaittimer = NULL;
static void changeObjs_timerout_handle(lv_timer_t * timer)
{
    FactoryModePageChangeObjs();

    if (ui_ChangeObjsWaittimer)
    {
        lv_timer_del(ui_ChangeObjsWaittimer);
    }
}

static void LoadAboutDevicePage(void)
{
    _ui_screen_change(ui_AboutDevice, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

/**
 * @description: 设置页编码器对象事件组设置
 * @return {*}
 * @param {uint8_t} index
 */
static void AboutDevicePageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *AboutDeviceNode = find_page(ui_AboutDevice);
    AboutDeviceNode->nav_level = index;
    if (index == 1)
    {
        lv_group_add_obj(encoder_group, ui_AboutDeviceBackBtn);
    }
    else if (index == 2)
    {

        ui_ChangeObjsWaittimer = lv_timer_create(changeObjs_timerout_handle, 600, NULL);
        lv_timer_set_repeat_count(ui_ChangeObjsWaittimer, 1);
    }
}

/**
 * @description: 工厂测试模式页添加事件对象到事件组
 * @return {*}
 * @param {uint8_t} index
 */
static void FactoryModePageChangeObjs(void)
{
    lv_group_add_obj(encoder_group, ui_FactorymodeServerSetDropdown);
    lv_group_add_obj(encoder_group, ui_FactorymodeConfirmBtn);
    lv_group_add_obj(encoder_group, ui_FactorymodeGetLevelDataBtn);
    lv_group_add_obj(encoder_group, ui_FactorymodeSaveAIdataBtn);

    lv_group_add_obj(encoder_group, ui_FactorymodeKeyboardTextArea);
    lv_group_add_obj(encoder_group, ui_FactorymodeKeyboard);
    lv_group_add_obj(encoder_group, ui_FactorymodeBareBoardTestBtn);
    lv_group_add_obj(encoder_group, ui_FactorymodeMachineTestBtn);
}