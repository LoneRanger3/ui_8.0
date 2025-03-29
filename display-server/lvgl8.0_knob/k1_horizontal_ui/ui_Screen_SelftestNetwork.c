/*
 * @Description: 
 * @Author: sunhui
 * @Date: 2023-06-25 02:45:00
 * @LastEditTime: 2023-10-30 03:17:46
 */

#include "ui_Screen_SelftestNetwork.h"
#include "mult_language.h"
#include "src/core/lv_obj_pos.h"
#include "src/misc/lv_area.h"
#include <stdio.h>

lv_obj_t * ui_SelftestNetwork;
lv_obj_t * ui_SelftestNetworkMainpanel;
lv_obj_t * ui_SelftestNetworktitle;
void ui_event_SelftestNetworkNextStepBtn(lv_event_t * e);
lv_obj_t * ui_SelftestNetworkNextStepBtn;
lv_obj_t * ui_SelftestNetworkBtnlabel1;
void ui_event_SelftestNetworkPrevStepBtn(lv_event_t * e);
lv_obj_t * ui_SelftestNetworkPrevStepBtn;
lv_obj_t * ui_SelftestNetworkBtnlabel2;
static lv_obj_t * ui_SelftesLocalNetworkPanel;
static lv_obj_t * ui_SelftestLoclNetworkImage;
lv_obj_t * ui_SelftestNetworkLabel1;
lv_obj_t * ui_SelftestNetworkLabel2;
static lv_obj_t * ui_SelftestNetworkArrowImage;
static lv_obj_t * ui_SelftestNetworkListPanel;
void ui_event_SelftestNetworkButton3(lv_event_t * e);
// lv_obj_t * ui_SelftestNetworkButton3;
// lv_obj_t * ui_SelftestNetworkBtnlabel3;
lv_obj_t * ui_SelftestDialog;
lv_obj_t * ui_SelftestDialogPanel;
lv_obj_t * ui_SelftestDialog_btn_1;
lv_obj_t * ui_SelftestDialog_btn_1_label;
lv_obj_t * ui_SelftestDialog_btn_2;
lv_obj_t * ui_SelftestDialog_btn_2_label;
lv_obj_t * ui_SelftestDialog_btn_3;
lv_obj_t * ui_SelftestDialog_btn_3_label;
wifi_list_t *selftestwifilist_array[20] = {NULL};
static char wifilist_name[64];         
extern const char * * kb_map[3];
extern const lv_btnmatrix_ctrl_t * kb_ctrl[2];
static unsigned char wifilist_state;   
static bool NetworkSetFlag = false;
bool selftest_network_flag = false;
lv_obj_t * listbtn;

lv_obj_t * ui_SelftestNetworkSettingPanel;
lv_obj_t * ui_SelftestNetworkKeyboardPanel;
lv_obj_t * ui_SelftestNetworkNamePanel;
lv_obj_t * ui_selftestnetworkNameLabel;
static lv_obj_t * ui_Selftestnetwork_Keyboard;
static lv_obj_t * ui_Selftestnetwork_TextArea;
lv_obj_t * ui_SelftestnetworkImage8;
lv_obj_t * ui_Selftestnetwork_Label4;

void ui_event_SelftestnetworkImage8(lv_event_t * e);
void ui_event_Selftestnetwork_Keyboard(lv_event_t * e);
void ui_event_SelftestNetwork(lv_event_t * e);
void LoadSelftestNetworkScreen(void);
static void WifiSelftestDialogAddFocusObjs(void);
void SelftestNetworkSetPageAddFocusObjs(uint8_t level);

static wifi_list_t * create_wifi_list_item(lv_obj_t *parent, lv_align_t align_mode, lv_coord_t x, lv_coord_t y);

