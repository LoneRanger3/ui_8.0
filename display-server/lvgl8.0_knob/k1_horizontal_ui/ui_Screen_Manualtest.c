#include "src/core/lv_obj.h"
#include "src/core/lv_obj_pos.h"
#include "src/core/lv_obj_style.h"
#include "src/widgets/lv_label.h"
#include "ui.h"
#include "mult_language.h"
#include <stdio.h>

lv_obj_t * ui_Manualtest;
static lv_obj_t * ui_PanelPageManualtest;
static lv_obj_t * ui_HomePageImage;
static lv_obj_t * ui_AxisMovPageImage;
static lv_obj_t * ui_FileManagePageImage;
static lv_obj_t * ui_SettingsPageImage;
static lv_obj_t * ui_ServePageImage;

lv_obj_t * ui_PanelManualtestOpt;
lv_obj_t * ui_PanelLineManualtest;

lv_obj_t * ui_ManualtestPanel4;
lv_obj_t * ui_ManualtestLabel2;
//lv_obj_t * ui_ManualtestButton1;
//lv_obj_t * ui_ManualtestBtnlabel1;
lv_obj_t * ui_ManualtestLabel1;
lv_obj_t * ui_ManualtestCheckbox1; // 振纹优化
lv_obj_t * ui_ManualtestCheckbox2; // 自动调平
lv_obj_t * ui_ManualtestCheckbox3; // 喷头PID校准(预留)
lv_obj_t * ui_ManualtestCheckbox4; // 热床PID校准(预留)
lv_obj_t * ui_ManualtestCheckbox5; // 振动补偿(预留)
lv_obj_t * ui_ManualtestCheckbox6; // 归位检测(预留)
lv_obj_t * ui_ManualtestCheckbox7; // 探头检测(预留)
lv_obj_t * ui_ManualtestCheckbox8; // 断料检测(预留)
lv_obj_t * ui_ManualtestCheckbox9; // 自动调平--
lv_obj_t * ui_ManualtestStartDetectBtn; //开始检测按钮
lv_obj_t * ui_ManualtestBtnlabel2;
lv_obj_t * ui_ManualtestBackButton;
//lv_obj_t * ui_ManualtestBtnlabel3;

static bool is_all_selected = false;

void ui_event_ManualtestButton1(lv_event_t * e);
void ui_event_ManualtestStartDetectBtn(lv_event_t * e);
void ui_event_ManualtestBackBtn(lv_event_t * e);
void ui_event_ui_ManualtestImage1(lv_event_t * e);
void ui_event_ui_ManualtestImage2(lv_event_t * e);
void ui_event_ui_ManualtestImage3(lv_event_t * e);
void ui_event_ui_ManualtestImage4(lv_event_t * e);
void ui_event_ui_ManualtestImage5(lv_event_t * e);
void ui_event_ui_Manualtest(lv_event_t * e);
void ui_event_Checkbox1(lv_event_t * e);
void ui_event_Checkbox2(lv_event_t * e);
void LoadManualtestScreen(void);
static void ManualtestPageChangeObjs(uint8_t index);

