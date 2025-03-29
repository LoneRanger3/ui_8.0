/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-01 14:54:52
 * @LastEditTime: 2023-10-23 02:15:15
 */
#include "k1_horizontal_ui/ui_screen_HomePrinting.h"
#include "src/core/lv_obj_pos.h"
#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "mult_language.h"

lv_obj_t * ui_ResetMachine;
lv_obj_t * ui_ResetMachineLeftPanel;
lv_obj_t * ui_homeimg1;
lv_obj_t * ui_axismoveimg1;
lv_obj_t * ui_fileimg1;
lv_obj_t * ui_settingsimg1;
lv_obj_t * ui_faqimg1;
static lv_obj_t * ui_ResetMachinePanel; 
static lv_obj_t * ui_ResetMachineTitle;
static lv_obj_t * ui_ResetMachineBackBtn;
static lv_obj_t * ui_ResetMachineDividlLine;
static lv_obj_t * ui_CleanItemLabel;


static lv_obj_t * ui_resetCheckbox1;
static lv_obj_t * ui_resetCheckbox2;
static lv_obj_t * ui_resetCheckbox3;
static lv_obj_t * ui_resetCheckbox4;
static lv_obj_t * ui_ResetMachineBtn;
static lv_obj_t * ui_ResetMachineBtnLabel;

void ui_event_ResetMachineCheckbox(lv_event_t * e);
void ui_event_ResetMachineBackBtn(lv_event_t * e);
void ui_event_ResetMachineBtn(lv_event_t * e);
void ui_event_resetmachinehomeimg1(lv_event_t * e);
void ui_event_resetmachineaxismoveimg1(lv_event_t * e);
void ui_event_resetmachinefileimg1(lv_event_t * e);
void ui_event_resetmachinesettingsimg1(lv_event_t * e);
void ui_event_resetmachinefaqimg1(lv_event_t * e);
void ui_event_ResetMachine(lv_event_t * e);
static void ResetMachinePageChangeObjs(uint8_t index);
void LoadResetMachineScreen(void);