void ui_SelftestNetwork_screen_init(void)
{
    ui_SelftestNetwork = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SelftestNetwork, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestNetwork, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetwork, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetwork, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    init_pages(ui_SelftestNetwork, SelftestNetworkSetPageAddFocusObjs, LoadSelftestNetworkScreen);
     
    uint8_t language_index = get_cur_language_index();
    ui_SelftestNetworkMainpanel = lv_obj_create(ui_SelftestNetwork);
    lv_obj_set_size(ui_SelftestNetworkMainpanel, 640, 360);
    lv_obj_set_pos(ui_SelftestNetworkMainpanel, 0, 60);
    lv_obj_set_align(ui_SelftestNetworkMainpanel, LV_ALIGN_TOP_LEFT); 
    lv_obj_clear_flag(ui_SelftestNetworkMainpanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestNetworkMainpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkMainpanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkMainpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestNetworkMainpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SelftestNetworkMainpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  
    ui_SelftestNetworktitle = lv_label_create(ui_SelftestNetworkMainpanel);
    lv_obj_set_size(ui_SelftestNetworktitle, 600, 34);
    lv_obj_set_pos(ui_SelftestNetworktitle, 0, 14);
    lv_obj_set_align(ui_SelftestNetworktitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_SelftestNetworktitle, SettingNetwork[language_index]);
    lv_obj_set_style_text_color(ui_SelftestNetworktitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworktitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestNetworktitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestNetworktitle, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //下一步按钮
    ui_SelftestNetworkNextStepBtn = lv_btn_create(ui_SelftestNetworkMainpanel);
    lv_obj_set_size(ui_SelftestNetworkNextStepBtn, 176, 52);
    lv_obj_align(ui_SelftestNetworkNextStepBtn, LV_ALIGN_BOTTOM_RIGHT, -96, -14);
    lv_obj_add_flag(ui_SelftestNetworkNextStepBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SelftestNetworkNextStepBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestNetworkNextStepBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkNextStepBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkNextStepBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestNetworkNextStepBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestNetworkNextStepBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_SelftestNetworkNextStepBtn, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_SelftestNetworkNextStepBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_SelftestNetworkNextStepBtn, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_SelftestNetworkNextStepBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_SelftestNetworkNextStepBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    ui_SelftestNetworkBtnlabel1 = lv_label_create(ui_SelftestNetworkNextStepBtn);
    lv_obj_set_width(ui_SelftestNetworkBtnlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestNetworkBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SelftestNetworkBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestNetworkBtnlabel1, NextStep[language_index]);
    lv_obj_set_style_text_color(ui_SelftestNetworkBtnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworkBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestNetworkBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //上一步按钮
    ui_SelftestNetworkPrevStepBtn = lv_btn_create(ui_SelftestNetworkMainpanel);
    lv_obj_set_size(ui_SelftestNetworkPrevStepBtn, 176, 52);
    lv_obj_align(ui_SelftestNetworkPrevStepBtn, LV_ALIGN_BOTTOM_LEFT, 96, -14);
    lv_obj_add_flag(ui_SelftestNetworkPrevStepBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SelftestNetworkPrevStepBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestNetworkPrevStepBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkPrevStepBtn, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkPrevStepBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestNetworkPrevStepBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestNetworkPrevStepBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_SelftestNetworkPrevStepBtn, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_SelftestNetworkPrevStepBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_SelftestNetworkPrevStepBtn, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_SelftestNetworkPrevStepBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_SelftestNetworkPrevStepBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    ui_SelftestNetworkBtnlabel2 = lv_label_create(ui_SelftestNetworkPrevStepBtn);
    lv_obj_set_width(ui_SelftestNetworkBtnlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestNetworkBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SelftestNetworkBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestNetworkBtnlabel2, PrevStep[language_index]);
    lv_obj_set_style_text_color(ui_SelftestNetworkBtnlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworkBtnlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestNetworkBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //本地网络面板
    ui_SelftesLocalNetworkPanel = lv_obj_create(ui_SelftestNetworkMainpanel);
    lv_obj_set_size(ui_SelftesLocalNetworkPanel, 625, 56);
    lv_obj_set_pos(ui_SelftesLocalNetworkPanel, 10, 60);
    lv_obj_clear_flag(ui_SelftesLocalNetworkPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftesLocalNetworkPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftesLocalNetworkPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftesLocalNetworkPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SelftesLocalNetworkPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SelftesLocalNetworkPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftesLocalNetworkPanel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_SelftesLocalNetworkPanel, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SelftesLocalNetworkPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftesLocalNetworkPanel, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_SelftesLocalNetworkPanel, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_SelftesLocalNetworkPanel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_SelftesLocalNetworkPanel, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_add_flag(ui_SelftesLocalNetworkPanel, LV_OBJ_FLAG_HIDDEN); 
    
    //本地网络电脑图标      
    ui_SelftestLoclNetworkImage = lv_img_create(ui_SelftesLocalNetworkPanel);
    lv_img_set_src(ui_SelftestLoclNetworkImage, &ui_img_network_png);
    lv_obj_set_width(ui_SelftestLoclNetworkImage, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SelftestLoclNetworkImage, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_SelftestLoclNetworkImage, 14);
    lv_obj_set_y(ui_SelftestLoclNetworkImage, 0);
    lv_obj_set_align(ui_SelftestLoclNetworkImage, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_SelftestLoclNetworkImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SelftestLoclNetworkImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags


    ui_SelftestNetworkLabel1 = lv_label_create(ui_SelftesLocalNetworkPanel);
    lv_obj_set_width(ui_SelftestNetworkLabel1, 200);
    lv_obj_set_height(ui_SelftestNetworkLabel1, 28);
    lv_obj_align(ui_SelftestNetworkLabel1, LV_ALIGN_LEFT_MID, 55, 0);
    lv_label_set_text(ui_SelftestNetworkLabel1, LocalNetworkArray[language_index]);
    lv_obj_set_style_text_color(ui_SelftestNetworkLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworkLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestNetworkLabel1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestNetworkLabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    /*未连接*/
    ui_SelftestNetworkLabel2 = lv_label_create(ui_SelftesLocalNetworkPanel);
    lv_obj_set_height(ui_SelftestNetworkLabel2, 28);
    lv_obj_set_width(ui_SelftestNetworkLabel2, LV_SIZE_CONTENT);   /// 123
    lv_obj_align(ui_SelftestNetworkLabel2, LV_ALIGN_RIGHT_MID, -35, 0);
    lv_label_set_text(ui_SelftestNetworkLabel2, UnConnectedArray[language_index]);
    lv_obj_set_style_text_color(ui_SelftestNetworkLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworkLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestNetworkLabel2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestNetworkLabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetworkArrowImage = lv_img_create(ui_SelftesLocalNetworkPanel);
    lv_img_set_src(ui_SelftestNetworkArrowImage, &ui_img_rightarrow_png);
    lv_obj_set_width(ui_SelftestNetworkArrowImage, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestNetworkArrowImage, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(ui_SelftestNetworkArrowImage, LV_ALIGN_RIGHT_MID, -10, 0);
    lv_obj_add_flag(ui_SelftestNetworkArrowImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SelftestNetworkArrowImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    
    //wifi网络列表面板
    ui_SelftestNetworkListPanel = lv_obj_create(ui_SelftestNetworkMainpanel);;
    lv_obj_set_size(ui_SelftestNetworkListPanel, 640, 225);
    lv_obj_set_pos(ui_SelftestNetworkListPanel, 0, 60);
    lv_obj_set_align(ui_SelftestNetworkListPanel, LV_ALIGN_TOP_LEFT); 
    lv_obj_set_style_radius(ui_SelftestNetworkListPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkListPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkListPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestNetworkListPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SelftestNetworkListPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //Write codes settings_list_1

    //wifi列表
    int ui_PanelWiFiListY = 0;
    for(int i = 0;i < 20; i++)
    {
        selftestwifilist_array[i] = create_wifi_list_item(ui_SelftestNetworkListPanel, LV_ALIGN_TOP_LEFT, 10, ui_PanelWiFiListY);
        lv_obj_add_flag(selftestwifilist_array[i]->parent, LV_OBJ_FLAG_HIDDEN);
        ui_PanelWiFiListY += 56;
    }

    // ui_SelftestNetworkButton3 = lv_btn_create(ui_SelftestNetworkMainpanel);
    // lv_obj_set_width(ui_SelftestNetworkButton3, 120);
    // lv_obj_set_height(ui_SelftestNetworkButton3, 50);
    // lv_obj_set_x(ui_SelftestNetworkButton3, 660);
    // lv_obj_set_y(ui_SelftestNetworkButton3, 14);
    // lv_obj_align(ui_SelftestNetworkButton3, LV_ALIGN_TOP_RIGHT, -14, -14);
    // lv_obj_add_flag(ui_SelftestNetworkButton3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_SelftestNetworkButton3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_SelftestNetworkButton3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_SelftestNetworkButton3, lv_color_hex(0x28292D), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_SelftestNetworkButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_SelftestNetworkButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_SelftestNetworkButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SelftestNetworkBtnlabel3 = lv_label_create(ui_SelftestNetworkButton3);
    // lv_obj_set_width(ui_SelftestNetworkBtnlabel3, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_SelftestNetworkBtnlabel3, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_align(ui_SelftestNetworkBtnlabel3, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_SelftestNetworkBtnlabel3, JumpOver[language_index]);
    // lv_obj_set_style_text_color(ui_SelftestNetworkBtnlabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_SelftestNetworkBtnlabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_SelftestNetworkBtnlabel3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //网络键盘页面板
    ui_SelftestNetworkSettingPanel = lv_obj_create(ui_SelftestNetwork);
    lv_obj_set_size(ui_SelftestNetworkSettingPanel, 640, 360);
    lv_obj_set_pos(ui_SelftestNetworkSettingPanel, 0, 60);
    lv_obj_clear_flag(ui_SelftestNetworkSettingPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestNetworkSettingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkSettingPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkSettingPanel, 240, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SelftestNetworkSettingPanel, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SelftestNetworkSettingPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestNetworkSettingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_SelftestNetworkSettingPanel, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SelftestNetworkSettingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
     // wifi名显示区域
    ui_SelftestNetworkNamePanel = lv_obj_create(ui_SelftestNetworkSettingPanel);
    lv_obj_set_size(ui_SelftestNetworkNamePanel, 630, 56);
    lv_obj_set_pos(ui_SelftestNetworkNamePanel, 5, 8);
    lv_obj_set_style_radius(ui_SelftestNetworkNamePanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkNamePanel, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkNamePanel, 229, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SelftestNetworkNamePanel, lv_color_hex(0x888989), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SelftestNetworkNamePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestNetworkNamePanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_SelftestNetworkNamePanel, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SelftestNetworkNamePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_selftestnetworkNameLabel = lv_label_create(ui_SelftestNetworkNamePanel);
    lv_obj_set_width(ui_selftestnetworkNameLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_selftestnetworkNameLabel, LV_SIZE_CONTENT);
    lv_obj_align(ui_selftestnetworkNameLabel, LV_ALIGN_LEFT_MID, 10, 0);
    lv_label_set_text(ui_selftestnetworkNameLabel, "");
    lv_obj_set_style_text_color(ui_selftestnetworkNameLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_selftestnetworkNameLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_selftestnetworkNameLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_selftestnetworkNameLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_selftestnetworkNameLabel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_selftestnetworkNameLabel, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_selftestnetworkNameLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_selftestnetworkNameLabel, lv_color_hex(0x888989), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_selftestnetworkNameLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_selftestnetworkNameLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_selftestnetworkNameLabel, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //密码输入区域
    ui_Selftestnetwork_TextArea = lv_textarea_create(ui_SelftestNetworkSettingPanel);
    lv_obj_set_size(ui_Selftestnetwork_TextArea, 630, 56);
    lv_obj_set_pos(ui_Selftestnetwork_TextArea, 5, 71);
    lv_obj_set_style_bg_color(ui_Selftestnetwork_TextArea, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Selftestnetwork_TextArea, 229, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Selftestnetwork_TextArea, lv_color_hex(0x888989), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Selftestnetwork_TextArea, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Selftestnetwork_TextArea, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Selftestnetwork_TextArea, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Selftestnetwork_TextArea, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_textarea_set_placeholder_text(ui_Selftestnetwork_TextArea, InputPasswordMsg[language_index]);
    lv_obj_set_style_text_font(ui_Selftestnetwork_TextArea, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Selftestnetwork_TextArea, lv_color_hex(0x42BDD8), LV_PART_CURSOR | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_Selftestnetwork_TextArea, 255, LV_PART_CURSOR | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_Selftestnetwork_TextArea, 2, LV_PART_CURSOR | LV_STATE_FOCUSED);

    
    ui_SelftestNetworkKeyboardPanel = lv_textarea_create(ui_SelftestNetworkSettingPanel);
    lv_obj_set_size(ui_SelftestNetworkKeyboardPanel, 640, 220);
    lv_obj_clear_flag(ui_SelftestNetworkKeyboardPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_align(ui_SelftestNetworkKeyboardPanel, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_bg_color(ui_SelftestNetworkKeyboardPanel, lv_color_hex(0x393D44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworkKeyboardPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestNetworkKeyboardPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SelftestNetworkKeyboardPanel, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);

     //键盘样式设置
    ui_Selftestnetwork_Keyboard = lv_btnmatrix_create(ui_SelftestNetworkKeyboardPanel); //创建按钮矩阵（Button Matrix）对象
    lv_btnmatrix_set_map(ui_Selftestnetwork_Keyboard, kb_map[KEYBOARD_MODE_TEXT_LOWER]); //设置按钮矩阵的按钮标签映射
    lv_btnmatrix_set_ctrl_map(ui_Selftestnetwork_Keyboard, kb_ctrl[0]);
    // lv_btnmatrix_set_btn_width(ui_Selftestnetwork_Keyboard, 36, 4);//
    lv_obj_set_size(ui_Selftestnetwork_Keyboard, 644, 224); 
    lv_obj_set_style_text_font(ui_Selftestnetwork_Keyboard, lv_font25.font, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Selftestnetwork_Keyboard, lv_color_hex(0xFFFFFF), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Selftestnetwork_Keyboard, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Selftestnetwork_Keyboard, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Selftestnetwork_Keyboard, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Selftestnetwork_Keyboard, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Selftestnetwork_Keyboard, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_Selftestnetwork_Keyboard, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_center(ui_Selftestnetwork_Keyboard);

    //关闭网络键盘图标
    // ui_SelftestnetworkImage8 = lv_img_create(ui_SelftestNetworkSettingPanel);
    // lv_img_set_src(ui_SelftestnetworkImage8, &ui_img_group_12_png);
    // lv_obj_set_width(ui_SelftestnetworkImage8, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_SelftestnetworkImage8, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_SelftestnetworkImage8, 19);
    // lv_obj_set_y(ui_SelftestnetworkImage8, 21);
    // lv_obj_add_flag(ui_SelftestnetworkImage8, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_add_flag(ui_SelftestnetworkImage8, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    // lv_obj_clear_flag(ui_SelftestnetworkImage8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_ext_click_area(ui_SelftestnetworkImage8, 30);
    
      //网络连接文本
    // ui_Selftestnetwork_Label4 = lv_label_create(ui_SelftestNetworkSettingPanel);
    // lv_obj_set_width(ui_Selftestnetwork_Label4, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Selftestnetwork_Label4, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Selftestnetwork_Label4, 0);
    // lv_obj_set_y(ui_Selftestnetwork_Label4, 21);
    // lv_obj_set_align(ui_Selftestnetwork_Label4, LV_ALIGN_TOP_MID);
    // lv_label_set_text(ui_Selftestnetwork_Label4, NetworkConnect[language_index]);
    // lv_obj_set_style_text_color(ui_Selftestnetwork_Label4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_Selftestnetwork_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_Selftestnetwork_Label4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_Selftestnetwork_Label4, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_keyboard_set_textarea(ui_Selftestnetwork_Keyboard, ui_Selftestnetwork_TextArea);
    lv_obj_add_flag(ui_SelftestNetworkSettingPanel,LV_OBJ_FLAG_HIDDEN);
   // lv_obj_add_event_cb(ui_SelftestnetworkImage8, ui_event_SelftestnetworkImage8, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_Selftestnetwork_Keyboard, ui_event_Selftestnetwork_Keyboard, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestNetworkNextStepBtn, ui_event_SelftestNetworkNextStepBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestNetworkPrevStepBtn, ui_event_SelftestNetworkPrevStepBtn, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_SelftestNetworkButton3, ui_event_SelftestNetworkButton3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestNetwork, ui_event_SelftestNetwork, LV_EVENT_ALL, NULL);

    switch (UIType)
    {
        case CR_K1:     
                lv_obj_add_flag(ui_SelftesLocalNetworkPanel, LV_OBJ_FLAG_HIDDEN);     /// Flags
                lv_obj_set_x(ui_SelftestNetworkListPanel, 0);
                lv_obj_set_y(ui_SelftestNetworkListPanel, 60);
                break;
        case CR_K1_Max:
        case PF_05: 
                lv_obj_clear_flag(ui_SelftesLocalNetworkPanel, LV_OBJ_FLAG_HIDDEN);     /// Flags
                lv_obj_set_x(ui_SelftestNetworkListPanel, 0);
                lv_obj_set_y(ui_SelftestNetworkListPanel, 118);
                lv_obj_set_height(ui_SelftestNetworkListPanel, 172);//225
                break;
        default:
            break;
    }

}

/**
 * @description: 下一步页面加载处理
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_SelftestNetworkNextStepBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        //_ui_screen_change(ui_TimezoneSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        if (NetworkSetFlag == true)
        {
            NetworkSetFlag = false;
            return;
        }
        //TODO: 网络设置键盘密码输入确认后此处会重载，目前添加标志位，待排查
        LoadPage(ui_TimezoneSettings, 0);
    }
}

/**
 * @description: 上一步页面加载处理
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_SelftestNetworkPrevStepBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        // _ui_screen_change(ui_SelftestPrivacyPolicy, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        //_ui_screen_change(ui_changelanguage, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        LoadSelftestPrivacyPolicyPageAndObjs();
    }
}
void ui_event_SelftestNetworkButton3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
       // _ui_screen_change(ui_TimezoneSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        LoadPage(ui_TimezoneSettings, 0);
    }
}
/**
 * @description: wifi引导设置页加载功能处理
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_SelftestNetwork(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        selftest_network_flag = true;
        // char te[100];
        // snprintf(te,100,"%s\t%s\t%s","2MW315R:2","CXSW-guest:1","CXSW:0");
        // get_response_printer_data(0x07,30,te);
        get_printer_data(0x07,1,"1");
        get_printer_data(0x07,1,"2");//获取wifi的列表
        wait_animmotion(1);
        for(int k=0;k < 20;k++)
        {
            lv_obj_add_flag(selftestwifilist_array[k]->parent,LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(selftestwifilist_array[k]->wifi_info, LV_OBJ_FLAG_HIDDEN);
        }
          
    }
    if(event_code == LV_EVENT_SCREEN_UNLOADED) {
        selftest_network_flag = false;
    }
}

void ui_event_SelftestnetworkImage8(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_obj_add_flag(ui_SelftestNetworkSettingPanel,LV_OBJ_FLAG_HIDDEN);
    }
}
// //wifi处理事件
static void wifi_select_btn_ok_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(wifilist_state == 2)
            {
                char ctemp[WIFI_NAME_LEN+4] = "2\t";
                unsigned char i = 0;
                for(i=0;i<strlen(wifilist_name);i++)
                {
                    ctemp[i+2] = wifilist_name[i];
                }
                set_printer_data(0x07,strlen(ctemp),ctemp);
                get_printer_data(0x07, 1, "2");
                wifi_wait_animmotion(6);
                int ui_PanelWiFiListY = 0;
                for(int i = 0;i < 20; i++)
                {
                    selftestwifilist_array[i] = create_wifi_list_item(ui_SelftestNetworkListPanel, LV_ALIGN_TOP_LEFT, 10, ui_PanelWiFiListY);
                    lv_obj_add_flag(selftestwifilist_array[i]->parent, LV_OBJ_FLAG_HIDDEN);
                    ui_PanelWiFiListY += 56;
                }
            }
            else if(wifilist_state == 1)
            {
                char ctemp[WIFI_NAME_LEN+4] = "1\t";
                unsigned char i = 0;
                for(i=0;i<strlen(wifilist_name);i++)
                {
                    ctemp[i+2] = wifilist_name[i];
                }
                set_printer_data(0x07,strlen(ctemp),ctemp);
                get_printer_data(0x07, 1, "2");
                wifi_wait_animmotion(6);
                int ui_PanelWiFiListY = 94;  
                for(int i = 1; i < 20; i++)
                {
                    lv_obj_set_pos(selftestwifilist_array[i]->parent, 14, ui_PanelWiFiListY);    
                    ui_PanelWiFiListY += 60;
                }
            }
            lv_obj_add_flag(ui_SelftestDialog, LV_OBJ_FLAG_HIDDEN);
            //lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
           
            if (IsThereAnyPopout())
            {
                ManagePopoutFocus();
            }
            else
            {
                 LoadPage(ui_SelftestNetwork, 0);
            }
        }
            break;
        default:
            break;
	}
}

static void wifi_select_btn_cancel_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(wifilist_state == 1 || wifilist_state == 2)
            {
                char ctemp[WIFI_NAME_LEN+4] = "3\t";
                unsigned char i = 0;
                for(i=0; i<strlen(wifilist_name); i++)
                {
                    ctemp[i+2] = wifilist_name[i];
                }
                set_printer_data(0x07,strlen(ctemp),ctemp);
                get_printer_data(0x07, 1, "2");
                 wifi_wait_animmotion(6);
            }
             
            int ui_PanelWiFiListY = 0;
            for(int i = 0;i < 20; i++)
            {
                selftestwifilist_array[i] = create_wifi_list_item(ui_SelftestNetworkListPanel, LV_ALIGN_TOP_LEFT, 10, ui_PanelWiFiListY);
                lv_obj_add_flag(selftestwifilist_array[i]->parent, LV_OBJ_FLAG_HIDDEN);
                ui_PanelWiFiListY += 56;
            }
            CrLogI("wifi_select_btn_cancel_event_handler BackPrepage(true)");

            lv_obj_add_flag(ui_SelftestDialog, LV_OBJ_FLAG_HIDDEN);
            //lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
            if (IsThereAnyPopout())
            {
                ManagePopoutFocus();
            }
            else
            {
                BackPrepage(true);
            }

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
            CrLogI("hidden the msgbox,%p",ui_SelftestDialog);
            lv_obj_add_flag(ui_SelftestDialog, LV_OBJ_FLAG_HIDDEN);
            //lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
            CrLogI("wifi_select_btn_quit_event_handler BackPrepage(true)");
            DeinitPopoutManager(&BtnDialogPopout);
            if (IsThereAnyPopout())
            {
                ManagePopoutFocus();
            }
            else
            {
                BackPrepage(true);
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
            lv_obj_add_flag(ui_SelftestDialog, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
            // _ui_screen_change(ui_NetworkInfo, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        }
            break;
        default:
            break;
	}
}

static void wifi_dialog(unsigned char flag,lv_obj_t * obj)
{
    uint8_t language_index = get_cur_language_index();
  
    if (!IsThereAnyPopout())
    {
        RecordObjBeforePopup();
    }
    if (ui_SelftestDialog == NULL)
    {
        ui_SelftestDialog = lv_obj_create(ui_SelftestNetwork);
        //lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_size(ui_SelftestDialog, 640, 360);
        lv_obj_set_pos(ui_SelftestDialog, 0, 60);
        lv_obj_add_style(ui_SelftestDialog, &style_cont_msgbox, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_SelftestDialog, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_SelftestDialog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

        ui_SelftestDialogPanel = lv_obj_create(ui_SelftestDialog);
        lv_obj_set_size(ui_SelftestDialogPanel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        //lv_obj_align_to(ui_SelftestDialogPanel,obj,LV_ALIGN_OUT_BOTTOM_MID,0,0);
        lv_obj_align(ui_SelftestDialogPanel, LV_ALIGN_RIGHT_MID, -15, 0);
        lv_obj_set_style_radius(ui_SelftestDialogPanel, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_SelftestDialogPanel, lv_color_hex(0x3C3E42), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_SelftestDialogPanel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(ui_SelftestDialogPanel, lv_color_hex(0x494949), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_SelftestDialogPanel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_SelftestDialogPanel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_layout(ui_SelftestDialogPanel, LV_LAYOUT_FLEX);
        lv_obj_set_flex_flow(ui_SelftestDialogPanel, LV_FLEX_FLOW_COLUMN);

        //btn_1
        ui_SelftestDialog_btn_1 = lv_btn_create(ui_SelftestDialogPanel);
        lv_obj_set_size(ui_SelftestDialog_btn_1, 96, 56);
        lv_obj_set_style_radius(ui_SelftestDialog_btn_1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_SelftestDialog_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_style(ui_SelftestDialog_btn_1, &StyleDialogBtnDefault, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_add_style(ui_SelftestDialog_btn_1, &StyleDialogFocusBtn, LV_PART_MAIN|LV_STATE_FOCUS_KEY);
       
        ui_SelftestDialog_btn_1_label = lv_label_create(ui_SelftestDialog_btn_1);
        if(flag == 0)
            lv_label_set_text(ui_SelftestDialog_btn_1_label, DisconnectOptArray[language_index]);
        else
            lv_label_set_text(ui_SelftestDialog_btn_1_label, ConnectOptArray[language_index]);
        lv_obj_set_style_text_color(ui_SelftestDialog_btn_1_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_SelftestDialog_btn_1_label, lv_font24.font, LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_SelftestDialog_btn_1_label, 0, LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_SelftestDialog_btn_1_label, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT);
        lv_obj_align(ui_SelftestDialog_btn_1_label, LV_ALIGN_CENTER, 0, 0);

        //btn_2
        ui_SelftestDialog_btn_2 = lv_btn_create(ui_SelftestDialogPanel);
        lv_obj_set_size(ui_SelftestDialog_btn_2, 96, 56);
        lv_obj_set_style_shadow_width(ui_SelftestDialog_btn_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_SelftestDialog_btn_2, 0, LV_STATE_DEFAULT);
        lv_obj_add_style(ui_SelftestDialog_btn_2, &StyleDialogBtnDefault, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_add_style(ui_SelftestDialog_btn_2, &StyleDialogFocusBtn, LV_PART_MAIN|LV_STATE_FOCUS_KEY);
        
        ui_SelftestDialog_btn_2_label = lv_label_create(ui_SelftestDialog_btn_2);
        lv_label_set_text(ui_SelftestDialog_btn_2_label, ForgetPasswordArray[language_index]);
        lv_obj_set_style_text_color(ui_SelftestDialog_btn_2_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_SelftestDialog_btn_2_label, lv_font24.font, LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_SelftestDialog_btn_2_label, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT);
        lv_obj_align(ui_SelftestDialog_btn_2_label, LV_ALIGN_CENTER, 0, 0);


        //btn_3 取消按钮
        ui_SelftestDialog_btn_3 = lv_btn_create(ui_SelftestDialogPanel);
        lv_obj_set_size(ui_SelftestDialog_btn_3, 96, 56);
        lv_obj_set_style_shadow_width(ui_SelftestDialog_btn_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_SelftestDialog_btn_3, 0, LV_STATE_DEFAULT);
        lv_obj_add_style(ui_SelftestDialog_btn_3, &StyleDialogBtnDefault, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_add_style(ui_SelftestDialog_btn_3, &StyleDialogFocusBtn, LV_PART_MAIN|LV_STATE_FOCUS_KEY);
        
        ui_SelftestDialog_btn_3_label = lv_label_create(ui_SelftestDialog_btn_3);
        lv_label_set_text(ui_SelftestDialog_btn_3_label, Cancel[language_index]);
        lv_obj_set_style_text_color(ui_SelftestDialog_btn_3_label, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_SelftestDialog_btn_3_label, lv_font24.font, LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_SelftestDialog_btn_3_label, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT);
        lv_obj_align(ui_SelftestDialog_btn_3_label, LV_ALIGN_CENTER, 0, 0);
        // redefine_label_size(ui_NetworkDialog_btn_3_label, lv_font24.font, 0, 0, 240, 0);
        // lv_obj_update_layout(ui_NetworkDialog_btn_3_label);
        // redefine_widgets_size(ui_NetworkDialog_btn_3, ui_NetworkDialog_btn_3_label, 5, 0, 96, 60);  
        lv_obj_add_flag(ui_SelftestDialog,LV_OBJ_FLAG_HIDDEN);
    }

    if (lv_obj_has_flag(ui_SelftestDialog,LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(ui_SelftestDialog,LV_OBJ_FLAG_HIDDEN);

        if(flag == 0)
            lv_label_set_text(ui_SelftestDialog_btn_1_label, DisconnectOptArray[language_index]);
        else
            lv_label_set_text(ui_SelftestDialog_btn_1_label, ConnectOptArray[language_index]);
        
        redefine_label_size(ui_SelftestDialog_btn_1_label, lv_font24.font, 0, 0, 240, 0);
        lv_obj_update_layout(ui_SelftestDialog_btn_1_label);
        redefine_widgets_size(ui_SelftestDialog_btn_1, ui_SelftestDialog_btn_1_label, 10, 0, 96, 60);

        lv_label_set_text(ui_SelftestDialog_btn_2_label, ForgetPasswordArray[language_index]);
        redefine_label_size(ui_SelftestDialog_btn_2_label, lv_font24.font, 0, 0, 240, 0);
        lv_obj_update_layout(ui_SelftestDialog_btn_2_label);
        redefine_widgets_size(ui_SelftestDialog_btn_2, ui_SelftestDialog_btn_2_label, 10, 0, 96, 60);
        
        redefine_label_size(ui_SelftestDialog_btn_3_label, lv_font24.font, 0, 0, 240, 0);
        lv_obj_update_layout(ui_SelftestDialog_btn_3_label);
        redefine_widgets_size(ui_SelftestDialog_btn_3, ui_SelftestDialog_btn_3_label, 10, 0, 96, 60);
        lv_coord_t width  = lv_obj_get_width(ui_SelftestDialog_btn_1) > lv_obj_get_width(ui_SelftestDialog_btn_2) ? lv_obj_get_width(ui_SelftestDialog_btn_1) : lv_obj_get_width(ui_SelftestDialog_btn_2);
        lv_obj_set_width(ui_SelftestDialog_btn_1, width);
        lv_obj_set_width(ui_SelftestDialog_btn_2, width);
        lv_obj_set_width(ui_SelftestDialog_btn_3, width);
    }
    lv_obj_add_event_cb(ui_SelftestDialog_btn_1, wifi_select_btn_ok_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestDialog_btn_2, wifi_select_btn_cancel_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestDialog_btn_3, wifi_select_btn_quit_event_handler, LV_EVENT_ALL, NULL);
    
    InitPopoutManager(&BtnDialogPopout, ui_SelftestDialog, WifiSelftestDialogAddFocusObjs);
    BtnDialogPopout.obj1_flag = true;
    BtnDialogPopout.obj2_flag = true;
    BtnDialogPopout.obj3_flag = true;
    BtnDialogPopout.popout_focus_obj1 = ui_SelftestDialog_btn_1;
    BtnDialogPopout.popout_focus_obj2 = ui_SelftestDialog_btn_2;
    BtnDialogPopout.popout_focus_obj3 = ui_SelftestDialog_btn_3;
    // Add3rLeveldObjsCb = WifiDialogAddFocusObjs;
    // LoadPage(ui_ScreenSettings, 3);
    //弹框聚焦对象处理
    ManagePopoutFocus();
}

/**
 * @description: 键盘功能处理
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_Selftestnetwork_Keyboard(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
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
        CrLogI("keyboard input id: %d",id);
        
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
            char ctemp[WIFI_NAME_LEN+4+63] = "0\t";
            unsigned char i,j;
            for(i=0;i<strlen(wifilist_name);i++)
            {
                ctemp[i+2] = wifilist_name[i];
            }
            ctemp[i+2] = '\t';
            j = i + 3;
            const char *passw = lv_textarea_get_text(ui_Selftestnetwork_TextArea);
            if(passw != NULL)
            {
                for(i=0;i<strlen(passw);i++)
                {
                    ctemp[j++] = *(passw + i);
                }
                ctemp[j] = '\0';
                set_printer_data(0x07,strlen(ctemp),ctemp);
                get_printer_data(0x07, 1, "2");
                if((strlen(passw) < 8 && strlen(passw) != 0) || strlen(passw) > 64)
                {
                    create_msgbox(PasswordLenLimit[get_cur_language_index()], NULL, 1000, lv_scr_act());
                }
            }
            lv_group_set_editing(encoder_group, 0); //退出编辑模式
            wifi_wait_animmotion(6);
            NetworkSetFlag = true;
            lv_obj_add_flag(ui_SelftestNetworkSettingPanel, LV_OBJ_FLAG_HIDDEN);
            LoadPage(ui_SelftestNetwork, 0);
            
        }
        else
        {
            const char * txt = lv_btnmatrix_get_btn_text(target, id);
            lv_textarea_add_text(ui_Selftestnetwork_TextArea, txt);
        }

    }
}

/**
 * @description: wifi 
 * @return {*}
 * @param {lv_event_t} *e
 */
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
                case 2:
                    wifi_dialog(0,obj);
                    break;
                case 1:
                    wifi_dialog(1,obj);
                    break;
                case 0:
                {
                    keyboard_spec_flag = false;
                    lv_obj_clear_flag(ui_SelftestNetworkSettingPanel, LV_OBJ_FLAG_HIDDEN);
                    lv_label_set_text(ui_selftestnetworkNameLabel,wifilist_name);
                    lv_btnmatrix_set_map(ui_Selftestnetwork_Keyboard, kb_map[KEYBOARD_MODE_TEXT_LOWER]);
                    lv_obj_add_state(ui_Selftestnetwork_TextArea, LV_STATE_FOCUSED);
                    lv_textarea_set_text(ui_Selftestnetwork_TextArea,"");

                    lv_group_remove_all_objs(encoder_group);
                    lv_group_add_obj(encoder_group, ui_Selftestnetwork_Keyboard);
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
void selftest_show_wifi_list(char *data,int len)
{
    if(selftest_network_flag)
    {
        char dis_wifi_name[60];
        char wifi_type[10] = {0};
        char wifi_dis[10] = {0};
        unsigned char i = 0,j = 0,k = 0;

        CrLogI("get data : %s",data);
        char *temp = strtok(data,"\t");
        for(k=0;k < 20;k++) 
        {
            lv_obj_clear_flag(selftestwifilist_array[k]->parent, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(selftestwifilist_array[k]->wifi_info,LV_OBJ_FLAG_HIDDEN);
        }
            
        k = 0;
        while(temp)
        {
            CrLogI("single wifi data : %s,%d",temp,k);
            int result = sscanf(temp, "%[^:]:%[^:]:%[^:]",dis_wifi_name, wifi_type, wifi_dis);
            if( result < 3)
            {
                CrLogE("explain the wifi data error,result count:%d",result);
                return;
            }
            CrLogI("single wifi name : %s",dis_wifi_name);
            CrLogI("single wifi type : %s",wifi_type);
            CrLogI("single wifi dis : %s",wifi_dis);

            if(k >= 20) return;
            switch(wifi_type[0])
            {
            case '2':{ //当前使用的wifi连接
                lv_obj_align(selftestwifilist_array[k]->wifi_name,LV_ALIGN_TOP_LEFT, 11, 0);
                lv_obj_align_to(selftestwifilist_array[k]->wifi_info,selftestwifilist_array[k]->wifi_name,LV_ALIGN_OUT_BOTTOM_LEFT, 1, 18);

                lv_label_set_text(selftestwifilist_array[k]->wifi_name, dis_wifi_name);
                //lv_label_set_text(selftestwifilist_array[k]->wifi_info, wifi_ip);
                lv_obj_set_style_text_color(selftestwifilist_array[k]->wifi_name,lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_clear_flag(selftestwifilist_array[k]->wifi_state,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(selftestwifilist_array[k]->wifi_info,LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(selftestwifilist_array[k]->wifi_state,&ui_img_wificheckstate_png);
                lv_img_set_src(selftestwifilist_array[k]->wifi_logo,&ui_img_wifi_state_png);
                lv_obj_align_to(selftestwifilist_array[k]->wifi_state, selftestwifilist_array[k]->wifi_logo, LV_ALIGN_OUT_LEFT_MID,-18, -1);
                // lv_img_set_src(selftestwifilist_array[k]->wifi_info,&ui_img_wifi_info_png);
               
                //绑定事件
                selftestwifilist_array[k]->wifi_type = 2;
                lv_obj_add_event_cb(selftestwifilist_array[k]->parent, wifi_list_event_handler, LV_EVENT_CLICKED, selftestwifilist_array[k]);
                
                int ui_PanelWiFiListY = 94;  
                for(int i = 1; i < 20; i++)
                {
                    lv_obj_set_pos(selftestwifilist_array[i]->parent, 14, ui_PanelWiFiListY);    
                    ui_PanelWiFiListY += 60;
                }
                 lv_obj_clear_flag(selftestwifilist_array[k]->wifi_info, LV_OBJ_FLAG_HIDDEN);

                k++;
                break;
            }
            case '1':{ //连接过保存的wifi
                //设置wifi名字并更新相关图片
                lv_label_set_text(selftestwifilist_array[k]->wifi_name, dis_wifi_name);
                lv_obj_set_style_text_color(selftestwifilist_array[k]->wifi_name, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_clear_flag(selftestwifilist_array[k]->wifi_state, LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(selftestwifilist_array[k]->wifi_state,&ui_img_wifi_state_1_png);
                lv_img_set_src(selftestwifilist_array[k]->wifi_logo,&ui_img_wifi_state_png);
                // lv_img_set_src(selftestwifilist_array[k]->wifi_info,&ui_img_wifi_info_png);
                lv_obj_align_to(selftestwifilist_array[k]->wifi_state, selftestwifilist_array[k]->wifi_logo, LV_ALIGN_OUT_LEFT_MID,-18, -1);
                lv_obj_add_flag(selftestwifilist_array[k]->wifi_info,LV_OBJ_FLAG_HIDDEN);
                //绑定事件
                selftestwifilist_array[k]->wifi_type = 1;
                lv_obj_add_event_cb(selftestwifilist_array[k]->parent, wifi_list_event_handler, LV_EVENT_CLICKED, selftestwifilist_array[k]);
                k++;
                break;
            }
            case '0':{ //未连接过的wifi
                //设置wifi名字并更新相关图片
                lv_label_set_text(selftestwifilist_array[k]->wifi_name,dis_wifi_name);
                lv_obj_set_style_text_color(selftestwifilist_array[k]->wifi_name,lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_add_flag(selftestwifilist_array[k]->wifi_state,LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(selftestwifilist_array[k]->wifi_logo,&ui_img_wifi_state_png);
                // lv_img_set_src(selftestwifilist_array[k]->wifi_info,&ui_img_wifi_info_png);
                lv_obj_add_flag(selftestwifilist_array[k]->wifi_info,LV_OBJ_FLAG_HIDDEN);
                //绑定事件
                selftestwifilist_array[k]->wifi_type = 0;
                lv_obj_add_event_cb(selftestwifilist_array[k]->parent, wifi_list_event_handler, LV_EVENT_CLICKED, selftestwifilist_array[k]);
                k++;
                break;
            }
            default:
                break;
            }
            temp = strtok(NULL,"\t");
        }
        for(;k < 20;k++)
            lv_obj_add_flag(selftestwifilist_array[k]->parent,LV_OBJ_FLAG_HIDDEN);
    }
}

static wifi_list_t * create_wifi_list_item(lv_obj_t *parent, lv_align_t align_mode, lv_coord_t x, lv_coord_t y)
{
    wifi_list_t *part = (wifi_list_t *)lv_mem_alloc(sizeof(wifi_list_t));
    if ( !part )
        return NULL;

    lv_obj_t * listPanel = lv_obj_create(parent);
    lv_obj_set_width(listPanel, 614);
    lv_obj_set_height(listPanel, 56);
    lv_obj_align(listPanel, align_mode, x, y);
    lv_obj_clear_flag(listPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(listPanel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_set_style_radius(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(listPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(listPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(listPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(listPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(listPanel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(listPanel, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_width(listPanel, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(listPanel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(listPanel, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_pad_all(listPanel, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    part->parent = listPanel;

    lv_obj_t * list_text = lv_label_create(listPanel);
    lv_obj_set_width(list_text, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(list_text, LV_SIZE_CONTENT); /// 1
    lv_obj_align(list_text,LV_ALIGN_LEFT_MID, 11, -5);
    lv_label_set_text(list_text, "");
    lv_obj_set_style_text_color(list_text, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(list_text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(list_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(list_text, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->wifi_name = list_text;

    // lv_obj_t *list_img3 = lv_img_create(listPanel);
    // lv_obj_set_width(list_img3, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(list_img3, LV_SIZE_CONTENT);    /// 1
    // lv_obj_align(list_img3,LV_ALIGN_RIGHT_MID,-20,0);
    // lv_obj_add_flag(list_img3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_add_flag(list_img3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    // lv_obj_clear_flag(list_img3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_img_set_src(list_img3,&ui_img_state_normal_png);
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
    part->wifi_info = list_wifiinfo;

    lv_obj_t *list_img2 = lv_img_create(listPanel);
    lv_img_set_src(list_img2,&ui_img_wifi_state_png);
    lv_obj_set_width(list_img2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(list_img2, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(list_img2,LV_ALIGN_RIGHT_MID,-8,0);
    lv_obj_add_flag(list_img2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(list_img2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_align_to(list_img2, list_img3, LV_ALIGN_OUT_LEFT_MID,-20,0);
    part->wifi_logo = list_img2;

    lv_obj_t *list_img1 = lv_img_create(listPanel);
    lv_obj_set_width(list_img1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(list_img1, LV_SIZE_CONTENT);    /// 1
    lv_obj_add_flag(list_img1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(list_img1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(list_img1,&ui_img_wificheckstate_png);
    lv_obj_align_to(list_img1,list_img2,LV_ALIGN_OUT_LEFT_MID,-18,0);
    part->wifi_state = list_img1;

    return part;
}

void selftest_network_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_SelftestNetworktitle )
        lv_label_set_text(ui_SelftestNetworktitle, SettingNetwork[language_index]);
    
    if ( ui_SelftestNetworkBtnlabel1 )
        lv_label_set_text(ui_SelftestNetworkBtnlabel1, NextStep[language_index]);

    if ( ui_SelftestNetworkBtnlabel2 )
        lv_label_set_text(ui_SelftestNetworkBtnlabel2, PrevStep[language_index]);
        
    if ( ui_SelftestNetworkLabel1 )
        lv_label_set_text(ui_SelftestNetworkLabel1, LocalNetworkArray[language_index]);

    if ( ui_SelftestNetworkLabel2 )
        lv_label_set_text(ui_SelftestNetworkLabel2, UnConnectedArray[language_index]);
    
    // if ( ui_SelftestNetworkBtnlabel3 )
    //     lv_label_set_text(ui_SelftestNetworkBtnlabel3, JumpOver[language_index]);
    
    if ( ui_SelftestNetworktitle )
        lv_textarea_set_placeholder_text(ui_Selftestnetwork_TextArea, InputPasswordMsg[language_index]);
    
    // if ( ui_Selftestnetwork_Label4 )
    //     lv_label_set_text(ui_Selftestnetwork_Label4, NetworkConnect[language_index]);

    if ( ui_SelftestDialog_btn_2_label )
        lv_label_set_text(ui_SelftestDialog_btn_2_label, ForgetPasswordArray[language_index]);
    
    if ( ui_SelftestDialog_btn_3_label )
    {
        //char buff[30] = {0};
       // sprintf(buff, "IP%s", InfoArray[language_index]);
        lv_label_set_text(ui_SelftestDialog_btn_3_label, Cancel[language_index]);
    }

}

void refresh_selftestnetworkstate(bool connect_state)
{
    if(connect_state)
    {
        lv_label_set_text(ui_SelftestNetworkLabel2, ConnectedArray[get_cur_language_index()]);
    }
    else
    {
        lv_label_set_text(ui_SelftestNetworkLabel2, UnConnectedArray[get_cur_language_index()]);
    }
}


void refresh_selftestwifilist_page(char * wifi_ip,char * wifi_mac)
{
    if(wifi_ip != NULL)
    {
        CrLogI("refresh the selftest wifi ip:%s", wifi_ip);
        for(int i = 0; i < 20; i++)
        {
            if(selftestwifilist_array[i]->wifi_type == 2)//属于已连接wifi
            {
                lv_label_set_text(selftestwifilist_array[i]->wifi_info, wifi_ip);
                break;
            }
        }
    }   
}

void LoadSelftestNetworkScreen(void)
{
    _ui_screen_change(ui_SelftestNetwork, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}


static void WifiSelftestDialogAddFocusObjs(void)
{
    //lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    lv_group_remove_all_objs(encoder_group);
    lv_group_add_obj(encoder_group, ui_SelftestDialog_btn_1);
    lv_group_add_obj(encoder_group, ui_SelftestDialog_btn_2);
    lv_group_add_obj(encoder_group, ui_SelftestDialog_btn_3);
}

void SelftestNetworkSetPageAddFocusObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *selftest_node = find_page(ui_SelftestNetwork);
    selftest_node->nav_level = index;
    lv_group_add_obj(encoder_group, ui_SelftesLocalNetworkPanel);

    for(int i = 0;i < 20; i++)
    {
        lv_group_add_obj(encoder_group, selftestwifilist_array[i]->parent);
    }
    //lv_group_focus_obj(selftestwifilist_array[0]->parent);
       
    lv_group_add_obj(encoder_group, ui_SelftestNetworkPrevStepBtn);
    lv_group_add_obj(encoder_group, ui_SelftestNetworkNextStepBtn);
    
}