void ui_Manualtest_screen_init(void)
{
    ui_Manualtest = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Manualtest, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Manualtest, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Manualtest, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_Manualtest, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_Manualtest, ManualtestPageChangeObjs, LoadManualtestScreen);

    uint8_t language_index = get_cur_language_index();
    char buff[80] = {0};
    ui_PanelPageManualtest = lv_obj_create(ui_Manualtest);
    lv_obj_set_width(ui_PanelPageManualtest, 68);
    lv_obj_set_height(ui_PanelPageManualtest, 360);
    lv_obj_set_pos(ui_PanelPageManualtest, 0, 60);
    lv_obj_clear_flag(ui_PanelPageManualtest, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPageManualtest, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPageManualtest, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPageManualtest, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelPageManualtest, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelPageManualtest, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelPageManualtest, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelPageManualtest, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_HomePageImage = lv_img_create(ui_PanelPageManualtest);
    lv_img_set_src(ui_HomePageImage, &ui_img_pagehome_png);
    lv_obj_set_size(ui_HomePageImage, 68, 72);
    lv_obj_set_pos(ui_HomePageImage, 0, 0);
    lv_obj_add_flag(ui_HomePageImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_HomePageImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_HomePageImage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AxisMovPageImage = lv_img_create(ui_PanelPageManualtest);
    lv_img_set_src(ui_AxisMovPageImage, &ui_img_pagemove_png);
    lv_obj_set_size(ui_AxisMovPageImage, 68, 72);
    lv_obj_set_pos(ui_AxisMovPageImage, 0, 72);
    lv_obj_add_flag(ui_AxisMovPageImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_AxisMovPageImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_AxisMovPageImage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AxisMovPageImage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FileManagePageImage = lv_img_create(ui_PanelPageManualtest);
    lv_img_set_src(ui_FileManagePageImage, &ui_img_pagefilemanage_png);
    lv_obj_set_size(ui_FileManagePageImage, 68, 72);
    lv_obj_set_pos(ui_FileManagePageImage, 0, 144);
    lv_obj_add_flag(ui_FileManagePageImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_FileManagePageImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_FileManagePageImage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FileManagePageImage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsPageImage = lv_img_create(ui_PanelPageManualtest);
    lv_img_set_src(ui_SettingsPageImage, &ui_img_pagesettingselected_png);
    lv_obj_set_size(ui_SettingsPageImage, 68, 72);
    lv_obj_set_pos(ui_SettingsPageImage, 0, 216);
    lv_obj_add_flag(ui_SettingsPageImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SettingsPageImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SettingsPageImage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SettingsPageImage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ServePageImage = lv_img_create(ui_PanelPageManualtest);
    lv_img_set_src(ui_ServePageImage, &ui_img_pagereserve_png);
    lv_obj_set_size(ui_ServePageImage, 68, 72);
    lv_obj_set_pos(ui_ServePageImage, 0, 288);
    lv_obj_add_flag(ui_ServePageImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ServePageImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ServePageImage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ServePageImage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //
    ui_PanelManualtestOpt = lv_obj_create(ui_Manualtest);
    lv_obj_set_width(ui_PanelManualtestOpt, 556); 
    lv_obj_set_height(ui_PanelManualtestOpt, 344);
    lv_obj_set_x(ui_PanelManualtestOpt, 76);
    lv_obj_set_y(ui_PanelManualtestOpt, 68);
   // lv_obj_set_align(ui_PanelManualtestOpt, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelManualtestOpt, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelManualtestOpt, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelManualtestOpt, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelManualtestOpt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelManualtestOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelManualtestOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  // lv_obj_add_flag(ui_PanelManualtestOpt, LV_OBJ_FLAG_HIDDEN);

    // ui_ManualtestPanel4 = lv_obj_create(ui_Manualtest);
    // lv_obj_set_width(ui_ManualtestPanel4, 660);
    // lv_obj_set_height(ui_ManualtestPanel4, 65);
    // lv_obj_set_x(ui_ManualtestPanel4, 18);
    // lv_obj_set_y(ui_ManualtestPanel4, 2);
    // lv_obj_clear_flag(ui_ManualtestPanel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_ManualtestPanel4, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ManualtestPanel4, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ManualtestPanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_ManualtestPanel4, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_ManualtestPanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_ManualtestPanel4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_ManualtestPanel4, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_all(ui_ManualtestPanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //设备自检label
    ui_ManualtestLabel2 = lv_label_create(ui_PanelManualtestOpt);
    lv_obj_set_size(ui_ManualtestLabel2, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_ManualtestLabel2, 25, 5);
    //lv_obj_set_align(ui_ManualtestLabel2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_ManualtestLabel2, DeviceSelfTestArray[language_index]);//DetectionItemArray[language_index]
    lv_obj_set_style_text_align(ui_ManualtestLabel2, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ManualtestLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestLabel2, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelLineManualtest = lv_obj_create(ui_PanelManualtestOpt);
    lv_obj_set_size(ui_PanelLineManualtest, 543, 1);
    lv_obj_set_pos(ui_PanelLineManualtest, 7, 52);
    lv_obj_clear_flag(ui_PanelLineManualtest, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_PanelLineManualtest, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelLineManualtest, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelLineManualtest, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLineManualtest, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLineManualtest, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ManualtestButton1 = lv_btn_create(ui_PanelManualtestOpt);
    // lv_obj_set_size(ui_ManualtestButton1, 140, 52);
    // lv_obj_set_pos(ui_ManualtestButton1, 408, 284);
   
    // //lv_obj_set_align(ui_ManualtestButton1, LV_ALIGN_TOP_RIGHT);
    // lv_obj_add_flag(ui_ManualtestButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_ManualtestButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_ManualtestButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ManualtestButton1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ManualtestButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_ManualtestButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_ManualtestButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_color(ui_ManualtestButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ManualtestButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_ManualtestButton1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ManualtestBtnlabel1 = lv_label_create(ui_ManualtestButton1);
    // lv_obj_set_width(ui_ManualtestBtnlabel1, 300);   /// 1
    // lv_obj_set_height(ui_ManualtestBtnlabel1, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_align(ui_ManualtestBtnlabel1, LV_ALIGN_RIGHT_MID);
    // lv_label_set_text(ui_ManualtestBtnlabel1, SelectAll[language_index]);
    // lv_obj_set_style_text_color(ui_ManualtestBtnlabel1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ManualtestBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_ManualtestBtnlabel1, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_ManualtestBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_left(ui_ManualtestBtnlabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_right(ui_ManualtestBtnlabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_top(ui_ManualtestBtnlabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_bottom(ui_ManualtestBtnlabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestLabel1 = lv_label_create(ui_PanelManualtestOpt);
    lv_obj_set_size(ui_ManualtestLabel1, 500, 80);
    lv_obj_set_pos(ui_ManualtestLabel1, 25, 247);
    lv_obj_set_style_text_color(ui_ManualtestLabel1, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_align(ui_ManualtestLabel1, LV_ALIGN_TOP_LEFT, 0, 197);
    lv_label_set_long_mode(ui_ManualtestLabel1, LV_LABEL_LONG_WRAP);
    lv_label_set_recolor(ui_ManualtestLabel1, true); 
   // sprintf(buff, "#6A707D %s##42bdd8 11##6A707D %s.#", SelfTestTipsMsg[language_index], MinuteArray[language_index]); 
    lv_label_set_text(ui_ManualtestLabel1, SelfTestTipsMsg[language_index]);
    lv_obj_set_style_text_opa(ui_ManualtestLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestLabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ManualtestCheckbox1 = lv_checkbox_create(ui_PanelManualtestOpt);
    lv_checkbox_set_text(ui_ManualtestCheckbox1, TurnOnThroatFan[language_index]);
    lv_obj_set_width(ui_ManualtestCheckbox1, LV_SIZE_CONTENT); //300
    lv_obj_set_height(ui_ManualtestCheckbox1, LV_SIZE_CONTENT); //33
    lv_obj_set_x(ui_ManualtestCheckbox1, 25);
    lv_obj_set_y(ui_ManualtestCheckbox1, 73);
    lv_obj_clear_flag(ui_ManualtestCheckbox1, LV_OBJ_FLAG_SCROLLABLE);   
    lv_obj_add_flag(ui_ManualtestCheckbox1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox1, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox1, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox1, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    //选中后样式
    lv_obj_set_style_border_color(ui_ManualtestCheckbox1, lv_color_hex(0xB0F1FF),
                                    LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox1, 3, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ManualtestCheckbox1, 0, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ManualtestCheckbox1, lv_color_hex(0xB0F1FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ManualtestCheckbox1, lv_color_hex(0xB0F1FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
  //  lv_obj_set_style_outline_color(ui_ManualtestCheckbox1, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_opa(ui_ManualtestCheckbox1, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_pad_all(ui_ManualtestCheckbox1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ManualtestCheckbox1, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox2 = lv_checkbox_create(ui_PanelManualtestOpt);
    lv_checkbox_set_text(ui_ManualtestCheckbox2, TurnOnModelFan[language_index]);
    lv_obj_set_width(ui_ManualtestCheckbox2, LV_SIZE_CONTENT); //300
    lv_obj_set_height(ui_ManualtestCheckbox2, LV_SIZE_CONTENT);//33
    lv_obj_set_x(ui_ManualtestCheckbox2, 25);
    lv_obj_set_y(ui_ManualtestCheckbox2, 130);
    lv_obj_clear_flag(ui_ManualtestCheckbox2, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui_ManualtestCheckbox2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox2, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox2, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox2, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox2, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_border_color(ui_ManualtestCheckbox2, lv_color_hex(0xB0F1FF),
                                    LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox2, 3, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ManualtestCheckbox2, 0, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ManualtestCheckbox2, lv_color_hex(0xB0F1FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ManualtestCheckbox2, lv_color_hex(0xB0F1FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
  //  lv_obj_set_style_outline_color(v, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_opa(ui_ManualtestCheckbox2, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_pad_all(ui_ManualtestCheckbox2, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ManualtestCheckbox2, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox3 = lv_checkbox_create(ui_PanelManualtestOpt);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s%s", HotendArray[language_index], PIDAdjustment[language_index]);
    lv_checkbox_set_text(ui_ManualtestCheckbox3, buff); 
    lv_obj_set_width(ui_ManualtestCheckbox3, 240);
    lv_obj_set_height(ui_ManualtestCheckbox3, 33);
    lv_obj_set_x(ui_ManualtestCheckbox3, 36);
    lv_obj_set_y(ui_ManualtestCheckbox3, 205);
    lv_obj_add_flag(ui_ManualtestCheckbox3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox3, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox3, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox3, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox3, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox4 = lv_checkbox_create(ui_PanelManualtestOpt);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s%s", BedArray[language_index], PIDAdjustment[language_index]);
    lv_checkbox_set_text(ui_ManualtestCheckbox4, buff);
    lv_obj_set_width(ui_ManualtestCheckbox4, 240);
    lv_obj_set_height(ui_ManualtestCheckbox4, 33);
    lv_obj_set_x(ui_ManualtestCheckbox4, 36);
    lv_obj_set_y(ui_ManualtestCheckbox4, 261);
    lv_obj_add_flag(ui_ManualtestCheckbox4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox4, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox4, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox4, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox4, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox5 = lv_checkbox_create(ui_PanelManualtestOpt);
    lv_checkbox_set_text(ui_ManualtestCheckbox5, VibrationCompensation[language_index]); 
    lv_obj_set_width(ui_ManualtestCheckbox5, 340);
    lv_obj_set_height(ui_ManualtestCheckbox5, 33);
    lv_obj_set_x(ui_ManualtestCheckbox5, 36);
    lv_obj_set_y(ui_ManualtestCheckbox5, 316);
    lv_obj_add_flag(ui_ManualtestCheckbox5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox5, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox5, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox5, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox5, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox5, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox5, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox5, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox5, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox5, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox5, 4, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox5, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox5, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox5, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox6 = lv_checkbox_create(ui_PanelManualtestOpt);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s%s", HomeArray[language_index], Detection[language_index]);
    lv_checkbox_set_text(ui_ManualtestCheckbox6, buff);
    lv_obj_set_width(ui_ManualtestCheckbox6, 240);
    lv_obj_set_height(ui_ManualtestCheckbox6, 33);
    lv_obj_set_x(ui_ManualtestCheckbox6, 430);
    lv_obj_set_y(ui_ManualtestCheckbox6, 96);
    lv_obj_add_flag(ui_ManualtestCheckbox6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox6, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox6, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox6, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox6, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox6, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox6, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox6, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox6, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox6, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox6, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox6, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox7 = lv_checkbox_create(ui_PanelManualtestOpt);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s%s", ProbeArray[language_index], Detection[language_index]);
    lv_checkbox_set_text(ui_ManualtestCheckbox7, buff);
    lv_obj_set_width(ui_ManualtestCheckbox7, 240);
    lv_obj_set_height(ui_ManualtestCheckbox7, 33);
    lv_obj_set_x(ui_ManualtestCheckbox7, 430);
    lv_obj_set_y(ui_ManualtestCheckbox7, 149);
    lv_obj_add_flag(ui_ManualtestCheckbox7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox7, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox7, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox7, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox7, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox7, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox7, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox7, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox7, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox7, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox7, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox7, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox8 = lv_checkbox_create(ui_PanelManualtestOpt);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s%s", RunoutArray[language_index], Detection[language_index]);
    lv_checkbox_set_text(ui_ManualtestCheckbox8, buff);
    lv_obj_set_width(ui_ManualtestCheckbox8, 240);
    lv_obj_set_height(ui_ManualtestCheckbox8, 33);
    lv_obj_set_x(ui_ManualtestCheckbox8, 430);
    lv_obj_set_y(ui_ManualtestCheckbox8, 205);
    lv_obj_add_flag(ui_ManualtestCheckbox8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox8, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox8, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox8, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox8, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox8, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox8, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox8, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox8, 3, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox8, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox8, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox8, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_ManualtestCheckbox9 = lv_checkbox_create(ui_PanelManualtestOpt);
    lv_checkbox_set_text(ui_ManualtestCheckbox9, AutoLevel[language_index]);
    lv_obj_set_width(ui_ManualtestCheckbox9, 240);
    lv_obj_set_height(ui_ManualtestCheckbox9, 33);
    lv_obj_set_x(ui_ManualtestCheckbox9, 430);
    lv_obj_set_y(ui_ManualtestCheckbox9, 261);
    lv_obj_add_flag(ui_ManualtestCheckbox9, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_ManualtestCheckbox9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestCheckbox9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestCheckbox9, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ManualtestCheckbox9, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox9, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox9, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox9, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox9, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox9, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestCheckbox9, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_ManualtestCheckbox9, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_ManualtestCheckbox9, 4, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_ManualtestCheckbox9, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_ManualtestCheckbox9, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ManualtestCheckbox9, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    
    //开始检测按钮
    ui_ManualtestStartDetectBtn = lv_btn_create(ui_PanelManualtestOpt);
    lv_obj_set_size(ui_ManualtestStartDetectBtn, 176, 52);
   // lv_obj_set_pos(ui_ManualtestStartDetectBtn, 372, 280);
    lv_obj_align(ui_ManualtestStartDetectBtn, LV_ALIGN_BOTTOM_RIGHT, -8, -12);
    lv_obj_add_flag(ui_ManualtestStartDetectBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ManualtestStartDetectBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestStartDetectBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestStartDetectBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestStartDetectBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ManualtestStartDetectBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ManualtestStartDetectBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ManualtestStartDetectBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestStartDetectBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestStartDetectBtn, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_ManualtestStartDetectBtn, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ManualtestStartDetectBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ManualtestStartDetectBtn, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ManualtestStartDetectBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ManualtestStartDetectBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ManualtestStartDetectBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    ui_ManualtestBtnlabel2 = lv_label_create(ui_ManualtestStartDetectBtn);
    lv_obj_set_width(ui_ManualtestBtnlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ManualtestBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ManualtestBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ManualtestBtnlabel2, StartDetection[language_index]);
    lv_label_set_long_mode(ui_ManualtestBtnlabel2, LV_LABEL_LONG_SCROLL_CIRCULAR);//设置长文本模式
    lv_obj_set_style_text_color(ui_ManualtestBtnlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ManualtestBtnlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ManualtestBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //返回按钮
    ui_ManualtestBackButton = lv_btn_create(ui_PanelManualtestOpt);
    lv_obj_set_size(ui_ManualtestBackButton, 68, 38);
    lv_obj_set_pos(ui_ManualtestBackButton, 474, 6);
    lv_obj_add_flag(ui_ManualtestBackButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ManualtestBackButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ManualtestBackButton, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ManualtestBackButton, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ManualtestBackButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestBackButton, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ManualtestBackButton, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ManualtestBackButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ManualtestBackButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ManualtestBackButton, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ManualtestBackButton, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ManualtestBackButton, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ManualtestBackButton, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ManualtestBackButton, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ManualtestBackButton, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ManualtestBackButton, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    // ui_ManualtestBtnlabel3 = lv_label_create(ui_ManualtestBackButton);
    // lv_obj_set_width(ui_ManualtestBtnlabel3, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_ManualtestBtnlabel3, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_align(ui_ManualtestBtnlabel3, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_ManualtestBtnlabel3, Back[language_index]);
    // lv_obj_set_style_text_color(ui_ManualtestBtnlabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ManualtestBtnlabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_ManualtestBtnlabel3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_flag(ui_HomePageImage, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_AxisMovPageImage, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_FileManagePageImage, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_SettingsPageImage, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_ServePageImage, LV_OBJ_FLAG_CLICKABLE);     /// Flags

   // lv_obj_add_event_cb(ui_ManualtestButton1, ui_event_ManualtestButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ManualtestStartDetectBtn, ui_event_ManualtestStartDetectBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ManualtestBackButton, ui_event_ManualtestBackBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_HomePageImage, ui_event_ui_ManualtestImage1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AxisMovPageImage, ui_event_ui_ManualtestImage2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FileManagePageImage, ui_event_ui_ManualtestImage3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingsPageImage, ui_event_ui_ManualtestImage4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ServePageImage, ui_event_ui_ManualtestImage5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Manualtest, ui_event_ui_Manualtest, LV_EVENT_ALL, NULL);


    lv_obj_add_event_cb(ui_ManualtestCheckbox1, ui_event_Checkbox1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ManualtestCheckbox2, ui_event_Checkbox2, LV_EVENT_ALL, NULL);

}

// void ui_event_ManualtestButton1(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         send_buzzer(0x01);
//         uint8_t index = get_cur_language_index();

//         if( !is_all_selected )
//         {
//             lv_obj_add_state(ui_ManualtestCheckbox1, LV_STATE_CHECKED);
//             lv_obj_add_state(ui_ManualtestCheckbox2, LV_STATE_CHECKED);
//             lv_obj_add_state(ui_ManualtestCheckbox3, LV_STATE_CHECKED);
//             lv_obj_add_state(ui_ManualtestCheckbox4, LV_STATE_CHECKED);
//             lv_obj_add_state(ui_ManualtestCheckbox5, LV_STATE_CHECKED);
//             lv_obj_add_state(ui_ManualtestCheckbox6, LV_STATE_CHECKED);
//             lv_obj_add_state(ui_ManualtestCheckbox7, LV_STATE_CHECKED);
//             lv_obj_add_state(ui_ManualtestCheckbox8, LV_STATE_CHECKED);
//             lv_obj_add_state(ui_ManualtestCheckbox9, LV_STATE_CHECKED);
//           //  lv_label_set_text(ui_ManualtestBtnlabel1,NotSelectAll[index]);
//             is_all_selected = true;
//             return ;
//         }
//         else
//         {
//             lv_obj_clear_state(ui_ManualtestCheckbox1, LV_STATE_CHECKED);
//             lv_obj_clear_state(ui_ManualtestCheckbox2, LV_STATE_CHECKED);
//             lv_obj_clear_state(ui_ManualtestCheckbox3, LV_STATE_CHECKED);
//             lv_obj_clear_state(ui_ManualtestCheckbox4, LV_STATE_CHECKED);
//             lv_obj_clear_state(ui_ManualtestCheckbox5, LV_STATE_CHECKED);
//             lv_obj_clear_state(ui_ManualtestCheckbox6, LV_STATE_CHECKED);
//             lv_obj_clear_state(ui_ManualtestCheckbox7, LV_STATE_CHECKED);
//             lv_obj_clear_state(ui_ManualtestCheckbox8, LV_STATE_CHECKED);
//             lv_obj_clear_state(ui_ManualtestCheckbox9, LV_STATE_CHECKED);
//            // lv_label_set_text(ui_ManualtestBtnlabel1, SelectAll[get_cur_language_index()]);
//             is_all_selected = false;
//         }
//     }
// }

void ui_event_ManualtestStartDetectBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if(print_state != 1)
        {
            CrLogI("manualtest page:machine state is print %d,don't start the print",print_state);
            create_msgbox(PrintingTips[get_cur_language_index()], NULL, 1000, lv_scr_act());
            return;
        }
        else
        {
            CrLogI("manualtest page:machine state is print %d,start the manualtest",print_state);
            manualtestcount = 100;
            if(lv_obj_has_state(ui_ManualtestCheckbox1,LV_STATE_CHECKED))  //振纹优化
            {
                manualtestcount += 10;
            }
            if(lv_obj_has_state(ui_ManualtestCheckbox2,LV_STATE_CHECKED))  //自动调平
            {
                manualtestcount += 1;
            }
            if(manualtestcount != 100)
            {
                LoadPage(ui_SelftestAll, 1);
                //_ui_screen_change(ui_SelftestAll, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            }
                
        }
        // int i = 0;
        // if(lv_obj_has_state(ui_ManualtestCheckbox1,LV_STATE_CHECKED))  //喉管风扇
        //     Manualtest[i++] = 1;
        // if(lv_obj_has_state(ui_ManualtestCheckbox2,LV_STATE_CHECKED))  //模型风扇
        //     Manualtest[i++] = 2;
        // // if(lv_obj_has_state(ui_ManualtestCheckbox3,LV_STATE_CHECKED))  //喷头PID
        // //     Manualtest[i++] = 3;
        // // if(lv_obj_has_state(ui_ManualtestCheckbox4,LV_STATE_CHECKED))  //热床PID
        // // //     Manualtest[i++] = 4;
        // // if(lv_obj_has_state(ui_ManualtestCheckbox5,LV_STATE_CHECKED))  //振动补偿
        // //     Manualtest[i++] = 5;
        // // if(lv_obj_has_state(ui_ManualtestCheckbox6,LV_STATE_CHECKED))  //归位检测
        // //     Manualtest[i++] = 6;
        // // // if(lv_obj_has_state(ui_ManualtestCheckbox8,LV_STATE_CHECKED))  //断料检测
        // // //     Manualtest[i++] = 7;
        // // if(lv_obj_has_state(ui_ManualtestCheckbox9,LV_STATE_CHECKED))  //自动调平
        // // {
        // //     // Manualtest[i++] = 8;
        // //     Manualtest[i++] = 9;
        // // }
        // Manualtest[i] = '\0';
        // Manualtestlength = i;
        // //决定跳转页面
        // if(Manualtestlength > 0)
        // {
        //     Manualtest_curpage = 0;
        //     change_manualtest_page(Manualtest[Manualtest_curpage]);
        // }

    }
}

void ui_event_ManualtestBackBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        BackPrepage(false);
       // _ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_ui_ManualtestImage1(lv_event_t * e)
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
void ui_event_ui_ManualtestImage2(lv_event_t * e)
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
void ui_event_ui_ManualtestImage3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadFileManageScreen();
    }
}
void ui_event_ui_ManualtestImage4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_ui_ManualtestImage5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadCustomerServiceScreen();
    }
}

void ui_event_ui_Manualtest(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        // lv_obj_add_flag(ui_ManualtestCheckbox1,LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(ui_ManualtestCheckbox2,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox3,LV_OBJ_FLAG_HIDDEN);

        lv_obj_add_flag(ui_ManualtestCheckbox4,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox5,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox6,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox7,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox8,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ManualtestCheckbox9,LV_OBJ_FLAG_HIDDEN);

        char buff[80]; 
        uint8_t index = get_cur_language_index();
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s%s", HomeArray[index], Detection[index]);
        // lv_checkbox_set_text(ui_ManualtestCheckbox1, buff);
        lv_checkbox_set_text(ui_ManualtestCheckbox1, VibrationOptimization[index]);
        lv_checkbox_set_text(ui_ManualtestCheckbox2, AutoLevel[index]);
    }
}


void ui_event_Checkbox1(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        lv_group_set_editing(encoder_group, false);
    }

}

void ui_event_Checkbox2(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        lv_group_set_editing(encoder_group, false);
    }

}

void manual_test_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    char buff[200] = {0};
    if ( ui_ManualtestLabel2 )
    lv_label_set_text(ui_ManualtestLabel2, DeviceSelfTestArray[language_index]); //DetectionItemArray

    // if ( ui_ManualtestBtnlabel1 )
    // lv_label_set_text(ui_ManualtestBtnlabel1, SelectAll[language_index]);

    if ( ui_ManualtestLabel1 )
    {
        if (language_index == 0)
            lv_obj_set_y(ui_ManualtestLabel1, 247);
        else
            lv_obj_set_y(ui_ManualtestLabel1, 210);
      //  sprintf(buff, "#6A707D %s##42bdd8 15##6A707D %s.#", SelfTestTipsMsg[language_index], MinuteArray[language_index]); 
        lv_label_set_text(ui_ManualtestLabel1, SelfTestTipsMsg[language_index]);
    }

    if ( ui_ManualtestCheckbox1 )
        lv_checkbox_set_text(ui_ManualtestCheckbox1, VibrationOptimization[language_index]);

    if ( ui_ManualtestCheckbox2 )
        lv_checkbox_set_text(ui_ManualtestCheckbox2, AutoLevel[language_index]);

    // if ( ui_ManualtestCheckbox3 )
    // {
    //     memset(buff, 0, sizeof(buff));
    //     sprintf(buff, "%s%s", HotendArray[language_index], PIDAdjustment[language_index]);
    //     lv_checkbox_set_text(ui_ManualtestCheckbox3, buff); 
    // }

    // if ( ui_ManualtestCheckbox4 )
    // {
    //     memset(buff, 0, sizeof(buff));
    //     sprintf(buff, "%s%s", BedArray[language_index], PIDAdjustment[language_index]);
    //     lv_checkbox_set_text(ui_ManualtestCheckbox4, buff);
    // }


    // if ( ui_ManualtestCheckbox5 )
    //     lv_checkbox_set_text(ui_ManualtestCheckbox5, VibrationCompensation[language_index]); 

    // if ( ui_ManualtestCheckbox6 )
    // {
    //     memset(buff, 0, sizeof(buff));
    //     sprintf(buff, "%s%s", HomeArray[language_index], Detection[language_index]);
    //     lv_checkbox_set_text(ui_ManualtestCheckbox6, buff);
    // }


    // if ( ui_ManualtestCheckbox7 )
    // {
    //     memset(buff, 0, sizeof(buff));
    //     sprintf(buff, "%s%s", ProbeArray[language_index], Detection[language_index]);
    //     lv_checkbox_set_text(ui_ManualtestCheckbox7, buff);
    // }


    // if ( ui_ManualtestCheckbox8 )
    // {
    //     memset(buff, 0, sizeof(buff));
    //     sprintf(buff, "%s%s", RunoutArray[language_index], Detection[language_index]);
    //     lv_checkbox_set_text(ui_ManualtestCheckbox8, buff);
    // }

    // if ( ui_ManualtestCheckbox9 )
    //     lv_checkbox_set_text(ui_ManualtestCheckbox9, AutoLevel[language_index]);

    if ( ui_ManualtestBtnlabel2 )
    {
        lv_label_set_text(ui_ManualtestBtnlabel2, StartDetection[language_index]);
        lv_obj_update_layout(ui_ManualtestStartDetectBtn);
        redefine_widgets_size(ui_ManualtestStartDetectBtn, ui_ManualtestBtnlabel2, 10, 0, 116, 60);
    }
        

    // if ( ui_ManualtestBtnlabel3 )
    //     lv_label_set_text(ui_ManualtestBtnlabel3, Back[language_index]);

    // if ( !ui_ManualtestBtnlabel1 )
    //     return ;

    // if ( is_all_selected )
    // {
    //     lv_label_set_text(ui_ManualtestBtnlabel1,NotSelectAll[language_index]);
    // }
    // else
    //     lv_label_set_text(ui_ManualtestBtnlabel1,SelectAll[language_index]);
}


void LoadManualtestScreen(void)
{
    _ui_screen_change(ui_Manualtest, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

static void ManualtestPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    // lv_indev_set_group(enc_indev, NULL); 
    // lv_indev_set_group(enc_indev, encoder_group); //关联组
    PageNode *Manualtest_node = find_page(ui_Manualtest);
    Manualtest_node->nav_level = index;

    
    switch (index)
    {
    case 1:
        lv_group_add_obj(encoder_group, ui_ManualtestBackButton);
        lv_group_add_obj(encoder_group, ui_ManualtestCheckbox1);
        lv_group_add_obj(encoder_group, ui_ManualtestCheckbox2);
        lv_group_add_obj(encoder_group, ui_ManualtestStartDetectBtn);
        break;
    default:
        break;
    }
 
}