void ui_ResetMachine_screen_init(void)
{
    ui_ResetMachine = lv_obj_create(NULL);
     lv_obj_set_style_bg_color(ui_ResetMachine, lv_color_hex(0x000000),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_ResetMachine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    
    init_pages(ui_ResetMachine, ResetMachinePageChangeObjs, LoadResetMachineScreen);

    uint8_t language_index = get_cur_language_index();
    ui_ResetMachineLeftPanel = lv_obj_create(ui_ResetMachine);
    lv_obj_set_width(ui_ResetMachineLeftPanel, 68);
    lv_obj_set_height(ui_ResetMachineLeftPanel, 360);
    lv_obj_set_pos(ui_ResetMachineLeftPanel, 0, 60);
    lv_obj_clear_flag(ui_ResetMachineLeftPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ResetMachineLeftPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ResetMachineLeftPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ResetMachineLeftPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ResetMachineLeftPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ResetMachineLeftPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ResetMachineLeftPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ResetMachineLeftPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
 
    ui_homeimg1 = lv_img_create(ui_ResetMachineLeftPanel);
    lv_img_set_src(ui_homeimg1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_homeimg1, 68);
    lv_obj_set_height(ui_homeimg1, 72);
    lv_obj_set_pos(ui_homeimg1, 0, 0);
    lv_obj_add_flag(ui_homeimg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_homeimg1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_homeimg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_homeimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_axismoveimg1 = lv_img_create(ui_ResetMachineLeftPanel);
    lv_img_set_src(ui_axismoveimg1, &ui_img_pagemove_png);
    lv_obj_set_width(ui_axismoveimg1, 68);
    lv_obj_set_height(ui_axismoveimg1, 72);
    lv_obj_set_x(ui_axismoveimg1, 0);
    lv_obj_set_y(ui_axismoveimg1, 72);
    lv_obj_add_flag(ui_axismoveimg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_axismoveimg1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_axismoveimg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_axismoveimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_axismoveimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_fileimg1 = lv_img_create(ui_ResetMachineLeftPanel);
    lv_img_set_src(ui_fileimg1, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_fileimg1, 68);
    lv_obj_set_height(ui_fileimg1, 72);
    lv_obj_set_x(ui_fileimg1, 0);
    lv_obj_set_y(ui_fileimg1, 144);
    lv_obj_add_flag(ui_fileimg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_fileimg1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_fileimg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_fileimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_fileimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingsimg1 = lv_img_create(ui_ResetMachineLeftPanel);
    lv_img_set_src(ui_settingsimg1, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_settingsimg1, 68);
    lv_obj_set_height(ui_settingsimg1, 72);
    lv_obj_set_x(ui_settingsimg1, 0);
    lv_obj_set_y(ui_settingsimg1, 216);
    lv_obj_add_flag(ui_settingsimg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_settingsimg1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_settingsimg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_settingsimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_settingsimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_faqimg1 = lv_img_create(ui_ResetMachineLeftPanel);
    lv_img_set_src(ui_faqimg1, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_faqimg1, 68);
    lv_obj_set_height(ui_faqimg1, 72);
    lv_obj_set_x(ui_faqimg1, 0);
    lv_obj_set_y(ui_faqimg1, 288);
    lv_obj_add_flag(ui_faqimg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(ui_faqimg1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_faqimg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_faqimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_faqimg1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_ResetMachinePanel = lv_obj_create(ui_ResetMachine);
    lv_obj_set_pos(ui_ResetMachinePanel, 76, 68);
    lv_obj_set_size(ui_ResetMachinePanel, 556, 344);
    lv_obj_set_align(ui_ResetMachinePanel, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_ResetMachinePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ResetMachinePanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ResetMachinePanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ResetMachinePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ResetMachinePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ResetMachinePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    

    ui_ResetMachineTitle = lv_label_create(ui_ResetMachinePanel);
    lv_obj_set_size(ui_ResetMachineTitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_ResetMachineTitle, 16, 0);//
    lv_label_set_text(ui_ResetMachineTitle, ResetMachine[language_index]);//DetectionItemArray[language_index]
    lv_obj_set_style_text_align(ui_ResetMachineTitle, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ResetMachineTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ResetMachineTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ResetMachineTitle, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //上下分割线
    ui_ResetMachineDividlLine = lv_obj_create(ui_ResetMachinePanel);
    lv_obj_set_size(ui_ResetMachineDividlLine, 543, 1);
    lv_obj_set_pos(ui_ResetMachineDividlLine, 7, 49);
    lv_obj_clear_flag(ui_ResetMachineDividlLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_ResetMachineDividlLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ResetMachineDividlLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ResetMachineDividlLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ResetMachineDividlLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ResetMachineDividlLine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CleanItemLabel = lv_label_create(ui_ResetMachinePanel);
    lv_obj_set_width(ui_CleanItemLabel, 500);
    lv_obj_set_height(ui_CleanItemLabel, 28);
    lv_obj_set_x(ui_CleanItemLabel, 16);
    lv_obj_set_y(ui_CleanItemLabel, 63);
    lv_label_set_text(ui_CleanItemLabel, CleanItemArray[language_index]);
    lv_obj_set_style_text_color(ui_CleanItemLabel, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CleanItemLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CleanItemLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_ResetMachineBackBtn = lv_btn_create(ui_ResetMachinePanel);
    lv_obj_set_size(ui_ResetMachineBackBtn, 68, 38);
    lv_obj_set_pos(ui_ResetMachineBackBtn, 474, 6);
    lv_obj_add_flag(ui_ResetMachineBackBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ResetMachineBackBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ResetMachineBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ResetMachineBackBtn, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ResetMachineBackBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ResetMachineBackBtn, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ResetMachineBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ResetMachineBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ResetMachineBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ResetMachineBackBtn, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ResetMachineBackBtn, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ResetMachineBackBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ResetMachineBackBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ResetMachineBackBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ResetMachineBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ResetMachineBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //日志
    ui_resetCheckbox1 = lv_checkbox_create(ui_ResetMachinePanel);
    lv_checkbox_set_text(ui_resetCheckbox1, LogArray[language_index]);
    lv_obj_set_size(ui_resetCheckbox1, 240, 33);
    lv_obj_align_to(ui_resetCheckbox1, ui_CleanItemLabel, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 12);
    lv_obj_clear_flag(ui_resetCheckbox1, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui_resetCheckbox1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_resetCheckbox1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetCheckbox1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetCheckbox1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_resetCheckbox1, 10);
    lv_obj_set_style_radius(ui_resetCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_resetCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox1, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_resetCheckbox1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_resetCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox1, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox1, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_pad_all(ui_resetCheckbox1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_resetCheckbox1, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox1, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_resetCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_resetCheckbox1, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_resetCheckbox1, 255, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_resetCheckbox1, 4, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_resetCheckbox1, 0, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_resetCheckbox1, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_resetCheckbox1, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_opa(ui_resetCheckbox1, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //延时摄影
    ui_resetCheckbox2 = lv_checkbox_create(ui_ResetMachinePanel);
    lv_checkbox_set_text(ui_resetCheckbox2, DelayPhotographVedioes[language_index]);
    lv_obj_set_size(ui_resetCheckbox2, 240, 33);
    lv_obj_align_to(ui_resetCheckbox2, ui_resetCheckbox1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 18);
    lv_obj_clear_flag(ui_resetCheckbox2, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui_resetCheckbox2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_resetCheckbox2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetCheckbox2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetCheckbox2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_resetCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_resetCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox2, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_resetCheckbox2, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_resetCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox2, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox2, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_pad_all(ui_resetCheckbox2, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_resetCheckbox2, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox2, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_resetCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_resetCheckbox2, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_resetCheckbox2, 255, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_resetCheckbox2, 4, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_resetCheckbox2, 0, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_resetCheckbox2, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_resetCheckbox2, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_opa(ui_resetCheckbox2, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    
    //Gcode文件
    ui_resetCheckbox3 = lv_checkbox_create(ui_ResetMachinePanel);
    lv_checkbox_set_text(ui_resetCheckbox3, FileArray[language_index]);
    lv_obj_set_size(ui_resetCheckbox3, 240, 33);
    lv_obj_align_to(ui_resetCheckbox3, ui_resetCheckbox2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 18);
    lv_obj_clear_flag(ui_resetCheckbox3, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui_resetCheckbox3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_resetCheckbox3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetCheckbox3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetCheckbox3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_resetCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_resetCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox3, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_resetCheckbox3, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_resetCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox3, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox3, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_pad_all(ui_resetCheckbox3, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_resetCheckbox3, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox3, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_resetCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_resetCheckbox3, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_resetCheckbox3, 255, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_resetCheckbox3, 4, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_resetCheckbox3, 0, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_resetCheckbox3, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_resetCheckbox3, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_opa(ui_resetCheckbox3, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    
    //打印记录
    ui_resetCheckbox4 = lv_checkbox_create(ui_ResetMachinePanel);
    lv_checkbox_set_text(ui_resetCheckbox4, RecordsArray[language_index]);
    lv_obj_set_size(ui_resetCheckbox4, 240, 33);
    lv_obj_align_to(ui_resetCheckbox4, ui_resetCheckbox3, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 18);
    lv_obj_clear_flag(ui_resetCheckbox4, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui_resetCheckbox4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_resetCheckbox4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetCheckbox4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetCheckbox4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_resetCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_resetCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox4, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_resetCheckbox4, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_resetCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox4, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetCheckbox4, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
     lv_obj_set_style_pad_all(ui_resetCheckbox4, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_resetCheckbox4, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_resetCheckbox4, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_resetCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_resetCheckbox4, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_resetCheckbox4, 255, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_resetCheckbox4, 4, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_resetCheckbox4, 0, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_resetCheckbox4, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_resetCheckbox4, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_opa(ui_resetCheckbox4, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //恢复按钮
    ui_ResetMachineBtn = lv_btn_create(ui_ResetMachinePanel);
    lv_obj_set_size(ui_ResetMachineBtn, 176, 52);
    //lv_obj_set_pos(ui_ResetMachineBtn, 372, 280);
    lv_obj_align(ui_ResetMachineBtn, LV_ALIGN_BOTTOM_RIGHT, -8, -12);
    lv_obj_add_flag(ui_ResetMachineBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ResetMachineBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ResetMachineBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ResetMachineBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ResetMachineBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ResetMachineBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ResetMachineBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ResetMachineBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ResetMachineBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_ResetMachineBtn, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ResetMachineBtn, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ResetMachineBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ResetMachineBtn, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ResetMachineBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ResetMachineBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    
    ui_ResetMachineBtnLabel = lv_label_create(ui_ResetMachineBtn);
    lv_obj_set_width(ui_ResetMachineBtnLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ResetMachineBtnLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ResetMachineBtnLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ResetMachineBtnLabel, ResetArray[language_index]);
    lv_obj_set_style_text_align(ui_ResetMachineBtnLabel, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ResetMachineBtnLabel, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_add_event_cb(ui_resetCheckbox1, ui_event_ResetMachineCheckbox, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_resetCheckbox2, ui_event_ResetMachineCheckbox, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_resetCheckbox3, ui_event_ResetMachineCheckbox, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_resetCheckbox4, ui_event_ResetMachineCheckbox, LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_ResetMachineBackBtn, ui_event_ResetMachineBackBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ResetMachineBtn, ui_event_ResetMachineBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_homeimg1, ui_event_resetmachinehomeimg1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_axismoveimg1, ui_event_resetmachineaxismoveimg1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_fileimg1, ui_event_resetmachinefileimg1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_settingsimg1, ui_event_resetmachinesettingsimg1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_faqimg1, ui_event_resetmachinefaqimg1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ResetMachine, ui_event_ResetMachine, LV_EVENT_ALL, NULL);

}

void ui_event_ResetMachineCheckbox(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    //lv_obj_t * target = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        lv_group_set_editing(encoder_group, false);
    }
}

void ui_event_ResetMachine(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load the resetmachine page");
        if(!lv_obj_get_state(ui_resetCheckbox1)) lv_obj_add_state(ui_resetCheckbox1, LV_STATE_CHECKED);
        if(!lv_obj_get_state(ui_resetCheckbox2)) lv_obj_add_state(ui_resetCheckbox2, LV_STATE_CHECKED);
        if(!lv_obj_get_state(ui_resetCheckbox3)) lv_obj_add_state(ui_resetCheckbox3, LV_STATE_CHECKED);
        if(!lv_obj_get_state(ui_resetCheckbox4)) lv_obj_add_state(ui_resetCheckbox4, LV_STATE_CHECKED);
    }
}

void ui_event_resetmachinehomeimg1(lv_event_t * e)
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

void ui_event_resetmachineaxismoveimg1(lv_event_t * e)
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

void ui_event_resetmachinefileimg1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadFileManageScreen();
    }
}

void ui_event_resetmachinesettingsimg1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_resetmachinefaqimg1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadCustomerServiceScreen();
    }
}

/**
 * @description: 返回上级页面事件处理
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_ResetMachineBackBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        BackPrepage(false);
        //_ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void clear_data()
{
    send_buzzer(0x01);
    int state[4] = {0};
    state[0] = lv_obj_get_state(ui_resetCheckbox1) & LV_STATE_CHECKED ? 1 : 0;  //日志
    state[1] = lv_obj_get_state(ui_resetCheckbox2) & LV_STATE_CHECKED ? 1 : 0;  //延时摄影视频
    state[2] = lv_obj_get_state(ui_resetCheckbox3) & LV_STATE_CHECKED ? 1 : 0;  //Gcode文件
    state[3] = lv_obj_get_state(ui_resetCheckbox4) & LV_STATE_CHECKED ? 1 : 0;  //打印记录
    CrLogI("reset options is %d%d%d%d.",state[0],state[1],state[2],state[3]);
    char temp[6]= {0};
    snprintf(temp,6,"6%d%d%d%d",state[0],state[1],state[2],state[3]);
    set_printer_data(0x06,6,temp);
    set_printer_data(0x06,2,"91");
    selftest_messagebox_close();
    create_msgbox(ResetMachineTips[get_cur_language_index()], &ui_img_wait_png, 20 * 1000, lv_scr_act());
}

void not_clear_data()
{
    send_buzzer(0x01);
    selftest_messagebox_close();
}

/**
 * @description: 恢复出厂按钮事件处理
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_ResetMachineBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        uint8_t language_index = get_cur_language_index();
        void (*btns_callback[2])(void) = {&not_clear_data, &clear_data};
        create_selftest_messagebox(KindTips[language_index], ResetUserData[language_index],Cancel[language_index], Confirm[language_index], btns_callback);
    }
}

void reset_machine_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_ResetMachineTitle )
        lv_label_set_text(ui_ResetMachineTitle, ResetMachine[language_index]);
        
    if ( ui_CleanItemLabel )
        lv_label_set_text(ui_CleanItemLabel, CleanItemArray[language_index]);
    
    if ( ui_resetCheckbox1 )
        lv_checkbox_set_text(ui_resetCheckbox1, LogArray[language_index]);
    
    if ( ui_resetCheckbox2 )
        lv_checkbox_set_text(ui_resetCheckbox2, DelayPhotographVedioes[language_index]);
    
    char buff[30] = {0};
    if ( ui_resetCheckbox3 )
    {
        // sprintf(buff, "Gcode%s", FileArray[language_index]);
        lv_checkbox_set_text(ui_resetCheckbox3, FileArray[language_index]);
    }

    if ( ui_resetCheckbox4 )
    {
        // memset(buff, 0, sizeof(buff));
        // sprintf(buff, "%s%s", Print[language_index], RecordsArray[language_index]);
        lv_checkbox_set_text(ui_resetCheckbox4, RecordsArray[language_index]);
    }

    if ( ui_ResetMachineBtnLabel )
    {
        lv_label_set_text(ui_ResetMachineBtnLabel, ResetArray[language_index]);
        lv_obj_update_layout(ui_ResetMachineBtn);
        redefine_widgets_size(ui_ResetMachineBtn, ui_ResetMachineBtnLabel, 10, 0, 116, 60);
    }
}

void LoadResetMachineScreen(void)
{
    _ui_screen_change(ui_ResetMachine, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

/**
 * @description: 设置页编码器对象事件组设置
 * @return {*}
 * @param {uint8_t} index
 */
static void ResetMachinePageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *ResetMachineNode = find_page(ui_ResetMachine);
    ResetMachineNode->nav_level = index;

    switch (index)
    {
    case 1: //1级事件组
        lv_group_add_obj(encoder_group, ui_ResetMachineBackBtn);
        lv_group_add_obj(encoder_group, ui_resetCheckbox1);
        lv_group_add_obj(encoder_group, ui_resetCheckbox2);
        lv_group_add_obj(encoder_group, ui_resetCheckbox3);
        lv_group_add_obj(encoder_group, ui_resetCheckbox4);
        lv_group_add_obj(encoder_group, ui_ResetMachineBtn);
        break;
    default:
        break;
    } 
}
